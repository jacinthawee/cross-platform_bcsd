
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 aep_mod_exp_mont(int param_1,undefined4 param_2,char *param_3,char *param_4,int param_5)

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
  char **ppcVar10;
  int *piVar11;
  char *pcVar12;
  undefined *puVar13;
  char *pcVar14;
  int unaff_s7;
  int iStack_d0;
  int iStack_cc;
  undefined *puStack_c8;
  char *pcStack_c4;
  int iStack_c0;
  undefined4 uStack_bc;
  char *pcStack_b8;
  char *pcStack_b4;
  undefined4 uStack_b0;
  int iStack_ac;
  code *pcStack_a4;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined *puStack_88;
  int iStack_80;
  int iStack_7c;
  undefined *puStack_78;
  char *pcStack_74;
  char *pcStack_70;
  int iStack_6c;
  undefined4 uStack_68;
  char *pcStack_64;
  int iStack_60;
  int iStack_5c;
  code *pcStack_54;
  int local_40;
  undefined4 local_3c;
  undefined *local_38;
  char *local_30;
  int local_2c;
  
  puStack_78 = PTR___stack_chk_guard_006aabf0;
  local_38 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(param_4);
  if (iVar2 < 0x881) {
    iVar2 = aep_get_connection(&local_30);
    if (iVar2 != 0) {
      pcStack_74 = &_ITM_registerTMCloneTable;
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(local_38 + -0x589c))();
      }
      local_40 = 0x26e;
      (**(code **)(local_38 + -0x6eb0))(AEPHK_lib_error_code,0x68,0x69,"e_aep.c");
      goto LAB_005cf9cc;
    }
    local_3c = 0;
    local_40 = param_1;
    iVar2 = (*p_AEP_ModExp)(local_30,param_2,param_3,param_4);
    if (iVar2 != 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(local_38 + -0x589c))();
      }
      pcStack_74 = "r";
      local_40 = 0x277;
      (**(code **)(local_38 + -0x6eb0))(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c");
      (**(code **)(local_38 + -0x6c74))(9,0x1e,"e_aep.c",0x3e2);
      ppcVar10 = (char **)(aep_app_conn_table + 4);
      iVar2 = 0;
      do {
        unaff_s7 = iVar2 + 1;
        if (local_30 == *ppcVar10) {
          iVar3 = (*p_AEP_CloseConnection)(local_30);
          unaff_s7 = iVar2;
          if (iVar3 == 0) {
            unaff_s7 = iVar2 * 8;
            *(undefined4 *)(aep_app_conn_table + unaff_s7) = 0;
            *(undefined4 *)(aep_app_conn_table + unaff_s7 + 4) = 0;
          }
          break;
        }
        ppcVar10 = ppcVar10 + 2;
        iVar2 = unaff_s7;
      } while (unaff_s7 != 0x100);
      (**(code **)(local_38 + -0x6c74))(10,0x1e,"e_aep.c",0x3f3);
      goto LAB_005cf9cc;
    }
    pcStack_74 = "r";
    (**(code **)(local_38 + -0x6c74))(9,0x1e,"e_aep.c",0x3cc);
    ppcVar10 = (char **)(aep_app_conn_table + 4);
    iVar2 = 0;
    do {
      iVar3 = iVar2 + 1;
      if (local_30 == *ppcVar10) {
        *(undefined4 *)(aep_app_conn_table + iVar2 * 8) = 1;
        break;
      }
      ppcVar10 = ppcVar10 + 2;
      iVar2 = iVar3;
    } while (iVar3 != 0x100);
    pcStack_b4 = (char *)0x3d8;
    pcStack_b8 = "e_aep.c";
    uStack_bc = 0x1e;
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
LAB_005cf9cc:
    local_40 = param_5;
    uStack_bc = param_2;
    pcStack_b8 = param_3;
    pcStack_b4 = param_4;
    uVar4 = (**(code **)(local_38 + -0x7498))(param_1);
    local_30 = param_4;
  }
  if (local_2c == *(int *)puStack_78) {
    return uVar4;
  }
  pcStack_54 = aep_mod_exp_dh;
  (**(code **)(local_38 + -0x5328))();
  uStack_b0 = local_3c;
  iStack_c0 = local_40;
  puStack_c8 = PTR___stack_chk_guard_006aabf0;
  iStack_60 = param_5;
  puStack_88 = &_gp;
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_70 = local_30;
  iStack_6c = param_1;
  uStack_68 = param_2;
  pcStack_64 = param_3;
  iStack_5c = unaff_s7;
  iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(local_40);
  if (iVar2 < 0x881) {
    iVar2 = aep_get_connection(&iStack_80);
    if (iVar2 != 0) {
      pcStack_c4 = &_ITM_registerTMCloneTable;
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(puStack_88 + -0x589c))();
      }
      uStack_90 = 0x26e;
      (**(code **)(puStack_88 + -0x6eb0))(AEPHK_lib_error_code,0x68,0x69,"e_aep.c");
      goto LAB_005cfcf0;
    }
    uStack_8c = 0;
    uStack_90 = uStack_bc;
    iVar2 = (*p_AEP_ModExp)(iStack_80,pcStack_b8,pcStack_b4,iStack_c0);
    if (iVar2 != 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(puStack_88 + -0x589c))();
      }
      pcStack_c4 = "r";
      uStack_90 = 0x277;
      (**(code **)(puStack_88 + -0x6eb0))(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c");
      (**(code **)(puStack_88 + -0x6c74))(9,0x1e,"e_aep.c",0x3e2);
      piVar11 = (int *)(aep_app_conn_table + 4);
      iVar2 = 0;
      do {
        unaff_s7 = iVar2 + 1;
        if (iStack_80 == *piVar11) {
          iVar3 = (*p_AEP_CloseConnection)(iStack_80);
          unaff_s7 = iVar2;
          if (iVar3 == 0) {
            unaff_s7 = iVar2 * 8;
            *(undefined4 *)(aep_app_conn_table + unaff_s7) = 0;
            *(undefined4 *)(aep_app_conn_table + unaff_s7 + 4) = 0;
          }
          break;
        }
        piVar11 = piVar11 + 2;
        iVar2 = unaff_s7;
      } while (unaff_s7 != 0x100);
      (**(code **)(puStack_88 + -0x6c74))(10,0x1e,"e_aep.c",0x3f3);
      goto LAB_005cfcf0;
    }
    pcStack_c4 = "r";
    (**(code **)(puStack_88 + -0x6c74))(9,0x1e,"e_aep.c",0x3cc);
    piVar11 = (int *)(aep_app_conn_table + 4);
    iVar2 = 0;
    do {
      iVar3 = iVar2 + 1;
      if (iStack_80 == *piVar11) {
        *(undefined4 *)(aep_app_conn_table + iVar2 * 8) = 1;
        break;
      }
      piVar11 = piVar11 + 2;
      iVar2 = iVar3;
    } while (iVar3 != 0x100);
    iVar2 = 0x3d8;
    pcVar14 = "e_aep.c";
    pcVar12 = (char *)0x1e;
    (**(code **)(puStack_88 + -0x6c74))(10);
    uVar4 = 1;
    iStack_c0 = iStack_80;
  }
  else {
    pcStack_c4 = &_ITM_registerTMCloneTable;
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (**(code **)(puStack_88 + -0x589c))();
    }
    uStack_90 = 0x266;
    (**(code **)(puStack_88 + -0x6eb0))(AEPHK_lib_error_code,0x68,0x74,"e_aep.c");
LAB_005cfcf0:
    uStack_90 = uStack_b0;
    pcVar12 = pcStack_b8;
    pcVar14 = pcStack_b4;
    iVar2 = iStack_c0;
    uVar4 = (**(code **)(puStack_88 + -0x7498))(uStack_bc);
  }
  if (iStack_7c == *(int *)puStack_c8) {
    return uVar4;
  }
  pcStack_a4 = aep_mod_exp_dsa;
  (**(code **)(puStack_88 + -0x5328))();
  uVar1 = uStack_8c;
  uVar4 = uStack_90;
  puVar13 = PTR___stack_chk_guard_006aabf0;
  iStack_cc = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_ac = unaff_s7;
  iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(uStack_90);
  if (iVar3 < 0x881) {
    iVar3 = aep_get_connection(&iStack_d0);
    if (iVar3 == 0) {
      iVar3 = (*p_AEP_ModExp)(iStack_d0,pcVar14,iVar2,uVar4,pcVar12,0);
      if (iVar3 == 0) {
        (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_aep.c",0x3cc);
        piVar11 = (int *)(aep_app_conn_table + 4);
        iVar2 = 0;
        do {
          iVar3 = iVar2 + 1;
          if (iStack_d0 == *piVar11) {
            *(undefined4 *)(aep_app_conn_table + iVar2 * 8) = 1;
            break;
          }
          piVar11 = piVar11 + 2;
          iVar2 = iVar3;
        } while (iVar3 != 0x100);
        (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"e_aep.c",0x3d8);
        uVar4 = 1;
        goto LAB_005d0034;
      }
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c",0x277);
      (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_aep.c",0x3e2);
      piVar11 = (int *)(aep_app_conn_table + 4);
      iVar3 = 0;
      do {
        iVar6 = iVar3 + 1;
        if (iStack_d0 == *piVar11) {
          iVar6 = (*p_AEP_CloseConnection)(iStack_d0);
          if (iVar6 == 0) {
            *(undefined4 *)(aep_app_conn_table + iVar3 * 8) = 0;
            *(undefined4 *)(aep_app_conn_table + iVar3 * 8 + 4) = 0;
          }
          break;
        }
        piVar11 = piVar11 + 2;
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
  uVar4 = (*(code *)PTR_BN_mod_exp_006a8a48)(pcVar12,pcVar14,iVar2,uVar4,uVar1);
LAB_005d0034:
  if (iStack_cc == *(int *)puVar13) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (aep_dso == 0) {
    puVar13 = AEP_LIBNAME;
    if (AEP_LIBNAME == (undefined *)0x0) {
      puVar13 = &DAT_00673d78;
    }
    aep_dso = (*(code *)PTR_DSO_load_006a99a4)(0,puVar13,0,0);
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

