
/* WARNING: Could not reconcile some variable overlaps */

void ssl23_connect(SSL *param_1)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  stack_st_SSL_CIPHER *psVar7;
  int iVar8;
  _STACK *p_Var9;
  void *pvVar10;
  SSL_METHOD *pSVar11;
  BUF_MEM *str;
  time_t tVar12;
  undefined4 *puVar13;
  uint uVar14;
  undefined4 uVar15;
  _func_3057 *p_Var16;
  SSL_CTX *pSVar17;
  size_t sVar18;
  ssl2_state_st *psVar19;
  _func_3149 *p_Var20;
  uint uVar21;
  byte *pbVar22;
  _func_3152 *p_Var23;
  int version;
  int iVar24;
  uint uVar25;
  ssl3_state_st *psVar26;
  byte *pbVar27;
  _func_3150 *p_Var28;
  undefined4 uVar29;
  int iVar30;
  _func_3152 *p_Var31;
  int iVar32;
  undefined4 uVar33;
  bool bVar34;
  undefined4 in_stack_ffffff98;
  undefined4 in_stack_ffffff9c;
  int local_50;
  byte *local_4c;
  byte local_48;
  time_t local_38;
  undefined4 local_34;
  undefined2 local_30;
  byte local_2e;
  int local_2c;
  
  local_2c = __TMC_END__;
  local_38 = time((time_t *)0x0);
  RAND_add(&local_38,4,(double)CONCAT44(in_stack_ffffff9c,in_stack_ffffff98));
  ERR_clear_error();
  piVar3 = __errno_location();
  p_Var31 = param_1->info_callback;
  *piVar3 = 0;
  if (p_Var31 == (_func_3152 *)0x0) {
    p_Var31 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar4 = SSL_state(param_1);
  if (((uVar4 & 0x3000) == 0) || (iVar5 = SSL_state(param_1), iVar5 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  iVar5 = param_1->state;
  do {
    iVar32 = iVar5;
    if (iVar32 < 0x1212) {
      if (iVar32 < 0x1210) {
        if ((iVar32 != 0x1000) && (iVar32 != 0x1003)) goto LAB_00054446;
        goto LAB_000544cc;
      }
      uVar25 = param_1->references;
      param_1->shutdown = 0;
      uVar4 = uVar25 & 0x1000000;
      iVar5 = iVar32;
      if (uVar4 == 0) {
        p_Var9 = (_STACK *)SSL_get_ciphers(param_1);
        for (; iVar5 = sk_num(p_Var9), (int)uVar4 < iVar5; uVar4 = uVar4 + 1) {
          pvVar10 = sk_value(p_Var9,uVar4);
          iVar24 = *(int *)((int)pvVar10 + 0x1c);
          if (iVar24 == 1) {
            iVar5 = param_1->state;
            uVar4 = 0x1000000;
            uVar21 = 0x3000000;
            uVar6 = 0x7000000;
            uVar14 = 0x17000000;
            goto LAB_00054578;
          }
        }
        iVar5 = param_1->state;
      }
      uVar4 = 0;
      uVar21 = 0x2000000;
      iVar24 = 0;
      uVar6 = 0x6000000;
      uVar14 = 0x16000000;
LAB_00054578:
      if ((int)(uVar25 << 4) < 0) {
        version = 0x303;
        if (uVar14 != (uVar14 & uVar25)) {
          version = 0x302;
        }
      }
      else {
        version = 0x303;
      }
      if (((int)(uVar25 << 3) < 0) && ((uVar6 & uVar25) != uVar6)) {
        version = 0x301;
      }
      if (((int)(uVar25 << 5) < 0) && ((uVar21 & uVar25) != uVar21)) {
        version = 0x300;
      }
      if (((int)(uVar25 << 6) < 0) && ((uVar25 & uVar4) != uVar4)) {
        version = 2;
        pbVar22 = (byte *)param_1->init_buf->data;
        if (iVar5 != 0x1210) goto LAB_0005475e;
LAB_000545d6:
        psVar26 = param_1->s3;
        if ((int)(param_1->options << 0x1a) < 0) {
          tVar12 = time((time_t *)0x0);
          psVar26->client_random[3] = (uchar)tVar12;
          psVar26->client_random[0] = (uchar)((uint)tVar12 >> 0x18);
          psVar26->client_random[1] = (uchar)((uint)tVar12 >> 0x10);
          psVar26->client_random[2] = (uchar)((uint)tVar12 >> 8);
          iVar5 = RAND_pseudo_bytes(psVar26->client_random + 4,0x1c);
        }
        else {
          iVar5 = RAND_pseudo_bytes(psVar26->client_random,0x20);
        }
        if (iVar5 < 1) goto LAB_00054974;
        if (version == 0x303) {
          local_50 = 3;
          local_48 = 3;
        }
        else if (version == 0x302) {
          local_50 = 2;
          local_48 = 3;
        }
        else if (version == 0x301) {
          local_50 = 1;
          local_48 = 3;
        }
        else if (version == 0x300) {
          local_50 = 0;
          local_48 = 3;
        }
        else {
          if (version != 2) {
            ERR_put_error(0x14,0x74,0xbf,"s23_clnt.c",0x1a3);
            goto LAB_00054974;
          }
          local_48 = 0;
          local_50 = version;
        }
        param_1->first_packet = version;
        if (iVar24 == 0) {
          pbVar22[9] = local_48;
          pbVar22[10] = (byte)local_50;
          pbVar27 = pbVar22 + 0x2e;
          psVar26 = param_1->s3;
          uVar33 = *(undefined4 *)(psVar26->client_random + 4);
          uVar29 = *(undefined4 *)(psVar26->client_random + 8);
          uVar15 = *(undefined4 *)(psVar26->client_random + 0xc);
          *(undefined4 *)(pbVar22 + 0xb) = *(undefined4 *)psVar26->client_random;
          *(undefined4 *)(pbVar22 + 0xf) = uVar33;
          *(undefined4 *)(pbVar22 + 0x13) = uVar29;
          *(undefined4 *)(pbVar22 + 0x17) = uVar15;
          uVar33 = *(undefined4 *)(psVar26->client_random + 0x14);
          uVar15 = *(undefined4 *)(psVar26->client_random + 0x1c);
          uVar29 = *(undefined4 *)(psVar26->client_random + 0x18);
          *(undefined4 *)(pbVar22 + 0x1b) = *(undefined4 *)(psVar26->client_random + 0x10);
          *(undefined4 *)(pbVar22 + 0x1f) = uVar33;
          *(undefined4 *)(pbVar22 + 0x27) = uVar15;
          *(undefined4 *)(pbVar22 + 0x23) = uVar29;
          pbVar22[0x2b] = 0;
          psVar7 = SSL_get_ciphers(param_1);
          iVar5 = ssl_cipher_list_to_bytes(param_1,psVar7,pbVar27,0x4f0a1);
          if (iVar5 == 0) {
            iVar5 = 0x1fb;
LAB_00054d3a:
            ERR_put_error(0x14,0x74,0xb5,"s23_clnt.c",iVar5);
          }
          else {
            pbVar22[0x2d] = (byte)iVar5;
            pbVar22[0x2c] = (byte)((uint)iVar5 >> 8);
            local_4c = pbVar27 + iVar5 + 1;
            if ((param_1->references << 0xe < 0) ||
               (*(_STACK **)(param_1->psk_server_callback + 0x98) == (_STACK *)0x0)) {
              pbVar27[iVar5] = 1;
            }
            else {
              iVar8 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
              pbVar27[iVar5] = (char)iVar8 + 1;
              pbVar27 = local_4c;
              iVar5 = iVar24;
              if (0 < iVar8) {
                do {
                  iVar30 = iVar5 + 1;
                  puVar13 = (undefined4 *)
                            sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),iVar5);
                  *pbVar27 = (byte)*puVar13;
                  pbVar27 = pbVar27 + 1;
                  iVar5 = iVar30;
                } while (iVar30 != iVar8);
                local_4c = local_4c + iVar30;
              }
            }
            *local_4c = 0;
            iVar5 = ssl_prepare_clienthello_tlsext(param_1);
            if (iVar5 < 1) {
              ERR_put_error(0x14,0x74,0xe2,"s23_clnt.c",0x220);
            }
            else {
              iVar5 = ssl_add_clienthello_tlsext(param_1,local_4c + 1,pbVar22 + 0x4000);
              if (iVar5 == 0) {
                iVar5 = 0x225;
              }
              else {
                pbVar22[5] = 1;
                iVar8 = iVar5 - (int)(pbVar22 + 9);
                pbVar22[8] = (byte)iVar8;
                uVar4 = iVar8 + 4;
                pbVar22[6] = (byte)((uint)iVar8 >> 0x10);
                pbVar22[7] = (byte)((uint)iVar8 >> 8);
                if (uVar4 < 0x4001) {
                  *pbVar22 = 0x16;
                  pbVar22[1] = local_48;
                  if ((param_1->first_packet >> 8 == 3) && (0x301 < param_1->first_packet)) {
                    local_50._0_1_ = 1;
                  }
                  pbVar22[2] = (byte)local_50;
                  pbVar22[4] = (byte)uVar4;
                  pbVar22[3] = (byte)(uVar4 >> 8);
                  param_1->init_num = iVar5 - (int)pbVar22;
                  param_1->init_off = 0;
                  ssl3_finish_mac(param_1,pbVar22 + 5,(iVar5 - (int)pbVar22) + -5);
                  goto LAB_000546e6;
                }
                iVar5 = 0x235;
              }
              ERR_put_error(0x14,0x74,0x44,"s23_clnt.c",iVar5);
            }
          }
          goto LAB_00054974;
        }
        pbVar22[3] = local_48;
        pbVar22[2] = 1;
        pbVar22[4] = (byte)local_50;
        pbVar27 = pbVar22 + 0xb;
        psVar7 = SSL_get_ciphers(param_1);
        iVar5 = ssl_cipher_list_to_bytes(param_1,psVar7,pbVar27,0);
        if (iVar5 == 0) {
          iVar5 = 0x1ba;
          goto LAB_00054d3a;
        }
        pbVar22[6] = (byte)iVar5;
        pbVar22[5] = (byte)((uint)iVar5 >> 8);
        pbVar22[7] = 0;
        pbVar22[8] = 0;
        uVar4 = param_1->references;
        pbVar22[9] = 0;
        uVar4 = uVar4 & 2;
        if (uVar4 != 0) {
          sVar18 = 0x10;
        }
        else {
          sVar18 = 0x20;
        }
        pbVar22[10] = (byte)sVar18;
        if (uVar4 != 0) {
          uVar4 = sVar18;
        }
        memset(param_1->s3->client_random,0,0x20);
        iVar8 = RAND_pseudo_bytes(param_1->s3->client_random + uVar4,sVar18);
        if (iVar8 < 1) goto LAB_00054974;
        memcpy(pbVar27 + iVar5,param_1->s3->client_random + uVar4,sVar18);
        pbVar27 = pbVar27 + iVar5 + (sVar18 - (int)(pbVar22 + 2));
        pbVar22[1] = (byte)pbVar27;
        *pbVar22 = (byte)((uint)pbVar27 >> 8) | 0x80;
        param_1->init_num = (int)(pbVar27 + 2);
        param_1->init_off = 0;
        ssl3_finish_mac(param_1,pbVar22 + 2);
LAB_000546e6:
        param_1->state = 0x1211;
        param_1->init_off = 0;
        iVar5 = ssl23_write_bytes(param_1);
        if (1 < iVar5) goto LAB_00054768;
LAB_000546fe:
        if (iVar5 != 1) goto LAB_000544ba;
LAB_00054702:
        param_1->init_num = 0;
        param_1->state = 0x1220;
      }
      else {
        if (param_1->tlsext_debug_arg != (void *)0x0) {
          iVar24 = 0;
        }
        if (param_1->servername_done != -1) {
          iVar24 = 0;
        }
        pbVar22 = (byte *)param_1->init_buf->data;
        if (iVar5 == 0x1210) goto LAB_000545d6;
LAB_0005475e:
        iVar5 = ssl23_write_bytes(param_1);
        if (iVar5 < 2) goto LAB_000546fe;
LAB_00054768:
        p_Var28 = param_1->msg_callback;
        if (p_Var28 == (_func_3150 *)0x0) goto LAB_00054702;
        if (iVar24 == 0) {
          (*p_Var28)(1,version,0x16,param_1->init_buf->data + 5,iVar5 - 5,param_1,
                     param_1->msg_callback_arg);
          param_1->init_num = 0;
          param_1->state = 0x1220;
        }
        else {
          (*p_Var28)(1,2,0,param_1->init_buf->data + 2,iVar5 - 2,param_1,param_1->msg_callback_arg);
          param_1->init_num = 0;
          param_1->state = 0x1220;
        }
      }
      pSVar17 = param_1->ctx;
    }
    else {
      if (iVar32 != 0x4000) {
        if (iVar32 < 0x4001) {
          if (iVar32 - 0x1220U < 2) {
            iVar5 = ssl23_read_bytes(param_1,7);
            if (iVar5 == 7) {
              puVar13 = (undefined4 *)param_1->packet;
              bVar1 = *(byte *)puVar13;
              local_34 = *puVar13;
              local_30 = *(undefined2 *)(puVar13 + 1);
              local_2e = *(byte *)((int)puVar13 + 6);
              if ((((-1 < (int)((uint)bVar1 << 0x18)) || (*(byte *)((int)puVar13 + 2) != 4)) ||
                  (*(byte *)((int)puVar13 + 5) != 0)) || (local_2e != 2)) {
                if ((*(byte *)((int)puVar13 + 1) == 3) &&
                   (bVar2 = *(byte *)((int)puVar13 + 2), bVar2 < 4)) {
                  if (bVar1 == 0x16) {
                    bVar1 = *(byte *)((int)puVar13 + 5);
                  }
                  else {
                    if ((bVar1 != 0x15) || (*(byte *)((int)puVar13 + 3) != 0)) goto LAB_000549e0;
                    bVar1 = *(byte *)(puVar13 + 1);
                  }
                  if (bVar1 == 2) {
                    if (bVar2 == 0) {
                      if (param_1->references << 6 < 0) goto LAB_000549b2;
                      param_1->version = 0x300;
                      pSVar11 = SSLv3_client_method();
                      param_1->method = pSVar11;
                    }
                    else if (bVar2 == 1) {
                      if (param_1->references << 5 < 0) goto LAB_000549b2;
                      param_1->version = 0x301;
                      pSVar11 = TLSv1_client_method();
                      param_1->method = pSVar11;
                    }
                    else if (bVar2 == 2) {
                      if (param_1->references << 3 < 0) {
LAB_000549b2:
                        iVar5 = 0x2df;
                        goto LAB_000549ba;
                      }
                      param_1->version = 0x302;
                      pSVar11 = TLSv1_1_client_method();
                      param_1->method = pSVar11;
                    }
                    else {
                      if ((bVar2 != 3) || (param_1->references << 4 < 0)) goto LAB_000549b2;
                      param_1->version = 0x303;
                      pSVar11 = TLSv1_2_client_method();
                      param_1->method = pSVar11;
                    }
                    if ((*(byte *)puVar13 != 0x15) || (*(byte *)((int)puVar13 + 5) == 1)) {
                      iVar5 = ssl_init_wbio_buffer(param_1,1);
                      if (iVar5 == 0) goto LAB_00054974;
                      param_1->rstate = 0xf0;
                      param_1->state = 0x1120;
                      puVar13 = (undefined4 *)(param_1->s3->rbuf).buf;
                      param_1->packet_length = 7;
                      if (puVar13 == (undefined4 *)0x0) {
                        iVar5 = ssl3_setup_read_buffer(param_1);
                        if (iVar5 == 0) goto LAB_00054974;
                        puVar13 = (undefined4 *)(param_1->s3->rbuf).buf;
                      }
                      param_1->packet = (uchar *)puVar13;
                      *puVar13 = local_34;
                      *(undefined2 *)(puVar13 + 1) = local_30;
                      *(byte *)((int)puVar13 + 6) = local_2e;
                      psVar26 = param_1->s3;
                      p_Var16 = param_1->method->ssl_connect;
                      (psVar26->rbuf).left = 7;
                      (psVar26->rbuf).offset = 0;
                      param_1->handshake_func = (_func_3149 *)p_Var16;
                      goto LAB_000548cc;
                    }
                    p_Var23 = param_1->info_callback;
                    if ((p_Var23 != (_func_3152 *)0x0) ||
                       (p_Var23 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
                       p_Var23 != (_func_3152 *)0x0)) {
                      (*p_Var23)(param_1,0x4004,
                                 (int)CONCAT11(*(byte *)((int)puVar13 + 5),
                                               *(byte *)((int)puVar13 + 6)));
                    }
                    if (param_1->msg_callback != (_func_3150 *)0x0) {
                      (*param_1->msg_callback)
                                (0,param_1->version,0x15,(byte *)((int)puVar13 + 5),2,param_1,
                                 param_1->msg_callback_arg);
                    }
                    param_1->rwstate = 1;
                    ERR_put_error(0x14,0x77,*(byte *)((int)puVar13 + 6) + 1000,"s23_clnt.c",0x2fa);
                    goto LAB_00054974;
                  }
                }
LAB_000549e0:
                ERR_put_error(0x14,0x77,0xfc,"s23_clnt.c",0x313);
                goto LAB_00054974;
              }
              if (param_1->references << 7 < 0) {
                iVar5 = 0x27d;
LAB_000549ba:
                ERR_put_error(0x14,0x77,0x102,"s23_clnt.c",iVar5);
                goto LAB_00054974;
              }
              if (param_1->s2 == (ssl2_state_st *)0x0) {
                iVar5 = ssl2_new(param_1);
                if (iVar5 == 0) goto LAB_00054974;
              }
              else {
                ssl2_clear();
              }
              psVar19 = param_1->s2;
              psVar26 = param_1->s3;
              if ((param_1->references & 2U) == 0) {
                sVar18 = 0x20;
              }
              else {
                sVar18 = 0x10;
              }
              psVar19->challenge_length = sVar18;
              memcpy(psVar19->challenge,(void *)((0xe0 - sVar18) + (int)psVar26),sVar18);
              if (param_1->s3 != (ssl3_state_st *)0x0) {
                ssl3_free(param_1);
              }
              iVar5 = BUF_MEM_grow_clean(param_1->init_buf,0x3fff);
              if (iVar5 == 0) {
                ERR_put_error(0x14,0x77,7,"s23_clnt.c",0x29d);
                goto LAB_00054974;
              }
              iVar5 = 0x1020;
              bVar34 = param_1->first_packet != 2;
              psVar19 = param_1->s2;
              param_1->state = 0x1020;
              if (bVar34) {
                iVar5 = 1;
              }
              if (bVar34) {
                psVar19->ssl2_rollback = iVar5;
              }
              puVar13 = (undefined4 *)psVar19->rbuf;
              param_1->rstate = 0xf0;
              param_1->packet = (uchar *)puVar13;
              param_1->packet_length = 7;
              *puVar13 = local_34;
              *(undefined2 *)(puVar13 + 1) = local_30;
              *(byte *)((int)puVar13 + 6) = local_2e;
              psVar19 = param_1->s2;
              psVar19->rbuf_left = 7;
              psVar19->rbuf_offs = 0;
              psVar19->write_sequence = 1;
              pSVar11 = SSLv2_client_method();
              p_Var20 = (_func_3149 *)pSVar11->ssl_connect;
              param_1->method = pSVar11;
              param_1->handshake_func = p_Var20;
LAB_000548cc:
              param_1->init_num = 0;
              iVar5 = ssl_get_new_session(param_1);
              if (iVar5 == 0) {
LAB_00054974:
                iVar5 = -1;
LAB_000544ba:
                param_1->in_handshake = param_1->in_handshake + -1;
LAB_0005446a:
                if (p_Var31 != (_func_3152 *)0x0) {
                  (*p_Var31)(param_1,0x1002,iVar5);
                }
                if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
                  __stack_chk_fail(iVar5);
                }
                return;
              }
              iVar5 = SSL_connect(param_1);
            }
            p_Var31 = (_func_3152 *)((uint)p_Var31 & iVar5 >> 0x1f);
            goto LAB_000544ba;
          }
        }
        else if (iVar32 == 0x5000) goto LAB_000544cc;
LAB_00054446:
        iVar5 = -1;
        ERR_put_error(0x14,0x75,0xff,"s23_clnt.c",0xe8);
        param_1->in_handshake = param_1->in_handshake + -1;
        goto LAB_0005446a;
      }
LAB_000544cc:
      if (param_1->session != (SSL_SESSION *)0x0) {
        iVar5 = -1;
        ERR_put_error(0x14,0x75,0xdd,"s23_clnt.c",0xb2);
        goto LAB_000544ba;
      }
      param_1->server = 0;
      if (p_Var31 != (_func_3152 *)0x0) {
        (*p_Var31)(param_1,0x10,1);
      }
      param_1->type = 0x1000;
      if (param_1->init_buf == (BUF_MEM *)0x0) {
        str = BUF_MEM_new();
        if (str == (BUF_MEM *)0x0) goto LAB_00054974;
        iVar5 = BUF_MEM_grow(str,0x4000);
        if (iVar5 == 0) {
          iVar5 = -1;
          param_1->in_handshake = param_1->in_handshake + -1;
          BUF_MEM_free(str);
          goto LAB_0005446a;
        }
        param_1->init_buf = str;
      }
      iVar5 = ssl3_setup_buffers(param_1);
      if (iVar5 == 0) goto LAB_00054974;
      ssl3_init_finished_mac(param_1);
      param_1->state = 0x1210;
      *(int *)(param_1->psk_server_callback + 0x34) =
           *(int *)(param_1->psk_server_callback + 0x34) + 1;
      pSVar17 = param_1->ctx;
      param_1->init_num = 0;
    }
    if (pSVar17 != (SSL_CTX *)0x0) {
      BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
    }
    iVar5 = param_1->state;
    if ((p_Var31 != (_func_3152 *)0x0) && (iVar5 != iVar32)) {
      param_1->state = iVar32;
      (*p_Var31)(param_1,0x1001,1);
      param_1->state = iVar5;
    }
  } while( true );
}

