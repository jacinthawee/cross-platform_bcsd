
undefined4 pkey_gost94cp_keygen(EVP_PKEY_CTX *param_1,EVP_PKEY *param_2)

{
  int *piVar1;
  DSA *r;
  int iVar2;
  void *pvVar3;
  
  piVar1 = (int *)EVP_PKEY_CTX_get_data(param_1);
  if (*piVar1 == 0) {
    ERR_GOST_error(0x8b,0x77,"gost_pmeth.c",0x117);
  }
  else {
    r = DSA_new();
    iVar2 = fill_GOST94_params(r,*piVar1);
    if (iVar2 != 0) {
      EVP_PKEY_assign(param_2,0x32c,r);
      pvVar3 = EVP_PKEY_get0(param_2);
      gost_sign_keygen(pvVar3);
      return 1;
    }
    DSA_free(r);
  }
  return 0;
}

