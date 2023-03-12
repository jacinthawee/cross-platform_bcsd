
int ENGINE_init(ENGINE *e)

{
  int iVar1;
  int iVar2;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x77,0x43,"eng_init.c",0x7e);
    return 0;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"eng_init.c",0x81);
  iVar1 = *(int *)(e + 0x5c);
  if ((iVar1 == 0) && (*(code **)(e + 0x38) != (code *)0x0)) {
    iVar2 = (**(code **)(e + 0x38))(e);
    if (iVar2 == 0) goto LAB_0051b320;
    iVar1 = *(int *)(e + 0x5c);
  }
  else {
    iVar2 = 1;
  }
  *(int *)(e + 0x5c) = iVar1 + 1;
  *(int *)(e + 0x58) = *(int *)(e + 0x58) + 1;
LAB_0051b320:
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"eng_init.c",0x83);
  return iVar2;
}

