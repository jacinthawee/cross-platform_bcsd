
bool aep_dsa_mod_exp(undefined4 param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                    BIGNUM *param_5,BIGNUM *param_6,BIGNUM *param_7,BN_CTX *param_8)

{
  int iVar1;
  int in_GS_OFFSET;
  bool bVar2;
  BIGNUM local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  BN_init(&local_34);
  iVar1 = BN_num_bits(param_7);
  if (iVar1 < 0x881) {
    iVar1 = aep_mod_exp_part_0(param_7,param_8);
  }
  else {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(AEPHK_lib_error_code,0x68,0x74,"e_aep.c",0x266);
    iVar1 = BN_mod_exp(param_2,param_3,param_4,param_7,param_8);
  }
  if (iVar1 != 0) {
    iVar1 = BN_num_bits(param_7);
    if (iVar1 < 0x881) {
      iVar1 = aep_mod_exp_part_0(param_7,param_8);
    }
    else {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(AEPHK_lib_error_code,0x68,0x74,"e_aep.c",0x266);
      iVar1 = BN_mod_exp(&local_34,param_5,param_6,param_7,param_8);
    }
    if (iVar1 != 0) {
      iVar1 = BN_mod_mul(param_2,param_2,&local_34,param_7,param_8);
      bVar2 = iVar1 != 0;
      goto LAB_0819e55c;
    }
  }
  bVar2 = false;
LAB_0819e55c:
  BN_free(&local_34);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

