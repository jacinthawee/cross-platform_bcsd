
undefined4 gost_set_default_param(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    return 0;
  }
  iVar1 = (*(code *)PTR_getenv_006a9a60)("CRYPT_PARAMS");
  if (iVar1 != 0) {
    param_2 = iVar1;
  }
  if (gost_params != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  gost_params = (*(code *)PTR_BUF_strdup_006a6fdc)(param_2);
  return 1;
}

