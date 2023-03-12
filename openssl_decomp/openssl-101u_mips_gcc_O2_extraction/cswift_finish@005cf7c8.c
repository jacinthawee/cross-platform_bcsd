
undefined4 cswift_finish(void)

{
  int iVar1;
  
  if (CSWIFT_LIBNAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  CSWIFT_LIBNAME = 0;
  if (cswift_dso != 0) {
    iVar1 = (*(code *)PTR_DSO_free_006a8874)();
    if (iVar1 != 0) {
      cswift_dso = 0;
      p_CSwift_AcquireAccContext = 0;
      p_CSwift_AttachKeyParam = 0;
      p_CSwift_SimpleRequest = 0;
      p_CSwift_ReleaseAccContext = 0;
      return 1;
    }
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(CSWIFT_lib_error_code,0x67,0x6c,"e_cswift.c",0x1c6);
    return 0;
  }
  if (CSWIFT_lib_error_code == 0) {
    CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(CSWIFT_lib_error_code,0x67,0x6a,"e_cswift.c",0x1c2);
  return 0;
}

