
undefined4 __regparm3
doapr_outch(void **param_1_00,void **param_2_00,uint *param_3,uint *param_1,undefined param_2)

{
  void *pvVar1;
  size_t __n;
  uint uVar2;
  
  __n = *param_3;
  uVar2 = *param_1;
  if ((param_2_00 != (void **)0x0) && (__n == uVar2)) {
    if (0x7ffffbff < __n) {
      return 0;
    }
    pvVar1 = *param_2_00;
    uVar2 = __n + 0x400;
    *param_1 = uVar2;
    if (pvVar1 == (void *)0x0) {
      pvVar1 = CRYPTO_malloc(uVar2,"b_print.c",0x2f3);
      *param_2_00 = pvVar1;
      if (pvVar1 == (void *)0x0) {
        return 0;
      }
      __n = *param_3;
      if (__n != 0) {
        memcpy(pvVar1,*param_1_00,__n);
        __n = *param_3;
      }
      uVar2 = *param_1;
      *param_1_00 = (void *)0x0;
      if (uVar2 <= __n) {
        return 1;
      }
      goto LAB_0811a1c0;
    }
    pvVar1 = CRYPTO_realloc(pvVar1,uVar2,"b_print.c",0x2fd);
    if (pvVar1 == (void *)0x0) {
      return 0;
    }
    *param_2_00 = pvVar1;
    __n = *param_3;
    uVar2 = *param_1;
  }
  if (uVar2 <= __n) {
    return 1;
  }
  pvVar1 = *param_1_00;
  if (pvVar1 != (void *)0x0) {
    *param_3 = __n + 1;
    *(undefined *)((int)pvVar1 + __n) = param_2;
    return 1;
  }
LAB_0811a1c0:
  pvVar1 = *param_2_00;
  *param_3 = __n + 1;
  *(undefined *)((int)pvVar1 + __n) = param_2;
  return 1;
}

