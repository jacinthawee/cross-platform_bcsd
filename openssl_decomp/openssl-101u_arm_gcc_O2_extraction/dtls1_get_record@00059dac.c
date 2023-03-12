
int dtls1_get_record(SSL *param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  pitem *ppVar5;
  uchar *puVar6;
  pqueue p_Var7;
  int iVar8;
  ssl3_state_st *psVar9;
  DTLS1_BITMAP *pDVar10;
  ulong uVar11;
  uchar *puVar12;
  uchar **ppuVar13;
  SSL3_RECORD *pSVar14;
  ssl3_state_st *psVar15;
  dtls1_state_st *pdVar16;
  uchar **ppuVar17;
  uchar **ppuVar18;
  uint uVar19;
  byte *pbVar20;
  undefined4 uVar21;
  ssl3_state_st *psVar22;
  uchar **ppuVar23;
  uint uVar24;
  uchar *puVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  
  psVar22 = param_1->s3;
  pdVar16 = param_1->d1;
LAB_00059dc2:
  ppVar5 = pqueue_peek((pdVar16->unprocessed_rcds).q);
  if (ppVar5 == (pitem *)0x0) {
LAB_0005a04e:
    pdVar16 = param_1->d1;
    uVar3 = pdVar16->r_epoch;
    p_Var7 = (pdVar16->processed_rcds).q;
    (pdVar16->unprocessed_rcds).epoch = uVar3 + 1;
    (pdVar16->processed_rcds).epoch = uVar3;
    ppVar5 = pqueue_pop(p_Var7);
  }
  else {
    pdVar16 = param_1->d1;
    if (((pdVar16->unprocessed_rcds).epoch == pdVar16->r_epoch) &&
       (psVar15 = param_1->s3, (psVar15->rbuf).left < 1)) {
LAB_00059e8a:
      ppVar5 = pqueue_peek((pdVar16->unprocessed_rcds).q);
      if (ppVar5 != (pitem *)0x0) {
        do {
          ppVar5 = pqueue_pop((param_1->d1->unprocessed_rcds).q);
          if (ppVar5 != (pitem *)0x0) {
            psVar9 = param_1->s3;
            ppuVar23 = (uchar **)ppVar5->data;
            puVar6 = (psVar9->rbuf).buf;
            if (puVar6 != (uchar *)0x0) {
              CRYPTO_free(puVar6);
              psVar9 = param_1->s3;
            }
            puVar6 = *ppuVar23;
            param_1->packet_length = (uint)ppuVar23[1];
            param_1->packet = puVar6;
            puVar12 = ppuVar23[3];
            puVar25 = ppuVar23[4];
            puVar6 = ppuVar23[5];
            (psVar9->rbuf).buf = ppuVar23[2];
            (psVar9->rbuf).len = (size_t)puVar12;
            (psVar9->rbuf).offset = (int)puVar25;
            (psVar9->rbuf).left = (int)puVar6;
            pSVar14 = &param_1->s3->rrec;
            ppuVar18 = ppuVar23 + 6;
            do {
              ppuVar17 = ppuVar18 + 4;
              puVar12 = ppuVar18[1];
              ppuVar13 = &pSVar14->input;
              puVar25 = ppuVar18[2];
              puVar6 = ppuVar18[3];
              pSVar14->type = (int)*ppuVar18;
              pSVar14->length = (uint)puVar12;
              pSVar14->off = (uint)puVar25;
              pSVar14->data = puVar6;
              pSVar14 = (SSL3_RECORD *)ppuVar13;
              ppuVar18 = ppuVar17;
            } while (ppuVar17 != ppuVar23 + 0xe);
            *ppuVar13 = *ppuVar17;
            puVar6 = *ppuVar23;
            psVar9 = param_1->s3;
            *(undefined4 *)(psVar9->read_sequence + 2) = *(undefined4 *)(puVar6 + 5);
            *(undefined2 *)(psVar9->read_sequence + 6) = *(undefined2 *)(puVar6 + 9);
            CRYPTO_free(ppVar5->data);
            pitem_free(ppVar5);
          }
          pdVar16 = param_1->d1;
          uVar11 = (psVar15->rrec).epoch;
          uVar19 = (uint)pdVar16->r_epoch;
          if (uVar11 == uVar19) {
            pDVar10 = &pdVar16->bitmap;
          }
          else {
            if (((uVar11 != uVar19 + 1) || ((pdVar16->unprocessed_rcds).epoch == uVar19)) ||
               (1 < (psVar15->rrec).type - 0x15U)) {
              ERR_put_error(0x14,0x1a8,0x44,"d1_pkt.c",0x167);
              return -1;
            }
            pDVar10 = &pdVar16->next_bitmap;
          }
          psVar9 = param_1->s3;
          uVar19 = (uint)psVar9->read_sequence[7] - (uint)pDVar10->max_seq_num[7];
          if ((uVar19 & 0x80) == 0) {
            uVar24 = ((int)uVar19 >> 8) +
                     ((uint)psVar9->read_sequence[6] - (uint)pDVar10->max_seq_num[6]);
            uVar26 = ((uint)psVar9->read_sequence[5] - (uint)pDVar10->max_seq_num[5]) +
                     ((int)uVar24 >> 8);
            uVar30 = ((uint)psVar9->read_sequence[4] - (uint)pDVar10->max_seq_num[4]) +
                     ((int)uVar26 >> 8);
            uVar29 = ((uint)psVar9->read_sequence[3] - (uint)pDVar10->max_seq_num[3]) +
                     ((int)uVar30 >> 8);
            uVar28 = ((uint)psVar9->read_sequence[2] - (uint)pDVar10->max_seq_num[2]) +
                     ((int)uVar29 >> 8);
            uVar27 = ((uint)psVar9->read_sequence[1] - (uint)pDVar10->max_seq_num[1]) +
                     ((int)uVar28 >> 8);
            uVar31 = ((uint)psVar9->read_sequence[0] - (uint)pDVar10->max_seq_num[0]) +
                     ((int)uVar27 >> 8);
            uVar24 = uVar26 | uVar24 | uVar30 | uVar29 | uVar28 | uVar27 | uVar31;
          }
          else {
            uVar24 = ((int)uVar19 >> 8) +
                     ((uint)psVar9->read_sequence[6] - (uint)pDVar10->max_seq_num[6]);
            uVar30 = ((uint)psVar9->read_sequence[5] - (uint)pDVar10->max_seq_num[5]) +
                     ((int)uVar24 >> 8);
            uVar29 = ((uint)psVar9->read_sequence[4] - (uint)pDVar10->max_seq_num[4]) +
                     ((int)uVar30 >> 8);
            uVar28 = ((uint)psVar9->read_sequence[3] - (uint)pDVar10->max_seq_num[3]) +
                     ((int)uVar29 >> 8);
            uVar27 = ((uint)psVar9->read_sequence[2] - (uint)pDVar10->max_seq_num[2]) +
                     ((int)uVar28 >> 8);
            uVar26 = ((uint)psVar9->read_sequence[1] - (uint)pDVar10->max_seq_num[1]) +
                     ((int)uVar27 >> 8);
            uVar31 = ((uint)psVar9->read_sequence[0] - (uint)pDVar10->max_seq_num[0]) +
                     ((int)uVar26 >> 8);
            uVar24 = ~uVar24 | ~uVar30 | ~uVar29 | ~uVar28 | ~uVar27 | ~uVar26 | ~uVar31;
          }
          uVar26 = ((int)uVar31 >> 8) * 0x100;
          if ((uVar24 & 0xff) == 0) {
            uVar26 = uVar26 + (uVar19 & 0xff);
          }
          else {
            uVar26 = uVar26 | 0x80;
          }
          if ((0 < (int)uVar26) ||
             ((-uVar26 < 0x1f || uVar26 == 0xffffffe1 &&
              (-1 < (int)((pDVar10->map >> (-uVar26 & 0xff)) << 0x1f))))) {
            uVar21 = *(undefined4 *)(psVar9->read_sequence + 4);
            *(undefined4 *)(psVar9->rrec).seq_num = *(undefined4 *)psVar9->read_sequence;
            *(undefined4 *)((psVar9->rrec).seq_num + 4) = uVar21;
            iVar8 = dtls1_process_record(param_1);
            if (iVar8 != 0) goto LAB_0005a1ae;
            pdVar16 = param_1->d1;
          }
          (psVar15->rrec).length = 0;
          p_Var7 = (pdVar16->unprocessed_rcds).q;
          param_1->packet_length = 0;
          ppVar5 = pqueue_peek(p_Var7);
          if (ppVar5 == (pitem *)0x0) break;
        } while( true );
      }
      goto LAB_0005a04e;
    }
    ppVar5 = pqueue_pop((pdVar16->processed_rcds).q);
  }
  if (ppVar5 != (pitem *)0x0) {
    psVar22 = param_1->s3;
    ppuVar23 = (uchar **)ppVar5->data;
    puVar6 = (psVar22->rbuf).buf;
    if (puVar6 != (uchar *)0x0) {
      CRYPTO_free(puVar6);
      psVar22 = param_1->s3;
    }
    puVar6 = ppuVar23[1];
    param_1->packet = *ppuVar23;
    param_1->packet_length = (uint)puVar6;
    puVar25 = ppuVar23[3];
    puVar6 = ppuVar23[4];
    puVar12 = ppuVar23[5];
    (psVar22->rbuf).buf = ppuVar23[2];
    (psVar22->rbuf).len = (size_t)puVar25;
    (psVar22->rbuf).offset = (int)puVar6;
    (psVar22->rbuf).left = (int)puVar12;
    pSVar14 = &param_1->s3->rrec;
    ppuVar18 = ppuVar23 + 6;
    do {
      ppuVar17 = ppuVar18 + 4;
      puVar25 = ppuVar18[1];
      ppuVar13 = &pSVar14->input;
      puVar6 = ppuVar18[2];
      puVar12 = ppuVar18[3];
      pSVar14->type = (int)*ppuVar18;
      pSVar14->length = (uint)puVar25;
      pSVar14->off = (uint)puVar6;
      pSVar14->data = puVar12;
      pSVar14 = (SSL3_RECORD *)ppuVar13;
      ppuVar18 = ppuVar17;
    } while (ppuVar17 != ppuVar23 + 0xe);
    *ppuVar13 = *ppuVar17;
    puVar6 = *ppuVar23;
    psVar22 = param_1->s3;
    *(undefined4 *)(psVar22->read_sequence + 2) = *(undefined4 *)(puVar6 + 5);
    *(undefined2 *)(psVar22->read_sequence + 6) = *(undefined2 *)(puVar6 + 9);
    CRYPTO_free(ppVar5->data);
    pitem_free(ppVar5);
    return 1;
  }
  if ((param_1->rstate == 0xf1) && (uVar19 = param_1->packet_length, 0xc < uVar19)) {
    uVar24 = (psVar22->rrec).length;
LAB_0005a084:
    if ((uVar24 <= uVar19 - 0xd) ||
       (uVar19 = ssl3_read_n(param_1,uVar24,uVar24,1), uVar19 == uVar24)) {
      pdVar16 = param_1->d1;
      param_1->rstate = 0xf0;
      uVar19 = (uint)pdVar16->r_epoch;
      uVar11 = (psVar22->rrec).epoch;
      if (uVar11 == uVar19) {
        pDVar10 = &pdVar16->bitmap;
        bVar4 = false;
LAB_0005a266:
        if (((pdVar16->mtu == 0) || ((psVar22->rrec).type != 0x16)) ||
           ((param_1->packet_length < 0xe || (param_1->packet[0xd] != '\x01')))) {
          psVar15 = param_1->s3;
          uVar19 = (uint)psVar15->read_sequence[7] - (uint)pDVar10->max_seq_num[7];
          if ((uVar19 & 0x80) == 0) {
            uVar24 = ((int)uVar19 >> 8) +
                     ((uint)psVar15->read_sequence[6] - (uint)pDVar10->max_seq_num[6]);
            uVar27 = ((uint)psVar15->read_sequence[5] - (uint)pDVar10->max_seq_num[5]) +
                     ((int)uVar24 >> 8);
            uVar28 = ((uint)psVar15->read_sequence[4] - (uint)pDVar10->max_seq_num[4]) +
                     ((int)uVar27 >> 8);
            uVar29 = ((uint)psVar15->read_sequence[3] - (uint)pDVar10->max_seq_num[3]) +
                     ((int)uVar28 >> 8);
            uVar26 = ((uint)psVar15->read_sequence[2] - (uint)pDVar10->max_seq_num[2]) +
                     ((int)uVar29 >> 8);
            uVar30 = ((uint)psVar15->read_sequence[1] - (uint)pDVar10->max_seq_num[1]) +
                     ((int)uVar26 >> 8);
            uVar31 = ((uint)psVar15->read_sequence[0] - (uint)pDVar10->max_seq_num[0]) +
                     ((int)uVar30 >> 8);
            uVar24 = uVar27 | uVar24 | uVar28 | uVar29 | uVar26 | uVar30 | uVar31;
          }
          else {
            uVar28 = ((uint)psVar15->read_sequence[6] - (uint)pDVar10->max_seq_num[6]) +
                     ((int)uVar19 >> 8);
            uVar24 = ((uint)psVar15->read_sequence[5] - (uint)pDVar10->max_seq_num[5]) +
                     ((int)uVar28 >> 8);
            uVar29 = ((uint)psVar15->read_sequence[4] - (uint)pDVar10->max_seq_num[4]) +
                     ((int)uVar24 >> 8);
            uVar30 = ((uint)psVar15->read_sequence[3] - (uint)pDVar10->max_seq_num[3]) +
                     ((int)uVar29 >> 8);
            uVar26 = ((uint)psVar15->read_sequence[2] - (uint)pDVar10->max_seq_num[2]) +
                     ((int)uVar30 >> 8);
            uVar27 = ((uint)psVar15->read_sequence[1] - (uint)pDVar10->max_seq_num[1]) +
                     ((int)uVar26 >> 8);
            uVar31 = ((uint)psVar15->read_sequence[0] - (uint)pDVar10->max_seq_num[0]) +
                     ((int)uVar27 >> 8);
            uVar24 = ~uVar28 | ~uVar24 | ~uVar29 | ~uVar30 | ~uVar26 | ~uVar27 | ~uVar31;
          }
          uVar26 = ((int)uVar31 >> 8) * 0x100;
          if ((uVar24 & 0xff) == 0) {
            uVar26 = uVar26 + (uVar19 & 0xff);
          }
          else {
            uVar26 = uVar26 | 0x80;
          }
          if (((int)uVar26 < 1) &&
             ((0x1e < -uVar26 && uVar26 != 0xffffffe1 ||
              ((int)((pDVar10->map >> (-uVar26 & 0xff)) << 0x1f) < 0)))) goto LAB_0005a0b4;
          uVar21 = *(undefined4 *)(psVar15->read_sequence + 4);
          *(undefined4 *)(psVar15->rrec).seq_num = *(undefined4 *)psVar15->read_sequence;
          *(undefined4 *)((psVar15->rrec).seq_num + 4) = uVar21;
        }
        if ((psVar22->rrec).length == 0) {
          pdVar16 = param_1->d1;
          goto LAB_00059dc2;
        }
        if (!bVar4) {
          iVar8 = dtls1_process_record();
          if (iVar8 != 0) {
            return 1;
          }
          pdVar16 = param_1->d1;
          (psVar22->rrec).length = 0;
          param_1->packet_length = 0;
          goto LAB_00059dc2;
        }
        uVar19 = SSL_state(param_1);
        if (((uVar19 & 0x3000) != 0) || (param_1->in_handshake != 0)) {
          pdVar16 = param_1->d1;
          if (pdVar16->mtu != 0) goto LAB_0005a0b4;
          iVar8 = dtls1_buffer_record_isra_6
                            (param_1,&(pdVar16->unprocessed_rcds).q,(psVar22->rrec).seq_num);
          if (iVar8 < 0) {
            return -1;
          }
        }
        pdVar16 = param_1->d1;
      }
      else if (((uVar11 == uVar19 + 1) && ((pdVar16->unprocessed_rcds).epoch != uVar19)) &&
              ((psVar22->rrec).type - 0x15U < 2)) {
        pDVar10 = &pdVar16->next_bitmap;
        bVar4 = true;
        goto LAB_0005a266;
      }
LAB_0005a0b4:
      (psVar22->rrec).length = 0;
      param_1->packet_length = 0;
      goto LAB_00059dc2;
    }
  }
  else {
    iVar8 = ssl3_read_n(param_1,0xd,(param_1->s3->rbuf).len,0);
    if (iVar8 < 1) {
      return iVar8;
    }
    if (param_1->packet_length != 0xd) {
      param_1->packet_length = 0;
      pdVar16 = param_1->d1;
      goto LAB_00059dc2;
    }
    pbVar20 = param_1->packet;
    param_1->rstate = 0xf1;
    psVar15 = param_1->s3;
    (psVar22->rrec).type = (uint)*pbVar20;
    bVar1 = pbVar20[1];
    bVar2 = pbVar20[2];
    (psVar22->rrec).epoch = (uint)CONCAT11(pbVar20[3],pbVar20[4]);
    *(undefined4 *)(psVar15->read_sequence + 2) = *(undefined4 *)(pbVar20 + 5);
    *(undefined2 *)(psVar15->read_sequence + 6) = *(undefined2 *)(pbVar20 + 9);
    iVar8 = param_1->max_cert_list;
    uVar24 = (uint)CONCAT11(pbVar20[0xb],pbVar20[0xc]);
    uVar19 = param_1->version;
    (psVar22->rrec).length = uVar24;
    if (iVar8 == 0) {
      if (CONCAT11(bVar1,bVar2) == uVar19) {
LAB_0005a426:
        if (uVar24 < 0x4541) {
          uVar19 = param_1->packet_length;
          goto LAB_0005a084;
        }
        goto LAB_0005a238;
      }
      (psVar22->rrec).length = 0;
      pdVar16 = param_1->d1;
      param_1->packet_length = 0;
      goto LAB_00059dc2;
    }
    if (((uVar19 ^ CONCAT11(bVar1,bVar2)) & 0xff00) == 0) goto LAB_0005a426;
  }
LAB_0005a238:
  pdVar16 = param_1->d1;
  (psVar22->rrec).length = 0;
  param_1->packet_length = 0;
  goto LAB_00059dc2;
LAB_0005a1ae:
  iVar8 = dtls1_buffer_record_isra_6
                    (param_1,&(param_1->d1->processed_rcds).q,(param_1->s3->rrec).seq_num);
  if (iVar8 < 0) {
    return -1;
  }
  pdVar16 = param_1->d1;
  goto LAB_00059e8a;
}

