
uint srp_main(int param_1,int param_2)

{
  bool bVar1;
  BIO *pBVar2;
  int iVar3;
  char **ppcVar4;
  OPENSSL_STRING *value;
  BIO_METHOD *type;
  void *pvVar5;
  size_t sVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  char **ppcVar12;
  undefined1 *puVar13;
  uint uVar14;
  char *pcVar15;
  char *pcVar16;
  char *pcVar17;
  int in_GS_OFFSET;
  bool bVar18;
  bool bVar19;
  byte bVar20;
  char *pcVar21;
  char *pcVar22;
  int local_84;
  char *local_80;
  BIO *local_7c;
  char **local_78;
  char *local_74;
  int local_70;
  int local_6c;
  int local_68;
  char *local_64;
  char *local_60;
  char *local_5c;
  char *local_58;
  int local_54;
  void *local_50;
  int local_48;
  int local_44;
  char *local_40;
  undefined local_3c [4];
  char *local_38;
  OPENSSL_STRING local_34;
  OPENSSL_STRING local_30;
  char *local_2c;
  char *local_28;
  char *local_24;
  int local_20;
  
  bVar20 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_48 = 0;
  local_44 = 0;
  local_40 = (char *)0xffffffff;
  signal(0xd,(__sighandler_t)0x1);
  conf = (CONF *)0x0;
  section = (char *)0x0;
  if (bio_err == (BIO *)0x0) {
    type = BIO_s_file();
    bio_err = BIO_new(type);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  ppcVar12 = (char **)(param_2 + 4);
  param_1 = param_1 + -1;
  bVar18 = param_1 == 0;
  if (0 < param_1) {
    local_58 = (char *)0x0;
    local_74 = (char *)0x0;
    local_80 = (char *)0x0;
    local_84 = 0;
    local_60 = (char *)0x0;
    local_5c = (char *)0x0;
    local_64 = (char *)0x0;
    local_78 = (char **)0x0;
    local_6c = 0;
    local_68 = 0;
    local_7c = (BIO *)0x0;
    local_70 = 0;
LAB_080934bd:
    pcVar22 = *ppcVar12;
    iVar10 = 9;
    pcVar21 = pcVar22;
    pcVar17 = "-verbose";
    do {
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
      bVar18 = *pcVar21 == *pcVar17;
      pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
      pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
    } while (bVar18);
    if (bVar18) {
      local_84 = local_84 + 1;
    }
    else {
      iVar10 = 8;
      pcVar21 = pcVar22;
      pcVar17 = "-config";
      do {
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        bVar18 = *pcVar21 == *pcVar17;
        pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
        pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
      } while (bVar18);
      if (bVar18) {
        if (param_1 == 1) {
LAB_08093b6a:
          param_1 = param_1 + -1;
          bVar20 = 1;
LAB_08093b6f:
          BIO_printf(bio_err,"unknown option %s\n",pcVar22);
          iVar10 = local_70 + local_68 + local_6c + (int)local_7c;
          bVar19 = (bool)(local_6c + local_68 * 2 == 1 & bVar20);
          bVar1 = true;
          if (local_80 == (char *)0x0 || local_74 == (char *)0x0) goto LAB_0809353b;
          goto LAB_08093bc6;
        }
        local_80 = ppcVar12[1];
        ppcVar12 = ppcVar12 + 2;
        param_1 = param_1 + -2;
        goto joined_r0x080934fc;
      }
      iVar10 = 6;
      pcVar21 = pcVar22;
      pcVar17 = "-name";
      do {
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        bVar18 = *pcVar21 == *pcVar17;
        pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
        pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
      } while (bVar18);
      if (bVar18) {
        if (param_1 + -1 == 0) goto LAB_08093b6a;
        section = ppcVar12[1];
        ppcVar12 = ppcVar12 + 1;
        param_1 = param_1 + -1;
      }
      else {
        iVar10 = 10;
        pcVar21 = pcVar22;
        pcVar17 = "-srpvfile";
        do {
          if (iVar10 == 0) break;
          iVar10 = iVar10 + -1;
          bVar18 = *pcVar21 == *pcVar17;
          pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
          pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
        } while (bVar18);
        if (bVar18) {
          if (param_1 + -1 == 0) goto LAB_08093b6a;
          local_74 = ppcVar12[1];
          ppcVar12 = ppcVar12 + 1;
          param_1 = param_1 + -1;
        }
        else {
          iVar10 = 5;
          pcVar21 = pcVar22;
          pcVar17 = "-add";
          do {
            if (iVar10 == 0) break;
            iVar10 = iVar10 + -1;
            bVar18 = *pcVar21 == *pcVar17;
            pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
            pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
          } while (bVar18);
          if (bVar18) {
            local_70 = 1;
          }
          else {
            iVar10 = 8;
            pcVar21 = pcVar22;
            pcVar17 = "-delete";
            do {
              if (iVar10 == 0) break;
              iVar10 = iVar10 + -1;
              bVar18 = *pcVar21 == *pcVar17;
              pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
              pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
            } while (bVar18);
            if (bVar18) {
              local_68 = 1;
            }
            else {
              iVar10 = 8;
              pcVar21 = pcVar22;
              pcVar17 = "-modify";
              do {
                if (iVar10 == 0) break;
                iVar10 = iVar10 + -1;
                bVar18 = *pcVar21 == *pcVar17;
                pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
                pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
              } while (bVar18);
              if (bVar18) {
                local_6c = 1;
              }
              else {
                iVar10 = 6;
                pcVar21 = pcVar22;
                pcVar17 = "-list";
                do {
                  if (iVar10 == 0) break;
                  iVar10 = iVar10 + -1;
                  bVar18 = *pcVar21 == *pcVar17;
                  pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
                  pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
                } while (bVar18);
                if (bVar18) {
                  local_7c = (BIO *)0x1;
                }
                else {
                  bVar18 = *pcVar22 == '-';
                  if ((((bVar18) && (bVar18 = pcVar22[1] == 'g', bVar18)) &&
                      (bVar18 = pcVar22[2] == 'n', bVar18)) && (bVar18 = pcVar22[3] == '\0', bVar18)
                     ) {
                    if (param_1 + -1 == 0) goto LAB_08093b6a;
                    local_5c = ppcVar12[1];
                    ppcVar12 = ppcVar12 + 1;
                    param_1 = param_1 + -1;
                    goto LAB_080934b5;
                  }
                  iVar10 = 10;
                  pcVar21 = pcVar22;
                  pcVar17 = "-userinfo";
                  do {
                    if (iVar10 == 0) break;
                    iVar10 = iVar10 + -1;
                    bVar18 = *pcVar21 == *pcVar17;
                    pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
                    pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
                  } while (bVar18);
                  if (bVar18) {
                    if (param_1 + -1 == 0) goto LAB_08093b6a;
                    local_60 = ppcVar12[1];
                    ppcVar12 = ppcVar12 + 1;
                    param_1 = param_1 + -1;
                  }
                  else {
                    iVar10 = 8;
                    pcVar21 = pcVar22;
                    pcVar17 = "-passin";
                    do {
                      if (iVar10 == 0) break;
                      iVar10 = iVar10 + -1;
                      bVar18 = *pcVar21 == *pcVar17;
                      pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
                      pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
                    } while (bVar18);
                    if (bVar18) {
                      if (param_1 + -1 == 0) goto LAB_08093b6a;
                      local_78 = (char **)ppcVar12[1];
                      ppcVar12 = ppcVar12 + 1;
                      param_1 = param_1 + -1;
                    }
                    else {
                      iVar10 = 9;
                      pcVar21 = pcVar22;
                      pcVar17 = "-passout";
                      do {
                        if (iVar10 == 0) break;
                        iVar10 = iVar10 + -1;
                        bVar18 = *pcVar21 == *pcVar17;
                        pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
                        pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
                      } while (bVar18);
                      if (bVar18) {
                        if (param_1 + -1 == 0) goto LAB_08093b6a;
                        local_64 = ppcVar12[1];
                        ppcVar12 = ppcVar12 + 1;
                        param_1 = param_1 + -1;
                      }
                      else {
                        iVar10 = 8;
                        pcVar21 = pcVar22;
                        pcVar17 = "-engine";
                        do {
                          if (iVar10 == 0) break;
                          iVar10 = iVar10 + -1;
                          bVar18 = *pcVar21 == *pcVar17;
                          pcVar21 = pcVar21 + (uint)bVar20 * -2 + 1;
                          pcVar17 = pcVar17 + (uint)bVar20 * -2 + 1;
                        } while (bVar18);
                        if (!bVar18) {
                          if (*pcVar22 == '-') {
                            bVar20 = 0;
                            goto LAB_08093b6f;
                          }
                          bVar19 = false;
                          bVar18 = local_74 != (char *)0x0 && local_80 != (char *)0x0;
                          iVar10 = local_70 + local_68 + local_6c + (int)local_7c;
                          goto LAB_08093533;
                        }
                        if (param_1 + -1 == 0) goto LAB_08093b6a;
                        local_58 = ppcVar12[1];
                        ppcVar12 = ppcVar12 + 1;
                        param_1 = param_1 + -1;
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
LAB_080934b5:
    ppcVar12 = ppcVar12 + 1;
    param_1 = param_1 + -1;
joined_r0x080934fc:
    bVar18 = param_1 == 0;
    if (bVar18) goto LAB_080934fe;
    goto LAB_080934bd;
  }
  bVar19 = false;
  local_58 = (char *)0x0;
  local_74 = (char *)0x0;
  local_80 = (char *)0x0;
  local_84 = 0;
  local_60 = (char *)0x0;
  local_5c = (char *)0x0;
  local_64 = (char *)0x0;
  local_78 = (char **)0x0;
  local_6c = 0;
  local_68 = 0;
  local_7c = (BIO *)0x0;
  local_70 = 0;
LAB_08093540:
  BIO_printf(bio_err,"Exactly one of the options -add, -delete, -modify -list must be specified.\n")
  ;
  bVar1 = true;
  goto LAB_0809355b;
code_r0x08093a78:
  BIO_printf(pBVar2,"failed to update srpvfile\n");
  BIO_printf(pBVar2,"TXT_DB error number %ld\n",*(undefined4 *)(*(int *)(iVar10 + 4) + 0x10));
  CRYPTO_free(value);
LAB_08093aa9:
  if (local_2c != (char *)0x0) {
LAB_080945a2:
    CRYPTO_free(local_2c);
  }
  if (local_28 != (char *)0x0) {
    CRYPTO_free(local_28);
  }
  if (local_24 != (char *)0x0) {
    CRYPTO_free(local_24);
  }
  if (local_38 != (char *)0x0) {
    CRYPTO_free(local_38);
  }
  if (local_34 != (OPENSSL_STRING)0x0) {
    CRYPTO_free(local_34);
  }
  if (local_30 != (OPENSSL_STRING)0x0) {
    CRYPTO_free(local_30);
  }
LAB_08093b15:
  uVar14 = 1;
LAB_08093b1a:
  if (local_54 == 0) {
    pcVar21 = (char *)0x0;
    goto LAB_08093604;
  }
  if (local_84 != 0) {
LAB_08093b32:
    pcVar21 = (char *)0x0;
    BIO_printf(bio_err,"User errors %d.\n",local_54);
    goto LAB_08093b4e;
  }
  goto LAB_08093620;
LAB_08094400:
  for (; iVar8 = sk_num(*(_STACK **)(*(int *)(iVar10 + 4) + 4)), iVar3 < iVar8; iVar3 = iVar3 + 1) {
    ppcVar12 = (char **)sk_value(*(_STACK **)(*(int *)(iVar10 + 4) + 4),iVar3);
    if (**ppcVar12 == 'v') {
      **ppcVar12 = 'V';
    }
  }
  iVar3 = save_index(local_74,&DAT_081eaee6,iVar10);
  if ((iVar3 != 0) && (iVar3 = rotate_index(local_74,&DAT_081eaee6,"old"), iVar3 != 0)) {
LAB_080943ea:
    uVar14 = (uint)(local_54 != 0);
    goto LAB_08093b1a;
  }
  goto LAB_08093c20;
LAB_080934fe:
  bVar18 = local_80 != (char *)0x0 && local_74 != (char *)0x0;
  iVar10 = local_70 + local_68 + local_6c + (int)local_7c;
  bVar19 = local_6c + local_68 * 2 == 1;
LAB_08093533:
  bVar1 = false;
  if (bVar18) {
LAB_08093bc6:
    BIO_printf(bio_err,"-dbfile and -configfile cannot be specified together.\n");
    bVar1 = true;
  }
LAB_0809353b:
  if (iVar10 != 1) goto LAB_08093540;
LAB_0809355b:
  if (bVar19) {
    BIO_printf(bio_err,"Need at least one user for options -add, -delete, -modify. \n");
    if (((local_48 != 0) || (local_44 != 0)) && (param_1 != 1)) goto LAB_080938d9;
LAB_08093585:
    puVar13 = srp_usage;
    iVar10 = srp_usage._0_4_;
    while (iVar10 != 0) {
      puVar13 = (undefined1 *)((int)puVar13 + 4);
      BIO_printf(bio_err,"%s",iVar10);
      iVar10 = *(int *)puVar13;
    }
    pcVar22 = (char *)0x3a;
    BIO_printf(bio_err," -rand file%cfile%c...\n",0x3a,0x3a);
    BIO_printf(bio_err,"                 load the file (or the files in the directory) into\n");
    pcVar21 = "                 the random number generator\n";
LAB_080935e5:
    BIO_printf(bio_err,pcVar21,pcVar22);
LAB_080935f3:
    pcVar21 = (char *)0x0;
    local_64 = (char *)0x0;
    iVar10 = 0;
  }
  else {
    if (((local_48 != 0) || (local_44 != 0)) && (param_1 != 1)) {
LAB_080938d9:
      BIO_printf(bio_err,"-passin, -passout arguments only valid with one user.\n");
      goto LAB_08093585;
    }
    if (bVar1) goto LAB_08093585;
    ERR_load_crypto_strings();
    pcVar22 = (char *)0x0;
    setup_engine(bio_err,local_58,0);
    iVar10 = app_passwd(bio_err,local_78,local_64,&local_48,&local_44);
    if (iVar10 == 0) {
      pcVar21 = "Error getting passwords\n";
      goto LAB_080935e5;
    }
    if (local_74 == (char *)0x0) {
      if ((local_80 == (char *)0x0) &&
         (pcVar21 = getenv("OPENSSL_CONF"), local_80 = pcVar21, pcVar21 == (char *)0x0)) {
        local_80 = getenv("SSLEAY_CONF");
        if (local_80 == (char *)0x0) {
          pcVar17 = X509_get_default_cert_area();
          sVar6 = strlen(pcVar17);
          sVar6 = sVar6 + 0xd;
          pcVar22 = (char *)0x1bd;
          pcVar21 = (char *)CRYPTO_malloc(sVar6,"srp.c",0x1bd);
          if (pcVar21 == (char *)0x0) {
            pcVar21 = "Out of memory\n";
            goto LAB_080935e5;
          }
          BUF_strlcpy(pcVar21,pcVar17,sVar6);
          BUF_strlcat(pcVar21,"/",sVar6);
          BUF_strlcat(pcVar21,"openssl.cnf",sVar6);
          local_80 = pcVar21;
        }
      }
      else {
        pcVar21 = (char *)0x0;
      }
      if (local_84 != 0) {
        BIO_printf(bio_err,"Using configuration from %s\n",local_80);
      }
      conf = NCONF_new((CONF_METHOD *)0x0);
      iVar10 = NCONF_load(conf,local_80,(long *)&local_40);
      if (iVar10 < 1) {
        if ((int)local_40 < 1) {
          pcVar22 = "error loading the config file \'%s\'\n";
        }
        else {
          pcVar22 = "error on line %ld of config file \'%s\'\n";
          local_80 = local_40;
        }
        iVar10 = 0;
        BIO_printf(bio_err,pcVar22,local_80);
        local_64 = (char *)0x0;
        goto LAB_080935ff;
      }
      if (pcVar21 != (char *)0x0) {
        CRYPTO_free(pcVar21);
      }
      iVar10 = load_config(bio_err,conf);
      if (iVar10 != 0) {
        if (section == (char *)0x0) {
          if (local_84 != 0) {
            BIO_printf(bio_err,"trying to read default_srp in \" BASE_SECTION \"\n");
          }
          section = NCONF_get_string(conf,"srp","default_srp");
          if (section == (char *)0x0) {
            pcVar22 = "srp";
            pcVar21 = "variable lookup failed for %s::%s\n";
            goto LAB_080935e5;
          }
        }
        local_64 = (char *)0x0;
        if (conf != (CONF *)0x0) {
          local_64 = NCONF_get_string(conf,"srp","RANDFILE");
        }
        if (local_84 != 0) {
          BIO_printf(bio_err,"trying to read srpvfile in section \"%s\"\n",section);
        }
        pcVar22 = "srpvfile";
        local_74 = NCONF_get_string(conf,section,"srpvfile");
        if (local_74 != (char *)0x0) {
          if (local_64 == (char *)0x0) goto LAB_080937a3;
          pcVar22 = (char *)0x0;
          app_RAND_load_file(local_64,bio_err,0);
          goto LAB_080937b0;
        }
        pcVar21 = (char *)0x0;
        iVar10 = 0;
        BIO_printf(bio_err,"variable lookup failed for %s::%s\n",section,"srpvfile");
        goto LAB_080935ff;
      }
      goto LAB_080935f3;
    }
LAB_080937a3:
    ERR_clear_error();
    local_64 = (char *)0x0;
LAB_080937b0:
    if (local_84 != 0) {
      pcVar22 = local_74;
      BIO_printf(bio_err,"Trying to read SRP verifier file \"%s\"\n",local_74);
    }
    pcVar21 = (char *)0x0;
    iVar10 = load_index(local_74,local_3c);
    if (iVar10 != 0) {
      local_80 = (char *)0xffffffff;
      pcVar17 = (char *)0xffffffff;
      for (; iVar3 = sk_num(*(_STACK **)(*(int *)(iVar10 + 4) + 4)), (int)pcVar21 < iVar3;
          pcVar21 = pcVar21 + 1) {
        ppcVar4 = (char **)sk_value(*(_STACK **)(*(int *)(iVar10 + 4) + 4),(int)pcVar21);
        if (**ppcVar4 == 'I') {
          if ((((int)local_80 < 0) && (local_5c != (char *)0x0)) &&
             (iVar3 = strcmp(local_5c,ppcVar4[3]), iVar3 == 0)) {
            local_80 = pcVar21;
          }
          pBVar2 = bio_err;
          pcVar17 = pcVar21;
          if ((1 < local_84) && (-1 < (int)pcVar21)) {
            pvVar5 = sk_value(*(_STACK **)(*(int *)(iVar10 + 4) + 4),(int)pcVar21);
            BIO_printf(pBVar2,"%s \"%s\"\n","g N entry",*(undefined4 *)((int)pvVar5 + 0xc));
            pcVar15 = (char *)0x0;
            do {
              pcVar16 = pcVar15 + 1;
              pcVar22 = pcVar15;
              BIO_printf(bio_err,"  %d = \"%s\"\n",pcVar15,
                         *(undefined4 *)((int)pvVar5 + (int)pcVar15 * 4));
              pcVar15 = pcVar16;
            } while (pcVar16 != (char *)0x6);
          }
        }
      }
      if (local_84 == 0) {
        if ((int)local_80 < 0) {
LAB_080942e8:
          if ((0 < (int)pcVar17) && (iVar3 = SRP_get_default_gN(local_5c), iVar3 == 0)) {
            pcVar21 = (char *)0x0;
            BIO_printf(bio_err,"No g and N value for index \"%s\"\n",local_5c);
            goto LAB_080935ff;
          }
          if ((local_84 != 0) &&
             (BIO_printf(bio_err,"Database has no g N information.\n"), local_84 != 1)) {
            local_50 = (void *)0x0;
            goto LAB_0809452d;
          }
          local_50 = (void *)0x0;
        }
        else {
          local_50 = sk_value(*(_STACK **)(*(int *)(iVar10 + 4) + 4),(int)local_80);
        }
      }
      else {
        BIO_printf(bio_err,"Database initialised\n",pcVar22);
        if ((int)local_80 < 0) goto LAB_080942e8;
        local_50 = sk_value(*(_STACK **)(*(int *)(iVar10 + 4) + 4),(int)local_80);
        pBVar2 = bio_err;
        if (local_84 == 1) goto LAB_08093f5b;
        pvVar5 = sk_value(*(_STACK **)(*(int *)(iVar10 + 4) + 4),(int)local_80);
        BIO_printf(pBVar2,"%s \"%s\"\n","Default g and N",*(undefined4 *)((int)pvVar5 + 0xc));
        pcVar21 = (char *)0x0;
        do {
          pcVar17 = pcVar21 + 1;
          pcVar22 = pcVar21;
          BIO_printf(bio_err,"  %d = \"%s\"\n",pcVar21,
                     *(undefined4 *)((int)pvVar5 + (int)pcVar21 * 4));
          pcVar21 = pcVar17;
        } while (pcVar17 != (char *)0x6);
LAB_0809452d:
        BIO_printf(bio_err,"Starting user processing\n",pcVar22);
      }
LAB_08093f5b:
      if (param_1 < 1) {
        pcVar21 = (char *)0x0;
        local_78 = ppcVar12;
      }
      else {
        pcVar21 = *ppcVar12;
        local_78 = ppcVar12 + 1;
      }
      bVar18 = false;
      local_54 = 0;
LAB_08093f80:
      if ((local_7c == (BIO *)0x0) && (pcVar21 == (char *)0x0)) {
        if (local_84 == 0) {
          iVar3 = 0;
          if (bVar18) goto LAB_08094400;
          goto LAB_080943ea;
        }
        BIO_printf(bio_err,"User procession done.\n",pcVar22);
        if (!bVar18) goto LAB_080943ea;
        for (iVar3 = 0; iVar8 = sk_num(*(_STACK **)(*(int *)(iVar10 + 4) + 4)), iVar3 < iVar8;
            iVar3 = iVar3 + 1) {
          ppcVar12 = (char **)sk_value(*(_STACK **)(*(int *)(iVar10 + 4) + 4),iVar3);
          if (**ppcVar12 == 'v') {
            **ppcVar12 = 'V';
            print_user_part_3(local_84);
          }
        }
        BIO_printf(bio_err,"Trying to update srpvfile.\n");
        iVar3 = save_index(local_74,&DAT_081eaee6,iVar10);
        if (iVar3 != 0) {
          BIO_printf(bio_err,"Temporary srpvfile created.\n");
          iVar3 = rotate_index(local_74,&DAT_081eaee6,"old");
          if (iVar3 == 0) goto LAB_08093b15;
          BIO_printf(bio_err,"srpvfile updated.\n");
          goto LAB_080943ea;
        }
        if (local_54 == 0) {
          pcVar21 = (char *)0x0;
          uVar14 = 1;
          goto LAB_08093b4e;
        }
LAB_080943ca:
        uVar14 = 1;
        goto LAB_08093b32;
      }
      if ((1 < local_84) && (pcVar21 != (char *)0x0)) {
        pcVar22 = pcVar21;
        BIO_printf(bio_err,"Processing user \"%s\"\n",pcVar21);
      }
      iVar3 = get_index();
      if (iVar3 < 0) {
LAB_08094077:
        if (local_7c == (BIO *)0x0) goto LAB_08093fea;
        if (pcVar21 == (char *)0x0) {
          BIO_printf(bio_err,"List all users\n",pcVar22);
          for (iVar3 = 0; iVar8 = sk_num(*(_STACK **)(*(int *)(iVar10 + 4) + 4)), iVar3 < iVar8;
              iVar3 = iVar3 + 1) {
            print_user_part_3(1);
          }
          goto LAB_080941dd;
        }
        if (-1 < iVar3) goto LAB_08094040;
        BIO_printf(bio_err,"user \"%s\" does not exist, ignored. t\n",pcVar21);
        local_54 = local_54 + 1;
        pcVar22 = pcVar21;
        if (0 < param_1 + -1) goto LAB_08094047;
LAB_080940b8:
        param_1 = param_1 + -1;
        pcVar21 = (char *)0x0;
        local_7c = (BIO *)0x0;
        goto LAB_08093f80;
      }
      if ((0 < local_84) || (local_7c != (BIO *)0x0)) {
        print_user_part_3(1);
        goto LAB_08094077;
      }
LAB_08093fea:
      if (local_70 == 0) {
        if (local_6c == 0) {
          local_7c = (BIO *)0x0;
          if (local_68 != 0) {
            if (iVar3 < 0) {
              BIO_printf(bio_err,"user \"%s\" does not exist, operation ignored. t\n",pcVar21);
              local_54 = local_54 + 1;
              local_7c = (BIO *)local_6c;
              pcVar22 = pcVar21;
            }
            else {
              puVar7 = (undefined4 *)sk_value(*(_STACK **)(*(int *)(iVar10 + 4) + 4),iVar3);
              BIO_printf(bio_err,"user \"%s\" revoked. t\n",pcVar21);
              bVar18 = true;
              *(undefined *)*puVar7 = 0x52;
              local_7c = (BIO *)local_6c;
              pcVar22 = pcVar21;
            }
          }
          goto LAB_08094040;
        }
        if (iVar3 < 0) {
          pcVar22 = "user \"%s\" does not exist, operation ignored.\n";
        }
        else {
          ppcVar12 = (char **)sk_value(*(_STACK **)(*(int *)(iVar10 + 4) + 4),iVar3);
          if (**ppcVar12 != 'v') {
            if (**ppcVar12 == 'V') {
              if (local_84 != 0) {
                pcVar22 = pcVar21;
                BIO_printf(bio_err,"Verifying password for user \"%s\"\n",pcVar21);
              }
              iVar8 = get_index();
              if (iVar8 < 0) {
LAB_080945c0:
                local_58 = (char *)0x0;
                pcVar17 = ppcVar12[4];
                local_7c = bio_err;
              }
              else {
                pvVar5 = sk_value(*(_STACK **)(*(int *)(iVar10 + 4) + 4),iVar3);
                local_7c = bio_err;
                if (pvVar5 == (void *)0x0) goto LAB_080945c0;
                local_58 = *(char **)((int)pvVar5 + 4);
                pcVar17 = *(char **)((int)pvVar5 + 8);
              }
              bio_err = local_7c;
              iVar3 = srp_verify_user(pcVar17,local_58,local_48,local_7c,local_84);
              if (iVar3 != 0) goto LAB_0809410f;
              BIO_printf(bio_err,"Invalid password for user \"%s\", operation abandoned.\n",pcVar21)
              ;
LAB_080943be:
              local_54 = local_54 + 1;
              if (local_84 == 0) goto LAB_08093c20;
              goto LAB_080943ca;
            }
LAB_0809410f:
            if (local_84 != 0) {
              pcVar22 = pcVar21;
              BIO_printf(bio_err,"Password for user \"%s\" ok.\n",pcVar21);
            }
            if (local_50 == (void *)0x0) {
              uVar11 = 0;
              uVar9 = 0;
            }
            else {
              uVar11 = *(undefined4 *)((int)local_50 + 4);
              uVar9 = *(undefined4 *)((int)local_50 + 8);
            }
            pcVar17 = (char *)srp_create_user(uVar9,uVar11,local_44,bio_err,local_84);
            if (pcVar17 == (char *)0x0) {
              BIO_printf(bio_err,
                         "Cannot create srp verifier for user \"%s\", operation abandoned.\n",
                         pcVar21);
              goto LAB_080943be;
            }
            **ppcVar12 = 'v';
            pcVar21 = BUF_strdup(pcVar17);
            ppcVar12[4] = pcVar21;
            if ((((ppcVar12[3] == (char *)0x0) || (pcVar21 == (char *)0x0)) ||
                (*ppcVar12 == (char *)0x0)) ||
               ((ppcVar12[1] == (char *)0x0 || (ppcVar12[2] == (char *)0x0)))) goto LAB_08093b15;
            if (local_60 == (char *)0x0) goto LAB_080941d5;
            pcVar21 = BUF_strdup(local_60);
            ppcVar12[5] = pcVar21;
            if (pcVar21 == (char *)0x0) goto LAB_08093b15;
            goto LAB_080941d5;
          }
          pcVar22 = "user \"%s\" already updated, operation ignored.\n";
        }
        BIO_printf(bio_err,pcVar22,pcVar21);
        local_54 = local_54 + 1;
        local_7c = (BIO *)0x0;
        pcVar22 = pcVar21;
      }
      else {
        if (-1 < iVar3) {
          puVar7 = (undefined4 *)sk_value(*(_STACK **)(*(int *)(iVar10 + 4) + 4),iVar3);
          BIO_printf(bio_err,"user \"%s\" reactivated.\n",pcVar21);
          bVar18 = true;
          local_7c = (BIO *)0x0;
          *(undefined *)*puVar7 = 0x56;
          pcVar22 = pcVar21;
          goto LAB_08094040;
        }
        local_34 = (OPENSSL_STRING)0x0;
        local_30 = (OPENSSL_STRING)0x0;
        local_24 = (char *)0x0;
        if (local_50 == (void *)0x0) {
          uVar11 = 0;
          pcVar22 = local_5c;
        }
        else {
          uVar11 = *(undefined4 *)((int)local_50 + 4);
          pcVar22 = *(char **)((int)local_50 + 8);
        }
        pcVar22 = (char *)srp_create_user(pcVar22,uVar11,local_44,bio_err,local_84);
        if (pcVar22 == (char *)0x0) {
          BIO_printf(bio_err,"Cannot create srp verifier for user \"%s\", operation abandoned .\n",
                     pcVar21);
          local_54 = local_54 + 1;
          goto LAB_08093b15;
        }
        local_2c = BUF_strdup(pcVar21);
        local_38 = BUF_strdup("v");
        local_28 = BUF_strdup(pcVar22);
        if ((local_2c == (char *)0x0) || (local_28 == (char *)0x0)) goto LAB_08093aa9;
        if ((local_38 == (char *)0x0) ||
           ((local_34 == (OPENSSL_STRING)0x0 || (local_30 == (OPENSSL_STRING)0x0))))
        goto LAB_080945a2;
        if ((local_60 != (char *)0x0) && (local_24 = BUF_strdup(local_60), local_24 == (char *)0x0))
        goto LAB_08093aa9;
        pBVar2 = bio_err;
        pcVar22 = (char *)0xb5;
        value = (OPENSSL_STRING *)CRYPTO_malloc(0x1c,"srp.c",0xb5);
        if (value == (OPENSSL_STRING *)0x0) {
          BIO_printf(bio_err,"Memory allocation failure\n");
          goto LAB_08093aa9;
        }
        value[6] = (OPENSSL_STRING)0x0;
        *value = local_38;
        local_38 = (char *)0x0;
        value[1] = local_34;
        local_34 = (OPENSSL_STRING)0x0;
        value[2] = local_30;
        local_30 = (OPENSSL_STRING)0x0;
        value[3] = local_2c;
        local_2c = (char *)0x0;
        value[4] = local_28;
        local_28 = (char *)0x0;
        value[5] = local_24;
        local_24 = (char *)0x0;
        iVar3 = TXT_DB_insert(*(TXT_DB **)(iVar10 + 4),value);
        if (iVar3 == 0) goto code_r0x08093a78;
LAB_080941d5:
        bVar18 = true;
LAB_080941dd:
        local_7c = (BIO *)0x0;
      }
LAB_08094040:
      if (param_1 + -1 < 1) goto LAB_080940b8;
LAB_08094047:
      param_1 = param_1 + -1;
      pcVar21 = *local_78;
      local_78 = local_78 + 1;
      goto LAB_08093f80;
    }
  }
LAB_080935ff:
  uVar14 = 1;
LAB_08093604:
  if (local_84 != 0) {
LAB_08093b4e:
    BIO_printf(bio_err,"SRP terminating with code %d.\n",uVar14);
  }
  if (pcVar21 != (char *)0x0) {
    CRYPTO_free(pcVar21);
  }
LAB_08093620:
  if (uVar14 != 0) {
LAB_08093c20:
    uVar14 = 1;
    ERR_print_errors(bio_err);
  }
  if (local_64 != (char *)0x0) {
    app_RAND_write_file(local_64,bio_err);
  }
  if (conf != (CONF *)0x0) {
    NCONF_free(conf);
  }
  if (iVar10 != 0) {
    free_index(iVar10);
  }
  OBJ_cleanup();
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar14;
}

