
undefined4 pkey_hmac_init(int param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0xe4,"hm_pmeth.c",0x4e);
  puVar1 = PTR_HMAC_CTX_init_006a7a1c;
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 0;
    puVar2[3] = 0;
    puVar2[1] = 0;
    puVar2[4] = 0;
    puVar2[2] = 4;
    (*(code *)puVar1)(puVar2 + 5);
    *(undefined4 **)(param_1 + 0x14) = puVar2;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return 1;
  }
  return 0;
}

