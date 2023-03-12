
EVP_PKEY * ENGINE_load_public_key(ENGINE *e,char *key_id,UI_METHOD *ui_method,void *callback_data)

{
  EVP_PKEY *pEVar1;
  int line;
  int reason;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x97,0x43,"eng_pkey.c",0x89);
    return (EVP_PKEY *)0x0;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_pkey.c",0x8c);
  if (*(int *)(e + 0x5c) == 0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_pkey.c",0x8e);
    reason = 0x75;
    line = 0x8f;
  }
  else {
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_pkey.c",0x92);
    if (*(code **)(e + 0x48) != (code *)0x0) {
      pEVar1 = (EVP_PKEY *)(**(code **)(e + 0x48))(e,key_id,ui_method,callback_data);
      if (pEVar1 != (EVP_PKEY *)0x0) {
        return pEVar1;
      }
      ERR_put_error(0x26,0x97,0x81,"eng_pkey.c",0x9a);
      return (EVP_PKEY *)0x0;
    }
    reason = 0x7d;
    line = 0x94;
  }
  ERR_put_error(0x26,0x97,reason,"eng_pkey.c",line);
  return (EVP_PKEY *)0x0;
}

