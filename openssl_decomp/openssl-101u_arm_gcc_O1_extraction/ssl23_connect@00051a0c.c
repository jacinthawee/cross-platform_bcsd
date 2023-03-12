
/* WARNING: Could not reconcile some variable overlaps */

void ssl23_connect(SSL *param_1)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  _STACK *p_Var6;
  void *pvVar7;
  stack_st_SSL_CIPHER *psVar8;
  int iVar9;
  SSL_METHOD *pSVar10;
  BUF_MEM *str;
  undefined4 *puVar11;
  time_t tVar12;
  _func_3057 *p_Var13;
  undefined4 uVar14;
  SSL_CTX *pSVar15;
  size_t __n;
  int iVar16;
  _func_3152 *p_Var17;
  byte *pbVar18;
  uint uVar19;
  int version;
  _func_3150 *p_Var20;
  ssl3_state_st *psVar21;
  byte *pbVar22;
  undefined4 uVar23;
  int iVar24;
  _func_3152 *p_Var25;
  int iVar26;
  undefined4 uVar27;
  bool bVar28;
  undefined4 in_stack_ffffff98;
  undefined4 in_stack_ffffff9c;
  uint local_4c;
  byte *local_48;
  time_t local_38;
  undefined4 local_34;
  undefined2 local_30;
  byte local_2e;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  local_38 = time((time_t *)0x0);
  RAND_add(&local_38,4,(double)CONCAT44(in_stack_ffffff9c,in_stack_ffffff98));
  ERR_clear_error();
  piVar3 = __errno_location();
  p_Var25 = param_1->info_callback;
  *piVar3 = 0;
  if (p_Var25 == (_func_3152 *)0x0) {
    p_Var25 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar4 = SSL_state(param_1);
  if (((uVar4 & 0x3000) == 0) || (iVar5 = SSL_state(param_1), iVar5 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  iVar5 = param_1->state;
  do {
    iVar26 = iVar5;
    if (iVar26 < 0x1212) {
      if (iVar26 < 0x1210) {
        if ((iVar26 != 0x1000) && (iVar26 != 0x1003)) goto LAB_00051a96;
        goto LAB_00051b1c;
      }
      uVar4 = param_1->references;
      param_1->shutdown = 0;
      uVar19 = uVar4 & 0x1000000;
      if (uVar19 == 0) {
        p_Var6 = (_STACK *)SSL_get_ciphers(param_1);
        for (; iVar5 = sk_num(p_Var6), (int)uVar19 < iVar5; uVar19 = uVar19 + 1) {
          pvVar7 = sk_value(p_Var6,uVar19);
          iVar16 = *(int *)((int)pvVar7 + 0x1c);
          if (iVar16 == 1) {
            iVar5 = param_1->state;
            goto LAB_00051bb8;
          }
        }
        iVar5 = param_1->state;
        iVar16 = 0;
      }
      else {
        iVar16 = 0;
        iVar5 = iVar26;
      }
LAB_00051bb8:
      if ((int)(uVar4 << 4) < 0) {
        if ((uVar4 & 0x16000000) == 0x16000000) {
          version = 0x303;
        }
        else {
          version = 0x302;
        }
      }
      else {
        version = 0x303;
      }
      local_4c = uVar4 & 0x10000000;
      if (local_4c != 0) {
        bVar28 = (uVar4 & 0x6000000) != 0x6000000;
        if (bVar28) {
          version = 0x301;
        }
        local_4c = (uint)bVar28;
      }
      if (((int)(uVar4 << 5) < 0) && ((uVar4 & 0x2000000) != 0x2000000)) {
        version = 0x300;
        local_4c._0_1_ = 0;
      }
      if (param_1->tlsext_debug_arg != (void *)0x0) {
        iVar16 = 0;
      }
      pbVar18 = (byte *)param_1->init_buf->data;
      if (param_1->servername_done != -1) {
        iVar16 = 0;
      }
      if (iVar5 == 0x1210) {
        iVar5 = ssl_get_new_session(param_1,0);
        if (iVar5 == 0) goto LAB_00051f68;
        psVar21 = param_1->s3;
        if ((int)(param_1->options << 0x1a) < 0) {
          tVar12 = time((time_t *)0x0);
          psVar21->client_random[3] = (uchar)tVar12;
          psVar21->client_random[0] = (uchar)((uint)tVar12 >> 0x18);
          psVar21->client_random[1] = (uchar)((uint)tVar12 >> 0x10);
          psVar21->client_random[2] = (uchar)((uint)tVar12 >> 8);
          iVar5 = RAND_bytes(psVar21->client_random + 4,0x1c);
        }
        else {
          iVar5 = RAND_bytes(psVar21->client_random,0x20);
        }
        if (iVar5 < 1) goto LAB_00051f68;
        if (version == 0x303) {
          local_4c._0_1_ = 3;
        }
        else if (version == 0x302) {
          local_4c._0_1_ = 2;
        }
        param_1->first_packet = version;
        if (iVar16 == 0) {
          pbVar18[9] = 3;
          pbVar18[10] = (byte)local_4c;
          pbVar22 = pbVar18 + 0x2e;
          psVar21 = param_1->s3;
          uVar27 = *(undefined4 *)(psVar21->client_random + 4);
          uVar23 = *(undefined4 *)(psVar21->client_random + 8);
          uVar14 = *(undefined4 *)(psVar21->client_random + 0xc);
          *(undefined4 *)(pbVar18 + 0xb) = *(undefined4 *)psVar21->client_random;
          *(undefined4 *)(pbVar18 + 0xf) = uVar27;
          *(undefined4 *)(pbVar18 + 0x13) = uVar23;
          *(undefined4 *)(pbVar18 + 0x17) = uVar14;
          uVar27 = *(undefined4 *)(psVar21->client_random + 0x14);
          uVar14 = *(undefined4 *)(psVar21->client_random + 0x1c);
          uVar23 = *(undefined4 *)(psVar21->client_random + 0x18);
          *(undefined4 *)(pbVar18 + 0x1b) = *(undefined4 *)(psVar21->client_random + 0x10);
          *(undefined4 *)(pbVar18 + 0x1f) = uVar27;
          *(undefined4 *)(pbVar18 + 0x27) = uVar14;
          *(undefined4 *)(pbVar18 + 0x23) = uVar23;
          pbVar18[0x2b] = 0;
          psVar8 = SSL_get_ciphers(param_1);
          iVar5 = ssl_cipher_list_to_bytes(param_1,psVar8,pbVar22,0x4c465);
          if (iVar5 != 0) {
            pbVar18[0x2d] = (byte)iVar5;
            pbVar18[0x2c] = (byte)((uint)iVar5 >> 8);
            local_48 = pbVar22 + iVar5 + 1;
            if ((param_1->references << 0xe < 0) ||
               (*(_STACK **)(param_1->psk_server_callback + 0x98) == (_STACK *)0x0)) {
              pbVar22[iVar5] = 1;
            }
            else {
              iVar9 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
              pbVar22[iVar5] = (char)iVar9 + 1;
              pbVar22 = local_48;
              iVar5 = iVar16;
              if (0 < iVar9) {
                do {
                  iVar24 = iVar5 + 1;
                  puVar11 = (undefined4 *)
                            sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),iVar5);
                  *pbVar22 = (byte)*puVar11;
                  pbVar22 = pbVar22 + 1;
                  iVar5 = iVar24;
                } while (iVar24 != iVar9);
                local_48 = local_48 + iVar24;
              }
            }
            *local_48 = 0;
            iVar5 = ssl_prepare_clienthello_tlsext(param_1);
            if (iVar5 < 1) {
              ERR_put_error(0x14,0x74,0xe2,"s23_clnt.c",0x21a);
            }
            else {
              iVar5 = ssl_add_clienthello_tlsext(param_1,local_48 + 1,pbVar18 + 0x4000);
              if (iVar5 == 0) {
                iVar5 = 0x222;
              }
              else {
                iVar9 = iVar5 - (int)(pbVar18 + 9);
                uVar4 = iVar9 + 4;
                pbVar18[8] = (byte)iVar9;
                pbVar18[5] = 1;
                pbVar18[6] = (byte)((uint)iVar9 >> 0x10);
                pbVar18[7] = (byte)((uint)iVar9 >> 8);
                if (uVar4 < 0x4001) {
                  *pbVar18 = 0x16;
                  pbVar18[1] = 3;
                  if ((param_1->first_packet >> 8 == 3) && (0x301 < param_1->first_packet)) {
                    local_4c._0_1_ = 1;
                  }
                  pbVar18[2] = (byte)local_4c;
                  pbVar18[4] = (byte)uVar4;
                  pbVar18[3] = (byte)(uVar4 >> 8);
                  param_1->init_num = iVar5 - (int)pbVar18;
                  param_1->init_off = 0;
                  ssl3_finish_mac(param_1,pbVar18 + 5,(iVar5 - (int)pbVar18) + -5);
                  goto LAB_00051dfc;
                }
                iVar5 = 0x231;
              }
              ERR_put_error(0x14,0x74,0x44,"s23_clnt.c",iVar5);
            }
            goto LAB_00051f68;
          }
          iVar5 = 0x1f6;
        }
        else {
          pbVar18[2] = 1;
          pbVar18[4] = (byte)local_4c;
          pbVar18[3] = 3;
          pbVar22 = pbVar18 + 0xb;
          psVar8 = SSL_get_ciphers(param_1);
          iVar5 = ssl_cipher_list_to_bytes(param_1,psVar8,pbVar22,0);
          if (iVar5 != 0) {
            pbVar18[6] = (byte)iVar5;
            pbVar18[5] = (byte)((uint)iVar5 >> 8);
            pbVar18[7] = 0;
            pbVar18[8] = 0;
            uVar4 = param_1->references;
            pbVar18[9] = 0;
            uVar4 = uVar4 & 2;
            if (uVar4 != 0) {
              __n = 0x10;
            }
            else {
              __n = 0x20;
            }
            pbVar18[10] = (byte)__n;
            if (uVar4 != 0) {
              uVar4 = __n;
            }
            memset(param_1->s3->client_random,0,0x20);
            iVar9 = RAND_bytes(param_1->s3->client_random + uVar4,__n);
            if (0 < iVar9) {
              memcpy(pbVar22 + iVar5,param_1->s3->client_random + uVar4,__n);
              pbVar22 = pbVar22 + iVar5 + (__n - (int)(pbVar18 + 2));
              pbVar18[1] = (byte)pbVar22;
              *pbVar18 = (byte)((uint)pbVar22 >> 8) | 0x80;
              param_1->init_num = (int)(pbVar22 + 2);
              param_1->init_off = 0;
              ssl3_finish_mac(param_1);
LAB_00051dfc:
              param_1->init_off = 0;
              param_1->state = 0x1211;
              iVar5 = ssl23_write_bytes(param_1);
              goto joined_r0x00051e12;
            }
            goto LAB_00051f68;
          }
          iVar5 = 0x1b2;
        }
        ERR_put_error(0x14,0x74,0xb5,"s23_clnt.c",iVar5);
        goto LAB_00051f68;
      }
      iVar5 = ssl23_write_bytes(param_1);
joined_r0x00051e12:
      if (iVar5 < 2) {
        if (iVar5 != 1) goto LAB_00051b0a;
LAB_00051c64:
        param_1->init_num = 0;
        param_1->state = 0x1220;
      }
      else {
        p_Var20 = param_1->msg_callback;
        if (p_Var20 == (_func_3150 *)0x0) goto LAB_00051c64;
        if (iVar16 != 0) {
          (*p_Var20)(1,2,0,param_1->init_buf->data + 2,iVar5 - 2,param_1,param_1->msg_callback_arg);
          goto LAB_00051c64;
        }
        (*p_Var20)(1,version,0x16,param_1->init_buf->data + 5,iVar5 - 5,param_1,
                   param_1->msg_callback_arg);
        param_1->init_num = 0;
        param_1->state = 0x1220;
      }
      pSVar15 = param_1->ctx;
    }
    else {
      if (iVar26 != 0x4000) {
        if (iVar26 < 0x4001) {
          if (iVar26 - 0x1220U < 2) {
            iVar5 = ssl23_read_bytes(param_1,7);
            if (iVar5 != 7) {
LAB_00051b06:
              p_Var25 = (_func_3152 *)((uint)p_Var25 & iVar5 >> 0x1f);
              goto LAB_00051b0a;
            }
            puVar11 = (undefined4 *)param_1->packet;
            bVar1 = *(byte *)puVar11;
            local_34 = *puVar11;
            local_30 = *(undefined2 *)(puVar11 + 1);
            local_2e = *(byte *)((int)puVar11 + 6);
            if (((((int)((uint)bVar1 << 0x18) < 0) && (*(byte *)((int)puVar11 + 2) == 4)) &&
                (*(byte *)((int)puVar11 + 5) == 0)) && (local_2e == 2)) {
              iVar5 = 0x272;
LAB_000520c0:
              ERR_put_error(0x14,0x77,0x102,"s23_clnt.c",iVar5);
              goto LAB_00051f68;
            }
            if ((*(byte *)((int)puVar11 + 1) == 3) &&
               (bVar2 = *(byte *)((int)puVar11 + 2), bVar2 < 4)) {
              if (bVar1 == 0x16) {
                bVar1 = *(byte *)((int)puVar11 + 5);
              }
              else {
                if ((bVar1 != 0x15) || (*(byte *)((int)puVar11 + 3) != 0)) goto LAB_0005213c;
                bVar1 = *(byte *)(puVar11 + 1);
              }
              if (bVar1 == 2) {
                if (bVar2 == 0) {
                  if (param_1->references << 6 < 0) goto LAB_000520b8;
                  param_1->version = 0x300;
                  pSVar10 = SSLv3_client_method();
                  param_1->method = pSVar10;
                }
                else if (bVar2 == 1) {
                  if (param_1->references << 5 < 0) goto LAB_000520b8;
                  param_1->version = 0x301;
                  pSVar10 = TLSv1_client_method();
                  param_1->method = pSVar10;
                }
                else if (bVar2 == 2) {
                  if (param_1->references << 3 < 0) {
LAB_000520b8:
                    iVar5 = 0x2d6;
                    goto LAB_000520c0;
                  }
                  param_1->version = 0x302;
                  pSVar10 = TLSv1_1_client_method();
                  param_1->method = pSVar10;
                }
                else {
                  if ((bVar2 != 3) || (param_1->references << 4 < 0)) goto LAB_000520b8;
                  param_1->version = 0x303;
                  pSVar10 = TLSv1_2_client_method();
                  param_1->method = pSVar10;
                }
                iVar5 = param_1->version;
                param_1->session->ssl_version = iVar5;
                if (0x303 < iVar5) {
                  OpenSSLDie("s23_clnt.c",0x2dd,"s->version <= TLS_MAX_VERSION");
                }
                if ((*(byte *)puVar11 == 0x15) && (*(byte *)((int)puVar11 + 5) != 1)) {
                  p_Var17 = param_1->info_callback;
                  if ((p_Var17 != (_func_3152 *)0x0) ||
                     (p_Var17 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
                     p_Var17 != (_func_3152 *)0x0)) {
                    (*p_Var17)(param_1,0x4004,
                               (int)CONCAT11(*(byte *)((int)puVar11 + 5),*(byte *)((int)puVar11 + 6)
                                            ));
                  }
                  if (param_1->msg_callback != (_func_3150 *)0x0) {
                    (*param_1->msg_callback)
                              (0,param_1->version,0x15,(byte *)((int)puVar11 + 5),2,param_1,
                               param_1->msg_callback_arg);
                  }
                  param_1->rwstate = 1;
                  ERR_put_error(0x14,0x77,*(byte *)((int)puVar11 + 6) + 1000,"s23_clnt.c",0x2f5);
LAB_00051f68:
                  iVar5 = -1;
LAB_00051b0a:
                  param_1->in_handshake = param_1->in_handshake + -1;
LAB_00051aba:
                  if (p_Var25 != (_func_3152 *)0x0) {
                    (*p_Var25)(param_1,0x1002,iVar5);
                  }
                  if (local_2c == __stack_chk_guard) {
                    return;
                  }
                    /* WARNING: Subroutine does not return */
                  __stack_chk_fail(iVar5);
                }
                iVar5 = ssl_init_wbio_buffer(param_1,1);
                if (iVar5 == 0) goto LAB_00051f68;
                param_1->rstate = 0xf0;
                param_1->state = 0x1120;
                puVar11 = (undefined4 *)(param_1->s3->rbuf).buf;
                param_1->packet_length = 7;
                if (puVar11 == (undefined4 *)0x0) {
                  iVar5 = ssl3_setup_read_buffer(param_1);
                  if (iVar5 == 0) goto LAB_00051f68;
                  puVar11 = (undefined4 *)(param_1->s3->rbuf).buf;
                }
                param_1->packet = (uchar *)puVar11;
                *puVar11 = local_34;
                *(undefined2 *)(puVar11 + 1) = local_30;
                *(byte *)((int)puVar11 + 6) = local_2e;
                psVar21 = param_1->s3;
                p_Var13 = param_1->method->ssl_connect;
                (psVar21->rbuf).left = 7;
                (psVar21->rbuf).offset = 0;
                param_1->handshake_func = (_func_3149 *)p_Var13;
                param_1->init_num = 0;
                iVar5 = SSL_connect(param_1);
                goto LAB_00051b06;
              }
            }
LAB_0005213c:
            ERR_put_error(0x14,0x77,0xfc,"s23_clnt.c",0x30e);
            goto LAB_00051f68;
          }
        }
        else if (iVar26 == 0x5000) goto LAB_00051b1c;
LAB_00051a96:
        iVar5 = -1;
        ERR_put_error(0x14,0x75,0xff,"s23_clnt.c",0xeb);
        param_1->in_handshake = param_1->in_handshake + -1;
        goto LAB_00051aba;
      }
LAB_00051b1c:
      if (param_1->session != (SSL_SESSION *)0x0) {
        iVar5 = -1;
        ERR_put_error(0x14,0x75,0xdd,"s23_clnt.c",0xb2);
        goto LAB_00051b0a;
      }
      param_1->server = 0;
      if (p_Var25 != (_func_3152 *)0x0) {
        (*p_Var25)(param_1,0x10,1);
      }
      param_1->type = 0x1000;
      if (param_1->init_buf == (BUF_MEM *)0x0) {
        str = BUF_MEM_new();
        if (str == (BUF_MEM *)0x0) goto LAB_00051f68;
        iVar5 = BUF_MEM_grow(str,0x4000);
        if (iVar5 == 0) {
          iVar5 = -1;
          param_1->in_handshake = param_1->in_handshake + -1;
          BUF_MEM_free(str);
          goto LAB_00051aba;
        }
        param_1->init_buf = str;
      }
      iVar5 = ssl3_setup_buffers(param_1);
      if (iVar5 == 0) goto LAB_00051f68;
      ssl3_init_finished_mac(param_1);
      param_1->state = 0x1210;
      *(int *)(param_1->psk_server_callback + 0x34) =
           *(int *)(param_1->psk_server_callback + 0x34) + 1;
      pSVar15 = param_1->ctx;
      param_1->init_num = 0;
    }
    if (pSVar15 != (SSL_CTX *)0x0) {
      BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
    }
    iVar5 = param_1->state;
    if ((p_Var25 != (_func_3152 *)0x0) && (iVar5 != iVar26)) {
      param_1->state = iVar26;
      (*p_Var25)(param_1,0x1001,1);
      param_1->state = iVar5;
    }
  } while( true );
}

