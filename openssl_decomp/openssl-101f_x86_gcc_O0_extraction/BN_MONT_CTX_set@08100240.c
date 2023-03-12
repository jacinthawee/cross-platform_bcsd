
int BN_MONT_CTX_set(BN_MONT_CTX *mont,BIGNUM *mod,BN_CTX *ctx)

{
  BIGNUM *a;
  BIGNUM *ret;
  BIGNUM *pBVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  int in_GS_OFFSET;
  BIGNUM local_3c;
  ulong local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  if (ret != (BIGNUM *)0x0) {
    a = &mont->RR;
    pBVar1 = BN_copy(&mont->N,mod);
    if (pBVar1 != (BIGNUM *)0x0) {
      (mont->N).neg = 0;
      BN_init(&local_3c);
      local_3c.d = &local_28;
      local_3c.dmax = 2;
      local_3c.neg = 0;
      iVar2 = BN_num_bits(mod);
      uVar4 = iVar2 + 0x1fU;
      if ((int)(iVar2 + 0x1fU) < 0) {
        uVar4 = iVar2 + 0x3e;
      }
      mont->ri = uVar4 & 0xffffffe0;
      BN_set_word(a,0);
      iVar2 = BN_set_bit(a,0x20);
      if (iVar2 != 0) {
        local_28 = *mod->d;
        local_24 = 0;
        local_3c.top = (int)(local_28 != 0);
        pBVar1 = BN_mod_inverse(ret,a,&local_3c,ctx);
        if ((pBVar1 != (BIGNUM *)0x0) && (iVar2 = BN_lshift(ret,ret,0x20), iVar2 != 0)) {
          if (ret->top == 0) {
            iVar2 = BN_set_word(ret,0xffffffff);
          }
          else {
            iVar2 = BN_sub_word(ret,1);
          }
          if ((iVar2 != 0) && (iVar2 = BN_div(ret,(BIGNUM *)0x0,ret,&local_3c,ctx), iVar2 != 0)) {
            uVar3 = 0;
            if (0 < ret->top) {
              uVar3 = *ret->d;
            }
            mont->n0[0] = uVar3;
            mont->n0[1] = 0;
            BN_set_word(&mont->RR,0);
            iVar2 = BN_set_bit(&mont->RR,mont->ri * 2);
            if (iVar2 != 0) {
              iVar2 = BN_div((BIGNUM *)0x0,a,a,&mont->N,ctx);
              uVar4 = (uint)(iVar2 != 0);
              goto LAB_081002ff;
            }
          }
        }
      }
    }
  }
  uVar4 = 0;
LAB_081002ff:
  BN_CTX_end(ctx);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

