
int ssl23_connect(SSL *param_1)

{
  char cVar1;
  SSL_CTX *pSVar2;
  _func_3150 *p_Var3;
  byte *pbVar4;
  ssl3_state_st *psVar5;
  _func_3057 *p_Var6;
  bool bVar7;
  _func_3152 *p_Var8;
  int *piVar9;
  uint uVar10;
  _STACK *p_Var11;
  void *pvVar12;
  stack_st_SSL_CIPHER *psVar13;
  undefined4 *puVar14;
  uint uVar15;
  int iVar16;
  uchar *puVar17;
  undefined *puVar18;
  SSL_METHOD *pSVar19;
  BUF_MEM *str;
  byte *pbVar20;
  time_t tVar21;
  uint uVar22;
  _func_3152 *p_Var23;
  uint uVar24;
  int iVar25;
  int in_GS_OFFSET;
  bool bVar26;
  byte bVar27;
  int iVar28;
  int iVar29;
  _func_3152 *local_50;
  byte *local_44;
  byte local_40;
  time_t local_2c;
  undefined4 local_28;
  undefined2 local_24;
  uchar local_22;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = time((time_t *)0x0);
  RAND_add(&local_2c,4,0.0);
  ERR_clear_error();
  piVar9 = __errno_location();
  *piVar9 = 0;
  local_50 = param_1->info_callback;
  if (local_50 == (_func_3152 *)0x0) {
    local_50 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar10 = SSL_state(param_1);
  if (((uVar10 & 0x3000) == 0) || (uVar10 = SSL_state(param_1), (uVar10 & 0x4000) != 0)) {
    SSL_clear(param_1);
  }
  iVar25 = param_1->state;
  do {
    iVar28 = iVar25;
    p_Var8 = local_50;
    if (0x1211 < iVar28) {
      if (iVar28 == 0x4000) goto LAB_080a91ac;
      if (iVar28 < 0x4001) {
        if (iVar28 - 0x1220U < 2) {
          iVar25 = ssl23_read_bytes(param_1,7);
          if (iVar25 == 7) {
            puVar14 = (undefined4 *)param_1->packet;
            local_28 = *puVar14;
            local_24 = *(undefined2 *)(puVar14 + 1);
            local_22 = *(uchar *)((int)puVar14 + 6);
            cVar1 = *(char *)puVar14;
            if ((cVar1 < '\0') && (*(char *)((int)puVar14 + 2) == '\x04')) {
              if ((*(char *)((int)puVar14 + 5) == '\0') && (*(char *)((int)puVar14 + 6) == '\x02'))
              {
                iVar25 = 0x272;
LAB_080a9a06:
                ERR_put_error(0x14,0x77,0x102,"s23_clnt.c",iVar25);
                goto LAB_080a9a20;
              }
            }
            else if ((*(char *)((int)puVar14 + 1) == '\x03') &&
                    (bVar27 = *(byte *)((int)puVar14 + 2), bVar27 < 4)) {
              if (cVar1 == '\x16') {
                cVar1 = *(char *)((int)puVar14 + 5);
              }
              else {
                if ((cVar1 != '\x15') || (*(char *)((int)puVar14 + 3) != '\0')) goto LAB_080a9b78;
                cVar1 = *(char *)(puVar14 + 1);
              }
              if (cVar1 == '\x02') {
                if (bVar27 == 0) {
                  if ((*(byte *)((int)&param_1->references + 3) & 2) != 0) goto LAB_080a99fe;
                  param_1->version = 0x300;
                  pSVar19 = SSLv3_client_method();
                  param_1->method = pSVar19;
                }
                else if (bVar27 == 1) {
                  if ((*(byte *)((int)&param_1->references + 3) & 4) != 0) goto LAB_080a99fe;
                  param_1->version = 0x301;
                  pSVar19 = TLSv1_client_method();
                  param_1->method = pSVar19;
                }
                else if (bVar27 == 2) {
                  if ((*(byte *)((int)&param_1->references + 3) & 0x10) != 0) goto LAB_080a99fe;
                  param_1->version = 0x302;
                  pSVar19 = TLSv1_1_client_method();
                  param_1->method = pSVar19;
                }
                else {
                  if ((*(byte *)((int)&param_1->references + 3) & 8) != 0) {
LAB_080a99fe:
                    iVar25 = 0x2d6;
                    goto LAB_080a9a06;
                  }
                  param_1->version = 0x303;
                  pSVar19 = TLSv1_2_client_method();
                  param_1->method = pSVar19;
                }
                iVar25 = param_1->version;
                param_1->session->ssl_version = iVar25;
                if (0x303 < iVar25) {
                  OpenSSLDie("s23_clnt.c",0x2dd,"s->version <= TLS_MAX_VERSION");
                }
                if ((*(char *)puVar14 == '\x15') && (*(char *)((int)puVar14 + 5) != '\x01')) {
                  p_Var23 = param_1->info_callback;
                  if ((p_Var23 != (_func_3152 *)0x0) ||
                     (p_Var23 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
                     p_Var23 != (_func_3152 *)0x0)) {
                    (*p_Var23)(param_1,0x4004,
                               (uint)(*(short *)((int)puVar14 + 5) << 8) |
                               (uint)(byte)((ushort)*(short *)((int)puVar14 + 5) >> 8));
                  }
                  if (param_1->msg_callback != (_func_3150 *)0x0) {
                    (*param_1->msg_callback)
                              (0,param_1->version,0x15,(char *)((int)puVar14 + 5),2,param_1,
                               param_1->msg_callback_arg);
                  }
                  param_1->rwstate = 1;
                  ERR_put_error(0x14,0x77,*(byte *)((int)puVar14 + 6) + 1000,"s23_clnt.c",0x2f5);
                }
                else {
                  iVar25 = ssl_init_wbio_buffer(param_1,1);
                  if (iVar25 != 0) {
                    param_1->state = 0x1120;
                    param_1->rstate = 0xf0;
                    param_1->packet_length = 7;
                    puVar14 = (undefined4 *)(param_1->s3->rbuf).buf;
                    if (puVar14 == (undefined4 *)0x0) {
                      iVar25 = ssl3_setup_read_buffer(param_1);
                      if (iVar25 == 0) goto LAB_080a9a20;
                      puVar14 = (undefined4 *)(param_1->s3->rbuf).buf;
                    }
                    param_1->packet = (uchar *)puVar14;
                    *puVar14 = local_28;
                    *(undefined2 *)(puVar14 + 1) = local_24;
                    *(uchar *)((int)puVar14 + 6) = local_22;
                    psVar5 = param_1->s3;
                    (psVar5->rbuf).left = 7;
                    (psVar5->rbuf).offset = 0;
                    p_Var6 = param_1->method->ssl_connect;
                    param_1->init_num = 0;
                    param_1->handshake_func = (_func_3149 *)p_Var6;
                    iVar25 = SSL_connect(param_1);
                    goto LAB_080a9154;
                  }
                }
                goto LAB_080a9a20;
              }
            }
LAB_080a9b78:
            ERR_put_error(0x14,0x77,0xfc,"s23_clnt.c",0x30e);
            goto LAB_080a9a20;
          }
LAB_080a9154:
          p_Var8 = (_func_3152 *)0x0;
          if (iVar25 < 0) {
            p_Var8 = local_50;
          }
          goto LAB_080a9164;
        }
      }
      else if (iVar28 == 0x5000) goto LAB_080a91ac;
LAB_080a90e0:
      iVar29 = 0xeb;
      iVar28 = 0xff;
LAB_080a90f2:
      iVar25 = -1;
      ERR_put_error(0x14,0x75,iVar28,"s23_clnt.c",iVar29);
      goto LAB_080a9164;
    }
    if (iVar28 < 0x1210) {
      if ((iVar28 != 0x1000) && (iVar28 != 0x1003)) goto LAB_080a90e0;
LAB_080a91ac:
      if (param_1->session != (SSL_SESSION *)0x0) {
        iVar29 = 0xb2;
        iVar28 = 0xdd;
        goto LAB_080a90f2;
      }
      param_1->server = 0;
      if (local_50 != (_func_3152 *)0x0) {
        (*local_50)(param_1,0x10,1);
      }
      param_1->type = 0x1000;
      if (param_1->init_buf == (BUF_MEM *)0x0) {
        str = BUF_MEM_new();
        if (str == (BUF_MEM *)0x0) goto LAB_080a9a20;
        iVar25 = BUF_MEM_grow(str,0x4000);
        if (iVar25 == 0) {
          param_1->in_handshake = param_1->in_handshake + -1;
          iVar25 = -1;
          BUF_MEM_free(str);
          goto LAB_080a9168;
        }
        param_1->init_buf = str;
      }
      iVar25 = ssl3_setup_buffers(param_1);
      if (iVar25 == 0) goto LAB_080a9a20;
      ssl3_init_finished_mac(param_1);
      param_1->state = 0x1210;
      *(int *)(param_1->psk_server_callback + 0x34) =
           *(int *)(param_1->psk_server_callback + 0x34) + 1;
      pSVar2 = param_1->ctx;
      param_1->init_num = 0;
    }
    else {
      uVar10 = param_1->references;
      param_1->shutdown = 0;
      bVar26 = (uVar10 & 0x1000000) == 0;
      iVar25 = iVar28;
      if (bVar26) {
        p_Var11 = (_STACK *)SSL_get_ciphers(param_1);
        for (iVar25 = 0; iVar29 = sk_num(p_Var11), iVar25 < iVar29; iVar25 = iVar25 + 1) {
          pvVar12 = sk_value(p_Var11,iVar25);
          if (*(int *)((int)pvVar12 + 0x1c) == 1) {
            iVar25 = param_1->state;
            goto LAB_080a928a;
          }
        }
        iVar25 = param_1->state;
        bVar26 = false;
      }
LAB_080a928a:
      iVar29 = 0x303;
      if ((uVar10 & 0x8000000) != 0) {
        iVar29 = ((uVar10 & 0x16000000) == 0x16000000) + 0x302;
      }
      bVar27 = false;
      if (((uVar10 & 0x10000000) != 0) && (bVar27 = (uVar10 & 0x6000000) != 0x6000000, (bool)bVar27)
         ) {
        iVar29 = 0x301;
      }
      if ((uVar10 & 0x4000000) != 0) {
        if ((uVar10 & 0x2000000) == 0) {
          bVar27 = false;
        }
        if ((uVar10 & 0x2000000) != 0x2000000) {
          iVar29 = 0x300;
        }
      }
      bVar7 = false;
      if (param_1->tlsext_debug_arg == (void *)0x0) {
        bVar7 = bVar26;
      }
      bVar26 = false;
      if (param_1->servername_done == -1) {
        bVar26 = bVar7;
      }
      if (iVar25 == 0x1210) {
        pbVar4 = (byte *)param_1->init_buf->data;
        iVar25 = ssl_get_new_session(param_1,0);
        if (iVar25 != 0) {
          psVar5 = param_1->s3;
          if ((*(byte *)&param_1->options & 0x20) == 0) {
            iVar25 = RAND_bytes(psVar5->client_random,0x20);
          }
          else {
            tVar21 = time((time_t *)0x0);
            psVar5->client_random[0] = (uchar)((uint)tVar21 >> 0x18);
            psVar5->client_random[3] = (uchar)tVar21;
            psVar5->client_random[1] = (uchar)((uint)tVar21 >> 0x10);
            psVar5->client_random[2] = (uchar)((uint)tVar21 >> 8);
            iVar25 = RAND_bytes(psVar5->client_random + 4,0x1c);
          }
          if (0 < iVar25) {
            if (iVar29 == 0x303) {
              bVar27 = 3;
            }
            else if (iVar29 == 0x302) {
              bVar27 = 2;
            }
            param_1->first_packet = iVar29;
            if (bVar26) {
              pbVar4[2] = 1;
              pbVar4[3] = 3;
              pbVar4[4] = bVar27;
              psVar13 = SSL_get_ciphers(param_1);
              iVar25 = ssl_cipher_list_to_bytes(param_1,psVar13,pbVar4 + 0xb,0);
              if (iVar25 == 0) {
                iVar25 = 0x1b2;
LAB_080a9d16:
                ERR_put_error(0x14,0x74,0xb5,"s23_clnt.c",iVar25);
              }
              else {
                pbVar4[6] = (byte)iVar25;
                pbVar4[5] = (byte)((uint)iVar25 >> 8);
                pbVar4[7] = 0;
                pbVar4[8] = 0;
                uVar10 = param_1->references;
                puVar14 = (undefined4 *)(pbVar4 + 0xb + iVar25);
                pbVar4[9] = 0;
                uVar10 = uVar10 & 2;
                uVar22 = -(uint)(uVar10 == 0) & 0x10;
                iVar25 = uVar22 + 0x10;
                uVar15 = ~-(uint)(uVar10 == 0) & 0x10;
                pbVar4[10] = (-(uVar10 == 0) & 0x10U) + 0x10;
                psVar5 = param_1->s3;
                uVar24 = 0;
                *(undefined4 *)psVar5->client_random = 0;
                *(undefined4 *)(psVar5->client_random + 0x1c) = 0;
                uVar10 = (uint)(psVar5->client_random + 4) & 0xfffffffc;
                do {
                  *(undefined4 *)(uVar10 + uVar24) = 0;
                  uVar24 = uVar24 + 4;
                } while (uVar24 < ((int)psVar5 + (0xe0 - uVar10) & 0xfffffffc));
                iVar16 = RAND_bytes(param_1->s3->client_random + uVar15,iVar25);
                if (0 < iVar16) {
                  puVar17 = param_1->s3->client_random + uVar15;
                  *puVar14 = *(undefined4 *)puVar17;
                  *(undefined4 *)((int)puVar14 + uVar22 + 0xc) =
                       *(undefined4 *)(puVar17 + uVar22 + 0xc);
                  iVar16 = (int)puVar14 - ((uint)(puVar14 + 1) & 0xfffffffc);
                  uVar10 = 0;
                  do {
                    *(undefined4 *)(((uint)(puVar14 + 1) & 0xfffffffc) + uVar10) =
                         *(undefined4 *)(puVar17 + (uVar10 - iVar16));
                    uVar10 = uVar10 + 4;
                  } while (uVar10 < (iVar16 + iVar25 & 0xfffffffcU));
                  puVar18 = (undefined *)((int)puVar14 + (iVar25 - (int)(pbVar4 + 2)));
                  pbVar4[1] = (byte)puVar18;
                  *pbVar4 = (byte)((uint)puVar18 >> 8) | 0x80;
                  param_1->init_off = 0;
                  param_1->init_num = (int)(puVar18 + 2);
                  ssl3_finish_mac(param_1,pbVar4 + 2,puVar18);
LAB_080a99ce:
                  param_1->state = 0x1211;
                  param_1->init_off = 0;
                  goto LAB_080a9337;
                }
              }
            }
            else {
              pbVar4[9] = 3;
              pbVar4[10] = bVar27;
              psVar5 = param_1->s3;
              *(undefined4 *)(pbVar4 + 0xb) = *(undefined4 *)psVar5->client_random;
              *(undefined4 *)(pbVar4 + 0xf) = *(undefined4 *)(psVar5->client_random + 4);
              *(undefined4 *)(pbVar4 + 0x13) = *(undefined4 *)(psVar5->client_random + 8);
              *(undefined4 *)(pbVar4 + 0x17) = *(undefined4 *)(psVar5->client_random + 0xc);
              *(undefined4 *)(pbVar4 + 0x1b) = *(undefined4 *)(psVar5->client_random + 0x10);
              *(undefined4 *)(pbVar4 + 0x1f) = *(undefined4 *)(psVar5->client_random + 0x14);
              *(undefined4 *)(pbVar4 + 0x23) = *(undefined4 *)(psVar5->client_random + 0x18);
              *(undefined4 *)(pbVar4 + 0x27) = *(undefined4 *)(psVar5->client_random + 0x1c);
              pbVar4[0x2b] = 0;
              pbVar20 = pbVar4 + 0x2e;
              psVar13 = SSL_get_ciphers(param_1);
              iVar25 = ssl_cipher_list_to_bytes(param_1,psVar13,pbVar20,ssl3_put_cipher_by_char);
              if (iVar25 == 0) {
                iVar25 = 0x1f6;
                goto LAB_080a9d16;
              }
              pbVar4[0x2c] = (byte)((uint)iVar25 >> 8);
              pbVar4[0x2d] = (byte)iVar25;
              if (((*(byte *)((int)&param_1->references + 2) & 2) == 0) &&
                 (*(_STACK **)(param_1->psk_server_callback + 0x98) != (_STACK *)0x0)) {
                iVar16 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
                local_44 = pbVar4 + iVar25 + 0x2f;
                pbVar20[iVar25] = (char)iVar16 + 1;
                if (0 < iVar16) {
                  iVar25 = 0;
                  do {
                    puVar14 = (undefined4 *)
                              sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),iVar25);
                    local_44[iVar25] = (byte)*puVar14;
                    iVar25 = iVar25 + 1;
                  } while (iVar16 != iVar25);
                  local_44 = local_44 + iVar16;
                }
              }
              else {
                pbVar20[iVar25] = 1;
                local_44 = pbVar4 + iVar25 + 0x2f;
              }
              *local_44 = 0;
              iVar25 = ssl_prepare_clienthello_tlsext(param_1);
              if (iVar25 < 1) {
                ERR_put_error(0x14,0x74,0xe2,"s23_clnt.c",0x21a);
              }
              else {
                iVar25 = ssl_add_clienthello_tlsext(param_1,local_44 + 1,pbVar4 + 0x4000);
                if (iVar25 == 0) {
                  iVar25 = 0x222;
                }
                else {
                  iVar16 = iVar25 - (int)(pbVar4 + 9);
                  pbVar4[5] = 1;
                  pbVar4[8] = (byte)iVar16;
                  pbVar4[6] = (byte)((uint)iVar16 >> 0x10);
                  uVar10 = iVar16 + 4;
                  pbVar4[7] = (byte)((uint)iVar16 >> 8);
                  if (uVar10 < 0x4001) {
                    *pbVar4 = 0x16;
                    pbVar4[1] = 3;
                    if ((param_1->first_packet >> 8 == 3) && (0x301 < param_1->first_packet)) {
                      bVar27 = 1;
                    }
                    pbVar4[2] = bVar27;
                    pbVar4[3] = (byte)(uVar10 >> 8);
                    local_40 = (byte)uVar10;
                    pbVar4[4] = local_40;
                    param_1->init_off = 0;
                    param_1->init_num = iVar25 - (int)pbVar4;
                    ssl3_finish_mac(param_1,pbVar4 + 5,(iVar25 - (int)pbVar4) + -5);
                    goto LAB_080a99ce;
                  }
                  iVar25 = 0x231;
                }
                ERR_put_error(0x14,0x74,0x44,"s23_clnt.c",iVar25);
              }
            }
          }
        }
LAB_080a9a20:
        iVar25 = -1;
LAB_080a9164:
        local_50 = p_Var8;
        param_1->in_handshake = param_1->in_handshake + -1;
LAB_080a9168:
        if (local_50 != (_func_3152 *)0x0) {
          (*local_50)(param_1,0x1002,iVar25);
        }
        if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return iVar25;
      }
LAB_080a9337:
      iVar25 = ssl23_write_bytes(param_1);
      if (iVar25 < 2) {
        if (iVar25 != 1) goto LAB_080a9164;
      }
      else {
        p_Var3 = param_1->msg_callback;
        if (p_Var3 != (_func_3150 *)0x0) {
          if (bVar26) {
            (*p_Var3)(1,2,0,param_1->init_buf->data + 2,iVar25 - 2,param_1,param_1->msg_callback_arg
                     );
          }
          else {
            (*p_Var3)(1,iVar29,0x16,param_1->init_buf->data + 5,iVar25 - 5,param_1,
                      param_1->msg_callback_arg);
          }
        }
      }
      pSVar2 = param_1->ctx;
      param_1->state = 0x1220;
      param_1->init_num = 0;
    }
    if (pSVar2 != (SSL_CTX *)0x0) {
      BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
    }
    iVar25 = param_1->state;
    if ((local_50 != (_func_3152 *)0x0) && (iVar25 != iVar28)) {
      param_1->state = iVar28;
      (*local_50)(param_1,0x1001,1);
      param_1->state = iVar25;
    }
  } while( true );
}

