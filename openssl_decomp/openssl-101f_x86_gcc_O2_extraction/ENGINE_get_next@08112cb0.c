
ENGINE * __regparm1 ENGINE_get_next(ENGINE *e)

{
  ENGINE *pEVar1;
  ENGINE *in_stack_00000004;
  
  if (in_stack_00000004 == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x73,0x43,"eng_list.c",0xe5);
    pEVar1 = (ENGINE *)0x0;
  }
  else {
    CRYPTO_lock((int)e,9,(char *)0x1e,(int)"eng_list.c");
    pEVar1 = *(ENGINE **)(in_stack_00000004 + 0x6c);
    if (pEVar1 != (ENGINE *)0x0) {
      *(int *)(pEVar1 + 0x58) = *(int *)(pEVar1 + 0x58) + 1;
    }
    CRYPTO_lock((int)e,10,(char *)0x1e,(int)"eng_list.c");
    ENGINE_free(in_stack_00000004);
  }
  return pEVar1;
}

