
undefined4
ec_GFp_nist_group_set_curve
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  BIGNUM *pBVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_5 == 0) {
    param_5 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (param_5 == 0) {
      return 0;
    }
    (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
    iVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    iVar1 = param_5;
    if (iVar3 == 0) {
      uVar4 = 0;
      (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
      goto LAB_00627f8c;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
    iVar1 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    if (iVar1 == 0) {
      (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
      return 0;
    }
    iVar1 = 0;
  }
  pBVar2 = BN_get0_nist_prime_192();
  iVar3 = (*(code *)PTR_BN_ucmp_006a9678)(pBVar2,param_2);
  if (iVar3 == 0) {
    *(undefined **)(param_1 + 0xa8) = PTR_BN_nist_mod_192_006aa9fc;
LAB_00627f54:
    uVar4 = ec_GFp_simple_group_set_curve(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    pBVar2 = BN_get0_nist_prime_224();
    iVar3 = (*(code *)PTR_BN_ucmp_006a9678)(pBVar2,param_2);
    if (iVar3 == 0) {
      *(undefined **)(param_1 + 0xa8) = PTR_BN_nist_mod_224_006aaa04;
      goto LAB_00627f54;
    }
    pBVar2 = BN_get0_nist_prime_256();
    iVar3 = (*(code *)PTR_BN_ucmp_006a9678)(pBVar2,param_2);
    if (iVar3 == 0) {
      *(undefined **)(param_1 + 0xa8) = PTR_BN_nist_mod_256_006aaa0c;
      goto LAB_00627f54;
    }
    pBVar2 = BN_get0_nist_prime_384();
    iVar3 = (*(code *)PTR_BN_ucmp_006a9678)(pBVar2,param_2);
    if (iVar3 == 0) {
      *(undefined **)(param_1 + 0xa8) = PTR_BN_nist_mod_384_006aaa14;
      goto LAB_00627f54;
    }
    pBVar2 = BN_get0_nist_prime_521();
    iVar3 = (*(code *)PTR_BN_ucmp_006a9678)(pBVar2,param_2);
    if (iVar3 == 0) {
      *(undefined **)(param_1 + 0xa8) = PTR_BN_nist_mod_521_006aaa1c;
      goto LAB_00627f54;
    }
    uVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xca,0x87,"ecp_nist.c",0x9a);
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
  param_5 = iVar1;
  if (iVar1 == 0) {
    return uVar4;
  }
LAB_00627f8c:
  (*(code *)PTR_BN_CTX_free_006a8a40)(param_5);
  return uVar4;
}

