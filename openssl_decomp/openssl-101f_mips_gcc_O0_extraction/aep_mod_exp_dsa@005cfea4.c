
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4
aep_mod_exp_dsa(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  int *piVar9;
  undefined *puVar10;
  int local_30;
  int local_2c;
  
  puVar10 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)(param_5);
  if (iVar1 < 0x881) {
    iVar1 = aep_get_connection(&local_30);
    if (iVar1 == 0) {
      iVar1 = (*p_AEP_ModExp)(local_30,param_3,param_4,param_5,param_2,0);
      if (iVar1 == 0) {
        (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_aep.c",0x3cc);
        piVar9 = (int *)(aep_app_conn_table + 4);
        iVar1 = 0;
        do {
          iVar2 = iVar1 + 1;
          if (local_30 == *piVar9) {
            *(undefined4 *)(aep_app_conn_table + iVar1 * 8) = 1;
            break;
          }
          piVar9 = piVar9 + 2;
          iVar1 = iVar2;
        } while (iVar2 != 0x100);
        (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"e_aep.c",0x3d8);
        uVar3 = 1;
        goto LAB_005d0034;
      }
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c",0x277);
      (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_aep.c",0x3e2);
      piVar9 = (int *)(aep_app_conn_table + 4);
      iVar1 = 0;
      do {
        iVar2 = iVar1 + 1;
        if (local_30 == *piVar9) {
          iVar2 = (*p_AEP_CloseConnection)(local_30);
          if (iVar2 == 0) {
            *(undefined4 *)(aep_app_conn_table + iVar1 * 8) = 0;
            *(undefined4 *)(aep_app_conn_table + iVar1 * 8 + 4) = 0;
          }
          break;
        }
        piVar9 = piVar9 + 2;
        iVar1 = iVar2;
      } while (iVar2 != 0x100);
      (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"e_aep.c",0x3f3);
    }
    else {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(AEPHK_lib_error_code,0x68,0x69,"e_aep.c",0x26e);
    }
  }
  else {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(AEPHK_lib_error_code,0x68,0x74,"e_aep.c",0x266);
  }
  uVar3 = (*(code *)PTR_BN_mod_exp_006a8a48)(param_2,param_3,param_4,param_5,param_6);
LAB_005d0034:
  if (local_2c == *(int *)puVar10) {
    return uVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (aep_dso == 0) {
    puVar10 = AEP_LIBNAME;
    if (AEP_LIBNAME == (undefined *)0x0) {
      puVar10 = &DAT_00673d78;
    }
    aep_dso = (*(code *)PTR_DSO_load_006a99a4)(0,puVar10,0,0);
    if (aep_dso == 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(AEPHK_lib_error_code,0x67,0x6f,"e_aep.c",0x1ca);
    }
    else {
      pcVar4 = (code *)(*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_ModExp");
      if ((((pcVar4 != (code *)0x0) &&
           (iVar1 = (*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_ModExpCrt"), iVar1 != 0)) &&
          (iVar2 = (*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_Finalize"), iVar2 != 0)) &&
         (((iVar5 = (*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_Initialize"), iVar5 != 0 &&
           (iVar6 = (*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_OpenConnection"), iVar6 != 0)
           ) && ((iVar7 = (*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_SetBNCallBacks"),
                 iVar7 != 0 &&
                 (pcVar8 = (code *)(*(code *)PTR_DSO_bind_func_006a99ac)
                                             (aep_dso,"AEP_CloseConnection"), pcVar8 != (code *)0x0)
                 ))))) {
        p_AEP_SetBNCallBacks = iVar7;
        p_AEP_Finalize = iVar2;
        p_AEP_Initialize = iVar5;
        p_AEP_ModExpCrt = iVar1;
        p_AEP_ModExp = pcVar4;
        p_AEP_CloseConnection = pcVar8;
        p_AEP_OpenConnection = iVar6;
        return 1;
      }
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(AEPHK_lib_error_code,0x67,0x6f,"e_aep.c",0x1d9);
    }
  }
  else {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(AEPHK_lib_error_code,0x67,100,"e_aep.c",0x1c1);
  }
  if (aep_dso != 0) {
    (*(code *)PTR_DSO_free_006a9994)();
  }
  aep_dso = 0;
  p_AEP_OpenConnection = 0;
  p_AEP_CloseConnection = (code *)0x0;
  p_AEP_ModExp = (code *)0x0;
  p_AEP_ModExpCrt = 0;
  p_AEP_Initialize = 0;
  p_AEP_Finalize = 0;
  p_AEP_SetBNCallBacks = 0;
  return 0;
}

