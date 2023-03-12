
undefined4 ConvertAEPBigNum(undefined4 *param_1,uint param_2,undefined *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = param_2 * 8 + 0x1f;
  if (iVar1 < 0) {
    iVar1 = param_2 * 8 + 0x3e;
  }
  if ((int)param_1[2] < iVar1 >> 5) {
    (*(code *)PTR_bn_expand2_006a9680)();
  }
  param_1[1] = param_2 >> 2;
  if (param_2 >> 2 != 0) {
    iVar1 = 0;
    puVar2 = (undefined4 *)*param_1;
    do {
      iVar1 = iVar1 + 1;
      *puVar2 = CONCAT22(CONCAT11(param_3[3],param_3[2]),CONCAT11(param_3[1],*param_3));
      puVar2 = puVar2 + 1;
      param_3 = param_3 + 4;
    } while (iVar1 < (int)param_1[1]);
  }
  return 0;
}

