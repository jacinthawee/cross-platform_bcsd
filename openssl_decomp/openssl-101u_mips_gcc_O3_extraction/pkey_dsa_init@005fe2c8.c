
undefined4 pkey_dsa_init(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18,"dsa_pmeth.c",0x54,param_4,&_gp)
  ;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = 0;
    puVar1[5] = 0;
    *puVar1 = 0x400;
    puVar1[1] = 0xa0;
    *(undefined4 **)(param_1 + 0x14) = puVar1;
    *(undefined4 **)(param_1 + 0x20) = puVar1 + 3;
    *(undefined4 *)(param_1 + 0x24) = 2;
    return 1;
  }
  return 0;
}

