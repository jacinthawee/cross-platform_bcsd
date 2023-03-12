
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int aep_get_connection(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
  
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_aep.c",0x36a);
  iVar1 = (*(code *)PTR_getpid_006a9a68)();
  if (iVar1 == recorded_pid) {
    iVar1 = 0;
    puVar7 = aep_app_conn_table;
    piVar3 = (int *)puVar7;
    do {
      iVar2 = *piVar3;
      piVar3 = piVar3 + 2;
      if (iVar2 == 1) {
        iVar2 = 0;
        *(undefined4 *)(aep_app_conn_table + iVar1 * 8) = 2;
        *param_1 = *(undefined4 *)(aep_app_conn_table + iVar1 * 8 + 4);
        goto LAB_005ccb70;
      }
      iVar1 = iVar1 + 1;
      iVar6 = 0;
    } while (iVar1 != 0x100);
    do {
      iVar1 = *(int *)puVar7;
      puVar7 = (undefined1 *)((int)puVar7 + 8);
      if (iVar1 == 0) {
        iVar2 = (*p_AEP_OpenConnection)(param_1);
        if (iVar2 == 0) {
          uVar5 = *param_1;
          *(undefined4 *)(aep_app_conn_table + iVar6 * 8) = 2;
          *(undefined4 *)(aep_app_conn_table + iVar6 * 8 + 4) = uVar5;
        }
        else {
          if (AEPHK_lib_error_code == 0) {
            AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x66,0x73,"e_aep.c",0x3c9);
        }
        goto LAB_005ccb70;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0x100);
    iVar2 = 0x10000001;
  }
  else {
    recorded_pid = iVar1;
    (*p_AEP_Finalize)();
    iVar2 = (*p_AEP_Initialize)(0);
    if (iVar2 == 0) {
      iVar2 = (*p_AEP_SetBNCallBacks)(GetBigNumSize,MakeAEPBigNum,ConvertAEPBigNum);
      if (iVar2 == 0) {
        piVar3 = (int *)aep_app_conn_table;
        do {
          *piVar3 = 0;
          piVar4 = piVar3 + 2;
          piVar3[1] = 0;
          piVar3 = piVar4;
        } while (piVar4 != &AEPHK_lib_error_code);
        iVar2 = (*p_AEP_OpenConnection)(param_1);
        if (iVar2 == 0) {
          aep_app_conn_table._4_4_ = *param_1;
          aep_app_conn_table._0_4_ = 2;
        }
        else {
          if (AEPHK_lib_error_code == 0) {
            AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x66,0x73,"e_aep.c",0x3aa);
          recorded_pid = 0;
        }
      }
      else {
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x66,0x72,"e_aep.c",0x391);
        recorded_pid = 0;
      }
    }
    else {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x66,0x6b,"e_aep.c",900);
      recorded_pid = 0;
    }
  }
LAB_005ccb70:
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"e_aep.c",0x3d4);
  return iVar2;
}

