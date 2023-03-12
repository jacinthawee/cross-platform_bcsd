
uint ssl3_accept(SSL *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  EVP_MD *pEVar6;
  int iVar7;
  BUF_MEM *str;
  SSL_CIPHER *pSVar8;
  uint uVar9;
  EVP_MD_CTX *ctx;
  ssl3_enc_method *psVar10;
  char *pcVar11;
  BIO *pBVar12;
  ssl3_state_st *psVar13;
  code *pcVar14;
  _func_3152 *p_Var15;
  int iVar16;
  undefined4 in_stack_ffffffc0;
  undefined4 in_stack_ffffffc4;
  time_t local_30;
  int local_2c [2];
  
  local_30 = time((time_t *)0x0);
  RAND_add(&local_30,4,(double)CONCAT44(in_stack_ffffffc4,in_stack_ffffffc0));
  ERR_clear_error();
  piVar1 = __errno_location();
  p_Var15 = param_1->info_callback;
  *piVar1 = 0;
  if (p_Var15 == (_func_3152 *)0x0) {
    p_Var15 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar2 = SSL_state(param_1);
  if (((uVar2 & 0x3000) == 0) || (iVar3 = SSL_state(param_1), iVar3 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  if (param_1->cert == (cert_st *)0x0) {
    ERR_put_error(0x14,0x80,0xb3,"s3_srvr.c",0xeb);
    return 0xffffffff;
  }
  if (param_1->tlsext_heartbeat != 0) {
    param_1->tlsext_heartbeat = 0;
    param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
  }
  iVar3 = param_1->state;
LAB_000471f2:
  if (0x2181 < iVar3) goto LAB_0004727e;
LAB_000471fc:
  if (0x217f < iVar3) {
    uVar2 = ssl3_check_client_hello(param_1);
    if (0 < (int)uVar2) {
      if (uVar2 == 2) {
        psVar13 = param_1->s3;
        param_1->state = 0x2112;
        uVar9 = 0;
LAB_0004726c:
        do {
          uVar9 = uVar9 | (psVar13->tmp).reuse_message;
          iVar5 = iVar3;
          while( true ) {
            if (uVar9 == 0) {
              if ((param_1->ctx != (SSL_CTX *)0x0) &&
                 (uVar2 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0), (int)uVar2 < 1))
              goto LAB_000475f2;
              if (p_Var15 == (_func_3152 *)0x0) {
                iVar3 = param_1->state;
              }
              else {
                iVar3 = param_1->state;
                if (iVar5 != iVar3) {
                  param_1->state = iVar5;
                  (*p_Var15)(param_1,0x2001,1);
                  param_1->state = iVar3;
                }
              }
              goto LAB_000471f2;
            }
            iVar3 = param_1->state;
            if (iVar3 < 0x2182) goto LAB_000471fc;
LAB_0004727e:
            if (0x21e1 < iVar3) {
              if (0x2211 < iVar3) {
                if ((iVar3 == 0x4000) || (iVar3 == 0x6000)) goto LAB_00047548;
                if (iVar3 == 0x3004) goto code_r0x00047542;
                goto LAB_0004772a;
              }
              if (iVar3 < 0x2210) {
                if (iVar3 < 0x21f0) goto LAB_0004772a;
                if (iVar3 < 0x21f2) {
                  uVar2 = ssl3_send_newsession_ticket(param_1);
                  if ((int)uVar2 < 1) goto LAB_000475f2;
                  param_1->init_num = 0;
                  psVar13 = param_1->s3;
                  uVar9 = 0;
                  param_1->state = 0x21d0;
                }
                else {
                  if (1 < iVar3 - 0x2200U) goto LAB_0004772a;
                  uVar2 = ssl3_send_cert_status(param_1);
                  if ((int)uVar2 < 1) goto LAB_000475f2;
                  param_1->init_num = 0;
                  psVar13 = param_1->s3;
                  uVar9 = 0;
                  param_1->state = 0x2150;
                }
              }
              else {
                psVar13 = param_1->s3;
                if (psVar13->change_cipher_spec == 0) {
                  psVar13->flags = psVar13->flags | 0x80;
                }
                uVar2 = ssl3_get_next_proto(param_1);
                if ((int)uVar2 < 1) goto LAB_000475f2;
                param_1->init_num = 0;
                psVar13 = param_1->s3;
                uVar9 = 0;
                param_1->state = 0x21c0;
              }
              goto LAB_0004726c;
            }
            if (0x21df < iVar3) {
              psVar10 = param_1->method->ssl3_enc;
              uVar2 = ssl3_send_finished(param_1,0x21e0,0x21e1,*(undefined4 *)(psVar10 + 0x28),
                                         *(undefined4 *)(psVar10 + 0x2c));
              if ((int)uVar2 < 1) goto LAB_000475f2;
              param_1->state = 0x2100;
              if (param_1->hit == 0) {
                psVar13 = param_1->s3;
                (psVar13->tmp).next_state = 3;
              }
              else {
                psVar13 = param_1->s3;
                if (psVar13->next_proto_neg_seen == 0) {
                  (psVar13->tmp).next_state = 0x21c0;
                }
                else {
                  (psVar13->tmp).next_state = 0x2210;
                }
              }
              param_1->init_num = 0;
              uVar9 = 0;
              goto LAB_0004726c;
            }
            if (0x21a1 < iVar3) break;
            if (0x219f < iVar3) {
              uVar2 = ssl3_get_cert_verify(param_1);
              if ((int)uVar2 < 1) goto LAB_000475f2;
LAB_00047754:
              psVar13 = param_1->s3;
              iVar16 = 0x2210;
              uVar9 = 0;
              iVar5 = psVar13->next_proto_neg_seen;
              param_1->init_num = 0;
              if (iVar5 == 0) {
                iVar16 = 0x21c0;
              }
              param_1->state = iVar16;
              goto LAB_0004726c;
            }
            if (1 < iVar3 - 0x2190U) goto LAB_0004772a;
            uVar2 = ssl3_get_client_key_exchange(param_1);
            if ((int)uVar2 < 1) goto LAB_000475f2;
            if (uVar2 == 2) goto LAB_00047754;
            if ((param_1->version >> 8 == 3) && (0x302 < param_1->version)) goto code_r0x000479b2;
            psVar13 = param_1->s3;
            param_1->state = 0x21a0;
            param_1->init_num = 0;
            if (psVar13->handshake_buffer != (BIO *)0x0) {
              iVar5 = ssl3_digest_cached_records(param_1);
              if (iVar5 == 0) goto LAB_000479e8;
              psVar13 = param_1->s3;
            }
            iVar16 = 0;
            iVar5 = 0;
            do {
              ctx = *(EVP_MD_CTX **)((int)psVar13->handshake_dgst + iVar16);
              if (ctx != (EVP_MD_CTX *)0x0) {
                pcVar14 = *(code **)(param_1->method->ssl3_enc + 0x1c);
                pEVar6 = EVP_MD_CTX_md(ctx);
                iVar7 = EVP_MD_type(pEVar6);
                (*pcVar14)(param_1,iVar7,(param_1->s3->tmp).cert_verify_md + iVar5);
                pEVar6 = EVP_MD_CTX_md(*(EVP_MD_CTX **)((int)param_1->s3->handshake_dgst + iVar16));
                iVar7 = EVP_MD_size(pEVar6);
                iVar5 = iVar5 + iVar7;
                if (iVar7 < 0) goto LAB_00047990;
                psVar13 = param_1->s3;
              }
              iVar16 = iVar16 + 4;
            } while (iVar16 != 0x18);
            uVar9 = (psVar13->tmp).reuse_message;
            iVar5 = iVar3;
          }
          if (iVar3 < 0x21c0) goto LAB_0004772a;
          if (0x21c1 < iVar3) {
            if (1 < iVar3 - 0x21d0U) goto LAB_0004772a;
            psVar10 = param_1->method->ssl3_enc;
            *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24) =
                 (param_1->s3->tmp).new_cipher;
            iVar5 = (**(code **)(psVar10 + 8))(param_1);
            if (iVar5 == 0) goto LAB_00047990;
            uVar2 = ssl3_send_change_cipher_spec(param_1,0x21d0,0x21d1);
            if ((int)uVar2 < 1) goto LAB_000475f2;
            param_1->state = 0x21e0;
            param_1->init_num = 0;
            iVar5 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x22);
            if (iVar5 != 0) goto LAB_00047492;
            goto LAB_00047990;
          }
          psVar13 = param_1->s3;
          if (psVar13->change_cipher_spec == 0) {
            psVar13->flags = psVar13->flags | 0x80;
          }
          uVar2 = ssl3_get_finished(param_1,0x21c0,0x21c1);
          if ((int)uVar2 < 1) goto LAB_000475f2;
          if (param_1->hit == 0) {
LAB_00047718:
            if (param_1->tlsext_ocsp_resplen == 0) {
              param_1->state = 0x21d0;
            }
            else {
              param_1->state = 0x21f0;
            }
          }
          else {
            param_1->state = 3;
          }
LAB_0004769c:
          param_1->init_num = 0;
          uVar9 = 0;
          psVar13 = param_1->s3;
        } while( true );
      }
      psVar13 = param_1->s3;
      if ((psVar13->tmp).cert_request != 0) {
        uVar2 = ssl3_get_client_certificate(param_1);
        if ((int)uVar2 < 1) goto LAB_000475f2;
        psVar13 = param_1->s3;
      }
      param_1->init_num = 0;
      uVar9 = 0;
      param_1->state = 0x2190;
      goto LAB_0004726c;
    }
    goto LAB_000475f2;
  }
  if (0x2131 < iVar3) {
    if (iVar3 < 0x2152) {
      if (0x214f < iVar3) {
        psVar13 = param_1->s3;
        pSVar8 = (psVar13->tmp).new_cipher;
        uVar2 = pSVar8->algorithm_mkey;
        (psVar13->tmp).use_rsa_tmp = 0;
        if ((((int)(uVar2 << 0x17) < 0) && (*(int *)(param_1->psk_server_callback + 0x14c) != 0)) ||
           ((uVar2 & 0x48e) != 0)) {
LAB_00047876:
          uVar2 = ssl3_send_server_key_exchange(param_1);
          if ((int)uVar2 < 1) goto LAB_000475f2;
          psVar13 = param_1->s3;
          uVar9 = 0;
        }
        else {
          if ((int)(uVar2 << 0x1f) < 0) {
            if (*(EVP_PKEY **)(param_1->cert + 0x34) == (EVP_PKEY *)0x0) goto LAB_00047876;
            if ((int)(pSVar8->algo_strength << 0x1e) < 0) {
              iVar5 = EVP_PKEY_size(*(EVP_PKEY **)(param_1->cert + 0x34));
              psVar13 = param_1->s3;
              if ((((psVar13->tmp).new_cipher)->algo_strength & 8) == 0) {
                iVar16 = 0x400;
              }
              else {
                iVar16 = 0x200;
              }
              if (iVar16 + iVar5 * -8 < 0 != SBORROW4(iVar16,iVar5 * 8)) goto LAB_00047876;
            }
          }
          uVar9 = 1;
        }
        param_1->init_num = 0;
        param_1->state = 0x2160;
        goto LAB_0004726c;
      }
      if (iVar3 - 0x2140U < 2) {
        psVar13 = param_1->s3;
        pSVar8 = (psVar13->tmp).new_cipher;
        if (((pSVar8->algorithm_auth & 0x424) != 0) || ((int)(pSVar8->algorithm_mkey << 0x17) < 0))
        {
          uVar9 = 1;
          param_1->state = 0x2150;
LAB_00047700:
          param_1->init_num = 0;
          goto LAB_0004726c;
        }
        if (iVar3 == 0x2140) {
          iVar5 = ssl_get_server_send_cert(param_1);
          if ((iVar5 == 0) &&
             ((pSVar8 = (param_1->s3->tmp).new_cipher, pSVar8->algorithm_auth != 0x20 ||
              ((int)(pSVar8->algorithm_mkey << 0x1b) < 0)))) {
            iVar3 = 0xd1b;
          }
          else {
            iVar5 = ssl3_output_cert_chain(param_1,iVar5);
            if (iVar5 != 0) {
              param_1->init_num = iVar5;
              param_1->init_off = 0;
              param_1->state = 0x2141;
              goto LAB_00047406;
            }
            iVar3 = 0xd23;
          }
          uVar2 = 0;
          ERR_put_error(0x14,0x9a,0x44,"s3_srvr.c",iVar3);
          param_1->state = 5;
        }
        else {
LAB_00047406:
          uVar2 = ssl3_do_write(param_1,0x16);
          if (0 < (int)uVar2) {
            uVar9 = param_1->tlsext_status_type;
            if (uVar9 == 0) {
              psVar13 = param_1->s3;
              param_1->state = 0x2150;
            }
            else {
              psVar13 = param_1->s3;
              param_1->state = 0x2200;
              uVar9 = 0;
            }
            goto LAB_00047700;
          }
        }
        goto LAB_000475f2;
      }
    }
    else if (0x215f < iVar3) {
      if (iVar3 < 0x2162) {
        iVar5 = param_1->verify_mode;
        if ((iVar5 << 0x1f < 0) &&
           ((*(int *)(param_1->session->krb5_client_princ + 0xc) == 0 || (-1 < iVar5 << 0x1d)))) {
          psVar13 = param_1->s3;
          pSVar8 = (psVar13->tmp).new_cipher;
          if ((((-1 < (int)(pSVar8->algorithm_auth << 0x1d)) || (iVar5 << 0x1e < 0)) &&
              ((pSVar8->algorithm_auth & 0x420) == 0)) &&
             (uVar9 = pSVar8->algorithm_mkey & 0x100, uVar9 == 0)) {
            (psVar13->tmp).cert_request = 1;
            uVar2 = ssl3_send_certificate_request(param_1);
            if (0 < (int)uVar2) {
              psVar13 = param_1->s3;
              param_1->state = 0x2100;
              (psVar13->tmp).next_state = 0x2180;
              param_1->init_num = 0;
              goto LAB_0004726c;
            }
            goto LAB_000475f2;
          }
        }
        else {
          psVar13 = param_1->s3;
        }
        pBVar12 = psVar13->handshake_buffer;
        (psVar13->tmp).cert_request = 0;
        param_1->state = 0x2170;
        if (pBVar12 == (BIO *)0x0) {
          uVar9 = 1;
        }
        else {
          iVar5 = ssl3_digest_cached_records(param_1);
          if (iVar5 == 0) {
LAB_000479e8:
            param_1->state = 5;
            return 0xffffffff;
          }
          psVar13 = param_1->s3;
          uVar9 = 1;
        }
        goto LAB_0004726c;
      }
      if (iVar3 - 0x2170U < 2) {
        if (iVar3 == 0x2170) {
          pcVar11 = param_1->init_buf->data;
          pcVar11[1] = '\0';
          pcVar11[2] = '\0';
          pcVar11[3] = '\0';
          *pcVar11 = '\x0e';
          param_1->init_off = 0;
          param_1->state = 0x2171;
          param_1->init_num = 4;
        }
        uVar2 = ssl3_do_write(param_1,0x16);
        if (0 < (int)uVar2) {
          psVar13 = param_1->s3;
          uVar9 = 0;
          (psVar13->tmp).next_state = 0x2180;
          param_1->init_num = 0;
          param_1->state = 0x2100;
          goto LAB_0004726c;
        }
        goto LAB_000475f2;
      }
    }
    goto LAB_0004772a;
  }
  if (iVar3 < 0x2130) {
    if (0x2112 < iVar3) {
      if (0x211f < iVar3) {
        if (iVar3 < 0x2122) {
          param_1->shutdown = 0;
          if (iVar3 == 0x2120) {
            pcVar11 = param_1->init_buf->data;
            *pcVar11 = '\0';
            pcVar11[1] = '\0';
            pcVar11[2] = '\0';
            pcVar11[3] = '\0';
            param_1->state = 0x2121;
            param_1->init_off = 0;
            param_1->init_num = 4;
          }
          uVar2 = ssl3_do_write(param_1,0x16);
          if (0 < (int)uVar2) {
            (param_1->s3->tmp).next_state = 0x2122;
            param_1->state = 0x2100;
            param_1->init_num = 0;
            ssl3_init_finished_mac(param_1);
            psVar13 = param_1->s3;
            uVar9 = 0;
            goto LAB_0004726c;
          }
          goto LAB_000475f2;
        }
        if (iVar3 == 0x2122) {
          psVar13 = param_1->s3;
          param_1->state = 3;
          uVar9 = 0;
          goto LAB_0004726c;
        }
      }
      goto LAB_0004772a;
    }
    if (iVar3 < 0x2110) {
      if (iVar3 == 0x2000) goto LAB_00047548;
      if (iVar3 < 0x2001) {
        if (iVar3 != 3) goto LAB_0004772a;
        ssl3_cleanup_key_block(param_1);
        BUF_MEM_free(param_1->init_buf);
        param_1->init_buf = (BUF_MEM *)0x0;
        ssl_free_wbio_buffer(param_1);
        param_1->init_num = 0;
        if (param_1->tlsext_hb_seq == 2) {
          param_1->tlsext_hb_seq = 0;
          param_1->new_session = 0;
          ssl_update_cache(param_1,2);
          *(int *)(param_1->psk_server_callback + 0x48) =
               *(int *)(param_1->psk_server_callback + 0x48) + 1;
          param_1->handshake_func = ssl3_accept;
          if (p_Var15 == (_func_3152 *)0x0) {
            param_1->in_handshake = param_1->in_handshake + -1;
            return 1;
          }
          uVar2 = 1;
          (*p_Var15)(param_1,0x20,1);
          param_1->in_handshake = param_1->in_handshake + -1;
          goto LAB_00047600;
        }
        uVar2 = 1;
      }
      else {
        if (iVar3 == 0x2003) goto LAB_00047548;
        if (iVar3 == 0x2100) {
          param_1->rwstate = 2;
          lVar4 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
          if (0 < lVar4) {
            psVar13 = param_1->s3;
            param_1->rwstate = 1;
            uVar9 = 0;
            param_1->state = (psVar13->tmp).next_state;
            goto LAB_0004726c;
          }
          uVar2 = 0xffffffff;
        }
        else {
LAB_0004772a:
          uVar2 = 0xffffffff;
          ERR_put_error(0x14,0x80,0xff,"s3_srvr.c",0x364);
        }
      }
    }
    else {
      param_1->shutdown = 0;
      if ((param_1->rwstate != 4) && (uVar2 = ssl3_get_client_hello(param_1), (int)uVar2 < 1))
      goto LAB_000475f2;
      psVar13 = param_1->s3;
      local_2c[0] = 0x70;
      uVar2 = ((psVar13->tmp).new_cipher)->algorithm_mkey & 0x400;
      if ((uVar2 == 0) || (uVar2 = param_1[1].version, uVar2 == 0)) {
LAB_000477b8:
        param_1->tlsext_hb_seq = 2;
        uVar9 = 0;
        param_1->init_num = uVar2;
        param_1->state = 0x2130;
        goto LAB_0004726c;
      }
      if (param_1[1].rbio == (BIO *)0x0) {
        local_2c[0] = 0x73;
      }
      else {
        uVar2 = SSL_srp_server_param_with_username(param_1,local_2c);
        if ((int)uVar2 < 0) {
          param_1->rwstate = 4;
          goto LAB_000475f2;
        }
        if (uVar2 == 0) {
          psVar13 = param_1->s3;
          goto LAB_000477b8;
        }
      }
      ssl3_send_alert(param_1,2,local_2c[0]);
      if (local_2c[0] != 0x73) {
        ERR_put_error(0x14,0x80,0xe2,"s3_srvr.c",0x181);
      }
LAB_00047990:
      uVar2 = 0xffffffff;
      param_1->state = 5;
    }
  }
  else {
    uVar2 = ssl3_send_server_hello(param_1);
    if (0 < (int)uVar2) {
      if (param_1->hit != 0) goto LAB_00047718;
      param_1->state = 0x2140;
      goto LAB_0004769c;
    }
  }
LAB_000475f2:
  param_1->in_handshake = param_1->in_handshake + -1;
  if (p_Var15 == (_func_3152 *)0x0) {
    return uVar2;
  }
LAB_00047600:
  (*p_Var15)(param_1,0x2002,uVar2);
  return uVar2;
code_r0x00047542:
  param_1->tlsext_hb_seq = 1;
LAB_00047548:
  param_1->server = 1;
  if (p_Var15 != (_func_3152 *)0x0) {
    (*p_Var15)(param_1,0x10,1);
  }
  if (param_1->version >> 8 == 3) {
    param_1->type = 0x2000;
    if (param_1->init_buf == (BUF_MEM *)0x0) {
      str = BUF_MEM_new();
      if (str == (BUF_MEM *)0x0) goto LAB_00047990;
      iVar5 = BUF_MEM_grow(str,0x4000);
      if (iVar5 == 0) {
        uVar2 = 0xffffffff;
        BUF_MEM_free(str);
        param_1->state = 5;
        goto LAB_000475f2;
      }
      param_1->init_buf = str;
    }
    iVar5 = ssl3_setup_buffers(param_1);
    if (iVar5 == 0) goto LAB_00047990;
    psVar13 = param_1->s3;
    iVar5 = param_1->state;
    param_1->init_num = 0;
    psVar13->change_cipher_spec = 0;
    psVar13->flags = psVar13->flags & 0xffffff3f;
    if (iVar5 == 0x3004) {
      if ((psVar13->send_connection_binding == 0) && (-1 < param_1->references << 0xd)) {
        uVar2 = 0xffffffff;
        ERR_put_error(0x14,0x80,0x152,"s3_srvr.c",0x145);
        ssl3_send_alert(param_1,2,0x28);
        param_1->state = 5;
        goto LAB_000475f2;
      }
      uVar9 = 0;
      *(int *)(param_1->psk_server_callback + 0x44) =
           *(int *)(param_1->psk_server_callback + 0x44) + 1;
      param_1->state = 0x2120;
    }
    else {
      iVar5 = ssl_init_wbio_buffer(param_1,1);
      if (iVar5 == 0) goto LAB_00047990;
      ssl3_init_finished_mac(param_1);
      psVar13 = param_1->s3;
      param_1->state = 0x2110;
      uVar9 = 0;
      *(int *)(param_1->psk_server_callback + 0x40) =
           *(int *)(param_1->psk_server_callback + 0x40) + 1;
    }
    goto LAB_0004726c;
  }
  iVar3 = 0x10c;
LAB_00047af8:
  ERR_put_error(0x14,0x80,0x44,"s3_srvr.c",iVar3);
  goto LAB_000479e8;
code_r0x000479b2:
  param_1->state = 0x21a0;
  param_1->init_num = 0;
  uVar9 = *(uint *)(param_1->session->krb5_client_princ + 0xc);
  psVar13 = param_1->s3;
  if (uVar9 == 0) goto LAB_0004726c;
  if (psVar13->handshake_buffer != (BIO *)0x0) {
    psVar13->flags = psVar13->flags | 0x20;
    iVar5 = ssl3_digest_cached_records(param_1);
    if (iVar5 == 0) goto LAB_000479e8;
LAB_00047492:
    psVar13 = param_1->s3;
    uVar9 = 0;
    goto LAB_0004726c;
  }
  iVar3 = 0x280;
  goto LAB_00047af8;
}

