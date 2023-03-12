
undefined4 cms_ri_cb(int param_1,int **param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == 2) {
    piVar2 = *param_2;
    iVar1 = *piVar2;
    if (iVar1 == 0) {
      iVar1 = piVar2[1];
      if (*(int *)(iVar1 + 0x14) != 0) {
        (*(code *)PTR_EVP_PKEY_free_006a7f78)();
      }
      if (*(int *)(iVar1 + 0x10) != 0) {
        (*(code *)PTR_X509_free_006a7f90)();
        return 1;
      }
    }
    else if ((iVar1 == 2) || (iVar1 == 3)) {
      iVar1 = piVar2[1];
      if (*(int *)(iVar1 + 0x10) != 0) {
        (*(code *)PTR_OPENSSL_cleanse_006a8174)
                  (*(int *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14));
        (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar1 + 0x10));
      }
    }
  }
  return 1;
}

