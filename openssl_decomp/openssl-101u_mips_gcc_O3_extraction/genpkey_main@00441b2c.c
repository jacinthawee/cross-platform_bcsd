
undefined4 genpkey_main(undefined4 param_1,int param_2,int **param_3,int **param_4)

{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  int **ppiVar10;
  undefined4 uVar11;
  char **ppcVar12;
  int iVar13;
  char *pcVar14;
  code *pcVar15;
  int **local_5c;
  int **local_4c;
  int **local_44;
  int ***local_38;
  int **local_34;
  int *local_30;
  int local_2c;
  
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  puVar3 = PTR_bio_err_006a6e3c;
  local_38 = (int ***)0x0;
  local_34 = (int **)0x0;
  local_30 = (int *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar8 = *(int *)PTR_bio_err_006a6e3c;
  if (iVar8 == 0) {
    iVar8 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(int *)puVar3 = iVar8;
  }
  pcVar9 = (char *)0x0;
  iVar8 = load_config(iVar8);
  if (iVar8 == 0) {
LAB_00441ba4:
    uVar11 = 1;
    iVar13 = 0;
    goto LAB_00441bac;
  }
  ppcVar12 = (char **)(param_2 + 4);
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  iVar8 = 3;
  pcVar14 = (char *)0x0;
  (*(code *)PTR_OPENSSL_add_all_algorithms_noconf_006a73fc)();
  bVar1 = false;
  bVar2 = false;
  local_44 = (int **)0x0;
  local_4c = (int **)0x0;
  local_5c = (int **)0x0;
  while ((puVar4 = PTR_bio_err_006a6e3c, pcVar9 = *ppcVar12, pcVar9 != (char *)0x0 &&
         (*pcVar9 == '-'))) {
    iVar13 = (*(code *)PTR_strcmp_006a9b18)(pcVar9,"-outform");
    if (iVar13 == 0) {
      if (ppcVar12[1] == (char *)0x0) goto LAB_00441d5c;
      iVar8 = str2fmt();
LAB_00441d00:
      ppcVar12 = ppcVar12 + 2;
    }
    else {
      iVar13 = (*(code *)PTR_strcmp_006a9b18)(pcVar9,"-pass");
      if (iVar13 == 0) {
        pcVar14 = ppcVar12[1];
        if (pcVar14 == (char *)0x0) goto LAB_00441d5c;
LAB_00441d30:
        ppcVar12 = ppcVar12 + 2;
      }
      else {
        iVar13 = (*(code *)PTR_strcmp_006a9b18)(pcVar9,"-engine");
        if (iVar13 == 0) {
          if (ppcVar12[1] == (char *)0x0) goto LAB_00441d5c;
          param_3 = (int **)0x0;
          ppcVar12 = ppcVar12 + 2;
          local_5c = (int **)setup_engine(*(undefined4 *)puVar3);
        }
        else {
          iVar13 = (*(code *)PTR_strcmp_006a9b18)(pcVar9,"-paramfile");
          if (iVar13 == 0) {
            ppiVar10 = (int **)ppcVar12[1];
            param_3 = ppiVar10;
            if ((ppiVar10 == (int **)0x0) || (bVar1)) goto LAB_00441d5c;
            uVar11 = *(undefined4 *)puVar3;
            if (local_34 != (int **)0x0) {
              pcVar9 = "Parameters already set!\n";
              (*(code *)PTR_BIO_puts_006a6f58)(uVar11);
              param_3 = ppiVar10;
              goto LAB_00441ba4;
            }
            iVar13 = (*(code *)PTR_BIO_new_file_006a6eac)(ppiVar10,"r");
            if (iVar13 == 0) {
              pcVar9 = "Can\'t open parameter file %s\n";
              (*(code *)PTR_BIO_printf_006a6e38)(uVar11);
              param_3 = ppiVar10;
              goto LAB_00441ba4;
            }
            iVar6 = (*(code *)PTR_PEM_read_bio_Parameters_006a6fc8)(iVar13,0);
            (*(code *)PTR_BIO_free_006a6e70)(iVar13);
            if (iVar6 == 0) {
              pcVar9 = "Error reading parameter file %s\n";
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3);
              param_3 = ppiVar10;
              goto LAB_00441ba4;
            }
            param_3 = (int **)(*(code *)PTR_EVP_PKEY_CTX_new_006a6fe0)(iVar6,local_5c);
            if (param_3 == (int **)0x0) {
              pcVar9 = "Error initializing context\n";
              (*(code *)PTR_BIO_puts_006a6f58)(uVar11);
              (*(code *)PTR_ERR_print_errors_006a6e40)(uVar11);
LAB_004420a8:
              (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar6);
              param_3 = ppiVar10;
              goto LAB_00441ba4;
            }
            iVar13 = (*(code *)PTR_EVP_PKEY_keygen_init_006a6fe8)(param_3);
            if (iVar13 < 1) {
              pcVar9 = "Error initializing context\n";
              (*(code *)PTR_BIO_puts_006a6f58)(uVar11);
              (*(code *)PTR_ERR_print_errors_006a6e40)(uVar11);
              (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(param_3);
              ppiVar10 = param_3;
              goto LAB_004420a8;
            }
            (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar6);
            ppcVar12 = ppcVar12 + 2;
            local_34 = param_3;
          }
          else {
            iVar13 = (*(code *)PTR_strcmp_006a9b18)(pcVar9,&DAT_00632514);
            if (iVar13 == 0) {
              local_4c = (int **)ppcVar12[1];
              if (local_4c != (int **)0x0) goto LAB_00441d30;
              goto LAB_00441d5c;
            }
            iVar13 = (*(code *)PTR_strcmp_006a9b18)(pcVar9,"-algorithm");
            if (iVar13 == 0) {
              param_3 = (int **)ppcVar12[1];
              if (param_3 == (int **)0x0) goto LAB_00441d5c;
              pcVar9 = (char *)&local_34;
              param_4 = local_5c;
              iVar13 = init_gen_str(*(undefined4 *)puVar3);
              if (iVar13 == 0) goto LAB_00441ba4;
              ppcVar12 = ppcVar12 + 2;
            }
            else {
              iVar13 = (*(code *)PTR_strcmp_006a9b18)(pcVar9,"-pkeyopt");
              if (iVar13 == 0) {
                if (ppcVar12[1] == (char *)0x0) goto LAB_00441d5c;
                if (local_34 != (int **)0x0) {
                  iVar13 = pkey_ctrl_string();
                  if (0 < iVar13) goto LAB_00441d00;
                  uVar11 = 1;
                  pcVar9 = "parameter setting error\n";
                  iVar13 = 0;
                  (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar3);
                  (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar3);
                  goto LAB_00441bac;
                }
                (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar3,"No keytype specified\n");
                goto LAB_00441d5c;
              }
              iVar13 = (*(code *)PTR_strcmp_006a9b18)(pcVar9,"-genparam");
              if (iVar13 == 0) {
                if (local_34 != (int **)0x0) goto LAB_00441d5c;
                ppcVar12 = ppcVar12 + 1;
                bVar1 = true;
              }
              else {
                iVar13 = (*(code *)PTR_strcmp_006a9b18)(pcVar9,"-text");
                if (iVar13 == 0) {
                  ppcVar12 = ppcVar12 + 1;
                  bVar2 = true;
                }
                else {
                  local_44 = (int **)(*(code *)PTR_EVP_get_cipherbyname_006a7394)(pcVar9 + 1);
                  if (local_44 == (int **)0x0) {
                    param_3 = (int **)(*ppcVar12 + 1);
                    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"Unknown cipher %s\n");
                    goto LAB_00441d5c;
                  }
                  if (bVar1) goto LAB_00441d5c;
                  ppcVar12 = ppcVar12 + 1;
                }
              }
            }
          }
        }
      }
    }
  }
  if (local_34 == (int **)0x0) {
LAB_00441d5c:
    uVar11 = 1;
    iVar13 = 0;
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"Usage: genpkey [options]\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"where options may be\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"-out file          output file\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar3,"-outform X         output format (DER or PEM)\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar3,"-pass arg          output file pass phrase source\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar3,"-<cipher>          use cipher <cipher> to encrypt the key\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar3,
               "-engine e          use engine e, possibly a hardware device.\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3,"-paramfile file    parameters file\n")
    ;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar3,"-algorithm alg     the public key algorithm\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar3,
               "-pkeyopt opt:value set the public key algorithm option <opt>\n                   to value <value>\n"
              );
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar3,"-genparam          generate parameters, not key\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar3,"-text              print the in text\n");
    pcVar9 = "NB: options order may be important!  See the manual page.\n";
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar3);
    goto LAB_00441bac;
  }
  param_4 = &local_30;
  param_3 = (int **)0x0;
  iVar13 = app_passwd(*(undefined4 *)puVar3,pcVar14,0,param_4,0);
  if (iVar13 == 0) {
    iVar13 = 0;
    pcVar9 = "Error getting password\n";
    uVar11 = 1;
    (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar4);
    goto LAB_00441bac;
  }
  if (local_4c == (int **)0x0) {
    iVar13 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
  }
  else {
    iVar13 = (*(code *)PTR_BIO_new_file_006a6eac)(local_4c,&DAT_00632420);
    if (iVar13 == 0) {
      uVar11 = 1;
      pcVar9 = "Can\'t open output file %s\n";
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4);
      param_3 = local_4c;
      goto LAB_00441bac;
    }
  }
  puVar4 = PTR_bio_err_006a6e3c;
  (*(code *)PTR_EVP_PKEY_CTX_set_cb_006a6f40)(local_34,genpkey_cb);
  (*(code *)PTR_EVP_PKEY_CTX_set_app_data_006a6f44)(local_34,*(undefined4 *)puVar3);
  if (bVar1) {
    iVar8 = (*(code *)PTR_EVP_PKEY_paramgen_006a7748)(local_34,&local_38);
    if (iVar8 < 1) {
      uVar11 = *(undefined4 *)puVar4;
      pcVar9 = "Error generating parameters\n";
LAB_00442484:
      (*(code *)PTR_BIO_puts_006a6f58)(uVar11);
      uVar11 = 1;
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
      goto LAB_00441bac;
    }
    pcVar9 = (char *)local_38;
    iVar8 = (*(code *)PTR_PEM_write_bio_Parameters_006a774c)(iVar13);
    local_44 = param_3;
  }
  else {
    iVar6 = (*(code *)PTR_EVP_PKEY_keygen_006a6f48)(local_34,&local_38);
    if (iVar6 < 1) {
      uVar11 = *(undefined4 *)puVar4;
      pcVar9 = "Error generating key\n";
      goto LAB_00442484;
    }
    pcVar9 = (char *)local_38;
    if (iVar8 == 3) {
      param_4 = (int **)0x0;
      iVar8 = (*(code *)PTR_PEM_write_bio_PrivateKey_006a6f50)(iVar13);
    }
    else {
      if (iVar8 != 1) {
        uVar11 = 1;
        pcVar9 = "Bad format specified for key\n";
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4);
        goto LAB_00441bac;
      }
      iVar8 = (*(code *)PTR_i2d_PrivateKey_bio_006a7758)(iVar13);
      local_44 = param_3;
    }
  }
  if (iVar8 < 1) {
    pcVar9 = "Error writing key\n";
    (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar3);
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar3);
  }
  if (bVar2) {
    pcVar15 = (code *)PTR_EVP_PKEY_print_private_006a7750;
    if (bVar1) {
      pcVar15 = (code *)PTR_EVP_PKEY_print_params_006a7754;
    }
    param_4 = (int **)0x0;
    local_44 = (int **)0x0;
    pcVar9 = (char *)local_38;
    iVar8 = (*pcVar15)(iVar13);
    if (iVar8 < 1) {
      uVar11 = 0;
      pcVar9 = "Error printing key\n";
      (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar3);
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar3);
      param_3 = local_44;
      goto LAB_00441bac;
    }
  }
  uVar11 = 0;
  param_3 = local_44;
LAB_00441bac:
  if (local_38 != (int ***)0x0) {
    (*(code *)PTR_EVP_PKEY_free_006a6e78)();
  }
  if (local_34 != (int **)0x0) {
    (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)();
  }
  if (iVar13 != 0) {
    (*(code *)PTR_BIO_free_all_006a6e74)(iVar13);
  }
  (*(code *)PTR_BIO_free_006a6e70)(0);
  if (local_30 != (int *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  if (local_2c != *(int *)puVar5) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    piVar7 = param_4[1];
    *(int **)pcVar9 = *param_4;
    *param_3 = piVar7;
    return 0;
  }
  return uVar11;
}
