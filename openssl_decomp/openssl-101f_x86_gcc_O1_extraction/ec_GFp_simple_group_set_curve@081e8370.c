
undefined4
ec_GFp_simple_group_set_curve
          (int *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  int iVar1;
  BIGNUM *r;
  BIGNUM *pBVar2;
  undefined4 uVar3;
  BN_CTX *ctx;
  
  iVar1 = BN_num_bits(param_2);
  if (((iVar1 < 3) || (param_2->top < 1)) || ((*(byte *)param_2->d & 1) == 0)) {
    ERR_put_error(0x10,0xa6,0x67,"ecp_smpl.c",0xb9);
    return 0;
  }
  if (param_5 == (BN_CTX *)0x0) {
    ctx = BN_CTX_new();
    if (ctx == (BN_CTX *)0x0) {
      return 0;
    }
    BN_CTX_start(ctx);
    r = BN_CTX_get(ctx);
    if ((r == (BIGNUM *)0x0) ||
       (pBVar2 = BN_copy((BIGNUM *)(param_1 + 0x12),param_2), param_5 = ctx, pBVar2 == (BIGNUM *)0x0
       )) {
      uVar3 = 0;
      BN_CTX_end(ctx);
      goto LAB_081e842a;
    }
  }
  else {
    BN_CTX_start(param_5);
    r = BN_CTX_get(param_5);
    if ((r == (BIGNUM *)0x0) ||
       (pBVar2 = BN_copy((BIGNUM *)(param_1 + 0x12),param_2), pBVar2 == (BIGNUM *)0x0)) {
      BN_CTX_end(param_5);
      return 0;
    }
    ctx = (BN_CTX *)0x0;
  }
  BN_set_negative((BIGNUM *)(param_1 + 0x12),0);
  iVar1 = BN_nnmod(r,param_3,param_2,param_5);
  if (iVar1 == 0) {
LAB_081e8411:
    uVar3 = 0;
  }
  else {
    if (*(code **)(*param_1 + 0x90) == (code *)0x0) {
      pBVar2 = BN_copy((BIGNUM *)(param_1 + 0x1d),r);
      if (pBVar2 != (BIGNUM *)0x0) goto LAB_081e84a2;
      goto LAB_081e8411;
    }
    iVar1 = (**(code **)(*param_1 + 0x90))(param_1,param_1 + 0x1d,r,param_5);
    if (iVar1 == 0) goto LAB_081e8411;
LAB_081e84a2:
    pBVar2 = (BIGNUM *)(param_1 + 0x22);
    iVar1 = BN_nnmod(pBVar2,param_4,param_2,param_5);
    if ((iVar1 == 0) ||
       (((*(code **)(*param_1 + 0x90) != (code *)0x0 &&
         (iVar1 = (**(code **)(*param_1 + 0x90))(param_1,pBVar2,pBVar2,param_5), iVar1 == 0)) ||
        (iVar1 = BN_add_word(r,3), iVar1 == 0)))) goto LAB_081e8411;
    uVar3 = 1;
    iVar1 = BN_cmp(r,(BIGNUM *)(param_1 + 0x12));
    param_1[0x27] = (uint)(iVar1 == 0);
  }
  BN_CTX_end(param_5);
  if (ctx == (BN_CTX *)0x0) {
    return uVar3;
  }
LAB_081e842a:
  BN_CTX_free(ctx);
  return uVar3;
}

