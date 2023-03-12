
uchar ** asn1_d2i_read_bio_constprop_0(undefined4 param_1,int *param_2)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uchar **ppuVar6;
  ulong uVar7;
  undefined4 uVar8;
  ASN1_VALUE **ppAVar9;
  uchar **ppuVar10;
  undefined *puVar11;
  int iVar12;
  ASN1_VALUE *pAVar13;
  ASN1_VALUE *pAVar14;
  ASN1_ITEM *it;
  int *piVar15;
  byte *pbVar16;
  undefined *puVar17;
  uchar *puVar18;
  ASN1_VALUE *val;
  uchar **unaff_s0;
  uchar **unaff_s1;
  uchar **unaff_s2;
  uchar **ppuVar19;
  int unaff_s3;
  uchar ***unaff_s5;
  int *unaff_s6;
  undefined auStack_2ce [10];
  int *piStack_2c4;
  uchar **ppuStack_2bc;
  ASN1_ITEM *pAStack_2b8;
  uchar *puStack_2b4;
  undefined *puStack_2b0;
  code *pcStack_2ac;
  uchar *puStack_288;
  int *piStack_284;
  uchar **ppuStack_27c;
  ASN1_ITEM *pAStack_278;
  undefined *puStack_274;
  undefined *puStack_270;
  code *pcStack_26c;
  uchar *puStack_248;
  ASN1_ITEM *pAStack_244;
  uchar **ppuStack_240;
  code *pcStack_23c;
  undefined *puStack_238;
  code *pcStack_234;
  undefined *puStack_230;
  code *pcStack_22c;
  undefined *puStack_208;
  ASN1_ITEM *pAStack_204;
  uchar **ppuStack_200;
  code *pcStack_1fc;
  undefined *puStack_1f8;
  ASN1_VALUE **ppAStack_1f4;
  undefined *puStack_1f0;
  int iStack_1ec;
  int *piStack_1e8;
  code *pcStack_1e4;
  ASN1_VALUE **ppAStack_1c0;
  code *pcStack_1bc;
  undefined *puStack_1b8;
  uchar **ppuStack_1b4;
  undefined *puStack_1b0;
  ASN1_VALUE **ppAStack_1ac;
  ASN1_ITEM *pAStack_1a8;
  uchar ***pppuStack_1a4;
  int *piStack_1a0;
  code *pcStack_19c;
  uchar *puStack_174;
  uchar *puStack_170;
  code *pcStack_16c;
  undefined *puStack_168;
  ASN1_VALUE **ppAStack_164;
  ASN1_ITEM *pAStack_160;
  uchar **ppuStack_15c;
  char *pcStack_158;
  code *pcStack_154;
  undefined *puStack_140;
  uchar **ppuStack_134;
  uchar *puStack_12c;
  uchar *puStack_128;
  ASN1_ITEM *pAStack_124;
  undefined *puStack_120;
  int *piStack_11c;
  char *pcStack_118;
  code *pcStack_114;
  undefined *puStack_100;
  uchar **ppuStack_f4;
  int iStack_ec;
  int iStack_e8;
  ASN1_ITEM *pAStack_e4;
  uchar **ppuStack_e0;
  uchar **ppuStack_dc;
  undefined *puStack_d8;
  code *pcStack_d4;
  int iStack_ac;
  int iStack_a8;
  int iStack_a4;
  uchar **ppuStack_a0;
  uchar **ppuStack_9c;
  uchar **ppuStack_98;
  int iStack_94;
  undefined4 uStack_90;
  code *pcStack_8c;
  int local_68;
  uchar **local_58 [3];
  uint local_4c;
  uchar *local_48;
  int iStack_44;
  uchar *local_40 [5];
  int local_2c;
  
  puVar11 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar4 = (*(code *)PTR_BUF_MEM_new_006a859c)();
  if (iVar4 != 0) {
    unaff_s5 = local_58;
    unaff_s6 = &iStack_44;
    ERR_clear_error();
    unaff_s0 = (uchar **)0x0;
    local_68 = 0;
    unaff_s1 = (uchar **)0x0;
    ppuVar6 = (uchar **)0x0;
LAB_0054f334:
    ppuVar10 = unaff_s0;
    ppuVar19 = ppuVar6;
    unaff_s3 = iVar4;
    if (&DAT_00000008 < unaff_s1) goto LAB_0054f39c;
    while ((unaff_s0 <= ppuVar19 + 2 &&
           (iVar5 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(iVar4), iVar5 != 0))) {
      iVar5 = (*(code *)PTR_BIO_read_006a85bc)
                        (param_1,(code *)(*(int *)(iVar4 + 4) + (int)unaff_s0),
                         (int)(ppuVar19 + 2) - (int)unaff_s0);
      ppuVar10 = unaff_s0;
      if (iVar5 < 0) {
        if (unaff_s0 == ppuVar19) {
          ppuStack_dc = (uchar **)0x8e;
          iVar5 = 0xaf;
          goto LAB_0054f554;
        }
      }
      else {
        ppuVar6 = (uchar **)(iVar5 + (int)unaff_s0);
        if (iVar5 != 0) {
          unaff_s0 = (uchar **)(uint)(ppuVar6 < unaff_s0);
          unaff_s1 = (uchar **)((int)ppuVar6 - (int)ppuVar19);
          ppuVar10 = ppuVar6;
          if (unaff_s0 != (uchar **)0x0) {
            ppuStack_dc = (uchar **)0x9b;
            iVar5 = 0xb6;
            goto LAB_0054f554;
          }
        }
      }
LAB_0054f39c:
      unaff_s0 = ppuVar10;
      iVar5 = *(int *)(iVar4 + 4);
      while( true ) {
        ppuVar6 = (uchar **)(iVar5 + (int)ppuVar19);
        ppuStack_15c = local_40;
        ppuStack_dc = &local_48;
        pcStack_158 = (char *)unaff_s6;
        local_58[0] = ppuVar6;
        local_4c = ASN1_get_object((uchar **)unaff_s5,(long *)local_40,(int *)&local_48,unaff_s6,
                                   (long)unaff_s1);
        if ((local_4c & 0x80) != 0) {
          uVar7 = ERR_peek_error();
          unaff_s1 = ppuVar6;
          unaff_s2 = ppuVar19;
          if ((uVar7 & 0xfff) != 0x9b) goto LAB_0054f568;
          ERR_clear_error();
        }
        unaff_s1 = (uchar **)((int)local_58[0] - (int)ppuVar6);
        ppuVar19 = (uchar **)((int)ppuVar19 + (int)unaff_s1);
        if ((local_4c & 1) == 0) {
          if ((local_68 != 0) && (local_40[0] == (uchar *)0x0)) {
            unaff_s1 = (uchar **)((int)unaff_s0 - (int)ppuVar19);
            ppuVar6 = ppuVar19;
            if ((local_48 != (uchar *)0x0) || (local_68 = local_68 + -1, local_68 != 0))
            goto LAB_0054f334;
            goto LAB_0054f43c;
          }
          if (local_40[0] <= (uchar *)((int)unaff_s0 - (int)ppuVar19)) goto LAB_0054f4cc;
          unaff_s1 = (uchar **)((int)(local_40[0] + (int)ppuVar19) - (int)unaff_s0);
          if (((int)unaff_s1 < 0) || (local_40[0] + (int)ppuVar19 < unaff_s0)) {
            ppuStack_dc = (uchar **)0x9b;
            iVar5 = 0xed;
          }
          else {
            iVar5 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(iVar4);
            if (iVar5 != 0) goto joined_r0x0054f494;
            ppuStack_dc = (uchar **)&DAT_00000041;
            iVar5 = 0xf2;
          }
          goto LAB_0054f554;
        }
        unaff_s1 = (uchar **)((int)unaff_s0 - (int)ppuVar19);
        local_68 = local_68 + 1;
        if (unaff_s1 < &DAT_00000009) break;
        iVar5 = *(int *)(iVar4 + 4);
      }
    }
    ppuStack_dc = (uchar **)&DAT_00000041;
    iVar5 = 0xa9;
    goto LAB_0054f554;
  }
  ppuStack_dc = (uchar **)&DAT_00000041;
  pcStack_158 = "a_d2i_fp.c";
  ppuStack_15c = (uchar **)&DAT_0000006b;
  ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",0x9c);
  ppuVar19 = (uchar **)0xffffffff;
LAB_0054f57c:
  if (local_2c == *(int *)puVar11) {
    return ppuVar19;
  }
  pcStack_8c = ASN1_d2i_fp;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_d8 = PTR___stack_chk_guard_006aabf0;
  iStack_a4 = *(int *)PTR___stack_chk_guard_006aabf0;
  ppuStack_a0 = unaff_s0;
  ppuStack_9c = unaff_s1;
  ppuStack_98 = unaff_s2;
  iStack_94 = unaff_s3;
  uStack_90 = param_1;
  uVar8 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  ppuVar6 = (uchar **)(*(code *)PTR_BIO_new_006a7fa4)(uVar8);
  if (ppuVar6 == (uchar **)0x0) {
    ppAStack_164 = (ASN1_VALUE **)&DAT_00000007;
    pcStack_118 = "a_d2i_fp.c";
    piStack_11c = (int *)&DAT_0000006d;
    ERR_put_error(0xd,0x6d,7,"a_d2i_fp.c",0x4d);
    ppuVar10 = (uchar **)0x0;
  }
  else {
    ppAStack_164 = (ASN1_VALUE **)0x0;
    (*(code *)PTR_BIO_ctrl_006a7f18)(ppuVar6,0x6a);
    piStack_11c = &iStack_ac;
    iStack_ac = 0;
    ppAVar9 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(ppuVar6);
    if ((int)ppAVar9 < 0) {
      ppuVar10 = (uchar **)0x0;
      pcStack_118 = (char *)ppuStack_dc;
    }
    else {
      piStack_11c = &iStack_a8;
      iStack_a8 = *(int *)(iStack_ac + 4);
      ppuVar10 = (uchar **)(*(code *)ppuStack_15c)(pcStack_158);
      ppAStack_164 = ppAVar9;
      pcStack_118 = (char *)ppuStack_dc;
    }
    if (iStack_ac != 0) {
      (*(code *)PTR_BUF_MEM_free_006a8594)();
    }
    (*(code *)PTR_BIO_free_006a7f70)(ppuVar6);
    unaff_s0 = ppuVar6;
    ppuStack_dc = ppuVar10;
  }
  if (iStack_a4 == *(int *)puStack_d8) {
    return ppuVar10;
  }
  pcStack_d4 = ASN1_d2i_bio;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_120 = PTR___stack_chk_guard_006aabf0;
  piVar15 = &iStack_ec;
  puStack_100 = &_gp;
  iStack_ec = 0;
  pAStack_e4 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  ppuStack_e0 = unaff_s0;
  ppAVar9 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(ppAStack_164,piVar15);
  if ((int)ppAVar9 < 0) {
    ppuVar6 = (uchar **)0x0;
  }
  else {
    piVar15 = &iStack_e8;
    iStack_e8 = *(int *)(iStack_ec + 4);
    ppuVar6 = (uchar **)(*(code *)piStack_11c)(pcStack_118,piVar15);
    ppAStack_164 = ppAVar9;
  }
  if (iStack_ec != 0) {
    ppuStack_f4 = ppuVar6;
    (**(code **)(puStack_100 + -0x794c))();
    ppuVar6 = ppuStack_f4;
  }
  if (pAStack_e4 == *(ASN1_ITEM **)puStack_120) {
    return ppuVar6;
  }
  pcStack_114 = ASN1_item_d2i_bio;
  pAStack_160 = pAStack_e4;
  (**(code **)(puStack_100 + -0x5328))();
  puStack_1b8 = PTR___stack_chk_guard_006aabf0;
  ppuStack_1b4 = &puStack_12c;
  puStack_140 = &_gp;
  puStack_12c = (uchar *)0x0;
  pAStack_124 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  ppAStack_1f4 = ppAStack_164;
  ppAVar9 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(piVar15);
  if ((int)ppAVar9 < 0) {
    ppuVar6 = (uchar **)0x0;
  }
  else {
    ppuStack_1b4 = &puStack_128;
    puStack_128 = *(uchar **)(puStack_12c + 4);
    ppuVar6 = (uchar **)ASN1_item_d2i(ppAStack_164,ppuStack_1b4,(long)ppAVar9,pAStack_160);
    ppAStack_1f4 = ppAVar9;
  }
  if (puStack_12c != (uchar *)0x0) {
    ppuStack_134 = ppuVar6;
    (**(code **)(puStack_140 + -0x794c))();
    ppuVar6 = ppuStack_134;
  }
  if (pAStack_124 == *(ASN1_ITEM **)puStack_1b8) {
    return ppuVar6;
  }
  pcStack_154 = ASN1_item_d2i_fp;
  pAStack_1a8 = pAStack_124;
  (**(code **)(puStack_140 + -0x5328))();
  puStack_274 = PTR___stack_chk_guard_006aabf0;
  puStack_168 = puStack_1b8;
  pcStack_16c = *(code **)PTR___stack_chk_guard_006aabf0;
  uVar8 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar11 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar8);
  if (puVar11 == (undefined *)0x0) {
    iStack_1ec = 7;
    ppuVar10 = (uchar **)0xce;
    ERR_put_error(0xd,0xce,7,"a_d2i_fp.c",0x83);
    ppuVar6 = (uchar **)0x0;
  }
  else {
    iStack_1ec = 0;
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar11,0x6a,0,ppuStack_1b4);
    ppuVar10 = &puStack_174;
    puStack_174 = (uchar *)0x0;
    iVar4 = asn1_d2i_read_bio_constprop_0(puVar11,ppuVar10);
    if (iVar4 < 0) {
      ppuVar6 = (uchar **)0x0;
    }
    else {
      ppuVar10 = &puStack_170;
      puStack_170 = *(uchar **)(puStack_174 + 4);
      ppuVar6 = (uchar **)ASN1_item_d2i(ppAStack_1f4,ppuVar10,iVar4,pAStack_1a8);
      iStack_1ec = iVar4;
    }
    if (puStack_174 != (uchar *)0x0) {
      (*(code *)PTR_BUF_MEM_free_006a8594)();
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar11);
    puStack_1b8 = puVar11;
    ppuStack_1b4 = ppuVar6;
  }
  if (pcStack_16c == *(code **)puStack_274) {
    return ppuVar6;
  }
  pcStack_19c = ASN1_i2d_fp;
  pcStack_1fc = pcStack_16c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1f0 = PTR___stack_chk_guard_006aabf0;
  puStack_1b0 = puStack_274;
  pcStack_1bc = *(code **)PTR___stack_chk_guard_006aabf0;
  ppAStack_1ac = ppAStack_1f4;
  pppuStack_1a4 = unaff_s5;
  piStack_1a0 = unaff_s6;
  uVar8 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar11 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar8);
  if (puVar11 == (undefined *)0x0) {
    iVar4 = 7;
    pcStack_234 = (code *)0x75;
    ppuStack_200 = (uchar **)0x0;
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x4a);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar11,0x6a,0,ppuVar10);
    iVar5 = (*pcStack_1fc)(iStack_1ec,0);
    unaff_s6 = (int *)0x670000;
    ppAStack_1f4 = (ASN1_VALUE **)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar5,"a_i2d_fp.c",0x5b);
    if (ppAStack_1f4 == (ASN1_VALUE **)0x0) {
      iVar4 = 0x41;
      pcStack_234 = (code *)&DAT_00000074;
      ppuStack_200 = (uchar **)0x0;
      ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5e);
    }
    else {
      ppAStack_1c0 = ppAStack_1f4;
      (*pcStack_1fc)(iStack_1ec,&ppAStack_1c0);
      pcStack_1fc = (code *)0x0;
      while( true ) {
        pcStack_234 = (code *)((int)ppAStack_1f4 + (int)pcStack_1fc);
        iVar4 = iVar5;
        iVar12 = (*(code *)PTR_BIO_write_006a7f14)(puVar11,pcStack_234,iVar5);
        if (iVar5 == iVar12) break;
        if (iVar12 < 1) {
          ppuStack_200 = (uchar **)0x0;
          goto LAB_0054fbe4;
        }
        pcStack_1fc = pcStack_1fc + iVar12;
        iVar5 = iVar5 - iVar12;
      }
      ppuStack_200 = (uchar **)0x1;
LAB_0054fbe4:
      (*(code *)PTR_CRYPTO_free_006a7f88)(ppAStack_1f4);
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar11);
    puStack_274 = puVar11;
  }
  if (pcStack_1bc == *(code **)puStack_1f0) {
    return ppuStack_200;
  }
  pcStack_1e4 = ASN1_i2d_bio;
  pcStack_23c = pcStack_1bc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_230 = PTR___stack_chk_guard_006aabf0;
  pAStack_204 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  puStack_1f8 = puStack_274;
  piStack_1e8 = unaff_s6;
  ppuStack_240 = (uchar **)(*pcStack_23c)(iVar4,0);
  puVar11 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(ppuStack_240,"a_i2d_fp.c",0x5b);
  if (puVar11 == (undefined *)0x0) {
    ppuVar6 = (uchar **)&DAT_00000041;
    puVar17 = &DAT_00000074;
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5e);
    ppuVar10 = (uchar **)0x0;
  }
  else {
    puStack_208 = puVar11;
    (*pcStack_23c)(iVar4,&puStack_208);
    pcStack_23c = (code *)0x0;
    while( true ) {
      puVar17 = puVar11 + (int)pcStack_23c;
      ppuVar6 = ppuStack_240;
      ppuVar10 = (uchar **)(*(code *)PTR_BIO_write_006a7f14)(pcStack_234,puVar17);
      if (ppuStack_240 == ppuVar10) break;
      if ((int)ppuVar10 < 1) {
        ppuVar10 = (uchar **)0x0;
        goto LAB_0054fd84;
      }
      pcStack_23c = pcStack_23c + (int)ppuVar10;
      ppuStack_240 = (uchar **)((int)ppuStack_240 - (int)ppuVar10);
    }
    ppuVar10 = (uchar **)0x1;
LAB_0054fd84:
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar11);
    ppuStack_240 = ppuVar10;
    puStack_274 = puVar11;
  }
  if (pAStack_204 == *(ASN1_ITEM **)puStack_230) {
    return ppuVar10;
  }
  pcStack_22c = ASN1_item_i2d_fp;
  pAStack_2b8 = pAStack_204;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_270 = PTR___stack_chk_guard_006aabf0;
  pAStack_244 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  puStack_238 = puStack_274;
  uVar8 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar11 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar8);
  if (puVar11 == (undefined *)0x0) {
    val = (ASN1_VALUE *)&DAT_00000007;
    puStack_2b4 = (uchar *)0xc1;
    ppuStack_2bc = (uchar **)0x0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7f);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar11,0x6a,0,puVar17);
    puStack_248 = (uchar *)0x0;
    pAVar13 = (ASN1_VALUE *)ASN1_item_i2d((ASN1_VALUE *)ppuVar6,&puStack_248,pAStack_2b8);
    if (puStack_248 == (uchar *)0x0) {
      val = (ASN1_VALUE *)&DAT_00000041;
      puStack_2b4 = &DAT_000000c0;
      ppuStack_2bc = (uchar **)0x0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x91);
    }
    else {
      pAStack_2b8 = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_2b4 = puStack_248 + (int)pAStack_2b8;
        val = pAVar13;
        pAVar14 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a7f14)(puVar11);
        if (pAVar13 == pAVar14) break;
        if ((int)pAVar14 < 1) {
          ppuStack_2bc = (uchar **)0x0;
          puStack_2b4 = puStack_248;
          goto LAB_0054fef0;
        }
        pAStack_2b8 = (ASN1_ITEM *)(pAVar14 + (int)&pAStack_2b8->itype);
        pAVar13 = pAVar13 + -(int)pAVar14;
      }
      ppuStack_2bc = (uchar **)0x1;
LAB_0054fef0:
      (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_248);
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar11);
    puStack_274 = puVar11;
  }
  if (pAStack_244 == *(ASN1_ITEM **)puStack_270) {
    return ppuStack_2bc;
  }
  pcStack_26c = ASN1_item_i2d_bio;
  it = pAStack_244;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_2b0 = PTR___stack_chk_guard_006aabf0;
  puStack_288 = (uchar *)0x0;
  piStack_284 = *(int **)PTR___stack_chk_guard_006aabf0;
  ppuStack_27c = ppuStack_2bc;
  pAStack_278 = pAStack_2b8;
  iVar4 = ASN1_item_i2d(val,&puStack_288,it);
  if (puStack_288 == (uchar *)0x0) {
    puVar18 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x91);
    ppuVar6 = (uchar **)0x0;
  }
  else {
    pAStack_2b8 = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar18 = puStack_288 + (int)pAStack_2b8;
      iVar5 = (*(code *)PTR_BIO_write_006a7f14)(puStack_2b4,puVar18,iVar4);
      if (iVar4 == iVar5) break;
      if (iVar5 < 1) {
        ppuVar6 = (uchar **)0x0;
        puVar18 = puStack_288;
        goto LAB_00550050;
      }
      pAStack_2b8 = (ASN1_ITEM *)(&pAStack_2b8->itype + iVar5);
      iVar4 = iVar4 - iVar5;
    }
    ppuVar6 = (uchar **)0x1;
LAB_00550050:
    (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_288);
    ppuStack_2bc = ppuVar6;
  }
  if (piStack_284 == *(int **)puStack_2b0) {
    return ppuVar6;
  }
  pcStack_2ac = ASN1_ENUMERATED_set;
  piVar15 = piStack_284;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar11 = PTR___stack_chk_guard_006aabf0;
  piVar15[1] = 10;
  piStack_2c4 = *(int **)puVar11;
  if (*piVar15 < 5) {
    if (piVar15[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    puVar17 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(5,"a_enum.c",0x51);
    piVar15[2] = (int)puVar17;
    if (puVar17 != (undefined *)0x0) {
      *puVar17 = 0;
      puVar17[1] = 0;
      puVar17[2] = 0;
      puVar17[3] = 0;
      puVar17[4] = 0;
      goto LAB_00550170;
    }
  }
  else {
LAB_00550170:
    puVar17 = (undefined *)piVar15[2];
    if (puVar17 != (undefined *)0x0) {
      if ((int)puVar18 < 0) {
        puVar18 = (uchar *)-(int)puVar18;
        piVar15[1] = 0x10a;
LAB_0055018c:
        auStack_2ce[2] = (char)puVar18;
        if ((int)puVar18 >> 8 == 0) {
          iVar4 = 1;
LAB_00550260:
          iVar5 = iVar4 + -1;
          *puVar17 = auStack_2ce[iVar4 + 1];
          if (iVar4 != 1) {
            iVar12 = iVar4 + -3;
            *(undefined *)(piVar15[2] + 1) = auStack_2ce[iVar4];
            if (iVar12 == -1) goto LAB_005501f0;
            goto LAB_005501c8;
          }
        }
        else {
          auStack_2ce[3] = (char)((uint)puVar18 >> 8);
          if ((int)puVar18 >> 0x10 == 0) {
            iVar4 = 2;
            goto LAB_00550260;
          }
          auStack_2ce[4] = (undefined)((uint)puVar18 >> 0x10);
          if ((int)puVar18 >> 0x18 == 0) {
            iVar4 = 3;
            goto LAB_00550260;
          }
          auStack_2ce[5] = (undefined)((uint)puVar18 >> 0x18);
          *puVar17 = auStack_2ce[5];
          iVar5 = 3;
          iVar12 = 1;
          *(undefined *)(piVar15[2] + 1) = auStack_2ce[4];
LAB_005501c8:
          *(undefined *)(piVar15[2] + 2) = auStack_2ce[iVar12 + 2];
          if (iVar12 != 0) {
            *(char *)(piVar15[2] + 3) = (char)puVar18;
          }
        }
        iVar4 = iVar5 + 1;
      }
      else {
        iVar4 = 0;
        if (puVar18 != (uchar *)0x0) goto LAB_0055018c;
      }
LAB_005501f0:
      ppuVar6 = (uchar **)0x1;
      *piVar15 = iVar4;
      goto LAB_005501f8;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x56);
  ppuVar6 = (uchar **)0x0;
LAB_005501f8:
  if (piStack_2c4 == *(int **)puVar11) {
    return ppuVar6;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (piStack_2c4 != (int *)0x0) {
    if (piStack_2c4[1] == 0x10a) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (piStack_2c4[1] != 10) {
        return (uchar **)0xffffffff;
      }
    }
    iVar4 = *piStack_2c4;
    if (4 < iVar4) {
      return (uchar **)0xffffffff;
    }
    pbVar16 = (byte *)piStack_2c4[2];
    if (pbVar16 != (byte *)0x0) {
      if (iVar4 < 1) {
        ppuVar6 = (uchar **)0x0;
      }
      else {
        ppuVar6 = (uchar **)(uint)*pbVar16;
        if (iVar4 != 1) {
          uVar1 = CONCAT11(*pbVar16,pbVar16[1]);
          ppuVar6 = (uchar **)(uint)uVar1;
          if (iVar4 != 2) {
            uVar2 = CONCAT21(uVar1,pbVar16[2]);
            ppuVar6 = (uchar **)(uint)uVar2;
            if (iVar4 == 4) {
              ppuVar6 = (uchar **)CONCAT31(uVar2,pbVar16[3]);
            }
          }
        }
      }
      if (!bVar3) {
        return ppuVar6;
      }
      return (uchar **)-(int)ppuVar6;
    }
  }
  return (uchar **)0x0;
joined_r0x0054f494:
  if (unaff_s1 == (uchar **)0x0) goto LAB_0054f4cc;
  ppuStack_dc = unaff_s1;
  iVar5 = (*(code *)PTR_BIO_read_006a85bc)(param_1,(code *)(*(int *)(iVar4 + 4) + (int)unaff_s0));
  if (iVar5 < 1) {
    ppuStack_dc = (uchar **)0x8e;
    iVar5 = 0xfb;
    goto LAB_0054f554;
  }
  unaff_s1 = (uchar **)((int)unaff_s1 - iVar5);
  unaff_s0 = (uchar **)((int)unaff_s0 + iVar5);
  goto joined_r0x0054f494;
LAB_0054f4cc:
  ppuVar6 = (uchar **)((int)ppuVar19 + (int)local_40[0]);
  ppuVar19 = (uchar **)(uint)(ppuVar6 < ppuVar19);
  if (ppuVar19 != (uchar **)0x0) {
    ppuStack_dc = (uchar **)0x9b;
    iVar5 = 0x106;
    goto LAB_0054f554;
  }
  ppuVar19 = ppuVar6;
  if (local_68 == 0) goto LAB_0054f43c;
  unaff_s1 = (uchar **)((int)unaff_s0 - (int)ppuVar6);
  goto LAB_0054f334;
LAB_0054f43c:
  pcStack_158 = "7 datafinal";
  if ((int)ppuVar19 < 0) {
    ppuStack_dc = (uchar **)0x9b;
    iVar5 = 0x115;
LAB_0054f554:
    pcStack_158 = "a_d2i_fp.c";
    ppuStack_15c = (uchar **)&DAT_0000006b;
    ERR_put_error(0xd,0x6b,(int)ppuStack_dc,"a_d2i_fp.c",iVar5);
    unaff_s2 = ppuVar19;
LAB_0054f568:
    (*(code *)PTR_BUF_MEM_free_006a8594)(iVar4);
    ppuVar19 = (uchar **)0xffffffff;
  }
  else {
    *param_2 = iVar4;
    ppuStack_15c = ppuVar19;
    unaff_s2 = ppuVar19;
  }
  goto LAB_0054f57c;
}

