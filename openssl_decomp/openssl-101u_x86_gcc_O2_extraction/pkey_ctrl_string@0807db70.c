
int pkey_ctrl_string(EVP_PKEY_CTX *param_1,char *param_2)

{
  char *__s;
  char *value;
  int iVar1;
  
  __s = BUF_strdup(param_2);
  if (__s == (char *)0x0) {
    iVar1 = -1;
  }
  else {
    value = strchr(__s,0x3a);
    if (value != (char *)0x0) {
      *value = '\0';
      value = value + 1;
    }
    iVar1 = EVP_PKEY_CTX_ctrl_str(param_1,__s,value);
    CRYPTO_free(__s);
  }
  return iVar1;
}

