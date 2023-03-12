
ENGINE * ENGINE_get_prev(ENGINE *e)

{
  ENGINE *pEVar1;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x74,0x43,"eng_list.c",0xfc);
  }
  else {
    CRYPTO_lock(9,0x1e,"eng_list.c",0xff);
    pEVar1 = *(ENGINE **)(e + 0x68);
    if (pEVar1 != (ENGINE *)0x0) {
      *(int *)(pEVar1 + 0x58) = *(int *)(pEVar1 + 0x58) + 1;
    }
    CRYPTO_lock(10,0x1e,"eng_list.c",0x107);
    ENGINE_free(e);
    e = pEVar1;
  }
  return e;
}

