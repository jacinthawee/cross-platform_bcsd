
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 nuron_init(void)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (pvDSOHandle == 0) {
    pcVar2 = NURON_LIBNAME;
    if (NURON_LIBNAME == (char *)0x0) {
      pcVar2 = "nuronssl";
    }
    pvDSOHandle = (*(code *)PTR_DSO_load_006a99a4)(0,pcVar2,0,2);
    if (pvDSOHandle != 0) {
      pfnModExp = (*(code *)PTR_DSO_bind_func_006a99ac)(pvDSOHandle,"nuron_mod_exp");
      if (pfnModExp != 0) {
        return 1;
      }
      if (NURON_lib_error_code == 0) {
        NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(NURON_lib_error_code,0x66,0x67,"e_nuron.c",0x8f);
      return 0;
    }
    if (NURON_lib_error_code == 0) {
      NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar3 = 0x68;
    uVar1 = 0x88;
  }
  else {
    if (NURON_lib_error_code == 0) {
      NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar3 = 100;
    uVar1 = 0x80;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(NURON_lib_error_code,0x66,uVar3,"e_nuron.c",uVar1);
  return 0;
}
