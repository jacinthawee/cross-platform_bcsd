
int dtls1_get_record(SSL *param_1)

{
  byte bVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  byte *pbVar5;
  ssl3_state_st *psVar6;
  undefined4 uVar7;
  bool bVar8;
  ushort uVar9;
  pitem *ppVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uchar **ppuVar14;
  pitem *ppVar15;
  byte bVar16;
  ssl3_state_st *psVar17;
  ssl3_state_st *psVar18;
  DTLS1_BITMAP *pDVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  undefined4 *puVar26;
  byte bVar27;
  dtls1_state_st *local_30;
  
  bVar27 = 0;
  psVar17 = param_1->s3;
  local_30 = param_1->d1;
LAB_080b5ea8:
  do {
    ppVar10 = pqueue_peek((local_30->unprocessed_rcds).q);
    if (ppVar10 == (pitem *)0x0) {
LAB_080b63d0:
      local_30 = param_1->d1;
      uVar9 = local_30->r_epoch;
      (local_30->processed_rcds).epoch = uVar9;
      (local_30->unprocessed_rcds).epoch = uVar9 + 1;
    }
    else {
      local_30 = param_1->d1;
      if (((local_30->unprocessed_rcds).epoch == local_30->r_epoch) &&
         (psVar6 = param_1->s3, (psVar6->rbuf).left < 1)) {
        while (ppVar10 = pqueue_peek((local_30->unprocessed_rcds).q), ppVar10 != (pitem *)0x0) {
          ppVar10 = pqueue_pop((param_1->d1->unprocessed_rcds).q);
          if (ppVar10 != (pitem *)0x0) {
            psVar18 = param_1->s3;
            ppuVar14 = (uchar **)ppVar10->data;
            puVar2 = (psVar18->rbuf).buf;
            if (puVar2 != (uchar *)0x0) {
              CRYPTO_free(puVar2);
              psVar18 = param_1->s3;
            }
            param_1->packet = *ppuVar14;
            param_1->packet_length = (uint)ppuVar14[1];
            puVar2 = ppuVar14[5];
            puVar3 = ppuVar14[4];
            puVar4 = ppuVar14[2];
            (psVar18->rbuf).len = (size_t)ppuVar14[3];
            (psVar18->rbuf).offset = (int)puVar3;
            (psVar18->rbuf).buf = puVar4;
            (psVar18->rbuf).left = (int)puVar2;
            psVar18 = param_1->s3;
            (psVar18->rrec).type = (int)ppuVar14[6];
            (psVar18->rrec).length = (uint)ppuVar14[7];
            (psVar18->rrec).off = (uint)ppuVar14[8];
            (psVar18->rrec).data = ppuVar14[9];
            (psVar18->rrec).input = ppuVar14[10];
            (psVar18->rrec).comp = ppuVar14[0xb];
            (psVar18->rrec).epoch = (ulong)ppuVar14[0xc];
            *(uchar **)(psVar18->rrec).seq_num = ppuVar14[0xd];
            *(uchar **)((psVar18->rrec).seq_num + 4) = ppuVar14[0xe];
            puVar2 = *ppuVar14;
            psVar18 = param_1->s3;
            *(undefined4 *)(psVar18->read_sequence + 2) = *(undefined4 *)(puVar2 + 5);
            *(undefined2 *)(psVar18->read_sequence + 6) = *(undefined2 *)(puVar2 + 9);
            CRYPTO_free(ppVar10->data);
            pitem_free(ppVar10);
          }
          local_30 = param_1->d1;
          uVar9 = local_30->r_epoch;
          uVar20 = (psVar6->rrec).epoch;
          if (uVar20 == uVar9) {
            pDVar19 = &local_30->bitmap;
          }
          else {
            if (((uVar20 != uVar9 + 1) || (uVar9 == (local_30->unprocessed_rcds).epoch)) ||
               (1 < (psVar6->rrec).type - 0x15U)) {
              ERR_put_error(0x14,0x1a8,0x44,"d1_pkt.c",0x167);
              return -1;
            }
            pDVar19 = &local_30->next_bitmap;
          }
          psVar18 = param_1->s3;
          uVar20 = (uint)psVar18->read_sequence[7] - (uint)pDVar19->max_seq_num[7];
          if ((uVar20 & 0x80) == 0) {
            iVar12 = ((uint)psVar18->read_sequence[6] - (uint)pDVar19->max_seq_num[6]) +
                     ((int)uVar20 >> 8);
            iVar22 = ((uint)psVar18->read_sequence[5] - (uint)pDVar19->max_seq_num[5]) +
                     (iVar12 >> 8);
            iVar11 = ((uint)psVar18->read_sequence[4] - (uint)pDVar19->max_seq_num[4]) +
                     (iVar22 >> 8);
            iVar23 = ((uint)psVar18->read_sequence[3] - (uint)pDVar19->max_seq_num[3]) +
                     (iVar11 >> 8);
            iVar21 = ((uint)psVar18->read_sequence[2] - (uint)pDVar19->max_seq_num[2]) +
                     (iVar23 >> 8);
            iVar24 = ((uint)psVar18->read_sequence[1] - (uint)pDVar19->max_seq_num[1]) +
                     (iVar21 >> 8);
            iVar25 = (iVar24 >> 8) +
                     ((uint)psVar18->read_sequence[0] - (uint)pDVar19->max_seq_num[0]);
            bVar16 = (byte)iVar12 | (byte)iVar22 | (byte)iVar11 | (byte)iVar23 | (byte)iVar21 |
                     (byte)iVar24 | (byte)iVar25;
          }
          else {
            iVar12 = ((uint)psVar18->read_sequence[6] - (uint)pDVar19->max_seq_num[6]) +
                     ((int)uVar20 >> 8);
            iVar22 = ((uint)psVar18->read_sequence[5] - (uint)pDVar19->max_seq_num[5]) +
                     (iVar12 >> 8);
            iVar11 = ((uint)psVar18->read_sequence[4] - (uint)pDVar19->max_seq_num[4]) +
                     (iVar22 >> 8);
            iVar23 = ((uint)psVar18->read_sequence[3] - (uint)pDVar19->max_seq_num[3]) +
                     (iVar11 >> 8);
            iVar21 = ((uint)psVar18->read_sequence[2] - (uint)pDVar19->max_seq_num[2]) +
                     (iVar23 >> 8);
            iVar24 = ((uint)psVar18->read_sequence[1] - (uint)pDVar19->max_seq_num[1]) +
                     (iVar21 >> 8);
            iVar25 = (iVar24 >> 8) +
                     ((uint)psVar18->read_sequence[0] - (uint)pDVar19->max_seq_num[0]);
            bVar16 = ~((byte)iVar12 & (byte)iVar22 & (byte)iVar11 & (byte)iVar23 & (byte)iVar21 &
                       (byte)iVar24 & (byte)iVar25);
          }
          uVar20 = (iVar25 >> 8) * 0x100 + (uVar20 & 0xff);
          if (bVar16 != 0) {
            uVar20 = (iVar25 >> 8) << 8 | 0x80;
          }
          if (((int)uVar20 < 1) &&
             ((uVar20 != 0xffffffe1 && 0x1e < (int)-uVar20 ||
              ((pDVar19->map >> (-uVar20 & 0x1f) & 1) != 0)))) {
LAB_080b6150:
            (psVar6->rrec).length = 0;
            param_1->packet_length = 0;
          }
          else {
            uVar7 = *(undefined4 *)(psVar18->read_sequence + 4);
            *(undefined4 *)(psVar18->rrec).seq_num = *(undefined4 *)psVar18->read_sequence;
            *(undefined4 *)((psVar18->rrec).seq_num + 4) = uVar7;
            iVar12 = dtls1_process_record();
            if (iVar12 == 0) {
              local_30 = param_1->d1;
              goto LAB_080b6150;
            }
            iVar12 = pqueue_size((param_1->d1->processed_rcds).q);
            if ((iVar12 < 100) && (iVar12 = dtls1_buffer_record_isra_6_part_7(), iVar12 < 0)) {
              return -1;
            }
            local_30 = param_1->d1;
          }
        }
        goto LAB_080b63d0;
      }
    }
    ppVar10 = pqueue_pop((local_30->processed_rcds).q);
    if (ppVar10 != (pitem *)0x0) {
      psVar17 = param_1->s3;
      ppuVar14 = (uchar **)ppVar10->data;
      puVar2 = (psVar17->rbuf).buf;
      if (puVar2 != (uchar *)0x0) {
        CRYPTO_free(puVar2);
        psVar17 = param_1->s3;
      }
      param_1->packet = *ppuVar14;
      param_1->packet_length = (uint)ppuVar14[1];
      puVar2 = ppuVar14[4];
      puVar3 = ppuVar14[5];
      puVar4 = ppuVar14[2];
      (psVar17->rbuf).len = (size_t)ppuVar14[3];
      (psVar17->rbuf).left = (int)puVar3;
      (psVar17->rbuf).offset = (int)puVar2;
      (psVar17->rbuf).buf = puVar4;
      psVar17 = param_1->s3;
      (psVar17->rrec).type = (int)ppuVar14[6];
      (psVar17->rrec).length = (uint)ppuVar14[7];
      (psVar17->rrec).off = (uint)ppuVar14[8];
      (psVar17->rrec).data = ppuVar14[9];
      (psVar17->rrec).input = ppuVar14[10];
      (psVar17->rrec).comp = ppuVar14[0xb];
      (psVar17->rrec).epoch = (ulong)ppuVar14[0xc];
      *(uchar **)(psVar17->rrec).seq_num = ppuVar14[0xd];
      *(uchar **)((psVar17->rrec).seq_num + 4) = ppuVar14[0xe];
      psVar17 = param_1->s3;
      puVar2 = *ppuVar14;
      *(undefined4 *)(psVar17->read_sequence + 2) = *(undefined4 *)(puVar2 + 5);
      *(undefined2 *)(psVar17->read_sequence + 6) = *(undefined2 *)(puVar2 + 9);
      CRYPTO_free(ppVar10->data);
      pitem_free(ppVar10);
      return 1;
    }
    if ((param_1->rstate == 0xf1) && (uVar20 = param_1->packet_length, 0xc < uVar20)) {
      uVar13 = (psVar17->rrec).length;
LAB_080b5feb:
      if ((uVar20 - 0xd < uVar13) &&
         (uVar20 = ssl3_read_n(param_1,uVar13,uVar13,1), uVar13 != uVar20)) {
LAB_080b64d5:
        (psVar17->rrec).length = 0;
LAB_080b6070:
        local_30 = param_1->d1;
        param_1->packet_length = 0;
        goto LAB_080b5ea8;
      }
      local_30 = param_1->d1;
      param_1->rstate = 0xf0;
      uVar9 = local_30->r_epoch;
      uVar20 = (psVar17->rrec).epoch;
      if (uVar20 == uVar9) {
        bVar8 = false;
        pDVar19 = &local_30->bitmap;
LAB_080b6522:
        if (((local_30->mtu == 0) || ((psVar17->rrec).type != 0x16)) ||
           ((param_1->packet_length < 0xe || (param_1->packet[0xd] != '\x01')))) {
          psVar6 = param_1->s3;
          uVar20 = (uint)psVar6->read_sequence[7] - (uint)pDVar19->max_seq_num[7];
          if ((uVar20 & 0x80) == 0) {
            iVar11 = ((uint)psVar6->read_sequence[6] - (uint)pDVar19->max_seq_num[6]) +
                     ((int)uVar20 >> 8);
            iVar21 = (iVar11 >> 8) +
                     ((uint)psVar6->read_sequence[5] - (uint)pDVar19->max_seq_num[5]);
            iVar22 = (iVar21 >> 8) +
                     ((uint)psVar6->read_sequence[4] - (uint)pDVar19->max_seq_num[4]);
            iVar23 = (iVar22 >> 8) +
                     ((uint)psVar6->read_sequence[3] - (uint)pDVar19->max_seq_num[3]);
            iVar24 = (iVar23 >> 8) +
                     ((uint)psVar6->read_sequence[2] - (uint)pDVar19->max_seq_num[2]);
            iVar25 = (iVar24 >> 8) +
                     ((uint)psVar6->read_sequence[1] - (uint)pDVar19->max_seq_num[1]);
            iVar12 = ((uint)psVar6->read_sequence[0] - (uint)pDVar19->max_seq_num[0]) +
                     (iVar25 >> 8);
            bVar16 = (byte)iVar11 | (byte)iVar21 | (byte)iVar22 | (byte)iVar23 | (byte)iVar24 |
                     (byte)iVar25 | (byte)iVar12;
          }
          else {
            iVar11 = ((uint)psVar6->read_sequence[6] - (uint)pDVar19->max_seq_num[6]) +
                     ((int)uVar20 >> 8);
            iVar21 = (iVar11 >> 8) +
                     ((uint)psVar6->read_sequence[5] - (uint)pDVar19->max_seq_num[5]);
            iVar22 = (iVar21 >> 8) +
                     ((uint)psVar6->read_sequence[4] - (uint)pDVar19->max_seq_num[4]);
            iVar23 = (iVar22 >> 8) +
                     ((uint)psVar6->read_sequence[3] - (uint)pDVar19->max_seq_num[3]);
            iVar24 = (iVar23 >> 8) +
                     ((uint)psVar6->read_sequence[2] - (uint)pDVar19->max_seq_num[2]);
            iVar25 = (iVar24 >> 8) +
                     ((uint)psVar6->read_sequence[1] - (uint)pDVar19->max_seq_num[1]);
            iVar12 = ((uint)psVar6->read_sequence[0] - (uint)pDVar19->max_seq_num[0]) +
                     (iVar25 >> 8);
            bVar16 = ~((byte)iVar11 & (byte)iVar21 & (byte)iVar22 & (byte)iVar23 & (byte)iVar24 &
                       (byte)iVar25 & (byte)iVar12);
          }
          uVar13 = (iVar12 >> 8) * 0x100;
          uVar20 = uVar13 + (uVar20 & 0xff);
          if (bVar16 != 0) {
            uVar20 = uVar13 | 0x80;
          }
          if (((int)uVar20 < 1) &&
             ((uVar20 != 0xffffffe1 && 0x1e < (int)-uVar20 ||
              ((pDVar19->map >> (-uVar20 & 0x1f) & 1) != 0)))) goto LAB_080b602a;
          uVar7 = *(undefined4 *)(psVar6->read_sequence + 4);
          *(undefined4 *)(psVar6->rrec).seq_num = *(undefined4 *)psVar6->read_sequence;
          *(undefined4 *)((psVar6->rrec).seq_num + 4) = uVar7;
        }
        if ((psVar17->rrec).length == 0) {
          local_30 = param_1->d1;
          goto LAB_080b5ea8;
        }
        if (!bVar8) {
          iVar12 = dtls1_process_record();
          if (iVar12 != 0) {
            return 1;
          }
          goto LAB_080b64d5;
        }
        uVar20 = SSL_state(param_1);
        if (((uVar20 & 0x3000) != 0) || (param_1->in_handshake != 0)) {
          local_30 = param_1->d1;
          if (local_30->mtu != 0) goto LAB_080b602a;
          iVar12 = pqueue_size((local_30->unprocessed_rcds).q);
          if (iVar12 < 100) {
            ppuVar14 = (uchar **)CRYPTO_malloc(0x3c,"d1_pkt.c",0xe6);
            ppVar10 = pitem_new((psVar17->rrec).seq_num,ppuVar14);
            if ((ppuVar14 == (uchar **)0x0) || (ppVar10 == (pitem *)0x0)) {
              if (ppuVar14 != (uchar **)0x0) {
                CRYPTO_free(ppuVar14);
              }
              if (ppVar10 != (pitem *)0x0) {
                pitem_free(ppVar10);
              }
              ERR_put_error(0x14,0xf7,0x44,"d1_pkt.c",0xee);
              return -1;
            }
            *ppuVar14 = param_1->packet;
            ppuVar14[1] = (uchar *)param_1->packet_length;
            psVar6 = param_1->s3;
            puVar2 = (uchar *)(psVar6->rbuf).len;
            puVar3 = (psVar6->rbuf).buf;
            puVar4 = (uchar *)(psVar6->rbuf).left;
            ppuVar14[4] = (uchar *)(psVar6->rbuf).offset;
            ppuVar14[3] = puVar2;
            ppuVar14[2] = puVar3;
            ppuVar14[5] = puVar4;
            psVar6 = param_1->s3;
            ppuVar14[6] = (uchar *)(psVar6->rrec).type;
            ppuVar14[7] = (uchar *)(psVar6->rrec).length;
            ppuVar14[8] = (uchar *)(psVar6->rrec).off;
            ppuVar14[9] = (psVar6->rrec).data;
            ppuVar14[10] = (psVar6->rrec).input;
            ppuVar14[0xb] = (psVar6->rrec).comp;
            ppuVar14[0xc] = (uchar *)(psVar6->rrec).epoch;
            ppuVar14[0xd] = *(uchar **)(psVar6->rrec).seq_num;
            ppuVar14[0xe] = *(uchar **)((psVar6->rrec).seq_num + 4);
            psVar6 = param_1->s3;
            ppVar10->data = ppuVar14;
            param_1->packet = (uchar *)0x0;
            param_1->packet_length = 0;
            (psVar6->rbuf).buf = (uchar *)0x0;
            (psVar6->rbuf).len = 0;
            (psVar6->rbuf).offset = 0;
            (psVar6->rbuf).left = 0;
            psVar6 = param_1->s3;
            (psVar6->rrec).type = 0;
            *(undefined4 *)((psVar6->rrec).seq_num + 4) = 0;
            puVar26 = (undefined4 *)((uint)&(psVar6->rrec).length & 0xfffffffc);
            uVar20 = (uint)((int)psVar6 + (0x130 - (int)puVar26)) >> 2;
            for (; uVar20 != 0; uVar20 = uVar20 - 1) {
              *puVar26 = 0;
              puVar26 = puVar26 + (uint)bVar27 * -2 + 1;
            }
            iVar12 = ssl3_setup_buffers(param_1);
            if (iVar12 == 0) {
              iVar12 = 0x109;
LAB_080b68ab:
              ERR_put_error(0x14,0xf7,0x44,"d1_pkt.c",iVar12);
              if (ppuVar14[2] != (uchar *)0x0) {
                CRYPTO_free(ppuVar14[2]);
              }
              CRYPTO_free(ppuVar14);
              pitem_free(ppVar10);
              return -1;
            }
            ppVar15 = pqueue_insert((local_30->unprocessed_rcds).q,ppVar10);
            if (ppVar15 == (pitem *)0x0) {
              iVar12 = 0x113;
              goto LAB_080b68ab;
            }
          }
        }
        local_30 = param_1->d1;
      }
      else if (((uVar20 == uVar9 + 1) && (uVar9 != (local_30->unprocessed_rcds).epoch)) &&
              ((psVar17->rrec).type - 0x15U < 2)) {
        bVar8 = true;
        pDVar19 = &local_30->next_bitmap;
        goto LAB_080b6522;
      }
LAB_080b602a:
      (psVar17->rrec).length = 0;
      param_1->packet_length = 0;
      goto LAB_080b5ea8;
    }
    iVar12 = ssl3_read_n(param_1,0xd,(param_1->s3->rbuf).len,0);
    if (iVar12 < 1) {
      return iVar12;
    }
    if (param_1->packet_length != 0xd) goto LAB_080b6070;
    pbVar5 = param_1->packet;
    param_1->rstate = 0xf1;
    (psVar17->rrec).type = (uint)*pbVar5;
    bVar16 = pbVar5[1];
    bVar1 = pbVar5[2];
    (psVar17->rrec).epoch =
         (uint)(ushort)(*(ushort *)(pbVar5 + 3) << 8 | *(ushort *)(pbVar5 + 3) >> 8);
    psVar6 = param_1->s3;
    *(undefined4 *)(psVar6->read_sequence + 2) = *(undefined4 *)(pbVar5 + 5);
    *(undefined2 *)(psVar6->read_sequence + 6) = *(undefined2 *)(pbVar5 + 9);
    iVar12 = param_1->max_cert_list;
    uVar9 = *(ushort *)(pbVar5 + 0xb) << 8 | *(ushort *)(pbVar5 + 0xb) >> 8;
    uVar13 = (uint)uVar9;
    (psVar17->rrec).length = uVar13;
    if (iVar12 == 0) {
      if ((uint)CONCAT11(bVar16,bVar1) == param_1->version) {
LAB_080b6950:
        if (uVar9 < 0x4541) {
          uVar20 = param_1->packet_length;
          goto LAB_080b5feb;
        }
        goto LAB_080b64d5;
      }
      local_30 = param_1->d1;
      (psVar17->rrec).length = 0;
      param_1->packet_length = 0;
    }
    else {
      if ((char)((uint)CONCAT11(bVar16,bVar1) >> 8) == (char)((uint)param_1->version >> 8))
      goto LAB_080b6950;
      local_30 = param_1->d1;
      (psVar17->rrec).length = 0;
      param_1->packet_length = 0;
    }
  } while( true );
}

