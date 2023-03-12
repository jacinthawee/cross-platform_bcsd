
undefined4 *
do_fp(int param_1,undefined4 *param_2,int param_3,int param_4,int param_5,int param_6,char **param_7
     ,undefined4 param_8,int param_9,int param_10,char *param_11)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  char **ppcVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  char *pcVar16;
  char *pcVar17;
  char **ppcVar18;
  code *pcVar19;
  int iStack_120;
  char *pcStack_11c;
  undefined *puStack_118;
  int iStack_114;
  char *pcStack_110;
  char *pcStack_10c;
  uint uStack_108;
  char *pcStack_fc;
  char *pcStack_f4;
  char *pcStack_ec;
  char *pcStack_e8;
  undefined4 uStack_e4;
  int iStack_d8;
  undefined4 uStack_d4;
  undefined *puStack_cc;
  int iStack_c4;
  int iStack_c0;
  undefined4 uStack_bc;
  int iStack_b8;
  undefined auStack_b4 [40];
  int iStack_8c;
  undefined4 *puStack_88;
  int iStack_84;
  undefined *puStack_80;
  int iStack_7c;
  char **ppcStack_78;
  char *pcStack_74;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  code *pcStack_64;
  char *local_50;
  undefined *local_48;
  int local_3c;
  int local_34;
  undefined4 local_30;
  int local_2c;
  
  puStack_80 = PTR___stack_chk_guard_006a9ae8;
  local_48 = &_gp;
  local_3c = param_10;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar19 = (code *)PTR_BIO_read_006a74c0;
  do {
    iVar7 = (*pcVar19)(param_3,param_2,0x2000);
    if (iVar7 < 0) {
      param_2 = *(undefined4 **)(local_48 + -0x7fa4);
      pcVar16 = "Read Error in %s\n";
      (**(code **)(local_48 + -0x7fa8))(*param_2,"Read Error in %s\n",param_11);
      goto LAB_00427c30;
    }
    pcVar19 = *(code **)(local_48 + -0x7920);
  } while (iVar7 != 0);
  if (param_7 == (char **)0x0) {
    if (param_6 == 0) {
      pcVar16 = (char *)param_2;
      local_34 = (**(code **)(local_48 + -0x790c))(param_3,param_2,0x2000,&local_30);
      if (local_34 < 0) {
        (**(code **)(local_48 + -0x7fa0))(**(undefined4 **)(local_48 + -0x7fa4));
        puVar8 = (undefined4 *)0x1;
        goto LAB_00427c44;
      }
    }
    else {
      (**(code **)(local_48 + -0x7fc8))(param_3,0x78,0);
      local_34 = 0x2000;
      iVar7 = (**(code **)(local_48 + -0x7910))(local_30,param_2,&local_34);
      if (iVar7 == 0) {
        param_2 = *(undefined4 **)(local_48 + -0x7fa4);
        pcVar19 = *(code **)(local_48 + -0x7fa8);
        pcVar16 = "Error Signing Data\n";
        goto LAB_00427df8;
      }
    }
    if (param_5 == 0) {
      if (param_4 == 2) {
        if (0 < local_34) {
          param_3 = 0;
          param_7 = (char **)&DAT_006338a8;
          do {
            cVar1 = *(char *)param_2;
            param_3 = param_3 + 1;
            param_2 = (undefined4 *)((int)param_2 + 1);
            (**(code **)(local_48 + -0x7fa8))(param_1,&DAT_006338a8,cVar1);
          } while (param_3 < local_34);
        }
        pcVar16 = " *%s\n";
        (**(code **)(local_48 + -0x7fa8))(param_1," *%s\n",param_11);
        puVar8 = (undefined4 *)0x0;
      }
      else {
        if (param_9 == 0) {
          if (local_3c == 0) {
            (**(code **)(local_48 + -0x7fa8))(param_1,"(%s)= ",param_11);
          }
          else {
            (**(code **)(local_48 + -0x7fa8))(param_1,"%s(%s)= ",local_3c,param_11);
          }
        }
        else {
          local_50 = param_11;
          (**(code **)(local_48 + -0x7fa8))(param_1,"%s-%s(%s)= ",param_9,local_3c);
        }
        if (0 < local_34) {
          param_3 = 0;
          param_7 = (char **)&DAT_006338a8;
          if (param_4 != 0) {
            param_11 = ":";
            do {
              pcVar19 = *(code **)(local_48 + -0x7fa8);
              do {
                cVar1 = *(char *)param_2;
                param_3 = param_3 + 1;
                param_2 = (undefined4 *)((int)param_2 + 1);
                (*pcVar19)(param_1,&DAT_006338a8,cVar1);
                if (local_34 <= param_3) goto LAB_00427e38;
                pcVar19 = *(code **)(local_48 + -0x7fa8);
              } while (param_3 == 0);
              (*pcVar19)(param_1,":");
            } while( true );
          }
          do {
            cVar1 = *(char *)param_2;
            param_3 = param_3 + 1;
            param_2 = (undefined4 *)((int)param_2 + 1);
            (**(code **)(local_48 + -0x7fa8))(param_1,&DAT_006338a8,cVar1);
          } while (param_3 < local_34);
        }
LAB_00427e38:
        pcVar16 = "\n";
        (**(code **)(local_48 + -0x7fa8))(param_1);
        puVar8 = (undefined4 *)0x0;
      }
    }
    else {
      pcVar16 = (char *)param_2;
      (**(code **)(local_48 + -0x7fcc))(param_1,param_2,local_34);
      puVar8 = (undefined4 *)0x0;
    }
  }
  else {
    (**(code **)(local_48 + -0x7fc8))(param_3,0x78,0,&local_30);
    iVar7 = (**(code **)(local_48 + -0x7914))(local_30,param_7,param_8);
    if (iVar7 < 1) {
      pcVar19 = *(code **)(local_48 + -0x7fa8);
      if (iVar7 == 0) {
        pcVar16 = "Verification Failure\n";
        (*pcVar19)(param_1);
        puVar8 = (undefined4 *)0x1;
      }
      else {
        param_2 = *(undefined4 **)(local_48 + -0x7fa4);
        pcVar16 = "Error Verifying Data\n";
LAB_00427df8:
        (*pcVar19)(*param_2);
LAB_00427c30:
        (**(code **)(local_48 + -0x7fa0))(*param_2);
        puVar8 = (undefined4 *)0x1;
      }
    }
    else {
      pcVar16 = "Verified OK\n";
      (**(code **)(local_48 + -0x7fa8))(param_1);
      puVar8 = (undefined4 *)0x0;
    }
  }
LAB_00427c44:
  if (local_2c == *(int *)puStack_80) {
    return puVar8;
  }
  pcStack_64 = dgst_main;
  iVar7 = local_2c;
  (**(code **)(local_48 + -0x5330))();
  puVar6 = PTR___stack_chk_guard_006a9ae8;
  iStack_68 = param_9;
  iStack_6c = param_6;
  iStack_c4 = 0;
  iStack_c0 = 0;
  iStack_8c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_88 = param_2;
  iStack_84 = param_3;
  iStack_7c = param_1;
  ppcStack_78 = param_7;
  pcStack_74 = param_11;
  iStack_70 = param_4;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iStack_114 = 0x630000;
  iVar9 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x2000,"dgst.c",0x87);
  puVar8 = (undefined4 *)PTR_bio_err_006a6e3c;
  if (iVar9 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"out of memory\n");
    if (iStack_c0 != 0) {
      iStack_120 = 0;
      ppcVar18 = (char **)0x0;
      param_6 = 0;
      param_1 = 0;
      puVar8 = (undefined4 *)0x1;
      pcVar16 = (char *)0x0;
      goto LAB_00428078;
    }
    puVar8 = (undefined4 *)0x1;
    (*(code *)PTR_BIO_free_all_006a6e74)(0);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(iStack_c4);
    iVar9 = param_9;
    goto LAB_004280fc;
  }
  iVar14 = *(int *)PTR_bio_err_006a6e3c;
  if (iVar14 == 0) {
    uVar15 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar14 = (*(code *)PTR_BIO_new_006a6ea4)(uVar15);
    *puVar8 = iVar14;
    if (iVar14 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar14,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
      iVar14 = *puVar8;
    }
  }
  iVar14 = (*(code *)PTR_load_config_006a6e64)(iVar14,0);
  if (iVar14 != 0) {
    puStack_cc = auStack_b4;
    (*(code *)PTR_program_name_006a7410)(*(undefined4 *)pcVar16,puStack_cc,0x28);
    param_4 = iVar7 + -1;
    param_7 = (char **)((int)pcVar16 + 4);
    iStack_d8 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(puStack_cc);
    if ((0 < param_4) && (pcVar16 = *(char **)((int)pcVar16 + 4), *pcVar16 == '-')) {
      iStack_120 = 0;
      bVar5 = false;
      pcStack_f4 = (char *)0x0;
      uStack_108 = 0xffffffff;
      param_6 = 0;
      pcStack_e8 = (char *)0x0;
      pcStack_fc = (char *)0x0;
      param_11 = (char *)0x0;
      uStack_d4 = 3;
      bVar2 = false;
      bVar4 = false;
      puStack_118 = &DAT_00632514;
      pcStack_11c = (char *)0x0;
      pcStack_ec = (char *)0x0;
      pcStack_110 = (char *)0x0;
      pcStack_10c = (char *)0x0;
      bVar3 = false;
      uStack_e4 = 0;
      do {
        cVar1 = pcVar16[1];
        ppcVar18 = param_7;
        iVar7 = iStack_d8;
        if (cVar1 == 'c') {
          if (pcVar16[2] == '\0') {
            param_11 = (char *)0x1;
          }
          else {
LAB_00428220:
            iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-rand");
            if (iVar14 == 0) {
              iVar14 = param_4 + -1;
              if (iVar14 == 0) goto LAB_004282a0;
              pcStack_11c = param_7[1];
              ppcVar18 = param_7 + 1;
              param_4 = iVar14;
            }
            else {
              iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,&DAT_00632514);
              if (iVar14 == 0) {
                iVar14 = param_4 + -1;
                if (iVar14 == 0) goto LAB_004282a0;
                pcStack_10c = param_7[1];
                ppcVar18 = param_7 + 1;
                param_4 = iVar14;
              }
              else {
                iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-sign");
                if (iVar14 == 0) {
                  iVar14 = param_4 + -1;
                  if (iVar14 == 0) goto LAB_004282a0;
                  pcStack_110 = param_7[1];
                  ppcVar18 = param_7 + 1;
                  param_4 = iVar14;
                }
                else {
                  iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-passin");
                  if (iVar14 == 0) {
                    iVar14 = param_4 + -1;
                    if (iVar14 == 0) goto LAB_004282a0;
                    pcStack_fc = param_7[1];
                    ppcVar18 = param_7 + 1;
                    param_4 = iVar14;
                  }
                  else {
                    iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-verify");
                    if (iVar14 == 0) {
                      iVar14 = param_4 + -1;
                      if (iVar14 == 0) goto LAB_004282a0;
                      pcStack_110 = param_7[1];
                      bVar2 = true;
                      bVar4 = true;
                      ppcVar18 = param_7 + 1;
                      param_4 = iVar14;
                    }
                    else {
                      iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-prverify");
                      if (iVar14 == 0) {
                        iVar14 = param_4 + -1;
                        if (iVar14 == 0) goto LAB_004282a0;
                        pcStack_110 = param_7[1];
                        bVar2 = true;
                        ppcVar18 = param_7 + 1;
                        param_4 = iVar14;
                      }
                      else {
                        iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-signature");
                        if (iVar14 == 0) {
                          iVar14 = param_4 + -1;
                          if (iVar14 == 0) goto LAB_004282a0;
                          pcStack_ec = param_7[1];
                          ppcVar18 = param_7 + 1;
                          param_4 = iVar14;
                        }
                        else {
                          iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-keyform");
                          if (iVar14 == 0) {
                            iVar14 = param_4 + -1;
                            if (iVar14 == 0) goto LAB_004282a0;
                            uStack_d4 = (*(code *)PTR_str2fmt_006a6e4c)(param_7[1]);
                            ppcVar18 = param_7 + 1;
                            param_4 = iVar14;
                          }
                          else {
                            iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-engine");
                            if (iVar14 == 0) {
                              iVar14 = param_4 + -1;
                              if (iVar14 == 0) goto LAB_004282a0;
                              uStack_e4 = (*(code *)PTR_setup_engine_006a6ec4)(*puVar8,param_7[1],0)
                              ;
                              ppcVar18 = param_7 + 1;
                              param_4 = iVar14;
                            }
                            else {
                              iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,&DAT_00633928);
                              if (iVar14 == 0) {
                                uStack_108 = 0;
                              }
                              else {
                                iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-binary");
                                if (iVar14 == 0) {
                                  uStack_108 = 1;
                                }
                                else if ((cVar1 == 'd') && (pcVar16[2] == '\0')) {
                                  bVar3 = true;
                                }
                                else {
                                  iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                     (pcVar16,"-fips-fingerprint");
                                  if (iVar14 == 0) {
                                    pcStack_e8 = "etaonrishdlcupfm";
                                  }
                                  else {
                                    iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                       (pcVar16,"-non-fips-allow");
                                    if (iVar14 == 0) {
                                      bVar5 = true;
                                    }
                                    else {
                                      iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-hmac");
                                      if (iVar14 == 0) {
                                        iVar14 = param_4 + -1;
                                        if (iVar14 == 0) goto LAB_004282a0;
                                        pcStack_e8 = param_7[1];
                                        ppcVar18 = param_7 + 1;
                                        param_4 = iVar14;
                                      }
                                      else {
                                        iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-mac");
                                        if (iVar14 == 0) {
                                          iVar14 = param_4 + -1;
                                          if (iVar14 == 0) goto LAB_004282a0;
                                          pcStack_f4 = param_7[1];
                                          ppcVar18 = param_7 + 1;
                                          param_4 = iVar14;
                                        }
                                        else {
                                          iVar14 = (*(code *)PTR_strcmp_006a9b18)(pcVar16,"-sigopt")
                                          ;
                                          if (iVar14 == 0) {
                                            iVar14 = param_4 + -1;
                                            if (param_4 + -1 == 0) goto LAB_004282a0;
                                            iVar13 = iStack_120;
                                            if (iStack_120 == 0) {
                                              iVar13 = (*(code *)PTR_sk_new_null_006a6fa4)();
                                              iStack_120 = iVar13;
joined_r0x004293ac:
                                              iVar14 = param_4 + -1;
                                              if (iVar13 == 0) goto LAB_004282a0;
                                            }
                                          }
                                          else {
                                            iVar14 = (*(code *)PTR_strcmp_006a9b18)
                                                               (pcVar16,"-macopt");
                                            if (iVar14 != 0) {
                                              iVar7 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)
                                                                (pcVar16 + 1);
                                              iVar14 = param_4;
                                              if (iVar7 != 0) goto joined_r0x00428294;
                                              goto LAB_004282a0;
                                            }
                                            iVar14 = param_4 + -1;
                                            if (param_4 + -1 == 0) goto LAB_004282a0;
                                            iVar13 = param_6;
                                            if (param_6 == 0) {
                                              iVar13 = (*(code *)PTR_sk_new_null_006a6fa4)();
                                              param_6 = iVar13;
                                              goto joined_r0x004293ac;
                                            }
                                          }
                                          ppcVar18 = param_7 + 1;
                                          param_7 = param_7 + 1;
                                          iVar13 = (*(code *)PTR_sk_push_006a6fa8)(iVar13,*ppcVar18)
                                          ;
                                          iVar14 = param_4 + -1;
                                          ppcVar18 = param_7;
                                          param_4 = param_4 + -1;
                                          if (iVar13 == 0) goto LAB_004282a0;
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
        }
        else {
          if ((cVar1 != 'r') || (pcVar16[2] != '\0')) goto LAB_00428220;
          param_11 = (char *)0x2;
        }
joined_r0x00428294:
        iStack_d8 = iVar7;
        param_4 = param_4 + -1;
        param_7 = ppcVar18 + 1;
        iVar14 = param_4;
        if ((param_4 == 0) || (pcVar16 = ppcVar18[1], *pcVar16 != '-')) goto LAB_004282a0;
      } while( true );
    }
    bVar5 = false;
    pcStack_f4 = (char *)0x0;
    param_11 = (char *)0x0;
    pcStack_e8 = (char *)0x0;
    param_6 = 0;
    uStack_108 = 0xffffffff;
    pcStack_fc = (char *)0x0;
    bVar2 = false;
    bVar4 = false;
    pcStack_11c = (char *)0x0;
    pcStack_ec = (char *)0x0;
    pcStack_110 = (char *)0x0;
    pcStack_10c = (char *)0x0;
    uStack_d4 = 3;
    bVar3 = false;
    uStack_e4 = 0;
    iStack_120 = 0;
    goto LAB_004282ac;
  }
  param_6 = 0;
  iStack_120 = 0;
  iVar14 = param_4;
LAB_00428038:
  ppcVar18 = (char **)0x0;
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar9,0x2000);
  puVar8 = (undefined4 *)0x1;
  param_1 = 0;
  pcVar16 = (char *)0x0;
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar9);
  param_4 = iVar14;
LAB_0042806c:
  do {
    param_9 = iVar9;
    if (iStack_c0 != 0) {
LAB_00428078:
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    (*(code *)PTR_BIO_free_all_006a6e74)(param_1);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(iStack_c4);
    if (iStack_120 != 0) {
      (*(code *)PTR_sk_free_006a6e80)(iStack_120);
    }
    if (param_6 != 0) {
      (*(code *)PTR_sk_free_006a6e80)(param_6);
    }
    if (ppcVar18 != (char **)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(ppcVar18);
    }
    iVar9 = param_9;
    if ((undefined4 *)pcVar16 != (undefined4 *)0x0) {
      (*(code *)PTR_BIO_free_006a6e70)(pcVar16);
    }
LAB_004280fc:
    if (iStack_8c == *(int *)puVar6) {
      return puVar8;
    }
    pcVar19 = (code *)PTR___stack_chk_fail_006a9ab0;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004291b4:
    iStack_d8 = (*pcVar19)();
LAB_00428f18:
    iVar7 = (*(code *)PTR_BIO_ctrl_006a6e18)(pcVar16,0x6f,0,iStack_d8);
    if (iVar7 == 0) {
      ppcVar18 = (char **)0x0;
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"Error setting digest %s\n",puStack_cc);
      uVar15 = *puVar8;
      puVar8 = (undefined4 *)0x1;
      (*(code *)PTR_ERR_print_errors_006a6e40)(uVar15);
      ppcVar10 = param_7;
    }
    else {
LAB_00428884:
      ppcVar10 = param_7;
      if ((pcStack_ec == (char *)0x0) || (iStack_c4 == 0)) {
        pcStack_11c = (char *)0x0;
        ppcVar18 = (char **)0x0;
LAB_0042892c:
        uVar15 = (*(code *)PTR_BIO_push_006a74c4)(pcVar16,puStack_118);
        if (iStack_d8 == 0) {
          (*(code *)PTR_BIO_ctrl_006a6e18)(pcVar16,0x78,0,&iStack_b8);
          iStack_d8 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(iStack_b8);
        }
        if (param_4 == 0) {
          (*(code *)PTR_BIO_ctrl_006a6e18)(puStack_118,0x6a,0,*(undefined4 *)PTR_stdin_006a9a14);
          puVar8 = (undefined4 *)
                   do_fp(param_1,iVar9,uVar15,param_11,uStack_108,iStack_c4,ppcVar18,pcStack_11c,0,0
                         ,"stdin",pcVar16);
        }
        else {
          iStack_b8 = 0;
          if (uStack_108 == 0) {
            if ((iStack_c4 != 0) &&
               (iVar7 = (*(code *)PTR_EVP_PKEY_get0_asn1_006a74fc)(), iVar7 != 0)) {
              (*(code *)PTR_EVP_PKEY_asn1_get0_info_006a6fc0)(0,0,0,0,&iStack_b8,iVar7);
            }
            uVar11 = (*(code *)PTR_EVP_MD_type_006a73cc)(iStack_d8);
            iStack_114 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar11);
          }
          else {
            iStack_114 = 0;
          }
          puVar8 = (undefined4 *)0x0;
          if (0 < param_4) {
            iVar7 = 0;
            do {
              iVar14 = (*(code *)PTR_BIO_ctrl_006a6e18)(puStack_118,0x6c,3,*param_7);
              if (iVar14 < 1) {
                puVar8 = (undefined4 *)((int)puVar8 + 1);
                (*(code *)PTR_perror_006a9a80)(*param_7);
              }
              else {
                puVar12 = (undefined4 *)
                          do_fp(param_1,iVar9,uVar15,param_11,uStack_108,iStack_c4,ppcVar18,
                                pcStack_11c,iStack_b8,iStack_114,*param_7,pcVar16);
                if (puVar12 != (undefined4 *)0x0) {
                  puVar8 = puVar12;
                }
                (*(code *)PTR_BIO_ctrl_006a6e18)(pcVar16,1,0,0);
              }
              iVar7 = iVar7 + 1;
              param_7 = param_7 + 1;
              ppcVar10 = ppcVar18;
            } while (param_4 != iVar7);
          }
        }
      }
      else {
        iVar7 = (*(code *)PTR_BIO_new_file_006a6eac)(pcStack_ec,&DAT_00633e40);
        uVar15 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(iStack_c4);
        ppcVar18 = (char **)(*(code *)PTR_CRYPTO_malloc_006a7008)(uVar15,iStack_114 + 0x38f0,0x1bd);
        if (iVar7 == 0) {
          uVar15 = *puVar8;
          pcVar17 = "Error opening signature file %s\n";
LAB_004291ec:
          (*(code *)PTR_BIO_printf_006a6e38)(uVar15,pcVar17,pcStack_ec);
        }
        else {
          if (ppcVar18 != (char **)0x0) {
            pcStack_11c = (char *)(*(code *)PTR_BIO_read_006a74c0)(iVar7,ppcVar18,uVar15);
            (*(code *)PTR_BIO_free_006a6e70)(iVar7);
            if (0 < (int)pcStack_11c) goto LAB_0042892c;
            uVar15 = *puVar8;
            pcVar17 = "Error reading signature file %s\n";
            goto LAB_004291ec;
          }
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"Out of memory\n");
        }
        uVar15 = *puVar8;
        puVar8 = (undefined4 *)0x1;
        (*(code *)PTR_ERR_print_errors_006a6e40)(uVar15);
      }
    }
LAB_004283f8:
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar9,0x2000);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar9);
    param_7 = ppcVar10;
LAB_00428420:
    (*(code *)PTR_BIO_free_006a6e70)(puStack_118);
  } while( true );
LAB_004282a0:
  param_4 = iVar14;
  if ((bVar2) && (pcStack_ec == (char *)0x0)) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar8,"No signature to verify: use the -signature option\n");
  }
  else {
LAB_004282ac:
    if ((param_4 < 1) || (**param_7 != '-')) {
      uVar15 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      puStack_118 = (undefined *)(*(code *)PTR_BIO_new_006a6ea4)(uVar15);
      uVar15 = (*(code *)PTR_BIO_f_md_006a74d8)();
      pcVar16 = (char *)(*(code *)PTR_BIO_new_006a6ea4)(uVar15);
      if ((puStack_118 == (undefined *)0x0) || ((undefined4 *)pcVar16 == (undefined4 *)0x0)) {
        (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar8);
        (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar9,0x2000);
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar9);
        if (puStack_118 != (undefined *)0x0) {
          param_1 = 0;
          puVar8 = (undefined4 *)0x1;
          ppcVar18 = (char **)0x0;
          goto LAB_00428420;
        }
        ppcVar18 = (char **)0x0;
        puVar8 = (undefined4 *)0x1;
        param_1 = 0;
        goto LAB_0042806c;
      }
      if (bVar3) {
        (*(code *)PTR_BIO_set_callback_006a74dc)(puStack_118,PTR_BIO_debug_callback_006a74e0);
        (*(code *)PTR_BIO_set_callback_arg_006a74e4)(puStack_118,*puVar8);
      }
      iVar7 = (*(code *)PTR_app_passwd_006a6e54)(*puVar8,pcStack_fc,0,&iStack_c0,0);
      ppcVar10 = param_7;
      if (iVar7 == 0) {
        ppcVar18 = (char **)0x0;
        param_1 = 0;
        puVar8 = (undefined4 *)0x1;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)PTR_bio_err_006a6e3c,"Error getting password\n");
        goto LAB_004283f8;
      }
      if (uStack_108 == 0xffffffff) {
        uStack_108 = (uint)(pcStack_110 != (char *)0x0);
      }
      if (pcStack_11c != (char *)0x0) {
        (*(code *)PTR_app_RAND_load_file_006a6ecc)(pcStack_11c,*puVar8,0);
      }
      if (pcStack_10c == (char *)0x0) {
        param_1 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
        if (param_1 == 0) {
          uVar15 = *puVar8;
          pcStack_10c = "(stdout)";
          goto LAB_00428e40;
        }
      }
      else {
        if (uStack_108 == 0) {
          param_1 = (*(code *)PTR_BIO_new_file_006a6eac)(pcStack_10c,"w");
        }
        else {
          param_1 = (*(code *)PTR_BIO_new_file_006a6eac)(pcStack_10c,&DAT_00632420);
        }
        if (param_1 == 0) {
          uVar15 = *puVar8;
LAB_00428e40:
          ppcVar18 = (char **)0x0;
          param_1 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)(uVar15,"Error opening output file %s\n",pcStack_10c);
          uVar15 = *puVar8;
          puVar8 = (undefined4 *)0x1;
          (*(code *)PTR_ERR_print_errors_006a6e40)(uVar15);
          goto LAB_004283f8;
        }
      }
      if (1 < (byte)((pcStack_f4 != (char *)0x0) + (pcStack_110 != (char *)0x0) +
                    (pcStack_e8 != (char *)0x0))) {
        uVar15 = *puVar8;
        ppcVar18 = (char **)0x0;
        puVar8 = (undefined4 *)0x1;
        (*(code *)PTR_BIO_printf_006a6e38)(uVar15,"MAC and Signing key cannot both be specified\n");
        goto LAB_004283f8;
      }
      if (pcStack_110 != (char *)0x0) {
        pcVar19 = (code *)PTR_load_key_006a6ec8;
        iVar7 = iStack_c0;
        if (bVar4) {
          pcVar19 = (code *)PTR_load_pubkey_006a74e8;
          iVar7 = 0;
        }
        iStack_c4 = (*pcVar19)(*puVar8,pcStack_110,uStack_d4,0,iVar7,uStack_e4,"key file");
        if (iStack_c4 == 0) goto LAB_00428d90;
      }
      if (pcStack_f4 == (char *)0x0) {
LAB_0042877c:
        if (bVar5) {
          (*(code *)PTR_BIO_ctrl_006a6e18)(pcVar16,0x78,0,&iStack_b8);
          (*(code *)PTR_EVP_MD_CTX_set_flags_006a7504)(iStack_b8,8);
        }
        if (pcStack_e8 == (char *)0x0) {
          if (iStack_c4 == 0) {
            pcVar19 = (code *)PTR_EVP_md5_006a70c8;
            if (iStack_d8 == 0) goto LAB_004291b4;
            goto LAB_00428f18;
          }
        }
        else {
          iStack_c4 = (*(code *)PTR_EVP_PKEY_new_mac_key_006a74f0)
                                (0x357,uStack_e4,pcStack_e8,0xffffffff);
          ppcVar10 = param_7;
          if (iStack_c4 == 0) goto LAB_00428d90;
        }
        uStack_bc = 0;
        iStack_b8 = 0;
        iVar7 = (*(code *)PTR_BIO_ctrl_006a6e18)(pcVar16,0x78,0,&uStack_bc);
        if (iVar7 == 0) {
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"Error getting context\n");
        }
        else {
          pcVar19 = (code *)PTR_EVP_DigestSignInit_006a6e20;
          if (bVar2) {
            pcVar19 = (code *)PTR_EVP_DigestVerifyInit_006a74f4;
          }
          iVar7 = (*pcVar19)(uStack_bc,&iStack_b8,iStack_d8,0,iStack_c4);
          if (iVar7 == 0) {
            (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"Error setting context\n");
          }
          else {
            if (iStack_120 == 0) goto LAB_00428884;
            iVar7 = 0;
            while( true ) {
              iVar14 = (*(code *)PTR_sk_num_006a6e2c)(iStack_120);
              if (iVar14 <= iVar7) goto LAB_00428884;
              uVar15 = (*(code *)PTR_sk_value_006a6e24)(iStack_120,iVar7);
              iVar14 = (*(code *)PTR_pkey_ctrl_string_006a6e28)(iStack_b8,uVar15);
              if (iVar14 < 1) break;
              iVar7 = iVar7 + 1;
            }
            (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"parameter error \"%s\"\n",uVar15);
          }
        }
        (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar8);
        ppcVar10 = param_7;
      }
      else {
        iStack_b8 = 0;
        iVar7 = init_gen_str(*puVar8,&iStack_b8,pcStack_f4,uStack_e4,0);
        if (iVar7 != 0) {
          if (param_6 != 0) {
            for (iVar7 = 0; iVar14 = (*(code *)PTR_sk_num_006a6e2c)(param_6), iVar7 < iVar14;
                iVar7 = iVar7 + 1) {
              ppcVar10 = (char **)(*(code *)PTR_sk_value_006a6e24)(param_6,iVar7);
              iVar14 = (*(code *)PTR_pkey_ctrl_string_006a6e28)(iStack_b8,ppcVar10);
              if (iVar14 < 1) {
                (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"MAC parameter error \"%s\"\n",ppcVar10);
                goto LAB_00428db8;
              }
            }
          }
          iVar7 = (*(code *)PTR_EVP_PKEY_keygen_006a6f48)(iStack_b8,&iStack_c4);
          if (0 < iVar7) {
            if (iStack_b8 != 0) {
              (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)();
            }
            goto LAB_0042877c;
          }
          (*(code *)PTR_BIO_puts_006a6f58)(*puVar8,"Error generating key\n");
          ppcVar10 = param_7;
LAB_00428db8:
          (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar8);
        }
        if (iStack_b8 != 0) {
          ppcVar18 = (char **)0x0;
          puVar8 = (undefined4 *)0x1;
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)();
          goto LAB_004283f8;
        }
      }
LAB_00428d90:
      ppcVar18 = (char **)0x0;
      puVar8 = (undefined4 *)0x1;
      goto LAB_004283f8;
    }
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"unknown option \'%s\'\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"options are\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar8,"-c              to output the digest with separating colons\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar8,"-r              to output the digest in coreutils format\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"-d              to output debug info\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"-hex            output as hex dump\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"-binary         output in binary form\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"-hmac arg       set the HMAC key to arg\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"-non-fips-allow allow use of non FIPS digest\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar8,"-sign   file    sign digest using private key in file\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar8,"-verify file    verify a signature using public key in file\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar8,"-prverify file  verify a signature using private key in file\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"-keyform arg    key file format (PEM or ENGINE)\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar8,"-out filename   output to filename rather than stdout\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"-signature file signature to verify\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"-sigopt nm:v    signature parameter\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"-hmac key       create hashed MAC with key\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar8,"-mac algorithm  create MAC (not neccessarily HMAC)\n");
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar8,"-macopt nm:v    MAC algorithm parameters or key\n");
    (*(code *)PTR_BIO_printf_006a6e38)
              (*puVar8,"-engine e       use engine e, possibly a hardware device.\n");
    (*(code *)PTR_EVP_MD_do_all_sorted_006a73c0)(list_md_fn,*puVar8);
    iVar14 = param_4;
  }
  goto LAB_00428038;
}

