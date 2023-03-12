
undefined4 pkey_gost01cp_keygen(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)(*(code *)PTR_EVP_PKEY_CTX_get_data_006aa6dc)();
  if (*piVar1 == 0) {
    (*(code *)PTR_ERR_GOST_error_006aa6f0)(0x8a,0x77,"gost_pmeth.c",299);
  }
  else {
    uVar2 = (*(code *)PTR_EC_KEY_new_006a82a8)();
    iVar3 = (*(code *)PTR_fill_GOST2001_params_006aa714)(uVar2,*piVar1);
    if (iVar3 != 0) {
      (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_2,0x32b,uVar2);
      uVar2 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
      (*(code *)PTR_gost2001_keygen_006aa71c)(uVar2);
      return 1;
    }
    (*(code *)PTR_EC_KEY_free_006a82d8)(uVar2);
  }
  return 0;
}

