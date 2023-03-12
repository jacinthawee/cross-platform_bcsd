
int get_gost_engine_param(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = gost_params;
    if (gost_params == 0) {
      iVar1 = (*(code *)PTR_getenv_006a9a60)("CRYPT_PARAMS");
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(code *)PTR_BUF_strdup_006a6fdc)(iVar1);
        gost_params = iVar1;
      }
    }
    return iVar1;
  }
  return 0;
}

