
uchar ** asn1_d2i_read_bio_constprop_0(undefined4 param_1,int *param_2)

{
  bool bVar1;
  ushort uVar2;
  uint3 uVar3;
  int iVar4;
  int iVar5;
  uchar **ppuVar6;
  ulong uVar7;
  undefined4 uVar8;
  ASN1_VALUE **ppAVar9;
  undefined *puVar10;
  int iVar11;
  ASN1_VALUE *pAVar12;
  ASN1_VALUE *pAVar13;
  ASN1_ITEM *it;
  int *piVar14;
  byte *pbVar15;
  undefined *puVar16;
  uchar *puVar17;
  ASN1_VALUE *val;
  int unaff_s0;
  uchar **unaff_s1;
  uchar **ppuVar18;
  uchar **unaff_s3;
  uchar **ppuVar19;
  uchar ***unaff_s4;
  uchar **unaff_s5;
  int *unaff_s6;
  uchar **ppuVar20;
  undefined auStack_2d6 [10];
  int *piStack_2cc;
  uchar **ppuStack_2c4;
  ASN1_ITEM *pAStack_2c0;
  uchar *puStack_2bc;
  undefined *puStack_2b8;
  code *pcStack_2b4;
  uchar *puStack_290;
  int *piStack_28c;
  uchar **ppuStack_284;
  ASN1_ITEM *pAStack_280;
  undefined *puStack_27c;
  undefined *puStack_278;
  code *pcStack_274;
  uchar *puStack_250;
  ASN1_ITEM *pAStack_24c;
  uchar **ppuStack_248;
  code *pcStack_244;
  undefined *puStack_240;
  code *pcStack_23c;
  undefined *puStack_238;
  code *pcStack_234;
  undefined *puStack_210;
  ASN1_ITEM *pAStack_20c;
  uchar **ppuStack_208;
  code *pcStack_204;
  undefined *puStack_200;
  ASN1_VALUE **ppAStack_1fc;
  undefined *puStack_1f8;
  int iStack_1f4;
  int *piStack_1f0;
  code *pcStack_1ec;
  ASN1_VALUE **ppAStack_1c8;
  code *pcStack_1c4;
  undefined *puStack_1c0;
  uchar **ppuStack_1bc;
  undefined *puStack_1b8;
  ASN1_VALUE **ppAStack_1b4;
  ASN1_ITEM *pAStack_1b0;
  uchar **ppuStack_1ac;
  int *piStack_1a8;
  undefined4 uStack_1a4;
  uchar *puStack_17c;
  uchar *puStack_178;
  code *pcStack_174;
  undefined *puStack_170;
  ASN1_VALUE **ppAStack_16c;
  ASN1_ITEM *pAStack_168;
  uint *puStack_164;
  char *pcStack_160;
  code *pcStack_15c;
  undefined *puStack_148;
  uchar **ppuStack_13c;
  uchar *puStack_134;
  uchar *puStack_130;
  ASN1_ITEM *pAStack_12c;
  undefined *puStack_128;
  int *piStack_124;
  char *pcStack_120;
  code *pcStack_11c;
  undefined *puStack_108;
  uchar **ppuStack_fc;
  int iStack_f4;
  int iStack_f0;
  ASN1_ITEM *pAStack_ec;
  int iStack_e8;
  uchar **ppuStack_e4;
  undefined *puStack_e0;
  code *pcStack_dc;
  int iStack_b4;
  int iStack_b0;
  int iStack_ac;
  int iStack_a8;
  uchar **ppuStack_a4;
  undefined4 uStack_a0;
  uchar **ppuStack_9c;
  uchar ***pppuStack_98;
  code *pcStack_94;
  int local_70;
  uchar **local_6c;
  uchar **local_58 [3];
  uint local_4c;
  uchar *local_48;
  int iStack_44;
  uint local_40 [5];
  int local_2c;
  
  puVar10 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar4 = (*(code *)PTR_BUF_MEM_new_006a749c)();
  if (iVar4 != 0) {
    unaff_s4 = local_58;
    unaff_s6 = &iStack_44;
    ERR_clear_error();
    local_70 = 0;
    ppuVar20 = (uchar **)0x0;
    unaff_s5 = (uchar **)0x0;
    ppuVar18 = (uchar **)0x0;
LAB_0054c08c:
    unaff_s0 = iVar4;
    if (&DAT_00000008 < unaff_s5) goto LAB_0054c0f0;
    while ((unaff_s3 = (uchar **)((int)(ppuVar18 + 2) - (int)ppuVar20), ppuVar20 <= ppuVar18 + 2 &&
           (iVar5 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(iVar4), iVar5 != 0))) {
      iVar5 = (*(code *)PTR_BIO_read_006a74c0)
                        (param_1,(char *)(*(int *)(iVar4 + 4) + (int)ppuVar20),unaff_s3);
      if (iVar5 < 0) {
        if (ppuVar20 == ppuVar18) {
          ppuStack_e4 = (uchar **)0x8e;
          iVar5 = 0xad;
          goto LAB_0054c284;
        }
      }
      else {
        ppuVar6 = (uchar **)(iVar5 + (int)ppuVar20);
        if ((iVar5 != 0) &&
           (bVar1 = ppuVar6 < ppuVar20, unaff_s5 = (uchar **)((int)ppuVar6 - (int)ppuVar18),
           ppuVar20 = ppuVar6, bVar1)) {
          ppuStack_e4 = (uchar **)&DAT_0000009b;
          iVar5 = 0xb2;
          goto LAB_0054c284;
        }
      }
LAB_0054c0f0:
      iVar5 = *(int *)(iVar4 + 4);
      while( true ) {
        puStack_164 = local_40;
        unaff_s3 = (uchar **)(iVar5 + (int)ppuVar18);
        ppuStack_e4 = &local_48;
        pcStack_160 = (char *)unaff_s6;
        local_58[0] = unaff_s3;
        local_4c = ASN1_get_object((uchar **)unaff_s4,(long *)puStack_164,(int *)&local_48,unaff_s6,
                                   (long)unaff_s5);
        if ((local_4c & 0x80) != 0) {
          uVar7 = ERR_peek_error();
          unaff_s1 = ppuVar18;
          if ((uVar7 & 0xfff) != 0x9b) goto LAB_0054c298;
          ERR_clear_error();
        }
        unaff_s3 = (uchar **)((int)local_58[0] - (int)unaff_s3);
        ppuVar18 = (uchar **)((int)ppuVar18 + (int)unaff_s3);
        if ((local_4c & 1) == 0) {
          if ((local_70 != 0) && (local_40[0] == 0)) {
            unaff_s5 = (uchar **)((int)ppuVar20 - (int)ppuVar18);
            if ((local_48 != (uchar *)0x0) || (local_70 = local_70 + -1, local_70 != 0))
            goto LAB_0054c08c;
            goto LAB_0054c324;
          }
          ppuVar6 = (uchar **)(local_40[0] + (int)ppuVar18);
          if (local_40[0] <= (uint)((int)ppuVar20 - (int)ppuVar18)) goto LAB_0054c220;
          unaff_s5 = (uchar **)((int)ppuVar6 - (int)ppuVar20);
          if ((-1 < (int)unaff_s5) && (ppuVar20 <= ppuVar6)) {
            local_6c = (uchar **)&DAT_00004000;
            if (unaff_s5 != (uchar **)0x0) goto LAB_0054c1a0;
            goto LAB_0054c220;
          }
          ppuStack_e4 = (uchar **)&DAT_0000009b;
          iVar5 = 0xe2;
          goto LAB_0054c284;
        }
        unaff_s5 = (uchar **)((int)ppuVar20 - (int)ppuVar18);
        local_70 = local_70 + 1;
        if (unaff_s5 < &DAT_00000009) break;
        iVar5 = *(int *)(iVar4 + 4);
      }
    }
    ppuStack_e4 = (uchar **)&DAT_00000041;
    iVar5 = 0xa8;
    goto LAB_0054c284;
  }
  ppuStack_e4 = (uchar **)&DAT_00000041;
  pcStack_160 = "a_d2i_fp.c";
  puStack_164 = (uint *)&DAT_0000006b;
  ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",0x9e);
  ppuVar18 = (uchar **)0xffffffff;
LAB_0054c2ac:
  if (local_2c == *(int *)puVar10) {
    return ppuVar18;
  }
  pcStack_94 = ASN1_d2i_fp;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_e0 = PTR___stack_chk_guard_006a9ae8;
  iStack_ac = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_a8 = unaff_s0;
  ppuStack_a4 = unaff_s1;
  uStack_a0 = param_1;
  ppuStack_9c = unaff_s3;
  pppuStack_98 = unaff_s4;
  uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar4 = (*(code *)PTR_BIO_new_006a6ea4)(uVar8);
  if (iVar4 == 0) {
    ppAStack_16c = (ASN1_VALUE **)&DAT_00000007;
    pcStack_120 = "a_d2i_fp.c";
    piStack_124 = (int *)&DAT_0000006d;
    ERR_put_error(0xd,0x6d,7,"a_d2i_fp.c",0x4c);
    ppuVar18 = (uchar **)0x0;
  }
  else {
    ppAStack_16c = (ASN1_VALUE **)0x0;
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar4,0x6a);
    piStack_124 = &iStack_b4;
    iStack_b4 = 0;
    ppAVar9 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(iVar4);
    if ((int)ppAVar9 < 0) {
      ppuVar18 = (uchar **)0x0;
      pcStack_120 = (char *)ppuStack_e4;
    }
    else {
      piStack_124 = &iStack_b0;
      iStack_b0 = *(int *)(iStack_b4 + 4);
      ppuVar18 = (uchar **)(*(code *)puStack_164)(pcStack_160);
      ppAStack_16c = ppAVar9;
      pcStack_120 = (char *)ppuStack_e4;
    }
    if (iStack_b4 != 0) {
      (*(code *)PTR_BUF_MEM_free_006a7494)();
    }
    (*(code *)PTR_BIO_free_006a6e70)(iVar4);
    unaff_s0 = iVar4;
    ppuStack_e4 = ppuVar18;
  }
  if (iStack_ac == *(int *)puStack_e0) {
    return ppuVar18;
  }
  pcStack_dc = ASN1_d2i_bio;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_128 = PTR___stack_chk_guard_006a9ae8;
  piVar14 = &iStack_f4;
  puStack_108 = &_gp;
  iStack_f4 = 0;
  pAStack_ec = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  iStack_e8 = unaff_s0;
  ppAVar9 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(ppAStack_16c,piVar14);
  if ((int)ppAVar9 < 0) {
    ppuVar18 = (uchar **)0x0;
  }
  else {
    piVar14 = &iStack_f0;
    iStack_f0 = *(int *)(iStack_f4 + 4);
    ppuVar18 = (uchar **)(*(code *)piStack_124)(pcStack_120,piVar14);
    ppAStack_16c = ppAVar9;
  }
  if (iStack_f4 != 0) {
    ppuStack_fc = ppuVar18;
    (**(code **)(puStack_108 + -0x794c))();
    ppuVar18 = ppuStack_fc;
  }
  if (pAStack_ec == *(ASN1_ITEM **)puStack_128) {
    return ppuVar18;
  }
  pcStack_11c = ASN1_item_d2i_bio;
  pAStack_168 = pAStack_ec;
  (**(code **)(puStack_108 + -0x5330))();
  puStack_1c0 = PTR___stack_chk_guard_006a9ae8;
  ppuStack_1bc = &puStack_134;
  puStack_148 = &_gp;
  puStack_134 = (uchar *)0x0;
  pAStack_12c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  ppAStack_1fc = ppAStack_16c;
  ppAVar9 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(piVar14);
  if ((int)ppAVar9 < 0) {
    ppuVar18 = (uchar **)0x0;
  }
  else {
    ppuStack_1bc = &puStack_130;
    puStack_130 = *(uchar **)(puStack_134 + 4);
    ppuVar18 = (uchar **)ASN1_item_d2i(ppAStack_16c,ppuStack_1bc,(long)ppAVar9,pAStack_168);
    ppAStack_1fc = ppAVar9;
  }
  if (puStack_134 != (uchar *)0x0) {
    ppuStack_13c = ppuVar18;
    (**(code **)(puStack_148 + -0x794c))();
    ppuVar18 = ppuStack_13c;
  }
  if (pAStack_12c == *(ASN1_ITEM **)puStack_1c0) {
    return ppuVar18;
  }
  pcStack_15c = ASN1_item_d2i_fp;
  pAStack_1b0 = pAStack_12c;
  (**(code **)(puStack_148 + -0x5330))();
  puStack_27c = PTR___stack_chk_guard_006a9ae8;
  puStack_170 = puStack_1c0;
  pcStack_174 = *(code **)PTR___stack_chk_guard_006a9ae8;
  uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar10 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar8);
  if (puVar10 == (undefined *)0x0) {
    iStack_1f4 = 7;
    ppuVar20 = (uchar **)0xce;
    ERR_put_error(0xd,0xce,7,"a_d2i_fp.c",0x85);
    ppuVar18 = (uchar **)0x0;
  }
  else {
    iStack_1f4 = 0;
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar10,0x6a,0,ppuStack_1bc);
    ppuVar20 = &puStack_17c;
    puStack_17c = (uchar *)0x0;
    iVar4 = asn1_d2i_read_bio_constprop_0(puVar10,ppuVar20);
    if (iVar4 < 0) {
      ppuVar18 = (uchar **)0x0;
    }
    else {
      ppuVar20 = &puStack_178;
      puStack_178 = *(uchar **)(puStack_17c + 4);
      ppuVar18 = (uchar **)ASN1_item_d2i(ppAStack_1fc,ppuVar20,iVar4,pAStack_1b0);
      iStack_1f4 = iVar4;
    }
    if (puStack_17c != (uchar *)0x0) {
      (*(code *)PTR_BUF_MEM_free_006a7494)();
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar10);
    puStack_1c0 = puVar10;
    ppuStack_1bc = ppuVar18;
  }
  if (pcStack_174 == *(code **)puStack_27c) {
    return ppuVar18;
  }
  uStack_1a4 = 0x54c854;
  pcStack_204 = pcStack_174;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1f8 = PTR___stack_chk_guard_006a9ae8;
  puStack_1b8 = puStack_27c;
  pcStack_1c4 = *(code **)PTR___stack_chk_guard_006a9ae8;
  ppAStack_1b4 = ppAStack_1fc;
  ppuStack_1ac = unaff_s5;
  piStack_1a8 = unaff_s6;
  uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar10 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar8);
  if (puVar10 == (undefined *)0x0) {
    iVar4 = 7;
    pcStack_23c = (code *)0x75;
    ppuStack_208 = (uchar **)0x0;
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x49);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar10,0x6a,0,ppuVar20);
    iVar5 = (*pcStack_204)(iStack_1f4,0);
    unaff_s6 = (int *)0x670000;
    ppAStack_1fc = (ASN1_VALUE **)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar5,"a_i2d_fp.c",0x5a);
    if (ppAStack_1fc == (ASN1_VALUE **)0x0) {
      iVar4 = 0x41;
      pcStack_23c = (code *)&DAT_00000074;
      ppuStack_208 = (uchar **)0x0;
      ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    }
    else {
      ppAStack_1c8 = ppAStack_1fc;
      (*pcStack_204)(iStack_1f4,&ppAStack_1c8);
      pcStack_204 = (code *)0x0;
      while( true ) {
        pcStack_23c = (code *)((int)ppAStack_1fc + (int)pcStack_204);
        iVar4 = iVar5;
        iVar11 = (*(code *)PTR_BIO_write_006a6e14)(puVar10,pcStack_23c,iVar5);
        if (iVar5 == iVar11) break;
        if (iVar11 < 1) {
          ppuStack_208 = (uchar **)0x0;
          goto LAB_0054c974;
        }
        pcStack_204 = pcStack_204 + iVar11;
        iVar5 = iVar5 - iVar11;
      }
      ppuStack_208 = (uchar **)0x1;
LAB_0054c974:
      (*(code *)PTR_CRYPTO_free_006a6e88)(ppAStack_1fc);
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar10);
    puStack_27c = puVar10;
  }
  if (pcStack_1c4 == *(code **)puStack_1f8) {
    return ppuStack_208;
  }
  pcStack_1ec = ASN1_i2d_bio;
  pcStack_244 = pcStack_1c4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_238 = PTR___stack_chk_guard_006a9ae8;
  pAStack_20c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_200 = puStack_27c;
  piStack_1f0 = unaff_s6;
  ppuStack_248 = (uchar **)(*pcStack_244)(iVar4,0);
  puVar10 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(ppuStack_248,"a_i2d_fp.c",0x5a);
  if (puVar10 == (undefined *)0x0) {
    ppuVar18 = (uchar **)&DAT_00000041;
    puVar16 = &DAT_00000074;
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    ppuVar20 = (uchar **)0x0;
  }
  else {
    puStack_210 = puVar10;
    (*pcStack_244)(iVar4,&puStack_210);
    pcStack_244 = (code *)0x0;
    while( true ) {
      puVar16 = puVar10 + (int)pcStack_244;
      ppuVar18 = ppuStack_248;
      ppuVar20 = (uchar **)(*(code *)PTR_BIO_write_006a6e14)(pcStack_23c,puVar16);
      if (ppuStack_248 == ppuVar20) break;
      if ((int)ppuVar20 < 1) {
        ppuVar20 = (uchar **)0x0;
        goto LAB_0054cb14;
      }
      pcStack_244 = pcStack_244 + (int)ppuVar20;
      ppuStack_248 = (uchar **)((int)ppuStack_248 - (int)ppuVar20);
    }
    ppuVar20 = (uchar **)0x1;
LAB_0054cb14:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar10);
    ppuStack_248 = ppuVar20;
    puStack_27c = puVar10;
  }
  if (pAStack_20c == *(ASN1_ITEM **)puStack_238) {
    return ppuVar20;
  }
  pcStack_234 = ASN1_item_i2d_fp;
  pAStack_2c0 = pAStack_20c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_278 = PTR___stack_chk_guard_006a9ae8;
  pAStack_24c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_240 = puStack_27c;
  uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar10 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar8);
  if (puVar10 == (undefined *)0x0) {
    val = (ASN1_VALUE *)&DAT_00000007;
    puStack_2bc = (uchar *)0xc1;
    ppuStack_2c4 = (uchar **)0x0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7b);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar10,0x6a,0,puVar16);
    puStack_250 = (uchar *)0x0;
    pAVar12 = (ASN1_VALUE *)ASN1_item_i2d((ASN1_VALUE *)ppuVar18,&puStack_250,pAStack_2c0);
    if (puStack_250 == (uchar *)0x0) {
      val = (ASN1_VALUE *)&DAT_00000041;
      puStack_2bc = &DAT_000000c0;
      ppuStack_2c4 = (uchar **)0x0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    }
    else {
      pAStack_2c0 = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_2bc = puStack_250 + (int)pAStack_2c0;
        val = pAVar12;
        pAVar13 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(puVar10);
        if (pAVar12 == pAVar13) break;
        if ((int)pAVar13 < 1) {
          ppuStack_2c4 = (uchar **)0x0;
          puStack_2bc = puStack_250;
          goto LAB_0054cc80;
        }
        pAStack_2c0 = (ASN1_ITEM *)(pAVar13 + (int)&pAStack_2c0->itype);
        pAVar12 = pAVar12 + -(int)pAVar13;
      }
      ppuStack_2c4 = (uchar **)0x1;
LAB_0054cc80:
      (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_250);
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar10);
    puStack_27c = puVar10;
  }
  if (pAStack_24c == *(ASN1_ITEM **)puStack_278) {
    return ppuStack_2c4;
  }
  pcStack_274 = ASN1_item_i2d_bio;
  it = pAStack_24c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_2b8 = PTR___stack_chk_guard_006a9ae8;
  puStack_290 = (uchar *)0x0;
  piStack_28c = *(int **)PTR___stack_chk_guard_006a9ae8;
  ppuStack_284 = ppuStack_2c4;
  pAStack_280 = pAStack_2c0;
  iVar4 = ASN1_item_i2d(val,&puStack_290,it);
  if (puStack_290 == (uchar *)0x0) {
    puVar17 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    ppuVar18 = (uchar **)0x0;
  }
  else {
    pAStack_2c0 = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar17 = puStack_290 + (int)pAStack_2c0;
      iVar5 = (*(code *)PTR_BIO_write_006a6e14)(puStack_2bc,puVar17,iVar4);
      if (iVar4 == iVar5) break;
      if (iVar5 < 1) {
        ppuVar18 = (uchar **)0x0;
        puVar17 = puStack_290;
        goto LAB_0054cde0;
      }
      pAStack_2c0 = (ASN1_ITEM *)(&pAStack_2c0->itype + iVar5);
      iVar4 = iVar4 - iVar5;
    }
    ppuVar18 = (uchar **)0x1;
LAB_0054cde0:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_290);
    ppuStack_2c4 = ppuVar18;
  }
  if (piStack_28c == *(int **)puStack_2b8) {
    return ppuVar18;
  }
  pcStack_2b4 = ASN1_ENUMERATED_set;
  piVar14 = piStack_28c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar10 = PTR___stack_chk_guard_006a9ae8;
  piVar14[1] = 10;
  piStack_2cc = *(int **)puVar10;
  if (*piVar14 < 5) {
    if (piVar14[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar16 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(5,"a_enum.c",0x51);
    piVar14[2] = (int)puVar16;
    if (puVar16 != (undefined *)0x0) {
      *puVar16 = 0;
      puVar16[1] = 0;
      puVar16[2] = 0;
      puVar16[3] = 0;
      puVar16[4] = 0;
      goto LAB_0054cf00;
    }
  }
  else {
LAB_0054cf00:
    puVar16 = (undefined *)piVar14[2];
    if (puVar16 != (undefined *)0x0) {
      if ((int)puVar17 < 0) {
        puVar17 = (uchar *)-(int)puVar17;
        piVar14[1] = 0x10a;
LAB_0054cf1c:
        auStack_2d6[2] = (char)puVar17;
        if ((int)puVar17 >> 8 == 0) {
          iVar4 = 1;
LAB_0054cff0:
          iVar5 = iVar4 + -1;
          *puVar16 = auStack_2d6[iVar4 + 1];
          if (iVar4 != 1) {
            iVar11 = iVar4 + -3;
            *(undefined *)(piVar14[2] + 1) = auStack_2d6[iVar4];
            if (iVar11 == -1) goto LAB_0054cf80;
            goto LAB_0054cf58;
          }
        }
        else {
          auStack_2d6[3] = (char)((uint)puVar17 >> 8);
          if ((int)puVar17 >> 0x10 == 0) {
            iVar4 = 2;
            goto LAB_0054cff0;
          }
          auStack_2d6[4] = (undefined)((uint)puVar17 >> 0x10);
          if ((int)puVar17 >> 0x18 == 0) {
            iVar4 = 3;
            goto LAB_0054cff0;
          }
          auStack_2d6[5] = (undefined)((uint)puVar17 >> 0x18);
          *puVar16 = auStack_2d6[5];
          iVar5 = 3;
          iVar11 = 1;
          *(undefined *)(piVar14[2] + 1) = auStack_2d6[4];
LAB_0054cf58:
          *(undefined *)(piVar14[2] + 2) = auStack_2d6[iVar11 + 2];
          if (iVar11 != 0) {
            *(char *)(piVar14[2] + 3) = (char)puVar17;
          }
        }
        iVar4 = iVar5 + 1;
      }
      else {
        iVar4 = 0;
        if (puVar17 != (uchar *)0x0) goto LAB_0054cf1c;
      }
LAB_0054cf80:
      ppuVar18 = (uchar **)0x1;
      *piVar14 = iVar4;
      goto LAB_0054cf88;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x55);
  ppuVar18 = (uchar **)0x0;
LAB_0054cf88:
  if (piStack_2cc == *(int **)puVar10) {
    return ppuVar18;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piStack_2cc != (int *)0x0) {
    if (piStack_2cc[1] == 0x10a) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
      if (piStack_2cc[1] != 10) {
        return (uchar **)0xffffffff;
      }
    }
    iVar4 = *piStack_2cc;
    if (4 < iVar4) {
      return (uchar **)0xffffffff;
    }
    pbVar15 = (byte *)piStack_2cc[2];
    if (pbVar15 != (byte *)0x0) {
      if (iVar4 < 1) {
        ppuVar18 = (uchar **)0x0;
      }
      else {
        ppuVar18 = (uchar **)(uint)*pbVar15;
        if (iVar4 != 1) {
          uVar2 = CONCAT11(*pbVar15,pbVar15[1]);
          ppuVar18 = (uchar **)(uint)uVar2;
          if (iVar4 != 2) {
            uVar3 = CONCAT21(uVar2,pbVar15[2]);
            ppuVar18 = (uchar **)(uint)uVar3;
            if (iVar4 == 4) {
              ppuVar18 = (uchar **)CONCAT31(uVar3,pbVar15[3]);
            }
          }
        }
      }
      if (!bVar1) {
        return ppuVar18;
      }
      return (uchar **)-(int)ppuVar18;
    }
  }
  return (uchar **)0x0;
  while( true ) {
    do {
      puStack_164 = (uint *)(*(int *)(iVar4 + 4) + (int)ppuVar20);
      ppuStack_e4 = ppuVar19;
      iVar5 = (*(code *)PTR_BIO_read_006a74c0)(param_1);
      if (iVar5 < 1) {
        ppuStack_e4 = (uchar **)0x8e;
        iVar5 = 0xf7;
        unaff_s3 = ppuVar19;
        goto LAB_0054c284;
      }
      unaff_s3 = (uchar **)((int)ppuVar19 - iVar5);
      ppuVar20 = (uchar **)((int)ppuVar20 + iVar5);
      ppuVar19 = unaff_s3;
    } while (unaff_s3 != (uchar **)0x0);
    unaff_s5 = (uchar **)((int)unaff_s5 - (int)ppuVar6);
    local_6c = (uchar **)((int)local_6c << (local_6c < (uchar **)0x3fffffff));
    if (unaff_s5 == (uchar **)0x0) break;
LAB_0054c1a0:
    unaff_s3 = (uchar **)(uint)(local_6c < unaff_s5);
    ppuVar6 = local_6c;
    if (unaff_s3 == (uchar **)0x0) {
      ppuVar6 = unaff_s5;
    }
    iVar5 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(iVar4,(char *)((int)ppuVar6 + (int)ppuVar20))
    ;
    ppuVar19 = ppuVar6;
    if (iVar5 == 0) {
      ppuStack_e4 = (uchar **)&DAT_00000041;
      iVar5 = 0xef;
      goto LAB_0054c284;
    }
  }
  ppuVar6 = (uchar **)((int)ppuVar18 + local_40[0]);
LAB_0054c220:
  ppuVar18 = (uchar **)(uint)(ppuVar6 < ppuVar18);
  if (ppuVar18 != (uchar **)0x0) {
    ppuStack_e4 = (uchar **)&DAT_0000009b;
    iVar5 = 0x106;
    goto LAB_0054c284;
  }
  ppuVar18 = ppuVar6;
  if (local_70 == 0) goto LAB_0054c324;
  unaff_s5 = (uchar **)((int)ppuVar20 - (int)ppuVar6);
  goto LAB_0054c08c;
LAB_0054c324:
  if ((int)ppuVar18 < 0) {
    ppuStack_e4 = (uchar **)&DAT_0000009b;
    iVar5 = 0x112;
LAB_0054c284:
    pcStack_160 = "a_d2i_fp.c";
    puStack_164 = (uint *)&DAT_0000006b;
    ERR_put_error(0xd,0x6b,(int)ppuStack_e4,"a_d2i_fp.c",iVar5);
    unaff_s1 = ppuVar18;
LAB_0054c298:
    (*(code *)PTR_BUF_MEM_free_006a7494)(iVar4);
    ppuVar18 = (uchar **)0xffffffff;
  }
  else {
    *param_2 = iVar4;
    unaff_s1 = ppuVar18;
  }
  goto LAB_0054c2ac;
}

