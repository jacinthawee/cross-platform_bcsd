
int ssl23_connect(SSL *param_1)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  SSL_CTX *pSVar4;
  ssl3_state_st *psVar5;
  byte *pbVar6;
  _func_3150 *p_Var7;
  undefined4 uVar8;
  ssl2_state_st *psVar9;
  bool bVar10;
  _func_3152 *p_Var11;
  int *piVar12;
  uint uVar13;
  uint uVar14;
  stack_st_SSL_CIPHER *psVar15;
  undefined4 *puVar16;
  uchar *puVar17;
  _STACK *p_Var18;
  void *pvVar19;
  SSL_METHOD *pSVar20;
  BUF_MEM *str;
  time_t tVar21;
  uint uVar22;
  _func_3152 *p_Var23;
  uint uVar24;
  undefined *puVar25;
  int iVar26;
  int in_GS_OFFSET;
  bool bVar27;
  int iVar28;
  int iVar29;
  _func_3152 *local_54;
  int local_50;
  uint local_44;
  byte local_40;
  byte *local_3c;
  time_t local_2c;
  undefined4 local_28;
  undefined2 local_24;
  uchar local_22;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = time((time_t *)0x0);
  RAND_add(&local_2c,4,0.0);
  ERR_clear_error();
  piVar12 = __errno_location();
  *piVar12 = 0;
  local_54 = param_1->info_callback;
  if (local_54 == (_func_3152 *)0x0) {
    local_54 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar13 = SSL_state(param_1);
  if (((uVar13 & 0x3000) == 0) || (uVar13 = SSL_state(param_1), (uVar13 & 0x4000) != 0)) {
    SSL_clear(param_1);
  }
  iVar26 = param_1->state;
  while (iVar28 = iVar26, p_Var11 = local_54, iVar28 < 0x1212) {
    if (iVar28 < 0x1210) {
      if ((iVar28 != 0x1000) && (iVar28 != 0x1003)) goto LAB_080ac800;
      goto LAB_080ac8cc;
    }
    uVar13 = param_1->references;
    param_1->shutdown = 0;
    local_44 = uVar13 & 0x1000000;
    bVar27 = local_44 == 0;
    if (bVar27) {
      p_Var18 = (_STACK *)SSL_get_ciphers(param_1);
      for (iVar26 = 0; iVar29 = sk_num(p_Var18), iVar26 < iVar29; iVar26 = iVar26 + 1) {
        pvVar19 = sk_value(p_Var18,iVar26);
        if (*(int *)((int)pvVar19 + 0x1c) == 1) {
          iVar26 = param_1->state;
          local_44 = 0x1000000;
          uVar14 = 0x3000000;
          uVar22 = 0x7000000;
          uVar24 = 0x17000000;
          goto LAB_080ac9c3;
        }
      }
      iVar26 = param_1->state;
      uVar14 = 0x2000000;
      uVar22 = 0x6000000;
      bVar27 = false;
      uVar24 = 0x16000000;
    }
    else {
      local_44 = 0;
      uVar14 = 0x2000000;
      uVar22 = 0x6000000;
      uVar24 = 0x16000000;
      iVar26 = iVar28;
    }
LAB_080ac9c3:
    local_50 = 0x303;
    if ((uVar13 & 0x8000000) != 0) {
      local_50 = (uVar24 == (uVar13 & uVar24)) + 0x302;
    }
    iVar29 = local_50;
    if (((uVar13 & 0x10000000) != 0) && (iVar29 = 0x301, (uVar13 & uVar22) == uVar22)) {
      iVar29 = local_50;
    }
    local_50 = iVar29;
    iVar29 = local_50;
    if (((uVar13 & 0x4000000) != 0) && (iVar29 = 0x300, (uVar13 & uVar14) == uVar14)) {
      iVar29 = local_50;
    }
    local_50 = iVar29;
    if (((uVar13 & 0x2000000) == 0) || ((uVar13 & local_44) == local_44)) {
      bVar10 = false;
      if (param_1->tlsext_debug_arg == (void *)0x0) {
        bVar10 = bVar27;
      }
      bVar27 = false;
      if (param_1->servername_done == -1) {
        bVar27 = bVar10;
      }
    }
    else {
      local_50 = 2;
    }
    if (iVar26 == 0x1210) {
      psVar5 = param_1->s3;
      pbVar6 = (byte *)param_1->init_buf->data;
      if ((*(byte *)&param_1->options & 0x20) == 0) {
        iVar26 = RAND_pseudo_bytes(psVar5->client_random,0x20);
      }
      else {
        tVar21 = time((time_t *)0x0);
        psVar5->client_random[3] = (uchar)tVar21;
        psVar5->client_random[0] = (uchar)((uint)tVar21 >> 0x18);
        psVar5->client_random[1] = (uchar)((uint)tVar21 >> 0x10);
        psVar5->client_random[2] = (uchar)((uint)tVar21 >> 8);
        iVar26 = RAND_pseudo_bytes(psVar5->client_random + 4,0x1c);
      }
      if (iVar26 < 1) goto LAB_080ad028;
      if (local_50 == 0x303) {
        bVar3 = 3;
        local_40 = 3;
      }
      else if (local_50 == 0x302) {
        bVar3 = 2;
        local_40 = 3;
      }
      else if (local_50 == 0x301) {
        bVar3 = 1;
        local_40 = 3;
      }
      else if (local_50 == 0x300) {
        bVar3 = 0;
        local_40 = 3;
      }
      else {
        if (local_50 != 2) {
          ERR_put_error(0x14,0x74,0xbf,"s23_clnt.c",0x1a3);
          goto LAB_080ad028;
        }
        bVar3 = 2;
        local_40 = 0;
      }
      param_1->first_packet = local_50;
      if (bVar27) {
        pbVar6[2] = 1;
        pbVar6[3] = local_40;
        pbVar6[4] = bVar3;
        psVar15 = SSL_get_ciphers(param_1);
        iVar26 = ssl_cipher_list_to_bytes(param_1,psVar15,pbVar6 + 0xb,0);
        if (iVar26 != 0) {
          pbVar6[6] = (byte)iVar26;
          pbVar6[5] = (byte)((uint)iVar26 >> 8);
          puVar16 = (undefined4 *)(pbVar6 + 0xb + iVar26);
          pbVar6[7] = 0;
          pbVar6[8] = 0;
          uVar13 = param_1->references;
          pbVar6[9] = 0;
          uVar13 = uVar13 & 2;
          uVar22 = -(uint)(uVar13 == 0) & 0x10;
          iVar26 = uVar22 + 0x10;
          uVar14 = ~-(uint)(uVar13 == 0) & 0x10;
          pbVar6[10] = (-(uVar13 == 0) & 0x10U) + 0x10;
          psVar5 = param_1->s3;
          uVar24 = 0;
          *(undefined4 *)psVar5->client_random = 0;
          *(undefined4 *)(psVar5->client_random + 0x1c) = 0;
          uVar13 = (uint)(psVar5->client_random + 4) & 0xfffffffc;
          do {
            *(undefined4 *)(uVar13 + uVar24) = 0;
            uVar24 = uVar24 + 4;
          } while (uVar24 < ((int)psVar5 + (0xe0 - uVar13) & 0xfffffffc));
          iVar29 = RAND_pseudo_bytes(param_1->s3->client_random + uVar14,iVar26);
          if (0 < iVar29) {
            puVar17 = param_1->s3->client_random + uVar14;
            *puVar16 = *(undefined4 *)puVar17;
            *(undefined4 *)((int)puVar16 + uVar22 + 0xc) = *(undefined4 *)(puVar17 + uVar22 + 0xc);
            iVar29 = (int)puVar16 - ((uint)(puVar16 + 1) & 0xfffffffc);
            uVar13 = 0;
            do {
              *(undefined4 *)(((uint)(puVar16 + 1) & 0xfffffffc) + uVar13) =
                   *(undefined4 *)(puVar17 + (uVar13 - iVar29));
              uVar13 = uVar13 + 4;
            } while (uVar13 < (iVar29 + iVar26 & 0xfffffffcU));
            puVar25 = (undefined *)((int)puVar16 + (iVar26 - (int)(pbVar6 + 2)));
            pbVar6[1] = (byte)puVar25;
            *pbVar6 = (byte)((uint)puVar25 >> 8) | 0x80;
            param_1->init_off = 0;
            param_1->init_num = (int)(puVar25 + 2);
            ssl3_finish_mac(param_1,pbVar6 + 2,puVar25);
LAB_080acc80:
            param_1->state = 0x1211;
            param_1->init_off = 0;
            goto LAB_080accc1;
          }
          goto LAB_080ad028;
        }
        iVar26 = 0x1ba;
      }
      else {
        pbVar6[9] = local_40;
        pbVar6[10] = bVar3;
        psVar5 = param_1->s3;
        *(undefined4 *)(pbVar6 + 0xb) = *(undefined4 *)psVar5->client_random;
        *(undefined4 *)(pbVar6 + 0xf) = *(undefined4 *)(psVar5->client_random + 4);
        *(undefined4 *)(pbVar6 + 0x13) = *(undefined4 *)(psVar5->client_random + 8);
        *(undefined4 *)(pbVar6 + 0x17) = *(undefined4 *)(psVar5->client_random + 0xc);
        *(undefined4 *)(pbVar6 + 0x1b) = *(undefined4 *)(psVar5->client_random + 0x10);
        *(undefined4 *)(pbVar6 + 0x1f) = *(undefined4 *)(psVar5->client_random + 0x14);
        *(undefined4 *)(pbVar6 + 0x23) = *(undefined4 *)(psVar5->client_random + 0x18);
        uVar8 = *(undefined4 *)(psVar5->client_random + 0x1c);
        pbVar1 = pbVar6 + 0x2e;
        pbVar6[0x2b] = 0;
        *(undefined4 *)(pbVar6 + 0x27) = uVar8;
        psVar15 = SSL_get_ciphers(param_1);
        iVar26 = ssl_cipher_list_to_bytes(param_1,psVar15,pbVar1,ssl3_put_cipher_by_char);
        if (iVar26 != 0) {
          pbVar6[0x2c] = (byte)((uint)iVar26 >> 8);
          pbVar6[0x2d] = (byte)iVar26;
          if (((*(byte *)((int)&param_1->references + 2) & 2) == 0) &&
             (*(_STACK **)(param_1->psk_server_callback + 0x98) != (_STACK *)0x0)) {
            iVar29 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
            local_3c = pbVar6 + iVar26 + 0x2f;
            pbVar1[iVar26] = (char)iVar29 + 1;
            if (0 < iVar29) {
              iVar26 = 0;
              do {
                puVar16 = (undefined4 *)
                          sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),iVar26);
                local_3c[iVar26] = (byte)*puVar16;
                iVar26 = iVar26 + 1;
              } while (iVar29 != iVar26);
              local_3c = local_3c + iVar29;
            }
          }
          else {
            local_3c = pbVar6 + iVar26 + 0x2f;
            pbVar1[iVar26] = 1;
          }
          *local_3c = 0;
          iVar26 = ssl_prepare_clienthello_tlsext(param_1);
          if (iVar26 < 1) {
            ERR_put_error(0x14,0x74,0xe2,"s23_clnt.c",0x220);
          }
          else {
            iVar26 = ssl_add_clienthello_tlsext(param_1,local_3c + 1,pbVar6 + 0x4000);
            if (iVar26 == 0) {
              iVar26 = 0x225;
            }
            else {
              iVar29 = iVar26 - (int)(pbVar6 + 9);
              pbVar6[5] = 1;
              pbVar6[8] = (byte)iVar29;
              pbVar6[6] = (byte)((uint)iVar29 >> 0x10);
              uVar13 = iVar29 + 4;
              pbVar6[7] = (byte)((uint)iVar29 >> 8);
              if (uVar13 < 0x4001) {
                *pbVar6 = 0x16;
                pbVar6[1] = local_40;
                if ((param_1->first_packet >> 8 == 3) && (0x301 < param_1->first_packet)) {
                  bVar3 = 1;
                }
                pbVar6[2] = bVar3;
                pbVar6[4] = (byte)uVar13;
                pbVar6[3] = (byte)(uVar13 >> 8);
                param_1->init_num = iVar26 - (int)pbVar6;
                param_1->init_off = 0;
                ssl3_finish_mac(param_1,pbVar6 + 5,(iVar26 - (int)pbVar6) + -5);
                goto LAB_080acc80;
              }
              iVar26 = 0x235;
            }
            ERR_put_error(0x14,0x74,0x44,"s23_clnt.c",iVar26);
          }
          goto LAB_080ad028;
        }
        iVar26 = 0x1fb;
      }
      ERR_put_error(0x14,0x74,0xb5,"s23_clnt.c",iVar26);
      goto LAB_080ad028;
    }
LAB_080accc1:
    iVar26 = ssl23_write_bytes(param_1);
    if (iVar26 < 2) {
      if (iVar26 != 1) goto LAB_080ac884;
    }
    else {
      p_Var7 = param_1->msg_callback;
      if (p_Var7 != (_func_3150 *)0x0) {
        if (bVar27) {
          (*p_Var7)(1,2,0,param_1->init_buf->data + 2,iVar26 - 2,param_1,param_1->msg_callback_arg);
        }
        else {
          (*p_Var7)(1,local_50,0x16,param_1->init_buf->data + 5,iVar26 - 5,param_1,
                    param_1->msg_callback_arg);
        }
      }
    }
    pSVar4 = param_1->ctx;
    param_1->state = 0x1220;
    param_1->init_num = 0;
joined_r0x080acd21:
    if (pSVar4 != (SSL_CTX *)0x0) {
      BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
    }
    iVar26 = param_1->state;
    if ((local_54 != (_func_3152 *)0x0) && (iVar26 != iVar28)) {
      param_1->state = iVar28;
      (*local_54)(param_1,0x1001,1);
      param_1->state = iVar26;
    }
  }
  if (iVar28 == 0x4000) {
LAB_080ac8cc:
    if (param_1->session == (SSL_SESSION *)0x0) {
      param_1->server = 0;
      if (local_54 != (_func_3152 *)0x0) {
        (*local_54)(param_1,0x10,1);
      }
      param_1->type = 0x1000;
      if (param_1->init_buf == (BUF_MEM *)0x0) {
        str = BUF_MEM_new();
        if (str == (BUF_MEM *)0x0) goto LAB_080ad028;
        iVar26 = BUF_MEM_grow(str,0x4000);
        if (iVar26 == 0) {
          param_1->in_handshake = param_1->in_handshake + -1;
          iVar26 = -1;
          BUF_MEM_free(str);
          goto LAB_080ac888;
        }
        param_1->init_buf = str;
      }
      iVar26 = ssl3_setup_buffers(param_1);
      if (iVar26 != 0) {
        ssl3_init_finished_mac(param_1);
        pSVar4 = param_1->ctx;
        param_1->state = 0x1210;
        *(int *)(param_1->psk_server_callback + 0x34) =
             *(int *)(param_1->psk_server_callback + 0x34) + 1;
        param_1->init_num = 0;
        goto joined_r0x080acd21;
      }
      goto LAB_080ad028;
    }
    iVar29 = 0xb2;
    iVar28 = 0xdd;
  }
  else {
    if (iVar28 < 0x4001) {
      if (iVar28 - 0x1220U < 2) {
        iVar26 = ssl23_read_bytes(param_1,7);
        if (iVar26 != 7) goto LAB_080ac874;
        puVar16 = (undefined4 *)param_1->packet;
        local_28 = *puVar16;
        local_24 = *(undefined2 *)(puVar16 + 1);
        local_22 = *(uchar *)((int)puVar16 + 6);
        cVar2 = *(char *)puVar16;
        if ((-1 < cVar2) || (*(char *)((int)puVar16 + 2) != '\x04')) {
          if ((*(char *)((int)puVar16 + 1) == '\x03') &&
             (bVar3 = *(byte *)((int)puVar16 + 2), bVar3 < 4)) {
            if (cVar2 == '\x16') {
              cVar2 = *(char *)((int)puVar16 + 5);
            }
            else {
              if ((cVar2 != '\x15') || (*(char *)((int)puVar16 + 3) != '\0')) goto LAB_080ad2b0;
              cVar2 = *(char *)(puVar16 + 1);
            }
            if (cVar2 == '\x02') {
              if (bVar3 == 0) {
                if ((*(byte *)((int)&param_1->references + 3) & 2) != 0) goto LAB_080ad006;
                param_1->version = 0x300;
                pSVar20 = SSLv3_client_method();
                param_1->method = pSVar20;
              }
              else if (bVar3 == 1) {
                if ((*(byte *)((int)&param_1->references + 3) & 4) != 0) goto LAB_080ad006;
                param_1->version = 0x301;
                pSVar20 = TLSv1_client_method();
                param_1->method = pSVar20;
              }
              else if (bVar3 == 2) {
                if ((*(byte *)((int)&param_1->references + 3) & 0x10) != 0) goto LAB_080ad006;
                param_1->version = 0x302;
                pSVar20 = TLSv1_1_client_method();
                param_1->method = pSVar20;
              }
              else {
                if ((*(byte *)((int)&param_1->references + 3) & 8) != 0) {
LAB_080ad006:
                  iVar26 = 0x2df;
                  goto LAB_080ad00e;
                }
                param_1->version = 0x303;
                pSVar20 = TLSv1_2_client_method();
                param_1->method = pSVar20;
              }
              if ((*(char *)puVar16 != '\x15') || (*(char *)((int)puVar16 + 5) == '\x01')) {
                iVar26 = ssl_init_wbio_buffer(param_1,1);
                if (iVar26 == 0) goto LAB_080ad028;
                param_1->state = 0x1120;
                param_1->rstate = 0xf0;
                param_1->packet_length = 7;
                puVar16 = (undefined4 *)(param_1->s3->rbuf).buf;
                if (puVar16 == (undefined4 *)0x0) {
                  iVar26 = ssl3_setup_read_buffer(param_1);
                  if (iVar26 == 0) goto LAB_080ad028;
                  puVar16 = (undefined4 *)(param_1->s3->rbuf).buf;
                }
                param_1->packet = (uchar *)puVar16;
                *puVar16 = local_28;
                *(undefined2 *)(puVar16 + 1) = local_24;
                *(uchar *)((int)puVar16 + 6) = local_22;
                psVar5 = param_1->s3;
                (psVar5->rbuf).left = 7;
                (psVar5->rbuf).offset = 0;
                param_1->handshake_func = (_func_3149 *)param_1->method->ssl_connect;
                goto LAB_080acef5;
              }
              p_Var23 = param_1->info_callback;
              if ((p_Var23 != (_func_3152 *)0x0) ||
                 (p_Var23 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
                 p_Var23 != (_func_3152 *)0x0)) {
                (*p_Var23)(param_1,0x4004,
                           (uint)(*(short *)((int)puVar16 + 5) << 8) |
                           (uint)(byte)((ushort)*(short *)((int)puVar16 + 5) >> 8));
              }
              if (param_1->msg_callback != (_func_3150 *)0x0) {
                (*param_1->msg_callback)
                          (0,param_1->version,0x15,(char *)((int)puVar16 + 5),2,param_1,
                           param_1->msg_callback_arg);
              }
              param_1->rwstate = 1;
              ERR_put_error(0x14,0x77,*(byte *)((int)puVar16 + 6) + 1000,"s23_clnt.c",0x2fa);
              goto LAB_080ad028;
            }
          }
LAB_080ad2b0:
          ERR_put_error(0x14,0x77,0xfc,"s23_clnt.c",0x313);
          goto LAB_080ad028;
        }
        if ((*(char *)((int)puVar16 + 5) != '\0') || (*(char *)((int)puVar16 + 6) != '\x02'))
        goto LAB_080ad2b0;
        if ((*(byte *)((int)&param_1->references + 3) & 1) != 0) {
          iVar26 = 0x27d;
LAB_080ad00e:
          ERR_put_error(0x14,0x77,0x102,"s23_clnt.c",iVar26);
          goto LAB_080ad028;
        }
        if (param_1->s2 == (ssl2_state_st *)0x0) {
          iVar26 = ssl2_new(param_1);
          if (iVar26 == 0) goto LAB_080ad028;
        }
        else {
          ssl2_clear(param_1);
        }
        psVar5 = param_1->s3;
        psVar9 = param_1->s2;
        uVar13 = (-(uint)((param_1->references & 2U) == 0) & 0x10) + 0x10;
        if (0x20 < uVar13) {
          uVar13 = 0x20;
        }
        psVar9->challenge_length = uVar13;
        puVar16 = (undefined4 *)((int)psVar5 + (0xe0 - uVar13));
        *(undefined4 *)psVar9->challenge = *puVar16;
        *(undefined4 *)(psVar9->challenge + (uVar13 - 4)) =
             *(undefined4 *)((uVar13 - 4) + (int)puVar16);
        uVar14 = (uint)(psVar9->challenge + 4) & 0xfffffffc;
        iVar26 = (int)psVar9 + (0x68 - uVar14);
        uVar22 = 0;
        do {
          *(undefined4 *)(uVar14 + uVar22) = *(undefined4 *)((int)puVar16 + (uVar22 - iVar26));
          uVar22 = uVar22 + 4;
        } while (uVar22 < (iVar26 + uVar13 & 0xfffffffc));
        if (param_1->s3 != (ssl3_state_st *)0x0) {
          ssl3_free(param_1);
        }
        iVar26 = BUF_MEM_grow_clean(param_1->init_buf,0x3fff);
        if (iVar26 == 0) {
          ERR_put_error(0x14,0x77,7,"s23_clnt.c",0x29d);
LAB_080ad028:
          iVar26 = -1;
        }
        else {
          param_1->state = 0x1020;
          psVar9 = param_1->s2;
          if (param_1->first_packet != 2) {
            psVar9->ssl2_rollback = 1;
          }
          puVar16 = (undefined4 *)psVar9->rbuf;
          param_1->rstate = 0xf0;
          param_1->packet_length = 7;
          param_1->packet = (uchar *)puVar16;
          *puVar16 = local_28;
          *(undefined2 *)(puVar16 + 1) = local_24;
          *(uchar *)((int)puVar16 + 6) = local_22;
          psVar9 = param_1->s2;
          psVar9->rbuf_left = 7;
          psVar9->rbuf_offs = 0;
          psVar9->write_sequence = 1;
          pSVar20 = SSLv2_client_method();
          param_1->method = pSVar20;
          param_1->handshake_func = (_func_3149 *)pSVar20->ssl_connect;
LAB_080acef5:
          param_1->init_num = 0;
          iVar26 = ssl_get_new_session(param_1,0);
          if (iVar26 == 0) goto LAB_080ad028;
          iVar26 = SSL_connect(param_1);
LAB_080ac874:
          p_Var11 = (_func_3152 *)0x0;
          if (iVar26 < 0) {
            p_Var11 = local_54;
          }
        }
        goto LAB_080ac884;
      }
    }
    else if (iVar28 == 0x5000) goto LAB_080ac8cc;
LAB_080ac800:
    iVar29 = 0xe8;
    iVar28 = 0xff;
  }
  iVar26 = -1;
  ERR_put_error(0x14,0x75,iVar28,"s23_clnt.c",iVar29);
LAB_080ac884:
  local_54 = p_Var11;
  param_1->in_handshake = param_1->in_handshake + -1;
LAB_080ac888:
  if (local_54 != (_func_3152 *)0x0) {
    (*local_54)(param_1,0x1002,iVar26);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar26;
}

