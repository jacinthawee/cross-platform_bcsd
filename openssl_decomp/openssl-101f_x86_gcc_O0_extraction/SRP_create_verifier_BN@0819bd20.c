
undefined4
SRP_create_verifier_BN
          (int param_1,int param_2,BIGNUM **param_3,BIGNUM **param_4,BIGNUM *param_5,BIGNUM *param_6
          )

{
  BN_CTX *ctx;
  BIGNUM *pBVar1;
  BIGNUM *r;
  int iVar2;
  undefined4 uVar3;
  int in_GS_OFFSET;
  uchar local_9e4 [2500];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ctx = BN_CTX_new();
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == (BIGNUM **)0x0)) ||
     (((param_4 == (BIGNUM **)0x0 || (param_5 == (BIGNUM *)0x0 || param_6 == (BIGNUM *)0x0)) ||
      (ctx == (BN_CTX *)0x0)))) {
    pBVar1 = (BIGNUM *)0x0;
    uVar3 = 0;
  }
  else {
    pBVar1 = *param_3;
    if (pBVar1 == (BIGNUM *)0x0) {
      RAND_pseudo_bytes(local_9e4,0x14);
      pBVar1 = BN_bin2bn(local_9e4,0x14,(BIGNUM *)0x0);
      *param_3 = pBVar1;
    }
    uVar3 = 0;
    pBVar1 = (BIGNUM *)SRP_Calc_x(pBVar1,param_1,param_2);
    r = BN_new();
    *param_4 = r;
    if (r != (BIGNUM *)0x0) {
      uVar3 = 1;
      iVar2 = BN_mod_exp(r,param_6,pBVar1,param_5,ctx);
      if (iVar2 == 0) {
        uVar3 = 0;
        BN_clear_free(*param_4);
      }
    }
  }
  BN_clear_free(pBVar1);
  BN_CTX_free(ctx);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

