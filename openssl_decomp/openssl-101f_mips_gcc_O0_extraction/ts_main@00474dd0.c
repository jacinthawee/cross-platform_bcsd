
bool ts_main(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  uint uVar12;
  undefined4 uVar13;
  int iVar14;
  undefined4 *puVar15;
  int iVar16;
  int iVar17;
  char **ppcVar18;
  int iVar19;
  bool bVar21;
  undefined4 uVar20;
  char *pcVar22;
  int *piVar23;
  char *pcVar24;
  int iVar25;
  code *pcVar26;
  int *piVar27;
  int *piVar28;
  char *local_b4;
  char *local_a8;
  char *local_a0;
  char *local_94;
  char *local_90;
  char *local_8c;
  char *local_88;
  char *local_80;
  int local_7c;
  char *local_78;
  char *local_70;
  char *local_6c;
  undefined4 local_60;
  char *local_5c;
  char *local_58;
  char *local_54;
  char *local_50;
  char *local_4c;
  undefined4 local_48;
  uint local_44;
  char local_40 [4];
  char local_3c;
  char local_3b;
  char local_3a;
  char local_39;
  int local_2c;
  
  puVar8 = PTR___stack_chk_guard_006aabf0;
  puVar6 = PTR_bio_err_006a7f3c;
  local_48 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar17 = *(int *)puVar6;
  if (iVar17 == 0) {
    uVar13 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar17 = (*(code *)PTR_BIO_new_006a7fa4)(uVar13);
    *(int *)puVar6 = iVar17;
    if (iVar17 == 0) goto LAB_00474e54;
    (*(code *)PTR_BIO_ctrl_006a7f18)(iVar17,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
    iVar17 = load_config(*(undefined4 *)puVar6,0);
    if (iVar17 == 0) goto LAB_00476024;
    bVar4 = true;
  }
  else {
LAB_00474e54:
    iVar17 = load_config(iVar17,0);
    if (iVar17 == 0) {
      bVar21 = true;
      app_RAND_write_file(0,*(undefined4 *)puVar6);
      (*(code *)PTR_NCONF_free_006a7f6c)(0);
      (*(code *)PTR_CRYPTO_free_006a7f88)(local_48);
      (*(code *)PTR_OBJ_cleanup_006a7f98)();
LAB_00474eb0:
      while (local_2c != *(int *)puVar8) {
        (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00476024:
        bVar21 = true;
        app_RAND_write_file(0,*(undefined4 *)puVar6);
        (*(code *)PTR_NCONF_free_006a7f6c)(0);
        (*(code *)PTR_CRYPTO_free_006a7f88)(local_48);
        (*(code *)PTR_OBJ_cleanup_006a7f98)();
LAB_00475558:
        (*(code *)PTR_BIO_free_all_006a7f74)(*(undefined4 *)puVar6);
        *(undefined4 *)puVar6 = 0;
      }
      return bVar21;
    }
    bVar4 = false;
  }
  param_1 = param_1 + -1;
  bVar5 = false;
  ppcVar18 = (char **)(param_2 + 4);
  bVar2 = false;
  local_4c = (char *)0x0;
  iVar17 = 0;
  local_50 = (char *)0x0;
  pcVar24 = (char *)0x0;
  local_6c = (char *)0x0;
  local_70 = (char *)0x0;
  local_54 = (char *)0x0;
  local_58 = (char *)0x0;
  local_5c = (char *)0x0;
  local_80 = (char *)0x0;
  local_88 = (char *)0x0;
  bVar3 = false;
  local_78 = (char *)0x0;
  local_8c = (char *)0x0;
  local_60 = 0;
  bVar21 = false;
  local_90 = (char *)0x0;
  local_94 = (char *)0x0;
  local_7c = 0;
  local_a0 = (char *)0x0;
  local_a8 = (char *)0x0;
  local_b4 = (char *)0x0;
joined_r0x00474f5c:
  if (param_1 < 1) goto LAB_00475000;
  pcVar22 = *ppcVar18;
  iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-config");
  if (iVar9 == 0) {
    pcVar24 = ppcVar18[1];
    param_1 = param_1 + -1;
    ppcVar18 = ppcVar18 + 1;
    goto LAB_00474fa4;
  }
  iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-section");
  if (iVar9 == 0) {
    local_b4 = ppcVar18[1];
    param_1 = param_1 + -2;
    ppcVar18 = ppcVar18 + 2;
    goto joined_r0x00474f5c;
  }
  iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-query");
  if (iVar9 == 0) {
    bVar1 = iVar17 == 0;
    iVar17 = 1;
    if (bVar1) {
      param_1 = param_1 + -1;
      goto LAB_00474fa8;
    }
    goto LAB_004754b8;
  }
  iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-data");
  if (iVar9 == 0) {
    local_a8 = ppcVar18[1];
    param_1 = param_1 + -1;
    ppcVar18 = ppcVar18 + 1;
  }
  else {
    iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-digest");
    if (iVar9 == 0) {
      local_a0 = ppcVar18[1];
      param_1 = param_1 + -1;
      ppcVar18 = ppcVar18 + 1;
      goto LAB_00474fa4;
    }
    iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-rand");
    if (iVar9 == 0) {
      local_94 = ppcVar18[1];
      param_1 = param_1 + -1;
      ppcVar18 = ppcVar18 + 1;
      goto LAB_00474fa4;
    }
    iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-policy");
    if (iVar9 == 0) {
      local_90 = ppcVar18[1];
      param_1 = param_1 + -1;
      ppcVar18 = ppcVar18 + 1;
      goto LAB_00474fa4;
    }
    iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-no_nonce");
    if (iVar9 == 0) {
      bVar21 = true;
      goto LAB_00474fa4;
    }
    iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-cert");
    if (iVar9 == 0) {
      local_60 = 1;
      goto LAB_00474fa4;
    }
    if (((*pcVar22 == '-') && (pcVar22[1] == 'i')) && ((pcVar22[2] == 'n' && (pcVar22[3] == '\0'))))
    {
      local_8c = ppcVar18[1];
      param_1 = param_1 + -1;
      ppcVar18 = ppcVar18 + 1;
      goto LAB_00474fa4;
    }
    iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-token_in");
    if (iVar9 == 0) {
      bVar2 = true;
      goto LAB_00474fa4;
    }
    iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,&DAT_00632edc);
    if (iVar9 == 0) {
      local_78 = ppcVar18[1];
      param_1 = param_1 + -1;
      ppcVar18 = ppcVar18 + 1;
      goto LAB_00474fa4;
    }
    iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-token_out");
    if (iVar9 == 0) {
      bVar5 = true;
      goto LAB_00474fa4;
    }
    iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-text");
    if (iVar9 == 0) {
      bVar3 = true;
      goto LAB_00474fa4;
    }
    iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-reply");
    if (iVar9 == 0) {
      bVar1 = iVar17 != 0;
      iVar17 = 2;
      if (bVar1) goto LAB_004754b8;
      param_1 = param_1 + -1;
      goto LAB_00474fa8;
    }
    iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-queryfile");
    if (iVar9 == 0) {
      local_88 = ppcVar18[1];
      param_1 = param_1 + -1;
      ppcVar18 = ppcVar18 + 1;
    }
    else {
      iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-passin");
      if (iVar9 == 0) {
        local_80 = ppcVar18[1];
        param_1 = param_1 + -1;
        ppcVar18 = ppcVar18 + 1;
      }
      else {
        iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-inkey");
        if (iVar9 == 0) {
          local_5c = ppcVar18[1];
          param_1 = param_1 + -1;
          ppcVar18 = ppcVar18 + 1;
        }
        else {
          iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-signer");
          if (iVar9 == 0) {
            local_58 = ppcVar18[1];
            param_1 = param_1 + -1;
            ppcVar18 = ppcVar18 + 1;
          }
          else {
            iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-chain");
            if (iVar9 == 0) {
              local_54 = ppcVar18[1];
              param_1 = param_1 + -1;
              ppcVar18 = ppcVar18 + 1;
              goto LAB_00474fa4;
            }
            iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-verify");
            if (iVar9 == 0) {
              bVar1 = iVar17 == 0;
              iVar17 = 3;
              if (bVar1) {
                param_1 = param_1 + -1;
                goto LAB_00474fa8;
              }
              goto LAB_004754b8;
            }
            iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-CApath");
            if (iVar9 == 0) {
              local_70 = ppcVar18[1];
              param_1 = param_1 + -1;
              ppcVar18 = ppcVar18 + 1;
            }
            else {
              iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-CAfile");
              if (iVar9 == 0) {
                local_6c = ppcVar18[1];
                param_1 = param_1 + -1;
                ppcVar18 = ppcVar18 + 1;
              }
              else {
                iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-untrusted");
                if (iVar9 == 0) {
                  local_50 = ppcVar18[1];
                  param_1 = param_1 + -1;
                  ppcVar18 = ppcVar18 + 1;
                }
                else {
                  iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar22,"-engine");
                  if (iVar9 == 0) {
                    local_4c = ppcVar18[1];
                    param_1 = param_1 + -1;
                    ppcVar18 = ppcVar18 + 1;
                  }
                  else {
                    local_7c = (*(code *)PTR_EVP_get_digestbyname_006a802c)(pcVar22 + 1);
                    if (local_7c == 0) goto LAB_004754b8;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_00474fa4:
  param_1 = param_1 + -1;
LAB_00474fa8:
  ppcVar18 = ppcVar18 + 1;
  goto joined_r0x00474f5c;
LAB_00475000:
  if (iVar17 == 1) {
    if (!bVar21) {
      iVar17 = app_RAND_load_file(0,*(undefined4 *)puVar6,1);
      if (iVar17 == 0) {
        if (local_94 != (char *)0x0) goto LAB_004759e0;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,
                   "warning, not much extra random data, consider using the -rand option\n");
      }
      else if (local_94 != (char *)0x0) {
LAB_004759e0:
        uVar20 = *(undefined4 *)puVar6;
        uVar13 = app_RAND_load_files(local_94);
        (*(code *)PTR_BIO_printf_006a7f38)(uVar20,"%ld semi-random bytes loaded\n",uVar13);
      }
    }
LAB_0047539c:
    if (local_a8 == (char *)0x0) {
      iVar17 = load_config_file(pcVar24);
      if (local_8c == (char *)0x0) {
        if (local_a0 == (char *)0x0) {
          iVar9 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdin_006aab20,0);
          goto LAB_00475d74;
        }
        iVar9 = 0;
LAB_004758ec:
        local_44 = 0;
        if (((local_7c == 0) &&
            (local_7c = (*(code *)PTR_EVP_get_digestbyname_006a802c)(&DAT_0064e19c), local_7c == 0))
           || (iVar19 = (*(code *)PTR_TS_REQ_new_006a8f88)(), iVar19 == 0)) {
          piVar28 = (int *)0x0;
          iVar25 = 0;
          piVar23 = (int *)0x0;
          iVar10 = 0;
          iVar19 = 0;
LAB_00475934:
          (*(code *)PTR_TS_REQ_free_006a8f4c)(iVar19);
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar6,"could not create query\n");
          iVar19 = 0;
          piVar27 = piVar28;
        }
        else {
          iVar10 = (*(code *)PTR_TS_REQ_set_version_006a8f8c)(iVar19,1);
          if (iVar10 == 0) {
            iVar25 = 0;
            piVar23 = (int *)0x0;
            iVar10 = 0;
            piVar28 = (int *)0x0;
            goto LAB_00475934;
          }
          iVar10 = (*(code *)PTR_TS_MSG_IMPRINT_new_006a8fb4)();
          if (iVar10 == 0) {
            piVar28 = (int *)0x0;
            iVar25 = 0;
            piVar23 = (int *)0x0;
            goto LAB_00475934;
          }
          piVar23 = (int *)(*(code *)PTR_X509_ALGOR_new_006a8fb8)();
          if (piVar23 == (int *)0x0) {
LAB_00475e88:
            iVar25 = 0;
            piVar28 = (int *)0x0;
            goto LAB_00475934;
          }
          uVar13 = (*(code *)PTR_EVP_MD_type_006a84cc)(local_7c);
          iVar25 = (*(code *)PTR_OBJ_nid2obj_006a8240)(uVar13);
          *piVar23 = iVar25;
          if (iVar25 == 0) goto LAB_00475e88;
          puVar15 = (undefined4 *)(*(code *)PTR_ASN1_TYPE_new_006a8fbc)();
          piVar23[1] = (int)puVar15;
          puVar7 = PTR_TS_MSG_IMPRINT_set_algo_006a8fc0;
          if (puVar15 == (undefined4 *)0x0) goto LAB_00475e88;
          *puVar15 = 5;
          iVar25 = (*(code *)puVar7)(iVar10,piVar23);
          if (((iVar25 == 0) ||
              (iVar25 = create_digest(iVar9,local_a0,local_7c,&local_44), iVar25 == 0)) ||
             ((iVar25 = (*(code *)PTR_TS_MSG_IMPRINT_set_msg_006a8fc8)(iVar10,local_44,iVar25),
              iVar25 == 0 ||
              (iVar25 = (*(code *)PTR_TS_REQ_set_msg_imprint_006a8fcc)(iVar19,iVar10), iVar25 == 0))
             )) goto LAB_00475e88;
          if (local_90 != (char *)0x0) {
            iVar25 = (*(code *)PTR_OBJ_txt2obj_006a8100)(local_90,0);
            if (iVar25 == 0) {
              piVar28 = (int *)0x0;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar6,"cannot convert %s to OID\n",local_90);
            }
            else {
              iVar14 = (*(code *)PTR_TS_REQ_set_policy_id_006a8fd0)(iVar19,iVar25);
              if (iVar14 != 0) goto LAB_00476158;
              piVar28 = (int *)0x0;
            }
            goto LAB_00475934;
          }
          iVar25 = 0;
LAB_00476158:
          piVar27 = (int *)0x0;
          if (!bVar21) {
            iVar14 = (*(code *)PTR_RAND_bytes_006a8d44)(local_40,8);
            if (iVar14 < 1) {
LAB_00476500:
              piVar27 = (int *)0x0;
            }
            else {
              if (local_40[0] == '\0') {
                if (local_40[1] == '\0') {
                  if (local_40[2] == '\0') {
                    if (local_40[3] == '\0') {
                      if (local_3c == '\0') {
                        if (local_3b == '\0') {
                          if (local_3a == '\0') {
                            iVar14 = 7;
                            if (local_39 == '\0') {
                              iVar14 = 8;
                            }
                          }
                          else {
                            iVar14 = 6;
                          }
                        }
                        else {
                          iVar14 = 5;
                        }
                      }
                      else {
                        iVar14 = 4;
                      }
                    }
                    else {
                      iVar14 = 3;
                    }
                  }
                  else {
                    iVar14 = 2;
                  }
                }
                else {
                  iVar14 = 1;
                }
              }
              else {
                iVar14 = 0;
              }
              piVar27 = (int *)(*(code *)PTR_ASN1_INTEGER_new_006a8260)();
              if (piVar27 == (int *)0x0) goto LAB_00476500;
              (*(code *)PTR_CRYPTO_free_006a7f88)(piVar27[2]);
              puVar7 = PTR_CRYPTO_malloc_006a8108;
              *piVar27 = 8 - iVar14;
              iVar16 = (*(code *)puVar7)(9 - iVar14,&DAT_006459ec,0x294);
              piVar27[2] = iVar16;
              if (iVar16 != 0) {
                (*(code *)PTR_memcpy_006aabf4)(iVar16,local_40 + iVar14,*piVar27);
                iVar14 = (*(code *)PTR_TS_REQ_set_nonce_006a8fd8)(iVar19,piVar27);
                piVar28 = piVar27;
                if (iVar14 == 0) goto LAB_00475934;
                goto LAB_00476168;
              }
            }
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar6,"could not create nonce\n");
            piVar28 = (int *)0x0;
            (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(piVar27);
            goto LAB_00475934;
          }
LAB_00476168:
          iVar14 = (*(code *)PTR_TS_REQ_set_cert_req_006a8fd4)(iVar19,local_60);
          piVar28 = piVar27;
          if (iVar14 == 0) goto LAB_00475934;
        }
        (*(code *)PTR_TS_MSG_IMPRINT_free_006a8f90)(iVar10);
        iVar10 = 0;
        (*(code *)PTR_X509_ALGOR_free_006a8f94)(piVar23);
        (*(code *)PTR_CRYPTO_free_006a7f88)(local_44);
        (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar25);
        (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(piVar27);
      }
      else {
LAB_004753c4:
        iVar10 = (*(code *)PTR_BIO_new_file_006a7fac)(local_8c,&DAT_006347ac);
        if (iVar10 == 0) {
          bVar21 = true;
          iVar25 = 0;
          iVar9 = 0;
          iVar19 = 0;
          goto LAB_00475450;
        }
        iVar9 = 0;
        iVar19 = (*(code *)PTR_d2i_TS_REQ_bio_006a8f5c)(iVar10,0);
      }
      if (iVar19 == 0) {
        bVar21 = true;
        iVar25 = 0;
      }
      else {
        if (local_78 == (char *)0x0) {
          iVar25 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
        }
        else {
          iVar25 = (*(code *)PTR_BIO_new_file_006a7fac)(local_78,&DAT_00632de8);
        }
        if (iVar25 == 0) {
          bVar21 = true;
        }
        else {
          pcVar26 = (code *)PTR_i2d_TS_REQ_bio_006a8f60;
          if (bVar3) {
            pcVar26 = (code *)PTR_TS_REQ_print_bio_006a8f64;
          }
          iVar14 = (*pcVar26)(iVar25,iVar19);
          bVar21 = iVar14 == 0;
        }
      }
    }
    else {
      if (local_a0 != (char *)0x0) {
LAB_004754b8:
        iVar17 = 0;
        bVar21 = true;
LAB_004754bc:
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar6,
                   "usage:\nts -query [-rand file%cfile%c...] [-config configfile] [-data file_to_hash] [-digest digest_bytes][-md2|-md4|-md5|-sha|-sha1|-mdc2|-ripemd160] [-policy object_id] [-no_nonce] [-cert] [-in request.tsq] [-out request.tsq] [-text]\n"
                   ,0x3a,0x3a);
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar6,
                   "or\nts -reply [-config configfile] [-section tsa_section] [-queryfile request.tsq] [-passin password] [-signer tsa_cert.pem] [-inkey private_key.pem] [-chain certs_file.pem] [-policy object_id] [-in response.tsr] [-token_in] [-out response.tsr] [-token_out] [-text] [-engine id]\n"
                  );
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar6,
                   "or\nts -verify [-data file_to_hash] [-digest digest_bytes] [-queryfile request.tsq] -in response.tsr [-token_in] -CApath ca_path -CAfile ca_file.pem -untrusted cert_file.pem\n"
                  );
        goto LAB_0047550c;
      }
      iVar17 = load_config_file(pcVar24);
      if (local_8c != (char *)0x0) goto LAB_004753c4;
      iVar9 = (*(code *)PTR_BIO_new_file_006a7fac)(local_a8,&DAT_006347ac);
LAB_00475d74:
      if (iVar9 != 0) goto LAB_004758ec;
      bVar21 = true;
      iVar25 = 0;
      iVar10 = 0;
      iVar19 = 0;
    }
LAB_00475450:
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar6);
    (*(code *)PTR_BIO_free_all_006a7f74)(iVar10);
    (*(code *)PTR_BIO_free_all_006a7f74)(iVar9);
    (*(code *)PTR_BIO_free_all_006a7f74)(iVar25);
    (*(code *)PTR_TS_REQ_free_006a8f4c)(iVar19);
  }
  else if (iVar17 == 2) {
    if ((local_80 != (char *)0x0) &&
       (iVar17 = app_passwd(*(undefined4 *)puVar6,local_80,0,&local_48,0), iVar17 == 0)) {
      iVar17 = 0;
      bVar21 = true;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"Error getting password.\n");
      goto LAB_0047550c;
    }
LAB_0047561c:
    iVar17 = load_config_file(pcVar24);
    uVar13 = local_48;
    if (local_8c == (char *)0x0) {
      bVar21 = true;
      if (local_88 == (char *)0x0) goto LAB_004754bc;
      if (iVar17 == 0) goto LAB_004754b8;
      if (bVar2) goto LAB_004754bc;
      iVar9 = (*(code *)PTR_BIO_new_file_006a7fac)(local_88,&DAT_006347ac);
      if (((iVar9 == 0) ||
          (iVar10 = (*(code *)PTR_TS_CONF_get_tsa_section_006a8f98)(iVar17,local_b4), iVar10 == 0))
         || (iVar19 = (*(code *)PTR_TS_RESP_CTX_new_006a8f9c)(), iVar19 == 0)) {
        iVar19 = 0;
LAB_00475b54:
        iVar25 = 0;
        iVar10 = 0;
        (*(code *)PTR_TS_RESP_free_006a8f54)(0);
        bVar21 = true;
        (*(code *)PTR_TS_RESP_CTX_free_006a8fa4)(iVar19);
        iVar19 = 0;
        (*(code *)PTR_BIO_free_all_006a7f74)(iVar9);
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar6,"Response is not generated.\n");
        goto LAB_00475794;
      }
      iVar25 = (*(code *)PTR_TS_CONF_set_serial_006a8fa0)(iVar17,iVar10,serial_cb,iVar19);
      if ((((((iVar25 == 0) ||
             (iVar25 = (*(code *)PTR_TS_CONF_set_crypto_device_006a8fdc)(iVar17,iVar10,local_4c),
             iVar25 == 0)) ||
            (iVar25 = (*(code *)PTR_TS_CONF_set_signer_cert_006a8fe0)(iVar17,iVar10,local_58,iVar19)
            , iVar25 == 0)) ||
           ((iVar25 = (*(code *)PTR_TS_CONF_set_certs_006a8fe4)(iVar17,iVar10,local_54,iVar19),
            iVar25 == 0 ||
            (iVar25 = (*(code *)PTR_TS_CONF_set_signer_key_006a8fe8)
                                (iVar17,iVar10,local_5c,uVar13,iVar19), iVar25 == 0)))) ||
          (iVar25 = (*(code *)PTR_TS_CONF_set_def_policy_006a8fec)(iVar17,iVar10,local_90,iVar19),
          iVar25 == 0)) ||
         ((((iVar25 = (*(code *)PTR_TS_CONF_set_policies_006a8ff0)(iVar17,iVar10,iVar19),
            iVar25 == 0 ||
            (iVar25 = (*(code *)PTR_TS_CONF_set_digests_006a8ff4)(iVar17,iVar10,iVar19), iVar25 == 0
            )) || ((iVar25 = (*(code *)PTR_TS_CONF_set_accuracy_006a8ff8)(iVar17,iVar10,iVar19),
                   iVar25 == 0 ||
                   (((iVar25 = (*(code *)PTR_TS_CONF_set_clock_precision_digits_006a8ffc)
                                         (iVar17,iVar10,iVar19), iVar25 == 0 ||
                     (iVar25 = (*(code *)PTR_TS_CONF_set_ordering_006a9000)(iVar17,iVar10,iVar19),
                     iVar25 == 0)) ||
                    (iVar25 = (*(code *)PTR_TS_CONF_set_tsa_name_006a9004)(iVar17,iVar10,iVar19),
                    iVar25 == 0)))))) ||
          ((iVar10 = (*(code *)PTR_TS_CONF_set_ess_cert_id_chain_006a9008)(iVar17,iVar10,iVar19),
           iVar10 == 0 ||
           (iVar10 = (*(code *)PTR_TS_RESP_create_response_006a900c)(iVar19,iVar9), iVar10 == 0)))))
         ) goto LAB_00475b54;
      (*(code *)PTR_TS_RESP_CTX_free_006a8fa4)(iVar19);
      iVar19 = 0;
      (*(code *)PTR_BIO_free_all_006a7f74)(iVar9);
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar6,"Response has been generated.\n");
LAB_00475730:
      if (local_78 == (char *)0x0) {
        iVar25 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
      }
      else {
        iVar25 = (*(code *)PTR_BIO_new_file_006a7fac)(local_78,&DAT_00632de8);
      }
      if (iVar25 == 0) {
        bVar21 = true;
      }
      else if (bVar3) {
        pcVar26 = (code *)PTR_TS_RESP_print_bio_006a8f7c;
        if (bVar5) {
          uVar13 = (*(code *)PTR_TS_RESP_get_tst_info_006a8f80)(iVar10);
          iVar9 = (*(code *)PTR_TS_TST_INFO_print_bio_006a8f84)(iVar25,uVar13);
          bVar21 = iVar9 == 0;
        }
        else {
LAB_00475ed8:
          iVar9 = (*pcVar26)(iVar25,iVar10);
          bVar21 = iVar9 == 0;
        }
      }
      else {
        pcVar26 = (code *)PTR_i2d_TS_RESP_bio_006a8fa8;
        if (!bVar5) goto LAB_00475ed8;
        uVar13 = (*(code *)PTR_TS_RESP_get_token_006a8fac)(iVar10);
        iVar9 = (*(code *)PTR_i2d_PKCS7_bio_006a869c)(iVar25,uVar13);
        bVar21 = iVar9 == 0;
      }
    }
    else {
      bVar21 = local_88 != (char *)0x0;
      if (local_88 != (char *)0x0) goto LAB_004754bc;
      iVar19 = (*(code *)PTR_BIO_new_file_006a7fac)(local_8c,&DAT_006347ac);
      if (iVar19 == 0) {
        bVar21 = true;
        iVar25 = 0;
        iVar10 = 0;
      }
      else {
        if (bVar2) {
          iVar9 = (*(code *)PTR_d2i_PKCS7_bio_006a86a4)(iVar19,0);
          if (iVar9 == 0) {
            puVar15 = (undefined4 *)0x0;
            iVar10 = 0;
            iVar25 = 0;
LAB_004756e4:
            (*(code *)PTR_PKCS7_free_006a8350)(iVar9);
            (*(code *)PTR_TS_TST_INFO_free_006a8f74)(iVar25);
            (*(code *)PTR_TS_RESP_free_006a8f54)(iVar10);
            iVar10 = 0;
          }
          else {
            iVar25 = (*(code *)PTR_PKCS7_to_TS_TST_INFO_006a8f68)(iVar9);
            if (iVar25 == 0) {
              puVar15 = (undefined4 *)0x0;
              iVar10 = 0;
              goto LAB_004756e4;
            }
            iVar10 = (*(code *)PTR_TS_RESP_new_006a8f6c)();
            if (iVar10 == 0) {
              puVar15 = (undefined4 *)0x0;
              goto LAB_004756e4;
            }
            puVar15 = (undefined4 *)(*(code *)PTR_TS_STATUS_INFO_new_006a8f70)();
            if (((puVar15 == (undefined4 *)0x0) ||
                (iVar14 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(*puVar15,0), iVar14 == 0)) ||
               (iVar14 = (*(code *)PTR_TS_RESP_set_status_info_006a9010)(iVar10,puVar15),
               iVar14 == 0)) goto LAB_004756e4;
            (*(code *)PTR_TS_RESP_set_tst_info_006a9014)(iVar10,iVar9,iVar25);
            (*(code *)PTR_PKCS7_free_006a8350)(0);
            (*(code *)PTR_TS_TST_INFO_free_006a8f74)(0);
          }
          (*(code *)PTR_TS_STATUS_INFO_free_006a8f78)(puVar15);
        }
        else {
          iVar10 = (*(code *)PTR_d2i_TS_RESP_bio_006a8f40)(iVar19,0);
        }
        if (iVar10 != 0) goto LAB_00475730;
        bVar21 = true;
        iVar25 = 0;
      }
    }
LAB_00475794:
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar6);
    (*(code *)PTR_BIO_free_all_006a7f74)(iVar19);
    (*(code *)PTR_BIO_free_all_006a7f74)(0);
    (*(code *)PTR_BIO_free_all_006a7f74)(0);
    (*(code *)PTR_BIO_free_all_006a7f74)(0);
    (*(code *)PTR_BIO_free_all_006a7f74)(iVar25);
    (*(code *)PTR_TS_RESP_free_006a8f54)(iVar10);
  }
  else {
    if (iVar17 == 1) goto LAB_0047539c;
    if (iVar17 == 0) goto LAB_004754b8;
    if (iVar17 == 2) goto LAB_0047561c;
    if (iVar17 != 3) {
      iVar17 = 0;
      bVar21 = true;
      goto LAB_0047550c;
    }
    if ((((local_88 != (char *)0x0) && (local_a8 != (char *)0x0)) || (local_a0 == (char *)0x0)) ||
       (local_8c == (char *)0x0)) goto LAB_004754b8;
    iVar17 = (*(code *)PTR_BIO_new_file_006a7fac)(local_8c,&DAT_006347ac);
    if (iVar17 == 0) {
LAB_00475a70:
      iVar9 = 0;
      iVar10 = 0;
LAB_00475a78:
      puVar11 = (uint *)0x0;
      (*(code *)PTR___printf_chk_006aaad0)(1,"Verification: ");
LAB_00475a94:
      bVar21 = true;
      (*(code *)PTR_puts_006aab60)("FAILED");
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar6);
    }
    else {
      if (bVar2) {
        iVar10 = (*(code *)PTR_d2i_PKCS7_bio_006a86a4)(iVar17,0);
        if (iVar10 == 0) goto LAB_00475a70;
        iVar9 = 0;
      }
      else {
        iVar9 = (*(code *)PTR_d2i_TS_RESP_bio_006a8f40)(iVar17,0);
        if (iVar9 == 0) goto LAB_00475a70;
        iVar10 = 0;
      }
      if (local_a8 == (char *)0x0) {
        if (local_a0 == (char *)0x0) {
          if (local_88 == (char *)0x0) goto LAB_00475a78;
          iVar19 = (*(code *)PTR_BIO_new_file_006a7fac)(local_88,&DAT_006347ac);
          if (iVar19 == 0) goto LAB_00475c2c;
          iVar25 = (*(code *)PTR_d2i_TS_REQ_bio_006a8f5c)(iVar19,0);
          if (iVar25 == 0) {
            puVar11 = (uint *)0x0;
          }
          else {
            puVar11 = (uint *)(*(code *)PTR_TS_REQ_to_TS_VERIFY_CTX_006a8fc4)(iVar25,0);
            if (puVar11 != (uint *)0x0) goto LAB_004750e8;
          }
        }
        else {
          puVar11 = (uint *)(*(code *)PTR_TS_VERIFY_CTX_new_006a8f44)();
          puVar7 = PTR_string_to_hex_006a848c;
          if (puVar11 == (uint *)0x0) goto LAB_00475c2c;
          *puVar11 = 0x4a;
          uVar12 = (*(code *)puVar7)(local_a0,&local_44);
          puVar11[5] = uVar12;
          if (uVar12 != 0) {
            iVar25 = 0;
            iVar19 = 0;
            puVar11[6] = local_44;
            goto LAB_004750e8;
          }
          iVar25 = 0;
          iVar19 = 0;
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar6,"invalid digest string\n");
        }
LAB_00475c3c:
        (*(code *)PTR_TS_VERIFY_CTX_free_006a8f58)(puVar11);
        (*(code *)PTR_BIO_free_all_006a7f74)(iVar19);
        (*(code *)PTR_TS_REQ_free_006a8f4c)(iVar25);
        goto LAB_00475a78;
      }
      puVar11 = (uint *)(*(code *)PTR_TS_VERIFY_CTX_new_006a8f44)();
      puVar7 = PTR_BIO_new_file_006a7fac;
      if (puVar11 == (uint *)0x0) {
LAB_00475c2c:
        iVar25 = 0;
        iVar19 = 0;
        puVar11 = (uint *)0x0;
        goto LAB_00475c3c;
      }
      iVar25 = 0;
      *puVar11 = 0x52;
      iVar19 = 0;
      uVar12 = (*(code *)puVar7)(local_a8,&DAT_006347ac);
      puVar11[7] = uVar12;
      if (uVar12 == 0) goto LAB_00475c3c;
LAB_004750e8:
      puVar7 = PTR_X509_STORE_new_006a8364;
      *puVar11 = *puVar11 | 1;
      uVar12 = (*(code *)puVar7)();
      (*(code *)PTR_X509_STORE_set_verify_cb_006a83f8)(uVar12,verify_cb);
      if (local_70 != (char *)0x0) {
        uVar13 = (*(code *)PTR_X509_LOOKUP_hash_dir_006a858c)();
        iVar14 = (*(code *)PTR_X509_STORE_add_lookup_006a8584)(uVar12,uVar13);
        if (iVar14 == 0) {
LAB_00476070:
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar6,"memory allocation failure\n");
        }
        else {
          iVar14 = (*(code *)PTR_X509_LOOKUP_ctrl_006a8588)(iVar14,2,local_70,1,0);
          if (iVar14 != 0) goto LAB_00475170;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar6,"Error loading directory %s\n",local_70);
        }
LAB_00475f54:
        (*(code *)PTR_X509_STORE_free_006a8384)(uVar12);
        puVar11[1] = 0;
        goto LAB_00475c3c;
      }
LAB_00475170:
      if (local_6c != (char *)0x0) {
        uVar13 = (*(code *)PTR_X509_LOOKUP_file_006a8580)();
        iVar14 = (*(code *)PTR_X509_STORE_add_lookup_006a8584)(uVar12,uVar13);
        if (iVar14 == 0) goto LAB_00476070;
        iVar14 = (*(code *)PTR_X509_LOOKUP_ctrl_006a8588)(iVar14,1,local_6c,1,0);
        if (iVar14 == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar6,"Error loading file %s\n",local_6c);
          goto LAB_00475f54;
        }
      }
      puVar11[1] = uVar12;
      if (uVar12 == 0) goto LAB_00475c3c;
      if (local_50 != (char *)0x0) {
        uVar12 = (*(code *)PTR_TS_CONF_load_certs_006a8f48)(local_50);
        puVar11[2] = uVar12;
        if (uVar12 == 0) goto LAB_00475c3c;
      }
      (*(code *)PTR_BIO_free_all_006a7f74)(iVar19);
      (*(code *)PTR_TS_REQ_free_006a8f4c)(iVar25);
      if (bVar2) {
        iVar19 = (*(code *)PTR_TS_RESP_verify_token_006a8f50)(puVar11,iVar10);
      }
      else {
        iVar19 = (*(code *)PTR_TS_RESP_verify_response_006a8fb0)(puVar11,iVar9);
      }
      (*(code *)PTR___printf_chk_006aaad0)(1,"Verification: ");
      if (iVar19 == 0) goto LAB_00475a94;
      bVar21 = false;
      (*(code *)PTR_puts_006aab60)(&DAT_00645b94);
    }
    (*(code *)PTR_BIO_free_all_006a7f74)(iVar17);
    (*(code *)PTR_PKCS7_free_006a8350)(iVar10);
    (*(code *)PTR_TS_RESP_free_006a8f54)(iVar9);
    iVar17 = 0;
    (*(code *)PTR_TS_VERIFY_CTX_free_006a8f58)(puVar11);
  }
LAB_0047550c:
  app_RAND_write_file(0,*(undefined4 *)puVar6);
  (*(code *)PTR_NCONF_free_006a7f6c)(iVar17);
  (*(code *)PTR_CRYPTO_free_006a7f88)(local_48);
  (*(code *)PTR_OBJ_cleanup_006a7f98)();
  if (bVar4) goto LAB_00475558;
  goto LAB_00474eb0;
}

