
_STACK * __regparm3 make_names_stack(_STACK *param_1)

{
  _STACK *st;
  int iVar1;
  char *value;
  GENERAL_NAME *a;
  _STACK *st_00;
  int iVar2;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    st = (_STACK *)0x0;
  }
  else {
    for (iVar2 = 0; iVar1 = sk_num(param_1), iVar2 < iVar1; iVar2 = iVar2 + 1) {
      value = (char *)sk_value(param_1,iVar2);
      a = a2i_GENERAL_NAME((GENERAL_NAME *)0x0,(X509V3_EXT_METHOD *)0x0,(X509V3_CTX *)0x0,1,value,0)
      ;
      if (a == (GENERAL_NAME *)0x0) {
        st_00 = (_STACK *)0x0;
LAB_0804b495:
        sk_pop_free(st,GENERAL_NAMES_free);
        if (st_00 != (_STACK *)0x0) {
          GENERAL_NAMES_free((GENERAL_NAMES *)st_00);
        }
        if (a == (GENERAL_NAME *)0x0) {
          return (_STACK *)0x0;
        }
        GENERAL_NAME_free(a);
        return (_STACK *)0x0;
      }
      st_00 = (_STACK *)GENERAL_NAMES_new();
      if ((st_00 == (_STACK *)0x0) || (iVar1 = sk_push(st_00,a), iVar1 == 0)) goto LAB_0804b495;
      iVar1 = sk_push(st,st_00);
      if (iVar1 == 0) {
        a = (GENERAL_NAME *)0x0;
        goto LAB_0804b495;
      }
    }
  }
  return st;
}

