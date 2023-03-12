
int ssl3_get_client_hello(SSL *param_1)

{
  _STACK *p_Var1;
  long lVar2;
  long lVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  stack_st_SSL_CIPHER *psVar7;
  SSL_CIPHER *pSVar8;
  SSL_CIPHER *pSVar9;
  undefined4 *puVar10;
  uint uVar11;
  int iVar12;
  SSL_SESSION *pSVar13;
  SSL_COMP *pSVar14;
  int iVar15;
  undefined4 uVar16;
  undefined4 *puVar17;
  dtls1_state_st *pdVar18;
  undefined *puVar19;
  SSL_COMP *pSVar20;
  int iVar21;
  _STACK *p_Var22;
  SSL_CIPHER *pSVar23;
  ssl3_state_st *psVar24;
  uint uVar25;
  uint uVar26;
  code *pcVar27;
  undefined4 uVar28;
  byte *pbVar29;
  bool bVar30;
  undefined4 *local_40 [2];
  int local_38;
  undefined4 local_34;
  _STACK *local_30;
  _STACK *local_2c [2];
  
  iVar15 = param_1->state;
  bVar30 = iVar15 == 0x2110;
  if (bVar30) {
    iVar15 = 0x2111;
  }
  param_1->max_cert_list = 1;
  if (bVar30) {
    param_1->state = iVar15;
  }
  local_30 = (_STACK *)0x0;
  lVar2 = (*param_1->method->ssl_get_message)(param_1,0x2111,0x2112,1,0x4000,&local_38);
  if (local_38 == 0) {
    return lVar2;
  }
  puVar19 = (undefined *)param_1->init_msg;
  param_1->max_cert_list = 0;
  local_40[0] = (undefined4 *)(puVar19 + 2);
  uVar11 = (uint)CONCAT11(*puVar19,puVar19[1]);
  param_1->first_packet = uVar11;
  if (param_1->version == 0xfeff) {
    if (uVar11 < 0xff00) goto LAB_00047a94;
LAB_00047a44:
    ERR_put_error(0x14,0x8a,0x10b,"s3_srvr.c",0x3c0);
    if (((param_1->first_packet >> 8 == 3) && (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0)) &&
       (param_1->write_hash == (EVP_MD_CTX *)0x0)) {
      param_1->version = param_1->first_packet;
    }
    iVar15 = -1;
    local_34 = 0x46;
  }
  else {
    if ((int)uVar11 < param_1->version) goto LAB_00047a44;
LAB_00047a94:
    lVar3 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((lVar3 << 0x12 < 0) &&
       (*(byte *)((int)local_40[0] + *(byte *)(local_40[0] + 8) + 0x21) == 0)) {
      return 1;
    }
    puVar10 = (undefined4 *)((int)local_40[0] + 0x21);
    uVar28 = local_40[0][1];
    uVar4 = local_40[0][2];
    uVar16 = local_40[0][3];
    psVar24 = param_1->s3;
    *(undefined4 *)psVar24->client_random = *local_40[0];
    *(undefined4 *)(psVar24->client_random + 4) = uVar28;
    *(undefined4 *)(psVar24->client_random + 8) = uVar4;
    *(undefined4 *)(psVar24->client_random + 0xc) = uVar16;
    uVar4 = local_40[0][7];
    uVar16 = local_40[0][4];
    uVar28 = local_40[0][5];
    *(undefined4 *)(psVar24->client_random + 0x18) = local_40[0][6];
    *(undefined4 *)(psVar24->client_random + 0x10) = uVar16;
    *(undefined4 *)(psVar24->client_random + 0x14) = uVar28;
    *(undefined4 *)(psVar24->client_random + 0x1c) = uVar4;
    uVar11 = (uint)*(byte *)(local_40[0] + 8);
    param_1->hit = 0;
    local_40[0] = puVar10;
    if ((param_1->new_session == 0) || (-1 < param_1->references << 0xf)) {
      iVar15 = ssl_get_prev_session(param_1,puVar10,uVar11,puVar19 + lVar2);
      if (iVar15 != 1) {
        if (iVar15 != -1) goto LAB_00047b28;
        goto LAB_00047bae;
      }
      param_1->hit = 1;
    }
    else {
LAB_00047b28:
      iVar15 = ssl_get_new_session(param_1,1);
      if (iVar15 == 0) {
LAB_00047bae:
        iVar15 = -1;
        goto LAB_00047a7a;
      }
    }
    pbVar29 = (byte *)((int)local_40[0] + uVar11);
    if (param_1->version == 0xfeff || param_1->version == 0x100) {
      uVar25 = (uint)*(byte *)((int)local_40[0] + uVar11);
      local_40[0] = (undefined4 *)(pbVar29 + 1);
      lVar3 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
      if ((lVar3 << 0x12 < 0) && (uVar25 != 0)) {
        memcpy(param_1->d1->rcvd_cookie,local_40[0],uVar25);
        if (*(code **)(param_1->psk_server_callback + 0x7c) == (code *)0x0) {
          pdVar18 = param_1->d1;
          iVar15 = memcmp(pdVar18->rcvd_cookie,pdVar18->cookie,pdVar18->cookie_len);
          if (iVar15 == 0) goto LAB_00047ba0;
          iVar12 = 0x42d;
        }
        else {
          iVar15 = (**(code **)(param_1->psk_server_callback + 0x7c))
                             (param_1,param_1->d1->rcvd_cookie,uVar25);
          if (iVar15 != 0) {
LAB_00047ba0:
            iVar15 = 2;
            goto LAB_00047c88;
          }
          iVar12 = 0x423;
        }
        iVar15 = -1;
        local_34 = 0x28;
        ERR_put_error(0x14,0x8a,0x134,"s3_srvr.c",iVar12);
        goto LAB_00047a72;
      }
      iVar15 = -1;
LAB_00047c88:
      pbVar29 = (byte *)((int)local_40[0] + uVar25);
    }
    else {
      iVar15 = -1;
    }
    local_40[0] = (undefined4 *)(pbVar29 + 2);
    uVar26 = (uint)CONCAT11(*pbVar29,pbVar29[1]);
    uVar25 = (uint)(uVar26 == 0);
    if (uVar11 == 0) {
      uVar25 = 0;
    }
    if (uVar25 == 0) {
      if ((undefined4 *)((int)local_40[0] + uVar26) < puVar19 + lVar2) {
        puVar10 = (undefined4 *)((int)local_40[0] + uVar26);
        if (uVar26 != 0) {
          iVar12 = ssl_bytes_to_cipher_list(param_1,local_40[0],uVar26,&local_30);
          if (iVar12 == 0) goto LAB_00047a7a;
          local_40[0] = (undefined4 *)((int)local_40[0] + uVar26);
          puVar10 = local_40[0];
          if (param_1->hit != 0) {
            iVar12 = *(int *)(*(int *)(param_1->session->krb5_client_princ + 0x24) + 8);
            do {
              iVar6 = sk_num(local_30);
              if (iVar6 <= (int)uVar25) {
                local_34 = 0x2f;
                ERR_put_error(0x14,0x8a,0xd7,"s3_srvr.c",0x47b);
                goto LAB_00047a72;
              }
              pvVar5 = sk_value(local_30,uVar25);
              puVar10 = local_40[0];
              uVar25 = uVar25 + 1;
            } while (*(int *)((int)pvVar5 + 8) != iVar12);
          }
        }
        puVar17 = (undefined4 *)((int)puVar10 + 1);
        uVar11 = (uint)*(byte *)puVar10;
        local_40[0] = (undefined4 *)((int)puVar17 + uVar11);
        if (local_40[0] <= puVar19 + lVar2) {
          if (uVar11 == 0) {
LAB_00047cde:
            local_34 = 0x32;
            ERR_put_error(0x14,0x8a,0xbb,"s3_srvr.c",0x494);
          }
          else {
            if (*(byte *)((int)puVar10 + 1) != 0) {
              do {
                if (puVar17 == (undefined4 *)((int)puVar10 + uVar11)) goto LAB_00047cde;
                puVar17 = (undefined4 *)((int)puVar17 + 1);
              } while (*(byte *)puVar17 != 0);
            }
            if ((param_1->version < 0x300) ||
               (iVar12 = ssl_parse_clienthello_tlsext(param_1,local_40,puVar19,lVar2,&local_34),
               iVar12 != 0)) {
              iVar12 = ssl_check_clienthello_tlsext_early(param_1);
              if (iVar12 < 1) {
                iVar12 = 0x4a4;
LAB_00047f12:
                ERR_put_error(0x14,0x8a,0xe2,"s3_srvr.c",iVar12);
                goto LAB_00047a7a;
              }
              iVar12 = ssl_fill_hello_random(param_1,1,param_1->s3->server_random,0x20);
              if (iVar12 < 1) {
LAB_00047eec:
                local_34 = 0x50;
              }
              else {
                p_Var22 = (_STACK *)param_1->hit;
                if (((p_Var22 != (_STACK *)0x0) || (param_1->version < 0x301)) ||
                   (pcVar27 = (code *)param_1->tls_session_ticket_ext_cb_arg, pcVar27 == (code *)0x0
                   )) {
LAB_00047df4:
                  pSVar13 = param_1->session;
                  uVar25 = *(uint *)(pSVar13->krb5_client_princ + 0x20);
                  (param_1->s3->tmp).new_compression = (SSL_COMP *)0x0;
                  if (uVar25 != 0) {
                    pSVar20 = (SSL_COMP *)(param_1->references & 0x20000);
                    pSVar14 = pSVar20;
                    if (pSVar20 == (SSL_COMP *)0x0) {
                      do {
                        iVar12 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
                        if (iVar12 <= (int)pSVar20) {
                          psVar24 = param_1->s3;
                          goto LAB_00047e48;
                        }
                        pSVar14 = (SSL_COMP *)
                                  sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),
                                           (int)pSVar20);
                        pSVar20 = (SSL_COMP *)((int)&pSVar20->id + 1);
                      } while (pSVar14->id != uVar25);
                      psVar24 = param_1->s3;
                      (psVar24->tmp).new_compression = pSVar14;
LAB_00047e48:
                      if ((psVar24->tmp).new_compression == (SSL_COMP *)0x0) {
                        local_34 = 0x50;
                        ERR_put_error(0x14,0x8a,0x155,"s3_srvr.c",0x4f9);
                      }
                      else {
                        iVar12 = 0;
                        do {
                          puVar10 = (undefined4 *)((int)puVar10 + 1);
                          if (*(byte *)puVar10 == uVar25) {
                            if (iVar12 < (int)uVar11) goto LAB_00047e6c;
                            break;
                          }
                          iVar12 = iVar12 + 1;
                        } while (iVar12 < (int)uVar11);
                        local_34 = 0x2f;
                        ERR_put_error(0x14,0x8a,0x156,"s3_srvr.c",0x505);
                      }
                    }
                    else {
                      local_34 = 0x50;
                      ERR_put_error(0x14,0x8a,0x154,"s3_srvr.c",0x4e9);
                    }
                    goto LAB_00047a72;
                  }
                  if (param_1->hit == 0) {
                    uVar25 = param_1->references & 0x20000;
                    if ((uVar25 == 0) &&
                       (*(_STACK **)(param_1->psk_server_callback + 0x98) != (_STACK *)0x0)) {
                      uVar26 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
                      if (0 < (int)uVar26) {
                        do {
                          pSVar14 = (SSL_COMP *)
                                    sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),
                                             uVar25);
                          puVar17 = puVar10;
                          do {
                            puVar17 = (undefined4 *)((int)puVar17 + 1);
                            if ((uint)*(byte *)puVar17 == pSVar14->id) {
                              (param_1->s3->tmp).new_compression = pSVar14;
                              goto LAB_00047e6c;
                            }
                          } while (puVar17 != (undefined4 *)((int)puVar10 + uVar11));
                          uVar25 = uVar25 + 1;
                        } while (uVar25 != uVar26);
                      }
                      pSVar14 = (SSL_COMP *)0x0;
LAB_00047e6c:
                      if (param_1->hit != 0) {
                        pSVar13 = param_1->session;
                        goto LAB_00047f80;
                      }
                      pSVar13 = param_1->session;
                      if (pSVar14 != (SSL_COMP *)0x0) {
                        pSVar14 = (SSL_COMP *)pSVar14->id;
                      }
                    }
                    else {
                      pSVar14 = (SSL_COMP *)0x0;
                    }
                    *(SSL_COMP **)(pSVar13->krb5_client_princ + 0x20) = pSVar14;
                    if (*(_STACK **)(pSVar13->krb5_client_princ + 0x2c) != (_STACK *)0x0) {
                      sk_free(*(_STACK **)(pSVar13->krb5_client_princ + 0x2c));
                      pSVar13 = param_1->session;
                    }
                    p_Var22 = local_30;
                    *(_STACK **)(pSVar13->krb5_client_princ + 0x2c) = local_30;
                    if (local_30 == (_STACK *)0x0) {
                      local_34 = 0x2f;
                      ERR_put_error(0x14,0x8a,0xb6,"s3_srvr.c",0x53f);
                      goto LAB_00047a72;
                    }
                    local_30 = (_STACK *)0x0;
                    psVar7 = SSL_get_ciphers(param_1);
                    pSVar8 = (SSL_CIPHER *)ssl3_choose_cipher(param_1,p_Var22,psVar7);
                    if (pSVar8 == (SSL_CIPHER *)0x0) {
                      iVar12 = 0x549;
                      goto LAB_000480e4;
                    }
                    (param_1->s3->tmp).new_cipher = pSVar8;
                  }
                  else {
LAB_00047f80:
                    if (param_1->references << 1 < 0) {
                      p_Var22 = *(_STACK **)(pSVar13->krb5_client_princ + 0x2c);
                      pSVar23 = (SSL_CIPHER *)0x0;
                      iVar12 = 0;
                      pSVar8 = (SSL_CIPHER *)0x0;
                      while( true ) {
                        iVar6 = sk_num(p_Var22);
                        iVar21 = iVar12 + 1;
                        if (iVar6 <= iVar12) break;
                        pSVar9 = (SSL_CIPHER *)sk_value(p_Var22,iVar12);
                        if ((pSVar9->algorithm_enc & 0x20) != 0) {
                          pSVar23 = pSVar9;
                        }
                        iVar12 = iVar21;
                        if ((pSVar9->algo_strength & 2) != 0) {
                          pSVar8 = pSVar9;
                        }
                      }
                      if (pSVar23 == (SSL_CIPHER *)0x0) {
                        if (pSVar8 == (SSL_CIPHER *)0x0) {
                          (param_1->s3->tmp).new_cipher =
                               *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24);
                        }
                        else {
                          (param_1->s3->tmp).new_cipher = pSVar8;
                        }
                      }
                      else {
                        (param_1->s3->tmp).new_cipher = pSVar23;
                      }
                    }
                    else {
                      (param_1->s3->tmp).new_cipher =
                           *(SSL_CIPHER **)(pSVar13->krb5_client_princ + 0x24);
                    }
                  }
                  iVar12 = param_1->version;
                  if (((iVar12 >> 8 != 3) || (iVar12 < 0x303)) ||
                     (-1 < param_1->verify_mode << 0x1f)) {
                    iVar12 = ssl3_digest_cached_records(param_1);
                    if (iVar12 == 0) goto LAB_00047eec;
                    iVar12 = param_1->version;
                  }
                  if ((iVar12 < 0x300) ||
                     (iVar12 = ssl_check_clienthello_tlsext_late(param_1), 0 < iVar12)) {
                    if (iVar15 == -1) {
                      iVar15 = 1;
                    }
                    goto LAB_00047a7a;
                  }
                  iVar12 = 0x586;
                  goto LAB_00047f12;
                }
                pSVar13 = param_1->session;
                pSVar13->master_key_length = 0x30;
                local_2c[0] = p_Var22;
                iVar12 = (*pcVar27)(param_1,pSVar13->master_key,&pSVar13->master_key_length,local_30
                                    ,local_2c,param_1->tls_session_secret_cb);
                p_Var1 = local_30;
                if (iVar12 == 0) goto LAB_00047df4;
                pSVar13 = param_1->session;
                param_1->hit = 1;
                *(undefined4 *)(pSVar13->krb5_client_princ + 0x10) = 0;
                *(_STACK **)(pSVar13->krb5_client_princ + 0x2c) = local_30;
                local_30 = p_Var22;
                if (local_2c[0] != (_STACK *)0x0) {
LAB_00047dc4:
                  p_Var22 = (_STACK *)param_1->cipher_list;
                  *(_STACK **)(pSVar13->krb5_client_princ + 0x24) = local_2c[0];
                  if (p_Var22 != (_STACK *)0x0) {
                    sk_free(p_Var22);
                  }
                  if ((_STACK *)param_1->cipher_list_by_id != (_STACK *)0x0) {
                    sk_free((_STACK *)param_1->cipher_list_by_id);
                  }
                  p_Var22 = sk_dup(*(_STACK **)(param_1->session->krb5_client_princ + 0x2c));
                  param_1->cipher_list = (stack_st_SSL_CIPHER *)p_Var22;
                  p_Var22 = sk_dup(*(_STACK **)(param_1->session->krb5_client_princ + 0x2c));
                  param_1->cipher_list_by_id = (stack_st_SSL_CIPHER *)p_Var22;
                  goto LAB_00047df4;
                }
                psVar7 = SSL_get_ciphers(param_1);
                local_2c[0] = (_STACK *)ssl3_choose_cipher(param_1,p_Var1,psVar7);
                if (local_2c[0] != (_STACK *)0x0) {
                  pSVar13 = param_1->session;
                  goto LAB_00047dc4;
                }
                iVar12 = 0x4c9;
LAB_000480e4:
                local_34 = 0x28;
                ERR_put_error(0x14,0x8a,0xc1,"s3_srvr.c",iVar12);
              }
            }
            else {
              ERR_put_error(0x14,0x8a,0xe3,"s3_srvr.c",0x49f);
            }
          }
          goto LAB_00047a72;
        }
        iVar12 = 0x486;
        local_40[0] = puVar17;
      }
      else {
        iVar12 = 0x443;
      }
      local_34 = 0x32;
      ERR_put_error(0x14,0x8a,0x9f,"s3_srvr.c",iVar12);
    }
    else {
      local_34 = 0x2f;
      ERR_put_error(0x14,0x8a,0xb7,"s3_srvr.c",0x43c);
    }
  }
LAB_00047a72:
  ssl3_send_alert(param_1,2,local_34);
LAB_00047a7a:
  if (local_30 != (_STACK *)0x0) {
    sk_free(local_30);
    return iVar15;
  }
  return iVar15;
}

