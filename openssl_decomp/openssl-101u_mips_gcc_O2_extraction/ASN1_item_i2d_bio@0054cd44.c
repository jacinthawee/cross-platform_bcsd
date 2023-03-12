
int ASN1_item_i2d_bio(ASN1_ITEM *it,BIO *out,void *x)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  byte *pbVar11;
  uchar *puVar12;
  int unaff_s0;
  int unaff_s1;
  undefined auStack_66 [10];
  int *piStack_5c;
  int iStack_54;
  int iStack_50;
  BIO *pBStack_4c;
  undefined *puStack_48;
  code *pcStack_44;
  uchar *local_20;
  int *local_1c;
  
  puStack_48 = PTR___stack_chk_guard_006a9ae8;
  local_20 = (uchar *)0x0;
  local_1c = *(int **)PTR___stack_chk_guard_006a9ae8;
  iVar5 = ASN1_item_i2d((ASN1_VALUE *)x,&local_20,it);
  if (local_20 == (uchar *)0x0) {
    puVar12 = &DAT_000000c0;
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    iVar5 = 0;
  }
  else {
    unaff_s1 = 0;
    while( true ) {
      puVar12 = local_20 + unaff_s1;
      iVar6 = (*(code *)PTR_BIO_write_006a6e14)(out,puVar12,iVar5);
      if (iVar5 == iVar6) break;
      if (iVar6 < 1) {
        iVar5 = 0;
        puVar12 = local_20;
        goto LAB_0054cde0;
      }
      unaff_s1 = unaff_s1 + iVar6;
      iVar5 = iVar5 - iVar6;
    }
    iVar5 = 1;
LAB_0054cde0:
    (*(code *)PTR_CRYPTO_free_006a6e88)(local_20);
    unaff_s0 = iVar5;
  }
  if (local_1c == *(int **)puStack_48) {
    return iVar5;
  }
  pcStack_44 = ASN1_ENUMERATED_set;
  piVar9 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  piVar9[1] = 10;
  piStack_5c = *(int **)puVar4;
  iStack_54 = unaff_s0;
  iStack_50 = unaff_s1;
  pBStack_4c = out;
  if (*piVar9 < 5) {
    if (piVar9[2] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar7 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(5,"a_enum.c",0x51);
    piVar9[2] = (int)puVar7;
    if (puVar7 != (undefined *)0x0) {
      *puVar7 = 0;
      puVar7[1] = 0;
      puVar7[2] = 0;
      puVar7[3] = 0;
      puVar7[4] = 0;
      goto LAB_0054cf00;
    }
  }
  else {
LAB_0054cf00:
    puVar7 = (undefined *)piVar9[2];
    if (puVar7 != (undefined *)0x0) {
      if ((int)puVar12 < 0) {
        puVar12 = (uchar *)-(int)puVar12;
        piVar9[1] = 0x10a;
LAB_0054cf1c:
        auStack_66[2] = (char)puVar12;
        if ((int)puVar12 >> 8 == 0) {
          iVar5 = 1;
LAB_0054cff0:
          iVar6 = iVar5 + -1;
          *puVar7 = auStack_66[iVar5 + 1];
          if (iVar5 != 1) {
            iVar10 = iVar5 + -3;
            *(undefined *)(piVar9[2] + 1) = auStack_66[iVar5];
            if (iVar10 == -1) goto LAB_0054cf80;
            goto LAB_0054cf58;
          }
        }
        else {
          auStack_66[3] = (char)((uint)puVar12 >> 8);
          if ((int)puVar12 >> 0x10 == 0) {
            iVar5 = 2;
            goto LAB_0054cff0;
          }
          auStack_66[4] = (undefined)((uint)puVar12 >> 0x10);
          if ((int)puVar12 >> 0x18 == 0) {
            iVar5 = 3;
            goto LAB_0054cff0;
          }
          auStack_66[5] = (undefined)((uint)puVar12 >> 0x18);
          *puVar7 = auStack_66[5];
          iVar6 = 3;
          iVar10 = 1;
          *(undefined *)(piVar9[2] + 1) = auStack_66[4];
LAB_0054cf58:
          *(undefined *)(piVar9[2] + 2) = auStack_66[iVar10 + 2];
          if (iVar10 != 0) {
            *(char *)(piVar9[2] + 3) = (char)puVar12;
          }
        }
        iVar5 = iVar6 + 1;
      }
      else {
        iVar5 = 0;
        if (puVar12 != (uchar *)0x0) goto LAB_0054cf1c;
      }
LAB_0054cf80:
      iVar6 = 1;
      *piVar9 = iVar5;
      goto LAB_0054cf88;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x55);
  iVar6 = 0;
LAB_0054cf88:
  if (piStack_5c == *(int **)puVar4) {
    return iVar6;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piStack_5c != (int *)0x0) {
    if (piStack_5c[1] == 0x10a) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (piStack_5c[1] != 10) {
        return -1;
      }
    }
    iVar5 = *piStack_5c;
    if (4 < iVar5) {
      return -1;
    }
    pbVar11 = (byte *)piStack_5c[2];
    if (pbVar11 != (byte *)0x0) {
      if (iVar5 < 1) {
        uVar8 = 0;
      }
      else {
        uVar8 = (uint)*pbVar11;
        if (iVar5 != 1) {
          uVar1 = CONCAT11(*pbVar11,pbVar11[1]);
          uVar8 = (uint)uVar1;
          if (iVar5 != 2) {
            uVar2 = CONCAT21(uVar1,pbVar11[2]);
            uVar8 = (uint)uVar2;
            if (iVar5 == 4) {
              uVar8 = CONCAT31(uVar2,pbVar11[3]);
            }
          }
        }
      }
      if (!bVar3) {
        return uVar8;
      }
      return -uVar8;
    }
  }
  return 0;
}

