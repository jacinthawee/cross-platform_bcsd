
int BN_MONT_CTX_set(BN_MONT_CTX *mont,BIGNUM *mod,BN_CTX *ctx)

{
  undefined *puVar1;
  uint uVar2;
  BIGNUM *pBVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  BIGNUM *pBVar7;
  BIGNUM *pBVar8;
  ulong *puVar9;
  BIGNUM *pBVar10;
  BIGNUM local_48;
  ulong local_34;
  undefined4 local_30;
  BIGNUM *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  uVar2 = mod->top;
  local_2c = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  pBVar3 = mod;
  if (uVar2 == 0) goto LAB_005003ec;
  pBVar10 = mod;
  BN_CTX_start(ctx);
  pBVar7 = BN_CTX_get(ctx);
  if (pBVar7 == (BIGNUM *)0x0) {
LAB_0050061c:
    pBVar3 = pBVar10;
    uVar2 = 0;
  }
  else {
    pBVar10 = mod;
    pBVar3 = BN_copy(&mont->N,mod);
    if (pBVar3 == (BIGNUM *)0x0) goto LAB_0050061c;
    (mont->N).neg = 0;
    pBVar3 = &mont->RR;
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
    BN_set_word(pBVar3,0);
    pBVar10 = (BIGNUM *)&DAT_00000020;
    iVar5 = BN_set_bit(pBVar3,0x20);
    if (iVar5 == 0) goto LAB_0050061c;
    local_34 = *mod->d;
    local_30 = 0;
    local_48.top = (int)(local_34 != 0);
    pBVar10 = pBVar3;
    iVar5 = (*(code *)PTR_BN_mod_inverse_006a85f0)(pBVar7,pBVar3,&local_48,ctx);
    if ((iVar5 == 0) || (pBVar10 = pBVar7, iVar5 = BN_lshift(pBVar7,pBVar7,0x20), iVar5 == 0))
    goto LAB_0050061c;
    if (pBVar7->top == 0) {
      pBVar10 = (BIGNUM *)0xffffffff;
      iVar5 = BN_set_word(pBVar7,0xffffffff);
      if (iVar5 != 0) goto LAB_00500570;
      goto LAB_0050061c;
    }
    pBVar10 = (BIGNUM *)0x1;
    iVar5 = BN_sub_word(pBVar7,1);
    if (iVar5 == 0) goto LAB_0050061c;
LAB_00500570:
    pBVar10 = (BIGNUM *)0x0;
    iVar5 = (*(code *)PTR_BN_div_006a855c)(pBVar7,0,pBVar7,&local_48,ctx);
    if (iVar5 == 0) goto LAB_0050061c;
    uVar6 = 0;
    if (0 < pBVar7->top) {
      uVar6 = *pBVar7->d;
    }
    mont->n0[0] = uVar6;
    mont->n0[1] = 0;
    BN_set_word(pBVar3,0);
    pBVar10 = (BIGNUM *)(mont->ri << 1);
    iVar5 = BN_set_bit(pBVar3,(int)pBVar10);
    if (iVar5 == 0) goto LAB_0050061c;
    iVar5 = (*(code *)PTR_BN_div_006a855c)(0,pBVar3,pBVar3,&mont->N,ctx);
    uVar2 = (uint)(iVar5 != 0);
  }
  BN_CTX_end(ctx);
LAB_005003ec:
  if (local_2c == *(BIGNUM **)puVar1) {
    return uVar2;
  }
  pBVar10 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (pBVar10 != pBVar3) {
    pBVar7 = BN_copy((BIGNUM *)&pBVar10->top,(BIGNUM *)&pBVar3->top);
    if ((pBVar7 == (BIGNUM *)0x0) ||
       (pBVar7 = BN_copy((BIGNUM *)&pBVar10[1].top,(BIGNUM *)&pBVar3[1].top),
       pBVar7 == (BIGNUM *)0x0)) {
      pBVar7 = (BIGNUM *)0x0;
    }
    else {
      pBVar8 = BN_copy((BIGNUM *)&pBVar10[2].top,(BIGNUM *)&pBVar3[2].top);
      pBVar7 = (BIGNUM *)0x0;
      if (pBVar8 != (BIGNUM *)0x0) {
        puVar9 = pBVar3->d;
        pBVar10[3].top = pBVar3[3].top;
        pBVar10->d = puVar9;
        pBVar10[3].dmax = pBVar3[3].dmax;
        pBVar7 = pBVar10;
      }
    }
    return (int)pBVar7;
  }
  return (int)pBVar10;
}

