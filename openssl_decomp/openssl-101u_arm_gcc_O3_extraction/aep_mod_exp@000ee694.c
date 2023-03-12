
int aep_mod_exp(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int local_2c [2];
  
  iVar2 = BN_num_bits(param_4);
  if (iVar2 < 0x881) {
    iVar2 = aep_get_connection(local_2c);
    if (iVar2 == 0) {
      iVar2 = (*p_AEP_ModExp)(local_2c[0],param_2,param_3,param_4,param_1,0);
      if (iVar2 == 0) {
        CRYPTO_lock(9,0x1e,"e_aep.c",0x3dc);
        do {
          iVar3 = iVar2 * 8;
          iVar2 = iVar2 + 1;
          if (local_2c[0] == *(int *)(aep_app_conn_table + iVar3 + 4)) {
            *(undefined4 *)(aep_app_conn_table + iVar3) = 1;
            break;
          }
        } while (iVar2 != 0x100);
        CRYPTO_lock(10,0x1e,"e_aep.c",1000);
        return 1;
      }
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c",0x279);
      puVar1 = PTR_aep_app_conn_table_000ee82c;
      CRYPTO_lock(9,0x1e,"e_aep.c",0x3f2);
      iVar2 = 0;
      do {
        iVar3 = iVar2 * 8;
        iVar2 = iVar2 + 1;
        if (local_2c[0] == *(int *)(puVar1 + iVar3 + 4)) {
          iVar2 = (*p_AEP_CloseConnection)(local_2c[0]);
          if (iVar2 == 0) {
            *(undefined4 *)(aep_app_conn_table + iVar3) = 0;
            *(undefined4 *)(aep_app_conn_table + iVar3 + 4) = 0;
          }
          break;
        }
      } while (iVar2 != 0x100);
      CRYPTO_lock(10,0x1e,"e_aep.c",0x403);
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
  iVar2 = BN_mod_exp(param_1,param_2,param_3,param_4,param_5);
  return iVar2;
}

