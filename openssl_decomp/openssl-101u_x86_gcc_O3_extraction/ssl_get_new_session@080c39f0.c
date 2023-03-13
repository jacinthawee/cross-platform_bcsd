
int ssl_get_new_session(SSL *param_1,int param_2)

{
  size_t __n;
  uchar *puVar1;
  SSL_SESSION *obj;
  time_t tVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  void *pvVar6;
  code *mode;
  uint uVar7;
  code *pcVar8;
  undefined4 *puVar9;
  int in_GS_OFFSET;
  byte bVar10;
  int iVar11;
  int line;
  uint local_24;
  int local_20;
  
  bVar10 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  obj = (SSL_SESSION *)CRYPTO_malloc(0xf4,"ssl_sess.c",0xc4);
  if (obj == (SSL_SESSION *)0x0) {
    iVar3 = 0;
    ERR_put_error(0x14,0xbd,0x41,"ssl_sess.c",0xc6);
    goto LAB_080c3baa;
  }
  obj->ssl_version = 0;
  *(undefined4 *)(obj->krb5_client_princ + 0x60) = 0;
  puVar9 = (undefined4 *)((uint)&obj->key_arg_length & 0xfffffffc);
  uVar7 = (uint)((int)obj + (0xf4 - (int)puVar9)) >> 2;
  for (; uVar7 != 0; uVar7 = uVar7 - 1) {
    *puVar9 = 0;
    puVar9 = puVar9 + (uint)bVar10 * -2 + 1;
  }
  *(undefined4 *)(obj->krb5_client_princ + 0x10) = 1;
  *(undefined4 *)(obj->krb5_client_princ + 0x14) = 1;
  *(undefined4 *)(obj->krb5_client_princ + 0x18) = 0x130;
  tVar2 = time((time_t *)0x0);
  *(time_t *)(obj->krb5_client_princ + 0x1c) = tVar2;
  *(undefined4 *)(obj->krb5_client_princ + 0x38) = 0;
  *(undefined4 *)(obj->krb5_client_princ + 0x3c) = 0;
  *(undefined4 *)(obj->krb5_client_princ + 0x20) = 0;
  *(undefined4 *)(obj->krb5_client_princ + 0x40) = 0;
  *(undefined4 *)(obj->krb5_client_princ + 0x44) = 0;
  *(undefined4 *)(obj->krb5_client_princ + 0x48) = 0;
  *(undefined4 *)(obj->krb5_client_princ + 0x4c) = 0;
  *(undefined4 *)(obj->krb5_client_princ + 0x50) = 0;
  CRYPTO_new_ex_data(3,obj,(CRYPTO_EX_DATA *)(obj->krb5_client_princ + 0x30));
  pvVar6 = param_1->tls_session_secret_cb_arg;
  obj->krb5_client_princ_len = 0;
  *(undefined4 *)obj->krb5_client_princ = 0;
  *(undefined4 *)(obj->krb5_client_princ + 0x60) = 0;
  iVar3 = *(int *)((int)pvVar6 + 0x24);
  if (iVar3 == 0) {
    lVar4 = SSL_get_default_timeout(param_1);
    *(long *)(obj->krb5_client_princ + 0x18) = lVar4;
  }
  else {
    *(int *)(obj->krb5_client_princ + 0x18) = iVar3;
  }
  if (param_1->session != (SSL_SESSION *)0x0) {
    iVar3 = CRYPTO_add_lock((int *)(param_1->session->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",
                            0x36c);
    if (iVar3 < 1) {
      SSL_SESSION_free_part_2();
    }
    param_1->session = (SSL_SESSION *)0x0;
  }
  if (param_2 == 0) {
    obj->session_id_length = 0;
    goto LAB_080c3b62;
  }
  mode = (code *)param_1->version;
  if (mode == (code *)0x2) {
    iVar3 = param_1->tlsext_ocsp_resplen;
    obj->ssl_version = 2;
    obj->session_id_length = 0x10;
    if (iVar3 != 0) goto LAB_080c3cab;
LAB_080c3ddb:
    CRYPTO_lock((int)mode,5,&DAT_0000000c,(int)"ssl_sess.c");
    pcVar8 = param_1->generate_session_id;
    if (pcVar8 == (GEN_SESSION_CB)0x0) {
      pcVar8 = *(GEN_SESSION_CB *)((int)param_1->tls_session_secret_cb_arg + 0xec);
      mode = def_generate_session_id;
      if (pcVar8 == (GEN_SESSION_CB)0x0) {
        pcVar8 = def_generate_session_id;
      }
    }
    CRYPTO_lock((int)mode,6,&DAT_0000000c,(int)"ssl_sess.c");
    local_24 = obj->session_id_length;
    puVar1 = obj->session_id;
    iVar11 = (*pcVar8)(param_1,puVar1,&local_24);
    if (iVar11 == 0) {
      iVar11 = 0x1e5;
      iVar3 = 0x12d;
      goto LAB_080c3c4f;
    }
    if (local_24 == 0) {
LAB_080c3e88:
      line = 0x1f0;
      iVar11 = 0x12f;
    }
    else {
      uVar7 = obj->session_id_length;
      if (uVar7 < local_24) goto LAB_080c3e88;
      if ((local_24 < uVar7) && (param_1->version == 2)) {
        memset(puVar1 + local_24,0,uVar7 - local_24);
        uVar7 = obj->session_id_length;
      }
      else {
        obj->session_id_length = local_24;
        uVar7 = local_24;
      }
      iVar11 = SSL_has_matching_session_id(param_1,puVar1,uVar7);
      if (iVar11 == 0) goto LAB_080c3cb2;
      line = 0x1fc;
      iVar11 = 0x12e;
    }
    ERR_put_error(0x14,0xb5,iVar11,"ssl_sess.c",line);
    iVar11 = CRYPTO_add_lock((int *)(obj->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
    if (iVar11 < 1) {
      SSL_SESSION_free_part_2();
      goto LAB_080c3baa;
    }
  }
  else {
    if (mode == (code *)0x300) {
      obj->ssl_version = 0x300;
      obj->session_id_length = 0x20;
LAB_080c3c9d:
      iVar3 = param_1->tlsext_ocsp_resplen;
      if (iVar3 == 0) goto LAB_080c3ddb;
LAB_080c3cab:
      obj->session_id_length = 0;
LAB_080c3cb2:
      if ((char *)param_1->tlsext_debug_arg == (char *)0x0) {
LAB_080c3cd6:
        if (param_1->tlsext_ecpointformatlist_length != 0) {
          if (*(void **)(obj->krb5_client_princ + 0x48) != (void *)0x0) {
            CRYPTO_free(*(void **)(obj->krb5_client_princ + 0x48));
          }
          pvVar6 = CRYPTO_malloc(param_1->tlsext_ticket_expected,"ssl_sess.c",0x20f);
          *(void **)(obj->krb5_client_princ + 0x48) = pvVar6;
          if (pvVar6 == (void *)0x0) {
            iVar11 = 0x211;
            iVar3 = 0x41;
            goto LAB_080c3c4f;
          }
          __n = param_1->tlsext_ticket_expected;
          *(size_t *)(obj->krb5_client_princ + 0x44) = __n;
          memcpy(pvVar6,(void *)param_1->tlsext_ecpointformatlist_length,__n);
        }
        if (param_1->tlsext_ellipticcurvelist_length != 0) {
          if (*(void **)(obj->krb5_client_princ + 0x50) != (void *)0x0) {
            CRYPTO_free(*(void **)(obj->krb5_client_princ + 0x50));
          }
          pvVar6 = CRYPTO_malloc((int)param_1->tlsext_ecpointformatlist,"ssl_sess.c",0x21e);
          *(void **)(obj->krb5_client_princ + 0x50) = pvVar6;
          if (pvVar6 == (void *)0x0) {
            iVar11 = 0x220;
            iVar3 = 0x41;
            goto LAB_080c3c4f;
          }
          puVar1 = param_1->tlsext_ecpointformatlist;
          *(uchar **)(obj->krb5_client_princ + 0x4c) = puVar1;
          memcpy(pvVar6,(void *)param_1->tlsext_ellipticcurvelist_length,(size_t)puVar1);
        }
LAB_080c3b62:
        if (param_1->sid_ctx_length < 0x21) {
          iVar3 = 1;
          memcpy(obj->sid_ctx,param_1->sid_ctx,param_1->sid_ctx_length);
          obj->sid_ctx_length = param_1->sid_ctx_length;
          iVar11 = param_1->version;
          param_1->session = obj;
          *(undefined4 *)(obj->krb5_client_princ + 0x10) = 0;
          obj->ssl_version = iVar11;
          goto LAB_080c3baa;
        }
        iVar11 = 0x230;
      }
      else {
        pcVar5 = BUF_strdup((char *)param_1->tlsext_debug_arg);
        *(char **)(obj->krb5_client_princ + 0x40) = pcVar5;
        if (pcVar5 != (char *)0x0) goto LAB_080c3cd6;
        iVar11 = 0x205;
      }
      iVar3 = 0x44;
    }
    else {
      if (mode == (code *)0x301) {
        obj->ssl_version = 0x301;
        obj->session_id_length = 0x20;
        goto LAB_080c3c9d;
      }
      if (mode == (code *)0x302) {
        obj->ssl_version = 0x302;
        obj->session_id_length = 0x20;
        goto LAB_080c3c9d;
      }
      if (mode == (code *)0x303) {
        obj->ssl_version = 0x303;
        obj->session_id_length = 0x20;
        goto LAB_080c3c9d;
      }
      if (mode == (code *)0x100) {
        obj->ssl_version = 0x100;
        obj->session_id_length = 0x20;
        goto LAB_080c3c9d;
      }
      if (mode == (code *)0xfeff) {
        obj->ssl_version = 0xfeff;
        obj->session_id_length = 0x20;
        goto LAB_080c3c9d;
      }
      iVar11 = 0x1c0;
      iVar3 = 0x103;
    }
LAB_080c3c4f:
    ERR_put_error(0x14,0xb5,iVar3,"ssl_sess.c",iVar11);
    iVar3 = CRYPTO_add_lock((int *)(obj->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
    if (iVar3 < 1) {
      iVar3 = 0;
      SSL_SESSION_free_part_2();
      goto LAB_080c3baa;
    }
  }
  iVar3 = 0;
LAB_080c3baa:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}

