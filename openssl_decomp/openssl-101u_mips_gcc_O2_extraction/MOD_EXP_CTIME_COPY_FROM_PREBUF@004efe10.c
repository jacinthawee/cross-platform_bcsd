
undefined4
MOD_EXP_CTIME_COPY_FROM_PREBUF(BIGNUM *param_1,int param_2,uint *param_3,uint param_4,uint param_5)

{
  BIGNUM *pBVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulong *puVar9;
  ulong *puVar10;
  ulong *puVar11;
  uint uVar12;
  
  if ((param_1->dmax < param_2) && (pBVar1 = bn_expand2(param_1,param_2), pBVar1 == (BIGNUM *)0x0))
  {
    return 0;
  }
  uVar8 = 1 << (param_5 & 0x1f);
  if ((int)param_5 < 4) {
    if (param_2 < 1) {
LAB_004f00c8:
      param_1->top = param_2;
      return 1;
    }
    puVar9 = param_1->d;
    puVar10 = puVar9;
    do {
      while (uVar6 = 0, (int)uVar8 < 1) {
        puVar11 = puVar10 + 1;
        param_3 = param_3 + uVar8;
        *puVar10 = 0;
        puVar10 = puVar11;
        if (puVar9 + param_2 == puVar11) goto LAB_004efed8;
      }
      uVar4 = 0;
      puVar5 = param_3;
      do {
        uVar3 = uVar4 ^ param_4;
        uVar4 = uVar4 + 1;
        uVar6 = uVar6 | (int)(uVar3 - 1 & ~uVar3) >> 0x1f & *puVar5;
        puVar5 = puVar5 + 1;
      } while (uVar8 != uVar4);
      *puVar10 = uVar6;
      puVar10 = puVar10 + 1;
      param_3 = param_3 + uVar8;
    } while (puVar9 + param_2 != puVar10);
  }
  else {
    uVar6 = (int)param_4 >> (param_5 - 2 & 0x1f);
    uVar4 = 1 << (param_5 - 2 & 0x1f);
    if (param_2 < 1) goto LAB_004f00c8;
    puVar9 = param_1->d;
    puVar10 = puVar9;
    while( true ) {
      if ((int)uVar4 < 1) {
        *puVar10 = 0;
      }
      else {
        uVar7 = 0;
        uVar3 = 0;
        puVar5 = param_3;
        do {
          puVar2 = puVar5 + uVar4;
          uVar12 = uVar3 ^ uVar4 - 1 & param_4;
          uVar3 = uVar3 + 1;
          uVar7 = uVar7 | ((int)(~(uVar6 ^ 1) & (uVar6 ^ 1) - 1) >> 0x1f & *puVar2 |
                           (int)(~(uVar6 ^ 2) & (uVar6 ^ 2) - 1) >> 0x1f & puVar2[uVar4] |
                           (int)(~uVar6 & uVar6 - 1) >> 0x1f & *puVar5 |
                          (int)(~(uVar6 ^ 3) & (uVar6 ^ 3) - 1) >> 0x1f & (puVar2 + uVar4)[uVar4]) &
                          (int)(~uVar12 & uVar12 - 1) >> 0x1f;
          puVar5 = puVar5 + 1;
        } while (uVar4 != uVar3);
        *puVar10 = uVar7;
      }
      puVar10 = puVar10 + 1;
      if (puVar10 == puVar9 + param_2) break;
      param_3 = param_3 + uVar8;
    }
  }
LAB_004efed8:
  param_1->top = param_2;
  puVar9 = puVar9 + param_2 + -2;
  do {
    if (puVar9[1] != 0) break;
    param_2 = param_2 + -1;
    puVar9 = puVar9 + -1;
  } while (param_2 != 0);
  param_1->top = param_2;
  return 1;
}

