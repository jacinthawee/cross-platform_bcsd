
int X509_VERIFY_PARAM_set1_name(X509_VERIFY_PARAM *param,char *name)

{
  char *pcVar1;
  
  if (param->name != (char *)0x0) {
    CRYPTO_free(param->name);
  }
  pcVar1 = BUF_strdup(name);
  param->name = pcVar1;
  return (uint)(pcVar1 != (char *)0x0);
}
