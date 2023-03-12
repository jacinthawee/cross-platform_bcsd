
int RSA_print(BIO *bp,RSA *r,int offset)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_new_006a8710)();
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_EVP_PKEY_set1_RSA_006a8714)(iVar1,r);
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_EVP_PKEY_print_private_006a8840)(bp,iVar1,offset,0);
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar1);
      return iVar2;
    }
  }
  return 0;
}

