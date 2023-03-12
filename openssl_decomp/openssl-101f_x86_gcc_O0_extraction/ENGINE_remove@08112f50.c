
int __regparm1 ENGINE_remove(ENGINE *e)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_stack_00000004;
  
  if (in_stack_00000004 == 0) {
    ERR_put_error(0x26,0x7b,0x43,"eng_list.c",0x12e);
    return 0;
  }
  CRYPTO_lock((int)e,9,(char *)0x1e,(int)"eng_list.c");
  iVar3 = engine_list_head;
  iVar2 = engine_list_head;
  if ((in_stack_00000004 != engine_list_head) && (engine_list_head != 0)) {
    do {
      iVar2 = *(int *)(iVar2 + 0x6c);
      if (iVar2 == 0) break;
    } while (in_stack_00000004 != iVar2);
  }
  if (iVar2 == 0) {
    iVar3 = 0;
    ERR_put_error(0x26,0x79,0x69,"eng_list.c",0xae);
    ERR_put_error(0x26,0x7b,0x6e,"eng_list.c",0x135);
  }
  else {
    iVar2 = *(int *)(in_stack_00000004 + 0x6c);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x68) = *(undefined4 *)(in_stack_00000004 + 0x68);
    }
    iVar1 = *(int *)(in_stack_00000004 + 0x68);
    if (iVar1 != 0) {
      *(int *)(iVar1 + 0x6c) = iVar2;
    }
    if (in_stack_00000004 == iVar3) {
      engine_list_head = *(int *)(in_stack_00000004 + 0x6c);
    }
    if (in_stack_00000004 == engine_list_tail) {
      engine_list_tail = iVar1;
    }
    iVar3 = 1;
    iVar2 = engine_free_util();
  }
  CRYPTO_lock(iVar2,10,(char *)0x1e,(int)"eng_list.c");
  return iVar3;
}

