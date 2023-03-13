
/* WARNING: Could not reconcile some variable overlaps */

uint ssl23_get_client_hello(SSL *param_1)

{
  byte bVar1;
  uchar *puVar2;
  char *pcVar3;
  char cVar4;
  ushort uVar5;
  SSL_METHOD *pSVar6;
  uint uVar7;
  ssl3_state_st *psVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  uint uVar13;
  uchar *puVar14;
  uchar *puVar15;
  int in_GS_OFFSET;
  bool bVar16;
  byte bVar17;
  int iVar18;
  int line;
  uint local_44;
  undefined local_30 [3];
  undefined2 uStack_2d;
  undefined4 local_2b [2];
  undefined2 local_23;
  byte local_21;
  int local_20;
  
  bVar17 = 0;
  uVar10 = 0;
  local_44 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1->state != 0x2210) goto LAB_080a857e;
  iVar18 = ssl3_setup_buffers(param_1);
  if (iVar18 == 0) goto LAB_080a88be;
  uVar7 = ssl23_read_bytes(param_1,0xb);
  if (uVar7 == 0xb) {
    puVar9 = (undefined4 *)param_1->packet;
    local_2b[0] = *puVar9;
    local_2b[1] = puVar9[1];
    local_23 = *(undefined2 *)(puVar9 + 2);
    local_21 = *(byte *)((int)puVar9 + 10);
    local_44 = uVar7;
    if ((char)*(byte *)puVar9 < '\0') {
      bVar16 = *(byte *)((int)puVar9 + 2) == 1;
      if (!bVar16) goto LAB_080a893c;
      if (*(byte *)((int)puVar9 + 3) == 0) {
        if (*(byte *)(puVar9 + 1) == 2) {
          uVar10 = (*(byte *)((int)&param_1->references + 3) ^ 1) & 1;
        }
      }
      else if (*(byte *)((int)puVar9 + 3) == 3) {
        bVar1 = *(byte *)(puVar9 + 1);
        if (bVar1 == 0) {
          uVar10 = param_1->references;
LAB_080a8cb4:
          if ((uVar10 & 0x2000000) != 0) {
            uVar10 = (uVar10 >> 0x18 ^ 1) & 1;
            goto LAB_080a857e;
          }
          param_1->version = 0x300;
          param_1->state = 0x2211;
        }
        else {
          uVar10 = param_1->references;
          if (bVar1 < 3) {
            if (bVar1 == 2) {
LAB_080a8d0c:
              if ((uVar10 & 0x10000000) == 0) {
                param_1->version = 0x302;
                param_1->state = 0x2211;
                goto LAB_080a8606;
              }
            }
            if ((uVar10 & 0x4000000) != 0) goto LAB_080a8cb4;
            param_1->version = 0x301;
            param_1->state = 0x2211;
          }
          else {
            if ((uVar10 & 0x8000000) != 0) goto LAB_080a8d0c;
            param_1->version = 0x303;
            param_1->state = 0x2211;
          }
        }
        goto LAB_080a8606;
      }
LAB_080a857e:
      if (0x303 < param_1->version) {
        OpenSSLDie("s23_srvr.c",0x193,"s->version <= TLS_MAX_VERSION");
        if (param_1->state != 0x2211) goto LAB_080a858f;
LAB_080a8603:
        puVar9 = (undefined4 *)param_1->packet;
LAB_080a8606:
        bVar1 = *(byte *)(puVar9 + 1);
        local_44 = (*(byte *)puVar9 & 0x7f) << 8 | (uint)*(byte *)((int)puVar9 + 1);
        if (local_44 < 0x1001) {
          if (local_44 < 9) {
            line = 0x1bc;
            iVar18 = 0xd5;
          }
          else {
            uVar7 = ssl23_read_bytes(param_1,local_44 + 2);
            if ((int)uVar7 < 1) goto LAB_080a88c3;
            ssl3_finish_mac(param_1,param_1->packet + 2,param_1->packet_length - 2);
            if (param_1->msg_callback != (_func_3150 *)0x0) {
              (*param_1->msg_callback)
                        (0,2,0,param_1->packet + 2,param_1->packet_length - 2,param_1,
                         param_1->msg_callback_arg);
            }
            puVar2 = param_1->packet;
            pcVar3 = param_1->init_buf->data;
            uVar5 = *(ushort *)(puVar2 + 5) << 8 | *(ushort *)(puVar2 + 5) >> 8;
            uVar10 = (uint)(ushort)(*(ushort *)(puVar2 + 9) << 8 | *(ushort *)(puVar2 + 9) >> 8);
            iVar18 = (uint)(ushort)(*(ushort *)(puVar2 + 7) << 8 | *(ushort *)(puVar2 + 7) >> 8) +
                     (uint)uVar5;
            if (uVar10 + 0xb + iVar18 == param_1->packet_length) {
              _local_30 = pcVar3 + 6;
              *pcVar3 = '\x01';
              pcVar3[4] = '\x03';
              pcVar3[5] = bVar1;
              uVar7 = 0x20;
              if (uVar10 < 0x21) {
                uVar7 = uVar10;
              }
              uVar10 = 0;
              *(undefined4 *)(pcVar3 + 6) = 0;
              *(undefined4 *)(pcVar3 + 0x22) = 0;
              do {
                *(undefined4 *)(((uint)(pcVar3 + 10) & 0xfffffffc) + uVar10) = 0;
                uVar10 = uVar10 + 4;
              } while (uVar10 < ((uint)(_local_30 + (0x20 - ((uint)(pcVar3 + 10) & 0xfffffffc))) &
                                0xfffffffc));
              puVar9 = (undefined4 *)(puVar2 + iVar18 + 0xb);
              puVar11 = (undefined4 *)(_local_30 + (0x20 - uVar7));
              if (uVar7 < 4) {
                if ((uVar7 != 0) && (*(undefined *)puVar11 = *(undefined *)puVar9, (uVar7 & 2) != 0)
                   ) {
                  *(undefined2 *)(_local_30 + 0x1e) = *(undefined2 *)((int)puVar9 + (uVar7 - 2));
                }
              }
              else {
                *puVar11 = *puVar9;
                *(undefined4 *)(_local_30 + 0x1c) = *(undefined4 *)((uVar7 - 4) + (int)puVar9);
                iVar18 = (int)puVar11 - ((uint)(_local_30 + (0x24 - uVar7)) & 0xfffffffc);
                uVar10 = iVar18 + uVar7 & 0xfffffffc;
                if (3 < uVar10) {
                  uVar13 = 0;
                  do {
                    *(undefined4 *)(((uint)(_local_30 + (0x24 - uVar7)) & 0xfffffffc) + uVar13) =
                         *(undefined4 *)((int)puVar9 + (uVar13 - iVar18));
                    uVar13 = uVar13 + 4;
                  } while (uVar13 < uVar10);
                }
              }
              pcVar3[0x26] = '\0';
              puVar15 = (uchar *)(pcVar3 + 0x29);
              if (uVar5 == 0) {
                iVar18 = 0;
                cVar4 = '\0';
              }
              else {
                iVar18 = 0;
                uVar10 = 0;
                puVar14 = puVar15;
                do {
                  puVar15 = puVar14;
                  if (puVar2[uVar10 + 0xb] == '\0') {
                    iVar18 = iVar18 + 2;
                    puVar15 = puVar14 + 2;
                    *puVar14 = puVar2[uVar10 + 0xc];
                    puVar14[1] = puVar2[uVar10 + 0xd];
                  }
                  uVar10 = uVar10 + 3;
                  puVar14 = puVar15;
                } while (uVar10 < uVar5);
                cVar4 = (char)((uint)iVar18 >> 8);
              }
              pcVar3[0x28] = (char)iVar18;
              pcVar3[0x27] = cVar4;
              *puVar15 = '\x01';
              puVar15[1] = '\0';
              puVar15 = puVar15 + (-2 - (int)param_1->init_buf->data);
              pcVar3[3] = (char)puVar15;
              pcVar3[1] = (char)((uint)puVar15 >> 0x10);
              uVar10 = 2;
              pcVar3[2] = (char)((uint)puVar15 >> 8);
              psVar8 = param_1->s3;
              (psVar8->tmp).reuse_message = 1;
              (psVar8->tmp).message_type = 1;
              (psVar8->tmp).message_size = (ulong)puVar15;
              goto LAB_080a8816;
            }
            line = 0x1de;
            iVar18 = 0xd5;
          }
        }
        else {
          line = 0x1b7;
          iVar18 = 0xd6;
        }
        goto LAB_080a88b2;
      }
      if (param_1->state == 0x2211) goto LAB_080a8603;
LAB_080a858f:
      if (uVar10 != 1) goto LAB_080a8598;
      line = 0x21d;
LAB_080a88a8:
      iVar18 = 0x102;
LAB_080a88b2:
      ERR_put_error(0x14,0x76,iVar18,"s23_srvr.c",line);
    }
    else {
      bVar16 = *(byte *)puVar9 == 0x16;
      if (((!bVar16) || (bVar16 = *(byte *)((int)puVar9 + 1) == 3, !bVar16)) ||
         (bVar16 = *(byte *)((int)puVar9 + 5) == 1, !bVar16)) {
LAB_080a893c:
        iVar18 = 4;
        pbVar12 = &DAT_081f4da4;
        puVar11 = puVar9;
        do {
          if (iVar18 == 0) break;
          iVar18 = iVar18 + -1;
          bVar16 = *pbVar12 == *(byte *)puVar11;
          pbVar12 = pbVar12 + (uint)bVar17 * -2 + 1;
          puVar11 = (undefined4 *)((int)puVar11 + (uint)bVar17 * -2 + 1);
        } while (bVar16);
        if (!bVar16) {
          iVar18 = 5;
          pbVar12 = (byte *)"POST ";
          puVar11 = puVar9;
          do {
            if (iVar18 == 0) break;
            iVar18 = iVar18 + -1;
            bVar16 = *pbVar12 == *(byte *)puVar11;
            pbVar12 = pbVar12 + (uint)bVar17 * -2 + 1;
            puVar11 = (undefined4 *)((int)puVar11 + (uint)bVar17 * -2 + 1);
          } while (bVar16);
          if (!bVar16) {
            iVar18 = 5;
            pbVar12 = (byte *)"HEAD ";
            puVar11 = puVar9;
            do {
              if (iVar18 == 0) break;
              iVar18 = iVar18 + -1;
              bVar16 = *pbVar12 == *(byte *)puVar11;
              pbVar12 = pbVar12 + (uint)bVar17 * -2 + 1;
              puVar11 = (undefined4 *)((int)puVar11 + (uint)bVar17 * -2 + 1);
            } while (bVar16);
            if (!bVar16) {
              iVar18 = 4;
              pbVar12 = &DAT_081ff4cb;
              puVar11 = puVar9;
              do {
                if (iVar18 == 0) break;
                iVar18 = iVar18 + -1;
                bVar16 = *pbVar12 == *(byte *)puVar11;
                pbVar12 = pbVar12 + (uint)bVar17 * -2 + 1;
                puVar11 = (undefined4 *)((int)puVar11 + (uint)bVar17 * -2 + 1);
              } while (bVar16);
              if (!bVar16) {
                iVar18 = 7;
                pbVar12 = (byte *)0x82040fb;
                do {
                  if (iVar18 == 0) break;
                  iVar18 = iVar18 + -1;
                  bVar16 = *pbVar12 == *(byte *)puVar9;
                  pbVar12 = pbVar12 + (uint)bVar17 * -2 + 1;
                  puVar9 = (undefined4 *)((int)puVar9 + (uint)bVar17 * -2 + 1);
                } while (bVar16);
                if (!bVar16) goto LAB_080a899c;
                line = 0x18d;
                iVar18 = 0x9b;
                goto LAB_080a88b2;
              }
            }
          }
        }
        line = 0x18a;
        iVar18 = 0x9c;
        goto LAB_080a88b2;
      }
      if (*(byte *)((int)puVar9 + 3) == 0) {
        if (4 < *(byte *)(puVar9 + 1)) {
          bVar16 = *(byte *)((int)puVar9 + 9) == 2;
          if (*(byte *)((int)puVar9 + 9) < 3) goto LAB_080a893c;
          if (5 < *(byte *)(puVar9 + 1)) goto LAB_080a8c5d;
        }
        line = 0x15c;
        iVar18 = 0x12a;
        goto LAB_080a88b2;
      }
      bVar16 = *(byte *)((int)puVar9 + 9) == 2;
      if (*(byte *)((int)puVar9 + 9) < 3) goto LAB_080a893c;
LAB_080a8c5d:
      if (*(byte *)((int)puVar9 + 9) < 4) {
        bVar1 = *(byte *)((int)puVar9 + 10);
        if (bVar1 == 0) {
          if ((param_1->references & 0x2000000U) != 0) {
            if ((param_1->references & 0x4000000U) == 0) goto LAB_080a8c91;
LAB_080a899c:
            uVar10 = 0;
            goto LAB_080a857e;
          }
LAB_080a8d52:
          param_1->version = 0x300;
        }
        else {
          if (2 < bVar1) goto LAB_080a8d70;
          uVar10 = param_1->references;
          if (bVar1 != 1) goto LAB_080a8d5d;
LAB_080a8d3a:
          if ((uVar10 & 0x4000000) != 0) {
            if ((uVar10 & 0x2000000) != 0) goto LAB_080a899c;
            goto LAB_080a8d52;
          }
LAB_080a8c91:
          param_1->version = 0x301;
        }
      }
      else {
LAB_080a8d70:
        uVar10 = param_1->references;
        if ((uVar10 & 0x8000000) == 0) {
          param_1->version = 0x303;
        }
        else {
LAB_080a8d5d:
          if ((uVar10 & 0x10000000) != 0) goto LAB_080a8d3a;
          param_1->version = 0x302;
        }
      }
      if (param_1->state == 0x2211) goto LAB_080a8606;
      uVar10 = 3;
LAB_080a8598:
      if (1 < uVar10 - 2) {
LAB_080a85a6:
        if (uVar10 - 1 < 3) {
          iVar18 = *(int *)(in_GS_OFFSET + 0x14);
          param_1->init_num = 0;
          if (local_20 == iVar18) {
            uVar10 = SSL_accept(param_1);
            return uVar10;
          }
          goto LAB_080a8c4e;
        }
        line = 0x27b;
        iVar18 = 0xfc;
        goto LAB_080a88b2;
      }
LAB_080a8816:
      iVar18 = param_1->version;
      if (iVar18 != 0x300) {
        if (iVar18 == 0x301) {
          pSVar6 = TLSv1_server_method();
          goto LAB_080a8845;
        }
        if (iVar18 == 0x302) {
          pSVar6 = TLSv1_1_server_method();
          goto LAB_080a8845;
        }
        if (iVar18 == 0x303) {
          pSVar6 = TLSv1_2_server_method();
          goto LAB_080a8845;
        }
LAB_080a88a0:
        line = 0x255;
        goto LAB_080a88a8;
      }
      pSVar6 = SSLv3_server_method();
LAB_080a8845:
      if (pSVar6 == (SSL_METHOD *)0x0) goto LAB_080a88a0;
      param_1->method = pSVar6;
      iVar18 = ssl_init_wbio_buffer(param_1,1);
      if (iVar18 != 0) {
        param_1->state = 0x2110;
        if (uVar10 == 3) {
          psVar8 = param_1->s3;
          param_1->rstate = 0xf0;
          param_1->packet_length = local_44;
          puVar9 = (undefined4 *)(psVar8->rbuf).buf;
          if (puVar9 == (undefined4 *)0x0) {
            iVar18 = ssl3_setup_read_buffer(param_1);
            if (iVar18 == 0) goto LAB_080a88be;
            psVar8 = param_1->s3;
            puVar9 = (undefined4 *)(psVar8->rbuf).buf;
          }
          param_1->packet = (uchar *)puVar9;
          if (local_44 < 4) {
            if (local_44 != 0) {
              *(uchar *)puVar9 = (uchar)local_2b[0];
              if ((local_44 & 2) == 0) goto LAB_080a8a21;
              *(undefined2 *)((int)puVar9 + (local_44 - 2)) =
                   *(undefined2 *)(local_30 + local_44 + 3);
              psVar8 = param_1->s3;
            }
          }
          else {
            *puVar9 = local_2b[0];
            *(undefined4 *)((int)puVar9 + (local_44 - 4)) = *(undefined4 *)(local_30 + local_44 + 1)
            ;
            iVar18 = (int)puVar9 - (int)(undefined4 *)((uint)(puVar9 + 1) & 0xfffffffc);
            puVar11 = (undefined4 *)((int)local_2b - iVar18);
            puVar9 = (undefined4 *)((uint)(puVar9 + 1) & 0xfffffffc);
            for (uVar7 = iVar18 + local_44 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
              *puVar9 = *puVar11;
              puVar11 = puVar11 + (uint)bVar17 * -2 + 1;
              puVar9 = puVar9 + (uint)bVar17 * -2 + 1;
            }
LAB_080a8a21:
            psVar8 = param_1->s3;
          }
          (psVar8->rbuf).offset = 0;
          (psVar8->rbuf).left = local_44;
        }
        else {
          psVar8 = param_1->s3;
          param_1->packet_length = 0;
          (psVar8->rbuf).left = 0;
          (psVar8->rbuf).offset = 0;
        }
        param_1->handshake_func = (_func_3149 *)param_1->method->ssl_accept;
        goto LAB_080a85a6;
      }
    }
LAB_080a88be:
    uVar7 = 0xffffffff;
  }
LAB_080a88c3:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar7;
  }
LAB_080a8c4e:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

