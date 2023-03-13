
undefined4 __regparm3 BN_from_montgomery_word(BIGNUM *param_1,BIGNUM *param_2,int param_3)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  uint uVar6;
  ulong *ap;
  ulong *puVar7;
  ulong *puVar8;
  int iVar9;
  BIGNUM *pBVar10;
  int iVar11;
  ulong *puVar12;
  ulong *puVar13;
  uint uVar14;
  ulong *puVar15;
  ulong *puVar16;
  int iVar17;
  
  iVar9 = *(int *)(param_3 + 0x1c);
  if (iVar9 == 0) {
    param_1->top = 0;
    return 1;
  }
  iVar11 = iVar9 * 2;
  if ((iVar11 <= param_2->dmax) || (pBVar10 = bn_expand2(param_2,iVar11), pBVar10 != (BIGNUM *)0x0))
  {
    param_2->neg = param_2->neg ^ *(uint *)(param_3 + 0x24);
    puVar15 = *(ulong **)(param_3 + 0x18);
    iVar17 = param_2->top;
    puVar16 = param_2->d;
    if (iVar17 < iVar11) {
      memset(puVar16 + iVar17,0,(iVar11 - iVar17) * 4);
    }
    param_2->top = iVar11;
    iVar11 = *(int *)(param_3 + 0x40);
    uVar14 = 0;
    if (0 < iVar9) {
      iVar17 = 0;
      do {
        uVar5 = bn_mul_add_words(puVar16,puVar15,iVar9,iVar11 * *puVar16);
        uVar1 = puVar16[iVar9];
        uVar6 = uVar5 + uVar14 + uVar1;
        puVar16[iVar9] = uVar6;
        iVar17 = iVar17 + 1;
        puVar16 = puVar16 + 1;
        uVar14 = (uVar14 | uVar1 != uVar6) & (uint)(uVar6 <= uVar1);
      } while (iVar9 != iVar17);
    }
    if ((iVar9 <= param_1->dmax) || (pBVar10 = bn_expand2(param_1,iVar9), pBVar10 != (BIGNUM *)0x0))
    {
      iVar11 = param_2->neg;
      param_1->top = iVar9;
      param_1->neg = iVar11;
      puVar16 = param_1->d;
      ap = param_2->d + iVar9;
      uVar5 = bn_sub_words(puVar16,ap,puVar15,iVar9);
      iVar11 = 0;
      puVar15 = (ulong *)(uVar14 - uVar5 & ((uint)ap ^ (uint)puVar16) ^ (uint)puVar16);
      if (4 < iVar9) {
        puVar8 = puVar15;
        puVar12 = ap + 1;
        puVar13 = puVar16 + 1;
        do {
          uVar5 = *puVar8;
          uVar2 = puVar8[1];
          uVar3 = puVar8[2];
          puVar12[-1] = 0;
          puVar7 = puVar8 + 4;
          uVar4 = puVar8[3];
          *puVar12 = 0;
          puVar13[-1] = uVar5;
          puVar12[1] = 0;
          *puVar13 = uVar2;
          puVar12[2] = 0;
          puVar13[1] = uVar3;
          puVar13[2] = uVar4;
          puVar8 = puVar7;
          puVar12 = puVar12 + 4;
          puVar13 = puVar13 + 4;
        } while (puVar7 != puVar15 + (iVar9 - 5U & 0xfffffffc) + 4);
        iVar11 = (iVar9 - 5U & 0xfffffffc) + 4;
      }
      puVar8 = puVar15 + iVar11;
      if (iVar11 < iVar9) {
        do {
          *(ulong *)((int)puVar16 + -(int)puVar15 + (int)puVar8) = *puVar8;
          *(undefined4 *)(-(int)puVar15 + (int)ap + (int)puVar8) = 0;
          puVar8 = puVar8 + 1;
        } while (puVar8 != puVar15 + iVar9);
      }
      iVar9 = param_2->top;
      if (0 < iVar9) {
        do {
          if (param_2->d[iVar9 + -1] != 0) break;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        param_2->top = iVar9;
      }
      iVar9 = param_1->top;
      if (iVar9 < 1) {
        return 1;
      }
      do {
        if (param_1->d[iVar9 + -1] != 0) break;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      param_1->top = iVar9;
      return 1;
    }
  }
  return 0;
}

