
void * ASN1_item_d2i_fp(ASN1_ITEM *it,FILE *in,void *x)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  FILE *pFVar7;
  undefined *puVar8;
  int iVar9;
  ASN1_VALUE *pAVar10;
  ASN1_VALUE *pAVar11;
  ASN1_ITEM *it_00;
  int *piVar12;
  byte *pbVar13;
  uchar **in_00;
  undefined *puVar14;
  uchar *puVar15;
  ASN1_VALUE *pAVar16;
  int unaff_s0;
  void *pvVar17;
  char *unaff_s6;
  undefined auStack_17e [10];
  int *piStack_174;
  void *pvStack_16c;
  ASN1_ITEM *pAStack_168;
  uchar *puStack_164;
  undefined *puStack_160;
  code *pcStack_15c;
  uchar *puStack_138;
  int *piStack_134;
  void *pvStack_12c;
  ASN1_ITEM *pAStack_128;
  undefined *puStack_124;
  undefined *puStack_120;
  code *pcStack_11c;
  uchar *puStack_f8;
  ASN1_ITEM *pAStack_f4;
  ASN1_VALUE *pAStack_f0;
  code *pcStack_ec;
  undefined *puStack_e8;
  code *pcStack_e4;
  undefined *puStack_e0;
  code *pcStack_dc;
  undefined *puStack_b8;
  ASN1_ITEM *pAStack_b4;
  void *pvStack_b0;
  code *pcStack_ac;
  undefined *puStack_a8;
  void *pvStack_a4;
  undefined *puStack_a0;
  int iStack_9c;
  char *pcStack_98;
  code *pcStack_94;
  void *pvStack_70;
  code *pcStack_6c;
  int iStack_68;
  FILE *pFStack_64;
  undefined *puStack_60;
  void *pvStack_5c;
  ASN1_ITEM *pAStack_58;
  uchar *local_24;
  uchar *local_20;
  code *local_1c;
  
  puStack_124 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(code **)PTR___stack_chk_guard_006a9ae8;
  uVar4 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar5 = (*(code *)PTR_BIO_new_006a6ea4)(uVar4);
  if (iVar5 == 0) {
    iStack_9c = 7;
    in_00 = (uchar **)0xce;
    ERR_put_error(0xd,0xce,7,"a_d2i_fp.c",0x85);
    pFVar7 = (FILE *)0x0;
  }
  else {
    iStack_9c = 0;
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar5,0x6a,0,in);
    in_00 = &local_24;
    local_24 = (uchar *)0x0;
    iVar6 = asn1_d2i_read_bio_constprop_0(iVar5,in_00);
    if (iVar6 < 0) {
      pFVar7 = (FILE *)0x0;
    }
    else {
      in_00 = &local_20;
      local_20 = *(uchar **)(local_24 + 4);
      pFVar7 = (FILE *)ASN1_item_d2i((ASN1_VALUE **)x,in_00,iVar6,it);
      iStack_9c = iVar6;
    }
    if (local_24 != (uchar *)0x0) {
      (*(code *)PTR_BUF_MEM_free_006a7494)();
    }
    (*(code *)PTR_BIO_free_006a6e70)(iVar5);
    unaff_s0 = iVar5;
    in = pFVar7;
  }
  if (local_1c == *(code **)puStack_124) {
    return pFVar7;
  }
  pcStack_ac = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_a0 = PTR___stack_chk_guard_006a9ae8;
  puStack_60 = puStack_124;
  pcStack_6c = *(code **)PTR___stack_chk_guard_006a9ae8;
  iStack_68 = unaff_s0;
  pFStack_64 = in;
  pvStack_5c = x;
  pAStack_58 = it;
  uVar4 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar8 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar4);
  if (puVar8 == (undefined *)0x0) {
    iVar5 = 7;
    pcStack_e4 = (code *)0x75;
    pvStack_b0 = (void *)0x0;
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x49);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar8,0x6a,0,in_00);
    iVar6 = (*pcStack_ac)(iStack_9c,0);
    unaff_s6 = "encrypt";
    x = (void *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar6,"a_i2d_fp.c",0x5a);
    if (x == (void *)0x0) {
      iVar5 = 0x41;
      pcStack_e4 = (code *)&DAT_00000074;
      pvStack_b0 = (void *)0x0;
      ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    }
    else {
      pvStack_70 = x;
      (*pcStack_ac)(iStack_9c,&pvStack_70);
      pcStack_ac = (code *)0x0;
      while( true ) {
        pcStack_e4 = (code *)((int)x + (int)pcStack_ac);
        iVar5 = iVar6;
        iVar9 = (*(code *)PTR_BIO_write_006a6e14)(puVar8,pcStack_e4,iVar6);
        if (iVar6 == iVar9) break;
        if (iVar9 < 1) {
          pvStack_b0 = (void *)0x0;
          goto LAB_0054c974;
        }
        pcStack_ac = pcStack_ac + iVar9;
        iVar6 = iVar6 - iVar9;
      }
      pvStack_b0 = (void *)0x1;
LAB_0054c974:
      (*(code *)PTR_CRYPTO_free_006a6e88)(x);
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar8);
    puStack_124 = puVar8;
  }
  if (pcStack_6c == *(code **)puStack_a0) {
    return pvStack_b0;
  }
  pcStack_94 = ASN1_i2d_bio;
  pcStack_ec = pcStack_6c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_e0 = PTR___stack_chk_guard_006a9ae8;
  pAStack_b4 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_a8 = puStack_124;
  pvStack_a4 = x;
  pcStack_98 = unaff_s6;
  pAStack_f0 = (ASN1_VALUE *)(*pcStack_ec)(iVar5,0);
  puVar8 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(pAStack_f0,"a_i2d_fp.c",0x5a);
  if (puVar8 == (undefined *)0x0) {
    pAVar16 = (ASN1_VALUE *)&DAT_00000041;
    puVar14 = &DAT_00000074;
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    pAVar10 = (ASN1_VALUE *)0x0;
  }
  else {
    puStack_b8 = puVar8;
    (*pcStack_ec)(iVar5,&puStack_b8);
    pcStack_ec = (code *)0x0;
    while( true ) {
      puVar14 = puVar8 + (int)pcStack_ec;
      pAVar16 = pAStack_f0;
      pAVar10 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(pcStack_e4,puVar14);
      if (pAStack_f0 == pAVar10) break;
      if ((int)pAVar10 < 1) {
        pAVar10 = (ASN1_VALUE *)0x0;
        goto LAB_0054cb14;
      }
      pcStack_ec = pcStack_ec + (int)pAVar10;
      pAStack_f0 = pAStack_f0 + -(int)pAVar10;
    }
    pAVar10 = (ASN1_VALUE *)0x1;
LAB_0054cb14:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar8);
    pAStack_f0 = pAVar10;
    puStack_124 = puVar8;
  }
  if (pAStack_b4 == *(ASN1_ITEM **)puStack_e0) {
    return pAVar10;
  }
  pcStack_dc = ASN1_item_i2d_fp;
  pAStack_168 = pAStack_b4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_120 = PTR___stack_chk_guard_006a9ae8;
  pAStack_f4 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_e8 = puStack_124;
  uVar4 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  puVar8 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar4);
  if (puVar8 == (undefined *)0x0) {
    pAVar16 = (ASN1_VALUE *)&DAT_00000007;
    puStack_164 = (uchar *)0xc1;
    pvStack_16c = (void *)0x0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7b);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar8,0x6a,0,puVar14);
    puStack_f8 = (uchar *)0x0;
    pAVar10 = (ASN1_VALUE *)ASN1_item_i2d(pAVar16,&puStack_f8,pAStack_168);
    if (puStack_f8 == (uchar *)0x0) {
      pAVar16 = (ASN1_VALUE *)&DAT_00000041;
      puStack_164 = &DAT_000000c0;
      pvStack_16c = (void *)0x0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    }
    else {
      pAStack_168 = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_164 = puStack_f8 + (int)pAStack_168;
        pAVar16 = pAVar10;
        pAVar11 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(puVar8);
        if (pAVar10 == pAVar11) break;
        if ((int)pAVar11 < 1) {
          pvStack_16c = (void *)0x0;
          puStack_164 = puStack_f8;
          goto LAB_0054cc80;
        }
        pAStack_168 = (ASN1_ITEM *)(pAVar11 + (int)&pAStack_168->itype);
        pAVar10 = pAVar10 + -(int)pAVar11;
      }
      pvStack_16c = (void *)0x1;
LAB_0054cc80:
      (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_f8);
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar8);
    puStack_124 = puVar8;
  }
  if (pAStack_f4 == *(ASN1_ITEM **)puStack_120) {
    return pvStack_16c;
  }
  pcStack_11c = ASN1_item_i2d_bio;
  it_00 = pAStack_f4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_160 = PTR___stack_chk_guard_006a9ae8;
  puStack_138 = (uchar *)0x0;
  piStack_134 = *(int **)PTR___stack_chk_guard_006a9ae8;
  pvStack_12c = pvStack_16c;
  pAStack_128 = pAStack_168;
  iVar5 = ASN1_item_i2d(pAVar16,&puStack_138,it_00);
  if (puStack_138 == (uchar *)0x0) {
    puVar15 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    pvVar17 = (void *)0x0;
  }
  else {
    pAStack_168 = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar15 = puStack_138 + (int)pAStack_168;
      iVar6 = (*(code *)PTR_BIO_write_006a6e14)(puStack_164,puVar15,iVar5);
      if (iVar5 == iVar6) break;
      if (iVar6 < 1) {
        pvVar17 = (void *)0x0;
        puVar15 = puStack_138;
        goto LAB_0054cde0;
      }
      pAStack_168 = (ASN1_ITEM *)(&pAStack_168->itype + iVar6);
      iVar5 = iVar5 - iVar6;
    }
    pvVar17 = (void *)0x1;
LAB_0054cde0:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_138);
    pvStack_16c = pvVar17;
  }
  if (piStack_134 == *(int **)puStack_160) {
    return pvVar17;
  }
  pcStack_15c = ASN1_ENUMERATED_set;
  piVar12 = piStack_134;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar8 = PTR___stack_chk_guard_006a9ae8;
  piVar12[1] = 10;
  piStack_174 = *(int **)puVar8;
  if (*piVar12 < 5) {
    if (piVar12[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar14 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(5,"a_enum.c",0x51);
    piVar12[2] = (int)puVar14;
    if (puVar14 != (undefined *)0x0) {
      *puVar14 = 0;
      puVar14[1] = 0;
      puVar14[2] = 0;
      puVar14[3] = 0;
      puVar14[4] = 0;
      goto LAB_0054cf00;
    }
  }
  else {
LAB_0054cf00:
    puVar14 = (undefined *)piVar12[2];
    if (puVar14 != (undefined *)0x0) {
      if ((int)puVar15 < 0) {
        puVar15 = (uchar *)-(int)puVar15;
        piVar12[1] = 0x10a;
LAB_0054cf1c:
        auStack_17e[2] = (char)puVar15;
        if ((int)puVar15 >> 8 == 0) {
          iVar5 = 1;
LAB_0054cff0:
          iVar6 = iVar5 + -1;
          *puVar14 = auStack_17e[iVar5 + 1];
          if (iVar5 != 1) {
            iVar9 = iVar5 + -3;
            *(undefined *)(piVar12[2] + 1) = auStack_17e[iVar5];
            if (iVar9 == -1) goto LAB_0054cf80;
            goto LAB_0054cf58;
          }
        }
        else {
          auStack_17e[3] = (char)((uint)puVar15 >> 8);
          if ((int)puVar15 >> 0x10 == 0) {
            iVar5 = 2;
            goto LAB_0054cff0;
          }
          auStack_17e[4] = (undefined)((uint)puVar15 >> 0x10);
          if ((int)puVar15 >> 0x18 == 0) {
            iVar5 = 3;
            goto LAB_0054cff0;
          }
          auStack_17e[5] = (undefined)((uint)puVar15 >> 0x18);
          *puVar14 = auStack_17e[5];
          iVar6 = 3;
          iVar9 = 1;
          *(undefined *)(piVar12[2] + 1) = auStack_17e[4];
LAB_0054cf58:
          *(undefined *)(piVar12[2] + 2) = auStack_17e[iVar9 + 2];
          if (iVar9 != 0) {
            *(char *)(piVar12[2] + 3) = (char)puVar15;
          }
        }
        iVar5 = iVar6 + 1;
      }
      else {
        iVar5 = 0;
        if (puVar15 != (uchar *)0x0) goto LAB_0054cf1c;
      }
LAB_0054cf80:
      pvVar17 = (void *)0x1;
      *piVar12 = iVar5;
      goto LAB_0054cf88;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x55);
  pvVar17 = (void *)0x0;
LAB_0054cf88:
  if (piStack_174 == *(int **)puVar8) {
    return pvVar17;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piStack_174 != (int *)0x0) {
    if (piStack_174[1] == 0x10a) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (piStack_174[1] != 10) {
        return (void *)0xffffffff;
      }
    }
    iVar5 = *piStack_174;
    if (4 < iVar5) {
      return (void *)0xffffffff;
    }
    pbVar13 = (byte *)piStack_174[2];
    if (pbVar13 != (byte *)0x0) {
      if (iVar5 < 1) {
        pvVar17 = (void *)0x0;
      }
      else {
        pvVar17 = (void *)(uint)*pbVar13;
        if (iVar5 != 1) {
          uVar1 = CONCAT11(*pbVar13,pbVar13[1]);
          pvVar17 = (void *)(uint)uVar1;
          if (iVar5 != 2) {
            uVar2 = CONCAT21(uVar1,pbVar13[2]);
            pvVar17 = (void *)(uint)uVar2;
            if (iVar5 == 4) {
              pvVar17 = (void *)CONCAT31(uVar2,pbVar13[3]);
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

