
int ASN1_STRING_TABLE_add(int param_1,long param_2,long param_3,ulong param_4,ulong param_5)

{
  bool bVar1;
  _STACK *data;
  int iVar2;
  int local_3c [6];
  
  if (stable == (_STACK *)0x0) {
    data = sk_new(sk_table_cmp + 1);
    stable = data;
    if (data == (_STACK *)0x0) {
      iVar2 = 0xf2;
      goto LAB_000c0260;
    }
  }
  local_3c[0] = param_1;
  data = (_STACK *)OBJ_bsearch_(local_3c,&tbl_standard,0x13,0x14,table_cmp_BSEARCH_CMP_FN + 1);
  if ((data == (_STACK *)0x0) &&
     (((stable == (_STACK *)0x0 || (iVar2 = sk_find(stable,local_3c), iVar2 < 0)) ||
      (data = (_STACK *)sk_value(stable,iVar2), data == (_STACK *)0x0)))) {
    data = (_STACK *)CRYPTO_malloc(0x14,"a_strnid.c",0xf6);
    if (data == (_STACK *)0x0) {
      iVar2 = 0xf8;
LAB_000c0260:
      ERR_put_error(0xd,0x81,0x41,"a_strnid.c",iVar2);
      return (int)data;
    }
    data->num = param_1;
    data->comp = (_func_257 *)(param_5 & 0xfffffffe | 1);
    bVar1 = true;
  }
  else {
    bVar1 = false;
    data->comp = (_func_257 *)(param_5 & 0xfffffffe | (uint)data->comp & 1);
  }
  data->num_alloc = param_4;
  if (param_2 != -1) {
    data->data = (char **)param_2;
  }
  if (param_3 != -1) {
    data->sorted = param_3;
  }
  if (bVar1) {
    sk_push(stable,data);
  }
  return 1;
}

