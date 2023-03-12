
undefined4 * rsautl_main(int param_1,char *param_2)

{
  bool bVar1;
  char cVar2;
  undefined *puVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  char **ppcVar10;
  char *pcVar11;
  undefined4 *puVar12;
  undefined *puVar13;
  char *unaff_s4;
  char *unaff_s5;
  char *pcVar14;
  char *unaff_s7;
  code *pcVar15;
  char **unaff_s8;
  char *local_6c;
  int local_68;
  char *local_64;
  char *local_60;
  int local_5c;
  char *local_58;
  int local_54;
  undefined4 local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  int local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  puVar6 = (undefined4 *)PTR_bio_err_006a7f3c;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar8 = *(int *)PTR_bio_err_006a7f3c;
  if (iVar8 == 0) {
    iVar8 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *puVar6 = iVar8;
  }
  iVar8 = (*(code *)PTR_load_config_006a7f64)(iVar8,0);
  if (iVar8 == 0) {
    iVar8 = 0;
    puVar13 = (undefined *)0x0;
    goto LAB_00437af0;
  }
  unaff_s7 = (char *)(param_1 + -1);
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  (*(code *)PTR_OPENSSL_add_all_algorithms_noconf_006a84fc)();
  if ((int)unaff_s7 < 1) {
    local_6c = (char *)0x0;
    param_2 = (char *)0x0;
    local_44 = 0;
    unaff_s5 = (char *)0x0;
    local_38 = 0;
    local_5c = 1;
    local_64 = (char *)0x0;
    local_40 = 0;
    local_50 = 3;
    local_58 = (char *)0x0;
    local_3c = 1;
    local_48 = 2;
    goto LAB_00437e68;
  }
  local_64 = (char *)0x0;
  local_40 = 0;
  local_38 = 0;
  local_3c = 1;
  unaff_s8 = (char **)(param_2 + 4);
  local_44 = 0;
  local_54 = 0;
  unaff_s5 = (char *)0x0;
  local_50 = 3;
  local_6c = (char *)0x0;
  param_2 = (char *)0x0;
  local_58 = (char *)0x0;
  puVar13 = &DAT_00632edc;
  local_5c = 1;
  unaff_s4 = "-inkey";
  local_48 = 2;
  local_68 = 0x630000;
  local_60 = "-keyform";
  local_4c = 0x630000;
  while ((((pcVar14 = *unaff_s8, *pcVar14 != '-' || (pcVar14[1] != 'i')) || (pcVar14[2] != 'n')) ||
         (pcVar14[3] != '\0'))) {
    iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,puVar13);
    if (iVar8 != 0) {
      iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,unaff_s4);
      if (iVar8 == 0) {
        unaff_s7 = unaff_s7 + -1;
        if (unaff_s7 != (char *)0x0) {
          local_6c = unaff_s8[1];
          ppcVar10 = unaff_s8 + 1;
          goto LAB_00437a5c;
        }
      }
      else {
        iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,local_68 + 0x30e8);
        if (iVar8 == 0) {
          unaff_s7 = unaff_s7 + -1;
          if (unaff_s7 != (char *)0x0) {
            local_64 = unaff_s8[1];
            ppcVar10 = unaff_s8 + 1;
            goto LAB_00437a5c;
          }
        }
        else {
          iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,local_60);
          if (iVar8 == 0) {
            unaff_s7 = unaff_s7 + -1;
            if (unaff_s7 != (char *)0x0) {
              ppcVar10 = unaff_s8 + 1;
              local_50 = (*(code *)PTR_str2fmt_006a7f4c)(unaff_s8[1]);
              goto LAB_00437a5c;
            }
          }
          else {
            iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,local_4c + 0x2884);
            if (iVar8 == 0) {
              unaff_s7 = unaff_s7 + -1;
              if (unaff_s7 != (char *)0x0) {
                local_58 = unaff_s8[1];
                ppcVar10 = unaff_s8 + 1;
                goto LAB_00437a5c;
              }
            }
            else {
              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-pubin");
              ppcVar10 = unaff_s8;
              if (iVar8 == 0) {
                local_5c = 2;
                goto LAB_00437a5c;
              }
              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-certin");
              if (iVar8 == 0) {
                local_5c = 3;
                goto LAB_00437a5c;
              }
              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-asn1parse");
              if (iVar8 == 0) {
                local_40 = 1;
                goto LAB_00437a5c;
              }
              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-hexdump");
              if (iVar8 == 0) {
                local_38 = 1;
                goto LAB_00437a5c;
              }
              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,&DAT_00638350);
              if (iVar8 == 0) {
                local_3c = 3;
                goto LAB_00437a5c;
              }
              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-oaep");
              if (iVar8 == 0) {
                local_3c = 4;
                goto LAB_00437a5c;
              }
              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,&DAT_00638360);
              if (iVar8 == 0) {
                local_3c = 2;
                goto LAB_00437a5c;
              }
              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-pkcs");
              if (iVar8 == 0) {
                local_3c = 1;
                goto LAB_00437a5c;
              }
              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-x931");
              if (iVar8 == 0) goto LAB_00438598;
              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-sign");
              if (iVar8 == 0) {
                local_54 = 1;
                local_48 = 1;
                goto LAB_00437a5c;
              }
              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-verify");
              if (iVar8 == 0) {
                local_48 = 2;
                goto LAB_00437a5c;
              }
              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,&DAT_00638378);
              if (iVar8 == 0) {
                local_44 = 1;
                goto LAB_00437a5c;
              }
              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-encrypt");
              if (iVar8 == 0) {
                local_48 = 3;
                goto LAB_00437a5c;
              }
              iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-decrypt");
              if (iVar8 == 0) {
                local_54 = 1;
                local_48 = 4;
                goto LAB_00437a5c;
              }
            }
          }
        }
      }
LAB_00437c3c:
      iVar8 = 0;
      puVar13 = (undefined *)0x0;
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"Usage: rsautl [options]\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"-in file        input file\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"-out file       output file\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"-inkey file     input key\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar6,"-keyform arg    private key format - default PEM\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"-pubin          input is an RSA public\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar6,"-certin         input is a certificate carrying an RSA public key\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"-ssl            use SSL v2 padding\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"-raw            use no padding\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar6,"-pkcs           use PKCS#1 v1.5 padding (default)\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"-oaep           use PKCS#1 OAEP\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"-sign           sign with private key\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"-verify         verify with public key\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"-encrypt        encrypt with public key\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"-decrypt        decrypt with private key\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"-hexdump        hex dump output\n");
      (*(code *)PTR_BIO_printf_006a7f38)
                (*puVar6,"-engine e       use engine e, possibly a hardware device.\n");
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"-passin arg    pass phrase source\n");
      goto LAB_00437af0;
    }
    bVar1 = unaff_s7 == (char *)0x1;
    unaff_s7 = unaff_s7 + -2;
    if (bVar1) goto LAB_00437c3c;
    unaff_s5 = unaff_s8[1];
    unaff_s8 = unaff_s8 + 2;
    for (; (int)unaff_s7 < 1; unaff_s7 = unaff_s7 + -1) {
      if (local_54 == 0) {
LAB_00437e68:
        unaff_s4 = PTR_bio_err_006a7f3c;
        puVar13 = (undefined *)(*(code *)PTR_setup_engine_006a7fc4)(*puVar6,local_58,0);
        iVar8 = (*(code *)PTR_app_passwd_006a7f54)(*puVar6,local_64,0,&local_30,0);
        if (iVar8 == 0) goto LAB_00437f30;
        (*(code *)PTR_app_RAND_load_file_006a7fcc)(0,*(undefined4 *)unaff_s4,0);
        if (local_5c == 2) {
          puVar5 = (undefined *)
                   (*(code *)PTR_load_pubkey_006a85e4)
                             (*(undefined4 *)unaff_s4,local_6c,local_50,0,0,puVar13,"Public Key");
LAB_00438134:
          puVar13 = puVar5;
          if (puVar5 != (undefined *)0x0) {
            iVar8 = (*(code *)PTR_EVP_PKEY_get1_RSA_006a86e8)(puVar5);
            (*(code *)PTR_EVP_PKEY_free_006a7f78)(puVar5);
            if (iVar8 == 0) {
              puVar13 = (undefined *)0x0;
              (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"Error getting RSA key\n");
              (*(code *)PTR_ERR_print_errors_006a7f40)(*puVar6);
              goto LAB_00437af0;
            }
            if (param_2 != (char *)0x0) {
              puVar13 = (undefined *)(*(code *)PTR_BIO_new_file_006a7fac)(param_2,&DAT_006347ac);
              if (puVar13 != (undefined *)0x0) goto LAB_00438184;
              uVar9 = *puVar6;
              pcVar14 = "Error Reading Input File\n";
LAB_00438340:
              (*(code *)PTR_BIO_printf_006a7f38)(uVar9,pcVar14);
              (*(code *)PTR_ERR_print_errors_006a7f40)(*puVar6);
              goto LAB_00437af0;
            }
            puVar13 = (undefined *)
                      (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdin_006aab20,0);
LAB_00438184:
            if (unaff_s5 == (char *)0x0) {
              unaff_s4 = (char *)(*(code *)PTR_BIO_new_fp_006a835c)
                                           (*(undefined4 *)PTR_stdout_006aaad4,0);
            }
            else {
              unaff_s4 = (char *)(*(code *)PTR_BIO_new_file_006a7fac)(unaff_s5,&DAT_00632de8);
              if (unaff_s4 == (char *)0x0) {
                uVar9 = *puVar6;
                pcVar14 = "Error Reading Output File\n";
                goto LAB_00438340;
              }
            }
            unaff_s7 = "s\n";
            iVar4 = (*(code *)PTR_RSA_size_006a8730)(iVar8);
            unaff_s5 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar4 << 1,"rsautl.c",0x104);
            param_2 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar4,"rsautl.c",0x105);
            iVar4 = (*(code *)PTR_BIO_read_006a85bc)(puVar13,unaff_s5,iVar4 << 1);
            if (iVar4 < 1) {
              (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"Error reading input Data\n");
              puVar6 = (undefined4 *)(*(code *)PTR_exit_006aab4c)(1);
              return puVar6;
            }
            if ((local_44 != 0) && (iVar4 >> 1 != 0)) {
              pcVar14 = unaff_s5;
              pcVar11 = unaff_s5 + iVar4 + -1;
              do {
                pcVar7 = pcVar14 + 1;
                cVar2 = *pcVar14;
                *pcVar14 = *pcVar11;
                *pcVar11 = cVar2;
                pcVar14 = pcVar7;
                pcVar11 = pcVar11 + -1;
              } while (unaff_s5 + (iVar4 >> 1) != pcVar7);
            }
            pcVar15 = (code *)PTR_RSA_public_decrypt_006a8740;
            if (local_48 == 2) {
LAB_00438284:
              iVar4 = (*pcVar15)(iVar4,unaff_s5,param_2,iVar8,local_3c);
              if (iVar4 < 1) goto LAB_004384c0;
              if (local_40 == 0) {
                pcVar15 = (code *)PTR_BIO_write_006a7f14;
                if (local_38 != 0) {
                  pcVar15 = (code *)PTR_BIO_dump_006a8738;
                }
                (*pcVar15)(unaff_s4,param_2);
                puVar12 = (undefined4 *)0x0;
              }
              else {
                iVar4 = (*(code *)PTR_ASN1_parse_dump_006a85b4)(unaff_s4,param_2,iVar4,1,0xffffffff)
                ;
                if (iVar4 == 0) {
                  puVar12 = (undefined4 *)0x0;
                  (*(code *)PTR_ERR_print_errors_006a7f40)(*puVar6);
                }
                else {
                  puVar12 = (undefined4 *)0x0;
                }
              }
            }
            else {
              if (local_48 < 3) {
                pcVar15 = (code *)PTR_RSA_private_encrypt_006a873c;
                if (local_48 == 1) goto LAB_00438284;
              }
              else {
                pcVar15 = (code *)PTR_RSA_public_encrypt_006a8744;
                if ((local_48 == 3) ||
                   (pcVar15 = (code *)PTR_RSA_private_decrypt_006a8734, local_48 == 4))
                goto LAB_00438284;
              }
LAB_004384c0:
              (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"RSA operation error\n");
              puVar12 = (undefined4 *)0x1;
              (*(code *)PTR_ERR_print_errors_006a7f40)(*puVar6);
            }
            (*(code *)PTR_RSA_free_006a86f0)(iVar8);
            (*(code *)PTR_BIO_free_006a7f70)(puVar13);
            (*(code *)PTR_BIO_free_all_006a7f74)(unaff_s4);
            if (unaff_s5 != (char *)0x0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s5);
            }
            if (param_2 != (char *)0x0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)(param_2);
            }
            goto LAB_00437b24;
          }
        }
        else if (local_5c == 3) {
          puVar13 = (undefined *)
                    (*(code *)PTR_load_cert_006a8178)
                              (*(undefined4 *)unaff_s4,local_6c,local_50,0,puVar13,"Certificate");
          if (puVar13 != (undefined *)0x0) {
            puVar5 = (undefined *)(*(code *)PTR_X509_get_pubkey_006a8008)(puVar13);
            (*(code *)PTR_X509_free_006a7f90)(puVar13);
            goto LAB_00438134;
          }
        }
        else if (local_5c == 1) goto LAB_0043838c;
        puVar12 = (undefined4 *)0x1;
      }
      else {
        if (local_5c == 1) {
          puVar13 = (undefined *)(*(code *)PTR_setup_engine_006a7fc4)(*puVar6,local_58,0);
          iVar8 = (*(code *)PTR_app_passwd_006a7f54)(*puVar6,local_64,0,&local_30,0);
          if (iVar8 != 0) {
            (*(code *)PTR_app_RAND_load_file_006a7fcc)(0,*(undefined4 *)PTR_bio_err_006a7f3c,0);
LAB_0043838c:
            puVar5 = (undefined *)
                     (*(code *)PTR_load_key_006a7fc8)
                               (*puVar6,local_6c,local_50,0,local_30,puVar13,"Private Key");
            goto LAB_00438134;
          }
LAB_00437f30:
          iVar8 = 0;
          puVar13 = (undefined *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"Error getting password\n");
        }
        else {
          iVar8 = 0;
          puVar13 = (undefined *)0x0;
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar6,"A private key is needed for this operation\n")
          ;
        }
LAB_00437af0:
        puVar12 = (undefined4 *)0x1;
        (*(code *)PTR_RSA_free_006a86f0)(iVar8);
        (*(code *)PTR_BIO_free_006a7f70)(puVar13);
        (*(code *)PTR_BIO_free_all_006a7f74)(0);
LAB_00437b24:
        puVar6 = puVar12;
        if (local_30 != 0) {
          (*(code *)PTR_CRYPTO_free_006a7f88)();
        }
      }
      if (local_2c == *(int *)puVar3) {
        return puVar12;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00438598:
      local_3c = 5;
      ppcVar10 = unaff_s8;
LAB_00437a5c:
      unaff_s8 = ppcVar10 + 1;
    }
  }
  unaff_s7 = unaff_s7 + -1;
  if (unaff_s7 != (char *)0x0) {
    param_2 = unaff_s8[1];
    ppcVar10 = unaff_s8 + 1;
    goto LAB_00437a5c;
  }
  goto LAB_00437c3c;
}

