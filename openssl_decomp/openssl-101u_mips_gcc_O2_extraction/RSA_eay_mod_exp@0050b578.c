
uint RSA_eay_mod_exp(BIGNUM *param_1,undefined4 *param_2,uint param_3,BN_CTX *param_4)

{
  undefined *puVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  BN_MONT_CTX *pBVar6;
  uint uVar7;
  ulong **ppuVar8;
  undefined4 *puVar9;
  BIGNUM *pBVar10;
  undefined4 *puVar11;
  BIGNUM *mod;
  code *pcVar12;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_58;
  BIGNUM local_54;
  BIGNUM local_40;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  BN_CTX_start(param_4);
  pBVar2 = BN_CTX_get(param_4);
  pBVar3 = BN_CTX_get(param_4);
  pBVar4 = BN_CTX_get(param_4);
  uVar7 = *(uint *)(param_3 + 0x3c);
  if ((uVar7 & 0x100) == 0) {
    pBVar10 = &local_54;
    BN_init(pBVar10);
    ppuVar8 = *(ulong ***)(param_3 + 0x1c);
    mod = &local_40;
    local_54.d = *ppuVar8;
    local_54.top = (int)ppuVar8[1];
    local_54.dmax = (int)ppuVar8[2];
    local_54.neg = (int)ppuVar8[3];
    local_54.flags = local_54.flags & 1U | (uint)ppuVar8[4] & 0xfffffffe | 6;
    BN_init(mod);
    ppuVar8 = *(ulong ***)(param_3 + 0x20);
    local_40.d = *ppuVar8;
    local_40.top = (int)ppuVar8[1];
    local_40.dmax = (int)ppuVar8[2];
    local_40.neg = (int)ppuVar8[3];
    local_40.flags = local_40.flags & 1U | (uint)ppuVar8[4] & 0xfffffffe | 6;
    uVar7 = *(uint *)(param_3 + 0x3c);
  }
  else {
    pBVar10 = *(BIGNUM **)(param_3 + 0x1c);
    mod = *(BIGNUM **)(param_3 + 0x20);
  }
  if ((uVar7 & 4) != 0) {
    pBVar6 = BN_MONT_CTX_set_locked((BN_MONT_CTX **)(param_3 + 0x44),9,pBVar10,param_4);
    if ((pBVar6 == (BN_MONT_CTX *)0x0) ||
       (pBVar6 = BN_MONT_CTX_set_locked((BN_MONT_CTX **)(param_3 + 0x48),9,mod,param_4),
       pBVar6 == (BN_MONT_CTX *)0x0)) goto LAB_0050ba60;
    uVar7 = *(uint *)(param_3 + 0x3c);
  }
  if ((uVar7 & 2) != 0) {
    pBVar6 = BN_MONT_CTX_set_locked
                       ((BN_MONT_CTX **)(param_3 + 0x40),9,*(BIGNUM **)(param_3 + 0x10),param_4);
    if (pBVar6 == (BN_MONT_CTX *)0x0) goto LAB_0050ba60;
    uVar7 = *(uint *)(param_3 + 0x3c);
  }
  if ((uVar7 & 0x100) == 0) {
    local_68 = *param_2;
    local_64 = param_2[1];
    local_60 = param_2[2];
    local_5c = param_2[3];
    local_58 = local_58 & 1 | param_2[4] & 0xfffffffe | 6;
    iVar5 = (*(code *)PTR_BN_div_006a855c)
                      (0,pBVar2,&local_68,*(undefined4 *)(param_3 + 0x20),param_4);
  }
  else {
    iVar5 = (*(code *)PTR_BN_div_006a855c)(0,pBVar2,param_2,*(undefined4 *)(param_3 + 0x20),param_4)
    ;
  }
  if (iVar5 == 0) goto LAB_0050ba60;
  if ((*(uint *)(param_3 + 0x3c) & 0x100) == 0) {
    puVar9 = *(undefined4 **)(param_3 + 0x28);
    puVar11 = &local_7c;
    local_7c = *puVar9;
    local_78 = puVar9[1];
    local_74 = puVar9[2];
    local_70 = puVar9[3];
    local_6c = local_6c & 1 | puVar9[4] & 0xfffffffe | 6;
  }
  else {
    puVar11 = *(undefined4 **)(param_3 + 0x28);
  }
  iVar5 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                    (pBVar3,pBVar2,puVar11,*(undefined4 *)(param_3 + 0x20),param_4,
                     *(undefined4 *)(param_3 + 0x48));
  if (iVar5 == 0) goto LAB_0050ba60;
  if ((*(uint *)(param_3 + 0x3c) & 0x100) == 0) {
    local_68 = *param_2;
    local_64 = param_2[1];
    local_60 = param_2[2];
    local_5c = param_2[3];
    local_58 = local_58 & 1 | param_2[4] & 0xfffffffe | 6;
    iVar5 = (*(code *)PTR_BN_div_006a855c)
                      (0,pBVar2,&local_68,*(undefined4 *)(param_3 + 0x1c),param_4);
    if (iVar5 == 0) goto LAB_0050ba60;
    if ((*(uint *)(param_3 + 0x3c) & 0x100) != 0) goto LAB_0050bc70;
LAB_0050b738:
    puVar9 = *(undefined4 **)(param_3 + 0x24);
    puVar11 = &local_90;
    local_90 = *puVar9;
    local_8c = puVar9[1];
    local_88 = puVar9[2];
    local_84 = puVar9[3];
    local_80 = local_80 & 1 | puVar9[4] & 0xfffffffe | 6;
  }
  else {
    iVar5 = (*(code *)PTR_BN_div_006a855c)(0,pBVar2,param_2,*(undefined4 *)(param_3 + 0x1c),param_4)
    ;
    if (iVar5 == 0) goto LAB_0050ba60;
    if ((*(uint *)(param_3 + 0x3c) & 0x100) == 0) goto LAB_0050b738;
LAB_0050bc70:
    puVar11 = *(undefined4 **)(param_3 + 0x24);
  }
  iVar5 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                    (param_1,pBVar2,puVar11,*(undefined4 *)(param_3 + 0x1c),param_4,
                     *(undefined4 *)(param_3 + 0x44));
  if ((((iVar5 != 0) && (iVar5 = (*(code *)PTR_BN_sub_006a85a8)(param_1,param_1,pBVar3), iVar5 != 0)
       ) && ((param_1->neg == 0 ||
             (iVar5 = (*(code *)PTR_BN_add_006a85a4)
                                (param_1,param_1,*(undefined4 *)(param_3 + 0x1c)), iVar5 != 0)))) &&
     (iVar5 = BN_mul(pBVar2,param_1,*(BIGNUM **)(param_3 + 0x2c),param_4), iVar5 != 0)) {
    pBVar10 = pBVar2;
    if ((*(uint *)(param_3 + 0x3c) & 0x100) == 0) {
      pBVar10 = &local_54;
      local_54.d = pBVar2->d;
      local_54.top = pBVar2->top;
      local_54.dmax = pBVar2->dmax;
      local_54.neg = pBVar2->neg;
      local_54.flags = local_54.flags & 1U | pBVar2->flags & 0xfffffffeU | 6;
    }
    iVar5 = (*(code *)PTR_BN_div_006a855c)
                      (0,param_1,pBVar10,*(undefined4 *)(param_3 + 0x1c),param_4);
    if (((iVar5 != 0) &&
        (((param_1->neg == 0 ||
          (iVar5 = (*(code *)PTR_BN_add_006a85a4)(param_1,param_1,*(undefined4 *)(param_3 + 0x1c)),
          iVar5 != 0)) &&
         (iVar5 = BN_mul(pBVar2,param_1,*(BIGNUM **)(param_3 + 0x20),param_4), iVar5 != 0)))) &&
       (iVar5 = (*(code *)PTR_BN_add_006a85a4)(param_1,pBVar2,pBVar3), iVar5 != 0)) {
      if (*(int *)(param_3 + 0x14) == 0) goto LAB_0050bc78;
      if (*(int *)(param_3 + 0x10) == 0) goto LAB_0050bc78;
      iVar5 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                        (pBVar4,param_1,*(int *)(param_3 + 0x14),*(int *)(param_3 + 0x10),param_4,
                         *(undefined4 *)(param_3 + 0x40));
      if (((iVar5 != 0) &&
          (iVar5 = (*(code *)PTR_BN_sub_006a85a8)(pBVar4,pBVar4,param_2), iVar5 != 0)) &&
         (iVar5 = (*(code *)PTR_BN_div_006a855c)
                            (0,pBVar4,pBVar4,*(undefined4 *)(param_3 + 0x10),param_4), iVar5 != 0))
      {
        pcVar12 = (code *)PTR_BN_add_006a85a4;
        if (pBVar4->neg != 0) goto LAB_0050bc8c;
        goto LAB_0050b970;
      }
    }
  }
LAB_0050ba60:
  param_3 = 0;
  while( true ) {
    BN_CTX_end(param_4);
    if (local_2c == *(int *)puVar1) break;
    pcVar12 = (code *)PTR___stack_chk_fail_006a9ab0;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0050bc8c:
    iVar5 = (*pcVar12)(pBVar4,pBVar4,*(undefined4 *)(param_3 + 0x10));
    if (iVar5 == 0) {
      param_3 = 0;
    }
    else {
LAB_0050b970:
      if (pBVar4->top == 0) {
LAB_0050bc78:
        param_3 = 1;
      }
      else {
        if ((*(uint *)(param_3 + 0x3c) & 0x100) == 0) {
          ppuVar8 = *(ulong ***)(param_3 + 0x18);
          pBVar2 = &local_40;
          local_40.d = *ppuVar8;
          local_40.top = (int)ppuVar8[1];
          local_40.dmax = (int)ppuVar8[2];
          local_40.neg = (int)ppuVar8[3];
          local_40.flags = local_40.flags & 1U | (uint)ppuVar8[4] & 0xfffffffe | 6;
        }
        else {
          pBVar2 = *(BIGNUM **)(param_3 + 0x18);
        }
        iVar5 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                          (param_1,param_2,pBVar2,*(undefined4 *)(param_3 + 0x10),param_4,
                           *(undefined4 *)(param_3 + 0x40));
        param_3 = (uint)(iVar5 != 0);
      }
    }
  }
  return param_3;
}

