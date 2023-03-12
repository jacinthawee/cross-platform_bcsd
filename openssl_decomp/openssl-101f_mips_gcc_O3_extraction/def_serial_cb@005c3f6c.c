
int def_serial_cb(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_ASN1_INTEGER_new_006a8260)();
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(iVar1,1);
    if (iVar2 != 0) {
      return iVar1;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x6e,0x41,"ts_rsp_sign.c",0x66);
  TS_RESP_CTX_set_status_info(param_1,2,"Error during serial number generation.");
  return 0;
}

