
long ssl3_get_server_hello(SSL *param_1)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  SSL_CIPHER *pSVar4;
  _STACK *st;
  byte *pbVar5;
  SSL_COMP *pSVar6;
  int iVar7;
  SSL_SESSION *pSVar8;
  byte *pbVar9;
  ssl3_state_st *psVar10;
  undefined4 uVar11;
  uint __n;
  SSL_SESSION *pSVar12;
  code *pcVar13;
  undefined4 uVar14;
  byte *local_30;
  undefined4 local_2c;
  int local_28;
  SSL_CIPHER *local_24 [2];
  
  lVar1 = (*param_1->method->ssl_get_message)(param_1,0x1120,0x1121,-1,20000,&local_28);
  if (local_28 == 0) {
    return lVar1;
  }
  iVar2 = SSL_version(param_1);
  if ((iVar2 == 0xfeff) || (iVar2 = SSL_version(param_1), iVar2 == 0x100)) {
    psVar10 = param_1->s3;
    iVar2 = (psVar10->tmp).message_type;
    if (iVar2 != 3) goto LAB_00047e20;
    if (param_1->d1->send_cookie == 0) {
      (psVar10->tmp).reuse_message = 1;
      return 1;
    }
    iVar2 = 0x361;
LAB_00048160:
    local_2c = 10;
    ERR_put_error(0x14,0x92,0x72,"s3_clnt.c",iVar2);
  }
  else {
    psVar10 = param_1->s3;
    iVar2 = (psVar10->tmp).message_type;
LAB_00047e20:
    if (iVar2 != 2) {
      iVar2 = 0x369;
      goto LAB_00048160;
    }
    pbVar9 = (byte *)param_1->init_msg;
    if (((uint)*pbVar9 == param_1->version >> 8) && ((uint)pbVar9[1] == (param_1->version & 0xffU)))
    {
      uVar14 = *(undefined4 *)(pbVar9 + 10);
      uVar3 = *(undefined4 *)(pbVar9 + 0xe);
      local_30 = pbVar9 + 0x23;
      uVar11 = *(undefined4 *)(pbVar9 + 2);
      *(undefined4 *)(psVar10->server_random + 4) = *(undefined4 *)(pbVar9 + 6);
      *(undefined4 *)(psVar10->server_random + 8) = uVar14;
      *(undefined4 *)psVar10->server_random = uVar11;
      *(undefined4 *)(psVar10->server_random + 0xc) = uVar3;
      uVar11 = *(undefined4 *)(pbVar9 + 0x16);
      uVar14 = *(undefined4 *)(pbVar9 + 0x1a);
      uVar3 = *(undefined4 *)(pbVar9 + 0x1e);
      *(undefined4 *)(psVar10->server_random + 0x10) = *(undefined4 *)(pbVar9 + 0x12);
      *(undefined4 *)(psVar10->server_random + 0x14) = uVar11;
      *(undefined4 *)(psVar10->server_random + 0x18) = uVar14;
      *(undefined4 *)(psVar10->server_random + 0x1c) = uVar3;
      param_1->hit = 0;
      __n = (uint)pbVar9[0x22];
      if (__n < 0x21) {
        if ((param_1->version < 0x301) ||
           (pcVar13 = (code *)param_1->tls_session_ticket_ext_cb_arg, pcVar13 == (code *)0x0)) {
          pSVar12 = param_1->session;
        }
        else {
          pSVar12 = param_1->session;
          if (*(int *)(pSVar12->krb5_client_princ + 0x54) != 0) {
            pSVar12->master_key_length = 0x30;
            local_24[0] = (SSL_CIPHER *)0x0;
            iVar2 = (*pcVar13)(param_1,pSVar12->master_key,&pSVar12->master_key_length,0,local_24,
                               param_1->tls_session_secret_cb);
            if (iVar2 == 0) {
              ERR_put_error(0x14,0x92,0x44,"s3_clnt.c",0x39e);
              local_2c = 0x50;
              goto LAB_000480aa;
            }
            pSVar8 = param_1->session;
            pSVar4 = local_24[0];
            pSVar12 = pSVar8;
            if (local_24[0] == (SSL_CIPHER *)0x0) {
              pSVar4 = (*param_1->method->get_cipher_by_char)(local_30 + __n);
              pSVar12 = param_1->session;
            }
            *(SSL_CIPHER **)(pSVar8->krb5_client_princ + 0x24) = pSVar4;
          }
        }
        pbVar5 = local_30;
        if ((__n == 0) || (pSVar12->session_id_length != __n)) {
          if (pSVar12->session_id_length != 0) goto LAB_00048064;
LAB_00047f2a:
          pSVar12->session_id_length = __n;
          memcpy(pSVar12->session_id,local_30,__n);
          pbVar5 = local_30;
LAB_00047f3c:
          local_30 = pbVar5 + __n;
          pSVar4 = (*param_1->method->get_cipher_by_char)(local_30);
          pbVar5 = local_30;
          if (pSVar4 == (SSL_CIPHER *)0x0) {
            local_2c = 0x2f;
            ERR_put_error(0x14,0x92,0xf8,"s3_clnt.c",0x3c6);
          }
          else if (((int)(pSVar4->algorithm_ssl << 0x1d) < 0) &&
                  ((param_1->version >> 8 != 3 || (param_1->version < 0x303)))) {
            local_2c = 0x2f;
            ERR_put_error(0x14,0x92,0x105,"s3_clnt.c",0x3cd);
          }
          else {
            if ((((int)(pSVar4->algorithm_mkey << 0x15) < 0) ||
                ((int)(pSVar4->algorithm_auth << 0x15) < 0)) && (-1 < param_1[1].rstate << 0x15)) {
              iVar2 = 0x3d4;
            }
            else {
              iVar2 = (*param_1->method->put_cipher_by_char)((SSL_CIPHER *)0x0,(uchar *)0x0);
              local_30 = pbVar5 + iVar2;
              st = (_STACK *)ssl_get_ciphers_by_id(param_1);
              iVar2 = sk_find(st,pSVar4);
              if (-1 < iVar2) {
                pSVar12 = param_1->session;
                if (*(int *)(pSVar12->krb5_client_princ + 0x24) != 0) {
                  *(undefined4 *)(pSVar12->krb5_client_princ + 0x28) =
                       *(undefined4 *)(*(int *)(pSVar12->krb5_client_princ + 0x24) + 8);
                }
                iVar2 = param_1->hit;
                if ((iVar2 == 0) || (*(ulong *)(pSVar12->krb5_client_princ + 0x28) == pSVar4->id)) {
                  iVar7 = param_1->version;
                  (param_1->s3->tmp).new_cipher = pSVar4;
                  if ((iVar7 >> 8 != 3) || (iVar7 < 0x303)) {
                    iVar2 = ssl3_digest_cached_records(param_1);
                    if (iVar2 == 0) goto LAB_00048178;
                    iVar2 = param_1->hit;
                  }
                  pbVar5 = local_30 + 1;
                  pSVar6 = (SSL_COMP *)(uint)*local_30;
                  local_30 = pbVar5;
                  if ((iVar2 == 0) ||
                     (*(SSL_COMP **)(param_1->session->krb5_client_princ + 0x20) == pSVar6)) {
                    if (pSVar6 == (SSL_COMP *)0x0) {
LAB_00048028:
                      iVar2 = param_1->version;
                      (param_1->s3->tmp).new_compression = pSVar6;
                      if (0x2ff < iVar2) {
                        iVar2 = ssl_parse_serverhello_tlsext
                                          (param_1,&local_30,pbVar9,lVar1,&local_2c);
                        if (iVar2 == 0) {
                          ERR_put_error(0x14,0x92,0xe3,"s3_clnt.c",0x432);
                          goto LAB_000480aa;
                        }
                        iVar2 = ssl_check_serverhello_tlsext(param_1);
                        if (iVar2 < 1) {
                          ERR_put_error(0x14,0x92,0x113,"s3_clnt.c",0x436);
                          goto LAB_000480b2;
                        }
                      }
                      if (local_30 == pbVar9 + lVar1) {
                        return 1;
                      }
                      local_2c = 0x32;
                      ERR_put_error(0x14,0x92,0x73,"s3_clnt.c",0x43f);
                    }
                    else if (param_1->references << 0xe < 0) {
                      local_2c = 0x2f;
                      ERR_put_error(0x14,0x92,0x157,"s3_clnt.c",0x41e);
                    }
                    else {
                      pSVar6 = (SSL_COMP *)
                               ssl3_comp_find(*(undefined4 *)(param_1->psk_server_callback + 0x98));
                      if (pSVar6 != (SSL_COMP *)0x0) goto LAB_00048028;
                      local_2c = 0x2f;
                      ERR_put_error(0x14,0x92,0x101,"s3_clnt.c",0x426);
                    }
                  }
                  else {
                    local_2c = 0x2f;
                    ERR_put_error(0x14,0x92,0x158,"s3_clnt.c",0x417);
                  }
                }
                else {
                  local_2c = 0x2f;
                  ERR_put_error(0x14,0x92,0xc5,"s3_clnt.c",0x3f2);
                }
                goto LAB_000480aa;
              }
              iVar2 = 0x3df;
            }
            local_2c = 0x2f;
            ERR_put_error(0x14,0x92,0x105,"s3_clnt.c",iVar2);
          }
        }
        else {
          iVar2 = memcmp(local_30,pSVar12->session_id,__n);
          if (iVar2 == 0) {
            if ((param_1->sid_ctx_length != pSVar12->sid_ctx_length) ||
               (iVar2 = memcmp(pSVar12->sid_ctx,param_1->sid_ctx,param_1->sid_ctx_length),
               iVar2 != 0)) {
              local_2c = 0x2f;
              ERR_put_error(0x14,0x92,0x110,"s3_clnt.c",0x3ac);
              goto LAB_000480aa;
            }
            param_1->hit = 1;
            goto LAB_00047f3c;
          }
LAB_00048064:
          iVar2 = ssl_get_new_session(param_1,0);
          if (iVar2 != 0) {
            pSVar12 = param_1->session;
            goto LAB_00047f2a;
          }
LAB_00048178:
          local_2c = 0x50;
        }
      }
      else {
        local_2c = 0x2f;
        ERR_put_error(0x14,0x92,300,"s3_clnt.c",899);
      }
    }
    else {
      local_30 = pbVar9;
      ERR_put_error(0x14,0x92,0x10a,"s3_clnt.c",0x370);
      local_2c = 0x46;
      param_1->version = param_1->version & 0xff00U | (uint)local_30[1];
    }
  }
LAB_000480aa:
  ssl3_send_alert(param_1,2,local_2c);
LAB_000480b2:
  param_1->state = 5;
  return -1;
}

