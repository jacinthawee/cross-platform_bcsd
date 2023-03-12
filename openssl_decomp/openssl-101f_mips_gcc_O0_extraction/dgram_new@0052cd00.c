
undefined4 dgram_new(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  iVar1 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x38,"bss_dgram.c",0xe1);
  if (iVar1 != 0) {
    (*(code *)PTR_memset_006aab00)(iVar1,0,0x38);
    *(int *)(param_1 + 0x20) = iVar1;
    *(undefined4 *)(param_1 + 0x14) = 0;
    return 1;
  }
  return 0;
}

