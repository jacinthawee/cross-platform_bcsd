
undefined4 TS_RESP_CTX_add_failure_info(int param_1,int param_2)

{
  int iVar1;
  ASN1_BIT_STRING *a;
  
  iVar1 = TS_RESP_get_status_info(*(undefined4 *)(param_1 + 0x48));
  a = *(ASN1_BIT_STRING **)(iVar1 + 8);
  if (a == (ASN1_BIT_STRING *)0x0) {
    a = ASN1_BIT_STRING_new();
    *(ASN1_BIT_STRING **)(iVar1 + 8) = a;
    if (a == (ASN1_BIT_STRING *)0x0) goto LAB_000e9204;
  }
  iVar1 = ASN1_BIT_STRING_set_bit(a,param_2,1);
  if (iVar1 != 0) {
    return 1;
  }
LAB_000e9204:
  ERR_put_error(0x2f,0x7c,0x41,"ts_rsp_sign.c",0x193);
  return 0;
}

