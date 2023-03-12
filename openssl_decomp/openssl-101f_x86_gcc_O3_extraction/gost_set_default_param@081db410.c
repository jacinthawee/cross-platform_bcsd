
undefined4 gost_set_default_param(int param_1,char *param_2)

{
  char *str;
  
  if (param_1 != 0) {
    return 0;
  }
  str = getenv("CRYPT_PARAMS");
  if (str == (char *)0x0) {
    str = param_2;
  }
  if (gost_params != (char *)0x0) {
    CRYPTO_free(gost_params);
  }
  gost_params = BUF_strdup(str);
  return 1;
}

