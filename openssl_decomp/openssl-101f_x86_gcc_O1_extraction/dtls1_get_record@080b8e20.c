
uint dtls1_get_record(SSL *param_1)

{
  byte bVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  byte *pbVar5;
  undefined4 uVar6;
  bool bVar7;
  pitem *ppVar8;
  uchar **ppuVar9;
  dtls1_state_st *pdVar10;
  pitem *ppVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ushort uVar16;
  DTLS1_BITMAP *pDVar17;
  ssl3_state_st *psVar18;
  ssl3_state_st *psVar19;
  byte bVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  undefined4 *puVar26;
  byte *local_28;
  
  bVar20 = 0;
  psVar18 = param_1->s3;
  ppVar8 = pqueue_peek((param_1->d1->unprocessed_rcds).q);
  if (ppVar8 != (pitem *)0x0) {
    pdVar10 = param_1->d1;
    if ((pdVar10->unprocessed_rcds).epoch != pdVar10->r_epoch) goto LAB_080b8e62;
    while (ppVar8 = pqueue_peek((pdVar10->unprocessed_rcds).q), ppVar8 != (pitem *)0x0) {
      ppVar8 = pqueue_pop((param_1->d1->unprocessed_rcds).q);
      if (ppVar8 != (pitem *)0x0) {
        psVar19 = param_1->s3;
        ppuVar9 = (uchar **)ppVar8->data;
        puVar2 = (psVar19->rbuf).buf;
        if (puVar2 != (uchar *)0x0) {
          CRYPTO_free(puVar2);
          psVar19 = param_1->s3;
        }
        param_1->packet = *ppuVar9;
        param_1->packet_length = (uint)ppuVar9[1];
        puVar2 = ppuVar9[5];
        puVar3 = ppuVar9[4];
        puVar4 = ppuVar9[2];
        (psVar19->rbuf).len = (size_t)ppuVar9[3];
        (psVar19->rbuf).offset = (int)puVar3;
        (psVar19->rbuf).buf = puVar4;
        (psVar19->rbuf).left = (int)puVar2;
        psVar19 = param_1->s3;
        (psVar19->rrec).type = (int)ppuVar9[6];
        (psVar19->rrec).length = (uint)ppuVar9[7];
        (psVar19->rrec).off = (uint)ppuVar9[8];
        (psVar19->rrec).data = ppuVar9[9];
        (psVar19->rrec).input = ppuVar9[10];
        (psVar19->rrec).comp = ppuVar9[0xb];
        (psVar19->rrec).epoch = (ulong)ppuVar9[0xc];
        *(uchar **)(psVar19->rrec).seq_num = ppuVar9[0xd];
        *(uchar **)((psVar19->rrec).seq_num + 4) = ppuVar9[0xe];
        puVar2 = *ppuVar9;
        psVar19 = param_1->s3;
        *(undefined4 *)(psVar19->read_sequence + 2) = *(undefined4 *)(puVar2 + 5);
        *(undefined2 *)(psVar19->read_sequence + 6) = *(undefined2 *)(puVar2 + 9);
        CRYPTO_free(ppVar8->data);
        pitem_free(ppVar8);
      }
      iVar13 = dtls1_process_record();
      if (iVar13 == 0) {
        pdVar10 = param_1->d1;
        goto LAB_080b8e62;
      }
      pdVar10 = param_1->d1;
      psVar19 = param_1->s3;
      iVar13 = pqueue_size((pdVar10->processed_rcds).q);
      if (iVar13 < 100) {
        ppuVar9 = (uchar **)CRYPTO_malloc(0x3c,"d1_pkt.c",0xd8);
        ppVar8 = pitem_new((psVar19->rrec).seq_num,ppuVar9);
        if ((ppuVar9 == (uchar **)0x0) || (ppVar8 == (pitem *)0x0)) {
          if (ppuVar9 != (uchar **)0x0) {
            CRYPTO_free(ppuVar9);
          }
          if (ppVar8 != (pitem *)0x0) {
            pitem_free(ppVar8);
          }
          ERR_put_error(0x14,0xf7,0x44,"d1_pkt.c",0xdf);
        }
        else {
          *ppuVar9 = param_1->packet;
          ppuVar9[1] = (uchar *)param_1->packet_length;
          psVar19 = param_1->s3;
          puVar2 = (uchar *)(psVar19->rbuf).len;
          puVar3 = (uchar *)(psVar19->rbuf).offset;
          puVar4 = (uchar *)(psVar19->rbuf).left;
          ppuVar9[2] = (psVar19->rbuf).buf;
          ppuVar9[4] = puVar3;
          ppuVar9[5] = puVar4;
          ppuVar9[3] = puVar2;
          psVar19 = param_1->s3;
          ppuVar9[6] = (uchar *)(psVar19->rrec).type;
          ppuVar9[7] = (uchar *)(psVar19->rrec).length;
          ppuVar9[8] = (uchar *)(psVar19->rrec).off;
          ppuVar9[9] = (psVar19->rrec).data;
          ppuVar9[10] = (psVar19->rrec).input;
          ppuVar9[0xb] = (psVar19->rrec).comp;
          ppuVar9[0xc] = (uchar *)(psVar19->rrec).epoch;
          ppuVar9[0xd] = *(uchar **)(psVar19->rrec).seq_num;
          ppuVar9[0xe] = *(uchar **)((psVar19->rrec).seq_num + 4);
          ppVar8->data = ppuVar9;
          ppVar11 = pqueue_insert((pdVar10->processed_rcds).q,ppVar8);
          if (ppVar11 != (pitem *)0x0) {
            psVar19 = param_1->s3;
            param_1->packet = (uchar *)0x0;
            param_1->packet_length = 0;
            (psVar19->rbuf).buf = (uchar *)0x0;
            (psVar19->rbuf).len = 0;
            (psVar19->rbuf).offset = 0;
            (psVar19->rbuf).left = 0;
            psVar19 = param_1->s3;
            (psVar19->rrec).type = 0;
            *(undefined4 *)((psVar19->rrec).seq_num + 4) = 0;
            puVar26 = (undefined4 *)((uint)&(psVar19->rrec).length & 0xfffffffc);
            uVar12 = (uint)((int)psVar19 + (0x130 - (int)puVar26)) >> 2;
            for (; uVar12 != 0; uVar12 = uVar12 - 1) {
              *puVar26 = 0;
              puVar26 = puVar26 + (uint)bVar20 * -2 + 1;
            }
            iVar13 = ssl3_setup_buffers(param_1);
            if (iVar13 != 0) goto LAB_080b8fcc;
            ERR_put_error(0x14,0xf7,0x44,"d1_pkt.c",0x101);
          }
          CRYPTO_free(ppuVar9);
          pitem_free(ppVar8);
        }
      }
LAB_080b8fcc:
      pdVar10 = param_1->d1;
    }
  }
  pdVar10 = param_1->d1;
  uVar16 = pdVar10->r_epoch;
  (pdVar10->processed_rcds).epoch = uVar16;
  (pdVar10->unprocessed_rcds).epoch = uVar16 + 1;
LAB_080b8e62:
  ppVar8 = pqueue_pop((pdVar10->processed_rcds).q);
  if (ppVar8 != (pitem *)0x0) {
    psVar18 = param_1->s3;
    ppuVar9 = (uchar **)ppVar8->data;
    puVar2 = (psVar18->rbuf).buf;
    if (puVar2 != (uchar *)0x0) {
      CRYPTO_free(puVar2);
      psVar18 = param_1->s3;
    }
    param_1->packet = *ppuVar9;
    param_1->packet_length = (uint)ppuVar9[1];
    puVar2 = ppuVar9[5];
    puVar3 = ppuVar9[4];
    puVar4 = ppuVar9[2];
    (psVar18->rbuf).len = (size_t)ppuVar9[3];
    (psVar18->rbuf).offset = (int)puVar3;
    (psVar18->rbuf).buf = puVar4;
    (psVar18->rbuf).left = (int)puVar2;
    psVar18 = param_1->s3;
    (psVar18->rrec).type = (int)ppuVar9[6];
    (psVar18->rrec).length = (uint)ppuVar9[7];
    (psVar18->rrec).off = (uint)ppuVar9[8];
    (psVar18->rrec).data = ppuVar9[9];
    (psVar18->rrec).input = ppuVar9[10];
    (psVar18->rrec).comp = ppuVar9[0xb];
    (psVar18->rrec).epoch = (ulong)ppuVar9[0xc];
    *(uchar **)(psVar18->rrec).seq_num = ppuVar9[0xd];
    *(uchar **)((psVar18->rrec).seq_num + 4) = ppuVar9[0xe];
    puVar2 = *ppuVar9;
    psVar18 = param_1->s3;
    *(undefined4 *)(psVar18->read_sequence + 2) = *(undefined4 *)(puVar2 + 5);
    *(undefined2 *)(psVar18->read_sequence + 6) = *(undefined2 *)(puVar2 + 9);
    CRYPTO_free(ppVar8->data);
    pitem_free(ppVar8);
    return 1;
  }
  local_28 = (byte *)0x0;
LAB_080b9300:
  while ((param_1->rstate != 0xf1 || (uVar12 = param_1->packet_length, uVar12 < 0xd))) {
    uVar12 = ssl3_read_n(param_1,0xd,(param_1->s3->rbuf).len,0);
    if ((int)uVar12 < 1) {
      return uVar12;
    }
    if (param_1->packet_length != 0xd) goto LAB_080b92f9;
    pbVar5 = param_1->packet;
    param_1->rstate = 0xf1;
    local_28 = pbVar5 + 0xd;
    (psVar18->rrec).type = (uint)*pbVar5;
    bVar20 = pbVar5[1];
    bVar1 = pbVar5[2];
    (psVar18->rrec).epoch =
         (uint)(ushort)(*(ushort *)(pbVar5 + 3) << 8 | *(ushort *)(pbVar5 + 3) >> 8);
    psVar19 = param_1->s3;
    *(undefined4 *)(psVar19->read_sequence + 2) = *(undefined4 *)(pbVar5 + 5);
    *(undefined2 *)(psVar19->read_sequence + 6) = *(undefined2 *)(pbVar5 + 9);
    iVar13 = param_1->max_cert_list;
    uVar16 = *(ushort *)(pbVar5 + 0xb) << 8 | *(ushort *)(pbVar5 + 0xb) >> 8;
    uVar21 = (uint)uVar16;
    (psVar18->rrec).length = uVar21;
    if (iVar13 == 0) {
      if ((uint)CONCAT11(bVar20,bVar1) == param_1->version) {
LAB_080b9638:
        if (uVar16 < 0x4541) {
          uVar12 = param_1->packet_length;
          goto LAB_080b92b2;
        }
        goto LAB_080b92eb;
      }
      (psVar18->rrec).length = 0;
      param_1->packet_length = 0;
    }
    else {
      if ((char)((uint)CONCAT11(bVar20,bVar1) >> 8) == (char)((uint)param_1->version >> 8))
      goto LAB_080b9638;
      (psVar18->rrec).length = 0;
      param_1->packet_length = 0;
    }
  }
  uVar21 = (psVar18->rrec).length;
LAB_080b92b2:
  if (uVar12 - 0xd < uVar21) {
    uVar12 = ssl3_read_n(param_1,uVar21,uVar21,1);
    if ((int)uVar12 < 1) {
      return uVar12;
    }
    if (uVar21 == uVar12) goto LAB_080b92bd;
  }
  else {
LAB_080b92bd:
    pdVar10 = param_1->d1;
    param_1->rstate = 0xf0;
    uVar12 = (psVar18->rrec).epoch;
    if (uVar12 == pdVar10->r_epoch) {
      pDVar17 = &pdVar10->bitmap;
      bVar7 = false;
    }
    else {
      if ((uVar12 != pdVar10->r_epoch + 1) || (1 < (psVar18->rrec).type - 0x15U)) goto LAB_080b92eb;
      pDVar17 = &pdVar10->next_bitmap;
      bVar7 = true;
    }
    if (((pdVar10->mtu == 0) || ((psVar18->rrec).type != 0x16)) || (*local_28 != 1)) {
      psVar19 = param_1->s3;
      uVar12 = (uint)psVar19->read_sequence[7] - (uint)pDVar17->max_seq_num[7];
      if ((uVar12 & 0x80) == 0) {
        iVar13 = ((uint)psVar19->read_sequence[6] - (uint)pDVar17->max_seq_num[6]) +
                 ((int)uVar12 >> 8);
        iVar22 = ((uint)psVar19->read_sequence[5] - (uint)pDVar17->max_seq_num[5]) + (iVar13 >> 8);
        iVar14 = ((uint)psVar19->read_sequence[4] - (uint)pDVar17->max_seq_num[4]) + (iVar22 >> 8);
        iVar23 = ((uint)psVar19->read_sequence[3] - (uint)pDVar17->max_seq_num[3]) + (iVar14 >> 8);
        iVar15 = ((uint)psVar19->read_sequence[2] - (uint)pDVar17->max_seq_num[2]) + (iVar23 >> 8);
        iVar24 = ((uint)psVar19->read_sequence[1] - (uint)pDVar17->max_seq_num[1]) + (iVar15 >> 8);
        iVar25 = (iVar24 >> 8) + ((uint)psVar19->read_sequence[0] - (uint)pDVar17->max_seq_num[0]);
        bVar20 = (byte)iVar13 | (byte)iVar22 | (byte)iVar14 | (byte)iVar23 | (byte)iVar15 |
                 (byte)iVar24 | (byte)iVar25;
      }
      else {
        iVar13 = ((uint)psVar19->read_sequence[6] - (uint)pDVar17->max_seq_num[6]) +
                 ((int)uVar12 >> 8);
        iVar22 = ((uint)psVar19->read_sequence[5] - (uint)pDVar17->max_seq_num[5]) + (iVar13 >> 8);
        iVar14 = ((uint)psVar19->read_sequence[4] - (uint)pDVar17->max_seq_num[4]) + (iVar22 >> 8);
        iVar23 = ((uint)psVar19->read_sequence[3] - (uint)pDVar17->max_seq_num[3]) + (iVar14 >> 8);
        iVar15 = ((uint)psVar19->read_sequence[2] - (uint)pDVar17->max_seq_num[2]) + (iVar23 >> 8);
        iVar24 = ((uint)psVar19->read_sequence[1] - (uint)pDVar17->max_seq_num[1]) + (iVar15 >> 8);
        iVar25 = (iVar24 >> 8) + ((uint)psVar19->read_sequence[0] - (uint)pDVar17->max_seq_num[0]);
        bVar20 = ~((byte)iVar13 & (byte)iVar22 & (byte)iVar14 & (byte)iVar23 & (byte)iVar15 &
                   (byte)iVar24 & (byte)iVar25);
      }
      uVar21 = (iVar25 >> 8) * 0x100;
      uVar12 = uVar21 + (uVar12 & 0xff);
      if (bVar20 != 0) {
        uVar12 = uVar21 | 0x80;
      }
      if (((int)uVar12 < 1) &&
         ((uVar12 != 0xffffffe1 && 0x1e < (int)-uVar12 ||
          ((pDVar17->map >> (-uVar12 & 0x1f) & 1) != 0)))) goto LAB_080b92eb;
      uVar6 = *(undefined4 *)(psVar19->read_sequence + 4);
      *(undefined4 *)(psVar19->rrec).seq_num = *(undefined4 *)psVar19->read_sequence;
      *(undefined4 *)((psVar19->rrec).seq_num + 4) = uVar6;
    }
    if ((psVar18->rrec).length == 0) goto LAB_080b9300;
    if (bVar7) {
      uVar12 = SSL_state(param_1);
      if ((((uVar12 & 0x3000) != 0) || (param_1->in_handshake != 0)) && (param_1->d1->mtu == 0)) {
        dtls1_buffer_record_isra_6();
      }
    }
    else {
      iVar13 = dtls1_process_record();
      if (iVar13 != 0) {
        return 1;
      }
    }
  }
LAB_080b92eb:
  (psVar18->rrec).length = 0;
LAB_080b92f9:
  param_1->packet_length = 0;
  goto LAB_080b9300;
}

