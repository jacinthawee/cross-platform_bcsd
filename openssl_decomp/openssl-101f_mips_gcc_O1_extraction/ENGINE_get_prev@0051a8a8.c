
ENGINE * ENGINE_get_prev(ENGINE *e)

{
  ENGINE *pEVar1;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x74,0x43,"eng_list.c",0xfc);
    pEVar1 = (ENGINE *)0x0;
  }
  else {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"eng_list.c",0xff);
    pEVar1 = *(ENGINE **)(e + 0x68);
    if (pEVar1 != (ENGINE *)0x0) {
      *(int *)(pEVar1 + 0x58) = *(int *)(pEVar1 + 0x58) + 1;
    }
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"eng_list.c",0x107);
    ENGINE_free(e);
  }
  return pEVar1;
}

