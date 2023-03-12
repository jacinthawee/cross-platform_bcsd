
undefined4 * spkac_main(int param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  char **ppcVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 *puVar10;
  char *pcVar11;
  int iVar12;
  int iVar13;
  char *pcVar14;
  char *pcVar15;
  char *local_80;
  char *local_74;
  char *local_68;
  char *local_5c;
  char *local_54;
  char *local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  puVar10 = (undefined4 *)PTR_bio_err_006a7f3c;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar7 = *puVar10;
  if (iVar7 == 0) {
    iVar7 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *puVar10 = iVar7;
  }
  iVar7 = load_config(iVar7,0);
  if (iVar7 != 0) {
    uVar4 = *param_2;
    param_1 = param_1 + -1;
    ppcVar6 = (char **)(param_2 + 1);
    if (0 < param_1) {
      local_4c = (char *)0x0;
      local_74 = (char *)0x0;
      local_68 = (char *)0x0;
      local_80 = (char *)0x0;
      local_40 = 0;
      local_54 = "default";
      pcVar14 = (char *)0x0;
      local_44 = 0;
      local_48 = 0;
      pcVar11 = (char *)0x0;
      bVar1 = false;
      local_5c = "SPKAC";
LAB_00468d0c:
      pcVar15 = *ppcVar6;
      if ((((*pcVar15 == '-') && (pcVar15[1] == 'i')) && (pcVar15[2] == 'n')) &&
         (pcVar15[3] == '\0')) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_00468d5c;
        pcVar11 = ppcVar6[1];
        ppcVar6 = ppcVar6 + 1;
      }
      else {
        iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar15,&DAT_00632edc);
        if (iVar7 == 0) {
          if (param_1 == 1) goto LAB_00468d5c;
          pcVar14 = ppcVar6[1];
          param_1 = param_1 + -2;
          ppcVar6 = ppcVar6 + 2;
          goto joined_r0x00468d48;
        }
        iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-passin");
        if (iVar7 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_00468d5c;
          local_80 = ppcVar6[1];
          ppcVar6 = ppcVar6 + 1;
        }
        else {
          iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar15,&DAT_006330b4);
          if (iVar7 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00468d5c;
            local_74 = ppcVar6[1];
            ppcVar6 = ppcVar6 + 1;
          }
          else {
            iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-challenge");
            if (iVar7 == 0) {
              param_1 = param_1 + -1;
              if (param_1 != 0) {
                local_68 = ppcVar6[1];
                ppcVar6 = ppcVar6 + 1;
                goto LAB_00468d00;
              }
              goto LAB_00468d5c;
            }
            iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-spkac");
            if (iVar7 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_00468d5c;
              local_5c = ppcVar6[1];
              ppcVar6 = ppcVar6 + 1;
            }
            else {
              iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-spksect");
              if (iVar7 == 0) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_00468d5c;
                local_54 = ppcVar6[1];
                ppcVar6 = ppcVar6 + 1;
              }
              else {
                iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-engine");
                if (iVar7 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_00468d5c;
                  local_4c = ppcVar6[1];
                  ppcVar6 = ppcVar6 + 1;
                }
                else {
                  iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-noout");
                  if (iVar7 == 0) {
                    local_44 = 1;
                  }
                  else {
                    iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-pubkey");
                    if (iVar7 == 0) {
                      local_40 = 1;
                    }
                    else {
                      iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar15,"-verify");
                      if (iVar7 == 0) {
                        local_48 = 1;
                      }
                      else {
                        bVar1 = true;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
LAB_00468d00:
      param_1 = param_1 + -1;
      ppcVar6 = ppcVar6 + 1;
joined_r0x00468d48:
      if (param_1 == 0) goto LAB_00468d50;
      goto LAB_00468d0c;
    }
    local_44 = 0;
    pcVar11 = (char *)0x0;
    local_80 = (char *)0x0;
    local_68 = (char *)0x0;
    pcVar14 = (char *)0x0;
    local_74 = (char *)0x0;
    local_4c = (char *)0x0;
    local_5c = "SPKAC";
    local_40 = 0;
    local_48 = 0;
    local_54 = "default";
    goto LAB_00469078;
  }
LAB_00468e84:
  iVar12 = 0;
  piVar9 = (int *)0x0;
  uVar4 = 0;
  iVar13 = 0;
  iVar7 = 0;
  puVar10 = (undefined4 *)0x1;
LAB_00468e9c:
  do {
    while( true ) {
      while( true ) {
        (*(code *)PTR_NCONF_free_006a7f6c)(uVar4);
        (*(code *)PTR_NETSCAPE_SPKI_free_006a81b8)(piVar9);
        (*(code *)PTR_BIO_free_006a7f70)(iVar7);
        (*(code *)PTR_BIO_free_all_006a7f74)(iVar13);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar12);
        if (local_30 != 0) {
          (*(code *)PTR_CRYPTO_free_006a7f88)();
        }
        if (local_2c == *(int *)puVar3) {
          return puVar10;
        }
        (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0046951c:
        iVar13 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
LAB_00469450:
        if (iVar13 != 0) break;
        iVar12 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)(*puVar10,"Error opening output file\n");
        uVar8 = *puVar10;
        puVar10 = (undefined4 *)0x1;
        (*(code *)PTR_ERR_print_errors_006a7f40)(uVar8);
      }
      if (local_44 == 0) {
        (*(code *)PTR_NETSCAPE_SPKI_print_006a8e20)(iVar13,piVar9);
      }
      iVar12 = (*(code *)PTR_NETSCAPE_SPKI_get_pubkey_006a81ac)(piVar9);
      if (local_48 != 0) break;
LAB_0046947c:
      if (local_40 == 0) {
        puVar10 = (undefined4 *)0x0;
      }
      else {
        puVar10 = (undefined4 *)0x0;
        (*(code *)PTR_PEM_write_bio_PUBKEY_006a8028)(iVar13,iVar12);
      }
    }
    iVar5 = (*(code *)PTR_NETSCAPE_SPKI_verify_006a81b0)(piVar9,iVar12);
    if (0 < iVar5) {
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar10,"Signature OK\n");
      goto LAB_0046947c;
    }
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar10,"Signature Failure\n");
    uVar8 = *puVar10;
    puVar10 = (undefined4 *)0x1;
    (*(code *)PTR_ERR_print_errors_006a7f40)(uVar8);
  } while( true );
LAB_00468d50:
  if (bVar1) {
LAB_00468d5c:
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar10,"%s [options]\n",uVar4);
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar10,"where options are\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar10," -in arg        input file\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar10," -out arg       output file\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar10," -key arg       create SPKAC using private key\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar10," -passin arg    input file pass phrase source\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar10," -challenge arg challenge string\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar10," -spkac arg     alternative SPKAC name\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar10," -noout         don\'t print SPKAC\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar10," -pubkey        output public key\n");
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar10," -verify        verify SPKAC signature\n");
    uVar4 = *puVar10;
    pcVar14 = " -engine e      use engine e, possibly a hardware device.\n";
  }
  else {
LAB_00469078:
    puVar2 = PTR_bio_err_006a7f3c;
    (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
    iVar7 = app_passwd(*puVar10,local_80,0,&local_30,0);
    if (iVar7 != 0) {
      uVar4 = setup_engine(*(undefined4 *)puVar2,local_4c,0);
      if (local_74 == (char *)0x0) {
        if (pcVar11 == (char *)0x0) {
          iVar7 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdin_006aab20,0);
        }
        else {
          iVar7 = (*(code *)PTR_BIO_new_file_006a7fac)(pcVar11,"r");
        }
        if (iVar7 == 0) {
          iVar12 = 0;
          piVar9 = (int *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar10,"Error opening input file\n");
          uVar4 = 0;
          iVar13 = 0;
          uVar8 = *puVar10;
          puVar10 = (undefined4 *)0x1;
          (*(code *)PTR_ERR_print_errors_006a7f40)(uVar8);
        }
        else {
          uVar4 = (*(code *)PTR_NCONF_new_006a7f58)(0);
          iVar12 = (*(code *)PTR_NCONF_load_bio_006a8e1c)(uVar4,iVar7,0);
          if (iVar12 == 0) {
            (*(code *)PTR_BIO_printf_006a7f38)(*puVar10,"Error parsing config file\n");
          }
          else {
            iVar12 = (*(code *)PTR_NCONF_get_string_006a7fa8)(uVar4,local_54,local_5c);
            if (iVar12 != 0) {
              piVar9 = (int *)(*(code *)PTR_NETSCAPE_SPKI_b64_decode_006a81d4)(iVar12,0xffffffff);
              if (piVar9 != (int *)0x0) {
                if (pcVar14 == (char *)0x0) goto LAB_0046951c;
                iVar13 = (*(code *)PTR_BIO_new_file_006a7fac)(pcVar14,"w");
                goto LAB_00469450;
              }
              iVar12 = 0;
              iVar13 = 0;
              (*(code *)PTR_BIO_printf_006a7f38)(*puVar10,"Error loading SPKAC\n");
              uVar8 = *puVar10;
              puVar10 = (undefined4 *)0x1;
              (*(code *)PTR_ERR_print_errors_006a7f40)(uVar8);
              goto LAB_00468e9c;
            }
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*puVar10,"Can\'t find SPKAC called \"%s\"\n",local_5c);
          }
          uVar8 = *puVar10;
          iVar12 = 0;
          piVar9 = (int *)0x0;
          iVar13 = 0;
          puVar10 = (undefined4 *)0x1;
          (*(code *)PTR_ERR_print_errors_006a7f40)(uVar8);
        }
        goto LAB_00468e9c;
      }
      if ((*local_74 == '-') && (local_74[1] == '\0')) {
        local_74 = (char *)0x0;
      }
      iVar12 = load_key(*(undefined4 *)puVar2,local_74,3,1,local_30,uVar4,"private key");
      if (iVar12 != 0) {
        piVar9 = (int *)(*(code *)PTR_NETSCAPE_SPKI_new_006a8e08)();
        if (local_68 != (char *)0x0) {
          uVar4 = (*(code *)PTR_strlen_006aab30)(local_68);
          (*(code *)PTR_ASN1_STRING_set_006a8e0c)(*(undefined4 *)(*piVar9 + 4),local_68,uVar4);
        }
        (*(code *)PTR_NETSCAPE_SPKI_set_pubkey_006a8e10)(piVar9,iVar12);
        uVar4 = (*(code *)PTR_EVP_md5_006a81c8)();
        (*(code *)PTR_NETSCAPE_SPKI_sign_006a8e14)(piVar9,iVar12,uVar4);
        uVar8 = (*(code *)PTR_NETSCAPE_SPKI_b64_encode_006a8e18)(piVar9);
        if (pcVar14 == (char *)0x0) {
          iVar13 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
        }
        else {
          iVar13 = (*(code *)PTR_BIO_new_file_006a7fac)(pcVar14,"w");
        }
        if (iVar13 == 0) {
          uVar4 = 0;
          iVar7 = 0;
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar10,"Error opening output file\n");
          uVar8 = *puVar10;
          puVar10 = (undefined4 *)0x1;
          (*(code *)PTR_ERR_print_errors_006a7f40)(uVar8);
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)(iVar13,"SPKAC=%s\n",uVar8);
          uVar4 = 0;
          iVar7 = 0;
          puVar10 = (undefined4 *)0x0;
          (*(code *)PTR_CRYPTO_free_006a7f88)(uVar8);
        }
        goto LAB_00468e9c;
      }
      goto LAB_00468e84;
    }
    uVar4 = *(undefined4 *)puVar2;
    pcVar14 = "Error getting password\n";
  }
  (*(code *)PTR_BIO_printf_006a7f38)(uVar4,pcVar14);
  goto LAB_00468e84;
}

