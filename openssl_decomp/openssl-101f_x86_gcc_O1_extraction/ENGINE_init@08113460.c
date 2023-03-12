
int __regparm1 ENGINE_init(ENGINE *e)

{
  int iVar1;
  int iVar2;
  int in_stack_00000004;
  
  if (in_stack_00000004 == 0) {
    ERR_put_error(0x26,0x77,0x43,"eng_init.c",0x7e);
    return 0;
  }
  CRYPTO_lock((int)e,9,(char *)0x1e,(int)"eng_init.c");
  iVar1 = *(int *)(in_stack_00000004 + 0x5c);
  if ((iVar1 == 0) && (*(code **)(in_stack_00000004 + 0x38) != (code *)0x0)) {
    iVar1 = (**(code **)(in_stack_00000004 + 0x38))();
    iVar2 = iVar1;
    if (iVar1 == 0) goto LAB_08113499;
    iVar1 = *(int *)(in_stack_00000004 + 0x5c);
  }
  else {
    iVar2 = 1;
  }
  *(int *)(in_stack_00000004 + 0x58) = *(int *)(in_stack_00000004 + 0x58) + 1;
  iVar1 = iVar1 + 1;
  *(int *)(in_stack_00000004 + 0x5c) = iVar1;
LAB_08113499:
  CRYPTO_lock(iVar1,10,(char *)0x1e,(int)"eng_init.c");
  return iVar2;
}

