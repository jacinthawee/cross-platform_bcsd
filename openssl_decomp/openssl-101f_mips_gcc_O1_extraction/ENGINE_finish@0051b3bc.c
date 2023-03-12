
int ENGINE_finish(ENGINE *e)

{
  int iVar1;
  int iVar2;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x6b,0x43,"eng_init.c",0x8e);
    return 0;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"eng_init.c",0x91);
  iVar1 = *(int *)(e + 0x5c);
  *(int *)(e + 0x5c) = iVar1 + -1;
  if ((iVar1 + -1 == 0) && (*(int *)(e + 0x3c) != 0)) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"eng_init.c",0x61);
    iVar1 = (**(code **)(e + 0x3c))(e);
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"eng_init.c",100);
    if (iVar1 == 0) goto LAB_0051b4d8;
    iVar2 = engine_free_util(e,0);
  }
  else {
    iVar1 = 1;
    iVar2 = engine_free_util(e,0);
  }
  if (iVar2 != 0) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"eng_init.c",0x93);
    return iVar1;
  }
  ERR_put_error(0x26,0xbf,0x6a,"eng_init.c",0x72);
LAB_0051b4d8:
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"eng_init.c",0x93);
  ERR_put_error(0x26,0x6b,0x6a,"eng_init.c",0x96);
  return 0;
}

