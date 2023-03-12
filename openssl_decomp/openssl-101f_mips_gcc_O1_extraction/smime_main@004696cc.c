
/* WARNING: Type propagation algorithm not settling */

int smime_main(undefined4 param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  char *pcVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  char **ppcVar16;
  char *pcVar17;
  int iVar18;
  int iVar19;
  char *pcVar20;
  uint uVar21;
  int iVar22;
  code *pcVar23;
  int iVar24;
  int local_b0;
  int local_ac;
  int local_a8;
  char *local_a4;
  char *local_a0;
  int local_98;
  char *local_94;
  uint local_90;
  char *local_8c;
  int local_88;
  char *local_84;
  undefined4 local_80;
  int local_7c;
  int local_78;
  int local_74;
  char *local_70;
  char *local_6c;
  char *local_64;
  char *local_60;
  char *local_5c;
  char *local_58;
  char *local_54;
  char *local_50;
  char *local_4c;
  char *local_48;
  char **local_40;
  int local_3c;
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar5 = PTR___stack_chk_guard_006aabf0;
  puVar3 = PTR_bio_err_006a7f3c;
  local_40 = (char **)(param_2 + 4);
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar11 = *(int *)puVar3;
  if (iVar11 == 0) {
    uVar8 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar11 = (*(code *)PTR_BIO_new_006a7fa4)(uVar8);
    *(int *)puVar3 = iVar11;
    if (iVar11 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar11,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
      iVar11 = *(int *)puVar3;
    }
  }
  iVar11 = load_config(iVar11,0);
  if (iVar11 == 0) {
    iVar11 = 0;
    local_a8 = 0;
    uVar8 = 0;
    local_a4 = (char *)0x0;
    iVar15 = 0;
    local_a0 = (char *)0x0;
    iVar13 = 1;
    local_ac = 0;
    iVar24 = 0;
    local_b0 = 0;
    iVar18 = 0;
    iVar19 = 0;
    goto LAB_00469afc;
  }
  local_a0 = (char *)0x0;
  local_78 = 0;
  local_80 = 3;
  bVar2 = false;
  iVar24 = 0;
  local_98 = 0;
  local_7c = 6;
  uVar21 = 0;
  local_74 = 6;
  local_48 = (char *)0x0;
  local_a4 = (char *)0x0;
  local_90 = 0x40;
  local_4c = (char *)0x0;
  local_50 = (char *)0x0;
  local_54 = (char *)0x0;
  local_58 = (char *)0x0;
  local_5c = (char *)0x0;
  local_88 = 0;
  local_60 = (char *)0x0;
  local_8c = (char *)0x0;
  local_70 = (char *)0x0;
  local_b0 = 0;
  local_84 = (char *)0x0;
  local_94 = (char *)0x0;
  local_64 = (char *)0x0;
  local_6c = (char *)0x0;
LAB_0046980c:
  uVar6 = local_38;
  if (local_38 == 0) {
LAB_00469814:
    ppcVar16 = local_40;
    pcVar20 = *local_40;
    if ((pcVar20 == (char *)0x0) || (*pcVar20 != '-')) goto LAB_004698bc;
    uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-encrypt");
    if (uVar6 == 0) {
      local_40 = ppcVar16 + 1;
      uVar21 = 0x11;
    }
    else {
      uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-decrypt");
      if (uVar6 == 0) {
        local_40 = ppcVar16 + 1;
        uVar21 = 0x22;
      }
      else {
        uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-sign");
        if (uVar6 == 0) {
          local_40 = ppcVar16 + 1;
          uVar21 = 0x53;
        }
        else {
          uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-resign");
          if (uVar6 == 0) {
            local_40 = ppcVar16 + 1;
            uVar21 = 0x76;
          }
          else {
            uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-verify");
            if (uVar6 == 0) {
              local_40 = ppcVar16 + 1;
              uVar21 = 0x24;
            }
            else {
              uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-pk7out");
              if (uVar6 == 0) {
                local_40 = ppcVar16 + 1;
                uVar21 = 0x35;
              }
              else {
                iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-des3");
                pcVar23 = (code *)PTR_EVP_des_ede3_cbc_006a7f48;
                if ((((((iVar11 == 0) ||
                       (iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,&DAT_0063ad0c),
                       pcVar23 = (code *)PTR_EVP_des_cbc_006a83a4, iVar11 == 0)) ||
                      (iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-seed"),
                      pcVar23 = (code *)PTR_EVP_seed_cbc_006a83b8, iVar11 == 0)) ||
                     ((iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-rc2-40"),
                      pcVar23 = (code *)PTR_EVP_rc2_40_cbc_006a8410, iVar11 == 0 ||
                      (iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-rc2-128"),
                      pcVar23 = (code *)PTR_EVP_rc2_cbc_006a840c, iVar11 == 0)))) ||
                    (iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-rc2-64"),
                    pcVar23 = (code *)PTR_EVP_rc2_64_cbc_006a8408, iVar11 == 0)) ||
                   (((iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-aes128"),
                     pcVar23 = (code *)PTR_EVP_aes_128_cbc_006a83b4, iVar11 == 0 ||
                     (iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-aes192"),
                     pcVar23 = (code *)PTR_EVP_aes_192_cbc_006a83b0, iVar11 == 0)) ||
                    ((iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-aes256"),
                     pcVar23 = (code *)PTR_EVP_aes_256_cbc_006a83ac, iVar11 == 0 ||
                     (((iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-camellia128"),
                       pcVar23 = (code *)PTR_EVP_camellia_128_cbc_006a83c0, iVar11 == 0 ||
                       (iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-camellia192"),
                       pcVar23 = (code *)PTR_EVP_camellia_192_cbc_006a83bc, iVar11 == 0)) ||
                      (iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-camellia256"),
                      pcVar23 = (code *)PTR_EVP_camellia_256_cbc_006a83c4, iVar11 == 0)))))))) {
                  local_88 = (*pcVar23)();
                  goto LAB_0046a4e0;
                }
                uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-text");
                if (uVar6 == 0) {
                  local_40 = ppcVar16 + 1;
                  local_90 = local_90 | 1;
                }
                else {
                  uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-nointern");
                  if (uVar6 == 0) {
                    local_40 = ppcVar16 + 1;
                    local_90 = local_90 | 0x10;
                  }
                  else {
                    uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-noverify");
                    if (uVar6 == 0) {
                      local_40 = ppcVar16 + 1;
                      local_90 = local_90 | 0x20;
                    }
                    else {
                      uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-nochain");
                      if (uVar6 == 0) {
                        local_40 = ppcVar16 + 1;
                        local_90 = local_90 | 8;
                      }
                      else {
                        uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-nocerts");
                        if (uVar6 == 0) {
                          local_40 = ppcVar16 + 1;
                          local_90 = local_90 | 2;
                        }
                        else {
                          uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-noattr");
                          if (uVar6 == 0) {
                            local_40 = ppcVar16 + 1;
                            local_90 = local_90 | 0x100;
                          }
                          else {
                            uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-nodetach");
                            if (uVar6 == 0) {
                              local_40 = ppcVar16 + 1;
                              local_90 = local_90 & 0xffffffbf;
                            }
                            else {
                              uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-nosmimecap");
                              if (uVar6 == 0) {
                                local_40 = ppcVar16 + 1;
                                local_90 = local_90 | 0x200;
                              }
                              else {
                                uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-binary");
                                if (uVar6 == 0) {
                                  local_40 = ppcVar16 + 1;
                                  local_90 = local_90 | 0x80;
                                }
                                else {
                                  uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-nosigs");
                                  if (uVar6 == 0) {
                                    local_40 = ppcVar16 + 1;
                                    local_90 = local_90 | 4;
                                  }
                                  else {
                                    uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-stream");
                                    if ((uVar6 == 0) ||
                                       (uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-indef"),
                                       uVar6 == 0)) {
                                      local_40 = ppcVar16 + 1;
                                      bVar2 = true;
                                    }
                                    else {
                                      uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-noindef");
                                      if (uVar6 == 0) {
                                        local_40 = ppcVar16 + 1;
                                        bVar2 = false;
                                      }
                                      else {
                                        uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-nooldmime")
                                        ;
                                        if (uVar6 == 0) {
                                          local_40 = ppcVar16 + 1;
                                          local_90 = local_90 | 0x400;
                                        }
                                        else {
                                          uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-crlfeol")
                                          ;
                                          if (uVar6 == 0) {
                                            local_40 = ppcVar16 + 1;
                                            local_90 = local_90 | 0x800;
                                          }
                                          else {
                                            uVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-rand");
                                            if (uVar6 == 0) {
                                              local_48 = ppcVar16[1];
                                              if (local_48 == (char *)0x0) goto LAB_00469c94;
                                              local_40 = ppcVar16 + 2;
                                              local_98 = 1;
                                            }
                                            else {
                                              uVar6 = (*(code *)PTR_strcmp_006aac20)
                                                                (pcVar20,"-engine");
                                              if (uVar6 == 0) {
                                                local_a0 = ppcVar16[1];
                                                pcVar20 = local_a0;
                                              }
                                              else {
                                                uVar6 = (*(code *)PTR_strcmp_006aac20)
                                                                  (pcVar20,"-passin");
                                                if (uVar6 == 0) {
                                                  local_a4 = ppcVar16[1];
                                                  pcVar20 = local_a4;
                                                }
                                                else {
                                                  cVar1 = pcVar20[1];
                                                  if (((cVar1 == 't') && (pcVar20[2] == 'o')) &&
                                                     (pcVar20[3] == '\0')) {
                                                    local_5c = ppcVar16[1];
                                                    pcVar20 = local_5c;
joined_r0x0046b3e8:
                                                    if (pcVar20 != (char *)0x0) {
                                                      local_40 = ppcVar16 + 2;
                                                      uVar6 = 0;
                                                      goto LAB_004698b4;
                                                    }
                                                    goto LAB_00469c94;
                                                  }
                                                  uVar6 = (*(code *)PTR_strcmp_006aac20)
                                                                    (pcVar20,"-from");
                                                  if (uVar6 == 0) {
                                                    local_58 = ppcVar16[1];
                                                    pcVar20 = local_58;
                                                  }
                                                  else {
                                                    uVar6 = (*(code *)PTR_strcmp_006aac20)
                                                                      (pcVar20,"-subject");
                                                    if (uVar6 == 0) {
                                                      local_54 = ppcVar16[1];
                                                      pcVar20 = local_54;
                                                    }
                                                    else {
                                                      iVar11 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar20,"-signer");
                                                      if (iVar11 == 0) {
                                                        if (ppcVar16[1] != (char *)0x0) {
                                                          if (local_94 != (char *)0x0) {
                                                            if (iVar24 == 0) {
                                                              iVar24 = (*(code *)
                                                  PTR_sk_new_null_006a80a4)();
                                                  }
                                                  if (local_8c == (char *)0x0) {
                                                    local_8c = local_94;
                                                  }
                                                  (*(code *)PTR_sk_push_006a80a8)(iVar24,local_94);
                                                  if (local_b0 == 0) {
                                                    local_b0 = (*(code *)PTR_sk_new_null_006a80a4)()
                                                    ;
                                                  }
                                                  (*(code *)PTR_sk_push_006a80a8)(local_b0,local_8c)
                                                  ;
                                                  local_8c = (char *)0x0;
                                                  ppcVar16 = local_40;
                                                  }
                                                  local_94 = ppcVar16[1];
                                                  local_40 = ppcVar16 + 2;
                                                  uVar6 = local_38;
                                                  goto LAB_004698b4;
                                                  }
                                                  goto LAB_00469c94;
                                                  }
                                                  uVar6 = (*(code *)PTR_strcmp_006aac20)
                                                                    (pcVar20,"-recip");
                                                  if (uVar6 == 0) {
                                                    local_84 = ppcVar16[1];
                                                    pcVar20 = local_84;
                                                  }
                                                  else {
                                                    if (((cVar1 == 'm') && (pcVar20[2] == 'd')) &&
                                                       (pcVar20[3] == '\0')) {
                                                      if (ppcVar16[1] != (char *)0x0) {
                                                        local_40 = ppcVar16 + 1;
                                                        local_78 = (*(code *)
                                                  PTR_EVP_get_digestbyname_006a802c)();
                                                  if (local_78 != 0) goto LAB_0046a4e0;
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar3,
                                                             "Unknown digest %s\n",*local_40);
                                                  }
                                                  goto LAB_00469c94;
                                                  }
                                                  iVar11 = (*(code *)PTR_strcmp_006aac20)
                                                                     (pcVar20,"-inkey");
                                                  if (iVar11 == 0) {
                                                    if (ppcVar16[1] == (char *)0x0)
                                                    goto LAB_00469c94;
                                                    if (local_8c != (char *)0x0) {
                                                      if (local_94 == (char *)0x0)
                                                      goto LAB_0046a554;
                                                      if (iVar24 == 0) {
                                                        iVar24 = (*(code *)PTR_sk_new_null_006a80a4)
                                                                           ();
                                                      }
                                                      (*(code *)PTR_sk_push_006a80a8)
                                                                (iVar24,local_94);
                                                      if (local_b0 == 0) {
                                                        local_b0 = (*(code *)
                                                  PTR_sk_new_null_006a80a4)();
                                                  }
                                                  (*(code *)PTR_sk_push_006a80a8)(local_b0,local_8c)
                                                  ;
                                                  local_94 = (char *)0x0;
                                                  ppcVar16 = local_40;
                                                  }
                                                  local_8c = ppcVar16[1];
                                                  local_40 = ppcVar16 + 2;
                                                  uVar6 = local_38;
                                                  goto LAB_004698b4;
                                                  }
                                                  iVar11 = (*(code *)PTR_strcmp_006aac20)
                                                                     (pcVar20,"-keyform");
                                                  if (iVar11 == 0) {
                                                    if (ppcVar16[1] != (char *)0x0) {
                                                      local_40 = ppcVar16 + 1;
                                                      local_80 = str2fmt();
                                                      local_40 = local_40 + 1;
                                                      uVar6 = local_38;
                                                      goto LAB_004698b4;
                                                    }
                                                    goto LAB_00469c94;
                                                  }
                                                  uVar6 = (*(code *)PTR_strcmp_006aac20)
                                                                    (pcVar20,"-certfile");
                                                  if (uVar6 == 0) {
                                                    local_70 = ppcVar16[1];
                                                    pcVar20 = local_70;
                                                  }
                                                  else {
                                                    uVar6 = (*(code *)PTR_strcmp_006aac20)
                                                                      (pcVar20,"-CAfile");
                                                    if (uVar6 == 0) {
                                                      local_50 = ppcVar16[1];
                                                      pcVar20 = local_50;
                                                    }
                                                    else {
                                                      uVar6 = (*(code *)PTR_strcmp_006aac20)
                                                                        (pcVar20,"-CApath");
                                                      if (uVar6 == 0) {
                                                        local_4c = ppcVar16[1];
                                                        pcVar20 = local_4c;
                                                      }
                                                      else {
                                                        if (((cVar1 == 'i') && (pcVar20[2] == 'n'))
                                                           && (pcVar20[3] == '\0')) {
                                                          local_6c = ppcVar16[1];
                                                          pcVar20 = local_6c;
                                                          goto joined_r0x0046b3e8;
                                                        }
                                                        iVar11 = (*(code *)PTR_strcmp_006aac20)
                                                                           (pcVar20,"-inform");
                                                        if (iVar11 == 0) {
                                                          if (ppcVar16[1] != (char *)0x0) {
                                                            local_40 = ppcVar16 + 1;
                                                            local_74 = str2fmt();
                                                            local_40 = local_40 + 1;
                                                            uVar6 = local_38;
                                                            goto LAB_004698b4;
                                                          }
                                                          goto LAB_00469c94;
                                                        }
                                                        iVar11 = (*(code *)PTR_strcmp_006aac20)
                                                                           (pcVar20,"-outform");
                                                        if (iVar11 == 0) {
                                                          if (ppcVar16[1] != (char *)0x0) {
                                                            local_40 = ppcVar16 + 1;
                                                            local_7c = str2fmt();
LAB_0046a4e0:
                                                            local_40 = local_40 + 1;
                                                            uVar6 = local_38;
                                                            goto LAB_004698b4;
                                                          }
                                                          goto LAB_00469c94;
                                                        }
                                                        uVar6 = (*(code *)PTR_strcmp_006aac20)
                                                                          (pcVar20,&DAT_00632edc);
                                                        if (uVar6 == 0) {
                                                          local_64 = ppcVar16[1];
                                                          pcVar20 = local_64;
                                                          goto joined_r0x0046b370;
                                                        }
                                                        uVar6 = (*(code *)PTR_strcmp_006aac20)
                                                                          (pcVar20,"-content");
                                                        if (uVar6 != 0) {
                                                          iVar11 = args_verify(&local_40,0,&local_38
                                                                               ,*(undefined4 *)
                                                                                 puVar3,&local_30);
                                                          if (iVar11 == 0) {
                                                            local_88 = (*(code *)
                                                  PTR_EVP_get_cipherbyname_006a8494)(*local_40 + 1);
                                                  if (local_88 == 0) {
                                                    local_40 = local_40 + 1;
                                                    uVar6 = 1;
                                                    local_38 = 1;
                                                    goto LAB_004698b4;
                                                  }
                                                  goto LAB_0046a4e0;
                                                  }
                                                  goto LAB_0046980c;
                                                  }
                                                  local_60 = ppcVar16[1];
                                                  pcVar20 = local_60;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
joined_r0x0046b370:
                                              if (pcVar20 == (char *)0x0) goto LAB_00469c94;
                                              local_40 = ppcVar16 + 2;
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
          }
        }
      }
    }
LAB_004698b4:
    if (uVar6 != 0) goto LAB_004698bc;
    goto LAB_00469814;
  }
LAB_004698bc:
  uVar14 = uVar21 & 0x40;
  if (uVar14 == 0) {
    if ((local_b0 == 0) && (iVar24 == 0)) {
      if (uVar21 != 0x22) {
        if (uVar21 == 0x11) {
          local_98 = 1;
          if (*local_40 != (char *)0x0) goto LAB_00469934;
          iVar24 = 0;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar3,"No recipient(s) certificate(s) specified\n");
          local_38 = 1;
          goto LAB_00469c94;
        }
        if (uVar21 == 0) {
          iVar24 = 0;
          local_38 = 1;
          goto LAB_00469c94;
        }
        goto LAB_00469934;
      }
      if ((local_84 != (char *)0x0) || (local_8c != (char *)0x0)) goto LAB_00469934;
      iVar24 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar3,"No recipient certificate or key specified\n");
      local_38 = 1;
    }
    else {
      (*(code *)PTR_BIO_puts_006a8058)
                (*(undefined4 *)puVar3,"Multiple signers or keys not allowed\n");
    }
LAB_00469c94:
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Usage smime [options] cert.pem ...\n")
    ;
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"where options are\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-encrypt       encrypt message\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-decrypt       decrypt encrypted message\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-sign          sign message\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-verify        verify signed message\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-pk7out        output PKCS#7 structure\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-des3          encrypt with triple DES\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-des           encrypt with DES\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-seed          encrypt with SEED\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-rc2-40        encrypt with RC2-40 (default)\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-rc2-64        encrypt with RC2-64\n")
    ;
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-rc2-128       encrypt with RC2-128\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-aes128, -aes192, -aes256\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"               encrypt PEM output with cbc aes\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-camellia128, -camellia192, -camellia256\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"               encrypt PEM output with cbc camellia\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,
               "-nointern      don\'t search certificates in message for signer\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-nosigs        don\'t verify message signature\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-noverify      don\'t verify signers certificate\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,
               "-nocerts       don\'t include signers certificate when signing\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-nodetach      use opaque signing\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-noattr        don\'t include any signed attributes\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-binary        don\'t translate message to text\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-certfile file other certificates file\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-signer file   signer certificate file\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-recip  file   recipient certificate file for decryption\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-in file       input file\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-inform arg    input format SMIME (default), PEM or DER\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,
               "-inkey file    input private key (if not signer or recipient)\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-keyform arg   input private key format (PEM or ENGINE)\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-out file      output file\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-outform arg   output format SMIME (default), PEM or DER\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,
               "-content file  supply or override content for detached signature\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-to addr       to address\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-from ad       from address\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-subject s     subject\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-text          include or delete text MIME headers\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-CApath dir    trusted certificates directory\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-CAfile file   trusted certificates file\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,
               "-crl_check     check revocation status of signer\'s certificate using CRLs\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,
               "-crl_check_all check revocation status of signer\'s certificate chain using CRLs\n")
    ;
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-engine e      use engine e, possibly a hardware device.\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-passin arg    input file pass phrase source\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-rand file%cfile%c...\n",0x3a,0x3a);
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,
               "               load the file (or the files in the directory) into\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"               the random number generator\n");
    uVar8 = *(undefined4 *)puVar3;
    pcVar20 = "cert.pem       recipient certificate(s) for encryption\n";
  }
  else {
    if (local_8c == (char *)0x0) {
      if (local_94 != (char *)0x0) goto LAB_004698dc;
    }
    else {
      if (local_94 == (char *)0x0) {
LAB_0046a554:
        (*(code *)PTR_BIO_puts_006a8058)(*(undefined4 *)puVar3,"Illegal -inkey without -signer\n");
        goto LAB_00469c94;
      }
LAB_004698dc:
      if (iVar24 == 0) {
        iVar24 = (*(code *)PTR_sk_new_null_006a80a4)();
      }
      (*(code *)PTR_sk_push_006a80a8)(iVar24,local_94);
      if (local_b0 == 0) {
        local_b0 = (*(code *)PTR_sk_new_null_006a80a4)();
      }
      pcVar20 = local_94;
      if (local_8c != (char *)0x0) {
        pcVar20 = local_8c;
      }
      (*(code *)PTR_sk_push_006a80a8)(local_b0,pcVar20);
    }
    if (iVar24 == 0) {
      iVar24 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"No signer certificate specified\n");
      local_98 = 1;
      local_38 = 1;
      goto LAB_00469c94;
    }
    local_8c = (char *)0x0;
    local_94 = (char *)0x0;
    local_98 = 1;
    uVar6 = local_38;
LAB_00469934:
    puVar4 = PTR_bio_err_006a7f3c;
    if (uVar6 != 0) goto LAB_00469c94;
    uVar7 = setup_engine(*(undefined4 *)puVar3,local_a0,0);
    iVar11 = app_passwd(*(undefined4 *)puVar3,local_a4,0,&local_34,0);
    if (iVar11 != 0) {
      if ((local_98 != 0) &&
         (app_RAND_load_file(0,*(undefined4 *)puVar4,local_48 != (char *)0x0),
         local_48 != (char *)0x0)) {
        uVar10 = *(undefined4 *)puVar4;
        uVar8 = app_RAND_load_files(local_48);
        (*(code *)PTR_BIO_printf_006a7f38)(uVar10,"%ld semi-random bytes loaded\n",uVar8);
      }
      if (uVar14 == 0) {
        local_90 = local_90 & 0xffffffbf;
      }
      if ((uVar21 & 0x10) == 0) {
        if ((local_90 & 0x80) == 0) {
          if ((uVar21 & 0x20) == 0) {
            pcVar20 = "w";
LAB_0046a900:
            pcVar17 = "r";
            goto LAB_004699dc;
          }
          pcVar20 = "w";
          goto LAB_0046a3c0;
        }
        if ((uVar21 & 0x20) != 0) {
          pcVar20 = "wb";
          goto LAB_0046a3c0;
        }
        pcVar20 = "wb";
        pcVar17 = "rb";
LAB_004699dc:
        if (uVar21 != 0x11) goto LAB_0046a3d8;
        if (local_88 == 0) {
          local_88 = (*(code *)PTR_EVP_rc2_40_cbc_006a8410)();
        }
        uVar8 = (*(code *)PTR_sk_new_null_006a80a4)();
        pcVar12 = *local_40;
        while (pcVar12 != (char *)0x0) {
          iVar11 = load_cert(*(undefined4 *)puVar3,pcVar12,3,0,uVar7,"recipient certificate file");
          if (iVar11 == 0) {
            local_a0 = (char *)0x0;
            goto LAB_00469a7c;
          }
          (*(code *)PTR_sk_push_006a80a8)(uVar8,iVar11);
          pcVar12 = local_40[1];
          local_40 = local_40 + 1;
        }
      }
      else {
        if (local_7c == 1) {
          pcVar20 = "wb";
        }
        else {
          pcVar20 = "w";
        }
        if ((uVar21 & 0x20) == 0) {
          if ((local_90 & 0x80) == 0) goto LAB_0046a900;
          pcVar17 = "rb";
          goto LAB_004699dc;
        }
LAB_0046a3c0:
        uVar6 = uVar21 & 0x20;
        if (local_74 == 1) {
          pcVar17 = "rb";
        }
        else {
          pcVar17 = "r";
        }
LAB_0046a3d8:
        uVar8 = 0;
      }
      if (local_70 == (char *)0x0) {
        local_a0 = (char *)0x0;
      }
      else {
        local_a0 = (char *)load_certs(*(undefined4 *)puVar3,local_70,3,0,uVar7,"certificate file");
        if (local_a0 == (char *)0x0) {
          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
LAB_00469a7c:
          local_ac = 0;
          iVar19 = 0;
          local_a4 = (char *)0x0;
          iVar15 = 0;
          local_a8 = 0;
          iVar18 = 0;
          iVar13 = 2;
          iVar11 = 0;
          goto LAB_0046a140;
        }
      }
      pcVar12 = local_8c;
      if (local_84 == (char *)0x0) {
        if (uVar21 != 0x22) goto LAB_0046a438;
        local_a4 = (char *)0x0;
        if (local_8c != (char *)0x0) goto LAB_0046a97c;
LAB_0046aa40:
        local_a4 = (char *)0x0;
        iVar11 = 0;
      }
      else {
        if (uVar21 == 0x22) {
          local_a4 = (char *)load_cert(*(undefined4 *)puVar3,local_84,3,0,uVar7,
                                       "recipient certificate file");
          if (local_a4 == (char *)0x0) {
            iVar19 = 0;
            iVar11 = 0;
            iVar15 = 0;
            iVar18 = 0;
            iVar13 = 2;
            (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
            local_ac = 0;
            local_a8 = 0;
            goto LAB_0046a140;
          }
          pcVar12 = local_84;
          if (local_8c != (char *)0x0) {
            pcVar12 = local_8c;
          }
        }
        else {
LAB_0046a438:
          iVar11 = 0;
          if (uVar21 != 0x53) {
            local_a4 = (char *)0x0;
            goto LAB_0046a448;
          }
          if (local_8c == (char *)0x0) {
            local_a4 = (char *)0x0;
            pcVar12 = local_94;
            if (local_94 == (char *)0x0) goto LAB_0046aa40;
          }
          else {
            local_a4 = (char *)0x0;
          }
        }
LAB_0046a97c:
        local_8c = pcVar12;
        iVar11 = load_key(*(undefined4 *)puVar3,local_8c,local_80,0,local_34,uVar7,
                          "signing key file");
        if (iVar11 == 0) {
          iVar19 = 0;
          local_ac = 0;
          iVar15 = 0;
          local_a8 = 0;
          iVar18 = 0;
          iVar13 = 2;
          goto LAB_0046a140;
        }
      }
LAB_0046a448:
      if (local_6c != (char *)0x0) {
        local_ac = (*(code *)PTR_BIO_new_file_006a7fac)(local_6c,pcVar17);
        if (local_ac != 0) goto LAB_0046a474;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar3,"Can\'t open input file %s\n",local_6c);
LAB_0046a4b0:
        iVar19 = 0;
        local_a8 = 0;
        iVar15 = 0;
        iVar18 = 0;
        iVar13 = 2;
        goto LAB_0046a140;
      }
      local_ac = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdin_006aab20,0);
LAB_0046a474:
      iVar18 = 0;
      if (uVar6 != 0) {
        if (local_74 == 6) {
          iVar18 = (*(code *)PTR_SMIME_read_PKCS7_006a8e38)(local_ac,&local_3c);
        }
        else if (local_74 == 3) {
          iVar18 = (*(code *)PTR_PEM_read_bio_PKCS7_006a8694)(local_ac,0,0,0);
        }
        else {
          if (local_74 != 1) {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar3,"Bad input format for PKCS#7 file\n");
            goto LAB_0046a4b0;
          }
          iVar18 = (*(code *)PTR_d2i_PKCS7_bio_006a86a4)(local_ac,0);
        }
        if (iVar18 == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Error reading S/MIME message\n")
          ;
LAB_0046ad18:
          iVar19 = 0;
          local_a8 = 0;
          iVar15 = 0;
          iVar13 = 2;
          goto LAB_0046a140;
        }
        if (local_60 != (char *)0x0) {
          (*(code *)PTR_BIO_free_006a7f70)(local_3c);
          local_3c = (*(code *)PTR_BIO_new_file_006a7fac)(local_60,&DAT_006347ac);
          if (local_3c == 0) {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar3,"Can\'t read content file %s\n",local_60);
            goto LAB_0046ad18;
          }
        }
      }
      if (local_64 == (char *)0x0) {
        iVar19 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
      }
      else {
        iVar19 = (*(code *)PTR_BIO_new_file_006a7fac)(local_64,pcVar20);
        if (iVar19 == 0) {
          iVar15 = 0;
          iVar13 = 2;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar3,"Can\'t open output file %s\n",local_64);
          local_a8 = 0;
          goto LAB_0046a140;
        }
      }
      if (uVar21 == 0x24) {
        local_a8 = setup_verify(*(undefined4 *)puVar3,local_50,local_4c);
        if (local_a8 == 0) {
          iVar15 = 0;
          iVar13 = 2;
          goto LAB_0046a140;
        }
        (*(code *)PTR_X509_STORE_set_verify_cb_006a83f8)(local_a8,smime_cb);
        if (local_30 != 0) {
          (*(code *)PTR_X509_STORE_set1_param_006a83fc)(local_a8);
        }
        if (uVar14 != 0) {
LAB_0046a680:
          local_90 = local_90 | 0x8000;
          goto LAB_0046a688;
        }
        if (iVar18 != 0) {
LAB_0046abec:
          iVar15 = (*(code *)PTR_PKCS7_verify_006a8e30)
                             (iVar18,local_a0,local_a8,local_3c,iVar19,local_90);
          if (iVar15 != 0) goto LAB_0046af88;
          iVar15 = 0;
          iVar13 = 4;
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Verification failure\n");
          goto LAB_0046a140;
        }
LAB_0046a8cc:
        iVar15 = 0;
        iVar18 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar3,"Error creating PKCS#7 structure\n");
        iVar13 = 3;
        goto LAB_0046a140;
      }
      if (uVar21 == 0x11) {
        if (bVar2) {
          local_90 = local_90 | 0x1000;
        }
        iVar18 = (*(code *)PTR_PKCS7_encrypt_006a8e2c)(uVar8,local_ac,local_88,local_90);
        local_a8 = 0;
LAB_0046a8c0:
        if (iVar18 == 0) goto LAB_0046a8cc;
      }
      else {
        if (uVar14 == 0) {
          local_a8 = 0;
        }
        else {
          if (uVar21 != 0x53) {
            local_a8 = 0;
            goto LAB_0046a680;
          }
          if ((local_90 & 0x40) == 0) {
            if (bVar2) {
              local_90 = local_90 | 0x1000;
            }
          }
          else if (local_7c == 6) {
            local_90 = local_90 | 0x1000;
          }
          local_90 = local_90 | 0x4000;
          iVar18 = (*(code *)PTR_PKCS7_sign_006a8e3c)(0,0,local_a0,local_ac,local_90);
          if (iVar18 == 0) {
            iVar15 = 0;
            local_a8 = 0;
            iVar13 = 3;
            goto LAB_0046a140;
          }
          local_a8 = 0;
LAB_0046a688:
          puVar4 = PTR_bio_err_006a7f3c;
          pcVar20 = local_94;
          for (iVar13 = 0; iVar15 = (*(code *)PTR_sk_num_006a7f2c)(iVar24), iVar13 < iVar15;
              iVar13 = iVar13 + 1) {
            pcVar20 = (char *)(*(code *)PTR_sk_value_006a7f24)(iVar24,iVar13);
            uVar10 = (*(code *)PTR_sk_value_006a7f24)(local_b0,iVar13);
            iVar15 = load_cert(*(undefined4 *)puVar3,pcVar20,3,0,uVar7,"signer certificate");
            iVar9 = iVar11;
            if (((iVar15 == 0) ||
                (iVar9 = load_key(*(undefined4 *)puVar4,uVar10,local_80,0,local_34,uVar7,
                                  "signing key file"), iVar9 == 0)) ||
               (iVar11 = (*(code *)PTR_PKCS7_sign_add_signer_006a8e24)
                                   (iVar18,iVar15,iVar9,local_78,local_90), iVar11 == 0)) {
              iVar13 = 3;
              iVar11 = iVar9;
              goto LAB_0046a140;
            }
            (*(code *)PTR_X509_free_006a7f90)(iVar15);
            iVar11 = 0;
            (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar9);
          }
          local_94 = pcVar20;
          if (uVar21 == 0x53) {
            if (((local_90 & 0x1000) == 0) &&
               (iVar15 = (*(code *)PTR_PKCS7_final_006a8e28)(iVar18,local_ac,local_90), iVar15 == 0)
               ) {
              iVar15 = 0;
              iVar13 = 3;
              goto LAB_0046a140;
            }
            goto LAB_0046a8c0;
          }
        }
        if (iVar18 == 0) goto LAB_0046a8cc;
        if (uVar21 == 0x22) {
          iVar15 = (*(code *)PTR_PKCS7_decrypt_006a8e34)(iVar18,iVar11,local_a4,iVar19,local_90);
          if (iVar15 == 0) {
            iVar15 = 0;
            iVar13 = 4;
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar3,"Error decrypting PKCS#7 structure\n");
          }
          else {
            iVar15 = 0;
            iVar13 = 0;
          }
          goto LAB_0046a140;
        }
        if (uVar21 == 0x24) goto LAB_0046abec;
        if (uVar21 == 0x35) {
          iVar15 = 0;
          (*(code *)PTR_PEM_write_bio_PKCS7_006a86a8)(iVar19,iVar18);
          iVar13 = 0;
          goto LAB_0046a140;
        }
      }
      if (local_5c != (char *)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)(iVar19,"To: %s\n",local_5c);
      }
      if (local_58 != (char *)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)(iVar19,"From: %s\n",local_58);
      }
      if (local_54 != (char *)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)(iVar19,"Subject: %s\n",local_54);
      }
      if (local_7c == 6) {
        iVar15 = local_3c;
        pcVar23 = (code *)PTR_SMIME_write_PKCS7_006a8e40;
        if (uVar21 != 0x76) goto LAB_0046adc8;
      }
      else {
        pcVar23 = (code *)PTR_PEM_write_bio_PKCS7_stream_006a8e44;
        if ((local_7c != 3) && (pcVar23 = (code *)PTR_i2d_PKCS7_bio_stream_006a8e48, local_7c != 1))
        {
          iVar15 = 0;
          iVar13 = 4;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar3,"Bad output format for PKCS#7 file\n");
          goto LAB_0046a140;
        }
LAB_0046adc8:
        iVar15 = local_ac;
      }
      (*pcVar23)(iVar19,iVar18,iVar15,local_90);
      iVar15 = 0;
      iVar13 = 0;
      goto LAB_0046a140;
    }
    uVar8 = *(undefined4 *)puVar4;
    pcVar20 = "Error getting password\n";
  }
  iVar19 = 0;
  (*(code *)PTR_BIO_printf_006a7f38)(uVar8,pcVar20);
  uVar8 = 0;
  iVar11 = 0;
  local_ac = 0;
  iVar15 = 0;
  local_a0 = (char *)0x0;
  iVar18 = 0;
  local_a4 = (char *)0x0;
  iVar13 = 1;
  local_a8 = 0;
LAB_0046a140:
  do {
    if (local_98 != 0) {
      app_RAND_write_file(0,*(undefined4 *)puVar3);
    }
    if (iVar13 != 0) {
LAB_00469afc:
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar3);
    }
    (*(code *)PTR_sk_pop_free_006a8158)(uVar8,PTR_X509_free_006a7f90);
    (*(code *)PTR_sk_pop_free_006a8158)(local_a0,PTR_X509_free_006a7f90);
    if (local_30 != 0) {
      (*(code *)PTR_X509_VERIFY_PARAM_free_006a83cc)();
    }
    if (iVar24 != 0) {
      (*(code *)PTR_sk_free_006a7f80)(iVar24);
    }
    if (local_b0 != 0) {
      (*(code *)PTR_sk_free_006a7f80)(local_b0);
    }
    (*(code *)PTR_X509_STORE_free_006a8384)(local_a8);
    (*(code *)PTR_X509_free_006a7f90)(0);
    (*(code *)PTR_X509_free_006a7f90)(local_a4);
    (*(code *)PTR_X509_free_006a7f90)(iVar15);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar11);
    (*(code *)PTR_PKCS7_free_006a8350)(iVar18);
    (*(code *)PTR_BIO_free_006a7f70)(local_ac);
    (*(code *)PTR_BIO_free_006a7f70)(local_3c);
    (*(code *)PTR_BIO_free_all_006a7f74)(iVar19);
    if (local_34 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (local_2c == *(int *)puVar5) {
      return iVar13;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0046af88:
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Verification successful\n");
    uVar7 = (*(code *)PTR_PKCS7_get0_signers_006a8e4c)(iVar18,local_a0,local_90);
    if (local_94 != (char *)0x0) {
      iVar15 = (*(code *)PTR_BIO_new_file_006a7fac)(local_94,"w");
      if (iVar15 == 0) {
        iVar15 = 0;
        iVar13 = 5;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,"Error writing signers to %s\n",local_94);
        goto LAB_0046a140;
      }
      iVar9 = (*(code *)PTR_sk_num_006a7f2c)(uVar7);
      iVar13 = 0;
      if (0 < iVar9) {
        do {
          iVar22 = iVar13 + 1;
          uVar10 = (*(code *)PTR_sk_value_006a7f24)(uVar7,iVar13);
          (*(code *)PTR_PEM_write_bio_X509_006a8020)(iVar15,uVar10);
          iVar9 = (*(code *)PTR_sk_num_006a7f2c)(uVar7);
          iVar13 = iVar22;
        } while (iVar22 < iVar9);
      }
      (*(code *)PTR_BIO_free_006a7f70)(iVar15);
    }
    iVar15 = 0;
    iVar13 = 0;
    (*(code *)PTR_sk_free_006a7f80)(uVar7);
  } while( true );
}

