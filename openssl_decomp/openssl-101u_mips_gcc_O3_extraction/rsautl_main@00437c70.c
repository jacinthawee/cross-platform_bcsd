
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
  int unaff_s7;
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
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  puVar6 = (undefined4 *)PTR_bio_err_006a6e3c;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar8 = *(int *)PTR_bio_err_006a6e3c;
  if (iVar8 == 0) {
    iVar8 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *puVar6 = iVar8;
  }
  iVar8 = (*(code *)PTR_load_config_006a6e64)(iVar8,0);
  if (iVar8 == 0) {
    iVar8 = 0;
    puVar13 = (undefined *)0x0;
    goto LAB_00437e50;
  }
  unaff_s7 = param_1 + -1;
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  (*(code *)PTR_OPENSSL_add_all_algorithms_noconf_006a73fc)();
  if (unaff_s7 < 1) {
    local_6c = (char *)0x0;
    param_2 = (char *)0x0;
    local_38 = 0;
    unaff_s5 = (char *)0x0;
    local_3c = 0;
    local_44 = 1;
    local_64 = (char *)0x0;
    local_40 = 0;
    local_48 = 2;
    local_58 = (char *)0x0;
    local_50 = 3;
    local_5c = 1;
    goto LAB_004381c8;
  }
  local_64 = (char *)0x0;
  local_3c = 0;
  local_38 = 0;
  local_44 = 1;
  unaff_s8 = (char **)(param_2 + 4);
  local_40 = 0;
  local_54 = 0;
  unaff_s5 = (char *)0x0;
  local_50 = 3;
  local_6c = (char *)0x0;
  param_2 = (char *)0x0;
  local_58 = (char *)0x0;
  puVar13 = &DAT_00632514;
  local_5c = 1;
  unaff_s4 = "-inkey";
  local_48 = 2;
  local_68 = 0x630000;
  local_60 = "-keyform";
  local_4c = 0x630000;
  while ((((pcVar14 = *unaff_s8, *pcVar14 != '-' || (pcVar14[1] != 'i')) || (pcVar14[2] != 'n')) ||
         (pcVar14[3] != '\0'))) {
    iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,puVar13);
    if (iVar8 != 0) {
      iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,unaff_s4);
      if (iVar8 == 0) {
        unaff_s7 = unaff_s7 + -1;
        if (unaff_s7 != 0) {
          local_6c = unaff_s8[1];
          ppcVar10 = unaff_s8 + 1;
          goto LAB_00437dbc;
        }
      }
      else {
        iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,local_68 + 0x2720);
        if (iVar8 == 0) {
          unaff_s7 = unaff_s7 + -1;
          if (unaff_s7 != 0) {
            local_64 = unaff_s8[1];
            ppcVar10 = unaff_s8 + 1;
            goto LAB_00437dbc;
          }
        }
        else {
          iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,local_60);
          if (iVar8 == 0) {
            unaff_s7 = unaff_s7 + -1;
            if (unaff_s7 != 0) {
              ppcVar10 = unaff_s8 + 1;
              local_50 = (*(code *)PTR_str2fmt_006a6e4c)(unaff_s8[1]);
              goto LAB_00437dbc;
            }
          }
          else {
            iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,local_4c + 0x1eb4);
            if (iVar8 == 0) {
              unaff_s7 = unaff_s7 + -1;
              if (unaff_s7 != 0) {
                local_58 = unaff_s8[1];
                ppcVar10 = unaff_s8 + 1;
                goto LAB_00437dbc;
              }
            }
            else {
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-pubin");
              ppcVar10 = unaff_s8;
              if (iVar8 == 0) {
                local_5c = 2;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-certin");
              if (iVar8 == 0) {
                local_5c = 3;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-asn1parse");
              if (iVar8 == 0) {
                local_3c = 1;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-hexdump");
              if (iVar8 == 0) {
                local_38 = 1;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,&DAT_00637b14);
              if (iVar8 == 0) {
                local_44 = 3;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-oaep");
              if (iVar8 == 0) {
                local_44 = 4;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,&DAT_00637b24);
              if (iVar8 == 0) {
                local_44 = 2;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-pkcs");
              if (iVar8 == 0) {
                local_44 = 1;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-x931");
              if (iVar8 == 0) goto LAB_004389c0;
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-sign");
              if (iVar8 == 0) {
                local_54 = 1;
                local_48 = 1;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-verify");
              if (iVar8 == 0) {
                local_48 = 2;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,&DAT_00637b3c);
              if (iVar8 == 0) {
                local_40 = 1;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-encrypt");
              if (iVar8 == 0) {
                local_48 = 3;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-decrypt");
              if (iVar8 == 0) {
                local_54 = 1;
                local_48 = 4;
                goto LAB_00437dbc;
              }
            }
          }
        }
      }
LAB_00437f9c:
      iVar8 = 0;
      puVar13 = (undefined *)0x0;
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"Usage: rsautl [options]\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"-in file        input file\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"-out file       output file\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"-inkey file     input key\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*puVar6,"-keyform arg    private key format - default PEM\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"-pubin          input is an RSA public\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*puVar6,"-certin         input is a certificate carrying an RSA public key\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"-ssl            use SSL v2 padding\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"-raw            use no padding\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*puVar6,"-pkcs           use PKCS#1 v1.5 padding (default)\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"-oaep           use PKCS#1 OAEP\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"-sign           sign with private key\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"-verify         verify with public key\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"-encrypt        encrypt with public key\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"-decrypt        decrypt with private key\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"-hexdump        hex dump output\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*puVar6,"-engine e       use engine e, possibly a hardware device.\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"-passin arg    pass phrase source\n");
      goto LAB_00437e50;
    }
    bVar1 = unaff_s7 == 1;
    unaff_s7 = unaff_s7 + -2;
    if (bVar1) goto LAB_00437f9c;
    unaff_s5 = unaff_s8[1];
    unaff_s8 = unaff_s8 + 2;
    for (; unaff_s7 < 1; unaff_s7 = unaff_s7 + -1) {
      if (local_54 == 0) {
LAB_004381c8:
        unaff_s4 = PTR_bio_err_006a6e3c;
        puVar13 = (undefined *)(*(code *)PTR_setup_engine_006a6ec4)(*puVar6,local_58,0);
        iVar8 = (*(code *)PTR_app_passwd_006a6e54)(*puVar6,local_64,0,&local_30,0);
        if (iVar8 == 0) goto LAB_00438290;
        (*(code *)PTR_app_RAND_load_file_006a6ecc)(0,*(undefined4 *)unaff_s4,0);
        if (local_5c == 2) {
          puVar5 = (undefined *)
                   (*(code *)PTR_load_pubkey_006a74e8)
                             (*(undefined4 *)unaff_s4,local_6c,local_50,0,0,puVar13,"Public Key");
LAB_00438494:
          puVar13 = puVar5;
          if (puVar5 != (undefined *)0x0) {
            iVar8 = (*(code *)PTR_EVP_PKEY_get1_RSA_006a75f8)(puVar5);
            (*(code *)PTR_EVP_PKEY_free_006a6e78)(puVar5);
            if (iVar8 == 0) {
              puVar13 = (undefined *)0x0;
              (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"Error getting RSA key\n");
              (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar6);
              goto LAB_00437e50;
            }
            if (param_2 != (char *)0x0) {
              puVar13 = (undefined *)(*(code *)PTR_BIO_new_file_006a6eac)(param_2,&DAT_00633e40);
              if (puVar13 != (undefined *)0x0) goto LAB_004384e4;
              uVar9 = *puVar6;
              pcVar14 = "Error Reading Input File\n";
LAB_004386a4:
              (*(code *)PTR_BIO_printf_006a6e38)(uVar9,pcVar14);
              (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar6);
              goto LAB_00437e50;
            }
            puVar13 = (undefined *)
                      (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14,0);
LAB_004384e4:
            if (unaff_s5 == (char *)0x0) {
              unaff_s4 = (char *)(*(code *)PTR_BIO_new_fp_006a7248)
                                           (*(undefined4 *)PTR_stdout_006a99c8,0);
            }
            else {
              unaff_s4 = (char *)(*(code *)PTR_BIO_new_file_006a6eac)(unaff_s5,&DAT_00632420);
              if (unaff_s4 == (char *)0x0) {
                uVar9 = *puVar6;
                pcVar14 = "Error Reading Output File\n";
                goto LAB_004386a4;
              }
            }
            iVar4 = (*(code *)PTR_RSA_size_006a7640)(iVar8);
            unaff_s7 = iVar4 << 1;
            unaff_s5 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(unaff_s7,"rsautl.c",0x10d);
            param_2 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar4,"rsautl.c",0x10e);
            if (unaff_s5 == (char *)0x0) {
              (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"Out of memory\n");
              puVar12 = (undefined4 *)0x1;
              (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar6);
              (*(code *)PTR_RSA_free_006a7600)(iVar8);
              (*(code *)PTR_BIO_free_006a6e70)(puVar13);
              (*(code *)PTR_BIO_free_all_006a6e74)(unaff_s4);
            }
            else {
              if (param_2 == (char *)0x0) {
                (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"Out of memory\n");
                puVar12 = (undefined4 *)0x1;
                (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar6);
                (*(code *)PTR_RSA_free_006a7600)(iVar8);
                (*(code *)PTR_BIO_free_006a6e70)(puVar13);
                (*(code *)PTR_BIO_free_all_006a6e74)(unaff_s4);
              }
              else {
                iVar4 = (*(code *)PTR_BIO_read_006a74c0)(puVar13,unaff_s5,unaff_s7);
                if (iVar4 < 1) {
                  (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"Error reading input Data\n");
                  puVar6 = (undefined4 *)(*(code *)PTR_exit_006a9a40)(1);
                  return puVar6;
                }
                if ((local_40 != 0) && (iVar4 >> 1 != 0)) {
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
                pcVar15 = (code *)PTR_RSA_public_decrypt_006a7650;
                if (local_48 == 2) {
LAB_004385ec:
                  iVar4 = (*pcVar15)(iVar4,unaff_s5,param_2,iVar8,local_44);
                  if (iVar4 < 1) goto LAB_00438898;
                  if (local_3c == 0) {
                    pcVar15 = (code *)PTR_BIO_write_006a6e14;
                    if (local_38 != 0) {
                      pcVar15 = (code *)PTR_BIO_dump_006a7648;
                    }
                    (*pcVar15)(unaff_s4,param_2,iVar4);
                    puVar12 = (undefined4 *)0x0;
                  }
                  else {
                    iVar4 = (*(code *)PTR_ASN1_parse_dump_006a74b8)
                                      (unaff_s4,param_2,iVar4,1,0xffffffff);
                    if (iVar4 == 0) {
                      puVar12 = (undefined4 *)0x0;
                      (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar6);
                    }
                    else {
                      puVar12 = (undefined4 *)0x0;
                    }
                  }
                }
                else {
                  if (local_48 < 3) {
                    pcVar15 = (code *)PTR_RSA_private_encrypt_006a764c;
                    if (local_48 == 1) goto LAB_004385ec;
                  }
                  else {
                    pcVar15 = (code *)PTR_RSA_public_encrypt_006a7654;
                    if ((local_48 == 3) ||
                       (pcVar15 = (code *)PTR_RSA_private_decrypt_006a7644, local_48 == 4))
                    goto LAB_004385ec;
                  }
LAB_00438898:
                  (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"RSA operation error\n");
                  puVar12 = (undefined4 *)0x1;
                  (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar6);
                }
                (*(code *)PTR_RSA_free_006a7600)(iVar8);
                (*(code *)PTR_BIO_free_006a6e70)(puVar13);
                (*(code *)PTR_BIO_free_all_006a6e74)(unaff_s4);
              }
              (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s5);
            }
            if (param_2 != (char *)0x0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)(param_2);
            }
            goto LAB_00437e84;
          }
        }
        else if (local_5c == 3) {
          puVar13 = (undefined *)
                    (*(code *)PTR_load_cert_006a7078)
                              (*(undefined4 *)unaff_s4,local_6c,local_50,0,puVar13,"Certificate");
          if (puVar13 != (undefined *)0x0) {
            puVar5 = (undefined *)(*(code *)PTR_X509_get_pubkey_006a6f08)(puVar13);
            (*(code *)PTR_X509_free_006a6e90)(puVar13);
            goto LAB_00438494;
          }
        }
        else if (local_5c == 1) goto LAB_004386f0;
        puVar12 = (undefined4 *)0x1;
      }
      else {
        if (local_5c == 1) {
          puVar13 = (undefined *)(*(code *)PTR_setup_engine_006a6ec4)(*puVar6,local_58,0);
          iVar8 = (*(code *)PTR_app_passwd_006a6e54)(*puVar6,local_64,0,&local_30,0);
          if (iVar8 != 0) {
            (*(code *)PTR_app_RAND_load_file_006a6ecc)(0,*(undefined4 *)PTR_bio_err_006a6e3c,0);
LAB_004386f0:
            puVar5 = (undefined *)
                     (*(code *)PTR_load_key_006a6ec8)
                               (*puVar6,local_6c,local_50,0,local_30,puVar13,"Private Key");
            goto LAB_00438494;
          }
LAB_00438290:
          iVar8 = 0;
          puVar13 = (undefined *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"Error getting password\n");
        }
        else {
          iVar8 = 0;
          puVar13 = (undefined *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar6,"A private key is needed for this operation\n")
          ;
        }
LAB_00437e50:
        puVar12 = (undefined4 *)0x1;
        (*(code *)PTR_RSA_free_006a7600)(iVar8);
        (*(code *)PTR_BIO_free_006a6e70)(puVar13);
        (*(code *)PTR_BIO_free_all_006a6e74)(0);
LAB_00437e84:
        puVar6 = puVar12;
        if (local_30 != 0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
        }
      }
      if (local_2c == *(int *)puVar3) {
        return puVar12;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004389c0:
      local_44 = 5;
      ppcVar10 = unaff_s8;
LAB_00437dbc:
      unaff_s8 = ppcVar10 + 1;
    }
  }
  unaff_s7 = unaff_s7 + -1;
  if (unaff_s7 != 0) {
    param_2 = unaff_s8[1];
    ppcVar10 = unaff_s8 + 1;
    goto LAB_00437dbc;
  }
  goto LAB_00437f9c;
}

