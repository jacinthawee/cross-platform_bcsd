
int asn1parse_main(undefined *param_1,undefined4 *param_2)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  char **ppcVar12;
  char *pcVar13;
  int iVar14;
  char **ppcVar15;
  undefined *unaff_s7;
  undefined *puVar16;
  code *pcVar17;
  int iVar18;
  char *local_78;
  char *local_74;
  int local_70;
  undefined4 local_64;
  char *local_58;
  int local_50;
  char *local_4c;
  int local_48;
  char *local_40;
  int local_3c;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  puVar3 = PTR_bio_err_006a6e3c;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iVar9 = *(int *)puVar3;
  if (iVar9 == 0) {
    uVar5 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar9 = (*(code *)PTR_BIO_new_006a6ea4)(uVar5);
    *(int *)puVar3 = iVar9;
    if (iVar9 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar9,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
      iVar9 = *(int *)puVar3;
    }
  }
  iVar9 = (*(code *)PTR_load_config_006a6e64)(iVar9,0);
  if (iVar9 == 0) {
    iVar9 = 0;
  }
  else {
    uVar5 = *param_2;
    unaff_s7 = param_1 + -1;
    ppcVar15 = (char **)(param_2 + 1);
    iVar9 = (*(code *)PTR_sk_new_null_006a6fa4)();
    if (iVar9 != 0) {
      local_4c = (char *)0x0;
      iVar10 = 3;
      local_40 = (char *)0x0;
      local_74 = (char *)0x0;
      local_58 = (char *)0x0;
      local_78 = (char *)0x0;
      local_3c = 0;
      bVar2 = false;
      local_64 = 0;
      local_48 = 0;
      local_50 = 0;
      if (0 < (int)unaff_s7) {
        param_2 = (undefined4 *)0x630000;
        param_1 = &DAT_00632514;
LAB_0042311c:
        pcVar13 = *ppcVar15;
        iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-inform");
        if (iVar14 == 0) {
          puVar16 = unaff_s7 + -1;
          if (puVar16 == (undefined *)0x0) goto LAB_00423600;
          ppcVar12 = ppcVar15 + 1;
          iVar10 = (*(code *)PTR_str2fmt_006a6e4c)(ppcVar15[1]);
        }
        else {
          ppcVar12 = ppcVar15;
          puVar16 = unaff_s7;
          if (*pcVar13 == '-') {
            cVar1 = pcVar13[1];
            if (((cVar1 != 'i') || (pcVar13[2] != 'n')) || (pcVar13[3] != '\0')) {
              iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,&DAT_00632514);
              if (iVar14 == 0) goto LAB_0042348c;
              if ((cVar1 == 'i') && (pcVar13[2] == '\0')) {
                local_64 = 1;
                goto LAB_00423110;
              }
              goto LAB_004234e0;
            }
            puVar16 = unaff_s7 + -1;
            if (unaff_s7 + -1 == (undefined *)0x0) goto LAB_00423604;
            local_78 = ppcVar15[1];
            unaff_s7 = unaff_s7 + -2;
            ppcVar15 = ppcVar15 + 2;
            goto joined_r0x00423190;
          }
          iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,&DAT_00632514);
          if (iVar14 == 0) {
LAB_0042348c:
            puVar16 = unaff_s7 + -1;
            if (puVar16 == (undefined *)0x0) goto LAB_00423600;
            local_74 = ppcVar15[1];
            ppcVar12 = ppcVar15 + 1;
            goto LAB_00423110;
          }
LAB_004234e0:
          iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-noout");
          if (iVar14 == 0) {
            bVar2 = true;
          }
          else {
            iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-oid");
            if (iVar14 == 0) {
              if (unaff_s7 + -1 == (undefined *)0x0) goto LAB_00423600;
              local_58 = ppcVar15[1];
              ppcVar12 = ppcVar15 + 1;
              puVar16 = unaff_s7 + -1;
            }
            else {
              iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-offset");
              if (iVar14 != 0) {
                iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-length");
                if (iVar14 != 0) {
                  iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-dump");
                  if (iVar14 == 0) {
                    local_3c = -1;
                  }
                  else {
                    iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-dlimit");
                    if (iVar14 == 0) {
                      if (unaff_s7 + -1 != (undefined *)0x0) {
                        local_3c = (*(code *)PTR_strtol_006a9958)(ppcVar15[1],0,10);
                        ppcVar12 = ppcVar15 + 1;
                        puVar16 = unaff_s7 + -1;
                        if (0 < local_3c) goto LAB_00423110;
                      }
LAB_00423600:
                      puVar16 = unaff_s7 + -1;
                      goto LAB_00423604;
                    }
                    iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-strparse");
                    if (iVar14 == 0) {
                      if (unaff_s7 + -1 == (undefined *)0x0) goto LAB_00423600;
                      (*(code *)PTR_sk_push_006a6fa8)(iVar9,ppcVar15[1]);
                      ppcVar12 = ppcVar15 + 1;
                      puVar16 = unaff_s7 + -1;
                    }
                    else {
                      iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-genstr");
                      if (iVar14 == 0) {
                        if (unaff_s7 + -1 == (undefined *)0x0) goto LAB_00423600;
                        local_40 = ppcVar15[1];
                        ppcVar12 = ppcVar15 + 1;
                        puVar16 = unaff_s7 + -1;
                      }
                      else {
                        iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-genconf");
                        if (iVar14 != 0) {
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)puVar3,"unknown option %s\n",pcVar13);
                          goto LAB_00423604;
                        }
                        if (unaff_s7 + -1 == (undefined *)0x0) goto LAB_00423600;
                        local_4c = ppcVar15[1];
                        ppcVar12 = ppcVar15 + 1;
                        puVar16 = unaff_s7 + -1;
                      }
                    }
                  }
                  goto LAB_00423110;
                }
                puVar16 = unaff_s7 + -1;
                if (puVar16 == (undefined *)0x0) goto LAB_00423600;
                local_48 = (*(code *)PTR_strtol_006a9958)(ppcVar15[1],0,10);
                ppcVar12 = ppcVar15 + 1;
                if (local_48 != 0) goto LAB_00423110;
LAB_00423604:
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar3,"%s [options] <infile\n",uVar5);
                (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"where options are\n");
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar3," -inform arg   input format - one of DER PEM\n");
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar3," -in arg       input file\n");
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar3,
                           " -out arg      output file (output format is always DER\n");
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar3," -noout arg    don\'t produce any output\n");
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar3," -offset arg   offset into file\n");
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar3," -length arg   length of section in file\n");
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar3," -i            indent entries\n");
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar3," -dump         dump unknown data in hex form\n");
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar3,
                           " -dlimit arg   dump the first arg bytes of unknown data in hex form\n");
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar3," -oid file     file of extra oid definitions\n");
                (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3," -strparse offset\n");
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar3,
                           "               a series of these can be used to \'dig\' into multiple\n"
                          );
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar3,"               ASN1 blob wrappings\n");
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar3,
                           " -genstr str   string to generate ASN1 structure from\n");
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar3,
                           " -genconf file file to generate ASN1 structure from\n");
                unaff_s7 = puVar16;
                goto LAB_00422fa8;
              }
              if (unaff_s7 + -1 == (undefined *)0x0) goto LAB_00423600;
              local_50 = (*(code *)PTR_strtol_006a9958)(ppcVar15[1],0,10);
              ppcVar12 = ppcVar15 + 1;
              puVar16 = unaff_s7 + -1;
            }
          }
        }
LAB_00423110:
        unaff_s7 = puVar16 + -1;
        ppcVar15 = ppcVar12 + 1;
joined_r0x00423190:
        if (unaff_s7 == (undefined *)0x0) goto LAB_0042319c;
        goto LAB_0042311c;
      }
LAB_0042319c:
      (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
      uVar5 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      param_1 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar5);
      uVar5 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      param_2 = (undefined4 *)(*(code *)PTR_BIO_new_006a6ea4)(uVar5);
      if (param_1 != (undefined *)0x0) {
        if (param_2 == (undefined4 *)0x0) {
          iVar10 = 0;
          iVar14 = 0;
          puVar16 = (undefined *)0x0;
          iVar18 = 1;
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar3);
          (*(code *)PTR_BIO_free_006a6e70)(0);
          goto LAB_00423858;
        }
        (*(code *)PTR_BIO_ctrl_006a6e18)(param_2,0x6a,0x10,*(undefined4 *)PTR_stdout_006a99c8);
        if (local_58 != (char *)0x0) {
          iVar14 = (*(code *)PTR_BIO_ctrl_006a6e18)(param_1,0x6c,3,local_58);
          if (iVar14 < 1) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar3,"problems opening %s\n",local_58);
            local_78 = *(char **)puVar3;
            pcVar17 = (code *)PTR_ERR_print_errors_006a6e40;
            goto LAB_00423a00;
          }
          (*(code *)PTR_OBJ_create_objects_006a6eb0)(param_1);
        }
        if (local_78 == (char *)0x0) {
          (*(code *)PTR_BIO_ctrl_006a6e18)(param_1,0x6a,0,*(undefined4 *)PTR_stdin_006a9a14);
        }
        else {
          iVar14 = (*(code *)PTR_BIO_ctrl_006a6e18)(param_1,0x6c,3,local_78);
          pcVar17 = (code *)PTR_perror_006a9a80;
          if (iVar14 < 1) {
LAB_00423a00:
            iVar10 = 0;
            (*pcVar17)(local_78);
            iVar14 = 0;
            local_78 = (char *)0x0;
            puVar16 = (undefined *)0x0;
            iVar18 = 1;
            goto LAB_00423950;
          }
        }
        if (local_74 == (char *)0x0) {
          local_78 = (char *)0x0;
        }
        else {
          local_78 = (char *)(*(code *)PTR_BIO_new_file_006a6eac)(local_74,&DAT_00632420);
          if (local_78 == (char *)0x0) {
            iVar10 = 0;
            iVar14 = 0;
            puVar16 = (undefined *)0x0;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar3,"problems opening %s\n",local_74);
            iVar18 = 1;
            (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar3);
            goto LAB_00423950;
          }
        }
        iVar14 = (*(code *)PTR_BUF_MEM_new_006a749c)();
        if ((iVar14 == 0) ||
           (iVar18 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(iVar14,0x10000), iVar18 == 0)) {
          iVar10 = 0;
          puVar16 = (undefined *)0x0;
          iVar18 = 1;
          goto LAB_00423950;
        }
        puVar8 = param_1;
        if (local_40 != (char *)0x0) {
          uVar5 = *(undefined4 *)puVar3;
          local_34 = 0;
          if (local_4c == (char *)0x0) {
            uVar11 = 0;
          }
          else {
            uVar11 = (*(code *)PTR_NCONF_new_006a6e58)(0);
            iVar10 = (*(code *)PTR_NCONF_load_006a6e5c)(uVar11,local_4c,&local_34);
            if (iVar10 == 0) goto LAB_00423b78;
          }
LAB_00423318:
          unaff_s7 = (undefined *)(*(code *)PTR_ASN1_generate_nconf_006a74a4)(local_40,uVar11);
          (*(code *)PTR_NCONF_free_006a6e6c)(uVar11);
          if (unaff_s7 == (undefined *)0x0) goto LAB_00423bc0;
          local_74 = (char *)(*(code *)PTR_i2d_ASN1_TYPE_006a74a8)(unaff_s7,0);
          if ((int)local_74 < 1) goto LAB_00423d4c;
          iVar10 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(iVar14,local_74);
          if (iVar10 == 0) goto LAB_00423d4c;
          local_30 = *(int *)(iVar14 + 4);
          (*(code *)PTR_i2d_ASN1_TYPE_006a74a8)(unaff_s7,&local_30);
          puVar16 = (undefined *)0x0;
          (*(code *)PTR_ASN1_TYPE_free_006a7498)(unaff_s7);
LAB_004233a8:
          local_70 = *(int *)(iVar14 + 4);
          iVar18 = (*(code *)PTR_sk_num_006a6e2c)(iVar9);
          iVar10 = 0;
          param_1 = puVar8;
          if (iVar18 != 0) {
            iVar18 = 0;
            iVar7 = 0;
            while (iVar6 = (*(code *)PTR_sk_num_006a6e2c)(iVar9), iVar10 = iVar7, iVar18 < iVar6) {
              uVar5 = (*(code *)PTR_sk_value_006a6e24)(iVar9,iVar18);
              iVar10 = (*(code *)PTR_strtol_006a9958)(uVar5,0,10);
              if (iVar10 == 0) {
                uVar11 = *(undefined4 *)puVar3;
                uVar5 = (*(code *)PTR_sk_value_006a6e24)(iVar9,iVar18);
                (*(code *)PTR_BIO_printf_006a6e38)(uVar11,"\'%s\' is an invalid number\n",uVar5);
                iVar18 = iVar18 + 1;
              }
              else {
                local_30 = local_70 + iVar10;
                iVar10 = (*(code *)PTR_d2i_ASN1_TYPE_006a74ac)(0,&local_30,(int)local_74 - iVar10);
                (*(code *)PTR_ASN1_TYPE_free_006a7498)(iVar7);
                if (iVar10 == 0) {
                  pcVar13 = "Error parsing structure\n";
                  uVar5 = *(undefined4 *)puVar3;
                  goto LAB_00423aa4;
                }
                iVar7 = (*(code *)PTR_ASN1_TYPE_get_006a74b0)(iVar10);
                if (((iVar7 == 6) || (iVar7 == 1)) || (iVar7 == 5)) {
                  uVar11 = *(undefined4 *)puVar3;
                  uVar5 = (*(code *)PTR_ASN1_tag2str_006a74b4)(iVar7);
                  (*(code *)PTR_BIO_printf_006a6e38)(uVar11,"Can\'t parse %s type\n",uVar5);
                  goto LAB_00423ab0;
                }
                iVar18 = iVar18 + 1;
                local_70 = (*(int **)(iVar10 + 4))[2];
                local_74 = (char *)**(int **)(iVar10 + 4);
                iVar7 = iVar10;
              }
            }
          }
          if ((int)local_74 <= local_50) {
            iVar18 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"Error: offset too large\n");
            goto LAB_00423950;
          }
          if ((local_48 == 0) || ((int)local_74 - local_50 < local_48)) {
            local_48 = (int)local_74 - local_50;
          }
          if ((local_78 == (char *)0x0) ||
             (iVar18 = (*(code *)PTR_BIO_write_006a6e14)(local_78,local_70 + local_50,local_48),
             local_48 == iVar18)) {
            if ((!bVar2) &&
               (iVar18 = (*(code *)PTR_ASN1_parse_dump_006a74b8)
                                   (param_2,local_70 + local_50,local_48,local_64,local_3c),
               iVar18 == 0)) {
              iVar18 = 1;
              (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar3);
              goto LAB_00423950;
            }
            iVar18 = 0;
            goto LAB_00423950;
          }
          uVar5 = *(undefined4 *)puVar3;
          pcVar13 = "Error writing output\n";
LAB_00423aa4:
          (*(code *)PTR_BIO_printf_006a6e38)(uVar5,pcVar13);
LAB_00423ab0:
          iVar18 = 1;
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar3);
          goto LAB_00423950;
        }
        if (local_4c != (char *)0x0) {
          uVar5 = *(undefined4 *)puVar3;
          local_34 = 0;
          uVar11 = (*(code *)PTR_NCONF_new_006a6e58)(0);
          iVar10 = (*(code *)PTR_NCONF_load_006a6e5c)(uVar11,local_4c,&local_34);
          if (iVar10 == 0) {
LAB_00423b78:
            if (0 < local_34) {
              unaff_s7 = (undefined *)0x0;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (uVar5,"Error on line %ld of config file \'%s\'\n",local_34,local_4c);
              goto LAB_00423ba0;
            }
            unaff_s7 = (undefined *)0x0;
            (*(code *)PTR_BIO_printf_006a6e38)(uVar5,"Error loading config file \'%s\'\n",local_4c);
            goto LAB_00423ba0;
          }
          local_40 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                       (uVar11,"default",&DAT_00632424);
          if (local_40 == (char *)0x0) {
            unaff_s7 = (undefined *)0x0;
            (*(code *)PTR_BIO_printf_006a6e38)(uVar5,"Can\'t find \'asn1\' in \'%s\'\n",local_4c);
            goto LAB_00423ba0;
          }
          goto LAB_00423318;
        }
        if (iVar10 == 3) {
          uVar5 = (*(code *)PTR_BIO_f_base64_006a74bc)();
          puVar8 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar5);
          puVar16 = puVar8;
          if (puVar8 == (undefined *)0x0) goto LAB_00423e3c;
          (*(code *)PTR_BIO_push_006a74c4)(puVar8,param_1);
          puVar16 = param_1;
        }
        else {
          puVar16 = (undefined *)0x0;
        }
        local_74 = (char *)0x0;
        while (iVar10 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(iVar14,(int)local_74 + 0x2000),
              param_1 = puVar8, iVar10 != 0) {
          iVar10 = (*(code *)PTR_BIO_read_006a74c0)
                             (puVar8,*(int *)(iVar14 + 4) + (int)local_74,0x2000);
          if (iVar10 < 1) goto LAB_004233a8;
          local_74 = (char *)((int)local_74 + iVar10);
        }
LAB_00423e3c:
        iVar10 = 0;
        iVar18 = 1;
        goto LAB_00423950;
      }
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar3);
      (*(code *)PTR_BIO_free_006a6e70)(0);
      if (param_2 != (undefined4 *)0x0) {
        puVar16 = (undefined *)0x0;
        iVar18 = 1;
        iVar14 = 0;
        iVar10 = 0;
        goto LAB_0042386c;
      }
      goto LAB_00422fb8;
    }
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"Memory allocation failure\n");
  }
LAB_00422fa8:
  (*(code *)PTR_BIO_free_006a6e70)(0);
LAB_00422fb8:
  iVar14 = 0;
  iVar10 = 0;
  iVar18 = 1;
  do {
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar3);
    do {
      if (iVar14 != 0) {
        (*(code *)PTR_BUF_MEM_free_006a7494)(iVar14);
      }
      if (iVar10 != 0) {
        (*(code *)PTR_ASN1_TYPE_free_006a7498)(iVar10);
      }
      if (iVar9 != 0) {
        (*(code *)PTR_sk_free_006a6e80)(iVar9);
      }
      (*(code *)PTR_OBJ_cleanup_006a6e98)();
      if (local_2c == *(int *)puVar4) {
        return iVar18;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00423d4c:
      uVar11 = 0;
LAB_00423ba0:
      (*(code *)PTR_NCONF_free_006a6e6c)(uVar11);
      (*(code *)PTR_ASN1_TYPE_free_006a7498)(unaff_s7);
LAB_00423bc0:
      iVar10 = 0;
      puVar16 = (undefined *)0x0;
      iVar18 = 1;
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar3);
LAB_00423950:
      (*(code *)PTR_BIO_free_006a6e70)(local_78);
LAB_00423858:
      (*(code *)PTR_BIO_free_006a6e70)(param_1);
      unaff_s7 = puVar16;
      if (param_2 != (undefined4 *)0x0) {
LAB_0042386c:
        (*(code *)PTR_BIO_free_all_006a6e74)(param_2);
        unaff_s7 = puVar16;
      }
      if (unaff_s7 != (undefined *)0x0) {
        (*(code *)PTR_BIO_free_006a6e70)(unaff_s7);
      }
    } while (iVar18 == 0);
  } while( true );
}

