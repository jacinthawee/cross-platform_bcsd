
undefined4 pkey_gost01cp_keygen(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)(*(code *)PTR_EVP_PKEY_CTX_get_data_006a95d0)();
  if (*piVar1 == 0) {
    (*(code *)PTR_ERR_GOST_error_006a95e4)(0x8a,0x77,"gost_pmeth.c",0x113);
  }
  else {
    uVar2 = (*(code *)PTR_EC_KEY_new_006a71a8)();
    iVar3 = (*(code *)PTR_fill_GOST2001_params_006a9608)(uVar2,*piVar1);
    if (iVar3 != 0) {
      (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_2,0x32b,uVar2);
      uVar2 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2);
      (*(code *)PTR_gost2001_keygen_006a9610)(uVar2);
      return 1;
    }
    (*(code *)PTR_EC_KEY_free_006a71d4)(uVar2);
  }
  return 0;
}

