
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

char * crl_main(undefined1 *param_1,int *param_2)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  int **ppiVar4;
  int iVar5;
  undefined4 uVar6;
  int **ppiVar7;
  int **ppiVar8;
  int iVar9;
  int **ppiVar10;
  char *pcVar11;
  int unaff_s3;
  int **unaff_s6;
  int **ppiVar12;
  int **unaff_s7;
  int **ppiVar13;
  int **ppiVar14;
  int **unaff_s8;
  int *local_158;
  int *local_154;
  int *local_14c;
  char *local_148;
  int *local_144;
  int local_140;
  int **local_13c;
  char *local_138;
  int **local_134;
  char *local_130;
  char *local_12c;
  int local_128;
  int **local_124;
  int **local_120;
  int **local_11c;
  int **local_118;
  int **local_114;
  int **local_110;
  int **local_10c;
  undefined4 local_104;
  int **local_100;
  undefined auStack_fc [4];
  undefined4 local_f8;
  undefined auStack_f4 [136];
  int *apiStack_6c [16];
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  puVar2 = PTR_bio_err_006a7f3c;
  local_104 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_140 = (*(code *)PTR_EVP_sha1_006a86c4)();
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar9 = *(int *)puVar2;
  if (iVar9 == 0) {
    uVar6 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar9 = (*(code *)PTR_BIO_new_006a7fa4)(uVar6);
    *(int *)puVar2 = iVar9;
    if (iVar9 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar9,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
      iVar9 = *(int *)puVar2;
    }
  }
  iVar9 = (*(code *)PTR_load_config_006a7f64)(iVar9,0);
  if (iVar9 == 0) goto LAB_00435dbc;
  if (bio_out == (int **)0x0) {
    uVar6 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    bio_out = (int **)(*(code *)PTR_BIO_new_006a7fa4)(uVar6);
    if (bio_out != (int **)0x0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(bio_out,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
    }
  }
  ppiVar13 = (int **)((int)param_1 + -1);
  local_144 = (int *)0x0;
  ppiVar14 = (int **)(param_2 + 1);
  local_10c = (int **)0x0;
  local_110 = (int **)0x0;
  ppiVar12 = (int **)0x3;
  local_128 = 0;
  unaff_s3 = 3;
  local_124 = (int **)0x0;
  local_114 = (int **)0x0;
  local_118 = (int **)0x0;
  local_11c = (int **)0x0;
  local_120 = (int **)0x0;
  local_14c = (int *)0x0;
  local_158 = (int *)0x0;
  local_134 = (int **)0x0;
  local_13c = (int **)0x0;
  local_130 = (char *)0x0;
  unaff_s7 = ppiVar13;
  unaff_s8 = ppiVar14;
  if ((int)ppiVar13 < 1) goto LAB_00435b38;
  param_2 = (int *)0x630000;
  pcVar11 = "-outform";
  local_154 = (int *)&DAT_00632edc;
  local_148 = (char *)0x630000;
  local_138 = "-CAfile";
  local_12c = (char *)0x630000;
  do {
    param_1 = (undefined1 *)*ppiVar14;
    iVar5 = (*(code *)PTR_strcmp_006aac20)(param_1,param_2 + 0xaa1);
    unaff_s6 = ppiVar12;
    unaff_s7 = ppiVar14;
    iVar9 = local_140;
    if (iVar5 == 0) {
      ppiVar13 = (int **)((int)ppiVar13 + -1);
      unaff_s8 = ppiVar13;
      if (ppiVar13 == (int **)0x0) goto LAB_00435f10;
      ppiVar10 = ppiVar14 + 1;
      unaff_s3 = (*(code *)PTR_str2fmt_006a7f4c)(ppiVar14[1]);
      goto LAB_00435acc;
    }
    iVar5 = (*(code *)PTR_strcmp_006aac20)(param_1,pcVar11);
    if (iVar5 != 0) {
      if ((((*param_1 == '-') && (*(char *)((int)param_1 + 1) == 'i')) &&
          (*(char *)((int)param_1 + 2) == 'n')) && (*(char *)((int)param_1 + 3) == '\0')) {
        ppiVar13 = (int **)((int)ppiVar13 + -1);
        unaff_s8 = ppiVar13;
        if (ppiVar13 == (int **)0x0) goto LAB_00435f10;
        local_158 = ppiVar14[1];
        ppiVar10 = ppiVar14 + 1;
        goto LAB_00435acc;
      }
      iVar5 = (*(code *)PTR_strcmp_006aac20)(param_1,local_154);
      if (iVar5 == 0) {
        ppiVar13 = (int **)((int)ppiVar13 + -1);
        unaff_s8 = ppiVar13;
        if (ppiVar13 == (int **)0x0) goto LAB_00435f10;
        local_14c = ppiVar14[1];
        ppiVar10 = ppiVar14 + 1;
        goto LAB_00435acc;
      }
      iVar5 = (*(code *)PTR_strcmp_006aac20)(param_1,local_148 + 0x2850);
      if (iVar5 == 0) {
        ppiVar13 = (int **)((int)ppiVar13 + -1);
        unaff_s8 = ppiVar13;
        if (ppiVar13 == (int **)0x0) goto LAB_00435f10;
        local_13c = (int **)ppiVar14[1];
        local_144 = (int *)0x1;
        ppiVar10 = ppiVar14 + 1;
        goto LAB_00435acc;
      }
      iVar5 = (*(code *)PTR_strcmp_006aac20)(param_1,local_138);
      if (iVar5 == 0) {
        ppiVar13 = (int **)((int)ppiVar13 + -1);
        ppiVar10 = ppiVar14 + 1;
        unaff_s8 = ppiVar13;
        if (ppiVar13 == (int **)0x0) goto LAB_00435f10;
        local_130 = (char *)ppiVar14[1];
        local_144 = (int *)0x1;
        goto LAB_00435acc;
      }
      iVar5 = (*(code *)PTR_strcmp_006aac20)(param_1,local_12c + 0x313c);
      ppiVar10 = ppiVar14;
      if (iVar5 == 0) {
        local_144 = (int *)0x1;
        goto LAB_00435acc;
      }
      iVar5 = (*(code *)PTR_strcmp_006aac20)(param_1,"-text");
      if (iVar5 == 0) {
        local_128 = 1;
        goto LAB_00435acc;
      }
      iVar5 = (*(code *)PTR_strcmp_006aac20)(param_1,"-hash");
      if (iVar5 != 0) {
        iVar5 = (*(code *)PTR_strcmp_006aac20)(param_1,"-nameopt");
        if (iVar5 == 0) {
          ppiVar13 = (int **)((int)ppiVar13 + -1);
          unaff_s8 = ppiVar13;
          if (ppiVar13 == (int **)0x0) goto LAB_00435f10;
          iVar5 = (*(code *)PTR_set_name_ex_006a80ac)(&local_104,ppiVar14[1]);
          ppiVar10 = ppiVar14 + 1;
          if (iVar5 != 0) goto LAB_00435acc;
          goto LAB_00435f10;
        }
        iVar5 = (*(code *)PTR_strcmp_006aac20)(param_1,"-issuer");
        if (iVar5 == 0) {
          local_134 = (int **)((int)local_134 + 1);
          local_11c = local_134;
          goto LAB_00435acc;
        }
        iVar5 = (*(code *)PTR_strcmp_006aac20)(param_1,"-lastupdate");
        if (iVar5 == 0) {
          local_134 = (int **)((int)local_134 + 1);
          local_118 = local_134;
          goto LAB_00435acc;
        }
        iVar5 = (*(code *)PTR_strcmp_006aac20)(param_1,"-nextupdate");
        if (iVar5 == 0) {
          local_134 = (int **)((int)local_134 + 1);
          local_114 = local_134;
          goto LAB_00435acc;
        }
        iVar5 = (*(code *)PTR_strcmp_006aac20)(param_1,"-noout");
        if (iVar5 == 0) {
          local_134 = (int **)((int)local_134 + 1);
          local_124 = local_134;
          goto LAB_00435acc;
        }
        iVar5 = (*(code *)PTR_strcmp_006aac20)(param_1,"-fingerprint");
        if (iVar5 != 0) goto LAB_00436560;
        local_134 = (int **)((int)local_134 + 1);
        local_110 = local_134;
        goto LAB_00435acc;
      }
      local_134 = (int **)((int)local_134 + 1);
      local_120 = local_134;
      goto LAB_00435acc;
    }
    unaff_s8 = (int **)((int)ppiVar13 + -1);
    if ((int **)((int)ppiVar13 + -1) == (int **)0x0) goto LAB_00435f10;
    ppiVar12 = ppiVar14 + 1;
    ppiVar14 = ppiVar14 + 2;
    ppiVar12 = (int **)(*(code *)PTR_str2fmt_006a7f4c)(*ppiVar12);
    for (ppiVar13 = (int **)((int)ppiVar13 + -2); unaff_s7 = ppiVar14, unaff_s8 = ppiVar13,
        ppiVar13 == (int **)0x0; ppiVar13 = (int **)((int)ppiVar13 + -1)) {
LAB_00435b38:
      ppiVar4 = local_114;
      ppiVar10 = local_118;
      unaff_s6 = local_11c;
      ppiVar14 = local_120;
      ppiVar13 = local_134;
      (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
      uVar6 = (*(code *)PTR_BIO_s_file_006a7fa0)();
      param_1 = (undefined1 *)(*(code *)PTR_BIO_new_006a7fa4)(uVar6);
      if ((int *)param_1 == (int *)0x0) {
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
LAB_00435da8:
        (*(code *)PTR_BIO_free_006a7f70)(param_1);
        unaff_s6 = ppiVar12;
        goto LAB_00435dbc;
      }
      if (local_158 == (int *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a7f18)(param_1,0x6a,0,*(undefined4 *)PTR_stdin_006aab20);
      }
      else {
        iVar9 = (*(code *)PTR_BIO_ctrl_006a7f18)(param_1,0x6c,3,local_158);
        if (iVar9 < 1) {
          (*(code *)PTR_perror_006aab88)(local_158);
          goto LAB_00435da8;
        }
      }
      if (unaff_s3 == 1) {
        param_2 = (int *)(*(code *)PTR_d2i_X509_CRL_bio_006a86c0)(param_1,0);
      }
      else {
        if (unaff_s3 != 3) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar2,"bad input format specified for input crl\n");
          goto LAB_00435da8;
        }
        param_2 = (int *)(*(code *)PTR_PEM_read_bio_X509_CRL_006a86bc)(param_1,0,0,0);
      }
      if (param_2 == (int *)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"unable to load CRL\n");
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
        goto LAB_00435da8;
      }
      (*(code *)PTR_BIO_free_006a7f70)(param_1);
      if (local_144 == (int *)0x0) {
        param_1 = (undefined1 *)0x0;
LAB_00435be8:
        if (local_134 != (int **)0x0) {
          unaff_s8 = (int **)0x1;
          local_138 = "issuer=";
          local_130 = "crlNumber=";
          local_148 = "s\n";
          local_12c = "%02X%c";
          do {
            if (unaff_s6 == unaff_s8) {
              (*(code *)PTR_print_name_006a8004)
                        (bio_out,"issuer=",*(undefined4 *)(*param_2 + 8),local_104);
              local_134 = local_10c;
            }
            ppiVar8 = bio_out;
            if (unaff_s8 == local_10c) {
              iVar9 = (*(code *)PTR_X509_CRL_get_ext_d2i_006a86c8)(param_2,0x58,0,0);
              (*(code *)PTR_BIO_printf_006a7f38)(bio_out,"crlNumber=");
              if (iVar9 == 0) {
                (*(code *)PTR_BIO_puts_006a8058)(bio_out,"<NONE>");
              }
              else {
                (*(code *)PTR_i2a_ASN1_INTEGER_006a86e4)(bio_out,iVar9);
                (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar9);
              }
              (*(code *)PTR_BIO_printf_006a7f38)(bio_out,"\n");
              ppiVar8 = bio_out;
              local_134 = local_10c;
              local_120 = local_10c;
            }
            bio_out = ppiVar8;
            if (ppiVar14 == unaff_s8) {
              uVar6 = (*(code *)PTR_X509_NAME_hash_006a86e0)(*(undefined4 *)(*param_2 + 8));
              (*(code *)PTR_BIO_printf_006a7f38)(ppiVar8,"%08lx\n",uVar6);
              local_134 = ppiVar8;
              local_120 = local_10c;
            }
            if (ppiVar10 == unaff_s8) {
              (*(code *)PTR_BIO_printf_006a7f38)(bio_out,"lastUpdate=");
              (*(code *)PTR_ASN1_TIME_print_006a826c)(bio_out,*(undefined4 *)(*param_2 + 0xc));
              (*(code *)PTR_BIO_printf_006a7f38)(bio_out,"\n");
              local_134 = local_10c;
            }
            if (unaff_s8 == ppiVar4) {
              (*(code *)PTR_BIO_printf_006a7f38)(bio_out,"nextUpdate=");
              if (*(int *)(*param_2 + 0x10) == 0) {
                (*(code *)PTR_BIO_printf_006a7f38)(bio_out,&DAT_00637b4c);
              }
              else {
                (*(code *)PTR_ASN1_TIME_print_006a826c)(bio_out);
              }
              (*(code *)PTR_BIO_printf_006a7f38)(bio_out,"\n");
              local_134 = local_10c;
            }
            ppiVar8 = apiStack_6c;
            unaff_s7 = ppiVar10;
            local_158 = (int *)&_ITM_registerTMCloneTable;
            local_154 = param_2;
            local_144 = (int *)param_1;
            local_13c = ppiVar12;
            if (unaff_s8 == local_110) {
              iVar9 = (*(code *)PTR_X509_CRL_digest_006a86dc)(param_2,local_140,ppiVar8,&local_100);
              ppiVar7 = bio_out;
              local_134 = ppiVar8;
              if (iVar9 == 0) {
                unaff_s3 = 0;
                pcVar11 = (char *)0x1;
                (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"out of memory\n");
                local_120 = local_10c;
                goto LAB_00435d34;
              }
              local_120 = bio_out;
              uVar6 = (*(code *)PTR_EVP_MD_type_006a84cc)(local_140);
              uVar6 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar6);
              (*(code *)PTR_BIO_printf_006a7f38)(ppiVar7,"%s Fingerprint=",uVar6);
              local_11c = local_10c;
              if (0 < (int)local_100) {
                local_118 = (int **)0x0;
                local_120 = (int **)&DAT_0000003a;
                local_11c = (int **)&DAT_0000000a;
                do {
                  local_118 = (int **)((int)local_118 + 1);
                  cVar1 = *(char *)ppiVar8;
                  ppiVar8 = (int **)((int)ppiVar8 + 1);
                  ppiVar7 = local_11c;
                  if (local_118 != local_100) {
                    ppiVar7 = local_120;
                  }
                  (*(code *)PTR_BIO_printf_006a7f38)(bio_out,"%02X%c",cVar1,ppiVar7);
                  local_134 = ppiVar8;
                  local_114 = local_10c;
                } while ((int)local_118 < (int)local_100);
              }
            }
            unaff_s8 = (int **)((int)unaff_s8 + 1);
          } while ((int)unaff_s8 <= (int)ppiVar13);
        }
        uVar6 = (*(code *)PTR_BIO_s_file_006a7fa0)();
        unaff_s3 = (*(code *)PTR_BIO_new_006a7fa4)(uVar6);
        if (unaff_s3 == 0) {
          pcVar11 = (char *)0x1;
          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
          unaff_s6 = ppiVar12;
        }
        else {
          if (local_14c == (int *)0x0) {
            (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s3,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
          }
          else {
            iVar9 = (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s3,0x6c,5,local_14c);
            if (iVar9 < 1) {
              pcVar11 = (char *)0x1;
              (*(code *)PTR_perror_006aab88)(local_14c);
              unaff_s6 = ppiVar12;
              goto LAB_00435d34;
            }
          }
          if (local_128 != 0) {
            (*(code *)PTR_X509_CRL_print_006a86a0)(unaff_s3,param_2);
          }
          if (local_124 == (int **)0x0) {
            if (ppiVar12 == (int **)0x1) {
              iVar9 = (*(code *)PTR_i2d_X509_CRL_bio_006a86cc)(unaff_s3,param_2);
            }
            else {
              if (ppiVar12 != (int **)0x3) {
                pcVar11 = (char *)0x1;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2,"bad output format specified for outfile\n");
                unaff_s6 = ppiVar12;
                goto LAB_00435d34;
              }
              iVar9 = (*(code *)PTR_PEM_write_bio_X509_CRL_006a8214)(unaff_s3,param_2);
            }
            if (iVar9 == 0) {
              pcVar11 = (char *)0x1;
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"unable to write CRL\n");
              unaff_s6 = ppiVar12;
              goto LAB_00435d34;
            }
          }
          pcVar11 = (char *)0x0;
          unaff_s6 = ppiVar12;
        }
      }
      else {
        param_1 = (undefined1 *)(*(code *)PTR_X509_STORE_new_006a8364)();
        uVar6 = (*(code *)PTR_X509_LOOKUP_file_006a8580)();
        iVar9 = (*(code *)PTR_X509_STORE_add_lookup_006a8584)(param_1,uVar6);
        if (iVar9 != 0) {
          iVar5 = (*(code *)PTR_X509_LOOKUP_ctrl_006a8588)(iVar9,1,local_130,1,0);
          if (iVar5 == 0) {
            (*(code *)PTR_X509_LOOKUP_ctrl_006a8588)(iVar9,1,0,3,0);
          }
          uVar6 = (*(code *)PTR_X509_LOOKUP_hash_dir_006a858c)();
          iVar9 = (*(code *)PTR_X509_STORE_add_lookup_006a8584)(param_1,uVar6);
          if (iVar9 != 0) {
            iVar5 = (*(code *)PTR_X509_LOOKUP_ctrl_006a8588)(iVar9,2,local_13c,1,0);
            if (iVar5 == 0) {
              (*(code *)PTR_X509_LOOKUP_ctrl_006a8588)(iVar9,2,0,3,0);
            }
            (*(code *)PTR_ERR_clear_error_006a7fe0)();
            iVar9 = (*(code *)PTR_X509_STORE_CTX_init_006a8304)(auStack_f4,param_1,0,0);
            if (iVar9 == 0) {
              unaff_s3 = 0;
              pcVar11 = (char *)0x1;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar2,"Error initialising X509 store\n");
              unaff_s6 = ppiVar12;
            }
            else {
              iVar9 = (*(code *)PTR_X509_STORE_get_by_subject_006a86d0)
                                (auStack_f4,1,*(undefined4 *)(*param_2 + 8),auStack_fc);
              if (iVar9 < 1) {
                unaff_s3 = 0;
                pcVar11 = (char *)0x1;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2,"Error getting CRL issuer certificate\n");
                unaff_s6 = ppiVar12;
              }
              else {
                iVar9 = (*(code *)PTR_X509_get_pubkey_006a8008)(local_f8);
                (*(code *)PTR_X509_OBJECT_free_contents_006a86d4)(auStack_fc);
                if (iVar9 != 0) {
                  iVar5 = (*(code *)PTR_X509_CRL_verify_006a86d8)(param_2,iVar9);
                  (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar9);
                  if (-1 < iVar5) {
                    if (iVar5 == 0) {
                      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"verify failure\n");
                    }
                    else {
                      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"verify OK\n");
                    }
                    goto LAB_00435be8;
                  }
                  goto LAB_00436280;
                }
                unaff_s3 = 0;
                pcVar11 = (char *)0x1;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2,"Error getting CRL issuer public key\n");
                unaff_s6 = ppiVar12;
              }
            }
            goto LAB_00435d34;
          }
        }
LAB_00436280:
        unaff_s3 = 0;
        pcVar11 = (char *)0x1;
        unaff_s6 = ppiVar12;
      }
LAB_00435d34:
      (*(code *)PTR_BIO_free_all_006a7f74)(unaff_s3);
      (*(code *)PTR_BIO_free_all_006a7f74)(bio_out);
      bio_out = (int **)0x0;
      (*(code *)PTR_X509_CRL_free_006a8160)(param_2);
      if ((int *)param_1 != (int *)0x0) {
        (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(auStack_f4);
        (*(code *)PTR_X509_STORE_free_006a8384)(param_1);
      }
      while( true ) {
        if (local_2c == *(int *)puVar3) {
          return pcVar11;
        }
        (*(code *)PTR___stack_chk_fail_006aabb8)();
        ppiVar12 = unaff_s6;
        ppiVar10 = unaff_s7;
        ppiVar13 = unaff_s8;
LAB_00436560:
        iVar9 = (*(code *)PTR_strcmp_006aac20)(param_1,"-crlnumber");
        if (iVar9 == 0) break;
        iVar9 = (*(code *)PTR_EVP_get_digestbyname_006a802c)((char *)((int)param_1 + 1));
        if (iVar9 != 0) goto LAB_00435acc;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"unknown option %s\n",*ppiVar10);
        unaff_s6 = ppiVar12;
        unaff_s7 = ppiVar10;
        unaff_s8 = ppiVar13;
LAB_00435f10:
        param_1 = SSL_str_reasons + 0xc0;
        param_2 = (int *)0x670000;
        if (crl_usage._0_4_ != 0) {
          param_1 = crl_usage;
          param_2 = (int *)0x6716bc;
          do {
            param_1 = (undefined1 *)((int)param_1 + 4);
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"%s");
          } while (*(int *)param_1 != 0);
        }
LAB_00435dbc:
        pcVar11 = (char *)0x1;
        (*(code *)PTR_BIO_free_all_006a7f74)(0);
        (*(code *)PTR_BIO_free_all_006a7f74)(bio_out);
        bio_out = (int **)0x0;
        (*(code *)PTR_X509_CRL_free_006a8160)(0);
      }
      local_134 = (int **)((int)local_134 + 1);
      iVar9 = local_140;
      local_10c = local_134;
LAB_00435acc:
      local_140 = iVar9;
      ppiVar14 = ppiVar10 + 1;
    }
  } while( true );
}

