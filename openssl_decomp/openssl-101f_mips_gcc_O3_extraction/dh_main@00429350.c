
undefined4 dh_main(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  undefined *puVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  char *pcVar15;
  undefined4 uVar16;
  char *unaff_s2;
  int unaff_s4;
  int unaff_s5;
  int iVar17;
  undefined4 *unaff_s6;
  undefined4 *unaff_s7;
  undefined *unaff_s8;
  undefined *puVar18;
  int iStack_134;
  int iStack_128;
  undefined4 uStack_120;
  int iStack_118;
  int iStack_108;
  int iStack_ec;
  uint uStack_e8;
  undefined4 uStack_e4;
  code *pcStack_e0;
  int iStack_dc;
  undefined *puStack_d8;
  undefined4 *puStack_d4;
  undefined4 *puStack_d0;
  undefined4 uStack_cc;
  int iStack_c8;
  int iStack_c4;
  undefined4 *puStack_c0;
  undefined4 *puStack_bc;
  undefined *puStack_b8;
  code *pcStack_b4;
  undefined *puStack_a0;
  undefined uStack_95;
  int iStack_94;
  undefined4 *puStack_8c;
  undefined4 *puStack_88;
  code *pcStack_84;
  undefined *local_70;
  char *local_64;
  undefined *local_60;
  int *local_5c;
  int local_58;
  int local_54;
  undefined4 local_50;
  undefined4 *local_4c;
  char *local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  int local_2c;
  
  puVar7 = PTR_bio_err_006a7f3c;
  local_5c = (int *)PTR___stack_chk_guard_006aabf0;
  local_70 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar12 = *(int *)puVar7;
  if (iVar12 == 0) {
    uVar8 = (**(code **)(local_70 + -0x7f40))();
    iVar12 = (**(code **)(local_70 + -0x7f3c))(uVar8);
    *(int *)puVar7 = iVar12;
    if (iVar12 != 0) {
      param_3 = (undefined4 *)&SUB_00000010;
      (**(code **)(local_70 + -0x7fc8))(iVar12,0x6a,0x10,**(undefined4 **)(local_70 + -0x52e0));
      iVar12 = *(int *)puVar7;
    }
  }
  iVar12 = (**(code **)(local_70 + -0x7f7c))(iVar12,0);
  puStack_b8 = unaff_s8;
  if (iVar12 == 0) {
LAB_00429730:
    uStack_cc = 1;
  }
  else {
    local_4c = (undefined4 *)*param_2;
    puVar18 = (undefined *)((int)param_1 + -1);
    unaff_s7 = param_2 + 1;
    local_50 = 0;
    local_58 = 0;
    unaff_s5 = 3;
    local_64 = (char *)0x0;
    unaff_s4 = 3;
    local_34 = 0;
    local_38 = 0;
    local_44 = 0;
    local_3c = 0;
    if (0 < (int)puVar18) {
      unaff_s6 = (undefined4 *)0x630000;
      param_1 = (undefined4 *)0x630000;
      unaff_s2 = "-outform";
      local_60 = &DAT_00632edc;
      local_54 = 0x630000;
      local_48 = "-check";
      local_40 = 0x630000;
LAB_00429474:
      do {
        param_2 = (undefined4 *)*unaff_s7;
        iVar12 = (**(code **)(local_70 + -0x52c0))(param_2,"-inform");
        if (iVar12 == 0) {
          puStack_b8 = puVar18 + -1;
          if (puStack_b8 != (undefined *)0x0) {
            param_2 = unaff_s7 + 1;
            unaff_s4 = (**(code **)(local_70 + -0x7f94))(unaff_s7[1]);
            goto LAB_00429468;
          }
LAB_00429624:
          param_3 = local_4c;
          (**(code **)(local_70 + -0x7fa8))(*(undefined4 *)puVar7,"%s [options] <infile >outfile\n")
          ;
          (**(code **)(local_70 + -0x7fa8))(*(undefined4 *)puVar7,"where options are\n");
          (**(code **)(local_70 + -0x7fa8))
                    (*(undefined4 *)puVar7," -inform arg   input format - one of DER PEM\n");
          (**(code **)(local_70 + -0x7fa8))
                    (*(undefined4 *)puVar7," -outform arg  output format - one of DER PEM\n");
          (**(code **)(local_70 + -0x7fa8))(*(undefined4 *)puVar7," -in arg       input file\n");
          (**(code **)(local_70 + -0x7fa8))(*(undefined4 *)puVar7," -out arg      output file\n");
          (**(code **)(local_70 + -0x7fa8))
                    (*(undefined4 *)puVar7," -check        check the DH parameters\n");
          (**(code **)(local_70 + -0x7fa8))
                    (*(undefined4 *)puVar7," -text         print a text form of the DH parameters\n"
                    );
          (**(code **)(local_70 + -0x7fa8))(*(undefined4 *)puVar7," -C            Output C code\n");
          (**(code **)(local_70 + -0x7fa8))(*(undefined4 *)puVar7," -noout        no output\n");
          (**(code **)(local_70 + -0x7fa8))
                    (*(undefined4 *)puVar7,
                     " -engine e     use engine e, possibly a hardware device.\n");
          goto LAB_00429730;
        }
        iVar12 = (**(code **)(local_70 + -0x52c0))(param_2,"-outform");
        if (iVar12 != 0) {
          unaff_s6 = (undefined4 *)(0x2d - (uint)*(byte *)param_2);
          if ((((unaff_s6 == (undefined4 *)0x0) && (*(char *)((int)param_2 + 1) == 'i')) &&
              (*(char *)((int)param_2 + 2) == 'n')) && (*(char *)((int)param_2 + 3) == '\0')) {
            puStack_b8 = puVar18 + -1;
            param_2 = unaff_s7 + 1;
            if (puStack_b8 == (undefined *)0x0) goto LAB_00429624;
            local_64 = (char *)unaff_s7[1];
          }
          else {
            iVar12 = (**(code **)(local_70 + -0x52c0))(param_2,local_60);
            if (iVar12 == 0) {
              puStack_b8 = puVar18 + -1;
              param_2 = unaff_s7 + 1;
              if (puStack_b8 == (undefined *)0x0) goto LAB_00429624;
              local_58 = unaff_s7[1];
            }
            else {
              iVar12 = (**(code **)(local_70 + -0x52c0))(param_2,local_54 + 0x2884);
              if (iVar12 == 0) {
                puStack_b8 = puVar18 + -1;
                param_2 = unaff_s7 + 1;
                if (puStack_b8 == (undefined *)0x0) goto LAB_00429624;
                local_50 = unaff_s7[1];
              }
              else {
                iVar12 = (**(code **)(local_70 + -0x52c0))(param_2,local_48);
                puStack_b8 = puVar18;
                if (iVar12 == 0) {
                  local_44 = 1;
                  param_2 = unaff_s7;
                }
                else {
                  iVar12 = (**(code **)(local_70 + -0x52c0))(param_2,local_40 + 0x3174);
                  if (iVar12 == 0) {
                    local_3c = 1;
                    param_2 = unaff_s7;
                  }
                  else if (((unaff_s6 == (undefined4 *)0x0) && (*(char *)((int)param_2 + 1) == 'C'))
                          && (*(char *)((int)param_2 + 2) == '\0')) {
                    local_34 = 1;
                    param_2 = unaff_s7;
                  }
                  else {
                    iVar12 = (**(code **)(local_70 + -0x52c0))(param_2,"-noout");
                    if (iVar12 != 0) {
                      (**(code **)(local_70 + -0x7fa8))
                                (*(undefined4 *)puVar7,"unknown option %s\n",param_2);
                      goto LAB_00429624;
                    }
                    local_38 = 1;
                    param_2 = unaff_s7;
                  }
                }
              }
            }
          }
LAB_00429468:
          puVar18 = puStack_b8 + -1;
          unaff_s7 = param_2 + 1;
          if (puVar18 == (undefined *)0x0) break;
          goto LAB_00429474;
        }
        puStack_b8 = puVar18 + -1;
        if (puVar18 + -1 == (undefined *)0x0) goto LAB_00429624;
        puVar14 = unaff_s7 + 1;
        puVar18 = puVar18 + -2;
        unaff_s7 = unaff_s7 + 2;
        unaff_s5 = (**(code **)(local_70 + -0x7f94))(*puVar14);
      } while (puVar18 != (undefined *)0x0);
    }
    unaff_s2 = *(char **)(local_70 + -0x7fa4);
    (**(code **)(local_70 + -0x7f90))();
    param_3 = (undefined4 *)0x0;
    (**(code **)(local_70 + -0x7f1c))(*(undefined4 *)puVar7,local_50);
    uVar8 = (**(code **)(local_70 + -0x7f40))();
    param_1 = (undefined4 *)(**(code **)(local_70 + -0x7f3c))(uVar8);
    uVar8 = (**(code **)(local_70 + -0x7f40))();
    param_2 = (undefined4 *)(**(code **)(local_70 + -0x7f3c))(uVar8);
    if (param_1 == (undefined4 *)0x0) {
      (**(code **)(local_70 + -0x7fa0))(*(undefined4 *)unaff_s2);
      puStack_b8 = puVar18;
      if (param_2 == (undefined4 *)0x0) goto LAB_00429730;
      unaff_s2 = (char *)0x0;
      uStack_cc = 1;
LAB_004295e0:
      (**(code **)(local_70 + -0x7f6c))(param_2);
    }
    else {
      if (param_2 == (undefined4 *)0x0) {
        uStack_cc = 1;
        uVar8 = *(undefined4 *)unaff_s2;
        unaff_s2 = (char *)0x0;
        (**(code **)(local_70 + -0x7fa0))(uVar8);
      }
      else {
        if (local_64 == (char *)0x0) {
          (**(code **)(local_70 + -0x7fc8))(param_1,0x6a,0,**(undefined4 **)(local_70 + -0x53c0));
        }
        else {
          param_3 = (undefined4 *)0x3;
          iVar12 = (**(code **)(local_70 + -0x7fc8))(param_1,0x6c,3,local_64);
          if (iVar12 < 1) {
            uStack_cc = 1;
            unaff_s2 = (char *)0x0;
            (**(code **)(local_70 + -0x5358))(local_64);
            goto LAB_004295cc;
          }
        }
        if (local_58 == 0) {
          param_3 = (undefined4 *)0x0;
          (**(code **)(local_70 + -0x7fc8))(param_2,0x6a,0,**(undefined4 **)(local_70 + -0x540c));
        }
        else {
          param_3 = (undefined4 *)&DAT_00000005;
          iVar12 = (**(code **)(local_70 + -0x7fc8))(param_2,0x6c,5,local_58);
          if (iVar12 < 1) {
            uStack_cc = 1;
            unaff_s2 = (char *)0x0;
            (**(code **)(local_70 + -0x5358))(local_58);
            goto LAB_004295cc;
          }
        }
        if (unaff_s4 == 1) {
          param_3 = param_1;
          unaff_s2 = (char *)(**(code **)(local_70 + -0x7c1c))
                                       (*(undefined4 *)(local_70 + -0x78c8),
                                        *(undefined4 *)(local_70 + -0x78cc),param_1,0);
        }
        else {
          if (unaff_s4 != 3) {
            unaff_s2 = (char *)0x0;
            uStack_cc = 1;
            (**(code **)(local_70 + -0x7fa8))(*(undefined4 *)puVar7,"bad input format specified\n");
            goto LAB_004295cc;
          }
          param_3 = (undefined4 *)0x0;
          unaff_s2 = (char *)(**(code **)(local_70 + -0x78d8))(param_1,0,0,0);
        }
        if ((undefined4 *)unaff_s2 == (undefined4 *)0x0) {
          (**(code **)(local_70 + -0x7fa8))(*(undefined4 *)puVar7,"unable to load DH parameters\n");
          uStack_cc = 1;
          (**(code **)(local_70 + -0x7fa0))(*(undefined4 *)puVar7);
        }
        else {
          if (local_3c != 0) {
            (**(code **)(local_70 + -0x78d4))(param_2,unaff_s2);
          }
          if (local_44 != 0) {
            iVar12 = (**(code **)(local_70 + -0x78d0))(unaff_s2,&local_30);
            if (iVar12 == 0) {
              uStack_cc = 1;
              (**(code **)(local_70 + -0x7fa0))(*(undefined4 *)puVar7);
              goto LAB_004295cc;
            }
            if ((local_30 & 1) != 0) {
              (**(code **)(local_70 + -0x5380))("p value is not prime");
            }
            if ((local_30 & 2) != 0) {
              (**(code **)(local_70 + -0x5380))("p value is not a safe prime");
            }
            if ((local_30 & 4) != 0) {
              (**(code **)(local_70 + -0x5380))("unable to check the generator value");
            }
            if ((local_30 & 8) != 0) {
              (**(code **)(local_70 + -0x5380))("the g value is not a generator");
            }
            if (local_30 == 0) {
              (**(code **)(local_70 + -0x5380))("DH parameters appear to be ok.");
            }
          }
          if (local_34 != 0) {
            iVar13 = (**(code **)(local_70 + -0x7bec))(*(undefined4 *)((int)unaff_s2 + 8));
            unaff_s6 = (undefined4 *)
                       (**(code **)(local_70 + -0x7bec))(*(undefined4 *)((int)unaff_s2 + 8));
            iVar12 = iVar13 + 7;
            if (iVar13 + 7 < 0) {
              iVar12 = iVar13 + 0xe;
            }
            param_3 = (undefined4 *)0x11e;
            unaff_s4 = (**(code **)(local_70 + -0x7dd8))(iVar12 >> 3,&DAT_006349f8);
            if (unaff_s4 == 0) {
              uStack_cc = 1;
              (**(code **)(local_70 + -0x5358))("OPENSSL_malloc");
              goto LAB_004295cc;
            }
            iVar12 = (**(code **)(local_70 + -0x7be0))(*(undefined4 *)((int)unaff_s2 + 8),unaff_s4);
            (**(code **)(local_70 + -0x5410))(1,"static unsigned char dh%d_p[]={",unaff_s6);
            local_30 = 0;
            if (0 < iVar12) {
              local_64 = "0x%02X,";
              local_60 = &DAT_00634a58;
              unaff_s7 = (undefined4 *)0x2aaaaaab;
              do {
                if (local_30 == ((int)local_30 / 0xc) * 0xc) {
                  (**(code **)(local_70 + -0x5410))(1,local_60);
                }
                (**(code **)(local_70 + -0x5410))(1,local_64,*(undefined *)(unaff_s4 + local_30));
                local_30 = local_30 + 1;
              } while ((int)local_30 < iVar12);
            }
            (**(code **)(local_70 + -0x5380))(&DAT_00634a30);
            puVar18 = (undefined *)
                      (**(code **)(local_70 + -0x7be0))
                                (*(undefined4 *)((int)unaff_s2 + 0xc),unaff_s4);
            (**(code **)(local_70 + -0x5410))(1,"static unsigned char dh%d_g[]={",unaff_s6);
            local_30 = 0;
            if (0 < (int)puVar18) {
              local_64 = "0x%02X,";
              local_60 = &DAT_00634a58;
              unaff_s7 = (undefined4 *)0x2aaaaaab;
              do {
                if (local_30 == ((int)local_30 / 0xc) * 0xc) {
                  (**(code **)(local_70 + -0x5410))(1,local_60);
                }
                (**(code **)(local_70 + -0x5410))(1,local_64,*(undefined *)(unaff_s4 + local_30));
                local_30 = local_30 + 1;
              } while ((int)local_30 < (int)puVar18);
            }
            (**(code **)(local_70 + -0x5380))("\n\t};\n");
            (**(code **)(local_70 + -0x5410))(1,"DH *get_dh%d()\n\t{\n",unaff_s6);
            (**(code **)(local_70 + -0x5380))("\tDH *dh;\n");
            (**(code **)(local_70 + -0x5380))("\tif ((dh=DH_new()) == NULL) return(NULL);");
            (**(code **)(local_70 + -0x5410))
                      (1,"\tdh->p=BN_bin2bn(dh%d_p,sizeof(dh%d_p),NULL);\n",unaff_s6,unaff_s6);
            param_3 = unaff_s6;
            (**(code **)(local_70 + -0x5410))
                      (1,"\tdh->g=BN_bin2bn(dh%d_g,sizeof(dh%d_g),NULL);\n",unaff_s6,unaff_s6);
            (**(code **)(local_70 + -0x5380))("\tif ((dh->p == NULL) || (dh->g == NULL))");
            (**(code **)(local_70 + -0x5380))("\t\treturn(NULL);");
            (**(code **)(local_70 + -0x5380))("\treturn(dh);\n\t}");
            (**(code **)(local_70 + -0x7f58))(unaff_s4);
          }
          if (local_38 == 0) {
            if (unaff_s5 == 1) {
              param_3 = (undefined4 *)unaff_s2;
              local_30 = (**(code **)(local_70 + -0x7c48))
                                   (*(undefined4 *)(local_70 + -0x78c4),param_2);
            }
            else {
              if (unaff_s5 != 3) {
                uStack_cc = 1;
                (**(code **)(local_70 + -0x7fa8))
                          (*(undefined4 *)puVar7,"bad output format specified for outfile\n");
                goto LAB_004295cc;
              }
              local_30 = (**(code **)(local_70 + -0x78c0))(param_2,unaff_s2);
            }
            if (local_30 == 0) {
              (**(code **)(local_70 + -0x7fa8))
                        (*(undefined4 *)puVar7,"unable to write DH parameters\n");
              uStack_cc = 1;
              (**(code **)(local_70 + -0x7fa0))(*(undefined4 *)puVar7);
              goto LAB_004295cc;
            }
          }
          uStack_cc = 0;
        }
      }
LAB_004295cc:
      (**(code **)(local_70 + -0x7f70))(param_1);
      if (param_2 != (undefined4 *)0x0) goto LAB_004295e0;
    }
    puStack_b8 = puVar18;
    if ((undefined4 *)unaff_s2 != (undefined4 *)0x0) {
      (**(code **)(local_70 + -0x78dc))(unaff_s2);
    }
  }
  if (local_2c == *local_5c) {
    return uStack_cc;
  }
  pcStack_84 = dh_cb;
  iVar12 = local_2c;
  (**(code **)(local_70 + -0x5328))();
  puStack_d8 = PTR___stack_chk_guard_006aabf0;
  uStack_95 = 0x2a;
  puStack_a0 = &_gp;
  iStack_94 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (iVar12 == 0) {
    uStack_95 = 0x2e;
  }
  else if (iVar12 == 1) {
    uStack_95 = 0x2b;
  }
  else if ((iVar12 != 2) && (iVar12 == 3)) {
    uStack_95 = 10;
  }
  puStack_8c = param_2;
  puStack_88 = param_1;
  (*(code *)PTR_BIO_write_006a7f14)(param_3[1],&uStack_95,1);
  puVar14 = (undefined4 *)&DAT_0000000b;
  (**(code **)(puStack_a0 + -0x7fc8))(param_3[1],0xb,0,0);
  if (iStack_94 == *(int *)puStack_d8) {
    return 1;
  }
  pcStack_b4 = dhparam_main;
  iVar12 = iStack_94;
  (**(code **)(puStack_a0 + -0x5328))();
  puVar18 = PTR___stack_chk_guard_006aabf0;
  puVar7 = PTR_bio_err_006a7f3c;
  iStack_ec = 0;
  iStack_dc = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_d4 = param_3;
  puStack_d0 = (undefined4 *)unaff_s2;
  iStack_c8 = unaff_s4;
  iStack_c4 = unaff_s5;
  puStack_c0 = unaff_s6;
  puStack_bc = unaff_s7;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar13 = *(int *)puVar7;
  if (iVar13 == 0) {
    uVar8 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar13 = (*(code *)PTR_BIO_new_006a7fa4)(uVar8);
    *(int *)puVar7 = iVar13;
    if (iVar13 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar13,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
      iVar13 = *(int *)puVar7;
    }
  }
  iVar13 = (*(code *)PTR_load_config_006a7f64)(iVar13,0);
  if (iVar13 == 0) goto LAB_0042a30c;
  uVar8 = *puVar14;
  iVar12 = iVar12 + -1;
  puVar10 = puVar14 + 1;
  iStack_118 = 0;
  uStack_120 = 0;
  iVar17 = 3;
  iStack_108 = 0;
  iVar13 = 3;
  iStack_128 = 0;
  iStack_134 = 0;
  bVar5 = false;
  bVar6 = false;
  bVar4 = false;
  bVar2 = false;
  bVar3 = false;
  if (0 < iVar12) {
LAB_0042a15c:
    do {
      puVar14 = (undefined4 *)*puVar10;
      iVar9 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-inform");
      if (iVar9 == 0) {
        iVar12 = iVar12 + -1;
        if (iVar12 != 0) {
          iVar13 = (*(code *)PTR_str2fmt_006a7f4c)(puVar10[1]);
          puVar10 = puVar10 + 1;
          goto LAB_0042a150;
        }
LAB_0042a4f4:
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"%s [options] [numbits]\n",uVar8);
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"where options are\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7," -inform arg   input format - one of DER PEM\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7," -outform arg  output format - one of DER PEM\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7," -in arg       input file\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7," -out arg      output file\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,
                   " -dsaparam     read or generate DSA parameters, convert to DH\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7," -check        check the DH parameters\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7," -text         print a text form of the DH parameters\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7," -C            Output C code\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,
                   " -2            generate parameters using  2 as the generator value\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,
                   " -5            generate parameters using  5 as the generator value\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,
                   " numbits       number of bits in to generate (default 512)\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,
                   " -engine e     use engine e, possibly a hardware device.\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7," -rand file%cfile%c...\n",0x3a,0x3a);
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,
                   "               - load the file (or the files in the directory) into\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,"               the random number generator\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7," -noout        no output\n");
        goto LAB_0042a30c;
      }
      iVar9 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-outform");
      if (iVar9 == 0) {
        if (iVar12 == 1) goto LAB_0042a4f4;
        iVar12 = iVar12 + -2;
        iVar17 = (*(code *)PTR_str2fmt_006a7f4c)(puVar10[1]);
        puVar14 = puVar10 + 1;
        puVar10 = puVar10 + 2;
        if (iVar12 == 0) break;
        goto LAB_0042a15c;
      }
      cVar1 = *(char *)puVar14;
      if ((((cVar1 == '-') && (*(char *)((int)puVar14 + 1) == 'i')) &&
          (*(char *)((int)puVar14 + 2) == 'n')) && (*(char *)((int)puVar14 + 3) == '\0')) {
        iVar12 = iVar12 + -1;
        if (iVar12 == 0) goto LAB_0042a4f4;
        iStack_134 = puVar10[1];
        puVar10 = puVar10 + 1;
      }
      else {
        iVar9 = (*(code *)PTR_strcmp_006aac20)(puVar14,&DAT_00632edc);
        if (iVar9 == 0) {
          iVar12 = iVar12 + -1;
          if (iVar12 == 0) goto LAB_0042a4f4;
          iStack_128 = puVar10[1];
          puVar10 = puVar10 + 1;
        }
        else {
          iVar9 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-engine");
          if (iVar9 == 0) {
            iVar12 = iVar12 + -1;
            if (iVar12 == 0) goto LAB_0042a4f4;
            uStack_120 = puVar10[1];
            puVar10 = puVar10 + 1;
          }
          else {
            iVar9 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-check");
            if (iVar9 == 0) {
              bVar4 = true;
            }
            else {
              iVar9 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-text");
              if (iVar9 == 0) {
                bVar3 = true;
              }
              else {
                iVar9 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-dsaparam");
                if (iVar9 == 0) {
                  bVar2 = true;
                }
                else if (cVar1 == '-') {
                  cVar1 = *(char *)((int)puVar14 + 1);
                  if ((cVar1 == 'C') && (*(char *)((int)puVar14 + 2) == '\0')) {
                    bVar5 = true;
                  }
                  else {
                    iVar9 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-noout");
                    if (iVar9 == 0) {
                      bVar6 = true;
                    }
                    else if (cVar1 == '2') {
                      if (*(char *)((int)puVar14 + 2) != '\0') {
LAB_0042a490:
                        iVar9 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-rand");
                        if (iVar9 == 0) {
                          iVar12 = iVar12 + -1;
                          if (iVar12 != 0) {
                            iStack_108 = puVar10[1];
                            puVar10 = puVar10 + 1;
                            goto LAB_0042a150;
                          }
                        }
                        else {
                          iVar9 = (*(code *)PTR___isoc99_sscanf_006aab10)(puVar14,"%d",&iStack_ec);
                          if ((iVar9 != 0) && (0 < iStack_ec)) goto LAB_0042a150;
                        }
                        goto LAB_0042a4f4;
                      }
                      iStack_118 = 2;
                    }
                    else {
                      if ((cVar1 != '5') || (*(char *)((int)puVar14 + 2) != '\0'))
                      goto LAB_0042a490;
                      iStack_118 = 5;
                    }
                  }
                }
                else {
                  iVar9 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-noout");
                  if (iVar9 != 0) goto LAB_0042a490;
                  bVar6 = true;
                }
              }
            }
          }
        }
      }
LAB_0042a150:
      iVar12 = iVar12 + -1;
      puVar14 = puVar10;
      puVar10 = puVar10 + 1;
    } while (iVar12 != 0);
  }
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  (*(code *)PTR_setup_engine_006a7fc4)(*(undefined4 *)puVar7,uStack_120,0);
  if (iStack_118 == 0) {
    if (!bVar2) {
      if (iStack_ec == 0) goto LAB_0042a6d4;
      iStack_118 = 2;
      goto LAB_0042a20c;
    }
    if (iStack_ec != 0) goto LAB_0042a20c;
LAB_0042a6d4:
    uVar8 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar12 = (*(code *)PTR_BIO_new_006a7fa4)(uVar8);
    if (iVar12 == 0) goto LAB_0042a2fc;
    if (iStack_134 != 0) {
      iVar9 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar12,0x6c,3,iStack_134);
      if (0 < iVar9) goto LAB_0042a724;
      (*(code *)PTR_perror_006aab88)(iStack_134);
      goto LAB_0042a74c;
    }
    (*(code *)PTR_BIO_ctrl_006a7f18)(iVar12,0x6a,0,*(undefined4 *)PTR_stdin_006aab20);
LAB_0042a724:
    if (iVar13 != 1) {
      if (iVar13 == 3) {
        if (!bVar2) {
          puVar14 = (undefined4 *)(*(code *)PTR_PEM_read_bio_DHparams_006a8608)(iVar12,0,0,0);
          goto LAB_0042aa7c;
        }
        iVar13 = (*(code *)PTR_PEM_read_bio_DSAparams_006a8634)(iVar12,0,0,0);
LAB_0042a980:
        if (iVar13 != 0) {
          puVar14 = (undefined4 *)(*(code *)PTR_DSA_dup_DH_006a8638)(iVar13);
          (*(code *)PTR_DSA_free_006a862c)(iVar13);
          if (puVar14 != (undefined4 *)0x0) goto LAB_0042a9b4;
          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
          goto LAB_0042a74c;
        }
        uVar8 = *(undefined4 *)puVar7;
        pcVar15 = "unable to load DSA parameters\n";
LAB_0042aa94:
        puVar14 = (undefined4 *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(uVar8,pcVar15);
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"bad input format specified\n");
LAB_0042a74c:
        puVar14 = (undefined4 *)0x0;
      }
LAB_0042a750:
      (*(code *)PTR_BIO_free_006a7f70)(iVar12);
      goto LAB_0042a760;
    }
    if (bVar2) {
      iVar13 = (*(code *)PTR_ASN1_d2i_bio_006a82c4)
                         (PTR_DSA_new_006a8624,PTR_d2i_DSAparams_006a863c,iVar12,0);
      goto LAB_0042a980;
    }
    puVar14 = (undefined4 *)
              (*(code *)PTR_ASN1_d2i_bio_006a82c4)
                        (PTR_DH_new_006a8618,PTR_d2i_DHparams_006a8614,iVar12,0);
LAB_0042aa7c:
    if (puVar14 == (undefined4 *)0x0) {
      uVar8 = *(undefined4 *)puVar7;
      pcVar15 = "unable to load DH parameters\n";
      goto LAB_0042aa94;
    }
LAB_0042a9b4:
    uVar8 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar13 = (*(code *)PTR_BIO_new_006a7fa4)(uVar8);
    if (iVar13 == 0) {
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
      goto LAB_0042a750;
    }
  }
  else {
    if (iStack_ec == 0) {
      iStack_ec = 0x200;
    }
    if (bVar2) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar7,"generator may not be chosen for DSA parameters\n");
      goto LAB_0042a30c;
    }
LAB_0042a20c:
    uStack_e4 = *(undefined4 *)puVar7;
    uStack_e8 = 2;
    pcStack_e0 = dh_cb;
    iVar12 = (*(code *)PTR_app_RAND_load_file_006a7fcc)(0,uStack_e4,1);
    if (iVar12 == 0) {
      if (iStack_108 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,
                   "warning, not much extra random data, consider using the -rand option\n");
      }
      else {
LAB_0042a250:
        uVar16 = *(undefined4 *)puVar7;
        uVar8 = (*(code *)PTR_app_RAND_load_files_006a8038)(iStack_108);
        (*(code *)PTR_BIO_printf_006a7f38)(uVar16,"%ld semi-random bytes loaded\n",uVar8);
      }
    }
    else if (iStack_108 != 0) goto LAB_0042a250;
    if (bVar2) {
      puVar10 = (undefined4 *)(*(code *)PTR_DSA_new_006a8624)();
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar7,"Generating DSA parameters, %d bit long prime\n",iStack_ec);
      puVar14 = puVar10;
      if (puVar10 != (undefined4 *)0x0) {
        iVar12 = (*(code *)PTR_DSA_generate_parameters_ex_006a8628)
                           (puVar10,iStack_ec,0,0,0,0,&uStack_e8);
        if (iVar12 != 0) {
          puVar14 = (undefined4 *)(*(code *)PTR_DSA_dup_DH_006a8638)(puVar10);
          (*(code *)PTR_DSA_free_006a862c)(puVar10);
          if (puVar14 == (undefined4 *)0x0) {
            (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
            goto LAB_0042a30c;
          }
          goto LAB_0042a848;
        }
        (*(code *)PTR_DSA_free_006a862c)(puVar10);
      }
LAB_0042a2fc:
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
LAB_0042a30c:
      uVar8 = 1;
      while (iStack_dc != *(int *)puVar18) {
        (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0042b138:
        uVar8 = 1;
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
LAB_0042a768:
        (*(code *)PTR_DH_free_006a8604)(puVar14);
      }
      return uVar8;
    }
    puVar14 = (undefined4 *)(*(code *)PTR_DH_new_006a8618)();
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar7,
               "Generating DH parameters, %d bit long safe prime, generator %d\n",iStack_ec,
               iStack_118);
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"This is going to take a long time\n");
    if ((puVar14 == (undefined4 *)0x0) ||
       (iVar12 = (*(code *)PTR_DH_generate_parameters_ex_006a8630)
                           (puVar14,iStack_ec,iStack_118,&uStack_e8), iVar12 == 0)) {
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
LAB_0042a760:
      uVar8 = 1;
      if (puVar14 != (undefined4 *)0x0) goto LAB_0042a768;
      goto LAB_0042a30c;
    }
LAB_0042a848:
    (*(code *)PTR_app_RAND_write_file_006a804c)(0,*(undefined4 *)puVar7);
    uVar8 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar13 = (*(code *)PTR_BIO_new_006a7fa4)(uVar8);
    if (iVar13 == 0) goto LAB_0042b138;
    iVar12 = 0;
  }
  if (iStack_128 == 0) {
    (*(code *)PTR_BIO_ctrl_006a7f18)(iVar13,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
  }
  else {
    iVar9 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar13,0x6c,5,iStack_128);
    if (iVar9 < 1) {
      uVar8 = 1;
      (*(code *)PTR_perror_006aab88)(iStack_128);
      goto LAB_0042a90c;
    }
  }
  if (bVar3) {
    (*(code *)PTR_DHparams_print_006a860c)(iVar13,puVar14);
  }
  if (bVar4) {
    iVar9 = (*(code *)PTR_DH_check_006a8610)(puVar14,&uStack_e8);
    if (iVar9 == 0) {
      uVar8 = 1;
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
      goto LAB_0042a90c;
    }
    if ((uStack_e8 & 1) != 0) {
      (*(code *)PTR_puts_006aab60)("p value is not prime");
    }
    if ((uStack_e8 & 2) != 0) {
      (*(code *)PTR_puts_006aab60)("p value is not a safe prime");
    }
    if ((uStack_e8 & 4) != 0) {
      (*(code *)PTR_puts_006aab60)("unable to check the generator value");
    }
    if ((uStack_e8 & 8) != 0) {
      (*(code *)PTR_puts_006aab60)("the g value is not a generator");
    }
    if (uStack_e8 == 0) {
      (*(code *)PTR_puts_006aab60)("DH parameters appear to be ok.");
    }
  }
  if (bVar5) {
    iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar14[2]);
    uVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar14[2]);
    iVar9 = iVar11 + 7;
    if (iVar11 + 7 < 0) {
      iVar9 = iVar11 + 0xe;
    }
    iVar9 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar9 >> 3,"dhparam.c",0x1d2);
    if (iVar9 == 0) {
      uVar8 = 1;
      (*(code *)PTR_perror_006aab88)("OPENSSL_malloc");
      goto LAB_0042a90c;
    }
    (*(code *)PTR_puts_006aab60)("#ifndef HEADER_DH_H\n#include <openssl/dh.h>\n#endif");
    (*(code *)PTR___printf_chk_006aaad0)(1,"DH *get_dh%d()\n\t{\n",uVar8);
    iVar11 = (*(code *)PTR_BN_bn2bin_006a8300)(puVar14[2],iVar9);
    (*(code *)PTR___printf_chk_006aaad0)(1,"\tstatic unsigned char dh%d_p[]={",uVar8);
    uStack_e8 = 0;
    if (0 < iVar11) {
      do {
        if (uStack_e8 == ((int)uStack_e8 / 0xc) * 0xc) {
          (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_00634efc);
        }
        (*(code *)PTR___printf_chk_006aaad0)(1,"0x%02X,",*(undefined *)(iVar9 + uStack_e8));
        uStack_e8 = uStack_e8 + 1;
      } while ((int)uStack_e8 < iVar11);
    }
    (*(code *)PTR_puts_006aab60)("\n\t\t};");
    iVar11 = (*(code *)PTR_BN_bn2bin_006a8300)(puVar14[3],iVar9);
    (*(code *)PTR___printf_chk_006aaad0)(1,"\tstatic unsigned char dh%d_g[]={",uVar8);
    uStack_e8 = 0;
    if (0 < iVar11) {
      do {
        if (uStack_e8 == ((int)uStack_e8 / 0xc) * 0xc) {
          (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_00634efc);
        }
        (*(code *)PTR___printf_chk_006aaad0)(1,"0x%02X,",*(undefined *)(iVar9 + uStack_e8));
        uStack_e8 = uStack_e8 + 1;
      } while ((int)uStack_e8 < iVar11);
    }
    (*(code *)PTR_puts_006aab60)("\n\t\t};");
    (*(code *)PTR_puts_006aab60)("\tDH *dh;\n");
    (*(code *)PTR_puts_006aab60)("\tif ((dh=DH_new()) == NULL) return(NULL);");
    (*(code *)PTR___printf_chk_006aaad0)
              (1,"\tdh->p=BN_bin2bn(dh%d_p,sizeof(dh%d_p),NULL);\n",uVar8,uVar8);
    (*(code *)PTR___printf_chk_006aaad0)
              (1,"\tdh->g=BN_bin2bn(dh%d_g,sizeof(dh%d_g),NULL);\n",uVar8,uVar8);
    (*(code *)PTR_puts_006aab60)("\tif ((dh->p == NULL) || (dh->g == NULL))");
    (*(code *)PTR_puts_006aab60)("\t\t{ DH_free(dh); return(NULL); }");
    if (puVar14[4] != 0) {
      (*(code *)PTR___printf_chk_006aaad0)(1,"\tdh->length = %ld;\n");
    }
    (*(code *)PTR_puts_006aab60)("\treturn(dh);\n\t}");
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar9);
  }
  if (!bVar6) {
    if (iVar17 == 1) {
      uStack_e8 = (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_DHparams_006a861c,iVar13,puVar14);
    }
    else {
      if (iVar17 != 3) {
        uVar8 = 1;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,"bad output format specified for outfile\n");
        goto LAB_0042a90c;
      }
      uStack_e8 = (*(code *)PTR_PEM_write_bio_DHparams_006a8620)(iVar13,puVar14);
    }
    if (uStack_e8 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"unable to write DH parameters\n");
      uVar8 = 1;
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
      goto LAB_0042a90c;
    }
  }
  uVar8 = 0;
LAB_0042a90c:
  if (iVar12 != 0) {
    (*(code *)PTR_BIO_free_006a7f70)(iVar12);
  }
  (*(code *)PTR_BIO_free_all_006a7f74)(iVar13);
  goto LAB_0042a768;
}

