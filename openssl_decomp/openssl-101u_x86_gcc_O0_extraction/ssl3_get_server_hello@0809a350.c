
long ssl3_get_server_hello(SSL *param_1)

{
  byte bVar1;
  code *pcVar2;
  SSL_SESSION *pSVar3;
  long lVar4;
  int iVar5;
  SSL_CIPHER *pSVar6;
  _STACK *st;
  SSL_COMP *pSVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  ssl3_state_st *psVar11;
  undefined4 *puVar12;
  SSL_SESSION *pSVar13;
  undefined4 *puVar14;
  int in_GS_OFFSET;
  byte bVar15;
  int line;
  undefined4 *local_44;
  undefined4 *local_30;
  undefined4 local_2c;
  int local_28;
  SSL_CIPHER *local_24;
  int local_20;
  
  bVar15 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  lVar4 = (*param_1->method->ssl_get_message)(param_1,0x1120,0x1121,-1,20000,&local_28);
  if (local_28 == 0) goto LAB_0809a393;
  iVar5 = SSL_version(param_1);
  if ((iVar5 == 0xfeff) || (iVar5 = SSL_version(param_1), iVar5 == 0x100)) {
    psVar11 = param_1->s3;
    iVar5 = (psVar11->tmp).message_type;
    if (iVar5 != 3) goto LAB_0809a3e7;
    if (param_1->d1->send_cookie == 0) {
      (psVar11->tmp).reuse_message = 1;
      lVar4 = 1;
      goto LAB_0809a393;
    }
    local_2c = 10;
    line = 0x361;
    iVar5 = 0x72;
LAB_0809a634:
    ERR_put_error(0x14,0x92,iVar5,"s3_clnt.c",line);
LAB_0809a7d2:
    ssl3_send_alert(param_1,2,local_2c);
  }
  else {
    psVar11 = param_1->s3;
    iVar5 = (psVar11->tmp).message_type;
LAB_0809a3e7:
    if (iVar5 != 2) {
      local_2c = 10;
      line = 0x369;
      iVar5 = 0x72;
      goto LAB_0809a634;
    }
    puVar10 = (undefined4 *)param_1->init_msg;
    if (((uint)*(byte *)puVar10 != param_1->version >> 8) ||
       (*(byte *)((int)puVar10 + 1) != (byte)param_1->version)) {
      local_30 = puVar10;
      ERR_put_error(0x14,0x92,0x10a,"s3_clnt.c",0x370);
      local_2c = 0x46;
      param_1->version = (uint)*(byte *)((int)local_30 + 1) | param_1->version & 0xff00U;
      goto LAB_0809a7d2;
    }
    *(undefined4 *)psVar11->server_random = *(undefined4 *)((int)puVar10 + 2);
    *(undefined4 *)(psVar11->server_random + 4) = *(undefined4 *)((int)puVar10 + 6);
    *(undefined4 *)(psVar11->server_random + 8) = *(undefined4 *)((int)puVar10 + 10);
    *(undefined4 *)(psVar11->server_random + 0xc) = *(undefined4 *)((int)puVar10 + 0xe);
    *(undefined4 *)(psVar11->server_random + 0x10) = *(undefined4 *)((int)puVar10 + 0x12);
    *(undefined4 *)(psVar11->server_random + 0x14) = *(undefined4 *)((int)puVar10 + 0x16);
    *(undefined4 *)(psVar11->server_random + 0x18) = *(undefined4 *)((int)puVar10 + 0x1a);
    *(undefined4 *)(psVar11->server_random + 0x1c) = *(undefined4 *)((int)puVar10 + 0x1e);
    param_1->hit = 0;
    local_30 = (undefined4 *)((int)puVar10 + 0x23);
    bVar1 = *(byte *)((int)puVar10 + 0x22);
    uVar9 = (uint)bVar1;
    if (0x20 < uVar9) {
      local_2c = 0x2f;
      line = 899;
      iVar5 = 300;
      goto LAB_0809a634;
    }
    if ((param_1->version < 0x301) ||
       (pcVar2 = (code *)param_1->tls_session_ticket_ext_cb_arg, pcVar2 == (code *)0x0)) {
      pSVar13 = param_1->session;
    }
    else {
      pSVar13 = param_1->session;
      if (*(int *)(pSVar13->krb5_client_princ + 0x54) != 0) {
        local_24 = (SSL_CIPHER *)0x0;
        pSVar13->master_key_length = 0x30;
        iVar5 = (*pcVar2)(param_1,pSVar13->master_key,&pSVar13->master_key_length,0,&local_24,
                          param_1->tls_session_secret_cb);
        if (iVar5 == 0) {
          ERR_put_error(0x14,0x92,0x44,"s3_clnt.c",0x39e);
          local_2c = 0x50;
          goto LAB_0809a7d2;
        }
        pSVar3 = param_1->session;
        pSVar6 = local_24;
        pSVar13 = pSVar3;
        if (local_24 == (SSL_CIPHER *)0x0) {
          pSVar6 = (*param_1->method->get_cipher_by_char)((byte *)(uVar9 + (int)local_30));
          pSVar13 = param_1->session;
        }
        *(SSL_CIPHER **)(pSVar3->krb5_client_princ + 0x24) = pSVar6;
      }
    }
    if ((uVar9 != 0) && (uVar9 == pSVar13->session_id_length)) {
      local_44 = local_30;
      iVar5 = memcmp(local_30,pSVar13->session_id,uVar9);
      if (iVar5 == 0) {
        if ((param_1->sid_ctx_length != pSVar13->sid_ctx_length) ||
           (iVar5 = memcmp(pSVar13->sid_ctx,param_1->sid_ctx,param_1->sid_ctx_length), iVar5 != 0))
        {
          local_2c = 0x2f;
          line = 0x3ac;
          iVar5 = 0x110;
          goto LAB_0809a634;
        }
        param_1->hit = 1;
        goto LAB_0809a4c0;
      }
LAB_0809a730:
      iVar5 = ssl_get_new_session(param_1,0);
      if (iVar5 != 0) {
        pSVar13 = param_1->session;
        goto LAB_0809a497;
      }
LAB_0809a900:
      local_2c = 0x50;
      goto LAB_0809a7d2;
    }
    if (pSVar13->session_id_length != 0) goto LAB_0809a730;
LAB_0809a497:
    pSVar13->session_id_length = uVar9;
    local_44 = local_30;
    if (uVar9 < 4) {
      if ((uVar9 != 0) && (pSVar13->session_id[0] = *(byte *)local_30, (bVar1 & 2) != 0)) {
        *(undefined2 *)(pSVar13->session_id + (uVar9 - 2)) =
             *(undefined2 *)((int)local_30 + (uVar9 - 2));
      }
    }
    else {
      *(undefined4 *)pSVar13->session_id = *local_30;
      puVar14 = (undefined4 *)((uint)(pSVar13->session_id + 4) & 0xfffffffc);
      *(undefined4 *)(pSVar13->session_id + (uVar9 - 4)) =
           *(undefined4 *)((int)local_30 + (uVar9 - 4));
      iVar5 = (int)pSVar13->session_id - (int)puVar14;
      puVar12 = (undefined4 *)((int)local_30 - iVar5);
      for (uVar8 = iVar5 + uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar14 = *puVar12;
        puVar12 = puVar12 + (uint)bVar15 * -2 + 1;
        puVar14 = puVar14 + (uint)bVar15 * -2 + 1;
      }
    }
LAB_0809a4c0:
    local_30 = (undefined4 *)((int)local_44 + uVar9);
    pSVar6 = (*param_1->method->get_cipher_by_char)((uchar *)local_30);
    if (pSVar6 == (SSL_CIPHER *)0x0) {
      local_2c = 0x2f;
      line = 0x3c6;
      iVar5 = 0xf8;
      goto LAB_0809a634;
    }
    if (((*(byte *)&pSVar6->algorithm_ssl & 4) != 0) &&
       ((param_1->version >> 8 != 3 || (param_1->version < 0x303)))) {
      local_2c = 0x2f;
      line = 0x3cd;
      iVar5 = 0x105;
      goto LAB_0809a634;
    }
    if ((((*(byte *)((int)&pSVar6->algorithm_mkey + 1) & 4) != 0) ||
        ((*(byte *)((int)&pSVar6->algorithm_auth + 1) & 4) != 0)) &&
       ((*(byte *)((int)&param_1[1].rstate + 1) & 4) == 0)) {
      local_2c = 0x2f;
      line = 0x3d4;
      iVar5 = 0x105;
      goto LAB_0809a634;
    }
    iVar5 = (*param_1->method->put_cipher_by_char)((SSL_CIPHER *)0x0,(uchar *)0x0);
    local_30 = (undefined4 *)((int)local_30 + iVar5);
    st = (_STACK *)ssl_get_ciphers_by_id(param_1);
    iVar5 = sk_find(st,pSVar6);
    if (iVar5 < 0) {
      local_2c = 0x2f;
      line = 0x3df;
      iVar5 = 0x105;
      goto LAB_0809a634;
    }
    pSVar13 = param_1->session;
    if (*(int *)(pSVar13->krb5_client_princ + 0x24) != 0) {
      *(undefined4 *)(pSVar13->krb5_client_princ + 0x28) =
           *(undefined4 *)(*(int *)(pSVar13->krb5_client_princ + 0x24) + 8);
    }
    iVar5 = param_1->hit;
    if ((iVar5 != 0) && (*(ulong *)(pSVar13->krb5_client_princ + 0x28) != pSVar6->id)) {
      local_2c = 0x2f;
      line = 0x3f2;
      iVar5 = 0xc5;
      goto LAB_0809a634;
    }
    (param_1->s3->tmp).new_cipher = pSVar6;
    if ((param_1->version >> 8 != 3) || (param_1->version < 0x303)) {
      iVar5 = ssl3_digest_cached_records(param_1);
      if (iVar5 == 0) goto LAB_0809a900;
      iVar5 = param_1->hit;
    }
    puVar12 = (undefined4 *)((int)local_30 + 1);
    uVar9 = (uint)*(byte *)local_30;
    local_30 = puVar12;
    if ((iVar5 != 0) && (uVar9 != *(uint *)(param_1->session->krb5_client_princ + 0x20))) {
      local_2c = 0x2f;
      line = 0x417;
      iVar5 = 0x158;
      goto LAB_0809a634;
    }
    if (uVar9 != 0) {
      if ((*(byte *)((int)&param_1->references + 2) & 2) == 0) {
        pSVar7 = (SSL_COMP *)
                 ssl3_comp_find(*(undefined4 *)(param_1->psk_server_callback + 0x98),uVar9);
        if (pSVar7 != (SSL_COMP *)0x0) goto LAB_0809a5f5;
        local_2c = 0x2f;
        line = 0x426;
        iVar5 = 0x101;
      }
      else {
        local_2c = 0x2f;
        line = 0x41e;
        iVar5 = 0x157;
      }
      goto LAB_0809a634;
    }
    pSVar7 = (SSL_COMP *)0x0;
LAB_0809a5f5:
    iVar5 = param_1->version;
    (param_1->s3->tmp).new_compression = pSVar7;
    if (iVar5 < 0x300) {
LAB_0809a60a:
      puVar10 = (undefined4 *)((int)puVar10 + lVar4);
      lVar4 = 1;
      if (local_30 == puVar10) goto LAB_0809a393;
      local_2c = 0x32;
      line = 0x43f;
      iVar5 = 0x73;
      goto LAB_0809a634;
    }
    iVar5 = ssl_parse_serverhello_tlsext(param_1,&local_30,puVar10,lVar4,&local_2c);
    if (iVar5 == 0) {
      line = 0x432;
      iVar5 = 0xe3;
      goto LAB_0809a634;
    }
    iVar5 = ssl_check_serverhello_tlsext(param_1);
    if (0 < iVar5) goto LAB_0809a60a;
    ERR_put_error(0x14,0x92,0x113,"s3_clnt.c",0x436);
  }
  param_1->state = 5;
  lVar4 = -1;
LAB_0809a393:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar4;
}

