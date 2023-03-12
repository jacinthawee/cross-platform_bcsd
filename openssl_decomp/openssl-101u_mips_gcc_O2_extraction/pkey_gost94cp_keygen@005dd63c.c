
undefined4 pkey_gost94cp_keygen(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)(*(code *)PTR_EVP_PKEY_CTX_get_data_006a95d0)();
  if (*piVar1 == 0) {
    (*(code *)PTR_ERR_GOST_error_006a95e4)(0x8b,0x77,"gost_pmeth.c",0x101);
  }
  else {
    uVar2 = (*(code *)PTR_DSA_new_006a7528)();
    iVar3 = fill_GOST94_params(uVar2,*piVar1);
    if (iVar3 != 0) {
      (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_2,0x32c,uVar2);
      uVar2 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2);
      gost_sign_keygen(uVar2);
      return 1;
    }
    (*(code *)PTR_DSA_free_006a7530)(uVar2);
  }
  return 0;
}
