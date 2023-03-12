
undefined4 pkey_cmac_keygen(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_CMAC_CTX_new_006aa638)();
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = (*(code *)PTR_CMAC_CTX_copy_006aa628)(iVar1,*(undefined4 *)(param_1 + 0x14));
  if (iVar2 != 0) {
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_2,0x37e,iVar1);
    return 1;
  }
  (*(code *)PTR_CMAC_CTX_free_006aa624)(iVar1);
  return 0;
}

