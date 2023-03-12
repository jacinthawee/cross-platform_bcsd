
undefined4 * pkcs8_main(undefined4 param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined *puVar5;
  int iVar6;
  undefined *puVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  char *pcVar16;
  code *pcVar17;
  int iVar18;
  int local_a0;
  int local_98;
  int local_94;
  int local_90;
  int local_88;
  int local_80;
  undefined4 local_78;
  int local_74;
  undefined4 local_6c;
  undefined *local_68;
  undefined *local_64;
  undefined auStack_60 [52];
  int local_2c;
  
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  puVar10 = (undefined4 *)PTR_bio_err_006a6e3c;
  local_68 = (undefined *)0x0;
  local_64 = (undefined *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar8 = *(int *)PTR_bio_err_006a6e3c;
  if (iVar8 == 0) {
    iVar8 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *puVar10 = iVar8;
  }
  iVar8 = load_config(iVar8,0);
  if (iVar8 != 0) {
    iVar8 = param_2 + 4;
    (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
    (*(code *)PTR_OPENSSL_add_all_algorithms_noconf_006a73fc)();
    pcVar16 = *(char **)(param_2 + 4);
    if (pcVar16 == (char *)0x0) {
LAB_00466d58:
      local_6c = 0;
      bVar4 = false;
      local_88 = 0;
      bVar3 = false;
      iVar12 = 0;
      local_90 = 0;
      iVar13 = -1;
      local_94 = 0;
      local_98 = 3;
      local_a0 = 3;
      local_74 = 0;
      local_80 = 0;
      local_78 = 0x800;
    }
    else {
      local_88 = 0;
      bVar4 = false;
      local_6c = 0;
      if (*pcVar16 != '-') goto LAB_00466d58;
      bVar3 = false;
      local_90 = 0;
      local_94 = 0;
      local_98 = 3;
      iVar12 = 0;
      local_a0 = 3;
      iVar13 = -1;
      local_74 = 0;
      local_80 = 0;
      local_78 = 0x800;
      do {
        cVar1 = pcVar16[1];
        iVar14 = iVar8;
        if (cVar1 != 'v') {
LAB_004669c0:
          iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-inform");
          if (iVar18 == 0) {
            if (*(int *)(iVar8 + 4) == 0) goto LAB_004669f4;
            local_a0 = str2fmt();
            bVar2 = false;
            iVar14 = iVar8 + 4;
            goto LAB_00466988;
          }
          iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-outform");
          if (iVar18 == 0) {
            if (*(int *)(iVar8 + 4) == 0) goto LAB_004669f4;
            local_98 = str2fmt();
            bVar2 = false;
            iVar14 = iVar8 + 4;
            goto LAB_00466988;
          }
          iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-topk8");
          if (iVar18 == 0) {
            bVar2 = false;
            bVar3 = true;
            goto LAB_00466988;
          }
          iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-noiter");
          if (iVar18 == 0) {
            bVar2 = false;
            local_78 = 1;
            goto LAB_00466988;
          }
          iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-nocrypt");
          if (iVar18 == 0) {
            bVar2 = false;
            bVar4 = true;
            goto LAB_00466988;
          }
          iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-nooct");
          if (iVar18 == 0) {
            bVar2 = false;
            local_6c = 1;
            goto LAB_00466988;
          }
          iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-nsdb");
          if (iVar18 == 0) {
            bVar2 = false;
            local_6c = 3;
            goto LAB_00466988;
          }
          iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-embed");
          if (iVar18 == 0) {
            bVar2 = false;
            local_6c = 2;
            goto LAB_00466988;
          }
          iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-passin");
          if (iVar18 == 0) {
            local_94 = *(int *)(iVar8 + 4);
            iVar14 = local_94;
joined_r0x00466b3c:
            if (iVar14 != 0) {
              bVar2 = false;
              iVar14 = iVar8 + 4;
              goto LAB_00466988;
            }
          }
          else {
            iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-passout");
            if (iVar18 != 0) {
              iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-engine");
              if (iVar18 != 0) {
                if (((cVar1 == 'i') && (pcVar16[2] == 'n')) && (pcVar16[3] == '\0')) {
                  if (*(int *)(iVar8 + 4) == 0) {
LAB_004669f4:
                    bVar2 = true;
                  }
                  else {
                    bVar2 = false;
                    iVar14 = iVar8 + 4;
                    local_80 = *(int *)(iVar8 + 4);
                  }
                }
                else {
                  iVar18 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,&DAT_00632514);
                  if (iVar18 != 0) goto LAB_004669f4;
                  if (*(int *)(iVar8 + 4) == 0) {
                    bVar2 = true;
                  }
                  else {
                    bVar2 = false;
                    iVar14 = iVar8 + 4;
                    local_74 = *(int *)(iVar8 + 4);
                  }
                }
                goto LAB_00466988;
              }
              local_88 = *(int *)(iVar8 + 4);
              iVar14 = local_88;
              goto joined_r0x00466b3c;
            }
            local_90 = *(int *)(iVar8 + 4);
            if (local_90 != 0) {
              bVar2 = false;
              iVar14 = iVar8 + 4;
              goto LAB_00466988;
            }
          }
LAB_00466b9c:
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar10,"Usage pkcs8 [options]\n");
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar10,"where options are\n");
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar10,"-in file        input file\n");
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar10,"-inform X       input format (DER or PEM)\n")
          ;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*puVar10,"-passin arg     input file pass phrase source\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*puVar10,"-outform X      output format (DER or PEM)\n");
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar10,"-out file       output file\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*puVar10,"-passout arg    output file pass phrase source\n");
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar10,"-topk8          output PKCS8 file\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*puVar10,"-nooct          use (nonstandard) no octet format\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*puVar10,"-embed          use (nonstandard) embedded DSA parameters format\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*puVar10,"-nsdb           use (nonstandard) DSA Netscape DB format\n");
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar10,"-noiter         use 1 as iteration count\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*puVar10,"-nocrypt        use or expect unencrypted private key\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*puVar10,"-v2 alg         use PKCS#5 v2.0 and cipher \"alg\"\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*puVar10,"-v1 obj         use PKCS#5 v1.5 and cipher \"alg\"\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*puVar10," -engine e       use engine e, possibly a hardware device.\n");
          goto LAB_004667d4;
        }
        if (pcVar16[2] != '2') {
          if ((pcVar16[2] != '1') || (pcVar16[3] != '\0')) goto LAB_004669c0;
          if (*(int *)(iVar8 + 4) != 0) {
            iVar14 = iVar8 + 4;
            iVar13 = (*(code *)PTR_OBJ_txt2nid_006a6f5c)(*(int *)(iVar8 + 4),"-inform");
            if (iVar13 == 0) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*puVar10,"Unknown PBE algorithm %s\n",*(undefined4 *)(iVar8 + 4));
              bVar2 = true;
            }
            else {
              bVar2 = false;
            }
            goto LAB_00466988;
          }
          goto LAB_004669f4;
        }
        if (pcVar16[3] != '\0') goto LAB_004669c0;
        if (*(int *)(iVar8 + 4) == 0) goto LAB_004669f4;
        iVar14 = iVar8 + 4;
        iVar12 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)();
        bVar2 = false;
        if (iVar12 == 0) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*puVar10,"Unknown cipher %s\n",*(undefined4 *)(iVar8 + 4));
          bVar2 = true;
        }
LAB_00466988:
        iVar8 = iVar14 + 4;
        if (bVar2) goto LAB_00466b9c;
        pcVar16 = *(char **)(iVar14 + 4);
      } while ((pcVar16 != (char *)0x0) && (*pcVar16 == '-'));
    }
    uVar9 = setup_engine(*puVar10,local_88,0);
    iVar8 = app_passwd(*puVar10,local_94,local_90,&local_68,&local_64);
    if (iVar8 != 0) {
      if ((iVar13 == -1) && (iVar12 == 0)) {
        iVar13 = 10;
      }
      if (local_80 == 0) {
        iVar8 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14,0);
      }
      else {
        iVar8 = (*(code *)PTR_BIO_new_file_006a6eac)(local_80,&DAT_00633e40);
        if (iVar8 == 0) {
          uVar9 = *puVar10;
          iVar18 = 0;
          puVar10 = (undefined4 *)0x1;
          piVar15 = (int *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)(uVar9,"Can\'t open input file %s\n",local_80);
          iVar12 = 0;
          iVar14 = 0;
          goto LAB_004667ec;
        }
      }
      if (local_74 != 0) {
        iVar14 = (*(code *)PTR_BIO_new_file_006a6eac)(local_74,&DAT_00632420);
        if (iVar14 != 0) goto LAB_00466e28;
        (*(code *)PTR_BIO_printf_006a6e38)(*puVar10,"Can\'t open output file %s\n",local_74);
LAB_00466e68:
        puVar10 = (undefined4 *)0x1;
        iVar18 = 0;
        piVar15 = (int *)0x0;
        iVar12 = 0;
        goto LAB_004667ec;
      }
      iVar14 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
LAB_00466e28:
      puVar7 = PTR_bio_err_006a6e3c;
      if (bVar3) {
        iVar18 = load_key(*puVar10,local_80,local_a0,1,local_68,uVar9,"key");
        if (iVar18 == 0) {
          puVar10 = (undefined4 *)0x1;
          piVar15 = (int *)0x0;
          iVar12 = 0;
          goto LAB_004667ec;
        }
        piVar15 = (int *)(*(code *)PTR_EVP_PKEY2PKCS8_broken_006a7cb8)(iVar18,local_6c);
        if (piVar15 == (int *)0x0) {
          puVar10 = (undefined4 *)0x1;
          iVar12 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar7,"Error converting key\n");
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar7);
          goto LAB_004667ec;
        }
        if (bVar4) {
          pcVar17 = (code *)PTR_PEM_write_bio_PKCS8_PRIV_KEY_INFO_006a7cd4;
          if ((local_98 == 3) ||
             (pcVar17 = (code *)PTR_i2d_PKCS8_PRIV_KEY_INFO_bio_006a7ccc, local_98 == 1)) {
            (*pcVar17)(iVar14,piVar15);
            puVar10 = (undefined4 *)0x0;
            iVar12 = 0;
          }
          else {
            puVar10 = (undefined4 *)0x1;
            iVar12 = 0;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar7,"Bad format specified for key\n");
          }
          goto LAB_004667ec;
        }
        puVar7 = local_64;
        if (local_64 == (undefined *)0x0) {
          puVar7 = auStack_60;
          iVar6 = (*(code *)PTR_EVP_read_pw_string_006a7278)
                            (puVar7,0x32,"Enter Encryption Password:",1);
          if (iVar6 != 0) {
            puVar10 = (undefined4 *)0x1;
            iVar12 = 0;
            goto LAB_004667ec;
          }
        }
        puVar11 = (undefined4 *)PTR_bio_err_006a6e3c;
        app_RAND_load_file(0,*puVar10,0);
        uVar9 = (*(code *)PTR_strlen_006a9a24)(puVar7);
        iVar12 = (*(code *)PTR_PKCS8_encrypt_006a7cbc)
                           (iVar13,iVar12,puVar7,uVar9,0,0,local_78,piVar15);
        if (iVar12 == 0) {
          uVar9 = *puVar11;
          pcVar16 = "Error encrypting key\n";
          goto LAB_004673a0;
        }
        app_RAND_write_file(0,*puVar11);
        pcVar17 = (code *)PTR_PEM_write_bio_PKCS8_006a7cd0;
        if ((local_98 == 3) ||
           (puVar10 = puVar11, pcVar17 = (code *)PTR_i2d_PKCS8_bio_006a7cc0, local_98 == 1)) {
          (*pcVar17)(iVar14,iVar12);
          puVar10 = (undefined4 *)0x0;
          goto LAB_004667ec;
        }
      }
      else {
        if (bVar4) {
          if (local_a0 == 3) {
            piVar15 = (int *)(*(code *)PTR_PEM_read_bio_PKCS8_PRIV_KEY_INFO_006a7cc8)(iVar8,0,0,0);
            iVar12 = 0;
          }
          else {
            if (local_a0 != 1) {
LAB_00466e54:
              (*(code *)PTR_BIO_printf_006a6e38)(*puVar10,"Bad format specified for key\n");
              goto LAB_00466e68;
            }
            iVar12 = 0;
            piVar15 = (int *)(*(code *)PTR_d2i_PKCS8_PRIV_KEY_INFO_bio_006a7cac)(iVar8,0);
          }
        }
        else {
          if (local_a0 == 3) {
            iVar12 = (*(code *)PTR_PEM_read_bio_PKCS8_006a7cc4)(iVar8,0,0,0);
          }
          else {
            if (local_a0 != 1) goto LAB_00466e54;
            iVar12 = (*(code *)PTR_d2i_PKCS8_bio_006a7cb0)(iVar8,0);
          }
          if (iVar12 == 0) goto LAB_00467590;
          puVar7 = local_68;
          if (local_68 == (undefined *)0x0) {
            puVar7 = auStack_60;
            (*(code *)PTR_EVP_read_pw_string_006a7278)(puVar7,0x32,"Enter Password:",0);
          }
          uVar9 = (*(code *)PTR_strlen_006a9a24)(puVar7);
          piVar15 = (int *)(*(code *)PTR_PKCS8_decrypt_006a7cb4)(iVar12,puVar7,uVar9);
        }
        if (piVar15 == (int *)0x0) {
          iVar18 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar10,"Error decrypting key\n");
          uVar9 = *puVar10;
          puVar10 = (undefined4 *)0x1;
          (*(code *)PTR_ERR_print_errors_006a6e40)(uVar9);
          goto LAB_004667ec;
        }
        iVar18 = (*(code *)PTR_EVP_PKCS82PKEY_006a7220)(piVar15);
        puVar7 = PTR_bio_err_006a6e3c;
        if (iVar18 == 0) {
          uVar9 = *puVar10;
          pcVar16 = "Error converting key\n";
          puVar11 = puVar10;
LAB_004673a0:
          (*(code *)PTR_BIO_printf_006a6e38)(uVar9,pcVar16);
          puVar10 = (undefined4 *)0x1;
          (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar11);
          goto LAB_004667ec;
        }
        if (*piVar15 != 0) {
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar10,"Warning: broken key encoding: ");
          iVar13 = *piVar15;
          if (iVar13 == 2) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar7,"DSA parameters included in PrivateKey\n");
          }
          else if (iVar13 < 3) {
            if (iVar13 == 1) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar7,"No Octet String in PrivateKey\n");
            }
            else {
LAB_004674fc:
              (*(code *)PTR_BIO_printf_006a6e38)(*puVar10,"Unknown broken type\n");
            }
          }
          else if (iVar13 == 3) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar7,"DSA public key include in PrivateKey\n");
          }
          else {
            if (iVar13 != 4) goto LAB_004674fc;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar7,"DSA private key value is negative\n");
          }
        }
        if (local_98 == 3) {
          puVar10 = (undefined4 *)0x0;
          (*(code *)PTR_PEM_write_bio_PrivateKey_006a6f50)(iVar14,iVar18,0,0,0,0,local_64);
          goto LAB_004667ec;
        }
        if (local_98 == 1) {
          puVar10 = (undefined4 *)0x0;
          (*(code *)PTR_i2d_PrivateKey_bio_006a7758)(iVar14,iVar18);
          goto LAB_004667ec;
        }
      }
      uVar9 = *puVar10;
      puVar10 = (undefined4 *)0x1;
      (*(code *)PTR_BIO_printf_006a6e38)(uVar9,"Bad format specified for key\n");
      goto LAB_004667ec;
    }
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"Error getting passwords\n");
  }
LAB_004667d4:
  puVar10 = (undefined4 *)0x1;
  iVar18 = 0;
  piVar15 = (int *)0x0;
  iVar12 = 0;
  iVar14 = 0;
  iVar8 = 0;
LAB_004667ec:
  while( true ) {
    (*(code *)PTR_X509_SIG_free_006a7ca8)(iVar12);
    (*(code *)PTR_PKCS8_PRIV_KEY_INFO_free_006a722c)(piVar15);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar18);
    (*(code *)PTR_BIO_free_all_006a6e74)(iVar14);
    (*(code *)PTR_BIO_free_006a6e70)(iVar8);
    if (local_68 != (undefined *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (local_64 != (undefined *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (local_2c == *(int *)puVar5) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00467590:
    iVar18 = 0;
    piVar15 = (int *)0x0;
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar10,"Error reading key\n");
    uVar9 = *puVar10;
    puVar10 = (undefined4 *)0x1;
    (*(code *)PTR_ERR_print_errors_006a6e40)(uVar9);
  }
  return puVar10;
}

