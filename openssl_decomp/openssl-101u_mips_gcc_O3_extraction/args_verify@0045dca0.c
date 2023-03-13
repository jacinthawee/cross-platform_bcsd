
undefined4 args_verify(int *param_1,int *param_2,int *param_3,undefined4 param_4,int *param_5)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puVar8 = (undefined4 *)*param_1;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar9 = *puVar8;
  iVar10 = puVar8[1];
  iVar2 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-policy");
  if (iVar2 == 0) {
    if (iVar10 == 0) {
      iVar4 = 1;
      *param_3 = 1;
      iVar3 = 0;
      puVar5 = puVar8;
    }
    else {
      iVar3 = (*(code *)PTR_OBJ_txt2obj_006a7000)(iVar10,0);
      if (iVar3 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(param_4,"Invalid Policy \"%s\"\n",iVar10);
        iVar4 = 1;
        puVar5 = (undefined4 *)*param_1;
        *param_3 = 1;
      }
      else {
        iVar4 = *param_3;
        puVar5 = (undefined4 *)*param_1;
      }
    }
    iVar10 = 0;
    iVar7 = -1;
    *param_1 = (int)(puVar5 + 1);
    iVar11 = 0;
  }
  else {
    iVar2 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-purpose");
    if (iVar2 == 0) {
      if (iVar10 == 0) {
        iVar4 = 1;
        *param_3 = 1;
        iVar2 = 0;
        puVar5 = puVar8;
      }
      else {
        iVar10 = (*(code *)PTR_X509_PURPOSE_get_by_sname_006a7bfc)(iVar10);
        if (iVar10 < 0) {
          (*(code *)PTR_BIO_printf_006a6e38)(param_4,"unrecognized purpose\n");
          iVar4 = 1;
          puVar5 = (undefined4 *)*param_1;
          iVar2 = 0;
          *param_3 = 1;
        }
        else {
          uVar9 = (*(code *)PTR_X509_PURPOSE_get0_006a7470)(iVar10);
          iVar2 = (*(code *)PTR_X509_PURPOSE_get_id_006a7718)(uVar9);
          iVar4 = *param_3;
          puVar5 = (undefined4 *)*param_1;
        }
      }
      iVar10 = 0;
      iVar7 = -1;
      *param_1 = (int)(puVar5 + 1);
      iVar11 = 0;
      iVar3 = 0;
      iVar6 = *param_5;
      if (iVar4 != 0) goto LAB_0045dd68;
      goto LAB_0045de64;
    }
    iVar2 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-verify_depth");
    if (iVar2 == 0) {
      if (iVar10 == 0) {
        iVar4 = 1;
        *param_3 = 1;
        iVar7 = -1;
        puVar5 = puVar8;
      }
      else {
        iVar7 = (*(code *)PTR_strtol_006a9958)(iVar10,0,10);
        if (iVar7 < 0) {
          (*(code *)PTR_BIO_printf_006a6e38)(param_4,"invalid depth\n");
          iVar4 = 1;
          puVar5 = (undefined4 *)*param_1;
          *param_3 = 1;
        }
        else {
          iVar4 = *param_3;
          puVar5 = (undefined4 *)*param_1;
        }
      }
      iVar10 = 0;
      *param_1 = (int)(puVar5 + 1);
      iVar11 = 0;
      iVar3 = 0;
    }
    else {
      iVar2 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-attime");
      if (iVar2 == 0) {
        if (iVar10 == 0) {
          iVar4 = 1;
          *param_3 = 1;
          puVar5 = puVar8;
        }
        else {
          iVar2 = (*(code *)PTR___isoc99_sscanf_006a9a04)(iVar10,&DAT_0063ff20,&local_30);
          if (iVar2 == 1) {
            iVar4 = *param_3;
          }
          else {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)PTR_bio_err_006a6e3c,"Error parsing timestamp %s\n",iVar10);
            iVar4 = 1;
            *param_3 = 1;
          }
          puVar5 = (undefined4 *)*param_1;
          iVar10 = local_30;
        }
        iVar7 = -1;
        *param_1 = (int)(puVar5 + 1);
        iVar11 = 0;
        iVar3 = 0;
      }
      else {
        iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-ignore_critical");
        if (iVar10 == 0) {
          iVar4 = *param_3;
          iVar10 = 0;
          iVar7 = -1;
          iVar11 = 0x10;
          iVar3 = 0;
        }
        else {
          iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-issuer_checks");
          if (iVar10 == 0) {
            iVar4 = *param_3;
            iVar10 = 0;
            iVar7 = -1;
            iVar11 = 1;
            iVar3 = 0;
          }
          else {
            iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-crl_check");
            if (iVar10 == 0) {
              iVar4 = *param_3;
              iVar10 = 0;
              iVar7 = -1;
              iVar11 = 4;
              iVar3 = 0;
            }
            else {
              iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-crl_check_all");
              if (iVar10 == 0) {
                iVar4 = *param_3;
                iVar10 = 0;
                iVar7 = -1;
                iVar11 = 0xc;
                iVar3 = 0;
              }
              else {
                iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-policy_check");
                if (iVar10 == 0) {
                  iVar4 = *param_3;
                  iVar10 = 0;
                  iVar7 = -1;
                  iVar11 = 0x80;
                  iVar3 = 0;
                }
                else {
                  iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-explicit_policy");
                  if (iVar10 == 0) {
                    iVar4 = *param_3;
                    iVar10 = 0;
                    iVar7 = -1;
                    iVar11 = 0x100;
                    iVar3 = 0;
                  }
                  else {
                    iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-inhibit_any");
                    if (iVar10 == 0) {
                      iVar4 = *param_3;
                      iVar10 = 0;
                      iVar7 = -1;
                      iVar11 = 0x200;
                      iVar3 = 0;
                    }
                    else {
                      iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-inhibit_map");
                      if (iVar10 == 0) goto LAB_0045e334;
                      iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-x509_strict");
                      if (iVar10 == 0) {
                        iVar4 = *param_3;
                        iVar10 = 0;
                        iVar7 = -1;
                        iVar11 = 0x20;
                        iVar3 = 0;
                      }
                      else {
                        iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-extended_crl");
                        if (iVar10 == 0) {
                          iVar4 = *param_3;
                          iVar10 = 0;
                          iVar7 = -1;
                          iVar11 = 0x1000;
                          iVar3 = 0;
                        }
                        else {
                          iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-use_deltas");
                          if (iVar10 == 0) {
                            iVar4 = *param_3;
                            iVar10 = 0;
                            iVar7 = -1;
                            iVar11 = 0x2000;
                            iVar3 = 0;
                          }
                          else {
                            iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-policy_print");
                            if (iVar10 == 0) {
                              iVar4 = *param_3;
                              iVar10 = 0;
                              iVar7 = -1;
                              iVar11 = 0x800;
                              iVar3 = 0;
                            }
                            else {
                              iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-check_ss_sig");
                              if (iVar10 == 0) {
                                iVar4 = *param_3;
                                iVar10 = 0;
                                iVar7 = -1;
                                iVar11 = 0x4000;
                                iVar3 = 0;
                              }
                              else {
                                iVar10 = (*(code *)PTR_strcmp_006a9b18)(uVar9,"-no_alt_chains");
                                if (iVar10 == 0) {
                                  iVar4 = *param_3;
                                  iVar10 = 0;
                                  iVar7 = -1;
                                  iVar11 = 0x100000;
                                  iVar3 = 0;
                                }
                                else {
                                  iVar10 = (*(code *)PTR_strcmp_006a9b18)
                                                     (uVar9,"-allow_proxy_certs");
                                  if (iVar10 != 0) {
                                    uVar9 = 0;
                                    goto LAB_0045dda8;
                                  }
                                  iVar4 = *param_3;
                                  iVar10 = 0;
                                  iVar7 = -1;
                                  iVar11 = 0x40;
                                  iVar3 = 0;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  do {
    iVar2 = 0;
    iVar6 = *param_5;
    if (iVar4 == 0) {
LAB_0045de64:
      if (iVar6 == 0) {
        iVar6 = (*(code *)PTR_X509_VERIFY_PARAM_new_006a7c00)();
        *param_5 = iVar6;
        if (iVar6 == 0) {
          *param_3 = 1;
          goto LAB_0045dd80;
        }
      }
      if (iVar3 != 0) {
        (*(code *)PTR_X509_VERIFY_PARAM_add0_policy_006a7c04)(iVar6,iVar3);
      }
      if (iVar11 != 0) {
        (*(code *)PTR_X509_VERIFY_PARAM_set_flags_006a7c08)(*param_5,iVar11);
      }
      if (iVar2 != 0) {
        (*(code *)PTR_X509_VERIFY_PARAM_set_purpose_006a7c0c)(*param_5,iVar2);
      }
      if (-1 < iVar7) {
        (*(code *)PTR_X509_VERIFY_PARAM_set_depth_006a7c10)(*param_5,iVar7);
      }
      if (iVar10 == 0) goto LAB_0045dd80;
      (*(code *)PTR_X509_VERIFY_PARAM_set_time_006a7c14)(*param_5,iVar10);
      iVar10 = *param_1 + 4;
      *param_1 = iVar10;
      if (param_2 != (int *)0x0) goto LAB_0045dd90;
LAB_0045dee0:
      uVar9 = 1;
    }
    else {
LAB_0045dd68:
      if (iVar6 != 0) {
        (*(code *)PTR_X509_VERIFY_PARAM_free_006a72cc)();
      }
      *param_5 = 0;
LAB_0045dd80:
      iVar10 = *param_1 + 4;
      *param_1 = iVar10;
      if (param_2 == (int *)0x0) goto LAB_0045dee0;
LAB_0045dd90:
      uVar9 = 1;
      *param_2 = *param_2 - (iVar10 - (int)puVar8 >> 2);
    }
LAB_0045dda8:
    if (local_2c == *(int *)puVar1) {
      return uVar9;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0045e334:
    iVar4 = *param_3;
    iVar10 = 0;
    iVar7 = -1;
    iVar11 = 0x400;
    iVar3 = 0;
  } while( true );
}

