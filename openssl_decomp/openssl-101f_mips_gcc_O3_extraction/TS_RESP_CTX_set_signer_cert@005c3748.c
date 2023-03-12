
undefined4 TS_RESP_CTX_set_signer_cert(int *param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = (*(code *)PTR_X509_check_purpose_006a87e8)(param_2,9,0);
  if (iVar2 == 1) {
    if (*param_1 != 0) {
      (*(code *)PTR_X509_free_006a7f90)();
    }
    puVar1 = PTR_CRYPTO_add_lock_006a9080;
    *param_1 = param_2;
    (*(code *)puVar1)(param_2 + 0x10,1,3,"ts_rsp_sign.c",0xd3);
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x83,0x75,"ts_rsp_sign.c",0xce);
  return 0;
}

