
long ssl3_get_server_hello(SSL *param_1)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  SSL_CIPHER *pSVar4;
  _STACK *st;
  byte *pbVar5;
  SSL_COMP *pSVar6;
  SSL_SESSION *pSVar7;
  int iVar8;
  ssl3_state_st *psVar9;
  uint uVar10;
  byte *pbVar11;
  undefined4 uVar12;
  SSL_SESSION *pSVar13;
  uint __n;
  undefined4 uVar14;
  code *pcVar15;
  byte *local_2c;
  int local_28;
  SSL_CIPHER *local_24;
  
  lVar1 = (*param_1->method->ssl_get_message)(param_1,0x1120,0x1121,-1,20000,&local_28);
  if (local_28 == 0) {
    return lVar1;
  }
  iVar2 = SSL_version(param_1);
  if ((iVar2 == 0xfeff) || (iVar2 = SSL_version(param_1), iVar2 == 0x100)) {
    psVar9 = param_1->s3;
    iVar2 = (psVar9->tmp).message_type;
    if (iVar2 != 3) goto LAB_0004b14c;
    if (param_1->d1->send_cookie == 0) {
      (psVar9->tmp).reuse_message = 1;
      return 1;
    }
    iVar2 = 0x353;
  }
  else {
    psVar9 = param_1->s3;
    iVar2 = (psVar9->tmp).message_type;
LAB_0004b14c:
    if (iVar2 == 2) {
      pbVar11 = (byte *)param_1->init_msg;
      if (((uint)*pbVar11 != param_1->version >> 8) ||
         ((uint)pbVar11[1] != (param_1->version & 0xffU))) {
        local_2c = pbVar11;
        ERR_put_error(0x14,0x92,0x10a,"s3_clnt.c",0x364);
        local_24 = (SSL_CIPHER *)0x46;
        param_1->version = param_1->version & 0xff00U | (uint)local_2c[1];
        goto LAB_0004b3ac;
      }
      uVar12 = *(undefined4 *)(pbVar11 + 10);
      local_2c = pbVar11 + 0x23;
      uVar3 = *(undefined4 *)(pbVar11 + 0xe);
      uVar14 = *(undefined4 *)(pbVar11 + 2);
      *(undefined4 *)(psVar9->server_random + 4) = *(undefined4 *)(pbVar11 + 6);
      *(undefined4 *)(psVar9->server_random + 8) = uVar12;
      *(undefined4 *)psVar9->server_random = uVar14;
      *(undefined4 *)(psVar9->server_random + 0xc) = uVar3;
      uVar14 = *(undefined4 *)(pbVar11 + 0x16);
      uVar12 = *(undefined4 *)(pbVar11 + 0x1a);
      uVar3 = *(undefined4 *)(pbVar11 + 0x1e);
      *(undefined4 *)(psVar9->server_random + 0x10) = *(undefined4 *)(pbVar11 + 0x12);
      *(undefined4 *)(psVar9->server_random + 0x14) = uVar14;
      *(undefined4 *)(psVar9->server_random + 0x18) = uVar12;
      *(undefined4 *)(psVar9->server_random + 0x1c) = uVar3;
      __n = (uint)pbVar11[0x22];
      if (0x20 < __n) {
        local_24 = (SSL_CIPHER *)0x2f;
        ERR_put_error(0x14,0x92,300,"s3_clnt.c",0x376);
        goto LAB_0004b3ac;
      }
      if ((param_1->version < 0x301) ||
         (pcVar15 = (code *)param_1->tls_session_ticket_ext_cb_arg, pcVar15 == (code *)0x0)) {
        pSVar7 = param_1->session;
        if (__n != 0) goto LAB_0004b20e;
LAB_0004b218:
        uVar10 = pSVar7->session_id_length;
        param_1->hit = 0;
        if (uVar10 == 0) {
LAB_0004b230:
          pSVar7->session_id_length = __n;
          memcpy(pSVar7->session_id,local_2c,__n);
          pbVar5 = local_2c;
          goto LAB_0004b242;
        }
        iVar2 = ssl_get_new_session(param_1);
        if (iVar2 != 0) {
          pSVar7 = param_1->session;
          goto LAB_0004b230;
        }
LAB_0004b4b0:
        local_24 = (SSL_CIPHER *)0x50;
        goto LAB_0004b3ac;
      }
      pSVar7 = param_1->session;
      local_24 = (SSL_CIPHER *)0x0;
      pSVar7->master_key_length = 0x30;
      iVar2 = (*pcVar15)(param_1,pSVar7->master_key,&pSVar7->master_key_length,0,&local_24,
                         param_1->tls_session_secret_cb);
      pSVar13 = param_1->session;
      pSVar7 = pSVar13;
      if (iVar2 != 0) {
        pSVar4 = local_24;
        if (local_24 == (SSL_CIPHER *)0x0) {
          pSVar4 = (*param_1->method->get_cipher_by_char)(local_2c + __n);
          pSVar7 = param_1->session;
        }
        *(SSL_CIPHER **)(pSVar13->krb5_client_princ + 0x24) = pSVar4;
      }
      if (__n == 0) goto LAB_0004b218;
LAB_0004b20e:
      pbVar5 = local_2c;
      if ((pSVar7->session_id_length != __n) ||
         (iVar2 = memcmp(local_2c,pSVar7->session_id,__n), iVar2 != 0)) goto LAB_0004b218;
      if ((param_1->sid_ctx_length != pSVar7->sid_ctx_length) ||
         (iVar2 = memcmp(pSVar7->sid_ctx,param_1->sid_ctx,param_1->sid_ctx_length), iVar2 != 0)) {
        local_24 = (SSL_CIPHER *)0x2f;
        ERR_put_error(0x14,0x92,0x110,"s3_clnt.c",0x393);
        goto LAB_0004b3ac;
      }
      param_1->hit = 1;
LAB_0004b242:
      local_2c = pbVar5 + __n;
      pSVar4 = (*param_1->method->get_cipher_by_char)(local_2c);
      pbVar5 = local_2c;
      if (pSVar4 == (SSL_CIPHER *)0x0) {
        local_24 = (SSL_CIPHER *)0x2f;
        ERR_put_error(0x14,0x92,0xf8,"s3_clnt.c",0x3ae);
        goto LAB_0004b3ac;
      }
      if (((int)(pSVar4->algorithm_ssl << 0x1d) < 0) &&
         ((param_1->version >> 8 != 3 || (param_1->version < 0x303)))) {
        local_24 = (SSL_CIPHER *)0x2f;
        ERR_put_error(0x14,0x92,0x105,"s3_clnt.c",0x3b6);
        goto LAB_0004b3ac;
      }
      iVar2 = (*param_1->method->put_cipher_by_char)((SSL_CIPHER *)0x0,(uchar *)0x0);
      local_2c = pbVar5 + iVar2;
      st = (_STACK *)ssl_get_ciphers_by_id(param_1);
      iVar2 = sk_find(st,pSVar4);
      if (iVar2 < 0) {
        local_24 = (SSL_CIPHER *)0x2f;
        ERR_put_error(0x14,0x92,0x105,"s3_clnt.c",0x3c1);
        goto LAB_0004b3ac;
      }
      pSVar7 = param_1->session;
      if (*(int *)(pSVar7->krb5_client_princ + 0x24) != 0) {
        *(undefined4 *)(pSVar7->krb5_client_princ + 0x28) =
             *(undefined4 *)(*(int *)(pSVar7->krb5_client_princ + 0x24) + 8);
      }
      iVar2 = param_1->hit;
      if ((iVar2 != 0) && (*(ulong *)(pSVar7->krb5_client_princ + 0x28) != pSVar4->id)) {
        local_24 = (SSL_CIPHER *)0x2f;
        ERR_put_error(0x14,0x92,0xc5,"s3_clnt.c",0x3d3);
        goto LAB_0004b3ac;
      }
      iVar8 = param_1->version;
      (param_1->s3->tmp).new_cipher = pSVar4;
      if ((iVar8 >> 8 != 3) || (iVar8 < 0x303)) {
        iVar2 = ssl3_digest_cached_records(param_1);
        if (iVar2 == 0) goto LAB_0004b4b0;
        iVar2 = param_1->hit;
      }
      pbVar5 = local_2c + 1;
      pSVar6 = (SSL_COMP *)(uint)*local_2c;
      local_2c = pbVar5;
      if ((iVar2 != 0) && (*(SSL_COMP **)(param_1->session->krb5_client_princ + 0x20) != pSVar6)) {
        local_24 = (SSL_CIPHER *)0x2f;
        ERR_put_error(0x14,0x92,0x158,"s3_clnt.c",0x3f7);
        goto LAB_0004b3ac;
      }
      if (pSVar6 != (SSL_COMP *)0x0) {
        if (param_1->references << 0xe < 0) {
          local_24 = (SSL_CIPHER *)0x2f;
          ERR_put_error(0x14,0x92,0x157,"s3_clnt.c",0x3ff);
          goto LAB_0004b3ac;
        }
        pSVar6 = (SSL_COMP *)ssl3_comp_find(*(undefined4 *)(param_1->psk_server_callback + 0x98));
        if (pSVar6 == (SSL_COMP *)0x0) {
          local_24 = (SSL_CIPHER *)0x2f;
          ERR_put_error(0x14,0x92,0x101,"s3_clnt.c",0x408);
          goto LAB_0004b3ac;
        }
      }
      iVar2 = param_1->version;
      (param_1->s3->tmp).new_compression = pSVar6;
      if (0x2ff < iVar2) {
        iVar2 = ssl_parse_serverhello_tlsext(param_1,&local_2c,pbVar11,lVar1,&local_24);
        if (iVar2 == 0) {
          ERR_put_error(0x14,0x92,0xe3,"s3_clnt.c",0x418);
          goto LAB_0004b3ac;
        }
        iVar2 = ssl_check_serverhello_tlsext(param_1);
        if (iVar2 < 1) {
          ERR_put_error(0x14,0x92,0x113,"s3_clnt.c",0x41d);
          return -1;
        }
      }
      if (local_2c == pbVar11 + lVar1) {
        return 1;
      }
      local_24 = (SSL_CIPHER *)0x32;
      ERR_put_error(0x14,0x92,0x73,"s3_clnt.c",0x427);
      goto LAB_0004b3ac;
    }
    iVar2 = 0x35c;
  }
  local_24 = (SSL_CIPHER *)0xa;
  ERR_put_error(0x14,0x92,0x72,"s3_clnt.c",iVar2);
LAB_0004b3ac:
  ssl3_send_alert(param_1,2,local_24);
  return -1;
}

