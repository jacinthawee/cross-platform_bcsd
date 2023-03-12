
undefined4 init_gen_str(undefined4 param_1,int *param_2,int **param_3,int **param_4,int param_5)

{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 uVar6;
  int **ppiVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  int **ppiVar13;
  int **ppiVar14;
  int **ppiVar15;
  int *unaff_s1;
  int **unaff_s2;
  int iVar16;
  int **unaff_s3;
  undefined4 unaff_s4;
  int unaff_s5;
  code *pcVar17;
  int *piVar18;
  int **ppiStack_ac;
  int **ppiStack_9c;
  int **ppiStack_94;
  int ***pppiStack_88;
  int **ppiStack_84;
  int *piStack_80;
  int iStack_7c;
  undefined *puStack_78;
  int *piStack_74;
  int **ppiStack_70;
  int **ppiStack_6c;
  undefined4 uStack_68;
  int iStack_64;
  int local_2c;
  undefined4 local_28;
  int local_24;
  
  puStack_78 = PTR___stack_chk_guard_006aabf0;
  local_2c = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (*param_2 == 0) {
    ppiVar15 = param_4;
    unaff_s5 = (*(code *)PTR_EVP_PKEY_asn1_find_str_006a80bc)(&local_2c,param_3,0xffffffff);
    if ((unaff_s5 == 0) &&
       ((param_4 == (int **)0x0 ||
        (unaff_s5 = (*(code *)PTR_ENGINE_get_pkey_asn1_meth_str_006a8834)
                              (param_4,param_3,0xffffffff), unaff_s5 == 0)))) {
      pcVar11 = "Algorithm %s not found\n";
      ppiVar13 = param_3;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
      uVar6 = 0;
    }
    else {
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
      ppiVar15 = (int **)0x0;
      ppiVar13 = (int **)0x0;
      (*(code *)PTR_EVP_PKEY_asn1_get0_info_006a80c0)(&local_28,0);
      if (local_2c != 0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
      }
      ppiVar7 = (int **)(*(code *)PTR_EVP_PKEY_CTX_new_id_006a80d8)(local_28);
      if (ppiVar7 == (int **)0x0) {
        pcVar11 = "Error initializing %s context\n";
        ppiVar13 = param_3;
        (*(code *)PTR_BIO_printf_006a7f38)(param_1);
        (*(code *)PTR_ERR_print_errors_006a7f40)(param_1);
        uVar6 = 0;
        param_4 = ppiVar7;
      }
      else {
        if (param_5 == 0) {
          iVar10 = (*(code *)PTR_EVP_PKEY_keygen_init_006a80e8)(ppiVar7);
          pcVar11 = (char *)param_4;
        }
        else {
          iVar10 = (*(code *)PTR_EVP_PKEY_paramgen_init_006a8830)(ppiVar7);
          pcVar11 = (char *)param_4;
        }
        if (iVar10 < 1) {
          pcVar11 = "Error initializing %s context\n";
          ppiVar13 = param_3;
          (*(code *)PTR_BIO_printf_006a7f38)(param_1);
          (*(code *)PTR_ERR_print_errors_006a7f40)(param_1);
          (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(ppiVar7);
          uVar6 = 0;
          param_4 = ppiVar7;
        }
        else {
          *param_2 = (int)ppiVar7;
          uVar6 = 1;
          param_4 = ppiVar7;
        }
      }
    }
  }
  else {
    pcVar11 = "Algorithm already set!\n";
    (*(code *)PTR_BIO_puts_006a8058)();
    uVar6 = 0;
    ppiVar13 = param_3;
    ppiVar15 = param_4;
    param_2 = unaff_s1;
    param_3 = unaff_s2;
    param_4 = unaff_s3;
    param_1 = unaff_s4;
  }
  if (local_24 == *(int *)puStack_78) {
    return uVar6;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar5 = PTR___stack_chk_guard_006aabf0;
  puVar3 = PTR_bio_err_006a7f3c;
  pppiStack_88 = (int ***)0x0;
  ppiStack_84 = (int **)0x0;
  piStack_80 = (int *)0x0;
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar10 = *(int *)PTR_bio_err_006a7f3c;
  piStack_74 = param_2;
  ppiStack_70 = param_3;
  ppiStack_6c = param_4;
  uStack_68 = param_1;
  iStack_64 = unaff_s5;
  if (iVar10 == 0) {
    iVar10 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *(int *)puVar3 = iVar10;
  }
  pcVar12 = (char *)0x0;
  iVar10 = load_config(iVar10);
  if (iVar10 == 0) {
LAB_00441714:
    uVar6 = 1;
    iVar16 = 0;
    goto LAB_0044171c;
  }
  ppiVar7 = (int **)((int)pcVar11 + 4);
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  iVar10 = 3;
  piVar9 = (int *)0x0;
  (*(code *)PTR_OPENSSL_add_all_algorithms_noconf_006a84fc)();
  bVar1 = false;
  bVar2 = false;
  ppiStack_94 = (int **)0x0;
  ppiStack_9c = (int **)0x0;
  ppiStack_ac = (int **)0x0;
  while ((puVar4 = PTR_bio_err_006a7f3c, piVar18 = *ppiVar7, piVar18 != (int *)0x0 &&
         (*(char *)piVar18 == '-'))) {
    iVar16 = (*(code *)PTR_strcmp_006aac20)(piVar18,"-outform");
    if (iVar16 == 0) {
      if (ppiVar7[1] == (int *)0x0) goto LAB_004418cc;
      iVar10 = str2fmt();
LAB_00441870:
      ppiVar7 = ppiVar7 + 2;
    }
    else {
      iVar16 = (*(code *)PTR_strcmp_006aac20)(piVar18,"-pass");
      if (iVar16 == 0) {
        piVar9 = ppiVar7[1];
        if (piVar9 == (int *)0x0) goto LAB_004418cc;
LAB_004418a0:
        ppiVar7 = ppiVar7 + 2;
      }
      else {
        iVar16 = (*(code *)PTR_strcmp_006aac20)(piVar18,"-engine");
        if (iVar16 == 0) {
          if (ppiVar7[1] == (int *)0x0) goto LAB_004418cc;
          ppiVar13 = (int **)0x0;
          ppiVar7 = ppiVar7 + 2;
          ppiStack_ac = (int **)setup_engine(*(undefined4 *)puVar3);
        }
        else {
          iVar16 = (*(code *)PTR_strcmp_006aac20)(piVar18,"-paramfile");
          if (iVar16 == 0) {
            ppiVar14 = (int **)ppiVar7[1];
            ppiVar13 = ppiVar14;
            if ((ppiVar14 == (int **)0x0) || (bVar1)) goto LAB_004418cc;
            uVar6 = *(undefined4 *)puVar3;
            if (ppiStack_84 != (int **)0x0) {
              pcVar12 = "Parameters already set!\n";
              (*(code *)PTR_BIO_puts_006a8058)(uVar6);
              ppiVar13 = ppiVar14;
              goto LAB_00441714;
            }
            iVar16 = (*(code *)PTR_BIO_new_file_006a7fac)(ppiVar14,"r");
            if (iVar16 == 0) {
              pcVar12 = "Can\'t open parameter file %s\n";
              (*(code *)PTR_BIO_printf_006a7f38)(uVar6);
              ppiVar13 = ppiVar14;
              goto LAB_00441714;
            }
            iVar8 = (*(code *)PTR_PEM_read_bio_Parameters_006a80c8)(iVar16,0);
            (*(code *)PTR_BIO_free_006a7f70)(iVar16);
            if (iVar8 == 0) {
              pcVar12 = "Error reading parameter file %s\n";
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3);
              ppiVar13 = ppiVar14;
              goto LAB_00441714;
            }
            ppiVar13 = (int **)(*(code *)PTR_EVP_PKEY_CTX_new_006a80e0)(iVar8,ppiStack_ac);
            if (ppiVar13 == (int **)0x0) {
              pcVar12 = "Error initializing context\n";
              (*(code *)PTR_BIO_puts_006a8058)(uVar6);
              (*(code *)PTR_ERR_print_errors_006a7f40)(uVar6);
LAB_00441c18:
              (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar8);
              ppiVar13 = ppiVar14;
              goto LAB_00441714;
            }
            iVar16 = (*(code *)PTR_EVP_PKEY_keygen_init_006a80e8)(ppiVar13);
            if (iVar16 < 1) {
              pcVar12 = "Error initializing context\n";
              (*(code *)PTR_BIO_puts_006a8058)(uVar6);
              (*(code *)PTR_ERR_print_errors_006a7f40)(uVar6);
              (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(ppiVar13);
              ppiVar14 = ppiVar13;
              goto LAB_00441c18;
            }
            (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar8);
            ppiVar7 = ppiVar7 + 2;
            ppiStack_84 = ppiVar13;
          }
          else {
            iVar16 = (*(code *)PTR_strcmp_006aac20)(piVar18,&DAT_00632edc);
            if (iVar16 == 0) {
              ppiStack_9c = (int **)ppiVar7[1];
              if (ppiStack_9c != (int **)0x0) goto LAB_004418a0;
              goto LAB_004418cc;
            }
            iVar16 = (*(code *)PTR_strcmp_006aac20)(piVar18,"-algorithm");
            if (iVar16 == 0) {
              ppiVar13 = (int **)ppiVar7[1];
              if (ppiVar13 == (int **)0x0) goto LAB_004418cc;
              pcVar12 = (char *)&ppiStack_84;
              ppiVar15 = ppiStack_ac;
              iVar16 = init_gen_str(*(undefined4 *)puVar3);
              if (iVar16 == 0) goto LAB_00441714;
              ppiVar7 = ppiVar7 + 2;
            }
            else {
              iVar16 = (*(code *)PTR_strcmp_006aac20)(piVar18,"-pkeyopt");
              if (iVar16 == 0) {
                if (ppiVar7[1] == (int *)0x0) goto LAB_004418cc;
                if (ppiStack_84 != (int **)0x0) {
                  iVar16 = pkey_ctrl_string();
                  if (0 < iVar16) goto LAB_00441870;
                  uVar6 = 1;
                  pcVar12 = "parameter setting error\n";
                  iVar16 = 0;
                  (*(code *)PTR_BIO_puts_006a8058)(*(undefined4 *)puVar3);
                  (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar3);
                  goto LAB_0044171c;
                }
                (*(code *)PTR_BIO_puts_006a8058)(*(undefined4 *)puVar3,"No keytype specified\n");
                goto LAB_004418cc;
              }
              iVar16 = (*(code *)PTR_strcmp_006aac20)(piVar18,"-genparam");
              if (iVar16 == 0) {
                if (ppiStack_84 != (int **)0x0) goto LAB_004418cc;
                ppiVar7 = ppiVar7 + 1;
                bVar1 = true;
              }
              else {
                iVar16 = (*(code *)PTR_strcmp_006aac20)(piVar18,"-text");
                if (iVar16 == 0) {
                  ppiVar7 = ppiVar7 + 1;
                  bVar2 = true;
                }
                else {
                  ppiStack_94 = (int **)(*(code *)PTR_EVP_get_cipherbyname_006a8494)
                                                  ((char *)((int)piVar18 + 1));
                  if (ppiStack_94 == (int **)0x0) {
                    ppiVar13 = (int **)((int)*ppiVar7 + 1);
                    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Unknown cipher %s\n");
                    goto LAB_004418cc;
                  }
                  if (bVar1) goto LAB_004418cc;
                  ppiVar7 = ppiVar7 + 1;
                }
              }
            }
          }
        }
      }
    }
  }
  if (ppiStack_84 == (int **)0x0) {
LAB_004418cc:
    uVar6 = 1;
    iVar16 = 0;
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Usage: genpkey [options]\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"where options may be\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-out file          output file\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-outform X         output format (DER or PEM)\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-pass arg          output file pass phrase source\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-<cipher>          use cipher <cipher> to encrypt the key\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,
               "-engine e          use engine e, possibly a hardware device.\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-paramfile file    parameters file\n")
    ;
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-algorithm alg     the public key algorithm\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,
               "-pkeyopt opt:value set the public key algorithm option <opt>\n                   to value <value>\n"
              );
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-genparam          generate parameters, not key\n");
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar3,"-text              print the in text\n");
    pcVar12 = "NB: options order may be important!  See the manual page.\n";
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3);
    goto LAB_0044171c;
  }
  ppiVar15 = &piStack_80;
  ppiVar13 = (int **)0x0;
  iVar16 = app_passwd(*(undefined4 *)puVar3,piVar9,0,ppiVar15,0);
  if (iVar16 == 0) {
    iVar16 = 0;
    pcVar12 = "Error getting password\n";
    uVar6 = 1;
    (*(code *)PTR_BIO_puts_006a8058)(*(undefined4 *)puVar4);
    goto LAB_0044171c;
  }
  if (ppiStack_9c == (int **)0x0) {
    iVar16 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
  }
  else {
    iVar16 = (*(code *)PTR_BIO_new_file_006a7fac)(ppiStack_9c,&DAT_00632de8);
    if (iVar16 == 0) {
      uVar6 = 1;
      pcVar12 = "Can\'t open output file %s\n";
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4);
      ppiVar13 = ppiStack_9c;
      goto LAB_0044171c;
    }
  }
  puVar4 = PTR_bio_err_006a7f3c;
  (*(code *)PTR_EVP_PKEY_CTX_set_cb_006a8040)(ppiStack_84,genpkey_cb);
  (*(code *)PTR_EVP_PKEY_CTX_set_app_data_006a8044)(ppiStack_84,*(undefined4 *)puVar3);
  if (bVar1) {
    iVar10 = (*(code *)PTR_EVP_PKEY_paramgen_006a8838)(ppiStack_84,&pppiStack_88);
    if (iVar10 < 1) {
      uVar6 = *(undefined4 *)puVar4;
      pcVar12 = "Error generating parameters\n";
LAB_00441ff4:
      (*(code *)PTR_BIO_puts_006a8058)(uVar6);
      uVar6 = 1;
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar4);
      goto LAB_0044171c;
    }
    pcVar12 = (char *)pppiStack_88;
    iVar10 = (*(code *)PTR_PEM_write_bio_Parameters_006a883c)(iVar16);
    ppiStack_94 = ppiVar13;
  }
  else {
    iVar8 = (*(code *)PTR_EVP_PKEY_keygen_006a8048)(ppiStack_84,&pppiStack_88);
    if (iVar8 < 1) {
      uVar6 = *(undefined4 *)puVar4;
      pcVar12 = "Error generating key\n";
      goto LAB_00441ff4;
    }
    pcVar12 = (char *)pppiStack_88;
    if (iVar10 == 3) {
      ppiVar15 = (int **)0x0;
      iVar10 = (*(code *)PTR_PEM_write_bio_PrivateKey_006a8050)(iVar16);
    }
    else {
      if (iVar10 != 1) {
        uVar6 = 1;
        pcVar12 = "Bad format specified for key\n";
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4);
        goto LAB_0044171c;
      }
      iVar10 = (*(code *)PTR_i2d_PrivateKey_bio_006a8848)(iVar16);
      ppiStack_94 = ppiVar13;
    }
  }
  if (iVar10 < 1) {
    pcVar12 = "Error writing key\n";
    (*(code *)PTR_BIO_puts_006a8058)(*(undefined4 *)puVar3);
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar3);
  }
  if (bVar2) {
    pcVar17 = (code *)PTR_EVP_PKEY_print_private_006a8840;
    if (bVar1) {
      pcVar17 = (code *)PTR_EVP_PKEY_print_params_006a8844;
    }
    ppiVar15 = (int **)0x0;
    ppiStack_94 = (int **)0x0;
    pcVar12 = (char *)pppiStack_88;
    iVar10 = (*pcVar17)(iVar16);
    if (iVar10 < 1) {
      uVar6 = 0;
      pcVar12 = "Error printing key\n";
      (*(code *)PTR_BIO_puts_006a8058)(*(undefined4 *)puVar3);
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar3);
      ppiVar13 = ppiStack_94;
      goto LAB_0044171c;
    }
  }
  uVar6 = 0;
  ppiVar13 = ppiStack_94;
LAB_0044171c:
  if (pppiStack_88 != (int ***)0x0) {
    (*(code *)PTR_EVP_PKEY_free_006a7f78)();
  }
  if (ppiStack_84 != (int **)0x0) {
    (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)();
  }
  if (iVar16 != 0) {
    (*(code *)PTR_BIO_free_all_006a7f74)(iVar16);
  }
  (*(code *)PTR_BIO_free_006a7f70)(0);
  if (piStack_80 != (int *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  if (iStack_7c == *(int *)puVar5) {
    return uVar6;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  piVar9 = ppiVar15[1];
  *(int **)pcVar12 = *ppiVar15;
  *ppiVar13 = piVar9;
  return 0;
}

