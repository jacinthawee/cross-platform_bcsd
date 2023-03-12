
uint do_cmd(undefined4 param_1,char *param_2,char **param_3)

{
  int *piVar1;
  char cVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  char **ppcVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  char *pcVar12;
  code *pcVar13;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  undefined4 local_40;
  char *local_3c;
  undefined4 local_38;
  char *local_34;
  undefined *local_30;
  char **local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(char ***)PTR___stack_chk_guard_006a9ae8;
  if (((int)param_2 < 1) || (*param_3 == (char *)0x0)) {
    uVar5 = 0;
    goto LAB_00421908;
  }
  local_34 = *param_3;
  iVar4 = (*(code *)PTR_lh_retrieve_006a73b0)(param_1,&local_38);
  if (iVar4 == 0) {
    iVar4 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(*param_3);
    if (iVar4 == 0) {
      iVar4 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(*param_3);
      if (iVar4 == 0) {
        pcVar12 = *param_3;
        iVar4 = (*(code *)PTR_strncmp_006a9970)(pcVar12,&DAT_006319bc,3);
        if (iVar4 == 0) {
          uVar8 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
          local_34 = *param_3 + 3;
          iVar4 = (*(code *)PTR_lh_retrieve_006a73b0)(param_1,&local_38);
          uVar5 = (uint)(iVar4 != 0);
          if (iVar4 == 0) {
            param_2 = "%s\n";
            (*(code *)PTR_BIO_printf_006a6e38)(uVar8,"%s\n",*param_3);
          }
          else {
            param_2 = "%s\n";
            (*(code *)PTR_BIO_printf_006a6e38)(uVar8,"%s\n",*param_3 + 3);
          }
          (*(code *)PTR_BIO_free_all_006a6e74)(uVar8);
          goto LAB_00421908;
        }
        param_2 = &DAT_006317e8;
        iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar12);
        if (iVar4 != 0) {
          cVar2 = *pcVar12;
          if (cVar2 == 'q') {
            if (pcVar12[1] != '\0') {
              param_2 = &DAT_006317f0;
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar12);
              if (iVar4 != 0) goto LAB_00421a18;
            }
          }
          else {
            param_2 = &DAT_006317f0;
            iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar12);
            if ((iVar4 != 0) &&
               ((((cVar2 != 'b' || (pcVar12[1] != 'y')) || (pcVar12[2] != 'e')) ||
                (pcVar12[3] != '\0')))) {
LAB_00421a18:
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar12,"list-standard-commands");
              if (iVar4 == 0) {
                ppcVar6 = (char **)(*(code *)PTR_BIO_new_fp_006a7248)
                                             (*(undefined4 *)PTR_stdout_006a99c8,0);
                param_2 = (char *)0x0;
                iVar4 = (*(code *)PTR_load_config_006a6e64)(bio_err);
                if (iVar4 != 0) {
                  iVar4 = 1;
LAB_00421b8c:
                  if (functions._4_4_ != 0) {
                    piVar11 = (int *)functions;
                    do {
                      if (*piVar11 == iVar4) {
                        param_2 = (char *)(char **)0x6371a0;
                        (*(code *)PTR_BIO_printf_006a6e38)(ppcVar6);
                      }
                      piVar1 = piVar11 + 4;
                      piVar11 = piVar11 + 3;
                    } while (*piVar1 != 0);
                  }
LAB_00421bf8:
                  uVar5 = 0;
                  (*(code *)PTR_BIO_free_all_006a6e74)(ppcVar6);
                  goto LAB_00421908;
                }
              }
              else {
                iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar12,"list-message-digest-commands");
                if (iVar4 == 0) {
                  ppcVar6 = (char **)(*(code *)PTR_BIO_new_fp_006a7248)
                                               (*(undefined4 *)PTR_stdout_006a99c8,0);
                  param_2 = (char *)0x0;
                  iVar4 = (*(code *)PTR_load_config_006a6e64)(bio_err);
                  if (iVar4 != 0) {
                    iVar4 = 2;
                    goto LAB_00421b8c;
                  }
                }
                else {
                  iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar12,"list-message-digest-algorithms");
                  if (iVar4 == 0) {
                    ppcVar6 = (char **)(*(code *)PTR_BIO_new_fp_006a7248)
                                                 (*(undefined4 *)PTR_stdout_006a99c8,0);
                    param_2 = (char *)0x0;
                    iVar4 = (*(code *)PTR_load_config_006a6e64)(bio_err);
                    if (iVar4 != 0) {
                      iVar4 = 5;
                      param_2 = (char *)ppcVar6;
                      (*(code *)PTR_EVP_MD_do_all_sorted_006a73c0)(list_md_fn);
                      goto LAB_00421b8c;
                    }
                  }
                  else {
                    iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar12,"list-cipher-commands");
                    if (((iVar4 != 0) &&
                        (iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar12,"list-cipher-algorithms"),
                        iVar4 != 0)) &&
                       (iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar12,"list-public-key-algorithms")
                       , iVar4 != 0)) {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (bio_err,"openssl:Error: \'%s\' is an invalid command.\n",pcVar12);
                      (*(code *)PTR_BIO_printf_006a6e38)(bio_err,"\nStandard commands");
                      if (functions._4_4_ != 0) {
                        iVar7 = 0;
                        uVar5 = 0;
                        iVar4 = functions._4_4_;
                        piVar11 = (int *)functions;
                        do {
                          uVar9 = uVar5 & 3;
                          uVar5 = uVar5 + 1;
                          if (uVar9 == 0) {
                            (*(code *)PTR_BIO_printf_006a6e38)(bio_err,"\n");
                            iVar10 = *piVar11;
                            if (iVar10 == iVar7) {
LAB_00422010:
                              iVar4 = piVar11[1];
                            }
                            else {
LAB_00421ffc:
                              iVar7 = iVar10;
                              if (iVar10 == 2) {
                                uVar5 = 1;
                                (*(code *)PTR_BIO_printf_006a6e38)
                                          (bio_err,
                                           "\nMessage Digest commands (see the `dgst\' command for more details)\n"
                                          );
                                iVar4 = piVar11[1];
                              }
                              else {
                                if (iVar10 != 3) goto LAB_00422010;
                                uVar5 = 1;
                                (*(code *)PTR_BIO_printf_006a6e38)
                                          (bio_err,
                                           "\nCipher commands (see the `enc\' command for more details)\n"
                                          );
                                iVar4 = piVar11[1];
                              }
                            }
                          }
                          else {
                            iVar10 = *piVar11;
                            if (iVar10 != iVar7) {
                              (*(code *)PTR_BIO_printf_006a6e38)(bio_err,"\n");
                              goto LAB_00421ffc;
                            }
                          }
                          (*(code *)PTR_BIO_printf_006a6e38)(bio_err,"%-18s",iVar4);
                          iVar4 = piVar11[4];
                          piVar11 = piVar11 + 3;
                        } while (iVar4 != 0);
                      }
                      uVar5 = 0;
                      param_2 = &DAT_00638660;
                      (*(code *)PTR_BIO_printf_006a6e38)(bio_err);
                      goto LAB_00421908;
                    }
                    iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar12,"list-public-key-algorithms");
                    if (iVar4 == 0) {
                      ppcVar6 = (char **)(*(code *)PTR_BIO_new_fp_006a7248)
                                                   (*(undefined4 *)PTR_stdout_006a99c8,0);
                      param_2 = (char *)0x0;
                      iVar4 = (*(code *)PTR_load_config_006a6e64)(bio_err);
                      if (iVar4 != 0) {
                        iVar4 = 0;
                        while (iVar7 = (*(code *)PTR_EVP_PKEY_asn1_get_count_006a73c4)(),
                              iVar4 < iVar7) {
                          uVar8 = (*(code *)PTR_EVP_PKEY_asn1_get0_006a73c8)(iVar4);
                          (*(code *)PTR_EVP_PKEY_asn1_get0_info_006a6fc0)
                                    (&local_4c,&local_48,&local_44,&local_40,&local_3c,uVar8);
                          if ((local_44 & 1) == 0) {
                            (*(code *)PTR_BIO_printf_006a6e38)(ppcVar6,"Name: %s\n",local_40);
                            if ((local_44 & 2) == 0) {
                              pcVar12 = "Builtin";
                            }
                            else {
                              pcVar12 = "External";
                            }
                            (*(code *)PTR_BIO_printf_006a6e38)
                                      (ppcVar6,"\tType: %s Algorithm\n",pcVar12);
                            uVar8 = (*(code *)PTR_OBJ_nid2ln_006a711c)(local_4c);
                            (*(code *)PTR_BIO_printf_006a6e38)(ppcVar6,"\tOID: %s\n",uVar8);
                            if (local_3c == (char *)0x0) {
                              local_3c = "(none)";
                            }
                            param_2 = "\tPEM string: %s\n";
                            iVar4 = iVar4 + 1;
                            (*(code *)PTR_BIO_printf_006a6e38)
                                      (ppcVar6,"\tPEM string: %s\n",local_3c);
                          }
                          else {
                            iVar4 = iVar4 + 1;
                            uVar8 = (*(code *)PTR_OBJ_nid2ln_006a711c)(local_4c);
                            (*(code *)PTR_BIO_printf_006a6e38)(ppcVar6,"Name: %s\n",uVar8);
                            uVar8 = (*(code *)PTR_OBJ_nid2ln_006a711c)(local_48);
                            param_2 = "\tType: Alias to %s\n";
                            (*(code *)PTR_BIO_printf_006a6e38)
                                      (ppcVar6,"\tType: Alias to %s\n",uVar8);
                          }
                        }
                        iVar4 = 4;
                        goto LAB_00421b8c;
                      }
                    }
                    else {
                      iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar12,"list-cipher-algorithms");
                      if (iVar4 == 0) {
                        ppcVar6 = (char **)(*(code *)PTR_BIO_new_fp_006a7248)
                                                     (*(undefined4 *)PTR_stdout_006a99c8,0);
                        param_2 = (char *)0x0;
                        iVar4 = (*(code *)PTR_load_config_006a6e64)(bio_err);
                        if (iVar4 != 0) {
                          param_2 = (char *)ppcVar6;
                          (*(code *)PTR_EVP_CIPHER_do_all_sorted_006a73bc)(list_cipher_fn);
                          goto LAB_00421bf8;
                        }
                      }
                      else {
                        ppcVar6 = (char **)(*(code *)PTR_BIO_new_fp_006a7248)
                                                     (*(undefined4 *)PTR_stdout_006a99c8,0);
                        param_2 = (char *)0x0;
                        iVar4 = (*(code *)PTR_load_config_006a6e64)(bio_err);
                        if (iVar4 != 0) {
                          iVar4 = 3;
                          goto LAB_00421b8c;
                        }
                      }
                    }
                  }
                }
              }
              uVar5 = 1;
              goto LAB_00421908;
            }
          }
        }
        uVar5 = 0xffffffff;
        goto LAB_00421908;
      }
      local_30 = PTR_enc_main_006a73b8;
      local_38 = 3;
      pcVar13 = (code *)PTR_enc_main_006a73b8;
    }
    else {
      local_30 = PTR_dgst_main_006a73b4;
      local_38 = 2;
      pcVar13 = (code *)PTR_dgst_main_006a73b4;
    }
  }
  else {
    pcVar13 = *(code **)(iVar4 + 8);
  }
  uVar5 = (*pcVar13)(param_2);
  param_2 = (char *)param_3;
LAB_00421908:
  if (local_2c == *(char ***)puVar3) {
    return uVar5;
  }
  ppcVar6 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (*ppcVar6 == *(char **)param_2) {
    uVar5 = (*(code *)PTR_strcmp_006a9b18)(ppcVar6[1],*(char **)((int)param_2 + 4));
    return uVar5;
  }
  return (int)*ppcVar6 - (int)*(char **)param_2;
}

