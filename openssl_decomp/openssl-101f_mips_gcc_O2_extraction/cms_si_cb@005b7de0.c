
undefined4 cms_si_cb(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 != 3) {
    return 1;
  }
  iVar1 = *param_2;
  if (*(int *)(iVar1 + 0x20) != 0) {
    (*(code *)PTR_EVP_PKEY_free_006a7f78)();
  }
  if (*(int *)(iVar1 + 0x1c) != 0) {
    (*(code *)PTR_X509_free_006a7f90)();
  }
  return 1;
}

