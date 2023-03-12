
void * ASN1_item_dup(ASN1_ITEM *it,void *x)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  ASN1_ITEM *pAVar4;
  int iVar5;
  ASN1_ITEM *pAVar6;
  uchar *puVar7;
  ulong uVar8;
  ASN1_ITEM *pAVar9;
  undefined4 uVar10;
  ASN1_VALUE **ppAVar11;
  char *pcVar12;
  void *pvVar13;
  ASN1_VALUE *pAVar14;
  undefined *puVar15;
  uchar **ppuVar16;
  int iVar17;
  int iVar18;
  ASN1_VALUE *pAVar19;
  ASN1_VALUE *pAVar20;
  int *piVar21;
  byte *pbVar22;
  uchar **in;
  undefined *puVar23;
  ASN1_ITEM *unaff_s0;
  ASN1_ITEM *unaff_s2;
  uchar *unaff_s3;
  uchar **unaff_s5;
  int *unaff_s6;
  undefined auStack_30e [10];
  int *piStack_304;
  void *pvStack_2fc;
  ASN1_ITEM *pAStack_2f8;
  uchar *puStack_2f4;
  undefined *puStack_2f0;
  code *pcStack_2ec;
  uchar *puStack_2c8;
  int *piStack_2c4;
  void *pvStack_2bc;
  ASN1_ITEM *pAStack_2b8;
  undefined *puStack_2b4;
  undefined *puStack_2b0;
  code *pcStack_2ac;
  uchar *puStack_288;
  ASN1_ITEM *pAStack_284;
  ASN1_VALUE *pAStack_280;
  code *pcStack_27c;
  undefined *puStack_278;
  code *pcStack_274;
  undefined *puStack_270;
  code *pcStack_26c;
  undefined *puStack_248;
  ASN1_ITEM *pAStack_244;
  void *pvStack_240;
  code *pcStack_23c;
  undefined *puStack_238;
  ASN1_VALUE **ppAStack_234;
  undefined *puStack_230;
  int iStack_22c;
  int *piStack_228;
  code *pcStack_224;
  ASN1_VALUE **ppAStack_200;
  code *pcStack_1fc;
  undefined *puStack_1f8;
  uchar **ppuStack_1f4;
  undefined *puStack_1f0;
  ASN1_VALUE **ppAStack_1ec;
  ASN1_ITEM *pAStack_1e8;
  uchar **ppuStack_1e4;
  int *piStack_1e0;
  code *pcStack_1dc;
  uchar *puStack_1b4;
  uchar *puStack_1b0;
  code *pcStack_1ac;
  undefined *puStack_1a8;
  ASN1_VALUE **ppAStack_1a4;
  ASN1_ITEM *pAStack_1a0;
  ASN1_ITEM *pAStack_19c;
  char *pcStack_198;
  code *pcStack_194;
  undefined *puStack_180;
  ASN1_VALUE *pAStack_174;
  uchar *puStack_16c;
  uchar *puStack_168;
  ASN1_ITEM *pAStack_164;
  undefined *puStack_160;
  int *piStack_15c;
  char *pcStack_158;
  code *pcStack_154;
  undefined *puStack_140;
  void *pvStack_134;
  int iStack_12c;
  int iStack_128;
  ASN1_ITEM *pAStack_124;
  ASN1_ITEM *pAStack_120;
  char *pcStack_11c;
  undefined *puStack_118;
  code *pcStack_114;
  int iStack_ec;
  int iStack_e8;
  int iStack_e4;
  ASN1_ITEM *pAStack_e0;
  char *pcStack_dc;
  ASN1_ITEM *pAStack_d8;
  uchar *puStack_d4;
  int iStack_d0;
  code *pcStack_cc;
  int iStack_a8;
  uchar *apuStack_98 [3];
  uint uStack_8c;
  int iStack_88;
  int iStack_84;
  ASN1_ITEM AStack_80;
  undefined *puStack_64;
  uchar *local_1c;
  uchar *local_18;
  int local_14;
  
  pcStack_dc = PTR___stack_chk_guard_006aabf0;
  local_1c = (uchar *)0x0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (x == (void *)0x0) {
    pAVar6 = (ASN1_ITEM *)0x0;
  }
  else {
    iVar5 = ASN1_item_i2d((ASN1_VALUE *)x,&local_1c,it);
    if (local_1c == (uchar *)0x0) {
      x = (uchar **)0xbf;
      ERR_put_error(0xd,0xbf,0x41,"a_dup.c",0x68);
      pAVar6 = (ASN1_ITEM *)0x0;
      unaff_s0 = it;
    }
    else {
      x = &local_18;
      local_18 = local_1c;
      pAVar6 = (ASN1_ITEM *)ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)x,iVar5,it);
      (*(code *)PTR_CRYPTO_free_006a7f88)(local_1c);
      unaff_s0 = pAVar6;
    }
  }
  if (local_14 == *(int *)pcStack_dc) {
    return pAVar6;
  }
  iStack_d0 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar15 = PTR___stack_chk_guard_006aabf0;
  puStack_64 = pcStack_dc;
  AStack_80.size = *(long *)PTR___stack_chk_guard_006aabf0;
  AStack_80.sname = &unaff_s0->itype;
  puVar7 = (uchar *)(*(code *)PTR_BUF_MEM_new_006a859c)();
  if (puVar7 != (uchar *)0x0) {
    unaff_s5 = apuStack_98;
    unaff_s6 = &iStack_84;
    ERR_clear_error();
    unaff_s0 = (ASN1_ITEM *)0x0;
    iStack_a8 = 0;
    pcStack_dc = (char *)0x0;
    pAVar6 = (ASN1_ITEM *)0x0;
LAB_0054f334:
    pAVar4 = unaff_s0;
    pAVar9 = pAVar6;
    unaff_s3 = puVar7;
    if (&DAT_00000008 < pcStack_dc) goto LAB_0054f39c;
    while ((unaff_s0 <= &pAVar9->templates &&
           (iVar5 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(puVar7), iVar5 != 0))) {
      iVar5 = (*(code *)PTR_BIO_read_006a85bc)
                        (iStack_d0,&unaff_s0->itype + *(int *)(puVar7 + 4),
                         (int)&pAVar9->templates - (int)unaff_s0);
      pAVar4 = unaff_s0;
      if (iVar5 < 0) {
        if (unaff_s0 == pAVar9) {
          pcStack_11c = (char *)0x8e;
          iVar5 = 0xaf;
          goto LAB_0054f554;
        }
      }
      else {
        pAVar6 = (ASN1_ITEM *)(&unaff_s0->itype + iVar5);
        if (iVar5 != 0) {
          unaff_s0 = (ASN1_ITEM *)(uint)(pAVar6 < unaff_s0);
          pcStack_dc = (char *)((int)pAVar6 - (int)pAVar9);
          pAVar4 = pAVar6;
          if (unaff_s0 != (ASN1_ITEM *)0x0) {
            pcStack_11c = (char *)0x9b;
            iVar5 = 0xb6;
            goto LAB_0054f554;
          }
        }
      }
LAB_0054f39c:
      unaff_s0 = pAVar4;
      iVar5 = *(int *)(puVar7 + 4);
      while( true ) {
        pcVar12 = &pAVar9->itype + iVar5;
        pAStack_19c = &AStack_80;
        pcStack_11c = (char *)&iStack_88;
        pcStack_198 = (char *)unaff_s6;
        apuStack_98[0] = (uchar *)pcVar12;
        uStack_8c = ASN1_get_object(unaff_s5,(long *)&AStack_80,&iStack_88,unaff_s6,(long)pcStack_dc
                                   );
        if ((uStack_8c & 0x80) != 0) {
          uVar8 = ERR_peek_error();
          pcStack_dc = pcVar12;
          unaff_s2 = pAVar9;
          if ((uVar8 & 0xfff) != 0x9b) goto LAB_0054f568;
          ERR_clear_error();
        }
        pcStack_dc = (char *)(apuStack_98[0] + -(int)pcVar12);
        pAVar9 = (ASN1_ITEM *)(pcStack_dc + (int)&pAVar9->itype);
        if ((uStack_8c & 1) == 0) {
          if ((iStack_a8 != 0) && (AStack_80._0_4_ == 0)) {
            pcStack_dc = (char *)((int)unaff_s0 - (int)pAVar9);
            pAVar6 = pAVar9;
            if ((iStack_88 != 0) || (iStack_a8 = iStack_a8 + -1, iStack_a8 != 0)) goto LAB_0054f334;
            goto LAB_0054f43c;
          }
          if (AStack_80._0_4_ <= (uint)((int)unaff_s0 - (int)pAVar9)) goto LAB_0054f4cc;
          pcStack_dc = (char *)((int)(ASN1_ITEM *)(&pAVar9->itype + AStack_80._0_4_) - (int)unaff_s0
                               );
          if (((int)pcStack_dc < 0) || ((ASN1_ITEM *)(&pAVar9->itype + AStack_80._0_4_) < unaff_s0))
          {
            pcStack_11c = (char *)0x9b;
            iVar5 = 0xed;
          }
          else {
            iVar5 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(puVar7);
            if (iVar5 != 0) goto joined_r0x0054f494;
            pcStack_11c = &DAT_00000041;
            iVar5 = 0xf2;
          }
          goto LAB_0054f554;
        }
        pcStack_dc = (char *)((int)unaff_s0 - (int)pAVar9);
        iStack_a8 = iStack_a8 + 1;
        if (pcStack_dc < &DAT_00000009) break;
        iVar5 = *(int *)(puVar7 + 4);
      }
    }
    pcStack_11c = &DAT_00000041;
    iVar5 = 0xa9;
    goto LAB_0054f554;
  }
  pcStack_11c = &DAT_00000041;
  pcStack_198 = "a_d2i_fp.c";
  pAStack_19c = (ASN1_ITEM *)&DAT_0000006b;
  ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",0x9c);
  pAVar9 = (ASN1_ITEM *)0xffffffff;
LAB_0054f57c:
  if (AStack_80.size == *(int *)puVar15) {
    return pAVar9;
  }
  pcStack_cc = ASN1_d2i_fp;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_118 = PTR___stack_chk_guard_006aabf0;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pAStack_e0 = unaff_s0;
  pAStack_d8 = unaff_s2;
  puStack_d4 = unaff_s3;
  uVar10 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  pAVar6 = (ASN1_ITEM *)(*(code *)PTR_BIO_new_006a7fa4)(uVar10);
  if (pAVar6 == (ASN1_ITEM *)0x0) {
    ppAStack_1a4 = (ASN1_VALUE **)&DAT_00000007;
    pcStack_158 = "a_d2i_fp.c";
    piStack_15c = (int *)&DAT_0000006d;
    ERR_put_error(0xd,0x6d,7,"a_d2i_fp.c",0x4d);
    pcVar12 = (char *)0x0;
  }
  else {
    ppAStack_1a4 = (ASN1_VALUE **)0x0;
    (*(code *)PTR_BIO_ctrl_006a7f18)(pAVar6,0x6a);
    piStack_15c = &iStack_ec;
    iStack_ec = 0;
    ppAVar11 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(pAVar6);
    if ((int)ppAVar11 < 0) {
      pcVar12 = (char *)0x0;
      pcStack_158 = pcStack_11c;
    }
    else {
      piStack_15c = &iStack_e8;
      iStack_e8 = *(int *)(iStack_ec + 4);
      pcVar12 = (char *)(*(code *)pAStack_19c)(pcStack_198);
      ppAStack_1a4 = ppAVar11;
      pcStack_158 = pcStack_11c;
    }
    if (iStack_ec != 0) {
      (*(code *)PTR_BUF_MEM_free_006a8594)();
    }
    (*(code *)PTR_BIO_free_006a7f70)(pAVar6);
    unaff_s0 = pAVar6;
    pcStack_11c = pcVar12;
  }
  if (iStack_e4 == *(int *)puStack_118) {
    return pcVar12;
  }
  pcStack_114 = ASN1_d2i_bio;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_160 = PTR___stack_chk_guard_006aabf0;
  piVar21 = &iStack_12c;
  puStack_140 = &_gp;
  iStack_12c = 0;
  pAStack_124 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  pAStack_120 = unaff_s0;
  ppAVar11 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(ppAStack_1a4,piVar21);
  if ((int)ppAVar11 < 0) {
    pvVar13 = (void *)0x0;
  }
  else {
    piVar21 = &iStack_128;
    iStack_128 = *(int *)(iStack_12c + 4);
    pvVar13 = (void *)(*(code *)piStack_15c)(pcStack_158,piVar21);
    ppAStack_1a4 = ppAVar11;
  }
  if (iStack_12c != 0) {
    pvStack_134 = pvVar13;
    (**(code **)(puStack_140 + -0x794c))();
    pvVar13 = pvStack_134;
  }
  if (pAStack_124 == *(ASN1_ITEM **)puStack_160) {
    return pvVar13;
  }
  pcStack_154 = ASN1_item_d2i_bio;
  pAStack_1a0 = pAStack_124;
  (**(code **)(puStack_140 + -0x5328))();
  puStack_1f8 = PTR___stack_chk_guard_006aabf0;
  ppuStack_1f4 = &puStack_16c;
  puStack_180 = &_gp;
  puStack_16c = (uchar *)0x0;
  pAStack_164 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  ppAStack_234 = ppAStack_1a4;
  ppAVar11 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(piVar21);
  if ((int)ppAVar11 < 0) {
    pAVar14 = (ASN1_VALUE *)0x0;
  }
  else {
    ppuStack_1f4 = &puStack_168;
    puStack_168 = *(uchar **)(puStack_16c + 4);
    pAVar14 = ASN1_item_d2i(ppAStack_1a4,ppuStack_1f4,(long)ppAVar11,pAStack_1a0);
    ppAStack_234 = ppAVar11;
  }
  if (puStack_16c != (uchar *)0x0) {
    pAStack_174 = pAVar14;
    (**(code **)(puStack_180 + -0x794c))();
    pAVar14 = pAStack_174;
  }
  if (pAStack_164 == *(ASN1_ITEM **)puStack_1f8) {
    return pAVar14;
  }
  pcStack_194 = ASN1_item_d2i_fp;
  pAStack_1e8 = pAStack_164;
  (**(code **)(puStack_180 + -0x5328))();
  puStack_2b4 = PTR___stack_chk_guard_006aabf0;
  puStack_1a8 = puStack_1f8;
  pcStack_1ac = *(code **)PTR___stack_chk_guard_006aabf0;
  uVar10 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar15 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar10);
  if (puVar15 == (undefined *)0x0) {
    iStack_22c = 7;
    in = (uchar **)0xce;
    ERR_put_error(0xd,0xce,7,"a_d2i_fp.c",0x83);
    ppuVar16 = (uchar **)0x0;
  }
  else {
    iStack_22c = 0;
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar15,0x6a,0,ppuStack_1f4);
    in = &puStack_1b4;
    puStack_1b4 = (uchar *)0x0;
    iVar5 = asn1_d2i_read_bio_constprop_0(puVar15,in);
    if (iVar5 < 0) {
      ppuVar16 = (uchar **)0x0;
    }
    else {
      in = &puStack_1b0;
      puStack_1b0 = *(uchar **)(puStack_1b4 + 4);
      ppuVar16 = (uchar **)ASN1_item_d2i(ppAStack_234,in,iVar5,pAStack_1e8);
      iStack_22c = iVar5;
    }
    if (puStack_1b4 != (uchar *)0x0) {
      (*(code *)PTR_BUF_MEM_free_006a8594)();
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar15);
    puStack_1f8 = puVar15;
    ppuStack_1f4 = ppuVar16;
  }
  if (pcStack_1ac == *(code **)puStack_2b4) {
    return ppuVar16;
  }
  pcStack_1dc = ASN1_i2d_fp;
  pcStack_23c = pcStack_1ac;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_230 = PTR___stack_chk_guard_006aabf0;
  puStack_1f0 = puStack_2b4;
  pcStack_1fc = *(code **)PTR___stack_chk_guard_006aabf0;
  ppAStack_1ec = ppAStack_234;
  ppuStack_1e4 = unaff_s5;
  piStack_1e0 = unaff_s6;
  uVar10 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar15 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar10);
  if (puVar15 == (undefined *)0x0) {
    iVar5 = 7;
    pcStack_274 = (code *)0x75;
    pvStack_240 = (void *)0x0;
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x4a);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar15,0x6a,0,in);
    iVar17 = (*pcStack_23c)(iStack_22c,0);
    unaff_s6 = (int *)0x670000;
    ppAStack_234 = (ASN1_VALUE **)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar17,"a_i2d_fp.c",0x5b);
    if (ppAStack_234 == (ASN1_VALUE **)0x0) {
      iVar5 = 0x41;
      pcStack_274 = (code *)&DAT_00000074;
      pvStack_240 = (void *)0x0;
      ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5e);
    }
    else {
      ppAStack_200 = ppAStack_234;
      (*pcStack_23c)(iStack_22c,&ppAStack_200);
      pcStack_23c = (code *)0x0;
      while( true ) {
        pcStack_274 = (code *)((int)ppAStack_234 + (int)pcStack_23c);
        iVar5 = iVar17;
        iVar18 = (*(code *)PTR_BIO_write_006a7f14)(puVar15,pcStack_274,iVar17);
        if (iVar17 == iVar18) break;
        if (iVar18 < 1) {
          pvStack_240 = (void *)0x0;
          goto LAB_0054fbe4;
        }
        pcStack_23c = pcStack_23c + iVar18;
        iVar17 = iVar17 - iVar18;
      }
      pvStack_240 = (void *)0x1;
LAB_0054fbe4:
      (*(code *)PTR_CRYPTO_free_006a7f88)(ppAStack_234);
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar15);
    puStack_2b4 = puVar15;
  }
  if (pcStack_1fc == *(code **)puStack_230) {
    return pvStack_240;
  }
  pcStack_224 = ASN1_i2d_bio;
  pcStack_27c = pcStack_1fc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_270 = PTR___stack_chk_guard_006aabf0;
  pAStack_244 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  puStack_238 = puStack_2b4;
  piStack_228 = unaff_s6;
  pAStack_280 = (ASN1_VALUE *)(*pcStack_27c)(iVar5,0);
  puVar15 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(pAStack_280,"a_i2d_fp.c",0x5b);
  if (puVar15 == (undefined *)0x0) {
    pAVar14 = (ASN1_VALUE *)&DAT_00000041;
    puVar23 = &DAT_00000074;
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5e);
    pAVar19 = (ASN1_VALUE *)0x0;
  }
  else {
    puStack_248 = puVar15;
    (*pcStack_27c)(iVar5,&puStack_248);
    pcStack_27c = (code *)0x0;
    while( true ) {
      puVar23 = puVar15 + (int)pcStack_27c;
      pAVar14 = pAStack_280;
      pAVar19 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a7f14)(pcStack_274,puVar23);
      if (pAStack_280 == pAVar19) break;
      if ((int)pAVar19 < 1) {
        pAVar19 = (ASN1_VALUE *)0x0;
        goto LAB_0054fd84;
      }
      pcStack_27c = pcStack_27c + (int)pAVar19;
      pAStack_280 = pAStack_280 + -(int)pAVar19;
    }
    pAVar19 = (ASN1_VALUE *)0x1;
LAB_0054fd84:
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar15);
    pAStack_280 = pAVar19;
    puStack_2b4 = puVar15;
  }
  if (pAStack_244 == *(ASN1_ITEM **)puStack_270) {
    return pAVar19;
  }
  pcStack_26c = ASN1_item_i2d_fp;
  pAStack_2f8 = pAStack_244;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_2b0 = PTR___stack_chk_guard_006aabf0;
  pAStack_284 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  puStack_278 = puStack_2b4;
  uVar10 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar15 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar10);
  if (puVar15 == (undefined *)0x0) {
    pAVar14 = (ASN1_VALUE *)&DAT_00000007;
    puStack_2f4 = (uchar *)0xc1;
    pvStack_2fc = (void *)0x0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7f);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar15,0x6a,0,puVar23);
    puStack_288 = (uchar *)0x0;
    pAVar19 = (ASN1_VALUE *)ASN1_item_i2d(pAVar14,&puStack_288,pAStack_2f8);
    if (puStack_288 == (uchar *)0x0) {
      pAVar14 = (ASN1_VALUE *)&DAT_00000041;
      puStack_2f4 = &DAT_000000c0;
      pvStack_2fc = (void *)0x0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x91);
    }
    else {
      pAStack_2f8 = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_2f4 = puStack_288 + (int)pAStack_2f8;
        pAVar14 = pAVar19;
        pAVar20 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a7f14)(puVar15);
        if (pAVar19 == pAVar20) break;
        if ((int)pAVar20 < 1) {
          pvStack_2fc = (void *)0x0;
          puStack_2f4 = puStack_288;
          goto LAB_0054fef0;
        }
        pAStack_2f8 = (ASN1_ITEM *)(pAVar20 + (int)&pAStack_2f8->itype);
        pAVar19 = pAVar19 + -(int)pAVar20;
      }
      pvStack_2fc = (void *)0x1;
LAB_0054fef0:
      (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_288);
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar15);
    puStack_2b4 = puVar15;
  }
  if (pAStack_284 == *(ASN1_ITEM **)puStack_2b0) {
    return pvStack_2fc;
  }
  pcStack_2ac = ASN1_item_i2d_bio;
  pAVar6 = pAStack_284;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_2f0 = PTR___stack_chk_guard_006aabf0;
  puStack_2c8 = (uchar *)0x0;
  piStack_2c4 = *(int **)PTR___stack_chk_guard_006aabf0;
  pvStack_2bc = pvStack_2fc;
  pAStack_2b8 = pAStack_2f8;
  iVar5 = ASN1_item_i2d(pAVar14,&puStack_2c8,pAVar6);
  if (puStack_2c8 == (uchar *)0x0) {
    puVar7 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x91);
    pvVar13 = (void *)0x0;
  }
  else {
    pAStack_2f8 = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar7 = puStack_2c8 + (int)pAStack_2f8;
      iVar17 = (*(code *)PTR_BIO_write_006a7f14)(puStack_2f4,puVar7,iVar5);
      if (iVar5 == iVar17) break;
      if (iVar17 < 1) {
        pvVar13 = (void *)0x0;
        puVar7 = puStack_2c8;
        goto LAB_00550050;
      }
      pAStack_2f8 = (ASN1_ITEM *)(&pAStack_2f8->itype + iVar17);
      iVar5 = iVar5 - iVar17;
    }
    pvVar13 = (void *)0x1;
LAB_00550050:
    (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_2c8);
    pvStack_2fc = pvVar13;
  }
  if (piStack_2c4 == *(int **)puStack_2f0) {
    return pvVar13;
  }
  pcStack_2ec = ASN1_ENUMERATED_set;
  piVar21 = piStack_2c4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar15 = PTR___stack_chk_guard_006aabf0;
  piVar21[1] = 10;
  piStack_304 = *(int **)puVar15;
  if (*piVar21 < 5) {
    if (piVar21[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    puVar23 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(5,"a_enum.c",0x51);
    piVar21[2] = (int)puVar23;
    if (puVar23 != (undefined *)0x0) {
      *puVar23 = 0;
      puVar23[1] = 0;
      puVar23[2] = 0;
      puVar23[3] = 0;
      puVar23[4] = 0;
      goto LAB_00550170;
    }
  }
  else {
LAB_00550170:
    puVar23 = (undefined *)piVar21[2];
    if (puVar23 != (undefined *)0x0) {
      if ((int)puVar7 < 0) {
        puVar7 = (uchar *)-(int)puVar7;
        piVar21[1] = 0x10a;
LAB_0055018c:
        auStack_30e[2] = (char)puVar7;
        if ((int)puVar7 >> 8 == 0) {
          iVar5 = 1;
LAB_00550260:
          iVar17 = iVar5 + -1;
          *puVar23 = auStack_30e[iVar5 + 1];
          if (iVar5 != 1) {
            iVar18 = iVar5 + -3;
            *(undefined *)(piVar21[2] + 1) = auStack_30e[iVar5];
            if (iVar18 == -1) goto LAB_005501f0;
            goto LAB_005501c8;
          }
        }
        else {
          auStack_30e[3] = (char)((uint)puVar7 >> 8);
          if ((int)puVar7 >> 0x10 == 0) {
            iVar5 = 2;
            goto LAB_00550260;
          }
          auStack_30e[4] = (undefined)((uint)puVar7 >> 0x10);
          if ((int)puVar7 >> 0x18 == 0) {
            iVar5 = 3;
            goto LAB_00550260;
          }
          auStack_30e[5] = (undefined)((uint)puVar7 >> 0x18);
          *puVar23 = auStack_30e[5];
          iVar17 = 3;
          iVar18 = 1;
          *(undefined *)(piVar21[2] + 1) = auStack_30e[4];
LAB_005501c8:
          *(undefined *)(piVar21[2] + 2) = auStack_30e[iVar18 + 2];
          if (iVar18 != 0) {
            *(char *)(piVar21[2] + 3) = (char)puVar7;
          }
        }
        iVar5 = iVar17 + 1;
      }
      else {
        iVar5 = 0;
        if (puVar7 != (uchar *)0x0) goto LAB_0055018c;
      }
LAB_005501f0:
      pvVar13 = (void *)0x1;
      *piVar21 = iVar5;
      goto LAB_005501f8;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x56);
  pvVar13 = (void *)0x0;
LAB_005501f8:
  if (piStack_304 == *(int **)puVar15) {
    return pvVar13;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (piStack_304 != (int *)0x0) {
    if (piStack_304[1] == 0x10a) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (piStack_304[1] != 10) {
        return (void *)0xffffffff;
      }
    }
    iVar5 = *piStack_304;
    if (4 < iVar5) {
      return (void *)0xffffffff;
    }
    pbVar22 = (byte *)piStack_304[2];
    if (pbVar22 != (byte *)0x0) {
      if (iVar5 < 1) {
        pvVar13 = (void *)0x0;
      }
      else {
        pvVar13 = (void *)(uint)*pbVar22;
        if (iVar5 != 1) {
          uVar1 = CONCAT11(*pbVar22,pbVar22[1]);
          pvVar13 = (void *)(uint)uVar1;
          if (iVar5 != 2) {
            uVar2 = CONCAT21(uVar1,pbVar22[2]);
            pvVar13 = (void *)(uint)uVar2;
            if (iVar5 == 4) {
              pvVar13 = (void *)CONCAT31(uVar2,pbVar22[3]);
            }
          }
        }
      }
      if (!bVar3) {
        return pvVar13;
      }
      return (void *)-(int)pvVar13;
    }
  }
  return (void *)0x0;
joined_r0x0054f494:
  if (pcStack_dc == (char *)0x0) goto LAB_0054f4cc;
  pcStack_11c = pcStack_dc;
  iVar5 = (*(code *)PTR_BIO_read_006a85bc)(iStack_d0,&unaff_s0->itype + *(int *)(puVar7 + 4));
  if (iVar5 < 1) {
    pcStack_11c = (char *)0x8e;
    iVar5 = 0xfb;
    goto LAB_0054f554;
  }
  pcStack_dc = pcStack_dc + -iVar5;
  unaff_s0 = (ASN1_ITEM *)(&unaff_s0->itype + iVar5);
  goto joined_r0x0054f494;
LAB_0054f4cc:
  pAVar6 = (ASN1_ITEM *)(&pAVar9->itype + AStack_80._0_4_);
  pAVar9 = (ASN1_ITEM *)(uint)(pAVar6 < pAVar9);
  if (pAVar9 != (ASN1_ITEM *)0x0) {
    pcStack_11c = (char *)0x9b;
    iVar5 = 0x106;
    goto LAB_0054f554;
  }
  pAVar9 = pAVar6;
  if (iStack_a8 == 0) goto LAB_0054f43c;
  pcStack_dc = (char *)((int)unaff_s0 - (int)pAVar6);
  goto LAB_0054f334;
LAB_0054f43c:
  pcStack_198 = "r";
  if ((int)pAVar9 < 0) {
    pcStack_11c = (char *)0x9b;
    iVar5 = 0x115;
LAB_0054f554:
    pcStack_198 = "a_d2i_fp.c";
    pAStack_19c = (ASN1_ITEM *)&DAT_0000006b;
    ERR_put_error(0xd,0x6b,(int)pcStack_11c,"a_d2i_fp.c",iVar5);
    unaff_s2 = pAVar9;
LAB_0054f568:
    (*(code *)PTR_BUF_MEM_free_006a8594)(puVar7);
    pAVar9 = (ASN1_ITEM *)0xffffffff;
  }
  else {
    *(uchar **)x = puVar7;
    pAStack_19c = pAVar9;
    unaff_s2 = pAVar9;
  }
  goto LAB_0054f57c;
}

