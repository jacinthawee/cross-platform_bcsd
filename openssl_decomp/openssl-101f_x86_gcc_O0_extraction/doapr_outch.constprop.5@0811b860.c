
void __regparm3
doapr_outch_constprop_5(void **param_1_00,void **param_2,uint *param_3,uint *param_1)

{
  void *pvVar1;
  uint num;
  uint __n;
  
  __n = *param_3;
  if (param_2 == (void **)0x0) {
    if (*param_1 <= __n) {
      return;
    }
  }
  else {
    while (num = *param_1, num <= __n) {
      while (pvVar1 = *param_2, pvVar1 != (void *)0x0) {
        *param_1 = num + 0x400;
        pvVar1 = CRYPTO_realloc(pvVar1,num + 0x400,"b_print.c",0x2ed);
        __n = *param_3;
        *param_2 = pvVar1;
        num = *param_1;
        if (__n < num) goto LAB_0811b8ae;
      }
      if (num == 0) {
        *param_1 = 0x400;
        num = 0x400;
      }
      pvVar1 = CRYPTO_malloc(num,"b_print.c",0x2e5);
      __n = *param_3;
      *param_2 = pvVar1;
      if (__n != 0) {
        memcpy(pvVar1,*param_1_00,__n);
        __n = *param_3;
      }
      *param_1_00 = (void *)0x0;
    }
  }
LAB_0811b8ae:
  pvVar1 = *param_1_00;
  if (pvVar1 == (void *)0x0) {
    pvVar1 = *param_2;
  }
  *param_3 = __n + 1;
  *(undefined *)((int)pvVar1 + __n) = 0x20;
  return;
}

