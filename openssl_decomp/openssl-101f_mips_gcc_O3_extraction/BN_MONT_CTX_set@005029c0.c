
int BN_MONT_CTX_set(BN_MONT_CTX *mont,BIGNUM *mod,BN_CTX *ctx)

{
  undefined *puVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  BIGNUM *pBVar7;
  ulong *puVar8;
  BIGNUM *n;
  uint uVar9;
  BIGNUM local_48;
  ulong local_34;
  undefined4 local_30;
  BIGNUM *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  n = mod;
  BN_CTX_start(ctx);
  pBVar2 = BN_CTX_get(ctx);
  if (pBVar2 != (BIGNUM *)0x0) {
    n = mod;
    pBVar3 = BN_copy(&mont->N,mod);
    pBVar7 = &mont->RR;
    if (pBVar3 != (BIGNUM *)0x0) {
      (mont->N).neg = 0;
      BN_init(&local_48);
      local_48.neg = 0;
      local_48.dmax = 2;
      local_48.d = &local_34;
      iVar4 = BN_num_bits(mod);
      iVar5 = iVar4 + 0x1f;
      if (iVar4 + 0x1f < 0) {
        iVar5 = iVar4 + 0x3e;
      }
      mont->ri = (iVar5 >> 5) << 5;
      BN_set_word(pBVar7,0);
      n = (BIGNUM *)&DAT_00000020;
      iVar5 = BN_set_bit(pBVar7,0x20);
      if (iVar5 != 0) {
        local_34 = *mod->d;
        local_30 = 0;
        local_48.top = (int)(local_34 != 0);
        n = pBVar7;
        iVar5 = (*(code *)PTR_BN_mod_inverse_006a9714)(pBVar2,pBVar7,&local_48,ctx);
        if ((iVar5 != 0) && (n = pBVar2, iVar5 = BN_lshift(pBVar2,pBVar2,0x20), iVar5 != 0)) {
          if (pBVar2->top == 0) {
            n = (BIGNUM *)0xffffffff;
            iVar5 = BN_set_word(pBVar2,0xffffffff);
            if (iVar5 == 0) {
              uVar9 = 0;
              goto LAB_00502ae0;
            }
          }
          else {
            n = (BIGNUM *)0x1;
            iVar5 = BN_sub_word(pBVar2,1);
            if (iVar5 == 0) goto LAB_00502adc;
          }
          n = (BIGNUM *)0x0;
          iVar5 = (*(code *)PTR_BN_div_006a967c)(pBVar2,0,pBVar2,&local_48,ctx);
          if (iVar5 != 0) {
            uVar6 = 0;
            if (0 < pBVar2->top) {
              uVar6 = *pBVar2->d;
            }
            mont->n0[0] = uVar6;
            mont->n0[1] = 0;
            BN_set_word(pBVar7,0);
            n = (BIGNUM *)(mont->ri << 1);
            iVar5 = BN_set_bit(pBVar7,(int)n);
            if (iVar5 != 0) {
              iVar5 = (*(code *)PTR_BN_div_006a967c)(0,pBVar7,pBVar7,&mont->N,ctx);
              uVar9 = (uint)(iVar5 != 0);
              n = pBVar7;
              goto LAB_00502ae0;
            }
          }
        }
      }
    }
  }
LAB_00502adc:
  uVar9 = 0;
LAB_00502ae0:
  BN_CTX_end(ctx);
  if (local_2c == *(BIGNUM **)puVar1) {
    return uVar9;
  }
  pBVar2 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (pBVar2 != n) {
    pBVar3 = BN_copy((BIGNUM *)&pBVar2->top,(BIGNUM *)&n->top);
    if ((pBVar3 == (BIGNUM *)0x0) ||
       (pBVar3 = BN_copy((BIGNUM *)&pBVar2[1].top,(BIGNUM *)&n[1].top), pBVar3 == (BIGNUM *)0x0)) {
      pBVar3 = (BIGNUM *)0x0;
    }
    else {
      pBVar7 = BN_copy((BIGNUM *)&pBVar2[2].top,(BIGNUM *)&n[2].top);
      pBVar3 = (BIGNUM *)0x0;
      if (pBVar7 != (BIGNUM *)0x0) {
        puVar8 = n->d;
        pBVar2[3].top = n[3].top;
        pBVar2->d = puVar8;
        pBVar2[3].dmax = n[3].dmax;
        pBVar3 = pBVar2;
      }
    }
    return (int)pBVar3;
  }
  return (int)pBVar2;
}

