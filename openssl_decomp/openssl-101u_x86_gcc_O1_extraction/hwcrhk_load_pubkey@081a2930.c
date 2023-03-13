
EVP_PKEY *
hwcrhk_load_pubkey(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  rsa_st *r;
  EVP_PKEY *pkey;
  rsa_st *mode;
  
  pkey = (EVP_PKEY *)hwcrhk_load_privkey(param_1,param_2,param_3,param_4);
  if (pkey == (EVP_PKEY *)0x0) {
    return (EVP_PKEY *)0x0;
  }
  if (pkey->type != 6) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x6a,0x67,"e_chil.c",0x37c);
    EVP_PKEY_free(pkey);
    return (EVP_PKEY *)0x0;
  }
  CRYPTO_lock((int)pkey,9,(char *)0xa,(int)"e_chil.c");
  r = (pkey->pkey).rsa;
  mode = RSA_new();
  (pkey->pkey).rsa = mode;
  mode->n = r->n;
  mode->e = r->e;
  r->n = (BIGNUM *)0x0;
  r->e = (BIGNUM *)0x0;
  CRYPTO_lock((int)mode,10,(char *)0xa,(int)"e_chil.c");
  RSA_free(r);
  return pkey;
}

