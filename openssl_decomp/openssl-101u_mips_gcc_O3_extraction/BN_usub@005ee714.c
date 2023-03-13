
int BN_usub(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  
  iVar13 = a->top;
  iVar12 = b->top;
  iVar14 = iVar13 - iVar12;
  if (iVar14 < 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x73,100,"bn_add.c",0xb7);
    return 0;
  }
  if ((r->dmax < iVar13) && (iVar10 = (*(code *)PTR_bn_expand2_006a8524)(r,iVar13), iVar10 == 0)) {
    return 0;
  }
  puVar11 = r->d;
  puVar7 = a->d;
  puVar5 = puVar11;
  if (iVar12 != 0) {
    bVar1 = false;
    puVar5 = b->d;
    puVar4 = puVar7;
    puVar9 = puVar11;
    iVar10 = iVar12;
    do {
      uVar3 = *puVar4;
      uVar8 = *puVar5;
      uVar6 = (uVar3 - 1) - uVar8;
      if (!bVar1) {
        uVar6 = uVar3 - uVar8;
      }
      bVar2 = uVar3 < uVar8;
      if (bVar1) {
        bVar2 = uVar3 <= uVar8;
      }
      bVar1 = bVar2;
      iVar10 = iVar10 + -1;
      *puVar9 = uVar6;
      puVar5 = puVar5 + 1;
      puVar4 = puVar4 + 1;
      puVar9 = puVar9 + 1;
    } while (iVar10 != 0);
    puVar7 = puVar7 + iVar12;
    puVar5 = puVar11 + iVar12;
    if (bVar1) {
      puVar4 = puVar5;
      puVar5 = puVar7;
      if (iVar14 == 0) {
        return 0;
      }
      do {
        puVar7 = puVar5 + 1;
        uVar6 = *puVar5;
        puVar5 = puVar4 + 1;
        iVar14 = iVar14 + -1;
        *puVar4 = uVar6 - 1;
        if (uVar6 != 0) goto LAB_005ee860;
        puVar4 = puVar5;
        puVar5 = puVar7;
      } while (iVar14 != 0);
      goto LAB_005ee804;
    }
  }
LAB_005ee860:
  if ((((puVar7 != puVar5) && (iVar14 != 0)) && (*puVar5 = *puVar7, iVar14 != 1)) &&
     (puVar5[1] = puVar7[1], iVar14 != 2)) {
    iVar12 = iVar14 + -4;
    puVar5[2] = puVar7[2];
    if (iVar14 != 3) {
      do {
        puVar5[3] = puVar7[3];
        if (iVar12 == 0) {
          r->top = iVar13;
          goto LAB_005ee808;
        }
        puVar5[4] = puVar7[4];
        if ((iVar12 == 1) || (puVar5[5] = puVar7[5], iVar12 == 2)) break;
        iVar12 = iVar12 + -4;
        puVar5[6] = puVar7[6];
        puVar5 = puVar5 + 4;
        puVar7 = puVar7 + 4;
      } while (iVar12 != -1);
    }
  }
LAB_005ee804:
  r->top = iVar13;
LAB_005ee808:
  r->neg = 0;
  if (iVar13 < 1) {
    return 1;
  }
  puVar11 = puVar11 + iVar13 + -2;
  do {
    if (puVar11[1] != 0) break;
    iVar13 = iVar13 + -1;
    puVar11 = puVar11 + -1;
  } while (iVar13 != 0);
  r->top = iVar13;
  return 1;
}

