
bool param_missing_gost01(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)();
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(iVar1);
    return iVar1 == 0;
  }
  return true;
}
