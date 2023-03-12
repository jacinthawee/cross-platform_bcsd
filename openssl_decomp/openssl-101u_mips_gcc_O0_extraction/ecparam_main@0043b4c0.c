
undefined4 ecparam_main(int param_1,undefined4 *param_2)

{
  char cVar1;
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
  undefined *puVar12;
  undefined *puVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  char **ppcVar21;
  char *pcVar22;
  char *pcVar23;
  int iVar24;
  char **ppcVar25;
  uint uVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  char *local_80;
  int local_7c;
  char *local_78;
  int local_74;
  char *local_64;
  undefined4 local_54;
  undefined4 local_4c;
  char *local_44;
  char *local_34;
  
  puVar12 = PTR_bio_err_006a6e3c;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iVar20 = *(int *)puVar12;
  if (iVar20 == 0) {
    uVar15 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar20 = (*(code *)PTR_BIO_new_006a6ea4)(uVar15);
    *(int *)puVar12 = iVar20;
    if (iVar20 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar20,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
      iVar20 = *(int *)puVar12;
    }
  }
  iVar20 = (*(code *)PTR_load_config_006a6e64)(iVar20,0);
  if (iVar20 == 0) {
    uVar15 = 1;
    iVar16 = 0;
    iVar20 = 0;
    iVar24 = 0;
    goto LAB_0043b908;
  }
  uVar14 = *param_2;
  param_1 = param_1 + -1;
  ppcVar25 = (char **)(param_2 + 1);
  if (param_1 < 1) {
    bVar8 = false;
    bVar9 = false;
    iVar29 = 3;
    iVar24 = 3;
    local_78 = (char *)0x0;
    local_4c = 1;
    local_80 = (char *)0x0;
    bVar11 = false;
    bVar10 = false;
    bVar6 = false;
    bVar7 = false;
    bVar5 = false;
    bVar2 = false;
    local_34 = (char *)0x0;
    local_64 = (char *)0x0;
    bVar4 = false;
    bVar3 = false;
    local_54 = 4;
    local_44 = (char *)0x0;
  }
  else {
    local_44 = (char *)0x0;
    bVar8 = false;
    bVar9 = false;
    local_4c = 1;
    iVar29 = 3;
    local_78 = (char *)0x0;
    iVar24 = 3;
    local_80 = (char *)0x0;
    local_54 = 4;
    bVar11 = false;
    bVar10 = false;
    bVar6 = false;
    bVar7 = false;
    bVar5 = false;
    bVar2 = false;
    local_34 = (char *)0x0;
    local_64 = (char *)0x0;
    bVar4 = false;
    bVar3 = false;
LAB_0043b600:
    do {
      pcVar22 = *ppcVar25;
      iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"-inform");
      if (iVar20 == 0) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          ppcVar21 = ppcVar25 + 1;
          iVar24 = str2fmt(ppcVar25[1]);
          goto LAB_0043b5f4;
        }
LAB_0043ba80:
        uVar15 = 1;
        iVar16 = 0;
        iVar20 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,"%s [options] <infile >outfile\n",uVar14);
        iVar24 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar12,"where options are\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,
                   " -inform arg       input format - default PEM (DER or PEM)\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12," -outform arg      output format - default PEM\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12," -in  arg          input file  - default stdin\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12," -out arg          output file - default stdout\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12," -noout            do not print the ec parameter\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,
                   " -text             print the ec parameters in text form\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12," -check            validate the ec parameters\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,
                   " -C                print a \'C\' function creating the parameters\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,
                   " -name arg         use the ec parameters with \'short name\' name\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,
                   " -list_curves      prints a list of all currently available curve \'short names\'\n"
                  );
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,
                   " -conv_form arg    specifies the point conversion form \n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,"                   possible values: compressed\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,
                   "                                    uncompressed (default)\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,"                                    hybrid\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,
                   " -param_enc arg    specifies the way the ec parameters are encoded\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,"                   in the asn1 der encoding\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,
                   "                   possible values: named_curve (default)\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,"                                    explicit\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,
                   " -no_seed          if \'explicit\' parameters are chosen do not use the seed\n")
        ;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12," -genkey           generate ec key\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,
                   " -rand file        files to use for random number input\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar12,
                   " -engine e         use engine e, possibly a hardware device\n");
        goto LAB_0043b908;
      }
      iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"-outform");
      if (iVar20 == 0) {
        if (param_1 == 1) goto LAB_0043ba80;
        ppcVar21 = ppcVar25 + 1;
        param_1 = param_1 + -2;
        ppcVar25 = ppcVar25 + 2;
        iVar29 = str2fmt(*ppcVar21);
        if (param_1 == 0) break;
        goto LAB_0043b600;
      }
      cVar1 = *pcVar22;
      if ((((cVar1 == '-') && (pcVar22[1] == 'i')) && (pcVar22[2] == 'n')) && (pcVar22[3] == '\0'))
      {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_0043ba80;
        local_80 = ppcVar25[1];
        ppcVar21 = ppcVar25 + 1;
      }
      else {
        iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,&DAT_00632514);
        if (iVar20 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0043ba80;
          local_78 = ppcVar25[1];
          ppcVar21 = ppcVar25 + 1;
        }
        else {
          iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"-text");
          ppcVar21 = ppcVar25;
          if (iVar20 == 0) {
            bVar6 = true;
          }
          else if (((cVar1 == '-') && (pcVar22[1] == 'C')) && (pcVar22[2] == '\0')) {
            bVar8 = true;
          }
          else {
            iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"-check");
            if (iVar20 == 0) {
              bVar7 = true;
            }
            else {
              iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"-name");
              if (iVar20 == 0) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_0043ba80;
                local_64 = ppcVar25[1];
                ppcVar21 = ppcVar25 + 1;
              }
              else {
                iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"-list_curves");
                if (iVar20 == 0) {
                  bVar2 = true;
                }
                else {
                  iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"-conv_form");
                  if (iVar20 == 0) {
                    param_1 = param_1 + -1;
                    if (param_1 == 0) goto LAB_0043ba80;
                    pcVar22 = ppcVar25[1];
                    ppcVar21 = ppcVar25 + 1;
                    iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"compressed");
                    if (iVar20 == 0) {
                      bVar3 = true;
                      local_54 = 2;
                    }
                    else {
                      iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"uncompressed");
                      if (iVar20 == 0) {
                        bVar3 = true;
                        local_54 = 4;
                      }
                      else {
                        iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"hybrid");
                        if (iVar20 != 0) goto LAB_0043ba80;
                        bVar3 = true;
                        local_54 = 6;
                      }
                    }
                  }
                  else {
                    iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"-param_enc");
                    if (iVar20 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 == 0) goto LAB_0043ba80;
                      pcVar22 = ppcVar25[1];
                      iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"named_curve");
                      ppcVar21 = ppcVar25 + 1;
                      if (iVar20 == 0) {
                        bVar4 = true;
                        local_4c = 1;
                      }
                      else {
                        iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"explicit");
                        if (iVar20 != 0) goto LAB_0043ba80;
                        local_4c = 0;
                        bVar4 = true;
                      }
                    }
                    else {
                      iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"-no_seed");
                      if (iVar20 == 0) {
                        bVar5 = true;
                      }
                      else {
                        iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"-noout");
                        if (iVar20 == 0) {
                          bVar9 = true;
                        }
                        else {
                          iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"-genkey");
                          if (iVar20 != 0) {
                            iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"-rand");
                            if (iVar20 == 0) {
                              param_1 = param_1 + -1;
                              if (param_1 != 0) {
                                local_34 = ppcVar25[1];
                                bVar10 = true;
                                ppcVar21 = ppcVar25 + 1;
                                goto LAB_0043b5f4;
                              }
                            }
                            else {
                              iVar20 = (*(code *)PTR_strcmp_006a9b18)(pcVar22,"-engine");
                              if (iVar20 == 0) {
                                param_1 = param_1 + -1;
                                if (param_1 != 0) {
                                  local_44 = ppcVar25[1];
                                  ppcVar21 = ppcVar25 + 1;
                                  goto LAB_0043b5f4;
                                }
                              }
                              else {
                                (*(code *)PTR_BIO_printf_006a6e38)
                                          (*(undefined4 *)puVar12,"unknown option %s\n",pcVar22);
                              }
                            }
                            goto LAB_0043ba80;
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
LAB_0043b5f4:
      param_1 = param_1 + -1;
      ppcVar25 = ppcVar21 + 1;
    } while (param_1 != 0);
  }
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  uVar15 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar20 = (*(code *)PTR_BIO_new_006a6ea4)(uVar15);
  uVar15 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar16 = (*(code *)PTR_BIO_new_006a6ea4)(uVar15);
  if ((iVar20 == 0) || (iVar16 == 0)) {
    uVar15 = 1;
    iVar24 = 0;
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar12);
    goto LAB_0043b908;
  }
  if (local_80 == (char *)0x0) {
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar20,0x6a,0,*(undefined4 *)PTR_stdin_006a9a14);
  }
  else {
    iVar17 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar20,0x6c,3,local_80);
    if (iVar17 < 1) {
      uVar15 = 1;
      iVar24 = 0;
      (*(code *)PTR_perror_006a9a80)(local_80);
      goto LAB_0043b908;
    }
  }
  if (local_78 == (char *)0x0) {
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar16,0x6a,0,*(undefined4 *)PTR_stdout_006a99c8);
  }
  else {
    iVar17 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar16,0x6c,5,local_78);
    if (iVar17 < 1) {
      uVar15 = 1;
      iVar24 = 0;
      (*(code *)PTR_perror_006a9a80)(local_78);
      goto LAB_0043b908;
    }
  }
  puVar13 = PTR_bio_err_006a6e3c;
  (*(code *)PTR_setup_engine_006a6ec4)(*(undefined4 *)puVar12,local_44,0);
  if (bVar2) {
    iVar24 = (*(code *)PTR_EC_get_builtin_curves_006a71a0)(0,0);
    iVar29 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar24 << 3,"ecparam.c",0x145);
    if (iVar29 == 0) {
      uVar15 = 1;
      iVar24 = 0;
    }
    else {
      iVar17 = (*(code *)PTR_EC_get_builtin_curves_006a71a0)(iVar29,iVar24);
      if (iVar17 == 0) {
        uVar15 = 1;
        iVar24 = 0;
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar29);
      }
      else {
        if (iVar24 != 0) {
          iVar17 = 0;
          ppcVar25 = (char **)(iVar29 + 4);
          do {
            iVar17 = iVar17 + 1;
            pcVar23 = *ppcVar25;
            pcVar22 = (char *)(*(code *)PTR_OBJ_nid2sn_006a709c)(ppcVar25[-1]);
            if (pcVar22 == (char *)0x0) {
              pcVar22 = "";
            }
            if (pcVar23 == (char *)0x0) {
              pcVar23 = "CURVE DESCRIPTION NOT AVAILABLE";
            }
            (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"  %-10s: ",pcVar22);
            (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"%s\n",pcVar23);
            ppcVar25 = ppcVar25 + 2;
          } while (iVar24 != iVar17);
        }
        uVar15 = 0;
        iVar24 = 0;
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar29);
      }
    }
    goto LAB_0043b908;
  }
  if (local_64 == (char *)0x0) {
    if (iVar24 == 1) {
      iVar24 = (*(code *)PTR_ASN1_d2i_bio_006a71c4)(0,PTR_d2i_ECPKParameters_006a71c8,iVar20,0);
    }
    else {
      if (iVar24 != 3) {
        uVar15 = 1;
        iVar24 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"bad input format specified\n");
        goto LAB_0043b908;
      }
      iVar24 = (*(code *)PTR_PEM_read_bio_ECPKParameters_006a71c0)(iVar20,0,0,0);
    }
    if (iVar24 == 0) {
      uVar15 = 1;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar12,"unable to load elliptic curve parameters\n");
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar12);
      goto LAB_0043b908;
    }
  }
  else {
    iVar24 = (*(code *)PTR_strcmp_006a9b18)(local_64,"secp192r1");
    if (iVar24 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar13,"using curve name prime192v1 instead of secp192r1\n");
      iVar24 = 0x199;
    }
    else {
      iVar24 = (*(code *)PTR_strcmp_006a9b18)(local_64,"secp256r1");
      if (iVar24 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,"using curve name prime256v1 instead of secp256r1\n");
        iVar24 = 0x19f;
      }
      else {
        iVar24 = (*(code *)PTR_OBJ_sn2nid_006a71a4)(local_64);
        if (iVar24 == 0) {
          uVar15 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar13,"unknown curve name (%s)\n",local_64);
          iVar24 = 0;
          goto LAB_0043b908;
        }
      }
    }
    iVar24 = (*(code *)PTR_EC_GROUP_new_by_curve_name_006a7184)(iVar24);
    if (iVar24 == 0) {
      uVar15 = 1;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar12,"unable to create curve (%s)\n",local_64);
      goto LAB_0043b908;
    }
    (*(code *)PTR_EC_GROUP_set_asn1_flag_006a7188)(iVar24,local_4c);
    (*(code *)PTR_EC_GROUP_set_point_conversion_form_006a718c)(iVar24,local_54);
  }
  if (bVar3) {
    (*(code *)PTR_EC_GROUP_set_point_conversion_form_006a718c)(iVar24,local_54);
  }
  if (bVar4) {
    (*(code *)PTR_EC_GROUP_set_asn1_flag_006a7188)(iVar24,local_4c);
  }
  if (bVar5) {
    (*(code *)PTR_EC_GROUP_set_seed_006a7190)(iVar24,0,0);
  }
  if ((bVar6) &&
     (iVar17 = (*(code *)PTR_ECPKParameters_print_006a7194)(iVar16,iVar24,0), iVar17 == 0)) {
    uVar15 = 1;
    goto LAB_0043b908;
  }
  puVar13 = PTR_bio_err_006a6e3c;
  if (bVar7) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar12,"checking elliptic curve parameters: ");
    iVar17 = (*(code *)PTR_EC_GROUP_check_006a71ac)(iVar24,0);
    if (iVar17 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"failed\n");
      uVar15 = 1;
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar13);
      goto LAB_0043b908;
    }
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"ok\n");
  }
  iVar17 = 0;
  if (bVar8) {
    uVar15 = (*(code *)PTR_EC_GROUP_method_of_006a71b0)(iVar24);
    local_80 = (char *)(*(code *)PTR_BN_new_006a71b4)();
    if ((local_80 == (char *)0x0) ||
       (local_78 = (char *)(*(code *)PTR_BN_new_006a71b4)(), local_78 == (char *)0x0)) {
      iVar27 = 0;
      local_7c = 0;
      local_74 = 0;
      local_78 = (char *)0x0;
LAB_0043c42c:
      iVar17 = 0;
      iVar28 = 0;
      (*(code *)PTR_perror_006a9a80)("OPENSSL_malloc");
      uVar15 = 1;
      goto LAB_0043b868;
    }
    local_74 = (*(code *)PTR_BN_new_006a71b4)();
    if (local_74 == 0) {
      iVar27 = 0;
      local_7c = 0;
      goto LAB_0043c42c;
    }
    local_7c = (*(code *)PTR_BN_new_006a71b4)();
    if (local_7c == 0) {
      iVar27 = 0;
      goto LAB_0043c42c;
    }
    iVar27 = (*(code *)PTR_BN_new_006a71b4)();
    if ((iVar27 == 0) || (iVar28 = (*(code *)PTR_BN_new_006a71b4)(), iVar28 == 0))
    goto LAB_0043c42c;
    iVar17 = (*(code *)PTR_EC_METHOD_get_field_type_006a71b8)(uVar15);
    if (((iVar17 == 0x196) &&
        (iVar17 = (*(code *)PTR_EC_GROUP_get_curve_GFp_006a71dc)
                            (iVar24,local_80,local_78,local_74,0), iVar17 != 0)) &&
       (iVar17 = (*(code *)PTR_EC_GROUP_get0_generator_006a71e0)(iVar24), iVar17 != 0)) {
      uVar15 = (*(code *)PTR_EC_GROUP_get_point_conversion_form_006a71e4)(iVar24);
      iVar17 = (*(code *)PTR_EC_POINT_point2bn_006a71e8)(iVar24,iVar17,uVar15,local_7c,0);
      if (((iVar17 != 0) &&
          (iVar17 = (*(code *)PTR_EC_GROUP_get_order_006a71ec)(iVar24,iVar27,0), iVar17 != 0)) &&
         (iVar17 = (*(code *)PTR_EC_GROUP_get_cofactor_006a71f0)(iVar24,iVar28,0), iVar17 != 0)) {
        uVar15 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar27);
        iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)(local_80);
        iVar17 = iVar18 + 7;
        if (iVar18 + 7 < 0) {
          iVar17 = iVar18 + 0xe;
        }
        iVar19 = (*(code *)PTR_BN_num_bits_006a71f4)(local_78);
        iVar18 = iVar19 + 7;
        if (iVar19 + 7 < 0) {
          iVar18 = iVar19 + 0xe;
        }
        uVar26 = iVar17 >> 3;
        if ((uint)(iVar17 >> 3) < (uint)(iVar18 >> 3)) {
          uVar26 = iVar18 >> 3;
        }
        iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)(local_74);
        iVar17 = iVar18 + 7;
        if (iVar18 + 7 < 0) {
          iVar17 = iVar18 + 0xe;
        }
        if (uVar26 <= (uint)(iVar17 >> 3)) {
          uVar26 = iVar17 >> 3;
        }
        iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)(local_7c);
        iVar17 = iVar18 + 7;
        if (iVar18 + 7 < 0) {
          iVar17 = iVar18 + 0xe;
        }
        if (uVar26 <= (uint)(iVar17 >> 3)) {
          uVar26 = iVar17 >> 3;
        }
        iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar27);
        iVar17 = iVar18 + 7;
        if (iVar18 + 7 < 0) {
          iVar17 = iVar18 + 0xe;
        }
        if (uVar26 <= (uint)(iVar17 >> 3)) {
          uVar26 = iVar17 >> 3;
        }
        iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar28);
        iVar17 = iVar18 + 7;
        if (iVar18 + 7 < 0) {
          iVar17 = iVar18 + 0xe;
        }
        if (uVar26 <= (uint)(iVar17 >> 3)) {
          uVar26 = iVar17 >> 3;
        }
        iVar17 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar26,"ecparam.c",0x1df);
        if (iVar17 != 0) {
          ecparam_print_var(iVar16,local_80,&DAT_00638cb4,uVar15,iVar17);
          ecparam_print_var(iVar16,local_78,&DAT_00638cbc,uVar15,iVar17);
          ecparam_print_var(iVar16,local_74,&DAT_00638cc4,uVar15,iVar17);
          ecparam_print_var(iVar16,local_7c,"ec_gen",uVar15,iVar17);
          ecparam_print_var(iVar16,iVar27,"ec_order",uVar15,iVar17);
          ecparam_print_var(iVar16,iVar28,"ec_cofactor",uVar15,iVar17);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,&DAT_00638660);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"EC_GROUP *get_ec_group_%d(void)\n\t{\n",uVar15)
          ;
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"\tint ok=0;\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"\tEC_GROUP *group = NULL;\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"\tEC_POINT *point = NULL;\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (iVar16,"\tBIGNUM   *tmp_1 = NULL, *tmp_2 = NULL, *tmp_3 = NULL;\n\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (iVar16,
                     "\tif ((tmp_1 = BN_bin2bn(ec_p_%d, sizeof(ec_p_%d), NULL)) == NULL)\n\t\tgoto err;\n"
                     ,uVar15,uVar15);
          (*(code *)PTR_BIO_printf_006a6e38)
                    (iVar16,
                     "\tif ((tmp_2 = BN_bin2bn(ec_a_%d, sizeof(ec_a_%d), NULL)) == NULL)\n\t\tgoto err;\n"
                     ,uVar15,uVar15);
          (*(code *)PTR_BIO_printf_006a6e38)
                    (iVar16,
                     "\tif ((tmp_3 = BN_bin2bn(ec_b_%d, sizeof(ec_b_%d), NULL)) == NULL)\n\t\tgoto err;\n"
                     ,uVar15,uVar15);
          (*(code *)PTR_BIO_printf_006a6e38)
                    (iVar16,
                     "\tif ((group = EC_GROUP_new_curve_GFp(tmp_1, tmp_2, tmp_3, NULL)) == NULL)\n\t\tgoto err;\n\n"
                    );
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"\t/* build generator */\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (iVar16,
                     "\tif ((tmp_1 = BN_bin2bn(ec_gen_%d, sizeof(ec_gen_%d), tmp_1)) == NULL)\n\t\tgoto err;\n"
                     ,uVar15,uVar15);
          (*(code *)PTR_BIO_printf_006a6e38)
                    (iVar16,"\tpoint = EC_POINT_bn2point(group, tmp_1, NULL, NULL);\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"\tif (point == NULL)\n\t\tgoto err;\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (iVar16,
                     "\tif ((tmp_2 = BN_bin2bn(ec_order_%d, sizeof(ec_order_%d), tmp_2)) == NULL)\n\t\tgoto err;\n"
                     ,uVar15,uVar15);
          (*(code *)PTR_BIO_printf_006a6e38)
                    (iVar16,
                     "\tif ((tmp_3 = BN_bin2bn(ec_cofactor_%d, sizeof(ec_cofactor_%d), tmp_3)) == NULL)\n\t\tgoto err;\n"
                     ,uVar15,uVar15);
          (*(code *)PTR_BIO_printf_006a6e38)
                    (iVar16,
                     "\tif (!EC_GROUP_set_generator(group, point, tmp_2, tmp_3))\n\t\tgoto err;\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"\n\tok=1;\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"err:\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"\tif (tmp_1)\n\t\tBN_free(tmp_1);\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"\tif (tmp_2)\n\t\tBN_free(tmp_2);\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"\tif (tmp_3)\n\t\tBN_free(tmp_3);\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"\tif (point)\n\t\tEC_POINT_free(point);\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"\tif (!ok)\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,&DAT_00639148);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"\t\tEC_GROUP_free(group);\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"\t\tgroup = NULL;\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,&DAT_00639180);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar16,"\treturn(group);\n\t}\n");
          goto LAB_0043b82c;
        }
        (*(code *)PTR_perror_006a9a80)("OPENSSL_malloc");
      }
    }
    iVar17 = 0;
    uVar15 = 1;
LAB_0043b874:
    (*(code *)PTR_BN_free_006a701c)(local_80);
  }
  else {
    local_7c = 0;
    iVar28 = 0;
    local_74 = 0;
    iVar27 = 0;
    local_78 = (char *)0x0;
    local_80 = (char *)0x0;
LAB_0043b82c:
    if (bVar9) {
LAB_0043c200:
      if (bVar10) {
        (*(code *)PTR_app_RAND_load_file_006a6ecc)(0,*(undefined4 *)puVar12,local_34 != (char *)0x0)
        ;
        if (local_34 != (char *)0x0) {
          uVar14 = *(undefined4 *)PTR_bio_err_006a6e3c;
          uVar15 = (*(code *)PTR_app_RAND_load_files_006a6f38)(local_34);
          (*(code *)PTR_BIO_printf_006a6e38)(uVar14,"%ld semi-random bytes loaded\n",uVar15);
        }
        if (bVar11) {
          iVar18 = (*(code *)PTR_EC_KEY_new_006a71a8)();
          if ((iVar18 == 0) ||
             (iVar19 = (*(code *)PTR_EC_KEY_set_group_006a71cc)(iVar18,iVar24), iVar19 == 0)) {
            uVar15 = 1;
          }
          else {
            iVar19 = (*(code *)PTR_EC_KEY_generate_key_006a71d0)(iVar18);
            if (iVar19 != 0) {
              if (iVar29 == 1) {
                (*(code *)PTR_i2d_ECPrivateKey_bio_006a71fc)(iVar16,iVar18);
              }
              else {
                if (iVar29 != 3) {
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar12,"bad output format specified for outfile\n");
                  uVar15 = 1;
                  (*(code *)PTR_EC_KEY_free_006a71d4)(iVar18);
                  goto LAB_0043b868;
                }
                (*(code *)PTR_PEM_write_bio_ECPrivateKey_006a71f8)(iVar16,iVar18,0,0,0,0,0);
              }
              (*(code *)PTR_EC_KEY_free_006a71d4)(iVar18);
              goto LAB_0043c570;
            }
            uVar15 = 1;
            (*(code *)PTR_EC_KEY_free_006a71d4)(iVar18);
          }
        }
        else {
LAB_0043c570:
          uVar15 = 0;
          (*(code *)PTR_app_RAND_write_file_006a6f4c)(0,*(undefined4 *)puVar12);
        }
      }
      else if (bVar11) {
        uVar15 = 1;
        iVar29 = (*(code *)PTR_EC_KEY_new_006a71a8)();
        if (iVar29 != 0) {
          uVar15 = (*(code *)PTR___assert_fail_006a993c)
                             ("need_rand","ecparam.c",0x242,"ecparam_main");
          return uVar15;
        }
      }
      else {
        uVar15 = 0;
      }
    }
    else if (iVar29 == 1) {
      iVar18 = (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_ECPKParameters_006a71d8,iVar16,iVar24);
LAB_0043c464:
      if (iVar18 != 0) goto LAB_0043c200;
      uVar15 = 1;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar12,"unable to write elliptic curve parameters\n");
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar12);
    }
    else {
      if (iVar29 == 3) {
        iVar18 = (*(code *)PTR_PEM_write_bio_ECPKParameters_006a71bc)(iVar16,iVar24);
        goto LAB_0043c464;
      }
      uVar15 = 1;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar12,"bad output format specified for outfile\n");
    }
LAB_0043b868:
    if (local_80 != (char *)0x0) goto LAB_0043b874;
  }
  if (local_78 != (char *)0x0) {
    (*(code *)PTR_BN_free_006a701c)();
  }
  if (local_74 != 0) {
    (*(code *)PTR_BN_free_006a701c)();
  }
  if (local_7c != 0) {
    (*(code *)PTR_BN_free_006a701c)();
  }
  if (iVar27 != 0) {
    (*(code *)PTR_BN_free_006a701c)(iVar27);
  }
  if (iVar28 != 0) {
    (*(code *)PTR_BN_free_006a701c)(iVar28);
  }
  if (iVar17 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar17);
  }
LAB_0043b908:
  if (iVar20 != 0) {
    (*(code *)PTR_BIO_free_006a6e70)(iVar20);
  }
  if (iVar16 != 0) {
    (*(code *)PTR_BIO_free_all_006a6e74)(iVar16);
  }
  if (iVar24 != 0) {
    (*(code *)PTR_EC_GROUP_free_006a719c)(iVar24);
  }
  return uVar15;
}

