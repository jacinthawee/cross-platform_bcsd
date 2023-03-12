
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void surewarehk_modexp_dh
               (undefined4 param_1,BIGNUM *param_2,undefined4 *param_3,undefined4 *param_4,
               undefined4 *param_5)

{
  BIGNUM *pBVar1;
  ulong *puVar2;
  int iVar3;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined2 local_58;
  undefined auStack_56 [50];
  int local_24;
  
  local_64 = s_ENGINE_modexp_00170508._0_4_;
  uStack_60 = s_ENGINE_modexp_00170508._4_4_;
  uStack_5c = s_ENGINE_modexp_00170508._8_4_;
  local_58 = (undefined2)ram0x00170514;
  local_24 = __TMC_END__;
  memset(auStack_56,0,0x32);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c",0x403);
    pBVar1 = (BIGNUM *)0x0;
  }
  else {
    bn_expand2(param_2,param_5[1]);
    pBVar1 = param_2;
    if (param_2 != (BIGNUM *)0x0) {
      if (param_2->dmax == param_5[1]) {
        pBVar1 = (BIGNUM *)
                 (*p_surewarehk_Mod_Exp)
                           (&local_64,param_2->dmax << 2,*param_5,param_4[1] << 2,*param_4,
                            param_3[1] << 2,*param_3,param_2->d);
        surewarehk_error_handling(&local_64,0x6b,pBVar1);
        if (pBVar1 == (BIGNUM *)0x1) {
          iVar3 = param_5[1];
          param_2->top = iVar3;
          if (0 < iVar3) {
            puVar2 = param_2->d + iVar3 + 0x3fffffff;
            do {
              if (*puVar2 != 0) break;
              iVar3 = iVar3 + -1;
              puVar2 = puVar2 + -1;
            } while (iVar3 != 0);
            param_2->top = iVar3;
          }
        }
      }
      else {
        pBVar1 = (BIGNUM *)0x0;
      }
    }
  }
  if (local_24 == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pBVar1);
}

