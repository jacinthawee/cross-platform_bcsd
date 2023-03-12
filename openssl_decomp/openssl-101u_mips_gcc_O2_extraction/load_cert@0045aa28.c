
/* WARNING: Type propagation algorithm not settling */

int *******
load_cert(undefined4 param_1,int *******param_2,int ******param_3,code *param_4,undefined4 param_5,
         int ******param_6)

{
  bool bVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int *******pppppppiVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *******pppppppiVar9;
  int iVar10;
  uint *puVar11;
  char *pcVar12;
  char *pcVar13;
  code *pcVar14;
  code *pcVar15;
  int *******unaff_s0;
  int iVar16;
  int **unaff_s6;
  int **ppiVar17;
  int *piVar18;
  int *******pppppppiStack_1b4;
  int *******pppppppiStack_16c;
  int ******ppppppiStack_168;
  uint *puStack_164;
  char *pcStack_15c;
  char *pcStack_158;
  code *pcStack_154;
  int *******pppppppiStack_150;
  undefined *puStack_14c;
  int *******pppppppiStack_148;
  code *pcStack_144;
  undefined *puStack_130;
  undefined4 uStack_12c;
  int *******pppppppiStack_124;
  int *******pppppppiStack_120;
  int iStack_11c;
  int *******pppppppiStack_114;
  int *******pppppppiStack_110;
  undefined *puStack_10c;
  int *******pppppppiStack_108;
  int iStack_104;
  int *******pppppppiStack_100;
  code *pcStack_fc;
  int *******pppppppiStack_e8;
  code *pcStack_e4;
  undefined *puStack_e0;
  int ******ppppppiStack_d4;
  int *******pppppppiStack_d0;
  int *******pppppppiStack_cc;
  code *pcStack_c8;
  char *pcStack_c4;
  undefined *puStack_c0;
  int *******pppppppiStack_bc;
  int iStack_b8;
  int *******pppppppiStack_b4;
  int **ppiStack_b0;
  code *pcStack_ac;
  int ******ppppppiStack_98;
  int *******pppppppiStack_94;
  int *******pppppppiStack_90;
  undefined *puStack_88;
  int *******pppppppiStack_80;
  int ******ppppppiStack_7c;
  int *******pppppppiStack_78;
  int iStack_74;
  int *******pppppppiStack_70;
  int ******ppppppiStack_6c;
  undefined *puStack_68;
  int *******pppppppiStack_64;
  undefined4 uStack_60;
  int ******ppppppiStack_5c;
  int ******local_40;
  code *local_3c;
  int *******local_38;
  int *******local_28;
  int local_24;
  
  puStack_68 = PTR___stack_chk_guard_006a9ae8;
  local_28 = (int *******)0x0;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcStack_c4 = (char *)param_2;
  pcStack_c8 = (code *)param_3;
  uVar4 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  pppppppiVar5 = (int *******)(*(code *)PTR_BIO_new_006a6ea4)(uVar4);
  pppppppiVar9 = (int *******)PTR_stdin_006a9a14;
  if (pppppppiVar5 == (int *******)0x0) {
    (*(code *)PTR_ERR_print_errors_006a6e40)(param_1);
    if (local_28 == (int *******)0x0) {
      pcStack_c4 = "unable to load certificate\n";
      (*(code *)PTR_BIO_printf_006a6e38)(param_1);
      (*(code *)PTR_ERR_print_errors_006a6e40)(param_1);
    }
  }
  else {
    if (param_2 == (int *******)0x0) {
      (*(code *)PTR_setvbuf_006a9a00)(*(undefined4 *)PTR_stdin_006a9a14,0,2,0);
      pcStack_c8 = (code *)0x0;
      param_4 = (code *)*pppppppiVar9;
      (*(code *)PTR_BIO_ctrl_006a6e18)(pppppppiVar5,0x6a);
      if (param_3 != (int ******)0x1) goto LAB_0045aacc;
LAB_0045abf8:
      local_28 = (int *******)(*(code *)PTR_d2i_X509_bio_006a7b74)(pppppppiVar5,0);
LAB_0045ab08:
      pcStack_c4 = "-check_ss_sig";
      param_2 = pppppppiVar9;
    }
    else {
      pcStack_c8 = (code *)0x3;
      param_4 = (code *)param_2;
      iVar6 = (*(code *)PTR_BIO_ctrl_006a6e18)(pppppppiVar5,0x6c);
      pppppppiVar9 = param_2;
      if (iVar6 < 1) {
        pcStack_c8 = (code *)param_6;
        param_4 = (code *)param_2;
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Error opening %s %s\n");
        (*(code *)PTR_ERR_print_errors_006a6e40)(param_1);
        goto LAB_0045ab08;
      }
      if (param_3 == (int ******)0x1) goto LAB_0045abf8;
LAB_0045aacc:
      if (param_3 == (int ******)&SUB_00000004) {
        pcStack_c8 = (code *)0x0;
        param_3 = (int ******)
                  (*(code *)PTR_ASN1_item_d2i_bio_006a7b78)
                            (PTR_NETSCAPE_X509_it_006a7724,pppppppiVar5);
        if (param_3 != (int ******)0x0) {
          pcStack_c8 = (code *)**param_3;
          iVar6 = (*(code *)PTR_strncmp_006a9970)("certificate",(*param_3)[2]);
          puVar2 = PTR_NETSCAPE_X509_free_006a7b7c;
          if (iVar6 == 0) {
            local_28 = (int *******)param_3[1];
            param_3[1] = (int *****)0x0;
            (*(code *)puVar2)(param_3);
          }
          else {
            (*(code *)PTR_NETSCAPE_X509_free_006a7b7c)(param_3);
            (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Error reading header on certificate\n");
          }
        }
        goto LAB_0045ab08;
      }
      if (param_3 == (int ******)0x3) {
        param_4 = (code *)0x0;
        pcStack_c8 = password_callback;
        local_28 = (int *******)(*(code *)PTR_PEM_read_bio_X509_AUX_006a7b80)(pppppppiVar5,0);
        goto LAB_0045ab08;
      }
      if (param_3 != (int ******)&DAT_00000005) {
        pcStack_c8 = (code *)param_6;
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,"bad input format specified for %s\n");
        goto LAB_0045ab08;
      }
      local_38 = (int *******)&local_28;
      local_3c = (code *)0x0;
      param_4 = (code *)0x0;
      local_40 = (int ******)0x0;
      pcStack_c4 = (char *)pppppppiVar5;
      pcStack_c8 = (code *)param_6;
      load_pkcs12_constprop_4(param_1);
      param_2 = pppppppiVar9;
    }
    if (local_28 == (int *******)0x0) {
      pcStack_c4 = "unable to load certificate\n";
      (*(code *)PTR_BIO_printf_006a6e38)(param_1);
      (*(code *)PTR_ERR_print_errors_006a6e40)(param_1);
    }
    (*(code *)PTR_BIO_free_006a6e70)(pppppppiVar5);
    unaff_s0 = pppppppiVar5;
  }
  if (local_24 == *(int *)puStack_68) {
    return local_28;
  }
  iStack_b8 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_c0 = PTR___stack_chk_guard_006a9ae8;
  ppppppiStack_5c = param_6;
  puStack_88 = &_gp;
  pppppppiStack_80 = (int *******)0x0;
  ppppppiStack_7c = local_40;
  iStack_74 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pppppppiStack_78 = (int *******)pcStack_c4;
  pppppppiStack_70 = unaff_s0;
  ppppppiStack_6c = param_3;
  pppppppiStack_64 = param_2;
  uStack_60 = param_1;
  if ((int *******)pcStack_c4 == (int *******)0x0) {
    if (((int *******)param_4 == (int *******)0x0) || (pcStack_c8 == (code *)&DAT_00000007)) {
      (*(code *)PTR_BIO_printf_006a6e38)(iStack_b8,"no keyfile specified\n");
    }
    else {
      uVar4 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      param_2 = (int *******)(**(code **)(puStack_88 + -0x7f3c))(uVar4);
      if (param_2 != (int *******)0x0) {
        unaff_s6 = *(int ***)(puStack_88 + -0x53cc);
        (**(code **)(puStack_88 + -0x53e0))(*unaff_s6,0,2,0);
        local_3c = (code *)0x0;
        param_4 = (code *)*unaff_s6;
        (**(code **)(puStack_88 + -0x7fc8))(param_2,0x6a);
LAB_0045ae70:
        if ((int ******)pcStack_c8 == (int ******)0x1) {
          pppppppiStack_80 = (int *******)(**(code **)(puStack_88 + -0x7258))(param_2,0);
        }
        else if ((int ******)pcStack_c8 == (int ******)0x3) {
          param_4 = (code *)&ppppppiStack_7c;
          local_3c = password_callback;
          pppppppiStack_80 = (int *******)(**(code **)(puStack_88 + -0x7254))(param_2,0);
        }
        else if ((pcStack_c8 == (code *)&SUB_00000004) || (pcStack_c8 == (code *)&DAT_00000008)) {
          local_3c = (code *)pcStack_c4;
          param_4 = (code *)local_38;
          ppppppiStack_98 = (int ******)pcStack_c8;
          pppppppiStack_80 = (int *******)load_netscape_key(iStack_b8,param_2);
        }
        else if (pcStack_c8 == (code *)&DAT_00000005) {
          pppppppiStack_94 = (int *******)&pppppppiStack_80;
          pppppppiStack_90 = (int *******)0x0;
          ppppppiStack_98 = (int ******)&ppppppiStack_7c;
          param_4 = password_callback;
          local_3c = (code *)local_38;
          load_pkcs12_constprop_4(iStack_b8,param_2);
        }
        else if (pcStack_c8 == (code *)&DAT_0000000b) {
          pppppppiStack_80 = (int *******)(**(code **)(puStack_88 + -0x724c))(param_2);
        }
        else if (pcStack_c8 == (code *)&SUB_0000000c) {
          local_3c = (code *)&ppppppiStack_7c;
          pppppppiStack_80 =
               (int *******)(**(code **)(puStack_88 + -0x7250))(param_2,password_callback);
        }
        else {
          (**(code **)(puStack_88 + -0x7fa8))(iStack_b8,"bad input format specified for key file\n")
          ;
        }
        goto LAB_0045aec0;
      }
LAB_0045afa4:
      (**(code **)(puStack_88 + -0x7fa0))(iStack_b8);
    }
LAB_0045aed0:
    pcStack_158 = "-check_ss_sig";
    if (pppppppiStack_80 == (int *******)0x0) {
      pcStack_158 = "unable to load %s\n";
      local_3c = (code *)local_38;
      (**(code **)(puStack_88 + -0x7fa8))(iStack_b8);
      (**(code **)(puStack_88 + -0x7fa0))(iStack_b8);
    }
  }
  else {
    if (pcStack_c8 != (code *)&DAT_00000007) {
      uVar4 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      param_2 = (int *******)(**(code **)(puStack_88 + -0x7f3c))(uVar4);
      if (param_2 == (int *******)0x0) goto LAB_0045afa4;
      local_3c = (code *)0x3;
      param_4 = (code *)pcStack_c4;
      iVar6 = (**(code **)(puStack_88 + -0x7fc8))(param_2,0x6c);
      if (0 < iVar6) goto LAB_0045ae70;
      local_3c = (code *)local_38;
      param_4 = (code *)pcStack_c4;
      (**(code **)(puStack_88 + -0x7fa8))(iStack_b8,"Error opening %s %s\n");
      (**(code **)(puStack_88 + -0x7fa0))(iStack_b8);
LAB_0045aec0:
      (**(code **)(puStack_88 + -0x7f70))(param_2);
      goto LAB_0045aed0;
    }
    if ((int *******)local_3c == (int *******)0x0) {
      (*(code *)PTR_BIO_printf_006a6e38)();
      goto LAB_0045aed0;
    }
    param_4 = (code *)&ppppppiStack_7c;
    pcStack_158 = pcStack_c4;
    pppppppiVar9 = ui_method;
    pppppppiStack_80 = (int *******)(*(code *)PTR_ENGINE_load_private_key_006a7b84)(local_3c);
    local_3c = (code *)pppppppiVar9;
    if (pppppppiStack_80 == (int *******)0x0) {
      local_3c = (code *)local_38;
      (**(code **)(puStack_88 + -0x7fa8))(iStack_b8,"cannot load %s from engine\n");
      (**(code **)(puStack_88 + -0x7fa0))(iStack_b8);
      goto LAB_0045aed0;
    }
  }
  if (iStack_74 == *(int *)puStack_c0) {
    return pppppppiStack_80;
  }
  pcStack_ac = load_pubkey;
  iStack_104 = iStack_74;
  (**(code **)(puStack_88 + -0x5330))();
  pppppppiVar9 = pppppppiStack_90;
  puStack_10c = PTR___stack_chk_guard_006a9ae8;
  pppppppiStack_b4 = local_38;
  puStack_e0 = &_gp;
  ppppppiStack_d4 = ppppppiStack_98;
  pppppppiStack_cc = *(int ********)PTR___stack_chk_guard_006a9ae8;
  pppppppiStack_d0 = (int *******)pcStack_158;
  pppppppiStack_bc = param_2;
  ppiStack_b0 = unaff_s6;
  if ((int *******)pcStack_158 == (int *******)0x0) {
    if (((int *******)param_4 == (int *******)0x0) || (local_3c == (code *)&DAT_00000007)) {
      (*(code *)PTR_BIO_printf_006a6e38)(iStack_104,"no keyfile specified\n");
      goto LAB_0045b2e8;
    }
    uVar4 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    param_2 = (int *******)(**(code **)(puStack_e0 + -0x7f3c))(uVar4);
    if (param_2 == (int *******)0x0) goto LAB_0045b2d4;
    ppiVar17 = *(int ***)(puStack_e0 + -0x53cc);
    (**(code **)(puStack_e0 + -0x53e0))(*ppiVar17,0,2,0);
    pcVar14 = (code *)0x0;
    param_4 = (code *)*ppiVar17;
    (**(code **)(puStack_e0 + -0x7fc8))(param_2,0x6a);
LAB_0045b21c:
    if ((int *******)local_3c == (int *******)0x1) {
      pppppppiStack_114 = (int *******)(**(code **)(puStack_e0 + -0x7240))(param_2,0);
    }
    else if (local_3c == (code *)&DAT_0000000a) {
      pcStack_158 = (char *)(**(code **)(puStack_e0 + -0x723c))(param_2,0);
      if ((int *******)pcStack_158 == (int *******)0x0) goto LAB_0045b3a8;
LAB_0045b340:
      pppppppiStack_114 = (int *******)(**(code **)(puStack_e0 + -0x77c0))();
      if (pppppppiStack_114 != (int *******)0x0) {
        (**(code **)(puStack_e0 + -0x77bc))(pppppppiStack_114,pcStack_158);
      }
      (**(code **)(puStack_e0 + -0x77e0))(pcStack_158);
    }
    else if (local_3c == (code *)&DAT_00000009) {
      param_4 = (code *)&ppppppiStack_d4;
      pcVar14 = password_callback;
      pcStack_158 = (char *)(**(code **)(puStack_e0 + -0x7238))(param_2,0);
      if ((int *******)pcStack_158 != (int *******)0x0) goto LAB_0045b340;
LAB_0045b3a8:
      pppppppiStack_114 = (int *******)0x0;
    }
    else if ((int *******)local_3c == (int *******)0x3) {
      param_4 = (code *)&ppppppiStack_d4;
      pcVar14 = password_callback;
      pppppppiStack_114 = (int *******)(**(code **)(puStack_e0 + -0x7234))(param_2,0);
    }
    else if ((local_3c == (code *)&SUB_00000004) || (local_3c == (code *)&DAT_00000008)) {
      pcVar14 = (code *)pcStack_158;
      param_4 = (code *)pppppppiVar9;
      pppppppiStack_e8 = (int *******)local_3c;
      pppppppiStack_114 = (int *******)load_netscape_key(iStack_104,param_2);
    }
    else if (local_3c == (code *)&DAT_0000000b) {
      pppppppiStack_114 = (int *******)(**(code **)(puStack_e0 + -0x7244))(param_2);
    }
    else {
      pppppppiStack_114 = (int *******)0x0;
      (**(code **)(puStack_e0 + -0x7fa8))(iStack_104,"bad input format specified for key file\n");
    }
LAB_0045b268:
    (**(code **)(puStack_e0 + -0x7f70))(param_2);
LAB_0045b198:
    pcStack_15c = "-check_ss_sig";
    if (pppppppiStack_114 == (int *******)0x0) goto LAB_0045b2e8;
  }
  else {
    if (local_3c == (code *)&DAT_00000007) {
      if (pppppppiStack_94 != (int *******)0x0) {
        param_4 = (code *)&ppppppiStack_d4;
        pcVar14 = (code *)ui_method;
        pppppppiStack_114 = (int *******)(*(code *)PTR_ENGINE_load_public_key_006a7b98)();
        goto LAB_0045b198;
      }
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"no engine specified\n");
    }
    else {
      uVar4 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      param_2 = (int *******)(**(code **)(puStack_e0 + -0x7f3c))(uVar4);
      if (param_2 != (int *******)0x0) {
        pcVar14 = (code *)0x3;
        param_4 = (code *)pcStack_158;
        iVar6 = (**(code **)(puStack_e0 + -0x7fc8))(param_2,0x6c);
        if (0 < iVar6) goto LAB_0045b21c;
        pcVar14 = (code *)pppppppiVar9;
        param_4 = (code *)pcStack_158;
        (**(code **)(puStack_e0 + -0x7fa8))(iStack_104,"Error opening %s %s\n");
        pppppppiStack_114 = (int *******)0x0;
        (**(code **)(puStack_e0 + -0x7fa0))(iStack_104);
        goto LAB_0045b268;
      }
LAB_0045b2d4:
      (**(code **)(puStack_e0 + -0x7fa0))(iStack_104);
    }
LAB_0045b2e8:
    pcStack_15c = "unable to load %s\n";
    pcVar14 = (code *)pppppppiVar9;
    (**(code **)(puStack_e0 + -0x7fa8))(iStack_104);
    pppppppiStack_114 = (int *******)0x0;
  }
  if (pppppppiStack_cc == *(int ********)puStack_10c) {
    return pppppppiStack_114;
  }
  pcStack_fc = load_certs;
  pppppppiStack_148 = pppppppiStack_cc;
  (**(code **)(puStack_e0 + -0x5330))();
  puStack_14c = PTR___stack_chk_guard_006a9ae8;
  pppppppiStack_100 = pppppppiVar9;
  puStack_130 = &_gp;
  iStack_11c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar15 = pcStack_e4;
  pppppppiStack_124 = (int *******)param_4;
  pppppppiStack_120 = (int *******)pcStack_15c;
  pppppppiStack_110 = (int *******)pcStack_158;
  pppppppiStack_108 = param_2;
  if ((int *******)pcVar14 == (int *******)0x3) {
    if ((int *******)pcStack_15c == (int *******)0x0) {
      pcStack_158 = (char *)(*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14);
      if ((int *******)pcStack_158 != (int *******)0x0) goto LAB_0045b52c;
      param_4 = (code *)"stdin";
LAB_0045b6bc:
      pcVar12 = "Error opening %s %s\n";
      (**(code **)(puStack_130 + -0x7fa8))(pppppppiStack_148);
LAB_0045b6a4:
      (**(code **)(puStack_130 + -0x7fa0))(pppppppiStack_148);
      pppppppiStack_150 = param_2;
      pppppppiVar9 = pppppppiStack_148;
      goto LAB_0045b624;
    }
    pcStack_158 = (char *)(*(code *)PTR_BIO_new_file_006a6eac)(pcStack_15c,"r");
    param_4 = (code *)pcStack_15c;
    if ((int *******)pcStack_158 == (int *******)0x0) goto LAB_0045b6bc;
LAB_0045b52c:
    param_4 = (code *)&pppppppiStack_124;
    pcVar15 = password_callback;
    pcVar12 = (char *)0x0;
    pcStack_e4 = (code *)(**(code **)(puStack_130 + -0x781c))(pcStack_158);
    (**(code **)(puStack_130 + -0x7f70))(pcStack_158);
    param_2 = (int *******)(**(code **)(puStack_130 + -0x7e3c))();
    if (param_2 == (int *******)0x0) {
LAB_0045b658:
      if (pcStack_e4 != (code *)0x0) {
        (**(code **)(puStack_130 + -0x7d88))(pcStack_e4,*(undefined4 *)(puStack_130 + -0x7818));
      }
      (**(code **)(puStack_130 + -0x7d88))(param_2,*(undefined4 *)(puStack_130 + -0x7f50));
      pcVar15 = (code *)0x631f24;
      pcVar12 = "unable to load %s\n";
      (**(code **)(puStack_130 + -0x7fa8))(pppppppiStack_148);
      goto LAB_0045b6a4;
    }
    pcStack_15c = (char *)0x0;
    iVar6 = (**(code **)(puStack_130 + -0x7fb4))(pcStack_e4);
    if (0 < iVar6) {
      do {
        pcStack_158 = (char *)(**(code **)(puStack_130 + -0x7fbc))(pcStack_e4,pcStack_15c);
        pcVar12 = *(char **)pcStack_158;
        if ((int ******)pcVar12 != (int ******)0x0) {
          iVar6 = (**(code **)(puStack_130 + -0x7e38))(param_2);
          if (iVar6 == 0) goto LAB_0045b658;
          *(int *******)pcStack_158 = (int ******)0x0;
        }
        pcStack_15c = (char *)((int)pcStack_15c + 1);
        iVar6 = (**(code **)(puStack_130 + -0x7fb4))(pcStack_e4);
      } while ((int)pcStack_15c < iVar6);
    }
    iVar6 = (**(code **)(puStack_130 + -0x7fb4))(param_2);
    if (iVar6 < 1) goto LAB_0045b658;
    pppppppiStack_150 = param_2;
    if (pcStack_e4 != (code *)0x0) {
      pcVar12 = *(char **)(puStack_130 + -0x7818);
      (**(code **)(puStack_130 + -0x7d88))(pcStack_e4);
    }
  }
  else {
    pcVar12 = "bad input format specified for %s\n";
    (*(code *)PTR_BIO_printf_006a6e38)();
    pppppppiStack_150 = param_2;
LAB_0045b624:
    param_2 = (int *******)0x0;
    pppppppiStack_148 = pppppppiVar9;
  }
  if (iStack_11c == *(int *)puStack_14c) {
    return param_2;
  }
  pcStack_144 = load_crls;
  iVar6 = iStack_11c;
  (**(code **)(puStack_130 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puStack_164 = *(uint **)PTR___stack_chk_guard_006a9ae8;
  pppppppiStack_16c = (int *******)param_4;
  ppppppiStack_168 = (int ******)pcVar12;
  pcStack_154 = pcStack_e4;
  if (pcVar15 == (code *)0x3) {
    if ((int ******)pcVar12 == (int ******)0x0) {
      iVar7 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14);
      if (iVar7 != 0) goto LAB_0045b7a0;
      pcVar12 = "stdin";
LAB_0045b930:
      pcVar13 = "Error opening %s %s\n";
      (*(code *)PTR_BIO_printf_006a6e38)(iVar6,"Error opening %s %s\n",uStack_12c,pcVar12);
    }
    else {
      iVar7 = (*(code *)PTR_BIO_new_file_006a6eac)(pcVar12,"r");
      if (iVar7 == 0) goto LAB_0045b930;
LAB_0045b7a0:
      pcVar13 = (char *)0x0;
      iVar8 = (*(code *)PTR_PEM_X509_INFO_read_bio_006a75c4)
                        (iVar7,0,password_callback,&pppppppiStack_16c);
      (*(code *)PTR_BIO_free_006a6e70)(iVar7);
      pppppppiVar9 = (int *******)(*(code *)PTR_sk_new_null_006a6fa4)();
      if (pppppppiVar9 != (int *******)0x0) {
        iVar16 = 0;
        iVar7 = (*(code *)PTR_sk_num_006a6e2c)(iVar8);
        if (0 < iVar7) {
          do {
            iVar7 = (*(code *)PTR_sk_value_006a6e24)(iVar8,iVar16);
            pcVar13 = *(char **)(iVar7 + 4);
            if (pcVar13 != (char *)0x0) {
              iVar10 = (*(code *)PTR_sk_push_006a6fa8)(pppppppiVar9);
              if (iVar10 == 0) goto LAB_0045b8cc;
              *(undefined4 *)(iVar7 + 4) = 0;
            }
            iVar16 = iVar16 + 1;
            iVar7 = (*(code *)PTR_sk_num_006a6e2c)(iVar8);
          } while (iVar16 < iVar7);
        }
        iVar7 = (*(code *)PTR_sk_num_006a6e2c)(pppppppiVar9);
        if (0 < iVar7) {
          if (iVar8 != 0) {
            pcVar13 = PTR_X509_INFO_free_006a75c8;
            (*(code *)PTR_sk_pop_free_006a7058)(iVar8);
          }
          goto LAB_0045b89c;
        }
      }
LAB_0045b8cc:
      if (iVar8 != 0) {
        (*(code *)PTR_sk_pop_free_006a7058)(iVar8,PTR_X509_INFO_free_006a75c8);
      }
      (*(code *)PTR_sk_pop_free_006a7058)(pppppppiVar9,PTR_X509_CRL_free_006a7060);
      pcVar13 = "unable to load %s\n";
      (*(code *)PTR_BIO_printf_006a6e38)(iVar6,"unable to load %s\n",&DAT_0063fb84);
    }
    (*(code *)PTR_ERR_print_errors_006a6e40)(iVar6);
  }
  else {
    pcVar13 = "bad input format specified for %s\n";
    (*(code *)PTR_BIO_printf_006a6e38)();
  }
  pppppppiVar9 = (int *******)0x0;
LAB_0045b89c:
  if (puStack_164 == *(uint **)puVar2) {
    return pppppppiVar9;
  }
  puVar11 = puStack_164;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (pcVar13 == (char *)0x0) {
    return (int *******)0x0;
  }
  iVar7 = 0;
  uVar4 = (*(code *)PTR_X509V3_parse_list_006a7b48)(pcVar13);
  pppppppiStack_1b4 = (int *******)0x1;
  iVar6 = (*(code *)PTR_sk_num_006a6e2c)(uVar4);
  if (0 < iVar6) {
    do {
      iVar6 = (*(code *)PTR_sk_value_006a6e24)(uVar4,iVar7);
      pcVar12 = *(char **)(iVar6 + 4);
      piVar18 = (int *)cert_tbl_16879;
      iVar6 = cert_tbl_16879._0_4_;
      if (*pcVar12 == '-') {
        pcVar12 = pcVar12 + 1;
        bVar1 = false;
      }
      else if (*pcVar12 == '+') {
        pcVar12 = pcVar12 + 1;
        bVar1 = true;
      }
      else {
        bVar1 = true;
      }
      while (iVar6 != 0) {
        iVar6 = (*(code *)PTR_strcasecmp_006a9a18)(pcVar12);
        if (iVar6 == 0) {
          uVar3 = ~piVar18[2] & *puVar11;
          *puVar11 = uVar3;
          if (bVar1) {
            *puVar11 = uVar3 | piVar18[1];
          }
          else {
            *puVar11 = ~piVar18[1] & uVar3;
          }
          goto LAB_00459948;
        }
        piVar18 = piVar18 + 3;
        iVar6 = *piVar18;
      }
      pppppppiStack_1b4 = (int *******)0x0;
LAB_00459948:
      iVar7 = iVar7 + 1;
      iVar6 = (*(code *)PTR_sk_num_006a6e2c)(uVar4);
    } while (iVar7 < iVar6);
  }
  (*(code *)PTR_sk_pop_free_006a7058)(uVar4,PTR_X509V3_conf_free_006a7b4c);
  return pppppppiStack_1b4;
}

