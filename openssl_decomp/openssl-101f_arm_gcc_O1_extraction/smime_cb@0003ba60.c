
int smime_cb(int param_1,X509_STORE_CTX *param_2)

{
  int iVar1;
  
  iVar1 = X509_STORE_CTX_get_error(param_2);
  if ((iVar1 == 0x2b) || (param_1 == 2 && iVar1 == 0)) {
    policies_print(0,param_2);
  }
  return param_1;
}

