
undefined4 TS_RESP_print_bio(BIO *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  BIO_printf(param_1,"Status info:\n");
  uVar1 = TS_RESP_get_status_info(param_2);
  TS_STATUS_INFO_print_bio(param_1,uVar1);
  BIO_printf(param_1,"\nTST info:\n");
  iVar2 = TS_RESP_get_tst_info(param_2);
  if (iVar2 != 0) {
    uVar1 = TS_RESP_get_tst_info(param_2);
    TS_TST_INFO_print_bio(param_1,uVar1);
    return 1;
  }
  BIO_printf(param_1,"Not included.\n");
  return 1;
}

