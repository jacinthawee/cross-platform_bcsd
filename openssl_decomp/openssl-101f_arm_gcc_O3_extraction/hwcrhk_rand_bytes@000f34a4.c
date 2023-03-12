
void hwcrhk_rand_bytes(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined *local_424;
  undefined4 local_420;
  undefined auStack_41c [1024];
  int local_1c;
  
  local_424 = auStack_41c;
  local_1c = __TMC_END__;
  local_420 = 0x400;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x6c,0x6a,"e_chil.c",0x45c);
    uVar2 = 0;
  }
  else {
    iVar1 = (*p_hwcrhk_RandomBytes)(hwcrhk_context,param_1,param_2,&local_424);
    if (iVar1 < 0) {
      if (iVar1 == -2) {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x6c,0x70,"e_chil.c",0x469);
      }
      else {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x6c,0x6f,"e_chil.c",0x46e);
      }
      ERR_add_error_data(1,local_424);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}

