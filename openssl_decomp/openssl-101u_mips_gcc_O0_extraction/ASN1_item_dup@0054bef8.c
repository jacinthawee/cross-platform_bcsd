
void * ASN1_item_dup(ASN1_ITEM *it,void *x)

{
  bool bVar1;
  ushort uVar2;
  uint3 uVar3;
  int iVar4;
  ASN1_ITEM *pAVar5;
  undefined *puVar6;
  ulong uVar7;
  undefined4 uVar8;
  ASN1_VALUE **ppAVar9;
  int *piVar10;
  void *pvVar11;
  ASN1_VALUE *pAVar12;
  undefined *puVar13;
  uchar **ppuVar14;
  int iVar15;
  int iVar16;
  ASN1_VALUE *pAVar17;
  ASN1_VALUE *pAVar18;
  byte *pbVar19;
  uchar **in;
  uchar *puVar20;
  ASN1_ITEM *unaff_s0;
  undefined *puVar21;
  int *unaff_s3;
  int *piVar22;
  int **unaff_s4;
  int *unaff_s5;
  int *unaff_s6;
  undefined *puVar23;
  undefined auStack_316 [10];
  int *piStack_30c;
  void *pvStack_304;
  ASN1_ITEM *pAStack_300;
  uchar *puStack_2fc;
  undefined *puStack_2f8;
  code *pcStack_2f4;
  uchar *puStack_2d0;
  int *piStack_2cc;
  void *pvStack_2c4;
  ASN1_ITEM *pAStack_2c0;
  undefined *puStack_2bc;
  undefined *puStack_2b8;
  code *pcStack_2b4;
  uchar *puStack_290;
  ASN1_ITEM *pAStack_28c;
  ASN1_VALUE *pAStack_288;
  code *pcStack_284;
  undefined *puStack_280;
  code *pcStack_27c;
  undefined *puStack_278;
  code *pcStack_274;
  undefined *puStack_250;
  ASN1_ITEM *pAStack_24c;
  void *pvStack_248;
  code *pcStack_244;
  undefined *puStack_240;
  ASN1_VALUE **ppAStack_23c;
  undefined *puStack_238;
  int iStack_234;
  int *piStack_230;
  code *pcStack_22c;
  ASN1_VALUE **ppAStack_208;
  code *pcStack_204;
  undefined *puStack_200;
  uchar **ppuStack_1fc;
  undefined *puStack_1f8;
  ASN1_VALUE **ppAStack_1f4;
  ASN1_ITEM *pAStack_1f0;
  int *piStack_1ec;
  int *piStack_1e8;
  undefined4 uStack_1e4;
  uchar *puStack_1bc;
  uchar *puStack_1b8;
  code *pcStack_1b4;
  undefined *puStack_1b0;
  ASN1_VALUE **ppAStack_1ac;
  ASN1_ITEM *pAStack_1a8;
  uint *puStack_1a4;
  char *pcStack_1a0;
  code *pcStack_19c;
  undefined *puStack_188;
  ASN1_VALUE *pAStack_17c;
  uchar *puStack_174;
  uchar *puStack_170;
  ASN1_ITEM *pAStack_16c;
  undefined *puStack_168;
  int *piStack_164;
  char *pcStack_160;
  code *pcStack_15c;
  undefined *puStack_148;
  void *pvStack_13c;
  int iStack_134;
  int iStack_130;
  ASN1_ITEM *pAStack_12c;
  ASN1_ITEM *pAStack_128;
  int *piStack_124;
  undefined *puStack_120;
  code *pcStack_11c;
  int iStack_f4;
  int iStack_f0;
  int iStack_ec;
  ASN1_ITEM *pAStack_e8;
  undefined *puStack_e4;
  int iStack_e0;
  int *piStack_dc;
  int **ppiStack_d8;
  code *pcStack_d4;
  int iStack_b0;
  int *piStack_ac;
  int *apiStack_98 [3];
  uint uStack_8c;
  int iStack_88;
  int iStack_84;
  uint auStack_80 [5];
  int iStack_6c;
  ASN1_ITEM *pAStack_68;
  undefined *puStack_64;
  ASN1_ITEM *local_1c;
  ASN1_ITEM *local_18;
  int local_14;
  
  puStack_e4 = PTR___stack_chk_guard_006a9ae8;
  local_1c = (ASN1_ITEM *)0x0;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (x == (void *)0x0) {
    pAVar5 = (ASN1_ITEM *)0x0;
  }
  else {
    iVar4 = ASN1_item_i2d((ASN1_VALUE *)x,(uchar **)&local_1c,it);
    if (local_1c == (ASN1_ITEM *)0x0) {
      x = (ASN1_ITEM **)0xbf;
      ERR_put_error(0xd,0xbf,0x41,"a_dup.c",0x6e);
      pAVar5 = (ASN1_ITEM *)0x0;
      unaff_s0 = it;
    }
    else {
      x = &local_18;
      local_18 = local_1c;
      pAVar5 = (ASN1_ITEM *)ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)x,iVar4,it);
      (*(code *)PTR_CRYPTO_free_006a6e88)(local_1c);
      unaff_s0 = pAVar5;
    }
  }
  if (local_14 == *(int *)puStack_e4) {
    return pAVar5;
  }
  iStack_e0 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar13 = PTR___stack_chk_guard_006a9ae8;
  puStack_64 = puStack_e4;
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAStack_68 = unaff_s0;
  pAVar5 = (ASN1_ITEM *)(*(code *)PTR_BUF_MEM_new_006a749c)();
  if (pAVar5 != (ASN1_ITEM *)0x0) {
    unaff_s4 = apiStack_98;
    unaff_s6 = &iStack_84;
    ERR_clear_error();
    iStack_b0 = 0;
    puVar23 = (undefined *)0x0;
    unaff_s5 = (int *)0x0;
    puVar21 = (undefined *)0x0;
LAB_0054c08c:
    unaff_s0 = pAVar5;
    if (&DAT_00000008 < unaff_s5) goto LAB_0054c0f0;
    while ((unaff_s3 = (int *)(puVar21 + 8 + -(int)puVar23), puVar23 <= puVar21 + 8 &&
           (iVar4 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(pAVar5), iVar4 != 0))) {
      iVar4 = (*(code *)PTR_BIO_read_006a74c0)(iStack_e0,puVar23 + pAVar5->utype,unaff_s3);
      if (iVar4 < 0) {
        if (puVar23 == puVar21) {
          piStack_124 = (int *)0x8e;
          iVar4 = 0xad;
          goto LAB_0054c284;
        }
      }
      else {
        puVar6 = puVar23 + iVar4;
        if ((iVar4 != 0) &&
           (bVar1 = puVar6 < puVar23, unaff_s5 = (int *)(puVar6 + -(int)puVar21), puVar23 = puVar6,
           bVar1)) {
          piStack_124 = (int *)&DAT_0000009b;
          iVar4 = 0xb2;
          goto LAB_0054c284;
        }
      }
LAB_0054c0f0:
      iVar4 = pAVar5->utype;
      while( true ) {
        puStack_1a4 = auStack_80;
        unaff_s3 = (int *)(puVar21 + iVar4);
        piStack_124 = &iStack_88;
        pcStack_1a0 = (char *)unaff_s6;
        apiStack_98[0] = unaff_s3;
        uStack_8c = ASN1_get_object((uchar **)unaff_s4,(long *)puStack_1a4,&iStack_88,unaff_s6,
                                    (long)unaff_s5);
        if ((uStack_8c & 0x80) != 0) {
          uVar7 = ERR_peek_error();
          puStack_e4 = puVar21;
          if ((uVar7 & 0xfff) != 0x9b) goto LAB_0054c298;
          ERR_clear_error();
        }
        unaff_s3 = (int *)((int)apiStack_98[0] - (int)unaff_s3);
        puVar21 = puVar21 + (int)unaff_s3;
        if ((uStack_8c & 1) == 0) {
          if ((iStack_b0 != 0) && (auStack_80[0] == 0)) {
            unaff_s5 = (int *)(puVar23 + -(int)puVar21);
            if ((iStack_88 != 0) || (iStack_b0 = iStack_b0 + -1, iStack_b0 != 0)) goto LAB_0054c08c;
            goto LAB_0054c324;
          }
          puVar6 = puVar21 + auStack_80[0];
          if (auStack_80[0] <= (uint)((int)puVar23 - (int)puVar21)) goto LAB_0054c220;
          unaff_s5 = (int *)(puVar6 + -(int)puVar23);
          if ((-1 < (int)unaff_s5) && (puVar23 <= puVar6)) {
            piStack_ac = (int *)&DAT_00004000;
            if (unaff_s5 != (int *)0x0) goto LAB_0054c1a0;
            goto LAB_0054c220;
          }
          piStack_124 = (int *)&DAT_0000009b;
          iVar4 = 0xe2;
          goto LAB_0054c284;
        }
        unaff_s5 = (int *)(puVar23 + -(int)puVar21);
        iStack_b0 = iStack_b0 + 1;
        if (unaff_s5 < &DAT_00000009) break;
        iVar4 = pAVar5->utype;
      }
    }
    piStack_124 = (int *)&DAT_00000041;
    iVar4 = 0xa8;
    goto LAB_0054c284;
  }
  piStack_124 = (int *)&DAT_00000041;
  pcStack_1a0 = "a_d2i_fp.c";
  puStack_1a4 = (uint *)&DAT_0000006b;
  ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",0x9e);
  puVar21 = (undefined *)0xffffffff;
LAB_0054c2ac:
  if (iStack_6c == *(int *)puVar13) {
    return puVar21;
  }
  pcStack_d4 = ASN1_d2i_fp;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_120 = PTR___stack_chk_guard_006a9ae8;
  iStack_ec = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAStack_e8 = unaff_s0;
  piStack_dc = unaff_s3;
  ppiStack_d8 = unaff_s4;
  uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  pAVar5 = (ASN1_ITEM *)(*(code *)PTR_BIO_new_006a6ea4)(uVar8);
  if (pAVar5 == (ASN1_ITEM *)0x0) {
    ppAStack_1ac = (ASN1_VALUE **)&DAT_00000007;
    pcStack_160 = "a_d2i_fp.c";
    piStack_164 = (int *)&DAT_0000006d;
    ERR_put_error(0xd,0x6d,7,"a_d2i_fp.c",0x4c);
    piVar10 = (int *)0x0;
  }
  else {
    ppAStack_1ac = (ASN1_VALUE **)0x0;
    (*(code *)PTR_BIO_ctrl_006a6e18)(pAVar5,0x6a);
    piStack_164 = &iStack_f4;
    iStack_f4 = 0;
    ppAVar9 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(pAVar5);
    if ((int)ppAVar9 < 0) {
      piVar10 = (int *)0x0;
      pcStack_160 = (char *)piStack_124;
    }
    else {
      piStack_164 = &iStack_f0;
      iStack_f0 = *(int *)(iStack_f4 + 4);
      piVar10 = (int *)(*(code *)puStack_1a4)(pcStack_1a0);
      ppAStack_1ac = ppAVar9;
      pcStack_160 = (char *)piStack_124;
    }
    if (iStack_f4 != 0) {
      (*(code *)PTR_BUF_MEM_free_006a7494)();
    }
    (*(code *)PTR_BIO_free_006a6e70)(pAVar5);
    unaff_s0 = pAVar5;
    piStack_124 = piVar10;
  }
  if (iStack_ec == *(int *)puStack_120) {
    return piVar10;
  }
  pcStack_11c = ASN1_d2i_bio;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_168 = PTR___stack_chk_guard_006a9ae8;
  piVar10 = &iStack_134;
  puStack_148 = &_gp;
  iStack_134 = 0;
  pAStack_12c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pAStack_128 = unaff_s0;
  ppAVar9 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(ppAStack_1ac,piVar10);
  if ((int)ppAVar9 < 0) {
    pvVar11 = (void *)0x0;
  }
  else {
    piVar10 = &iStack_130;
    iStack_130 = *(int *)(iStack_134 + 4);
    pvVar11 = (void *)(*(code *)piStack_164)(pcStack_160,piVar10);
    ppAStack_1ac = ppAVar9;
  }
  if (iStack_134 != 0) {
    pvStack_13c = pvVar11;
    (**(code **)(puStack_148 + -0x794c))();
    pvVar11 = pvStack_13c;
  }
  if (pAStack_12c == *(ASN1_ITEM **)puStack_168) {
    return pvVar11;
  }
  pcStack_15c = ASN1_item_d2i_bio;
  pAStack_1a8 = pAStack_12c;
  (**(code **)(puStack_148 + -0x5330))();
  puStack_200 = PTR___stack_chk_guard_006a9ae8;
  ppuStack_1fc = &puStack_174;
  puStack_188 = &_gp;
  puStack_174 = (uchar *)0x0;
  pAStack_16c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  ppAStack_23c = ppAStack_1ac;
  ppAVar9 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(piVar10);
  if ((int)ppAVar9 < 0) {
    pAVar12 = (ASN1_VALUE *)0x0;
  }
  else {
    ppuStack_1fc = &puStack_170;
    puStack_170 = *(uchar **)(puStack_174 + 4);
    pAVar12 = ASN1_item_d2i(ppAStack_1ac,ppuStack_1fc,(long)ppAVar9,pAStack_1a8);
    ppAStack_23c = ppAVar9;
  }
  if (puStack_174 != (uchar *)0x0) {
    pAStack_17c = pAVar12;
    (**(code **)(puStack_188 + -0x794c))();
    pAVar12 = pAStack_17c;
  }
  if (pAStack_16c == *(ASN1_ITEM **)puStack_200) {
    return pAVar12;
  }
  pcStack_19c = ASN1_item_d2i_fp;
  pAStack_1f0 = pAStack_16c;
  (**(code **)(puStack_188 + -0x5330))();
  puStack_2bc = PTR___stack_chk_guard_006a9ae8;
  puStack_1b0 = puStack_200;
  pcStack_1b4 = *(code **)PTR___stack_chk_guard_006a9ae8;
  uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar13 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar8);
  if (puVar13 == (undefined *)0x0) {
    iStack_234 = 7;
    in = (uchar **)0xce;
    ERR_put_error(0xd,0xce,7,"a_d2i_fp.c",0x85);
    ppuVar14 = (uchar **)0x0;
  }
  else {
    iStack_234 = 0;
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar13,0x6a,0,ppuStack_1fc);
    in = &puStack_1bc;
    puStack_1bc = (uchar *)0x0;
    iVar4 = asn1_d2i_read_bio_constprop_0(puVar13,in);
    if (iVar4 < 0) {
      ppuVar14 = (uchar **)0x0;
    }
    else {
      in = &puStack_1b8;
      puStack_1b8 = *(uchar **)(puStack_1bc + 4);
      ppuVar14 = (uchar **)ASN1_item_d2i(ppAStack_23c,in,iVar4,pAStack_1f0);
      iStack_234 = iVar4;
    }
    if (puStack_1bc != (uchar *)0x0) {
      (*(code *)PTR_BUF_MEM_free_006a7494)();
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar13);
    puStack_200 = puVar13;
    ppuStack_1fc = ppuVar14;
  }
  if (pcStack_1b4 == *(code **)puStack_2bc) {
    return ppuVar14;
  }
  uStack_1e4 = 0x54c854;
  pcStack_244 = pcStack_1b4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_238 = PTR___stack_chk_guard_006a9ae8;
  puStack_1f8 = puStack_2bc;
  pcStack_204 = *(code **)PTR___stack_chk_guard_006a9ae8;
  ppAStack_1f4 = ppAStack_23c;
  piStack_1ec = unaff_s5;
  piStack_1e8 = unaff_s6;
  uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar13 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar8);
  if (puVar13 == (undefined *)0x0) {
    iVar4 = 7;
    pcStack_27c = (code *)0x75;
    pvStack_248 = (void *)0x0;
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x49);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar13,0x6a,0,in);
    iVar15 = (*pcStack_244)(iStack_234,0);
    unaff_s6 = (int *)0x670000;
    ppAStack_23c = (ASN1_VALUE **)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar15,"a_i2d_fp.c",0x5a);
    if (ppAStack_23c == (ASN1_VALUE **)0x0) {
      iVar4 = 0x41;
      pcStack_27c = (code *)&DAT_00000074;
      pvStack_248 = (void *)0x0;
      ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    }
    else {
      ppAStack_208 = ppAStack_23c;
      (*pcStack_244)(iStack_234,&ppAStack_208);
      pcStack_244 = (code *)0x0;
      while( true ) {
        pcStack_27c = (code *)((int)ppAStack_23c + (int)pcStack_244);
        iVar4 = iVar15;
        iVar16 = (*(code *)PTR_BIO_write_006a6e14)(puVar13,pcStack_27c,iVar15);
        if (iVar15 == iVar16) break;
        if (iVar16 < 1) {
          pvStack_248 = (void *)0x0;
          goto LAB_0054c974;
        }
        pcStack_244 = pcStack_244 + iVar16;
        iVar15 = iVar15 - iVar16;
      }
      pvStack_248 = (void *)0x1;
LAB_0054c974:
      (*(code *)PTR_CRYPTO_free_006a6e88)(ppAStack_23c);
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar13);
    puStack_2bc = puVar13;
  }
  if (pcStack_204 == *(code **)puStack_238) {
    return pvStack_248;
  }
  pcStack_22c = ASN1_i2d_bio;
  pcStack_284 = pcStack_204;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_278 = PTR___stack_chk_guard_006a9ae8;
  pAStack_24c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_240 = puStack_2bc;
  piStack_230 = unaff_s6;
  pAStack_288 = (ASN1_VALUE *)(*pcStack_284)(iVar4,0);
  puVar13 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(pAStack_288,"a_i2d_fp.c",0x5a);
  if (puVar13 == (undefined *)0x0) {
    pAVar12 = (ASN1_VALUE *)&DAT_00000041;
    puVar21 = &DAT_00000074;
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    pAVar17 = (ASN1_VALUE *)0x0;
  }
  else {
    puStack_250 = puVar13;
    (*pcStack_284)(iVar4,&puStack_250);
    pcStack_284 = (code *)0x0;
    while( true ) {
      puVar21 = puVar13 + (int)pcStack_284;
      pAVar12 = pAStack_288;
      pAVar17 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(pcStack_27c,puVar21);
      if (pAStack_288 == pAVar17) break;
      if ((int)pAVar17 < 1) {
        pAVar17 = (ASN1_VALUE *)0x0;
        goto LAB_0054cb14;
      }
      pcStack_284 = pcStack_284 + (int)pAVar17;
      pAStack_288 = pAStack_288 + -(int)pAVar17;
    }
    pAVar17 = (ASN1_VALUE *)0x1;
LAB_0054cb14:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar13);
    pAStack_288 = pAVar17;
    puStack_2bc = puVar13;
  }
  if (pAStack_24c == *(ASN1_ITEM **)puStack_278) {
    return pAVar17;
  }
  pcStack_274 = ASN1_item_i2d_fp;
  pAStack_300 = pAStack_24c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_2b8 = PTR___stack_chk_guard_006a9ae8;
  pAStack_28c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_280 = puStack_2bc;
  uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar13 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar8);
  if (puVar13 == (undefined *)0x0) {
    pAVar12 = (ASN1_VALUE *)&DAT_00000007;
    puStack_2fc = (uchar *)0xc1;
    pvStack_304 = (void *)0x0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7b);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar13,0x6a,0,puVar21);
    puStack_290 = (uchar *)0x0;
    pAVar17 = (ASN1_VALUE *)ASN1_item_i2d(pAVar12,&puStack_290,pAStack_300);
    if (puStack_290 == (uchar *)0x0) {
      pAVar12 = (ASN1_VALUE *)&DAT_00000041;
      puStack_2fc = &DAT_000000c0;
      pvStack_304 = (void *)0x0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    }
    else {
      pAStack_300 = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_2fc = puStack_290 + (int)pAStack_300;
        pAVar12 = pAVar17;
        pAVar18 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(puVar13);
        if (pAVar17 == pAVar18) break;
        if ((int)pAVar18 < 1) {
          pvStack_304 = (void *)0x0;
          puStack_2fc = puStack_290;
          goto LAB_0054cc80;
        }
        pAStack_300 = (ASN1_ITEM *)(pAVar18 + (int)&pAStack_300->itype);
        pAVar17 = pAVar17 + -(int)pAVar18;
      }
      pvStack_304 = (void *)0x1;
LAB_0054cc80:
      (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_290);
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar13);
    puStack_2bc = puVar13;
  }
  if (pAStack_28c == *(ASN1_ITEM **)puStack_2b8) {
    return pvStack_304;
  }
  pcStack_2b4 = ASN1_item_i2d_bio;
  pAVar5 = pAStack_28c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_2f8 = PTR___stack_chk_guard_006a9ae8;
  puStack_2d0 = (uchar *)0x0;
  piStack_2cc = *(int **)PTR___stack_chk_guard_006a9ae8;
  pvStack_2c4 = pvStack_304;
  pAStack_2c0 = pAStack_300;
  iVar4 = ASN1_item_i2d(pAVar12,&puStack_2d0,pAVar5);
  if (puStack_2d0 == (uchar *)0x0) {
    puVar20 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    pvVar11 = (void *)0x0;
  }
  else {
    pAStack_300 = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar20 = puStack_2d0 + (int)pAStack_300;
      iVar15 = (*(code *)PTR_BIO_write_006a6e14)(puStack_2fc,puVar20,iVar4);
      if (iVar4 == iVar15) break;
      if (iVar15 < 1) {
        pvVar11 = (void *)0x0;
        puVar20 = puStack_2d0;
        goto LAB_0054cde0;
      }
      pAStack_300 = (ASN1_ITEM *)(&pAStack_300->itype + iVar15);
      iVar4 = iVar4 - iVar15;
    }
    pvVar11 = (void *)0x1;
LAB_0054cde0:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_2d0);
    pvStack_304 = pvVar11;
  }
  if (piStack_2cc == *(int **)puStack_2f8) {
    return pvVar11;
  }
  pcStack_2f4 = ASN1_ENUMERATED_set;
  piVar10 = piStack_2cc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar13 = PTR___stack_chk_guard_006a9ae8;
  piVar10[1] = 10;
  piStack_30c = *(int **)puVar13;
  if (*piVar10 < 5) {
    if (piVar10[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar21 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(5,"a_enum.c",0x51);
    piVar10[2] = (int)puVar21;
    if (puVar21 != (undefined *)0x0) {
      *puVar21 = 0;
      puVar21[1] = 0;
      puVar21[2] = 0;
      puVar21[3] = 0;
      puVar21[4] = 0;
      goto LAB_0054cf00;
    }
  }
  else {
LAB_0054cf00:
    puVar21 = (undefined *)piVar10[2];
    if (puVar21 != (undefined *)0x0) {
      if ((int)puVar20 < 0) {
        puVar20 = (uchar *)-(int)puVar20;
        piVar10[1] = 0x10a;
LAB_0054cf1c:
        auStack_316[2] = (char)puVar20;
        if ((int)puVar20 >> 8 == 0) {
          iVar4 = 1;
LAB_0054cff0:
          iVar15 = iVar4 + -1;
          *puVar21 = auStack_316[iVar4 + 1];
          if (iVar4 != 1) {
            iVar16 = iVar4 + -3;
            *(undefined *)(piVar10[2] + 1) = auStack_316[iVar4];
            if (iVar16 == -1) goto LAB_0054cf80;
            goto LAB_0054cf58;
          }
        }
        else {
          auStack_316[3] = (char)((uint)puVar20 >> 8);
          if ((int)puVar20 >> 0x10 == 0) {
            iVar4 = 2;
            goto LAB_0054cff0;
          }
          auStack_316[4] = (undefined)((uint)puVar20 >> 0x10);
          if ((int)puVar20 >> 0x18 == 0) {
            iVar4 = 3;
            goto LAB_0054cff0;
          }
          auStack_316[5] = (undefined)((uint)puVar20 >> 0x18);
          *puVar21 = auStack_316[5];
          iVar15 = 3;
          iVar16 = 1;
          *(undefined *)(piVar10[2] + 1) = auStack_316[4];
LAB_0054cf58:
          *(undefined *)(piVar10[2] + 2) = auStack_316[iVar16 + 2];
          if (iVar16 != 0) {
            *(char *)(piVar10[2] + 3) = (char)puVar20;
          }
        }
        iVar4 = iVar15 + 1;
      }
      else {
        iVar4 = 0;
        if (puVar20 != (uchar *)0x0) goto LAB_0054cf1c;
      }
LAB_0054cf80:
      pvVar11 = (void *)0x1;
      *piVar10 = iVar4;
      goto LAB_0054cf88;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x55);
  pvVar11 = (void *)0x0;
LAB_0054cf88:
  if (piStack_30c == *(int **)puVar13) {
    return pvVar11;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piStack_30c != (int *)0x0) {
    if (piStack_30c[1] == 0x10a) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
      if (piStack_30c[1] != 10) {
        return (void *)0xffffffff;
      }
    }
    iVar4 = *piStack_30c;
    if (4 < iVar4) {
      return (void *)0xffffffff;
    }
    pbVar19 = (byte *)piStack_30c[2];
    if (pbVar19 != (byte *)0x0) {
      if (iVar4 < 1) {
        pvVar11 = (void *)0x0;
      }
      else {
        pvVar11 = (void *)(uint)*pbVar19;
        if (iVar4 != 1) {
          uVar2 = CONCAT11(*pbVar19,pbVar19[1]);
          pvVar11 = (void *)(uint)uVar2;
          if (iVar4 != 2) {
            uVar3 = CONCAT21(uVar2,pbVar19[2]);
            pvVar11 = (void *)(uint)uVar3;
            if (iVar4 == 4) {
              pvVar11 = (void *)CONCAT31(uVar3,pbVar19[3]);
            }
          }
        }
      }
      if (!bVar1) {
        return pvVar11;
      }
      return (void *)-(int)pvVar11;
    }
  }
  return (void *)0x0;
  while( true ) {
    do {
      puStack_1a4 = (uint *)(puVar23 + pAVar5->utype);
      piStack_124 = piVar22;
      iVar4 = (*(code *)PTR_BIO_read_006a74c0)(iStack_e0);
      if (iVar4 < 1) {
        piStack_124 = (int *)0x8e;
        iVar4 = 0xf7;
        unaff_s3 = piVar22;
        goto LAB_0054c284;
      }
      unaff_s3 = (int *)((int)piVar22 - iVar4);
      puVar23 = puVar23 + iVar4;
      piVar22 = unaff_s3;
    } while (unaff_s3 != (int *)0x0);
    unaff_s5 = (int *)((int)unaff_s5 - (int)piVar10);
    piStack_ac = (int *)((int)piStack_ac << (piStack_ac < (int *)0x3fffffff));
    if (unaff_s5 == (int *)0x0) break;
LAB_0054c1a0:
    unaff_s3 = (int *)(uint)(piStack_ac < unaff_s5);
    piVar10 = piStack_ac;
    if (unaff_s3 == (int *)0x0) {
      piVar10 = unaff_s5;
    }
    iVar4 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(pAVar5,(char *)((int)piVar10 + (int)puVar23))
    ;
    piVar22 = piVar10;
    if (iVar4 == 0) {
      piStack_124 = (int *)&DAT_00000041;
      iVar4 = 0xef;
      goto LAB_0054c284;
    }
  }
  puVar6 = puVar21 + auStack_80[0];
LAB_0054c220:
  puVar21 = (undefined *)(uint)(puVar6 < puVar21);
  if (puVar21 != (undefined *)0x0) {
    piStack_124 = (int *)&DAT_0000009b;
    iVar4 = 0x106;
    goto LAB_0054c284;
  }
  puVar21 = puVar6;
  if (iStack_b0 == 0) goto LAB_0054c324;
  unaff_s5 = (int *)(puVar23 + -(int)puVar6);
  goto LAB_0054c08c;
LAB_0054c324:
  if ((int)puVar21 < 0) {
    piStack_124 = (int *)&DAT_0000009b;
    iVar4 = 0x112;
LAB_0054c284:
    pcStack_1a0 = "a_d2i_fp.c";
    puStack_1a4 = (uint *)&DAT_0000006b;
    ERR_put_error(0xd,0x6b,(int)piStack_124,"a_d2i_fp.c",iVar4);
    puStack_e4 = puVar21;
LAB_0054c298:
    (*(code *)PTR_BUF_MEM_free_006a7494)(pAVar5);
    puVar21 = (undefined *)0xffffffff;
  }
  else {
    *(ASN1_ITEM **)x = pAVar5;
    puStack_e4 = puVar21;
  }
  goto LAB_0054c2ac;
}

