
bool RSA_eay_mod_exp(BIGNUM *param_1,BIGNUM *param_2,int param_3,BN_CTX *param_4)

{
  undefined4 *puVar1;
  ulong **ppuVar2;
  BIGNUM *pBVar3;
  BIGNUM *b;
  BIGNUM *r;
  int iVar4;
  BIGNUM *pBVar5;
  BN_MONT_CTX *pBVar6;
  BIGNUM *pBVar7;
  undefined4 *puVar8;
  uint extraout_EDX;
  uint uVar9;
  uint extraout_EDX_00;
  int in_GS_OFFSET;
  bool bVar10;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  uint local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  BIGNUM local_5c;
  BIGNUM local_48;
  BIGNUM local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  BN_CTX_start(param_4);
  pBVar3 = BN_CTX_get(param_4);
  b = BN_CTX_get(param_4);
  r = BN_CTX_get(param_4);
  uVar9 = *(uint *)(param_3 + 0x3c);
  if ((uVar9 & 0x100) == 0) {
    BN_init(&local_48);
    ppuVar2 = *(ulong ***)(param_3 + 0x1c);
    local_48.d = *ppuVar2;
    local_48.top = (int)ppuVar2[1];
    local_48.dmax = (int)ppuVar2[2];
    local_48.neg = (int)ppuVar2[3];
    local_48.flags = (uint)ppuVar2[4] & 0xfffffffe | local_48.flags & 1U | 6;
    pBVar5 = &local_34;
    BN_init(pBVar5);
    ppuVar2 = *(ulong ***)(param_3 + 0x20);
    local_34.d = *ppuVar2;
    local_34.top = (int)ppuVar2[1];
    local_34.dmax = (int)ppuVar2[2];
    local_34.neg = (int)ppuVar2[3];
    local_34.flags = (uint)ppuVar2[4] & 0xfffffffe | local_34.flags & 1U | 6;
    uVar9 = *(uint *)(param_3 + 0x3c);
    pBVar7 = &local_48;
  }
  else {
    pBVar7 = *(BIGNUM **)(param_3 + 0x1c);
    pBVar5 = *(BIGNUM **)(param_3 + 0x20);
  }
  if ((uVar9 & 4) == 0) {
joined_r0x08109395:
    if ((uVar9 & 2) != 0) {
      pBVar6 = BN_MONT_CTX_set_locked
                         ((BN_MONT_CTX **)(param_3 + 0x40),(int)(BN_MONT_CTX **)(param_3 + 0x40),
                          (BIGNUM *)0x9,*(BN_CTX **)(param_3 + 0x10));
      if (pBVar6 == (BN_MONT_CTX *)0x0) goto LAB_08109330;
      uVar9 = *(uint *)(param_3 + 0x3c);
    }
    if ((uVar9 & 0x100) == 0) {
      local_5c.d = param_2->d;
      local_5c.top = param_2->top;
      local_5c.dmax = param_2->dmax;
      local_5c.neg = param_2->neg;
      local_5c.flags = param_2->flags & 0xfffffffeU | local_5c.flags & 1U | 6;
      iVar4 = BN_div((BIGNUM *)0x0,pBVar3,&local_5c,*(BIGNUM **)(param_3 + 0x20),param_4);
    }
    else {
      iVar4 = BN_div((BIGNUM *)0x0,pBVar3,param_2,*(BIGNUM **)(param_3 + 0x20),param_4);
    }
    if (iVar4 != 0) {
      if ((*(byte *)(param_3 + 0x3d) & 1) == 0) {
        puVar1 = *(undefined4 **)(param_3 + 0x28);
        local_70 = *puVar1;
        local_6c = puVar1[1];
        local_68 = puVar1[2];
        local_64 = puVar1[3];
        puVar8 = &local_70;
        local_60 = puVar1[4] & 0xfffffffe | local_60 & 1 | 6;
      }
      else {
        puVar8 = *(undefined4 **)(param_3 + 0x28);
      }
      iVar4 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                        (b,pBVar3,puVar8,*(undefined4 *)(param_3 + 0x20),param_4,
                         *(undefined4 *)(param_3 + 0x48));
      if (iVar4 != 0) {
        if ((*(byte *)(param_3 + 0x3d) & 1) == 0) {
          local_5c.d = param_2->d;
          local_5c.top = param_2->top;
          local_5c.dmax = param_2->dmax;
          local_5c.neg = param_2->neg;
          local_5c.flags = param_2->flags & 0xfffffffeU | local_5c.flags & 1U | 6;
          pBVar7 = *(BIGNUM **)(param_3 + 0x1c);
          pBVar5 = &local_5c;
        }
        else {
          pBVar7 = *(BIGNUM **)(param_3 + 0x1c);
          pBVar5 = param_2;
        }
        iVar4 = BN_div((BIGNUM *)0x0,pBVar3,pBVar5,pBVar7,param_4);
        if (iVar4 != 0) {
          if ((*(byte *)(param_3 + 0x3d) & 1) == 0) {
            puVar1 = *(undefined4 **)(param_3 + 0x24);
            local_84 = *puVar1;
            local_80 = puVar1[1];
            local_7c = puVar1[2];
            local_78 = puVar1[3];
            puVar8 = &local_84;
            local_74 = puVar1[4] & 0xfffffffe | local_74 & 1 | 6;
          }
          else {
            puVar8 = *(undefined4 **)(param_3 + 0x24);
          }
          iVar4 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                            (param_1,pBVar3,puVar8,*(undefined4 *)(param_3 + 0x1c),param_4,
                             *(undefined4 *)(param_3 + 0x44));
          if ((((iVar4 != 0) && (iVar4 = BN_sub(param_1,param_1,b), iVar4 != 0)) &&
              ((param_1->neg == 0 ||
               (iVar4 = BN_add(param_1,param_1,*(BIGNUM **)(param_3 + 0x1c)), iVar4 != 0)))) &&
             (iVar4 = BN_mul(pBVar3,param_1,*(BIGNUM **)(param_3 + 0x2c),param_4), iVar4 != 0)) {
            pBVar5 = pBVar3;
            if ((*(byte *)(param_3 + 0x3d) & 1) == 0) {
              local_48.d = pBVar3->d;
              local_48.top = pBVar3->top;
              local_48.dmax = pBVar3->dmax;
              local_48.neg = pBVar3->neg;
              local_48.flags = pBVar3->flags & 0xfffffffeU | local_48.flags & 1U | 6;
              pBVar5 = &local_48;
            }
            iVar4 = BN_div((BIGNUM *)0x0,param_1,pBVar5,*(BIGNUM **)(param_3 + 0x1c),param_4);
            if ((iVar4 != 0) &&
               ((((param_1->neg == 0 ||
                  (iVar4 = BN_add(param_1,param_1,*(BIGNUM **)(param_3 + 0x1c)), iVar4 != 0)) &&
                 (iVar4 = BN_mul(pBVar3,param_1,*(BIGNUM **)(param_3 + 0x20),param_4), iVar4 != 0))
                && (iVar4 = BN_add(param_1,pBVar3,b), iVar4 != 0)))) {
              if ((*(int *)(param_3 + 0x14) != 0) && (*(int *)(param_3 + 0x10) != 0)) {
                iVar4 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                                  (r,param_1,*(int *)(param_3 + 0x14),*(int *)(param_3 + 0x10),
                                   param_4,*(undefined4 *)(param_3 + 0x40));
                if ((iVar4 == 0) ||
                   (((iVar4 = BN_sub(r,r,param_2), iVar4 == 0 ||
                     (iVar4 = BN_div((BIGNUM *)0x0,r,r,*(BIGNUM **)(param_3 + 0x10),param_4),
                     iVar4 == 0)) ||
                    ((uVar9 = extraout_EDX, r->neg != 0 &&
                     (iVar4 = BN_add(r,r,*(BIGNUM **)(param_3 + 0x10)), uVar9 = extraout_EDX_00,
                     iVar4 == 0)))))) goto LAB_08109330;
                if (r->top != 0) {
                  pBVar3 = *(BIGNUM **)(param_3 + 0x18);
                  if ((*(byte *)(param_3 + 0x3d) & 1) == 0) {
                    local_34.d = pBVar3->d;
                    local_34.top = pBVar3->top;
                    local_34.dmax = pBVar3->dmax;
                    local_34.neg = pBVar3->neg;
                    uVar9 = local_34.flags & 1;
                    local_34.flags = pBVar3->flags & 0xfffffffeU | uVar9 | 6;
                    pBVar3 = &local_34;
                  }
                  iVar4 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                                    (param_1,param_2,pBVar3,*(undefined4 *)(param_3 + 0x10),param_4,
                                     *(undefined4 *)(param_3 + 0x40),uVar9,uVar9);
                  bVar10 = iVar4 != 0;
                  goto LAB_08109332;
                }
              }
              bVar10 = true;
              goto LAB_08109332;
            }
          }
        }
      }
    }
  }
  else {
    pBVar6 = BN_MONT_CTX_set_locked
                       ((BN_MONT_CTX **)(param_3 + 0x44),(int)(BN_MONT_CTX **)(param_3 + 0x44),
                        (BIGNUM *)0x9,(BN_CTX *)pBVar7);
    if ((pBVar6 != (BN_MONT_CTX *)0x0) &&
       (pBVar6 = BN_MONT_CTX_set_locked
                           ((BN_MONT_CTX **)(param_3 + 0x48),(int)(BN_MONT_CTX **)(param_3 + 0x48),
                            (BIGNUM *)0x9,(BN_CTX *)pBVar5), pBVar6 != (BN_MONT_CTX *)0x0)) {
      uVar9 = *(uint *)(param_3 + 0x3c);
      goto joined_r0x08109395;
    }
  }
LAB_08109330:
  bVar10 = false;
LAB_08109332:
  BN_CTX_end(param_4);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar10;
}

