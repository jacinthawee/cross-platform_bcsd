
int ASN1_i2d_bio(undefined1 *i2d,BIO *out,uchar *x)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  int iVar4;
  ASN1_VALUE *pAVar5;
  undefined4 uVar6;
  ASN1_VALUE *pAVar7;
  int iVar8;
  undefined *puVar9;
  uint uVar10;
  ASN1_ITEM *it;
  int *piVar11;
  int iVar12;
  byte *pbVar13;
  undefined *puVar14;
  uchar *puVar15;
  ASN1_VALUE *pAVar16;
  int unaff_s2;
  undefined auStack_ee [10];
  int *piStack_e4;
  int iStack_dc;
  ASN1_ITEM *pAStack_d8;
  uchar *puStack_d4;
  undefined *puStack_d0;
  code *pcStack_cc;
  uchar *puStack_a8;
  int *piStack_a4;
  int iStack_9c;
  ASN1_ITEM *pAStack_98;
  int iStack_94;
  undefined *puStack_90;
  code *pcStack_8c;
  uchar *puStack_68;
  ASN1_ITEM *pAStack_64;
  ASN1_VALUE *pAStack_60;
  undefined1 *puStack_5c;
  int iStack_58;
  BIO *pBStack_54;
  undefined *puStack_50;
  code *pcStack_4c;
  int local_28;
  ASN1_ITEM *local_24;
  
  puStack_50 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pAStack_60 = (ASN1_VALUE *)(*(code *)i2d)(x,0);
  iVar4 = (*(code *)PTR_CRYPTO_malloc_006a7008)(pAStack_60,"a_i2d_fp.c",0x5a);
  if (iVar4 == 0) {
    pAVar16 = (ASN1_VALUE *)&DAT_00000041;
    puVar14 = &DAT_00000074;
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    pAVar5 = (ASN1_VALUE *)0x0;
  }
  else {
    local_28 = iVar4;
    (*(code *)i2d)(x,&local_28);
    i2d = (undefined1 *)0x0;
    while( true ) {
      puVar14 = i2d + iVar4;
      pAVar16 = pAStack_60;
      pAVar5 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(out,puVar14);
      if (pAStack_60 == pAVar5) break;
      if ((int)pAVar5 < 1) {
        pAVar5 = (ASN1_VALUE *)0x0;
        goto LAB_0054cb14;
      }
      i2d = i2d + (int)pAVar5;
      pAStack_60 = pAStack_60 + -(int)pAVar5;
    }
    pAVar5 = (ASN1_VALUE *)0x1;
LAB_0054cb14:
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar4);
    pAStack_60 = pAVar5;
    unaff_s2 = iVar4;
  }
  if (local_24 == *(ASN1_ITEM **)puStack_50) {
    return (int)pAVar5;
  }
  pcStack_4c = ASN1_item_i2d_fp;
  pAStack_d8 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_90 = PTR___stack_chk_guard_006a9ae8;
  pAStack_64 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  puStack_5c = i2d;
  iStack_58 = unaff_s2;
  pBStack_54 = out;
  uVar6 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar4 = (*(code *)PTR_BIO_new_006a6ea4)(uVar6);
  if (iVar4 == 0) {
    pAVar16 = (ASN1_VALUE *)&DAT_00000007;
    puStack_d4 = (uchar *)0xc1;
    iStack_dc = 0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7b);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar4,0x6a,0,puVar14);
    puStack_68 = (uchar *)0x0;
    pAVar5 = (ASN1_VALUE *)ASN1_item_i2d(pAVar16,&puStack_68,pAStack_d8);
    if (puStack_68 == (uchar *)0x0) {
      pAVar16 = (ASN1_VALUE *)&DAT_00000041;
      puStack_d4 = &DAT_000000c0;
      iStack_dc = 0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    }
    else {
      pAStack_d8 = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_d4 = puStack_68 + (int)pAStack_d8;
        pAVar16 = pAVar5;
        pAVar7 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(iVar4);
        if (pAVar5 == pAVar7) break;
        if ((int)pAVar7 < 1) {
          iStack_dc = 0;
          puStack_d4 = puStack_68;
          goto LAB_0054cc80;
        }
        pAStack_d8 = (ASN1_ITEM *)(pAVar7 + (int)&pAStack_d8->itype);
        pAVar5 = pAVar5 + -(int)pAVar7;
      }
      iStack_dc = 1;
LAB_0054cc80:
      (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_68);
    }
    (*(code *)PTR_BIO_free_006a6e70)(iVar4);
    unaff_s2 = iVar4;
  }
  if (pAStack_64 == *(ASN1_ITEM **)puStack_90) {
    return iStack_dc;
  }
  pcStack_8c = ASN1_item_i2d_bio;
  it = pAStack_64;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_d0 = PTR___stack_chk_guard_006a9ae8;
  puStack_a8 = (uchar *)0x0;
  piStack_a4 = *(int **)PTR___stack_chk_guard_006a9ae8;
  iStack_9c = iStack_dc;
  pAStack_98 = pAStack_d8;
  iStack_94 = unaff_s2;
  iVar4 = ASN1_item_i2d(pAVar16,&puStack_a8,it);
  if (puStack_a8 == (uchar *)0x0) {
    puVar15 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    iVar4 = 0;
  }
  else {
    pAStack_d8 = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar15 = puStack_a8 + (int)pAStack_d8;
      iVar8 = (*(code *)PTR_BIO_write_006a6e14)(puStack_d4,puVar15,iVar4);
      if (iVar4 == iVar8) break;
      if (iVar8 < 1) {
        iVar4 = 0;
        puVar15 = puStack_a8;
        goto LAB_0054cde0;
      }
      pAStack_d8 = (ASN1_ITEM *)(&pAStack_d8->itype + iVar8);
      iVar4 = iVar4 - iVar8;
    }
    iVar4 = 1;
LAB_0054cde0:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_a8);
    iStack_dc = iVar4;
  }
  if (piStack_a4 == *(int **)puStack_d0) {
    return iVar4;
  }
  pcStack_cc = ASN1_ENUMERATED_set;
  piVar11 = piStack_a4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar14 = PTR___stack_chk_guard_006a9ae8;
  piVar11[1] = 10;
  piStack_e4 = *(int **)puVar14;
  if (*piVar11 < 5) {
    if (piVar11[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar9 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(5,"a_enum.c",0x51);
    piVar11[2] = (int)puVar9;
    if (puVar9 != (undefined *)0x0) {
      *puVar9 = 0;
      puVar9[1] = 0;
      puVar9[2] = 0;
      puVar9[3] = 0;
      puVar9[4] = 0;
      goto LAB_0054cf00;
    }
  }
  else {
LAB_0054cf00:
    puVar9 = (undefined *)piVar11[2];
    if (puVar9 != (undefined *)0x0) {
      if ((int)puVar15 < 0) {
        puVar15 = (uchar *)-(int)puVar15;
        piVar11[1] = 0x10a;
LAB_0054cf1c:
        auStack_ee[2] = (char)puVar15;
        if ((int)puVar15 >> 8 == 0) {
          iVar4 = 1;
LAB_0054cff0:
          iVar8 = iVar4 + -1;
          *puVar9 = auStack_ee[iVar4 + 1];
          if (iVar4 != 1) {
            iVar12 = iVar4 + -3;
            *(undefined *)(piVar11[2] + 1) = auStack_ee[iVar4];
            if (iVar12 == -1) goto LAB_0054cf80;
            goto LAB_0054cf58;
          }
        }
        else {
          auStack_ee[3] = (char)((uint)puVar15 >> 8);
          if ((int)puVar15 >> 0x10 == 0) {
            iVar4 = 2;
            goto LAB_0054cff0;
          }
          auStack_ee[4] = (undefined)((uint)puVar15 >> 0x10);
          if ((int)puVar15 >> 0x18 == 0) {
            iVar4 = 3;
            goto LAB_0054cff0;
          }
          auStack_ee[5] = (undefined)((uint)puVar15 >> 0x18);
          *puVar9 = auStack_ee[5];
          iVar8 = 3;
          iVar12 = 1;
          *(undefined *)(piVar11[2] + 1) = auStack_ee[4];
LAB_0054cf58:
          *(undefined *)(piVar11[2] + 2) = auStack_ee[iVar12 + 2];
          if (iVar12 != 0) {
            *(char *)(piVar11[2] + 3) = (char)puVar15;
          }
        }
        iVar4 = iVar8 + 1;
      }
      else {
        iVar4 = 0;
        if (puVar15 != (uchar *)0x0) goto LAB_0054cf1c;
      }
LAB_0054cf80:
      iVar8 = 1;
      *piVar11 = iVar4;
      goto LAB_0054cf88;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x55);
  iVar8 = 0;
LAB_0054cf88:
  if (piStack_e4 == *(int **)puVar14) {
    return iVar8;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piStack_e4 != (int *)0x0) {
    if (piStack_e4[1] == 0x10a) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (piStack_e4[1] != 10) {
        return -1;
      }
    }
    iVar4 = *piStack_e4;
    if (4 < iVar4) {
      return -1;
    }
    pbVar13 = (byte *)piStack_e4[2];
    if (pbVar13 != (byte *)0x0) {
      if (iVar4 < 1) {
        uVar10 = 0;
      }
      else {
        uVar10 = (uint)*pbVar13;
        if (iVar4 != 1) {
          uVar1 = CONCAT11(*pbVar13,pbVar13[1]);
          uVar10 = (uint)uVar1;
          if (iVar4 != 2) {
            uVar2 = CONCAT21(uVar1,pbVar13[2]);
            uVar10 = (uint)uVar2;
            if (iVar4 == 4) {
              uVar10 = CONCAT31(uVar2,pbVar13[3]);
            }
          }
        }
      }
      if (!bVar3) {
        return uVar10;
      }
      return -uVar10;
    }
  }
  return 0;
}

