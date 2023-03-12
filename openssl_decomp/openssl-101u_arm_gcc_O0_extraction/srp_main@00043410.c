
/* WARNING: Restarted to delay deadcode elimination for space: ram */

CONF * srp_main(int param_1,int param_2)

{
  char cVar1;
  BIO *pBVar2;
  int iVar3;
  char **ppcVar4;
  int iVar5;
  char **ppcVar6;
  undefined4 uVar7;
  BIO_METHOD *type;
  void *pvVar8;
  char *pcVar9;
  OPENSSL_STRING *value;
  size_t sVar10;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  int extraout_r1_03;
  int extraout_r1_04;
  int extraout_r1_05;
  int extraout_r1_06;
  char *pcVar11;
  int extraout_r1_07;
  int extraout_r1_08;
  int extraout_r1_09;
  int extraout_r1_10;
  undefined *puVar12;
  char *pcVar13;
  void *pvVar14;
  undefined **ppuVar15;
  CONF *pCVar16;
  CONF *pCVar17;
  CONF *pCVar18;
  CONF **ppCVar19;
  CONF *pCVar20;
  uint uVar21;
  CONF *pCVar22;
  CONF *pCVar23;
  uint uVar24;
  uint uVar25;
  undefined4 *puVar26;
  CONF *pCVar27;
  int iVar28;
  bool bVar29;
  bool bVar30;
  bool bVar31;
  CONF **local_80;
  CONF *local_78;
  CONF *local_74;
  CONF *local_70;
  CONF *local_6c;
  CONF *local_68;
  CONF *local_64;
  CONF *local_5c;
  CONF *local_58;
  CONF *local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined auStack_44 [4];
  char *local_40;
  OPENSSL_STRING local_3c;
  OPENSSL_STRING local_38;
  char *local_34;
  char *local_30;
  char *local_2c;
  
  local_48 = -1;
  local_50 = 0;
  local_4c = 0;
  signal(0xd,(__sighandler_t)0x1);
  conf = (CONF *)0x0;
  section = (CONF *)0x0;
  if (bio_err == (BIO *)0x0) {
    type = BIO_s_file();
    bio_err = BIO_new(type);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  param_1 = param_1 + -1;
  ppCVar19 = (CONF **)(param_2 + 4);
  if (param_1 < 1) {
    pCVar16 = (CONF *)0x0;
    local_74 = (CONF *)0x0;
    local_5c = (CONF *)0x0;
    local_54 = (CONF *)0x0;
    local_64 = (CONF *)0x0;
    local_70 = (CONF *)0x0;
    local_6c = (CONF *)0x0;
    local_68 = (CONF *)0x0;
    local_78 = (CONF *)0x0;
    pCVar22 = pCVar16;
    pCVar23 = pCVar16;
    pCVar20 = pCVar16;
    pCVar27 = pCVar16;
LAB_00043516:
    BIO_printf(bio_err,
               "Exactly one of the options -add, -delete, -modify -list must be specified.\n");
    pCVar18 = (CONF *)0x1;
  }
  else {
    pCVar23 = (CONF *)0x0;
    local_74 = (CONF *)0x0;
    pCVar22 = (CONF *)0x0;
    local_5c = (CONF *)0x0;
    local_54 = (CONF *)0x0;
    pCVar27 = (CONF *)0x0;
    local_64 = (CONF *)0x0;
    pCVar20 = (CONF *)0x0;
    local_70 = (CONF *)0x0;
    local_6c = (CONF *)0x0;
    local_68 = (CONF *)0x0;
    local_78 = (CONF *)0x0;
    do {
      while( true ) {
        pCVar16 = *ppCVar19;
        iVar3 = strcmp((char *)pCVar16,"-verbose");
        if (iVar3 == 0) {
          pCVar22 = (CONF *)((int)&pCVar22->meth + 1);
          iVar3 = extraout_r1;
          goto LAB_00043492;
        }
        iVar3 = strcmp((char *)pCVar16,"-config");
        if (iVar3 != 0) break;
        if (param_1 == 1) {
LAB_000438ba:
          param_1 = param_1 + -1;
LAB_000438c2:
          BIO_printf(bio_err,"unknown option %s\n",pCVar16);
          iVar28 = (int)&pCVar27->meth +
                   (int)&local_6c->meth + (int)&local_78->meth + (int)&local_68->meth;
          pCVar16 = (CONF *)((int)&local_6c->meth + (int)local_68 * 2);
          pCVar18 = (CONF *)0x1;
          if (local_74 != (CONF *)0x0 && pCVar20 != (CONF *)0x0) goto LAB_00043900;
          goto LAB_00043512;
        }
        param_1 = param_1 + -2;
        pCVar20 = ppCVar19[1];
        ppCVar19 = ppCVar19 + 2;
        iVar3 = extraout_r1_00;
        pCVar18 = local_78;
        pCVar17 = local_68;
        if (param_1 < 1) goto LAB_000434ea;
      }
      iVar3 = strcmp((char *)pCVar16,"-name");
      if (iVar3 == 0) {
        if (param_1 + -1 != 0) {
          section = ppCVar19[1];
          ppCVar19 = ppCVar19 + 1;
          iVar3 = extraout_r1_01;
          param_1 = param_1 + -1;
          goto LAB_00043492;
        }
        goto LAB_000438ba;
      }
      iVar3 = strcmp((char *)pCVar16,"-srpvfile");
      if (iVar3 != 0) {
        iVar3 = strcmp((char *)pCVar16,"-add");
        if (iVar3 == 0) {
          local_78 = (CONF *)0x1;
          iVar3 = extraout_r1_03;
          goto LAB_00043492;
        }
        iVar3 = strcmp((char *)pCVar16,"-delete");
        if (iVar3 == 0) {
          local_68 = (CONF *)0x1;
          iVar3 = extraout_r1_04;
          goto LAB_00043492;
        }
        iVar3 = strcmp((char *)pCVar16,"-modify");
        if (iVar3 == 0) {
          local_6c = (CONF *)0x1;
          iVar3 = extraout_r1_05;
          goto LAB_00043492;
        }
        iVar28 = strcmp((char *)pCVar16,"-list");
        iVar3 = extraout_r1_06;
        if (iVar28 == 0) {
          pCVar27 = (CONF *)0x1;
          goto LAB_00043492;
        }
        cVar1 = *(char *)&pCVar16->meth;
        if ((((cVar1 == '-') && (*(char *)((int)&pCVar16->meth + 1) == 'g')) &&
            (*(char *)((int)&pCVar16->meth + 2) == 'n')) &&
           (*(char *)((int)&pCVar16->meth + 3) == '\0')) {
          if (param_1 + -1 != 0) {
            local_54 = ppCVar19[1];
            ppCVar19 = ppCVar19 + 1;
            param_1 = param_1 + -1;
            goto LAB_00043492;
          }
          goto LAB_000438ba;
        }
        iVar3 = strcmp((char *)pCVar16,"-userinfo");
        if (iVar3 == 0) {
          if (param_1 + -1 != 0) {
            local_5c = ppCVar19[1];
            ppCVar19 = ppCVar19 + 1;
            iVar3 = extraout_r1_07;
            param_1 = param_1 + -1;
            goto LAB_00043492;
          }
          goto LAB_000438ba;
        }
        iVar3 = strcmp((char *)pCVar16,"-passin");
        if (iVar3 == 0) {
          if (param_1 + -1 != 0) {
            local_70 = ppCVar19[1];
            ppCVar19 = ppCVar19 + 1;
            iVar3 = extraout_r1_08;
            param_1 = param_1 + -1;
            goto LAB_00043492;
          }
          goto LAB_000438ba;
        }
        iVar3 = strcmp((char *)pCVar16,"-passout");
        if (iVar3 == 0) {
          if (param_1 + -1 != 0) {
            local_64 = ppCVar19[1];
            ppCVar19 = ppCVar19 + 1;
            iVar3 = extraout_r1_09;
            param_1 = param_1 + -1;
            goto LAB_00043492;
          }
          goto LAB_000438ba;
        }
        iVar28 = strcmp((char *)pCVar16,"-engine");
        iVar3 = extraout_r1_10;
        if (iVar28 == 0) {
          if (param_1 + -1 != 0) {
            pCVar23 = ppCVar19[1];
            ppCVar19 = ppCVar19 + 1;
            param_1 = param_1 + -1;
            goto LAB_00043492;
          }
          goto LAB_000438ba;
        }
        pCVar18 = local_68;
        pCVar17 = local_78;
        if (cVar1 == '-') goto LAB_000438c2;
        break;
      }
      if (param_1 + -1 == 0) goto LAB_000438ba;
      local_74 = ppCVar19[1];
      ppCVar19 = ppCVar19 + 1;
      iVar3 = extraout_r1_02;
      param_1 = param_1 + -1;
LAB_00043492:
      param_1 = param_1 + -1;
      ppCVar19 = ppCVar19 + 1;
      pCVar18 = local_78;
      pCVar17 = local_68;
    } while (0 < param_1);
LAB_000434ea:
    if (local_74 != (CONF *)0x0 && pCVar20 != (CONF *)0x0) {
      iVar3 = 1;
    }
    if (local_74 == (CONF *)0x0 || pCVar20 == (CONF *)0x0) {
      iVar3 = 0;
    }
    pCVar16 = (CONF *)((int)&local_6c->meth + (int)local_68 * 2);
    iVar28 = (int)&pCVar27->meth + (int)&local_6c->meth + (int)&pCVar17->meth + (int)&pCVar18->meth;
    pCVar18 = (CONF *)0x0;
    if (iVar3 != 0) {
LAB_00043900:
      pCVar18 = (CONF *)0x1;
      BIO_printf(bio_err,"-dbfile and -configfile cannot be specified together.\n");
    }
LAB_00043512:
    if (iVar28 != 1) goto LAB_00043516;
  }
  if ((pCVar16 == (CONF *)0x1) && (param_1 < 1)) {
    BIO_printf(bio_err,"Need at least one user for options -add, -delete, -modify. \n");
    pCVar18 = pCVar16;
  }
  if ((local_50 == 0 && local_4c == 0) || (param_1 == 1)) {
    if (pCVar18 != (CONF *)0x0) goto LAB_00043556;
    ERR_load_crypto_strings();
    setup_engine(bio_err,pCVar23,0);
    iVar3 = app_passwd(bio_err,local_70,local_64,&local_50,&local_4c);
    if (iVar3 == 0) {
      BIO_printf(bio_err,"Error getting passwords\n");
      local_58 = pCVar18;
      local_70 = pCVar18;
    }
    else if (local_74 == (CONF *)0x0) {
      pCVar18 = pCVar20;
      if ((pCVar20 == (CONF *)0x0) &&
         (pCVar18 = (CONF *)getenv("OPENSSL_CONF"), pCVar18 == (CONF *)0x0)) {
        pCVar23 = (CONF *)getenv("SSLEAY_CONF");
        local_58 = pCVar18;
        if (pCVar23 == (CONF *)0x0) {
          pcVar9 = X509_get_default_cert_area();
          sVar10 = strlen(pcVar9);
          sVar10 = sVar10 + 0xd;
          local_58 = (CONF *)CRYPTO_malloc(sVar10,"srp.c",0x1bd);
          if (local_58 == (CONF *)0x0) {
            BIO_printf(bio_err,"Out of memory\n");
            local_58 = pCVar18;
            local_70 = pCVar18;
            goto LAB_000435b8;
          }
          BUF_strlcpy((char *)local_58,pcVar9,sVar10);
          BUF_strlcat((char *)local_58,"/",sVar10);
          BUF_strlcat((char *)local_58,"openssl.cnf",sVar10);
          pCVar23 = local_58;
        }
      }
      else {
        local_58 = (CONF *)0x0;
        pCVar23 = pCVar18;
      }
      if (pCVar22 != (CONF *)0x0) {
        BIO_printf(bio_err,"Using configuration from %s\n",pCVar23);
      }
      conf = NCONF_new((CONF_METHOD *)0x0);
      iVar3 = NCONF_load(conf,(char *)pCVar23,&local_48);
      if (iVar3 < 1) {
        if (local_48 < 1) {
          local_70 = (CONF *)0x0;
          BIO_printf(bio_err,"error loading the config file \'%s\'\n",pCVar23);
          pCVar18 = (CONF *)0x0;
        }
        else {
          local_70 = (CONF *)0x0;
          BIO_printf(bio_err,"error on line %ld of config file \'%s\'\n",local_48,pCVar23);
          pCVar18 = local_70;
        }
      }
      else {
        if (local_58 != (CONF *)0x0) {
          CRYPTO_free(local_58);
        }
        pCVar18 = (CONF *)load_config(bio_err,conf);
        local_58 = pCVar18;
        local_70 = pCVar18;
        if (pCVar18 != (CONF *)0x0) {
          if (section == (CONF *)0x0) {
            if (pCVar22 != (CONF *)0x0) {
              BIO_printf(bio_err,"trying to read default_srp in \" BASE_SECTION \"\n");
            }
            pCVar18 = (CONF *)NCONF_get_string(conf,"srp","default_srp");
            section = pCVar18;
            if (pCVar18 == (CONF *)0x0) {
              BIO_printf(bio_err,"variable lookup failed for %s::%s\n","srp","default_srp");
              local_58 = pCVar18;
              local_70 = pCVar18;
              goto LAB_000435b8;
            }
          }
          local_70 = conf;
          if (conf != (CONF *)0x0) {
            local_70 = (CONF *)NCONF_get_string(conf,"srp","RANDFILE");
          }
          if (pCVar22 != (CONF *)0x0) {
            BIO_printf(bio_err,"trying to read srpvfile in section \"%s\"\n",section);
          }
          local_74 = (CONF *)NCONF_get_string(conf,(char *)section,"srpvfile");
          if (local_74 != (CONF *)0x0) {
            if (local_70 == (CONF *)0x0) goto LAB_000436ca;
            app_RAND_load_file(local_70,bio_err,0);
            goto LAB_000436d2;
          }
          BIO_printf(bio_err,"variable lookup failed for %s::%s\n",section,"srpvfile");
          pCVar18 = local_74;
          local_58 = local_74;
        }
      }
    }
    else {
LAB_000436ca:
      ERR_clear_error();
      local_70 = (CONF *)0x0;
LAB_000436d2:
      if (pCVar22 != (CONF *)0x0) {
        BIO_printf(bio_err,"Trying to read SRP verifier file \"%s\"\n",local_74);
      }
      pCVar18 = (CONF *)load_index(local_74,auStack_44);
      local_58 = pCVar18;
      if (pCVar18 != (CONF *)0x0) {
        uVar25 = 0xffffffff;
        uVar21 = 0xffffffff;
        for (uVar24 = 0; iVar3 = sk_num(*(_STACK **)((int)pCVar18->meth_data + 4)),
            (int)uVar24 < iVar3; uVar24 = uVar24 + 1) {
          ppcVar4 = (char **)sk_value(*(_STACK **)((int)pCVar18->meth_data + 4),uVar24);
          if (**ppcVar4 == 'I') {
            pCVar23 = local_54;
            if (local_54 != (CONF *)0x0) {
              pCVar23 = (CONF *)0x1;
            }
            if ((((uint)pCVar23 & uVar21 >> 0x1f) != 0) &&
               (iVar3 = strcmp((char *)local_54,ppcVar4[3]), iVar3 == 0)) {
              uVar21 = uVar24;
            }
            pBVar2 = bio_err;
            bVar29 = (int)uVar24 < 0;
            bVar31 = uVar24 == 0;
            bVar30 = bVar29;
            if (!bVar29) {
              bVar30 = (int)((int)&pCVar22[-1].data + 3) < 0;
              bVar31 = pCVar22 == (CONF *)0x1;
            }
            uVar25 = uVar24;
            if (!bVar31 && bVar30 == (!bVar29 && SBORROW4((int)pCVar22,1))) {
              pvVar8 = sk_value(*(_STACK **)((int)pCVar18->meth_data + 4),uVar24);
              puVar26 = (undefined4 *)((int)pvVar8 + -4);
              BIO_printf(pBVar2,"%s \"%s\"\n","g N entry",*(undefined4 *)((int)pvVar8 + 0xc));
              iVar3 = 0;
              do {
                puVar26 = puVar26 + 1;
                iVar28 = iVar3 + 1;
                BIO_printf(bio_err,"  %d = \"%s\"\n",iVar3,*puVar26);
                iVar3 = iVar28;
              } while (iVar28 != 6);
            }
          }
        }
        if (pCVar22 != (CONF *)0x0) {
          BIO_printf(bio_err,"Database initialised\n");
        }
        if ((int)uVar21 < 0) {
          if ((0 < (int)uVar25) &&
             (local_58 = (CONF *)SRP_get_default_gN(local_54), local_58 == (CONF *)0x0)) {
            BIO_printf(bio_err,"No g and N value for index \"%s\"\n",local_54);
            goto LAB_000435b8;
          }
          if ((pCVar22 == (CONF *)0x0) ||
             (BIO_printf(bio_err,"Database has no g N information.\n"), pCVar22 == (CONF *)0x1)) {
            local_64 = (CONF *)0x0;
            goto LAB_00043b2c;
          }
          local_64 = (CONF *)0x0;
        }
        else {
          local_64 = (CONF *)sk_value(*(_STACK **)((int)pCVar18->meth_data + 4),uVar21);
          pBVar2 = bio_err;
          if ((int)pCVar22 < 2) goto LAB_00043b2c;
          pvVar8 = sk_value(*(_STACK **)((int)pCVar18->meth_data + 4),uVar21);
          BIO_printf(pBVar2,"%s \"%s\"\n","Default g and N",*(undefined4 *)((int)pvVar8 + 0xc));
          iVar3 = 0;
          do {
            iVar28 = iVar3 + 1;
            BIO_printf(bio_err,"  %d = \"%s\"\n",iVar3);
            iVar3 = iVar28;
          } while (iVar28 != 6);
        }
        BIO_printf(bio_err,"Starting user processing\n");
LAB_00043b2c:
        if (param_1 < 1) {
          pCVar23 = (CONF *)0x0;
          local_80 = ppCVar19;
        }
        else {
          local_80 = ppCVar19 + 1;
          pCVar23 = *ppCVar19;
        }
        bVar30 = false;
        local_58 = (CONF *)0x0;
LAB_00043b46:
        pCVar20 = pCVar27;
        if (pCVar27 != (CONF *)0x0) {
          pCVar20 = (CONF *)0x1;
        }
        pCVar16 = pCVar23;
        if (pCVar23 != (CONF *)0x0) {
          pCVar16 = (CONF *)0x1;
        }
        uVar21 = (uint)pCVar16 | (uint)pCVar20;
        if (uVar21 == 0) {
          if (pCVar22 != (CONF *)0x0) {
            BIO_printf(bio_err,"User procession done.\n");
            if (bVar30) goto LAB_00044112;
            goto LAB_00043fac;
          }
          pCVar27 = pCVar22;
          if (bVar30) goto LAB_00043f6a;
          goto LAB_00043fac;
        }
        if (pCVar16 != (CONF *)0x0) {
          if (1 < (int)pCVar22) {
            BIO_printf(bio_err,"Processing user \"%s\"\n",pCVar23);
          }
          for (iVar3 = 0; iVar28 = sk_num(*(_STACK **)((int)pCVar18->meth_data + 4)), iVar3 < iVar28
              ; iVar3 = iVar3 + 1) {
            ppcVar4 = (char **)sk_value(*(_STACK **)((int)pCVar18->meth_data + 4),iVar3);
            if ((**ppcVar4 != 'I') && (iVar28 = strcmp((char *)pCVar23,ppcVar4[3]), iVar28 == 0)) {
              if (iVar3 < 0) goto LAB_00043bb4;
              pCVar16 = pCVar20;
              if (0 < (int)pCVar22) {
                pCVar16 = (CONF *)((uint)pCVar20 | 1);
              }
              if (pCVar16 == (CONF *)0x0) goto LAB_00043be0;
              print_user_part_4(pCVar18,bio_err,iVar3,1);
              goto LAB_00043bb4;
            }
          }
        }
        iVar3 = -1;
LAB_00043bb4:
        if (pCVar20 == (CONF *)0x0) {
LAB_00043be0:
          if (local_78 == (CONF *)0x0) {
            if (local_6c == (CONF *)0x0) {
              pCVar27 = local_68;
              if (local_68 != (CONF *)0x0) {
                pCVar27 = local_6c;
                if (iVar3 < 0) {
                  local_58 = (CONF *)((int)&local_58->meth + 1);
                  BIO_printf(bio_err,"user \"%s\" does not exist, operation ignored. t\n",pCVar23);
                }
                else {
                  bVar30 = true;
                  puVar26 = (undefined4 *)sk_value(*(_STACK **)((int)pCVar18->meth_data + 4),iVar3);
                  BIO_printf(bio_err,"user \"%s\" revoked. t\n",pCVar23);
                  *(undefined *)*puVar26 = 0x52;
                }
              }
            }
            else {
              if (iVar3 < 0) {
                pcVar9 = "user \"%s\" does not exist, operation ignored.\n";
              }
              else {
                ppcVar4 = (char **)sk_value(*(_STACK **)((int)pCVar18->meth_data + 4),iVar3);
                if (**ppcVar4 != 'v') {
                  if (**ppcVar4 == 'V') {
                    if (pCVar22 != (CONF *)0x0) {
                      BIO_printf(bio_err,"Verifying password for user \"%s\"\n",pCVar23);
                    }
                    pcVar9 = ppcVar4[4];
                    if (pcVar9 != (char *)0x0) {
                      for (iVar28 = 0; iVar5 = sk_num(*(_STACK **)((int)pCVar18->meth_data + 4)),
                          iVar28 < iVar5; iVar28 = iVar28 + 1) {
                        ppcVar6 = (char **)sk_value(*(_STACK **)((int)pCVar18->meth_data + 4),iVar28
                                                   );
                        if ((**ppcVar6 == 'I') && (iVar5 = strcmp(pcVar9,ppcVar6[3]), iVar5 == 0)) {
                          if (iVar28 < 0) {
                            pcVar9 = ppcVar4[4];
                            goto LAB_00043fc6;
                          }
                          pvVar8 = sk_value(*(_STACK **)((int)pCVar18->meth_data + 4),iVar3);
                          pcVar11 = ppcVar4[1];
                          pcVar13 = ppcVar4[2];
                          if (pvVar8 != (void *)0x0) {
                            pcVar9 = *(char **)((int)pvVar8 + 8);
                            uVar7 = *(undefined4 *)((int)pvVar8 + 4);
                            goto LAB_0004384c;
                          }
                          pcVar9 = ppcVar4[4];
                          goto LAB_00043fce;
                        }
                      }
                      pcVar9 = ppcVar4[4];
                    }
LAB_00043fc6:
                    pcVar11 = ppcVar4[1];
                    pcVar13 = ppcVar4[2];
LAB_00043fce:
                    uVar7 = 0;
LAB_0004384c:
                    iVar3 = srp_verify_user(pCVar23,pcVar11,pcVar13,pcVar9,uVar7,local_50,bio_err,
                                            pCVar22);
                    if (iVar3 != 0) goto LAB_00043c48;
                    BIO_printf(bio_err,"Invalid password for user \"%s\", operation abandoned.\n",
                               pCVar23);
                  }
                  else {
LAB_00043c48:
                    if (pCVar22 != (CONF *)0x0) {
                      BIO_printf(bio_err,"Password for user \"%s\" ok.\n",pCVar23);
                    }
                    pvVar8 = local_64;
                    pvVar14 = local_64;
                    if (local_64 != (CONF *)0x0) {
                      pvVar8 = *(void **)((int)local_64 + 4);
                      pvVar14 = *(void **)((int)local_64 + 8);
                    }
                    pcVar9 = (char *)srp_create_user(pCVar23,ppcVar4 + 1,ppcVar4 + 2,pvVar14,pvVar8,
                                                     local_4c,bio_err,pCVar22);
                    if (pcVar9 != (char *)0x0) {
                      **ppcVar4 = 'v';
                      pcVar9 = BUF_strdup(pcVar9);
                      ppcVar4[4] = pcVar9;
                      if ((((ppcVar4[3] != (char *)0x0) && (pcVar9 != (char *)0x0)) &&
                          (*ppcVar4 != (char *)0x0)) &&
                         ((ppcVar4[1] != (char *)0x0 && (ppcVar4[2] != (char *)0x0)))) {
                        if (local_5c == (CONF *)0x0) {
                          bVar30 = true;
                          pCVar27 = local_5c;
                        }
                        else {
                          pcVar9 = BUF_strdup((char *)local_5c);
                          ppcVar4[5] = pcVar9;
                          if (pcVar9 == (char *)0x0) goto LAB_0004409a;
                          bVar30 = true;
                          pCVar27 = (CONF *)0x0;
                        }
                        goto LAB_00043bc8;
                      }
LAB_0004409a:
                      pCVar27 = (CONF *)0x1;
                      goto LAB_00043eae;
                    }
                    BIO_printf(bio_err,
                               "Cannot create srp verifier for user \"%s\", operation abandoned.\n",
                               pCVar23);
                  }
                  local_58 = (CONF *)((int)&local_58->meth + 1);
                  pCVar27 = (CONF *)0x1;
                  goto LAB_0004388a;
                }
                pcVar9 = "user \"%s\" already updated, operation ignored.\n";
              }
              local_58 = (CONF *)((int)&local_58->meth + 1);
              BIO_printf(bio_err,pcVar9);
              pCVar27 = local_78;
            }
          }
          else if (iVar3 < 0) {
            local_3c = (OPENSSL_STRING)0x0;
            local_38 = (OPENSSL_STRING)0x0;
            local_2c = (char *)0x0;
            pvVar8 = local_64;
            pCVar27 = local_54;
            if (local_64 != (CONF *)0x0) {
              pvVar8 = *(void **)((int)local_64 + 4);
              pCVar27 = *(CONF **)((int)local_64 + 8);
            }
            pcVar9 = (char *)srp_create_user(pCVar23,&local_3c,&local_38,pCVar27,pvVar8,local_4c,
                                             bio_err,pCVar22);
            if (pcVar9 == (char *)0x0) {
              local_58 = (CONF *)((int)&local_58->meth + 1);
              BIO_printf(bio_err,
                         "Cannot create srp verifier for user \"%s\", operation abandoned .\n",
                         pCVar23);
              goto LAB_00043eaa;
            }
            local_34 = BUF_strdup((char *)pCVar23);
            local_40 = BUF_strdup("v");
            local_30 = BUF_strdup(pcVar9);
            if (local_34 == (char *)0x0) goto LAB_00043e84;
            if (((local_30 == (char *)0x0) || (local_40 == (char *)0x0)) ||
               ((local_3c == (OPENSSL_STRING)0x0 || (local_38 == (OPENSSL_STRING)0x0))))
            goto LAB_00044028;
            if ((local_5c != (CONF *)0x0) &&
               (local_2c = BUF_strdup((char *)local_5c), local_2c == (char *)0x0))
            goto LAB_00043e7a;
            pBVar2 = bio_err;
            value = (OPENSSL_STRING *)CRYPTO_malloc(0x1c,"srp.c",0xb5);
            if (value == (OPENSSL_STRING *)0x0) {
              BIO_printf(bio_err,"Memory allocation failure\n");
              goto LAB_00043e7a;
            }
            value[6] = (OPENSSL_STRING)0x0;
            *value = local_40;
            local_40 = (char *)0x0;
            value[1] = local_3c;
            local_3c = (OPENSSL_STRING)0x0;
            value[2] = local_38;
            local_38 = (OPENSSL_STRING)0x0;
            value[3] = local_34;
            local_34 = (char *)0x0;
            value[4] = local_30;
            local_30 = (char *)0x0;
            value[5] = local_2c;
            local_2c = (char *)0x0;
            iVar3 = TXT_DB_insert((TXT_DB *)pCVar18->meth_data,value);
            if (iVar3 == 0) goto LAB_00043e52;
            bVar30 = true;
            pCVar27 = (CONF *)0x0;
          }
          else {
            bVar30 = true;
            puVar26 = (undefined4 *)sk_value(*(_STACK **)((int)pCVar18->meth_data + 4),iVar3);
            BIO_printf(bio_err,"user \"%s\" reactivated.\n",pCVar23);
            *(undefined *)*puVar26 = 0x56;
            pCVar27 = (CONF *)0x0;
          }
        }
        else if (pCVar23 == (CONF *)0x0) {
          BIO_printf(bio_err,"List all users\n");
          while( true ) {
            iVar3 = sk_num(*(_STACK **)((int)pCVar18->meth_data + 4));
            if (iVar3 <= (int)pCVar23) break;
            print_user_part_4(pCVar18,bio_err,pCVar23);
            pCVar23 = (CONF *)((int)&pCVar23->meth + 1);
          }
          pCVar27 = (CONF *)0x0;
        }
        else if (iVar3 < 0) {
          local_58 = (CONF *)((int)&local_58->meth + 1);
          BIO_printf(bio_err,"user \"%s\" does not exist, ignored. t\n",pCVar23);
        }
LAB_00043bc8:
        param_1 = param_1 + -1;
        if (param_1 < 1) {
          pCVar23 = (CONF *)0x0;
          pCVar27 = pCVar23;
        }
        else {
          pCVar23 = *local_80;
          local_80 = local_80 + 1;
        }
        goto LAB_00043b46;
      }
    }
  }
  else {
    BIO_printf(bio_err,"-passin, -passout arguments only valid with one user.\n");
LAB_00043556:
    ppuVar15 = &srp_usage;
    puVar12 = srp_usage;
    while (puVar12 != (undefined *)0x0) {
      BIO_printf(bio_err,"%s");
      ppuVar15 = ppuVar15 + 1;
      puVar12 = *ppuVar15;
    }
    BIO_printf(bio_err," -rand file%cfile%c...\n",0x3a,0x3a);
    BIO_printf(bio_err,"                 load the file (or the files in the directory) into\n");
    BIO_printf(bio_err,"                 the random number generator\n");
    local_70 = (CONF *)0x0;
    pCVar18 = (CONF *)0x0;
    local_58 = (CONF *)0x0;
  }
LAB_000435b8:
  pCVar27 = (CONF *)0x1;
  goto joined_r0x00043eb8;
LAB_00043f6a:
  while( true ) {
    iVar3 = sk_num(*(_STACK **)((int)pCVar18->meth_data + 4));
    pCVar23 = (CONF *)((int)&pCVar27->meth + 1);
    if (iVar3 <= (int)pCVar27) break;
    ppcVar4 = (char **)sk_value(*(_STACK **)((int)pCVar18->meth_data + 4),(int)pCVar27);
    pCVar27 = pCVar23;
    if (**ppcVar4 == 'v') {
      **ppcVar4 = 'V';
    }
  }
  iVar3 = save_index(local_74,"new",pCVar18);
  if ((iVar3 == 0) || (iVar3 = rotate_index(local_74,"new","old"), iVar3 == 0)) goto LAB_00043eaa;
LAB_00043fac:
  pCVar27 = local_58;
  if (local_58 != (CONF *)0x0) {
    pCVar27 = (CONF *)0x1;
  }
  goto LAB_00043eae;
LAB_00044112:
  for (; iVar3 = sk_num(*(_STACK **)((int)pCVar18->meth_data + 4)), (int)uVar21 < iVar3;
      uVar21 = uVar21 + 1) {
    ppcVar4 = (char **)sk_value(*(_STACK **)((int)pCVar18->meth_data + 4),uVar21);
    if (**ppcVar4 == 'v') {
      **ppcVar4 = 'V';
      print_user_part_4(pCVar18,bio_err,uVar21,pCVar22);
    }
  }
  BIO_printf(bio_err,"Trying to update srpvfile.\n");
  iVar3 = save_index(local_74,"new",pCVar18);
  if (iVar3 != 0) {
    BIO_printf(bio_err,"Temporary srpvfile created.\n");
    iVar3 = rotate_index(local_74,"new","old");
    if (iVar3 != 0) {
      BIO_printf(bio_err,"srpvfile updated.\n");
      goto LAB_00043fac;
    }
  }
  goto LAB_00043eaa;
LAB_00043e52:
  BIO_printf(pBVar2,"failed to update srpvfile\n");
  BIO_printf(pBVar2,"TXT_DB error number %ld\n",*(undefined4 *)((int)pCVar18->meth_data + 0x10));
  CRYPTO_free(value);
LAB_00043e7a:
  if (local_34 != (char *)0x0) {
LAB_00044028:
    CRYPTO_free(local_34);
  }
LAB_00043e84:
  if (local_30 != (char *)0x0) {
    CRYPTO_free(local_30);
  }
  if (local_2c != (char *)0x0) {
    CRYPTO_free(local_2c);
  }
  if (local_40 != (char *)0x0) {
    CRYPTO_free(local_40);
  }
  if (local_3c != (OPENSSL_STRING)0x0) {
    CRYPTO_free(local_3c);
  }
  if (local_38 != (OPENSSL_STRING)0x0) {
    CRYPTO_free(local_38);
  }
LAB_00043eaa:
  pCVar27 = (CONF *)0x1;
LAB_00043eae:
  if (local_58 == (CONF *)0x0) {
joined_r0x00043eb8:
    if (pCVar22 != (CONF *)0x0) goto LAB_000438a6;
  }
  else {
LAB_0004388a:
    if (pCVar22 == (CONF *)0x0) goto LAB_000435cc;
    BIO_printf(bio_err,"User errors %d.\n",local_58);
    local_58 = (CONF *)0x0;
LAB_000438a6:
    BIO_printf(bio_err,"SRP terminating with code %d.\n",pCVar27);
  }
  if (local_58 != (CONF *)0x0) {
    CRYPTO_free(local_58);
  }
LAB_000435cc:
  if (pCVar27 != (CONF *)0x0) {
    ERR_print_errors(bio_err);
  }
  if (local_70 != (CONF *)0x0) {
    app_RAND_write_file(local_70,bio_err);
  }
  if (conf != (CONF *)0x0) {
    NCONF_free(conf);
  }
  if (pCVar18 != (CONF *)0x0) {
    free_index(pCVar18);
  }
  OBJ_cleanup();
  return pCVar27;
}

