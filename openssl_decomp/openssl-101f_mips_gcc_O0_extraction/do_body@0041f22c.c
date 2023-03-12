
int do_body(int **param_1,undefined4 param_2,int *param_3,undefined4 param_4,undefined4 param_5,
           undefined4 param_6,int *param_7,int param_8,int param_9,undefined4 param_10,
           undefined4 param_11,int param_12,undefined4 param_13,int param_14,int param_15,
           int param_16,int param_17,int *param_18,int param_19,undefined4 param_20,uint param_21,
           undefined4 param_22,int param_23,undefined4 param_24,int param_25)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int **ppiVar11;
  undefined4 uVar12;
  int iVar13;
  char **ppcVar14;
  undefined **ppuVar15;
  undefined4 *extraout_v1;
  undefined4 *puVar16;
  char *pcVar17;
  int unaff_s1;
  int **ppiVar18;
  undefined4 uVar19;
  int iVar20;
  int iVar21;
  int *piVar22;
  code *pcVar23;
  int local_c8;
  undefined auStack_7c [28];
  undefined *local_60 [3];
  int local_54;
  int local_50;
  int local_4c;
  byte local_48 [28];
  int local_2c;
  
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar4 = (*(code *)PTR_ASN1_UTCTIME_new_006a8130)();
  if (iVar4 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,"malloc error\n");
    iVar5 = 0;
    goto LAB_0041fc00;
  }
  local_60[0] = (undefined *)0x0;
  local_60[1] = (undefined *)0x0;
  local_60[2] = (undefined *)0x0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  if (param_9 != 0) {
    param_9 = (*(code *)PTR_parse_name_006a80f0)(param_9,param_10,param_11);
    if (param_9 == 0) {
      iVar5 = -1;
      ppiVar18 = (int **)0x0;
      iVar20 = 0;
      unaff_s1 = 0;
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
      goto LAB_0041fb54;
    }
    (*(code *)PTR_X509_REQ_set_subject_name_006a80f4)(param_18,param_9);
    puVar2 = PTR_X509_NAME_free_006a80f8;
    *(undefined4 *)(*param_18 + 8) = 1;
    (*(code *)puVar2)(param_9);
  }
  if (param_23 != 0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,
               "The Subject\'s Distinguished Name is as follows\n");
  }
  puVar2 = PTR_bio_err_006a7f3c;
  uVar19 = *(undefined4 *)(*param_18 + 0x10);
  for (iVar5 = 0; iVar20 = (*(code *)PTR_X509_NAME_entry_count_006a8074)(uVar19), iVar5 < iVar20;
      iVar5 = iVar5 + 1) {
    puVar6 = (undefined4 *)(*(code *)PTR_X509_NAME_get_entry_006a8220)(uVar19,iVar5);
    puVar7 = (undefined4 *)(*(code *)PTR_X509_NAME_ENTRY_get_data_006a8224)(puVar6);
    uVar8 = (*(code *)PTR_X509_NAME_ENTRY_get_object_006a8228)(puVar6);
    if (msie_hack != 0) {
      iVar20 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar6);
      if (puVar7[1] == 0x1c) {
        (*(code *)PTR_ASN1_UNIVERSALSTRING_to_string_006a8230)(puVar7);
      }
      if (puVar7[1] == 0x16) {
        if (iVar20 != 0x30) {
          puVar7[1] = 0x14;
        }
      }
      else if ((iVar20 == 0x30) && (puVar7[1] == 0x13)) {
        puVar7[1] = 0x16;
      }
    }
    iVar20 = (*(code *)PTR_OBJ_obj2nid_006a822c)(uVar8);
    if ((iVar20 != 0x30) || (param_12 != 0)) {
      iVar20 = (*(code *)PTR_OBJ_obj2nid_006a822c)(uVar8);
      iVar21 = puVar7[1];
      if ((iVar20 == 0x30) && (iVar21 != 0x16)) {
        pcVar17 = "\nemailAddress type needs to be of type IA5STRING\n";
LAB_0041f558:
        iVar5 = -1;
        ppiVar18 = (int **)0x0;
        iVar20 = 0;
        param_9 = 0;
        unaff_s1 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,pcVar17);
        goto LAB_0041fb54;
      }
      if ((iVar21 != 0x1e) && (iVar21 != 0xc)) {
        iVar20 = (*(code *)PTR_ASN1_PRINTABLE_type_006a8234)(puVar7[2],*puVar7);
        if (iVar20 == 0x14) {
          if (puVar7[1] != 0x14) {
LAB_0041f550:
            pcVar17 = "\nThe string contains characters that are illegal for the ASN.1 type\n";
            goto LAB_0041f558;
          }
        }
        else if ((iVar20 == 0x16) && (puVar7[1] == 0x13)) goto LAB_0041f550;
      }
      if (param_23 != 0) {
        old_entry_print(*(undefined4 *)puVar2,uVar8,puVar7);
      }
    }
  }
  param_9 = (*(code *)PTR_X509_NAME_new_006a8238)();
  if (param_9 == 0) {
    iVar20 = 0;
    iVar5 = -1;
    ppiVar18 = (int **)0x0;
    unaff_s1 = 0;
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"Memory allocation failure\n");
    goto LAB_0041fb54;
  }
  if (param_25 == 0) {
    unaff_s1 = (*(code *)PTR_X509_NAME_dup_006a823c)(*(undefined4 *)(*param_3 + 0x14));
  }
  else {
    unaff_s1 = (*(code *)PTR_X509_NAME_dup_006a823c)(uVar19);
  }
  if (unaff_s1 == 0) {
LAB_0041f754:
    iVar5 = -1;
    ppiVar18 = (int **)0x0;
    iVar20 = 0;
    goto LAB_0041fb54;
  }
  for (local_c8 = 0; iVar5 = (*(code *)PTR_sk_num_006a7f2c)(param_6), local_c8 < iVar5;
      local_c8 = local_c8 + 1) {
    iVar5 = (*(code *)PTR_sk_value_006a7f24)(param_6,local_c8);
    iVar20 = (*(code *)PTR_OBJ_txt2nid_006a805c)(*(undefined4 *)(iVar5 + 4));
    if (iVar20 == 0) {
      pcVar17 = "%s:unknown object type in \'policy\' configuration\n";
      uVar8 = *(undefined4 *)(iVar5 + 4);
      uVar19 = *(undefined4 *)PTR_bio_err_006a7f3c;
LAB_0041f748:
      (*(code *)PTR_BIO_printf_006a7f38)(uVar19,pcVar17,uVar8);
      goto LAB_0041f754;
    }
    uVar9 = (*(code *)PTR_OBJ_nid2obj_006a8240)(iVar20);
    iVar20 = -1;
LAB_0041f680:
    do {
      iVar21 = (*(code *)PTR_X509_NAME_get_index_by_OBJ_006a8244)(uVar19,uVar9,iVar20);
      if (iVar21 < 0) {
        if (iVar20 != -1) break;
        ppiVar18 = (int **)0x0;
      }
      else {
        ppiVar18 = (int **)(*(code *)PTR_X509_NAME_get_entry_006a8220)(uVar19,iVar21);
      }
      uVar8 = *(undefined4 *)(iVar5 + 8);
      iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar8,"optional");
      ppiVar11 = ppiVar18;
      iVar20 = iVar21;
      if (iVar10 == 0) {
        if (ppiVar18 != (int **)0x0) goto LAB_0041f8f0;
      }
      else {
        iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar8,"supplied");
        if (iVar10 == 0) {
          if (ppiVar18 == (int **)0x0) {
            uVar19 = *(undefined4 *)(iVar5 + 4);
            pcVar17 = "The %s field needed to be supplied and was missing\n";
LAB_0041f7ec:
            iVar5 = -1;
            iVar20 = 0;
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,pcVar17,uVar19);
            goto LAB_0041fb54;
          }
        }
        else {
          iVar21 = (*(code *)PTR_strcmp_006aac20)(uVar8,"match");
          if (iVar21 != 0) {
            pcVar17 = "%s:invalid type in \'policy\' configuration\n";
            uVar19 = *(undefined4 *)PTR_bio_err_006a7f3c;
            goto LAB_0041f748;
          }
          iVar10 = -1;
          if (ppiVar18 == (int **)0x0) {
            uVar19 = *(undefined4 *)(iVar5 + 4);
            pcVar17 = "The mandatory %s field was missing\n";
            goto LAB_0041f7ec;
          }
          do {
            iVar21 = (*(code *)PTR_X509_NAME_get_index_by_OBJ_006a8244)(unaff_s1,uVar9,iVar10);
            if (iVar21 < 0) {
              uVar8 = *(undefined4 *)(iVar5 + 4);
              puVar6 = (undefined4 *)PTR_bio_err_006a7f3c;
              pcVar23 = (code *)PTR_BIO_printf_006a7f38;
              if (iVar10 != -1) goto LAB_0041fb30;
              uVar19 = *(undefined4 *)PTR_bio_err_006a7f3c;
              pcVar17 = 
              "The %s field does not exist in the CA certificate,\nthe \'policy\' is misconfigured\n"
              ;
              goto LAB_0041f748;
            }
            ppiVar11 = (int **)(*(code *)PTR_X509_NAME_get_entry_006a8220)(unaff_s1,iVar21);
            uVar8 = (*(code *)PTR_X509_NAME_ENTRY_get_data_006a8224)(ppiVar18);
            uVar12 = (*(code *)PTR_X509_NAME_ENTRY_get_data_006a8224)(ppiVar11);
            iVar13 = (*(code *)PTR_ASN1_STRING_cmp_006a8248)(uVar8,uVar12);
            iVar10 = iVar21;
          } while (iVar13 != 0);
          if (ppiVar11 == (int **)0x0) goto LAB_0041f680;
        }
LAB_0041f8f0:
        iVar10 = (*(code *)PTR_X509_NAME_add_entry_006a824c)(param_9,ppiVar11,0xffffffff,0);
        if (iVar10 == 0) {
          iVar5 = -1;
          ppiVar18 = (int **)0x0;
          (*(code *)PTR_X509_NAME_ENTRY_free_006a8250)(ppiVar11);
          iVar20 = 0;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)PTR_bio_err_006a7f3c,"Memory allocation failure\n");
          goto LAB_0041fb54;
        }
      }
    } while (-1 < iVar21);
  }
  if (preserve != 0) {
    (*(code *)PTR_X509_NAME_free_006a80f8)(param_9);
    param_9 = (*(code *)PTR_X509_NAME_dup_006a823c)(uVar19);
    if (param_9 == 0) {
      iVar20 = 0;
      iVar5 = -1;
      ppiVar18 = (int **)0x0;
      goto LAB_0041fb54;
    }
  }
  if (param_17 != 0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,
               "The subject name appears to be ok, checking data base for clashes\n");
  }
  iVar20 = param_9;
  if (param_12 == 0) {
    iVar20 = (*(code *)PTR_X509_NAME_dup_006a823c)(param_9);
    if (iVar20 != 0) {
      while (iVar5 = (*(code *)PTR_X509_NAME_get_index_by_NID_006a8254)(iVar20,0x30,0xffffffff),
            -1 < iVar5) {
        uVar19 = (*(code *)PTR_X509_NAME_get_entry_006a8220)(iVar20,iVar5);
        (*(code *)PTR_X509_NAME_delete_entry_006a8258)(iVar20,iVar5);
        (*(code *)PTR_X509_NAME_ENTRY_free_006a8250)(uVar19);
      }
      goto LAB_0041fa44;
    }
  }
  else {
LAB_0041fa44:
    if (*(int *)(param_8 + 4) == 0) {
      local_54 = (*(code *)PTR_BUF_strdup_006a80dc)("00");
    }
    else {
      local_54 = (*(code *)PTR_BN_bn2hex_006a8118)(param_8);
    }
    if (local_54 != 0) {
      if ((*param_7 == 0) ||
         (ppcVar14 = (char **)(*(code *)PTR_TXT_DB_get_by_index_006a8120)(param_7[1],5,local_60),
         ppcVar14 == (char **)0x0)) {
        ppcVar14 = (char **)(*(code *)PTR_TXT_DB_get_by_index_006a8120)(param_7[1],3,local_60);
        puVar2 = PTR_bio_err_006a7f3c;
        if (ppcVar14 == (char **)0x0) {
          if (param_17 != 0) {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)PTR_bio_err_006a7f3c,
                       "Everything appears to be ok, creating and signing the certificate\n");
          }
          ppiVar18 = (int **)(*(code *)PTR_X509_new_006a7fe8)();
          if (ppiVar18 != (int **)0x0) {
            piVar22 = *ppiVar18;
            iVar5 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(param_8,piVar22[1]);
            if (iVar5 != 0) {
              if (param_25 == 0) {
                uVar19 = (*(code *)PTR_X509_get_subject_name_006a8000)(param_3);
                iVar5 = (*(code *)PTR_X509_set_issuer_name_006a8088)(ppiVar18,uVar19);
              }
              else {
                iVar5 = (*(code *)PTR_X509_set_issuer_name_006a8088)(ppiVar18,param_9);
              }
              if (iVar5 != 0) {
                iVar5 = (*(code *)PTR_strcmp_006aac20)(param_13,"today");
                if (iVar5 == 0) {
                  (*(code *)PTR_X509_gmtime_adj_006a808c)(*(undefined4 *)(*ppiVar18)[4],0);
                }
                else {
                  (*(code *)PTR_ASN1_TIME_set_string_006a8184)
                            (*(undefined4 *)(*ppiVar18)[4],param_13);
                }
                if (param_14 == 0) {
                  (*(code *)PTR_X509_time_adj_ex_006a8090)
                            (*(undefined4 *)((*ppiVar18)[4] + 4),param_15,0,0);
                }
                else {
                  (*(code *)PTR_ASN1_TIME_set_string_006a8184)
                            (*(undefined4 *)((*ppiVar18)[4] + 4),param_14);
                }
                iVar5 = (*(code *)PTR_X509_set_subject_name_006a8094)(ppiVar18,param_9);
                if (iVar5 != 0) {
                  uVar19 = (*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(param_18);
                  iVar5 = (*(code *)PTR_X509_set_pubkey_006a8098)(ppiVar18,uVar19);
                  (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar19);
                  if (iVar5 != 0) {
                    if (param_19 != 0) {
                      if (*piVar22 == 0) {
                        iVar5 = (*(code *)PTR_ASN1_INTEGER_new_006a8260)();
                        *piVar22 = iVar5;
                        if (iVar5 == 0) {
                          iVar5 = -1;
                          goto LAB_0041fb54;
                        }
                      }
                      (*(code *)PTR_ASN1_INTEGER_set_006a8264)(*piVar22,2);
                      if (piVar22[9] != 0) {
                        (*(code *)PTR_sk_pop_free_006a8158)
                                  (piVar22[9],PTR_X509_EXTENSION_free_006a8268);
                      }
                      puVar2 = PTR_X509V3_set_ctx_006a7fb4;
                      piVar22[9] = 0;
                      if (param_25 == 0) {
                        (*(code *)puVar2)(auStack_7c,param_3,ppiVar18,param_18,0,0);
                      }
                      else {
                        (*(code *)puVar2)(auStack_7c,ppiVar18,ppiVar18,param_18,0,0);
                      }
                      if (extconf == 0) {
                        (*(code *)PTR_X509V3_set_nconf_006a7fb8)(auStack_7c,param_20);
                        iVar5 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)
                                          (param_20,auStack_7c,param_19,ppiVar18);
                        if (iVar5 == 0) goto LAB_0041ffa8;
                        if (param_17 != 0) {
                          (*(code *)PTR_BIO_printf_006a7f38)
                                    (*(undefined4 *)PTR_bio_err_006a7f3c,
                                     "Successfully added extensions from config\n");
                        }
                      }
                      else {
                        if (param_17 != 0) {
                          (*(code *)PTR_BIO_printf_006a7f38)
                                    (*(undefined4 *)PTR_bio_err_006a7f3c,
                                     "Extra configuration file found\n");
                        }
                        (*(code *)PTR_X509V3_set_nconf_006a7fb8)(auStack_7c,extconf);
                        iVar5 = (*(code *)PTR_X509V3_EXT_add_nconf_006a7fbc)
                                          (extconf,auStack_7c,param_19,ppiVar18);
                        if (iVar5 == 0) {
LAB_0041ffa8:
                          puVar2 = PTR_bio_err_006a7f3c;
                          (*(code *)PTR_BIO_printf_006a7f38)
                                    (*(undefined4 *)PTR_bio_err_006a7f3c,
                                     "ERROR: adding extensions in section %s\n",param_19);
                          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
                          goto LAB_004203cc;
                        }
                        if (param_17 != 0) {
                          (*(code *)PTR_BIO_printf_006a7f38)
                                    (*(undefined4 *)PTR_bio_err_006a7f3c,
                                     "Successfully added extensions from file.\n");
                        }
                      }
                    }
                    iVar5 = (*(code *)PTR_copy_extensions_006a825c)(ppiVar18,param_18,param_24);
                    puVar2 = PTR_bio_err_006a7f3c;
                    if (iVar5 == 0) {
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)PTR_bio_err_006a7f3c,
                                 "ERROR: adding extensions from request\n");
                      iVar5 = -1;
                      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
                      goto LAB_0041fb54;
                    }
                    if ((param_12 != 0) ||
                       (iVar5 = (*(code *)PTR_X509_set_subject_name_006a8094)(ppiVar18,iVar20),
                       iVar5 != 0)) {
                      puVar2 = PTR_bio_err_006a7f3c;
                      if (param_23 == 0) {
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*(undefined4 *)PTR_bio_err_006a7f3c,"Certificate Details:\n");
                        (*(code *)PTR_X509_print_ex_006a7ffc)
                                  (*(undefined4 *)puVar2,ppiVar18,param_22,param_21 | 0x208);
                      }
                      (*(code *)PTR_BIO_printf_006a7f38)
                                (*(undefined4 *)puVar2,"Certificate is to be certified until ");
                      (*(code *)PTR_ASN1_TIME_print_006a826c)
                                (*(undefined4 *)puVar2,*(undefined4 *)((*ppiVar18)[4] + 4));
                      if (param_15 != 0) {
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*(undefined4 *)PTR_bio_err_006a7f3c," (%ld days)",param_15);
                      }
                      puVar3 = PTR_bio_err_006a7f3c;
                      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"\n");
                      if (param_16 == 0) {
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*(undefined4 *)puVar3,"Sign the certificate? [y/n]:");
                        (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)puVar3,0xb,0,0);
                        local_48[0] = 0;
                        iVar5 = (*(code *)PTR_fgets_006aabe8)
                                          (local_48,0x18,*(undefined4 *)PTR_stdin_006aab20);
                        if (iVar5 == 0) {
                          iVar5 = 0;
                          (*(code *)PTR_BIO_printf_006a7f38)
                                    (*(undefined4 *)puVar3,
                                     "CERTIFICATE WILL NOT BE CERTIFIED: I/O error\n");
                          goto LAB_0041fb54;
                        }
                        if ((local_48[0] & 0xdf) != 0x59) {
                          iVar5 = 0;
                          (*(code *)PTR_BIO_printf_006a7f38)
                                    (*(undefined4 *)puVar3,"CERTIFICATE WILL NOT BE CERTIFIED\n");
                          goto LAB_0041fb54;
                        }
                      }
                      uVar19 = (*(code *)PTR_X509_get_pubkey_006a8008)(ppiVar18);
                      iVar5 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a8270)(uVar19);
                      if ((iVar5 != 0) &&
                         (iVar5 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a8270)(param_2),
                         iVar5 == 0)) {
                        (*(code *)PTR_EVP_PKEY_copy_parameters_006a8274)(uVar19,param_2);
                      }
                      (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar19);
                      iVar5 = do_X509_sign(*(undefined4 *)puVar2,ppiVar18,param_2,param_4,param_5);
                      if (iVar5 != 0) {
                        local_60[0] = (undefined *)
                                      (*(code *)PTR_CRYPTO_malloc_006a8108)(2,&DAT_00635b2c,0x881);
                        piVar22 = *(int **)((*ppiVar18)[4] + 4);
                        local_60[1] = (undefined *)
                                      (*(code *)PTR_CRYPTO_malloc_006a8108)
                                                (*piVar22 + 1,&DAT_00635b2c,0x884);
                        (*(code *)PTR_memcpy_006aabf4)(local_60[1],piVar22[2],*piVar22);
                        puVar3 = PTR_CRYPTO_malloc_006a8108;
                        *(undefined *)((int)local_60[1] + *piVar22) = 0;
                        local_60[2] = (undefined *)0x0;
                        local_50 = (*(code *)puVar3)(8,&DAT_00635b2c,0x88b);
                        uVar19 = (*(code *)PTR_X509_get_subject_name_006a8000)(ppiVar18);
                        local_4c = (*(code *)PTR_X509_NAME_oneline_006a8110)(uVar19,0,0);
                        if ((((local_60[0] == (undefined *)0x0) || (local_60[1] == (undefined *)0x0)
                             ) || (local_50 == 0)) || (local_4c == 0)) {
                          uVar19 = *(undefined4 *)puVar2;
                        }
                        else {
                          (*(code *)PTR_BUF_strlcpy_006a8064)(local_50,"unknown",8);
                          *local_60[0] = 0x56;
                          puVar3 = PTR_CRYPTO_malloc_006a8108;
                          local_60[0][1] = 0;
                          puVar6 = (undefined4 *)(*(code *)puVar3)(0x1c,&DAT_00635b2c,0x898);
                          if (puVar6 != (undefined4 *)0x0) {
                            puVar7 = puVar6;
                            ppuVar15 = local_60;
                            do {
                              puVar16 = puVar7 + 1;
                              *puVar7 = *ppuVar15;
                              puVar3 = PTR_TXT_DB_insert_006a8128;
                              *ppuVar15 = (undefined *)0x0;
                              puVar7 = puVar16;
                              ppuVar15 = ppuVar15 + 1;
                            } while (puVar16 != puVar6 + 6);
                            puVar6[6] = 0;
                            iVar5 = (*(code *)puVar3)(param_7[1],puVar6);
                            if (iVar5 == 0) {
                              (*(code *)PTR_BIO_printf_006a7f38)
                                        (*(undefined4 *)puVar2,"failed to update database\n");
                              iVar5 = -1;
                              (*(code *)PTR_BIO_printf_006a7f38)
                                        (*(undefined4 *)puVar2,"TXT_DB error number %ld\n",
                                         *(undefined4 *)(param_7[1] + 0x10));
                            }
                            else {
                              iVar5 = 1;
                            }
                            goto LAB_0041fb54;
                          }
                          uVar19 = *(undefined4 *)PTR_bio_err_006a7f3c;
                        }
                        (*(code *)PTR_BIO_printf_006a7f38)(uVar19,"Memory allocation failure\n");
                      }
                    }
                  }
                }
              }
            }
          }
LAB_004203cc:
          iVar5 = -1;
          goto LAB_0041fb54;
        }
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,
                   "ERROR:Serial number %s has already been issued,\n",local_54);
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar2,"      check the database/serial_file for corruption\n");
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,
                   "ERROR:There is already a certificate for %s\n",local_4c);
      }
      puVar2 = PTR_bio_err_006a7f3c;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,
                 "The matching entry has the following details\n");
      cVar1 = **ppcVar14;
      if (cVar1 == 'E') {
        pcVar17 = "Expired";
      }
      else if (cVar1 == 'R') {
        pcVar17 = "Revoked";
      }
      else if (cVar1 == 'V') {
        pcVar17 = "Valid";
      }
      else {
        pcVar17 = "\ninvalid type, Data base error\n";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Type\t  :%s\n",pcVar17);
      if (**ppcVar14 == 'R') {
        pcVar17 = ppcVar14[1];
        if (pcVar17 == (char *)0x0) {
          pcVar17 = "undef";
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Was revoked on:%s\n",pcVar17);
      }
      pcVar17 = ppcVar14[1];
      if (pcVar17 == (char *)0x0) {
        pcVar17 = "undef";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Expires on    :%s\n",pcVar17);
      pcVar17 = ppcVar14[3];
      if (pcVar17 == (char *)0x0) {
        pcVar17 = "undef";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Serial Number :%s\n",pcVar17);
      pcVar17 = ppcVar14[4];
      if (pcVar17 == (char *)0x0) {
        pcVar17 = "undef";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"File name     :%s\n",pcVar17);
      pcVar17 = ppcVar14[5];
      if (pcVar17 == (char *)0x0) {
        pcVar17 = "undef";
      }
      ppiVar18 = (int **)0x0;
      iVar5 = -1;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"Subject Name  :%s\n",pcVar17);
      goto LAB_0041fb54;
    }
  }
  iVar5 = -1;
  ppiVar18 = (int **)0x0;
  (*(code *)PTR_BIO_printf_006a7f38)
            (*(undefined4 *)PTR_bio_err_006a7f3c,"Memory allocation failure\n");
LAB_0041fb54:
  while( true ) {
    iVar21 = 0;
    ppuVar15 = local_60;
    do {
      if (*ppuVar15 != (undefined *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      iVar21 = iVar21 + 4;
      ppuVar15 = (undefined **)((int)local_60 + iVar21);
    } while (iVar21 != 0x18);
    if (unaff_s1 != 0) {
      (*(code *)PTR_X509_NAME_free_006a80f8)(unaff_s1);
    }
    if (param_9 != 0) {
      (*(code *)PTR_X509_NAME_free_006a80f8)(param_9);
    }
    if ((iVar20 != 0) && (param_12 == 0)) {
      (*(code *)PTR_X509_NAME_free_006a80f8)(iVar20);
    }
    (*(code *)PTR_ASN1_UTCTIME_free_006a810c)(iVar4);
    if (iVar5 == 1) {
      *param_1 = (int *)ppiVar18;
      iVar5 = 1;
    }
    else if (ppiVar18 != (int **)0x0) {
      (*(code *)PTR_X509_free_006a7f90)(ppiVar18);
    }
LAB_0041fc00:
    if (local_2c == *(int *)PTR___stack_chk_guard_006aabf0) break;
    pcVar23 = (code *)PTR___stack_chk_fail_006aabb8;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    puVar6 = extraout_v1;
LAB_0041fb30:
    iVar5 = -1;
    ppiVar18 = (int **)0x0;
    (*pcVar23)(*puVar6,
               "The %s field needed to be the same in the\nCA certificate (%s) and the request (%s)\n"
              );
    iVar20 = 0;
  }
  return iVar5;
}

