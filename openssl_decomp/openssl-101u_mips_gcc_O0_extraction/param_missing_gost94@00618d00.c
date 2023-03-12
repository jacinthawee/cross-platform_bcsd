
bool param_missing_gost94(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)();
  if (iVar1 != 0) {
    return *(int *)(iVar1 + 0x10) == 0;
  }
  return true;
}

