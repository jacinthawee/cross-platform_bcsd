
undefined4 TS_RESP_CTX_set_signer_key(int param_1,int param_2)

{
  undefined *puVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    (*(code *)PTR_EVP_PKEY_free_006a7f78)();
  }
  puVar1 = PTR_CRYPTO_add_lock_006a9080;
  *(int *)(param_1 + 4) = param_2;
  (*(code *)puVar1)(param_2 + 8,1,10,"ts_rsp_sign.c",0xdb);
  return 1;
}

