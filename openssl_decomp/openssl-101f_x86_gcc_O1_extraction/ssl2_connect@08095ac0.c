
int ssl2_connect(SSL *param_1)

{
  char *__dest;
  char cVar1;
  _func_3154 *p_Var2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  X509 *x;
  SSL_SESSION *pSVar6;
  uchar uVar7;
  uchar uVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  stack_st_SSL_CIPHER *psVar13;
  ssl2_state_st *psVar14;
  _STACK *p_Var15;
  void *pvVar16;
  EVP_PKEY *pkey;
  undefined4 uVar17;
  BUF_MEM *str;
  uchar *to;
  int iVar18;
  char *pcVar19;
  undefined4 *__dest_00;
  size_t sVar20;
  _STACK *p_Var21;
  uchar *puVar22;
  int in_GS_OFFSET;
  _func_3152 *local_68;
  uchar *local_64;
  _STACK *local_60;
  int local_58;
  size_t local_50;
  time_t local_48;
  uchar *local_44;
  uchar *local_40;
  X509 *local_3c;
  EVP_MD_CTX local_38;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_48 = time((time_t *)0x0);
  RAND_add(&local_48,4,0.0);
  ERR_clear_error();
  piVar9 = __errno_location();
  *piVar9 = 0;
  local_68 = param_1->info_callback;
  if (local_68 == (_func_3152 *)0x0) {
    local_68 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar10 = SSL_state(param_1);
  if (((uVar10 & 0x3000) == 0) || (uVar10 = SSL_state(param_1), (uVar10 & 0x4000) != 0)) {
    SSL_clear(param_1);
  }
  iVar11 = param_1->state;
  do {
    while (iVar12 = iVar11, 0x1041 < iVar12) {
      if (0x1071 < iVar12) {
        if (iVar12 == 0x1090) {
LAB_080960a0:
          puVar22 = (uchar *)param_1->init_buf->data;
          if (iVar12 == 0x1050) {
            iVar11 = ssl2_read(param_1,puVar22 + param_1->init_num,0x22 - param_1->init_num);
            if (0x12 - param_1->init_num <= iVar11) {
              sVar20 = param_1->init_num + iVar11;
              param_1->init_num = sVar20;
              if (param_1->msg_callback != (_func_3150 *)0x0) {
                (*param_1->msg_callback)
                          (0,param_1->version,0,puVar22,sVar20,param_1,param_1->msg_callback_arg);
              }
              if (puVar22[1] == '\x01') {
                if ((((int **)param_1->cert == (int **)0x0) ||
                    (piVar9 = *(int **)param_1->cert, *piVar9 == 0)) || (piVar9[1] == 0)) {
                  param_1->state = 0x1090;
                  sVar20 = param_1->init_num - 2;
                  goto LAB_08096870;
                }
                param_1->state = 0x1052;
                sVar20 = param_1->init_num - 2;
                goto LAB_08096a0f;
              }
              ssl2_return_error(param_1,6);
              ERR_put_error(0x14,100,0x66,"s2_clnt.c",0x309);
              goto LAB_080964d0;
            }
            iVar11 = ssl2_part_read(param_1,100,iVar11);
          }
          else {
            sVar20 = param_1->init_num - 2;
            iVar11 = iVar12;
            if (iVar12 == 0x1090) {
LAB_08096870:
              local_3c = (X509 *)0x0;
              local_38.digest = (EVP_MD *)0x0;
              if (*(code **)(param_1->psk_server_callback + 0x74) == (code *)0x0) {
                param_1->rwstate = 1;
                goto LAB_08096ba1;
              }
              uVar10 = (**(code **)(param_1->psk_server_callback + 0x74))
                                 (param_1,&local_3c,&local_38);
              if ((int)uVar10 < 0) {
                param_1->rwstate = 4;
                goto LAB_080964d0;
              }
              param_1->rwstate = 1;
              if (uVar10 == 1) {
                if (local_38.digest == (EVP_MD *)0x0) {
                  if ((local_3c != (X509 *)0x0) &&
                     (X509_free(local_3c), local_38.digest != (EVP_MD *)0x0)) goto LAB_08096b7a;
                }
                else {
                  if (local_3c != (X509 *)0x0) {
                    param_1->state = 0x1052;
                    iVar11 = SSL_use_certificate(param_1,local_3c);
                    uVar10 = 0;
                    if (iVar11 != 0) {
                      iVar11 = SSL_use_PrivateKey(param_1,(EVP_PKEY *)local_38.digest);
                      uVar10 = (uint)(iVar11 != 0);
                    }
                    X509_free(local_3c);
                    EVP_PKEY_free((EVP_PKEY *)local_38.digest);
                    goto LAB_080968bc;
                  }
LAB_08096b7a:
                  EVP_PKEY_free((EVP_PKEY *)local_38.digest);
                }
                ERR_put_error(0x14,100,0x6a,"s2_clnt.c",0x341);
LAB_08096ba1:
                param_1->state = 0x1051;
                *puVar22 = '\0';
                puVar22[1] = '\0';
                puVar22[2] = '\x02';
                param_1->init_off = 0;
                local_44 = puVar22 + 3;
                param_1->init_num = 3;
              }
              else {
LAB_080968bc:
                if (uVar10 == 0) goto LAB_08096ba1;
              }
              iVar11 = param_1->state;
            }
            if ((iVar11 != 0x1051) && (iVar11 == 0x1052)) {
LAB_08096a0f:
              local_64 = puVar22 + 2;
              local_44 = puVar22;
              EVP_MD_CTX_init(&local_38);
              EVP_DigestInit_ex(&local_38,*(EVP_MD **)(param_1->psk_server_callback + 0x88),
                                (ENGINE *)0x0);
              EVP_DigestUpdate(&local_38,param_1->s2->key_material,param_1->s2->key_material_length)
              ;
              EVP_DigestUpdate(&local_38,local_64,sVar20);
              sVar20 = i2d_X509(**(X509 ***)(*(int *)(param_1->session->krb5_client_princ + 8) + 8),
                                &local_44);
              if (0 < (int)sVar20) {
                EVP_DigestUpdate(&local_38,puVar22,sVar20);
              }
              local_40 = puVar22 + 6;
              *puVar22 = '\b';
              local_44 = puVar22 + 2;
              puVar22[1] = '\x01';
              local_3c = (X509 *)i2d_X509(**(X509 ***)param_1->cert,&local_40);
              *local_44 = (uchar)((uint)local_3c >> 8);
              local_44[1] = (uchar)local_3c;
              local_44 = local_44 + 2;
              EVP_SignFinal(&local_38,local_40,(uint *)&local_3c,
                            *(EVP_PKEY **)(*(int *)param_1->cert + 4));
              EVP_MD_CTX_cleanup(&local_38);
              *local_44 = (uchar)((uint)local_3c >> 8);
              local_44[1] = (uchar)local_3c;
              local_40 = local_40 + (int)(local_3c->sha1_hash + -0x58);
              local_44 = local_44 + 2;
              param_1->state = 0x1053;
              param_1->init_off = 0;
              param_1->init_num = (int)local_40 - (int)puVar22;
            }
            iVar11 = ssl2_do_write(param_1);
          }
LAB_080960eb:
          if (0 < iVar11) {
LAB_08095d15:
            param_1->init_num = 0;
            param_1->state = 0x1070;
            iVar18 = 0x1070;
            goto LAB_08095d28;
          }
          goto LAB_08095c07;
        }
        if (iVar12 < 0x1091) {
          if (iVar12 == 0x1080) {
            iVar11 = ssl2_enc_init(param_1,1);
            if (iVar11 != 0) {
              iVar18 = 0x1040;
              param_1->s2->clear_text = 0;
              param_1->state = 0x1040;
              iVar12 = 0x1080;
              if (local_68 == (_func_3152 *)0x0) goto LAB_08095e27;
              goto LAB_08095db0;
            }
            goto LAB_080964d0;
          }
        }
        else if ((iVar12 == 0x4000) || (iVar12 == 0x5000)) goto LAB_08095ef0;
LAB_08095ec0:
        iVar11 = -1;
        ERR_put_error(0x14,0x7b,0xff,"s2_clnt.c",0x136);
        goto LAB_08095c24;
      }
      if (iVar12 < 0x1070) {
        if (iVar12 < 0x1050) goto LAB_08095ec0;
        if (iVar12 < 0x1054) goto LAB_080960a0;
        if (1 < iVar12 - 0x1060U) goto LAB_08095ec0;
        pcVar19 = param_1->init_buf->data;
        iVar11 = param_1->init_num;
        if (iVar12 != 0x1060) {
LAB_08095cac:
          sVar20 = param_1->s2->challenge_length + 1;
          iVar18 = sVar20 - iVar11;
          iVar11 = ssl2_read(param_1,pcVar19 + iVar11,iVar18);
          if (iVar11 < iVar18) goto LAB_0809655b;
          if (param_1->msg_callback != (_func_3150 *)0x0) {
            (*param_1->msg_callback)
                      (0,param_1->version,0,pcVar19,sVar20,param_1,param_1->msg_callback_arg);
          }
          iVar11 = CRYPTO_memcmp(pcVar19 + 1,param_1->s2->challenge,param_1->s2->challenge_length);
          if (iVar11 == 0) goto LAB_08095d15;
          ssl2_return_error(param_1,0);
          ERR_put_error(0x14,0x6e,0x88,"s2_clnt.c",0x3b1);
          goto LAB_080964d0;
        }
        iVar11 = ssl2_read(param_1,pcVar19 + iVar11,1 - iVar11);
        if (1 - param_1->init_num <= iVar11) {
          iVar11 = iVar11 + param_1->init_num;
          param_1->state = 0x1061;
          param_1->init_num = iVar11;
          if (*pcVar19 == '\x05') {
            pcVar19 = param_1->init_buf->data;
            goto LAB_08095cac;
          }
          if (*pcVar19 != '\0') {
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x6e,0xd4,"s2_clnt.c",0x397);
            goto LAB_080964d0;
          }
          ERR_put_error(0x14,0x6e,200,"s2_clnt.c",0x39b);
          iVar11 = ssl2_read(param_1,pcVar19 + param_1->init_num,3 - param_1->init_num);
        }
LAB_0809655b:
        iVar11 = ssl2_part_read(param_1,0x6e,iVar11);
        goto LAB_080960eb;
      }
      pcVar19 = param_1->init_buf->data;
      iVar11 = param_1->init_num;
      if (iVar12 == 0x1070) {
        iVar18 = ssl2_read(param_1,pcVar19 + iVar11,1 - iVar11);
        if (iVar18 < 1 - param_1->init_num) goto LAB_080968e0;
        iVar11 = iVar18 + param_1->init_num;
        param_1->init_num = iVar11;
        cVar1 = *pcVar19;
        if (cVar1 == '\a') {
          param_1->state = 0x1050;
          iVar18 = 0x1050;
          goto LAB_08095da4;
        }
        if (cVar1 == '\x06') {
          param_1->state = 0x1071;
          goto LAB_0809632f;
        }
        if (cVar1 != '\0') {
          ssl2_return_error(param_1,0);
          ERR_put_error(0x14,0x6c,0xd4,"s2_clnt.c",0x3d0);
          goto LAB_080964d0;
        }
        ERR_put_error(0x14,0x6c,200,"s2_clnt.c",0x3d4);
        uVar17 = ssl2_read(param_1,pcVar19 + param_1->init_num,3 - param_1->init_num);
        iVar11 = ssl2_part_read(param_1,0x6e,uVar17);
      }
      else {
LAB_0809632f:
        iVar18 = ssl2_read(param_1,pcVar19 + iVar11,0x11 - iVar11);
        if (0x11 - iVar11 <= iVar18) {
          sVar20 = iVar18 + param_1->init_num;
          param_1->init_num = sVar20;
          if (param_1->msg_callback != (_func_3150 *)0x0) {
            (*param_1->msg_callback)
                      (0,param_1->version,0,pcVar19,sVar20,param_1,param_1->msg_callback_arg);
          }
          if (param_1->hit == 0) {
            pSVar6 = param_1->session;
            pSVar6->session_id_length = 0x10;
            uVar17 = *(undefined4 *)(pcVar19 + 5);
            uVar3 = *(undefined4 *)(pcVar19 + 9);
            uVar4 = *(undefined4 *)(pcVar19 + 0xd);
            *(undefined4 *)pSVar6->session_id = *(undefined4 *)(pcVar19 + 1);
            *(undefined4 *)(pSVar6->session_id + 4) = uVar17;
            *(undefined4 *)(pSVar6->session_id + 8) = uVar3;
            *(undefined4 *)(pSVar6->session_id + 0xc) = uVar4;
          }
          else if ((*(byte *)&param_1->references & 1) == 0) {
            uVar10 = param_1->session->session_id_length;
            if ((0x20 < uVar10) ||
               (iVar11 = memcmp(pcVar19 + 1,param_1->session->session_id,uVar10), iVar11 != 0)) {
              ssl2_return_error(param_1,0);
              ERR_put_error(0x14,0x6c,0xe7,"s2_clnt.c",0x3f9);
              goto LAB_080964d0;
            }
          }
          param_1->state = 3;
          iVar18 = 3;
          goto LAB_08095da4;
        }
LAB_080968e0:
        iVar11 = ssl2_part_read(param_1,0x6c,iVar18);
      }
      if (iVar11 < 1) goto LAB_08095c07;
      iVar18 = param_1->state;
LAB_08095d28:
      iVar11 = iVar18;
      if ((local_68 != (_func_3152 *)0x0) && (iVar11 = iVar12, iVar12 != iVar18)) {
LAB_08095db0:
        param_1->state = iVar12;
        (*local_68)(param_1,0x1001,1);
        param_1->state = iVar18;
        iVar11 = iVar18;
      }
    }
    if (iVar12 < 0x1040) {
      if (iVar12 < 0x1012) {
        if (iVar12 < 0x1010) {
          if ((iVar12 != 0x1000) && (iVar12 != 0x1003)) {
            if (iVar12 != 3) goto LAB_08095ec0;
            if (param_1->init_buf != (BUF_MEM *)0x0) {
              BUF_MEM_free(param_1->init_buf);
              param_1->init_buf = (BUF_MEM *)0x0;
            }
            param_1->init_num = 0;
            ssl_update_cache(param_1,1);
            p_Var2 = param_1->psk_server_callback;
            if (param_1->hit != 0) {
              piVar9 = (int *)(p_Var2 + 0x58);
              *piVar9 = *piVar9 + 1;
            }
            piVar9 = (int *)(p_Var2 + 0x3c);
            *piVar9 = *piVar9 + 1;
            iVar11 = 1;
            if (local_68 != (_func_3152 *)0x0) {
              (*local_68)(param_1,0x20,1);
              iVar11 = 1;
            }
            goto LAB_08095c07;
          }
LAB_08095ef0:
          param_1->server = 0;
          if (local_68 != (_func_3152 *)0x0) {
            (*local_68)(param_1,0x10,1);
          }
          str = param_1->init_buf;
          param_1->version = 2;
          param_1->type = 0x1000;
          if ((str == (BUF_MEM *)0x0) && (str = BUF_MEM_new(), str == (BUF_MEM *)0x0))
          goto LAB_080964d0;
          iVar11 = BUF_MEM_grow(str,0x3fff);
          if (iVar11 != 0) {
            param_1->init_buf = str;
            iVar18 = 0x1010;
            param_1->init_num = 0;
            param_1->state = 0x1010;
            *(int *)(param_1->psk_server_callback + 0x34) =
                 *(int *)(param_1->psk_server_callback + 0x34) + 1;
            param_1->handshake_func = ssl2_connect;
            goto LAB_08095d28;
          }
          if (str == param_1->init_buf) {
LAB_080964d0:
            iVar11 = -1;
LAB_08095c07:
            param_1->in_handshake = param_1->in_handshake + -1;
          }
          else {
            param_1->in_handshake = param_1->in_handshake + -1;
            BUF_MEM_free(str);
            iVar11 = -1;
          }
          if (local_68 != (_func_3152 *)0x0) {
            (*local_68)(param_1,0x1002,iVar11);
          }
LAB_08095c24:
          if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail();
          }
          return iVar11;
        }
        param_1->shutdown = 0;
        if (iVar12 == 0x1010) {
          pcVar19 = param_1->init_buf->data;
          if (((param_1->session == (SSL_SESSION *)0x0) ||
              (param_1->session->ssl_version != param_1->version)) &&
             (iVar11 = ssl_get_new_session(param_1,0), iVar11 == 0)) {
LAB_08096c5f:
            ssl2_return_error(param_1,0);
            goto LAB_080964d0;
          }
          *pcVar19 = '\x01';
          pcVar19[1] = '\0';
          pcVar19[2] = '\x02';
          psVar13 = SSL_get_ciphers(param_1);
          iVar11 = ssl_cipher_list_to_bytes(param_1,psVar13,pcVar19 + 9,0);
          __dest_00 = (undefined4 *)(pcVar19 + 9 + iVar11);
          if (iVar11 == 0) {
            ERR_put_error(0x14,0x65,0xb5,"s2_clnt.c",0x241);
            goto LAB_080964d0;
          }
          pcVar19[4] = (char)iVar11;
          pcVar19[3] = (char)((uint)iVar11 >> 8);
          sVar20 = param_1->session->session_id_length;
          pcVar19[5] = '\0';
          if (sVar20 - 1 < 0x20) {
            pcVar19[6] = (char)sVar20;
            memcpy(__dest_00,param_1->session->session_id,sVar20);
            __dest_00 = (undefined4 *)((int)__dest_00 + sVar20);
          }
          else {
            pcVar19[6] = '\0';
          }
          param_1->s2->challenge_length = 0x10;
          pcVar19[7] = '\0';
          pcVar19[8] = '\x10';
          iVar11 = RAND_pseudo_bytes(param_1->s2->challenge,0x10);
          if (iVar11 < 1) goto LAB_080964d0;
          psVar14 = param_1->s2;
          uVar17 = *(undefined4 *)(psVar14->challenge + 4);
          uVar3 = *(undefined4 *)(psVar14->challenge + 8);
          uVar4 = *(undefined4 *)(psVar14->challenge + 0xc);
          *__dest_00 = *(undefined4 *)psVar14->challenge;
          __dest_00[2] = uVar3;
          __dest_00[3] = uVar4;
          __dest_00[1] = uVar17;
          param_1->state = 0x1011;
          param_1->init_num = (int)((int)__dest_00 + (0x10 - (int)pcVar19));
          param_1->init_off = 0;
        }
        iVar11 = ssl2_do_write(param_1);
        if (iVar11 < 1) goto LAB_08095c07;
        param_1->init_num = 0;
        param_1->state = 0x1020;
        iVar18 = 0x1020;
      }
      else {
        if (iVar12 < 0x1020) goto LAB_08095ec0;
        if (iVar12 < 0x1022) {
          pcVar19 = param_1->init_buf->data;
          if (iVar12 != 0x1020) {
            psVar14 = param_1->s2;
LAB_08096115:
            uVar10 = (psVar14->tmp).csl + (psVar14->tmp).cert_length + 0xb +
                     (psVar14->tmp).conn_id_length;
            if (0x3fff < uVar10) {
              ERR_put_error(0x14,0x6d,0x128,"s2_clnt.c",0x180);
              goto LAB_080964d0;
            }
            iVar18 = uVar10 - param_1->init_num;
            iVar11 = ssl2_read(param_1,pcVar19 + param_1->init_num,iVar18);
            if (iVar18 != iVar11) goto LAB_08096688;
            if (param_1->msg_callback != (_func_3150 *)0x0) {
              (*param_1->msg_callback)
                        (0,param_1->version,0,pcVar19,uVar10,param_1,param_1->msg_callback_arg);
            }
            local_64 = (uchar *)(pcVar19 + 0xb);
            if (param_1->hit == 0) {
              if ((param_1->session->session_id_length != 0) &&
                 (iVar11 = ssl_get_new_session(param_1,0), iVar11 == 0)) goto LAB_08096c5f;
              iVar11 = ssl2_set_certificate
                                 (param_1,(param_1->s2->tmp).cert_type,
                                  (param_1->s2->tmp).cert_length,local_64);
              if (iVar11 < 1) {
                ssl2_return_error(param_1,4);
                goto LAB_080964d0;
              }
              uVar10 = (param_1->s2->tmp).csl;
              uVar5 = (param_1->s2->tmp).cert_length;
              if (uVar10 == 0) {
                ssl2_return_error(param_1,1);
                ERR_put_error(0x14,0x6d,0xb8,"s2_clnt.c",0x1c4);
                goto LAB_080964d0;
              }
              local_60 = (_STACK *)
                         ssl_bytes_to_cipher_list
                                   (param_1,(char *)local_64 + uVar5,uVar10,
                                    param_1->session->krb5_client_princ + 0x2c);
              local_64 = (uchar *)((char *)local_64 + uVar5 + (param_1->s2->tmp).csl);
              if (local_60 == (_STACK *)0x0) {
                ssl2_return_error(param_1,0);
                ERR_put_error(0x14,0x6d,0x41,"s2_clnt.c",0x1d3);
                goto LAB_080964d0;
              }
              sk_set_cmp_func(local_60,ssl_cipher_ptr_id_cmp);
              p_Var15 = (_STACK *)SSL_get_ciphers(param_1);
              sk_set_cmp_func(p_Var15,ssl_cipher_ptr_id_cmp);
              p_Var21 = p_Var15;
              if ((*(byte *)((int)&param_1->references + 2) & 0x40) != 0) {
                p_Var21 = local_60;
                local_60 = p_Var15;
              }
              for (iVar11 = 0; iVar18 = sk_num(p_Var21), iVar11 < iVar18; iVar11 = iVar11 + 1) {
                pvVar16 = sk_value(p_Var21,iVar11);
                iVar18 = sk_find(local_60,pvVar16);
                if (-1 < iVar18) break;
              }
              iVar18 = sk_num(p_Var21);
              if (iVar18 <= iVar11) {
                ssl2_return_error(param_1,1);
                ERR_put_error(0x14,0x6d,0xb9,"s2_clnt.c",0x1fb);
                goto LAB_080964d0;
              }
              pSVar6 = param_1->session;
              pvVar16 = sk_value(p_Var21,iVar11);
              *(void **)(pSVar6->krb5_client_princ + 0x24) = pvVar16;
              pSVar6 = param_1->session;
              if (*(int *)(pSVar6->krb5_client_princ + 0xc) == 0) {
                iVar11 = **(int **)(*(int *)(pSVar6->krb5_client_princ + 8) + 8);
                *(int *)(pSVar6->krb5_client_princ + 0xc) = iVar11;
                CRYPTO_add_lock((int *)(iVar11 + 0x10),1,3,"s2_clnt.c",0x20a);
                goto LAB_080965a6;
              }
              ssl2_return_error(param_1,0);
              iVar11 = 0x204;
            }
            else {
              psVar14 = param_1->s2;
              if ((psVar14->tmp).cert_length != 0) {
                ERR_put_error(0x14,0x6d,0xd8,"s2_clnt.c",400);
                goto LAB_080964d0;
              }
              if (((psVar14->tmp).cert_type != 0) && ((*(byte *)&param_1->references & 0x10) == 0))
              {
                ERR_put_error(0x14,0x6d,0xd9,"s2_clnt.c",0x198);
                goto LAB_080964d0;
              }
              if ((psVar14->tmp).csl != 0) {
                ERR_put_error(0x14,0x6d,0xda,"s2_clnt.c",0x19e);
                goto LAB_080964d0;
              }
LAB_080965a6:
              iVar11 = *(int *)(param_1->session->krb5_client_princ + 8);
              if ((iVar11 != 0) &&
                 (*(int *)(param_1->session->krb5_client_princ + 0xc) == **(int **)(iVar11 + 8))) {
                psVar14 = param_1->s2;
                uVar10 = (psVar14->tmp).conn_id_length;
                psVar14->conn_id_length = uVar10;
                if (uVar10 < 0x11) {
                  memcpy(psVar14->conn_id,local_64,uVar10);
                  goto LAB_080965f9;
                }
                ssl2_return_error(param_1,0);
                ERR_put_error(0x14,0x6d,299,"s2_clnt.c",0x21a);
                goto LAB_080964d0;
              }
              ssl2_return_error(param_1,0);
              iVar11 = 0x212;
            }
            ERR_put_error(0x14,0x6d,0x44,"s2_clnt.c",iVar11);
            goto LAB_080964d0;
          }
          iVar11 = ssl2_read(param_1,pcVar19 + param_1->init_num,0xb - param_1->init_num);
          if (0xb - param_1->init_num <= iVar11) {
            param_1->init_num = 0xb;
            if (*pcVar19 == '\x04') {
              param_1->hit = (uint)(pcVar19[1] != '\0');
              psVar14 = param_1->s2;
              (psVar14->tmp).cert_type = (uint)(byte)pcVar19[2];
              uVar10 = (uint)(ushort)(*(ushort *)(pcVar19 + 3) << 8 | *(ushort *)(pcVar19 + 3) >> 8)
              ;
              if ((int)uVar10 < param_1->version) {
                param_1->version = uVar10;
              }
              (psVar14->tmp).cert_length =
                   (uint)(ushort)(*(ushort *)(pcVar19 + 5) << 8 | *(ushort *)(pcVar19 + 5) >> 8);
              (psVar14->tmp).csl =
                   (uint)(ushort)(*(ushort *)(pcVar19 + 7) << 8 | *(ushort *)(pcVar19 + 7) >> 8);
              (psVar14->tmp).conn_id_length =
                   (uint)(ushort)(*(ushort *)(pcVar19 + 9) << 8 | *(ushort *)(pcVar19 + 9) >> 8);
              param_1->state = 0x1021;
              goto LAB_08096115;
            }
            if (*pcVar19 == '\0') {
              ERR_put_error(0x14,0x6d,200,"s2_clnt.c",0x167);
            }
            else {
              ssl2_return_error(param_1,0);
              ERR_put_error(0x14,0x6d,0xd4,"s2_clnt.c",0x163);
            }
            goto LAB_080964d0;
          }
LAB_08096688:
          iVar11 = ssl2_part_read(param_1,0x6d,iVar11);
          if (iVar11 < 1) goto LAB_08095c07;
LAB_080965f9:
          param_1->init_num = 0;
          if (param_1->hit == 0) {
            param_1->state = 0x1030;
            iVar18 = 0x1030;
            goto LAB_08095da4;
          }
        }
        else {
          if (1 < iVar12 - 0x1030U) goto LAB_08095ec0;
          if (iVar12 == 0x1030) {
            pcVar19 = param_1->init_buf->data;
            iVar11 = ssl_cipher_get_evp(param_1->session,&local_3c,&local_38,0,0,0);
            if (iVar11 == 0) {
              ssl2_return_error(param_1,1);
              ERR_put_error(0x14,0x66,0xce,"s2_clnt.c",0x275);
            }
            else {
              pSVar6 = param_1->session;
              __dest = pcVar19 + 10;
              *pcVar19 = '\x02';
              iVar11 = (*param_1->method->put_cipher_by_char)
                                 (*(SSL_CIPHER **)(pSVar6->krb5_client_princ + 0x24),
                                  (uchar *)(pcVar19 + 1));
              puVar22 = (uchar *)(pcVar19 + 1 + iVar11);
              uVar10 = EVP_CIPHER_iv_length((EVP_CIPHER *)local_3c);
              pSVar6->key_arg_length = uVar10;
              if ((int)uVar10 < 9) {
                if ((0 < (int)uVar10) &&
                   (iVar11 = RAND_pseudo_bytes(pSVar6->key_arg,uVar10), iVar11 < 1))
                goto LAB_080964d0;
                iVar11 = EVP_CIPHER_key_length((EVP_CIPHER *)local_3c);
                pSVar6->master_key_length = iVar11;
                if (0 < iVar11) {
                  if (0x30 < iVar11) {
                    ssl2_return_error(param_1,0);
                    iVar11 = 0x295;
                    goto LAB_0809703d;
                  }
                  iVar18 = RAND_bytes(pSVar6->master_key,iVar11);
                  if (iVar18 < 1) goto LAB_08096c5f;
                }
                if ((*(byte *)(*(int *)(pSVar6->krb5_client_princ + 0x24) + 0x24) & 2) == 0) {
                  if ((*(byte *)(*(int *)(pSVar6->krb5_client_princ + 0x24) + 0x20) & 2) != 0) {
                    local_58 = 5;
                    goto LAB_080963e8;
                  }
                  uVar8 = '\0';
                  uVar7 = '\0';
                  local_50 = 0;
                  local_58 = iVar11;
                }
                else {
                  local_58 = 8;
LAB_080963e8:
                  if (iVar11 < local_58) {
                    ssl2_return_error(param_1,0);
                    ERR_put_error(0x14,0x66,0x8b,"s2_clnt.c",0x2a9);
                    goto LAB_080964d0;
                  }
                  local_50 = iVar11 - local_58;
                  uVar7 = (uchar)(local_50 >> 8);
                  uVar8 = (uchar)local_50;
                }
                puVar22[1] = uVar8;
                *puVar22 = uVar7;
                memcpy(__dest,pSVar6->master_key,local_50);
                iVar11 = param_1->s2->ssl2_rollback;
                if (((*(int *)(pSVar6->krb5_client_princ + 8) == 0) ||
                    (x = **(X509 ***)(*(int *)(pSVar6->krb5_client_princ + 8) + 8), x == (X509 *)0x0
                    )) || (pkey = X509_get_pubkey(x), pkey == (EVP_PKEY *)0x0)) {
                  ERR_put_error(0x14,0xbc,0xc0,"s2_clnt.c",0x450);
                }
                else {
                  if (pkey->type == 6) {
                    to = (uchar *)(__dest + local_50);
                    iVar11 = RSA_public_encrypt(local_58,pSVar6->master_key + local_50,to,
                                                (pkey->pkey).rsa,2 - (uint)(iVar11 == 0));
                    if (-1 < iVar11) {
                      EVP_PKEY_free(pkey);
                      if (iVar11 != 0) {
                        puVar22[3] = (uchar)iVar11;
                        puVar22[2] = (uchar)((uint)iVar11 >> 8);
                        sVar20 = pSVar6->key_arg_length;
                        puVar22[5] = (uchar)sVar20;
                        puVar22[4] = (uchar)(sVar20 >> 8);
                        if ((int)sVar20 < 9) {
                          memcpy(to + iVar11,pSVar6->key_arg,sVar20);
                          param_1->state = 0x1031;
                          param_1->init_off = 0;
                          param_1->init_num = (int)(to + iVar11 + (sVar20 - (int)pcVar19));
                          goto LAB_08095d7b;
                        }
                        ssl2_return_error(param_1,0);
                        iVar11 = 0x2c6;
                        goto LAB_0809703d;
                      }
                      goto LAB_080964a2;
                    }
                    ERR_put_error(0x14,0xbc,4,"s2_clnt.c",0x45c);
                  }
                  else {
                    ERR_put_error(0x14,0xbc,0xd1,"s2_clnt.c",0x455);
                  }
                  EVP_PKEY_free(pkey);
                }
LAB_080964a2:
                ssl2_return_error(param_1,0);
                ERR_put_error(0x14,0x66,0xd0,"s2_clnt.c",0x2b7);
              }
              else {
                ssl2_return_error(param_1,0);
                iVar11 = 0x286;
LAB_0809703d:
                ERR_put_error(0x14,0x66,0x44,"s2_clnt.c",iVar11);
              }
            }
            goto LAB_080964d0;
          }
LAB_08095d7b:
          iVar11 = ssl2_do_write(param_1);
          if (iVar11 < 1) goto LAB_08095c07;
          param_1->init_num = 0;
        }
        param_1->state = 0x1080;
        iVar18 = 0x1080;
      }
    }
    else {
      iVar18 = iVar12;
      if (iVar12 == 0x1040) {
LAB_08095e27:
        pcVar19 = param_1->init_buf->data;
        *pcVar19 = '\x03';
        uVar10 = param_1->s2->conn_id_length;
        if (0x10 < uVar10) {
          ERR_put_error(0x14,0xa7,0x44,"s2_clnt.c",0x2df);
          iVar11 = -1;
          goto LAB_08095c07;
        }
        memcpy(pcVar19 + 1,param_1->s2->conn_id,uVar10);
        param_1->state = 0x1041;
        uVar10 = param_1->s2->conn_id_length;
        param_1->init_off = 0;
        param_1->init_num = uVar10 + 1;
        iVar12 = iVar18;
      }
      iVar11 = ssl2_do_write(param_1);
      if (iVar11 < 1) goto LAB_08095c07;
      param_1->init_num = 0;
      param_1->state = 0x1060;
      iVar18 = 0x1060;
    }
LAB_08095da4:
    iVar11 = iVar18;
    if (local_68 != (_func_3152 *)0x0) goto LAB_08095db0;
  } while( true );
}

