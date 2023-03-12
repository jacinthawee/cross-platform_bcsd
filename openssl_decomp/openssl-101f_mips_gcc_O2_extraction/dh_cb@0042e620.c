
int dh_cb(int param_1,undefined4 param_2,int param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  char **ppcVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  int iVar10;
  char *pcVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  int iVar14;
  int unaff_s2;
  undefined4 unaff_s4;
  undefined4 unaff_s5;
  char *unaff_s6;
  char **unaff_s7;
  code *pcVar15;
  int unaff_s8;
  undefined4 uStack_1d0;
  char acStack_1cc [256];
  int iStack_cc;
  int iStack_c8;
  char *pcStack_c4;
  int iStack_c0;
  undefined *puStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  char *pcStack_b0;
  char **ppcStack_ac;
  int iStack_a8;
  undefined4 uStack_a4;
  undefined *puStack_90;
  char *pcStack_84;
  int *piStack_80;
  char *pcStack_7c;
  char *pcStack_78;
  char *pcStack_74;
  char *pcStack_6c;
  undefined4 uStack_68;
  int iStack_64;
  code *pcStack_60;
  int iStack_5c;
  undefined *puStack_58;
  int iStack_54;
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
  (*(code *)PTR_BIO_write_006a7f14)(*(undefined4 *)(param_3 + 4),&local_15,1);
  pcStack_c4 = &DAT_0000000b;
  (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)(param_3 + 4),0xb,0,0);
  if (local_14 == *(int *)puStack_58) {
    return 1;
  }
  iVar4 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_bc = PTR_bio_err_006a7f3c;
  puStack_90 = &_gp;
  piStack_80 = (int *)PTR___stack_chk_guard_006aabf0;
  pcStack_6c = (char *)0x200;
  iStack_5c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_54 = param_3;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar10 = *(int *)puStack_bc;
  uStack_68 = 2;
  pcStack_60 = dh_cb;
  iStack_64 = iVar10;
  if (iVar10 == 0) {
    uVar5 = (**(code **)(puStack_90 + -0x7f40))();
    iVar10 = (**(code **)(puStack_90 + -0x7f3c))(uVar5);
    *(int *)puStack_bc = iVar10;
    if (iVar10 != 0) {
      (**(code **)(puStack_90 + -0x7fc8))(iVar10,0x6a,0x10,**(undefined4 **)(puStack_90 + -0x52e0));
      iVar10 = *(int *)puStack_bc;
    }
  }
  pcVar11 = (char *)0x0;
  iVar10 = (**(code **)(puStack_90 + -0x7f7c))(iVar10);
  if (iVar10 != 0) {
    unaff_s8 = iVar4 + -1;
    unaff_s7 = (char **)(pcStack_c4 + 4);
    if (0 < unaff_s8) {
      pcStack_78 = (char *)0x0;
      pcStack_7c = (char *)0x0;
      pcStack_c4 = (char *)0x0;
      unaff_s5 = 2;
      pcStack_84 = "-engine";
      unaff_s2 = 0x2d;
      unaff_s4 = 0x32;
      pcStack_74 = "-rand";
LAB_0042e808:
      unaff_s6 = *unaff_s7;
      iVar4 = (**(code **)(puStack_90 + -0x52c0))(unaff_s6,&DAT_00632edc);
      if (iVar4 == 0) {
        unaff_s8 = unaff_s8 + -1;
        ppcVar3 = unaff_s7 + 1;
        if (unaff_s8 != 0) {
          pcStack_c4 = unaff_s7[1];
          goto LAB_0042e7fc;
        }
      }
      else {
        if (*unaff_s6 == '-') {
          ppcVar3 = unaff_s7;
          if (unaff_s6[1] == '2') {
            if (unaff_s6[2] != '\0') goto LAB_0042e830;
            unaff_s5 = 2;
          }
          else {
            pcVar15 = *(code **)(puStack_90 + -0x52c0);
            if ((unaff_s6[1] != '5') || (unaff_s6[2] != '\0')) goto LAB_0042e834;
            unaff_s5 = 5;
          }
LAB_0042e7fc:
          unaff_s8 = unaff_s8 + -1;
          unaff_s7 = ppcVar3 + 1;
          if (unaff_s8 == 0) goto LAB_0042ea18;
          goto LAB_0042e808;
        }
LAB_0042e830:
        pcVar15 = *(code **)(puStack_90 + -0x52c0);
LAB_0042e834:
        iVar4 = (*pcVar15)(unaff_s6,pcStack_84);
        if (iVar4 == 0) {
          unaff_s8 = unaff_s8 + -1;
          if (unaff_s8 != 0) {
            pcStack_78 = unaff_s7[1];
            ppcVar3 = unaff_s7 + 1;
            goto LAB_0042e7fc;
          }
        }
        else {
          iVar4 = (**(code **)(puStack_90 + -0x52c0))(unaff_s6,pcStack_74);
          if (iVar4 == 0) {
            unaff_s8 = unaff_s8 + -1;
            if (unaff_s8 != 0) {
              pcStack_7c = unaff_s7[1];
              ppcVar3 = unaff_s7 + 1;
              goto LAB_0042e7fc;
            }
            goto LAB_0042e884;
          }
          iVar4 = (**(code **)(puStack_90 + -0x53d0))(unaff_s6,"%d",&pcStack_6c);
          if ((iVar4 != 0) && (-1 < (int)pcStack_6c)) goto LAB_0042ea18;
        }
      }
LAB_0042e884:
      (**(code **)(puStack_90 + -0x7fa8))
                (*(undefined4 *)puStack_bc,"usage: gendh [args] [numbits]\n");
      (**(code **)(puStack_90 + -0x7fa8))
                (*(undefined4 *)puStack_bc," -out file - output the key to \'file\n");
      (**(code **)(puStack_90 + -0x7fa8))
                (*(undefined4 *)puStack_bc," -2        - use 2 as the generator value\n");
      (**(code **)(puStack_90 + -0x7fa8))
                (*(undefined4 *)puStack_bc," -5        - use 5 as the generator value\n");
      (**(code **)(puStack_90 + -0x7fa8))
                (*(undefined4 *)puStack_bc,
                 " -engine e - use engine e, possibly a hardware device.\n");
      (**(code **)(puStack_90 + -0x7fa8))
                (*(undefined4 *)puStack_bc," -rand file%cfile%c...\n",0x3a,0x3a);
      (**(code **)(puStack_90 + -0x7fa8))
                (*(undefined4 *)puStack_bc,
                 "           - load the file (or the files in the directory) into\n");
      pcVar11 = "             the random number generator\n";
      (**(code **)(puStack_90 + -0x7fa8))(*(undefined4 *)puStack_bc);
      goto LAB_0042e948;
    }
    pcVar11 = (char *)0x0;
    (**(code **)(puStack_90 + -0x7f1c))(*(undefined4 *)puStack_bc,0,0);
    uVar5 = (**(code **)(puStack_90 + -0x7f40))();
    unaff_s2 = (**(code **)(puStack_90 + -0x7f3c))(uVar5);
    if (unaff_s2 != 0) {
      unaff_s5 = 2;
      pcStack_7c = (char *)0x0;
      goto LAB_0042ec2c;
    }
    goto LAB_0042eccc;
  }
LAB_0042e948:
  iStack_c8 = 1;
  (**(code **)(puStack_90 + -0x7fa0))(*(undefined4 *)puStack_bc);
LAB_0042e95c:
  if (iStack_5c == *piStack_80) {
    return iStack_c8;
  }
  uStack_a4 = 0x42ed0c;
  iVar4 = iStack_5c;
  (**(code **)(puStack_90 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar1 = PTR_bio_err_006a7f3c;
  pcVar6 = (char *)0x1;
  iStack_cc = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_c0 = unaff_s2;
  uStack_b8 = unaff_s4;
  uStack_b4 = unaff_s5;
  pcStack_b0 = unaff_s6;
  ppcStack_ac = unaff_s7;
  iStack_a8 = unaff_s8;
  (*(code *)PTR_signal_006aabe0)(0xd);
  if (*(int *)puVar1 == 0) {
    uVar5 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar10 = (*(code *)PTR_BIO_new_006a7fa4)(uVar5);
    *(int *)puVar1 = iVar10;
    if (iVar10 != 0) {
      pcVar6 = &DAT_0000006a;
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar10,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
    }
  }
  (*(code *)PTR_SSL_load_error_strings_006a867c)();
  if (iVar4 < 2) {
LAB_0042ef24:
    iVar10 = 0;
  }
  else {
    pcVar6 = "-stats";
    iVar10 = (*(code *)PTR_strcmp_006aac20)(*(undefined4 *)(pcVar11 + 4));
    if (iVar10 == 0) {
      uVar5 = (*(code *)PTR_BIO_s_file_006a7fa0)();
      pcVar8 = (char *)(*(code *)PTR_BIO_new_006a7fa4)(uVar5);
      if (pcVar8 != (char *)0x0) {
        pcVar6 = &DAT_0000006a;
        iVar10 = (*(code *)PTR_BIO_ctrl_006a7f18)(pcVar8,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
        if (iVar10 != 0) {
          uVar5 = (*(code *)PTR_ERR_get_string_table_006a8684)();
          (*(code *)PTR_lh_node_stats_bio_006a8688)(uVar5,pcVar8);
          uVar5 = (*(code *)PTR_ERR_get_string_table_006a8684)();
          (*(code *)PTR_lh_stats_bio_006a868c)(uVar5,pcVar8);
          uVar5 = (*(code *)PTR_ERR_get_string_table_006a8684)();
          pcVar6 = pcVar8;
          (*(code *)PTR_lh_node_usage_stats_bio_006a8690)(uVar5);
        }
        (*(code *)PTR_BIO_free_all_006a7f74)(pcVar8);
      }
      iVar4 = iVar4 + -1;
      pcVar11 = pcVar11 + 4;
      if (iVar4 == 1) goto LAB_0042ef24;
    }
    puVar13 = (undefined4 *)(pcVar11 + 4);
    iVar10 = 0;
    iVar14 = 1;
    do {
      while (iVar7 = (*(code *)PTR___isoc99_sscanf_006aab10)(*puVar13,&DAT_006359e0,&uStack_1d0),
            iVar7 != 0) {
        iVar14 = iVar14 + 1;
        puVar13 = puVar13 + 1;
        pcVar6 = acStack_1cc;
        (*(code *)PTR_ERR_error_string_n_006a8680)(uStack_1d0,acStack_1cc,0x100);
        (*(code *)PTR_puts_006aab60)(acStack_1cc);
        if (iVar4 <= iVar14) goto LAB_0042ee74;
      }
      iVar14 = iVar14 + 1;
      iVar10 = iVar10 + 1;
      pcVar6 = "%s: bad error code\n";
      (*(code *)PTR___printf_chk_006aaad0)(1,"%s: bad error code\n",*puVar13);
      puVar13 = puVar13 + 1;
      (*(code *)PTR_puts_006aab60)("usage: errstr [-stats] <errno> ...");
    } while (iVar14 < iVar4);
  }
LAB_0042ee74:
  if (iStack_cc == *(int *)puVar2) {
    return iVar10;
  }
  iVar4 = iStack_cc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar4 == 2) {
    iVar4 = (*(code *)PTR_OBJ_txt2obj_006a8100)(pcVar6,0);
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar4);
    if (iVar4 == 0) {
      pcVar11 = "Invalid object identifier %s\n";
LAB_0042f13c:
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,pcVar11,pcVar6);
      return 0;
    }
    pcVar11 = "holdInstruction";
LAB_0042f1d8:
    piVar9 = (int *)(*(code *)PTR_X509_gmtime_adj_006a808c)(0,0);
    iVar4 = (*(code *)PTR_strlen_006aab30)(pcVar11);
    iVar4 = *piVar9 + 2 + iVar4;
    if (pcVar6 == (char *)0x0) {
LAB_0042f3a4:
      iVar10 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar4,&DAT_00635b2c,0xae1);
      if (iVar10 == 0) {
        return 0;
      }
      (*(code *)PTR_BUF_strlcpy_006a8064)(iVar10,piVar9[2],iVar4);
      if (pcVar11 == (char *)0x0) goto LAB_0042f2cc;
      pcVar6 = (char *)0x0;
    }
    else {
      iVar10 = (*(code *)PTR_strlen_006aab30)(pcVar6);
      iVar4 = iVar4 + 1 + iVar10;
      iVar10 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar4,&DAT_00635b2c,0xae1);
      if (iVar10 == 0) {
        return 0;
      }
      (*(code *)PTR_BUF_strlcpy_006a8064)(iVar10,piVar9[2],iVar4);
    }
    (*(code *)PTR_BUF_strlcat_006a8068)(iVar10,",",iVar4);
    (*(code *)PTR_BUF_strlcat_006a8068)(iVar10,pcVar11,iVar4);
    if (pcVar6 != (char *)0x0) {
      (*(code *)PTR_BUF_strlcat_006a8068)(iVar10,",",iVar4);
      (*(code *)PTR_BUF_strlcat_006a8068)(iVar10,pcVar6,iVar4);
    }
  }
  else {
    if (iVar4 < 3) {
      if (iVar4 == 1) {
        iVar4 = (*(code *)PTR_strcasecmp_006aab24)(pcVar6,"unspecified");
        if (iVar4 == 0) {
          pcVar11 = "unspecified";
        }
        else {
          iVar4 = (*(code *)PTR_strcasecmp_006aab24)(pcVar6,"keyCompromise");
          if (iVar4 == 0) {
            pcVar11 = "keyCompromise";
          }
          else {
            iVar4 = (*(code *)PTR_strcasecmp_006aab24)(pcVar6,"CACompromise");
            if (iVar4 == 0) {
              pcVar11 = "CACompromise";
            }
            else {
              iVar4 = (*(code *)PTR_strcasecmp_006aab24)(pcVar6,"affiliationChanged");
              if (iVar4 == 0) {
                pcVar11 = "affiliationChanged";
              }
              else {
                iVar4 = (*(code *)PTR_strcasecmp_006aab24)(pcVar6,"superseded");
                if (iVar4 == 0) {
                  pcVar11 = "superseded";
                }
                else {
                  iVar4 = (*(code *)PTR_strcasecmp_006aab24)(pcVar6,"cessationOfOperation");
                  if (iVar4 == 0) {
                    pcVar11 = "cessationOfOperation";
                  }
                  else {
                    iVar4 = (*(code *)PTR_strcasecmp_006aab24)(pcVar6,"certificateHold");
                    if (iVar4 == 0) {
                      pcVar11 = "certificateHold";
                    }
                    else {
                      iVar4 = (*(code *)PTR_strcasecmp_006aab24)(pcVar6,"removeFromCRL");
                      if (iVar4 != 0) {
                        pcVar11 = "Unknown CRL reason %s\n";
                        goto LAB_0042f13c;
                      }
                      pcVar11 = "removeFromCRL";
                    }
                  }
                }
              }
            }
          }
        }
        piVar9 = (int *)(*(code *)PTR_X509_gmtime_adj_006a808c)(0,0);
        iVar4 = (*(code *)PTR_strlen_006aab30)(pcVar11);
        iVar4 = *piVar9 + 2 + iVar4;
        goto LAB_0042f3a4;
      }
    }
    else if (iVar4 < 5) {
      iVar10 = (*(code *)PTR_ASN1_GENERALIZEDTIME_set_string_006a80fc)(0);
      if (iVar10 == 0) {
        pcVar11 = "Invalid time format %s. Need YYYYMMDDHHMMSSZ\n";
        goto LAB_0042f13c;
      }
      if (iVar4 == 3) {
        pcVar11 = "keyTime";
      }
      else {
        pcVar11 = "CAkeyTime";
      }
      goto LAB_0042f1d8;
    }
    piVar9 = (int *)(*(code *)PTR_X509_gmtime_adj_006a808c)(0,0);
    iVar4 = *piVar9;
    iVar10 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar4 + 1,&DAT_00635b2c,0xae1);
    if (iVar10 == 0) {
      return 0;
    }
    (*(code *)PTR_BUF_strlcpy_006a8064)(iVar10,piVar9[2],iVar4 + 1);
  }
LAB_0042f2cc:
  (*(code *)PTR_ASN1_UTCTIME_free_006a810c)(piVar9);
  return iVar10;
LAB_0042ea18:
  pcVar11 = pcStack_78;
  (**(code **)(puStack_90 + -0x7f1c))(*(undefined4 *)puStack_bc,pcStack_78,0);
  uVar5 = (**(code **)(puStack_90 + -0x7f40))();
  unaff_s2 = (**(code **)(puStack_90 + -0x7f3c))(uVar5);
  if (unaff_s2 == 0) {
LAB_0042eccc:
    (**(code **)(puStack_90 + -0x7fa0))(*(undefined4 *)puStack_bc);
    goto LAB_0042e948;
  }
  if (pcStack_c4 == (char *)0x0) {
LAB_0042ec2c:
    (**(code **)(puStack_90 + -0x7fc8))(unaff_s2,0x6a,0,**(undefined4 **)(puStack_90 + -0x540c));
LAB_0042ea7c:
    iVar4 = (**(code **)(puStack_90 + -0x7f14))(0,*(undefined4 *)puStack_bc,1);
    if (iVar4 == 0) {
      pcVar15 = *(code **)(puStack_90 + -0x7ea8);
      if (pcStack_7c == (char *)0x0) {
        (**(code **)(puStack_90 + -0x7fa8))
                  (**(undefined4 **)(puStack_90 + -0x7fa4),
                   "warning, not much extra random data, consider using the -rand option\n");
      }
      else {
LAB_0042eaa8:
        uVar12 = *(undefined4 *)puStack_bc;
        uVar5 = (*pcVar15)(pcStack_7c);
        (**(code **)(puStack_90 + -0x7fa8))(uVar12,"%ld semi-random bytes loaded\n",uVar5);
      }
    }
    else {
      pcVar15 = *(code **)(puStack_90 + -0x7ea8);
      if (pcStack_7c != (char *)0x0) goto LAB_0042eaa8;
    }
    puVar13 = *(undefined4 **)(puStack_90 + -0x7fa4);
    (**(code **)(puStack_90 + -0x7fa8))
              (*(undefined4 *)puStack_bc,
               "Generating DH parameters, %d bit long safe prime, generator %d\n",pcStack_6c,
               unaff_s5);
    pcVar11 = "This is going to take a long time\n";
    (**(code **)(puStack_90 + -0x7fa8))(*(undefined4 *)puStack_bc);
    pcVar6 = (char *)(**(code **)(puStack_90 + -0x78c8))();
    if (pcVar6 == (char *)0x0) {
      iStack_c8 = 1;
      (**(code **)(puStack_90 + -0x7fa0))(*puVar13);
    }
    else {
      pcVar11 = pcStack_6c;
      iVar4 = (**(code **)(puStack_90 + -0x78b0))(pcVar6,pcStack_6c,unaff_s5,&uStack_68);
      if (iVar4 != 0) {
        (**(code **)(puStack_90 + -0x7e94))(0,*puVar13);
        pcVar11 = pcVar6;
        iVar4 = (**(code **)(puStack_90 + -0x78c0))(unaff_s2);
        if (iVar4 != 0) {
          iStack_c8 = 0;
          goto LAB_0042eb58;
        }
      }
      iStack_c8 = 1;
      (**(code **)(puStack_90 + -0x7fa0))(*(undefined4 *)puStack_bc);
    }
  }
  else {
    pcVar11 = &DAT_0000006c;
    iVar4 = (**(code **)(puStack_90 + -0x7fc8))(unaff_s2,0x6c,5,pcStack_c4);
    if (0 < iVar4) goto LAB_0042ea7c;
    iStack_c8 = 1;
    pcVar6 = (char *)0x0;
    (**(code **)(puStack_90 + -0x5358))(pcStack_c4);
    (**(code **)(puStack_90 + -0x7fa0))(**(undefined4 **)(puStack_90 + -0x7fa4));
  }
LAB_0042eb58:
  (**(code **)(puStack_90 + -0x7f6c))(unaff_s2);
  pcStack_c4 = pcVar6;
  if (pcVar6 != (char *)0x0) {
    (**(code **)(puStack_90 + -0x78dc))(pcVar6);
  }
  goto LAB_0042e95c;
}

