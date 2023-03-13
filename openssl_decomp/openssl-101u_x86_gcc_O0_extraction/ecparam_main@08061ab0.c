
undefined4 ecparam_main(int param_1,undefined4 *param_2)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  int iVar12;
  BIO_METHOD *pBVar13;
  BIO *bp;
  BIO *bp_00;
  long lVar14;
  EC_GROUP *group;
  size_t nitems;
  EC_builtin_curve *r;
  size_t sVar15;
  char *pcVar16;
  EC_KEY *pEVar17;
  EC_METHOD *meth;
  EC_POINT *pEVar18;
  point_conversion_form_t form;
  BIGNUM *pBVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  uint num;
  uint uVar23;
  byte **ppbVar24;
  byte **ppbVar25;
  byte *pbVar26;
  undefined4 uVar27;
  char **ppcVar28;
  byte *pbVar29;
  bool bVar30;
  bool bVar31;
  bool bVar32;
  byte bVar33;
  char *pcVar34;
  byte *pbVar35;
  void *local_70;
  BIGNUM *local_6c;
  int local_68;
  BIGNUM *local_64;
  BIGNUM *local_60;
  BIGNUM *local_5c;
  BIGNUM *local_54;
  BIGNUM *local_50;
  point_conversion_form_t local_48;
  int local_40;
  byte *local_38;
  byte *local_28;
  
  bVar33 = 0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar13 = BIO_s_file();
    bio_err = BIO_new(pBVar13);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar12 = load_config(bio_err,0);
  if (iVar12 == 0) {
    uVar27 = 1;
    bp_00 = (BIO *)0x0;
    bp = (BIO *)0x0;
    group = (EC_GROUP *)0x0;
    goto LAB_08061edb;
  }
  uVar27 = *param_2;
  param_1 = param_1 + -1;
  bVar31 = param_1 == 0;
  ppbVar25 = (byte **)(param_2 + 1);
  if (param_1 < 1) {
    bVar8 = false;
    bVar9 = false;
    local_68 = 3;
    local_6c = (BIGNUM *)0x3;
    local_60 = (BIGNUM *)0x0;
    local_64 = (BIGNUM *)0x0;
    bVar11 = false;
    bVar10 = false;
    bVar6 = false;
    bVar7 = false;
    bVar5 = false;
    bVar2 = false;
    local_28 = (byte *)0x0;
    local_54 = (BIGNUM *)0x0;
    bVar4 = false;
    local_40 = 1;
    bVar3 = false;
    local_48 = POINT_CONVERSION_UNCOMPRESSED;
    local_38 = (byte *)0x0;
  }
  else {
    local_38 = (byte *)0x0;
    bVar8 = false;
    bVar9 = false;
    local_68 = 3;
    local_6c = (BIGNUM *)0x3;
    local_60 = (BIGNUM *)0x0;
    local_64 = (BIGNUM *)0x0;
    bVar11 = false;
    bVar10 = false;
    bVar6 = false;
    bVar7 = false;
    bVar5 = false;
    bVar2 = false;
    local_28 = (byte *)0x0;
    local_54 = (BIGNUM *)0x0;
    bVar4 = false;
    local_40 = 1;
    bVar3 = false;
    local_48 = POINT_CONVERSION_UNCOMPRESSED;
LAB_08061bde:
    do {
      pbVar35 = *ppbVar25;
      iVar12 = 8;
      pbVar26 = pbVar35;
      pbVar29 = (byte *)"-inform";
      do {
        if (iVar12 == 0) break;
        iVar12 = iVar12 + -1;
        bVar31 = *pbVar26 == *pbVar29;
        pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
        pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
      } while (bVar31);
      if (bVar31) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          ppbVar24 = ppbVar25 + 1;
          local_6c = (BIGNUM *)str2fmt(ppbVar25[1]);
          goto LAB_08061bd6;
        }
LAB_08062000:
        BIO_printf(bio_err,"%s [options] <infile >outfile\n",uVar27);
        BIO_printf(bio_err,"where options are\n");
        BIO_printf(bio_err," -inform arg       input format - default PEM (DER or PEM)\n");
        BIO_printf(bio_err," -outform arg      output format - default PEM\n");
        BIO_printf(bio_err," -in  arg          input file  - default stdin\n");
        BIO_printf(bio_err," -out arg          output file - default stdout\n");
        BIO_printf(bio_err," -noout            do not print the ec parameter\n");
        BIO_printf(bio_err," -text             print the ec parameters in text form\n");
        BIO_printf(bio_err," -check            validate the ec parameters\n");
        BIO_printf(bio_err," -C                print a \'C\' function creating the parameters\n");
        BIO_printf(bio_err," -name arg         use the ec parameters with \'short name\' name\n");
        BIO_printf(bio_err,
                   " -list_curves      prints a list of all currently available curve \'short names\'\n"
                  );
        BIO_printf(bio_err," -conv_form arg    specifies the point conversion form \n");
        BIO_printf(bio_err,"                   possible values: compressed\n");
        BIO_printf(bio_err,"                                    uncompressed (default)\n");
        BIO_printf(bio_err,"                                    hybrid\n");
        BIO_printf(bio_err," -param_enc arg    specifies the way the ec parameters are encoded\n");
        BIO_printf(bio_err,"                   in the asn1 der encoding\n");
        BIO_printf(bio_err,"                   possible values: named_curve (default)\n");
        BIO_printf(bio_err,"                                    explicit\n");
        BIO_printf(bio_err,
                   " -no_seed          if \'explicit\' parameters are chosen do not use the seed\n")
        ;
        bp_00 = (BIO *)0x0;
        BIO_printf(bio_err," -genkey           generate ec key\n");
        uVar27 = 1;
        group = (EC_GROUP *)0x0;
        BIO_printf(bio_err," -rand file        files to use for random number input\n");
        bp = (BIO *)0x0;
        BIO_printf(bio_err," -engine e         use engine e, possibly a hardware device\n");
        goto LAB_08061edb;
      }
      iVar12 = 9;
      pbVar26 = pbVar35;
      pbVar29 = (byte *)"-outform";
      do {
        if (iVar12 == 0) break;
        iVar12 = iVar12 + -1;
        bVar31 = *pbVar26 == *pbVar29;
        pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
        pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
      } while (bVar31);
      if (!bVar31) {
        bVar1 = *pbVar35;
        bVar31 = 0x2d < bVar1;
        bVar32 = bVar1 == 0x2d;
        if (bVar32) {
          bVar31 = pbVar35[1] < 0x69;
          bVar32 = pbVar35[1] == 0x69;
          if (bVar32) {
            bVar31 = pbVar35[2] < 0x6e;
            bVar32 = pbVar35[2] == 0x6e;
            if (bVar32) {
              bVar31 = false;
              bVar32 = pbVar35[3] == 0;
              if (bVar32) {
                param_1 = param_1 + -1;
                if (param_1 != 0) {
                  local_64 = (BIGNUM *)ppbVar25[1];
                  ppbVar24 = ppbVar25 + 1;
                  goto LAB_08061bd6;
                }
                goto LAB_08062000;
              }
            }
          }
        }
        iVar12 = 5;
        pbVar26 = pbVar35;
        pbVar29 = &DAT_081eab75;
        do {
          if (iVar12 == 0) break;
          iVar12 = iVar12 + -1;
          bVar31 = *pbVar26 < *pbVar29;
          bVar32 = *pbVar26 == *pbVar29;
          pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
          pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
        } while (bVar32);
        bVar30 = (!bVar31 && !bVar32) < bVar31;
        bVar31 = (!bVar31 && !bVar32) == bVar31;
        if (bVar31) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_08062000;
          local_60 = (BIGNUM *)ppbVar25[1];
          ppbVar24 = ppbVar25 + 1;
        }
        else {
          iVar12 = 6;
          pbVar26 = pbVar35;
          pbVar29 = (byte *)"-text";
          do {
            if (iVar12 == 0) break;
            iVar12 = iVar12 + -1;
            bVar30 = *pbVar26 < *pbVar29;
            bVar31 = *pbVar26 == *pbVar29;
            pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
            pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
          } while (bVar31);
          ppbVar24 = ppbVar25;
          if ((!bVar30 && !bVar31) == bVar30) {
            bVar6 = true;
          }
          else {
            bVar31 = bVar1 == 0x2d;
            if (((bVar31) && (bVar31 = pbVar35[1] == 0x43, bVar31)) &&
               (bVar31 = pbVar35[2] == 0, bVar31)) {
              bVar8 = true;
            }
            else {
              iVar12 = 7;
              pbVar26 = pbVar35;
              pbVar29 = (byte *)"-check";
              do {
                if (iVar12 == 0) break;
                iVar12 = iVar12 + -1;
                bVar31 = *pbVar26 == *pbVar29;
                pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
                pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
              } while (bVar31);
              if (bVar31) {
                bVar7 = true;
              }
              else {
                iVar12 = 6;
                pbVar26 = pbVar35;
                pbVar29 = (byte *)"-name";
                do {
                  if (iVar12 == 0) break;
                  iVar12 = iVar12 + -1;
                  bVar31 = *pbVar26 == *pbVar29;
                  pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
                  pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
                } while (bVar31);
                if (bVar31) {
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_08062000;
                  local_54 = (BIGNUM *)ppbVar25[1];
                  ppbVar24 = ppbVar25 + 1;
                }
                else {
                  iVar12 = 0xd;
                  pbVar26 = pbVar35;
                  pbVar29 = (byte *)"-list_curves";
                  do {
                    if (iVar12 == 0) break;
                    iVar12 = iVar12 + -1;
                    bVar31 = *pbVar26 == *pbVar29;
                    pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
                    pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
                  } while (bVar31);
                  if (bVar31) {
                    bVar2 = true;
                  }
                  else {
                    iVar12 = 0xb;
                    pbVar26 = pbVar35;
                    pbVar29 = (byte *)"-conv_form";
                    do {
                      if (iVar12 == 0) break;
                      iVar12 = iVar12 + -1;
                      bVar31 = *pbVar26 == *pbVar29;
                      pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
                      pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
                    } while (bVar31);
                    if (bVar31) {
                      param_1 = param_1 + -1;
                      bVar31 = param_1 == 0;
                      if (bVar31) goto LAB_08062000;
                      pbVar35 = ppbVar25[1];
                      iVar12 = 0xb;
                      ppbVar24 = ppbVar25 + 1;
                      pbVar26 = pbVar35;
                      pbVar29 = (byte *)0x81f08df;
                      do {
                        if (iVar12 == 0) break;
                        iVar12 = iVar12 + -1;
                        bVar31 = *pbVar26 == *pbVar29;
                        pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
                        pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
                      } while (bVar31);
                      if (bVar31) {
                        bVar3 = true;
                        local_48 = POINT_CONVERSION_COMPRESSED;
                      }
                      else {
                        iVar12 = 0xd;
                        pbVar26 = pbVar35;
                        pbVar29 = (byte *)"uncompressed";
                        do {
                          if (iVar12 == 0) break;
                          iVar12 = iVar12 + -1;
                          bVar31 = *pbVar26 == *pbVar29;
                          pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
                          pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
                        } while (bVar31);
                        if (bVar31) {
                          bVar3 = true;
                          local_48 = POINT_CONVERSION_UNCOMPRESSED;
                        }
                        else {
                          iVar12 = 7;
                          pbVar26 = (byte *)"hybrid";
                          do {
                            if (iVar12 == 0) break;
                            iVar12 = iVar12 + -1;
                            bVar31 = *pbVar35 == *pbVar26;
                            pbVar35 = pbVar35 + (uint)bVar33 * -2 + 1;
                            pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
                          } while (bVar31);
                          if (!bVar31) goto LAB_08062000;
                          bVar3 = true;
                          local_48 = POINT_CONVERSION_HYBRID;
                        }
                      }
                    }
                    else {
                      iVar12 = 0xb;
                      pbVar26 = pbVar35;
                      pbVar29 = (byte *)"-param_enc";
                      do {
                        if (iVar12 == 0) break;
                        iVar12 = iVar12 + -1;
                        bVar31 = *pbVar26 == *pbVar29;
                        pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
                        pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
                      } while (bVar31);
                      if (bVar31) {
                        param_1 = param_1 + -1;
                        bVar31 = param_1 == 0;
                        if (bVar31) goto LAB_08062000;
                        iVar12 = 0xc;
                        pbVar35 = ppbVar25[1];
                        pbVar26 = (byte *)0x81f4faa;
                        do {
                          if (iVar12 == 0) break;
                          iVar12 = iVar12 + -1;
                          bVar31 = *pbVar35 == *pbVar26;
                          pbVar35 = pbVar35 + (uint)bVar33 * -2 + 1;
                          pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
                        } while (bVar31);
                        ppbVar24 = ppbVar25 + 1;
                        if (bVar31) {
                          bVar4 = true;
                          local_40 = 1;
                        }
                        else {
                          iVar12 = 9;
                          pbVar35 = ppbVar25[1];
                          pbVar26 = (byte *)0x81fc66e;
                          do {
                            if (iVar12 == 0) break;
                            iVar12 = iVar12 + -1;
                            bVar31 = *pbVar35 == *pbVar26;
                            pbVar35 = pbVar35 + (uint)bVar33 * -2 + 1;
                            pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
                          } while (bVar31);
                          if (!bVar31) goto LAB_08062000;
                          bVar4 = true;
                          local_40 = 0;
                        }
                      }
                      else {
                        iVar12 = 9;
                        pbVar26 = pbVar35;
                        pbVar29 = (byte *)"-no_seed";
                        do {
                          if (iVar12 == 0) break;
                          iVar12 = iVar12 + -1;
                          bVar31 = *pbVar26 == *pbVar29;
                          pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
                          pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
                        } while (bVar31);
                        if (bVar31) {
                          bVar5 = true;
                        }
                        else {
                          iVar12 = 7;
                          pbVar26 = pbVar35;
                          pbVar29 = (byte *)"-noout";
                          do {
                            if (iVar12 == 0) break;
                            iVar12 = iVar12 + -1;
                            bVar31 = *pbVar26 == *pbVar29;
                            pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
                            pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
                          } while (bVar31);
                          if (bVar31) {
                            bVar9 = true;
                          }
                          else {
                            iVar12 = 8;
                            pbVar26 = pbVar35;
                            pbVar29 = (byte *)"-genkey";
                            do {
                              if (iVar12 == 0) break;
                              iVar12 = iVar12 + -1;
                              bVar31 = *pbVar26 == *pbVar29;
                              pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
                              pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
                            } while (bVar31);
                            if (!bVar31) {
                              iVar12 = 6;
                              pbVar26 = pbVar35;
                              pbVar29 = (byte *)"-rand";
                              do {
                                if (iVar12 == 0) break;
                                iVar12 = iVar12 + -1;
                                bVar31 = *pbVar26 == *pbVar29;
                                pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
                                pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
                              } while (bVar31);
                              if (bVar31) {
                                param_1 = param_1 + -1;
                                if (param_1 != 0) {
                                  local_28 = ppbVar25[1];
                                  bVar10 = true;
                                  ppbVar24 = ppbVar25 + 1;
                                  goto LAB_08061bd6;
                                }
                              }
                              else {
                                iVar12 = 8;
                                pbVar26 = pbVar35;
                                pbVar29 = (byte *)"-engine";
                                do {
                                  if (iVar12 == 0) break;
                                  iVar12 = iVar12 + -1;
                                  bVar31 = *pbVar26 == *pbVar29;
                                  pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
                                  pbVar29 = pbVar29 + (uint)bVar33 * -2 + 1;
                                } while (bVar31);
                                if (bVar31) {
                                  param_1 = param_1 + -1;
                                  if (param_1 != 0) {
                                    local_38 = ppbVar25[1];
                                    ppbVar24 = ppbVar25 + 1;
                                    goto LAB_08061bd6;
                                  }
                                }
                                else {
                                  BIO_printf(bio_err,"unknown option %s\n",pbVar35);
                                }
                              }
                              goto LAB_08062000;
                            }
                            bVar11 = true;
                            bVar10 = true;
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
LAB_08061bd6:
        param_1 = param_1 + -1;
        bVar31 = param_1 == 0;
        ppbVar25 = ppbVar24 + 1;
        if (bVar31) break;
        goto LAB_08061bde;
      }
      if (param_1 == 1) goto LAB_08062000;
      local_68 = str2fmt(ppbVar25[1]);
      param_1 = param_1 + -2;
      bVar31 = param_1 == 0;
      ppbVar25 = ppbVar25 + 2;
    } while (!bVar31);
  }
  ERR_load_crypto_strings();
  pBVar13 = BIO_s_file();
  bp = BIO_new(pBVar13);
  pBVar13 = BIO_s_file();
  bp_00 = BIO_new(pBVar13);
  if ((bp == (BIO *)0x0) || (bp_00 == (BIO *)0x0)) {
    uVar27 = 1;
    group = (EC_GROUP *)0x0;
    ERR_print_errors(bio_err);
    goto LAB_08061edb;
  }
  if (local_64 == (BIGNUM *)0x0) {
    BIO_ctrl(bp,0x6a,0,stdin);
  }
  else {
    lVar14 = BIO_ctrl(bp,0x6c,3,local_64);
    if (lVar14 < 1) {
      uVar27 = 1;
      group = (EC_GROUP *)0x0;
      perror((char *)local_64);
      goto LAB_08061edb;
    }
  }
  if (local_60 == (BIGNUM *)0x0) {
    BIO_ctrl(bp_00,0x6a,0,stdout);
  }
  else {
    lVar14 = BIO_ctrl(bp_00,0x6c,5,local_60);
    if (lVar14 < 1) {
      uVar27 = 1;
      group = (EC_GROUP *)0x0;
      perror((char *)local_60);
      goto LAB_08061edb;
    }
  }
  pbVar35 = (byte *)0x0;
  setup_engine(bio_err,local_38,0);
  if (bVar2) {
    nitems = EC_get_builtin_curves((EC_builtin_curve *)0x0,0);
    r = (EC_builtin_curve *)CRYPTO_malloc(nitems << 3,"ecparam.c",0x145);
    if (r != (EC_builtin_curve *)0x0) {
      sVar15 = EC_get_builtin_curves(r,nitems);
      if (sVar15 == 0) {
        uVar27 = 1;
        group = (EC_GROUP *)0x0;
        CRYPTO_free(r);
      }
      else {
        ppcVar28 = &r->comment;
        if (nitems != 0) {
          sVar15 = 0;
          do {
            pcVar34 = *ppcVar28;
            pcVar16 = OBJ_nid2sn(((EC_builtin_curve *)(ppcVar28 + -1))->nid);
            if (pcVar34 == (char *)0x0) {
              pcVar34 = "CURVE DESCRIPTION NOT AVAILABLE";
            }
            if (pcVar16 == (char *)0x0) {
              pcVar16 = "";
            }
            sVar15 = sVar15 + 1;
            ppcVar28 = ppcVar28 + 2;
            BIO_printf(bp_00,"  %-10s: ",pcVar16);
            BIO_printf(bp_00,"%s\n",pcVar34);
          } while (nitems != sVar15);
        }
        uVar27 = 0;
        group = (EC_GROUP *)0x0;
        CRYPTO_free(r);
      }
      goto LAB_08061edb;
    }
LAB_0806251f:
    uVar27 = 1;
    group = (EC_GROUP *)0x0;
    goto LAB_08061edb;
  }
  bVar31 = local_54 == (BIGNUM *)0x0;
  if (bVar31) {
    if (local_6c == (BIGNUM *)0x1) {
      group = (EC_GROUP *)ASN1_d2i_bio((xnew *)0x0,d2i_ECPKParameters,bp,(void **)0x0);
    }
    else {
      if (local_6c != (BIGNUM *)0x3) {
        pcVar34 = "bad input format specified\n";
LAB_08062511:
        BIO_printf(bio_err,pcVar34,pbVar35);
        goto LAB_0806251f;
      }
      group = PEM_read_bio_ECPKParameters(bp,(EC_GROUP **)0x0,(undefined1 *)0x0,(void *)0x0);
    }
    if (group != (EC_GROUP *)0x0) goto LAB_08061d57;
    pcVar34 = "unable to load elliptic curve parameters\n";
LAB_080627bc:
    BIO_printf(bio_err,pcVar34);
    ERR_print_errors(bio_err);
  }
  else {
    iVar12 = 10;
    pbVar35 = (byte *)local_54;
    pbVar26 = (byte *)"secp192r1";
    do {
      if (iVar12 == 0) break;
      iVar12 = iVar12 + -1;
      bVar31 = *pbVar35 == *pbVar26;
      pbVar35 = pbVar35 + (uint)bVar33 * -2 + 1;
      pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
    } while (bVar31);
    if (bVar31) {
      BIO_printf(bio_err,"using curve name prime192v1 instead of secp192r1\n");
      iVar12 = 0x199;
    }
    else {
      iVar12 = 10;
      pbVar35 = (byte *)local_54;
      pbVar26 = (byte *)"secp256r1";
      do {
        if (iVar12 == 0) break;
        iVar12 = iVar12 + -1;
        bVar31 = *pbVar35 == *pbVar26;
        pbVar35 = pbVar35 + (uint)bVar33 * -2 + 1;
        pbVar26 = pbVar26 + (uint)bVar33 * -2 + 1;
      } while (bVar31);
      if (bVar31) {
        BIO_printf(bio_err,"using curve name prime256v1 instead of secp256r1\n");
        iVar12 = 0x19f;
      }
      else {
        iVar12 = OBJ_sn2nid((char *)local_54);
        if (iVar12 == 0) {
          pcVar34 = "unknown curve name (%s)\n";
          pbVar35 = (byte *)local_54;
          goto LAB_08062511;
        }
      }
    }
    group = EC_GROUP_new_by_curve_name(iVar12);
    if (group == (EC_GROUP *)0x0) {
      uVar27 = 1;
      BIO_printf(bio_err,"unable to create curve (%s)\n",local_54);
      goto LAB_08061edb;
    }
    EC_GROUP_set_asn1_flag(group,local_40);
    EC_GROUP_set_point_conversion_form(group,local_48);
LAB_08061d57:
    if (bVar3) {
      EC_GROUP_set_point_conversion_form(group,local_48);
    }
    if (bVar4) {
      EC_GROUP_set_asn1_flag(group,local_40);
    }
    if (bVar5) {
      EC_GROUP_set_seed(group,(uchar *)0x0,0);
    }
    if ((!bVar6) || (iVar12 = ECPKParameters_print(bp_00,group,0), iVar12 != 0)) {
      if (bVar7) {
        BIO_printf(bio_err,"checking elliptic curve parameters: ");
        iVar12 = EC_GROUP_check(group,(BN_CTX *)0x0);
        if (iVar12 == 0) {
          pcVar34 = "failed\n";
          goto LAB_080627bc;
        }
        BIO_printf(bio_err,"ok\n");
      }
      if (bVar8) {
        meth = EC_GROUP_method_of(group);
        local_60 = BN_new();
        if ((local_60 == (BIGNUM *)0x0) || (local_54 = BN_new(), local_54 == (BIGNUM *)0x0)) {
          local_6c = (BIGNUM *)0x0;
          local_5c = (BIGNUM *)0x0;
          local_50 = (BIGNUM *)0x0;
          local_54 = (BIGNUM *)0x0;
LAB_080627fb:
          uVar27 = 1;
          perror("OPENSSL_malloc");
          local_70 = (void *)0x0;
          local_64 = (BIGNUM *)0x0;
          goto LAB_08061e38;
        }
        local_50 = BN_new();
        if (local_50 == (BIGNUM *)0x0) {
          local_6c = (BIGNUM *)0x0;
          local_5c = (BIGNUM *)0x0;
          goto LAB_080627fb;
        }
        local_5c = BN_new();
        if (local_5c == (BIGNUM *)0x0) {
          local_6c = (BIGNUM *)0x0;
          goto LAB_080627fb;
        }
        local_6c = BN_new();
        if ((local_6c == (BIGNUM *)0x0) || (local_64 = BN_new(), local_64 == (BIGNUM *)0x0))
        goto LAB_080627fb;
        iVar12 = EC_METHOD_get_field_type(meth);
        if (((iVar12 == 0x196) &&
            (iVar12 = EC_GROUP_get_curve_GFp(group,local_60,local_54,local_50,(BN_CTX *)0x0),
            iVar12 != 0)) && (pEVar18 = EC_GROUP_get0_generator(group), pEVar18 != (EC_POINT *)0x0))
        {
          form = EC_GROUP_get_point_conversion_form(group);
          pBVar19 = EC_POINT_point2bn(group,pEVar18,form,local_5c,(BN_CTX *)0x0);
          if (((pBVar19 != (BIGNUM *)0x0) &&
              (iVar12 = EC_GROUP_get_order(group,local_6c,(BN_CTX *)0x0), iVar12 != 0)) &&
             (iVar12 = EC_GROUP_get_cofactor(group,local_64,(BN_CTX *)0x0), iVar12 != 0)) {
            iVar20 = BN_num_bits(local_6c);
            iVar21 = BN_num_bits(local_60);
            iVar12 = iVar21 + 7;
            if (iVar21 + 7 < 0) {
              iVar12 = iVar21 + 0xe;
            }
            iVar22 = BN_num_bits(local_54);
            iVar21 = iVar22 + 7;
            if (iVar22 + 7 < 0) {
              iVar21 = iVar22 + 0xe;
            }
            uVar23 = iVar12 >> 3;
            if ((uint)(iVar12 >> 3) < (uint)(iVar21 >> 3)) {
              uVar23 = iVar21 >> 3;
            }
            iVar21 = BN_num_bits(local_50);
            iVar12 = iVar21 + 7;
            if (iVar21 + 7 < 0) {
              iVar12 = iVar21 + 0xe;
            }
            if (uVar23 <= (uint)(iVar12 >> 3)) {
              uVar23 = iVar12 >> 3;
            }
            iVar21 = BN_num_bits(local_5c);
            iVar12 = iVar21 + 7;
            if (iVar21 + 7 < 0) {
              iVar12 = iVar21 + 0xe;
            }
            if (uVar23 <= (uint)(iVar12 >> 3)) {
              uVar23 = iVar12 >> 3;
            }
            iVar21 = BN_num_bits(local_6c);
            iVar12 = iVar21 + 7;
            if (iVar21 + 7 < 0) {
              iVar12 = iVar21 + 0xe;
            }
            if (uVar23 <= (uint)(iVar12 >> 3)) {
              uVar23 = iVar12 >> 3;
            }
            iVar21 = BN_num_bits(local_64);
            iVar12 = iVar21 + 7;
            if (iVar21 + 7 < 0) {
              iVar12 = iVar21 + 0xe;
            }
            num = iVar12 >> 3;
            if ((uint)(iVar12 >> 3) < uVar23) {
              num = uVar23;
            }
            local_70 = CRYPTO_malloc(num,"ecparam.c",0x1df);
            if (local_70 != (void *)0x0) {
              ecparam_print_var(iVar20,local_70);
              ecparam_print_var(iVar20,local_70);
              ecparam_print_var(iVar20,local_70);
              ecparam_print_var(iVar20,local_70);
              ecparam_print_var(iVar20,local_70);
              ecparam_print_var(iVar20,local_70);
              BIO_printf(bp_00,"\n\n");
              BIO_printf(bp_00,"EC_GROUP *get_ec_group_%d(void)\n\t{\n",iVar20);
              BIO_printf(bp_00,"\tint ok=0;\n");
              BIO_printf(bp_00,"\tEC_GROUP *group = NULL;\n");
              BIO_printf(bp_00,"\tEC_POINT *point = NULL;\n");
              BIO_printf(bp_00,"\tBIGNUM   *tmp_1 = NULL, *tmp_2 = NULL, *tmp_3 = NULL;\n\n");
              BIO_printf(bp_00,
                         "\tif ((tmp_1 = BN_bin2bn(ec_p_%d, sizeof(ec_p_%d), NULL)) == NULL)\n\t\tgoto err;\n"
                         ,iVar20,iVar20);
              BIO_printf(bp_00,
                         "\tif ((tmp_2 = BN_bin2bn(ec_a_%d, sizeof(ec_a_%d), NULL)) == NULL)\n\t\tgoto err;\n"
                         ,iVar20,iVar20);
              BIO_printf(bp_00,
                         "\tif ((tmp_3 = BN_bin2bn(ec_b_%d, sizeof(ec_b_%d), NULL)) == NULL)\n\t\tgoto err;\n"
                         ,iVar20,iVar20);
              BIO_printf(bp_00,
                         "\tif ((group = EC_GROUP_new_curve_GFp(tmp_1, tmp_2, tmp_3, NULL)) == NULL)\n\t\tgoto err;\n\n"
                        );
              BIO_printf(bp_00,"\t/* build generator */\n");
              BIO_printf(bp_00,
                         "\tif ((tmp_1 = BN_bin2bn(ec_gen_%d, sizeof(ec_gen_%d), tmp_1)) == NULL)\n\t\tgoto err;\n"
                         ,iVar20,iVar20);
              BIO_printf(bp_00,"\tpoint = EC_POINT_bn2point(group, tmp_1, NULL, NULL);\n");
              BIO_printf(bp_00,"\tif (point == NULL)\n\t\tgoto err;\n");
              BIO_printf(bp_00,
                         "\tif ((tmp_2 = BN_bin2bn(ec_order_%d, sizeof(ec_order_%d), tmp_2)) == NULL)\n\t\tgoto err;\n"
                         ,iVar20,iVar20);
              BIO_printf(bp_00,
                         "\tif ((tmp_3 = BN_bin2bn(ec_cofactor_%d, sizeof(ec_cofactor_%d), tmp_3)) == NULL)\n\t\tgoto err;\n"
                         ,iVar20,iVar20);
              BIO_printf(bp_00,
                         "\tif (!EC_GROUP_set_generator(group, point, tmp_2, tmp_3))\n\t\tgoto err;\n"
                        );
              BIO_printf(bp_00,"\n\tok=1;\n");
              BIO_printf(bp_00,"err:\n");
              BIO_printf(bp_00,"\tif (tmp_1)\n\t\tBN_free(tmp_1);\n");
              BIO_printf(bp_00,"\tif (tmp_2)\n\t\tBN_free(tmp_2);\n");
              BIO_printf(bp_00,"\tif (tmp_3)\n\t\tBN_free(tmp_3);\n");
              BIO_printf(bp_00,"\tif (point)\n\t\tEC_POINT_free(point);\n");
              BIO_printf(bp_00,"\tif (!ok)\n");
              BIO_printf(bp_00,"\t\t{\n");
              BIO_printf(bp_00,"\t\tEC_GROUP_free(group);\n");
              BIO_printf(bp_00,"\t\tgroup = NULL;\n");
              BIO_printf(bp_00,"\t\t}\n");
              BIO_printf(bp_00,"\treturn(group);\n\t}\n");
              goto LAB_08061dfb;
            }
            perror("OPENSSL_malloc");
          }
        }
        local_70 = (void *)0x0;
        uVar27 = 1;
LAB_08061e40:
        BN_free(local_60);
      }
      else {
        local_70 = (void *)0x0;
        local_64 = (BIGNUM *)0x0;
        local_6c = (BIGNUM *)0x0;
        local_5c = (BIGNUM *)0x0;
        local_50 = (BIGNUM *)0x0;
        local_54 = (BIGNUM *)0x0;
        local_60 = (BIGNUM *)0x0;
LAB_08061dfb:
        if (bVar9) {
LAB_08062623:
          if (bVar10) {
            app_RAND_load_file(0,bio_err,local_28 != (byte *)0x0);
            if (local_28 != (byte *)0x0) {
              uVar27 = app_RAND_load_files(local_28);
              BIO_printf(bio_err,"%ld semi-random bytes loaded\n",uVar27);
            }
            if (bVar11) {
              pEVar17 = EC_KEY_new();
              if (pEVar17 == (EC_KEY *)0x0) goto LAB_0806264a;
              uVar27 = 1;
              iVar12 = EC_KEY_set_group(pEVar17,group);
              if (iVar12 != 0) {
                iVar12 = EC_KEY_generate_key(pEVar17);
                if (iVar12 != 0) {
                  if (local_68 == 1) {
                    i2d_ECPrivateKey_bio(bp_00,pEVar17);
                  }
                  else {
                    if (local_68 != 3) {
                      BIO_printf(bio_err,"bad output format specified for outfile\n");
                      EC_KEY_free(pEVar17);
                      goto LAB_08061e38;
                    }
                    PEM_write_bio_ECPrivateKey
                              (bp_00,pEVar17,(EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,
                               (void *)0x0);
                  }
                  EC_KEY_free(pEVar17);
                  goto LAB_0806291e;
                }
                EC_KEY_free(pEVar17);
              }
            }
            else {
LAB_0806291e:
              uVar27 = 0;
              app_RAND_write_file(0,bio_err);
            }
          }
          else {
            uVar27 = 0;
            if (bVar11) {
              pEVar17 = EC_KEY_new();
              if (pEVar17 != (EC_KEY *)0x0) {
                    /* WARNING: Subroutine does not return */
                __assert_fail("need_rand","ecparam.c",0x242,"ecparam_main");
              }
LAB_0806264a:
              uVar27 = 1;
            }
          }
        }
        else if (local_68 == 1) {
          iVar12 = ASN1_i2d_bio(i2d_ECPKParameters,bp_00,(uchar *)group);
LAB_08062871:
          if (iVar12 != 0) goto LAB_08062623;
          uVar27 = 1;
          BIO_printf(bio_err,"unable to write elliptic curve parameters\n");
          ERR_print_errors(bio_err);
        }
        else {
          if (local_68 == 3) {
            iVar12 = PEM_write_bio_ECPKParameters(bp_00,group);
            goto LAB_08062871;
          }
          uVar27 = 1;
          BIO_printf(bio_err,"bad output format specified for outfile\n");
        }
LAB_08061e38:
        if (local_60 != (BIGNUM *)0x0) goto LAB_08061e40;
      }
      if (local_54 != (BIGNUM *)0x0) {
        BN_free(local_54);
      }
      if (local_50 != (BIGNUM *)0x0) {
        BN_free(local_50);
      }
      if (local_5c != (BIGNUM *)0x0) {
        BN_free(local_5c);
      }
      if (local_6c != (BIGNUM *)0x0) {
        BN_free(local_6c);
      }
      if (local_64 != (BIGNUM *)0x0) {
        BN_free(local_64);
      }
      if (local_70 != (void *)0x0) {
        CRYPTO_free(local_70);
      }
      goto LAB_08061edb;
    }
  }
  uVar27 = 1;
LAB_08061edb:
  if (bp != (BIO *)0x0) {
    BIO_free(bp);
  }
  if (bp_00 != (BIO *)0x0) {
    BIO_free_all(bp_00);
  }
  if (group != (EC_GROUP *)0x0) {
    EC_GROUP_free(group);
  }
  return uVar27;
}

