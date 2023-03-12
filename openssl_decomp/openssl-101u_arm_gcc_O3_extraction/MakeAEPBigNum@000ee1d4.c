
undefined4 MakeAEPBigNum(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = param_1[1];
  if (0 < iVar4) {
    puVar1 = param_3;
    puVar3 = (undefined4 *)*param_1;
    do {
      puVar2 = puVar1 + 1;
      *puVar1 = *puVar3;
      puVar1 = puVar2;
      puVar3 = puVar3 + 1;
    } while (puVar2 != param_3 + iVar4);
  }
  return 0;
}

