
int TS_RESP_CTX_new(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x50,"ts_rsp_sign.c",0xac);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x7f,0x41,"ts_rsp_sign.c",0xad);
    iVar1 = 0;
  }
  else {
    (*(code *)PTR_memset_006a99f4)(iVar1,0,0x50);
    *(code **)(iVar1 + 0x34) = def_time_cb;
    *(code **)(iVar1 + 0x2c) = def_serial_cb;
    *(code **)(iVar1 + 0x3c) = def_extension_cb;
  }
  return iVar1;
}

