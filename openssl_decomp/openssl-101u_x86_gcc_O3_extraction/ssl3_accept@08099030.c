
int ssl3_accept(SSL *param_1)

{
  SSL_CIPHER *pSVar1;
  char *pcVar2;
  BIO *pBVar3;
  EVP_MD_CTX *ctx;
  code *pcVar4;
  ssl3_enc_method *psVar5;
  int *piVar6;
  uint uVar7;
  long lVar8;
  int iVar9;
  EVP_MD *pEVar10;
  int iVar11;
  BUF_MEM *str;
  ssl3_state_st *psVar12;
  _func_3152 *p_Var13;
  int iVar14;
  int iVar15;
  int in_GS_OFFSET;
  time_t local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = time((time_t *)0x0);
  RAND_add(&local_28,4,0.0);
  ERR_clear_error();
  piVar6 = __errno_location();
  p_Var13 = param_1->info_callback;
  *piVar6 = 0;
  if (p_Var13 == (_func_3152 *)0x0) {
    p_Var13 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar7 = SSL_state(param_1);
  if (((uVar7 & 0x3000) == 0) || (uVar7 = SSL_state(param_1), (uVar7 & 0x4000) != 0)) {
    SSL_clear(param_1);
  }
  if (param_1->cert == (cert_st *)0x0) {
    ERR_put_error(0x14,0x80,0xb3,"s3_srvr.c",0xeb);
    iVar9 = -1;
LAB_0809931b:
    if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return iVar9;
  }
  if (param_1->tlsext_heartbeat != 0) {
    param_1->tlsext_heartbeat = 0;
    param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
  }
LAB_080990d0:
  iVar14 = param_1->state;
  if (0x2181 < iVar14) goto LAB_080991d0;
LAB_080990df:
  if (0x217f < iVar14) {
    iVar9 = ssl3_check_client_hello(param_1);
    if (0 < iVar9) {
      if (iVar9 == 2) {
        param_1->state = 0x2112;
        psVar12 = param_1->s3;
        uVar7 = 0;
        goto LAB_08099180;
      }
      psVar12 = param_1->s3;
      if ((psVar12->tmp).cert_request != 0) {
        iVar9 = ssl3_get_client_certificate(param_1);
        if (iVar9 < 1) goto LAB_080992f8;
        psVar12 = param_1->s3;
      }
      param_1->init_num = 0;
      param_1->state = 0x2190;
      uVar7 = 0;
      goto LAB_08099180;
    }
    goto LAB_080992f8;
  }
  if (iVar14 < 0x2132) {
    if (0x212f < iVar14) {
      iVar9 = ssl3_send_server_hello(param_1);
      if (0 < iVar9) {
        if (param_1->hit != 0) goto LAB_0809992f;
        param_1->state = 0x2140;
        goto LAB_0809977b;
      }
      goto LAB_080992f8;
    }
    if (0x2112 < iVar14) {
      if (iVar14 < 0x2120) goto LAB_08099a10;
      if (iVar14 < 0x2122) {
        param_1->shutdown = 0;
        if (iVar14 == 0x2120) {
          pcVar2 = param_1->init_buf->data;
          *pcVar2 = '\0';
          pcVar2[1] = '\0';
          pcVar2[2] = '\0';
          pcVar2[3] = '\0';
          param_1->state = 0x2121;
          param_1->init_num = 4;
          param_1->init_off = 0;
        }
        iVar9 = ssl3_do_write(param_1,0x16);
        if (iVar9 < 1) goto LAB_080992f8;
        uVar7 = 0;
        (param_1->s3->tmp).next_state = 0x2122;
        param_1->state = 0x2100;
        param_1->init_num = 0;
        ssl3_init_finished_mac(param_1);
        psVar12 = param_1->s3;
      }
      else {
        if (iVar14 != 0x2122) goto LAB_08099a10;
        param_1->state = 3;
        psVar12 = param_1->s3;
        uVar7 = 0;
      }
      goto LAB_08099180;
    }
    if (iVar14 < 0x2110) {
      if (iVar14 == 0x2000) goto LAB_080995e6;
      if (0x2000 < iVar14) {
        if (iVar14 == 0x2003) goto LAB_080995e6;
        if (iVar14 != 0x2100) goto LAB_08099a10;
        param_1->rwstate = 2;
        lVar8 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
        if (0 < lVar8) {
          psVar12 = param_1->s3;
          param_1->rwstate = 1;
          uVar7 = 0;
          param_1->state = (psVar12->tmp).next_state;
          goto LAB_08099180;
        }
        iVar9 = -1;
        goto LAB_080992f8;
      }
      if (iVar14 != 3) goto LAB_08099a10;
      ssl3_cleanup_key_block(param_1);
      BUF_MEM_free(param_1->init_buf);
      param_1->init_buf = (BUF_MEM *)0x0;
      ssl_free_wbio_buffer(param_1);
      param_1->init_num = 0;
      iVar9 = 1;
      if (param_1->tlsext_hb_seq != 2) goto LAB_080992f8;
      param_1->tlsext_hb_seq = 0;
      param_1->new_session = 0;
      ssl_update_cache(param_1,2);
      *(int *)(param_1->psk_server_callback + 0x48) =
           *(int *)(param_1->psk_server_callback + 0x48) + 1;
      param_1->handshake_func = ssl3_accept;
      if (p_Var13 == (_func_3152 *)0x0) {
        param_1->in_handshake = param_1->in_handshake + -1;
        iVar9 = 1;
        goto LAB_0809931b;
      }
      (*p_Var13)(param_1,0x20,1);
      param_1->in_handshake = param_1->in_handshake + -1;
      iVar9 = 1;
    }
    else {
      param_1->shutdown = 0;
      if ((param_1->rwstate == 4) || (iVar9 = ssl3_get_client_hello(param_1), 0 < iVar9)) {
        psVar12 = param_1->s3;
        local_24 = 0x70;
        if (((*(byte *)((int)&((psVar12->tmp).new_cipher)->algorithm_mkey + 1) & 4) == 0) ||
           (param_1[1].version == 0)) {
LAB_08099b9a:
          param_1->tlsext_hb_seq = 2;
          param_1->state = 0x2130;
          uVar7 = 0;
          param_1->init_num = 0;
          goto LAB_08099180;
        }
        if (param_1[1].rbio == (BIO *)0x0) {
          local_24 = 0x73;
        }
        else {
          iVar9 = SSL_srp_server_param_with_username(param_1,&local_24);
          if (iVar9 < 0) {
            param_1->rwstate = 4;
            goto LAB_080992f8;
          }
          if (iVar9 == 0) {
            psVar12 = param_1->s3;
            goto LAB_08099b9a;
          }
        }
        ssl3_send_alert(param_1,2,local_24);
        if (local_24 != 0x73) {
          ERR_put_error(0x14,0x80,0xe2,"s3_srvr.c",0x181);
        }
LAB_08099dd8:
        param_1->state = 5;
        iVar9 = -1;
      }
LAB_080992f8:
      param_1->in_handshake = param_1->in_handshake + -1;
      if (p_Var13 == (_func_3152 *)0x0) goto LAB_0809931b;
    }
    (*p_Var13)(param_1,0x2002,iVar9);
    goto LAB_0809931b;
  }
  if (0x2151 < iVar14) {
    if (0x215f < iVar14) {
      if (iVar14 < 0x2162) {
        uVar7 = param_1->verify_mode;
        if (((uVar7 & 1) == 0) ||
           ((*(int *)(param_1->session->krb5_client_princ + 0xc) != 0 && ((uVar7 & 4) != 0)))) {
          psVar12 = param_1->s3;
        }
        else {
          psVar12 = param_1->s3;
          pSVar1 = (psVar12->tmp).new_cipher;
          if (((((*(byte *)&pSVar1->algorithm_auth & 4) == 0) || ((uVar7 & 2) != 0)) &&
              ((pSVar1->algorithm_auth & 0x420) == 0)) &&
             ((*(byte *)((int)&pSVar1->algorithm_mkey + 1) & 1) == 0)) {
            (psVar12->tmp).cert_request = 1;
            iVar9 = ssl3_send_certificate_request(param_1);
            if (0 < iVar9) {
              psVar12 = param_1->s3;
              param_1->state = 0x2100;
              uVar7 = 0;
              (psVar12->tmp).next_state = 0x2180;
              param_1->init_num = 0;
              goto LAB_08099180;
            }
            goto LAB_080992f8;
          }
        }
        pBVar3 = psVar12->handshake_buffer;
        (psVar12->tmp).cert_request = 0;
        param_1->state = 0x2170;
        if (pBVar3 == (BIO *)0x0) {
          uVar7 = 1;
          goto LAB_08099180;
        }
        iVar9 = ssl3_digest_cached_records(param_1);
        if (iVar9 == 0) {
LAB_08099291:
          param_1->state = 5;
          iVar9 = -1;
          goto LAB_0809931b;
        }
        psVar12 = param_1->s3;
        uVar7 = 1;
        goto LAB_08099180;
      }
      if (iVar14 - 0x2170U < 2) {
        if (iVar14 == 0x2170) {
          pcVar2 = param_1->init_buf->data;
          *pcVar2 = '\x0e';
          pcVar2[1] = '\0';
          pcVar2[2] = '\0';
          pcVar2[3] = '\0';
          param_1->state = 0x2171;
          param_1->init_num = 4;
          param_1->init_off = 0;
        }
        iVar9 = ssl3_do_write(param_1,0x16);
        if (0 < iVar9) {
          psVar12 = param_1->s3;
          uVar7 = 0;
          (psVar12->tmp).next_state = 0x2180;
          param_1->state = 0x2100;
          param_1->init_num = 0;
          goto LAB_08099180;
        }
        goto LAB_080992f8;
      }
    }
LAB_08099a10:
    ERR_put_error(0x14,0x80,0xff,"s3_srvr.c",0x364);
    iVar9 = -1;
    goto LAB_080992f8;
  }
  if (iVar14 < 0x2150) {
    if (1 < iVar14 - 0x2140U) goto LAB_08099a10;
    psVar12 = param_1->s3;
    pSVar1 = (psVar12->tmp).new_cipher;
    if (((pSVar1->algorithm_auth & 0x424) == 0) &&
       ((*(byte *)((int)&pSVar1->algorithm_mkey + 1) & 1) == 0)) {
      if (iVar14 == 0x2140) {
        iVar9 = ssl_get_server_send_cert(param_1);
        if ((iVar9 == 0) &&
           ((pSVar1 = (param_1->s3->tmp).new_cipher, pSVar1->algorithm_auth != 0x20 ||
            ((*(byte *)&pSVar1->algorithm_mkey & 0x10) != 0)))) {
          iVar9 = 0xd1b;
        }
        else {
          iVar9 = ssl3_output_cert_chain(param_1,iVar9);
          if (iVar9 != 0) {
            param_1->state = 0x2141;
            param_1->init_num = iVar9;
            param_1->init_off = 0;
            goto LAB_08099403;
          }
          iVar9 = 0xd23;
        }
        ERR_put_error(0x14,0x9a,0x44,"s3_srvr.c",iVar9);
        param_1->state = 5;
        iVar9 = 0;
      }
      else {
LAB_08099403:
        iVar9 = ssl3_do_write(param_1,0x16);
        if (0 < iVar9) {
          if (param_1->tlsext_status_type == 0) {
            param_1->state = 0x2150;
            psVar12 = param_1->s3;
            uVar7 = 0;
          }
          else {
            param_1->state = 0x2200;
            psVar12 = param_1->s3;
            uVar7 = 0;
          }
          goto LAB_080998fc;
        }
      }
      goto LAB_080992f8;
    }
    param_1->state = 0x2150;
    uVar7 = 1;
  }
  else {
    psVar12 = param_1->s3;
    pSVar1 = (psVar12->tmp).new_cipher;
    uVar7 = pSVar1->algorithm_mkey;
    (psVar12->tmp).use_rsa_tmp = 0;
    if ((((uVar7 & 0x100) == 0) || (*(int *)(param_1->psk_server_callback + 0x14c) == 0)) &&
       ((uVar7 & 0x48e) == 0)) {
      if ((uVar7 & 1) == 0) {
        uVar7 = 1;
      }
      else {
        if (*(EVP_PKEY **)(param_1->cert + 0x34) == (EVP_PKEY *)0x0) goto LAB_08099c2b;
        uVar7 = 1;
        if ((*(byte *)&pSVar1->algo_strength & 2) != 0) {
          iVar9 = EVP_PKEY_size(*(EVP_PKEY **)(param_1->cert + 0x34));
          psVar12 = param_1->s3;
          if ((int)((-(uint)((((psVar12->tmp).new_cipher)->algo_strength & 8) == 0) & 0x200) + 0x200
                   ) < iVar9 * 8) goto LAB_08099c2b;
        }
      }
    }
    else {
LAB_08099c2b:
      iVar9 = ssl3_send_server_key_exchange(param_1);
      if (iVar9 < 1) goto LAB_080992f8;
      psVar12 = param_1->s3;
      uVar7 = 0;
    }
    param_1->state = 0x2160;
  }
LAB_080998fc:
  param_1->init_num = 0;
LAB_08099180:
  if ((uVar7 | (psVar12->tmp).reuse_message) != 0) goto LAB_080990d0;
  if ((param_1->ctx != (SSL_CTX *)0x0) &&
     (iVar9 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0), iVar9 < 1)) goto LAB_080992f8;
  if (p_Var13 == (_func_3152 *)0x0) {
    iVar9 = param_1->state;
  }
  else {
    iVar9 = param_1->state;
    if (iVar9 != iVar14) {
      param_1->state = iVar14;
      (*p_Var13)(param_1,0x2001,1);
      param_1->state = iVar9;
    }
  }
  iVar14 = iVar9;
  if (iVar14 < 0x2182) goto LAB_080990df;
LAB_080991d0:
  if (iVar14 < 0x21e2) {
    if (0x21df < iVar14) {
      psVar5 = param_1->method->ssl3_enc;
      iVar9 = ssl3_send_finished(param_1,0x21e0,0x21e1,*(undefined4 *)(psVar5 + 0x28),
                                 *(undefined4 *)(psVar5 + 0x2c));
      if (iVar9 < 1) goto LAB_080992f8;
      param_1->state = 0x2100;
      psVar12 = param_1->s3;
      if (param_1->hit == 0) {
        (psVar12->tmp).next_state = 3;
      }
      else {
        (psVar12->tmp).next_state =
             (-(uint)(psVar12->next_proto_neg_seen == 0) & 0xffffffb0) + 0x2210;
      }
      param_1->init_num = 0;
      uVar7 = 0;
      goto LAB_08099180;
    }
    if (iVar14 < 0x21a2) {
      if (iVar14 < 0x21a0) {
        if (1 < iVar14 - 0x2190U) goto LAB_08099a10;
        iVar9 = ssl3_get_client_key_exchange(param_1);
        if (iVar9 < 1) goto LAB_080992f8;
        if (iVar9 != 2) {
          param_1->state = 0x21a0;
          param_1->init_num = 0;
          if ((param_1->version >> 8 != 3) || (param_1->version < 0x303)) {
            psVar12 = param_1->s3;
            if (psVar12->handshake_buffer != (BIO *)0x0) {
              iVar9 = ssl3_digest_cached_records(param_1);
              if (iVar9 == 0) goto LAB_08099291;
              psVar12 = param_1->s3;
            }
            iVar15 = 0;
            iVar9 = 0;
            do {
              ctx = *(EVP_MD_CTX **)((int)psVar12->handshake_dgst + iVar15);
              if (ctx != (EVP_MD_CTX *)0x0) {
                pcVar4 = *(code **)(param_1->method->ssl3_enc + 0x1c);
                pEVar10 = EVP_MD_CTX_md(ctx);
                iVar11 = EVP_MD_type(pEVar10);
                (*pcVar4)(param_1,iVar11,(psVar12->tmp).cert_verify_md + iVar9);
                pEVar10 = EVP_MD_CTX_md(*(EVP_MD_CTX **)((int)param_1->s3->handshake_dgst + iVar15))
                ;
                iVar11 = EVP_MD_size(pEVar10);
                if (iVar11 < 0) goto LAB_08099dd8;
                psVar12 = param_1->s3;
                iVar9 = iVar9 + iVar11;
              }
              iVar15 = iVar15 + 4;
            } while (iVar15 != 0x18);
            uVar7 = 0;
            goto LAB_08099180;
          }
          if (*(int *)(param_1->session->krb5_client_princ + 0xc) == 0) goto LAB_080994e0;
          psVar12 = param_1->s3;
          if (psVar12->handshake_buffer == (BIO *)0x0) {
            iVar9 = 0x280;
            goto LAB_08099f5b;
          }
          psVar12->flags = psVar12->flags | 0x20;
          iVar9 = ssl3_digest_cached_records(param_1);
          if (iVar9 == 0) goto LAB_08099291;
          goto LAB_080994e0;
        }
      }
      else {
        iVar9 = ssl3_get_cert_verify(param_1);
        if (iVar9 < 1) goto LAB_080992f8;
      }
      psVar12 = param_1->s3;
      iVar9 = psVar12->next_proto_neg_seen;
      param_1->init_num = 0;
      uVar7 = 0;
      param_1->state = (-(uint)(iVar9 == 0) & 0xffffffb0) + 0x2210;
      goto LAB_08099180;
    }
    if (iVar14 < 0x21c0) goto LAB_08099a10;
    if (iVar14 < 0x21c2) {
      psVar12 = param_1->s3;
      if (psVar12->change_cipher_spec == 0) {
        psVar12->flags = psVar12->flags | 0x80;
      }
      iVar9 = ssl3_get_finished(param_1,0x21c0,0x21c1);
      if (0 < iVar9) {
        if (param_1->hit == 0) {
LAB_0809992f:
          param_1->state = (-(uint)(param_1->tlsext_ocsp_resplen == 0) & 0xffffffe0) + 0x21f0;
        }
        else {
          param_1->state = 3;
        }
        goto LAB_0809977b;
      }
      goto LAB_080992f8;
    }
    if (1 < iVar14 - 0x21d0U) goto LAB_08099a10;
    *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24) = (param_1->s3->tmp).new_cipher;
    iVar9 = (**(code **)(param_1->method->ssl3_enc + 8))(param_1);
    if (iVar9 == 0) goto LAB_08099dd8;
    iVar9 = ssl3_send_change_cipher_spec(param_1,0x21d0,0x21d1);
    if (iVar9 < 1) goto LAB_080992f8;
    param_1->state = 0x21e0;
    param_1->init_num = 0;
    iVar9 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x22);
    if (iVar9 == 0) goto LAB_08099dd8;
  }
  else {
    if (0x2211 < iVar14) {
      if ((iVar14 != 0x4000) && (iVar14 != 0x6000)) {
        if (iVar14 != 0x3004) goto LAB_08099a10;
        param_1->tlsext_hb_seq = 1;
      }
LAB_080995e6:
      param_1->server = 1;
      if (p_Var13 != (_func_3152 *)0x0) {
        (*p_Var13)(param_1,0x10,1);
      }
      if (param_1->version >> 8 != 3) {
        iVar9 = 0x10c;
LAB_08099f5b:
        ERR_put_error(0x14,0x80,0x44,"s3_srvr.c",iVar9);
        param_1->state = 5;
        iVar9 = -1;
        goto LAB_0809931b;
      }
      param_1->type = 0x2000;
      if (param_1->init_buf == (BUF_MEM *)0x0) {
        str = BUF_MEM_new();
        if (str == (BUF_MEM *)0x0) goto LAB_08099dd8;
        iVar9 = BUF_MEM_grow(str,0x4000);
        if (iVar9 == 0) {
          BUF_MEM_free(str);
          param_1->state = 5;
          iVar9 = -1;
          goto LAB_080992f8;
        }
        param_1->init_buf = str;
      }
      iVar9 = ssl3_setup_buffers(param_1);
      if (iVar9 == 0) goto LAB_08099dd8;
      psVar12 = param_1->s3;
      param_1->init_num = 0;
      psVar12->flags = psVar12->flags & 0xffffff3f;
      iVar9 = param_1->state;
      psVar12->change_cipher_spec = 0;
      if (iVar9 == 0x3004) {
        if ((psVar12->send_connection_binding == 0) &&
           ((*(byte *)((int)&param_1->references + 2) & 4) == 0)) {
          ERR_put_error(0x14,0x80,0x152,"s3_srvr.c",0x145);
          ssl3_send_alert(param_1,2,0x28);
          param_1->state = 5;
          iVar9 = -1;
          goto LAB_080992f8;
        }
        uVar7 = 0;
        *(int *)(param_1->psk_server_callback + 0x44) =
             *(int *)(param_1->psk_server_callback + 0x44) + 1;
        param_1->state = 0x2120;
      }
      else {
        iVar9 = ssl_init_wbio_buffer(param_1,1);
        if (iVar9 == 0) goto LAB_08099dd8;
        uVar7 = 0;
        ssl3_init_finished_mac(param_1);
        param_1->state = 0x2110;
        psVar12 = param_1->s3;
        *(int *)(param_1->psk_server_callback + 0x40) =
             *(int *)(param_1->psk_server_callback + 0x40) + 1;
      }
      goto LAB_08099180;
    }
    if (0x220f < iVar14) {
      psVar12 = param_1->s3;
      if (psVar12->change_cipher_spec == 0) {
        psVar12->flags = psVar12->flags | 0x80;
      }
      iVar9 = ssl3_get_next_proto(param_1);
      if (0 < iVar9) {
        param_1->init_num = 0;
        param_1->state = 0x21c0;
        goto LAB_080994e0;
      }
      goto LAB_080992f8;
    }
    if (iVar14 < 0x21f0) goto LAB_08099a10;
    if (0x21f1 < iVar14) {
      if (1 < iVar14 - 0x2200U) goto LAB_08099a10;
      iVar9 = ssl3_send_cert_status(param_1);
      if (iVar9 < 1) goto LAB_080992f8;
      param_1->state = 0x2150;
      param_1->init_num = 0;
      uVar7 = 0;
      psVar12 = param_1->s3;
      goto LAB_08099180;
    }
    iVar9 = ssl3_send_newsession_ticket(param_1);
    if (iVar9 < 1) goto LAB_080992f8;
    param_1->state = 0x21d0;
LAB_0809977b:
    param_1->init_num = 0;
  }
LAB_080994e0:
  psVar12 = param_1->s3;
  uVar7 = 0;
  goto LAB_08099180;
}

