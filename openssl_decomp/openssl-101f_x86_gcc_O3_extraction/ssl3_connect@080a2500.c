
int ssl3_connect(SSL *param_1)

{
  byte bVar1;
  _func_3154 *p_Var2;
  ssl3_enc_method *psVar3;
  SSL_COMP *pSVar4;
  SSL_SESSION *pSVar5;
  SSL_CIPHER *pSVar6;
  char *pcVar7;
  SSL_CTX *pSVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  BIO *pBVar12;
  uint uVar13;
  long lVar14;
  BUF_MEM *str;
  uint uVar15;
  ssl3_state_st *psVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  uint uVar19;
  int in_GS_OFFSET;
  byte bVar20;
  int iVar21;
  _func_3152 *local_3c;
  time_t local_28;
  int local_24;
  int local_20;
  
  bVar20 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = time((time_t *)0x0);
  RAND_add(&local_28,4,0.0);
  ERR_clear_error();
  piVar9 = __errno_location();
  *piVar9 = 0;
  local_3c = param_1->info_callback;
  if (local_3c == (_func_3152 *)0x0) {
    local_3c = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar10 = SSL_state(param_1);
  if (((uVar10 & 0x3000) == 0) || (uVar10 = SSL_state(param_1), (uVar10 & 0x4000) != 0)) {
    SSL_clear(param_1);
  }
  if (param_1->tlsext_heartbeat != 0) {
    param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
    param_1->tlsext_heartbeat = 0;
  }
LAB_080a25a0:
  iVar11 = param_1->state;
LAB_080a25a3:
  iVar21 = iVar11;
  if (iVar21 < 0x1182) {
    if (iVar21 < 0x1180) {
      if (iVar21 < 0x1132) {
        if (0x112f < iVar21) {
          if (*(int *)(param_1->session->krb5_client_princ + 0x54) == 0) {
            psVar16 = param_1->s3;
          }
          else {
            iVar11 = (*param_1->method->ssl_get_message)
                               (param_1,0x1130,0x1131,-1,param_1->mode,&local_24);
            if (local_24 == 0) {
              if (iVar11 < 1) goto LAB_080a296e;
              psVar16 = param_1->s3;
              if (iVar11 == 2) goto LAB_080a2e33;
            }
            else {
              psVar16 = param_1->s3;
              (psVar16->tmp).reuse_message = 1;
              if (((psVar16->tmp).message_type & 0xffffffefU) == 4) {
LAB_080a2e33:
                param_1->hit = 1;
                param_1->init_num = 0;
                param_1->state = (-(uint)(param_1->tlsext_ocsp_resplen == 0) & 0xfffffff0) + 0x11e0;
                uVar10 = 0;
                goto LAB_080a2a78;
              }
            }
          }
          pSVar6 = (psVar16->tmp).new_cipher;
          if (((*(byte *)&pSVar6->algorithm_auth & 4) == 0) &&
             ((*(byte *)((int)&pSVar6->algorithm_mkey + 1) & 1) == 0)) {
            iVar11 = ssl3_get_server_certificate(param_1);
            if (iVar11 < 1) goto LAB_080a296e;
            if (param_1->tlsext_status_type == 0) {
              param_1->state = 0x1140;
              psVar16 = param_1->s3;
              uVar10 = 0;
            }
            else {
              param_1->state = 0x11f0;
              psVar16 = param_1->s3;
              uVar10 = 0;
            }
          }
          else {
            param_1->state = 0x1140;
            uVar10 = 1;
          }
          param_1->init_num = 0;
          goto LAB_080a2a78;
        }
        if (iVar21 == 0x1100) {
          param_1->rwstate = 2;
          lVar14 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
          if (0 < lVar14) {
            psVar16 = param_1->s3;
            param_1->rwstate = 1;
            param_1->state = (psVar16->tmp).next_state;
            uVar10 = 0;
            goto LAB_080a2a78;
          }
          goto LAB_080a2bf1;
        }
        if (iVar21 < 0x1101) {
          if ((iVar21 == 0x1000) || (iVar21 == 0x1003)) goto LAB_080a29df;
          if (iVar21 == 3) {
            ssl3_cleanup_key_block(param_1);
            if (param_1->init_buf != (BUF_MEM *)0x0) {
              BUF_MEM_free(param_1->init_buf);
              param_1->init_buf = (BUF_MEM *)0x0;
            }
            if ((*(byte *)&param_1->s3->flags & 4) == 0) {
              ssl_free_wbio_buffer(param_1);
            }
            param_1->init_num = 0;
            param_1->tlsext_hb_seq = 0;
            param_1->new_session = 0;
            ssl_update_cache(param_1,1);
            p_Var2 = param_1->psk_server_callback;
            if (param_1->hit != 0) {
              piVar9 = (int *)(p_Var2 + 0x58);
              *piVar9 = *piVar9 + 1;
            }
            param_1->handshake_func = ssl3_connect;
            piVar9 = (int *)(p_Var2 + 0x3c);
            *piVar9 = *piVar9 + 1;
            iVar11 = 1;
            if (local_3c != (_func_3152 *)0x0) {
              (*local_3c)(param_1,0x20,1);
            }
            goto LAB_080a296e;
          }
        }
        else if (0x110f < iVar21) {
          if (iVar21 < 0x1112) {
            param_1->shutdown = 0;
            iVar11 = ssl3_client_hello(param_1);
            if (0 < iVar11) {
              param_1->state = 0x1120;
              param_1->init_num = 0;
              if (param_1->bbio == param_1->wbio) goto LAB_080a278d;
              pBVar12 = BIO_push(param_1->bbio,param_1->wbio);
              psVar16 = param_1->s3;
              param_1->wbio = pBVar12;
              uVar10 = 0;
              goto LAB_080a2a78;
            }
          }
          else {
            if (1 < iVar21 - 0x1120U) goto LAB_080a2bd0;
            iVar11 = ssl3_get_server_hello(param_1);
            if (0 < iVar11) {
              if (param_1->hit == 0) {
                param_1->state = 0x1130;
              }
              else {
                param_1->state = 0x11d0;
                if (param_1->tlsext_ocsp_resplen != 0) {
                  param_1->state = 0x11e0;
                }
              }
              goto LAB_080a2c7b;
            }
          }
          goto LAB_080a296e;
        }
      }
      else {
        if (iVar21 < 0x1152) {
          if (iVar21 < 0x1150) {
            if (1 < iVar21 - 0x1140U) goto LAB_080a2bd0;
            iVar11 = ssl3_get_key_exchange(param_1);
            if (0 < iVar11) {
              param_1->state = 0x1150;
              param_1->init_num = 0;
              iVar11 = ssl3_check_cert_and_algorithm(param_1);
              if (iVar11 == 0) goto LAB_080a2bf1;
LAB_080a278d:
              psVar16 = param_1->s3;
              uVar10 = 0;
              goto LAB_080a2a78;
            }
          }
          else {
            iVar11 = ssl3_get_certificate_request(param_1);
            if (0 < iVar11) {
              param_1->state = 0x1160;
LAB_080a2c7b:
              param_1->init_num = 0;
              psVar16 = param_1->s3;
              uVar10 = 0;
              goto LAB_080a2a78;
            }
          }
          goto LAB_080a296e;
        }
        if (0x115f < iVar21) {
          if (iVar21 < 0x1162) {
            iVar11 = (*param_1->method->ssl_get_message)(param_1,0x1160,0x1161,0xe,0x1e,&local_24);
            if (local_24 == 0) {
              if (0 < iVar11) {
                psVar16 = param_1->s3;
                bVar1 = *(byte *)((int)&((psVar16->tmp).new_cipher)->algorithm_mkey + 1);
                goto joined_r0x080a2f21;
              }
            }
            else {
              if (iVar11 < 1) {
                psVar16 = param_1->s3;
                bVar1 = *(byte *)((int)&((psVar16->tmp).new_cipher)->algorithm_mkey + 1);
joined_r0x080a2f21:
                if ((bVar1 & 4) != 0) {
                  iVar11 = SRP_Calc_A_param(param_1);
                  if (iVar11 < 1) {
                    ERR_put_error(0x14,0x84,0x169,"s3_clnt.c",0x186);
                    ssl3_send_alert(param_1,2,0x50);
                    goto LAB_080a296e;
                  }
                  psVar16 = param_1->s3;
                }
                iVar11 = (psVar16->tmp).cert_req;
                param_1->init_num = 0;
                param_1->state = (-(uint)(iVar11 == 0) & 0x10) + 0x1170;
                uVar10 = 0;
                goto LAB_080a2a78;
              }
              iVar11 = -1;
              ssl3_send_alert(param_1,2,0x32);
              ERR_put_error(0x14,0x91,0x9f,"s3_clnt.c",0x8a0);
            }
            goto LAB_080a296e;
          }
          if (iVar21 - 0x1170U < 4) {
            iVar11 = ssl3_send_client_certificate(param_1);
            if (0 < iVar11) {
              param_1->state = 0x1180;
              param_1->init_num = 0;
              uVar10 = 0;
              psVar16 = param_1->s3;
              goto LAB_080a2a78;
            }
            goto LAB_080a296e;
          }
        }
      }
LAB_080a2bd0:
      iVar21 = 0x26a;
      iVar11 = 0xff;
LAB_080a2be2:
      ERR_put_error(0x14,0x84,iVar11,"s3_clnt.c",iVar21);
LAB_080a2bf1:
      iVar11 = -1;
    }
    else {
      iVar11 = ssl3_send_client_key_exchange(param_1);
      if (0 < iVar11) {
        psVar16 = param_1->s3;
        if ((psVar16->tmp).cert_req == 1) {
          param_1->state = 0x1190;
        }
        else {
          param_1->state = 0x11a0;
          psVar16->change_cipher_spec = 0;
        }
        if ((*(byte *)&psVar16->flags & 0x10) == 0) {
LAB_080a2b4a:
          param_1->init_num = 0;
          uVar10 = 0;
        }
        else {
          param_1->state = 0x11a0;
          uVar10 = 0;
          psVar16->change_cipher_spec = 0;
          param_1->init_num = 0;
        }
        goto LAB_080a2a78;
      }
    }
  }
  else {
    if (0x11e1 < iVar21) {
      if (0x1201 < iVar21) {
        if ((iVar21 != 0x4000) && (iVar21 != 0x5000)) {
          if (iVar21 != 0x3004) goto LAB_080a2bd0;
          param_1->tlsext_hb_seq = 1;
          param_1->state = 0x1000;
          *(int *)(param_1->psk_server_callback + 0x38) =
               *(int *)(param_1->psk_server_callback + 0x38) + 1;
        }
LAB_080a29df:
        param_1->server = 0;
        if (local_3c != (_func_3152 *)0x0) {
          (*local_3c)(param_1,0x10,1);
        }
        if ((param_1->version & 0xff00U) != 0x300) {
          iVar21 = 0xef;
          iVar11 = 0x44;
          goto LAB_080a2be2;
        }
        param_1->type = 0x1000;
        if (param_1->init_buf == (BUF_MEM *)0x0) {
          str = BUF_MEM_new();
          if (str == (BUF_MEM *)0x0) goto LAB_080a2bf1;
          iVar11 = BUF_MEM_grow(str,0x4000);
          if (iVar11 == 0) {
            param_1->in_handshake = param_1->in_handshake + -1;
            iVar11 = -1;
            BUF_MEM_free(str);
            goto LAB_080a2972;
          }
          param_1->init_buf = str;
        }
        iVar11 = ssl3_setup_buffers(param_1);
        if ((iVar11 != 0) && (iVar11 = ssl_init_wbio_buffer(param_1,0), iVar11 != 0)) {
          ssl3_init_finished_mac(param_1);
          psVar16 = param_1->s3;
          param_1->state = 0x1110;
          *(int *)(param_1->psk_server_callback + 0x34) =
               *(int *)(param_1->psk_server_callback + 0x34) + 1;
          param_1->init_num = 0;
          uVar10 = 0;
          goto LAB_080a2a78;
        }
        goto LAB_080a2bf1;
      }
      if (iVar21 < 0x1200) {
        if (1 < iVar21 - 0x11f0U) goto LAB_080a2bd0;
        iVar11 = ssl3_get_cert_status(param_1);
        if (0 < iVar11) {
          param_1->state = 0x1140;
          param_1->init_num = 0;
          uVar10 = 0;
          psVar16 = param_1->s3;
          goto LAB_080a2a78;
        }
        goto LAB_080a296e;
      }
      if (iVar21 == 0x1200) {
        bVar1 = *(byte *)&param_1->next_proto_negotiated;
        uVar10 = (uint)bVar1;
        iVar11 = -(uVar10 + 2 & 0x1f);
        uVar13 = iVar11 + 0x20;
        pcVar7 = param_1->init_buf->data;
        pcVar7[4] = bVar1;
        pSVar8 = param_1->initial_ctx;
        if (uVar10 < 4) {
          if ((uVar10 != 0) && (pcVar7[5] = *(char *)&pSVar8->method, (bVar1 & 2) != 0)) {
            *(undefined2 *)(pcVar7 + uVar10 + 3) = *(undefined2 *)((int)pSVar8 + (uVar10 - 2));
          }
        }
        else {
          *(SSL_METHOD **)(pcVar7 + 5) = pSVar8->method;
          *(undefined4 *)(pcVar7 + uVar10 + 1) = *(undefined4 *)((int)pSVar8 + (uVar10 - 4));
          puVar17 = (undefined4 *)
                    ((int)pSVar8 -
                    (int)(pcVar7 + (5 - (int)(undefined4 *)((uint)(pcVar7 + 9) & 0xfffffffc))));
          puVar18 = (undefined4 *)((uint)(pcVar7 + 9) & 0xfffffffc);
          for (uVar15 = (uint)(pcVar7 + (5 - (int)(undefined4 *)((uint)(pcVar7 + 9) & 0xfffffffc)) +
                              uVar10) >> 2; uVar15 != 0; uVar15 = uVar15 - 1) {
            *puVar18 = *puVar17;
            puVar17 = puVar17 + (uint)bVar20 * -2 + 1;
            puVar18 = puVar18 + (uint)bVar20 * -2 + 1;
          }
        }
        pcVar7[uVar10 + 5] = (char)uVar13;
        puVar17 = (undefined4 *)(pcVar7 + uVar10 + 6);
        if (uVar13 < 4) {
          if ((uVar13 != 0) && (*(undefined *)puVar17 = 0, (uVar13 & 2) != 0)) {
            *(undefined2 *)((int)puVar17 + iVar11 + 0x1e) = 0;
          }
        }
        else {
          *puVar17 = 0;
          *(undefined4 *)((int)puVar17 + iVar11 + 0x1c) = 0;
          uVar15 = (uint)((int)puVar17 + (uVar13 - ((uint)(puVar17 + 1) & 0xfffffffc))) & 0xfffffffc
          ;
          if (3 < uVar15) {
            uVar19 = 0;
            do {
              *(undefined4 *)(((uint)(puVar17 + 1) & 0xfffffffc) + uVar19) = 0;
              uVar19 = uVar19 + 4;
            } while (uVar19 < uVar15);
          }
        }
        *pcVar7 = 'C';
        pcVar7[1] = '\0';
        pcVar7[2] = (char)(uVar10 + uVar13 + 2 >> 8);
        pcVar7[3] = bVar1 + 2 + (char)uVar13;
        param_1->state = 0x1201;
        param_1->init_num = uVar10 + uVar13 + 6;
        param_1->init_off = 0;
      }
      iVar11 = ssl3_do_write(param_1,0x16);
      if (iVar11 < 1) goto LAB_080a296e;
      param_1->state = 0x11b0;
      psVar16 = param_1->s3;
      uVar10 = 0;
LAB_080a2a78:
      if ((uVar10 | (psVar16->tmp).reuse_message) != 0) goto LAB_080a25a0;
LAB_080a26e8:
      if ((param_1->ctx != (SSL_CTX *)0x0) &&
         (iVar11 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0), iVar11 < 1)) goto LAB_080a296e;
      if (local_3c == (_func_3152 *)0x0) {
        iVar11 = param_1->state;
      }
      else {
        iVar11 = param_1->state;
        if (iVar11 != iVar21) {
          param_1->state = iVar21;
          (*local_3c)(param_1,0x1001,1);
          param_1->state = iVar11;
        }
      }
      goto LAB_080a25a3;
    }
    if (iVar21 < 0x11e0) {
      if (iVar21 < 0x11a2) {
        if (iVar21 < 0x11a0) {
          if (1 < iVar21 - 0x1190U) goto LAB_080a2bd0;
          iVar11 = ssl3_send_client_verify(param_1);
          if (iVar11 < 1) goto LAB_080a296e;
          param_1->state = 0x11a0;
          param_1->init_num = 0;
          iVar11 = (param_1->s3->tmp).reuse_message;
          param_1->s3->change_cipher_spec = 0;
          if (iVar11 == 0) goto LAB_080a26e8;
          goto LAB_080a25a0;
        }
        iVar11 = ssl3_send_change_cipher_spec(param_1,0x11a0,0x11a1);
        if (0 < iVar11) {
          psVar16 = param_1->s3;
          iVar11 = psVar16->next_proto_neg_seen;
          pSVar6 = (psVar16->tmp).new_cipher;
          pSVar4 = (psVar16->tmp).new_compression;
          param_1->init_num = 0;
          param_1->state = (-(uint)(iVar11 == 0) & 0xffffffb0) + 0x1200;
          pSVar5 = param_1->session;
          *(SSL_CIPHER **)(pSVar5->krb5_client_princ + 0x24) = pSVar6;
          if (pSVar4 == (SSL_COMP *)0x0) {
            iVar11 = 0;
          }
          else {
            iVar11 = pSVar4->id;
          }
          *(int *)(pSVar5->krb5_client_princ + 0x20) = iVar11;
          iVar11 = (**(code **)(param_1->method->ssl3_enc + 8))(param_1);
          if ((iVar11 != 0) &&
             (iVar11 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x12), iVar11 != 0))
          goto LAB_080a278d;
          goto LAB_080a2bf1;
        }
      }
      else {
        if (iVar21 < 0x11b0) goto LAB_080a2bd0;
        if (iVar21 < 0x11b2) {
          psVar3 = param_1->method->ssl3_enc;
          iVar11 = ssl3_send_finished(param_1,0x11b0,0x11b1,*(undefined4 *)(psVar3 + 0x20),
                                      *(undefined4 *)(psVar3 + 0x24));
          if (0 < iVar11) {
            psVar16 = param_1->s3;
            iVar11 = param_1->hit;
            param_1->state = 0x1100;
            uVar10 = psVar16->flags;
            uVar13 = uVar10 & 0xfffffffb;
            psVar16->flags = uVar13;
            if (iVar11 != 0) {
              (psVar16->tmp).next_state = 3;
              if ((uVar10 & 2) != 0) {
                param_1->state = 3;
                psVar16->delay_buf_pop_ret = 0;
                psVar16->flags = uVar13 | 4;
              }
              goto LAB_080a2b4a;
            }
            (psVar16->tmp).next_state =
                 (-(uint)(param_1->tlsext_ocsp_resplen == 0) & 0xfffffff0) + 0x11e0;
            param_1->init_num = 0;
            uVar10 = 0;
            goto LAB_080a2a78;
          }
        }
        else {
          if (1 < iVar21 - 0x11d0U) goto LAB_080a2bd0;
          iVar11 = ssl3_get_finished(param_1,0x11d0,0x11d1);
          if (0 < iVar11) {
            param_1->init_num = 0;
            psVar16 = param_1->s3;
            param_1->state = (-(uint)(param_1->hit == 0) & 0xffffee63) + 0x11a0;
            uVar10 = 0;
            goto LAB_080a2a78;
          }
        }
      }
    }
    else {
      iVar11 = ssl3_get_new_session_ticket(param_1);
      if (0 < iVar11) {
        param_1->state = 0x11d0;
        param_1->init_num = 0;
        uVar10 = 0;
        psVar16 = param_1->s3;
        goto LAB_080a2a78;
      }
    }
  }
LAB_080a296e:
  param_1->in_handshake = param_1->in_handshake + -1;
LAB_080a2972:
  if (local_3c != (_func_3152 *)0x0) {
    (*local_3c)(param_1,0x1002,iVar11);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar11;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

