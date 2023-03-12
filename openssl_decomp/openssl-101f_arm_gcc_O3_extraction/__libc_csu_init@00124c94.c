
void __libc_csu_init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  code **ppcVar3;
  int iVar4;
  
  iVar1 = DAT_00124ccc;
  iVar4 = DAT_00124cc8 + 0x124ca6;
  _init();
  iVar4 = iVar4 - (int)(code **)(iVar1 + 0x124cac) >> 2;
  if (iVar4 != 0) {
    iVar2 = 0;
    ppcVar3 = (code **)(iVar1 + 0x124cac);
    do {
      iVar2 = iVar2 + 1;
      (**ppcVar3)(param_1,param_2,param_3,*ppcVar3,param_4);
      ppcVar3 = ppcVar3 + 1;
    } while (iVar2 != iVar4);
  }
  return;
}

