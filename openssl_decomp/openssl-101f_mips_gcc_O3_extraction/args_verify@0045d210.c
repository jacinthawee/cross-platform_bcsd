
undefined4 args_verify(int *param_1,int *param_2,int *param_3,undefined4 param_4,int *param_5)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puVar8 = (undefined4 *)*param_1;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar9 = *puVar8;
  iVar10 = puVar8[1];
  iVar2 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-policy");
  if (iVar2 == 0) {
    if (iVar10 == 0) {
      iVar5 = 1;
      *param_3 = 1;
      iVar3 = 0;
      puVar4 = puVar8;
    }
    else {
      iVar3 = (*(code *)PTR_OBJ_txt2obj_006a8100)(iVar10,0);
      if (iVar3 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(param_4,"Invalid Policy \"%s\"\n",iVar10);
        iVar5 = 1;
        puVar4 = (undefined4 *)*param_1;
        *param_3 = 1;
      }
      else {
        iVar5 = *param_3;
        puVar4 = (undefined4 *)*param_1;
      }
    }
    iVar10 = 0;
    iVar7 = -1;
    *param_1 = (int)(puVar4 + 1);
    iVar11 = 0;
  }
  else {
    iVar2 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-purpose");
    if (iVar2 == 0) {
      if (iVar10 == 0) {
        iVar5 = 1;
        *param_3 = 1;
        iVar2 = 0;
        puVar4 = puVar8;
      }
      else {
        iVar10 = (*(code *)PTR_X509_PURPOSE_get_by_sname_006a8ce8)(iVar10);
        if (iVar10 < 0) {
          (*(code *)PTR_BIO_printf_006a7f38)(param_4,"unrecognized purpose\n");
          iVar5 = 1;
          puVar4 = (undefined4 *)*param_1;
          iVar2 = 0;
          *param_3 = 1;
        }
        else {
          uVar9 = (*(code *)PTR_X509_PURPOSE_get0_006a8570)(iVar10);
          iVar2 = (*(code *)PTR_X509_PURPOSE_get_id_006a87e4)(uVar9);
          iVar5 = *param_3;
          puVar4 = (undefined4 *)*param_1;
        }
      }
      iVar10 = 0;
      iVar7 = -1;
      *param_1 = (int)(puVar4 + 1);
      iVar11 = 0;
      iVar3 = 0;
      iVar6 = *param_5;
      if (iVar5 != 0) goto LAB_0045d2d8;
      goto LAB_0045d3d4;
    }
    iVar2 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-verify_depth");
    if (iVar2 == 0) {
      if (iVar10 == 0) {
        iVar5 = 1;
        *param_3 = 1;
        iVar7 = -1;
        puVar4 = puVar8;
      }
      else {
        iVar7 = (*(code *)PTR_strtol_006aaa68)(iVar10,0,10);
        if (iVar7 < 0) {
          (*(code *)PTR_BIO_printf_006a7f38)(param_4,"invalid depth\n");
          iVar5 = 1;
          puVar4 = (undefined4 *)*param_1;
          *param_3 = 1;
        }
        else {
          iVar5 = *param_3;
          puVar4 = (undefined4 *)*param_1;
        }
      }
      iVar10 = 0;
      *param_1 = (int)(puVar4 + 1);
      iVar11 = 0;
      iVar3 = 0;
    }
    else {
      iVar2 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-attime");
      if (iVar2 == 0) {
        if (iVar10 == 0) {
          iVar5 = 1;
          *param_3 = 1;
          puVar4 = puVar8;
        }
        else {
          iVar2 = (*(code *)PTR___isoc99_sscanf_006aab10)(iVar10,&DAT_006404bc,&local_30);
          if (iVar2 == 1) {
            iVar5 = *param_3;
          }
          else {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)PTR_bio_err_006a7f3c,"Error parsing timestamp %s\n",iVar10);
            iVar5 = 1;
            *param_3 = 1;
          }
          puVar4 = (undefined4 *)*param_1;
          iVar10 = local_30;
        }
        iVar7 = -1;
        *param_1 = (int)(puVar4 + 1);
        iVar11 = 0;
        iVar3 = 0;
      }
      else {
        iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-ignore_critical");
        if (iVar10 == 0) {
          iVar5 = *param_3;
          iVar10 = 0;
          iVar7 = -1;
          iVar11 = 0x10;
          iVar3 = 0;
        }
        else {
          iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-issuer_checks");
          if (iVar10 == 0) {
            iVar5 = *param_3;
            iVar10 = 0;
            iVar7 = -1;
            iVar11 = 1;
            iVar3 = 0;
          }
          else {
            iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-crl_check");
            if (iVar10 == 0) {
              iVar5 = *param_3;
              iVar10 = 0;
              iVar7 = -1;
              iVar11 = 4;
              iVar3 = 0;
            }
            else {
              iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-crl_check_all");
              if (iVar10 == 0) {
                iVar5 = *param_3;
                iVar10 = 0;
                iVar7 = -1;
                iVar11 = 0xc;
                iVar3 = 0;
              }
              else {
                iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-policy_check");
                if (iVar10 == 0) {
                  iVar5 = *param_3;
                  iVar10 = 0;
                  iVar7 = -1;
                  iVar11 = 0x80;
                  iVar3 = 0;
                }
                else {
                  iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-explicit_policy");
                  if (iVar10 == 0) {
                    iVar5 = *param_3;
                    iVar10 = 0;
                    iVar7 = -1;
                    iVar11 = 0x100;
                    iVar3 = 0;
                  }
                  else {
                    iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-inhibit_any");
                    if (iVar10 == 0) {
                      iVar5 = *param_3;
                      iVar10 = 0;
                      iVar7 = -1;
                      iVar11 = 0x200;
                      iVar3 = 0;
                    }
                    else {
                      iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-inhibit_map");
                      if (iVar10 == 0) goto LAB_0045d8a4;
                      iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-x509_strict");
                      if (iVar10 == 0) {
                        iVar5 = *param_3;
                        iVar10 = 0;
                        iVar7 = -1;
                        iVar11 = 0x20;
                        iVar3 = 0;
                      }
                      else {
                        iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-extended_crl");
                        if (iVar10 == 0) {
                          iVar5 = *param_3;
                          iVar10 = 0;
                          iVar7 = -1;
                          iVar11 = 0x1000;
                          iVar3 = 0;
                        }
                        else {
                          iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-use_deltas");
                          if (iVar10 == 0) {
                            iVar5 = *param_3;
                            iVar10 = 0;
                            iVar7 = -1;
                            iVar11 = 0x2000;
                            iVar3 = 0;
                          }
                          else {
                            iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-policy_print");
                            if (iVar10 == 0) {
                              iVar5 = *param_3;
                              iVar10 = 0;
                              iVar7 = -1;
                              iVar11 = 0x800;
                              iVar3 = 0;
                            }
                            else {
                              iVar10 = (*(code *)PTR_strcmp_006aac20)(uVar9,"-check_ss_sig");
                              if (iVar10 != 0) {
                                uVar9 = 0;
                                goto LAB_0045d318;
                              }
                              iVar5 = *param_3;
                              iVar10 = 0;
                              iVar7 = -1;
                              iVar11 = 0x4000;
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
  do {
    iVar2 = 0;
    iVar6 = *param_5;
    if (iVar5 == 0) {
LAB_0045d3d4:
      if (iVar6 == 0) {
        iVar6 = (*(code *)PTR_X509_VERIFY_PARAM_new_006a8cec)();
        *param_5 = iVar6;
        if (iVar6 == 0) {
          *param_3 = 1;
          goto LAB_0045d2f0;
        }
      }
      if (iVar3 != 0) {
        (*(code *)PTR_X509_VERIFY_PARAM_add0_policy_006a8cf0)(iVar6,iVar3);
      }
      if (iVar11 != 0) {
        (*(code *)PTR_X509_VERIFY_PARAM_set_flags_006a8cf4)(*param_5,iVar11);
      }
      if (iVar2 != 0) {
        (*(code *)PTR_X509_VERIFY_PARAM_set_purpose_006a8cf8)(*param_5,iVar2);
      }
      if (-1 < iVar7) {
        (*(code *)PTR_X509_VERIFY_PARAM_set_depth_006a8cfc)(*param_5,iVar7);
      }
      if (iVar10 == 0) goto LAB_0045d2f0;
      (*(code *)PTR_X509_VERIFY_PARAM_set_time_006a8d00)(*param_5,iVar10);
      iVar10 = *param_1 + 4;
      *param_1 = iVar10;
      if (param_2 != (int *)0x0) goto LAB_0045d300;
LAB_0045d450:
      uVar9 = 1;
    }
    else {
LAB_0045d2d8:
      if (iVar6 != 0) {
        (*(code *)PTR_X509_VERIFY_PARAM_free_006a83cc)();
      }
      *param_5 = 0;
LAB_0045d2f0:
      iVar10 = *param_1 + 4;
      *param_1 = iVar10;
      if (param_2 == (int *)0x0) goto LAB_0045d450;
LAB_0045d300:
      uVar9 = 1;
      *param_2 = *param_2 - (iVar10 - (int)puVar8 >> 2);
    }
LAB_0045d318:
    if (local_2c == *(int *)puVar1) {
      return uVar9;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0045d8a4:
    iVar5 = *param_3;
    iVar10 = 0;
    iVar7 = -1;
    iVar11 = 0x400;
    iVar3 = 0;
  } while( true );
}

