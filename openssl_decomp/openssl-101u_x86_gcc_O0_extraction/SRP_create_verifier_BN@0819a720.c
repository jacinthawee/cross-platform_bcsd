
undefined4
SRP_create_verifier_BN
          (int param_1,int param_2,BIGNUM **param_3,BIGNUM **param_4,BIGNUM *param_5,BIGNUM *param_6
          )

{
  BN_CTX *ctx;
  BIGNUM *p;
  BIGNUM *r;
  int iVar1;
  BIGNUM *a;
  undefined4 uVar2;
  int in_GS_OFFSET;
  uchar local_9e4 [2500];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ctx = BN_CTX_new();
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == (BIGNUM **)0x0)) ||
     (((param_4 == (BIGNUM **)0x0 || (param_5 == (BIGNUM *)0x0 || param_6 == (BIGNUM *)0x0)) ||
      (ctx == (BN_CTX *)0x0)))) {
LAB_0819a800:
    a = (BIGNUM *)0x0;
    p = (BIGNUM *)0x0;
  }
  else {
    a = *param_3;
    if (a == (BIGNUM *)0x0) {
      iVar1 = RAND_bytes(local_9e4,0x14);
      if (iVar1 < 1) goto LAB_0819a800;
      a = BN_bin2bn(local_9e4,0x14,(BIGNUM *)0x0);
    }
    p = (BIGNUM *)SRP_Calc_x(a,param_1,param_2);
    r = BN_new();
    *param_4 = r;
    if (r != (BIGNUM *)0x0) {
      iVar1 = BN_mod_exp(r,param_6,p,param_5,ctx);
      if (iVar1 != 0) {
        *param_3 = a;
        uVar2 = 1;
        goto LAB_0819a817;
      }
      BN_clear_free(*param_4);
    }
  }
  if (a == *param_3) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    BN_clear_free(a);
  }
LAB_0819a817:
  BN_clear_free(p);
  BN_CTX_free(ctx);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

