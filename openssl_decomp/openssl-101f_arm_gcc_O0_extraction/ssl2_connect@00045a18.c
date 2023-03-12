
int ssl2_connect(SSL *param_1)

{
  char cVar1;
  _STACK *p_Var2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  stack_st_SSL_CIPHER *psVar6;
  undefined4 uVar7;
  _STACK *st;
  _STACK *p_Var8;
  int iVar9;
  X509 *x;
  EVP_PKEY *pkey;
  void *pvVar10;
  undefined4 uVar11;
  int iVar12;
  char *__dest;
  uint uVar13;
  _func_3154 *p_Var14;
  size_t sVar15;
  ssl2_state_st *psVar16;
  undefined4 uVar17;
  BUF_MEM *str;
  char *pcVar18;
  SSL_SESSION *pSVar19;
  undefined4 *__dest_00;
  SSL_SESSION *pSVar20;
  undefined4 *puVar21;
  uint uVar22;
  _func_3152 *p_Var23;
  uchar *puVar24;
  int iVar25;
  undefined4 in_stack_ffffff78;
  undefined4 in_stack_ffffff7c;
  int local_58;
  time_t local_50;
  uchar *local_4c;
  uchar *local_48;
  X509 *local_44;
  EVP_MD_CTX local_40;
  
  local_50 = time((time_t *)0x0);
  RAND_add(&local_50,4,(double)CONCAT44(in_stack_ffffff7c,in_stack_ffffff78));
  ERR_clear_error();
  piVar3 = __errno_location();
  p_Var23 = param_1->info_callback;
  *piVar3 = 0;
  if (p_Var23 == (_func_3152 *)0x0) {
    p_Var23 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar4 = SSL_state(param_1);
  if (((uVar4 & 0x3000) == 0) || (iVar5 = SSL_state(param_1), iVar5 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  iVar5 = param_1->state;
  do {
    while (iVar25 = iVar5, 0x1041 < iVar25) {
      iVar5 = 0x1071;
      if (iVar25 < 0x1072) {
        if (0x106f < iVar25) {
          pcVar18 = param_1->init_buf->data;
          if (iVar25 == 0x1070) {
            iVar12 = ssl2_read(param_1,pcVar18 + param_1->init_num,1 - param_1->init_num);
            if (iVar12 < 1 - param_1->init_num) goto LAB_00046346;
            iVar9 = param_1->init_num + iVar12;
            param_1->init_num = iVar9;
            cVar1 = *pcVar18;
            if (cVar1 == '\a') {
              iVar5 = 0x1050;
            }
            if (cVar1 == '\a') {
              param_1->state = iVar5;
              goto LAB_00045bae;
            }
            if (cVar1 == '\x06') {
              param_1->state = iVar5;
              goto LAB_00045cbe;
            }
            if (cVar1 != '\0') {
              ssl2_return_error(param_1,0);
              ERR_put_error(0x14,0x6c,0xd4,"s2_clnt.c",0x3d0);
              goto LAB_00046288;
            }
            ERR_put_error(0x14,0x6c,200,"s2_clnt.c",0x3d4);
            uVar7 = ssl2_read(param_1,pcVar18 + param_1->init_num,3 - param_1->init_num);
            iVar5 = ssl2_part_read(param_1,0x6e,uVar7);
          }
          else {
            iVar9 = param_1->init_num;
LAB_00045cbe:
            iVar12 = ssl2_read(param_1,pcVar18 + iVar9,0x11 - iVar9);
            if (0x11 - iVar9 <= iVar12) {
              sVar15 = iVar12 + param_1->init_num;
              param_1->init_num = sVar15;
              if (param_1->msg_callback != (_func_3150 *)0x0) {
                (*param_1->msg_callback)
                          (0,param_1->version,0,pcVar18,sVar15,param_1,param_1->msg_callback_arg);
              }
              if (param_1->hit == 0) {
                pSVar19 = param_1->session;
                pSVar19->session_id_length = 0x10;
                uVar17 = *(undefined4 *)(pcVar18 + 5);
                uVar7 = *(undefined4 *)(pcVar18 + 9);
                uVar11 = *(undefined4 *)(pcVar18 + 0xd);
                *(undefined4 *)pSVar19->session_id = *(undefined4 *)(pcVar18 + 1);
                *(undefined4 *)(pSVar19->session_id + 4) = uVar17;
                *(undefined4 *)(pSVar19->session_id + 8) = uVar7;
                *(undefined4 *)(pSVar19->session_id + 0xc) = uVar11;
              }
              else if (-1 < param_1->references << 0x1f) {
                sVar15 = param_1->session->session_id_length;
                if ((0x20 < sVar15) ||
                   (iVar5 = memcmp(pcVar18 + 1,param_1->session->session_id,sVar15), iVar5 != 0)) {
                  ssl2_return_error(param_1,0);
                  ERR_put_error(0x14,0x6c,0xe7,"s2_clnt.c",0x3f9);
                  goto LAB_00046288;
                }
              }
              iVar5 = 3;
              param_1->state = 3;
              goto LAB_00045bae;
            }
LAB_00046346:
            iVar5 = ssl2_part_read(param_1,0x6c,iVar12);
          }
          if (0 < iVar5) {
            iVar5 = param_1->state;
            goto LAB_00045bae;
          }
          goto LAB_00045af6;
        }
        if (iVar25 < 0x1050) goto LAB_00045c46;
        if (iVar25 < 0x1054) goto LAB_00045c68;
        if (1 < iVar25 - 0x1060U) goto LAB_00045c46;
        iVar5 = param_1->init_num;
        pcVar18 = param_1->init_buf->data;
        if (iVar25 != 0x1060) {
LAB_00045b58:
          sVar15 = param_1->s2->challenge_length + 1;
          iVar12 = sVar15 - iVar5;
          iVar5 = ssl2_read(param_1,pcVar18 + iVar5,iVar12);
          if (iVar5 < iVar12) goto LAB_00045fd6;
          if (param_1->msg_callback != (_func_3150 *)0x0) {
            (*param_1->msg_callback)
                      (0,param_1->version,0,pcVar18,sVar15,param_1,param_1->msg_callback_arg);
          }
          iVar5 = CRYPTO_memcmp(pcVar18 + 1,param_1->s2->challenge,param_1->s2->challenge_length);
          if (iVar5 == 0) goto LAB_00045ba4;
          ssl2_return_error(param_1,0);
          ERR_put_error(0x14,0x6e,0x88,"s2_clnt.c",0x3b1);
          goto LAB_00046288;
        }
        iVar5 = ssl2_read(param_1,pcVar18 + iVar5,1 - iVar5);
        if (1 - param_1->init_num <= iVar5) {
          iVar5 = param_1->init_num + iVar5;
          param_1->state = 0x1061;
          param_1->init_num = iVar5;
          if (*pcVar18 == '\x05') {
            pcVar18 = param_1->init_buf->data;
            goto LAB_00045b58;
          }
          if (*pcVar18 != '\0') {
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x6e,0xd4,"s2_clnt.c",0x397);
            goto LAB_00046288;
          }
          ERR_put_error(0x14,0x6e,200,"s2_clnt.c",0x39b);
          iVar5 = ssl2_read(param_1,pcVar18 + param_1->init_num,3 - param_1->init_num);
        }
LAB_00045fd6:
        iVar5 = ssl2_part_read(param_1,0x6e,iVar5);
        goto LAB_00045ca8;
      }
      if (iVar25 == 0x1090) {
LAB_00045c68:
        puVar24 = (uchar *)param_1->init_buf->data;
        if (iVar25 == 0x1050) {
          iVar5 = ssl2_read(param_1,puVar24 + param_1->init_num,0x22 - param_1->init_num);
          if (0x12 - param_1->init_num <= iVar5) {
            sVar15 = param_1->init_num + iVar5;
            param_1->init_num = sVar15;
            if (param_1->msg_callback != (_func_3150 *)0x0) {
              (*param_1->msg_callback)
                        (0,param_1->version,0,puVar24,sVar15,param_1,param_1->msg_callback_arg);
            }
            if (puVar24[1] == '\x01') {
              if ((((int **)param_1->cert == (int **)0x0) ||
                  (piVar3 = *(int **)param_1->cert, *piVar3 == 0)) || (piVar3[1] == 0)) {
                param_1->state = 0x1090;
                sVar15 = param_1->init_num - 2;
                goto LAB_0004630e;
              }
              param_1->state = 0x1052;
              sVar15 = param_1->init_num - 2;
              goto LAB_0004641a;
            }
            ssl2_return_error(param_1,6);
            ERR_put_error(0x14,100,0x66,"s2_clnt.c",0x309);
            goto LAB_00046288;
          }
          iVar5 = ssl2_part_read(param_1,100,iVar5);
        }
        else {
          sVar15 = param_1->init_num - 2;
          iVar5 = iVar25;
          if (iVar25 == 0x1090) {
LAB_0004630e:
            local_44 = (X509 *)0x0;
            local_40.digest = (EVP_MD *)0x0;
            if (*(code **)(param_1->psk_server_callback + 0x74) == (code *)0x0) {
              param_1->rwstate = 1;
              goto LAB_0004651c;
            }
            iVar5 = (**(code **)(param_1->psk_server_callback + 0x74))(param_1,&local_44,&local_40);
            if (iVar5 < 0) {
              param_1->rwstate = 4;
              goto LAB_00046288;
            }
            param_1->rwstate = 1;
            if (iVar5 == 1) {
              if (local_40.digest == (EVP_MD *)0x0) {
                if ((local_44 != (X509 *)0x0) &&
                   (X509_free(local_44), local_40.digest != (EVP_MD *)0x0)) goto LAB_00046500;
              }
              else {
                if (local_44 != (X509 *)0x0) {
                  param_1->state = 0x1052;
                  iVar5 = SSL_use_certificate(param_1,local_44);
                  if ((iVar5 != 0) &&
                     (iVar5 = SSL_use_PrivateKey(param_1,(EVP_PKEY *)local_40.digest), iVar5 != 0))
                  {
                    iVar5 = 1;
                  }
                  X509_free(local_44);
                  EVP_PKEY_free((EVP_PKEY *)local_40.digest);
                  goto LAB_0004633a;
                }
LAB_00046500:
                EVP_PKEY_free((EVP_PKEY *)local_40.digest);
              }
              ERR_put_error(0x14,100,0x6a,"s2_clnt.c",0x341);
LAB_0004651c:
              param_1->state = 0x1051;
              *puVar24 = '\0';
              puVar24[1] = '\0';
              puVar24[2] = '\x02';
              param_1->init_off = 0;
              local_4c = puVar24 + 3;
              param_1->init_num = 3;
            }
            else {
LAB_0004633a:
              if (iVar5 == 0) goto LAB_0004651c;
            }
            iVar5 = param_1->state;
          }
          if ((iVar5 != 0x1051) && (iVar5 == 0x1052)) {
LAB_0004641a:
            local_4c = puVar24;
            EVP_MD_CTX_init(&local_40);
            EVP_DigestInit_ex(&local_40,*(EVP_MD **)(param_1->psk_server_callback + 0x88),
                              (ENGINE *)0x0);
            EVP_DigestUpdate(&local_40,param_1->s2->key_material,param_1->s2->key_material_length);
            EVP_DigestUpdate(&local_40,puVar24 + 2,sVar15);
            sVar15 = i2d_X509(**(X509 ***)(*(int *)(param_1->session->krb5_client_princ + 8) + 8),
                              &local_4c);
            if (0 < (int)sVar15) {
              EVP_DigestUpdate(&local_40,puVar24,sVar15);
            }
            local_48 = puVar24 + 6;
            *puVar24 = '\b';
            local_4c = puVar24 + 2;
            puVar24[1] = '\x01';
            local_44 = (X509 *)i2d_X509(**(X509 ***)param_1->cert,&local_48);
            *local_4c = (uchar)((uint)local_44 >> 8);
            local_4c[1] = (uchar)local_44;
            local_4c = local_4c + 2;
            EVP_SignFinal(&local_40,local_48,(uint *)&local_44,
                          *(EVP_PKEY **)(*(int *)param_1->cert + 4));
            EVP_MD_CTX_cleanup(&local_40);
            *local_4c = (uchar)((uint)local_44 >> 8);
            local_4c[1] = (uchar)local_44;
            local_48 = local_48 + (int)(local_44->sha1_hash + -0x58);
            param_1->state = 0x1053;
            local_4c = local_4c + 2;
            param_1->init_num = (int)local_48 - (int)puVar24;
            param_1->init_off = 0;
          }
          iVar5 = ssl2_do_write(param_1);
        }
LAB_00045ca8:
        if (0 < iVar5) {
LAB_00045ba4:
          iVar5 = 0x1070;
          param_1->state = 0x1070;
          param_1->init_num = 0;
          goto LAB_00045bae;
        }
        goto LAB_00045af6;
      }
      if (0x1090 < iVar25) {
        if ((iVar25 != 0x4000) && (iVar25 != 0x5000)) goto LAB_00045c46;
        goto LAB_00045d30;
      }
      if (iVar25 != 0x1080) {
LAB_00045c46:
        ERR_put_error(0x14,0x7b,0xff,"s2_clnt.c",0x136);
        return -1;
      }
      iVar5 = ssl2_enc_init(param_1,1);
      if (iVar5 == 0) goto LAB_00046288;
      iVar5 = 0x1040;
      param_1->s2->clear_text = 0;
      param_1->state = 0x1040;
      if (p_Var23 != (_func_3152 *)0x0) goto LAB_00045bb4;
      iVar5 = 0x1040;
    }
    if (iVar25 < 0x1040) {
      if (iVar25 < 0x1012) {
        if (iVar25 < 0x1010) {
          if ((iVar25 != 0x1000) && (iVar25 != 0x1003)) {
            if (iVar25 != 3) goto LAB_00045c46;
            if (param_1->init_buf != (BUF_MEM *)0x0) {
              BUF_MEM_free(param_1->init_buf);
              param_1->init_buf = (BUF_MEM *)0x0;
            }
            param_1->init_num = 0;
            ssl_update_cache(param_1,1);
            if (param_1->hit == 0) {
              p_Var14 = param_1->psk_server_callback;
            }
            else {
              p_Var14 = param_1->psk_server_callback;
              *(int *)(p_Var14 + 0x58) = *(int *)(p_Var14 + 0x58) + 1;
            }
            iVar5 = 1;
            *(int *)(p_Var14 + 0x3c) = *(int *)(p_Var14 + 0x3c) + 1;
            if (p_Var23 != (_func_3152 *)0x0) {
              iVar5 = 1;
              (*p_Var23)(param_1,0x20,1);
            }
            goto LAB_00045af6;
          }
LAB_00045d30:
          param_1->server = 0;
          if (p_Var23 != (_func_3152 *)0x0) {
            (*p_Var23)(param_1,0x10,1);
          }
          str = param_1->init_buf;
          param_1->version = 2;
          param_1->type = 0x1000;
          if ((str != (BUF_MEM *)0x0) || (str = BUF_MEM_new(), str != (BUF_MEM *)0x0)) {
            iVar5 = BUF_MEM_grow(str,0x3fff);
            if (iVar5 != 0) {
              iVar5 = 0x1010;
              param_1->init_buf = str;
              param_1->state = 0x1010;
              iVar12 = *(int *)(param_1->psk_server_callback + 0x34);
              param_1->init_num = 0;
              *(int *)(param_1->psk_server_callback + 0x34) = iVar12 + 1;
              param_1->handshake_func = ssl2_connect;
              goto LAB_00045bae;
            }
            if (str != param_1->init_buf) {
              iVar5 = -1;
              param_1->in_handshake = param_1->in_handshake + -1;
              BUF_MEM_free(str);
              goto LAB_00045afc;
            }
          }
          goto LAB_00046288;
        }
        param_1->shutdown = 0;
        pcVar18 = param_1->init_buf->data;
        if (iVar25 == 0x1010) {
          if (((param_1->session == (SSL_SESSION *)0x0) ||
              (param_1->session->ssl_version != param_1->version)) &&
             (iVar5 = ssl_get_new_session(param_1,0), iVar5 == 0)) {
LAB_000465d2:
            ssl2_return_error(param_1,0);
            goto LAB_00046288;
          }
          *pcVar18 = '\x01';
          pcVar18[2] = '\x02';
          pcVar18[1] = '\0';
          psVar6 = SSL_get_ciphers(param_1);
          iVar5 = ssl_cipher_list_to_bytes(param_1,psVar6,pcVar18 + 9,0);
          __dest_00 = (undefined4 *)(pcVar18 + 9 + iVar5);
          if (iVar5 == 0) {
            ERR_put_error(0x14,0x65,0xb5,"s2_clnt.c",0x241);
            goto LAB_00046288;
          }
          pcVar18[4] = (char)iVar5;
          pcVar18[3] = (char)((uint)iVar5 >> 8);
          sVar15 = param_1->session->session_id_length;
          if (sVar15 - 1 < 0x20) {
            pcVar18[5] = '\0';
            pcVar18[6] = (char)sVar15;
            puVar21 = (undefined4 *)((int)__dest_00 + sVar15);
            memcpy(__dest_00,param_1->session->session_id,sVar15);
          }
          else {
            pcVar18[5] = '\0';
            pcVar18[6] = '\0';
            puVar21 = __dest_00;
          }
          param_1->s2->challenge_length = 0x10;
          pcVar18[8] = '\x10';
          pcVar18[7] = '\0';
          iVar5 = RAND_pseudo_bytes(param_1->s2->challenge,0x10);
          if (iVar5 < 1) goto LAB_00046288;
          psVar16 = param_1->s2;
          uVar7 = *(undefined4 *)(psVar16->challenge + 4);
          uVar11 = *(undefined4 *)(psVar16->challenge + 8);
          uVar17 = *(undefined4 *)(psVar16->challenge + 0xc);
          *puVar21 = *(undefined4 *)psVar16->challenge;
          puVar21[1] = uVar7;
          puVar21[2] = uVar11;
          puVar21[3] = uVar17;
          param_1->init_num = (int)((int)puVar21 + (0x10 - (int)pcVar18));
          param_1->init_off = 0;
          param_1->state = 0x1011;
        }
        iVar5 = ssl2_do_write(param_1);
        if (iVar5 < 1) goto LAB_00045af6;
        iVar5 = 0x1020;
        param_1->state = 0x1020;
        param_1->init_num = 0;
      }
      else {
        if (iVar25 < 0x1020) goto LAB_00045c46;
        if (0x1021 < iVar25) {
          if (1 < iVar25 - 0x1030U) goto LAB_00045c46;
          pcVar18 = param_1->init_buf->data;
          if (iVar25 != 0x1030) {
LAB_00045bf2:
            iVar5 = ssl2_do_write(param_1);
            if (0 < iVar5) {
              iVar5 = 0x1080;
              param_1->state = 0x1080;
              param_1->init_num = 0;
              goto LAB_00045bae;
            }
            goto LAB_00045af6;
          }
          iVar5 = ssl_cipher_get_evp(param_1->session,&local_44,&local_40,0,0,0);
          if (iVar5 == 0) {
            ssl2_return_error(param_1,1);
            ERR_put_error(0x14,0x66,0xce,"s2_clnt.c",0x275);
          }
          else {
            pSVar19 = param_1->session;
            puVar24 = (uchar *)(pcVar18 + 1);
            __dest = pcVar18 + 10;
            *pcVar18 = '\x02';
            iVar5 = (*param_1->method->put_cipher_by_char)
                              (*(SSL_CIPHER **)(pSVar19->krb5_client_princ + 0x24),puVar24);
            uVar4 = EVP_CIPHER_iv_length((EVP_CIPHER *)local_44);
            pSVar19->key_arg_length = uVar4;
            if ((int)uVar4 < 9) {
              if ((0 < (int)uVar4) &&
                 (iVar12 = RAND_pseudo_bytes(pSVar19->key_arg,uVar4), iVar12 < 1))
              goto LAB_00046288;
              iVar12 = EVP_CIPHER_key_length((EVP_CIPHER *)local_44);
              pSVar19->master_key_length = iVar12;
              if (0 < iVar12) {
                if (0x30 < iVar12) {
                  ssl2_return_error(param_1,0);
                  iVar5 = 0x295;
                  goto LAB_00046888;
                }
                iVar9 = RAND_bytes(pSVar19->master_key,iVar12);
                if (iVar9 < 1) goto LAB_000465d2;
              }
              if (*(int *)(*(int *)(pSVar19->krb5_client_princ + 0x24) + 0x24) << 0x1e < 0) {
                iVar9 = 8;
                local_58 = 8;
LAB_000461ea:
                if (iVar12 < iVar9) {
                  ssl2_return_error(param_1,0);
                  ERR_put_error(0x14,0x66,0x8b,"s2_clnt.c",0x2a9);
                  goto LAB_00046288;
                }
                uVar22 = iVar12 - iVar9;
                uVar13 = uVar22 * 0x10000 >> 0x18;
                uVar4 = uVar22 & 0xff;
              }
              else {
                uVar13 = *(uint *)(*(int *)(pSVar19->krb5_client_princ + 0x24) + 0x20) & 2;
                uVar4 = uVar13;
                uVar22 = uVar13;
                local_58 = iVar12;
                if (uVar13 != 0) {
                  iVar9 = 5;
                  local_58 = 5;
                  goto LAB_000461ea;
                }
              }
              puVar24[iVar5] = (uchar)uVar13;
              puVar24[iVar5 + 1] = (uchar)uVar4;
              memcpy(__dest,pSVar19->master_key,uVar22);
              if (param_1->s2->ssl2_rollback == 0) {
                iVar12 = 1;
              }
              else {
                iVar12 = 2;
              }
              if (((*(int *)(pSVar19->krb5_client_princ + 8) == 0) ||
                  (x = **(X509 ***)(*(int *)(pSVar19->krb5_client_princ + 8) + 8), x == (X509 *)0x0)
                  ) || (pkey = X509_get_pubkey(x), pkey == (EVP_PKEY *)0x0)) {
                ERR_put_error(0x14,0xbc,0xc0,"s2_clnt.c",0x450);
              }
              else {
                if (pkey->type == 6) {
                  iVar12 = RSA_public_encrypt(local_58,pSVar19->master_key + uVar22,
                                              (uchar *)(__dest + uVar22),(pkey->pkey).rsa,iVar12);
                  if (-1 < iVar12) {
                    EVP_PKEY_free(pkey);
                    if (iVar12 != 0) {
                      puVar24[iVar5 + 3] = (uchar)iVar12;
                      puVar24[iVar5 + 2] = (uchar)((uint)iVar12 >> 8);
                      sVar15 = pSVar19->key_arg_length;
                      puVar24[iVar5 + 5] = (uchar)sVar15;
                      puVar24[iVar5 + 4] = (uchar)(sVar15 >> 8);
                      if ((int)sVar15 < 9) {
                        pvVar10 = memcpy(__dest + uVar22 + iVar12,pSVar19->key_arg,sVar15);
                        param_1->state = 0x1031;
                        param_1->init_num = (int)pvVar10 + (sVar15 - (int)pcVar18);
                        param_1->init_off = 0;
                        goto LAB_00045bf2;
                      }
                      ssl2_return_error(param_1,0);
                      iVar5 = 0x2c6;
                      goto LAB_00046888;
                    }
                    goto LAB_00046268;
                  }
                  ERR_put_error(0x14,0xbc,4,"s2_clnt.c",0x45c);
                }
                else {
                  ERR_put_error(0x14,0xbc,0xd1,"s2_clnt.c",0x455);
                }
                EVP_PKEY_free(pkey);
              }
LAB_00046268:
              ssl2_return_error(param_1,0);
              ERR_put_error(0x14,0x66,0xd0,"s2_clnt.c",0x2b7);
            }
            else {
              ssl2_return_error(param_1,0);
              iVar5 = 0x286;
LAB_00046888:
              ERR_put_error(0x14,0x66,0x44,"s2_clnt.c",iVar5);
            }
          }
          goto LAB_00046288;
        }
        pcVar18 = param_1->init_buf->data;
        if (iVar25 != 0x1020) {
          psVar16 = param_1->s2;
LAB_00045e68:
          uVar4 = (psVar16->tmp).cert_length + (psVar16->tmp).csl + 0xb +
                  (psVar16->tmp).conn_id_length;
          if (0x3fff < uVar4) {
            ERR_put_error(0x14,0x6d,0x128,"s2_clnt.c",0x180);
            goto LAB_00046288;
          }
          iVar12 = uVar4 - param_1->init_num;
          iVar5 = ssl2_read(param_1,pcVar18 + param_1->init_num,iVar12);
          if (iVar12 != iVar5) goto LAB_00046126;
          if (param_1->msg_callback != (_func_3150 *)0x0) {
            (*param_1->msg_callback)
                      (0,param_1->version,0,pcVar18,uVar4,param_1,param_1->msg_callback_arg);
          }
          pcVar18 = pcVar18 + 0xb;
          if (param_1->hit == 0) {
            if ((param_1->session->session_id_length != 0) &&
               (iVar5 = ssl_get_new_session(param_1), iVar5 == 0)) goto LAB_000465d2;
            iVar5 = ssl2_set_certificate
                              (param_1,(param_1->s2->tmp).cert_type,(param_1->s2->tmp).cert_length,
                               pcVar18);
            if (iVar5 < 1) {
              ssl2_return_error(param_1,4);
              goto LAB_00046288;
            }
            uVar4 = (param_1->s2->tmp).csl;
            uVar22 = (param_1->s2->tmp).cert_length;
            if (uVar4 == 0) {
              ssl2_return_error(param_1,1);
              ERR_put_error(0x14,0x6d,0xb8,"s2_clnt.c",0x1c4);
              goto LAB_00046288;
            }
            st = (_STACK *)
                 ssl_bytes_to_cipher_list
                           (param_1,pcVar18 + uVar22,uVar4,
                            param_1->session->krb5_client_princ + 0x2c);
            pcVar18 = pcVar18 + uVar22 + (param_1->s2->tmp).csl;
            if (st == (_STACK *)0x0) {
              ssl2_return_error(param_1,0);
              ERR_put_error(0x14,0x6d,0x41,"s2_clnt.c",0x1d3);
              goto LAB_00046288;
            }
            iVar5 = 0;
            sk_set_cmp_func(st,ssl_cipher_ptr_id_cmp + 1);
            p_Var8 = (_STACK *)SSL_get_ciphers(param_1);
            sk_set_cmp_func(p_Var8,ssl_cipher_ptr_id_cmp + 1);
            p_Var2 = p_Var8;
            if (param_1->references << 9 < 0) {
              p_Var2 = st;
              st = p_Var8;
            }
            for (; iVar12 = sk_num(p_Var2), iVar5 < iVar12; iVar5 = iVar5 + 1) {
              pvVar10 = sk_value(p_Var2,iVar5);
              iVar12 = sk_find(st,pvVar10);
              if (-1 < iVar12) break;
            }
            iVar12 = sk_num(p_Var2);
            if (iVar12 <= iVar5) {
              ssl2_return_error(param_1,1);
              ERR_put_error(0x14,0x6d,0xb9,"s2_clnt.c",0x1fb);
              goto LAB_00046288;
            }
            pSVar20 = param_1->session;
            pvVar10 = sk_value(p_Var2,iVar5);
            pSVar19 = param_1->session;
            iVar5 = *(int *)(pSVar19->krb5_client_princ + 0xc);
            *(void **)(pSVar20->krb5_client_princ + 0x24) = pvVar10;
            if (iVar5 == 0) {
              iVar5 = **(int **)(*(int *)(pSVar19->krb5_client_princ + 8) + 8);
              *(int *)(pSVar19->krb5_client_princ + 0xc) = iVar5;
              CRYPTO_add_lock((int *)(iVar5 + 0x10),1,3,"s2_clnt.c",0x20a);
              goto LAB_00045ee6;
            }
            ssl2_return_error(param_1,0);
            iVar5 = 0x204;
          }
          else {
            psVar16 = param_1->s2;
            if ((psVar16->tmp).cert_length != 0) {
              ERR_put_error(0x14,0x6d,0xd8,"s2_clnt.c",400);
              goto LAB_00046288;
            }
            if (((psVar16->tmp).cert_type != 0) && (-1 < param_1->references << 0x1b)) {
              ERR_put_error(0x14,0x6d,0xd9,"s2_clnt.c",0x198);
              goto LAB_00046288;
            }
            if ((psVar16->tmp).csl != 0) {
              ERR_put_error(0x14,0x6d,0xda,"s2_clnt.c",0x19e);
              goto LAB_00046288;
            }
LAB_00045ee6:
            iVar5 = *(int *)(param_1->session->krb5_client_princ + 8);
            if ((iVar5 != 0) &&
               (*(int *)(param_1->session->krb5_client_princ + 0xc) == **(int **)(iVar5 + 8))) {
              psVar16 = param_1->s2;
              sVar15 = (psVar16->tmp).conn_id_length;
              psVar16->conn_id_length = sVar15;
              if (sVar15 < 0x11) {
                memcpy(psVar16->conn_id,pcVar18,sVar15);
                goto LAB_00045f1a;
              }
              ssl2_return_error(param_1,0);
              ERR_put_error(0x14,0x6d,299,"s2_clnt.c",0x21a);
              goto LAB_00046288;
            }
            ssl2_return_error(param_1,0);
            iVar5 = 0x212;
          }
          ERR_put_error(0x14,0x6d,0x44,"s2_clnt.c",iVar5);
          goto LAB_00046288;
        }
        iVar5 = ssl2_read(param_1,pcVar18 + param_1->init_num,0xb - param_1->init_num);
        if (0xb - param_1->init_num <= iVar5) {
          param_1->init_num = 0xb;
          if (*pcVar18 == '\x04') {
            uVar4 = (uint)(byte)pcVar18[1];
            psVar16 = param_1->s2;
            iVar5 = param_1->version;
            if (uVar4 != 0) {
              uVar4 = 1;
            }
            param_1->hit = uVar4;
            (psVar16->tmp).cert_type = (uint)(byte)pcVar18[2];
            if ((int)(uint)CONCAT11(pcVar18[3],pcVar18[4]) < iVar5) {
              param_1->version = (uint)CONCAT11(pcVar18[3],pcVar18[4]);
            }
            (psVar16->tmp).cert_length = (uint)CONCAT11(pcVar18[5],pcVar18[6]);
            (psVar16->tmp).csl = (uint)CONCAT11(pcVar18[7],pcVar18[8]);
            (psVar16->tmp).conn_id_length = (uint)CONCAT11(pcVar18[9],pcVar18[10]);
            param_1->state = 0x1021;
            goto LAB_00045e68;
          }
          if (*pcVar18 == '\0') {
            ERR_put_error(0x14,0x6d,200,"s2_clnt.c",0x167);
          }
          else {
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x6d,0xd4,"s2_clnt.c",0x163);
          }
LAB_00046288:
          iVar5 = -1;
LAB_00045af6:
          param_1->in_handshake = param_1->in_handshake + -1;
LAB_00045afc:
          if (p_Var23 != (_func_3152 *)0x0) {
            (*p_Var23)(param_1,0x1002,iVar5);
          }
          return iVar5;
        }
LAB_00046126:
        iVar5 = ssl2_part_read(param_1,0x6d,iVar5);
        if (iVar5 < 1) goto LAB_00045af6;
LAB_00045f1a:
        param_1->init_num = 0;
        if (param_1->hit == 0) {
          iVar5 = 0x1030;
          param_1->state = 0x1030;
        }
        else {
          iVar5 = 0x1080;
          param_1->state = 0x1080;
        }
      }
    }
    else {
      if (iVar25 == 0x1040) {
        pcVar18 = param_1->init_buf->data;
        *pcVar18 = '\x03';
        sVar15 = param_1->s2->conn_id_length;
        if (0x10 < sVar15) {
          iVar5 = -1;
          ERR_put_error(0x14,0xa7,0x44,"s2_clnt.c",0x2df);
          goto LAB_00045af6;
        }
        memcpy(pcVar18 + 1,param_1->s2->conn_id,sVar15);
        param_1->state = 0x1041;
        uVar4 = param_1->s2->conn_id_length;
        param_1->init_off = 0;
        param_1->init_num = uVar4 + 1;
      }
      iVar5 = ssl2_do_write(param_1);
      if (iVar5 < 1) goto LAB_00045af6;
      iVar5 = 0x1060;
      param_1->state = 0x1060;
      param_1->init_num = 0;
    }
LAB_00045bae:
    if ((p_Var23 != (_func_3152 *)0x0) && (iVar25 != iVar5)) {
LAB_00045bb4:
      param_1->state = iVar25;
      (*p_Var23)(param_1,0x1001,1);
      param_1->state = iVar5;
    }
  } while( true );
}

