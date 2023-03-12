
undefined4 TS_RESP_CTX_set_status_info_cond(int param_1,long param_2,char *param_3)

{
  ASN1_INTEGER **ppAVar1;
  long lVar2;
  int iVar3;
  size_t len;
  _STACK *st;
  undefined4 uVar4;
  ASN1_UTF8STRING *str;
  
  ppAVar1 = (ASN1_INTEGER **)TS_RESP_get_status_info(*(undefined4 *)(param_1 + 0x48));
  lVar2 = ASN1_INTEGER_get(*ppAVar1);
  if (lVar2 != 0) {
    return 1;
  }
  ppAVar1 = (ASN1_INTEGER **)TS_STATUS_INFO_new();
  if ((ppAVar1 == (ASN1_INTEGER **)0x0) || (iVar3 = ASN1_INTEGER_set(*ppAVar1,param_2), iVar3 == 0))
  {
LAB_08195ff8:
    str = (ASN1_UTF8STRING *)0x0;
  }
  else {
    if (param_3 == (char *)0x0) {
LAB_08196090:
      iVar3 = TS_RESP_set_status_info(*(undefined4 *)(param_1 + 0x48),ppAVar1);
      if (iVar3 != 0) {
        str = (ASN1_UTF8STRING *)0x0;
        uVar4 = 1;
        goto LAB_0819601a;
      }
      goto LAB_08195ff8;
    }
    str = ASN1_UTF8STRING_new();
    if (str == (ASN1_UTF8STRING *)0x0) goto LAB_08195ff8;
    len = strlen(param_3);
    iVar3 = ASN1_STRING_set(str,param_3,len);
    if (iVar3 != 0) {
      st = (_STACK *)ppAVar1[1];
      if (st == (_STACK *)0x0) {
        st = sk_new_null();
        ppAVar1[1] = (ASN1_INTEGER *)st;
        if (st == (_STACK *)0x0) goto LAB_08195ffa;
      }
      iVar3 = sk_push(st,str);
      if (iVar3 != 0) goto LAB_08196090;
    }
  }
LAB_08195ffa:
  uVar4 = 0;
  ERR_put_error(0x2f,0x84,0x41,"ts_rsp_sign.c",0x16e);
LAB_0819601a:
  TS_STATUS_INFO_free(ppAVar1);
  ASN1_UTF8STRING_free(str);
  return uVar4;
}

