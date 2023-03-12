
bool surewarehk_dsa_mod_exp
               (undefined4 param_1,BIGNUM *param_2,undefined4 *param_3,undefined4 *param_4,
               undefined4 *param_5,undefined4 *param_6,BIGNUM *param_7,BN_CTX *param_8)

{
  int iVar1;
  undefined4 *puVar2;
  int in_GS_OFFSET;
  bool bVar3;
  byte bVar4;
  BIGNUM local_74;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50 [12];
  int local_20;
  
  bVar4 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  BN_init(&local_74);
  local_60 = 0x49474e45;
  puVar2 = local_50;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + (uint)bVar4 * -2 + 1;
  }
  local_5c = 0x6d5f454e;
  local_58 = 0x7865646f;
  local_54 = 0x70;
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
LAB_081a5df0:
    local_54 = 0x70;
    local_58 = 0x7865646f;
    local_5c = 0x6d5f454e;
    local_60 = 0x49474e45;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c",0x403);
  }
  else {
    bn_expand2(param_2,param_7->top);
    if ((param_2 != (BIGNUM *)0x0) && (param_2->dmax == param_7->top)) {
      iVar1 = (*p_surewarehk_Mod_Exp)
                        (&local_60,param_2->dmax << 2,param_7->d,param_4[1] << 2,*param_4,
                         param_3[1] << 2,*param_3,param_2->d);
      surewarehk_error_handling();
      if (iVar1 == 1) {
        iVar1 = param_7->top;
        param_2->top = iVar1;
        if (0 < iVar1) {
          do {
            if (param_2->d[iVar1 + -1] != 0) break;
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
          param_2->top = iVar1;
        }
      }
      else if (iVar1 == 0) goto LAB_081a5ca1;
      local_60 = 0x49474e45;
      local_5c = 0x6d5f454e;
      puVar2 = local_50;
      for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + (uint)bVar4 * -2 + 1;
      }
      local_58 = 0x7865646f;
      local_54 = 0x70;
      if (p_surewarehk_Mod_Exp == (code *)0x0) goto LAB_081a5df0;
      bn_expand2(&local_74,param_7->top);
      if (local_74.dmax == param_7->top) {
        iVar1 = (*p_surewarehk_Mod_Exp)
                          (&local_60,local_74.dmax << 2,param_7->d,param_6[1] << 2,*param_6,
                           param_5[1] << 2,*param_5,local_74.d);
        surewarehk_error_handling();
        if (iVar1 == 1) {
          local_74.top = param_7->top;
          if (0 < local_74.top) {
            do {
              if (local_74.d[local_74.top + -1] != 0) break;
              local_74.top = local_74.top + -1;
            } while (local_74.top != 0);
          }
        }
        else if (iVar1 == 0) goto LAB_081a5ca1;
        iVar1 = BN_mod_mul(param_2,param_2,&local_74,param_7,param_8);
        bVar3 = iVar1 != 0;
        goto LAB_081a5ca3;
      }
    }
  }
LAB_081a5ca1:
  bVar3 = false;
LAB_081a5ca3:
  BN_free(&local_74);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

