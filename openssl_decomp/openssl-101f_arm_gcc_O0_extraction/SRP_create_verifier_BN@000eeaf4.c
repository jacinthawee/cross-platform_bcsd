
void SRP_create_verifier_BN
               (int param_1,BIGNUM *param_2,BIGNUM **param_3,BIGNUM **param_4,BIGNUM *param_5,
               BIGNUM *param_6)

{
  bool bVar1;
  bool bVar2;
  BIGNUM *ctx;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  bool bVar5;
  bool bVar6;
  uchar auStack_9f0 [2500];
  int local_2c;
  
  local_2c = __TMC_END__;
  ctx = (BIGNUM *)BN_CTX_new();
  bVar5 = param_2 == (BIGNUM *)0x0;
  bVar1 = param_1 == 0;
  if (bVar5 || bVar1) {
    param_2 = (BIGNUM *)0x0;
  }
  pBVar3 = param_2;
  if (!bVar5 && !bVar1) {
    bVar6 = param_4 == (BIGNUM **)0x0;
    bVar2 = param_3 == (BIGNUM **)0x0;
    pBVar4 = param_2;
    if (bVar6 || bVar2) {
      pBVar4 = (BIGNUM *)(uint)(bVar5 || bVar1);
    }
    param_2 = pBVar4;
    pBVar3 = pBVar4;
    if (((!bVar6 && !bVar2) &&
        (param_2 = (BIGNUM *)(uint)(bVar6 || bVar2), pBVar3 = (BIGNUM *)(uint)(bVar6 || bVar2),
        param_6 != (BIGNUM *)0x0 && param_5 != (BIGNUM *)0x0)) &&
       (param_2 = ctx, pBVar3 = ctx, ctx != (BIGNUM *)0x0)) {
      pBVar3 = *param_3;
      if (pBVar3 == (BIGNUM *)0x0) {
        RAND_pseudo_bytes(auStack_9f0,0x14);
        pBVar3 = BN_bin2bn(auStack_9f0,0x14,(BIGNUM *)0x0);
        *param_3 = pBVar3;
      }
      param_2 = (BIGNUM *)SRP_Calc_x(pBVar3,param_1,pBVar4);
      pBVar3 = BN_new();
      *param_4 = pBVar3;
      if (pBVar3 != (BIGNUM *)0x0) {
        pBVar3 = (BIGNUM *)BN_mod_exp(pBVar3,param_6,param_2,param_5,(BN_CTX *)ctx);
        if (pBVar3 == (BIGNUM *)0x0) {
          BN_clear_free(*param_4);
        }
        else {
          pBVar3 = (BIGNUM *)0x1;
        }
      }
    }
  }
  BN_clear_free(param_2);
  BN_CTX_free((BN_CTX *)ctx);
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pBVar3);
  }
  return;
}

