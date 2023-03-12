
void doapr_outch(void **param_1,void **param_2,uint *param_3,uint *param_4,undefined param_5)

{
  uint num;
  uint __n;
  void *pvVar1;
  
  if (param_2 == (void **)0x0) {
    __n = *param_3;
    if (*param_4 <= __n) {
      return;
    }
  }
  else {
    __n = *param_3;
    while( true ) {
      num = *param_4;
      if (__n < num) break;
      pvVar1 = *param_2;
      if (pvVar1 == (void *)0x0) {
        if (num == 0) {
          *param_4 = 0x400;
          num = 0x400;
        }
        pvVar1 = CRYPTO_malloc(num,"b_print.c",0x2e5);
        __n = *param_3;
        *param_2 = pvVar1;
        if (__n != 0) {
          memcpy(pvVar1,*param_1,__n);
          __n = *param_3;
        }
        *param_1 = (void *)0x0;
      }
      else {
        *param_4 = num + 0x400;
        pvVar1 = CRYPTO_realloc(pvVar1,num + 0x400,"b_print.c",0x2ed);
        __n = *param_3;
        *param_2 = pvVar1;
      }
    }
  }
  pvVar1 = *param_1;
  if (pvVar1 == (void *)0x0) {
    pvVar1 = *param_2;
  }
  *param_3 = __n + 1;
  *(undefined *)((int)pvVar1 + __n) = param_5;
  return;
}

