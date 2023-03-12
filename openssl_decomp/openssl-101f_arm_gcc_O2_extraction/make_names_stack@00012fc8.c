
_STACK * make_names_stack(_STACK *param_1)

{
  _STACK *st;
  int iVar1;
  char *value;
  _STACK *a;
  _STACK *st_00;
  int iVar2;
  
  st = sk_new_null();
  if (st != (_STACK *)0x0) {
    iVar2 = 0;
    do {
      iVar1 = sk_num(param_1);
      if (iVar1 <= iVar2) {
        return st;
      }
      value = (char *)sk_value(param_1,iVar2);
      a = (_STACK *)
          a2i_GENERAL_NAME((GENERAL_NAME *)0x0,(X509V3_EXT_METHOD *)0x0,(X509V3_CTX *)0x0,1,value,0)
      ;
      st_00 = a;
    } while ((((a != (_STACK *)0x0) &&
              (st_00 = (_STACK *)GENERAL_NAMES_new(), st_00 != (_STACK *)0x0)) &&
             (iVar1 = sk_push(st_00,a), iVar1 != 0)) &&
            (a = (_STACK *)sk_push(st,st_00), iVar2 = iVar2 + 1, a != (_STACK *)0x0));
    sk_pop_free(st,GENERAL_NAMES_free);
    if (st_00 != (_STACK *)0x0) {
      GENERAL_NAMES_free((GENERAL_NAMES *)st_00);
    }
    st = a;
    if (a != (_STACK *)0x0) {
      GENERAL_NAME_free((GENERAL_NAME *)a);
      st = (_STACK *)0x0;
    }
  }
  return st;
}

