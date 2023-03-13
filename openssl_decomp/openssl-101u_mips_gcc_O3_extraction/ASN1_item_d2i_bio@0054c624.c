
void * ASN1_item_d2i_bio(ASN1_ITEM *it,BIO *in,void *x)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  ASN1_VALUE **len;
  ASN1_VALUE *pAVar4;
  undefined4 uVar5;
  undefined *puVar6;
  int iVar7;
  uchar **ppuVar8;
  int iVar9;
  int iVar10;
  ASN1_VALUE *pAVar11;
  ASN1_VALUE *pAVar12;
  ASN1_ITEM *it_00;
  int *piVar13;
  byte *pbVar14;
  uchar **in_00;
  undefined *puVar15;
  uchar *puVar16;
  void *pvVar17;
  char *unaff_s6;
  undefined auStack_1be [10];
  int *piStack_1b4;
  void *pvStack_1ac;
  ASN1_ITEM *pAStack_1a8;
  uchar *puStack_1a4;
  undefined *puStack_1a0;
  code *pcStack_19c;
  uchar *puStack_178;
  int *piStack_174;
  void *pvStack_16c;
  ASN1_ITEM *pAStack_168;
  undefined *puStack_164;
  undefined *puStack_160;
  code *pcStack_15c;
  uchar *puStack_138;
  ASN1_ITEM *pAStack_134;
  ASN1_VALUE *pAStack_130;
  code *pcStack_12c;
  undefined *puStack_128;
  code *pcStack_124;
  undefined *puStack_120;
  code *pcStack_11c;
  undefined *puStack_f8;
  ASN1_ITEM *pAStack_f4;
  void *pvStack_f0;
  code *pcStack_ec;
  undefined *puStack_e8;
  ASN1_VALUE **ppAStack_e4;
  undefined *puStack_e0;
  int iStack_dc;
  char *pcStack_d8;
  code *pcStack_d4;
  ASN1_VALUE **ppAStack_b0;
  code *pcStack_ac;
  undefined *puStack_a8;
  uchar **ppuStack_a4;
  undefined *puStack_a0;
  ASN1_VALUE **ppAStack_9c;
  ASN1_ITEM *pAStack_98;
  uchar *puStack_64;
  uchar *puStack_60;
  code *pcStack_5c;
  undefined *puStack_58;
  void *pvStack_54;
  ASN1_ITEM *pAStack_50;
  uchar *local_1c;
  uchar *local_18;
  ASN1_ITEM *local_14;
  
  puStack_a8 = PTR___stack_chk_guard_006a9ae8;
  ppuStack_a4 = &local_1c;
  local_1c = (uchar *)0x0;
  local_14 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  ppAStack_e4 = (ASN1_VALUE **)x;
  len = (ASN1_VALUE **)asn1_d2i_read_bio_constprop_0(in);
  if ((int)len < 0) {
    pAVar4 = (ASN1_VALUE *)0x0;
  }
  else {
    ppuStack_a4 = &local_18;
    local_18 = *(uchar **)(local_1c + 4);
    pAVar4 = ASN1_item_d2i((ASN1_VALUE **)x,ppuStack_a4,(long)len,it);
    ppAStack_e4 = len;
  }
  if (local_1c != (uchar *)0x0) {
    (*(code *)PTR_BUF_MEM_free_006a7494)();
  }
  if (local_14 == *(ASN1_ITEM **)puStack_a8) {
    return pAVar4;
  }
  pAStack_98 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_164 = PTR___stack_chk_guard_006a9ae8;
  puStack_58 = puStack_a8;
  pcStack_5c = *(code **)PTR___stack_chk_guard_006a9ae8;
  pvStack_54 = x;
  pAStack_50 = it;
  uVar5 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar6 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar5);
  if (puVar6 == (undefined *)0x0) {
    iStack_dc = 7;
    in_00 = (uchar **)0xce;
    ERR_put_error(0xd,0xce,7,"a_d2i_fp.c",0x85);
    ppuVar8 = (uchar **)0x0;
  }
  else {
    iStack_dc = 0;
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar6,0x6a,0,ppuStack_a4);
    in_00 = &puStack_64;
    puStack_64 = (uchar *)0x0;
    iVar7 = asn1_d2i_read_bio_constprop_0(puVar6,in_00);
    if (iVar7 < 0) {
      ppuVar8 = (uchar **)0x0;
    }
    else {
      in_00 = &puStack_60;
      puStack_60 = *(uchar **)(puStack_64 + 4);
      ppuVar8 = (uchar **)ASN1_item_d2i(ppAStack_e4,in_00,iVar7,pAStack_98);
      iStack_dc = iVar7;
    }
    if (puStack_64 != (uchar *)0x0) {
      (*(code *)PTR_BUF_MEM_free_006a7494)();
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar6);
    puStack_a8 = puVar6;
    ppuStack_a4 = ppuVar8;
  }
  if (pcStack_5c == *(code **)puStack_164) {
    return ppuVar8;
  }
  pcStack_ec = pcStack_5c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_e0 = PTR___stack_chk_guard_006a9ae8;
  puStack_a0 = puStack_164;
  pcStack_ac = *(code **)PTR___stack_chk_guard_006a9ae8;
  ppAStack_9c = ppAStack_e4;
  uVar5 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar6 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar5);
  if (puVar6 == (undefined *)0x0) {
    iVar7 = 7;
    pcStack_124 = (code *)0x75;
    pvStack_f0 = (void *)0x0;
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x49);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar6,0x6a,0,in_00);
    iVar9 = (*pcStack_ec)(iStack_dc,0);
    unaff_s6 = "encrypt";
    ppAStack_e4 = (ASN1_VALUE **)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar9,"a_i2d_fp.c",0x5a);
    if (ppAStack_e4 == (ASN1_VALUE **)0x0) {
      iVar7 = 0x41;
      pcStack_124 = (code *)&DAT_00000074;
      pvStack_f0 = (void *)0x0;
      ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    }
    else {
      ppAStack_b0 = ppAStack_e4;
      (*pcStack_ec)(iStack_dc,&ppAStack_b0);
      pcStack_ec = (code *)0x0;
      while( true ) {
        pcStack_124 = (code *)((int)ppAStack_e4 + (int)pcStack_ec);
        iVar7 = iVar9;
        iVar10 = (*(code *)PTR_BIO_write_006a6e14)(puVar6,pcStack_124,iVar9);
        if (iVar9 == iVar10) break;
        if (iVar10 < 1) {
          pvStack_f0 = (void *)0x0;
          goto LAB_0054c974;
        }
        pcStack_ec = pcStack_ec + iVar10;
        iVar9 = iVar9 - iVar10;
      }
      pvStack_f0 = (void *)0x1;
LAB_0054c974:
      (*(code *)PTR_CRYPTO_free_006a6e88)(ppAStack_e4);
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar6);
    puStack_164 = puVar6;
  }
  if (pcStack_ac == *(code **)puStack_e0) {
    return pvStack_f0;
  }
  pcStack_d4 = ASN1_i2d_bio;
  pcStack_12c = pcStack_ac;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_120 = PTR___stack_chk_guard_006a9ae8;
  pAStack_f4 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_e8 = puStack_164;
  pcStack_d8 = unaff_s6;
  pAStack_130 = (ASN1_VALUE *)(*pcStack_12c)(iVar7,0);
  puVar6 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(pAStack_130,"a_i2d_fp.c",0x5a);
  if (puVar6 == (undefined *)0x0) {
    pAVar4 = (ASN1_VALUE *)&DAT_00000041;
    puVar15 = &DAT_00000074;
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    pAVar11 = (ASN1_VALUE *)0x0;
  }
  else {
    puStack_f8 = puVar6;
    (*pcStack_12c)(iVar7,&puStack_f8);
    pcStack_12c = (code *)0x0;
    while( true ) {
      puVar15 = puVar6 + (int)pcStack_12c;
      pAVar4 = pAStack_130;
      pAVar11 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(pcStack_124,puVar15);
      if (pAStack_130 == pAVar11) break;
      if ((int)pAVar11 < 1) {
        pAVar11 = (ASN1_VALUE *)0x0;
        goto LAB_0054cb14;
      }
      pcStack_12c = pcStack_12c + (int)pAVar11;
      pAStack_130 = pAStack_130 + -(int)pAVar11;
    }
    pAVar11 = (ASN1_VALUE *)0x1;
LAB_0054cb14:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar6);
    pAStack_130 = pAVar11;
    puStack_164 = puVar6;
  }
  if (pAStack_f4 == *(ASN1_ITEM **)puStack_120) {
    return pAVar11;
  }
  pcStack_11c = ASN1_item_i2d_fp;
  pAStack_1a8 = pAStack_f4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_160 = PTR___stack_chk_guard_006a9ae8;
  pAStack_134 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_128 = puStack_164;
  uVar5 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar6 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar5);
  if (puVar6 == (undefined *)0x0) {
    pAVar4 = (ASN1_VALUE *)&DAT_00000007;
    puStack_1a4 = (uchar *)0xc1;
    pvStack_1ac = (void *)0x0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7b);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar6,0x6a,0,puVar15);
    puStack_138 = (uchar *)0x0;
    pAVar11 = (ASN1_VALUE *)ASN1_item_i2d(pAVar4,&puStack_138,pAStack_1a8);
    if (puStack_138 == (uchar *)0x0) {
      pAVar4 = (ASN1_VALUE *)&DAT_00000041;
      puStack_1a4 = &DAT_000000c0;
      pvStack_1ac = (void *)0x0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    }
    else {
      pAStack_1a8 = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_1a4 = puStack_138 + (int)pAStack_1a8;
        pAVar4 = pAVar11;
        pAVar12 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(puVar6);
        if (pAVar11 == pAVar12) break;
        if ((int)pAVar12 < 1) {
          pvStack_1ac = (void *)0x0;
          puStack_1a4 = puStack_138;
          goto LAB_0054cc80;
        }
        pAStack_1a8 = (ASN1_ITEM *)(pAVar12 + (int)&pAStack_1a8->itype);
        pAVar11 = pAVar11 + -(int)pAVar12;
      }
      pvStack_1ac = (void *)0x1;
LAB_0054cc80:
      (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_138);
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar6);
    puStack_164 = puVar6;
  }
  if (pAStack_134 == *(ASN1_ITEM **)puStack_160) {
    return pvStack_1ac;
  }
  pcStack_15c = ASN1_item_i2d_bio;
  it_00 = pAStack_134;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1a0 = PTR___stack_chk_guard_006a9ae8;
  puStack_178 = (uchar *)0x0;
  piStack_174 = *(int **)PTR___stack_chk_guard_006a9ae8;
  pvStack_16c = pvStack_1ac;
  pAStack_168 = pAStack_1a8;
  iVar7 = ASN1_item_i2d(pAVar4,&puStack_178,it_00);
  if (puStack_178 == (uchar *)0x0) {
    puVar16 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    pvVar17 = (void *)0x0;
  }
  else {
    pAStack_1a8 = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar16 = puStack_178 + (int)pAStack_1a8;
      iVar9 = (*(code *)PTR_BIO_write_006a6e14)(puStack_1a4,puVar16,iVar7);
      if (iVar7 == iVar9) break;
      if (iVar9 < 1) {
        pvVar17 = (void *)0x0;
        puVar16 = puStack_178;
        goto LAB_0054cde0;
      }
      pAStack_1a8 = (ASN1_ITEM *)(&pAStack_1a8->itype + iVar9);
      iVar7 = iVar7 - iVar9;
    }
    pvVar17 = (void *)0x1;
LAB_0054cde0:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_178);
    pvStack_1ac = pvVar17;
  }
  if (piStack_174 == *(int **)puStack_1a0) {
    return pvVar17;
  }
  pcStack_19c = ASN1_ENUMERATED_set;
  piVar13 = piStack_174;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar6 = PTR___stack_chk_guard_006a9ae8;
  piVar13[1] = 10;
  piStack_1b4 = *(int **)puVar6;
  if (*piVar13 < 5) {
    if (piVar13[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar15 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(5,"a_enum.c",0x51);
    piVar13[2] = (int)puVar15;
    if (puVar15 != (undefined *)0x0) {
      *puVar15 = 0;
      puVar15[1] = 0;
      puVar15[2] = 0;
      puVar15[3] = 0;
      puVar15[4] = 0;
      goto LAB_0054cf00;
    }
  }
  else {
LAB_0054cf00:
    puVar15 = (undefined *)piVar13[2];
    if (puVar15 != (undefined *)0x0) {
      if ((int)puVar16 < 0) {
        puVar16 = (uchar *)-(int)puVar16;
        piVar13[1] = 0x10a;
LAB_0054cf1c:
        auStack_1be[2] = (char)puVar16;
        if ((int)puVar16 >> 8 == 0) {
          iVar7 = 1;
LAB_0054cff0:
          iVar9 = iVar7 + -1;
          *puVar15 = auStack_1be[iVar7 + 1];
          if (iVar7 != 1) {
            iVar10 = iVar7 + -3;
            *(undefined *)(piVar13[2] + 1) = auStack_1be[iVar7];
            if (iVar10 == -1) goto LAB_0054cf80;
            goto LAB_0054cf58;
          }
        }
        else {
          auStack_1be[3] = (char)((uint)puVar16 >> 8);
          if ((int)puVar16 >> 0x10 == 0) {
            iVar7 = 2;
            goto LAB_0054cff0;
          }
          auStack_1be[4] = (undefined)((uint)puVar16 >> 0x10);
          if ((int)puVar16 >> 0x18 == 0) {
            iVar7 = 3;
            goto LAB_0054cff0;
          }
          auStack_1be[5] = (undefined)((uint)puVar16 >> 0x18);
          *puVar15 = auStack_1be[5];
          iVar9 = 3;
          iVar10 = 1;
          *(undefined *)(piVar13[2] + 1) = auStack_1be[4];
LAB_0054cf58:
          *(undefined *)(piVar13[2] + 2) = auStack_1be[iVar10 + 2];
          if (iVar10 != 0) {
            *(char *)(piVar13[2] + 3) = (char)puVar16;
          }
        }
        iVar7 = iVar9 + 1;
      }
      else {
        iVar7 = 0;
        if (puVar16 != (uchar *)0x0) goto LAB_0054cf1c;
      }
LAB_0054cf80:
      pvVar17 = (void *)0x1;
      *piVar13 = iVar7;
      goto LAB_0054cf88;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x55);
  pvVar17 = (void *)0x0;
LAB_0054cf88:
  if (piStack_1b4 == *(int **)puVar6) {
    return pvVar17;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piStack_1b4 != (int *)0x0) {
    if (piStack_1b4[1] == 0x10a) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (piStack_1b4[1] != 10) {
        return (void *)0xffffffff;
      }
    }
    iVar7 = *piStack_1b4;
    if (4 < iVar7) {
      return (void *)0xffffffff;
    }
    pbVar14 = (byte *)piStack_1b4[2];
    if (pbVar14 != (byte *)0x0) {
      if (iVar7 < 1) {
        pvVar17 = (void *)0x0;
      }
      else {
        pvVar17 = (void *)(uint)*pbVar14;
        if (iVar7 != 1) {
          uVar1 = CONCAT11(*pbVar14,pbVar14[1]);
          pvVar17 = (void *)(uint)uVar1;
          if (iVar7 != 2) {
            uVar2 = CONCAT21(uVar1,pbVar14[2]);
            pvVar17 = (void *)(uint)uVar2;
            if (iVar7 == 4) {
              pvVar17 = (void *)CONCAT31(uVar2,pbVar14[3]);
            }
          }
        }
      }
      if (!bVar3) {
        return pvVar17;
      }
      return (void *)-(int)pvVar17;
    }
  }
  return (void *)0x0;
}

