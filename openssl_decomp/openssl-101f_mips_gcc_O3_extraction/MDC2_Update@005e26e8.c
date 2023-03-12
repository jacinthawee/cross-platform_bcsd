
undefined4 MDC2_Update(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (iVar1 + param_3 < 8) {
      (*(code *)PTR_memcpy_006aabf4)((int)param_1 + iVar1 + 4);
      *param_1 = *param_1 + param_3;
      return 1;
    }
    iVar2 = 8 - iVar1;
    (*(code *)PTR_memcpy_006aabf4)((int)param_1 + iVar1 + 4,param_2,iVar2);
    *param_1 = 0;
    mdc2_body(param_1,param_1 + 1,8);
    param_3 = param_3 - iVar2;
    param_2 = param_2 + iVar2;
  }
  uVar3 = param_3 & 0xfffffff8;
  if (uVar3 != 0) {
    mdc2_body(param_1,param_2,uVar3);
  }
  iVar1 = param_3 - uVar3;
  if (iVar1 == 0) {
    return 1;
  }
  (*(code *)PTR_memcpy_006aabf4)(param_1 + 1,param_2 + uVar3,iVar1);
  *param_1 = iVar1;
  return 1;
}

