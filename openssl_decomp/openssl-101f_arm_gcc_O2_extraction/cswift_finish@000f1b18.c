
undefined4 cswift_finish(void)

{
  int iVar1;
  
  if (CSWIFT_LIBNAME != (void *)0x0) {
    CRYPTO_free(CSWIFT_LIBNAME);
  }
  CSWIFT_LIBNAME = (void *)0x0;
  if (cswift_dso != (DSO *)0x0) {
    iVar1 = DSO_free(cswift_dso);
    if (iVar1 != 0) {
      cswift_dso = (DSO *)0x0;
      p_CSwift_AcquireAccContext = 0;
      p_CSwift_AttachKeyParam = 0;
      p_CSwift_SimpleRequest = 0;
      p_CSwift_ReleaseAccContext = 0;
      return 1;
    }
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CSWIFT_lib_error_code,0x67,0x6c,"e_cswift.c",0x1c2);
    return 0;
  }
  if (CSWIFT_lib_error_code == 0) {
    CSWIFT_lib_error_code = ERR_get_next_error_library();
  }
  ERR_put_error(CSWIFT_lib_error_code,0x67,0x6a,"e_cswift.c",0x1bd);
  return 0;
}

