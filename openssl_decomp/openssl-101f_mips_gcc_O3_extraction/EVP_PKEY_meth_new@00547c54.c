
EVP_PKEY_METHOD * EVP_PKEY_meth_new(int id,int flags)

{
  int *piVar1;
  
  piVar1 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x6c,"pmeth_lib.c",0xcb);
  if (piVar1 != (int *)0x0) {
    (*(code *)PTR_memset_006aab00)(piVar1,0,0x6c);
    *piVar1 = id;
    piVar1[1] = flags | 1;
    piVar1[2] = 0;
    piVar1[3] = 0;
    piVar1[4] = 0;
    piVar1[5] = 0;
    piVar1[6] = 0;
    piVar1[7] = 0;
    piVar1[8] = 0;
    piVar1[9] = 0;
    piVar1[10] = 0;
    piVar1[0xb] = 0;
    piVar1[0xc] = 0;
    piVar1[0xd] = 0;
    piVar1[0xe] = 0;
    piVar1[0xf] = 0;
    piVar1[0x10] = 0;
    piVar1[0x11] = 0;
    piVar1[0x12] = 0;
    piVar1[0x13] = 0;
    piVar1[0x14] = 0;
    piVar1[0x15] = 0;
    piVar1[0x16] = 0;
    piVar1[0x17] = 0;
    piVar1[0x18] = 0;
    piVar1[0x19] = 0;
    piVar1[0x1a] = 0;
  }
  return (EVP_PKEY_METHOD *)piVar1;
}

