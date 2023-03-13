
undefined4 MDC2_Update(size_t *param_1,void *param_2,uint param_3)

{
  void *__dest;
  size_t sVar1;
  void *pvVar2;
  uint uVar3;
  
  sVar1 = *param_1;
  pvVar2 = param_2;
  if (sVar1 != 0) {
    uVar3 = 8 - sVar1;
    __dest = (void *)((int)param_1 + sVar1 + 4);
    if (param_3 < uVar3) {
      memcpy(__dest,param_2,param_3);
      *param_1 = *param_1 + param_3;
      return 1;
    }
    param_3 = param_3 - uVar3;
    pvVar2 = (void *)((int)param_2 + uVar3);
    memcpy(__dest,param_2,uVar3);
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

