
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
  SSL_SESSION *pSVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  int in_GS_OFFSET;
  byte bVar15;
  int line;
  undefined4 *local_34;
  undefined4 *local_2c;
  int local_28;
  SSL_CIPHER *local_24;
  int local_20;
  
  bVar15 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  lVar4 = (*param_1->method->ssl_get_message)(param_1,0x1120,0x1121,-1,20000,&local_28);
  if (local_28 == 0) goto LAB_0809e0d3;
  iVar5 = SSL_version(param_1);
  if ((iVar5 == 0xfeff) || (iVar5 = SSL_version(param_1), iVar5 == 0x100)) {
    psVar11 = param_1->s3;
    iVar5 = (psVar11->tmp).message_type;
    if (iVar5 != 3) goto LAB_0809e127;
    if (param_1->d1->send_cookie == 0) {
      (psVar11->tmp).reuse_message = 1;
      lVar4 = 1;
      goto LAB_0809e0d3;
    }
    local_24 = (SSL_CIPHER *)0xa;
    line = 0x353;
    iVar5 = 0x72;
LAB_0809e35e:
    ERR_put_error(0x14,0x92,iVar5,"s3_clnt.c",line);
  }
  else {
    psVar11 = param_1->s3;
    iVar5 = (psVar11->tmp).message_type;
LAB_0809e127:
    if (iVar5 != 2) {
      local_24 = (SSL_CIPHER *)0xa;
      line = 0x35c;
      iVar5 = 0x72;
      goto LAB_0809e35e;
    }
    puVar10 = (undefined4 *)param_1->init_msg;
    if (((uint)*(byte *)puVar10 == param_1->version >> 8) &&
       (*(byte *)((int)puVar10 + 1) == (byte)param_1->version)) {
      *(undefined4 *)psVar11->server_random = *(undefined4 *)((int)puVar10 + 2);
      *(undefined4 *)(psVar11->server_random + 4) = *(undefined4 *)((int)puVar10 + 6);
      *(undefined4 *)(psVar11->server_random + 8) = *(undefined4 *)((int)puVar10 + 10);
      *(undefined4 *)(psVar11->server_random + 0xc) = *(undefined4 *)((int)puVar10 + 0xe);
      *(undefined4 *)(psVar11->server_random + 0x10) = *(undefined4 *)((int)puVar10 + 0x12);
      *(undefined4 *)(psVar11->server_random + 0x14) = *(undefined4 *)((int)puVar10 + 0x16);
      *(undefined4 *)(psVar11->server_random + 0x18) = *(undefined4 *)((int)puVar10 + 0x1a);
      *(undefined4 *)(psVar11->server_random + 0x1c) = *(undefined4 *)((int)puVar10 + 0x1e);
      bVar1 = *(byte *)((int)puVar10 + 0x22);
      uVar9 = (uint)bVar1;
      local_2c = (undefined4 *)((int)puVar10 + 0x23);
      if (0x20 < uVar9) {
        local_24 = (SSL_CIPHER *)0x2f;
        line = 0x376;
        iVar5 = 300;
        goto LAB_0809e35e;
      }
      if ((param_1->version < 0x301) ||
         (pcVar2 = (code *)param_1->tls_session_ticket_ext_cb_arg, pcVar2 == (code *)0x0)) {
        pSVar12 = param_1->session;
      }
      else {
        pSVar12 = param_1->session;
        local_24 = (SSL_CIPHER *)0x0;
        pSVar12->master_key_length = 0x30;
        iVar5 = (*pcVar2)(param_1,pSVar12->master_key,&pSVar12->master_key_length,0,&local_24,
                          param_1->tls_session_secret_cb);
        pSVar3 = param_1->session;
        pSVar12 = pSVar3;
        if (iVar5 != 0) {
          pSVar6 = local_24;
          if (local_24 == (SSL_CIPHER *)0x0) {
            pSVar6 = (*param_1->method->get_cipher_by_char)((byte *)(uVar9 + (int)local_2c));
            pSVar12 = param_1->session;
          }
          *(SSL_CIPHER **)(pSVar3->krb5_client_princ + 0x24) = pSVar6;
        }
      }
      if ((uVar9 != 0) && (uVar9 == pSVar12->session_id_length)) {
        local_34 = local_2c;
        iVar5 = memcmp(local_2c,pSVar12->session_id,uVar9);
        if (iVar5 != 0) {
          param_1->hit = 0;
          goto LAB_0809e460;
        }
        if ((param_1->sid_ctx_length != pSVar12->sid_ctx_length) ||
           (iVar5 = memcmp(pSVar12->sid_ctx,param_1->sid_ctx,param_1->sid_ctx_length), iVar5 != 0))
        {
          local_24 = (SSL_CIPHER *)0x2f;
          line = 0x393;
          iVar5 = 0x110;
          goto LAB_0809e35e;
        }
        param_1->hit = 1;
LAB_0809e203:
        local_2c = (undefined4 *)((int)local_34 + uVar9);
        pSVar6 = (*param_1->method->get_cipher_by_char)((uchar *)local_2c);
        if (pSVar6 == (SSL_CIPHER *)0x0) {
          local_24 = (SSL_CIPHER *)0x2f;
          line = 0x3ae;
          iVar5 = 0xf8;
        }
        else if (((*(byte *)&pSVar6->algorithm_ssl & 4) == 0) ||
                ((param_1->version >> 8 == 3 && (0x302 < param_1->version)))) {
          iVar5 = (*param_1->method->put_cipher_by_char)((SSL_CIPHER *)0x0,(uchar *)0x0);
          local_2c = (undefined4 *)((int)local_2c + iVar5);
          st = (_STACK *)ssl_get_ciphers_by_id(param_1);
          iVar5 = sk_find(st,pSVar6);
          if (iVar5 < 0) {
            local_24 = (SSL_CIPHER *)0x2f;
            line = 0x3c1;
            iVar5 = 0x105;
          }
          else {
            pSVar12 = param_1->session;
            if (*(int *)(pSVar12->krb5_client_princ + 0x24) != 0) {
              *(undefined4 *)(pSVar12->krb5_client_princ + 0x28) =
                   *(undefined4 *)(*(int *)(pSVar12->krb5_client_princ + 0x24) + 8);
            }
            iVar5 = param_1->hit;
            if ((iVar5 == 0) || (*(ulong *)(pSVar12->krb5_client_princ + 0x28) == pSVar6->id)) {
              (param_1->s3->tmp).new_cipher = pSVar6;
              if ((param_1->version >> 8 != 3) || (param_1->version < 0x303)) {
                iVar5 = ssl3_digest_cached_records(param_1);
                if (iVar5 == 0) goto LAB_0809e648;
                iVar5 = param_1->hit;
              }
              puVar13 = (undefined4 *)((int)local_2c + 1);
              uVar9 = (uint)*(byte *)local_2c;
              local_2c = puVar13;
              if ((iVar5 == 0) || (uVar9 == *(uint *)(param_1->session->krb5_client_princ + 0x20)))
              {
                if (uVar9 == 0) {
                  pSVar7 = (SSL_COMP *)0x0;
LAB_0809e31f:
                  iVar5 = param_1->version;
                  (param_1->s3->tmp).new_compression = pSVar7;
                  if (0x2ff < iVar5) {
                    iVar5 = ssl_parse_serverhello_tlsext(param_1,&local_2c,puVar10,lVar4,&local_24);
                    if (iVar5 == 0) {
                      line = 0x418;
                      iVar5 = 0xe3;
                      goto LAB_0809e35e;
                    }
                    iVar5 = ssl_check_serverhello_tlsext(param_1);
                    if (iVar5 < 1) {
                      ERR_put_error(0x14,0x92,0x113,"s3_clnt.c",0x41d);
                      lVar4 = -1;
                      goto LAB_0809e0d3;
                    }
                  }
                  puVar10 = (undefined4 *)((int)puVar10 + lVar4);
                  lVar4 = 1;
                  if (local_2c == puVar10) goto LAB_0809e0d3;
                  local_24 = (SSL_CIPHER *)0x32;
                  line = 0x427;
                  iVar5 = 0x73;
                }
                else if ((*(byte *)((int)&param_1->references + 2) & 2) == 0) {
                  pSVar7 = (SSL_COMP *)
                           ssl3_comp_find(*(undefined4 *)(param_1->psk_server_callback + 0x98),uVar9
                                         );
                  if (pSVar7 != (SSL_COMP *)0x0) goto LAB_0809e31f;
                  local_24 = (SSL_CIPHER *)0x2f;
                  line = 0x408;
                  iVar5 = 0x101;
                }
                else {
                  local_24 = (SSL_CIPHER *)0x2f;
                  line = 0x3ff;
                  iVar5 = 0x157;
                }
              }
              else {
                local_24 = (SSL_CIPHER *)0x2f;
                line = 0x3f7;
                iVar5 = 0x158;
              }
            }
            else {
              local_24 = (SSL_CIPHER *)0x2f;
              line = 0x3d3;
              iVar5 = 0xc5;
            }
          }
        }
        else {
          local_24 = (SSL_CIPHER *)0x2f;
          line = 0x3b6;
          iVar5 = 0x105;
        }
        goto LAB_0809e35e;
      }
      uVar8 = pSVar12->session_id_length;
      param_1->hit = 0;
      if (uVar8 == 0) {
LAB_0809e1da:
        pSVar12->session_id_length = uVar9;
        local_34 = local_2c;
        if (uVar9 < 4) {
          if ((uVar9 != 0) && (pSVar12->session_id[0] = *(byte *)local_2c, (bVar1 & 2) != 0)) {
            *(undefined2 *)(pSVar12->session_id + (uVar9 - 2)) =
                 *(undefined2 *)((int)local_2c + (uVar9 - 2));
          }
        }
        else {
          *(undefined4 *)pSVar12->session_id = *local_2c;
          puVar14 = (undefined4 *)((uint)(pSVar12->session_id + 4) & 0xfffffffc);
          *(undefined4 *)(pSVar12->session_id + (uVar9 - 4)) =
               *(undefined4 *)((int)local_2c + (uVar9 - 4));
          iVar5 = (int)pSVar12->session_id - (int)puVar14;
          puVar13 = (undefined4 *)((int)local_2c - iVar5);
          for (uVar8 = iVar5 + uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar14 = *puVar13;
            puVar13 = puVar13 + (uint)bVar15 * -2 + 1;
            puVar14 = puVar14 + (uint)bVar15 * -2 + 1;
          }
        }
        goto LAB_0809e203;
      }
LAB_0809e460:
      iVar5 = ssl_get_new_session(param_1,0);
      if (iVar5 != 0) {
        pSVar12 = param_1->session;
        goto LAB_0809e1da;
      }
LAB_0809e648:
      local_24 = (SSL_CIPHER *)0x50;
    }
    else {
      local_2c = puVar10;
      ERR_put_error(0x14,0x92,0x10a,"s3_clnt.c",0x364);
      local_24 = (SSL_CIPHER *)0x46;
      param_1->version = (uint)*(byte *)((int)local_2c + 1) | param_1->version & 0xff00U;
    }
  }
  ssl3_send_alert(param_1,2,local_24);
  lVar4 = -1;
LAB_0809e0d3:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar4;
}

