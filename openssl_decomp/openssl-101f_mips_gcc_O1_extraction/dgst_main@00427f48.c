
undefined4 * dgst_main(int param_1,undefined4 *param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined *puVar6;
  int iVar7;
  char **ppcVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  char *pcVar15;
  undefined4 *puVar16;
  char **unaff_s3;
  char **unaff_s4;
  undefined4 unaff_s5;
  int unaff_s6;
  int unaff_s7;
  code *pcVar17;
  int unaff_s8;
  int local_c0;
  undefined *local_bc;
  char *local_b8;
  int local_b4;
  char *local_b0;
  char *local_ac;
  uint local_a8;
  char *local_9c;
  char *local_94;
  char *local_8c;
  char *local_88;
  undefined4 local_84;
  int local_78;
  undefined4 local_74;
  undefined *local_6c;
  int local_64;
  int local_60;
  undefined4 local_5c;
  int local_58;
  undefined auStack_54 [40];
  int local_2c;
  
  puVar6 = PTR___stack_chk_guard_006aabf0;
  local_64 = 0;
  local_60 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  local_b4 = 0x630000;
  iVar7 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x2000,"dgst.c",0x87);
  puVar16 = (undefined4 *)PTR_bio_err_006a7f3c;
  if (iVar7 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,"out of memory\n");
    if (local_60 != 0) {
      unaff_s3 = (char **)0x0;
      local_c0 = 0;
      param_2 = (undefined4 *)0x0;
      unaff_s6 = 0;
      iVar13 = 0;
      puVar16 = (undefined4 *)0x1;
      goto LAB_00428048;
    }
    puVar16 = (undefined4 *)0x1;
    (*(code *)PTR_BIO_free_all_006a7f74)(0);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(local_64);
    iVar7 = unaff_s8;
    goto LAB_004280cc;
  }
  iVar13 = *(int *)PTR_bio_err_006a7f3c;
  if (iVar13 == 0) {
    uVar14 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar13 = (*(code *)PTR_BIO_new_006a7fa4)(uVar14);
    *puVar16 = iVar13;
    if (iVar13 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar13,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
      iVar13 = *puVar16;
    }
  }
  iVar13 = (*(code *)PTR_load_config_006a7f64)(iVar13,0);
  if (iVar13 != 0) {
    local_6c = auStack_54;
    (*(code *)PTR_program_name_006a8510)(*param_2,local_6c,0x28);
    unaff_s7 = param_1 + -1;
    unaff_s4 = (char **)(param_2 + 1);
    local_78 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(local_6c);
    if ((0 < unaff_s7) && (pcVar15 = (char *)param_2[1], *pcVar15 == '-')) {
      local_c0 = 0;
      bVar5 = false;
      local_94 = (char *)0x0;
      local_a8 = 0xffffffff;
      unaff_s6 = 0;
      local_88 = (char *)0x0;
      local_9c = (char *)0x0;
      unaff_s5 = 0;
      local_74 = 3;
      bVar2 = false;
      bVar4 = false;
      local_bc = &DAT_00632edc;
      local_b8 = (char *)0x0;
      local_8c = (char *)0x0;
      local_b0 = (char *)0x0;
      local_ac = (char *)0x0;
      bVar3 = false;
      local_84 = 0;
      do {
        cVar1 = pcVar15[1];
        ppcVar8 = unaff_s4;
        iVar13 = local_78;
        if (cVar1 == 'c') {
          if (pcVar15[2] == '\0') {
            unaff_s5 = 1;
          }
          else {
LAB_004281f0:
            iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-rand");
            if (iVar9 == 0) {
              iVar9 = unaff_s7 + -1;
              if (iVar9 == 0) goto LAB_00428270;
              local_b8 = unaff_s4[1];
              ppcVar8 = unaff_s4 + 1;
              unaff_s7 = iVar9;
            }
            else {
              iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar15,&DAT_00632edc);
              if (iVar9 == 0) {
                iVar9 = unaff_s7 + -1;
                if (iVar9 == 0) goto LAB_00428270;
                local_ac = unaff_s4[1];
                ppcVar8 = unaff_s4 + 1;
                unaff_s7 = iVar9;
              }
              else {
                iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-sign");
                if (iVar9 == 0) {
                  iVar9 = unaff_s7 + -1;
                  if (iVar9 == 0) goto LAB_00428270;
                  local_b0 = unaff_s4[1];
                  ppcVar8 = unaff_s4 + 1;
                  unaff_s7 = iVar9;
                }
                else {
                  iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-passin");
                  if (iVar9 == 0) {
                    iVar9 = unaff_s7 + -1;
                    if (iVar9 == 0) goto LAB_00428270;
                    local_9c = unaff_s4[1];
                    ppcVar8 = unaff_s4 + 1;
                    unaff_s7 = iVar9;
                  }
                  else {
                    iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-verify");
                    if (iVar9 == 0) {
                      iVar9 = unaff_s7 + -1;
                      if (iVar9 == 0) goto LAB_00428270;
                      local_b0 = unaff_s4[1];
                      bVar2 = true;
                      bVar4 = true;
                      ppcVar8 = unaff_s4 + 1;
                      unaff_s7 = iVar9;
                    }
                    else {
                      iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-prverify");
                      if (iVar9 == 0) {
                        iVar9 = unaff_s7 + -1;
                        if (iVar9 == 0) goto LAB_00428270;
                        local_b0 = unaff_s4[1];
                        bVar2 = true;
                        ppcVar8 = unaff_s4 + 1;
                        unaff_s7 = iVar9;
                      }
                      else {
                        iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-signature");
                        if (iVar9 == 0) {
                          iVar9 = unaff_s7 + -1;
                          if (iVar9 == 0) goto LAB_00428270;
                          local_8c = unaff_s4[1];
                          ppcVar8 = unaff_s4 + 1;
                          unaff_s7 = iVar9;
                        }
                        else {
                          iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-keyform");
                          if (iVar9 == 0) {
                            iVar9 = unaff_s7 + -1;
                            if (iVar9 == 0) goto LAB_00428270;
                            local_74 = (*(code *)PTR_str2fmt_006a7f4c)(unaff_s4[1]);
                            ppcVar8 = unaff_s4 + 1;
                            unaff_s7 = iVar9;
                          }
                          else {
                            iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-engine");
                            if (iVar9 == 0) {
                              iVar9 = unaff_s7 + -1;
                              if (iVar9 == 0) goto LAB_00428270;
                              local_84 = (*(code *)PTR_setup_engine_006a7fc4)
                                                   (*puVar16,unaff_s4[1],0);
                              ppcVar8 = unaff_s4 + 1;
                              unaff_s7 = iVar9;
                            }
                            else {
                              iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar15,&DAT_006342f0);
                              if (iVar9 == 0) {
                                local_a8 = 0;
                              }
                              else {
                                iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-binary");
                                if (iVar9 == 0) {
                                  local_a8 = 1;
                                }
                                else if ((cVar1 == 'd') && (pcVar15[2] == '\0')) {
                                  bVar3 = true;
                                }
                                else {
                                  iVar9 = (*(code *)PTR_strcmp_006aac20)
                                                    (pcVar15,"-fips-fingerprint");
                                  if (iVar9 == 0) {
                                    local_88 = "etaonrishdlcupfm";
                                  }
                                  else {
                                    iVar9 = (*(code *)PTR_strcmp_006aac20)
                                                      (pcVar15,"-non-fips-allow");
                                    if (iVar9 == 0) {
                                      bVar5 = true;
                                    }
                                    else {
                                      iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-hmac");
                                      if (iVar9 == 0) {
                                        iVar9 = unaff_s7 + -1;
                                        if (iVar9 == 0) goto LAB_00428270;
                                        local_88 = unaff_s4[1];
                                        ppcVar8 = unaff_s4 + 1;
                                        unaff_s7 = iVar9;
                                      }
                                      else {
                                        iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-mac");
                                        if (iVar9 == 0) {
                                          iVar9 = unaff_s7 + -1;
                                          if (iVar9 == 0) goto LAB_00428270;
                                          local_94 = unaff_s4[1];
                                          ppcVar8 = unaff_s4 + 1;
                                          unaff_s7 = iVar9;
                                        }
                                        else {
                                          iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-sigopt");
                                          if (iVar9 == 0) {
                                            iVar9 = unaff_s7 + -1;
                                            if (unaff_s7 + -1 == 0) goto LAB_00428270;
                                            iVar12 = local_c0;
                                            if (local_c0 == 0) {
                                              iVar12 = (*(code *)PTR_sk_new_null_006a80a4)();
                                              local_c0 = iVar12;
joined_r0x00429318:
                                              iVar9 = unaff_s7 + -1;
                                              if (iVar12 == 0) goto LAB_00428270;
                                            }
                                          }
                                          else {
                                            iVar9 = (*(code *)PTR_strcmp_006aac20)
                                                              (pcVar15,"-macopt");
                                            if (iVar9 != 0) {
                                              iVar13 = (*(code *)PTR_EVP_get_digestbyname_006a802c)
                                                                 (pcVar15 + 1);
                                              iVar9 = unaff_s7;
                                              if (iVar13 != 0) goto joined_r0x00428264;
                                              goto LAB_00428270;
                                            }
                                            iVar9 = unaff_s7 + -1;
                                            if (unaff_s7 + -1 == 0) goto LAB_00428270;
                                            iVar12 = unaff_s6;
                                            if (unaff_s6 == 0) {
                                              iVar12 = (*(code *)PTR_sk_new_null_006a80a4)();
                                              unaff_s6 = iVar12;
                                              goto joined_r0x00429318;
                                            }
                                          }
                                          ppcVar8 = unaff_s4 + 1;
                                          unaff_s4 = unaff_s4 + 1;
                                          iVar12 = (*(code *)PTR_sk_push_006a80a8)(iVar12,*ppcVar8);
                                          iVar9 = unaff_s7 + -1;
                                          ppcVar8 = unaff_s4;
                                          unaff_s7 = unaff_s7 + -1;
                                          if (iVar12 == 0) goto LAB_00428270;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else {
          if ((cVar1 != 'r') || (pcVar15[2] != '\0')) goto LAB_004281f0;
          unaff_s5 = 2;
        }
joined_r0x00428264:
        local_78 = iVar13;
        unaff_s7 = unaff_s7 + -1;
        unaff_s4 = ppcVar8 + 1;
        iVar9 = unaff_s7;
        if ((unaff_s7 == 0) || (pcVar15 = ppcVar8[1], *pcVar15 != '-')) goto LAB_00428270;
      } while( true );
    }
    bVar5 = false;
    local_94 = (char *)0x0;
    unaff_s5 = 0;
    local_88 = (char *)0x0;
    unaff_s6 = 0;
    local_a8 = 0xffffffff;
    local_9c = (char *)0x0;
    bVar2 = false;
    bVar4 = false;
    local_b8 = (char *)0x0;
    local_8c = (char *)0x0;
    local_b0 = (char *)0x0;
    local_ac = (char *)0x0;
    local_74 = 3;
    bVar3 = false;
    local_84 = 0;
    local_c0 = 0;
    goto LAB_0042827c;
  }
  unaff_s6 = 0;
  local_c0 = 0;
  iVar9 = unaff_s7;
LAB_00428008:
  param_2 = (undefined4 *)0x0;
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar7,0x2000);
  (*(code *)PTR_CRYPTO_free_006a7f88)(iVar7);
  unaff_s7 = iVar9;
LAB_00428030:
  unaff_s3 = (char **)0x0;
  puVar16 = (undefined4 *)0x1;
  iVar13 = 0;
  do {
    unaff_s8 = iVar7;
    if (local_60 != 0) {
LAB_00428048:
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    (*(code *)PTR_BIO_free_all_006a7f74)(unaff_s3);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(local_64);
    if (local_c0 != 0) {
      (*(code *)PTR_sk_free_006a7f80)(local_c0);
    }
    if (unaff_s6 != 0) {
      (*(code *)PTR_sk_free_006a7f80)(unaff_s6);
    }
    if (iVar13 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar13);
    }
    iVar7 = unaff_s8;
    if (param_2 != (undefined4 *)0x0) {
      (*(code *)PTR_BIO_free_006a7f70)(param_2);
    }
LAB_004280cc:
    if (local_2c == *(int *)puVar6) {
      return puVar16;
    }
    pcVar17 = (code *)PTR___stack_chk_fail_006aabb8;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00429154:
    local_78 = (*pcVar17)();
LAB_00428eac:
    iVar13 = (*(code *)PTR_BIO_ctrl_006a7f18)(param_2,0x6f,0,local_78);
    if (iVar13 == 0) {
      iVar13 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"Error setting digest %s\n",local_6c);
      uVar14 = *puVar16;
      puVar16 = (undefined4 *)0x1;
      (*(code *)PTR_ERR_print_errors_006a7f40)(uVar14);
      ppcVar8 = unaff_s4;
    }
    else {
LAB_00428888:
      ppcVar8 = unaff_s4;
      if ((local_8c == (char *)0x0) || (local_64 == 0)) {
        local_b8 = (char *)0x0;
        iVar13 = 0;
LAB_0042892c:
        uVar14 = (*(code *)PTR_BIO_push_006a85c0)(param_2,local_bc);
        if (local_78 == 0) {
          (*(code *)PTR_BIO_ctrl_006a7f18)(param_2,0x78,0,&local_58);
          local_78 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(local_58);
        }
        if (unaff_s7 == 0) {
          (*(code *)PTR_BIO_ctrl_006a7f18)(local_bc,0x6a,0,*(undefined4 *)PTR_stdin_006aab20);
          puVar16 = (undefined4 *)
                    do_fp(unaff_s3,iVar7,uVar14,unaff_s5,local_a8,local_64,iVar13,local_b8,0,0,
                          "stdin",param_2);
        }
        else {
          local_58 = 0;
          if (local_a8 == 0) {
            if ((local_64 != 0) &&
               (iVar9 = (*(code *)PTR_EVP_PKEY_get0_asn1_006a85f8)(), iVar9 != 0)) {
              (*(code *)PTR_EVP_PKEY_asn1_get0_info_006a80c0)(0,0,0,0,&local_58,iVar9);
            }
            uVar10 = (*(code *)PTR_EVP_MD_type_006a84cc)(local_78);
            local_b4 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar10);
          }
          else {
            local_b4 = 0;
          }
          puVar16 = (undefined4 *)0x0;
          if (0 < unaff_s7) {
            iVar9 = 0;
            do {
              iVar12 = (*(code *)PTR_BIO_ctrl_006a7f18)(local_bc,0x6c,3,*unaff_s4);
              if (iVar12 < 1) {
                puVar16 = (undefined4 *)((int)puVar16 + 1);
                (*(code *)PTR_perror_006aab88)(*unaff_s4);
              }
              else {
                puVar11 = (undefined4 *)
                          do_fp(unaff_s3,iVar7,uVar14,unaff_s5,local_a8,local_64,iVar13,local_b8,
                                local_58,local_b4,*unaff_s4,param_2);
                if (puVar11 != (undefined4 *)0x0) {
                  puVar16 = puVar11;
                }
                (*(code *)PTR_BIO_ctrl_006a7f18)(param_2,1,0,0);
              }
              iVar9 = iVar9 + 1;
              unaff_s4 = unaff_s4 + 1;
              ppcVar8 = unaff_s3;
            } while (unaff_s7 != iVar9);
          }
        }
      }
      else {
        iVar9 = (*(code *)PTR_BIO_new_file_006a7fac)(local_8c,&DAT_006347ac);
        uVar14 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(local_64);
        iVar13 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar14,local_b4 + 0x42b8,0x1d9);
        if (iVar9 == 0) {
          uVar14 = *puVar16;
          pcVar15 = "Error opening signature file %s\n";
        }
        else {
          local_b8 = (char *)(*(code *)PTR_BIO_read_006a85bc)(iVar9,iVar13,uVar14);
          (*(code *)PTR_BIO_free_006a7f70)(iVar9);
          if (0 < (int)local_b8) goto LAB_0042892c;
          uVar14 = *puVar16;
          pcVar15 = "Error reading signature file %s\n";
        }
        (*(code *)PTR_BIO_printf_006a7f38)(uVar14,pcVar15,local_8c);
        uVar14 = *puVar16;
        puVar16 = (undefined4 *)0x1;
        (*(code *)PTR_ERR_print_errors_006a7f40)(uVar14);
      }
    }
LAB_004283c8:
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar7,0x2000);
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar7);
    unaff_s4 = ppcVar8;
LAB_00428524:
    (*(code *)PTR_BIO_free_006a7f70)(local_bc);
  } while( true );
LAB_00428270:
  unaff_s7 = iVar9;
  if ((bVar2) && (local_8c == (char *)0x0)) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*puVar16,"No signature to verify: use the -signature option\n");
  }
  else {
LAB_0042827c:
    if ((unaff_s7 < 1) || (**unaff_s4 != '-')) {
      uVar14 = (*(code *)PTR_BIO_s_file_006a7fa0)();
      local_bc = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar14);
      uVar14 = (*(code *)PTR_BIO_f_md_006a85d4)();
      param_2 = (undefined4 *)(*(code *)PTR_BIO_new_006a7fa4)(uVar14);
      if (bVar3) {
        (*(code *)PTR_BIO_set_callback_006a85d8)(local_bc,PTR_BIO_debug_callback_006a85dc);
        (*(code *)PTR_BIO_set_callback_arg_006a85e0)(local_bc,*puVar16);
      }
      iVar13 = (*(code *)PTR_app_passwd_006a7f54)(*puVar16,local_9c,0,&local_60,0);
      if (iVar13 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,"Error getting password\n");
      }
      else {
        if ((local_bc != (undefined *)0x0) && (param_2 != (undefined4 *)0x0)) {
          if (local_a8 == 0xffffffff) {
            local_a8 = (uint)(local_b0 != (char *)0x0);
          }
          if (local_b8 != (char *)0x0) {
            (*(code *)PTR_app_RAND_load_file_006a7fcc)(local_b8,*puVar16,0);
          }
          ppcVar8 = unaff_s4;
          if (local_ac == (char *)0x0) {
            unaff_s3 = (char **)(*(code *)PTR_BIO_new_fp_006a835c)
                                          (*(undefined4 *)PTR_stdout_006aaad4,0);
            if (unaff_s3 == (char **)0x0) {
              uVar14 = *puVar16;
              local_ac = "(stdout)";
              goto LAB_00428dd4;
            }
          }
          else {
            if (local_a8 == 0) {
              unaff_s3 = (char **)(*(code *)PTR_BIO_new_file_006a7fac)(local_ac,"w");
            }
            else {
              unaff_s3 = (char **)(*(code *)PTR_BIO_new_file_006a7fac)(local_ac,&DAT_00632de8);
            }
            if (unaff_s3 == (char **)0x0) {
              uVar14 = *puVar16;
LAB_00428dd4:
              iVar13 = 0;
              unaff_s3 = (char **)0x0;
              (*(code *)PTR_BIO_printf_006a7f38)(uVar14,"Error opening output file %s\n",local_ac);
              uVar14 = *puVar16;
              puVar16 = (undefined4 *)0x1;
              (*(code *)PTR_ERR_print_errors_006a7f40)(uVar14);
              goto LAB_004283c8;
            }
          }
          if (1 < (byte)((local_94 != (char *)0x0) + (local_b0 != (char *)0x0) +
                        (local_88 != (char *)0x0))) {
            uVar14 = *puVar16;
            iVar13 = 0;
            puVar16 = (undefined4 *)0x1;
            (*(code *)PTR_BIO_printf_006a7f38)
                      (uVar14,"MAC and Signing key cannot both be specified\n");
            goto LAB_004283c8;
          }
          if (local_b0 != (char *)0x0) {
            pcVar17 = (code *)PTR_load_key_006a7fc8;
            iVar13 = local_60;
            if (bVar4) {
              pcVar17 = (code *)PTR_load_pubkey_006a85e4;
              iVar13 = 0;
            }
            local_64 = (*pcVar17)(*puVar16,local_b0,local_74,0,iVar13,local_84,"key file");
            if (local_64 == 0) goto LAB_00428d14;
          }
          if (local_94 == (char *)0x0) {
LAB_00428780:
            if (bVar5) {
              (*(code *)PTR_BIO_ctrl_006a7f18)(param_2,0x78,0,&local_58);
              (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(local_58,8);
            }
            if (local_88 == (char *)0x0) {
              if (local_64 == 0) {
                pcVar17 = (code *)PTR_EVP_md5_006a81c8;
                if (local_78 == 0) goto LAB_00429154;
                goto LAB_00428eac;
              }
            }
            else {
              local_64 = (*(code *)PTR_EVP_PKEY_new_mac_key_006a85ec)
                                   (0x357,local_84,local_88,0xffffffff);
              ppcVar8 = unaff_s4;
              if (local_64 == 0) goto LAB_00428d14;
            }
            local_5c = 0;
            local_58 = 0;
            iVar13 = (*(code *)PTR_BIO_ctrl_006a7f18)(param_2,0x78,0,&local_5c);
            if (iVar13 == 0) {
              (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"Error getting context\n");
            }
            else {
              pcVar17 = (code *)PTR_EVP_DigestSignInit_006a7f20;
              if (bVar2) {
                pcVar17 = (code *)PTR_EVP_DigestVerifyInit_006a85f0;
              }
              iVar13 = (*pcVar17)(local_5c,&local_58,local_78,local_84,local_64);
              if (iVar13 == 0) {
                (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"Error setting context\n");
              }
              else {
                if (local_c0 == 0) goto LAB_00428888;
                iVar13 = 0;
                while( true ) {
                  iVar9 = (*(code *)PTR_sk_num_006a7f2c)(local_c0);
                  if (iVar9 <= iVar13) goto LAB_00428888;
                  uVar14 = (*(code *)PTR_sk_value_006a7f24)(local_c0,iVar13);
                  iVar9 = (*(code *)PTR_pkey_ctrl_string_006a7f28)(local_58,uVar14);
                  if (iVar9 < 1) break;
                  iVar13 = iVar13 + 1;
                }
                (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"parameter error \"%s\"\n",uVar14);
              }
            }
            (*(code *)PTR_ERR_print_errors_006a7f40)(*puVar16);
            ppcVar8 = unaff_s4;
          }
          else {
            local_58 = 0;
            iVar13 = init_gen_str(*puVar16,&local_58,local_94,local_84,0);
            if (iVar13 != 0) {
              if (unaff_s6 != 0) {
                for (iVar13 = 0; iVar9 = (*(code *)PTR_sk_num_006a7f2c)(unaff_s6), iVar13 < iVar9;
                    iVar13 = iVar13 + 1) {
                  ppcVar8 = (char **)(*(code *)PTR_sk_value_006a7f24)(unaff_s6,iVar13);
                  iVar9 = (*(code *)PTR_pkey_ctrl_string_006a7f28)(local_58,ppcVar8);
                  if (iVar9 < 1) {
                    (*(code *)PTR_BIO_printf_006a7f38)
                              (*puVar16,"MAC parameter error \"%s\"\n",ppcVar8);
                    goto LAB_00428d4c;
                  }
                }
              }
              iVar13 = (*(code *)PTR_EVP_PKEY_keygen_006a8048)(local_58,&local_64);
              if (0 < iVar13) {
                if (local_58 != 0) {
                  (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)();
                }
                goto LAB_00428780;
              }
              (*(code *)PTR_BIO_puts_006a8058)(*puVar16,"Error generating key\n");
              ppcVar8 = unaff_s4;
LAB_00428d4c:
              (*(code *)PTR_ERR_print_errors_006a7f40)(*puVar16);
            }
            if (local_58 != 0) {
              iVar13 = 0;
              puVar16 = (undefined4 *)0x1;
              (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)();
              goto LAB_004283c8;
            }
          }
LAB_00428d14:
          iVar13 = 0;
          puVar16 = (undefined4 *)0x1;
          goto LAB_004283c8;
        }
        (*(code *)PTR_ERR_print_errors_006a7f40)(*puVar16);
      }
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar7,0x2000);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar7);
      if (local_bc != (undefined *)0x0) {
        puVar16 = (undefined4 *)0x1;
        iVar13 = 0;
        unaff_s3 = (char **)0x0;
        goto LAB_00428524;
      }
      goto LAB_00428030;
    }
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"unknown option \'%s\'\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"options are\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*puVar16,"-c              to output the digest with separating colons\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*puVar16,"-r              to output the digest in coreutils format\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"-d              to output debug info\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"-hex            output as hex dump\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"-binary         output in binary form\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*puVar16,"-sign   file    sign digest using private key in file\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*puVar16,"-verify file    verify a signature using public key in file\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*puVar16,"-prverify file  verify a signature using private key in file\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"-keyform arg    key file format (PEM or ENGINE)\n")
    ;
    (*(code *)PTR_BIO_printf_006a7f38)
              (*puVar16,"-out filename   output to filename rather than stdout\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"-signature file signature to verify\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"-sigopt nm:v    signature parameter\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"-hmac key       create hashed MAC with key\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*puVar16,"-mac algorithm  create MAC (not neccessarily HMAC)\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"-macopt nm:v    MAC algorithm parameters or key\n")
    ;
    (*(code *)PTR_BIO_printf_006a7f38)
              (*puVar16,"-engine e       use engine e, possibly a hardware device.\n");
    (*(code *)PTR_EVP_MD_do_all_sorted_006a84c0)(list_md_fn,*puVar16);
    iVar9 = unaff_s7;
  }
  goto LAB_00428008;
}

