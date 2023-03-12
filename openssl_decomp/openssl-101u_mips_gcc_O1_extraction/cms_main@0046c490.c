
/* WARNING: Type propagation algorithm not settling */

int cms_main(undefined4 param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  uint uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int iVar19;
  char *pcVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  char **ppcVar25;
  char *pcVar26;
  int iVar27;
  char *pcVar28;
  int iVar29;
  code *pcVar30;
  int iVar31;
  int local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  char *local_f0;
  char *local_e8;
  int local_e4;
  char *local_e0;
  char *local_dc;
  int local_d8;
  char *local_d4;
  int local_d0;
  uint local_c8;
  int local_c4;
  char *local_c0;
  int local_bc;
  char *local_b4;
  int local_b0;
  char *local_ac;
  int local_a8;
  undefined4 local_a4;
  int local_a0;
  char *local_9c;
  char *local_98;
  char *local_94;
  char *local_90;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  char *local_7c;
  char *local_70;
  char *local_6c;
  char *local_68;
  char *local_64;
  char *local_60;
  char **local_54;
  int local_50;
  uint local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  
  puVar10 = PTR___stack_chk_guard_006a9ae8;
  puVar8 = PTR_bio_err_006a6e3c;
  local_54 = (char **)(param_2 + 4);
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iVar19 = *(int *)puVar8;
  if (iVar19 == 0) {
    uVar12 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar19 = (*(code *)PTR_BIO_new_006a6ea4)(uVar12);
    *(int *)puVar8 = iVar19;
    if (iVar19 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar19,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
      iVar19 = *(int *)puVar8;
    }
  }
  iVar19 = load_config(iVar19,0);
  if (iVar19 == 0) {
    iVar23 = 0;
    local_d0 = 0;
    iVar24 = 0;
    local_d8 = 0;
    iVar31 = 0;
    local_e4 = 0;
    iVar27 = 0;
    bVar2 = false;
    iVar13 = 0;
    local_fc = 0;
    iVar29 = 0;
    local_f0 = (char *)0x0;
    iVar19 = 0;
    local_dc = (char *)0x0;
    iVar22 = 1;
    local_d4 = (char *)0x0;
    local_e8 = (char *)0x0;
    local_f4 = 0;
    local_e0 = (char *)0x0;
    local_f8 = 0;
    local_100 = 0;
    local_104 = 0;
    goto LAB_0046cc80;
  }
  local_d0 = 0;
  local_80 = 0;
  local_84 = 3;
  local_a4 = 0;
  local_ac = (char *)0x0;
  iVar31 = 0;
  local_a0 = 6;
  uVar21 = 0;
  local_b0 = 6;
  local_a8 = 6;
  local_d8 = 0;
  local_e4 = 0;
  local_c4 = -1;
  local_dc = (char *)0x0;
  local_88 = 0;
  local_c8 = 0x40;
  bVar2 = false;
  local_d4 = (char *)0x0;
  local_e0 = (char *)0x0;
  local_60 = (char *)0x0;
  local_64 = (char *)0x0;
  local_68 = (char *)0x0;
  local_6c = (char *)0x0;
  local_70 = (char *)0x0;
  local_fc = 0;
  bVar5 = false;
  bVar6 = false;
  bVar4 = false;
  bVar3 = false;
  local_bc = 0;
  local_7c = (char *)0x0;
  local_90 = (char *)0x0;
  local_f0 = (char *)0x0;
  local_94 = (char *)0x0;
  local_100 = 0;
  local_104 = 0;
  local_e8 = (char *)0x0;
  local_c0 = (char *)0x0;
  local_b4 = (char *)0x0;
  local_98 = (char *)0x0;
  local_9c = (char *)0x0;
LAB_0046c610:
  uVar11 = local_4c;
  if (local_4c == 0) {
LAB_0046c618:
    ppcVar25 = local_54;
    pcVar28 = *local_54;
    if ((pcVar28 == (char *)0x0) || (*pcVar28 != '-')) goto LAB_0046c994;
    uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-encrypt");
    if (uVar11 == 0) {
      local_54 = ppcVar25 + 1;
      uVar21 = 0x11;
      goto LAB_0046c988;
    }
    uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-decrypt");
    if (uVar11 == 0) {
      local_54 = ppcVar25 + 1;
      uVar21 = 0x22;
      goto LAB_0046c988;
    }
    uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-sign");
    if (uVar11 == 0) {
      local_54 = ppcVar25 + 1;
      uVar21 = 0x53;
      goto LAB_0046c988;
    }
    uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-sign_receipt");
    if (uVar11 == 0) {
      local_54 = ppcVar25 + 1;
      uVar21 = 0x3f;
      goto LAB_0046c988;
    }
    uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-resign");
    if (uVar11 == 0) {
      local_54 = ppcVar25 + 1;
      uVar21 = 0x76;
      goto LAB_0046c988;
    }
    uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-verify");
    if (uVar11 == 0) {
      local_54 = ppcVar25 + 1;
      uVar21 = 0x24;
      goto LAB_0046c988;
    }
    uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-verify_retcode");
    if (uVar11 == 0) {
      local_54 = ppcVar25 + 1;
      bVar6 = true;
      goto LAB_0046c988;
    }
    uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-verify_receipt");
    if (uVar11 == 0) {
      local_b4 = ppcVar25[1];
      if (local_b4 == (char *)0x0) goto LAB_0046cf00;
      uVar21 = 0x30;
      local_54 = ppcVar25 + 2;
      goto LAB_0046c988;
    }
    uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-cmsout");
    if (uVar11 == 0) {
      local_54 = ppcVar25 + 1;
      uVar21 = 0x35;
      goto LAB_0046c988;
    }
    uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-data_out");
    if (uVar11 == 0) {
      local_54 = ppcVar25 + 1;
      uVar21 = 0x27;
      goto LAB_0046c988;
    }
    uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-data_create");
    if (uVar11 == 0) {
      local_54 = ppcVar25 + 1;
      uVar21 = 0x18;
      goto LAB_0046c988;
    }
    uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-digest_verify");
    if (uVar11 == 0) {
      local_54 = ppcVar25 + 1;
      uVar21 = 0x29;
      goto LAB_0046c988;
    }
    uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-digest_create");
    if (uVar11 == 0) {
      uVar21 = 0x1a;
      local_54 = ppcVar25;
    }
    else {
      uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-compress");
      if (uVar11 == 0) {
        uVar21 = 0x1c;
        local_54 = ppcVar25;
      }
      else {
        uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-uncompress");
        if (uVar11 == 0) {
          uVar21 = 0x2b;
          local_54 = ppcVar25;
        }
        else {
          uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-EncryptedData_decrypt");
          if (uVar11 == 0) {
            uVar21 = 0x2d;
            local_54 = ppcVar25;
          }
          else {
            uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-EncryptedData_encrypt");
            if (uVar11 == 0) {
              uVar21 = 0x1e;
              local_54 = ppcVar25;
            }
            else {
              iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-des3");
              pcVar30 = (code *)PTR_EVP_des_ede3_cbc_006a6e48;
              if (((((iVar19 == 0) ||
                    (iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,&DAT_0063a4ec),
                    pcVar30 = (code *)PTR_EVP_des_cbc_006a72a4, iVar19 == 0)) ||
                   (iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-seed"),
                   pcVar30 = (code *)PTR_EVP_seed_cbc_006a72b0, iVar19 == 0)) ||
                  ((iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-rc2-40"),
                   pcVar30 = (code *)PTR_EVP_rc2_40_cbc_006a7310, iVar19 == 0 ||
                   (iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-rc2-128"),
                   pcVar30 = (code *)PTR_EVP_rc2_cbc_006a730c, iVar19 == 0)))) ||
                 ((((iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-rc2-64"),
                    pcVar30 = (code *)PTR_EVP_rc2_64_cbc_006a7308, iVar19 == 0 ||
                    ((iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-aes128"),
                     pcVar30 = (code *)PTR_EVP_aes_128_cbc_006a72a8, iVar19 == 0 ||
                     (iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-aes192"),
                     pcVar30 = (code *)PTR_EVP_aes_192_cbc_006a72c0, iVar19 == 0)))) ||
                   (iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-aes256"),
                   pcVar30 = (code *)PTR_EVP_aes_256_cbc_006a72bc, iVar19 == 0)) ||
                  (((iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-camellia128"),
                    pcVar30 = (code *)PTR_EVP_camellia_128_cbc_006a72b8, iVar19 == 0 ||
                    (iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-camellia192"),
                    pcVar30 = (code *)PTR_EVP_camellia_192_cbc_006a72b4, iVar19 == 0)) ||
                   (iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-camellia256"),
                   pcVar30 = (code *)PTR_EVP_camellia_256_cbc_006a72c4, iVar19 == 0)))))) {
                local_bc = (*pcVar30)();
                uVar11 = local_4c;
              }
              else {
                uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-debug_decrypt");
                if (uVar11 == 0) {
                  local_c8 = local_c8 | 0x20000;
                  local_54 = ppcVar25;
                }
                else {
                  uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-text");
                  if (uVar11 == 0) {
                    local_c8 = local_c8 | 1;
                    local_54 = ppcVar25;
                  }
                  else {
                    uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-nointern");
                    if (uVar11 == 0) {
                      local_c8 = local_c8 | 0x10;
                      local_54 = ppcVar25;
                    }
                    else {
                      iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-noverify");
                      if ((iVar19 == 0) ||
                         (iVar19 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-no_signer_cert_verify"),
                         iVar19 == 0)) {
                        local_c8 = local_c8 | 0x20;
                        uVar11 = 0;
                        local_54 = ppcVar25;
                      }
                      else {
                        uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-nocerts");
                        if (uVar11 == 0) {
                          local_c8 = local_c8 | 2;
                          local_54 = ppcVar25;
                        }
                        else {
                          uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-noattr");
                          if (uVar11 == 0) {
                            local_c8 = local_c8 | 0x100;
                            local_54 = ppcVar25;
                          }
                          else {
                            uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-nodetach");
                            if (uVar11 == 0) {
                              local_c8 = local_c8 & 0xffffffbf;
                              local_54 = ppcVar25;
                            }
                            else {
                              uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-nosmimecap");
                              if (uVar11 == 0) {
                                local_c8 = local_c8 | 0x200;
                                local_54 = ppcVar25;
                              }
                              else {
                                uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-binary");
                                if (uVar11 == 0) {
                                  local_c8 = local_c8 | 0x80;
                                  local_54 = ppcVar25;
                                }
                                else {
                                  uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-keyid");
                                  if (uVar11 == 0) {
                                    local_c8 = local_c8 | 0x10000;
                                    local_54 = ppcVar25;
                                  }
                                  else {
                                    uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-nosigs");
                                    if (uVar11 == 0) {
                                      local_c8 = local_c8 | 0xc;
                                      local_54 = ppcVar25;
                                    }
                                    else {
                                      uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                         (pcVar28,"-no_content_verify");
                                      if (uVar11 == 0) {
                                        local_c8 = local_c8 | 4;
                                        local_54 = ppcVar25;
                                      }
                                      else {
                                        uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                           (pcVar28,"-no_attr_verify");
                                        if (uVar11 == 0) {
                                          local_c8 = local_c8 | 8;
                                          local_54 = ppcVar25;
                                        }
                                        else {
                                          uVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar28,"-stream")
                                          ;
                                          if ((uVar11 == 0) ||
                                             (uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                 (pcVar28,"-indef"), uVar11 == 0)) {
                                            local_c8 = local_c8 | 0x1000;
                                            local_54 = ppcVar25;
                                          }
                                          else {
                                            uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                               (pcVar28,"-noindef");
                                            if (uVar11 == 0) {
                                              local_c8 = local_c8 & 0xffffefff;
                                              local_54 = ppcVar25;
                                            }
                                            else {
                                              uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                 (pcVar28,"-nooldmime");
                                              if (uVar11 == 0) {
                                                local_c8 = local_c8 | 0x400;
                                                local_54 = ppcVar25;
                                              }
                                              else {
                                                uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                   (pcVar28,"-crlfeol");
                                                if (uVar11 == 0) {
                                                  local_c8 = local_c8 | 0x800;
                                                  local_54 = ppcVar25;
                                                }
                                                else {
                                                  uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                     (pcVar28,"-noout");
                                                  if (uVar11 == 0) {
                                                    bVar3 = true;
                                                    local_54 = ppcVar25;
                                                  }
                                                  else {
                                                    uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar28,
                                                  "-receipt_request_print");
                                                  if (uVar11 == 0) {
                                                    bVar5 = true;
                                                    local_54 = ppcVar25;
                                                  }
                                                  else {
                                                    uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar28,
                                                  "-receipt_request_all");
                                                  if (uVar11 == 0) {
                                                    local_c4 = 0;
                                                    local_54 = ppcVar25;
                                                  }
                                                  else {
                                                    uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar28,
                                                  "-receipt_request_first");
                                                  if (uVar11 == 0) {
                                                    local_c4 = 1;
                                                    local_54 = ppcVar25;
                                                  }
                                                  else {
                                                    iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar28,
                                                  "-receipt_request_from");
                                                  if (iVar19 == 0) {
                                                    if (ppcVar25[1] == (char *)0x0)
                                                    goto LAB_0046cf00;
                                                    local_54 = ppcVar25 + 1;
                                                    iVar19 = local_fc;
                                                    if (local_fc == 0) {
                                                      local_fc = (*(code *)PTR_sk_new_null_006a6fa4)
                                                                           ();
                                                      iVar19 = local_fc;
                                                    }
                                                  }
                                                  else {
                                                    iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar28,
                                                  "-receipt_request_to");
                                                  if (iVar19 != 0) {
                                                    uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar28,"-print");
                                                    if (uVar11 == 0) {
                                                      bVar4 = true;
                                                      bVar3 = true;
                                                      local_54 = ppcVar25;
                                                    }
                                                    else {
                                                      iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (pcVar28,"-secretkey");
                                                      if (iVar19 == 0) {
                                                        if (ppcVar25[1] == (char *)0x0)
                                                        goto LAB_0046cf00;
                                                        local_54 = ppcVar25 + 1;
                                                        local_e4 = (*(code *)
                                                  PTR_string_to_hex_006a738c)(ppcVar25[1],&local_30)
                                                  ;
                                                  if (local_e4 == 0) {
                                                    (*(code *)PTR_BIO_printf_006a6e38)
                                                              (*(undefined4 *)puVar8,
                                                               "Invalid key %s\n",*local_54);
                                                    goto LAB_0046cf00;
                                                  }
                                                  local_a4 = local_30;
                                                  uVar11 = local_4c;
                                                  }
                                                  else {
                                                    iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar28,"-secretkeyid");
                                                    if (iVar19 == 0) {
                                                      if (ppcVar25[1] == (char *)0x0)
                                                      goto LAB_0046cf00;
                                                      local_54 = ppcVar25 + 1;
                                                      local_d8 = (*(code *)
                                                  PTR_string_to_hex_006a738c)(ppcVar25[1],&local_30)
                                                  ;
                                                  if (local_d8 == 0) {
                                                    (*(code *)PTR_BIO_printf_006a6e38)
                                                              (*(undefined4 *)puVar8,
                                                               "Invalid id %s\n",*local_54);
                                                    goto LAB_0046cf00;
                                                  }
                                                  local_80 = local_30;
                                                  uVar11 = local_4c;
                                                  }
                                                  else {
                                                    uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar28,"-pwri_password");
                                                    if (uVar11 == 0) {
                                                      local_ac = ppcVar25[1];
                                                      pcVar28 = local_ac;
                                                      goto joined_r0x0046f6c8;
                                                    }
                                                    iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar28,"-econtent_type");
                                                    if (iVar19 == 0) {
                                                      if (ppcVar25[1] == (char *)0x0)
                                                      goto LAB_0046cf00;
                                                      local_54 = ppcVar25 + 1;
                                                      local_d0 = (*(code *)PTR_OBJ_txt2obj_006a7000)
                                                                           (ppcVar25[1],0);
                                                      uVar11 = local_4c;
                                                      if (local_d0 == 0) {
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar8,
                                                                   "Invalid OID %s\n",*local_54);
                                                        goto LAB_0046cf00;
                                                      }
                                                    }
                                                    else {
                                                      uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (pcVar28,"-rand");
                                                      if (uVar11 == 0) {
                                                        local_d4 = ppcVar25[1];
                                                        if (local_d4 != (char *)0x0) {
                                                          bVar2 = true;
                                                          local_54 = ppcVar25 + 1;
                                                          goto LAB_0046c980;
                                                        }
                                                        goto LAB_0046cf00;
                                                      }
                                                      uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (pcVar28,"-engine");
                                                      if (uVar11 == 0) {
                                                        local_dc = ppcVar25[1];
                                                        pcVar28 = local_dc;
                                                      }
                                                      else {
                                                        uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (pcVar28,"-passin");
                                                        if (uVar11 == 0) {
                                                          local_e0 = ppcVar25[1];
                                                          pcVar28 = local_e0;
                                                        }
                                                        else {
                                                          cVar1 = pcVar28[1];
                                                          if (((cVar1 == 't') && (pcVar28[2] == 'o')
                                                              ) && (pcVar28[3] == '\0')) {
                                                            local_70 = ppcVar25[1];
                                                            pcVar28 = local_70;
joined_r0x0046f330:
                                                            if (pcVar28 != (char *)0x0) {
                                                              uVar11 = 0;
                                                              local_54 = ppcVar25 + 1;
                                                              goto LAB_0046c980;
                                                            }
                                                            goto LAB_0046cf00;
                                                          }
                                                          uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (pcVar28,"-from");
                                                          if (uVar11 == 0) {
                                                            local_6c = ppcVar25[1];
                                                            pcVar28 = local_6c;
                                                          }
                                                          else {
                                                            uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (pcVar28,"-subject");
                                                            if (uVar11 == 0) {
                                                              local_68 = ppcVar25[1];
                                                              pcVar28 = local_68;
                                                            }
                                                            else {
                                                              iVar19 = (*(code *)PTR_strcmp_006a9b18
                                                                       )(pcVar28,"-signer");
                                                              if (iVar19 == 0) {
                                                                if (ppcVar25[1] != (char *)0x0) {
                                                                  if (local_c0 != (char *)0x0) {
                                                                    if (local_104 == 0) {
                                                                      local_104 = (*(code *)
                                                  PTR_sk_new_null_006a6fa4)();
                                                  }
                                                  if (local_f0 == (char *)0x0) {
                                                    local_f0 = local_c0;
                                                  }
                                                  (*(code *)PTR_sk_push_006a6fa8)
                                                            (local_104,local_c0);
                                                  if (local_100 == 0) {
                                                    local_100 = (*(code *)PTR_sk_new_null_006a6fa4)
                                                                          ();
                                                  }
                                                  (*(code *)PTR_sk_push_006a6fa8)
                                                            (local_100,local_f0);
                                                  local_f0 = (char *)0x0;
                                                  ppcVar25 = local_54;
                                                  }
                                                  local_c0 = ppcVar25[1];
                                                  uVar11 = local_4c;
                                                  local_54 = ppcVar25 + 1;
                                                  goto LAB_0046c980;
                                                  }
                                                  goto LAB_0046cf00;
                                                  }
                                                  uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                     (pcVar28,"-recip");
                                                  if (uVar11 == 0) {
                                                    local_e8 = ppcVar25[1];
                                                    pcVar28 = local_e8;
                                                  }
                                                  else {
                                                    uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar28,"-certsout");
                                                    if (uVar11 != 0) {
                                                      if (((cVar1 == 'm') && (pcVar28[2] == 'd')) &&
                                                         (pcVar28[3] == '\0')) {
                                                        if (ppcVar25[1] != (char *)0x0) {
                                                          local_54 = ppcVar25 + 1;
                                                          local_88 = (*(code *)
                                                  PTR_EVP_get_digestbyname_006a6f2c)();
                                                  uVar11 = local_4c;
                                                  if (local_88 != 0) goto LAB_0046c980;
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar8,
                                                             "Unknown digest %s\n",*local_54);
                                                  }
                                                  goto LAB_0046cf00;
                                                  }
                                                  iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                     (pcVar28,"-inkey");
                                                  if (iVar19 == 0) {
                                                    if (ppcVar25[1] == (char *)0x0)
                                                    goto LAB_0046cf00;
                                                    if (local_f0 != (char *)0x0) {
                                                      if (local_c0 == (char *)0x0)
                                                      goto LAB_0046d9a0;
                                                      if (local_104 == 0) {
                                                        local_104 = (*(code *)
                                                  PTR_sk_new_null_006a6fa4)();
                                                  }
                                                  (*(code *)PTR_sk_push_006a6fa8)
                                                            (local_104,local_c0);
                                                  if (local_100 == 0) {
                                                    local_100 = (*(code *)PTR_sk_new_null_006a6fa4)
                                                                          ();
                                                  }
                                                  (*(code *)PTR_sk_push_006a6fa8)
                                                            (local_100,local_f0);
                                                  local_c0 = (char *)0x0;
                                                  ppcVar25 = local_54;
                                                  }
                                                  local_f0 = ppcVar25[1];
                                                  uVar11 = local_4c;
                                                  local_54 = ppcVar25 + 1;
                                                  }
                                                  else {
                                                    iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar28,"-keyform");
                                                    if (iVar19 == 0) {
                                                      if (ppcVar25[1] == (char *)0x0)
                                                      goto LAB_0046cf00;
                                                      local_54 = ppcVar25 + 1;
                                                      local_84 = str2fmt();
                                                      uVar11 = local_4c;
                                                    }
                                                    else {
                                                      iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (pcVar28,"-rctform");
                                                      if (iVar19 != 0) {
                                                        uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (pcVar28,"-certfile");
                                                        if (uVar11 == 0) {
                                                          local_94 = ppcVar25[1];
                                                          pcVar28 = local_94;
                                                        }
                                                        else {
                                                          uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (pcVar28,"-CAfile");
                                                          if (uVar11 == 0) {
                                                            local_64 = ppcVar25[1];
                                                            pcVar28 = local_64;
                                                          }
                                                          else {
                                                            uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (pcVar28,"-CApath");
                                                            if (uVar11 == 0) {
                                                              local_60 = ppcVar25[1];
                                                              pcVar28 = local_60;
                                                              goto joined_r0x0046f6c8;
                                                            }
                                                            if (((cVar1 == 'i') &&
                                                                (pcVar28[2] == 'n')) &&
                                                               (pcVar28[3] == '\0')) {
                                                              local_9c = ppcVar25[1];
                                                              pcVar28 = local_9c;
                                                              goto joined_r0x0046f330;
                                                            }
                                                            iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (pcVar28,"-inform");
                                                            if (iVar19 == 0) {
                                                              if (ppcVar25[1] == (char *)0x0)
                                                              goto LAB_0046cf00;
                                                              local_54 = ppcVar25 + 1;
                                                              local_a8 = str2fmt();
                                                              uVar11 = local_4c;
                                                              goto LAB_0046c980;
                                                            }
                                                            iVar19 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (pcVar28,"-outform");
                                                            if (iVar19 == 0) {
                                                              if (ppcVar25[1] != (char *)0x0) {
                                                                local_54 = ppcVar25 + 1;
                                                                local_b0 = str2fmt();
                                                                uVar11 = local_4c;
                                                                goto LAB_0046c980;
                                                              }
                                                              goto LAB_0046cf00;
                                                            }
                                                            uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (pcVar28,&
                                                  DAT_00632514);
                                                  if (uVar11 != 0) {
                                                    uVar11 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar28,"-content");
                                                    if (uVar11 == 0) {
                                                      local_90 = ppcVar25[1];
                                                      pcVar28 = local_90;
                                                      goto joined_r0x0046f6c8;
                                                    }
                                                    iVar19 = args_verify(&local_54,0,&local_4c,
                                                                         *(undefined4 *)puVar8,
                                                                         &local_44);
                                                    if (iVar19 == 0) {
                                                      local_bc = (*(code *)
                                                  PTR_EVP_get_cipherbyname_006a7394)(*local_54 + 1);
                                                  uVar11 = local_4c;
                                                  if (local_bc == 0) {
                                                    local_4c = 1;
                                                    uVar11 = 1;
                                                  }
                                                  goto LAB_0046c980;
                                                  }
                                                  goto LAB_0046c610;
                                                  }
                                                  local_98 = ppcVar25[1];
                                                  pcVar28 = local_98;
                                                  }
                                                  }
                                                  goto joined_r0x0046f6c8;
                                                  }
                                                  if (ppcVar25[1] == (char *)0x0) goto LAB_0046cf00;
                                                  local_54 = ppcVar25 + 1;
                                                  local_a0 = str2fmt();
                                                  uVar11 = local_4c;
                                                  }
                                                  }
                                                  goto LAB_0046c980;
                                                  }
                                                  local_7c = ppcVar25[1];
                                                  pcVar28 = local_7c;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
joined_r0x0046f6c8:
                                                  if (pcVar28 == (char *)0x0) goto LAB_0046cf00;
                                                  local_54 = ppcVar25 + 1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_0046c980;
                                                  }
                                                  if (ppcVar25[1] == (char *)0x0) goto LAB_0046cf00;
                                                  local_54 = ppcVar25 + 1;
                                                  iVar19 = iVar31;
                                                  if (iVar31 == 0) {
                                                    iVar19 = (*(code *)PTR_sk_new_null_006a6fa4)();
                                                    iVar31 = iVar19;
                                                  }
                                                  }
                                                  (*(code *)PTR_sk_push_006a6fa8)(iVar19,*local_54);
                                                  uVar11 = local_4c;
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
              }
            }
          }
        }
      }
    }
LAB_0046c980:
    local_54 = local_54 + 1;
LAB_0046c988:
    if (uVar11 != 0) goto LAB_0046c994;
    goto LAB_0046c618;
  }
LAB_0046c994:
  if ((local_c4 == -1) && (local_fc == 0)) {
    if ((uVar21 & 0x40) != 0) goto LAB_0046c9b8;
    if (iVar31 == 0) {
      if ((local_100 != 0) || (local_104 != 0)) {
        (*(code *)PTR_BIO_puts_006a6f58)
                  (*(undefined4 *)puVar8,"Multiple signers or keys not allowed\n");
        goto LAB_0046cf00;
      }
      puVar7 = (undefined4 *)PTR_bio_err_006a6e3c;
      if (uVar21 == 0x22) {
        if ((((local_e8 == (char *)0x0) && (local_f0 == (char *)0x0)) && (local_e4 == 0)) &&
           (local_ac == (char *)0x0)) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar8,"No recipient certificate or key specified\n");
          local_104 = 0;
          local_4c = 1;
          goto LAB_0046cf00;
        }
      }
      else if (uVar21 == 0x11) {
        if ((*local_54 == (char *)0x0) && (local_e4 == 0)) {
          bVar2 = true;
          if (local_ac == (char *)0x0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar8,"No recipient(s) certificate(s) specified\n");
            local_4c = 1;
            local_104 = 0;
            goto LAB_0046cf00;
          }
        }
        else {
          bVar2 = true;
        }
      }
      else if (uVar21 == 0) {
        local_104 = 0;
        local_4c = 1;
        goto LAB_0046cf00;
      }
      goto joined_r0x0046ca24;
    }
LAB_0046cee4:
    (*(code *)PTR_BIO_puts_006a6f58)
              (*(undefined4 *)puVar8,"Signed receipts only allowed with -sign\n");
LAB_0046cf00:
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"Usage cms [options] cert.pem ...\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"where options are\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"-encrypt       encrypt message\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-decrypt       decrypt encrypted message\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"-sign          sign message\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-verify        verify signed message\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-cmsout        output CMS structure\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-des3          encrypt with triple DES\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"-des           encrypt with DES\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"-seed          encrypt with SEED\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-rc2-40        encrypt with RC2-40 (default)\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"-rc2-64        encrypt with RC2-64\n")
    ;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-rc2-128       encrypt with RC2-128\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"-aes128, -aes192, -aes256\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"               encrypt PEM output with cbc aes\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-camellia128, -camellia192, -camellia256\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"               encrypt PEM output with cbc camellia\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,
               "-nointern      don\'t search certificates in message for signer\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-nosigs        don\'t verify message signature\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-noverify      don\'t verify signers certificate\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,
               "-nocerts       don\'t include signers certificate when signing\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"-nodetach      use opaque signing\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-noattr        don\'t include any signed attributes\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-binary        don\'t translate message to text\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-certfile file other certificates file\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-certsout file certificate output file\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-signer file   signer certificate file\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-recip  file   recipient certificate file for decryption\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-keyid         use subject key identifier\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"-in file       input file\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-inform arg    input format SMIME (default), PEM or DER\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,
               "-inkey file    input private key (if not signer or recipient)\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-keyform arg   input private key format (PEM or ENGINE)\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"-out file      output file\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-outform arg   output format SMIME (default), PEM or DER\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,
               "-content file  supply or override content for detached signature\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"-to addr       to address\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"-from ad       from address\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"-subject s     subject\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-text          include or delete text MIME headers\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-CApath dir    trusted certificates directory\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-CAfile file   trusted certificates file\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,
               "-no_alt_chains only ever use the first certificate chain found\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,
               "-crl_check     check revocation status of signer\'s certificate using CRLs\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,
               "-crl_check_all check revocation status of signer\'s certificate chain using CRLs\n")
    ;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-engine e      use engine e, possibly a hardware device.\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"-passin arg    input file pass phrase source\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"-rand file%cfile%c...\n",0x3a,0x3a);
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,
               "               load the file (or the files in the directory) into\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar8,"               the random number generator\n");
    uVar12 = *(undefined4 *)puVar8;
    pcVar28 = "cert.pem       recipient certificate(s) for encryption\n";
  }
  else {
    if (iVar31 == 0) {
      (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar8,"No Signed Receipts Recipients\n");
      goto LAB_0046cf00;
    }
    if ((uVar21 & 0x40) == 0) goto LAB_0046cee4;
LAB_0046c9b8:
    if (local_f0 == (char *)0x0) {
      if (local_c0 != (char *)0x0) goto LAB_0046c9c8;
    }
    else {
      if (local_c0 == (char *)0x0) {
LAB_0046d9a0:
        (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar8,"Illegal -inkey without -signer\n");
        goto LAB_0046cf00;
      }
LAB_0046c9c8:
      if (local_104 == 0) {
        local_104 = (*(code *)PTR_sk_new_null_006a6fa4)();
      }
      (*(code *)PTR_sk_push_006a6fa8)(local_104,local_c0);
      if (local_100 == 0) {
        local_100 = (*(code *)PTR_sk_new_null_006a6fa4)();
      }
      if (local_f0 != (char *)0x0) {
        local_c0 = local_f0;
      }
      (*(code *)PTR_sk_push_006a6fa8)(local_100,local_c0);
    }
    if (local_104 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"No signer certificate specified\n");
      local_104 = 0;
      bVar2 = true;
      local_4c = 1;
      goto LAB_0046cf00;
    }
    local_f0 = (char *)0x0;
    local_c0 = (char *)0x0;
    bVar2 = true;
    uVar11 = local_4c;
    puVar7 = (undefined4 *)PTR_bio_err_006a6e3c;
joined_r0x0046ca24:
    PTR_bio_err_006a6e3c = (undefined *)puVar7;
    if (uVar11 != 0) goto LAB_0046cf00;
    uVar12 = setup_engine(*(undefined4 *)puVar8,local_dc,0);
    iVar19 = app_passwd(*(undefined4 *)puVar8,local_e0,0,&local_48,0);
    if (iVar19 != 0) {
      if ((bVar2) &&
         (app_RAND_load_file(0,*puVar7,local_d4 != (char *)0x0), local_d4 != (char *)0x0)) {
        uVar17 = *puVar7;
        uVar16 = app_RAND_load_files(local_d4);
        (*(code *)PTR_BIO_printf_006a6e38)(uVar17,"%ld semi-random bytes loaded\n",uVar16);
      }
      if ((uVar21 & 0x40) == 0) {
        local_c8 = local_c8 & 0xffffffbf;
      }
      if ((uVar21 & 0x10) == 0) {
        if ((local_c8 & 0x80) == 0) {
          if ((uVar21 & 0x20) == 0) {
            pcVar28 = "w";
LAB_0046d914:
            pcVar26 = "r";
            goto LAB_0046d6fc;
          }
          pcVar28 = "w";
          goto LAB_0046cad0;
        }
        if ((uVar21 & 0x20) != 0) {
          pcVar28 = "wb";
          goto LAB_0046cad0;
        }
        pcVar28 = "wb";
        pcVar26 = "rb";
LAB_0046d6fc:
        if (uVar21 != 0x11) goto LAB_0046cae8;
        if (local_bc == 0) {
          local_bc = (*(code *)PTR_EVP_des_ede3_cbc_006a6e48)();
        }
        if ((local_e4 == 0) || (local_d8 != 0)) {
          if (*local_54 == (char *)0x0) goto LAB_0046cae8;
          local_d4 = (char *)(*(code *)PTR_sk_new_null_006a6fa4)();
          pcVar20 = *local_54;
          while (pcVar20 != (char *)0x0) {
            iVar19 = load_cert(*(undefined4 *)puVar8,pcVar20,3,0,uVar12,"recipient certificate file"
                              );
            if (iVar19 == 0) {
              local_dc = (char *)0x0;
              goto LAB_0046d7dc;
            }
            (*(code *)PTR_sk_push_006a6fa8)(local_d4,iVar19);
            pcVar20 = local_54[1];
            local_54 = local_54 + 1;
          }
          goto LAB_0046caec;
        }
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"No secret key id\n");
        local_dc = (char *)0x0;
        local_d4 = (char *)0x0;
LAB_0046d7dc:
        local_f4 = 0;
LAB_0046d7e4:
        local_e8 = (char *)0x0;
        local_f0 = (char *)0x0;
        iVar13 = 0;
        iVar27 = 0;
        iVar24 = 0;
        iVar23 = 0;
        local_e0 = (char *)0x0;
        iVar29 = 0;
        local_f8 = 0;
        iVar19 = 0;
        iVar22 = 2;
        goto LAB_0046cc80;
      }
      if (local_b0 == 1) {
        pcVar28 = "wb";
      }
      else {
        pcVar28 = "w";
      }
      if ((uVar21 & 0x20) == 0) {
        if ((local_c8 & 0x80) == 0) goto LAB_0046d914;
        pcVar26 = "rb";
        goto LAB_0046d6fc;
      }
LAB_0046cad0:
      uVar11 = uVar21 & 0x20;
      if (local_a8 == 1) {
        pcVar26 = "rb";
      }
      else {
        pcVar26 = "r";
      }
LAB_0046cae8:
      local_d4 = (char *)0x0;
LAB_0046caec:
      if (local_94 == (char *)0x0) {
        local_dc = (char *)0x0;
      }
      else {
        local_dc = (char *)load_certs(*(undefined4 *)puVar8,local_94,3,0,uVar12,"certificate file");
        if (local_dc == (char *)0x0) {
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
          goto LAB_0046d7dc;
        }
      }
      if (local_e8 == (char *)0x0) {
        if (uVar21 == 0x3f) {
LAB_0046d9f4:
          local_f4 = load_cert(*(undefined4 *)puVar8,local_c0,3,0,uVar12,
                               "receipt signer certificate file");
          if (local_f4 == 0) {
            (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
            goto LAB_0046d7e4;
          }
LAB_0046d580:
          if (local_f0 == (char *)0x0) {
            if (local_c0 != (char *)0x0) {
              local_e0 = (char *)0x0;
              local_e8 = local_c0;
              goto LAB_0046d594;
            }
            goto LAB_0046cb64;
          }
        }
        else {
          if (uVar21 != 0x22) goto LAB_0046cb54;
          if (local_f0 == (char *)0x0) goto LAB_0046cb60;
          local_f4 = 0;
        }
        local_e0 = (char *)0x0;
        local_e8 = local_f0;
LAB_0046d594:
        local_e8 = (char *)load_key(*(undefined4 *)puVar8,local_e8,local_84,0,local_48,uVar12,
                                    "signing key file");
        if (local_e8 == (char *)0x0) {
          iVar23 = 0;
          local_f0 = (char *)0x0;
          iVar24 = 0;
          local_f8 = 0;
          iVar27 = 0;
          iVar13 = 0;
          iVar29 = 0;
          iVar19 = 0;
          iVar22 = 2;
          goto LAB_0046cc80;
        }
      }
      else {
        if (uVar21 == 0x22) {
          local_e0 = (char *)load_cert(*(undefined4 *)puVar8,local_e8,3,0,uVar12,
                                       "recipient certificate file");
          if (local_e0 == (char *)0x0) {
            iVar23 = 0;
            iVar24 = 0;
            iVar27 = 0;
            iVar13 = 0;
            iVar29 = 0;
            iVar19 = 0;
            iVar22 = 2;
            (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
            local_f0 = (char *)0x0;
            local_e8 = (char *)0x0;
            local_f4 = 0;
            local_f8 = 0;
            goto LAB_0046cc80;
          }
          local_f4 = 0;
          if (local_f0 != (char *)0x0) {
            local_e8 = local_f0;
          }
          goto LAB_0046d594;
        }
        if (uVar21 == 0x3f) goto LAB_0046d9f4;
LAB_0046cb54:
        if (uVar21 == 0x53) {
          local_f4 = 0;
          goto LAB_0046d580;
        }
LAB_0046cb60:
        local_f4 = 0;
LAB_0046cb64:
        local_e0 = (char *)0x0;
        local_e8 = (char *)0x0;
      }
      if (local_9c != (char *)0x0) {
        iVar13 = (*(code *)PTR_BIO_new_file_006a6eac)(local_9c,pcVar26);
        if (iVar13 != 0) goto LAB_0046cb98;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar8,"Can\'t open input file %s\n",local_9c);
LAB_0046cbd0:
        iVar23 = 0;
        local_f0 = (char *)0x0;
        iVar24 = 0;
        local_f8 = 0;
        iVar27 = 0;
        iVar29 = 0;
        iVar19 = 0;
        iVar22 = 2;
        goto LAB_0046cc80;
      }
      iVar13 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14,0);
LAB_0046cb98:
      if (uVar11 == 0) {
        iVar19 = 0;
      }
      else {
        if (local_a8 == 6) {
          iVar19 = (*(code *)PTR_SMIME_read_CMS_006a72d8)(iVar13,&local_50);
        }
        else if (local_a8 == 3) {
          iVar19 = (*(code *)PTR_PEM_read_bio_CMS_006a7304)(iVar13,0,0,0);
        }
        else {
          if (local_a8 != 1) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar8,"Bad input format for CMS file\n");
            goto LAB_0046cbd0;
          }
          iVar19 = (*(code *)PTR_d2i_CMS_bio_006a72dc)(iVar13,0);
        }
        if (iVar19 == 0) {
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"Error reading S/MIME message\n")
          ;
          goto LAB_0046db5c;
        }
        if (local_90 != (char *)0x0) {
          (*(code *)PTR_BIO_free_006a6e70)(local_50);
          local_50 = (*(code *)PTR_BIO_new_file_006a6eac)(local_90,&DAT_00633e40);
          if (local_50 == 0) goto LAB_0046e648;
        }
        if (local_7c != (char *)0x0) {
          uVar16 = (*(code *)PTR_CMS_get1_certs_006a7300)(iVar19);
          iVar27 = save_certs(local_7c,uVar16);
          if (iVar27 == 0) {
            iVar23 = 0;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar8,"Error writing certs to %s\n",local_7c);
            iVar24 = 0;
            iVar27 = 0;
            local_f0 = (char *)0x0;
            iVar29 = 0;
            local_f8 = 0;
            iVar22 = 5;
            goto LAB_0046cc80;
          }
          (*(code *)PTR_sk_pop_free_006a7058)(uVar16,PTR_X509_free_006a6e90);
        }
      }
      if (local_b4 == (char *)0x0) {
        local_f0 = (char *)0x0;
        local_f8 = 0;
      }
      else {
        if (local_a0 == 1) {
          local_f0 = (char *)(*(code *)PTR_BIO_new_file_006a6eac)(local_b4,&DAT_00633e40);
          if (local_f0 == (char *)0x0) goto LAB_0046db3c;
          local_f8 = (*(code *)PTR_d2i_CMS_bio_006a72dc)(local_f0,0);
        }
        else {
          local_f0 = (char *)(*(code *)PTR_BIO_new_file_006a6eac)(local_b4,"r");
          if (local_f0 == (char *)0x0) {
LAB_0046db3c:
            uVar12 = *(undefined4 *)puVar8;
            pcVar28 = "Can\'t open receipt file %s\n";
            goto LAB_0046db50;
          }
          if (local_a0 == 6) {
            local_f8 = (*(code *)PTR_SMIME_read_CMS_006a72d8)(local_f0,0);
          }
          else {
            if (local_a0 != 3) {
              iVar23 = 0;
              iVar24 = 0;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar8,"Bad input format for receipt\n");
              iVar27 = 0;
              iVar29 = 0;
              local_f8 = 0;
              iVar22 = 2;
              goto LAB_0046cc80;
            }
            local_f8 = (*(code *)PTR_PEM_read_bio_CMS_006a7304)(local_f0,0,0,0);
          }
        }
        if (local_f8 == 0) {
          iVar23 = 0;
          iVar24 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"Error reading receipt\n");
          iVar27 = 0;
          iVar29 = 0;
          iVar22 = 2;
          goto LAB_0046cc80;
        }
      }
      if (local_98 == (char *)0x0) {
        iVar27 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
      }
      else {
        iVar27 = (*(code *)PTR_BIO_new_file_006a6eac)(local_98,pcVar28);
        if (iVar27 == 0) {
          iVar23 = 0;
          iVar24 = 0;
          iVar29 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar8,"Can\'t open output file %s\n",local_98);
          iVar22 = 2;
          goto LAB_0046cc80;
        }
      }
      if ((uVar21 == 0x24) || (uVar21 == 0x30)) {
        iVar29 = setup_verify(*(undefined4 *)puVar8,local_64,local_60);
        if (iVar29 == 0) {
          iVar23 = 0;
          iVar24 = 0;
          iVar22 = 2;
          goto LAB_0046cc80;
        }
        (*(code *)PTR_X509_STORE_set_verify_cb_006a72f8)(iVar29,cms_cb);
        if (local_44 != 0) {
          (*(code *)PTR_X509_STORE_set1_param_006a72fc)(iVar29);
        }
      }
      else {
        iVar29 = 0;
      }
      if (uVar21 != 0x18) {
        pcVar30 = (code *)PTR_CMS_digest_create_006a7378;
        if (uVar21 == 0x1a) {
LAB_0046ec0c:
          iVar19 = (*pcVar30)(iVar13,local_88,local_c8);
          iVar24 = 0;
          goto LAB_0046e854;
        }
        if (uVar21 == 0x1c) {
          local_88 = -1;
          pcVar30 = (code *)PTR_CMS_compress_006a7374;
          goto LAB_0046ec0c;
        }
        if (uVar21 == 0x11) {
          uVar11 = local_c8 | 0x4000;
          iVar19 = (*(code *)PTR_CMS_encrypt_006a734c)(local_d4,iVar13,local_bc,uVar11);
          if (iVar19 == 0) {
LAB_0046ea4c:
            iVar23 = 0;
            iVar24 = 0;
            iVar22 = 3;
            goto LAB_0046cc80;
          }
          if (local_e4 != 0) {
            iVar23 = (*(code *)PTR_CMS_add0_recipient_key_006a7350)
                               (iVar19,0,local_e4,local_a4,local_d8,local_80,0,0,0);
            if (iVar23 == 0) goto LAB_0046ea4c;
            local_d8 = 0;
          }
          if ((local_ac != (char *)0x0) &&
             ((iVar23 = (*(code *)PTR_BUF_strdup_006a6fdc)(local_ac), iVar23 == 0 ||
              (iVar24 = (*(code *)PTR_CMS_add0_recipient_password_006a7354)
                                  (iVar19,0xffffffff,0,0,iVar23,0xffffffff,0), iVar24 == 0)))) {
LAB_0046ea7c:
            local_e4 = 0;
            iVar24 = 0;
            iVar22 = 3;
            goto LAB_0046cc80;
          }
          if (((local_c8 & 0x1000) == 0) &&
             (iVar23 = (*(code *)PTR_CMS_final_006a72f0)(iVar19,iVar13,0,uVar11), iVar23 == 0)) {
            iVar23 = 0;
            goto LAB_0046ea7c;
          }
          local_e4 = 0;
LAB_0046e81c:
          iVar24 = 0;
          local_c8 = uVar11;
          goto LAB_0046de2c;
        }
        if (uVar21 == 0x1e) {
          iVar24 = 0;
          iVar19 = (*(code *)PTR_CMS_EncryptedData_encrypt_006a7348)
                             (iVar13,local_bc,local_e4,local_a4,local_c8);
          goto LAB_0046e854;
        }
        if (uVar21 == 0x3f) {
          iVar23 = (*(code *)PTR_CMS_get0_SignerInfos_006a72e4)(iVar19);
          if (iVar23 != 0) {
            uVar12 = (*(code *)PTR_sk_value_006a6e24)(iVar23,0);
            iVar23 = (*(code *)PTR_CMS_sign_receipt_006a7344)
                               (uVar12,local_f4,local_e8,local_dc,local_c8);
            if (iVar23 != 0) {
              (*(code *)PTR_CMS_ContentInfo_free_006a72d4)(iVar19);
              uVar11 = local_c8;
              iVar19 = iVar23;
              goto LAB_0046e81c;
            }
          }
          goto LAB_0046ea4c;
        }
        iVar24 = 0;
        if ((uVar21 & 0x40) != 0) {
          if (uVar21 == 0x53) {
            if (((local_c8 & 0x40) != 0) && (local_b0 == 6)) {
              local_c8 = local_c8 | 0x1000;
            }
            local_c8 = local_c8 | 0x4000;
            iVar19 = (*(code *)PTR_CMS_sign_006a7358)(0,0,local_dc,iVar13,local_c8);
            if (iVar19 == 0) goto LAB_0046ea4c;
            if (local_d0 != 0) {
              (*(code *)PTR_CMS_set1_eContentType_006a735c)(iVar19,local_d0);
            }
            iVar24 = 0;
            if (iVar31 != 0) {
              iVar23 = make_names_stack(iVar31);
              if (iVar23 != 0) {
                if (local_fc == 0) {
                  iVar24 = 0;
                }
                else {
                  iVar24 = make_names_stack(local_fc);
                  if (iVar24 == 0) goto LAB_0046ea34;
                }
                iVar24 = (*(code *)PTR_CMS_ReceiptRequest_create0_006a7360)
                                   (0,0xffffffff,local_c4,iVar24,iVar23);
                if (iVar24 != 0) goto LAB_0046dc2c;
              }
LAB_0046ea34:
              (*(code *)PTR_BIO_puts_006a6f58)
                        (*(undefined4 *)puVar8,"Signed Receipt Request Creation Error\n");
              goto LAB_0046ea4c;
            }
          }
          else {
            iVar24 = 0;
            local_c8 = local_c8 | 0x8000;
          }
LAB_0046dc2c:
          puVar9 = PTR_bio_err_006a6e3c;
          for (iVar23 = 0; iVar22 = (*(code *)PTR_sk_num_006a6e2c)(local_104), iVar23 < iVar22;
              iVar23 = iVar23 + 1) {
            local_c0 = (char *)(*(code *)PTR_sk_value_006a6e24)(local_104,iVar23);
            uVar16 = (*(code *)PTR_sk_value_006a6e24)(local_100,iVar23);
            iVar14 = load_cert(*(undefined4 *)puVar8,local_c0,3,0,uVar12,"signer certificate");
            iVar15 = (int)local_e8;
            if ((((iVar14 == 0) ||
                 (iVar15 = load_key(*(undefined4 *)puVar9,uVar16,local_84,0,local_48,uVar12,
                                    "signing key file"), iVar15 == 0)) ||
                (iVar22 = (*(code *)PTR_CMS_add1_signer_006a72e8)
                                    (iVar19,iVar14,iVar15,local_88,local_c8), iVar22 == 0)) ||
               ((iVar24 != 0 &&
                (iVar22 = (*(code *)PTR_CMS_add1_ReceiptRequest_006a72ec)(iVar22,iVar24),
                iVar22 == 0)))) {
              iVar23 = 0;
              iVar22 = 3;
              local_f4 = iVar14;
              local_e8 = (char *)iVar15;
              goto LAB_0046cc80;
            }
            local_f4 = 0;
            (*(code *)PTR_X509_free_006a6e90)(iVar14);
            local_e8 = (char *)0x0;
            (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar15);
          }
          if (uVar21 == 0x53) {
            if (((local_c8 & 0x1000) == 0) &&
               (iVar23 = (*(code *)PTR_CMS_final_006a72f0)(iVar19,iVar13,0,local_c8), iVar23 == 0))
            {
              iVar23 = 0;
              iVar22 = 3;
              goto LAB_0046cc80;
            }
            goto LAB_0046e854;
          }
        }
        if (iVar19 == 0) goto LAB_0046e85c;
        if (uVar21 == 0x22) {
          if ((int)(local_c8 << 0xe) < 0) {
            (*(code *)PTR_CMS_decrypt_006a7364)(iVar19,0,0,0,0,local_c8);
          }
          if ((local_e4 == 0) ||
             (iVar23 = (*(code *)PTR_CMS_decrypt_set1_key_006a7368)
                                 (iVar19,local_e4,local_a4,local_d8,local_80), iVar23 != 0)) {
            if ((local_e8 != (char *)0x0) &&
               (iVar23 = (*(code *)PTR_CMS_decrypt_set1_pkey_006a736c)(iVar19,local_e8,local_e0),
               iVar23 == 0)) {
              iVar23 = 0;
              iVar22 = 4;
              (*(code *)PTR_BIO_puts_006a6f58)
                        (*(undefined4 *)puVar8,"Error decrypting CMS using private key\n");
              goto LAB_0046cc80;
            }
            if ((local_ac != (char *)0x0) &&
               (iVar23 = (*(code *)PTR_CMS_decrypt_set1_password_006a7370)
                                   (iVar19,local_ac,0xffffffff), iVar23 == 0)) {
              iVar23 = 0;
              iVar22 = 4;
              (*(code *)PTR_BIO_puts_006a6f58)
                        (*(undefined4 *)puVar8,"Error decrypting CMS using password\n");
              goto LAB_0046cc80;
            }
            iVar23 = (*(code *)PTR_CMS_decrypt_006a7364)(iVar19,0,0,local_50,iVar27,local_c8);
            if (iVar23 == 0) {
              iVar23 = 0;
              iVar22 = 4;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar8,"Error decrypting CMS structure\n");
              goto LAB_0046cc80;
            }
            goto LAB_0046de5c;
          }
          iVar23 = 0;
          iVar22 = 4;
          (*(code *)PTR_BIO_puts_006a6f58)
                    (*(undefined4 *)puVar8,"Error decrypting CMS using secret key\n");
          goto LAB_0046cc80;
        }
        if (uVar21 == 0x27) {
          iVar23 = 0;
          iVar22 = (*(code *)PTR_CMS_data_006a7340)(iVar19,iVar27,local_c8);
          if (iVar22 != 0) {
            iVar22 = 0;
            goto LAB_0046cc90;
          }
        }
        else if (uVar21 == 0x2b) {
          iVar23 = 0;
          iVar22 = (*(code *)PTR_CMS_uncompress_006a733c)(iVar19,local_50,iVar27,local_c8);
          if (iVar22 != 0) {
            iVar22 = 0;
            goto LAB_0046cc90;
          }
        }
        else {
          if (uVar21 == 0x29) {
            iVar23 = (*(code *)PTR_CMS_digest_verify_006a7320)(iVar19,local_50,iVar27,local_c8);
            uVar12 = *(undefined4 *)puVar8;
joined_r0x0046e2a8:
            if (0 < iVar23) {
              iVar23 = 0;
              iVar22 = 0;
              (*(code *)PTR_BIO_printf_006a6e38)(uVar12,"Verification successful\n");
              goto LAB_0046cc90;
            }
            iVar23 = 0;
            iVar22 = 4;
            (*(code *)PTR_BIO_printf_006a6e38)(uVar12,"Verification failure\n");
            goto LAB_0046cc80;
          }
          if (uVar21 == 0x2d) {
            iVar23 = 0;
            iVar22 = (*(code *)PTR_CMS_EncryptedData_decrypt_006a7338)
                               (iVar19,local_e4,local_a4,local_50,iVar27,local_c8);
            if (iVar22 != 0) {
              iVar22 = 0;
              goto LAB_0046cc90;
            }
          }
          else {
            if (uVar21 != 0x24) {
              if (uVar21 == 0x30) {
                iVar23 = (*(code *)PTR_CMS_verify_receipt_006a7314)
                                   (local_f8,iVar19,local_dc,iVar29,local_c8);
                uVar12 = *(undefined4 *)puVar8;
                goto joined_r0x0046e2a8;
              }
              goto LAB_0046de2c;
            }
            iVar23 = (*(code *)PTR_CMS_verify_006a7318)
                               (iVar19,local_dc,iVar29,local_50,iVar27,local_c8);
            if (0 < iVar23) {
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"Verification successful\n");
              if (local_c0 != (char *)0x0) {
                uVar12 = (*(code *)PTR_CMS_get0_signers_006a731c)(iVar19);
                iVar23 = save_certs(local_c0,uVar12);
                if (iVar23 == 0) {
                  iVar23 = 0;
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar8,"Error writing signers to %s\n",local_c0);
                  iVar22 = 5;
                  goto LAB_0046cc80;
                }
                (*(code *)PTR_sk_free_006a6e80)(uVar12);
              }
              if (bVar5) {
                uVar16 = *(undefined4 *)puVar8;
                uVar12 = (*(code *)PTR_CMS_get0_SignerInfos_006a72e4)(iVar19);
                iVar23 = 0;
                while (iVar22 = (*(code *)PTR_sk_num_006a6e2c)(uVar12),
                      puVar9 = PTR_bio_err_006a6e3c, iVar23 < iVar22) {
                  iVar22 = iVar23 + 1;
                  uVar17 = (*(code *)PTR_sk_value_006a6e24)(uVar12,iVar23);
                  iVar23 = (*(code *)PTR_CMS_get1_ReceiptRequest_006a7324)(uVar17,&local_40);
                  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"Signer %d:\n",iVar22);
                  if (iVar23 == 0) {
                    (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar9,"  No Receipt Request\n")
                    ;
                  }
                  else if (iVar23 < 0) {
                    (*(code *)PTR_BIO_puts_006a6f58)
                              (*(undefined4 *)puVar9,"  Receipt Request Parse Error\n");
                    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar9);
                  }
                  else {
                    (*(code *)PTR_CMS_ReceiptRequest_get0_values_006a7328)
                              (local_40,&local_30,&local_3c,&local_34,&local_38);
                    (*(code *)PTR_BIO_puts_006a6f58)(uVar16,"  Signed Content ID:\n");
                    uVar17 = (*(code *)PTR_ASN1_STRING_length_006a732c)(local_30);
                    uVar18 = (*(code *)PTR_ASN1_STRING_data_006a7330)(local_30);
                    (*(code *)PTR_BIO_dump_indent_006a7334)(uVar16,uVar18,uVar17,4);
                    (*(code *)PTR_BIO_puts_006a6f58)(uVar16,"  Receipts From");
                    if (local_34 == 0) {
                      if (local_3c == 1) {
                        (*(code *)PTR_BIO_puts_006a6f58)(uVar16,": First Tier\n");
                      }
                      else if (local_3c == 0) {
                        (*(code *)PTR_BIO_puts_006a6f58)(uVar16,": All\n");
                      }
                      else {
                        (*(code *)PTR_BIO_printf_006a6e38)(uVar16," Unknown (%d)\n");
                      }
                    }
                    else {
                      (*(code *)PTR_BIO_puts_006a6f58)(uVar16," List:\n");
                      gnames_stack_print(uVar16,local_34);
                    }
                    (*(code *)PTR_BIO_puts_006a6f58)(uVar16,"  Receipts To:\n");
                    gnames_stack_print(uVar16,local_38);
                  }
                  iVar23 = iVar22;
                  if (local_40 != 0) {
                    (*(code *)PTR_CMS_ReceiptRequest_free_006a72d0)();
                  }
                }
                iVar23 = 0;
                iVar22 = 0;
                goto LAB_0046cc90;
              }
              goto LAB_0046de5c;
            }
            iVar23 = 0;
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"Verification failure\n");
            if (bVar6) {
              iVar22 = verify_err + 0x20;
              if (iVar22 == 0) goto LAB_0046cc90;
              goto LAB_0046cc80;
            }
          }
        }
LAB_0046e4bc:
        iVar23 = 0;
        iVar22 = 4;
        goto LAB_0046cc80;
      }
      iVar24 = 0;
      iVar19 = (*(code *)PTR_CMS_data_create_006a737c)(iVar13,local_c8);
LAB_0046e854:
      if (iVar19 == 0) {
LAB_0046e85c:
        iVar23 = 0;
        iVar19 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"Error creating CMS structure\n");
        iVar22 = 3;
        goto LAB_0046cc80;
      }
LAB_0046de2c:
      if (bVar3) {
        if (bVar4) {
          (*(code *)PTR_CMS_ContentInfo_print_ctx_006a72f4)(iVar27,iVar19,0,0);
        }
        goto LAB_0046de5c;
      }
      if (local_b0 == 6) {
        if (local_70 != (char *)0x0) {
          (*(code *)PTR_BIO_printf_006a6e38)(iVar27,"To: %s\n",local_70);
        }
        if (local_6c != (char *)0x0) {
          (*(code *)PTR_BIO_printf_006a6e38)(iVar27,"From: %s\n",local_6c);
        }
        if (local_68 != (char *)0x0) {
          (*(code *)PTR_BIO_printf_006a6e38)(iVar27,"Subject: %s\n",local_68);
        }
        pcVar30 = (code *)PTR_SMIME_write_CMS_006a7384;
        if (uVar21 != 0x76) goto LAB_0046ec88;
        iVar22 = (*(code *)PTR_SMIME_write_CMS_006a7384)(iVar27,iVar19,local_50,local_c8);
      }
      else {
        pcVar30 = (code *)PTR_PEM_write_bio_CMS_stream_006a7380;
        if ((local_b0 != 3) && (pcVar30 = (code *)PTR_i2d_CMS_bio_stream_006a7388, local_b0 != 1)) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar8,"Bad output format for CMS file\n");
          goto LAB_0046e4bc;
        }
LAB_0046ec88:
        iVar22 = (*pcVar30)(iVar27,iVar19,iVar13,local_c8);
      }
      iVar23 = 0;
      if (0 < iVar22) {
LAB_0046de5c:
        iVar23 = 0;
        iVar22 = 0;
        goto LAB_0046cc90;
      }
      iVar22 = 6;
      goto LAB_0046cc80;
    }
    uVar12 = *puVar7;
    pcVar28 = "Error getting password\n";
  }
  iVar23 = 0;
  (*(code *)PTR_BIO_printf_006a6e38)(uVar12,pcVar28);
  iVar24 = 0;
  local_f0 = (char *)0x0;
  iVar27 = 0;
  iVar13 = 0;
  local_dc = (char *)0x0;
  local_d4 = (char *)0x0;
  iVar29 = 0;
  local_e8 = (char *)0x0;
  iVar19 = 0;
  local_f4 = 0;
  iVar22 = 1;
  local_e0 = (char *)0x0;
  local_f8 = 0;
LAB_0046cc80:
  while( true ) {
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar8);
LAB_0046cc90:
    if (bVar2) {
      app_RAND_write_file(0,*(undefined4 *)puVar8);
    }
    (*(code *)PTR_sk_pop_free_006a7058)(local_d4,PTR_X509_free_006a6e90);
    (*(code *)PTR_sk_pop_free_006a7058)(local_dc,PTR_X509_free_006a6e90);
    if (local_44 != 0) {
      (*(code *)PTR_X509_VERIFY_PARAM_free_006a72cc)();
    }
    if (local_104 != 0) {
      (*(code *)PTR_sk_free_006a6e80)(local_104);
    }
    if (local_100 != 0) {
      (*(code *)PTR_sk_free_006a6e80)(local_100);
    }
    if (local_e4 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(local_e4);
    }
    if (local_d8 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(local_d8);
    }
    if (iVar23 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar23);
    }
    if (local_d0 != 0) {
      (*(code *)PTR_ASN1_OBJECT_free_006a7004)(local_d0);
    }
    if (iVar24 != 0) {
      (*(code *)PTR_CMS_ReceiptRequest_free_006a72d0)(iVar24);
    }
    if (iVar31 != 0) {
      (*(code *)PTR_sk_free_006a6e80)(iVar31);
    }
    if (local_fc != 0) {
      (*(code *)PTR_sk_free_006a6e80)(local_fc);
    }
    (*(code *)PTR_X509_STORE_free_006a7274)(iVar29);
    (*(code *)PTR_X509_free_006a6e90)(0);
    (*(code *)PTR_X509_free_006a6e90)(local_e0);
    (*(code *)PTR_X509_free_006a6e90)(local_f4);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(local_e8);
    (*(code *)PTR_CMS_ContentInfo_free_006a72d4)(iVar19);
    (*(code *)PTR_CMS_ContentInfo_free_006a72d4)(local_f8);
    (*(code *)PTR_BIO_free_006a6e70)(local_f0);
    (*(code *)PTR_BIO_free_006a6e70)(iVar13);
    (*(code *)PTR_BIO_free_006a6e70)(local_50);
    (*(code *)PTR_BIO_free_all_006a6e74)(iVar27);
    if (local_48 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (local_2c == *(int *)puVar10) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0046e648:
    uVar12 = *(undefined4 *)puVar8;
    pcVar28 = "Can\'t read content file %s\n";
    local_b4 = local_90;
LAB_0046db50:
    (*(code *)PTR_BIO_printf_006a6e38)(uVar12,pcVar28,local_b4);
LAB_0046db5c:
    iVar23 = 0;
    local_f0 = (char *)0x0;
    iVar24 = 0;
    local_f8 = 0;
    iVar27 = 0;
    iVar29 = 0;
    iVar22 = 2;
  }
  return iVar22;
}

