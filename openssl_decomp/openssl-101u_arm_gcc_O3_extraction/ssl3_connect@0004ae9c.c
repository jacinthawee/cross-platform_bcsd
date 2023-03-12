
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
  SSL_CIPHER *pSVar9;
  SSL_SESSION *pSVar10;
  _func_3154 *p_Var11;
  ssl3_state_st *psVar12;
  _func_3152 *p_Var13;
  ulong max;
  char *pcVar14;
  SSL_METHOD *pSVar15;
  size_t __n;
  uint uVar16;
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
  p_Var13 = param_1->info_callback;
  *piVar1 = 0;
  if (p_Var13 == (_func_3152 *)0x0) {
    p_Var13 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
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
LAB_0004af12:
  iVar6 = iVar3;
  if (iVar6 < 0x1182) {
    if (iVar6 < 0x1180) {
      if (iVar6 < 0x1132) {
        if (iVar6 < 0x1130) {
          if (iVar6 == 0x1100) {
            param_1->rwstate = 2;
            lVar5 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
            if (lVar5 < 1) goto LAB_0004b4b0;
            psVar12 = param_1->s3;
            param_1->rwstate = 1;
            uVar2 = 0;
            param_1->state = (psVar12->tmp).next_state;
          }
          else {
            if (iVar6 < 0x1101) {
              if ((iVar6 == 0x1000) || (iVar6 == 0x1003)) goto LAB_0004b1d4;
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
                if (p_Var13 != (_func_3152 *)0x0) {
                  iVar3 = 1;
                  (*p_Var13)(param_1,0x20,1);
                  param_1->in_handshake = param_1->in_handshake + -1;
                  goto LAB_0004b188;
                }
LAB_0004b334:
                param_1->in_handshake = param_1->in_handshake + -1;
LAB_0004b188:
                if (p_Var13 != (_func_3152 *)0x0) {
                  (*p_Var13)(param_1,0x1002,iVar3);
                }
                return iVar3;
              }
              goto LAB_0004b318;
            }
            if (iVar6 < 0x1110) goto LAB_0004b318;
            if (iVar6 < 0x1112) {
              param_1->shutdown = 0;
              iVar3 = ssl3_client_hello(param_1);
              if (0 < iVar3) {
                param_1->init_num = 0;
                param_1->state = 0x1120;
                if (param_1->bbio == param_1->wbio) goto LAB_0004b042;
                pBVar4 = BIO_push(param_1->bbio,param_1->wbio);
                psVar12 = param_1->s3;
                uVar2 = 0;
                param_1->wbio = pBVar4;
                goto LAB_0004b242;
              }
              goto LAB_0004b334;
            }
            if (1 < iVar6 - 0x1120U) goto LAB_0004b318;
            iVar3 = ssl3_get_server_hello(param_1);
            if (iVar3 < 1) goto LAB_0004b334;
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
            uVar2 = 0;
            psVar12 = param_1->s3;
          }
        }
        else {
          local_2c[0] = 0;
          if (((0x300 < param_1->version) && (param_1->tls_session_ticket_ext_cb_arg != (void *)0x0)
              ) && (*(int *)(param_1->session->krb5_client_princ + 0x54) != 0)) {
            pSVar15 = param_1->method;
            max = param_1->mode;
            param_1->s3->flags = param_1->s3->flags | 0x80;
            (*pSVar15->ssl_get_message)(param_1,0x1130,0x1131,-1,max,local_2c);
            psVar12 = param_1->s3;
            psVar12->flags = psVar12->flags & 0xffffff7f;
            if (local_2c[0] != 0) {
              (psVar12->tmp).reuse_message = 1;
              if ((psVar12->tmp).message_type == 0x14) {
                param_1->hit = 1;
                param_1->init_num = 0;
                uVar2 = 0;
                param_1->state = 0x11d0;
                goto LAB_0004b242;
              }
              if (psVar12->change_cipher_spec == 0) goto LAB_0004b4b8;
              ERR_put_error(0x14,0x153,0x85,"s3_clnt.c",0xdb9);
              ssl3_send_alert(param_1,2,10);
            }
LAB_0004b4b0:
            iVar3 = -1;
            goto LAB_0004b334;
          }
          psVar12 = param_1->s3;
LAB_0004b4b8:
          pSVar9 = (psVar12->tmp).new_cipher;
          if (((pSVar9->algorithm_auth & 0x404) == 0) &&
             (uVar16 = pSVar9->algorithm_mkey & 0x100, uVar16 == 0)) {
            iVar3 = ssl3_get_server_certificate(param_1);
            if (iVar3 < 1) goto LAB_0004b334;
            uVar2 = param_1->tlsext_status_type;
            if (uVar2 == 0) {
              psVar12 = param_1->s3;
              param_1->state = 0x1140;
            }
            else {
              psVar12 = param_1->s3;
              param_1->state = 0x11f0;
              uVar2 = uVar16;
            }
          }
          else {
            param_1->state = 0x1140;
            uVar2 = 1;
          }
          param_1->init_num = 0;
        }
      }
      else if (iVar6 < 0x1152) {
        if (iVar6 < 0x1150) {
          if (1 < iVar6 - 0x1140U) goto LAB_0004b318;
          iVar3 = ssl3_get_key_exchange(param_1);
          if (iVar3 < 1) goto LAB_0004b334;
          param_1->state = 0x1150;
          param_1->init_num = 0;
          iVar3 = ssl3_check_cert_and_algorithm(param_1);
          if (iVar3 == 0) goto LAB_0004b3b4;
LAB_0004b042:
          psVar12 = param_1->s3;
          uVar2 = 0;
        }
        else {
          iVar3 = ssl3_get_certificate_request(param_1);
          if (iVar3 < 1) goto LAB_0004b334;
          param_1->init_num = 0;
          psVar12 = param_1->s3;
          uVar2 = 0;
          param_1->state = 0x1160;
        }
      }
      else {
        if (iVar6 < 0x1160) goto LAB_0004b318;
        if (iVar6 < 0x1162) {
          iVar3 = (*param_1->method->ssl_get_message)(param_1,0x1160,0x1161,0xe,0x1e,local_2c);
          if (local_2c[0] == 0) {
            if (iVar3 < 1) goto LAB_0004b334;
          }
          else if (0 < iVar3) {
            iVar3 = -1;
            ssl3_send_alert(param_1,2,0x32);
            ERR_put_error(0x14,0x91,0x9f,"s3_clnt.c",0x92b);
            param_1->state = 5;
            goto LAB_0004b334;
          }
          psVar12 = param_1->s3;
          if ((int)(((psVar12->tmp).new_cipher)->algorithm_mkey << 0x15) < 0) {
            iVar3 = SRP_Calc_A_param(param_1);
            if (iVar3 < 1) {
              ERR_put_error(0x14,0x84,0x169,"s3_clnt.c",0x192);
              ssl3_send_alert(param_1,2,0x50);
              param_1->state = 5;
              goto LAB_0004b334;
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
          if (3 < iVar6 - 0x1170U) goto LAB_0004b318;
          iVar3 = ssl3_send_client_certificate(param_1);
          if (iVar3 < 1) goto LAB_0004b334;
          param_1->init_num = 0;
          psVar12 = param_1->s3;
          uVar2 = 0;
          param_1->state = 0x1180;
        }
      }
    }
    else {
      iVar3 = ssl3_send_client_key_exchange(param_1);
      if (iVar3 < 1) goto LAB_0004b334;
      psVar12 = param_1->s3;
      iVar3 = psVar12->flags;
      if ((psVar12->tmp).cert_req == 1) {
        iVar7 = 0x1190;
      }
      else {
        iVar7 = 0x11a0;
      }
      param_1->state = iVar7;
      bVar18 = iVar3 << 0x1b < 0;
      if (bVar18) {
        iVar7 = 0x11a0;
      }
      if (bVar18) {
        param_1->state = iVar7;
      }
LAB_0004b500:
      param_1->init_num = 0;
      uVar2 = 0;
    }
  }
  else {
    if (iVar6 < 0x11e2) {
      if (0x11df < iVar6) {
        iVar3 = ssl3_get_new_session_ticket(param_1);
        if (0 < iVar3) {
          param_1->init_num = 0;
          psVar12 = param_1->s3;
          uVar2 = 0;
          param_1->state = 0x11d0;
          goto LAB_0004b242;
        }
        goto LAB_0004b334;
      }
      if (0x11a1 < iVar6) {
        if (0x11af < iVar6) {
          if (iVar6 < 0x11b2) {
            psVar17 = param_1->method->ssl3_enc;
            iVar3 = ssl3_send_finished(param_1,0x11b0,0x11b1,*(undefined4 *)(psVar17 + 0x20),
                                       *(undefined4 *)(psVar17 + 0x24));
            if (0 < iVar3) {
              psVar12 = param_1->s3;
              iVar3 = param_1->hit;
              param_1->state = 0x1100;
              uVar16 = psVar12->flags;
              uVar2 = uVar16 & 0xfffffffb;
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
                if ((int)(uVar16 << 0x1e) < 0) {
                  param_1->state = 3;
                  psVar12->flags = uVar2 | 4;
                  psVar12->delay_buf_pop_ret = 0;
                }
              }
              goto LAB_0004b500;
            }
            goto LAB_0004b334;
          }
          if (iVar6 - 0x11d0U < 2) {
            psVar12 = param_1->s3;
            if (psVar12->change_cipher_spec == 0) {
              psVar12->flags = psVar12->flags | 0x80;
            }
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
              goto LAB_0004b242;
            }
            goto LAB_0004b334;
          }
        }
LAB_0004b318:
        iVar3 = -1;
        ERR_put_error(0x14,0x84,0xff,"s3_clnt.c",0x281);
        goto LAB_0004b334;
      }
      if (0x119f < iVar6) {
        iVar3 = ssl3_send_change_cipher_spec(param_1,0x11a0);
        if (0 < iVar3) {
          psVar12 = param_1->s3;
          pSVar10 = param_1->session;
          pSVar9 = (psVar12->tmp).new_cipher;
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
          *(SSL_CIPHER **)(pSVar10->krb5_client_princ + 0x24) = pSVar9;
          if (pSVar8 != (SSL_COMP *)0x0) {
            pSVar8 = (SSL_COMP *)pSVar8->id;
          }
          pSVar15 = param_1->method;
          *(SSL_COMP **)(pSVar10->krb5_client_princ + 0x20) = pSVar8;
          iVar3 = (**(code **)(pSVar15->ssl3_enc + 8))(param_1);
          if ((iVar3 != 0) &&
             (iVar3 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x12), iVar3 != 0))
          goto LAB_0004b042;
          goto LAB_0004b3b4;
        }
        goto LAB_0004b334;
      }
      if (1 < iVar6 - 0x1190U) goto LAB_0004b318;
      iVar3 = ssl3_send_client_verify(param_1);
      if (iVar3 < 1) goto LAB_0004b334;
      param_1->init_num = 0;
      param_1->state = 0x11a0;
      uVar2 = (param_1->s3->tmp).reuse_message;
      goto joined_r0x0004afd8;
    }
    if (iVar6 < 0x1202) {
      if (0x11ff < iVar6) {
        if (iVar6 == 0x1200) {
          uVar2 = (uint)*(byte *)&param_1->next_proto_negotiated;
          pcVar14 = param_1->init_buf->data;
          __n = 0x20 - (uVar2 + 2 & 0x1f);
          pcVar14[4] = *(byte *)&param_1->next_proto_negotiated;
          memcpy(pcVar14 + 5,param_1->initial_ctx,uVar2);
          pcVar14[uVar2 + 5] = (char)__n;
          memset(pcVar14 + uVar2 + 6,0,__n);
          pcVar14[1] = '\0';
          *pcVar14 = 'C';
          pcVar14[3] = (char)(uVar2 + 2) + (char)__n;
          pcVar14[2] = (char)(uVar2 + __n + 2 >> 8);
          param_1->init_num = uVar2 + __n + 6;
          param_1->state = 0x1201;
          param_1->init_off = 0;
        }
        iVar3 = ssl3_do_write(param_1,0x16);
        if (0 < iVar3) {
          psVar12 = param_1->s3;
          param_1->state = 0x11b0;
          uVar2 = 0;
          goto LAB_0004b242;
        }
        goto LAB_0004b334;
      }
      if (1 < iVar6 - 0x11f0U) goto LAB_0004b318;
      iVar3 = ssl3_get_cert_status(param_1);
      if (iVar3 < 1) goto LAB_0004b334;
      param_1->init_num = 0;
      psVar12 = param_1->s3;
      uVar2 = 0;
      param_1->state = 0x1140;
    }
    else {
      if ((iVar6 != 0x4000) && (iVar6 != 0x5000)) {
        if (iVar6 != 0x3004) goto LAB_0004b318;
        param_1->tlsext_hb_seq = 1;
        param_1->state = 0x1000;
        *(int *)(param_1->psk_server_callback + 0x38) =
             *(int *)(param_1->psk_server_callback + 0x38) + 1;
      }
LAB_0004b1d4:
      param_1->server = 0;
      if (p_Var13 != (_func_3152 *)0x0) {
        (*p_Var13)(param_1,0x10,1);
      }
      if ((param_1->version & 0xff00U) != 0x300) {
        iVar3 = -1;
        ERR_put_error(0x14,0x84,0x44,"s3_clnt.c",0xf0);
        param_1->state = 5;
        goto LAB_0004b334;
      }
      param_1->type = 0x1000;
      if (param_1->init_buf == (BUF_MEM *)0x0) {
        str = BUF_MEM_new();
        if (str == (BUF_MEM *)0x0) goto LAB_0004b3b4;
        iVar3 = BUF_MEM_grow(str,0x4000);
        if (iVar3 == 0) {
          param_1->state = 5;
          param_1->in_handshake = param_1->in_handshake + -1;
          BUF_MEM_free(str);
          iVar3 = -1;
          goto LAB_0004b188;
        }
        param_1->init_buf = str;
      }
      iVar3 = ssl3_setup_buffers(param_1);
      if (iVar3 == 0) goto LAB_0004b4b0;
      iVar3 = ssl_init_wbio_buffer(param_1,0);
      if (iVar3 == 0) {
LAB_0004b3b4:
        iVar3 = -1;
        param_1->state = 5;
        goto LAB_0004b334;
      }
      ssl3_init_finished_mac(param_1);
      psVar12 = param_1->s3;
      uVar2 = 0;
      param_1->state = 0x1110;
      uVar16 = psVar12->flags;
      *(int *)(param_1->psk_server_callback + 0x34) =
           *(int *)(param_1->psk_server_callback + 0x34) + 1;
      param_1->init_num = 0;
      psVar12->change_cipher_spec = 0;
      psVar12->flags = uVar16 & 0xffffff7f;
    }
  }
LAB_0004b242:
  uVar2 = uVar2 | (psVar12->tmp).reuse_message;
joined_r0x0004afd8:
  if (uVar2 == 0) {
    if ((param_1->ctx != (SSL_CTX *)0x0) &&
       (iVar3 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0), iVar3 < 1)) goto LAB_0004b334;
    if (p_Var13 == (_func_3152 *)0x0) {
      iVar3 = param_1->state;
    }
    else {
      iVar3 = param_1->state;
      if (iVar6 != iVar3) {
        param_1->state = iVar6;
        (*p_Var13)(param_1,0x1001,1);
        param_1->state = iVar3;
      }
    }
  }
  else {
    iVar3 = param_1->state;
  }
  goto LAB_0004af12;
}

