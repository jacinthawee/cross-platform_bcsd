
undefined4 hwcrhk_rand_bytes(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_GS_OFFSET;
  undefined *local_418;
  undefined4 local_414;
  undefined local_410 [1024];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_418 = local_410;
  local_414 = 0x400;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x6c,0x6a,"e_chil.c",0x45e);
    uVar2 = 0;
  }
  else {
    iVar1 = (*p_hwcrhk_RandomBytes)(hwcrhk_context,param_1,param_2,&local_418);
    uVar2 = 1;
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
        ERR_put_error(HWCRHK_lib_error_code,0x6c,0x6f,"e_chil.c",0x46b);
      }
      ERR_add_error_data(1,local_418);
      uVar2 = 0;
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

