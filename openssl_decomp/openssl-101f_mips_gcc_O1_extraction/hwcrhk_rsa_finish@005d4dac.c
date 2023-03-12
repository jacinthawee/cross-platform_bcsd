
undefined4 hwcrhk_rsa_finish(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)PTR_RSA_get_ex_data_006aa640)(param_1,hndidx_rsa);
  if (puVar1 != (undefined4 *)0x0) {
    (*p_hwcrhk_RSAUnloadKey)(*puVar1,0);
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar1);
    (*(code *)PTR_RSA_set_ex_data_006aa648)(param_1,hndidx_rsa,0);
  }
  return 1;
}

