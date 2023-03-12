
undefined4 gost_control_func(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  char *str;
  undefined4 uVar1;
  
  if (param_2 == 200) {
    str = getenv("CRYPT_PARAMS");
    if (str == (char *)0x0) {
      str = param_4;
    }
    if (gost_params != (char *)0x0) {
      CRYPTO_free(gost_params);
    }
    gost_params = BUF_strdup(str);
    uVar1 = 1;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

