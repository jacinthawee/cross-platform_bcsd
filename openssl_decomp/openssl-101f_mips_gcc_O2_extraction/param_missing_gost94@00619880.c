
bool param_missing_gost94(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)();
  if (iVar1 != 0) {
    return *(int *)(iVar1 + 0x10) == 0;
  }
  return true;
}

