
void * ASN1_d2i_bio(xnew *xnew,undefined1 *d2i,BIO *in,void **x)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  BIO *pBVar4;
  void *pvVar5;
  ASN1_VALUE *pAVar6;
  undefined4 uVar7;
  undefined *puVar8;
  int iVar9;
  uchar **ppuVar10;
  int iVar11;
  int iVar12;
  ASN1_VALUE *pAVar13;
  ASN1_VALUE *pAVar14;
  ASN1_ITEM *it;
  int *piVar15;
  byte *pbVar16;
  uchar **in_00;
  undefined *puVar17;
  uchar *puVar18;
  char *unaff_s6;
  undefined auStack_1fe [10];
  int *piStack_1f4;
  void *pvStack_1ec;
  ASN1_ITEM *pAStack_1e8;
  uchar *puStack_1e4;
  undefined *puStack_1e0;
  code *pcStack_1dc;
  uchar *puStack_1b8;
  int *piStack_1b4;
  void *pvStack_1ac;
  ASN1_ITEM *pAStack_1a8;
  undefined *puStack_1a4;
  undefined *puStack_1a0;
  code *pcStack_19c;
  uchar *puStack_178;
  ASN1_ITEM *pAStack_174;
  ASN1_VALUE *pAStack_170;
  code *pcStack_16c;
  undefined *puStack_168;
  code *pcStack_164;
  undefined *puStack_160;
  code *pcStack_15c;
  undefined *puStack_138;
  ASN1_ITEM *pAStack_134;
  void *pvStack_130;
  code *pcStack_12c;
  undefined *puStack_128;
  BIO *pBStack_124;
  undefined *puStack_120;
  int iStack_11c;
  char *pcStack_118;
  code *pcStack_114;
  BIO *pBStack_f0;
  code *pcStack_ec;
  undefined *puStack_e8;
  uchar **ppuStack_e4;
  undefined *puStack_e0;
  BIO *pBStack_dc;
  ASN1_ITEM *pAStack_d8;
  uchar *puStack_a4;
  uchar *puStack_a0;
  code *pcStack_9c;
  undefined *puStack_98;
  BIO *pBStack_94;
  ASN1_ITEM *pAStack_90;
  uchar *puStack_5c;
  uchar *puStack_58;
  ASN1_ITEM *pAStack_54;
  undefined *puStack_50;
  undefined1 *puStack_4c;
  void **ppvStack_48;
  code *pcStack_44;
  undefined *local_30;
  void *local_24;
  int local_1c;
  int local_18;
  ASN1_ITEM *local_14;
  
  puStack_50 = PTR___stack_chk_guard_006a9ae8;
  piVar15 = &local_1c;
  local_30 = &_gp;
  local_1c = 0;
  local_14 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pBVar4 = (BIO *)asn1_d2i_read_bio_constprop_0(in,piVar15);
  if ((int)pBVar4 < 0) {
    pvVar5 = (void *)0x0;
  }
  else {
    piVar15 = &local_18;
    local_18 = *(int *)(local_1c + 4);
    pvVar5 = (void *)(*(code *)d2i)(x,piVar15);
    in = pBVar4;
  }
  if (local_1c != 0) {
    local_24 = pvVar5;
    (**(code **)(local_30 + -0x794c))();
    pvVar5 = local_24;
  }
  if (local_14 == *(ASN1_ITEM **)puStack_50) {
    return pvVar5;
  }
  pcStack_44 = ASN1_item_d2i_bio;
  pAStack_90 = local_14;
  (**(code **)(local_30 + -0x5330))();
  puStack_e8 = PTR___stack_chk_guard_006a9ae8;
  ppuStack_e4 = &puStack_5c;
  puStack_5c = (uchar *)0x0;
  pAStack_54 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pBStack_124 = in;
  puStack_4c = d2i;
  ppvStack_48 = x;
  pBVar4 = (BIO *)asn1_d2i_read_bio_constprop_0(piVar15);
  if ((int)pBVar4 < 0) {
    pAVar6 = (ASN1_VALUE *)0x0;
  }
  else {
    ppuStack_e4 = &puStack_58;
    puStack_58 = *(uchar **)(puStack_5c + 4);
    pAVar6 = ASN1_item_d2i((ASN1_VALUE **)in,ppuStack_e4,(long)pBVar4,pAStack_90);
    pBStack_124 = pBVar4;
  }
  if (puStack_5c != (uchar *)0x0) {
    (*(code *)PTR_BUF_MEM_free_006a7494)();
  }
  if (pAStack_54 == *(ASN1_ITEM **)puStack_e8) {
    return pAVar6;
  }
  pAStack_d8 = pAStack_54;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1a4 = PTR___stack_chk_guard_006a9ae8;
  puStack_98 = puStack_e8;
  pcStack_9c = *(code **)PTR___stack_chk_guard_006a9ae8;
  pBStack_94 = in;
  uVar7 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar8 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar7);
  if (puVar8 == (undefined *)0x0) {
    iStack_11c = 7;
    in_00 = (uchar **)0xce;
    ERR_put_error(0xd,0xce,7,"a_d2i_fp.c",0x85);
    ppuVar10 = (uchar **)0x0;
  }
  else {
    iStack_11c = 0;
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar8,0x6a,0,ppuStack_e4);
    in_00 = &puStack_a4;
    puStack_a4 = (uchar *)0x0;
    iVar9 = asn1_d2i_read_bio_constprop_0(puVar8,in_00);
    if (iVar9 < 0) {
      ppuVar10 = (uchar **)0x0;
    }
    else {
      in_00 = &puStack_a0;
      puStack_a0 = *(uchar **)(puStack_a4 + 4);
      ppuVar10 = (uchar **)ASN1_item_d2i((ASN1_VALUE **)pBStack_124,in_00,iVar9,pAStack_d8);
      iStack_11c = iVar9;
    }
    if (puStack_a4 != (uchar *)0x0) {
      (*(code *)PTR_BUF_MEM_free_006a7494)();
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar8);
    puStack_e8 = puVar8;
    ppuStack_e4 = ppuVar10;
  }
  if (pcStack_9c == *(code **)puStack_1a4) {
    return ppuVar10;
  }
  pcStack_12c = pcStack_9c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_120 = PTR___stack_chk_guard_006a9ae8;
  puStack_e0 = puStack_1a4;
  pcStack_ec = *(code **)PTR___stack_chk_guard_006a9ae8;
  pBStack_dc = pBStack_124;
  uVar7 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar8 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar7);
  if (puVar8 == (undefined *)0x0) {
    iVar9 = 7;
    pcStack_164 = (code *)0x75;
    pvStack_130 = (void *)0x0;
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x49);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar8,0x6a,0,in_00);
    iVar11 = (*pcStack_12c)(iStack_11c,0);
    unaff_s6 = "encrypt";
    pBStack_124 = (BIO *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar11,"a_i2d_fp.c",0x5a);
    if (pBStack_124 == (BIO *)0x0) {
      iVar9 = 0x41;
      pcStack_164 = (code *)&DAT_00000074;
      pvStack_130 = (void *)0x0;
      ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    }
    else {
      pBStack_f0 = pBStack_124;
      (*pcStack_12c)(iStack_11c,&pBStack_f0);
      pcStack_12c = (code *)0x0;
      while( true ) {
        pcStack_164 = pcStack_12c + (int)&pBStack_124->method;
        iVar9 = iVar11;
        iVar12 = (*(code *)PTR_BIO_write_006a6e14)(puVar8,pcStack_164,iVar11);
        if (iVar11 == iVar12) break;
        if (iVar12 < 1) {
          pvStack_130 = (void *)0x0;
          goto LAB_0054c974;
        }
        pcStack_12c = pcStack_12c + iVar12;
        iVar11 = iVar11 - iVar12;
      }
      pvStack_130 = (void *)0x1;
LAB_0054c974:
      (*(code *)PTR_CRYPTO_free_006a6e88)(pBStack_124);
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar8);
    puStack_1a4 = puVar8;
  }
  if (pcStack_ec == *(code **)puStack_120) {
    return pvStack_130;
  }
  pcStack_114 = ASN1_i2d_bio;
  pcStack_16c = pcStack_ec;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_160 = PTR___stack_chk_guard_006a9ae8;
  pAStack_134 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_128 = puStack_1a4;
  pcStack_118 = unaff_s6;
  pAStack_170 = (ASN1_VALUE *)(*pcStack_16c)(iVar9,0);
  puVar8 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(pAStack_170,"a_i2d_fp.c",0x5a);
  if (puVar8 == (undefined *)0x0) {
    pAVar6 = (ASN1_VALUE *)&DAT_00000041;
    puVar17 = &DAT_00000074;
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    pAVar13 = (ASN1_VALUE *)0x0;
  }
  else {
    puStack_138 = puVar8;
    (*pcStack_16c)(iVar9,&puStack_138);
    pcStack_16c = (code *)0x0;
    while( true ) {
      puVar17 = puVar8 + (int)pcStack_16c;
      pAVar6 = pAStack_170;
      pAVar13 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(pcStack_164,puVar17);
      if (pAStack_170 == pAVar13) break;
      if ((int)pAVar13 < 1) {
        pAVar13 = (ASN1_VALUE *)0x0;
        goto LAB_0054cb14;
      }
      pcStack_16c = pcStack_16c + (int)pAVar13;
      pAStack_170 = pAStack_170 + -(int)pAVar13;
    }
    pAVar13 = (ASN1_VALUE *)0x1;
LAB_0054cb14:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar8);
    pAStack_170 = pAVar13;
    puStack_1a4 = puVar8;
  }
  if (pAStack_134 == *(ASN1_ITEM **)puStack_160) {
    return pAVar13;
  }
  pcStack_15c = ASN1_item_i2d_fp;
  pAStack_1e8 = pAStack_134;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1a0 = PTR___stack_chk_guard_006a9ae8;
  pAStack_174 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_168 = puStack_1a4;
  uVar7 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar8 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar7);
  if (puVar8 == (undefined *)0x0) {
    pAVar6 = (ASN1_VALUE *)&DAT_00000007;
    puStack_1e4 = (uchar *)0xc1;
    pvStack_1ec = (void *)0x0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7b);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar8,0x6a,0,puVar17);
    puStack_178 = (uchar *)0x0;
    pAVar13 = (ASN1_VALUE *)ASN1_item_i2d(pAVar6,&puStack_178,pAStack_1e8);
    if (puStack_178 == (uchar *)0x0) {
      pAVar6 = (ASN1_VALUE *)&DAT_00000041;
      puStack_1e4 = &DAT_000000c0;
      pvStack_1ec = (void *)0x0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    }
    else {
      pAStack_1e8 = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_1e4 = puStack_178 + (int)pAStack_1e8;
        pAVar6 = pAVar13;
        pAVar14 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(puVar8);
        if (pAVar13 == pAVar14) break;
        if ((int)pAVar14 < 1) {
          pvStack_1ec = (void *)0x0;
          puStack_1e4 = puStack_178;
          goto LAB_0054cc80;
        }
        pAStack_1e8 = (ASN1_ITEM *)(pAVar14 + (int)&pAStack_1e8->itype);
        pAVar13 = pAVar13 + -(int)pAVar14;
      }
      pvStack_1ec = (void *)0x1;
LAB_0054cc80:
      (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_178);
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar8);
    puStack_1a4 = puVar8;
  }
  if (pAStack_174 == *(ASN1_ITEM **)puStack_1a0) {
    return pvStack_1ec;
  }
  pcStack_19c = ASN1_item_i2d_bio;
  it = pAStack_174;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1e0 = PTR___stack_chk_guard_006a9ae8;
  puStack_1b8 = (uchar *)0x0;
  piStack_1b4 = *(int **)PTR___stack_chk_guard_006a9ae8;
  pvStack_1ac = pvStack_1ec;
  pAStack_1a8 = pAStack_1e8;
  iVar9 = ASN1_item_i2d(pAVar6,&puStack_1b8,it);
  if (puStack_1b8 == (uchar *)0x0) {
    puVar18 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    pvVar5 = (void *)0x0;
  }
  else {
    pAStack_1e8 = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar18 = puStack_1b8 + (int)pAStack_1e8;
      iVar11 = (*(code *)PTR_BIO_write_006a6e14)(puStack_1e4,puVar18,iVar9);
      if (iVar9 == iVar11) break;
      if (iVar11 < 1) {
        pvVar5 = (void *)0x0;
        puVar18 = puStack_1b8;
        goto LAB_0054cde0;
      }
      pAStack_1e8 = (ASN1_ITEM *)(&pAStack_1e8->itype + iVar11);
      iVar9 = iVar9 - iVar11;
    }
    pvVar5 = (void *)0x1;
LAB_0054cde0:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_1b8);
    pvStack_1ec = pvVar5;
  }
  if (piStack_1b4 == *(int **)puStack_1e0) {
    return pvVar5;
  }
  pcStack_1dc = ASN1_ENUMERATED_set;
  piVar15 = piStack_1b4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar8 = PTR___stack_chk_guard_006a9ae8;
  piVar15[1] = 10;
  piStack_1f4 = *(int **)puVar8;
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
        auStack_1fe[2] = (char)puVar18;
        if ((int)puVar18 >> 8 == 0) {
          iVar9 = 1;
LAB_0054cff0:
          iVar11 = iVar9 + -1;
          *puVar17 = auStack_1fe[iVar9 + 1];
          if (iVar9 != 1) {
            iVar12 = iVar9 + -3;
            *(undefined *)(piVar15[2] + 1) = auStack_1fe[iVar9];
            if (iVar12 == -1) goto LAB_0054cf80;
            goto LAB_0054cf58;
          }
        }
        else {
          auStack_1fe[3] = (char)((uint)puVar18 >> 8);
          if ((int)puVar18 >> 0x10 == 0) {
            iVar9 = 2;
            goto LAB_0054cff0;
          }
          auStack_1fe[4] = (undefined)((uint)puVar18 >> 0x10);
          if ((int)puVar18 >> 0x18 == 0) {
            iVar9 = 3;
            goto LAB_0054cff0;
          }
          auStack_1fe[5] = (undefined)((uint)puVar18 >> 0x18);
          *puVar17 = auStack_1fe[5];
          iVar11 = 3;
          iVar12 = 1;
          *(undefined *)(piVar15[2] + 1) = auStack_1fe[4];
LAB_0054cf58:
          *(undefined *)(piVar15[2] + 2) = auStack_1fe[iVar12 + 2];
          if (iVar12 != 0) {
            *(char *)(piVar15[2] + 3) = (char)puVar18;
          }
        }
        iVar9 = iVar11 + 1;
      }
      else {
        iVar9 = 0;
        if (puVar18 != (uchar *)0x0) goto LAB_0054cf1c;
      }
LAB_0054cf80:
      pvVar5 = (void *)0x1;
      *piVar15 = iVar9;
      goto LAB_0054cf88;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x55);
  pvVar5 = (void *)0x0;
LAB_0054cf88:
  if (piStack_1f4 == *(int **)puVar8) {
    return pvVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piStack_1f4 != (int *)0x0) {
    if (piStack_1f4[1] == 0x10a) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (piStack_1f4[1] != 10) {
        return (void *)0xffffffff;
      }
    }
    iVar9 = *piStack_1f4;
    if (4 < iVar9) {
      return (void *)0xffffffff;
    }
    pbVar16 = (byte *)piStack_1f4[2];
    if (pbVar16 != (byte *)0x0) {
      if (iVar9 < 1) {
        pvVar5 = (void *)0x0;
      }
      else {
        pvVar5 = (void *)(uint)*pbVar16;
        if (iVar9 != 1) {
          uVar1 = CONCAT11(*pbVar16,pbVar16[1]);
          pvVar5 = (void *)(uint)uVar1;
          if (iVar9 != 2) {
            uVar2 = CONCAT21(uVar1,pbVar16[2]);
            pvVar5 = (void *)(uint)uVar2;
            if (iVar9 == 4) {
              pvVar5 = (void *)CONCAT31(uVar2,pbVar16[3]);
            }
          }
        }
      }
      if (!bVar3) {
        return pvVar5;
      }
      return (void *)-(int)pvVar5;
    }
  }
  return (void *)0x0;
}

