
_STACK * v2i_EXTENDED_KEY_USAGE(undefined4 param_1,undefined4 param_2,_STACK *param_3)

{
  _STACK *st;
  ASN1_OBJECT *data;
  int iVar1;
  undefined4 *puVar2;
  char *s;
  int iVar3;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x67,0x41,"v3_extku.c",0x7f);
    st = (_STACK *)0x0;
  }
  else {
    for (iVar3 = 0; iVar1 = sk_num(param_3), iVar3 < iVar1; iVar3 = iVar3 + 1) {
      puVar2 = (undefined4 *)sk_value(param_3,iVar3);
      s = (char *)puVar2[2];
      if (s == (char *)0x0) {
        s = (char *)puVar2[1];
      }
      data = OBJ_txt2obj(s,0);
      if (data == (ASN1_OBJECT *)0x0) {
        sk_pop_free(st,ASN1_OBJECT_free);
        ERR_put_error(0x22,0x67,0x6e,"v3_extku.c",0x89);
        ERR_add_error_data(6,"section:",*puVar2,",name:",puVar2[1],",value:",puVar2[2]);
        return (_STACK *)0x0;
      }
      sk_push(st,data);
    }
  }
  return st;
}

