
bool genrsa_cb(int param_1,undefined4 param_2,undefined4 *param_3)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  char **ppcVar9;
  char *pcVar10;
  undefined4 uVar11;
  bool bVar12;
  undefined4 *puVar13;
  int unaff_s2;
  char **ppcVar14;
  int unaff_s6;
  int unaff_s7;
  undefined4 uVar15;
  char *pcVar16;
  undefined4 uStack_a0;
  char *pcStack_98;
  char *pcStack_90;
  undefined4 uStack_8c;
  char *pcStack_84;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  char *pcStack_6c;
  undefined4 uStack_68;
  int iStack_64;
  code *pcStack_60;
  int iStack_5c;
  undefined *puStack_58;
  undefined4 *puStack_54;
  undefined local_15;
  int local_14;
  
  puStack_58 = PTR___stack_chk_guard_006aabf0;
  local_15 = 0x2a;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_1 == 0) {
    local_15 = 0x2e;
  }
  else if (param_1 == 1) {
    local_15 = 0x2b;
  }
  else if ((param_1 != 2) && (param_1 == 3)) {
    local_15 = 10;
  }
  (*(code *)PTR_BIO_write_006a7f14)(param_3[1],&local_15,1);
  pcVar10 = &DAT_0000000b;
  (*(code *)PTR_BIO_ctrl_006a7f18)(param_3[1],0xb,0,0);
  if (local_14 == *(int *)puStack_58) {
    return true;
  }
  iVar6 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iStack_78 = 0x400;
  iStack_74 = 0;
  iStack_5c = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_54 = param_3;
  iVar3 = (*(code *)PTR_BN_new_006a82b4)();
  puVar13 = (undefined4 *)PTR_bio_err_006a7f3c;
  if (iVar3 == 0) {
    bVar12 = true;
    if (iStack_74 != 0) goto LAB_0043ffac;
    goto LAB_00440268;
  }
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar8 = *puVar13;
  uStack_68 = 2;
  pcStack_60 = genrsa_cb;
  iStack_64 = iVar8;
  if (iVar8 == 0) {
    uVar11 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar8 = (*(code *)PTR_BIO_new_006a7fa4)(uVar11);
    *puVar13 = iVar8;
    if (iVar8 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar8,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
      iVar8 = *puVar13;
    }
  }
  iVar8 = load_config(iVar8,0);
  if (iVar8 == 0) {
    unaff_s6 = 0;
    goto LAB_0043ff78;
  }
  uVar11 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  unaff_s6 = (*(code *)PTR_BIO_new_006a7fa4)(uVar11);
  if (unaff_s6 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar13,"unable to create BIO for output\n");
    goto LAB_0043ff78;
  }
  iVar6 = iVar6 + -1;
  ppcVar14 = (char **)(pcVar10 + 4);
  if (0 < iVar6) {
    pcStack_90 = (char *)0x0;
    pcStack_98 = (char *)0x0;
    pcVar10 = (char *)0x0;
    pcStack_84 = (char *)0x0;
    uStack_8c = 0;
    uStack_a0 = 0x10001;
LAB_004400b0:
    pcVar16 = *ppcVar14;
    iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar16,&DAT_00632edc);
    if (iVar8 == 0) {
      unaff_s7 = iVar6 + -1;
      ppcVar9 = ppcVar14 + 1;
      if (unaff_s7 != 0) {
        pcVar10 = ppcVar14[1];
        goto LAB_004400a4;
      }
LAB_00440338:
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar13,"usage: genrsa [args] [numbits]\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar13," -des            encrypt the generated key with DES in cbc mode\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar13,
                 " -des3           encrypt the generated key with DES in ede cbc mode (168 bit key)\n"
                );
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar13," -idea           encrypt the generated key with IDEA in cbc mode\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar13," -seed\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar13,"                 encrypt PEM output with cbc seed\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar13," -aes128, -aes192, -aes256\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar13,"                 encrypt PEM output with cbc aes\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar13," -camellia128, -camellia192, -camellia256\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar13,"                 encrypt PEM output with cbc camellia\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar13," -out file       output the key to \'file\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar13," -passout arg    output file pass phrase source\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar13," -f4             use F4 (0x10001) for the E value\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar13," -3              use 3 for the E value\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar13," -engine e       use engine e, possibly a hardware device.\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar13," -rand file%cfile%c...\n",0x3a,0x3a);
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar13,"                 load the file (or the files in the directory) into\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar13,"                 the random number generator\n");
      goto LAB_0043ff78;
    }
    unaff_s7 = iVar6;
    if (*pcVar16 == '-') {
      cVar1 = pcVar16[1];
      ppcVar9 = ppcVar14;
      if (cVar1 == '3') {
        if (pcVar16[2] != '\0') goto LAB_004400e0;
        uStack_a0 = 3;
      }
      else {
        if ((((cVar1 != 'F') && (cVar1 != 'f')) || (pcVar16[2] != '4')) || (pcVar16[3] != '\0'))
        goto LAB_004400e0;
        uStack_a0 = 0x10001;
      }
LAB_004400a4:
      iVar6 = unaff_s7 + -1;
      ppcVar14 = ppcVar9;
    }
    else {
LAB_004400e0:
      iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar16,"-engine");
      if (iVar8 == 0) {
        unaff_s7 = iVar6 + -1;
        if (iVar6 + -1 == 0) goto LAB_00440338;
        pcStack_98 = ppcVar14[1];
        iVar6 = iVar6 + -2;
        ppcVar14 = ppcVar14 + 2;
        goto joined_r0x004400a8;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar16,"-rand");
      if (iVar8 == 0) {
        unaff_s7 = iVar6 + -1;
        if (unaff_s7 == 0) goto LAB_00440338;
        pcStack_90 = ppcVar14[1];
        ppcVar9 = ppcVar14 + 1;
        goto LAB_004400a4;
      }
      iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar16,&DAT_0063ad0c);
      if (iVar8 == 0) {
        iVar6 = iVar6 + -1;
        uStack_8c = (*(code *)PTR_EVP_des_cbc_006a83a4)();
      }
      else {
        iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar16,"-des3");
        if (iVar8 == 0) {
          iVar6 = iVar6 + -1;
          uStack_8c = (*(code *)PTR_EVP_des_ede3_cbc_006a7f48)();
        }
        else {
          iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar16,"-idea");
          if (iVar8 == 0) {
            iVar6 = iVar6 + -1;
            uStack_8c = (*(code *)PTR_EVP_idea_cbc_006a83a8)();
          }
          else {
            iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar16,"-seed");
            if (iVar8 == 0) {
              iVar6 = iVar6 + -1;
              uStack_8c = (*(code *)PTR_EVP_seed_cbc_006a83b8)();
            }
            else {
              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar16,"-aes128");
              if (iVar8 == 0) {
                iVar6 = iVar6 + -1;
                uStack_8c = (*(code *)PTR_EVP_aes_128_cbc_006a83b4)();
              }
              else {
                iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar16,"-aes192");
                if (iVar8 == 0) {
                  iVar6 = iVar6 + -1;
                  uStack_8c = (*(code *)PTR_EVP_aes_192_cbc_006a83b0)();
                }
                else {
                  iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar16,"-aes256");
                  if (iVar8 == 0) {
                    iVar6 = iVar6 + -1;
                    uStack_8c = (*(code *)PTR_EVP_aes_256_cbc_006a83ac)();
                  }
                  else {
                    iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar16,"-camellia128");
                    if (iVar8 == 0) {
                      iVar6 = iVar6 + -1;
                      uStack_8c = (*(code *)PTR_EVP_camellia_128_cbc_006a83c0)();
                    }
                    else {
                      iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar16,"-camellia192");
                      if (iVar8 != 0) {
                        iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar16,"-camellia256");
                        if (iVar8 == 0) {
                          iVar6 = iVar6 + -1;
                          uStack_8c = (*(code *)PTR_EVP_camellia_256_cbc_006a83c4)();
                          goto LAB_004400a8;
                        }
                        iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar16,"-passout");
                        if (iVar8 == 0) {
                          unaff_s7 = iVar6 + -1;
                          if (unaff_s7 != 0) {
                            pcStack_84 = ppcVar14[1];
                            ppcVar9 = ppcVar14 + 1;
                            goto LAB_004400a4;
                          }
                          goto LAB_00440338;
                        }
                        iVar8 = (*(code *)PTR___isoc99_sscanf_006aab10)(pcVar16,"%d",&iStack_78);
                        if ((iVar8 != 0) && (-1 < iStack_78)) goto LAB_00440118;
                        goto LAB_00440338;
                      }
                      iVar6 = iVar6 + -1;
                      uStack_8c = (*(code *)PTR_EVP_camellia_192_cbc_006a83bc)();
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_004400a8:
    ppcVar14 = ppcVar14 + 1;
joined_r0x004400a8:
    if (iVar6 == 0) goto LAB_00440118;
    goto LAB_004400b0;
  }
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  iVar8 = app_passwd(*puVar13,0,0,0,&iStack_74);
  if (iVar8 != 0) {
    uVar11 = setup_engine(*(undefined4 *)PTR_bio_err_006a7f3c,0,0);
    uStack_8c = 0;
    pcStack_90 = (char *)0x0;
    uStack_a0 = 0x10001;
    goto LAB_004408ac;
  }
LAB_0044063c:
  (*(code *)PTR_BIO_printf_006a7f38)(*puVar13,"Error getting password\n");
  unaff_s7 = iVar6;
LAB_0043ff78:
  bVar12 = true;
  (*(code *)PTR_BN_free_006a811c)(iVar3);
  if (unaff_s6 == 0) goto LAB_0043ffa0;
  while( true ) {
    (*(code *)PTR_BIO_free_all_006a7f74)(unaff_s6);
LAB_0043ffa0:
    param_3 = puVar13;
    unaff_s2 = iVar3;
    if (iStack_74 != 0) {
LAB_0043ffac:
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    puVar13 = param_3;
    iVar3 = unaff_s2;
    if (bVar12 != false) {
LAB_00440268:
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
      puVar13 = param_3;
      iVar3 = unaff_s2;
    }
    if (iStack_5c == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00440998:
    uVar11 = 0;
LAB_004406f0:
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar13,"e is %ld (0x%lX)\n",uVar11);
    iStack_70 = iStack_74;
    pcStack_6c = pcVar10;
    iVar6 = (*(code *)PTR_PEM_write_bio_RSAPrivateKey_006a8724)
                      (unaff_s6,unaff_s7,uStack_8c,0,0,PTR_password_callback_006a8828,&iStack_70);
    bVar12 = iVar6 == 0;
LAB_00440234:
    (*(code *)PTR_BN_free_006a811c)(iVar3);
    (*(code *)PTR_RSA_free_006a86f0)(unaff_s7);
  }
  return bVar12;
LAB_00440118:
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  iVar8 = app_passwd(*puVar13,0,pcStack_84,0,&iStack_74);
  if (iVar8 != 0) {
    uVar11 = setup_engine(*(undefined4 *)PTR_bio_err_006a7f3c,pcStack_98,0);
    if (pcVar10 == (char *)0x0) {
LAB_004408ac:
      pcVar10 = (char *)0x0;
      (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s6,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
    }
    else {
      iVar8 = (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s6,0x6c,5,pcVar10);
      if (iVar8 < 1) {
        (*(code *)PTR_perror_006aab88)(pcVar10);
        unaff_s7 = iVar6;
        goto LAB_0043ff78;
      }
    }
    iVar6 = (*(code *)PTR_app_RAND_load_file_006a7fcc)(0,*puVar13,1);
    if (iVar6 == 0) {
      if (pcStack_90 == (char *)0x0) {
        iVar6 = (*(code *)PTR_RAND_status_006a882c)();
        if (iVar6 == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)PTR_bio_err_006a7f3c,
                     "warning, not much extra random data, consider using the -rand option\n");
        }
      }
      else {
LAB_004401bc:
        uVar15 = *puVar13;
        uVar4 = (*(code *)PTR_app_RAND_load_files_006a8038)(pcStack_90);
        (*(code *)PTR_BIO_printf_006a7f38)(uVar15,"%ld semi-random bytes loaded\n",uVar4);
      }
    }
    else if (pcStack_90 != (char *)0x0) goto LAB_004401bc;
    (*(code *)PTR_BIO_printf_006a7f38)
              (*puVar13,"Generating RSA private key, %d bit long modulus\n",iStack_78);
    unaff_s7 = (*(code *)PTR_RSA_new_method_006a881c)(uVar11);
    if (unaff_s7 != 0) {
      iVar6 = (*(code *)PTR_BN_set_word_006a8820)(iVar3,uStack_a0);
      if ((iVar6 != 0) &&
         (iVar6 = (*(code *)PTR_RSA_generate_key_ex_006a8824)(unaff_s7,iStack_78,iVar3,&uStack_68),
         iVar6 != 0)) {
        (*(code *)PTR_app_RAND_write_file_006a804c)(0,*(undefined4 *)PTR_bio_err_006a7f3c);
        iVar6 = (*(int **)(unaff_s7 + 0x14))[1];
        if (iVar6 < 1) goto LAB_00440998;
        puVar5 = (undefined4 *)**(int **)(unaff_s7 + 0x14);
        puVar7 = puVar5 + iVar6;
        do {
          uVar11 = *puVar5;
          puVar5 = puVar5 + 1;
          if (puVar7 == puVar5) goto LAB_004406f0;
        } while( true );
      }
      bVar12 = true;
      goto LAB_00440234;
    }
    goto LAB_0043ff78;
  }
  goto LAB_0044063c;
}

