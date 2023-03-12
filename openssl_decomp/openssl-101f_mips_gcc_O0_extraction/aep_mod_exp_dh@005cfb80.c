
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4
aep_mod_exp_dh(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4,int param_5,
              undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  code *pcVar9;
  int *piVar10;
  undefined4 uVar11;
  undefined *puVar12;
  char *pcVar13;
  int unaff_s7;
  int iStack_80;
  int iStack_7c;
  undefined *puStack_78;
  char *pcStack_74;
  int iStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  char *pcStack_64;
  undefined4 uStack_60;
  int iStack_5c;
  code *pcStack_54;
  undefined4 local_40;
  undefined4 local_3c;
  undefined *local_38;
  int local_30;
  int local_2c;
  
  puStack_78 = PTR___stack_chk_guard_006aabf0;
  local_38 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(param_5);
  if (iVar2 < 0x881) {
    iVar2 = aep_get_connection(&local_30);
    if (iVar2 != 0) {
      pcStack_74 = &_ITM_registerTMCloneTable;
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(local_38 + -0x589c))();
      }
      local_40 = 0x26e;
      (**(code **)(local_38 + -0x6eb0))(AEPHK_lib_error_code,0x68,0x69,"e_aep.c");
      goto LAB_005cfcf0;
    }
    local_3c = 0;
    local_40 = param_2;
    iVar2 = (*p_AEP_ModExp)(local_30,param_3,param_4,param_5);
    if (iVar2 != 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(local_38 + -0x589c))();
      }
      pcStack_74 = "r";
      local_40 = 0x277;
      (**(code **)(local_38 + -0x6eb0))(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c");
      (**(code **)(local_38 + -0x6c74))(9,0x1e,"e_aep.c",0x3e2);
      piVar10 = (int *)(aep_app_conn_table + 4);
      iVar2 = 0;
      do {
        unaff_s7 = iVar2 + 1;
        if (local_30 == *piVar10) {
          iVar3 = (*p_AEP_CloseConnection)(local_30);
          unaff_s7 = iVar2;
          if (iVar3 == 0) {
            unaff_s7 = iVar2 * 8;
            *(undefined4 *)(aep_app_conn_table + unaff_s7) = 0;
            *(undefined4 *)(aep_app_conn_table + unaff_s7 + 4) = 0;
          }
          break;
        }
        piVar10 = piVar10 + 2;
        iVar2 = unaff_s7;
      } while (unaff_s7 != 0x100);
      (**(code **)(local_38 + -0x6c74))(10,0x1e,"e_aep.c",0x3f3);
      goto LAB_005cfcf0;
    }
    pcStack_74 = "r";
    (**(code **)(local_38 + -0x6c74))(9,0x1e,"e_aep.c",0x3cc);
    piVar10 = (int *)(aep_app_conn_table + 4);
    iVar2 = 0;
    do {
      iVar3 = iVar2 + 1;
      if (local_30 == *piVar10) {
        *(undefined4 *)(aep_app_conn_table + iVar2 * 8) = 1;
        break;
      }
      piVar10 = piVar10 + 2;
      iVar2 = iVar3;
    } while (iVar3 != 0x100);
    iVar2 = 0x3d8;
    pcVar13 = "e_aep.c";
    uVar11 = 0x1e;
    (**(code **)(local_38 + -0x6c74))(10);
    uVar4 = 1;
  }
  else {
    pcStack_74 = &_ITM_registerTMCloneTable;
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (**(code **)(local_38 + -0x589c))();
    }
    local_40 = 0x266;
    (**(code **)(local_38 + -0x6eb0))(AEPHK_lib_error_code,0x68,0x74,"e_aep.c");
LAB_005cfcf0:
    local_40 = param_6;
    uVar11 = param_3;
    pcVar13 = param_4;
    iVar2 = param_5;
    uVar4 = (**(code **)(local_38 + -0x7498))(param_2);
    local_30 = param_5;
  }
  if (local_2c == *(int *)puStack_78) {
    return uVar4;
  }
  pcStack_54 = aep_mod_exp_dsa;
  (**(code **)(local_38 + -0x5328))();
  uVar1 = local_3c;
  uVar4 = local_40;
  puVar12 = PTR___stack_chk_guard_006aabf0;
  uStack_60 = param_6;
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_70 = local_30;
  uStack_6c = param_2;
  uStack_68 = param_3;
  pcStack_64 = param_4;
  iStack_5c = unaff_s7;
  iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(local_40);
  if (iVar3 < 0x881) {
    iVar3 = aep_get_connection(&iStack_80);
    if (iVar3 == 0) {
      iVar3 = (*p_AEP_ModExp)(iStack_80,pcVar13,iVar2,uVar4,uVar11,0);
      if (iVar3 == 0) {
        (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_aep.c",0x3cc);
        piVar10 = (int *)(aep_app_conn_table + 4);
        iVar2 = 0;
        do {
          iVar3 = iVar2 + 1;
          if (iStack_80 == *piVar10) {
            *(undefined4 *)(aep_app_conn_table + iVar2 * 8) = 1;
            break;
          }
          piVar10 = piVar10 + 2;
          iVar2 = iVar3;
        } while (iVar3 != 0x100);
        (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"e_aep.c",0x3d8);
        uVar11 = 1;
        goto LAB_005d0034;
      }
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c",0x277);
      (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_aep.c",0x3e2);
      piVar10 = (int *)(aep_app_conn_table + 4);
      iVar3 = 0;
      do {
        iVar6 = iVar3 + 1;
        if (iStack_80 == *piVar10) {
          iVar6 = (*p_AEP_CloseConnection)(iStack_80);
          if (iVar6 == 0) {
            *(undefined4 *)(aep_app_conn_table + iVar3 * 8) = 0;
            *(undefined4 *)(aep_app_conn_table + iVar3 * 8 + 4) = 0;
          }
          break;
        }
        piVar10 = piVar10 + 2;
        iVar3 = iVar6;
      } while (iVar6 != 0x100);
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
  uVar11 = (*(code *)PTR_BN_mod_exp_006a8a48)(uVar11,pcVar13,iVar2,uVar4,uVar1);
LAB_005d0034:
  if (iStack_7c == *(int *)puVar12) {
    return uVar11;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (aep_dso == 0) {
    puVar12 = AEP_LIBNAME;
    if (AEP_LIBNAME == (undefined *)0x0) {
      puVar12 = &DAT_00673d78;
    }
    aep_dso = (*(code *)PTR_DSO_load_006a99a4)(0,puVar12,0,0);
    if (aep_dso == 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(AEPHK_lib_error_code,0x67,0x6f,"e_aep.c",0x1ca);
    }
    else {
      pcVar5 = (code *)(*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_ModExp");
      if ((((pcVar5 != (code *)0x0) &&
           (iVar2 = (*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_ModExpCrt"), iVar2 != 0)) &&
          (iVar3 = (*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_Finalize"), iVar3 != 0)) &&
         (((iVar6 = (*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_Initialize"), iVar6 != 0 &&
           (iVar7 = (*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_OpenConnection"), iVar7 != 0)
           ) && ((iVar8 = (*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_SetBNCallBacks"),
                 iVar8 != 0 &&
                 (pcVar9 = (code *)(*(code *)PTR_DSO_bind_func_006a99ac)
                                             (aep_dso,"AEP_CloseConnection"), pcVar9 != (code *)0x0)
                 ))))) {
        p_AEP_SetBNCallBacks = iVar8;
        p_AEP_Finalize = iVar3;
        p_AEP_Initialize = iVar6;
        p_AEP_ModExpCrt = iVar2;
        p_AEP_ModExp = pcVar5;
        p_AEP_CloseConnection = pcVar9;
        p_AEP_OpenConnection = iVar7;
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

