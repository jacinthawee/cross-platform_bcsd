
undefined4 cms_si_cb(int param_1,int *param_2)

{
  int iVar1;
  EVP_PKEY *pkey;
  X509 *a;
  
  if (param_1 == 3) {
    iVar1 = *param_2;
    pkey = *(EVP_PKEY **)(iVar1 + 0x20);
    if (pkey != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(pkey);
    }
    a = *(X509 **)(iVar1 + 0x1c);
    if (a != (X509 *)0x0) {
      X509_free(a);
      return 1;
    }
  }
  return 1;
}

