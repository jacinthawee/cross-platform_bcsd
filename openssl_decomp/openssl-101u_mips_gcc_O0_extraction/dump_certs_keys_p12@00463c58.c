
uint dump_certs_keys_p12(char *param_1,int param_2,char *param_3,undefined4 param_4,uint param_5,
                        int param_6)

{
  int *piVar1;
  char **ppcVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint unaff_s0;
  uint uVar9;
  undefined4 *unaff_s1;
  undefined4 *unaff_s2;
  int unaff_s4;
  undefined4 *puVar10;
  undefined4 *puVar11;
  char *pcVar12;
  int iStack_234;
  undefined4 *puStack_230;
  char *pcStack_22c;
  undefined4 uStack_228;
  char *pcStack_224;
  char *pcStack_220;
  char *pcStack_21c;
  char *pcStack_218;
  int iStack_214;
  int iStack_210;
  int iStack_20c;
  int iStack_208;
  int iStack_204;
  char *pcStack_200;
  int iStack_1fc;
  int iStack_1f8;
  int iStack_1f4;
  int iStack_1f0;
  int iStack_1ec;
  int iStack_1e8;
  undefined4 uStack_1e4;
  char *pcStack_1e0;
  char *pcStack_1dc;
  char *pcStack_1d8;
  int iStack_1d4;
  int iStack_1d0;
  int iStack_1cc;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  char *pcStack_1bc;
  char *pcStack_1b8;
  undefined auStack_1b4 [136];
  char acStack_12c [52];
  char acStack_f8 [52];
  int iStack_c4;
  uint uStack_c0;
  undefined4 *puStack_bc;
  undefined4 *puStack_b8;
  char *pcStack_b4;
  int iStack_b0;
  char *pcStack_ac;
  undefined4 uStack_a8;
  int iStack_a4;
  uint uStack_a0;
  code *pcStack_9c;
  uint local_88;
  int local_84;
  int local_80;
  undefined *local_78;
  int local_6c;
  uint local_68;
  int local_64;
  uint local_60;
  char *local_5c;
  uint local_58;
  char *local_54;
  char *local_50;
  undefined4 *local_4c;
  undefined4 *local_48;
  uint local_44;
  char *local_40;
  char *local_3c;
  int *local_38;
  uint local_34;
  undefined4 local_30;
  int local_2c;
  
  local_38 = (int *)PTR___stack_chk_guard_006a9ae8;
  local_78 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_64 = (*(code *)PTR_PKCS12_unpack_authsafes_006a7230)(param_2);
  if (local_64 == 0) {
    uVar9 = 0;
  }
  else {
    local_68 = param_5 & 4;
    local_6c = 0;
    local_60 = param_5 & 1;
    local_58 = param_5 & 2;
    local_44 = param_5 & 0x10;
    local_34 = param_5 & 8;
    local_5c = "Bag Attributes";
    local_50 = "Key Attributes";
    local_3c = "-check_ss_sig";
    local_40 = "%s, Iteration %ld\n";
    local_54 = "-check_ss_sig";
    while (iVar5 = (**(code **)(local_78 + -0x7fb4))(local_64), local_6c < iVar5) {
      iVar5 = (**(code **)(local_78 + -0x7fbc))(local_64,local_6c);
      iVar6 = (**(code **)(local_78 + -0x7cb4))(*(undefined4 *)(iVar5 + 0x10));
      if (iVar6 == 0x15) {
        unaff_s4 = (**(code **)(local_78 + -0x7ba0))(iVar5);
        if (local_68 == 0) goto LAB_00463dc0;
        (**(code **)(local_78 + -0x7fa8))(**(undefined4 **)(local_78 + -0x7fa4),"PKCS7 Data\n");
        if (unaff_s4 == 0) goto LAB_00464330;
LAB_00463dc8:
        unaff_s2 = (undefined4 *)0x0;
        iVar5 = (**(code **)(local_78 + -0x7fb4))(unaff_s4);
        if (0 < iVar5) {
          do {
            unaff_s1 = (undefined4 *)(**(code **)(local_78 + -0x7fbc))(unaff_s4,unaff_s2);
            iVar5 = (**(code **)(local_78 + -0x7cb4))(*unaff_s1);
            if (iVar5 == 0x97) {
              if (local_68 != 0) {
                local_48 = *(undefined4 **)(local_78 + -0x7fa4);
                (**(code **)(local_78 + -0x7fa8))
                          (**(undefined4 **)(local_78 + -0x7fa4),local_3c + 0x15f0);
                local_4c = *(undefined4 **)unaff_s1[1];
                local_30 = (*(undefined4 **)(local_4c[1] + 4))[2];
                iVar5 = (**(code **)(local_78 + -0x7bdc))
                                  (0,&local_30,**(undefined4 **)(local_4c[1] + 4));
                if (iVar5 != 0) {
                  local_48 = (undefined4 *)*local_48;
                  uVar7 = (**(code **)(local_78 + -0x7cb4))(*local_4c);
                  local_4c = (undefined4 *)(**(code **)(local_78 + -0x7cc4))(uVar7);
                  uVar7 = (**(code **)(local_78 + -0x7bd8))(*(undefined4 *)(iVar5 + 4));
                  (**(code **)(local_78 + -0x7fa8))(local_48,local_40,local_4c,uVar7);
                  (**(code **)(local_78 + -0x7bd4))(iVar5);
                }
              }
              if (local_60 == 0) {
                print_attribs(param_1,unaff_s1[2],local_5c);
                iVar5 = (**(code **)(local_78 + -0x7bb8))(unaff_s1,param_3,param_4);
                if (iVar5 != 0) {
                  unaff_s1 = (undefined4 *)(**(code **)(local_78 + -0x7bc0))(iVar5);
                  if (unaff_s1 != (undefined4 *)0x0) {
                    print_attribs(param_1,*(undefined4 *)(iVar5 + 0x10),local_50);
                    (**(code **)(local_78 + -0x7bb4))(iVar5);
                    local_80 = param_6;
                    local_84 = 0;
                    local_88 = 0;
                    (**(code **)(local_78 + -0x7e90))
                              (param_1,unaff_s1,**(undefined4 **)(local_78 + -0x7bbc),0);
                    (**(code **)(local_78 + -0x7f68))(unaff_s1);
                    goto LAB_00463ec0;
                  }
                  (**(code **)(local_78 + -0x7bb4))(iVar5);
                }
LAB_0046417c:
                uVar9 = 0;
                (**(code **)(local_78 + -0x7d88))(unaff_s4,*(undefined4 *)(local_78 + -0x7ba8));
                goto LAB_00464194;
              }
            }
            else if (iVar5 < 0x98) {
              if (iVar5 == 0x96) {
                if (local_68 != 0) {
                  (**(code **)(local_78 + -0x7fa8))
                            (**(undefined4 **)(local_78 + -0x7fa4),"Key bag\n");
                }
                if (local_60 == 0) {
                  print_attribs(param_1,unaff_s1[2],local_5c);
                  unaff_s1 = (undefined4 *)unaff_s1[1];
                  iVar5 = (**(code **)(local_78 + -0x7bc0))(unaff_s1);
                  if (iVar5 == 0) goto LAB_0046417c;
                  print_attribs(param_1,unaff_s1[4],local_50);
                  local_80 = param_6;
                  local_84 = 0;
                  local_88 = 0;
                  (**(code **)(local_78 + -0x7e90))
                            (param_1,iVar5,**(undefined4 **)(local_78 + -0x7bbc),0);
                  (**(code **)(local_78 + -0x7f68))(iVar5);
                }
              }
              else {
LAB_0046405c:
                puVar11 = *(undefined4 **)(local_78 + -0x7fa4);
                (**(code **)(local_78 + -0x7fa8))(*puVar11,local_54 + 0x162c);
                (**(code **)(local_78 + -0x7db4))(*puVar11,*unaff_s1);
                (**(code **)(local_78 + -0x7fa8))(*puVar11,"\n");
              }
            }
            else if (iVar5 == 0x98) {
              if (local_68 != 0) {
                (**(code **)(local_78 + -0x7fa8))
                          (**(undefined4 **)(local_78 + -0x7fa4),"Certificate bag\n");
              }
              if (local_58 == 0) {
                iVar5 = (**(code **)(local_78 + -0x7bcc))(unaff_s1[2],0x9d);
                uVar9 = local_34;
                if (iVar5 != 0) {
                  uVar9 = local_44;
                }
                if (uVar9 == 0) {
                  print_attribs(param_1,unaff_s1[2],local_5c);
                  iVar5 = (**(code **)(local_78 + -0x7cb4))(*(undefined4 *)unaff_s1[1]);
                  if (iVar5 == 0x9e) {
                    iVar5 = (**(code **)(local_78 + -0x7bc8))(unaff_s1);
                    if (iVar5 == 0) goto LAB_0046417c;
                    dump_cert_text(param_1,iVar5);
                    (**(code **)(local_78 + -0x7ec0))(param_1,iVar5);
                    (**(code **)(local_78 + -0x7f50))(iVar5);
                  }
                }
              }
            }
            else {
              if (iVar5 != 0x9b) goto LAB_0046405c;
              if (local_68 != 0) {
                (**(code **)(local_78 + -0x7fa8))
                          (**(undefined4 **)(local_78 + -0x7fa4),"Safe Contents bag\n");
              }
              print_attribs(param_1,unaff_s1[2],local_5c);
              unaff_s1 = (undefined4 *)unaff_s1[1];
              for (iVar5 = 0; iVar6 = (**(code **)(local_78 + -0x7fb4))(unaff_s1), iVar5 < iVar6;
                  iVar5 = iVar5 + 1) {
                uVar7 = (**(code **)(local_78 + -0x7fbc))(unaff_s1,iVar5);
                local_84 = param_6;
                local_88 = param_5;
                iVar6 = dump_certs_pkeys_bag(param_1,uVar7,param_3,param_4);
                if (iVar6 == 0) goto LAB_0046417c;
              }
            }
LAB_00463ec0:
            unaff_s2 = (undefined4 *)((int)unaff_s2 + 1);
            iVar5 = (**(code **)(local_78 + -0x7fb4))(unaff_s4);
          } while ((int)unaff_s2 < iVar5);
        }
        (**(code **)(local_78 + -0x7d88))(unaff_s4,*(undefined4 *)(local_78 + -0x7ba8));
      }
      else if (iVar6 == 0x1a) {
        unaff_s2 = *(undefined4 **)(local_78 + -0x7fa4);
        if (local_68 != 0) {
          (**(code **)(local_78 + -0x7fa8))(*unaff_s2,"PKCS7 Encrypted data: ");
          puVar10 = *(undefined4 **)(*(int *)(*(int *)(iVar5 + 0x14) + 4) + 4);
          puVar11 = *(undefined4 **)(puVar10[1] + 4);
          local_30 = puVar11[2];
          unaff_s1 = (undefined4 *)(**(code **)(local_78 + -0x7bdc))(0,&local_30,*puVar11);
          if (unaff_s1 != (undefined4 *)0x0) {
            uVar8 = *unaff_s2;
            uVar7 = (**(code **)(local_78 + -0x7cb4))(*puVar10);
            unaff_s2 = (undefined4 *)(**(code **)(local_78 + -0x7cc4))(uVar7);
            uVar7 = (**(code **)(local_78 + -0x7bd8))(unaff_s1[1]);
            (**(code **)(local_78 + -0x7fa8))(uVar8,local_40,unaff_s2,uVar7);
            (**(code **)(local_78 + -0x7bd4))(unaff_s1);
          }
        }
        unaff_s4 = (**(code **)(local_78 + -0x7bac))(iVar5,param_3,param_4);
LAB_00463dc0:
        if (unaff_s4 != 0) goto LAB_00463dc8;
LAB_00464330:
        uVar9 = 0;
        goto LAB_00464194;
      }
      local_6c = local_6c + 1;
    }
    uVar9 = 1;
LAB_00464194:
    param_2 = *(int *)(local_78 + -0x7ba4);
    (**(code **)(local_78 + -0x7d88))(local_64);
    unaff_s0 = uVar9;
  }
  if (local_2c == *local_38) {
    return uVar9;
  }
  pcStack_9c = pkcs12_main;
  (**(code **)(local_78 + -0x5330))();
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  puVar11 = (undefined4 *)PTR_enc_006a7224;
  puVar3 = PTR_bio_err_006a6e3c;
  uStack_1c0 = 0x92;
  uStack_a0 = param_5;
  iStack_a4 = param_6;
  pcStack_1bc = (char *)0x0;
  pcStack_1b8 = (char *)0x0;
  iStack_c4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_c0 = unaff_s0;
  puStack_bc = unaff_s1;
  puStack_b8 = unaff_s2;
  pcStack_b4 = param_1;
  iStack_b0 = unaff_s4;
  pcStack_ac = param_3;
  uStack_a8 = param_4;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  uVar7 = (*(code *)PTR_EVP_des_ede3_cbc_006a6e48)();
  iVar5 = *(int *)puVar3;
  *puVar11 = uVar7;
  if (iVar5 == 0) {
    iVar5 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(int *)puVar3 = iVar5;
  }
  iVar5 = load_config(iVar5,0);
  if (iVar5 == 0) {
    uVar9 = 1;
    (*(code *)PTR_BIO_free_006a6e70)(0);
    (*(code *)PTR_BIO_free_all_006a6e74)(0);
    goto LAB_00464ac4;
  }
  param_3 = *(char **)(param_2 + 4);
  param_5 = param_2 + 4;
  iStack_214 = 0;
  iStack_1cc = 0;
  param_6 = 0;
  uStack_1c4 = 0x95;
  iStack_1d0 = 0;
  iStack_1ec = 0;
  iStack_1d4 = 1;
  puStack_230 = (undefined4 *)0x0;
  pcStack_224 = (char *)0x0;
  iStack_204 = 0;
  iStack_208 = 0;
  iStack_210 = 0;
  uStack_228 = 0;
  iStack_20c = 0;
  iStack_1f4 = 0x800;
  uStack_1e4 = 0x800;
  if (param_3 == (char *)0x0) {
    uVar9 = 0;
    iStack_1f8 = 0;
    iStack_234 = 0;
    pcStack_1dc = (char *)0x0;
    iStack_1f0 = 0;
    iStack_1e8 = 0;
    iStack_1fc = 0;
    pcStack_1e0 = (char *)0x0;
    pcStack_21c = (char *)0x0;
    pcStack_220 = (char *)0x0;
    goto LAB_00464bdc;
  }
  iStack_1f8 = 0;
  iStack_234 = 0;
  pcStack_1dc = (char *)0x0;
  unaff_s2 = (undefined4 *)0x0;
  iStack_1f0 = 0;
  uVar9 = 0;
  iStack_1e8 = 0;
  pcStack_22c = "-keyex";
  param_1 = "-nokeys";
  iStack_1fc = 0;
  pcStack_1e0 = (char *)0x0;
  pcStack_218 = "-check_ss_sig";
  pcStack_21c = (char *)0x0;
  pcStack_220 = (char *)0x0;
  pcStack_200 = "-nocerts";
  pcStack_1d8 = "-check_ss_sig";
LAB_00464580:
  if (*param_3 == '-') {
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,param_1);
    if (iVar5 == 0) {
      uVar9 = uVar9 | 1;
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,pcStack_22c);
    if (iVar5 == 0) {
      uStack_228 = 0x10;
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,pcStack_218 + 0x1694);
    if (iVar5 == 0) {
      uStack_228 = 0x80;
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,pcStack_200);
    if (iVar5 == 0) {
      uVar9 = uVar9 | 2;
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,pcStack_1d8 + 0x16a8);
    if (iVar5 == 0) {
      uVar9 = uVar9 | 8;
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-cacerts");
    if (iVar5 == 0) {
      uVar9 = uVar9 | 0x10;
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-noout");
    if (iVar5 == 0) {
      uVar9 = uVar9 | 3;
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-info");
    if (iVar5 == 0) {
      uVar9 = uVar9 | 4;
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-chain");
    if (iVar5 == 0) {
      iStack_1f8 = 1;
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-twopass");
    if (iVar5 != 0) {
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-nomacver");
      if (iVar5 != 0) {
        iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-descert");
        if (iVar5 != 0) goto LAB_004659f4;
        uStack_1c4 = 0x92;
        goto LAB_00464594;
      }
      iStack_1d4 = 0;
      goto LAB_00464594;
    }
    iStack_20c = 1;
    goto LAB_00464594;
  }
LAB_00464590:
  unaff_s2 = (undefined4 *)0x1;
LAB_00464594:
  do {
    param_3 = *(char **)(param_5 + 4);
    param_5 = param_5 + 4;
    if (param_3 != (char *)0x0) goto LAB_00464580;
    if (unaff_s2 == (undefined4 *)0x0) {
LAB_00464bdc:
      unaff_s2 = (undefined4 *)PTR_bio_err_006a6e3c;
      param_5 = setup_engine(*(undefined4 *)puVar3,iStack_214,0);
      if (pcStack_224 != (char *)0x0) {
        if (iStack_234 == 0) {
          iVar5 = app_passwd(*unaff_s2,pcStack_224,iStack_204,&pcStack_1bc,&pcStack_1b8);
          if (iVar5 != 0) goto LAB_00464c30;
        }
        else {
          iVar5 = app_passwd(*unaff_s2,iStack_208,pcStack_224,&pcStack_1bc,&pcStack_1b8);
          if (iVar5 != 0) goto LAB_00464e70;
        }
LAB_00464ee8:
        param_1 = (char *)0x0;
        puVar11 = (undefined4 *)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"Error getting passwords\n");
        goto LAB_00464a38;
      }
      iVar5 = app_passwd(*unaff_s2,iStack_208,iStack_204,&pcStack_1bc,&pcStack_1b8);
      if (iVar5 == 0) goto LAB_00464ee8;
      if (iStack_234 == 0) {
LAB_00464c30:
        if (pcStack_1bc == (char *)0x0) {
LAB_004652a0:
          pcStack_224 = acStack_f8;
          param_3 = acStack_12c;
        }
        else {
          pcStack_224 = pcStack_1bc;
          iStack_210 = 1;
          param_3 = pcStack_1bc;
        }
        if (puStack_230 != (undefined4 *)0x0) {
          app_RAND_load_file(0,*(undefined4 *)puVar3,1);
LAB_00464c68:
          unaff_s2 = *(undefined4 **)puVar3;
          uVar7 = app_RAND_load_files(puStack_230);
          (*(code *)PTR_BIO_printf_006a6e38)(unaff_s2,"%ld semi-random bytes loaded\n",uVar7);
        }
      }
      else {
LAB_00464e70:
        if (pcStack_1b8 == (char *)0x0) {
          pcStack_224 = acStack_f8;
          if (iStack_234 == 0) goto LAB_004652a0;
          param_3 = acStack_12c;
        }
        else {
          pcStack_224 = pcStack_1b8;
          iStack_210 = 1;
          param_3 = pcStack_1b8;
        }
        app_RAND_load_file(0,*(undefined4 *)puVar3,puStack_230 != (undefined4 *)0x0);
        unaff_s2 = puStack_230;
        if (puStack_230 != (undefined4 *)0x0) goto LAB_00464c68;
      }
      (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
      if (pcStack_220 == (char *)0x0) {
        puVar11 = (undefined4 *)
                  (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14,0);
        if (puVar11 == (undefined4 *)0x0) {
          uVar7 = *(undefined4 *)puVar3;
          pcVar12 = "<stdin>";
          goto LAB_0046542c;
        }
      }
      else {
        puVar11 = (undefined4 *)(*(code *)PTR_BIO_new_file_006a6eac)(pcStack_220,&DAT_00633e40);
        if (puVar11 == (undefined4 *)0x0) {
          uVar7 = *(undefined4 *)puVar3;
          pcVar12 = pcStack_220;
LAB_0046542c:
          param_1 = (char *)0x0;
          puVar11 = (undefined4 *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)(uVar7,"Error opening input file %s\n",pcVar12);
          (*(code *)PTR_perror_006a9a80)(pcStack_220);
          goto LAB_00464a38;
        }
      }
      if (pcStack_21c == (char *)0x0) {
        param_1 = (char *)(*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
        if (param_1 == (char *)0x0) {
          uVar7 = *(undefined4 *)puVar3;
          pcVar12 = "<stdout>";
          goto LAB_00465488;
        }
      }
      else {
        param_1 = (char *)(*(code *)PTR_BIO_new_file_006a6eac)(pcStack_21c,&DAT_00632420);
        if (param_1 == (char *)0x0) {
          uVar7 = *(undefined4 *)puVar3;
          pcVar12 = pcStack_21c;
LAB_00465488:
          param_1 = (char *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)(uVar7,"Error opening output file %s\n",pcVar12);
          (*(code *)PTR_perror_006a9a80)(pcStack_21c);
          goto LAB_00464a38;
        }
      }
      if ((iStack_20c != 0) &&
         (iVar5 = (*(code *)PTR_EVP_read_pw_string_006a7278)
                            (acStack_f8,0x32,"Enter MAC Password:",iStack_234), iVar5 != 0)) {
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"Can\'t read Password\n");
        goto LAB_00464a38;
      }
      if (iStack_234 == 0) {
        param_5 = (*(code *)PTR_d2i_PKCS12_bio_006a727c)(puVar11,0);
        if (param_5 != 0) {
          if ((iStack_210 == 0) &&
             (iVar5 = (*(code *)PTR_EVP_read_pw_string_006a7278)
                                (acStack_12c,0x32,"Enter Import Password:",0), iVar5 != 0)) {
            uVar9 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"Can\'t read Password\n");
          }
          else {
            if (iStack_20c == 0) {
              (*(code *)PTR_BUF_strlcpy_006a6f64)(acStack_f8,acStack_12c,0x32);
            }
            if (((uVar9 & 4) != 0) && (*(int *)(param_5 + 4) != 0)) {
              unaff_s2 = *(undefined4 **)puVar3;
              if (*(int *)(*(int *)(param_5 + 4) + 8) == 0) {
                uVar7 = 1;
              }
              else {
                uVar7 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)();
              }
              (*(code *)PTR_BIO_printf_006a6e38)(unaff_s2,"MAC Iteration %ld\n",uVar7);
            }
            if (iStack_1d4 != 0) {
              if ((*pcStack_224 == '\0') &&
                 (iVar5 = (*(code *)PTR_PKCS12_verify_mac_006a7280)(param_5,0,0), iVar5 != 0)) {
                if (iStack_20c == 0) {
                  param_3 = (char *)0x0;
                }
              }
              else {
                iVar5 = (*(code *)PTR_PKCS12_verify_mac_006a7280)(param_5,pcStack_224,0xffffffff);
                if (iVar5 == 0) {
                  uVar9 = 1;
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar3,"Mac verify error: invalid password?\n");
                  (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar3);
                  goto LAB_004651cc;
                }
              }
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"MAC verified OK\n");
            }
            iVar5 = dump_certs_keys_p12(param_1,param_5,param_3,0xffffffff,uVar9,pcStack_1b8);
            if (iVar5 == 0) {
              uVar9 = 1;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar3,"Error outputting keys and certificates\n");
              (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar3);
            }
            else {
              uVar9 = 0;
            }
          }
LAB_004651cc:
          (*(code *)PTR_PKCS12_free_006a7268)(param_5);
          goto LAB_00464a3c;
        }
        uVar9 = 1;
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar3);
        goto LAB_00464a48;
      }
      if ((uVar9 & 3) == 3) {
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"Nothing to do!\n");
LAB_004654f8:
        uVar9 = 1;
      }
      else {
        unaff_s2 = (undefined4 *)(uVar9 & 2);
        if (unaff_s2 == (undefined4 *)0x0) {
          if ((uVar9 & 1) != 0) {
            uVar9 = 1;
            unaff_s2 = (undefined4 *)
                       load_certs(*(undefined4 *)puVar3,pcStack_220,3,0,param_5,"certificates");
            if (unaff_s2 != (undefined4 *)0x0) {
              pcStack_22c = (char *)0x0;
              pcStack_220 = (char *)0x0;
LAB_004655d4:
              if (iStack_1fc == 0) goto LAB_00464fd8;
              iVar5 = load_certs(*(undefined4 *)puVar3,iStack_1fc,3,0,param_5,
                                 "certificates from certfile");
              if (iVar5 != 0) goto LAB_00464fb4;
              uVar9 = 1;
              param_5 = 0;
              goto LAB_00465178;
            }
            goto LAB_00464a58;
          }
LAB_00464d30:
          pcVar12 = pcStack_1e0;
          if (pcStack_1e0 == (char *)0x0) {
            pcVar12 = pcStack_220;
          }
          pcStack_22c = (char *)load_key(*(undefined4 *)puVar3,pcVar12,3,1,pcStack_1bc,param_5,
                                         "private key");
          if (pcStack_22c == (char *)0x0) goto LAB_004654f8;
          if (unaff_s2 != (undefined4 *)0x0) {
            unaff_s2 = (undefined4 *)0x0;
            pcStack_220 = (char *)0x0;
            goto LAB_004655d4;
          }
          unaff_s2 = (undefined4 *)
                     load_certs(*(undefined4 *)puVar3,pcStack_220,3,0,param_5,"certificates");
          if (unaff_s2 == (undefined4 *)0x0) {
            pcStack_220 = (char *)0x0;
            uVar9 = 1;
            param_5 = 0;
            pcVar12 = param_3;
          }
          else {
            for (pcVar12 = (char *)0x0; iVar5 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2),
                pcStack_21c = param_3, (int)pcVar12 < iVar5; pcVar12 = pcVar12 + 1) {
              pcStack_220 = (char *)(*(code *)PTR_sk_value_006a6e24)(unaff_s2,pcVar12);
              iVar5 = (*(code *)PTR_X509_check_private_key_006a707c)(pcStack_220,pcStack_22c);
              if (iVar5 != 0) {
                (*(code *)PTR_X509_keyid_set1_006a7284)(pcStack_220,0,0);
                (*(code *)PTR_X509_alias_set1_006a7254)(pcStack_220,0,0);
                (*(code *)PTR_sk_delete_006a7288)(unaff_s2,pcVar12);
                pcVar12 = param_3;
                if (pcStack_220 != (char *)0x0) goto LAB_004655d4;
                break;
              }
            }
            uVar9 = 1;
            param_5 = 0;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar3,"No certificate matches private key\n");
            pcStack_220 = (char *)0x0;
          }
LAB_00465184:
          (*(code *)PTR_EVP_PKEY_free_006a6e78)(pcStack_22c);
          param_3 = pcVar12;
        }
        else {
          if ((uVar9 & 1) == 0) {
            iStack_1f8 = 0;
            goto LAB_00464d30;
          }
          if (iStack_1fc == 0) {
            pcStack_22c = (char *)0x0;
            unaff_s2 = (undefined4 *)0x0;
            pcStack_220 = (char *)0x0;
LAB_00464fe4:
            for (iVar5 = 0; iVar6 = (*(code *)PTR_sk_num_006a6e2c)(param_6), iVar5 < iVar6;
                iVar5 = iVar5 + 1) {
              uVar7 = (*(code *)PTR_sk_value_006a6e24)(param_6,iVar5);
              uVar8 = (*(code *)PTR_sk_value_006a6e24)(unaff_s2,iVar5);
              (*(code *)PTR_X509_alias_set1_006a7254)(uVar8,uVar7,0xffffffff);
            }
            if (iStack_1f0 == 0) {
              pcVar12 = pcStack_22c;
              if (pcStack_1dc != (char *)0x0) goto joined_r0x00465740;
            }
            else if (pcStack_22c != (char *)0x0) {
              (*(code *)PTR_EVP_PKEY_add1_attr_by_NID_006a7258)
                        (pcStack_22c,0x1a1,0x1001,iStack_1f0,0xffffffff);
              pcVar12 = pcStack_1dc;
joined_r0x00465740:
              if (pcVar12 != (char *)0x0) {
                (*(code *)PTR_EVP_PKEY_add1_attr_by_NID_006a7258)(pcStack_22c,0x358,0,0,0xffffffff);
              }
            }
            if ((iStack_210 == 0) &&
               (iVar5 = (*(code *)PTR_EVP_read_pw_string_006a7278)
                                  (acStack_12c,0x32,"Enter Export Password:",1), iVar5 != 0)) {
              uVar9 = 1;
              param_5 = 0;
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"Can\'t read Password\n");
            }
            else {
              if (iStack_20c == 0) {
                (*(code *)PTR_BUF_strlcpy_006a6f64)(acStack_f8,acStack_12c,0x32);
              }
              param_5 = (*(code *)PTR_PKCS12_create_006a725c)
                                  (param_3,iStack_1e8,pcStack_22c,pcStack_220,unaff_s2,uStack_1c0,
                                   uStack_1c4,uStack_1e4,0xffffffff,uStack_228);
              if (param_5 == 0) {
                uVar9 = 1;
                (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar3);
              }
              else {
                if (iStack_1ec == 0) {
                  iVar5 = 0;
                }
                else {
                  iVar5 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(iStack_1ec);
                  if (iVar5 == 0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar3,"Unknown digest algorithm %s\n",iStack_1ec);
                  }
                }
                if (iStack_1f4 != -1) {
                  (*(code *)PTR_PKCS12_set_mac_006a7260)
                            (param_5,pcStack_224,0xffffffff,0,0,iStack_1f4,iVar5);
                }
                uVar9 = 0;
                (*(code *)PTR_i2d_PKCS12_bio_006a7264)(param_1,param_5);
              }
            }
          }
          else {
            iVar5 = load_certs(*(undefined4 *)puVar3,iStack_1fc,3,0,param_5,
                               "certificates from certfile");
            if (iVar5 == 0) goto LAB_004654f8;
            pcStack_22c = (char *)0x0;
            unaff_s2 = (undefined4 *)0x0;
            pcStack_220 = (char *)0x0;
            iStack_1f8 = 0;
LAB_00464fb4:
            while (iVar6 = (*(code *)PTR_sk_num_006a6e2c)(iVar5), 0 < iVar6) {
              uVar7 = (*(code *)PTR_sk_shift_006a724c)(iVar5);
              (*(code *)PTR_sk_push_006a6fa8)(unaff_s2,uVar7);
            }
            (*(code *)PTR_sk_free_006a6e80)(iVar5);
LAB_00464fd8:
            if (iStack_1f8 == 0) goto LAB_00464fe4;
            param_5 = (*(code *)PTR_X509_STORE_new_006a7250)();
            if (param_5 == 0) {
              uVar9 = 1;
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"Memory allocation error\n");
            }
            else {
              iVar5 = (*(code *)PTR_X509_STORE_load_locations_006a726c)
                                (param_5,iStack_1cc,iStack_1d0);
              if (iVar5 == 0) {
                (*(code *)PTR_X509_STORE_set_default_paths_006a7298)(param_5);
              }
              iVar5 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)(auStack_1b4,param_5,pcStack_220,0)
              ;
              if (iVar5 == 0) {
                (*(code *)PTR_X509_STORE_free_006a7274)(param_5);
              }
              else {
                iVar5 = (*(code *)PTR_X509_verify_cert_006a728c)(auStack_1b4);
                if (0 < iVar5) {
                  uVar7 = (*(code *)PTR_X509_STORE_CTX_get1_chain_006a7290)(auStack_1b4);
                  (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(auStack_1b4);
                  (*(code *)PTR_X509_STORE_free_006a7274)(param_5);
                  for (iVar5 = 1; iVar6 = (*(code *)PTR_sk_num_006a6e2c)(uVar7), iVar5 < iVar6;
                      iVar5 = iVar5 + 1) {
                    uVar8 = (*(code *)PTR_sk_value_006a6e24)(uVar7,iVar5);
                    (*(code *)PTR_sk_push_006a6fa8)(unaff_s2,uVar8);
                  }
                  uVar8 = (*(code *)PTR_sk_value_006a6e24)(uVar7,0);
                  (*(code *)PTR_X509_free_006a6e90)(uVar8);
                  (*(code *)PTR_sk_free_006a6e80)(uVar7);
                  goto LAB_00464fe4;
                }
                param_3 = (char *)(*(code *)PTR_X509_STORE_CTX_get_error_006a729c)(auStack_1b4);
                if (param_3 == (char *)0x0) {
                  (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(auStack_1b4);
                  (*(code *)PTR_X509_STORE_free_006a7274)(param_5);
                }
                else {
                  (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(auStack_1b4);
                  (*(code *)PTR_X509_STORE_free_006a7274)(param_5);
                  if (param_3 != (char *)0x1) {
                    uVar8 = *(undefined4 *)puVar3;
                    param_5 = 0;
                    uVar7 = (*(code *)PTR_X509_verify_cert_error_string_006a72a0)(param_3);
                    uVar9 = 1;
                    (*(code *)PTR_BIO_printf_006a6e38)(uVar8,"Error %s getting chain.\n",uVar7);
                    goto LAB_00465178;
                  }
                }
              }
              uVar9 = 1;
              param_5 = 0;
              (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar3);
            }
          }
LAB_00465178:
          pcVar12 = param_3;
          if (pcStack_22c != (char *)0x0) goto LAB_00465184;
        }
        if (unaff_s2 != (undefined4 *)0x0) {
          (*(code *)PTR_sk_pop_free_006a7058)(unaff_s2,PTR_X509_free_006a6e90);
        }
        if (pcStack_220 != (char *)0x0) {
          (*(code *)PTR_X509_free_006a6e90)(pcStack_220);
        }
        if (param_5 != 0) goto LAB_004651cc;
      }
LAB_00464a58:
      app_RAND_write_file(0,*(undefined4 *)puVar3);
    }
    else {
      param_1 = (char *)0x0;
      puVar11 = (undefined4 *)0x0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"Usage: pkcs12 [options]\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"where options are\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"-export       output PKCS12 file\n")
      ;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-chain        add certificate chain\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-inkey file   private key if not infile\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"-certfile f   add all certs in f\n")
      ;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-CApath arg   - PEM format directory of CA\'s\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-CAfile arg   - PEM format file of CA\'s\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-name \"name\"  use name as friendly name\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,
                 "-caname \"nm\"  use nm as CA friendly name (can be used more than once).\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"-in  infile   input filename\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"-out outfile  output filename\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-noout        don\'t output anything, just verify.\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"-nomacver     don\'t verify MAC.\n")
      ;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-nocerts      don\'t output certificates.\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-clcerts      only output client certificates.\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-cacerts      only output CA certificates.\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-nokeys       don\'t output private keys.\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-info         give info about PKCS#12 structure.\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-des          encrypt private keys with DES\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,
                 "-des3         encrypt private keys with triple DES (default)\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-idea         encrypt private keys with idea\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-seed         encrypt private keys with seed\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"-aes128, -aes192, -aes256\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"              encrypt PEM output with cbc aes\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-camellia128, -camellia192, -camellia256\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"              encrypt PEM output with cbc camellia\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-nodes        don\'t encrypt private keys\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-noiter       don\'t use encryption iteration\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-nomaciter    don\'t use MAC iteration\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"-maciter      use MAC iteration\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-nomac        don\'t generate MAC\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-twopass      separate MAC, encryption passwords\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,
                 "-descert      encrypt PKCS#12 certificates with triple DES (default RC2-40)\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,
                 "-certpbe alg  specify certificate PBE algorithm (default RC2-40)\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,
                 "-keypbe alg   specify private key PBE algorithm (default 3DES)\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-macalg alg   digest algorithm used in MAC (default SHA1)\n"
                );
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-keyex        set MS key exchange type\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-keysig       set MS key signature type\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-password p   set import/export password source\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-passin p     input file pass phrase source\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-passout p    output file pass phrase source\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"-engine e     use engine e, possibly a hardware device.\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"-rand file%cfile%c...\n",0x3a,0x3a);
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,
                 "              load the file (or the files in the directory) into\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,"              the random number generator\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"-CSP name     Microsoft CSP name\n")
      ;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar3,
                 "-LMK          Add local machine keyset attribute to private key\n");
LAB_00464a38:
      uVar9 = 1;
LAB_00464a3c:
      if (iStack_234 != 0) goto LAB_00464a58;
LAB_00464a48:
      if (puStack_230 != (undefined4 *)0x0) goto LAB_00464a58;
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar11);
    (*(code *)PTR_BIO_free_all_006a6e74)(param_1);
    if (param_6 != 0) {
      (*(code *)PTR_sk_free_006a6e80)(param_6);
    }
LAB_00464ac4:
    if (pcStack_1bc != (char *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (pcStack_1b8 != (char *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (iStack_c4 == *(int *)puVar4) {
      return uVar9;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004659f4:
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-export");
    if (iVar5 != 0) {
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,&DAT_0063a4ec);
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_des_cbc_006a72a4)();
        *puVar11 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-des3");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_des_ede3_cbc_006a6e48)();
        *puVar11 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-idea");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_idea_cbc_006a72ac)();
        *puVar11 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-seed");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_seed_cbc_006a72b0)();
        *puVar11 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-aes128");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_aes_128_cbc_006a72a8)();
        *puVar11 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-aes192");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_aes_192_cbc_006a72c0)();
        *puVar11 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-aes256");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_aes_256_cbc_006a72bc)();
        *puVar11 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-camellia128");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_camellia_128_cbc_006a72b8)();
        *puVar11 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-camellia192");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_camellia_192_cbc_006a72b4)();
        *puVar11 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-camellia256");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_camellia_256_cbc_006a72c4)();
        *puVar11 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-noiter");
      if (iVar5 == 0) {
        uStack_1e4 = 1;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-maciter");
      if (iVar5 == 0) {
        iStack_1f4 = 0x800;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-nomaciter");
      if (iVar5 == 0) {
        iStack_1f4 = 1;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-nomac");
      if (iVar5 == 0) {
        iStack_1f4 = -1;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-macalg");
      if (iVar5 == 0) {
        piVar1 = (int *)(param_5 + 4);
        if (*piVar1 == 0) goto LAB_00464590;
        param_5 = param_5 + 4;
        iStack_1ec = *piVar1;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-nodes");
      if (iVar5 == 0) {
        *puVar11 = 0;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-certpbe");
      if (iVar5 == 0) {
        uVar7 = *(undefined4 *)(param_5 + 4);
        puVar10 = &uStack_1c4;
      }
      else {
        iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-keypbe");
        if (iVar5 != 0) {
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-rand");
          if (iVar5 == 0) {
            puVar10 = (undefined4 *)(param_5 + 4);
            if ((undefined4 *)*puVar10 == (undefined4 *)0x0) goto LAB_00464590;
            param_5 = param_5 + 4;
            puStack_230 = (undefined4 *)*puVar10;
            goto LAB_00464594;
          }
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-inkey");
          if (iVar5 == 0) {
            ppcVar2 = (char **)(param_5 + 4);
            if (*ppcVar2 == (char *)0x0) goto LAB_00464590;
            param_5 = param_5 + 4;
            pcStack_1e0 = *ppcVar2;
            goto LAB_00464594;
          }
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-certfile");
          if (iVar5 == 0) {
            piVar1 = (int *)(param_5 + 4);
            if (*piVar1 == 0) goto LAB_00464590;
            param_5 = param_5 + 4;
            iStack_1fc = *piVar1;
            goto LAB_00464594;
          }
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-name");
          if (iVar5 == 0) {
            piVar1 = (int *)(param_5 + 4);
            if (*piVar1 == 0) goto LAB_00464590;
            param_5 = param_5 + 4;
            iStack_1e8 = *piVar1;
            goto LAB_00464594;
          }
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,&DAT_00641738);
          if (iVar5 == 0) {
            pcStack_1dc = (char *)0x1;
            goto LAB_00464594;
          }
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,&DAT_00641740);
          if (iVar5 == 0) {
            piVar1 = (int *)(param_5 + 4);
            if (*piVar1 == 0) goto LAB_00464590;
            param_5 = param_5 + 4;
            iStack_1f0 = *piVar1;
            goto LAB_00464594;
          }
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-caname");
          if (iVar5 != 0) {
            if (((param_3[1] == 'i') && (param_3[2] == 'n')) && (param_3[3] == '\0')) {
              ppcVar2 = (char **)(param_5 + 4);
              if (*ppcVar2 == (char *)0x0) goto LAB_00464590;
              param_5 = param_5 + 4;
              pcStack_220 = *ppcVar2;
            }
            else {
              iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,&DAT_00632514);
              if (iVar5 == 0) {
                ppcVar2 = (char **)(param_5 + 4);
                if (*ppcVar2 == (char *)0x0) goto LAB_00464590;
                param_5 = param_5 + 4;
                pcStack_21c = *ppcVar2;
              }
              else {
                iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-passin");
                if (iVar5 == 0) {
                  piVar1 = (int *)(param_5 + 4);
                  if (*piVar1 == 0) goto LAB_00464590;
                  param_5 = param_5 + 4;
                  iStack_208 = *piVar1;
                }
                else {
                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-passout");
                  if (iVar5 == 0) {
                    piVar1 = (int *)(param_5 + 4);
                    if (*piVar1 == 0) goto LAB_00464590;
                    param_5 = param_5 + 4;
                    iStack_204 = *piVar1;
                  }
                  else {
                    iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-password");
                    if (iVar5 == 0) {
                      ppcVar2 = (char **)(param_5 + 4);
                      if (*ppcVar2 == (char *)0x0) goto LAB_00464590;
                      param_5 = param_5 + 4;
                      iStack_210 = 1;
                      pcStack_224 = *ppcVar2;
                    }
                    else {
                      iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-CApath");
                      if (iVar5 == 0) {
                        piVar1 = (int *)(param_5 + 4);
                        if (*piVar1 == 0) goto LAB_00464590;
                        param_5 = param_5 + 4;
                        iStack_1d0 = *piVar1;
                      }
                      else {
                        iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-CAfile");
                        if (iVar5 == 0) {
                          piVar1 = (int *)(param_5 + 4);
                          if (*piVar1 == 0) goto LAB_00464590;
                          param_5 = param_5 + 4;
                          iStack_1cc = *piVar1;
                        }
                        else {
                          iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_3,"-engine");
                          if ((iVar5 != 0) || (piVar1 = (int *)(param_5 + 4), *piVar1 == 0))
                          goto LAB_00464590;
                          param_5 = param_5 + 4;
                          iStack_214 = *piVar1;
                        }
                      }
                    }
                  }
                }
              }
            }
            goto LAB_00464594;
          }
          iVar5 = *(int *)(param_5 + 4);
          if (iVar5 != 0) {
            if (param_6 == 0) {
              param_6 = (*(code *)PTR_sk_new_null_006a6fa4)();
              iVar5 = *(int *)(param_5 + 4);
            }
            (*(code *)PTR_sk_push_006a6fa8)(param_6,iVar5);
            param_5 = param_5 + 4;
            goto LAB_00464594;
          }
          goto LAB_00464590;
        }
        uVar7 = *(undefined4 *)(param_5 + 4);
        puVar10 = &uStack_1c0;
      }
      param_5 = param_5 + 4;
      iVar5 = set_pbe_isra_0(puVar10,uVar7);
      if (iVar5 == 0) {
        unaff_s2 = (undefined4 *)0x1;
      }
      goto LAB_00464594;
    }
    iStack_234 = 1;
  } while( true );
}
