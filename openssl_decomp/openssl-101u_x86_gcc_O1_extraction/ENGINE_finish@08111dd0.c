
int __regparm1 ENGINE_finish(ENGINE *e)

{
  int iVar1;
  int iVar2;
  int in_stack_00000004;
  
  if (in_stack_00000004 == 0) {
    iVar2 = 0x92;
    iVar1 = 0x43;
    goto LAB_08111eb4;
  }
  CRYPTO_lock((int)e,9,(char *)0x1e,(int)"eng_init.c");
  iVar1 = *(int *)(in_stack_00000004 + 0x5c) + -1;
  *(int *)(in_stack_00000004 + 0x5c) = iVar1;
  if ((iVar1 == 0) && (*(int *)(in_stack_00000004 + 0x3c) != 0)) {
    CRYPTO_lock(*(int *)(in_stack_00000004 + 0x3c),10,(char *)0x1e,(int)"eng_init.c");
    iVar1 = (**(code **)(in_stack_00000004 + 0x3c))();
    iVar2 = iVar1;
    CRYPTO_lock(iVar1,9,(char *)0x1e,(int)"eng_init.c");
    if (iVar1 != 0) goto LAB_08111e42;
  }
  else {
    iVar1 = 1;
LAB_08111e42:
    iVar2 = engine_free_util();
    if (iVar2 != 0) {
      CRYPTO_lock(iVar2,10,(char *)0x1e,(int)"eng_init.c");
      return iVar1;
    }
    ERR_put_error(0x26,0xbf,0x6a,"eng_init.c",0x78);
  }
  CRYPTO_lock(iVar2,10,(char *)0x1e,(int)"eng_init.c");
  iVar2 = 0x99;
  iVar1 = 0x6a;
LAB_08111eb4:
  ERR_put_error(0x26,0x6b,iVar1,"eng_init.c",iVar2);
  return 0;
}

