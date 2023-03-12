
int ENGINE_load_ssl_client_cert
              (ENGINE *e,SSL *s,stack_st_X509_NAME *ca_dn,X509 **pcert,EVP_PKEY **ppkey,
              stack_st_X509 **pother,UI_METHOD *ui_method,void *callback_data)

{
  int iVar1;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0xc2,0x43,"eng_pkey.c",0xb0);
    return 0;
  }
  CRYPTO_lock((int)ppkey,9,(char *)0x1e,(int)"eng_pkey.c");
  if (*(int *)(e + 0x5c) == 0) {
    CRYPTO_lock(0,10,(char *)0x1e,(int)"eng_pkey.c");
    ERR_put_error(0x26,0xc2,0x75,"eng_pkey.c",0xb8);
  }
  else {
    CRYPTO_lock(*(int *)(e + 0x5c),10,(char *)0x1e,(int)"eng_pkey.c");
    if (*(code **)(e + 0x4c) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0811432e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(e + 0x4c))();
      return iVar1;
    }
    ERR_put_error(0x26,0xc2,0x7d,"eng_pkey.c",0xbf);
  }
  return 0;
}

