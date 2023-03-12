
size_t EC_GROUP_set_seed(EC_GROUP *param_1,uchar *param_2,size_t len)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x3c) != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  if ((len != 0) && (param_2 != (uchar *)0x0)) {
    iVar1 = (*(code *)PTR_CRYPTO_malloc_006a8108)(len,"ec_lib.c",0x182);
    *(int *)(param_1 + 0x3c) = iVar1;
    if (iVar1 != 0) {
      (*(code *)PTR_memcpy_006aabf4)(iVar1,param_2,len);
      *(size_t *)(param_1 + 0x40) = len;
      return len;
    }
    return 0;
  }
  return 1;
}

