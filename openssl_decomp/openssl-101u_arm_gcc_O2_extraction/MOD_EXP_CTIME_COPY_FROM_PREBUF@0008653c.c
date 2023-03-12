
undefined4
MOD_EXP_CTIME_COPY_FROM_PREBUF(BIGNUM *param_1,int param_2,uint *param_3,uint param_4,uint param_5)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  BIGNUM *pBVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulong *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  ulong *puVar14;
  uint *local_44;
  ulong *local_40;
  ulong *local_2c;
  
  if ((param_1->dmax < param_2) && (pBVar5 = bn_expand2(param_1,param_2), pBVar5 == (BIGNUM *)0x0))
  {
    return 0;
  }
  uVar3 = 1 << (param_5 & 0xff);
  if ((int)param_5 < 4) {
    if (param_2 < 1) {
LAB_000866b6:
      param_1->top = param_2;
      return 1;
    }
    local_2c = param_1->d;
    puVar10 = local_2c;
    do {
      uVar6 = 0;
      if (0 < (int)uVar3) {
        uVar9 = 0;
        puVar11 = param_3;
        do {
          uVar7 = uVar9 ^ param_4;
          uVar9 = uVar9 + 1;
          uVar6 = uVar6 | *puVar11 & (int)(uVar7 - 1 & ~uVar7) >> 0x1f;
          puVar11 = puVar11 + 1;
        } while (uVar9 != uVar3);
      }
      puVar14 = puVar10 + 1;
      *puVar10 = uVar6;
      param_3 = param_3 + uVar3;
      puVar10 = puVar14;
    } while (puVar14 != local_2c + param_2);
  }
  else {
    uVar6 = (int)param_4 >> (param_5 - 2 & 0xff);
    uVar9 = 1 << (param_5 - 2 & 0xff);
    if (param_2 < 1) goto LAB_000866b6;
    local_2c = param_1->d;
    local_44 = param_3;
    local_40 = local_2c;
    do {
      uVar7 = 0;
      if (0 < (int)uVar9) {
        uVar8 = 0;
        puVar11 = local_44;
        do {
          uVar13 = *puVar11;
          puVar12 = puVar11 + uVar9 * 3;
          puVar1 = puVar11 + uVar9;
          puVar2 = puVar11 + uVar9 * 2;
          puVar11 = puVar11 + 1;
          uVar4 = uVar8 ^ uVar9 - 1 & param_4;
          uVar8 = uVar8 + 1;
          uVar7 = uVar7 | (*puVar1 & (int)((uVar6 ^ 1) - 1 & ~(uVar6 ^ 1)) >> 0x1f |
                           *puVar2 & (int)((uVar6 ^ 2) - 1 & ~(uVar6 ^ 2)) >> 0x1f |
                           uVar13 & (int)(uVar6 - 1 & ~uVar6) >> 0x1f |
                          *puVar12 & (int)((uVar6 ^ 3) - 1 & ~(uVar6 ^ 3)) >> 0x1f) &
                          (int)(uVar4 - 1 & ~uVar4) >> 0x1f;
        } while (uVar8 != uVar9);
      }
      puVar10 = local_40 + 1;
      *local_40 = uVar7;
      local_44 = local_44 + uVar3;
      local_40 = puVar10;
    } while (puVar10 != local_2c + param_2);
  }
  param_1->top = param_2;
  puVar10 = local_2c + param_2 + 0x3fffffff;
  do {
    if (*puVar10 != 0) break;
    param_2 = param_2 + -1;
    puVar10 = puVar10 + -1;
  } while (param_2 != 0);
  param_1->top = param_2;
  return 1;
}

