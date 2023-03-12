
BIGNUM * generate_key(int param_1)

{
  bool bVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BN_CTX *ctx;
  BIGNUM *pBVar4;
  int iVar5;
  BIGNUM *rnd;
  BIGNUM *pBVar6;
  BN_MONT_CTX *pBVar7;
  BIGNUM local_34;
  
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
LAB_0009a6c4:
    rnd = (BIGNUM *)0x0;
    pBVar6 = (BIGNUM *)0x0;
LAB_0009a5d6:
    ERR_put_error(5,0x67,3,"dh_key.c",0xc3);
    if (pBVar6 == (BIGNUM *)0x0) goto LAB_0009a5fc;
    pBVar3 = (BIGNUM *)0x0;
    pBVar4 = pBVar6;
    pBVar2 = *(BIGNUM **)(param_1 + 0x14);
  }
  else {
    rnd = *(BIGNUM **)(param_1 + 0x18);
    bVar1 = false;
    if (rnd == (BIGNUM *)0x0) {
      rnd = BN_new();
      bVar1 = true;
      if (rnd == (BIGNUM *)0x0) goto LAB_0009a6c4;
    }
    pBVar6 = *(BIGNUM **)(param_1 + 0x14);
    if (((pBVar6 == (BIGNUM *)0x0) && (pBVar6 = BN_new(), pBVar6 == (BIGNUM *)0x0)) ||
       ((pBVar7 = (BN_MONT_CTX *)(*(uint *)(param_1 + 0x1c) & 1), pBVar7 != (BN_MONT_CTX *)0x0 &&
        (pBVar7 = BN_MONT_CTX_set_locked
                            ((BN_MONT_CTX **)(param_1 + 0x20),0x1a,*(BIGNUM **)(param_1 + 8),ctx),
        pBVar7 == (BN_MONT_CTX *)0x0)))) goto LAB_0009a5d6;
    if (bVar1) {
      pBVar4 = *(BIGNUM **)(param_1 + 0x24);
      if (pBVar4 == (BIGNUM *)0x0) {
        iVar5 = *(int *)(param_1 + 0x10);
        if (iVar5 == 0) {
          iVar5 = BN_num_bits(*(BIGNUM **)(param_1 + 8));
          iVar5 = iVar5 + -1;
        }
        iVar5 = BN_rand(rnd,iVar5,0,0);
        if (iVar5 != 0) goto LAB_0009a62c;
      }
      else {
        while (iVar5 = BN_rand_range(rnd,pBVar4), iVar5 != 0) {
          if ((rnd->top != 0) && (((rnd->top != 1 || (*rnd->d != 1)) || (rnd->neg != 0))))
          goto LAB_0009a62c;
          pBVar4 = *(BIGNUM **)(param_1 + 0x24);
        }
      }
      goto LAB_0009a5d6;
    }
LAB_0009a62c:
    pBVar4 = rnd;
    if (-1 < *(int *)(param_1 + 0x1c) << 0x1e) {
      BN_init(&local_34);
      local_34.d = rnd->d;
      local_34.top = rnd->top;
      local_34.dmax = rnd->dmax;
      local_34.neg = rnd->neg;
      local_34.flags = local_34.flags & 1U | rnd->flags & 0xfffffffeU | 6;
      pBVar4 = &local_34;
    }
    iVar5 = (**(code **)(*(int *)(param_1 + 0x44) + 0xc))
                      (param_1,pBVar6,*(undefined4 *)(param_1 + 0xc),pBVar4,
                       *(undefined4 *)(param_1 + 8),ctx,pBVar7);
    if (iVar5 == 0) goto LAB_0009a5d6;
    *(BIGNUM **)(param_1 + 0x14) = pBVar6;
    *(BIGNUM **)(param_1 + 0x18) = rnd;
    pBVar3 = (BIGNUM *)0x1;
    pBVar4 = pBVar6;
    pBVar2 = pBVar6;
  }
  pBVar6 = pBVar3;
  if (pBVar2 == (BIGNUM *)0x0) {
    BN_free(pBVar4);
  }
LAB_0009a5fc:
  if ((rnd != (BIGNUM *)0x0) && (*(int *)(param_1 + 0x18) == 0)) {
    BN_free(rnd);
  }
  BN_CTX_free(ctx);
  return pBVar6;
}

