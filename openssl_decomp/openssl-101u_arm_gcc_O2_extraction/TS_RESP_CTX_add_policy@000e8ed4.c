
undefined4 TS_RESP_CTX_add_policy(int param_1,ASN1_OBJECT *param_2)

{
  ASN1_OBJECT *a;
  int iVar1;
  _STACK *p_Var2;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    p_Var2 = sk_new_null();
    *(_STACK **)(param_1 + 0xc) = p_Var2;
    if (p_Var2 != (_STACK *)0x0) goto LAB_000e8ede;
  }
  else {
LAB_000e8ede:
    a = OBJ_dup(param_2);
    if (a != (ASN1_OBJECT *)0x0) {
      iVar1 = sk_push(*(_STACK **)(param_1 + 0xc),a);
      if (iVar1 != 0) {
        return 1;
      }
      goto LAB_000e8ef2;
    }
  }
  a = (ASN1_OBJECT *)0x0;
LAB_000e8ef2:
  ERR_put_error(0x2f,0x7e,0x41,"ts_rsp_sign.c",0x113);
  ASN1_OBJECT_free(a);
  return 0;
}
