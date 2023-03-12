
undefined4 MakeAEPBigNum(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = param_1[1];
  if (0 < iVar4) {
    puVar1 = (undefined *)(*param_1 + 1);
    puVar2 = param_3;
    do {
      puVar3 = puVar2 + 1;
      *puVar2 = CONCAT22(CONCAT11(puVar1[2],puVar1[1]),CONCAT11(*puVar1,puVar1[-1]));
      puVar1 = puVar1 + 4;
      puVar2 = puVar3;
    } while (puVar3 != param_3 + iVar4);
  }
  return 0;
}

