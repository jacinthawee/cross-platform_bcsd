
EVP_PKEY * __regparm1
ENGINE_load_public_key(ENGINE *e,char *key_id,UI_METHOD *ui_method,void *callback_data)

{
  EVP_PKEY *pEVar1;
  undefined4 in_stack_00000010;
  int reason;
  int line;
  
  if (key_id == (char *)0x0) {
    line = 0x89;
    reason = 0x43;
  }
  else {
    CRYPTO_lock((int)e,9,(char *)0x1e,(int)"eng_pkey.c");
    if (*(int *)(key_id + 0x5c) == 0) {
      CRYPTO_lock(0,10,(char *)0x1e,(int)"eng_pkey.c");
      line = 0x8f;
      reason = 0x75;
    }
    else {
      CRYPTO_lock(*(int *)(key_id + 0x5c),10,(char *)0x1e,(int)"eng_pkey.c");
      if (*(code **)(key_id + 0x48) == (code *)0x0) {
        line = 0x94;
        reason = 0x7d;
      }
      else {
        pEVar1 = (EVP_PKEY *)
                 (**(code **)(key_id + 0x48))(key_id,ui_method,callback_data,in_stack_00000010);
        if (pEVar1 != (EVP_PKEY *)0x0) {
          return pEVar1;
        }
        line = 0x9a;
        reason = 0x81;
      }
    }
  }
  ERR_put_error(0x26,0x97,reason,"eng_pkey.c",line);
  return (EVP_PKEY *)0x0;
}

