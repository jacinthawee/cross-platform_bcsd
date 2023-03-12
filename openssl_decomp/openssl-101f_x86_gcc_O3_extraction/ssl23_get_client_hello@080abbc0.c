
/* WARNING: Could not reconcile some variable overlaps */

uint ssl23_get_client_hello(SSL *param_1)

{
  uchar *puVar1;
  char *pcVar2;
  ssl2_state_st *psVar3;
  ushort uVar4;
  undefined4 *puVar5;
  SSL_METHOD *pSVar6;
  ssl3_state_st *psVar7;
  uint uVar8;
  char cVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  uchar *puVar14;
  uchar *puVar15;
  int iVar16;
  int iVar17;
  byte *pbVar18;
  int iVar19;
  int in_GS_OFFSET;
  bool bVar20;
  byte bVar21;
  undefined local_30 [3];
  undefined2 uStack_2d;
  undefined4 local_2b [2];
  undefined2 local_23;
  byte local_21;
  int local_20;
  
  bVar21 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar17 = param_1->state;
  if (iVar17 == 0x2210) {
    iVar17 = ssl3_setup_buffers(param_1);
    if (iVar17 == 0) goto LAB_080abebe;
    uVar12 = ssl23_read_bytes(param_1,0xb);
    if (uVar12 == 0xb) {
      puVar5 = (undefined4 *)param_1->packet;
      local_2b[0] = *puVar5;
      local_2b[1] = puVar5[1];
      local_23 = *(undefined2 *)(puVar5 + 2);
      local_21 = *(byte *)((int)puVar5 + 10);
      if (-1 < (char)*(byte *)puVar5) {
        bVar20 = *(byte *)puVar5 == 0x16;
        if (((!bVar20) || (bVar20 = *(byte *)((int)puVar5 + 1) == 3, !bVar20)) ||
           (bVar20 = *(byte *)((int)puVar5 + 5) == 1, !bVar20)) goto LAB_080abf3a;
        if (*(byte *)((int)puVar5 + 3) != 0) {
          bVar20 = *(byte *)((int)puVar5 + 9) == 2;
          if (*(byte *)((int)puVar5 + 9) < 3) goto LAB_080abf3a;
LAB_080ac281:
          if (3 < *(byte *)((int)puVar5 + 9)) {
LAB_080ac2fd:
            uVar8 = param_1->references;
            if ((uVar8 & 0x8000000) == 0) {
              param_1->version = 0x303;
              iVar17 = param_1->state;
              iVar11 = 1;
              iVar16 = 3;
              iVar19 = 3;
              goto LAB_080abbf0;
            }
LAB_080ac2d3:
            if ((uVar8 & 0x10000000) == 0) {
              param_1->version = 0x302;
              iVar17 = param_1->state;
              iVar11 = 1;
              iVar16 = 3;
              iVar19 = 3;
              goto LAB_080abbf0;
            }
            goto LAB_080ac1ba;
          }
          bVar21 = *(byte *)((int)puVar5 + 10);
          if (bVar21 != 0) {
            if (2 < bVar21) goto LAB_080ac2fd;
            uVar8 = param_1->references;
            if (bVar21 == 1) goto LAB_080ac1ba;
            goto LAB_080ac2d3;
          }
          if ((param_1->references & 0x2000000U) == 0) goto LAB_080ac3b6;
          if ((param_1->references & 0x4000000U) != 0) goto LAB_080ac2ab;
LAB_080ac1c6:
          param_1->version = 0x301;
          iVar17 = param_1->state;
          iVar11 = 1;
          iVar16 = 3;
          iVar19 = 3;
          goto LAB_080abbf0;
        }
        if (4 < *(byte *)(puVar5 + 1)) {
          bVar20 = *(byte *)((int)puVar5 + 9) == 2;
          if (*(byte *)((int)puVar5 + 9) < 3) goto LAB_080abf3a;
          if (5 < *(byte *)(puVar5 + 1)) goto LAB_080ac281;
        }
        uVar8 = param_1->references;
LAB_080ac1ba:
        if ((uVar8 & 0x4000000) == 0) goto LAB_080ac1c6;
        if ((uVar8 & 0x2000000) == 0) {
LAB_080ac3b6:
          param_1->version = 0x300;
          iVar17 = param_1->state;
          iVar11 = 1;
          iVar16 = 3;
          iVar19 = 3;
          goto LAB_080abbf0;
        }
LAB_080ac2ab:
        if (param_1->state != 0x2211) goto LAB_080ac2b8;
        goto LAB_080ac000;
      }
      bVar20 = *(byte *)((int)puVar5 + 2) == 1;
      if (!bVar20) {
LAB_080abf3a:
        iVar17 = 4;
        pbVar18 = &DAT_081f4785;
        puVar13 = puVar5;
        do {
          if (iVar17 == 0) break;
          iVar17 = iVar17 + -1;
          bVar20 = *pbVar18 == *(byte *)puVar13;
          pbVar18 = pbVar18 + (uint)bVar21 * -2 + 1;
          puVar13 = (undefined4 *)((int)puVar13 + (uint)bVar21 * -2 + 1);
        } while (bVar20);
        if (!bVar20) {
          iVar17 = 5;
          pbVar18 = (byte *)"POST ";
          puVar13 = puVar5;
          do {
            if (iVar17 == 0) break;
            iVar17 = iVar17 + -1;
            bVar20 = *pbVar18 == *(byte *)puVar13;
            pbVar18 = pbVar18 + (uint)bVar21 * -2 + 1;
            puVar13 = (undefined4 *)((int)puVar13 + (uint)bVar21 * -2 + 1);
          } while (bVar20);
          if (!bVar20) {
            iVar17 = 5;
            pbVar18 = (byte *)"HEAD ";
            puVar13 = puVar5;
            do {
              if (iVar17 == 0) break;
              iVar17 = iVar17 + -1;
              bVar20 = *pbVar18 == *(byte *)puVar13;
              pbVar18 = pbVar18 + (uint)bVar21 * -2 + 1;
              puVar13 = (undefined4 *)((int)puVar13 + (uint)bVar21 * -2 + 1);
            } while (bVar20);
            if (bVar20) goto LAB_080ac1e8;
            iVar17 = 4;
            pbVar18 = &DAT_081ff012;
            puVar13 = puVar5;
            do {
              if (iVar17 == 0) break;
              iVar17 = iVar17 + -1;
              bVar20 = *pbVar18 == *(byte *)puVar13;
              pbVar18 = pbVar18 + (uint)bVar21 * -2 + 1;
              puVar13 = (undefined4 *)((int)puVar13 + (uint)bVar21 * -2 + 1);
            } while (bVar20);
            if (bVar20) goto LAB_080ac1e8;
            iVar17 = 7;
            pbVar18 = (byte *)0x8203e4d;
            do {
              if (iVar17 == 0) break;
              iVar17 = iVar17 + -1;
              bVar20 = *pbVar18 == *(byte *)puVar5;
              pbVar18 = pbVar18 + (uint)bVar21 * -2 + 1;
              puVar5 = (undefined4 *)((int)puVar5 + (uint)bVar21 * -2 + 1);
            } while (bVar20);
            if (!bVar20) goto LAB_080abf9e;
            iVar11 = 0x1a7;
            iVar17 = 0x9b;
            goto LAB_080abeb2;
          }
        }
LAB_080ac1e8:
        iVar11 = 0x1a2;
        iVar17 = 0x9c;
        goto LAB_080abeb2;
      }
      if (*(byte *)((int)puVar5 + 3) != 0) {
        if (*(byte *)((int)puVar5 + 3) != 3) goto LAB_080abf9e;
        bVar21 = *(byte *)(puVar5 + 1);
        if (bVar21 == 0) {
          uVar12 = param_1->references;
LAB_080ac347:
          if ((uVar12 & 0x2000000) != 0) {
            uVar12 = uVar12 >> 0x18;
            goto LAB_080ac089;
          }
          param_1->version = 0x300;
          param_1->state = 0x2211;
        }
        else {
          uVar12 = param_1->references;
          if (bVar21 < 3) {
            if (bVar21 == 2) {
LAB_080ac35d:
              if ((uVar12 & 0x10000000) == 0) {
                param_1->version = 0x302;
                param_1->state = 0x2211;
                goto LAB_080abbfe;
              }
            }
            if ((uVar12 & 0x4000000) != 0) goto LAB_080ac347;
            param_1->version = 0x301;
            param_1->state = 0x2211;
          }
          else {
            if ((uVar12 & 0x8000000) != 0) goto LAB_080ac35d;
            param_1->version = 0x303;
            param_1->state = 0x2211;
          }
        }
        goto LAB_080abbfe;
      }
      if (*(byte *)(puVar5 + 1) != 2) {
LAB_080abf9e:
        iVar17 = param_1->state;
        iVar11 = -2;
        iVar16 = 0;
        iVar19 = 0;
        goto LAB_080abbf0;
      }
      uVar12 = (uint)*(byte *)((int)&param_1->references + 3);
LAB_080ac089:
      if (param_1->state == 0x2211) goto LAB_080abbfe;
      if (((uVar12 ^ 1) & 1) != 1) {
LAB_080ac2b8:
        iVar16 = 0;
        goto LAB_080abe69;
      }
      if (param_1->s2 == (ssl2_state_st *)0x0) {
        iVar17 = ssl2_new(param_1);
        if (iVar17 == 0) goto LAB_080abebe;
      }
      else {
        ssl2_clear(param_1);
      }
      if (param_1->s3 != (ssl3_state_st *)0x0) {
        ssl3_free(param_1);
      }
      iVar17 = BUF_MEM_grow_clean(param_1->init_buf,0x3fff);
      if (iVar17 == 0) goto LAB_080abebe;
      param_1->state = 0x2010;
      psVar3 = param_1->s2;
      if ((param_1->references & 0x6000000U) == 0x6000000) {
        psVar3->ssl2_rollback = 0;
      }
      else {
        psVar3->ssl2_rollback = 1;
      }
      puVar5 = (undefined4 *)psVar3->rbuf;
      param_1->rstate = 0xf0;
      param_1->packet_length = 0xb;
      param_1->packet = (uchar *)puVar5;
      *puVar5 = local_2b[0];
      puVar5[1] = local_2b[1];
      *(undefined2 *)(puVar5 + 2) = local_23;
      *(byte *)((int)puVar5 + 10) = local_21;
      psVar3 = param_1->s2;
      psVar3->rbuf_left = 0xb;
      psVar3->rbuf_offs = 0;
      pSVar6 = SSLv2_server_method();
      param_1->method = pSVar6;
      param_1->handshake_func = (_func_3149 *)pSVar6->ssl_accept;
LAB_080abe71:
      iVar17 = *(int *)(in_GS_OFFSET + 0x14);
      param_1->init_num = 0;
      if (local_20 == iVar17) {
        uVar12 = SSL_accept(param_1);
        return uVar12;
      }
      goto LAB_080ac25b;
    }
  }
  else {
    iVar11 = -2;
    iVar16 = 0;
    iVar19 = 0;
    uVar12 = 0;
LAB_080abbf0:
    if (iVar17 == 0x2211) {
      puVar5 = (undefined4 *)param_1->packet;
LAB_080abbfe:
      uVar12 = (*(byte *)puVar5 & 0x7f) << 8 | (uint)*(byte *)((int)puVar5 + 1);
      if (uVar12 < 0x1001) {
        bVar21 = *(byte *)(puVar5 + 1);
        uVar12 = ssl23_read_bytes(param_1,uVar12 + 2);
        if ((int)uVar12 < 1) goto LAB_080abec3;
        ssl3_finish_mac(param_1,param_1->packet + 2,param_1->packet_length - 2);
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          (*param_1->msg_callback)
                    (0,2,0,param_1->packet + 2,param_1->packet_length - 2,param_1,
                     param_1->msg_callback_arg);
        }
        puVar1 = param_1->packet;
        pcVar2 = param_1->init_buf->data;
        uVar4 = *(ushort *)(puVar1 + 5) << 8 | *(ushort *)(puVar1 + 5) >> 8;
        uVar12 = (uint)(ushort)(*(ushort *)(puVar1 + 9) << 8 | *(ushort *)(puVar1 + 9) >> 8);
        iVar17 = (uint)(ushort)(*(ushort *)(puVar1 + 7) << 8 | *(ushort *)(puVar1 + 7) >> 8) +
                 (uint)uVar4;
        if (uVar12 + 0xb + iVar17 == param_1->packet_length) {
          _local_30 = pcVar2 + 6;
          pcVar2[5] = bVar21;
          *pcVar2 = '\x01';
          uVar8 = 0x20;
          if (uVar12 < 0x21) {
            uVar8 = uVar12;
          }
          *(undefined4 *)(pcVar2 + 6) = 0;
          *(undefined4 *)(pcVar2 + 0x22) = 0;
          pcVar2[4] = '\x03';
          uVar12 = 0;
          do {
            *(undefined4 *)(((uint)(pcVar2 + 10) & 0xfffffffc) + uVar12) = 0;
            uVar12 = uVar12 + 4;
          } while (uVar12 < ((uint)(_local_30 + (0x20 - ((uint)(pcVar2 + 10) & 0xfffffffc))) &
                            0xfffffffc));
          puVar13 = (undefined4 *)(puVar1 + iVar17 + 0xb);
          puVar5 = (undefined4 *)(_local_30 + (0x20 - uVar8));
          if (uVar8 < 4) {
            if ((uVar8 != 0) && (*(undefined *)puVar5 = *(undefined *)puVar13, (uVar8 & 2) != 0)) {
              *(undefined2 *)(_local_30 + 0x1e) = *(undefined2 *)((int)puVar13 + (uVar8 - 2));
            }
          }
          else {
            *puVar5 = *puVar13;
            *(undefined4 *)(_local_30 + 0x1c) = *(undefined4 *)((uVar8 - 4) + (int)puVar13);
            iVar17 = (int)puVar5 - ((uint)(_local_30 + (0x24 - uVar8)) & 0xfffffffc);
            uVar12 = iVar17 + uVar8 & 0xfffffffc;
            if (3 < uVar12) {
              uVar10 = 0;
              do {
                *(undefined4 *)(((uint)(_local_30 + (0x24 - uVar8)) & 0xfffffffc) + uVar10) =
                     *(undefined4 *)((int)puVar13 + (uVar10 - iVar17));
                uVar10 = uVar10 + 4;
              } while (uVar10 < uVar12);
            }
          }
          pcVar2[0x26] = '\0';
          puVar15 = (uchar *)(pcVar2 + 0x29);
          if (uVar4 == 0) {
            iVar17 = 0;
            cVar9 = '\0';
          }
          else {
            uVar12 = 0;
            iVar17 = 0;
            puVar14 = puVar15;
            do {
              puVar15 = puVar14;
              if (puVar1[uVar12 + 0xb] == '\0') {
                iVar17 = iVar17 + 2;
                puVar15 = puVar14 + 2;
                *puVar14 = puVar1[uVar12 + 0xc];
                puVar14[1] = puVar1[uVar12 + 0xd];
              }
              uVar12 = uVar12 + 3;
              puVar14 = puVar15;
            } while (uVar12 < uVar4);
            cVar9 = (char)((uint)iVar17 >> 8);
          }
          pcVar2[0x27] = cVar9;
          pcVar2[0x28] = (char)iVar17;
          *puVar15 = '\x01';
          puVar15[1] = '\0';
          puVar15 = puVar15 + (-2 - (int)param_1->init_buf->data);
          pcVar2[3] = (char)puVar15;
          pcVar2[1] = (char)((uint)puVar15 >> 0x10);
          pcVar2[2] = (char)((uint)puVar15 >> 8);
          psVar7 = param_1->s3;
          (psVar7->tmp).reuse_message = 1;
          (psVar7->tmp).message_type = 1;
          (psVar7->tmp).message_size = (ulong)puVar15;
          iVar17 = ssl_init_wbio_buffer(param_1,1);
          if (iVar17 != 0) {
            param_1->state = 0x2110;
            iVar16 = 2;
            goto LAB_080abe08;
          }
          goto LAB_080abebe;
        }
        iVar11 = 0x1d7;
        iVar17 = 0xd5;
      }
      else {
LAB_080ac000:
        iVar11 = 0x1c2;
        iVar17 = 0xd6;
      }
LAB_080abeb2:
      ERR_put_error(0x14,0x76,iVar17,"s23_srvr.c",iVar11);
    }
    else {
      if (iVar11 != 1) {
LAB_080abe69:
        if (iVar16 - 1U < 3) goto LAB_080abe71;
        iVar11 = 0x274;
        iVar17 = 0xfc;
        goto LAB_080abeb2;
      }
      iVar17 = ssl_init_wbio_buffer(param_1,1,iVar17,iVar17);
      if (iVar17 != 0) {
        param_1->state = 0x2110;
        if (iVar19 == 3) {
          psVar7 = param_1->s3;
          param_1->rstate = 0xf0;
          param_1->packet_length = uVar12;
          puVar5 = (undefined4 *)(psVar7->rbuf).buf;
          if (puVar5 == (undefined4 *)0x0) {
            iVar17 = ssl3_setup_read_buffer(param_1);
            if (iVar17 == 0) goto LAB_080abebe;
            psVar7 = param_1->s3;
            puVar5 = (undefined4 *)(psVar7->rbuf).buf;
          }
          param_1->packet = (uchar *)puVar5;
          if (uVar12 < 4) {
            if (uVar12 != 0) {
              *(uchar *)puVar5 = (uchar)local_2b[0];
              if ((uVar12 & 2) == 0) goto LAB_080ac42a;
              *(undefined2 *)((int)puVar5 + (uVar12 - 2)) = *(undefined2 *)(local_30 + uVar12 + 3);
              psVar7 = param_1->s3;
            }
          }
          else {
            *puVar5 = local_2b[0];
            *(undefined4 *)((int)puVar5 + (uVar12 - 4)) = *(undefined4 *)(local_30 + uVar12 + 1);
            iVar17 = (int)puVar5 - ((uint)(puVar5 + 1) & 0xfffffffc);
            uVar8 = iVar17 + uVar12 & 0xfffffffc;
            if (3 < uVar8) {
              uVar10 = 0;
              do {
                *(undefined4 *)(((uint)(puVar5 + 1) & 0xfffffffc) + uVar10) =
                     *(undefined4 *)((int)local_2b + (uVar10 - iVar17));
                uVar10 = uVar10 + 4;
              } while (uVar10 < uVar8);
            }
LAB_080ac42a:
            psVar7 = param_1->s3;
          }
          (psVar7->rbuf).left = uVar12;
          (psVar7->rbuf).offset = 0;
        }
        else {
LAB_080abe08:
          psVar7 = param_1->s3;
          param_1->packet_length = 0;
          (psVar7->rbuf).left = 0;
          (psVar7->rbuf).offset = 0;
        }
        iVar17 = param_1->version;
        if (iVar17 == 0x303) {
          pSVar6 = TLSv1_2_server_method();
          param_1->method = pSVar6;
        }
        else if (iVar17 == 0x302) {
          pSVar6 = TLSv1_1_server_method();
          param_1->method = pSVar6;
        }
        else if (iVar17 == 0x301) {
          pSVar6 = TLSv1_server_method();
          param_1->method = pSVar6;
        }
        else {
          pSVar6 = SSLv3_server_method();
          param_1->method = pSVar6;
        }
        param_1->handshake_func = (_func_3149 *)pSVar6->ssl_accept;
        goto LAB_080abe69;
      }
    }
LAB_080abebe:
    uVar12 = 0xffffffff;
  }
LAB_080abec3:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar12;
  }
LAB_080ac25b:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

