
undefined4 gost_control_func(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (param_2 == 200) {
    iVar1 = (*(code *)PTR_getenv_006a9a60)("CRYPT_PARAMS");
    if (iVar1 != 0) {
      param_4 = iVar1;
    }
    if (gost_params != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    gost_params = (*(code *)PTR_BUF_strdup_006a6fdc)(param_4);
    return 1;
  }
  return 0xffffffff;
}

