
int ssl3_accept(SSL *param_1)

{
  SSL_CIPHER *pSVar1;
  char *pcVar2;
  BIO *pBVar3;
  EVP_MD_CTX *ctx;
  code *pcVar4;
  ssl3_enc_method *psVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  long lVar9;
  int iVar10;
  EVP_MD *pEVar11;
  int iVar12;
  BUF_MEM *str;
  ssl3_state_st *psVar13;
  int iVar14;
  int in_GS_OFFSET;
  bool bVar15;
  int iVar16;
  _func_3152 *local_38;
  int local_34;
  time_t local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = time((time_t *)0x0);
  RAND_add(&local_28,4,0.0);
  ERR_clear_error();
  piVar7 = __errno_location();
  *piVar7 = 0;
  local_38 = param_1->info_callback;
  if (local_38 == (_func_3152 *)0x0) {
    local_38 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar8 = SSL_state(param_1);
  if (((uVar8 & 0x3000) == 0) || (uVar8 = SSL_state(param_1), (uVar8 & 0x4000) != 0)) {
    SSL_clear(param_1);
  }
  if (param_1->cert == (cert_st *)0x0) {
    iVar10 = 0xec;
    iVar16 = 0xb3;
LAB_0809dcc9:
    ERR_put_error(0x14,0x80,iVar16,"s3_srvr.c",iVar10);
LAB_0809d091:
    local_34 = -1;
LAB_0809d11b:
    if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return local_34;
  }
  if (param_1->tlsext_heartbeat != 0) {
    param_1->tlsext_heartbeat = 0;
    param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
  }
LAB_0809cec8:
  iVar16 = param_1->state;
  if (0x2181 < iVar16) goto LAB_0809cfd0;
LAB_0809ced7:
  if (0x217f < iVar16) {
    local_34 = ssl3_check_client_hello(param_1);
    if (0 < local_34) {
      if (local_34 == 2) {
        param_1->state = 0x2112;
        psVar13 = param_1->s3;
        uVar8 = 0;
        goto LAB_0809cf78;
      }
      psVar13 = param_1->s3;
      if ((psVar13->tmp).cert_request != 0) {
        local_34 = ssl3_get_client_certificate(param_1);
        if (local_34 < 1) goto LAB_0809d0f0;
        psVar13 = param_1->s3;
      }
      param_1->init_num = 0;
      param_1->state = 0x2190;
      uVar8 = 0;
      goto LAB_0809cf78;
    }
    goto LAB_0809d0f0;
  }
  if (iVar16 < 0x2132) {
    if (0x212f < iVar16) {
      local_34 = ssl3_send_server_hello(param_1);
      if (0 < local_34) {
        if (param_1->hit != 0) goto LAB_0809d6bf;
        param_1->state = 0x2140;
        goto LAB_0809d54b;
      }
      goto LAB_0809d0f0;
    }
    if (0x2112 < iVar16) {
      if (iVar16 < 0x2120) goto LAB_0809d790;
      if (iVar16 < 0x2122) {
        param_1->shutdown = 0;
        if (iVar16 == 0x2120) {
          pcVar2 = param_1->init_buf->data;
          *pcVar2 = '\0';
          pcVar2[1] = '\0';
          pcVar2[2] = '\0';
          pcVar2[3] = '\0';
          param_1->state = 0x2121;
          param_1->init_num = 4;
          param_1->init_off = 0;
        }
        local_34 = ssl3_do_write(param_1,0x16);
        if (local_34 < 1) goto LAB_0809d0f0;
        uVar8 = 0;
        (param_1->s3->tmp).next_state = 0x2122;
        param_1->state = 0x2100;
        param_1->init_num = 0;
        ssl3_init_finished_mac(param_1);
        psVar13 = param_1->s3;
      }
      else {
        if (iVar16 != 0x2122) goto LAB_0809d790;
        param_1->state = 3;
        psVar13 = param_1->s3;
        uVar8 = 0;
      }
      goto LAB_0809cf78;
    }
    if (iVar16 < 0x2110) {
      if (iVar16 == 0x2000) goto LAB_0809d3c6;
      if (0x2000 < iVar16) {
        if (iVar16 == 0x2003) goto LAB_0809d3c6;
        if (iVar16 != 0x2100) goto LAB_0809d790;
        param_1->rwstate = 2;
        lVar9 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
        if (0 < lVar9) {
          psVar13 = param_1->s3;
          param_1->rwstate = 1;
          uVar8 = 0;
          param_1->state = (psVar13->tmp).next_state;
          goto LAB_0809cf78;
        }
LAB_0809dbe8:
        local_34 = -1;
        goto LAB_0809d0f0;
      }
      if (iVar16 != 3) goto LAB_0809d790;
      ssl3_cleanup_key_block(param_1);
      BUF_MEM_free(param_1->init_buf);
      param_1->init_buf = (BUF_MEM *)0x0;
      ssl_free_wbio_buffer(param_1);
      param_1->init_num = 0;
      local_34 = 1;
      if (param_1->tlsext_hb_seq != 2) goto LAB_0809d0f0;
      param_1->tlsext_hb_seq = 0;
      param_1->new_session = 0;
      ssl_update_cache(param_1,2);
      *(int *)(param_1->psk_server_callback + 0x48) =
           *(int *)(param_1->psk_server_callback + 0x48) + 1;
      param_1->handshake_func = ssl3_accept;
      if (local_38 == (_func_3152 *)0x0) {
        param_1->in_handshake = param_1->in_handshake + -1;
        local_34 = 1;
        goto LAB_0809d11b;
      }
      (*local_38)(param_1,0x20,1);
      param_1->in_handshake = param_1->in_handshake + -1;
      local_34 = 1;
    }
    else {
      param_1->shutdown = 0;
      if ((param_1->rwstate == 4) || (local_34 = ssl3_get_client_hello(param_1), 0 < local_34)) {
        psVar13 = param_1->s3;
        local_24 = 0x70;
        if (((*(byte *)((int)&((psVar13->tmp).new_cipher)->algorithm_mkey + 1) & 4) == 0) ||
           (param_1[1].version == 0)) {
LAB_0809d98a:
          param_1->tlsext_hb_seq = 2;
          param_1->state = 0x2130;
          uVar8 = 0;
          param_1->init_num = 0;
          goto LAB_0809cf78;
        }
        if (param_1[1].rbio == (BIO *)0x0) {
          local_24 = 0x73;
        }
        else {
          local_34 = SSL_srp_server_param_with_username(param_1,&local_24);
          if (local_34 < 0) {
            param_1->rwstate = 4;
            goto LAB_0809d0f0;
          }
          if (local_34 == 0) {
            psVar13 = param_1->s3;
            goto LAB_0809d98a;
          }
        }
        ssl3_send_alert(param_1,2,local_24);
        local_34 = -1;
        if (local_24 != 0x73) {
          local_34 = -1;
          ERR_put_error(0x14,0x80,0xe2,"s3_srvr.c",0x177);
        }
      }
LAB_0809d0f0:
      param_1->in_handshake = param_1->in_handshake + -1;
      if (local_38 == (_func_3152 *)0x0) goto LAB_0809d11b;
    }
    (*local_38)(param_1,0x2002,local_34);
    goto LAB_0809d11b;
  }
  if (0x2151 < iVar16) {
    if (0x215f < iVar16) {
      if (iVar16 < 0x2162) {
        uVar8 = param_1->verify_mode;
        if (((uVar8 & 1) == 0) ||
           ((*(int *)(param_1->session->krb5_client_princ + 0xc) != 0 && ((uVar8 & 4) != 0)))) {
          psVar13 = param_1->s3;
        }
        else {
          psVar13 = param_1->s3;
          pSVar1 = (psVar13->tmp).new_cipher;
          uVar6 = pSVar1->algorithm_auth;
          if (((((uVar6 & 4) == 0) || ((uVar8 & 2) != 0)) && ((uVar6 & 0x20) == 0)) &&
             ((*(byte *)((int)&pSVar1->algorithm_mkey + 1) & 1) == 0)) {
            (psVar13->tmp).cert_request = 1;
            local_34 = ssl3_send_certificate_request(param_1);
            if (0 < local_34) {
              psVar13 = param_1->s3;
              param_1->state = 0x2100;
              uVar8 = 0;
              (psVar13->tmp).next_state = 0x2180;
              param_1->init_num = 0;
              goto LAB_0809cf78;
            }
            goto LAB_0809d0f0;
          }
        }
        pBVar3 = psVar13->handshake_buffer;
        (psVar13->tmp).cert_request = 0;
        param_1->state = 0x2170;
        if (pBVar3 == (BIO *)0x0) {
          uVar8 = 1;
          goto LAB_0809cf78;
        }
        iVar10 = ssl3_digest_cached_records(param_1);
        if (iVar10 == 0) goto LAB_0809d091;
        psVar13 = param_1->s3;
        uVar8 = 1;
        goto LAB_0809cf78;
      }
      if (iVar16 - 0x2170U < 2) {
        if (iVar16 == 0x2170) {
          pcVar2 = param_1->init_buf->data;
          *pcVar2 = '\x0e';
          pcVar2[1] = '\0';
          pcVar2[2] = '\0';
          pcVar2[3] = '\0';
          param_1->state = 0x2171;
          param_1->init_num = 4;
          param_1->init_off = 0;
        }
        local_34 = ssl3_do_write(param_1,0x16);
        if (0 < local_34) {
          psVar13 = param_1->s3;
          uVar8 = 0;
          (psVar13->tmp).next_state = 0x2180;
          param_1->state = 0x2100;
          param_1->init_num = 0;
          goto LAB_0809cf78;
        }
        goto LAB_0809d0f0;
      }
    }
LAB_0809d790:
    ERR_put_error(0x14,0x80,0xff,"s3_srvr.c",0x32e);
    local_34 = -1;
    goto LAB_0809d0f0;
  }
  if (iVar16 < 0x2150) {
    if (1 < iVar16 - 0x2140U) goto LAB_0809d790;
    psVar13 = param_1->s3;
    pSVar1 = (psVar13->tmp).new_cipher;
    uVar8 = pSVar1->algorithm_auth;
    if ((((uVar8 & 4) == 0) && ((*(byte *)((int)&pSVar1->algorithm_mkey + 1) & 1) == 0)) &&
       ((uVar8 & 0x20) == 0)) {
      if (iVar16 == 0x2140) {
        iVar10 = ssl_get_server_send_cert(param_1);
        if ((iVar10 == 0) &&
           ((pSVar1 = (param_1->s3->tmp).new_cipher, pSVar1->algorithm_auth != 0x20 ||
            ((*(byte *)&pSVar1->algorithm_mkey & 0x10) != 0)))) {
          ERR_put_error(0x14,0x9a,0x44,"s3_srvr.c",0xd0a);
          local_34 = 0;
          goto LAB_0809d0f0;
        }
        iVar10 = ssl3_output_cert_chain(param_1,iVar10);
        param_1->state = 0x2141;
        param_1->init_num = iVar10;
        param_1->init_off = 0;
      }
      local_34 = ssl3_do_write(param_1,0x16);
      if (local_34 < 1) goto LAB_0809d0f0;
      if (param_1->tlsext_status_type == 0) {
        param_1->state = 0x2150;
        psVar13 = param_1->s3;
        uVar8 = 0;
      }
      else {
        param_1->state = 0x2200;
        psVar13 = param_1->s3;
        uVar8 = 0;
      }
    }
    else {
      param_1->state = 0x2150;
      uVar8 = 1;
    }
  }
  else {
    psVar13 = param_1->s3;
    pSVar1 = (psVar13->tmp).new_cipher;
    bVar15 = (param_1->references & 0x200000U) != 0;
    uVar8 = pSVar1->algorithm_mkey;
    (psVar13->tmp).use_rsa_tmp = (uint)bVar15;
    if ((bVar15) ||
       ((((uVar8 & 0x100) != 0 && (*(int *)(param_1->psk_server_callback + 0x14c) != 0)) ||
        ((uVar8 & 0x48e) != 0)))) {
LAB_0809d8f0:
      local_34 = ssl3_send_server_key_exchange(param_1);
      if (local_34 < 1) goto LAB_0809d0f0;
      psVar13 = param_1->s3;
      uVar8 = 0;
    }
    else if ((uVar8 & 1) == 0) {
      uVar8 = 1;
    }
    else {
      if (*(EVP_PKEY **)(param_1->cert + 0x34) == (EVP_PKEY *)0x0) goto LAB_0809d8f0;
      uVar8 = 1;
      if ((*(byte *)&pSVar1->algo_strength & 2) != 0) {
        iVar10 = EVP_PKEY_size(*(EVP_PKEY **)(param_1->cert + 0x34));
        psVar13 = param_1->s3;
        if ((int)((-(uint)((((psVar13->tmp).new_cipher)->algo_strength & 8) == 0) & 0x200) + 0x200)
            < iVar10 * 8) goto LAB_0809d8f0;
      }
    }
    param_1->state = 0x2160;
  }
  param_1->init_num = 0;
LAB_0809cf78:
  if ((uVar8 | (psVar13->tmp).reuse_message) != 0) goto LAB_0809cec8;
  if ((param_1->ctx != (SSL_CTX *)0x0) &&
     (local_34 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0), local_34 < 1)) goto LAB_0809d0f0;
  if (local_38 == (_func_3152 *)0x0) {
    iVar10 = param_1->state;
  }
  else {
    iVar10 = param_1->state;
    if (iVar10 != iVar16) {
      param_1->state = iVar16;
      (*local_38)(param_1,0x2001,1);
      param_1->state = iVar10;
    }
  }
  iVar16 = iVar10;
  if (iVar16 < 0x2182) goto LAB_0809ced7;
LAB_0809cfd0:
  if (iVar16 < 0x21e2) {
    if (0x21df < iVar16) {
      psVar5 = param_1->method->ssl3_enc;
      local_34 = ssl3_send_finished(param_1,0x21e0,0x21e1,*(undefined4 *)(psVar5 + 0x28),
                                    *(undefined4 *)(psVar5 + 0x2c));
      if (local_34 < 1) goto LAB_0809d0f0;
      param_1->state = 0x2100;
      psVar13 = param_1->s3;
      if (param_1->hit == 0) {
        (psVar13->tmp).next_state = 3;
      }
      else {
        (psVar13->tmp).next_state =
             (-(uint)(psVar13->next_proto_neg_seen == 0) & 0xffffffb0) + 0x2210;
      }
      param_1->init_num = 0;
      uVar8 = 0;
      goto LAB_0809cf78;
    }
    if (iVar16 < 0x21a2) {
      if (iVar16 < 0x21a0) {
        if (1 < iVar16 - 0x2190U) goto LAB_0809d790;
        local_34 = ssl3_get_client_key_exchange(param_1);
        if (local_34 < 1) goto LAB_0809d0f0;
        if (local_34 != 2) {
          param_1->state = 0x21a0;
          param_1->init_num = 0;
          if ((param_1->version >> 8 != 3) || (param_1->version < 0x303)) {
            psVar13 = param_1->s3;
            if (psVar13->handshake_buffer != (BIO *)0x0) {
              iVar10 = ssl3_digest_cached_records(param_1);
              if (iVar10 == 0) goto LAB_0809d091;
              psVar13 = param_1->s3;
            }
            iVar14 = 0;
            iVar10 = 0;
            do {
              ctx = *(EVP_MD_CTX **)((int)psVar13->handshake_dgst + iVar14);
              if (ctx != (EVP_MD_CTX *)0x0) {
                pcVar4 = *(code **)(param_1->method->ssl3_enc + 0x1c);
                pEVar11 = EVP_MD_CTX_md(ctx);
                iVar12 = EVP_MD_type(pEVar11);
                (*pcVar4)(param_1,iVar12,(psVar13->tmp).cert_verify_md + iVar10);
                pEVar11 = EVP_MD_CTX_md(*(EVP_MD_CTX **)((int)param_1->s3->handshake_dgst + iVar14))
                ;
                iVar12 = EVP_MD_size(pEVar11);
                if (iVar12 < 0) goto LAB_0809dbe8;
                psVar13 = param_1->s3;
                iVar10 = iVar10 + iVar12;
              }
              iVar14 = iVar14 + 4;
            } while (iVar14 != 0x18);
            uVar8 = 0;
            goto LAB_0809cf78;
          }
          if (*(int *)(param_1->session->krb5_client_princ + 0xc) == 0) goto LAB_0809d2c0;
          psVar13 = param_1->s3;
          if (psVar13->handshake_buffer == (BIO *)0x0) {
            iVar10 = 0x279;
            goto LAB_0809dcc2;
          }
          psVar13->flags = psVar13->flags | 0x20;
          iVar10 = ssl3_digest_cached_records(param_1);
          if (iVar10 == 0) goto LAB_0809d091;
          goto LAB_0809d2c0;
        }
      }
      else {
        local_34 = ssl3_get_cert_verify(param_1);
        if (local_34 < 1) goto LAB_0809d0f0;
      }
      psVar13 = param_1->s3;
      iVar10 = psVar13->next_proto_neg_seen;
      param_1->init_num = 0;
      uVar8 = 0;
      param_1->state = (-(uint)(iVar10 == 0) & 0xffffffb0) + 0x2210;
      goto LAB_0809cf78;
    }
    if (iVar16 < 0x21c0) goto LAB_0809d790;
    if (iVar16 < 0x21c2) {
      local_34 = ssl3_get_finished(param_1,0x21c0,0x21c1);
      if (0 < local_34) {
        if (param_1->hit == 0) {
LAB_0809d6bf:
          param_1->state = (-(uint)(param_1->tlsext_ocsp_resplen == 0) & 0xffffffe0) + 0x21f0;
        }
        else {
          param_1->state = 3;
        }
        goto LAB_0809d54b;
      }
      goto LAB_0809d0f0;
    }
    if (1 < iVar16 - 0x21d0U) goto LAB_0809d790;
    *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24) = (param_1->s3->tmp).new_cipher;
    iVar10 = (**(code **)(param_1->method->ssl3_enc + 8))(param_1);
    if (iVar10 == 0) goto LAB_0809dbe8;
    local_34 = ssl3_send_change_cipher_spec(param_1,0x21d0,0x21d1);
    if (local_34 < 1) goto LAB_0809d0f0;
    param_1->state = 0x21e0;
    param_1->init_num = 0;
    iVar10 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x22);
    if (iVar10 == 0) goto LAB_0809dbe8;
  }
  else {
    if (0x2211 < iVar16) {
      if ((iVar16 != 0x4000) && (iVar16 != 0x6000)) {
        if (iVar16 != 0x3004) goto LAB_0809d790;
        param_1->tlsext_hb_seq = 1;
      }
LAB_0809d3c6:
      param_1->server = 1;
      if (local_38 != (_func_3152 *)0x0) {
        (*local_38)(param_1,0x10,1);
      }
      if (param_1->version >> 8 != 3) {
        iVar10 = 0x110;
LAB_0809dcc2:
        iVar16 = 0x44;
        goto LAB_0809dcc9;
      }
      param_1->type = 0x2000;
      if (param_1->init_buf == (BUF_MEM *)0x0) {
        str = BUF_MEM_new();
        if ((str == (BUF_MEM *)0x0) || (iVar10 = BUF_MEM_grow(str,0x4000), iVar10 == 0))
        goto LAB_0809dbe8;
        param_1->init_buf = str;
      }
      iVar10 = ssl3_setup_buffers(param_1);
      if (iVar10 == 0) goto LAB_0809dbe8;
      psVar13 = param_1->s3;
      param_1->init_num = 0;
      psVar13->flags = psVar13->flags & 0xffffffbf;
      if (param_1->state == 0x3004) {
        if ((psVar13->send_connection_binding == 0) &&
           ((*(byte *)((int)&param_1->references + 2) & 4) == 0)) {
          ERR_put_error(0x14,0x80,0x152,"s3_srvr.c",0x13f);
          ssl3_send_alert(param_1,2,0x28);
          local_34 = -1;
          goto LAB_0809d0f0;
        }
        uVar8 = 0;
        *(int *)(param_1->psk_server_callback + 0x44) =
             *(int *)(param_1->psk_server_callback + 0x44) + 1;
        param_1->state = 0x2120;
      }
      else {
        iVar10 = ssl_init_wbio_buffer(param_1,1);
        if (iVar10 == 0) goto LAB_0809dbe8;
        uVar8 = 0;
        ssl3_init_finished_mac(param_1);
        param_1->state = 0x2110;
        psVar13 = param_1->s3;
        *(int *)(param_1->psk_server_callback + 0x40) =
             *(int *)(param_1->psk_server_callback + 0x40) + 1;
      }
      goto LAB_0809cf78;
    }
    if (0x220f < iVar16) {
      local_34 = ssl3_get_next_proto(param_1);
      if (0 < local_34) {
        param_1->init_num = 0;
        param_1->state = 0x21c0;
        goto LAB_0809d2c0;
      }
      goto LAB_0809d0f0;
    }
    if (iVar16 < 0x21f0) goto LAB_0809d790;
    if (0x21f1 < iVar16) {
      if (1 < iVar16 - 0x2200U) goto LAB_0809d790;
      local_34 = ssl3_send_cert_status(param_1);
      if (local_34 < 1) goto LAB_0809d0f0;
      param_1->state = 0x2150;
      param_1->init_num = 0;
      uVar8 = 0;
      psVar13 = param_1->s3;
      goto LAB_0809cf78;
    }
    local_34 = ssl3_send_newsession_ticket(param_1);
    if (local_34 < 1) goto LAB_0809d0f0;
    param_1->state = 0x21d0;
LAB_0809d54b:
    param_1->init_num = 0;
  }
LAB_0809d2c0:
  psVar13 = param_1->s3;
  uVar8 = 0;
  goto LAB_0809cf78;
}

