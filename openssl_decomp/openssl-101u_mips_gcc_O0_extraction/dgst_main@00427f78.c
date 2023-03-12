
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
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  char *pcVar15;
  char **ppcVar16;
  undefined4 *puVar17;
  int unaff_s3;
  char **unaff_s4;
  undefined4 unaff_s5;
  int unaff_s6;
  int unaff_s7;
  code *pcVar18;
  int unaff_s8;
  int local_c0;
  char *local_bc;
  undefined *local_b8;
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
  
  puVar6 = PTR___stack_chk_guard_006a9ae8;
  local_64 = 0;
  local_60 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  local_b4 = 0x630000;
  iVar7 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x2000,"dgst.c",0x87);
  puVar17 = (undefined4 *)PTR_bio_err_006a6e3c;
  if (iVar7 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"out of memory\n");
    if (local_60 != 0) {
      local_c0 = 0;
      ppcVar16 = (char **)0x0;
      unaff_s7 = 0;
      unaff_s3 = 0;
      puVar17 = (undefined4 *)0x1;
      param_2 = (undefined4 *)0x0;
      goto LAB_00428078;
    }
    puVar17 = (undefined4 *)0x1;
    (*(code *)PTR_BIO_free_all_006a6e74)(0);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(local_64);
    iVar7 = unaff_s8;
    goto LAB_004280fc;
  }
  iVar13 = *(int *)PTR_bio_err_006a6e3c;
  if (iVar13 == 0) {
    uVar14 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar13 = (*(code *)PTR_BIO_new_006a6ea4)(uVar14);
    *puVar17 = iVar13;
    if (iVar13 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar13,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
      iVar13 = *puVar17;
    }
  }
  iVar13 = (*(code *)PTR_load_config_006a6e64)(iVar13,0);
  if (iVar13 != 0) {
    local_6c = auStack_54;
    (*(code *)PTR_program_name_006a7410)(*param_2,local_6c,0x28);
    unaff_s6 = param_1 + -1;
    unaff_s4 = (char **)(param_2 + 1);
    local_78 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(local_6c);
    if ((0 < unaff_s6) && (pcVar15 = (char *)param_2[1], *pcVar15 == '-')) {
      local_c0 = 0;
      bVar5 = false;
      local_94 = (char *)0x0;
      local_a8 = 0xffffffff;
      unaff_s7 = 0;
      local_88 = (char *)0x0;
      local_9c = (char *)0x0;
      unaff_s5 = 0;
      local_74 = 3;
      bVar2 = false;
      bVar4 = false;
      local_b8 = &DAT_00632514;
      local_bc = (char *)0x0;
      local_8c = (char *)0x0;
      local_b0 = (char *)0x0;
      local_ac = (char *)0x0;
      bVar3 = false;
      local_84 = 0;
      do {
        cVar1 = pcVar15[1];
        ppcVar16 = unaff_s4;
        iVar13 = local_78;
        if (cVar1 == 'c') {
          if (pcVar15[2] == '\0') {
            unaff_s5 = 1;
          }
          else {
LAB_00428220:
            iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-rand");
            if (iVar11 == 0) {
              iVar11 = unaff_s6 + -1;
              if (iVar11 == 0) goto LAB_004282a0;
              local_bc = unaff_s4[1];
              ppcVar16 = unaff_s4 + 1;
              unaff_s6 = iVar11;
            }
            else {
              iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,&DAT_00632514);
              if (iVar11 == 0) {
                iVar11 = unaff_s6 + -1;
                if (iVar11 == 0) goto LAB_004282a0;
                local_ac = unaff_s4[1];
                ppcVar16 = unaff_s4 + 1;
                unaff_s6 = iVar11;
              }
              else {
                iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-sign");
                if (iVar11 == 0) {
                  iVar11 = unaff_s6 + -1;
                  if (iVar11 == 0) goto LAB_004282a0;
                  local_b0 = unaff_s4[1];
                  ppcVar16 = unaff_s4 + 1;
                  unaff_s6 = iVar11;
                }
                else {
                  iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-passin");
                  if (iVar11 == 0) {
                    iVar11 = unaff_s6 + -1;
                    if (iVar11 == 0) goto LAB_004282a0;
                    local_9c = unaff_s4[1];
                    ppcVar16 = unaff_s4 + 1;
                    unaff_s6 = iVar11;
                  }
                  else {
                    iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-verify");
                    if (iVar11 == 0) {
                      iVar11 = unaff_s6 + -1;
                      if (iVar11 == 0) goto LAB_004282a0;
                      local_b0 = unaff_s4[1];
                      bVar2 = true;
                      bVar4 = true;
                      ppcVar16 = unaff_s4 + 1;
                      unaff_s6 = iVar11;
                    }
                    else {
                      iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-prverify");
                      if (iVar11 == 0) {
                        iVar11 = unaff_s6 + -1;
                        if (iVar11 == 0) goto LAB_004282a0;
                        local_b0 = unaff_s4[1];
                        bVar2 = true;
                        ppcVar16 = unaff_s4 + 1;
                        unaff_s6 = iVar11;
                      }
                      else {
                        iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-signature");
                        if (iVar11 == 0) {
                          iVar11 = unaff_s6 + -1;
                          if (iVar11 == 0) goto LAB_004282a0;
                          local_8c = unaff_s4[1];
                          ppcVar16 = unaff_s4 + 1;
                          unaff_s6 = iVar11;
                        }
                        else {
                          iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-keyform");
                          if (iVar11 == 0) {
                            iVar11 = unaff_s6 + -1;
                            if (iVar11 == 0) goto LAB_004282a0;
                            local_74 = (*(code *)PTR_str2fmt_006a6e4c)(unaff_s4[1]);
                            ppcVar16 = unaff_s4 + 1;
                            unaff_s6 = iVar11;
                          }
                          else {
                            iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-engine");
                            if (iVar11 == 0) {
                              iVar11 = unaff_s6 + -1;
                              if (iVar11 == 0) goto LAB_004282a0;
                              local_84 = (*(code *)PTR_setup_engine_006a6ec4)
                                                   (*puVar17,unaff_s4[1],0);
                              ppcVar16 = unaff_s4 + 1;
                              unaff_s6 = iVar11;
                            }
                            else {
                              iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,&DAT_00633928);
                              if (iVar11 == 0) {
                                local_a8 = 0;
                              }
                              else {
                                iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-binary");
                                if (iVar11 == 0) {
                                  local_a8 = 1;
                                }
                                else if ((cVar1 == 'd') && (pcVar15[2] == '\0')) {
                                  bVar3 = true;
                                }
                                else {
                                  iVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                     (pcVar15,"-fips-fingerprint");
                                  if (iVar11 == 0) {
                                    local_88 = "etaonrishdlcupfm";
                                  }
                                  else {
                                    iVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                       (pcVar15,"-non-fips-allow");
                                    if (iVar11 == 0) {
                                      bVar5 = true;
                                    }
                                    else {
                                      iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-hmac");
                                      if (iVar11 == 0) {
                                        iVar11 = unaff_s6 + -1;
                                        if (iVar11 == 0) goto LAB_004282a0;
                                        local_88 = unaff_s4[1];
                                        ppcVar16 = unaff_s4 + 1;
                                        unaff_s6 = iVar11;
                                      }
                                      else {
                                        iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-mac");
                                        if (iVar11 == 0) {
                                          iVar11 = unaff_s6 + -1;
                                          if (iVar11 == 0) goto LAB_004282a0;
                                          local_94 = unaff_s4[1];
                                          ppcVar16 = unaff_s4 + 1;
                                          unaff_s6 = iVar11;
                                        }
                                        else {
                                          iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-sigopt")
                                          ;
                                          if (iVar11 == 0) {
                                            iVar11 = unaff_s6 + -1;
                                            if (unaff_s6 + -1 == 0) goto LAB_004282a0;
                                            iVar12 = local_c0;
                                            if (local_c0 == 0) {
                                              iVar12 = (*(code *)PTR_sk_new_null_006a6fa4)();
                                              local_c0 = iVar12;
joined_r0x004293ac:
                                              iVar11 = unaff_s6 + -1;
                                              if (iVar12 == 0) goto LAB_004282a0;
                                            }
                                          }
                                          else {
                                            iVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                               (pcVar15,"-macopt");
                                            if (iVar11 != 0) {
                                              iVar13 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)
                                                                 (pcVar15 + 1);
                                              iVar11 = unaff_s6;
                                              if (iVar13 != 0) goto joined_r0x00428294;
                                              goto LAB_004282a0;
                                            }
                                            iVar11 = unaff_s6 + -1;
                                            if (unaff_s6 + -1 == 0) goto LAB_004282a0;
                                            iVar12 = unaff_s7;
                                            if (unaff_s7 == 0) {
                                              iVar12 = (*(code *)PTR_sk_new_null_006a6fa4)();
                                              unaff_s7 = iVar12;
                                              goto joined_r0x004293ac;
                                            }
                                          }
                                          ppcVar16 = unaff_s4 + 1;
                                          unaff_s4 = unaff_s4 + 1;
                                          iVar12 = (*(code *)PTR_sk_push_006a6fa8)(iVar12,*ppcVar16)
                                          ;
                                          iVar11 = unaff_s6 + -1;
                                          ppcVar16 = unaff_s4;
                                          unaff_s6 = unaff_s6 + -1;
                                          if (iVar12 == 0) goto LAB_004282a0;
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
          if ((cVar1 != 'r') || (pcVar15[2] != '\0')) goto LAB_00428220;
          unaff_s5 = 2;
        }
joined_r0x00428294:
        local_78 = iVar13;
        unaff_s6 = unaff_s6 + -1;
        unaff_s4 = ppcVar16 + 1;
        iVar11 = unaff_s6;
        if ((unaff_s6 == 0) || (pcVar15 = ppcVar16[1], *pcVar15 != '-')) goto LAB_004282a0;
      } while( true );
    }
    bVar5 = false;
    local_94 = (char *)0x0;
    unaff_s5 = 0;
    local_88 = (char *)0x0;
    unaff_s7 = 0;
    local_a8 = 0xffffffff;
    local_9c = (char *)0x0;
    bVar2 = false;
    bVar4 = false;
    local_bc = (char *)0x0;
    local_8c = (char *)0x0;
    local_b0 = (char *)0x0;
    local_ac = (char *)0x0;
    local_74 = 3;
    bVar3 = false;
    local_84 = 0;
    local_c0 = 0;
    goto LAB_004282ac;
  }
  unaff_s7 = 0;
  local_c0 = 0;
  iVar11 = unaff_s6;
LAB_00428038:
  ppcVar16 = (char **)0x0;
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar7,0x2000);
  puVar17 = (undefined4 *)0x1;
  unaff_s3 = 0;
  param_2 = (undefined4 *)0x0;
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar7);
  unaff_s6 = iVar11;
LAB_0042806c:
  do {
    unaff_s8 = iVar7;
    if (local_60 != 0) {
LAB_00428078:
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    (*(code *)PTR_BIO_free_all_006a6e74)(unaff_s3);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(local_64);
    if (local_c0 != 0) {
      (*(code *)PTR_sk_free_006a6e80)(local_c0);
    }
    if (unaff_s7 != 0) {
      (*(code *)PTR_sk_free_006a6e80)(unaff_s7);
    }
    if (ppcVar16 != (char **)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(ppcVar16);
    }
    iVar7 = unaff_s8;
    if (param_2 != (undefined4 *)0x0) {
      (*(code *)PTR_BIO_free_006a6e70)(param_2);
    }
LAB_004280fc:
    if (local_2c == *(int *)puVar6) {
      return puVar17;
    }
    pcVar18 = (code *)PTR___stack_chk_fail_006a9ab0;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004291b4:
    local_78 = (*pcVar18)();
LAB_00428f18:
    iVar13 = (*(code *)PTR_BIO_ctrl_006a6e18)(param_2,0x6f,0,local_78);
    if (iVar13 == 0) {
      ppcVar16 = (char **)0x0;
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"Error setting digest %s\n",local_6c);
      uVar14 = *puVar17;
      puVar17 = (undefined4 *)0x1;
      (*(code *)PTR_ERR_print_errors_006a6e40)(uVar14);
      ppcVar8 = unaff_s4;
    }
    else {
LAB_00428884:
      ppcVar8 = unaff_s4;
      if ((local_8c == (char *)0x0) || (local_64 == 0)) {
        local_bc = (char *)0x0;
        ppcVar16 = (char **)0x0;
LAB_0042892c:
        uVar14 = (*(code *)PTR_BIO_push_006a74c4)(param_2,local_b8);
        if (local_78 == 0) {
          (*(code *)PTR_BIO_ctrl_006a6e18)(param_2,0x78,0,&local_58);
          local_78 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(local_58);
        }
        if (unaff_s6 == 0) {
          (*(code *)PTR_BIO_ctrl_006a6e18)(local_b8,0x6a,0,*(undefined4 *)PTR_stdin_006a9a14);
          puVar17 = (undefined4 *)
                    do_fp(unaff_s3,iVar7,uVar14,unaff_s5,local_a8,local_64,ppcVar16,local_bc,0,0,
                          "stdin",param_2);
        }
        else {
          local_58 = 0;
          if (local_a8 == 0) {
            if ((local_64 != 0) &&
               (iVar13 = (*(code *)PTR_EVP_PKEY_get0_asn1_006a74fc)(), iVar13 != 0)) {
              (*(code *)PTR_EVP_PKEY_asn1_get0_info_006a6fc0)(0,0,0,0,&local_58,iVar13);
            }
            uVar9 = (*(code *)PTR_EVP_MD_type_006a73cc)(local_78);
            local_b4 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar9);
          }
          else {
            local_b4 = 0;
          }
          puVar17 = (undefined4 *)0x0;
          if (0 < unaff_s6) {
            iVar13 = 0;
            do {
              iVar11 = (*(code *)PTR_BIO_ctrl_006a6e18)(local_b8,0x6c,3,*unaff_s4);
              if (iVar11 < 1) {
                puVar17 = (undefined4 *)((int)puVar17 + 1);
                (*(code *)PTR_perror_006a9a80)(*unaff_s4);
              }
              else {
                puVar10 = (undefined4 *)
                          do_fp(unaff_s3,iVar7,uVar14,unaff_s5,local_a8,local_64,ppcVar16,local_bc,
                                local_58,local_b4,*unaff_s4,param_2);
                if (puVar10 != (undefined4 *)0x0) {
                  puVar17 = puVar10;
                }
                (*(code *)PTR_BIO_ctrl_006a6e18)(param_2,1,0,0);
              }
              iVar13 = iVar13 + 1;
              unaff_s4 = unaff_s4 + 1;
              ppcVar8 = ppcVar16;
            } while (unaff_s6 != iVar13);
          }
        }
      }
      else {
        iVar13 = (*(code *)PTR_BIO_new_file_006a6eac)(local_8c,&DAT_00633e40);
        uVar14 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(local_64);
        ppcVar16 = (char **)(*(code *)PTR_CRYPTO_malloc_006a7008)(uVar14,local_b4 + 0x38f0,0x1bd);
        if (iVar13 == 0) {
          uVar14 = *puVar17;
          pcVar15 = "Error opening signature file %s\n";
LAB_004291ec:
          (*(code *)PTR_BIO_printf_006a6e38)(uVar14,pcVar15,local_8c);
        }
        else {
          if (ppcVar16 != (char **)0x0) {
            local_bc = (char *)(*(code *)PTR_BIO_read_006a74c0)(iVar13,ppcVar16,uVar14);
            (*(code *)PTR_BIO_free_006a6e70)(iVar13);
            if (0 < (int)local_bc) goto LAB_0042892c;
            uVar14 = *puVar17;
            pcVar15 = "Error reading signature file %s\n";
            goto LAB_004291ec;
          }
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"Out of memory\n");
        }
        uVar14 = *puVar17;
        puVar17 = (undefined4 *)0x1;
        (*(code *)PTR_ERR_print_errors_006a6e40)(uVar14);
      }
    }
LAB_004283f8:
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar7,0x2000);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar7);
    unaff_s4 = ppcVar8;
LAB_00428420:
    (*(code *)PTR_BIO_free_006a6e70)(local_b8);
  } while( true );
LAB_004282a0:
  unaff_s6 = iVar11;
  if ((bVar2) && (local_8c == (char *)0x0)) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar17,"No signature to verify: use the -signature option\n");
  }
  else {
LAB_004282ac:
    if ((unaff_s6 < 1) || (**unaff_s4 != '-')) {
      uVar14 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      local_b8 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar14);
      uVar14 = (*(code *)PTR_BIO_f_md_006a74d8)();
      param_2 = (undefined4 *)(*(code *)PTR_BIO_new_006a6ea4)(uVar14);
      if ((local_b8 == (undefined *)0x0) || (param_2 == (undefined4 *)0x0)) {
        (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar17);
        (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar7,0x2000);
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar7);
        if (local_b8 != (undefined *)0x0) {
          unaff_s3 = 0;
          puVar17 = (undefined4 *)0x1;
          ppcVar16 = (char **)0x0;
          goto LAB_00428420;
        }
        ppcVar16 = (char **)0x0;
        puVar17 = (undefined4 *)0x1;
        unaff_s3 = 0;
        goto LAB_0042806c;
      }
      if (bVar3) {
        (*(code *)PTR_BIO_set_callback_006a74dc)(local_b8,PTR_BIO_debug_callback_006a74e0);
        (*(code *)PTR_BIO_set_callback_arg_006a74e4)(local_b8,*puVar17);
      }
      iVar13 = (*(code *)PTR_app_passwd_006a6e54)(*puVar17,local_9c,0,&local_60,0);
      ppcVar8 = unaff_s4;
      if (iVar13 == 0) {
        ppcVar16 = (char **)0x0;
        unaff_s3 = 0;
        puVar17 = (undefined4 *)0x1;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)PTR_bio_err_006a6e3c,"Error getting password\n");
        goto LAB_004283f8;
      }
      if (local_a8 == 0xffffffff) {
        local_a8 = (uint)(local_b0 != (char *)0x0);
      }
      if (local_bc != (char *)0x0) {
        (*(code *)PTR_app_RAND_load_file_006a6ecc)(local_bc,*puVar17,0);
      }
      if (local_ac == (char *)0x0) {
        unaff_s3 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
        if (unaff_s3 == 0) {
          uVar14 = *puVar17;
          local_ac = "(stdout)";
          goto LAB_00428e40;
        }
      }
      else {
        if (local_a8 == 0) {
          unaff_s3 = (*(code *)PTR_BIO_new_file_006a6eac)(local_ac,"w");
        }
        else {
          unaff_s3 = (*(code *)PTR_BIO_new_file_006a6eac)(local_ac,&DAT_00632420);
        }
        if (unaff_s3 == 0) {
          uVar14 = *puVar17;
LAB_00428e40:
          ppcVar16 = (char **)0x0;
          unaff_s3 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)(uVar14,"Error opening output file %s\n",local_ac);
          uVar14 = *puVar17;
          puVar17 = (undefined4 *)0x1;
          (*(code *)PTR_ERR_print_errors_006a6e40)(uVar14);
          goto LAB_004283f8;
        }
      }
      if (1 < (byte)((local_94 != (char *)0x0) + (local_b0 != (char *)0x0) +
                    (local_88 != (char *)0x0))) {
        uVar14 = *puVar17;
        ppcVar16 = (char **)0x0;
        puVar17 = (undefined4 *)0x1;
        (*(code *)PTR_BIO_printf_006a6e38)(uVar14,"MAC and Signing key cannot both be specified\n");
        goto LAB_004283f8;
      }
      if (local_b0 != (char *)0x0) {
        pcVar18 = (code *)PTR_load_key_006a6ec8;
        iVar13 = local_60;
        if (bVar4) {
          pcVar18 = (code *)PTR_load_pubkey_006a74e8;
          iVar13 = 0;
        }
        local_64 = (*pcVar18)(*puVar17,local_b0,local_74,0,iVar13,local_84,"key file");
        if (local_64 == 0) goto LAB_00428d90;
      }
      if (local_94 == (char *)0x0) {
LAB_0042877c:
        if (bVar5) {
          (*(code *)PTR_BIO_ctrl_006a6e18)(param_2,0x78,0,&local_58);
          (*(code *)PTR_EVP_MD_CTX_set_flags_006a7504)(local_58,8);
        }
        if (local_88 == (char *)0x0) {
          if (local_64 == 0) {
            pcVar18 = (code *)PTR_EVP_md5_006a70c8;
            if (local_78 == 0) goto LAB_004291b4;
            goto LAB_00428f18;
          }
        }
        else {
          local_64 = (*(code *)PTR_EVP_PKEY_new_mac_key_006a74f0)
                               (0x357,local_84,local_88,0xffffffff);
          ppcVar8 = unaff_s4;
          if (local_64 == 0) goto LAB_00428d90;
        }
        local_5c = 0;
        local_58 = 0;
        iVar13 = (*(code *)PTR_BIO_ctrl_006a6e18)(param_2,0x78,0,&local_5c);
        if (iVar13 == 0) {
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"Error getting context\n");
        }
        else {
          pcVar18 = (code *)PTR_EVP_DigestSignInit_006a6e20;
          if (bVar2) {
            pcVar18 = (code *)PTR_EVP_DigestVerifyInit_006a74f4;
          }
          iVar13 = (*pcVar18)(local_5c,&local_58,local_78,0,local_64);
          if (iVar13 == 0) {
            (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"Error setting context\n");
          }
          else {
            if (local_c0 == 0) goto LAB_00428884;
            iVar13 = 0;
            while( true ) {
              iVar11 = (*(code *)PTR_sk_num_006a6e2c)(local_c0);
              if (iVar11 <= iVar13) goto LAB_00428884;
              uVar14 = (*(code *)PTR_sk_value_006a6e24)(local_c0,iVar13);
              iVar11 = (*(code *)PTR_pkey_ctrl_string_006a6e28)(local_58,uVar14);
              if (iVar11 < 1) break;
              iVar13 = iVar13 + 1;
            }
            (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"parameter error \"%s\"\n",uVar14);
          }
        }
        (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar17);
        ppcVar8 = unaff_s4;
      }
      else {
        local_58 = 0;
        iVar13 = init_gen_str(*puVar17,&local_58,local_94,local_84,0);
        if (iVar13 != 0) {
          if (unaff_s7 != 0) {
            for (iVar13 = 0; iVar11 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s7), iVar13 < iVar11;
                iVar13 = iVar13 + 1) {
              ppcVar8 = (char **)(*(code *)PTR_sk_value_006a6e24)(unaff_s7,iVar13);
              iVar11 = (*(code *)PTR_pkey_ctrl_string_006a6e28)(local_58,ppcVar8);
              if (iVar11 < 1) {
                (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"MAC parameter error \"%s\"\n",ppcVar8);
                goto LAB_00428db8;
              }
            }
          }
          iVar13 = (*(code *)PTR_EVP_PKEY_keygen_006a6f48)(local_58,&local_64);
          if (0 < iVar13) {
            if (local_58 != 0) {
              (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)();
            }
            goto LAB_0042877c;
          }
          (*(code *)PTR_BIO_puts_006a6f58)(*puVar17,"Error generating key\n");
          ppcVar8 = unaff_s4;
LAB_00428db8:
          (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar17);
        }
        if (local_58 != 0) {
          ppcVar16 = (char **)0x0;
          puVar17 = (undefined4 *)0x1;
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)();
          goto LAB_004283f8;
        }
      }
LAB_00428d90:
      ppcVar16 = (char **)0x0;
      puVar17 = (undefined4 *)0x1;
      goto LAB_004283f8;
    }
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"unknown option \'%s\'\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"options are\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar17,"-c              to output the digest with separating colons\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar17,"-r              to output the digest in coreutils format\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"-d              to output debug info\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"-hex            output as hex dump\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"-binary         output in binary form\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"-hmac arg       set the HMAC key to arg\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"-non-fips-allow allow use of non FIPS digest\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar17,"-sign   file    sign digest using private key in file\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar17,"-verify file    verify a signature using public key in file\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar17,"-prverify file  verify a signature using private key in file\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"-keyform arg    key file format (PEM or ENGINE)\n")
    ;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar17,"-out filename   output to filename rather than stdout\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"-signature file signature to verify\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"-sigopt nm:v    signature parameter\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"-hmac key       create hashed MAC with key\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar17,"-mac algorithm  create MAC (not neccessarily HMAC)\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar17,"-macopt nm:v    MAC algorithm parameters or key\n")
    ;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar17,"-engine e       use engine e, possibly a hardware device.\n");
    (*(code *)PTR_EVP_MD_do_all_sorted_006a73c0)(list_md_fn,*puVar17);
    iVar11 = unaff_s6;
  }
  goto LAB_00428038;
}

