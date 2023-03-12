
X509_ALGOR * X509_ALGOR_dup(X509_ALGOR *xn)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  int iVar4;
  X509_ALGOR *pXVar5;
  ASN1_OBJECT *pAVar6;
  char **ppcVar7;
  ulong uVar8;
  undefined4 uVar9;
  ASN1_VALUE **ppAVar10;
  X509_ALGOR *pXVar11;
  undefined *puVar12;
  int iVar13;
  int iVar14;
  ASN1_VALUE *pAVar15;
  ASN1_VALUE *pAVar16;
  ASN1_ITEM *it;
  int *piVar17;
  byte *pbVar18;
  uchar **in;
  undefined *puVar19;
  uchar *puVar20;
  ASN1_VALUE *val;
  X509_ALGOR *unaff_s0;
  X509_ALGOR *pXVar21;
  X509_ALGOR *unaff_s2;
  ASN1_OBJECT *unaff_s3;
  X509_ALGOR **unaff_s5;
  ASN1_TYPE **unaff_s6;
  undefined auStack_30e [10];
  int *piStack_304;
  X509_ALGOR *pXStack_2fc;
  ASN1_ITEM *pAStack_2f8;
  uchar *puStack_2f4;
  undefined *puStack_2f0;
  code *pcStack_2ec;
  uchar *puStack_2c8;
  int *piStack_2c4;
  X509_ALGOR *pXStack_2bc;
  ASN1_ITEM *pAStack_2b8;
  undefined *puStack_2b4;
  undefined *puStack_2b0;
  code *pcStack_2ac;
  uchar *puStack_288;
  ASN1_ITEM *pAStack_284;
  X509_ALGOR *pXStack_280;
  code *pcStack_27c;
  undefined *puStack_278;
  code *pcStack_274;
  undefined *puStack_270;
  code *pcStack_26c;
  undefined *puStack_248;
  ASN1_ITEM *pAStack_244;
  X509_ALGOR *pXStack_240;
  code *pcStack_23c;
  undefined *puStack_238;
  ASN1_VALUE **ppAStack_234;
  undefined *puStack_230;
  int iStack_22c;
  ASN1_TYPE **ppAStack_228;
  code *pcStack_224;
  ASN1_VALUE **ppAStack_200;
  code *pcStack_1fc;
  undefined *puStack_1f8;
  X509_ALGOR *pXStack_1f4;
  undefined *puStack_1f0;
  ASN1_VALUE **ppAStack_1ec;
  ASN1_ITEM *pAStack_1e8;
  X509_ALGOR **ppXStack_1e4;
  ASN1_TYPE **ppAStack_1e0;
  code *pcStack_1dc;
  uchar *puStack_1b4;
  uchar *puStack_1b0;
  code *pcStack_1ac;
  undefined *puStack_1a8;
  ASN1_VALUE **ppAStack_1a4;
  ASN1_ITEM *pAStack_1a0;
  X509_ALGOR *pXStack_19c;
  char *pcStack_198;
  code *pcStack_194;
  undefined *puStack_180;
  X509_ALGOR *pXStack_174;
  undefined auStack_16c [8];
  ASN1_ITEM *pAStack_164;
  undefined *puStack_160;
  int *piStack_15c;
  char *pcStack_158;
  code *pcStack_154;
  undefined *puStack_140;
  X509_ALGOR *pXStack_134;
  int iStack_12c;
  int iStack_128;
  ASN1_ITEM *pAStack_124;
  X509_ALGOR *pXStack_120;
  X509_ALGOR *pXStack_11c;
  undefined *puStack_118;
  code *pcStack_114;
  int iStack_ec;
  int iStack_e8;
  int iStack_e4;
  X509_ALGOR *pXStack_e0;
  X509_ALGOR *pXStack_dc;
  X509_ALGOR *pXStack_d8;
  ASN1_OBJECT *pAStack_d4;
  ASN1_TYPE *pAStack_d0;
  code *pcStack_cc;
  int iStack_a8;
  X509_ALGOR *apXStack_98 [3];
  uint uStack_8c;
  X509_ALGOR XStack_88;
  X509_ALGOR aXStack_80 [2];
  int iStack_6c;
  X509_ALGOR *pXStack_68;
  undefined *puStack_64;
  ASN1_OBJECT *pAStack_1c;
  X509_ALGOR XStack_18;
  
  pXStack_dc = (X509_ALGOR *)PTR___stack_chk_guard_006aabf0;
  pAStack_1c = (ASN1_OBJECT *)0x0;
  XStack_18.parameter = *(ASN1_TYPE **)PTR___stack_chk_guard_006aabf0;
  if (xn == (X509_ALGOR *)0x0) {
    pXVar5 = (X509_ALGOR *)0x0;
  }
  else {
    iVar4 = ASN1_item_i2d((ASN1_VALUE *)xn,(uchar **)&pAStack_1c,(ASN1_ITEM *)X509_ALGOR_it);
    if (pAStack_1c == (ASN1_OBJECT *)0x0) {
      xn = (X509_ALGOR *)0xbf;
      ERR_put_error(0xd,0xbf,0x41,"a_dup.c",0x68);
      pXVar5 = (X509_ALGOR *)0x0;
      unaff_s0 = (X509_ALGOR *)X509_ALGOR_it;
    }
    else {
      xn = &XStack_18;
      XStack_18.algorithm = pAStack_1c;
      pXVar5 = (X509_ALGOR *)
               ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)xn,iVar4,(ASN1_ITEM *)X509_ALGOR_it);
      (*(code *)PTR_CRYPTO_free_006a7f88)(pAStack_1c);
      unaff_s0 = pXVar5;
    }
  }
  if (XStack_18.parameter == *(ASN1_TYPE **)pXStack_dc) {
    return pXVar5;
  }
  pAStack_d0 = XStack_18.parameter;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar12 = PTR___stack_chk_guard_006aabf0;
  puStack_64 = (undefined *)pXStack_dc;
  iStack_6c = *(int *)PTR___stack_chk_guard_006aabf0;
  pXStack_68 = unaff_s0;
  pAVar6 = (ASN1_OBJECT *)(*(code *)PTR_BUF_MEM_new_006a859c)();
  if (pAVar6 != (ASN1_OBJECT *)0x0) {
    unaff_s5 = apXStack_98;
    unaff_s6 = &XStack_88.parameter;
    ERR_clear_error();
    unaff_s0 = (X509_ALGOR *)0x0;
    iStack_a8 = 0;
    pXStack_dc = (X509_ALGOR *)0x0;
    pXVar5 = (X509_ALGOR *)0x0;
LAB_0054f334:
    pXVar11 = unaff_s0;
    pXVar21 = pXVar5;
    unaff_s3 = pAVar6;
    if ((X509_ALGOR *)&DAT_00000008 < pXStack_dc) goto LAB_0054f39c;
    while ((unaff_s0 <= pXVar21 + 1 &&
           (iVar4 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(pAVar6), iVar4 != 0))) {
      iVar4 = (*(code *)PTR_BIO_read_006a85bc)
                        (pAStack_d0,(undefined *)((int)&unaff_s0->algorithm + (int)pAVar6->ln),
                         (int)(pXVar21 + 1) - (int)unaff_s0);
      pXVar11 = unaff_s0;
      if (iVar4 < 0) {
        if (unaff_s0 == pXVar21) {
          pXStack_11c = (X509_ALGOR *)0x8e;
          iVar4 = 0xaf;
          goto LAB_0054f554;
        }
      }
      else {
        pXVar5 = (X509_ALGOR *)((int)&unaff_s0->algorithm + iVar4);
        if (iVar4 != 0) {
          unaff_s0 = (X509_ALGOR *)(uint)(pXVar5 < unaff_s0);
          pXStack_dc = (X509_ALGOR *)((int)pXVar5 - (int)pXVar21);
          pXVar11 = pXVar5;
          if (unaff_s0 != (X509_ALGOR *)0x0) {
            pXStack_11c = (X509_ALGOR *)0x9b;
            iVar4 = 0xb6;
            goto LAB_0054f554;
          }
        }
      }
LAB_0054f39c:
      unaff_s0 = pXVar11;
      ppcVar7 = pAVar6->ln;
      while( true ) {
        pXVar5 = (X509_ALGOR *)((int)&pXVar21->algorithm + (int)ppcVar7);
        pXStack_19c = aXStack_80;
        pXStack_11c = &XStack_88;
        pcStack_198 = (char *)unaff_s6;
        apXStack_98[0] = pXVar5;
        uStack_8c = ASN1_get_object((uchar **)unaff_s5,(long *)aXStack_80,(int *)&XStack_88,
                                    (int *)unaff_s6,(long)pXStack_dc);
        if ((uStack_8c & 0x80) != 0) {
          uVar8 = ERR_peek_error();
          pXStack_dc = pXVar5;
          unaff_s2 = pXVar21;
          if ((uVar8 & 0xfff) != 0x9b) goto LAB_0054f568;
          ERR_clear_error();
        }
        pXStack_dc = (X509_ALGOR *)((int)apXStack_98[0] - (int)pXVar5);
        pXVar21 = (X509_ALGOR *)((int)pXVar21 + (int)pXStack_dc);
        if ((uStack_8c & 1) == 0) {
          if ((iStack_a8 != 0) && (aXStack_80[0].algorithm == (ASN1_OBJECT *)0x0)) {
            pXStack_dc = (X509_ALGOR *)((int)unaff_s0 - (int)pXVar21);
            pXVar5 = pXVar21;
            if ((XStack_88.algorithm != (ASN1_OBJECT *)0x0) ||
               (iStack_a8 = iStack_a8 + -1, iStack_a8 != 0)) goto LAB_0054f334;
            goto LAB_0054f43c;
          }
          if (aXStack_80[0].algorithm <= (ASN1_OBJECT *)((int)unaff_s0 - (int)pXVar21))
          goto LAB_0054f4cc;
          pXStack_dc = (X509_ALGOR *)
                       ((int)(X509_ALGOR *)((int)aXStack_80[0].algorithm + (int)pXVar21) -
                       (int)unaff_s0);
          if (((int)pXStack_dc < 0) ||
             ((X509_ALGOR *)((int)aXStack_80[0].algorithm + (int)pXVar21) < unaff_s0)) {
            pXStack_11c = (X509_ALGOR *)0x9b;
            iVar4 = 0xed;
          }
          else {
            iVar4 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(pAVar6);
            if (iVar4 != 0) goto joined_r0x0054f494;
            pXStack_11c = (X509_ALGOR *)&DAT_00000041;
            iVar4 = 0xf2;
          }
          goto LAB_0054f554;
        }
        pXStack_dc = (X509_ALGOR *)((int)unaff_s0 - (int)pXVar21);
        iStack_a8 = iStack_a8 + 1;
        if (pXStack_dc < (X509_ALGOR *)&DAT_00000009) break;
        ppcVar7 = pAVar6->ln;
      }
    }
    pXStack_11c = (X509_ALGOR *)&DAT_00000041;
    iVar4 = 0xa9;
    goto LAB_0054f554;
  }
  pXStack_11c = (X509_ALGOR *)&DAT_00000041;
  pcStack_198 = "a_d2i_fp.c";
  pXStack_19c = (X509_ALGOR *)&DAT_0000006b;
  ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",0x9c);
  pXVar21 = (X509_ALGOR *)0xffffffff;
LAB_0054f57c:
  if (iStack_6c == *(int *)puVar12) {
    return pXVar21;
  }
  pcStack_cc = ASN1_d2i_fp;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_118 = PTR___stack_chk_guard_006aabf0;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pXStack_e0 = unaff_s0;
  pXStack_d8 = unaff_s2;
  pAStack_d4 = unaff_s3;
  uVar9 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  pXVar5 = (X509_ALGOR *)(*(code *)PTR_BIO_new_006a7fa4)(uVar9);
  if (pXVar5 == (X509_ALGOR *)0x0) {
    ppAStack_1a4 = (ASN1_VALUE **)&DAT_00000007;
    pcStack_158 = "a_d2i_fp.c";
    piStack_15c = (int *)&DAT_0000006d;
    ERR_put_error(0xd,0x6d,7,"a_d2i_fp.c",0x4d);
    pXVar11 = (X509_ALGOR *)0x0;
  }
  else {
    ppAStack_1a4 = (ASN1_VALUE **)0x0;
    (*(code *)PTR_BIO_ctrl_006a7f18)(pXVar5,0x6a);
    piStack_15c = &iStack_ec;
    iStack_ec = 0;
    ppAVar10 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(pXVar5);
    if ((int)ppAVar10 < 0) {
      pXVar11 = (X509_ALGOR *)0x0;
      pcStack_158 = (char *)pXStack_11c;
    }
    else {
      piStack_15c = &iStack_e8;
      iStack_e8 = *(int *)(iStack_ec + 4);
      pXVar11 = (X509_ALGOR *)(*(code *)pXStack_19c)(pcStack_198);
      ppAStack_1a4 = ppAVar10;
      pcStack_158 = (char *)pXStack_11c;
    }
    if (iStack_ec != 0) {
      (*(code *)PTR_BUF_MEM_free_006a8594)();
    }
    (*(code *)PTR_BIO_free_006a7f70)(pXVar5);
    unaff_s0 = pXVar5;
    pXStack_11c = pXVar11;
  }
  if (iStack_e4 == *(int *)puStack_118) {
    return pXVar11;
  }
  pcStack_114 = ASN1_d2i_bio;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_160 = PTR___stack_chk_guard_006aabf0;
  piVar17 = &iStack_12c;
  puStack_140 = &_gp;
  iStack_12c = 0;
  pAStack_124 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  pXStack_120 = unaff_s0;
  ppAVar10 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(ppAStack_1a4,piVar17);
  if ((int)ppAVar10 < 0) {
    pXVar5 = (X509_ALGOR *)0x0;
  }
  else {
    piVar17 = &iStack_128;
    iStack_128 = *(int *)(iStack_12c + 4);
    pXVar5 = (X509_ALGOR *)(*(code *)piStack_15c)(pcStack_158,piVar17);
    ppAStack_1a4 = ppAVar10;
  }
  if (iStack_12c != 0) {
    pXStack_134 = pXVar5;
    (**(code **)(puStack_140 + -0x794c))();
    pXVar5 = pXStack_134;
  }
  if (pAStack_124 == *(ASN1_ITEM **)puStack_160) {
    return pXVar5;
  }
  pcStack_154 = ASN1_item_d2i_bio;
  pAStack_1a0 = pAStack_124;
  (**(code **)(puStack_140 + -0x5328))();
  puStack_1f8 = PTR___stack_chk_guard_006aabf0;
  pXStack_1f4 = (X509_ALGOR *)auStack_16c;
  puStack_180 = &_gp;
  auStack_16c._0_4_ = (ASN1_OBJECT *)0x0;
  pAStack_164 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  ppAStack_234 = ppAStack_1a4;
  ppAVar10 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(piVar17);
  if ((int)ppAVar10 < 0) {
    pXVar5 = (X509_ALGOR *)0x0;
  }
  else {
    pXStack_1f4 = (X509_ALGOR *)(auStack_16c + 4);
    auStack_16c._4_4_ = (ASN1_TYPE *)(auStack_16c._0_4_)->ln;
    pXVar5 = (X509_ALGOR *)
             ASN1_item_d2i(ppAStack_1a4,(uchar **)pXStack_1f4,(long)ppAVar10,pAStack_1a0);
    ppAStack_234 = ppAVar10;
  }
  if (auStack_16c._0_4_ != (ASN1_OBJECT *)0x0) {
    pXStack_174 = pXVar5;
    (**(code **)(puStack_180 + -0x794c))();
    pXVar5 = pXStack_174;
  }
  if (pAStack_164 == *(ASN1_ITEM **)puStack_1f8) {
    return pXVar5;
  }
  pcStack_194 = ASN1_item_d2i_fp;
  pAStack_1e8 = pAStack_164;
  (**(code **)(puStack_180 + -0x5328))();
  puStack_2b4 = PTR___stack_chk_guard_006aabf0;
  puStack_1a8 = puStack_1f8;
  pcStack_1ac = *(code **)PTR___stack_chk_guard_006aabf0;
  uVar9 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar12 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar9);
  if (puVar12 == (undefined *)0x0) {
    iStack_22c = 7;
    in = (uchar **)0xce;
    ERR_put_error(0xd,0xce,7,"a_d2i_fp.c",0x83);
    pXVar5 = (X509_ALGOR *)0x0;
  }
  else {
    iStack_22c = 0;
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar12,0x6a,0,pXStack_1f4);
    in = &puStack_1b4;
    puStack_1b4 = (uchar *)0x0;
    iVar4 = asn1_d2i_read_bio_constprop_0(puVar12,in);
    if (iVar4 < 0) {
      pXVar5 = (X509_ALGOR *)0x0;
    }
    else {
      in = &puStack_1b0;
      puStack_1b0 = *(uchar **)(puStack_1b4 + 4);
      pXVar5 = (X509_ALGOR *)ASN1_item_d2i(ppAStack_234,in,iVar4,pAStack_1e8);
      iStack_22c = iVar4;
    }
    if (puStack_1b4 != (uchar *)0x0) {
      (*(code *)PTR_BUF_MEM_free_006a8594)();
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar12);
    puStack_1f8 = puVar12;
    pXStack_1f4 = pXVar5;
  }
  if (pcStack_1ac == *(code **)puStack_2b4) {
    return pXVar5;
  }
  pcStack_1dc = ASN1_i2d_fp;
  pcStack_23c = pcStack_1ac;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_230 = PTR___stack_chk_guard_006aabf0;
  puStack_1f0 = puStack_2b4;
  pcStack_1fc = *(code **)PTR___stack_chk_guard_006aabf0;
  ppAStack_1ec = ppAStack_234;
  ppXStack_1e4 = unaff_s5;
  ppAStack_1e0 = unaff_s6;
  uVar9 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar12 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar9);
  if (puVar12 == (undefined *)0x0) {
    iVar4 = 7;
    pcStack_274 = (code *)0x75;
    pXStack_240 = (X509_ALGOR *)0x0;
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x4a);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar12,0x6a,0,in);
    iVar13 = (*pcStack_23c)(iStack_22c,0);
    unaff_s6 = (ASN1_TYPE **)0x670000;
    ppAStack_234 = (ASN1_VALUE **)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar13,"a_i2d_fp.c",0x5b);
    if (ppAStack_234 == (ASN1_VALUE **)0x0) {
      iVar4 = 0x41;
      pcStack_274 = (code *)&DAT_00000074;
      pXStack_240 = (X509_ALGOR *)0x0;
      ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5e);
    }
    else {
      ppAStack_200 = ppAStack_234;
      (*pcStack_23c)(iStack_22c,&ppAStack_200);
      pcStack_23c = (code *)0x0;
      while( true ) {
        pcStack_274 = (code *)((int)ppAStack_234 + (int)pcStack_23c);
        iVar4 = iVar13;
        iVar14 = (*(code *)PTR_BIO_write_006a7f14)(puVar12,pcStack_274,iVar13);
        if (iVar13 == iVar14) break;
        if (iVar14 < 1) {
          pXStack_240 = (X509_ALGOR *)0x0;
          goto LAB_0054fbe4;
        }
        pcStack_23c = pcStack_23c + iVar14;
        iVar13 = iVar13 - iVar14;
      }
      pXStack_240 = (X509_ALGOR *)0x1;
LAB_0054fbe4:
      (*(code *)PTR_CRYPTO_free_006a7f88)(ppAStack_234);
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar12);
    puStack_2b4 = puVar12;
  }
  if (pcStack_1fc == *(code **)puStack_230) {
    return pXStack_240;
  }
  pcStack_224 = ASN1_i2d_bio;
  pcStack_27c = pcStack_1fc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_270 = PTR___stack_chk_guard_006aabf0;
  pAStack_244 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  puStack_238 = puStack_2b4;
  ppAStack_228 = unaff_s6;
  pXStack_280 = (X509_ALGOR *)(*pcStack_27c)(iVar4,0);
  puVar12 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(pXStack_280,"a_i2d_fp.c",0x5b);
  if (puVar12 == (undefined *)0x0) {
    pXVar5 = (X509_ALGOR *)&DAT_00000041;
    puVar19 = &DAT_00000074;
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5e);
    pXVar11 = (X509_ALGOR *)0x0;
  }
  else {
    puStack_248 = puVar12;
    (*pcStack_27c)(iVar4,&puStack_248);
    pcStack_27c = (code *)0x0;
    while( true ) {
      puVar19 = puVar12 + (int)pcStack_27c;
      pXVar5 = pXStack_280;
      pXVar11 = (X509_ALGOR *)(*(code *)PTR_BIO_write_006a7f14)(pcStack_274,puVar19);
      if (pXStack_280 == pXVar11) break;
      if ((int)pXVar11 < 1) {
        pXVar11 = (X509_ALGOR *)0x0;
        goto LAB_0054fd84;
      }
      pcStack_27c = pcStack_27c + (int)pXVar11;
      pXStack_280 = (X509_ALGOR *)((int)pXStack_280 - (int)pXVar11);
    }
    pXVar11 = (X509_ALGOR *)0x1;
LAB_0054fd84:
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar12);
    pXStack_280 = pXVar11;
    puStack_2b4 = puVar12;
  }
  if (pAStack_244 == *(ASN1_ITEM **)puStack_270) {
    return pXVar11;
  }
  pcStack_26c = ASN1_item_i2d_fp;
  pAStack_2f8 = pAStack_244;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_2b0 = PTR___stack_chk_guard_006aabf0;
  pAStack_284 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  puStack_278 = puStack_2b4;
  uVar9 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar12 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar9);
  if (puVar12 == (undefined *)0x0) {
    val = (ASN1_VALUE *)&DAT_00000007;
    puStack_2f4 = (uchar *)0xc1;
    pXStack_2fc = (X509_ALGOR *)0x0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7f);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar12,0x6a,0,puVar19);
    puStack_288 = (uchar *)0x0;
    pAVar15 = (ASN1_VALUE *)ASN1_item_i2d((ASN1_VALUE *)pXVar5,&puStack_288,pAStack_2f8);
    if (puStack_288 == (uchar *)0x0) {
      val = (ASN1_VALUE *)&DAT_00000041;
      puStack_2f4 = &DAT_000000c0;
      pXStack_2fc = (X509_ALGOR *)0x0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x91);
    }
    else {
      pAStack_2f8 = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_2f4 = puStack_288 + (int)pAStack_2f8;
        val = pAVar15;
        pAVar16 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a7f14)(puVar12);
        if (pAVar15 == pAVar16) break;
        if ((int)pAVar16 < 1) {
          pXStack_2fc = (X509_ALGOR *)0x0;
          puStack_2f4 = puStack_288;
          goto LAB_0054fef0;
        }
        pAStack_2f8 = (ASN1_ITEM *)(pAVar16 + (int)&pAStack_2f8->itype);
        pAVar15 = pAVar15 + -(int)pAVar16;
      }
      pXStack_2fc = (X509_ALGOR *)0x1;
LAB_0054fef0:
      (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_288);
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar12);
    puStack_2b4 = puVar12;
  }
  if (pAStack_284 == *(ASN1_ITEM **)puStack_2b0) {
    return pXStack_2fc;
  }
  pcStack_2ac = ASN1_item_i2d_bio;
  it = pAStack_284;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_2f0 = PTR___stack_chk_guard_006aabf0;
  puStack_2c8 = (uchar *)0x0;
  piStack_2c4 = *(int **)PTR___stack_chk_guard_006aabf0;
  pXStack_2bc = pXStack_2fc;
  pAStack_2b8 = pAStack_2f8;
  iVar4 = ASN1_item_i2d(val,&puStack_2c8,it);
  if (puStack_2c8 == (uchar *)0x0) {
    puVar20 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x91);
    pXVar5 = (X509_ALGOR *)0x0;
  }
  else {
    pAStack_2f8 = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar20 = puStack_2c8 + (int)pAStack_2f8;
      iVar13 = (*(code *)PTR_BIO_write_006a7f14)(puStack_2f4,puVar20,iVar4);
      if (iVar4 == iVar13) break;
      if (iVar13 < 1) {
        pXVar5 = (X509_ALGOR *)0x0;
        puVar20 = puStack_2c8;
        goto LAB_00550050;
      }
      pAStack_2f8 = (ASN1_ITEM *)(&pAStack_2f8->itype + iVar13);
      iVar4 = iVar4 - iVar13;
    }
    pXVar5 = (X509_ALGOR *)0x1;
LAB_00550050:
    (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_2c8);
    pXStack_2fc = pXVar5;
  }
  if (piStack_2c4 == *(int **)puStack_2f0) {
    return pXVar5;
  }
  pcStack_2ec = ASN1_ENUMERATED_set;
  piVar17 = piStack_2c4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar12 = PTR___stack_chk_guard_006aabf0;
  piVar17[1] = 10;
  piStack_304 = *(int **)puVar12;
  if (*piVar17 < 5) {
    if (piVar17[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    puVar19 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(5,"a_enum.c",0x51);
    piVar17[2] = (int)puVar19;
    if (puVar19 != (undefined *)0x0) {
      *puVar19 = 0;
      puVar19[1] = 0;
      puVar19[2] = 0;
      puVar19[3] = 0;
      puVar19[4] = 0;
      goto LAB_00550170;
    }
  }
  else {
LAB_00550170:
    puVar19 = (undefined *)piVar17[2];
    if (puVar19 != (undefined *)0x0) {
      if ((int)puVar20 < 0) {
        puVar20 = (uchar *)-(int)puVar20;
        piVar17[1] = 0x10a;
LAB_0055018c:
        auStack_30e[2] = (char)puVar20;
        if ((int)puVar20 >> 8 == 0) {
          iVar4 = 1;
LAB_00550260:
          iVar13 = iVar4 + -1;
          *puVar19 = auStack_30e[iVar4 + 1];
          if (iVar4 != 1) {
            iVar14 = iVar4 + -3;
            *(undefined *)(piVar17[2] + 1) = auStack_30e[iVar4];
            if (iVar14 == -1) goto LAB_005501f0;
            goto LAB_005501c8;
          }
        }
        else {
          auStack_30e[3] = (char)((uint)puVar20 >> 8);
          if ((int)puVar20 >> 0x10 == 0) {
            iVar4 = 2;
            goto LAB_00550260;
          }
          auStack_30e[4] = (undefined)((uint)puVar20 >> 0x10);
          if ((int)puVar20 >> 0x18 == 0) {
            iVar4 = 3;
            goto LAB_00550260;
          }
          auStack_30e[5] = (undefined)((uint)puVar20 >> 0x18);
          *puVar19 = auStack_30e[5];
          iVar13 = 3;
          iVar14 = 1;
          *(undefined *)(piVar17[2] + 1) = auStack_30e[4];
LAB_005501c8:
          *(undefined *)(piVar17[2] + 2) = auStack_30e[iVar14 + 2];
          if (iVar14 != 0) {
            *(char *)(piVar17[2] + 3) = (char)puVar20;
          }
        }
        iVar4 = iVar13 + 1;
      }
      else {
        iVar4 = 0;
        if (puVar20 != (uchar *)0x0) goto LAB_0055018c;
      }
LAB_005501f0:
      pXVar5 = (X509_ALGOR *)0x1;
      *piVar17 = iVar4;
      goto LAB_005501f8;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x56);
  pXVar5 = (X509_ALGOR *)0x0;
LAB_005501f8:
  if (piStack_304 == *(int **)puVar12) {
    return pXVar5;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (piStack_304 != (int *)0x0) {
    if (piStack_304[1] == 0x10a) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (piStack_304[1] != 10) {
        return (X509_ALGOR *)0xffffffff;
      }
    }
    iVar4 = *piStack_304;
    if (4 < iVar4) {
      return (X509_ALGOR *)0xffffffff;
    }
    pbVar18 = (byte *)piStack_304[2];
    if (pbVar18 != (byte *)0x0) {
      if (iVar4 < 1) {
        pXVar5 = (X509_ALGOR *)0x0;
      }
      else {
        pXVar5 = (X509_ALGOR *)(uint)*pbVar18;
        if (iVar4 != 1) {
          uVar1 = CONCAT11(*pbVar18,pbVar18[1]);
          pXVar5 = (X509_ALGOR *)(uint)uVar1;
          if (iVar4 != 2) {
            uVar2 = CONCAT21(uVar1,pbVar18[2]);
            pXVar5 = (X509_ALGOR *)(uint)uVar2;
            if (iVar4 == 4) {
              pXVar5 = (X509_ALGOR *)CONCAT31(uVar2,pbVar18[3]);
            }
          }
        }
      }
      if (!bVar3) {
        return pXVar5;
      }
      return (X509_ALGOR *)-(int)pXVar5;
    }
  }
  return (X509_ALGOR *)0x0;
joined_r0x0054f494:
  if (pXStack_dc == (X509_ALGOR *)0x0) goto LAB_0054f4cc;
  pXStack_11c = pXStack_dc;
  iVar4 = (*(code *)PTR_BIO_read_006a85bc)
                    (pAStack_d0,(undefined *)((int)&unaff_s0->algorithm + (int)pAVar6->ln));
  if (iVar4 < 1) {
    pXStack_11c = (X509_ALGOR *)0x8e;
    iVar4 = 0xfb;
    goto LAB_0054f554;
  }
  pXStack_dc = (X509_ALGOR *)((int)pXStack_dc - iVar4);
  unaff_s0 = (X509_ALGOR *)((int)&unaff_s0->algorithm + iVar4);
  goto joined_r0x0054f494;
LAB_0054f4cc:
  pXVar5 = (X509_ALGOR *)((int)&(aXStack_80[0].algorithm)->sn + (int)&pXVar21->algorithm);
  pXVar21 = (X509_ALGOR *)(uint)(pXVar5 < pXVar21);
  if (pXVar21 != (X509_ALGOR *)0x0) {
    pXStack_11c = (X509_ALGOR *)0x9b;
    iVar4 = 0x106;
    goto LAB_0054f554;
  }
  pXVar21 = pXVar5;
  if (iStack_a8 == 0) goto LAB_0054f43c;
  pXStack_dc = (X509_ALGOR *)((int)unaff_s0 - (int)pXVar5);
  goto LAB_0054f334;
LAB_0054f43c:
  pcStack_198 = "7 datafinal";
  if ((int)pXVar21 < 0) {
    pXStack_11c = (X509_ALGOR *)0x9b;
    iVar4 = 0x115;
LAB_0054f554:
    pcStack_198 = "a_d2i_fp.c";
    pXStack_19c = (X509_ALGOR *)&DAT_0000006b;
    ERR_put_error(0xd,0x6b,(int)pXStack_11c,"a_d2i_fp.c",iVar4);
    unaff_s2 = pXVar21;
LAB_0054f568:
    (*(code *)PTR_BUF_MEM_free_006a8594)(pAVar6);
    pXVar21 = (X509_ALGOR *)0xffffffff;
  }
  else {
    xn->algorithm = pAVar6;
    pXStack_19c = pXVar21;
    unaff_s2 = pXVar21;
  }
  goto LAB_0054f57c;
}

