
undefined4 gost_control_func(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (param_2 == 200) {
    iVar1 = (*(code *)PTR_getenv_006aab6c)("CRYPT_PARAMS");
    if (iVar1 != 0) {
      param_4 = iVar1;
    }
    if (gost_params != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    gost_params = (*(code *)PTR_BUF_strdup_006a80dc)(param_4);
    return 1;
  }
  return 0xffffffff;
}

