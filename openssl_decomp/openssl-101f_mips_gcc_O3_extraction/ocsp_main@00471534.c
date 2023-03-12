
undefined * ocsp_main(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  char **ppcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  char *pcVar18;
  undefined *puVar19;
  char *pcVar20;
  char *unaff_s7;
  int local_18c;
  int local_188;
  int local_184;
  char *local_180;
  int local_17c;
  char *local_178;
  int local_174;
  undefined *local_170;
  char *local_16c;
  int local_168;
  char *local_164;
  int local_160;
  undefined4 local_15c;
  int local_158;
  undefined4 local_154;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  int local_128;
  undefined4 local_124;
  int local_120;
  int local_118;
  uint local_110;
  uint local_10c;
  int local_108;
  char *local_104;
  int local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_cc;
  int local_c8;
  undefined *local_c4;
  int local_c0;
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
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  puVar2 = PTR_bio_err_006a7f3c;
  local_c0 = -1;
  local_c4 = &DAT_0063ba98;
  local_cc = 0;
  local_c8 = 0;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar14 = *(int *)PTR_bio_err_006a7f3c;
  if (iVar14 == 0) {
    iVar14 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *(int *)puVar2 = iVar14;
  }
  iVar14 = load_config(iVar14,0);
  if (iVar14 != 0) {
    iVar14 = param_2 + 4;
    (*(code *)PTR_SSL_load_error_strings_006a867c)();
    (*(code *)PTR_SSL_library_init_006a8980)();
    local_154 = (*(code *)PTR_sk_new_null_006a80a4)();
    local_15c = (*(code *)PTR_sk_new_null_006a80a4)();
    pcVar20 = *(char **)(param_2 + 4);
    if ((pcVar20 != (char *)0x0) && (*pcVar20 == '-')) {
      local_17c = 0;
      local_170 = (undefined *)0x0;
      local_174 = 0;
      local_120 = -1;
      iVar11 = 0;
      local_144 = -1;
      iVar16 = 0x630000;
      local_ec = -1;
      local_134 = 0;
      pcVar18 = "s\n";
      local_108 = 0;
      puVar19 = &UNK_0064492c;
      local_f0 = 300;
      local_110 = 0;
      local_164 = "s\n";
      local_10c = 0;
      local_124 = 0;
      local_180 = (char *)0x0;
      local_f8 = 0;
      local_140 = 1;
      local_12c = 0;
      local_e4 = 0;
      local_e8 = 0;
      local_118 = 0;
      local_178 = "certificate";
      local_128 = 0;
      local_158 = 0;
      local_160 = 0;
      local_f4 = 0;
      local_18c = 0;
      local_148 = 0;
      local_13c = 0;
      local_130 = 0;
      local_138 = 0;
      local_fc = 0;
      local_184 = 0;
      local_16c = "issuer certificate";
      local_188 = 0;
      unaff_s7 = (char *)0xffffffff;
      goto LAB_00471954;
    }
    local_170 = (undefined *)0x0;
    local_174 = 0;
    iVar17 = 0;
    local_134 = 0;
    local_188 = 0;
    local_120 = -1;
    local_144 = -1;
    local_ec = -1;
    local_108 = 0;
    local_110 = 0;
    local_f0 = 300;
    local_10c = 0;
    local_124 = 0;
    local_104 = (char *)0xffffffff;
    local_180 = (char *)0x0;
    local_f8 = 0;
    local_140 = 1;
    bVar1 = false;
    local_12c = 0;
    local_e4 = 0;
    local_e8 = 0;
    local_118 = 0;
    local_128 = 0;
    local_158 = 0;
    local_160 = 0;
    local_f4 = 0;
    local_18c = 0;
    local_148 = 0;
    local_13c = 0;
    local_130 = 0;
    local_138 = 0;
    local_fc = 0;
    local_184 = 0;
    unaff_s7 = pcVar20;
    goto LAB_00471af4;
  }
  iVar14 = 0;
  local_15c = 0;
  local_164 = (char *)0x0;
  local_154 = 0;
  pcVar18 = (char *)0x0;
  local_188 = 0;
  puVar19 = (undefined *)0x1;
  local_17c = 0;
  iVar17 = 0;
  local_184 = 0;
  pcVar20 = (char *)0x0;
  local_174 = 0;
  iVar16 = 0;
  local_168 = 0;
  local_178 = (char *)0x0;
  local_18c = 0;
  local_158 = 0;
  local_160 = 0;
LAB_00471618:
  do {
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
    (*(code *)PTR_X509_free_006a7f90)(local_18c);
    (*(code *)PTR_X509_STORE_free_006a8384)(pcVar20);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(local_168);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(local_174);
    (*(code *)PTR_X509_free_006a7f90)(local_160);
    (*(code *)PTR_X509_free_006a7f90)(local_158);
    (*(code *)PTR_X509_free_006a7f90)(local_178);
    (*(code *)PTR_X509_free_006a7f90)(pcVar18);
    free_index(local_164);
    (*(code *)PTR_BIO_free_all_006a7f74)(local_b4);
    (*(code *)PTR_BIO_free_all_006a7f74)(local_184);
    (*(code *)PTR_BIO_free_006a7f70)(local_17c);
    (*(code *)PTR_OCSP_REQUEST_free_006a8864)(local_b8);
    (*(code *)PTR_OCSP_RESPONSE_free_006a8868)(iVar14);
    (*(code *)PTR_OCSP_BASICRESP_free_006a8ea0)(iVar16);
    (*(code *)PTR_sk_free_006a7f80)(local_154);
    (*(code *)PTR_sk_free_006a7f80)(local_15c);
    (*(code *)PTR_sk_pop_free_006a8158)(local_188,PTR_X509_free_006a7f90);
    (*(code *)PTR_sk_pop_free_006a8158)(iVar17,PTR_X509_free_006a7f90);
    (*(code *)PTR_sk_pop_free_006a8158)(local_bc,PTR_X509V3_conf_free_006a8c38);
    if (local_c0 != -1) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(local_cc);
      (*(code *)PTR_CRYPTO_free_006a7f88)(local_c8);
      (*(code *)PTR_CRYPTO_free_006a7f88)(local_c4);
    }
    if (local_2c == *(int *)puVar3) {
      return puVar19;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_004736bc:
    iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-no_cert_checks");
    iVar4 = iVar14;
    if (iVar11 == 0) {
      local_10c = local_10c | 0x100;
      bVar1 = false;
    }
    else {
      iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-no_explicit");
      if (iVar11 == 0) {
        local_10c = local_10c | 0x20;
        bVar1 = false;
      }
      else {
        iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-trust_other");
        if (iVar11 == 0) {
          local_10c = local_10c | 0x200;
          bVar1 = false;
        }
        else {
          iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-no_intern");
          if (iVar11 == 0) {
            local_10c = local_10c | 2;
            bVar1 = false;
          }
          else {
            iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-text");
            if (iVar11 == 0) {
              bVar1 = false;
              local_118 = 1;
              local_128 = 1;
            }
            else {
              iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-req_text");
              if (iVar11 == 0) {
                bVar1 = false;
                local_128 = 1;
              }
              else {
                iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-resp_text");
                if (iVar11 == 0) {
                  bVar1 = false;
                  local_118 = 1;
                }
                else {
                  iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-reqin");
                  iVar11 = iVar17;
                  if (iVar8 == 0) {
                    if (*(int *)(iVar14 + 4) == 0) goto LAB_00471a70;
                    bVar1 = false;
                    iVar4 = iVar14 + 4;
                    local_184 = *(int *)(iVar14 + 4);
                  }
                  else {
                    iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-respin");
                    if (iVar8 == 0) {
                      if (*(int *)(iVar14 + 4) == 0) goto LAB_00471a70;
                      bVar1 = false;
                      iVar4 = iVar14 + 4;
                      local_fc = *(int *)(iVar14 + 4);
                    }
                    else {
                      iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-signer");
                      if (iVar8 == 0) {
                        if (*(int *)(iVar14 + 4) == 0) goto LAB_00471a70;
                        bVar1 = false;
                        iVar4 = iVar14 + 4;
                        local_13c = *(int *)(iVar14 + 4);
                      }
                      else {
                        iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-VAfile");
                        if (iVar8 == 0) {
                          if (*(int *)(iVar14 + 4) == 0) goto LAB_00471a70;
                          bVar1 = false;
                          local_10c = local_10c | 0x200;
                          iVar4 = iVar14 + 4;
                          local_f8 = *(int *)(iVar14 + 4);
                        }
                        else {
                          iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-sign_other");
                          if (iVar8 == 0) {
                            if (*(int *)(iVar14 + 4) == 0) goto LAB_00471a70;
                            bVar1 = false;
                            iVar4 = iVar14 + 4;
                            local_12c = *(int *)(iVar14 + 4);
                          }
                          else {
                            iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-verify_other");
                            if (iVar8 == 0) {
                              if (*(int *)(iVar14 + 4) == 0) goto LAB_00471a70;
                              bVar1 = false;
                              iVar4 = iVar14 + 4;
                              local_f8 = *(int *)(iVar14 + 4);
                            }
                            else {
                              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-CAfile");
                              if (iVar8 == 0) {
                                if (*(int *)(iVar14 + 4) == 0) goto LAB_00471a70;
                                bVar1 = false;
                                iVar4 = iVar14 + 4;
                                local_e8 = *(int *)(iVar14 + 4);
                              }
                              else {
                                iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-CApath");
                                if (iVar8 == 0) {
                                  if (*(int *)(iVar14 + 4) == 0) goto LAB_00471a70;
                                  bVar1 = false;
                                  iVar4 = iVar14 + 4;
                                  local_e4 = *(int *)(iVar14 + 4);
                                }
                                else {
                                  iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-validity_period")
                                  ;
                                  if (iVar8 == 0) {
                                    if (*(int *)(iVar14 + 4) == 0) goto LAB_00471a70;
                                    iVar4 = iVar14 + 4;
                                    local_f0 = (*(code *)PTR_strtol_006aaa68)
                                                         (*(int *)(iVar14 + 4),0,10);
                                    if (-1 < local_f0) goto LAB_004719ac;
                                    (*(code *)PTR_BIO_printf_006a7f38)
                                              (*(undefined4 *)puVar2,"Illegal validity period %s\n",
                                               *(undefined4 *)(iVar14 + 4));
                                    bVar1 = true;
                                  }
                                  else {
                                    iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-status_age");
                                    if (iVar8 == 0) {
                                      if (*(int *)(iVar14 + 4) == 0) goto LAB_00471a70;
                                      iVar4 = iVar14 + 4;
                                      local_ec = (*(code *)PTR_strtol_006aaa68)
                                                           (*(int *)(iVar14 + 4),0,10);
                                      if (-1 < local_ec) goto LAB_004719ac;
                                      (*(code *)PTR_BIO_printf_006a7f38)
                                                (*(undefined4 *)puVar2,"Illegal validity age %s\n",
                                                 *(undefined4 *)(iVar14 + 4));
                                      bVar1 = true;
                                    }
                                    else {
                                      iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-signkey");
                                      if (iVar8 == 0) {
                                        if (*(int *)(iVar14 + 4) == 0) goto LAB_00471a70;
                                        bVar1 = false;
                                        iVar4 = iVar14 + 4;
                                        local_148 = *(int *)(iVar14 + 4);
                                      }
                                      else {
                                        iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-reqout");
                                        if (iVar8 == 0) {
                                          if (*(int *)(iVar14 + 4) == 0) goto LAB_00471a70;
                                          bVar1 = false;
                                          iVar4 = iVar14 + 4;
                                          local_138 = *(int *)(iVar14 + 4);
                                        }
                                        else {
                                          iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-respout")
                                          ;
                                          if (iVar8 == 0) {
                                            if (*(int *)(iVar14 + 4) == 0) goto LAB_00471a70;
                                            bVar1 = false;
                                            iVar4 = iVar14 + 4;
                                            local_130 = *(int *)(iVar14 + 4);
                                          }
                                          else {
                                            iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-path");
                                            if (iVar8 == 0) {
                                              if (*(undefined **)(iVar14 + 4) == (undefined *)0x0)
                                              goto LAB_00471a70;
                                              bVar1 = false;
                                              iVar4 = iVar14 + 4;
                                              local_c4 = *(undefined **)(iVar14 + 4);
                                            }
                                            else {
                                              iVar8 = (*(code *)PTR_strcmp_006aac20)
                                                                (pcVar20,"-issuer");
                                              if (iVar8 != 0) {
                                                iVar8 = (*(code *)PTR_strcmp_006aac20)
                                                                  (pcVar20,"-cert");
                                                if (iVar8 == 0) {
                                                  if (*(int *)(iVar14 + 4) == 0) goto LAB_00471a70;
                                                  (*(code *)PTR_X509_free_006a7f90)(local_158);
                                                  local_158 = load_cert(*(undefined4 *)puVar2,
                                                                        *(undefined4 *)(iVar14 + 4),
                                                                        3,0,0,local_178);
                                                  if (local_158 == 0) goto LAB_00472a0c;
                                                  if (local_17c == 0) {
                                                    local_17c = (*(code *)PTR_EVP_sha1_006a86c4)();
                                                  }
                                                  if (local_160 == 0) {
LAB_00473d18:
                                                    (*(code *)PTR_BIO_printf_006a7f38)
                                                              (*(undefined4 *)puVar2,
                                                               "No issuer certificate specified\n");
                                                    goto LAB_00472a0c;
                                                  }
                                                  if ((local_b8 != 0) ||
                                                     (local_b8 = (*(code *)
                                                  PTR_OCSP_REQUEST_new_006a886c)(), local_b8 != 0))
                                                  {
                                                    iVar4 = (*(code *)PTR_OCSP_cert_to_id_006a8870)
                                                                      (local_17c,local_158,local_160
                                                                      );
joined_r0x00473e14:
                                                    if (iVar4 != 0) {
                                                      iVar11 = (*(code *)PTR_sk_push_006a80a8)
                                                                         (local_15c,iVar4);
                                                      if ((iVar11 != 0) &&
                                                         (iVar11 = (*(code *)
                                                  PTR_OCSP_request_add0_id_006a8874)(local_b8,iVar4)
                                                  , iVar11 != 0)) {
                                                    iVar14 = (*(code *)PTR_sk_push_006a80a8)
                                                                       (local_154,
                                                                        *(undefined4 *)(iVar14 + 4))
                                                    ;
                                                    if (iVar14 != 0) {
                                                      bVar1 = false;
                                                      iVar4 = iVar14 + 4;
                                                      goto LAB_00471934;
                                                    }
                                                    goto LAB_00472a0c;
                                                  }
                                                  }
                                                  }
                                                }
                                                else {
                                                  iVar8 = (*(code *)PTR_strcmp_006aac20)
                                                                    (pcVar20,"-serial");
                                                  if (iVar8 != 0) {
                                                    iVar8 = (*(code *)PTR_strcmp_006aac20)
                                                                      (pcVar20,"-index");
                                                    if (iVar8 == 0) {
                                                      if (*(int *)(iVar14 + 4) == 0)
                                                      goto LAB_00471a70;
                                                      bVar1 = false;
                                                      iVar4 = iVar14 + 4;
                                                      local_134 = *(int *)(iVar14 + 4);
                                                    }
                                                    else if (((pcVar20[1] == 'C') &&
                                                             (pcVar20[2] == 'A')) &&
                                                            (pcVar20[3] == '\0')) {
                                                      if (*(int *)(iVar14 + 4) == 0)
                                                      goto LAB_00471a70;
                                                      bVar1 = false;
                                                      iVar4 = iVar14 + 4;
                                                      local_174 = *(int *)(iVar14 + 4);
                                                    }
                                                    else {
                                                      iVar8 = (*(code *)PTR_strcmp_006aac20)
                                                                        (pcVar20,"-nmin");
                                                      if (iVar8 == 0) {
                                                        if (*(int *)(iVar14 + 4) == 0) {
                                                          bVar1 = false;
                                                        }
                                                        else {
                                                          local_170 = (undefined *)
                                                                      (*(code *)PTR_strtol_006aaa68)
                                                                                (*(int *)(iVar14 + 4
                                                                                         ),0,10);
                                                          if ((int)local_170 < 0) {
                                                            (*(code *)PTR_BIO_printf_006a7f38)
                                                                      (*(undefined4 *)puVar2,
                                                                       "Illegal update period %s\n",
                                                                       *(undefined4 *)(iVar14 + 4));
                                                            bVar1 = true;
                                                            iVar14 = iVar14 + 4;
                                                          }
                                                          else {
                                                            bVar1 = false;
                                                            iVar14 = iVar14 + 4;
                                                          }
                                                        }
                                                        if (local_120 != -1) goto LAB_00471a70;
                                                        local_120 = 0;
                                                        iVar4 = iVar14;
                                                      }
                                                      else {
                                                        iVar8 = (*(code *)PTR_strcmp_006aac20)
                                                                          (pcVar20,"-nrequest");
                                                        if (iVar8 == 0) {
                                                          if (*(int *)(iVar14 + 4) == 0)
                                                          goto LAB_00471a70;
                                                          iVar4 = iVar14 + 4;
                                                          local_144 = (*(code *)PTR_strtol_006aaa68)
                                                                                (*(int *)(iVar14 + 4
                                                                                         ),0,10);
                                                          if (-1 < local_144) goto LAB_004719ac;
                                                          (*(code *)PTR_BIO_printf_006a7f38)
                                                                    (*(undefined4 *)puVar2,
                                                                     "Illegal accept count %s\n",
                                                                     *(undefined4 *)(iVar14 + 4));
                                                          bVar1 = true;
                                                        }
                                                        else {
                                                          iVar8 = (*(code *)PTR_strcmp_006aac20)
                                                                            (pcVar20,"-ndays");
                                                          if (iVar8 == 0) {
                                                            if (*(int *)(iVar14 + 4) == 0)
                                                            goto LAB_00471a70;
                                                            iVar4 = iVar14 + 4;
                                                            local_120 = (*(code *)
                                                  PTR_strtol_006aaa68)(*(int *)(iVar14 + 4),0,10);
                                                  if (-1 < local_120) goto LAB_004719ac;
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar2,
                                                             "Illegal update period %s\n",
                                                             *(undefined4 *)(iVar14 + 4));
                                                  bVar1 = true;
                                                  }
                                                  else {
                                                    iVar8 = (*(code *)PTR_strcmp_006aac20)
                                                                      (pcVar20,"-rsigner");
                                                    if (iVar8 == 0) {
                                                      if (*(int *)(iVar14 + 4) == 0)
                                                      goto LAB_00471a70;
                                                      bVar1 = false;
                                                      iVar4 = iVar14 + 4;
                                                      local_18c = *(int *)(iVar14 + 4);
                                                    }
                                                    else {
                                                      iVar8 = (*(code *)PTR_strcmp_006aac20)
                                                                        (pcVar20,"-rkey");
                                                      if (iVar8 == 0) {
                                                        if (*(int *)(iVar14 + 4) == 0)
                                                        goto LAB_00471a70;
                                                        bVar1 = false;
                                                        iVar4 = iVar14 + 4;
                                                        local_188 = *(int *)(iVar14 + 4);
                                                      }
                                                      else {
                                                        iVar11 = (*(code *)PTR_strcmp_006aac20)
                                                                           (pcVar20,"-rother");
                                                        if (iVar11 == 0) {
                                                          if (*(char **)(iVar14 + 4) == (char *)0x0)
                                                          {
                                                            bVar1 = true;
                                                          }
                                                          else {
                                                            bVar1 = false;
                                                            iVar4 = iVar14 + 4;
                                                            local_180 = *(char **)(iVar14 + 4);
                                                          }
                                                        }
                                                        else {
                                                          local_17c = (*(code *)
                                                  PTR_EVP_get_digestbyname_006a802c)(pcVar20 + 1);
                                                  bVar1 = local_17c == 0;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_00471934;
                                                  }
                                                  local_168 = *(int *)(iVar14 + 4);
                                                  if (local_168 == 0) goto LAB_00471a70;
                                                  if (local_17c == 0) {
                                                    local_17c = (*(code *)PTR_EVP_sha1_006a86c4)();
                                                    local_168 = *(int *)(iVar14 + 4);
                                                  }
                                                  if (local_160 == 0) goto LAB_00473d18;
                                                  if ((local_b8 != 0) ||
                                                     (local_b8 = (*(code *)
                                                  PTR_OCSP_REQUEST_new_006a886c)(), local_b8 != 0))
                                                  {
                                                    uVar6 = (*(code *)
                                                  PTR_X509_get_subject_name_006a8000)(local_160);
                                                  uVar7 = (*(code *)
                                                  PTR_X509_get0_pubkey_bitstr_006a8f18)(local_160);
                                                  iVar11 = (*(code *)PTR_s2i_ASN1_INTEGER_006a80b4)
                                                                     (0,local_168);
                                                  if (iVar11 != 0) {
                                                    iVar4 = (*(code *)PTR_OCSP_cert_id_new_006a8f1c)
                                                                      (local_17c,uVar6,uVar7,iVar11)
                                                    ;
                                                    (*(code *)PTR_ASN1_INTEGER_free_006a7f94)
                                                              (iVar11);
                                                    goto joined_r0x00473e14;
                                                  }
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar2,
                                                             "Error converting serial number %s\n",
                                                             local_168);
                                                  goto LAB_00472a0c;
                                                  }
                                                }
                                                (*(code *)PTR_BIO_printf_006a7f38)
                                                          (*(undefined4 *)puVar2,
                                                           "Error Creating OCSP request\n");
                                                goto LAB_00472a0c;
                                              }
                                              if (*(int *)(iVar14 + 4) == 0) goto LAB_00471a70;
                                              (*(code *)PTR_X509_free_006a7f90)(local_160);
                                              local_160 = load_cert(*(undefined4 *)puVar2,
                                                                    *(undefined4 *)(iVar14 + 4),3,0,
                                                                    0,local_16c);
                                              if (local_160 == 0) goto LAB_00472a0c;
                                              bVar1 = false;
                                              iVar4 = iVar14 + 4;
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
LAB_00471934:
    iVar14 = iVar4 + 4;
    local_104 = unaff_s7;
    if (!bVar1) {
      pcVar20 = *(char **)(iVar4 + 4);
      if ((pcVar20 == (char *)0x0) || (iVar11 = iVar17, *pcVar20 != '-')) goto LAB_00471af4;
LAB_00471954:
      iVar17 = (*(code *)PTR_strcmp_006aac20)(pcVar20,iVar16 + 0x2edc);
      if (iVar17 != 0) {
        iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar20,pcVar18 + -0x3f70);
        iVar17 = iVar11;
        if (iVar4 == 0) {
          if (*(int *)(iVar14 + 4) != 0) {
            iVar4 = iVar14 + 4;
            unaff_s7 = (char *)(*(code *)PTR_strtol_006aaa68)(*(int *)(iVar14 + 4),0,10);
            if ((int)unaff_s7 < 0) {
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar2,"Illegal timeout value %s\n",
                         *(undefined4 *)(iVar14 + 4));
              bVar1 = true;
            }
            else {
LAB_004719ac:
              bVar1 = false;
            }
            goto LAB_00471934;
          }
        }
        else {
          iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar20,puVar19);
          if (iVar4 == 0) {
            if (*(int *)(iVar14 + 4) != 0) {
              iVar4 = iVar14 + 4;
              iVar14 = (*(code *)PTR_OCSP_parse_url_006a8854)
                                 (*(int *)(iVar14 + 4),&local_cc,&local_c8,&local_c4,&local_c0);
              if (iVar14 != 0) goto LAB_004719ac;
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Error parsing URL\n");
              bVar1 = true;
              goto LAB_00471934;
            }
          }
          else {
            iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar20,local_164 + -0x26dc);
            if (iVar4 == 0) {
              if (*(int *)(iVar14 + 4) != 0) {
                bVar1 = false;
                iVar4 = iVar14 + 4;
                local_cc = *(int *)(iVar14 + 4);
                goto LAB_00471934;
              }
            }
            else {
              iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-port");
              if (iVar4 == 0) {
                if (*(int *)(iVar14 + 4) != 0) {
                  bVar1 = false;
                  iVar4 = iVar14 + 4;
                  local_c8 = *(int *)(iVar14 + 4);
                  goto LAB_00471934;
                }
              }
              else {
                iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-header");
                if (iVar4 != 0) {
                  iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-ignore_err");
                  iVar4 = iVar14;
                  if (iVar11 == 0) {
                    local_108 = 1;
                    bVar1 = false;
                    goto LAB_00471934;
                  }
                  iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-noverify");
                  if (iVar11 == 0) {
                    bVar1 = false;
                    local_f4 = 1;
                    goto LAB_00471934;
                  }
                  iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-nonce");
                  if (iVar11 == 0) {
                    bVar1 = false;
                    local_140 = 2;
                    goto LAB_00471934;
                  }
                  iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-no_nonce");
                  if (iVar11 == 0) {
                    local_140 = 0;
                    bVar1 = false;
                    goto LAB_00471934;
                  }
                  iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-resp_no_certs");
                  if (iVar11 == 0) {
                    local_110 = local_110 | 1;
                    bVar1 = false;
                    goto LAB_00471934;
                  }
                  iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-resp_key_id");
                  if (iVar11 == 0) {
                    local_110 = local_110 | 0x400;
                    bVar1 = false;
                    goto LAB_00471934;
                  }
                  iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-no_certs");
                  if (iVar11 == 0) {
                    bVar1 = false;
                    local_124 = 1;
                    goto LAB_00471934;
                  }
                  iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-no_signature_verify");
                  if (iVar11 == 0) {
                    local_10c = local_10c | 4;
                    bVar1 = false;
                    goto LAB_00471934;
                  }
                  iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-no_cert_verify");
                  if (iVar11 == 0) {
                    local_10c = local_10c | 0x10;
                    bVar1 = false;
                    goto LAB_00471934;
                  }
                  iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar20,"-no_chain");
                  if (iVar11 == 0) {
                    local_10c = local_10c | 8;
                    bVar1 = false;
                    goto LAB_00471934;
                  }
                  goto LAB_004736bc;
                }
                if ((*(int *)(iVar14 + 4) != 0) && (*(int *)(iVar14 + 8) != 0)) {
                  iVar11 = (*(code *)PTR_X509V3_add_value_006a8ea4)
                                     (*(int *)(iVar14 + 4),*(int *)(iVar14 + 8),&local_bc);
                  if (iVar11 == 0) goto LAB_00472a0c;
                  bVar1 = false;
                  iVar4 = iVar14 + 8;
                  goto LAB_00471934;
                }
              }
            }
          }
        }
LAB_00471a70:
        bVar1 = true;
        iVar17 = iVar11;
        iVar4 = iVar14;
        goto LAB_00471934;
      }
      iVar17 = *(int *)(iVar14 + 4);
      if (iVar17 == 0) goto LAB_00471a70;
      bVar1 = false;
      iVar4 = iVar14 + 4;
      goto LAB_00471934;
    }
    bVar1 = true;
LAB_00471af4:
    if (((((local_b8 == 0) && (local_184 == 0)) && (local_fc == 0)) &&
        ((local_c8 == 0 || (local_134 == 0)))) || (bVar1)) {
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"OCSP utility\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Usage ocsp [options]\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"where options are\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-out file          output filename\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-issuer file       issuer certificate\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-cert file         certificate to check\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-serial n          serial number to check\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-signer file       certificate to sign OCSP request with\n")
      ;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-signkey file      private key to sign OCSP request with\n")
      ;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,
                 "-sign_other file   additional certificates to include in signed request\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,
                 "-no_certs          don\'t include any certificates in signed request\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-req_text          print text form of request\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-resp_text         print text form of response\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,
                 "-text              print text form of request and response\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,
                 "-reqout file       write DER encoded OCSP request to \"file\"\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,
                 "-respout file      write DER encoded OCSP reponse to \"file\"\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,
                 "-reqin file        read DER encoded OCSP request from \"file\"\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,
                 "-respin file       read DER encoded OCSP reponse from \"file\"\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-nonce             add OCSP nonce to request\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-no_nonce          don\'t add OCSP nonce to request\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-url URL           OCSP responder URL\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-host host:n       send OCSP request to host on port n\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-path              path to use in OCSP request\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-CApath dir        trusted certificates directory\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-CAfile file       trusted certificates file\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-VAfile file       validator certificates file\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,
                 "-validity_period n maximum validity discrepancy in seconds\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-status_age n      maximum status age in seconds\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-noverify          don\'t verify response at all\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,
                 "-verify_other file additional certificates to search for signer\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-trust_other       don\'t verify additional certificates\n")
      ;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,
                 "-no_intern         don\'t search certificates contained in response for signer\n")
      ;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-no_signature_verify don\'t check signature on response\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-no_cert_verify    don\'t check signing certificate\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-no_chain          don\'t chain verify response\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,
                 "-no_cert_checks    don\'t do additional checks on signing certificate\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-port num\t\t port to run responder on\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-index file\t certificate status index file\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"-CA file\t\t CA certificate\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,
                 "-rsigner file\t responder certificate to sign responses with\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-rkey file\t responder key to sign responses with\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-rother file\t other certificates to include in response\n")
      ;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,
                 "-resp_no_certs     don\'t include any certificates in response\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-nmin n\t \t number of minutes before next update\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-ndays n\t \t number of days before next update\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,
                 "-resp_key_id       identify reponse by signing certificate key ID\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,
                 "-nrequest n        number of requests to accept (default unlimited)\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar2,"-<dgst alg>     use specified digest in the request\n");
LAB_00472a0c:
      iVar14 = 0;
      local_17c = 0;
LAB_00472a2c:
      local_188 = 0;
      local_164 = (char *)0x0;
      pcVar20 = (char *)0x0;
      pcVar18 = (char *)0x0;
      iVar17 = 0;
      puVar19 = (undefined *)0x1;
      local_184 = 0;
      iVar16 = 0;
      local_174 = 0;
      local_168 = 0;
      local_178 = (char *)0x0;
      local_18c = 0;
      goto LAB_00471618;
    }
    if (iVar17 == 0) {
      local_17c = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
    }
    else {
      local_17c = (*(code *)PTR_BIO_new_file_006a7fac)(iVar17,"w");
    }
    iVar14 = local_c8;
    if (local_17c == 0) {
      iVar14 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Error opening output file\n");
      goto LAB_00472a2c;
    }
    if (local_b8 == 0) {
      if (local_140 != 2) {
        local_140 = 0;
      }
      if (local_184 == 0) {
        if (local_c8 == 0) goto LAB_00471b38;
        uVar6 = (*(code *)PTR_BIO_f_buffer_006a8940)();
        iVar11 = (*(code *)PTR_BIO_new_006a7fa4)(uVar6);
        if (iVar11 == 0) {
          local_184 = 0;
        }
        else {
          local_184 = (*(code *)PTR_BIO_new_accept_006a8ef4)(iVar14);
          if (local_184 != 0) {
            (*(code *)PTR_BIO_ctrl_006a7f18)(local_184,0x76,2,iVar11);
            iVar14 = (*(code *)PTR_BIO_ctrl_006a7f18)(local_184,0x65,0,0);
            if (0 < iVar14) {
              pcVar18 = (char *)0x0;
              if (local_18c != 0) goto LAB_00471b44;
              local_e0 = 0;
              local_174 = 0;
              local_178 = (char *)0x0;
              goto LAB_00471c34;
            }
            iVar11 = 0;
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar2,"Error setting up accept BIO\n");
            (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
          }
        }
        iVar14 = 0;
        (*(code *)PTR_BIO_free_all_006a7f74)(local_184);
        (*(code *)PTR_BIO_free_006a7f70)(iVar11);
      }
      else {
        iVar14 = (*(code *)PTR_BIO_new_file_006a7fac)(local_184,&DAT_006347ac);
        if (iVar14 == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar2,"Error Opening OCSP request file\n");
        }
        else {
          local_b8 = (*(code *)PTR_ASN1_d2i_bio_006a82c4)
                               (PTR_OCSP_REQUEST_new_006a886c,PTR_d2i_OCSP_REQUEST_006a8e80,iVar14,0
                               );
          (*(code *)PTR_BIO_free_006a7f70)(iVar14);
          if (local_b8 != 0) goto LAB_00471b38;
          iVar14 = 0;
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Error reading OCSP request\n");
        }
      }
      goto LAB_00472a2c;
    }
LAB_00471b38:
    local_184 = 0;
    if (local_18c == 0) {
      pcVar18 = (char *)0x0;
      local_e0 = 0;
      local_174 = 0;
      local_178 = (char *)0x0;
LAB_00471c50:
      local_188 = 0;
      local_168 = 0;
      local_18c = 0;
      local_164 = (char *)0x0;
      iVar11 = (int)local_170 * 0x3c;
      iVar14 = 0;
LAB_00471cc4:
      do {
        unaff_s7 = pcVar18;
        if (local_184 != 0) {
          iVar16 = do_responder_isra_0(&local_b8,&local_b4,local_184);
          if (iVar16 != 0) {
            if (local_b8 != 0) goto LAB_00471cf4;
            iVar14 = (*(code *)PTR_OCSP_response_create_006a8ea8)(1,0);
            puVar10 = local_80;
            puVar13 = (undefined4 *)
                      "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
            ;
            do {
              puVar12 = puVar13 + 4;
              puVar9 = puVar10 + 4;
              uVar15 = puVar13[1];
              uVar7 = puVar13[2];
              uVar6 = puVar13[3];
              *puVar10 = *puVar13;
              puVar10[1] = uVar15;
              puVar10[2] = uVar7;
              puVar10[3] = uVar6;
              puVar10 = puVar9;
              puVar13 = puVar12;
            } while (puVar12 != (undefined4 *)0x645930);
            *(char *)puVar9 = s_HTTP_1_0_200_OK_Content_type__ap_006458e0[80];
            if (local_b4 == 0) goto LAB_004722fc;
LAB_004721ec:
            iVar16 = local_b4;
            uVar6 = (*(code *)PTR_i2d_OCSP_RESPONSE_006a8884)(iVar14,0);
            (*(code *)PTR_BIO_printf_006a7f38)(iVar16,local_80,uVar6);
            (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_OCSP_RESPONSE_006a8884,iVar16,iVar14);
            (*(code *)PTR_BIO_ctrl_006a7f18)(iVar16,0xb,0,0);
            goto LAB_004722fc;
          }
LAB_00472c58:
          puVar19 = (undefined *)0x1;
          iVar17 = 0;
          pcVar20 = (char *)0x0;
          iVar16 = 0;
          goto LAB_00471618;
        }
        if (local_b8 != 0) {
LAB_00471cf4:
          if (local_140 != 0) {
            (*(code *)PTR_OCSP_request_add1_nonce_006a8eac)(local_b8,0,0xffffffff);
          }
          puVar19 = PTR_bio_err_006a7f3c;
          if (local_13c != 0) {
            local_18c = load_cert(*(undefined4 *)puVar2,local_13c,3,0,0,"signer certificate");
            if (local_148 == 0) {
              local_148 = local_13c;
            }
            if (local_18c == 0) {
              uVar6 = *(undefined4 *)puVar19;
              pcVar20 = "Error loading signer certificate\n";
            }
            else {
              if (((local_12c != 0) &&
                  (local_188 = load_certs(*(undefined4 *)puVar19,local_12c,3,0,0,
                                          "signer certificates"), local_188 == 0)) ||
                 (local_168 = load_key(*(undefined4 *)puVar2,local_148,3,0,0,0,"signer private key")
                 , local_168 == 0)) goto LAB_00472c58;
              iVar16 = (*(code *)PTR_OCSP_request_sign_006a8eb0)
                                 (local_b8,local_18c,local_168,0,local_188,local_124);
              if (iVar16 != 0) goto LAB_00471dec;
              pcVar20 = "Error signing OCSP request\n";
              uVar6 = *(undefined4 *)PTR_bio_err_006a7f3c;
            }
            goto LAB_00472c0c;
          }
LAB_00471dec:
          if ((local_128 != 0) && (local_b8 != 0)) {
            (*(code *)PTR_OCSP_REQUEST_print_006a8eb4)(local_17c,local_b8,0);
          }
          if (local_138 == 0) {
LAB_00471e64:
            if (local_134 == 0) goto LAB_004722b0;
            if (((local_174 == 0) || (local_178 == (char *)0x0)) || (pcVar18 == (char *)0x0)) {
              uVar6 = *(undefined4 *)puVar2;
              pcVar20 = "Need a responder certificate, key and CA for this operation!\n";
              goto LAB_00472c0c;
            }
            if ((local_164 == (char *)0x0) &&
               ((local_164 = (char *)load_index(local_134,0), local_164 == (char *)0x0 ||
                (iVar16 = index_index(local_164), iVar16 == 0)))) goto LAB_00472c58;
            goto LAB_00471e90;
          }
          iVar16 = (*(code *)PTR_BIO_new_file_006a7fac)(local_138,&DAT_00632de8);
          if (iVar16 != 0) {
            (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_OCSP_REQUEST_006a8eb8,iVar16,local_b8);
            (*(code *)PTR_BIO_free_006a7f70)(iVar16);
            goto LAB_00471e64;
          }
          uVar6 = *(undefined4 *)puVar2;
          iVar11 = local_138;
LAB_00472fcc:
          puVar19 = (undefined *)0x1;
          iVar17 = 0;
          (*(code *)PTR_BIO_printf_006a7f38)(uVar6,"Error opening file %s\n",iVar11);
          pcVar20 = (char *)0x0;
          goto LAB_00471618;
        }
        if (((local_13c != 0) || (local_138 != 0)) ||
           ((local_cc != 0 || ((local_140 != 0 || (local_134 != 0)))))) {
          uVar6 = *(undefined4 *)puVar2;
          pcVar20 = "Need an OCSP request for this operation!\n";
LAB_00472c0c:
          puVar19 = (undefined *)0x1;
          (*(code *)PTR_BIO_printf_006a7f38)(uVar6,pcVar20);
          iVar17 = 0;
          pcVar20 = (char *)0x0;
          iVar16 = 0;
          goto LAB_00471618;
        }
LAB_004722b0:
        if (local_164 == (char *)0x0) {
          if (local_cc != 0) {
            iVar14 = process_responder(*(undefined4 *)puVar2,local_b8,local_cc,local_c4,local_c8,
                                       local_c0,local_bc,local_104);
            if (iVar14 == 0) goto LAB_00472c58;
            goto LAB_004722fc;
          }
          if (local_fc != 0) {
            iVar16 = (*(code *)PTR_BIO_new_file_006a7fac)(local_fc,&DAT_006347ac);
            if (iVar16 != 0) {
              iVar14 = (*(code *)PTR_ASN1_d2i_bio_006a82c4)
                                 (PTR_OCSP_RESPONSE_new_006a8ef0,PTR_d2i_OCSP_RESPONSE_006a8a28,
                                  iVar16,0);
              (*(code *)PTR_BIO_free_006a7f70)(iVar16);
              if (iVar14 == 0) {
                uVar6 = *(undefined4 *)puVar2;
                pcVar20 = "Error reading OCSP response\n";
                goto LAB_00472c0c;
              }
              goto LAB_004722fc;
            }
            puVar19 = (undefined *)0x1;
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar2,"Error Opening OCSP response file\n");
            iVar17 = 0;
            pcVar20 = (char *)0x0;
            goto LAB_00471618;
          }
          break;
        }
LAB_00471e90:
        iVar14 = local_b8;
        iVar16 = (*(code *)PTR_OCSP_request_onereq_count_006a8ebc)(local_b8);
        if (iVar16 < 1) {
          iVar17 = 0;
          iVar14 = (*(code *)PTR_OCSP_response_create_006a8ea8)(1,0);
          local_180 = (char *)0x0;
          local_16c = (char *)0x0;
          local_170 = (undefined *)0x0;
        }
        else {
          local_180 = (char *)(*(code *)PTR_OCSP_BASICRESP_new_006a8ec0)();
          local_170 = (undefined *)(*(code *)PTR_X509_gmtime_adj_006a808c)(0,0);
          if (local_120 == -1) {
            local_16c = (char *)0x0;
          }
          else {
            local_16c = (char *)(*(code *)PTR_X509_gmtime_adj_006a808c)
                                          (0,local_120 * 0x15180 + iVar11);
          }
          iVar17 = 0;
          iVar4 = 0;
          do {
            while( true ) {
              uVar6 = (*(code *)PTR_OCSP_request_onereq_get0_006a8ecc)(iVar14,iVar4);
              uVar6 = (*(code *)PTR_OCSP_onereq_get0_id_006a8ed0)(uVar6);
              (*(code *)PTR_OCSP_id_get0_info_006a8ec4)(0,&local_ac,0,0,uVar6);
              uVar7 = (*(code *)PTR_OBJ_obj2nid_006a822c)(local_ac);
              uVar7 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar7);
              iVar8 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar7);
              if (iVar8 == 0) {
                iVar14 = (*(code *)PTR_OCSP_response_create_006a8ea8)(2,0);
                goto LAB_00472150;
              }
              if (iVar17 != 0) {
                (*(code *)PTR_OCSP_CERTID_free_006a8860)(iVar17);
              }
              iVar17 = (*(code *)PTR_OCSP_cert_to_id_006a8870)(iVar8,0,pcVar18);
              iVar8 = (*(code *)PTR_OCSP_id_issuer_cmp_006a8ed4)(iVar17,uVar6);
              if (iVar8 == 0) break;
LAB_004720bc:
              uVar7 = 2;
LAB_004720c8:
              iVar4 = iVar4 + 1;
              (*(code *)PTR_OCSP_basic_add1_status_006a8ed8)
                        (local_180,uVar6,uVar7,0,0,local_170,local_16c);
              if (iVar16 == iVar4) goto LAB_004720f4;
            }
            (*(code *)PTR_OCSP_id_get0_info_006a8ec4)(0,0,0,&local_b0,uVar6);
            local_98 = 0;
            local_94 = 0;
            local_90 = 0;
            local_8c = 0;
            local_88 = 0;
            local_84 = 0;
            iVar8 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(local_b0,0);
            if (iVar8 == 0) {
              (*(code *)PTR_OpenSSLDie_006a8d4c)("ocsp.c",0x48d,&DAT_00645760);
            }
            if (*(int *)(iVar8 + 4) == 0) {
              uVar7 = (*(code *)PTR_BUF_strdup_006a80dc)("00");
            }
            else {
              uVar7 = (*(code *)PTR_BN_bn2hex_006a8118)(iVar8);
            }
            local_8c = uVar7;
            (*(code *)PTR_BN_free_006a811c)(iVar8);
            ppcVar5 = (char **)(*(code *)PTR_TXT_DB_get_by_index_006a8120)
                                         (*(undefined4 *)(local_164 + 4),3,&local_98);
            (*(code *)PTR_CRYPTO_free_006a7f88)(uVar7);
            if (ppcVar5 == (char **)0x0) goto LAB_004720bc;
            if (**ppcVar5 == 'V') {
              uVar7 = 0;
              goto LAB_004720c8;
            }
            if (**ppcVar5 == 'R') {
              local_a8 = 0;
              local_a4 = 0;
              local_a0 = 0;
              local_9c = -1;
              (*(code *)PTR_unpack_revinfo_006a8ec8)
                        (&local_a4,&local_9c,&local_a8,&local_a0,ppcVar5[2]);
              uVar6 = (*(code *)PTR_OCSP_basic_add1_status_006a8ed8)
                                (local_180,uVar6,1,local_9c,local_a4,local_170,local_16c);
              if (local_a0 == 0) {
                if (local_a8 != 0) {
                  (*(code *)PTR_OCSP_SINGLERESP_add1_ext_i2d_006a8ee8)(uVar6,0x1ae,local_a8,0,0);
                }
              }
              else {
                (*(code *)PTR_OCSP_SINGLERESP_add1_ext_i2d_006a8ee8)(uVar6,0x8e,local_a0,0,0);
              }
              (*(code *)PTR_ASN1_OBJECT_free_006a8104)(local_a8);
              (*(code *)PTR_ASN1_TIME_free_006a8150)(local_a4);
              (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a8138)(local_a0);
            }
            iVar4 = iVar4 + 1;
          } while (iVar16 != iVar4);
LAB_004720f4:
          (*(code *)PTR_OCSP_copy_nonce_006a8edc)(local_180,iVar14);
          (*(code *)PTR_OCSP_basic_sign_006a8ee0)
                    (local_180,local_178,local_174,0,local_e0,local_110);
          iVar14 = (*(code *)PTR_OCSP_response_create_006a8ea8)(0,local_180);
        }
LAB_00472150:
        (*(code *)PTR_ASN1_TIME_free_006a8150)(local_170);
        (*(code *)PTR_ASN1_TIME_free_006a8150)(local_16c);
        (*(code *)PTR_OCSP_CERTID_free_006a8860)(iVar17);
        (*(code *)PTR_OCSP_BASICRESP_free_006a8ea0)(local_180);
        if (local_b4 != 0) {
          puVar10 = (undefined4 *)
                    "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
          ;
          puVar13 = local_80;
          do {
            puVar9 = puVar10 + 4;
            puVar12 = puVar13 + 4;
            uVar15 = puVar10[1];
            uVar7 = puVar10[2];
            uVar6 = puVar10[3];
            *puVar13 = *puVar10;
            puVar13[1] = uVar15;
            puVar13[2] = uVar7;
            puVar13[3] = uVar6;
            puVar10 = puVar9;
            puVar13 = puVar12;
          } while (puVar9 != (undefined4 *)0x645930);
          *(char *)puVar12 = s_HTTP_1_0_200_OK_Content_type__ap_006458e0[80];
          goto LAB_004721ec;
        }
LAB_004722fc:
        if (local_130 != 0) {
          iVar16 = (*(code *)PTR_BIO_new_file_006a7fac)(local_130,&DAT_00632de8);
          if (iVar16 == 0) {
            uVar6 = *(undefined4 *)puVar2;
            iVar11 = local_130;
            goto LAB_00472fcc;
          }
          (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_OCSP_RESPONSE_006a8884,iVar16,iVar14);
          (*(code *)PTR_BIO_free_006a7f70)(iVar16);
        }
        iVar16 = (*(code *)PTR_OCSP_response_status_006a8ee4)(iVar14);
        if (iVar16 == 0) {
          if (local_118 != 0) {
            (*(code *)PTR_OCSP_RESPONSE_print_006a8888)(local_17c,iVar14,0);
          }
          if (local_b4 == 0) {
            pcVar20 = (char *)setup_verify(*(undefined4 *)puVar2,local_e8,local_e4);
            if (pcVar20 == (char *)0x0) {
              puVar19 = (undefined *)0x1;
              iVar17 = 0;
              iVar16 = 0;
              goto LAB_00471618;
            }
            if (local_f8 == 0) {
              iVar17 = 0;
            }
            else {
              iVar17 = load_certs(*(undefined4 *)PTR_bio_err_006a7f3c,local_f8,3,0,0,
                                  "validator certificate");
              if (iVar17 == 0) {
                puVar19 = (undefined *)0x1;
                iVar16 = 0;
                goto LAB_00471618;
              }
            }
            iVar16 = (*(code *)PTR_OCSP_response_get1_basic_006a8ef8)(iVar14);
            if (iVar16 == 0) {
              puVar19 = (undefined *)0x1;
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Error parsing response\n");
              goto LAB_00471618;
            }
            if (local_f4 == 0) {
              if ((local_b8 != 0) &&
                 (iVar11 = (*(code *)PTR_OCSP_check_nonce_006a8efc)(local_b8,iVar16), iVar11 < 1)) {
                if (iVar11 != -1) {
                  puVar19 = (undefined *)0x1;
                  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Nonce Verify error\n");
                  goto LAB_00471618;
                }
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2,"WARNING: no nonce in response\n");
              }
              iVar11 = (*(code *)PTR_OCSP_basic_verify_006a8f00)(iVar16,iVar17,pcVar20,local_10c);
              if (iVar11 < 0) {
                iVar11 = (*(code *)PTR_OCSP_basic_verify_006a8f00)(iVar16,0,pcVar20,0);
              }
              if (iVar11 < 1) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2,"Response Verify Failure\n");
                (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
              }
              else {
                (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Response verify OK\n");
              }
            }
            if (((local_b8 != 0) &&
                (iVar11 = (*(code *)PTR_sk_num_006a7f2c)(local_154), iVar11 != 0)) &&
               (iVar11 = (*(code *)PTR_sk_num_006a7f2c)(local_15c), iVar11 != 0)) {
              iVar11 = 0;
              local_180 = "s\n";
              local_170 = &DAT_00632848;
              local_16c = "s\n";
              goto LAB_004731a8;
            }
            puVar19 = (undefined *)0x0;
            goto LAB_00471618;
          }
          local_144 = local_144 - (uint)(0 < local_144);
          if (local_144 == 0) goto LAB_00472c58;
          (*(code *)PTR_BIO_free_all_006a7f74)();
          local_b4 = 0;
          (*(code *)PTR_OCSP_REQUEST_free_006a8864)(local_b8);
          local_b8 = 0;
          (*(code *)PTR_OCSP_RESPONSE_free_006a8868)(iVar14);
          iVar14 = 0;
          goto LAB_00471cc4;
        }
        uVar6 = (*(code *)PTR_OCSP_response_status_str_006a8eec)(iVar16);
        (*(code *)PTR_BIO_printf_006a7f38)(local_17c,"Responder Error: %s (%d)\n",uVar6,iVar16);
      } while (local_108 != 0);
      puVar19 = (undefined *)0x0;
      iVar17 = 0;
      pcVar20 = (char *)0x0;
      iVar16 = 0;
    }
    else {
LAB_00471b44:
      puVar19 = PTR_bio_err_006a7f3c;
      iVar14 = local_18c;
      if (local_188 != 0) {
        iVar14 = local_188;
      }
      local_178 = (char *)load_cert(*(undefined4 *)puVar2,local_18c,3,0,0,"responder certificate");
      if (local_178 == (char *)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar19,"Error loading responder certificate\n");
        pcVar18 = (char *)0x0;
LAB_00472e8c:
        local_164 = (char *)0x0;
        iVar14 = 0;
        puVar19 = (undefined *)0x1;
        local_188 = 0;
        iVar17 = 0;
        local_174 = 0;
        pcVar20 = (char *)0x0;
        local_168 = 0;
        local_18c = 0;
        iVar16 = 0;
      }
      else {
        pcVar18 = (char *)load_cert(*(undefined4 *)puVar19,local_174,3,0,0,"CA certificate");
        if (local_180 == (char *)0x0) {
          local_e0 = 0;
        }
        else {
          local_e0 = load_certs(*(undefined4 *)puVar19,local_180,3,0,0,
                                "responder other certificates");
          if (local_e0 == 0) goto LAB_00472e8c;
        }
        local_174 = load_key(*(undefined4 *)puVar2,iVar14,3,0,0,0,"responder private key");
        if (local_174 != 0) {
          if (local_184 != 0) {
LAB_00471c34:
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar2,"Waiting for OCSP client connections...\n");
          }
          goto LAB_00471c50;
        }
        iVar14 = 0;
        local_188 = 0;
        local_164 = (char *)0x0;
        local_168 = 0;
        puVar19 = (undefined *)0x1;
        local_18c = 0;
        iVar17 = 0;
        pcVar20 = (char *)0x0;
        iVar16 = 0;
      }
    }
  } while( true );
LAB_004731a8:
  iVar4 = (*(code *)PTR_sk_num_006a7f2c)(local_15c);
  if (iVar11 < iVar4) {
    local_148 = (*(code *)PTR_sk_value_006a7f24)(local_15c,iVar11);
    uVar6 = (*(code *)PTR_sk_value_006a7f24)(local_154,iVar11);
    (*(code *)PTR_BIO_printf_006a7f38)(local_17c,&DAT_00632848,uVar6);
    iVar4 = (*(code *)PTR_OCSP_resp_find_status_006a8f04)
                      (iVar16,local_148,&local_ac,&local_a8,&local_a4,&local_a0,&local_9c);
    if (iVar4 == 0) {
      (*(code *)PTR_BIO_puts_006a8058)(local_17c,"ERROR: No Status found.\n");
LAB_00473258:
      iVar11 = iVar11 + 1;
    }
    else {
      iVar4 = (*(code *)PTR_OCSP_check_validity_006a8f08)(local_a0,local_9c,local_f0,local_ec);
      if (iVar4 == 0) {
        (*(code *)PTR_BIO_puts_006a8058)(local_17c,"WARNING: Status times invalid.\n");
        (*(code *)PTR_ERR_print_errors_006a7f40)(local_17c);
      }
      uVar6 = (*(code *)PTR_OCSP_cert_status_str_006a8f0c)(local_ac);
      (*(code *)PTR_BIO_printf_006a7f38)(local_17c,"%s\n",uVar6);
      (*(code *)PTR_BIO_puts_006a8058)(local_17c,"\tThis Update: ");
      (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a8f10)(local_17c,local_a0);
      (*(code *)PTR_BIO_puts_006a8058)(local_17c,"\n");
      if (local_9c != 0) {
        (*(code *)PTR_BIO_puts_006a8058)(local_17c,"\tNext Update: ");
        (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a8f10)(local_17c,local_9c);
        (*(code *)PTR_BIO_puts_006a8058)(local_17c,"\n");
      }
      if (local_ac != 1) goto LAB_00473258;
      if (local_a8 != -1) {
        uVar6 = (*(code *)PTR_OCSP_crl_reason_str_006a8f14)();
        (*(code *)PTR_BIO_printf_006a7f38)(local_17c,"\tReason: %s\n",uVar6);
      }
      iVar11 = iVar11 + 1;
      (*(code *)PTR_BIO_puts_006a8058)(local_17c,"\tRevocation Time: ");
      (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a8f10)(local_17c,local_a4);
      (*(code *)PTR_BIO_puts_006a8058)(local_17c,"\n");
    }
    goto LAB_004731a8;
  }
  puVar19 = (undefined *)0x0;
  unaff_s7 = "%s\n";
  goto LAB_00471618;
}

