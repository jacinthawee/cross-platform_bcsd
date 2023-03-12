
bool atalla_dsa_mod_exp(undefined4 param_1,BIGNUM *param_2)

{
  int iVar1;
  int in_GS_OFFSET;
  bool bVar2;
  BIGNUM *param_7;
  BN_CTX *param_8;
  BIGNUM local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  BN_init(&local_34);
  iVar1 = atalla_mod_exp(param_7,param_8);
  if (iVar1 != 0) {
    iVar1 = atalla_mod_exp(param_7,param_8);
    if (iVar1 != 0) {
      iVar1 = BN_mod_mul(param_2,param_2,&local_34,param_7,param_8);
      bVar2 = iVar1 != 0;
      goto LAB_0819fbe5;
    }
  }
  bVar2 = false;
LAB_0819fbe5:
  BN_free(&local_34);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

