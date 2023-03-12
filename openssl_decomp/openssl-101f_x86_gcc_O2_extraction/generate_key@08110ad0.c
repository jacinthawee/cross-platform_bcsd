
undefined4 generate_key(int param_1)

{
  bool bVar1;
  BN_CTX *c;
  BIGNUM *pBVar2;
  int iVar3;
  BIGNUM *rnd;
  BN_MONT_CTX *pBVar4;
  undefined4 uVar5;
  int in_GS_OFFSET;
  BIGNUM *local_44;
  BIGNUM local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  c = BN_CTX_new();
  if (c == (BN_CTX *)0x0) {
LAB_08110ce0:
    rnd = (BIGNUM *)0x0;
    local_44 = (BIGNUM *)0x0;
LAB_08110b72:
    uVar5 = 0;
    ERR_put_error(5,0x67,3,"dh_key.c",0xc3);
    if (local_44 == (BIGNUM *)0x0) goto LAB_08110ba2;
  }
  else {
    rnd = *(BIGNUM **)(param_1 + 0x18);
    bVar1 = false;
    if (rnd == (BIGNUM *)0x0) {
      rnd = BN_new();
      if (rnd == (BIGNUM *)0x0) goto LAB_08110ce0;
      bVar1 = true;
    }
    local_44 = *(BIGNUM **)(param_1 + 0x14);
    if (((local_44 == (BIGNUM *)0x0) && (local_44 = BN_new(), local_44 == (BIGNUM *)0x0)) ||
       ((pBVar4 = (BN_MONT_CTX *)0x0, (*(byte *)(param_1 + 0x1c) & 1) != 0 &&
        (pBVar4 = BN_MONT_CTX_set_locked
                            ((BN_MONT_CTX **)(param_1 + 0x20),(int)(BN_MONT_CTX **)(param_1 + 0x20),
                             (BIGNUM *)0x1a,*(BN_CTX **)(param_1 + 8)), pBVar4 == (BN_MONT_CTX *)0x0
        )))) goto LAB_08110b72;
    if (bVar1) {
      pBVar2 = *(BIGNUM **)(param_1 + 0x24);
      if (pBVar2 == (BIGNUM *)0x0) {
        iVar3 = *(int *)(param_1 + 0x10);
        if (iVar3 == 0) {
          iVar3 = BN_num_bits(*(BIGNUM **)(param_1 + 8));
          iVar3 = iVar3 + -1;
        }
        iVar3 = BN_rand(rnd,iVar3,0,0);
        if (iVar3 != 0) goto LAB_08110c10;
      }
      else {
        while (iVar3 = BN_rand_range(rnd,pBVar2), iVar3 != 0) {
          if ((rnd->top != 0) && (((rnd->top != 1 || (*rnd->d != 1)) || (rnd->neg != 0))))
          goto LAB_08110c10;
          pBVar2 = *(BIGNUM **)(param_1 + 0x24);
        }
      }
      goto LAB_08110b72;
    }
LAB_08110c10:
    pBVar2 = rnd;
    if ((*(byte *)(param_1 + 0x1c) & 2) == 0) {
      pBVar2 = &local_34;
      BN_init(pBVar2);
      local_34.d = rnd->d;
      local_34.top = rnd->top;
      local_34.dmax = rnd->dmax;
      local_34.neg = rnd->neg;
      local_34.flags = local_34.flags & 1U | rnd->flags & 0xfffffffeU | 6;
    }
    iVar3 = (**(code **)(*(int *)(param_1 + 0x44) + 0xc))
                      (param_1,local_44,*(undefined4 *)(param_1 + 0xc),pBVar2,
                       *(undefined4 *)(param_1 + 8),c,pBVar4);
    if (iVar3 == 0) goto LAB_08110b72;
    *(BIGNUM **)(param_1 + 0x14) = local_44;
    *(BIGNUM **)(param_1 + 0x18) = rnd;
    uVar5 = 1;
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    BN_free(local_44);
  }
LAB_08110ba2:
  if ((rnd != (BIGNUM *)0x0) && (*(int *)(param_1 + 0x18) == 0)) {
    BN_free(rnd);
  }
  BN_CTX_free(c);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}

