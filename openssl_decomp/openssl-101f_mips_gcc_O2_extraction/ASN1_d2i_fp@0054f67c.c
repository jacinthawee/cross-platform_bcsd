
void * ASN1_d2i_fp(xnew *xnew,undefined1 *d2i,FILE *in,void **x)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  ASN1_VALUE **ppAVar6;
  FILE *pFVar7;
  void *pvVar8;
  ASN1_VALUE *pAVar9;
  undefined *puVar10;
  uchar **ppuVar11;
  int iVar12;
  int iVar13;
  ASN1_VALUE *pAVar14;
  ASN1_VALUE *pAVar15;
  ASN1_ITEM *it;
  int *piVar16;
  byte *pbVar17;
  uchar **in_00;
  undefined *puVar18;
  uchar *puVar19;
  int unaff_s0;
  char *unaff_s6;
  undefined auStack_246 [10];
  int *piStack_23c;
  void *pvStack_234;
  ASN1_ITEM *pAStack_230;
  uchar *puStack_22c;
  undefined *puStack_228;
  code *pcStack_224;
  uchar *puStack_200;
  int *piStack_1fc;
  void *pvStack_1f4;
  ASN1_ITEM *pAStack_1f0;
  undefined *puStack_1ec;
  undefined *puStack_1e8;
  code *pcStack_1e4;
  uchar *puStack_1c0;
  ASN1_ITEM *pAStack_1bc;
  ASN1_VALUE *pAStack_1b8;
  code *pcStack_1b4;
  undefined *puStack_1b0;
  code *pcStack_1ac;
  undefined *puStack_1a8;
  code *pcStack_1a4;
  undefined *puStack_180;
  ASN1_ITEM *pAStack_17c;
  void *pvStack_178;
  code *pcStack_174;
  undefined *puStack_170;
  ASN1_VALUE **ppAStack_16c;
  undefined *puStack_168;
  int iStack_164;
  char *pcStack_160;
  code *pcStack_15c;
  ASN1_VALUE **ppAStack_138;
  code *pcStack_134;
  undefined *puStack_130;
  uchar **ppuStack_12c;
  undefined *puStack_128;
  ASN1_VALUE **ppAStack_124;
  ASN1_ITEM *pAStack_120;
  uchar *puStack_ec;
  uchar *puStack_e8;
  code *pcStack_e4;
  undefined *puStack_e0;
  ASN1_VALUE **ppAStack_dc;
  ASN1_ITEM *pAStack_d8;
  undefined1 *puStack_d4;
  void **ppvStack_d0;
  code *pcStack_cc;
  undefined *puStack_b8;
  ASN1_VALUE *pAStack_ac;
  uchar *puStack_a4;
  uchar *puStack_a0;
  ASN1_ITEM *pAStack_9c;
  undefined *puStack_98;
  int *piStack_94;
  char *pcStack_90;
  code *pcStack_8c;
  undefined *puStack_78;
  void *pvStack_6c;
  int iStack_64;
  int iStack_60;
  ASN1_ITEM *pAStack_5c;
  int iStack_58;
  FILE *pFStack_54;
  undefined *puStack_50;
  code *pcStack_4c;
  int local_24;
  int local_20;
  int local_1c;
  
  puStack_50 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  iVar5 = (*(code *)PTR_BIO_new_006a7fa4)(uVar4);
  if (iVar5 == 0) {
    ppAStack_dc = (ASN1_VALUE **)&DAT_00000007;
    pcStack_90 = "a_d2i_fp.c";
    piStack_94 = (int *)&DAT_0000006d;
    ERR_put_error(0xd,0x6d,7,"a_d2i_fp.c",0x4d);
    pFVar7 = (FILE *)0x0;
  }
  else {
    ppAStack_dc = (ASN1_VALUE **)0x0;
    (*(code *)PTR_BIO_ctrl_006a7f18)(iVar5,0x6a);
    piStack_94 = &local_24;
    local_24 = 0;
    ppAVar6 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(iVar5);
    if ((int)ppAVar6 < 0) {
      pFVar7 = (FILE *)0x0;
      pcStack_90 = (char *)in;
    }
    else {
      piStack_94 = &local_20;
      local_20 = *(int *)(local_24 + 4);
      pFVar7 = (FILE *)(*(code *)d2i)(x);
      ppAStack_dc = ppAVar6;
      pcStack_90 = (char *)in;
    }
    if (local_24 != 0) {
      (*(code *)PTR_BUF_MEM_free_006a8594)();
    }
    (*(code *)PTR_BIO_free_006a7f70)(iVar5);
    unaff_s0 = iVar5;
    in = pFVar7;
  }
  if (local_1c == *(int *)puStack_50) {
    return pFVar7;
  }
  pcStack_4c = ASN1_d2i_bio;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_98 = PTR___stack_chk_guard_006aabf0;
  piVar16 = &iStack_64;
  puStack_78 = &_gp;
  iStack_64 = 0;
  pAStack_5c = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  iStack_58 = unaff_s0;
  pFStack_54 = in;
  ppAVar6 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(ppAStack_dc,piVar16);
  if ((int)ppAVar6 < 0) {
    pvVar8 = (void *)0x0;
  }
  else {
    piVar16 = &iStack_60;
    iStack_60 = *(int *)(iStack_64 + 4);
    pvVar8 = (void *)(*(code *)piStack_94)(pcStack_90,piVar16);
    ppAStack_dc = ppAVar6;
  }
  if (iStack_64 != 0) {
    pvStack_6c = pvVar8;
    (**(code **)(puStack_78 + -0x794c))();
    pvVar8 = pvStack_6c;
  }
  if (pAStack_5c == *(ASN1_ITEM **)puStack_98) {
    return pvVar8;
  }
  pcStack_8c = ASN1_item_d2i_bio;
  pAStack_d8 = pAStack_5c;
  (**(code **)(puStack_78 + -0x5328))();
  puStack_130 = PTR___stack_chk_guard_006aabf0;
  ppuStack_12c = &puStack_a4;
  puStack_b8 = &_gp;
  puStack_a4 = (uchar *)0x0;
  pAStack_9c = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  ppAStack_16c = ppAStack_dc;
  ppAVar6 = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(piVar16);
  if ((int)ppAVar6 < 0) {
    pAVar9 = (ASN1_VALUE *)0x0;
  }
  else {
    ppuStack_12c = &puStack_a0;
    puStack_a0 = *(uchar **)(puStack_a4 + 4);
    pAVar9 = ASN1_item_d2i(ppAStack_dc,ppuStack_12c,(long)ppAVar6,pAStack_d8);
    ppAStack_16c = ppAVar6;
  }
  if (puStack_a4 != (uchar *)0x0) {
    pAStack_ac = pAVar9;
    (**(code **)(puStack_b8 + -0x794c))();
    pAVar9 = pAStack_ac;
  }
  if (pAStack_9c == *(ASN1_ITEM **)puStack_130) {
    return pAVar9;
  }
  pcStack_cc = ASN1_item_d2i_fp;
  pAStack_120 = pAStack_9c;
  (**(code **)(puStack_b8 + -0x5328))();
  puStack_1ec = PTR___stack_chk_guard_006aabf0;
  puStack_e0 = puStack_130;
  pcStack_e4 = *(code **)PTR___stack_chk_guard_006aabf0;
  puStack_d4 = d2i;
  ppvStack_d0 = x;
  uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar10 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar4);
  if (puVar10 == (undefined *)0x0) {
    iStack_164 = 7;
    in_00 = (uchar **)0xce;
    ERR_put_error(0xd,0xce,7,"a_d2i_fp.c",0x83);
    ppuVar11 = (uchar **)0x0;
  }
  else {
    iStack_164 = 0;
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar10,0x6a,0,ppuStack_12c);
    in_00 = &puStack_ec;
    puStack_ec = (uchar *)0x0;
    iVar5 = asn1_d2i_read_bio_constprop_0(puVar10,in_00);
    if (iVar5 < 0) {
      ppuVar11 = (uchar **)0x0;
    }
    else {
      in_00 = &puStack_e8;
      puStack_e8 = *(uchar **)(puStack_ec + 4);
      ppuVar11 = (uchar **)ASN1_item_d2i(ppAStack_16c,in_00,iVar5,pAStack_120);
      iStack_164 = iVar5;
    }
    if (puStack_ec != (uchar *)0x0) {
      (*(code *)PTR_BUF_MEM_free_006a8594)();
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar10);
    puStack_130 = puVar10;
    ppuStack_12c = ppuVar11;
  }
  if (pcStack_e4 == *(code **)puStack_1ec) {
    return ppuVar11;
  }
  pcStack_174 = pcStack_e4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_168 = PTR___stack_chk_guard_006aabf0;
  puStack_128 = puStack_1ec;
  pcStack_134 = *(code **)PTR___stack_chk_guard_006aabf0;
  ppAStack_124 = ppAStack_16c;
  uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar10 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar4);
  if (puVar10 == (undefined *)0x0) {
    iVar5 = 7;
    pcStack_1ac = (code *)0x75;
    pvStack_178 = (void *)0x0;
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x4a);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar10,0x6a,0,in_00);
    iVar12 = (*pcStack_174)(iStack_164,0);
    unaff_s6 = "7 datafinal";
    ppAStack_16c = (ASN1_VALUE **)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar12,"a_i2d_fp.c",0x5b);
    if (ppAStack_16c == (ASN1_VALUE **)0x0) {
      iVar5 = 0x41;
      pcStack_1ac = (code *)&DAT_00000074;
      pvStack_178 = (void *)0x0;
      ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5e);
    }
    else {
      ppAStack_138 = ppAStack_16c;
      (*pcStack_174)(iStack_164,&ppAStack_138);
      pcStack_174 = (code *)0x0;
      while( true ) {
        pcStack_1ac = (code *)((int)ppAStack_16c + (int)pcStack_174);
        iVar5 = iVar12;
        iVar13 = (*(code *)PTR_BIO_write_006a7f14)(puVar10,pcStack_1ac,iVar12);
        if (iVar12 == iVar13) break;
        if (iVar13 < 1) {
          pvStack_178 = (void *)0x0;
          goto LAB_0054fbe4;
        }
        pcStack_174 = pcStack_174 + iVar13;
        iVar12 = iVar12 - iVar13;
      }
      pvStack_178 = (void *)0x1;
LAB_0054fbe4:
      (*(code *)PTR_CRYPTO_free_006a7f88)(ppAStack_16c);
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar10);
    puStack_1ec = puVar10;
  }
  if (pcStack_134 == *(code **)puStack_168) {
    return pvStack_178;
  }
  pcStack_15c = ASN1_i2d_bio;
  pcStack_1b4 = pcStack_134;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1a8 = PTR___stack_chk_guard_006aabf0;
  pAStack_17c = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  puStack_170 = puStack_1ec;
  pcStack_160 = unaff_s6;
  pAStack_1b8 = (ASN1_VALUE *)(*pcStack_1b4)(iVar5,0);
  puVar10 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(pAStack_1b8,"a_i2d_fp.c",0x5b);
  if (puVar10 == (undefined *)0x0) {
    pAVar9 = (ASN1_VALUE *)&DAT_00000041;
    puVar18 = &DAT_00000074;
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5e);
    pAVar14 = (ASN1_VALUE *)0x0;
  }
  else {
    puStack_180 = puVar10;
    (*pcStack_1b4)(iVar5,&puStack_180);
    pcStack_1b4 = (code *)0x0;
    while( true ) {
      puVar18 = puVar10 + (int)pcStack_1b4;
      pAVar9 = pAStack_1b8;
      pAVar14 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a7f14)(pcStack_1ac,puVar18);
      if (pAStack_1b8 == pAVar14) break;
      if ((int)pAVar14 < 1) {
        pAVar14 = (ASN1_VALUE *)0x0;
        goto LAB_0054fd84;
      }
      pcStack_1b4 = pcStack_1b4 + (int)pAVar14;
      pAStack_1b8 = pAStack_1b8 + -(int)pAVar14;
    }
    pAVar14 = (ASN1_VALUE *)0x1;
LAB_0054fd84:
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar10);
    pAStack_1b8 = pAVar14;
    puStack_1ec = puVar10;
  }
  if (pAStack_17c == *(ASN1_ITEM **)puStack_1a8) {
    return pAVar14;
  }
  pcStack_1a4 = ASN1_item_i2d_fp;
  pAStack_230 = pAStack_17c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1e8 = PTR___stack_chk_guard_006aabf0;
  pAStack_1bc = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  puStack_1b0 = puStack_1ec;
  uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  puVar10 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar4);
  if (puVar10 == (undefined *)0x0) {
    pAVar9 = (ASN1_VALUE *)&DAT_00000007;
    puStack_22c = (uchar *)0xc1;
    pvStack_234 = (void *)0x0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7f);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar10,0x6a,0,puVar18);
    puStack_1c0 = (uchar *)0x0;
    pAVar14 = (ASN1_VALUE *)ASN1_item_i2d(pAVar9,&puStack_1c0,pAStack_230);
    if (puStack_1c0 == (uchar *)0x0) {
      pAVar9 = (ASN1_VALUE *)&DAT_00000041;
      puStack_22c = &DAT_000000c0;
      pvStack_234 = (void *)0x0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x91);
    }
    else {
      pAStack_230 = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_22c = puStack_1c0 + (int)pAStack_230;
        pAVar9 = pAVar14;
        pAVar15 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a7f14)(puVar10);
        if (pAVar14 == pAVar15) break;
        if ((int)pAVar15 < 1) {
          pvStack_234 = (void *)0x0;
          puStack_22c = puStack_1c0;
          goto LAB_0054fef0;
        }
        pAStack_230 = (ASN1_ITEM *)(pAVar15 + (int)&pAStack_230->itype);
        pAVar14 = pAVar14 + -(int)pAVar15;
      }
      pvStack_234 = (void *)0x1;
LAB_0054fef0:
      (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_1c0);
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar10);
    puStack_1ec = puVar10;
  }
  if (pAStack_1bc == *(ASN1_ITEM **)puStack_1e8) {
    return pvStack_234;
  }
  pcStack_1e4 = ASN1_item_i2d_bio;
  it = pAStack_1bc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_228 = PTR___stack_chk_guard_006aabf0;
  puStack_200 = (uchar *)0x0;
  piStack_1fc = *(int **)PTR___stack_chk_guard_006aabf0;
  pvStack_1f4 = pvStack_234;
  pAStack_1f0 = pAStack_230;
  iVar5 = ASN1_item_i2d(pAVar9,&puStack_200,it);
  if (puStack_200 == (uchar *)0x0) {
    puVar19 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x91);
    pvVar8 = (void *)0x0;
  }
  else {
    pAStack_230 = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar19 = puStack_200 + (int)pAStack_230;
      iVar12 = (*(code *)PTR_BIO_write_006a7f14)(puStack_22c,puVar19,iVar5);
      if (iVar5 == iVar12) break;
      if (iVar12 < 1) {
        pvVar8 = (void *)0x0;
        puVar19 = puStack_200;
        goto LAB_00550050;
      }
      pAStack_230 = (ASN1_ITEM *)(&pAStack_230->itype + iVar12);
      iVar5 = iVar5 - iVar12;
    }
    pvVar8 = (void *)0x1;
LAB_00550050:
    (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_200);
    pvStack_234 = pvVar8;
  }
  if (piStack_1fc == *(int **)puStack_228) {
    return pvVar8;
  }
  pcStack_224 = ASN1_ENUMERATED_set;
  piVar16 = piStack_1fc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar10 = PTR___stack_chk_guard_006aabf0;
  piVar16[1] = 10;
  piStack_23c = *(int **)puVar10;
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
        auStack_246[2] = (char)puVar19;
        if ((int)puVar19 >> 8 == 0) {
          iVar5 = 1;
LAB_00550260:
          iVar12 = iVar5 + -1;
          *puVar18 = auStack_246[iVar5 + 1];
          if (iVar5 != 1) {
            iVar13 = iVar5 + -3;
            *(undefined *)(piVar16[2] + 1) = auStack_246[iVar5];
            if (iVar13 == -1) goto LAB_005501f0;
            goto LAB_005501c8;
          }
        }
        else {
          auStack_246[3] = (char)((uint)puVar19 >> 8);
          if ((int)puVar19 >> 0x10 == 0) {
            iVar5 = 2;
            goto LAB_00550260;
          }
          auStack_246[4] = (undefined)((uint)puVar19 >> 0x10);
          if ((int)puVar19 >> 0x18 == 0) {
            iVar5 = 3;
            goto LAB_00550260;
          }
          auStack_246[5] = (undefined)((uint)puVar19 >> 0x18);
          *puVar18 = auStack_246[5];
          iVar12 = 3;
          iVar13 = 1;
          *(undefined *)(piVar16[2] + 1) = auStack_246[4];
LAB_005501c8:
          *(undefined *)(piVar16[2] + 2) = auStack_246[iVar13 + 2];
          if (iVar13 != 0) {
            *(char *)(piVar16[2] + 3) = (char)puVar19;
          }
        }
        iVar5 = iVar12 + 1;
      }
      else {
        iVar5 = 0;
        if (puVar19 != (uchar *)0x0) goto LAB_0055018c;
      }
LAB_005501f0:
      pvVar8 = (void *)0x1;
      *piVar16 = iVar5;
      goto LAB_005501f8;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x56);
  pvVar8 = (void *)0x0;
LAB_005501f8:
  if (piStack_23c == *(int **)puVar10) {
    return pvVar8;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (piStack_23c != (int *)0x0) {
    if (piStack_23c[1] == 0x10a) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (piStack_23c[1] != 10) {
        return (void *)0xffffffff;
      }
    }
    iVar5 = *piStack_23c;
    if (4 < iVar5) {
      return (void *)0xffffffff;
    }
    pbVar17 = (byte *)piStack_23c[2];
    if (pbVar17 != (byte *)0x0) {
      if (iVar5 < 1) {
        pvVar8 = (void *)0x0;
      }
      else {
        pvVar8 = (void *)(uint)*pbVar17;
        if (iVar5 != 1) {
          uVar1 = CONCAT11(*pbVar17,pbVar17[1]);
          pvVar8 = (void *)(uint)uVar1;
          if (iVar5 != 2) {
            uVar2 = CONCAT21(uVar1,pbVar17[2]);
            pvVar8 = (void *)(uint)uVar2;
            if (iVar5 == 4) {
              pvVar8 = (void *)CONCAT31(uVar2,pbVar17[3]);
            }
          }
        }
      }
      if (!bVar3) {
        return pvVar8;
      }
      return (void *)-(int)pvVar8;
    }
  }
  return (void *)0x0;
}

