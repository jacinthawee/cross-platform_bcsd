
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 crl_main(undefined1 *param_1,int param_2)

{
  char **ppcVar1;
  undefined uVar2;
  bool bVar3;
  bool bVar4;
  undefined *puVar5;
  undefined *puVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  int iVar10;
  undefined *puVar11;
  int iVar12;
  char *pcVar13;
  int iVar14;
  char **ppcVar15;
  char *local_15c;
  char *local_150;
  int local_144;
  char *local_140;
  int local_138;
  char *local_134;
  int local_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  undefined4 local_104;
  int local_100;
  undefined auStack_fc [4];
  undefined4 local_f8;
  undefined auStack_f4 [136];
  undefined auStack_6c [64];
  int local_2c;
  
  puVar6 = PTR___stack_chk_guard_006a9ae8;
  puVar5 = PTR_bio_err_006a6e3c;
  local_104 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_144 = (*(code *)PTR_EVP_sha1_006a75d0)();
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iVar12 = *(int *)puVar5;
  if (iVar12 == 0) {
    uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar12 = (*(code *)PTR_BIO_new_006a6ea4)(uVar8);
    *(int *)puVar5 = iVar12;
    if (iVar12 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar12,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
      iVar12 = *(int *)puVar5;
    }
  }
  iVar12 = (*(code *)PTR_load_config_006a6e64)(iVar12,0);
  if (iVar12 == 0) goto LAB_00435fdc;
  if (bio_out == 0) {
    uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    bio_out = (*(code *)PTR_BIO_new_006a6ea4)(uVar8);
    if (bio_out != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(bio_out,0x6a,0,*(undefined4 *)PTR_stdout_006a99c8);
    }
  }
  param_1 = (undefined1 *)((int)param_1 + -1);
  bVar3 = false;
  ppcVar15 = (char **)(param_2 + 4);
  if ((int)param_1 < 1) {
    local_110 = 0;
    iVar14 = 3;
    local_114 = 0;
    iVar12 = 3;
    bVar4 = false;
    local_128 = 0;
    local_118 = 0;
    local_11c = 0;
    local_120 = 0;
    local_124 = 0;
    local_150 = (char *)0x0;
    local_15c = (char *)0x0;
    local_138 = 0;
    local_140 = (char *)0x0;
    local_134 = (char *)0x0;
    local_10c = 0;
  }
  else {
    local_10c = 0;
    local_110 = 0;
    local_114 = 0;
    bVar4 = false;
    iVar14 = 3;
    local_128 = 0;
    iVar12 = 3;
    local_118 = 0;
    local_11c = 0;
    local_120 = 0;
    local_124 = 0;
    local_150 = (char *)0x0;
    local_15c = (char *)0x0;
    local_138 = 0;
    local_140 = (char *)0x0;
    local_134 = (char *)0x0;
    do {
      while( true ) {
        pcVar13 = *ppcVar15;
        iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-inform");
        if (iVar7 != 0) break;
        param_1 = param_1 + -1;
        if (param_1 == (undefined1 *)0x0) goto LAB_00436130;
        iVar12 = (*(code *)PTR_str2fmt_006a6e4c)(ppcVar15[1]);
        ppcVar15 = ppcVar15 + 1;
LAB_00435ce0:
        param_1 = param_1 + -1;
        ppcVar15 = ppcVar15 + 1;
        if (param_1 == (undefined1 *)0x0) goto LAB_00435d4c;
      }
      iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-outform");
      if (iVar7 != 0) {
        if ((((*pcVar13 == '-') && (pcVar13[1] == 'i')) && (pcVar13[2] == 'n')) &&
           (pcVar13[3] == '\0')) {
          param_1 = param_1 + -1;
          if (param_1 == (undefined1 *)0x0) goto LAB_00436130;
          local_15c = ppcVar15[1];
          ppcVar15 = ppcVar15 + 1;
        }
        else {
          iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,&DAT_00632514);
          if (iVar7 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == (undefined1 *)0x0) goto LAB_00436130;
            local_150 = ppcVar15[1];
            ppcVar15 = ppcVar15 + 1;
          }
          else {
            iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-CApath");
            if (iVar7 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == (undefined1 *)0x0) goto LAB_00436130;
              local_140 = ppcVar15[1];
              bVar3 = true;
              ppcVar15 = ppcVar15 + 1;
            }
            else {
              iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-CAfile");
              if (iVar7 == 0) {
                param_1 = param_1 + -1;
                if (param_1 == (undefined1 *)0x0) goto LAB_00436130;
                local_134 = ppcVar15[1];
                bVar3 = true;
                ppcVar15 = ppcVar15 + 1;
              }
              else {
                iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-verify");
                if (iVar7 == 0) {
                  bVar3 = true;
                }
                else {
                  iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-text");
                  if (iVar7 == 0) {
                    bVar4 = true;
                  }
                  else {
                    iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-hash");
                    if (iVar7 == 0) {
                      local_138 = local_138 + 1;
                      local_124 = local_138;
                    }
                    else {
                      iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-hash_old");
                      if (iVar7 == 0) {
                        local_138 = local_138 + 1;
                        local_114 = local_138;
                      }
                      else {
                        iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-nameopt");
                        if (iVar7 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 == (undefined1 *)0x0) {
LAB_00436130:
                            param_1 = methods_sockp + 0x10;
                            if (crl_usage._0_4_ == 0) goto LAB_00435fdc;
                            param_1 = crl_usage;
                            do {
                              param_1 = (undefined1 *)((int)param_1 + 4);
                              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar5,"%s");
                              if (*(int *)param_1 == 0) goto LAB_00435fdc;
                            } while( true );
                          }
                          iVar7 = (*(code *)PTR_set_name_ex_006a6fac)(&local_104,ppcVar15[1]);
                          ppcVar15 = ppcVar15 + 1;
                          if (iVar7 == 0) goto LAB_00436130;
                        }
                        else {
                          iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-issuer");
                          if (iVar7 == 0) {
                            local_138 = local_138 + 1;
                            local_120 = local_138;
                          }
                          else {
                            iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-lastupdate");
                            if (iVar7 == 0) {
                              local_138 = local_138 + 1;
                              local_11c = local_138;
                            }
                            else {
                              iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-nextupdate");
                              if (iVar7 == 0) {
                                local_138 = local_138 + 1;
                                local_118 = local_138;
                              }
                              else {
                                iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-noout");
                                if (iVar7 == 0) {
                                  local_138 = local_138 + 1;
                                  local_128 = local_138;
                                }
                                else {
                                  iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-fingerprint");
                                  if (iVar7 == 0) {
                                    local_138 = local_138 + 1;
                                    local_110 = local_138;
                                  }
                                  else {
                                    iVar7 = (*(code *)PTR_strcmp_006a9b18)(pcVar13,"-crlnumber");
                                    if (iVar7 == 0) {
                                      local_138 = local_138 + 1;
                                      local_10c = local_138;
                                    }
                                    else {
                                      local_144 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)
                                                            (pcVar13 + 1);
                                      if (local_144 == 0) {
                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                  (*(undefined4 *)puVar5,"unknown option %s\n",
                                                   *ppcVar15);
                                        goto LAB_00436130;
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
        goto LAB_00435ce0;
      }
      if (param_1 == (undefined1 *)0x1) goto LAB_00436130;
      ppcVar1 = ppcVar15 + 1;
      param_1 = param_1 + -2;
      ppcVar15 = ppcVar15 + 2;
      iVar14 = (*(code *)PTR_str2fmt_006a6e4c)(*ppcVar1);
    } while (param_1 != (undefined1 *)0x0);
  }
LAB_00435d4c:
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  param_1 = (undefined1 *)(*(code *)PTR_BIO_new_006a6ea4)(uVar8);
  if ((int *)param_1 == (int *)0x0) goto LAB_004367c4;
  if (local_15c == (char *)0x0) {
    (*(code *)PTR_BIO_ctrl_006a6e18)(param_1,0x6a,0,*(undefined4 *)PTR_stdin_006a9a14);
  }
  else {
    iVar7 = (*(code *)PTR_BIO_ctrl_006a6e18)(param_1,0x6c,3,local_15c);
    if (iVar7 < 1) {
      (*(code *)PTR_perror_006a9a80)(local_15c);
      goto LAB_00435fc8;
    }
  }
  if (iVar12 == 1) {
    piVar9 = (int *)(*(code *)PTR_d2i_X509_CRL_bio_006a75cc)(param_1,0);
  }
  else {
    if (iVar12 != 3) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar5,"bad input format specified for input crl\n");
      goto LAB_00435fc8;
    }
    piVar9 = (int *)(*(code *)PTR_PEM_read_bio_X509_CRL_006a75b8)(param_1,0,0,0);
  }
  if (piVar9 == (int *)0x0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar5,"unable to load CRL\n");
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar5);
    goto LAB_00435fc8;
  }
  (*(code *)PTR_BIO_free_006a6e70)(param_1);
  if (bVar3) {
    param_1 = (undefined1 *)(*(code *)PTR_X509_STORE_new_006a7250)();
    uVar8 = (*(code *)PTR_X509_LOOKUP_file_006a7480)();
    iVar12 = (*(code *)PTR_X509_STORE_add_lookup_006a7484)(param_1,uVar8);
    if (iVar12 != 0) {
      iVar7 = (*(code *)PTR_X509_LOOKUP_ctrl_006a7488)(iVar12,1,local_134,1,0);
      if (iVar7 == 0) {
        (*(code *)PTR_X509_LOOKUP_ctrl_006a7488)(iVar12,1,0,3,0);
      }
      uVar8 = (*(code *)PTR_X509_LOOKUP_hash_dir_006a748c)();
      iVar12 = (*(code *)PTR_X509_STORE_add_lookup_006a7484)(param_1,uVar8);
      if (iVar12 != 0) {
        iVar7 = (*(code *)PTR_X509_LOOKUP_ctrl_006a7488)(iVar12,2,local_140,1,0);
        if (iVar7 == 0) {
          (*(code *)PTR_X509_LOOKUP_ctrl_006a7488)(iVar12,2,0,3,0);
        }
        (*(code *)PTR_ERR_clear_error_006a6ee0)();
        iVar12 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)(auStack_f4,param_1,0,0);
        if (iVar12 == 0) {
          iVar12 = 0;
          uVar8 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar5,"Error initialising X509 store\n");
          goto LAB_00435f54;
        }
        iVar12 = (*(code *)PTR_X509_STORE_get_by_subject_006a75dc)
                           (auStack_f4,1,*(undefined4 *)(*piVar9 + 8),auStack_fc);
        if (iVar12 < 1) {
          iVar12 = 0;
          uVar8 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar5,"Error getting CRL issuer certificate\n");
          goto LAB_00435f54;
        }
        iVar12 = (*(code *)PTR_X509_get_pubkey_006a6f08)(local_f8);
        (*(code *)PTR_X509_OBJECT_free_contents_006a75e0)(auStack_fc);
        if (iVar12 == 0) {
          iVar12 = 0;
          uVar8 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar5,"Error getting CRL issuer public key\n");
          goto LAB_00435f54;
        }
        iVar7 = (*(code *)PTR_X509_CRL_verify_006a75e4)(piVar9,iVar12);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar12);
        if (-1 < iVar7) {
          if (iVar7 == 0) {
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar5,"verify failure\n");
          }
          else {
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar5,"verify OK\n");
          }
          goto LAB_00435dfc;
        }
      }
    }
    iVar12 = 0;
    uVar8 = 1;
  }
  else {
    param_1 = (undefined1 *)0x0;
LAB_00435dfc:
    if (local_138 != 0) {
      iVar12 = 1;
      do {
        if (local_120 == iVar12) {
          (*(code *)PTR_print_name_006a6f04)
                    (bio_out,"issuer=",*(undefined4 *)(*piVar9 + 8),local_104);
        }
        iVar7 = bio_out;
        if (local_10c == iVar12) {
          iVar7 = (*(code *)PTR_X509_CRL_get_ext_d2i_006a75d4)(piVar9,0x58,0,0);
          (*(code *)PTR_BIO_printf_006a6e38)(bio_out,"crlNumber=");
          if (iVar7 == 0) {
            (*(code *)PTR_BIO_puts_006a6f58)(bio_out,"<NONE>");
          }
          else {
            (*(code *)PTR_i2a_ASN1_INTEGER_006a75f0)(bio_out,iVar7);
            (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar7);
          }
          (*(code *)PTR_BIO_printf_006a6e38)(bio_out,"\n");
          iVar7 = bio_out;
        }
        if (local_124 == iVar12) {
          bio_out = iVar7;
          uVar8 = (*(code *)PTR_X509_NAME_hash_006a75ec)(*(undefined4 *)(*piVar9 + 8));
          (*(code *)PTR_BIO_printf_006a6e38)(iVar7,"%08lx\n",uVar8);
          iVar7 = bio_out;
        }
        bio_out = iVar7;
        if (iVar12 == local_114) {
          uVar8 = (*(code *)PTR_X509_NAME_hash_old_006a75e8)(*(undefined4 *)(*piVar9 + 8));
          (*(code *)PTR_BIO_printf_006a6e38)(iVar7,"%08lx\n",uVar8);
        }
        if (local_11c == iVar12) {
          (*(code *)PTR_BIO_printf_006a6e38)(bio_out,"lastUpdate=");
          (*(code *)PTR_ASN1_TIME_print_006a716c)(bio_out,*(undefined4 *)(*piVar9 + 0xc));
          (*(code *)PTR_BIO_printf_006a6e38)(bio_out,"\n");
        }
        if (iVar12 == local_118) {
          (*(code *)PTR_BIO_printf_006a6e38)(bio_out,"nextUpdate=");
          if (*(int *)(*piVar9 + 0x10) == 0) {
            (*(code *)PTR_BIO_printf_006a6e38)(bio_out,&DAT_006372d8);
          }
          else {
            (*(code *)PTR_ASN1_TIME_print_006a716c)(bio_out);
          }
          (*(code *)PTR_BIO_printf_006a6e38)(bio_out,"\n");
        }
        puVar11 = auStack_6c;
        if (iVar12 == local_110) {
          iVar10 = (*(code *)PTR_X509_CRL_digest_006a75f4)(piVar9,local_144,puVar11,&local_100);
          iVar7 = bio_out;
          if (iVar10 == 0) {
            iVar12 = 0;
            uVar8 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar5,"out of memory\n");
            goto LAB_00435f54;
          }
          uVar8 = (*(code *)PTR_EVP_MD_type_006a73cc)(local_144);
          uVar8 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar8);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar7,"%s Fingerprint=",uVar8);
          if (0 < local_100) {
            iVar7 = 0;
            do {
              iVar7 = iVar7 + 1;
              uVar2 = *puVar11;
              puVar11 = puVar11 + 1;
              uVar8 = 10;
              if (iVar7 != local_100) {
                uVar8 = 0x3a;
              }
              (*(code *)PTR_BIO_printf_006a6e38)(bio_out,"%02X%c",uVar2,uVar8);
            } while (iVar7 < local_100);
          }
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 <= local_138);
    }
    uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar12 = (*(code *)PTR_BIO_new_006a6ea4)(uVar8);
    if (iVar12 == 0) {
      uVar8 = 1;
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar5);
    }
    else {
      if (local_150 == (char *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a6e18)(iVar12,0x6a,0,*(undefined4 *)PTR_stdout_006a99c8);
      }
      else {
        iVar7 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar12,0x6c,5,local_150);
        if (iVar7 < 1) {
          uVar8 = 1;
          (*(code *)PTR_perror_006a9a80)(local_150);
          goto LAB_00435f54;
        }
      }
      if (bVar4) {
        (*(code *)PTR_X509_CRL_print_006a75b0)(iVar12,piVar9);
      }
      if (local_128 == 0) {
        if (iVar14 == 1) {
          iVar14 = (*(code *)PTR_i2d_X509_CRL_bio_006a75d8)(iVar12,piVar9);
        }
        else {
          if (iVar14 != 3) {
            uVar8 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar5,"bad output format specified for outfile\n");
            goto LAB_00435f54;
          }
          iVar14 = (*(code *)PTR_PEM_write_bio_X509_CRL_006a7114)(iVar12,piVar9);
        }
        if (iVar14 == 0) {
          uVar8 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar5,"unable to write CRL\n");
          goto LAB_00435f54;
        }
      }
      uVar8 = 0;
    }
  }
LAB_00435f54:
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar12);
  (*(code *)PTR_BIO_free_all_006a6e74)(bio_out);
  bio_out = 0;
  (*(code *)PTR_X509_CRL_free_006a7060)(piVar9);
  if ((int *)param_1 != (int *)0x0) {
    (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(auStack_f4);
    (*(code *)PTR_X509_STORE_free_006a7274)(param_1);
  }
  while (local_2c != *(int *)puVar6) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004367c4:
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar5);
LAB_00435fc8:
    (*(code *)PTR_BIO_free_006a6e70)(param_1);
LAB_00435fdc:
    uVar8 = 1;
    (*(code *)PTR_BIO_free_all_006a6e74)(0);
    (*(code *)PTR_BIO_free_all_006a6e74)(bio_out);
    bio_out = 0;
    (*(code *)PTR_X509_CRL_free_006a7060)(0);
  }
  return uVar8;
}

