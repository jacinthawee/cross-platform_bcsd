
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
  
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar4 = (*(code *)PTR_ASN1_UTCTIME_new_006a7030)();
  if (iVar4 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"malloc error\n");
    iVar5 = 0;
    goto LAB_0041fbd8;
  }
  local_60[0] = (undefined *)0x0;
  local_60[1] = (undefined *)0x0;
  local_60[2] = (undefined *)0x0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  if (param_9 != 0) {
    param_9 = (*(code *)PTR_parse_name_006a6ff0)(param_9,param_10,param_11);
    if (param_9 == 0) {
      iVar5 = -1;
      ppiVar18 = (int **)0x0;
      iVar20 = 0;
      unaff_s1 = 0;
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
      goto LAB_0041fb2c;
    }
    (*(code *)PTR_X509_REQ_set_subject_name_006a6ff4)(param_18,param_9);
    puVar2 = PTR_X509_NAME_free_006a6ff8;
    *(undefined4 *)(*param_18 + 8) = 1;
    (*(code *)puVar2)(param_9);
  }
  if (param_23 != 0) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,
               "The Subject\'s Distinguished Name is as follows\n");
  }
  puVar2 = PTR_bio_err_006a6e3c;
  uVar19 = *(undefined4 *)(*param_18 + 0x10);
  for (iVar5 = 0; iVar20 = (*(code *)PTR_X509_NAME_entry_count_006a6f70)(uVar19), iVar5 < iVar20;
      iVar5 = iVar5 + 1) {
    puVar6 = (undefined4 *)(*(code *)PTR_X509_NAME_get_entry_006a7120)(uVar19,iVar5);
    puVar7 = (undefined4 *)(*(code *)PTR_X509_NAME_ENTRY_get_data_006a7124)(puVar6);
    uVar8 = (*(code *)PTR_X509_NAME_ENTRY_get_object_006a7128)(puVar6);
    if (msie_hack != 0) {
      iVar20 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar6);
      if (puVar7[1] == 0x1c) {
        (*(code *)PTR_ASN1_UNIVERSALSTRING_to_string_006a7130)(puVar7);
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
    iVar20 = (*(code *)PTR_OBJ_obj2nid_006a712c)(uVar8);
    if ((iVar20 != 0x30) || (param_12 != 0)) {
      iVar20 = (*(code *)PTR_OBJ_obj2nid_006a712c)(uVar8);
      iVar21 = puVar7[1];
      if ((iVar20 == 0x30) && (iVar21 != 0x16)) {
        pcVar17 = "\nemailAddress type needs to be of type IA5STRING\n";
LAB_0041f530:
        iVar5 = -1;
        ppiVar18 = (int **)0x0;
        iVar20 = 0;
        param_9 = 0;
        unaff_s1 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,pcVar17);
        goto LAB_0041fb2c;
      }
      if ((iVar21 != 0x1e) && (iVar21 != 0xc)) {
        iVar20 = (*(code *)PTR_ASN1_PRINTABLE_type_006a7134)(puVar7[2],*puVar7);
        if (iVar20 == 0x14) {
          if (puVar7[1] != 0x14) {
LAB_0041f528:
            pcVar17 = "\nThe string contains characters that are illegal for the ASN.1 type\n";
            goto LAB_0041f530;
          }
        }
        else if ((iVar20 == 0x16) && (puVar7[1] == 0x13)) goto LAB_0041f528;
      }
      if (param_23 != 0) {
        old_entry_print(*(undefined4 *)puVar2,uVar8,puVar7);
      }
    }
  }
  param_9 = (*(code *)PTR_X509_NAME_new_006a7138)();
  if (param_9 == 0) {
    iVar20 = 0;
    iVar5 = -1;
    ppiVar18 = (int **)0x0;
    unaff_s1 = 0;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"Memory allocation failure\n");
    goto LAB_0041fb2c;
  }
  if (param_25 == 0) {
    unaff_s1 = (*(code *)PTR_X509_NAME_dup_006a713c)(*(undefined4 *)(*param_3 + 0x14));
  }
  else {
    unaff_s1 = (*(code *)PTR_X509_NAME_dup_006a713c)(uVar19);
  }
  if (unaff_s1 == 0) {
LAB_0041f72c:
    iVar5 = -1;
    ppiVar18 = (int **)0x0;
    iVar20 = 0;
    goto LAB_0041fb2c;
  }
  for (local_c8 = 0; iVar5 = (*(code *)PTR_sk_num_006a6e2c)(param_6), local_c8 < iVar5;
      local_c8 = local_c8 + 1) {
    iVar5 = (*(code *)PTR_sk_value_006a6e24)(param_6,local_c8);
    iVar20 = (*(code *)PTR_OBJ_txt2nid_006a6f5c)(*(undefined4 *)(iVar5 + 4));
    if (iVar20 == 0) {
      pcVar17 = "%s:unknown object type in \'policy\' configuration\n";
      uVar8 = *(undefined4 *)(iVar5 + 4);
      uVar19 = *(undefined4 *)PTR_bio_err_006a6e3c;
LAB_0041f720:
      (*(code *)PTR_BIO_printf_006a6e38)(uVar19,pcVar17,uVar8);
      goto LAB_0041f72c;
    }
    uVar9 = (*(code *)PTR_OBJ_nid2obj_006a7140)(iVar20);
    iVar20 = -1;
LAB_0041f658:
    do {
      iVar21 = (*(code *)PTR_X509_NAME_get_index_by_OBJ_006a7144)(uVar19,uVar9,iVar20);
      if (iVar21 < 0) {
        if (iVar20 != -1) break;
        ppiVar18 = (int **)0x0;
      }
      else {
        ppiVar18 = (int **)(*(code *)PTR_X509_NAME_get_entry_006a7120)(uVar19,iVar21);
      }
      uVar8 = *(undefined4 *)(iVar5 + 8);
      iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar8,"optional");
      ppiVar11 = ppiVar18;
      iVar20 = iVar21;
      if (iVar10 == 0) {
        if (ppiVar18 != (int **)0x0) goto LAB_0041f8c8;
      }
      else {
        iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar8,"supplied");
        if (iVar10 == 0) {
          if (ppiVar18 == (int **)0x0) {
            uVar19 = *(undefined4 *)(iVar5 + 4);
            pcVar17 = "The %s field needed to be supplied and was missing\n";
LAB_0041f7c4:
            iVar5 = -1;
            iVar20 = 0;
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,pcVar17,uVar19);
            goto LAB_0041fb2c;
          }
        }
        else {
          iVar21 = (*(code *)PTR_strcmp_006a9b18)(uVar8,"match");
          if (iVar21 != 0) {
            pcVar17 = "%s:invalid type in \'policy\' configuration\n";
            uVar19 = *(undefined4 *)PTR_bio_err_006a6e3c;
            goto LAB_0041f720;
          }
          iVar10 = -1;
          if (ppiVar18 == (int **)0x0) {
            uVar19 = *(undefined4 *)(iVar5 + 4);
            pcVar17 = "The mandatory %s field was missing\n";
            goto LAB_0041f7c4;
          }
          do {
            iVar21 = (*(code *)PTR_X509_NAME_get_index_by_OBJ_006a7144)(unaff_s1,uVar9,iVar10);
            if (iVar21 < 0) {
              uVar8 = *(undefined4 *)(iVar5 + 4);
              puVar6 = (undefined4 *)PTR_bio_err_006a6e3c;
              pcVar23 = (code *)PTR_BIO_printf_006a6e38;
              if (iVar10 != -1) goto LAB_0041fb08;
              uVar19 = *(undefined4 *)PTR_bio_err_006a6e3c;
              pcVar17 = 
              "The %s field does not exist in the CA certificate,\nthe \'policy\' is misconfigured\n"
              ;
              goto LAB_0041f720;
            }
            ppiVar11 = (int **)(*(code *)PTR_X509_NAME_get_entry_006a7120)(unaff_s1,iVar21);
            uVar8 = (*(code *)PTR_X509_NAME_ENTRY_get_data_006a7124)(ppiVar18);
            uVar12 = (*(code *)PTR_X509_NAME_ENTRY_get_data_006a7124)(ppiVar11);
            iVar13 = (*(code *)PTR_ASN1_STRING_cmp_006a7148)(uVar8,uVar12);
            iVar10 = iVar21;
          } while (iVar13 != 0);
          if (ppiVar11 == (int **)0x0) goto LAB_0041f658;
        }
LAB_0041f8c8:
        iVar10 = (*(code *)PTR_X509_NAME_add_entry_006a714c)(param_9,ppiVar11,0xffffffff,0);
        if (iVar10 == 0) {
          iVar5 = -1;
          ppiVar18 = (int **)0x0;
          (*(code *)PTR_X509_NAME_ENTRY_free_006a7150)(ppiVar11);
          iVar20 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)PTR_bio_err_006a6e3c,"Memory allocation failure\n");
          goto LAB_0041fb2c;
        }
      }
    } while (-1 < iVar21);
  }
  if (preserve != 0) {
    (*(code *)PTR_X509_NAME_free_006a6ff8)(param_9);
    param_9 = (*(code *)PTR_X509_NAME_dup_006a713c)(uVar19);
    if (param_9 == 0) {
      iVar20 = 0;
      iVar5 = -1;
      ppiVar18 = (int **)0x0;
      goto LAB_0041fb2c;
    }
  }
  if (param_17 != 0) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,
               "The subject name appears to be ok, checking data base for clashes\n");
  }
  iVar20 = param_9;
  if (param_12 == 0) {
    iVar20 = (*(code *)PTR_X509_NAME_dup_006a713c)(param_9);
    if (iVar20 != 0) {
      while (iVar5 = (*(code *)PTR_X509_NAME_get_index_by_NID_006a7154)(iVar20,0x30,0xffffffff),
            -1 < iVar5) {
        uVar19 = (*(code *)PTR_X509_NAME_get_entry_006a7120)(iVar20,iVar5);
        (*(code *)PTR_X509_NAME_delete_entry_006a7158)(iVar20,iVar5);
        (*(code *)PTR_X509_NAME_ENTRY_free_006a7150)(uVar19);
      }
      goto LAB_0041fa1c;
    }
  }
  else {
LAB_0041fa1c:
    if (*(int *)(param_8 + 4) == 0) {
      local_54 = (*(code *)PTR_BUF_strdup_006a6fdc)("00");
    }
    else {
      local_54 = (*(code *)PTR_BN_bn2hex_006a7018)(param_8);
    }
    if (local_54 != 0) {
      if ((*param_7 == 0) ||
         (ppcVar14 = (char **)(*(code *)PTR_TXT_DB_get_by_index_006a7020)(param_7[1],5,local_60),
         ppcVar14 == (char **)0x0)) {
        ppcVar14 = (char **)(*(code *)PTR_TXT_DB_get_by_index_006a7020)(param_7[1],3,local_60);
        puVar2 = PTR_bio_err_006a6e3c;
        if (ppcVar14 == (char **)0x0) {
          if (param_17 != 0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)PTR_bio_err_006a6e3c,
                       "Everything appears to be ok, creating and signing the certificate\n");
          }
          ppiVar18 = (int **)(*(code *)PTR_X509_new_006a6ee8)();
          if (ppiVar18 != (int **)0x0) {
            piVar22 = *ppiVar18;
            iVar5 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(param_8,piVar22[1]);
            if (iVar5 != 0) {
              if (param_25 == 0) {
                uVar19 = (*(code *)PTR_X509_get_subject_name_006a6f00)(param_3);
                iVar5 = (*(code *)PTR_X509_set_issuer_name_006a6f88)(ppiVar18,uVar19);
              }
              else {
                iVar5 = (*(code *)PTR_X509_set_issuer_name_006a6f88)(ppiVar18,param_9);
              }
              if (iVar5 != 0) {
                iVar5 = (*(code *)PTR_strcmp_006a9b18)(param_13,"today");
                if (iVar5 == 0) {
                  (*(code *)PTR_X509_gmtime_adj_006a6f8c)(*(undefined4 *)(*ppiVar18)[4],0);
                }
                else {
                  (*(code *)PTR_ASN1_TIME_set_string_006a7084)
                            (*(undefined4 *)(*ppiVar18)[4],param_13);
                }
                if (param_14 == 0) {
                  (*(code *)PTR_X509_time_adj_ex_006a6f90)
                            (*(undefined4 *)((*ppiVar18)[4] + 4),param_15,0,0);
                }
                else {
                  (*(code *)PTR_ASN1_TIME_set_string_006a7084)
                            (*(undefined4 *)((*ppiVar18)[4] + 4),param_14);
                }
                iVar5 = (*(code *)PTR_X509_set_subject_name_006a6f94)(ppiVar18,param_9);
                if (iVar5 != 0) {
                  uVar19 = (*(code *)PTR_X509_REQ_get_pubkey_006a6ef4)(param_18);
                  iVar5 = (*(code *)PTR_X509_set_pubkey_006a6f98)(ppiVar18,uVar19);
                  (*(code *)PTR_EVP_PKEY_free_006a6e78)(uVar19);
                  if (iVar5 != 0) {
                    if (param_19 != 0) {
                      if (*piVar22 == 0) {
                        iVar5 = (*(code *)PTR_ASN1_INTEGER_new_006a7160)();
                        *piVar22 = iVar5;
                        if (iVar5 == 0) {
                          iVar5 = -1;
                          goto LAB_0041fb2c;
                        }
                      }
                      (*(code *)PTR_ASN1_INTEGER_set_006a7164)(*piVar22,2);
                      if (piVar22[9] != 0) {
                        (*(code *)PTR_sk_pop_free_006a7058)
                                  (piVar22[9],PTR_X509_EXTENSION_free_006a7168);
                      }
                      puVar2 = PTR_X509V3_set_ctx_006a6eb4;
                      piVar22[9] = 0;
                      if (param_25 == 0) {
                        (*(code *)puVar2)(auStack_7c,param_3,ppiVar18,param_18,0,0);
                      }
                      else {
                        (*(code *)puVar2)(auStack_7c,ppiVar18,ppiVar18,param_18,0,0);
                      }
                      if (extconf == 0) {
                        (*(code *)PTR_X509V3_set_nconf_006a6eb8)(auStack_7c,param_20);
                        iVar5 = (*(code *)PTR_X509V3_EXT_add_nconf_006a6ebc)
                                          (param_20,auStack_7c,param_19,ppiVar18);
                        if (iVar5 == 0) goto LAB_0041ff80;
                        if (param_17 != 0) {
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)PTR_bio_err_006a6e3c,
                                     "Successfully added extensions from config\n");
                        }
                      }
                      else {
                        if (param_17 != 0) {
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)PTR_bio_err_006a6e3c,
                                     "Extra configuration file found\n");
                        }
                        (*(code *)PTR_X509V3_set_nconf_006a6eb8)(auStack_7c,extconf);
                        iVar5 = (*(code *)PTR_X509V3_EXT_add_nconf_006a6ebc)
                                          (extconf,auStack_7c,param_19,ppiVar18);
                        if (iVar5 == 0) {
LAB_0041ff80:
                          puVar2 = PTR_bio_err_006a6e3c;
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)PTR_bio_err_006a6e3c,
                                     "ERROR: adding extensions in section %s\n",param_19);
                          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
                          goto LAB_004203a4;
                        }
                        if (param_17 != 0) {
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)PTR_bio_err_006a6e3c,
                                     "Successfully added extensions from file.\n");
                        }
                      }
                    }
                    iVar5 = (*(code *)PTR_copy_extensions_006a715c)(ppiVar18,param_18,param_24);
                    puVar2 = PTR_bio_err_006a6e3c;
                    if (iVar5 == 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)PTR_bio_err_006a6e3c,
                                 "ERROR: adding extensions from request\n");
                      iVar5 = -1;
                      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
                      goto LAB_0041fb2c;
                    }
                    if ((param_12 != 0) ||
                       (iVar5 = (*(code *)PTR_X509_set_subject_name_006a6f94)(ppiVar18,iVar20),
                       iVar5 != 0)) {
                      puVar2 = PTR_bio_err_006a6e3c;
                      if (param_23 == 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)PTR_bio_err_006a6e3c,"Certificate Details:\n");
                        (*(code *)PTR_X509_print_ex_006a6efc)
                                  (*(undefined4 *)puVar2,ppiVar18,param_22,param_21 | 0x208);
                      }
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar2,"Certificate is to be certified until ");
                      (*(code *)PTR_ASN1_TIME_print_006a716c)
                                (*(undefined4 *)puVar2,*(undefined4 *)((*ppiVar18)[4] + 4));
                      if (param_15 != 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)PTR_bio_err_006a6e3c," (%ld days)",param_15);
                      }
                      puVar3 = PTR_bio_err_006a6e3c;
                      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"\n");
                      if (param_16 == 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar3,"Sign the certificate? [y/n]:");
                        (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar3,0xb,0,0);
                        local_48[0] = 0;
                        iVar5 = (*(code *)PTR_fgets_006a9ae0)
                                          (local_48,0x18,*(undefined4 *)PTR_stdin_006a9a14);
                        if (iVar5 == 0) {
                          iVar5 = 0;
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)puVar3,
                                     "CERTIFICATE WILL NOT BE CERTIFIED: I/O error\n");
                          goto LAB_0041fb2c;
                        }
                        if ((local_48[0] & 0xdf) != 0x59) {
                          iVar5 = 0;
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)puVar3,"CERTIFICATE WILL NOT BE CERTIFIED\n");
                          goto LAB_0041fb2c;
                        }
                      }
                      uVar19 = (*(code *)PTR_X509_get_pubkey_006a6f08)(ppiVar18);
                      iVar5 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a7170)(uVar19);
                      if ((iVar5 != 0) &&
                         (iVar5 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a7170)(param_2),
                         iVar5 == 0)) {
                        (*(code *)PTR_EVP_PKEY_copy_parameters_006a7174)(uVar19,param_2);
                      }
                      (*(code *)PTR_EVP_PKEY_free_006a6e78)(uVar19);
                      iVar5 = do_X509_sign(*(undefined4 *)puVar2,ppiVar18,param_2,param_4,param_5);
                      if (iVar5 != 0) {
                        local_60[0] = (undefined *)
                                      (*(code *)PTR_CRYPTO_malloc_006a7008)(2,&DAT_0063526c,0x82f);
                        piVar22 = *(int **)((*ppiVar18)[4] + 4);
                        local_60[1] = (undefined *)
                                      (*(code *)PTR_CRYPTO_malloc_006a7008)
                                                (*piVar22 + 1,&DAT_0063526c,0x832);
                        (*(code *)PTR_memcpy_006a9aec)(local_60[1],piVar22[2],*piVar22);
                        puVar3 = PTR_CRYPTO_malloc_006a7008;
                        *(undefined *)((int)local_60[1] + *piVar22) = 0;
                        local_60[2] = (undefined *)0x0;
                        local_50 = (*(code *)puVar3)(8,&DAT_0063526c,0x839);
                        uVar19 = (*(code *)PTR_X509_get_subject_name_006a6f00)(ppiVar18);
                        local_4c = (*(code *)PTR_X509_NAME_oneline_006a7010)(uVar19,0,0);
                        if ((((local_60[0] == (undefined *)0x0) || (local_60[1] == (undefined *)0x0)
                             ) || (local_50 == 0)) || (local_4c == 0)) {
                          uVar19 = *(undefined4 *)puVar2;
                        }
                        else {
                          (*(code *)PTR_BUF_strlcpy_006a6f64)(local_50,"unknown",8);
                          *local_60[0] = 0x56;
                          puVar3 = PTR_CRYPTO_malloc_006a7008;
                          local_60[0][1] = 0;
                          puVar6 = (undefined4 *)(*(code *)puVar3)(0x1c,&DAT_0063526c,0x846);
                          if (puVar6 != (undefined4 *)0x0) {
                            puVar7 = puVar6;
                            ppuVar15 = local_60;
                            do {
                              puVar16 = puVar7 + 1;
                              *puVar7 = *ppuVar15;
                              puVar3 = PTR_TXT_DB_insert_006a7028;
                              *ppuVar15 = (undefined *)0x0;
                              puVar7 = puVar16;
                              ppuVar15 = ppuVar15 + 1;
                            } while (puVar16 != puVar6 + 6);
                            puVar6[6] = 0;
                            iVar5 = (*(code *)puVar3)(param_7[1],puVar6);
                            if (iVar5 == 0) {
                              (*(code *)PTR_BIO_printf_006a6e38)
                                        (*(undefined4 *)puVar2,"failed to update database\n");
                              iVar5 = -1;
                              (*(code *)PTR_BIO_printf_006a6e38)
                                        (*(undefined4 *)puVar2,"TXT_DB error number %ld\n",
                                         *(undefined4 *)(param_7[1] + 0x10));
                            }
                            else {
                              iVar5 = 1;
                            }
                            goto LAB_0041fb2c;
                          }
                          uVar19 = *(undefined4 *)PTR_bio_err_006a6e3c;
                        }
                        (*(code *)PTR_BIO_printf_006a6e38)(uVar19,"Memory allocation failure\n");
                      }
                    }
                  }
                }
              }
            }
          }
LAB_004203a4:
          iVar5 = -1;
          goto LAB_0041fb2c;
        }
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)PTR_bio_err_006a6e3c,
                   "ERROR:Serial number %s has already been issued,\n",local_54);
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar2,"      check the database/serial_file for corruption\n");
      }
      else {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)PTR_bio_err_006a6e3c,
                   "ERROR:There is already a certificate for %s\n",local_4c);
      }
      puVar2 = PTR_bio_err_006a6e3c;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,
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
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Type          :%s\n",pcVar17);
      if (**ppcVar14 == 'R') {
        pcVar17 = ppcVar14[1];
        if (pcVar17 == (char *)0x0) {
          pcVar17 = "undef";
        }
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Was revoked on:%s\n",pcVar17);
      }
      pcVar17 = ppcVar14[1];
      if (pcVar17 == (char *)0x0) {
        pcVar17 = "undef";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Expires on    :%s\n",pcVar17);
      pcVar17 = ppcVar14[3];
      if (pcVar17 == (char *)0x0) {
        pcVar17 = "undef";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Serial Number :%s\n",pcVar17);
      pcVar17 = ppcVar14[4];
      if (pcVar17 == (char *)0x0) {
        pcVar17 = "undef";
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"File name     :%s\n",pcVar17);
      pcVar17 = ppcVar14[5];
      if (pcVar17 == (char *)0x0) {
        pcVar17 = "undef";
      }
      ppiVar18 = (int **)0x0;
      iVar5 = -1;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Subject Name  :%s\n",pcVar17);
      goto LAB_0041fb2c;
    }
  }
  iVar5 = -1;
  ppiVar18 = (int **)0x0;
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)PTR_bio_err_006a6e3c,"Memory allocation failure\n");
LAB_0041fb2c:
  while( true ) {
    iVar21 = 0;
    ppuVar15 = local_60;
    do {
      if (*ppuVar15 != (undefined *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      iVar21 = iVar21 + 4;
      ppuVar15 = (undefined **)((int)local_60 + iVar21);
    } while (iVar21 != 0x18);
    if (unaff_s1 != 0) {
      (*(code *)PTR_X509_NAME_free_006a6ff8)(unaff_s1);
    }
    if (param_9 != 0) {
      (*(code *)PTR_X509_NAME_free_006a6ff8)(param_9);
    }
    if ((iVar20 != 0) && (param_12 == 0)) {
      (*(code *)PTR_X509_NAME_free_006a6ff8)(iVar20);
    }
    (*(code *)PTR_ASN1_UTCTIME_free_006a700c)(iVar4);
    if (iVar5 == 1) {
      *param_1 = (int *)ppiVar18;
      iVar5 = 1;
    }
    else if (ppiVar18 != (int **)0x0) {
      (*(code *)PTR_X509_free_006a6e90)(ppiVar18);
    }
LAB_0041fbd8:
    if (local_2c == *(int *)PTR___stack_chk_guard_006a9ae8) break;
    pcVar23 = (code *)PTR___stack_chk_fail_006a9ab0;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    puVar6 = extraout_v1;
LAB_0041fb08:
    iVar5 = -1;
    ppiVar18 = (int **)0x0;
    (*pcVar23)(*puVar6,
               "The %s field needed to be the same in the\nCA certificate (%s) and the request (%s)\n"
              );
    iVar20 = 0;
  }
  return iVar5;
}

