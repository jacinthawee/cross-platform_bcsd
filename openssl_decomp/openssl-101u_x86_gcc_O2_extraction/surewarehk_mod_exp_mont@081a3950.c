
int surewarehk_mod_exp_mont
              (BIGNUM *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_GS_OFFSET;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50 [12];
  int local_20;
  
  local_60 = 0x49474e45;
  local_5c = 0x6d5f454e;
  local_58 = 0x7865646f;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_54 = 0x70;
  puVar3 = local_50;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    iVar2 = 0;
    ERR_put_error(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c",0x435);
  }
  else {
    if (param_1 != (BIGNUM *)0x0) {
      bn_expand2(param_1,param_4[1]);
      if (param_1->dmax == param_4[1]) {
        iVar2 = (*p_surewarehk_Mod_Exp)
                          (&local_60,param_1->dmax << 2,*param_4,param_3[1] << 2,*param_3,
                           param_2[1] << 2,*param_2,param_1->d);
        surewarehk_error_handling();
        if (iVar2 == 1) {
          iVar1 = param_4[1];
          param_1->top = iVar1;
          if (0 < iVar1) {
            do {
              if (param_1->d[iVar1 + -1] != 0) break;
              iVar1 = iVar1 + -1;
            } while (iVar1 != 0);
            param_1->top = iVar1;
          }
        }
        goto LAB_081a39d9;
      }
    }
    iVar2 = 0;
  }
LAB_081a39d9:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

