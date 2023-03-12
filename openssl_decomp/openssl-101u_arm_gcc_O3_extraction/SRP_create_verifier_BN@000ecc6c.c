
void SRP_create_verifier_BN
               (int param_1,int param_2,BIGNUM **param_3,BIGNUM **param_4,BIGNUM *param_5,
               BIGNUM *param_6)

{
  BN_CTX *ctx;
  BIGNUM *r;
  int iVar1;
  BIGNUM *a;
  undefined4 uVar2;
  BIGNUM *p;
  uchar auStack_9f0 [2500];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  ctx = BN_CTX_new();
  if ((((param_2 == 0 || param_1 == 0) || (param_4 == (BIGNUM **)0x0 || param_3 == (BIGNUM **)0x0))
      || (param_6 == (BIGNUM *)0x0 || param_5 == (BIGNUM *)0x0)) || (ctx == (BN_CTX *)0x0)) {
LAB_000eccb0:
    a = (BIGNUM *)0x0;
    p = (BIGNUM *)0x0;
  }
  else {
    a = *param_3;
    if (a == (BIGNUM *)0x0) {
      iVar1 = RAND_bytes(auStack_9f0,0x14);
      if (iVar1 < 1) goto LAB_000eccb0;
      a = BN_bin2bn(auStack_9f0,0x14,(BIGNUM *)0x0);
    }
    p = (BIGNUM *)SRP_Calc_x(a,param_1,param_2);
    r = BN_new();
    *param_4 = r;
    if (r != (BIGNUM *)0x0) {
      iVar1 = BN_mod_exp(r,param_6,p,param_5,ctx);
      if (iVar1 != 0) {
        *param_3 = a;
        uVar2 = 1;
        goto LAB_000eccc6;
      }
      BN_clear_free(*param_4);
    }
  }
  if (*param_3 == a) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    BN_clear_free(a);
  }
LAB_000eccc6:
  BN_clear_free(p);
  BN_CTX_free(ctx);
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}

