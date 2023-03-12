
int ssl23_connect(SSL *param_1)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined4 uVar13;
  int iVar14;
  SSL_CTX *pSVar15;
  uint uVar16;
  int iVar17;
  stack_st_SSL_CIPHER *psVar18;
  int iVar19;
  SSL_METHOD *pSVar20;
  BUF_MEM *pBVar21;
  byte *pbVar22;
  int iVar23;
  _func_3057 *p_Var24;
  undefined4 uVar25;
  char *pcVar26;
  int iVar27;
  uint uVar28;
  ssl2_state_st *psVar29;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  uint in_t4;
  uint in_t5;
  _func_3152 *p_Var30;
  int iVar31;
  byte *pbVar32;
  ssl3_state_st *psVar33;
  byte *pbVar34;
  uint uVar35;
  byte *pbVar36;
  byte *pbVar37;
  _func_3150 *p_Var38;
  _func_3152 *p_Var39;
  byte bStack_41;
  undefined4 local_38;
  undefined4 local_34;
  uchar local_30;
  uchar local_2f;
  uchar local_2e;
  int local_2c;
  
  puVar10 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_38 = (*(code *)PTR_time_006aabe4)(0);
  (*(code *)PTR_RAND_add_006a9020)(&local_38,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
  puVar11 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  p_Var30 = param_1->info_callback;
  *puVar11 = 0;
  if (p_Var30 == (_func_3152 *)0x0) {
    p_Var30 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar12 = SSL_state(param_1);
  if (((uVar12 & 0x3000) == 0) || (uVar12 = SSL_state(param_1), (uVar12 & 0x4000) != 0)) {
    SSL_clear(param_1);
  }
  iVar14 = param_1->state;
  do {
    iVar23 = iVar14;
    if (iVar23 < 0x1212) {
      if (iVar23 < 0x1210) {
        if ((iVar23 != 0x1000) && (iVar23 != 0x1003)) goto LAB_00493f78;
        goto LAB_00494078;
      }
      uVar12 = param_1->references;
      param_1->shutdown = 0;
      uVar35 = uVar12 & 0x1000000;
      bVar3 = uVar35 == 0;
      if (uVar35 == 0) {
        psVar18 = SSL_get_ciphers(param_1);
        for (iVar14 = 0; iVar31 = (*(code *)PTR_sk_num_006a7f2c)(psVar18), iVar14 < iVar31;
            iVar14 = iVar14 + 1) {
          iVar31 = (*(code *)PTR_sk_value_006a7f24)(psVar18,iVar14);
          if (*(int *)(iVar31 + 0x1c) == 1) {
            iVar14 = param_1->state;
            uVar35 = 0x1000000;
            pcVar26 = (char *)0x3000000;
            uVar28 = 0x7000000;
            uVar16 = 0x17000000;
            goto LAB_00494160;
          }
        }
        iVar14 = param_1->state;
        pcVar26 = (char *)0x2000000;
        uVar28 = 0x6000000;
        bVar3 = false;
        uVar16 = 0x16000000;
      }
      else {
        uVar35 = 0;
        pcVar26 = (char *)0x2000000;
        uVar28 = 0x6000000;
        uVar16 = 0x16000000;
        iVar14 = iVar23;
      }
LAB_00494160:
      iVar31 = 0x303;
      if (((uVar12 & 0x8000000) != 0) && (iVar31 = 0x303, uVar16 != (uVar12 & uVar16))) {
        iVar31 = 0x302;
      }
      if (((int)(uVar12 << 3) < 0) && ((uVar12 & uVar28) != uVar28)) {
        iVar31 = 0x301;
      }
      if (((int)(uVar12 << 5) < 0) && ((char *)(uVar12 & (uint)pcVar26) != pcVar26)) {
        iVar31 = 0x300;
      }
      if (((int)(uVar12 << 6) < 0) && ((uVar12 & uVar35) != uVar35)) {
        iVar31 = 2;
      }
      else {
        if (param_1->tlsext_debug_arg != (void *)0x0) {
          bVar3 = false;
        }
        if (param_1->servername_done != -1) {
          bVar3 = false;
        }
      }
      if (iVar14 == 0x1210) {
        psVar33 = param_1->s3;
        pbVar32 = (byte *)param_1->init_buf->data;
        if ((param_1->options & 0x20) == 0) {
          iVar17 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(psVar33->client_random,0x20);
        }
        else {
          uVar12 = (*(code *)PTR_time_006aabe4)(0);
          pcVar26 = (char *)(uVar12 >> 0x18);
          psVar33->client_random[3] = (uchar)uVar12;
          psVar33->client_random[0] = (uchar)(uVar12 >> 0x18);
          psVar33->client_random[1] = (uchar)(uVar12 >> 0x10);
          puVar9 = PTR_RAND_pseudo_bytes_006a8664;
          psVar33->client_random[2] = (uchar)(uVar12 >> 8);
          iVar17 = (*(code *)puVar9)(psVar33->client_random + 4,0x1c);
        }
        iVar14 = -1;
        if (iVar17 < 1) goto LAB_00494060;
        if (iVar31 == 0x303) {
          bVar2 = 3;
          bStack_41 = 3;
        }
        else if (iVar31 == 0x302) {
          bVar2 = 2;
          bStack_41 = 3;
        }
        else if (iVar31 == 0x301) {
          bVar2 = 1;
          bStack_41 = 3;
        }
        else if (iVar31 == 0x300) {
          bVar2 = 0;
          bStack_41 = 3;
        }
        else {
          pcVar26 = "s\n";
          if (iVar31 != 2) {
            uVar25 = 0xbf;
            uVar13 = 0x1a3;
            goto LAB_00494ce0;
          }
          bStack_41 = 0;
          bVar2 = 2;
        }
        param_1->first_packet = iVar31;
        if (bVar3) {
          pbVar34 = pbVar32 + 0xb;
          pbVar32[3] = bStack_41;
          pbVar32[4] = bVar2;
          pbVar32[2] = 1;
          psVar18 = SSL_get_ciphers(param_1);
          iVar14 = ssl_cipher_list_to_bytes(param_1,psVar18,pbVar34,0);
          if (iVar14 == 0) {
            uVar25 = 0xb5;
            uVar13 = 0x1ba;
            goto LAB_00494ce0;
          }
          pbVar32[6] = (byte)iVar14;
          pbVar32[7] = 0;
          pbVar32[8] = 0;
          iVar27 = 0x10;
          pbVar32[5] = (byte)((uint)iVar14 >> 8);
          puVar9 = PTR_memset_006aab00;
          iVar17 = 0x20;
          uVar12 = param_1->references;
          pbVar32[9] = 0;
          if ((uVar12 & 2) == 0) {
            iVar27 = 0;
          }
          else {
            iVar17 = 0x10;
          }
          pbVar32[10] = (byte)iVar17;
          (*(code *)puVar9)(param_1->s3->client_random,0,0x20);
          iVar19 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)
                             (param_1->s3->client_random + iVar27,iVar17);
          if (iVar19 < 1) goto LAB_00494784;
          (*(code *)PTR_memcpy_006aabf4)
                    (pbVar34 + iVar14,param_1->s3->client_random + iVar27,iVar17);
          pbVar34 = pbVar34 + iVar14 + (iVar17 - (int)(pbVar32 + 2));
          pbVar32[1] = (byte)pbVar34;
          *pbVar32 = (byte)((uint)pbVar34 >> 8) | 0x80;
          param_1->init_num = (int)(pbVar34 + 2);
          param_1->init_off = 0;
          ssl3_finish_mac(param_1,pbVar32 + 2);
        }
        else {
          pbVar34 = pbVar32 + 0x2e;
          pbVar32[9] = bStack_41;
          pbVar32[10] = bVar2;
          psVar33 = param_1->s3;
          uVar12 = (uint)psVar33->client_random & 3;
          uVar35 = (uint)(psVar33->client_random + 4) & 3;
          uVar16 = (uint)(psVar33->client_random + 8) & 3;
          uVar4 = (uint)(psVar33->client_random + 0xc) & 3;
          uVar5 = (uint)(psVar33->client_random + 0x10) & 3;
          uVar6 = (uint)(psVar33->client_random + 0x14) & 3;
          iVar14 = *(int *)(psVar33->client_random + 0x14 + -uVar6);
          uVar7 = (uint)(psVar33->client_random + 0x18) & 3;
          iVar17 = *(int *)(psVar33->client_random + 0x18 + -uVar7);
          uVar8 = (uint)(psVar33->client_random + 3) & 3;
          in_t5 = (*(int *)(psVar33->client_random + -uVar12) << uVar12 * 8 |
                  in_t5 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar8 + 1) * 8 |
                  *(uint *)(psVar33->client_random + 3 + -uVar8) >> (3 - uVar8) * 8;
          uVar12 = (uint)(psVar33->client_random + 7) & 3;
          in_t4 = (*(int *)(psVar33->client_random + 4 + -uVar35) << uVar35 * 8 |
                  in_t4 & 0xffffffffU >> (4 - uVar35) * 8) & -1 << (uVar12 + 1) * 8 |
                  *(uint *)(psVar33->client_random + 7 + -uVar12) >> (3 - uVar12) * 8;
          uVar12 = (uint)(psVar33->client_random + 0xb) & 3;
          in_t3 = (*(int *)(psVar33->client_random + 8 + -uVar16) << uVar16 * 8 |
                  in_t3 & 0xffffffffU >> (4 - uVar16) * 8) & -1 << (uVar12 + 1) * 8 |
                  *(uint *)(psVar33->client_random + 0xb + -uVar12) >> (3 - uVar12) * 8;
          uVar12 = (uint)(psVar33->client_random + 0xf) & 3;
          in_t2 = (*(int *)(psVar33->client_random + 0xc + -uVar4) << uVar4 * 8 |
                  in_t2 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar12 + 1) * 8 |
                  *(uint *)(psVar33->client_random + 0xf + -uVar12) >> (3 - uVar12) * 8;
          uVar12 = (uint)(psVar33->client_random + 0x13) & 3;
          in_t1 = (*(int *)(psVar33->client_random + 0x10 + -uVar5) << uVar5 * 8 |
                  in_t1 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar12 + 1) * 8 |
                  *(uint *)(psVar33->client_random + 0x13 + -uVar12) >> (3 - uVar12) * 8;
          uVar12 = (uint)(psVar33->client_random + 0x17) & 3;
          uVar16 = *(uint *)(psVar33->client_random + 0x17 + -uVar12);
          uVar35 = (uint)(psVar33->client_random + 0x1b) & 3;
          uVar4 = *(uint *)(psVar33->client_random + 0x1b + -uVar35);
          uVar13 = *(undefined4 *)(psVar33->client_random + 0x1c);
          *(uint *)(pbVar32 + 0xb) = in_t5;
          *(uint *)(pbVar32 + 0xf) = in_t4;
          *(uint *)(pbVar32 + 0x13) = in_t3;
          *(uint *)(pbVar32 + 0x17) = in_t2;
          *(uint *)(pbVar32 + 0x1b) = in_t1;
          *(uint *)(pbVar32 + 0x1f) =
               (iVar14 << uVar6 * 8 | uVar28 & 0xffffffffU >> (4 - uVar6) * 8) &
               -1 << (uVar12 + 1) * 8 | uVar16 >> (3 - uVar12) * 8;
          *(uint *)(pbVar32 + 0x23) =
               (iVar17 << uVar7 * 8 | (uint)pcVar26 & 0xffffffffU >> (4 - uVar7) * 8) &
               -1 << (uVar35 + 1) * 8 | uVar4 >> (3 - uVar35) * 8;
          *(undefined4 *)(pbVar32 + 0x27) = uVar13;
          pbVar32[0x2b] = 0;
          psVar18 = SSL_get_ciphers(param_1);
          iVar14 = ssl_cipher_list_to_bytes
                             (param_1,psVar18,pbVar34,PTR_ssl3_put_cipher_by_char_006a90ec);
          if (iVar14 == 0) {
            uVar25 = 0xb5;
            uVar13 = 0x1fb;
            goto LAB_00494ce0;
          }
          pbVar32[0x2d] = (byte)iVar14;
          pbVar32[0x2c] = (byte)((uint)iVar14 >> 8);
          if ((param_1->references << 0xe < 0) ||
             (*(int *)(param_1->psk_server_callback + 0x98) == 0)) {
            pbVar34[iVar14] = 1;
            pbVar34 = pbVar34 + iVar14 + 1;
          }
          else {
            iVar17 = (*(code *)PTR_sk_num_006a7f2c)();
            pbVar22 = pbVar34 + iVar14 + 1;
            pbVar34[iVar14] = (char)iVar17 + 1;
            pbVar34 = pbVar22;
            if (0 < iVar17) {
              pbVar36 = pbVar22;
              do {
                pbVar37 = pbVar36 + 1;
                puVar11 = (undefined4 *)
                          (*(code *)PTR_sk_value_006a7f24)
                                    (*(undefined4 *)(param_1->psk_server_callback + 0x98),
                                     (int)pbVar36 - (int)pbVar22);
                *pbVar36 = (byte)*puVar11;
                pbVar34 = pbVar22 + iVar17;
                pbVar36 = pbVar37;
              } while (pbVar37 != pbVar22 + iVar17);
            }
          }
          *pbVar34 = 0;
          iVar14 = ssl_prepare_clienthello_tlsext(param_1);
          if (iVar14 < 1) {
            uVar25 = 0xe2;
            uVar13 = 0x220;
            goto LAB_00494ce0;
          }
          iVar14 = ssl_add_clienthello_tlsext(param_1,pbVar34 + 1,pbVar32 + 0x4000);
          if (iVar14 == 0) goto LAB_00494d80;
          iVar17 = iVar14 - (int)(pbVar32 + 9);
          pbVar32[5] = 1;
          pbVar32[8] = (byte)iVar17;
          uVar12 = iVar17 + 4;
          pbVar32[6] = (byte)((uint)iVar17 >> 0x10);
          pbVar32[7] = (byte)((uint)iVar17 >> 8);
          if (0x4000 < uVar12) {
            uVar25 = 0x44;
            uVar13 = 0x235;
            goto LAB_00494ce0;
          }
          *pbVar32 = 0x16;
          pbVar32[1] = bStack_41;
          if ((param_1->first_packet >> 8 == 3) && (0x301 < param_1->first_packet)) {
            bVar2 = 1;
          }
          pbVar32[2] = bVar2;
          pbVar32[4] = (byte)uVar12;
          pbVar32[3] = (byte)(uVar12 >> 8);
          param_1->init_num = iVar14 - (int)pbVar32;
          param_1->init_off = 0;
          ssl3_finish_mac(param_1,pbVar32 + 5,(iVar14 - (int)pbVar32) + -5);
        }
        param_1->init_off = 0;
        param_1->state = 0x1211;
      }
      iVar14 = ssl23_write_bytes(param_1);
      if (iVar14 < 2) {
        if (iVar14 != 1) {
          iVar23 = param_1->in_handshake;
          while( true ) {
            param_1->in_handshake = iVar23 + -1;
LAB_00493fac:
            if (p_Var30 != (_func_3152 *)0x0) {
              (*p_Var30)(param_1,0x1002,iVar14);
            }
            if (local_2c == *(int *)puVar10) break;
            (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00494d80:
            uVar25 = 0x44;
            uVar13 = 0x225;
LAB_00494ce0:
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x74,uVar25,"s23_clnt.c",uVar13);
            iVar14 = -1;
LAB_00494060:
            iVar23 = param_1->in_handshake;
          }
          return iVar14;
        }
      }
      else {
        p_Var38 = param_1->msg_callback;
        if (p_Var38 != (_func_3150 *)0x0) {
          if (bVar3) {
            (*p_Var38)(1,2,0,param_1->init_buf->data + 2,iVar14 - 2,param_1,
                       param_1->msg_callback_arg);
          }
          else {
            (*p_Var38)(1,iVar31,0x16,param_1->init_buf->data + 5,iVar14 - 5,param_1,
                       param_1->msg_callback_arg);
          }
        }
      }
      param_1->init_num = 0;
      param_1->state = 0x1220;
      pSVar15 = param_1->ctx;
    }
    else {
      if (iVar23 != 0x4000) {
        if (iVar23 < 0x4001) {
          if (iVar23 - 0x1220U < 2) {
            iVar14 = ssl23_read_bytes(param_1,7);
            if (iVar14 != 7) goto LAB_00494058;
            puVar11 = (undefined4 *)param_1->packet;
            local_34 = *puVar11;
            local_2f = *(uchar *)((int)puVar11 + 5);
            local_30 = *(uchar *)(puVar11 + 1);
            local_2e = *(uchar *)((int)puVar11 + 6);
            cVar1 = *(char *)puVar11;
            if ((cVar1 < '\0') && (*(char *)((int)puVar11 + 2) == '\x04')) {
              if ((*(char *)((int)puVar11 + 5) == '\0') && (local_2e == '\x02')) {
                uVar25 = 0x102;
                if (param_1->references << 7 < 0) {
                  uVar13 = 0x27d;
                  goto LAB_004947fc;
                }
                if (param_1->s2 == (ssl2_state_st *)0x0) {
                  iVar14 = ssl2_new(param_1,4,0x102);
                  if (iVar14 == 0) {
                    iVar14 = -1;
                    goto LAB_00494060;
                  }
                }
                else {
                  ssl2_clear(param_1);
                }
                puVar9 = PTR_memcpy_006aabf4;
                uVar12 = 0x10;
                psVar29 = param_1->s2;
                psVar33 = param_1->s3;
                if ((param_1->references & 2U) == 0) {
                  uVar12 = 0x20;
                }
                psVar29->challenge_length = uVar12;
                (*(code *)puVar9)(psVar29->challenge,(int)psVar33 + (0xe0 - uVar12));
                if (param_1->s3 != (ssl3_state_st *)0x0) {
                  ssl3_free(param_1);
                }
                iVar14 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(param_1->init_buf,0x3fff);
                if (iVar14 == 0) {
                  uVar25 = 7;
                  uVar13 = 0x29d;
                  goto LAB_004947fc;
                }
                param_1->state = 0x1020;
                if (param_1->first_packet == 2) {
                  psVar29 = param_1->s2;
                }
                else {
                  psVar29 = param_1->s2;
                  psVar29->ssl2_rollback = 1;
                }
                puVar11 = (undefined4 *)psVar29->rbuf;
                param_1->packet_length = 7;
                param_1->packet = (uchar *)puVar11;
                param_1->rstate = 0xf0;
                *puVar11 = local_34;
                *(uchar *)(puVar11 + 1) = local_30;
                *(uchar *)((int)puVar11 + 5) = local_2f;
                *(uchar *)((int)puVar11 + 6) = local_2e;
                psVar29 = param_1->s2;
                psVar29->rbuf_left = 7;
                psVar29->rbuf_offs = 0;
                psVar29->write_sequence = 1;
                pSVar20 = SSLv2_client_method();
                p_Var24 = pSVar20->ssl_connect;
                param_1->method = pSVar20;
                param_1->handshake_func = (_func_3149 *)p_Var24;
LAB_00494588:
                param_1->init_num = 0;
                iVar14 = ssl_get_new_session(param_1,0);
                if (iVar14 != 0) {
                  iVar14 = SSL_connect(param_1);
LAB_00494058:
                  if (iVar14 < 0) goto LAB_00494060;
                  p_Var30 = (_func_3152 *)0x0;
                  goto LAB_00494060;
                }
LAB_00494784:
                iVar14 = -1;
                goto LAB_00494060;
              }
            }
            else if ((*(char *)((int)puVar11 + 1) == '\x03') &&
                    (bVar2 = *(byte *)((int)puVar11 + 2), bVar2 < 4)) {
              if (cVar1 == '\x16') {
                cVar1 = *(char *)((int)puVar11 + 5);
              }
              else {
                if ((cVar1 != '\x15') || (*(char *)((int)puVar11 + 3) != '\0')) goto LAB_00494844;
                cVar1 = *(char *)(puVar11 + 1);
              }
              if (cVar1 == '\x02') {
                if (bVar2 == 0) {
                  if (param_1->references << 6 < 0) goto LAB_004947ec;
                  param_1->version = 0x300;
                  pSVar20 = SSLv3_client_method();
                  param_1->method = pSVar20;
                }
                else if (bVar2 == 1) {
                  if (param_1->references << 5 < 0) goto LAB_004947ec;
                  param_1->version = 0x301;
                  pSVar20 = TLSv1_client_method();
                  param_1->method = pSVar20;
                }
                else if (bVar2 == 2) {
                  if (param_1->references << 3 < 0) goto LAB_004947ec;
                  param_1->version = 0x302;
                  pSVar20 = TLSv1_1_client_method();
                  param_1->method = pSVar20;
                }
                else {
                  if (param_1->references << 4 < 0) {
LAB_004947ec:
                    uVar25 = 0x102;
                    uVar13 = 0x2df;
                    goto LAB_004947fc;
                  }
                  param_1->version = 0x303;
                  pSVar20 = TLSv1_2_client_method();
                  param_1->method = pSVar20;
                }
                if ((*(char *)puVar11 != '\x15') || (*(char *)((int)puVar11 + 5) == '\x01')) {
                  iVar14 = ssl_init_wbio_buffer(param_1,1);
                  if (iVar14 == 0) goto LAB_00494784;
                  param_1->state = 0x1120;
                  puVar11 = (undefined4 *)(param_1->s3->rbuf).buf;
                  param_1->rstate = 0xf0;
                  param_1->packet_length = 7;
                  if (puVar11 == (undefined4 *)0x0) {
                    iVar14 = ssl3_setup_read_buffer(param_1);
                    if (iVar14 == 0) goto LAB_00494784;
                    puVar11 = (undefined4 *)(param_1->s3->rbuf).buf;
                  }
                  param_1->packet = (uchar *)puVar11;
                  *puVar11 = local_34;
                  *(uchar *)((int)puVar11 + 6) = local_2e;
                  *(uchar *)(puVar11 + 1) = local_30;
                  *(uchar *)((int)puVar11 + 5) = local_2f;
                  psVar33 = param_1->s3;
                  p_Var24 = param_1->method->ssl_connect;
                  (psVar33->rbuf).left = 7;
                  (psVar33->rbuf).offset = 0;
                  param_1->handshake_func = (_func_3149 *)p_Var24;
                  goto LAB_00494588;
                }
                p_Var39 = param_1->info_callback;
                if ((p_Var39 == (_func_3152 *)0x0) &&
                   (p_Var39 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
                   p_Var39 == (_func_3152 *)0x0)) {
                  p_Var38 = param_1->msg_callback;
                }
                else {
                  (*p_Var39)(param_1,0x4004,(int)*(undefined2 *)((int)puVar11 + 5));
                  p_Var38 = param_1->msg_callback;
                }
                if (p_Var38 != (_func_3150 *)0x0) {
                  (*p_Var38)(0,param_1->version,0x15,(char *)((int)puVar11 + 5),2,param_1,
                             param_1->msg_callback_arg);
                }
                puVar9 = PTR_ERR_put_error_006a9030;
                param_1->rwstate = 1;
                (*(code *)puVar9)(0x14,0x77,*(byte *)((int)puVar11 + 6) + 1000,"s23_clnt.c",0x2fa);
                goto LAB_00494784;
              }
            }
LAB_00494844:
            uVar25 = 0xfc;
            uVar13 = 0x313;
LAB_004947fc:
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x77,uVar25,"s23_clnt.c",uVar13);
            iVar14 = -1;
            goto LAB_00494060;
          }
        }
        else if (iVar23 == 0x5000) goto LAB_00494078;
LAB_00493f78:
        uVar25 = 0xff;
        uVar13 = 0xe8;
        goto LAB_00493f88;
      }
LAB_00494078:
      if (param_1->session != (SSL_SESSION *)0x0) {
        uVar25 = 0xdd;
        uVar13 = 0xb2;
LAB_00493f88:
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x75,uVar25,"s23_clnt.c",uVar13);
        iVar14 = -1;
        param_1->in_handshake = param_1->in_handshake + -1;
        goto LAB_00493fac;
      }
      param_1->server = 0;
      if (p_Var30 != (_func_3152 *)0x0) {
        (*p_Var30)(param_1,0x10,1);
      }
      param_1->type = 0x1000;
      if (param_1->init_buf == (BUF_MEM *)0x0) {
        pBVar21 = (BUF_MEM *)(*(code *)PTR_BUF_MEM_new_006a859c)();
        if (pBVar21 == (BUF_MEM *)0x0) goto LAB_00494784;
        iVar14 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(pBVar21,0x4000);
        puVar9 = PTR_BUF_MEM_free_006a8594;
        if (iVar14 == 0) {
          param_1->in_handshake = param_1->in_handshake + -1;
          (*(code *)puVar9)(pBVar21);
          iVar14 = -1;
          goto LAB_00493fac;
        }
        param_1->init_buf = pBVar21;
      }
      iVar14 = ssl3_setup_buffers(param_1);
      if (iVar14 == 0) goto LAB_00494784;
      ssl3_init_finished_mac(param_1);
      param_1->state = 0x1210;
      *(int *)(param_1->psk_server_callback + 0x34) =
           *(int *)(param_1->psk_server_callback + 0x34) + 1;
      param_1->init_num = 0;
      pSVar15 = param_1->ctx;
    }
    if (pSVar15 != (SSL_CTX *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(param_1->wbio,0xb,0,0);
    }
    iVar14 = param_1->state;
    if ((p_Var30 != (_func_3152 *)0x0) && (iVar14 != iVar23)) {
      param_1->state = iVar23;
      (*p_Var30)(param_1,0x1001,1);
      param_1->state = iVar14;
    }
  } while( true );
}

