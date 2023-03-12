
X509_STORE * setup_verify(BIO *param_1,char *param_2,char *param_3)

{
  X509_STORE *v;
  X509_LOOKUP_METHOD *pXVar1;
  X509_LOOKUP *pXVar2;
  int iVar3;
  
  v = X509_STORE_new();
  if (v != (X509_STORE *)0x0) {
    pXVar1 = X509_LOOKUP_file();
    pXVar2 = X509_STORE_add_lookup(v,pXVar1);
    if (pXVar2 != (X509_LOOKUP *)0x0) {
      if (param_2 == (char *)0x0) {
        X509_LOOKUP_ctrl(pXVar2,1,(char *)0x0,3,(char **)0x0);
      }
      else {
        iVar3 = X509_LOOKUP_ctrl(pXVar2,1,param_2,1,(char **)0x0);
        if (iVar3 == 0) {
          BIO_printf(param_1,"Error loading file %s\n",param_2);
          goto LAB_00033f4a;
        }
      }
      pXVar1 = X509_LOOKUP_hash_dir();
      pXVar2 = X509_STORE_add_lookup(v,pXVar1);
      if (pXVar2 != (X509_LOOKUP *)0x0) {
        if (param_3 == (char *)0x0) {
          X509_LOOKUP_ctrl(pXVar2,2,(char *)0x0,3,(char **)0x0);
        }
        else {
          iVar3 = X509_LOOKUP_ctrl(pXVar2,2,param_3,1,(char **)0x0);
          if (iVar3 == 0) {
            BIO_printf(param_1,"Error loading directory %s\n",param_3);
            goto LAB_00033f4a;
          }
        }
        ERR_clear_error();
        return v;
      }
    }
  }
LAB_00033f4a:
  X509_STORE_free(v);
  return (X509_STORE *)0x0;
}

