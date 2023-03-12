
undefined4 ibm_4758_cca_finish(void)

{
  int iVar1;
  
  if (CCA4758_LIB_NAME != (void *)0x0) {
    CRYPTO_free(CCA4758_LIB_NAME);
  }
  CCA4758_LIB_NAME = (void *)0x0;
  if (dso != (DSO *)0x0) {
    iVar1 = DSO_free(dso);
    if (iVar1 != 0) {
      dso = (DSO *)0x0;
      keyRecordRead = 0;
      randomNumberGenerate = 0;
      digitalSignatureGenerate = 0;
      digitalSignatureVerify = 0;
      publicKeyExtract = 0;
      pkaEncrypt = 0;
      pkaDecrypt = 0;
      return 1;
    }
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CCA4758_lib_error_code,0x65,0x6c,"e_4758cca.c",0x15f);
    return 0;
  }
  if (CCA4758_lib_error_code == 0) {
    CCA4758_lib_error_code = ERR_get_next_error_library();
  }
  ERR_put_error(CCA4758_lib_error_code,0x65,0x6a,"e_4758cca.c",0x15b);
  return 0;
}

