
void hwcrhk_mod_exp_isra_1
               (BIGNUM *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,int *param_5,
               undefined4 *param_6,int *param_7)

{
  int iVar1;
  undefined4 uVar2;
  ulong *puVar3;
  uint uVar4;
  undefined *local_454;
  undefined4 local_450;
  undefined4 local_44c;
  int local_448;
  undefined4 local_444;
  int local_440;
  undefined4 local_43c;
  int local_438;
  ulong *local_434;
  uint local_430;
  undefined auStack_42c [1024];
  int local_2c;
  
  local_454 = auStack_42c;
  local_2c = __stack_chk_guard;
  local_450 = 0x400;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x6b,0x6a,"e_chil.c",0x39a);
    uVar2 = 0;
  }
  else {
    bn_expand2(param_1,*param_7);
    local_43c = *param_6;
    local_44c = *param_2;
    local_438 = *param_7 << 2;
    local_444 = *param_4;
    local_448 = *param_3 << 2;
    local_440 = *param_5 << 2;
    local_434 = param_1->d;
    local_430 = param_1->dmax << 2;
    iVar1 = (*p_hwcrhk_ModExp)(hwcrhk_context,local_44c,local_448,local_444,local_440,local_43c,
                               local_438,&local_434,&local_454);
    uVar4 = local_430 >> 2;
    param_1->top = uVar4;
    if (uVar4 != 0) {
      puVar3 = param_1->d + uVar4 + 0x3fffffff;
      do {
        if (*puVar3 != 0) break;
        uVar4 = uVar4 - 1;
        puVar3 = puVar3 + -1;
      } while (uVar4 != 0);
      param_1->top = uVar4;
    }
    if (iVar1 < 0) {
      if (iVar1 == -2) {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x6b,0x70,"e_chil.c",0x3b1);
      }
      else {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x6b,0x6f,"e_chil.c",0x3b3);
      }
      ERR_add_error_data(1,local_454);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}

