
bool param_missing_gost94(EVP_PKEY *param_1)

{
  void *pvVar1;
  
  pvVar1 = EVP_PKEY_get0(param_1);
  if (pvVar1 != (void *)0x0) {
    return *(int *)((int)pvVar1 + 0x10) == 0;
  }
  return true;
}

