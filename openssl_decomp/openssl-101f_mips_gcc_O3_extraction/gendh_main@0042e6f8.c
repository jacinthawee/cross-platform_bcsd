
int gendh_main(int param_1,char *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  char **ppcVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
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
  undefined4 uStack_1a0;
  char acStack_19c [256];
  int iStack_9c;
  int iStack_98;
  char *pcStack_94;
  int iStack_90;
  undefined *puStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  char *pcStack_80;
  char **ppcStack_7c;
  int iStack_78;
  undefined4 uStack_74;
  undefined *local_60;
  char *local_54;
  int *local_50;
  char *local_4c;
  char *local_48;
  char *local_44;
  char *local_3c;
  undefined4 local_38;
  int local_34;
  code *local_30;
  int local_2c;
  
  puStack_8c = PTR_bio_err_006a7f3c;
  local_60 = &_gp;
  local_50 = (int *)PTR___stack_chk_guard_006aabf0;
  local_3c = (char *)0x200;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar10 = *(int *)puStack_8c;
  local_38 = 2;
  local_30 = dh_cb;
  local_34 = iVar10;
  if (iVar10 == 0) {
    uVar4 = (**(code **)(local_60 + -0x7f40))();
    iVar10 = (**(code **)(local_60 + -0x7f3c))(uVar4);
    *(int *)puStack_8c = iVar10;
    if (iVar10 != 0) {
      (**(code **)(local_60 + -0x7fc8))(iVar10,0x6a,0x10,**(undefined4 **)(local_60 + -0x52e0));
      iVar10 = *(int *)puStack_8c;
    }
  }
  pcVar11 = (char *)0x0;
  iVar10 = (**(code **)(local_60 + -0x7f7c))(iVar10);
  if (iVar10 != 0) {
    unaff_s8 = param_1 + -1;
    unaff_s7 = (char **)(param_2 + 4);
    if (0 < unaff_s8) {
      local_48 = (char *)0x0;
      local_4c = (char *)0x0;
      param_2 = (char *)0x0;
      unaff_s5 = 2;
      local_54 = "-engine";
      unaff_s2 = 0x2d;
      unaff_s4 = 0x32;
      local_44 = "-rand";
LAB_0042e808:
      unaff_s6 = *unaff_s7;
      iVar10 = (**(code **)(local_60 + -0x52c0))(unaff_s6,&DAT_00632edc);
      if (iVar10 == 0) {
        unaff_s8 = unaff_s8 + -1;
        ppcVar3 = unaff_s7 + 1;
        if (unaff_s8 != 0) {
          param_2 = unaff_s7[1];
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
            pcVar15 = *(code **)(local_60 + -0x52c0);
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
        pcVar15 = *(code **)(local_60 + -0x52c0);
LAB_0042e834:
        iVar10 = (*pcVar15)(unaff_s6,local_54);
        if (iVar10 == 0) {
          unaff_s8 = unaff_s8 + -1;
          if (unaff_s8 != 0) {
            local_48 = unaff_s7[1];
            ppcVar3 = unaff_s7 + 1;
            goto LAB_0042e7fc;
          }
        }
        else {
          iVar10 = (**(code **)(local_60 + -0x52c0))(unaff_s6,local_44);
          if (iVar10 == 0) {
            unaff_s8 = unaff_s8 + -1;
            if (unaff_s8 != 0) {
              local_4c = unaff_s7[1];
              ppcVar3 = unaff_s7 + 1;
              goto LAB_0042e7fc;
            }
            goto LAB_0042e884;
          }
          iVar10 = (**(code **)(local_60 + -0x53d0))(unaff_s6,"%d",&local_3c);
          if ((iVar10 != 0) && (-1 < (int)local_3c)) goto LAB_0042ea18;
        }
      }
LAB_0042e884:
      (**(code **)(local_60 + -0x7fa8))(*(undefined4 *)puStack_8c,"usage: gendh [args] [numbits]\n")
      ;
      (**(code **)(local_60 + -0x7fa8))
                (*(undefined4 *)puStack_8c," -out file - output the key to \'file\n");
      (**(code **)(local_60 + -0x7fa8))
                (*(undefined4 *)puStack_8c," -2        - use 2 as the generator value\n");
      (**(code **)(local_60 + -0x7fa8))
                (*(undefined4 *)puStack_8c," -5        - use 5 as the generator value\n");
      (**(code **)(local_60 + -0x7fa8))
                (*(undefined4 *)puStack_8c,
                 " -engine e - use engine e, possibly a hardware device.\n");
      (**(code **)(local_60 + -0x7fa8))
                (*(undefined4 *)puStack_8c," -rand file%cfile%c...\n",0x3a,0x3a);
      (**(code **)(local_60 + -0x7fa8))
                (*(undefined4 *)puStack_8c,
                 "           - load the file (or the files in the directory) into\n");
      pcVar11 = "             the random number generator\n";
      (**(code **)(local_60 + -0x7fa8))(*(undefined4 *)puStack_8c);
      goto LAB_0042e948;
    }
    pcVar11 = (char *)0x0;
    (**(code **)(local_60 + -0x7f1c))(*(undefined4 *)puStack_8c,0,0);
    uVar4 = (**(code **)(local_60 + -0x7f40))();
    unaff_s2 = (**(code **)(local_60 + -0x7f3c))(uVar4);
    if (unaff_s2 != 0) {
      unaff_s5 = 2;
      local_4c = (char *)0x0;
      goto LAB_0042ec2c;
    }
    goto LAB_0042eccc;
  }
LAB_0042e948:
  iStack_98 = 1;
  (**(code **)(local_60 + -0x7fa0))(*(undefined4 *)puStack_8c);
LAB_0042e95c:
  if (local_2c == *local_50) {
    return iStack_98;
  }
  uStack_74 = 0x42ed0c;
  iVar10 = local_2c;
  (**(code **)(local_60 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar1 = PTR_bio_err_006a7f3c;
  pcVar5 = (char *)0x1;
  iStack_9c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_94 = param_2;
  iStack_90 = unaff_s2;
  uStack_88 = unaff_s4;
  uStack_84 = unaff_s5;
  pcStack_80 = unaff_s6;
  ppcStack_7c = unaff_s7;
  iStack_78 = unaff_s8;
  (*(code *)PTR_signal_006aabe0)(0xd);
  if (*(int *)puVar1 == 0) {
    uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar6 = (*(code *)PTR_BIO_new_006a7fa4)(uVar4);
    *(int *)puVar1 = iVar6;
    if (iVar6 != 0) {
      pcVar5 = &DAT_0000006a;
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar6,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
    }
  }
  (*(code *)PTR_SSL_load_error_strings_006a867c)();
  if (iVar10 < 2) {
LAB_0042ef24:
    iVar6 = 0;
  }
  else {
    pcVar5 = "-stats";
    iVar6 = (*(code *)PTR_strcmp_006aac20)(*(undefined4 *)(pcVar11 + 4));
    if (iVar6 == 0) {
      uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
      pcVar8 = (char *)(*(code *)PTR_BIO_new_006a7fa4)(uVar4);
      if (pcVar8 != (char *)0x0) {
        pcVar5 = &DAT_0000006a;
        iVar6 = (*(code *)PTR_BIO_ctrl_006a7f18)(pcVar8,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
        if (iVar6 != 0) {
          uVar4 = (*(code *)PTR_ERR_get_string_table_006a8684)();
          (*(code *)PTR_lh_node_stats_bio_006a8688)(uVar4,pcVar8);
          uVar4 = (*(code *)PTR_ERR_get_string_table_006a8684)();
          (*(code *)PTR_lh_stats_bio_006a868c)(uVar4,pcVar8);
          uVar4 = (*(code *)PTR_ERR_get_string_table_006a8684)();
          pcVar5 = pcVar8;
          (*(code *)PTR_lh_node_usage_stats_bio_006a8690)(uVar4);
        }
        (*(code *)PTR_BIO_free_all_006a7f74)(pcVar8);
      }
      iVar10 = iVar10 + -1;
      pcVar11 = pcVar11 + 4;
      if (iVar10 == 1) goto LAB_0042ef24;
    }
    puVar13 = (undefined4 *)(pcVar11 + 4);
    iVar6 = 0;
    iVar14 = 1;
    do {
      while (iVar7 = (*(code *)PTR___isoc99_sscanf_006aab10)(*puVar13,&DAT_006359e0,&uStack_1a0),
            iVar7 != 0) {
        iVar14 = iVar14 + 1;
        puVar13 = puVar13 + 1;
        pcVar5 = acStack_19c;
        (*(code *)PTR_ERR_error_string_n_006a8680)(uStack_1a0,acStack_19c,0x100);
        (*(code *)PTR_puts_006aab60)(acStack_19c);
        if (iVar10 <= iVar14) goto LAB_0042ee74;
      }
      iVar14 = iVar14 + 1;
      iVar6 = iVar6 + 1;
      pcVar5 = "%s: bad error code\n";
      (*(code *)PTR___printf_chk_006aaad0)(1,"%s: bad error code\n",*puVar13);
      puVar13 = puVar13 + 1;
      (*(code *)PTR_puts_006aab60)("usage: errstr [-stats] <errno> ...");
    } while (iVar14 < iVar10);
  }
LAB_0042ee74:
  if (iStack_9c == *(int *)puVar2) {
    return iVar6;
  }
  iVar10 = iStack_9c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar10 == 2) {
    iVar10 = (*(code *)PTR_OBJ_txt2obj_006a8100)(pcVar5,0);
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar10);
    if (iVar10 == 0) {
      pcVar11 = "Invalid object identifier %s\n";
LAB_0042f13c:
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,pcVar11,pcVar5);
      return 0;
    }
    pcVar11 = "holdInstruction";
LAB_0042f1d8:
    piVar9 = (int *)(*(code *)PTR_X509_gmtime_adj_006a808c)(0,0);
    iVar10 = (*(code *)PTR_strlen_006aab30)(pcVar11);
    iVar10 = *piVar9 + 2 + iVar10;
    if (pcVar5 == (char *)0x0) {
LAB_0042f3a4:
      iVar6 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar10,&DAT_00635b2c,0xae1);
      if (iVar6 == 0) {
        return 0;
      }
      (*(code *)PTR_BUF_strlcpy_006a8064)(iVar6,piVar9[2],iVar10);
      if (pcVar11 == (char *)0x0) goto LAB_0042f2cc;
      pcVar5 = (char *)0x0;
    }
    else {
      iVar6 = (*(code *)PTR_strlen_006aab30)(pcVar5);
      iVar10 = iVar10 + 1 + iVar6;
      iVar6 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar10,&DAT_00635b2c,0xae1);
      if (iVar6 == 0) {
        return 0;
      }
      (*(code *)PTR_BUF_strlcpy_006a8064)(iVar6,piVar9[2],iVar10);
    }
    (*(code *)PTR_BUF_strlcat_006a8068)(iVar6,",",iVar10);
    (*(code *)PTR_BUF_strlcat_006a8068)(iVar6,pcVar11,iVar10);
    if (pcVar5 != (char *)0x0) {
      (*(code *)PTR_BUF_strlcat_006a8068)(iVar6,",",iVar10);
      (*(code *)PTR_BUF_strlcat_006a8068)(iVar6,pcVar5,iVar10);
    }
  }
  else {
    if (iVar10 < 3) {
      if (iVar10 == 1) {
        iVar10 = (*(code *)PTR_strcasecmp_006aab24)(pcVar5,"unspecified");
        if (iVar10 == 0) {
          pcVar11 = "unspecified";
        }
        else {
          iVar10 = (*(code *)PTR_strcasecmp_006aab24)(pcVar5,"keyCompromise");
          if (iVar10 == 0) {
            pcVar11 = "keyCompromise";
          }
          else {
            iVar10 = (*(code *)PTR_strcasecmp_006aab24)(pcVar5,"CACompromise");
            if (iVar10 == 0) {
              pcVar11 = "CACompromise";
            }
            else {
              iVar10 = (*(code *)PTR_strcasecmp_006aab24)(pcVar5,"affiliationChanged");
              if (iVar10 == 0) {
                pcVar11 = "affiliationChanged";
              }
              else {
                iVar10 = (*(code *)PTR_strcasecmp_006aab24)(pcVar5,"superseded");
                if (iVar10 == 0) {
                  pcVar11 = "superseded";
                }
                else {
                  iVar10 = (*(code *)PTR_strcasecmp_006aab24)(pcVar5,"cessationOfOperation");
                  if (iVar10 == 0) {
                    pcVar11 = "cessationOfOperation";
                  }
                  else {
                    iVar10 = (*(code *)PTR_strcasecmp_006aab24)(pcVar5,"certificateHold");
                    if (iVar10 == 0) {
                      pcVar11 = "certificateHold";
                    }
                    else {
                      iVar10 = (*(code *)PTR_strcasecmp_006aab24)(pcVar5,"removeFromCRL");
                      if (iVar10 != 0) {
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
        iVar10 = (*(code *)PTR_strlen_006aab30)(pcVar11);
        iVar10 = *piVar9 + 2 + iVar10;
        goto LAB_0042f3a4;
      }
    }
    else if (iVar10 < 5) {
      iVar6 = (*(code *)PTR_ASN1_GENERALIZEDTIME_set_string_006a80fc)(0);
      if (iVar6 == 0) {
        pcVar11 = "Invalid time format %s. Need YYYYMMDDHHMMSSZ\n";
        goto LAB_0042f13c;
      }
      if (iVar10 == 3) {
        pcVar11 = "keyTime";
      }
      else {
        pcVar11 = "CAkeyTime";
      }
      goto LAB_0042f1d8;
    }
    piVar9 = (int *)(*(code *)PTR_X509_gmtime_adj_006a808c)(0,0);
    iVar10 = *piVar9;
    iVar6 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar10 + 1,&DAT_00635b2c,0xae1);
    if (iVar6 == 0) {
      return 0;
    }
    (*(code *)PTR_BUF_strlcpy_006a8064)(iVar6,piVar9[2],iVar10 + 1);
  }
LAB_0042f2cc:
  (*(code *)PTR_ASN1_UTCTIME_free_006a810c)(piVar9);
  return iVar6;
LAB_0042ea18:
  pcVar11 = local_48;
  (**(code **)(local_60 + -0x7f1c))(*(undefined4 *)puStack_8c,local_48,0);
  uVar4 = (**(code **)(local_60 + -0x7f40))();
  unaff_s2 = (**(code **)(local_60 + -0x7f3c))(uVar4);
  if (unaff_s2 == 0) {
LAB_0042eccc:
    (**(code **)(local_60 + -0x7fa0))(*(undefined4 *)puStack_8c);
    goto LAB_0042e948;
  }
  if (param_2 == (char *)0x0) {
LAB_0042ec2c:
    (**(code **)(local_60 + -0x7fc8))(unaff_s2,0x6a,0,**(undefined4 **)(local_60 + -0x540c));
LAB_0042ea7c:
    iVar10 = (**(code **)(local_60 + -0x7f14))(0,*(undefined4 *)puStack_8c,1);
    if (iVar10 == 0) {
      pcVar15 = *(code **)(local_60 + -0x7ea8);
      if (local_4c == (char *)0x0) {
        (**(code **)(local_60 + -0x7fa8))
                  (**(undefined4 **)(local_60 + -0x7fa4),
                   "warning, not much extra random data, consider using the -rand option\n");
      }
      else {
LAB_0042eaa8:
        uVar12 = *(undefined4 *)puStack_8c;
        uVar4 = (*pcVar15)(local_4c);
        (**(code **)(local_60 + -0x7fa8))(uVar12,"%ld semi-random bytes loaded\n",uVar4);
      }
    }
    else {
      pcVar15 = *(code **)(local_60 + -0x7ea8);
      if (local_4c != (char *)0x0) goto LAB_0042eaa8;
    }
    puVar13 = *(undefined4 **)(local_60 + -0x7fa4);
    (**(code **)(local_60 + -0x7fa8))
              (*(undefined4 *)puStack_8c,
               "Generating DH parameters, %d bit long safe prime, generator %d\n",local_3c,unaff_s5)
    ;
    pcVar11 = "This is going to take a long time\n";
    (**(code **)(local_60 + -0x7fa8))(*(undefined4 *)puStack_8c);
    pcVar5 = (char *)(**(code **)(local_60 + -0x78c8))();
    if (pcVar5 == (char *)0x0) {
      iStack_98 = 1;
      (**(code **)(local_60 + -0x7fa0))(*puVar13);
    }
    else {
      pcVar11 = local_3c;
      iVar10 = (**(code **)(local_60 + -0x78b0))(pcVar5,local_3c,unaff_s5,&local_38);
      if (iVar10 != 0) {
        (**(code **)(local_60 + -0x7e94))(0,*puVar13);
        pcVar11 = pcVar5;
        iVar10 = (**(code **)(local_60 + -0x78c0))(unaff_s2);
        if (iVar10 != 0) {
          iStack_98 = 0;
          goto LAB_0042eb58;
        }
      }
      iStack_98 = 1;
      (**(code **)(local_60 + -0x7fa0))(*(undefined4 *)puStack_8c);
    }
  }
  else {
    pcVar11 = &DAT_0000006c;
    iVar10 = (**(code **)(local_60 + -0x7fc8))(unaff_s2,0x6c,5,param_2);
    if (0 < iVar10) goto LAB_0042ea7c;
    iStack_98 = 1;
    pcVar5 = (char *)0x0;
    (**(code **)(local_60 + -0x5358))(param_2);
    (**(code **)(local_60 + -0x7fa0))(**(undefined4 **)(local_60 + -0x7fa4));
  }
LAB_0042eb58:
  (**(code **)(local_60 + -0x7f6c))(unaff_s2);
  param_2 = pcVar5;
  if (pcVar5 != (char *)0x0) {
    (**(code **)(local_60 + -0x78dc))(pcVar5);
  }
  goto LAB_0042e95c;
}

