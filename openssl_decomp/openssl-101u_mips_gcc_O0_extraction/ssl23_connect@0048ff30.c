
int ssl23_connect(SSL *param_1)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
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
  SSL_METHOD *pSVar17;
  int iVar18;
  stack_st_SSL_CIPHER *psVar19;
  int iVar20;
  BUF_MEM *pBVar21;
  int iVar22;
  _func_3057 *p_Var23;
  undefined4 uVar24;
  ssl3_state_st *psVar25;
  byte *pbVar26;
  byte *pbVar27;
  int iVar28;
  void *in_t0;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  uint in_t4;
  uint in_t5;
  _func_3152 *p_Var29;
  int iVar30;
  byte *pbVar31;
  byte bVar33;
  byte *pbVar32;
  _func_3150 *p_Var34;
  _func_3152 *p_Var35;
  byte *local_44;
  undefined4 local_38;
  undefined4 local_34;
  uchar local_30;
  uchar local_2f;
  uchar local_2e;
  int local_2c;
  
  puVar10 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_38 = (*(code *)PTR_time_006a9adc)(0);
  (*(code *)PTR_RAND_add_006a8004)(&local_38,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a6ee0)();
  puVar11 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
  p_Var29 = param_1->info_callback;
  *puVar11 = 0;
  if (p_Var29 == (_func_3152 *)0x0) {
    p_Var29 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar12 = SSL_state(param_1);
  if (((uVar12 & 0x3000) == 0) || (uVar12 = SSL_state(param_1), (uVar12 & 0x4000) != 0)) {
    SSL_clear(param_1);
  }
  iVar14 = param_1->state;
  do {
    iVar22 = iVar14;
    if (iVar22 < 0x1212) {
      if (iVar22 < 0x1210) {
        if ((iVar22 != 0x1000) && (iVar22 != 0x1003)) goto LAB_00490048;
        goto LAB_00490148;
      }
      uVar12 = param_1->references;
      param_1->shutdown = 0;
      bVar2 = (uVar12 & 0x1000000) == 0;
      iVar14 = iVar22;
      if ((uVar12 & 0x1000000) == 0) {
        psVar19 = SSL_get_ciphers(param_1);
        for (iVar14 = 0; iVar30 = (*(code *)PTR_sk_num_006a6e2c)(psVar19), iVar14 < iVar30;
            iVar14 = iVar14 + 1) {
          iVar30 = (*(code *)PTR_sk_value_006a6e24)(psVar19,iVar14);
          if (*(int *)(iVar30 + 0x1c) == 1) {
            iVar14 = param_1->state;
            goto LAB_00490218;
          }
        }
        bVar2 = false;
        iVar14 = param_1->state;
      }
LAB_00490218:
      iVar30 = 0x303;
      if (((uVar12 & 0x8000000) != 0) && (iVar30 = 0x302, (uVar12 & 0x16000000) == 0x16000000)) {
        iVar30 = 0x303;
      }
      bVar33 = false;
      if (((int)(uVar12 << 3) < 0) &&
         (uVar16 = uVar12 & 0x6000000 ^ 0x6000000, bVar33 = uVar16 != 0, uVar16 != 0)) {
        iVar30 = 0x301;
      }
      if (((int)(uVar12 << 5) < 0) && ((uVar12 & 0x2000000) != 0x2000000)) {
        bVar33 = false;
        iVar30 = 0x300;
      }
      if (param_1->tlsext_debug_arg != (void *)0x0) {
        bVar2 = false;
      }
      if (param_1->servername_done != -1) {
        bVar2 = false;
      }
      if (iVar14 == 0x1210) {
        pbVar31 = (byte *)param_1->init_buf->data;
        iVar14 = ssl_get_new_session(param_1,0);
        if (iVar14 == 0) goto LAB_004907a4;
        psVar25 = param_1->s3;
        if ((param_1->options & 0x20) == 0) {
          iVar18 = (*(code *)PTR_RAND_bytes_006a7574)(psVar25->client_random,0x20);
        }
        else {
          uVar12 = (*(code *)PTR_time_006a9adc)(0);
          puVar9 = PTR_RAND_bytes_006a7574;
          in_t0 = (void *)(uVar12 >> 0x18);
          psVar25->client_random[3] = (uchar)uVar12;
          psVar25->client_random[0] = (uchar)(uVar12 >> 0x18);
          psVar25->client_random[1] = (uchar)(uVar12 >> 0x10);
          psVar25->client_random[2] = (uchar)(uVar12 >> 8);
          iVar18 = (*(code *)puVar9)(psVar25->client_random + 4,0x1c);
        }
        iVar14 = -1;
        if (iVar18 < 1) goto LAB_00490130;
        if (iVar30 == 0x303) {
          bVar33 = 3;
        }
        else if (iVar30 == 0x302) {
          bVar33 = 2;
        }
        param_1->first_packet = iVar30;
        if (bVar2) {
          pbVar31[4] = bVar33;
          pbVar32 = pbVar31 + 0xb;
          pbVar31[2] = 1;
          pbVar31[3] = 3;
          psVar19 = SSL_get_ciphers(param_1);
          iVar14 = ssl_cipher_list_to_bytes(param_1,psVar19,pbVar32,0);
          if (iVar14 == 0) {
            uVar24 = 0xb5;
            uVar13 = 0x1b2;
            goto LAB_00490c74;
          }
          pbVar31[6] = (byte)iVar14;
          pbVar31[7] = 0;
          pbVar31[8] = 0;
          iVar28 = 0x10;
          pbVar31[5] = (byte)((uint)iVar14 >> 8);
          puVar9 = PTR_memset_006a99f4;
          iVar18 = 0x20;
          uVar12 = param_1->references;
          pbVar31[9] = 0;
          if ((uVar12 & 2) == 0) {
            iVar28 = 0;
          }
          else {
            iVar18 = 0x10;
          }
          pbVar31[10] = (byte)iVar18;
          (*(code *)puVar9)(param_1->s3->client_random,0,0x20);
          iVar20 = (*(code *)PTR_RAND_bytes_006a7574)(param_1->s3->client_random + iVar28,iVar18);
          if (iVar20 < 1) goto LAB_004907a4;
          (*(code *)PTR_memcpy_006a9aec)
                    (pbVar32 + iVar14,param_1->s3->client_random + iVar28,iVar18);
          pbVar32 = pbVar32 + iVar14 + (iVar18 - (int)(pbVar31 + 2));
          pbVar31[1] = (byte)pbVar32;
          *pbVar31 = (byte)((uint)pbVar32 >> 8) | 0x80;
          param_1->init_num = (int)(pbVar32 + 2);
          param_1->init_off = 0;
          ssl3_finish_mac(param_1,pbVar31 + 2);
        }
        else {
          pbVar31[10] = bVar33;
          pbVar31[9] = 3;
          psVar25 = param_1->s3;
          uVar12 = (uint)psVar25->client_random & 3;
          uVar16 = (uint)(psVar25->client_random + 4) & 3;
          uVar3 = (uint)(psVar25->client_random + 8) & 3;
          uVar4 = (uint)(psVar25->client_random + 0xc) & 3;
          uVar5 = (uint)(psVar25->client_random + 0x10) & 3;
          uVar6 = (uint)(psVar25->client_random + 0x14) & 3;
          iVar14 = *(int *)(psVar25->client_random + 0x14 + -uVar6);
          uVar7 = (uint)(psVar25->client_random + 0x18) & 3;
          iVar18 = *(int *)(psVar25->client_random + 0x18 + -uVar7);
          uVar8 = (uint)(psVar25->client_random + 3) & 3;
          in_t5 = (*(int *)(psVar25->client_random + -uVar12) << uVar12 * 8 |
                  in_t5 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar8 + 1) * 8 |
                  *(uint *)(psVar25->client_random + 3 + -uVar8) >> (3 - uVar8) * 8;
          uVar12 = (uint)(psVar25->client_random + 7) & 3;
          in_t4 = (*(int *)(psVar25->client_random + 4 + -uVar16) << uVar16 * 8 |
                  in_t4 & 0xffffffffU >> (4 - uVar16) * 8) & -1 << (uVar12 + 1) * 8 |
                  *(uint *)(psVar25->client_random + 7 + -uVar12) >> (3 - uVar12) * 8;
          uVar12 = (uint)(psVar25->client_random + 0xb) & 3;
          in_t3 = (*(int *)(psVar25->client_random + 8 + -uVar3) << uVar3 * 8 |
                  in_t3 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar12 + 1) * 8 |
                  *(uint *)(psVar25->client_random + 0xb + -uVar12) >> (3 - uVar12) * 8;
          uVar12 = (uint)(psVar25->client_random + 0xf) & 3;
          in_t2 = (*(int *)(psVar25->client_random + 0xc + -uVar4) << uVar4 * 8 |
                  in_t2 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar12 + 1) * 8 |
                  *(uint *)(psVar25->client_random + 0xf + -uVar12) >> (3 - uVar12) * 8;
          uVar12 = (uint)(psVar25->client_random + 0x13) & 3;
          in_t1 = (*(int *)(psVar25->client_random + 0x10 + -uVar5) << uVar5 * 8 |
                  in_t1 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar12 + 1) * 8 |
                  *(uint *)(psVar25->client_random + 0x13 + -uVar12) >> (3 - uVar12) * 8;
          uVar12 = (uint)(psVar25->client_random + 0x17) & 3;
          uVar3 = *(uint *)(psVar25->client_random + 0x17 + -uVar12);
          uVar16 = (uint)(psVar25->client_random + 0x1b) & 3;
          uVar4 = *(uint *)(psVar25->client_random + 0x1b + -uVar16);
          uVar13 = *(undefined4 *)(psVar25->client_random + 0x1c);
          *(uint *)(pbVar31 + 0xb) = in_t5;
          *(uint *)(pbVar31 + 0xf) = in_t4;
          *(uint *)(pbVar31 + 0x13) = in_t3;
          *(uint *)(pbVar31 + 0x17) = in_t2;
          *(uint *)(pbVar31 + 0x1b) = in_t1;
          *(uint *)(pbVar31 + 0x1f) =
               (iVar14 << uVar6 * 8 | (uint)in_t0 & 0xffffffffU >> (4 - uVar6) * 8) &
               -1 << (uVar12 + 1) * 8 | uVar3 >> (3 - uVar12) * 8;
          *(uint *)(pbVar31 + 0x23) =
               (iVar18 << uVar7 * 8 | (uint)(pbVar31 + 9) & 0xffffffffU >> (4 - uVar7) * 8) &
               -1 << (uVar16 + 1) * 8 | uVar4 >> (3 - uVar16) * 8;
          *(undefined4 *)(pbVar31 + 0x27) = uVar13;
          pbVar31[0x2b] = 0;
          psVar19 = SSL_get_ciphers(param_1);
          iVar14 = ssl_cipher_list_to_bytes
                             (param_1,psVar19,pbVar31 + 0x2e,PTR_ssl3_put_cipher_by_char_006a7f64);
          if (iVar14 == 0) {
            uVar24 = 0xb5;
            uVar13 = 0x1f6;
            goto LAB_00490c74;
          }
          pbVar31[0x2d] = (byte)iVar14;
          pbVar31[0x2c] = (byte)((uint)iVar14 >> 8);
          if ((param_1->references << 0xe < 0) ||
             (*(int *)(param_1->psk_server_callback + 0x98) == 0)) {
            pbVar31[iVar14 + 0x2e] = 1;
            local_44 = pbVar31 + iVar14 + 0x2f;
          }
          else {
            iVar18 = (*(code *)PTR_sk_num_006a6e2c)();
            pbVar31[iVar14 + 0x2e] = (char)iVar18 + 1;
            pbVar32 = pbVar31 + iVar14 + 0x2f;
            local_44 = pbVar32;
            if (0 < iVar18) {
              local_44 = pbVar32 + iVar18;
              pbVar26 = pbVar32;
              do {
                pbVar27 = pbVar26 + 1;
                puVar11 = (undefined4 *)
                          (*(code *)PTR_sk_value_006a6e24)
                                    (*(undefined4 *)(param_1->psk_server_callback + 0x98),
                                     (int)pbVar26 - (int)pbVar32);
                *pbVar26 = (byte)*puVar11;
                pbVar26 = pbVar27;
              } while (pbVar27 != local_44);
            }
          }
          *local_44 = 0;
          iVar14 = ssl_prepare_clienthello_tlsext(param_1);
          if (iVar14 < 1) {
            uVar24 = 0xe2;
            uVar13 = 0x21a;
            goto LAB_00490c74;
          }
          iVar14 = ssl_add_clienthello_tlsext(param_1,local_44 + 1,pbVar31 + 0x4000);
          if (iVar14 == 0) goto LAB_00490cfc;
          iVar18 = iVar14 - (int)(pbVar31 + 9);
          pbVar31[5] = 1;
          pbVar31[8] = (byte)iVar18;
          uVar12 = iVar18 + 4;
          pbVar31[6] = (byte)((uint)iVar18 >> 0x10);
          pbVar31[7] = (byte)((uint)iVar18 >> 8);
          if (0x4000 < uVar12) {
            uVar24 = 0x44;
            uVar13 = 0x231;
            goto LAB_00490c74;
          }
          *pbVar31 = 0x16;
          pbVar31[1] = 3;
          if ((param_1->first_packet >> 8 == 3) && (0x301 < param_1->first_packet)) {
            bVar33 = 1;
          }
          in_t0 = (void *)((int)uVar12 >> 8);
          pbVar31[2] = bVar33;
          pbVar31[4] = (byte)uVar12;
          pbVar31[3] = (byte)(uVar12 >> 8);
          param_1->init_num = iVar14 - (int)pbVar31;
          param_1->init_off = 0;
          ssl3_finish_mac(param_1,pbVar31 + 5,(iVar14 - (int)pbVar31) + -5);
        }
        param_1->init_off = 0;
        param_1->state = 0x1211;
      }
      iVar14 = ssl23_write_bytes(param_1);
      if (iVar14 < 2) {
        if (iVar14 != 1) {
          iVar22 = param_1->in_handshake;
          while( true ) {
            param_1->in_handshake = iVar22 + -1;
LAB_0049007c:
            if (p_Var29 != (_func_3152 *)0x0) {
              (*p_Var29)(param_1,0x1002,iVar14);
            }
            if (local_2c == *(int *)puVar10) break;
            (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00490cfc:
            uVar24 = 0x44;
            uVar13 = 0x222;
LAB_00490c74:
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x74,uVar24,"s23_clnt.c",uVar13);
            iVar14 = -1;
LAB_00490130:
            iVar22 = param_1->in_handshake;
          }
          return iVar14;
        }
      }
      else {
        p_Var34 = param_1->msg_callback;
        if (p_Var34 != (_func_3150 *)0x0) {
          if (bVar2) {
            in_t0 = param_1->msg_callback_arg;
            (*p_Var34)(1,2,0,param_1->init_buf->data + 2,iVar14 - 2,param_1,in_t0);
          }
          else {
            in_t0 = param_1->msg_callback_arg;
            (*p_Var34)(1,iVar30,0x16,param_1->init_buf->data + 5,iVar14 - 5,param_1,in_t0);
          }
        }
      }
      param_1->init_num = 0;
      param_1->state = 0x1220;
      pSVar15 = param_1->ctx;
    }
    else {
      if (iVar22 != 0x4000) {
        if (iVar22 < 0x4001) {
          if (iVar22 - 0x1220U < 2) {
            iVar14 = ssl23_read_bytes(param_1,7);
            if (iVar14 != 7) goto LAB_00490128;
            puVar11 = (undefined4 *)param_1->packet;
            local_34 = *puVar11;
            local_2f = *(uchar *)((int)puVar11 + 5);
            local_30 = *(uchar *)(puVar11 + 1);
            local_2e = *(uchar *)((int)puVar11 + 6);
            cVar1 = *(char *)puVar11;
            if ((cVar1 < '\0') && (*(char *)((int)puVar11 + 2) == '\x04')) {
              if ((*(char *)((int)puVar11 + 5) == '\0') && (local_2e == '\x02')) {
                uVar24 = 0x102;
                uVar13 = 0x272;
                goto LAB_00490a20;
              }
            }
            else if ((*(char *)((int)puVar11 + 1) == '\x03') &&
                    (bVar33 = *(byte *)((int)puVar11 + 2), bVar33 < 4)) {
              if (cVar1 == '\x16') {
                cVar1 = *(char *)((int)puVar11 + 5);
              }
              else {
                if ((cVar1 != '\x15') || (*(char *)((int)puVar11 + 3) != '\0')) goto LAB_00490af4;
                cVar1 = *(char *)(puVar11 + 1);
              }
              if (cVar1 == '\x02') {
                if (bVar33 == 0) {
                  if (param_1->references << 6 < 0) goto LAB_00490a10;
                  param_1->version = 0x300;
                  pSVar17 = SSLv3_client_method();
                  param_1->method = pSVar17;
                }
                else if (bVar33 == 1) {
                  if (param_1->references << 5 < 0) goto LAB_00490a10;
                  param_1->version = 0x301;
                  pSVar17 = TLSv1_client_method();
                  param_1->method = pSVar17;
                }
                else if (bVar33 == 2) {
                  if (param_1->references << 3 < 0) goto LAB_00490a10;
                  param_1->version = 0x302;
                  pSVar17 = TLSv1_1_client_method();
                  param_1->method = pSVar17;
                }
                else {
                  if (param_1->references << 4 < 0) {
LAB_00490a10:
                    uVar24 = 0x102;
                    uVar13 = 0x2d6;
                    goto LAB_00490a20;
                  }
                  param_1->version = 0x303;
                  pSVar17 = TLSv1_2_client_method();
                  param_1->method = pSVar17;
                }
                iVar14 = param_1->version;
                param_1->session->ssl_version = iVar14;
                if (0x303 < iVar14) {
                  (*(code *)PTR_OpenSSLDie_006a7c5c)
                            ("s23_clnt.c",0x2dd,"s->version <= TLS_MAX_VERSION");
                }
                if ((*(char *)puVar11 == '\x15') && (*(char *)((int)puVar11 + 5) != '\x01')) {
                  p_Var35 = param_1->info_callback;
                  if ((p_Var35 == (_func_3152 *)0x0) &&
                     (p_Var35 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
                     p_Var35 == (_func_3152 *)0x0)) {
                    p_Var34 = param_1->msg_callback;
                  }
                  else {
                    (*p_Var35)(param_1,0x4004,(int)*(undefined2 *)((int)puVar11 + 5));
                    p_Var34 = param_1->msg_callback;
                  }
                  if (p_Var34 != (_func_3150 *)0x0) {
                    (*p_Var34)(0,param_1->version,0x15,(char *)((int)puVar11 + 5),2,param_1,
                               param_1->msg_callback_arg);
                  }
                  puVar9 = PTR_ERR_put_error_006a7f34;
                  param_1->rwstate = 1;
                  (*(code *)puVar9)(0x14,0x77,*(byte *)((int)puVar11 + 6) + 1000,"s23_clnt.c",0x2f5)
                  ;
LAB_004907a4:
                  iVar14 = -1;
                  goto LAB_00490130;
                }
                iVar14 = ssl_init_wbio_buffer(param_1,1);
                if (iVar14 == 0) goto LAB_004907a4;
                param_1->state = 0x1120;
                puVar11 = (undefined4 *)(param_1->s3->rbuf).buf;
                param_1->rstate = 0xf0;
                param_1->packet_length = 7;
                if (puVar11 == (undefined4 *)0x0) {
                  iVar14 = ssl3_setup_read_buffer(param_1);
                  if (iVar14 == 0) goto LAB_004907a4;
                  puVar11 = (undefined4 *)(param_1->s3->rbuf).buf;
                }
                param_1->packet = (uchar *)puVar11;
                *puVar11 = local_34;
                *(uchar *)((int)puVar11 + 6) = local_2e;
                *(uchar *)(puVar11 + 1) = local_30;
                *(uchar *)((int)puVar11 + 5) = local_2f;
                psVar25 = param_1->s3;
                p_Var23 = param_1->method->ssl_connect;
                (psVar25->rbuf).left = 7;
                (psVar25->rbuf).offset = 0;
                param_1->init_num = 0;
                param_1->handshake_func = (_func_3149 *)p_Var23;
                iVar14 = SSL_connect(param_1);
LAB_00490128:
                if (iVar14 < 0) goto LAB_00490130;
                p_Var29 = (_func_3152 *)0x0;
                goto LAB_00490130;
              }
            }
LAB_00490af4:
            uVar24 = 0xfc;
            uVar13 = 0x30e;
LAB_00490a20:
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x77,uVar24,"s23_clnt.c",uVar13);
            iVar14 = -1;
            goto LAB_00490130;
          }
        }
        else if (iVar22 == 0x5000) goto LAB_00490148;
LAB_00490048:
        uVar24 = 0xff;
        uVar13 = 0xeb;
        goto LAB_00490058;
      }
LAB_00490148:
      if (param_1->session != (SSL_SESSION *)0x0) {
        uVar24 = 0xdd;
        uVar13 = 0xb2;
LAB_00490058:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x75,uVar24,"s23_clnt.c",uVar13);
        iVar14 = -1;
        param_1->in_handshake = param_1->in_handshake + -1;
        goto LAB_0049007c;
      }
      param_1->server = 0;
      if (p_Var29 != (_func_3152 *)0x0) {
        (*p_Var29)(param_1,0x10,1);
      }
      param_1->type = 0x1000;
      if (param_1->init_buf == (BUF_MEM *)0x0) {
        pBVar21 = (BUF_MEM *)(*(code *)PTR_BUF_MEM_new_006a749c)();
        if (pBVar21 == (BUF_MEM *)0x0) goto LAB_004907a4;
        iVar14 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(pBVar21,0x4000);
        puVar9 = PTR_BUF_MEM_free_006a7494;
        if (iVar14 == 0) {
          param_1->in_handshake = param_1->in_handshake + -1;
          (*(code *)puVar9)(pBVar21);
          iVar14 = -1;
          goto LAB_0049007c;
        }
        param_1->init_buf = pBVar21;
      }
      iVar14 = ssl3_setup_buffers(param_1);
      if (iVar14 == 0) goto LAB_004907a4;
      ssl3_init_finished_mac(param_1);
      param_1->state = 0x1210;
      *(int *)(param_1->psk_server_callback + 0x34) =
           *(int *)(param_1->psk_server_callback + 0x34) + 1;
      param_1->init_num = 0;
      pSVar15 = param_1->ctx;
    }
    if (pSVar15 != (SSL_CTX *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(param_1->wbio,0xb,0,0);
    }
    iVar14 = param_1->state;
    if ((p_Var29 != (_func_3152 *)0x0) && (iVar14 != iVar22)) {
      param_1->state = iVar22;
      (*p_Var29)(param_1,0x1001,1);
      param_1->state = iVar14;
    }
  } while( true );
}

