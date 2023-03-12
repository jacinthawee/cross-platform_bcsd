
int errstr_main(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 local_130;
  char acStack_12c [256];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar1 = PTR_bio_err_006a7f3c;
  pcVar7 = (char *)0x1;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd);
  if (*(int *)puVar1 == 0) {
    uVar5 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar3 = (*(code *)PTR_BIO_new_006a7fa4)(uVar5);
    *(int *)puVar1 = iVar3;
    if (iVar3 != 0) {
      pcVar7 = &DAT_0000006a;
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar3,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
    }
  }
  (*(code *)PTR_SSL_load_error_strings_006a867c)();
  if (param_1 < 2) {
LAB_0042ef24:
    iVar3 = 0;
  }
  else {
    pcVar7 = "-stats";
    iVar3 = (*(code *)PTR_strcmp_006aac20)(*(undefined4 *)(param_2 + 4));
    if (iVar3 == 0) {
      uVar5 = (*(code *)PTR_BIO_s_file_006a7fa0)();
      pcVar8 = (char *)(*(code *)PTR_BIO_new_006a7fa4)(uVar5);
      if (pcVar8 != (char *)0x0) {
        pcVar7 = &DAT_0000006a;
        iVar3 = (*(code *)PTR_BIO_ctrl_006a7f18)(pcVar8,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
        if (iVar3 != 0) {
          uVar5 = (*(code *)PTR_ERR_get_string_table_006a8684)();
          (*(code *)PTR_lh_node_stats_bio_006a8688)(uVar5,pcVar8);
          uVar5 = (*(code *)PTR_ERR_get_string_table_006a8684)();
          (*(code *)PTR_lh_stats_bio_006a868c)(uVar5,pcVar8);
          uVar5 = (*(code *)PTR_ERR_get_string_table_006a8684)();
          pcVar7 = pcVar8;
          (*(code *)PTR_lh_node_usage_stats_bio_006a8690)(uVar5);
        }
        (*(code *)PTR_BIO_free_all_006a7f74)(pcVar8);
      }
      param_1 = param_1 + -1;
      param_2 = param_2 + 4;
      if (param_1 == 1) goto LAB_0042ef24;
    }
    puVar9 = (undefined4 *)(param_2 + 4);
    iVar3 = 0;
    iVar10 = 1;
    do {
      while (iVar4 = (*(code *)PTR___isoc99_sscanf_006aab10)(*puVar9,&DAT_006359e0,&local_130),
            iVar4 != 0) {
        iVar10 = iVar10 + 1;
        puVar9 = puVar9 + 1;
        pcVar7 = acStack_12c;
        (*(code *)PTR_ERR_error_string_n_006a8680)(local_130,acStack_12c,0x100);
        (*(code *)PTR_puts_006aab60)(acStack_12c);
        if (param_1 <= iVar10) goto LAB_0042ee74;
      }
      iVar10 = iVar10 + 1;
      iVar3 = iVar3 + 1;
      pcVar7 = "%s: bad error code\n";
      (*(code *)PTR___printf_chk_006aaad0)(1,"%s: bad error code\n",*puVar9);
      puVar9 = puVar9 + 1;
      (*(code *)PTR_puts_006aab60)("usage: errstr [-stats] <errno> ...");
    } while (iVar10 < param_1);
  }
LAB_0042ee74:
  if (local_2c == *(int *)puVar2) {
    return iVar3;
  }
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar3 == 2) {
    iVar3 = (*(code *)PTR_OBJ_txt2obj_006a8100)(pcVar7,0);
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar3);
    if (iVar3 == 0) {
      pcVar8 = "Invalid object identifier %s\n";
LAB_0042f13c:
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,pcVar8,pcVar7);
      return 0;
    }
    pcVar8 = "holdInstruction";
LAB_0042f1d8:
    piVar6 = (int *)(*(code *)PTR_X509_gmtime_adj_006a808c)(0,0);
    iVar3 = (*(code *)PTR_strlen_006aab30)(pcVar8);
    iVar3 = *piVar6 + 2 + iVar3;
    if (pcVar7 == (char *)0x0) {
LAB_0042f3a4:
      iVar10 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3,&DAT_00635b2c,0xae1);
      if (iVar10 == 0) {
        return 0;
      }
      (*(code *)PTR_BUF_strlcpy_006a8064)(iVar10,piVar6[2],iVar3);
      if (pcVar8 == (char *)0x0) goto LAB_0042f2cc;
      pcVar7 = (char *)0x0;
    }
    else {
      iVar10 = (*(code *)PTR_strlen_006aab30)(pcVar7);
      iVar3 = iVar3 + 1 + iVar10;
      iVar10 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3,&DAT_00635b2c,0xae1);
      if (iVar10 == 0) {
        return 0;
      }
      (*(code *)PTR_BUF_strlcpy_006a8064)(iVar10,piVar6[2],iVar3);
    }
    (*(code *)PTR_BUF_strlcat_006a8068)(iVar10,",",iVar3);
    (*(code *)PTR_BUF_strlcat_006a8068)(iVar10,pcVar8,iVar3);
    if (pcVar7 != (char *)0x0) {
      (*(code *)PTR_BUF_strlcat_006a8068)(iVar10,",",iVar3);
      (*(code *)PTR_BUF_strlcat_006a8068)(iVar10,pcVar7,iVar3);
    }
  }
  else {
    if (iVar3 < 3) {
      if (iVar3 == 1) {
        iVar3 = (*(code *)PTR_strcasecmp_006aab24)(pcVar7,"unspecified");
        if (iVar3 == 0) {
          pcVar8 = "unspecified";
        }
        else {
          iVar3 = (*(code *)PTR_strcasecmp_006aab24)(pcVar7,"keyCompromise");
          if (iVar3 == 0) {
            pcVar8 = "keyCompromise";
          }
          else {
            iVar3 = (*(code *)PTR_strcasecmp_006aab24)(pcVar7,"CACompromise");
            if (iVar3 == 0) {
              pcVar8 = "CACompromise";
            }
            else {
              iVar3 = (*(code *)PTR_strcasecmp_006aab24)(pcVar7,"affiliationChanged");
              if (iVar3 == 0) {
                pcVar8 = "affiliationChanged";
              }
              else {
                iVar3 = (*(code *)PTR_strcasecmp_006aab24)(pcVar7,"superseded");
                if (iVar3 == 0) {
                  pcVar8 = "superseded";
                }
                else {
                  iVar3 = (*(code *)PTR_strcasecmp_006aab24)(pcVar7,"cessationOfOperation");
                  if (iVar3 == 0) {
                    pcVar8 = "cessationOfOperation";
                  }
                  else {
                    iVar3 = (*(code *)PTR_strcasecmp_006aab24)(pcVar7,"certificateHold");
                    if (iVar3 == 0) {
                      pcVar8 = "certificateHold";
                    }
                    else {
                      iVar3 = (*(code *)PTR_strcasecmp_006aab24)(pcVar7,"removeFromCRL");
                      if (iVar3 != 0) {
                        pcVar8 = "Unknown CRL reason %s\n";
                        goto LAB_0042f13c;
                      }
                      pcVar8 = "removeFromCRL";
                    }
                  }
                }
              }
            }
          }
        }
        piVar6 = (int *)(*(code *)PTR_X509_gmtime_adj_006a808c)(0,0);
        iVar3 = (*(code *)PTR_strlen_006aab30)(pcVar8);
        iVar3 = *piVar6 + 2 + iVar3;
        goto LAB_0042f3a4;
      }
    }
    else if (iVar3 < 5) {
      iVar10 = (*(code *)PTR_ASN1_GENERALIZEDTIME_set_string_006a80fc)(0);
      if (iVar10 == 0) {
        pcVar8 = "Invalid time format %s. Need YYYYMMDDHHMMSSZ\n";
        goto LAB_0042f13c;
      }
      if (iVar3 == 3) {
        pcVar8 = "keyTime";
      }
      else {
        pcVar8 = "CAkeyTime";
      }
      goto LAB_0042f1d8;
    }
    piVar6 = (int *)(*(code *)PTR_X509_gmtime_adj_006a808c)(0,0);
    iVar3 = *piVar6;
    iVar10 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3 + 1,&DAT_00635b2c,0xae1);
    if (iVar10 == 0) {
      return 0;
    }
    (*(code *)PTR_BUF_strlcpy_006a8064)(iVar10,piVar6[2],iVar3 + 1);
  }
LAB_0042f2cc:
  (*(code *)PTR_ASN1_UTCTIME_free_006a810c)(piVar6);
  return iVar10;
}

