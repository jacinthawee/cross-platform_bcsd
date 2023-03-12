
undefined1 * dtls1_accept(SSL *param_1)

{
  uchar *puVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  cert_st *pcVar7;
  undefined1 *val;
  ssl3_state_st *psVar8;
  int iVar9;
  ssl3_enc_method *psVar10;
  BUF_MEM *pBVar11;
  undefined4 uVar12;
  dtls1_state_st *pdVar13;
  SSL_CIPHER *pSVar14;
  int iVar15;
  uint uVar16;
  undefined4 uVar17;
  char *pcVar18;
  _func_3152 *p_Var19;
  uint uVar20;
  code *pcVar21;
  int iVar22;
  undefined4 local_30;
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_30 = (*(code *)PTR_time_006aabe4)(0);
  (*(code *)PTR_RAND_add_006a9020)(&local_30,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
  puVar5 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  p_Var19 = param_1->info_callback;
  *puVar5 = 0;
  if (p_Var19 == (_func_3152 *)0x0) {
    p_Var19 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  uVar20 = param_1->d1->mtu;
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar6 = SSL_state(param_1);
  if (((uVar6 & 0x3000) == 0) || (uVar6 = SSL_state(param_1), (uVar6 & 0x4000) != 0)) {
    SSL_clear(param_1);
  }
  pcVar7 = param_1->cert;
  param_1->d1->mtu = uVar20;
  if (pcVar7 == (cert_st *)0x0) {
    uVar17 = 0xb3;
    uVar12 = 0xb9;
LAB_0049e6a0:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf6,uVar17,"d1_srvr.c",uVar12);
    val = (undefined1 *)0xffffffff;
  }
  else {
    if (param_1->tlsext_heartbeat != 0) {
      dtls1_stop_timer(param_1);
      param_1->tlsext_heartbeat = 0;
      param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
    }
    iVar15 = param_1->state;
LAB_0049d87c:
    iVar22 = iVar15;
    if (0x2171 < iVar15) goto LAB_0049d940;
LAB_0049d88c:
    puVar3 = PTR_BIO_ctrl_006a7f18;
    if (iVar22 < 0x2170) {
      if (iVar22 < 0x2122) {
        if (iVar22 < 0x2120) {
          if (iVar22 == 0x2100) {
            param_1->rwstate = 2;
            iVar15 = (*(code *)puVar3)(param_1->wbio,0xb,0,0);
            if (0 < iVar15) {
              psVar8 = param_1->s3;
              param_1->rwstate = 1;
              param_1->state = (psVar8->tmp).next_state;
              goto LAB_0049dbc4;
            }
            iVar15 = (*(code *)PTR_BIO_test_flags_006a8954)(param_1->wbio,8);
            if (iVar15 == 0) {
              val = (undefined1 *)0xffffffff;
              param_1->rwstate = 1;
              param_1->state = (param_1->s3->tmp).next_state;
            }
            else {
LAB_0049e628:
              val = (undefined1 *)0xffffffff;
            }
          }
          else if (iVar22 < 0x2101) {
            if (iVar22 == 0x2000) goto LAB_0049dd8c;
            if (iVar22 == 0x2003) goto LAB_0049dd8c;
            if (iVar22 != 3) goto LAB_0049e02c;
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
              if (p_Var19 != (_func_3152 *)0x0) {
                (*p_Var19)(param_1,0x20,1);
              }
            }
            pdVar13 = param_1->d1;
            val = (undefined1 *)0x1;
            pdVar13->handshake_read_seq = 0;
            pdVar13->handshake_write_seq = 0;
            pdVar13->next_handshake_write_seq = 0;
          }
          else if (iVar22 < 0x2110) {
LAB_0049e02c:
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf6,0xff,"d1_srvr.c",0x333);
            val = (undefined1 *)0xffffffff;
          }
          else if (iVar22 < 0x2113) {
            param_1->shutdown = 0;
            val = (undefined1 *)ssl3_get_client_hello(param_1);
            if (0 < (int)val) {
              dtls1_stop_timer(param_1);
              if ((val == (undefined1 *)0x1) &&
                 (uVar6 = SSL_ctrl(param_1,0x20,0,(void *)0x0), (uVar6 & 0x2000) != 0)) {
                iVar15 = 0x2113;
              }
              else {
                iVar15 = 0x2130;
              }
              param_1->state = iVar15;
              param_1->init_num = 0;
              if (uVar20 == 0) {
                if ((param_1->s3->tmp).reuse_message == 0) goto LAB_0049d9b4;
                goto LAB_0049d87c;
              }
              psVar8 = param_1->s3;
              uVar16 = *(uint *)psVar8->read_sequence;
              uVar12 = *(undefined4 *)(psVar8->read_sequence + 4);
              uVar6 = (uint)psVar8->write_sequence & 3;
              puVar1 = psVar8->write_sequence + -uVar6;
              *(uint *)puVar1 = *(uint *)puVar1 & -1 << (4 - uVar6) * 8 | uVar16 >> uVar6 * 8;
              puVar1 = psVar8->write_sequence + 3;
              uVar6 = (uint)puVar1 & 3;
              *(uint *)(puVar1 + -uVar6) =
                   *(uint *)(puVar1 + -uVar6) & 0xffffffffU >> (uVar6 + 1) * 8 |
                   uVar16 << (3 - uVar6) * 8;
              *(undefined4 *)(psVar8->write_sequence + 4) = uVar12;
              if (param_1->state != 0x2130) {
                psVar8 = param_1->s3;
                goto LAB_0049dbc4;
              }
              pdVar13 = param_1->d1;
              val = (undefined1 *)0x2;
              pdVar13->mtu = 0;
              pdVar13->handshake_read_seq = 2;
              pdVar13->handshake_write_seq = 1;
              pdVar13->next_handshake_write_seq = 1;
            }
          }
          else {
            if (0x2114 < iVar22) goto LAB_0049e02c;
            if (iVar22 == 0x2113) {
              pcVar18 = param_1->init_buf->data;
              pcVar18[0xc] = (char)((uint)param_1->version >> 8);
              pcVar18[0xd] = (char)param_1->version;
              if ((*(code **)(param_1->psk_server_callback + 0x78) == (code *)0x0) ||
                 (iVar15 = (**(code **)(param_1->psk_server_callback + 0x78))
                                     (param_1,param_1->d1->cookie,&param_1->d1->cookie_len),
                 puVar3 = PTR_memcpy_006aabf4, iVar15 == 0)) {
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x108,0x44,"d1_srvr.c",900);
                val = (undefined1 *)0x0;
                goto LAB_0049da8c;
              }
              pcVar18[0xe] = (char)param_1->d1->cookie_len;
              iVar15 = (*(code *)puVar3)(pcVar18 + 0xf,param_1->d1->cookie,param_1->d1->cookie_len);
              iVar15 = iVar15 + param_1->d1->cookie_len;
              iVar9 = iVar15 - (int)(pcVar18 + 0xc);
              dtls1_set_message_header(param_1,pcVar18,3,iVar9,0,iVar9);
              param_1->init_off = 0;
              param_1->state = 0x2114;
              param_1->init_num = iVar15 - (int)pcVar18;
            }
            val = (undefined1 *)dtls1_do_write(param_1,0x16);
            if (0 < (int)val) {
              psVar8 = param_1->s3;
              iVar15 = param_1->version;
              param_1->state = 0x2100;
              (psVar8->tmp).next_state = 0x2110;
              if (iVar15 != 0x100) {
                ssl3_init_finished_mac(param_1);
                iVar15 = (param_1->s3->tmp).reuse_message;
                goto joined_r0x0049d924;
              }
LAB_0049dbc4:
              do {
                if ((psVar8->tmp).reuse_message == 0) goto LAB_0049d9b4;
                iVar22 = param_1->state;
LAB_0049d930:
                while( true ) {
                  if (iVar22 < 0x2172) goto LAB_0049d88c;
LAB_0049d940:
                  if (0x21d1 < iVar22) {
                    if (0x2201 < iVar22) {
                      if ((iVar22 == 0x4000) || (iVar22 == 0x6000)) goto LAB_0049dd8c;
                      if (iVar22 == 0x3004) goto code_r0x0049dd84;
                      goto LAB_0049e02c;
                    }
                    if (0x21ff < iVar22) {
                      val = (undefined1 *)ssl3_send_cert_status(param_1);
                      if ((int)val < 1) goto LAB_0049da8c;
                      psVar8 = param_1->s3;
                      param_1->init_num = 0;
                      param_1->state = 0x2150;
                      goto LAB_0049dbc4;
                    }
                    if (iVar22 < 0x21e0) goto LAB_0049e02c;
                    if (iVar22 < 0x21e2) {
                      psVar10 = param_1->method->ssl3_enc;
                      val = (undefined1 *)
                            dtls1_send_finished(param_1,0x21e0,0x21e1,
                                                *(undefined4 *)(psVar10 + 0x28),
                                                *(undefined4 *)(psVar10 + 0x2c));
                      if ((int)val < 1) goto LAB_0049da8c;
                      param_1->state = 0x2100;
                      if (param_1->hit == 0) {
                        psVar8 = param_1->s3;
                        (psVar8->tmp).next_state = 3;
                        param_1->init_num = 0;
                      }
                      else {
                        psVar8 = param_1->s3;
                        (psVar8->tmp).next_state = 0x21c0;
                        param_1->init_num = 0;
                      }
                    }
                    else {
                      if (1 < iVar22 - 0x21f0U) goto LAB_0049e02c;
                      val = (undefined1 *)dtls1_send_newsession_ticket(param_1);
                      if ((int)val < 1) goto LAB_0049da8c;
                      psVar8 = param_1->s3;
                      param_1->init_num = 0;
                      param_1->state = 0x21d0;
                    }
                    goto LAB_0049dbc4;
                  }
                  if (0x21cf < iVar22) {
                    pcVar21 = *(code **)(param_1->method->ssl3_enc + 8);
                    *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24) =
                         (param_1->s3->tmp).new_cipher;
                    iVar15 = (*pcVar21)(param_1);
                    if (iVar15 == 0) goto LAB_0049e628;
                    val = (undefined1 *)dtls1_send_change_cipher_spec(param_1,0x21d0,0x21d1);
                    if ((int)val < 1) goto LAB_0049da8c;
                    param_1->init_num = 0;
                    param_1->state = 0x21e0;
                    iVar15 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x22);
                    if (iVar15 == 0) goto LAB_0049e628;
                    dtls1_reset_seq_numbers(param_1,2);
                    psVar8 = param_1->s3;
                    goto LAB_0049dbc4;
                  }
                  if (0x2191 < iVar22) {
                    if (iVar22 < 0x21a0) goto LAB_0049e02c;
                    if (iVar22 < 0x21a2) {
                      param_1->d1->listen = 1;
                      val = (undefined1 *)ssl3_get_cert_verify(param_1);
                      if ((int)val < 1) goto LAB_0049da8c;
                      psVar8 = param_1->s3;
                      param_1->init_num = 0;
                      param_1->state = 0x21c0;
                    }
                    else {
                      if (1 < iVar22 - 0x21c0U) goto LAB_0049e02c;
                      param_1->d1->listen = 1;
                      val = (undefined1 *)ssl3_get_finished(param_1,0x21c0,0x21c1);
                      if ((int)val < 1) goto LAB_0049da8c;
                      dtls1_stop_timer(param_1);
                      if (param_1->hit == 0) {
LAB_0049db50:
                        if (param_1->tlsext_ocsp_resplen == 0) {
                          param_1->init_num = 0;
                          param_1->state = 0x21d0;
                          psVar8 = param_1->s3;
                        }
                        else {
                          param_1->init_num = 0;
                          param_1->state = 0x21f0;
                          psVar8 = param_1->s3;
                        }
                      }
                      else {
                        param_1->init_num = 0;
                        param_1->state = 3;
                        psVar8 = param_1->s3;
                      }
                    }
                    goto LAB_0049dbc4;
                  }
                  if (0x218f < iVar22) {
                    val = (undefined1 *)ssl3_get_client_key_exchange(param_1);
                    if ((int)val < 1) goto LAB_0049da8c;
                    param_1->init_num = 0;
                    param_1->state = 0x21a0;
                    if (val == (undefined1 *)0x2) {
                      psVar8 = param_1->s3;
                      param_1->state = 0x21c0;
                    }
                    else {
                      (**(code **)(param_1->method->ssl3_enc + 0x1c))(param_1,4,&param_1->s3->tmp);
                      (**(code **)(param_1->method->ssl3_enc + 0x1c))
                                (param_1,0x40,(param_1->s3->tmp).cert_verify_md + 0x10);
                      psVar8 = param_1->s3;
                    }
                    goto LAB_0049dbc4;
                  }
                  if (1 < iVar22 - 0x2180U) goto LAB_0049e02c;
                  val = (undefined1 *)ssl3_check_client_hello(param_1);
                  if ((int)val < 1) goto LAB_0049da8c;
                  if (val == (undefined1 *)0x2) break;
                  val = (undefined1 *)ssl3_get_client_certificate(param_1);
                  if ((int)val < 1) goto LAB_0049da8c;
                  param_1->init_num = 0;
                  param_1->state = 0x2190;
                  iVar15 = (param_1->s3->tmp).reuse_message;
joined_r0x0049d924:
                  if (iVar15 == 0) {
LAB_0049d9b4:
                    if ((param_1->ctx != (SSL_CTX *)0x0) &&
                       (val = (undefined1 *)(*(code *)PTR_BIO_ctrl_006a7f18)(param_1->wbio,0xb,0,0),
                       (int)val < 1)) {
                      iVar15 = param_1->in_handshake;
                      goto LAB_0049da90;
                    }
                    if (p_Var19 != (_func_3152 *)0x0) {
                      iVar9 = param_1->state;
                      iVar15 = iVar22;
                      if (iVar9 != iVar22) {
                        param_1->state = iVar22;
                        (*p_Var19)(param_1,0x2001,1);
                        param_1->state = iVar9;
                        iVar15 = iVar9;
                      }
                      goto LAB_0049d87c;
                    }
                  }
LAB_0049d92c:
                  iVar22 = param_1->state;
                }
                dtls1_stop_timer(param_1);
                psVar8 = param_1->s3;
                param_1->state = 0x2112;
              } while( true );
            }
          }
        }
        else {
          param_1->shutdown = 0;
          dtls1_clear_record_buffer(param_1);
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
            psVar8 = param_1->s3;
            goto LAB_0049dbc4;
          }
        }
      }
      else {
        if (0x2141 < iVar22) {
          if (0x214f < iVar22) {
            if (iVar22 < 0x2152) {
              psVar8 = param_1->s3;
              pSVar14 = (psVar8->tmp).new_cipher;
              uVar6 = param_1->references & 0x200000;
              uVar16 = pSVar14->algorithm_mkey;
              (psVar8->tmp).use_rsa_tmp = (uint)(uVar6 != 0);
              if ((uVar6 == 0) &&
                 ((((uVar16 & 0x100) == 0 || (*(int *)(param_1->psk_server_callback + 0x14c) == 0))
                  && ((uVar16 & 0x8e) == 0)))) {
                bVar2 = true;
                if ((uVar16 & 1) != 0) {
                  if (*(int *)(param_1->cert + 0x34) == 0) goto LAB_0049dfd8;
                  bVar2 = true;
                  if ((pSVar14->algo_strength & 2) != 0) {
                    iVar15 = (*(code *)PTR_EVP_PKEY_size_006a85f4)();
                    psVar8 = param_1->s3;
                    iVar9 = 0x200;
                    if ((((psVar8->tmp).new_cipher)->algo_strength & 8) == 0) {
                      iVar9 = 0x400;
                    }
                    if (iVar9 < iVar15 << 3) goto LAB_0049dfd8;
                    bVar2 = true;
                  }
                }
              }
              else {
LAB_0049dfd8:
                dtls1_start_timer(param_1);
                val = (undefined1 *)dtls1_send_server_key_exchange(param_1);
                if ((int)val < 1) goto LAB_0049da8c;
                psVar8 = param_1->s3;
                bVar2 = false;
              }
              param_1->init_num = 0;
              param_1->state = 0x2160;
              goto LAB_0049e0b8;
            }
            if (iVar22 - 0x2160U < 2) {
              uVar6 = param_1->verify_mode;
              if (((uVar6 & 1) == 0) ||
                 ((*(int *)(param_1->session->krb5_client_princ + 0xc) != 0 && ((uVar6 & 4) != 0))))
              {
                psVar8 = param_1->s3;
              }
              else {
                psVar8 = param_1->s3;
                pSVar14 = (psVar8->tmp).new_cipher;
                uVar16 = pSVar14->algorithm_auth;
                if ((((uVar16 & 4) == 0) || ((uVar6 & 2) != 0)) &&
                   (((uVar16 & 0x20) == 0 && ((pSVar14->algorithm_mkey & 0x100) == 0)))) {
                  (psVar8->tmp).cert_request = 1;
                  dtls1_start_timer(param_1);
                  val = (undefined1 *)dtls1_send_certificate_request(param_1);
                  if (0 < (int)val) {
                    psVar8 = param_1->s3;
                    param_1->init_num = 0;
                    param_1->state = 0x2170;
                    goto LAB_0049dbc4;
                  }
                  goto LAB_0049da8c;
                }
              }
              (psVar8->tmp).cert_request = 0;
              iVar22 = 0x2170;
              param_1->state = 0x2170;
              goto LAB_0049e210;
            }
          }
          goto LAB_0049e02c;
        }
        if (0x213f < iVar22) {
          psVar8 = param_1->s3;
          pSVar14 = (psVar8->tmp).new_cipher;
          if (((pSVar14->algorithm_auth & 4) == 0) && ((pSVar14->algorithm_mkey & 0x100) == 0)) {
            dtls1_start_timer(param_1);
            if (param_1->state == 0x2140) {
              iVar15 = ssl_get_server_send_cert(param_1);
              if ((iVar15 == 0) &&
                 ((pSVar14 = (param_1->s3->tmp).new_cipher, pSVar14->algorithm_mkey != 0x10 ||
                  (pSVar14->algorithm_auth != 0x20)))) {
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x109,0x44,"d1_srvr.c",0x63a);
                val = (undefined1 *)0x0;
                goto LAB_0049da8c;
              }
              iVar15 = dtls1_output_cert_chain(param_1,iVar15);
              param_1->init_num = iVar15;
              param_1->init_off = 0;
              param_1->state = 0x2141;
              dtls1_buffer_message(param_1,0);
            }
            val = (undefined1 *)dtls1_do_write(param_1,0x16);
            if ((int)val < 1) goto LAB_0049da8c;
            psVar8 = param_1->s3;
            if (param_1->tlsext_status_type == 0) {
              bVar2 = false;
              param_1->state = 0x2150;
            }
            else {
              bVar2 = false;
              param_1->state = 0x2200;
            }
          }
          else {
            bVar2 = true;
            param_1->state = 0x2150;
          }
          param_1->init_num = 0;
LAB_0049e0b8:
          if ((psVar8->tmp).reuse_message != 0) goto LAB_0049d92c;
          if (!bVar2) goto LAB_0049d9b4;
          iVar22 = param_1->state;
          goto LAB_0049d930;
        }
        if (iVar22 == 0x2122) {
          psVar8 = param_1->s3;
          param_1->state = 3;
          goto LAB_0049dbc4;
        }
        if (1 < iVar22 - 0x2130U) goto LAB_0049e02c;
        param_1->tlsext_hb_seq = 2;
        dtls1_start_timer(param_1);
        val = (undefined1 *)dtls1_send_server_hello(param_1);
        if (0 < (int)val) {
          if (param_1->hit != 0) goto LAB_0049db50;
          param_1->init_num = 0;
          param_1->state = 0x2140;
          psVar8 = param_1->s3;
          goto LAB_0049dbc4;
        }
      }
    }
    else {
LAB_0049e210:
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
        psVar8 = param_1->s3;
        (psVar8->tmp).next_state = 0x2180;
        param_1->init_num = 0;
        param_1->state = 0x2100;
        goto LAB_0049dbc4;
      }
    }
LAB_0049da8c:
    iVar15 = param_1->in_handshake;
LAB_0049da90:
    param_1->in_handshake = iVar15 + -1;
    if (p_Var19 != (_func_3152 *)0x0) {
      (*p_Var19)(param_1,0x2002,(int)val);
    }
  }
  if (local_2c == *(int *)puVar4) {
    return val;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((local_2c != 0xfeff) && (local_2c != 0x100)) {
    return (undefined1 *)0x0;
  }
  return DTLSv1_client_method_data_15845;
code_r0x0049dd84:
  param_1->tlsext_hb_seq = 1;
LAB_0049dd8c:
  param_1->server = 1;
  if (p_Var19 != (_func_3152 *)0x0) {
    (*p_Var19)(param_1,0x10,1);
  }
  if ((param_1->version & 0xff00U) != 0xfe00) {
    uVar17 = 0x44;
    uVar12 = 0xde;
    goto LAB_0049e6a0;
  }
  param_1->type = 0x2000;
  if (param_1->init_buf == (BUF_MEM *)0x0) {
    pBVar11 = (BUF_MEM *)(*(code *)PTR_BUF_MEM_new_006a859c)();
    if ((pBVar11 == (BUF_MEM *)0x0) ||
       (iVar15 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(pBVar11,0x4000), iVar15 == 0))
    goto LAB_0049e628;
    param_1->init_buf = pBVar11;
  }
  iVar15 = ssl3_setup_buffers(param_1);
  if (iVar15 == 0) goto LAB_0049e628;
  param_1->init_num = 0;
  if (param_1->state == 0x3004) {
    psVar8 = param_1->s3;
    *(int *)(param_1->psk_server_callback + 0x44) =
         *(int *)(param_1->psk_server_callback + 0x44) + 1;
    param_1->state = 0x2120;
  }
  else {
    iVar15 = ssl_init_wbio_buffer(param_1,1);
    if (iVar15 == 0) goto LAB_0049e628;
    ssl3_init_finished_mac(param_1);
    psVar8 = param_1->s3;
    param_1->state = 0x2110;
    *(int *)(param_1->psk_server_callback + 0x40) =
         *(int *)(param_1->psk_server_callback + 0x40) + 1;
  }
  goto LAB_0049dbc4;
}

