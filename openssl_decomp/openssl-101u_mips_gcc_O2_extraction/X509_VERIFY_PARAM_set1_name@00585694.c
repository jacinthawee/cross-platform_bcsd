
int X509_VERIFY_PARAM_set1_name(X509_VERIFY_PARAM *param,char *name)

{
  char *pcVar1;
  
  if (param->name != (char *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  pcVar1 = (char *)(*(code *)PTR_BUF_strdup_006a6fdc)(name);
  param->name = pcVar1;
  return (uint)(pcVar1 != (char *)0x0);
}

