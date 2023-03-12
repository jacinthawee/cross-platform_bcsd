
uint dtls1_get_record(SSL *param_1)

{
  ushort uVar1;
  bool bVar2;
  int *piVar3;
  undefined *puVar4;
  int iVar5;
  dtls1_state_st *pdVar6;
  byte *pbVar7;
  SSL3_RECORD *pSVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  uchar *puVar12;
  uint uVar13;
  uchar **ppuVar14;
  uint uVar15;
  uint uVar16;
  DTLS1_BITMAP *pDVar17;
  uchar *puVar18;
  uchar *puVar19;
  uchar *puVar20;
  ssl3_state_st *psVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  ssl3_state_st *psVar26;
  uchar **ppuVar27;
  byte *pbVar28;
  uint uVar29;
  
  psVar26 = param_1->s3;
  iVar5 = (*(code *)PTR_pqueue_peek_006a93c4)((param_1->d1->unprocessed_rcds).q);
  if (iVar5 != 0) {
    pdVar6 = param_1->d1;
    if ((pdVar6->unprocessed_rcds).epoch != pdVar6->r_epoch) {
LAB_004a22f8:
      iVar5 = (*(code *)PTR_pqueue_pop_006a93a0)((pdVar6->processed_rcds).q);
      goto joined_r0x004a2308;
    }
    iVar5 = (*(code *)PTR_pqueue_peek_006a93c4)((pdVar6->unprocessed_rcds).q);
    while (iVar5 != 0) {
      iVar5 = (*(code *)PTR_pqueue_pop_006a93a0)((param_1->d1->unprocessed_rcds).q);
      if (iVar5 != 0) {
        psVar21 = param_1->s3;
        puVar12 = (psVar21->rbuf).buf;
        ppuVar27 = *(uchar ***)(iVar5 + 8);
        if (puVar12 != (uchar *)0x0) {
          CRYPTO_free(puVar12);
          psVar21 = param_1->s3;
        }
        puVar12 = ppuVar27[1];
        ppuVar14 = ppuVar27 + 6;
        param_1->packet = *ppuVar27;
        param_1->packet_length = (uint)puVar12;
        puVar20 = ppuVar27[3];
        puVar18 = ppuVar27[4];
        puVar12 = ppuVar27[5];
        (psVar21->rbuf).buf = ppuVar27[2];
        (psVar21->rbuf).len = (size_t)puVar20;
        (psVar21->rbuf).offset = (int)puVar18;
        (psVar21->rbuf).left = (int)puVar12;
        pSVar8 = &param_1->s3->rrec;
        do {
          puVar19 = *ppuVar14;
          puVar20 = ppuVar14[1];
          puVar12 = ppuVar14[2];
          puVar18 = ppuVar14[3];
          ppuVar14 = ppuVar14 + 4;
          pSVar8->type = (int)puVar19;
          pSVar8->length = (uint)puVar20;
          pSVar8->off = (uint)puVar12;
          pSVar8->data = puVar18;
          pSVar8 = (SSL3_RECORD *)&pSVar8->input;
        } while (ppuVar14 != ppuVar27 + 0xe);
        *(uchar **)pSVar8 = *ppuVar14;
        puVar18 = *ppuVar27;
        psVar21 = param_1->s3;
        uVar13 = *(uint *)(puVar18 + 5);
        puVar12 = psVar21->read_sequence + 2;
        uVar29 = (uint)puVar12 & 3;
        *(uint *)(puVar12 + -uVar29) =
             *(uint *)(puVar12 + -uVar29) & -1 << (4 - uVar29) * 8 | uVar13 >> uVar29 * 8;
        puVar12 = psVar21->read_sequence + 5;
        uVar29 = (uint)puVar12 & 3;
        *(uint *)(puVar12 + -uVar29) =
             *(uint *)(puVar12 + -uVar29) & 0xffffffffU >> (uVar29 + 1) * 8 |
             uVar13 << (3 - uVar29) * 8;
        psVar21->read_sequence[6] = puVar18[9];
        psVar21->read_sequence[7] = puVar18[10];
        CRYPTO_free(*(void **)(iVar5 + 8));
        (*(code *)PTR_pitem_free_006a939c)(iVar5);
      }
      iVar5 = dtls1_process_record(param_1);
      if (iVar5 == 0) {
        pdVar6 = param_1->d1;
        goto LAB_004a22f8;
      }
      pdVar6 = param_1->d1;
      psVar21 = param_1->s3;
      iVar5 = (*(code *)PTR_pqueue_size_006a93b8)((pdVar6->processed_rcds).q);
      if (iVar5 < 100) {
        ppuVar27 = (uchar **)CRYPTO_malloc(0x3c,"d1_pkt.c",0xd8);
        iVar5 = (*(code *)PTR_pitem_new_006a93bc)((psVar21->rrec).seq_num,ppuVar27);
        if (ppuVar27 == (uchar **)0x0) {
          if (iVar5 != 0) {
            (*(code *)PTR_pitem_free_006a939c)(iVar5);
          }
        }
        else {
          if (iVar5 != 0) {
            psVar21 = param_1->s3;
            ppuVar14 = ppuVar27 + 6;
            puVar12 = (uchar *)param_1->packet_length;
            *ppuVar27 = param_1->packet;
            ppuVar27[1] = puVar12;
            puVar20 = (uchar *)(psVar21->rbuf).len;
            puVar18 = (uchar *)(psVar21->rbuf).offset;
            puVar12 = (uchar *)(psVar21->rbuf).left;
            ppuVar27[2] = (psVar21->rbuf).buf;
            ppuVar27[3] = puVar20;
            ppuVar27[4] = puVar18;
            ppuVar27[5] = puVar12;
            psVar21 = param_1->s3;
            pSVar8 = &psVar21->rrec;
            do {
              piVar3 = &pSVar8->type;
              puVar20 = (uchar *)pSVar8->length;
              puVar18 = (uchar *)pSVar8->off;
              puVar12 = pSVar8->data;
              pSVar8 = (SSL3_RECORD *)&pSVar8->input;
              *ppuVar14 = (uchar *)*piVar3;
              ppuVar14[1] = puVar20;
              ppuVar14[2] = puVar18;
              ppuVar14[3] = puVar12;
              puVar4 = PTR_pqueue_insert_006a93c0;
              ppuVar14 = ppuVar14 + 4;
            } while (pSVar8 != (SSL3_RECORD *)((psVar21->rrec).seq_num + 4));
            *ppuVar14 = *(uchar **)pSVar8;
            *(uchar ***)(iVar5 + 8) = ppuVar27;
            iVar9 = (*(code *)puVar4)((pdVar6->processed_rcds).q,iVar5);
            puVar4 = PTR_memset_006aab00;
            if (iVar9 != 0) {
              param_1->packet = (uchar *)0x0;
              param_1->packet_length = 0;
              (*(code *)puVar4)(&param_1->s3->rbuf,0,0x10);
              (*(code *)PTR_memset_006aab00)(&param_1->s3->rrec,0,0x24);
              iVar9 = ssl3_setup_buffers(param_1);
              if (iVar9 != 0) goto LAB_004a2618;
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf7,0x44,"d1_pkt.c",0x101);
            }
            CRYPTO_free(ppuVar27);
            (*(code *)PTR_pitem_free_006a939c)(iVar5);
            pdVar6 = param_1->d1;
            goto LAB_004a261c;
          }
          CRYPTO_free(ppuVar27);
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf7,0x44,"d1_pkt.c",0xdf);
        pdVar6 = param_1->d1;
      }
      else {
LAB_004a2618:
        pdVar6 = param_1->d1;
      }
LAB_004a261c:
      iVar5 = (*(code *)PTR_pqueue_peek_006a93c4)((pdVar6->unprocessed_rcds).q);
    }
  }
  puVar4 = PTR_pqueue_pop_006a93a0;
  pdVar6 = param_1->d1;
  uVar1 = pdVar6->r_epoch;
  (pdVar6->processed_rcds).epoch = uVar1;
  (pdVar6->unprocessed_rcds).epoch = uVar1 + 1;
  iVar5 = (*(code *)puVar4)((pdVar6->processed_rcds).q);
joined_r0x004a2308:
  if (iVar5 != 0) {
    psVar26 = param_1->s3;
    puVar12 = (psVar26->rbuf).buf;
    ppuVar27 = *(uchar ***)(iVar5 + 8);
    if (puVar12 != (uchar *)0x0) {
      CRYPTO_free(puVar12);
      psVar26 = param_1->s3;
    }
    puVar12 = ppuVar27[1];
    ppuVar14 = ppuVar27 + 6;
    param_1->packet = *ppuVar27;
    param_1->packet_length = (uint)puVar12;
    puVar20 = ppuVar27[3];
    puVar18 = ppuVar27[4];
    puVar12 = ppuVar27[5];
    (psVar26->rbuf).buf = ppuVar27[2];
    (psVar26->rbuf).len = (size_t)puVar20;
    (psVar26->rbuf).offset = (int)puVar18;
    (psVar26->rbuf).left = (int)puVar12;
    pSVar8 = &param_1->s3->rrec;
    do {
      puVar12 = *ppuVar14;
      puVar19 = ppuVar14[1];
      puVar20 = ppuVar14[2];
      puVar18 = ppuVar14[3];
      ppuVar14 = ppuVar14 + 4;
      pSVar8->type = (int)puVar12;
      pSVar8->length = (uint)puVar19;
      pSVar8->off = (uint)puVar20;
      pSVar8->data = puVar18;
      pSVar8 = (SSL3_RECORD *)&pSVar8->input;
    } while (ppuVar14 != ppuVar27 + 0xe);
    *(uchar **)pSVar8 = *ppuVar14;
    puVar18 = *ppuVar27;
    psVar26 = param_1->s3;
    uVar13 = *(uint *)(puVar18 + 5);
    puVar12 = psVar26->read_sequence + 2;
    uVar29 = (uint)puVar12 & 3;
    *(uint *)(puVar12 + -uVar29) =
         *(uint *)(puVar12 + -uVar29) & -1 << (4 - uVar29) * 8 | uVar13 >> uVar29 * 8;
    puVar12 = psVar26->read_sequence + 5;
    uVar29 = (uint)puVar12 & 3;
    *(uint *)(puVar12 + -uVar29) =
         *(uint *)(puVar12 + -uVar29) & 0xffffffffU >> (uVar29 + 1) * 8 | uVar13 << (3 - uVar29) * 8
    ;
    psVar26->read_sequence[6] = puVar18[9];
    psVar26->read_sequence[7] = puVar18[10];
    CRYPTO_free(*(void **)(iVar5 + 8));
    (*(code *)PTR_pitem_free_006a939c)(iVar5);
    return 1;
  }
  pbVar28 = (byte *)0x0;
  do {
    if (param_1->rstate != 0xf1) goto LAB_004a26d0;
LAB_004a2680:
    if (param_1->packet_length < 0xd) goto LAB_004a26d0;
    uVar29 = (psVar26->rrec).length;
    if (param_1->packet_length - 0xd < uVar29) goto LAB_004a27ac;
LAB_004a26a0:
    pdVar6 = param_1->d1;
    uVar29 = (psVar26->rrec).epoch;
    param_1->rstate = 0xf0;
    if (uVar29 == pdVar6->r_epoch) {
      pDVar17 = &pdVar6->bitmap;
      bVar2 = false;
    }
    else {
      if ((uVar29 != pdVar6->r_epoch + 1) ||
         (pDVar17 = &pdVar6->next_bitmap, 1 < (psVar26->rrec).type - 0x15U)) goto LAB_004a26c0;
      bVar2 = true;
    }
    if (((pdVar6->mtu == 0) || ((psVar26->rrec).type != 0x16)) || (*pbVar28 != 1)) {
      psVar21 = param_1->s3;
      uVar29 = (uint)psVar21->read_sequence[7] - (uint)pDVar17->max_seq_num[7];
      if ((uVar29 & 0x80) == 0) {
        uVar15 = ((uint)psVar21->read_sequence[6] - (uint)pDVar17->max_seq_num[6]) +
                 ((int)uVar29 >> 8);
        uVar22 = ((uint)psVar21->read_sequence[5] - (uint)pDVar17->max_seq_num[5]) +
                 ((int)uVar15 >> 8);
        uVar25 = ((uint)psVar21->read_sequence[4] - (uint)pDVar17->max_seq_num[4]) +
                 ((int)uVar22 >> 8);
        uVar24 = ((uint)psVar21->read_sequence[3] - (uint)pDVar17->max_seq_num[3]) +
                 ((int)uVar25 >> 8);
        uVar23 = ((uint)psVar21->read_sequence[2] - (uint)pDVar17->max_seq_num[2]) +
                 ((int)uVar24 >> 8);
        uVar16 = ((uint)psVar21->read_sequence[1] - (uint)pDVar17->max_seq_num[1]) +
                 ((int)uVar23 >> 8);
        uVar10 = ((uint)psVar21->read_sequence[0] - (uint)pDVar17->max_seq_num[0]) +
                 ((int)uVar16 >> 8);
        uVar13 = ((int)uVar10 >> 8) << 8;
        if (((uVar15 | uVar22 | uVar25 | uVar24 | uVar23 | uVar16 | uVar10) & 0xff) != 0)
        goto LAB_004a2c34;
LAB_004a2ad0:
        uVar13 = (uVar29 & 0xff) + uVar13;
      }
      else {
        uVar25 = ((uint)psVar21->read_sequence[6] - (uint)pDVar17->max_seq_num[6]) +
                 ((int)uVar29 >> 8);
        uVar16 = ((uint)psVar21->read_sequence[5] - (uint)pDVar17->max_seq_num[5]) +
                 ((int)uVar25 >> 8);
        uVar24 = ((uint)psVar21->read_sequence[4] - (uint)pDVar17->max_seq_num[4]) +
                 ((int)uVar16 >> 8);
        uVar23 = ((uint)psVar21->read_sequence[3] - (uint)pDVar17->max_seq_num[3]) +
                 ((int)uVar24 >> 8);
        uVar10 = ((uint)psVar21->read_sequence[2] - (uint)pDVar17->max_seq_num[2]) +
                 ((int)uVar23 >> 8);
        uVar22 = ((uint)psVar21->read_sequence[1] - (uint)pDVar17->max_seq_num[1]) +
                 ((int)uVar10 >> 8);
        uVar15 = ((uint)psVar21->read_sequence[0] - (uint)pDVar17->max_seq_num[0]) +
                 ((int)uVar22 >> 8);
        uVar13 = ((int)uVar15 >> 8) << 8;
        if ((~(uVar15 & uVar22 & uVar10 & uVar23 & uVar24 & uVar16 & uVar25) & 0xff) == 0)
        goto LAB_004a2ad0;
LAB_004a2c34:
        uVar13 = uVar13 | 0x80;
      }
      if (((int)uVar13 < 1) &&
         ((0x1f < (int)-uVar13 || ((pDVar17->map >> (-uVar13 & 0x1f) & 1) != 0))))
      goto LAB_004a26c0;
      uVar13 = *(uint *)psVar21->read_sequence;
      uVar11 = *(undefined4 *)(psVar21->read_sequence + 4);
      puVar12 = (psVar21->rrec).seq_num;
      uVar29 = (uint)puVar12 & 3;
      puVar12 = puVar12 + -uVar29;
      *(uint *)puVar12 = *(uint *)puVar12 & -1 << (4 - uVar29) * 8 | uVar13 >> uVar29 * 8;
      puVar12 = (psVar21->rrec).seq_num + 3;
      uVar29 = (uint)puVar12 & 3;
      *(uint *)(puVar12 + -uVar29) =
           *(uint *)(puVar12 + -uVar29) & 0xffffffffU >> (uVar29 + 1) * 8 |
           uVar13 << (3 - uVar29) * 8;
      *(undefined4 *)((psVar21->rrec).seq_num + 4) = uVar11;
      uVar29 = (psVar26->rrec).length;
    }
    else {
      uVar29 = (psVar26->rrec).length;
    }
  } while (uVar29 == 0);
  if (bVar2) {
    uVar29 = SSL_state(param_1);
    if ((((uVar29 & 0x3000) != 0) || (param_1->in_handshake != 0)) && (param_1->d1->mtu == 0)) {
      dtls1_buffer_record_isra_6(param_1,&(param_1->d1->unprocessed_rcds).q,(psVar26->rrec).seq_num)
      ;
      (psVar26->rrec).length = 0;
      goto LAB_004a26c4;
    }
  }
  else {
    iVar5 = dtls1_process_record(param_1);
    if (iVar5 != 0) {
      return 1;
    }
  }
LAB_004a26c0:
  (psVar26->rrec).length = 0;
LAB_004a26c4:
  do {
    param_1->packet_length = 0;
    if (param_1->rstate == 0xf1) goto LAB_004a2680;
LAB_004a26d0:
    uVar29 = ssl3_read_n(param_1,0xd,(param_1->s3->rbuf).len,0);
    if ((int)uVar29 < 1) {
      return uVar29;
    }
  } while (param_1->packet_length != 0xd);
  pbVar7 = param_1->packet;
  param_1->rstate = 0xf1;
  psVar21 = param_1->s3;
  pbVar28 = pbVar7 + 0xd;
  (psVar26->rrec).type = (uint)*pbVar7;
  uVar1 = *(ushort *)(pbVar7 + 1);
  (psVar26->rrec).epoch = (uint)*(ushort *)(pbVar7 + 3);
  uVar13 = *(uint *)(pbVar7 + 5);
  puVar12 = psVar21->read_sequence + 2;
  uVar29 = (uint)puVar12 & 3;
  *(uint *)(puVar12 + -uVar29) =
       *(uint *)(puVar12 + -uVar29) & -1 << (4 - uVar29) * 8 | uVar13 >> uVar29 * 8;
  puVar12 = psVar21->read_sequence + 5;
  uVar29 = (uint)puVar12 & 3;
  *(uint *)(puVar12 + -uVar29) =
       *(uint *)(puVar12 + -uVar29) & 0xffffffffU >> (uVar29 + 1) * 8 | uVar13 << (3 - uVar29) * 8;
  psVar21->read_sequence[6] = pbVar7[9];
  psVar21->read_sequence[7] = pbVar7[10];
  iVar5 = param_1->max_cert_list;
  uVar29 = (uint)*(ushort *)(pbVar7 + 0xb);
  uVar13 = param_1->version;
  (psVar26->rrec).length = uVar29;
  if (iVar5 == 0) {
    if (uVar1 != uVar13) goto LAB_004a26c0;
  }
  else if (((uVar1 ^ uVar13) & 0xff00) != 0) {
    (psVar26->rrec).length = 0;
    goto LAB_004a26c4;
  }
  if (0x4540 < uVar29) goto LAB_004a26c0;
  if (uVar29 <= param_1->packet_length - 0xd) goto LAB_004a26a0;
LAB_004a27ac:
  uVar13 = ssl3_read_n(param_1,uVar29,uVar29,1);
  if ((int)uVar13 < 1) {
    return uVar13;
  }
  if (uVar29 == uVar13) goto LAB_004a26a0;
  (psVar26->rrec).length = 0;
  goto LAB_004a26c4;
}

