
undefined4 atalla_finish(void)

{
  int iVar1;
  
  if (ATALLA_LIBNAME != (void *)0x0) {
    CRYPTO_free(ATALLA_LIBNAME);
  }
  ATALLA_LIBNAME = (void *)0x0;
  if (atalla_dso != (DSO *)0x0) {
    iVar1 = DSO_free(atalla_dso);
    if (iVar1 != 0) {
      atalla_dso = (DSO *)0x0;
      p_Atalla_GetHardwareConfig = 0;
      p_Atalla_RSAPrivateKeyOpFn = 0;
      p_Atalla_GetPerformanceStatistics = 0;
      return 1;
    }
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(ATALLA_lib_error_code,0x65,0x6b,"e_atalla.c",0x19a);
    return 0;
  }
  if (ATALLA_lib_error_code == 0) {
    ATALLA_lib_error_code = ERR_get_next_error_library();
  }
  ERR_put_error(ATALLA_lib_error_code,0x65,0x69,"e_atalla.c",0x195);
  return 0;
}

