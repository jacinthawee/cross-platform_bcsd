
X509_ATTRIBUTE * X509_ATTRIBUTE_dup(X509_ATTRIBUTE *xa)

{
  bool bVar1;
  ushort uVar2;
  uint3 uVar3;
  int iVar4;
  ASN1_OBJECT *pAVar5;
  X509_ATTRIBUTE *pXVar6;
  ulong uVar7;
  undefined4 uVar8;
  ASN1_VALUE **ppAVar9;
  undefined *puVar10;
  int iVar11;
  int iVar12;
  ASN1_VALUE *pAVar13;
  ASN1_VALUE *pAVar14;
  ASN1_ITEM *it;
  int *piVar15;
  byte *pbVar16;
  uchar **in;
  undefined *puVar17;
  uchar *puVar18;
  ASN1_VALUE *val;
  ASN1_OBJECT *unaff_s0;
  X509_ATTRIBUTE *pXVar19;
  char **ppcVar20;
  X509_ATTRIBUTE *pXVar21;
  X509_ATTRIBUTE *unaff_s3;
  X509_ATTRIBUTE **unaff_s4;
  X509_ATTRIBUTE *unaff_s5;
  int *unaff_s6;
  X509_ATTRIBUTE *pXVar22;
  undefined auStack_316 [10];
  int *piStack_30c;
  X509_ATTRIBUTE *pXStack_304;
  ASN1_ITEM *pAStack_300;
  uchar *puStack_2fc;
  undefined *puStack_2f8;
  code *pcStack_2f4;
  uchar *puStack_2d0;
  int *piStack_2cc;
  X509_ATTRIBUTE *pXStack_2c4;
  ASN1_ITEM *pAStack_2c0;
  undefined *puStack_2bc;
  undefined *puStack_2b8;
  code *pcStack_2b4;
  uchar *puStack_290;
  ASN1_ITEM *pAStack_28c;
  X509_ATTRIBUTE *pXStack_288;
  code *pcStack_284;
  undefined *puStack_280;
  code *pcStack_27c;
  undefined *puStack_278;
  code *pcStack_274;
  undefined *puStack_250;
  ASN1_ITEM *pAStack_24c;
  X509_ATTRIBUTE *pXStack_248;
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
  X509_ATTRIBUTE *pXStack_1fc;
  undefined *puStack_1f8;
  ASN1_VALUE **ppAStack_1f4;
  _union_330 _Stack_1f0;
  X509_ATTRIBUTE *pXStack_1ec;
  int *piStack_1e8;
  undefined4 uStack_1e4;
  uchar *puStack_1bc;
  uchar *puStack_1b8;
  code *pcStack_1b4;
  undefined *puStack_1b0;
  ASN1_VALUE **ppAStack_1ac;
  ASN1_ITEM *pAStack_1a8;
  _union_330 *p_Stack_1a4;
  char *pcStack_1a0;
  code *pcStack_19c;
  undefined *puStack_188;
  X509_ATTRIBUTE *pXStack_17c;
  undefined auStack_174 [8];
  _union_330 _Stack_16c;
  undefined *puStack_168;
  int *piStack_164;
  char *pcStack_160;
  code *pcStack_15c;
  undefined *puStack_148;
  X509_ATTRIBUTE *pXStack_13c;
  int iStack_134;
  int iStack_130;
  ASN1_ITEM *pAStack_12c;
  ASN1_OBJECT *pAStack_128;
  X509_ATTRIBUTE *pXStack_124;
  undefined *puStack_120;
  code *pcStack_11c;
  int iStack_f4;
  int iStack_f0;
  int iStack_ec;
  ASN1_OBJECT *pAStack_e8;
  X509_ATTRIBUTE *pXStack_e4;
  int iStack_e0;
  X509_ATTRIBUTE *pXStack_dc;
  X509_ATTRIBUTE **ppXStack_d8;
  code *pcStack_d4;
  int iStack_b0;
  X509_ATTRIBUTE *pXStack_ac;
  X509_ATTRIBUTE *apXStack_98 [3];
  uint uStack_8c;
  X509_ATTRIBUTE aXStack_88 [2];
  int iStack_6c;
  ASN1_OBJECT *pAStack_68;
  undefined *puStack_64;
  ASN1_OBJECT *pAStack_1c;
  X509_ATTRIBUTE XStack_18;
  
  pXStack_e4 = (X509_ATTRIBUTE *)PTR___stack_chk_guard_006a9ae8;
  pAStack_1c = (ASN1_OBJECT *)0x0;
  XStack_18.single = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (xa == (X509_ATTRIBUTE *)0x0) {
    pAVar5 = (ASN1_OBJECT *)0x0;
  }
  else {
    iVar4 = ASN1_item_i2d((ASN1_VALUE *)xa,(uchar **)&pAStack_1c,(ASN1_ITEM *)X509_ATTRIBUTE_it);
    if (pAStack_1c == (ASN1_OBJECT *)0x0) {
      xa = (X509_ATTRIBUTE *)0xbf;
      ERR_put_error(0xd,0xbf,0x41,"a_dup.c",0x6e);
      pAVar5 = (ASN1_OBJECT *)0x0;
      unaff_s0 = (ASN1_OBJECT *)X509_ATTRIBUTE_it;
    }
    else {
      xa = &XStack_18;
      XStack_18.object = pAStack_1c;
      pAVar5 = (ASN1_OBJECT *)
               ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)xa,iVar4,(ASN1_ITEM *)X509_ATTRIBUTE_it);
      (*(code *)PTR_CRYPTO_free_006a6e88)(pAStack_1c);
      unaff_s0 = pAVar5;
    }
  }
  if (XStack_18.single == *(int *)pXStack_e4) {
    return (X509_ATTRIBUTE *)pAVar5;
  }
  iStack_e0 = XStack_18.single;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar10 = PTR___stack_chk_guard_006a9ae8;
  puStack_64 = (undefined *)pXStack_e4;
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAStack_68 = unaff_s0;
  pAVar5 = (ASN1_OBJECT *)(*(code *)PTR_BUF_MEM_new_006a749c)();
  if (pAVar5 != (ASN1_OBJECT *)0x0) {
    unaff_s4 = apXStack_98;
    unaff_s6 = &aXStack_88[0].single;
    ERR_clear_error();
    iStack_b0 = 0;
    pXVar22 = (X509_ATTRIBUTE *)0x0;
    unaff_s5 = (X509_ATTRIBUTE *)0x0;
    pXVar19 = (X509_ATTRIBUTE *)0x0;
LAB_0054c08c:
    unaff_s0 = pAVar5;
    if ((X509_ATTRIBUTE *)&DAT_00000008 < unaff_s5) goto LAB_0054c0f0;
    while ((unaff_s3 = (X509_ATTRIBUTE *)((int)&pXVar19->value - (int)pXVar22),
           pXVar22 <= &pXVar19->value &&
           (iVar4 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(pAVar5), iVar4 != 0))) {
      iVar4 = (*(code *)PTR_BIO_read_006a74c0)
                        (iStack_e0,(undefined *)((int)&pXVar22->object + (int)pAVar5->ln),unaff_s3);
      if (iVar4 < 0) {
        if (pXVar22 == pXVar19) {
          pXStack_124 = (X509_ATTRIBUTE *)0x8e;
          iVar4 = 0xad;
          goto LAB_0054c284;
        }
      }
      else {
        pXVar6 = (X509_ATTRIBUTE *)((int)&pXVar22->object + iVar4);
        if ((iVar4 != 0) &&
           (bVar1 = pXVar6 < pXVar22, unaff_s5 = (X509_ATTRIBUTE *)((int)pXVar6 - (int)pXVar19),
           pXVar22 = pXVar6, bVar1)) {
          pXStack_124 = (X509_ATTRIBUTE *)&DAT_0000009b;
          iVar4 = 0xb2;
          goto LAB_0054c284;
        }
      }
LAB_0054c0f0:
      ppcVar20 = pAVar5->ln;
      while( true ) {
        p_Stack_1a4 = &aXStack_88[0].value;
        unaff_s3 = (X509_ATTRIBUTE *)((int)&pXVar19->object + (int)ppcVar20);
        pXStack_124 = aXStack_88;
        pcStack_1a0 = (char *)unaff_s6;
        apXStack_98[0] = unaff_s3;
        uStack_8c = ASN1_get_object((uchar **)unaff_s4,(long *)p_Stack_1a4,(int *)aXStack_88,
                                    unaff_s6,(long)unaff_s5);
        if ((uStack_8c & 0x80) != 0) {
          uVar7 = ERR_peek_error();
          pXStack_e4 = pXVar19;
          if ((uVar7 & 0xfff) != 0x9b) goto LAB_0054c298;
          ERR_clear_error();
        }
        unaff_s3 = (X509_ATTRIBUTE *)((int)apXStack_98[0] - (int)unaff_s3);
        pXVar19 = (X509_ATTRIBUTE *)((int)pXVar19 + (int)unaff_s3);
        if ((uStack_8c & 1) == 0) {
          if ((iStack_b0 != 0) && (aXStack_88[0].value.ptr == (char *)0x0)) {
            unaff_s5 = (X509_ATTRIBUTE *)((int)pXVar22 - (int)pXVar19);
            if ((aXStack_88[0].object != (ASN1_OBJECT *)0x0) ||
               (iStack_b0 = iStack_b0 + -1, iStack_b0 != 0)) goto LAB_0054c08c;
            goto LAB_0054c324;
          }
          pXVar6 = (X509_ATTRIBUTE *)(aXStack_88[0].value.ptr + (int)pXVar19);
          if (aXStack_88[0].value.ptr <= (char *)((int)pXVar22 - (int)pXVar19)) goto LAB_0054c220;
          unaff_s5 = (X509_ATTRIBUTE *)((int)pXVar6 - (int)pXVar22);
          if ((-1 < (int)unaff_s5) && (pXVar22 <= pXVar6)) {
            pXStack_ac = (X509_ATTRIBUTE *)&DAT_00004000;
            if (unaff_s5 != (X509_ATTRIBUTE *)0x0) goto LAB_0054c1a0;
            goto LAB_0054c220;
          }
          pXStack_124 = (X509_ATTRIBUTE *)&DAT_0000009b;
          iVar4 = 0xe2;
          goto LAB_0054c284;
        }
        unaff_s5 = (X509_ATTRIBUTE *)((int)pXVar22 - (int)pXVar19);
        iStack_b0 = iStack_b0 + 1;
        if (unaff_s5 < (X509_ATTRIBUTE *)&DAT_00000009) break;
        ppcVar20 = pAVar5->ln;
      }
    }
    pXStack_124 = (X509_ATTRIBUTE *)&DAT_00000041;
    iVar4 = 0xa8;
    goto LAB_0054c284;
  }
  pXStack_124 = (X509_ATTRIBUTE *)&DAT_00000041;
  pcStack_1a0 = "a_d2i_fp.c";
  p_Stack_1a4 = (_union_330 *)&DAT_0000006b;
  ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",0x9e);
  pXVar19 = (X509_ATTRIBUTE *)0xffffffff;
LAB_0054c2ac:
  if (iStack_6c == *(int *)puVar10) {
    return pXVar19;
  }
  pcStack_d4 = ASN1_d2i_fp;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_120 = PTR___stack_chk_guard_006a9ae8;
  iStack_ec = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAStack_e8 = unaff_s0;
  pXStack_dc = unaff_s3;
  ppXStack_d8 = unaff_s4;
  uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  pAVar5 = (ASN1_OBJECT *)(*(code *)PTR_BIO_new_006a6ea4)(uVar8);
  if (pAVar5 == (ASN1_OBJECT *)0x0) {
    ppAStack_1ac = (ASN1_VALUE **)&DAT_00000007;
    pcStack_160 = "a_d2i_fp.c";
    piStack_164 = (int *)&DAT_0000006d;
    ERR_put_error(0xd,0x6d,7,"a_d2i_fp.c",0x4c);
    pXVar19 = (X509_ATTRIBUTE *)0x0;
  }
  else {
    ppAStack_1ac = (ASN1_VALUE **)0x0;
    (*(code *)PTR_BIO_ctrl_006a6e18)(pAVar5,0x6a);
    piStack_164 = &iStack_f4;
    iStack_f4 = 0;
    ppAVar9 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(pAVar5);
    if ((int)ppAVar9 < 0) {
      pXVar19 = (X509_ATTRIBUTE *)0x0;
      pcStack_160 = (char *)pXStack_124;
    }
    else {
      piStack_164 = &iStack_f0;
      iStack_f0 = *(int *)(iStack_f4 + 4);
      pXVar19 = (X509_ATTRIBUTE *)(*(code *)p_Stack_1a4)(pcStack_1a0);
      ppAStack_1ac = ppAVar9;
      pcStack_160 = (char *)pXStack_124;
    }
    if (iStack_f4 != 0) {
      (*(code *)PTR_BUF_MEM_free_006a7494)();
    }
    (*(code *)PTR_BIO_free_006a6e70)(pAVar5);
    unaff_s0 = pAVar5;
    pXStack_124 = pXVar19;
  }
  if (iStack_ec == *(int *)puStack_120) {
    return pXVar19;
  }
  pcStack_11c = ASN1_d2i_bio;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_168 = PTR___stack_chk_guard_006a9ae8;
  piVar15 = &iStack_134;
  puStack_148 = &_gp;
  iStack_134 = 0;
  pAStack_12c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pAStack_128 = unaff_s0;
  ppAVar9 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(ppAStack_1ac,piVar15);
  if ((int)ppAVar9 < 0) {
    pXVar19 = (X509_ATTRIBUTE *)0x0;
  }
  else {
    piVar15 = &iStack_130;
    iStack_130 = *(int *)(iStack_134 + 4);
    pXVar19 = (X509_ATTRIBUTE *)(*(code *)piStack_164)(pcStack_160,piVar15);
    ppAStack_1ac = ppAVar9;
  }
  if (iStack_134 != 0) {
    pXStack_13c = pXVar19;
    (**(code **)(puStack_148 + -0x794c))();
    pXVar19 = pXStack_13c;
  }
  if (pAStack_12c == *(ASN1_ITEM **)puStack_168) {
    return pXVar19;
  }
  pcStack_15c = ASN1_item_d2i_bio;
  pAStack_1a8 = pAStack_12c;
  (**(code **)(puStack_148 + -0x5330))();
  puStack_200 = PTR___stack_chk_guard_006a9ae8;
  pXStack_1fc = (X509_ATTRIBUTE *)auStack_174;
  puStack_188 = &_gp;
  auStack_174._0_4_ = (ASN1_OBJECT *)0x0;
  _Stack_16c = *(_union_330 *)PTR___stack_chk_guard_006a9ae8;
  ppAStack_23c = ppAStack_1ac;
  ppAVar9 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(piVar15);
  if ((int)ppAVar9 < 0) {
    pXVar19 = (X509_ATTRIBUTE *)0x0;
  }
  else {
    pXStack_1fc = (X509_ATTRIBUTE *)(auStack_174 + 4);
    auStack_174._4_4_ = (auStack_174._0_4_)->ln;
    pXVar19 = (X509_ATTRIBUTE *)
              ASN1_item_d2i(ppAStack_1ac,(uchar **)pXStack_1fc,(long)ppAVar9,pAStack_1a8);
    ppAStack_23c = ppAVar9;
  }
  if (auStack_174._0_4_ != (ASN1_OBJECT *)0x0) {
    pXStack_17c = pXVar19;
    (**(code **)(puStack_188 + -0x794c))();
    pXVar19 = pXStack_17c;
  }
  if ((ASN1_ITEM *)_Stack_16c.ptr == *(ASN1_ITEM **)puStack_200) {
    return pXVar19;
  }
  pcStack_19c = ASN1_item_d2i_fp;
  _Stack_1f0 = _Stack_16c;
  (**(code **)(puStack_188 + -0x5330))();
  puStack_2bc = PTR___stack_chk_guard_006a9ae8;
  puStack_1b0 = puStack_200;
  pcStack_1b4 = *(code **)PTR___stack_chk_guard_006a9ae8;
  uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar10 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar8);
  if (puVar10 == (undefined *)0x0) {
    iStack_234 = 7;
    in = (uchar **)0xce;
    ERR_put_error(0xd,0xce,7,"a_d2i_fp.c",0x85);
    pXVar19 = (X509_ATTRIBUTE *)0x0;
  }
  else {
    iStack_234 = 0;
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar10,0x6a,0,pXStack_1fc);
    in = &puStack_1bc;
    puStack_1bc = (uchar *)0x0;
    iVar4 = asn1_d2i_read_bio_constprop_0(puVar10,in);
    if (iVar4 < 0) {
      pXVar19 = (X509_ATTRIBUTE *)0x0;
    }
    else {
      in = &puStack_1b8;
      puStack_1b8 = *(uchar **)(puStack_1bc + 4);
      pXVar19 = (X509_ATTRIBUTE *)ASN1_item_d2i(ppAStack_23c,in,iVar4,(ASN1_ITEM *)_Stack_1f0.set);
      iStack_234 = iVar4;
    }
    if (puStack_1bc != (uchar *)0x0) {
      (*(code *)PTR_BUF_MEM_free_006a7494)();
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar10);
    puStack_200 = puVar10;
    pXStack_1fc = pXVar19;
  }
  if (pcStack_1b4 == *(code **)puStack_2bc) {
    return pXVar19;
  }
  uStack_1e4 = 0x54c854;
  pcStack_244 = pcStack_1b4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_238 = PTR___stack_chk_guard_006a9ae8;
  puStack_1f8 = puStack_2bc;
  pcStack_204 = *(code **)PTR___stack_chk_guard_006a9ae8;
  ppAStack_1f4 = ppAStack_23c;
  pXStack_1ec = unaff_s5;
  piStack_1e8 = unaff_s6;
  uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar10 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar8);
  if (puVar10 == (undefined *)0x0) {
    iVar4 = 7;
    pcStack_27c = (code *)0x75;
    pXStack_248 = (X509_ATTRIBUTE *)0x0;
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x49);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar10,0x6a,0,in);
    iVar11 = (*pcStack_244)(iStack_234,0);
    unaff_s6 = (int *)0x670000;
    ppAStack_23c = (ASN1_VALUE **)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar11,"a_i2d_fp.c",0x5a);
    if (ppAStack_23c == (ASN1_VALUE **)0x0) {
      iVar4 = 0x41;
      pcStack_27c = (code *)&DAT_00000074;
      pXStack_248 = (X509_ATTRIBUTE *)0x0;
      ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    }
    else {
      ppAStack_208 = ppAStack_23c;
      (*pcStack_244)(iStack_234,&ppAStack_208);
      pcStack_244 = (code *)0x0;
      while( true ) {
        pcStack_27c = (code *)((int)ppAStack_23c + (int)pcStack_244);
        iVar4 = iVar11;
        iVar12 = (*(code *)PTR_BIO_write_006a6e14)(puVar10,pcStack_27c,iVar11);
        if (iVar11 == iVar12) break;
        if (iVar12 < 1) {
          pXStack_248 = (X509_ATTRIBUTE *)0x0;
          goto LAB_0054c974;
        }
        pcStack_244 = pcStack_244 + iVar12;
        iVar11 = iVar11 - iVar12;
      }
      pXStack_248 = (X509_ATTRIBUTE *)0x1;
LAB_0054c974:
      (*(code *)PTR_CRYPTO_free_006a6e88)(ppAStack_23c);
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar10);
    puStack_2bc = puVar10;
  }
  if (pcStack_204 == *(code **)puStack_238) {
    return pXStack_248;
  }
  pcStack_22c = ASN1_i2d_bio;
  pcStack_284 = pcStack_204;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_278 = PTR___stack_chk_guard_006a9ae8;
  pAStack_24c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_240 = puStack_2bc;
  piStack_230 = unaff_s6;
  pXStack_288 = (X509_ATTRIBUTE *)(*pcStack_284)(iVar4,0);
  puVar10 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(pXStack_288,"a_i2d_fp.c",0x5a);
  if (puVar10 == (undefined *)0x0) {
    pXVar19 = (X509_ATTRIBUTE *)&DAT_00000041;
    puVar17 = &DAT_00000074;
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    pXVar22 = (X509_ATTRIBUTE *)0x0;
  }
  else {
    puStack_250 = puVar10;
    (*pcStack_284)(iVar4,&puStack_250);
    pcStack_284 = (code *)0x0;
    while( true ) {
      puVar17 = puVar10 + (int)pcStack_284;
      pXVar19 = pXStack_288;
      pXVar22 = (X509_ATTRIBUTE *)(*(code *)PTR_BIO_write_006a6e14)(pcStack_27c,puVar17);
      if (pXStack_288 == pXVar22) break;
      if ((int)pXVar22 < 1) {
        pXVar22 = (X509_ATTRIBUTE *)0x0;
        goto LAB_0054cb14;
      }
      pcStack_284 = pcStack_284 + (int)pXVar22;
      pXStack_288 = (X509_ATTRIBUTE *)((int)pXStack_288 - (int)pXVar22);
    }
    pXVar22 = (X509_ATTRIBUTE *)0x1;
LAB_0054cb14:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar10);
    pXStack_288 = pXVar22;
    puStack_2bc = puVar10;
  }
  if (pAStack_24c == *(ASN1_ITEM **)puStack_278) {
    return pXVar22;
  }
  pcStack_274 = ASN1_item_i2d_fp;
  pAStack_300 = pAStack_24c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_2b8 = PTR___stack_chk_guard_006a9ae8;
  pAStack_28c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_280 = puStack_2bc;
  uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar10 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar8);
  if (puVar10 == (undefined *)0x0) {
    val = (ASN1_VALUE *)&DAT_00000007;
    puStack_2fc = (uchar *)0xc1;
    pXStack_304 = (X509_ATTRIBUTE *)0x0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7b);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar10,0x6a,0,puVar17);
    puStack_290 = (uchar *)0x0;
    pAVar13 = (ASN1_VALUE *)ASN1_item_i2d((ASN1_VALUE *)pXVar19,&puStack_290,pAStack_300);
    if (puStack_290 == (uchar *)0x0) {
      val = (ASN1_VALUE *)&DAT_00000041;
      puStack_2fc = &DAT_000000c0;
      pXStack_304 = (X509_ATTRIBUTE *)0x0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    }
    else {
      pAStack_300 = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_2fc = puStack_290 + (int)pAStack_300;
        val = pAVar13;
        pAVar14 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(puVar10);
        if (pAVar13 == pAVar14) break;
        if ((int)pAVar14 < 1) {
          pXStack_304 = (X509_ATTRIBUTE *)0x0;
          puStack_2fc = puStack_290;
          goto LAB_0054cc80;
        }
        pAStack_300 = (ASN1_ITEM *)(pAVar14 + (int)&pAStack_300->itype);
        pAVar13 = pAVar13 + -(int)pAVar14;
      }
      pXStack_304 = (X509_ATTRIBUTE *)0x1;
LAB_0054cc80:
      (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_290);
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar10);
    puStack_2bc = puVar10;
  }
  if (pAStack_28c == *(ASN1_ITEM **)puStack_2b8) {
    return pXStack_304;
  }
  pcStack_2b4 = ASN1_item_i2d_bio;
  it = pAStack_28c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_2f8 = PTR___stack_chk_guard_006a9ae8;
  puStack_2d0 = (uchar *)0x0;
  piStack_2cc = *(int **)PTR___stack_chk_guard_006a9ae8;
  pXStack_2c4 = pXStack_304;
  pAStack_2c0 = pAStack_300;
  iVar4 = ASN1_item_i2d(val,&puStack_2d0,it);
  if (puStack_2d0 == (uchar *)0x0) {
    puVar18 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    pXVar19 = (X509_ATTRIBUTE *)0x0;
  }
  else {
    pAStack_300 = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar18 = puStack_2d0 + (int)pAStack_300;
      iVar11 = (*(code *)PTR_BIO_write_006a6e14)(puStack_2fc,puVar18,iVar4);
      if (iVar4 == iVar11) break;
      if (iVar11 < 1) {
        pXVar19 = (X509_ATTRIBUTE *)0x0;
        puVar18 = puStack_2d0;
        goto LAB_0054cde0;
      }
      pAStack_300 = (ASN1_ITEM *)(&pAStack_300->itype + iVar11);
      iVar4 = iVar4 - iVar11;
    }
    pXVar19 = (X509_ATTRIBUTE *)0x1;
LAB_0054cde0:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_2d0);
    pXStack_304 = pXVar19;
  }
  if (piStack_2cc == *(int **)puStack_2f8) {
    return pXVar19;
  }
  pcStack_2f4 = ASN1_ENUMERATED_set;
  piVar15 = piStack_2cc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar10 = PTR___stack_chk_guard_006a9ae8;
  piVar15[1] = 10;
  piStack_30c = *(int **)puVar10;
  if (*piVar15 < 5) {
    if (piVar15[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar17 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(5,"a_enum.c",0x51);
    piVar15[2] = (int)puVar17;
    if (puVar17 != (undefined *)0x0) {
      *puVar17 = 0;
      puVar17[1] = 0;
      puVar17[2] = 0;
      puVar17[3] = 0;
      puVar17[4] = 0;
      goto LAB_0054cf00;
    }
  }
  else {
LAB_0054cf00:
    puVar17 = (undefined *)piVar15[2];
    if (puVar17 != (undefined *)0x0) {
      if ((int)puVar18 < 0) {
        puVar18 = (uchar *)-(int)puVar18;
        piVar15[1] = 0x10a;
LAB_0054cf1c:
        auStack_316[2] = (char)puVar18;
        if ((int)puVar18 >> 8 == 0) {
          iVar4 = 1;
LAB_0054cff0:
          iVar11 = iVar4 + -1;
          *puVar17 = auStack_316[iVar4 + 1];
          if (iVar4 != 1) {
            iVar12 = iVar4 + -3;
            *(undefined *)(piVar15[2] + 1) = auStack_316[iVar4];
            if (iVar12 == -1) goto LAB_0054cf80;
            goto LAB_0054cf58;
          }
        }
        else {
          auStack_316[3] = (char)((uint)puVar18 >> 8);
          if ((int)puVar18 >> 0x10 == 0) {
            iVar4 = 2;
            goto LAB_0054cff0;
          }
          auStack_316[4] = (undefined)((uint)puVar18 >> 0x10);
          if ((int)puVar18 >> 0x18 == 0) {
            iVar4 = 3;
            goto LAB_0054cff0;
          }
          auStack_316[5] = (undefined)((uint)puVar18 >> 0x18);
          *puVar17 = auStack_316[5];
          iVar11 = 3;
          iVar12 = 1;
          *(undefined *)(piVar15[2] + 1) = auStack_316[4];
LAB_0054cf58:
          *(undefined *)(piVar15[2] + 2) = auStack_316[iVar12 + 2];
          if (iVar12 != 0) {
            *(char *)(piVar15[2] + 3) = (char)puVar18;
          }
        }
        iVar4 = iVar11 + 1;
      }
      else {
        iVar4 = 0;
        if (puVar18 != (uchar *)0x0) goto LAB_0054cf1c;
      }
LAB_0054cf80:
      pXVar19 = (X509_ATTRIBUTE *)0x1;
      *piVar15 = iVar4;
      goto LAB_0054cf88;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x55);
  pXVar19 = (X509_ATTRIBUTE *)0x0;
LAB_0054cf88:
  if (piStack_30c == *(int **)puVar10) {
    return pXVar19;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piStack_30c != (int *)0x0) {
    if (piStack_30c[1] == 0x10a) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
      if (piStack_30c[1] != 10) {
        return (X509_ATTRIBUTE *)0xffffffff;
      }
    }
    iVar4 = *piStack_30c;
    if (4 < iVar4) {
      return (X509_ATTRIBUTE *)0xffffffff;
    }
    pbVar16 = (byte *)piStack_30c[2];
    if (pbVar16 != (byte *)0x0) {
      if (iVar4 < 1) {
        pXVar19 = (X509_ATTRIBUTE *)0x0;
      }
      else {
        pXVar19 = (X509_ATTRIBUTE *)(uint)*pbVar16;
        if (iVar4 != 1) {
          uVar2 = CONCAT11(*pbVar16,pbVar16[1]);
          pXVar19 = (X509_ATTRIBUTE *)(uint)uVar2;
          if (iVar4 != 2) {
            uVar3 = CONCAT21(uVar2,pbVar16[2]);
            pXVar19 = (X509_ATTRIBUTE *)(uint)uVar3;
            if (iVar4 == 4) {
              pXVar19 = (X509_ATTRIBUTE *)CONCAT31(uVar3,pbVar16[3]);
            }
          }
        }
      }
      if (!bVar1) {
        return pXVar19;
      }
      return (X509_ATTRIBUTE *)-(int)pXVar19;
    }
  }
  return (X509_ATTRIBUTE *)0x0;
  while( true ) {
    do {
      p_Stack_1a4 = (_union_330 *)((int)&pXVar22->object + (int)pAVar5->ln);
      pXStack_124 = pXVar21;
      iVar4 = (*(code *)PTR_BIO_read_006a74c0)(iStack_e0);
      if (iVar4 < 1) {
        pXStack_124 = (X509_ATTRIBUTE *)0x8e;
        iVar4 = 0xf7;
        unaff_s3 = pXVar21;
        goto LAB_0054c284;
      }
      unaff_s3 = (X509_ATTRIBUTE *)((int)pXVar21 - iVar4);
      pXVar22 = (X509_ATTRIBUTE *)((int)&pXVar22->object + iVar4);
      pXVar21 = unaff_s3;
    } while (unaff_s3 != (X509_ATTRIBUTE *)0x0);
    unaff_s5 = (X509_ATTRIBUTE *)((int)unaff_s5 - (int)pXVar6);
    pXStack_ac = (X509_ATTRIBUTE *)((int)pXStack_ac << (pXStack_ac < (X509_ATTRIBUTE *)0x3fffffff));
    if (unaff_s5 == (X509_ATTRIBUTE *)0x0) break;
LAB_0054c1a0:
    unaff_s3 = (X509_ATTRIBUTE *)(uint)(pXStack_ac < unaff_s5);
    pXVar6 = pXStack_ac;
    if (unaff_s3 == (X509_ATTRIBUTE *)0x0) {
      pXVar6 = unaff_s5;
    }
    iVar4 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)
                      (pAVar5,(undefined *)((int)&pXVar22->object + (int)&pXVar6->object));
    pXVar21 = pXVar6;
    if (iVar4 == 0) {
      pXStack_124 = (X509_ATTRIBUTE *)&DAT_00000041;
      iVar4 = 0xef;
      goto LAB_0054c284;
    }
  }
  pXVar6 = (X509_ATTRIBUTE *)((int)&pXVar19->object + (int)aXStack_88[0].value.ptr);
LAB_0054c220:
  pXVar19 = (X509_ATTRIBUTE *)(uint)(pXVar6 < pXVar19);
  if (pXVar19 != (X509_ATTRIBUTE *)0x0) {
    pXStack_124 = (X509_ATTRIBUTE *)&DAT_0000009b;
    iVar4 = 0x106;
    goto LAB_0054c284;
  }
  pXVar19 = pXVar6;
  if (iStack_b0 == 0) goto LAB_0054c324;
  unaff_s5 = (X509_ATTRIBUTE *)((int)pXVar22 - (int)pXVar6);
  goto LAB_0054c08c;
LAB_0054c324:
  if ((int)pXVar19 < 0) {
    pXStack_124 = (X509_ATTRIBUTE *)&DAT_0000009b;
    iVar4 = 0x112;
LAB_0054c284:
    pcStack_1a0 = "a_d2i_fp.c";
    p_Stack_1a4 = (_union_330 *)&DAT_0000006b;
    ERR_put_error(0xd,0x6b,(int)pXStack_124,"a_d2i_fp.c",iVar4);
    pXStack_e4 = pXVar19;
LAB_0054c298:
    (*(code *)PTR_BUF_MEM_free_006a7494)(pAVar5);
    pXVar19 = (X509_ATTRIBUTE *)0xffffffff;
  }
  else {
    xa->object = pAVar5;
    pXStack_e4 = pXVar19;
  }
  goto LAB_0054c2ac;
}

