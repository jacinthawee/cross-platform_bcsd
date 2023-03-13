
int BN_sqr(BIGNUM *r,BIGNUM *a,BN_CTX *ctx)

{
  ulong *puVar1;
  int words;
  BIGNUM *a_00;
  BIGNUM *pBVar2;
  int iVar3;
  int in_GS_OFFSET;
  BIGNUM *local_bc;
  ulong local_b4;
  undefined local_a0 [128];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_b4 = a->top;
  if ((int)local_b4 < 1) {
    r->top = 0;
    r->neg = 0;
    iVar3 = 1;
    goto LAB_080fbb33;
  }
  BN_CTX_start(ctx);
  local_bc = r;
  if (a == r) {
    local_bc = BN_CTX_get(ctx);
  }
  a_00 = BN_CTX_get(ctx);
  if (((local_bc == (BIGNUM *)0x0) || (a_00 == (BIGNUM *)0x0)) ||
     ((words = local_b4 * 2, local_bc->dmax < words &&
      (pBVar2 = bn_expand2(local_bc,words), pBVar2 == (BIGNUM *)0x0)))) goto LAB_080fbb23;
  if (local_b4 == 4) {
    bn_sqr_comba4(local_bc->d,a->d);
    local_b4 = 4;
LAB_080fbaba:
    puVar1 = a->d;
    iVar3 = 1;
    local_bc->neg = 0;
    local_bc->top = words - (uint)((puVar1[local_b4 - 1] & 0xffff0000) == 0);
    if (local_bc != r) {
      BN_copy(r,local_bc);
    }
  }
  else {
    if (local_b4 == 8) {
      bn_sqr_comba8(local_bc->d,a->d);
      local_b4 = 8;
      goto LAB_080fbaba;
    }
    if ((int)local_b4 < 0x10) {
      bn_sqr_normal(local_bc->d,a->d,local_b4,local_a0);
      goto LAB_080fbaba;
    }
    iVar3 = BN_num_bits_word(local_b4);
    if (local_b4 == 1 << ((char)iVar3 - 1U & 0x1f)) {
      iVar3 = local_b4 * 4;
      if ((iVar3 - a_00->dmax == 0 || iVar3 < a_00->dmax) ||
         (pBVar2 = bn_expand2(a_00,iVar3), pBVar2 != (BIGNUM *)0x0)) {
        bn_sqr_recursive(local_bc->d,a->d,local_b4,a_00->d);
        goto LAB_080fbaba;
      }
    }
    else if ((words <= a_00->dmax) || (pBVar2 = bn_expand2(a_00,words), pBVar2 != (BIGNUM *)0x0)) {
      bn_sqr_normal(local_bc->d,a->d,local_b4,a_00->d);
      goto LAB_080fbaba;
    }
LAB_080fbb23:
    iVar3 = 0;
  }
  BN_CTX_end(ctx);
LAB_080fbb33:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}

