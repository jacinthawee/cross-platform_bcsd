
undefined4 atalla_finish(void)

{
  int iVar1;
  
  if (ATALLA_LIBNAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  ATALLA_LIBNAME = 0;
  if (atalla_dso != 0) {
    iVar1 = (*(code *)PTR_DSO_free_006a9994)();
    if (iVar1 != 0) {
      atalla_dso = 0;
      p_Atalla_RSAPrivateKeyOpFn = 0;
      return 1;
    }
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(ATALLA_lib_error_code,0x65,0x6b,"e_atalla.c",0x19a);
    return 0;
  }
  if (ATALLA_lib_error_code == 0) {
    ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
  }
  (*(code *)PTR_ERR_put_error_006a9030)(ATALLA_lib_error_code,0x65,0x69,"e_atalla.c",0x195);
  return 0;
}

