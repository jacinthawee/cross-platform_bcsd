
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void surewarehk_dsa_mod_exp
               (undefined4 param_1,BIGNUM *param_2,undefined4 *param_3,undefined4 *param_4,
               undefined4 *param_5,undefined4 *param_6,BIGNUM *param_7,BN_CTX *param_8)

{
  ulong *puVar1;
  int iVar2;
  BIGNUM local_80;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined2 local_60;
  undefined auStack_5e [50];
  int local_2c;
  
  local_2c = __TMC_END__;
  BN_init(&local_80);
  local_6c = s_ENGINE_modexp_001704e4._0_4_;
  uStack_68 = s_ENGINE_modexp_001704e4._4_4_;
  uStack_64 = s_ENGINE_modexp_001704e4._8_4_;
  local_60 = (undefined2)ram0x001704f0;
  memset(auStack_5e,0,0x32);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
LAB_000f526a:
    ERR_put_error(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c",0x403);
  }
  else {
    bn_expand2(param_2,param_7->top);
    if ((param_2 != (BIGNUM *)0x0) && (param_2->dmax == param_7->top)) {
      iVar2 = (*p_surewarehk_Mod_Exp)
                        (&local_6c,param_2->dmax << 2,param_7->d,param_4[1] << 2,*param_4,
                         param_3[1] << 2,*param_3,param_2->d);
      surewarehk_error_handling(&local_6c,0x6b,iVar2);
      if (iVar2 == 1) {
        iVar2 = param_7->top;
        param_2->top = iVar2;
        if (0 < iVar2) {
          puVar1 = param_2->d + iVar2 + 0x3fffffff;
          do {
            if (*puVar1 != 0) break;
            iVar2 = iVar2 + -1;
            puVar1 = puVar1 + -1;
          } while (iVar2 != 0);
          param_2->top = iVar2;
        }
      }
      else if (iVar2 == 0) goto LAB_000f5166;
      local_6c = s_ENGINE_modexp_001704e4._0_4_;
      uStack_68 = s_ENGINE_modexp_001704e4._4_4_;
      uStack_64 = s_ENGINE_modexp_001704e4._8_4_;
      local_60 = (undefined2)ram0x001704f0;
      memset(auStack_5e,0,0x32);
      if (p_surewarehk_Mod_Exp == (code *)0x0) {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = ERR_get_next_error_library();
        }
        goto LAB_000f526a;
      }
      bn_expand2(&local_80,param_7->top);
      if (local_80.dmax == param_7->top) {
        iVar2 = (*p_surewarehk_Mod_Exp)
                          (&local_6c,local_80.dmax << 2,param_7->d,param_6[1] << 2,*param_6,
                           param_5[1] << 2,*param_5,local_80.d);
        surewarehk_error_handling(&local_6c,0x6b,iVar2);
        if (iVar2 == 1) {
          local_80.top = param_7->top;
          if (0 < local_80.top) {
            puVar1 = local_80.d + local_80.top + 0x3fffffff;
            do {
              if (*puVar1 != 0) break;
              local_80.top = local_80.top + -1;
              puVar1 = puVar1 + -1;
            } while (local_80.top != 0);
          }
        }
        else if (iVar2 == 0) goto LAB_000f5166;
        iVar2 = BN_mod_mul(param_2,param_2,&local_80,param_7,param_8);
        if (iVar2 != 0) {
          iVar2 = 1;
        }
        goto LAB_000f5168;
      }
    }
  }
LAB_000f5166:
  iVar2 = 0;
LAB_000f5168:
  BN_free(&local_80);
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}

