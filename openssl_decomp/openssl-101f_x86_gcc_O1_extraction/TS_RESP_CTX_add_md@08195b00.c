
undefined4 TS_RESP_CTX_add_md(int param_1,void *param_2)

{
  int iVar1;
  _STACK *st;
  
  st = *(_STACK **)(param_1 + 0x14);
  if (st == (_STACK *)0x0) {
    st = sk_new_null();
    *(_STACK **)(param_1 + 0x14) = st;
    if (st == (_STACK *)0x0) goto LAB_08195b23;
  }
  iVar1 = sk_push(st,param_2);
  if (iVar1 != 0) {
    return 1;
  }
LAB_08195b23:
  ERR_put_error(0x2f,0x7d,0x41,"ts_rsp_sign.c",0x11d);
  return 0;
}
