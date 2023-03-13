
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
  SSL_METHOD *pSVar7;
  int iVar8;
  char **ppcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  char *pcVar16;
  undefined4 uVar17;
  uint *puVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int unaff_s3;
  char *pcVar23;
  undefined *puVar24;
  char *pcVar25;
  uint *puVar26;
  uint uVar27;
  undefined *puVar28;
  undefined **unaff_s7;
  code *pcVar29;
  char *pcStack_280;
  uint uStack_27c;
  uint uStack_278;
  uint uStack_274;
  uint uStack_270;
  char *pcStack_26c;
  int iStack_268;
  uint uStack_264;
  uint uStack_260;
  undefined *puStack_25c;
  char *pcStack_258;
  char *pcStack_254;
  uint uStack_250;
  int iStack_24c;
  undefined4 uStack_248;
  int iStack_244;
  undefined4 uStack_240;
  undefined *puStack_234;
  int iStack_230;
  int iStack_22c;
  undefined *puStack_228;
  uint uStack_224;
  uint uStack_220;
  uint uStack_21c;
  uint uStack_218;
  int iStack_214;
  undefined4 uStack_210;
  int iStack_208;
  int iStack_204;
  uint uStack_1fc;
  uint uStack_1f8;
  int iStack_1f4;
  int iStack_1f0;
  uint uStack_1e8;
  uint uStack_1e4;
  int iStack_1e0;
  int iStack_1dc;
  int iStack_1d8;
  uint uStack_1d4;
  uint uStack_1d0;
  int iStack_1c8;
  uint uStack_1b4;
  uint uStack_1b0;
  undefined *puStack_1ac;
  undefined4 uStack_1a8;
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
  
  puStack_f8 = PTR___stack_chk_guard_006a9ae8;
  local_d0 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_c4 = param_1;
  iVar4 = (*(code *)PTR_BIO_new_connect_006a7d94)(param_3);
  if (iVar4 == 0) {
    puStack_110 = (undefined *)0x0;
    pcVar16 = "Error creating connect BIO\n";
    (**(code **)(local_d0 + -0x7fa8))(local_c4);
    goto LAB_00471ac8;
  }
  if (param_5 != 0) {
    (**(code **)(local_d0 + -0x7fc8))(iVar4,100,1,param_5);
  }
  if (param_6 != 1) {
    param_6 = 0;
LAB_004719f8:
    local_b8 = (undefined *)0x0;
    if (param_8 == -1) {
      iVar5 = (**(code **)(local_d0 + -0x7fc8))(iVar4,0x65,0,0);
      if (iVar5 < 1) {
LAB_00471ed8:
        (**(code **)(local_d0 + -0x7e88))(local_c4,"Error connecting BIO\n");
      }
      else {
        iVar5 = (**(code **)(local_d0 + -0x7fc8))(iVar4,0x69,0,&local_bc);
        if (iVar5 < 0) {
LAB_00471a78:
          puVar6 = *(undefined4 **)(local_d0 + -0x7fa4);
          goto LAB_00471a7c;
        }
LAB_00471b40:
        param_4 = (uint *)(**(code **)(local_d0 + -0x7048))(iVar4,param_4,0,0xffffffff);
        if (param_4 != (uint *)0x0) {
          for (iVar5 = 0; iVar8 = (**(code **)(local_d0 + -0x7fb4))(param_7), iVar5 < iVar8;
              iVar5 = iVar5 + 1) {
            iVar8 = (**(code **)(local_d0 + -0x7fbc))(param_7,iVar5);
            pcVar16 = *(char **)(iVar8 + 4);
            iVar8 = (**(code **)(local_d0 + -0x7044))(param_4,pcVar16,*(undefined4 *)(iVar8 + 8));
            if (iVar8 == 0) goto LAB_00471cd0;
          }
          pcVar16 = (char *)param_2;
          iVar5 = (**(code **)(local_d0 + -0x7040))(param_4);
          if (iVar5 != 0) {
            local_c8 = &local_b4;
            unaff_s7 = &local_b8;
            param_2 = auStack_ac;
            param_7 = 0x8000001f;
            do {
              if (param_8 == -1) goto LAB_00471d38;
              pcVar16 = (char *)param_4;
              iVar5 = (**(code **)(local_d0 + -0x703c))(unaff_s7);
              if (iVar5 != -1) goto LAB_00471cd0;
              (**(code **)(local_d0 + -0x53ec))(param_2,0,0x80);
              iVar5 = (**(code **)(local_d0 + -0x5340))(local_bc);
              pcVar29 = *(code **)(local_d0 + -0x7578);
              local_b0 = 0;
              local_b4 = param_8;
              auStack_ac[iVar5] = 1 << (local_bc & 0x1f) | auStack_ac[iVar5];
              iVar5 = (*pcVar29)(iVar4,1);
              if (iVar5 == 0) {
                iVar5 = (**(code **)(local_d0 + -0x7578))(iVar4,2);
                if (iVar5 == 0) {
                  pcVar16 = "Unexpected retry condition\n";
                  (**(code **)(local_d0 + -0x7e88))(local_c4);
                  goto LAB_00471cd0;
                }
                local_d8 = local_c8;
                iVar5 = (**(code **)(local_d0 + -0x531c))(local_bc + 1,0,param_2,0);
              }
              else {
                local_d8 = local_c8;
                iVar5 = (**(code **)(local_d0 + -0x531c))(local_bc + 1,param_2,0,0);
              }
              if (iVar5 == 0) {
                pcVar16 = "Timeout on request\n";
                (**(code **)(local_d0 + -0x7e88))(local_c4);
                goto LAB_00471cd0;
              }
            } while (iVar5 != -1);
            pcVar16 = "Select error\n";
            (**(code **)(local_d0 + -0x7e88))(local_c4);
          }
LAB_00471cd0:
          pcVar29 = *(code **)(local_d0 + -0x7038);
          goto LAB_00471cd4;
        }
      }
    }
    else {
      (**(code **)(local_d0 + -0x7fc8))(iVar4,0x66,1);
      iVar5 = (**(code **)(local_d0 + -0x7fc8))(iVar4,0x65,0,0);
      if (0 < iVar5) {
        iVar5 = (**(code **)(local_d0 + -0x7fc8))(iVar4,0x69,0,&local_bc);
        if (-1 < iVar5) goto LAB_00471b40;
        puVar6 = *(undefined4 **)(local_d0 + -0x7fa4);
LAB_00471a7c:
        pcVar16 = "Can\'t get connection fd\n";
        (**(code **)(local_d0 + -0x7e88))(*puVar6);
        puStack_110 = local_b8;
        if (local_b8 == (undefined *)0x0) goto LAB_00471eb4;
        goto LAB_00471a9c;
      }
      iVar5 = (**(code **)(local_d0 + -0x7578))(iVar4,8);
      if (iVar5 == 0) goto LAB_00471ed8;
      iVar5 = (**(code **)(local_d0 + -0x7fc8))(iVar4,0x69,0,&local_bc);
      if (iVar5 < 0) goto LAB_00471a78;
      (**(code **)(local_d0 + -0x53ec))(auStack_ac,0,0x80);
      iVar5 = (**(code **)(local_d0 + -0x5340))(local_bc);
      pcVar29 = *(code **)(local_d0 + -0x531c);
      local_b0 = 0;
      local_b4 = param_8;
      local_d8 = &local_b4;
      auStack_ac[iVar5] = 1 << (local_bc & 0x1f) | auStack_ac[iVar5];
      iVar5 = (*pcVar29)(local_bc + 1,0,auStack_ac,0);
      if (iVar5 != 0) goto LAB_00471b40;
      (**(code **)(local_d0 + -0x7e88))(local_c4,"Timeout on connect\n");
    }
LAB_00471eb4:
    puVar6 = *(undefined4 **)(local_d0 + -0x7fa4);
    goto LAB_00471eb8;
  }
  pSVar7 = SSLv23_client_method();
  param_6 = (**(code **)(local_d0 + -0x7540))(pSVar7);
  if (param_6 != 0) {
    (**(code **)(local_d0 + -0x7684))(param_6,0x21,4,0);
    uVar10 = (**(code **)(local_d0 + -0x7034))(param_6,1);
    iVar4 = (**(code **)(local_d0 + -0x791c))(uVar10,iVar4);
    goto LAB_004719f8;
  }
  puStack_110 = (undefined *)0x0;
  pcVar16 = "Error creating SSL context.\n";
  (**(code **)(local_d0 + -0x7fa8))(local_c4);
LAB_00471aa4:
  (**(code **)(local_d0 + -0x7f6c))(iVar4);
  goto LAB_00471ab4;
LAB_00471d38:
  do {
    pcVar16 = (char *)param_4;
    iVar5 = (**(code **)(local_d0 + -0x703c))(unaff_s7);
  } while (iVar5 == -1);
  pcVar29 = *(code **)(local_d0 + -0x7038);
LAB_00471cd4:
  (*pcVar29)(param_4);
  puStack_110 = local_b8;
  if (local_b8 == (undefined *)0x0) {
    puVar6 = *(undefined4 **)(local_d0 + -0x7fa4);
LAB_00471eb8:
    pcVar16 = "Error querying OCSP responder\n";
    (**(code **)(local_d0 + -0x7fa8))(*puVar6);
    puStack_110 = (undefined *)0x0;
  }
LAB_00471a9c:
  if (iVar4 != 0) goto LAB_00471aa4;
LAB_00471ab4:
  unaff_s3 = iVar4;
  if (param_6 != 0) {
    (**(code **)(local_d0 + -0x7550))(param_6);
  }
LAB_00471ac8:
  if (local_2c == *(int *)puStack_f8) {
    return puStack_110;
  }
  pcStack_ec = ocsp_main;
  (**(code **)(local_d0 + -0x5330))();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  puVar2 = PTR_bio_err_006a6e3c;
  uStack_1a8 = 0xffffffff;
  iStack_100 = param_8;
  puStack_1ac = &DAT_0063b2b4;
  uStack_1b4 = 0;
  uStack_1b0 = 0;
  uStack_1a4 = 0;
  iStack_1a0 = 0;
  iStack_19c = 0;
  iStack_114 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar4 = *(int *)PTR_bio_err_006a6e3c;
  uStack_10c = param_7;
  puStack_108 = param_4;
  iStack_104 = unaff_s3;
  iStack_fc = param_6;
  ppuStack_f4 = unaff_s7;
  puStack_f0 = param_2;
  if (iVar4 == 0) {
    iVar4 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(int *)puVar2 = iVar4;
  }
  iVar4 = load_config(iVar4,0);
  if (iVar4 != 0) {
    (*(code *)PTR_SSL_load_error_strings_006a7588)();
    (*(code *)PTR_SSL_library_init_006a7898)();
    uStack_240 = (*(code *)PTR_sk_new_null_006a6fa4)();
    uStack_248 = (*(code *)PTR_sk_new_null_006a6fa4)();
    pcVar25 = *(char **)((int)pcVar16 + 4);
    if ((pcVar25 != (char *)0x0) && (*pcVar25 == '-')) {
      iStack_268 = 0;
      puStack_25c = (undefined *)0x0;
      uStack_260 = 0;
      iStack_204 = -1;
      uVar21 = 0;
      iStack_230 = -1;
      puVar28 = (undefined *)0x0;
      iStack_1d8 = -1;
      uStack_220 = 0;
      iVar4 = 0x630000;
      iStack_1f4 = 0;
      pcVar23 = "-check_ss_sig";
      iStack_1dc = 300;
      uStack_1fc = 0;
      puVar24 = &UNK_006443fc;
      uStack_1f8 = 0;
      uStack_210 = 0;
      pcStack_26c = (char *)0x0;
      uStack_1e4 = 0;
      iStack_22c = 1;
      uStack_218 = 0;
      uStack_1d0 = 0;
      uStack_1d4 = 0;
      iStack_208 = 0;
      iStack_214 = 0;
      iStack_244 = 0;
      iStack_24c = 0;
      iStack_1e0 = 0;
      uStack_274 = 0;
      puStack_234 = (undefined *)0x0;
      puStack_228 = (undefined *)0x0;
      uStack_21c = 0;
      uStack_224 = 0;
      uStack_1e8 = 0;
      uStack_264 = 0;
      uStack_278 = 0;
      uStack_27c = 0;
      pcStack_280 = "-check_ss_sig";
      uStack_270 = 0;
      iStack_1f0 = -1;
      pcStack_258 = "certificate";
      pcStack_254 = "issuer certificate";
      goto LAB_004723cc;
    }
    puStack_25c = (undefined *)0x0;
    uStack_260 = 0;
    uVar20 = 0;
    uStack_220 = 0;
    iStack_204 = -1;
    puVar28 = (undefined *)0x0;
    iStack_230 = -1;
    iStack_1d8 = -1;
    iStack_1f4 = 0;
    uStack_1fc = 0;
    iStack_1dc = 300;
    uStack_1f8 = 0;
    uStack_210 = 0;
    iStack_1f0 = -1;
    pcStack_26c = (char *)0x0;
    uStack_1e4 = 0;
    iStack_22c = 1;
    bVar1 = false;
    uStack_218 = 0;
    uStack_1d0 = 0;
    uStack_1d4 = 0;
    iStack_208 = 0;
    iStack_214 = 0;
    iStack_244 = 0;
    iStack_24c = 0;
    iStack_1e0 = 0;
    uStack_274 = 0;
    puStack_234 = (undefined *)0x0;
    puStack_228 = (undefined *)0x0;
    uStack_21c = 0;
    uStack_224 = 0;
    uStack_1e8 = 0;
    uStack_264 = 0;
    uStack_278 = 0;
    uStack_27c = 0;
    uVar27 = 0;
    goto LAB_004725b0;
  }
  puVar18 = (uint *)0x0;
  uStack_248 = 0;
  uStack_250 = 0;
  uStack_240 = 0;
  pcVar23 = (char *)0x0;
  uStack_274 = 0;
  puVar24 = (undefined *)0x1;
  iStack_268 = 0;
  uVar20 = 0;
  uStack_270 = 0;
  pcVar25 = (char *)0x0;
  uStack_260 = 0;
  iVar4 = 0;
  pcStack_254 = (char *)0x0;
  puVar28 = (undefined *)0x0;
  uStack_264 = 0;
  pcStack_280 = (char *)0x0;
  iStack_244 = 0;
  iStack_24c = 0;
  uStack_278 = 0;
  uStack_27c = 0;
LAB_00472078:
  do {
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
    (*(code *)PTR_X509_free_006a6e90)(pcStack_280);
    (*(code *)PTR_X509_STORE_free_006a7274)(pcVar25);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(pcStack_254);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(uStack_260);
    (*(code *)PTR_X509_free_006a6e90)(iStack_24c);
    (*(code *)PTR_X509_free_006a6e90)(iStack_244);
    (*(code *)PTR_X509_free_006a6e90)(uStack_264);
    (*(code *)PTR_X509_free_006a6e90)(pcVar23);
    free_index(uStack_250);
    (*(code *)PTR_BIO_free_all_006a6e74)(iStack_19c);
    (*(code *)PTR_BIO_free_all_006a6e74)(uStack_270);
    (*(code *)PTR_BIO_free_006a6e70)(iStack_268);
    (*(code *)PTR_OCSP_REQUEST_free_006a7774)(iStack_1a0);
    (*(code *)PTR_OCSP_RESPONSE_free_006a7778)(puVar18);
    (*(code *)PTR_OCSP_BASICRESP_free_006a7db0)(iVar4);
    (*(code *)PTR_sk_free_006a6e80)(uStack_240);
    (*(code *)PTR_sk_free_006a6e80)(uStack_248);
    (*(code *)PTR_sk_pop_free_006a7058)(uStack_274,PTR_X509_free_006a6e90);
    (*(code *)PTR_sk_pop_free_006a7058)(uVar20,PTR_X509_free_006a6e90);
    (*(code *)PTR_sk_pop_free_006a7058)(uStack_1a4,PTR_X509V3_conf_free_006a7b4c);
    if (uStack_27c != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(uStack_27c);
    }
    if (uStack_278 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(uStack_278);
    }
    if (puVar28 != (undefined *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(puVar28);
    }
    if (iStack_114 == *(int *)puVar3) {
      return puVar24;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    iStack_1f0 = uStack_250;
LAB_00474214:
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_cert_checks");
    if (iVar5 == 0) {
      uStack_1f8 = uStack_1f8 | 0x100;
      bVar1 = false;
    }
    else {
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_explicit");
      if (iVar5 == 0) {
        uStack_1f8 = uStack_1f8 | 0x20;
        bVar1 = false;
      }
      else {
        iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-trust_other");
        if (iVar5 == 0) {
          uStack_1f8 = uStack_1f8 | 0x200;
          bVar1 = false;
        }
        else {
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_intern");
          if (iVar5 == 0) {
            uStack_1f8 = uStack_1f8 | 2;
            bVar1 = false;
          }
          else {
            iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-text");
            if (iVar5 == 0) {
              bVar1 = false;
              iStack_208 = 1;
              iStack_214 = 1;
            }
            else {
              iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-req_text");
              if (iVar5 == 0) {
                bVar1 = false;
                iStack_214 = 1;
              }
              else {
                iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-resp_text");
                if (iVar5 == 0) {
                  bVar1 = false;
                  iStack_208 = 1;
                }
                else {
                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-reqin");
                  uVar21 = uVar20;
                  if (iVar5 == 0) {
                    puVar26 = puVar18 + 1;
                    if (*puVar26 == 0) goto LAB_00472528;
                    bVar1 = false;
                    puVar18 = puVar18 + 1;
                    uStack_264 = *puVar26;
                  }
                  else {
                    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-respin");
                    if (iVar5 == 0) {
                      puVar26 = puVar18 + 1;
                      if (*puVar26 == 0) goto LAB_00472528;
                      bVar1 = false;
                      puVar18 = puVar18 + 1;
                      uStack_1e8 = *puVar26;
                    }
                    else {
                      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-signer");
                      if (iVar5 == 0) {
                        puVar26 = puVar18 + 1;
                        if ((undefined *)*puVar26 == (undefined *)0x0) goto LAB_00472528;
                        bVar1 = false;
                        puVar18 = puVar18 + 1;
                        puStack_228 = (undefined *)*puVar26;
                      }
                      else {
                        iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-VAfile");
                        if (iVar5 == 0) {
                          puVar26 = puVar18 + 1;
                          if (*puVar26 == 0) goto LAB_00472528;
                          bVar1 = false;
                          uStack_1f8 = uStack_1f8 | 0x200;
                          puVar18 = puVar18 + 1;
                          uStack_1e4 = *puVar26;
                        }
                        else {
                          iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-sign_other");
                          if (iVar5 == 0) {
                            puVar26 = puVar18 + 1;
                            if (*puVar26 == 0) goto LAB_00472528;
                            bVar1 = false;
                            puVar18 = puVar18 + 1;
                            uStack_218 = *puVar26;
                          }
                          else {
                            iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-verify_other");
                            if (iVar5 == 0) {
                              puVar26 = puVar18 + 1;
                              if (*puVar26 == 0) goto LAB_00472528;
                              bVar1 = false;
                              puVar18 = puVar18 + 1;
                              uStack_1e4 = *puVar26;
                            }
                            else {
                              iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-CAfile");
                              if (iVar5 == 0) {
                                puVar26 = puVar18 + 1;
                                if (*puVar26 == 0) goto LAB_00472528;
                                bVar1 = false;
                                puVar18 = puVar18 + 1;
                                uStack_1d4 = *puVar26;
                              }
                              else {
                                iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-CApath");
                                if (iVar5 == 0) {
                                  puVar26 = puVar18 + 1;
                                  if (*puVar26 == 0) goto LAB_00472528;
                                  bVar1 = false;
                                  puVar18 = puVar18 + 1;
                                  uStack_1d0 = *puVar26;
                                }
                                else {
                                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-validity_period")
                                  ;
                                  if (iVar5 == 0) {
                                    if (puVar18[1] == 0) goto LAB_00472528;
                                    puVar26 = puVar18 + 1;
                                    iStack_1dc = (*(code *)PTR_strtol_006a9958)(puVar18[1],0,10);
                                    if (-1 < iStack_1dc) goto LAB_00472424;
                                    (*(code *)PTR_BIO_printf_006a6e38)
                                              (*(undefined4 *)puVar2,"Illegal validity period %s\n",
                                               puVar18[1]);
                                    bVar1 = true;
                                    puVar18 = puVar26;
                                  }
                                  else {
                                    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-status_age");
                                    if (iVar5 == 0) {
                                      if (puVar18[1] == 0) goto LAB_00472528;
                                      puVar26 = puVar18 + 1;
                                      iStack_1d8 = (*(code *)PTR_strtol_006a9958)(puVar18[1],0,10);
                                      if (-1 < iStack_1d8) goto LAB_00472424;
                                      (*(code *)PTR_BIO_printf_006a6e38)
                                                (*(undefined4 *)puVar2,"Illegal validity age %s\n",
                                                 puVar18[1]);
                                      bVar1 = true;
                                      puVar18 = puVar26;
                                    }
                                    else {
                                      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-signkey");
                                      if (iVar5 == 0) {
                                        puVar26 = puVar18 + 1;
                                        if ((undefined *)*puVar26 == (undefined *)0x0)
                                        goto LAB_00472528;
                                        bVar1 = false;
                                        puVar18 = puVar18 + 1;
                                        puStack_234 = (undefined *)*puVar26;
                                      }
                                      else {
                                        iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-reqout");
                                        if (iVar5 == 0) {
                                          puVar26 = puVar18 + 1;
                                          if (*puVar26 == 0) goto LAB_00472528;
                                          bVar1 = false;
                                          puVar18 = puVar18 + 1;
                                          uStack_224 = *puVar26;
                                        }
                                        else {
                                          iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-respout")
                                          ;
                                          if (iVar5 == 0) {
                                            puVar26 = puVar18 + 1;
                                            if (*puVar26 == 0) goto LAB_00472528;
                                            bVar1 = false;
                                            puVar18 = puVar18 + 1;
                                            uStack_21c = *puVar26;
                                          }
                                          else {
                                            iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-path");
                                            if (iVar5 == 0) {
                                              puVar26 = puVar18 + 1;
                                              if ((undefined *)*puVar26 == (undefined *)0x0)
                                              goto LAB_00472528;
                                              bVar1 = false;
                                              puVar18 = puVar18 + 1;
                                              puStack_1ac = (undefined *)*puVar26;
                                            }
                                            else {
                                              iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                (pcVar25,"-issuer");
                                              if (iVar5 != 0) {
                                                iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                  (pcVar25,"-cert");
                                                if (iVar5 == 0) {
                                                  if (puVar18[1] == 0) goto LAB_00472528;
                                                  (*(code *)PTR_X509_free_006a6e90)(iStack_244);
                                                  iStack_244 = load_cert(*(undefined4 *)puVar2,
                                                                         puVar18[1],3,0,0,
                                                                         pcStack_258);
                                                  if (iStack_244 == 0) goto LAB_00473514;
                                                  if (iStack_268 == 0) {
                                                    iStack_268 = (*(code *)PTR_EVP_sha1_006a75d0)();
                                                  }
                                                  if (iStack_24c == 0) {
LAB_00474870:
                                                    (*(code *)PTR_BIO_printf_006a6e38)
                                                              (*(undefined4 *)puVar2,
                                                               "No issuer certificate specified\n");
                                                    goto LAB_00473514;
                                                  }
                                                  if ((iStack_1a0 != 0) ||
                                                     (iStack_1a0 = (*(code *)
                                                  PTR_OCSP_REQUEST_new_006a777c)(), iStack_1a0 != 0)
                                                  ) {
                                                    iVar8 = (*(code *)PTR_OCSP_cert_to_id_006a7780)
                                                                      (iStack_268,iStack_244,
                                                                       iStack_24c);
joined_r0x0047496c:
                                                    if (iVar8 != 0) {
                                                      iVar5 = (*(code *)PTR_sk_push_006a6fa8)
                                                                        (uStack_248,iVar8);
                                                      if ((iVar5 != 0) &&
                                                         (iVar5 = (*(code *)
                                                  PTR_OCSP_request_add0_id_006a7784)
                                                            (iStack_1a0,iVar8), iVar5 != 0)) {
                                                    iVar5 = (*(code *)PTR_sk_push_006a6fa8)
                                                                      (uStack_240,puVar18[1]);
                                                    if (iVar5 != 0) {
                                                      bVar1 = false;
                                                      puVar18 = puVar18 + 1;
                                                      goto LAB_004723ac;
                                                    }
                                                    goto LAB_00473514;
                                                  }
                                                  }
                                                  }
                                                }
                                                else {
                                                  iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                    (pcVar25,"-serial");
                                                  if (iVar5 != 0) {
                                                    iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (pcVar25,"-index");
                                                    if (iVar5 == 0) {
                                                      puVar26 = puVar18 + 1;
                                                      if (*puVar26 == 0) goto LAB_00472528;
                                                      bVar1 = false;
                                                      puVar18 = puVar18 + 1;
                                                      uStack_220 = *puVar26;
                                                    }
                                                    else if (((pcVar25[1] == 'C') &&
                                                             (pcVar25[2] == 'A')) &&
                                                            (pcVar25[3] == '\0')) {
                                                      puVar26 = puVar18 + 1;
                                                      if (*puVar26 == 0) goto LAB_00472528;
                                                      bVar1 = false;
                                                      puVar18 = puVar18 + 1;
                                                      uStack_260 = *puVar26;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                        (pcVar25,"-nmin");
                                                      if (iVar5 == 0) {
                                                        if (puVar18[1] == 0) {
                                                          bVar1 = false;
                                                        }
                                                        else {
                                                          puStack_25c = (undefined *)
                                                                        (*(code *)
                                                  PTR_strtol_006a9958)(puVar18[1],0,10);
                                                  if ((int)puStack_25c < 0) {
                                                    (*(code *)PTR_BIO_printf_006a6e38)
                                                              (*(undefined4 *)puVar2,
                                                               "Illegal update period %s\n",
                                                               puVar18[1]);
                                                    bVar1 = true;
                                                    puVar18 = puVar18 + 1;
                                                  }
                                                  else {
                                                    bVar1 = false;
                                                    puVar18 = puVar18 + 1;
                                                  }
                                                  }
                                                  if (iStack_204 != -1) goto LAB_00472528;
                                                  iStack_204 = 0;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (pcVar25,"-nrequest");
                                                    if (iVar5 == 0) {
                                                      if (puVar18[1] == 0) goto LAB_00472528;
                                                      puVar26 = puVar18 + 1;
                                                      iStack_230 = (*(code *)PTR_strtol_006a9958)
                                                                             (puVar18[1],0,10);
                                                      if (-1 < iStack_230) goto LAB_00472424;
                                                      (*(code *)PTR_BIO_printf_006a6e38)
                                                                (*(undefined4 *)puVar2,
                                                                 "Illegal accept count %s\n",
                                                                 puVar18[1]);
                                                      bVar1 = true;
                                                      puVar18 = puVar26;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                        (pcVar25,"-ndays");
                                                      if (iVar5 == 0) {
                                                        if (puVar18[1] == 0) goto LAB_00472528;
                                                        puVar26 = puVar18 + 1;
                                                        iStack_204 = (*(code *)PTR_strtol_006a9958)
                                                                               (puVar18[1],0,10);
                                                        if (-1 < iStack_204) goto LAB_00472424;
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar2,
                                                                   "Illegal update period %s\n",
                                                                   puVar18[1]);
                                                        bVar1 = true;
                                                        puVar18 = puVar26;
                                                      }
                                                      else {
                                                        iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                          (pcVar25,"-rsigner");
                                                        if (iVar5 == 0) {
                                                          puVar26 = puVar18 + 1;
                                                          if (*puVar26 == 0) goto LAB_00472528;
                                                          puVar18 = puVar18 + 1;
                                                          bVar1 = false;
                                                          uStack_274 = *puVar26;
                                                        }
                                                        else {
                                                          iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                            (pcVar25,"-rkey");
                                                          if (iVar5 == 0) {
                                                            puVar26 = puVar18 + 1;
                                                            if (*puVar26 == 0) goto LAB_00472528;
                                                            puVar18 = puVar18 + 1;
                                                            bVar1 = false;
                                                            uStack_270 = *puVar26;
                                                          }
                                                          else {
                                                            iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                              (pcVar25,"-rother");
                                                            if (iVar5 == 0) {
                                                              ppcVar9 = (char **)(puVar18 + 1);
                                                              if (*ppcVar9 == (char *)0x0) {
                                                                bVar1 = true;
                                                              }
                                                              else {
                                                                puVar18 = puVar18 + 1;
                                                                bVar1 = false;
                                                                pcStack_26c = *ppcVar9;
                                                              }
                                                            }
                                                            else {
                                                              iStack_268 = (*(code *)
                                                  PTR_EVP_get_digestbyname_006a6f2c)(pcVar25 + 1);
                                                  bVar1 = iStack_268 == 0;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_004723ac;
                                                  }
                                                  uStack_250 = puVar18[1];
                                                  if (uStack_250 == 0) goto LAB_00472528;
                                                  if (iStack_268 == 0) {
                                                    iStack_268 = (*(code *)PTR_EVP_sha1_006a75d0)();
                                                    uStack_250 = puVar18[1];
                                                  }
                                                  if (iStack_24c == 0) goto LAB_00474870;
                                                  if ((iStack_1a0 != 0) ||
                                                     (iStack_1a0 = (*(code *)
                                                  PTR_OCSP_REQUEST_new_006a777c)(), iStack_1a0 != 0)
                                                  ) {
                                                    uVar10 = (*(code *)
                                                  PTR_X509_get_subject_name_006a6f00)(iStack_24c);
                                                  uVar11 = (*(code *)
                                                  PTR_X509_get0_pubkey_bitstr_006a7e28)(iStack_24c);
                                                  iVar5 = (*(code *)PTR_s2i_ASN1_INTEGER_006a6fb4)
                                                                    (0,uStack_250);
                                                  if (iVar5 != 0) {
                                                    iVar8 = (*(code *)PTR_OCSP_cert_id_new_006a7e2c)
                                                                      (iStack_268,uVar10,uVar11,
                                                                       iVar5);
                                                    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar5)
                                                    ;
                                                    goto joined_r0x0047496c;
                                                  }
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar2,
                                                             "Error converting serial number %s\n",
                                                             uStack_250);
                                                  goto LAB_00473514;
                                                  }
                                                }
                                                (*(code *)PTR_BIO_printf_006a6e38)
                                                          (*(undefined4 *)puVar2,
                                                           "Error Creating OCSP request\n");
                                                goto LAB_00473514;
                                              }
                                              if (puVar18[1] == 0) goto LAB_00472528;
                                              (*(code *)PTR_X509_free_006a6e90)(iStack_24c);
                                              iStack_24c = load_cert(*(undefined4 *)puVar2,
                                                                     puVar18[1],3,0,0,pcStack_254);
                                              if (iStack_24c == 0) goto LAB_00473514;
                                              bVar1 = false;
                                              puVar18 = puVar18 + 1;
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
    uVar27 = uStack_270;
    if (!bVar1) {
      pcVar25 = (char *)puVar18[1];
      if ((pcVar25 == (char *)0x0) || (uVar21 = uVar20, pcVar16 = (char *)puVar18, *pcVar25 != '-'))
      goto LAB_004725b0;
LAB_004723cc:
      puVar18 = (uint *)((int)pcVar16 + 4);
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,iVar4 + 0x2514);
      if (iVar5 != 0) {
        iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,pcVar23 + -0x475c);
        uVar20 = uVar21;
        if (iVar5 == 0) {
          if (*(uint *)((int)pcVar16 + 8) != 0) {
            puVar26 = (uint *)((int)pcVar16 + 8);
            iStack_1f0 = (*(code *)PTR_strtol_006a9958)(*(uint *)((int)pcVar16 + 8),0,10);
            if (iStack_1f0 < 0) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar2,"Illegal timeout value %s\n",
                         *(uint *)((int)pcVar16 + 8));
              bVar1 = true;
              puVar18 = puVar26;
            }
            else {
LAB_00472424:
              bVar1 = false;
              puVar18 = puVar26;
            }
            goto LAB_004723ac;
          }
        }
        else {
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,puVar24);
          if (iVar5 == 0) {
            if (uStack_27c != 0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)(uStack_27c);
            }
            if (uStack_278 != 0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)(uStack_278);
            }
            if (puVar28 != (undefined *)0x0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)(puVar28);
            }
            if (*(uint *)((int)pcVar16 + 8) != 0) {
              iVar5 = (*(code *)PTR_OCSP_parse_url_006a7764)
                                (*(uint *)((int)pcVar16 + 8),&uStack_1b4,&uStack_1b0,&puStack_1ac,
                                 &uStack_1a8);
              bVar1 = iVar5 == 0;
              if (bVar1) {
                (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Error parsing URL\n");
              }
              uStack_27c = uStack_1b4;
              uStack_278 = uStack_1b0;
              puVar18 = (uint *)((int)pcVar16 + 8);
              puVar28 = puStack_1ac;
              goto LAB_004723ac;
            }
          }
          else {
            iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,pcStack_280 + -0x2d0c);
            if (iVar5 == 0) {
              if (*(uint *)((int)pcVar16 + 8) != 0) {
                bVar1 = false;
                puVar18 = (uint *)((int)pcVar16 + 8);
                uStack_1b4 = *(uint *)((int)pcVar16 + 8);
                goto LAB_004723ac;
              }
            }
            else {
              iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-port");
              if (iVar5 == 0) {
                if (*(uint *)((int)pcVar16 + 8) != 0) {
                  bVar1 = false;
                  puVar18 = (uint *)((int)pcVar16 + 8);
                  uStack_1b0 = *(uint *)((int)pcVar16 + 8);
                  goto LAB_004723ac;
                }
              }
              else {
                iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-header");
                if (iVar5 != 0) {
                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-ignore_err");
                  if (iVar5 == 0) {
                    iStack_1f4 = 1;
                    bVar1 = false;
                    goto LAB_004723ac;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-noverify");
                  if (iVar5 == 0) {
                    bVar1 = false;
                    iStack_1e0 = 1;
                    goto LAB_004723ac;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-nonce");
                  if (iVar5 == 0) {
                    bVar1 = false;
                    iStack_22c = 2;
                    goto LAB_004723ac;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_nonce");
                  if (iVar5 == 0) {
                    iStack_22c = 0;
                    bVar1 = false;
                    goto LAB_004723ac;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-resp_no_certs");
                  if (iVar5 == 0) {
                    uStack_1fc = uStack_1fc | 1;
                    bVar1 = false;
                    goto LAB_004723ac;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-resp_key_id");
                  if (iVar5 == 0) {
                    uStack_1fc = uStack_1fc | 0x400;
                    bVar1 = false;
                    goto LAB_004723ac;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_certs");
                  if (iVar5 == 0) {
                    bVar1 = false;
                    uStack_210 = 1;
                    goto LAB_004723ac;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_signature_verify");
                  if (iVar5 == 0) {
                    uStack_1f8 = uStack_1f8 | 4;
                    bVar1 = false;
                    goto LAB_004723ac;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_cert_verify");
                  if (iVar5 == 0) {
                    uStack_1f8 = uStack_1f8 | 0x10;
                    bVar1 = false;
                    goto LAB_004723ac;
                  }
                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_chain");
                  if (iVar5 == 0) {
                    uStack_1f8 = uStack_1f8 | 8;
                    bVar1 = false;
                    goto LAB_004723ac;
                  }
                  goto LAB_00474214;
                }
                if ((*(uint *)((int)pcVar16 + 8) != 0) && (*(uint *)((int)pcVar16 + 0xc) != 0)) {
                  iVar5 = (*(code *)PTR_X509V3_add_value_006a7db4)
                                    (*(uint *)((int)pcVar16 + 8),*(uint *)((int)pcVar16 + 0xc),
                                     &uStack_1a4);
                  if (iVar5 == 0) goto LAB_00473514;
                  bVar1 = false;
                  puVar18 = (uint *)((int)pcVar16 + 0xc);
                  goto LAB_004723ac;
                }
              }
            }
          }
        }
LAB_00472528:
        bVar1 = true;
        uVar20 = uVar21;
        goto LAB_004723ac;
      }
      uVar20 = *(uint *)((int)pcVar16 + 8);
      if (uVar20 == 0) goto LAB_00472528;
      bVar1 = false;
      puVar18 = (uint *)((int)pcVar16 + 8);
      goto LAB_004723ac;
    }
    bVar1 = true;
LAB_004725b0:
    if (((((iStack_1a0 == 0) && (uStack_264 == 0)) && (uStack_1e8 == 0)) &&
        ((uStack_1b0 == 0 || (uStack_220 == 0)))) || (bVar1)) {
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
      puVar18 = (uint *)0x0;
      iStack_268 = 0;
LAB_00473534:
      uStack_274 = 0;
      uStack_250 = 0;
      pcVar25 = (char *)0x0;
      pcVar23 = (char *)0x0;
      uVar20 = 0;
      puVar24 = (undefined *)0x1;
      uStack_270 = 0;
      iVar4 = 0;
      uStack_260 = 0;
      pcStack_254 = (char *)0x0;
      uStack_264 = 0;
      pcStack_280 = (char *)0x0;
      goto LAB_00472078;
    }
    if (uVar20 == 0) {
      iStack_268 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
    }
    else {
      iStack_268 = (*(code *)PTR_BIO_new_file_006a6eac)(uVar20,"w");
    }
    uVar21 = uStack_1b0;
    if (iStack_268 == 0) {
      puVar18 = (uint *)0x0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Error opening output file\n");
      goto LAB_00473534;
    }
    if (iStack_1a0 == 0) {
      if (iStack_22c != 2) {
        iStack_22c = 0;
      }
      if (uStack_264 == 0) {
        if (uStack_1b0 == 0) goto LAB_004725f4;
        uVar10 = (*(code *)PTR_BIO_f_buffer_006a7854)();
        iVar4 = (*(code *)PTR_BIO_new_006a6ea4)(uVar10);
        if (iVar4 == 0) {
          uStack_270 = 0;
        }
        else {
          uStack_270 = (*(code *)PTR_BIO_new_accept_006a7e04)(uVar21);
          if (uStack_270 != 0) {
            (*(code *)PTR_BIO_ctrl_006a6e18)(uStack_270,0x76,2,iVar4);
            iVar4 = (*(code *)PTR_BIO_ctrl_006a6e18)(uStack_270,0x65,0,0);
            if (0 < iVar4) {
              pcVar23 = (char *)0x0;
              if (uStack_274 != 0) goto LAB_00472600;
              iStack_1c8 = 0;
              uStack_260 = 0;
              uStack_264 = 0;
              goto LAB_004726f0;
            }
            iVar4 = 0;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar2,"Error setting up accept BIO\n");
            (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
          }
        }
        puVar18 = (uint *)0x0;
        (*(code *)PTR_BIO_free_all_006a6e74)(uStack_270);
        (*(code *)PTR_BIO_free_006a6e70)(iVar4);
      }
      else {
        puVar18 = (uint *)(*(code *)PTR_BIO_new_file_006a6eac)(uStack_264,&DAT_00633e40);
        if (puVar18 == (uint *)0x0) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar2,"Error Opening OCSP request file\n");
        }
        else {
          iStack_1a0 = (*(code *)PTR_ASN1_d2i_bio_006a71c4)
                                 (PTR_OCSP_REQUEST_new_006a777c,PTR_d2i_OCSP_REQUEST_006a7d90,
                                  puVar18,0);
          (*(code *)PTR_BIO_free_006a6e70)(puVar18);
          if (iStack_1a0 != 0) goto LAB_004725f4;
          puVar18 = (uint *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Error reading OCSP request\n");
        }
      }
      goto LAB_00473534;
    }
LAB_004725f4:
    uStack_270 = 0;
    if (uStack_274 == 0) {
      pcVar23 = (char *)0x0;
      iStack_1c8 = 0;
      uStack_260 = 0;
      uStack_264 = 0;
LAB_0047270c:
      uStack_274 = 0;
      pcStack_254 = (char *)0x0;
      pcStack_280 = (char *)0x0;
      uStack_250 = 0;
      iVar5 = (int)puStack_25c * 0x3c;
      puVar18 = (uint *)0x0;
LAB_00472770:
      do {
        if (uStack_270 != 0) {
          iVar4 = do_responder_isra_0(&iStack_1a0,&iStack_19c,uStack_270);
          if (iVar4 != 0) {
            if (iStack_1a0 != 0) goto LAB_004727a0;
            puVar18 = (uint *)(*(code *)PTR_OCSP_response_create_006a7db8)(1,0);
            puVar6 = auStack_168;
            puVar15 = (undefined4 *)
                      "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
            ;
            do {
              puVar14 = puVar15 + 4;
              puVar13 = puVar6 + 4;
              uVar17 = puVar15[1];
              uVar11 = puVar15[2];
              uVar10 = puVar15[3];
              *puVar6 = *puVar15;
              puVar6[1] = uVar17;
              puVar6[2] = uVar11;
              puVar6[3] = uVar10;
              puVar6 = puVar13;
              puVar15 = puVar14;
            } while (puVar14 != (undefined4 *)0x64551c);
            *(char *)puVar13 = s_HTTP_1_0_200_OK_Content_type__ap_006454cc[80];
            if (iStack_19c == 0) goto LAB_00472db0;
LAB_00472ca0:
            iVar4 = iStack_19c;
            uVar10 = (*(code *)PTR_i2d_OCSP_RESPONSE_006a7794)(puVar18,0);
            (*(code *)PTR_BIO_printf_006a6e38)(iVar4,auStack_168,uVar10);
            (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_OCSP_RESPONSE_006a7794,iVar4,puVar18);
            (*(code *)PTR_BIO_ctrl_006a6e18)(iVar4,0xb,0,0);
            goto LAB_00472db0;
          }
LAB_00473760:
          puVar24 = (undefined *)0x1;
          uVar20 = 0;
          pcVar25 = (char *)0x0;
          iVar4 = 0;
          goto LAB_00472078;
        }
        if (iStack_1a0 == 0) {
          if (((puStack_228 != (undefined *)0x0) || (uStack_224 != 0)) ||
             ((uStack_1b4 != 0 || ((iStack_22c != 0 || (uStack_220 != 0)))))) {
            pcVar16 = "Need an OCSP request for this operation!\n";
            uVar10 = *(undefined4 *)puVar2;
LAB_00473718:
            puVar24 = (undefined *)0x1;
            (*(code *)PTR_BIO_printf_006a6e38)(uVar10,pcVar16);
            uVar20 = 0;
            pcVar25 = (char *)0x0;
            iVar4 = 0;
            goto LAB_00472078;
          }
LAB_00472d64:
          if (uStack_250 == 0) {
            if (uStack_1b4 != 0) {
              puVar18 = (uint *)process_responder(*(undefined4 *)puVar2,iStack_1a0,uStack_1b4,
                                                  puStack_1ac,uStack_1b0,uStack_1a8,uStack_1a4,
                                                  iStack_1f0);
              if (puVar18 == (uint *)0x0) goto LAB_00473760;
              goto LAB_00472db0;
            }
            if (uStack_1e8 != 0) {
              iVar4 = (*(code *)PTR_BIO_new_file_006a6eac)(uStack_1e8,&DAT_00633e40);
              if (iVar4 != 0) {
                puVar18 = (uint *)(*(code *)PTR_ASN1_d2i_bio_006a71c4)
                                            (PTR_OCSP_RESPONSE_new_006a7e00,
                                             PTR_d2i_OCSP_RESPONSE_006a793c,iVar4,0);
                (*(code *)PTR_BIO_free_006a6e70)(iVar4);
                if (puVar18 == (uint *)0x0) {
                  pcVar16 = "Error reading OCSP response\n";
                  uVar10 = *(undefined4 *)puVar2;
                  goto LAB_00473718;
                }
                goto LAB_00472db0;
              }
              puVar24 = (undefined *)0x1;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar2,"Error Opening OCSP response file\n");
              uVar20 = 0;
              pcVar25 = (char *)0x0;
              goto LAB_00472078;
            }
            break;
          }
        }
        else {
LAB_004727a0:
          if (iStack_22c != 0) {
            (*(code *)PTR_OCSP_request_add1_nonce_006a7dbc)(iStack_1a0,0,0xffffffff);
          }
          puVar24 = PTR_bio_err_006a6e3c;
          if (puStack_228 != (undefined *)0x0) {
            pcStack_280 = (char *)load_cert(*(undefined4 *)puVar2,puStack_228,3,0,0,
                                            "signer certificate");
            if (puStack_234 == (undefined *)0x0) {
              puStack_234 = puStack_228;
            }
            if (pcStack_280 == (char *)0x0) {
              pcVar16 = "Error loading signer certificate\n";
              uVar10 = *(undefined4 *)puVar24;
            }
            else {
              if (((uStack_218 != 0) &&
                  (uStack_274 = load_certs(*(undefined4 *)puVar24,uStack_218,3,0,0,
                                           "signer certificates"), uStack_274 == 0)) ||
                 (pcStack_254 = (char *)load_key(*(undefined4 *)puVar2,puStack_234,3,0,0,0,
                                                 "signer private key"), pcStack_254 == (char *)0x0))
              goto LAB_00473760;
              iVar4 = (*(code *)PTR_OCSP_request_sign_006a7dc0)
                                (iStack_1a0,pcStack_280,pcStack_254,0,uStack_274,uStack_210);
              if (iVar4 != 0) goto LAB_00472898;
              pcVar16 = "Error signing OCSP request\n";
              uVar10 = *(undefined4 *)PTR_bio_err_006a6e3c;
            }
            goto LAB_00473718;
          }
LAB_00472898:
          if ((iStack_214 != 0) && (iStack_1a0 != 0)) {
            (*(code *)PTR_OCSP_REQUEST_print_006a7dc4)(iStack_268,iStack_1a0,0);
          }
          if (uStack_224 != 0) {
            iVar4 = (*(code *)PTR_BIO_new_file_006a6eac)(uStack_224,&DAT_00632420);
            if (iVar4 != 0) {
              (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_OCSP_REQUEST_006a7dc8,iVar4,iStack_1a0);
              (*(code *)PTR_BIO_free_006a6e70)(iVar4);
              goto LAB_00472910;
            }
            uVar10 = *(undefined4 *)puVar2;
            uVar21 = uStack_224;
LAB_00473af0:
            puVar24 = (undefined *)0x1;
            uVar20 = 0;
            (*(code *)PTR_BIO_printf_006a6e38)(uVar10,"Error opening file %s\n",uVar21);
            pcVar25 = (char *)0x0;
            goto LAB_00472078;
          }
LAB_00472910:
          if (uStack_220 == 0) goto LAB_00472d64;
          if (((uStack_260 == 0) || (uStack_264 == 0)) || (pcVar23 == (char *)0x0)) {
            pcVar16 = "Need a responder certificate, key and CA for this operation!\n";
            uVar10 = *(undefined4 *)puVar2;
            goto LAB_00473718;
          }
          if (uStack_250 != 0) goto LAB_0047293c;
          uStack_250 = load_index(uStack_220,0);
          if (uStack_250 == 0) {
            puVar24 = (undefined *)0x1;
            uVar20 = 0;
            pcVar25 = (char *)0x0;
            iVar4 = 0;
            goto LAB_00472078;
          }
          iVar4 = index_index(uStack_250);
          if (iVar4 == 0) goto LAB_00473760;
        }
LAB_0047293c:
        iVar4 = iStack_1a0;
        iVar8 = (*(code *)PTR_OCSP_request_onereq_count_006a7dcc)(iStack_1a0);
        if (iVar8 < 1) {
          iVar22 = 0;
          puVar18 = (uint *)(*(code *)PTR_OCSP_response_create_006a7db8)(1,0);
          pcStack_26c = (char *)0x0;
          pcStack_258 = (char *)0x0;
          puStack_25c = (undefined *)0x0;
        }
        else {
          pcStack_26c = (char *)(*(code *)PTR_OCSP_BASICRESP_new_006a7dd0)();
          puStack_25c = (undefined *)(*(code *)PTR_X509_gmtime_adj_006a6f8c)(0,0);
          if (iStack_204 == -1) {
            pcStack_258 = (char *)0x0;
          }
          else {
            pcStack_258 = (char *)(*(code *)PTR_X509_time_adj_ex_006a6f90)(0,iStack_204,iVar5,0);
          }
          iVar22 = 0;
          iVar19 = 0;
          do {
            while( true ) {
              uVar10 = (*(code *)PTR_OCSP_request_onereq_get0_006a7ddc)(iVar4,iVar19);
              uVar10 = (*(code *)PTR_OCSP_onereq_get0_id_006a7de0)(uVar10);
              (*(code *)PTR_OCSP_id_get0_info_006a7dd4)(0,&iStack_194,0,0,uVar10);
              uVar11 = (*(code *)PTR_OBJ_obj2nid_006a712c)(iStack_194);
              uVar11 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar11);
              iVar12 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar11);
              if (iVar12 == 0) {
                puVar18 = (uint *)(*(code *)PTR_OCSP_response_create_006a7db8)(2,0);
                goto LAB_00472c04;
              }
              if (iVar22 != 0) {
                (*(code *)PTR_OCSP_CERTID_free_006a7770)(iVar22);
              }
              iVar22 = (*(code *)PTR_OCSP_cert_to_id_006a7780)(iVar12,0,pcVar23);
              iVar12 = (*(code *)PTR_OCSP_id_issuer_cmp_006a7de4)(iVar22,uVar10);
              if (iVar12 == 0) break;
LAB_00472b70:
              uVar11 = 2;
LAB_00472b7c:
              iVar19 = iVar19 + 1;
              (*(code *)PTR_OCSP_basic_add1_status_006a7de8)
                        (pcStack_26c,uVar10,uVar11,0,0,puStack_25c,pcStack_258);
              if (iVar8 == iVar19) goto LAB_00472ba8;
            }
            (*(code *)PTR_OCSP_id_get0_info_006a7dd4)(0,0,0,&uStack_198,uVar10);
            uStack_180 = 0;
            uStack_17c = 0;
            uStack_178 = 0;
            uStack_174 = 0;
            uStack_170 = 0;
            uStack_16c = 0;
            iVar12 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(uStack_198,0);
            if (iVar12 == 0) {
              (*(code *)PTR_OpenSSLDie_006a7c5c)("ocsp.c",0x445,&DAT_0064534c);
            }
            if (*(int *)(iVar12 + 4) == 0) {
              uVar11 = (*(code *)PTR_BUF_strdup_006a6fdc)("00");
            }
            else {
              uVar11 = (*(code *)PTR_BN_bn2hex_006a7018)(iVar12);
            }
            uStack_174 = uVar11;
            (*(code *)PTR_BN_free_006a701c)(iVar12);
            ppcVar9 = (char **)(*(code *)PTR_TXT_DB_get_by_index_006a7020)
                                         (*(undefined4 *)(uStack_250 + 4),3,&uStack_180);
            (*(code *)PTR_CRYPTO_free_006a6e88)(uVar11);
            if (ppcVar9 == (char **)0x0) goto LAB_00472b70;
            if (**ppcVar9 == 'V') {
              uVar11 = 0;
              goto LAB_00472b7c;
            }
            if (**ppcVar9 == 'R') {
              iStack_190 = 0;
              uStack_18c = 0;
              iStack_188 = 0;
              iStack_184 = -1;
              (*(code *)PTR_unpack_revinfo_006a7dd8)
                        (&uStack_18c,&iStack_184,&iStack_190,&iStack_188,ppcVar9[2]);
              uVar10 = (*(code *)PTR_OCSP_basic_add1_status_006a7de8)
                                 (pcStack_26c,uVar10,1,iStack_184,uStack_18c,puStack_25c,pcStack_258
                                 );
              if (iStack_188 == 0) {
                if (iStack_190 != 0) {
                  (*(code *)PTR_OCSP_SINGLERESP_add1_ext_i2d_006a7df8)(uVar10,0x1ae,iStack_190,0,0);
                }
              }
              else {
                (*(code *)PTR_OCSP_SINGLERESP_add1_ext_i2d_006a7df8)(uVar10,0x8e,iStack_188,0,0);
              }
              (*(code *)PTR_ASN1_OBJECT_free_006a7004)(iStack_190);
              (*(code *)PTR_ASN1_TIME_free_006a7050)(uStack_18c);
              (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a7038)(iStack_188);
            }
            iVar19 = iVar19 + 1;
          } while (iVar8 != iVar19);
LAB_00472ba8:
          (*(code *)PTR_OCSP_copy_nonce_006a7dec)(pcStack_26c,iVar4);
          (*(code *)PTR_OCSP_basic_sign_006a7df0)
                    (pcStack_26c,uStack_264,uStack_260,0,iStack_1c8,uStack_1fc);
          puVar18 = (uint *)(*(code *)PTR_OCSP_response_create_006a7db8)(0,pcStack_26c);
        }
LAB_00472c04:
        (*(code *)PTR_ASN1_TIME_free_006a7050)(puStack_25c);
        (*(code *)PTR_ASN1_TIME_free_006a7050)(pcStack_258);
        (*(code *)PTR_OCSP_CERTID_free_006a7770)(iVar22);
        (*(code *)PTR_OCSP_BASICRESP_free_006a7db0)(pcStack_26c);
        if (iStack_19c != 0) {
          puVar6 = (undefined4 *)
                   "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
          ;
          puVar15 = auStack_168;
          do {
            puVar13 = puVar6 + 4;
            puVar14 = puVar15 + 4;
            uVar17 = puVar6[1];
            uVar11 = puVar6[2];
            uVar10 = puVar6[3];
            *puVar15 = *puVar6;
            puVar15[1] = uVar17;
            puVar15[2] = uVar11;
            puVar15[3] = uVar10;
            puVar6 = puVar13;
            puVar15 = puVar14;
          } while (puVar13 != (undefined4 *)0x64551c);
          *(char *)puVar14 = s_HTTP_1_0_200_OK_Content_type__ap_006454cc[80];
          goto LAB_00472ca0;
        }
LAB_00472db0:
        if (uStack_21c != 0) {
          iVar4 = (*(code *)PTR_BIO_new_file_006a6eac)(uStack_21c,&DAT_00632420);
          if (iVar4 == 0) {
            uVar10 = *(undefined4 *)puVar2;
            uVar21 = uStack_21c;
            goto LAB_00473af0;
          }
          (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_OCSP_RESPONSE_006a7794,iVar4,puVar18);
          (*(code *)PTR_BIO_free_006a6e70)(iVar4);
        }
        iVar4 = (*(code *)PTR_OCSP_response_status_006a7df4)(puVar18);
        if (iVar4 == 0) {
          if (iStack_208 != 0) {
            (*(code *)PTR_OCSP_RESPONSE_print_006a7798)(iStack_268,puVar18,0);
          }
          if (iStack_19c == 0) {
            pcVar25 = (char *)setup_verify(*(undefined4 *)puVar2,uStack_1d4,uStack_1d0);
            if (pcVar25 == (char *)0x0) {
              puVar24 = (undefined *)0x1;
              uVar20 = 0;
              iVar4 = 0;
              goto LAB_00472078;
            }
            if (uStack_1e4 == 0) {
              uVar20 = 0;
            }
            else {
              uVar20 = load_certs(*(undefined4 *)PTR_bio_err_006a6e3c,uStack_1e4,3,0,0,
                                  "validator certificate");
              if (uVar20 == 0) {
                puVar24 = (undefined *)0x1;
                iVar4 = 0;
                goto LAB_00472078;
              }
            }
            iVar4 = (*(code *)PTR_OCSP_response_get1_basic_006a7e08)(puVar18);
            if (iVar4 == 0) {
              puVar24 = (undefined *)0x1;
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Error parsing response\n");
              goto LAB_00472078;
            }
            if (iStack_1e0 == 0) {
              if ((iStack_1a0 != 0) &&
                 (iVar5 = (*(code *)PTR_OCSP_check_nonce_006a7e0c)(iStack_1a0,iVar4), iVar5 < 1)) {
                if (iVar5 != -1) {
                  puVar24 = (undefined *)0x1;
                  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Nonce Verify error\n");
                  goto LAB_00472078;
                }
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar2,"WARNING: no nonce in response\n");
              }
              iVar5 = (*(code *)PTR_OCSP_basic_verify_006a7e10)(iVar4,uVar20,pcVar25,uStack_1f8);
              if (iVar5 < 0) {
                iVar5 = (*(code *)PTR_OCSP_basic_verify_006a7e10)(iVar4,0,pcVar25,0);
              }
              if (iVar5 < 1) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar2,"Response Verify Failure\n");
                (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
              }
              else {
                (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Response verify OK\n");
              }
            }
            if (((iStack_1a0 != 0) &&
                (iVar5 = (*(code *)PTR_sk_num_006a6e2c)(uStack_240), iVar5 != 0)) &&
               (iVar5 = (*(code *)PTR_sk_num_006a6e2c)(uStack_248), iVar5 != 0)) {
              iVar5 = 0;
              pcStack_26c = "-check_ss_sig";
              puStack_25c = &DAT_00631e78;
              pcStack_258 = "%s\n";
              goto LAB_00473ce0;
            }
            puVar24 = (undefined *)0x0;
            goto LAB_00472078;
          }
          iStack_230 = iStack_230 - (uint)(0 < iStack_230);
          if (iStack_230 == 0) goto LAB_00473760;
          (*(code *)PTR_BIO_free_all_006a6e74)();
          iStack_19c = 0;
          (*(code *)PTR_OCSP_REQUEST_free_006a7774)(iStack_1a0);
          iStack_1a0 = 0;
          (*(code *)PTR_OCSP_RESPONSE_free_006a7778)(puVar18);
          puVar18 = (uint *)0x0;
          goto LAB_00472770;
        }
        uVar10 = (*(code *)PTR_OCSP_response_status_str_006a7dfc)(iVar4);
        (*(code *)PTR_BIO_printf_006a6e38)(iStack_268,"Responder Error: %s (%d)\n",uVar10,iVar4);
      } while (iStack_1f4 != 0);
      puVar24 = (undefined *)0x0;
      uVar20 = 0;
      pcVar25 = (char *)0x0;
      iVar4 = 0;
    }
    else {
LAB_00472600:
      puVar24 = PTR_bio_err_006a6e3c;
      uVar21 = uStack_274;
      if (uVar27 != 0) {
        uVar21 = uVar27;
      }
      uStack_264 = load_cert(*(undefined4 *)puVar2,uStack_274,3,0,0,"responder certificate");
      if (uStack_264 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar24,"Error loading responder certificate\n");
        pcVar23 = (char *)0x0;
LAB_004739a0:
        uStack_250 = 0;
        puVar18 = (uint *)0x0;
        puVar24 = (undefined *)0x1;
        uStack_274 = 0;
        uVar20 = 0;
        uStack_260 = 0;
        pcVar25 = (char *)0x0;
        pcStack_254 = (char *)0x0;
        pcStack_280 = (char *)0x0;
        iVar4 = 0;
      }
      else {
        pcVar23 = (char *)load_cert(*(undefined4 *)puVar24,uStack_260,3,0,0,"CA certificate");
        if (pcStack_26c == (char *)0x0) {
          iStack_1c8 = 0;
        }
        else {
          iStack_1c8 = load_certs(*(undefined4 *)puVar24,pcStack_26c,3,0,0,
                                  "responder other certificates");
          if (iStack_1c8 == 0) goto LAB_004739a0;
        }
        uStack_260 = load_key(*(undefined4 *)puVar2,uVar21,3,0,0,0,"responder private key");
        if (uStack_260 != 0) {
          if (uStack_270 != 0) {
LAB_004726f0:
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar2,"Waiting for OCSP client connections...\n");
          }
          goto LAB_0047270c;
        }
        puVar18 = (uint *)0x0;
        uStack_274 = 0;
        uStack_250 = 0;
        pcStack_254 = (char *)0x0;
        puVar24 = (undefined *)0x1;
        pcStack_280 = (char *)0x0;
        uVar20 = 0;
        pcVar25 = (char *)0x0;
        iVar4 = 0;
      }
    }
  } while( true );
LAB_00473ce0:
  iVar8 = (*(code *)PTR_sk_num_006a6e2c)(uStack_248);
  if (iVar5 < iVar8) {
    iStack_230 = (*(code *)PTR_sk_value_006a6e24)(uStack_248,iVar5);
    uVar10 = (*(code *)PTR_sk_value_006a6e24)(uStack_240,iVar5);
    (*(code *)PTR_BIO_printf_006a6e38)(iStack_268,&DAT_00631e78,uVar10);
    iVar8 = (*(code *)PTR_OCSP_resp_find_status_006a7e14)
                      (iVar4,iStack_230,&iStack_194,&iStack_190,&uStack_18c,&iStack_188,&iStack_184)
    ;
    if (iVar8 == 0) {
      (*(code *)PTR_BIO_puts_006a6f58)(iStack_268,"ERROR: No Status found.\n");
LAB_00473d90:
      iVar5 = iVar5 + 1;
    }
    else {
      iVar8 = (*(code *)PTR_OCSP_check_validity_006a7e18)
                        (iStack_188,iStack_184,iStack_1dc,iStack_1d8);
      if (iVar8 == 0) {
        (*(code *)PTR_BIO_puts_006a6f58)(iStack_268,"WARNING: Status times invalid.\n");
        (*(code *)PTR_ERR_print_errors_006a6e40)(iStack_268);
      }
      uVar10 = (*(code *)PTR_OCSP_cert_status_str_006a7e1c)(iStack_194);
      (*(code *)PTR_BIO_printf_006a6e38)(iStack_268,"%s\n",uVar10);
      (*(code *)PTR_BIO_puts_006a6f58)(iStack_268,"\tThis Update: ");
      (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(iStack_268,iStack_188);
      (*(code *)PTR_BIO_puts_006a6f58)(iStack_268,"\n");
      if (iStack_184 != 0) {
        (*(code *)PTR_BIO_puts_006a6f58)(iStack_268,"\tNext Update: ");
        (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(iStack_268,iStack_184);
        (*(code *)PTR_BIO_puts_006a6f58)(iStack_268,"\n");
      }
      if (iStack_194 != 1) goto LAB_00473d90;
      if (iStack_190 != -1) {
        uVar10 = (*(code *)PTR_OCSP_crl_reason_str_006a7e24)();
        (*(code *)PTR_BIO_printf_006a6e38)(iStack_268,"\tReason: %s\n",uVar10);
      }
      iVar5 = iVar5 + 1;
      (*(code *)PTR_BIO_puts_006a6f58)(iStack_268,"\tRevocation Time: ");
      (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(iStack_268,uStack_18c);
      (*(code *)PTR_BIO_puts_006a6f58)(iStack_268,"\n");
    }
    goto LAB_00473ce0;
  }
  puVar24 = (undefined *)0x0;
  puStack_234 = puVar28;
  goto LAB_00472078;
}

