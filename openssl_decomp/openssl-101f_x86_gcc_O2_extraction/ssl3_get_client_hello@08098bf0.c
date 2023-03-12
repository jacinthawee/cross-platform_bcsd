
long ssl3_get_client_hello(SSL *param_1)

{
  byte bVar1;
  ushort *puVar2;
  code *pcVar3;
  ushort uVar4;
  long lVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  void *pvVar9;
  int iVar10;
  uint uVar11;
  _STACK *p_Var12;
  stack_st_SSL_CIPHER *psVar13;
  SSL_CIPHER *pSVar14;
  SSL_CIPHER *pSVar15;
  ssl3_state_st *psVar16;
  uint uVar17;
  SSL_SESSION *pSVar18;
  SSL_CIPHER *pSVar19;
  undefined4 *puVar20;
  long lVar21;
  dtls1_state_st *pdVar22;
  undefined4 *puVar23;
  int in_GS_OFFSET;
  byte bVar24;
  int iVar25;
  uint local_50;
  SSL_COMP *local_4c;
  int local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  _STACK *local_28;
  int local_24;
  int local_20;
  
  bVar24 = 0;
  local_28 = (_STACK *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1->state == 0x2110) {
    param_1->state = 0x2111;
  }
  param_1->max_cert_list = 1;
  lVar5 = (*param_1->method->ssl_get_message)(param_1,0x2111,0x2112,1,0x4000,&local_34);
  lVar21 = lVar5;
  if (local_34 == 0) goto LAB_08098d06;
  puVar2 = (ushort *)param_1->init_msg;
  param_1->max_cert_list = 0;
  local_2c = (undefined4 *)(puVar2 + 1);
  uVar4 = *puVar2 << 8 | *puVar2 >> 8;
  param_1->first_packet = (uint)uVar4;
  if (param_1->version == 0xfeff) {
    if (0xfeff < uVar4) goto LAB_08098c9a;
LAB_08098d32:
    uVar6 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if (((uVar6 & 0x2000) != 0) &&
       (lVar21 = 1, *(byte *)((int)local_2c + *(byte *)(local_2c + 8) + 0x21) == 0))
    goto LAB_08098d06;
    psVar16 = param_1->s3;
    *(undefined4 *)psVar16->client_random = *local_2c;
    *(undefined4 *)(psVar16->client_random + 4) = local_2c[1];
    *(undefined4 *)(psVar16->client_random + 8) = local_2c[2];
    *(undefined4 *)(psVar16->client_random + 0xc) = local_2c[3];
    *(undefined4 *)(psVar16->client_random + 0x10) = local_2c[4];
    *(undefined4 *)(psVar16->client_random + 0x14) = local_2c[5];
    *(undefined4 *)(psVar16->client_random + 0x18) = local_2c[6];
    *(undefined4 *)(psVar16->client_random + 0x1c) = local_2c[7];
    uVar6 = (uint)*(byte *)(local_2c + 8);
    local_2c = (undefined4 *)((int)local_2c + 0x21);
    param_1->hit = 0;
    if ((param_1->new_session == 0) || ((*(byte *)((int)&param_1->references + 2) & 1) == 0)) {
      iVar7 = ssl_get_prev_session(param_1,local_2c,uVar6,(int)puVar2 + lVar5);
      if (iVar7 == 1) {
        param_1->hit = 1;
        goto LAB_08098e12;
      }
      if (iVar7 != -1) goto LAB_08098e00;
    }
    else {
LAB_08098e00:
      iVar7 = ssl_get_new_session(param_1,1);
      if (iVar7 != 0) {
LAB_08098e12:
        puVar8 = (ushort *)(uVar6 + (int)local_2c);
        if ((param_1->version == 0x100) || (param_1->version == 0xfeff)) {
          local_2c = (undefined4 *)((int)puVar8 + 1);
          bVar1 = *(byte *)puVar8;
          uVar17 = (uint)bVar1;
          uVar11 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
          if (((uVar11 & 0x2000) != 0) && (uVar17 != 0)) {
            pdVar22 = param_1->d1;
            if (uVar17 < 4) {
              if (uVar17 != 0) {
                pdVar22->rcvd_cookie[0] = *(byte *)local_2c;
                if ((bVar1 & 2) == 0) goto LAB_08099417;
                *(undefined2 *)(pdVar22->rcvd_cookie + (uVar17 - 2)) =
                     *(undefined2 *)((int)local_2c + (uVar17 - 2));
                pdVar22 = param_1->d1;
              }
            }
            else {
              *(undefined4 *)pdVar22->rcvd_cookie = *local_2c;
              puVar23 = (undefined4 *)((uint)(pdVar22->rcvd_cookie + 4) & 0xfffffffc);
              *(undefined4 *)(pdVar22->rcvd_cookie + (uVar17 - 4)) =
                   *(undefined4 *)((int)local_2c + (uVar17 - 4));
              iVar7 = (int)pdVar22 + (0x104 - (int)puVar23);
              puVar20 = (undefined4 *)((int)local_2c - iVar7);
              for (uVar11 = iVar7 + uVar17 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
                *puVar23 = *puVar20;
                puVar20 = puVar20 + (uint)bVar24 * -2 + 1;
                puVar23 = puVar23 + (uint)bVar24 * -2 + 1;
              }
LAB_08099417:
              pdVar22 = param_1->d1;
            }
            if (*(code **)(param_1->psk_server_callback + 0x7c) == (code *)0x0) {
              iVar7 = memcmp(pdVar22->rcvd_cookie,pdVar22->cookie,pdVar22->cookie_len);
              if (iVar7 == 0) goto LAB_08099447;
              iVar7 = 0x42d;
            }
            else {
              iVar7 = (**(code **)(param_1->psk_server_callback + 0x7c))
                                (param_1,pdVar22->rcvd_cookie,uVar17);
              if (iVar7 != 0) {
LAB_08099447:
                lVar21 = 2;
                goto LAB_08099059;
              }
              iVar7 = 0x423;
            }
            local_30 = 0x28;
            lVar21 = -1;
            ERR_put_error(0x14,0x8a,0x134,"s3_srvr.c",iVar7);
            goto LAB_08098ce1;
          }
          lVar21 = -1;
LAB_08099059:
          puVar8 = (ushort *)(uVar17 + (int)local_2c);
        }
        else {
          lVar21 = -1;
        }
        local_2c = (undefined4 *)(puVar8 + 1);
        uVar4 = *puVar8 << 8 | *puVar8 >> 8;
        uVar17 = (uint)uVar4;
        if ((uVar17 == 0) && (uVar6 != 0)) {
          local_30 = 0x2f;
          iVar25 = 0x43c;
          iVar7 = 0xb7;
LAB_08098e79:
          ERR_put_error(0x14,0x8a,iVar7,"s3_srvr.c",iVar25);
          goto LAB_08098ce1;
        }
        if ((undefined4 *)(lVar5 + (int)puVar2) <= (undefined4 *)((int)local_2c + uVar17)) {
          local_30 = 0x32;
          iVar25 = 0x443;
          iVar7 = 0x9f;
          goto LAB_08098e79;
        }
        puVar20 = (undefined4 *)((int)local_2c + uVar17);
        if (uVar4 == 0) {
LAB_08098fc4:
          uVar6 = (uint)*(byte *)puVar20;
          local_2c = (undefined4 *)((int)(undefined4 *)((int)puVar20 + 1U) + uVar6);
          if ((undefined4 *)(lVar5 + (int)puVar2) < local_2c) {
            local_30 = 0x32;
            iVar25 = 0x486;
            iVar7 = 0x9f;
            local_2c = (undefined4 *)((int)puVar20 + 1U);
          }
          else if (uVar6 == 0) {
LAB_08098ffe:
            local_30 = 0x32;
            iVar25 = 0x494;
            iVar7 = 0xbb;
          }
          else {
            if (*(byte *)((int)puVar20 + 1) != 0) {
              uVar17 = 0;
              do {
                if (uVar6 == uVar17 + 1) goto LAB_08098ffe;
                iVar7 = uVar17 + 2;
                uVar17 = uVar17 + 1;
              } while (*(byte *)((int)puVar20 + iVar7) != 0);
            }
            if ((param_1->version < 0x300) ||
               (iVar7 = ssl_parse_clienthello_tlsext(param_1,&local_2c,puVar2,lVar5,&local_30),
               iVar7 != 0)) {
              iVar7 = ssl_check_clienthello_tlsext_early(param_1);
              if (0 < iVar7) {
                iVar7 = ssl_fill_hello_random(param_1,1,param_1->s3->server_random,0x20);
                if (0 < iVar7) {
                  if (((param_1->hit == 0) && (0x300 < param_1->version)) &&
                     (pcVar3 = (code *)param_1->tls_session_ticket_ext_cb_arg, pcVar3 != (code *)0x0
                     )) {
                    pSVar18 = param_1->session;
                    local_24 = 0;
                    pSVar18->master_key_length = 0x30;
                    iVar7 = (*pcVar3)(param_1,pSVar18->master_key,&pSVar18->master_key_length,
                                      local_28,&local_24,param_1->tls_session_secret_cb);
                    p_Var12 = local_28;
                    if (iVar7 == 0) goto LAB_080991fb;
                    pSVar18 = param_1->session;
                    param_1->hit = 1;
                    local_28 = (_STACK *)0x0;
                    *(_STACK **)(pSVar18->krb5_client_princ + 0x2c) = p_Var12;
                    *(undefined4 *)(pSVar18->krb5_client_princ + 0x10) = 0;
                    if (local_24 != 0) {
LAB_08099188:
                      *(int *)(pSVar18->krb5_client_princ + 0x24) = local_24;
                      if ((_STACK *)param_1->cipher_list != (_STACK *)0x0) {
                        sk_free((_STACK *)param_1->cipher_list);
                      }
                      if ((_STACK *)param_1->cipher_list_by_id != (_STACK *)0x0) {
                        sk_free((_STACK *)param_1->cipher_list_by_id);
                      }
                      p_Var12 = sk_dup(*(_STACK **)(param_1->session->krb5_client_princ + 0x2c));
                      param_1->cipher_list = (stack_st_SSL_CIPHER *)p_Var12;
                      p_Var12 = sk_dup(*(_STACK **)(param_1->session->krb5_client_princ + 0x2c));
                      param_1->cipher_list_by_id = (stack_st_SSL_CIPHER *)p_Var12;
                      goto LAB_080991fb;
                    }
                    psVar13 = SSL_get_ciphers(param_1);
                    local_24 = ssl3_choose_cipher(param_1,*(undefined4 *)
                                                           (param_1->session->krb5_client_princ +
                                                           0x2c),psVar13);
                    if (local_24 != 0) {
                      pSVar18 = param_1->session;
                      goto LAB_08099188;
                    }
                    iVar25 = 0x4c9;
LAB_08099781:
                    local_30 = 0x28;
                    iVar7 = 0xc1;
                    goto LAB_08098e79;
                  }
LAB_080991fb:
                  pSVar18 = param_1->session;
                  (param_1->s3->tmp).new_compression = (SSL_COMP *)0x0;
                  local_50 = *(uint *)(pSVar18->krb5_client_princ + 0x20);
                  if (local_50 != 0) {
                    if ((*(byte *)((int)&param_1->references + 2) & 2) == 0) {
                      local_4c = (SSL_COMP *)0x0;
                      for (iVar7 = 0;
                          iVar25 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98)),
                          iVar7 < iVar25; iVar7 = iVar7 + 1) {
                        local_4c = (SSL_COMP *)
                                   sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),iVar7)
                        ;
                        if (local_50 == local_4c->id) {
                          psVar16 = param_1->s3;
                          (psVar16->tmp).new_compression = local_4c;
                          goto LAB_0809929d;
                        }
                      }
                      psVar16 = param_1->s3;
LAB_0809929d:
                      uVar17 = 0;
                      if ((psVar16->tmp).new_compression == (SSL_COMP *)0x0) {
                        local_30 = 0x50;
                        iVar25 = 0x4f9;
                        iVar7 = 0x155;
                      }
                      else {
                        do {
                          if (local_50 == *(byte *)((int)puVar20 + uVar17 + 1)) {
                            if ((int)uVar17 < (int)uVar6) {
                              pSVar18 = param_1->session;
                              if (param_1->hit != 0) goto LAB_08099521;
                              if (local_4c == (SSL_COMP *)0x0) {
                                local_50 = 0;
                              }
                              else {
LAB_080992f1:
                                local_50 = local_4c->id;
                              }
                              goto LAB_080992fb;
                            }
                            break;
                          }
                          uVar17 = uVar17 + 1;
                        } while (uVar6 != uVar17);
                        local_30 = 0x2f;
                        iVar25 = 0x505;
                        iVar7 = 0x156;
                      }
                    }
                    else {
                      local_30 = 0x50;
                      iVar25 = 0x4e9;
                      iVar7 = 0x154;
                    }
                    goto LAB_08098e79;
                  }
                  if (param_1->hit == 0) {
                    if (((*(byte *)((int)&param_1->references + 2) & 2) == 0) &&
                       (*(_STACK **)(param_1->psk_server_callback + 0x98) != (_STACK *)0x0)) {
                      iVar7 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
                      if (0 < iVar7) {
                        iVar25 = 0;
                        do {
                          local_4c = (SSL_COMP *)
                                     sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),
                                              iVar25);
                          uVar17 = 0;
                          do {
                            if (local_4c->id == (uint)*(byte *)((int)puVar20 + uVar17 + 1)) {
                              iVar7 = param_1->hit;
                              (param_1->s3->tmp).new_compression = local_4c;
                              if (iVar7 != 0) goto LAB_0809951b;
                              pSVar18 = param_1->session;
                              goto LAB_080992f1;
                            }
                            uVar17 = uVar17 + 1;
                          } while (uVar6 != uVar17);
                          iVar25 = iVar25 + 1;
                        } while (iVar7 != iVar25);
                      }
                      if (param_1->hit != 0) {
LAB_0809951b:
                        pSVar18 = param_1->session;
                        goto LAB_08099521;
                      }
                      pSVar18 = param_1->session;
                    }
LAB_080992fb:
                    *(uint *)(pSVar18->krb5_client_princ + 0x20) = local_50;
                    if (*(_STACK **)(pSVar18->krb5_client_princ + 0x2c) != (_STACK *)0x0) {
                      sk_free(*(_STACK **)(pSVar18->krb5_client_princ + 0x2c));
                      pSVar18 = param_1->session;
                    }
                    *(_STACK **)(pSVar18->krb5_client_princ + 0x2c) = local_28;
                    if (local_28 == (_STACK *)0x0) {
                      local_30 = 0x2f;
                      iVar25 = 0x53f;
                      iVar7 = 0xb6;
                      goto LAB_08098e79;
                    }
                    local_28 = (_STACK *)0x0;
                    psVar13 = SSL_get_ciphers(param_1);
                    pSVar14 = (SSL_CIPHER *)
                              ssl3_choose_cipher(param_1,*(undefined4 *)
                                                          (param_1->session->krb5_client_princ +
                                                          0x2c),psVar13);
                    if (pSVar14 == (SSL_CIPHER *)0x0) {
                      iVar25 = 0x549;
                      goto LAB_08099781;
                    }
                    (param_1->s3->tmp).new_cipher = pSVar14;
                  }
                  else {
LAB_08099521:
                    if ((*(byte *)((int)&param_1->references + 3) & 0x40) == 0) {
                      psVar16 = param_1->s3;
                      pSVar14 = *(SSL_CIPHER **)(pSVar18->krb5_client_princ + 0x24);
LAB_080995ea:
                      (psVar16->tmp).new_cipher = pSVar14;
                    }
                    else {
                      p_Var12 = *(_STACK **)(pSVar18->krb5_client_princ + 0x2c);
                      pSVar19 = (SSL_CIPHER *)0x0;
                      pSVar14 = (SSL_CIPHER *)0x0;
                      for (iVar7 = 0; iVar25 = sk_num(p_Var12), iVar7 < iVar25; iVar7 = iVar7 + 1) {
                        pSVar15 = (SSL_CIPHER *)sk_value(p_Var12,iVar7);
                        if ((*(byte *)&pSVar15->algorithm_enc & 0x20) != 0) {
                          pSVar19 = pSVar15;
                        }
                        if ((*(byte *)&pSVar15->algo_strength & 2) != 0) {
                          pSVar14 = pSVar15;
                        }
                      }
                      if (pSVar19 == (SSL_CIPHER *)0x0) {
                        psVar16 = param_1->s3;
                        if (pSVar14 != (SSL_CIPHER *)0x0) goto LAB_080995ea;
                        (psVar16->tmp).new_cipher =
                             *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24);
                      }
                      else {
                        (param_1->s3->tmp).new_cipher = pSVar19;
                      }
                    }
                  }
                  if ((((param_1->version >> 8 == 3) && (0x302 < param_1->version)) &&
                      ((*(byte *)&param_1->verify_mode & 1) != 0)) ||
                     (iVar7 = ssl3_digest_cached_records(param_1), iVar7 != 0)) {
                    if ((param_1->version < 0x300) ||
                       (iVar7 = ssl_check_clienthello_tlsext_late(param_1), 0 < iVar7)) {
                      if (lVar21 == -1) {
                        lVar21 = 1;
                      }
                      goto LAB_08098cf0;
                    }
                    iVar7 = 0x586;
                    goto LAB_08099459;
                  }
                }
                local_30 = 0x50;
                goto LAB_08098ce1;
              }
              iVar7 = 0x4a4;
LAB_08099459:
              ERR_put_error(0x14,0x8a,0xe2,"s3_srvr.c",iVar7);
              goto LAB_08098cf0;
            }
            iVar25 = 0x49f;
            iVar7 = 0xe3;
          }
          goto LAB_08098e79;
        }
        iVar7 = ssl_bytes_to_cipher_list(param_1,local_2c,uVar17,&local_28);
        if (iVar7 != 0) {
          local_2c = (undefined4 *)(uVar17 + (int)local_2c);
          puVar20 = local_2c;
          if (param_1->hit != 0) {
            iVar7 = *(int *)(*(int *)(param_1->session->krb5_client_princ + 0x24) + 8);
            for (iVar25 = 0; iVar10 = sk_num(local_28), iVar25 < iVar10; iVar25 = iVar25 + 1) {
              pvVar9 = sk_value(local_28,iVar25);
              puVar20 = local_2c;
              if (iVar7 == *(int *)((int)pvVar9 + 8)) goto LAB_08098fc4;
            }
            local_30 = 0x2f;
            iVar25 = 0x47b;
            iVar7 = 0xd7;
            goto LAB_08098e79;
          }
          goto LAB_08098fc4;
        }
        goto LAB_08098cf0;
      }
    }
    lVar21 = -1;
  }
  else {
    if (param_1->version <= (int)(uint)uVar4) goto LAB_08098d32;
LAB_08098c9a:
    ERR_put_error(0x14,0x8a,0x10b,"s3_srvr.c",0x3c0);
    if (((param_1->first_packet >> 8 == 3) && (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0)) &&
       (param_1->write_hash == (EVP_MD_CTX *)0x0)) {
      param_1->version = param_1->first_packet;
    }
    local_30 = 0x46;
    lVar21 = -1;
LAB_08098ce1:
    ssl3_send_alert(param_1,2,local_30);
  }
LAB_08098cf0:
  if (local_28 != (_STACK *)0x0) {
    sk_free(local_28);
  }
LAB_08098d06:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar21;
}

