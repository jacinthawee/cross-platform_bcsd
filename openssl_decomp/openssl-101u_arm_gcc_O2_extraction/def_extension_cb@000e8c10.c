
undefined4 def_extension_cb(int param_1)

{
  ASN1_INTEGER **ppAVar1;
  int iVar2;
  ASN1_BIT_STRING *a;
  _STACK *st;
  ASN1_UTF8STRING *str;
  
  ppAVar1 = (ASN1_INTEGER **)TS_STATUS_INFO_new();
  if (((ppAVar1 == (ASN1_INTEGER **)0x0) || (iVar2 = ASN1_INTEGER_set(*ppAVar1,2), iVar2 == 0)) ||
     (str = ASN1_UTF8STRING_new(), str == (ASN1_UTF8STRING *)0x0)) {
LAB_000e8c28:
    str = (ASN1_UTF8STRING *)0x0;
LAB_000e8c2a:
    ERR_put_error(0x2f,0x84,0x41,"ts_rsp_sign.c",0x177);
  }
  else {
    iVar2 = ASN1_STRING_set(str,"Unsupported extension.",0x16);
    if (iVar2 == 0) goto LAB_000e8c2a;
    st = (_STACK *)ppAVar1[1];
    if (st == (_STACK *)0x0) {
      st = sk_new_null();
      ppAVar1[1] = (ASN1_INTEGER *)st;
      if (st == (_STACK *)0x0) goto LAB_000e8c2a;
    }
    iVar2 = sk_push(st,str);
    if (iVar2 == 0) goto LAB_000e8c2a;
    iVar2 = TS_RESP_set_status_info(*(undefined4 *)(param_1 + 0x48),ppAVar1);
    if (iVar2 == 0) goto LAB_000e8c28;
    str = (ASN1_UTF8STRING *)0x0;
  }
  TS_STATUS_INFO_free(ppAVar1);
  ASN1_UTF8STRING_free(str);
  iVar2 = TS_RESP_get_status_info(*(undefined4 *)(param_1 + 0x48));
  a = *(ASN1_BIT_STRING **)(iVar2 + 8);
  if (a == (ASN1_BIT_STRING *)0x0) {
    a = ASN1_BIT_STRING_new();
    *(ASN1_BIT_STRING **)(iVar2 + 8) = a;
    if (a == (ASN1_BIT_STRING *)0x0) goto LAB_000e8c64;
  }
  iVar2 = ASN1_BIT_STRING_set_bit(a,0x10,1);
  if (iVar2 != 0) {
    return 0;
  }
LAB_000e8c64:
  ERR_put_error(0x2f,0x7c,0x41,"ts_rsp_sign.c",0x193);
  return 0;
}

