
int ENGINE_up_ref(ENGINE *e)

{
  if (e != (ENGINE *)0x0) {
    (*(code *)PTR_CRYPTO_add_lock_006a805c)(e + 0x58,1,0x1e,"eng_list.c",0x193);
    return 1;
  }
  ERR_put_error(0x26,0xbe,0x43,"eng_list.c",400);
  return 0;
}

