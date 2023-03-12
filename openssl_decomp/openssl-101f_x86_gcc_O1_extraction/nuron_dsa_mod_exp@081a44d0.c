
bool nuron_dsa_mod_exp(undefined4 param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,BIGNUM *param_7,BN_CTX *param_8)

{
  int iVar1;
  int in_GS_OFFSET;
  bool bVar2;
  BIGNUM local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  BN_init(&local_34);
  if (pvDSOHandle == 0) {
LAB_081a45a0:
    if (NURON_lib_error_code == 0) {
      NURON_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(NURON_lib_error_code,0x67,0x69,"e_nuron.c",0xc5);
  }
  else {
    iVar1 = (*pfnModExp)(param_2,param_3,param_4,param_7);
    if (iVar1 != 0) {
      if (pvDSOHandle == 0) goto LAB_081a45a0;
      iVar1 = (*pfnModExp)(&local_34,param_5,param_6,param_7);
      if (iVar1 != 0) {
        iVar1 = BN_mod_mul(param_2,param_2,&local_34,param_7,param_8);
        bVar2 = iVar1 != 0;
        goto LAB_081a453c;
      }
    }
  }
  bVar2 = false;
LAB_081a453c:
  BN_free(&local_34);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

