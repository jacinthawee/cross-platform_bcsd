
undefined4 MakeAEPBigNum(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1[1];
  if (0 < iVar1) {
    iVar2 = *param_1;
    iVar3 = 0;
    do {
      *(undefined4 *)(param_3 + iVar3 * 4) = *(undefined4 *)(iVar2 + iVar3 * 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 != iVar1);
  }
  return 0;
}

