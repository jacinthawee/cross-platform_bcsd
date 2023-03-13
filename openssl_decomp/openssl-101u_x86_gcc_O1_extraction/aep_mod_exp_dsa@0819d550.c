
int aep_mod_exp_dsa(undefined4 param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                   BIGNUM *param_5,BN_CTX *param_6)

{
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  int local_24;
  
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = BN_num_bits(param_5);
  if (iVar2 < 0x881) {
    iVar2 = aep_get_connection();
    if (iVar2 == 0) {
      iVar2 = (*p_AEP_ModExp)(local_24,param_3,param_4,param_5,param_2,0);
      if (iVar2 == 0) {
        CRYPTO_lock(0,9,(char *)0x1e,(int)"e_aep.c");
        iVar2 = 0;
        do {
          if (local_24 == *(int *)(aep_app_conn_table + iVar2 * 8 + 4)) {
            *(undefined4 *)(aep_app_conn_table + iVar2 * 8) = 1;
            break;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 != 0x100);
        CRYPTO_lock(iVar2,10,(char *)0x1e,(int)"e_aep.c");
        iVar2 = 1;
        goto LAB_0819d653;
      }
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c",0x279);
      uVar5 = 0x3f2;
      pcVar4 = "e_aep.c";
      uVar3 = 0x1e;
      CRYPTO_lock(local_24,9,(char *)0x1e,(int)"e_aep.c");
      iVar2 = 0;
      do {
        if (local_24 == *(int *)(aep_app_conn_table + iVar2 * 8 + 4)) {
          local_24 = (*p_AEP_CloseConnection)(local_24,uVar3,pcVar4,uVar5);
          if (local_24 == 0) {
            *(undefined4 *)(aep_app_conn_table + iVar2 * 8) = 0;
            *(undefined4 *)(aep_app_conn_table + iVar2 * 8 + 4) = 0;
          }
          break;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x100);
      CRYPTO_lock(local_24,10,(char *)0x1e,(int)"e_aep.c");
    }
    else {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(AEPHK_lib_error_code,0x68,0x69,"e_aep.c",0x26e);
    }
  }
  else {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(AEPHK_lib_error_code,0x68,0x74,"e_aep.c",0x265);
  }
  iVar2 = BN_mod_exp(param_2,param_3,param_4,param_5,param_6);
LAB_0819d653:
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

