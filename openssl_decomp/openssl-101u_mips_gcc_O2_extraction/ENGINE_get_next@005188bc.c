
ENGINE * ENGINE_get_next(ENGINE *e)

{
  ENGINE *pEVar1;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x73,0x43,"eng_list.c",0xd9);
    pEVar1 = (ENGINE *)0x0;
  }
  else {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_list.c",0xdc);
    pEVar1 = *(ENGINE **)(e + 0x6c);
    if (pEVar1 != (ENGINE *)0x0) {
      *(int *)(pEVar1 + 0x58) = *(int *)(pEVar1 + 0x58) + 1;
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_list.c",0xe3);
    ENGINE_free(e);
  }
  return pEVar1;
}

