
EVP_PKEY * hwcrhk_load_pubkey(void)

{
  EVP_PKEY *pkey;
  rsa_st *prVar1;
  rsa_st *r;
  BIGNUM *pBVar2;
  
  pkey = (EVP_PKEY *)hwcrhk_load_privkey();
  if (pkey != (EVP_PKEY *)0x0) {
    if (pkey->type == 6) {
      CRYPTO_lock(9,10,"e_chil.c",0x36e);
      r = (pkey->pkey).rsa;
      prVar1 = RSA_new();
      (pkey->pkey).rsa = prVar1;
      pBVar2 = r->e;
      prVar1->n = r->n;
      prVar1->e = pBVar2;
      r->n = (BIGNUM *)0x0;
      r->e = (BIGNUM *)0x0;
      CRYPTO_lock(10,10,"e_chil.c",0x375);
      RSA_free(r);
      return pkey;
    }
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x6a,0x67,"e_chil.c",0x37c);
    EVP_PKEY_free(pkey);
    pkey = (EVP_PKEY *)0x0;
  }
  return pkey;
}

