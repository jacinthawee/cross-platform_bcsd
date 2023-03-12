
undefined4 nuron_init(void)

{
  char *filename;
  
  if (pvDSOHandle == (DSO *)0x0) {
    filename = NURON_LIBNAME;
    if (NURON_LIBNAME == (char *)0x0) {
      filename = "nuronssl";
    }
    pvDSOHandle = DSO_load((DSO *)0x0,filename,(DSO_METHOD *)0x0,2);
    if (pvDSOHandle == (DSO *)0x0) {
      if (NURON_lib_error_code == 0) {
        NURON_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(NURON_lib_error_code,0x66,0x68,"e_nuron.c",0x8b);
    }
    else {
      pfnModExp = DSO_bind_func(pvDSOHandle,"nuron_mod_exp");
      if (pfnModExp != (DSO_FUNC_TYPE)0x0) {
        return 1;
      }
      if (NURON_lib_error_code == 0) {
        NURON_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(NURON_lib_error_code,0x66,0x67,"e_nuron.c",0x91);
    }
  }
  else {
    if (NURON_lib_error_code == 0) {
      NURON_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(NURON_lib_error_code,0x66,100,"e_nuron.c",0x84);
  }
  return 0;
}

