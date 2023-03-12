
void * ASN1_dup(undefined1 *i2d,undefined1 *d2i,void *x)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  ASN1_ITEM *pAVar4;
  int iVar5;
  undefined4 uVar6;
  ASN1_ITEM *pAVar7;
  ASN1_ITEM *pAVar8;
  ulong uVar9;
  ASN1_ITEM *pAVar10;
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
  ASN1_ITEM **in;
  uchar **in_00;
  undefined *puVar23;
  uchar *puVar24;
  ASN1_ITEM *unaff_s0;
  void *unaff_s1;
  undefined1 *unaff_s4;
  uchar **unaff_s5;
  int *unaff_s6;
  undefined auStack_35e [10];
  int *piStack_354;
  void *pvStack_34c;
  ASN1_ITEM *pAStack_348;
  uchar *puStack_344;
  undefined *puStack_340;
  code *pcStack_33c;
  uchar *puStack_318;
  int *piStack_314;
  void *pvStack_30c;
  ASN1_ITEM *pAStack_308;
  undefined *puStack_304;
  undefined *puStack_300;
  code *pcStack_2fc;
  uchar *puStack_2d8;
  ASN1_ITEM *pAStack_2d4;
  ASN1_VALUE *pAStack_2d0;
  code *pcStack_2cc;
  undefined *puStack_2c8;
  code *pcStack_2c4;
  undefined *puStack_2c0;
  code *pcStack_2bc;
  undefined *puStack_298;
  ASN1_ITEM *pAStack_294;
  void *pvStack_290;
  code *pcStack_28c;
  undefined *puStack_288;
  ASN1_VALUE **ppAStack_284;
  undefined *puStack_280;
  int iStack_27c;
  int *piStack_278;
  code *pcStack_274;
  ASN1_VALUE **ppAStack_250;
  code *pcStack_24c;
  undefined *puStack_248;
  uchar **ppuStack_244;
  undefined *puStack_240;
  ASN1_VALUE **ppAStack_23c;
  ASN1_ITEM *pAStack_238;
  uchar **ppuStack_234;
  int *piStack_230;
  code *pcStack_22c;
  uchar *puStack_204;
  uchar *puStack_200;
  code *pcStack_1fc;
  undefined *puStack_1f8;
  ASN1_VALUE **ppAStack_1f4;
  ASN1_ITEM *pAStack_1f0;
  ASN1_ITEM *pAStack_1ec;
  char *pcStack_1e8;
  code *pcStack_1e4;
  undefined *puStack_1d0;
  ASN1_VALUE *pAStack_1c4;
  uchar *puStack_1bc;
  uchar *puStack_1b8;
  ASN1_ITEM *pAStack_1b4;
  undefined *puStack_1b0;
  int *piStack_1ac;
  char *pcStack_1a8;
  code *pcStack_1a4;
  undefined *puStack_190;
  void *pvStack_184;
  int iStack_17c;
  int iStack_178;
  ASN1_ITEM *pAStack_174;
  ASN1_ITEM *pAStack_170;
  char *pcStack_16c;
  undefined *puStack_168;
  code *pcStack_164;
  int iStack_13c;
  int iStack_138;
  int iStack_134;
  ASN1_ITEM *pAStack_130;
  char *pcStack_12c;
  ASN1_ITEM *pAStack_128;
  ASN1_ITEM *pAStack_124;
  int iStack_120;
  code *pcStack_11c;
  int iStack_f8;
  uchar *apuStack_e8 [3];
  uint uStack_dc;
  int iStack_d8;
  int iStack_d4;
  ASN1_ITEM AStack_d0;
  undefined *puStack_b4;
  undefined *puStack_b0;
  undefined1 *puStack_ac;
  undefined1 *puStack_a8;
  uchar **ppuStack_a4;
  ASN1_ITEM *pAStack_6c;
  ASN1_ITEM *pAStack_68;
  int iStack_64;
  ASN1_ITEM *pAStack_5c;
  void *pvStack_58;
  code *pcStack_54;
  ASN1_ITEM *local_2c;
  ASN1_ITEM *local_28;
  ASN1_ITEM *local_24;
  
  pAStack_128 = (ASN1_ITEM *)PTR___stack_chk_guard_006aabf0;
  local_24 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  if (x == (void *)0x0) {
    pAVar7 = (ASN1_ITEM *)0x0;
    in = (ASN1_ITEM **)d2i;
  }
  else {
    iVar5 = (*(code *)i2d)(x,0);
    unaff_s5 = (uchar **)0x670000;
    unaff_s0 = (ASN1_ITEM *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar5 + 10,"a_dup.c",0x4b);
    unaff_s1 = x;
    unaff_s4 = d2i;
    if (unaff_s0 == (ASN1_ITEM *)0x0) {
      in = (ASN1_ITEM **)&DAT_0000006f;
      ERR_put_error(0xd,0x6f,0x41,"a_dup.c",0x4d);
      pAVar7 = (ASN1_ITEM *)0x0;
    }
    else {
      local_2c = unaff_s0;
      uVar6 = (*(code *)i2d)(x,&local_2c);
      in = &local_28;
      local_28 = unaff_s0;
      pAVar7 = (ASN1_ITEM *)(*(code *)d2i)(0,in,uVar6);
      (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s0);
      unaff_s0 = pAVar7;
    }
  }
  if (local_24 == *(ASN1_ITEM **)pAStack_128) {
    return pAVar7;
  }
  pcStack_54 = ASN1_item_dup;
  pAVar7 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pcStack_12c = PTR___stack_chk_guard_006aabf0;
  pAStack_6c = (ASN1_ITEM *)0x0;
  iStack_64 = *(int *)PTR___stack_chk_guard_006aabf0;
  pAStack_5c = unaff_s0;
  pvStack_58 = unaff_s1;
  if (in == (ASN1_ITEM **)0x0) {
    pAVar8 = (ASN1_ITEM *)0x0;
  }
  else {
    iVar5 = ASN1_item_i2d((ASN1_VALUE *)in,(uchar **)&pAStack_6c,pAVar7);
    if (pAStack_6c == (ASN1_ITEM *)0x0) {
      in = (ASN1_ITEM **)0xbf;
      ERR_put_error(0xd,0xbf,0x41,"a_dup.c",0x68);
      pAVar8 = (ASN1_ITEM *)0x0;
      unaff_s0 = pAVar7;
    }
    else {
      in = &pAStack_68;
      pAStack_68 = pAStack_6c;
      pAVar8 = (ASN1_ITEM *)ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)in,iVar5,pAVar7);
      (*(code *)PTR_CRYPTO_free_006a7f88)(pAStack_6c);
      unaff_s0 = pAVar8;
    }
  }
  if (iStack_64 == *(int *)pcStack_12c) {
    return pAVar8;
  }
  iStack_120 = iStack_64;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar15 = PTR___stack_chk_guard_006aabf0;
  puStack_b0 = &pAStack_128->itype;
  puStack_b4 = pcStack_12c;
  AStack_d0.size = *(long *)PTR___stack_chk_guard_006aabf0;
  AStack_d0.sname = &unaff_s0->itype;
  puStack_ac = i2d;
  puStack_a8 = unaff_s4;
  ppuStack_a4 = unaff_s5;
  pAVar7 = (ASN1_ITEM *)(*(code *)PTR_BUF_MEM_new_006a859c)();
  if (pAVar7 != (ASN1_ITEM *)0x0) {
    unaff_s5 = apuStack_e8;
    unaff_s6 = &iStack_d4;
    ERR_clear_error();
    unaff_s0 = (ASN1_ITEM *)0x0;
    iStack_f8 = 0;
    pcStack_12c = (char *)0x0;
    pAVar8 = (ASN1_ITEM *)0x0;
LAB_0054f334:
    pAVar4 = unaff_s0;
    pAVar10 = pAVar8;
    i2d = (undefined1 *)pAVar7;
    if (&DAT_00000008 < pcStack_12c) goto LAB_0054f39c;
    while ((unaff_s0 <= &pAVar10->templates &&
           (iVar5 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(pAVar7), iVar5 != 0))) {
      iVar5 = (*(code *)PTR_BIO_read_006a85bc)
                        (iStack_120,&unaff_s0->itype + pAVar7->utype,
                         (int)&pAVar10->templates - (int)unaff_s0);
      pAVar4 = unaff_s0;
      if (iVar5 < 0) {
        if (unaff_s0 == pAVar10) {
          pcStack_16c = (char *)0x8e;
          iVar5 = 0xaf;
          goto LAB_0054f554;
        }
      }
      else {
        pAVar8 = (ASN1_ITEM *)(&unaff_s0->itype + iVar5);
        if (iVar5 != 0) {
          unaff_s0 = (ASN1_ITEM *)(uint)(pAVar8 < unaff_s0);
          pcStack_12c = (char *)((int)pAVar8 - (int)pAVar10);
          pAVar4 = pAVar8;
          if (unaff_s0 != (ASN1_ITEM *)0x0) {
            pcStack_16c = (char *)0x9b;
            iVar5 = 0xb6;
            goto LAB_0054f554;
          }
        }
      }
LAB_0054f39c:
      unaff_s0 = pAVar4;
      iVar5 = pAVar7->utype;
      while( true ) {
        pcVar12 = &pAVar10->itype + iVar5;
        pAStack_1ec = &AStack_d0;
        pcStack_16c = (char *)&iStack_d8;
        pcStack_1e8 = (char *)unaff_s6;
        apuStack_e8[0] = (uchar *)pcVar12;
        uStack_dc = ASN1_get_object(unaff_s5,(long *)&AStack_d0,&iStack_d8,unaff_s6,
                                    (long)pcStack_12c);
        if ((uStack_dc & 0x80) != 0) {
          uVar9 = ERR_peek_error();
          pcStack_12c = pcVar12;
          pAStack_128 = pAVar10;
          if ((uVar9 & 0xfff) != 0x9b) goto LAB_0054f568;
          ERR_clear_error();
        }
        pcStack_12c = (char *)(apuStack_e8[0] + -(int)pcVar12);
        pAVar10 = (ASN1_ITEM *)(pcStack_12c + (int)&pAVar10->itype);
        if ((uStack_dc & 1) == 0) {
          if ((iStack_f8 != 0) && (AStack_d0._0_4_ == 0)) {
            pcStack_12c = (char *)((int)unaff_s0 - (int)pAVar10);
            pAVar8 = pAVar10;
            if ((iStack_d8 != 0) || (iStack_f8 = iStack_f8 + -1, iStack_f8 != 0)) goto LAB_0054f334;
            goto LAB_0054f43c;
          }
          if (AStack_d0._0_4_ <= (uint)((int)unaff_s0 - (int)pAVar10)) goto LAB_0054f4cc;
          pcStack_12c = (char *)((int)(ASN1_ITEM *)(&pAVar10->itype + AStack_d0._0_4_) -
                                (int)unaff_s0);
          if (((int)pcStack_12c < 0) ||
             ((ASN1_ITEM *)(&pAVar10->itype + AStack_d0._0_4_) < unaff_s0)) {
            pcStack_16c = (char *)0x9b;
            iVar5 = 0xed;
          }
          else {
            iVar5 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(pAVar7);
            if (iVar5 != 0) goto joined_r0x0054f494;
            pcStack_16c = &DAT_00000041;
            iVar5 = 0xf2;
          }
          goto LAB_0054f554;
        }
        pcStack_12c = (char *)((int)unaff_s0 - (int)pAVar10);
        iStack_f8 = iStack_f8 + 1;
        if (pcStack_12c < &DAT_00000009) break;
        iVar5 = pAVar7->utype;
      }
    }
    pcStack_16c = &DAT_00000041;
    iVar5 = 0xa9;
    goto LAB_0054f554;
  }
  pcStack_16c = &DAT_00000041;
  pcStack_1e8 = "a_d2i_fp.c";
  pAStack_1ec = (ASN1_ITEM *)&DAT_0000006b;
  ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",0x9c);
  pAVar10 = (ASN1_ITEM *)0xffffffff;
LAB_0054f57c:
  if (AStack_d0.size == *(int *)puVar15) {
    return pAVar10;
  }
  pcStack_11c = ASN1_d2i_fp;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_168 = PTR___stack_chk_guard_006aabf0;
  iStack_134 = *(int *)PTR___stack_chk_guard_006aabf0;
  pAStack_130 = unaff_s0;
  pAStack_124 = (ASN1_ITEM *)i2d;
  uVar6 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  pAVar7 = (ASN1_ITEM *)(*(code *)PTR_BIO_new_006a7fa4)(uVar6);
  if (pAVar7 == (ASN1_ITEM *)0x0) {
    ppAStack_1f4 = (ASN1_VALUE **)&DAT_00000007;
    pcStack_1a8 = "a_d2i_fp.c";
    piStack_1ac = (int *)&DAT_0000006d;
    ERR_put_error(0xd,0x6d,7,"a_d2i_fp.c",0x4d);
    pcVar12 = (char *)0x0;
  }
  else {
    ppAStack_1f4 = (ASN1_VALUE **)0x0;
    (*(code *)PTR_BIO_ctrl_006a7f18)(pAVar7,0x6a);
    piStack_1ac = &iStack_13c;
    iStack_13c = 0;
    ppAVar11 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(pAVar7);
    if ((int)ppAVar11 < 0) {
      pcVar12 = (char *)0x0;
      pcStack_1a8 = pcStack_16c;
    }
    else {
      piStack_1ac = &iStack_138;
      iStack_138 = *(int *)(iStack_13c + 4);
      pcVar12 = (char *)(*(code *)pAStack_1ec)(pcStack_1e8);
      ppAStack_1f4 = ppAVar11;
      pcStack_1a8 = pcStack_16c;
    }
    if (iStack_13c != 0) {
      (*(code *)PTR_BUF_MEM_free_006a8594)();
    }
    (*(code *)PTR_BIO_free_006a7f70)(pAVar7);
    unaff_s0 = pAVar7;
    pcStack_16c = pcVar12;
  }
  if (iStack_134 == *(int *)puStack_168) {
    return pcVar12;
  }
  pcStack_164 = ASN1_d2i_bio;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1b0 = PTR___stack_chk_guard_006aabf0;
  piVar21 = &iStack_17c;
  puStack_190 = &_gp;
  iStack_17c = 0;
  pAStack_174 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  pAStack_170 = unaff_s0;
  ppAVar11 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(ppAStack_1f4,piVar21);
  if ((int)ppAVar11 < 0) {
    pvVar13 = (void *)0x0;
  }
  else {
    piVar21 = &iStack_178;
    iStack_178 = *(int *)(iStack_17c + 4);
    pvVar13 = (void *)(*(code *)piStack_1ac)(pcStack_1a8,piVar21);
    ppAStack_1f4 = ppAVar11;
  }
  if (iStack_17c != 0) {
    pvStack_184 = pvVar13;
    (**(code **)(puStack_190 + -0x794c))();
    pvVar13 = pvStack_184;
  }
  if (pAStack_174 == *(ASN1_ITEM **)puStack_1b0) {
    return pvVar13;
  }
  pcStack_1a4 = ASN1_item_d2i_bio;
  pAStack_1f0 = pAStack_174;
  (**(code **)(puStack_190 + -0x5328))();
  puStack_248 = PTR___stack_chk_guard_006aabf0;
  ppuStack_244 = &puStack_1bc;
  puStack_1d0 = &_gp;
  puStack_1bc = (uchar *)0x0;
  pAStack_1b4 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  ppAStack_284 = ppAStack_1f4;
  ppAVar11 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(piVar21);
  if ((int)ppAVar11 < 0) {
    pAVar14 = (ASN1_VALUE *)0x0;
  }
  else {
    ppuStack_244 = &puStack_1b8;
    puStack_1b8 = *(uchar **)(puStack_1bc + 4);
    pAVar14 = ASN1_item_d2i(ppAStack_1f4,ppuStack_244,(long)ppAVar11,pAStack_1f0);
    ppAStack_284 = ppAVar11;
  }
  if (puStack_1bc != (uchar *)0x0) {
    pAStack_1c4 = pAVar14;
    (**(code **)(puStack_1d0 + -0x794c))();
    pAVar14 = pAStack_1c4;
  }
  if (pAStack_1b4 == *(ASN1_ITEM **)puStack_248) {
    return pAVar14;
  }
  pcStack_1e4 = ASN1_item_d2i_fp;
  pAStack_238 = pAStack_1b4;
  (**(code **)(puStack_1d0 + -0x5328))();
  puStack_304 = PTR___stack_chk_guard_006aabf0;
  puStack_1f8 = puStack_248;
  pcStack_1fc = *(code **)PTR___stack_chk_guard_006aabf0;
  uVar6 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar15 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar6);
  if (puVar15 == (undefined *)0x0) {
    iStack_27c = 7;
    in_00 = (uchar **)0xce;
    ERR_put_error(0xd,0xce,7,"a_d2i_fp.c",0x83);
    ppuVar16 = (uchar **)0x0;
  }
  else {
    iStack_27c = 0;
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar15,0x6a,0,ppuStack_244);
    in_00 = &puStack_204;
    puStack_204 = (uchar *)0x0;
    iVar5 = asn1_d2i_read_bio_constprop_0(puVar15,in_00);
    if (iVar5 < 0) {
      ppuVar16 = (uchar **)0x0;
    }
    else {
      in_00 = &puStack_200;
      puStack_200 = *(uchar **)(puStack_204 + 4);
      ppuVar16 = (uchar **)ASN1_item_d2i(ppAStack_284,in_00,iVar5,pAStack_238);
      iStack_27c = iVar5;
    }
    if (puStack_204 != (uchar *)0x0) {
      (*(code *)PTR_BUF_MEM_free_006a8594)();
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar15);
    puStack_248 = puVar15;
    ppuStack_244 = ppuVar16;
  }
  if (pcStack_1fc == *(code **)puStack_304) {
    return ppuVar16;
  }
  pcStack_22c = ASN1_i2d_fp;
  pcStack_28c = pcStack_1fc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_280 = PTR___stack_chk_guard_006aabf0;
  puStack_240 = puStack_304;
  pcStack_24c = *(code **)PTR___stack_chk_guard_006aabf0;
  ppAStack_23c = ppAStack_284;
  ppuStack_234 = unaff_s5;
  piStack_230 = unaff_s6;
  uVar6 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar15 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar6);
  if (puVar15 == (undefined *)0x0) {
    iVar5 = 7;
    pcStack_2c4 = (code *)0x75;
    pvStack_290 = (void *)0x0;
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x4a);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar15,0x6a,0,in_00);
    iVar17 = (*pcStack_28c)(iStack_27c,0);
    unaff_s6 = (int *)0x670000;
    ppAStack_284 = (ASN1_VALUE **)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar17,"a_i2d_fp.c",0x5b);
    if (ppAStack_284 == (ASN1_VALUE **)0x0) {
      iVar5 = 0x41;
      pcStack_2c4 = (code *)&DAT_00000074;
      pvStack_290 = (void *)0x0;
      ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5e);
    }
    else {
      ppAStack_250 = ppAStack_284;
      (*pcStack_28c)(iStack_27c,&ppAStack_250);
      pcStack_28c = (code *)0x0;
      while( true ) {
        pcStack_2c4 = (code *)((int)ppAStack_284 + (int)pcStack_28c);
        iVar5 = iVar17;
        iVar18 = (*(code *)PTR_BIO_write_006a7f14)(puVar15,pcStack_2c4,iVar17);
        if (iVar17 == iVar18) break;
        if (iVar18 < 1) {
          pvStack_290 = (void *)0x0;
          goto LAB_0054fbe4;
        }
        pcStack_28c = pcStack_28c + iVar18;
        iVar17 = iVar17 - iVar18;
      }
      pvStack_290 = (void *)0x1;
LAB_0054fbe4:
      (*(code *)PTR_CRYPTO_free_006a7f88)(ppAStack_284);
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar15);
    puStack_304 = puVar15;
  }
  if (pcStack_24c == *(code **)puStack_280) {
    return pvStack_290;
  }
  pcStack_274 = ASN1_i2d_bio;
  pcStack_2cc = pcStack_24c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_2c0 = PTR___stack_chk_guard_006aabf0;
  pAStack_294 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  puStack_288 = puStack_304;
  piStack_278 = unaff_s6;
  pAStack_2d0 = (ASN1_VALUE *)(*pcStack_2cc)(iVar5,0);
  puVar15 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(pAStack_2d0,"a_i2d_fp.c",0x5b);
  if (puVar15 == (undefined *)0x0) {
    pAVar14 = (ASN1_VALUE *)&DAT_00000041;
    puVar23 = &DAT_00000074;
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5e);
    pAVar19 = (ASN1_VALUE *)0x0;
  }
  else {
    puStack_298 = puVar15;
    (*pcStack_2cc)(iVar5,&puStack_298);
    pcStack_2cc = (code *)0x0;
    while( true ) {
      puVar23 = puVar15 + (int)pcStack_2cc;
      pAVar14 = pAStack_2d0;
      pAVar19 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a7f14)(pcStack_2c4,puVar23);
      if (pAStack_2d0 == pAVar19) break;
      if ((int)pAVar19 < 1) {
        pAVar19 = (ASN1_VALUE *)0x0;
        goto LAB_0054fd84;
      }
      pcStack_2cc = pcStack_2cc + (int)pAVar19;
      pAStack_2d0 = pAStack_2d0 + -(int)pAVar19;
    }
    pAVar19 = (ASN1_VALUE *)0x1;
LAB_0054fd84:
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar15);
    pAStack_2d0 = pAVar19;
    puStack_304 = puVar15;
  }
  if (pAStack_294 == *(ASN1_ITEM **)puStack_2c0) {
    return pAVar19;
  }
  pcStack_2bc = ASN1_item_i2d_fp;
  pAStack_348 = pAStack_294;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_300 = PTR___stack_chk_guard_006aabf0;
  pAStack_2d4 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  puStack_2c8 = puStack_304;
  uVar6 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar15 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar6);
  if (puVar15 == (undefined *)0x0) {
    pAVar14 = (ASN1_VALUE *)&DAT_00000007;
    puStack_344 = (uchar *)0xc1;
    pvStack_34c = (void *)0x0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7f);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar15,0x6a,0,puVar23);
    puStack_2d8 = (uchar *)0x0;
    pAVar19 = (ASN1_VALUE *)ASN1_item_i2d(pAVar14,&puStack_2d8,pAStack_348);
    if (puStack_2d8 == (uchar *)0x0) {
      pAVar14 = (ASN1_VALUE *)&DAT_00000041;
      puStack_344 = &DAT_000000c0;
      pvStack_34c = (void *)0x0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x91);
    }
    else {
      pAStack_348 = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_344 = puStack_2d8 + (int)pAStack_348;
        pAVar14 = pAVar19;
        pAVar20 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a7f14)(puVar15);
        if (pAVar19 == pAVar20) break;
        if ((int)pAVar20 < 1) {
          pvStack_34c = (void *)0x0;
          puStack_344 = puStack_2d8;
          goto LAB_0054fef0;
        }
        pAStack_348 = (ASN1_ITEM *)(pAVar20 + (int)&pAStack_348->itype);
        pAVar19 = pAVar19 + -(int)pAVar20;
      }
      pvStack_34c = (void *)0x1;
LAB_0054fef0:
      (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_2d8);
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar15);
    puStack_304 = puVar15;
  }
  if (pAStack_2d4 == *(ASN1_ITEM **)puStack_300) {
    return pvStack_34c;
  }
  pcStack_2fc = ASN1_item_i2d_bio;
  pAVar7 = pAStack_2d4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_340 = PTR___stack_chk_guard_006aabf0;
  puStack_318 = (uchar *)0x0;
  piStack_314 = *(int **)PTR___stack_chk_guard_006aabf0;
  pvStack_30c = pvStack_34c;
  pAStack_308 = pAStack_348;
  iVar5 = ASN1_item_i2d(pAVar14,&puStack_318,pAVar7);
  if (puStack_318 == (uchar *)0x0) {
    puVar24 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x91);
    pvVar13 = (void *)0x0;
  }
  else {
    pAStack_348 = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar24 = puStack_318 + (int)pAStack_348;
      iVar17 = (*(code *)PTR_BIO_write_006a7f14)(puStack_344,puVar24,iVar5);
      if (iVar5 == iVar17) break;
      if (iVar17 < 1) {
        pvVar13 = (void *)0x0;
        puVar24 = puStack_318;
        goto LAB_00550050;
      }
      pAStack_348 = (ASN1_ITEM *)(&pAStack_348->itype + iVar17);
      iVar5 = iVar5 - iVar17;
    }
    pvVar13 = (void *)0x1;
LAB_00550050:
    (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_318);
    pvStack_34c = pvVar13;
  }
  if (piStack_314 == *(int **)puStack_340) {
    return pvVar13;
  }
  pcStack_33c = ASN1_ENUMERATED_set;
  piVar21 = piStack_314;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar15 = PTR___stack_chk_guard_006aabf0;
  piVar21[1] = 10;
  piStack_354 = *(int **)puVar15;
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
      if ((int)puVar24 < 0) {
        puVar24 = (uchar *)-(int)puVar24;
        piVar21[1] = 0x10a;
LAB_0055018c:
        auStack_35e[2] = (char)puVar24;
        if ((int)puVar24 >> 8 == 0) {
          iVar5 = 1;
LAB_00550260:
          iVar17 = iVar5 + -1;
          *puVar23 = auStack_35e[iVar5 + 1];
          if (iVar5 != 1) {
            iVar18 = iVar5 + -3;
            *(undefined *)(piVar21[2] + 1) = auStack_35e[iVar5];
            if (iVar18 == -1) goto LAB_005501f0;
            goto LAB_005501c8;
          }
        }
        else {
          auStack_35e[3] = (char)((uint)puVar24 >> 8);
          if ((int)puVar24 >> 0x10 == 0) {
            iVar5 = 2;
            goto LAB_00550260;
          }
          auStack_35e[4] = (undefined)((uint)puVar24 >> 0x10);
          if ((int)puVar24 >> 0x18 == 0) {
            iVar5 = 3;
            goto LAB_00550260;
          }
          auStack_35e[5] = (undefined)((uint)puVar24 >> 0x18);
          *puVar23 = auStack_35e[5];
          iVar17 = 3;
          iVar18 = 1;
          *(undefined *)(piVar21[2] + 1) = auStack_35e[4];
LAB_005501c8:
          *(undefined *)(piVar21[2] + 2) = auStack_35e[iVar18 + 2];
          if (iVar18 != 0) {
            *(char *)(piVar21[2] + 3) = (char)puVar24;
          }
        }
        iVar5 = iVar17 + 1;
      }
      else {
        iVar5 = 0;
        if (puVar24 != (uchar *)0x0) goto LAB_0055018c;
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
  if (piStack_354 == *(int **)puVar15) {
    return pvVar13;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (piStack_354 != (int *)0x0) {
    if (piStack_354[1] == 0x10a) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (piStack_354[1] != 10) {
        return (void *)0xffffffff;
      }
    }
    iVar5 = *piStack_354;
    if (4 < iVar5) {
      return (void *)0xffffffff;
    }
    pbVar22 = (byte *)piStack_354[2];
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
  if (pcStack_12c == (char *)0x0) goto LAB_0054f4cc;
  pcStack_16c = pcStack_12c;
  iVar5 = (*(code *)PTR_BIO_read_006a85bc)(iStack_120,&unaff_s0->itype + pAVar7->utype);
  if (iVar5 < 1) {
    pcStack_16c = (char *)0x8e;
    iVar5 = 0xfb;
    goto LAB_0054f554;
  }
  pcStack_12c = pcStack_12c + -iVar5;
  unaff_s0 = (ASN1_ITEM *)(&unaff_s0->itype + iVar5);
  goto joined_r0x0054f494;
LAB_0054f4cc:
  pAVar8 = (ASN1_ITEM *)(&pAVar10->itype + AStack_d0._0_4_);
  pAVar10 = (ASN1_ITEM *)(uint)(pAVar8 < pAVar10);
  if (pAVar10 != (ASN1_ITEM *)0x0) {
    pcStack_16c = (char *)0x9b;
    iVar5 = 0x106;
    goto LAB_0054f554;
  }
  pAVar10 = pAVar8;
  if (iStack_f8 == 0) goto LAB_0054f43c;
  pcStack_12c = (char *)((int)unaff_s0 - (int)pAVar8);
  goto LAB_0054f334;
LAB_0054f43c:
  pcStack_1e8 = "r";
  if ((int)pAVar10 < 0) {
    pcStack_16c = (char *)0x9b;
    iVar5 = 0x115;
LAB_0054f554:
    pcStack_1e8 = "a_d2i_fp.c";
    pAStack_1ec = (ASN1_ITEM *)&DAT_0000006b;
    ERR_put_error(0xd,0x6b,(int)pcStack_16c,"a_d2i_fp.c",iVar5);
    pAStack_128 = pAVar10;
LAB_0054f568:
    (*(code *)PTR_BUF_MEM_free_006a8594)(pAVar7);
    pAVar10 = (ASN1_ITEM *)0xffffffff;
  }
  else {
    *in = pAVar7;
    pAStack_1ec = pAVar10;
    pAStack_128 = pAVar10;
  }
  goto LAB_0054f57c;
}

