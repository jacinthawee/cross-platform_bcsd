
undefined4 pkeyparam_main(undefined4 param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char **ppcVar12;
  
  puVar3 = PTR_bio_err_006a7f3c;
  iVar6 = *(int *)PTR_bio_err_006a7f3c;
  if (iVar6 == 0) {
    iVar6 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *(int *)puVar3 = iVar6;
  }
  iVar6 = load_config(iVar6,0);
  if (iVar6 == 0) {
    uVar8 = 1;
    iVar5 = 0;
    iVar4 = 0;
    iVar6 = 0;
  }
  else {
    ppcVar12 = (char **)(param_2 + 4);
    (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
    pcVar11 = (char *)0x0;
    pcVar9 = (char *)0x0;
    pcVar7 = (char *)0x0;
    (*(code *)PTR_OPENSSL_add_all_algorithms_noconf_006a84fc)();
    bVar1 = false;
    bVar2 = false;
    pcVar10 = *ppcVar12;
    while ((pcVar10 != (char *)0x0 && (*pcVar10 == '-'))) {
      if ((pcVar10[1] == 'i') && ((pcVar10[2] == 'n' && (pcVar10[3] == '\0')))) {
        pcVar7 = ppcVar12[1];
        pcVar10 = pcVar7;
joined_r0x004675fc:
        if (pcVar10 == (char *)0x0) {
LAB_00467604:
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Usage pkeyparam [options]\n");
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"where options are\n");
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-in file        input file\n");
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"-out file       output file\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar3,"-text           print parameters as text\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar3,"-noout          don\'t output encoded parameters\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar3,
                     "-engine e       use engine e, possibly a hardware device.\n");
          return 1;
        }
        ppcVar12 = ppcVar12 + 2;
      }
      else {
        iVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar10,&DAT_00632edc);
        if (iVar6 == 0) {
          pcVar9 = ppcVar12[1];
          pcVar10 = pcVar9;
          goto joined_r0x004675fc;
        }
        iVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar10,"-engine");
        if (iVar6 == 0) {
          pcVar11 = ppcVar12[1];
          if (pcVar11 == (char *)0x0) goto LAB_00467604;
          ppcVar12 = ppcVar12 + 2;
        }
        else {
          iVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar10,"-text");
          if (iVar6 == 0) {
            ppcVar12 = ppcVar12 + 1;
            bVar2 = true;
          }
          else {
            ppcVar12 = ppcVar12 + 1;
            iVar6 = (*(code *)PTR_strcmp_006aac20)(pcVar10,"-noout");
            if (iVar6 == 0) {
              bVar1 = true;
            }
          }
        }
      }
      pcVar10 = *ppcVar12;
    }
    setup_engine(*(undefined4 *)puVar3,pcVar11,0);
    if (pcVar7 == (char *)0x0) {
      iVar6 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdin_006aab20,0);
    }
    else {
      iVar6 = (*(code *)PTR_BIO_new_file_006a7fac)(pcVar7,"r");
      if (iVar6 == 0) {
        uVar8 = 1;
        iVar5 = 0;
        iVar4 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,"Can\'t open input file %s\n",pcVar7);
        goto LAB_00467740;
      }
    }
    if (pcVar9 == (char *)0x0) {
      iVar4 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
    }
    else {
      iVar4 = (*(code *)PTR_BIO_new_file_006a7fac)(pcVar9,"w");
      if (iVar4 == 0) {
        uVar8 = 1;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar3,"Can\'t open output file %s\n",pcVar9);
        iVar5 = 0;
        goto LAB_00467740;
      }
    }
    iVar5 = (*(code *)PTR_PEM_read_bio_Parameters_006a80c8)(iVar6,0);
    if (iVar5 == 0) {
      uVar8 = 1;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar3,"Error reading parameters\n");
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar3);
    }
    else {
      if (!bVar1) {
        (*(code *)PTR_PEM_write_bio_Parameters_006a883c)(iVar4,iVar5);
      }
      if (bVar2) {
        (*(code *)PTR_EVP_PKEY_print_params_006a8844)(iVar4,iVar5,0,0);
        uVar8 = 0;
      }
      else {
        uVar8 = 0;
      }
    }
  }
LAB_00467740:
  (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar5);
  (*(code *)PTR_BIO_free_all_006a7f74)(iVar4);
  (*(code *)PTR_BIO_free_006a7f70)(iVar6);
  return uVar8;
}

