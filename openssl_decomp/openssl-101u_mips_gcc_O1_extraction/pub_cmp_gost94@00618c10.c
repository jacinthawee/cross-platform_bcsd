
bool pub_cmp_gost94(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)();
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2);
  if ((((iVar1 != 0) && (iVar2 != 0)) && (*(int *)(iVar1 + 0x18) != 0)) &&
     (*(int *)(iVar2 + 0x18) != 0)) {
    iVar1 = (*(code *)PTR_BN_cmp_006a7960)();
    return iVar1 == 0;
  }
  return false;
}

