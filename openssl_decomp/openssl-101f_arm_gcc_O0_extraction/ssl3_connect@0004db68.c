
int ssl3_connect(SSL *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  BIO *pBVar4;
  long lVar5;
  BUF_MEM *str;
  int iVar6;
  int iVar7;
  SSL_COMP *pSVar8;
  SSL_SESSION *pSVar9;
  SSL_CIPHER *pSVar10;
  _func_3154 *p_Var11;
  ssl3_state_st *psVar12;
  SSL_METHOD *pSVar13;
  _func_3152 *p_Var14;
  uint uVar15;
  char *pcVar16;
  size_t __n;
  ssl3_enc_method *psVar17;
  bool bVar18;
  undefined4 in_stack_ffffffb8;
  undefined4 in_stack_ffffffbc;
  time_t local_30;
  int local_2c [2];
  
  local_30 = time((time_t *)0x0);
  RAND_add(&local_30,4,(double)CONCAT44(in_stack_ffffffbc,in_stack_ffffffb8));
  ERR_clear_error();
  piVar1 = __errno_location();
  p_Var14 = param_1->info_callback;
  *piVar1 = 0;
  if (p_Var14 == (_func_3152 *)0x0) {
    p_Var14 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar2 = SSL_state(param_1);
  if (((uVar2 & 0x3000) == 0) || (iVar3 = SSL_state(param_1), iVar3 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  if (param_1->tlsext_heartbeat != 0) {
    param_1->tlsext_heartbeat = 0;
    param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
  }
  iVar3 = param_1->state;
LAB_0004dbde:
  iVar6 = iVar3;
  if (iVar6 < 0x1182) {
    if (0x117f < iVar6) {
      iVar3 = ssl3_send_client_key_exchange(param_1);
      if (0 < iVar3) {
        psVar12 = param_1->s3;
        bVar18 = (psVar12->tmp).cert_req == 1;
        if (bVar18) {
          iVar3 = 0x1190;
        }
        else {
          iVar3 = 0x11a0;
        }
        if (bVar18) {
          param_1->state = iVar3;
        }
        if (!bVar18) {
          param_1->state = iVar3;
        }
        if (!bVar18) {
          psVar12->change_cipher_spec = 0;
        }
        if (psVar12->flags << 0x1b < 0) {
          param_1->state = 0x11a0;
          psVar12->change_cipher_spec = 0;
          uVar2 = 0;
          param_1->init_num = 0;
        }
        else {
LAB_0004df80:
          param_1->init_num = 0;
          uVar2 = 0;
        }
        goto LAB_0004defc;
      }
      goto LAB_0004dfee;
    }
    if (iVar6 < 0x1132) {
      if (0x112f < iVar6) {
        if (*(int *)(param_1->session->krb5_client_princ + 0x54) == 0) {
          psVar12 = param_1->s3;
        }
        else {
          iVar3 = (*param_1->method->ssl_get_message)
                            (param_1,0x1130,0x1131,-1,param_1->mode,local_2c);
          if (local_2c[0] == 0) {
            if (iVar3 < 1) goto LAB_0004dfee;
            psVar12 = param_1->s3;
            if (iVar3 == 2) goto LAB_0004e14c;
          }
          else {
            psVar12 = param_1->s3;
            (psVar12->tmp).reuse_message = 1;
            if (((psVar12->tmp).message_type & 0xffffffefU) == 4) {
LAB_0004e14c:
              param_1->init_num = 0;
              if (param_1->tlsext_ocsp_resplen == 0) {
                iVar3 = 0x11d0;
              }
              else {
                iVar3 = 0x11e0;
              }
              param_1->hit = 1;
              param_1->state = iVar3;
              uVar2 = 0;
              goto LAB_0004defc;
            }
          }
        }
        pSVar10 = (psVar12->tmp).new_cipher;
        if (((int)(pSVar10->algorithm_auth << 0x1d) < 0) ||
           (uVar15 = pSVar10->algorithm_mkey & 0x100, uVar15 != 0)) {
          param_1->state = 0x1140;
          uVar2 = 1;
        }
        else {
          iVar3 = ssl3_get_server_certificate(param_1);
          if (iVar3 < 1) goto LAB_0004dfee;
          uVar2 = param_1->tlsext_status_type;
          if (uVar2 == 0) {
            psVar12 = param_1->s3;
            param_1->state = 0x1140;
          }
          else {
            psVar12 = param_1->s3;
            param_1->state = 0x11f0;
            uVar2 = uVar15;
          }
        }
        param_1->init_num = 0;
        goto LAB_0004defc;
      }
      if (iVar6 == 0x1100) {
        param_1->rwstate = 2;
        lVar5 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
        if (0 < lVar5) {
          psVar12 = param_1->s3;
          param_1->rwstate = 1;
          uVar2 = 0;
          param_1->state = (psVar12->tmp).next_state;
          goto LAB_0004defc;
        }
        goto LAB_0004e0ca;
      }
      if (iVar6 < 0x1101) {
        if ((iVar6 == 0x1000) || (iVar6 == 0x1003)) goto LAB_0004de9c;
        if (iVar6 == 3) {
          ssl3_cleanup_key_block(param_1);
          if (param_1->init_buf != (BUF_MEM *)0x0) {
            BUF_MEM_free(param_1->init_buf);
            param_1->init_buf = (BUF_MEM *)0x0;
          }
          if (-1 < param_1->s3->flags << 0x1d) {
            ssl_free_wbio_buffer(param_1);
          }
          param_1->init_num = 0;
          param_1->tlsext_hb_seq = 0;
          param_1->new_session = 0;
          ssl_update_cache(param_1,1);
          if (param_1->hit == 0) {
            p_Var11 = param_1->psk_server_callback;
          }
          else {
            p_Var11 = param_1->psk_server_callback;
            *(int *)(p_Var11 + 0x58) = *(int *)(p_Var11 + 0x58) + 1;
          }
          iVar6 = *(int *)(p_Var11 + 0x3c);
          iVar3 = 1;
          param_1->handshake_func = ssl3_connect;
          *(int *)(p_Var11 + 0x3c) = iVar6 + 1;
          if (p_Var14 != (_func_3152 *)0x0) {
            iVar3 = 1;
            (*p_Var14)(param_1,0x20,1);
            param_1->in_handshake = param_1->in_handshake + -1;
            goto LAB_0004de4e;
          }
LAB_0004dfee:
          param_1->in_handshake = param_1->in_handshake + -1;
LAB_0004de4e:
          if (p_Var14 != (_func_3152 *)0x0) {
            (*p_Var14)(param_1,0x1002,iVar3);
          }
          return iVar3;
        }
LAB_0004dfd2:
        iVar3 = -1;
        ERR_put_error(0x14,0x84,0xff,"s3_clnt.c",0x26a);
        goto LAB_0004dfee;
      }
      if (iVar6 < 0x1110) goto LAB_0004dfd2;
      if (iVar6 < 0x1112) {
        param_1->shutdown = 0;
        iVar3 = ssl3_client_hello(param_1);
        if (0 < iVar3) {
          param_1->init_num = 0;
          param_1->state = 0x1120;
          if (param_1->bbio == param_1->wbio) goto LAB_0004dd14;
          pBVar4 = BIO_push(param_1->bbio,param_1->wbio);
          psVar12 = param_1->s3;
          uVar2 = 0;
          param_1->wbio = pBVar4;
          goto LAB_0004defc;
        }
        goto LAB_0004dfee;
      }
      if (1 < iVar6 - 0x1120U) goto LAB_0004dfd2;
      iVar3 = ssl3_get_server_hello(param_1);
      if (iVar3 < 1) goto LAB_0004dfee;
      if (param_1->hit == 0) {
        param_1->state = 0x1130;
      }
      else {
        param_1->state = 0x11d0;
        if (param_1->tlsext_ocsp_resplen != 0) {
          param_1->state = 0x11e0;
        }
      }
      param_1->init_num = 0;
      uVar2 = (param_1->s3->tmp).reuse_message;
      goto joined_r0x0004dc58;
    }
    if (iVar6 < 0x1152) {
      if (0x114f < iVar6) {
        iVar3 = ssl3_get_certificate_request(param_1);
        if (0 < iVar3) {
          param_1->init_num = 0;
          psVar12 = param_1->s3;
          uVar2 = 0;
          param_1->state = 0x1160;
          goto LAB_0004defc;
        }
        goto LAB_0004dfee;
      }
      if (1 < iVar6 - 0x1140U) goto LAB_0004dfd2;
      iVar3 = ssl3_get_key_exchange(param_1);
      if (iVar3 < 1) goto LAB_0004dfee;
      param_1->state = 0x1150;
      param_1->init_num = 0;
      iVar3 = ssl3_check_cert_and_algorithm(param_1);
      if (iVar3 == 0) goto LAB_0004e0ca;
LAB_0004dd14:
      psVar12 = param_1->s3;
      uVar2 = 0;
    }
    else {
      if (iVar6 < 0x1160) goto LAB_0004dfd2;
      if (iVar6 < 0x1162) {
        iVar3 = (*param_1->method->ssl_get_message)(param_1,0x1160,0x1161,0xe,0x1e,local_2c);
        if (local_2c[0] == 0) {
          if (iVar3 < 1) goto LAB_0004dfee;
        }
        else if (0 < iVar3) {
          iVar3 = -1;
          ssl3_send_alert(param_1,2,0x32);
          ERR_put_error(0x14,0x91,0x9f,"s3_clnt.c",0x8a0);
          goto LAB_0004dfee;
        }
        psVar12 = param_1->s3;
        if ((int)(((psVar12->tmp).new_cipher)->algorithm_mkey << 0x15) < 0) {
          iVar3 = SRP_Calc_A_param(param_1);
          if (iVar3 < 1) {
            ERR_put_error(0x14,0x84,0x169,"s3_clnt.c",0x186);
            ssl3_send_alert(param_1,2,0x50);
            goto LAB_0004dfee;
          }
          psVar12 = param_1->s3;
        }
        iVar3 = (psVar12->tmp).cert_req;
        iVar7 = 0x1170;
        uVar2 = 0;
        param_1->init_num = 0;
        if (iVar3 == 0) {
          iVar7 = 0x1180;
        }
        param_1->state = iVar7;
      }
      else {
        if (3 < iVar6 - 0x1170U) goto LAB_0004dfd2;
        iVar3 = ssl3_send_client_certificate(param_1);
        if (iVar3 < 1) goto LAB_0004dfee;
        param_1->init_num = 0;
        psVar12 = param_1->s3;
        uVar2 = 0;
        param_1->state = 0x1180;
      }
    }
  }
  else if (iVar6 < 0x11e2) {
    if (iVar6 < 0x11e0) {
      if (iVar6 < 0x11a2) {
        if (0x119f < iVar6) {
          iVar3 = ssl3_send_change_cipher_spec(param_1,0x11a0);
          if (0 < iVar3) {
            psVar12 = param_1->s3;
            pSVar9 = param_1->session;
            pSVar10 = (psVar12->tmp).new_cipher;
            pSVar8 = (psVar12->tmp).new_compression;
            iVar3 = psVar12->next_proto_neg_seen;
            param_1->init_num = 0;
            if (iVar3 == 0) {
              iVar3 = 0x11b0;
            }
            else {
              iVar3 = 0x1200;
            }
            param_1->state = iVar3;
            *(SSL_CIPHER **)(pSVar9->krb5_client_princ + 0x24) = pSVar10;
            if (pSVar8 != (SSL_COMP *)0x0) {
              pSVar8 = (SSL_COMP *)pSVar8->id;
            }
            pSVar13 = param_1->method;
            *(SSL_COMP **)(pSVar9->krb5_client_princ + 0x20) = pSVar8;
            iVar3 = (**(code **)(pSVar13->ssl3_enc + 8))(param_1);
            if ((iVar3 != 0) &&
               (iVar3 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x12), iVar3 != 0))
            goto LAB_0004dd14;
            goto LAB_0004e0ca;
          }
          goto LAB_0004dfee;
        }
        if (iVar6 - 0x1190U < 2) {
          iVar3 = ssl3_send_client_verify(param_1);
          if (0 < iVar3) {
            psVar12 = param_1->s3;
            param_1->init_num = 0;
            uVar2 = 0;
            param_1->state = 0x11a0;
            psVar12->change_cipher_spec = 0;
            goto LAB_0004defc;
          }
          goto LAB_0004dfee;
        }
      }
      else {
        if (iVar6 < 0x11b0) goto LAB_0004dfd2;
        if (iVar6 < 0x11b2) {
          psVar17 = param_1->method->ssl3_enc;
          iVar3 = ssl3_send_finished(param_1,0x11b0,0x11b1,*(undefined4 *)(psVar17 + 0x20),
                                     *(undefined4 *)(psVar17 + 0x24));
          if (0 < iVar3) {
            psVar12 = param_1->s3;
            iVar3 = param_1->hit;
            param_1->state = 0x1100;
            uVar15 = psVar12->flags;
            uVar2 = uVar15 & 0xfffffffb;
            psVar12->flags = uVar2;
            if (iVar3 == 0) {
              if (param_1->tlsext_ocsp_resplen == 0) {
                (psVar12->tmp).next_state = 0x11d0;
              }
              else {
                (psVar12->tmp).next_state = 0x11e0;
              }
            }
            else {
              (psVar12->tmp).next_state = 3;
              if ((int)(uVar15 << 0x1e) < 0) {
                param_1->state = 3;
                psVar12->flags = uVar2 | 4;
                psVar12->delay_buf_pop_ret = 0;
              }
            }
            goto LAB_0004df80;
          }
          goto LAB_0004dfee;
        }
        if (iVar6 - 0x11d0U < 2) {
          iVar3 = ssl3_get_finished(param_1,0x11d0,0x11d1);
          if (0 < iVar3) {
            uVar2 = 0;
            param_1->init_num = 0;
            if (param_1->hit == 0) {
              iVar3 = 3;
            }
            else {
              iVar3 = 0x11a0;
            }
            psVar12 = param_1->s3;
            param_1->state = iVar3;
            goto LAB_0004defc;
          }
          goto LAB_0004dfee;
        }
      }
      goto LAB_0004dfd2;
    }
    iVar3 = ssl3_get_new_session_ticket(param_1);
    if (iVar3 < 1) goto LAB_0004dfee;
    param_1->init_num = 0;
    psVar12 = param_1->s3;
    uVar2 = 0;
    param_1->state = 0x11d0;
  }
  else if (iVar6 < 0x1202) {
    if (iVar6 < 0x1200) {
      if (1 < iVar6 - 0x11f0U) goto LAB_0004dfd2;
      iVar3 = ssl3_get_cert_status(param_1);
      if (iVar3 < 1) goto LAB_0004dfee;
      param_1->init_num = 0;
      psVar12 = param_1->s3;
      uVar2 = 0;
      param_1->state = 0x1140;
    }
    else {
      if (iVar6 == 0x1200) {
        uVar2 = (uint)*(byte *)&param_1->next_proto_negotiated;
        pcVar16 = param_1->init_buf->data;
        __n = 0x20 - (uVar2 + 2 & 0x1f);
        pcVar16[4] = *(byte *)&param_1->next_proto_negotiated;
        memcpy(pcVar16 + 5,param_1->initial_ctx,uVar2);
        pcVar16[uVar2 + 5] = (char)__n;
        memset(pcVar16 + uVar2 + 6,0,__n);
        pcVar16[1] = '\0';
        *pcVar16 = 'C';
        pcVar16[3] = (char)__n + (char)(uVar2 + 2);
        pcVar16[2] = (char)(uVar2 + __n + 2 >> 8);
        param_1->init_num = uVar2 + __n + 6;
        param_1->state = 0x1201;
        param_1->init_off = 0;
      }
      iVar3 = ssl3_do_write(param_1,0x16);
      if (iVar3 < 1) goto LAB_0004dfee;
      psVar12 = param_1->s3;
      param_1->state = 0x11b0;
      uVar2 = 0;
    }
  }
  else {
    if ((iVar6 != 0x4000) && (iVar6 != 0x5000)) {
      if (iVar6 != 0x3004) goto LAB_0004dfd2;
      param_1->tlsext_hb_seq = 1;
      param_1->state = 0x1000;
      *(int *)(param_1->psk_server_callback + 0x38) =
           *(int *)(param_1->psk_server_callback + 0x38) + 1;
    }
LAB_0004de9c:
    param_1->server = 0;
    if (p_Var14 != (_func_3152 *)0x0) {
      (*p_Var14)(param_1,0x10,1);
    }
    if ((param_1->version & 0xff00U) != 0x300) {
      iVar3 = -1;
      ERR_put_error(0x14,0x84,0x44,"s3_clnt.c",0xef);
      goto LAB_0004dfee;
    }
    param_1->type = 0x1000;
    if (param_1->init_buf == (BUF_MEM *)0x0) {
      str = BUF_MEM_new();
      if (str == (BUF_MEM *)0x0) goto LAB_0004e0ca;
      iVar3 = BUF_MEM_grow(str,0x4000);
      if (iVar3 == 0) {
        iVar3 = -1;
        param_1->in_handshake = param_1->in_handshake + -1;
        BUF_MEM_free(str);
        goto LAB_0004de4e;
      }
      param_1->init_buf = str;
    }
    iVar3 = ssl3_setup_buffers(param_1);
    if ((iVar3 == 0) || (iVar3 = ssl_init_wbio_buffer(param_1,0), iVar3 == 0)) {
LAB_0004e0ca:
      iVar3 = -1;
      goto LAB_0004dfee;
    }
    ssl3_init_finished_mac(param_1);
    uVar2 = 0;
    param_1->state = 0x1110;
    psVar12 = param_1->s3;
    *(int *)(param_1->psk_server_callback + 0x34) =
         *(int *)(param_1->psk_server_callback + 0x34) + 1;
    param_1->init_num = 0;
  }
LAB_0004defc:
  uVar2 = uVar2 | (psVar12->tmp).reuse_message;
joined_r0x0004dc58:
  if (uVar2 == 0) {
    if ((param_1->ctx != (SSL_CTX *)0x0) &&
       (iVar3 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0), iVar3 < 1)) goto LAB_0004dfee;
    if (p_Var14 == (_func_3152 *)0x0) {
      iVar3 = param_1->state;
    }
    else {
      iVar3 = param_1->state;
      if (iVar6 != iVar3) {
        param_1->state = iVar6;
        (*p_Var14)(param_1,0x1001,1);
        param_1->state = iVar3;
      }
    }
  }
  else {
    iVar3 = param_1->state;
  }
  goto LAB_0004dbde;
}

