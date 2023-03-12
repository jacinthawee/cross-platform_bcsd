
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint aep_mod_exp_part_0(char *param_1,char *param_2,char *param_3,char *param_4,char *param_5)

{
  char *pcVar1;
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
  int unaff_s7;
  int iStack_188;
  int iStack_184;
  undefined *puStack_180;
  char *pcStack_17c;
  char *pcStack_178;
  char *pcStack_174;
  char *pcStack_170;
  char *pcStack_16c;
  char *pcStack_168;
  char *pcStack_164;
  char *pcStack_160;
  code *pcStack_15c;
  char *pcStack_148;
  undefined4 uStack_144;
  undefined *puStack_140;
  char *pcStack_138;
  int iStack_134;
  undefined *puStack_130;
  char *pcStack_12c;
  char *pcStack_128;
  char *pcStack_124;
  char *pcStack_120;
  char *pcStack_11c;
  char *pcStack_118;
  char *pcStack_114;
  char *pcStack_110;
  code *pcStack_10c;
  char *pcStack_f8;
  char *pcStack_f4;
  undefined *puStack_f0;
  char *pcStack_e8;
  int iStack_e4;
  uint uStack_e0;
  char *pcStack_dc;
  undefined *puStack_d8;
  char *pcStack_d4;
  char *pcStack_d0;
  char *pcStack_cc;
  char *pcStack_c8;
  char *pcStack_c4;
  char *pcStack_c0;
  code *pcStack_bc;
  char *pcStack_a8;
  undefined *puStack_a0;
  undefined *puStack_94;
  char acStack_90 [20];
  char *pcStack_7c;
  undefined *puStack_78;
  char *pcStack_74;
  char *pcStack_70;
  char *pcStack_6c;
  char *pcStack_68;
  char *pcStack_64;
  char *pcStack_60;
  int iStack_5c;
  code *pcStack_54;
  char *local_40;
  char *local_3c;
  char *local_38;
  char *pcStack_34;
  char *local_30;
  int local_2c;
  
  puStack_78 = PTR___stack_chk_guard_006a9ae8;
  local_38 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = aep_get_connection(&local_30);
  if (iVar3 == 0) {
    local_3c = (char *)0x0;
    local_40 = param_1;
    iVar3 = (*p_AEP_ModExp)(local_30,param_2,param_3,param_4);
    if (iVar3 != 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(local_38 + -0x58a8))();
      }
      pcStack_74 = "encrypt";
      local_40 = (char *)0x279;
      (**(code **)(local_38 + -0x6eac))(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c");
      (**(code **)(local_38 + -0x6c9c))(9,0x1e,"e_aep.c",0x3f2);
      ppcVar11 = (char **)(aep_app_conn_table + 4);
      iVar3 = 0;
      do {
        unaff_s7 = iVar3 + 1;
        if (local_30 == *ppcVar11) {
          iVar4 = (*p_AEP_CloseConnection)(local_30);
          unaff_s7 = iVar3;
          if (iVar4 == 0) {
            unaff_s7 = iVar3 * 8;
            *(undefined4 *)(aep_app_conn_table + unaff_s7) = 0;
            *(undefined4 *)(aep_app_conn_table + unaff_s7 + 4) = 0;
          }
          break;
        }
        ppcVar11 = ppcVar11 + 2;
        iVar3 = unaff_s7;
      } while (unaff_s7 != 0x100);
      (**(code **)(local_38 + -0x6c9c))(10,0x1e,"e_aep.c",0x403);
      goto LAB_005ccfe0;
    }
    pcStack_74 = "encrypt";
    (**(code **)(local_38 + -0x6c9c))(9,0x1e,"e_aep.c",0x3dc);
    ppcVar11 = (char **)(aep_app_conn_table + 4);
    iVar3 = 0;
    do {
      iVar4 = iVar3 + 1;
      if (local_30 == *ppcVar11) {
        *(undefined4 *)(aep_app_conn_table + iVar3 * 8) = 1;
        break;
      }
      ppcVar11 = ppcVar11 + 2;
      iVar3 = iVar4;
    } while (iVar4 != 0x100);
    pcStack_160 = (char *)0x3e8;
    pcStack_cc = "e_aep.c";
    pcStack_d0 = (char *)0x1e;
    (**(code **)(local_38 + -0x6c9c))(10);
    uVar5 = 1;
  }
  else {
    pcStack_74 = &_gp_1;
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (**(code **)(local_38 + -0x58a8))();
    }
    local_40 = (char *)0x26e;
    (**(code **)(local_38 + -0x6eac))(AEPHK_lib_error_code,0x68,0x69,"e_aep.c");
LAB_005ccfe0:
    local_40 = param_5;
    pcStack_d0 = param_2;
    pcStack_cc = param_3;
    pcStack_160 = param_4;
    uVar5 = (**(code **)(local_38 + -0x7484))(param_1);
    local_30 = param_1;
  }
  if (local_2c == *(int *)puStack_78) {
    return uVar5;
  }
  pcStack_54 = aep_dsa_mod_exp;
  (**(code **)(local_38 + -0x5330))();
  pcStack_128 = local_38;
  pcStack_164 = local_3c;
  pcStack_c8 = local_40;
  puStack_d8 = PTR___stack_chk_guard_006a9ae8;
  pcStack_dc = acStack_90;
  pcStack_60 = param_5;
  puStack_a0 = &_gp;
  pcStack_7c = *(char **)PTR___stack_chk_guard_006a9ae8;
  pcStack_70 = local_30;
  pcStack_6c = param_2;
  pcStack_68 = param_3;
  pcStack_64 = param_4;
  iStack_5c = unaff_s7;
  (*(code *)PTR_BN_init_006a857c)(pcStack_dc);
  iVar3 = (**(code **)(puStack_a0 + -0x7bec))(pcStack_128);
  pcStack_120 = pcStack_cc;
  pcStack_11c = pcStack_160;
  pcVar13 = pcStack_128;
  if (iVar3 < 0x881) {
    pcStack_a8 = pcStack_34;
    iVar3 = aep_mod_exp_part_0(pcStack_d0);
    if (iVar3 == 0) goto LAB_005cd0d8;
    pcVar6 = *(code **)(puStack_a0 + -0x7bec);
LAB_005cd130:
    iVar3 = (*pcVar6)(pcStack_128);
    pcStack_120 = pcStack_c8;
    pcStack_11c = pcStack_164;
    if (iVar3 < 0x881) {
      pcStack_a8 = pcStack_34;
      pcVar13 = pcStack_128;
      iVar3 = aep_mod_exp_part_0(pcStack_dc);
      if (iVar3 == 0) goto LAB_005cd0d8;
      pcVar6 = *(code **)(puStack_a0 + -0x686c);
    }
    else {
      pcStack_cc = &_gp_1;
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(puStack_a0 + -0x58a8))();
      }
      pcStack_a8 = (char *)0x265;
      (**(code **)(puStack_a0 + -0x6eac))(AEPHK_lib_error_code,0x68,0x74,"e_aep.c");
      pcStack_a8 = pcStack_34;
      pcVar13 = pcStack_128;
      iVar3 = (**(code **)(puStack_a0 + -0x7484))(pcStack_dc);
      if (iVar3 == 0) goto LAB_005cd0d8;
      pcVar6 = *(code **)(puStack_a0 + -0x686c);
    }
    pcStack_a8 = pcStack_34;
    pcStack_120 = pcStack_d0;
    pcStack_11c = pcStack_dc;
    iVar3 = (*pcVar6)(pcStack_d0);
    uStack_e0 = (uint)(iVar3 != 0);
  }
  else {
    iVar3 = AEPHK_lib_error_code;
    if (AEPHK_lib_error_code == 0) {
      puStack_94 = &_gp_1;
      iVar3 = (**(code **)(puStack_a0 + -0x58a8))();
      *(int *)(puStack_94 + -0x1d78) = iVar3;
    }
    pcStack_a8 = (char *)0x265;
    (**(code **)(puStack_a0 + -0x6eac))(iVar3,0x68,0x74,"e_aep.c");
    pcStack_a8 = pcStack_34;
    iVar3 = (**(code **)(puStack_a0 + -0x7484))(pcStack_d0);
    if (iVar3 != 0) {
      pcVar6 = *(code **)(puStack_a0 + -0x7bec);
      goto LAB_005cd130;
    }
LAB_005cd0d8:
    uStack_e0 = 0;
    pcStack_128 = pcVar13;
  }
  (**(code **)(puStack_a0 + -0x7dc4))(pcStack_dc);
  if (pcStack_7c == *(char **)puStack_d8) {
    return uStack_e0;
  }
  pcStack_bc = aep_mod_exp_mont;
  pcStack_124 = pcStack_7c;
  (**(code **)(puStack_a0 + -0x5330))();
  pcStack_118 = pcStack_a8;
  puStack_130 = PTR___stack_chk_guard_006a9ae8;
  pcStack_d4 = pcStack_34;
  puStack_f0 = &_gp;
  pcStack_c4 = pcStack_164;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcStack_c0 = pcStack_160;
  iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(pcStack_128);
  if (iVar3 < 0x881) {
    iVar3 = aep_get_connection(&pcStack_e8);
    if (iVar3 != 0) {
      pcStack_12c = &_gp_1;
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(puStack_f0 + -0x58a8))();
      }
      pcStack_f8 = (char *)0x26e;
      (**(code **)(puStack_f0 + -0x6eac))(AEPHK_lib_error_code,0x68,0x69,"e_aep.c");
      goto LAB_005cd3fc;
    }
    pcStack_f4 = (char *)0x0;
    pcStack_f8 = pcStack_124;
    iVar3 = (*p_AEP_ModExp)(pcStack_e8,pcStack_120,pcStack_11c,pcStack_128);
    if (iVar3 != 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(puStack_f0 + -0x58a8))();
      }
      pcStack_12c = "encrypt";
      pcStack_f8 = (char *)0x279;
      (**(code **)(puStack_f0 + -0x6eac))(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c");
      (**(code **)(puStack_f0 + -0x6c9c))(9,0x1e,"e_aep.c",0x3f2);
      ppcVar11 = (char **)(aep_app_conn_table + 4);
      pcVar13 = (char *)0x0;
      do {
        pcStack_164 = pcVar13 + 1;
        if (pcStack_e8 == *ppcVar11) {
          iVar3 = (*p_AEP_CloseConnection)(pcStack_e8);
          pcStack_164 = pcVar13;
          if (iVar3 == 0) {
            pcStack_164 = (char *)((int)pcVar13 * 8);
            *(undefined4 *)(pcStack_164 + 0x6ada88) = 0;
            *(undefined4 *)(pcStack_164 + 0x6ada8c) = 0;
          }
          break;
        }
        ppcVar11 = ppcVar11 + 2;
        pcVar13 = pcStack_164;
      } while (pcStack_164 != (char *)0x100);
      (**(code **)(puStack_f0 + -0x6c9c))(10,0x1e,"e_aep.c",0x403);
      pcStack_160 = pcStack_e8;
      goto LAB_005cd3fc;
    }
    pcStack_12c = "encrypt";
    (**(code **)(puStack_f0 + -0x6c9c))(9,0x1e,"e_aep.c",0x3dc);
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
    pcStack_16c = (char *)0x3e8;
    pcStack_170 = "e_aep.c";
    pcStack_174 = (char *)0x1e;
    (**(code **)(puStack_f0 + -0x6c9c))(10);
    uVar5 = 1;
    pcStack_128 = pcStack_e8;
  }
  else {
    pcStack_12c = &_gp_1;
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (**(code **)(puStack_f0 + -0x58a8))();
    }
    pcStack_f8 = (char *)0x265;
    (**(code **)(puStack_f0 + -0x6eac))(AEPHK_lib_error_code,0x68,0x74,"e_aep.c");
LAB_005cd3fc:
    pcStack_f8 = pcStack_118;
    pcStack_174 = pcStack_120;
    pcStack_170 = pcStack_11c;
    pcStack_16c = pcStack_128;
    uVar5 = (**(code **)(puStack_f0 + -0x7484))(pcStack_124);
  }
  if (iStack_e4 == *(int *)puStack_130) {
    return uVar5;
  }
  pcStack_10c = aep_mod_exp_dh;
  (**(code **)(puStack_f0 + -0x5330))();
  pcStack_168 = pcStack_f4;
  pcStack_178 = pcStack_f8;
  puStack_180 = PTR___stack_chk_guard_006a9ae8;
  puStack_140 = &_gp;
  iStack_134 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcStack_114 = pcStack_164;
  pcStack_110 = pcStack_160;
  iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(pcStack_f8);
  if (iVar3 < 0x881) {
    iVar3 = aep_get_connection(&pcStack_138);
    if (iVar3 != 0) {
      pcStack_17c = &_gp_1;
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(puStack_140 + -0x58a8))();
      }
      pcStack_148 = (char *)0x26e;
      (**(code **)(puStack_140 + -0x6eac))(AEPHK_lib_error_code,0x68,0x69,"e_aep.c");
      goto LAB_005cd720;
    }
    uStack_144 = 0;
    pcStack_148 = pcStack_174;
    iVar3 = (*p_AEP_ModExp)(pcStack_138,pcStack_170,pcStack_16c,pcStack_178);
    if (iVar3 != 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (**(code **)(puStack_140 + -0x58a8))();
      }
      pcStack_17c = "encrypt";
      pcStack_148 = (char *)0x279;
      (**(code **)(puStack_140 + -0x6eac))(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c");
      (**(code **)(puStack_140 + -0x6c9c))(9,0x1e,"e_aep.c",0x3f2);
      ppcVar11 = (char **)(aep_app_conn_table + 4);
      pcVar13 = (char *)0x0;
      do {
        pcStack_164 = pcVar13 + 1;
        if (pcStack_138 == *ppcVar11) {
          iVar3 = (*p_AEP_CloseConnection)(pcStack_138);
          pcStack_164 = pcVar13;
          if (iVar3 == 0) {
            pcStack_164 = (char *)((int)pcVar13 * 8);
            *(undefined4 *)(pcStack_164 + 0x6ada88) = 0;
            *(undefined4 *)(pcStack_164 + 0x6ada8c) = 0;
          }
          break;
        }
        ppcVar11 = ppcVar11 + 2;
        pcVar13 = pcStack_164;
      } while (pcStack_164 != (char *)0x100);
      (**(code **)(puStack_140 + -0x6c9c))(10,0x1e,"e_aep.c",0x403);
      pcStack_160 = pcStack_138;
      goto LAB_005cd720;
    }
    pcStack_17c = "encrypt";
    (**(code **)(puStack_140 + -0x6c9c))(9,0x1e,"e_aep.c",0x3dc);
    ppcVar11 = (char **)(aep_app_conn_table + 4);
    iVar3 = 0;
    do {
      iVar4 = iVar3 + 1;
      if (pcStack_138 == *ppcVar11) {
        *(undefined4 *)(aep_app_conn_table + iVar3 * 8) = 1;
        break;
      }
      ppcVar11 = ppcVar11 + 2;
      iVar3 = iVar4;
    } while (iVar4 != 0x100);
    pcVar16 = (char *)0x3e8;
    pcVar15 = "e_aep.c";
    pcVar13 = (char *)0x1e;
    (**(code **)(puStack_140 + -0x6c9c))(10);
    uVar5 = 1;
    pcStack_178 = pcStack_138;
  }
  else {
    pcStack_17c = &_gp_1;
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (**(code **)(puStack_140 + -0x58a8))();
    }
    pcStack_148 = (char *)0x265;
    (**(code **)(puStack_140 + -0x6eac))(AEPHK_lib_error_code,0x68,0x74,"e_aep.c");
LAB_005cd720:
    pcStack_148 = pcStack_168;
    pcVar13 = pcStack_170;
    pcVar15 = pcStack_16c;
    pcVar16 = pcStack_178;
    uVar5 = (**(code **)(puStack_140 + -0x7484))(pcStack_174);
  }
  if (iStack_134 == *(int *)puStack_180) {
    return uVar5;
  }
  pcStack_15c = aep_mod_exp_dsa;
  (**(code **)(puStack_140 + -0x5330))();
  uVar2 = uStack_144;
  pcVar1 = pcStack_148;
  puVar14 = PTR___stack_chk_guard_006a9ae8;
  iStack_184 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(pcStack_148);
  if (iVar3 < 0x881) {
    iVar3 = aep_get_connection(&iStack_188);
    if (iVar3 == 0) {
      iVar3 = (*p_AEP_ModExp)(iStack_188,pcVar15,pcVar16,pcVar1,pcVar13,0);
      if (iVar3 == 0) {
        (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_aep.c",0x3dc);
        piVar12 = (int *)(aep_app_conn_table + 4);
        iVar3 = 0;
        do {
          iVar4 = iVar3 + 1;
          if (iStack_188 == *piVar12) {
            *(undefined4 *)(aep_app_conn_table + iVar3 * 8) = 1;
            break;
          }
          piVar12 = piVar12 + 2;
          iVar3 = iVar4;
        } while (iVar4 != 0x100);
        (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"e_aep.c",1000);
        uVar5 = 1;
        goto LAB_005cda64;
      }
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x68,0x6e,"e_aep.c",0x279);
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_aep.c",0x3f2);
      piVar12 = (int *)(aep_app_conn_table + 4);
      iVar3 = 0;
      do {
        iVar4 = iVar3 + 1;
        if (iStack_188 == *piVar12) {
          iVar4 = (*p_AEP_CloseConnection)(iStack_188);
          if (iVar4 == 0) {
            *(undefined4 *)(aep_app_conn_table + iVar3 * 8) = 0;
            *(undefined4 *)(aep_app_conn_table + iVar3 * 8 + 4) = 0;
          }
          break;
        }
        piVar12 = piVar12 + 2;
        iVar3 = iVar4;
      } while (iVar4 != 0x100);
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"e_aep.c",0x403);
    }
    else {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x68,0x69,"e_aep.c",0x26e);
    }
  }
  else {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x68,0x74,"e_aep.c",0x265);
  }
  uVar5 = (*(code *)PTR_BN_mod_exp_006a795c)(pcVar13,pcVar15,pcVar16,pcVar1,uVar2);
LAB_005cda64:
  if (iStack_184 == *(int *)puVar14) {
    return uVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (aep_dso == 0) {
    puVar14 = AEP_LIBNAME;
    if (AEP_LIBNAME == (undefined *)0x0) {
      puVar14 = &DAT_00673488;
    }
    aep_dso = (*(code *)PTR_DSO_load_006a8884)(0,puVar14,0,0);
    if (aep_dso == 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x67,0x6f,"e_aep.c",0x1d4);
    }
    else {
      pcVar6 = (code *)(*(code *)PTR_DSO_bind_func_006a888c)(aep_dso,"AEP_ModExp");
      if ((((pcVar6 != (code *)0x0) &&
           (iVar3 = (*(code *)PTR_DSO_bind_func_006a888c)(aep_dso,"AEP_ModExpCrt"), iVar3 != 0)) &&
          (iVar4 = (*(code *)PTR_DSO_bind_func_006a888c)(aep_dso,"AEP_Finalize"), iVar4 != 0)) &&
         (((iVar7 = (*(code *)PTR_DSO_bind_func_006a888c)(aep_dso,"AEP_Initialize"), iVar7 != 0 &&
           (iVar8 = (*(code *)PTR_DSO_bind_func_006a888c)(aep_dso,"AEP_OpenConnection"), iVar8 != 0)
           ) && ((iVar9 = (*(code *)PTR_DSO_bind_func_006a888c)(aep_dso,"AEP_SetBNCallBacks"),
                 iVar9 != 0 &&
                 (pcVar10 = (code *)(*(code *)PTR_DSO_bind_func_006a888c)
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
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x67,0x6f,"e_aep.c",0x1e2);
    }
  }
  else {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x67,100,"e_aep.c",0x1cc);
  }
  if (aep_dso != 0) {
    (*(code *)PTR_DSO_free_006a8874)();
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

