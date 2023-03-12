
/* WARNING: Type propagation algorithm not settling */

int load_key(undefined4 param_1,int *******param_2,int ******param_3,code *param_4,int ******param_5
            ,code *param_6,int *******param_7)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  char *pcVar11;
  char *pcVar12;
  int *******pppppppiVar13;
  code *pcVar14;
  code *pcVar15;
  int iVar16;
  int unaff_s3;
  int **unaff_s6;
  int **ppiVar17;
  int *piVar18;
  int iStack_164;
  int *******pppppppiStack_11c;
  int ******ppppppiStack_118;
  uint *puStack_114;
  char *pcStack_10c;
  char *pcStack_108;
  code *pcStack_104;
  int iStack_100;
  undefined *puStack_fc;
  int *******pppppppiStack_f8;
  code *pcStack_f4;
  undefined *puStack_e0;
  undefined4 uStack_dc;
  int *******pppppppiStack_d4;
  int *******pppppppiStack_d0;
  int iStack_cc;
  int iStack_c4;
  int *******pppppppiStack_c0;
  undefined *puStack_bc;
  int iStack_b8;
  int iStack_b4;
  int *******pppppppiStack_b0;
  code *pcStack_ac;
  int *******pppppppiStack_98;
  code *pcStack_94;
  undefined *puStack_90;
  int ******ppppppiStack_84;
  int *******pppppppiStack_80;
  int *******pppppppiStack_7c;
  int ******ppppppiStack_78;
  int *******pppppppiStack_74;
  undefined *puStack_70;
  int iStack_6c;
  undefined4 uStack_68;
  int *******pppppppiStack_64;
  int **ppiStack_60;
  code *pcStack_5c;
  int ******local_48;
  int *local_44;
  int *******local_40;
  undefined *local_38;
  int local_30;
  int ******local_2c;
  int *******local_28;
  int local_24;
  
  puStack_70 = PTR___stack_chk_guard_006a9ae8;
  local_38 = &_gp;
  local_30 = 0;
  local_2c = param_5;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_28 = param_2;
  if (param_2 == (int *******)0x0) {
    if (((int *******)param_4 == (int *******)0x0) || (param_3 == (int ******)&DAT_00000007)) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"no keyfile specified\n");
    }
    else {
      uVar3 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      unaff_s3 = (**(code **)(local_38 + -0x7f3c))(uVar3);
      if (unaff_s3 != 0) {
        unaff_s6 = *(int ***)(local_38 + -0x53cc);
        (**(code **)(local_38 + -0x53e0))(*unaff_s6,0,2,0);
        param_6 = (code *)0x0;
        param_4 = (code *)*unaff_s6;
        (**(code **)(local_38 + -0x7fc8))(unaff_s3,0x6a);
LAB_0045ae70:
        if (param_3 == (int ******)0x1) {
          local_30 = (**(code **)(local_38 + -0x7258))(unaff_s3,0);
        }
        else if (param_3 == (int ******)0x3) {
          param_4 = (code *)&local_2c;
          param_6 = password_callback;
          local_30 = (**(code **)(local_38 + -0x7254))(unaff_s3,0);
        }
        else if ((param_3 == (int ******)&SUB_00000004) || (param_3 == (int ******)&DAT_00000008)) {
          param_6 = (code *)param_2;
          param_4 = (code *)param_7;
          local_48 = param_3;
          local_30 = load_netscape_key(param_1,unaff_s3);
        }
        else if (param_3 == (int ******)&DAT_00000005) {
          local_44 = &local_30;
          local_40 = (int *******)0x0;
          local_48 = (int ******)&local_2c;
          param_4 = password_callback;
          param_6 = (code *)param_7;
          load_pkcs12_constprop_4(param_1,unaff_s3);
        }
        else if (param_3 == (int ******)&DAT_0000000b) {
          local_30 = (**(code **)(local_38 + -0x724c))(unaff_s3);
        }
        else if (param_3 == (int ******)&SUB_0000000c) {
          param_6 = (code *)&local_2c;
          local_30 = (**(code **)(local_38 + -0x7250))(unaff_s3,password_callback);
        }
        else {
          (**(code **)(local_38 + -0x7fa8))(param_1,"bad input format specified for key file\n");
        }
        goto LAB_0045aec0;
      }
LAB_0045afa4:
      (**(code **)(local_38 + -0x7fa0))(param_1);
    }
LAB_0045aed0:
    pcStack_108 = "-check_ss_sig";
    if (local_30 == 0) {
      pcStack_108 = "unable to load %s\n";
      param_6 = (code *)param_7;
      (**(code **)(local_38 + -0x7fa8))(param_1);
      (**(code **)(local_38 + -0x7fa0))(param_1);
    }
  }
  else {
    if (param_3 != (int ******)&DAT_00000007) {
      uVar3 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      unaff_s3 = (**(code **)(local_38 + -0x7f3c))(uVar3);
      if (unaff_s3 == 0) goto LAB_0045afa4;
      param_6 = (code *)0x3;
      param_4 = (code *)param_2;
      iVar5 = (**(code **)(local_38 + -0x7fc8))(unaff_s3,0x6c);
      if (0 < iVar5) goto LAB_0045ae70;
      param_6 = (code *)param_7;
      param_4 = (code *)param_2;
      (**(code **)(local_38 + -0x7fa8))(param_1,"Error opening %s %s\n");
      (**(code **)(local_38 + -0x7fa0))(param_1);
LAB_0045aec0:
      (**(code **)(local_38 + -0x7f70))(unaff_s3);
      goto LAB_0045aed0;
    }
    if ((int *******)param_6 == (int *******)0x0) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"no engine specified\n");
      goto LAB_0045aed0;
    }
    param_4 = (code *)&local_2c;
    pcStack_108 = (char *)param_2;
    pppppppiVar13 = ui_method;
    local_30 = (*(code *)PTR_ENGINE_load_private_key_006a7b84)(param_6);
    param_6 = (code *)pppppppiVar13;
    if (local_30 == 0) {
      param_6 = (code *)param_7;
      (**(code **)(local_38 + -0x7fa8))(param_1,"cannot load %s from engine\n");
      (**(code **)(local_38 + -0x7fa0))(param_1);
      goto LAB_0045aed0;
    }
  }
  if (local_24 == *(int *)puStack_70) {
    return local_30;
  }
  pcStack_5c = load_pubkey;
  iStack_b4 = local_24;
  (**(code **)(local_38 + -0x5330))();
  pppppppiVar13 = local_40;
  puStack_bc = PTR___stack_chk_guard_006a9ae8;
  pppppppiStack_64 = param_7;
  puStack_90 = &_gp;
  ppppppiStack_84 = local_48;
  pppppppiStack_7c = *(int ********)PTR___stack_chk_guard_006a9ae8;
  pppppppiStack_80 = (int *******)pcStack_108;
  ppppppiStack_78 = param_3;
  pppppppiStack_74 = param_2;
  iStack_6c = unaff_s3;
  uStack_68 = param_1;
  ppiStack_60 = unaff_s6;
  if ((int *******)pcStack_108 == (int *******)0x0) {
    if (((int *******)param_4 == (int *******)0x0) || (param_6 == (code *)&DAT_00000007)) {
      (*(code *)PTR_BIO_printf_006a6e38)(iStack_b4,"no keyfile specified\n");
      goto LAB_0045b2e8;
    }
    uVar3 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    unaff_s3 = (**(code **)(puStack_90 + -0x7f3c))(uVar3);
    if (unaff_s3 == 0) goto LAB_0045b2d4;
    ppiVar17 = *(int ***)(puStack_90 + -0x53cc);
    (**(code **)(puStack_90 + -0x53e0))(*ppiVar17,0,2,0);
    pcVar14 = (code *)0x0;
    param_4 = (code *)*ppiVar17;
    (**(code **)(puStack_90 + -0x7fc8))(unaff_s3,0x6a);
LAB_0045b21c:
    if ((int *******)param_6 == (int *******)0x1) {
      iStack_c4 = (**(code **)(puStack_90 + -0x7240))(unaff_s3,0);
    }
    else if (param_6 == (code *)&DAT_0000000a) {
      pcStack_108 = (char *)(**(code **)(puStack_90 + -0x723c))(unaff_s3,0);
      if ((int *******)pcStack_108 == (int *******)0x0) goto LAB_0045b3a8;
LAB_0045b340:
      iStack_c4 = (**(code **)(puStack_90 + -0x77c0))();
      if (iStack_c4 != 0) {
        (**(code **)(puStack_90 + -0x77bc))(iStack_c4,pcStack_108);
      }
      (**(code **)(puStack_90 + -0x77e0))(pcStack_108);
    }
    else if (param_6 == (code *)&DAT_00000009) {
      param_4 = (code *)&ppppppiStack_84;
      pcVar14 = password_callback;
      pcStack_108 = (char *)(**(code **)(puStack_90 + -0x7238))(unaff_s3,0);
      if ((int *******)pcStack_108 != (int *******)0x0) goto LAB_0045b340;
LAB_0045b3a8:
      iStack_c4 = 0;
    }
    else if ((int *******)param_6 == (int *******)0x3) {
      param_4 = (code *)&ppppppiStack_84;
      pcVar14 = password_callback;
      iStack_c4 = (**(code **)(puStack_90 + -0x7234))(unaff_s3,0);
    }
    else if ((param_6 == (code *)&SUB_00000004) || (param_6 == (code *)&DAT_00000008)) {
      pcVar14 = (code *)pcStack_108;
      param_4 = (code *)pppppppiVar13;
      pppppppiStack_98 = (int *******)param_6;
      iStack_c4 = load_netscape_key(iStack_b4,unaff_s3);
    }
    else if (param_6 == (code *)&DAT_0000000b) {
      iStack_c4 = (**(code **)(puStack_90 + -0x7244))(unaff_s3);
    }
    else {
      iStack_c4 = 0;
      (**(code **)(puStack_90 + -0x7fa8))(iStack_b4,"bad input format specified for key file\n");
    }
LAB_0045b268:
    (**(code **)(puStack_90 + -0x7f70))(unaff_s3);
LAB_0045b198:
    pcStack_10c = "-check_ss_sig";
    if (iStack_c4 == 0) goto LAB_0045b2e8;
  }
  else {
    if (param_6 == (code *)&DAT_00000007) {
      if (local_44 != (int *)0x0) {
        param_4 = (code *)&ppppppiStack_84;
        pcVar14 = (code *)ui_method;
        iStack_c4 = (*(code *)PTR_ENGINE_load_public_key_006a7b98)();
        goto LAB_0045b198;
      }
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"no engine specified\n");
    }
    else {
      uVar3 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      unaff_s3 = (**(code **)(puStack_90 + -0x7f3c))(uVar3);
      if (unaff_s3 != 0) {
        pcVar14 = (code *)0x3;
        param_4 = (code *)pcStack_108;
        iVar5 = (**(code **)(puStack_90 + -0x7fc8))(unaff_s3,0x6c);
        if (0 < iVar5) goto LAB_0045b21c;
        pcVar14 = (code *)pppppppiVar13;
        param_4 = (code *)pcStack_108;
        (**(code **)(puStack_90 + -0x7fa8))(iStack_b4,"Error opening %s %s\n");
        iStack_c4 = 0;
        (**(code **)(puStack_90 + -0x7fa0))(iStack_b4);
        goto LAB_0045b268;
      }
LAB_0045b2d4:
      (**(code **)(puStack_90 + -0x7fa0))(iStack_b4);
    }
LAB_0045b2e8:
    pcStack_10c = "unable to load %s\n";
    pcVar14 = (code *)pppppppiVar13;
    (**(code **)(puStack_90 + -0x7fa8))(iStack_b4);
    iStack_c4 = 0;
  }
  if (pppppppiStack_7c == *(int ********)puStack_bc) {
    return iStack_c4;
  }
  pcStack_ac = load_certs;
  pppppppiStack_f8 = pppppppiStack_7c;
  (**(code **)(puStack_90 + -0x5330))();
  puStack_fc = PTR___stack_chk_guard_006a9ae8;
  pppppppiStack_b0 = pppppppiVar13;
  puStack_e0 = &_gp;
  iStack_cc = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar15 = pcStack_94;
  pppppppiStack_d4 = (int *******)param_4;
  pppppppiStack_d0 = (int *******)pcStack_10c;
  pppppppiStack_c0 = (int *******)pcStack_108;
  iStack_b8 = unaff_s3;
  if ((int *******)pcVar14 == (int *******)0x3) {
    if ((int *******)pcStack_10c == (int *******)0x0) {
      pcStack_108 = (char *)(*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14);
      if ((int *******)pcStack_108 != (int *******)0x0) goto LAB_0045b52c;
      param_4 = (code *)"stdin";
LAB_0045b6bc:
      pcVar11 = "Error opening %s %s\n";
      (**(code **)(puStack_e0 + -0x7fa8))(pppppppiStack_f8);
LAB_0045b6a4:
      (**(code **)(puStack_e0 + -0x7fa0))(pppppppiStack_f8);
      iStack_100 = unaff_s3;
      pppppppiVar13 = pppppppiStack_f8;
      goto LAB_0045b624;
    }
    pcStack_108 = (char *)(*(code *)PTR_BIO_new_file_006a6eac)(pcStack_10c,"r");
    param_4 = (code *)pcStack_10c;
    if ((int *******)pcStack_108 == (int *******)0x0) goto LAB_0045b6bc;
LAB_0045b52c:
    param_4 = (code *)&pppppppiStack_d4;
    pcVar15 = password_callback;
    pcVar11 = (char *)0x0;
    pcStack_94 = (code *)(**(code **)(puStack_e0 + -0x781c))(pcStack_108);
    (**(code **)(puStack_e0 + -0x7f70))(pcStack_108);
    unaff_s3 = (**(code **)(puStack_e0 + -0x7e3c))();
    if (unaff_s3 == 0) {
LAB_0045b658:
      if (pcStack_94 != (code *)0x0) {
        (**(code **)(puStack_e0 + -0x7d88))(pcStack_94,*(undefined4 *)(puStack_e0 + -0x7818));
      }
      (**(code **)(puStack_e0 + -0x7d88))(unaff_s3,*(undefined4 *)(puStack_e0 + -0x7f50));
      pcVar15 = (code *)0x631f24;
      pcVar11 = "unable to load %s\n";
      (**(code **)(puStack_e0 + -0x7fa8))(pppppppiStack_f8);
      goto LAB_0045b6a4;
    }
    pcStack_10c = (char *)0x0;
    iVar5 = (**(code **)(puStack_e0 + -0x7fb4))(pcStack_94);
    if (0 < iVar5) {
      do {
        pcStack_108 = (char *)(**(code **)(puStack_e0 + -0x7fbc))(pcStack_94,pcStack_10c);
        pcVar11 = *(char **)pcStack_108;
        if ((int ******)pcVar11 != (int ******)0x0) {
          iVar5 = (**(code **)(puStack_e0 + -0x7e38))(unaff_s3);
          if (iVar5 == 0) goto LAB_0045b658;
          *(int *******)pcStack_108 = (int ******)0x0;
        }
        pcStack_10c = (char *)((int)pcStack_10c + 1);
        iVar5 = (**(code **)(puStack_e0 + -0x7fb4))(pcStack_94);
      } while ((int)pcStack_10c < iVar5);
    }
    iVar5 = (**(code **)(puStack_e0 + -0x7fb4))(unaff_s3);
    if (iVar5 < 1) goto LAB_0045b658;
    iStack_100 = unaff_s3;
    if (pcStack_94 != (code *)0x0) {
      pcVar11 = *(char **)(puStack_e0 + -0x7818);
      (**(code **)(puStack_e0 + -0x7d88))(pcStack_94);
    }
  }
  else {
    pcVar11 = "bad input format specified for %s\n";
    (*(code *)PTR_BIO_printf_006a6e38)();
    iStack_100 = unaff_s3;
LAB_0045b624:
    unaff_s3 = 0;
    pppppppiStack_f8 = pppppppiVar13;
  }
  if (iStack_cc == *(int *)puStack_fc) {
    return unaff_s3;
  }
  pcStack_f4 = load_crls;
  iVar5 = iStack_cc;
  (**(code **)(puStack_e0 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puStack_114 = *(uint **)PTR___stack_chk_guard_006a9ae8;
  pppppppiStack_11c = (int *******)param_4;
  ppppppiStack_118 = (int ******)pcVar11;
  pcStack_104 = pcStack_94;
  if (pcVar15 == (code *)0x3) {
    if ((int ******)pcVar11 == (int ******)0x0) {
      iVar6 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14);
      if (iVar6 != 0) goto LAB_0045b7a0;
      pcVar11 = "stdin";
LAB_0045b930:
      pcVar12 = "Error opening %s %s\n";
      (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"Error opening %s %s\n",uStack_dc,pcVar11);
    }
    else {
      iVar6 = (*(code *)PTR_BIO_new_file_006a6eac)(pcVar11,"r");
      if (iVar6 == 0) goto LAB_0045b930;
LAB_0045b7a0:
      pcVar12 = (char *)0x0;
      iVar7 = (*(code *)PTR_PEM_X509_INFO_read_bio_006a75c4)
                        (iVar6,0,password_callback,&pppppppiStack_11c);
      (*(code *)PTR_BIO_free_006a6e70)(iVar6);
      iVar6 = (*(code *)PTR_sk_new_null_006a6fa4)();
      if (iVar6 != 0) {
        iVar16 = 0;
        iVar8 = (*(code *)PTR_sk_num_006a6e2c)(iVar7);
        if (0 < iVar8) {
          do {
            iVar8 = (*(code *)PTR_sk_value_006a6e24)(iVar7,iVar16);
            pcVar12 = *(char **)(iVar8 + 4);
            if (pcVar12 != (char *)0x0) {
              iVar9 = (*(code *)PTR_sk_push_006a6fa8)(iVar6);
              if (iVar9 == 0) goto LAB_0045b8cc;
              *(undefined4 *)(iVar8 + 4) = 0;
            }
            iVar16 = iVar16 + 1;
            iVar8 = (*(code *)PTR_sk_num_006a6e2c)(iVar7);
          } while (iVar16 < iVar8);
        }
        iVar8 = (*(code *)PTR_sk_num_006a6e2c)(iVar6);
        if (0 < iVar8) {
          if (iVar7 != 0) {
            pcVar12 = PTR_X509_INFO_free_006a75c8;
            (*(code *)PTR_sk_pop_free_006a7058)(iVar7);
          }
          goto LAB_0045b89c;
        }
      }
LAB_0045b8cc:
      if (iVar7 != 0) {
        (*(code *)PTR_sk_pop_free_006a7058)(iVar7,PTR_X509_INFO_free_006a75c8);
      }
      (*(code *)PTR_sk_pop_free_006a7058)(iVar6,PTR_X509_CRL_free_006a7060);
      pcVar12 = "unable to load %s\n";
      (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"unable to load %s\n",&DAT_0063fb84);
    }
    (*(code *)PTR_ERR_print_errors_006a6e40)(iVar5);
  }
  else {
    pcVar12 = "bad input format specified for %s\n";
    (*(code *)PTR_BIO_printf_006a6e38)();
  }
  iVar6 = 0;
LAB_0045b89c:
  if (puStack_114 == *(uint **)puVar2) {
    return iVar6;
  }
  puVar10 = puStack_114;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (pcVar12 == (char *)0x0) {
    return 0;
  }
  iVar6 = 0;
  uVar3 = (*(code *)PTR_X509V3_parse_list_006a7b48)(pcVar12);
  iStack_164 = 1;
  iVar5 = (*(code *)PTR_sk_num_006a6e2c)(uVar3);
  if (0 < iVar5) {
    do {
      iVar5 = (*(code *)PTR_sk_value_006a6e24)(uVar3,iVar6);
      pcVar11 = *(char **)(iVar5 + 4);
      piVar18 = (int *)cert_tbl_16879;
      iVar5 = cert_tbl_16879._0_4_;
      if (*pcVar11 == '-') {
        pcVar11 = pcVar11 + 1;
        bVar1 = false;
      }
      else if (*pcVar11 == '+') {
        pcVar11 = pcVar11 + 1;
        bVar1 = true;
      }
      else {
        bVar1 = true;
      }
      while (iVar5 != 0) {
        iVar5 = (*(code *)PTR_strcasecmp_006a9a18)(pcVar11);
        if (iVar5 == 0) {
          uVar4 = ~piVar18[2] & *puVar10;
          *puVar10 = uVar4;
          if (bVar1) {
            *puVar10 = uVar4 | piVar18[1];
          }
          else {
            *puVar10 = ~piVar18[1] & uVar4;
          }
          goto LAB_00459948;
        }
        piVar18 = piVar18 + 3;
        iVar5 = *piVar18;
      }
      iStack_164 = 0;
LAB_00459948:
      iVar6 = iVar6 + 1;
      iVar5 = (*(code *)PTR_sk_num_006a6e2c)(uVar3);
    } while (iVar6 < iVar5);
  }
  (*(code *)PTR_sk_pop_free_006a7058)(uVar3,PTR_X509V3_conf_free_006a7b4c);
  return iStack_164;
}

