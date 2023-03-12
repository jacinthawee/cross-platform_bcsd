
undefined4
ec_GFp_nist_group_set_curve
          (int param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4,BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  int iVar2;
  undefined4 uVar3;
  BN_CTX *pBVar4;
  
  if (param_5 == (BN_CTX *)0x0) {
    param_5 = BN_CTX_new();
    if (param_5 == (BN_CTX *)0x0) {
      return 0;
    }
    BN_CTX_start(param_5);
    pBVar1 = BN_CTX_get(param_5);
    pBVar4 = param_5;
    if (pBVar1 == (BIGNUM *)0x0) {
      uVar3 = 0;
      BN_CTX_end(param_5);
      goto LAB_081e2a41;
    }
  }
  else {
    BN_CTX_start(param_5);
    pBVar1 = BN_CTX_get(param_5);
    pBVar4 = (BN_CTX *)0x0;
    if (pBVar1 == (BIGNUM *)0x0) {
      BN_CTX_end(param_5);
      return 0;
    }
  }
  pBVar1 = BN_get0_nist_prime_192();
  iVar2 = BN_ucmp(pBVar1,param_2);
  if (iVar2 == 0) {
    *(code **)(param_1 + 0xa8) = BN_nist_mod_192;
LAB_081e2a15:
    uVar3 = ec_GFp_simple_group_set_curve(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    pBVar1 = BN_get0_nist_prime_224();
    iVar2 = BN_ucmp(pBVar1,param_2);
    if (iVar2 == 0) {
      *(code **)(param_1 + 0xa8) = BN_nist_mod_224;
      goto LAB_081e2a15;
    }
    pBVar1 = BN_get0_nist_prime_256();
    iVar2 = BN_ucmp(pBVar1,param_2);
    if (iVar2 == 0) {
      *(code **)(param_1 + 0xa8) = BN_nist_mod_256;
      goto LAB_081e2a15;
    }
    pBVar1 = BN_get0_nist_prime_384();
    iVar2 = BN_ucmp(pBVar1,param_2);
    if (iVar2 == 0) {
      *(code **)(param_1 + 0xa8) = BN_nist_mod_384;
      goto LAB_081e2a15;
    }
    pBVar1 = BN_get0_nist_prime_521();
    iVar2 = BN_ucmp(pBVar1,param_2);
    if (iVar2 == 0) {
      *(code **)(param_1 + 0xa8) = BN_nist_mod_521;
      goto LAB_081e2a15;
    }
    uVar3 = 0;
    ERR_put_error(0x10,0xca,0x87,"ecp_nist.c",0x9a);
  }
  BN_CTX_end(param_5);
  param_5 = pBVar4;
  if (pBVar4 == (BN_CTX *)0x0) {
    return uVar3;
  }
LAB_081e2a41:
  BN_CTX_free(param_5);
  return uVar3;
}

