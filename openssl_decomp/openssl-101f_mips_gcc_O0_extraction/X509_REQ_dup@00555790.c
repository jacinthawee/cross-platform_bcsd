
X509_REQ * X509_REQ_dup(X509_REQ *req)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  int iVar4;
  X509_REQ *pXVar5;
  X509_REQ_INFO *pXVar6;
  ulong uVar7;
  undefined4 uVar8;
  ASN1_VALUE **ppAVar9;
  X509_REQ *pXVar10;
  undefined *puVar11;
  int iVar12;
  int iVar13;
  ASN1_VALUE *pAVar14;
  ASN1_VALUE *pAVar15;
  ASN1_ITEM *it;
  int *piVar16;
  byte *pbVar17;
  uchar **in;
  undefined *puVar18;
  uchar *puVar19;
  ASN1_VALUE *val;
  X509_REQ *unaff_s0;
  X509_REQ *pXVar20;
  X509_REQ *unaff_s2;
  X509_REQ_INFO *unaff_s3;
  X509_REQ **unaff_s5;
  int *unaff_s6;
  undefined auStack_30e [10];
  int *piStack_304;
  X509_REQ *pXStack_2fc;
  ASN1_ITEM *pAStack_2f8;
  uchar *puStack_2f4;
  undefined *puStack_2f0;
  code *pcStack_2ec;
  uchar *puStack_2c8;
  int *piStack_2c4;
  X509_REQ *pXStack_2bc;
  ASN1_ITEM *pAStack_2b8;
  undefined *puStack_2b4;
  undefined *puStack_2b0;
  code *pcStack_2ac;
  uchar *puStack_288;
  ASN1_ITEM *pAStack_284;
  X509_REQ *pXStack_280;
  code *pcStack_27c;
  undefined *puStack_278;
  code *pcStack_274;
  undefined *puStack_270;
  code *pcStack_26c;
  undefined *puStack_248;
  ASN1_ITEM *pAStack_244;
  X509_REQ *pXStack_240;
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
  X509_REQ *pXStack_1f4;
  undefined *puStack_1f0;
  ASN1_VALUE **ppAStack_1ec;
  ASN1_ITEM *pAStack_1e8;
  X509_REQ **ppXStack_1e4;
  int *piStack_1e0;
  code *pcStack_1dc;
  uchar *puStack_1b4;
  uchar *puStack_1b0;
  code *pcStack_1ac;
  undefined *puStack_1a8;
  ASN1_VALUE **ppAStack_1a4;
  ASN1_ITEM *pAStack_1a0;
  X509_REQ *pXStack_19c;
  char *pcStack_198;
  code *pcStack_194;
  undefined *puStack_180;
  X509_REQ *pXStack_174;
  undefined auStack_16c [8];
  ASN1_ITEM *pAStack_164;
  undefined *puStack_160;
  int *piStack_15c;
  char *pcStack_158;
  code *pcStack_154;
  undefined *puStack_140;
  X509_REQ *pXStack_134;
  int iStack_12c;
  int iStack_128;
  ASN1_ITEM *pAStack_124;
  X509_REQ *pXStack_120;
  X509_REQ *pXStack_11c;
  undefined *puStack_118;
  code *pcStack_114;
  int iStack_ec;
  int iStack_e8;
  int iStack_e4;
  X509_REQ *pXStack_e0;
  X509_REQ *pXStack_dc;
  X509_REQ *pXStack_d8;
  X509_REQ_INFO *pXStack_d4;
  X509_ALGOR *pXStack_d0;
  code *pcStack_cc;
  int iStack_a8;
  X509_REQ *apXStack_98 [3];
  uint uStack_8c;
  undefined auStack_88 [28];
  int iStack_6c;
  X509_REQ *pXStack_68;
  undefined *puStack_64;
  X509_REQ_INFO *pXStack_1c;
  X509_REQ_INFO *pXStack_18;
  X509_ALGOR *pXStack_14;
  
  pXStack_dc = (X509_REQ *)PTR___stack_chk_guard_006aabf0;
  pXStack_1c = (X509_REQ_INFO *)0x0;
  pXStack_14 = *(X509_ALGOR **)PTR___stack_chk_guard_006aabf0;
  if (req == (X509_REQ *)0x0) {
    pXVar5 = (X509_REQ *)0x0;
  }
  else {
    iVar4 = ASN1_item_i2d((ASN1_VALUE *)req,(uchar **)&pXStack_1c,(ASN1_ITEM *)X509_REQ_it);
    if (pXStack_1c == (X509_REQ_INFO *)0x0) {
      req = (X509_REQ *)0xbf;
      ERR_put_error(0xd,0xbf,0x41,"a_dup.c",0x68);
      pXVar5 = (X509_REQ *)0x0;
      unaff_s0 = (X509_REQ *)X509_REQ_it;
    }
    else {
      req = (X509_REQ *)&pXStack_18;
      pXStack_18 = pXStack_1c;
      pXVar5 = (X509_REQ *)
               ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)req,iVar4,(ASN1_ITEM *)X509_REQ_it);
      (*(code *)PTR_CRYPTO_free_006a7f88)(pXStack_1c);
      unaff_s0 = pXVar5;
    }
  }
  if (pXStack_14 == *(X509_ALGOR **)pXStack_dc) {
    return pXVar5;
  }
  pXStack_d0 = pXStack_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar11 = PTR___stack_chk_guard_006aabf0;
  puStack_64 = (undefined *)pXStack_dc;
  iStack_6c = *(int *)PTR___stack_chk_guard_006aabf0;
  pXStack_68 = unaff_s0;
  pXVar6 = (X509_REQ_INFO *)(*(code *)PTR_BUF_MEM_new_006a859c)();
  if (pXVar6 != (X509_REQ_INFO *)0x0) {
    unaff_s5 = apXStack_98;
    unaff_s6 = (int *)(auStack_88 + 4);
    ERR_clear_error();
    unaff_s0 = (X509_REQ *)0x0;
    iStack_a8 = 0;
    pXStack_dc = (X509_REQ *)0x0;
    pXVar5 = (X509_REQ *)0x0;
LAB_0054f334:
    pXVar10 = unaff_s0;
    pXVar20 = pXVar5;
    unaff_s3 = pXVar6;
    if ((X509_REQ *)&DAT_00000008 < pXStack_dc) goto LAB_0054f39c;
    while ((unaff_s0 <= &pXVar20->signature &&
           (iVar4 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(pXVar6), iVar4 != 0))) {
      iVar4 = (*(code *)PTR_BIO_read_006a85bc)
                        (pXStack_d0,(undefined *)((int)&unaff_s0->req_info + (pXVar6->enc).len),
                         (int)&pXVar20->signature - (int)unaff_s0);
      pXVar10 = unaff_s0;
      if (iVar4 < 0) {
        if (unaff_s0 == pXVar20) {
          pXStack_11c = (X509_REQ *)0x8e;
          iVar4 = 0xaf;
          goto LAB_0054f554;
        }
      }
      else {
        pXVar5 = (X509_REQ *)((int)&unaff_s0->req_info + iVar4);
        if (iVar4 != 0) {
          unaff_s0 = (X509_REQ *)(uint)(pXVar5 < unaff_s0);
          pXStack_dc = (X509_REQ *)((int)pXVar5 - (int)pXVar20);
          pXVar10 = pXVar5;
          if (unaff_s0 != (X509_REQ *)0x0) {
            pXStack_11c = (X509_REQ *)0x9b;
            iVar4 = 0xb6;
            goto LAB_0054f554;
          }
        }
      }
LAB_0054f39c:
      unaff_s0 = pXVar10;
      iVar4 = (pXVar6->enc).len;
      while( true ) {
        pXVar5 = (X509_REQ *)((int)&pXVar20->req_info + iVar4);
        pXStack_19c = (X509_REQ *)(auStack_88 + 8);
        pXStack_11c = (X509_REQ *)auStack_88;
        pcStack_198 = (char *)unaff_s6;
        apXStack_98[0] = pXVar5;
        uStack_8c = ASN1_get_object((uchar **)unaff_s5,(long *)(X509_REQ *)(auStack_88 + 8),
                                    (int *)(X509_REQ *)auStack_88,unaff_s6,(long)pXStack_dc);
        if ((uStack_8c & 0x80) != 0) {
          uVar7 = ERR_peek_error();
          pXStack_dc = pXVar5;
          unaff_s2 = pXVar20;
          if ((uVar7 & 0xfff) != 0x9b) goto LAB_0054f568;
          ERR_clear_error();
        }
        pXStack_dc = (X509_REQ *)((int)apXStack_98[0] - (int)pXVar5);
        pXVar20 = (X509_REQ *)((int)pXVar20 + (int)pXStack_dc);
        if ((uStack_8c & 1) == 0) {
          if ((iStack_a8 != 0) && (auStack_88._8_4_ == (ASN1_BIT_STRING *)0x0)) {
            pXStack_dc = (X509_REQ *)((int)unaff_s0 - (int)pXVar20);
            pXVar5 = pXVar20;
            if ((auStack_88._0_4_ != (X509_REQ_INFO *)0x0) ||
               (iStack_a8 = iStack_a8 + -1, iStack_a8 != 0)) goto LAB_0054f334;
            goto LAB_0054f43c;
          }
          if (auStack_88._8_4_ <= (ASN1_BIT_STRING *)((int)unaff_s0 - (int)pXVar20))
          goto LAB_0054f4cc;
          pXStack_dc = (X509_REQ *)
                       ((int)(X509_REQ *)((int)auStack_88._8_4_ + (int)pXVar20) - (int)unaff_s0);
          if (((int)pXStack_dc < 0) ||
             ((X509_REQ *)((int)auStack_88._8_4_ + (int)pXVar20) < unaff_s0)) {
            pXStack_11c = (X509_REQ *)0x9b;
            iVar4 = 0xed;
          }
          else {
            iVar4 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(pXVar6);
            if (iVar4 != 0) goto joined_r0x0054f494;
            pXStack_11c = (X509_REQ *)&DAT_00000041;
            iVar4 = 0xf2;
          }
          goto LAB_0054f554;
        }
        pXStack_dc = (X509_REQ *)((int)unaff_s0 - (int)pXVar20);
        iStack_a8 = iStack_a8 + 1;
        if (pXStack_dc < (X509_REQ *)&DAT_00000009) break;
        iVar4 = (pXVar6->enc).len;
      }
    }
    pXStack_11c = (X509_REQ *)&DAT_00000041;
    iVar4 = 0xa9;
    goto LAB_0054f554;
  }
  pXStack_11c = (X509_REQ *)&DAT_00000041;
  pcStack_198 = "a_d2i_fp.c";
  pXStack_19c = (X509_REQ *)&DAT_0000006b;
  ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",0x9c);
  pXVar20 = (X509_REQ *)0xffffffff;
LAB_0054f57c:
  if (iStack_6c == *(int *)puVar11) {
    return pXVar20;
  }
  pcStack_cc = ASN1_d2i_fp;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_118 = PTR___stack_chk_guard_006aabf0;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pXStack_e0 = unaff_s0;
  pXStack_d8 = unaff_s2;
  pXStack_d4 = unaff_s3;
  uVar8 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  pXVar5 = (X509_REQ *)(*(code *)PTR_BIO_new_006a7fa4)(uVar8);
  if (pXVar5 == (X509_REQ *)0x0) {
    ppAStack_1a4 = (ASN1_VALUE **)&DAT_00000007;
    pcStack_158 = "a_d2i_fp.c";
    piStack_15c = (int *)&DAT_0000006d;
    ERR_put_error(0xd,0x6d,7,"a_d2i_fp.c",0x4d);
    pXVar10 = (X509_REQ *)0x0;
  }
  else {
    ppAStack_1a4 = (ASN1_VALUE **)0x0;
    (*(code *)PTR_BIO_ctrl_006a7f18)(pXVar5,0x6a);
    piStack_15c = &iStack_ec;
    iStack_ec = 0;
    ppAVar9 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(pXVar5);
    if ((int)ppAVar9 < 0) {
      pXVar10 = (X509_REQ *)0x0;
      pcStack_158 = (char *)pXStack_11c;
    }
    else {
      piStack_15c = &iStack_e8;
      iStack_e8 = *(int *)(iStack_ec + 4);
      pXVar10 = (X509_REQ *)(*(code *)pXStack_19c)(pcStack_198);
      ppAStack_1a4 = ppAVar9;
      pcStack_158 = (char *)pXStack_11c;
    }
    if (iStack_ec != 0) {
      (*(code *)PTR_BUF_MEM_free_006a8594)();
    }
    (*(code *)PTR_BIO_free_006a7f70)(pXVar5);
    unaff_s0 = pXVar5;
    pXStack_11c = pXVar10;
  }
  if (iStack_e4 == *(int *)puStack_118) {
    return pXVar10;
  }
  pcStack_114 = ASN1_d2i_bio;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_160 = PTR___stack_chk_guard_006aabf0;
  piVar16 = &iStack_12c;
  puStack_140 = &_gp;
  iStack_12c = 0;
  pAStack_124 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  pXStack_120 = unaff_s0;
  ppAVar9 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(ppAStack_1a4,piVar16);
  if ((int)ppAVar9 < 0) {
    pXVar5 = (X509_REQ *)0x0;
  }
  else {
    piVar16 = &iStack_128;
    iStack_128 = *(int *)(iStack_12c + 4);
    pXVar5 = (X509_REQ *)(*(code *)piStack_15c)(pcStack_158,piVar16);
    ppAStack_1a4 = ppAVar9;
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
  pXStack_1f4 = (X509_REQ *)auStack_16c;
  puStack_180 = &_gp;
  auStack_16c._0_4_ = (X509_REQ_INFO *)0x0;
  pAStack_164 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  ppAStack_234 = ppAStack_1a4;
  ppAVar9 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(piVar16);
  if ((int)ppAVar9 < 0) {
    pXVar5 = (X509_REQ *)0x0;
  }
  else {
    pXStack_1f4 = (X509_REQ *)(auStack_16c + 4);
    auStack_16c._4_4_ = (X509_ALGOR *)((auStack_16c._0_4_)->enc).len;
    pXVar5 = (X509_REQ *)ASN1_item_d2i(ppAStack_1a4,(uchar **)pXStack_1f4,(long)ppAVar9,pAStack_1a0)
    ;
    ppAStack_234 = ppAVar9;
  }
  if (auStack_16c._0_4_ != (X509_REQ_INFO *)0x0) {
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
  uVar8 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar11 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar8);
  if (puVar11 == (undefined *)0x0) {
    iStack_22c = 7;
    in = (uchar **)0xce;
    ERR_put_error(0xd,0xce,7,"a_d2i_fp.c",0x83);
    pXVar5 = (X509_REQ *)0x0;
  }
  else {
    iStack_22c = 0;
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar11,0x6a,0,pXStack_1f4);
    in = &puStack_1b4;
    puStack_1b4 = (uchar *)0x0;
    iVar4 = asn1_d2i_read_bio_constprop_0(puVar11,in);
    if (iVar4 < 0) {
      pXVar5 = (X509_REQ *)0x0;
    }
    else {
      in = &puStack_1b0;
      puStack_1b0 = *(uchar **)(puStack_1b4 + 4);
      pXVar5 = (X509_REQ *)ASN1_item_d2i(ppAStack_234,in,iVar4,pAStack_1e8);
      iStack_22c = iVar4;
    }
    if (puStack_1b4 != (uchar *)0x0) {
      (*(code *)PTR_BUF_MEM_free_006a8594)();
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar11);
    puStack_1f8 = puVar11;
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
  piStack_1e0 = unaff_s6;
  uVar8 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar11 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar8);
  if (puVar11 == (undefined *)0x0) {
    iVar4 = 7;
    pcStack_274 = (code *)0x75;
    pXStack_240 = (X509_REQ *)0x0;
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x4a);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar11,0x6a,0,in);
    iVar12 = (*pcStack_23c)(iStack_22c,0);
    unaff_s6 = (int *)0x670000;
    ppAStack_234 = (ASN1_VALUE **)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar12,"a_i2d_fp.c",0x5b);
    if (ppAStack_234 == (ASN1_VALUE **)0x0) {
      iVar4 = 0x41;
      pcStack_274 = (code *)&DAT_00000074;
      pXStack_240 = (X509_REQ *)0x0;
      ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5e);
    }
    else {
      ppAStack_200 = ppAStack_234;
      (*pcStack_23c)(iStack_22c,&ppAStack_200);
      pcStack_23c = (code *)0x0;
      while( true ) {
        pcStack_274 = (code *)((int)ppAStack_234 + (int)pcStack_23c);
        iVar4 = iVar12;
        iVar13 = (*(code *)PTR_BIO_write_006a7f14)(puVar11,pcStack_274,iVar12);
        if (iVar12 == iVar13) break;
        if (iVar13 < 1) {
          pXStack_240 = (X509_REQ *)0x0;
          goto LAB_0054fbe4;
        }
        pcStack_23c = pcStack_23c + iVar13;
        iVar12 = iVar12 - iVar13;
      }
      pXStack_240 = (X509_REQ *)0x1;
LAB_0054fbe4:
      (*(code *)PTR_CRYPTO_free_006a7f88)(ppAStack_234);
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar11);
    puStack_2b4 = puVar11;
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
  piStack_228 = unaff_s6;
  pXStack_280 = (X509_REQ *)(*pcStack_27c)(iVar4,0);
  puVar11 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(pXStack_280,"a_i2d_fp.c",0x5b);
  if (puVar11 == (undefined *)0x0) {
    pXVar5 = (X509_REQ *)&DAT_00000041;
    puVar18 = &DAT_00000074;
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5e);
    pXVar10 = (X509_REQ *)0x0;
  }
  else {
    puStack_248 = puVar11;
    (*pcStack_27c)(iVar4,&puStack_248);
    pcStack_27c = (code *)0x0;
    while( true ) {
      puVar18 = puVar11 + (int)pcStack_27c;
      pXVar5 = pXStack_280;
      pXVar10 = (X509_REQ *)(*(code *)PTR_BIO_write_006a7f14)(pcStack_274,puVar18);
      if (pXStack_280 == pXVar10) break;
      if ((int)pXVar10 < 1) {
        pXVar10 = (X509_REQ *)0x0;
        goto LAB_0054fd84;
      }
      pcStack_27c = pcStack_27c + (int)pXVar10;
      pXStack_280 = (X509_REQ *)((int)pXStack_280 - (int)pXVar10);
    }
    pXVar10 = (X509_REQ *)0x1;
LAB_0054fd84:
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar11);
    pXStack_280 = pXVar10;
    puStack_2b4 = puVar11;
  }
  if (pAStack_244 == *(ASN1_ITEM **)puStack_270) {
    return pXVar10;
  }
  pcStack_26c = ASN1_item_i2d_fp;
  pAStack_2f8 = pAStack_244;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_2b0 = PTR___stack_chk_guard_006aabf0;
  pAStack_284 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  puStack_278 = puStack_2b4;
  uVar8 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar11 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar8);
  if (puVar11 == (undefined *)0x0) {
    val = (ASN1_VALUE *)&DAT_00000007;
    puStack_2f4 = (uchar *)0xc1;
    pXStack_2fc = (X509_REQ *)0x0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7f);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar11,0x6a,0,puVar18);
    puStack_288 = (uchar *)0x0;
    pAVar14 = (ASN1_VALUE *)ASN1_item_i2d((ASN1_VALUE *)pXVar5,&puStack_288,pAStack_2f8);
    if (puStack_288 == (uchar *)0x0) {
      val = (ASN1_VALUE *)&DAT_00000041;
      puStack_2f4 = &DAT_000000c0;
      pXStack_2fc = (X509_REQ *)0x0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x91);
    }
    else {
      pAStack_2f8 = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_2f4 = puStack_288 + (int)pAStack_2f8;
        val = pAVar14;
        pAVar15 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a7f14)(puVar11);
        if (pAVar14 == pAVar15) break;
        if ((int)pAVar15 < 1) {
          pXStack_2fc = (X509_REQ *)0x0;
          puStack_2f4 = puStack_288;
          goto LAB_0054fef0;
        }
        pAStack_2f8 = (ASN1_ITEM *)(pAVar15 + (int)&pAStack_2f8->itype);
        pAVar14 = pAVar14 + -(int)pAVar15;
      }
      pXStack_2fc = (X509_REQ *)0x1;
LAB_0054fef0:
      (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_288);
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar11);
    puStack_2b4 = puVar11;
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
    puVar19 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x91);
    pXVar5 = (X509_REQ *)0x0;
  }
  else {
    pAStack_2f8 = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar19 = puStack_2c8 + (int)pAStack_2f8;
      iVar12 = (*(code *)PTR_BIO_write_006a7f14)(puStack_2f4,puVar19,iVar4);
      if (iVar4 == iVar12) break;
      if (iVar12 < 1) {
        pXVar5 = (X509_REQ *)0x0;
        puVar19 = puStack_2c8;
        goto LAB_00550050;
      }
      pAStack_2f8 = (ASN1_ITEM *)(&pAStack_2f8->itype + iVar12);
      iVar4 = iVar4 - iVar12;
    }
    pXVar5 = (X509_REQ *)0x1;
LAB_00550050:
    (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_2c8);
    pXStack_2fc = pXVar5;
  }
  if (piStack_2c4 == *(int **)puStack_2f0) {
    return pXVar5;
  }
  pcStack_2ec = ASN1_ENUMERATED_set;
  piVar16 = piStack_2c4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar11 = PTR___stack_chk_guard_006aabf0;
  piVar16[1] = 10;
  piStack_304 = *(int **)puVar11;
  if (*piVar16 < 5) {
    if (piVar16[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    puVar18 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(5,"a_enum.c",0x51);
    piVar16[2] = (int)puVar18;
    if (puVar18 != (undefined *)0x0) {
      *puVar18 = 0;
      puVar18[1] = 0;
      puVar18[2] = 0;
      puVar18[3] = 0;
      puVar18[4] = 0;
      goto LAB_00550170;
    }
  }
  else {
LAB_00550170:
    puVar18 = (undefined *)piVar16[2];
    if (puVar18 != (undefined *)0x0) {
      if ((int)puVar19 < 0) {
        puVar19 = (uchar *)-(int)puVar19;
        piVar16[1] = 0x10a;
LAB_0055018c:
        auStack_30e[2] = (char)puVar19;
        if ((int)puVar19 >> 8 == 0) {
          iVar4 = 1;
LAB_00550260:
          iVar12 = iVar4 + -1;
          *puVar18 = auStack_30e[iVar4 + 1];
          if (iVar4 != 1) {
            iVar13 = iVar4 + -3;
            *(undefined *)(piVar16[2] + 1) = auStack_30e[iVar4];
            if (iVar13 == -1) goto LAB_005501f0;
            goto LAB_005501c8;
          }
        }
        else {
          auStack_30e[3] = (char)((uint)puVar19 >> 8);
          if ((int)puVar19 >> 0x10 == 0) {
            iVar4 = 2;
            goto LAB_00550260;
          }
          auStack_30e[4] = (undefined)((uint)puVar19 >> 0x10);
          if ((int)puVar19 >> 0x18 == 0) {
            iVar4 = 3;
            goto LAB_00550260;
          }
          auStack_30e[5] = (undefined)((uint)puVar19 >> 0x18);
          *puVar18 = auStack_30e[5];
          iVar12 = 3;
          iVar13 = 1;
          *(undefined *)(piVar16[2] + 1) = auStack_30e[4];
LAB_005501c8:
          *(undefined *)(piVar16[2] + 2) = auStack_30e[iVar13 + 2];
          if (iVar13 != 0) {
            *(char *)(piVar16[2] + 3) = (char)puVar19;
          }
        }
        iVar4 = iVar12 + 1;
      }
      else {
        iVar4 = 0;
        if (puVar19 != (uchar *)0x0) goto LAB_0055018c;
      }
LAB_005501f0:
      pXVar5 = (X509_REQ *)0x1;
      *piVar16 = iVar4;
      goto LAB_005501f8;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x56);
  pXVar5 = (X509_REQ *)0x0;
LAB_005501f8:
  if (piStack_304 == *(int **)puVar11) {
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
        return (X509_REQ *)0xffffffff;
      }
    }
    iVar4 = *piStack_304;
    if (4 < iVar4) {
      return (X509_REQ *)0xffffffff;
    }
    pbVar17 = (byte *)piStack_304[2];
    if (pbVar17 != (byte *)0x0) {
      if (iVar4 < 1) {
        pXVar5 = (X509_REQ *)0x0;
      }
      else {
        pXVar5 = (X509_REQ *)(uint)*pbVar17;
        if (iVar4 != 1) {
          uVar1 = CONCAT11(*pbVar17,pbVar17[1]);
          pXVar5 = (X509_REQ *)(uint)uVar1;
          if (iVar4 != 2) {
            uVar2 = CONCAT21(uVar1,pbVar17[2]);
            pXVar5 = (X509_REQ *)(uint)uVar2;
            if (iVar4 == 4) {
              pXVar5 = (X509_REQ *)CONCAT31(uVar2,pbVar17[3]);
            }
          }
        }
      }
      if (!bVar3) {
        return pXVar5;
      }
      return (X509_REQ *)-(int)pXVar5;
    }
  }
  return (X509_REQ *)0x0;
joined_r0x0054f494:
  if (pXStack_dc == (X509_REQ *)0x0) goto LAB_0054f4cc;
  pXStack_11c = pXStack_dc;
  iVar4 = (*(code *)PTR_BIO_read_006a85bc)
                    (pXStack_d0,(undefined *)((int)&unaff_s0->req_info + (pXVar6->enc).len));
  if (iVar4 < 1) {
    pXStack_11c = (X509_REQ *)0x8e;
    iVar4 = 0xfb;
    goto LAB_0054f554;
  }
  pXStack_dc = (X509_REQ *)((int)pXStack_dc - iVar4);
  unaff_s0 = (X509_REQ *)((int)&unaff_s0->req_info + iVar4);
  goto joined_r0x0054f494;
LAB_0054f4cc:
  pXVar5 = (X509_REQ *)((int)&(auStack_88._8_4_)->length + (int)&pXVar20->req_info);
  pXVar20 = (X509_REQ *)(uint)(pXVar5 < pXVar20);
  if (pXVar20 != (X509_REQ *)0x0) {
    pXStack_11c = (X509_REQ *)0x9b;
    iVar4 = 0x106;
    goto LAB_0054f554;
  }
  pXVar20 = pXVar5;
  if (iStack_a8 == 0) goto LAB_0054f43c;
  pXStack_dc = (X509_REQ *)((int)unaff_s0 - (int)pXVar5);
  goto LAB_0054f334;
LAB_0054f43c:
  pcStack_198 = "r";
  if ((int)pXVar20 < 0) {
    pXStack_11c = (X509_REQ *)0x9b;
    iVar4 = 0x115;
LAB_0054f554:
    pcStack_198 = "a_d2i_fp.c";
    pXStack_19c = (X509_REQ *)&DAT_0000006b;
    ERR_put_error(0xd,0x6b,(int)pXStack_11c,"a_d2i_fp.c",iVar4);
    unaff_s2 = pXVar20;
LAB_0054f568:
    (*(code *)PTR_BUF_MEM_free_006a8594)(pXVar6);
    pXVar20 = (X509_REQ *)0xffffffff;
  }
  else {
    req->req_info = pXVar6;
    pXStack_19c = pXVar20;
    unaff_s2 = pXVar20;
  }
  goto LAB_0054f57c;
}

