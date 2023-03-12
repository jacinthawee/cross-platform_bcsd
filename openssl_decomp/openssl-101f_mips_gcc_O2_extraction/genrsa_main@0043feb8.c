
bool genrsa_main(int param_1,char *param_2)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  char **ppcVar8;
  undefined4 uVar9;
  bool bVar10;
  undefined4 *unaff_s1;
  undefined4 *puVar11;
  int unaff_s2;
  char **ppcVar12;
  int unaff_s6;
  int unaff_s7;
  undefined4 uVar13;
  char *pcVar14;
  undefined4 local_70;
  char *local_68;
  char *local_60;
  undefined4 local_5c;
  char *local_54;
  int local_48;
  int local_44;
  int local_40;
  char *local_3c;
  undefined4 local_38;
  int local_34;
  code *local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_48 = 0x400;
  local_44 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = (*(code *)PTR_BN_new_006a82b4)();
  puVar11 = (undefined4 *)PTR_bio_err_006a7f3c;
  if (iVar3 == 0) {
    bVar10 = true;
    if (local_44 != 0) goto LAB_0043ffac;
    goto LAB_00440268;
  }
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar7 = *puVar11;
  local_38 = 2;
  local_30 = genrsa_cb;
  local_34 = iVar7;
  if (iVar7 == 0) {
    uVar9 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar7 = (*(code *)PTR_BIO_new_006a7fa4)(uVar9);
    *puVar11 = iVar7;
    if (iVar7 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar7,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
      iVar7 = *puVar11;
    }
  }
  iVar7 = load_config(iVar7,0);
  if (iVar7 == 0) {
    unaff_s6 = 0;
    goto LAB_0043ff78;
  }
  uVar9 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  unaff_s6 = (*(code *)PTR_BIO_new_006a7fa4)(uVar9);
  if (unaff_s6 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar11,"unable to create BIO for output\n");
    goto LAB_0043ff78;
  }
  param_1 = param_1 + -1;
  ppcVar12 = (char **)(param_2 + 4);
  if (0 < param_1) {
    local_60 = (char *)0x0;
    local_68 = (char *)0x0;
    param_2 = (char *)0x0;
    local_54 = (char *)0x0;
    local_5c = 0;
    local_70 = 0x10001;
LAB_004400b0:
    pcVar14 = *ppcVar12;
    iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar14,&DAT_00632edc);
    if (iVar7 == 0) {
      unaff_s7 = param_1 + -1;
      ppcVar8 = ppcVar12 + 1;
      if (unaff_s7 != 0) {
        param_2 = ppcVar12[1];
        goto LAB_004400a4;
      }
LAB_00440338:
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar11,"usage: genrsa [args] [numbits]\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar11," -des            encrypt the generated key with DES in cbc mode\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar11,
                 " -des3           encrypt the generated key with DES in ede cbc mode (168 bit key)\n"
                );
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar11," -idea           encrypt the generated key with IDEA in cbc mode\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar11," -seed\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar11,"                 encrypt PEM output with cbc seed\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar11," -aes128, -aes192, -aes256\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar11,"                 encrypt PEM output with cbc aes\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar11," -camellia128, -camellia192, -camellia256\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar11,"                 encrypt PEM output with cbc camellia\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar11," -out file       output the key to \'file\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar11," -passout arg    output file pass phrase source\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar11," -f4             use F4 (0x10001) for the E value\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar11," -3              use 3 for the E value\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar11," -engine e       use engine e, possibly a hardware device.\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar11," -rand file%cfile%c...\n",0x3a,0x3a);
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar11,"                 load the file (or the files in the directory) into\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar11,"                 the random number generator\n");
      goto LAB_0043ff78;
    }
    unaff_s7 = param_1;
    if (*pcVar14 == '-') {
      cVar1 = pcVar14[1];
      ppcVar8 = ppcVar12;
      if (cVar1 == '3') {
        if (pcVar14[2] != '\0') goto LAB_004400e0;
        local_70 = 3;
      }
      else {
        if ((((cVar1 != 'F') && (cVar1 != 'f')) || (pcVar14[2] != '4')) || (pcVar14[3] != '\0'))
        goto LAB_004400e0;
        local_70 = 0x10001;
      }
LAB_004400a4:
      param_1 = unaff_s7 + -1;
      ppcVar12 = ppcVar8;
    }
    else {
LAB_004400e0:
      iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-engine");
      if (iVar7 == 0) {
        unaff_s7 = param_1 + -1;
        if (param_1 + -1 == 0) goto LAB_00440338;
        local_68 = ppcVar12[1];
        param_1 = param_1 + -2;
        ppcVar12 = ppcVar12 + 2;
        goto joined_r0x004400a8;
      }
      iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-rand");
      if (iVar7 == 0) {
        unaff_s7 = param_1 + -1;
        if (unaff_s7 == 0) goto LAB_00440338;
        local_60 = ppcVar12[1];
        ppcVar8 = ppcVar12 + 1;
        goto LAB_004400a4;
      }
      iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar14,&DAT_0063ad0c);
      if (iVar7 == 0) {
        param_1 = param_1 + -1;
        local_5c = (*(code *)PTR_EVP_des_cbc_006a83a4)();
      }
      else {
        iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-des3");
        if (iVar7 == 0) {
          param_1 = param_1 + -1;
          local_5c = (*(code *)PTR_EVP_des_ede3_cbc_006a7f48)();
        }
        else {
          iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-idea");
          if (iVar7 == 0) {
            param_1 = param_1 + -1;
            local_5c = (*(code *)PTR_EVP_idea_cbc_006a83a8)();
          }
          else {
            iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-seed");
            if (iVar7 == 0) {
              param_1 = param_1 + -1;
              local_5c = (*(code *)PTR_EVP_seed_cbc_006a83b8)();
            }
            else {
              iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-aes128");
              if (iVar7 == 0) {
                param_1 = param_1 + -1;
                local_5c = (*(code *)PTR_EVP_aes_128_cbc_006a83b4)();
              }
              else {
                iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-aes192");
                if (iVar7 == 0) {
                  param_1 = param_1 + -1;
                  local_5c = (*(code *)PTR_EVP_aes_192_cbc_006a83b0)();
                }
                else {
                  iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-aes256");
                  if (iVar7 == 0) {
                    param_1 = param_1 + -1;
                    local_5c = (*(code *)PTR_EVP_aes_256_cbc_006a83ac)();
                  }
                  else {
                    iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-camellia128");
                    if (iVar7 == 0) {
                      param_1 = param_1 + -1;
                      local_5c = (*(code *)PTR_EVP_camellia_128_cbc_006a83c0)();
                    }
                    else {
                      iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-camellia192");
                      if (iVar7 != 0) {
                        iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-camellia256");
                        if (iVar7 == 0) {
                          param_1 = param_1 + -1;
                          local_5c = (*(code *)PTR_EVP_camellia_256_cbc_006a83c4)();
                          goto LAB_004400a8;
                        }
                        iVar7 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-passout");
                        if (iVar7 == 0) {
                          unaff_s7 = param_1 + -1;
                          if (unaff_s7 != 0) {
                            local_54 = ppcVar12[1];
                            ppcVar8 = ppcVar12 + 1;
                            goto LAB_004400a4;
                          }
                          goto LAB_00440338;
                        }
                        iVar7 = (*(code *)PTR___isoc99_sscanf_006aab10)(pcVar14,"%d",&local_48);
                        if ((iVar7 != 0) && (-1 < local_48)) goto LAB_00440118;
                        goto LAB_00440338;
                      }
                      param_1 = param_1 + -1;
                      local_5c = (*(code *)PTR_EVP_camellia_192_cbc_006a83bc)();
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
    ppcVar12 = ppcVar12 + 1;
joined_r0x004400a8:
    if (param_1 == 0) goto LAB_00440118;
    goto LAB_004400b0;
  }
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  iVar7 = app_passwd(*puVar11,0,0,0,&local_44);
  if (iVar7 != 0) {
    uVar9 = setup_engine(*(undefined4 *)PTR_bio_err_006a7f3c,0,0);
    local_5c = 0;
    local_60 = (char *)0x0;
    local_70 = 0x10001;
    goto LAB_004408ac;
  }
LAB_0044063c:
  (*(code *)PTR_BIO_printf_006a7f38)(*puVar11,"Error getting password\n");
  unaff_s7 = param_1;
LAB_0043ff78:
  bVar10 = true;
  (*(code *)PTR_BN_free_006a811c)(iVar3);
  if (unaff_s6 == 0) goto LAB_0043ffa0;
  while( true ) {
    (*(code *)PTR_BIO_free_all_006a7f74)(unaff_s6);
LAB_0043ffa0:
    unaff_s1 = puVar11;
    unaff_s2 = iVar3;
    if (local_44 != 0) {
LAB_0043ffac:
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    puVar11 = unaff_s1;
    iVar3 = unaff_s2;
    if (bVar10 != false) {
LAB_00440268:
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
      puVar11 = unaff_s1;
      iVar3 = unaff_s2;
    }
    if (local_2c == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00440998:
    uVar9 = 0;
LAB_004406f0:
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar11,"e is %ld (0x%lX)\n",uVar9);
    local_40 = local_44;
    local_3c = param_2;
    iVar7 = (*(code *)PTR_PEM_write_bio_RSAPrivateKey_006a8724)
                      (unaff_s6,unaff_s7,local_5c,0,0,PTR_password_callback_006a8828,&local_40);
    bVar10 = iVar7 == 0;
LAB_00440234:
    (*(code *)PTR_BN_free_006a811c)(iVar3);
    (*(code *)PTR_RSA_free_006a86f0)(unaff_s7);
  }
  return bVar10;
LAB_00440118:
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  iVar7 = app_passwd(*puVar11,0,local_54,0,&local_44);
  if (iVar7 != 0) {
    uVar9 = setup_engine(*(undefined4 *)PTR_bio_err_006a7f3c,local_68,0);
    if (param_2 == (char *)0x0) {
LAB_004408ac:
      param_2 = (char *)0x0;
      (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s6,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
    }
    else {
      iVar7 = (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s6,0x6c,5,param_2);
      if (iVar7 < 1) {
        (*(code *)PTR_perror_006aab88)(param_2);
        unaff_s7 = param_1;
        goto LAB_0043ff78;
      }
    }
    iVar7 = (*(code *)PTR_app_RAND_load_file_006a7fcc)(0,*puVar11,1);
    if (iVar7 == 0) {
      if (local_60 == (char *)0x0) {
        iVar7 = (*(code *)PTR_RAND_status_006a882c)();
        if (iVar7 == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)PTR_bio_err_006a7f3c,
                     "warning, not much extra random data, consider using the -rand option\n");
        }
      }
      else {
LAB_004401bc:
        uVar13 = *puVar11;
        uVar4 = (*(code *)PTR_app_RAND_load_files_006a8038)(local_60);
        (*(code *)PTR_BIO_printf_006a7f38)(uVar13,"%ld semi-random bytes loaded\n",uVar4);
      }
    }
    else if (local_60 != (char *)0x0) goto LAB_004401bc;
    (*(code *)PTR_BIO_printf_006a7f38)
              (*puVar11,"Generating RSA private key, %d bit long modulus\n",local_48);
    unaff_s7 = (*(code *)PTR_RSA_new_method_006a881c)(uVar9);
    if (unaff_s7 != 0) {
      iVar7 = (*(code *)PTR_BN_set_word_006a8820)(iVar3,local_70);
      if ((iVar7 != 0) &&
         (iVar7 = (*(code *)PTR_RSA_generate_key_ex_006a8824)(unaff_s7,local_48,iVar3,&local_38),
         iVar7 != 0)) {
        (*(code *)PTR_app_RAND_write_file_006a804c)(0,*(undefined4 *)PTR_bio_err_006a7f3c);
        iVar7 = (*(int **)(unaff_s7 + 0x14))[1];
        if (iVar7 < 1) goto LAB_00440998;
        puVar5 = (undefined4 *)**(int **)(unaff_s7 + 0x14);
        puVar6 = puVar5 + iVar7;
        do {
          uVar9 = *puVar5;
          puVar5 = puVar5 + 1;
          if (puVar6 == puVar5) goto LAB_004406f0;
        } while( true );
      }
      bVar10 = true;
      goto LAB_00440234;
    }
    goto LAB_0043ff78;
  }
  goto LAB_0044063c;
}

