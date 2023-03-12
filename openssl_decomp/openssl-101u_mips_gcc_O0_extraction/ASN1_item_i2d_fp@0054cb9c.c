
int ASN1_item_i2d_fp(ASN1_ITEM *it,FILE *out,void *x)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  ASN1_VALUE *pAVar7;
  ASN1_VALUE *pAVar8;
  int iVar9;
  undefined *puVar10;
  uint uVar11;
  ASN1_ITEM *it_00;
  int *piVar12;
  int iVar13;
  byte *pbVar14;
  uchar *puVar15;
  ASN1_VALUE *val;
  int unaff_s2;
  undefined auStack_a6 [10];
  int *piStack_9c;
  int iStack_94;
  ASN1_ITEM *pAStack_90;
  uchar *puStack_8c;
  undefined *puStack_88;
  code *pcStack_84;
  uchar *puStack_60;
  int *piStack_5c;
  int iStack_54;
  ASN1_ITEM *pAStack_50;
  int iStack_4c;
  undefined *puStack_48;
  code *pcStack_44;
  uchar *local_20;
  ASN1_ITEM *local_1c;
  
  puStack_48 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  uVar5 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar6 = (*(code *)PTR_BIO_new_006a6ea4)(uVar5);
  if (iVar6 == 0) {
    val = (ASN1_VALUE *)&DAT_00000007;
    puStack_8c = (uchar *)0xc1;
    iStack_94 = 0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7b);
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar6,0x6a,0,out);
    local_20 = (uchar *)0x0;
    pAVar7 = (ASN1_VALUE *)ASN1_item_i2d((ASN1_VALUE *)x,&local_20,it);
    if (local_20 == (uchar *)0x0) {
      val = (ASN1_VALUE *)&DAT_00000041;
      puStack_8c = &DAT_000000c0;
      iStack_94 = 0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    }
    else {
      it = (ASN1_ITEM *)0x0;
      while( true ) {
        puStack_8c = local_20 + (int)it;
        val = pAVar7;
        pAVar8 = (ASN1_VALUE *)(*(code *)PTR_BIO_write_006a6e14)(iVar6);
        if (pAVar7 == pAVar8) break;
        if ((int)pAVar8 < 1) {
          iStack_94 = 0;
          puStack_8c = local_20;
          goto LAB_0054cc80;
        }
        it = (ASN1_ITEM *)(pAVar8 + (int)&it->itype);
        pAVar7 = pAVar7 + -(int)pAVar8;
      }
      iStack_94 = 1;
LAB_0054cc80:
      (*(code *)PTR_CRYPTO_free_006a6e88)(local_20);
    }
    (*(code *)PTR_BIO_free_006a6e70)(iVar6);
    unaff_s2 = iVar6;
  }
  if (local_1c == *(ASN1_ITEM **)puStack_48) {
    return iStack_94;
  }
  pcStack_44 = ASN1_item_i2d_bio;
  it_00 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_88 = PTR___stack_chk_guard_006a9ae8;
  puStack_60 = (uchar *)0x0;
  piStack_5c = *(int **)PTR___stack_chk_guard_006a9ae8;
  iStack_54 = iStack_94;
  pAStack_50 = it;
  iStack_4c = unaff_s2;
  iVar6 = ASN1_item_i2d(val,&puStack_60,it_00);
  if (puStack_60 == (uchar *)0x0) {
    puVar15 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    iVar6 = 0;
  }
  else {
    it = (ASN1_ITEM *)0x0;
    while( true ) {
      puVar15 = puStack_60 + (int)it;
      iVar9 = (*(code *)PTR_BIO_write_006a6e14)(puStack_8c,puVar15,iVar6);
      if (iVar6 == iVar9) break;
      if (iVar9 < 1) {
        iVar6 = 0;
        puVar15 = puStack_60;
        goto LAB_0054cde0;
      }
      it = (ASN1_ITEM *)(&it->itype + iVar9);
      iVar6 = iVar6 - iVar9;
    }
    iVar6 = 1;
LAB_0054cde0:
    (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_60);
    iStack_94 = iVar6;
  }
  if (piStack_5c == *(int **)puStack_88) {
    return iVar6;
  }
  pcStack_84 = ASN1_ENUMERATED_set;
  piVar12 = piStack_5c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  piVar12[1] = 10;
  piStack_9c = *(int **)puVar4;
  pAStack_90 = it;
  if (*piVar12 < 5) {
    if (piVar12[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar10 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(5,"a_enum.c",0x51);
    piVar12[2] = (int)puVar10;
    if (puVar10 != (undefined *)0x0) {
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = 0;
      puVar10[4] = 0;
      goto LAB_0054cf00;
    }
  }
  else {
LAB_0054cf00:
    puVar10 = (undefined *)piVar12[2];
    if (puVar10 != (undefined *)0x0) {
      if ((int)puVar15 < 0) {
        puVar15 = (uchar *)-(int)puVar15;
        piVar12[1] = 0x10a;
LAB_0054cf1c:
        auStack_a6[2] = (char)puVar15;
        if ((int)puVar15 >> 8 == 0) {
          iVar6 = 1;
LAB_0054cff0:
          iVar9 = iVar6 + -1;
          *puVar10 = auStack_a6[iVar6 + 1];
          if (iVar6 != 1) {
            iVar13 = iVar6 + -3;
            *(undefined *)(piVar12[2] + 1) = auStack_a6[iVar6];
            if (iVar13 == -1) goto LAB_0054cf80;
            goto LAB_0054cf58;
          }
        }
        else {
          auStack_a6[3] = (char)((uint)puVar15 >> 8);
          if ((int)puVar15 >> 0x10 == 0) {
            iVar6 = 2;
            goto LAB_0054cff0;
          }
          auStack_a6[4] = (undefined)((uint)puVar15 >> 0x10);
          if ((int)puVar15 >> 0x18 == 0) {
            iVar6 = 3;
            goto LAB_0054cff0;
          }
          auStack_a6[5] = (undefined)((uint)puVar15 >> 0x18);
          *puVar10 = auStack_a6[5];
          iVar9 = 3;
          iVar13 = 1;
          *(undefined *)(piVar12[2] + 1) = auStack_a6[4];
LAB_0054cf58:
          *(undefined *)(piVar12[2] + 2) = auStack_a6[iVar13 + 2];
          if (iVar13 != 0) {
            *(char *)(piVar12[2] + 3) = (char)puVar15;
          }
        }
        iVar6 = iVar9 + 1;
      }
      else {
        iVar6 = 0;
        if (puVar15 != (uchar *)0x0) goto LAB_0054cf1c;
      }
LAB_0054cf80:
      iVar9 = 1;
      *piVar12 = iVar6;
      goto LAB_0054cf88;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x55);
  iVar9 = 0;
LAB_0054cf88:
  if (piStack_9c == *(int **)puVar4) {
    return iVar9;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piStack_9c != (int *)0x0) {
    if (piStack_9c[1] == 0x10a) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (piStack_9c[1] != 10) {
        return -1;
      }
    }
    iVar6 = *piStack_9c;
    if (4 < iVar6) {
      return -1;
    }
    pbVar14 = (byte *)piStack_9c[2];
    if (pbVar14 != (byte *)0x0) {
      if (iVar6 < 1) {
        uVar11 = 0;
      }
      else {
        uVar11 = (uint)*pbVar14;
        if (iVar6 != 1) {
          uVar1 = CONCAT11(*pbVar14,pbVar14[1]);
          uVar11 = (uint)uVar1;
          if (iVar6 != 2) {
            uVar2 = CONCAT21(uVar1,pbVar14[2]);
            uVar11 = (uint)uVar2;
            if (iVar6 == 4) {
              uVar11 = CONCAT31(uVar2,pbVar14[3]);
            }
          }
        }
      }
      if (!bVar3) {
        return uVar11;
      }
      return -uVar11;
    }
  }
  return 0;
}

