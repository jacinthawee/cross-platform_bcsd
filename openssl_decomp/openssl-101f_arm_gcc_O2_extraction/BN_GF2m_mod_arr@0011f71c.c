
undefined4 BN_GF2m_mod_arr(BIGNUM *param_1,BIGNUM *param_2,uint *param_3)

{
  int iVar1;
  uint *puVar2;
  BIGNUM *pBVar3;
  uint uVar4;
  int iVar5;
  ulong *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  ulong uVar10;
  ulong *puVar11;
  uint uVar12;
  
  uVar4 = *param_3;
  if (uVar4 == 0) {
    BN_set_word(param_1,0);
    return 1;
  }
  if (param_2 == param_1) {
    puVar11 = param_1->d;
    iVar5 = param_1->top;
  }
  else {
    iVar5 = param_2->top;
    if (param_1->dmax < iVar5) {
      pBVar3 = bn_expand2(param_1,iVar5);
      if (pBVar3 == (BIGNUM *)0x0) {
        return 0;
      }
      iVar5 = param_2->top;
    }
    if (iVar5 < 1) {
      puVar11 = param_1->d;
    }
    else {
      puVar11 = param_1->d;
      iVar8 = 0;
      puVar6 = param_2->d;
      iVar1 = 0;
      do {
        iVar1 = iVar1 + 1;
        *(undefined4 *)((int)puVar11 + iVar8) = *(undefined4 *)((int)puVar6 + iVar8);
        iVar8 = iVar8 + 4;
        iVar5 = param_2->top;
      } while (iVar1 < iVar5);
    }
    param_1->top = iVar5;
    uVar4 = *param_3;
  }
  iVar5 = iVar5 + -1;
  uVar7 = uVar4 & ~((int)uVar4 >> 0x20);
  if ((int)uVar4 < 0) {
    uVar7 = uVar4 + 0x1f;
  }
  iVar1 = (int)uVar7 >> 5;
joined_r0x0011f77c:
  if (iVar1 < iVar5) {
    while (uVar4 = puVar11[iVar5], uVar4 != 0) {
      puVar11[iVar5] = 0;
      puVar2 = param_3 + 1;
      uVar7 = param_3[1];
      while (uVar7 != 0) {
        uVar9 = *param_3 - uVar7;
        uVar12 = uVar9 + 0x1f & (int)uVar9 >> 0x20;
        if (*param_3 < uVar7) {
          uVar12 = uVar9;
        }
        iVar8 = iVar5 - ((int)uVar12 >> 5);
        uVar9 = (int)uVar9 % 0x20;
        puVar11[iVar8] = puVar11[iVar8] ^ uVar4 >> (uVar9 & 0xff);
        if (uVar9 != 0) {
          puVar11[iVar8 + -1] = puVar11[iVar8 + -1] ^ uVar4 << (0x20 - uVar9 & 0xff);
        }
        puVar2 = puVar2 + 1;
        uVar7 = *puVar2;
      }
      iVar8 = iVar5 - iVar1;
      uVar7 = (int)*param_3 % 0x20;
      puVar11[iVar8] = puVar11[iVar8] ^ uVar4 >> (uVar7 & 0xff);
      if (uVar7 == 0) goto joined_r0x0011f77c;
      puVar11[iVar8 + -1] = puVar11[iVar8 + -1] ^ uVar4 << (0x20 - uVar7 & 0xff);
      if (iVar5 <= iVar1) goto LAB_0011f83c;
    }
    iVar5 = iVar5 + -1;
    goto joined_r0x0011f77c;
  }
LAB_0011f83c:
  if (iVar1 == iVar5) {
    uVar4 = puVar11[iVar1];
    uVar10 = (int)*param_3 % 0x20;
    uVar7 = uVar4 >> (uVar10 & 0xff);
    while (uVar7 != 0) {
      if (uVar10 != 0) {
        uVar10 = (uVar4 << (0x20 - uVar10 & 0xff)) >> (0x20 - uVar10 & 0xff);
      }
      puVar11[iVar1] = uVar10;
      *puVar11 = *puVar11 ^ uVar7;
      uVar4 = param_3[1];
      if (uVar4 != 0) {
        puVar2 = param_3 + 1;
        do {
          uVar12 = uVar4 + 0x1f & (int)uVar4 >> 0x20;
          if (((int)uVar4 >> 0x1e & 1U) == 0) {
            uVar12 = uVar4;
          }
          iVar5 = (int)uVar12 >> 5;
          uVar4 = (int)uVar4 % 0x20;
          uVar12 = uVar7 >> (0x20 - uVar4 & 0xff);
          puVar11[iVar5] = puVar11[iVar5] ^ uVar7 << (uVar4 & 0xff);
          if (uVar4 != 0 && uVar12 != 0) {
            puVar11[iVar5 + 1] = uVar12 ^ puVar11[iVar5 + 1];
          }
          puVar2 = puVar2 + 1;
          uVar4 = *puVar2;
        } while (uVar4 != 0);
      }
      uVar4 = puVar11[iVar1];
      uVar10 = (int)*param_3 % 0x20;
      uVar7 = uVar4 >> (uVar10 & 0xff);
    }
  }
  iVar5 = param_1->top;
  if (0 < iVar5) {
    puVar11 = puVar11 + iVar5 + 0x3fffffff;
    do {
      if (*puVar11 != 0) break;
      iVar5 = iVar5 + -1;
      puVar11 = puVar11 + -1;
    } while (iVar5 != 0);
    param_1->top = iVar5;
  }
  return 1;
}

