
undefined1 * dtls1_accept(SSL *param_1)

{
  uchar *puVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  cert_st *pcVar8;
  undefined1 *val;
  ssl3_state_st *psVar9;
  int iVar10;
  ssl3_enc_method *psVar11;
  BUF_MEM *pBVar12;
  undefined4 uVar13;
  dtls1_state_st *pdVar14;
  SSL_CIPHER *pSVar15;
  int iVar16;
  uint uVar17;
  undefined4 uVar18;
  char *pcVar19;
  _func_3152 *p_Var20;
  uint uVar21;
  code *pcVar22;
  int iVar23;
  undefined4 local_30;
  int local_2c;
  
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_30 = (*(code *)PTR_time_006a9adc)(0);
  (*(code *)PTR_RAND_add_006a8004)(&local_30,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a6ee0)();
  puVar6 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
  p_Var20 = param_1->info_callback;
  *puVar6 = 0;
  if (p_Var20 == (_func_3152 *)0x0) {
    p_Var20 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  uVar21 = param_1->d1->mtu;
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar7 = SSL_state(param_1);
  if (((uVar7 & 0x3000) == 0) || (uVar7 = SSL_state(param_1), (uVar7 & 0x4000) != 0)) {
    SSL_clear(param_1);
  }
  pcVar8 = param_1->cert;
  param_1->d1->mtu = uVar21;
  if (pcVar8 == (cert_st *)0x0) {
    uVar18 = 0xb3;
    uVar13 = 0xb9;
LAB_0049ac80:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf6,uVar18,"d1_srvr.c",uVar13);
    val = (undefined1 *)0xffffffff;
  }
  else {
    if (param_1->tlsext_heartbeat != 0) {
      dtls1_stop_timer(param_1);
      param_1->tlsext_heartbeat = 0;
      param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
    }
    iVar16 = param_1->state;
LAB_00499dac:
    iVar23 = iVar16;
    if (0x2171 < iVar16) goto LAB_00499e74;
LAB_00499dbc:
    puVar4 = PTR_ssl3_get_client_hello_006a8238;
    puVar3 = PTR_BIO_ctrl_006a6e18;
    if (iVar23 < 0x2170) {
      if (0x2121 < iVar23) {
        if (iVar23 < 0x2142) {
          if (0x213f < iVar23) {
            psVar9 = param_1->s3;
            pSVar15 = (psVar9->tmp).new_cipher;
            if (((pSVar15->algorithm_auth & 4) != 0) || ((pSVar15->algorithm_mkey & 0x100) != 0)) {
              param_1->init_num = 0;
              bVar2 = true;
              param_1->state = 0x2150;
LAB_0049a4ec:
              if ((psVar9->tmp).reuse_message != 0) goto LAB_00499e60;
              if (bVar2) {
                iVar23 = param_1->state;
                goto LAB_00499e64;
              }
LAB_00499ee0:
              if ((param_1->ctx == (SSL_CTX *)0x0) ||
                 (val = (undefined1 *)(*(code *)PTR_BIO_ctrl_006a6e18)(param_1->wbio,0xb,0,0),
                 0 < (int)val)) {
                if (p_Var20 == (_func_3152 *)0x0) {
LAB_00499e60:
                  iVar23 = param_1->state;
LAB_00499e64:
                  if (iVar23 < 0x2172) goto LAB_00499dbc;
LAB_00499e74:
                  if (iVar23 < 0x21d2) {
                    if (0x21cf < iVar23) {
                      pcVar22 = *(code **)(param_1->method->ssl3_enc + 8);
                      *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24) =
                           (param_1->s3->tmp).new_cipher;
                      iVar16 = (*pcVar22)(param_1);
                      if (iVar16 != 0) {
                        val = (undefined1 *)dtls1_send_change_cipher_spec(param_1,0x21d0,0x21d1);
                        if ((int)val < 1) goto LAB_00499fc0;
                        param_1->init_num = 0;
                        param_1->state = 0x21e0;
                        iVar16 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x22);
                        if (iVar16 != 0) {
                          dtls1_reset_seq_numbers(param_1,2);
                          psVar9 = param_1->s3;
                          goto LAB_0049a0f8;
                        }
                      }
LAB_0049ac60:
                      val = (undefined1 *)0xffffffff;
                      param_1->state = 5;
                      goto LAB_00499fc0;
                    }
                    if (iVar23 < 0x2192) {
                      if (iVar23 < 0x2190) {
                        if (1 < iVar23 - 0x2180U) goto LAB_0049a540;
                        val = (undefined1 *)(*(code *)PTR_ssl3_check_client_hello_006a8224)(param_1)
                        ;
                        if ((int)val < 1) goto LAB_00499fc0;
                        if (val != (undefined1 *)0x2) goto code_r0x00499ebc;
                        dtls1_stop_timer(param_1);
                        psVar9 = param_1->s3;
                        param_1->state = 0x2112;
                      }
                      else {
                        val = (undefined1 *)ssl3_get_client_key_exchange(param_1);
                        if ((int)val < 1) goto LAB_00499fc0;
                        param_1->init_num = 0;
                        param_1->state = 0x21a0;
                        if (val == (undefined1 *)0x2) {
                          psVar9 = param_1->s3;
                          param_1->state = 0x21c0;
                        }
                        else {
                          (**(code **)(param_1->method->ssl3_enc + 0x1c))
                                    (param_1,4,&param_1->s3->tmp);
                          (**(code **)(param_1->method->ssl3_enc + 0x1c))
                                    (param_1,0x40,(param_1->s3->tmp).cert_verify_md + 0x10);
                          psVar9 = param_1->s3;
                        }
                      }
                    }
                    else {
                      if (iVar23 < 0x21a0) goto LAB_0049a540;
                      if (iVar23 < 0x21a2) {
                        val = (undefined1 *)ssl3_get_cert_verify(param_1);
                        if ((int)val < 1) goto LAB_00499fc0;
                        psVar9 = param_1->s3;
                        param_1->init_num = 0;
                        param_1->state = 0x21c0;
                      }
                      else {
                        if (1 < iVar23 - 0x21c0U) goto LAB_0049a540;
                        if (param_1->s3->change_cipher_spec == 0) {
                          param_1->d1[1].send_cookie = 1;
                        }
                        val = (undefined1 *)ssl3_get_finished(param_1,0x21c0,0x21c1);
                        if ((int)val < 1) goto LAB_00499fc0;
                        dtls1_stop_timer(param_1);
                        if (param_1->hit == 0) {
LAB_0049a084:
                          if (param_1->tlsext_ocsp_resplen == 0) {
                            param_1->init_num = 0;
                            param_1->state = 0x21d0;
                            psVar9 = param_1->s3;
                          }
                          else {
                            param_1->init_num = 0;
                            param_1->state = 0x21f0;
                            psVar9 = param_1->s3;
                          }
                        }
                        else {
                          param_1->init_num = 0;
                          param_1->state = 3;
                          psVar9 = param_1->s3;
                        }
                      }
                    }
                  }
                  else if (iVar23 < 0x2202) {
                    if (iVar23 < 0x2200) {
                      if (iVar23 < 0x21e0) goto LAB_0049a540;
                      if (iVar23 < 0x21e2) {
                        psVar11 = param_1->method->ssl3_enc;
                        val = (undefined1 *)
                              dtls1_send_finished(param_1,0x21e0,0x21e1,
                                                  *(undefined4 *)(psVar11 + 0x28),
                                                  *(undefined4 *)(psVar11 + 0x2c));
                        if ((int)val < 1) goto LAB_00499fc0;
                        param_1->state = 0x2100;
                        if (param_1->hit == 0) {
                          psVar9 = param_1->s3;
                          (psVar9->tmp).next_state = 3;
                          param_1->init_num = 0;
                        }
                        else {
                          psVar9 = param_1->s3;
                          (psVar9->tmp).next_state = 0x21c0;
                          param_1->init_num = 0;
                        }
                      }
                      else {
                        if (1 < iVar23 - 0x21f0U) goto LAB_0049a540;
                        val = (undefined1 *)dtls1_send_newsession_ticket(param_1);
                        if ((int)val < 1) goto LAB_00499fc0;
                        psVar9 = param_1->s3;
                        param_1->init_num = 0;
                        param_1->state = 0x21d0;
                      }
                    }
                    else {
                      val = (undefined1 *)ssl3_send_cert_status(param_1);
                      if ((int)val < 1) goto LAB_00499fc0;
                      psVar9 = param_1->s3;
                      param_1->init_num = 0;
                      param_1->state = 0x2150;
                    }
                  }
                  else {
                    if ((iVar23 != 0x4000) && (iVar23 != 0x6000)) {
                      if (iVar23 != 0x3004) goto LAB_0049a540;
                      param_1->tlsext_hb_seq = 1;
                    }
LAB_0049a2e0:
                    param_1->server = 1;
                    if (p_Var20 != (_func_3152 *)0x0) {
                      (*p_Var20)(param_1,0x10,1);
                    }
                    if ((param_1->version & 0xff00U) != 0xfe00) {
                      uVar18 = 0x44;
                      uVar13 = 0xdb;
                      goto LAB_0049ac80;
                    }
                    param_1->type = 0x2000;
                    if (param_1->init_buf == (BUF_MEM *)0x0) {
                      pBVar12 = (BUF_MEM *)(*(code *)PTR_BUF_MEM_new_006a749c)();
                      if (pBVar12 != (BUF_MEM *)0x0) {
                        iVar16 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(pBVar12,0x4000);
                        if (iVar16 != 0) {
                          param_1->init_buf = pBVar12;
                          goto LAB_0049a31c;
                        }
                        (*(code *)PTR_BUF_MEM_free_006a7494)(pBVar12);
                      }
                      goto LAB_0049ac60;
                    }
LAB_0049a31c:
                    iVar16 = ssl3_setup_buffers(param_1);
                    if (iVar16 == 0) goto LAB_0049ac60;
                    psVar9 = param_1->s3;
                    iVar16 = param_1->state;
                    param_1->init_num = 0;
                    param_1->d1[1].send_cookie = 0;
                    psVar9->change_cipher_spec = 0;
                    if (iVar16 != 0x3004) {
                      iVar16 = ssl_init_wbio_buffer(param_1,1);
                      if (iVar16 == 0) goto LAB_0049ac60;
                      ssl3_init_finished_mac(param_1);
                      param_1->state = 0x2110;
                      psVar9 = param_1->s3;
                      *(int *)(param_1->psk_server_callback + 0x40) =
                           *(int *)(param_1->psk_server_callback + 0x40) + 1;
                      goto LAB_0049a0f8;
                    }
                    if ((psVar9->send_connection_binding == 0) &&
                       ((param_1->references & 0x40000U) == 0)) {
                      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf6,0x152,"d1_srvr.c",0x116);
                      ssl3_send_alert(param_1,2,0x28);
                      val = (undefined1 *)0xffffffff;
                      param_1->state = 5;
                      goto LAB_00499fc0;
                    }
                    *(int *)(param_1->psk_server_callback + 0x44) =
                         *(int *)(param_1->psk_server_callback + 0x44) + 1;
                    param_1->state = 0x2120;
                  }
LAB_0049a0f8:
                  if ((psVar9->tmp).reuse_message == 0) goto LAB_00499ee0;
                  iVar23 = param_1->state;
                  goto LAB_00499e64;
                }
                iVar10 = param_1->state;
                iVar16 = iVar23;
                if (iVar10 != iVar23) {
                  param_1->state = iVar23;
                  (*p_Var20)(param_1,0x2001,1);
                  param_1->state = iVar10;
                  iVar16 = iVar10;
                }
                goto LAB_00499dac;
              }
              iVar16 = param_1->in_handshake;
              goto LAB_00499fc4;
            }
            dtls1_start_timer(param_1);
            if (param_1->state == 0x2140) {
              iVar16 = ssl_get_server_send_cert(param_1);
              if ((iVar16 == 0) &&
                 ((pSVar15 = (param_1->s3->tmp).new_cipher, pSVar15->algorithm_mkey != 0x10 ||
                  (pSVar15->algorithm_auth != 0x20)))) {
                uVar13 = 0x65f;
              }
              else {
                iVar16 = dtls1_output_cert_chain(param_1,iVar16);
                if (iVar16 != 0) {
                  param_1->init_num = iVar16;
                  param_1->init_off = 0;
                  param_1->state = 0x2141;
                  dtls1_buffer_message(param_1,0);
                  goto LAB_0049a8a8;
                }
                uVar13 = 0x666;
              }
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x109,0x44,"d1_srvr.c",uVar13);
              val = (undefined1 *)0x0;
            }
            else {
LAB_0049a8a8:
              val = (undefined1 *)dtls1_do_write(param_1,0x16);
              if (0 < (int)val) {
                psVar9 = param_1->s3;
                if (param_1->tlsext_status_type == 0) {
                  param_1->init_num = 0;
                  bVar2 = false;
                  param_1->state = 0x2150;
                }
                else {
                  param_1->init_num = 0;
                  bVar2 = false;
                  param_1->state = 0x2200;
                }
                goto LAB_0049a4ec;
              }
            }
            goto LAB_00499fc0;
          }
          if (iVar23 == 0x2122) {
            psVar9 = param_1->s3;
            param_1->state = 3;
            goto LAB_0049a0f8;
          }
          if (iVar23 - 0x2130U < 2) {
            param_1->tlsext_hb_seq = 2;
            dtls1_start_timer(param_1);
            val = (undefined1 *)dtls1_send_server_hello(param_1);
            if (0 < (int)val) {
              if (param_1->hit != 0) goto LAB_0049a084;
              param_1->init_num = 0;
              param_1->state = 0x2140;
              psVar9 = param_1->s3;
              goto LAB_0049a0f8;
            }
            goto LAB_00499fc0;
          }
        }
        else if (0x214f < iVar23) {
          if (iVar23 < 0x2152) {
            psVar9 = param_1->s3;
            pSVar15 = (psVar9->tmp).new_cipher;
            uVar7 = pSVar15->algorithm_mkey;
            (psVar9->tmp).use_rsa_tmp = 0;
            if ((((uVar7 & 0x100) == 0) || (*(int *)(param_1->psk_server_callback + 0x14c) == 0)) &&
               ((uVar7 & 0x88) == 0)) {
              bVar2 = true;
              if ((uVar7 & 1) != 0) {
                if (*(int *)(param_1->cert + 0x34) == 0) goto LAB_0049a4c0;
                bVar2 = true;
                if ((pSVar15->algo_strength & 2) != 0) {
                  iVar16 = (*(code *)PTR_EVP_PKEY_size_006a74f8)();
                  psVar9 = param_1->s3;
                  iVar10 = 0x200;
                  if ((((psVar9->tmp).new_cipher)->algo_strength & 8) == 0) {
                    iVar10 = 0x400;
                  }
                  if (iVar10 < iVar16 << 3) goto LAB_0049a4c0;
                  bVar2 = true;
                }
              }
            }
            else {
LAB_0049a4c0:
              dtls1_start_timer(param_1);
              val = (undefined1 *)dtls1_send_server_key_exchange(param_1);
              if ((int)val < 1) goto LAB_00499fc0;
              psVar9 = param_1->s3;
              bVar2 = false;
            }
            param_1->init_num = 0;
            param_1->state = 0x2160;
            goto LAB_0049a4ec;
          }
          if (iVar23 - 0x2160U < 2) {
            uVar7 = param_1->verify_mode;
            if (((uVar7 & 1) == 0) ||
               ((*(int *)(param_1->session->krb5_client_princ + 0xc) != 0 && ((uVar7 & 4) != 0)))) {
              psVar9 = param_1->s3;
            }
            else {
              psVar9 = param_1->s3;
              pSVar15 = (psVar9->tmp).new_cipher;
              uVar17 = pSVar15->algorithm_auth;
              if ((((uVar17 & 4) == 0) || ((uVar7 & 2) != 0)) &&
                 (((uVar17 & 0x20) == 0 && ((pSVar15->algorithm_mkey & 0x100) == 0)))) {
                (psVar9->tmp).cert_request = 1;
                dtls1_start_timer(param_1);
                val = (undefined1 *)dtls1_send_certificate_request(param_1);
                if (0 < (int)val) {
                  psVar9 = param_1->s3;
                  param_1->init_num = 0;
                  param_1->state = 0x2170;
                  goto LAB_0049a0f8;
                }
                goto LAB_00499fc0;
              }
            }
            (psVar9->tmp).cert_request = 0;
            iVar23 = 0x2170;
            param_1->state = 0x2170;
            goto LAB_0049a7e8;
          }
        }
        goto LAB_0049a540;
      }
      if (iVar23 < 0x2120) {
        if (iVar23 == 0x2100) {
          param_1->rwstate = 2;
          iVar16 = (*(code *)puVar3)(param_1->wbio,0xb,0,0);
          if (0 < iVar16) {
            psVar9 = param_1->s3;
            param_1->rwstate = 1;
            param_1->state = (psVar9->tmp).next_state;
            goto LAB_0049a0f8;
          }
          iVar16 = (*(code *)PTR_BIO_test_flags_006a7868)(param_1->wbio,8);
          if (iVar16 == 0) {
            val = (undefined1 *)0xffffffff;
            param_1->rwstate = 1;
            param_1->state = (param_1->s3->tmp).next_state;
          }
          else {
            val = (undefined1 *)0xffffffff;
          }
        }
        else if (iVar23 < 0x2101) {
          if (iVar23 == 0x2000) goto LAB_0049a2e0;
          if (iVar23 == 0x2003) goto LAB_0049a2e0;
          if (iVar23 != 3) goto LAB_0049a540;
          ssl3_cleanup_key_block(param_1);
          ssl_free_wbio_buffer(param_1);
          param_1->init_num = 0;
          if (param_1->tlsext_hb_seq == 2) {
            param_1->tlsext_hb_seq = 0;
            param_1->new_session = 0;
            ssl_update_cache(param_1,2);
            *(int *)(param_1->psk_server_callback + 0x48) =
                 *(int *)(param_1->psk_server_callback + 0x48) + 1;
            param_1->handshake_func = dtls1_accept;
            if (p_Var20 != (_func_3152 *)0x0) {
              (*p_Var20)(param_1,0x20,1);
            }
          }
          pdVar14 = param_1->d1;
          pdVar14->handshake_read_seq = 0;
          pdVar14->handshake_write_seq = 0;
          pdVar14->next_handshake_write_seq = 0;
          dtls1_clear_received_buffer(param_1);
          val = (undefined1 *)0x1;
        }
        else if (iVar23 < 0x2110) {
LAB_0049a540:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf6,0xff,"d1_srvr.c",0x36b);
          val = (undefined1 *)0xffffffff;
        }
        else if (iVar23 < 0x2113) {
          param_1->shutdown = 0;
          val = (undefined1 *)(*(code *)puVar4)(param_1);
          if (0 < (int)val) {
            dtls1_stop_timer(param_1);
            if ((val == (undefined1 *)0x1) &&
               (uVar7 = SSL_ctrl(param_1,0x20,0,(void *)0x0), (uVar7 & 0x2000) != 0)) {
              iVar16 = 0x2113;
            }
            else {
              iVar16 = 0x2130;
            }
            param_1->state = iVar16;
            param_1->init_num = 0;
            if (uVar21 == 0) {
              if ((param_1->s3->tmp).reuse_message == 0) goto LAB_00499ee0;
              goto LAB_00499dac;
            }
            psVar9 = param_1->s3;
            uVar17 = *(uint *)psVar9->read_sequence;
            uVar13 = *(undefined4 *)(psVar9->read_sequence + 4);
            uVar7 = (uint)psVar9->write_sequence & 3;
            puVar1 = psVar9->write_sequence + -uVar7;
            *(uint *)puVar1 = *(uint *)puVar1 & -1 << (4 - uVar7) * 8 | uVar17 >> uVar7 * 8;
            puVar1 = psVar9->write_sequence + 3;
            uVar7 = (uint)puVar1 & 3;
            *(uint *)(puVar1 + -uVar7) =
                 *(uint *)(puVar1 + -uVar7) & 0xffffffffU >> (uVar7 + 1) * 8 |
                 uVar17 << (3 - uVar7) * 8;
            *(undefined4 *)(psVar9->write_sequence + 4) = uVar13;
            if (param_1->state != 0x2130) {
              psVar9 = param_1->s3;
              goto LAB_0049a0f8;
            }
            pdVar14 = param_1->d1;
            val = (undefined1 *)0x2;
            pdVar14->mtu = 0;
            pdVar14->handshake_read_seq = 2;
            pdVar14->handshake_write_seq = 1;
            pdVar14->next_handshake_write_seq = 1;
          }
        }
        else {
          if (0x2114 < iVar23) goto LAB_0049a540;
          if (iVar23 == 0x2113) {
            pcVar19 = param_1->init_buf->data;
            pcVar19[0xc] = (char)((uint)param_1->version >> 8);
            pcVar19[0xd] = (char)param_1->version;
            if ((*(code **)(param_1->psk_server_callback + 0x78) == (code *)0x0) ||
               (iVar16 = (**(code **)(param_1->psk_server_callback + 0x78))
                                   (param_1,param_1->d1->cookie,&param_1->d1->cookie_len),
               puVar3 = PTR_memcpy_006a9aec, iVar16 == 0)) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x108,0x44,"d1_srvr.c",0x3b9);
              val = (undefined1 *)0x0;
              param_1->state = 5;
              goto LAB_00499fc0;
            }
            pcVar19[0xe] = (char)param_1->d1->cookie_len;
            iVar16 = (*(code *)puVar3)(pcVar19 + 0xf,param_1->d1->cookie,param_1->d1->cookie_len);
            iVar16 = iVar16 + param_1->d1->cookie_len;
            iVar10 = iVar16 - (int)(pcVar19 + 0xc);
            dtls1_set_message_header(param_1,pcVar19,3,iVar10,0,iVar10);
            param_1->init_off = 0;
            param_1->state = 0x2114;
            param_1->init_num = iVar16 - (int)pcVar19;
          }
          val = (undefined1 *)dtls1_do_write(param_1,0x16);
          if (0 < (int)val) {
            psVar9 = param_1->s3;
            iVar16 = param_1->version;
            param_1->state = 0x2100;
            (psVar9->tmp).next_state = 0x2110;
            if (iVar16 == 0x100) goto LAB_0049a0f8;
            ssl3_init_finished_mac(param_1);
            iVar16 = (param_1->s3->tmp).reuse_message;
            goto joined_r0x00499e58;
          }
        }
      }
      else {
        param_1->shutdown = 0;
        dtls1_clear_sent_buffer(param_1);
        dtls1_start_timer(param_1);
        if (param_1->state == 0x2120) {
          dtls1_set_message_header(param_1,param_1->init_buf->data,0,0,0,0);
          param_1->init_off = 0;
          param_1->state = 0x2121;
          param_1->init_num = 0xc;
        }
        val = (undefined1 *)dtls1_do_write(param_1,0x16);
        if (0 < (int)val) {
          (param_1->s3->tmp).next_state = 0x2110;
          param_1->init_num = 0;
          param_1->state = 0x2100;
          ssl3_init_finished_mac(param_1);
          psVar9 = param_1->s3;
          goto LAB_0049a0f8;
        }
      }
    }
    else {
LAB_0049a7e8:
      dtls1_start_timer(param_1);
      if (param_1->state == 0x2170) {
        dtls1_set_message_header(param_1,param_1->init_buf->data,0xe,0,0,0);
        param_1->init_off = 0;
        param_1->state = 0x2171;
        param_1->init_num = 0xc;
        dtls1_buffer_message(param_1,0);
      }
      val = (undefined1 *)dtls1_do_write(param_1,0x16);
      if (0 < (int)val) {
        psVar9 = param_1->s3;
        (psVar9->tmp).next_state = 0x2180;
        param_1->init_num = 0;
        param_1->state = 0x2100;
        goto LAB_0049a0f8;
      }
    }
LAB_00499fc0:
    iVar16 = param_1->in_handshake;
LAB_00499fc4:
    param_1->in_handshake = iVar16 + -1;
    if (p_Var20 != (_func_3152 *)0x0) {
      (*p_Var20)(param_1,0x2002,(int)val);
    }
  }
  if (local_2c == *(int *)puVar5) {
    return val;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((local_2c != 0xfeff) && (local_2c != 0x100)) {
    return (undefined1 *)0x0;
  }
  return DTLSv1_client_method_data_15875;
code_r0x00499ebc:
  psVar9 = param_1->s3;
  if ((psVar9->tmp).cert_request != 0) {
    val = (undefined1 *)ssl3_get_client_certificate(param_1);
    if ((int)val < 1) goto LAB_00499fc0;
    psVar9 = param_1->s3;
  }
  iVar16 = (psVar9->tmp).reuse_message;
  param_1->init_num = 0;
  param_1->state = 0x2190;
joined_r0x00499e58:
  if (iVar16 == 0) goto LAB_00499ee0;
  goto LAB_00499e60;
}

