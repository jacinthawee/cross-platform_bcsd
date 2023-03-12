
undefined *
process_responder(undefined4 param_1,uint *param_2,undefined4 param_3,uint *param_4,int param_5,
                 int param_6,undefined4 param_7,int param_8)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  char **ppcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  char *pcVar15;
  undefined4 uVar16;
  uint *puVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  int unaff_s3;
  undefined **ppuVar22;
  undefined *puVar23;
  undefined **ppuVar24;
  uint *puVar25;
  undefined **unaff_s7;
  code *pcVar26;
  uint uStack_274;
  uint uStack_270;
  uint uStack_26c;
  char *pcStack_268;
  int iStack_264;
  char *pcStack_260;
  uint uStack_25c;
  undefined *puStack_258;
  char *pcStack_254;
  uint uStack_250;
  char *pcStack_24c;
  int iStack_248;
  undefined4 uStack_244;
  int iStack_240;
  undefined4 uStack_23c;
  uint uStack_230;
  int iStack_22c;
  int iStack_228;
  uint uStack_224;
  uint uStack_220;
  uint uStack_21c;
  uint uStack_218;
  uint uStack_214;
  int iStack_210;
  undefined4 uStack_20c;
  int iStack_208;
  int iStack_200;
  uint uStack_1f8;
  uint uStack_1f4;
  int iStack_1f0;
  undefined **ppuStack_1ec;
  uint uStack_1e4;
  uint uStack_1e0;
  int iStack_1dc;
  int iStack_1d8;
  int iStack_1d4;
  uint uStack_1d0;
  uint uStack_1cc;
  int iStack_1c8;
  uint uStack_1b4;
  uint uStack_1b0;
  undefined *puStack_1ac;
  int iStack_1a8;
  undefined4 uStack_1a4;
  int iStack_1a0;
  int iStack_19c;
  undefined4 uStack_198;
  int iStack_194;
  int iStack_190;
  undefined4 uStack_18c;
  int iStack_188;
  int iStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined4 auStack_168 [4];
  undefined auStack_158 [68];
  int iStack_114;
  undefined *puStack_110;
  undefined4 uStack_10c;
  uint *puStack_108;
  int iStack_104;
  int iStack_100;
  int iStack_fc;
  undefined *puStack_f8;
  undefined **ppuStack_f4;
  uint *puStack_f0;
  code *pcStack_ec;
  int *local_d8;
  undefined *local_d0;
  int *local_c8;
  undefined4 local_c4;
  uint local_bc;
  undefined *local_b8;
  int local_b4;
  undefined4 local_b0;
  uint auStack_ac [32];
  int local_2c;
  
  puStack_f8 = PTR___stack_chk_guard_006aabf0;
  local_d0 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_c4 = param_1;
  iVar4 = (*(code *)PTR_BIO_new_connect_006a8e84)(param_3);
  if (iVar4 == 0) {
    puStack_110 = (undefined *)0x0;
    pcVar15 = "Error creating connect BIO\n";
    (**(code **)(local_d0 + -0x7fa8))(local_c4);
    goto LAB_00471074;
  }
  if (param_5 != 0) {
    (**(code **)(local_d0 + -0x7fc8))(iVar4,100,1,param_5);
  }
  if (param_6 != 1) {
    param_6 = 0;
LAB_00470fa8:
    local_b8 = (undefined *)0x0;
    if (param_8 == -1) {
      iVar5 = (**(code **)(local_d0 + -0x7fc8))(iVar4,0x65,0,0);
      if (iVar5 < 1) {
LAB_00471484:
        (**(code **)(local_d0 + -0x7e88))(local_c4,"Error connecting BIO\n");
      }
      else {
        iVar5 = (**(code **)(local_d0 + -0x7fc8))(iVar4,0x69,0,&local_bc);
        if (iVar5 < 1) goto LAB_0047102c;
LAB_004710ec:
        param_4 = (uint *)(**(code **)(local_d0 + -0x7058))(iVar4,param_4,0,0xffffffff);
        if (param_4 != (uint *)0x0) {
          for (iVar5 = 0; iVar7 = (**(code **)(local_d0 + -0x7fb4))(param_7), iVar5 < iVar7;
              iVar5 = iVar5 + 1) {
            iVar7 = (**(code **)(local_d0 + -0x7fbc))(param_7,iVar5);
            pcVar15 = *(char **)(iVar7 + 4);
            iVar7 = (**(code **)(local_d0 + -0x7054))(param_4,pcVar15,*(undefined4 *)(iVar7 + 8));
            if (iVar7 == 0) goto LAB_0047127c;
          }
          pcVar15 = (char *)param_2;
          iVar5 = (**(code **)(local_d0 + -0x7050))(param_4);
          if (iVar5 != 0) {
            local_c8 = &local_b4;
            unaff_s7 = &local_b8;
            param_2 = auStack_ac;
            param_7 = 0x8000001f;
            do {
              if (param_8 == -1) goto LAB_004712e4;
              pcVar15 = (char *)param_4;
              iVar5 = (**(code **)(local_d0 + -0x704c))(unaff_s7);
              if (iVar5 != -1) goto LAB_0047127c;
              (**(code **)(local_d0 + -0x53e0))(param_2,0,0x80);
              iVar5 = (**(code **)(local_d0 + -0x5338))(local_bc);
              pcVar26 = *(code **)(local_d0 + -0x758c);
              local_b0 = 0;
              local_b4 = param_8;
              auStack_ac[iVar5] = 1 << (local_bc & 0x1f) | auStack_ac[iVar5];
              iVar5 = (*pcVar26)(iVar4,1);
              if (iVar5 == 0) {
                iVar5 = (**(code **)(local_d0 + -0x758c))(iVar4,2);
                if (iVar5 == 0) {
                  pcVar15 = "Unexpected retry condition\n";
                  (**(code **)(local_d0 + -0x7e88))(local_c4);
                  goto LAB_0047127c;
                }
                local_d8 = local_c8;
                iVar5 = (**(code **)(local_d0 + -0x5314))(local_bc + 1,0,param_2,0);
              }
              else {
                local_d8 = local_c8;
                iVar5 = (**(code **)(local_d0 + -0x5314))(local_bc + 1,param_2,0,0);
              }
              if (iVar5 == 0) {
                pcVar15 = "Timeout on request\n";
                (**(code **)(local_d0 + -0x7e88))(local_c4);
                goto LAB_0047127c;
              }
            } while (iVar5 != -1);
            pcVar15 = "Select error\n";
            (**(code **)(local_d0 + -0x7e88))(local_c4);
          }
LAB_0047127c:
          pcVar26 = *(code **)(local_d0 + -0x7048);
          goto LAB_00471280;
        }
      }
    }
    else {
      (**(code **)(local_d0 + -0x7fc8))(iVar4,0x66,1);
      iVar5 = (**(code **)(local_d0 + -0x7fc8))(iVar4,0x65,0,0);
      if (0 < iVar5) {
        iVar5 = (**(code **)(local_d0 + -0x7fc8))(iVar4,0x69,0,&local_bc);
        if (0 < iVar5) goto LAB_004710ec;
LAB_0047102c:
        pcVar15 = "Can\'t get connection fd\n";
        (**(code **)(local_d0 + -0x7e88))(local_c4);
        puStack_110 = local_b8;
        if (local_b8 == (undefined *)0x0) goto LAB_00471460;
        goto LAB_00471048;
      }
      iVar5 = (**(code **)(local_d0 + -0x758c))(iVar4,8);
      if (iVar5 == 0) goto LAB_00471484;
      iVar5 = (**(code **)(local_d0 + -0x7fc8))(iVar4,0x69,0,&local_bc);
      if (iVar5 < 1) goto LAB_0047102c;
      (**(code **)(local_d0 + -0x53e0))(auStack_ac,0,0x80);
      iVar5 = (**(code **)(local_d0 + -0x5338))(local_bc);
      pcVar26 = *(code **)(local_d0 + -0x5314);
      local_b0 = 0;
      local_b4 = param_8;
      local_d8 = &local_b4;
      auStack_ac[iVar5] = 1 << (local_bc & 0x1f) | auStack_ac[iVar5];
      iVar5 = (*pcVar26)(local_bc + 1,0,auStack_ac,0);
      if (iVar5 != 0) goto LAB_004710ec;
      (**(code **)(local_d0 + -0x7e88))(local_c4,"Timeout on connect\n");
    }
LAB_00471460:
    puVar6 = *(undefined4 **)(local_d0 + -0x7fa4);
    goto LAB_00471464;
  }
  uVar9 = (**(code **)(local_d0 + -0x7470))();
  param_6 = (**(code **)(local_d0 + -0x7558))(uVar9);
  if (param_6 != 0) {
    (**(code **)(local_d0 + -0x7694))(param_6,0x21,4,0);
    uVar9 = (**(code **)(local_d0 + -0x7044))(param_6,1);
    iVar4 = (**(code **)(local_d0 + -0x7920))(uVar9,iVar4);
    goto LAB_00470fa8;
  }
  puStack_110 = (undefined *)0x0;
  pcVar15 = "Error creating SSL context.\n";
  (**(code **)(local_d0 + -0x7fa8))(local_c4);
LAB_00471050:
  (**(code **)(local_d0 + -0x7f6c))(iVar4);
  goto LAB_00471060;
LAB_004712e4:
  do {
    pcVar15 = (char *)param_4;
    iVar5 = (**(code **)(local_d0 + -0x704c))(unaff_s7);
  } while (iVar5 == -1);
  pcVar26 = *(code **)(local_d0 + -0x7048);
LAB_00471280:
  (*pcVar26)(param_4);
  puStack_110 = local_b8;
  if (local_b8 == (undefined *)0x0) {
    puVar6 = *(undefined4 **)(local_d0 + -0x7fa4);
LAB_00471464:
    pcVar15 = "Error querying OCSP responsder\n";
    (**(code **)(local_d0 + -0x7fa8))(*puVar6);
    puStack_110 = (undefined *)0x0;
  }
LAB_00471048:
  if (iVar4 != 0) goto LAB_00471050;
LAB_00471060:
  unaff_s3 = iVar4;
  if (param_6 != 0) {
    (**(code **)(local_d0 + -0x7568))(param_6);
  }
LAB_00471074:
  if (local_2c == *(int *)puStack_f8) {
    return puStack_110;
  }
  pcStack_ec = ocsp_main;
  (**(code **)(local_d0 + -0x5328))();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  puVar2 = PTR_bio_err_006a7f3c;
  iStack_1a8 = -1;
  iStack_100 = param_8;
  puStack_1ac = &DAT_0063ba98;
  uStack_1b4 = 0;
  uStack_1b0 = 0;
  uStack_1a4 = 0;
  iStack_1a0 = 0;
  iStack_19c = 0;
  iStack_114 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar4 = *(int *)PTR_bio_err_006a7f3c;
  uStack_10c = param_7;
  puStack_108 = param_4;
  iStack_104 = unaff_s3;
  iStack_fc = param_6;
  ppuStack_f4 = unaff_s7;
  puStack_f0 = param_2;
  if (iVar4 == 0) {
    iVar4 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *(int *)puVar2 = iVar4;
  }
  iVar4 = load_config(iVar4,0);
  if (iVar4 != 0) {
    (*(code *)PTR_SSL_load_error_strings_006a867c)();
    (*(code *)PTR_SSL_library_init_006a8980)();
    uStack_23c = (*(code *)PTR_sk_new_null_006a80a4)();
    uStack_244 = (*(code *)PTR_sk_new_null_006a80a4)();
    ppuVar24 = *(undefined ***)((int)pcVar15 + 4);
    if ((ppuVar24 != (undefined **)0x0) && (*(char *)ppuVar24 == '-')) {
      iStack_264 = 0;
      puStack_258 = (undefined *)0x0;
      uStack_25c = 0;
      iStack_208 = -1;
      uVar20 = 0;
      iStack_22c = -1;
      iVar4 = 0x630000;
      iStack_1d4 = -1;
      uStack_21c = 0;
      ppuVar22 = (undefined **)0x640000;
      iStack_1f0 = 0;
      puVar23 = &UNK_0064492c;
      iStack_1d8 = 300;
      uStack_1f8 = 0;
      pcStack_24c = "s\n";
      uStack_1f4 = 0;
      uStack_20c = 0;
      pcStack_268 = (char *)0x0;
      uStack_1e0 = 0;
      iStack_228 = 1;
      uStack_214 = 0;
      uStack_1cc = 0;
      uStack_1d0 = 0;
      iStack_200 = 0;
      pcStack_260 = "certificate";
      iStack_210 = 0;
      iStack_240 = 0;
      iStack_248 = 0;
      iStack_1dc = 0;
      uStack_274 = 0;
      uStack_230 = 0;
      uStack_224 = 0;
      uStack_218 = 0;
      uStack_220 = 0;
      uStack_1e4 = 0;
      uStack_26c = 0;
      pcStack_254 = "issuer certificate";
      uStack_270 = 0;
      unaff_s7 = (undefined **)0xffffffff;
      goto LAB_00471954;
    }
    puStack_258 = (undefined *)0x0;
    uStack_25c = 0;
    uVar19 = 0;
    uStack_21c = 0;
    uStack_270 = 0;
    iStack_208 = -1;
    iStack_22c = -1;
    iStack_1d4 = -1;
    iStack_1f0 = 0;
    uStack_1f8 = 0;
    iStack_1d8 = 300;
    uStack_1f4 = 0;
    uStack_20c = 0;
    ppuStack_1ec = (undefined **)0xffffffff;
    pcStack_268 = (char *)0x0;
    uStack_1e0 = 0;
    iStack_228 = 1;
    bVar1 = false;
    uStack_214 = 0;
    uStack_1cc = 0;
    uStack_1d0 = 0;
    iStack_200 = 0;
    iStack_210 = 0;
    iStack_240 = 0;
    iStack_248 = 0;
    iStack_1dc = 0;
    uStack_274 = 0;
    uStack_230 = 0;
    uStack_224 = 0;
    uStack_218 = 0;
    uStack_220 = 0;
    uStack_1e4 = 0;
    uStack_26c = 0;
    unaff_s7 = ppuVar24;
    goto LAB_00471af4;
  }
  puVar17 = (uint *)0x0;
  uStack_244 = 0;
  pcStack_24c = (char *)0x0;
  uStack_23c = 0;
  ppuVar22 = (undefined **)0x0;
  uStack_270 = 0;
  puVar23 = (undefined *)0x1;
  iStack_264 = 0;
  uVar19 = 0;
  uStack_26c = 0;
  ppuVar24 = (undefined **)0x0;
  uStack_25c = 0;
  iVar4 = 0;
  uStack_250 = 0;
  pcStack_260 = (char *)0x0;
  uStack_274 = 0;
  iStack_240 = 0;
  iStack_248 = 0;
LAB_00471618:
  do {
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
    (*(code *)PTR_X509_free_006a7f90)(uStack_274);
    (*(code *)PTR_X509_STORE_free_006a8384)(ppuVar24);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(uStack_250);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(uStack_25c);
    (*(code *)PTR_X509_free_006a7f90)(iStack_248);
    (*(code *)PTR_X509_free_006a7f90)(iStack_240);
    (*(code *)PTR_X509_free_006a7f90)(pcStack_260);
    (*(code *)PTR_X509_free_006a7f90)(ppuVar22);
    free_index(pcStack_24c);
    (*(code *)PTR_BIO_free_all_006a7f74)(iStack_19c);
    (*(code *)PTR_BIO_free_all_006a7f74)(uStack_26c);
    (*(code *)PTR_BIO_free_006a7f70)(iStack_264);
    (*(code *)PTR_OCSP_REQUEST_free_006a8864)(iStack_1a0);
    (*(code *)PTR_OCSP_RESPONSE_free_006a8868)(puVar17);
    (*(code *)PTR_OCSP_BASICRESP_free_006a8ea0)(iVar4);
    (*(code *)PTR_sk_free_006a7f80)(uStack_23c);
    (*(code *)PTR_sk_free_006a7f80)(uStack_244);
    (*(code *)PTR_sk_pop_free_006a8158)(uStack_270,PTR_X509_free_006a7f90);
    (*(code *)PTR_sk_pop_free_006a8158)(uVar19,PTR_X509_free_006a7f90);
    (*(code *)PTR_sk_pop_free_006a8158)(uStack_1a4,PTR_X509V3_conf_free_006a8c38);
    if (iStack_1a8 != -1) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(uStack_1b4);
      (*(code *)PTR_CRYPTO_free_006a7f88)(uStack_1b0);
      (*(code *)PTR_CRYPTO_free_006a7f88)(puStack_1ac);
    }
    if (iStack_114 == *(int *)puVar3) {
      return puVar23;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_004736bc:
    iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_cert_checks");
    if (iVar5 == 0) {
      uStack_1f4 = uStack_1f4 | 0x100;
      bVar1 = false;
    }
    else {
      iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_explicit");
      if (iVar5 == 0) {
        uStack_1f4 = uStack_1f4 | 0x20;
        bVar1 = false;
      }
      else {
        iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-trust_other");
        if (iVar5 == 0) {
          uStack_1f4 = uStack_1f4 | 0x200;
          bVar1 = false;
        }
        else {
          iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_intern");
          if (iVar5 == 0) {
            uStack_1f4 = uStack_1f4 | 2;
            bVar1 = false;
          }
          else {
            iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-text");
            if (iVar5 == 0) {
              bVar1 = false;
              iStack_200 = 1;
              iStack_210 = 1;
            }
            else {
              iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-req_text");
              if (iVar5 == 0) {
                bVar1 = false;
                iStack_210 = 1;
              }
              else {
                iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-resp_text");
                if (iVar5 == 0) {
                  bVar1 = false;
                  iStack_200 = 1;
                }
                else {
                  iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-reqin");
                  uVar20 = uVar19;
                  if (iVar5 == 0) {
                    puVar25 = puVar17 + 1;
                    if (*puVar25 == 0) goto LAB_00471a70;
                    bVar1 = false;
                    puVar17 = puVar17 + 1;
                    uStack_26c = *puVar25;
                  }
                  else {
                    iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-respin");
                    if (iVar5 == 0) {
                      puVar25 = puVar17 + 1;
                      if (*puVar25 == 0) goto LAB_00471a70;
                      bVar1 = false;
                      puVar17 = puVar17 + 1;
                      uStack_1e4 = *puVar25;
                    }
                    else {
                      iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-signer");
                      if (iVar5 == 0) {
                        puVar25 = puVar17 + 1;
                        if (*puVar25 == 0) goto LAB_00471a70;
                        bVar1 = false;
                        puVar17 = puVar17 + 1;
                        uStack_224 = *puVar25;
                      }
                      else {
                        iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-VAfile");
                        if (iVar5 == 0) {
                          puVar25 = puVar17 + 1;
                          if (*puVar25 == 0) goto LAB_00471a70;
                          bVar1 = false;
                          uStack_1f4 = uStack_1f4 | 0x200;
                          puVar17 = puVar17 + 1;
                          uStack_1e0 = *puVar25;
                        }
                        else {
                          iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-sign_other");
                          if (iVar5 == 0) {
                            puVar25 = puVar17 + 1;
                            if (*puVar25 == 0) goto LAB_00471a70;
                            bVar1 = false;
                            puVar17 = puVar17 + 1;
                            uStack_214 = *puVar25;
                          }
                          else {
                            iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-verify_other");
                            if (iVar5 == 0) {
                              puVar25 = puVar17 + 1;
                              if (*puVar25 == 0) goto LAB_00471a70;
                              bVar1 = false;
                              puVar17 = puVar17 + 1;
                              uStack_1e0 = *puVar25;
                            }
                            else {
                              iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-CAfile");
                              if (iVar5 == 0) {
                                puVar25 = puVar17 + 1;
                                if (*puVar25 == 0) goto LAB_00471a70;
                                bVar1 = false;
                                puVar17 = puVar17 + 1;
                                uStack_1d0 = *puVar25;
                              }
                              else {
                                iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-CApath");
                                if (iVar5 == 0) {
                                  puVar25 = puVar17 + 1;
                                  if (*puVar25 == 0) goto LAB_00471a70;
                                  bVar1 = false;
                                  puVar17 = puVar17 + 1;
                                  uStack_1cc = *puVar25;
                                }
                                else {
                                  iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                    (ppuVar24,"-validity_period");
                                  if (iVar5 == 0) {
                                    if (puVar17[1] == 0) goto LAB_00471a70;
                                    puVar25 = puVar17 + 1;
                                    iStack_1d8 = (*(code *)PTR_strtol_006aaa68)(puVar17[1],0,10);
                                    if (-1 < iStack_1d8) goto LAB_004719ac;
                                    (*(code *)PTR_BIO_printf_006a7f38)
                                              (*(undefined4 *)puVar2,"Illegal validity period %s\n",
                                               puVar17[1]);
                                    bVar1 = true;
                                    puVar17 = puVar25;
                                  }
                                  else {
                                    iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-status_age");
                                    if (iVar5 == 0) {
                                      if (puVar17[1] == 0) goto LAB_00471a70;
                                      puVar25 = puVar17 + 1;
                                      iStack_1d4 = (*(code *)PTR_strtol_006aaa68)(puVar17[1],0,10);
                                      if (-1 < iStack_1d4) goto LAB_004719ac;
                                      (*(code *)PTR_BIO_printf_006a7f38)
                                                (*(undefined4 *)puVar2,"Illegal validity age %s\n",
                                                 puVar17[1]);
                                      bVar1 = true;
                                      puVar17 = puVar25;
                                    }
                                    else {
                                      iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-signkey");
                                      if (iVar5 == 0) {
                                        puVar25 = puVar17 + 1;
                                        if (*puVar25 == 0) goto LAB_00471a70;
                                        bVar1 = false;
                                        puVar17 = puVar17 + 1;
                                        uStack_230 = *puVar25;
                                      }
                                      else {
                                        iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-reqout");
                                        if (iVar5 == 0) {
                                          puVar25 = puVar17 + 1;
                                          if (*puVar25 == 0) goto LAB_00471a70;
                                          bVar1 = false;
                                          puVar17 = puVar17 + 1;
                                          uStack_220 = *puVar25;
                                        }
                                        else {
                                          iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                            (ppuVar24,"-respout");
                                          if (iVar5 == 0) {
                                            puVar25 = puVar17 + 1;
                                            if (*puVar25 == 0) goto LAB_00471a70;
                                            bVar1 = false;
                                            puVar17 = puVar17 + 1;
                                            uStack_218 = *puVar25;
                                          }
                                          else {
                                            iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-path")
                                            ;
                                            if (iVar5 == 0) {
                                              puVar25 = puVar17 + 1;
                                              if ((undefined *)*puVar25 == (undefined *)0x0)
                                              goto LAB_00471a70;
                                              bVar1 = false;
                                              puVar17 = puVar17 + 1;
                                              puStack_1ac = (undefined *)*puVar25;
                                            }
                                            else {
                                              iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                (ppuVar24,"-issuer");
                                              if (iVar5 != 0) {
                                                iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                  (ppuVar24,"-cert");
                                                if (iVar5 == 0) {
                                                  if (puVar17[1] == 0) goto LAB_00471a70;
                                                  (*(code *)PTR_X509_free_006a7f90)(iStack_240);
                                                  iStack_240 = load_cert(*(undefined4 *)puVar2,
                                                                         puVar17[1],3,0,0,
                                                                         pcStack_260);
                                                  if (iStack_240 == 0) goto LAB_00472a0c;
                                                  if (iStack_264 == 0) {
                                                    iStack_264 = (*(code *)PTR_EVP_sha1_006a86c4)();
                                                  }
                                                  if (iStack_248 == 0) {
LAB_00473d18:
                                                    (*(code *)PTR_BIO_printf_006a7f38)
                                                              (*(undefined4 *)puVar2,
                                                               "No issuer certificate specified\n");
                                                    goto LAB_00472a0c;
                                                  }
                                                  if ((iStack_1a0 != 0) ||
                                                     (iStack_1a0 = (*(code *)
                                                  PTR_OCSP_REQUEST_new_006a886c)(), iStack_1a0 != 0)
                                                  ) {
                                                    iVar7 = (*(code *)PTR_OCSP_cert_to_id_006a8870)
                                                                      (iStack_264,iStack_240,
                                                                       iStack_248);
joined_r0x00473e14:
                                                    if (iVar7 != 0) {
                                                      iVar5 = (*(code *)PTR_sk_push_006a80a8)
                                                                        (uStack_244,iVar7);
                                                      if ((iVar5 != 0) &&
                                                         (iVar5 = (*(code *)
                                                  PTR_OCSP_request_add0_id_006a8874)
                                                            (iStack_1a0,iVar7), iVar5 != 0)) {
                                                    iVar5 = (*(code *)PTR_sk_push_006a80a8)
                                                                      (uStack_23c,puVar17[1]);
                                                    if (iVar5 != 0) {
                                                      bVar1 = false;
                                                      puVar17 = puVar17 + 1;
                                                      goto LAB_00471934;
                                                    }
                                                    goto LAB_00472a0c;
                                                  }
                                                  }
                                                  }
                                                }
                                                else {
                                                  iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                    (ppuVar24,"-serial");
                                                  if (iVar5 != 0) {
                                                    iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                      (ppuVar24,"-index");
                                                    if (iVar5 == 0) {
                                                      puVar25 = puVar17 + 1;
                                                      if (*puVar25 == 0) goto LAB_00471a70;
                                                      bVar1 = false;
                                                      puVar17 = puVar17 + 1;
                                                      uStack_21c = *puVar25;
                                                    }
                                                    else if (((*(char *)((int)ppuVar24 + 1) == 'C')
                                                             && (*(char *)((int)ppuVar24 + 2) == 'A'
                                                                )) && (*(char *)((int)ppuVar24 + 3)
                                                                       == '\0')) {
                                                      puVar25 = puVar17 + 1;
                                                      if (*puVar25 == 0) goto LAB_00471a70;
                                                      bVar1 = false;
                                                      puVar17 = puVar17 + 1;
                                                      uStack_25c = *puVar25;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                        (ppuVar24,"-nmin");
                                                      if (iVar5 == 0) {
                                                        if (puVar17[1] == 0) {
                                                          bVar1 = false;
                                                        }
                                                        else {
                                                          puStack_258 = (undefined *)
                                                                        (*(code *)
                                                  PTR_strtol_006aaa68)(puVar17[1],0,10);
                                                  if ((int)puStack_258 < 0) {
                                                    (*(code *)PTR_BIO_printf_006a7f38)
                                                              (*(undefined4 *)puVar2,
                                                               "Illegal update period %s\n",
                                                               puVar17[1]);
                                                    bVar1 = true;
                                                    puVar17 = puVar17 + 1;
                                                  }
                                                  else {
                                                    bVar1 = false;
                                                    puVar17 = puVar17 + 1;
                                                  }
                                                  }
                                                  if (iStack_208 != -1) goto LAB_00471a70;
                                                  iStack_208 = 0;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                      (ppuVar24,"-nrequest");
                                                    if (iVar5 == 0) {
                                                      if (puVar17[1] == 0) goto LAB_00471a70;
                                                      puVar25 = puVar17 + 1;
                                                      iStack_22c = (*(code *)PTR_strtol_006aaa68)
                                                                             (puVar17[1],0,10);
                                                      if (-1 < iStack_22c) goto LAB_004719ac;
                                                      (*(code *)PTR_BIO_printf_006a7f38)
                                                                (*(undefined4 *)puVar2,
                                                                 "Illegal accept count %s\n",
                                                                 puVar17[1]);
                                                      bVar1 = true;
                                                      puVar17 = puVar25;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                        (ppuVar24,"-ndays");
                                                      if (iVar5 == 0) {
                                                        if (puVar17[1] == 0) goto LAB_00471a70;
                                                        puVar25 = puVar17 + 1;
                                                        iStack_208 = (*(code *)PTR_strtol_006aaa68)
                                                                               (puVar17[1],0,10);
                                                        if (-1 < iStack_208) goto LAB_004719ac;
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar2,
                                                                   "Illegal update period %s\n",
                                                                   puVar17[1]);
                                                        bVar1 = true;
                                                        puVar17 = puVar25;
                                                      }
                                                      else {
                                                        iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                          (ppuVar24,"-rsigner");
                                                        if (iVar5 == 0) {
                                                          puVar25 = puVar17 + 1;
                                                          if (*puVar25 == 0) goto LAB_00471a70;
                                                          puVar17 = puVar17 + 1;
                                                          bVar1 = false;
                                                          uStack_274 = *puVar25;
                                                        }
                                                        else {
                                                          iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                            (ppuVar24,"-rkey");
                                                          if (iVar5 == 0) {
                                                            puVar25 = puVar17 + 1;
                                                            if (*puVar25 == 0) goto LAB_00471a70;
                                                            puVar17 = puVar17 + 1;
                                                            bVar1 = false;
                                                            uStack_270 = *puVar25;
                                                          }
                                                          else {
                                                            iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                              (ppuVar24,"-rother");
                                                            if (iVar5 == 0) {
                                                              ppcVar8 = (char **)(puVar17 + 1);
                                                              if (*ppcVar8 == (char *)0x0) {
                                                                bVar1 = true;
                                                              }
                                                              else {
                                                                puVar17 = puVar17 + 1;
                                                                bVar1 = false;
                                                                pcStack_268 = *ppcVar8;
                                                              }
                                                            }
                                                            else {
                                                              iStack_264 = (*(code *)
                                                  PTR_EVP_get_digestbyname_006a802c)
                                                            ((char *)((int)ppuVar24 + 1));
                                                  bVar1 = iStack_264 == 0;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_00471934;
                                                  }
                                                  uStack_250 = puVar17[1];
                                                  if (uStack_250 == 0) goto LAB_00471a70;
                                                  if (iStack_264 == 0) {
                                                    iStack_264 = (*(code *)PTR_EVP_sha1_006a86c4)();
                                                    uStack_250 = puVar17[1];
                                                  }
                                                  if (iStack_248 == 0) goto LAB_00473d18;
                                                  if ((iStack_1a0 != 0) ||
                                                     (iStack_1a0 = (*(code *)
                                                  PTR_OCSP_REQUEST_new_006a886c)(), iStack_1a0 != 0)
                                                  ) {
                                                    uVar9 = (*(code *)
                                                  PTR_X509_get_subject_name_006a8000)(iStack_248);
                                                  uVar10 = (*(code *)
                                                  PTR_X509_get0_pubkey_bitstr_006a8f18)(iStack_248);
                                                  iVar5 = (*(code *)PTR_s2i_ASN1_INTEGER_006a80b4)
                                                                    (0,uStack_250);
                                                  if (iVar5 != 0) {
                                                    iVar7 = (*(code *)PTR_OCSP_cert_id_new_006a8f1c)
                                                                      (iStack_264,uVar9,uVar10,iVar5
                                                                      );
                                                    (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar5)
                                                    ;
                                                    goto joined_r0x00473e14;
                                                  }
                                                  (*(code *)PTR_BIO_printf_006a7f38)
                                                            (*(undefined4 *)puVar2,
                                                             "Error converting serial number %s\n",
                                                             uStack_250);
                                                  goto LAB_00472a0c;
                                                  }
                                                }
                                                (*(code *)PTR_BIO_printf_006a7f38)
                                                          (*(undefined4 *)puVar2,
                                                           "Error Creating OCSP request\n");
                                                goto LAB_00472a0c;
                                              }
                                              if (puVar17[1] == 0) goto LAB_00471a70;
                                              (*(code *)PTR_X509_free_006a7f90)(iStack_248);
                                              iStack_248 = load_cert(*(undefined4 *)puVar2,
                                                                     puVar17[1],3,0,0,pcStack_254);
                                              if (iStack_248 == 0) goto LAB_00472a0c;
                                              bVar1 = false;
                                              puVar17 = puVar17 + 1;
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
    ppuStack_1ec = unaff_s7;
    if (!bVar1) {
      ppuVar24 = (undefined **)puVar17[1];
      if ((ppuVar24 == (undefined **)0x0) ||
         (uVar20 = uVar19, pcVar15 = (char *)puVar17, *(char *)ppuVar24 != '-')) goto LAB_00471af4;
LAB_00471954:
      puVar17 = (uint *)((int)pcVar15 + 4);
      iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,iVar4 + 0x2edc);
      if (iVar5 != 0) {
        iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,ppuVar22 + -0xfdc);
        uVar19 = uVar20;
        if (iVar5 == 0) {
          if (*(uint *)((int)pcVar15 + 8) != 0) {
            puVar25 = (uint *)((int)pcVar15 + 8);
            unaff_s7 = (undefined **)
                       (*(code *)PTR_strtol_006aaa68)(*(uint *)((int)pcVar15 + 8),0,10);
            if ((int)unaff_s7 < 0) {
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar2,"Illegal timeout value %s\n",
                         *(uint *)((int)pcVar15 + 8));
              bVar1 = true;
              puVar17 = puVar25;
            }
            else {
LAB_004719ac:
              bVar1 = false;
              puVar17 = puVar25;
            }
            goto LAB_00471934;
          }
        }
        else {
          iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,puVar23);
          if (iVar5 == 0) {
            if (*(uint *)((int)pcVar15 + 8) != 0) {
              puVar25 = (uint *)((int)pcVar15 + 8);
              iVar5 = (*(code *)PTR_OCSP_parse_url_006a8854)
                                (*(uint *)((int)pcVar15 + 8),&uStack_1b4,&uStack_1b0,&puStack_1ac,
                                 &iStack_1a8);
              if (iVar5 != 0) goto LAB_004719ac;
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Error parsing URL\n");
              bVar1 = true;
              puVar17 = puVar25;
              goto LAB_00471934;
            }
          }
          else {
            iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,pcStack_24c + -0x26dc);
            if (iVar5 == 0) {
              if (*(uint *)((int)pcVar15 + 8) != 0) {
                bVar1 = false;
                puVar17 = (uint *)((int)pcVar15 + 8);
                uStack_1b4 = *(uint *)((int)pcVar15 + 8);
                goto LAB_00471934;
              }
            }
            else {
              iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-port");
              if (iVar5 == 0) {
                if (*(uint *)((int)pcVar15 + 8) != 0) {
                  bVar1 = false;
                  puVar17 = (uint *)((int)pcVar15 + 8);
                  uStack_1b0 = *(uint *)((int)pcVar15 + 8);
                  goto LAB_00471934;
                }
              }
              else {
                iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-header");
                if (iVar5 != 0) {
                  iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-ignore_err");
                  if (iVar5 == 0) {
                    iStack_1f0 = 1;
                    bVar1 = false;
                    goto LAB_00471934;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-noverify");
                  if (iVar5 == 0) {
                    bVar1 = false;
                    iStack_1dc = 1;
                    goto LAB_00471934;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-nonce");
                  if (iVar5 == 0) {
                    bVar1 = false;
                    iStack_228 = 2;
                    goto LAB_00471934;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_nonce");
                  if (iVar5 == 0) {
                    iStack_228 = 0;
                    bVar1 = false;
                    goto LAB_00471934;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-resp_no_certs");
                  if (iVar5 == 0) {
                    uStack_1f8 = uStack_1f8 | 1;
                    bVar1 = false;
                    goto LAB_00471934;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-resp_key_id");
                  if (iVar5 == 0) {
                    uStack_1f8 = uStack_1f8 | 0x400;
                    bVar1 = false;
                    goto LAB_00471934;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_certs");
                  if (iVar5 == 0) {
                    bVar1 = false;
                    uStack_20c = 1;
                    goto LAB_00471934;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_signature_verify");
                  if (iVar5 == 0) {
                    uStack_1f4 = uStack_1f4 | 4;
                    bVar1 = false;
                    goto LAB_00471934;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_cert_verify");
                  if (iVar5 == 0) {
                    uStack_1f4 = uStack_1f4 | 0x10;
                    bVar1 = false;
                    goto LAB_00471934;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006aac20)(ppuVar24,"-no_chain");
                  if (iVar5 == 0) {
                    uStack_1f4 = uStack_1f4 | 8;
                    bVar1 = false;
                    goto LAB_00471934;
                  }
                  goto LAB_004736bc;
                }
                if ((*(uint *)((int)pcVar15 + 8) != 0) && (*(uint *)((int)pcVar15 + 0xc) != 0)) {
                  iVar5 = (*(code *)PTR_X509V3_add_value_006a8ea4)
                                    (*(uint *)((int)pcVar15 + 8),*(uint *)((int)pcVar15 + 0xc),
                                     &uStack_1a4);
                  if (iVar5 == 0) goto LAB_00472a0c;
                  bVar1 = false;
                  puVar17 = (uint *)((int)pcVar15 + 0xc);
                  goto LAB_00471934;
                }
              }
            }
          }
        }
LAB_00471a70:
        bVar1 = true;
        uVar19 = uVar20;
        goto LAB_00471934;
      }
      uVar19 = *(uint *)((int)pcVar15 + 8);
      if (uVar19 == 0) goto LAB_00471a70;
      bVar1 = false;
      puVar17 = (uint *)((int)pcVar15 + 8);
      goto LAB_00471934;
    }
    bVar1 = true;
LAB_00471af4:
    if (((((iStack_1a0 == 0) && (uStack_26c == 0)) && (uStack_1e4 == 0)) &&
        ((uStack_1b0 == 0 || (uStack_21c == 0)))) || (bVar1)) {
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
      puVar17 = (uint *)0x0;
      iStack_264 = 0;
LAB_00472a2c:
      uStack_270 = 0;
      pcStack_24c = (char *)0x0;
      ppuVar24 = (undefined **)0x0;
      ppuVar22 = (undefined **)0x0;
      uVar19 = 0;
      puVar23 = (undefined *)0x1;
      uStack_26c = 0;
      iVar4 = 0;
      uStack_25c = 0;
      uStack_250 = 0;
      pcStack_260 = (char *)0x0;
      uStack_274 = 0;
      goto LAB_00471618;
    }
    if (uVar19 == 0) {
      iStack_264 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
    }
    else {
      iStack_264 = (*(code *)PTR_BIO_new_file_006a7fac)(uVar19,"w");
    }
    uVar20 = uStack_1b0;
    if (iStack_264 == 0) {
      puVar17 = (uint *)0x0;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Error opening output file\n");
      goto LAB_00472a2c;
    }
    if (iStack_1a0 == 0) {
      if (iStack_228 != 2) {
        iStack_228 = 0;
      }
      if (uStack_26c == 0) {
        if (uStack_1b0 == 0) goto LAB_00471b38;
        uVar9 = (*(code *)PTR_BIO_f_buffer_006a8940)();
        iVar4 = (*(code *)PTR_BIO_new_006a7fa4)(uVar9);
        if (iVar4 == 0) {
          uStack_26c = 0;
        }
        else {
          uStack_26c = (*(code *)PTR_BIO_new_accept_006a8ef4)(uVar20);
          if (uStack_26c != 0) {
            (*(code *)PTR_BIO_ctrl_006a7f18)(uStack_26c,0x76,2,iVar4);
            iVar4 = (*(code *)PTR_BIO_ctrl_006a7f18)(uStack_26c,0x65,0,0);
            if (0 < iVar4) {
              ppuVar22 = (undefined **)0x0;
              if (uStack_274 != 0) goto LAB_00471b44;
              iStack_1c8 = 0;
              uStack_25c = 0;
              pcStack_260 = (char *)0x0;
              goto LAB_00471c34;
            }
            iVar4 = 0;
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar2,"Error setting up accept BIO\n");
            (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
          }
        }
        puVar17 = (uint *)0x0;
        (*(code *)PTR_BIO_free_all_006a7f74)(uStack_26c);
        (*(code *)PTR_BIO_free_006a7f70)(iVar4);
      }
      else {
        puVar17 = (uint *)(*(code *)PTR_BIO_new_file_006a7fac)(uStack_26c,&DAT_006347ac);
        if (puVar17 == (uint *)0x0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar2,"Error Opening OCSP request file\n");
        }
        else {
          iStack_1a0 = (*(code *)PTR_ASN1_d2i_bio_006a82c4)
                                 (PTR_OCSP_REQUEST_new_006a886c,PTR_d2i_OCSP_REQUEST_006a8e80,
                                  puVar17,0);
          (*(code *)PTR_BIO_free_006a7f70)(puVar17);
          if (iStack_1a0 != 0) goto LAB_00471b38;
          puVar17 = (uint *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Error reading OCSP request\n");
        }
      }
      goto LAB_00472a2c;
    }
LAB_00471b38:
    uStack_26c = 0;
    if (uStack_274 == 0) {
      ppuVar22 = (undefined **)0x0;
      iStack_1c8 = 0;
      uStack_25c = 0;
      pcStack_260 = (char *)0x0;
LAB_00471c50:
      uStack_270 = 0;
      uStack_250 = 0;
      uStack_274 = 0;
      pcStack_24c = (char *)0x0;
      iVar5 = (int)puStack_258 * 0x3c;
      puVar17 = (uint *)0x0;
LAB_00471cc4:
      do {
        unaff_s7 = ppuVar22;
        if (uStack_26c != 0) {
          iVar4 = do_responder_isra_0(&iStack_1a0,&iStack_19c,uStack_26c);
          if (iVar4 != 0) {
            if (iStack_1a0 != 0) goto LAB_00471cf4;
            puVar17 = (uint *)(*(code *)PTR_OCSP_response_create_006a8ea8)(1,0);
            puVar6 = auStack_168;
            puVar14 = (undefined4 *)
                      "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
            ;
            do {
              puVar13 = puVar14 + 4;
              puVar12 = puVar6 + 4;
              uVar16 = puVar14[1];
              uVar10 = puVar14[2];
              uVar9 = puVar14[3];
              *puVar6 = *puVar14;
              puVar6[1] = uVar16;
              puVar6[2] = uVar10;
              puVar6[3] = uVar9;
              puVar6 = puVar12;
              puVar14 = puVar13;
            } while (puVar13 != (undefined4 *)0x645930);
            *(char *)puVar12 = s_HTTP_1_0_200_OK_Content_type__ap_006458e0[80];
            if (iStack_19c == 0) goto LAB_004722fc;
LAB_004721ec:
            iVar4 = iStack_19c;
            uVar9 = (*(code *)PTR_i2d_OCSP_RESPONSE_006a8884)(puVar17,0);
            (*(code *)PTR_BIO_printf_006a7f38)(iVar4,auStack_168,uVar9);
            (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_OCSP_RESPONSE_006a8884,iVar4,puVar17);
            (*(code *)PTR_BIO_ctrl_006a7f18)(iVar4,0xb,0,0);
            goto LAB_004722fc;
          }
LAB_00472c58:
          puVar23 = (undefined *)0x1;
          uVar19 = 0;
          ppuVar24 = (undefined **)0x0;
          iVar4 = 0;
          goto LAB_00471618;
        }
        if (iStack_1a0 != 0) {
LAB_00471cf4:
          if (iStack_228 != 0) {
            (*(code *)PTR_OCSP_request_add1_nonce_006a8eac)(iStack_1a0,0,0xffffffff);
          }
          puVar23 = PTR_bio_err_006a7f3c;
          if (uStack_224 != 0) {
            uStack_274 = load_cert(*(undefined4 *)puVar2,uStack_224,3,0,0,"signer certificate");
            if (uStack_230 == 0) {
              uStack_230 = uStack_224;
            }
            if (uStack_274 == 0) {
              uVar9 = *(undefined4 *)puVar23;
              pcVar15 = "Error loading signer certificate\n";
            }
            else {
              if (((uStack_214 != 0) &&
                  (uStack_270 = load_certs(*(undefined4 *)puVar23,uStack_214,3,0,0,
                                           "signer certificates"), uStack_270 == 0)) ||
                 (uStack_250 = load_key(*(undefined4 *)puVar2,uStack_230,3,0,0,0,
                                        "signer private key"), uStack_250 == 0)) goto LAB_00472c58;
              iVar4 = (*(code *)PTR_OCSP_request_sign_006a8eb0)
                                (iStack_1a0,uStack_274,uStack_250,0,uStack_270,uStack_20c);
              if (iVar4 != 0) goto LAB_00471dec;
              pcVar15 = "Error signing OCSP request\n";
              uVar9 = *(undefined4 *)PTR_bio_err_006a7f3c;
            }
            goto LAB_00472c0c;
          }
LAB_00471dec:
          if ((iStack_210 != 0) && (iStack_1a0 != 0)) {
            (*(code *)PTR_OCSP_REQUEST_print_006a8eb4)(iStack_264,iStack_1a0,0);
          }
          if (uStack_220 == 0) {
LAB_00471e64:
            if (uStack_21c == 0) goto LAB_004722b0;
            if (((uStack_25c == 0) || (pcStack_260 == (char *)0x0)) ||
               (ppuVar22 == (undefined **)0x0)) {
              uVar9 = *(undefined4 *)puVar2;
              pcVar15 = "Need a responder certificate, key and CA for this operation!\n";
              goto LAB_00472c0c;
            }
            if ((pcStack_24c == (char *)0x0) &&
               ((pcStack_24c = (char *)load_index(uStack_21c,0), pcStack_24c == (char *)0x0 ||
                (iVar4 = index_index(pcStack_24c), iVar4 == 0)))) goto LAB_00472c58;
            goto LAB_00471e90;
          }
          iVar4 = (*(code *)PTR_BIO_new_file_006a7fac)(uStack_220,&DAT_00632de8);
          if (iVar4 != 0) {
            (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_OCSP_REQUEST_006a8eb8,iVar4,iStack_1a0);
            (*(code *)PTR_BIO_free_006a7f70)(iVar4);
            goto LAB_00471e64;
          }
          uVar9 = *(undefined4 *)puVar2;
          uVar20 = uStack_220;
LAB_00472fcc:
          puVar23 = (undefined *)0x1;
          uVar19 = 0;
          (*(code *)PTR_BIO_printf_006a7f38)(uVar9,"Error opening file %s\n",uVar20);
          ppuVar24 = (undefined **)0x0;
          goto LAB_00471618;
        }
        if (((uStack_224 != 0) || (uStack_220 != 0)) ||
           ((uStack_1b4 != 0 || ((iStack_228 != 0 || (uStack_21c != 0)))))) {
          uVar9 = *(undefined4 *)puVar2;
          pcVar15 = "Need an OCSP request for this operation!\n";
LAB_00472c0c:
          puVar23 = (undefined *)0x1;
          (*(code *)PTR_BIO_printf_006a7f38)(uVar9,pcVar15);
          uVar19 = 0;
          ppuVar24 = (undefined **)0x0;
          iVar4 = 0;
          goto LAB_00471618;
        }
LAB_004722b0:
        if (pcStack_24c == (char *)0x0) {
          if (uStack_1b4 != 0) {
            puVar17 = (uint *)process_responder(*(undefined4 *)puVar2,iStack_1a0,uStack_1b4,
                                                puStack_1ac,uStack_1b0,iStack_1a8,uStack_1a4,
                                                ppuStack_1ec);
            if (puVar17 == (uint *)0x0) goto LAB_00472c58;
            goto LAB_004722fc;
          }
          if (uStack_1e4 != 0) {
            iVar4 = (*(code *)PTR_BIO_new_file_006a7fac)(uStack_1e4,&DAT_006347ac);
            if (iVar4 != 0) {
              puVar17 = (uint *)(*(code *)PTR_ASN1_d2i_bio_006a82c4)
                                          (PTR_OCSP_RESPONSE_new_006a8ef0,
                                           PTR_d2i_OCSP_RESPONSE_006a8a28,iVar4,0);
              (*(code *)PTR_BIO_free_006a7f70)(iVar4);
              if (puVar17 == (uint *)0x0) {
                uVar9 = *(undefined4 *)puVar2;
                pcVar15 = "Error reading OCSP response\n";
                goto LAB_00472c0c;
              }
              goto LAB_004722fc;
            }
            puVar23 = (undefined *)0x1;
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar2,"Error Opening OCSP response file\n");
            uVar19 = 0;
            ppuVar24 = (undefined **)0x0;
            goto LAB_00471618;
          }
          break;
        }
LAB_00471e90:
        iVar4 = iStack_1a0;
        iVar7 = (*(code *)PTR_OCSP_request_onereq_count_006a8ebc)(iStack_1a0);
        if (iVar7 < 1) {
          iVar21 = 0;
          puVar17 = (uint *)(*(code *)PTR_OCSP_response_create_006a8ea8)(1,0);
          pcStack_268 = (char *)0x0;
          pcStack_254 = (char *)0x0;
          puStack_258 = (undefined *)0x0;
        }
        else {
          pcStack_268 = (char *)(*(code *)PTR_OCSP_BASICRESP_new_006a8ec0)();
          puStack_258 = (undefined *)(*(code *)PTR_X509_gmtime_adj_006a808c)(0,0);
          if (iStack_208 == -1) {
            pcStack_254 = (char *)0x0;
          }
          else {
            pcStack_254 = (char *)(*(code *)PTR_X509_gmtime_adj_006a808c)
                                            (0,iStack_208 * 0x15180 + iVar5);
          }
          iVar21 = 0;
          iVar18 = 0;
          do {
            while( true ) {
              uVar9 = (*(code *)PTR_OCSP_request_onereq_get0_006a8ecc)(iVar4,iVar18);
              uVar9 = (*(code *)PTR_OCSP_onereq_get0_id_006a8ed0)(uVar9);
              (*(code *)PTR_OCSP_id_get0_info_006a8ec4)(0,&iStack_194,0,0,uVar9);
              uVar10 = (*(code *)PTR_OBJ_obj2nid_006a822c)(iStack_194);
              uVar10 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar10);
              iVar11 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar10);
              if (iVar11 == 0) {
                puVar17 = (uint *)(*(code *)PTR_OCSP_response_create_006a8ea8)(2,0);
                goto LAB_00472150;
              }
              if (iVar21 != 0) {
                (*(code *)PTR_OCSP_CERTID_free_006a8860)(iVar21);
              }
              iVar21 = (*(code *)PTR_OCSP_cert_to_id_006a8870)(iVar11,0,ppuVar22);
              iVar11 = (*(code *)PTR_OCSP_id_issuer_cmp_006a8ed4)(iVar21,uVar9);
              if (iVar11 == 0) break;
LAB_004720bc:
              uVar10 = 2;
LAB_004720c8:
              iVar18 = iVar18 + 1;
              (*(code *)PTR_OCSP_basic_add1_status_006a8ed8)
                        (pcStack_268,uVar9,uVar10,0,0,puStack_258,pcStack_254);
              if (iVar7 == iVar18) goto LAB_004720f4;
            }
            (*(code *)PTR_OCSP_id_get0_info_006a8ec4)(0,0,0,&uStack_198,uVar9);
            uStack_180 = 0;
            uStack_17c = 0;
            uStack_178 = 0;
            uStack_174 = 0;
            uStack_170 = 0;
            uStack_16c = 0;
            iVar11 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(uStack_198,0);
            if (iVar11 == 0) {
              (*(code *)PTR_OpenSSLDie_006a8d4c)("ocsp.c",0x48d,&DAT_00645760);
            }
            if (*(int *)(iVar11 + 4) == 0) {
              uVar10 = (*(code *)PTR_BUF_strdup_006a80dc)("00");
            }
            else {
              uVar10 = (*(code *)PTR_BN_bn2hex_006a8118)(iVar11);
            }
            uStack_174 = uVar10;
            (*(code *)PTR_BN_free_006a811c)(iVar11);
            ppcVar8 = (char **)(*(code *)PTR_TXT_DB_get_by_index_006a8120)
                                         (*(undefined4 *)(pcStack_24c + 4),3,&uStack_180);
            (*(code *)PTR_CRYPTO_free_006a7f88)(uVar10);
            if (ppcVar8 == (char **)0x0) goto LAB_004720bc;
            if (**ppcVar8 == 'V') {
              uVar10 = 0;
              goto LAB_004720c8;
            }
            if (**ppcVar8 == 'R') {
              iStack_190 = 0;
              uStack_18c = 0;
              iStack_188 = 0;
              iStack_184 = -1;
              (*(code *)PTR_unpack_revinfo_006a8ec8)
                        (&uStack_18c,&iStack_184,&iStack_190,&iStack_188,ppcVar8[2]);
              uVar9 = (*(code *)PTR_OCSP_basic_add1_status_006a8ed8)
                                (pcStack_268,uVar9,1,iStack_184,uStack_18c,puStack_258,pcStack_254);
              if (iStack_188 == 0) {
                if (iStack_190 != 0) {
                  (*(code *)PTR_OCSP_SINGLERESP_add1_ext_i2d_006a8ee8)(uVar9,0x1ae,iStack_190,0,0);
                }
              }
              else {
                (*(code *)PTR_OCSP_SINGLERESP_add1_ext_i2d_006a8ee8)(uVar9,0x8e,iStack_188,0,0);
              }
              (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iStack_190);
              (*(code *)PTR_ASN1_TIME_free_006a8150)(uStack_18c);
              (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a8138)(iStack_188);
            }
            iVar18 = iVar18 + 1;
          } while (iVar7 != iVar18);
LAB_004720f4:
          (*(code *)PTR_OCSP_copy_nonce_006a8edc)(pcStack_268,iVar4);
          (*(code *)PTR_OCSP_basic_sign_006a8ee0)
                    (pcStack_268,pcStack_260,uStack_25c,0,iStack_1c8,uStack_1f8);
          puVar17 = (uint *)(*(code *)PTR_OCSP_response_create_006a8ea8)(0,pcStack_268);
        }
LAB_00472150:
        (*(code *)PTR_ASN1_TIME_free_006a8150)(puStack_258);
        (*(code *)PTR_ASN1_TIME_free_006a8150)(pcStack_254);
        (*(code *)PTR_OCSP_CERTID_free_006a8860)(iVar21);
        (*(code *)PTR_OCSP_BASICRESP_free_006a8ea0)(pcStack_268);
        if (iStack_19c != 0) {
          puVar6 = (undefined4 *)
                   "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
          ;
          puVar14 = auStack_168;
          do {
            puVar12 = puVar6 + 4;
            puVar13 = puVar14 + 4;
            uVar16 = puVar6[1];
            uVar10 = puVar6[2];
            uVar9 = puVar6[3];
            *puVar14 = *puVar6;
            puVar14[1] = uVar16;
            puVar14[2] = uVar10;
            puVar14[3] = uVar9;
            puVar6 = puVar12;
            puVar14 = puVar13;
          } while (puVar12 != (undefined4 *)0x645930);
          *(char *)puVar13 = s_HTTP_1_0_200_OK_Content_type__ap_006458e0[80];
          goto LAB_004721ec;
        }
LAB_004722fc:
        if (uStack_218 != 0) {
          iVar4 = (*(code *)PTR_BIO_new_file_006a7fac)(uStack_218,&DAT_00632de8);
          if (iVar4 == 0) {
            uVar9 = *(undefined4 *)puVar2;
            uVar20 = uStack_218;
            goto LAB_00472fcc;
          }
          (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_OCSP_RESPONSE_006a8884,iVar4,puVar17);
          (*(code *)PTR_BIO_free_006a7f70)(iVar4);
        }
        iVar4 = (*(code *)PTR_OCSP_response_status_006a8ee4)(puVar17);
        if (iVar4 == 0) {
          if (iStack_200 != 0) {
            (*(code *)PTR_OCSP_RESPONSE_print_006a8888)(iStack_264,puVar17,0);
          }
          if (iStack_19c == 0) {
            ppuVar24 = (undefined **)setup_verify(*(undefined4 *)puVar2,uStack_1d0,uStack_1cc);
            if (ppuVar24 == (undefined **)0x0) {
              puVar23 = (undefined *)0x1;
              uVar19 = 0;
              iVar4 = 0;
              goto LAB_00471618;
            }
            if (uStack_1e0 == 0) {
              uVar19 = 0;
            }
            else {
              uVar19 = load_certs(*(undefined4 *)PTR_bio_err_006a7f3c,uStack_1e0,3,0,0,
                                  "validator certificate");
              if (uVar19 == 0) {
                puVar23 = (undefined *)0x1;
                iVar4 = 0;
                goto LAB_00471618;
              }
            }
            iVar4 = (*(code *)PTR_OCSP_response_get1_basic_006a8ef8)(puVar17);
            if (iVar4 == 0) {
              puVar23 = (undefined *)0x1;
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Error parsing response\n");
              goto LAB_00471618;
            }
            if (iStack_1dc == 0) {
              if ((iStack_1a0 != 0) &&
                 (iVar5 = (*(code *)PTR_OCSP_check_nonce_006a8efc)(iStack_1a0,iVar4), iVar5 < 1)) {
                if (iVar5 != -1) {
                  puVar23 = (undefined *)0x1;
                  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Nonce Verify error\n");
                  goto LAB_00471618;
                }
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2,"WARNING: no nonce in response\n");
              }
              iVar5 = (*(code *)PTR_OCSP_basic_verify_006a8f00)(iVar4,uVar19,ppuVar24,uStack_1f4);
              if (iVar5 < 0) {
                iVar5 = (*(code *)PTR_OCSP_basic_verify_006a8f00)(iVar4,0,ppuVar24,0);
              }
              if (iVar5 < 1) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2,"Response Verify Failure\n");
                (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
              }
              else {
                (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Response verify OK\n");
              }
            }
            if (((iStack_1a0 != 0) &&
                (iVar5 = (*(code *)PTR_sk_num_006a7f2c)(uStack_23c), iVar5 != 0)) &&
               (iVar5 = (*(code *)PTR_sk_num_006a7f2c)(uStack_244), iVar5 != 0)) {
              iVar5 = 0;
              pcStack_268 = "s\n";
              puStack_258 = &DAT_00632848;
              pcStack_254 = "s\n";
              goto LAB_004731a8;
            }
            puVar23 = (undefined *)0x0;
            goto LAB_00471618;
          }
          iStack_22c = iStack_22c - (uint)(0 < iStack_22c);
          if (iStack_22c == 0) goto LAB_00472c58;
          (*(code *)PTR_BIO_free_all_006a7f74)();
          iStack_19c = 0;
          (*(code *)PTR_OCSP_REQUEST_free_006a8864)(iStack_1a0);
          iStack_1a0 = 0;
          (*(code *)PTR_OCSP_RESPONSE_free_006a8868)(puVar17);
          puVar17 = (uint *)0x0;
          goto LAB_00471cc4;
        }
        uVar9 = (*(code *)PTR_OCSP_response_status_str_006a8eec)(iVar4);
        (*(code *)PTR_BIO_printf_006a7f38)(iStack_264,"Responder Error: %s (%d)\n",uVar9,iVar4);
      } while (iStack_1f0 != 0);
      puVar23 = (undefined *)0x0;
      uVar19 = 0;
      ppuVar24 = (undefined **)0x0;
      iVar4 = 0;
    }
    else {
LAB_00471b44:
      puVar23 = PTR_bio_err_006a7f3c;
      uVar20 = uStack_274;
      if (uStack_270 != 0) {
        uVar20 = uStack_270;
      }
      pcStack_260 = (char *)load_cert(*(undefined4 *)puVar2,uStack_274,3,0,0,"responder certificate"
                                     );
      if (pcStack_260 == (char *)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar23,"Error loading responder certificate\n");
        ppuVar22 = (undefined **)0x0;
LAB_00472e8c:
        pcStack_24c = (char *)0x0;
        puVar17 = (uint *)0x0;
        puVar23 = (undefined *)0x1;
        uStack_270 = 0;
        uVar19 = 0;
        uStack_25c = 0;
        ppuVar24 = (undefined **)0x0;
        uStack_250 = 0;
        uStack_274 = 0;
        iVar4 = 0;
      }
      else {
        ppuVar22 = (undefined **)load_cert(*(undefined4 *)puVar23,uStack_25c,3,0,0,"CA certificate")
        ;
        if (pcStack_268 == (char *)0x0) {
          iStack_1c8 = 0;
        }
        else {
          iStack_1c8 = load_certs(*(undefined4 *)puVar23,pcStack_268,3,0,0,
                                  "responder other certificates");
          if (iStack_1c8 == 0) goto LAB_00472e8c;
        }
        uStack_25c = load_key(*(undefined4 *)puVar2,uVar20,3,0,0,0,"responder private key");
        if (uStack_25c != 0) {
          if (uStack_26c != 0) {
LAB_00471c34:
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar2,"Waiting for OCSP client connections...\n");
          }
          goto LAB_00471c50;
        }
        puVar17 = (uint *)0x0;
        uStack_270 = 0;
        pcStack_24c = (char *)0x0;
        uStack_250 = 0;
        puVar23 = (undefined *)0x1;
        uStack_274 = 0;
        uVar19 = 0;
        ppuVar24 = (undefined **)0x0;
        iVar4 = 0;
      }
    }
  } while( true );
LAB_004731a8:
  iVar7 = (*(code *)PTR_sk_num_006a7f2c)(uStack_244);
  if (iVar5 < iVar7) {
    uStack_230 = (*(code *)PTR_sk_value_006a7f24)(uStack_244,iVar5);
    uVar9 = (*(code *)PTR_sk_value_006a7f24)(uStack_23c,iVar5);
    (*(code *)PTR_BIO_printf_006a7f38)(iStack_264,&DAT_00632848,uVar9);
    iVar7 = (*(code *)PTR_OCSP_resp_find_status_006a8f04)
                      (iVar4,uStack_230,&iStack_194,&iStack_190,&uStack_18c,&iStack_188,&iStack_184)
    ;
    if (iVar7 == 0) {
      (*(code *)PTR_BIO_puts_006a8058)(iStack_264,"ERROR: No Status found.\n");
LAB_00473258:
      iVar5 = iVar5 + 1;
    }
    else {
      iVar7 = (*(code *)PTR_OCSP_check_validity_006a8f08)
                        (iStack_188,iStack_184,iStack_1d8,iStack_1d4);
      if (iVar7 == 0) {
        (*(code *)PTR_BIO_puts_006a8058)(iStack_264,"WARNING: Status times invalid.\n");
        (*(code *)PTR_ERR_print_errors_006a7f40)(iStack_264);
      }
      uVar9 = (*(code *)PTR_OCSP_cert_status_str_006a8f0c)(iStack_194);
      (*(code *)PTR_BIO_printf_006a7f38)(iStack_264,"%s\n",uVar9);
      (*(code *)PTR_BIO_puts_006a8058)(iStack_264,"\tThis Update: ");
      (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a8f10)(iStack_264,iStack_188);
      (*(code *)PTR_BIO_puts_006a8058)(iStack_264,"\n");
      if (iStack_184 != 0) {
        (*(code *)PTR_BIO_puts_006a8058)(iStack_264,"\tNext Update: ");
        (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a8f10)(iStack_264,iStack_184);
        (*(code *)PTR_BIO_puts_006a8058)(iStack_264,"\n");
      }
      if (iStack_194 != 1) goto LAB_00473258;
      if (iStack_190 != -1) {
        uVar9 = (*(code *)PTR_OCSP_crl_reason_str_006a8f14)();
        (*(code *)PTR_BIO_printf_006a7f38)(iStack_264,"\tReason: %s\n",uVar9);
      }
      iVar5 = iVar5 + 1;
      (*(code *)PTR_BIO_puts_006a8058)(iStack_264,"\tRevocation Time: ");
      (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a8f10)(iStack_264,uStack_18c);
      (*(code *)PTR_BIO_puts_006a8058)(iStack_264,"\n");
    }
    goto LAB_004731a8;
  }
  puVar23 = (undefined *)0x0;
  unaff_s7 = (undefined **)0x637a20;
  goto LAB_00471618;
}

