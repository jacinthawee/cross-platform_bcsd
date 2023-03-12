
undefined4
ec_GFp_nist_group_set_curve
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  BIGNUM *pBVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_5 == 0) {
    param_5 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if (param_5 == 0) {
      return 0;
    }
    (*(code *)PTR_BN_CTX_start_006a8528)(param_5);
    iVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    iVar1 = param_5;
    if (iVar3 == 0) {
      uVar4 = 0;
      (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
      goto LAB_0062755c;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a8528)(param_5);
    iVar1 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    if (iVar1 == 0) {
      (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
      return 0;
    }
    iVar1 = 0;
  }
  pBVar2 = BN_get0_nist_prime_192();
  iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(pBVar2,param_2);
  if (iVar3 == 0) {
    *(undefined **)(param_1 + 0xa8) = PTR_BN_nist_mod_192_006a98ec;
LAB_00627524:
    uVar4 = ec_GFp_simple_group_set_curve(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    pBVar2 = BN_get0_nist_prime_224();
    iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(pBVar2,param_2);
    if (iVar3 == 0) {
      *(undefined **)(param_1 + 0xa8) = PTR_BN_nist_mod_224_006a98f4;
      goto LAB_00627524;
    }
    pBVar2 = BN_get0_nist_prime_256();
    iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(pBVar2,param_2);
    if (iVar3 == 0) {
      *(undefined **)(param_1 + 0xa8) = PTR_BN_nist_mod_256_006a98fc;
      goto LAB_00627524;
    }
    pBVar2 = BN_get0_nist_prime_384();
    iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(pBVar2,param_2);
    if (iVar3 == 0) {
      *(undefined **)(param_1 + 0xa8) = PTR_BN_nist_mod_384_006a9904;
      goto LAB_00627524;
    }
    pBVar2 = BN_get0_nist_prime_521();
    iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(pBVar2,param_2);
    if (iVar3 == 0) {
      *(undefined **)(param_1 + 0xa8) = PTR_BN_nist_mod_521_006a990c;
      goto LAB_00627524;
    }
    uVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xca,0x87,"ecp_nist.c",0x9d);
  }
  (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
  param_5 = iVar1;
  if (iVar1 == 0) {
    return uVar4;
  }
LAB_0062755c:
  (*(code *)PTR_BN_CTX_free_006a7954)(param_5);
  return uVar4;
}

