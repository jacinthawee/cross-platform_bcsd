
undefined4 nbiof_new(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(8,"bf_nbio.c",0x6a,param_4,&_gp);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0xffffffff;
    puVar1[1] = 0xffffffff;
    *(undefined4 **)(param_1 + 0x20) = puVar1;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0xc) = 1;
    return 1;
  }
  return 0;
}

