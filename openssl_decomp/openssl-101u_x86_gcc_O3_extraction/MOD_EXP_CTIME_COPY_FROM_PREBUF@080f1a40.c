
undefined4 __regparm3
MOD_EXP_CTIME_COPY_FROM_PREBUF
          (BIGNUM *param_1_00,int param_2_00,uint *param_3,uint param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  BIGNUM *pBVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint local_54;
  uint *local_34;
  ulong *local_2c;
  int local_28;
  
  if ((param_1_00->dmax < param_2_00) &&
     (pBVar4 = bn_expand2(param_1_00,param_2_00), pBVar4 == (BIGNUM *)0x0)) {
    return 0;
  }
  uVar9 = 1 << ((byte)param_2 & 0x1f);
  local_34 = param_3;
  if (param_2 < 4) {
    if (0 < param_2_00) {
      local_54 = 0;
      local_2c = param_1_00->d;
      do {
        if ((int)uVar9 < 1) {
          uVar7 = 0;
        }
        else {
          uVar7 = 0;
          uVar6 = 0;
          puVar8 = local_34;
          do {
            uVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            uVar1 = param_1 ^ uVar6;
            uVar6 = uVar6 + 1;
            uVar7 = uVar7 | (int)(~uVar1 & uVar1 - 1) >> 0x1f & uVar10;
          } while (uVar9 != uVar6);
        }
        local_34 = local_34 + uVar9;
        local_2c[local_54] = uVar7;
        local_54 = local_54 + 1;
      } while (param_2_00 != local_54);
LAB_080f1af0:
      param_1_00->top = param_2_00;
      do {
        if (local_2c[param_2_00 + -1] != 0) break;
        param_2_00 = param_2_00 + -1;
      } while (param_2_00 != 0);
      param_1_00->top = param_2_00;
      return 1;
    }
  }
  else {
    bVar5 = (byte)param_2 - 2;
    uVar7 = 1 << (bVar5 & 0x1f);
    uVar6 = (int)param_1 >> (bVar5 & 0x1f);
    if (0 < param_2_00) {
      local_28 = 0;
      local_2c = param_1_00->d;
      if ((int)uVar7 < 1) goto LAB_080f1c73;
      do {
        local_54 = 0;
        uVar10 = 0;
        puVar8 = local_34;
        do {
          uVar1 = *puVar8;
          puVar2 = puVar8 + uVar7;
          puVar8 = puVar8 + 1;
          uVar3 = uVar7 - 1 & param_1 ^ uVar10;
          uVar10 = uVar10 + 1;
          local_54 = local_54 |
                     (puVar2[uVar7] & (int)((uVar6 ^ 2) - 1 & ~(uVar6 ^ 2)) >> 0x1f |
                      *puVar2 & (int)((uVar6 ^ 1) - 1 & ~(uVar6 ^ 1)) >> 0x1f |
                      uVar1 & (int)(uVar6 - 1 & ~uVar6) >> 0x1f |
                     (puVar2 + uVar7)[uVar7] & (int)(~(uVar6 ^ 3) & (uVar6 ^ 3) - 1) >> 0x1f) &
                     (int)(uVar3 - 1 & ~uVar3) >> 0x1f;
        } while (uVar7 != uVar10);
        while( true ) {
          local_2c[local_28] = local_54;
          local_28 = local_28 + 1;
          local_34 = local_34 + uVar9;
          if (param_2_00 == local_28) goto LAB_080f1af0;
          if (0 < (int)uVar7) break;
LAB_080f1c73:
          local_54 = 0;
        }
      } while( true );
    }
  }
  param_1_00->top = param_2_00;
  return 1;
}

