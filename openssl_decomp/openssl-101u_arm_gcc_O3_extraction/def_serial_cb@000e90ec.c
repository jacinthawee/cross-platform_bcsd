
ASN1_INTEGER * def_serial_cb(undefined4 param_1)

{
  ASN1_INTEGER *a;
  int iVar1;
  
  a = ASN1_INTEGER_new();
  if ((a != (ASN1_INTEGER *)0x0) && (iVar1 = ASN1_INTEGER_set(a,1), iVar1 != 0)) {
    return a;
  }
  ERR_put_error(0x2f,0x6e,0x41,"ts_rsp_sign.c",0x6a);
  TS_RESP_CTX_set_status_info(param_1,2,"Error during serial number generation.");
  return (ASN1_INTEGER *)0x0;
}

