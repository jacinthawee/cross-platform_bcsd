
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint aep_dsa_mod_exp(undefined4 param_1,undefined1 *param_2,undefined1 *param_3,char *param_4,
                    undefined1 *param_5,char *param_6,char *param_7,char *param_8)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  code *pcVar10;
  char **ppcVar11;
  int *piVar12;
  char *pcVar13;
  undefined *puVar14;
  char *pcVar15;
  char *pcVar16;
  int iStack_138;
  int iStack_134;
  undefined *puStack_130;
  char *pcStack_12c;
  char *pcStack_128;
  undefined1 *puStack_124;
  char *pcStack_120;
  char *pcStack_11c;
  undefined1 *puStack_118;
  char *pcStack_114;
  char *pcStack_110;
  code *pcStack_10c;
  undefined1 *puStack_f8;
  undefined4 uStack_f4;
  undefined *puStack_f0;
  char *pcStack_e8;
  int iStack_e4;
  undefined *puStack_e0;
  char *pcStack_dc;
  char *pcStack_d8;
  char *pcStack_d4;
  undefined1 *puStack_d0;
  char *pcStack_cc;
  char *pcStack_c8;
  char *pcStack_c4;
  char *pcStack_c0;
  code *pcStack_bc;
  char *pcStack_a8;
  undefined1 *puStack_a4;
  undefined *puStack_a0;
  char *pcStack_98;
  int iStack_94;
  uint uStack_90;
  char *pcStack_8c;
  undefined *puStack_88;
  char *pcStack_84;
  undefined1 *puStack_80;
  undefined1 *puStack_7c;
  undefined1 *puStack_78;
  char *pcStack_74;
  char *pcStack_70;
  code *pcStack_6c;
  char *local_58;
  undefined *local_50;
  undefined1 *local_44;
  char acStack_40 [20];
  char *local_2c;
  
  puStack_88 = PTR___stack_chk_guard_006aabf0;
  pcStack_8c = acStack_40;
  local_50 = &_gp;
  local_2c = *(char **)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_BN_init_006a96a0)(pcStack_8c);
  iVar3 = (**(code **)(local_50 + -0x7bec))(param_7);
  puStack_d0 = param_3;
  pcStack_cc = param_4;
  pcVar13 = param_7;
  if (iVar3 < 0x881) {
    local_58 = param_8;
    iVar3 = aep_mod_exp_part_0(param_2);
    if (iVar3 == 0) goto LAB_005cf6a8;
    pcVar6 = *(code **)(local_50 + -0x7bec);
LAB_005cf700:
    iVar3 = (*pcVar6)(param_7);
    puStack_d0 = param_5;
    pcStack_cc = param_6;
    if (iVar3 < 0x881) {
      local_58 = param_8;
      pcVar13 = param_7;
      iVar3 = aep_mod_exp_part_0(pcStack_8c);
      if (iVar3 == 0) goto LAB_005cf6a8;
      pcVar6 = *(code **)(local_50 + -0x6848);
    }
    else {
      param_3 = &_ITM_registerTMCloneTable;
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(local_50 + -0x589c))();
      }
      local_58 = (char *)0x266;
      (**(code **)(local_50 + -0x6eb0))(AEPHK_lib_error_code,0x68,0x74,"e_aep.c");
      local_58 = param_8;
      pcVar13 = param_7;
      iVar3 = (**(code **)(local_50 + -0x7498))(pcStack_8c);
      if (iVar3 == 0) goto LAB_005cf6a8;
      pcVar6 = *(code **)(local_50 + -0x6848);
    }
    local_58 = param_8;
    puStack_d0 = param_2;
    pcStack_cc = pcStack_8c;
    iVar3 = (*pcVar6)(param_2);
    uStack_90 = (uint)(iVar3 != 0);
  }
  else {
    iVar3 = AEPHK_lib_error_code;
    if (AEPHK_lib_error_code == 0) {
      local_44 = &_ITM_registerTMCloneTable;
      iVar3 = (**(code **)(local_50 + -0x589c))();
      *(int *)(local_44 + -0xba8) = iVar3;
    }
    local_58 = (char *)0x266;
    (**(code **)(local_50 + -0x6eb0))(iVar3,0x68,0x74,"e_aep.c");
    local_58 = param_8;
    iVar3 = (**(code **)(local_50 + -0x7498))(param_2);
    if (iVar3 != 0) {
      pcVar6 = *(code **)(local_50 + -0x7bec);
      goto LAB_005cf700;
    }
LAB_005cf6a8:
    uStack_90 = 0;
    param_7 = pcVar13;
  }
  (**(code **)(local_50 + -0x7dc4))(pcStack_8c);
  if (local_2c == *(char **)puStack_88) {
    return uStack_90;
  }
  pcStack_6c = aep_mod_exp_mont;
  pcStack_d4 = local_2c;
  (**(code **)(local_50 + -0x5328))();
  pcStack_c8 = local_58;
  puStack_e0 = PTR___stack_chk_guard_006aabf0;
  puStack_78 = param_5;
  pcStack_84 = param_8;
  puStack_a0 = &_gp;
  pcStack_74 = param_6;
  iStack_94 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_80 = param_2;
  puStack_7c = param_3;
  pcStack_70 = param_4;
  iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(param_7);
  if (iVar3 < 0x881) {
    iVar3 = aep_get_connection(&pcStack_98);
    if (iVar3 != 0) {
      pcStack_dc = &_ITM_registerTMCloneTable;
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(puStack_a0 + -0x589c))();
      }
      pcStack_a8 = (char *)0x26e;
      (**(code **)(puStack_a0 + -0x6eb0))(AEPHK_lib_error_code,0x68,0x69,"e_aep.c");
      goto LAB_005cf9cc;
    }
    puStack_a4 = (undefined1 *)0x0;
    pcStack_a8 = pcStack_d4;
    iVar3 = (*p_AEP_ModExp)(pcStack_98,puStack_d0,pcStack_cc,param_7);
    if (iVar3 != 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(puStack_a0 + -0x589c))();
      }
      pcStack_dc = "7 datafinal";
      pcStack_a8 = (char *)0x277;
      (**(code **)(puStack_a0 + -0x6eb0))(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c");
      (**(code **)(puStack_a0 + -0x6c74))(9,0x1e,"e_aep.c",0x3e2);
      ppcVar11 = (char **)(aep_app_conn_table + 4);
      pcVar13 = (char *)0x0;
      do {
        param_6 = pcVar13 + 1;
        if (pcStack_98 == *ppcVar11) {
          iVar3 = (*p_AEP_CloseConnection)(pcStack_98);
          param_6 = pcVar13;
          if (iVar3 == 0) {
            param_6 = (char *)((int)pcVar13 * 8);
            *(undefined4 *)(param_6 + 0x6aec58) = 0;
            *(undefined4 *)(param_6 + 0x6aec5c) = 0;
          }
          break;
        }
        ppcVar11 = ppcVar11 + 2;
        pcVar13 = param_6;
      } while (param_6 != (char *)0x100);
      (**(code **)(puStack_a0 + -0x6c74))(10,0x1e,"e_aep.c",0x3f3);
      param_4 = pcStack_98;
      goto LAB_005cf9cc;
    }
    pcStack_dc = "7 datafinal";
    (**(code **)(puStack_a0 + -0x6c74))(9,0x1e,"e_aep.c",0x3cc);
    ppcVar11 = (char **)(aep_app_conn_table + 4);
    iVar3 = 0;
    do {
      iVar4 = iVar3 + 1;
      if (pcStack_98 == *ppcVar11) {
        *(undefined4 *)(aep_app_conn_table + iVar3 * 8) = 1;
        break;
      }
      ppcVar11 = ppcVar11 + 2;
      iVar3 = iVar4;
    } while (iVar4 != 0x100);
    pcStack_11c = (char *)0x3d8;
    pcStack_120 = "e_aep.c";
    puStack_124 = (undefined1 *)0x1e;
    (**(code **)(puStack_a0 + -0x6c74))(10);
    uVar5 = 1;
  }
  else {
    pcStack_dc = &_ITM_registerTMCloneTable;
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (**(code **)(puStack_a0 + -0x589c))();
    }
    pcStack_a8 = (char *)0x266;
    (**(code **)(puStack_a0 + -0x6eb0))(AEPHK_lib_error_code,0x68,0x74,"e_aep.c");
LAB_005cf9cc:
    pcStack_a8 = pcStack_c8;
    puStack_124 = puStack_d0;
    pcStack_120 = pcStack_cc;
    pcStack_11c = param_7;
    uVar5 = (**(code **)(puStack_a0 + -0x7498))(pcStack_d4);
    pcStack_98 = param_7;
  }
  if (iStack_94 == *(int *)puStack_e0) {
    return uVar5;
  }
  pcStack_bc = aep_mod_exp_dh;
  (**(code **)(puStack_a0 + -0x5328))();
  puStack_118 = puStack_a4;
  pcStack_128 = pcStack_a8;
  puStack_130 = PTR___stack_chk_guard_006aabf0;
  puStack_f0 = &_gp;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_d8 = pcStack_98;
  pcStack_c4 = param_6;
  pcStack_c0 = param_4;
  iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(pcStack_a8);
  if (iVar3 < 0x881) {
    iVar3 = aep_get_connection(&pcStack_e8);
    if (iVar3 != 0) {
      pcStack_12c = &_ITM_registerTMCloneTable;
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(puStack_f0 + -0x589c))();
      }
      puStack_f8 = (undefined1 *)0x26e;
      (**(code **)(puStack_f0 + -0x6eb0))(AEPHK_lib_error_code,0x68,0x69,"e_aep.c");
      goto LAB_005cfcf0;
    }
    uStack_f4 = 0;
    puStack_f8 = puStack_124;
    iVar3 = (*p_AEP_ModExp)(pcStack_e8,pcStack_120,pcStack_11c,pcStack_128);
    if (iVar3 != 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(puStack_f0 + -0x589c))();
      }
      pcStack_12c = "7 datafinal";
      puStack_f8 = (undefined1 *)0x277;
      (**(code **)(puStack_f0 + -0x6eb0))(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c");
      (**(code **)(puStack_f0 + -0x6c74))(9,0x1e,"e_aep.c",0x3e2);
      ppcVar11 = (char **)(aep_app_conn_table + 4);
      pcVar13 = (char *)0x0;
      do {
        param_6 = pcVar13 + 1;
        if (pcStack_e8 == *ppcVar11) {
          iVar3 = (*p_AEP_CloseConnection)(pcStack_e8);
          param_6 = pcVar13;
          if (iVar3 == 0) {
            param_6 = (char *)((int)pcVar13 * 8);
            *(undefined4 *)(param_6 + 0x6aec58) = 0;
            *(undefined4 *)(param_6 + 0x6aec5c) = 0;
          }
          break;
        }
        ppcVar11 = ppcVar11 + 2;
        pcVar13 = param_6;
      } while (param_6 != (char *)0x100);
      (**(code **)(puStack_f0 + -0x6c74))(10,0x1e,"e_aep.c",0x3f3);
      param_4 = pcStack_e8;
      goto LAB_005cfcf0;
    }
    pcStack_12c = "7 datafinal";
    (**(code **)(puStack_f0 + -0x6c74))(9,0x1e,"e_aep.c",0x3cc);
    ppcVar11 = (char **)(aep_app_conn_table + 4);
    iVar3 = 0;
    do {
      iVar4 = iVar3 + 1;
      if (pcStack_e8 == *ppcVar11) {
        *(undefined4 *)(aep_app_conn_table + iVar3 * 8) = 1;
        break;
      }
      ppcVar11 = ppcVar11 + 2;
      iVar3 = iVar4;
    } while (iVar4 != 0x100);
    pcVar16 = (char *)0x3d8;
    pcVar15 = "e_aep.c";
    pcVar13 = (char *)0x1e;
    (**(code **)(puStack_f0 + -0x6c74))(10);
    uVar5 = 1;
    pcStack_128 = pcStack_e8;
  }
  else {
    pcStack_12c = &_ITM_registerTMCloneTable;
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (**(code **)(puStack_f0 + -0x589c))();
    }
    puStack_f8 = (undefined1 *)0x266;
    (**(code **)(puStack_f0 + -0x6eb0))(AEPHK_lib_error_code,0x68,0x74,"e_aep.c");
LAB_005cfcf0:
    puStack_f8 = puStack_118;
    pcVar13 = pcStack_120;
    pcVar15 = pcStack_11c;
    pcVar16 = pcStack_128;
    uVar5 = (**(code **)(puStack_f0 + -0x7498))(puStack_124);
  }
  if (iStack_e4 == *(int *)puStack_130) {
    return uVar5;
  }
  pcStack_10c = aep_mod_exp_dsa;
  (**(code **)(puStack_f0 + -0x5328))();
  uVar2 = uStack_f4;
  puVar1 = puStack_f8;
  puVar14 = PTR___stack_chk_guard_006aabf0;
  iStack_134 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_114 = param_6;
  pcStack_110 = param_4;
  iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(puStack_f8);
  if (iVar3 < 0x881) {
    iVar3 = aep_get_connection(&iStack_138);
    if (iVar3 == 0) {
      iVar3 = (*p_AEP_ModExp)(iStack_138,pcVar15,pcVar16,puVar1,pcVar13,0);
      if (iVar3 == 0) {
        (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_aep.c",0x3cc);
        piVar12 = (int *)(aep_app_conn_table + 4);
        iVar3 = 0;
        do {
          iVar4 = iVar3 + 1;
          if (iStack_138 == *piVar12) {
            *(undefined4 *)(aep_app_conn_table + iVar3 * 8) = 1;
            break;
          }
          piVar12 = piVar12 + 2;
          iVar3 = iVar4;
        } while (iVar4 != 0x100);
        (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"e_aep.c",0x3d8);
        uVar5 = 1;
        goto LAB_005d0034;
      }
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c",0x277);
      (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_aep.c",0x3e2);
      piVar12 = (int *)(aep_app_conn_table + 4);
      iVar3 = 0;
      do {
        iVar4 = iVar3 + 1;
        if (iStack_138 == *piVar12) {
          iVar4 = (*p_AEP_CloseConnection)(iStack_138);
          if (iVar4 == 0) {
            *(undefined4 *)(aep_app_conn_table + iVar3 * 8) = 0;
            *(undefined4 *)(aep_app_conn_table + iVar3 * 8 + 4) = 0;
          }
          break;
        }
        piVar12 = piVar12 + 2;
        iVar3 = iVar4;
      } while (iVar4 != 0x100);
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
  uVar5 = (*(code *)PTR_BN_mod_exp_006a8a48)(pcVar13,pcVar15,pcVar16,puVar1,uVar2);
LAB_005d0034:
  if (iStack_134 == *(int *)puVar14) {
    return uVar5;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (aep_dso == 0) {
    puVar14 = AEP_LIBNAME;
    if (AEP_LIBNAME == (undefined *)0x0) {
      puVar14 = &DAT_00673d98;
    }
    aep_dso = (*(code *)PTR_DSO_load_006a99a4)(0,puVar14,0,0);
    if (aep_dso == 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(AEPHK_lib_error_code,0x67,0x6f,"e_aep.c",0x1ca);
    }
    else {
      pcVar6 = (code *)(*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_ModExp");
      if ((((pcVar6 != (code *)0x0) &&
           (iVar3 = (*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_ModExpCrt"), iVar3 != 0)) &&
          (iVar4 = (*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_Finalize"), iVar4 != 0)) &&
         (((iVar7 = (*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_Initialize"), iVar7 != 0 &&
           (iVar8 = (*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_OpenConnection"), iVar8 != 0)
           ) && ((iVar9 = (*(code *)PTR_DSO_bind_func_006a99ac)(aep_dso,"AEP_SetBNCallBacks"),
                 iVar9 != 0 &&
                 (pcVar10 = (code *)(*(code *)PTR_DSO_bind_func_006a99ac)
                                              (aep_dso,"AEP_CloseConnection"),
                 pcVar10 != (code *)0x0)))))) {
        p_AEP_SetBNCallBacks = iVar9;
        p_AEP_Finalize = iVar4;
        p_AEP_Initialize = iVar7;
        p_AEP_ModExpCrt = iVar3;
        p_AEP_ModExp = pcVar6;
        p_AEP_CloseConnection = pcVar10;
        p_AEP_OpenConnection = iVar8;
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

