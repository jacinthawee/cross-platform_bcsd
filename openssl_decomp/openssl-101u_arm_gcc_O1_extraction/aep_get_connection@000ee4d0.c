
int aep_get_connection(undefined4 *param_1)

{
  __pid_t _Var1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  CRYPTO_lock(9,0x1e,"e_aep.c",0x36a);
  _Var1 = getpid();
  if (recorded_pid == _Var1) {
    iVar2 = 0;
    do {
      iVar3 = iVar2 * 8;
      iVar5 = iVar2 * 8;
      iVar2 = iVar2 + 1;
      if (*(int *)(aep_app_conn_table + iVar3) == 1) {
        iVar2 = 0;
        *(undefined4 *)(aep_app_conn_table + iVar5) = 2;
        *param_1 = *(undefined4 *)(aep_app_conn_table + iVar5 + 4);
        goto LAB_000ee580;
      }
    } while (iVar2 != 0x100);
    iVar2 = 0;
    do {
      iVar3 = iVar2 * 8;
      iVar5 = iVar2 * 8;
      iVar2 = iVar2 + 1;
      if (*(int *)(aep_app_conn_table + iVar3) == 0) {
        iVar2 = (*p_AEP_OpenConnection)(param_1);
        if (iVar2 == 0) {
          uVar4 = *param_1;
          *(undefined4 *)(aep_app_conn_table + iVar5) = 2;
          *(undefined4 *)(aep_app_conn_table + iVar5 + 4) = uVar4;
        }
        else {
          if (AEPHK_lib_error_code == 0) {
            AEPHK_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(AEPHK_lib_error_code,0x66,0x73,"e_aep.c",0x3c9);
        }
        goto LAB_000ee580;
      }
    } while (iVar2 != 0x100);
    iVar2 = 0x10000001;
  }
  else {
    recorded_pid = _Var1;
    (*p_AEP_Finalize)();
    iVar2 = (*p_AEP_Initialize)(0);
    if (iVar2 == 0) {
      iVar2 = (*p_AEP_SetBNCallBacks)(0xee1c9,0xee1d5,0xee20d);
      if (iVar2 == 0) {
        do {
          *(undefined4 *)(aep_app_conn_table + iVar2) = 0;
          iVar3 = iVar2 + 8;
          *(undefined4 *)(aep_app_conn_table + iVar2 + 4) = 0;
          iVar2 = iVar3;
        } while (iVar3 != 0x800);
        iVar2 = (*p_AEP_OpenConnection)(param_1);
        if (iVar2 == 0) {
          aep_app_conn_table._4_4_ = *param_1;
          aep_app_conn_table._0_4_ = 2;
        }
        else {
          if (AEPHK_lib_error_code == 0) {
            AEPHK_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(AEPHK_lib_error_code,0x66,0x73,"e_aep.c",0x3aa);
          recorded_pid = 0;
        }
      }
      else {
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(AEPHK_lib_error_code,0x66,0x72,"e_aep.c",0x391);
        recorded_pid = 0;
      }
    }
    else {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(AEPHK_lib_error_code,0x66,0x6b,"e_aep.c",900);
      recorded_pid = 0;
    }
  }
LAB_000ee580:
  CRYPTO_lock(10,0x1e,"e_aep.c",0x3d4);
  return iVar2;
}

