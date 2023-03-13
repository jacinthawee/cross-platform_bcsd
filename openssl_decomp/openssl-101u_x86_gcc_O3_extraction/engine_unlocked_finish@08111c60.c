
int engine_unlocked_finish(int param_1,int param_2)

{
  code *mode;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(param_1 + 0x5c) + -1;
  *(int *)(param_1 + 0x5c) = iVar1;
  if ((iVar1 == 0) && (mode = *(code **)(param_1 + 0x3c), mode != (code *)0x0)) {
    if (param_2 == 0) {
      iVar1 = (*mode)(param_1);
    }
    else {
      uVar5 = 0x69;
      pcVar4 = "eng_init.c";
      uVar3 = 0x1e;
      CRYPTO_lock((int)mode,10,(char *)0x1e,(int)"eng_init.c");
      iVar1 = (**(code **)(param_1 + 0x3c))(param_1,uVar3,pcVar4,uVar5);
      CRYPTO_lock(iVar1,9,(char *)0x1e,(int)"eng_init.c");
    }
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    iVar1 = 1;
  }
  iVar2 = engine_free_util(param_1,0);
  if (iVar2 != 0) {
    return iVar1;
  }
  ERR_put_error(0x26,0xbf,0x6a,"eng_init.c",0x78);
  return 0;
}

