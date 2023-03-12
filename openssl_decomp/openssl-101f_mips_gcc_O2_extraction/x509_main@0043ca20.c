
undefined4 x509_main(int param_1,int param_2)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  char *pcVar8;
  int iVar9;
  int **ppiVar10;
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
  int local_32c;
  int local_328;
  int *local_324;
  int *local_320;
  undefined4 *local_31c;
  int local_318;
  int local_314;
  undefined4 local_310;
  int local_30c;
  int *local_308;
  int local_304;
  undefined4 local_300;
  int *local_2fc;
  int local_2f8;
  int local_2f4;
  undefined4 local_2ec;
  char *local_2e8;
  int *local_2e4;
  int *local_2e0;
  char *local_2dc;
  char *local_2d8;
  int *local_2d4;
  int *local_2d0;
  int *local_2cc;
  int *local_2c8;
  int *local_2c4;
  int local_2c0;
  int *local_2bc;
  int local_2b8;
  int local_2b4;
  int *local_2b0;
  int **local_2ac;
  char *local_2a8;
  char *local_2a4;
  char *local_2a0;
  int *local_29c;
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
  int local_270;
  int *local_26c;
  int *local_268;
  int *local_264;
  int *local_260;
  char *local_25c;
  char *local_258;
  char *local_254;
  char *local_250;
  int *local_24c;
  int *local_248;
  int *local_244;
  int local_240;
  int local_23c;
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
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  puVar2 = PTR_bio_err_006a7f3c;
  reqfile = 0;
  local_308 = (int *)&_ITM_registerTMCloneTable;
  local_21c = 0;
  local_218 = 0;
  local_214 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar11 = *(int *)puVar2;
  if (iVar11 == 0) {
    iVar11 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *(int *)puVar2 = iVar11;
  }
  iVar11 = load_config(iVar11,0);
  puVar22 = (undefined4 *)PTR_stdout_006aaad4;
  if (iVar11 == 0) {
    local_32c = 0;
    local_310 = 0;
LAB_0043cad4:
    local_314 = 0;
    local_318 = 0;
    local_31c = (undefined4 *)0x0;
    iVar11 = 0;
    iVar20 = 0;
    local_320 = (int *)0x0;
    local_2f8 = 0;
    local_328 = 0;
    puVar22 = (undefined4 *)0x0;
    local_324 = (int *)0x0;
    puVar23 = (undefined4 *)0x0;
    piVar15 = (int *)0x0;
    uVar17 = 1;
    goto LAB_0043cafc;
  }
  local_310 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
  local_32c = (*(code *)PTR_X509_STORE_new_006a8364)();
  if (local_32c == 0) goto LAB_0043cad4;
  param_1 = param_1 + -1;
  (*(code *)PTR_X509_STORE_set_verify_cb_006a83f8)(local_32c,callb);
  ppcVar18 = (char **)(param_2 + 4);
  local_254 = (char *)0x0;
  local_23c = 0;
  local_240 = 0;
  local_30c = 0;
  local_258 = (char *)0x0;
  local_25c = (char *)0x0;
  local_2e8 = (char *)0x0;
  if (param_1 < 1) {
    local_2b0 = (int *)0x0;
    local_260 = (int *)0x0;
    local_31c = (undefined4 *)0x0;
    local_264 = (int *)0x0;
    local_2b8 = 0x1e;
    local_268 = (int *)0x0;
    local_2bc = (int *)0x0;
    iVar20 = 3;
    local_26c = (int *)0x0;
    local_270 = 0;
    local_274 = (int *)0x0;
    local_244 = (int *)0x0;
    local_248 = (int *)0x0;
    local_2c0 = 0;
    local_278 = (int *)0x0;
    local_27c = (int *)0x0;
    local_24c = (int *)0x0;
    local_2e4 = (int *)0x0;
    local_2c4 = (int *)0x0;
    local_2e0 = (int *)0x0;
    local_280 = (int *)0x0;
    local_284 = (int *)0x0;
    local_28c = (int *)0x0;
    local_290 = (int *)0x0;
    local_2c8 = (int *)0x0;
    local_2cc = (int *)0x0;
    local_2d0 = (int *)0x0;
    local_294 = (int *)0x0;
    local_298 = (int *)0x0;
    local_29c = (int *)0x0;
    local_2d4 = (int *)0x0;
    local_250 = (char *)0x0;
    local_2a0 = (char *)0x0;
    local_2a4 = (char *)0x0;
    local_2d8 = (char *)0x0;
    local_2a8 = (char *)0x0;
    local_2ac = (int **)0x0;
    local_2dc = (char *)0x0;
    local_2ec = 3;
    local_2f4 = 3;
    local_300 = 3;
    local_304 = 3;
    local_314 = 0;
    local_318 = 0;
    local_2fc = (int *)0x0;
    local_320 = (int *)0x0;
    local_2b4 = 0;
    local_288 = (int *)0x0;
  }
  else {
    local_2b4 = 0;
    local_2b0 = (int *)0x0;
    local_260 = (int *)0x0;
    local_2b8 = 0x1e;
    local_264 = (int *)0x0;
    local_268 = (int *)0x0;
    local_2bc = (int *)0x0;
    local_26c = (int *)0x0;
    local_270 = 0;
    local_274 = (int *)0x0;
    local_244 = (int *)0x0;
    local_248 = (int *)0x0;
    local_2c0 = 0;
    local_278 = (int *)0x0;
    local_27c = (int *)0x0;
    local_24c = (int *)0x0;
    local_2e4 = (int *)0x0;
    local_2c4 = (int *)0x0;
    local_2e0 = (int *)0x0;
    local_280 = (int *)0x0;
    local_284 = (int *)0x0;
    local_288 = (int *)0x0;
    local_28c = (int *)0x0;
    local_290 = (int *)0x0;
    local_2c8 = (int *)0x0;
    local_2cc = (int *)0x0;
    local_2d0 = (int *)0x0;
    local_294 = (int *)0x0;
    local_298 = (int *)0x0;
    local_29c = (int *)0x0;
    local_2d4 = (int *)0x0;
    local_250 = (char *)0x0;
    local_2a0 = (char *)0x0;
    local_2ec = 3;
    local_2f4 = 3;
    local_300 = 3;
    local_304 = 3;
    local_31c = (undefined4 *)0x0;
    iVar20 = 3;
    local_2a4 = (char *)0x0;
    local_2d8 = (char *)0x0;
    local_2a8 = (char *)0x0;
    local_2ac = (int **)0x0;
    local_2dc = (char *)0x0;
    local_314 = 0;
    local_318 = 0;
    local_2fc = (int *)0x0;
    local_320 = (int *)0x0;
    do {
      pcVar14 = *ppcVar18;
      iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-inform");
      puVar23 = local_31c;
      iVar11 = local_2b4;
      if (iVar5 == 0) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_0043d084;
        iVar20 = str2fmt(ppcVar18[1]);
        ppcVar18 = ppcVar18 + 1;
      }
      else {
        iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-outform");
        if (iVar5 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0043d084;
          local_304 = str2fmt(ppcVar18[1]);
          ppcVar18 = ppcVar18 + 1;
        }
        else {
          iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-keyform");
          if (iVar5 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0043d084;
            local_300 = str2fmt(ppcVar18[1]);
            ppcVar18 = ppcVar18 + 1;
          }
          else {
            iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,&DAT_00639a94);
            if (iVar5 != 0) {
              iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-CAform");
              if (iVar5 == 0) {
                param_1 = param_1 + -1;
                if (param_1 != 0) {
                  local_2f4 = str2fmt(ppcVar18[1]);
                  ppcVar18 = ppcVar18 + 1;
                  goto LAB_0043ce1c;
                }
              }
              else {
                iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-CAkeyform");
                if (iVar5 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 != 0) {
                    local_2ec = str2fmt(ppcVar18[1]);
                    ppcVar18 = ppcVar18 + 1;
                    goto LAB_0043ce1c;
                  }
                }
                else {
                  iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-sigopt");
                  if (iVar5 == 0) {
                    if ((param_1 != 1) &&
                       ((pcVar24 = (code *)PTR_sk_push_006a80a8, local_31c != (undefined4 *)0x0 ||
                        (puVar23 = (undefined4 *)(*(code *)PTR_sk_new_null_006a80a4)(),
                        pcVar24 = (code *)PTR_sk_push_006a80a8, local_31c = puVar23,
                        puVar23 != (undefined4 *)0x0)))) goto LAB_0043d0cc;
                  }
                  else {
                    iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-days");
                    if (iVar5 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 != 0) {
                        local_2b8 = (*(code *)PTR_strtol_006aaa68)(ppcVar18[1],0,10);
                        ppcVar18 = ppcVar18 + 1;
                        if (local_2b8 != 0) goto LAB_0043ce1c;
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*(undefined4 *)puVar2,"bad number of days\n");
                      }
                    }
                    else {
                      iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-passin");
                      if (iVar5 == 0) {
                        param_1 = param_1 + -1;
                        if (param_1 != 0) {
                          local_258 = ppcVar18[1];
                          ppcVar18 = ppcVar18 + 1;
                          goto LAB_0043ce1c;
                        }
                      }
                      else {
                        iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-extfile");
                        if (iVar5 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 != 0) {
                            local_25c = ppcVar18[1];
                            ppcVar18 = ppcVar18 + 1;
                            goto LAB_0043ce1c;
                          }
                        }
                        else {
                          iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-extensions");
                          if (iVar5 == 0) {
                            param_1 = param_1 + -1;
                            if (param_1 != 0) {
                              local_2e8 = ppcVar18[1];
                              ppcVar18 = ppcVar18 + 1;
                              goto LAB_0043ce1c;
                            }
                          }
                          else {
                            cVar1 = *pcVar14;
                            if ((((cVar1 == '-') && (pcVar14[1] == 'i')) && (pcVar14[2] == 'n')) &&
                               (pcVar14[3] == '\0')) {
                              param_1 = param_1 + -1;
                              if (param_1 != 0) {
                                local_2dc = ppcVar18[1];
                                ppcVar18 = ppcVar18 + 1;
                                goto LAB_0043ce1c;
                              }
                            }
                            else {
                              iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,&DAT_00632edc);
                              if (iVar5 == 0) {
                                param_1 = param_1 + -1;
                                if (param_1 != 0) {
                                  local_2ac = (int **)ppcVar18[1];
                                  ppcVar18 = ppcVar18 + 1;
                                  goto LAB_0043ce1c;
                                }
                              }
                              else {
                                iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-signkey");
                                if (iVar5 == 0) {
                                  param_1 = param_1 + -1;
                                  if (param_1 != 0) {
                                    local_2a8 = ppcVar18[1];
                                    local_2fc = (int *)((int)local_2fc + 1);
                                    local_30c = 1;
                                    ppcVar18 = ppcVar18 + 1;
                                    local_2c4 = local_2fc;
                                    goto LAB_0043ce1c;
                                  }
                                }
                                else if (((cVar1 == '-') && (pcVar14[1] == 'C')) &&
                                        ((pcVar14[2] == 'A' && (pcVar14[3] == '\0')))) {
                                  param_1 = param_1 + -1;
                                  if (param_1 != 0) {
                                    local_2d8 = ppcVar18[1];
                                    local_2fc = (int *)((int)local_2fc + 1);
                                    local_30c = 1;
                                    ppcVar18 = ppcVar18 + 1;
                                    local_2e4 = local_2fc;
                                    goto LAB_0043ce1c;
                                  }
                                }
                                else {
                                  iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-CAkey");
                                  if (iVar5 == 0) {
                                    param_1 = param_1 + -1;
                                    if (param_1 != 0) {
                                      local_2a4 = ppcVar18[1];
                                      ppcVar18 = ppcVar18 + 1;
                                      goto LAB_0043ce1c;
                                    }
                                  }
                                  else {
                                    iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-CAserial");
                                    if (iVar5 == 0) {
                                      param_1 = param_1 + -1;
                                      if (param_1 != 0) {
                                        local_2a0 = ppcVar18[1];
                                        ppcVar18 = ppcVar18 + 1;
                                        goto LAB_0043ce1c;
                                      }
                                    }
                                    else {
                                      iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-set_serial");
                                      if (iVar5 == 0) {
                                        if (param_1 != 1) {
                                          local_320 = (int *)(*(code *)PTR_s2i_ASN1_INTEGER_006a80b4
                                                             )(0,ppcVar18[1]);
                                          piVar15 = local_320;
joined_r0x0043d0d8:
                                          param_1 = param_1 + -1;
                                          ppcVar18 = ppcVar18 + 1;
                                          puVar23 = local_31c;
                                          if (piVar15 != (int *)0x0) goto LAB_0043ce1c;
                                        }
                                      }
                                      else {
                                        iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-addtrust");
                                        if (iVar5 == 0) {
                                          param_1 = param_1 + -1;
                                          if (param_1 != 0) {
                                            iVar5 = (*(code *)PTR_OBJ_txt2obj_006a8100)
                                                              (ppcVar18[1],0);
                                            if (iVar5 != 0) {
                                              if (local_318 == 0) {
                                                local_318 = (*(code *)PTR_sk_new_null_006a80a4)();
                                              }
                                              (*(code *)PTR_sk_push_006a80a8)(local_318,iVar5);
                                              local_2c0 = 1;
                                              ppcVar18 = ppcVar18 + 1;
                                              goto LAB_0043ce1c;
                                            }
                                            (*(code *)PTR_BIO_printf_006a7f38)
                                                      (*(undefined4 *)puVar2,
                                                       "Invalid trust object value %s\n",ppcVar18[1]
                                                      );
                                          }
                                        }
                                        else {
                                          iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                            (pcVar14,"-addreject");
                                          if (iVar5 == 0) {
                                            param_1 = param_1 + -1;
                                            if (param_1 != 0) {
                                              iVar5 = (*(code *)PTR_OBJ_txt2obj_006a8100)
                                                                (ppcVar18[1],0);
                                              if (iVar5 != 0) {
                                                if (local_314 == 0) {
                                                  local_314 = (*(code *)PTR_sk_new_null_006a80a4)();
                                                }
                                                (*(code *)PTR_sk_push_006a80a8)(local_314,iVar5);
                                                local_2c0 = 1;
                                                ppcVar18 = ppcVar18 + 1;
                                                goto LAB_0043ce1c;
                                              }
                                              (*(code *)PTR_BIO_printf_006a7f38)
                                                        (*(undefined4 *)puVar2,
                                                         "Invalid reject object value %s\n",
                                                         ppcVar18[1]);
                                            }
                                          }
                                          else {
                                            iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                              (pcVar14,"-setalias");
                                            if (iVar5 == 0) {
                                              param_1 = param_1 + -1;
                                              if (param_1 != 0) {
                                                local_250 = ppcVar18[1];
                                                local_2c0 = 1;
                                                ppcVar18 = ppcVar18 + 1;
                                                goto LAB_0043ce1c;
                                              }
                                            }
                                            else {
                                              iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                (pcVar14,"-certopt");
                                              if (iVar5 == 0) {
                                                if (param_1 != 1) {
                                                  puVar23 = &local_214;
                                                  pcVar24 = (code *)PTR_set_cert_ex_006a80b0;
LAB_0043d0cc:
                                                  piVar15 = (int *)(*pcVar24)(puVar23,ppcVar18[1]);
                                                  goto joined_r0x0043d0d8;
                                                }
                                              }
                                              else {
                                                iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                  (pcVar14,"-nameopt");
                                                if (iVar5 != 0) {
                                                  iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                    (pcVar14,"-engine");
                                                  if (iVar5 == 0) {
                                                    param_1 = param_1 + -1;
                                                    if (param_1 == 0) goto LAB_0043d084;
                                                    local_254 = ppcVar18[1];
                                                    ppcVar18 = ppcVar18 + 1;
                                                  }
                                                  else if (((cVar1 == '-') && (pcVar14[1] == 'C'))
                                                          && (pcVar14[2] == '\0')) {
                                                    local_2fc = (int *)((int)local_2fc + 1);
                                                    local_26c = local_2fc;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                      (pcVar14,"-email");
                                                    if (iVar5 == 0) {
                                                      local_2fc = (int *)((int)local_2fc + 1);
                                                      local_27c = local_2fc;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                        (pcVar14,"-ocsp_uri");
                                                      if (iVar5 == 0) {
                                                        local_2fc = (int *)((int)local_2fc + 1);
                                                        local_278 = local_2fc;
                                                      }
                                                      else {
                                                        iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                          (pcVar14,"-serial");
                                                        if (iVar5 == 0) {
                                                          local_2fc = (int *)((int)local_2fc + 1);
                                                          local_29c = local_2fc;
                                                        }
                                                        else {
                                                          iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                            (pcVar14,"-next_serial")
                                                          ;
                                                          if (iVar5 == 0) {
                                                            local_2fc = (int *)((int)local_2fc + 1);
                                                            local_2c8 = local_2fc;
                                                          }
                                                          else {
                                                            iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                              (pcVar14,"-modulus");
                                                            if (iVar5 == 0) {
                                                              local_2fc = (int *)((int)local_2fc + 1
                                                                                 );
                                                              local_268 = local_2fc;
                                                            }
                                                            else {
                                                              iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                                (pcVar14,"-pubkey");
                                                              if (iVar5 == 0) {
                                                                local_2fc = (int *)((int)local_2fc +
                                                                                   1);
                                                                local_264 = local_2fc;
                                                              }
                                                              else {
                                                                iVar5 = (*(code *)
                                                  PTR_strcmp_006aac20)(pcVar14,"-x509toreq");
                                                  if (iVar5 == 0) {
                                                    local_2fc = (int *)((int)local_2fc + 1);
                                                    local_2bc = local_2fc;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                      (pcVar14,"-text");
                                                    if (iVar5 == 0) {
                                                      local_2fc = (int *)((int)local_2fc + 1);
                                                      local_2d4 = local_2fc;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                        (pcVar14,"-hash");
                                                      if ((iVar5 == 0) ||
                                                         (iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                            (pcVar14,"-subject_hash"
                                                                            ), iVar5 == 0)) {
                                                        local_2fc = (int *)((int)local_2fc + 1);
                                                        local_290 = local_2fc;
                                                      }
                                                      else {
                                                        iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                          (pcVar14,
                                                  "-subject_hash_old");
                                                  if (iVar5 == 0) {
                                                    local_2fc = (int *)((int)local_2fc + 1);
                                                    local_284 = local_2fc;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                      (pcVar14,"-issuer_hash");
                                                    if (iVar5 == 0) {
                                                      local_2fc = (int *)((int)local_2fc + 1);
                                                      local_28c = local_2fc;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                        (pcVar14,"-issuer_hash_old")
                                                      ;
                                                      if (iVar5 == 0) {
                                                        local_2fc = (int *)((int)local_2fc + 1);
                                                        local_280 = local_2fc;
                                                      }
                                                      else {
                                                        iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                          (pcVar14,"-subject");
                                                        if (iVar5 == 0) {
                                                          local_2fc = (int *)((int)local_2fc + 1);
                                                          local_298 = local_2fc;
                                                        }
                                                        else {
                                                          iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                            (pcVar14,"-issuer");
                                                          if (iVar5 == 0) {
                                                            local_2fc = (int *)((int)local_2fc + 1);
                                                            local_294 = local_2fc;
                                                          }
                                                          else {
                                                            iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                              (pcVar14,
                                                  "-fingerprint");
                                                  if (iVar5 == 0) {
                                                    local_2fc = (int *)((int)local_2fc + 1);
                                                    local_2b0 = local_2fc;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                      (pcVar14,"-dates");
                                                    if (iVar5 == 0) {
                                                      local_2d0 = (int *)((int)local_2fc + 1);
                                                      local_2fc = (int *)((int)local_2fc + 2);
                                                      local_2cc = local_2fc;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                        (pcVar14,"-purpose");
                                                      if (iVar5 == 0) {
                                                        local_2fc = (int *)((int)local_2fc + 1);
                                                        local_260 = local_2fc;
                                                      }
                                                      else {
                                                        iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                          (pcVar14,"-startdate");
                                                        if (iVar5 == 0) {
                                                          local_2fc = (int *)((int)local_2fc + 1);
                                                          local_2d0 = local_2fc;
                                                        }
                                                        else {
                                                          iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                            (pcVar14,"-enddate");
                                                          if (iVar5 == 0) {
                                                            local_2fc = (int *)((int)local_2fc + 1);
                                                            local_2cc = local_2fc;
                                                          }
                                                          else {
                                                            iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                              (pcVar14,"-checkend");
                                                            if (iVar5 == 0) {
                                                              param_1 = param_1 + -1;
                                                              if (param_1 == 0) goto LAB_0043d084;
                                                              local_23c = (*(code *)
                                                  PTR_strtol_006aaa68)(ppcVar18[1],0,10);
                                                  local_240 = 1;
                                                  ppcVar18 = ppcVar18 + 1;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                      (pcVar14,"-noout");
                                                    if (iVar5 == 0) {
                                                      local_2fc = (int *)((int)local_2fc + 1);
                                                      local_2e0 = local_2fc;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                        (pcVar14,"-trustout");
                                                      if (iVar5 == 0) {
                                                        local_2c0 = 1;
                                                      }
                                                      else {
                                                        iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                          (pcVar14,"-clrtrust");
                                                        if (iVar5 == 0) {
                                                          local_2fc = (int *)((int)local_2fc + 1);
                                                          local_248 = local_2fc;
                                                        }
                                                        else {
                                                          iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                            (pcVar14,"-clrreject");
                                                          if (iVar5 == 0) {
                                                            local_2fc = (int *)((int)local_2fc + 1);
                                                            local_244 = local_2fc;
                                                          }
                                                          else {
                                                            iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                              (pcVar14,"-alias");
                                                            if (iVar5 == 0) {
                                                              local_2fc = (int *)((int)local_2fc + 1
                                                                                 );
                                                              local_274 = local_2fc;
                                                            }
                                                            else {
                                                              iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                                (pcVar14,
                                                  "-CAcreateserial");
                                                  if (iVar5 == 0) {
                                                    local_2fc = (int *)((int)local_2fc + 1);
                                                    local_24c = local_2fc;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                      (pcVar14,"-clrext");
                                                    if (iVar5 == 0) {
                                                      local_270 = 1;
                                                    }
                                                    else {
                                                      iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                        (pcVar14,"-crlext");
                                                      if (iVar5 == 0) {
                                                        (*(code *)PTR_BIO_printf_006a7f38)
                                                                  (*(undefined4 *)puVar2,
                                                                                                                                      
                                                  "use -clrext instead of -crlext\n");
                                                  local_270 = 1;
                                                  }
                                                  else {
                                                    iVar5 = (*(code *)PTR_strcmp_006aac20)
                                                                      (pcVar14,"-ocspid");
                                                    if (iVar5 == 0) {
                                                      local_2fc = (int *)((int)local_2fc + 1);
                                                      local_288 = local_2fc;
                                                    }
                                                    else {
                                                      iVar11 = (*(code *)
                                                  PTR_EVP_get_digestbyname_006a802c)(pcVar14 + 1);
                                                  if (iVar11 == 0) {
                                                    (*(code *)PTR_BIO_printf_006a7f38)
                                                              (*(undefined4 *)puVar2,
                                                               "unknown option %s\n",*ppcVar18);
                                                    goto LAB_0043d084;
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
                                                  goto LAB_0043ce1c;
                                                }
                                                if (param_1 != 1) {
                                                  puVar23 = &local_218;
                                                  pcVar24 = (code *)PTR_set_name_ex_006a80ac;
                                                  goto LAB_0043d0cc;
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
LAB_0043d084:
              if (x509_usage._0_4_ != 0) {
                puVar19 = x509_usage;
                do {
                  puVar19 = (undefined1 *)((int)puVar19 + 4);
                  (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"%s");
                } while (*(int *)puVar19 != 0);
                local_31c = (undefined4 *)0x0;
                goto LAB_0043cff4;
              }
              goto LAB_0043cff0;
            }
            local_30c = 1;
            reqfile = 1;
          }
        }
      }
LAB_0043ce1c:
      local_2b4 = iVar11;
      param_1 = param_1 + -1;
      ppcVar18 = ppcVar18 + 1;
    } while (param_1 != 0);
  }
  local_254 = (char *)setup_engine(*(undefined4 *)puVar2,local_254,0);
  if (local_30c != 0) {
    (*(code *)PTR_app_RAND_load_file_006a7fcc)(0,*(undefined4 *)PTR_bio_err_006a7f3c,0);
  }
  puVar12 = PTR_bio_err_006a7f3c;
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  iVar11 = app_passwd(*(undefined4 *)puVar2,local_258,0,&local_21c,0);
  puVar23 = local_31c;
  if (iVar11 == 0) {
    uVar17 = *(undefined4 *)puVar12;
    pcVar14 = "Error getting password\n";
LAB_0043cfe4:
    (*(code *)PTR_BIO_printf_006a7f38)(uVar17,pcVar14);
  }
  else {
    iVar11 = (*(code *)PTR_X509_STORE_set_default_paths_006a83a0)(local_32c);
    if (iVar11 != 0) {
      if ((local_2a4 == (char *)0x0) && (local_2e4 != (int *)0x0)) {
        if (local_2f4 != 3) {
          uVar17 = *(undefined4 *)puVar12;
          pcVar14 = "need to specify a CAkey if using the CA command\n";
          goto LAB_0043cfe4;
        }
        local_2a4 = local_2d8;
      }
      if (local_25c == (char *)0x0) goto LAB_0043d54c;
      local_210 = (int *)0xffffffff;
      iVar11 = (*(code *)PTR_NCONF_new_006a7f58)(0);
      iVar5 = (*(code *)PTR_NCONF_load_006a7f5c)(iVar11,local_25c,&local_210);
      local_31c = (undefined4 *)iVar11;
      if (iVar5 == 0) {
        if ((int)local_210 < 1) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar2,"error loading the config file \'%s\'\n",local_25c);
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar2,"error on line %ld of config file \'%s\'\n",local_210,
                     local_25c);
        }
      }
      else {
        if ((local_2e8 == (char *)0x0) &&
           (local_2e8 = (char *)(*(code *)PTR_NCONF_get_string_006a7fa8)
                                          (iVar11,"default","extensions"), local_2e8 == (char *)0x0)
           ) {
          local_2e8 = "default";
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        (*(code *)PTR_X509V3_set_ctx_006a7fb4)(local_1f4,0,0,0,0,1);
        (*(code *)PTR_X509V3_set_nconf_006a7fb8)(local_1f4,iVar11);
        iVar5 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)(iVar11,local_1f4,local_2e8,0);
        if (iVar5 != 0) goto LAB_0043d320;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar2,"Error Loading extension section %s\n",local_2e8);
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
      }
      goto LAB_0043cff4;
    }
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar12);
  }
LAB_0043cff0:
  local_31c = (undefined4 *)0x0;
LAB_0043cff4:
  do {
    iVar11 = 0;
    local_328 = 0;
    iVar20 = 0;
    local_324 = (int *)0x0;
    local_2f8 = 0;
    puVar22 = (undefined4 *)0x0;
    piVar15 = (int *)0x0;
    uVar17 = 1;
LAB_0043d014:
    if (local_30c != 0) {
      (*(code *)PTR_app_RAND_write_file_006a804c)(0,*(undefined4 *)puVar2);
    }
LAB_0043cafc:
    (*(code *)PTR_OBJ_cleanup_006a7f98)();
    (*(code *)PTR_NCONF_free_006a7f6c)(local_31c);
    (*(code *)PTR_BIO_free_all_006a7f74)(iVar20);
    (*(code *)PTR_BIO_free_all_006a7f74)(local_310);
    (*(code *)PTR_X509_STORE_free_006a8384)(local_32c);
    (*(code *)PTR_X509_REQ_free_006a7f8c)(local_324);
    (*(code *)PTR_X509_free_006a7f90)(piVar15);
    (*(code *)PTR_X509_free_006a7f90)(local_328);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(puVar22);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(local_2f8);
    if (puVar23 != (undefined4 *)0x0) {
      (*(code *)PTR_sk_free_006a7f80)(puVar23);
    }
    (*(code *)PTR_X509_REQ_free_006a7f8c)(iVar11);
    (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(local_320);
    (*(code *)PTR_sk_pop_free_006a8158)(local_318,PTR_ASN1_OBJECT_free_006a8104);
    (*(code *)PTR_sk_pop_free_006a8158)(local_314,PTR_ASN1_OBJECT_free_006a8104);
    if (local_21c != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (local_2c == *(int *)puVar3) {
      return uVar17;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0043d54c:
    local_31c = (undefined4 *)0x0;
    iVar11 = (int)local_31c;
LAB_0043d320:
    local_31c = (undefined4 *)iVar11;
    if (local_308[-0x1374] == 0) {
      piVar15 = (int *)load_cert(*(undefined4 *)puVar2,local_2dc,iVar20,0,local_254,"Certificate");
      if (piVar15 == (int *)0x0) {
LAB_0043f208:
        iVar11 = 0;
        local_328 = 0;
        iVar20 = 0;
        local_324 = (int *)0x0;
        local_2f8 = 0;
        puVar22 = (undefined4 *)0x0;
        uVar17 = 1;
        goto LAB_0043d014;
      }
      local_324 = (int *)0x0;
LAB_0043d5ec:
      if (local_2e4 == (int *)0x0) {
        local_328 = 0;
      }
      else {
        local_328 = load_cert(*(undefined4 *)puVar2,local_2d8,local_2f4,0,local_254,"CA Certificate"
                             );
        if (local_328 == 0) {
          iVar11 = 0;
          iVar20 = 0;
          local_2f8 = 0;
          puVar22 = (undefined4 *)0x0;
          uVar17 = 1;
          goto LAB_0043d014;
        }
      }
      if (((local_2e0 == (int *)0x0) || (local_2d4 != (int *)0x0)) || (local_2c8 != (int *)0x0)) {
        (*(code *)PTR_OBJ_create_006a87a0)("2.99999.3","SET.ex3","SET x509v3 extension 3");
        uVar17 = (*(code *)PTR_BIO_s_file_006a7fa0)();
        iVar20 = (*(code *)PTR_BIO_new_006a7fa4)(uVar17);
        if (iVar20 == 0) {
          ppiVar10 = *(int ***)puVar2;
          pcVar24 = (code *)PTR_ERR_print_errors_006a7f40;
LAB_0043f41c:
          iVar11 = 0;
          (*pcVar24)(ppiVar10);
          local_2f8 = 0;
          puVar22 = (undefined4 *)0x0;
          uVar17 = 1;
          goto LAB_0043d014;
        }
        if (local_2ac == (int **)0x0) {
          (*(code *)PTR_BIO_ctrl_006a7f18)(iVar20,0x6a,0,*puVar22);
        }
        else {
          iVar11 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar20,0x6c,5,local_2ac);
          ppiVar10 = local_2ac;
          pcVar24 = (code *)PTR_perror_006aab88;
          if (iVar11 < 1) goto LAB_0043f41c;
        }
      }
      else {
        iVar20 = 0;
      }
      if (local_250 != (char *)0x0) {
        (*(code *)PTR_X509_alias_set1_006a8368)(piVar15,local_250,0xffffffff);
      }
      if (local_248 != (int *)0x0) {
        (*(code *)PTR_X509_trust_clear_006a87a4)(piVar15);
      }
      if (local_244 != (int *)0x0) {
        (*(code *)PTR_X509_reject_clear_006a87a8)(piVar15);
      }
      if (local_318 != 0) {
        for (iVar11 = 0; iVar5 = (*(code *)PTR_sk_num_006a7f2c)(local_318), iVar11 < iVar5;
            iVar11 = iVar11 + 1) {
          uVar17 = (*(code *)PTR_sk_value_006a7f24)(local_318,iVar11);
          (*(code *)PTR_X509_add1_trust_object_006a87ac)(piVar15,uVar17);
        }
      }
      if (local_314 != 0) {
        for (iVar11 = 0; iVar5 = (*(code *)PTR_sk_num_006a7f2c)(local_314), iVar11 < iVar5;
            iVar11 = iVar11 + 1) {
          uVar17 = (*(code *)PTR_sk_value_006a7f24)(local_314,iVar11);
          (*(code *)PTR_X509_add1_reject_object_006a87b0)(piVar15,uVar17);
        }
      }
      if (local_2fc != (int *)0x0) {
        local_248 = (int *)(local_2b8 * 0x15180);
        local_2f4 = 0;
        puVar22 = (undefined4 *)0x0;
        local_2f8 = 0;
        piVar21 = (int *)0x1;
        local_250 = "%s\n";
LAB_0043db50:
        puVar12 = PTR_bio_err_006a7f3c;
        if (local_294 == piVar21) {
          uVar17 = (*(code *)PTR_X509_get_issuer_name_006a87d0)(piVar15);
          print_name(local_310,"issuer= ",uVar17,local_218);
        }
        else if (local_298 == piVar21) {
          uVar17 = (*(code *)PTR_X509_get_subject_name_006a8000)(piVar15);
          print_name(local_310,"subject= ",uVar17,local_218);
        }
        else if (local_29c == piVar21) {
          (*(code *)PTR_BIO_printf_006a7f38)(local_310,"serial=");
          uVar17 = (*(code *)PTR_X509_get_serialNumber_006a809c)(piVar15);
          (*(code *)PTR_i2a_ASN1_INTEGER_006a86e4)(local_310,uVar17);
          pcVar24 = (code *)PTR_BIO_printf_006a7f38;
LAB_0043e128:
          (*pcVar24)(local_310,"\n");
        }
        else {
          iVar11 = local_2f4;
          if (local_2c8 == piVar21) {
            uVar17 = (*(code *)PTR_X509_get_serialNumber_006a809c)(piVar15);
            iVar5 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(uVar17,0);
            if (((iVar5 == 0) || (iVar9 = (*(code *)PTR_BN_add_word_006a81bc)(iVar5,1), iVar9 == 0))
               || (iVar9 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(iVar5,0), iVar9 == 0))
            goto LAB_0043e0d8;
            (*(code *)PTR_BN_free_006a811c)(iVar5);
            (*(code *)PTR_i2a_ASN1_INTEGER_006a86e4)(iVar20,iVar9);
            (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar9);
            (*(code *)PTR_BIO_puts_006a8058)(iVar20,"\n");
            goto LAB_0043dc0c;
          }
          if (local_27c == piVar21) {
            uVar17 = (*(code *)PTR_X509_get1_email_006a8808)(piVar15);
          }
          else {
            if (local_278 != piVar21) {
              if (local_274 == piVar21) {
                iVar11 = (*(code *)PTR_X509_alias_get0_006a87fc)(piVar15,0);
                if (iVar11 == 0) {
                  (*(code *)PTR_BIO_puts_006a8058)(local_310,"<No Alias>\n");
                }
                else {
                  (*(code *)PTR_BIO_printf_006a7f38)(local_310,"%s\n",iVar11);
                }
              }
              else {
                pcVar24 = (code *)PTR_X509_subject_name_hash_006a87f8;
                if (((local_290 == piVar21) ||
                    (pcVar24 = (code *)PTR_X509_subject_name_hash_old_006a87f4, local_284 == piVar21
                    )) || ((pcVar24 = (code *)PTR_X509_issuer_name_hash_006a87f0,
                           local_28c == piVar21 ||
                           (pcVar24 = (code *)PTR_X509_issuer_name_hash_old_006a87ec,
                           local_280 == piVar21)))) {
                  uVar17 = (*pcVar24)(piVar15);
                  (*(code *)PTR_BIO_printf_006a7f38)(local_310,"%08lx\n",uVar17);
                }
                else {
                  if (local_260 == piVar21) {
                    (*(code *)PTR_BIO_printf_006a7f38)(local_310,"Certificate purposes:\n");
                    local_244 = (int *)0x6395d0;
                    local_2dc = "%s%s : ";
                    local_2ac = (int **)0x640000;
                    for (iVar11 = 0; iVar5 = (*(code *)PTR_X509_PURPOSE_get_count_006a857c)(),
                        iVar11 < iVar5; iVar11 = iVar11 + 1) {
                      uVar17 = (*(code *)PTR_X509_PURPOSE_get0_006a8570)(iVar11);
                      uVar13 = (*(code *)PTR_X509_PURPOSE_get_id_006a87e4)(uVar17);
                      uVar17 = (*(code *)PTR_X509_PURPOSE_get0_name_006a8578)(uVar17);
                      iVar5 = (*(code *)PTR_X509_check_purpose_006a87e8)(piVar15,uVar13,0);
                      (*(code *)PTR_BIO_printf_006a7f38)(local_310,"%s%s : ",uVar17,"");
                      if (iVar5 == 1) {
                        (*(code *)PTR_BIO_printf_006a7f38)(local_310,&DAT_00639dd8);
                      }
                      else if (iVar5 == 0) {
                        (*(code *)PTR_BIO_printf_006a7f38)(local_310,&DAT_00639dd4);
                      }
                      else {
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (local_310,"Yes (WARNING code=%d)\n",iVar5);
                      }
                      iVar5 = (*(code *)PTR_X509_check_purpose_006a87e8)(piVar15,uVar13,1);
                      (*(code *)PTR_BIO_printf_006a7f38)(local_310,"%s%s : ",uVar17,&DAT_00639de0);
                      if (iVar5 == 1) {
                        (*(code *)PTR_BIO_printf_006a7f38)(local_310,&DAT_00639dd8);
                      }
                      else if (iVar5 == 0) {
                        (*(code *)PTR_BIO_printf_006a7f38)(local_310,&DAT_00639dd4);
                      }
                      else {
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (local_310,"Yes (WARNING code=%d)\n",iVar5);
                      }
                    }
                    goto LAB_0043dc0c;
                  }
                  if (piVar21 == local_268) {
                    piVar4 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)(piVar15);
                    if (piVar4 == (int *)0x0) {
                      pcVar14 = "Modulus=unavailable\n";
                      uVar13 = *(undefined4 *)puVar2;
                      goto LAB_0043eba4;
                    }
                    (*(code *)PTR_BIO_printf_006a7f38)(local_310,"Modulus=");
                    if (*piVar4 == 6) {
                      (*(code *)PTR_BN_print_006a8024)(local_310,*(undefined4 *)(piVar4[5] + 0x10));
                    }
                    else if (*piVar4 == 0x74) {
                      (*(code *)PTR_BN_print_006a8024)(local_310,*(undefined4 *)(piVar4[5] + 0x18));
                    }
                    else {
                      (*(code *)PTR_BIO_printf_006a7f38)(local_310,"Wrong Algorithm type");
                    }
                    piVar7 = (int *)0x63bac8;
                    pcVar24 = (code *)PTR_BIO_printf_006a7f38;
                  }
                  else {
                    if (piVar21 != local_264) {
                      if (local_26c != piVar21) {
                        if (local_2d4 == piVar21) {
                          (*(code *)PTR_X509_print_ex_006a7ffc)
                                    (local_310,piVar15,local_218,local_214);
                          goto LAB_0043dc0c;
                        }
                        if (local_2d0 == piVar21) {
                          (*(code *)PTR_BIO_puts_006a8058)(local_310,"notBefore=");
                          uVar17 = **(undefined4 **)(*piVar15 + 0x10);
                        }
                        else {
                          if (local_2cc != piVar21) {
                            if (local_2b0 == piVar21) {
                              iVar5 = local_2b4;
                              if (local_2b4 == 0) {
                                iVar5 = (*(code *)PTR_EVP_sha1_006a86c4)();
                              }
                              iVar9 = (*(code *)PTR_X509_digest_006a87e0)
                                                (piVar15,iVar5,local_16c,local_1f4);
                              if (iVar9 != 0) {
                                iVar11 = 0;
                                uVar17 = (*(code *)PTR_EVP_MD_type_006a84cc)(iVar5);
                                uVar17 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar17);
                                (*(code *)PTR_BIO_printf_006a7f38)
                                          (local_310,"%s Fingerprint=",uVar17);
                                while (puVar12 = local_16c + iVar11, iVar11 < local_1f4[0]) {
                                  iVar11 = iVar11 + 1;
                                  ppiVar10 = (int **)&DAT_0000000a;
                                  if (local_1f4[0] != iVar11) {
                                    ppiVar10 = (int **)&DAT_0000003a;
                                  }
                                  (*(code *)PTR_BIO_printf_006a7f38)
                                            (local_310,"%02X%c",*puVar12,ppiVar10);
                                  local_2dc = &DAT_0000003a;
                                  local_2ac = (int **)&DAT_0000000a;
                                }
                                goto LAB_0043dc0c;
                              }
                              uVar17 = 1;
                              (*(code *)PTR_BIO_printf_006a7f38)
                                        (*(undefined4 *)puVar2,"out of memory\n");
                              goto LAB_0043d014;
                            }
                            if ((local_2c4 == piVar21) && (local_2bc == (int *)0x0)) {
                              (*(code *)PTR_BIO_printf_006a7f38)
                                        (*(undefined4 *)puVar2,"Getting Private key\n");
                              if ((puVar22 == (undefined4 *)0x0) &&
                                 (puVar22 = (undefined4 *)
                                            load_key(*(undefined4 *)PTR_bio_err_006a7f3c,local_2a8,
                                                     local_300,0,local_21c,local_254,"Private key"),
                                 puVar22 == (undefined4 *)0x0)) {
LAB_0043e0d8:
                                uVar17 = 1;
                              }
                              else {
                                if (local_30c == 0) {
                                  uVar17 = 0x3c6;
LAB_0043e080:
                                  uVar17 = (*(code *)PTR___assert_fail_006aaa4c)
                                                     ("need_rand","x509.c",uVar17,
                                                      __PRETTY_FUNCTION___16748);
                                  return uVar17;
                                }
                                uVar17 = (*(code *)PTR_X509_get_pubkey_006a8008)(piVar15);
                                (*(code *)PTR_EVP_PKEY_copy_parameters_006a8274)(uVar17,puVar22);
                                (*(code *)PTR_EVP_PKEY_save_parameters_006a87c0)(uVar17,1);
                                (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar17);
                                uVar17 = (*(code *)PTR_X509_get_subject_name_006a8000)(piVar15);
                                iVar5 = (*(code *)PTR_X509_set_issuer_name_006a8088)(piVar15,uVar17)
                                ;
                                if ((((iVar5 != 0) &&
                                     (iVar5 = (*(code *)PTR_X509_gmtime_adj_006a808c)
                                                        (**(undefined4 **)(*piVar15 + 0x10),0),
                                     iVar5 != 0)) &&
                                    (iVar5 = (*(code *)PTR_X509_gmtime_adj_006a808c)
                                                       (*(undefined4 *)
                                                         (*(int *)(*piVar15 + 0x10) + 4),local_248),
                                    iVar5 != 0)) &&
                                   (iVar5 = (*(code *)PTR_X509_set_pubkey_006a8098)(piVar15,puVar22)
                                   , iVar5 != 0)) {
                                  if (local_270 != 0) {
                                    while (iVar5 = (*(code *)PTR_X509_get_ext_count_006a87c4)
                                                             (piVar15), 0 < iVar5) {
                                      (*(code *)PTR_X509_delete_ext_006a87cc)(piVar15,0);
                                    }
                                  }
                                  if (local_31c != (undefined4 *)0x0) {
                                    (*(code *)PTR_X509_set_version_006a7fec)(piVar15,2);
                                    (*(code *)PTR_X509V3_set_ctx_006a7fb4)
                                              (local_1f4,piVar15,piVar15,0,0,0);
                                    (*(code *)PTR_X509V3_set_nconf_006a7fb8)(local_1f4,local_31c);
                                    iVar5 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)
                                                      (local_31c,local_1f4,local_2e8,piVar15);
                                    if (iVar5 == 0) goto LAB_0043e020;
                                  }
                                  iVar5 = (*(code *)PTR_X509_sign_006a87c8)
                                                    (piVar15,puVar22,local_2b4);
                                  if (iVar5 != 0) goto LAB_0043dc0c;
                                }
LAB_0043e020:
                                uVar17 = 1;
                                (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
                              }
                              goto LAB_0043d014;
                            }
                            if (local_2e4 == piVar21) {
                              (*(code *)PTR_BIO_printf_006a7f38)
                                        (*(undefined4 *)puVar2,"Getting CA Private Key\n");
                              if ((local_2a4 != (char *)0x0) &&
                                 (local_2f8 = load_key(*(undefined4 *)PTR_bio_err_006a7f3c,local_2a4
                                                       ,local_2ec,0,local_21c,local_254,
                                                       "CA Private Key"), local_2f8 == 0))
                              goto LAB_0043e0d8;
                              if (local_30c == 0) {
                                uVar17 = 0x3d6;
                                goto LAB_0043e080;
                              }
                              uVar17 = (*(code *)PTR_X509_get_pubkey_006a8008)(local_328);
                              (*(code *)PTR_EVP_PKEY_copy_parameters_006a8274)(uVar17,local_2f8);
                              (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar17);
                              iVar5 = (*(code *)PTR_X509_STORE_CTX_init_006a8304)
                                                (local_1f4,local_32c,piVar15,0);
                              if (iVar5 == 0) {
                                piVar4 = (int *)0x0;
                                (*(code *)PTR_BIO_printf_006a7f38)
                                          (*(undefined4 *)puVar2,"Error initialising X509 store\n");
LAB_0043de44:
                                (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(local_1f4);
                                (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
                                local_308 = local_1f4;
                                if (local_320 != (int *)0x0) goto LAB_0043d848;
                              }
                              else {
                                piVar4 = local_320;
                                if (local_320 != (int *)0x0) {
LAB_0043ddd0:
                                  (*(code *)PTR_X509_STORE_CTX_set_cert_006a87b8)(local_1f4,piVar15)
                                  ;
                                  (*(code *)PTR_X509_STORE_CTX_set_flags_006a87bc)(local_1f4,0x4000)
                                  ;
                                  if ((local_308[-0x1374] != 0) ||
                                     (iVar5 = (*(code *)PTR_X509_verify_cert_006a8308)(local_1f4),
                                     0 < iVar5)) {
                                    iVar5 = (*(code *)PTR_X509_check_private_key_006a817c)
                                                      (local_328,local_2f8);
                                    if (iVar5 == 0) {
                                      (*(code *)PTR_BIO_printf_006a7f38)
                                                (*(undefined4 *)puVar2,
                                                 "CA certificate and CA private key do not match\n")
                                      ;
                                    }
                                    else {
                                      uVar17 = (*(code *)PTR_X509_get_subject_name_006a8000)
                                                         (local_328);
                                      iVar5 = (*(code *)PTR_X509_set_issuer_name_006a8088)
                                                        (piVar15,uVar17);
                                      if ((((iVar5 != 0) &&
                                           (iVar5 = (*(code *)PTR_X509_set_serialNumber_006a8084)
                                                              (piVar15,piVar4), iVar5 != 0)) &&
                                          (iVar5 = (*(code *)PTR_X509_gmtime_adj_006a808c)
                                                             (**(undefined4 **)(*piVar15 + 0x10),0),
                                          iVar5 != 0)) &&
                                         (iVar5 = (*(code *)PTR_X509_time_adj_ex_006a8090)
                                                            (*(undefined4 *)
                                                              (*(int *)(*piVar15 + 0x10) + 4),
                                                             local_2b8,0,0), iVar5 != 0)) {
                                        if (local_270 != 0) {
                                          while (iVar5 = (*(code *)PTR_X509_get_ext_count_006a87c4)
                                                                   (piVar15), 0 < iVar5) {
                                            (*(code *)PTR_X509_delete_ext_006a87cc)(piVar15,0);
                                          }
                                        }
                                        if (local_31c != (undefined4 *)0x0) {
                                          (*(code *)PTR_X509_set_version_006a7fec)(piVar15,2);
                                          local_2dc = (char *)&local_210;
                                          (*(code *)PTR_X509V3_set_ctx_006a7fb4)
                                                    (local_2dc,local_328,piVar15,0,0,0);
                                          (*(code *)PTR_X509V3_set_nconf_006a7fb8)
                                                    (local_2dc,local_31c);
                                          iVar5 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)
                                                            (local_31c,local_2dc,local_2e8,piVar15);
                                          if (iVar5 == 0) goto LAB_0043de44;
                                        }
                                        iVar5 = do_X509_sign(*(undefined4 *)puVar2,piVar15,local_2f8
                                                             ,local_2b4,puVar23);
                                        if (iVar5 != 0) {
                                          (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(local_1f4);
                                          if (local_320 == (int *)0x0) {
                                            (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(piVar4);
                                          }
                                          goto LAB_0043dc0c;
                                        }
                                      }
                                    }
                                  }
                                  goto LAB_0043de44;
                                }
                                local_210 = (int *)0x0;
                                if (local_2a0 == (char *)0x0) {
                                  iVar5 = (*(code *)PTR_strlen_006aab30)(local_2d8);
                                  iVar5 = iVar5 + 6;
                                  pcVar14 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                                              (iVar5,"x509.c",0x45d);
                                  if (pcVar14 == (char *)0x0) goto LAB_0043e784;
                                  (*(code *)PTR_BUF_strlcpy_006a8064)(pcVar14,local_2d8,iVar5);
                                  for (pcVar8 = pcVar14; *pcVar8 != '\0'; pcVar8 = pcVar8 + 1) {
                                    if (*pcVar8 == '.') {
                                      *pcVar8 = '\0';
                                      break;
                                    }
                                  }
                                  (*(code *)PTR_BUF_strlcat_006a8068)(pcVar14,&DAT_00639efc,iVar5);
LAB_0043e6d8:
                                  local_2dc = (char *)load_serial(pcVar14,local_24c,0);
                                  if ((int **)local_2dc != (int **)0x0) {
                                    iVar5 = (*(code *)PTR_BN_add_word_006a81bc)(local_2dc,1);
                                    if (iVar5 == 0) {
                                      (*(code *)PTR_BIO_printf_006a7f38)
                                                (*(undefined4 *)puVar2,"add_word failure\n");
                                    }
                                    else {
                                      save_serial(pcVar14,0,local_2dc,&local_210);
                                    }
                                  }
                                  (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar14);
                                }
                                else {
                                  iVar5 = (*(code *)PTR_strlen_006aab30)(local_2a0);
                                  pcVar14 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                                              (iVar5 + 1,"x509.c",0x45d);
                                  if (pcVar14 != (char *)0x0) {
                                    (*(code *)PTR_BUF_strlcpy_006a8064)(pcVar14,local_2a0,iVar5 + 1)
                                    ;
                                    goto LAB_0043e6d8;
                                  }
LAB_0043e784:
                                  (*(code *)PTR_BIO_printf_006a7f38)
                                            (*(undefined4 *)puVar2,"out of mem\n");
                                  local_2dc = (char *)0x0;
                                }
                                (*(code *)PTR_BN_free_006a811c)(local_2dc);
                                piVar4 = local_210;
                                if (local_210 != (int *)0x0) goto LAB_0043ddd0;
                                (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(local_1f4);
                                (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
                              }
                              uVar17 = 1;
                              (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(piVar4);
                              local_308 = local_1f4;
                              goto LAB_0043d014;
                            }
                            if (local_2bc != piVar21) {
                              if (local_288 == piVar21) {
                                (*(code *)PTR_X509_ocspid_print_006a87b4)(iVar20,piVar15);
                              }
                              goto LAB_0043dc0c;
                            }
                            (*(code *)PTR_BIO_printf_006a7f38)
                                      (*(undefined4 *)puVar2,"Getting request Private Key\n");
                            if (local_2a8 == (char *)0x0) {
                              uVar17 = 1;
                              (*(code *)PTR_BIO_printf_006a7f38)
                                        (*(undefined4 *)puVar12,"no request key file specified\n");
                              goto LAB_0043d014;
                            }
                            iVar5 = load_key(*(undefined4 *)puVar12,local_2a8,local_300,0,local_21c,
                                             local_254,"request key");
                            if (iVar5 == 0) goto LAB_0043e0d8;
                            (*(code *)PTR_BIO_printf_006a7f38)
                                      (*(undefined4 *)puVar12,"Generating certificate request\n");
                            local_2f4 = (*(code *)PTR_X509_to_X509_REQ_006a81cc)
                                                  (piVar15,iVar5,local_2b4);
                            (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar5);
                            if (local_2f4 == 0) {
                              uVar17 = 1;
                              (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar12);
                              iVar11 = local_2f4;
                              goto LAB_0043d014;
                            }
                            if (local_2e0 == (int *)0x0) {
                              (*(code *)PTR_X509_REQ_print_006a827c)(iVar20,local_2f4);
                              (*(code *)PTR_PEM_write_bio_X509_REQ_006a8014)(iVar20,local_2f4);
                              local_2e0 = (int *)0x1;
                            }
                            else {
                              local_2e0 = (int *)0x1;
                            }
                            goto LAB_0043dc0c;
                          }
                          (*(code *)PTR_BIO_puts_006a8058)(local_310,"notAfter=");
                          uVar17 = *(undefined4 *)(*(int *)(*piVar15 + 0x10) + 4);
                        }
                        (*(code *)PTR_ASN1_TIME_print_006a826c)(local_310,uVar17);
                        pcVar24 = (code *)PTR_BIO_puts_006a8058;
                        goto LAB_0043e128;
                      }
                      uVar17 = (*(code *)PTR_X509_get_subject_name_006a8000)(piVar15);
                      (*(code *)PTR_X509_NAME_oneline_006a8110)(uVar17,auStack_12c,0x100);
                      (*(code *)PTR_BIO_printf_006a7f38)(local_310,"/* subject:%s */\n",auStack_12c)
                      ;
                      uVar17 = (*(code *)PTR_X509_get_issuer_name_006a87d0)(piVar15);
                      (*(code *)PTR_X509_NAME_oneline_006a8110)(uVar17,auStack_12c,0x100);
                      (*(code *)PTR_BIO_printf_006a7f38)(local_310,"/* issuer :%s */\n",auStack_12c)
                      ;
                      uVar17 = (*(code *)PTR_i2d_X509_006a87d4)(piVar15,0);
                      iVar11 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar17,"x509.c",0x369);
                      local_1f4[0] = iVar11;
                      uVar17 = (*(code *)PTR_X509_get_subject_name_006a8000)(piVar15);
                      uVar6 = (*(code *)PTR_i2d_X509_NAME_006a87d8)(uVar17,local_1f4);
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (local_310,"unsigned char XXX_subject_name[%d]={\n",uVar6);
                      local_1f4[0] = iVar11;
                      for (uVar16 = 0; (int)uVar16 < (int)uVar6; uVar16 = uVar16 + 1) {
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (local_310,"0x%02X,",*(undefined *)(local_1f4[0] + uVar16));
                        if ((uVar16 & 0xf) == 0xf) {
                          (*(code *)PTR_BIO_printf_006a7f38)(local_310,"\n");
                        }
                      }
                      if ((int)uVar6 < 0) {
                        uVar6 = 0;
                      }
                      if ((uVar6 & 0xf) != 0) {
                        (*(code *)PTR_BIO_printf_006a7f38)(local_310,"\n");
                      }
                      local_2ac = (int **)0x640000;
                      (*(code *)PTR_BIO_printf_006a7f38)(local_310,&DAT_00639e3c);
                      uVar6 = (*(code *)PTR_i2d_X509_PUBKEY_006a87dc)
                                        (*(undefined4 *)(*piVar15 + 0x18),local_1f4);
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (local_310,"unsigned char XXX_public_key[%d]={\n",uVar6);
                      local_1f4[0] = iVar11;
                      for (uVar16 = 0; (int)uVar16 < (int)uVar6; uVar16 = uVar16 + 1) {
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (local_310,"0x%02X,",*(undefined *)(local_1f4[0] + uVar16));
                        if ((uVar16 & 0xf) == 0xf) {
                          (*(code *)PTR_BIO_printf_006a7f38)(local_310,"\n");
                        }
                      }
                      if ((int)uVar6 < 0) {
                        uVar6 = 0;
                      }
                      if ((uVar6 & 0xf) != 0) {
                        (*(code *)PTR_BIO_printf_006a7f38)(local_310,"\n");
                      }
                      (*(code *)PTR_BIO_printf_006a7f38)(local_310,&DAT_00639e3c);
                      uVar6 = (*(code *)PTR_i2d_X509_006a87d4)(piVar15,local_1f4);
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (local_310,"unsigned char XXX_certificate[%d]={\n",uVar6);
                      local_2dc = "0x%02X,";
                      local_1f4[0] = iVar11;
                      for (uVar16 = 0; (int)uVar16 < (int)uVar6; uVar16 = uVar16 + 1) {
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (local_310,"0x%02X,",*(undefined *)(local_1f4[0] + uVar16));
                        if ((uVar16 & 0xf) == 0xf) {
                          (*(code *)PTR_BIO_printf_006a7f38)(local_310,"\n");
                        }
                      }
                      if ((int)uVar6 < 0) {
                        uVar6 = 0;
                      }
                      if ((uVar6 & 0xf) != 0) {
                        (*(code *)PTR_BIO_printf_006a7f38)(local_310,"\n");
                      }
                      (*(code *)PTR_BIO_printf_006a7f38)(local_310,&DAT_00639e3c);
                      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar11);
                      local_244 = piVar15;
                      goto LAB_0043dc0c;
                    }
                    piVar7 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)(piVar15);
                    piVar4 = piVar7;
                    pcVar24 = (code *)PTR_PEM_write_bio_PUBKEY_006a8028;
                    if (piVar7 == (int *)0x0) {
                      pcVar14 = "Error getting public key\n";
                      uVar13 = *(undefined4 *)puVar2;
                      goto LAB_0043eba4;
                    }
                  }
                  (*pcVar24)(local_310,piVar7);
                  (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar4);
                }
              }
              goto LAB_0043dc0c;
            }
            uVar17 = (*(code *)PTR_X509_get1_ocsp_006a8800)(piVar15);
          }
          for (iVar11 = 0; iVar5 = (*(code *)PTR_sk_num_006a7f2c)(uVar17), iVar11 < iVar5;
              iVar11 = iVar11 + 1) {
            uVar13 = (*(code *)PTR_sk_value_006a7f24)(uVar17,iVar11);
            (*(code *)PTR_BIO_printf_006a7f38)(local_310,"%s\n",uVar13);
          }
          (*(code *)PTR_X509_email_free_006a8804)(uVar17);
        }
LAB_0043dc0c:
        piVar21 = (int *)((int)piVar21 + 1);
        iVar11 = local_2f4;
        if ((int)local_2fc < (int)piVar21) goto LAB_0043d794;
        goto LAB_0043db50;
      }
      local_2f8 = 0;
      puVar22 = (undefined4 *)0x0;
      iVar11 = 0;
LAB_0043d794:
      if (local_240 != 0) {
        local_1f4[0] = (*(code *)PTR_time_006aabe4)(0);
        local_1f4[0] = local_23c + local_1f4[0];
        iVar5 = (*(code *)PTR_X509_cmp_time_006a880c)
                          (*(undefined4 *)(*(int *)(*piVar15 + 0x10) + 4),local_1f4);
        if (iVar5 < 0) {
          uVar17 = 1;
          (*(code *)PTR_BIO_printf_006a7f38)(iVar20,"Certificate will expire\n");
        }
        else {
          uVar17 = 0;
          (*(code *)PTR_BIO_printf_006a7f38)(iVar20,"Certificate will not expire\n");
        }
        goto LAB_0043d014;
      }
      if (local_2e0 == (int *)0x0) {
        if (local_304 == 1) {
          iVar5 = (*(code *)PTR_i2d_X509_bio_006a801c)(iVar20,piVar15);
        }
        else if (local_304 == 3) {
          if (local_2c0 == 0) {
            iVar5 = (*(code *)PTR_PEM_write_bio_X509_006a8020)(iVar20,piVar15);
          }
          else {
            iVar5 = (*(code *)PTR_PEM_write_bio_X509_AUX_006a8818)(iVar20,piVar15);
          }
        }
        else {
          if (local_304 != 4) {
            uVar17 = 1;
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar2,"bad output format specified for outfile\n");
            goto LAB_0043d014;
          }
          local_1f4[0] = 0xb;
          local_1ec = "certificate";
          local_210 = local_1f4;
          local_20c = piVar15;
          iVar5 = (*(code *)PTR_ASN1_item_i2d_bio_006a8810)
                            (PTR_NETSCAPE_X509_it_006a8814,iVar20,&local_210);
        }
        if (iVar5 == 0) {
          uVar13 = *(undefined4 *)puVar2;
          pcVar14 = "unable to write certificate\n";
LAB_0043eba4:
          uVar17 = 1;
          (*(code *)PTR_BIO_printf_006a7f38)(uVar13,pcVar14);
          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
          goto LAB_0043d014;
        }
      }
      uVar17 = 0;
      goto LAB_0043d014;
    }
    if ((local_2c4 != (int *)0x0) || (local_2e4 != (int *)0x0)) {
      uVar17 = (*(code *)PTR_BIO_s_file_006a7fa0)();
      piVar15 = (int *)(*(code *)PTR_BIO_new_006a7fa4)(uVar17);
      if (piVar15 == (int *)0x0) {
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
        goto LAB_0043f208;
      }
      if ((int **)local_2dc == (int **)0x0) {
        (*(code *)PTR_BIO_ctrl_006a7f18)(piVar15,0x6a,0x10,*(undefined4 *)PTR_stdin_006aab20);
      }
      else {
        iVar11 = (*(code *)PTR_BIO_ctrl_006a7f18)(piVar15,0x6c,3,local_2dc);
        if (iVar11 < 1) {
          (*(code *)PTR_perror_006aab88)(local_2dc);
          (*(code *)PTR_BIO_free_006a7f70)(piVar15);
          goto LAB_0043cff4;
        }
      }
      local_324 = (int *)(*(code *)PTR_PEM_read_bio_X509_REQ_006a7fe4)(piVar15,0,0,0);
      (*(code *)PTR_BIO_free_006a7f70)(piVar15);
      if (local_324 == (int *)0x0) {
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
LAB_0043d830:
        iVar11 = 0;
        local_328 = 0;
        iVar20 = 0;
        local_2f8 = 0;
        puVar22 = (undefined4 *)0x0;
        piVar15 = (int *)0x0;
LAB_0043d848:
        uVar17 = 1;
      }
      else {
        if ((((*local_324 == 0) || (iVar11 = *(int *)(*local_324 + 0x14), iVar11 == 0)) ||
            (iVar11 = *(int *)(iVar11 + 4), iVar11 == 0)) || (*(int *)(iVar11 + 8) == 0)) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar2,"The certificate request appears to corrupted\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar2,"It does not contain a public key\n");
          goto LAB_0043d830;
        }
        piVar15 = (int *)(*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(local_324);
        piVar21 = local_320;
        if (piVar15 == (int *)0x0) {
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"error unpacking public key\n");
LAB_0043d458:
          local_320 = piVar21;
          local_328 = 0;
          iVar20 = 0;
          local_2f8 = 0;
          puVar22 = (undefined4 *)0x0;
          uVar17 = 1;
          iVar11 = 0;
        }
        else {
          piVar4 = (int *)(*(code *)PTR_X509_REQ_verify_006a7ff0)(local_324,piVar15);
          (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar15);
          if (-1 < (int)piVar4) {
            if (piVar4 == (int *)0x0) {
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar2,"Signature did not match the certificate request\n");
              piVar15 = piVar4;
            }
            else {
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Signature ok\n");
              print_name(*(undefined4 *)puVar2,"subject=",*(undefined4 *)(*local_324 + 0x10),
                         local_218);
              piVar15 = (int *)(*(code *)PTR_X509_new_006a7fe8)();
              if (piVar15 != (int *)0x0) {
                if (local_320 == (int *)0x0) {
                  piVar21 = (int *)(*(code *)PTR_ASN1_INTEGER_new_006a8260)();
                  if (piVar21 == (int *)0x0) {
                    local_320 = (int *)0x0;
                    piVar21 = local_320;
                  }
                  else {
                    iVar11 = rand_serial(0,piVar21);
                    if ((iVar11 != 0) &&
                       (iVar11 = (*(code *)PTR_X509_set_serialNumber_006a8084)(piVar15,piVar21),
                       iVar11 != 0)) {
                      (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(piVar21);
                      goto LAB_0043d9ec;
                    }
                  }
                }
                else {
                  iVar11 = (*(code *)PTR_X509_set_serialNumber_006a8084)(piVar15,local_320);
                  if (iVar11 != 0) {
LAB_0043d9ec:
                    iVar11 = (*(code *)PTR_X509_set_issuer_name_006a8088)
                                       (piVar15,*(undefined4 *)(*local_324 + 0x10));
                    piVar21 = local_320;
                    if ((iVar11 != 0) &&
                       (iVar11 = (*(code *)PTR_X509_set_subject_name_006a8094)
                                           (piVar15,*(undefined4 *)(*local_324 + 0x10)), iVar11 != 0
                       )) {
                      (*(code *)PTR_X509_gmtime_adj_006a808c)(**(undefined4 **)(*piVar15 + 0x10),0);
                      (*(code *)PTR_X509_time_adj_ex_006a8090)
                                (*(undefined4 *)(*(int *)(*piVar15 + 0x10) + 4),local_2b8,0,0);
                      uVar17 = (*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(local_324);
                      (*(code *)PTR_X509_set_pubkey_006a8098)(piVar15,uVar17);
                      (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar17);
                      goto LAB_0043d5ec;
                    }
                  }
                }
              }
            }
            goto LAB_0043d458;
          }
          iVar11 = 0;
          iVar20 = 0;
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Signature verification error\n")
          ;
          local_2f8 = 0;
          puVar22 = (undefined4 *)0x0;
          piVar15 = (int *)0x0;
          uVar17 = 1;
          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
          local_328 = 0;
        }
      }
      goto LAB_0043d014;
    }
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"We need a private key to sign with\n")
    ;
  } while( true );
}

