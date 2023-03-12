
/* WARNING: Type propagation algorithm not settling */

int load_pubkey(undefined4 param_1,int *******param_2,int param_3,int *******param_4,
               int ******param_5,int param_6,int *******param_7)

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
  code *pcVar13;
  code *pcVar14;
  int iVar15;
  int unaff_s3;
  int **ppiVar16;
  int *piVar17;
  int iStack_10c;
  int *******pppppppiStack_c4;
  int ******ppppppiStack_c0;
  uint *puStack_bc;
  char *pcStack_b4;
  int *******pppppppiStack_b0;
  code *pcStack_ac;
  int iStack_a8;
  undefined *puStack_a4;
  int *******pppppppiStack_a0;
  code *pcStack_9c;
  undefined *puStack_88;
  undefined4 uStack_84;
  int *******pppppppiStack_7c;
  int *******pppppppiStack_78;
  int iStack_74;
  int iStack_6c;
  int *******pppppppiStack_68;
  undefined *puStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  int *******pppppppiStack_58;
  code *pcStack_54;
  int local_40;
  code *pcStack_3c;
  undefined *local_38;
  int ******local_2c;
  int *******local_28;
  int *******local_24;
  
  puStack_64 = PTR___stack_chk_guard_006a9ae8;
  local_38 = &_gp;
  local_2c = param_5;
  local_24 = *(int ********)PTR___stack_chk_guard_006a9ae8;
  local_28 = param_2;
  if (param_2 == (int *******)0x0) {
    if ((param_4 == (int *******)0x0) || (param_3 == 7)) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"no keyfile specified\n");
      goto LAB_0045b2e8;
    }
    uVar3 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    unaff_s3 = (**(code **)(local_38 + -0x7f3c))(uVar3);
    if (unaff_s3 == 0) goto LAB_0045b2d4;
    ppiVar16 = *(int ***)(local_38 + -0x53cc);
    (**(code **)(local_38 + -0x53e0))(*ppiVar16,0,2,0);
    pcVar13 = (code *)0x0;
    param_4 = (int *******)*ppiVar16;
    (**(code **)(local_38 + -0x7fc8))(unaff_s3,0x6a);
LAB_0045b21c:
    if (param_3 == 1) {
      iStack_6c = (**(code **)(local_38 + -0x7240))(unaff_s3,0);
    }
    else if (param_3 == 10) {
      param_2 = (int *******)(**(code **)(local_38 + -0x723c))(unaff_s3,0);
      if (param_2 == (int *******)0x0) goto LAB_0045b3a8;
LAB_0045b340:
      iStack_6c = (**(code **)(local_38 + -0x77c0))();
      if (iStack_6c != 0) {
        (**(code **)(local_38 + -0x77bc))(iStack_6c,param_2);
      }
      (**(code **)(local_38 + -0x77e0))(param_2);
    }
    else if (param_3 == 9) {
      param_4 = &local_2c;
      pcVar13 = password_callback;
      param_2 = (int *******)(**(code **)(local_38 + -0x7238))(unaff_s3,0);
      if (param_2 != (int *******)0x0) goto LAB_0045b340;
LAB_0045b3a8:
      iStack_6c = 0;
    }
    else if (param_3 == 3) {
      param_4 = &local_2c;
      pcVar13 = password_callback;
      iStack_6c = (**(code **)(local_38 + -0x7234))(unaff_s3,0);
    }
    else if ((param_3 == 4) || (param_3 == 8)) {
      pcVar13 = (code *)param_2;
      param_4 = param_7;
      local_40 = param_3;
      iStack_6c = load_netscape_key(param_1,unaff_s3);
    }
    else if (param_3 == 0xb) {
      iStack_6c = (**(code **)(local_38 + -0x7244))(unaff_s3);
    }
    else {
      iStack_6c = 0;
      (**(code **)(local_38 + -0x7fa8))(param_1,"bad input format specified for key file\n");
    }
LAB_0045b268:
    (**(code **)(local_38 + -0x7f70))(unaff_s3);
LAB_0045b198:
    pcStack_b4 = "-check_ss_sig";
    if (iStack_6c == 0) goto LAB_0045b2e8;
  }
  else {
    if (param_3 == 7) {
      if (param_6 != 0) {
        param_4 = &local_2c;
        pcVar13 = (code *)ui_method;
        iStack_6c = (*(code *)PTR_ENGINE_load_public_key_006a7b98)();
        goto LAB_0045b198;
      }
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"no engine specified\n");
    }
    else {
      uVar3 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      unaff_s3 = (**(code **)(local_38 + -0x7f3c))(uVar3);
      if (unaff_s3 != 0) {
        pcVar13 = (code *)0x3;
        param_4 = param_2;
        iVar5 = (**(code **)(local_38 + -0x7fc8))(unaff_s3,0x6c);
        if (0 < iVar5) goto LAB_0045b21c;
        pcVar13 = (code *)param_7;
        param_4 = param_2;
        (**(code **)(local_38 + -0x7fa8))(param_1,"Error opening %s %s\n");
        iStack_6c = 0;
        (**(code **)(local_38 + -0x7fa0))(param_1);
        goto LAB_0045b268;
      }
LAB_0045b2d4:
      (**(code **)(local_38 + -0x7fa0))(param_1);
    }
LAB_0045b2e8:
    pcStack_b4 = "unable to load %s\n";
    pcVar13 = (code *)param_7;
    (**(code **)(local_38 + -0x7fa8))(param_1);
    iStack_6c = 0;
  }
  if (local_24 == *(int ********)puStack_64) {
    return iStack_6c;
  }
  pcStack_54 = load_certs;
  pppppppiStack_a0 = local_24;
  (**(code **)(local_38 + -0x5330))();
  puStack_a4 = PTR___stack_chk_guard_006a9ae8;
  pppppppiStack_58 = param_7;
  puStack_88 = &_gp;
  iStack_74 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar14 = pcStack_3c;
  pppppppiStack_7c = param_4;
  pppppppiStack_78 = (int *******)pcStack_b4;
  pppppppiStack_68 = param_2;
  iStack_60 = unaff_s3;
  uStack_5c = param_1;
  if ((int *******)pcVar13 == (int *******)0x3) {
    if ((int *******)pcStack_b4 == (int *******)0x0) {
      param_2 = (int *******)(*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14);
      if (param_2 != (int *******)0x0) goto LAB_0045b52c;
      param_4 = (int *******)"stdin";
LAB_0045b6bc:
      pcVar11 = "Error opening %s %s\n";
      (**(code **)(puStack_88 + -0x7fa8))(pppppppiStack_a0);
LAB_0045b6a4:
      (**(code **)(puStack_88 + -0x7fa0))(pppppppiStack_a0);
      iStack_a8 = unaff_s3;
      param_7 = pppppppiStack_a0;
      goto LAB_0045b624;
    }
    param_2 = (int *******)(*(code *)PTR_BIO_new_file_006a6eac)(pcStack_b4,"r");
    param_4 = (int *******)pcStack_b4;
    if (param_2 == (int *******)0x0) goto LAB_0045b6bc;
LAB_0045b52c:
    param_4 = (int *******)&pppppppiStack_7c;
    pcVar14 = password_callback;
    pcVar11 = (char *)0x0;
    pcStack_3c = (code *)(**(code **)(puStack_88 + -0x781c))(param_2);
    (**(code **)(puStack_88 + -0x7f70))(param_2);
    unaff_s3 = (**(code **)(puStack_88 + -0x7e3c))();
    if (unaff_s3 == 0) {
LAB_0045b658:
      if (pcStack_3c != (code *)0x0) {
        (**(code **)(puStack_88 + -0x7d88))(pcStack_3c,*(undefined4 *)(puStack_88 + -0x7818));
      }
      (**(code **)(puStack_88 + -0x7d88))(unaff_s3,*(undefined4 *)(puStack_88 + -0x7f50));
      pcVar14 = (code *)0x631f24;
      pcVar11 = "unable to load %s\n";
      (**(code **)(puStack_88 + -0x7fa8))(pppppppiStack_a0);
      goto LAB_0045b6a4;
    }
    pcStack_b4 = (char *)0x0;
    iVar5 = (**(code **)(puStack_88 + -0x7fb4))(pcStack_3c);
    if (0 < iVar5) {
      do {
        param_2 = (int *******)(**(code **)(puStack_88 + -0x7fbc))(pcStack_3c,pcStack_b4);
        pcVar11 = (char *)*param_2;
        if ((int ******)pcVar11 != (int ******)0x0) {
          iVar5 = (**(code **)(puStack_88 + -0x7e38))(unaff_s3);
          if (iVar5 == 0) goto LAB_0045b658;
          *param_2 = (int ******)0x0;
        }
        pcStack_b4 = (char *)((int)pcStack_b4 + 1);
        iVar5 = (**(code **)(puStack_88 + -0x7fb4))(pcStack_3c);
      } while ((int)pcStack_b4 < iVar5);
    }
    iVar5 = (**(code **)(puStack_88 + -0x7fb4))(unaff_s3);
    if (iVar5 < 1) goto LAB_0045b658;
    iStack_a8 = unaff_s3;
    if (pcStack_3c != (code *)0x0) {
      pcVar11 = *(char **)(puStack_88 + -0x7818);
      (**(code **)(puStack_88 + -0x7d88))(pcStack_3c);
    }
  }
  else {
    pcVar11 = "bad input format specified for %s\n";
    (*(code *)PTR_BIO_printf_006a6e38)();
    iStack_a8 = unaff_s3;
LAB_0045b624:
    unaff_s3 = 0;
    pppppppiStack_a0 = param_7;
  }
  if (iStack_74 == *(int *)puStack_a4) {
    return unaff_s3;
  }
  pcStack_9c = load_crls;
  iVar5 = iStack_74;
  (**(code **)(puStack_88 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puStack_bc = *(uint **)PTR___stack_chk_guard_006a9ae8;
  pppppppiStack_c4 = param_4;
  ppppppiStack_c0 = (int ******)pcVar11;
  pppppppiStack_b0 = param_2;
  pcStack_ac = pcStack_3c;
  if (pcVar14 == (code *)0x3) {
    if ((int ******)pcVar11 == (int ******)0x0) {
      iVar6 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14);
      if (iVar6 != 0) goto LAB_0045b7a0;
      pcVar11 = "stdin";
LAB_0045b930:
      pcVar12 = "Error opening %s %s\n";
      (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"Error opening %s %s\n",uStack_84,pcVar11);
    }
    else {
      iVar6 = (*(code *)PTR_BIO_new_file_006a6eac)(pcVar11,"r");
      if (iVar6 == 0) goto LAB_0045b930;
LAB_0045b7a0:
      pcVar12 = (char *)0x0;
      iVar7 = (*(code *)PTR_PEM_X509_INFO_read_bio_006a75c4)
                        (iVar6,0,password_callback,&pppppppiStack_c4);
      (*(code *)PTR_BIO_free_006a6e70)(iVar6);
      iVar6 = (*(code *)PTR_sk_new_null_006a6fa4)();
      if (iVar6 != 0) {
        iVar15 = 0;
        iVar8 = (*(code *)PTR_sk_num_006a6e2c)(iVar7);
        if (0 < iVar8) {
          do {
            iVar8 = (*(code *)PTR_sk_value_006a6e24)(iVar7,iVar15);
            pcVar12 = *(char **)(iVar8 + 4);
            if (pcVar12 != (char *)0x0) {
              iVar9 = (*(code *)PTR_sk_push_006a6fa8)(iVar6);
              if (iVar9 == 0) goto LAB_0045b8cc;
              *(undefined4 *)(iVar8 + 4) = 0;
            }
            iVar15 = iVar15 + 1;
            iVar8 = (*(code *)PTR_sk_num_006a6e2c)(iVar7);
          } while (iVar15 < iVar8);
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
  if (puStack_bc == *(uint **)puVar2) {
    return iVar6;
  }
  puVar10 = puStack_bc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (pcVar12 == (char *)0x0) {
    return 0;
  }
  iVar6 = 0;
  uVar3 = (*(code *)PTR_X509V3_parse_list_006a7b48)(pcVar12);
  iStack_10c = 1;
  iVar5 = (*(code *)PTR_sk_num_006a6e2c)(uVar3);
  if (0 < iVar5) {
    do {
      iVar5 = (*(code *)PTR_sk_value_006a6e24)(uVar3,iVar6);
      pcVar11 = *(char **)(iVar5 + 4);
      piVar17 = (int *)cert_tbl_16879;
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
          uVar4 = ~piVar17[2] & *puVar10;
          *puVar10 = uVar4;
          if (bVar1) {
            *puVar10 = uVar4 | piVar17[1];
          }
          else {
            *puVar10 = ~piVar17[1] & uVar4;
          }
          goto LAB_00459948;
        }
        piVar17 = piVar17 + 3;
        iVar5 = *piVar17;
      }
      iStack_10c = 0;
LAB_00459948:
      iVar6 = iVar6 + 1;
      iVar5 = (*(code *)PTR_sk_num_006a6e2c)(uVar3);
    } while (iVar6 < iVar5);
  }
  (*(code *)PTR_sk_pop_free_006a7058)(uVar3,PTR_X509V3_conf_free_006a7b4c);
  return iStack_10c;
}

