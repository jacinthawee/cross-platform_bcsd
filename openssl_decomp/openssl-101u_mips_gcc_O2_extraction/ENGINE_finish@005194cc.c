
int ENGINE_finish(ENGINE *e)

{
  int iVar1;
  int iVar2;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x6b,0x43,"eng_init.c",0x92);
    return 0;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_init.c",0x95);
  iVar1 = *(int *)(e + 0x5c);
  *(int *)(e + 0x5c) = iVar1 + -1;
  if ((iVar1 + -1 == 0) && (*(int *)(e + 0x3c) != 0)) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_init.c",0x69);
    iVar1 = (**(code **)(e + 0x3c))(e);
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_init.c",0x6c);
    if (iVar1 == 0) goto LAB_005195e8;
    iVar2 = engine_free_util(e,0);
  }
  else {
    iVar1 = 1;
    iVar2 = engine_free_util(e,0);
  }
  if (iVar2 != 0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_init.c",0x97);
    return iVar1;
  }
  ERR_put_error(0x26,0xbf,0x6a,"eng_init.c",0x78);
LAB_005195e8:
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_init.c",0x97);
  ERR_put_error(0x26,0x6b,0x6a,"eng_init.c",0x99);
  return 0;
}

