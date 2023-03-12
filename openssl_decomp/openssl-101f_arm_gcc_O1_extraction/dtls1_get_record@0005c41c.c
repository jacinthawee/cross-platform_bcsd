
uint dtls1_get_record(SSL *param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  pitem *ppVar4;
  uchar *puVar5;
  pqueue pq;
  uint uVar6;
  int iVar7;
  ssl3_state_st *psVar8;
  uchar *puVar9;
  uchar **ppuVar10;
  SSL3_RECORD *pSVar11;
  DTLS1_BITMAP *pDVar12;
  undefined4 uVar13;
  dtls1_state_st *pdVar14;
  uchar **ppuVar15;
  uchar **ppuVar16;
  ulong uVar17;
  byte *pbVar18;
  ssl3_state_st *psVar19;
  uchar **ppuVar20;
  uchar *puVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint local_34;
  pitem *local_30;
  
  psVar19 = param_1->s3;
  ppVar4 = pqueue_peek((param_1->d1->unprocessed_rcds).q);
  if (ppVar4 != (pitem *)0x0) {
    pdVar14 = param_1->d1;
    if ((pdVar14->unprocessed_rcds).epoch != pdVar14->r_epoch) {
LAB_0005c448:
      local_30 = pqueue_pop((pdVar14->processed_rcds).q);
      goto joined_r0x0005c5d2;
    }
    while (ppVar4 = pqueue_peek((pdVar14->unprocessed_rcds).q), ppVar4 != (pitem *)0x0) {
      ppVar4 = pqueue_pop((param_1->d1->unprocessed_rcds).q);
      if (ppVar4 != (pitem *)0x0) {
        psVar8 = param_1->s3;
        ppuVar20 = (uchar **)ppVar4->data;
        puVar5 = (psVar8->rbuf).buf;
        if (puVar5 != (uchar *)0x0) {
          CRYPTO_free(puVar5);
          psVar8 = param_1->s3;
        }
        puVar5 = *ppuVar20;
        param_1->packet_length = (uint)ppuVar20[1];
        param_1->packet = puVar5;
        puVar21 = ppuVar20[3];
        puVar9 = ppuVar20[4];
        puVar5 = ppuVar20[5];
        (psVar8->rbuf).buf = ppuVar20[2];
        (psVar8->rbuf).len = (size_t)puVar21;
        (psVar8->rbuf).offset = (int)puVar9;
        (psVar8->rbuf).left = (int)puVar5;
        pSVar11 = &param_1->s3->rrec;
        ppuVar16 = ppuVar20 + 6;
        do {
          ppuVar15 = ppuVar16 + 4;
          puVar21 = ppuVar16[1];
          ppuVar10 = &pSVar11->input;
          puVar5 = ppuVar16[2];
          puVar9 = ppuVar16[3];
          pSVar11->type = (int)*ppuVar16;
          pSVar11->length = (uint)puVar21;
          pSVar11->off = (uint)puVar5;
          pSVar11->data = puVar9;
          pSVar11 = (SSL3_RECORD *)ppuVar10;
          ppuVar16 = ppuVar15;
        } while (ppuVar15 != ppuVar20 + 0xe);
        *ppuVar10 = *ppuVar15;
        puVar5 = *ppuVar20;
        psVar8 = param_1->s3;
        *(undefined4 *)(psVar8->read_sequence + 2) = *(undefined4 *)(puVar5 + 5);
        *(undefined2 *)(psVar8->read_sequence + 6) = *(undefined2 *)(puVar5 + 9);
        CRYPTO_free(ppVar4->data);
        pitem_free(ppVar4);
      }
      iVar7 = dtls1_process_record(param_1);
      if (iVar7 == 0) {
        pdVar14 = param_1->d1;
        goto LAB_0005c448;
      }
      dtls1_buffer_record_isra_6
                (param_1,&(param_1->d1->processed_rcds).q,(param_1->s3->rrec).seq_num);
      pdVar14 = param_1->d1;
    }
  }
  pdVar14 = param_1->d1;
  uVar3 = pdVar14->r_epoch;
  pq = (pdVar14->processed_rcds).q;
  (pdVar14->unprocessed_rcds).epoch = uVar3 + 1;
  (pdVar14->processed_rcds).epoch = uVar3;
  local_30 = pqueue_pop(pq);
joined_r0x0005c5d2:
  if (local_30 == (pitem *)0x0) {
LAB_0005c61c:
    do {
      if ((param_1->rstate != 0xf1) || (uVar6 = param_1->packet_length, uVar6 < 0xd)) {
        uVar6 = ssl3_read_n(param_1,0xd,(param_1->s3->rbuf).len,0);
        if ((int)uVar6 < 1) {
          return uVar6;
        }
        if (param_1->packet_length != 0xd) goto LAB_0005c61a;
        pbVar18 = param_1->packet;
        param_1->rstate = 0xf1;
        local_30 = (pitem *)(pbVar18 + 0xd);
        psVar8 = param_1->s3;
        (psVar19->rrec).type = (uint)*pbVar18;
        bVar2 = pbVar18[1];
        bVar1 = pbVar18[2];
        (psVar19->rrec).epoch = (uint)CONCAT11(pbVar18[3],pbVar18[4]);
        *(undefined4 *)(psVar8->read_sequence + 2) = *(undefined4 *)(pbVar18 + 5);
        *(undefined2 *)(psVar8->read_sequence + 6) = *(undefined2 *)(pbVar18 + 9);
        local_34 = param_1->max_cert_list;
        uVar22 = (uint)CONCAT11(pbVar18[0xb],pbVar18[0xc]);
        uVar6 = param_1->version;
        (psVar19->rrec).length = uVar22;
        if (local_34 != 0) {
          if (((uVar6 ^ CONCAT11(bVar2,bVar1)) & 0xff00) == 0) goto LAB_0005c882;
          goto LAB_0005c616;
        }
        if (CONCAT11(bVar2,bVar1) == uVar6) {
LAB_0005c882:
          if (uVar22 < 0x4541) {
            uVar6 = param_1->packet_length;
            goto LAB_0005c5ee;
          }
          goto LAB_0005c616;
        }
        goto LAB_0005c694;
      }
      uVar22 = (psVar19->rrec).length;
LAB_0005c5ee:
      if (uVar6 - 0xd < uVar22) {
        uVar6 = ssl3_read_n(param_1,uVar22,uVar22,1);
        if ((int)uVar6 < 1) {
          return uVar6;
        }
        if (uVar6 != uVar22) goto LAB_0005c616;
      }
      pdVar14 = param_1->d1;
      param_1->rstate = 0xf0;
      uVar17 = (psVar19->rrec).epoch;
      if (uVar17 == pdVar14->r_epoch) {
        pDVar12 = &pdVar14->bitmap;
        local_34 = 0;
      }
      else {
        if ((uVar17 != pdVar14->r_epoch + 1) || (1 < (psVar19->rrec).type - 0x15U))
        goto LAB_0005c616;
        pDVar12 = &pdVar14->next_bitmap;
        local_34 = 1;
      }
      if (((pdVar14->mtu == 0) || ((psVar19->rrec).type != 0x16)) || (local_30->priority[0] != 1)) {
        psVar8 = param_1->s3;
        uVar6 = (uint)psVar8->read_sequence[7] - (uint)pDVar12->max_seq_num[7];
        if ((uVar6 & 0x80) == 0) {
          uVar22 = ((int)uVar6 >> 8) +
                   ((uint)psVar8->read_sequence[6] - (uint)pDVar12->max_seq_num[6]);
          uVar23 = ((uint)psVar8->read_sequence[5] - (uint)pDVar12->max_seq_num[5]) +
                   ((int)uVar22 >> 8);
          uVar27 = ((uint)psVar8->read_sequence[4] - (uint)pDVar12->max_seq_num[4]) +
                   ((int)uVar23 >> 8);
          uVar25 = ((uint)psVar8->read_sequence[3] - (uint)pDVar12->max_seq_num[3]) +
                   ((int)uVar27 >> 8);
          uVar24 = ((uint)psVar8->read_sequence[2] - (uint)pDVar12->max_seq_num[2]) +
                   ((int)uVar25 >> 8);
          uVar26 = ((uint)psVar8->read_sequence[1] - (uint)pDVar12->max_seq_num[1]) +
                   ((int)uVar24 >> 8);
          uVar28 = ((uint)psVar8->read_sequence[0] - (uint)pDVar12->max_seq_num[0]) +
                   ((int)uVar26 >> 8);
          uVar22 = uVar23 | uVar22 | uVar27 | uVar25 | uVar24 | uVar26 | uVar28;
        }
        else {
          uVar25 = ((uint)psVar8->read_sequence[6] - (uint)pDVar12->max_seq_num[6]) +
                   ((int)uVar6 >> 8);
          uVar23 = ((uint)psVar8->read_sequence[5] - (uint)pDVar12->max_seq_num[5]) +
                   ((int)uVar25 >> 8);
          uVar26 = ((uint)psVar8->read_sequence[4] - (uint)pDVar12->max_seq_num[4]) +
                   ((int)uVar23 >> 8);
          uVar27 = ((uint)psVar8->read_sequence[3] - (uint)pDVar12->max_seq_num[3]) +
                   ((int)uVar26 >> 8);
          uVar22 = ((uint)psVar8->read_sequence[2] - (uint)pDVar12->max_seq_num[2]) +
                   ((int)uVar27 >> 8);
          uVar24 = ((uint)psVar8->read_sequence[1] - (uint)pDVar12->max_seq_num[1]) +
                   ((int)uVar22 >> 8);
          uVar28 = ((uint)psVar8->read_sequence[0] - (uint)pDVar12->max_seq_num[0]) +
                   ((int)uVar24 >> 8);
          uVar22 = ~uVar25 | ~uVar23 | ~uVar26 | ~uVar27 | ~uVar22 | ~uVar24 | ~uVar28;
        }
        uVar23 = ((int)uVar28 >> 8) * 0x100;
        if ((uVar22 & 0xff) == 0) {
          uVar23 = uVar23 + (uVar6 & 0xff);
        }
        else {
          uVar23 = uVar23 | 0x80;
        }
        if (((int)uVar23 < 1) &&
           ((0x1e < -uVar23 && uVar23 != 0xffffffe1 ||
            ((int)((pDVar12->map >> (-uVar23 & 0xff)) << 0x1f) < 0)))) goto LAB_0005c616;
        uVar13 = *(undefined4 *)(psVar8->read_sequence + 4);
        *(undefined4 *)(psVar8->rrec).seq_num = *(undefined4 *)psVar8->read_sequence;
        *(undefined4 *)((psVar8->rrec).seq_num + 4) = uVar13;
      }
    } while ((psVar19->rrec).length == 0);
    if (local_34 != 0) {
      uVar6 = SSL_state(param_1);
      if ((((uVar6 & 0x3000) != 0) || (param_1->in_handshake != 0)) && (param_1->d1->mtu == 0)) {
        dtls1_buffer_record_isra_6
                  (param_1,&(param_1->d1->unprocessed_rcds).q,(psVar19->rrec).seq_num);
      }
LAB_0005c616:
      (psVar19->rrec).length = 0;
LAB_0005c61a:
      param_1->packet_length = 0;
      goto LAB_0005c61c;
    }
    iVar7 = dtls1_process_record();
    if (iVar7 == 0) {
LAB_0005c694:
      (psVar19->rrec).length = local_34;
      param_1->packet_length = local_34;
      goto LAB_0005c61c;
    }
  }
  else {
    psVar19 = param_1->s3;
    ppuVar20 = (uchar **)local_30->data;
    puVar5 = (psVar19->rbuf).buf;
    if (puVar5 != (uchar *)0x0) {
      CRYPTO_free(puVar5);
      psVar19 = param_1->s3;
    }
    puVar5 = ppuVar20[1];
    param_1->packet = *ppuVar20;
    param_1->packet_length = (uint)puVar5;
    puVar21 = ppuVar20[3];
    puVar5 = ppuVar20[4];
    puVar9 = ppuVar20[5];
    (psVar19->rbuf).buf = ppuVar20[2];
    (psVar19->rbuf).len = (size_t)puVar21;
    (psVar19->rbuf).offset = (int)puVar5;
    (psVar19->rbuf).left = (int)puVar9;
    pSVar11 = &param_1->s3->rrec;
    ppuVar16 = ppuVar20 + 6;
    do {
      ppuVar15 = ppuVar16 + 4;
      puVar21 = ppuVar16[1];
      ppuVar10 = &pSVar11->input;
      puVar5 = ppuVar16[2];
      puVar9 = ppuVar16[3];
      pSVar11->type = (int)*ppuVar16;
      pSVar11->length = (uint)puVar21;
      pSVar11->off = (uint)puVar5;
      pSVar11->data = puVar9;
      pSVar11 = (SSL3_RECORD *)ppuVar10;
      ppuVar16 = ppuVar15;
    } while (ppuVar15 != ppuVar20 + 0xe);
    *ppuVar10 = *ppuVar15;
    puVar5 = *ppuVar20;
    psVar19 = param_1->s3;
    *(undefined4 *)(psVar19->read_sequence + 2) = *(undefined4 *)(puVar5 + 5);
    *(undefined2 *)(psVar19->read_sequence + 6) = *(undefined2 *)(puVar5 + 9);
    CRYPTO_free(local_30->data);
    pitem_free(local_30);
  }
  return 1;
}

