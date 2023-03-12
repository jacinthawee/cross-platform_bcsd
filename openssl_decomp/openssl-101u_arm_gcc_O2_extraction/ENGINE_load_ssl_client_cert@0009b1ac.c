
int ENGINE_load_ssl_client_cert
              (ENGINE *e,SSL *s,stack_st_X509_NAME *ca_dn,X509 **pcert,EVP_PKEY **ppkey,
              stack_st_X509 **pother,UI_METHOD *ui_method,void *callback_data)

{
  int iVar1;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0xc2,0x43,"eng_pkey.c",0xa8);
    return 0;
  }
  CRYPTO_lock(9,0x1e,"eng_pkey.c",0xab);
  if (*(int *)(e + 0x5c) == 0) {
    CRYPTO_lock(10,0x1e,"eng_pkey.c",0xad);
    ERR_put_error(0x26,0xc2,0x75,"eng_pkey.c",0xaf);
  }
  else {
    CRYPTO_lock(10,0x1e,"eng_pkey.c",0xb2);
    if (*(code **)(e + 0x4c) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0009b21c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(e + 0x4c))(e,s,ca_dn,pcert);
      return iVar1;
    }
    ERR_put_error(0x26,0xc2,0x7d,"eng_pkey.c",0xb5);
  }
  return 0;
}

