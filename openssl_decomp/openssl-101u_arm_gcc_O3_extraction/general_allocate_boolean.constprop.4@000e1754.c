
int general_allocate_boolean_constprop_4
              (int param_1,int param_2,int param_3,byte *param_4,char *param_5,int param_6,
              int param_7,int param_8)

{
  byte bVar1;
  char *pcVar2;
  int *ptr;
  _STACK *st;
  int iVar3;
  uint __c;
  byte *pbVar4;
  
  if (param_4 == (byte *)0x0) {
    iVar3 = 0xc4;
  }
  else {
    if (param_5 != (char *)0x0) {
      bVar1 = *param_4;
      pbVar4 = param_4;
      while (__c = (uint)bVar1, __c != 0) {
        while (pcVar2 = strchr(param_5,__c), pcVar2 == (char *)0x0) {
          pbVar4 = pbVar4 + 1;
          __c = (uint)*pbVar4;
          if (__c == 0) goto LAB_000e17aa;
        }
        ERR_put_error(0x28,0x6c,0x68,"ui_lib.c",0xcb);
        pbVar4 = pbVar4 + 1;
        bVar1 = *pbVar4;
      }
LAB_000e17aa:
      if (param_2 == 0) {
        ERR_put_error(0x28,0x6d,0x43,"ui_lib.c",0x8f);
        return -1;
      }
      if (param_8 == 0) {
        ERR_put_error(0x28,0x6d,0x69,"ui_lib.c",0x92);
        return -1;
      }
      ptr = (int *)CRYPTO_malloc(0x20,"ui_lib.c",0x93);
      if (ptr == (int *)0x0) {
        return -1;
      }
      ptr[1] = param_2;
      ptr[3] = param_8;
      st = *(_STACK **)(param_1 + 4);
      if (param_6 != 0) {
        param_6 = 1;
      }
      *ptr = 3;
      ptr[7] = param_6;
      ptr[2] = param_7;
      if (st == (_STACK *)0x0) {
        st = sk_new_null();
        *(_STACK **)(param_1 + 4) = st;
        if (st == (_STACK *)0x0) {
          if ((ptr[7] << 0x1f < 0) && (CRYPTO_free((void *)ptr[1]), *ptr == 3)) {
            CRYPTO_free((void *)ptr[4]);
            CRYPTO_free((void *)ptr[5]);
            CRYPTO_free((void *)ptr[6]);
          }
          CRYPTO_free(ptr);
          return -1;
        }
      }
      ptr[4] = param_3;
      ptr[5] = (int)param_4;
      ptr[6] = (int)param_5;
      iVar3 = sk_push(st,ptr);
      if (0 < iVar3) {
        return iVar3;
      }
      return iVar3 + -1;
    }
    iVar3 = 0xc6;
  }
  ERR_put_error(0x28,0x6c,0x43,"ui_lib.c",iVar3);
  return -1;
}

