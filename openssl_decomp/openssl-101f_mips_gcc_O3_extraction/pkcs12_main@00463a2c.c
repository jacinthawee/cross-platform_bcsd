
uint pkcs12_main(undefined4 param_1,int param_2)

{
  int *piVar1;
  char **ppcVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined *unaff_s2;
  char *unaff_s3;
  undefined4 *puVar11;
  char *unaff_s5;
  char *pcVar12;
  int unaff_s7;
  int unaff_s8;
  int local_19c;
  undefined *local_198;
  char *local_194;
  undefined4 local_190;
  char *local_18c;
  char *local_188;
  char *local_184;
  char *local_180;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  int local_16c;
  char *local_168;
  int local_164;
  int local_160;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  undefined4 local_14c;
  char *local_148;
  char *local_144;
  char *local_140;
  int local_13c;
  int local_138;
  int local_134;
  undefined4 local_12c;
  undefined4 local_128;
  char *local_124;
  char *local_120;
  undefined auStack_11c [136];
  char acStack_94 [52];
  char acStack_60 [52];
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006aabf0;
  puVar11 = (undefined4 *)PTR_enc_006a8338;
  puVar3 = PTR_bio_err_006a7f3c;
  local_128 = 0x92;
  local_124 = (char *)0x0;
  local_120 = (char *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  local_12c = 0x95;
  uVar5 = (*(code *)PTR_EVP_des_ede3_cbc_006a7f48)();
  iVar8 = *(int *)puVar3;
  *puVar11 = uVar5;
  if (iVar8 == 0) {
    iVar8 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *(int *)puVar3 = iVar8;
  }
  iVar8 = load_config(iVar8,0);
  if (iVar8 == 0) {
    uVar10 = 1;
    (*(code *)PTR_BIO_free_006a7f70)(0);
    (*(code *)PTR_BIO_free_all_006a7f74)(0);
    goto LAB_004640c8;
  }
  unaff_s5 = *(char **)(param_2 + 4);
  unaff_s8 = param_2 + 4;
  local_17c = 0;
  local_134 = 0;
  unaff_s7 = 0;
  local_13c = 1;
  local_138 = 0;
  local_154 = 0;
  local_198 = (undefined *)0x0;
  local_18c = (char *)0x0;
  local_16c = 0;
  local_170 = 0;
  local_178 = 0;
  local_190 = 0;
  local_174 = 0;
  local_15c = 0x800;
  local_14c = 0x800;
  if (unaff_s5 == (char *)0x0) {
    uVar10 = 0;
    local_160 = 0;
    local_19c = 0;
    local_144 = (char *)0x0;
    local_158 = 0;
    local_150 = 0;
    local_164 = 0;
    local_148 = (char *)0x0;
    local_184 = (char *)0x0;
    local_188 = (char *)0x0;
    goto LAB_004641e0;
  }
  local_160 = 0;
  local_19c = 0;
  local_144 = (char *)0x0;
  unaff_s2 = (undefined *)0x0;
  local_158 = 0;
  uVar10 = 0;
  local_150 = 0;
  local_194 = "-keyex";
  unaff_s3 = "-nokeys";
  local_164 = 0;
  local_148 = (char *)0x0;
  local_180 = "s\n";
  local_184 = (char *)0x0;
  local_188 = (char *)0x0;
  local_168 = "-nocerts";
  local_140 = "s\n";
LAB_00463b84:
  if (*unaff_s5 == '-') {
    iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,unaff_s3);
    if (iVar8 == 0) {
      uVar10 = uVar10 | 1;
      goto LAB_00463b98;
    }
    iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,local_194);
    if (iVar8 == 0) {
      local_190 = 0x10;
      goto LAB_00463b98;
    }
    iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,local_180 + 0x1c04);
    if (iVar8 == 0) {
      local_190 = 0x80;
      goto LAB_00463b98;
    }
    iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,local_168);
    if (iVar8 == 0) {
      uVar10 = uVar10 | 2;
      goto LAB_00463b98;
    }
    iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,local_140 + 0x1c18);
    if (iVar8 == 0) {
      uVar10 = uVar10 | 8;
      goto LAB_00463b98;
    }
    iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-cacerts");
    if (iVar8 == 0) {
      uVar10 = uVar10 | 0x10;
      goto LAB_00463b98;
    }
    iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-noout");
    if (iVar8 == 0) {
      uVar10 = uVar10 | 3;
      goto LAB_00463b98;
    }
    iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-info");
    if (iVar8 != 0) {
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-chain");
      if (iVar8 == 0) {
        local_160 = 1;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-twopass");
      if (iVar8 == 0) {
        local_174 = 1;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-nomacver");
      if (iVar8 == 0) {
        local_13c = 0;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-descert");
      if (iVar8 != 0) goto LAB_00464fdc;
      local_12c = 0x92;
      goto LAB_00463b98;
    }
    uVar10 = uVar10 | 4;
    goto LAB_00463b98;
  }
LAB_00463b94:
  unaff_s2 = (undefined *)0x1;
LAB_00463b98:
  do {
    unaff_s5 = *(char **)(unaff_s8 + 4);
    unaff_s8 = unaff_s8 + 4;
    if (unaff_s5 != (char *)0x0) goto LAB_00463b84;
    if (unaff_s2 == (undefined *)0x0) {
LAB_004641e0:
      unaff_s2 = PTR_bio_err_006a7f3c;
      unaff_s8 = setup_engine(*(undefined4 *)puVar3,local_17c,0);
      if (local_18c != (char *)0x0) {
        if (local_19c == 0) {
          iVar8 = app_passwd(*(undefined4 *)unaff_s2,local_18c,local_16c,&local_124,&local_120);
          if (iVar8 != 0) goto LAB_00464234;
        }
        else {
          iVar8 = app_passwd(*(undefined4 *)unaff_s2,local_170,local_18c,&local_124,&local_120);
          if (iVar8 != 0) goto LAB_00464474;
        }
LAB_004644ec:
        unaff_s3 = (char *)0x0;
        puVar11 = (undefined4 *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Error getting passwords\n");
        goto LAB_0046403c;
      }
      iVar8 = app_passwd(*(undefined4 *)unaff_s2,local_170,local_16c,&local_124,&local_120);
      if (iVar8 == 0) goto LAB_004644ec;
      if (local_19c == 0) {
LAB_00464234:
        if (local_124 == (char *)0x0) {
LAB_0046493c:
          local_18c = acStack_60;
          unaff_s5 = acStack_94;
        }
        else {
          local_18c = local_124;
          local_178 = 1;
          unaff_s5 = local_124;
        }
        if (local_198 != (undefined *)0x0) {
          app_RAND_load_file(0,*(undefined4 *)puVar3,1);
LAB_0046426c:
          unaff_s2 = *(undefined **)puVar3;
          uVar5 = app_RAND_load_files(local_198);
          (*(code *)PTR_BIO_printf_006a7f38)(unaff_s2,"%ld semi-random bytes loaded\n",uVar5);
        }
      }
      else {
LAB_00464474:
        if (local_120 == (char *)0x0) {
          local_18c = acStack_60;
          if (local_19c == 0) goto LAB_0046493c;
          unaff_s5 = acStack_94;
        }
        else {
          local_18c = local_120;
          local_178 = 1;
          unaff_s5 = local_120;
        }
        app_RAND_load_file(0,*(undefined4 *)puVar3,local_198 != (undefined *)0x0);
        unaff_s2 = local_198;
        if (local_198 != (undefined *)0x0) goto LAB_0046426c;
      }
      (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
      if (local_188 == (char *)0x0) {
        puVar11 = (undefined4 *)
                  (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdin_006aab20,0);
        if (puVar11 == (undefined4 *)0x0) {
          uVar5 = *(undefined4 *)puVar3;
          pcVar12 = "<stdin>";
          goto LAB_00464ac8;
        }
      }
      else {
        puVar11 = (undefined4 *)(*(code *)PTR_BIO_new_file_006a7fac)(local_188,&DAT_006347ac);
        if (puVar11 == (undefined4 *)0x0) {
          uVar5 = *(undefined4 *)puVar3;
          pcVar12 = local_188;
LAB_00464ac8:
          unaff_s3 = (char *)0x0;
          puVar11 = (undefined4 *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)(uVar5,"Error opening input file %s\n",pcVar12);
          (*(code *)PTR_perror_006aab88)(local_188);
          goto LAB_0046403c;
        }
      }
      if (local_184 == (char *)0x0) {
        unaff_s3 = (char *)(*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
        if (unaff_s3 == (char *)0x0) {
          uVar5 = *(undefined4 *)puVar3;
          pcVar12 = "<stdout>";
          goto LAB_00464b24;
        }
      }
      else {
        unaff_s3 = (char *)(*(code *)PTR_BIO_new_file_006a7fac)(local_184,&DAT_00632de8);
        if (unaff_s3 == (char *)0x0) {
          uVar5 = *(undefined4 *)puVar3;
          pcVar12 = local_184;
LAB_00464b24:
          unaff_s3 = (char *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)(uVar5,"Error opening output file %s\n",pcVar12);
          (*(code *)PTR_perror_006aab88)(local_184);
          goto LAB_0046403c;
        }
      }
      if ((local_174 != 0) &&
         (iVar8 = (*(code *)PTR_EVP_read_pw_string_006a8388)
                            (acStack_60,0x32,"Enter MAC Password:",local_19c), iVar8 != 0)) {
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Can\'t read Password\n");
        goto LAB_0046403c;
      }
      if (local_19c == 0) {
        unaff_s8 = (*(code *)PTR_d2i_PKCS12_bio_006a838c)(puVar11,0);
        if (unaff_s8 != 0) {
          if ((local_178 == 0) &&
             (iVar8 = (*(code *)PTR_EVP_read_pw_string_006a8388)
                                (acStack_94,0x32,"Enter Import Password:",0), iVar8 != 0)) {
            uVar10 = 1;
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Can\'t read Password\n");
          }
          else {
            if (local_174 == 0) {
              (*(code *)PTR_BUF_strlcpy_006a8064)(acStack_60,acStack_94,0x32);
            }
            if (((uVar10 & 4) != 0) && (*(int *)(unaff_s8 + 4) != 0)) {
              unaff_s2 = *(undefined **)puVar3;
              if (*(int *)(*(int *)(unaff_s8 + 4) + 8) == 0) {
                uVar5 = 1;
              }
              else {
                uVar5 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)();
              }
              (*(code *)PTR_BIO_printf_006a7f38)(unaff_s2,"MAC Iteration %ld\n",uVar5);
            }
            if (local_13c != 0) {
              if ((*local_18c == '\0') &&
                 (iVar8 = (*(code *)PTR_PKCS12_verify_mac_006a8390)(unaff_s8,0,0), iVar8 != 0)) {
                if (local_174 == 0) {
                  unaff_s5 = (char *)0x0;
                }
              }
              else {
                iVar8 = (*(code *)PTR_PKCS12_verify_mac_006a8390)(unaff_s8,local_18c,0xffffffff);
                if (iVar8 == 0) {
                  uVar10 = 1;
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar3,"Mac verify error: invalid password?\n");
                  (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar3);
                  goto LAB_004647d0;
                }
              }
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"MAC verified OK\n");
            }
            iVar8 = dump_certs_keys_p12(unaff_s3,unaff_s8,unaff_s5,0xffffffff,uVar10,local_120);
            if (iVar8 == 0) {
              uVar10 = 1;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar3,"Error outputting keys and certificates\n");
              (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar3);
            }
            else {
              uVar10 = 0;
            }
          }
LAB_004647d0:
          (*(code *)PTR_PKCS12_free_006a837c)(unaff_s8);
          goto LAB_00464040;
        }
        uVar10 = 1;
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar3);
        goto LAB_0046404c;
      }
      if ((uVar10 & 3) == 3) {
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Nothing to do!\n");
LAB_00464b94:
        uVar10 = 1;
      }
      else {
        unaff_s2 = (undefined *)(uVar10 & 2);
        if (unaff_s2 == (undefined *)0x0) {
          if ((uVar10 & 1) != 0) {
            uVar10 = 1;
            unaff_s2 = (undefined *)
                       load_certs(*(undefined4 *)puVar3,local_188,3,0,unaff_s8,"certificates");
            if (unaff_s2 != (undefined *)0x0) {
              local_194 = (char *)0x0;
              local_188 = (char *)0x0;
LAB_00464c70:
              if (local_164 == 0) goto LAB_004645dc;
              iVar8 = load_certs(*(undefined4 *)puVar3,local_164,3,0,unaff_s8,
                                 "certificates from certfile");
              if (iVar8 != 0) goto LAB_004645b8;
              uVar10 = 1;
              unaff_s8 = 0;
              goto LAB_0046477c;
            }
            goto LAB_0046405c;
          }
LAB_00464334:
          pcVar12 = local_148;
          if (local_148 == (char *)0x0) {
            pcVar12 = local_188;
          }
          local_194 = (char *)load_key(*(undefined4 *)puVar3,pcVar12,3,1,local_124,unaff_s8,
                                       "private key");
          if (local_194 == (char *)0x0) goto LAB_00464b94;
          if (unaff_s2 != (undefined *)0x0) {
            unaff_s2 = (undefined *)0x0;
            local_188 = (char *)0x0;
            goto LAB_00464c70;
          }
          unaff_s2 = (undefined *)
                     load_certs(*(undefined4 *)puVar3,local_188,3,0,unaff_s8,"certificates");
          if (unaff_s2 == (undefined *)0x0) {
            local_188 = (char *)0x0;
            uVar10 = 1;
            unaff_s8 = 0;
            pcVar12 = unaff_s5;
          }
          else {
            for (pcVar12 = (char *)0x0; iVar8 = (*(code *)PTR_sk_num_006a7f2c)(unaff_s2),
                local_184 = unaff_s5, (int)pcVar12 < iVar8; pcVar12 = pcVar12 + 1) {
              local_188 = (char *)(*(code *)PTR_sk_value_006a7f24)(unaff_s2,pcVar12);
              iVar8 = (*(code *)PTR_X509_check_private_key_006a817c)(local_188,local_194);
              if (iVar8 != 0) {
                (*(code *)PTR_X509_keyid_set1_006a8394)(local_188,0,0);
                (*(code *)PTR_X509_alias_set1_006a8368)(local_188,0,0);
                (*(code *)PTR_sk_delete_006a8398)(unaff_s2,pcVar12);
                pcVar12 = unaff_s5;
                if (local_188 != (char *)0x0) goto LAB_00464c70;
                break;
              }
            }
            uVar10 = 1;
            unaff_s8 = 0;
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar3,"No certificate matches private key\n");
            local_188 = (char *)0x0;
          }
LAB_00464788:
          (*(code *)PTR_EVP_PKEY_free_006a7f78)(local_194);
          unaff_s5 = pcVar12;
        }
        else {
          if ((uVar10 & 1) == 0) {
            local_160 = 0;
            goto LAB_00464334;
          }
          if (local_164 == 0) {
            local_194 = (char *)0x0;
            unaff_s2 = (undefined *)0x0;
            local_188 = (char *)0x0;
LAB_004645e8:
            for (iVar8 = 0; iVar6 = (*(code *)PTR_sk_num_006a7f2c)(unaff_s7), iVar8 < iVar6;
                iVar8 = iVar8 + 1) {
              uVar5 = (*(code *)PTR_sk_value_006a7f24)(unaff_s7,iVar8);
              uVar7 = (*(code *)PTR_sk_value_006a7f24)(unaff_s2,iVar8);
              (*(code *)PTR_X509_alias_set1_006a8368)(uVar7,uVar5,0xffffffff);
            }
            if (local_158 == 0) {
              pcVar12 = local_194;
              if (local_144 != (char *)0x0) goto joined_r0x00464ddc;
            }
            else if (local_194 != (char *)0x0) {
              (*(code *)PTR_EVP_PKEY_add1_attr_by_NID_006a836c)
                        (local_194,0x1a1,0x1001,local_158,0xffffffff);
              pcVar12 = local_144;
joined_r0x00464ddc:
              if (pcVar12 != (char *)0x0) {
                (*(code *)PTR_EVP_PKEY_add1_attr_by_NID_006a836c)(local_194,0x358,0,0,0xffffffff);
              }
            }
            if ((local_178 == 0) &&
               (iVar8 = (*(code *)PTR_EVP_read_pw_string_006a8388)
                                  (acStack_94,0x32,"Enter Export Password:",1), iVar8 != 0)) {
              uVar10 = 1;
              unaff_s8 = 0;
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Can\'t read Password\n");
            }
            else {
              if (local_174 == 0) {
                (*(code *)PTR_BUF_strlcpy_006a8064)(acStack_60,acStack_94,0x32);
              }
              unaff_s8 = (*(code *)PTR_PKCS12_create_006a8370)
                                   (unaff_s5,local_150,local_194,local_188,unaff_s2,local_128,
                                    local_12c,local_14c,0xffffffff,local_190);
              if (unaff_s8 == 0) {
                uVar10 = 1;
                (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar3);
              }
              else {
                if (local_154 == 0) {
                  iVar8 = 0;
                }
                else {
                  iVar8 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(local_154);
                  if (iVar8 == 0) {
                    (*(code *)PTR_BIO_printf_006a7f38)
                              (*(undefined4 *)puVar3,"Unknown digest algorithm %s\n",local_154);
                  }
                }
                if (local_15c != -1) {
                  (*(code *)PTR_PKCS12_set_mac_006a8374)
                            (unaff_s8,local_18c,0xffffffff,0,0,local_15c,iVar8);
                }
                uVar10 = 0;
                (*(code *)PTR_i2d_PKCS12_bio_006a8378)(unaff_s3,unaff_s8);
              }
            }
          }
          else {
            iVar8 = load_certs(*(undefined4 *)puVar3,local_164,3,0,unaff_s8,
                               "certificates from certfile");
            if (iVar8 == 0) goto LAB_00464b94;
            local_160 = 0;
            unaff_s2 = (undefined *)0x0;
            local_188 = (char *)0x0;
            local_194 = (char *)0x0;
LAB_004645b8:
            while (iVar6 = (*(code *)PTR_sk_num_006a7f2c)(iVar8), 0 < iVar6) {
              uVar5 = (*(code *)PTR_sk_shift_006a8360)(iVar8);
              (*(code *)PTR_sk_push_006a80a8)(unaff_s2,uVar5);
            }
            (*(code *)PTR_sk_free_006a7f80)(iVar8);
LAB_004645dc:
            if (local_160 == 0) goto LAB_004645e8;
            unaff_s8 = (*(code *)PTR_X509_STORE_new_006a8364)();
            if (unaff_s8 == 0) {
              uVar10 = 1;
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Memory allocation error\n");
            }
            else {
              iVar8 = (*(code *)PTR_X509_STORE_load_locations_006a8380)
                                (unaff_s8,local_134,local_138);
              if (iVar8 == 0) {
                (*(code *)PTR_X509_STORE_set_default_paths_006a83a0)(unaff_s8);
              }
              (*(code *)PTR_X509_STORE_CTX_init_006a8304)(auStack_11c,unaff_s8,local_188,0);
              iVar8 = (*(code *)PTR_X509_verify_cert_006a8308)(auStack_11c);
              if (0 < iVar8) {
                uVar5 = (*(code *)PTR_X509_STORE_CTX_get1_chain_006a830c)(auStack_11c);
                (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(auStack_11c);
                (*(code *)PTR_X509_STORE_free_006a8384)(unaff_s8);
                for (iVar8 = 1; iVar6 = (*(code *)PTR_sk_num_006a7f2c)(uVar5), iVar8 < iVar6;
                    iVar8 = iVar8 + 1) {
                  uVar7 = (*(code *)PTR_sk_value_006a7f24)(uVar5,iVar8);
                  (*(code *)PTR_sk_push_006a80a8)(unaff_s2,uVar7);
                }
                uVar7 = (*(code *)PTR_sk_value_006a7f24)(uVar5,0);
                (*(code *)PTR_X509_free_006a7f90)(uVar7);
                (*(code *)PTR_sk_free_006a7f80)(uVar5);
                goto LAB_004645e8;
              }
              unaff_s5 = (char *)(*(code *)PTR_X509_STORE_CTX_get_error_006a8314)(auStack_11c);
              if (unaff_s5 == (char *)0x0) {
                (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(auStack_11c);
                (*(code *)PTR_X509_STORE_free_006a8384)(unaff_s8);
              }
              else {
                (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(auStack_11c);
                (*(code *)PTR_X509_STORE_free_006a8384)(unaff_s8);
                if (-1 < (int)unaff_s5) {
                  uVar7 = *(undefined4 *)puVar3;
                  unaff_s8 = 0;
                  uVar5 = (*(code *)PTR_X509_verify_cert_error_string_006a839c)(unaff_s5);
                  uVar10 = 1;
                  (*(code *)PTR_BIO_printf_006a7f38)(uVar7,"Error %s getting chain.\n",uVar5);
                  goto LAB_0046477c;
                }
              }
              uVar10 = 1;
              unaff_s8 = 0;
              (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar3);
            }
          }
LAB_0046477c:
          pcVar12 = unaff_s5;
          if (local_194 != (char *)0x0) goto LAB_00464788;
        }
        if (unaff_s2 != (undefined *)0x0) {
          (*(code *)PTR_sk_pop_free_006a8158)(unaff_s2,PTR_X509_free_006a7f90);
        }
        if (local_188 != (char *)0x0) {
          (*(code *)PTR_X509_free_006a7f90)(local_188);
        }
        if (unaff_s8 != 0) goto LAB_004647d0;
      }
LAB_0046405c:
      app_RAND_write_file(0,*(undefined4 *)puVar3);
    }
    else {
      unaff_s3 = (char *)0x0;
      puVar11 = (undefined4 *)0x0;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Usage: pkcs12 [options]\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"where options are\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-export       output PKCS12 file\n")
      ;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-chain        add certificate chain\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-inkey file   private key if not infile\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-certfile f   add all certs in f\n")
      ;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-CApath arg   - PEM format directory of CA\'s\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-CAfile arg   - PEM format file of CA\'s\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-name \"name\"  use name as friendly name\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,
                 "-caname \"nm\"  use nm as CA friendly name (can be used more than once).\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-in  infile   input filename\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-out outfile  output filename\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-noout        don\'t output anything, just verify.\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-nomacver     don\'t verify MAC.\n")
      ;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-nocerts      don\'t output certificates.\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-clcerts      only output client certificates.\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-cacerts      only output CA certificates.\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-nokeys       don\'t output private keys.\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-info         give info about PKCS#12 structure.\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-des          encrypt private keys with DES\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,
                 "-des3         encrypt private keys with triple DES (default)\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-idea         encrypt private keys with idea\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-seed         encrypt private keys with seed\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-aes128, -aes192, -aes256\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"              encrypt PEM output with cbc aes\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-camellia128, -camellia192, -camellia256\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"              encrypt PEM output with cbc camellia\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-nodes        don\'t encrypt private keys\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-noiter       don\'t use encryption iteration\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-nomaciter    don\'t use MAC iteration\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-maciter      use MAC iteration\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-nomac        don\'t generate MAC\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-twopass      separate MAC, encryption passwords\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,
                 "-descert      encrypt PKCS#12 certificates with triple DES (default RC2-40)\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,
                 "-certpbe alg  specify certificate PBE algorithm (default RC2-40)\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,
                 "-keypbe alg   specify private key PBE algorithm (default 3DES)\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-macalg alg   digest algorithm used in MAC (default SHA1)\n"
                );
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-keyex        set MS key exchange type\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-keysig       set MS key signature type\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-password p   set import/export password source\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-passin p     input file pass phrase source\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-passout p    output file pass phrase source\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"-engine e     use engine e, possibly a hardware device.\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-rand file%cfile%c...\n",0x3a,0x3a);
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,
                 "              load the file (or the files in the directory) into\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"              the random number generator\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-CSP name     Microsoft CSP name\n")
      ;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,
                 "-LMK          Add local machine keyset attribute to private key\n");
LAB_0046403c:
      uVar10 = 1;
LAB_00464040:
      if (local_19c != 0) goto LAB_0046405c;
LAB_0046404c:
      if (local_198 != (undefined *)0x0) goto LAB_0046405c;
    }
    (*(code *)PTR_BIO_free_006a7f70)(puVar11);
    (*(code *)PTR_BIO_free_all_006a7f74)(unaff_s3);
    if (unaff_s7 != 0) {
      (*(code *)PTR_sk_free_006a7f80)(unaff_s7);
    }
LAB_004640c8:
    if (local_124 != (char *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (local_120 != (char *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (local_2c == *(int *)puVar4) {
      return uVar10;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00464fdc:
    iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-export");
    if (iVar8 == 0) {
      local_19c = 1;
      goto LAB_00463b98;
    }
    iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,&DAT_0063ad0c);
    if (iVar8 != 0) {
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-des3");
      if (iVar8 == 0) {
        uVar5 = (*(code *)PTR_EVP_des_ede3_cbc_006a7f48)();
        *puVar11 = uVar5;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-idea");
      if (iVar8 == 0) {
        uVar5 = (*(code *)PTR_EVP_idea_cbc_006a83a8)();
        *puVar11 = uVar5;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-seed");
      if (iVar8 == 0) {
        uVar5 = (*(code *)PTR_EVP_seed_cbc_006a83b8)();
        *puVar11 = uVar5;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-aes128");
      if (iVar8 == 0) {
        uVar5 = (*(code *)PTR_EVP_aes_128_cbc_006a83b4)();
        *puVar11 = uVar5;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-aes192");
      if (iVar8 == 0) {
        uVar5 = (*(code *)PTR_EVP_aes_192_cbc_006a83b0)();
        *puVar11 = uVar5;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-aes256");
      if (iVar8 == 0) {
        uVar5 = (*(code *)PTR_EVP_aes_256_cbc_006a83ac)();
        *puVar11 = uVar5;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-camellia128");
      if (iVar8 == 0) {
        uVar5 = (*(code *)PTR_EVP_camellia_128_cbc_006a83c0)();
        *puVar11 = uVar5;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-camellia192");
      if (iVar8 == 0) {
        uVar5 = (*(code *)PTR_EVP_camellia_192_cbc_006a83bc)();
        *puVar11 = uVar5;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-camellia256");
      if (iVar8 == 0) {
        uVar5 = (*(code *)PTR_EVP_camellia_256_cbc_006a83c4)();
        *puVar11 = uVar5;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-noiter");
      if (iVar8 == 0) {
        local_14c = 1;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-maciter");
      if (iVar8 == 0) {
        local_15c = 0x800;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-nomaciter");
      if (iVar8 == 0) {
        local_15c = 1;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-nomac");
      if (iVar8 == 0) {
        local_15c = -1;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-macalg");
      if (iVar8 == 0) {
        piVar1 = (int *)(unaff_s8 + 4);
        if (*piVar1 == 0) goto LAB_00463b94;
        unaff_s8 = unaff_s8 + 4;
        local_154 = *piVar1;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-nodes");
      if (iVar8 == 0) {
        *puVar11 = 0;
        goto LAB_00463b98;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-certpbe");
      if (iVar8 == 0) {
        uVar5 = *(undefined4 *)(unaff_s8 + 4);
        puVar9 = &local_12c;
      }
      else {
        iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-keypbe");
        if (iVar8 != 0) {
          iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-rand");
          if (iVar8 == 0) {
            puVar9 = (undefined4 *)(unaff_s8 + 4);
            if ((undefined *)*puVar9 == (undefined *)0x0) goto LAB_00463b94;
            unaff_s8 = unaff_s8 + 4;
            local_198 = (undefined *)*puVar9;
            goto LAB_00463b98;
          }
          iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-inkey");
          if (iVar8 == 0) {
            ppcVar2 = (char **)(unaff_s8 + 4);
            if (*ppcVar2 == (char *)0x0) goto LAB_00463b94;
            unaff_s8 = unaff_s8 + 4;
            local_148 = *ppcVar2;
            goto LAB_00463b98;
          }
          iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-certfile");
          if (iVar8 == 0) {
            piVar1 = (int *)(unaff_s8 + 4);
            if (*piVar1 == 0) goto LAB_00463b94;
            unaff_s8 = unaff_s8 + 4;
            local_164 = *piVar1;
            goto LAB_00463b98;
          }
          iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-name");
          if (iVar8 == 0) {
            piVar1 = (int *)(unaff_s8 + 4);
            if (*piVar1 == 0) goto LAB_00463b94;
            unaff_s8 = unaff_s8 + 4;
            local_150 = *piVar1;
            goto LAB_00463b98;
          }
          iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,&DAT_00641ca8);
          if (iVar8 == 0) {
            local_144 = (char *)0x1;
            goto LAB_00463b98;
          }
          iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,&DAT_00641cb0);
          if (iVar8 == 0) {
            piVar1 = (int *)(unaff_s8 + 4);
            if (*piVar1 == 0) goto LAB_00463b94;
            unaff_s8 = unaff_s8 + 4;
            local_158 = *piVar1;
            goto LAB_00463b98;
          }
          iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-caname");
          if (iVar8 != 0) {
            if (((unaff_s5[1] == 'i') && (unaff_s5[2] == 'n')) && (unaff_s5[3] == '\0')) {
              ppcVar2 = (char **)(unaff_s8 + 4);
              if (*ppcVar2 == (char *)0x0) goto LAB_00463b94;
              unaff_s8 = unaff_s8 + 4;
              local_188 = *ppcVar2;
            }
            else {
              iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,&DAT_00632edc);
              if (iVar8 == 0) {
                ppcVar2 = (char **)(unaff_s8 + 4);
                if (*ppcVar2 == (char *)0x0) goto LAB_00463b94;
                unaff_s8 = unaff_s8 + 4;
                local_184 = *ppcVar2;
              }
              else {
                iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-passin");
                if (iVar8 == 0) {
                  piVar1 = (int *)(unaff_s8 + 4);
                  if (*piVar1 == 0) goto LAB_00463b94;
                  unaff_s8 = unaff_s8 + 4;
                  local_170 = *piVar1;
                }
                else {
                  iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-passout");
                  if (iVar8 == 0) {
                    piVar1 = (int *)(unaff_s8 + 4);
                    if (*piVar1 == 0) goto LAB_00463b94;
                    unaff_s8 = unaff_s8 + 4;
                    local_16c = *piVar1;
                  }
                  else {
                    iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-password");
                    if (iVar8 == 0) {
                      ppcVar2 = (char **)(unaff_s8 + 4);
                      if (*ppcVar2 == (char *)0x0) goto LAB_00463b94;
                      unaff_s8 = unaff_s8 + 4;
                      local_178 = 1;
                      local_18c = *ppcVar2;
                    }
                    else {
                      iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-CApath");
                      if (iVar8 == 0) {
                        piVar1 = (int *)(unaff_s8 + 4);
                        if (*piVar1 == 0) goto LAB_00463b94;
                        unaff_s8 = unaff_s8 + 4;
                        local_138 = *piVar1;
                      }
                      else {
                        iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-CAfile");
                        if (iVar8 == 0) {
                          piVar1 = (int *)(unaff_s8 + 4);
                          if (*piVar1 == 0) goto LAB_00463b94;
                          unaff_s8 = unaff_s8 + 4;
                          local_134 = *piVar1;
                        }
                        else {
                          iVar8 = (*(code *)PTR_strcmp_006aac20)(unaff_s5,"-engine");
                          if ((iVar8 != 0) || (piVar1 = (int *)(unaff_s8 + 4), *piVar1 == 0))
                          goto LAB_00463b94;
                          unaff_s8 = unaff_s8 + 4;
                          local_17c = *piVar1;
                        }
                      }
                    }
                  }
                }
              }
            }
            goto LAB_00463b98;
          }
          iVar8 = *(int *)(unaff_s8 + 4);
          if (iVar8 != 0) {
            if (unaff_s7 == 0) {
              unaff_s7 = (*(code *)PTR_sk_new_null_006a80a4)();
              iVar8 = *(int *)(unaff_s8 + 4);
            }
            (*(code *)PTR_sk_push_006a80a8)(unaff_s7,iVar8);
            unaff_s8 = unaff_s8 + 4;
            goto LAB_00463b98;
          }
          goto LAB_00463b94;
        }
        uVar5 = *(undefined4 *)(unaff_s8 + 4);
        puVar9 = &local_128;
      }
      unaff_s8 = unaff_s8 + 4;
      iVar8 = set_pbe_isra_0(puVar9,uVar5);
      if (iVar8 == 0) {
        unaff_s2 = (undefined *)0x1;
      }
      goto LAB_00463b98;
    }
    uVar5 = (*(code *)PTR_EVP_des_cbc_006a83a4)();
    *puVar11 = uVar5;
  } while( true );
}

