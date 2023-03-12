
undefined4 x509_main(int param_1,int param_2)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int **ppiVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  undefined *puVar12;
  undefined4 uVar13;
  char *pcVar14;
  int *piVar15;
  uint uVar16;
  undefined4 uVar17;
  char **ppcVar18;
  undefined1 *puVar19;
  int iVar20;
  int *piVar21;
  undefined4 *puVar22;
  undefined4 *puVar23;
  code *pcVar24;
  int local_328;
  int local_324;
  int *local_320;
  int *local_31c;
  undefined4 *local_318;
  int local_314;
  int local_310;
  undefined4 local_30c;
  int local_308;
  int *local_304;
  int local_300;
  undefined4 local_2fc;
  int *local_2f8;
  int local_2f4;
  int local_2f0;
  undefined4 local_2e8;
  char *local_2e4;
  int *local_2e0;
  int *local_2dc;
  int local_2d8;
  char *local_2d4;
  char *local_2d0;
  int *local_2cc;
  int *local_2c8;
  int *local_2c4;
  int *local_2c0;
  int *local_2bc;
  int local_2b8;
  int *local_2b4;
  int local_2b0;
  char *local_2ac;
  char *local_2a8;
  char *local_2a4;
  char *local_2a0;
  char *local_29c;
  int *local_298;
  int *local_294;
  int *local_290;
  int *local_28c;
  int *local_288;
  int *local_284;
  int *local_280;
  int *local_27c;
  int *local_278;
  int *local_274;
  int *local_270;
  int local_26c;
  int *local_268;
  int *local_264;
  int *local_260;
  int *local_25c;
  int *local_258;
  char *local_254;
  char *local_250;
  char *local_24c;
  int *local_248;
  int *local_244;
  char *local_240;
  int local_23c;
  int local_238;
  int local_21c;
  undefined4 local_218;
  undefined4 local_214;
  int *local_210;
  int *local_20c;
  int local_1f4 [2];
  char *local_1ec;
  undefined local_16c [64];
  undefined auStack_12c [256];
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  puVar2 = PTR_bio_err_006a6e3c;
  reqfile = 0;
  local_304 = (int *)&_gp_1;
  local_21c = 0;
  local_218 = 0;
  local_214 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iVar11 = *(int *)puVar2;
  if (iVar11 == 0) {
    iVar11 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(int *)puVar2 = iVar11;
  }
  iVar11 = load_config(iVar11,0);
  puVar22 = (undefined4 *)PTR_stdout_006a99c8;
  if (iVar11 == 0) {
    local_328 = 0;
    local_30c = 0;
LAB_0043cf04:
    local_310 = 0;
    local_314 = 0;
    local_318 = (undefined4 *)0x0;
    iVar11 = 0;
    iVar20 = 0;
    local_31c = (int *)0x0;
    local_2f4 = 0;
    local_324 = 0;
    puVar22 = (undefined4 *)0x0;
    local_320 = (int *)0x0;
    puVar23 = (undefined4 *)0x0;
    piVar15 = (int *)0x0;
    uVar17 = 1;
    goto LAB_0043cf2c;
  }
  local_30c = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
  local_328 = (*(code *)PTR_X509_STORE_new_006a7250)();
  if (local_328 == 0) goto LAB_0043cf04;
  param_1 = param_1 + -1;
  (*(code *)PTR_X509_STORE_set_verify_cb_006a72f8)(local_328,callb);
  ppcVar18 = (char **)(param_2 + 4);
  local_250 = (char *)0x0;
  local_238 = 0;
  local_23c = 0;
  local_308 = 0;
  local_2ac = (char *)0x0;
  local_254 = (char *)0x0;
  local_2e4 = (char *)0x0;
  if (param_1 < 1) {
    local_258 = (int *)0x0;
    local_25c = (int *)0x0;
    local_318 = (undefined4 *)0x0;
    local_260 = (int *)0x0;
    local_2b0 = 0x1e;
    local_264 = (int *)0x0;
    local_2b4 = (int *)0x0;
    iVar20 = 3;
    local_268 = (int *)0x0;
    local_26c = 0;
    local_270 = (int *)0x0;
    local_240 = (char *)0x0;
    local_244 = (int *)0x0;
    local_2b8 = 0;
    local_274 = (int *)0x0;
    local_278 = (int *)0x0;
    local_248 = (int *)0x0;
    local_2e0 = (int *)0x0;
    local_2bc = (int *)0x0;
    local_2dc = (int *)0x0;
    local_27c = (int *)0x0;
    local_280 = (int *)0x0;
    local_288 = (int *)0x0;
    local_28c = (int *)0x0;
    local_2c0 = (int *)0x0;
    local_2c4 = (int *)0x0;
    local_2c8 = (int *)0x0;
    local_290 = (int *)0x0;
    local_294 = (int *)0x0;
    local_298 = (int *)0x0;
    local_2cc = (int *)0x0;
    local_24c = (char *)0x0;
    local_29c = (char *)0x0;
    local_2a0 = (char *)0x0;
    local_2d0 = (char *)0x0;
    local_2a4 = (char *)0x0;
    local_2a8 = (char *)0x0;
    local_2d4 = (char *)0x0;
    local_2e8 = 3;
    local_2f0 = 3;
    local_2fc = 3;
    local_300 = 3;
    local_310 = 0;
    local_314 = 0;
    local_2f8 = (int *)0x0;
    local_31c = (int *)0x0;
    local_2d8 = 0;
    local_284 = (int *)0x0;
  }
  else {
    local_2d8 = 0;
    local_258 = (int *)0x0;
    local_25c = (int *)0x0;
    local_2b0 = 0x1e;
    local_260 = (int *)0x0;
    local_264 = (int *)0x0;
    local_2b4 = (int *)0x0;
    local_268 = (int *)0x0;
    local_26c = 0;
    local_270 = (int *)0x0;
    local_240 = (char *)0x0;
    local_244 = (int *)0x0;
    local_2b8 = 0;
    local_274 = (int *)0x0;
    local_278 = (int *)0x0;
    local_248 = (int *)0x0;
    local_2e0 = (int *)0x0;
    local_2bc = (int *)0x0;
    local_2dc = (int *)0x0;
    local_27c = (int *)0x0;
    local_280 = (int *)0x0;
    local_284 = (int *)0x0;
    local_288 = (int *)0x0;
    local_28c = (int *)0x0;
    local_2c0 = (int *)0x0;
    local_2c4 = (int *)0x0;
    local_2c8 = (int *)0x0;
    local_290 = (int *)0x0;
    local_294 = (int *)0x0;
    local_298 = (int *)0x0;
    local_2cc = (int *)0x0;
    local_24c = (char *)0x0;
    local_29c = (char *)0x0;
    local_2e8 = 3;
    local_2f0 = 3;
    local_2fc = 3;
    local_300 = 3;
    local_318 = (undefined4 *)0x0;
    iVar20 = 3;
    local_2a0 = (char *)0x0;
    local_2d0 = (char *)0x0;
    local_2a4 = (char *)0x0;
    local_2a8 = (char *)0x0;
    local_2d4 = (char *)0x0;
    local_310 = 0;
    local_314 = 0;
    local_2f8 = (int *)0x0;
    local_31c = (int *)0x0;
    do {
      pcVar14 = *ppcVar18;
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-inform");
      puVar23 = local_318;
      iVar11 = local_2d8;
      if (iVar5 == 0) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_0043d4b4;
        iVar20 = str2fmt(ppcVar18[1]);
        ppcVar18 = ppcVar18 + 1;
      }
      else {
        iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-outform");
        if (iVar5 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0043d4b4;
          local_300 = str2fmt(ppcVar18[1]);
          ppcVar18 = ppcVar18 + 1;
        }
        else {
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-keyform");
          if (iVar5 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0043d4b4;
            local_2fc = str2fmt(ppcVar18[1]);
            ppcVar18 = ppcVar18 + 1;
          }
          else {
            iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,&DAT_00639254);
            if (iVar5 != 0) {
              iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-CAform");
              if (iVar5 == 0) {
                param_1 = param_1 + -1;
                if (param_1 != 0) {
                  local_2f0 = str2fmt(ppcVar18[1]);
                  ppcVar18 = ppcVar18 + 1;
                  goto LAB_0043d24c;
                }
              }
              else {
                iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-CAkeyform");
                if (iVar5 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 != 0) {
                    local_2e8 = str2fmt(ppcVar18[1]);
                    ppcVar18 = ppcVar18 + 1;
                    goto LAB_0043d24c;
                  }
                }
                else {
                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-sigopt");
                  if (iVar5 == 0) {
                    if ((param_1 != 1) &&
                       ((pcVar24 = (code *)PTR_sk_push_006a6fa8, local_318 != (undefined4 *)0x0 ||
                        (puVar23 = (undefined4 *)(*(code *)PTR_sk_new_null_006a6fa4)(),
                        pcVar24 = (code *)PTR_sk_push_006a6fa8, local_318 = puVar23,
                        puVar23 != (undefined4 *)0x0)))) goto LAB_0043d4fc;
                  }
                  else {
                    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-days");
                    if (iVar5 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 != 0) {
                        local_2b0 = (*(code *)PTR_strtol_006a9958)(ppcVar18[1],0,10);
                        ppcVar18 = ppcVar18 + 1;
                        if (local_2b0 != 0) goto LAB_0043d24c;
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar2,"bad number of days\n");
                      }
                    }
                    else {
                      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-passin");
                      if (iVar5 == 0) {
                        param_1 = param_1 + -1;
                        if (param_1 != 0) {
                          local_2ac = ppcVar18[1];
                          ppcVar18 = ppcVar18 + 1;
                          goto LAB_0043d24c;
                        }
                      }
                      else {
                        iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-extfile");
                        if (iVar5 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 != 0) {
                            local_254 = ppcVar18[1];
                            ppcVar18 = ppcVar18 + 1;
                            goto LAB_0043d24c;
                          }
                        }
                        else {
                          iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-extensions");
                          if (iVar5 == 0) {
                            param_1 = param_1 + -1;
                            if (param_1 != 0) {
                              local_2e4 = ppcVar18[1];
                              ppcVar18 = ppcVar18 + 1;
                              goto LAB_0043d24c;
                            }
                          }
                          else {
                            cVar1 = *pcVar14;
                            if ((((cVar1 == '-') && (pcVar14[1] == 'i')) && (pcVar14[2] == 'n')) &&
                               (pcVar14[3] == '\0')) {
                              param_1 = param_1 + -1;
                              if (param_1 != 0) {
                                local_2d4 = ppcVar18[1];
                                ppcVar18 = ppcVar18 + 1;
                                goto LAB_0043d24c;
                              }
                            }
                            else {
                              iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,&DAT_00632514);
                              if (iVar5 == 0) {
                                param_1 = param_1 + -1;
                                if (param_1 != 0) {
                                  local_2a8 = ppcVar18[1];
                                  ppcVar18 = ppcVar18 + 1;
                                  goto LAB_0043d24c;
                                }
                              }
                              else {
                                iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-signkey");
                                if (iVar5 == 0) {
                                  param_1 = param_1 + -1;
                                  if (param_1 != 0) {
                                    local_2a4 = ppcVar18[1];
                                    local_2f8 = (int *)((int)local_2f8 + 1);
                                    local_308 = 1;
                                    ppcVar18 = ppcVar18 + 1;
                                    local_2bc = local_2f8;
                                    goto LAB_0043d24c;
                                  }
                                }
                                else if (((cVar1 == '-') && (pcVar14[1] == 'C')) &&
                                        ((pcVar14[2] == 'A' && (pcVar14[3] == '\0')))) {
                                  param_1 = param_1 + -1;
                                  if (param_1 != 0) {
                                    local_2d0 = ppcVar18[1];
                                    local_2f8 = (int *)((int)local_2f8 + 1);
                                    local_308 = 1;
                                    ppcVar18 = ppcVar18 + 1;
                                    local_2e0 = local_2f8;
                                    goto LAB_0043d24c;
                                  }
                                }
                                else {
                                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-CAkey");
                                  if (iVar5 == 0) {
                                    param_1 = param_1 + -1;
                                    if (param_1 != 0) {
                                      local_2a0 = ppcVar18[1];
                                      ppcVar18 = ppcVar18 + 1;
                                      goto LAB_0043d24c;
                                    }
                                  }
                                  else {
                                    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-CAserial");
                                    if (iVar5 == 0) {
                                      param_1 = param_1 + -1;
                                      if (param_1 != 0) {
                                        local_29c = ppcVar18[1];
                                        ppcVar18 = ppcVar18 + 1;
                                        goto LAB_0043d24c;
                                      }
                                    }
                                    else {
                                      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-set_serial");
                                      if (iVar5 == 0) {
                                        if (param_1 != 1) {
                                          local_31c = (int *)(*(code *)PTR_s2i_ASN1_INTEGER_006a6fb4
                                                             )(0,ppcVar18[1]);
                                          piVar15 = local_31c;
joined_r0x0043d508:
                                          param_1 = param_1 + -1;
                                          ppcVar18 = ppcVar18 + 1;
                                          puVar23 = local_318;
                                          if (piVar15 != (int *)0x0) goto LAB_0043d24c;
                                        }
                                      }
                                      else {
                                        iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-addtrust");
                                        if (iVar5 == 0) {
                                          param_1 = param_1 + -1;
                                          if (param_1 != 0) {
                                            iVar5 = (*(code *)PTR_OBJ_txt2obj_006a7000)
                                                              (ppcVar18[1],0);
                                            if (iVar5 != 0) {
                                              if (local_314 == 0) {
                                                local_314 = (*(code *)PTR_sk_new_null_006a6fa4)();
                                              }
                                              (*(code *)PTR_sk_push_006a6fa8)(local_314,iVar5);
                                              local_2b8 = 1;
                                              ppcVar18 = ppcVar18 + 1;
                                              goto LAB_0043d24c;
                                            }
                                            (*(code *)PTR_BIO_printf_006a6e38)
                                                      (*(undefined4 *)puVar2,
                                                       "Invalid trust object value %s\n",ppcVar18[1]
                                                      );
                                          }
                                        }
                                        else {
                                          iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                            (pcVar14,"-addreject");
                                          if (iVar5 == 0) {
                                            param_1 = param_1 + -1;
                                            if (param_1 != 0) {
                                              iVar5 = (*(code *)PTR_OBJ_txt2obj_006a7000)
                                                                (ppcVar18[1],0);
                                              if (iVar5 != 0) {
                                                if (local_310 == 0) {
                                                  local_310 = (*(code *)PTR_sk_new_null_006a6fa4)();
                                                }
                                                (*(code *)PTR_sk_push_006a6fa8)(local_310,iVar5);
                                                local_2b8 = 1;
                                                ppcVar18 = ppcVar18 + 1;
                                                goto LAB_0043d24c;
                                              }
                                              (*(code *)PTR_BIO_printf_006a6e38)
                                                        (*(undefined4 *)puVar2,
                                                         "Invalid reject object value %s\n",
                                                         ppcVar18[1]);
                                            }
                                          }
                                          else {
                                            iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                              (pcVar14,"-setalias");
                                            if (iVar5 == 0) {
                                              param_1 = param_1 + -1;
                                              if (param_1 != 0) {
                                                local_24c = ppcVar18[1];
                                                local_2b8 = 1;
                                                ppcVar18 = ppcVar18 + 1;
                                                goto LAB_0043d24c;
                                              }
                                            }
                                            else {
                                              iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                (pcVar14,"-certopt");
                                              if (iVar5 == 0) {
                                                if (param_1 != 1) {
                                                  puVar23 = &local_214;
                                                  pcVar24 = (code *)PTR_set_cert_ex_006a6fb0;
LAB_0043d4fc:
                                                  piVar15 = (int *)(*pcVar24)(puVar23,ppcVar18[1]);
                                                  goto joined_r0x0043d508;
                                                }
                                              }
                                              else {
                                                iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                  (pcVar14,"-nameopt");
                                                if (iVar5 != 0) {
                                                  iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                    (pcVar14,"-engine");
                                                  if (iVar5 == 0) {
                                                    param_1 = param_1 + -1;
                                                    if (param_1 == 0) goto LAB_0043d4b4;
                                                    local_250 = ppcVar18[1];
                                                    ppcVar18 = ppcVar18 + 1;
                                                  }
                                                  else if (((cVar1 == '-') && (pcVar14[1] == 'C'))
                                                          && (pcVar14[2] == '\0')) {
                                                    local_2f8 = (int *)((int)local_2f8 + 1);
                                                    local_268 = local_2f8;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (pcVar14,"-email");
                                                    if (iVar5 == 0) {
                                                      local_2f8 = (int *)((int)local_2f8 + 1);
                                                      local_278 = local_2f8;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                        (pcVar14,"-ocsp_uri");
                                                      if (iVar5 == 0) {
                                                        local_2f8 = (int *)((int)local_2f8 + 1);
                                                        local_274 = local_2f8;
                                                      }
                                                      else {
                                                        iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                          (pcVar14,"-serial");
                                                        if (iVar5 == 0) {
                                                          local_2f8 = (int *)((int)local_2f8 + 1);
                                                          local_298 = local_2f8;
                                                        }
                                                        else {
                                                          iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                            (pcVar14,"-next_serial")
                                                          ;
                                                          if (iVar5 == 0) {
                                                            local_2f8 = (int *)((int)local_2f8 + 1);
                                                            local_2c0 = local_2f8;
                                                          }
                                                          else {
                                                            iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                              (pcVar14,"-modulus");
                                                            if (iVar5 == 0) {
                                                              local_2f8 = (int *)((int)local_2f8 + 1
                                                                                 );
                                                              local_264 = local_2f8;
                                                            }
                                                            else {
                                                              iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                                (pcVar14,"-pubkey");
                                                              if (iVar5 == 0) {
                                                                local_2f8 = (int *)((int)local_2f8 +
                                                                                   1);
                                                                local_260 = local_2f8;
                                                              }
                                                              else {
                                                                iVar5 = (*(code *)
                                                  PTR_strcmp_006a9b18)(pcVar14,"-x509toreq");
                                                  if (iVar5 == 0) {
                                                    local_2f8 = (int *)((int)local_2f8 + 1);
                                                    local_2b4 = local_2f8;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (pcVar14,"-text");
                                                    if (iVar5 == 0) {
                                                      local_2f8 = (int *)((int)local_2f8 + 1);
                                                      local_2cc = local_2f8;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                        (pcVar14,"-hash");
                                                      if ((iVar5 == 0) ||
                                                         (iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                            (pcVar14,"-subject_hash"
                                                                            ), iVar5 == 0)) {
                                                        local_2f8 = (int *)((int)local_2f8 + 1);
                                                        local_28c = local_2f8;
                                                      }
                                                      else {
                                                        iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                          (pcVar14,
                                                  "-subject_hash_old");
                                                  if (iVar5 == 0) {
                                                    local_2f8 = (int *)((int)local_2f8 + 1);
                                                    local_280 = local_2f8;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (pcVar14,"-issuer_hash");
                                                    if (iVar5 == 0) {
                                                      local_2f8 = (int *)((int)local_2f8 + 1);
                                                      local_288 = local_2f8;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                        (pcVar14,"-issuer_hash_old")
                                                      ;
                                                      if (iVar5 == 0) {
                                                        local_2f8 = (int *)((int)local_2f8 + 1);
                                                        local_27c = local_2f8;
                                                      }
                                                      else {
                                                        iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                          (pcVar14,"-subject");
                                                        if (iVar5 == 0) {
                                                          local_2f8 = (int *)((int)local_2f8 + 1);
                                                          local_294 = local_2f8;
                                                        }
                                                        else {
                                                          iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                            (pcVar14,"-issuer");
                                                          if (iVar5 == 0) {
                                                            local_2f8 = (int *)((int)local_2f8 + 1);
                                                            local_290 = local_2f8;
                                                          }
                                                          else {
                                                            iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                              (pcVar14,
                                                  "-fingerprint");
                                                  if (iVar5 == 0) {
                                                    local_2f8 = (int *)((int)local_2f8 + 1);
                                                    local_258 = local_2f8;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (pcVar14,"-dates");
                                                    if (iVar5 == 0) {
                                                      local_2c8 = (int *)((int)local_2f8 + 1);
                                                      local_2f8 = (int *)((int)local_2f8 + 2);
                                                      local_2c4 = local_2f8;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                        (pcVar14,"-purpose");
                                                      if (iVar5 == 0) {
                                                        local_2f8 = (int *)((int)local_2f8 + 1);
                                                        local_25c = local_2f8;
                                                      }
                                                      else {
                                                        iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                          (pcVar14,"-startdate");
                                                        if (iVar5 == 0) {
                                                          local_2f8 = (int *)((int)local_2f8 + 1);
                                                          local_2c8 = local_2f8;
                                                        }
                                                        else {
                                                          iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                            (pcVar14,"-enddate");
                                                          if (iVar5 == 0) {
                                                            local_2f8 = (int *)((int)local_2f8 + 1);
                                                            local_2c4 = local_2f8;
                                                          }
                                                          else {
                                                            iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                              (pcVar14,"-checkend");
                                                            if (iVar5 == 0) {
                                                              param_1 = param_1 + -1;
                                                              if (param_1 == 0) goto LAB_0043d4b4;
                                                              local_238 = (*(code *)
                                                  PTR_strtol_006a9958)(ppcVar18[1],0,10);
                                                  local_23c = 1;
                                                  ppcVar18 = ppcVar18 + 1;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (pcVar14,"-noout");
                                                    if (iVar5 == 0) {
                                                      local_2f8 = (int *)((int)local_2f8 + 1);
                                                      local_2dc = local_2f8;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                        (pcVar14,"-trustout");
                                                      if (iVar5 == 0) {
                                                        local_2b8 = 1;
                                                      }
                                                      else {
                                                        iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                          (pcVar14,"-clrtrust");
                                                        if (iVar5 == 0) {
                                                          local_2f8 = (int *)((int)local_2f8 + 1);
                                                          local_244 = local_2f8;
                                                        }
                                                        else {
                                                          iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                            (pcVar14,"-clrreject");
                                                          if (iVar5 == 0) {
                                                            local_2f8 = (int *)((int)local_2f8 + 1);
                                                            local_240 = (char *)local_2f8;
                                                          }
                                                          else {
                                                            iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                              (pcVar14,"-alias");
                                                            if (iVar5 == 0) {
                                                              local_2f8 = (int *)((int)local_2f8 + 1
                                                                                 );
                                                              local_270 = local_2f8;
                                                            }
                                                            else {
                                                              iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                                (pcVar14,
                                                  "-CAcreateserial");
                                                  if (iVar5 == 0) {
                                                    local_2f8 = (int *)((int)local_2f8 + 1);
                                                    local_248 = local_2f8;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (pcVar14,"-clrext");
                                                    if (iVar5 == 0) {
                                                      local_26c = 1;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                        (pcVar14,"-crlext");
                                                      if (iVar5 == 0) {
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar2,
                                                                                                                                      
                                                  "use -clrext instead of -crlext\n");
                                                  local_26c = 1;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (pcVar14,"-ocspid");
                                                    if (iVar5 == 0) {
                                                      local_2f8 = (int *)((int)local_2f8 + 1);
                                                      local_284 = local_2f8;
                                                    }
                                                    else {
                                                      iVar11 = (*(code *)
                                                  PTR_EVP_get_digestbyname_006a6f2c)(pcVar14 + 1);
                                                  if (iVar11 == 0) {
                                                    (*(code *)PTR_BIO_printf_006a6e38)
                                                              (*(undefined4 *)puVar2,
                                                               "unknown option %s\n",*ppcVar18);
                                                    goto LAB_0043d4b4;
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
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_0043d24c;
                                                }
                                                if (param_1 != 1) {
                                                  puVar23 = &local_218;
                                                  pcVar24 = (code *)PTR_set_name_ex_006a6fac;
                                                  goto LAB_0043d4fc;
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
LAB_0043d4b4:
              if (x509_usage._0_4_ != 0) {
                puVar19 = x509_usage;
                do {
                  puVar19 = (undefined1 *)((int)puVar19 + 4);
                  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"%s");
                } while (*(int *)puVar19 != 0);
                local_318 = (undefined4 *)0x0;
                goto LAB_0043d424;
              }
              goto LAB_0043d420;
            }
            local_308 = 1;
            reqfile = 1;
          }
        }
      }
LAB_0043d24c:
      local_2d8 = iVar11;
      param_1 = param_1 + -1;
      ppcVar18 = ppcVar18 + 1;
    } while (param_1 != 0);
  }
  local_250 = (char *)setup_engine(*(undefined4 *)puVar2,local_250,0);
  if (local_308 != 0) {
    (*(code *)PTR_app_RAND_load_file_006a6ecc)(0,*(undefined4 *)PTR_bio_err_006a6e3c,0);
  }
  puVar12 = PTR_bio_err_006a6e3c;
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  iVar11 = app_passwd(*(undefined4 *)puVar2,local_2ac,0,&local_21c,0);
  puVar23 = local_318;
  if (iVar11 == 0) {
    uVar17 = *(undefined4 *)puVar12;
    pcVar14 = "Error getting password\n";
LAB_0043d414:
    (*(code *)PTR_BIO_printf_006a6e38)(uVar17,pcVar14);
  }
  else {
    iVar11 = (*(code *)PTR_X509_STORE_set_default_paths_006a7298)(local_328);
    if (iVar11 != 0) {
      if ((local_2a0 == (char *)0x0) && (local_2e0 != (int *)0x0)) {
        if (local_2f0 != 3) {
          uVar17 = *(undefined4 *)puVar12;
          pcVar14 = "need to specify a CAkey if using the CA command\n";
          goto LAB_0043d414;
        }
        local_2a0 = local_2d0;
      }
      if (local_254 == (char *)0x0) goto LAB_0043d980;
      local_210 = (int *)0xffffffff;
      iVar11 = (*(code *)PTR_NCONF_new_006a6e58)(0);
      iVar5 = (*(code *)PTR_NCONF_load_006a6e5c)(iVar11,local_254,&local_210);
      local_318 = (undefined4 *)iVar11;
      if (iVar5 == 0) {
        if ((int)local_210 < 1) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar2,"error loading the config file \'%s\'\n",local_254);
        }
        else {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar2,"error on line %ld of config file \'%s\'\n",local_210,
                     local_254);
        }
      }
      else {
        if ((local_2e4 == (char *)0x0) &&
           (local_2e4 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                          (iVar11,"default","extensions"), local_2e4 == (char *)0x0)
           ) {
          local_2e4 = "default";
          (*(code *)PTR_ERR_clear_error_006a6ee0)();
        }
        (*(code *)PTR_X509V3_set_ctx_006a6eb4)(local_1f4,0,0,0,0,1);
        (*(code *)PTR_X509V3_set_nconf_006a6eb8)(local_1f4,iVar11);
        iVar5 = (*(code *)PTR_X509V3_EXT_add_nconf_006a6ebc)(iVar11,local_1f4,local_2e4,0);
        if (iVar5 != 0) goto LAB_0043d754;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar2,"Error Loading extension section %s\n",local_2e4);
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
      }
      goto LAB_0043d424;
    }
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar12);
  }
LAB_0043d420:
  local_318 = (undefined4 *)0x0;
LAB_0043d424:
  do {
    iVar11 = 0;
    local_324 = 0;
    iVar20 = 0;
    local_320 = (int *)0x0;
    local_2f4 = 0;
    puVar22 = (undefined4 *)0x0;
    piVar15 = (int *)0x0;
    uVar17 = 1;
LAB_0043d444:
    if (local_308 != 0) {
      (*(code *)PTR_app_RAND_write_file_006a6f4c)(0,*(undefined4 *)puVar2);
    }
LAB_0043cf2c:
    (*(code *)PTR_OBJ_cleanup_006a6e98)();
    (*(code *)PTR_NCONF_free_006a6e6c)(local_318);
    (*(code *)PTR_BIO_free_all_006a6e74)(iVar20);
    (*(code *)PTR_BIO_free_all_006a6e74)(local_30c);
    (*(code *)PTR_X509_STORE_free_006a7274)(local_328);
    (*(code *)PTR_X509_REQ_free_006a6e8c)(local_320);
    (*(code *)PTR_X509_free_006a6e90)(piVar15);
    (*(code *)PTR_X509_free_006a6e90)(local_324);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(puVar22);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(local_2f4);
    if (puVar23 != (undefined4 *)0x0) {
      (*(code *)PTR_sk_free_006a6e80)(puVar23);
    }
    (*(code *)PTR_X509_REQ_free_006a6e8c)(iVar11);
    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(local_31c);
    (*(code *)PTR_sk_pop_free_006a7058)(local_314,PTR_ASN1_OBJECT_free_006a7004);
    (*(code *)PTR_sk_pop_free_006a7058)(local_310,PTR_ASN1_OBJECT_free_006a7004);
    if (local_21c != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (local_2c == *(int *)puVar3) {
      return uVar17;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0043d980:
    local_318 = (undefined4 *)0x0;
    iVar11 = (int)local_318;
LAB_0043d754:
    local_318 = (undefined4 *)iVar11;
    if (local_304[-0x17b8] == 0) {
      piVar15 = (int *)load_cert(*(undefined4 *)puVar2,local_2d4,iVar20,0,local_250,"Certificate");
      if (piVar15 == (int *)0x0) {
LAB_0043f0b8:
        iVar11 = 0;
        local_324 = 0;
        iVar20 = 0;
        local_320 = (int *)0x0;
        local_2f4 = 0;
        puVar22 = (undefined4 *)0x0;
        uVar17 = 1;
        goto LAB_0043d444;
      }
      local_320 = (int *)0x0;
LAB_0043da20:
      if (local_2e0 == (int *)0x0) {
        local_324 = 0;
      }
      else {
        local_324 = load_cert(*(undefined4 *)puVar2,local_2d0,local_2f0,0,local_250,"CA Certificate"
                             );
        if (local_324 == 0) {
          iVar11 = 0;
          iVar20 = 0;
          local_2f4 = 0;
          puVar22 = (undefined4 *)0x0;
          uVar17 = 1;
          goto LAB_0043d444;
        }
      }
      if (((local_2dc == (int *)0x0) || (local_2cc != (int *)0x0)) || (local_2c0 != (int *)0x0)) {
        (*(code *)PTR_OBJ_create_006a76b0)("2.99999.3","SET.ex3","SET x509v3 extension 3");
        uVar17 = (*(code *)PTR_BIO_s_file_006a6ea0)();
        iVar20 = (*(code *)PTR_BIO_new_006a6ea4)(uVar17);
        if (iVar20 == 0) {
          pcVar14 = *(char **)puVar2;
          pcVar24 = (code *)PTR_ERR_print_errors_006a6e40;
LAB_0043f688:
          iVar11 = 0;
          (*pcVar24)(pcVar14);
          local_2f4 = 0;
          puVar22 = (undefined4 *)0x0;
          uVar17 = 1;
          goto LAB_0043d444;
        }
        if (local_2a8 == (char *)0x0) {
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar20,0x6a,0,*puVar22);
        }
        else {
          iVar11 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar20,0x6c,5,local_2a8);
          pcVar14 = local_2a8;
          pcVar24 = (code *)PTR_perror_006a9a80;
          if (iVar11 < 1) goto LAB_0043f688;
        }
      }
      else {
        iVar20 = 0;
      }
      if (local_24c != (char *)0x0) {
        (*(code *)PTR_X509_alias_set1_006a7254)(piVar15,local_24c,0xffffffff);
      }
      if (local_244 != (int *)0x0) {
        (*(code *)PTR_X509_trust_clear_006a76b4)(piVar15);
      }
      if ((int *)local_240 != (int *)0x0) {
        (*(code *)PTR_X509_reject_clear_006a76b8)(piVar15);
      }
      if (local_314 != 0) {
        for (iVar11 = 0; iVar5 = (*(code *)PTR_sk_num_006a6e2c)(local_314), iVar11 < iVar5;
            iVar11 = iVar11 + 1) {
          uVar17 = (*(code *)PTR_sk_value_006a6e24)(local_314,iVar11);
          (*(code *)PTR_X509_add1_trust_object_006a76bc)(piVar15,uVar17);
        }
      }
      if (local_310 != 0) {
        for (iVar11 = 0; iVar5 = (*(code *)PTR_sk_num_006a6e2c)(local_310), iVar11 < iVar5;
            iVar11 = iVar11 + 1) {
          uVar17 = (*(code *)PTR_sk_value_006a6e24)(local_310,iVar11);
          (*(code *)PTR_X509_add1_reject_object_006a76c0)(piVar15,uVar17);
        }
      }
      if (local_2f8 != (int *)0x0) {
        local_2f0 = 0;
        puVar22 = (undefined4 *)0x0;
        local_2f4 = 0;
        piVar21 = (int *)0x1;
        local_24c = "%s\n";
        local_240 = "-check_ss_sig";
LAB_0043df6c:
        puVar12 = PTR_bio_err_006a6e3c;
        if (local_290 == piVar21) {
          uVar17 = (*(code *)PTR_X509_get_issuer_name_006a76e4)(piVar15);
          print_name(local_30c,"issuer= ",uVar17,local_218);
        }
        else if (local_294 == piVar21) {
          uVar17 = (*(code *)PTR_X509_get_subject_name_006a6f00)(piVar15);
          print_name(local_30c,"subject= ",uVar17,local_218);
        }
        else if (local_298 == piVar21) {
          (*(code *)PTR_BIO_printf_006a6e38)(local_30c,"serial=");
          uVar17 = (*(code *)PTR_X509_get_serialNumber_006a6f9c)(piVar15);
          (*(code *)PTR_i2a_ASN1_INTEGER_006a75f0)(local_30c,uVar17);
          pcVar24 = (code *)PTR_BIO_printf_006a6e38;
LAB_0043eaa4:
          (*pcVar24)(local_30c,"\n");
        }
        else {
          iVar11 = local_2f0;
          if (local_2c0 == piVar21) {
            uVar17 = (*(code *)PTR_X509_get_serialNumber_006a6f9c)(piVar15);
            iVar5 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(uVar17,0);
            if (((iVar5 == 0) || (iVar7 = (*(code *)PTR_BN_add_word_006a70bc)(iVar5,1), iVar7 == 0))
               || (iVar7 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(iVar5,0), iVar7 == 0))
            goto LAB_0043e3d8;
            (*(code *)PTR_BN_free_006a701c)(iVar5);
            (*(code *)PTR_i2a_ASN1_INTEGER_006a75f0)(iVar20,iVar7);
            (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar7);
            (*(code *)PTR_BIO_puts_006a6f58)(iVar20,"\n");
            goto LAB_0043e02c;
          }
          if (local_278 == piVar21) {
            uVar17 = (*(code *)PTR_X509_get1_email_006a76f4)(piVar15);
          }
          else {
            if (local_274 != piVar21) {
              if (piVar21 == local_270) {
                iVar11 = (*(code *)PTR_X509_alias_get0_006a7708)(piVar15,0);
                if (iVar11 == 0) {
                  (*(code *)PTR_BIO_puts_006a6f58)(local_30c,"<No Alias>\n");
                }
                else {
                  (*(code *)PTR_BIO_printf_006a6e38)(local_30c,"%s\n",iVar11);
                }
              }
              else {
                pcVar24 = (code *)PTR_X509_subject_name_hash_006a7704;
                if (((local_28c == piVar21) ||
                    (pcVar24 = (code *)PTR_X509_subject_name_hash_old_006a7700, local_280 == piVar21
                    )) || ((pcVar24 = (code *)PTR_X509_issuer_name_hash_006a7714,
                           local_288 == piVar21 ||
                           (pcVar24 = (code *)PTR_X509_issuer_name_hash_old_006a7710,
                           local_27c == piVar21)))) {
                  uVar17 = (*pcVar24)(piVar15);
                  (*(code *)PTR_BIO_printf_006a6e38)(local_30c,"%08lx\n",uVar17);
                }
                else {
                  if (piVar21 == local_25c) {
                    (*(code *)PTR_BIO_printf_006a6e38)(local_30c,"Certificate purposes:\n");
                    local_244 = (int *)0x638d8c;
                    local_2d4 = "%s%s : ";
                    local_2a8 = "No\n";
                    for (iVar11 = 0; iVar5 = (*(code *)PTR_X509_PURPOSE_get_count_006a747c)(),
                        iVar11 < iVar5; iVar11 = iVar11 + 1) {
                      uVar17 = (*(code *)PTR_X509_PURPOSE_get0_006a7470)(iVar11);
                      uVar13 = (*(code *)PTR_X509_PURPOSE_get_id_006a7718)(uVar17);
                      uVar17 = (*(code *)PTR_X509_PURPOSE_get0_name_006a7478)(uVar17);
                      iVar5 = (*(code *)PTR_X509_check_purpose_006a771c)(piVar15,uVar13,0);
                      (*(code *)PTR_BIO_printf_006a6e38)(local_30c,"%s%s : ",uVar17,"");
                      if (iVar5 == 1) {
                        (*(code *)PTR_BIO_printf_006a6e38)(local_30c,&DAT_00639598);
                      }
                      else if (iVar5 == 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)(local_30c,&DAT_00639594);
                      }
                      else {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (local_30c,"Yes (WARNING code=%d)\n",iVar5);
                      }
                      iVar5 = (*(code *)PTR_X509_check_purpose_006a771c)(piVar15,uVar13,1);
                      (*(code *)PTR_BIO_printf_006a6e38)(local_30c,"%s%s : ",uVar17,&DAT_006395a0);
                      if (iVar5 == 1) {
                        (*(code *)PTR_BIO_printf_006a6e38)(local_30c,&DAT_00639598);
                      }
                      else if (iVar5 == 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)(local_30c,&DAT_00639594);
                      }
                      else {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (local_30c,"Yes (WARNING code=%d)\n",iVar5);
                      }
                    }
                    goto LAB_0043e02c;
                  }
                  if (local_264 == piVar21) {
                    piVar4 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)(piVar15);
                    if (piVar4 == (int *)0x0) {
                      pcVar14 = "Modulus=unavailable\n";
                      uVar13 = *(undefined4 *)puVar2;
                      goto LAB_0043efd0;
                    }
                    (*(code *)PTR_BIO_printf_006a6e38)(local_30c,"Modulus=");
                    if (*piVar4 == 6) {
                      (*(code *)PTR_BN_print_006a6f24)(local_30c,*(undefined4 *)(piVar4[5] + 0x10));
                    }
                    else if (*piVar4 == 0x74) {
                      (*(code *)PTR_BN_print_006a6f24)(local_30c,*(undefined4 *)(piVar4[5] + 0x18));
                    }
                    else {
                      (*(code *)PTR_BIO_printf_006a6e38)(local_30c,"Wrong Algorithm type");
                    }
                    piVar10 = (int *)0x63b2e4;
                    pcVar24 = (code *)PTR_BIO_printf_006a6e38;
                  }
                  else {
                    if (piVar21 != local_260) {
                      if (local_268 == piVar21) {
                        uVar17 = (*(code *)PTR_X509_get_subject_name_006a6f00)(piVar15);
                        (*(code *)PTR_X509_NAME_oneline_006a7010)(uVar17,auStack_12c,0x100);
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (local_30c,"/* subject:%s */\n",auStack_12c);
                        uVar17 = (*(code *)PTR_X509_get_issuer_name_006a76e4)(piVar15);
                        (*(code *)PTR_X509_NAME_oneline_006a7010)(uVar17,auStack_12c,0x100);
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (local_30c,"/* issuer :%s */\n",auStack_12c);
                        uVar17 = (*(code *)PTR_i2d_X509_006a76e8)(piVar15,0);
                        iVar5 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar17,"x509.c",0x311);
                        if (iVar5 != 0) {
                          local_1f4[0] = iVar5;
                          uVar17 = (*(code *)PTR_X509_get_subject_name_006a6f00)(piVar15);
                          uVar9 = (*(code *)PTR_i2d_X509_NAME_006a76ec)(uVar17,local_1f4);
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (local_30c,"unsigned char XXX_subject_name[%d]={\n",uVar9);
                          local_1f4[0] = iVar5;
                          for (uVar16 = 0; (int)uVar16 < (int)uVar9; uVar16 = uVar16 + 1) {
                            (*(code *)PTR_BIO_printf_006a6e38)
                                      (local_30c,"0x%02X,",*(undefined *)(local_1f4[0] + uVar16));
                            if ((uVar16 & 0xf) == 0xf) {
                              (*(code *)PTR_BIO_printf_006a6e38)(local_30c,"\n");
                            }
                          }
                          if ((int)uVar9 < 0) {
                            uVar9 = 0;
                          }
                          if ((uVar9 & 0xf) != 0) {
                            (*(code *)PTR_BIO_printf_006a6e38)(local_30c,"\n");
                          }
                          (*(code *)PTR_BIO_printf_006a6e38)(local_30c,&DAT_006395fc);
                          uVar9 = (*(code *)PTR_i2d_X509_PUBKEY_006a76f0)
                                            (*(undefined4 *)(*piVar15 + 0x18),local_1f4);
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (local_30c,"unsigned char XXX_public_key[%d]={\n",uVar9);
                          local_1f4[0] = iVar5;
                          for (uVar16 = 0; (int)uVar16 < (int)uVar9; uVar16 = uVar16 + 1) {
                            (*(code *)PTR_BIO_printf_006a6e38)
                                      (local_30c,"0x%02X,",*(undefined *)(local_1f4[0] + uVar16));
                            if ((uVar16 & 0xf) == 0xf) {
                              (*(code *)PTR_BIO_printf_006a6e38)(local_30c,"\n");
                            }
                          }
                          if ((int)uVar9 < 0) {
                            uVar9 = 0;
                          }
                          if ((uVar9 & 0xf) != 0) {
                            (*(code *)PTR_BIO_printf_006a6e38)(local_30c,"\n");
                          }
                          (*(code *)PTR_BIO_printf_006a6e38)(local_30c,&DAT_006395fc);
                          uVar9 = (*(code *)PTR_i2d_X509_006a76e8)(piVar15,local_1f4);
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (local_30c,"unsigned char XXX_certificate[%d]={\n",uVar9);
                          local_2d4 = "0x%02X,";
                          local_2a8 = "\n";
                          local_1f4[0] = iVar5;
                          for (uVar16 = 0; (int)uVar16 < (int)uVar9; uVar16 = uVar16 + 1) {
                            (*(code *)PTR_BIO_printf_006a6e38)
                                      (local_30c,"0x%02X,",*(undefined *)(local_1f4[0] + uVar16));
                            if ((uVar16 & 0xf) == 0xf) {
                              (*(code *)PTR_BIO_printf_006a6e38)(local_30c,"\n");
                            }
                          }
                          if ((int)uVar9 < 0) {
                            uVar9 = 0;
                          }
                          if ((uVar9 & 0xf) != 0) {
                            (*(code *)PTR_BIO_printf_006a6e38)(local_30c,"\n");
                          }
                          (*(code *)PTR_BIO_printf_006a6e38)(local_30c,&DAT_006395fc);
                          (*(code *)PTR_CRYPTO_free_006a6e88)(iVar5);
                          local_244 = piVar15;
                          goto LAB_0043e02c;
                        }
                        pcVar14 = "Out of memory\n";
                        uVar13 = *(undefined4 *)puVar2;
                        goto LAB_0043efd0;
                      }
                      if (local_2cc != piVar21) {
                        if (local_2c8 == piVar21) {
                          (*(code *)PTR_BIO_puts_006a6f58)(local_30c,"notBefore=");
                          uVar17 = **(undefined4 **)(*piVar15 + 0x10);
                        }
                        else {
                          if (local_2c4 != piVar21) {
                            if (local_258 == piVar21) {
                              iVar5 = local_2d8;
                              if (local_2d8 == 0) {
                                iVar5 = (*(code *)PTR_EVP_sha1_006a75d0)();
                              }
                              iVar7 = (*(code *)PTR_X509_digest_006a76e0)
                                                (piVar15,iVar5,local_16c,local_1f4);
                              if (iVar7 != 0) {
                                iVar11 = 0;
                                uVar17 = (*(code *)PTR_EVP_MD_type_006a73cc)(iVar5);
                                uVar17 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar17);
                                (*(code *)PTR_BIO_printf_006a6e38)
                                          (local_30c,"%s Fingerprint=",uVar17);
                                while (puVar12 = local_16c + iVar11, iVar11 < local_1f4[0]) {
                                  iVar11 = iVar11 + 1;
                                  ppiVar8 = (int **)&DAT_0000000a;
                                  if (local_1f4[0] != iVar11) {
                                    ppiVar8 = (int **)&DAT_0000003a;
                                  }
                                  (*(code *)PTR_BIO_printf_006a6e38)
                                            (local_30c,"%02X%c",*puVar12,ppiVar8);
                                  local_2d4 = &DAT_0000003a;
                                  local_2a8 = "%02X%c";
                                }
                                goto LAB_0043e02c;
                              }
                              uVar17 = 1;
                              (*(code *)PTR_BIO_printf_006a6e38)
                                        (*(undefined4 *)puVar2,"out of memory\n");
                              goto LAB_0043d444;
                            }
                            if ((local_2bc == piVar21) && (local_2b4 == (int *)0x0)) {
                              (*(code *)PTR_BIO_printf_006a6e38)
                                        (*(undefined4 *)puVar2,"Getting Private key\n");
                              if ((puVar22 == (undefined4 *)0x0) &&
                                 (puVar22 = (undefined4 *)
                                            load_key(*(undefined4 *)PTR_bio_err_006a6e3c,local_2a4,
                                                     local_2fc,0,local_21c,local_250,"Private key"),
                                 puVar22 == (undefined4 *)0x0)) {
LAB_0043e3d8:
                                uVar17 = 1;
                              }
                              else {
                                if (local_308 == 0) {
                                  uVar17 = 0x36a;
LAB_0043e380:
                                  uVar17 = (*(code *)PTR___assert_fail_006a993c)
                                                     ("need_rand","x509.c",uVar17,
                                                      __PRETTY_FUNCTION___16758);
                                  return uVar17;
                                }
                                iVar5 = (*(code *)PTR_X509_get_pubkey_006a6f08)(piVar15);
                                if (iVar5 != 0) {
                                  (*(code *)PTR_EVP_PKEY_copy_parameters_006a7174)(iVar5,puVar22);
                                  (*(code *)PTR_EVP_PKEY_save_parameters_006a76d0)(iVar5,1);
                                  (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar5);
                                  uVar17 = (*(code *)PTR_X509_get_subject_name_006a6f00)(piVar15);
                                  iVar5 = (*(code *)PTR_X509_set_issuer_name_006a6f88)
                                                    (piVar15,uVar17);
                                  if ((((iVar5 != 0) &&
                                       (iVar5 = (*(code *)PTR_X509_gmtime_adj_006a6f8c)
                                                          (**(undefined4 **)(*piVar15 + 0x10),0),
                                       iVar5 != 0)) &&
                                      (iVar5 = (*(code *)PTR_X509_time_adj_ex_006a6f90)
                                                         (*(undefined4 *)
                                                           (*(int *)(*piVar15 + 0x10) + 4),local_2b0
                                                          ,0,0), iVar5 != 0)) &&
                                     (iVar5 = (*(code *)PTR_X509_set_pubkey_006a6f98)
                                                        (piVar15,puVar22), iVar5 != 0)) {
                                    if (local_26c != 0) {
                                      while (iVar5 = (*(code *)PTR_X509_get_ext_count_006a76d4)
                                                               (piVar15), 0 < iVar5) {
                                        (*(code *)PTR_X509_delete_ext_006a76dc)(piVar15,0);
                                      }
                                    }
                                    if (local_318 != (undefined4 *)0x0) {
                                      (*(code *)PTR_X509_set_version_006a6eec)(piVar15,2);
                                      (*(code *)PTR_X509V3_set_ctx_006a6eb4)
                                                (local_1f4,piVar15,piVar15,0,0,0);
                                      (*(code *)PTR_X509V3_set_nconf_006a6eb8)(local_1f4,local_318);
                                      iVar5 = (*(code *)PTR_X509V3_EXT_add_nconf_006a6ebc)
                                                        (local_318,local_1f4,local_2e4,piVar15);
                                      if (iVar5 == 0) goto LAB_0043e34c;
                                    }
                                    iVar5 = (*(code *)PTR_X509_sign_006a76d8)
                                                      (piVar15,puVar22,local_2d8);
                                    if (iVar5 != 0) goto LAB_0043e02c;
                                  }
                                }
LAB_0043e34c:
                                uVar17 = 1;
                                (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
                              }
                              goto LAB_0043d444;
                            }
                            if (local_2e0 == piVar21) {
                              (*(code *)PTR_BIO_printf_006a6e38)
                                        (*(undefined4 *)puVar2,"Getting CA Private Key\n");
                              if ((local_2a0 != (char *)0x0) &&
                                 (local_2f4 = load_key(*(undefined4 *)PTR_bio_err_006a6e3c,local_2a0
                                                       ,local_2e8,0,local_21c,local_250,
                                                       "CA Private Key"), local_2f4 == 0))
                              goto LAB_0043e3d8;
                              if (local_308 == 0) {
                                uVar17 = 0x377;
                                goto LAB_0043e380;
                              }
                              piVar4 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)(local_324);
                              if (piVar4 == (int *)0x0) {
                                (*(code *)PTR_BIO_printf_006a6e38)
                                          (*(undefined4 *)puVar2,
                                           "Error obtaining CA X509 public key\n");
LAB_0043e268:
                                local_304 = local_1f4;
                                (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(local_304);
                                (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
                                if (local_31c != (int *)0x0) goto LAB_0043dc78;
                              }
                              else {
                                (*(code *)PTR_EVP_PKEY_copy_parameters_006a7174)(piVar4,local_2f4);
                                (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar4);
                                iVar5 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)
                                                  (local_1f4,local_328,piVar15,0);
                                if (iVar5 == 0) {
                                  piVar4 = (int *)0x0;
                                  (*(code *)PTR_BIO_printf_006a6e38)
                                            (*(undefined4 *)puVar2,"Error initialising X509 store\n"
                                            );
                                  goto LAB_0043e268;
                                }
                                piVar4 = local_31c;
                                if (local_31c != (int *)0x0) {
LAB_0043e1f4:
                                  (*(code *)PTR_X509_STORE_CTX_set_cert_006a76c8)(local_1f4,piVar15)
                                  ;
                                  (*(code *)PTR_X509_STORE_CTX_set_flags_006a76cc)(local_1f4,0x4000)
                                  ;
                                  if ((local_304[-0x17b8] != 0) ||
                                     (iVar5 = (*(code *)PTR_X509_verify_cert_006a728c)(local_1f4),
                                     0 < iVar5)) {
                                    iVar5 = (*(code *)PTR_X509_check_private_key_006a707c)
                                                      (local_324,local_2f4);
                                    if (iVar5 == 0) {
                                      (*(code *)PTR_BIO_printf_006a6e38)
                                                (*(undefined4 *)puVar2,
                                                 "CA certificate and CA private key do not match\n")
                                      ;
                                    }
                                    else {
                                      uVar17 = (*(code *)PTR_X509_get_subject_name_006a6f00)
                                                         (local_324);
                                      iVar5 = (*(code *)PTR_X509_set_issuer_name_006a6f88)
                                                        (piVar15,uVar17);
                                      if ((((iVar5 != 0) &&
                                           (iVar5 = (*(code *)PTR_X509_set_serialNumber_006a6f84)
                                                              (piVar15,piVar4), iVar5 != 0)) &&
                                          (iVar5 = (*(code *)PTR_X509_gmtime_adj_006a6f8c)
                                                             (**(undefined4 **)(*piVar15 + 0x10),0),
                                          iVar5 != 0)) &&
                                         (iVar5 = (*(code *)PTR_X509_time_adj_ex_006a6f90)
                                                            (*(undefined4 *)
                                                              (*(int *)(*piVar15 + 0x10) + 4),
                                                             local_2b0,0,0), iVar5 != 0)) {
                                        if (local_26c != 0) {
                                          while (iVar5 = (*(code *)PTR_X509_get_ext_count_006a76d4)
                                                                   (piVar15), 0 < iVar5) {
                                            (*(code *)PTR_X509_delete_ext_006a76dc)(piVar15,0);
                                          }
                                        }
                                        if (local_318 != (undefined4 *)0x0) {
                                          (*(code *)PTR_X509_set_version_006a6eec)(piVar15,2);
                                          local_2d4 = (char *)&local_210;
                                          (*(code *)PTR_X509V3_set_ctx_006a6eb4)
                                                    (local_2d4,local_324,piVar15,0,0,0);
                                          (*(code *)PTR_X509V3_set_nconf_006a6eb8)
                                                    (local_2d4,local_318);
                                          iVar5 = (*(code *)PTR_X509V3_EXT_add_nconf_006a6ebc)
                                                            (local_318,local_2d4,local_2e4,piVar15);
                                          if (iVar5 == 0) goto LAB_0043e268;
                                        }
                                        iVar5 = do_X509_sign(*(undefined4 *)puVar2,piVar15,local_2f4
                                                             ,local_2d8,puVar23);
                                        if (iVar5 != 0) {
                                          (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(local_1f4);
                                          if (local_31c == (int *)0x0) {
                                            (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(piVar4);
                                          }
                                          goto LAB_0043e02c;
                                        }
                                      }
                                    }
                                  }
                                  goto LAB_0043e268;
                                }
                                local_210 = (int *)0x0;
                                if (local_29c == (char *)0x0) {
                                  iVar5 = (*(code *)PTR_strlen_006a9a24)(local_2d0);
                                  iVar5 = iVar5 + 6;
                                  pcVar14 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)
                                                              (iVar5,"x509.c",0x3f0);
                                  if (pcVar14 == (char *)0x0) goto LAB_0043e828;
                                  (*(code *)PTR_BUF_strlcpy_006a6f64)(pcVar14,local_2d0,iVar5);
                                  for (pcVar6 = pcVar14; *pcVar6 != '\0'; pcVar6 = pcVar6 + 1) {
                                    if (*pcVar6 == '.') {
                                      *pcVar6 = '\0';
                                      break;
                                    }
                                  }
                                  (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar14,&DAT_006396e0,iVar5);
LAB_0043e77c:
                                  local_2d4 = (char *)load_serial(pcVar14,local_248,0);
                                  if ((int **)local_2d4 != (int **)0x0) {
                                    iVar5 = (*(code *)PTR_BN_add_word_006a70bc)(local_2d4,1);
                                    if (iVar5 == 0) {
                                      (*(code *)PTR_BIO_printf_006a6e38)
                                                (*(undefined4 *)puVar2,"add_word failure\n");
                                    }
                                    else {
                                      save_serial(pcVar14,0,local_2d4,&local_210);
                                    }
                                  }
                                  (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar14);
                                }
                                else {
                                  iVar5 = (*(code *)PTR_strlen_006a9a24)(local_29c);
                                  pcVar14 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)
                                                              (iVar5 + 1,"x509.c",0x3f0);
                                  if (pcVar14 != (char *)0x0) {
                                    (*(code *)PTR_BUF_strlcpy_006a6f64)(pcVar14,local_29c,iVar5 + 1)
                                    ;
                                    goto LAB_0043e77c;
                                  }
LAB_0043e828:
                                  (*(code *)PTR_BIO_printf_006a6e38)
                                            (*(undefined4 *)puVar2,"out of mem\n");
                                  local_2d4 = (char *)0x0;
                                }
                                (*(code *)PTR_BN_free_006a701c)(local_2d4);
                                piVar4 = local_210;
                                if (local_210 != (int *)0x0) goto LAB_0043e1f4;
                                (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(local_1f4);
                                (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
                              }
                              local_304 = local_1f4;
                              uVar17 = 1;
                              (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(piVar4);
                              goto LAB_0043d444;
                            }
                            if (local_2b4 != piVar21) {
                              if (local_284 == piVar21) {
                                (*(code *)PTR_X509_ocspid_print_006a76c4)(iVar20,piVar15);
                              }
                              goto LAB_0043e02c;
                            }
                            (*(code *)PTR_BIO_printf_006a6e38)
                                      (*(undefined4 *)puVar2,"Getting request Private Key\n");
                            if (local_2a4 == (char *)0x0) {
                              uVar17 = 1;
                              (*(code *)PTR_BIO_printf_006a6e38)
                                        (*(undefined4 *)puVar12,"no request key file specified\n");
                              goto LAB_0043d444;
                            }
                            iVar5 = load_key(*(undefined4 *)puVar12,local_2a4,local_2fc,0,local_21c,
                                             local_250,"request key");
                            if (iVar5 == 0) goto LAB_0043e3d8;
                            (*(code *)PTR_BIO_printf_006a6e38)
                                      (*(undefined4 *)puVar12,"Generating certificate request\n");
                            local_2f0 = (*(code *)PTR_X509_to_X509_REQ_006a70cc)
                                                  (piVar15,iVar5,local_2d8);
                            (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar5);
                            if (local_2f0 == 0) {
                              uVar17 = 1;
                              (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar12);
                              iVar11 = local_2f0;
                              goto LAB_0043d444;
                            }
                            if (local_2dc == (int *)0x0) {
                              (*(code *)PTR_X509_REQ_print_006a717c)(iVar20,local_2f0);
                              (*(code *)PTR_PEM_write_bio_X509_REQ_006a6f14)(iVar20,local_2f0);
                              local_2dc = (int *)0x1;
                            }
                            else {
                              local_2dc = (int *)0x1;
                            }
                            goto LAB_0043e02c;
                          }
                          (*(code *)PTR_BIO_puts_006a6f58)(local_30c,"notAfter=");
                          uVar17 = *(undefined4 *)(*(int *)(*piVar15 + 0x10) + 4);
                        }
                        (*(code *)PTR_ASN1_TIME_print_006a716c)(local_30c,uVar17);
                        pcVar24 = (code *)PTR_BIO_puts_006a6f58;
                        goto LAB_0043eaa4;
                      }
                      (*(code *)PTR_X509_print_ex_006a6efc)(local_30c,piVar15,local_218,local_214);
                      goto LAB_0043e02c;
                    }
                    piVar10 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)(piVar15);
                    piVar4 = piVar10;
                    pcVar24 = (code *)PTR_PEM_write_bio_PUBKEY_006a6f28;
                    if (piVar10 == (int *)0x0) {
                      pcVar14 = "Error getting public key\n";
                      uVar13 = *(undefined4 *)puVar2;
                      goto LAB_0043efd0;
                    }
                  }
                  (*pcVar24)(local_30c,piVar10);
                  (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar4);
                }
              }
              goto LAB_0043e02c;
            }
            uVar17 = (*(code *)PTR_X509_get1_ocsp_006a770c)(piVar15);
          }
          for (iVar11 = 0; iVar5 = (*(code *)PTR_sk_num_006a6e2c)(uVar17), iVar11 < iVar5;
              iVar11 = iVar11 + 1) {
            uVar13 = (*(code *)PTR_sk_value_006a6e24)(uVar17,iVar11);
            (*(code *)PTR_BIO_printf_006a6e38)(local_30c,"%s\n",uVar13);
          }
          (*(code *)PTR_X509_email_free_006a76f8)(uVar17);
        }
LAB_0043e02c:
        piVar21 = (int *)((int)piVar21 + 1);
        iVar11 = local_2f0;
        if ((int)local_2f8 < (int)piVar21) goto LAB_0043dbc4;
        goto LAB_0043df6c;
      }
      local_2f4 = 0;
      puVar22 = (undefined4 *)0x0;
      iVar11 = 0;
LAB_0043dbc4:
      if (local_23c != 0) {
        local_1f4[0] = (*(code *)PTR_time_006a9adc)(0);
        local_1f4[0] = local_1f4[0] + local_238;
        iVar5 = (*(code *)PTR_X509_cmp_time_006a76fc)
                          (*(undefined4 *)(*(int *)(*piVar15 + 0x10) + 4),local_1f4);
        if (iVar5 < 0) {
          uVar17 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)(iVar20,"Certificate will expire\n");
        }
        else {
          uVar17 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)(iVar20,"Certificate will not expire\n");
        }
        goto LAB_0043d444;
      }
      if (local_2dc == (int *)0x0) {
        if (local_300 == 1) {
          iVar5 = (*(code *)PTR_i2d_X509_bio_006a6f1c)(iVar20,piVar15);
        }
        else if (local_300 == 3) {
          if (local_2b8 == 0) {
            iVar5 = (*(code *)PTR_PEM_write_bio_X509_006a6f20)(iVar20,piVar15);
          }
          else {
            iVar5 = (*(code *)PTR_PEM_write_bio_X509_AUX_006a7728)(iVar20,piVar15);
          }
        }
        else {
          if (local_300 != 4) {
            uVar17 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar2,"bad output format specified for outfile\n");
            goto LAB_0043d444;
          }
          local_1f4[0] = 0xb;
          local_1ec = "certificate";
          local_210 = local_1f4;
          local_20c = piVar15;
          iVar5 = (*(code *)PTR_ASN1_item_i2d_bio_006a7720)
                            (PTR_NETSCAPE_X509_it_006a7724,iVar20,&local_210);
        }
        if (iVar5 == 0) {
          uVar13 = *(undefined4 *)puVar2;
          pcVar14 = "unable to write certificate\n";
LAB_0043efd0:
          uVar17 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)(uVar13,pcVar14);
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
          goto LAB_0043d444;
        }
      }
      uVar17 = 0;
      goto LAB_0043d444;
    }
    if ((local_2bc != (int *)0x0) || (local_2e0 != (int *)0x0)) {
      uVar17 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      piVar15 = (int *)(*(code *)PTR_BIO_new_006a6ea4)(uVar17);
      if (piVar15 == (int *)0x0) {
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
        goto LAB_0043f0b8;
      }
      if ((int **)local_2d4 == (int **)0x0) {
        (*(code *)PTR_BIO_ctrl_006a6e18)(piVar15,0x6a,0x10,*(undefined4 *)PTR_stdin_006a9a14);
      }
      else {
        iVar11 = (*(code *)PTR_BIO_ctrl_006a6e18)(piVar15,0x6c,3,local_2d4);
        if (iVar11 < 1) {
          (*(code *)PTR_perror_006a9a80)(local_2d4);
          (*(code *)PTR_BIO_free_006a6e70)(piVar15);
          goto LAB_0043d424;
        }
      }
      local_320 = (int *)(*(code *)PTR_PEM_read_bio_X509_REQ_006a6ee4)(piVar15,0,0,0);
      (*(code *)PTR_BIO_free_006a6e70)(piVar15);
      if (local_320 == (int *)0x0) {
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
LAB_0043dc60:
        iVar11 = 0;
        local_324 = 0;
        iVar20 = 0;
        local_2f4 = 0;
        puVar22 = (undefined4 *)0x0;
        piVar15 = (int *)0x0;
LAB_0043dc78:
        uVar17 = 1;
      }
      else {
        if ((((*local_320 == 0) || (iVar11 = *(int *)(*local_320 + 0x14), iVar11 == 0)) ||
            (iVar11 = *(int *)(iVar11 + 4), iVar11 == 0)) || (*(int *)(iVar11 + 8) == 0)) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar2,"The certificate request appears to corrupted\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar2,"It does not contain a public key\n");
          goto LAB_0043dc60;
        }
        piVar15 = (int *)(*(code *)PTR_X509_REQ_get_pubkey_006a6ef4)(local_320);
        piVar21 = local_31c;
        if (piVar15 == (int *)0x0) {
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"error unpacking public key\n");
LAB_0043d88c:
          local_31c = piVar21;
          local_324 = 0;
          iVar20 = 0;
          local_2f4 = 0;
          puVar22 = (undefined4 *)0x0;
          uVar17 = 1;
          iVar11 = 0;
        }
        else {
          piVar4 = (int *)(*(code *)PTR_X509_REQ_verify_006a6ef0)(local_320,piVar15);
          (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar15);
          if (-1 < (int)piVar4) {
            if (piVar4 == (int *)0x0) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar2,"Signature did not match the certificate request\n");
              piVar15 = piVar4;
            }
            else {
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Signature ok\n");
              print_name(*(undefined4 *)puVar2,"subject=",*(undefined4 *)(*local_320 + 0x10),
                         local_218);
              piVar15 = (int *)(*(code *)PTR_X509_new_006a6ee8)();
              if (piVar15 != (int *)0x0) {
                if (local_31c == (int *)0x0) {
                  piVar21 = (int *)(*(code *)PTR_ASN1_INTEGER_new_006a7160)();
                  if (piVar21 == (int *)0x0) {
                    local_31c = (int *)0x0;
                    piVar21 = local_31c;
                  }
                  else {
                    iVar11 = rand_serial(0,piVar21);
                    if ((iVar11 != 0) &&
                       (iVar11 = (*(code *)PTR_X509_set_serialNumber_006a6f84)(piVar15,piVar21),
                       iVar11 != 0)) {
                      (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(piVar21);
                      goto LAB_0043de1c;
                    }
                  }
                }
                else {
                  iVar11 = (*(code *)PTR_X509_set_serialNumber_006a6f84)(piVar15,local_31c);
                  if (iVar11 != 0) {
LAB_0043de1c:
                    iVar11 = (*(code *)PTR_X509_set_issuer_name_006a6f88)
                                       (piVar15,*(undefined4 *)(*local_320 + 0x10));
                    piVar21 = local_31c;
                    if ((iVar11 != 0) &&
                       (iVar11 = (*(code *)PTR_X509_set_subject_name_006a6f94)
                                           (piVar15,*(undefined4 *)(*local_320 + 0x10)), iVar11 != 0
                       )) {
                      (*(code *)PTR_X509_gmtime_adj_006a6f8c)(**(undefined4 **)(*piVar15 + 0x10),0);
                      (*(code *)PTR_X509_time_adj_ex_006a6f90)
                                (*(undefined4 *)(*(int *)(*piVar15 + 0x10) + 4),local_2b0,0,0);
                      uVar17 = (*(code *)PTR_X509_REQ_get_pubkey_006a6ef4)(local_320);
                      (*(code *)PTR_X509_set_pubkey_006a6f98)(piVar15,uVar17);
                      (*(code *)PTR_EVP_PKEY_free_006a6e78)(uVar17);
                      goto LAB_0043da20;
                    }
                  }
                }
              }
            }
            goto LAB_0043d88c;
          }
          iVar11 = 0;
          iVar20 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Signature verification error\n")
          ;
          local_2f4 = 0;
          puVar22 = (undefined4 *)0x0;
          piVar15 = (int *)0x0;
          uVar17 = 1;
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
          local_324 = 0;
        }
      }
      goto LAB_0043d444;
    }
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"We need a private key to sign with\n")
    ;
  } while( true );
}

