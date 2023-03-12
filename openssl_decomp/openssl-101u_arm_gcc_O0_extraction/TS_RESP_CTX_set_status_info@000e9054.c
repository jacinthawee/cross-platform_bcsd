
undefined4 TS_RESP_CTX_set_status_info(int param_1,long param_2,char *param_3)

{
  ASN1_INTEGER **ppAVar1;
  int iVar2;
  size_t len;
  _STACK *st;
  undefined4 uVar3;
  ASN1_UTF8STRING *str;
  
  ppAVar1 = (ASN1_INTEGER **)TS_STATUS_INFO_new();
  if ((ppAVar1 == (ASN1_INTEGER **)0x0) || (iVar2 = ASN1_INTEGER_set(*ppAVar1,param_2), iVar2 == 0))
  {
LAB_000e9070:
    str = (ASN1_UTF8STRING *)0x0;
  }
  else {
    if (param_3 == (char *)0x0) {
LAB_000e90cc:
      iVar2 = TS_RESP_set_status_info(*(undefined4 *)(param_1 + 0x48),ppAVar1);
      uVar3 = 1;
      str = (ASN1_UTF8STRING *)0x0;
      if (iVar2 != 0) goto LAB_000e908c;
      goto LAB_000e9070;
    }
    str = ASN1_UTF8STRING_new();
    if (str == (ASN1_UTF8STRING *)0x0) goto LAB_000e9070;
    len = strlen(param_3);
    iVar2 = ASN1_STRING_set(str,param_3,len);
    if (iVar2 != 0) {
      st = (_STACK *)ppAVar1[1];
      if (st == (_STACK *)0x0) {
        st = sk_new_null();
        ppAVar1[1] = (ASN1_INTEGER *)st;
        if (st == (_STACK *)0x0) goto LAB_000e9072;
      }
      iVar2 = sk_push(st,str);
      if (iVar2 != 0) goto LAB_000e90cc;
    }
  }
LAB_000e9072:
  uVar3 = 0;
  ERR_put_error(0x2f,0x84,0x41,"ts_rsp_sign.c",0x177);
LAB_000e908c:
  TS_STATUS_INFO_free(ppAVar1);
  ASN1_UTF8STRING_free(str);
  return uVar3;
}

