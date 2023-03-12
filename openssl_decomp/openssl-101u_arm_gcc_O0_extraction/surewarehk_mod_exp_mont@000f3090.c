
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void surewarehk_mod_exp_mont
               (BIGNUM *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  ulong *puVar1;
  int iVar2;
  int iVar3;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined2 local_58;
  undefined auStack_56 [50];
  int local_24;
  
  local_64 = s_ENGINE_modexp_0016f1f0._0_4_;
  uStack_60 = s_ENGINE_modexp_0016f1f0._4_4_;
  uStack_5c = s_ENGINE_modexp_0016f1f0._8_4_;
  local_58 = (undefined2)ram0x0016f1fc;
  local_24 = __stack_chk_guard;
  memset(auStack_56,0,0x32);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    iVar3 = 0;
    ERR_put_error(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c",0x435);
  }
  else {
    if (param_1 != (BIGNUM *)0x0) {
      bn_expand2(param_1,param_4[1]);
      if (param_1->dmax == param_4[1]) {
        iVar3 = (*p_surewarehk_Mod_Exp)
                          (&local_64,param_1->dmax << 2,*param_4,param_3[1] << 2,*param_3,
                           param_2[1] << 2,*param_2,param_1->d);
        surewarehk_error_handling(&local_64,0x6b,iVar3);
        if (iVar3 == 1) {
          iVar2 = param_4[1];
          param_1->top = iVar2;
          if (0 < iVar2) {
            puVar1 = param_1->d + iVar2 + 0x3fffffff;
            do {
              if (*puVar1 != 0) break;
              iVar2 = iVar2 + -1;
              puVar1 = puVar1 + -1;
            } while (iVar2 != 0);
            param_1->top = iVar2;
          }
        }
        goto LAB_000f30f2;
      }
    }
    iVar3 = 0;
  }
LAB_000f30f2:
  if (local_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar3);
}

