
int engine_unlocked_finish(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x5c) + -1;
  *(int *)(param_1 + 0x5c) = iVar2;
  if ((iVar2 == 0) && (*(code **)(param_1 + 0x3c) != (code *)0x0)) {
    if (param_2 == 0) {
      iVar2 = (**(code **)(param_1 + 0x3c))();
    }
    else {
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_init.c",0x69);
      iVar2 = (**(code **)(param_1 + 0x3c))(param_1);
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_init.c",0x6c);
    }
    if (iVar2 == 0) {
      return 0;
    }
    iVar1 = engine_free_util(param_1,0);
  }
  else {
    iVar2 = 1;
    iVar1 = engine_free_util(param_1,0);
  }
  if (iVar1 != 0) {
    return iVar2;
  }
  ERR_put_error(0x26,0xbf,0x6a,"eng_init.c",0x78);
  return 0;
}

