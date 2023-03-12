
EVP_PKEY * ENGINE_load_public_key(ENGINE *e,char *key_id,UI_METHOD *ui_method,void *callback_data)

{
  EVP_PKEY *pEVar1;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x97,0x43,"eng_pkey.c",0x89);
  }
  else {
    CRYPTO_lock(9,0x1e,"eng_pkey.c",0x8c);
    pEVar1 = *(EVP_PKEY **)(e + 0x5c);
    if (pEVar1 == (EVP_PKEY *)0x0) {
      CRYPTO_lock(10,0x1e,"eng_pkey.c",0x8e);
      ERR_put_error(0x26,0x97,0x75,"eng_pkey.c",0x8f);
      e = (ENGINE *)pEVar1;
    }
    else {
      CRYPTO_lock(10,0x1e,"eng_pkey.c",0x92);
      pEVar1 = *(EVP_PKEY **)(e + 0x48);
      if (pEVar1 == (EVP_PKEY *)0x0) {
        ERR_put_error(0x26,0x97,0x7d,"eng_pkey.c",0x94);
        e = (ENGINE *)pEVar1;
      }
      else {
        e = (ENGINE *)(*(code *)pEVar1)(e,key_id,ui_method,callback_data);
        if ((EVP_PKEY *)e == (EVP_PKEY *)0x0) {
          ERR_put_error(0x26,0x97,0x81,"eng_pkey.c",0x9a);
        }
      }
    }
  }
  return (EVP_PKEY *)e;
}

