
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 ecparam_main(int param_1,undefined4 *param_2)

{
  char **ppcVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  BIO *bp;
  int iVar11;
  BIO_METHOD *pBVar12;
  BIO *bp_00;
  long lVar13;
  size_t nitems;
  BIO *pBVar14;
  EC_METHOD *meth;
  BIGNUM *order;
  BIGNUM *cofactor;
  EC_KEY *pEVar15;
  EC_POINT *pEVar16;
  point_conversion_form_t form;
  BIGNUM *pBVar17;
  int iVar18;
  int iVar19;
  uint num;
  char *pcVar20;
  undefined4 uVar21;
  int iVar22;
  char **ppcVar23;
  char *pcVar24;
  char *pcVar25;
  int iVar26;
  size_t sVar27;
  uint uVar28;
  BIGNUM *local_6c;
  BIGNUM *local_68;
  BIGNUM *local_64;
  BIGNUM *local_60;
  BIO *local_5c;
  BIGNUM *local_58;
  point_conversion_form_t local_50;
  BIO *local_4c;
  int local_40;
  char *local_38;
  
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar12 = BIO_s_file();
    bio_err = BIO_new(pBVar12);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  bp = (BIO *)load_config(bio_err,0);
  if (bp == (BIO *)0x0) {
    uVar21 = 1;
    local_4c = bp;
    bp_00 = bp;
    goto LAB_00022516;
  }
  param_1 = param_1 + -1;
  ppcVar23 = (char **)(param_2 + 1);
  uVar21 = *param_2;
  pcVar25 = (char *)0x0;
  iVar22 = 3;
  local_58 = (BIGNUM *)0x0;
  bVar8 = false;
  local_6c = (BIGNUM *)0x0;
  iVar26 = 3;
  bVar10 = false;
  bVar9 = false;
  bVar6 = false;
  bVar7 = false;
  bVar5 = false;
  local_4c = (BIO *)0x0;
  local_38 = (char *)0x0;
  local_5c = (BIO *)0x0;
  bVar4 = false;
  bVar3 = false;
  local_40 = 1;
  local_50 = POINT_CONVERSION_UNCOMPRESSED;
  local_60 = (BIGNUM *)pcVar25;
  pcVar24 = (char *)0x0;
  if (0 < param_1) {
    iVar22 = 3;
    local_60 = (BIGNUM *)0x0;
LAB_00022324:
    do {
      pcVar24 = *ppcVar23;
      iVar11 = strcmp(pcVar24,"-inform");
      if (iVar11 == 0) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          ppcVar1 = ppcVar23 + 1;
          ppcVar23 = ppcVar23 + 1;
          iVar26 = str2fmt(*ppcVar1);
          goto LAB_0002231a;
        }
LAB_000225d0:
        BIO_printf(bio_err,"%s [options] <infile >outfile\n",uVar21);
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
        BIO_printf(bio_err," -genkey           generate ec key\n");
        BIO_printf(bio_err," -rand file        files to use for random number input\n");
        bp = (BIO *)0x0;
        BIO_printf(bio_err," -engine e         use engine e, possibly a hardware device\n");
        uVar21 = 1;
        local_4c = (BIO *)0x0;
        bp_00 = (BIO *)0x0;
        goto LAB_00022516;
      }
      iVar11 = strcmp(pcVar24,"-outform");
      if (iVar11 != 0) {
        cVar2 = *pcVar24;
        if ((((cVar2 == '-') && (pcVar24[1] == 'i')) && (pcVar24[2] == 'n')) && (pcVar24[3] == '\0')
           ) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_000225d0;
          pcVar25 = ppcVar23[1];
          ppcVar23 = ppcVar23 + 1;
        }
        else {
          iVar11 = strcmp(pcVar24,"-out");
          if (iVar11 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_000225d0;
            local_6c = (BIGNUM *)ppcVar23[1];
            ppcVar23 = ppcVar23 + 1;
          }
          else {
            iVar11 = strcmp(pcVar24,"-text");
            if (iVar11 == 0) {
              bVar6 = true;
            }
            else if (((cVar2 == '-') && (pcVar24[1] == 'C')) && (pcVar24[2] == '\0')) {
              local_58 = (BIGNUM *)0x1;
            }
            else {
              iVar11 = strcmp(pcVar24,"-check");
              if (iVar11 == 0) {
                bVar7 = true;
              }
              else {
                iVar11 = strcmp(pcVar24,"-name");
                if (iVar11 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_000225d0;
                  local_5c = (BIO *)ppcVar23[1];
                  ppcVar23 = ppcVar23 + 1;
                }
                else {
                  iVar11 = strcmp(pcVar24,"-list_curves");
                  if (iVar11 == 0) {
                    local_4c = (BIO *)0x1;
                  }
                  else {
                    iVar11 = strcmp(pcVar24,"-conv_form");
                    if (iVar11 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 == 0) goto LAB_000225d0;
                      pcVar24 = ppcVar23[1];
                      ppcVar23 = ppcVar23 + 1;
                      iVar11 = strcmp(pcVar24,"compressed");
                      if (iVar11 == 0) {
                        bVar3 = true;
                        local_50 = POINT_CONVERSION_COMPRESSED;
                      }
                      else {
                        iVar11 = strcmp(pcVar24,"uncompressed");
                        if (iVar11 == 0) {
                          bVar3 = true;
                          local_50 = POINT_CONVERSION_UNCOMPRESSED;
                        }
                        else {
                          iVar11 = strcmp(pcVar24,"hybrid");
                          if (iVar11 != 0) goto LAB_000225d0;
                          bVar3 = true;
                          local_50 = POINT_CONVERSION_HYBRID;
                        }
                      }
                    }
                    else {
                      iVar11 = strcmp(pcVar24,"-param_enc");
                      if (iVar11 == 0) {
                        param_1 = param_1 + -1;
                        if (param_1 == 0) goto LAB_000225d0;
                        pcVar24 = ppcVar23[1];
                        ppcVar23 = ppcVar23 + 1;
                        iVar11 = strcmp(pcVar24,"named_curve");
                        if (iVar11 == 0) {
                          bVar4 = true;
                          local_40 = 1;
                        }
                        else {
                          local_40 = strcmp(pcVar24,"explicit");
                          if (local_40 != 0) goto LAB_000225d0;
                          bVar4 = true;
                        }
                      }
                      else {
                        iVar11 = strcmp(pcVar24,"-no_seed");
                        if (iVar11 == 0) {
                          bVar5 = true;
                        }
                        else {
                          iVar11 = strcmp(pcVar24,"-noout");
                          if (iVar11 == 0) {
                            bVar8 = true;
                          }
                          else {
                            iVar11 = strcmp(pcVar24,"-genkey");
                            if (iVar11 != 0) {
                              iVar11 = strcmp(pcVar24,"-rand");
                              if (iVar11 == 0) {
                                param_1 = param_1 + -1;
                                if (param_1 != 0) {
                                  local_38 = ppcVar23[1];
                                  ppcVar23 = ppcVar23 + 1;
                                  bVar9 = true;
                                  goto LAB_0002231a;
                                }
                              }
                              else {
                                iVar11 = strcmp(pcVar24,"-engine");
                                if (iVar11 == 0) {
                                  param_1 = param_1 + -1;
                                  if (param_1 != 0) {
                                    local_60 = (BIGNUM *)ppcVar23[1];
                                    ppcVar23 = ppcVar23 + 1;
                                    goto LAB_0002231a;
                                  }
                                }
                                else {
                                  BIO_printf(bio_err,"unknown option %s\n",pcVar24);
                                }
                              }
                              goto LAB_000225d0;
                            }
                            bVar10 = true;
                            bVar9 = true;
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
LAB_0002231a:
        param_1 = param_1 + -1;
        ppcVar23 = ppcVar23 + 1;
        pcVar24 = pcVar25;
        if (param_1 < 1) break;
        goto LAB_00022324;
      }
      if (param_1 == 1) goto LAB_000225d0;
      param_1 = param_1 + -2;
      iVar22 = str2fmt(ppcVar23[1]);
      ppcVar23 = ppcVar23 + 2;
      pcVar24 = pcVar25;
    } while (0 < param_1);
  }
  ERR_load_crypto_strings();
  pBVar12 = BIO_s_file();
  bp_00 = BIO_new(pBVar12);
  pBVar12 = BIO_s_file();
  bp = BIO_new(pBVar12);
  if (bp_00 == (BIO *)0x0 || bp == (BIO *)0x0) {
    uVar21 = 1;
    ERR_print_errors(bio_err);
    local_4c = (BIO *)0x0;
    goto LAB_00022516;
  }
  if (pcVar24 == (char *)0x0) {
    BIO_ctrl(bp_00,0x6a,0,stdin);
  }
  else {
    lVar13 = BIO_ctrl(bp_00,0x6c,3,pcVar24);
    if (lVar13 < 1) {
      perror(pcVar24);
      uVar21 = 1;
      local_4c = (BIO *)0x0;
      goto LAB_00022516;
    }
  }
  if (local_6c == (BIGNUM *)0x0) {
    BIO_ctrl(bp,0x6a,0,stdout);
  }
  else {
    lVar13 = BIO_ctrl(bp,0x6c,5,local_6c);
    if (lVar13 < 1) {
      uVar21 = 1;
      perror((char *)local_6c);
      local_4c = (BIO *)0x0;
      goto LAB_00022516;
    }
  }
  setup_engine(bio_err,local_60,0);
  if (local_4c != (BIO *)0x0) {
    nitems = EC_get_builtin_curves((EC_builtin_curve *)0x0,0);
    local_4c = (BIO *)CRYPTO_malloc(nitems << 3,"ecparam.c",0x145);
    if (local_4c == (BIO *)0x0) {
      uVar21 = 1;
    }
    else {
      pBVar14 = (BIO *)EC_get_builtin_curves((EC_builtin_curve *)local_4c,nitems);
      if (pBVar14 == (BIO *)0x0) {
        uVar21 = 1;
        CRYPTO_free(local_4c);
        local_4c = pBVar14;
      }
      else {
        if (nitems != 0) {
          local_6c = (BIGNUM *)0x12afd8;
          sVar27 = 0;
          iVar26 = 0;
          do {
            sVar27 = sVar27 + 1;
            pcVar24 = *(char **)((int)&local_4c->callback + iVar26);
            pcVar25 = OBJ_nid2sn(*(int *)((int)&local_4c->method + iVar26));
            if (pcVar24 == (char *)0x0) {
              pcVar24 = "CURVE DESCRIPTION NOT AVAILABLE";
            }
            pcVar20 = (char *)local_6c;
            if (pcVar25 != (char *)0x0) {
              pcVar20 = pcVar25;
            }
            BIO_printf(bp,"  %-10s: ",pcVar20);
            BIO_printf(bp,"%s\n",pcVar24);
            iVar26 = iVar26 + 8;
          } while (sVar27 != nitems);
        }
        uVar21 = 0;
        CRYPTO_free(local_4c);
        local_4c = (BIO *)0x0;
      }
    }
    goto LAB_00022516;
  }
  if (local_5c == (BIO *)0x0) {
    if (iVar26 == 1) {
      local_4c = (BIO *)ASN1_d2i_bio((xnew *)0x0,d2i_ECPKParameters + 1,bp_00,(void **)0x0);
    }
    else {
      if (iVar26 != 3) {
        uVar21 = 1;
        BIO_printf(bio_err,"bad input format specified\n");
        local_4c = local_5c;
        goto LAB_00022516;
      }
      local_4c = (BIO *)PEM_read_bio_ECPKParameters
                                  (bp_00,(EC_GROUP **)0x0,(undefined1 *)0x0,(void *)0x0);
    }
    if (local_4c == (BIO *)0x0) {
      uVar21 = 1;
      BIO_printf(bio_err,"unable to load elliptic curve parameters\n");
      ERR_print_errors(bio_err);
      goto LAB_00022516;
    }
  }
  else {
    iVar26 = strcmp((char *)local_5c,"secp192r1");
    if (iVar26 == 0) {
      BIO_printf(bio_err,"using curve name prime192v1 instead of secp192r1\n");
      iVar26 = 0x199;
    }
    else {
      iVar26 = strcmp((char *)local_5c,"secp256r1");
      if (iVar26 == 0) {
        BIO_printf(bio_err,"using curve name prime256v1 instead of secp256r1\n");
        iVar26 = 0x19f;
      }
      else {
        iVar26 = OBJ_sn2nid((char *)local_5c);
        if (iVar26 == 0) {
          uVar21 = 1;
          BIO_printf(bio_err,"unknown curve name (%s)\n",local_5c);
          goto LAB_00022516;
        }
      }
    }
    local_4c = (BIO *)EC_GROUP_new_by_curve_name(iVar26);
    if (local_4c == (BIO *)0x0) {
      BIO_printf(bio_err,"unable to create curve (%s)\n",local_5c);
      uVar21 = 1;
      goto LAB_00022516;
    }
    EC_GROUP_set_asn1_flag((EC_GROUP *)local_4c,local_40);
    EC_GROUP_set_point_conversion_form((EC_GROUP *)local_4c,local_50);
  }
  if (bVar3) {
    EC_GROUP_set_point_conversion_form((EC_GROUP *)local_4c,local_50);
  }
  if (bVar4) {
    EC_GROUP_set_asn1_flag((EC_GROUP *)local_4c,local_40);
  }
  if (bVar5) {
    EC_GROUP_set_seed((EC_GROUP *)local_4c,(uchar *)0x0,0);
  }
  if ((bVar6) && (iVar26 = ECPKParameters_print(bp,(EC_GROUP *)local_4c,0), iVar26 == 0)) {
    uVar21 = 1;
    goto LAB_00022516;
  }
  if (bVar7) {
    BIO_printf(bio_err,"checking elliptic curve parameters: ");
    iVar26 = EC_GROUP_check((EC_GROUP *)local_4c,(BN_CTX *)0x0);
    if (iVar26 == 0) {
      uVar21 = 1;
      BIO_printf(bio_err,"failed\n");
      ERR_print_errors(bio_err);
      goto LAB_00022516;
    }
    BIO_printf(bio_err,"ok\n");
  }
  if (local_58 == (BIGNUM *)0x0) {
    local_68 = local_58;
    local_6c = local_58;
    local_64 = local_58;
    local_60 = local_58;
    order = local_58;
    cofactor = local_58;
LAB_000224a6:
    if (!bVar8) {
      if (iVar22 == 1) {
        iVar26 = ASN1_i2d_bio(i2d_ECPKParameters + 1,bp,(uchar *)local_4c);
LAB_00022b60:
        if (iVar26 != 0) goto LAB_00022a02;
        uVar21 = 1;
        BIO_printf(bio_err,"unable to write elliptic curve parameters\n");
        ERR_print_errors(bio_err);
      }
      else {
        if (iVar22 == 3) {
          iVar26 = PEM_write_bio_ECPKParameters(bp,(EC_GROUP *)local_4c);
          goto LAB_00022b60;
        }
        uVar21 = 1;
        BIO_printf(bio_err,"bad output format specified for outfile\n");
      }
      goto LAB_000224ca;
    }
LAB_00022a02:
    if (bVar9) {
      pcVar24 = local_38;
      if (local_38 != (char *)0x0) {
        pcVar24 = (char *)0x1;
      }
      app_RAND_load_file(0,bio_err,pcVar24);
      pBVar14 = bio_err;
      if (pcVar24 != (char *)0x0) {
        uVar21 = app_RAND_load_files(local_38);
        BIO_printf(pBVar14,"%ld semi-random bytes loaded\n",uVar21);
      }
      if (!bVar10) {
LAB_00022bf8:
        app_RAND_write_file(0,bio_err);
        goto LAB_00022a12;
      }
      pEVar15 = EC_KEY_new();
      if ((pEVar15 == (EC_KEY *)0x0) ||
         (iVar26 = EC_KEY_set_group(pEVar15,(EC_GROUP *)local_4c), iVar26 == 0)) goto LAB_00022ca4;
      iVar26 = EC_KEY_generate_key(pEVar15);
      if (iVar26 != 0) {
        if (iVar22 == 1) {
          i2d_ECPrivateKey_bio(bp,pEVar15);
        }
        else {
          if (iVar22 != 3) {
            uVar21 = 1;
            BIO_printf(bio_err,"bad output format specified for outfile\n");
            EC_KEY_free(pEVar15);
            goto LAB_000224ca;
          }
          PEM_write_bio_ECPrivateKey
                    (bp,pEVar15,(EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
        }
        EC_KEY_free(pEVar15);
        goto LAB_00022bf8;
      }
      uVar21 = 1;
      EC_KEY_free(pEVar15);
    }
    else {
      if (bVar10) {
        pEVar15 = EC_KEY_new();
        if (pEVar15 != (EC_KEY *)0x0) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("need_rand","ecparam.c",0x242,"ecparam_main");
        }
LAB_00022ca4:
        uVar21 = 1;
        goto LAB_000224ca;
      }
LAB_00022a12:
      uVar21 = 0;
    }
LAB_000224ca:
    if (local_60 != (BIGNUM *)0x0) goto LAB_000224ce;
  }
  else {
    meth = EC_GROUP_method_of((EC_GROUP *)local_4c);
    local_60 = BN_new();
    if ((local_60 == (BIGNUM *)0x0) || (local_64 = BN_new(), local_64 == (BIGNUM *)0x0)) {
      local_68 = (BIGNUM *)0x0;
      local_6c = (BIGNUM *)0x0;
      local_64 = (BIGNUM *)0x0;
      order = (BIGNUM *)0x0;
LAB_00022b18:
      local_58 = (BIGNUM *)0x0;
      cofactor = (BIGNUM *)0x0;
      perror("OPENSSL_malloc");
      uVar21 = 1;
      goto LAB_000224ca;
    }
    local_6c = BN_new();
    order = local_6c;
    local_68 = local_6c;
    if ((((local_6c == (BIGNUM *)0x0) ||
         (local_68 = BN_new(), order = local_68, local_68 == (BIGNUM *)0x0)) ||
        (order = BN_new(), order == (BIGNUM *)0x0)) ||
       (cofactor = BN_new(), cofactor == (BIGNUM *)0x0)) goto LAB_00022b18;
    iVar26 = EC_METHOD_get_field_type(meth);
    if (((iVar26 == 0x196) &&
        (iVar26 = EC_GROUP_get_curve_GFp
                            ((EC_GROUP *)local_4c,local_60,local_64,local_6c,(BN_CTX *)0x0),
        iVar26 != 0)) &&
       (pEVar16 = EC_GROUP_get0_generator((EC_GROUP *)local_4c), pEVar16 != (EC_POINT *)0x0)) {
      form = EC_GROUP_get_point_conversion_form((EC_GROUP *)local_4c);
      pBVar17 = EC_POINT_point2bn((EC_GROUP *)local_4c,pEVar16,form,local_68,(BN_CTX *)0x0);
      if (((pBVar17 != (BIGNUM *)0x0) &&
          (iVar26 = EC_GROUP_get_order((EC_GROUP *)local_4c,order,(BN_CTX *)0x0), iVar26 != 0)) &&
         (iVar26 = EC_GROUP_get_cofactor((EC_GROUP *)local_4c,cofactor,(BN_CTX *)0x0), iVar26 != 0))
      {
        iVar11 = BN_num_bits(order);
        iVar18 = BN_num_bits(local_60);
        iVar26 = iVar18 + 0xe;
        if (-1 < iVar18 + 7) {
          iVar26 = iVar18 + 7;
        }
        iVar19 = BN_num_bits(local_64);
        iVar18 = iVar19 + 0xe;
        if (-1 < iVar19 + 7) {
          iVar18 = iVar19 + 7;
        }
        iVar19 = BN_num_bits(local_6c);
        uVar28 = iVar18 >> 3;
        if ((uint)(iVar18 >> 3) < (uint)(iVar26 >> 3)) {
          uVar28 = iVar26 >> 3;
        }
        iVar26 = iVar19 + 0xe;
        if (-1 < iVar19 + 7) {
          iVar26 = iVar19 + 7;
        }
        if (uVar28 < (uint)(iVar26 >> 3)) {
          uVar28 = iVar26 >> 3;
        }
        iVar18 = BN_num_bits(local_68);
        iVar26 = iVar18 + 7;
        if (iVar18 + 7 < 0) {
          iVar26 = iVar18 + 0xe;
        }
        if (uVar28 < (uint)(iVar26 >> 3)) {
          uVar28 = iVar26 >> 3;
        }
        iVar18 = BN_num_bits(order);
        iVar26 = iVar18 + 7;
        if (iVar18 + 7 < 0) {
          iVar26 = iVar18 + 0xe;
        }
        if (uVar28 < (uint)(iVar26 >> 3)) {
          uVar28 = iVar26 >> 3;
        }
        iVar18 = BN_num_bits(cofactor);
        iVar26 = iVar18 + 7;
        if (iVar18 + 7 < 0) {
          iVar26 = iVar18 + 0xe;
        }
        num = iVar26 >> 3;
        if ((uint)(iVar26 >> 3) < uVar28) {
          num = uVar28;
        }
        local_58 = (BIGNUM *)CRYPTO_malloc(num,"ecparam.c",0x1df);
        if (local_58 != (BIGNUM *)0x0) {
          ecparam_print_var(bp,local_60,&DAT_0012af00,iVar11,local_58);
          ecparam_print_var(bp,local_64,&DAT_0012af08,iVar11,local_58);
          ecparam_print_var(bp,local_6c,&DAT_0012af10,iVar11,local_58);
          ecparam_print_var(bp,local_68,"ec_gen",iVar11,local_58);
          ecparam_print_var(bp,order,"ec_order",iVar11,local_58);
          ecparam_print_var(bp,cofactor,"ec_cofactor",iVar11,local_58);
          BIO_printf(bp,"\n\n");
          BIO_printf(bp,"EC_GROUP *get_ec_group_%d(void)\n\t{\n",iVar11);
          BIO_printf(bp,"\tint ok=0;\n");
          BIO_printf(bp,"\tEC_GROUP *group = NULL;\n");
          BIO_printf(bp,"\tEC_POINT *point = NULL;\n");
          BIO_printf(bp,"\tBIGNUM   *tmp_1 = NULL, *tmp_2 = NULL, *tmp_3 = NULL;\n\n");
          BIO_printf(bp,
                     "\tif ((tmp_1 = BN_bin2bn(ec_p_%d, sizeof(ec_p_%d), NULL)) == NULL)\n\t\tgoto err;\n"
                     ,iVar11,iVar11);
          BIO_printf(bp,
                     "\tif ((tmp_2 = BN_bin2bn(ec_a_%d, sizeof(ec_a_%d), NULL)) == NULL)\n\t\tgoto err;\n"
                     ,iVar11,iVar11);
          BIO_printf(bp,
                     "\tif ((tmp_3 = BN_bin2bn(ec_b_%d, sizeof(ec_b_%d), NULL)) == NULL)\n\t\tgoto err;\n"
                     ,iVar11,iVar11);
          BIO_printf(bp,
                     "\tif ((group = EC_GROUP_new_curve_GFp(tmp_1, tmp_2, tmp_3, NULL)) == NULL)\n\t\tgoto err;\n\n"
                    );
          BIO_printf(bp,"\t/* build generator */\n");
          BIO_printf(bp,
                     "\tif ((tmp_1 = BN_bin2bn(ec_gen_%d, sizeof(ec_gen_%d), tmp_1)) == NULL)\n\t\tgoto err;\n"
                     ,iVar11,iVar11);
          BIO_printf(bp,"\tpoint = EC_POINT_bn2point(group, tmp_1, NULL, NULL);\n");
          BIO_printf(bp,"\tif (point == NULL)\n\t\tgoto err;\n");
          BIO_printf(bp,
                     "\tif ((tmp_2 = BN_bin2bn(ec_order_%d, sizeof(ec_order_%d), tmp_2)) == NULL)\n\t\tgoto err;\n"
                     ,iVar11,iVar11);
          BIO_printf(bp,
                     "\tif ((tmp_3 = BN_bin2bn(ec_cofactor_%d, sizeof(ec_cofactor_%d), tmp_3)) == NULL)\n\t\tgoto err;\n"
                     ,iVar11,iVar11);
          BIO_printf(bp,
                     "\tif (!EC_GROUP_set_generator(group, point, tmp_2, tmp_3))\n\t\tgoto err;\n");
          BIO_printf(bp,"\n\tok=1;\n");
          BIO_printf(bp,"err:\n");
          BIO_printf(bp,"\tif (tmp_1)\n\t\tBN_free(tmp_1);\n");
          BIO_printf(bp,"\tif (tmp_2)\n\t\tBN_free(tmp_2);\n");
          BIO_printf(bp,"\tif (tmp_3)\n\t\tBN_free(tmp_3);\n");
          BIO_printf(bp,"\tif (point)\n\t\tEC_POINT_free(point);\n");
          BIO_printf(bp,"\tif (!ok)\n");
          BIO_printf(bp,"\t\t{\n");
          BIO_printf(bp,"\t\tEC_GROUP_free(group);\n");
          BIO_printf(bp,"\t\tgroup = NULL;\n");
          BIO_printf(bp,"\t\t}\n");
          BIO_printf(bp,"\treturn(group);\n\t}\n");
          goto LAB_000224a6;
        }
        perror("OPENSSL_malloc");
      }
    }
    local_58 = (BIGNUM *)0x0;
    uVar21 = 1;
LAB_000224ce:
    BN_free(local_60);
  }
  if (local_64 != (BIGNUM *)0x0) {
    BN_free(local_64);
  }
  if (local_6c != (BIGNUM *)0x0) {
    BN_free(local_6c);
  }
  if (local_68 != (BIGNUM *)0x0) {
    BN_free(local_68);
  }
  if (order != (BIGNUM *)0x0) {
    BN_free(order);
  }
  if (cofactor != (BIGNUM *)0x0) {
    BN_free(cofactor);
  }
  if (local_58 != (BIGNUM *)0x0) {
    CRYPTO_free(local_58);
  }
LAB_00022516:
  if (bp_00 != (BIO *)0x0) {
    BIO_free(bp_00);
  }
  if (bp != (BIO *)0x0) {
    BIO_free_all(bp);
  }
  if (local_4c != (BIO *)0x0) {
    EC_GROUP_free((EC_GROUP *)local_4c);
  }
  return uVar21;
}

