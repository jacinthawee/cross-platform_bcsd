
bool srp_main(int param_1,int param_2)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  char **ppcVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  char *pcVar11;
  char *pcVar12;
  undefined4 uVar13;
  undefined1 *puVar14;
  char *pcVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  bool bVar19;
  int iVar20;
  char *pcVar21;
  int iVar22;
  char **ppcVar23;
  int local_b4;
  int local_b0;
  int local_ac;
  char *local_a8;
  int local_a4;
  int local_9c;
  int local_98;
  char *local_90;
  char *local_84;
  char *local_80;
  char *local_7c;
  char *local_78;
  char *local_74;
  int local_54;
  int local_50;
  int local_4c;
  undefined auStack_48 [4];
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006aabf0;
  puVar2 = PTR_bio_err_006a7f3c;
  local_4c = -1;
  local_54 = 0;
  local_50 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  conf = 0;
  section = (char *)0x0;
  if (*(int *)puVar2 == 0) {
    uVar10 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar22 = (*(code *)PTR_BIO_new_006a7fa4)(uVar10);
    *(int *)puVar2 = iVar22;
    if (iVar22 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar22,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
    }
  }
  param_1 = param_1 + -1;
  ppcVar23 = (char **)(param_2 + 4);
  if (0 < param_1) {
    local_78 = (char *)0x0;
    local_a8 = (char *)0x0;
    local_90 = (char *)0x0;
    local_74 = (char *)0x0;
    pcVar21 = (char *)0x0;
    local_7c = (char *)0x0;
    iVar22 = 0;
    local_80 = (char *)0x0;
    local_a4 = 0;
    local_9c = 0;
    local_98 = 0;
    local_ac = 0;
LAB_00476f8c:
    pcVar15 = *ppcVar23;
    iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-verbose");
    if (iVar5 == 0) {
      iVar22 = iVar22 + 1;
    }
    else {
      iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-config");
      if (iVar5 == 0) {
        iVar5 = param_1 + -1;
        if (param_1 + -1 == 0) goto LAB_00477734;
        pcVar21 = ppcVar23[1];
        param_1 = param_1 + -2;
        ppcVar23 = ppcVar23 + 2;
        goto joined_r0x00476fd8;
      }
      iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-name");
      if (iVar5 == 0) {
        param_1 = param_1 + -1;
        iVar5 = param_1;
        if (param_1 == 0) goto LAB_00477734;
        section = ppcVar23[1];
        ppcVar23 = ppcVar23 + 1;
      }
      else {
        iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-srpvfile");
        if (iVar5 == 0) {
          param_1 = param_1 + -1;
          iVar5 = param_1;
          if (param_1 == 0) goto LAB_00477734;
          local_a8 = ppcVar23[1];
          ppcVar23 = ppcVar23 + 1;
          goto LAB_00476f80;
        }
        iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar15,&DAT_00645fd4);
        if (iVar5 == 0) {
          local_ac = 1;
        }
        else {
          iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-delete");
          if (iVar5 == 0) {
            local_9c = 1;
          }
          else {
            iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-modify");
            if (iVar5 == 0) {
              local_a4 = 1;
            }
            else {
              iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-list");
              if (iVar5 != 0) {
                cVar1 = *pcVar15;
                if ((((cVar1 == '-') && (pcVar15[1] == 'g')) && (pcVar15[2] == 'n')) &&
                   (pcVar15[3] == '\0')) {
                  param_1 = param_1 + -1;
                  iVar5 = param_1;
                  if (param_1 != 0) {
                    local_74 = ppcVar23[1];
                    ppcVar23 = ppcVar23 + 1;
                    goto LAB_00476f80;
                  }
                }
                else {
                  iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-userinfo");
                  if (iVar5 == 0) {
                    param_1 = param_1 + -1;
                    iVar5 = param_1;
                    if (param_1 != 0) {
                      local_90 = ppcVar23[1];
                      ppcVar23 = ppcVar23 + 1;
                      goto LAB_00476f80;
                    }
                  }
                  else {
                    iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-passin");
                    if (iVar5 == 0) {
                      param_1 = param_1 + -1;
                      iVar5 = param_1;
                      if (param_1 != 0) {
                        local_80 = ppcVar23[1];
                        ppcVar23 = ppcVar23 + 1;
                        goto LAB_00476f80;
                      }
                    }
                    else {
                      iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-passout");
                      if (iVar5 == 0) {
                        param_1 = param_1 + -1;
                        iVar5 = param_1;
                        if (param_1 != 0) {
                          local_7c = ppcVar23[1];
                          ppcVar23 = ppcVar23 + 1;
                          goto LAB_00476f80;
                        }
                      }
                      else {
                        iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-engine");
                        if (iVar5 == 0) {
                          param_1 = param_1 + -1;
                          iVar5 = param_1;
                          if (param_1 != 0) {
                            local_78 = ppcVar23[1];
                            ppcVar23 = ppcVar23 + 1;
                            goto LAB_00476f80;
                          }
                        }
                        else {
                          iVar5 = param_1;
                          if (cVar1 != '-') goto LAB_00476fe8;
                        }
                      }
                    }
                  }
                }
LAB_00477734:
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2,"unknown option %s\n",pcVar15);
                iVar16 = local_9c * 2 + local_a4;
                iVar17 = local_9c + local_ac + local_a4 + local_98;
                bVar19 = true;
                goto LAB_00477008;
              }
              local_98 = 1;
            }
          }
        }
      }
    }
LAB_00476f80:
    param_1 = param_1 + -1;
    ppcVar23 = ppcVar23 + 1;
joined_r0x00476fd8:
    iVar5 = param_1;
    if (param_1 == 0) goto LAB_00476fe8;
    goto LAB_00476f8c;
  }
  iVar16 = 0;
  local_78 = (char *)0x0;
  iVar17 = 0;
  local_a8 = (char *)0x0;
  pcVar21 = (char *)0x0;
  local_90 = (char *)0x0;
  iVar22 = 0;
  local_74 = (char *)0x0;
  local_7c = (char *)0x0;
  bVar19 = false;
  local_80 = (char *)0x0;
  local_a4 = 0;
  local_9c = 0;
  local_98 = 0;
  local_ac = 0;
  goto LAB_00477038;
LAB_00476fe8:
  iVar16 = local_9c * 2 + local_a4;
  iVar17 = local_ac + local_9c + local_a4 + local_98;
  bVar19 = false;
LAB_00477008:
  param_1 = iVar5;
  if ((local_a8 != (char *)0x0) && (pcVar21 != (char *)0x0)) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar2,"-dbfile and -configfile cannot be specified together.\n");
    bVar19 = true;
  }
LAB_00477038:
  if (iVar17 != 1) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar2,
               "Exactly one of the options -add, -delete, -modify -list must be specified.\n");
    bVar19 = true;
  }
  if ((iVar16 == 1) && (param_1 < 1)) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar2,"Need at least one user for options -add, -delete, -modify. \n"
              );
    bVar19 = true;
  }
  if (((local_54 == 0) && (local_50 == 0)) || (param_1 == 1)) {
    if (bVar19) goto LAB_00477090;
    (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
    setup_engine(*(undefined4 *)puVar2,local_78,0);
    iVar5 = app_passwd(*(undefined4 *)puVar2,local_80,local_7c,&local_54,&local_50);
    if (iVar5 == 0) {
      pcVar21 = "Error getting passwords\n";
      uVar10 = *(undefined4 *)PTR_bio_err_006a7f3c;
      goto LAB_00477110;
    }
    if (local_a8 != (char *)0x0) {
LAB_00477328:
      iVar16 = 0;
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
LAB_00477338:
      if (iVar22 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar2,"Trying to read SRP verifier file \"%s\"\n",local_a8);
      }
      iVar5 = load_index(local_a8,auStack_48);
      if (iVar5 == 0) {
        pcVar15 = (char *)0x0;
        goto LAB_0047712c;
      }
      iVar18 = 0;
      local_b0 = -1;
      iVar17 = -1;
      iVar6 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*(int *)(iVar5 + 4) + 4));
      if (0 < iVar6) {
        do {
          ppcVar7 = (char **)(*(code *)PTR_sk_value_006a7f24)
                                       (*(undefined4 *)(*(int *)(iVar5 + 4) + 4),iVar18);
          if (**ppcVar7 == 'I') {
            if (((local_b0 < 0) && (local_74 != (char *)0x0)) &&
               (iVar17 = (*(code *)PTR_strcmp_006aac20)(local_74,ppcVar7[3]), iVar17 == 0)) {
              local_b0 = iVar18;
            }
            iVar17 = iVar18;
            if ((-1 < iVar18) && (1 < iVar22)) {
              uVar10 = *(undefined4 *)puVar2;
              puVar9 = (undefined4 *)
                       (*(code *)PTR_sk_value_006a7f24)
                                 (*(undefined4 *)(*(int *)(iVar5 + 4) + 4),iVar18);
              (*(code *)PTR_BIO_printf_006a7f38)(uVar10,"%s \"%s\"\n","g N entry",puVar9[3]);
              iVar6 = 0;
              do {
                uVar10 = *puVar9;
                iVar20 = iVar6 + 1;
                puVar9 = puVar9 + 1;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2,"  %d = \"%s\"\n",iVar6,uVar10);
                iVar6 = iVar20;
              } while (iVar20 != 6);
            }
          }
          iVar18 = iVar18 + 1;
          iVar6 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*(int *)(iVar5 + 4) + 4));
        } while (iVar18 < iVar6);
      }
      if (iVar22 == 0) {
        if (local_b0 < 0) {
          if (iVar17 < 1) {
            iVar17 = 0;
          }
          else {
LAB_00477b54:
            iVar17 = (*(code *)PTR_SRP_get_default_gN_006a901c)(local_74);
            if (iVar17 == 0) {
              pcVar15 = (char *)0x0;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar2,"No g and N value for index \"%s\"\n",local_74);
              goto LAB_0047712c;
            }
            iVar17 = 0;
            if (iVar22 != 0) goto LAB_00477b6c;
          }
        }
        else {
          iVar17 = (*(code *)PTR_sk_value_006a7f24)
                             (*(undefined4 *)(*(int *)(iVar5 + 4) + 4),local_b0);
        }
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Database initialised\n");
        if (local_b0 < 0) {
          if (0 < iVar17) goto LAB_00477b54;
LAB_00477b6c:
          iVar17 = 0;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar2,"Database has no g N information.\n");
          if (1 < iVar22) {
LAB_00477b94:
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Starting user processing\n");
          }
        }
        else {
          iVar17 = (*(code *)PTR_sk_value_006a7f24)
                             (*(undefined4 *)(*(int *)(iVar5 + 4) + 4),local_b0);
          uVar10 = *(undefined4 *)PTR_bio_err_006a7f3c;
          if (iVar22 != 1) {
            puVar9 = (undefined4 *)
                     (*(code *)PTR_sk_value_006a7f24)
                               (*(undefined4 *)(*(int *)(iVar5 + 4) + 4),local_b0);
            (*(code *)PTR_BIO_printf_006a7f38)(uVar10,"%s \"%s\"\n","Default g and N",puVar9[3]);
            iVar6 = 0;
            do {
              uVar10 = *puVar9;
              iVar18 = iVar6 + 1;
              puVar9 = puVar9 + 1;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar2,"  %d = \"%s\"\n",iVar6,uVar10);
              iVar6 = iVar18;
            } while (iVar18 != 6);
            goto LAB_00477b94;
          }
        }
      }
      pcVar21 = (char *)0x0;
      if (0 < param_1) {
        pcVar21 = *ppcVar23;
        ppcVar23 = ppcVar23 + 1;
      }
      bVar19 = false;
      local_b4 = 0;
      local_84 = "user \"%s\" does not exist, operation ignored. t\n";
      if (local_98 != 0) goto LAB_0047750c;
LAB_00477480:
      if (pcVar21 != (char *)0x0) {
LAB_00477488:
        if (1 < iVar22) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar2,"Processing user \"%s\"\n",pcVar21);
        }
        iVar6 = get_index(iVar5,pcVar21,0x55);
        if (iVar6 < 0) goto LAB_004774dc;
        uVar10 = *(undefined4 *)puVar2;
        if ((iVar22 == 0) && (local_98 == 0)) {
          if (local_ac != 0) goto LAB_00477e1c;
          goto LAB_00477618;
        }
        do {
          print_user_part_3(iVar5,uVar10,iVar6,1);
LAB_004774dc:
          if (local_98 == 0) {
            if (local_ac == 0) {
LAB_00477618:
              if (local_a4 == 0) {
                local_98 = 0;
                if (local_9c != 0) {
                  if (iVar6 < 0) {
                    uVar10 = *(undefined4 *)puVar2;
                    pcVar15 = local_84;
                    goto LAB_00478084;
                  }
                  puVar9 = (undefined4 *)
                           (*(code *)PTR_sk_value_006a7f24)
                                     (*(undefined4 *)(*(int *)(iVar5 + 4) + 4),iVar6);
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar2,"user \"%s\" revoked. t\n",pcVar21);
                  bVar19 = true;
                  *(undefined *)*puVar9 = 0x52;
                }
              }
              else {
                if (iVar6 < 0) {
                  uVar10 = *(undefined4 *)puVar2;
                  pcVar15 = "user \"%s\" does not exist, operation ignored.\n";
                }
                else {
                  ppcVar7 = (char **)(*(code *)PTR_sk_value_006a7f24)
                                               (*(undefined4 *)(*(int *)(iVar5 + 4) + 4),iVar6);
                  if (**ppcVar7 != 'v') {
                    if (**ppcVar7 == 'V') {
                      if (iVar22 == 0) {
                        pcVar15 = ppcVar7[4];
                      }
                      else {
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*(undefined4 *)puVar2,"Verifying password for user \"%s\"\n",
                                   pcVar21);
                        pcVar15 = ppcVar7[4];
                      }
                      iVar18 = get_index(iVar5,pcVar15,0x49);
                      if (iVar18 < 0) {
                        pcVar15 = ppcVar7[1];
                        pcVar11 = ppcVar7[2];
LAB_00477688:
                        pcVar12 = ppcVar7[4];
                        uVar10 = 0;
                      }
                      else {
                        iVar6 = (*(code *)PTR_sk_value_006a7f24)
                                          (*(undefined4 *)(*(int *)(iVar5 + 4) + 4),iVar6);
                        pcVar15 = ppcVar7[1];
                        pcVar11 = ppcVar7[2];
                        if (iVar6 == 0) goto LAB_00477688;
                        pcVar12 = *(char **)(iVar6 + 8);
                        uVar10 = *(undefined4 *)(iVar6 + 4);
                      }
                      iVar6 = srp_verify_user(pcVar21,pcVar15,pcVar11,pcVar12,uVar10,local_54,
                                              *(undefined4 *)puVar2,iVar22);
                      if (iVar6 != 0) goto LAB_00477d58;
                      pcVar15 = "Invalid password for user \"%s\", operation abandoned.\n";
                      uVar10 = *(undefined4 *)PTR_bio_err_006a7f3c;
                    }
                    else {
LAB_00477d58:
                      if (iVar22 != 0) {
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*(undefined4 *)puVar2,"Password for user \"%s\" ok.\n",pcVar21);
                      }
                      if (iVar17 == 0) {
                        uVar13 = 0;
                        uVar10 = 0;
                      }
                      else {
                        uVar13 = *(undefined4 *)(iVar17 + 8);
                        uVar10 = *(undefined4 *)(iVar17 + 4);
                      }
                      iVar6 = srp_create_user(pcVar21,ppcVar7 + 1,ppcVar7 + 2,uVar13,uVar10,local_50
                                              ,*(undefined4 *)puVar2,iVar22);
                      puVar3 = PTR_BUF_strdup_006a80dc;
                      if (iVar6 != 0) {
                        **ppcVar7 = 'v';
                        pcVar21 = (char *)(*(code *)puVar3)(iVar6);
                        ppcVar7[4] = pcVar21;
                        if (((ppcVar7[3] != (char *)0x0) && (pcVar21 != (char *)0x0)) &&
                           ((*ppcVar7 != (char *)0x0 &&
                            ((ppcVar7[1] != (char *)0x0 && (ppcVar7[2] != (char *)0x0)))))) {
                          if (local_90 != (char *)0x0) {
                            pcVar21 = (char *)(*(code *)PTR_BUF_strdup_006a80dc)(local_90);
                            ppcVar7[5] = pcVar21;
                            if (pcVar21 == (char *)0x0) goto LAB_00478030;
                          }
                          local_98 = 0;
                          bVar19 = true;
                          goto LAB_004774f4;
                        }
                        goto LAB_00478030;
                      }
                      pcVar15 = "Cannot create srp verifier for user \"%s\", operation abandoned.\n"
                      ;
                      uVar10 = *(undefined4 *)PTR_bio_err_006a7f3c;
                    }
                    local_b4 = local_b4 + 1;
                    (*(code *)PTR_BIO_printf_006a7f38)(uVar10,pcVar15,pcVar21);
                    if (iVar22 == 0) goto LAB_00477580;
                    goto LAB_004776f0;
                  }
                  uVar10 = *(undefined4 *)puVar2;
                  pcVar15 = "user \"%s\" already updated, operation ignored.\n";
                }
LAB_00478084:
                local_98 = 0;
                local_b4 = local_b4 + 1;
                (*(code *)PTR_BIO_printf_006a7f38)(uVar10,pcVar15,pcVar21);
              }
            }
            else {
              if (iVar6 < 0) {
                local_40 = 0;
                local_3c = 0;
                local_30 = 0;
                if (iVar17 == 0) {
                  uVar10 = 0;
                  pcVar15 = local_74;
                }
                else {
                  uVar10 = *(undefined4 *)(iVar17 + 4);
                  pcVar15 = *(char **)(iVar17 + 8);
                }
                iVar6 = srp_create_user(pcVar21,&local_40,&local_3c,pcVar15,uVar10,local_50,
                                        *(undefined4 *)puVar2,iVar22);
                if (iVar6 == 0) {
                  local_b4 = local_b4 + 1;
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)PTR_bio_err_006a7f3c,
                             "Cannot create srp verifier for user \"%s\", operation abandoned .\n",
                             pcVar21);
                  goto LAB_00478030;
                }
                local_38 = (*(code *)PTR_BUF_strdup_006a80dc)(pcVar21);
                local_44 = (*(code *)PTR_BUF_strdup_006a80dc)("v");
                local_34 = (*(code *)PTR_BUF_strdup_006a80dc)(iVar6);
                if (local_38 != 0) {
                  if ((((local_34 != 0) && (local_44 != 0)) && (local_40 != 0)) && (local_3c != 0))
                  {
                    if ((local_90 == (char *)0x0) ||
                       (local_30 = (*(code *)PTR_BUF_strdup_006a80dc)(local_90), local_30 != 0)) {
                      uVar10 = *(undefined4 *)puVar2;
                      piVar8 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x1c,"srp.c",0xb6);
                      if (piVar8 == (int *)0x0) {
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*(undefined4 *)PTR_bio_err_006a7f3c,"Memory allocation failure\n"
                                  );
                      }
                      else {
                        piVar8[6] = 0;
                        puVar3 = PTR_TXT_DB_insert_006a8128;
                        *piVar8 = local_44;
                        local_44 = 0;
                        piVar8[1] = local_40;
                        local_40 = 0;
                        piVar8[2] = local_3c;
                        local_3c = 0;
                        piVar8[3] = local_38;
                        local_38 = 0;
                        piVar8[4] = local_34;
                        local_34 = 0;
                        piVar8[5] = local_30;
                        local_30 = 0;
                        iVar6 = (*(code *)puVar3)(*(undefined4 *)(iVar5 + 4),piVar8);
                        if (iVar6 != 0) {
                          param_1 = param_1 + -1;
                          bVar19 = true;
                          if (0 < param_1) goto LAB_00477500;
                          break;
                        }
                        (*(code *)PTR_BIO_printf_006a7f38)(uVar10,"failed to update srpvfile\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (uVar10,"TXT_DB error number %ld\n",
                                   *(undefined4 *)(*(int *)(iVar5 + 4) + 0x10));
                        (*(code *)PTR_CRYPTO_free_006a7f88)(piVar8);
                      }
                    }
                    if (local_38 == 0) goto LAB_00477fb8;
                  }
                  (*(code *)PTR_CRYPTO_free_006a7f88)();
                }
LAB_00477fb8:
                if (local_34 != 0) {
                  (*(code *)PTR_CRYPTO_free_006a7f88)(local_34);
                }
                if (local_30 != 0) {
                  (*(code *)PTR_CRYPTO_free_006a7f88)();
                }
                if (local_44 != 0) {
                  (*(code *)PTR_CRYPTO_free_006a7f88)();
                }
                if (local_40 != 0) {
                  (*(code *)PTR_CRYPTO_free_006a7f88)();
                }
                if (local_3c != 0) {
                  (*(code *)PTR_CRYPTO_free_006a7f88)();
                }
                goto LAB_00478030;
              }
LAB_00477e1c:
              puVar9 = (undefined4 *)
                       (*(code *)PTR_sk_value_006a7f24)
                                 (*(undefined4 *)(*(int *)(iVar5 + 4) + 4),iVar6);
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar2,"user \"%s\" reactivated.\n",pcVar21);
              local_98 = 0;
              bVar19 = true;
              *(undefined *)*puVar9 = 0x56;
            }
          }
          else {
            if (pcVar21 == (char *)0x0) goto LAB_00477ed0;
            if (iVar6 < 0) {
              local_b4 = local_b4 + 1;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar2,"user \"%s\" does not exist, ignored. t\n",pcVar21);
            }
          }
LAB_004774f4:
          while( true ) {
            param_1 = param_1 + -1;
            if (param_1 < 1) goto LAB_00477d38;
LAB_00477500:
            pcVar21 = *ppcVar23;
            ppcVar23 = ppcVar23 + 1;
            if (local_98 == 0) goto LAB_00477480;
LAB_0047750c:
            if (pcVar21 != (char *)0x0) goto LAB_00477488;
            iVar6 = get_index(iVar5,0,0x55);
            if (-1 < iVar6) break;
LAB_00477ed0:
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"List all users\n");
            for (iVar6 = 0;
                iVar18 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*(int *)(iVar5 + 4) + 4)),
                iVar6 < iVar18; iVar6 = iVar6 + 1) {
              print_user_part_3(iVar5,*(undefined4 *)puVar2,iVar6,1);
            }
            local_98 = 0;
          }
          uVar10 = *(undefined4 *)puVar2;
        } while( true );
      }
LAB_00477d38:
      if (iVar22 == 0) {
        if (bVar19) {
          iVar17 = 0;
          while (iVar6 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*(int *)(iVar5 + 4) + 4)),
                iVar17 < iVar6) {
            ppcVar23 = (char **)(*(code *)PTR_sk_value_006a7f24)
                                          (*(undefined4 *)(*(int *)(iVar5 + 4) + 4),iVar17);
            if (**ppcVar23 == 'v') {
              **ppcVar23 = 'V';
              iVar17 = iVar17 + 1;
            }
            else {
              iVar17 = iVar17 + 1;
            }
          }
          iVar17 = save_index(local_a8,"new",iVar5);
          if (iVar17 == 0) goto LAB_00477580;
          iVar17 = rotate_index(local_a8,"new","old");
          if (iVar17 == 0) goto LAB_00477580;
        }
LAB_00477d4c:
        bVar19 = local_b4 != 0;
LAB_00478034:
        if (local_b4 == 0) goto LAB_004785dc;
        if (iVar22 == 0) {
          if (bVar19 == false) goto LAB_00477150;
          goto LAB_00477580;
        }
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"User procession done.\n");
        if (!bVar19) goto LAB_00477d4c;
        iVar17 = 0;
        while (iVar6 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*(int *)(iVar5 + 4) + 4)),
              puVar3 = PTR_bio_err_006a7f3c, iVar17 < iVar6) {
          ppcVar23 = (char **)(*(code *)PTR_sk_value_006a7f24)
                                        (*(undefined4 *)(*(int *)(iVar5 + 4) + 4),iVar17);
          if (**ppcVar23 == 'v') {
            **ppcVar23 = 'V';
            print_user_part_3(iVar5,*(undefined4 *)puVar2,iVar17,iVar22);
            iVar17 = iVar17 + 1;
          }
          else {
            iVar17 = iVar17 + 1;
          }
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Trying to update srpvfile.\n");
        iVar17 = save_index(local_a8,"new",iVar5);
        if (iVar17 != 0) {
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Temporary srpvfile created.\n");
          iVar17 = rotate_index(local_a8,"new","old");
          if (iVar17 == 0) {
LAB_00478030:
            bVar19 = true;
          }
          else {
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"srpvfile updated.\n");
            bVar19 = local_b4 != 0;
          }
          goto LAB_00478034;
        }
        bVar19 = true;
        if (local_b4 == 0) goto LAB_00477710;
LAB_004776f0:
        bVar19 = true;
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"User errors %d.\n",local_b4);
LAB_00477710:
      pcVar15 = (char *)0x0;
      goto LAB_00477714;
    }
    if (pcVar21 == (char *)0x0) {
      pcVar21 = (char *)(*(code *)PTR_getenv_006aab6c)("OPENSSL_CONF");
      if (pcVar21 == (char *)0x0) {
        pcVar11 = (char *)(*(code *)PTR_getenv_006aab6c)("SSLEAY_CONF");
        pcVar15 = pcVar21;
        pcVar21 = pcVar11;
        if (pcVar11 == (char *)0x0) {
          uVar10 = (*(code *)PTR_X509_get_default_cert_area_006a8164)();
          iVar5 = (*(code *)PTR_strlen_006aab30)(uVar10);
          iVar5 = iVar5 + 0xd;
          pcVar15 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar5,"srp.c",0x1c4);
          (*(code *)PTR_BUF_strlcpy_006a8064)(pcVar15,uVar10,iVar5);
          (*(code *)PTR_BUF_strlcat_006a8068)(pcVar15,&DAT_0063ba98,iVar5);
          (*(code *)PTR_BUF_strlcat_006a8068)(pcVar15,"openssl.cnf",iVar5);
          pcVar21 = pcVar15;
        }
      }
      else {
        pcVar15 = (char *)0x0;
      }
    }
    else {
      pcVar15 = (char *)0x0;
    }
    if (iVar22 != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"Using configuration from %s\n",pcVar21);
    }
    conf = (*(code *)PTR_NCONF_new_006a7f58)(0);
    iVar5 = (*(code *)PTR_NCONF_load_006a7f5c)(conf,pcVar21,&local_4c);
    if (iVar5 < 1) {
      if (local_4c < 1) {
        iVar16 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar2,"error loading the config file \'%s\'\n",pcVar21);
        iVar5 = 0;
      }
      else {
        iVar16 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar2,"error on line %ld of config file \'%s\'\n",local_4c,
                   pcVar21);
        iVar5 = 0;
      }
      goto LAB_0047712c;
    }
    if (pcVar15 != (char *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar15);
    }
    iVar5 = load_config(*(undefined4 *)puVar2,conf);
    if (iVar5 != 0) {
      if (section == (char *)0x0) {
        if (iVar22 != 0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)PTR_bio_err_006a7f3c,
                     "trying to read default_srp in \" BASE_SECTION \"\n");
        }
        section = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)(conf,"srp","default_srp");
        if (section == (char *)0x0) {
          pcVar15 = (char *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar2,"variable lookup failed for %s::%s\n","srp","default_srp"
                    );
          iVar16 = 0;
          iVar5 = 0;
          goto LAB_0047712c;
        }
      }
      if (conf == 0) {
        iVar16 = 0;
      }
      else {
        iVar16 = (*(code *)PTR_NCONF_get_string_006a7fa8)(conf,"srp","RANDFILE");
      }
      if (iVar22 != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar2,"trying to read srpvfile in section \"%s\"\n",section);
      }
      local_a8 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)(conf,section,"srpvfile");
      if (local_a8 == (char *)0x0) {
        pcVar15 = (char *)0x0;
        iVar5 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar2,"variable lookup failed for %s::%s\n",section,"srpvfile");
        goto LAB_0047712c;
      }
      if (iVar16 == 0) goto LAB_00477328;
      app_RAND_load_file(iVar16,*(undefined4 *)puVar2,0);
      goto LAB_00477338;
    }
  }
  else {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar2,"-passin, -passout arguments only valid with one user.\n");
LAB_00477090:
    if (srp_usage._0_4_ != 0) {
      puVar14 = srp_usage;
      do {
        puVar14 = (undefined1 *)((int)puVar14 + 4);
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"%s");
      } while (*(int *)puVar14 != 0);
    }
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2," -rand file%cfile%c...\n",0x3a,0x3a);
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar2,
               "                 load the file (or the files in the directory) into\n");
    uVar10 = *(undefined4 *)puVar2;
    pcVar21 = "                 the random number generator\n";
LAB_00477110:
    (*(code *)PTR_BIO_printf_006a7f38)(uVar10,pcVar21);
  }
  pcVar15 = (char *)0x0;
  iVar16 = 0;
  iVar5 = 0;
LAB_0047712c:
  bVar19 = true;
  while( true ) {
    if (iVar22 != 0) {
LAB_00477714:
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"SRP terminating with code %d.\n",bVar19);
    }
    if (pcVar15 != (char *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar15);
    }
    if (bVar19 != false) {
LAB_00477580:
      bVar19 = true;
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
    }
LAB_00477150:
    if (iVar16 != 0) {
      app_RAND_write_file(iVar16,*(undefined4 *)puVar2);
    }
    if (conf != 0) {
      (*(code *)PTR_NCONF_free_006a7f6c)();
    }
    if (iVar5 != 0) {
      free_index(iVar5);
    }
    (*(code *)PTR_OBJ_cleanup_006a7f98)();
    if (local_2c == *(int *)puVar4) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_004785dc:
    pcVar15 = (char *)0x0;
  }
  return bVar19;
}

