
undefined4 * pkeyutl_main(int param_1,char *param_2)

{
  undefined uVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  int iVar7;
  char *pcVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 *puVar11;
  int unaff_s4;
  char *unaff_s5;
  char *pcVar12;
  char **unaff_s6;
  int unaff_s7;
  code *pcVar13;
  char **ppcVar14;
  uint uVar15;
  char *local_7c;
  char *local_78;
  int local_74;
  undefined4 local_70;
  int local_6c;
  char *local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  char *local_58;
  int local_54;
  int local_50;
  char *local_4c;
  char *local_48;
  int local_38;
  int local_34;
  char *local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  puVar11 = (undefined4 *)PTR_bio_err_006a7f3c;
  local_38 = 0;
  local_34 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar7 = *(int *)PTR_bio_err_006a7f3c;
  if (iVar7 == 0) {
    iVar7 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *puVar11 = iVar7;
  }
  iVar7 = load_config(iVar7,0);
  if (iVar7 != 0) {
    iVar7 = param_1 + -1;
    (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
    (*(code *)PTR_OPENSSL_add_all_algorithms_noconf_006a84fc)();
    unaff_s7 = iVar7;
    if (iVar7 < 1) goto LAB_00468750;
    local_68 = (char *)0x0;
    unaff_s6 = (char **)(param_2 + 4);
    local_50 = 0;
    unaff_s4 = 0;
    bVar2 = false;
    local_64 = -1;
    local_54 = 0;
    unaff_s5 = (char *)0x0;
    local_70 = 0;
    param_2 = (char *)0x0;
    local_5c = 3;
    param_1 = 0x630000;
    local_60 = 3;
    local_78 = (char *)0x0;
    local_6c = 1;
    local_74 = 8;
    local_7c = "s\n";
    local_58 = "Peer Key";
    local_4c = "Private Key";
    local_48 = "Public Key";
    goto LAB_00467cd8;
  }
LAB_00467b3c:
  (*(code *)PTR_BIO_free_006a7f70)(0);
  pcVar8 = (char *)0x0;
  pcVar12 = unaff_s5;
LAB_00467b50:
  puVar11 = (undefined4 *)0x1;
  (*(code *)PTR_BIO_free_all_006a7f74)(pcVar8);
  if (local_38 == 0) goto LAB_00467b90;
  pcVar12 = (char *)0x0;
  pcVar8 = param_2;
  do {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    param_2 = pcVar8;
    do {
      if (pcVar12 != (char *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar12);
      }
LAB_00467b90:
      if (local_34 != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      if (local_2c == *(int *)puVar3) {
        return puVar11;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      unaff_s5 = pcVar12;
      iVar7 = unaff_s7;
LAB_00468ab0:
      bVar2 = true;
      ppcVar14 = unaff_s6;
      unaff_s7 = iVar7;
LAB_00467cd0:
      iVar7 = unaff_s7 + -1;
      unaff_s6 = ppcVar14 + 1;
      unaff_s7 = iVar7;
      if (0 < iVar7) goto LAB_00467cd8;
LAB_00467d24:
      if (unaff_s4 == 0) goto LAB_00468750;
      if (local_78 == (char *)0x0) {
        if (local_74 == 0x10) {
          uVar9 = *puVar11;
          pcVar8 = "No signature file specified for verify\n";
          goto LAB_00467d4c;
        }
        param_1 = 0;
        app_RAND_load_file(0,*puVar11,0);
        if (local_74 != 0x400) {
          if (param_2 == (char *)0x0) goto LAB_00468420;
          goto LAB_004681b0;
        }
      }
      else {
        if (local_74 != 0x10) {
          uVar9 = *puVar11;
          pcVar8 = "Signature file specified for non verify\n";
LAB_00467d4c:
          (*(code *)PTR_BIO_puts_006a8058)(uVar9,pcVar8);
          goto LAB_00467d58;
        }
        app_RAND_load_file(0,*puVar11,0);
        if (param_2 != (char *)0x0) {
LAB_004681b0:
          param_1 = (*(code *)PTR_BIO_new_file_006a7fac)(param_2,&DAT_006347ac);
          if (param_1 != 0) goto LAB_004681d0;
          pcVar12 = (char *)0x0;
          pcVar8 = (char *)0x0;
          (*(code *)PTR_BIO_puts_006a8058)(*puVar11,"Error Opening Input File\n");
          uVar9 = *puVar11;
          puVar11 = (undefined4 *)0x1;
          (*(code *)PTR_ERR_print_errors_006a7f40)(uVar9);
          goto LAB_00467d68;
        }
LAB_00468420:
        param_1 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdin_006aab20,0);
      }
LAB_004681d0:
      if (unaff_s5 == (char *)0x0) {
        pcVar8 = (char *)(*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
      }
      else {
        pcVar8 = (char *)(*(code *)PTR_BIO_new_file_006a7fac)(unaff_s5,&DAT_00632de8);
        if (pcVar8 == (char *)0x0) {
          pcVar12 = (char *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar11,"Error Creating Output File\n");
          uVar9 = *puVar11;
          puVar11 = (undefined4 *)0x1;
          (*(code *)PTR_ERR_print_errors_006a7f40)(uVar9);
          goto LAB_00467d68;
        }
      }
      if (local_78 == (char *)0x0) {
        unaff_s5 = (char *)0xffffffff;
      }
      else {
        pcVar12 = (char *)(*(code *)PTR_BIO_new_file_006a7fac)(local_78,&DAT_006347ac);
        if (pcVar12 == (char *)0x0) {
          uVar9 = *puVar11;
          puVar11 = (undefined4 *)0x1;
          (*(code *)PTR_BIO_printf_006a7f38)(uVar9,"Can\'t open signature file %s\n",local_78);
          goto LAB_00467d68;
        }
        unaff_s5 = (char *)bio_to_mem(&local_34,local_64 * 10,pcVar12);
        (*(code *)PTR_BIO_free_006a7f70)(pcVar12);
        if ((int)unaff_s5 < 1) {
          uVar9 = *puVar11;
          pcVar12 = (char *)0x0;
          puVar11 = (undefined4 *)0x1;
          (*(code *)PTR_BIO_printf_006a7f38)(uVar9,"Error reading signature data\n");
          goto LAB_00467d68;
        }
      }
      if (param_1 == 0) {
        uVar15 = 0;
      }
      else {
        uVar5 = bio_to_mem(&local_38,local_64 * 10,param_1);
        if ((int)uVar5 < 1) {
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar11,"Error reading input Data\n");
          puVar11 = (undefined4 *)(*(code *)PTR_exit_006aab4c)(1);
          return puVar11;
        }
        uVar15 = uVar5;
        if (local_54 != 0) {
          uVar15 = 1;
          if (uVar5 >> 1 != 0) {
            uVar10 = 0;
            do {
              iVar7 = (uVar5 - 1) - uVar10;
              puVar6 = (undefined *)(local_38 + uVar10);
              uVar10 = uVar10 + 1;
              uVar1 = *puVar6;
              *puVar6 = *(undefined *)(local_38 + iVar7);
              *(undefined *)(local_38 + iVar7) = uVar1;
              uVar15 = uVar5;
            } while (uVar5 >> 1 != uVar10);
          }
        }
      }
      if (local_74 == 0x10) {
        iVar7 = (*(code *)PTR_EVP_PKEY_verify_006a8df8)(unaff_s4,local_34,unaff_s5,local_38,uVar15);
        if (iVar7 == 0) {
          (*(code *)PTR_BIO_puts_006a8058)(pcVar8,"Signature Verification Failure\n");
LAB_00468024:
          (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(unaff_s4);
          (*(code *)PTR_BIO_free_006a7f70)(param_1);
          param_2 = pcVar8;
          pcVar12 = unaff_s5;
          goto LAB_00467b50;
        }
        if (iVar7 == 1) {
          puVar11 = (undefined4 *)0x1;
          (*(code *)PTR_BIO_puts_006a8058)(pcVar8,"Signature Verified Successfully\n");
          pcVar12 = (char *)0x0;
        }
        else {
          if (iVar7 < 0) goto LAB_00468554;
          puVar11 = (undefined4 *)0x1;
          pcVar12 = (char *)0x0;
        }
      }
      else {
        pcVar13 = (code *)PTR_EVP_PKEY_encrypt_006a8e04;
        if (local_74 == 0x100) {
LAB_0046830c:
          iVar7 = (*pcVar13)(unaff_s4,0,&local_30,local_38,uVar15);
LAB_00468328:
          unaff_s6 = &local_30;
          if ((iVar7 < 1) ||
             (pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(local_30,"pkeyutl.c",0x15b),
             pcVar12 == (char *)0x0)) goto LAB_00468554;
          pcVar13 = (code *)PTR_EVP_PKEY_encrypt_006a8e04;
          if (local_74 == 0x100) {
LAB_0046837c:
            iVar7 = (*pcVar13)(unaff_s4,pcVar12,unaff_s6,local_38,uVar15);
LAB_00468394:
            if (0 < iVar7) {
              if (local_50 == 0) {
                pcVar13 = (code *)PTR_BIO_write_006a7f14;
                if (bVar2) {
                  pcVar13 = (code *)PTR_BIO_dump_006a8738;
                }
                puVar11 = (undefined4 *)0x0;
                (*pcVar13)(pcVar8,pcVar12,local_30);
              }
              else {
                iVar7 = (*(code *)PTR_ASN1_parse_dump_006a85b4)
                                  (pcVar8,pcVar12,local_30,1,0xffffffff);
                if (iVar7 == 0) {
                  uVar9 = *puVar11;
                  puVar11 = (undefined4 *)0x0;
                  (*(code *)PTR_ERR_print_errors_006a7f40)(uVar9);
                }
                else {
                  puVar11 = (undefined4 *)0x0;
                }
              }
              goto LAB_00467d68;
            }
          }
          else {
            if (0x100 < local_74) {
              pcVar13 = (code *)PTR_EVP_PKEY_decrypt_006a8dfc;
              if (local_74 == 0x200) goto LAB_0046837c;
              if (local_74 != 0x400) goto LAB_00468558;
              iVar7 = (*(code *)PTR_EVP_PKEY_derive_006a8df4)(unaff_s4,pcVar12,unaff_s6,local_38);
              goto LAB_00468394;
            }
            pcVar13 = (code *)PTR_EVP_PKEY_sign_006a8e00;
            if ((local_74 == 8) ||
               (pcVar13 = (code *)PTR_EVP_PKEY_verify_recover_006a8de8, local_74 == 0x20))
            goto LAB_0046837c;
          }
        }
        else {
          if (0x100 < local_74) {
            pcVar13 = (code *)PTR_EVP_PKEY_decrypt_006a8dfc;
            if (local_74 == 0x200) goto LAB_0046830c;
            if (local_74 != 0x400) goto LAB_00468554;
            iVar7 = (*(code *)PTR_EVP_PKEY_derive_006a8df4)(unaff_s4,0,&local_30,local_38);
            goto LAB_00468328;
          }
          pcVar13 = (code *)PTR_EVP_PKEY_sign_006a8e00;
          if ((local_74 == 8) ||
             (pcVar13 = (code *)PTR_EVP_PKEY_verify_recover_006a8de8, local_74 == 0x20))
          goto LAB_0046830c;
LAB_00468554:
          pcVar12 = (char *)0x0;
        }
LAB_00468558:
        (*(code *)PTR_BIO_printf_006a7f38)(*puVar11,"Public Key operation error\n");
        uVar9 = *puVar11;
        puVar11 = (undefined4 *)0x1;
        (*(code *)PTR_ERR_print_errors_006a7f40)(uVar9);
      }
LAB_00467d68:
      (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(unaff_s4);
      (*(code *)PTR_BIO_free_006a7f70)(param_1);
      (*(code *)PTR_BIO_free_all_006a7f74)(pcVar8);
      param_2 = pcVar8;
    } while (local_38 == 0);
  } while( true );
LAB_00467cd8:
  while( true ) {
    pcVar8 = *unaff_s6;
    if ((((*pcVar8 == '-') && (pcVar8[1] == 'i')) && (pcVar8[2] == 'n')) && (pcVar8[3] == '\0')) {
      unaff_s7 = iVar7 + -1;
      if (unaff_s7 == 0) goto LAB_0046800c;
      param_2 = unaff_s6[1];
      ppcVar14 = unaff_s6 + 1;
      goto LAB_00467cd0;
    }
    iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,param_1 + 0x2edc);
    if (iVar4 != 0) break;
    unaff_s7 = iVar7 + -1;
    if (iVar7 + -1 == 0) goto LAB_0046800c;
    unaff_s5 = unaff_s6[1];
    iVar7 = iVar7 + -2;
    unaff_s6 = unaff_s6 + 2;
    unaff_s7 = iVar7;
    if (iVar7 < 1) goto LAB_00467d24;
  }
  iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,local_7c + 0x2d14);
  if (iVar4 == 0) {
    unaff_s7 = iVar7 + -1;
    if (unaff_s7 != 0) {
      local_78 = unaff_s6[1];
      ppcVar14 = unaff_s6 + 1;
      goto LAB_00467cd0;
    }
    goto LAB_0046800c;
  }
  iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-inkey");
  if (iVar4 != 0) {
    iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-peerkey");
    if (iVar4 == 0) {
      unaff_s7 = iVar7 + -1;
      if (unaff_s7 != 0) {
        uVar9 = *puVar11;
        ppcVar14 = unaff_s6 + 1;
        unaff_s6 = (char **)unaff_s6[1];
        if (unaff_s4 == 0) {
          (*(code *)PTR_BIO_puts_006a8058)(uVar9,"-peerkey command before -inkey\n");
        }
        else {
          iVar7 = load_pubkey(uVar9,unaff_s6,local_5c,0,0,0,local_58);
          if (iVar7 == 0) {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)PTR_bio_err_006a7f3c,"Error reading peer key %s\n",unaff_s6);
            (*(code *)PTR_ERR_print_errors_006a7f40)(uVar9);
          }
          else {
            unaff_s6 = (char **)(*(code *)PTR_EVP_PKEY_derive_set_peer_006a8de0)(unaff_s4,iVar7);
            (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar7);
            if ((0 < (int)unaff_s6) ||
               ((*(code *)PTR_ERR_print_errors_006a7f40)(uVar9), unaff_s6 != (char **)0x0))
            goto LAB_00467cd0;
          }
        }
      }
    }
    else {
      iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-passin");
      if (iVar4 == 0) {
        unaff_s7 = iVar7 + -1;
        if (unaff_s7 != 0) {
          local_68 = unaff_s6[1];
          ppcVar14 = unaff_s6 + 1;
          goto LAB_00467cd0;
        }
      }
      else {
        iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-peerform");
        if (iVar4 == 0) {
          unaff_s7 = iVar7 + -1;
          if (unaff_s7 != 0) {
            ppcVar14 = unaff_s6 + 1;
            local_5c = str2fmt(unaff_s6[1]);
            goto LAB_00467cd0;
          }
        }
        else {
          iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-keyform");
          if (iVar4 == 0) {
            unaff_s7 = iVar7 + -1;
            if (unaff_s7 != 0) {
              local_60 = str2fmt(unaff_s6[1]);
              ppcVar14 = unaff_s6 + 1;
              goto LAB_00467cd0;
            }
          }
          else {
            iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-engine");
            if (iVar4 == 0) {
              unaff_s7 = iVar7 + -1;
              if (unaff_s7 != 0) {
                local_70 = setup_engine(*puVar11,unaff_s6[1],0);
                ppcVar14 = unaff_s6 + 1;
                goto LAB_00467cd0;
              }
            }
            else {
              iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-pubin");
              ppcVar14 = unaff_s6;
              if (iVar4 == 0) {
                local_6c = 2;
                unaff_s7 = iVar7;
                goto LAB_00467cd0;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-certin");
              if (iVar4 == 0) {
                local_6c = 3;
                unaff_s7 = iVar7;
                goto LAB_00467cd0;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-asn1parse");
              if (iVar4 == 0) {
                local_50 = 1;
                unaff_s7 = iVar7;
                goto LAB_00467cd0;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-hexdump");
              if (iVar4 == 0) goto LAB_00468ab0;
              iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-sign");
              if (iVar4 == 0) {
                local_74 = 8;
                unaff_s7 = iVar7;
                goto LAB_00467cd0;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-verify");
              if (iVar4 == 0) {
                local_74 = 0x10;
                unaff_s7 = iVar7;
                goto LAB_00467cd0;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-verifyrecover");
              if (iVar4 == 0) {
                local_74 = 0x20;
                unaff_s7 = iVar7;
                goto LAB_00467cd0;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,&DAT_00638378);
              if (iVar4 == 0) {
                local_54 = 1;
                unaff_s7 = iVar7;
                goto LAB_00467cd0;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-encrypt");
              if (iVar4 == 0) {
                local_74 = 0x100;
                unaff_s7 = iVar7;
                goto LAB_00467cd0;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-decrypt");
              if (iVar4 == 0) {
                local_74 = 0x200;
                unaff_s7 = iVar7;
                goto LAB_00467cd0;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-derive");
              if (iVar4 == 0) {
                local_74 = 0x400;
                unaff_s7 = iVar7;
                goto LAB_00467cd0;
              }
              iVar4 = (*(code *)PTR_strcmp_006aac20)(pcVar8,"-pkeyopt");
              unaff_s7 = iVar7;
              if ((iVar4 == 0) && (unaff_s7 = iVar7 + -1, unaff_s7 != 0)) {
                if (unaff_s4 != 0) {
                  iVar7 = pkey_ctrl_string(unaff_s4,unaff_s6[1]);
                  ppcVar14 = unaff_s6 + 1;
                  if (iVar7 < 1) {
                    (*(code *)PTR_BIO_puts_006a8058)(*puVar11,"parameter setting error\n");
                    (*(code *)PTR_ERR_print_errors_006a7f40)(*puVar11);
LAB_00467d58:
                    puVar11 = (undefined4 *)0x1;
                    pcVar12 = (char *)0x0;
                    pcVar8 = (char *)0x0;
                    param_1 = 0;
                    goto LAB_00467d68;
                  }
                  goto LAB_00467cd0;
                }
                (*(code *)PTR_BIO_puts_006a8058)(*puVar11,"-pkeyopt command before -inkey\n");
              }
            }
          }
        }
      }
    }
    goto LAB_0046800c;
  }
  unaff_s7 = iVar7 + -1;
  if (unaff_s7 == 0) goto LAB_0046800c;
  pcVar8 = unaff_s6[1];
  local_30 = (char *)0x0;
  if (((local_74 == 8) || (local_74 == 0x200)) || (local_74 == 0x400)) {
    if (local_6c != 1) {
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar11,"A private key is needed for this operation\n");
      goto joined_r0x004680d0;
    }
    iVar7 = app_passwd(*puVar11,local_68,0,&local_30,0);
    if (iVar7 != 0) {
LAB_004684e0:
      iVar7 = load_key(*puVar11,pcVar8,local_60,0,local_30,local_70,local_4c);
      goto LAB_00467ec4;
    }
LAB_004680b4:
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar11,"Error getting password\n");
  }
  else {
    iVar7 = app_passwd(*puVar11,local_68,0,&local_30,0);
    if (iVar7 == 0) goto LAB_004680b4;
    if (local_6c == 2) {
      iVar7 = load_pubkey(*(undefined4 *)PTR_bio_err_006a7f3c,pcVar8,local_60,0,0,local_70,local_48)
      ;
LAB_00467ec4:
      local_64 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(iVar7);
      if (iVar7 != 0) {
        unaff_s4 = (*(code *)PTR_EVP_PKEY_CTX_new_006a80e0)(iVar7,local_70);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar7);
        if (unaff_s4 != 0) {
          if (local_74 == 0x20) {
            iVar7 = (*(code *)PTR_EVP_PKEY_verify_recover_init_006a8dd0)(unaff_s4);
LAB_004684b8:
            if (0 < iVar7) {
              ppcVar14 = unaff_s6 + 1;
              if (local_30 != (char *)0x0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
              }
              goto LAB_00467cd0;
            }
          }
          else {
            if (0x20 < local_74) {
              if (local_74 == 0x200) {
                iVar7 = (*(code *)PTR_EVP_PKEY_decrypt_init_006a8dd4)(unaff_s4);
              }
              else if (local_74 == 0x400) {
                iVar7 = (*(code *)PTR_EVP_PKEY_derive_init_006a8dd8)(unaff_s4);
              }
              else {
                if (local_74 != 0x100) goto LAB_00467f44;
                iVar7 = (*(code *)PTR_EVP_PKEY_encrypt_init_006a8ddc)(unaff_s4);
              }
              goto LAB_004684b8;
            }
            if (local_74 == 8) {
              iVar7 = (*(code *)PTR_EVP_PKEY_sign_init_006a8dec)(unaff_s4);
              goto LAB_004684b8;
            }
            if (local_74 == 0x10) {
              iVar7 = (*(code *)PTR_EVP_PKEY_verify_init_006a8df0)(unaff_s4);
              goto LAB_004684b8;
            }
          }
LAB_00467f44:
          (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(unaff_s4);
        }
      }
    }
    else {
      if (local_6c == 3) {
        iVar4 = load_cert(*puVar11,pcVar8,local_60,0,local_70,"Certificate");
        if (iVar4 != 0) {
          iVar7 = (*(code *)PTR_X509_get_pubkey_006a8008)(iVar4);
          (*(code *)PTR_X509_free_006a7f90)(iVar4);
          goto LAB_00467ec4;
        }
      }
      else if (local_6c == 1) goto LAB_004684e0;
      (*(code *)PTR_EVP_PKEY_size_006a85f4)(0);
    }
  }
joined_r0x004680d0:
  if (local_30 != (char *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  unaff_s4 = 0;
  (*(code *)PTR_BIO_puts_006a8058)(*puVar11,"Error initializing context\n");
  (*(code *)PTR_ERR_print_errors_006a7f40)(*puVar11);
LAB_0046800c:
  usage();
  if (unaff_s4 == 0) goto LAB_00467b3c;
  pcVar8 = (char *)0x0;
  param_1 = 0;
  goto LAB_00468024;
LAB_00468750:
  usage();
  goto LAB_00467b3c;
}

