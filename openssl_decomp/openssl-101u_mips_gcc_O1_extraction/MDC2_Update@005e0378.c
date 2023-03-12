
undefined4 MDC2_Update(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    uVar2 = 8 - iVar1;
    if (param_3 < uVar2) {
      (*(code *)PTR_memcpy_006a9aec)((int)param_1 + iVar1 + 4);
      *param_1 = *param_1 + param_3;
      return 1;
    }
    (*(code *)PTR_memcpy_006a9aec)((int)param_1 + iVar1 + 4,param_2,uVar2);
    *param_1 = 0;
    mdc2_body(param_1,param_1 + 1,8);
    param_3 = param_3 - uVar2;
    param_2 = param_2 + uVar2;
  }
  uVar2 = param_3 & 0xfffffff8;
  if (uVar2 != 0) {
    mdc2_body(param_1,param_2,uVar2);
  }
  iVar1 = param_3 - uVar2;
  if (iVar1 == 0) {
    return 1;
  }
  (*(code *)PTR_memcpy_006a9aec)(param_1 + 1,param_2 + uVar2,iVar1);
  *param_1 = iVar1;
  return 1;
}

