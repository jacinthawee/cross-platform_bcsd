
undefined4 nuron_finish(void)

{
  int iVar1;
  
  if (NURON_LIBNAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  NURON_LIBNAME = 0;
  if (pvDSOHandle != 0) {
    iVar1 = (*(code *)PTR_DSO_free_006a9994)();
    if (iVar1 != 0) {
      pvDSOHandle = 0;
      pfnModExp = 0;
      return 1;
    }
    if (NURON_lib_error_code == 0) {
      NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(NURON_lib_error_code,0x65,0x66,"e_nuron.c",0xa0);
    return 0;
  }
  if (NURON_lib_error_code == 0) {
    NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
  }
  (*(code *)PTR_ERR_put_error_006a9030)(NURON_lib_error_code,0x65,0x69,"e_nuron.c",0x9b);
  return 0;
}
