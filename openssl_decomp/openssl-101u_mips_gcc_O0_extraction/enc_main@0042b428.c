
undefined4 enc_main(int param_1,undefined4 *param_2)

{
  char cVar1;
  byte bVar2;
  undefined uVar3;
  char cVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  undefined *puVar12;
  undefined *puVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  undefined *puVar22;
  int iVar23;
  undefined *puVar24;
  char *pcVar25;
  char **ppcVar26;
  undefined *puVar27;
  char *pcVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  code *pcVar32;
  char *local_1ac;
  int local_1a8;
  char *local_1a4;
  uint local_1a0;
  char *local_19c;
  int local_198;
  byte *local_194;
  char *local_190;
  undefined1 *local_18c;
  int local_17c;
  char *local_174;
  char *local_170;
  char *local_168;
  int local_150;
  int local_14c;
  char *local_144;
  undefined4 local_140;
  undefined auStack_13c [8];
  undefined auStack_134 [8];
  undefined auStack_12c [16];
  char local_11c;
  char local_11b;
  char local_11a;
  char local_119;
  undefined auStack_f4 [200];
  int local_2c;
  
  puVar13 = PTR___stack_chk_guard_006a9ae8;
  puVar12 = PTR_bio_err_006a6e3c;
  local_144 = (char *)0x0;
  local_140 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iVar23 = *(int *)puVar12;
  if (iVar23 == 0) {
    uVar29 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar23 = (*(code *)PTR_BIO_new_006a6ea4)(uVar29);
    *(int *)puVar12 = iVar23;
    if (iVar23 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar23,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
      iVar23 = *(int *)puVar12;
    }
  }
  iVar23 = (*(code *)PTR_load_config_006a6e64)(iVar23,0);
  if (iVar23 == 0) goto LAB_0042b4b4;
  (*(code *)PTR_program_name_006a7410)(*param_2,&local_11c,0x28);
  iVar23 = (*(code *)PTR_strcmp_006a9b18)(&local_11c,"base64");
  if (iVar23 == 0) {
    local_198 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(&local_11c);
    bVar5 = true;
  }
  else {
    local_198 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(&local_11c);
    if (local_198 == 0) {
      if (((local_11c != 'e') || (local_11b != 'n')) || (local_11a != 'c')) {
        uVar29 = *(undefined4 *)puVar12;
LAB_0042c07c:
        (*(code *)PTR_BIO_printf_006a6e38)(uVar29,"%s is an unknown cipher\n",&local_11c);
        local_14c = 0x630000;
        local_150 = 0x630000;
        goto LAB_0042b95c;
      }
      bVar5 = false;
      if (local_119 != '\0') {
        uVar29 = *(undefined4 *)puVar12;
        goto LAB_0042c07c;
      }
    }
    else {
      bVar5 = false;
    }
  }
  param_1 = param_1 + -1;
  ppcVar26 = (char **)(param_2 + 1);
  if (param_1 < 1) {
    bVar9 = false;
    pcVar28 = (char *)0x0;
    local_19c = (char *)0x0;
    iVar23 = 1;
    local_1ac = (char *)0x0;
    local_194 = (byte *)0x0;
    bVar8 = false;
    bVar11 = false;
    bVar7 = false;
    local_17c = 0;
    local_190 = (char *)0x0;
    local_168 = (char *)0x0;
    local_170 = (char *)0x0;
    local_174 = (char *)0x0;
    local_1a4 = (char *)0x0;
    local_18c = (char *)0x0;
    bVar10 = false;
    bVar6 = false;
  }
  else {
    bVar9 = false;
    local_19c = (char *)0x0;
    local_1ac = (char *)0x0;
    bVar8 = false;
    bVar11 = false;
    bVar7 = false;
    iVar23 = 1;
    local_17c = 0;
    pcVar28 = (char *)0x0;
    local_190 = (char *)0x0;
    local_168 = (char *)0x0;
    local_170 = (char *)0x0;
    local_174 = (char *)0x0;
    local_1a4 = (char *)0x0;
    local_18c = (char *)0x0;
    bVar10 = false;
    bVar6 = false;
    local_194 = (byte *)0x0;
    do {
      while( true ) {
        pcVar25 = *ppcVar26;
        cVar1 = *pcVar25;
        if (cVar1 == '-') break;
LAB_0042b60c:
        iVar15 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,&DAT_00632514);
        if (iVar15 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) {
LAB_0042b950:
            local_14c = 0x630000;
            local_150 = 0x630000;
            goto LAB_0042b95c;
          }
          local_1ac = ppcVar26[1];
          ppcVar26 = ppcVar26 + 1;
        }
        else {
          iVar15 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-pass");
          if (iVar15 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0042b950;
            local_1a4 = ppcVar26[1];
            ppcVar26 = ppcVar26 + 1;
          }
          else {
            iVar15 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-engine");
            if (iVar15 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0042b950;
              local_19c = ppcVar26[1];
              ppcVar26 = ppcVar26 + 1;
            }
            else {
              if (cVar1 == '-') {
                cVar4 = pcVar25[1];
                if (cVar4 != 'd') {
                  if (cVar4 == 'p') {
                    if (pcVar25[2] != '\0') goto LAB_0042b864;
                    local_17c = 1;
                  }
                  else {
                    if ((cVar4 != 'v') || (pcVar25[2] != '\0')) goto LAB_0042b864;
                    bVar6 = true;
                  }
                  goto LAB_0042b634;
                }
                if (pcVar25[2] == '\0') {
                  iVar23 = 0;
                  goto LAB_0042b634;
                }
              }
LAB_0042b864:
              local_14c = 0x630000;
              iVar15 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-nopad");
              if (iVar15 == 0) {
                bVar10 = true;
              }
              else {
                iVar15 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-salt");
                if (iVar15 == 0) {
                  bVar8 = false;
                }
                else {
                  iVar15 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-nosalt");
                  if (iVar15 == 0) {
                    bVar8 = true;
                  }
                  else {
                    iVar15 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-debug");
                    if (iVar15 == 0) {
                      bVar7 = true;
                    }
                    else {
                      if (cVar1 == '-') {
                        cVar4 = pcVar25[1];
                        if (cVar4 == 'P') {
                          if (pcVar25[2] == '\0') {
                            local_17c = 2;
                            goto LAB_0042b634;
                          }
                          goto LAB_0042b8e4;
                        }
                        if (cVar4 == 'A') {
                          if (pcVar25[2] == '\0') {
                            bVar11 = true;
                            goto LAB_0042b634;
                          }
                          goto LAB_0042b8e4;
                        }
                        if ((cVar4 != 'a') || (pcVar25[2] != '\0')) goto LAB_0042b8e4;
                      }
                      else {
LAB_0042b8e4:
                        iVar15 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-base64");
                        if (iVar15 != 0) {
                          iVar15 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-bufsize");
                          if (iVar15 == 0) {
                            param_1 = param_1 + -1;
                            local_150 = 0x630000;
                            if (param_1 == 0) goto LAB_0042b95c;
                            local_194 = (byte *)ppcVar26[1];
                            ppcVar26 = ppcVar26 + 1;
                          }
                          else if (cVar1 == '-') {
                            cVar4 = pcVar25[1];
                            if ((cVar4 == 'k') && (local_150 = 0x630000, pcVar25[2] == '\0')) {
                              param_1 = param_1 + -1;
                              if (param_1 == 0) goto LAB_0042b95c;
                              local_18c = ppcVar26[1];
                              ppcVar26 = ppcVar26 + 1;
                            }
                            else {
                              local_150 = 0x630000;
                              iVar15 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-kfile");
                              if (iVar15 == 0) goto LAB_0042cc54;
                              if (cVar4 == 'K') {
                                if (pcVar25[2] == '\0') {
                                  param_1 = param_1 + -1;
                                  if (param_1 == 0) goto LAB_0042b95c;
                                  local_174 = ppcVar26[1];
                                  ppcVar26 = ppcVar26 + 1;
                                }
                                else {
LAB_0042ce70:
                                  if (cVar4 == 'i') {
                                    if ((pcVar25[2] == 'v') && (pcVar25[3] == '\0')) {
                                      param_1 = param_1 + -1;
                                      if (param_1 == 0) goto LAB_0042b95c;
                                      local_170 = ppcVar26[1];
                                      ppcVar26 = ppcVar26 + 1;
                                    }
                                    else {
LAB_0042cd24:
                                      local_150 = 0x630000;
                                      iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                         (pcVar25,"-non-fips-allow");
                                      if (iVar15 == 0) {
                                        bVar9 = true;
                                      }
                                      else {
                                        if (cVar1 == '-') {
                                          local_198 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)
                                                                (pcVar25 + 1);
                                          if (local_198 != 0) goto LAB_0042b634;
                                          pcVar25 = *ppcVar26;
                                        }
                                        iVar15 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-none");
                                        if (iVar15 != 0) {
                                          (*(code *)PTR_BIO_printf_006a6e38)
                                                    (*(undefined4 *)puVar12,
                                                     "unknown option \'%s\'\n",pcVar25);
                                          goto LAB_0042b95c;
                                        }
                                        local_198 = 0;
                                      }
                                    }
                                  }
                                  else {
                                    if (((cVar4 != 'm') || (pcVar25[2] != 'd')) ||
                                       (pcVar25[3] != '\0')) goto LAB_0042cd24;
                                    param_1 = param_1 + -1;
                                    if (param_1 == 0) goto LAB_0042b95c;
                                    local_190 = ppcVar26[1];
                                    ppcVar26 = ppcVar26 + 1;
                                  }
                                }
                              }
                              else {
                                if (cVar4 != 'S') goto LAB_0042ce70;
                                if (pcVar25[2] != '\0') goto LAB_0042cd24;
                                param_1 = param_1 + -1;
                                if (param_1 == 0) goto LAB_0042b95c;
                                local_168 = ppcVar26[1];
                                ppcVar26 = ppcVar26 + 1;
                              }
                            }
                          }
                          else {
                            iVar15 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-kfile");
                            if (iVar15 != 0) goto LAB_0042cd24;
LAB_0042cc54:
                            local_150 = 0x630000;
                            param_1 = param_1 + -1;
                            if (param_1 == 0) goto LAB_0042b95c;
                            pcVar25 = ppcVar26[1];
                            ppcVar26 = ppcVar26 + 1;
                            iVar15 = (*(code *)PTR_fopen_006a9b00)(pcVar25,"r");
                            if (iVar15 == 0) {
LAB_0042cdb8:
                              (*(code *)PTR_BIO_printf_006a6e38)
                                        (*(undefined4 *)puVar12,"unable to read key from \'%s\'\n",
                                         pcVar25);
                              goto LAB_0042b95c;
                            }
                            buf_16496[0] = 0;
                            iVar17 = (*(code *)PTR_fgets_006a9ae0)(buf_16496,0x80,iVar15);
                            if (iVar17 == 0) goto LAB_0042cdb8;
                            (*(code *)PTR_fclose_006a9998)(iVar15);
                            iVar15 = (*(code *)PTR_strlen_006a9a24)(buf_16496);
                            if (iVar15 < 1) {
LAB_0042ce0c:
                              (*(code *)PTR_BIO_printf_006a6e38)
                                        (*(undefined4 *)puVar12,"zero length password\n");
                              goto LAB_0042b95c;
                            }
                            cVar1 = *(char *)((int)&n_16255 + iVar15 + 3);
                            if ((cVar1 == '\n') || (cVar1 == '\r')) {
                              *(undefined *)((int)&n_16255 + iVar15 + 3) = 0;
                              if (iVar15 == 1) goto LAB_0042ce0c;
                              cVar1 = *(char *)((int)&n_16255 + iVar15 + 2);
                              if ((cVar1 == '\n') || (cVar1 == '\r')) {
                                *(undefined *)((int)&n_16255 + iVar15 + 2) = 0;
                                if (iVar15 == 2) goto LAB_0042ce0c;
                                local_18c = buf_16496;
                                goto LAB_0042b634;
                              }
                            }
                            local_18c = buf_16496;
                          }
                          goto LAB_0042b634;
                        }
                      }
                      bVar5 = true;
                    }
                  }
                }
              }
            }
          }
        }
LAB_0042b634:
        param_1 = param_1 + -1;
        ppcVar26 = ppcVar26 + 1;
        if (param_1 == 0) goto LAB_0042b68c;
      }
      if (pcVar25[1] != 'e') {
        if (((pcVar25[1] != 'i') || (pcVar25[2] != 'n')) || (pcVar25[3] != '\0')) goto LAB_0042b60c;
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_0042b950;
        pcVar28 = ppcVar26[1];
        ppcVar26 = ppcVar26 + 1;
        goto LAB_0042b634;
      }
      if (pcVar25[2] != '\0') goto LAB_0042b60c;
      param_1 = param_1 + -1;
      iVar23 = 1;
      ppcVar26 = ppcVar26 + 1;
    } while (param_1 != 0);
  }
LAB_0042b68c:
  puVar24 = PTR_bio_err_006a6e3c;
  (*(code *)PTR_setup_engine_006a6ec4)(*(undefined4 *)puVar12,local_19c,0);
  if (local_198 != 0) {
    iVar15 = (*(code *)PTR_EVP_CIPHER_flags_006a7544)(local_198);
    if (iVar15 << 10 < 0) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar24,"AEAD ciphers not supported by the enc utility\n");
      goto LAB_0042b4b4;
    }
    uVar16 = (*(code *)PTR_EVP_CIPHER_flags_006a7544)(local_198);
    if ((uVar16 & 0xf0007) == 0x10001) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar24,"Ciphers in XTS mode are not supported by the enc utility\n"
                );
      goto LAB_0042b4b4;
    }
  }
  if (local_190 == (char *)0x0) {
    local_1a8 = (*(code *)PTR_EVP_md5_006a70c8)();
  }
  else {
    local_1a8 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(local_190);
    if (local_1a8 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar12,"%s is an unsupported message digest type\n",local_190);
      goto LAB_0042b4b4;
    }
  }
  if (local_194 == (byte *)0x0) {
    iVar15 = 0x2c52;
    local_1a0 = 0x2000;
  }
  else {
    local_1a0 = 0;
    bVar2 = *local_194;
    while (uVar16 = (uint)bVar2, uVar16 != 0) {
      if (uVar16 - 0x30 < 10) {
        local_1a0 = (local_1a0 * 10 + uVar16) - 0x30;
      }
      else if (uVar16 == 0x6b) {
        if (local_194[1] != 0) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar12,"invalid \'bufsize\' specified.\n");
          goto LAB_0042b4b4;
        }
        local_1a0 = local_1a0 << 10;
        local_194 = local_194 + 1;
        break;
      }
      local_194 = local_194 + 1;
      bVar2 = *local_194;
    }
    if ((bVar5) && (local_1a0 < 0x50)) {
      iVar15 = 0xc0;
      local_1a0 = 0x50;
    }
    else {
      iVar15 = (((int)(local_1a0 + 2) / 3) * 2 + (int)local_1a0 / 0x30 + 0x29) * 2;
    }
    if (bVar6) {
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"bufsize=%d\n",local_1a0);
    }
  }
  pcVar25 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x200,"enc.c",0x179);
  iVar17 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar15,"enc.c",0x17a);
  if (iVar17 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"OPENSSL_malloc failure %ld\n",iVar15)
    ;
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar12);
    if (pcVar25 == (char *)0x0) goto LAB_0042b4c4;
    local_1ac = (char *)0x0;
    iVar19 = 0;
    iVar18 = 0;
    iVar15 = 0;
    uVar29 = 1;
LAB_0042bde8:
    (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar25);
    if (iVar17 == 0) goto LAB_0042be0c;
  }
  else {
    if (pcVar25 != (char *)0x0) {
      uVar29 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      iVar15 = (*(code *)PTR_BIO_new_006a6ea4)(uVar29);
      uVar29 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      iVar18 = (*(code *)PTR_BIO_new_006a6ea4)(uVar29);
      if ((iVar15 == 0) || (iVar18 == 0)) {
        pcVar28 = *(char **)puVar12;
        pcVar32 = (code *)PTR_ERR_print_errors_006a6e40;
LAB_0042c0c4:
        (*pcVar32)(pcVar28);
LAB_0042c0d0:
        local_1ac = (char *)0x0;
        iVar19 = 0;
LAB_0042c0d8:
        uVar29 = 1;
      }
      else {
        if (bVar7) {
          (*(code *)PTR_BIO_set_callback_006a74dc)(iVar15,PTR_BIO_debug_callback_006a74e0);
          (*(code *)PTR_BIO_set_callback_006a74dc)(iVar18,PTR_BIO_debug_callback_006a74e0);
          (*(code *)PTR_BIO_set_callback_arg_006a74e4)(iVar15,*(undefined4 *)puVar12);
          (*(code *)PTR_BIO_set_callback_arg_006a74e4)(iVar18,*(undefined4 *)puVar12);
          if (pcVar28 == (char *)0x0) goto LAB_0042bf10;
LAB_0042bcd8:
          iVar19 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar15,0x6c,3,pcVar28);
          pcVar32 = (code *)PTR_perror_006a9a80;
          if (iVar19 < 1) goto LAB_0042c0c4;
        }
        else {
          if (pcVar28 != (char *)0x0) goto LAB_0042bcd8;
LAB_0042bf10:
          puVar24 = PTR_stdin_006a9a14;
          if (local_194 != (byte *)0x0) {
            (*(code *)PTR_setvbuf_006a9a00)(*(undefined4 *)PTR_stdin_006a9a14,0,2,0);
          }
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar15,0x6a,0,*(undefined4 *)puVar24);
        }
        pcVar28 = local_18c;
        if (local_18c == (char *)0x0) {
          if (local_1a4 == (char *)0x0) {
LAB_0042c684:
            pcVar28 = local_18c;
            if ((local_198 == 0) || (local_174 != (char *)0x0)) goto LAB_0042bd08;
            pcVar28 = "encryption";
            if (iVar23 == 0) {
              pcVar28 = "decryption";
            }
            do {
              uVar29 = (*(code *)PTR_EVP_CIPHER_nid_006a73d0)(local_198);
              uVar29 = (*(code *)PTR_OBJ_nid2ln_006a711c)(uVar29);
              (*(code *)PTR_BIO_snprintf_006a6f60)
                        (auStack_f4,200,"enter %s %s password:",uVar29,pcVar28);
              puVar24 = PTR_EVP_read_pw_string_006a7278;
              *pcVar25 = '\0';
              iVar19 = (*(code *)puVar24)(pcVar25,0x200,auStack_f4,iVar23);
              if (iVar19 == 0) {
                pcVar28 = pcVar25;
                if (*pcVar25 != '\0') goto LAB_0042bd08;
                goto LAB_0042c0d0;
              }
            } while (-1 < iVar19);
            uVar29 = *(undefined4 *)puVar12;
            pcVar28 = "bad password read\n";
          }
          else {
            iVar19 = (*(code *)PTR_app_passwd_006a6e54)
                               (*(undefined4 *)puVar12,local_1a4,0,&local_144,0);
            if (iVar19 != 0) {
              pcVar28 = local_144;
              if (local_144 != (char *)0x0) goto LAB_0042bd08;
              goto LAB_0042c684;
            }
            pcVar28 = "Error getting password\n";
            uVar29 = *(undefined4 *)PTR_bio_err_006a6e3c;
          }
          local_1ac = (char *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)(uVar29,pcVar28);
          iVar19 = 0;
          goto LAB_0042c0d8;
        }
LAB_0042bd08:
        local_18c = pcVar28;
        puVar24 = PTR_stdout_006a99c8;
        if (local_1ac == (char *)0x0) {
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar18,0x6a,0,*(undefined4 *)PTR_stdout_006a99c8);
          if (local_194 != (byte *)0x0) {
            (*(code *)PTR_setvbuf_006a9a00)(*(undefined4 *)puVar24,0,2,0);
          }
        }
        else {
          iVar19 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar18,0x6c,5,local_1ac);
          pcVar28 = local_1ac;
          pcVar32 = (code *)PTR_perror_006a9a80;
          if (iVar19 < 1) goto LAB_0042c0c4;
        }
        iVar21 = iVar18;
        local_1ac = (char *)iVar15;
        if (bVar5) {
          uVar29 = (*(code *)PTR_BIO_f_base64_006a74bc)();
          iVar19 = (*(code *)PTR_BIO_new_006a6ea4)(uVar29);
          if (iVar19 != 0) {
            if (bVar7) {
              (*(code *)PTR_BIO_set_callback_006a74dc)(iVar19,PTR_BIO_debug_callback_006a74e0);
              (*(code *)PTR_BIO_set_callback_arg_006a74e4)(iVar19,*(undefined4 *)puVar12);
            }
            if (bVar11) {
              (*(code *)PTR_BIO_set_flags_006a7570)(iVar19,0x100);
            }
            if (iVar23 == 0) {
              local_1ac = (char *)(*(code *)PTR_BIO_push_006a74c4)(iVar19,iVar15);
            }
            else {
              iVar21 = (*(code *)PTR_BIO_push_006a74c4)(iVar19,iVar18);
            }
            goto LAB_0042bd40;
          }
LAB_0042c9b8:
          local_1ac = (char *)0x0;
          uVar29 = 1;
        }
        else {
          iVar19 = 0;
LAB_0042bd40:
          iVar14 = (int)local_1ac;
          if (local_198 == 0) {
            local_1ac = (char *)0x0;
LAB_0042c458:
            do {
              iVar23 = (*(code *)PTR_BIO_read_006a74c0)(iVar14,iVar17,local_1a0);
              if (iVar23 < 1) {
                iVar23 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar21,0xb,0,0);
                if (iVar23 == 0) {
                  uVar29 = 1;
                  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"bad decrypt\n");
                }
                else {
                  if (!bVar6) goto LAB_0042c4ac;
                  uVar30 = *(undefined4 *)puVar12;
                  uVar29 = (*(code *)PTR_BIO_number_read_006a7568)(iVar15);
                  (*(code *)PTR_BIO_printf_006a6e38)(uVar30,"bytes read   :%8ld\n",uVar29);
                  uVar31 = *(undefined4 *)puVar12;
                  uVar30 = (*(code *)PTR_BIO_number_written_006a756c)(iVar18);
                  uVar29 = 0;
                  (*(code *)PTR_BIO_printf_006a6e38)(uVar31,"bytes written:%8ld\n",uVar30);
                }
                goto LAB_0042bdd4;
              }
              iVar20 = (*(code *)PTR_BIO_write_006a6e14)(iVar21,iVar17,iVar23);
            } while (iVar23 == iVar20);
            uVar29 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"error writing output file\n")
            ;
          }
          else {
            if (local_18c == (char *)0x0) {
              if (local_170 != (char *)0x0) goto LAB_0042c170;
              iVar20 = (*(code *)PTR_EVP_CIPHER_iv_length_006a7550)(local_198);
              if (iVar20 != 0) {
                local_1ac = (char *)0x0;
                uVar29 = 1;
                (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"iv undefined\n");
                goto LAB_0042bdd4;
              }
            }
            else {
              if (bVar8) {
                puVar24 = (undefined *)0x0;
              }
              else {
                if (iVar23 == 0) {
                  iVar20 = (*(code *)PTR_BIO_read_006a74c0)(local_1ac,auStack_13c,8);
                  if (iVar20 == 8) {
                    puVar24 = auStack_134;
                    iVar20 = (*(code *)PTR_BIO_read_006a74c0)(local_1ac,puVar24,8);
                    if (iVar20 == 8) {
                      iVar20 = (*(code *)PTR_memcmp_006a9ad0)(auStack_13c,"Salted__",8);
                      if (iVar20 != 0) {
                        local_1ac = (char *)0x0;
                        uVar29 = 1;
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar12,"bad magic number\n");
                        goto LAB_0042bdd4;
                      }
                      goto LAB_0042c0e8;
                    }
                  }
                  local_1ac = (char *)0x0;
                  uVar29 = 1;
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar12,"error reading input file\n");
                  goto LAB_0042bdd4;
                }
                puVar24 = auStack_134;
                if (local_168 == (char *)0x0) {
                  iVar20 = (*(code *)PTR_RAND_bytes_006a7574)(puVar24,8);
                  if (iVar20 < 1) goto LAB_0042c9b8;
                }
                else {
                  iVar20 = set_hex(local_168,puVar24,8);
                  if (iVar20 == 0) {
                    local_1ac = (char *)0x0;
                    uVar29 = 1;
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar12,"invalid hex salt value\n");
                    goto LAB_0042bdd4;
                  }
                }
                if ((local_17c != 2) &&
                   ((iVar20 = (*(code *)PTR_BIO_write_006a6e14)(iVar21,"Salted__",8), iVar20 != 8 ||
                    (iVar20 = (*(code *)PTR_BIO_write_006a6e14)(iVar21,puVar24,8), iVar20 != 8)))) {
                  local_1ac = (char *)0x0;
                  uVar29 = 1;
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar12,"error writing output file\n");
                  goto LAB_0042bdd4;
                }
              }
LAB_0042c0e8:
              uVar29 = (*(code *)PTR_strlen_006a9a24)(local_18c);
              (*(code *)PTR_EVP_BytesToKey_006a754c)
                        (local_198,local_1a8,puVar24,local_18c,uVar29,1,auStack_f4,auStack_12c);
              if (local_18c == pcVar25) {
                (*(code *)PTR_OPENSSL_cleanse_006a7074)(pcVar25,0x200);
              }
              else {
                uVar29 = (*(code *)PTR_strlen_006a9a24)(local_18c);
                (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_18c,uVar29);
              }
              if (local_170 != (char *)0x0) {
LAB_0042c170:
                iVar20 = (*(code *)PTR_EVP_CIPHER_iv_length_006a7550)(local_198);
                if (iVar20 == 0) {
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar12,"warning: iv not use by this cipher\n");
                }
                else {
                  iVar20 = set_hex(local_170,auStack_12c,0x10);
                  if (iVar20 == 0) {
                    local_1ac = (char *)0x0;
                    uVar29 = 1;
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar12,"invalid hex iv value\n");
                    goto LAB_0042bdd4;
                  }
                }
              }
            }
            if (local_174 != (char *)0x0) {
              uVar29 = (*(code *)PTR_EVP_CIPHER_key_length_006a7554)(local_198);
              iVar20 = set_hex(local_174,auStack_f4,uVar29);
              if (iVar20 == 0) {
                local_1ac = (char *)0x0;
                uVar29 = 1;
                (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"invalid hex key value\n")
                ;
                goto LAB_0042bdd4;
              }
            }
            uVar29 = (*(code *)PTR_BIO_f_cipher_006a7558)();
            local_1ac = (char *)(*(code *)PTR_BIO_new_006a6ea4)(uVar29);
            if (local_1ac == (char *)0x0) goto LAB_0042c0d8;
            (*(code *)PTR_BIO_ctrl_006a6e18)(local_1ac,0x81,0,&local_140);
            if (bVar9) {
              (*(code *)PTR_EVP_CIPHER_CTX_set_flags_006a755c)(local_140,0x8000);
            }
            iVar20 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)(local_140,local_198,0,0,0,iVar23);
            if (iVar20 != 0) {
              if (bVar10) {
                (*(code *)PTR_EVP_CIPHER_CTX_set_padding_006a7564)(local_140,0);
              }
              puVar24 = auStack_12c;
              puVar27 = auStack_f4;
              iVar23 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)
                                 (local_140,0,0,puVar27,puVar24,iVar23);
              if (iVar23 != 0) {
                if (bVar7) {
                  (*(code *)PTR_BIO_set_callback_006a74dc)
                            (local_1ac,PTR_BIO_debug_callback_006a74e0);
                  (*(code *)PTR_BIO_set_callback_arg_006a74e4)(local_1ac,*(undefined4 *)puVar12);
                }
                if (local_17c != 0) {
                  puVar22 = auStack_134;
                  if (!bVar8) {
                    (*(code *)PTR___printf_chk_006a99c4)(1,"salt=");
                    do {
                      uVar3 = *puVar22;
                      puVar22 = puVar22 + 1;
                      (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_00634b80,uVar3);
                    } while (puVar24 != puVar22);
                    (*(code *)PTR_putchar_006a99ec)(10);
                  }
                  if (0 < *(int *)(local_198 + 8)) {
                    (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_00634b88);
                    if (0 < *(int *)(local_198 + 8)) {
                      iVar23 = 0;
                      do {
                        uVar3 = *puVar27;
                        iVar23 = iVar23 + 1;
                        puVar27 = puVar27 + 1;
                        (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_00634b80,uVar3);
                      } while (iVar23 < *(int *)(local_198 + 8));
                    }
                    (*(code *)PTR_putchar_006a99ec)(10);
                  }
                  if (0 < *(int *)(local_198 + 0xc)) {
                    (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_00634b90);
                    if (0 < *(int *)(local_198 + 0xc)) {
                      iVar23 = 0;
                      do {
                        uVar3 = *puVar24;
                        iVar23 = iVar23 + 1;
                        puVar24 = puVar24 + 1;
                        (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_00634b80,uVar3);
                      } while (iVar23 < *(int *)(local_198 + 0xc));
                    }
                    (*(code *)PTR_putchar_006a99ec)(10);
                  }
                  if (local_17c == 2) {
LAB_0042c4ac:
                    uVar29 = 0;
                    goto LAB_0042bdd4;
                  }
                }
                iVar21 = (*(code *)PTR_BIO_push_006a74c4)(local_1ac,iVar21);
                goto LAB_0042c458;
              }
            }
            uVar31 = *(undefined4 *)puVar12;
            uVar29 = (*(code *)PTR_EVP_CIPHER_nid_006a73d0)(local_198);
            uVar30 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar29);
            uVar29 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)(uVar31,"Error setting cipher %s\n",uVar30);
            (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar12);
          }
        }
      }
LAB_0042bdd4:
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar12);
      goto LAB_0042bde8;
    }
    uVar29 = 1;
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"OPENSSL_malloc failure %ld\n",iVar15)
    ;
    iVar15 = 0;
    iVar19 = 0;
    iVar18 = 0;
    local_1ac = (char *)0x0;
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar12);
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar17);
LAB_0042be0c:
  if (iVar15 != 0) {
    (*(code *)PTR_BIO_free_006a6e70)(iVar15);
  }
  if (iVar18 != 0) {
    (*(code *)PTR_BIO_free_all_006a6e74)(iVar18);
  }
  if (local_1ac != (char *)0x0) {
    (*(code *)PTR_BIO_free_006a6e70)(local_1ac);
  }
  if (iVar19 != 0) {
    (*(code *)PTR_BIO_free_006a6e70)(iVar19);
  }
  while( true ) {
    if (local_144 != (char *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (local_2c == *(int *)puVar13) break;
    local_150 = (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0042b95c:
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"options are\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"%-14s input file\n","-in <file>");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"%-14s output file\n","-out <file>");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar12,"%-14s pass phrase source\n","-pass <arg>");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"%-14s encrypt\n",&DAT_006346f8);
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"%-14s decrypt\n",&DAT_0063470c);
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar12,"%-14s base64 encode/decode, depending on encryption flag\n",
               "-a/-base64");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar12,"%-14s passphrase is the next argument\n",&DAT_00634768);
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar12,"%-14s passphrase is the first line of the file argument\n",
               local_150 + 0x4668);
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar12,"%-14s the next argument is the md to use to create a key\n",
               &DAT_006347d0);
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar12,"%-14s   from a passphrase.  One of md2, md5, sha or sha1\n",
               "");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar12,"%-14s salt in hex is the next argument\n",&DAT_0063484c);
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar12,"%-14s key/iv in hex is the next argument\n",&DAT_00634878);
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar12,"%-14s print the iv/key (then exit if -P)\n","-[pP]");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"%-14s buffer size\n","-bufsize <n>");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar12,"%-14s disable standard block padding\n",local_14c + 0x4634);
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar12,"%-14s use engine e, possibly a hardware device.\n",
               "-engine e");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"Cipher Types\n");
    (*(code *)PTR_OBJ_NAME_do_all_sorted_006a7548)(2,show_ciphers,*(undefined4 *)puVar12);
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"\n");
LAB_0042b4b4:
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar12);
LAB_0042b4c4:
    uVar29 = 1;
  }
  return uVar29;
}

