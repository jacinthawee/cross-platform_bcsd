
undefined4 __regparm3
hwcrhk_mod_exp_isra_1
          (BIGNUM *param_1_00,undefined4 *param_2_00,int *param_3_00,undefined4 *param_1,
          int *param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_GS_OFFSET;
  undefined *local_430;
  undefined4 local_42c;
  ulong *local_428;
  uint local_424;
  undefined local_420 [1024];
  int local_20;
  
  local_42c = 0x400;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_430 = local_420;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x6b,0x6a,"e_chil.c",0x390);
    uVar3 = 0;
  }
  else {
    bn_expand2(param_1_00,*param_4);
    local_424 = param_1_00->dmax << 2;
    local_428 = param_1_00->d;
    iVar1 = (*p_hwcrhk_ModExp)(hwcrhk_context,*param_2_00,*param_3_00 * 4,*param_1,*param_2 << 2,
                               *param_3,*param_4 * 4,&local_428,&local_430);
    uVar2 = local_424 >> 2;
    param_1_00->top = uVar2;
    if (uVar2 != 0) {
      do {
        if (param_1_00->d[uVar2 - 1] != 0) break;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
      param_1_00->top = uVar2;
    }
    uVar3 = 1;
    if (iVar1 < 0) {
      if (iVar1 == -2) {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x6b,0x70,"e_chil.c",0x3a8);
      }
      else {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x6b,0x6f,"e_chil.c",0x3ac);
      }
      ERR_add_error_data(1,local_430);
      uVar3 = 0;
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

