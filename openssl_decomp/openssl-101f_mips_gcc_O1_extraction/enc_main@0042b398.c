
int enc_main(byte *param_1,byte **param_2)

{
  byte **ppbVar1;
  byte bVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined4 uVar7;
  byte *pbVar8;
  byte *pbVar9;
  int iVar10;
  uint uVar11;
  byte *pbVar12;
  int iVar13;
  char *pcVar14;
  byte *unaff_s2;
  byte *unaff_s3;
  byte *unaff_s4;
  undefined4 uVar15;
  byte *unaff_s7;
  code *pcVar16;
  byte *local_1b0;
  byte *local_1ac;
  char *local_1a8;
  byte *local_1a4;
  uint local_1a0;
  byte *local_19c;
  byte *local_198;
  byte *local_194;
  byte *local_190;
  byte *local_18c;
  int local_188;
  int local_184;
  int local_180;
  int local_17c;
  int local_178;
  byte *local_174;
  byte *local_170;
  undefined1 *local_16c;
  byte *local_168;
  int local_164;
  int local_160;
  int local_15c;
  undefined1 *local_158;
  undefined1 *local_154;
  int local_150;
  byte *local_144;
  undefined4 local_140;
  byte abStack_13c [8];
  byte abStack_134 [8];
  byte abStack_12c [16];
  byte local_11c;
  char local_11b;
  char local_11a;
  char local_119;
  byte abStack_f4 [200];
  int local_2c;
  
  puVar6 = PTR___stack_chk_guard_006aabf0;
  puVar4 = PTR_bio_err_006a7f3c;
  local_144 = (byte *)0x0;
  local_140 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar13 = *(int *)puVar4;
  if (iVar13 == 0) {
    uVar7 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar13 = (*(code *)PTR_BIO_new_006a7fa4)(uVar7);
    *(int *)puVar4 = iVar13;
    if (iVar13 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar13,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
      iVar13 = *(int *)puVar4;
    }
  }
  iVar13 = (*(code *)PTR_load_config_006a7f64)(iVar13,0);
  if (iVar13 == 0) goto LAB_0042b424;
  unaff_s2 = &local_11c;
  (*(code *)PTR_program_name_006a8510)(*param_2,unaff_s2,0x28);
  iVar13 = (*(code *)PTR_strcmp_006aac20)(unaff_s2,"base64");
  if (iVar13 == 0) {
    local_18c = (byte *)(*(code *)PTR_EVP_get_cipherbyname_006a8494)(unaff_s2);
    local_188 = 1;
  }
  else {
    local_18c = (byte *)(*(code *)PTR_EVP_get_cipherbyname_006a8494)(unaff_s2);
    if (local_18c == (byte *)0x0) {
      if (((local_11c == 0x65) && (local_11b == 'n')) && (local_11a == 'c')) {
        local_188 = 0;
        if (local_119 == '\0') goto LAB_0042b4e4;
        uVar7 = *(undefined4 *)puVar4;
      }
      else {
        uVar7 = *(undefined4 *)puVar4;
      }
      (*(code *)PTR_BIO_printf_006a7f38)(uVar7,"%s is an unknown cipher\n",unaff_s2);
      local_150 = 0x630000;
      goto LAB_0042bb2c;
    }
    local_188 = 0;
  }
LAB_0042b4e4:
  unaff_s3 = param_1 + -1;
  param_2 = param_2 + 1;
  if ((int)unaff_s3 < 1) {
    local_15c = 0;
    local_19c = (byte *)0x0;
    unaff_s7 = (byte *)0x1;
    local_1ac = (byte *)0x0;
    param_1 = (byte *)0x0;
    local_178 = 0;
    local_160 = 0;
    local_180 = 0;
    local_17c = 0;
    local_198 = (byte *)0x0;
    local_168 = (byte *)0x0;
    local_170 = (byte *)0x0;
    local_174 = (byte *)0x0;
    local_1a4 = (byte *)0x0;
    local_194 = (byte *)0x0;
    local_164 = 0;
    local_184 = 0;
    pbVar9 = (byte *)0x0;
    goto LAB_0042b600;
  }
  local_15c = 0;
  local_19c = (byte *)0x0;
  local_1ac = (byte *)0x0;
  local_154 = &_ITM_registerTMCloneTable;
  local_178 = 0;
  local_160 = 0;
  local_158 = buf_16486;
  local_180 = 0;
  unaff_s7 = (byte *)0x1;
  local_17c = 0;
  unaff_s2 = (byte *)0x0;
  local_1b0 = &DAT_00632edc;
  local_198 = (byte *)0x0;
  local_168 = (byte *)0x0;
  local_170 = (byte *)0x0;
  local_174 = (byte *)0x0;
  local_1a8 = "-pass";
  local_1a4 = (byte *)0x0;
  local_194 = (byte *)0x0;
  local_164 = 0;
  local_184 = 0;
  local_1a0 = 0x630000;
  local_16c = buf_16486;
  local_190 = (byte *)0x0;
  do {
    unaff_s4 = *param_2;
    param_1 = (byte *)(uint)*unaff_s4;
    iVar13 = 0x2d - (int)param_1;
    pbVar9 = local_194;
    if (iVar13 == 0) {
      if (unaff_s4[1] == 0x65) {
        if (unaff_s4[2] != 0) goto LAB_0042b580;
        unaff_s7 = (byte *)0x1;
        pbVar8 = local_190;
      }
      else {
        if (((unaff_s4[1] != 0x69) || (unaff_s4[2] != 0x6e)) || (unaff_s4[3] != 0))
        goto LAB_0042b580;
        if (unaff_s3 + -1 == (byte *)0x0) {
LAB_0042bb20:
          unaff_s3 = unaff_s3 + -1;
          local_150 = 0x630000;
          goto LAB_0042bb2c;
        }
        unaff_s2 = param_2[1];
        param_2 = param_2 + 1;
        pbVar8 = local_190;
        unaff_s3 = unaff_s3 + -1;
      }
    }
    else {
LAB_0042b580:
      iVar10 = (*(code *)PTR_strcmp_006aac20)(unaff_s4,local_1b0);
      if (iVar10 == 0) {
        if (unaff_s3 + -1 == (byte *)0x0) goto LAB_0042bb20;
        local_1ac = param_2[1];
        param_2 = param_2 + 1;
        pbVar8 = local_190;
        unaff_s3 = unaff_s3 + -1;
      }
      else {
        iVar10 = (*(code *)PTR_strcmp_006aac20)(unaff_s4,local_1a8);
        if (iVar10 == 0) {
          if (unaff_s3 + -1 == (byte *)0x0) goto LAB_0042bb20;
          local_1a4 = param_2[1];
          param_2 = param_2 + 1;
          pbVar8 = local_190;
          unaff_s3 = unaff_s3 + -1;
        }
        else {
          iVar10 = (*(code *)PTR_strcmp_006aac20)(unaff_s4,local_1a0 + 0x2884);
          if (iVar10 == 0) {
            if (unaff_s3 + -1 == (byte *)0x0) goto LAB_0042bb20;
            local_19c = param_2[1];
            param_2 = param_2 + 1;
            pbVar8 = local_190;
            unaff_s3 = unaff_s3 + -1;
          }
          else {
            if (iVar13 == 0) {
              bVar2 = unaff_s4[1];
              if (bVar2 != 100) {
                if (bVar2 == 0x70) {
                  if (unaff_s4[2] != 0) goto LAB_0042b78c;
                  local_17c = 1;
                  pbVar8 = local_190;
                }
                else {
                  if ((bVar2 != 0x76) || (unaff_s4[2] != 0)) goto LAB_0042b78c;
                  local_184 = 1;
                  pbVar8 = local_190;
                }
                goto joined_r0x0042b5f0;
              }
              if (unaff_s4[2] == 0) {
                unaff_s7 = (byte *)0x0;
                pbVar8 = local_190;
                goto joined_r0x0042b5f0;
              }
            }
LAB_0042b78c:
            local_150 = 0x630000;
            iVar10 = (*(code *)PTR_strcmp_006aac20)(unaff_s4,"-nopad");
            if (iVar10 == 0) {
              local_164 = 1;
              pbVar8 = local_190;
            }
            else {
              iVar10 = (*(code *)PTR_strcmp_006aac20)(unaff_s4,"-salt");
              if (iVar10 == 0) {
                local_178 = 0;
                pbVar8 = local_190;
              }
              else {
                iVar10 = (*(code *)PTR_strcmp_006aac20)(unaff_s4,"-nosalt");
                if (iVar10 == 0) {
                  local_178 = 1;
                  pbVar8 = local_190;
                }
                else {
                  iVar10 = (*(code *)PTR_strcmp_006aac20)(unaff_s4,"-debug");
                  if (iVar10 == 0) {
                    local_180 = 1;
                    pbVar8 = local_190;
                  }
                  else {
                    if (iVar13 == 0) {
                      bVar2 = unaff_s4[1];
                      if (bVar2 == 0x50) {
                        if (unaff_s4[2] == 0) {
                          local_17c = 2;
                          pbVar8 = local_190;
                          goto joined_r0x0042b5f0;
                        }
                        goto LAB_0042b80c;
                      }
                      if (bVar2 == 0x41) {
                        if (unaff_s4[2] == 0) {
                          local_160 = 1;
                          pbVar8 = local_190;
                          goto joined_r0x0042b5f0;
                        }
                        goto LAB_0042b80c;
                      }
                      if ((bVar2 != 0x61) || (unaff_s4[2] != 0)) goto LAB_0042b80c;
                    }
                    else {
LAB_0042b80c:
                      iVar10 = (*(code *)PTR_strcmp_006aac20)(unaff_s4,"-base64");
                      if (iVar10 != 0) {
                        iVar10 = (*(code *)PTR_strcmp_006aac20)(unaff_s4,"-bufsize");
                        if (iVar10 != 0) goto LAB_0042cae4;
                        unaff_s3 = unaff_s3 + -1;
                        if (unaff_s3 == (byte *)0x0) goto LAB_0042bb2c;
                        ppbVar1 = param_2 + 1;
                        param_2 = param_2 + 1;
                        pbVar8 = *ppbVar1;
                        goto joined_r0x0042b5f0;
                      }
                    }
                    local_188 = 1;
                    pbVar8 = local_190;
                  }
                }
              }
            }
          }
        }
      }
    }
joined_r0x0042b5f0:
    param_1 = pbVar8;
    local_194 = pbVar9;
    unaff_s3 = unaff_s3 + -1;
    param_2 = param_2 + 1;
    pbVar9 = unaff_s2;
    local_190 = param_1;
    if (unaff_s3 == (byte *)0x0) {
LAB_0042b600:
      (*(code *)PTR_setup_engine_006a7fc4)(*(undefined4 *)puVar4,local_19c,0);
      if (local_198 == (byte *)0x0) {
        local_1a8 = (char *)(*(code *)PTR_EVP_md5_006a81c8)();
      }
      else {
        local_1a8 = (char *)(*(code *)PTR_EVP_get_digestbyname_006a802c)(local_198);
        if ((byte *)local_1a8 == (byte *)0x0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)PTR_bio_err_006a7f3c,
                     "%s is an unsupported message digest type\n",local_198);
          goto LAB_0042b424;
        }
      }
      if (param_1 == (byte *)0x0) {
        unaff_s2 = (byte *)0x2c52;
        local_1a0 = 0x2000;
      }
      else {
        uVar11 = 0;
        bVar2 = *param_1;
        while (uVar3 = (uint)bVar2, uVar3 != 0) {
          if (uVar3 - 0x30 < 10) {
            uVar11 = (uVar11 * 10 + uVar3) - 0x30;
          }
          else if (uVar3 == 0x6b) {
            if (param_1[1] != 0) {
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar4,"invalid \'bufsize\' specified.\n");
              goto LAB_0042b424;
            }
            uVar11 = uVar11 << 10;
            param_1 = param_1 + 1;
            break;
          }
          param_1 = param_1 + 1;
          bVar2 = *param_1;
        }
        if ((local_188 == 0) || (0x4f < uVar11)) {
          unaff_s2 = (byte *)((((int)(uVar11 + 2) / 3) * 2 + (int)uVar11 / 0x30 + 0x29) * 2);
          local_1a0 = uVar11;
        }
        else {
          unaff_s2 = &DAT_000000c0;
          local_1a0 = 0x50;
        }
        if (local_184 != 0) {
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4,"bufsize=%d\n",local_1a0);
        }
      }
      local_1b0 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x200,"enc.c",0x176);
      param_2 = (byte **)(*(code *)PTR_CRYPTO_malloc_006a8108)(unaff_s2,"enc.c",0x177);
      if (param_2 == (byte **)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar4,"OPENSSL_malloc failure %ld\n",unaff_s2);
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar4);
        unaff_s3 = local_1b0;
        if (local_1b0 == (byte *)0x0) goto LAB_0042b434;
        param_1 = (byte *)0x0;
        unaff_s2 = (byte *)0x0;
        unaff_s4 = (byte *)0x0;
        unaff_s3 = (byte *)0x0;
        iVar13 = 1;
LAB_0042baa8:
        (*(code *)PTR_CRYPTO_free_006a7f88)(local_1b0);
        if (param_2 != (byte **)0x0) goto LAB_0042babc;
      }
      else {
        if (local_1b0 != (byte *)0x0) {
          uVar7 = (*(code *)PTR_BIO_s_file_006a7fa0)();
          unaff_s3 = (byte *)(*(code *)PTR_BIO_new_006a7fa4)(uVar7);
          uVar7 = (*(code *)PTR_BIO_s_file_006a7fa0)();
          unaff_s4 = (byte *)(*(code *)PTR_BIO_new_006a7fa4)(uVar7);
          if ((unaff_s3 == (byte *)0x0) || (unaff_s4 == (byte *)0x0)) {
            pbVar9 = *(byte **)puVar4;
            pcVar16 = (code *)PTR_ERR_print_errors_006a7f40;
LAB_0042bfb4:
            (*pcVar16)(pbVar9);
LAB_0042bfc0:
            param_1 = (byte *)0x0;
            unaff_s2 = (byte *)0x0;
LAB_0042bfc8:
            iVar13 = 1;
          }
          else {
            if (local_180 == 0) {
              if (pbVar9 == (byte *)0x0) goto LAB_0042be40;
LAB_0042b998:
              iVar13 = (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s3,0x6c,3,pbVar9);
              pcVar16 = (code *)PTR_perror_006aab88;
              if (iVar13 < 1) goto LAB_0042bfb4;
            }
            else {
              (*(code *)PTR_BIO_set_callback_006a85d8)(unaff_s3,PTR_BIO_debug_callback_006a85dc);
              (*(code *)PTR_BIO_set_callback_006a85d8)(unaff_s4,PTR_BIO_debug_callback_006a85dc);
              (*(code *)PTR_BIO_set_callback_arg_006a85e0)(unaff_s3,*(undefined4 *)puVar4);
              (*(code *)PTR_BIO_set_callback_arg_006a85e0)(unaff_s4,*(undefined4 *)puVar4);
              if (pbVar9 != (byte *)0x0) goto LAB_0042b998;
LAB_0042be40:
              puVar5 = PTR_stdin_006aab20;
              if (param_1 != (byte *)0x0) {
                (*(code *)PTR_setvbuf_006aab0c)(*(undefined4 *)PTR_stdin_006aab20,0,2,0);
              }
              (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s3,0x6a,0,*(undefined4 *)puVar5);
            }
            pbVar9 = local_194;
            if (local_194 == (byte *)0x0) {
              if (local_1a4 == (byte *)0x0) {
LAB_0042c4e8:
                pbVar9 = local_194;
                if ((local_18c == (byte *)0x0) || (local_174 != (byte *)0x0)) goto LAB_0042b9c8;
                pcVar14 = "encryption";
                if (unaff_s7 == (byte *)0x0) {
                  pcVar14 = "decryption";
                }
                local_198 = abStack_f4;
                do {
                  uVar7 = (*(code *)PTR_EVP_CIPHER_nid_006a84d0)(local_18c);
                  uVar7 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar7);
                  (*(code *)PTR_BIO_snprintf_006a8060)
                            (local_198,200,"enter %s %s password:",uVar7,pcVar14);
                  puVar5 = PTR_EVP_read_pw_string_006a8388;
                  *local_1b0 = 0;
                  iVar13 = (*(code *)puVar5)(local_1b0,0x200,local_198,unaff_s7);
                  if (iVar13 == 0) {
                    pbVar9 = local_1b0;
                    if (*local_1b0 == 0) goto LAB_0042bfc0;
                    goto LAB_0042b9c8;
                  }
                } while (-1 < iVar13);
                uVar7 = *(undefined4 *)puVar4;
                pcVar14 = "bad password read\n";
              }
              else {
                iVar13 = (*(code *)PTR_app_passwd_006a7f54)
                                   (*(undefined4 *)puVar4,local_1a4,0,&local_144,0);
                if (iVar13 != 0) {
                  pbVar9 = local_144;
                  if (local_144 != (byte *)0x0) goto LAB_0042b9c8;
                  goto LAB_0042c4e8;
                }
                pcVar14 = "Error getting password\n";
                uVar7 = *(undefined4 *)PTR_bio_err_006a7f3c;
              }
              param_1 = (byte *)0x0;
              (*(code *)PTR_BIO_printf_006a7f38)(uVar7,pcVar14);
              unaff_s2 = (byte *)0x0;
              goto LAB_0042bfc8;
            }
LAB_0042b9c8:
            local_194 = pbVar9;
            puVar5 = PTR_stdout_006aaad4;
            if (local_1ac == (byte *)0x0) {
              (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s4,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
              if (param_1 != (byte *)0x0) {
                (*(code *)PTR_setvbuf_006aab0c)(*(undefined4 *)puVar5,0,2,0);
              }
            }
            else {
              iVar13 = (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s4,0x6c,5,local_1ac);
              pbVar9 = local_1ac;
              pcVar16 = (code *)PTR_perror_006aab88;
              if (iVar13 < 1) goto LAB_0042bfb4;
            }
            pbVar9 = unaff_s4;
            if (local_188 == 0) {
              unaff_s2 = (byte *)0x0;
              local_1a4 = unaff_s3;
LAB_0042ba00:
              if (local_18c == (byte *)0x0) {
                local_1ac = (byte *)0x0;
LAB_0042c34c:
                do {
                  iVar13 = (*(code *)PTR_BIO_read_006a85bc)(local_1a4,param_2,local_1a0);
                  param_1 = local_1ac;
                  unaff_s7 = local_1a4;
                  local_1a8 = (char *)unaff_s2;
                  if (iVar13 < 1) {
                    iVar13 = (*(code *)PTR_BIO_ctrl_006a7f18)(pbVar9,0xb,0,0);
                    if (iVar13 == 0) {
                      iVar13 = 1;
                      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4,"bad decrypt\n");
                    }
                    else {
                      if (local_184 == 0) goto LAB_0042c3a0;
                      uVar15 = *(undefined4 *)puVar4;
                      uVar7 = (*(code *)PTR_BIO_number_read_006a8654)(unaff_s3);
                      (*(code *)PTR_BIO_printf_006a7f38)(uVar15,"bytes read   :%8ld\n",uVar7);
                      uVar15 = *(undefined4 *)puVar4;
                      uVar7 = (*(code *)PTR_BIO_number_written_006a8658)(unaff_s4);
                      iVar13 = 0;
                      (*(code *)PTR_BIO_printf_006a7f38)(uVar15,"bytes written:%8ld\n",uVar7);
                    }
                    goto LAB_0042ba94;
                  }
                  iVar10 = (*(code *)PTR_BIO_write_006a7f14)(pbVar9,param_2,iVar13);
                } while (iVar13 == iVar10);
                iVar13 = 1;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar4,"error writing output file\n");
              }
              else {
                if (local_194 == (byte *)0x0) {
                  local_19c = abStack_12c;
                  if (local_170 != (byte *)0x0) goto LAB_0042c068;
                  iVar13 = (*(code *)PTR_EVP_CIPHER_iv_length_006a865c)(local_18c,local_19c);
                  if (iVar13 != 0) {
                    param_1 = (byte *)0x0;
                    iVar13 = 1;
                    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4,"iv undefined\n");
                    goto LAB_0042ba94;
                  }
                }
                else {
                  if (local_178 == 0) {
                    if (unaff_s7 == (byte *)0x0) {
                      local_1ac = abStack_13c;
                      pbVar8 = (byte *)(*(code *)PTR_BIO_read_006a85bc)(local_1a4,local_1ac,8);
                      if (pbVar8 == &DAT_00000008) {
                        pbVar12 = abStack_134;
                        iVar13 = (*(code *)PTR_BIO_read_006a85bc)(local_1a4,pbVar12,8);
                        local_19c = pbVar8;
                        if (iVar13 == 8) {
                          iVar13 = (*(code *)PTR_memcmp_006aabd8)(local_1ac,"Salted__",8);
                          if (iVar13 != 0) {
                            param_1 = (byte *)0x0;
                            iVar13 = 1;
                            (*(code *)PTR_BIO_printf_006a7f38)
                                      (*(undefined4 *)puVar4,"bad magic number\n");
                            goto LAB_0042ba94;
                          }
                          goto LAB_0042bfd8;
                        }
                      }
                      param_1 = (byte *)0x0;
                      iVar13 = 1;
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar4,"error reading input file\n");
                      goto LAB_0042ba94;
                    }
                    pbVar12 = abStack_134;
                    if (local_168 == (byte *)0x0) {
                      iVar13 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(pbVar12,8);
                      if (iVar13 < 0) goto LAB_0042c8b8;
                    }
                    else {
                      iVar13 = set_hex(local_168,pbVar12,8);
                      if (iVar13 == 0) {
                        param_1 = (byte *)0x0;
                        iVar13 = 1;
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*(undefined4 *)puVar4,"invalid hex salt value\n");
                        goto LAB_0042ba94;
                      }
                    }
                    if ((local_17c != 2) &&
                       ((pbVar8 = (byte *)(*(code *)PTR_BIO_write_006a7f14)(pbVar9,"Salted__",8),
                        pbVar8 != &DAT_00000008 ||
                        (iVar13 = (*(code *)PTR_BIO_write_006a7f14)(pbVar9,pbVar12,8),
                        local_1ac = pbVar8, iVar13 != 8)))) {
                      iVar13 = 1;
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar4,"error writing output file\n");
                      param_1 = (byte *)0x0;
                      goto LAB_0042ba94;
                    }
                  }
                  else {
                    pbVar12 = (byte *)0x0;
                  }
LAB_0042bfd8:
                  uVar7 = (*(code *)PTR_strlen_006aab30)(local_194);
                  (*(code *)PTR_EVP_BytesToKey_006a8644)
                            (local_18c,local_1a8,pbVar12,local_194,uVar7,1,abStack_f4,abStack_12c);
                  if (local_194 == local_1b0) {
                    (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_1b0,0x200);
                  }
                  else {
                    uVar7 = (*(code *)PTR_strlen_006aab30)(local_194);
                    (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_194,uVar7);
                  }
                  if (local_170 != (byte *)0x0) {
LAB_0042c068:
                    local_19c = abStack_12c;
                    iVar13 = set_hex(local_170,local_19c,0x10);
                    if (iVar13 == 0) {
                      param_1 = (byte *)0x0;
                      iVar13 = 1;
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar4,"invalid hex iv value\n");
                      goto LAB_0042ba94;
                    }
                  }
                }
                local_19c = abStack_12c;
                if ((local_174 == (byte *)0x0) ||
                   (iVar13 = set_hex(local_174,abStack_f4,0x40), iVar13 != 0)) {
                  uVar7 = (*(code *)PTR_BIO_f_cipher_006a8648)();
                  param_1 = (byte *)(*(code *)PTR_BIO_new_006a7fa4)(uVar7);
                  if (param_1 == (byte *)0x0) goto LAB_0042bfc8;
                  (*(code *)PTR_BIO_ctrl_006a7f18)(param_1,0x81,0,&local_140);
                  if (local_15c != 0) {
                    (*(code *)PTR_EVP_CIPHER_CTX_set_flags_006a8668)(local_140,0x8000);
                  }
                  iVar13 = (*(code *)PTR_EVP_CipherInit_ex_006a864c)
                                     (local_140,local_18c,0,0,0,unaff_s7);
                  if (iVar13 != 0) {
                    if (local_164 != 0) {
                      (*(code *)PTR_EVP_CIPHER_CTX_set_padding_006a8650)(local_140,0);
                    }
                    local_19c = abStack_12c;
                    pbVar8 = abStack_f4;
                    iVar13 = (*(code *)PTR_EVP_CipherInit_ex_006a864c)
                                       (local_140,0,0,pbVar8,local_19c,unaff_s7);
                    local_198 = pbVar8;
                    if (iVar13 != 0) {
                      if (local_180 != 0) {
                        (*(code *)PTR_BIO_set_callback_006a85d8)
                                  (param_1,PTR_BIO_debug_callback_006a85dc);
                        (*(code *)PTR_BIO_set_callback_arg_006a85e0)(param_1,*(undefined4 *)puVar4);
                      }
                      if (local_17c != 0) {
                        pbVar12 = abStack_134;
                        if (local_178 == 0) {
                          (*(code *)PTR___printf_chk_006aaad0)(1,"salt=");
                          do {
                            bVar2 = *pbVar12;
                            pbVar12 = pbVar12 + 1;
                            (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_00635448,bVar2);
                          } while (pbVar12 != local_19c);
                          (*(code *)PTR_putchar_006aaaf8)(10);
                          local_1ac = pbVar12;
                        }
                        if (0 < *(int *)(local_18c + 8)) {
                          (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_00635450);
                          if (0 < *(int *)(local_18c + 8)) {
                            local_1ac = &DAT_00635448;
                            iVar13 = 0;
                            do {
                              bVar2 = *pbVar8;
                              iVar13 = iVar13 + 1;
                              pbVar8 = pbVar8 + 1;
                              (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_00635448,bVar2);
                              local_1a8 = (char *)param_1;
                              local_198 = unaff_s2;
                            } while (iVar13 < *(int *)(local_18c + 8));
                          }
                          (*(code *)PTR_putchar_006aaaf8)(10);
                        }
                        unaff_s7 = local_18c;
                        if (0 < *(int *)(local_18c + 0xc)) {
                          (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_00635458);
                          if (0 < *(int *)(local_18c + 0xc)) {
                            local_1ac = &DAT_00635448;
                            iVar13 = 0;
                            pbVar8 = local_19c;
                            do {
                              bVar2 = *pbVar8;
                              iVar13 = iVar13 + 1;
                              pbVar8 = pbVar8 + 1;
                              (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_00635448,bVar2);
                              unaff_s7 = unaff_s4;
                              local_1a8 = (char *)param_1;
                            } while (iVar13 < *(int *)(local_18c + 0xc));
                          }
                          (*(code *)PTR_putchar_006aaaf8)(10);
                        }
                        if (local_17c == 2) {
LAB_0042c3a0:
                          iVar13 = 0;
                          goto LAB_0042ba94;
                        }
                      }
                      pbVar9 = (byte *)(*(code *)PTR_BIO_push_006a85c0)(param_1,pbVar9);
                      local_1ac = param_1;
                      goto LAB_0042c34c;
                    }
                  }
                  local_19c = abStack_12c;
                  uVar15 = *(undefined4 *)puVar4;
                  uVar7 = (*(code *)PTR_EVP_CIPHER_nid_006a84d0)(local_18c);
                  uVar7 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar7);
                  iVar13 = 1;
                  (*(code *)PTR_BIO_printf_006a7f38)(uVar15,"Error setting cipher %s\n",uVar7);
                  (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar4);
                }
                else {
                  param_1 = (byte *)0x0;
                  iVar13 = 1;
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (*(undefined4 *)puVar4,"invalid hex key value\n");
                }
              }
            }
            else {
              uVar7 = (*(code *)PTR_BIO_f_base64_006a85b8)();
              unaff_s2 = (byte *)(*(code *)PTR_BIO_new_006a7fa4)(uVar7);
              if (unaff_s2 != (byte *)0x0) {
                if (local_180 != 0) {
                  (*(code *)PTR_BIO_set_callback_006a85d8)(unaff_s2,PTR_BIO_debug_callback_006a85dc)
                  ;
                  (*(code *)PTR_BIO_set_callback_arg_006a85e0)(unaff_s2,*(undefined4 *)puVar4);
                }
                if (local_160 != 0) {
                  (*(code *)PTR_BIO_set_flags_006a8660)(unaff_s2,0x100);
                }
                if (unaff_s7 == (byte *)0x0) {
                  local_1a4 = (byte *)(*(code *)PTR_BIO_push_006a85c0)(unaff_s2,unaff_s3);
                }
                else {
                  pbVar9 = (byte *)(*(code *)PTR_BIO_push_006a85c0)(unaff_s2,unaff_s4);
                  local_1a4 = unaff_s3;
                }
                goto LAB_0042ba00;
              }
LAB_0042c8b8:
              param_1 = (byte *)0x0;
              iVar13 = 1;
            }
          }
LAB_0042ba94:
          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar4);
          goto LAB_0042baa8;
        }
        param_1 = (byte *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar4,"OPENSSL_malloc failure %ld\n",unaff_s2);
        unaff_s3 = (byte *)0x0;
        unaff_s4 = (byte *)0x0;
        unaff_s2 = (byte *)0x0;
        iVar13 = 1;
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar4);
LAB_0042babc:
        (*(code *)PTR_CRYPTO_free_006a7f88)(param_2);
      }
      if (unaff_s3 != (byte *)0x0) {
        (*(code *)PTR_BIO_free_006a7f70)(unaff_s3);
      }
      if (unaff_s4 != (byte *)0x0) {
        (*(code *)PTR_BIO_free_all_006a7f74)(unaff_s4);
      }
      if (param_1 != (byte *)0x0) {
        (*(code *)PTR_BIO_free_006a7f70)(param_1);
      }
      if (unaff_s2 != (byte *)0x0) {
        (*(code *)PTR_BIO_free_006a7f70)(unaff_s2);
      }
LAB_0042b438:
      if (local_144 != (byte *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      if (local_2c == *(int *)puVar6) {
        return iVar13;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0042cae4:
      pbVar9 = local_194;
      if (iVar13 != 0) {
        iVar13 = (*(code *)PTR_strcmp_006aac20)(unaff_s4,"-kfile");
        if (iVar13 != 0) goto LAB_0042ccd4;
LAB_0042cb40:
        unaff_s3 = unaff_s3 + -1;
        if (unaff_s3 != (byte *)0x0) {
          unaff_s4 = param_2[1];
          param_2 = param_2 + 1;
          param_1 = (byte *)(*(code *)PTR_fopen_006aac08)(unaff_s4,"r");
          puVar5 = PTR_fgets_006aabe8;
          if (param_1 != (byte *)0x0) {
            local_154[-0x4ecc] = 0;
            iVar13 = (*(code *)puVar5)(local_158,0x80,param_1);
            if (iVar13 != 0) {
              (*(code *)PTR_fclose_006aaaa4)(param_1);
              iVar13 = (*(code *)PTR_strlen_006aab30)(local_158);
              if (0 < iVar13) {
                iVar10 = iVar13 + -1;
                if ((local_158[iVar10] != 10) &&
                   (pbVar9 = local_16c, pbVar8 = local_190, local_158[iVar10] != 0xd))
                goto joined_r0x0042b5f0;
                local_158[iVar10] = 0;
                if (iVar10 != 0) {
                  iVar13 = iVar13 + -2;
                  if (((local_16c[iVar13] != 10) &&
                      (pbVar9 = local_16c, pbVar8 = local_190, local_16c[iVar13] != 0xd)) ||
                     (local_16c[iVar13] = 0, pbVar9 = local_16c, pbVar8 = local_190, iVar13 != 0))
                  goto joined_r0x0042b5f0;
                }
              }
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4,"zero length password\n");
              param_1 = local_158;
              goto LAB_0042bb2c;
            }
          }
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar4,"unable to read key from \'%s\'\n",unaff_s4);
        }
LAB_0042bb2c:
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4,"options are\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4,"%-14s input file\n","-in <file>");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar4,"%-14s output file\n","-out <file>");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar4,"%-14s pass phrase source\n","-pass <arg>");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4,"%-14s encrypt\n",&DAT_00635050);
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4,"%-14s decrypt\n",&DAT_00635064);
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar4,
                   "%-14s base64 encode/decode, depending on encryption flag\n","-a/-base64");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar4,"%-14s passphrase is the next argument\n",&DAT_006350c0);
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar4,"%-14s passphrase is the first line of the file argument\n"
                   ,"-kfile");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar4,
                   "%-14s the next argument is the md to use to create a key\n",&DAT_00635128);
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar4,
                   "%-14s   from a passphrase.  One of md2, md5, sha or sha1\n","");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar4,"%-14s salt in hex is the next argument\n",&DAT_006351a4);
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar4,"%-14s key/iv in hex is the next argument\n",&DAT_006351d0)
        ;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar4,"%-14s print the iv/key (then exit if -P)\n","-[pP]");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar4,"%-14s buffer size\n","-bufsize <n>");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar4,"%-14s disable standard block padding\n",local_150 + 0x4f8c
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar4,"%-14s use engine e, possibly a hardware device.\n",
                   "-engine e");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4,"Cipher Types\n");
        (*(code *)PTR_OBJ_NAME_do_all_sorted_006a8640)(2,show_ciphers,*(undefined4 *)puVar4);
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4,"\n");
LAB_0042b424:
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar4);
LAB_0042b434:
        iVar13 = 1;
        goto LAB_0042b438;
      }
      bVar2 = unaff_s4[1];
      if ((bVar2 != 0x6b) || (unaff_s4[2] != 0)) {
        iVar13 = (*(code *)PTR_strcmp_006aac20)(unaff_s4,"-kfile");
        if (iVar13 == 0) goto LAB_0042cb40;
        if (bVar2 == 0x4b) {
          if (unaff_s4[2] == 0) {
            unaff_s3 = unaff_s3 + -1;
            if (unaff_s3 != (byte *)0x0) {
              local_174 = param_2[1];
              param_2 = param_2 + 1;
              pbVar8 = local_190;
              goto joined_r0x0042b5f0;
            }
          }
          else {
LAB_0042cd14:
            if (bVar2 == 0x69) {
              if ((unaff_s4[2] != 0x76) || (unaff_s4[3] != 0)) goto LAB_0042ccd4;
              unaff_s3 = unaff_s3 + -1;
              if (unaff_s3 != (byte *)0x0) {
                local_170 = param_2[1];
                param_2 = param_2 + 1;
                pbVar8 = local_190;
                goto joined_r0x0042b5f0;
              }
            }
            else if (((bVar2 == 0x6d) && (unaff_s4[2] == 100)) && (unaff_s4[3] == 0)) {
              unaff_s3 = unaff_s3 + -1;
              if (unaff_s3 != (byte *)0x0) {
                local_198 = param_2[1];
                param_2 = param_2 + 1;
                pbVar8 = local_190;
                goto joined_r0x0042b5f0;
              }
            }
            else {
LAB_0042ccd4:
              iVar13 = (*(code *)PTR_strcmp_006aac20)(unaff_s4,"-non-fips-allow");
              if (iVar13 == 0) {
                local_15c = 1;
                pbVar8 = local_190;
                goto joined_r0x0042b5f0;
              }
              if (param_1 == &DAT_0000002d) {
                local_18c = (byte *)(*(code *)PTR_EVP_get_cipherbyname_006a8494)(unaff_s4 + 1);
                pbVar8 = local_190;
                if (local_18c != (byte *)0x0) goto joined_r0x0042b5f0;
                unaff_s4 = *param_2;
              }
              iVar13 = (*(code *)PTR_strcmp_006aac20)(unaff_s4,"-none");
              if (iVar13 == 0) {
                local_18c = (byte *)0x0;
                pbVar8 = local_190;
                goto joined_r0x0042b5f0;
              }
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar4,"unknown option \'%s\'\n",unaff_s4);
            }
          }
        }
        else {
          if (bVar2 != 0x53) goto LAB_0042cd14;
          if (unaff_s4[2] != 0) goto LAB_0042ccd4;
          unaff_s3 = unaff_s3 + -1;
          if (unaff_s3 != (byte *)0x0) {
            local_168 = param_2[1];
            param_2 = param_2 + 1;
            pbVar8 = local_190;
            goto joined_r0x0042b5f0;
          }
        }
        goto LAB_0042bb2c;
      }
      unaff_s3 = unaff_s3 + -1;
      if (unaff_s3 == (byte *)0x0) goto LAB_0042bb2c;
      ppbVar1 = param_2 + 1;
      param_2 = param_2 + 1;
      pbVar9 = *ppbVar1;
      pbVar8 = local_190;
      goto joined_r0x0042b5f0;
    }
  } while( true );
}

