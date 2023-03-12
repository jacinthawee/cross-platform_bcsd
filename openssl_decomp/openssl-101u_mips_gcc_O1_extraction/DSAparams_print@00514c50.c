
int DSAparams_print(BIO *bp,DSA *x)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_new_006a7620)();
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_EVP_PKEY_set1_DSA_006a7668)(iVar1,x);
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_EVP_PKEY_print_params_006a7754)(bp,iVar1,4,0);
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar1);
      return iVar2;
    }
  }
  return 0;
}

