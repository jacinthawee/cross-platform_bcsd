
undefined * ocsp_main(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  char **ppcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  char *pcVar17;
  undefined *puVar18;
  char *pcVar19;
  int iVar20;
  undefined *puVar21;
  char *local_198;
  int local_194;
  int local_190;
  int local_18c;
  int local_188;
  char *local_184;
  int local_180;
  int local_17c;
  int local_178;
  undefined *local_174;
  char *local_170;
  char *local_16c;
  int local_168;
  int local_164;
  undefined4 local_160;
  int local_15c;
  undefined4 local_158;
  undefined *local_14c;
  int local_148;
  int local_144;
  undefined *local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  undefined4 local_128;
  int local_120;
  int local_11c;
  uint local_114;
  uint local_110;
  int local_10c;
  int local_108;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e0;
  int local_cc;
  int local_c8;
  undefined *local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_b8;
  int local_b4;
  undefined4 local_b0;
  int local_ac;
  int local_a8;
  undefined4 local_a4;
  int local_a0;
  int local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80 [4];
  undefined local_70 [68];
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  puVar2 = PTR_bio_err_006a6e3c;
  local_c0 = 0xffffffff;
  local_c4 = &DAT_0063b2b4;
  local_cc = 0;
  local_c8 = 0;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar13 = *(int *)PTR_bio_err_006a6e3c;
  if (iVar13 == 0) {
    iVar13 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(int *)puVar2 = iVar13;
  }
  iVar13 = load_config(iVar13,0);
  if (iVar13 != 0) {
    iVar13 = param_2 + 4;
    (*(code *)PTR_SSL_load_error_strings_006a7588)();
    (*(code *)PTR_SSL_library_init_006a7898)();
    local_158 = (*(code *)PTR_sk_new_null_006a6fa4)();
    local_160 = (*(code *)PTR_sk_new_null_006a6fa4)();
    pcVar19 = *(char **)(param_2 + 4);
    if ((pcVar19 != (char *)0x0) && (*pcVar19 == '-')) {
      local_180 = 0;
      local_174 = (undefined *)0x0;
      local_178 = 0;
      local_11c = -1;
      iVar10 = 0;
      local_148 = -1;
      puVar21 = (undefined *)0x0;
      local_f0 = -1;
      local_138 = 0;
      iVar15 = 0x630000;
      local_10c = 0;
      pcVar17 = "-check_ss_sig";
      local_f4 = 300;
      local_114 = 0;
      puVar18 = &UNK_006443fc;
      local_110 = 0;
      local_128 = 0;
      local_184 = (char *)0x0;
      local_fc = 0;
      local_144 = 1;
      local_130 = 0;
      local_e8 = 0;
      local_ec = 0;
      local_120 = 0;
      local_12c = 0;
      local_15c = 0;
      local_164 = 0;
      local_f8 = 0;
      local_18c = 0;
      local_14c = (undefined *)0x0;
      local_140 = (undefined *)0x0;
      local_134 = 0;
      local_13c = 0;
      local_100 = 0;
      local_17c = 0;
      local_190 = 0;
      local_194 = 0;
      local_198 = "-check_ss_sig";
      local_188 = 0;
      local_108 = -1;
      local_170 = "certificate";
      local_16c = "issuer certificate";
      goto LAB_004723cc;
    }
    local_174 = (undefined *)0x0;
    local_178 = 0;
    iVar16 = 0;
    local_138 = 0;
    local_11c = -1;
    puVar21 = (undefined *)0x0;
    local_148 = -1;
    local_f0 = -1;
    local_10c = 0;
    local_114 = 0;
    local_f4 = 300;
    local_110 = 0;
    local_128 = 0;
    local_108 = -1;
    local_184 = (char *)0x0;
    local_fc = 0;
    local_144 = 1;
    bVar1 = false;
    local_130 = 0;
    local_e8 = 0;
    local_ec = 0;
    local_120 = 0;
    local_12c = 0;
    local_15c = 0;
    local_164 = 0;
    local_f8 = 0;
    local_18c = 0;
    local_14c = (undefined *)0x0;
    local_140 = (undefined *)0x0;
    local_134 = 0;
    local_13c = 0;
    local_100 = 0;
    local_17c = 0;
    local_190 = 0;
    local_194 = 0;
    iVar4 = 0;
    goto LAB_004725b0;
  }
  iVar13 = 0;
  local_160 = 0;
  local_168 = 0;
  local_158 = 0;
  pcVar17 = (char *)0x0;
  local_18c = 0;
  puVar18 = (undefined *)0x1;
  local_180 = 0;
  iVar16 = 0;
  local_188 = 0;
  pcVar19 = (char *)0x0;
  local_178 = 0;
  iVar15 = 0;
  local_16c = (char *)0x0;
  puVar21 = (undefined *)0x0;
  local_17c = 0;
  local_198 = (char *)0x0;
  local_15c = 0;
  local_164 = 0;
  local_190 = 0;
  local_194 = 0;
LAB_00472078:
  do {
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
    (*(code *)PTR_X509_free_006a6e90)(local_198);
    (*(code *)PTR_X509_STORE_free_006a7274)(pcVar19);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(local_16c);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(local_178);
    (*(code *)PTR_X509_free_006a6e90)(local_164);
    (*(code *)PTR_X509_free_006a6e90)(local_15c);
    (*(code *)PTR_X509_free_006a6e90)(local_17c);
    (*(code *)PTR_X509_free_006a6e90)(pcVar17);
    free_index(local_168);
    (*(code *)PTR_BIO_free_all_006a6e74)(local_b4);
    (*(code *)PTR_BIO_free_all_006a6e74)(local_188);
    (*(code *)PTR_BIO_free_006a6e70)(local_180);
    (*(code *)PTR_OCSP_REQUEST_free_006a7774)(local_b8);
    (*(code *)PTR_OCSP_RESPONSE_free_006a7778)(iVar13);
    (*(code *)PTR_OCSP_BASICRESP_free_006a7db0)(iVar15);
    (*(code *)PTR_sk_free_006a6e80)(local_158);
    (*(code *)PTR_sk_free_006a6e80)(local_160);
    (*(code *)PTR_sk_pop_free_006a7058)(local_18c,PTR_X509_free_006a6e90);
    (*(code *)PTR_sk_pop_free_006a7058)(iVar16,PTR_X509_free_006a6e90);
    (*(code *)PTR_sk_pop_free_006a7058)(local_bc,PTR_X509V3_conf_free_006a7b4c);
    if (local_194 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(local_194);
    }
    if (local_190 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(local_190);
    }
    if (puVar21 != (undefined *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(puVar21);
    }
    if (local_2c == *(int *)puVar3) {
      return puVar18;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    local_108 = local_168;
LAB_00474214:
    iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-no_cert_checks");
    iVar20 = iVar13;
    if (iVar10 == 0) {
      local_110 = local_110 | 0x100;
      bVar1 = false;
    }
    else {
      iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-no_explicit");
      if (iVar10 == 0) {
        local_110 = local_110 | 0x20;
        bVar1 = false;
      }
      else {
        iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-trust_other");
        if (iVar10 == 0) {
          local_110 = local_110 | 0x200;
          bVar1 = false;
        }
        else {
          iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-no_intern");
          if (iVar10 == 0) {
            local_110 = local_110 | 2;
            bVar1 = false;
          }
          else {
            iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-text");
            if (iVar10 == 0) {
              bVar1 = false;
              local_120 = 1;
              local_12c = 1;
            }
            else {
              iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-req_text");
              if (iVar10 == 0) {
                bVar1 = false;
                local_12c = 1;
              }
              else {
                iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-resp_text");
                if (iVar10 == 0) {
                  bVar1 = false;
                  local_120 = 1;
                }
                else {
                  iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-reqin");
                  iVar10 = iVar16;
                  if (iVar4 == 0) {
                    if (*(int *)(iVar13 + 4) == 0) goto LAB_00472528;
                    bVar1 = false;
                    iVar20 = iVar13 + 4;
                    local_17c = *(int *)(iVar13 + 4);
                  }
                  else {
                    iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-respin");
                    if (iVar4 == 0) {
                      if (*(int *)(iVar13 + 4) == 0) goto LAB_00472528;
                      bVar1 = false;
                      iVar20 = iVar13 + 4;
                      local_100 = *(int *)(iVar13 + 4);
                    }
                    else {
                      iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-signer");
                      if (iVar4 == 0) {
                        if (*(undefined **)(iVar13 + 4) == (undefined *)0x0) goto LAB_00472528;
                        bVar1 = false;
                        iVar20 = iVar13 + 4;
                        local_140 = *(undefined **)(iVar13 + 4);
                      }
                      else {
                        iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-VAfile");
                        if (iVar4 == 0) {
                          if (*(int *)(iVar13 + 4) == 0) goto LAB_00472528;
                          bVar1 = false;
                          local_110 = local_110 | 0x200;
                          iVar20 = iVar13 + 4;
                          local_fc = *(int *)(iVar13 + 4);
                        }
                        else {
                          iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-sign_other");
                          if (iVar4 == 0) {
                            if (*(int *)(iVar13 + 4) == 0) goto LAB_00472528;
                            bVar1 = false;
                            iVar20 = iVar13 + 4;
                            local_130 = *(int *)(iVar13 + 4);
                          }
                          else {
                            iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-verify_other");
                            if (iVar4 == 0) {
                              if (*(int *)(iVar13 + 4) == 0) goto LAB_00472528;
                              bVar1 = false;
                              iVar20 = iVar13 + 4;
                              local_fc = *(int *)(iVar13 + 4);
                            }
                            else {
                              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-CAfile");
                              if (iVar4 == 0) {
                                if (*(int *)(iVar13 + 4) == 0) goto LAB_00472528;
                                bVar1 = false;
                                iVar20 = iVar13 + 4;
                                local_ec = *(int *)(iVar13 + 4);
                              }
                              else {
                                iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-CApath");
                                if (iVar4 == 0) {
                                  if (*(int *)(iVar13 + 4) == 0) goto LAB_00472528;
                                  bVar1 = false;
                                  iVar20 = iVar13 + 4;
                                  local_e8 = *(int *)(iVar13 + 4);
                                }
                                else {
                                  iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-validity_period")
                                  ;
                                  if (iVar4 == 0) {
                                    if (*(int *)(iVar13 + 4) == 0) goto LAB_00472528;
                                    iVar20 = iVar13 + 4;
                                    local_f4 = (*(code *)PTR_strtol_006a9958)
                                                         (*(int *)(iVar13 + 4),0,10);
                                    if (-1 < local_f4) goto LAB_00472424;
                                    (*(code *)PTR_BIO_printf_006a6e38)
                                              (*(undefined4 *)puVar2,"Illegal validity period %s\n",
                                               *(undefined4 *)(iVar13 + 4));
                                    bVar1 = true;
                                  }
                                  else {
                                    iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-status_age");
                                    if (iVar4 == 0) {
                                      if (*(int *)(iVar13 + 4) == 0) goto LAB_00472528;
                                      iVar20 = iVar13 + 4;
                                      local_f0 = (*(code *)PTR_strtol_006a9958)
                                                           (*(int *)(iVar13 + 4),0,10);
                                      if (-1 < local_f0) goto LAB_00472424;
                                      (*(code *)PTR_BIO_printf_006a6e38)
                                                (*(undefined4 *)puVar2,"Illegal validity age %s\n",
                                                 *(undefined4 *)(iVar13 + 4));
                                      bVar1 = true;
                                    }
                                    else {
                                      iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-signkey");
                                      if (iVar4 == 0) {
                                        if (*(undefined **)(iVar13 + 4) == (undefined *)0x0)
                                        goto LAB_00472528;
                                        bVar1 = false;
                                        iVar20 = iVar13 + 4;
                                        local_14c = *(undefined **)(iVar13 + 4);
                                      }
                                      else {
                                        iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-reqout");
                                        if (iVar4 == 0) {
                                          if (*(int *)(iVar13 + 4) == 0) goto LAB_00472528;
                                          bVar1 = false;
                                          iVar20 = iVar13 + 4;
                                          local_13c = *(int *)(iVar13 + 4);
                                        }
                                        else {
                                          iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-respout")
                                          ;
                                          if (iVar4 == 0) {
                                            if (*(int *)(iVar13 + 4) == 0) goto LAB_00472528;
                                            bVar1 = false;
                                            iVar20 = iVar13 + 4;
                                            local_134 = *(int *)(iVar13 + 4);
                                          }
                                          else {
                                            iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-path");
                                            if (iVar4 == 0) {
                                              if (*(undefined **)(iVar13 + 4) == (undefined *)0x0)
                                              goto LAB_00472528;
                                              bVar1 = false;
                                              iVar20 = iVar13 + 4;
                                              local_c4 = *(undefined **)(iVar13 + 4);
                                            }
                                            else {
                                              iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                (pcVar19,"-issuer");
                                              if (iVar4 != 0) {
                                                iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                  (pcVar19,"-cert");
                                                if (iVar4 == 0) {
                                                  if (*(int *)(iVar13 + 4) == 0) goto LAB_00472528;
                                                  (*(code *)PTR_X509_free_006a6e90)(local_15c);
                                                  local_15c = load_cert(*(undefined4 *)puVar2,
                                                                        *(undefined4 *)(iVar13 + 4),
                                                                        3,0,0,local_170);
                                                  if (local_15c == 0) goto LAB_00473514;
                                                  if (local_180 == 0) {
                                                    local_180 = (*(code *)PTR_EVP_sha1_006a75d0)();
                                                  }
                                                  if (local_164 == 0) {
LAB_00474870:
                                                    (*(code *)PTR_BIO_printf_006a6e38)
                                                              (*(undefined4 *)puVar2,
                                                               "No issuer certificate specified\n");
                                                    goto LAB_00473514;
                                                  }
                                                  if ((local_b8 != 0) ||
                                                     (local_b8 = (*(code *)
                                                  PTR_OCSP_REQUEST_new_006a777c)(), local_b8 != 0))
                                                  {
                                                    iVar4 = (*(code *)PTR_OCSP_cert_to_id_006a7780)
                                                                      (local_180,local_15c,local_164
                                                                      );
joined_r0x0047496c:
                                                    if (iVar4 != 0) {
                                                      iVar10 = (*(code *)PTR_sk_push_006a6fa8)
                                                                         (local_160,iVar4);
                                                      if ((iVar10 != 0) &&
                                                         (iVar10 = (*(code *)
                                                  PTR_OCSP_request_add0_id_006a7784)(local_b8,iVar4)
                                                  , iVar10 != 0)) {
                                                    iVar13 = (*(code *)PTR_sk_push_006a6fa8)
                                                                       (local_158,
                                                                        *(undefined4 *)(iVar13 + 4))
                                                    ;
                                                    if (iVar13 != 0) {
                                                      bVar1 = false;
                                                      iVar20 = iVar13 + 4;
                                                      goto LAB_004723ac;
                                                    }
                                                    goto LAB_00473514;
                                                  }
                                                  }
                                                  }
                                                }
                                                else {
                                                  iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                    (pcVar19,"-serial");
                                                  if (iVar4 != 0) {
                                                    iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (pcVar19,"-index");
                                                    if (iVar4 == 0) {
                                                      if (*(int *)(iVar13 + 4) == 0)
                                                      goto LAB_00472528;
                                                      bVar1 = false;
                                                      iVar20 = iVar13 + 4;
                                                      local_138 = *(int *)(iVar13 + 4);
                                                    }
                                                    else if (((pcVar19[1] == 'C') &&
                                                             (pcVar19[2] == 'A')) &&
                                                            (pcVar19[3] == '\0')) {
                                                      if (*(int *)(iVar13 + 4) == 0)
                                                      goto LAB_00472528;
                                                      bVar1 = false;
                                                      iVar20 = iVar13 + 4;
                                                      local_178 = *(int *)(iVar13 + 4);
                                                    }
                                                    else {
                                                      iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                        (pcVar19,"-nmin");
                                                      if (iVar4 == 0) {
                                                        if (*(int *)(iVar13 + 4) == 0) {
                                                          bVar1 = false;
                                                        }
                                                        else {
                                                          local_174 = (undefined *)
                                                                      (*(code *)PTR_strtol_006a9958)
                                                                                (*(int *)(iVar13 + 4
                                                                                         ),0,10);
                                                          if ((int)local_174 < 0) {
                                                            (*(code *)PTR_BIO_printf_006a6e38)
                                                                      (*(undefined4 *)puVar2,
                                                                       "Illegal update period %s\n",
                                                                       *(undefined4 *)(iVar13 + 4));
                                                            bVar1 = true;
                                                            iVar13 = iVar13 + 4;
                                                          }
                                                          else {
                                                            bVar1 = false;
                                                            iVar13 = iVar13 + 4;
                                                          }
                                                        }
                                                        if (local_11c != -1) goto LAB_00472528;
                                                        local_11c = 0;
                                                        iVar20 = iVar13;
                                                      }
                                                      else {
                                                        iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                          (pcVar19,"-nrequest");
                                                        if (iVar4 == 0) {
                                                          if (*(int *)(iVar13 + 4) == 0)
                                                          goto LAB_00472528;
                                                          iVar20 = iVar13 + 4;
                                                          local_148 = (*(code *)PTR_strtol_006a9958)
                                                                                (*(int *)(iVar13 + 4
                                                                                         ),0,10);
                                                          if (-1 < local_148) goto LAB_00472424;
                                                          (*(code *)PTR_BIO_printf_006a6e38)
                                                                    (*(undefined4 *)puVar2,
                                                                     "Illegal accept count %s\n",
                                                                     *(undefined4 *)(iVar13 + 4));
                                                          bVar1 = true;
                                                        }
                                                        else {
                                                          iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                            (pcVar19,"-ndays");
                                                          if (iVar4 == 0) {
                                                            if (*(int *)(iVar13 + 4) == 0)
                                                            goto LAB_00472528;
                                                            iVar20 = iVar13 + 4;
                                                            local_11c = (*(code *)
                                                  PTR_strtol_006a9958)(*(int *)(iVar13 + 4),0,10);
                                                  if (-1 < local_11c) goto LAB_00472424;
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar2,
                                                             "Illegal update period %s\n",
                                                             *(undefined4 *)(iVar13 + 4));
                                                  bVar1 = true;
                                                  }
                                                  else {
                                                    iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (pcVar19,"-rsigner");
                                                    if (iVar4 == 0) {
                                                      if (*(int *)(iVar13 + 4) == 0)
                                                      goto LAB_00472528;
                                                      bVar1 = false;
                                                      iVar20 = iVar13 + 4;
                                                      local_18c = *(int *)(iVar13 + 4);
                                                    }
                                                    else {
                                                      iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                        (pcVar19,"-rkey");
                                                      if (iVar4 == 0) {
                                                        if (*(int *)(iVar13 + 4) == 0)
                                                        goto LAB_00472528;
                                                        bVar1 = false;
                                                        iVar20 = iVar13 + 4;
                                                        local_188 = *(int *)(iVar13 + 4);
                                                      }
                                                      else {
                                                        iVar10 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (pcVar19,"-rother");
                                                        if (iVar10 == 0) {
                                                          if (*(char **)(iVar13 + 4) == (char *)0x0)
                                                          {
                                                            bVar1 = true;
                                                          }
                                                          else {
                                                            bVar1 = false;
                                                            iVar20 = iVar13 + 4;
                                                            local_184 = *(char **)(iVar13 + 4);
                                                          }
                                                        }
                                                        else {
                                                          local_180 = (*(code *)
                                                  PTR_EVP_get_digestbyname_006a6f2c)(pcVar19 + 1);
                                                  bVar1 = local_180 == 0;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_004723ac;
                                                  }
                                                  local_168 = *(int *)(iVar13 + 4);
                                                  if (local_168 == 0) goto LAB_00472528;
                                                  if (local_180 == 0) {
                                                    local_180 = (*(code *)PTR_EVP_sha1_006a75d0)();
                                                    local_168 = *(int *)(iVar13 + 4);
                                                  }
                                                  if (local_164 == 0) goto LAB_00474870;
                                                  if ((local_b8 != 0) ||
                                                     (local_b8 = (*(code *)
                                                  PTR_OCSP_REQUEST_new_006a777c)(), local_b8 != 0))
                                                  {
                                                    uVar6 = (*(code *)
                                                  PTR_X509_get_subject_name_006a6f00)(local_164);
                                                  uVar7 = (*(code *)
                                                  PTR_X509_get0_pubkey_bitstr_006a7e28)(local_164);
                                                  iVar10 = (*(code *)PTR_s2i_ASN1_INTEGER_006a6fb4)
                                                                     (0,local_168);
                                                  if (iVar10 != 0) {
                                                    iVar4 = (*(code *)PTR_OCSP_cert_id_new_006a7e2c)
                                                                      (local_180,uVar6,uVar7,iVar10)
                                                    ;
                                                    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)
                                                              (iVar10);
                                                    goto joined_r0x0047496c;
                                                  }
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar2,
                                                             "Error converting serial number %s\n",
                                                             local_168);
                                                  goto LAB_00473514;
                                                  }
                                                }
                                                (*(code *)PTR_BIO_printf_006a6e38)
                                                          (*(undefined4 *)puVar2,
                                                           "Error Creating OCSP request\n");
                                                goto LAB_00473514;
                                              }
                                              if (*(int *)(iVar13 + 4) == 0) goto LAB_00472528;
                                              (*(code *)PTR_X509_free_006a6e90)(local_164);
                                              local_164 = load_cert(*(undefined4 *)puVar2,
                                                                    *(undefined4 *)(iVar13 + 4),3,0,
                                                                    0,local_16c);
                                              if (local_164 == 0) goto LAB_00473514;
                                              bVar1 = false;
                                              iVar20 = iVar13 + 4;
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
LAB_004723ac:
    iVar13 = iVar20 + 4;
    iVar4 = local_188;
    if (!bVar1) {
      pcVar19 = *(char **)(iVar20 + 4);
      if ((pcVar19 == (char *)0x0) || (iVar10 = iVar16, *pcVar19 != '-')) goto LAB_004725b0;
LAB_004723cc:
      iVar16 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,iVar15 + 0x2514);
      if (iVar16 != 0) {
        iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,pcVar17 + -0x475c);
        iVar16 = iVar10;
        if (iVar4 == 0) {
          if (*(int *)(iVar13 + 4) != 0) {
            iVar20 = iVar13 + 4;
            local_108 = (*(code *)PTR_strtol_006a9958)(*(int *)(iVar13 + 4),0,10);
            if (local_108 < 0) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar2,"Illegal timeout value %s\n",
                         *(undefined4 *)(iVar13 + 4));
              bVar1 = true;
            }
            else {
LAB_00472424:
              bVar1 = false;
            }
            goto LAB_004723ac;
          }
        }
        else {
          iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,puVar18);
          if (iVar4 == 0) {
            if (local_194 != 0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)(local_194);
            }
            if (local_190 != 0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)(local_190);
            }
            if (puVar21 != (undefined *)0x0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)(puVar21);
            }
            if (*(int *)(iVar13 + 4) != 0) {
              iVar13 = (*(code *)PTR_OCSP_parse_url_006a7764)
                                 (*(int *)(iVar13 + 4),&local_cc,&local_c8,&local_c4,&local_c0);
              bVar1 = iVar13 == 0;
              if (bVar1) {
                (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Error parsing URL\n");
              }
              local_194 = local_cc;
              local_190 = local_c8;
              iVar20 = iVar13 + 4;
              puVar21 = local_c4;
              goto LAB_004723ac;
            }
          }
          else {
            iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,local_198 + -0x2d0c);
            if (iVar4 == 0) {
              if (*(int *)(iVar13 + 4) != 0) {
                bVar1 = false;
                iVar20 = iVar13 + 4;
                local_cc = *(int *)(iVar13 + 4);
                goto LAB_004723ac;
              }
            }
            else {
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-port");
              if (iVar4 == 0) {
                if (*(int *)(iVar13 + 4) != 0) {
                  bVar1 = false;
                  iVar20 = iVar13 + 4;
                  local_c8 = *(int *)(iVar13 + 4);
                  goto LAB_004723ac;
                }
              }
              else {
                iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-header");
                if (iVar4 != 0) {
                  iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-ignore_err");
                  iVar20 = iVar13;
                  if (iVar10 == 0) {
                    local_10c = 1;
                    bVar1 = false;
                    goto LAB_004723ac;
                  }
                  iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-noverify");
                  if (iVar10 == 0) {
                    bVar1 = false;
                    local_f8 = 1;
                    goto LAB_004723ac;
                  }
                  iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-nonce");
                  if (iVar10 == 0) {
                    bVar1 = false;
                    local_144 = 2;
                    goto LAB_004723ac;
                  }
                  iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-no_nonce");
                  if (iVar10 == 0) {
                    local_144 = 0;
                    bVar1 = false;
                    goto LAB_004723ac;
                  }
                  iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-resp_no_certs");
                  if (iVar10 == 0) {
                    local_114 = local_114 | 1;
                    bVar1 = false;
                    goto LAB_004723ac;
                  }
                  iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-resp_key_id");
                  if (iVar10 == 0) {
                    local_114 = local_114 | 0x400;
                    bVar1 = false;
                    goto LAB_004723ac;
                  }
                  iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-no_certs");
                  if (iVar10 == 0) {
                    bVar1 = false;
                    local_128 = 1;
                    goto LAB_004723ac;
                  }
                  iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-no_signature_verify");
                  if (iVar10 == 0) {
                    local_110 = local_110 | 4;
                    bVar1 = false;
                    goto LAB_004723ac;
                  }
                  iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-no_cert_verify");
                  if (iVar10 == 0) {
                    local_110 = local_110 | 0x10;
                    bVar1 = false;
                    goto LAB_004723ac;
                  }
                  iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar19,"-no_chain");
                  if (iVar10 == 0) {
                    local_110 = local_110 | 8;
                    bVar1 = false;
                    goto LAB_004723ac;
                  }
                  goto LAB_00474214;
                }
                if ((*(int *)(iVar13 + 4) != 0) && (*(int *)(iVar13 + 8) != 0)) {
                  iVar10 = (*(code *)PTR_X509V3_add_value_006a7db4)
                                     (*(int *)(iVar13 + 4),*(int *)(iVar13 + 8),&local_bc);
                  if (iVar10 == 0) goto LAB_00473514;
                  bVar1 = false;
                  iVar20 = iVar13 + 8;
                  goto LAB_004723ac;
                }
              }
            }
          }
        }
LAB_00472528:
        bVar1 = true;
        iVar16 = iVar10;
        iVar20 = iVar13;
        goto LAB_004723ac;
      }
      iVar16 = *(int *)(iVar13 + 4);
      if (iVar16 == 0) goto LAB_00472528;
      bVar1 = false;
      iVar20 = iVar13 + 4;
      goto LAB_004723ac;
    }
    bVar1 = true;
LAB_004725b0:
    if (((((local_b8 == 0) && (local_17c == 0)) && (local_100 == 0)) &&
        ((local_c8 == 0 || (local_138 == 0)))) || (bVar1)) {
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"OCSP utility\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Usage ocsp [options]\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"where options are\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-out file            output filename\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-issuer file         issuer certificate\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-cert file           certificate to check\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-serial n            serial number to check\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-signer file         certificate to sign OCSP request with\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-signkey file        private key to sign OCSP request with\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-sign_other file     additional certificates to include in signed request\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-no_certs            don\'t include any certificates in signed request\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-req_text            print text form of request\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-resp_text           print text form of response\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-text                print text form of request and response\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-reqout file         write DER encoded OCSP request to \"file\"\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-respout file        write DER encoded OCSP reponse to \"file\"\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-reqin file          read DER encoded OCSP request from \"file\"\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-respin file         read DER encoded OCSP reponse from \"file\"\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-nonce               add OCSP nonce to request\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-no_nonce            don\'t add OCSP nonce to request\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-url URL             OCSP responder URL\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-host host:n         send OCSP request to host on port n\n")
      ;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-path                path to use in OCSP request\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-CApath dir          trusted certificates directory\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-CAfile file         trusted certificates file\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-no_alt_chains       only ever use the first certificate chain found\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-VAfile file         validator certificates file\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-validity_period n   maximum validity discrepancy in seconds\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-status_age n        maximum status age in seconds\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-noverify            don\'t verify response at all\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-verify_other file   additional certificates to search for signer\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-trust_other         don\'t verify additional certificates\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-no_intern           don\'t search certificates contained in response for signer\n"
                );
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-no_signature_verify don\'t check signature on response\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-no_cert_verify      don\'t check signing certificate\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-no_chain            don\'t chain verify response\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-no_cert_checks      don\'t do additional checks on signing certificate\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-port num            port to run responder on\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-index file          certificate status index file\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-CA file             CA certificate\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-rsigner file        responder certificate to sign responses with\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-rkey file           responder key to sign responses with\n"
                );
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-rother file         other certificates to include in response\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-resp_no_certs       don\'t include any certificates in response\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-nmin n              number of minutes before next update\n"
                );
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-ndays n             number of days before next update\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-resp_key_id         identify reponse by signing certificate key ID\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-nrequest n          number of requests to accept (default unlimited)\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"-<dgst alg>          use specified digest in the request\n")
      ;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,
                 "-timeout n           timeout connection to OCSP responder after n seconds\n");
LAB_00473514:
      iVar13 = 0;
      local_180 = 0;
LAB_00473534:
      local_18c = 0;
      local_168 = 0;
      pcVar19 = (char *)0x0;
      pcVar17 = (char *)0x0;
      iVar16 = 0;
      puVar18 = (undefined *)0x1;
      local_188 = 0;
      iVar15 = 0;
      local_178 = 0;
      local_16c = (char *)0x0;
      local_17c = 0;
      local_198 = (char *)0x0;
      goto LAB_00472078;
    }
    if (iVar16 == 0) {
      local_180 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
    }
    else {
      local_180 = (*(code *)PTR_BIO_new_file_006a6eac)(iVar16,"w");
    }
    iVar13 = local_c8;
    if (local_180 == 0) {
      iVar13 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Error opening output file\n");
      goto LAB_00473534;
    }
    if (local_b8 == 0) {
      if (local_144 != 2) {
        local_144 = 0;
      }
      if (local_17c == 0) {
        if (local_c8 == 0) goto LAB_004725f4;
        uVar6 = (*(code *)PTR_BIO_f_buffer_006a7854)();
        iVar10 = (*(code *)PTR_BIO_new_006a6ea4)(uVar6);
        if (iVar10 == 0) {
          local_188 = 0;
        }
        else {
          local_188 = (*(code *)PTR_BIO_new_accept_006a7e04)(iVar13);
          if (local_188 != 0) {
            (*(code *)PTR_BIO_ctrl_006a6e18)(local_188,0x76,2,iVar10);
            iVar13 = (*(code *)PTR_BIO_ctrl_006a6e18)(local_188,0x65,0,0);
            if (0 < iVar13) {
              pcVar17 = (char *)0x0;
              if (local_18c != 0) goto LAB_00472600;
              local_e0 = 0;
              local_178 = 0;
              local_17c = 0;
              goto LAB_004726f0;
            }
            iVar10 = 0;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar2,"Error setting up accept BIO\n");
            (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
          }
        }
        iVar13 = 0;
        (*(code *)PTR_BIO_free_all_006a6e74)(local_188);
        (*(code *)PTR_BIO_free_006a6e70)(iVar10);
      }
      else {
        iVar13 = (*(code *)PTR_BIO_new_file_006a6eac)(local_17c,&DAT_00633e40);
        if (iVar13 == 0) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar2,"Error Opening OCSP request file\n");
        }
        else {
          local_b8 = (*(code *)PTR_ASN1_d2i_bio_006a71c4)
                               (PTR_OCSP_REQUEST_new_006a777c,PTR_d2i_OCSP_REQUEST_006a7d90,iVar13,0
                               );
          (*(code *)PTR_BIO_free_006a6e70)(iVar13);
          if (local_b8 != 0) goto LAB_004725f4;
          iVar13 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Error reading OCSP request\n");
        }
      }
      goto LAB_00473534;
    }
LAB_004725f4:
    local_188 = 0;
    if (local_18c == 0) {
      pcVar17 = (char *)0x0;
      local_e0 = 0;
      local_178 = 0;
      local_17c = 0;
LAB_0047270c:
      local_18c = 0;
      local_16c = (char *)0x0;
      local_198 = (char *)0x0;
      local_168 = 0;
      iVar10 = (int)local_174 * 0x3c;
      iVar13 = 0;
LAB_00472770:
      do {
        if (local_188 != 0) {
          iVar15 = do_responder_isra_0(&local_b8,&local_b4,local_188);
          if (iVar15 != 0) {
            if (local_b8 != 0) goto LAB_004727a0;
            iVar13 = (*(code *)PTR_OCSP_response_create_006a7db8)(1,0);
            puVar9 = local_80;
            puVar12 = (undefined4 *)
                      "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
            ;
            do {
              puVar11 = puVar12 + 4;
              puVar8 = puVar9 + 4;
              uVar14 = puVar12[1];
              uVar7 = puVar12[2];
              uVar6 = puVar12[3];
              *puVar9 = *puVar12;
              puVar9[1] = uVar14;
              puVar9[2] = uVar7;
              puVar9[3] = uVar6;
              puVar9 = puVar8;
              puVar12 = puVar11;
            } while (puVar11 != (undefined4 *)0x64551c);
            *(char *)puVar8 = s_HTTP_1_0_200_OK_Content_type__ap_006454cc[80];
            if (local_b4 == 0) goto LAB_00472db0;
LAB_00472ca0:
            iVar15 = local_b4;
            uVar6 = (*(code *)PTR_i2d_OCSP_RESPONSE_006a7794)(iVar13,0);
            (*(code *)PTR_BIO_printf_006a6e38)(iVar15,local_80,uVar6);
            (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_OCSP_RESPONSE_006a7794,iVar15,iVar13);
            (*(code *)PTR_BIO_ctrl_006a6e18)(iVar15,0xb,0,0);
            goto LAB_00472db0;
          }
LAB_00473760:
          puVar18 = (undefined *)0x1;
          iVar16 = 0;
          pcVar19 = (char *)0x0;
          iVar15 = 0;
          goto LAB_00472078;
        }
        if (local_b8 == 0) {
          if (((local_140 != (undefined *)0x0) || (local_13c != 0)) ||
             ((local_cc != 0 || ((local_144 != 0 || (local_138 != 0)))))) {
            pcVar19 = "Need an OCSP request for this operation!\n";
            uVar6 = *(undefined4 *)puVar2;
LAB_00473718:
            puVar18 = (undefined *)0x1;
            (*(code *)PTR_BIO_printf_006a6e38)(uVar6,pcVar19);
            iVar16 = 0;
            pcVar19 = (char *)0x0;
            iVar15 = 0;
            goto LAB_00472078;
          }
LAB_00472d64:
          if (local_168 == 0) {
            if (local_cc != 0) {
              iVar13 = process_responder(*(undefined4 *)puVar2,local_b8,local_cc,local_c4,local_c8,
                                         local_c0,local_bc,local_108);
              if (iVar13 == 0) goto LAB_00473760;
              goto LAB_00472db0;
            }
            if (local_100 != 0) {
              iVar15 = (*(code *)PTR_BIO_new_file_006a6eac)(local_100,&DAT_00633e40);
              if (iVar15 != 0) {
                iVar13 = (*(code *)PTR_ASN1_d2i_bio_006a71c4)
                                   (PTR_OCSP_RESPONSE_new_006a7e00,PTR_d2i_OCSP_RESPONSE_006a793c,
                                    iVar15,0);
                (*(code *)PTR_BIO_free_006a6e70)(iVar15);
                if (iVar13 == 0) {
                  pcVar19 = "Error reading OCSP response\n";
                  uVar6 = *(undefined4 *)puVar2;
                  goto LAB_00473718;
                }
                goto LAB_00472db0;
              }
              puVar18 = (undefined *)0x1;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar2,"Error Opening OCSP response file\n");
              iVar16 = 0;
              pcVar19 = (char *)0x0;
              goto LAB_00472078;
            }
            break;
          }
        }
        else {
LAB_004727a0:
          if (local_144 != 0) {
            (*(code *)PTR_OCSP_request_add1_nonce_006a7dbc)(local_b8,0,0xffffffff);
          }
          puVar18 = PTR_bio_err_006a6e3c;
          if (local_140 != (undefined *)0x0) {
            local_198 = (char *)load_cert(*(undefined4 *)puVar2,local_140,3,0,0,"signer certificate"
                                         );
            if (local_14c == (undefined *)0x0) {
              local_14c = local_140;
            }
            if (local_198 == (char *)0x0) {
              pcVar19 = "Error loading signer certificate\n";
              uVar6 = *(undefined4 *)puVar18;
            }
            else {
              if (((local_130 != 0) &&
                  (local_18c = load_certs(*(undefined4 *)puVar18,local_130,3,0,0,
                                          "signer certificates"), local_18c == 0)) ||
                 (local_16c = (char *)load_key(*(undefined4 *)puVar2,local_14c,3,0,0,0,
                                               "signer private key"), local_16c == (char *)0x0))
              goto LAB_00473760;
              iVar15 = (*(code *)PTR_OCSP_request_sign_006a7dc0)
                                 (local_b8,local_198,local_16c,0,local_18c,local_128);
              if (iVar15 != 0) goto LAB_00472898;
              pcVar19 = "Error signing OCSP request\n";
              uVar6 = *(undefined4 *)PTR_bio_err_006a6e3c;
            }
            goto LAB_00473718;
          }
LAB_00472898:
          if ((local_12c != 0) && (local_b8 != 0)) {
            (*(code *)PTR_OCSP_REQUEST_print_006a7dc4)(local_180,local_b8,0);
          }
          if (local_13c != 0) {
            iVar15 = (*(code *)PTR_BIO_new_file_006a6eac)(local_13c,&DAT_00632420);
            if (iVar15 != 0) {
              (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_OCSP_REQUEST_006a7dc8,iVar15,local_b8);
              (*(code *)PTR_BIO_free_006a6e70)(iVar15);
              goto LAB_00472910;
            }
            uVar6 = *(undefined4 *)puVar2;
            iVar10 = local_13c;
LAB_00473af0:
            puVar18 = (undefined *)0x1;
            iVar16 = 0;
            (*(code *)PTR_BIO_printf_006a6e38)(uVar6,"Error opening file %s\n",iVar10);
            pcVar19 = (char *)0x0;
            goto LAB_00472078;
          }
LAB_00472910:
          if (local_138 == 0) goto LAB_00472d64;
          if (((local_178 == 0) || (local_17c == 0)) || (pcVar17 == (char *)0x0)) {
            pcVar19 = "Need a responder certificate, key and CA for this operation!\n";
            uVar6 = *(undefined4 *)puVar2;
            goto LAB_00473718;
          }
          if (local_168 != 0) goto LAB_0047293c;
          local_168 = load_index(local_138,0);
          if (local_168 == 0) {
            puVar18 = (undefined *)0x1;
            iVar16 = 0;
            pcVar19 = (char *)0x0;
            iVar15 = 0;
            goto LAB_00472078;
          }
          iVar15 = index_index(local_168);
          if (iVar15 == 0) goto LAB_00473760;
        }
LAB_0047293c:
        iVar13 = local_b8;
        iVar15 = (*(code *)PTR_OCSP_request_onereq_count_006a7dcc)(local_b8);
        if (iVar15 < 1) {
          iVar16 = 0;
          iVar13 = (*(code *)PTR_OCSP_response_create_006a7db8)(1,0);
          local_184 = (char *)0x0;
          local_170 = (char *)0x0;
          local_174 = (undefined *)0x0;
        }
        else {
          local_184 = (char *)(*(code *)PTR_OCSP_BASICRESP_new_006a7dd0)();
          local_174 = (undefined *)(*(code *)PTR_X509_gmtime_adj_006a6f8c)(0,0);
          if (local_11c == -1) {
            local_170 = (char *)0x0;
          }
          else {
            local_170 = (char *)(*(code *)PTR_X509_time_adj_ex_006a6f90)(0,local_11c,iVar10,0);
          }
          iVar16 = 0;
          iVar4 = 0;
          do {
            while( true ) {
              uVar6 = (*(code *)PTR_OCSP_request_onereq_get0_006a7ddc)(iVar13,iVar4);
              uVar6 = (*(code *)PTR_OCSP_onereq_get0_id_006a7de0)(uVar6);
              (*(code *)PTR_OCSP_id_get0_info_006a7dd4)(0,&local_ac,0,0,uVar6);
              uVar7 = (*(code *)PTR_OBJ_obj2nid_006a712c)(local_ac);
              uVar7 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar7);
              iVar20 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar7);
              if (iVar20 == 0) {
                iVar13 = (*(code *)PTR_OCSP_response_create_006a7db8)(2,0);
                goto LAB_00472c04;
              }
              if (iVar16 != 0) {
                (*(code *)PTR_OCSP_CERTID_free_006a7770)(iVar16);
              }
              iVar16 = (*(code *)PTR_OCSP_cert_to_id_006a7780)(iVar20,0,pcVar17);
              iVar20 = (*(code *)PTR_OCSP_id_issuer_cmp_006a7de4)(iVar16,uVar6);
              if (iVar20 == 0) break;
LAB_00472b70:
              uVar7 = 2;
LAB_00472b7c:
              iVar4 = iVar4 + 1;
              (*(code *)PTR_OCSP_basic_add1_status_006a7de8)
                        (local_184,uVar6,uVar7,0,0,local_174,local_170);
              if (iVar15 == iVar4) goto LAB_00472ba8;
            }
            (*(code *)PTR_OCSP_id_get0_info_006a7dd4)(0,0,0,&local_b0,uVar6);
            local_98 = 0;
            local_94 = 0;
            local_90 = 0;
            local_8c = 0;
            local_88 = 0;
            local_84 = 0;
            iVar20 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(local_b0,0);
            if (iVar20 == 0) {
              (*(code *)PTR_OpenSSLDie_006a7c5c)("ocsp.c",0x445,&DAT_0064534c);
            }
            if (*(int *)(iVar20 + 4) == 0) {
              uVar7 = (*(code *)PTR_BUF_strdup_006a6fdc)("00");
            }
            else {
              uVar7 = (*(code *)PTR_BN_bn2hex_006a7018)(iVar20);
            }
            local_8c = uVar7;
            (*(code *)PTR_BN_free_006a701c)(iVar20);
            ppcVar5 = (char **)(*(code *)PTR_TXT_DB_get_by_index_006a7020)
                                         (*(undefined4 *)(local_168 + 4),3,&local_98);
            (*(code *)PTR_CRYPTO_free_006a6e88)(uVar7);
            if (ppcVar5 == (char **)0x0) goto LAB_00472b70;
            if (**ppcVar5 == 'V') {
              uVar7 = 0;
              goto LAB_00472b7c;
            }
            if (**ppcVar5 == 'R') {
              local_a8 = 0;
              local_a4 = 0;
              local_a0 = 0;
              local_9c = -1;
              (*(code *)PTR_unpack_revinfo_006a7dd8)
                        (&local_a4,&local_9c,&local_a8,&local_a0,ppcVar5[2]);
              uVar6 = (*(code *)PTR_OCSP_basic_add1_status_006a7de8)
                                (local_184,uVar6,1,local_9c,local_a4,local_174,local_170);
              if (local_a0 == 0) {
                if (local_a8 != 0) {
                  (*(code *)PTR_OCSP_SINGLERESP_add1_ext_i2d_006a7df8)(uVar6,0x1ae,local_a8,0,0);
                }
              }
              else {
                (*(code *)PTR_OCSP_SINGLERESP_add1_ext_i2d_006a7df8)(uVar6,0x8e,local_a0,0,0);
              }
              (*(code *)PTR_ASN1_OBJECT_free_006a7004)(local_a8);
              (*(code *)PTR_ASN1_TIME_free_006a7050)(local_a4);
              (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a7038)(local_a0);
            }
            iVar4 = iVar4 + 1;
          } while (iVar15 != iVar4);
LAB_00472ba8:
          (*(code *)PTR_OCSP_copy_nonce_006a7dec)(local_184,iVar13);
          (*(code *)PTR_OCSP_basic_sign_006a7df0)
                    (local_184,local_17c,local_178,0,local_e0,local_114);
          iVar13 = (*(code *)PTR_OCSP_response_create_006a7db8)(0,local_184);
        }
LAB_00472c04:
        (*(code *)PTR_ASN1_TIME_free_006a7050)(local_174);
        (*(code *)PTR_ASN1_TIME_free_006a7050)(local_170);
        (*(code *)PTR_OCSP_CERTID_free_006a7770)(iVar16);
        (*(code *)PTR_OCSP_BASICRESP_free_006a7db0)(local_184);
        if (local_b4 != 0) {
          puVar9 = (undefined4 *)
                   "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
          ;
          puVar12 = local_80;
          do {
            puVar8 = puVar9 + 4;
            puVar11 = puVar12 + 4;
            uVar14 = puVar9[1];
            uVar7 = puVar9[2];
            uVar6 = puVar9[3];
            *puVar12 = *puVar9;
            puVar12[1] = uVar14;
            puVar12[2] = uVar7;
            puVar12[3] = uVar6;
            puVar9 = puVar8;
            puVar12 = puVar11;
          } while (puVar8 != (undefined4 *)0x64551c);
          *(char *)puVar11 = s_HTTP_1_0_200_OK_Content_type__ap_006454cc[80];
          goto LAB_00472ca0;
        }
LAB_00472db0:
        if (local_134 != 0) {
          iVar15 = (*(code *)PTR_BIO_new_file_006a6eac)(local_134,&DAT_00632420);
          if (iVar15 == 0) {
            uVar6 = *(undefined4 *)puVar2;
            iVar10 = local_134;
            goto LAB_00473af0;
          }
          (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_OCSP_RESPONSE_006a7794,iVar15,iVar13);
          (*(code *)PTR_BIO_free_006a6e70)(iVar15);
        }
        iVar15 = (*(code *)PTR_OCSP_response_status_006a7df4)(iVar13);
        if (iVar15 == 0) {
          if (local_120 != 0) {
            (*(code *)PTR_OCSP_RESPONSE_print_006a7798)(local_180,iVar13,0);
          }
          if (local_b4 == 0) {
            pcVar19 = (char *)setup_verify(*(undefined4 *)puVar2,local_ec,local_e8);
            if (pcVar19 == (char *)0x0) {
              puVar18 = (undefined *)0x1;
              iVar16 = 0;
              iVar15 = 0;
              goto LAB_00472078;
            }
            if (local_fc == 0) {
              iVar16 = 0;
            }
            else {
              iVar16 = load_certs(*(undefined4 *)PTR_bio_err_006a6e3c,local_fc,3,0,0,
                                  "validator certificate");
              if (iVar16 == 0) {
                puVar18 = (undefined *)0x1;
                iVar15 = 0;
                goto LAB_00472078;
              }
            }
            iVar15 = (*(code *)PTR_OCSP_response_get1_basic_006a7e08)(iVar13);
            if (iVar15 == 0) {
              puVar18 = (undefined *)0x1;
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Error parsing response\n");
              goto LAB_00472078;
            }
            if (local_f8 == 0) {
              if ((local_b8 != 0) &&
                 (iVar10 = (*(code *)PTR_OCSP_check_nonce_006a7e0c)(local_b8,iVar15), iVar10 < 1)) {
                if (iVar10 != -1) {
                  puVar18 = (undefined *)0x1;
                  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Nonce Verify error\n");
                  goto LAB_00472078;
                }
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar2,"WARNING: no nonce in response\n");
              }
              iVar10 = (*(code *)PTR_OCSP_basic_verify_006a7e10)(iVar15,iVar16,pcVar19,local_110);
              if (iVar10 < 0) {
                iVar10 = (*(code *)PTR_OCSP_basic_verify_006a7e10)(iVar15,0,pcVar19,0);
              }
              if (iVar10 < 1) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar2,"Response Verify Failure\n");
                (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
              }
              else {
                (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Response verify OK\n");
              }
            }
            if (((local_b8 != 0) &&
                (iVar10 = (*(code *)PTR_sk_num_006a6e2c)(local_158), iVar10 != 0)) &&
               (iVar10 = (*(code *)PTR_sk_num_006a6e2c)(local_160), iVar10 != 0)) {
              iVar10 = 0;
              local_184 = "-check_ss_sig";
              local_174 = &DAT_00631e78;
              local_170 = "%s\n";
              goto LAB_00473ce0;
            }
            puVar18 = (undefined *)0x0;
            goto LAB_00472078;
          }
          local_148 = local_148 - (uint)(0 < local_148);
          if (local_148 == 0) goto LAB_00473760;
          (*(code *)PTR_BIO_free_all_006a6e74)();
          local_b4 = 0;
          (*(code *)PTR_OCSP_REQUEST_free_006a7774)(local_b8);
          local_b8 = 0;
          (*(code *)PTR_OCSP_RESPONSE_free_006a7778)(iVar13);
          iVar13 = 0;
          goto LAB_00472770;
        }
        uVar6 = (*(code *)PTR_OCSP_response_status_str_006a7dfc)(iVar15);
        (*(code *)PTR_BIO_printf_006a6e38)(local_180,"Responder Error: %s (%d)\n",uVar6,iVar15);
      } while (local_10c != 0);
      puVar18 = (undefined *)0x0;
      iVar16 = 0;
      pcVar19 = (char *)0x0;
      iVar15 = 0;
    }
    else {
LAB_00472600:
      puVar18 = PTR_bio_err_006a6e3c;
      iVar13 = local_18c;
      if (iVar4 != 0) {
        iVar13 = iVar4;
      }
      local_17c = load_cert(*(undefined4 *)puVar2,local_18c,3,0,0,"responder certificate");
      if (local_17c == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar18,"Error loading responder certificate\n");
        pcVar17 = (char *)0x0;
LAB_004739a0:
        local_168 = 0;
        iVar13 = 0;
        puVar18 = (undefined *)0x1;
        local_18c = 0;
        iVar16 = 0;
        local_178 = 0;
        pcVar19 = (char *)0x0;
        local_16c = (char *)0x0;
        local_198 = (char *)0x0;
        iVar15 = 0;
      }
      else {
        pcVar17 = (char *)load_cert(*(undefined4 *)puVar18,local_178,3,0,0,"CA certificate");
        if (local_184 == (char *)0x0) {
          local_e0 = 0;
        }
        else {
          local_e0 = load_certs(*(undefined4 *)puVar18,local_184,3,0,0,
                                "responder other certificates");
          if (local_e0 == 0) goto LAB_004739a0;
        }
        local_178 = load_key(*(undefined4 *)puVar2,iVar13,3,0,0,0,"responder private key");
        if (local_178 != 0) {
          if (local_188 != 0) {
LAB_004726f0:
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar2,"Waiting for OCSP client connections...\n");
          }
          goto LAB_0047270c;
        }
        iVar13 = 0;
        local_18c = 0;
        local_168 = 0;
        local_16c = (char *)0x0;
        puVar18 = (undefined *)0x1;
        local_198 = (char *)0x0;
        iVar16 = 0;
        pcVar19 = (char *)0x0;
        iVar15 = 0;
      }
    }
  } while( true );
LAB_00473ce0:
  iVar4 = (*(code *)PTR_sk_num_006a6e2c)(local_160);
  if (iVar10 < iVar4) {
    local_148 = (*(code *)PTR_sk_value_006a6e24)(local_160,iVar10);
    uVar6 = (*(code *)PTR_sk_value_006a6e24)(local_158,iVar10);
    (*(code *)PTR_BIO_printf_006a6e38)(local_180,&DAT_00631e78,uVar6);
    iVar4 = (*(code *)PTR_OCSP_resp_find_status_006a7e14)
                      (iVar15,local_148,&local_ac,&local_a8,&local_a4,&local_a0,&local_9c);
    if (iVar4 == 0) {
      (*(code *)PTR_BIO_puts_006a6f58)(local_180,"ERROR: No Status found.\n");
LAB_00473d90:
      iVar10 = iVar10 + 1;
    }
    else {
      iVar4 = (*(code *)PTR_OCSP_check_validity_006a7e18)(local_a0,local_9c,local_f4,local_f0);
      if (iVar4 == 0) {
        (*(code *)PTR_BIO_puts_006a6f58)(local_180,"WARNING: Status times invalid.\n");
        (*(code *)PTR_ERR_print_errors_006a6e40)(local_180);
      }
      uVar6 = (*(code *)PTR_OCSP_cert_status_str_006a7e1c)(local_ac);
      (*(code *)PTR_BIO_printf_006a6e38)(local_180,"%s\n",uVar6);
      (*(code *)PTR_BIO_puts_006a6f58)(local_180,"\tThis Update: ");
      (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(local_180,local_a0);
      (*(code *)PTR_BIO_puts_006a6f58)(local_180,"\n");
      if (local_9c != 0) {
        (*(code *)PTR_BIO_puts_006a6f58)(local_180,"\tNext Update: ");
        (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(local_180,local_9c);
        (*(code *)PTR_BIO_puts_006a6f58)(local_180,"\n");
      }
      if (local_ac != 1) goto LAB_00473d90;
      if (local_a8 != -1) {
        uVar6 = (*(code *)PTR_OCSP_crl_reason_str_006a7e24)();
        (*(code *)PTR_BIO_printf_006a6e38)(local_180,"\tReason: %s\n",uVar6);
      }
      iVar10 = iVar10 + 1;
      (*(code *)PTR_BIO_puts_006a6f58)(local_180,"\tRevocation Time: ");
      (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(local_180,local_a4);
      (*(code *)PTR_BIO_puts_006a6f58)(local_180,"\n");
    }
    goto LAB_00473ce0;
  }
  puVar18 = (undefined *)0x0;
  local_14c = puVar21;
  goto LAB_00472078;
}

