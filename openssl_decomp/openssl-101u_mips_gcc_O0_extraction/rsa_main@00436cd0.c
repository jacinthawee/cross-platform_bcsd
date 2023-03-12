
undefined4 * rsa_main(int param_1,char **param_2)

{
  bool bVar1;
  char cVar2;
  undefined *puVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined *puVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  undefined4 *puVar12;
  undefined *puVar13;
  undefined4 *puVar14;
  char *unaff_s3;
  char *unaff_s4;
  char *unaff_s5;
  undefined *unaff_s6;
  char *pcVar15;
  char **unaff_s7;
  char **ppcVar16;
  code *pcVar17;
  char **unaff_s8;
  char *pcStack_11c;
  int iStack_118;
  char *pcStack_114;
  char *pcStack_110;
  int iStack_10c;
  char *pcStack_108;
  int iStack_104;
  undefined4 uStack_100;
  int iStack_fc;
  int iStack_f8;
  undefined4 uStack_f4;
  int iStack_f0;
  int iStack_ec;
  int iStack_e8;
  int iStack_e0;
  int iStack_dc;
  char **ppcStack_d8;
  int iStack_d4;
  undefined4 *puStack_d0;
  undefined4 *puStack_cc;
  char *pcStack_c8;
  char *pcStack_c4;
  undefined *puStack_c0;
  char **ppcStack_bc;
  char **ppcStack_b8;
  code *pcStack_b4;
  undefined4 ****local_a0;
  undefined4 *local_9c;
  char *local_98;
  undefined *local_90;
  char **local_84;
  int *local_80;
  char *local_7c;
  int local_78;
  char *local_74;
  char *local_70;
  char *local_6c;
  char *local_68;
  int local_64;
  char *local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  undefined4 *local_4c;
  undefined4 local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 ****local_38;
  undefined4 ****local_34;
  char **local_30;
  int local_2c;
  
  puVar3 = PTR_bio_err_006a6e3c;
  local_80 = (int *)PTR___stack_chk_guard_006a9ae8;
  local_90 = &_gp;
  local_38 = (undefined4 ****)0x0;
  local_34 = (undefined4 ****)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iVar8 = *(int *)puVar3;
  if (iVar8 == 0) {
    uVar4 = (**(code **)(local_90 + -0x7f40))();
    iVar8 = (**(code **)(local_90 + -0x7f3c))(uVar4);
    *(int *)puVar3 = iVar8;
    if (iVar8 != 0) {
      (**(code **)(local_90 + -0x7fc8))(iVar8,0x6a,0x10,**(undefined4 **)(local_90 + -0x52e8));
      iVar8 = *(int *)puVar3;
    }
  }
  pcVar10 = (char *)0x0;
  iVar8 = (**(code **)(local_90 + -0x7f7c))(iVar8);
  ppcStack_d8 = param_2;
  if (iVar8 != 0) {
    local_70 = *param_2;
    ppcVar16 = (char **)(param_1 + -1);
    unaff_s8 = param_2 + 1;
    if ((int)ppcVar16 < 1) {
      local_74 = (char *)0x0;
      local_7c = (char *)0x0;
      unaff_s5 = (char *)0x3;
      local_84 = (char **)0x0;
      unaff_s4 = (char *)0x3;
      local_48 = 2;
      local_40 = 0;
      local_60 = (char *)0x0;
      local_68 = (char *)0x0;
      local_58 = 0;
      local_5c = 0;
      local_4c = (undefined4 *)0x0;
      local_50 = 0;
      local_44 = 0;
      local_54 = 0;
      local_3c = 0;
    }
    else {
      local_40 = 0;
      local_60 = (char *)0x0;
      local_68 = (char *)0x0;
      local_48 = 2;
      local_74 = (char *)0x0;
      unaff_s5 = (char *)0x3;
      local_7c = (char *)0x0;
      unaff_s4 = (char *)0x3;
      local_78 = 0x630000;
      local_84 = (char **)0x0;
      param_1 = 0x630000;
      local_58 = 0;
      local_5c = 0;
      unaff_s3 = "-outform";
      local_4c = (undefined4 *)0x0;
      unaff_s6 = &DAT_00632514;
      local_6c = "-passout";
      local_50 = 0;
      local_44 = 0;
      local_64 = 0x630000;
      local_3c = 0;
      local_54 = 0;
      unaff_s7 = unaff_s8;
      unaff_s8 = ppcVar16;
LAB_00436e24:
      do {
        ppcStack_d8 = (char **)*unaff_s7;
        iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,"-inform");
        if (iVar8 == 0) {
          ppcVar16 = (char **)((int)unaff_s8 + -1);
          if (ppcVar16 != (char **)0x0) {
            unaff_s4 = (char *)(**(code **)(local_90 + -0x7f94))(unaff_s7[1]);
            unaff_s7 = unaff_s7 + 1;
            unaff_s8 = ppcVar16;
            goto LAB_00436e18;
          }
LAB_0043717c:
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3,"%s [options] <infile >outfile\n",local_70);
          (**(code **)(local_90 + -0x7fa8))(*(undefined4 *)puVar3,"where options are\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3," -inform arg     input format - one of DER NET PEM\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3," -outform arg    output format - one of DER NET PEM\n");
          (**(code **)(local_90 + -0x7fa8))(*(undefined4 *)puVar3," -in arg         input file\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3," -sgckey         Use IIS SGC key format\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3," -passin arg     input file pass phrase source\n");
          (**(code **)(local_90 + -0x7fa8))(*(undefined4 *)puVar3," -out arg        output file\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3," -passout arg    output file pass phrase source\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3," -des            encrypt PEM output with cbc des\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3,
                     " -des3           encrypt PEM output with ede cbc des using 168 bit key\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3," -idea           encrypt PEM output with cbc idea\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3," -seed           encrypt PEM output with cbc seed\n");
          (**(code **)(local_90 + -0x7fa8))(*(undefined4 *)puVar3," -aes128, -aes192, -aes256\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3,"                 encrypt PEM output with cbc aes\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3," -camellia128, -camellia192, -camellia256\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3,"                 encrypt PEM output with cbc camellia\n"
                    );
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3," -text           print the key in text\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3," -noout          don\'t print key out\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3," -modulus        print the RSA key modulus\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3," -check          verify key consistency\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3," -pubin          expect a public key in input file\n");
          (**(code **)(local_90 + -0x7fa8))
                    (*(undefined4 *)puVar3," -pubout         output a public key\n");
          pcVar10 = " -engine e       use engine e, possibly a hardware device.\n";
          (**(code **)(local_90 + -0x7fa8))(*(undefined4 *)puVar3);
          unaff_s8 = ppcVar16;
          goto LAB_00437034;
        }
        iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,"-outform");
        if (iVar8 == 0) {
          ppcVar16 = (char **)((int)unaff_s8 + -1);
          if ((char **)((int)unaff_s8 + -1) == (char **)0x0) goto LAB_0043717c;
          unaff_s8 = (char **)((int)unaff_s8 + -2);
          ppcVar16 = unaff_s7 + 2;
          unaff_s5 = (char *)(**(code **)(local_90 + -0x7f94))(unaff_s7[1]);
          unaff_s7 = ppcVar16;
          if (unaff_s8 == (char **)0x0) break;
          goto LAB_00436e24;
        }
        if ((((*(char *)ppcStack_d8 == '-') && (*(char *)((int)ppcStack_d8 + 1) == 'i')) &&
            (*(char *)((int)ppcStack_d8 + 2) == 'n')) && (*(char *)((int)ppcStack_d8 + 3) == '\0'))
        {
          ppcVar16 = (char **)((int)unaff_s8 + -1);
          ppcStack_d8 = unaff_s7 + 1;
          if (ppcVar16 == (char **)0x0) goto LAB_0043717c;
          local_84 = (char **)unaff_s7[1];
          unaff_s7 = ppcStack_d8;
          unaff_s8 = ppcVar16;
        }
        else {
          iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,&DAT_00632514);
          if (iVar8 == 0) {
            ppcVar16 = (char **)((int)unaff_s8 + -1);
            ppcStack_d8 = unaff_s7 + 1;
            if (ppcVar16 == (char **)0x0) goto LAB_0043717c;
            local_7c = unaff_s7[1];
            unaff_s7 = ppcStack_d8;
            unaff_s8 = ppcVar16;
          }
          else {
            iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,local_78 + 0x2720);
            if (iVar8 == 0) {
              ppcVar16 = (char **)((int)unaff_s8 + -1);
              ppcStack_d8 = unaff_s7 + 1;
              if (ppcVar16 == (char **)0x0) goto LAB_0043717c;
              local_74 = unaff_s7[1];
              unaff_s7 = ppcStack_d8;
              unaff_s8 = ppcVar16;
            }
            else {
              iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,local_6c);
              if (iVar8 == 0) {
                ppcVar16 = (char **)((int)unaff_s8 + -1);
                ppcStack_d8 = unaff_s7 + 1;
                if (ppcVar16 == (char **)0x0) goto LAB_0043717c;
                local_68 = unaff_s7[1];
                unaff_s7 = ppcStack_d8;
                unaff_s8 = ppcVar16;
              }
              else {
                iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,local_64 + 0x1eb4);
                if (iVar8 == 0) {
                  ppcVar16 = (char **)((int)unaff_s8 + -1);
                  ppcStack_d8 = unaff_s7 + 1;
                  if (ppcVar16 == (char **)0x0) goto LAB_0043717c;
                  local_60 = unaff_s7[1];
                  unaff_s7 = ppcStack_d8;
                  unaff_s8 = ppcVar16;
                }
                else {
                  iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,"-sgckey");
                  if (iVar8 == 0) {
                    local_54 = 1;
                  }
                  else {
                    iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,"-pubin");
                    if (iVar8 == 0) {
                      local_5c = 1;
                    }
                    else {
                      iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,"-pubout");
                      if (iVar8 == 0) {
                        local_58 = 1;
                      }
                      else {
                        iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,"-RSAPublicKey_in");
                        if (iVar8 == 0) {
                          local_5c = 2;
                        }
                        else {
                          iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,"-RSAPublicKey_out")
                          ;
                          if (iVar8 == 0) {
                            local_58 = 2;
                          }
                          else {
                            iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,"-pvk-strong");
                            if (iVar8 == 0) {
                              local_48 = 2;
                            }
                            else {
                              iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,"-pvk-weak");
                              if (iVar8 == 0) {
                                local_48 = 1;
                              }
                              else {
                                iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,"-pvk-none");
                                if (iVar8 == 0) {
                                  local_48 = 0;
                                }
                                else {
                                  iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,"-noout");
                                  if (iVar8 == 0) {
                                    local_4c = (undefined4 *)0x1;
                                  }
                                  else {
                                    iVar8 = (**(code **)(local_90 + -0x52c8))(ppcStack_d8,"-text");
                                    if (iVar8 == 0) {
                                      local_44 = 1;
                                    }
                                    else {
                                      iVar8 = (**(code **)(local_90 + -0x52c8))
                                                        (ppcStack_d8,"-modulus");
                                      if (iVar8 == 0) {
                                        local_40 = 1;
                                      }
                                      else {
                                        iVar8 = (**(code **)(local_90 + -0x52c8))
                                                          (ppcStack_d8,"-check");
                                        if (iVar8 == 0) {
                                          local_50 = 1;
                                        }
                                        else {
                                          local_3c = (**(code **)(local_90 + -0x7a4c))
                                                               ((undefined *)((int)ppcStack_d8 + 1))
                                          ;
                                          if (local_3c == 0) {
                                            (**(code **)(local_90 + -0x7fa8))
                                                      (*(undefined4 *)puVar3,"unknown option %s\n",
                                                       *unaff_s7);
                                            ppcVar16 = unaff_s8;
                                            goto LAB_0043717c;
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
        }
LAB_00436e18:
        unaff_s8 = (char **)((int)unaff_s8 + -1);
        ppcVar16 = unaff_s7 + 1;
        unaff_s7 = ppcVar16;
      } while (unaff_s8 != (char **)0x0);
    }
    ppcStack_d8 = *(char ***)(local_90 + -0x7fa4);
    (**(code **)(local_90 + -0x7f90))();
    unaff_s3 = (char *)(**(code **)(local_90 + -0x7f1c))(*(undefined4 *)puVar3,local_60,0);
    local_a0 = &local_34;
    iVar8 = (**(code **)(local_90 + -0x7f8c))(*(undefined4 *)puVar3,local_74,local_68,&local_38);
    unaff_s7 = ppcVar16;
    if (iVar8 == 0) {
      pcVar10 = "Error getting passwords\n";
      (**(code **)(local_90 + -0x7fa8))(*ppcStack_d8);
    }
    else {
      if (local_50 == 0) {
        uVar4 = (**(code **)(local_90 + -0x7f40))();
        param_1 = (**(code **)(local_90 + -0x7f3c))(uVar4);
        if (local_5c == 0) goto LAB_00436f10;
        if (local_5c == 2) {
          if (unaff_s4 == (char *)0x3) {
            unaff_s4 = &DAT_00000009;
          }
          else {
            bVar1 = unaff_s4 == (char *)0x1;
            unaff_s4 = (char *)0xffffffff;
            if (bVar1) {
              unaff_s4 = &DAT_0000000a;
            }
          }
        }
        else if ((unaff_s4 == &SUB_00000004) && (local_54 != 0)) {
          unaff_s4 = &DAT_00000008;
        }
        local_a0 = local_38;
        local_98 = "Public Key";
        pcVar10 = (char *)local_84;
        local_9c = (undefined4 *)unaff_s3;
        ppcVar16 = (char **)(**(code **)(local_90 + -0x78f8))
                                      (*(undefined4 *)puVar3,local_84,unaff_s4,1);
      }
      else {
        if (local_5c != 0) {
          pcVar10 = "Only private keys can be checked\n";
          (**(code **)(local_90 + -0x7fa8))(*ppcStack_d8);
          goto LAB_00437034;
        }
        uVar4 = (**(code **)(local_90 + -0x7f40))();
        param_1 = (**(code **)(local_90 + -0x7f3c))(uVar4);
LAB_00436f10:
        pcVar15 = unaff_s4;
        if ((unaff_s4 == &SUB_00000004) && (pcVar15 = &DAT_00000008, local_54 == 0)) {
          pcVar15 = unaff_s4;
        }
        local_a0 = local_38;
        local_98 = "Private Key";
        pcVar10 = (char *)local_84;
        local_9c = (undefined4 *)unaff_s3;
        ppcVar16 = (char **)(**(code **)(local_90 + -0x7f18))
                                      (*(undefined4 *)puVar3,local_84,pcVar15,1);
      }
      if (ppcVar16 == (char **)0x0) {
        (**(code **)(local_90 + -0x7f68))(0);
      }
      else {
        ppcStack_d8 = (char **)(**(code **)(local_90 + -0x77e8))(ppcVar16);
        (**(code **)(local_90 + -0x7f68))(ppcVar16);
        ppcVar16 = ppcStack_d8;
        if (ppcStack_d8 != (char **)0x0) {
          if (local_7c == (char *)0x0) {
            (**(code **)(local_90 + -0x7fc8))(param_1,0x6a,0,**(undefined4 **)(local_90 + -0x5418));
LAB_00436fa4:
            if ((local_44 != 0) &&
               (pcVar10 = (char *)ppcStack_d8,
               iVar8 = (**(code **)(local_90 + -0x77e4))(param_1,ppcStack_d8,0), iVar8 == 0)) {
              (**(code **)(local_90 + -0x5360))(local_7c);
LAB_0043776c:
              puVar14 = (undefined4 *)0x1;
              (**(code **)(local_90 + -0x7fa0))(*(undefined4 *)puVar3);
              goto LAB_00436fd4;
            }
            pcVar10 = "";
            if (local_40 != 0) {
              (**(code **)(local_90 + -0x7fa8))(param_1,"Modulus=");
              (**(code **)(local_90 + -0x7ebc))(param_1,ppcStack_d8[4]);
              pcVar10 = "\n";
              (**(code **)(local_90 + -0x7fa8))(param_1);
            }
            if (local_50 != 0) {
              iVar8 = (**(code **)(local_90 + -0x77dc))(ppcStack_d8);
              if (iVar8 == 1) {
                pcVar10 = "RSA key ok\n";
                (**(code **)(local_90 + -0x7fa8))(param_1);
LAB_00437840:
                pcVar17 = *(code **)(local_90 + -0x7e8c);
LAB_00437844:
                iVar8 = (*pcVar17)();
                if (iVar8 == 0) goto LAB_00436fc8;
              }
              else {
                unaff_s3 = "";
                if (iVar8 == 0) {
                  unaff_s8 = (char **)&SUB_00000004;
                  unaff_s6 = (undefined *)0x7b;
                  unaff_s4 = &DAT_00000041;
                  unaff_s3 = "RSA key error: %s\n";
                  while (uVar5 = (**(code **)(local_90 + -0x7e8c))(), uVar5 != 0) {
                    if (((uVar5 >> 0x18 != 4) || ((uVar5 << 8) >> 0x14 != 0x7b)) ||
                       ((uVar5 & 0xfff) == 0x41)) goto LAB_00437840;
                    uVar4 = (**(code **)(local_90 + -0x77d8))(uVar5);
                    pcVar10 = unaff_s3;
                    (**(code **)(local_90 + -0x7fa8))(param_1,"RSA key error: %s\n",uVar4);
                    (**(code **)(local_90 + -0x77d4))();
                  }
                  pcVar17 = *(code **)(local_90 + -0x7e8c);
                  goto LAB_00437844;
                }
                pcVar17 = *(code **)(local_90 + -0x7e8c);
                if (iVar8 != -1) goto LAB_00437844;
              }
              puVar14 = (undefined4 *)0x1;
              (**(code **)(local_90 + -0x7fa0))(*(undefined4 *)puVar3);
              goto LAB_00436fd4;
            }
LAB_00436fc8:
            if (local_4c != (undefined4 *)0x0) {
LAB_00436fd0:
              pcVar10 = "";
              puVar14 = (undefined4 *)0x0;
              goto LAB_00436fd4;
            }
            unaff_s3 = *(char **)(local_90 + -0x7fa4);
            (**(code **)(local_90 + -0x7fa8))(*(undefined4 *)puVar3,"writing RSA key\n");
            if (unaff_s5 == (char *)0x1) {
              if (local_58 == 0) {
                pcVar17 = *(code **)(local_90 + -0x77cc);
                if (local_5c != 0) goto LAB_004379bc;
                ppcVar16 = (char **)(**(code **)(local_90 + -0x77c8))(param_1,ppcStack_d8);
              }
              else if (local_58 == 2) {
                ppcVar16 = (char **)(**(code **)(local_90 + -0x77d0))(param_1,ppcStack_d8);
              }
              else {
                pcVar17 = *(code **)(local_90 + -0x77cc);
LAB_004379bc:
                ppcVar16 = (char **)(*pcVar17)(param_1,ppcStack_d8);
              }
LAB_00437998:
              if ((int)ppcVar16 < 1) {
                pcVar10 = "unable to write key\n";
                (**(code **)(local_90 + -0x7fa8))(*(undefined4 *)puVar3);
                goto LAB_0043776c;
              }
              goto LAB_00436fd0;
            }
            if (unaff_s5 != &SUB_00000004) {
              if (unaff_s5 == (char *)0x3) {
                if (local_58 == 0) {
                  pcVar17 = *(code **)(local_90 + -0x77b0);
                  if (local_5c != 0) goto LAB_00437b68;
                  local_9c = (undefined4 *)0x0;
                  local_a0 = (undefined4 ****)0x0;
                  local_98 = (char *)local_34;
                  ppcVar16 = (char **)(**(code **)(local_90 + -0x77ac))
                                                (param_1,ppcStack_d8,local_3c,0);
                }
                else if (local_58 == 2) {
                  ppcVar16 = (char **)(**(code **)(local_90 + -0x77b4))(param_1,ppcStack_d8);
                }
                else {
                  pcVar17 = *(code **)(local_90 + -0x77b0);
LAB_00437b68:
                  ppcVar16 = (char **)(*pcVar17)(param_1,ppcStack_d8);
                }
                goto LAB_00437998;
              }
              if (unaff_s5 + -0xb < &SUB_00000002) {
                unaff_s3 = (char *)(**(code **)(local_90 + -0x77c0))();
                (**(code **)(local_90 + -0x77bc))(unaff_s3,ppcStack_d8);
                if (unaff_s5 == &SUB_0000000c) {
                  local_a0 = local_34;
                  local_84 = (char **)(**(code **)(local_90 + -0x77a8))(param_1,unaff_s3,local_48,0)
                  ;
                }
                else if ((local_5c == 0) && (local_58 == 0)) {
                  local_84 = (char **)(**(code **)(local_90 + -0x77a4))(param_1,unaff_s3);
                }
                else {
                  local_84 = (char **)(**(code **)(local_90 + -0x77b8))(param_1,unaff_s3);
                }
                (**(code **)(local_90 + -0x7f68))(unaff_s3);
                ppcVar16 = local_84;
                goto LAB_00437998;
              }
              puVar14 = (undefined4 *)0x1;
              pcVar10 = "bad output format specified for outfile\n";
              (**(code **)(local_90 + -0x7fa8))(*(undefined4 *)unaff_s3);
              goto LAB_00436fd4;
            }
            unaff_s4 = (char *)(**(code **)(local_90 + -0x77c4))(ppcStack_d8,0,0,local_54);
            ppcVar16 = (char **)(**(code **)(local_90 + -0x7dd8))(unaff_s4,"rsa.c",0x17c);
            local_30 = ppcVar16;
            if (ppcVar16 == (char **)0x0) {
              puVar14 = (undefined4 *)0x1;
              pcVar10 = "Memory allocation failure\n";
              (**(code **)(local_90 + -0x7fa8))(*(undefined4 *)unaff_s3);
              goto LAB_00436fd4;
            }
            (**(code **)(local_90 + -0x77c4))(ppcStack_d8,&local_30,0,local_54);
            pcVar10 = (char *)ppcVar16;
            (**(code **)(local_90 + -0x7fcc))(param_1,ppcVar16,unaff_s4);
            puVar14 = (undefined4 *)0x0;
            (**(code **)(local_90 + -0x7f58))(ppcVar16);
            puStack_d0 = local_4c;
            if (param_1 != 0) goto LAB_00436fdc;
LAB_00436fec:
            pcVar17 = *(code **)(local_90 + -0x77e0);
          }
          else {
            pcVar10 = &DAT_0000006c;
            iVar8 = (**(code **)(local_90 + -0x7fc8))(param_1,0x6c,5,local_7c);
            if (0 < iVar8) goto LAB_00436fa4;
            puVar14 = (undefined4 *)0x1;
            (**(code **)(local_90 + -0x5360))(local_7c);
LAB_00436fd4:
            pcVar17 = *(code **)(local_90 + -0x77e0);
            puStack_d0 = puVar14;
            if (param_1 != 0) {
LAB_00436fdc:
              (**(code **)(local_90 + -0x7f6c))(param_1);
              puStack_d0 = puVar14;
              goto LAB_00436fec;
            }
          }
          (*pcVar17)(ppcStack_d8);
          goto LAB_00437038;
        }
      }
      (**(code **)(local_90 + -0x7fa0))(*(undefined4 *)puVar3);
      ppcStack_d8 = ppcVar16;
      if (param_1 != 0) {
        (**(code **)(local_90 + -0x7f6c))(param_1);
      }
    }
  }
LAB_00437034:
  puStack_d0 = (undefined4 *)0x1;
LAB_00437038:
  if (local_38 != (undefined4 ****)0x0) {
    (**(code **)(local_90 + -0x7f58))();
  }
  if (local_34 != (undefined4 ****)0x0) {
    (**(code **)(local_90 + -0x7f58))();
  }
  if (local_2c == *local_80) {
    return puStack_d0;
  }
  pcStack_b4 = rsautl_main;
  iVar8 = local_2c;
  (**(code **)(local_90 + -0x5330))();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  puVar14 = (undefined4 *)PTR_bio_err_006a6e3c;
  iStack_e0 = 0;
  iStack_dc = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar9 = *(int *)PTR_bio_err_006a6e3c;
  iStack_d4 = param_1;
  puStack_cc = (undefined4 *)unaff_s3;
  pcStack_c8 = unaff_s4;
  pcStack_c4 = unaff_s5;
  puStack_c0 = unaff_s6;
  ppcStack_bc = unaff_s7;
  ppcStack_b8 = unaff_s8;
  if (iVar9 == 0) {
    iVar9 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *puVar14 = iVar9;
  }
  iVar9 = (*(code *)PTR_load_config_006a6e64)(iVar9,0);
  if (iVar9 == 0) {
    iVar8 = 0;
    puVar13 = (undefined *)0x0;
    goto LAB_00437e50;
  }
  unaff_s7 = (char **)(iVar8 + -1);
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  (*(code *)PTR_OPENSSL_add_all_algorithms_noconf_006a73fc)();
  if ((int)unaff_s7 < 1) {
    pcStack_11c = (char *)0x0;
    pcVar10 = (char *)0x0;
    iStack_e8 = 0;
    unaff_s5 = (char *)0x0;
    iStack_ec = 0;
    uStack_f4 = 1;
    pcStack_114 = (char *)0x0;
    iStack_f0 = 0;
    iStack_f8 = 2;
    pcStack_108 = (char *)0x0;
    uStack_100 = 3;
    iStack_10c = 1;
    goto LAB_004381c8;
  }
  pcStack_114 = (char *)0x0;
  iStack_ec = 0;
  iStack_e8 = 0;
  uStack_f4 = 1;
  unaff_s8 = (char **)((int)pcVar10 + 4);
  iStack_f0 = 0;
  iStack_104 = 0;
  unaff_s5 = (char *)0x0;
  uStack_100 = 3;
  pcStack_11c = (char *)0x0;
  pcVar10 = (char *)0x0;
  pcStack_108 = (char *)0x0;
  puVar13 = &DAT_00632514;
  iStack_10c = 1;
  unaff_s4 = "-inkey";
  iStack_f8 = 2;
  iStack_118 = 0x630000;
  pcStack_110 = "-keyform";
  iStack_fc = 0x630000;
  while (((pcVar15 = *unaff_s8, *pcVar15 != '-' || (pcVar15[1] != 'i')) ||
         ((pcVar15[2] != 'n' || (pcVar15[3] != '\0'))))) {
    iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,puVar13);
    if (iVar8 != 0) {
      iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,unaff_s4);
      if (iVar8 == 0) {
        unaff_s7 = (char **)((int)unaff_s7 + -1);
        if (unaff_s7 != (char **)0x0) {
          pcStack_11c = unaff_s8[1];
          ppcVar16 = unaff_s8 + 1;
          goto LAB_00437dbc;
        }
      }
      else {
        iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,iStack_118 + 0x2720);
        if (iVar8 == 0) {
          unaff_s7 = (char **)((int)unaff_s7 + -1);
          if (unaff_s7 != (char **)0x0) {
            pcStack_114 = unaff_s8[1];
            ppcVar16 = unaff_s8 + 1;
            goto LAB_00437dbc;
          }
        }
        else {
          iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,pcStack_110);
          if (iVar8 == 0) {
            unaff_s7 = (char **)((int)unaff_s7 + -1);
            if (unaff_s7 != (char **)0x0) {
              ppcVar16 = unaff_s8 + 1;
              uStack_100 = (*(code *)PTR_str2fmt_006a6e4c)(unaff_s8[1]);
              goto LAB_00437dbc;
            }
          }
          else {
            iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,iStack_fc + 0x1eb4);
            if (iVar8 == 0) {
              unaff_s7 = (char **)((int)unaff_s7 + -1);
              if (unaff_s7 != (char **)0x0) {
                pcStack_108 = unaff_s8[1];
                ppcVar16 = unaff_s8 + 1;
                goto LAB_00437dbc;
              }
            }
            else {
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-pubin");
              ppcVar16 = unaff_s8;
              if (iVar8 == 0) {
                iStack_10c = 2;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-certin");
              if (iVar8 == 0) {
                iStack_10c = 3;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-asn1parse");
              if (iVar8 == 0) {
                iStack_ec = 1;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-hexdump");
              if (iVar8 == 0) {
                iStack_e8 = 1;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,&DAT_00637b14);
              if (iVar8 == 0) {
                uStack_f4 = 3;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-oaep");
              if (iVar8 == 0) {
                uStack_f4 = 4;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,&DAT_00637b24);
              if (iVar8 == 0) {
                uStack_f4 = 2;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-pkcs");
              if (iVar8 == 0) {
                uStack_f4 = 1;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-x931");
              if (iVar8 == 0) goto LAB_004389c0;
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-sign");
              if (iVar8 == 0) {
                iStack_104 = 1;
                iStack_f8 = 1;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-verify");
              if (iVar8 == 0) {
                iStack_f8 = 2;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,&DAT_00637b3c);
              if (iVar8 == 0) {
                iStack_f0 = 1;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-encrypt");
              if (iVar8 == 0) {
                iStack_f8 = 3;
                goto LAB_00437dbc;
              }
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-decrypt");
              if (iVar8 == 0) {
                iStack_104 = 1;
                iStack_f8 = 4;
                goto LAB_00437dbc;
              }
            }
          }
        }
      }
LAB_00437f9c:
      iVar8 = 0;
      puVar13 = (undefined *)0x0;
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"Usage: rsautl [options]\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"-in file        input file\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"-out file       output file\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"-inkey file     input key\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*puVar14,"-keyform arg    private key format - default PEM\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"-pubin          input is an RSA public\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*puVar14,"-certin         input is a certificate carrying an RSA public key\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"-ssl            use SSL v2 padding\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"-raw            use no padding\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*puVar14,"-pkcs           use PKCS#1 v1.5 padding (default)\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"-oaep           use PKCS#1 OAEP\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"-sign           sign with private key\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"-verify         verify with public key\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"-encrypt        encrypt with public key\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"-decrypt        decrypt with private key\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"-hexdump        hex dump output\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*puVar14,"-engine e       use engine e, possibly a hardware device.\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"-passin arg    pass phrase source\n");
      goto LAB_00437e50;
    }
    bVar1 = unaff_s7 == (char **)0x1;
    unaff_s7 = (char **)((int)unaff_s7 + -2);
    if (bVar1) goto LAB_00437f9c;
    unaff_s5 = unaff_s8[1];
    unaff_s8 = unaff_s8 + 2;
    for (; (int)unaff_s7 < 1; unaff_s7 = (char **)((int)unaff_s7 + -1)) {
      if (iStack_104 == 0) {
LAB_004381c8:
        unaff_s4 = PTR_bio_err_006a6e3c;
        puVar13 = (undefined *)(*(code *)PTR_setup_engine_006a6ec4)(*puVar14,pcStack_108,0);
        iVar8 = (*(code *)PTR_app_passwd_006a6e54)(*puVar14,pcStack_114,0,&iStack_e0,0);
        if (iVar8 == 0) goto LAB_00438290;
        (*(code *)PTR_app_RAND_load_file_006a6ecc)(0,*(undefined4 *)unaff_s4,0);
        if (iStack_10c == 2) {
          puVar6 = (undefined *)
                   (*(code *)PTR_load_pubkey_006a74e8)
                             (*(undefined4 *)unaff_s4,pcStack_11c,uStack_100,0,0,puVar13,
                              "Public Key");
LAB_00438494:
          puVar13 = puVar6;
          if (puVar6 != (undefined *)0x0) {
            iVar8 = (*(code *)PTR_EVP_PKEY_get1_RSA_006a75f8)(puVar6);
            (*(code *)PTR_EVP_PKEY_free_006a6e78)(puVar6);
            if (iVar8 == 0) {
              puVar13 = (undefined *)0x0;
              (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"Error getting RSA key\n");
              (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar14);
              goto LAB_00437e50;
            }
            if ((char **)pcVar10 != (char **)0x0) {
              puVar13 = (undefined *)(*(code *)PTR_BIO_new_file_006a6eac)(pcVar10,&DAT_00633e40);
              if (puVar13 != (undefined *)0x0) goto LAB_004384e4;
              uVar4 = *puVar14;
              pcVar15 = "Error Reading Input File\n";
LAB_004386a4:
              (*(code *)PTR_BIO_printf_006a6e38)(uVar4,pcVar15);
              (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar14);
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
                uVar4 = *puVar14;
                pcVar15 = "Error Reading Output File\n";
                goto LAB_004386a4;
              }
            }
            iVar9 = (*(code *)PTR_RSA_size_006a7640)(iVar8);
            unaff_s7 = (char **)(iVar9 << 1);
            unaff_s5 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(unaff_s7,"rsautl.c",0x10d);
            pcVar10 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar9,"rsautl.c",0x10e);
            if (unaff_s5 == (char *)0x0) {
              (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"Out of memory\n");
              puVar12 = (undefined4 *)0x1;
              (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar14);
              (*(code *)PTR_RSA_free_006a7600)(iVar8);
              (*(code *)PTR_BIO_free_006a6e70)(puVar13);
              (*(code *)PTR_BIO_free_all_006a6e74)(unaff_s4);
            }
            else {
              if ((char **)pcVar10 == (char **)0x0) {
                (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"Out of memory\n");
                puVar12 = (undefined4 *)0x1;
                (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar14);
                (*(code *)PTR_RSA_free_006a7600)(iVar8);
                (*(code *)PTR_BIO_free_006a6e70)(puVar13);
                (*(code *)PTR_BIO_free_all_006a6e74)(unaff_s4);
              }
              else {
                iVar9 = (*(code *)PTR_BIO_read_006a74c0)(puVar13,unaff_s5,unaff_s7);
                if (iVar9 < 1) {
                  (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"Error reading input Data\n");
                  puVar14 = (undefined4 *)(*(code *)PTR_exit_006a9a40)(1);
                  return puVar14;
                }
                if ((iStack_f0 != 0) && (iVar9 >> 1 != 0)) {
                  pcVar15 = unaff_s5;
                  pcVar11 = unaff_s5 + iVar9 + -1;
                  do {
                    pcVar7 = pcVar15 + 1;
                    cVar2 = *pcVar15;
                    *pcVar15 = *pcVar11;
                    *pcVar11 = cVar2;
                    pcVar15 = pcVar7;
                    pcVar11 = pcVar11 + -1;
                  } while (unaff_s5 + (iVar9 >> 1) != pcVar7);
                }
                pcVar17 = (code *)PTR_RSA_public_decrypt_006a7650;
                if (iStack_f8 == 2) {
LAB_004385ec:
                  iVar9 = (*pcVar17)(iVar9,unaff_s5,pcVar10,iVar8,uStack_f4);
                  if (iVar9 < 1) goto LAB_00438898;
                  if (iStack_ec == 0) {
                    pcVar17 = (code *)PTR_BIO_write_006a6e14;
                    if (iStack_e8 != 0) {
                      pcVar17 = (code *)PTR_BIO_dump_006a7648;
                    }
                    (*pcVar17)(unaff_s4,pcVar10,iVar9);
                    puVar12 = (undefined4 *)0x0;
                  }
                  else {
                    iVar9 = (*(code *)PTR_ASN1_parse_dump_006a74b8)
                                      (unaff_s4,pcVar10,iVar9,1,0xffffffff);
                    if (iVar9 == 0) {
                      puVar12 = (undefined4 *)0x0;
                      (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar14);
                    }
                    else {
                      puVar12 = (undefined4 *)0x0;
                    }
                  }
                }
                else {
                  if (iStack_f8 < 3) {
                    pcVar17 = (code *)PTR_RSA_private_encrypt_006a764c;
                    if (iStack_f8 == 1) goto LAB_004385ec;
                  }
                  else {
                    pcVar17 = (code *)PTR_RSA_public_encrypt_006a7654;
                    if ((iStack_f8 == 3) ||
                       (pcVar17 = (code *)PTR_RSA_private_decrypt_006a7644, iStack_f8 == 4))
                    goto LAB_004385ec;
                  }
LAB_00438898:
                  (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"RSA operation error\n");
                  puVar12 = (undefined4 *)0x1;
                  (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar14);
                }
                (*(code *)PTR_RSA_free_006a7600)(iVar8);
                (*(code *)PTR_BIO_free_006a6e70)(puVar13);
                (*(code *)PTR_BIO_free_all_006a6e74)(unaff_s4);
              }
              (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s5);
            }
            if ((char **)pcVar10 != (char **)0x0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar10);
            }
            goto LAB_00437e84;
          }
        }
        else if (iStack_10c == 3) {
          puVar13 = (undefined *)
                    (*(code *)PTR_load_cert_006a7078)
                              (*(undefined4 *)unaff_s4,pcStack_11c,uStack_100,0,puVar13,
                               "Certificate");
          if (puVar13 != (undefined *)0x0) {
            puVar6 = (undefined *)(*(code *)PTR_X509_get_pubkey_006a6f08)(puVar13);
            (*(code *)PTR_X509_free_006a6e90)(puVar13);
            goto LAB_00438494;
          }
        }
        else if (iStack_10c == 1) goto LAB_004386f0;
        puVar12 = (undefined4 *)0x1;
      }
      else {
        if (iStack_10c == 1) {
          puVar13 = (undefined *)(*(code *)PTR_setup_engine_006a6ec4)(*puVar14,pcStack_108,0);
          iVar8 = (*(code *)PTR_app_passwd_006a6e54)(*puVar14,pcStack_114,0,&iStack_e0,0);
          if (iVar8 != 0) {
            (*(code *)PTR_app_RAND_load_file_006a6ecc)(0,*(undefined4 *)PTR_bio_err_006a6e3c,0);
LAB_004386f0:
            puVar6 = (undefined *)
                     (*(code *)PTR_load_key_006a6ec8)
                               (*puVar14,pcStack_11c,uStack_100,0,iStack_e0,puVar13,"Private Key");
            goto LAB_00438494;
          }
LAB_00438290:
          iVar8 = 0;
          puVar13 = (undefined *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)(*puVar14,"Error getting password\n");
        }
        else {
          iVar8 = 0;
          puVar13 = (undefined *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*puVar14,"A private key is needed for this operation\n");
        }
LAB_00437e50:
        puVar12 = (undefined4 *)0x1;
        (*(code *)PTR_RSA_free_006a7600)(iVar8);
        (*(code *)PTR_BIO_free_006a6e70)(puVar13);
        (*(code *)PTR_BIO_free_all_006a6e74)(0);
LAB_00437e84:
        puVar14 = puVar12;
        if (iStack_e0 != 0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
        }
      }
      if (iStack_dc == *(int *)puVar3) {
        return puVar12;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004389c0:
      uStack_f4 = 5;
      ppcVar16 = unaff_s8;
LAB_00437dbc:
      unaff_s8 = ppcVar16 + 1;
    }
  }
  unaff_s7 = (char **)((int)unaff_s7 + -1);
  if (unaff_s7 != (char **)0x0) {
    pcVar10 = unaff_s8[1];
    ppcVar16 = unaff_s8 + 1;
    goto LAB_00437dbc;
  }
  goto LAB_00437f9c;
}

