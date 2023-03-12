
undefined4 pkey_gost94_paramgen(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)(*(code *)PTR_EVP_PKEY_CTX_get_data_006aa6dc)();
  if (*piVar1 == 0) {
    (*(code *)PTR_ERR_GOST_error_006aa6f0)(0x8b,0x77,"gost_pmeth.c",0x117);
    return 0;
  }
  uVar2 = (*(code *)PTR_DSA_new_006a8624)();
  iVar3 = fill_GOST94_params(uVar2,*piVar1);
  if (iVar3 != 0) {
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_2,0x32c,uVar2);
    return 1;
  }
  (*(code *)PTR_DSA_free_006a862c)(uVar2);
  return 0;
}

