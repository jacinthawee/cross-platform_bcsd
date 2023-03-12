
int aep_dsa_mod_exp(undefined4 param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,
                   undefined4 param_5,undefined4 param_6,BIGNUM *param_7,BN_CTX *param_8)

{
  int iVar1;
  int iVar2;
  int local_40;
  BIGNUM BStack_3c;
  
  BN_init(&BStack_3c);
  iVar1 = BN_num_bits(param_7);
  if (iVar1 < 0x881) {
    iVar1 = aep_get_connection(&local_40);
    if (iVar1 != 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x26e;
      iVar1 = 0x69;
      goto LAB_000eedec;
    }
    iVar1 = (*p_AEP_ModExp)(local_40,param_3,param_4,param_7,param_2,0);
    if (iVar1 != 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c",0x279);
      iVar1 = 0;
      CRYPTO_lock(9,0x1e,"e_aep.c",0x3f2);
      do {
        iVar2 = iVar1 * 8;
        iVar1 = iVar1 + 1;
        if (local_40 == *(int *)(PTR_aep_app_conn_table_000eeec8 + iVar2 + 4)) {
          iVar1 = (*p_AEP_CloseConnection)(local_40);
          if (iVar1 == 0) {
            *(undefined4 *)(aep_app_conn_table + iVar2) = 0;
            *(undefined4 *)(aep_app_conn_table + iVar2 + 4) = 0;
          }
          break;
        }
      } while (iVar1 != 0x100);
      CRYPTO_lock(10,0x1e,"e_aep.c",0x403);
      goto LAB_000eedf0;
    }
    CRYPTO_lock(9,0x1e,"e_aep.c",0x3dc);
    do {
      iVar2 = iVar1 * 8;
      iVar1 = iVar1 + 1;
      if (local_40 == *(int *)(aep_app_conn_table + iVar2 + 4)) {
        *(undefined4 *)(aep_app_conn_table + iVar2) = 1;
        break;
      }
    } while (iVar1 != 0x100);
    CRYPTO_lock(10,0x1e,"e_aep.c",1000);
LAB_000eeda8:
    iVar1 = aep_mod_exp(&BStack_3c,param_5,param_6,param_7,param_8);
    if (iVar1 != 0) {
      iVar1 = BN_mod_mul(param_2,param_2,&BStack_3c,param_7,param_8);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      goto LAB_000eee04;
    }
  }
  else {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    iVar2 = 0x265;
    iVar1 = 0x74;
LAB_000eedec:
    ERR_put_error(AEPHK_lib_error_code,0x68,iVar1,"e_aep.c",iVar2);
LAB_000eedf0:
    iVar1 = BN_mod_exp(param_2,param_3,param_4,param_7,param_8);
    if (iVar1 != 0) goto LAB_000eeda8;
  }
  iVar1 = 0;
LAB_000eee04:
  BN_free(&BStack_3c);
  return iVar1;
}

