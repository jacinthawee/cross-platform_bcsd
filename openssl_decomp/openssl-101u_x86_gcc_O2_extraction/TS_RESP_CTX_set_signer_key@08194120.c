
undefined4 TS_RESP_CTX_set_signer_key(int param_1,int param_2)

{
  if (*(EVP_PKEY **)(param_1 + 4) != (EVP_PKEY *)0x0) {
    EVP_PKEY_free(*(EVP_PKEY **)(param_1 + 4));
  }
  *(int *)(param_1 + 4) = param_2;
  CRYPTO_add_lock((int *)(param_2 + 8),1,10,"ts_rsp_sign.c",0xde);
  return 1;
}

