
undefined4 doapr_outch(void **param_1,void **param_2,uint *param_3,uint *param_4,undefined param_5)

{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 == (void **)0x0) {
    uVar3 = *param_4;
    uVar2 = *param_3;
  }
  else {
    uVar2 = *param_3;
    uVar3 = *param_4;
    if (uVar2 == uVar3) {
      if (0x7ffffbff < uVar2) {
        return 0;
      }
      pvVar1 = *param_2;
      uVar2 = uVar2 + 0x400;
      *param_4 = uVar2;
      if (pvVar1 == (void *)0x0) {
        pvVar1 = CRYPTO_malloc(uVar2,"b_print.c",0x2f3);
        *param_2 = pvVar1;
        if (pvVar1 == (void *)0x0) {
          return 0;
        }
        uVar2 = *param_3;
        if (uVar2 != 0) {
          memcpy(pvVar1,*param_1,uVar2);
          uVar2 = *param_3;
        }
        uVar3 = *param_4;
        *param_1 = (void *)0x0;
      }
      else {
        pvVar1 = CRYPTO_realloc(pvVar1,uVar2,"b_print.c",0x2fd);
        if (pvVar1 == (void *)0x0) {
          return 0;
        }
        uVar3 = *param_4;
        uVar2 = *param_3;
        *param_2 = pvVar1;
      }
    }
  }
  if (uVar3 <= uVar2) {
    return 1;
  }
  pvVar1 = *param_1;
  if (pvVar1 == (void *)0x0) {
    pvVar1 = *param_2;
  }
  *param_3 = uVar2 + 1;
  *(undefined *)((int)pvVar1 + uVar2) = param_5;
  return 1;
}

