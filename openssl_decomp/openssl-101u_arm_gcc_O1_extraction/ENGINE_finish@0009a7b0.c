
int ENGINE_finish(ENGINE *e)

{
  int iVar1;
  int iVar2;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x6b,0x43,"eng_init.c",0x92);
    return 0;
  }
  CRYPTO_lock(9,0x1e,"eng_init.c",0x95);
  iVar2 = *(int *)(e + 0x5c);
  *(int *)(e + 0x5c) = iVar2 + -1;
  if ((iVar2 + -1 == 0) && (*(int *)(e + 0x3c) != 0)) {
    CRYPTO_lock(10,0x1e,"eng_init.c",0x69);
    iVar2 = (**(code **)(e + 0x3c))(e);
    CRYPTO_lock(9,0x1e,"eng_init.c",0x6c);
    if (iVar2 == 0) goto LAB_0009a842;
    iVar1 = engine_free_util(e,0);
  }
  else {
    iVar2 = 1;
    iVar1 = engine_free_util(e,0);
  }
  if (iVar1 != 0) {
    CRYPTO_lock(10,0x1e,"eng_init.c",0x97);
    return iVar2;
  }
  ERR_put_error(0x26,0xbf,0x6a,"eng_init.c",0x78);
LAB_0009a842:
  CRYPTO_lock(10,0x1e,"eng_init.c",0x97);
  ERR_put_error(0x26,0x6b,0x6a,"eng_init.c",0x99);
  return 0;
}

