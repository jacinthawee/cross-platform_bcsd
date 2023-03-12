
undefined4 ibm_4758_cca_finish(void)

{
  int iVar1;
  
  if (CCA4758_LIB_NAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  CCA4758_LIB_NAME = 0;
  if (dso != 0) {
    iVar1 = (*(code *)PTR_DSO_free_006a9994)();
    if (iVar1 != 0) {
      dso = 0;
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
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(CCA4758_lib_error_code,0x65,0x6c,"e_4758cca.c",0x15e);
    return 0;
  }
  if (CCA4758_lib_error_code == 0) {
    CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
  }
  (*(code *)PTR_ERR_put_error_006a9030)(CCA4758_lib_error_code,0x65,0x6a,"e_4758cca.c",0x158);
  return 0;
}

