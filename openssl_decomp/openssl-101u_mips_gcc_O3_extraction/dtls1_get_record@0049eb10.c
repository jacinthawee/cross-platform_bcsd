
int dtls1_get_record(SSL *param_1)

{
  ushort uVar1;
  bool bVar2;
  int *piVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  ssl3_state_st *psVar7;
  byte *pbVar8;
  uint uVar9;
  uchar **ppuVar10;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  SSL3_RECORD *pSVar14;
  uchar *puVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  DTLS1_BITMAP *pDVar19;
  ssl3_state_st *psVar20;
  uchar *puVar21;
  uchar *puVar22;
  uchar *puVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  dtls1_state_st *pdVar27;
  uchar **ppuVar28;
  ssl3_state_st *psVar29;
  
  psVar29 = param_1->s3;
  pdVar27 = param_1->d1;
LAB_0049eb68:
  do {
    iVar5 = (*(code *)PTR_pqueue_peek_006a82a4)((pdVar27->unprocessed_rcds).q);
joined_r0x0049eb74:
    if (iVar5 == 0) {
LAB_0049ed80:
      pdVar27 = param_1->d1;
      uVar1 = pdVar27->r_epoch;
      (pdVar27->processed_rcds).epoch = uVar1;
      (pdVar27->unprocessed_rcds).epoch = uVar1 + 1;
    }
    else {
      pdVar27 = param_1->d1;
      if (((pdVar27->unprocessed_rcds).epoch == pdVar27->r_epoch) &&
         (psVar20 = param_1->s3, (psVar20->rbuf).left < 1)) {
        while (iVar5 = (*(code *)PTR_pqueue_peek_006a82a4)((pdVar27->unprocessed_rcds).q),
              iVar5 != 0) {
          iVar5 = (*(code *)PTR_pqueue_pop_006a827c)((param_1->d1->unprocessed_rcds).q);
          if (iVar5 != 0) {
            psVar7 = param_1->s3;
            puVar15 = (psVar7->rbuf).buf;
            ppuVar28 = *(uchar ***)(iVar5 + 8);
            if (puVar15 != (uchar *)0x0) {
              CRYPTO_free(puVar15);
              psVar7 = param_1->s3;
            }
            puVar15 = ppuVar28[1];
            ppuVar10 = ppuVar28 + 6;
            param_1->packet = *ppuVar28;
            param_1->packet_length = (uint)puVar15;
            puVar23 = ppuVar28[3];
            puVar21 = ppuVar28[4];
            puVar15 = ppuVar28[5];
            (psVar7->rbuf).buf = ppuVar28[2];
            (psVar7->rbuf).len = (size_t)puVar23;
            (psVar7->rbuf).offset = (int)puVar21;
            (psVar7->rbuf).left = (int)puVar15;
            pSVar14 = &param_1->s3->rrec;
            do {
              puVar22 = *ppuVar10;
              puVar23 = ppuVar10[1];
              puVar21 = ppuVar10[2];
              puVar15 = ppuVar10[3];
              ppuVar10 = ppuVar10 + 4;
              pSVar14->type = (int)puVar22;
              pSVar14->length = (uint)puVar23;
              pSVar14->off = (uint)puVar21;
              pSVar14->data = puVar15;
              pSVar14 = (SSL3_RECORD *)&pSVar14->input;
            } while (ppuVar10 != ppuVar28 + 0xe);
            *(uchar **)pSVar14 = *ppuVar10;
            puVar21 = *ppuVar28;
            psVar7 = param_1->s3;
            uVar16 = *(uint *)(puVar21 + 5);
            puVar15 = psVar7->read_sequence + 2;
            uVar6 = (uint)puVar15 & 3;
            *(uint *)(puVar15 + -uVar6) =
                 *(uint *)(puVar15 + -uVar6) & -1 << (4 - uVar6) * 8 | uVar16 >> uVar6 * 8;
            puVar15 = psVar7->read_sequence + 5;
            uVar6 = (uint)puVar15 & 3;
            *(uint *)(puVar15 + -uVar6) =
                 *(uint *)(puVar15 + -uVar6) & 0xffffffffU >> (uVar6 + 1) * 8 |
                 uVar16 << (3 - uVar6) * 8;
            psVar7->read_sequence[6] = puVar21[9];
            psVar7->read_sequence[7] = puVar21[10];
            CRYPTO_free(*(void **)(iVar5 + 8));
            (*(code *)PTR_pitem_free_006a8278)(iVar5);
          }
          pdVar27 = param_1->d1;
          uVar16 = (psVar20->rrec).epoch;
          uVar6 = (uint)pdVar27->r_epoch;
          if (uVar16 == uVar6) {
            pDVar19 = &pdVar27->bitmap;
          }
          else if (((uVar16 != uVar6 + 1) || ((pdVar27->unprocessed_rcds).epoch == uVar6)) ||
                  (pDVar19 = &pdVar27->next_bitmap, 1 < (psVar20->rrec).type - 0x15U)) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x1a8,0x44,"d1_pkt.c",0x167);
            return -1;
          }
          psVar7 = param_1->s3;
          uVar6 = (uint)psVar7->read_sequence[7] - (uint)pDVar19->max_seq_num[7];
          if ((uVar6 & 0x80) == 0) {
            uVar12 = ((uint)psVar7->read_sequence[6] - (uint)pDVar19->max_seq_num[6]) +
                     ((int)uVar6 >> 8);
            uVar18 = ((uint)psVar7->read_sequence[5] - (uint)pDVar19->max_seq_num[5]) +
                     ((int)uVar12 >> 8);
            uVar26 = ((uint)psVar7->read_sequence[4] - (uint)pDVar19->max_seq_num[4]) +
                     ((int)uVar18 >> 8);
            uVar25 = ((uint)psVar7->read_sequence[3] - (uint)pDVar19->max_seq_num[3]) +
                     ((int)uVar26 >> 8);
            uVar24 = ((uint)psVar7->read_sequence[2] - (uint)pDVar19->max_seq_num[2]) +
                     ((int)uVar25 >> 8);
            uVar17 = ((uint)psVar7->read_sequence[1] - (uint)pDVar19->max_seq_num[1]) +
                     ((int)uVar24 >> 8);
            uVar9 = ((uint)psVar7->read_sequence[0] - (uint)pDVar19->max_seq_num[0]) +
                    ((int)uVar17 >> 8);
            uVar16 = ((int)uVar9 >> 8) << 8;
            if (((uVar12 | uVar18 | uVar26 | uVar25 | uVar24 | uVar17 | uVar9) & 0xff) == 0)
            goto LAB_0049f088;
LAB_0049f1b8:
            uVar16 = uVar16 | 0x80;
          }
          else {
            uVar18 = ((uint)psVar7->read_sequence[6] - (uint)pDVar19->max_seq_num[6]) +
                     ((int)uVar6 >> 8);
            uVar26 = ((uint)psVar7->read_sequence[5] - (uint)pDVar19->max_seq_num[5]) +
                     ((int)uVar18 >> 8);
            uVar25 = ((uint)psVar7->read_sequence[4] - (uint)pDVar19->max_seq_num[4]) +
                     ((int)uVar26 >> 8);
            uVar24 = ((uint)psVar7->read_sequence[3] - (uint)pDVar19->max_seq_num[3]) +
                     ((int)uVar25 >> 8);
            uVar9 = ((uint)psVar7->read_sequence[2] - (uint)pDVar19->max_seq_num[2]) +
                    ((int)uVar24 >> 8);
            uVar17 = ((uint)psVar7->read_sequence[1] - (uint)pDVar19->max_seq_num[1]) +
                     ((int)uVar9 >> 8);
            uVar12 = ((uint)psVar7->read_sequence[0] - (uint)pDVar19->max_seq_num[0]) +
                     ((int)uVar17 >> 8);
            uVar16 = ((int)uVar12 >> 8) << 8;
            if ((~(uVar12 & uVar17 & uVar9 & uVar24 & uVar25 & uVar26 & uVar18) & 0xff) != 0)
            goto LAB_0049f1b8;
LAB_0049f088:
            uVar16 = (uVar6 & 0xff) + uVar16;
          }
          if (((int)uVar16 < 1) &&
             ((0x1f < (int)-uVar16 || ((pDVar19->map >> (-uVar16 & 0x1f) & 1) != 0)))) {
            (psVar20->rrec).length = 0;
            param_1->packet_length = 0;
          }
          else {
            uVar16 = *(uint *)psVar7->read_sequence;
            uVar13 = *(undefined4 *)(psVar7->read_sequence + 4);
            puVar15 = (psVar7->rrec).seq_num;
            uVar6 = (uint)puVar15 & 3;
            puVar15 = puVar15 + -uVar6;
            *(uint *)puVar15 = *(uint *)puVar15 & -1 << (4 - uVar6) * 8 | uVar16 >> uVar6 * 8;
            puVar15 = (psVar7->rrec).seq_num + 3;
            uVar6 = (uint)puVar15 & 3;
            *(uint *)(puVar15 + -uVar6) =
                 *(uint *)(puVar15 + -uVar6) & 0xffffffffU >> (uVar6 + 1) * 8 |
                 uVar16 << (3 - uVar6) * 8;
            *(undefined4 *)((psVar7->rrec).seq_num + 4) = uVar13;
            iVar5 = dtls1_process_record(param_1);
            if (iVar5 == 0) {
              pdVar27 = param_1->d1;
              (psVar20->rrec).length = 0;
              param_1->packet_length = 0;
            }
            else {
              pdVar27 = param_1->d1;
              psVar7 = param_1->s3;
              iVar5 = (*(code *)PTR_pqueue_size_006a82ac)((pdVar27->processed_rcds).q);
              if (iVar5 < 100) {
                iVar5 = dtls1_buffer_record_isra_6_part_7
                                  (param_1,&(pdVar27->processed_rcds).q,(psVar7->rrec).seq_num);
                if (iVar5 < 0) {
                  return -1;
                }
                pdVar27 = param_1->d1;
              }
              else {
                pdVar27 = param_1->d1;
              }
            }
          }
        }
        goto LAB_0049ed80;
      }
    }
    iVar5 = (*(code *)PTR_pqueue_pop_006a827c)((pdVar27->processed_rcds).q);
    if (iVar5 != 0) {
      psVar29 = param_1->s3;
      puVar15 = (psVar29->rbuf).buf;
      ppuVar28 = *(uchar ***)(iVar5 + 8);
      if (puVar15 != (uchar *)0x0) {
        CRYPTO_free(puVar15);
        psVar29 = param_1->s3;
      }
      puVar15 = ppuVar28[1];
      ppuVar10 = ppuVar28 + 6;
      param_1->packet = *ppuVar28;
      param_1->packet_length = (uint)puVar15;
      puVar23 = ppuVar28[3];
      puVar21 = ppuVar28[4];
      puVar15 = ppuVar28[5];
      (psVar29->rbuf).buf = ppuVar28[2];
      (psVar29->rbuf).len = (size_t)puVar23;
      (psVar29->rbuf).offset = (int)puVar21;
      (psVar29->rbuf).left = (int)puVar15;
      pSVar14 = &param_1->s3->rrec;
      do {
        puVar22 = *ppuVar10;
        puVar23 = ppuVar10[1];
        puVar15 = ppuVar10[2];
        puVar21 = ppuVar10[3];
        ppuVar10 = ppuVar10 + 4;
        pSVar14->type = (int)puVar22;
        pSVar14->length = (uint)puVar23;
        pSVar14->off = (uint)puVar15;
        pSVar14->data = puVar21;
        pSVar14 = (SSL3_RECORD *)&pSVar14->input;
      } while (ppuVar10 != ppuVar28 + 0xe);
      *(uchar **)pSVar14 = *ppuVar10;
      puVar21 = *ppuVar28;
      psVar29 = param_1->s3;
      uVar16 = *(uint *)(puVar21 + 5);
      puVar15 = psVar29->read_sequence + 2;
      uVar6 = (uint)puVar15 & 3;
      *(uint *)(puVar15 + -uVar6) =
           *(uint *)(puVar15 + -uVar6) & -1 << (4 - uVar6) * 8 | uVar16 >> uVar6 * 8;
      puVar15 = psVar29->read_sequence + 5;
      uVar6 = (uint)puVar15 & 3;
      *(uint *)(puVar15 + -uVar6) =
           *(uint *)(puVar15 + -uVar6) & 0xffffffffU >> (uVar6 + 1) * 8 | uVar16 << (3 - uVar6) * 8;
      psVar29->read_sequence[6] = puVar21[9];
      psVar29->read_sequence[7] = puVar21[10];
      CRYPTO_free(*(void **)(iVar5 + 8));
      (*(code *)PTR_pitem_free_006a8278)(iVar5);
      return 1;
    }
    if ((param_1->rstate == 0xf1) && (uVar6 = param_1->packet_length, 0xc < uVar6)) {
      uVar16 = (psVar29->rrec).length;
    }
    else {
      iVar5 = ssl3_read_n(param_1,0xd,(param_1->s3->rbuf).len,0);
      if (iVar5 < 1) {
        return iVar5;
      }
      if (param_1->packet_length != 0xd) {
        pdVar27 = param_1->d1;
        param_1->packet_length = 0;
        goto LAB_0049eb68;
      }
      pbVar8 = param_1->packet;
      param_1->rstate = 0xf1;
      psVar20 = param_1->s3;
      (psVar29->rrec).type = (uint)*pbVar8;
      uVar1 = *(ushort *)(pbVar8 + 1);
      (psVar29->rrec).epoch = (uint)*(ushort *)(pbVar8 + 3);
      uVar16 = *(uint *)(pbVar8 + 5);
      puVar15 = psVar20->read_sequence + 2;
      uVar6 = (uint)puVar15 & 3;
      *(uint *)(puVar15 + -uVar6) =
           *(uint *)(puVar15 + -uVar6) & -1 << (4 - uVar6) * 8 | uVar16 >> uVar6 * 8;
      puVar15 = psVar20->read_sequence + 5;
      uVar6 = (uint)puVar15 & 3;
      *(uint *)(puVar15 + -uVar6) =
           *(uint *)(puVar15 + -uVar6) & 0xffffffffU >> (uVar6 + 1) * 8 | uVar16 << (3 - uVar6) * 8;
      psVar20->read_sequence[6] = pbVar8[9];
      psVar20->read_sequence[7] = pbVar8[10];
      iVar5 = param_1->max_cert_list;
      uVar16 = (uint)*(ushort *)(pbVar8 + 0xb);
      uVar6 = param_1->version;
      (psVar29->rrec).length = uVar16;
      if (iVar5 == 0) {
        if (uVar1 != uVar6) goto LAB_0049f2f0;
      }
      else if (((uVar1 ^ uVar6) & 0xff00) != 0) goto LAB_0049f2f0;
      if (0x4540 < uVar16) goto LAB_0049f2f0;
      uVar6 = param_1->packet_length;
    }
    if (uVar16 <= uVar6 - 0xd) {
      pdVar27 = param_1->d1;
      uVar16 = (psVar29->rrec).epoch;
      param_1->rstate = 0xf0;
      uVar6 = (uint)pdVar27->r_epoch;
      if (uVar16 == uVar6) goto LAB_0049f334;
LAB_0049ed58:
      if (((uVar16 == uVar6 + 1) && ((pdVar27->unprocessed_rcds).epoch != uVar6)) &&
         (pDVar19 = &pdVar27->next_bitmap, (psVar29->rrec).type - 0x15U < 2)) {
        bVar2 = true;
        goto LAB_0049f338;
      }
LAB_0049ed64:
      (psVar29->rrec).length = 0;
      param_1->packet_length = 0;
      goto LAB_0049ed6c;
    }
    uVar6 = ssl3_read_n(param_1,uVar16,uVar16,1);
    if (uVar16 != uVar6) goto LAB_0049f2f0;
    pdVar27 = param_1->d1;
    uVar16 = (psVar29->rrec).epoch;
    param_1->rstate = 0xf0;
    uVar6 = (uint)pdVar27->r_epoch;
    if (uVar16 != uVar6) goto LAB_0049ed58;
LAB_0049f334:
    pDVar19 = &pdVar27->bitmap;
    bVar2 = false;
LAB_0049f338:
    if (((pdVar27->mtu == 0) || ((psVar29->rrec).type != 0x16)) ||
       ((param_1->packet_length < 0xe || (param_1->packet[0xd] != '\x01')))) {
      psVar20 = param_1->s3;
      uVar6 = (uint)psVar20->read_sequence[7] - (uint)pDVar19->max_seq_num[7];
      if ((uVar6 & 0x80) == 0) {
        uVar12 = ((uint)psVar20->read_sequence[6] - (uint)pDVar19->max_seq_num[6]) +
                 ((int)uVar6 >> 8);
        uVar17 = ((uint)psVar20->read_sequence[5] - (uint)pDVar19->max_seq_num[5]) +
                 ((int)uVar12 >> 8);
        uVar26 = ((uint)psVar20->read_sequence[4] - (uint)pDVar19->max_seq_num[4]) +
                 ((int)uVar17 >> 8);
        uVar25 = ((uint)psVar20->read_sequence[3] - (uint)pDVar19->max_seq_num[3]) +
                 ((int)uVar26 >> 8);
        uVar24 = ((uint)psVar20->read_sequence[2] - (uint)pDVar19->max_seq_num[2]) +
                 ((int)uVar25 >> 8);
        uVar18 = ((uint)psVar20->read_sequence[1] - (uint)pDVar19->max_seq_num[1]) +
                 ((int)uVar24 >> 8);
        uVar9 = ((uint)psVar20->read_sequence[0] - (uint)pDVar19->max_seq_num[0]) +
                ((int)uVar18 >> 8);
        uVar16 = ((int)uVar9 >> 8) << 8;
        if (((uVar12 | uVar17 | uVar26 | uVar25 | uVar24 | uVar18 | uVar9) & 0xff) != 0)
        goto LAB_0049f53c;
LAB_0049f420:
        uVar16 = (uVar6 & 0xff) + uVar16;
      }
      else {
        uVar26 = ((uint)psVar20->read_sequence[6] - (uint)pDVar19->max_seq_num[6]) +
                 ((int)uVar6 >> 8);
        uVar25 = ((uint)psVar20->read_sequence[5] - (uint)pDVar19->max_seq_num[5]) +
                 ((int)uVar26 >> 8);
        uVar24 = ((uint)psVar20->read_sequence[4] - (uint)pDVar19->max_seq_num[4]) +
                 ((int)uVar25 >> 8);
        uVar12 = ((uint)psVar20->read_sequence[3] - (uint)pDVar19->max_seq_num[3]) +
                 ((int)uVar24 >> 8);
        uVar18 = ((uint)psVar20->read_sequence[2] - (uint)pDVar19->max_seq_num[2]) +
                 ((int)uVar12 >> 8);
        uVar17 = ((uint)psVar20->read_sequence[1] - (uint)pDVar19->max_seq_num[1]) +
                 ((int)uVar18 >> 8);
        uVar9 = ((uint)psVar20->read_sequence[0] - (uint)pDVar19->max_seq_num[0]) +
                ((int)uVar17 >> 8);
        uVar16 = ((int)uVar9 >> 8) << 8;
        if ((~(uVar9 & uVar17 & uVar18 & uVar12 & uVar24 & uVar25 & uVar26) & 0xff) == 0)
        goto LAB_0049f420;
LAB_0049f53c:
        uVar16 = uVar16 | 0x80;
      }
      if (((int)uVar16 < 1) &&
         ((0x1f < (int)-uVar16 || ((pDVar19->map >> (-uVar16 & 0x1f) & 1) != 0))))
      goto LAB_0049ed64;
      uVar16 = *(uint *)psVar20->read_sequence;
      uVar13 = *(undefined4 *)(psVar20->read_sequence + 4);
      puVar15 = (psVar20->rrec).seq_num;
      uVar6 = (uint)puVar15 & 3;
      puVar15 = puVar15 + -uVar6;
      *(uint *)puVar15 = *(uint *)puVar15 & -1 << (4 - uVar6) * 8 | uVar16 >> uVar6 * 8;
      puVar15 = (psVar20->rrec).seq_num + 3;
      uVar6 = (uint)puVar15 & 3;
      *(uint *)(puVar15 + -uVar6) =
           *(uint *)(puVar15 + -uVar6) & 0xffffffffU >> (uVar6 + 1) * 8 | uVar16 << (3 - uVar6) * 8;
      *(undefined4 *)((psVar20->rrec).seq_num + 4) = uVar13;
      uVar6 = (psVar29->rrec).length;
    }
    else {
      uVar6 = (psVar29->rrec).length;
    }
    if (uVar6 == 0) {
      pdVar27 = param_1->d1;
      goto LAB_0049eb68;
    }
    if (bVar2) {
      uVar6 = SSL_state(param_1);
      if (((uVar6 & 0x3000) != 0) || (param_1->in_handshake != 0)) {
        pdVar27 = param_1->d1;
        if (pdVar27->mtu != 0) goto LAB_0049ed64;
        iVar5 = (*(code *)PTR_pqueue_size_006a82ac)((pdVar27->unprocessed_rcds).q);
        if (iVar5 < 100) {
          ppuVar28 = (uchar **)CRYPTO_malloc(0x3c,"d1_pkt.c",0xe6);
          iVar5 = (*(code *)PTR_pitem_new_006a829c)((psVar29->rrec).seq_num,ppuVar28);
          if (ppuVar28 == (uchar **)0x0) {
            if (iVar5 != 0) {
              (*(code *)PTR_pitem_free_006a8278)(iVar5);
            }
LAB_0049f7f4:
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf7,0x44,"d1_pkt.c",0xee);
            return -1;
          }
          if (iVar5 == 0) {
            CRYPTO_free(ppuVar28);
            goto LAB_0049f7f4;
          }
          psVar20 = param_1->s3;
          ppuVar10 = ppuVar28 + 6;
          puVar15 = (uchar *)param_1->packet_length;
          *ppuVar28 = param_1->packet;
          ppuVar28[1] = puVar15;
          puVar23 = (uchar *)(psVar20->rbuf).len;
          puVar21 = (uchar *)(psVar20->rbuf).offset;
          puVar15 = (uchar *)(psVar20->rbuf).left;
          ppuVar28[2] = (psVar20->rbuf).buf;
          ppuVar28[3] = puVar23;
          ppuVar28[4] = puVar21;
          ppuVar28[5] = puVar15;
          psVar20 = param_1->s3;
          pSVar14 = &psVar20->rrec;
          do {
            piVar3 = &pSVar14->type;
            puVar23 = (uchar *)pSVar14->length;
            puVar21 = (uchar *)pSVar14->off;
            puVar15 = pSVar14->data;
            pSVar14 = (SSL3_RECORD *)&pSVar14->input;
            *ppuVar10 = (uchar *)*piVar3;
            ppuVar10[1] = puVar23;
            ppuVar10[2] = puVar21;
            ppuVar10[3] = puVar15;
            puVar4 = PTR_memset_006a99f4;
            ppuVar10 = ppuVar10 + 4;
          } while (pSVar14 != (SSL3_RECORD *)((psVar20->rrec).seq_num + 4));
          *ppuVar10 = *(uchar **)pSVar14;
          *(uchar ***)(iVar5 + 8) = ppuVar28;
          param_1->packet = (uchar *)0x0;
          param_1->packet_length = 0;
          (*(code *)puVar4)(&param_1->s3->rbuf,0,0x10);
          (*(code *)PTR_memset_006a99f4)(&param_1->s3->rrec,0,0x24);
          iVar11 = ssl3_setup_buffers(param_1);
          if (iVar11 == 0) {
            uVar13 = 0x109;
LAB_0049f744:
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf7,0x44,"d1_pkt.c",uVar13);
            if (ppuVar28[2] != (uchar *)0x0) {
              CRYPTO_free(ppuVar28[2]);
            }
            CRYPTO_free(ppuVar28);
            (*(code *)PTR_pitem_free_006a8278)(iVar5);
            return -1;
          }
          iVar11 = (*(code *)PTR_pqueue_insert_006a82a0)((pdVar27->unprocessed_rcds).q,iVar5);
          if (iVar11 == 0) {
            uVar13 = 0x113;
            goto LAB_0049f744;
          }
        }
      }
      pdVar27 = param_1->d1;
      (psVar29->rrec).length = 0;
      param_1->packet_length = 0;
LAB_0049ed6c:
      iVar5 = (*(code *)PTR_pqueue_peek_006a82a4)((pdVar27->unprocessed_rcds).q);
      goto joined_r0x0049eb74;
    }
    iVar5 = dtls1_process_record(param_1);
    if (iVar5 != 0) {
      return 1;
    }
LAB_0049f2f0:
    pdVar27 = param_1->d1;
    (psVar29->rrec).length = 0;
    param_1->packet_length = 0;
  } while( true );
}

