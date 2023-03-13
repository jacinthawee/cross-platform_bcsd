
int __regparm3
general_allocate_boolean_constprop_5
          (int param_1_00,int param_2_00,int param_3_00,char *param_1,char *param_2,int param_3,
          int param_4,int param_5)

{
  char cVar1;
  char *pcVar2;
  int *ptr;
  int iVar3;
  _STACK *st;
  char *pcVar4;
  
  if (param_1 == (char *)0x0) {
    iVar3 = 0xc4;
  }
  else {
    if (param_2 != (char *)0x0) {
      cVar1 = *param_1;
      pcVar4 = param_1;
      while (cVar1 != '\0') {
        while (pcVar2 = strchr(param_2,(int)cVar1), pcVar2 != (char *)0x0) {
          pcVar4 = pcVar4 + 1;
          ERR_put_error(0x28,0x6c,0x68,"ui_lib.c",0xcb);
          cVar1 = *pcVar4;
          if (cVar1 == '\0') goto LAB_08187d3a;
        }
        pcVar4 = pcVar4 + 1;
        cVar1 = *pcVar4;
      }
LAB_08187d3a:
      if (param_2_00 == 0) {
        ERR_put_error(0x28,0x6d,0x43,"ui_lib.c",0x8f);
        return -1;
      }
      if (param_5 != 0) {
        ptr = (int *)CRYPTO_malloc(0x20,"ui_lib.c",0x93);
        if (ptr == (int *)0x0) {
          return -1;
        }
        ptr[1] = param_2_00;
        *ptr = 3;
        ptr[7] = (uint)(param_3 != 0);
        ptr[2] = param_4;
        ptr[3] = param_5;
        st = *(_STACK **)(param_1_00 + 4);
        if (st == (_STACK *)0x0) {
          st = sk_new_null();
          *(_STACK **)(param_1_00 + 4) = st;
          if (st == (_STACK *)0x0) {
            if (((*(byte *)(ptr + 7) & 1) != 0) && (CRYPTO_free((void *)ptr[1]), *ptr == 3)) {
              CRYPTO_free((void *)ptr[4]);
              CRYPTO_free((void *)ptr[5]);
              CRYPTO_free((void *)ptr[6]);
            }
            CRYPTO_free(ptr);
            return -1;
          }
        }
        ptr[5] = (int)param_1;
        ptr[6] = (int)param_2;
        ptr[4] = param_3_00;
        iVar3 = sk_push(st,ptr);
        return iVar3 - (uint)(iVar3 < 1);
      }
      ERR_put_error(0x28,0x6d,0x69,"ui_lib.c",0x92);
      return -1;
    }
    iVar3 = 0xc6;
  }
  ERR_put_error(0x28,0x6c,0x43,"ui_lib.c",iVar3);
  return -1;
}

