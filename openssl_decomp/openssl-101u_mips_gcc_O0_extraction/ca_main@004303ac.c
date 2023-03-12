
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ca_main(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  undefined4 uVar17;
  uint uVar18;
  int *piVar19;
  byte *pbVar20;
  int iVar21;
  char **ppcVar22;
  undefined4 *puVar23;
  int iVar24;
  undefined *puVar25;
  undefined4 uVar26;
  int iVar27;
  undefined4 uVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  byte *pbVar34;
  undefined4 *puVar35;
  undefined4 *puVar36;
  undefined4 uVar37;
  char *pcVar38;
  undefined1 *puVar39;
  uint *puVar40;
  int iVar41;
  int iVar42;
  undefined4 uVar43;
  char *pcVar44;
  int iVar45;
  undefined *puVar46;
  undefined *puVar47;
  char *pcVar48;
  char **ppcVar49;
  code *pcVar50;
  int local_44c;
  int local_444;
  char *local_440;
  char *local_438;
  int local_434;
  int local_430;
  int local_42c;
  int local_428;
  int local_424;
  int local_420;
  int local_418;
  char *local_414;
  undefined4 local_410;
  char *local_40c;
  char *local_408;
  char *local_404;
  char *local_400;
  char *local_3f4;
  char *local_3f0;
  int local_3ec;
  char *local_3e8;
  char *local_3e4;
  char *local_3e0;
  char *local_3dc;
  undefined4 local_3d8;
  char *local_3d4;
  int local_3d0;
  char *local_3c8;
  char *local_3c4;
  char *local_3c0;
  char *local_3bc;
  int local_3b8;
  char *local_3b4;
  int local_3ac;
  undefined4 local_3a8;
  char *local_374;
  int local_370;
  int local_36c;
  int local_368;
  int local_364;
  char *local_360;
  undefined4 local_35c;
  undefined4 local_358;
  undefined4 local_354;
  int *local_350;
  undefined4 local_34c;
  undefined4 local_348 [7];
  uint local_32c [3];
  char *local_320;
  undefined4 local_31c;
  undefined4 local_318;
  uint auStack_314 [122];
  undefined auStack_12c [256];
  int local_2c;
  
  puVar11 = PTR___stack_chk_guard_006a9ae8;
  puVar10 = PTR_bio_err_006a6e3c;
  local_368 = -1;
  local_374 = (char *)0x0;
  local_370 = 0;
  local_36c = 0;
  local_364 = 0;
  local_360 = (char *)0x0;
  local_35c = 0;
  local_358 = 0;
  local_354 = 0;
  local_350 = (int *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  local_374 = (char *)0x0;
  conf = 0;
  section = (char *)0x0;
  preserve = 0;
  msie_hack = 0;
  if (*(int *)puVar10 == 0) {
    uVar15 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar45 = (*(code *)PTR_BIO_new_006a6ea4)(uVar15);
    *(int *)puVar10 = iVar45;
    if (iVar45 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar45,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
    }
  }
  param_1 = param_1 + -1;
  local_438 = (char *)0x0;
  ppcVar49 = (char **)(param_2 + 4);
  if (param_1 < 1) {
    local_3d0 = 0;
    bVar8 = false;
    pcVar48 = (char *)0x0;
    local_3ec = 0;
    iVar45 = 0;
    local_424 = 0x1001;
    local_408 = (char *)0x0;
    local_40c = (char *)0x0;
    local_3a8 = 3;
    local_3d4 = (char *)0x0;
    local_3d8 = 0;
    local_3f0 = (char *)0x0;
    local_410 = 0;
    local_440 = (char *)0x0;
    local_3e0 = (char *)0x0;
    local_414 = (char *)0x0;
    local_404 = (char *)0x0;
    local_3c0 = (char *)0x0;
    local_3e4 = (char *)0x0;
    local_3bc = (char *)0x0;
    local_3e8 = (char *)0x0;
    local_3dc = (char *)0x0;
    local_3c4 = (char *)0x0;
    local_3c8 = (char *)0x0;
    local_400 = (char *)0x0;
    local_3f4 = (char *)0x0;
    local_3b8 = 0;
    bVar7 = false;
    bVar9 = false;
    bVar6 = false;
    bVar4 = true;
    local_418 = 0;
    local_3b4 = (char *)0x0;
    local_420 = 0;
    bVar3 = false;
  }
  else {
    local_420 = 0;
    local_3d0 = 0;
    bVar8 = false;
    local_424 = 0x1001;
    local_3ec = 0;
    pcVar48 = (char *)0x0;
    local_408 = (char *)0x0;
    iVar45 = 0;
    local_3a8 = 3;
    local_40c = (char *)0x0;
    local_3d4 = (char *)0x0;
    bVar4 = true;
    local_3d8 = 0;
    local_3f0 = (char *)0x0;
    local_410 = 0;
    local_440 = (char *)0x0;
    local_3e0 = (char *)0x0;
    local_414 = (char *)0x0;
    local_404 = (char *)0x0;
    local_3c0 = (char *)0x0;
    local_3e4 = (char *)0x0;
    local_3bc = (char *)0x0;
    local_3e8 = (char *)0x0;
    local_3dc = (char *)0x0;
    local_3c4 = (char *)0x0;
    local_3c8 = (char *)0x0;
    local_400 = (char *)0x0;
    local_3f4 = (char *)0x0;
    local_3b8 = 0;
    bVar7 = false;
    bVar9 = false;
    bVar6 = false;
    bVar3 = false;
    local_418 = 0;
    local_3b4 = (char *)0x0;
    do {
      while( true ) {
        pcVar38 = *ppcVar49;
        iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-verbose");
        if (iVar14 != 0) break;
        param_1 = param_1 + -1;
        iVar45 = 1;
        ppcVar49 = ppcVar49 + 1;
        if (param_1 == 0) goto LAB_004305cc;
      }
      iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-config");
      if (iVar14 == 0) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_00430988;
        pcVar48 = ppcVar49[1];
        ppcVar22 = ppcVar49 + 1;
      }
      else {
        iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-name");
        if (iVar14 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_00430988;
          section = ppcVar49[1];
          ppcVar22 = ppcVar49 + 1;
        }
        else {
          iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-subj");
          if (iVar14 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00430988;
            local_440 = ppcVar49[1];
            ppcVar22 = ppcVar49 + 1;
          }
          else {
            iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-utf8");
            ppcVar22 = ppcVar49;
            if (iVar14 == 0) {
              local_424 = 0x1000;
            }
            else {
              iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-create_serial");
              if (iVar14 == 0) {
                local_418 = 1;
              }
              else {
                iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-multivalue-rdn");
                if (iVar14 == 0) {
                  local_410 = 1;
                }
                else {
                  iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-startdate");
                  if (iVar14 == 0) {
                    param_1 = param_1 + -1;
                    if (param_1 == 0) goto LAB_00430988;
                    local_40c = ppcVar49[1];
                    ppcVar22 = ppcVar49 + 1;
                  }
                  else {
                    iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-enddate");
                    if (iVar14 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 == 0) goto LAB_00430988;
                      local_408 = ppcVar49[1];
                      ppcVar22 = ppcVar49 + 1;
                    }
                    else {
                      iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-days");
                      if (iVar14 == 0) {
                        param_1 = param_1 + -1;
                        if (param_1 == 0) goto LAB_00430988;
                        local_360 = (char *)(*(code *)PTR_strtol_006a9958)(ppcVar49[1],0,10);
                        ppcVar22 = ppcVar49 + 1;
                      }
                      else {
                        cVar1 = *pcVar38;
                        if ((((cVar1 == '-') && (pcVar38[1] == 'm')) && (pcVar38[2] == 'd')) &&
                           (pcVar38[3] == '\0')) {
                          param_1 = param_1 + -1;
                          if (param_1 == 0) goto LAB_00430988;
                          local_3f4 = ppcVar49[1];
                          ppcVar22 = ppcVar49 + 1;
                        }
                        else {
                          iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-policy");
                          if (iVar14 == 0) {
                            param_1 = param_1 + -1;
                            if (param_1 == 0) goto LAB_00430988;
                            local_400 = ppcVar49[1];
                            ppcVar22 = ppcVar49 + 1;
                          }
                          else {
                            iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-keyfile");
                            if (iVar14 == 0) {
                              param_1 = param_1 + -1;
                              if (param_1 == 0) goto LAB_00430988;
                              local_3c8 = ppcVar49[1];
                              ppcVar22 = ppcVar49 + 1;
                            }
                            else {
                              iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-keyform");
                              if (iVar14 == 0) {
                                param_1 = param_1 + -1;
                                if (param_1 == 0) goto LAB_00430988;
                                local_3a8 = (*(code *)PTR_str2fmt_006a6e4c)(ppcVar49[1]);
                                ppcVar22 = ppcVar49 + 1;
                              }
                              else {
                                iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-passin");
                                if (iVar14 == 0) {
                                  param_1 = param_1 + -1;
                                  if (param_1 == 0) goto LAB_00430988;
                                  local_3b4 = ppcVar49[1];
                                  ppcVar22 = ppcVar49 + 1;
                                }
                                else {
                                  iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,&DAT_006326ec);
                                  if (iVar14 == 0) {
                                    param_1 = param_1 + -1;
                                    if (param_1 == 0) goto LAB_00430988;
                                    local_374 = ppcVar49[1];
                                    ppcVar22 = ppcVar49 + 1;
                                  }
                                  else {
                                    iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-cert");
                                    if (iVar14 == 0) {
                                      param_1 = param_1 + -1;
                                      if (param_1 == 0) goto LAB_00430988;
                                      local_3c4 = ppcVar49[1];
                                      ppcVar22 = ppcVar49 + 1;
                                    }
                                    else {
                                      iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-selfsign");
                                      if (iVar14 == 0) {
                                        local_3d0 = 1;
                                      }
                                      else if (((cVar1 == '-') && (pcVar38[1] == 'i')) &&
                                              ((pcVar38[2] == 'n' && (pcVar38[3] == '\0')))) {
                                        param_1 = param_1 + -1;
                                        if (param_1 == 0) goto LAB_00430988;
                                        local_3dc = ppcVar49[1];
                                        bVar3 = true;
                                        ppcVar22 = ppcVar49 + 1;
                                      }
                                      else {
                                        iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                           (pcVar38,&DAT_00632514);
                                        if (iVar14 == 0) {
                                          param_1 = param_1 + -1;
                                          if (param_1 == 0) goto LAB_00430988;
                                          local_3c0 = ppcVar49[1];
                                          ppcVar22 = ppcVar49 + 1;
                                        }
                                        else {
                                          iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar38,"-outdir")
                                          ;
                                          if (iVar14 == 0) {
                                            param_1 = param_1 + -1;
                                            if (param_1 == 0) goto LAB_00430988;
                                            local_404 = ppcVar49[1];
                                            ppcVar22 = ppcVar49 + 1;
                                          }
                                          else {
                                            iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                               (pcVar38,"-sigopt");
                                            if (iVar14 == 0) {
                                              param_1 = param_1 + -1;
                                              if (param_1 == 0) {
LAB_00430988:
                                                (*(code *)PTR_BIO_printf_006a6e38)
                                                          (*(undefined4 *)puVar10,
                                                           "unknown option %s\n",pcVar38);
                                                if (ca_usage._0_4_ == 0) goto LAB_00430670;
                                                puVar39 = ca_usage;
                                                do {
                                                  puVar39 = (undefined1 *)((int)puVar39 + 4);
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar10,"%s");
                                                } while (*(int *)puVar39 != 0);
                                                local_428 = 0;
                                                goto LAB_00430674;
                                              }
                                              if ((local_420 == 0) &&
                                                 (local_420 = (*(code *)PTR_sk_new_null_006a6fa4)(),
                                                 local_420 == 0)) {
                                                pcVar38 = *ppcVar49;
                                                goto LAB_00430988;
                                              }
                                              ppcVar22 = ppcVar49 + 1;
                                              iVar14 = (*(code *)PTR_sk_push_006a6fa8)
                                                                 (local_420,ppcVar49[1]);
                                              if (iVar14 == 0) {
                                                pcVar38 = ppcVar49[1];
                                                goto LAB_00430988;
                                              }
                                            }
                                            else {
                                              iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                 (pcVar38,"-notext");
                                              if (iVar14 == 0) {
                                                bVar8 = true;
                                              }
                                              else {
                                                iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                   (pcVar38,"-batch");
                                                if (iVar14 == 0) {
                                                  local_3ec = 1;
                                                }
                                                else {
                                                  iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                     (pcVar38,"-preserveDN");
                                                  if (iVar14 == 0) {
                                                    preserve = 1;
                                                  }
                                                  else {
                                                    iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar38,"-noemailDN");
                                                    if (iVar14 == 0) {
                                                      bVar4 = false;
                                                    }
                                                    else {
                                                      iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (pcVar38,"-gencrl");
                                                      if (iVar14 == 0) {
                                                        bVar6 = true;
                                                      }
                                                      else {
                                                        iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (pcVar38,"-msie_hack");
                                                        if (iVar14 == 0) {
                                                          msie_hack = 1;
                                                        }
                                                        else {
                                                          iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (pcVar38,"-crldays");
                                                          if (iVar14 == 0) {
                                                            param_1 = param_1 + -1;
                                                            if (param_1 == 0) goto LAB_00430988;
                                                            local_370 = (*(code *)
                                                  PTR_strtol_006a9958)(ppcVar49[1],0,10);
                                                  ppcVar22 = ppcVar49 + 1;
                                                  }
                                                  else {
                                                    iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar38,"-crlhours");
                                                    if (iVar14 == 0) {
                                                      param_1 = param_1 + -1;
                                                      if (param_1 == 0) goto LAB_00430988;
                                                      local_36c = (*(code *)PTR_strtol_006a9958)
                                                                            (ppcVar49[1],0,10);
                                                      ppcVar22 = ppcVar49 + 1;
                                                    }
                                                    else {
                                                      iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (pcVar38,"-crlsec");
                                                      if (iVar14 == 0) {
                                                        param_1 = param_1 + -1;
                                                        if (param_1 == 0) goto LAB_00430988;
                                                        local_3b8 = (*(code *)PTR_strtol_006a9958)
                                                                              (ppcVar49[1],0,10);
                                                        ppcVar22 = ppcVar49 + 1;
                                                      }
                                                      else {
                                                        iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (pcVar38,"-infiles");
                                                        if (iVar14 == 0) {
                                                          param_1 = param_1 + -1;
                                                          ppcVar49 = ppcVar49 + 1;
                                                          bVar3 = true;
                                                          break;
                                                        }
                                                        iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (pcVar38,"-ss_cert");
                                                        if (iVar14 == 0) {
                                                          param_1 = param_1 + -1;
                                                          if (param_1 == 0) goto LAB_00430988;
                                                          local_3bc = ppcVar49[1];
                                                          bVar3 = true;
                                                          ppcVar22 = ppcVar49 + 1;
                                                        }
                                                        else {
                                                          iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (pcVar38,"-spkac");
                                                          if (iVar14 == 0) {
                                                            param_1 = param_1 + -1;
                                                            if (param_1 == 0) goto LAB_00430988;
                                                            local_3e8 = ppcVar49[1];
                                                            bVar3 = true;
                                                            ppcVar22 = ppcVar49 + 1;
                                                          }
                                                          else {
                                                            iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (pcVar38,"-revoke");
                                                            if (iVar14 == 0) {
                                                              param_1 = param_1 + -1;
                                                              if (param_1 == 0) goto LAB_00430988;
                                                              local_3dc = ppcVar49[1];
                                                              bVar9 = true;
                                                              ppcVar22 = ppcVar49 + 1;
                                                            }
                                                            else {
                                                              iVar14 = (*(code *)PTR_strcmp_006a9b18
                                                                       )(pcVar38,"-extensions");
                                                              if (iVar14 == 0) {
                                                                param_1 = param_1 + -1;
                                                                if (param_1 == 0) goto LAB_00430988;
                                                                local_414 = ppcVar49[1];
                                                                ppcVar22 = ppcVar49 + 1;
                                                              }
                                                              else {
                                                                iVar14 = (*(code *)
                                                  PTR_strcmp_006a9b18)(pcVar38,"-extfile");
                                                  if (iVar14 == 0) {
                                                    param_1 = param_1 + -1;
                                                    if (param_1 == 0) goto LAB_00430988;
                                                    local_3e0 = ppcVar49[1];
                                                    ppcVar22 = ppcVar49 + 1;
                                                  }
                                                  else {
                                                    iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar38,"-status");
                                                    if (iVar14 == 0) {
                                                      param_1 = param_1 + -1;
                                                      if (param_1 == 0) goto LAB_00430988;
                                                      local_3e4 = ppcVar49[1];
                                                      ppcVar22 = ppcVar49 + 1;
                                                    }
                                                    else {
                                                      iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (pcVar38,"-updatedb");
                                                      if (iVar14 == 0) {
                                                        bVar7 = true;
                                                      }
                                                      else {
                                                        iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (pcVar38,"-crlexts");
                                                        if (iVar14 == 0) {
                                                          param_1 = param_1 + -1;
                                                          if (param_1 == 0) goto LAB_00430988;
                                                          local_3f0 = ppcVar49[1];
                                                          ppcVar22 = ppcVar49 + 1;
                                                        }
                                                        else {
                                                          iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (pcVar38,"-crl_reason")
                                                          ;
                                                          if (iVar14 == 0) {
                                                            param_1 = param_1 + -1;
                                                            if (param_1 == 0) goto LAB_00430988;
                                                            local_3d4 = ppcVar49[1];
                                                            local_3d8 = 1;
                                                            ppcVar22 = ppcVar49 + 1;
                                                          }
                                                          else {
                                                            iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (pcVar38,"-crl_hold")
                                                            ;
                                                            if (iVar14 == 0) {
                                                              param_1 = param_1 + -1;
                                                              if (param_1 == 0) goto LAB_00430988;
                                                              local_3d4 = ppcVar49[1];
                                                              local_3d8 = 2;
                                                              ppcVar22 = ppcVar49 + 1;
                                                            }
                                                            else {
                                                              iVar14 = (*(code *)PTR_strcmp_006a9b18
                                                                       )(pcVar38,"-crl_compromise");
                                                              if (iVar14 == 0) {
                                                                param_1 = param_1 + -1;
                                                                if (param_1 == 0) goto LAB_00430988;
                                                                local_3d4 = ppcVar49[1];
                                                                local_3d8 = 3;
                                                                ppcVar22 = ppcVar49 + 1;
                                                              }
                                                              else {
                                                                iVar14 = (*(code *)
                                                  PTR_strcmp_006a9b18)(pcVar38,"-crl_CA_compromise")
                                                  ;
                                                  if (iVar14 == 0) {
                                                    param_1 = param_1 + -1;
                                                    if (param_1 == 0) goto LAB_00430988;
                                                    local_3d4 = ppcVar49[1];
                                                    local_3d8 = 4;
                                                    ppcVar22 = ppcVar49 + 1;
                                                  }
                                                  else {
                                                    iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (pcVar38,"-engine");
                                                    if ((iVar14 != 0) ||
                                                       (param_1 = param_1 + -1, param_1 == 0))
                                                    goto LAB_00430988;
                                                    local_438 = ppcVar49[1];
                                                    ppcVar22 = ppcVar49 + 1;
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
      param_1 = param_1 + -1;
      ppcVar49 = ppcVar22 + 1;
    } while (param_1 != 0);
  }
LAB_004305cc:
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  if (((pcVar48 == (char *)0x0) &&
      (pcVar48 = (char *)(*(code *)PTR_getenv_006a9a60)("OPENSSL_CONF"), pcVar48 == (char *)0x0)) &&
     (pcVar48 = (char *)(*(code *)PTR_getenv_006a9a60)("SSLEAY_CONF"), pcVar48 == (char *)0x0)) {
    uVar15 = (*(code *)PTR_X509_get_default_cert_area_006a7064)();
    iVar14 = (*(code *)PTR_strlen_006a9a24)(uVar15);
    iVar14 = iVar14 + 0xd;
    pcVar38 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar14,&DAT_0063526c,0x232);
    if (pcVar38 == (char *)0x0) {
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"Out of memory\n");
      local_428 = 0;
      goto LAB_00430680;
    }
    (*(code *)PTR_BUF_strlcpy_006a6f64)(pcVar38,uVar15,iVar14);
    (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar38,&DAT_0063b2b4,iVar14);
    (*(code *)PTR_BUF_strlcat_006a6f68)(pcVar38,"openssl.cnf",iVar14);
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar10,"Using configuration from %s\n",pcVar38);
    conf = (*(code *)PTR_NCONF_new_006a6e58)(0);
    iVar14 = (*(code *)PTR_NCONF_load_006a6e5c)(conf,pcVar38,&local_368);
    pcVar48 = pcVar38;
    if (iVar14 < 1) goto LAB_00430638;
    (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar38);
  }
  else {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar10,"Using configuration from %s\n",pcVar48);
    conf = (*(code *)PTR_NCONF_new_006a6e58)(0);
    iVar14 = (*(code *)PTR_NCONF_load_006a6e5c)(conf,pcVar48,&local_368);
    if (iVar14 < 1) {
      pcVar38 = (char *)0x0;
      goto LAB_00430638;
    }
  }
  puVar25 = PTR_bio_err_006a6e3c;
  iVar14 = (*(code *)PTR_load_config_006a6e64)(*(undefined4 *)puVar10,conf);
  if (iVar14 == 0) goto LAB_00430670;
  uVar15 = (*(code *)PTR_setup_engine_006a6ec4)(*(undefined4 *)puVar25,local_438,0);
  if ((section == (char *)0x0) &&
     (section = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,"ca","default_ca"),
     section == (char *)0x0)) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar25,"variable lookup failed for %s::%s\n","ca","default_ca");
    goto LAB_00430670;
  }
  if (conf != 0) {
    iVar14 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,0,"oid_file");
    if ((iVar14 == 0) || (iVar14 = (*(code *)PTR_BIO_new_file_006a6eac)(iVar14,"r"), iVar14 == 0)) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
    else {
      (*(code *)PTR_OBJ_create_objects_006a6eb0)(iVar14);
      (*(code *)PTR_BIO_free_006a6e70)(iVar14);
    }
    iVar14 = (*(code *)PTR_add_oid_section_006a6e60)(*(undefined4 *)puVar10,conf);
    if (iVar14 == 0) {
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
      goto LAB_00430670;
    }
  }
  local_428 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,"ca","RANDFILE");
  if (local_428 == 0) {
    (*(code *)PTR_ERR_clear_error_006a6ee0)();
  }
  (*(code *)PTR_app_RAND_load_file_006a6ecc)(local_428,*(undefined4 *)puVar10,0);
  iVar14 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"string_mask");
  if (iVar14 == 0) {
    (*(code *)PTR_ERR_clear_error_006a6ee0)();
  }
  else {
    iVar16 = (*(code *)PTR_ASN1_STRING_set_default_mask_asc_006a6ec0)(iVar14);
    if (iVar16 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"Invalid global string mask setting %s\n",
                 iVar14);
      goto LAB_00430674;
    }
  }
  if (local_424 == 0x1000) {
LAB_00430ce4:
    local_424 = 0x1000;
  }
  else {
    pcVar48 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,&DAT_00633198);
    if (pcVar48 == (char *)0x0) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
    else if ((((*pcVar48 == 'y') && (pcVar48[1] == 'e')) && (pcVar48[2] == 's')) &&
            (pcVar48[3] == '\0')) goto LAB_00430ce4;
  }
  local_34c = 1;
  iVar14 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"unique_subject");
  if (iVar14 == 0) {
    (*(code *)PTR_ERR_clear_error_006a6ee0)();
  }
  else {
    local_34c = (*(code *)PTR_parse_yesno_006a7068)(iVar14,1);
  }
  uVar17 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  local_42c = (*(code *)PTR_BIO_new_006a6ea4)(uVar17);
  uVar17 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  local_430 = (*(code *)PTR_BIO_new_006a6ea4)(uVar17);
  uVar17 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  local_438 = (char *)(*(code *)PTR_BIO_new_006a6ea4)(uVar17);
  uVar17 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  local_434 = (*(code *)PTR_BIO_new_006a6ea4)(uVar17);
  if (((local_42c == 0) || (local_430 == 0)) || ((local_438 == (char *)0x0 || (local_434 == 0)))) {
    pcVar38 = (char *)0x0;
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar10);
    goto LAB_00430690;
  }
  if (local_3e4 != (char *)0x0) {
    iVar45 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"database");
    if (iVar45 != 0) {
      pcVar38 = (char *)(*(code *)PTR_load_index_006a706c)(iVar45,&local_34c);
      if (pcVar38 == (char *)0x0) goto LAB_00430690;
      iVar45 = (*(code *)PTR_index_index_006a7070)(pcVar38);
      if (iVar45 == 0) goto LAB_00430690;
      puVar40 = local_32c;
      local_32c[0] = 0;
      local_32c[1] = 0;
      local_32c[2] = 0;
      local_320 = (char *)0x0;
      local_31c = 0;
      local_318 = 0;
      iVar45 = (*(code *)PTR_strlen_006a9a24)(local_3e4);
      pcVar48 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar45 + 2,&DAT_0063526c,0x98f);
      local_320 = pcVar48;
      if (pcVar48 == (char *)0x0) {
        iVar45 = -1;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"Malloc failure\n");
      }
      else {
        uVar18 = (*(code *)PTR_strlen_006a9a24)(local_3e4);
        puVar25 = PTR_strlen_006a9a24;
        if ((uVar18 & 1) == 0) {
          (*(code *)PTR_memcpy_006a9aec)(pcVar48,local_3e4,uVar18);
          iVar45 = (*(code *)PTR_strlen_006a9a24)(local_3e4);
          local_320[iVar45] = '\0';
        }
        else {
          *pcVar48 = '0';
          uVar15 = (*(code *)puVar25)(local_3e4);
          (*(code *)PTR_memcpy_006a9aec)(local_320 + 1,local_3e4,uVar15);
          iVar45 = (*(code *)PTR_strlen_006a9a24)(local_3e4);
          local_320[iVar45 + 1] = '\0';
        }
        pcVar48 = local_320;
        uVar18 = (uint)*local_320;
        if (uVar18 != 0) {
          piVar19 = (int *)(*(code *)PTR___ctype_toupper_loc_006a9b28)();
          iVar45 = 0;
          do {
            iVar45 = iVar45 + 1;
            *pcVar48 = (char)*(undefined4 *)(*piVar19 + (uVar18 & 0xff) * 4);
            pcVar48 = local_320 + iVar45;
            uVar18 = (uint)*pcVar48;
          } while (uVar18 != 0);
        }
        ppcVar49 = (char **)(*(code *)PTR_TXT_DB_get_by_index_006a7020)
                                      (*(undefined4 *)(pcVar38 + 4),3,puVar40);
        if (ppcVar49 == (char **)0x0) {
          iVar45 = -1;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar10,"Serial %s not present in db.\n",local_320);
        }
        else {
          cVar1 = **ppcVar49;
          if (cVar1 == 'V') {
            iVar45 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar10,"%s=Valid (%c)\n",local_320,0x56);
          }
          else if (cVar1 == 'R') {
            iVar45 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar10,"%s=Revoked (%c)\n",local_320,0x52);
          }
          else if (cVar1 == 'E') {
            iVar45 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar10,"%s=Expired (%c)\n",local_320,0x45);
          }
          else if (cVar1 == 'S') {
            iVar45 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar10,"%s=Suspended (%c)\n",local_320,0x53);
          }
          else {
            iVar45 = -1;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar10,"%s=Unknown (%c).\n",local_320);
          }
        }
      }
      do {
        if (*puVar40 != 0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
        }
        puVar40 = puVar40 + 1;
      } while (puVar40 != auStack_314);
      if (iVar45 == 1) goto LAB_00430690;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar10,"Error verifying serial %s!\n",local_3e4);
      goto LAB_00430690;
    }
    pcVar48 = "database";
LAB_004316ec:
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar10,"variable lookup failed for %s::%s\n",section,pcVar48);
    pcVar38 = (char *)0x0;
    goto LAB_00430690;
  }
  if ((local_3c8 == (char *)0x0) &&
     (local_3c8 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"private_key"),
     local_3c8 == (char *)0x0)) {
    pcVar48 = "private_key";
    goto LAB_004316ec;
  }
  if (local_374 == (char *)0x0) {
    iVar14 = (*(code *)PTR_app_passwd_006a6e54)(*(undefined4 *)puVar10,local_3b4,0,&local_374,0);
    if (iVar14 == 0) {
      iVar16 = 0;
      iVar41 = 0;
      pcVar38 = (char *)0x0;
      iVar14 = 0;
      iVar42 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"Error getting password\n");
      iVar45 = 1;
      local_444 = 0;
      bVar5 = true;
      goto LAB_004306ac;
    }
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  local_444 = (*(code *)PTR_load_key_006a6ec8)
                        (*(undefined4 *)puVar10,local_3c8,local_3a8,0,local_374,uVar15,
                         "CA private key");
  pcVar48 = local_374;
  if (local_374 != (char *)0x0) {
    uVar17 = (*(code *)PTR_strlen_006a9a24)(local_374);
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(pcVar48,uVar17);
  }
  if (local_444 == 0) {
LAB_004318d8:
    iVar16 = 0;
    iVar41 = 0;
    pcVar38 = (char *)0x0;
    iVar14 = 0;
    iVar42 = 0;
    iVar45 = 1;
    goto LAB_004306ac;
  }
  if ((((local_3d0 == 0) || (local_3e8 != (char *)0x0)) || (local_3bc != (char *)0x0)) || (bVar6)) {
    if ((local_3c4 == (char *)0x0) &&
       (local_3c4 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"certificate"),
       local_3c4 == (char *)0x0)) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar10,"variable lookup failed for %s::%s\n",section,"certificate")
      ;
      goto LAB_004318d8;
    }
    iVar14 = (*(code *)PTR_load_cert_006a7078)
                       (*(undefined4 *)puVar10,local_3c4,3,0,uVar15,"CA certificate");
    if (iVar14 != 0) {
      iVar16 = (*(code *)PTR_X509_check_private_key_006a707c)(iVar14,local_444);
      if (iVar16 != 0) {
        local_3b4 = (char *)iVar14;
        if (local_3d0 != 0) goto LAB_004316d4;
        goto LAB_004313f4;
      }
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,
                 "CA certificate and CA private key do not match\n");
    }
  }
  else {
    iVar14 = 0;
LAB_004316d4:
    local_3b4 = (char *)0x0;
LAB_004313f4:
    pbVar20 = (byte *)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,"ca","preserve");
    if (pbVar20 == (byte *)0x0) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
    else if ((*pbVar20 & 0xdf) == 0x59) {
      preserve = 1;
    }
    pbVar20 = (byte *)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,"ca","msie_hack");
    if (pbVar20 == (byte *)0x0) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
    else if ((*pbVar20 & 0xdf) == 0x59) {
      msie_hack = 1;
    }
    iVar16 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"name_opt");
    if (iVar16 == 0) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
      local_3c8 = (char *)0x1;
    }
    else {
      iVar42 = (*(code *)PTR_set_name_ex_006a6fac)(&local_35c,iVar16);
      if (iVar42 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar10,"Invalid name options: \"%s\"\n",iVar16);
        goto LAB_0043181c;
      }
      local_3c8 = (char *)0x0;
    }
    iVar16 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"cert_opt");
    if (iVar16 == 0) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
    else {
      iVar42 = (*(code *)PTR_set_cert_ex_006a6fb0)(&local_358,iVar16);
      if (iVar42 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar10,"Invalid certificate options: \"%s\"\n",iVar16);
        goto LAB_0043181c;
      }
      local_3c8 = (char *)0x0;
    }
    iVar16 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"copy_extensions");
    if (iVar16 == 0) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
    else {
      iVar42 = (*(code *)PTR_set_ext_copy_006a7080)(&local_354,iVar16);
      if (iVar42 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar10,"Invalid extension copy option: \"%s\"\n",iVar16);
        goto LAB_0043181c;
      }
    }
    if ((local_404 == (char *)0x0) && (bVar3)) {
      local_404 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"new_certs_dir");
      if (local_404 == (char *)0x0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar10,
                   "there needs to be defined a directory for new certificate to be placed in\n");
      }
      else {
        iVar16 = (*(code *)PTR_access_006a99cc)(local_404,7);
        if (iVar16 == 0) {
          iVar16 = (*(code *)PTR_app_isdir_006a7088)(local_404);
          if (0 < iVar16) goto LAB_00431550;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar10,"%s need to be a directory\n",local_404);
          (*(code *)PTR_perror_006a9a80)(local_404);
        }
        else {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar10,"I am unable to access the %s directory\n",local_404);
          (*(code *)PTR_perror_006a9a80)(local_404);
        }
      }
    }
    else {
LAB_00431550:
      iVar21 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"database");
      if (iVar21 != 0) {
        pcVar38 = (char *)(*(code *)PTR_load_index_006a706c)(iVar21,&local_34c);
        if (pcVar38 != (char *)0x0) {
          for (iVar16 = 0;
              iVar42 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*(int *)(pcVar38 + 4) + 4)),
              iVar16 < iVar42; iVar16 = iVar16 + 1) {
            ppcVar22 = (char **)(*(code *)PTR_sk_value_006a6e24)
                                          (*(undefined4 *)(*(int *)(pcVar38 + 4) + 4),iVar16);
            if (**ppcVar22 == 'R') {
              iVar42 = make_revoked(0,ppcVar22[2]);
              if (iVar42 == 0) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar10," in entry %d\n",iVar16 + 1);
                goto LAB_00431690;
              }
            }
            else if (*ppcVar22[2] != '\0') {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar10,
                         "entry %d: not revoked yet, but has a revocation date\n",iVar16 + 1);
              goto LAB_00431690;
            }
            iVar42 = (*(code *)PTR_ASN1_TIME_set_string_006a7084)(0,ppcVar22[1]);
            if (iVar42 == 0) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar10,"entry %d: invalid expiry date\n",iVar16 + 1);
              goto LAB_00431690;
            }
            pcVar44 = ppcVar22[3];
            uVar18 = (*(code *)PTR_strlen_006a9a24)(pcVar44);
            pcVar48 = pcVar44;
            if (*pcVar44 == '-') {
              uVar18 = uVar18 - 1;
              pcVar48 = pcVar44 + 1;
            }
            if (((uVar18 & 1) != 0) || ((int)uVar18 < 2)) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar10,"entry %d: bad serial number length (%d)\n",
                         iVar16 + 1,uVar18);
              goto LAB_00431690;
            }
            while( true ) {
              uVar18 = (uint)*pcVar48;
              if (uVar18 == 0) break;
              if ((9 < (uVar18 & 0xff) - 0x30) && (5 < (uVar18 & 0xdf) - 0x41)) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar10,
                           "entry %d: bad serial number characters, char pos %ld, char is \'%c\'\n",
                           iVar16 + 1,(int)pcVar48 - (int)pcVar44,uVar18);
                goto LAB_00431690;
              }
              pcVar48 = pcVar48 + 1;
            }
          }
          if (iVar45 != 0) {
            (*(code *)PTR_BIO_ctrl_006a6e18)(local_430,0x6a,0x10,*(undefined4 *)PTR_stdout_006a99c8)
            ;
            (*(code *)PTR_TXT_DB_write_006a708c)(local_430,*(undefined4 *)(pcVar38 + 4));
            uVar43 = *(undefined4 *)puVar10;
            uVar17 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*(int *)(pcVar38 + 4) + 4));
            (*(code *)PTR_BIO_printf_006a6e38)
                      (uVar43,"%d entries loaded from the database\n",uVar17);
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"generating index\n");
          }
          iVar16 = (*(code *)PTR_index_index_006a7070)(pcVar38);
          if (iVar16 != 0) {
            if (!bVar7) {
LAB_00431ddc:
              if (local_3e0 != (char *)0x0) {
                extconf = (*(code *)PTR_NCONF_new_006a6e58)(0);
                iVar16 = (*(code *)PTR_NCONF_load_006a6e5c)(extconf,local_3e0,&local_368);
                if (0 < iVar16) {
                  if (iVar45 != 0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,"Successfully loaded extensions file %s\n",
                               local_3e0);
                  }
                  if (local_414 == (char *)0x0) {
                    pcVar48 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                                (extconf,"default","extensions");
                    local_414 = "default";
                    if (pcVar48 != (char *)0x0) {
                      local_414 = pcVar48;
                    }
                  }
                  goto LAB_00431e7c;
                }
                uVar15 = *(undefined4 *)puVar10;
                if (0 < local_368) {
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (uVar15,"ERROR: on line %ld of config file \'%s\'\n",local_368,local_3e0
                            );
                  goto LAB_00432228;
                }
                pcVar48 = "ERROR: loading the config file \'%s\'\n";
                local_400 = local_3e0;
LAB_00432ea0:
                (*(code *)PTR_BIO_printf_006a6e38)(uVar15,pcVar48,local_400);
                goto LAB_00432228;
              }
LAB_00431e7c:
              if ((bVar3) || (bVar6)) {
                if (local_3c0 == (char *)0x0) {
                  (*(code *)PTR_BIO_ctrl_006a6e18)
                            (local_438,0x6a,0x10,*(undefined4 *)PTR_stdout_006a99c8);
                }
                else {
                  iVar16 = (*(code *)PTR_BIO_ctrl_006a6e18)(local_438,0x6c,5,local_3c0);
                  if (iVar16 < 1) {
                    (*(code *)PTR_perror_006a9a80)(local_3c0);
                    goto LAB_00432228;
                  }
                }
              }
              if ((local_3f4 == (char *)0x0) &&
                 (local_3f4 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                                (conf,section,"default_md"),
                 local_3f4 == (char *)0x0)) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar10,"variable lookup failed for %s::%s\n",section,
                           "default_md");
                goto LAB_00432228;
              }
              iVar16 = (*(code *)PTR_strcmp_006a9b18)(local_3f4,"default");
              if (iVar16 == 0) {
                iVar16 = (*(code *)PTR_EVP_PKEY_get_default_digest_nid_006a7098)
                                   (local_444,local_348);
                if (iVar16 < 1) {
                  (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar10,"no default digest\n");
                  goto LAB_00432228;
                }
                local_3f4 = (char *)(*(code *)PTR_OBJ_nid2sn_006a709c)(local_348[0]);
              }
              puVar23 = (undefined4 *)(*(code *)PTR_EVP_get_digestbyname_006a6f2c)(local_3f4);
              if (puVar23 == (undefined4 *)0x0) {
                uVar15 = *(undefined4 *)puVar10;
                pcVar48 = "%s is an unsupported message digest type\n";
                local_400 = local_3f4;
                goto LAB_00432ea0;
              }
              iVar16 = 0;
              if (!bVar3) goto LAB_00433214;
              if ((bVar4 != false) &&
                 (pbVar20 = (byte *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                              (conf,section,"email_in_dn"), pbVar20 != (byte *)0x0))
              {
                iVar16 = 0x6e - (uint)*pbVar20;
                if ((iVar16 == 0) && (iVar16 = 0x6f - (uint)pbVar20[1], iVar16 == 0)) {
                  iVar16 = -(uint)pbVar20[2];
                }
                bVar4 = iVar16 != 0;
              }
              if (iVar45 == 0) {
                if ((local_400 == (char *)0x0) &&
                   (local_400 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                                  (conf,section,"policy"), local_400 == (char *)0x0)
                   ) {
LAB_00433acc:
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar10,"variable lookup failed for %s::%s\n",section,
                             "policy");
                  goto LAB_00432228;
                }
              }
              else {
                uVar43 = *(undefined4 *)puVar10;
                uVar17 = (*(code *)PTR_OBJ_nid2ln_006a711c)(*puVar23);
                (*(code *)PTR_BIO_printf_006a6e38)(uVar43,"message digest is %s\n",uVar17);
                if ((local_400 == (char *)0x0) &&
                   (local_400 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                                  (conf,section,"policy"), local_400 == (char *)0x0)
                   ) goto LAB_00433acc;
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar10,"policy is %s\n",local_400);
              }
              iVar42 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"serial");
              if (iVar42 == 0) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar10,"variable lookup failed for %s::%s\n",section,
                           "serial");
              }
              else {
                if (extconf == 0) {
                  if ((local_414 == (char *)0x0) &&
                     (local_414 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                                    (conf,section,"x509_extensions"),
                     local_414 == (char *)0x0)) {
                    (*(code *)PTR_ERR_clear_error_006a6ee0)();
                  }
                  else {
                    (*(code *)PTR_X509V3_set_ctx_006a6eb4)(local_348,0,0,0,0,1);
                    (*(code *)PTR_X509V3_set_nconf_006a6eb8)(local_348,conf);
                    iVar16 = (*(code *)PTR_X509V3_EXT_add_nconf_006a6ebc)
                                       (conf,local_348,local_414,0);
                    if (iVar16 == 0) {
                      uVar15 = *(undefined4 *)puVar10;
                      pcVar48 = "Error Loading extension section %s\n";
                      local_400 = local_414;
                      goto LAB_00432ea0;
                    }
                  }
                }
                if ((local_40c == (char *)0x0) &&
                   (local_40c = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                                  (conf,section,"default_startdate"),
                   local_40c == (char *)0x0)) {
                  (*(code *)PTR_ERR_clear_error_006a6ee0)();
                  local_40c = "today";
                }
                else {
                  iVar16 = (*(code *)PTR_ASN1_TIME_set_string_006a7084)(0,local_40c);
                  if (iVar16 == 0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,
                               "start date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n"
                              );
                    goto LAB_00432228;
                  }
                }
                if ((local_408 == (char *)0x0) &&
                   (local_408 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                                  (conf,section,"default_enddate"),
                   local_408 == (char *)0x0)) {
                  (*(code *)PTR_ERR_clear_error_006a6ee0)();
                }
                else {
                  iVar16 = (*(code *)PTR_ASN1_TIME_set_string_006a7084)(0,local_408);
                  if (iVar16 == 0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,
                               "end date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n"
                              );
                    goto LAB_00432228;
                  }
                }
                if (local_360 == (char *)0x0) {
                  iVar16 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                                     (conf,section,"default_days",&local_360);
                  if (iVar16 == 0) {
                    local_360 = (char *)0x0;
                    pcVar48 = local_408;
                  }
                  else {
                    pcVar48 = local_360;
                    if (local_408 != (char *)0x0) goto LAB_00431fe8;
                  }
                  if (pcVar48 == (char *)0x0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,"cannot lookup how many days to certify for\n"
                              );
                    goto LAB_00432228;
                  }
                }
LAB_00431fe8:
                local_364 = (*(code *)PTR_load_serial_006a70a0)(iVar42,local_418,0);
                if (local_364 != 0) {
                  if (iVar45 != 0) {
                    if (*(int *)(local_364 + 4) == 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,"next serial number is 00\n");
                    }
                    else {
                      iVar16 = (*(code *)PTR_BN_bn2hex_006a7018)(local_364);
                      if (iVar16 == 0) goto LAB_00432228;
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,"next serial number is %s\n",iVar16);
                      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar16);
                    }
                  }
                  iVar24 = (*(code *)PTR_NCONF_get_section_006a6ed4)(conf,local_400);
                  if (iVar24 == 0) {
                    uVar15 = *(undefined4 *)puVar10;
                    pcVar48 = "unable to find \'section\' for %s\n";
                    goto LAB_00432ea0;
                  }
                  iVar16 = (*(code *)PTR_sk_new_null_006a6fa4)();
                  uVar12 = local_354;
                  uVar43 = local_358;
                  uVar17 = local_35c;
                  pcVar48 = local_360;
                  iVar33 = local_364;
                  iVar41 = conf;
                  if (iVar16 == 0) {
                    uVar15 = *(undefined4 *)puVar10;
                    pcVar48 = "Memory allocation failure\n";
LAB_00432b74:
                    iVar41 = 0;
                    (*(code *)PTR_BIO_printf_006a6e38)(uVar15,pcVar48);
                    iVar42 = 0;
                    iVar45 = 1;
                    goto LAB_004306ac;
                  }
                  if (local_3e8 == (char *)0x0) {
                    bVar3 = false;
                    iVar41 = 0;
                    local_3ac = 2;
                    local_3e8 = (char *)0x2;
                    local_400 = (char *)0x1;
                    local_418 = 1;
                    iVar33 = 0;
                    goto LAB_00432538;
                  }
                  puVar25 = (undefined *)(*(code *)PTR_CONF_load_006a70a4)(0,local_3e8,local_348);
                  if (puVar25 == (undefined *)0x0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,"error on line %ld of %s\n",local_348[0],
                               local_3e8);
                    puVar25 = *(undefined **)puVar10;
                    pcVar50 = (code *)PTR_ERR_print_errors_006a6e40;
LAB_00432e40:
                    iVar41 = 0;
                    (*pcVar50)(puVar25);
LAB_00432478:
                    iVar42 = 0;
                  }
                  else {
                    uVar26 = (*(code *)PTR_CONF_get_section_006a70a8)(puVar25,"default");
                    iVar27 = (*(code *)PTR_sk_num_006a6e2c)(uVar26);
                    if (iVar27 == 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,"no name/value pairs found in %s\n",
                                 local_3e8);
                      (*(code *)PTR_CONF_free_006a70b4)(puVar25);
                      pcVar50 = (code *)PTR_CONF_free_006a70b4;
                      goto LAB_00432e40;
                    }
                    piVar19 = (int *)(*(code *)PTR_X509_REQ_new_006a6ed0)();
                    if (piVar19 == (int *)0x0) {
                      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar10);
                      pcVar50 = (code *)PTR_CONF_free_006a70b4;
                      goto LAB_00432e40;
                    }
                    iVar27 = 0;
                    local_400 = (char *)0x0;
                    uVar28 = *(undefined4 *)(*piVar19 + 0x10);
                    for (; iVar29 = (*(code *)PTR_sk_num_006a6e2c)(uVar26),
                        puVar47 = PTR_bio_err_006a6e3c, (int)local_400 < iVar29;
                        local_400 = (char *)((int)local_400 + 1)) {
                      iVar29 = (*(code *)PTR_sk_value_006a6e24)(uVar26,local_400);
                      pbVar34 = *(byte **)(iVar29 + 4);
                      bVar2 = *pbVar34;
                      pbVar20 = pbVar34;
                      while (bVar2 != 0) {
                        if ((bVar2 == 0x3a) || ((bVar2 & 0xfd) == 0x2c)) {
                          if (*(byte *)((int)pbVar20 + 1) != 0) {
                            pbVar34 = (byte *)((int)pbVar20 + 1);
                          }
                          break;
                        }
                        pbVar20 = (byte *)((int)pbVar20 + 1);
                        bVar2 = *pbVar20;
                      }
                      uVar37 = *(undefined4 *)(iVar29 + 8);
                      iVar30 = (*(code *)PTR_OBJ_txt2nid_006a6f5c)(pbVar34);
                      if (iVar30 == 0) {
                        iVar30 = (*(code *)PTR_strcmp_006a9b18)(pbVar34,"SPKAC");
                        if ((iVar30 == 0) &&
                           (iVar27 = (*(code *)PTR_NETSCAPE_SPKI_b64_decode_006a70d4)
                                               (*(undefined4 *)(iVar29 + 8),0xffffffff), iVar27 == 0
                           )) {
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)puVar10,
                                     "unable to load Netscape SPKAC structure\n");
                          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar10);
                          iVar33 = -1;
                          goto LAB_004323f4;
                        }
                      }
                      else {
                        iVar29 = (*(code *)PTR_X509_NAME_add_entry_by_NID_006a6f78)
                                           (uVar28,iVar30,local_424,uVar37,0xffffffff,0xffffffff,0);
                        if (iVar29 == 0) {
                          iVar33 = -1;
                          goto LAB_004323f4;
                        }
                      }
                    }
                    if (iVar27 == 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,"Netscape SPKAC structure not found in %s\n"
                                 ,local_3e8);
                      iVar33 = -1;
                    }
                    else {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,
                                 "Check that the SPKAC request matches the signature\n");
                      iVar29 = (*(code *)PTR_NETSCAPE_SPKI_get_pubkey_006a70ac)(iVar27);
                      if (iVar29 == 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar47,"error unpacking SPKAC public key\n");
                        iVar33 = -1;
                      }
                      else {
                        iVar30 = (*(code *)PTR_NETSCAPE_SPKI_verify_006a70b0)(iVar27,iVar29);
                        if (iVar30 < 1) {
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)puVar47,
                                     "signature verification failed on SPKAC public key\n");
                          iVar33 = -1;
                        }
                        else {
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)puVar47,"Signature ok\n");
                          (*(code *)PTR_X509_REQ_set_pubkey_006a6f30)(piVar19,iVar29);
                          (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar29);
                          iVar33 = do_body(&local_350,local_444,iVar14,puVar23,local_420,iVar24,
                                           pcVar38,iVar33,local_440,local_424,local_410,bVar4,
                                           local_40c,local_408,pcVar48,1,iVar45,piVar19,local_414,
                                           iVar41,uVar43,uVar17,local_3c8,uVar12,0);
                        }
                      }
                    }
LAB_004323f4:
                    (*(code *)PTR_X509_REQ_free_006a6e8c)(piVar19);
                    (*(code *)PTR_CONF_free_006a70b4)(puVar25);
                    if (iVar27 != 0) {
                      (*(code *)PTR_NETSCAPE_SPKI_free_006a70b8)(iVar27);
                    }
                    iVar41 = 0;
                    if (iVar33 < 0) goto LAB_00432478;
                    if (iVar33 != 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"\n");
                      iVar41 = (*(code *)PTR_BN_add_word_006a70bc)(local_364,1);
                      if (iVar41 == 0) goto LAB_00432474;
                      iVar41 = (*(code *)PTR_sk_push_006a6fa8)(iVar16,local_350);
                      if (iVar41 != 0) {
                        iVar41 = 1;
                        local_3ac = 3;
                        local_3e8 = (char *)0x3;
                        if (local_3c0 != (char *)0x0) {
                          local_3ec = 1;
                        }
                        local_400 = (char *)0x2;
                        local_418 = 2;
                        bVar3 = local_3c0 != (char *)0x0;
                        iVar33 = 1;
                        goto LAB_00432538;
                      }
LAB_00432b60:
                      pcVar48 = "Memory allocation failure\n";
                      uVar15 = *(undefined4 *)PTR_bio_err_006a6e3c;
                      goto LAB_00432b74;
                    }
                    bVar3 = false;
                    iVar41 = 0;
                    local_3ac = 2;
                    local_3e8 = (char *)0x3;
                    local_400 = (char *)0x1;
                    local_418 = 2;
                    iVar33 = 1;
LAB_00432538:
                    uVar12 = local_354;
                    uVar43 = local_358;
                    uVar17 = local_35c;
                    pcVar48 = local_360;
                    iVar30 = local_364;
                    iVar29 = (int)local_400;
                    iVar27 = conf;
                    iVar31 = local_418;
                    if (local_3bc == (char *)0x0) goto LAB_004326d0;
                    iVar33 = (*(code *)PTR_load_cert_006a7078)
                                       (*(undefined4 *)puVar10,local_3bc,3,0,uVar15,local_3bc);
                    if (iVar33 == 0) {
LAB_00432474:
                      iVar41 = 0;
                      goto LAB_00432478;
                    }
                    if (iVar45 != 0) {
                      (*(code *)PTR_X509_print_006a70c0)(*(undefined4 *)PTR_bio_err_006a6e3c,iVar33)
                      ;
                    }
                    puVar25 = PTR_bio_err_006a6e3c;
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,
                               "Check that the request matches the signature\n");
                    iVar31 = (*(code *)PTR_X509_get_pubkey_006a6f08)(iVar33);
                    if (iVar31 == 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar25,"error unpacking public key\n");
                      iVar27 = -1;
                    }
                    else {
                      iVar32 = (*(code *)PTR_X509_verify_006a70c4)(iVar33,iVar31);
                      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar31);
                      if (iVar32 < 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar25,"Signature verification problems....\n");
                        iVar27 = 0;
                      }
                      else if (iVar32 == 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar25,
                                   "Signature did not match the certificate\n");
                        iVar27 = 0;
                      }
                      else {
                        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar25,"Signature ok\n");
                        uVar26 = (*(code *)PTR_EVP_md5_006a70c8)();
                        iVar31 = (*(code *)PTR_X509_to_X509_REQ_006a70cc)(iVar33,0,uVar26);
                        if (iVar31 == 0) {
                          iVar27 = -1;
                        }
                        else {
                          iVar27 = do_body(&local_350,local_444,iVar14,puVar23,local_420,iVar24,
                                           pcVar38,iVar30,local_440,local_424,local_410,bVar4,
                                           local_40c,local_408,pcVar48,local_3ec,iVar45,iVar31,
                                           local_414,iVar27,uVar43,uVar17,local_3c8,uVar12,0);
                          (*(code *)PTR_X509_REQ_free_006a6e8c)(iVar31);
                        }
                      }
                    }
                    (*(code *)PTR_X509_free_006a6e90)(iVar33);
                    if (iVar27 < 0) goto LAB_00432474;
                    iVar31 = (int)local_3e8;
                    iVar33 = local_418;
                    if (iVar27 != 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"\n");
                      iVar41 = (*(code *)PTR_BN_add_word_006a70bc)(local_364,1);
                      if (iVar41 == 0) goto LAB_00432474;
                      iVar41 = (*(code *)PTR_sk_push_006a6fa8)(iVar16,local_350);
                      if (iVar41 == 0) goto LAB_00432b60;
                      local_400 = (char *)local_3ac;
                      iVar41 = iVar29;
                    }
LAB_004326d0:
                    local_418 = iVar33;
                    iVar33 = local_418;
                    if (local_3dc != (char *)0x0) {
                      iVar27 = certify(&local_350,local_3dc,local_444,local_3b4,puVar23,local_420,
                                       iVar24,pcVar38,local_364,local_440,local_424,local_410,bVar4,
                                       local_40c,local_408,local_360,local_3ec,local_414,conf,iVar45
                                       ,local_358,local_35c,local_3c8,local_354,local_3d0);
                      if (iVar27 < 0) goto LAB_00432474;
                      iVar33 = iVar31;
                      if (iVar27 != 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"\n");
                        iVar41 = (*(code *)PTR_BN_add_word_006a70bc)(local_364,1);
                        if (iVar41 == 0) goto LAB_00432474;
                        iVar27 = (*(code *)PTR_sk_push_006a6fa8)(iVar16,local_350);
                        iVar41 = (int)local_400;
                        if (iVar27 == 0) goto LAB_00432b60;
                      }
                    }
                    iVar27 = iVar33 + param_1;
                    local_418 = iVar33;
                    if (0 < param_1) {
                      do {
                        iVar33 = iVar33 + 1;
                        iVar29 = certify(&local_350,*ppcVar49,local_444,local_3b4,puVar23,local_420,
                                         iVar24,pcVar38,local_364,local_440,local_424,local_410,
                                         bVar4,local_40c,local_408,local_360,local_3ec,local_414,
                                         conf,iVar45,local_358,local_35c,local_3c8,local_354,
                                         local_3d0);
                        if (iVar29 < 0) goto LAB_00432474;
                        if (iVar29 != 0) {
                          iVar41 = iVar41 + 1;
                          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"\n");
                          iVar29 = (*(code *)PTR_BN_add_word_006a70bc)(local_364,1);
                          if (iVar29 == 0) goto LAB_00432474;
                          iVar29 = (*(code *)PTR_sk_push_006a6fa8)(iVar16,local_350);
                          if (iVar29 == 0) goto LAB_00432b60;
                        }
                        ppcVar49 = ppcVar49 + 1;
                        local_418 = iVar27;
                      } while (iVar27 != iVar33);
                    }
                    iVar24 = (*(code *)PTR_sk_num_006a6e2c)(iVar16);
                    puVar25 = PTR_bio_err_006a6e3c;
                    if (0 < iVar24) {
                      if (local_3ec != 0) {
LAB_00432bdc:
                        uVar43 = *(undefined4 *)puVar10;
                        uVar17 = (*(code *)PTR_sk_num_006a6e2c)(iVar16);
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (uVar43,"Write out database with %d new entries\n",uVar17);
                        iVar41 = (*(code *)PTR_save_serial_006a70d0)(iVar42,"new",local_364,0);
                        if ((iVar41 == 0) ||
                           (iVar41 = (*(code *)PTR_save_index_006a7090)(iVar21,"new",pcVar38),
                           iVar41 == 0)) goto LAB_00432474;
                        goto LAB_00432c48;
                      }
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,
                                 "\n%d out of %d certificate requests certified, commit? [y/n]",
                                 iVar41,local_418);
                      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar10,0xb,0,0);
                      local_32c[0] = local_32c[0] & 0xffffff;
                      iVar41 = (*(code *)PTR_fgets_006a9ae0)
                                         (local_32c,10,*(undefined4 *)PTR_stdin_006a9a14);
                      if (iVar41 == 0) {
                        uVar15 = *(undefined4 *)puVar25;
                        pcVar48 = "CERTIFICATION CANCELED: I/O error\n";
                      }
                      else {
                        if ((local_32c[0]._0_1_ & 0xdf) == 0x59) goto LAB_00432bdc;
                        uVar15 = *(undefined4 *)puVar25;
                        pcVar48 = "CERTIFICATION CANCELED\n";
                      }
                      iVar41 = 0;
                      (*(code *)PTR_BIO_printf_006a6e38)(uVar15,pcVar48);
LAB_004329e0:
                      iVar42 = 0;
                      iVar45 = 0;
                      goto LAB_004306ac;
                    }
LAB_00432c48:
                    if (iVar45 != 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,"writing new certificates\n");
                    }
                    for (iVar41 = 0; iVar24 = (*(code *)PTR_sk_num_006a6e2c)(iVar16),
                        iVar41 < iVar24; iVar41 = iVar41 + 1) {
                      local_350 = (int *)(*(code *)PTR_sk_value_006a6e24)(iVar16,iVar41);
                      iVar24 = **(int **)(*local_350 + 4);
                      puVar25 = (undefined *)(*(int **)(*local_350 + 4))[2];
                      uVar18 = (*(code *)PTR_strlen_006a9a24)(local_404);
                      if (iVar24 == 0) {
                        if (0xf7 < uVar18) goto LAB_00433a14;
                        (*(code *)PTR___memcpy_chk_006a9a48)(auStack_12c,local_404,uVar18 + 1,0x100)
                        ;
                        (*(code *)PTR_BUF_strlcat_006a6f68)(auStack_12c,&DAT_0063b2b4,0x100);
                        iVar33 = (*(code *)PTR_strlen_006a9a24)(auStack_12c);
                        puVar35 = (undefined4 *)(auStack_12c + iVar33);
LAB_00433138:
                        puVar36 = (undefined4 *)((int)puVar35 + 2);
                        auStack_12c[iVar33] = 0x30;
                        *(undefined *)((int)puVar35 + 1) = 0x30;
                      }
                      else {
                        if ((uint)((0x7d - iVar24) * 2) <= uVar18) {
LAB_00433a14:
                          uVar15 = *(undefined4 *)puVar10;
                          pcVar48 = "certificate file name too long\n";
                          goto LAB_00432b74;
                        }
                        (*(code *)PTR___memcpy_chk_006a9a48)(auStack_12c,local_404,uVar18 + 1,0x100)
                        ;
                        (*(code *)PTR_BUF_strlcat_006a6f68)(auStack_12c,&DAT_0063b2b4,0x100);
                        iVar33 = (*(code *)PTR_strlen_006a9a24)(auStack_12c);
                        puVar36 = (undefined4 *)(auStack_12c + iVar33);
                        puVar35 = puVar36;
                        if (iVar24 < 1) goto LAB_00433138;
                        if (puVar36 < &local_2c) {
                          puVar13 = (undefined4 *)(auStack_12c + iVar33 + 2);
                          puVar47 = puVar25;
                          do {
                            puVar36 = puVar13;
                            puVar46 = puVar47 + 1;
                            (*(code *)PTR_BIO_snprintf_006a6f60)
                                      (puVar35,(int)&local_2c - (int)puVar35,&DAT_00634b80,*puVar47)
                            ;
                            if (puVar46 == puVar25 + iVar24) break;
                            puVar35 = puVar36;
                            puVar13 = (undefined4 *)((int)puVar36 + 2);
                            puVar47 = puVar46;
                          } while (puVar25 + ((uint)((int)&local_2c +
                                                    (1 - (int)(auStack_12c + iVar33 + 2))) >> 1) + 1
                                   != puVar46);
                        }
                      }
                      puVar25 = auStack_12c;
                      *(undefined *)(puVar36 + 1) = 0;
                      *(undefined *)puVar36 = 0x2e;
                      *(undefined *)((int)puVar36 + 1) = 0x70;
                      *(undefined *)((int)puVar36 + 2) = 0x65;
                      *(undefined *)((int)puVar36 + 3) = 0x6d;
                      if (iVar45 != 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar10,"writing %s\n",puVar25);
                      }
                      iVar24 = (*(code *)PTR_BIO_ctrl_006a6e18)(local_434,0x6c,5,puVar25);
                      piVar19 = local_350;
                      pcVar50 = (code *)PTR_perror_006a9a80;
                      if (iVar24 < 1) goto LAB_00432e40;
                      if (bVar8) {
                        (*(code *)PTR_PEM_write_bio_X509_006a6f20)(local_434,local_350);
                        piVar19 = local_350;
                        if (bVar3) goto LAB_00433a2c;
LAB_004331e0:
                        (*(code *)PTR_PEM_write_bio_X509_006a6f20)(local_438,piVar19);
                      }
                      else {
                        (*(code *)PTR_X509_print_006a70c0)(local_434,local_350);
                        (*(code *)PTR_PEM_write_bio_X509_006a6f20)(local_434,piVar19);
                        piVar19 = local_350;
                        if (!bVar3) {
                          (*(code *)PTR_X509_print_006a70c0)(local_438,local_350);
                          goto LAB_004331e0;
                        }
LAB_00433a2c:
                        (*(code *)PTR_i2d_X509_bio_006a6f1c)(local_438,local_350);
                      }
                    }
                    iVar41 = (*(code *)PTR_sk_num_006a6e2c)(iVar16);
                    if (iVar41 != 0) {
                      iVar42 = (*(code *)PTR_rotate_serial_006a7118)(iVar42,"new","old");
                      if ((iVar42 == 0) ||
                         (iVar42 = (*(code *)PTR_rotate_index_006a7094)(iVar21,"new","old"),
                         iVar42 == 0)) goto LAB_00432474;
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,"Data Base Updated\n");
                    }
LAB_00433214:
                    iVar41 = 0;
                    if (!bVar6) {
LAB_00433714:
                      if (bVar9) {
                        if (local_3dc == (char *)0x0) {
                          iVar42 = 0;
                          iVar45 = 1;
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)puVar10,"no input files\n");
                          goto LAB_004306ac;
                        }
                        iVar45 = (*(code *)PTR_load_cert_006a7078)
                                           (*(undefined4 *)puVar10,local_3dc,3,0,uVar15,local_3dc);
                        if ((iVar45 != 0) &&
                           (iVar42 = do_revoke(iVar45,pcVar38,local_3d8,local_3d4), 0 < iVar42)) {
                          (*(code *)PTR_X509_free_006a6e90)(iVar45);
                          iVar45 = (*(code *)PTR_save_index_006a7090)(iVar21,"new",pcVar38);
                          if ((iVar45 != 0) &&
                             (iVar45 = (*(code *)PTR_rotate_index_006a7094)(iVar21,"new","old"),
                             iVar45 != 0)) {
                            iVar42 = 0;
                            iVar45 = 0;
                            (*(code *)PTR_BIO_printf_006a6e38)
                                      (*(undefined4 *)PTR_bio_err_006a6e3c,"Data Base Updated\n");
                            goto LAB_004306ac;
                          }
                        }
                        goto LAB_00432478;
                      }
                      goto LAB_004329e0;
                    }
                    if ((local_3f0 == (char *)0x0) &&
                       (local_3f0 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                                      (conf,section,"crl_extensions"),
                       local_3f0 == (char *)0x0)) {
                      (*(code *)PTR_ERR_clear_error_006a6ee0)();
                    }
                    else {
                      (*(code *)PTR_X509V3_set_ctx_006a6eb4)(local_348,0,0,0,0,1);
                      (*(code *)PTR_X509V3_set_nconf_006a6eb8)(local_348,conf);
                      iVar42 = (*(code *)PTR_X509V3_EXT_add_nconf_006a6ebc)
                                         (conf,local_348,local_3f0,0);
                      if (iVar42 == 0) {
                        iVar41 = 0;
                        iVar42 = 0;
                        iVar45 = 1;
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar10,"Error Loading CRL extension section %s\n"
                                   ,local_3f0);
                        goto LAB_004306ac;
                      }
                    }
                    iVar24 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"crlnumber");
                    if (iVar24 == 0) {
                      iVar42 = 0;
                    }
                    else {
                      iVar42 = (*(code *)PTR_load_serial_006a70a0)(iVar24,0,0);
                      if (iVar42 == 0) {
                        iVar41 = 0;
                        iVar45 = 1;
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar10,"error while loading CRL number\n");
                        goto LAB_004306ac;
                      }
                    }
                    if (((local_370 == 0) && (local_36c == 0)) && (local_3b8 == 0)) {
                      iVar41 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                                         (conf,section,"default_crl_days",&local_370);
                      if (iVar41 == 0) {
                        local_370 = 0;
                      }
                      iVar41 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                                         (conf,section,"default_crl_hours",&local_36c);
                      if (iVar41 == 0) {
                        local_36c = 0;
                      }
                      (*(code *)PTR_ERR_clear_error_006a6ee0)();
                      if ((local_370 == 0) && (local_36c == 0)) {
                        iVar41 = 0;
                        iVar45 = 1;
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar10,
                                   "cannot lookup how long until the next CRL is issued\n");
                        goto LAB_004306ac;
                      }
                    }
                    if (iVar45 != 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"making CRL\n");
                    }
                    iVar41 = (*(code *)PTR_X509_CRL_new_006a70d8)();
                    if (iVar41 != 0) {
                      uVar17 = (*(code *)PTR_X509_get_subject_name_006a6f00)(iVar14);
                      iVar33 = (*(code *)PTR_X509_CRL_set_issuer_name_006a70dc)(iVar41,uVar17);
                      if ((iVar33 != 0) &&
                         (iVar33 = (*(code *)PTR_ASN1_TIME_new_006a70e0)(), iVar33 != 0)) {
                        (*(code *)PTR_X509_gmtime_adj_006a6f8c)(iVar33,0);
                        (*(code *)PTR_X509_CRL_set_lastUpdate_006a70e4)(iVar41,iVar33);
                        iVar27 = (*(code *)PTR_X509_time_adj_ex_006a6f90)
                                           (iVar33,local_370,local_36c * 0xe10 + local_3b8,0);
                        if (iVar27 == 0) {
                          iVar45 = 1;
                          (*(code *)PTR_BIO_puts_006a6f58)
                                    (*(undefined4 *)puVar10,"error setting CRL nextUpdate\n");
                          goto LAB_004306ac;
                        }
                        (*(code *)PTR_X509_CRL_set_nextUpdate_006a70e8)(iVar41,iVar33);
                        (*(code *)PTR_ASN1_TIME_free_006a7050)(iVar33);
                        bVar4 = false;
                        for (local_424 = 0;
                            iVar33 = (*(code *)PTR_sk_num_006a6e2c)
                                               (*(undefined4 *)(*(int *)(pcVar38 + 4) + 4)),
                            local_424 < iVar33; local_424 = local_424 + 1) {
                          ppcVar49 = (char **)(*(code *)PTR_sk_value_006a6e24)
                                                        (*(undefined4 *)(*(int *)(pcVar38 + 4) + 4),
                                                         local_424);
                          if (**ppcVar49 == 'R') {
                            iVar33 = (*(code *)PTR_X509_REVOKED_new_006a70ec)();
                            if ((iVar33 != 0) &&
                               (iVar27 = make_revoked(iVar33,ppcVar49[2]), iVar27 != 0)) {
                              if (iVar27 == 2) {
                                bVar4 = true;
                              }
                              iVar27 = (*(code *)PTR_BN_hex2bn_006a70f0)(&local_364,ppcVar49[3]);
                              if (iVar27 != 0) {
                                iVar27 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(local_364,0);
                                (*(code *)PTR_BN_free_006a701c)(local_364);
                                local_364 = 0;
                                if (iVar27 != 0) {
                                  (*(code *)PTR_X509_REVOKED_set_serialNumber_006a70f8)
                                            (iVar33,iVar27);
                                  (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar27);
                                  (*(code *)PTR_X509_CRL_add0_revoked_006a70fc)(iVar41,iVar33);
                                  goto LAB_00433454;
                                }
                              }
                            }
                            iVar45 = 1;
                            goto LAB_004306ac;
                          }
LAB_00433454:
                        }
                        (*(code *)PTR_X509_CRL_sort_006a7100)(iVar41);
                        if (iVar45 != 0) {
                          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"signing CRL\n")
                          ;
                        }
                        if (local_3f0 == (char *)0x0) {
                          if (iVar24 == 0) {
                            if (bVar4) goto LAB_004337f4;
LAB_00433698:
                            if (iVar42 != 0) {
                              (*(code *)PTR_BN_free_006a701c)(iVar42);
                            }
                            iVar45 = do_X509_CRL_sign(*(undefined4 *)puVar10,iVar41,local_444,
                                                      puVar23,local_420);
                            if ((iVar45 == 0) ||
                               (((*(code *)PTR_PEM_write_bio_X509_CRL_006a7114)(local_438,iVar41),
                                iVar24 != 0 &&
                                (iVar45 = (*(code *)PTR_rotate_serial_006a7118)(iVar24,"new","old"),
                                iVar45 == 0)))) goto LAB_00432478;
                            goto LAB_00433714;
                          }
                          (*(code *)PTR_X509V3_set_ctx_006a6eb4)(local_348,iVar14,0,0,iVar41,0);
                          (*(code *)PTR_X509V3_set_nconf_006a6eb8)(local_348,conf);
LAB_004335f0:
                          iVar45 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(iVar42,0);
                          if (iVar45 != 0) {
                            (*(code *)PTR_X509_CRL_add1_ext_i2d_006a710c)(iVar41,0x58,iVar45,0,0);
                            (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar45);
                            iVar45 = (*(code *)PTR_BN_add_word_006a70bc)(iVar42,1);
                            if ((iVar45 != 0) &&
                               (iVar45 = (*(code *)PTR_X509_CRL_set_version_006a7108)(iVar41,1),
                               iVar45 != 0)) {
                              if (iVar24 != 0) {
                                iVar45 = (*(code *)PTR_save_serial_006a70d0)(iVar24,"new",iVar42,0);
                                goto joined_r0x00433690;
                              }
                              goto LAB_00433698;
                            }
                          }
                        }
                        else {
                          (*(code *)PTR_X509V3_set_ctx_006a6eb4)(local_348,iVar14,0,0,iVar41,0);
                          (*(code *)PTR_X509V3_set_nconf_006a6eb8)(local_348,conf);
                          iVar45 = (*(code *)PTR_X509V3_EXT_CRL_add_nconf_006a7104)
                                             (conf,local_348,local_3f0,iVar41);
                          if (iVar45 != 0) {
                            if (iVar24 != 0) goto LAB_004335f0;
LAB_004337f4:
                            iVar45 = (*(code *)PTR_X509_CRL_set_version_006a7108)(iVar41,1);
joined_r0x00433690:
                            if (iVar45 != 0) goto LAB_00433698;
                          }
                        }
                      }
                    }
                  }
                  iVar45 = 1;
                  goto LAB_004306ac;
                }
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar10,"error while loading serial number\n");
              }
LAB_00432228:
              iVar16 = 0;
              iVar41 = 0;
              iVar42 = 0;
              iVar45 = 1;
              goto LAB_004306ac;
            }
            if (iVar45 != 0) {
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"Updating %s ...\n",iVar21);
            }
            iVar16 = (*(code *)PTR_ASN1_UTCTIME_new_006a7030)();
            if (iVar16 != 0) {
              piVar19 = (int *)(*(code *)PTR_X509_gmtime_adj_006a6f8c)(iVar16,0);
              iVar16 = (*(code *)PTR_CRYPTO_malloc_006a7008)(*piVar19 + 1,&DAT_0063526c,0x9da);
              if (iVar16 != 0) {
                (*(code *)PTR_memcpy_006a9aec)(iVar16,piVar19[2],*piVar19);
                puVar25 = PTR_strncmp_006a9970;
                *(undefined *)(iVar16 + *piVar19) = 0;
                iVar42 = (*(code *)puVar25)(iVar16,&DAT_006360a8,2);
                local_44c = 0;
                for (local_3c4 = (char *)0x0;
                    iVar41 = (*(code *)PTR_sk_num_006a6e2c)
                                       (*(undefined4 *)(*(int *)(pcVar38 + 4) + 4)),
                    (int)local_3c4 < iVar41; local_3c4 = (char *)((int)local_3c4 + 1)) {
                  ppcVar22 = (char **)(*(code *)PTR_sk_value_006a6e24)
                                                (*(undefined4 *)(*(int *)(pcVar38 + 4) + 4),
                                                 local_3c4);
                  pcVar48 = *ppcVar22;
                  if (*pcVar48 == 'V') {
                    pcVar44 = ppcVar22[1];
                    iVar41 = (*(code *)PTR_strncmp_006a9970)(pcVar44,&DAT_006360a8,2);
                    if (iVar41 < 1) {
                      if (iVar42 < 1) {
LAB_00433de8:
                        iVar41 = (*(code *)PTR_strcmp_006a9b18)(pcVar44,iVar16);
                        if (iVar41 < 1) {
                          *pcVar48 = 'E';
                          pcVar48 = *ppcVar22;
                          goto LAB_00433d6c;
                        }
                      }
                    }
                    else {
                      if (0 < iVar42) goto LAB_00433de8;
                      *pcVar48 = 'E';
                      pcVar48 = *ppcVar22;
LAB_00433d6c:
                      puVar25 = PTR_BIO_printf_006a6e38;
                      local_44c = local_44c + 1;
                      pcVar48[1] = '\0';
                      (*(code *)puVar25)(*(undefined4 *)puVar10,"%s=Expired\n",ppcVar22[3]);
                    }
                  }
                }
                (*(code *)PTR_ASN1_UTCTIME_free_006a700c)(piVar19);
                (*(code *)PTR_CRYPTO_free_006a6e88)(iVar16);
                if (local_44c == 0) {
                  if (iVar45 != 0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,"No entries found to mark expired\n");
                  }
                }
                else {
                  iVar16 = (*(code *)PTR_save_index_006a7090)(iVar21,"new",pcVar38);
                  if ((iVar16 == 0) ||
                     (iVar16 = (*(code *)PTR_rotate_index_006a7094)(iVar21,"new","old"), iVar16 == 0
                     )) goto LAB_00431690;
                  if (iVar45 != 0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,"Done. %d entries marked as expired\n",
                               local_44c);
                  }
                }
                goto LAB_00431ddc;
              }
              (*(code *)PTR_ASN1_UTCTIME_free_006a700c)(piVar19);
              (*(code *)PTR_CRYPTO_free_006a6e88)(0);
            }
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"Malloc failure\n");
          }
        }
LAB_00431690:
        iVar16 = 0;
        iVar41 = 0;
        iVar42 = 0;
        iVar45 = 1;
        goto LAB_004306ac;
      }
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar10,"variable lookup failed for %s::%s\n",section,"database");
    }
  }
LAB_0043181c:
  iVar16 = 0;
  iVar41 = 0;
  pcVar38 = (char *)0x0;
  iVar42 = 0;
  iVar45 = 1;
LAB_004306ac:
  while( true ) {
    (*(code *)PTR_BIO_free_all_006a6e74)(local_434);
    (*(code *)PTR_BIO_free_all_006a6e74)(local_438);
    (*(code *)PTR_BIO_free_all_006a6e74)(local_430);
    (*(code *)PTR_BIO_free_all_006a6e74)(local_42c);
    if (iVar16 != 0) {
      (*(code *)PTR_sk_pop_free_006a7058)(iVar16,PTR_X509_free_006a6e90);
    }
    if (iVar45 != 0) {
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar10);
    }
    (*(code *)PTR_app_RAND_write_file_006a6f4c)(local_428,*(undefined4 *)puVar10);
    if ((bVar5) && (local_374 != (char *)0x0)) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    (*(code *)PTR_BN_free_006a701c)(local_364);
    (*(code *)PTR_BN_free_006a701c)(iVar42);
    (*(code *)PTR_free_index_006a705c)(pcVar38);
    if (local_420 != 0) {
      (*(code *)PTR_sk_free_006a6e80)(local_420);
    }
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(local_444);
    if (iVar14 != 0) {
      (*(code *)PTR_X509_free_006a6e90)(iVar14);
    }
    (*(code *)PTR_X509_CRL_free_006a7060)(iVar41);
    (*(code *)PTR_NCONF_free_006a6e6c)(conf);
    (*(code *)PTR_NCONF_free_006a6e6c)(extconf);
    (*(code *)PTR_OBJ_cleanup_006a6e98)();
    if (local_2c == *(int *)puVar11) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    pcVar48 = pcVar38;
LAB_00430638:
    if (local_368 < 1) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar10,"error loading the config file \'%s\'\n",pcVar48);
    }
    else {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar10,"error on line %ld of config file \'%s\'\n",local_368,
                 pcVar48);
    }
    if (pcVar38 != (char *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar38);
    }
LAB_00430670:
    local_428 = 0;
LAB_00430674:
    pcVar38 = (char *)0x0;
LAB_00430680:
    local_434 = 0;
    local_438 = (char *)0x0;
    local_430 = 0;
    local_42c = 0;
LAB_00430690:
    iVar16 = 0;
    iVar41 = 0;
    local_444 = 0;
    iVar14 = 0;
    bVar5 = false;
    iVar42 = 0;
    iVar45 = 1;
  }
  return iVar45;
}

