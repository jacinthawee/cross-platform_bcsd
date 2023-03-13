
bool srp_main(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  char **ppcVar5;
  byte *pbVar6;
  byte **ppbVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  undefined4 uVar10;
  char *pcVar11;
  char *pcVar12;
  char *pcVar13;
  undefined1 *puVar14;
  int *piVar15;
  byte *pbVar16;
  int iVar17;
  int iVar18;
  byte *pbVar19;
  bool bVar20;
  byte **ppbVar21;
  int iVar22;
  byte **ppbVar23;
  byte **ppbVar24;
  int iVar25;
  byte **ppbVar26;
  char *local_b4;
  int local_b0;
  int local_ac;
  byte *local_a8;
  int local_a4;
  int local_9c;
  int local_98;
  byte *local_90;
  char *local_84;
  char *local_80;
  char *local_7c;
  char *local_78;
  byte *local_74;
  uint local_5c;
  int local_54;
  int local_50;
  int local_4c;
  undefined auStack_48 [4];
  byte *local_44;
  byte *local_40;
  byte *local_3c;
  byte *local_38;
  byte *local_34;
  byte *local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  puVar1 = PTR_bio_err_006a6e3c;
  local_4c = -1;
  local_54 = 0;
  local_50 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  local_b4 = &_gp_1;
  conf = 0;
  section = (byte *)0x0;
  if (*(int *)puVar1 == 0) {
    uVar10 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar4 = (*(code *)PTR_BIO_new_006a6ea4)(uVar10);
    *(int *)puVar1 = iVar4;
    if (iVar4 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar4,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
    }
  }
  puVar14 = (undefined1 *)(param_1 + -1);
  ppbVar26 = (byte **)(param_2 + 4);
  if ((int)puVar14 < 1) {
    iVar4 = 0;
    local_78 = (char *)0x0;
    iVar17 = 0;
    local_a8 = (byte *)0x0;
    ppbVar7 = (byte **)0x0;
    local_90 = (byte *)0x0;
    iVar25 = 0;
    local_74 = (byte *)0x0;
    local_7c = (char *)0x0;
    bVar20 = false;
    local_80 = (char *)0x0;
    local_a4 = 0;
    local_9c = 0;
    local_98 = 0;
    local_ac = 0;
    goto LAB_00477b98;
  }
  local_78 = (char *)0x0;
  local_a8 = (byte *)0x0;
  local_90 = (byte *)0x0;
  local_74 = (byte *)0x0;
  ppbVar24 = (byte **)0x0;
  local_7c = (char *)0x0;
  iVar25 = 0;
  local_80 = (char *)0x0;
  local_a4 = 0;
  local_9c = 0;
  local_98 = 0;
  local_ac = 0;
  do {
    while( true ) {
      pbVar16 = *ppbVar26;
      iVar4 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,"-verbose");
      if (iVar4 != 0) break;
      iVar25 = iVar25 + 1;
LAB_00477ae0:
      puVar14 = (undefined1 *)((int)puVar14 + -1);
      ppbVar26 = ppbVar26 + 1;
      if ((int *)puVar14 == (int *)0x0) goto LAB_00477b48;
    }
    iVar4 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,"-config");
    if (iVar4 != 0) {
      iVar4 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,"-name");
      if (iVar4 == 0) {
        puVar14 = (undefined1 *)((int)puVar14 + -1);
        piVar15 = (int *)puVar14;
        if ((int *)puVar14 == (int *)0x0) goto LAB_00478298;
        section = ppbVar26[1];
        ppbVar26 = ppbVar26 + 1;
      }
      else {
        iVar4 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,"-srpvfile");
        if (iVar4 == 0) {
          puVar14 = (undefined1 *)((int)puVar14 + -1);
          piVar15 = (int *)puVar14;
          if ((int *)puVar14 == (int *)0x0) goto LAB_00478298;
          local_a8 = ppbVar26[1];
          ppbVar26 = ppbVar26 + 1;
        }
        else {
          iVar4 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,&DAT_00645ba4);
          if (iVar4 == 0) {
            local_ac = 1;
          }
          else {
            iVar4 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,"-delete");
            if (iVar4 == 0) {
              local_9c = 1;
            }
            else {
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,"-modify");
              if (iVar4 == 0) {
                local_a4 = 1;
              }
              else {
                iVar4 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,"-list");
                if (iVar4 == 0) {
                  local_98 = 1;
                }
                else {
                  local_5c = (uint)*pbVar16;
                  if ((((local_5c == 0x2d) && (pbVar16[1] == 0x67)) && (pbVar16[2] == 0x6e)) &&
                     (pbVar16[3] == 0)) {
                    puVar14 = (undefined1 *)((int)puVar14 + -1);
                    piVar15 = (int *)puVar14;
                    if ((int *)puVar14 == (int *)0x0) goto LAB_00478298;
                    local_74 = ppbVar26[1];
                    ppbVar26 = ppbVar26 + 1;
                  }
                  else {
                    iVar4 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,"-userinfo");
                    if (iVar4 == 0) {
                      puVar14 = (undefined1 *)((int)puVar14 + -1);
                      piVar15 = (int *)puVar14;
                      if ((int *)puVar14 == (int *)0x0) goto LAB_00478298;
                      local_90 = ppbVar26[1];
                      ppbVar26 = ppbVar26 + 1;
                    }
                    else {
                      iVar4 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,"-passin");
                      if (iVar4 == 0) {
                        puVar14 = (undefined1 *)((int)puVar14 + -1);
                        piVar15 = (int *)puVar14;
                        if ((int *)puVar14 == (int *)0x0) goto LAB_00478298;
                        local_80 = (char *)ppbVar26[1];
                        ppbVar26 = ppbVar26 + 1;
                      }
                      else {
                        iVar4 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,"-passout");
                        if (iVar4 == 0) {
                          puVar14 = (undefined1 *)((int)puVar14 + -1);
                          piVar15 = (int *)puVar14;
                          if ((int *)puVar14 == (int *)0x0) goto LAB_00478298;
                          local_7c = (char *)ppbVar26[1];
                          ppbVar26 = ppbVar26 + 1;
                        }
                        else {
                          iVar4 = (*(code *)PTR_strcmp_006a9b18)(pbVar16,"-engine");
                          if (iVar4 != 0) goto LAB_00479174;
                          puVar14 = (undefined1 *)((int)puVar14 + -1);
                          piVar15 = (int *)puVar14;
                          if ((int *)puVar14 == (int *)0x0) goto LAB_00478298;
                          local_78 = (char *)ppbVar26[1];
                          ppbVar26 = ppbVar26 + 1;
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
      goto LAB_00477ae0;
    }
    piVar15 = (int *)((int)puVar14 + -1);
    if ((int *)((int)puVar14 + -1) == (int *)0x0) goto LAB_00478298;
    ppbVar24 = (byte **)ppbVar26[1];
    puVar14 = (undefined1 *)((int)puVar14 + -2);
    ppbVar26 = ppbVar26 + 2;
  } while ((int *)puVar14 != (int *)0x0);
LAB_00477b48:
  iVar4 = local_9c * 2 + local_a4;
  iVar17 = local_ac + local_9c + local_a4 + local_98;
  bVar20 = false;
  piVar15 = (int *)puVar14;
  do {
    puVar14 = (undefined1 *)piVar15;
    ppbVar7 = ppbVar24;
    if ((local_a8 != (byte *)0x0) && (ppbVar24 != (byte **)0x0)) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-dbfile and -configfile cannot be specified together.\n");
      bVar20 = true;
    }
LAB_00477b98:
    ppbVar24 = ppbVar26;
    if (iVar17 != 1) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,
                 "Exactly one of the options -add, -delete, -modify -list must be specified.\n");
      bVar20 = true;
    }
    if ((iVar4 == 1) && ((int)puVar14 < 1)) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,
                 "Need at least one user for options -add, -delete, -modify. \n");
      bVar20 = true;
    }
    puVar2 = PTR_bio_err_006a6e3c;
    if (((local_54 == 0) && (local_50 == 0)) || ((int *)puVar14 == (int *)0x1)) {
      if (bVar20) goto LAB_00477bf0;
      (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
      setup_engine(*(undefined4 *)puVar1,local_78,0);
      iVar4 = app_passwd(*(undefined4 *)puVar1,local_80,local_7c,&local_54,&local_50);
      if (iVar4 == 0) {
        uVar10 = *(undefined4 *)puVar2;
        pcVar11 = "Error getting passwords\n";
        goto LAB_00477c70;
      }
      if (local_a8 == (byte *)0x0) {
        if (ppbVar7 == (byte **)0x0) {
          ppbVar7 = (byte **)(*(code *)PTR_getenv_006a9a60)("OPENSSL_CONF");
          if (ppbVar7 == (byte **)0x0) {
            ppbVar26 = (byte **)(*(code *)PTR_getenv_006a9a60)("SSLEAY_CONF");
            ppbVar23 = ppbVar7;
            ppbVar7 = ppbVar26;
            if (ppbVar26 == (byte **)0x0) {
              uVar10 = (*(code *)PTR_X509_get_default_cert_area_006a7064)();
              iVar4 = (*(code *)PTR_strlen_006a9a24)(uVar10);
              iVar4 = iVar4 + 0xd;
              ppbVar23 = (byte **)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar4,"srp.c",0x1bd);
              ppbVar7 = ppbVar23;
              if (ppbVar23 == (byte **)0x0) {
                uVar10 = *(undefined4 *)puVar2;
                pcVar11 = "Out of memory\n";
                goto LAB_00477c70;
              }
              (*(code *)PTR_BUF_strlcpy_006a6f64)(ppbVar23,uVar10,iVar4);
              (*(code *)PTR_BUF_strlcat_006a6f68)(ppbVar23,&DAT_0063b2b4,iVar4);
              (*(code *)PTR_BUF_strlcat_006a6f68)(ppbVar23,"openssl.cnf",iVar4);
            }
          }
          else {
            ppbVar23 = (byte **)0x0;
          }
        }
        else {
          ppbVar23 = (byte **)0x0;
        }
        if (iVar25 != 0) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar1,"Using configuration from %s\n",ppbVar7);
        }
        conf = (*(code *)PTR_NCONF_new_006a6e58)(0);
        iVar4 = (*(code *)PTR_NCONF_load_006a6e5c)(conf,ppbVar7,&local_4c);
        if (0 < iVar4) {
          if (ppbVar23 != (byte **)0x0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)(ppbVar23);
          }
          iVar4 = load_config(*(undefined4 *)puVar1,conf);
          if (iVar4 != 0) {
            iVar4 = *(int *)(local_b4 + -0x5460);
            if (iVar4 == 0) {
              if (iVar25 != 0) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)PTR_bio_err_006a6e3c,
                           "trying to read default_srp in \" BASE_SECTION \"\n");
              }
              iVar4 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,"srp","default_srp");
              *(int *)(local_b4 + -0x5460) = iVar4;
              if (iVar4 == 0) {
                ppbVar23 = (byte **)0x0;
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar1,"variable lookup failed for %s::%s\n","srp",
                           "default_srp");
                ppbVar21 = (byte **)0x0;
                pbVar16 = (byte *)0x0;
                goto LAB_00477c8c;
              }
            }
            if (conf == 0) {
              ppbVar21 = (byte **)0x0;
            }
            else {
              ppbVar21 = (byte **)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,"srp","RANDFILE");
              iVar4 = *(int *)(local_b4 + -0x5460);
            }
            if (iVar25 != 0) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar1,"trying to read srpvfile in section \"%s\"\n",iVar4);
              iVar4 = *(int *)(local_b4 + -0x5460);
            }
            local_a8 = (byte *)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,iVar4,"srpvfile");
            if (local_a8 != (byte *)0x0) {
              if (ppbVar21 == (byte **)0x0) goto LAB_00477e8c;
              app_RAND_load_file(ppbVar21,*(undefined4 *)puVar1,0);
              goto LAB_00477e9c;
            }
            ppbVar23 = (byte **)0x0;
            pbVar16 = (byte *)0x0;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar1,"variable lookup failed for %s::%s\n",
                       *(undefined4 *)(local_b4 + -0x5460),"srpvfile");
            goto LAB_00477c8c;
          }
          goto LAB_00477c7c;
        }
        if (local_4c < 1) {
          ppbVar21 = (byte **)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar1,"error loading the config file \'%s\'\n",ppbVar7);
          pbVar16 = (byte *)0x0;
        }
        else {
          ppbVar21 = (byte **)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar1,"error on line %ld of config file \'%s\'\n",local_4c,
                     ppbVar7);
          pbVar16 = (byte *)0x0;
        }
        goto LAB_00477c8c;
      }
LAB_00477e8c:
      ppbVar21 = (byte **)0x0;
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
LAB_00477e9c:
      if (iVar25 != 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar1,"Trying to read SRP verifier file \"%s\"\n",local_a8);
      }
      pbVar16 = (byte *)load_index(local_a8,auStack_48);
      if (pbVar16 == (byte *)0x0) {
        ppbVar23 = (byte **)0x0;
        goto LAB_00477c8c;
      }
      iVar18 = 0;
      local_b0 = -1;
      iVar4 = -1;
      local_b4 = "  %d = \"%s\"\n";
      iVar17 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*(int *)(pbVar16 + 4) + 4));
      if (0 < iVar17) {
        do {
          ppcVar5 = (char **)(*(code *)PTR_sk_value_006a6e24)
                                       (*(undefined4 *)(*(int *)(pbVar16 + 4) + 4),iVar18);
          if (**ppcVar5 == 'I') {
            if (((local_b0 < 0) && (local_74 != (byte *)0x0)) &&
               (iVar4 = (*(code *)PTR_strcmp_006a9b18)(local_74,ppcVar5[3]), iVar4 == 0)) {
              local_b0 = iVar18;
            }
            iVar4 = iVar18;
            if ((-1 < iVar18) && (1 < iVar25)) {
              uVar10 = *(undefined4 *)puVar1;
              puVar8 = (undefined4 *)
                       (*(code *)PTR_sk_value_006a6e24)
                                 (*(undefined4 *)(*(int *)(pbVar16 + 4) + 4),iVar18);
              (*(code *)PTR_BIO_printf_006a6e38)(uVar10,"%s \"%s\"\n","g N entry",puVar8[3]);
              iVar17 = 0;
              do {
                uVar10 = *puVar8;
                iVar22 = iVar17 + 1;
                puVar8 = puVar8 + 1;
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar1,"  %d = \"%s\"\n",iVar17,uVar10);
                iVar17 = iVar22;
              } while (iVar22 != 6);
            }
          }
          iVar18 = iVar18 + 1;
          iVar17 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*(int *)(pbVar16 + 4) + 4));
        } while (iVar18 < iVar17);
      }
      if (iVar25 == 0) {
        if (local_b0 < 0) {
          if (iVar4 < 1) {
            ppbVar26 = (byte **)0x0;
          }
          else {
LAB_004786b8:
            iVar4 = (*(code *)PTR_SRP_get_default_gN_006a7f2c)(local_74);
            if (iVar4 == 0) {
              ppbVar23 = (byte **)0x0;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar1,"No g and N value for index \"%s\"\n",local_74);
              ppbVar7 = ppbVar21;
              goto LAB_00477c8c;
            }
            ppbVar26 = (byte **)0x0;
            if (iVar25 != 0) goto LAB_004786d0;
          }
        }
        else {
          ppbVar26 = (byte **)(*(code *)PTR_sk_value_006a6e24)
                                        (*(undefined4 *)(*(int *)(pbVar16 + 4) + 4),local_b0);
        }
      }
      else {
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"Database initialised\n");
        if (local_b0 < 0) {
          if (0 < iVar4) goto LAB_004786b8;
LAB_004786d0:
          ppbVar26 = (byte **)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar1,"Database has no g N information.\n");
          if (1 < iVar25) {
LAB_004786f8:
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"Starting user processing\n");
          }
        }
        else {
          ppbVar26 = (byte **)(*(code *)PTR_sk_value_006a6e24)
                                        (*(undefined4 *)(*(int *)(pbVar16 + 4) + 4),local_b0);
          uVar10 = *(undefined4 *)PTR_bio_err_006a6e3c;
          if (iVar25 != 1) {
            puVar8 = (undefined4 *)
                     (*(code *)PTR_sk_value_006a6e24)
                               (*(undefined4 *)(*(int *)(pbVar16 + 4) + 4),local_b0);
            (*(code *)PTR_BIO_printf_006a6e38)(uVar10,"%s \"%s\"\n","Default g and N",puVar8[3]);
            iVar4 = 0;
            do {
              uVar10 = *puVar8;
              iVar17 = iVar4 + 1;
              puVar8 = puVar8 + 1;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar1,"  %d = \"%s\"\n",iVar4,uVar10);
              iVar4 = iVar17;
            } while (iVar17 != 6);
            goto LAB_004786f8;
          }
        }
      }
      pbVar19 = (byte *)0x0;
      if (0 < (int)puVar14) {
        pbVar19 = *ppbVar24;
        ppbVar24 = ppbVar24 + 1;
      }
      bVar20 = false;
      local_b4 = (char *)0x0;
      local_84 = "user \"%s\" does not exist, operation ignored. t\n";
      local_80 = "-check_ss_sig";
      local_7c = "Verifying password for user \"%s\"\n";
      local_78 = "-check_ss_sig";
      iVar4 = local_98;
      if (local_98 != 0) goto LAB_00478070;
LAB_00477fe4:
      if (pbVar19 != (byte *)0x0) {
LAB_00477fec:
        if (1 < iVar25) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar1,"Processing user \"%s\"\n",pbVar19);
        }
        iVar17 = get_index(pbVar16,pbVar19,0x55);
        if (iVar17 < 0) goto LAB_00478040;
        uVar10 = *(undefined4 *)puVar1;
        if ((iVar25 == 0) && (iVar4 == 0)) {
          if (local_ac != 0) goto LAB_00478980;
          goto LAB_0047817c;
        }
        do {
          print_user_part_3(pbVar16,uVar10,iVar17,1);
LAB_00478040:
          if (iVar4 == 0) {
            if (local_ac == 0) {
LAB_0047817c:
              if (local_a4 == 0) {
                iVar4 = 0;
                if (local_9c != 0) {
                  if (iVar17 < 0) {
                    uVar10 = *(undefined4 *)puVar1;
                    pcVar11 = local_84;
                    goto LAB_00478be8;
                  }
                  puVar8 = (undefined4 *)
                           (*(code *)PTR_sk_value_006a6e24)
                                     (*(undefined4 *)(*(int *)(pbVar16 + 4) + 4),iVar17);
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar1,"user \"%s\" revoked. t\n",pbVar19);
                  bVar20 = true;
                  *(undefined *)*puVar8 = 0x52;
                }
              }
              else {
                if (iVar17 < 0) {
                  uVar10 = *(undefined4 *)puVar1;
                  pcVar11 = "user \"%s\" does not exist, operation ignored.\n";
                }
                else {
                  ppcVar5 = (char **)(*(code *)PTR_sk_value_006a6e24)
                                               (*(undefined4 *)(*(int *)(pbVar16 + 4) + 4),iVar17);
                  if (**ppcVar5 != 'v') {
                    if (**ppcVar5 == 'V') {
                      if (iVar25 == 0) {
                        pcVar11 = ppcVar5[4];
                      }
                      else {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar1,"Verifying password for user \"%s\"\n",
                                   pbVar19);
                        pcVar11 = ppcVar5[4];
                      }
                      iVar4 = get_index(pbVar16,pcVar11,0x49);
                      if (iVar4 < 0) {
                        pcVar11 = ppcVar5[1];
                        pcVar12 = ppcVar5[2];
LAB_004781ec:
                        pcVar13 = ppcVar5[4];
                        uVar10 = 0;
                      }
                      else {
                        iVar4 = (*(code *)PTR_sk_value_006a6e24)
                                          (*(undefined4 *)(*(int *)(pbVar16 + 4) + 4),iVar17);
                        pcVar11 = ppcVar5[1];
                        pcVar12 = ppcVar5[2];
                        if (iVar4 == 0) goto LAB_004781ec;
                        pcVar13 = *(char **)(iVar4 + 8);
                        uVar10 = *(undefined4 *)(iVar4 + 4);
                      }
                      iVar4 = srp_verify_user(pbVar19,pcVar11,pcVar12,pcVar13,uVar10,local_54,
                                              *(undefined4 *)puVar1,iVar25);
                      if (iVar4 != 0) goto LAB_004788bc;
                      pcVar11 = "Invalid password for user \"%s\", operation abandoned.\n";
                      uVar10 = *(undefined4 *)PTR_bio_err_006a6e3c;
                    }
                    else {
LAB_004788bc:
                      if (iVar25 != 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar1,"Password for user \"%s\" ok.\n",pbVar19);
                      }
                      if (ppbVar26 == (byte **)0x0) {
                        pbVar6 = (byte *)0x0;
                        pbVar9 = (byte *)0x0;
                      }
                      else {
                        pbVar6 = ppbVar26[2];
                        pbVar9 = ppbVar26[1];
                      }
                      iVar4 = srp_create_user(pbVar19,ppcVar5 + 1,ppcVar5 + 2,pbVar6,pbVar9,local_50
                                              ,*(undefined4 *)puVar1,iVar25);
                      puVar2 = PTR_BUF_strdup_006a6fdc;
                      if (iVar4 != 0) {
                        **ppcVar5 = 'v';
                        pcVar11 = (char *)(*(code *)puVar2)(iVar4);
                        ppcVar5[4] = pcVar11;
                        if (((ppcVar5[3] != (char *)0x0) && (pcVar11 != (char *)0x0)) &&
                           ((*ppcVar5 != (char *)0x0 &&
                            ((ppcVar5[1] != (char *)0x0 && (ppcVar5[2] != (char *)0x0)))))) {
                          if (local_90 != (byte *)0x0) {
                            pcVar11 = (char *)(*(code *)PTR_BUF_strdup_006a6fdc)(local_90);
                            ppcVar5[5] = pcVar11;
                            if (pcVar11 == (char *)0x0) goto LAB_00478b94;
                          }
                          iVar4 = 0;
                          bVar20 = true;
                          goto LAB_00478058;
                        }
                        goto LAB_00478b94;
                      }
                      pcVar11 = "Cannot create srp verifier for user \"%s\", operation abandoned.\n"
                      ;
                      uVar10 = *(undefined4 *)PTR_bio_err_006a6e3c;
                    }
                    local_b4 = local_b4 + 1;
                    (*(code *)PTR_BIO_printf_006a6e38)(uVar10,pcVar11,pbVar19);
                    if (iVar25 == 0) goto LAB_004780e4;
                    goto LAB_00478254;
                  }
                  uVar10 = *(undefined4 *)puVar1;
                  pcVar11 = "user \"%s\" already updated, operation ignored.\n";
                }
LAB_00478be8:
                iVar4 = 0;
                local_b4 = local_b4 + 1;
                (*(code *)PTR_BIO_printf_006a6e38)(uVar10,pcVar11,pbVar19);
              }
            }
            else {
              if (iVar17 < 0) {
                local_40 = (byte *)0x0;
                local_3c = (byte *)0x0;
                local_30 = (byte *)0x0;
                if (ppbVar26 == (byte **)0x0) {
                  pbVar6 = (byte *)0x0;
                  pbVar9 = local_74;
                }
                else {
                  pbVar6 = ppbVar26[1];
                  pbVar9 = ppbVar26[2];
                }
                iVar17 = srp_create_user(pbVar19,&local_40,&local_3c,pbVar9,pbVar6,local_50,
                                         *(undefined4 *)puVar1,iVar25);
                if (iVar17 == 0) {
                  local_b4 = local_b4 + 1;
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)PTR_bio_err_006a6e3c,
                             "Cannot create srp verifier for user \"%s\", operation abandoned .\n",
                             pbVar19);
                  goto LAB_00478b94;
                }
                local_38 = (byte *)(*(code *)PTR_BUF_strdup_006a6fdc)(pbVar19);
                local_44 = (byte *)(*(code *)PTR_BUF_strdup_006a6fdc)("v");
                local_34 = (byte *)(*(code *)PTR_BUF_strdup_006a6fdc)(iVar17);
                if (local_38 != (byte *)0x0) {
                  if ((((local_34 != (byte *)0x0) && (local_44 != (byte *)0x0)) &&
                      (local_40 != (byte *)0x0)) && (local_3c != (byte *)0x0)) {
                    if ((local_90 == (byte *)0x0) ||
                       (local_30 = (byte *)(*(code *)PTR_BUF_strdup_006a6fdc)(local_90),
                       local_30 != (byte *)0x0)) {
                      uVar10 = *(undefined4 *)puVar1;
                      ppbVar7 = (byte **)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x1c,"srp.c",0xb5);
                      if (ppbVar7 == (byte **)0x0) {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)PTR_bio_err_006a6e3c,"Memory allocation failure\n"
                                  );
                      }
                      else {
                        ppbVar7[6] = (byte *)0x0;
                        puVar2 = PTR_TXT_DB_insert_006a7028;
                        *ppbVar7 = local_44;
                        local_44 = (byte *)0x0;
                        ppbVar7[1] = local_40;
                        local_40 = (byte *)0x0;
                        ppbVar7[2] = local_3c;
                        local_3c = (byte *)0x0;
                        ppbVar7[3] = local_38;
                        local_38 = (byte *)0x0;
                        ppbVar7[4] = local_34;
                        local_34 = (byte *)0x0;
                        ppbVar7[5] = local_30;
                        local_30 = (byte *)0x0;
                        iVar17 = (*(code *)puVar2)(*(undefined4 *)(pbVar16 + 4),ppbVar7);
                        if (iVar17 != 0) {
                          puVar14 = (undefined1 *)((int)puVar14 + -1);
                          bVar20 = true;
                          if (0 < (int)puVar14) goto LAB_00478064;
                          break;
                        }
                        (*(code *)PTR_BIO_printf_006a6e38)(uVar10,"failed to update srpvfile\n");
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (uVar10,"TXT_DB error number %ld\n",
                                   *(undefined4 *)(*(int *)(pbVar16 + 4) + 0x10));
                        (*(code *)PTR_CRYPTO_free_006a6e88)(ppbVar7);
                        ppbVar26 = ppbVar7;
                      }
                    }
                    if (local_38 == (byte *)0x0) goto LAB_00478b1c;
                  }
                  (*(code *)PTR_CRYPTO_free_006a6e88)();
                }
LAB_00478b1c:
                if (local_34 != (byte *)0x0) {
                  (*(code *)PTR_CRYPTO_free_006a6e88)(local_34);
                }
                if (local_30 != (byte *)0x0) {
                  (*(code *)PTR_CRYPTO_free_006a6e88)();
                }
                if (local_44 != (byte *)0x0) {
                  (*(code *)PTR_CRYPTO_free_006a6e88)();
                }
                if (local_40 != (byte *)0x0) {
                  (*(code *)PTR_CRYPTO_free_006a6e88)();
                }
                if (local_3c != (byte *)0x0) {
                  (*(code *)PTR_CRYPTO_free_006a6e88)();
                }
                goto LAB_00478b94;
              }
LAB_00478980:
              puVar8 = (undefined4 *)
                       (*(code *)PTR_sk_value_006a6e24)
                                 (*(undefined4 *)(*(int *)(pbVar16 + 4) + 4),iVar17);
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar1,"user \"%s\" reactivated.\n",pbVar19);
              iVar4 = 0;
              bVar20 = true;
              *(undefined *)*puVar8 = 0x56;
            }
          }
          else {
            if (pbVar19 == (byte *)0x0) goto LAB_00478a34;
            if (iVar17 < 0) {
              local_b4 = local_b4 + 1;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar1,"user \"%s\" does not exist, ignored. t\n",pbVar19);
            }
          }
LAB_00478058:
          while( true ) {
            puVar14 = (undefined1 *)((int)puVar14 + -1);
            if ((int)puVar14 < 1) goto LAB_0047889c;
LAB_00478064:
            pbVar19 = *ppbVar24;
            ppbVar24 = ppbVar24 + 1;
            if (iVar4 == 0) goto LAB_00477fe4;
LAB_00478070:
            if (pbVar19 != (byte *)0x0) goto LAB_00477fec;
            iVar17 = get_index(pbVar16,0,0x55);
            if (-1 < iVar17) break;
LAB_00478a34:
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"List all users\n");
            for (iVar4 = 0;
                iVar17 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*(int *)(pbVar16 + 4) + 4)),
                iVar4 < iVar17; iVar4 = iVar4 + 1) {
              print_user_part_3(pbVar16,*(undefined4 *)puVar1,iVar4,1);
            }
            iVar4 = 0;
          }
          uVar10 = *(undefined4 *)puVar1;
        } while( true );
      }
LAB_0047889c:
      if (iVar25 != 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"User procession done.\n");
        if (!bVar20) goto LAB_004788b0;
        iVar4 = 0;
        while (iVar17 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*(int *)(pbVar16 + 4) + 4)),
              puVar14 = PTR_bio_err_006a6e3c, iVar4 < iVar17) {
          ppcVar5 = (char **)(*(code *)PTR_sk_value_006a6e24)
                                       (*(undefined4 *)(*(int *)(pbVar16 + 4) + 4),iVar4);
          if (**ppcVar5 == 'v') {
            **ppcVar5 = 'V';
            print_user_part_3(pbVar16,*(undefined4 *)puVar1,iVar4,iVar25);
            iVar4 = iVar4 + 1;
          }
          else {
            iVar4 = iVar4 + 1;
          }
        }
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"Trying to update srpvfile.\n");
        iVar4 = save_index(local_a8,"new",pbVar16);
        if (iVar4 != 0) {
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar14,"Temporary srpvfile created.\n")
          ;
          iVar4 = rotate_index(local_a8,"new","old");
          if (iVar4 == 0) {
LAB_00478b94:
            bVar20 = true;
          }
          else {
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar14,"srpvfile updated.\n");
            bVar20 = local_b4 != (char *)0x0;
          }
          goto LAB_00478b98;
        }
        bVar20 = true;
        if (local_b4 != (char *)0x0) {
LAB_00478254:
          bVar20 = true;
          goto LAB_00478258;
        }
LAB_00478274:
        ppbVar23 = (byte **)0x0;
        goto LAB_00478278;
      }
      if (!bVar20) {
LAB_004788b0:
        bVar20 = local_b4 != (char *)0x0;
LAB_00478b98:
        if (local_b4 == (char *)0x0) {
          ppbVar23 = (byte **)0x0;
          ppbVar7 = ppbVar24;
          goto joined_r0x0047918c;
        }
        if (iVar25 != 0) {
LAB_00478258:
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"User errors %d.\n",local_b4);
          goto LAB_00478274;
        }
        goto joined_r0x00478ba8;
      }
      iVar4 = 0;
      while (iVar17 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(*(int *)(pbVar16 + 4) + 4)),
            iVar4 < iVar17) {
        ppcVar5 = (char **)(*(code *)PTR_sk_value_006a6e24)
                                     (*(undefined4 *)(*(int *)(pbVar16 + 4) + 4),iVar4);
        if (**ppcVar5 == 'v') {
          **ppcVar5 = 'V';
          iVar4 = iVar4 + 1;
        }
        else {
          iVar4 = iVar4 + 1;
        }
      }
      puVar14 = (undefined1 *)0x680000;
      iVar4 = save_index(local_a8,"new",pbVar16);
      if ((iVar4 != 0) && (iVar4 = rotate_index(local_a8,"new","old"), iVar4 != 0))
      goto LAB_004788b0;
LAB_004780e4:
      bVar20 = true;
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar1);
    }
    else {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-passin, -passout arguments only valid with one user.\n");
LAB_00477bf0:
      puVar14 = methods_sockp + 0x10;
      if (srp_usage._0_4_ != 0) {
        puVar14 = srp_usage;
        do {
          puVar14 = (undefined1 *)((int)puVar14 + 4);
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"%s");
        } while (*(int *)puVar14 != 0);
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1," -rand file%cfile%c...\n",0x3a,0x3a)
      ;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,
                 "                 load the file (or the files in the directory) into\n");
      uVar10 = *(undefined4 *)puVar1;
      pcVar11 = "                 the random number generator\n";
LAB_00477c70:
      (*(code *)PTR_BIO_printf_006a6e38)(uVar10,pcVar11);
LAB_00477c7c:
      ppbVar23 = (byte **)0x0;
      ppbVar21 = (byte **)0x0;
      pbVar16 = (byte *)0x0;
LAB_00477c8c:
      bVar20 = true;
      ppbVar26 = ppbVar24;
joined_r0x0047918c:
      ppbVar24 = ppbVar7;
      if (iVar25 != 0) {
LAB_00478278:
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar1,"SRP terminating with code %d.\n",bVar20);
      }
      if (ppbVar23 != (byte **)0x0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)(ppbVar23);
      }
joined_r0x00478ba8:
      if (bVar20 != false) goto LAB_004780e4;
    }
    if (ppbVar21 != (byte **)0x0) {
      app_RAND_write_file(ppbVar21,*(undefined4 *)puVar1);
    }
    if (conf != 0) {
      (*(code *)PTR_NCONF_free_006a6e6c)();
    }
    if (pbVar16 != (byte *)0x0) {
      free_index(pbVar16);
    }
    (*(code *)PTR_OBJ_cleanup_006a6e98)();
    if (local_2c == *(int *)puVar3) {
      return bVar20;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00479174:
    piVar15 = (int *)puVar14;
    if (local_5c != 0x2d) goto LAB_00477b48;
LAB_00478298:
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"unknown option %s\n",pbVar16);
    iVar4 = local_9c * 2 + local_a4;
    iVar17 = local_9c + local_ac + local_a4 + local_98;
    bVar20 = true;
  } while( true );
}

