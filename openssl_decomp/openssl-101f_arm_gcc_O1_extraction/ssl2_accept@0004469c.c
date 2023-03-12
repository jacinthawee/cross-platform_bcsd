
int ssl2_accept(SSL *param_1)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  BIO *pBVar7;
  _STACK *p_Var8;
  _STACK *st;
  void *data;
  undefined4 uVar9;
  _STACK *st_00;
  EVP_CIPHER *d;
  EVP_PKEY *pkey;
  ssl2_state_st *psVar10;
  SSL_SESSION *pSVar11;
  ulong uVar12;
  SSL_SESSION *pSVar13;
  int iVar14;
  BUF_MEM *pBVar15;
  char *pcVar16;
  byte *pbVar17;
  _func_3152 *p_Var18;
  X509 *st_01;
  uchar *puVar19;
  size_t sVar20;
  size_t sVar21;
  int iVar22;
  X509 *x;
  size_t sVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 in_stack_ffffffa0;
  undefined4 in_stack_ffffffa4;
  time_t local_4c;
  uchar *local_48;
  EVP_CIPHER *local_44;
  EVP_MD_CTX local_40;
  
  local_4c = time((time_t *)0x0);
  RAND_add(&local_4c,4,(double)CONCAT44(in_stack_ffffffa4,in_stack_ffffffa0));
  ERR_clear_error();
  piVar3 = __errno_location();
  p_Var18 = param_1->info_callback;
  *piVar3 = 0;
  if (p_Var18 == (_func_3152 *)0x0) {
    p_Var18 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar4 = SSL_state(param_1);
  if (((uVar4 & 0x3000) == 0) || (iVar5 = SSL_state(param_1), iVar5 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  if (param_1->cert == (cert_st *)0x0) {
    ERR_put_error(0x14,0x7a,0xb3,"s2_srvr.c",0xa9);
    return -1;
  }
  *piVar3 = 0;
  iVar5 = param_1->state;
  do {
    while (iVar14 = iVar5, 0x2041 < iVar14) {
      if (iVar14 < 0x2062) {
        if (0x205f < iVar14) {
          if (iVar14 == 0x2060) {
            pcVar16 = param_1->init_buf->data;
            *pcVar16 = '\x06';
            sVar20 = param_1->session->session_id_length;
            if (0x20 < sVar20) {
              iVar5 = -1;
              ERR_put_error(0x14,0xef,0x44,"s2_srvr.c",0x388);
              goto LAB_00044a5c;
            }
            memcpy(pcVar16 + 1,param_1->session->session_id,sVar20);
            param_1->state = 0x2061;
            uVar4 = param_1->session->session_id_length;
            param_1->init_off = 0;
            param_1->init_num = uVar4 + 1;
          }
          iVar5 = ssl2_do_write(param_1);
          if (0 < iVar5) {
            iVar5 = 3;
            param_1->state = 3;
            param_1->init_num = 0;
            goto LAB_00044836;
          }
          goto LAB_00044a5c;
        }
        if (iVar14 == 0x2042) {
          lVar6 = BIO_ctrl(param_1->wbio,3,0,(void *)0x0);
          if (0 < lVar6) {
            param_1->rwstate = 2;
            lVar6 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
            if (lVar6 < 1) goto LAB_00044f4c;
            param_1->rwstate = 1;
          }
          pBVar7 = BIO_pop(param_1->wbio);
          iVar5 = 0x2050;
          param_1->state = 0x2050;
          param_1->wbio = pBVar7;
          goto LAB_00044aaa;
        }
        if (1 < iVar14 - 0x2050U) goto LAB_00044a40;
        pcVar16 = param_1->init_buf->data;
        if (iVar14 == 0x2050) {
          iVar5 = ssl2_read(param_1,pcVar16 + param_1->init_num,1 - param_1->init_num);
          if (iVar5 < 1 - param_1->init_num) {
LAB_00044dd8:
            iVar5 = ssl2_part_read(param_1,0x69,iVar5);
          }
          else {
            param_1->init_num = param_1->init_num + iVar5;
            if (*pcVar16 == '\x03') {
              param_1->state = 0x2051;
              goto LAB_000447ce;
            }
            if (*pcVar16 != '\0') {
              ssl2_return_error(param_1,0);
              ERR_put_error(0x14,0x69,0xd4,"s2_srvr.c",0x33e);
              goto LAB_00044f4c;
            }
            ERR_put_error(0x14,0x69,200,"s2_srvr.c",0x342);
            uVar9 = ssl2_read(param_1,pcVar16 + param_1->init_num,3 - param_1->init_num);
            iVar5 = ssl2_part_read(param_1,0x6e,uVar9);
          }
          if (iVar5 < 1) goto LAB_00044a5c;
        }
        else {
LAB_000447ce:
          uVar4 = param_1->s2->conn_id_length;
          if (0x10 < uVar4) {
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x69,0x44,"s2_srvr.c",0x350);
            goto LAB_00044f4c;
          }
          sVar20 = uVar4 + 1;
          iVar22 = sVar20 - param_1->init_num;
          iVar5 = ssl2_read(param_1,pcVar16 + param_1->init_num,iVar22);
          if (iVar5 < iVar22) goto LAB_00044dd8;
          if (param_1->msg_callback != (_func_3150 *)0x0) {
            (*param_1->msg_callback)
                      (0,param_1->version,0,pcVar16,sVar20,param_1,param_1->msg_callback_arg);
          }
          iVar5 = memcmp(pcVar16 + 1,param_1->s2->conn_id,param_1->s2->conn_id_length);
          if (iVar5 != 0) {
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x69,0x8f,"s2_srvr.c",0x360);
            goto LAB_00044f4c;
          }
        }
        iVar5 = 0x2070;
        param_1->state = 0x2070;
        param_1->init_num = 0;
        goto LAB_00044836;
      }
      if (iVar14 != 0x2080) {
        if (iVar14 < 0x2081) {
          if (iVar14 - 0x2070U < 4) {
            if ((-1 < param_1->verify_mode << 0x1f) ||
               ((*(int *)(param_1->session->krb5_client_princ + 0xc) != 0 &&
                (param_1->verify_mode << 0x1d < 0)))) {
              iVar5 = 0x2060;
              param_1->state = 0x2060;
              goto LAB_00044836;
            }
            psVar10 = param_1->s2;
            puVar19 = (psVar10->tmp).ccl;
            if (iVar14 == 0x2070) {
              pcVar16 = param_1->init_buf->data;
              *pcVar16 = '\a';
              pcVar16[1] = '\x01';
              iVar5 = RAND_pseudo_bytes(puVar19,0x10);
              if (iVar5 < 1) goto LAB_00044f4c;
              uVar24 = *(undefined4 *)((psVar10->tmp).ccl + 4);
              uVar25 = *(undefined4 *)((psVar10->tmp).ccl + 8);
              uVar9 = *(undefined4 *)((psVar10->tmp).ccl + 0xc);
              *(undefined4 *)(pcVar16 + 2) = *(undefined4 *)puVar19;
              *(undefined4 *)(pcVar16 + 6) = uVar24;
              *(undefined4 *)(pcVar16 + 10) = uVar25;
              *(undefined4 *)(pcVar16 + 0xe) = uVar9;
              param_1->state = 0x2071;
              param_1->init_num = 0x12;
              param_1->init_off = 0;
LAB_000452e0:
              iVar5 = ssl2_do_write(param_1);
              if (iVar5 < 1) {
                st_01 = (X509 *)0x0;
                x = (X509 *)0x0;
              }
              else {
                iVar22 = 6;
                iVar5 = 0;
                param_1->init_num = 0;
                param_1->state = 0x2072;
LAB_000452f8:
                pbVar17 = (byte *)param_1->init_buf->data;
                iVar5 = ssl2_read(param_1,pbVar17 + iVar5,iVar22);
                if (iVar5 < 3 - param_1->init_num) goto LAB_00045128;
                iVar5 = param_1->init_num + iVar5;
                param_1->init_num = iVar5;
                st_01 = (X509 *)(uint)*pbVar17;
                if ((iVar5 < 3) || (st_01 != (X509 *)0x0)) {
                  if ((st_01 == (X509 *)&DAT_00000008) && (5 < iVar5)) {
                    if (iVar5 == 6) {
                      if (pbVar17[1] == 1) {
                        psVar10 = param_1->s2;
                        (psVar10->tmp).clen = (uint)CONCAT11(pbVar17[2],pbVar17[3]);
                        (psVar10->tmp).rlen = (uint)CONCAT11(pbVar17[4],pbVar17[5]);
                        param_1->state = 0x2073;
                        goto LAB_000448a4;
                      }
                      st_01 = (X509 *)0x0;
                      ssl2_return_error(param_1);
                      ERR_put_error(0x14,0x71,0x75,"s2_srvr.c",0x3f5);
                      x = (X509 *)0x0;
                      iVar5 = -1;
                    }
                    else {
                      st_01 = (X509 *)0x0;
                      ERR_put_error(0x14,0x71,0x44,"s2_srvr.c",0x3eb);
                      x = (X509 *)0x0;
                      iVar5 = -1;
                    }
                  }
                  else {
                    ssl2_return_error(param_1,0);
                    st_01 = (X509 *)0x0;
                    ERR_put_error(0x14,0x71,0xdb,"s2_srvr.c",0x3e6);
                    x = (X509 *)0x0;
                    iVar5 = -1;
                  }
                }
                else {
                  if (pbVar17[1] != 2) {
                    param_1->init_num = iVar5 + -3;
                    iVar5 = ssl2_part_read(param_1,0x71,3);
                    x = st_01;
                    goto LAB_0004513a;
                  }
                  if (param_1->msg_callback != (_func_3150 *)0x0) {
                    (*param_1->msg_callback)
                              (0,param_1->version,0,pbVar17 + 2,3,param_1,param_1->msg_callback_arg)
                    ;
                  }
                  if ((param_1->verify_mode & 2U) == 0) {
                    sk_free((_STACK *)0x0);
                    X509_free((X509 *)0x0);
LAB_0004514c:
                    iVar5 = 0x2060;
                    param_1->state = 0x2060;
                    param_1->init_num = 0;
                    goto LAB_00044836;
                  }
                  ssl2_return_error(param_1,4);
                  st_01 = (X509 *)0x0;
                  ERR_put_error(0x14,0x71,199,"s2_srvr.c",0x3dd);
                  x = (X509 *)0x0;
                  iVar5 = -1;
                }
              }
            }
            else {
              if (iVar14 == 0x2071) goto LAB_000452e0;
              if (iVar14 == 0x2072) {
                iVar5 = param_1->init_num;
                iVar22 = 6 - iVar5;
                goto LAB_000452f8;
              }
LAB_000448a4:
              uVar4 = (psVar10->tmp).clen + (psVar10->tmp).rlen + 6;
              pcVar16 = param_1->init_buf->data;
              if (uVar4 < 0x4000) {
                iVar22 = uVar4 - param_1->init_num;
                iVar5 = ssl2_read(param_1,pcVar16 + param_1->init_num,iVar22);
                if (iVar5 < iVar22) {
LAB_00045128:
                  st_01 = (X509 *)0x0;
                  iVar5 = ssl2_part_read(param_1,0x71,iVar5);
                  x = (X509 *)0x0;
                  goto LAB_0004513a;
                }
                if (param_1->msg_callback != (_func_3150 *)0x0) {
                  (*param_1->msg_callback)
                            (0,param_1->version,0,pcVar16,uVar4,param_1,param_1->msg_callback_arg);
                }
                local_48 = (uchar *)(pcVar16 + 6);
                x = d2i_X509((X509 **)0x0,&local_48,(param_1->s2->tmp).clen);
                if (x == (X509 *)0x0) {
                  ERR_put_error(0x14,0x71,0xb,"s2_srvr.c",0x414);
                  st_01 = x;
                }
                else {
                  st_01 = (X509 *)sk_new_null();
                  if ((st_01 == (X509 *)0x0) || (iVar5 = sk_push((_STACK *)st_01,x), iVar5 == 0)) {
                    iVar5 = 0x41a;
LAB_000450bc:
                    ERR_put_error(0x14,0x71,0x41,"s2_srvr.c",iVar5);
                  }
                  else {
                    iVar5 = ssl_verify_cert_chain(param_1,st_01);
                    if (0 < iVar5) {
                      EVP_MD_CTX_init(&local_40);
                      iVar5 = EVP_DigestInit_ex(&local_40,
                                                *(EVP_MD **)(param_1->psk_server_callback + 0x88),
                                                (ENGINE *)0x0);
                      if (((iVar5 != 0) &&
                          (iVar5 = EVP_DigestUpdate(&local_40,param_1->s2->key_material,
                                                    param_1->s2->key_material_length), iVar5 != 0))
                         && (iVar5 = EVP_DigestUpdate(&local_40,puVar19,0x10), iVar5 != 0)) {
                        iVar5 = i2d_X509(*(X509 **)(param_1->cert + 0x30),(uchar **)0x0);
                        d = (EVP_CIPHER *)CRYPTO_malloc(iVar5,"s2_srvr.c",0x42e);
                        if (d == (EVP_CIPHER *)0x0) {
                          iVar5 = 0x431;
                          goto LAB_000450bc;
                        }
                        local_44 = d;
                        sVar20 = i2d_X509(*(X509 **)(param_1->cert + 0x30),(uchar **)&local_44);
                        iVar5 = EVP_DigestUpdate(&local_40,d,sVar20);
                        if (iVar5 != 0) {
                          CRYPTO_free(d);
                          pkey = X509_get_pubkey(x);
                          if (pkey == (EVP_PKEY *)0x0) {
                            iVar5 = -1;
                          }
                          else {
                            iVar5 = EVP_VerifyFinal(&local_40,local_48,(param_1->s2->tmp).rlen,pkey)
                            ;
                            EVP_PKEY_free(pkey);
                            EVP_MD_CTX_cleanup(&local_40);
                            if (iVar5 < 1) {
                              ERR_put_error(0x14,0x71,0x68,"s2_srvr.c",0x44f);
                              goto LAB_000450cc;
                            }
                            pSVar11 = param_1->session;
                            if (*(X509 **)(pSVar11->krb5_client_princ + 0xc) != (X509 *)0x0) {
                              X509_free(*(X509 **)(pSVar11->krb5_client_princ + 0xc));
                              pSVar11 = param_1->session;
                            }
                            *(X509 **)(pSVar11->krb5_client_princ + 0xc) = x;
                            CRYPTO_add_lock(&x->references,1,3,"s2_srvr.c",0x448);
                            iVar5 = 1;
                            *(int *)(param_1->session->krb5_client_princ + 0x10) = param_1->debug;
                          }
LAB_0004513a:
                          sk_free((_STACK *)st_01);
                          X509_free(x);
                          if (0 < iVar5) goto LAB_0004514c;
                          goto LAB_00044a5c;
                        }
                        CRYPTO_free(d);
                      }
                    }
                  }
                }
LAB_000450cc:
                ssl2_return_error(param_1,4);
                iVar5 = -1;
              }
              else {
                st_01 = (X509 *)0x0;
                ERR_put_error(0x14,0x71,0x128,"s2_srvr.c",0x402);
                x = (X509 *)0x0;
                iVar5 = -1;
              }
            }
            sk_free((_STACK *)st_01);
            X509_free(x);
            goto LAB_00044a5c;
          }
        }
        else if ((iVar14 == 0x4000) || (iVar14 == 0x6000)) goto LAB_00044aee;
LAB_00044a40:
        iVar5 = -1;
        ERR_put_error(0x14,0x7a,0xff,"s2_srvr.c",0x157);
        goto LAB_00044a5c;
      }
      iVar5 = ssl2_enc_init(param_1,0);
      if (iVar5 == 0) goto LAB_00044f4c;
      iVar5 = 0x2040;
      param_1->s2->clear_text = 0;
      param_1->state = 0x2040;
LAB_00044aaa:
      if (p_Var18 != (_func_3152 *)0x0) {
LAB_0004483c:
        param_1->state = iVar14;
        (*p_Var18)(param_1,0x2001,1);
        param_1->state = iVar5;
      }
    }
    if (iVar14 < 0x2040) {
      if (iVar14 < 0x2013) {
        if (iVar14 < 0x2010) {
          if ((iVar14 != 0x2000) && (iVar14 != 0x2003)) {
            if (iVar14 != 3) goto LAB_00044a40;
            BUF_MEM_free(param_1->init_buf);
            ssl_free_wbio_buffer(param_1);
            param_1->init_buf = (BUF_MEM *)0x0;
            param_1->init_num = 0;
            ssl_update_cache(param_1,2);
            *(int *)(param_1->psk_server_callback + 0x48) =
                 *(int *)(param_1->psk_server_callback + 0x48) + 1;
            if (p_Var18 == (_func_3152 *)0x0) {
              param_1->in_handshake = param_1->in_handshake + -1;
              return 1;
            }
            iVar5 = 1;
            (*p_Var18)(param_1,0x20,1);
            param_1->in_handshake = param_1->in_handshake + -1;
            goto LAB_0004477e;
          }
LAB_00044aee:
          param_1->server = 1;
          if (p_Var18 != (_func_3152 *)0x0) {
            (*p_Var18)(param_1,0x10,1);
          }
          pBVar15 = param_1->init_buf;
          param_1->version = 2;
          param_1->type = 0x2000;
          if (((pBVar15 != (BUF_MEM *)0x0) || (pBVar15 = BUF_MEM_new(), pBVar15 != (BUF_MEM *)0x0))
             && (iVar5 = BUF_MEM_grow(pBVar15,0x3fff), iVar5 != 0)) {
            param_1->init_num = 0;
            iVar5 = 0x2010;
            param_1->init_buf = pBVar15;
            *(int *)(param_1->psk_server_callback + 0x40) =
                 *(int *)(param_1->psk_server_callback + 0x40) + 1;
            param_1->handshake_func = ssl2_accept;
            param_1->state = 0x2010;
            goto LAB_00044836;
          }
          goto LAB_00044f4c;
        }
        param_1->shutdown = 0;
        if (iVar14 == 0x2010) {
          param_1->max_cert_list = 1;
          param_1->state = 0x2011;
          pcVar16 = param_1->init_buf->data;
LAB_00044e4c:
          iVar5 = ssl2_read(param_1,pcVar16 + param_1->init_num,9 - param_1->init_num);
          if (9 - param_1->init_num <= iVar5) {
            param_1->init_num = 9;
            if (*pcVar16 == '\x01') {
              if ((int)(uint)CONCAT11(pcVar16[1],pcVar16[2]) < param_1->version) {
                param_1->version = (uint)CONCAT11(pcVar16[1],pcVar16[2]);
              }
              psVar10 = param_1->s2;
              (psVar10->tmp).cipher_spec_length = (uint)CONCAT11(pcVar16[3],pcVar16[4]);
              (psVar10->tmp).session_id_length = (uint)CONCAT11(pcVar16[5],pcVar16[6]);
              cVar1 = pcVar16[7];
              cVar2 = pcVar16[8];
              psVar10->challenge_length = (uint)CONCAT11(cVar1,cVar2);
              if (CONCAT11(cVar1,cVar2) - 0x10 < 0x11) {
                pBVar15 = param_1->init_buf;
                param_1->state = 0x2012;
                goto LAB_00044b54;
              }
              ssl2_return_error(param_1,0);
              ERR_put_error(0x14,0x6a,0x9e,"s2_srvr.c",0x237);
              iVar5 = -1;
            }
            else if (*pcVar16 == '\0') {
              iVar5 = -1;
              ERR_put_error(0x14,0x6a,200,"s2_srvr.c",0x22b);
            }
            else {
              ssl2_return_error(param_1,0);
              ERR_put_error(0x14,0x6a,0xd4,"s2_srvr.c",0x228);
              iVar5 = -1;
            }
            goto LAB_00044a5c;
          }
LAB_00044e64:
          iVar5 = ssl2_part_read(param_1,0x6a,iVar5);
          if (iVar5 < 1) goto LAB_00044a5c;
        }
        else {
          pBVar15 = param_1->init_buf;
          pcVar16 = pBVar15->data;
          if (iVar14 == 0x2011) goto LAB_00044e4c;
          psVar10 = param_1->s2;
LAB_00044b54:
          pcVar16 = pBVar15->data;
          uVar4 = (psVar10->tmp).cipher_spec_length + psVar10->challenge_length + 9 +
                  (psVar10->tmp).session_id_length;
          if (0x3fff < uVar4) {
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x6a,0x128,"s2_srvr.c",0x243);
            iVar5 = -1;
            goto LAB_00044a5c;
          }
          iVar22 = uVar4 - param_1->init_num;
          iVar5 = ssl2_read(param_1,pcVar16 + param_1->init_num,iVar22);
          if (iVar22 != iVar5) goto LAB_00044e64;
          if (param_1->msg_callback != (_func_3150 *)0x0) {
            (*param_1->msg_callback)
                      (0,param_1->version,0,pcVar16,uVar4,param_1,param_1->msg_callback_arg);
          }
          pcVar16 = pcVar16 + 9;
          uVar4 = (param_1->s2->tmp).session_id_length;
          if ((uVar4 & 0xffffffef) != 0) {
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x6a,0x7d,"s2_srvr.c",0x254);
            iVar5 = -1;
            goto LAB_00044a5c;
          }
          if (uVar4 == 0) {
LAB_00044bba:
            iVar5 = ssl_get_new_session(param_1,1);
            if (iVar5 == 0) {
LAB_00045604:
              ssl2_return_error(param_1,0);
              iVar5 = -1;
              goto LAB_00044a5c;
            }
            if (param_1->hit == 0) {
              p_Var8 = (_STACK *)
                       ssl_bytes_to_cipher_list
                                 (param_1,pcVar16,(param_1->s2->tmp).cipher_spec_length,
                                  param_1->session->krb5_client_princ + 0x2c);
              if ((p_Var8 == (_STACK *)0x0) ||
                 ((st = (_STACK *)SSL_get_ciphers(param_1), st_00 = p_Var8,
                  param_1->references << 9 < 0 &&
                  (st_00 = sk_dup(st), st = p_Var8, st_00 == (_STACK *)0x0)))) {
                iVar5 = 0;
                ERR_put_error(0x14,0x6a,0x41,"s2_srvr.c",0x2b5);
                goto LAB_00044a5c;
              }
              for (iVar5 = 0; iVar22 = sk_num(st_00), iVar5 < iVar22; iVar5 = iVar5 + 1) {
                data = sk_value(st_00,iVar5);
                iVar22 = sk_find(st,data);
                if (iVar22 < 0) {
                  sk_delete(st_00,iVar5);
                  iVar5 = iVar5 + -1;
                }
              }
              if (param_1->references << 9 < 0) {
                sk_free(*(_STACK **)(param_1->session->krb5_client_princ + 0x2c));
                *(_STACK **)(param_1->session->krb5_client_princ + 0x2c) = st_00;
              }
            }
          }
          else {
            iVar5 = ssl_get_prev_session(param_1,pcVar16 + (param_1->s2->tmp).cipher_spec_length);
            if (iVar5 != 1) {
              if (iVar5 == -1) goto LAB_00045604;
              if (param_1->cert != (cert_st *)0x0) goto LAB_00044bba;
              ssl2_return_error(param_1,2);
              ERR_put_error(0x14,0x6a,0xb3,"s2_srvr.c",0x272);
              iVar5 = -1;
              goto LAB_00044a5c;
            }
            param_1->hit = 1;
          }
          psVar10 = param_1->s2;
          if (0x20 < psVar10->challenge_length) {
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x6a,0x44,"s2_srvr.c",0x2af);
            iVar5 = -1;
            goto LAB_00044a5c;
          }
          memcpy(psVar10->challenge,
                 pcVar16 + (psVar10->tmp).session_id_length + (psVar10->tmp).cipher_spec_length,
                 psVar10->challenge_length);
        }
        iVar5 = 0x2020;
        param_1->state = 0x2020;
        param_1->init_num = 0;
      }
      else {
        if (iVar14 < 0x2020) goto LAB_00044a40;
        if (iVar14 < 0x2022) {
          pcVar16 = param_1->init_buf->data;
          if (iVar14 == 0x2020) {
            local_40.digest = (EVP_MD *)(pcVar16 + 0xb);
            *pcVar16 = '\x04';
            iVar5 = param_1->hit;
            pcVar16[1] = (char)iVar5;
            if (iVar5 == 0) {
              pSVar11 = param_1->session;
              if (*(int *)(pSVar11->krb5_client_princ + 8) != 0) {
                ssl_sess_cert_free();
                pSVar11 = param_1->session;
              }
              uVar9 = ssl_sess_cert_new();
              pSVar13 = param_1->session;
              *(undefined4 *)(pSVar11->krb5_client_princ + 8) = uVar9;
              if (*(int *)(pSVar13->krb5_client_princ + 8) == 0) {
                ERR_put_error(0x14,0x72,0x41,"s2_srvr.c",0x2d0);
LAB_00044f4c:
                iVar5 = -1;
LAB_00044a5c:
                param_1->in_handshake = param_1->in_handshake + -1;
                if (p_Var18 == (_func_3152 *)0x0) {
                  return iVar5;
                }
LAB_0004477e:
                (*p_Var18)(param_1,0x2002,iVar5);
                return iVar5;
              }
              if (param_1->cert == (cert_st *)0x0) goto LAB_000457ae;
              pcVar16[2] = '\x01';
              pcVar16[3] = (char)((uint)param_1->version >> 8);
              pcVar16[4] = (char)param_1->version;
              iVar5 = i2d_X509(*(X509 **)(param_1->cert + 0x30),(uchar **)0x0);
              pcVar16[6] = (char)iVar5;
              pcVar16[5] = (char)((uint)iVar5 >> 8);
              i2d_X509(*(X509 **)(param_1->cert + 0x30),(uchar **)&local_40);
              iVar5 = ssl_cipher_list_to_bytes
                                (param_1,*(undefined4 *)(param_1->session->krb5_client_princ + 0x2c)
                                 ,local_40.digest,0);
              local_40.digest =
                   (EVP_MD *)((int)(local_40.digest)->required_pkey_type + iVar5 + -0x2c);
              pcVar16[8] = (char)iVar5;
              pcVar16[7] = (char)((uint)iVar5 >> 8);
            }
            else {
              if (param_1->cert == (cert_st *)0x0) {
LAB_000457ae:
                ssl2_return_error(param_1,2);
                ERR_put_error(0x14,0x72,0xb4,"s2_srvr.c",0x2f5);
                goto LAB_00044f4c;
              }
              pcVar16[2] = '\0';
              pcVar16[3] = (char)((uint)param_1->version >> 8);
              iVar5 = param_1->version;
              pcVar16[5] = '\0';
              pcVar16[6] = '\0';
              pcVar16[4] = (char)iVar5;
              pcVar16[7] = '\0';
              pcVar16[8] = '\0';
            }
            pcVar16[10] = '\x10';
            pcVar16[9] = '\0';
            psVar10 = param_1->s2;
            psVar10->conn_id_length = 0x10;
            iVar5 = RAND_pseudo_bytes(psVar10->conn_id,0x10);
            if (iVar5 < 1) goto LAB_00044f4c;
            psVar10 = param_1->s2;
            iVar22 = *(int *)psVar10->conn_id;
            iVar5 = *(int *)(psVar10->conn_id + 8);
            uVar12 = *(ulong *)(psVar10->conn_id + 0xc);
            (local_40.digest)->pkey_type = *(int *)(psVar10->conn_id + 4);
            (local_40.digest)->type = iVar22;
            (local_40.digest)->md_size = iVar5;
            (local_40.digest)->flags = uVar12;
            param_1->state = 0x2021;
            local_40.digest = (EVP_MD *)&(local_40.digest)->init;
            pcVar16 = param_1->init_buf->data;
            param_1->init_off = 0;
            param_1->init_num = (int)local_40.digest - (int)pcVar16;
          }
          if ((param_1->hit == 0) || (iVar5 = ssl_init_wbio_buffer(param_1,1), iVar5 != 0)) {
            iVar5 = ssl2_do_write(param_1);
            if (0 < iVar5) {
              param_1->init_num = 0;
              if (param_1->hit == 0) {
                iVar5 = 0x2030;
                param_1->state = 0x2030;
              }
              else {
                iVar5 = 0x2080;
                param_1->state = 0x2080;
              }
              goto LAB_00044836;
            }
            goto LAB_00044a5c;
          }
          goto LAB_00044f4c;
        }
        if (1 < iVar14 - 0x2030U) goto LAB_00044a40;
        pBVar15 = param_1->init_buf;
        pcVar16 = pBVar15->data;
        if (iVar14 != 0x2030) {
LAB_0004492a:
          if (pBVar15->length < 0x3fff) {
            ssl2_return_error(param_1,0);
            iVar5 = 0x1a6;
          }
          else {
            sVar20 = param_1->session->key_arg_length;
            uVar4 = (param_1->s2->tmp).clear + sVar20 + 10 + (param_1->s2->tmp).enc;
            if (0x3fff < uVar4) {
              ssl2_return_error(param_1,0);
              ERR_put_error(0x14,0x6b,0x128,"s2_srvr.c",0x1ae);
              iVar5 = -1;
              goto LAB_00044a5c;
            }
            iVar22 = uVar4 - param_1->init_num;
            iVar5 = ssl2_read(param_1,pcVar16 + param_1->init_num,iVar22);
            if (iVar22 != iVar5) goto LAB_00044dba;
            if (param_1->msg_callback != (_func_3150 *)0x0) {
              (*param_1->msg_callback)
                        (0,param_1->version,0,pcVar16,uVar4,param_1,param_1->msg_callback_arg);
            }
            puVar19 = (uchar *)(pcVar16 + 10);
            memcpy(param_1->session->key_arg,
                   puVar19 + (param_1->s2->tmp).enc + (param_1->s2->tmp).clear,sVar20);
            piVar3 = *(int **)(param_1->cert + 0x34);
            if (piVar3 == (int *)0x0) {
              ssl2_return_error(param_1,0);
              ERR_put_error(0x14,0x6b,0xbd,"s2_srvr.c",0x1be);
              iVar5 = -1;
              goto LAB_00044a5c;
            }
            psVar10 = param_1->s2;
            if (psVar10->ssl2_rollback == 0) {
              iVar5 = 1;
            }
            else {
              iVar5 = 2;
            }
            if (*piVar3 == 6) {
              sVar20 = RSA_private_decrypt((psVar10->tmp).enc,puVar19 + (psVar10->tmp).clear,
                                           puVar19 + (psVar10->tmp).clear,(RSA *)piVar3[5],iVar5);
              if ((int)sVar20 < 0) {
                ERR_put_error(0x14,0xbb,4,"s2_srvr.c",0x473);
              }
            }
            else {
              sVar20 = 0xffffffff;
              ERR_put_error(0x14,0xbb,0xd1,"s2_srvr.c",0x46b);
            }
            uVar4 = *(uint *)(*(int *)(param_1->session->krb5_client_princ + 0x24) + 0x20) & 2;
            iVar5 = ssl_cipher_get_evp(param_1->session,&local_44,&local_40,0,0,0);
            if (iVar5 == 0) {
              ssl2_return_error(param_1,1);
              ERR_put_error(0x14,0x6b,0xce,"s2_srvr.c",0x1ca);
              goto LAB_00044a5c;
            }
            if (*(int *)(*(int *)(param_1->session->krb5_client_princ + 0x24) + 0x24) << 0x1e < 0) {
              if ((int)sVar20 < 0) {
                ERR_clear_error();
                sVar21 = 8;
LAB_00044e0a:
                iVar5 = RAND_pseudo_bytes(puVar19,sVar21);
                if (iVar5 < 1) goto LAB_0004521e;
              }
              else {
                sVar21 = 8;
                sVar23 = 8;
LAB_00044e00:
                if ((sVar23 != sVar20) ||
                   (uVar4 = (param_1->s2->tmp).clear, iVar5 = EVP_CIPHER_key_length(local_44),
                   uVar4 + sVar21 != iVar5)) {
                  ERR_clear_error();
                  sVar21 = sVar23;
                  goto LAB_00044e0a;
                }
              }
              sVar20 = (param_1->s2->tmp).clear + sVar21;
            }
            else {
              if ((int)sVar20 < 0) {
                ERR_clear_error();
                if (uVar4 != 0) {
                  sVar21 = 5;
                  goto LAB_00044e0a;
                }
LAB_00045208:
                sVar20 = EVP_CIPHER_key_length(local_44);
                iVar5 = RAND_pseudo_bytes(puVar19,sVar20);
                if (0 < iVar5) goto LAB_00044e22;
LAB_0004521e:
                iVar5 = 0;
                goto LAB_00044a5c;
              }
              if (uVar4 != 0) {
                sVar21 = 5;
                sVar23 = 5;
                goto LAB_00044e00;
              }
              sVar21 = EVP_CIPHER_key_length(local_44);
              if (sVar21 != sVar20) {
                ERR_clear_error();
                goto LAB_00045208;
              }
            }
LAB_00044e22:
            if ((int)sVar20 < 0x31) {
              pSVar11 = param_1->session;
              pSVar11->master_key_length = sVar20;
              memcpy(pSVar11->master_key,puVar19,sVar20);
              goto LAB_00044dcc;
            }
            ssl2_return_error(param_1,0);
            iVar5 = 0x201;
          }
          ERR_put_error(0x14,0x6b,0x44,"s2_srvr.c",iVar5);
          iVar5 = -1;
          goto LAB_00044a5c;
        }
        iVar5 = ssl2_read(param_1,pcVar16 + param_1->init_num,10 - param_1->init_num);
        if (10 - param_1->init_num <= iVar5) {
          param_1->init_num = 10;
          if (*pcVar16 == '\x02') {
            iVar5 = ssl2_get_cipher_by_char(pcVar16 + 1);
            if (iVar5 == 0) {
              ssl2_return_error(param_1,1);
              ERR_put_error(0x14,0x6b,0xb9,"s2_srvr.c",0x18e);
              iVar5 = -1;
            }
            else {
              pSVar11 = param_1->session;
              psVar10 = param_1->s2;
              *(int *)(pSVar11->krb5_client_princ + 0x24) = iVar5;
              (psVar10->tmp).clear = (uint)CONCAT11(pcVar16[4],pcVar16[5]);
              (psVar10->tmp).enc = (uint)CONCAT11(pcVar16[6],pcVar16[7]);
              if (CONCAT11(pcVar16[8],pcVar16[9]) < 9) {
                pBVar15 = param_1->init_buf;
                pSVar11->key_arg_length = (uint)CONCAT11(pcVar16[8],pcVar16[9]);
                param_1->state = 0x2031;
                pcVar16 = pBVar15->data;
                goto LAB_0004492a;
              }
              ssl2_return_error(param_1,0);
              ERR_put_error(0x14,0x6b,0x11c,"s2_srvr.c",0x19a);
              iVar5 = -1;
            }
          }
          else if (*pcVar16 == '\0') {
            iVar5 = -1;
            ERR_put_error(0x14,0x6b,200,"s2_srvr.c",0x186);
          }
          else {
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x6b,0xd4,"s2_srvr.c",0x183);
            iVar5 = -1;
          }
          goto LAB_00044a5c;
        }
LAB_00044dba:
        iVar5 = ssl2_part_read(param_1,0x6b,iVar5);
        if (iVar5 < 1) goto LAB_00044a5c;
LAB_00044dcc:
        iVar5 = 0x2080;
        param_1->state = 0x2080;
        param_1->init_num = 0;
      }
    }
    else {
      if (iVar14 == 0x2040) {
        pcVar16 = param_1->init_buf->data;
        *pcVar16 = '\x05';
        sVar20 = param_1->s2->challenge_length;
        if (0x20 < sVar20) {
          iVar5 = -1;
          ERR_put_error(0x14,0xf0,0x44,"s2_srvr.c",0x370);
          goto LAB_00044a5c;
        }
        memcpy(pcVar16 + 1,param_1->s2->challenge,sVar20);
        param_1->state = 0x2041;
        uVar4 = param_1->s2->challenge_length;
        param_1->init_off = 0;
        param_1->init_num = uVar4 + 1;
      }
      iVar5 = ssl2_do_write(param_1);
      if (iVar5 < 1) goto LAB_00044a5c;
      param_1->init_num = 0;
      if (param_1->hit == 0) {
        iVar5 = 0x2050;
        param_1->state = 0x2050;
      }
      else {
        iVar5 = 0x2042;
        param_1->state = 0x2042;
      }
    }
LAB_00044836:
    if ((p_Var18 != (_func_3152 *)0x0) && (iVar5 != iVar14)) goto LAB_0004483c;
  } while( true );
}

