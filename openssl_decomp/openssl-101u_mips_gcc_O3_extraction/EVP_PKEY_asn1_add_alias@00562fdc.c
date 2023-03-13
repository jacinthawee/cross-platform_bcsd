
int EVP_PKEY_asn1_add_alias(int to,int from)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x6c,"ameth_lib.c",0x11d);
  if (piVar1 != (int *)0x0) {
    (*(code *)PTR_memset_006a99f4)(piVar1,0,0x6c);
    iVar2 = app_methods;
    *piVar1 = from;
    piVar1[4] = 0;
    piVar1[3] = 0;
    piVar1[2] = 3;
    piVar1[5] = 0;
    piVar1[6] = 0;
    piVar1[7] = 0;
    piVar1[8] = 0;
    piVar1[9] = 0;
    piVar1[10] = 0;
    piVar1[0xb] = 0;
    piVar1[0x18] = 0;
    piVar1[0x17] = 0;
    piVar1[0x19] = 0;
    piVar1[0x1a] = 0;
    piVar1[0xc] = 0;
    piVar1[0xd] = 0;
    piVar1[0xe] = 0;
    piVar1[0xf] = 0;
    piVar1[0x10] = 0;
    piVar1[0x11] = 0;
    piVar1[0x12] = 0;
    piVar1[0x13] = 0;
    piVar1[0x15] = 0;
    piVar1[0x16] = 0;
    piVar1[1] = to;
    if (((iVar2 != 0) ||
        (iVar2 = (*(code *)PTR_sk_new_006a806c)(ameth_cmp), app_methods = iVar2, iVar2 != 0)) &&
       (iVar2 = (*(code *)PTR_sk_push_006a6fa8)(iVar2,piVar1), iVar2 != 0)) {
      (*(code *)PTR_sk_sort_006a83bc)(app_methods);
      return 1;
    }
    if ((piVar1[2] & 2U) != 0) {
      if (piVar1[3] != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      if (piVar1[4] != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(piVar1);
    }
  }
  return 0;
}

