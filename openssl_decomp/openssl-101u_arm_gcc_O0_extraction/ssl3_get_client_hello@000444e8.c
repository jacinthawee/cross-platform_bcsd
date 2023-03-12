
long ssl3_get_client_hello(SSL *param_1)

{
  byte bVar1;
  _STACK *p_Var2;
  long lVar3;
  long lVar4;
  undefined4 uVar5;
  uint uVar6;
  void *pvVar7;
  int iVar8;
  SSL_SESSION *pSVar9;
  stack_st_SSL_CIPHER *psVar10;
  SSL_CIPHER *pSVar11;
  SSL_CIPHER *pSVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  SSL_COMP *pSVar15;
  int iVar16;
  uint uVar17;
  undefined4 uVar18;
  SSL_COMP *pSVar19;
  dtls1_state_st *pdVar20;
  undefined4 *puVar21;
  byte *pbVar22;
  SSL_CIPHER *pSVar23;
  int iVar24;
  undefined4 *puVar25;
  _STACK *p_Var26;
  uint uVar27;
  ssl3_state_st *psVar28;
  code *pcVar29;
  bool bVar30;
  undefined4 *local_40 [2];
  int local_38;
  undefined4 local_34;
  _STACK *local_30;
  _STACK *local_2c [2];
  
  iVar16 = param_1->state;
  bVar30 = iVar16 == 0x2110;
  if (bVar30) {
    iVar16 = 0x2111;
  }
  param_1->max_cert_list = 1;
  if (bVar30) {
    param_1->state = iVar16;
  }
  local_30 = (_STACK *)0x0;
  lVar3 = (*param_1->method->ssl_get_message)(param_1,0x2111,0x2112,1,0x4000,&local_38);
  if (local_38 == 0) {
    return lVar3;
  }
  puVar21 = (undefined4 *)param_1->init_msg;
  param_1->max_cert_list = 0;
  if (lVar3 < 0x23) {
    iVar16 = 0x3ef;
    local_40[0] = puVar21;
    goto LAB_0004459e;
  }
  local_40[0] = (undefined4 *)((int)puVar21 + 2);
  uVar17 = (uint)CONCAT11(*(byte *)puVar21,*(byte *)((int)puVar21 + 1));
  param_1->first_packet = uVar17;
  if (param_1->version != 0xfeff) {
    if (param_1->version <= (int)uVar17) goto LAB_000445de;
LAB_0004456a:
    ERR_put_error(0x14,0x8a,0x10b,"s3_srvr.c",0x3fc);
    if (((param_1->first_packet >> 8 == 3) && (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0)) &&
       (param_1->write_hash == (EVP_MD_CTX *)0x0)) {
      param_1->version = param_1->first_packet;
    }
    local_34 = 0x46;
    goto LAB_000445b4;
  }
  if (0xfeff < uVar17) goto LAB_0004456a;
LAB_000445de:
  lVar4 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
  if (lVar4 << 0x12 < 0) {
    if ((byte *)((int)puVar21 + (lVar3 - (int)local_40[0])) <=
        (byte *)(*(byte *)(local_40[0] + 8) + 0x21)) {
      iVar16 = 0x415;
      goto LAB_0004459e;
    }
    if (*(byte *)((int)local_40[0] + (int)(byte *)(*(byte *)(local_40[0] + 8) + 0x21)) == 0) {
      return 1;
    }
  }
  pbVar22 = (byte *)(lVar3 + (int)puVar21);
  puVar21 = (undefined4 *)((int)local_40[0] + 0x21);
  uVar5 = local_40[0][1];
  uVar13 = local_40[0][2];
  uVar18 = local_40[0][3];
  psVar28 = param_1->s3;
  *(undefined4 *)psVar28->client_random = *local_40[0];
  *(undefined4 *)(psVar28->client_random + 4) = uVar5;
  *(undefined4 *)(psVar28->client_random + 8) = uVar13;
  *(undefined4 *)(psVar28->client_random + 0xc) = uVar18;
  uVar13 = local_40[0][7];
  uVar18 = local_40[0][4];
  uVar5 = local_40[0][5];
  *(undefined4 *)(psVar28->client_random + 0x18) = local_40[0][6];
  *(undefined4 *)(psVar28->client_random + 0x1c) = uVar13;
  *(undefined4 *)(psVar28->client_random + 0x10) = uVar18;
  *(undefined4 *)(psVar28->client_random + 0x14) = uVar5;
  uVar17 = (uint)*(byte *)(local_40[0] + 8);
  local_40[0] = puVar21;
  if ((int)pbVar22 - (int)puVar21 < (int)uVar17) {
    iVar16 = 0x427;
    goto LAB_0004459e;
  }
  if (0x20 < uVar17) {
    iVar16 = 0x42d;
    goto LAB_0004471c;
  }
  param_1->hit = 0;
  if ((param_1->new_session == 0) || (-1 < param_1->references << 0xf)) {
    iVar16 = ssl_get_prev_session(param_1,puVar21,uVar17,pbVar22);
    if (iVar16 == 1) {
      iVar16 = param_1->version;
      if (iVar16 != param_1->session->ssl_version) goto LAB_0004467a;
      param_1->hit = 1;
      goto LAB_00044686;
    }
    if (iVar16 != -1) goto LAB_0004467a;
  }
  else {
LAB_0004467a:
    iVar16 = ssl_get_new_session(param_1,1);
    if (iVar16 != 0) {
      iVar16 = param_1->version;
LAB_00044686:
      puVar21 = (undefined4 *)((int)local_40[0] + uVar17);
      uVar6 = (uint)(iVar16 == 0xfeff || iVar16 == 0x100);
      if (iVar16 == 0xfeff || iVar16 == 0x100) {
        if ((int)pbVar22 - (int)puVar21 < 1) {
          iVar16 = 0x45f;
          local_40[0] = puVar21;
        }
        else {
          puVar21 = (undefined4 *)((int)puVar21 + 1);
          uVar17 = (uint)*(byte *)((int)local_40[0] + uVar17);
          local_40[0] = puVar21;
          if (uVar17 <= (uint)((int)pbVar22 - (int)puVar21)) {
            uVar6 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
            uVar6 = uVar6 & 0x2000;
            if ((uVar6 != 0) && (uVar6 = uVar17, uVar17 != 0)) {
              memcpy(param_1->d1->rcvd_cookie,local_40[0],uVar17);
              if (*(code **)(param_1->psk_server_callback + 0x7c) == (code *)0x0) {
                pdVar20 = param_1->d1;
                iVar16 = memcmp(pdVar20->rcvd_cookie,pdVar20->cookie,pdVar20->cookie_len);
                if (iVar16 == 0) goto LAB_00044a12;
                iVar16 = 0x488;
              }
              else {
                iVar16 = (**(code **)(param_1->psk_server_callback + 0x7c))
                                   (param_1,param_1->d1->rcvd_cookie,uVar17);
                if (iVar16 != 0) {
LAB_00044a12:
                  uVar6 = 1;
                  goto LAB_000446e8;
                }
                iVar16 = 0x47f;
              }
              local_34 = 0x28;
              ERR_put_error(0x14,0x8a,0x134,"s3_srvr.c",iVar16);
              goto LAB_000445b4;
            }
LAB_000446e8:
            puVar21 = (undefined4 *)((int)local_40[0] + uVar17);
            goto LAB_000446ee;
          }
          iVar16 = 0x466;
        }
LAB_0004459e:
        local_34 = 0x32;
        ERR_put_error(0x14,0x8a,0xa0,"s3_srvr.c",iVar16);
      }
      else {
LAB_000446ee:
        if ((int)pbVar22 - (int)puVar21 < 2) {
          iVar16 = 0x493;
          local_40[0] = puVar21;
          goto LAB_0004459e;
        }
        local_40[0] = (undefined4 *)((int)puVar21 + 2);
        uVar17 = (uint)CONCAT11(*(byte *)puVar21,*(byte *)((int)puVar21 + 1));
        if (uVar17 == 0) {
          local_34 = 0x2f;
          ERR_put_error(0x14,0x8a,0xb7,"s3_srvr.c",0x49a);
          goto LAB_000445b4;
        }
        if ((int)pbVar22 - (int)local_40[0] <= (int)uVar17) {
          iVar16 = 0x4a2;
LAB_0004471c:
          local_34 = 0x32;
          ERR_put_error(0x14,0x8a,0x9f,"s3_srvr.c",iVar16);
          goto LAB_000445b4;
        }
        iVar16 = ssl_bytes_to_cipher_list(param_1,local_40[0],uVar17,&local_30);
        if (iVar16 == 0) goto LAB_000445bc;
        local_40[0] = (undefined4 *)(uVar17 + (int)local_40[0]);
        puVar21 = local_40[0];
        if (param_1->hit != 0) {
          iVar24 = *(int *)(*(int *)(param_1->session->krb5_client_princ + 0x24) + 8);
          iVar16 = 0;
          do {
            iVar8 = sk_num(local_30);
            if (iVar8 <= iVar16) {
              local_34 = 0x2f;
              ERR_put_error(0x14,0x8a,0xd7,"s3_srvr.c",0x4da);
              goto LAB_000445b4;
            }
            pvVar7 = sk_value(local_30,iVar16);
            puVar21 = local_40[0];
            iVar16 = iVar16 + 1;
          } while (*(int *)((int)pvVar7 + 8) != iVar24);
        }
        puVar25 = (undefined4 *)((int)puVar21 + 1);
        uVar17 = (uint)*(byte *)puVar21;
        if ((int)pbVar22 - (int)puVar25 < (int)uVar17) {
          iVar16 = 0x4e4;
          local_40[0] = puVar25;
          goto LAB_0004471c;
        }
        if (uVar17 == 0) {
LAB_00044840:
          local_40[0] = (undefined4 *)((int)puVar25 + uVar17);
          local_34 = 0x32;
          ERR_put_error(0x14,0x8a,0xbb,"s3_srvr.c",0x4f1);
        }
        else {
          if (*(byte *)((int)puVar21 + 1) != 0) {
            puVar14 = puVar25;
            do {
              if (puVar14 == (undefined4 *)((int)puVar21 + uVar17)) goto LAB_00044840;
              puVar14 = (undefined4 *)((int)puVar14 + 1);
            } while (*(byte *)puVar14 != 0);
          }
          local_40[0] = (undefined4 *)((int)puVar25 + uVar17);
          if ((param_1->version < 0x300) ||
             (iVar16 = ssl_parse_clienthello_tlsext(param_1,local_40), iVar16 != 0)) {
            iVar16 = ssl_check_clienthello_tlsext_early(param_1);
            if (iVar16 < 1) {
              iVar16 = 0x4fe;
LAB_00044a2e:
              ERR_put_error(0x14,0x8a,0xe2,"s3_srvr.c",iVar16);
              goto LAB_000445bc;
            }
            iVar16 = ssl_fill_hello_random(param_1,1,param_1->s3->server_random,0x20);
            if (iVar16 < 1) {
LAB_00044a16:
              local_34 = 0x50;
            }
            else {
              p_Var26 = (_STACK *)param_1->hit;
              if (((p_Var26 != (_STACK *)0x0) || (param_1->version < 0x301)) ||
                 (pcVar29 = (code *)param_1->tls_session_ticket_ext_cb_arg, pcVar29 == (code *)0x0))
              {
LAB_00044944:
                pSVar9 = param_1->session;
                uVar27 = *(uint *)(pSVar9->krb5_client_princ + 0x20);
                (param_1->s3->tmp).new_compression = (SSL_COMP *)0x0;
                if (uVar27 != 0) {
                  pSVar19 = (SSL_COMP *)(param_1->references & 0x20000);
                  pSVar15 = pSVar19;
                  if (pSVar19 == (SSL_COMP *)0x0) {
                    do {
                      iVar16 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
                      if (iVar16 <= (int)pSVar19) {
                        psVar28 = param_1->s3;
                        goto LAB_0004499a;
                      }
                      pSVar15 = (SSL_COMP *)
                                sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),
                                         (int)pSVar19);
                      pSVar19 = (SSL_COMP *)((int)&pSVar19->id + 1);
                    } while (pSVar15->id != uVar27);
                    psVar28 = param_1->s3;
                    (psVar28->tmp).new_compression = pSVar15;
LAB_0004499a:
                    if ((psVar28->tmp).new_compression != (SSL_COMP *)0x0) {
                      if (*(byte *)((int)puVar21 + 1) != uVar27) {
                        do {
                          if (puVar25 == (undefined4 *)((int)puVar21 + uVar17)) {
                            local_34 = 0x2f;
                            ERR_put_error(0x14,0x8a,0x156,"s3_srvr.c",0x562);
                            goto LAB_000445b4;
                          }
                          puVar25 = (undefined4 *)((int)puVar25 + 1);
                        } while (*(byte *)puVar25 != uVar27);
                      }
                      goto LAB_00044aa2;
                    }
                    local_34 = 0x50;
                    ERR_put_error(0x14,0x8a,0x155,"s3_srvr.c",0x557);
                  }
                  else {
                    local_34 = 0x50;
                    ERR_put_error(0x14,0x8a,0x154,"s3_srvr.c",0x549);
                  }
                  goto LAB_000445b4;
                }
                if (param_1->hit == 0) {
                  uVar27 = param_1->references & 0x20000;
                  if ((uVar27 == 0) &&
                     (*(_STACK **)(param_1->psk_server_callback + 0x98) != (_STACK *)0x0)) {
                    iVar16 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
                    for (; (int)uVar27 < iVar16; uVar27 = uVar27 + 1) {
                      pSVar15 = (SSL_COMP *)
                                sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),uVar27);
                      bVar1 = *(byte *)((int)puVar21 + 1);
                      puVar14 = puVar25;
                      while( true ) {
                        if ((uint)bVar1 == pSVar15->id) {
                          (param_1->s3->tmp).new_compression = pSVar15;
                          goto LAB_00044aa2;
                        }
                        if (puVar14 == (undefined4 *)(uVar17 + (int)puVar21)) break;
                        puVar14 = (undefined4 *)((int)puVar14 + 1);
                        bVar1 = *(byte *)puVar14;
                      }
                    }
                    pSVar15 = (SSL_COMP *)0x0;
LAB_00044aa2:
                    if (param_1->hit != 0) {
                      pSVar9 = param_1->session;
                      goto LAB_00044b32;
                    }
                    pSVar9 = param_1->session;
                    if (pSVar15 != (SSL_COMP *)0x0) {
                      pSVar15 = (SSL_COMP *)pSVar15->id;
                    }
                  }
                  else {
                    pSVar15 = (SSL_COMP *)0x0;
                  }
                  *(SSL_COMP **)(pSVar9->krb5_client_princ + 0x20) = pSVar15;
                  if (*(_STACK **)(pSVar9->krb5_client_princ + 0x2c) != (_STACK *)0x0) {
                    sk_free(*(_STACK **)(pSVar9->krb5_client_princ + 0x2c));
                    pSVar9 = param_1->session;
                  }
                  p_Var26 = local_30;
                  *(_STACK **)(pSVar9->krb5_client_princ + 0x2c) = local_30;
                  if (local_30 == (_STACK *)0x0) {
                    local_34 = 0x50;
                    ERR_put_error(0x14,0x8a,0x44,"s3_srvr.c",0x598);
                    goto LAB_000445b4;
                  }
                  local_30 = (_STACK *)0x0;
                  psVar10 = SSL_get_ciphers(param_1);
                  pSVar11 = (SSL_CIPHER *)ssl3_choose_cipher(param_1,p_Var26,psVar10);
                  if (pSVar11 == (SSL_CIPHER *)0x0) {
                    iVar16 = 0x5a0;
                    goto LAB_00044c1e;
                  }
                  (param_1->s3->tmp).new_cipher = pSVar11;
                }
                else {
LAB_00044b32:
                  if (param_1->references << 1 < 0) {
                    p_Var26 = *(_STACK **)(pSVar9->krb5_client_princ + 0x2c);
                    pSVar23 = (SSL_CIPHER *)0x0;
                    pSVar11 = (SSL_CIPHER *)0x0;
                    iVar16 = 0;
                    while( true ) {
                      iVar24 = sk_num(p_Var26);
                      iVar8 = iVar16 + 1;
                      if (iVar24 <= iVar16) break;
                      pSVar12 = (SSL_CIPHER *)sk_value(p_Var26,iVar16);
                      if ((pSVar12->algorithm_enc & 0x20) != 0) {
                        pSVar23 = pSVar12;
                      }
                      iVar16 = iVar8;
                      if ((pSVar12->algo_strength & 2) != 0) {
                        pSVar11 = pSVar12;
                      }
                    }
                    if (pSVar23 == (SSL_CIPHER *)0x0) {
                      if (pSVar11 == (SSL_CIPHER *)0x0) {
                        (param_1->s3->tmp).new_cipher =
                             *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24);
                      }
                      else {
                        (param_1->s3->tmp).new_cipher = pSVar11;
                      }
                    }
                    else {
                      (param_1->s3->tmp).new_cipher = pSVar23;
                    }
                  }
                  else {
                    (param_1->s3->tmp).new_cipher =
                         *(SSL_CIPHER **)(pSVar9->krb5_client_princ + 0x24);
                  }
                }
                iVar16 = param_1->version;
                if (((iVar16 >> 8 != 3) || (iVar16 < 0x303)) || (-1 < param_1->verify_mode << 0x1f))
                {
                  iVar16 = ssl3_digest_cached_records(param_1);
                  if (iVar16 == 0) goto LAB_00044a16;
                  iVar16 = param_1->version;
                }
                if ((iVar16 < 0x300) ||
                   (iVar16 = ssl_check_clienthello_tlsext_late(param_1), 0 < iVar16)) {
                  if (uVar6 == 0) {
                    lVar3 = 1;
                  }
                  else {
                    lVar3 = 2;
                  }
                  goto LAB_000445c4;
                }
                iVar16 = 0x5d6;
                goto LAB_00044a2e;
              }
              pSVar9 = param_1->session;
              pSVar9->master_key_length = 0x30;
              local_2c[0] = p_Var26;
              iVar16 = (*pcVar29)(param_1,pSVar9->master_key,&pSVar9->master_key_length,local_30,
                                  local_2c,param_1->tls_session_secret_cb);
              p_Var2 = local_30;
              if (iVar16 == 0) goto LAB_00044944;
              pSVar9 = param_1->session;
              param_1->hit = 1;
              *(undefined4 *)(pSVar9->krb5_client_princ + 0x10) = 0;
              *(_STACK **)(pSVar9->krb5_client_princ + 0x2c) = local_30;
              local_30 = p_Var26;
              if (local_2c[0] != (_STACK *)0x0) {
LAB_00044914:
                p_Var26 = (_STACK *)param_1->cipher_list;
                *(_STACK **)(pSVar9->krb5_client_princ + 0x24) = local_2c[0];
                if (p_Var26 != (_STACK *)0x0) {
                  sk_free(p_Var26);
                }
                if ((_STACK *)param_1->cipher_list_by_id != (_STACK *)0x0) {
                  sk_free((_STACK *)param_1->cipher_list_by_id);
                }
                p_Var26 = sk_dup(*(_STACK **)(param_1->session->krb5_client_princ + 0x2c));
                param_1->cipher_list = (stack_st_SSL_CIPHER *)p_Var26;
                p_Var26 = sk_dup(*(_STACK **)(param_1->session->krb5_client_princ + 0x2c));
                param_1->cipher_list_by_id = (stack_st_SSL_CIPHER *)p_Var26;
                goto LAB_00044944;
              }
              psVar10 = SSL_get_ciphers(param_1);
              local_2c[0] = (_STACK *)ssl3_choose_cipher(param_1,p_Var2,psVar10);
              if (local_2c[0] != (_STACK *)0x0) {
                pSVar9 = param_1->session;
                goto LAB_00044914;
              }
              iVar16 = 0x528;
LAB_00044c1e:
              local_34 = 0x28;
              ERR_put_error(0x14,0x8a,0xc1,"s3_srvr.c",iVar16);
            }
          }
          else {
            ERR_put_error(0x14,0x8a,0xe3,"s3_srvr.c",0x4f9);
          }
        }
      }
LAB_000445b4:
      ssl3_send_alert(param_1,2,local_34);
    }
  }
LAB_000445bc:
  lVar3 = -1;
  param_1->state = 5;
LAB_000445c4:
  if (local_30 != (_STACK *)0x0) {
    sk_free(local_30);
    return lVar3;
  }
  return lVar3;
}

