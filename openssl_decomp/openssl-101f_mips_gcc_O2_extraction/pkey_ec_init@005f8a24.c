
undefined4 pkey_ec_init(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(8,"ec_pmeth.c",0x50,param_4,&_gp);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    *(undefined4 **)(param_1 + 0x14) = puVar1;
    return 1;
  }
  return 0;
}

