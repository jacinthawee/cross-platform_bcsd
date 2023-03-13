
int __regparm3 aep_get_connection(int *param_1)

{
  __pid_t _Var1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int line;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 uVar8;
  
  uVar8 = 0x36a;
  pcVar7 = "e_aep.c";
  uVar6 = 0x1e;
  CRYPTO_lock((int)param_1,9,(char *)0x1e,(int)"e_aep.c");
  _Var1 = getpid();
  if (_Var1 == recorded_pid) {
    iVar4 = 0;
    do {
      if (*(int *)(aep_app_conn_table + iVar4 * 8) == 1) {
        *(undefined4 *)(aep_app_conn_table + iVar4 * 8) = 2;
        iVar4 = *(int *)(aep_app_conn_table + iVar4 * 8 + 4);
        iVar2 = 0;
        *param_1 = iVar4;
        goto LAB_0819cc56;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x100);
    iVar5 = 0;
    do {
      iVar4 = *(int *)(aep_app_conn_table + iVar5 * 8);
      if (iVar4 == 0) {
        iVar2 = (*p_AEP_OpenConnection)(param_1,uVar6,pcVar7,uVar8);
        if (iVar2 == 0) {
          iVar4 = *param_1;
          *(undefined4 *)(aep_app_conn_table + iVar5 * 8) = 2;
          *(int *)(aep_app_conn_table + iVar5 * 8 + 4) = iVar4;
        }
        else {
          if (AEPHK_lib_error_code == 0) {
            AEPHK_lib_error_code = ERR_get_next_error_library();
          }
          iVar4 = AEPHK_lib_error_code;
          ERR_put_error(AEPHK_lib_error_code,0x66,0x73,"e_aep.c",0x3c9);
        }
        goto LAB_0819cc56;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0x100);
    iVar2 = 0x10000001;
  }
  else {
    recorded_pid = _Var1;
    (*p_AEP_Finalize)();
    iVar2 = (*p_AEP_Initialize)(0);
    if (iVar2 == 0) {
      iVar2 = (*p_AEP_SetBNCallBacks)(GetBigNumSize,MakeAEPBigNum,ConvertAEPBigNum);
      puVar3 = aep_app_conn_table;
      if (iVar2 == 0) {
        do {
          *(undefined4 *)puVar3 = 0;
          *(undefined4 *)((int)puVar3 + 4) = 0;
          puVar3 = (undefined1 *)((int)puVar3 + 8);
        } while ((int *)puVar3 != &AEPHK_lib_error_code);
        iVar2 = (*p_AEP_OpenConnection)(param_1);
        if (iVar2 == 0) {
          iVar4 = *param_1;
          aep_app_conn_table._0_4_ = 2;
          aep_app_conn_table._4_4_ = iVar4;
          goto LAB_0819cc56;
        }
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        line = 0x3aa;
        iVar5 = 0x73;
      }
      else {
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        line = 0x391;
        iVar5 = 0x72;
      }
    }
    else {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      line = 900;
      iVar5 = 0x6b;
    }
    iVar4 = AEPHK_lib_error_code;
    ERR_put_error(AEPHK_lib_error_code,0x66,iVar5,"e_aep.c",line);
    recorded_pid = 0;
  }
LAB_0819cc56:
  CRYPTO_lock(iVar4,10,(char *)0x1e,(int)"e_aep.c");
  return iVar2;
}

