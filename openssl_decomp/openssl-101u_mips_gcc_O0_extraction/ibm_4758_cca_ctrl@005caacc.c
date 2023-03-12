
bool ibm_4758_cca_ctrl(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 != 200) {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,100,0x66,"e_4758cca.c",0x184);
    return false;
  }
  if (param_4 == 0) {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar2 = 0x43;
    uVar1 = 0x178;
  }
  else {
    if (dso == 0) {
      if (CCA4758_LIB_NAME != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      CCA4758_LIB_NAME = 0;
      CCA4758_LIB_NAME = (*(code *)PTR_BUF_strdup_006a6fdc)(param_4);
      return CCA4758_LIB_NAME != 0;
    }
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar2 = 100;
    uVar1 = 0x17c;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,100,uVar2,"e_4758cca.c",uVar1);
  return false;
}

