
int BN_MONT_CTX_set(BN_MONT_CTX *mont,BIGNUM *mod,BN_CTX *ctx)

{
  BIGNUM *ret;
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *pBVar3;
  ulong uVar4;
  uint uVar5;
  int in_GS_OFFSET;
  BIGNUM local_3c;
  ulong local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar5 = mod->top;
  if (uVar5 == 0) goto LAB_080fe4e6;
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  if (ret == (BIGNUM *)0x0) {
LAB_080fe6a8:
    uVar5 = 0;
  }
  else {
    pBVar1 = BN_copy(&mont->N,mod);
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_080fe6a8;
    pBVar1 = &mont->RR;
    (mont->N).neg = 0;
    BN_init(&local_3c);
    local_3c.d = &local_28;
    local_3c.dmax = 2;
    local_3c.neg = 0;
    iVar2 = BN_num_bits(mod);
    uVar5 = iVar2 + 0x1fU;
    if ((int)(iVar2 + 0x1fU) < 0) {
      uVar5 = iVar2 + 0x3e;
    }
    mont->ri = uVar5 & 0xffffffe0;
    BN_set_word(pBVar1,0);
    iVar2 = BN_set_bit(pBVar1,0x20);
    if (iVar2 == 0) goto LAB_080fe6a8;
    local_28 = *mod->d;
    local_24 = 0;
    local_3c.top = (int)(local_28 != 0);
    pBVar3 = BN_mod_inverse(ret,pBVar1,&local_3c,ctx);
    if ((pBVar3 == (BIGNUM *)0x0) || (iVar2 = BN_lshift(ret,ret,0x20), iVar2 == 0))
    goto LAB_080fe6a8;
    if (ret->top == 0) {
      iVar2 = BN_set_word(ret,0xffffffff);
      if (iVar2 != 0) goto LAB_080fe619;
      goto LAB_080fe6a8;
    }
    iVar2 = BN_sub_word(ret,1);
    if (iVar2 == 0) goto LAB_080fe6a8;
LAB_080fe619:
    iVar2 = BN_div(ret,(BIGNUM *)0x0,ret,&local_3c,ctx);
    if (iVar2 == 0) goto LAB_080fe6a8;
    uVar4 = 0;
    if (0 < ret->top) {
      uVar4 = *ret->d;
    }
    mont->n0[0] = uVar4;
    mont->n0[1] = 0;
    BN_set_word(&mont->RR,0);
    iVar2 = BN_set_bit(&mont->RR,mont->ri * 2);
    if (iVar2 == 0) goto LAB_080fe6a8;
    iVar2 = BN_div((BIGNUM *)0x0,pBVar1,pBVar1,&mont->N,ctx);
    uVar5 = (uint)(iVar2 != 0);
  }
  BN_CTX_end(ctx);
LAB_080fe4e6:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}

