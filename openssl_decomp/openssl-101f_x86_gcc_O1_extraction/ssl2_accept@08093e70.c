
int ssl2_accept(SSL *param_1)

{
  undefined4 *buf;
  ulong uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ushort uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  BIO *pBVar9;
  undefined4 uVar10;
  BUF_MEM *pBVar11;
  _STACK *p_Var12;
  _STACK *st;
  void *data;
  int iVar13;
  _STACK *st_00;
  EVP_CIPHER *d;
  EVP_PKEY *pkey;
  SSL_SESSION *pSVar14;
  ssl2_state_st *psVar15;
  uint uVar16;
  X509 *x;
  int iVar17;
  char *pcVar18;
  size_t sVar19;
  uchar *puVar20;
  uint uVar21;
  int in_GS_OFFSET;
  int iVar22;
  _func_3152 *local_58;
  time_t local_44;
  uchar *local_40;
  EVP_CIPHER *local_3c;
  EVP_MD_CTX local_38;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_44 = time((time_t *)0x0);
  RAND_add(&local_44,4,0.0);
  ERR_clear_error();
  piVar5 = __errno_location();
  *piVar5 = 0;
  local_58 = param_1->info_callback;
  if (local_58 == (_func_3152 *)0x0) {
    local_58 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar6 = SSL_state(param_1);
  if (((uVar6 & 0x3000) == 0) || (uVar6 = SSL_state(param_1), (uVar6 & 0x4000) != 0)) {
    SSL_clear(param_1);
  }
  if (param_1->cert == (cert_st *)0x0) {
    ERR_put_error(0x14,0x7a,0xb3,"s2_srvr.c",0xa9);
    iVar7 = -1;
LAB_08093fd6:
    if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return iVar7;
  }
  *piVar5 = 0;
  iVar7 = param_1->state;
LAB_08093f10:
  iVar22 = iVar7;
  if (iVar22 < 0x2042) {
    if (0x203f < iVar22) {
      if (iVar22 == 0x2040) {
        pcVar18 = param_1->init_buf->data;
        *pcVar18 = '\x05';
        uVar6 = param_1->s2->challenge_length;
        if (0x20 < uVar6) {
          ERR_put_error(0x14,0xf0,0x44,"s2_srvr.c",0x370);
          iVar7 = -1;
          goto LAB_080944ab;
        }
        memcpy(pcVar18 + 1,param_1->s2->challenge,uVar6);
        param_1->state = 0x2041;
        uVar6 = param_1->s2->challenge_length;
        param_1->init_off = 0;
        param_1->init_num = uVar6 + 1;
      }
      iVar7 = ssl2_do_write(param_1);
      if (iVar7 < 1) goto LAB_080944ab;
      param_1->init_num = 0;
      if (param_1->hit == 0) {
        param_1->state = 0x2050;
        iVar17 = 0x2050;
      }
      else {
        param_1->state = 0x2042;
        iVar17 = 0x2042;
      }
joined_r0x0809445f:
      iVar7 = iVar17;
      if ((local_58 != (_func_3152 *)0x0) && (iVar7 = iVar22, iVar17 != iVar22)) goto LAB_080940f4;
      goto LAB_08093f10;
    }
    if (iVar22 < 0x2013) {
      if (0x200f < iVar22) {
        param_1->shutdown = 0;
        if (iVar22 == 0x2010) {
          param_1->max_cert_list = 1;
          param_1->state = 0x2011;
          pcVar18 = param_1->init_buf->data;
LAB_08094a47:
          iVar7 = ssl2_read(param_1,pcVar18 + param_1->init_num,9 - param_1->init_num);
          if (iVar7 < 9 - param_1->init_num) {
LAB_08094a70:
            iVar7 = ssl2_part_read(param_1,0x6a,iVar7);
            if (0 < iVar7) {
LAB_08094817:
              param_1->init_num = 0;
              param_1->state = 0x2020;
              iVar17 = 0x2020;
              goto joined_r0x0809445f;
            }
            goto LAB_080944ab;
          }
          param_1->init_num = 9;
          if (*pcVar18 == '\x01') {
            uVar6 = (uint)(ushort)(*(ushort *)(pcVar18 + 1) << 8 | *(ushort *)(pcVar18 + 1) >> 8);
            if ((int)uVar6 < param_1->version) {
              param_1->version = uVar6;
            }
            psVar15 = param_1->s2;
            (psVar15->tmp).cipher_spec_length =
                 (uint)(ushort)(*(ushort *)(pcVar18 + 3) << 8 | *(ushort *)(pcVar18 + 3) >> 8);
            (psVar15->tmp).session_id_length =
                 (uint)(ushort)(*(ushort *)(pcVar18 + 5) << 8 | *(ushort *)(pcVar18 + 5) >> 8);
            uVar6 = (uint)(ushort)(*(ushort *)(pcVar18 + 7) << 8 | *(ushort *)(pcVar18 + 7) >> 8);
            psVar15->challenge_length = uVar6;
            if (uVar6 - 0x10 < 0x11) {
              param_1->state = 0x2012;
              pcVar18 = param_1->init_buf->data;
              goto LAB_08094742;
            }
            ssl2_return_error(param_1,0,iVar22,iVar22);
            iVar22 = 0x237;
            iVar7 = 0x9e;
          }
          else if (*pcVar18 == '\0') {
            iVar22 = 0x22b;
            iVar7 = 200;
          }
          else {
            ssl2_return_error(param_1,0);
            iVar22 = 0x228;
            iVar7 = 0xd4;
          }
        }
        else {
          pcVar18 = param_1->init_buf->data;
          if (iVar22 == 0x2011) goto LAB_08094a47;
          psVar15 = param_1->s2;
LAB_08094742:
          uVar6 = psVar15->challenge_length + (psVar15->tmp).cipher_spec_length + 9 +
                  (psVar15->tmp).session_id_length;
          if (uVar6 < 0x4000) {
            iVar17 = uVar6 - param_1->init_num;
            iVar7 = ssl2_read(param_1,pcVar18 + param_1->init_num,iVar17);
            if (iVar17 != iVar7) goto LAB_08094a70;
            if (param_1->msg_callback != (_func_3150 *)0x0) {
              (*param_1->msg_callback)
                        (0,param_1->version,0,pcVar18,uVar6,param_1,param_1->msg_callback_arg);
            }
            pcVar18 = pcVar18 + 9;
            uVar6 = (param_1->s2->tmp).session_id_length;
            if ((uVar6 & 0xffffffef) == 0) {
              if (uVar6 == 0) {
LAB_080947c6:
                iVar7 = ssl_get_new_session(param_1,1);
                if (iVar7 == 0) {
LAB_080955a8:
                  ssl2_return_error(param_1,0);
                  iVar7 = -1;
                  goto LAB_080944ab;
                }
                if (param_1->hit == 0) {
                  p_Var12 = (_STACK *)
                            ssl_bytes_to_cipher_list
                                      (param_1,pcVar18,(param_1->s2->tmp).cipher_spec_length,
                                       param_1->session->krb5_client_princ + 0x2c);
                  if ((p_Var12 == (_STACK *)0x0) ||
                     ((st = (_STACK *)SSL_get_ciphers(param_1), st_00 = p_Var12,
                      (*(byte *)((int)&param_1->references + 2) & 0x40) != 0 &&
                      (st_00 = sk_dup(st), st = p_Var12, st_00 == (_STACK *)0x0)))) {
                    ERR_put_error(0x14,0x6a,0x41,"s2_srvr.c",0x2b5);
                    iVar7 = 0;
                    goto LAB_080944ab;
                  }
                  iVar7 = 0;
                  while (iVar17 = sk_num(st_00), iVar7 < iVar17) {
                    data = sk_value(st_00,iVar7);
                    iVar13 = sk_find(st,data);
                    iVar17 = iVar7;
                    if (iVar13 < 0) {
                      iVar17 = iVar7 + -1;
                      sk_delete(st_00,iVar7);
                    }
                    iVar7 = iVar17 + 1;
                  }
                  if ((*(byte *)((int)&param_1->references + 2) & 0x40) != 0) {
                    sk_free(*(_STACK **)(param_1->session->krb5_client_princ + 0x2c));
                    *(_STACK **)(param_1->session->krb5_client_princ + 0x2c) = st_00;
                  }
                }
              }
              else {
                iVar7 = ssl_get_prev_session
                                  (param_1,pcVar18 + (param_1->s2->tmp).cipher_spec_length,uVar6,0);
                if (iVar7 != 1) {
                  if (iVar7 != -1) {
                    if (param_1->cert == (cert_st *)0x0) {
                      ssl2_return_error(param_1,2);
                      iVar22 = 0x272;
                      iVar7 = 0xb3;
                      goto LAB_08094adb;
                    }
                    goto LAB_080947c6;
                  }
                  goto LAB_080955a8;
                }
                param_1->hit = 1;
              }
              psVar15 = param_1->s2;
              if (psVar15->challenge_length < 0x21) {
                memcpy(psVar15->challenge,
                       pcVar18 + (psVar15->tmp).cipher_spec_length +
                                 (psVar15->tmp).session_id_length,psVar15->challenge_length);
                goto LAB_08094817;
              }
              ssl2_return_error(param_1,0);
              iVar22 = 0x2af;
              iVar7 = 0x44;
            }
            else {
              ssl2_return_error(param_1,0);
              iVar22 = 0x254;
              iVar7 = 0x7d;
            }
          }
          else {
            ssl2_return_error(param_1,0);
            iVar22 = 0x243;
            iVar7 = 0x128;
          }
        }
LAB_08094adb:
        ERR_put_error(0x14,0x6a,iVar7,"s2_srvr.c",iVar22);
        iVar7 = -1;
        goto LAB_080944ab;
      }
      if ((iVar22 == 0x2000) || (iVar22 == 0x2003)) {
LAB_08094500:
        param_1->server = 1;
        if (local_58 != (_func_3152 *)0x0) {
          (*local_58)(param_1,0x10,1);
        }
        pBVar11 = param_1->init_buf;
        param_1->version = 2;
        param_1->type = 0x2000;
        if (((pBVar11 != (BUF_MEM *)0x0) || (pBVar11 = BUF_MEM_new(), pBVar11 != (BUF_MEM *)0x0)) &&
           (iVar7 = BUF_MEM_grow(pBVar11,0x3fff), iVar7 != 0)) {
          param_1->init_buf = pBVar11;
          iVar17 = 0x2010;
          param_1->init_num = 0;
          *(int *)(param_1->psk_server_callback + 0x40) =
               *(int *)(param_1->psk_server_callback + 0x40) + 1;
          param_1->handshake_func = ssl2_accept;
          param_1->state = 0x2010;
          goto joined_r0x0809445f;
        }
        goto LAB_08094a06;
      }
      if (iVar22 == 3) {
        BUF_MEM_free(param_1->init_buf);
        ssl_free_wbio_buffer(param_1);
        param_1->init_buf = (BUF_MEM *)0x0;
        param_1->init_num = 0;
        ssl_update_cache(param_1,2);
        *(int *)(param_1->psk_server_callback + 0x48) =
             *(int *)(param_1->psk_server_callback + 0x48) + 1;
        if (local_58 == (_func_3152 *)0x0) {
          param_1->in_handshake = param_1->in_handshake + -1;
          iVar7 = 1;
          goto LAB_08093fd6;
        }
        (*local_58)(param_1,0x20,1);
        param_1->in_handshake = param_1->in_handshake + -1;
        iVar7 = 1;
        goto LAB_08093fbb;
      }
    }
    else if (0x201f < iVar22) {
      if (iVar22 < 0x2022) {
        if (iVar22 == 0x2020) {
          pcVar18 = param_1->init_buf->data;
          local_38.digest = (EVP_MD *)(pcVar18 + 0xb);
          *pcVar18 = '\x04';
          iVar7 = param_1->hit;
          pcVar18[1] = (char)iVar7;
          if (iVar7 == 0) {
            pSVar14 = param_1->session;
            if (*(int *)(pSVar14->krb5_client_princ + 8) != 0) {
              ssl_sess_cert_free(*(int *)(pSVar14->krb5_client_princ + 8));
              pSVar14 = param_1->session;
            }
            uVar10 = ssl_sess_cert_new();
            *(undefined4 *)(pSVar14->krb5_client_princ + 8) = uVar10;
            if (*(int *)(param_1->session->krb5_client_princ + 8) == 0) {
              ERR_put_error(0x14,0x72,0x41,"s2_srvr.c",0x2d0);
              goto LAB_08094a06;
            }
            if (param_1->cert == (cert_st *)0x0) goto LAB_08094f6e;
            pcVar18[2] = '\x01';
            pcVar18[3] = (char)((uint)param_1->version >> 8);
            pcVar18[4] = (char)param_1->version;
            iVar7 = i2d_X509(*(X509 **)(param_1->cert + 0x30),(uchar **)0x0);
            pcVar18[6] = (char)iVar7;
            pcVar18[5] = (char)((uint)iVar7 >> 8);
            i2d_X509(*(X509 **)(param_1->cert + 0x30),(uchar **)&local_38);
            iVar7 = ssl_cipher_list_to_bytes
                              (param_1,*(undefined4 *)(param_1->session->krb5_client_princ + 0x2c),
                               local_38.digest,0);
            local_38.digest = (EVP_MD *)((int)(local_38.digest)->required_pkey_type + iVar7 + -0x2c)
            ;
            pcVar18[8] = (char)iVar7;
            pcVar18[7] = (char)((uint)iVar7 >> 8);
          }
          else {
            if (param_1->cert == (cert_st *)0x0) {
LAB_08094f6e:
              ssl2_return_error(param_1,2);
              ERR_put_error(0x14,0x72,0xb4,"s2_srvr.c",0x2f5);
              goto LAB_08094a06;
            }
            pcVar18[2] = '\0';
            pcVar18[3] = (char)((uint)param_1->version >> 8);
            iVar7 = param_1->version;
            pcVar18[5] = '\0';
            pcVar18[6] = '\0';
            pcVar18[7] = '\0';
            pcVar18[8] = '\0';
            pcVar18[4] = (char)iVar7;
          }
          pcVar18[9] = '\0';
          pcVar18[10] = '\x10';
          psVar15 = param_1->s2;
          psVar15->conn_id_length = 0x10;
          iVar7 = RAND_pseudo_bytes(psVar15->conn_id,0x10);
          if (iVar7 < 1) goto LAB_08094a06;
          psVar15 = param_1->s2;
          iVar7 = *(int *)(psVar15->conn_id + 4);
          iVar17 = *(int *)(psVar15->conn_id + 8);
          uVar1 = *(ulong *)(psVar15->conn_id + 0xc);
          (local_38.digest)->type = *(int *)psVar15->conn_id;
          (local_38.digest)->pkey_type = iVar7;
          (local_38.digest)->md_size = iVar17;
          (local_38.digest)->flags = uVar1;
          param_1->state = 0x2021;
          local_38.digest = (EVP_MD *)&(local_38.digest)->init;
          pcVar18 = param_1->init_buf->data;
          param_1->init_off = 0;
          param_1->init_num = (int)local_38.digest - (int)pcVar18;
        }
        if ((param_1->hit == 0) || (iVar7 = ssl_init_wbio_buffer(param_1,1), iVar7 != 0)) {
          iVar7 = ssl2_do_write(param_1);
          if (0 < iVar7) {
            param_1->init_num = 0;
            if (param_1->hit == 0) {
              param_1->state = 0x2030;
              iVar17 = 0x2030;
            }
            else {
LAB_0809470e:
              param_1->state = 0x2080;
              iVar17 = 0x2080;
            }
            goto joined_r0x0809445f;
          }
          goto LAB_080944ab;
        }
        goto LAB_08094a06;
      }
      if (iVar22 - 0x2030U < 2) {
        pBVar11 = param_1->init_buf;
        pcVar18 = pBVar11->data;
        if (iVar22 == 0x2030) {
          iVar7 = ssl2_read(param_1,pcVar18 + param_1->init_num,10 - param_1->init_num);
          if (iVar7 < 10 - param_1->init_num) {
LAB_080946f0:
            iVar7 = ssl2_part_read(param_1,0x6b,iVar7);
            if (0 < iVar7) {
LAB_08094707:
              param_1->init_num = 0;
              goto LAB_0809470e;
            }
            goto LAB_080944ab;
          }
          param_1->init_num = 10;
          if (*pcVar18 == '\x02') {
            iVar7 = ssl2_get_cipher_by_char(pcVar18 + 1);
            if (iVar7 == 0) {
              ssl2_return_error(param_1,1,0,0);
              iVar22 = 0x18e;
              iVar7 = 0xb9;
            }
            else {
              pSVar14 = param_1->session;
              psVar15 = param_1->s2;
              *(int *)(pSVar14->krb5_client_princ + 0x24) = iVar7;
              (psVar15->tmp).clear =
                   (uint)(ushort)(*(ushort *)(pcVar18 + 4) << 8 | *(ushort *)(pcVar18 + 4) >> 8);
              (psVar15->tmp).enc =
                   (uint)(ushort)(*(ushort *)(pcVar18 + 6) << 8 | *(ushort *)(pcVar18 + 6) >> 8);
              uVar4 = *(ushort *)(pcVar18 + 8) << 8 | *(ushort *)(pcVar18 + 8) >> 8;
              uVar6 = (uint)uVar4;
              if (uVar4 < 9) {
                pBVar11 = param_1->init_buf;
                pSVar14->key_arg_length = uVar6;
                param_1->state = 0x2031;
                pcVar18 = pBVar11->data;
                goto LAB_0809422b;
              }
              ssl2_return_error(param_1,0,uVar6,uVar6);
              iVar22 = 0x19a;
              iVar7 = 0x11c;
            }
          }
          else if (*pcVar18 == '\0') {
            iVar22 = 0x186;
            iVar7 = 200;
          }
          else {
            ssl2_return_error(param_1,0);
            iVar22 = 0x183;
            iVar7 = 0xd4;
          }
        }
        else {
LAB_0809422b:
          if (pBVar11->length < 0x3fff) {
            ssl2_return_error(param_1,0);
            iVar22 = 0x1a6;
LAB_080954e2:
            iVar7 = 0x44;
          }
          else {
            sVar19 = param_1->session->key_arg_length;
            uVar6 = sVar19 + (param_1->s2->tmp).clear + 10 + (param_1->s2->tmp).enc;
            if (uVar6 < 0x4000) {
              iVar17 = uVar6 - param_1->init_num;
              iVar7 = ssl2_read(param_1,pcVar18 + param_1->init_num,iVar17);
              if (iVar17 != iVar7) goto LAB_080946f0;
              if (param_1->msg_callback != (_func_3150 *)0x0) {
                (*param_1->msg_callback)
                          (0,param_1->version,0,pcVar18,uVar6,param_1,param_1->msg_callback_arg);
              }
              buf = (undefined4 *)(pcVar18 + 10);
              memcpy(param_1->session->key_arg,
                     (uchar *)((int)buf + (param_1->s2->tmp).clear + (param_1->s2->tmp).enc),sVar19)
              ;
              piVar5 = *(int **)(param_1->cert + 0x34);
              if (piVar5 != (int *)0x0) {
                psVar15 = param_1->s2;
                puVar20 = (uchar *)((psVar15->tmp).clear + (int)buf);
                if (*piVar5 == 6) {
                  uVar6 = RSA_private_decrypt((psVar15->tmp).enc,puVar20,puVar20,(RSA *)piVar5[5],
                                              2 - (uint)(psVar15->ssl2_rollback == 0));
                  if ((int)uVar6 < 0) {
                    ERR_put_error(0x14,0xbb,4,"s2_srvr.c",0x473);
                  }
                }
                else {
                  ERR_put_error(0x14,0xbb,0xd1,"s2_srvr.c",0x46b);
                  uVar6 = 0xffffffff;
                }
                uVar21 = *(uint *)(*(int *)(param_1->session->krb5_client_princ + 0x24) + 0x20);
                iVar7 = ssl_cipher_get_evp(param_1->session,&local_3c,&local_38,0,0,0);
                if (iVar7 != 0) {
                  if ((*(byte *)(*(int *)(param_1->session->krb5_client_princ + 0x24) + 0x24) & 2)
                      == 0) {
                    uVar21 = uVar21 & 2;
                    if ((int)uVar6 < 0) {
                      ERR_clear_error();
                      if (uVar21 == 0) {
LAB_080943ad:
                        uVar6 = EVP_CIPHER_key_length(local_3c);
                        iVar7 = RAND_pseudo_bytes((uchar *)buf,uVar6);
                        if (0 < iVar7) goto LAB_08094c27;
                      }
                      else {
                        iVar7 = RAND_pseudo_bytes((uchar *)buf,5);
                        if (0 < iVar7) {
                          iVar7 = 5;
                          goto LAB_08094c1c;
                        }
                      }
LAB_080943d7:
                      iVar7 = 0;
                      goto LAB_080944ab;
                    }
                    if (uVar21 != 0) {
                      iVar7 = 5;
                      uVar21 = 5;
                      goto LAB_08094bf2;
                    }
                    uVar21 = EVP_CIPHER_key_length(local_3c);
                    if (uVar21 != uVar6) {
                      ERR_clear_error();
                      goto LAB_080943ad;
                    }
                  }
                  else {
                    if ((int)uVar6 < 0) {
                      ERR_clear_error();
                      iVar7 = RAND_pseudo_bytes((uchar *)buf,8);
                      if (iVar7 < 1) goto LAB_080943d7;
                      iVar7 = 8;
                    }
                    else {
                      iVar7 = 8;
                      uVar21 = 8;
LAB_08094bf2:
                      if ((uVar6 != uVar21) ||
                         (uVar6 = (param_1->s2->tmp).clear, iVar17 = EVP_CIPHER_key_length(local_3c)
                         , iVar7 + uVar6 != iVar17)) {
                        ERR_clear_error();
                        iVar17 = RAND_pseudo_bytes((uchar *)buf,uVar21);
                        if (iVar17 < 1) goto LAB_080943d7;
                      }
                    }
LAB_08094c1c:
                    uVar6 = iVar7 + (param_1->s2->tmp).clear;
                  }
LAB_08094c27:
                  if ((int)uVar6 < 0x31) {
                    pSVar14 = param_1->session;
                    pSVar14->master_key_length = uVar6;
                    if (uVar6 < 4) {
                      if ((uVar6 != 0) && (pSVar14->master_key[0] = *(uchar *)buf, (uVar6 & 2) != 0)
                         ) {
                        *(undefined2 *)(pSVar14->master_key + (uVar6 - 2)) =
                             *(undefined2 *)(pcVar18 + uVar6 + 8);
                      }
                    }
                    else {
                      *(undefined4 *)pSVar14->master_key = *buf;
                      *(undefined4 *)(pSVar14->master_key + (uVar6 - 4)) =
                           *(undefined4 *)(pcVar18 + uVar6 + 6);
                      uVar21 = (uint)(pSVar14->master_key + 4) & 0xfffffffc;
                      iVar7 = (int)pSVar14 + (0x14 - uVar21);
                      uVar6 = iVar7 + uVar6 & 0xfffffffc;
                      if (3 < uVar6) {
                        uVar16 = 0;
                        do {
                          *(undefined4 *)(uVar21 + uVar16) =
                               *(undefined4 *)((int)buf + (uVar16 - iVar7));
                          uVar16 = uVar16 + 4;
                        } while (uVar16 < uVar6);
                      }
                    }
                    goto LAB_08094707;
                  }
                  ssl2_return_error(param_1,0);
                  iVar22 = 0x201;
                  goto LAB_080954e2;
                }
                ssl2_return_error(param_1,1);
                ERR_put_error(0x14,0x6b,0xce,"s2_srvr.c",0x1ca);
                iVar7 = 0;
                goto LAB_080944ab;
              }
              ssl2_return_error(param_1,0);
              iVar22 = 0x1be;
              iVar7 = 0xbd;
            }
            else {
              ssl2_return_error(param_1,0);
              iVar22 = 0x1ae;
              iVar7 = 0x128;
            }
          }
        }
        ERR_put_error(0x14,0x6b,iVar7,"s2_srvr.c",iVar22);
LAB_08094a06:
        iVar7 = -1;
LAB_080944ab:
        param_1->in_handshake = param_1->in_handshake + -1;
        if (local_58 != (_func_3152 *)0x0) {
LAB_08093fbb:
          (*local_58)(param_1,0x2002,iVar7);
        }
        goto LAB_08093fd6;
      }
    }
  }
  else {
    if (iVar22 < 0x2062) {
      if (0x205f < iVar22) {
        if (iVar22 == 0x2060) {
          pcVar18 = param_1->init_buf->data;
          *pcVar18 = '\x06';
          uVar6 = param_1->session->session_id_length;
          if (0x20 < uVar6) {
            ERR_put_error(0x14,0xef,0x44,"s2_srvr.c",0x388);
            iVar7 = -1;
            goto LAB_080944ab;
          }
          memcpy(pcVar18 + 1,param_1->session->session_id,uVar6);
          param_1->state = 0x2061;
          uVar6 = param_1->session->session_id_length;
          param_1->init_off = 0;
          param_1->init_num = uVar6 + 1;
        }
        iVar7 = ssl2_do_write(param_1);
        if (0 < iVar7) {
          param_1->init_num = 0;
          param_1->state = 3;
          iVar17 = 3;
          goto joined_r0x0809445f;
        }
        goto LAB_080944ab;
      }
      if (iVar22 == 0x2042) {
        lVar8 = BIO_ctrl(param_1->wbio,3,0,(void *)0x0);
        if (0 < lVar8) {
          param_1->rwstate = 2;
          lVar8 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
          if (lVar8 < 1) goto LAB_08094a06;
          param_1->rwstate = 1;
        }
        iVar17 = 0x2050;
        pBVar9 = BIO_pop(param_1->wbio);
        param_1->state = 0x2050;
        param_1->wbio = pBVar9;
        goto LAB_080944ec;
      }
      if (1 < iVar22 - 0x2050U) goto LAB_08094488;
      pcVar18 = param_1->init_buf->data;
      if (iVar22 == 0x2050) {
        iVar7 = ssl2_read(param_1,pcVar18 + param_1->init_num,1 - param_1->init_num);
        if (iVar7 < 1 - param_1->init_num) {
LAB_08094a10:
          iVar7 = ssl2_part_read(param_1,0x69,iVar7);
        }
        else {
          param_1->init_num = iVar7 + param_1->init_num;
          if (*pcVar18 == '\x03') {
            param_1->state = 0x2051;
            goto LAB_0809404d;
          }
          if (*pcVar18 != '\0') {
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x69,0xd4,"s2_srvr.c",0x33e);
            goto LAB_08094a06;
          }
          ERR_put_error(0x14,0x69,200,"s2_srvr.c",0x342);
          uVar10 = ssl2_read(param_1,pcVar18 + param_1->init_num,3 - param_1->init_num);
          iVar7 = ssl2_part_read(param_1,0x6e,uVar10);
        }
        if (iVar7 < 1) goto LAB_080944ab;
      }
      else {
LAB_0809404d:
        uVar6 = param_1->s2->conn_id_length;
        if (0x10 < uVar6) {
          ssl2_return_error(param_1,0);
          ERR_put_error(0x14,0x69,0x44,"s2_srvr.c",0x350);
          goto LAB_08094a06;
        }
        sVar19 = uVar6 + 1;
        iVar17 = sVar19 - param_1->init_num;
        iVar7 = ssl2_read(param_1,pcVar18 + param_1->init_num,iVar17);
        if (iVar7 < iVar17) goto LAB_08094a10;
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          (*param_1->msg_callback)
                    (0,param_1->version,0,pcVar18,sVar19,param_1,param_1->msg_callback_arg);
        }
        iVar7 = memcmp(pcVar18 + 1,param_1->s2->conn_id,param_1->s2->conn_id_length);
        if (iVar7 != 0) {
          ssl2_return_error(param_1,0);
          ERR_put_error(0x14,0x69,0x8f,"s2_srvr.c",0x360);
          goto LAB_08094a06;
        }
      }
      param_1->init_num = 0;
      param_1->state = 0x2070;
      iVar17 = 0x2070;
      goto joined_r0x0809445f;
    }
    if (iVar22 == 0x2080) {
      iVar7 = ssl2_enc_init(param_1,0);
      if (iVar7 == 0) goto LAB_08094a06;
      iVar17 = 0x2040;
      param_1->s2->clear_text = 0;
      param_1->state = 0x2040;
LAB_080944ec:
      iVar7 = iVar17;
      if (local_58 != (_func_3152 *)0x0) {
LAB_080940f4:
        param_1->state = iVar22;
        (*local_58)(param_1,0x2001,1);
        param_1->state = iVar17;
        iVar7 = iVar17;
      }
      goto LAB_08093f10;
    }
    if (0x2080 < iVar22) {
      if ((iVar22 == 0x4000) || (iVar22 == 0x6000)) goto LAB_08094500;
      goto LAB_08094488;
    }
    if (iVar22 - 0x2070U < 4) {
      if (((param_1->verify_mode & 1U) == 0) ||
         ((*(int *)(param_1->session->krb5_client_princ + 0xc) != 0 &&
          ((param_1->verify_mode & 4U) != 0)))) {
LAB_0809444d:
        param_1->state = 0x2060;
        iVar17 = 0x2060;
        goto joined_r0x0809445f;
      }
      psVar15 = param_1->s2;
      puVar20 = (psVar15->tmp).ccl;
      if (iVar22 == 0x2070) {
        pcVar18 = param_1->init_buf->data;
        *pcVar18 = '\a';
        pcVar18[1] = '\x01';
        iVar7 = RAND_pseudo_bytes(puVar20,0x10);
        if (iVar7 < 1) goto LAB_08094a06;
        uVar10 = *(undefined4 *)((psVar15->tmp).ccl + 4);
        uVar2 = *(undefined4 *)((psVar15->tmp).ccl + 8);
        uVar3 = *(undefined4 *)((psVar15->tmp).ccl + 0xc);
        *(undefined4 *)(pcVar18 + 2) = *(undefined4 *)(psVar15->tmp).ccl;
        *(undefined4 *)(pcVar18 + 10) = uVar2;
        *(undefined4 *)(pcVar18 + 0xe) = uVar3;
        *(undefined4 *)(pcVar18 + 6) = uVar10;
        param_1->state = 0x2071;
        param_1->init_num = 0x12;
        param_1->init_off = 0;
LAB_080951b4:
        iVar7 = ssl2_do_write(param_1);
        if (0 < iVar7) {
          param_1->init_num = 0;
          param_1->state = 0x2072;
          iVar7 = 0;
          iVar17 = 6;
LAB_080951dd:
          pcVar18 = param_1->init_buf->data;
          iVar7 = ssl2_read(param_1,pcVar18 + iVar7,iVar17);
          if (iVar7 < 3 - param_1->init_num) {
LAB_08094417:
            x = (X509 *)0x0;
            iVar7 = ssl2_part_read(param_1,0x71,iVar7);
            p_Var12 = (_STACK *)0x0;
LAB_08094426:
            sk_free(p_Var12);
            X509_free(x);
            if (iVar7 < 1) goto LAB_080944ab;
          }
          else {
            iVar7 = iVar7 + param_1->init_num;
            param_1->init_num = iVar7;
            if ((iVar7 < 3) || (*pcVar18 != '\0')) {
              if ((iVar7 < 6) || (*pcVar18 != '\b')) {
                ssl2_return_error(param_1,0);
                iVar22 = 0x3e6;
                iVar7 = 0xdb;
              }
              else if (iVar7 == 6) {
                if (pcVar18[1] == '\x01') {
                  psVar15 = param_1->s2;
                  (psVar15->tmp).clen =
                       (uint)(ushort)(*(ushort *)(pcVar18 + 2) << 8 | *(ushort *)(pcVar18 + 2) >> 8)
                  ;
                  (psVar15->tmp).rlen =
                       (uint)(ushort)(*(ushort *)(pcVar18 + 4) << 8 | *(ushort *)(pcVar18 + 4) >> 8)
                  ;
                  param_1->state = 0x2073;
                  goto LAB_0809418c;
                }
                ssl2_return_error(param_1,6);
                iVar22 = 0x3f5;
                iVar7 = 0x75;
              }
              else {
                iVar22 = 0x3eb;
                iVar7 = 0x44;
              }
LAB_080941b9:
              x = (X509 *)0x0;
              ERR_put_error(0x14,0x71,iVar7,"s2_srvr.c",iVar22);
              p_Var12 = (_STACK *)0x0;
              iVar7 = -1;
              goto LAB_080941ce;
            }
            if (pcVar18[1] != '\x02') {
              param_1->init_num = iVar7 + -3;
              iVar7 = 3;
              goto LAB_08094417;
            }
            if (param_1->msg_callback != (_func_3150 *)0x0) {
              (*param_1->msg_callback)
                        (0,param_1->version,0,pcVar18 + 2,3,param_1,param_1->msg_callback_arg);
            }
            if ((*(byte *)&param_1->verify_mode & 2) != 0) {
              ssl2_return_error(param_1,4);
              iVar22 = 0x3dd;
              iVar7 = 199;
              goto LAB_080941b9;
            }
            sk_free((_STACK *)0x0);
            X509_free((X509 *)0x0);
          }
          param_1->init_num = 0;
          goto LAB_0809444d;
        }
        p_Var12 = (_STACK *)0x0;
        x = (X509 *)0x0;
      }
      else {
        if (iVar22 == 0x2071) goto LAB_080951b4;
        if (iVar22 == 0x2072) {
          iVar7 = param_1->init_num;
          iVar17 = 6 - iVar7;
          goto LAB_080951dd;
        }
LAB_0809418c:
        uVar6 = (psVar15->tmp).rlen + (psVar15->tmp).clen + 6;
        if (0x3fff < uVar6) {
          iVar22 = 0x402;
          iVar7 = 0x128;
          goto LAB_080941b9;
        }
        pcVar18 = param_1->init_buf->data;
        iVar17 = uVar6 - param_1->init_num;
        iVar7 = ssl2_read(param_1,pcVar18 + param_1->init_num,iVar17);
        if (iVar7 < iVar17) goto LAB_08094417;
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          (*param_1->msg_callback)
                    (0,param_1->version,0,pcVar18,uVar6,param_1,param_1->msg_callback_arg);
        }
        local_40 = (uchar *)(pcVar18 + 6);
        x = d2i_X509((X509 **)0x0,&local_40,(param_1->s2->tmp).clen);
        if (x == (X509 *)0x0) {
          ERR_put_error(0x14,0x71,0xb,"s2_srvr.c",0x414);
          p_Var12 = (_STACK *)0x0;
        }
        else {
          p_Var12 = sk_new_null();
          if ((p_Var12 == (_STACK *)0x0) || (iVar7 = sk_push(p_Var12,x), iVar7 == 0)) {
            iVar22 = 0x41a;
            iVar7 = 0x41;
LAB_08094f2f:
            ERR_put_error(0x14,0x71,iVar7,"s2_srvr.c",iVar22);
          }
          else {
            iVar7 = ssl_verify_cert_chain(param_1,p_Var12);
            if (0 < iVar7) {
              EVP_MD_CTX_init(&local_38);
              iVar7 = EVP_DigestInit_ex(&local_38,*(EVP_MD **)(param_1->psk_server_callback + 0x88),
                                        (ENGINE *)0x0);
              if (((iVar7 != 0) &&
                  (iVar7 = EVP_DigestUpdate(&local_38,param_1->s2->key_material,
                                            param_1->s2->key_material_length), iVar7 != 0)) &&
                 (iVar7 = EVP_DigestUpdate(&local_38,puVar20,0x10), iVar7 != 0)) {
                iVar7 = i2d_X509(*(X509 **)(param_1->cert + 0x30),(uchar **)0x0);
                d = (EVP_CIPHER *)CRYPTO_malloc(iVar7,"s2_srvr.c",0x42e);
                if (d == (EVP_CIPHER *)0x0) {
                  iVar22 = 0x431;
                  iVar7 = 0x41;
                  goto LAB_08094f2f;
                }
                local_3c = d;
                sVar19 = i2d_X509(*(X509 **)(param_1->cert + 0x30),(uchar **)&local_3c);
                iVar7 = EVP_DigestUpdate(&local_38,d,sVar19);
                if (iVar7 == 0) {
                  CRYPTO_free(d);
                  goto LAB_08094f3f;
                }
                CRYPTO_free(d);
                pkey = X509_get_pubkey(x);
                if (pkey == (EVP_PKEY *)0x0) {
                  iVar7 = -1;
                }
                else {
                  iVar7 = EVP_VerifyFinal(&local_38,local_40,(param_1->s2->tmp).rlen,pkey);
                  EVP_PKEY_free(pkey);
                  EVP_MD_CTX_cleanup(&local_38);
                  if (iVar7 < 1) {
                    iVar22 = 0x44f;
                    iVar7 = 0x68;
                    goto LAB_08094f2f;
                  }
                  pSVar14 = param_1->session;
                  if (*(X509 **)(pSVar14->krb5_client_princ + 0xc) != (X509 *)0x0) {
                    X509_free(*(X509 **)(pSVar14->krb5_client_princ + 0xc));
                    pSVar14 = param_1->session;
                  }
                  *(X509 **)(pSVar14->krb5_client_princ + 0xc) = x;
                  CRYPTO_add_lock(&x->references,1,3,"s2_srvr.c",0x448);
                  *(int *)(param_1->session->krb5_client_princ + 0x10) = param_1->debug;
                  iVar7 = 1;
                }
                goto LAB_08094426;
              }
            }
          }
        }
LAB_08094f3f:
        ssl2_return_error(param_1,4);
        iVar7 = -1;
      }
LAB_080941ce:
      sk_free(p_Var12);
      X509_free(x);
      goto LAB_080944ab;
    }
  }
LAB_08094488:
  ERR_put_error(0x14,0x7a,0xff,"s2_srvr.c",0x157);
  iVar7 = -1;
  goto LAB_080944ab;
}

