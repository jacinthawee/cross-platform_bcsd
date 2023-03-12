
void * ssl_get_new_session(SSL *param_1,int param_2)

{
  SSL_SESSION *ses;
  time_t tVar1;
  char *pcVar2;
  long lVar3;
  void *pvVar4;
  size_t sVar5;
  uchar *__n;
  void *pvVar6;
  int iVar7;
  uint uVar8;
  GEN_SESSION_CB pGVar9;
  bool bVar10;
  uint local_1c;
  
  ses = (SSL_SESSION *)CRYPTO_malloc(0xf4,"ssl_sess.c",0xc0);
  if (ses == (SSL_SESSION *)0x0) {
    ERR_put_error(0x14,0xbd,0x41,"ssl_sess.c",0xc3);
    return (void *)0x0;
  }
  memset(ses,0,0xf4);
  *(undefined4 *)(ses->krb5_client_princ + 0x10) = 1;
  *(undefined4 *)(ses->krb5_client_princ + 0x14) = 1;
  *(undefined4 *)(ses->krb5_client_princ + 0x18) = 0x130;
  tVar1 = time((time_t *)0x0);
  *(undefined4 *)(ses->krb5_client_princ + 0x38) = 0;
  *(undefined4 *)(ses->krb5_client_princ + 0x3c) = 0;
  *(undefined4 *)(ses->krb5_client_princ + 0x20) = 0;
  *(undefined4 *)(ses->krb5_client_princ + 0x40) = 0;
  *(undefined4 *)(ses->krb5_client_princ + 0x44) = 0;
  *(undefined4 *)(ses->krb5_client_princ + 0x48) = 0;
  *(undefined4 *)(ses->krb5_client_princ + 0x4c) = 0;
  *(undefined4 *)(ses->krb5_client_princ + 0x50) = 0;
  *(time_t *)(ses->krb5_client_princ + 0x1c) = tVar1;
  CRYPTO_new_ex_data(3,ses,(CRYPTO_EX_DATA *)(ses->krb5_client_princ + 0x30));
  pvVar6 = param_1->tls_session_secret_cb_arg;
  ses->krb5_client_princ_len = 0;
  *(undefined4 *)ses->krb5_client_princ = 0;
  iVar7 = *(int *)((int)pvVar6 + 0x24);
  *(undefined4 *)(ses->krb5_client_princ + 0x60) = 0;
  if (iVar7 == 0) {
    lVar3 = SSL_get_default_timeout(param_1);
    *(long *)(ses->krb5_client_princ + 0x18) = lVar3;
  }
  else {
    *(int *)(ses->krb5_client_princ + 0x18) = iVar7;
  }
  if (param_1->session != (SSL_SESSION *)0x0) {
    SSL_SESSION_free(param_1->session);
    param_1->session = (SSL_SESSION *)0x0;
  }
  if (param_2 == 0) {
    ses->session_id_length = 0;
  }
  else {
    uVar8 = param_1->version;
    bVar10 = uVar8 == 2;
    if (bVar10) {
      ses->ssl_version = 2;
      uVar8 = 0x10;
    }
    if (bVar10) {
      ses->session_id_length = uVar8;
    }
    else {
      if (((((uVar8 != 0x300) && (uVar8 != 0x301)) && (uVar8 != 0x302)) &&
          ((uVar8 != 0x303 && (uVar8 != 0x100)))) && (uVar8 != 0xfeff)) {
        ERR_put_error(0x14,0xb5,0x103,"ssl_sess.c",0x14d);
        SSL_SESSION_free(ses);
        return (void *)0x0;
      }
      ses->ssl_version = uVar8;
      ses->session_id_length = 0x20;
    }
    if (param_1->tlsext_ocsp_resplen == 0) {
      CRYPTO_lock(5,0xc,"ssl_sess.c",0x15a);
      pGVar9 = param_1->generate_session_id;
      if (param_1->generate_session_id == (GEN_SESSION_CB)0x0) {
        pGVar9 = *(GEN_SESSION_CB *)((int)param_1->tls_session_secret_cb_arg + 0xec);
        if (pGVar9 == (GEN_SESSION_CB)0x0) {
          pGVar9 = def_generate_session_id + 1;
        }
      }
      CRYPTO_lock(6,0xc,"ssl_sess.c",0x15f);
      local_1c = ses->session_id_length;
      iVar7 = (*pGVar9)(param_1,ses->session_id,&local_1c);
      if (iVar7 == 0) {
        ERR_put_error(0x14,0xb5,0x12d,"ssl_sess.c",0x166);
        SSL_SESSION_free(ses);
        return (void *)0x0;
      }
      if (local_1c == 0) {
LAB_000642be:
        ERR_put_error(0x14,0xb5,0x12f,"ssl_sess.c",0x170);
        SSL_SESSION_free(ses);
        return (void *)0x0;
      }
      uVar8 = ses->session_id_length;
      if (uVar8 < local_1c) goto LAB_000642be;
      if ((local_1c < uVar8) && (param_1->version == 2)) {
        memset(ses->session_id + local_1c,0,uVar8 - local_1c);
        uVar8 = ses->session_id_length;
      }
      else {
        ses->session_id_length = local_1c;
        uVar8 = local_1c;
      }
      iVar7 = SSL_has_matching_session_id(param_1,ses->session_id,uVar8);
      if (iVar7 != 0) {
        ERR_put_error(0x14,0xb5,0x12e,"ssl_sess.c",0x17e);
        SSL_SESSION_free(ses);
        return (void *)0x0;
      }
    }
    else {
      ses->session_id_length = 0;
    }
    if ((char *)param_1->tlsext_debug_arg != (char *)0x0) {
      pcVar2 = BUF_strdup((char *)param_1->tlsext_debug_arg);
      *(char **)(ses->krb5_client_princ + 0x40) = pcVar2;
      if (pcVar2 == (char *)0x0) {
        ERR_put_error(0x14,0xb5,0x44,"ssl_sess.c",0x187);
        SSL_SESSION_free(ses);
        return (void *)0x0;
      }
    }
    if (param_1->tlsext_ecpointformatlist_length != 0) {
      if (*(void **)(ses->krb5_client_princ + 0x48) != (void *)0x0) {
        CRYPTO_free(*(void **)(ses->krb5_client_princ + 0x48));
      }
      pvVar6 = CRYPTO_malloc(param_1->tlsext_ticket_expected,"ssl_sess.c",400);
      iVar7 = 0x192;
      *(void **)(ses->krb5_client_princ + 0x48) = pvVar6;
      if (pvVar6 == (void *)0x0) goto LAB_000642e8;
      sVar5 = param_1->tlsext_ticket_expected;
      pvVar4 = (void *)param_1->tlsext_ecpointformatlist_length;
      *(size_t *)(ses->krb5_client_princ + 0x44) = sVar5;
      memcpy(pvVar6,pvVar4,sVar5);
    }
    if (param_1->tlsext_ellipticcurvelist_length != 0) {
      if (*(void **)(ses->krb5_client_princ + 0x50) != (void *)0x0) {
        CRYPTO_free(*(void **)(ses->krb5_client_princ + 0x50));
      }
      pvVar6 = CRYPTO_malloc((int)param_1->tlsext_ecpointformatlist,"ssl_sess.c",0x19c);
      *(void **)(ses->krb5_client_princ + 0x50) = pvVar6;
      if (pvVar6 == (void *)0x0) {
        iVar7 = 0x19e;
LAB_000642e8:
        ERR_put_error(0x14,0xb5,0x41,"ssl_sess.c",iVar7);
        SSL_SESSION_free(ses);
        return pvVar6;
      }
      __n = param_1->tlsext_ecpointformatlist;
      pvVar4 = (void *)param_1->tlsext_ellipticcurvelist_length;
      *(uchar **)(ses->krb5_client_princ + 0x4c) = __n;
      memcpy(pvVar6,pvVar4,(size_t)__n);
      sVar5 = param_1->sid_ctx_length;
      goto joined_r0x000641f4;
    }
  }
  sVar5 = param_1->sid_ctx_length;
joined_r0x000641f4:
  if (sVar5 < 0x21) {
    memcpy(ses->sid_ctx,param_1->sid_ctx,sVar5);
    iVar7 = param_1->version;
    ses->sid_ctx_length = param_1->sid_ctx_length;
    param_1->session = ses;
    ses->ssl_version = iVar7;
    *(undefined4 *)(ses->krb5_client_princ + 0x10) = 0;
    return (void *)0x1;
  }
  ERR_put_error(0x14,0xb5,0x44,"ssl_sess.c",0x1af);
  SSL_SESSION_free(ses);
  return (void *)0x0;
}

