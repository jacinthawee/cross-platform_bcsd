
int ASN1_i2d_fp(undefined1 *i2d,FILE *out,void *x)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  ASN1_VALUE *pAVar9;
  ASN1_VALUE *pAVar10;
  int iVar11;
  undefined *puVar12;
  uint uVar13;
  ASN1_ITEM *it;
  int *piVar14;
  byte *pbVar15;
  code *pcVar16;
  uchar *puVar17;
  ASN1_VALUE *pAVar18;
  int unaff_s2;
  int unaff_s3;
  char *unaff_s6;
  undefined auStack_136 [10];
  int *piStack_12c;
  int iStack_124;
  ASN1_ITEM *pAStack_120;
  uchar *puStack_11c;
  undefined *puStack_118;
  code *pcStack_114;
  uchar *puStack_f0;
  int *piStack_ec;
  int iStack_e4;
  ASN1_ITEM *pAStack_e0;
  int iStack_dc;
  undefined *puStack_d8;
  code *pcStack_d4;
  uchar *puStack_b0;
  ASN1_ITEM *pAStack_ac;
  ASN1_VALUE *pAStack_a8;
  code *pcStack_a4;
  int iStack_a0;
  undefined *puStack_9c;
  undefined *puStack_98;
  code *pcStack_94;
  int iStack_70;
  ASN1_ITEM *pAStack_6c;
  int iStack_68;
  undefined1 *puStack_64;
  int iStack_60;
  int iStack_5c;
  undefined *puStack_58;
  void *pvStack_54;
  char *pcStack_50;
  code *pcStack_4c;
  int local_28;
  code *local_24;
  
  puStack_58 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(code **)PTR___stack_chk_guard_006a9ae8;
  uVar5 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar6 = (*(code *)PTR_BIO_new_006a6ea4)(uVar5);
  if (iVar6 == 0) {
    iVar11 = 7;
    puStack_9c = (undefined *)0x75;
    iStack_68 = 0;
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x49);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar6,0x6a,0,out);
    iVar7 = (*(code *)i2d)(x,0);
    unaff_s6 = "encrypt";
    unaff_s3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar7,"a_i2d_fp.c",0x5a);
    if (unaff_s3 == 0) {
      iVar11 = 0x41;
      puStack_9c = &DAT_00000074;
      iStack_68 = 0;
      ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    }
    else {
      local_28 = unaff_s3;
      (*(code *)i2d)(x,&local_28);
      i2d = (undefined1 *)0x0;
      while( true ) {
        puStack_9c = i2d + unaff_s3;
        iVar11 = iVar7;
        iVar8 = (*(code *)PTR_BIO_write_006a6e14)(iVar6,puStack_9c,iVar7);
        if (iVar7 == iVar8) break;
        if (iVar8 < 1) {
          iStack_68 = 0;
          goto LAB_0054c974;
        }
        i2d = i2d + iVar8;
        iVar7 = iVar7 - iVar8;
      }
      iStack_68 = 1;
LAB_0054c974:
      (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s3);
    }
    (*(code *)PTR_BIO_free_006a6e70)(iVar6);
    unaff_s2 = iVar6;
  }
  if (local_24 == *(code **)puStack_58) {
    return iStack_68;
  }
  pcStack_4c = ASN1_i2d_bio;
  pcStack_a4 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_98 = PTR___stack_chk_guard_006a9ae8;
  pAStack_6c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_64 = i2d;
  iStack_60 = unaff_s2;
  iStack_5c = unaff_s3;
  pvStack_54 = x;
  pcStack_50 = unaff_s6;
  pAStack_a8 = (ASN1_VALUE *)(*pcStack_a4)(iVar11,0);
  iVar6 = (*(code *)PTR_CRYPTO_malloc_006a7008)(pAStack_a8,"a_i2d_fp.c",0x5a);
  if (iVar6 == 0) {
    pAVar18 = (ASN1_VALUE *)&DAT_00000041;
    pcVar16 = (code *)&DAT_00000074;
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    pAVar9 = (ASN1_VALUE *)0x0;
  }
  else {
    iStack_70 = iVar6;
    (*pcStack_a4)(iVar11,&iStack_70);
    pcStack_a4 = (code *)0x0;
    while( true ) {
      pcVar16 = pcStack_a4 + iVar6;
      pAVar18 = pAStack_a8;
      pAVar9 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(puStack_9c,pcVar16);
      if (pAStack_a8 == pAVar9) break;
      if ((int)pAVar9 < 1) {
        pAVar9 = (ASN1_VALUE *)0x0;
        goto LAB_0054cb14;
      }
      pcStack_a4 = pcStack_a4 + (int)pAVar9;
      pAStack_a8 = pAStack_a8 + -(int)pAVar9;
    }
    pAVar9 = (ASN1_VALUE *)0x1;
LAB_0054cb14:
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar6);
    pAStack_a8 = pAVar9;
    unaff_s2 = iVar6;
  }
  if (pAStack_6c == *(ASN1_ITEM **)puStack_98) {
    return (int)pAVar9;
  }
  pcStack_94 = ASN1_item_i2d_fp;
  pAStack_120 = pAStack_6c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_d8 = PTR___stack_chk_guard_006a9ae8;
  pAStack_ac = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  iStack_a0 = unaff_s2;
  uVar5 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar6 = (*(code *)PTR_BIO_new_006a6ea4)(uVar5);
  if (iVar6 == 0) {
    pAVar18 = (ASN1_VALUE *)&DAT_00000007;
    puStack_11c = (uchar *)0xc1;
    iStack_124 = 0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7b);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar6,0x6a,0,pcVar16);
    puStack_b0 = (uchar *)0x0;
    pAVar9 = (ASN1_VALUE *)ASN1_item_i2d(pAVar18,&puStack_b0,pAStack_120);
    if (puStack_b0 == (uchar *)0x0) {
      pAVar18 = (ASN1_VALUE *)&DAT_00000041;
      puStack_11c = &DAT_000000c0;
      iStack_124 = 0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    }
    else {
      pAStack_120 = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_11c = puStack_b0 + (int)pAStack_120;
        pAVar18 = pAVar9;
        pAVar10 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(iVar6);
        if (pAVar9 == pAVar10) break;
        if ((int)pAVar10 < 1) {
          iStack_124 = 0;
          puStack_11c = puStack_b0;
          goto LAB_0054cc80;
        }
        pAStack_120 = (ASN1_ITEM *)(pAVar10 + (int)&pAStack_120->itype);
        pAVar9 = pAVar9 + -(int)pAVar10;
      }
      iStack_124 = 1;
LAB_0054cc80:
      (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_b0);
    }
    (*(code *)PTR_BIO_free_006a6e70)(iVar6);
    unaff_s2 = iVar6;
  }
  if (pAStack_ac == *(ASN1_ITEM **)puStack_d8) {
    return iStack_124;
  }
  pcStack_d4 = ASN1_item_i2d_bio;
  it = pAStack_ac;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_118 = PTR___stack_chk_guard_006a9ae8;
  puStack_f0 = (uchar *)0x0;
  piStack_ec = *(int **)PTR___stack_chk_guard_006a9ae8;
  iStack_e4 = iStack_124;
  pAStack_e0 = pAStack_120;
  iStack_dc = unaff_s2;
  iVar6 = ASN1_item_i2d(pAVar18,&puStack_f0,it);
  if (puStack_f0 == (uchar *)0x0) {
    puVar17 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    iVar6 = 0;
  }
  else {
    pAStack_120 = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar17 = puStack_f0 + (int)pAStack_120;
      iVar11 = (*(code *)PTR_BIO_write_006a6e14)(puStack_11c,puVar17,iVar6);
      if (iVar6 == iVar11) break;
      if (iVar11 < 1) {
        iVar6 = 0;
        puVar17 = puStack_f0;
        goto LAB_0054cde0;
      }
      pAStack_120 = (ASN1_ITEM *)(&pAStack_120->itype + iVar11);
      iVar6 = iVar6 - iVar11;
    }
    iVar6 = 1;
LAB_0054cde0:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_f0);
    iStack_124 = iVar6;
  }
  if (piStack_ec == *(int **)puStack_118) {
    return iVar6;
  }
  pcStack_114 = ASN1_ENUMERATED_set;
  piVar14 = piStack_ec;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  piVar14[1] = 10;
  piStack_12c = *(int **)puVar4;
  if (*piVar14 < 5) {
    if (piVar14[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar12 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(5,"a_enum.c",0x51);
    piVar14[2] = (int)puVar12;
    if (puVar12 != (undefined *)0x0) {
      *puVar12 = 0;
      puVar12[1] = 0;
      puVar12[2] = 0;
      puVar12[3] = 0;
      puVar12[4] = 0;
      goto LAB_0054cf00;
    }
  }
  else {
LAB_0054cf00:
    puVar12 = (undefined *)piVar14[2];
    if (puVar12 != (undefined *)0x0) {
      if ((int)puVar17 < 0) {
        puVar17 = (uchar *)-(int)puVar17;
        piVar14[1] = 0x10a;
LAB_0054cf1c:
        auStack_136[2] = (char)puVar17;
        if ((int)puVar17 >> 8 == 0) {
          iVar6 = 1;
LAB_0054cff0:
          iVar11 = iVar6 + -1;
          *puVar12 = auStack_136[iVar6 + 1];
          if (iVar6 != 1) {
            iVar7 = iVar6 + -3;
            *(undefined *)(piVar14[2] + 1) = auStack_136[iVar6];
            if (iVar7 == -1) goto LAB_0054cf80;
            goto LAB_0054cf58;
          }
        }
        else {
          auStack_136[3] = (char)((uint)puVar17 >> 8);
          if ((int)puVar17 >> 0x10 == 0) {
            iVar6 = 2;
            goto LAB_0054cff0;
          }
          auStack_136[4] = (undefined)((uint)puVar17 >> 0x10);
          if ((int)puVar17 >> 0x18 == 0) {
            iVar6 = 3;
            goto LAB_0054cff0;
          }
          auStack_136[5] = (undefined)((uint)puVar17 >> 0x18);
          *puVar12 = auStack_136[5];
          iVar11 = 3;
          iVar7 = 1;
          *(undefined *)(piVar14[2] + 1) = auStack_136[4];
LAB_0054cf58:
          *(undefined *)(piVar14[2] + 2) = auStack_136[iVar7 + 2];
          if (iVar7 != 0) {
            *(char *)(piVar14[2] + 3) = (char)puVar17;
          }
        }
        iVar6 = iVar11 + 1;
      }
      else {
        iVar6 = 0;
        if (puVar17 != (uchar *)0x0) goto LAB_0054cf1c;
      }
LAB_0054cf80:
      iVar11 = 1;
      *piVar14 = iVar6;
      goto LAB_0054cf88;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x55);
  iVar11 = 0;
LAB_0054cf88:
  if (piStack_12c == *(int **)puVar4) {
    return iVar11;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piStack_12c != (int *)0x0) {
    if (piStack_12c[1] == 0x10a) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (piStack_12c[1] != 10) {
        return -1;
      }
    }
    iVar6 = *piStack_12c;
    if (4 < iVar6) {
      return -1;
    }
    pbVar15 = (byte *)piStack_12c[2];
    if (pbVar15 != (byte *)0x0) {
      if (iVar6 < 1) {
        uVar13 = 0;
      }
      else {
        uVar13 = (uint)*pbVar15;
        if (iVar6 != 1) {
          uVar1 = CONCAT11(*pbVar15,pbVar15[1]);
          uVar13 = (uint)uVar1;
          if (iVar6 != 2) {
            uVar2 = CONCAT21(uVar1,pbVar15[2]);
            uVar13 = (uint)uVar2;
            if (iVar6 == 4) {
              uVar13 = CONCAT31(uVar2,pbVar15[3]);
            }
          }
        }
      }
      if (!bVar3) {
        return uVar13;
      }
      return -uVar13;
    }
  }
  return 0;
}

