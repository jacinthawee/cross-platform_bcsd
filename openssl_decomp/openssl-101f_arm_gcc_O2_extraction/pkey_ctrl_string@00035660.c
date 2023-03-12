
int pkey_ctrl_string(EVP_PKEY_CTX *param_1,char *param_2)

{
  char *__s;
  char *pcVar1;
  int iVar2;
  char *value;
  
  __s = BUF_strdup(param_2);
  if (__s != (char *)0x0) {
    pcVar1 = strchr(__s,0x3a);
    value = pcVar1;
    if (pcVar1 != (char *)0x0) {
      value = pcVar1 + 1;
      *pcVar1 = '\0';
    }
    iVar2 = EVP_PKEY_CTX_ctrl_str(param_1,__s,value);
    CRYPTO_free(__s);
    return iVar2;
  }
  return -1;
}

