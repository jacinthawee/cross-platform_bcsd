
/* WARNING: Type propagation algorithm not settling */

int load_certs(undefined4 param_1,undefined4 *******param_2,int param_3,undefined4 *******param_4,
              undefined4 param_5,code *param_6)

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
  int iVar14;
  char **unaff_s1;
  int unaff_s3;
  undefined4 unaff_s5;
  int *piVar15;
  int iStack_bc;
  undefined4 *******pppppppuStack_74;
  char *pcStack_70;
  uint *puStack_6c;
  undefined4 *******pppppppuStack_64;
  char **ppcStack_60;
  code *pcStack_5c;
  int iStack_58;
  undefined *puStack_54;
  undefined4 uStack_50;
  code *pcStack_4c;
  undefined *local_38;
  undefined4 uStack_34;
  undefined4 *******local_2c;
  undefined4 *******local_28;
  int local_24;
  
  puStack_54 = PTR___stack_chk_guard_006a9ae8;
  local_38 = &_gp;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar13 = param_6;
  local_2c = param_4;
  local_28 = param_2;
  if (param_3 == 3) {
    if (param_2 == (undefined4 *******)0x0) {
      unaff_s1 = (char **)(*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14);
      if (unaff_s1 != (char **)0x0) goto LAB_0045b52c;
      param_4 = (undefined4 *******)"stdin";
LAB_0045b6bc:
      pcVar11 = "Error opening %s %s\n";
      (**(code **)(local_38 + -0x7fa8))(param_1);
LAB_0045b6a4:
      (**(code **)(local_38 + -0x7fa0))(param_1);
      iStack_58 = unaff_s3;
      unaff_s5 = param_1;
      goto LAB_0045b624;
    }
    unaff_s1 = (char **)(*(code *)PTR_BIO_new_file_006a6eac)(param_2,"r");
    param_4 = param_2;
    if (unaff_s1 == (char **)0x0) goto LAB_0045b6bc;
LAB_0045b52c:
    param_4 = &local_2c;
    pcVar13 = password_callback;
    pcVar11 = (char *)0x0;
    param_6 = (code *)(**(code **)(local_38 + -0x781c))(unaff_s1);
    (**(code **)(local_38 + -0x7f70))(unaff_s1);
    unaff_s3 = (**(code **)(local_38 + -0x7e3c))();
    if (unaff_s3 == 0) {
LAB_0045b658:
      if (param_6 != (code *)0x0) {
        (**(code **)(local_38 + -0x7d88))(param_6,*(undefined4 *)(local_38 + -0x7818));
      }
      (**(code **)(local_38 + -0x7d88))(unaff_s3,*(undefined4 *)(local_38 + -0x7f50));
      pcVar13 = (code *)0x631f24;
      pcVar11 = "unable to load %s\n";
      (**(code **)(local_38 + -0x7fa8))(param_1);
      goto LAB_0045b6a4;
    }
    param_2 = (undefined4 *******)0x0;
    iVar5 = (**(code **)(local_38 + -0x7fb4))(param_6);
    if (0 < iVar5) {
      do {
        unaff_s1 = (char **)(**(code **)(local_38 + -0x7fbc))(param_6,param_2);
        pcVar11 = *unaff_s1;
        if (pcVar11 != (char *)0x0) {
          iVar5 = (**(code **)(local_38 + -0x7e38))(unaff_s3);
          if (iVar5 == 0) goto LAB_0045b658;
          *unaff_s1 = (char *)0x0;
        }
        param_2 = (undefined4 *******)((int)param_2 + 1);
        iVar5 = (**(code **)(local_38 + -0x7fb4))(param_6);
      } while ((int)param_2 < iVar5);
    }
    iVar5 = (**(code **)(local_38 + -0x7fb4))(unaff_s3);
    if (iVar5 < 1) goto LAB_0045b658;
    iStack_58 = unaff_s3;
    if (param_6 != (code *)0x0) {
      pcVar11 = *(char **)(local_38 + -0x7818);
      (**(code **)(local_38 + -0x7d88))(param_6);
    }
  }
  else {
    pcVar11 = "bad input format specified for %s\n";
    (*(code *)PTR_BIO_printf_006a6e38)();
    iStack_58 = unaff_s3;
LAB_0045b624:
    unaff_s3 = 0;
    param_1 = unaff_s5;
  }
  if (local_24 == *(int *)puStack_54) {
    return unaff_s3;
  }
  pcStack_4c = load_crls;
  iVar5 = local_24;
  (**(code **)(local_38 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puStack_6c = *(uint **)PTR___stack_chk_guard_006a9ae8;
  pppppppuStack_74 = param_4;
  pcStack_70 = pcVar11;
  pppppppuStack_64 = param_2;
  ppcStack_60 = unaff_s1;
  pcStack_5c = param_6;
  uStack_50 = param_1;
  if (pcVar13 == (code *)0x3) {
    if (pcVar11 == (char *)0x0) {
      iVar6 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14);
      if (iVar6 != 0) goto LAB_0045b7a0;
      pcVar11 = "stdin";
LAB_0045b930:
      pcVar12 = "Error opening %s %s\n";
      (*(code *)PTR_BIO_printf_006a6e38)(iVar5,"Error opening %s %s\n",uStack_34,pcVar11);
    }
    else {
      iVar6 = (*(code *)PTR_BIO_new_file_006a6eac)(pcVar11,"r");
      if (iVar6 == 0) goto LAB_0045b930;
LAB_0045b7a0:
      pcVar12 = (char *)0x0;
      iVar7 = (*(code *)PTR_PEM_X509_INFO_read_bio_006a75c4)
                        (iVar6,0,password_callback,&pppppppuStack_74);
      (*(code *)PTR_BIO_free_006a6e70)(iVar6);
      iVar6 = (*(code *)PTR_sk_new_null_006a6fa4)();
      if (iVar6 != 0) {
        iVar14 = 0;
        iVar8 = (*(code *)PTR_sk_num_006a6e2c)(iVar7);
        if (0 < iVar8) {
          do {
            iVar8 = (*(code *)PTR_sk_value_006a6e24)(iVar7,iVar14);
            pcVar12 = *(char **)(iVar8 + 4);
            if (pcVar12 != (char *)0x0) {
              iVar9 = (*(code *)PTR_sk_push_006a6fa8)(iVar6);
              if (iVar9 == 0) goto LAB_0045b8cc;
              *(undefined4 *)(iVar8 + 4) = 0;
            }
            iVar14 = iVar14 + 1;
            iVar8 = (*(code *)PTR_sk_num_006a6e2c)(iVar7);
          } while (iVar14 < iVar8);
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
  if (puStack_6c == *(uint **)puVar2) {
    return iVar6;
  }
  puVar10 = puStack_6c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (pcVar12 == (char *)0x0) {
    return 0;
  }
  iVar6 = 0;
  uVar3 = (*(code *)PTR_X509V3_parse_list_006a7b48)(pcVar12);
  iStack_bc = 1;
  iVar5 = (*(code *)PTR_sk_num_006a6e2c)(uVar3);
  if (0 < iVar5) {
    do {
      iVar5 = (*(code *)PTR_sk_value_006a6e24)(uVar3,iVar6);
      pcVar11 = *(char **)(iVar5 + 4);
      piVar15 = (int *)cert_tbl_16879;
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
          uVar4 = ~piVar15[2] & *puVar10;
          *puVar10 = uVar4;
          if (bVar1) {
            *puVar10 = uVar4 | piVar15[1];
          }
          else {
            *puVar10 = ~piVar15[1] & uVar4;
          }
          goto LAB_00459948;
        }
        piVar15 = piVar15 + 3;
        iVar5 = *piVar15;
      }
      iStack_bc = 0;
LAB_00459948:
      iVar6 = iVar6 + 1;
      iVar5 = (*(code *)PTR_sk_num_006a6e2c)(uVar3);
    } while (iVar6 < iVar5);
  }
  (*(code *)PTR_sk_pop_free_006a7058)(uVar3,PTR_X509V3_conf_free_006a7b4c);
  return iStack_bc;
}

