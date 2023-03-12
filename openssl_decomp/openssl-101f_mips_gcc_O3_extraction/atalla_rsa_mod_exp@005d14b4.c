
undefined4 atalla_rsa_mod_exp(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (atalla_dso == 0) {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar3 = 0x69;
    uVar1 = 0x20a;
  }
  else {
    iVar2 = param_3;
    if ((*(int *)(param_3 + 0x18) != 0) &&
       (iVar2 = *(int *)(param_3 + 0x18), *(int *)(param_3 + 0x10) != 0)) {
      uVar1 = atalla_mod_exp();
      return uVar1;
    }
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)(0,param_2,iVar2);
    }
    uVar3 = 0x68;
    uVar1 = 0x20f;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(ATALLA_lib_error_code,0x68,uVar3,"e_atalla.c",uVar1);
  return 0;
}

