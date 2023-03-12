
undefined4 MDC2_Update(size_t *param_1,void *param_2,uint param_3)

{
  size_t sVar1;
  void *pvVar2;
  size_t __n;
  uint uVar3;
  
  sVar1 = *param_1;
  pvVar2 = param_2;
  if (sVar1 != 0) {
    if (sVar1 + param_3 < 8) {
      memcpy((void *)((int)param_1 + sVar1 + 4),param_2,param_3);
      *param_1 = *param_1 + param_3;
      return 1;
    }
    __n = 8 - sVar1;
    param_3 = param_3 - __n;
    pvVar2 = (void *)((int)param_2 + __n);
    memcpy((void *)((int)param_1 + sVar1 + 4),param_2,__n);
    *param_1 = 0;
    mdc2_body();
  }
  uVar3 = param_3 & 0xfffffff8;
  if (uVar3 != 0) {
    mdc2_body();
  }
  sVar1 = param_3 - uVar3;
  if (sVar1 == 0) {
    return 1;
  }
  memcpy(param_1 + 1,(void *)(uVar3 + (int)pvVar2),sVar1);
  *param_1 = sVar1;
  return 1;
}

