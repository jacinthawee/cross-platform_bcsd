
void ssl2_clear(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = param_1[0x15];
  uVar2 = *(undefined4 *)(iVar1 + 0x30);
  uVar3 = *(undefined4 *)(iVar1 + 0x34);
  (*(code *)PTR_memset_006aab00)(iVar1,0,0x120,param_4,&_gp);
  *(undefined4 *)(iVar1 + 0x30) = uVar2;
  *(undefined4 *)(iVar1 + 4) = 1;
  *(undefined4 *)(iVar1 + 0x34) = uVar3;
  param_1[0x13] = uVar2;
  *param_1 = 2;
  param_1[0x14] = 0;
  return;
}

