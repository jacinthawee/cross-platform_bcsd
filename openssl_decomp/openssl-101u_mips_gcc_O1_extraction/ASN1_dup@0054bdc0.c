
void * ASN1_dup(undefined1 *i2d,undefined1 *d2i,void *x)

{
  bool bVar1;
  ushort uVar2;
  uint3 uVar3;
  int iVar4;
  undefined4 uVar5;
  ASN1_ITEM *pAVar6;
  ASN1_ITEM *pAVar7;
  undefined *puVar8;
  ulong uVar9;
  ASN1_VALUE **ppAVar10;
  int *piVar11;
  void *pvVar12;
  ASN1_VALUE *pAVar13;
  undefined *puVar14;
  uchar **ppuVar15;
  int iVar16;
  int iVar17;
  ASN1_VALUE *pAVar18;
  ASN1_VALUE *pAVar19;
  byte *pbVar20;
  ASN1_ITEM **in;
  uchar **in_00;
  uchar *puVar21;
  ASN1_ITEM *unaff_s0;
  void *unaff_s1;
  undefined *puVar22;
  int *piVar23;
  int **unaff_s4;
  int *unaff_s5;
  int *unaff_s6;
  undefined *puVar24;
  undefined auStack_366 [10];
  int *piStack_35c;
  void *pvStack_354;
  ASN1_ITEM *pAStack_350;
  uchar *puStack_34c;
  undefined *puStack_348;
  code *pcStack_344;
  uchar *puStack_320;
  int *piStack_31c;
  void *pvStack_314;
  ASN1_ITEM *pAStack_310;
  undefined *puStack_30c;
  undefined *puStack_308;
  code *pcStack_304;
  uchar *puStack_2e0;
  ASN1_ITEM *pAStack_2dc;
  ASN1_VALUE *pAStack_2d8;
  code *pcStack_2d4;
  undefined *puStack_2d0;
  code *pcStack_2cc;
  undefined *puStack_2c8;
  code *pcStack_2c4;
  undefined *puStack_2a0;
  ASN1_ITEM *pAStack_29c;
  void *pvStack_298;
  code *pcStack_294;
  undefined *puStack_290;
  ASN1_VALUE **ppAStack_28c;
  undefined *puStack_288;
  int iStack_284;
  int *piStack_280;
  code *pcStack_27c;
  ASN1_VALUE **ppAStack_258;
  code *pcStack_254;
  undefined *puStack_250;
  uchar **ppuStack_24c;
  undefined *puStack_248;
  ASN1_VALUE **ppAStack_244;
  ASN1_ITEM *pAStack_240;
  int *piStack_23c;
  int *piStack_238;
  undefined4 uStack_234;
  uchar *puStack_20c;
  uchar *puStack_208;
  code *pcStack_204;
  undefined *puStack_200;
  ASN1_VALUE **ppAStack_1fc;
  ASN1_ITEM *pAStack_1f8;
  uint *puStack_1f4;
  char *pcStack_1f0;
  code *pcStack_1ec;
  undefined *puStack_1d8;
  ASN1_VALUE *pAStack_1cc;
  uchar *puStack_1c4;
  uchar *puStack_1c0;
  ASN1_ITEM *pAStack_1bc;
  undefined *puStack_1b8;
  int *piStack_1b4;
  char *pcStack_1b0;
  code *pcStack_1ac;
  undefined *puStack_198;
  void *pvStack_18c;
  int iStack_184;
  int iStack_180;
  ASN1_ITEM *pAStack_17c;
  ASN1_ITEM *pAStack_178;
  int *piStack_174;
  undefined *puStack_170;
  code *pcStack_16c;
  int iStack_144;
  int iStack_140;
  int iStack_13c;
  ASN1_ITEM *pAStack_138;
  undefined *puStack_134;
  int iStack_130;
  int *piStack_12c;
  int **ppiStack_128;
  code *pcStack_124;
  int iStack_100;
  int *piStack_fc;
  int *apiStack_e8 [3];
  uint uStack_dc;
  int iStack_d8;
  int iStack_d4;
  uint auStack_d0 [5];
  int iStack_bc;
  ASN1_ITEM *pAStack_b8;
  undefined *puStack_b4;
  undefined *puStack_b0;
  undefined1 *puStack_ac;
  int **ppiStack_a8;
  int *piStack_a4;
  ASN1_ITEM *pAStack_6c;
  ASN1_ITEM *pAStack_68;
  int iStack_64;
  ASN1_ITEM *pAStack_5c;
  void *pvStack_58;
  code *pcStack_54;
  ASN1_ITEM *local_2c;
  ASN1_ITEM *local_28;
  ASN1_ITEM *local_24;
  
  puStack_b0 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  if (x == (void *)0x0) {
    pAVar6 = (ASN1_ITEM *)0x0;
    in = (ASN1_ITEM **)d2i;
  }
  else {
    iVar4 = (*(code *)i2d)(x,0);
    unaff_s5 = (int *)0x670000;
    unaff_s0 = (ASN1_ITEM *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar4 + 10,"a_dup.c",0x4c);
    unaff_s1 = x;
    unaff_s4 = (int **)d2i;
    if (unaff_s0 == (ASN1_ITEM *)0x0) {
      in = (ASN1_ITEM **)&DAT_0000006f;
      ERR_put_error(0xd,0x6f,0x41,"a_dup.c",0x4e);
      pAVar6 = (ASN1_ITEM *)0x0;
    }
    else {
      local_2c = unaff_s0;
      uVar5 = (*(code *)i2d)(x,&local_2c);
      in = &local_28;
      local_28 = unaff_s0;
      pAVar6 = (ASN1_ITEM *)(*(code *)d2i)(0,in,uVar5);
      (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s0);
      unaff_s0 = pAVar6;
    }
  }
  if (local_24 == *(ASN1_ITEM **)puStack_b0) {
    return pAVar6;
  }
  pcStack_54 = ASN1_item_dup;
  pAVar6 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_134 = PTR___stack_chk_guard_006a9ae8;
  pAStack_6c = (ASN1_ITEM *)0x0;
  iStack_64 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAStack_5c = unaff_s0;
  pvStack_58 = unaff_s1;
  if (in == (ASN1_ITEM **)0x0) {
    pAVar7 = (ASN1_ITEM *)0x0;
  }
  else {
    iVar4 = ASN1_item_i2d((ASN1_VALUE *)in,(uchar **)&pAStack_6c,pAVar6);
    if (pAStack_6c == (ASN1_ITEM *)0x0) {
      in = (ASN1_ITEM **)0xbf;
      ERR_put_error(0xd,0xbf,0x41,"a_dup.c",0x6e);
      pAVar7 = (ASN1_ITEM *)0x0;
      unaff_s0 = pAVar6;
    }
    else {
      in = &pAStack_68;
      pAStack_68 = pAStack_6c;
      pAVar7 = (ASN1_ITEM *)ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)in,iVar4,pAVar6);
      (*(code *)PTR_CRYPTO_free_006a6e88)(pAStack_6c);
      unaff_s0 = pAVar7;
    }
  }
  if (iStack_64 == *(int *)puStack_134) {
    return pAVar7;
  }
  iStack_130 = iStack_64;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar14 = PTR___stack_chk_guard_006a9ae8;
  puStack_b4 = puStack_134;
  iStack_bc = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAStack_b8 = unaff_s0;
  puStack_ac = i2d;
  ppiStack_a8 = unaff_s4;
  piStack_a4 = unaff_s5;
  pAVar6 = (ASN1_ITEM *)(*(code *)PTR_BUF_MEM_new_006a749c)();
  if (pAVar6 != (ASN1_ITEM *)0x0) {
    unaff_s4 = apiStack_e8;
    unaff_s6 = &iStack_d4;
    ERR_clear_error();
    iStack_100 = 0;
    puVar24 = (undefined *)0x0;
    unaff_s5 = (int *)0x0;
    puVar22 = (undefined *)0x0;
LAB_0054c08c:
    unaff_s0 = pAVar6;
    if (&DAT_00000008 < unaff_s5) goto LAB_0054c0f0;
    while ((i2d = puVar22 + 8 + -(int)puVar24, puVar24 <= puVar22 + 8 &&
           (iVar4 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(pAVar6), iVar4 != 0))) {
      iVar4 = (*(code *)PTR_BIO_read_006a74c0)(iStack_130,puVar24 + pAVar6->utype,i2d);
      if (iVar4 < 0) {
        if (puVar24 == puVar22) {
          piStack_174 = (int *)0x8e;
          iVar4 = 0xad;
          goto LAB_0054c284;
        }
      }
      else {
        puVar8 = puVar24 + iVar4;
        if ((iVar4 != 0) &&
           (bVar1 = puVar8 < puVar24, unaff_s5 = (int *)(puVar8 + -(int)puVar22), puVar24 = puVar8,
           bVar1)) {
          piStack_174 = (int *)&DAT_0000009b;
          iVar4 = 0xb2;
          goto LAB_0054c284;
        }
      }
LAB_0054c0f0:
      iVar4 = pAVar6->utype;
      while( true ) {
        puStack_1f4 = auStack_d0;
        i2d = puVar22 + iVar4;
        piStack_174 = &iStack_d8;
        pcStack_1f0 = (char *)unaff_s6;
        apiStack_e8[0] = (int *)i2d;
        uStack_dc = ASN1_get_object((uchar **)unaff_s4,(long *)puStack_1f4,&iStack_d8,unaff_s6,
                                    (long)unaff_s5);
        if ((uStack_dc & 0x80) != 0) {
          uVar9 = ERR_peek_error();
          puStack_134 = puVar22;
          if ((uVar9 & 0xfff) != 0x9b) goto LAB_0054c298;
          ERR_clear_error();
        }
        i2d = (undefined1 *)((int)apiStack_e8[0] - (int)i2d);
        puVar22 = puVar22 + (int)i2d;
        if ((uStack_dc & 1) == 0) {
          if ((iStack_100 != 0) && (auStack_d0[0] == 0)) {
            unaff_s5 = (int *)(puVar24 + -(int)puVar22);
            if ((iStack_d8 != 0) || (iStack_100 = iStack_100 + -1, iStack_100 != 0))
            goto LAB_0054c08c;
            goto LAB_0054c324;
          }
          puVar8 = puVar22 + auStack_d0[0];
          if (auStack_d0[0] <= (uint)((int)puVar24 - (int)puVar22)) goto LAB_0054c220;
          unaff_s5 = (int *)(puVar8 + -(int)puVar24);
          if ((-1 < (int)unaff_s5) && (puVar24 <= puVar8)) {
            piStack_fc = (int *)&DAT_00004000;
            if (unaff_s5 != (int *)0x0) goto LAB_0054c1a0;
            goto LAB_0054c220;
          }
          piStack_174 = (int *)&DAT_0000009b;
          iVar4 = 0xe2;
          goto LAB_0054c284;
        }
        unaff_s5 = (int *)(puVar24 + -(int)puVar22);
        iStack_100 = iStack_100 + 1;
        if (unaff_s5 < &DAT_00000009) break;
        iVar4 = pAVar6->utype;
      }
    }
    piStack_174 = (int *)&DAT_00000041;
    iVar4 = 0xa8;
    goto LAB_0054c284;
  }
  piStack_174 = (int *)&DAT_00000041;
  pcStack_1f0 = "a_d2i_fp.c";
  puStack_1f4 = (uint *)&DAT_0000006b;
  ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",0x9e);
  puVar22 = (undefined *)0xffffffff;
LAB_0054c2ac:
  if (iStack_bc == *(int *)puVar14) {
    return puVar22;
  }
  pcStack_124 = ASN1_d2i_fp;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_170 = PTR___stack_chk_guard_006a9ae8;
  iStack_13c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAStack_138 = unaff_s0;
  piStack_12c = (int *)i2d;
  ppiStack_128 = unaff_s4;
  uVar5 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  pAVar6 = (ASN1_ITEM *)(*(code *)PTR_BIO_new_006a6ea4)(uVar5);
  if (pAVar6 == (ASN1_ITEM *)0x0) {
    ppAStack_1fc = (ASN1_VALUE **)&DAT_00000007;
    pcStack_1b0 = "a_d2i_fp.c";
    piStack_1b4 = (int *)&DAT_0000006d;
    ERR_put_error(0xd,0x6d,7,"a_d2i_fp.c",0x4c);
    piVar11 = (int *)0x0;
  }
  else {
    ppAStack_1fc = (ASN1_VALUE **)0x0;
    (*(code *)PTR_BIO_ctrl_006a6e18)(pAVar6,0x6a);
    piStack_1b4 = &iStack_144;
    iStack_144 = 0;
    ppAVar10 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(pAVar6);
    if ((int)ppAVar10 < 0) {
      piVar11 = (int *)0x0;
      pcStack_1b0 = (char *)piStack_174;
    }
    else {
      piStack_1b4 = &iStack_140;
      iStack_140 = *(int *)(iStack_144 + 4);
      piVar11 = (int *)(*(code *)puStack_1f4)(pcStack_1f0);
      ppAStack_1fc = ppAVar10;
      pcStack_1b0 = (char *)piStack_174;
    }
    if (iStack_144 != 0) {
      (*(code *)PTR_BUF_MEM_free_006a7494)();
    }
    (*(code *)PTR_BIO_free_006a6e70)(pAVar6);
    unaff_s0 = pAVar6;
    piStack_174 = piVar11;
  }
  if (iStack_13c == *(int *)puStack_170) {
    return piVar11;
  }
  pcStack_16c = ASN1_d2i_bio;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1b8 = PTR___stack_chk_guard_006a9ae8;
  piVar11 = &iStack_184;
  puStack_198 = &_gp;
  iStack_184 = 0;
  pAStack_17c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pAStack_178 = unaff_s0;
  ppAVar10 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(ppAStack_1fc,piVar11);
  if ((int)ppAVar10 < 0) {
    pvVar12 = (void *)0x0;
  }
  else {
    piVar11 = &iStack_180;
    iStack_180 = *(int *)(iStack_184 + 4);
    pvVar12 = (void *)(*(code *)piStack_1b4)(pcStack_1b0,piVar11);
    ppAStack_1fc = ppAVar10;
  }
  if (iStack_184 != 0) {
    pvStack_18c = pvVar12;
    (**(code **)(puStack_198 + -0x794c))();
    pvVar12 = pvStack_18c;
  }
  if (pAStack_17c == *(ASN1_ITEM **)puStack_1b8) {
    return pvVar12;
  }
  pcStack_1ac = ASN1_item_d2i_bio;
  pAStack_1f8 = pAStack_17c;
  (**(code **)(puStack_198 + -0x5330))();
  puStack_250 = PTR___stack_chk_guard_006a9ae8;
  ppuStack_24c = &puStack_1c4;
  puStack_1d8 = &_gp;
  puStack_1c4 = (uchar *)0x0;
  pAStack_1bc = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  ppAStack_28c = ppAStack_1fc;
  ppAVar10 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(piVar11);
  if ((int)ppAVar10 < 0) {
    pAVar13 = (ASN1_VALUE *)0x0;
  }
  else {
    ppuStack_24c = &puStack_1c0;
    puStack_1c0 = *(uchar **)(puStack_1c4 + 4);
    pAVar13 = ASN1_item_d2i(ppAStack_1fc,ppuStack_24c,(long)ppAVar10,pAStack_1f8);
    ppAStack_28c = ppAVar10;
  }
  if (puStack_1c4 != (uchar *)0x0) {
    pAStack_1cc = pAVar13;
    (**(code **)(puStack_1d8 + -0x794c))();
    pAVar13 = pAStack_1cc;
  }
  if (pAStack_1bc == *(ASN1_ITEM **)puStack_250) {
    return pAVar13;
  }
  pcStack_1ec = ASN1_item_d2i_fp;
  pAStack_240 = pAStack_1bc;
  (**(code **)(puStack_1d8 + -0x5330))();
  puStack_30c = PTR___stack_chk_guard_006a9ae8;
  puStack_200 = puStack_250;
  pcStack_204 = *(code **)PTR___stack_chk_guard_006a9ae8;
  uVar5 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar14 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar5);
  if (puVar14 == (undefined *)0x0) {
    iStack_284 = 7;
    in_00 = (uchar **)0xce;
    ERR_put_error(0xd,0xce,7,"a_d2i_fp.c",0x85);
    ppuVar15 = (uchar **)0x0;
  }
  else {
    iStack_284 = 0;
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar14,0x6a,0,ppuStack_24c);
    in_00 = &puStack_20c;
    puStack_20c = (uchar *)0x0;
    iVar4 = asn1_d2i_read_bio_constprop_0(puVar14,in_00);
    if (iVar4 < 0) {
      ppuVar15 = (uchar **)0x0;
    }
    else {
      in_00 = &puStack_208;
      puStack_208 = *(uchar **)(puStack_20c + 4);
      ppuVar15 = (uchar **)ASN1_item_d2i(ppAStack_28c,in_00,iVar4,pAStack_240);
      iStack_284 = iVar4;
    }
    if (puStack_20c != (uchar *)0x0) {
      (*(code *)PTR_BUF_MEM_free_006a7494)();
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar14);
    puStack_250 = puVar14;
    ppuStack_24c = ppuVar15;
  }
  if (pcStack_204 == *(code **)puStack_30c) {
    return ppuVar15;
  }
  uStack_234 = 0x54c854;
  pcStack_294 = pcStack_204;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_288 = PTR___stack_chk_guard_006a9ae8;
  puStack_248 = puStack_30c;
  pcStack_254 = *(code **)PTR___stack_chk_guard_006a9ae8;
  ppAStack_244 = ppAStack_28c;
  piStack_23c = unaff_s5;
  piStack_238 = unaff_s6;
  uVar5 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar14 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar5);
  if (puVar14 == (undefined *)0x0) {
    iVar4 = 7;
    pcStack_2cc = (code *)0x75;
    pvStack_298 = (void *)0x0;
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x49);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar14,0x6a,0,in_00);
    iVar16 = (*pcStack_294)(iStack_284,0);
    unaff_s6 = (int *)0x670000;
    ppAStack_28c = (ASN1_VALUE **)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar16,"a_i2d_fp.c",0x5a);
    if (ppAStack_28c == (ASN1_VALUE **)0x0) {
      iVar4 = 0x41;
      pcStack_2cc = (code *)&DAT_00000074;
      pvStack_298 = (void *)0x0;
      ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    }
    else {
      ppAStack_258 = ppAStack_28c;
      (*pcStack_294)(iStack_284,&ppAStack_258);
      pcStack_294 = (code *)0x0;
      while( true ) {
        pcStack_2cc = (code *)((int)ppAStack_28c + (int)pcStack_294);
        iVar4 = iVar16;
        iVar17 = (*(code *)PTR_BIO_write_006a6e14)(puVar14,pcStack_2cc,iVar16);
        if (iVar16 == iVar17) break;
        if (iVar17 < 1) {
          pvStack_298 = (void *)0x0;
          goto LAB_0054c974;
        }
        pcStack_294 = pcStack_294 + iVar17;
        iVar16 = iVar16 - iVar17;
      }
      pvStack_298 = (void *)0x1;
LAB_0054c974:
      (*(code *)PTR_CRYPTO_free_006a6e88)(ppAStack_28c);
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar14);
    puStack_30c = puVar14;
  }
  if (pcStack_254 == *(code **)puStack_288) {
    return pvStack_298;
  }
  pcStack_27c = ASN1_i2d_bio;
  pcStack_2d4 = pcStack_254;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_2c8 = PTR___stack_chk_guard_006a9ae8;
  pAStack_29c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_290 = puStack_30c;
  piStack_280 = unaff_s6;
  pAStack_2d8 = (ASN1_VALUE *)(*pcStack_2d4)(iVar4,0);
  puVar14 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(pAStack_2d8,"a_i2d_fp.c",0x5a);
  if (puVar14 == (undefined *)0x0) {
    pAVar13 = (ASN1_VALUE *)&DAT_00000041;
    puVar22 = &DAT_00000074;
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    pAVar18 = (ASN1_VALUE *)0x0;
  }
  else {
    puStack_2a0 = puVar14;
    (*pcStack_2d4)(iVar4,&puStack_2a0);
    pcStack_2d4 = (code *)0x0;
    while( true ) {
      puVar22 = puVar14 + (int)pcStack_2d4;
      pAVar13 = pAStack_2d8;
      pAVar18 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(pcStack_2cc,puVar22);
      if (pAStack_2d8 == pAVar18) break;
      if ((int)pAVar18 < 1) {
        pAVar18 = (ASN1_VALUE *)0x0;
        goto LAB_0054cb14;
      }
      pcStack_2d4 = pcStack_2d4 + (int)pAVar18;
      pAStack_2d8 = pAStack_2d8 + -(int)pAVar18;
    }
    pAVar18 = (ASN1_VALUE *)0x1;
LAB_0054cb14:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar14);
    pAStack_2d8 = pAVar18;
    puStack_30c = puVar14;
  }
  if (pAStack_29c == *(ASN1_ITEM **)puStack_2c8) {
    return pAVar18;
  }
  pcStack_2c4 = ASN1_item_i2d_fp;
  pAStack_350 = pAStack_29c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_308 = PTR___stack_chk_guard_006a9ae8;
  pAStack_2dc = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_2d0 = puStack_30c;
  uVar5 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar14 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar5);
  if (puVar14 == (undefined *)0x0) {
    pAVar13 = (ASN1_VALUE *)&DAT_00000007;
    puStack_34c = (uchar *)0xc1;
    pvStack_354 = (void *)0x0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7b);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar14,0x6a,0,puVar22);
    puStack_2e0 = (uchar *)0x0;
    pAVar18 = (ASN1_VALUE *)ASN1_item_i2d(pAVar13,&puStack_2e0,pAStack_350);
    if (puStack_2e0 == (uchar *)0x0) {
      pAVar13 = (ASN1_VALUE *)&DAT_00000041;
      puStack_34c = &DAT_000000c0;
      pvStack_354 = (void *)0x0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    }
    else {
      pAStack_350 = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_34c = puStack_2e0 + (int)pAStack_350;
        pAVar13 = pAVar18;
        pAVar19 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(puVar14);
        if (pAVar18 == pAVar19) break;
        if ((int)pAVar19 < 1) {
          pvStack_354 = (void *)0x0;
          puStack_34c = puStack_2e0;
          goto LAB_0054cc80;
        }
        pAStack_350 = (ASN1_ITEM *)(pAVar19 + (int)&pAStack_350->itype);
        pAVar18 = pAVar18 + -(int)pAVar19;
      }
      pvStack_354 = (void *)0x1;
LAB_0054cc80:
      (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_2e0);
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar14);
    puStack_30c = puVar14;
  }
  if (pAStack_2dc == *(ASN1_ITEM **)puStack_308) {
    return pvStack_354;
  }
  pcStack_304 = ASN1_item_i2d_bio;
  pAVar6 = pAStack_2dc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_348 = PTR___stack_chk_guard_006a9ae8;
  puStack_320 = (uchar *)0x0;
  piStack_31c = *(int **)PTR___stack_chk_guard_006a9ae8;
  pvStack_314 = pvStack_354;
  pAStack_310 = pAStack_350;
  iVar4 = ASN1_item_i2d(pAVar13,&puStack_320,pAVar6);
  if (puStack_320 == (uchar *)0x0) {
    puVar21 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    pvVar12 = (void *)0x0;
  }
  else {
    pAStack_350 = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar21 = puStack_320 + (int)pAStack_350;
      iVar16 = (*(code *)PTR_BIO_write_006a6e14)(puStack_34c,puVar21,iVar4);
      if (iVar4 == iVar16) break;
      if (iVar16 < 1) {
        pvVar12 = (void *)0x0;
        puVar21 = puStack_320;
        goto LAB_0054cde0;
      }
      pAStack_350 = (ASN1_ITEM *)(&pAStack_350->itype + iVar16);
      iVar4 = iVar4 - iVar16;
    }
    pvVar12 = (void *)0x1;
LAB_0054cde0:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_320);
    pvStack_354 = pvVar12;
  }
  if (piStack_31c == *(int **)puStack_348) {
    return pvVar12;
  }
  pcStack_344 = ASN1_ENUMERATED_set;
  piVar11 = piStack_31c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar14 = PTR___stack_chk_guard_006a9ae8;
  piVar11[1] = 10;
  piStack_35c = *(int **)puVar14;
  if (*piVar11 < 5) {
    if (piVar11[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar22 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(5,"a_enum.c",0x51);
    piVar11[2] = (int)puVar22;
    if (puVar22 != (undefined *)0x0) {
      *puVar22 = 0;
      puVar22[1] = 0;
      puVar22[2] = 0;
      puVar22[3] = 0;
      puVar22[4] = 0;
      goto LAB_0054cf00;
    }
  }
  else {
LAB_0054cf00:
    puVar22 = (undefined *)piVar11[2];
    if (puVar22 != (undefined *)0x0) {
      if ((int)puVar21 < 0) {
        puVar21 = (uchar *)-(int)puVar21;
        piVar11[1] = 0x10a;
LAB_0054cf1c:
        auStack_366[2] = (char)puVar21;
        if ((int)puVar21 >> 8 == 0) {
          iVar4 = 1;
LAB_0054cff0:
          iVar16 = iVar4 + -1;
          *puVar22 = auStack_366[iVar4 + 1];
          if (iVar4 != 1) {
            iVar17 = iVar4 + -3;
            *(undefined *)(piVar11[2] + 1) = auStack_366[iVar4];
            if (iVar17 == -1) goto LAB_0054cf80;
            goto LAB_0054cf58;
          }
        }
        else {
          auStack_366[3] = (char)((uint)puVar21 >> 8);
          if ((int)puVar21 >> 0x10 == 0) {
            iVar4 = 2;
            goto LAB_0054cff0;
          }
          auStack_366[4] = (undefined)((uint)puVar21 >> 0x10);
          if ((int)puVar21 >> 0x18 == 0) {
            iVar4 = 3;
            goto LAB_0054cff0;
          }
          auStack_366[5] = (undefined)((uint)puVar21 >> 0x18);
          *puVar22 = auStack_366[5];
          iVar16 = 3;
          iVar17 = 1;
          *(undefined *)(piVar11[2] + 1) = auStack_366[4];
LAB_0054cf58:
          *(undefined *)(piVar11[2] + 2) = auStack_366[iVar17 + 2];
          if (iVar17 != 0) {
            *(char *)(piVar11[2] + 3) = (char)puVar21;
          }
        }
        iVar4 = iVar16 + 1;
      }
      else {
        iVar4 = 0;
        if (puVar21 != (uchar *)0x0) goto LAB_0054cf1c;
      }
LAB_0054cf80:
      pvVar12 = (void *)0x1;
      *piVar11 = iVar4;
      goto LAB_0054cf88;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x55);
  pvVar12 = (void *)0x0;
LAB_0054cf88:
  if (piStack_35c == *(int **)puVar14) {
    return pvVar12;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piStack_35c != (int *)0x0) {
    if (piStack_35c[1] == 0x10a) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
      if (piStack_35c[1] != 10) {
        return (void *)0xffffffff;
      }
    }
    iVar4 = *piStack_35c;
    if (4 < iVar4) {
      return (void *)0xffffffff;
    }
    pbVar20 = (byte *)piStack_35c[2];
    if (pbVar20 != (byte *)0x0) {
      if (iVar4 < 1) {
        pvVar12 = (void *)0x0;
      }
      else {
        pvVar12 = (void *)(uint)*pbVar20;
        if (iVar4 != 1) {
          uVar2 = CONCAT11(*pbVar20,pbVar20[1]);
          pvVar12 = (void *)(uint)uVar2;
          if (iVar4 != 2) {
            uVar3 = CONCAT21(uVar2,pbVar20[2]);
            pvVar12 = (void *)(uint)uVar3;
            if (iVar4 == 4) {
              pvVar12 = (void *)CONCAT31(uVar3,pbVar20[3]);
            }
          }
        }
      }
      if (!bVar1) {
        return pvVar12;
      }
      return (void *)-(int)pvVar12;
    }
  }
  return (void *)0x0;
  while( true ) {
    do {
      puStack_1f4 = (uint *)(puVar24 + pAVar6->utype);
      piStack_174 = piVar23;
      iVar4 = (*(code *)PTR_BIO_read_006a74c0)(iStack_130);
      if (iVar4 < 1) {
        piStack_174 = (int *)0x8e;
        iVar4 = 0xf7;
        i2d = (undefined1 *)piVar23;
        goto LAB_0054c284;
      }
      i2d = (undefined1 *)((int)piVar23 - iVar4);
      puVar24 = puVar24 + iVar4;
      piVar23 = (int *)i2d;
    } while ((int *)i2d != (int *)0x0);
    unaff_s5 = (int *)((int)unaff_s5 - (int)piVar11);
    piStack_fc = (int *)((int)piStack_fc << (piStack_fc < (int *)0x3fffffff));
    if (unaff_s5 == (int *)0x0) break;
LAB_0054c1a0:
    i2d = (undefined1 *)(uint)(piStack_fc < unaff_s5);
    piVar11 = piStack_fc;
    if ((int *)i2d == (int *)0x0) {
      piVar11 = unaff_s5;
    }
    iVar4 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(pAVar6,(char *)((int)piVar11 + (int)puVar24))
    ;
    piVar23 = piVar11;
    if (iVar4 == 0) {
      piStack_174 = (int *)&DAT_00000041;
      iVar4 = 0xef;
      goto LAB_0054c284;
    }
  }
  puVar8 = puVar22 + auStack_d0[0];
LAB_0054c220:
  puVar22 = (undefined *)(uint)(puVar8 < puVar22);
  if (puVar22 != (undefined *)0x0) {
    piStack_174 = (int *)&DAT_0000009b;
    iVar4 = 0x106;
    goto LAB_0054c284;
  }
  puVar22 = puVar8;
  if (iStack_100 == 0) goto LAB_0054c324;
  unaff_s5 = (int *)(puVar24 + -(int)puVar8);
  goto LAB_0054c08c;
LAB_0054c324:
  if ((int)puVar22 < 0) {
    piStack_174 = (int *)&DAT_0000009b;
    iVar4 = 0x112;
LAB_0054c284:
    pcStack_1f0 = "a_d2i_fp.c";
    puStack_1f4 = (uint *)&DAT_0000006b;
    ERR_put_error(0xd,0x6b,(int)piStack_174,"a_d2i_fp.c",iVar4);
    puStack_134 = puVar22;
LAB_0054c298:
    (*(code *)PTR_BUF_MEM_free_006a7494)(pAVar6);
    puVar22 = (undefined *)0xffffffff;
  }
  else {
    *in = pAVar6;
    puStack_134 = puVar22;
  }
  goto LAB_0054c2ac;
}

