
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
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  puVar11 = (undefined4 *)PTR_bio_err_006a6e3c;
  local_38 = 0;
  local_34 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar7 = *(int *)PTR_bio_err_006a6e3c;
  if (iVar7 == 0) {
    iVar7 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *puVar11 = iVar7;
  }
  iVar7 = load_config(iVar7,0);
  if (iVar7 != 0) {
    iVar7 = param_1 + -1;
    (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
    (*(code *)PTR_OPENSSL_add_all_algorithms_noconf_006a73fc)();
    unaff_s7 = iVar7;
    if (iVar7 < 1) goto LAB_00469160;
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
    local_7c = "-check_ss_sig";
    local_58 = "Peer Key";
    local_4c = "Private Key";
    local_48 = "Public Key";
    goto LAB_004686e8;
  }
LAB_0046854c:
  (*(code *)PTR_BIO_free_006a6e70)(0);
  pcVar8 = (char *)0x0;
  pcVar12 = unaff_s5;
LAB_00468560:
  puVar11 = (undefined4 *)0x1;
  (*(code *)PTR_BIO_free_all_006a6e74)(pcVar8);
  if (local_38 == 0) goto LAB_004685a0;
  pcVar12 = (char *)0x0;
  pcVar8 = param_2;
  do {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    param_2 = pcVar8;
    do {
      if (pcVar12 != (char *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar12);
      }
LAB_004685a0:
      if (local_34 != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      if (local_2c == *(int *)puVar3) {
        return puVar11;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
      unaff_s5 = pcVar12;
      iVar7 = unaff_s7;
LAB_004694c0:
      bVar2 = true;
      ppcVar14 = unaff_s6;
      unaff_s7 = iVar7;
LAB_004686e0:
      iVar7 = unaff_s7 + -1;
      unaff_s6 = ppcVar14 + 1;
      unaff_s7 = iVar7;
      if (0 < iVar7) goto LAB_004686e8;
LAB_00468734:
      if (unaff_s4 == 0) goto LAB_00469160;
      if (local_78 == (char *)0x0) {
        if (local_74 == 0x10) {
          uVar9 = *puVar11;
          pcVar8 = "No signature file specified for verify\n";
          goto LAB_0046875c;
        }
        param_1 = 0;
        app_RAND_load_file(0,*puVar11,0);
        if (local_74 != 0x400) {
          if (param_2 == (char *)0x0) goto LAB_00468e30;
          goto LAB_00468bc0;
        }
      }
      else {
        if (local_74 != 0x10) {
          uVar9 = *puVar11;
          pcVar8 = "Signature file specified for non verify\n";
LAB_0046875c:
          (*(code *)PTR_BIO_puts_006a6f58)(uVar9,pcVar8);
          goto LAB_00468768;
        }
        app_RAND_load_file(0,*puVar11,0);
        if (param_2 != (char *)0x0) {
LAB_00468bc0:
          param_1 = (*(code *)PTR_BIO_new_file_006a6eac)(param_2,&DAT_00633e40);
          if (param_1 != 0) goto LAB_00468be0;
          pcVar12 = (char *)0x0;
          pcVar8 = (char *)0x0;
          (*(code *)PTR_BIO_puts_006a6f58)(*puVar11,"Error Opening Input File\n");
          uVar9 = *puVar11;
          puVar11 = (undefined4 *)0x1;
          (*(code *)PTR_ERR_print_errors_006a6e40)(uVar9);
          goto LAB_00468778;
        }
LAB_00468e30:
        param_1 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14,0);
      }
LAB_00468be0:
      if (unaff_s5 == (char *)0x0) {
        pcVar8 = (char *)(*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
      }
      else {
        pcVar8 = (char *)(*(code *)PTR_BIO_new_file_006a6eac)(unaff_s5,&DAT_00632420);
        if (pcVar8 == (char *)0x0) {
          pcVar12 = (char *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar11,"Error Creating Output File\n");
          uVar9 = *puVar11;
          puVar11 = (undefined4 *)0x1;
          (*(code *)PTR_ERR_print_errors_006a6e40)(uVar9);
          goto LAB_00468778;
        }
      }
      if (local_78 == (char *)0x0) {
        unaff_s5 = (char *)0xffffffff;
      }
      else {
        pcVar12 = (char *)(*(code *)PTR_BIO_new_file_006a6eac)(local_78,&DAT_00633e40);
        if (pcVar12 == (char *)0x0) {
          uVar9 = *puVar11;
          puVar11 = (undefined4 *)0x1;
          (*(code *)PTR_BIO_printf_006a6e38)(uVar9,"Can\'t open signature file %s\n",local_78);
          goto LAB_00468778;
        }
        unaff_s5 = (char *)bio_to_mem(&local_34,local_64 * 10,pcVar12);
        (*(code *)PTR_BIO_free_006a6e70)(pcVar12);
        if ((int)unaff_s5 < 1) {
          uVar9 = *puVar11;
          pcVar12 = (char *)0x0;
          puVar11 = (undefined4 *)0x1;
          (*(code *)PTR_BIO_printf_006a6e38)(uVar9,"Error reading signature data\n");
          goto LAB_00468778;
        }
      }
      if (param_1 == 0) {
        uVar15 = 0;
      }
      else {
        uVar5 = bio_to_mem(&local_38,local_64 * 10,param_1);
        if ((int)uVar5 < 1) {
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar11,"Error reading input Data\n");
          puVar11 = (undefined4 *)(*(code *)PTR_exit_006a9a40)(1);
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
        iVar7 = (*(code *)PTR_EVP_PKEY_verify_006a7d08)(unaff_s4,local_34,unaff_s5,local_38,uVar15);
        if (iVar7 == 0) {
          (*(code *)PTR_BIO_puts_006a6f58)(pcVar8,"Signature Verification Failure\n");
LAB_00468a34:
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(unaff_s4);
          (*(code *)PTR_BIO_free_006a6e70)(param_1);
          param_2 = pcVar8;
          pcVar12 = unaff_s5;
          goto LAB_00468560;
        }
        if (iVar7 == 1) {
          puVar11 = (undefined4 *)0x1;
          (*(code *)PTR_BIO_puts_006a6f58)(pcVar8,"Signature Verified Successfully\n");
          pcVar12 = (char *)0x0;
        }
        else {
          if (iVar7 < 0) goto LAB_00468f64;
          puVar11 = (undefined4 *)0x1;
          pcVar12 = (char *)0x0;
        }
      }
      else {
        pcVar13 = (code *)PTR_EVP_PKEY_encrypt_006a7d14;
        if (local_74 == 0x100) {
LAB_00468d1c:
          iVar7 = (*pcVar13)(unaff_s4,0,&local_30,local_38,uVar15);
LAB_00468d38:
          unaff_s6 = &local_30;
          if ((iVar7 < 1) ||
             (pcVar12 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(local_30,"pkeyutl.c",0x136),
             pcVar12 == (char *)0x0)) goto LAB_00468f64;
          pcVar13 = (code *)PTR_EVP_PKEY_encrypt_006a7d14;
          if (local_74 == 0x100) {
LAB_00468d8c:
            iVar7 = (*pcVar13)(unaff_s4,pcVar12,unaff_s6,local_38,uVar15);
LAB_00468da4:
            if (0 < iVar7) {
              if (local_50 == 0) {
                pcVar13 = (code *)PTR_BIO_write_006a6e14;
                if (bVar2) {
                  pcVar13 = (code *)PTR_BIO_dump_006a7648;
                }
                puVar11 = (undefined4 *)0x0;
                (*pcVar13)(pcVar8,pcVar12,local_30);
              }
              else {
                iVar7 = (*(code *)PTR_ASN1_parse_dump_006a74b8)
                                  (pcVar8,pcVar12,local_30,1,0xffffffff);
                if (iVar7 == 0) {
                  uVar9 = *puVar11;
                  puVar11 = (undefined4 *)0x0;
                  (*(code *)PTR_ERR_print_errors_006a6e40)(uVar9);
                }
                else {
                  puVar11 = (undefined4 *)0x0;
                }
              }
              goto LAB_00468778;
            }
          }
          else {
            if (0x100 < local_74) {
              pcVar13 = (code *)PTR_EVP_PKEY_decrypt_006a7d0c;
              if (local_74 == 0x200) goto LAB_00468d8c;
              if (local_74 != 0x400) goto LAB_00468f68;
              iVar7 = (*(code *)PTR_EVP_PKEY_derive_006a7d04)(unaff_s4,pcVar12,unaff_s6,local_38);
              goto LAB_00468da4;
            }
            pcVar13 = (code *)PTR_EVP_PKEY_sign_006a7d10;
            if ((local_74 == 8) ||
               (pcVar13 = (code *)PTR_EVP_PKEY_verify_recover_006a7cf8, local_74 == 0x20))
            goto LAB_00468d8c;
          }
        }
        else {
          if (0x100 < local_74) {
            pcVar13 = (code *)PTR_EVP_PKEY_decrypt_006a7d0c;
            if (local_74 == 0x200) goto LAB_00468d1c;
            if (local_74 != 0x400) goto LAB_00468f64;
            iVar7 = (*(code *)PTR_EVP_PKEY_derive_006a7d04)(unaff_s4,0,&local_30,local_38);
            goto LAB_00468d38;
          }
          pcVar13 = (code *)PTR_EVP_PKEY_sign_006a7d10;
          if ((local_74 == 8) ||
             (pcVar13 = (code *)PTR_EVP_PKEY_verify_recover_006a7cf8, local_74 == 0x20))
          goto LAB_00468d1c;
LAB_00468f64:
          pcVar12 = (char *)0x0;
        }
LAB_00468f68:
        (*(code *)PTR_BIO_printf_006a6e38)(*puVar11,"Public Key operation error\n");
        uVar9 = *puVar11;
        puVar11 = (undefined4 *)0x1;
        (*(code *)PTR_ERR_print_errors_006a6e40)(uVar9);
      }
LAB_00468778:
      (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(unaff_s4);
      (*(code *)PTR_BIO_free_006a6e70)(param_1);
      (*(code *)PTR_BIO_free_all_006a6e74)(pcVar8);
      param_2 = pcVar8;
    } while (local_38 == 0);
  } while( true );
LAB_004686e8:
  while( true ) {
    pcVar8 = *unaff_s6;
    if ((((*pcVar8 == '-') && (pcVar8[1] == 'i')) && (pcVar8[2] == 'n')) && (pcVar8[3] == '\0')) {
      unaff_s7 = iVar7 + -1;
      if (unaff_s7 == 0) goto LAB_00468a1c;
      param_2 = unaff_s6[1];
      ppcVar14 = unaff_s6 + 1;
      goto LAB_004686e0;
    }
    iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,param_1 + 0x2514);
    if (iVar4 != 0) break;
    unaff_s7 = iVar7 + -1;
    if (iVar7 + -1 == 0) goto LAB_00468a1c;
    unaff_s5 = unaff_s6[1];
    iVar7 = iVar7 + -2;
    unaff_s6 = unaff_s6 + 2;
    unaff_s7 = iVar7;
    if (iVar7 < 1) goto LAB_00468734;
  }
  iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,local_7c + 0x27a4);
  if (iVar4 == 0) {
    unaff_s7 = iVar7 + -1;
    if (unaff_s7 != 0) {
      local_78 = unaff_s6[1];
      ppcVar14 = unaff_s6 + 1;
      goto LAB_004686e0;
    }
    goto LAB_00468a1c;
  }
  iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-inkey");
  if (iVar4 != 0) {
    iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-peerkey");
    if (iVar4 == 0) {
      unaff_s7 = iVar7 + -1;
      if (unaff_s7 != 0) {
        uVar9 = *puVar11;
        ppcVar14 = unaff_s6 + 1;
        unaff_s6 = (char **)unaff_s6[1];
        if (unaff_s4 == 0) {
          (*(code *)PTR_BIO_puts_006a6f58)(uVar9,"-peerkey command before -inkey\n");
        }
        else {
          iVar7 = load_pubkey(uVar9,unaff_s6,local_5c,0,0,0,local_58);
          if (iVar7 == 0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)PTR_bio_err_006a6e3c,"Error reading peer key %s\n",unaff_s6);
            (*(code *)PTR_ERR_print_errors_006a6e40)(uVar9);
          }
          else {
            unaff_s6 = (char **)(*(code *)PTR_EVP_PKEY_derive_set_peer_006a7cf0)(unaff_s4,iVar7);
            (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar7);
            if ((0 < (int)unaff_s6) ||
               ((*(code *)PTR_ERR_print_errors_006a6e40)(uVar9), unaff_s6 != (char **)0x0))
            goto LAB_004686e0;
          }
        }
      }
    }
    else {
      iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-passin");
      if (iVar4 == 0) {
        unaff_s7 = iVar7 + -1;
        if (unaff_s7 != 0) {
          local_68 = unaff_s6[1];
          ppcVar14 = unaff_s6 + 1;
          goto LAB_004686e0;
        }
      }
      else {
        iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-peerform");
        if (iVar4 == 0) {
          unaff_s7 = iVar7 + -1;
          if (unaff_s7 != 0) {
            ppcVar14 = unaff_s6 + 1;
            local_5c = str2fmt(unaff_s6[1]);
            goto LAB_004686e0;
          }
        }
        else {
          iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-keyform");
          if (iVar4 == 0) {
            unaff_s7 = iVar7 + -1;
            if (unaff_s7 != 0) {
              local_60 = str2fmt(unaff_s6[1]);
              ppcVar14 = unaff_s6 + 1;
              goto LAB_004686e0;
            }
          }
          else {
            iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-engine");
            if (iVar4 == 0) {
              unaff_s7 = iVar7 + -1;
              if (unaff_s7 != 0) {
                local_70 = setup_engine(*puVar11,unaff_s6[1],0);
                ppcVar14 = unaff_s6 + 1;
                goto LAB_004686e0;
              }
            }
            else {
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-pubin");
              ppcVar14 = unaff_s6;
              if (iVar4 == 0) {
                local_6c = 2;
                unaff_s7 = iVar7;
                goto LAB_004686e0;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-certin");
              if (iVar4 == 0) {
                local_6c = 3;
                unaff_s7 = iVar7;
                goto LAB_004686e0;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-asn1parse");
              if (iVar4 == 0) {
                local_50 = 1;
                unaff_s7 = iVar7;
                goto LAB_004686e0;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-hexdump");
              if (iVar4 == 0) goto LAB_004694c0;
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-sign");
              if (iVar4 == 0) {
                local_74 = 8;
                unaff_s7 = iVar7;
                goto LAB_004686e0;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-verify");
              if (iVar4 == 0) {
                local_74 = 0x10;
                unaff_s7 = iVar7;
                goto LAB_004686e0;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-verifyrecover");
              if (iVar4 == 0) {
                local_74 = 0x20;
                unaff_s7 = iVar7;
                goto LAB_004686e0;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,&DAT_00637b3c);
              if (iVar4 == 0) {
                local_54 = 1;
                unaff_s7 = iVar7;
                goto LAB_004686e0;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-encrypt");
              if (iVar4 == 0) {
                local_74 = 0x100;
                unaff_s7 = iVar7;
                goto LAB_004686e0;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-decrypt");
              if (iVar4 == 0) {
                local_74 = 0x200;
                unaff_s7 = iVar7;
                goto LAB_004686e0;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-derive");
              if (iVar4 == 0) {
                local_74 = 0x400;
                unaff_s7 = iVar7;
                goto LAB_004686e0;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar8,"-pkeyopt");
              unaff_s7 = iVar7;
              if ((iVar4 == 0) && (unaff_s7 = iVar7 + -1, unaff_s7 != 0)) {
                if (unaff_s4 != 0) {
                  iVar7 = pkey_ctrl_string(unaff_s4,unaff_s6[1]);
                  ppcVar14 = unaff_s6 + 1;
                  if (iVar7 < 1) {
                    (*(code *)PTR_BIO_puts_006a6f58)(*puVar11,"parameter setting error\n");
                    (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar11);
LAB_00468768:
                    puVar11 = (undefined4 *)0x1;
                    pcVar12 = (char *)0x0;
                    pcVar8 = (char *)0x0;
                    param_1 = 0;
                    goto LAB_00468778;
                  }
                  goto LAB_004686e0;
                }
                (*(code *)PTR_BIO_puts_006a6f58)(*puVar11,"-pkeyopt command before -inkey\n");
              }
            }
          }
        }
      }
    }
    goto LAB_00468a1c;
  }
  unaff_s7 = iVar7 + -1;
  if (unaff_s7 == 0) goto LAB_00468a1c;
  pcVar8 = unaff_s6[1];
  local_30 = (char *)0x0;
  if (((local_74 == 8) || (local_74 == 0x200)) || (local_74 == 0x400)) {
    if (local_6c != 1) {
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar11,"A private key is needed for this operation\n");
      goto joined_r0x00468ae0;
    }
    iVar7 = app_passwd(*puVar11,local_68,0,&local_30,0);
    if (iVar7 != 0) {
LAB_00468ef0:
      iVar7 = load_key(*puVar11,pcVar8,local_60,0,local_30,local_70,local_4c);
      goto LAB_004688d4;
    }
LAB_00468ac4:
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar11,"Error getting password\n");
  }
  else {
    iVar7 = app_passwd(*puVar11,local_68,0,&local_30,0);
    if (iVar7 == 0) goto LAB_00468ac4;
    if (local_6c == 2) {
      iVar7 = load_pubkey(*(undefined4 *)PTR_bio_err_006a6e3c,pcVar8,local_60,0,0,local_70,local_48)
      ;
LAB_004688d4:
      local_64 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(iVar7);
      if (iVar7 != 0) {
        unaff_s4 = (*(code *)PTR_EVP_PKEY_CTX_new_006a6fe0)(iVar7,local_70);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar7);
        if (unaff_s4 != 0) {
          if (local_74 == 0x20) {
            iVar7 = (*(code *)PTR_EVP_PKEY_verify_recover_init_006a7ce0)(unaff_s4);
LAB_00468ec8:
            if (0 < iVar7) {
              ppcVar14 = unaff_s6 + 1;
              if (local_30 != (char *)0x0) {
                (*(code *)PTR_CRYPTO_free_006a6e88)();
              }
              goto LAB_004686e0;
            }
          }
          else {
            if (0x20 < local_74) {
              if (local_74 == 0x200) {
                iVar7 = (*(code *)PTR_EVP_PKEY_decrypt_init_006a7ce4)(unaff_s4);
              }
              else if (local_74 == 0x400) {
                iVar7 = (*(code *)PTR_EVP_PKEY_derive_init_006a7ce8)(unaff_s4);
              }
              else {
                if (local_74 != 0x100) goto LAB_00468954;
                iVar7 = (*(code *)PTR_EVP_PKEY_encrypt_init_006a7cec)(unaff_s4);
              }
              goto LAB_00468ec8;
            }
            if (local_74 == 8) {
              iVar7 = (*(code *)PTR_EVP_PKEY_sign_init_006a7cfc)(unaff_s4);
              goto LAB_00468ec8;
            }
            if (local_74 == 0x10) {
              iVar7 = (*(code *)PTR_EVP_PKEY_verify_init_006a7d00)(unaff_s4);
              goto LAB_00468ec8;
            }
          }
LAB_00468954:
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(unaff_s4);
        }
      }
    }
    else {
      if (local_6c == 3) {
        iVar4 = load_cert(*puVar11,pcVar8,local_60,0,local_70,"Certificate");
        if (iVar4 != 0) {
          iVar7 = (*(code *)PTR_X509_get_pubkey_006a6f08)(iVar4);
          (*(code *)PTR_X509_free_006a6e90)(iVar4);
          goto LAB_004688d4;
        }
      }
      else if (local_6c == 1) goto LAB_00468ef0;
      (*(code *)PTR_EVP_PKEY_size_006a74f8)(0);
    }
  }
joined_r0x00468ae0:
  if (local_30 != (char *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  unaff_s4 = 0;
  (*(code *)PTR_BIO_puts_006a6f58)(*puVar11,"Error initializing context\n");
  (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar11);
LAB_00468a1c:
  usage();
  if (unaff_s4 == 0) goto LAB_0046854c;
  pcVar8 = (char *)0x0;
  param_1 = 0;
  goto LAB_00468a34;
LAB_00469160:
  usage();
  goto LAB_0046854c;
}

