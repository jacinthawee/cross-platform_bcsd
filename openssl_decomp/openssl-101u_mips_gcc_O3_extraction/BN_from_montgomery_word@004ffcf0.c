
ulonglong BN_from_montgomery_word(BIGNUM *param_1,BIGNUM *param_2,int param_3)

{
  ulong uVar1;
  ulong *puVar2;
  ulong *puVar3;
  BIGNUM *pBVar4;
  uint in_v1;
  uint extraout_v1;
  uint uVar5;
  int iVar6;
  uint uVar7;
  ulong *puVar8;
  ulong *puVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong *puVar13;
  ulong *rp;
  int iVar14;
  uint uVar15;
  uint *puVar16;
  ulong *puVar17;
  int num;
  
  num = *(int *)(param_3 + 0x1c);
  iVar14 = num * 2;
  if (num == 0) {
    param_1->top = 0;
LAB_004fffc4:
    return CONCAT44(1,in_v1);
  }
  if ((iVar14 <= param_2->dmax) || (pBVar4 = bn_expand2(param_2,iVar14), pBVar4 != (BIGNUM *)0x0)) {
    iVar6 = param_2->top;
    puVar13 = *(ulong **)(param_3 + 0x18);
    puVar17 = param_2->d;
    in_v1 = (uint)(iVar6 < iVar14);
    param_2->neg = param_2->neg ^ *(uint *)(param_3 + 0x24);
    if (in_v1 != 0) {
      (*(code *)PTR_memset_006a99f4)(puVar17 + iVar6,0,(iVar14 - iVar6) * 4);
      in_v1 = extraout_v1;
    }
    iVar6 = *(int *)(param_3 + 0x40);
    param_2->top = iVar14;
    uVar15 = 0;
    if (0 < num) {
      iVar14 = 0;
      uVar15 = 0;
      puVar16 = puVar17 + num;
      do {
        iVar14 = iVar14 + 1;
        uVar1 = bn_mul_add_words(puVar17,puVar13,num,iVar6 * *puVar17);
        uVar5 = *puVar16;
        uVar7 = uVar1 + uVar15 + uVar5;
        *puVar16 = uVar7;
        in_v1 = uVar5 < uVar7 ^ 1;
        uVar15 = in_v1 & (uVar5 != uVar7 | uVar15);
        puVar16 = puVar16 + 1;
        puVar17 = puVar17 + 1;
      } while (num != iVar14);
    }
    if ((num <= param_1->dmax) || (pBVar4 = bn_expand2(param_1,num), pBVar4 != (BIGNUM *)0x0)) {
      iVar14 = param_2->neg;
      rp = param_1->d;
      puVar9 = param_2->d + num;
      param_1->top = num;
      param_1->neg = iVar14;
      uVar1 = bn_sub_words(rp,puVar9,puVar13,num);
      puVar17 = (ulong *)(uVar15 - uVar1 & ((uint)rp ^ (uint)puVar9) ^ (uint)rp);
      iVar14 = 0;
      if (4 < num) {
        puVar13 = puVar17;
        puVar3 = puVar9;
        puVar8 = rp;
        do {
          uVar12 = *puVar13;
          puVar2 = puVar13 + 4;
          uVar11 = puVar13[1];
          uVar10 = puVar13[2];
          *puVar3 = 0;
          uVar1 = puVar13[3];
          puVar3[1] = 0;
          *puVar8 = uVar12;
          puVar3[2] = 0;
          puVar8[1] = uVar11;
          puVar3[3] = 0;
          puVar8[2] = uVar10;
          puVar8[3] = uVar1;
          puVar13 = puVar2;
          puVar3 = puVar3 + 4;
          puVar8 = puVar8 + 4;
        } while (puVar2 != puVar17 + (num - 5U & 0xfffffffc) + 4);
        iVar14 = ((num - 5U >> 2) + 1) * 4;
      }
      if (iVar14 < num) {
        puVar3 = puVar17 + iVar14;
        puVar13 = rp + iVar14;
        puVar9 = puVar9 + iVar14;
        do {
          uVar1 = *puVar3;
          puVar3 = puVar3 + 1;
          *puVar13 = uVar1;
          *puVar9 = 0;
          puVar13 = puVar13 + 1;
          puVar9 = puVar9 + 1;
        } while (puVar17 + num != puVar3);
      }
      iVar14 = param_2->top;
      if (0 < iVar14) {
        puVar17 = param_2->d + iVar14 + -2;
        do {
          if (puVar17[1] != 0) break;
          iVar14 = iVar14 + -1;
          puVar17 = puVar17 + -1;
        } while (iVar14 != 0);
        param_2->top = iVar14;
      }
      iVar14 = param_1->top;
      in_v1 = iVar14 * 4;
      if (0 < iVar14) {
        puVar17 = param_1->d + iVar14 + -2;
        do {
          puVar13 = puVar17;
          if (puVar13[1] != 0) break;
          iVar14 = iVar14 + -1;
          puVar17 = puVar13 + -1;
        } while (iVar14 != 0);
        param_1->top = iVar14;
        return CONCAT44(1,puVar13);
      }
      goto LAB_004fffc4;
    }
  }
  return (ulonglong)in_v1;
}

