
char ** dump_certs_pkeys_bag
                  (int param_1,char **param_2,char **param_3,char **param_4,char **param_5,
                  int param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  char **ppcVar8;
  undefined4 uVar9;
  char *pcVar10;
  char *pcVar11;
  char **ppcVar12;
  char **unaff_s2;
  char **unaff_s3;
  char *pcVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  char **ppcVar16;
  undefined4 *unaff_s8;
  int iStack_2c4;
  char **ppcStack_2c0;
  char *pcStack_2bc;
  undefined4 uStack_2b8;
  char **ppcStack_2b4;
  char *pcStack_2b0;
  char **ppcStack_2ac;
  char *pcStack_2a8;
  char *pcStack_2a4;
  int iStack_2a0;
  int iStack_29c;
  char *pcStack_298;
  char *pcStack_294;
  char *pcStack_290;
  char *pcStack_28c;
  int iStack_288;
  int iStack_284;
  char *pcStack_280;
  char *pcStack_27c;
  char *pcStack_278;
  undefined4 uStack_274;
  char *pcStack_270;
  char *pcStack_26c;
  char *pcStack_268;
  int iStack_264;
  char *pcStack_260;
  char *pcStack_25c;
  undefined4 uStack_254;
  undefined4 uStack_250;
  char **ppcStack_24c;
  char **ppcStack_248;
  undefined auStack_244 [136];
  char *apcStack_1bc [13];
  char *apcStack_188 [13];
  int iStack_154;
  char **ppcStack_150;
  char **ppcStack_14c;
  char **ppcStack_148;
  char *pcStack_144;
  int iStack_140;
  char **ppcStack_13c;
  char **ppcStack_138;
  int iStack_134;
  char **ppcStack_130;
  code *pcStack_12c;
  char **ppcStack_118;
  int iStack_114;
  int iStack_110;
  undefined *puStack_108;
  int iStack_fc;
  uint uStack_f8;
  int iStack_f4;
  uint uStack_f0;
  char *pcStack_ec;
  uint uStack_e8;
  char *pcStack_e4;
  char *pcStack_e0;
  undefined4 *puStack_dc;
  undefined4 *puStack_d8;
  uint uStack_d4;
  char *pcStack_d0;
  char *pcStack_cc;
  int *piStack_c8;
  uint uStack_c4;
  undefined4 uStack_c0;
  int iStack_bc;
  char **ppcStack_b8;
  char **ppcStack_b4;
  char **ppcStack_b0;
  char **ppcStack_ac;
  int iStack_a8;
  int iStack_a4;
  char **ppcStack_a0;
  char **ppcStack_9c;
  undefined4 *puStack_98;
  code *pcStack_94;
  char **local_80;
  int local_7c;
  int local_78;
  undefined *local_70;
  char **local_68;
  uint local_64;
  uint local_60;
  char *local_5c;
  uint local_58;
  char *local_54;
  char *local_50;
  char *local_4c;
  uint local_48;
  char *local_44;
  char *local_40;
  uint local_3c;
  char **local_38;
  undefined4 *local_34;
  char *local_30;
  char *local_2c;
  
  local_68 = (char **)PTR___stack_chk_guard_006a9ae8;
  local_70 = &_gp;
  local_2c = *(char **)PTR___stack_chk_guard_006a9ae8;
  pcVar10 = (char *)param_2;
  pcVar11 = (char *)param_3;
  ppcStack_138 = param_4;
  iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*param_2);
  if (iVar3 == 0x97) {
    unaff_s3 = *(char ***)(local_70 + -0x7fa4);
    if (((uint)param_5 & 4) != 0) {
      (**(code **)(local_70 + -0x7fa8))(*unaff_s3,"Shrouded Keybag: ");
      pcVar10 = (char *)&local_30;
      unaff_s8 = *(undefined4 **)param_2[1];
      local_30 = (char *)(*(undefined4 **)(unaff_s8[1] + 4))[2];
      unaff_s2 = (char **)(**(code **)(local_70 + -0x7bdc))
                                    (0,pcVar10,**(undefined4 **)(unaff_s8[1] + 4));
      if (unaff_s2 != (char **)0x0) {
        uVar7 = *unaff_s8;
        unaff_s8 = (undefined4 *)*unaff_s3;
        uVar7 = (**(code **)(local_70 + -0x7cb4))(uVar7);
        unaff_s3 = (char **)(**(code **)(local_70 + -0x7cc4))(uVar7);
        ppcStack_138 = (char **)(**(code **)(local_70 + -0x7bd8))(unaff_s2[1]);
        pcVar10 = "%s, Iteration %ld\n";
        (**(code **)(local_70 + -0x7fa8))(unaff_s8,"%s, Iteration %ld\n",unaff_s3);
        (**(code **)(local_70 + -0x7bd4))(unaff_s2);
      }
    }
    ppcStack_14c = (char **)((uint)param_5 & 1);
    pcVar11 = "-check_ss_sig";
    if (ppcStack_14c == (char **)0x0) {
      print_attribs(param_1,param_2[2],"Bag Attributes");
      pcVar10 = (char *)param_3;
      pcVar11 = (char *)param_4;
      param_2 = (char **)(**(code **)(local_70 + -0x7bb8))(param_2);
      if (param_2 != (char **)0x0) {
        unaff_s2 = (char **)(**(code **)(local_70 + -0x7bc0))(param_2);
        if (unaff_s2 == (char **)0x0) {
          (**(code **)(local_70 + -0x7bb4))(param_2);
        }
        else {
          ppcStack_14c = (char **)0x1;
          print_attribs(param_1,param_2[4],"Key Attributes");
          (**(code **)(local_70 + -0x7bb4))(param_2);
          ppcStack_138 = (char **)0x0;
          local_78 = param_6;
          local_7c = 0;
          local_80 = (char **)0x0;
          pcVar11 = **(char ***)(local_70 + -0x7bbc);
          pcVar10 = (char *)unaff_s2;
          (**(code **)(local_70 + -0x7e90))(param_1);
          (**(code **)(local_70 + -0x7f68))(unaff_s2);
        }
        goto LAB_00463488;
      }
      goto LAB_0046381c;
    }
  }
  else {
    if (iVar3 < 0x98) {
      if (iVar3 != 0x96) {
LAB_004638d4:
        puVar15 = *(undefined4 **)(local_70 + -0x7fa4);
        (**(code **)(local_70 + -0x7fa8))(*puVar15,"Warning unsupported bag type: ");
        (**(code **)(local_70 + -0x7db4))(*puVar15,*param_2);
        pcVar10 = "\n";
        ppcStack_14c = (char **)0x1;
        (**(code **)(local_70 + -0x7fa8))(*puVar15);
        goto LAB_00463488;
      }
      if (((uint)param_5 & 4) != 0) {
        pcVar10 = "Key bag\n";
        (**(code **)(local_70 + -0x7fa8))(**(undefined4 **)(local_70 + -0x7fa4));
      }
      ppcStack_14c = (char **)0x1;
      if (((uint)param_5 & 1) != 0) goto LAB_00463488;
      pcVar10 = param_2[2];
      pcVar11 = "Bag Attributes";
      print_attribs(param_1);
      pcVar13 = param_2[1];
      param_2 = (char **)(**(code **)(local_70 + -0x7bc0))(pcVar13);
      if (param_2 != (char **)0x0) {
        ppcStack_14c = (char **)0x1;
        print_attribs(param_1,*(undefined4 *)(pcVar13 + 0x10),"Key Attributes");
        ppcStack_138 = (char **)0x0;
        local_78 = param_6;
        local_7c = 0;
        local_80 = (char **)0x0;
        pcVar11 = **(char ***)(local_70 + -0x7bbc);
        pcVar10 = (char *)param_2;
        (**(code **)(local_70 + -0x7e90))(param_1);
        (**(code **)(local_70 + -0x7f68))(param_2);
        goto LAB_00463488;
      }
LAB_0046381c:
      ppcStack_14c = (char **)0x0;
      goto LAB_00463488;
    }
    if (iVar3 == 0x98) {
      if (((uint)param_5 & 4) != 0) {
        pcVar10 = "Certificate bag\n";
        (**(code **)(local_70 + -0x7fa8))(**(undefined4 **)(local_70 + -0x7fa4));
      }
      if (((uint)param_5 & 2) == 0) {
        pcVar10 = (char *)0x9d;
        iVar3 = (**(code **)(local_70 + -0x7bcc))(param_2[2]);
        if (iVar3 == 0) {
          pcVar11 = "-check_ss_sig";
          if (((uint)param_5 & 8) != 0) {
            ppcStack_14c = (char **)0x1;
            goto LAB_00463488;
          }
        }
        else {
          ppcStack_14c = (char **)0x1;
          if (((uint)param_5 & 0x10) != 0) goto LAB_00463488;
        }
        pcVar10 = param_2[2];
        pcVar11 = "Bag Attributes";
        print_attribs(param_1);
        iVar3 = (**(code **)(local_70 + -0x7cb4))(*(undefined4 *)param_2[1]);
        if (iVar3 == 0x9e) {
          param_2 = (char **)(**(code **)(local_70 + -0x7bc8))(param_2);
          if (param_2 == (char **)0x0) goto LAB_0046381c;
          dump_cert_text(param_1,param_2);
          pcVar10 = (char *)param_2;
          (**(code **)(local_70 + -0x7ec0))(param_1);
          (**(code **)(local_70 + -0x7f50))(param_2);
        }
      }
    }
    else {
      uVar4 = (uint)param_5 & 4;
      if (iVar3 != 0x9b) goto LAB_004638d4;
      local_64 = uVar4;
      if (uVar4 != 0) {
        (**(code **)(local_70 + -0x7fa8))
                  (**(undefined4 **)(local_70 + -0x7fa4),"Safe Contents bag\n");
      }
      pcVar10 = param_2[2];
      pcVar11 = "Bag Attributes";
      local_5c = "-check_ss_sig";
      local_60 = (uint)param_5 & 1;
      unaff_s3 = (char **)0x0;
      print_attribs(param_1);
      local_58 = (uint)param_5 & 2;
      local_48 = (uint)param_5 & 0x10;
      unaff_s8 = (undefined4 *)param_2[1];
      local_3c = (uint)param_5 & 8;
      local_4c = "Key Attributes";
      local_44 = "Shrouded Keybag: ";
      local_40 = "-check_ss_sig";
      local_54 = "Warning unsupported bag type: ";
      local_50 = "-check_ss_sig";
      iVar3 = (**(code **)(local_70 + -0x7fb4))(unaff_s8);
      if (0 < iVar3) {
        do {
          pcVar10 = (char *)unaff_s3;
          unaff_s2 = (char **)(**(code **)(local_70 + -0x7fbc))(unaff_s8);
          iVar3 = (**(code **)(local_70 + -0x7cb4))(*unaff_s2);
          if (iVar3 == 0x97) {
            if (local_64 != 0) {
              local_34 = *(undefined4 **)(local_70 + -0x7fa4);
              (**(code **)(local_70 + -0x7fa8))(**(undefined4 **)(local_70 + -0x7fa4),local_44);
              pcVar10 = (char *)&local_30;
              ppcStack_138 = *(char ***)unaff_s2[1];
              local_30 = (*(char ***)(ppcStack_138[1] + 4))[2];
              pcVar11 = **(char ***)(ppcStack_138[1] + 4);
              local_38 = ppcStack_138;
              param_2 = (char **)(**(code **)(local_70 + -0x7bdc))(0);
              if (param_2 != (char **)0x0) {
                local_34 = (undefined4 *)*local_34;
                uVar7 = (**(code **)(local_70 + -0x7cb4))(*local_38);
                local_38 = (char **)(**(code **)(local_70 + -0x7cc4))(uVar7);
                ppcStack_138 = (char **)(**(code **)(local_70 + -0x7bd8))(param_2[1]);
                pcVar10 = local_40 + 0x1550;
                pcVar11 = (char *)local_38;
                (**(code **)(local_70 + -0x7fa8))(local_34);
                (**(code **)(local_70 + -0x7bd4))(param_2);
              }
            }
            if (local_60 == 0) {
              print_attribs(param_1,unaff_s2[2],local_5c + 0x15d0);
              pcVar10 = (char *)param_3;
              pcVar11 = (char *)param_4;
              param_2 = (char **)(**(code **)(local_70 + -0x7bb8))(unaff_s2);
              if (param_2 == (char **)0x0) goto LAB_0046381c;
              unaff_s2 = (char **)(**(code **)(local_70 + -0x7bc0))(param_2);
              if (unaff_s2 == (char **)0x0) {
                (**(code **)(local_70 + -0x7bb4))(param_2);
                goto LAB_0046381c;
              }
              print_attribs(param_1,param_2[4],local_4c);
              (**(code **)(local_70 + -0x7bb4))(param_2);
              ppcStack_138 = (char **)0x0;
              local_78 = param_6;
              local_7c = 0;
              local_80 = (char **)0x0;
              pcVar11 = **(char ***)(local_70 + -0x7bbc);
              pcVar10 = (char *)unaff_s2;
              (**(code **)(local_70 + -0x7e90))(param_1);
              (**(code **)(local_70 + -0x7f68))(unaff_s2);
            }
          }
          else if (iVar3 < 0x98) {
            if (iVar3 == 0x96) {
              if (local_64 != 0) {
                pcVar10 = "Key bag\n";
                (**(code **)(local_70 + -0x7fa8))(**(undefined4 **)(local_70 + -0x7fa4));
              }
              if (local_60 == 0) {
                pcVar10 = unaff_s2[2];
                pcVar11 = local_5c + 0x15d0;
                print_attribs(param_1);
                unaff_s2 = (char **)unaff_s2[1];
                param_2 = (char **)(**(code **)(local_70 + -0x7bc0))(unaff_s2);
                if (param_2 == (char **)0x0) goto LAB_0046381c;
                print_attribs(param_1,unaff_s2[4],local_4c);
                ppcStack_138 = (char **)0x0;
                local_78 = param_6;
                local_7c = 0;
                local_80 = (char **)0x0;
                pcVar11 = **(char ***)(local_70 + -0x7bbc);
                pcVar10 = (char *)param_2;
                (**(code **)(local_70 + -0x7e90))(param_1);
                (**(code **)(local_70 + -0x7f68))(param_2);
              }
            }
            else {
LAB_004636f4:
              param_2 = *(char ***)(local_70 + -0x7fa4);
              (**(code **)(local_70 + -0x7fa8))(*param_2,local_54);
              (**(code **)(local_70 + -0x7db4))(*param_2,*unaff_s2);
              pcVar10 = local_50 + -0x4d1c;
              (**(code **)(local_70 + -0x7fa8))(*param_2);
            }
          }
          else if (iVar3 == 0x98) {
            if (local_64 != 0) {
              pcVar10 = "Certificate bag\n";
              (**(code **)(local_70 + -0x7fa8))(**(undefined4 **)(local_70 + -0x7fa4));
            }
            if (local_58 == 0) {
              pcVar10 = (char *)0x9d;
              iVar3 = (**(code **)(local_70 + -0x7bcc))(unaff_s2[2]);
              uVar4 = local_3c;
              if (iVar3 != 0) {
                uVar4 = local_48;
              }
              if (uVar4 == 0) {
                pcVar10 = unaff_s2[2];
                pcVar11 = local_5c + 0x15d0;
                print_attribs(param_1);
                iVar3 = (**(code **)(local_70 + -0x7cb4))(*(undefined4 *)unaff_s2[1]);
                if (iVar3 == 0x9e) {
                  param_2 = (char **)(**(code **)(local_70 + -0x7bc8))(unaff_s2);
                  if (param_2 == (char **)0x0) goto LAB_0046381c;
                  dump_cert_text(param_1,param_2);
                  pcVar10 = (char *)param_2;
                  (**(code **)(local_70 + -0x7ec0))(param_1);
                  (**(code **)(local_70 + -0x7f50))(param_2);
                }
              }
            }
          }
          else {
            if (iVar3 != 0x9b) goto LAB_004636f4;
            if (local_64 != 0) {
              (**(code **)(local_70 + -0x7fa8))
                        (**(undefined4 **)(local_70 + -0x7fa4),"Safe Contents bag\n");
            }
            pcVar10 = unaff_s2[2];
            pcVar11 = local_5c + 0x15d0;
            print_attribs(param_1);
            unaff_s2 = (char **)unaff_s2[1];
            for (param_2 = (char **)0x0; iVar3 = (**(code **)(local_70 + -0x7fb4))(unaff_s2),
                (int)param_2 < iVar3; param_2 = (char **)((int)param_2 + 1)) {
              pcVar10 = (char *)(**(code **)(local_70 + -0x7fbc))(unaff_s2,param_2);
              local_7c = param_6;
              local_80 = param_5;
              pcVar11 = (char *)param_3;
              ppcStack_138 = param_4;
              iVar3 = dump_certs_pkeys_bag(param_1);
              if (iVar3 == 0) goto LAB_0046381c;
            }
          }
          unaff_s3 = (char **)((int)unaff_s3 + 1);
          iVar3 = (**(code **)(local_70 + -0x7fb4))(unaff_s8);
        } while ((int)unaff_s3 < iVar3);
      }
    }
  }
  ppcStack_14c = (char **)0x1;
LAB_00463488:
  if (local_2c == *local_68) {
    return ppcStack_14c;
  }
  pcStack_94 = dump_certs_keys_p12;
  pcVar13 = local_2c;
  (**(code **)(local_70 + -0x5330))();
  iVar3 = local_7c;
  ppcVar8 = local_80;
  piStack_c8 = (int *)PTR___stack_chk_guard_006a9ae8;
  iStack_a4 = param_6;
  puStack_108 = &_gp;
  iStack_bc = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppcStack_b8 = param_2;
  ppcStack_b4 = ppcStack_14c;
  ppcStack_b0 = unaff_s2;
  ppcStack_ac = unaff_s3;
  iStack_a8 = param_1;
  ppcStack_a0 = param_3;
  ppcStack_9c = param_4;
  puStack_98 = unaff_s8;
  iStack_f4 = (*(code *)PTR_PKCS12_unpack_authsafes_006a7230)(pcVar10);
  if (iStack_f4 == 0) {
    ppcVar12 = (char **)0x0;
  }
  else {
    uStack_f8 = (uint)ppcVar8 & 4;
    iStack_fc = 0;
    uStack_f0 = (uint)ppcVar8 & 1;
    uStack_e8 = (uint)ppcVar8 & 2;
    uStack_d4 = (uint)ppcVar8 & 0x10;
    uStack_c4 = (uint)ppcVar8 & 8;
    pcStack_ec = "Bag Attributes";
    pcStack_e0 = "Key Attributes";
    pcStack_cc = "-check_ss_sig";
    pcStack_d0 = "%s, Iteration %ld\n";
    pcStack_e4 = "-check_ss_sig";
    while (iVar5 = (**(code **)(puStack_108 + -0x7fb4))(iStack_f4), iStack_fc < iVar5) {
      iVar5 = (**(code **)(puStack_108 + -0x7fbc))(iStack_f4,iStack_fc);
      iVar6 = (**(code **)(puStack_108 + -0x7cb4))(*(undefined4 *)(iVar5 + 0x10));
      if (iVar6 == 0x15) {
        param_1 = (**(code **)(puStack_108 + -0x7ba0))(iVar5);
        if (uStack_f8 == 0) goto LAB_00463dc0;
        (**(code **)(puStack_108 + -0x7fa8))
                  (**(undefined4 **)(puStack_108 + -0x7fa4),"PKCS7 Data\n");
        if (param_1 == 0) goto LAB_00464330;
LAB_00463dc8:
        unaff_s2 = (char **)0x0;
        iVar5 = (**(code **)(puStack_108 + -0x7fb4))(param_1);
        if (0 < iVar5) {
          do {
            ppcStack_14c = (char **)(**(code **)(puStack_108 + -0x7fbc))(param_1,unaff_s2);
            iVar5 = (**(code **)(puStack_108 + -0x7cb4))(*ppcStack_14c);
            if (iVar5 == 0x97) {
              if (uStack_f8 != 0) {
                puStack_d8 = *(undefined4 **)(puStack_108 + -0x7fa4);
                (**(code **)(puStack_108 + -0x7fa8))
                          (**(undefined4 **)(puStack_108 + -0x7fa4),pcStack_cc + 0x15f0);
                puStack_dc = *(undefined4 **)ppcStack_14c[1];
                uStack_c0 = (*(undefined4 **)(puStack_dc[1] + 4))[2];
                iVar5 = (**(code **)(puStack_108 + -0x7bdc))
                                  (0,&uStack_c0,**(undefined4 **)(puStack_dc[1] + 4));
                if (iVar5 != 0) {
                  puStack_d8 = (undefined4 *)*puStack_d8;
                  uVar7 = (**(code **)(puStack_108 + -0x7cb4))(*puStack_dc);
                  puStack_dc = (undefined4 *)(**(code **)(puStack_108 + -0x7cc4))(uVar7);
                  uVar7 = (**(code **)(puStack_108 + -0x7bd8))(*(undefined4 *)(iVar5 + 4));
                  (**(code **)(puStack_108 + -0x7fa8))(puStack_d8,pcStack_d0,puStack_dc,uVar7);
                  (**(code **)(puStack_108 + -0x7bd4))(iVar5);
                }
              }
              if (uStack_f0 == 0) {
                print_attribs(pcVar13,ppcStack_14c[2],pcStack_ec);
                iVar5 = (**(code **)(puStack_108 + -0x7bb8))(ppcStack_14c,pcVar11,ppcStack_138);
                if (iVar5 != 0) {
                  ppcStack_14c = (char **)(**(code **)(puStack_108 + -0x7bc0))(iVar5);
                  if (ppcStack_14c != (char **)0x0) {
                    print_attribs(pcVar13,*(undefined4 *)(iVar5 + 0x10),pcStack_e0);
                    (**(code **)(puStack_108 + -0x7bb4))(iVar5);
                    iStack_110 = iVar3;
                    iStack_114 = 0;
                    ppcStack_118 = (char **)0x0;
                    (**(code **)(puStack_108 + -0x7e90))
                              (pcVar13,ppcStack_14c,**(undefined4 **)(puStack_108 + -0x7bbc),0);
                    (**(code **)(puStack_108 + -0x7f68))(ppcStack_14c);
                    goto LAB_00463ec0;
                  }
                  (**(code **)(puStack_108 + -0x7bb4))(iVar5);
                }
LAB_0046417c:
                ppcVar12 = (char **)0x0;
                (**(code **)(puStack_108 + -0x7d88))(param_1,*(undefined4 *)(puStack_108 + -0x7ba8))
                ;
                goto LAB_00464194;
              }
            }
            else if (iVar5 < 0x98) {
              if (iVar5 == 0x96) {
                if (uStack_f8 != 0) {
                  (**(code **)(puStack_108 + -0x7fa8))
                            (**(undefined4 **)(puStack_108 + -0x7fa4),"Key bag\n");
                }
                if (uStack_f0 == 0) {
                  print_attribs(pcVar13,ppcStack_14c[2],pcStack_ec);
                  ppcStack_14c = (char **)ppcStack_14c[1];
                  iVar5 = (**(code **)(puStack_108 + -0x7bc0))(ppcStack_14c);
                  if (iVar5 == 0) goto LAB_0046417c;
                  print_attribs(pcVar13,ppcStack_14c[4],pcStack_e0);
                  iStack_110 = iVar3;
                  iStack_114 = 0;
                  ppcStack_118 = (char **)0x0;
                  (**(code **)(puStack_108 + -0x7e90))
                            (pcVar13,iVar5,**(undefined4 **)(puStack_108 + -0x7bbc),0);
                  (**(code **)(puStack_108 + -0x7f68))(iVar5);
                }
              }
              else {
LAB_0046405c:
                puVar15 = *(undefined4 **)(puStack_108 + -0x7fa4);
                (**(code **)(puStack_108 + -0x7fa8))(*puVar15,pcStack_e4 + 0x162c);
                (**(code **)(puStack_108 + -0x7db4))(*puVar15,*ppcStack_14c);
                (**(code **)(puStack_108 + -0x7fa8))(*puVar15,"\n");
              }
            }
            else if (iVar5 == 0x98) {
              if (uStack_f8 != 0) {
                (**(code **)(puStack_108 + -0x7fa8))
                          (**(undefined4 **)(puStack_108 + -0x7fa4),"Certificate bag\n");
              }
              if (uStack_e8 == 0) {
                iVar5 = (**(code **)(puStack_108 + -0x7bcc))(ppcStack_14c[2],0x9d);
                uVar4 = uStack_c4;
                if (iVar5 != 0) {
                  uVar4 = uStack_d4;
                }
                if (uVar4 == 0) {
                  print_attribs(pcVar13,ppcStack_14c[2],pcStack_ec);
                  iVar5 = (**(code **)(puStack_108 + -0x7cb4))(*(undefined4 *)ppcStack_14c[1]);
                  if (iVar5 == 0x9e) {
                    iVar5 = (**(code **)(puStack_108 + -0x7bc8))(ppcStack_14c);
                    if (iVar5 == 0) goto LAB_0046417c;
                    dump_cert_text(pcVar13,iVar5);
                    (**(code **)(puStack_108 + -0x7ec0))(pcVar13,iVar5);
                    (**(code **)(puStack_108 + -0x7f50))(iVar5);
                  }
                }
              }
            }
            else {
              if (iVar5 != 0x9b) goto LAB_0046405c;
              if (uStack_f8 != 0) {
                (**(code **)(puStack_108 + -0x7fa8))
                          (**(undefined4 **)(puStack_108 + -0x7fa4),"Safe Contents bag\n");
              }
              print_attribs(pcVar13,ppcStack_14c[2],pcStack_ec);
              ppcStack_14c = (char **)ppcStack_14c[1];
              for (iVar5 = 0; iVar6 = (**(code **)(puStack_108 + -0x7fb4))(ppcStack_14c),
                  iVar5 < iVar6; iVar5 = iVar5 + 1) {
                uVar7 = (**(code **)(puStack_108 + -0x7fbc))(ppcStack_14c,iVar5);
                iStack_114 = iVar3;
                ppcStack_118 = ppcVar8;
                iVar6 = dump_certs_pkeys_bag(pcVar13,uVar7,pcVar11,ppcStack_138);
                if (iVar6 == 0) goto LAB_0046417c;
              }
            }
LAB_00463ec0:
            unaff_s2 = (char **)((int)unaff_s2 + 1);
            iVar5 = (**(code **)(puStack_108 + -0x7fb4))(param_1);
          } while ((int)unaff_s2 < iVar5);
        }
        (**(code **)(puStack_108 + -0x7d88))(param_1,*(undefined4 *)(puStack_108 + -0x7ba8));
      }
      else if (iVar6 == 0x1a) {
        unaff_s2 = *(char ***)(puStack_108 + -0x7fa4);
        if (uStack_f8 != 0) {
          (**(code **)(puStack_108 + -0x7fa8))(*unaff_s2,"PKCS7 Encrypted data: ");
          puVar14 = *(undefined4 **)(*(int *)(*(int *)(iVar5 + 0x14) + 4) + 4);
          puVar15 = *(undefined4 **)(puVar14[1] + 4);
          uStack_c0 = puVar15[2];
          ppcStack_14c = (char **)(**(code **)(puStack_108 + -0x7bdc))(0,&uStack_c0,*puVar15);
          if (ppcStack_14c != (char **)0x0) {
            pcVar10 = *unaff_s2;
            uVar7 = (**(code **)(puStack_108 + -0x7cb4))(*puVar14);
            unaff_s2 = (char **)(**(code **)(puStack_108 + -0x7cc4))(uVar7);
            uVar7 = (**(code **)(puStack_108 + -0x7bd8))(ppcStack_14c[1]);
            (**(code **)(puStack_108 + -0x7fa8))(pcVar10,pcStack_d0,unaff_s2,uVar7);
            (**(code **)(puStack_108 + -0x7bd4))(ppcStack_14c);
          }
        }
        param_1 = (**(code **)(puStack_108 + -0x7bac))(iVar5,pcVar11,ppcStack_138);
LAB_00463dc0:
        if (param_1 != 0) goto LAB_00463dc8;
LAB_00464330:
        ppcVar12 = (char **)0x0;
        goto LAB_00464194;
      }
      iStack_fc = iStack_fc + 1;
    }
    ppcVar12 = (char **)0x1;
LAB_00464194:
    pcVar10 = *(char **)(puStack_108 + -0x7ba4);
    (**(code **)(puStack_108 + -0x7d88))(iStack_f4);
    param_2 = ppcVar12;
  }
  if (iStack_bc == *piStack_c8) {
    return ppcVar12;
  }
  pcStack_12c = pkcs12_main;
  (**(code **)(puStack_108 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puVar15 = (undefined4 *)PTR_enc_006a7224;
  puVar1 = PTR_bio_err_006a6e3c;
  uStack_250 = 0x92;
  ppcStack_130 = ppcVar8;
  iStack_134 = iVar3;
  ppcStack_24c = (char **)0x0;
  ppcStack_248 = (char **)0x0;
  iStack_154 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppcStack_150 = param_2;
  ppcStack_148 = unaff_s2;
  pcStack_144 = pcVar13;
  iStack_140 = param_1;
  ppcStack_13c = (char **)pcVar11;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  uVar7 = (*(code *)PTR_EVP_des_ede3_cbc_006a6e48)();
  iVar5 = *(int *)puVar1;
  *puVar15 = uVar7;
  if (iVar5 == 0) {
    iVar5 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(int *)puVar1 = iVar5;
  }
  iVar5 = load_config(iVar5,0);
  if (iVar5 == 0) {
    ppcVar12 = (char **)0x1;
    (*(code *)PTR_BIO_free_006a6e70)(0);
    (*(code *)PTR_BIO_free_all_006a6e74)(0);
    goto LAB_00464ac4;
  }
  pcVar11 = *(char **)((int)pcVar10 + 4);
  ppcVar8 = (char **)((int)pcVar10 + 4);
  pcStack_2a4 = (char *)0x0;
  pcStack_25c = (char *)0x0;
  iVar3 = 0;
  uStack_254 = 0x95;
  pcStack_260 = (char *)0x0;
  pcStack_27c = (char *)0x0;
  iStack_264 = 1;
  ppcStack_2c0 = (char **)0x0;
  ppcStack_2b4 = (char **)0x0;
  pcStack_294 = (char *)0x0;
  pcStack_298 = (char *)0x0;
  iStack_2a0 = 0;
  uStack_2b8 = 0;
  iStack_29c = 0;
  iStack_284 = 0x800;
  uStack_274 = 0x800;
  if ((char **)pcVar11 == (char **)0x0) {
    ppcVar12 = (char **)0x0;
    iStack_288 = 0;
    iStack_2c4 = 0;
    pcStack_26c = (char *)0x0;
    pcStack_280 = (char *)0x0;
    pcStack_278 = (char *)0x0;
    pcStack_28c = (char *)0x0;
    pcStack_270 = (char *)0x0;
    ppcStack_2ac = (char **)0x0;
    pcStack_2b0 = (char *)0x0;
    goto LAB_00464bdc;
  }
  iStack_288 = 0;
  iStack_2c4 = 0;
  pcStack_26c = (char *)0x0;
  unaff_s2 = (char **)0x0;
  pcStack_280 = (char *)0x0;
  ppcVar12 = (char **)0x0;
  pcStack_278 = (char *)0x0;
  pcStack_2bc = "-keyex";
  pcVar13 = "-nokeys";
  pcStack_28c = (char *)0x0;
  pcStack_270 = (char *)0x0;
  pcStack_2a8 = "-check_ss_sig";
  ppcStack_2ac = (char **)0x0;
  pcStack_2b0 = (char *)0x0;
  pcStack_290 = "-nocerts";
  pcStack_268 = "-check_ss_sig";
LAB_00464580:
  if (*pcVar11 == '-') {
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,pcVar13);
    if (iVar5 == 0) {
      ppcVar12 = (char **)((uint)ppcVar12 | 1);
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,pcStack_2bc);
    if (iVar5 == 0) {
      uStack_2b8 = 0x10;
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,pcStack_2a8 + 0x1694);
    if (iVar5 == 0) {
      uStack_2b8 = 0x80;
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,pcStack_290);
    if (iVar5 == 0) {
      ppcVar12 = (char **)((uint)ppcVar12 | 2);
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,pcStack_268 + 0x16a8);
    if (iVar5 == 0) {
      ppcVar12 = (char **)((uint)ppcVar12 | 8);
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-cacerts");
    if (iVar5 == 0) {
      ppcVar12 = (char **)((uint)ppcVar12 | 0x10);
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-noout");
    if (iVar5 == 0) {
      ppcVar12 = (char **)((uint)ppcVar12 | 3);
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-info");
    if (iVar5 == 0) {
      ppcVar12 = (char **)((uint)ppcVar12 | 4);
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-chain");
    if (iVar5 == 0) {
      iStack_288 = 1;
      goto LAB_00464594;
    }
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-twopass");
    if (iVar5 != 0) {
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-nomacver");
      if (iVar5 != 0) {
        iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-descert");
        if (iVar5 != 0) goto LAB_004659f4;
        uStack_254 = 0x92;
        goto LAB_00464594;
      }
      iStack_264 = 0;
      goto LAB_00464594;
    }
    iStack_29c = 1;
    goto LAB_00464594;
  }
LAB_00464590:
  unaff_s2 = (char **)0x1;
LAB_00464594:
  do {
    pcVar11 = ppcVar8[1];
    ppcVar8 = ppcVar8 + 1;
    if ((char **)pcVar11 != (char **)0x0) goto LAB_00464580;
    if (unaff_s2 == (char **)0x0) {
LAB_00464bdc:
      unaff_s2 = (char **)PTR_bio_err_006a6e3c;
      ppcVar8 = (char **)setup_engine(*(undefined4 *)puVar1,pcStack_2a4,0);
      if (ppcStack_2b4 != (char **)0x0) {
        if (iStack_2c4 == 0) {
          iVar5 = app_passwd(*unaff_s2,ppcStack_2b4,pcStack_294,&ppcStack_24c,&ppcStack_248);
          if (iVar5 != 0) goto LAB_00464c30;
        }
        else {
          iVar5 = app_passwd(*unaff_s2,pcStack_298,ppcStack_2b4,&ppcStack_24c,&ppcStack_248);
          if (iVar5 != 0) goto LAB_00464e70;
        }
LAB_00464ee8:
        pcVar13 = (char *)0x0;
        puVar15 = (undefined4 *)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"Error getting passwords\n");
        goto LAB_00464a38;
      }
      iVar5 = app_passwd(*unaff_s2,pcStack_298,pcStack_294,&ppcStack_24c,&ppcStack_248);
      if (iVar5 == 0) goto LAB_00464ee8;
      if (iStack_2c4 == 0) {
LAB_00464c30:
        if (ppcStack_24c == (char **)0x0) {
LAB_004652a0:
          ppcStack_2b4 = apcStack_188;
          pcVar11 = (char *)apcStack_1bc;
        }
        else {
          ppcStack_2b4 = ppcStack_24c;
          iStack_2a0 = 1;
          pcVar11 = (char *)ppcStack_24c;
        }
        if (ppcStack_2c0 != (char **)0x0) {
          app_RAND_load_file(0,*(undefined4 *)puVar1,1);
LAB_00464c68:
          unaff_s2 = *(char ***)puVar1;
          uVar7 = app_RAND_load_files(ppcStack_2c0);
          (*(code *)PTR_BIO_printf_006a6e38)(unaff_s2,"%ld semi-random bytes loaded\n",uVar7);
        }
      }
      else {
LAB_00464e70:
        if (ppcStack_248 == (char **)0x0) {
          ppcStack_2b4 = apcStack_188;
          if (iStack_2c4 == 0) goto LAB_004652a0;
          pcVar11 = (char *)apcStack_1bc;
        }
        else {
          ppcStack_2b4 = ppcStack_248;
          iStack_2a0 = 1;
          pcVar11 = (char *)ppcStack_248;
        }
        app_RAND_load_file(0,*(undefined4 *)puVar1,ppcStack_2c0 != (char **)0x0);
        unaff_s2 = ppcStack_2c0;
        if (ppcStack_2c0 != (char **)0x0) goto LAB_00464c68;
      }
      (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
      if (pcStack_2b0 == (char *)0x0) {
        puVar15 = (undefined4 *)
                  (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14,0);
        if (puVar15 == (undefined4 *)0x0) {
          uVar7 = *(undefined4 *)puVar1;
          pcVar10 = "<stdin>";
          goto LAB_0046542c;
        }
      }
      else {
        puVar15 = (undefined4 *)(*(code *)PTR_BIO_new_file_006a6eac)(pcStack_2b0,&DAT_00633e40);
        if (puVar15 == (undefined4 *)0x0) {
          uVar7 = *(undefined4 *)puVar1;
          pcVar10 = pcStack_2b0;
LAB_0046542c:
          pcVar13 = (char *)0x0;
          puVar15 = (undefined4 *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)(uVar7,"Error opening input file %s\n",pcVar10);
          (*(code *)PTR_perror_006a9a80)(pcStack_2b0);
          goto LAB_00464a38;
        }
      }
      if (ppcStack_2ac == (char **)0x0) {
        pcVar13 = (char *)(*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
        if (pcVar13 == (char *)0x0) {
          uVar7 = *(undefined4 *)puVar1;
          pcVar10 = "<stdout>";
          goto LAB_00465488;
        }
      }
      else {
        pcVar13 = (char *)(*(code *)PTR_BIO_new_file_006a6eac)(ppcStack_2ac,&DAT_00632420);
        if (pcVar13 == (char *)0x0) {
          uVar7 = *(undefined4 *)puVar1;
          pcVar10 = (char *)ppcStack_2ac;
LAB_00465488:
          pcVar13 = (char *)0x0;
          (*(code *)PTR_BIO_printf_006a6e38)(uVar7,"Error opening output file %s\n",pcVar10);
          (*(code *)PTR_perror_006a9a80)(ppcStack_2ac);
          goto LAB_00464a38;
        }
      }
      if ((iStack_29c != 0) &&
         (iVar5 = (*(code *)PTR_EVP_read_pw_string_006a7278)
                            (apcStack_188,0x32,"Enter MAC Password:",iStack_2c4), iVar5 != 0)) {
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"Can\'t read Password\n");
        goto LAB_00464a38;
      }
      if (iStack_2c4 == 0) {
        ppcVar8 = (char **)(*(code *)PTR_d2i_PKCS12_bio_006a727c)(puVar15,0);
        if (ppcVar8 != (char **)0x0) {
          if ((iStack_2a0 == 0) &&
             (iVar5 = (*(code *)PTR_EVP_read_pw_string_006a7278)
                                (apcStack_1bc,0x32,"Enter Import Password:",0), iVar5 != 0)) {
            ppcVar12 = (char **)0x1;
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"Can\'t read Password\n");
          }
          else {
            if (iStack_29c == 0) {
              (*(code *)PTR_BUF_strlcpy_006a6f64)(apcStack_188,apcStack_1bc,0x32);
            }
            if ((((uint)ppcVar12 & 4) != 0) && (ppcVar8[1] != (char *)0x0)) {
              unaff_s2 = *(char ***)puVar1;
              if (*(int *)(ppcVar8[1] + 8) == 0) {
                uVar7 = 1;
              }
              else {
                uVar7 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)();
              }
              (*(code *)PTR_BIO_printf_006a6e38)(unaff_s2,"MAC Iteration %ld\n",uVar7);
            }
            if (iStack_264 != 0) {
              if ((*(char *)ppcStack_2b4 == '\0') &&
                 (iVar5 = (*(code *)PTR_PKCS12_verify_mac_006a7280)(ppcVar8,0,0), iVar5 != 0)) {
                if (iStack_29c == 0) {
                  pcVar11 = (char *)0x0;
                }
              }
              else {
                iVar5 = (*(code *)PTR_PKCS12_verify_mac_006a7280)(ppcVar8,ppcStack_2b4,0xffffffff);
                if (iVar5 == 0) {
                  ppcVar12 = (char **)0x1;
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar1,"Mac verify error: invalid password?\n");
                  (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar1);
                  goto LAB_004651cc;
                }
              }
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"MAC verified OK\n");
            }
            iVar5 = dump_certs_keys_p12(pcVar13,ppcVar8,pcVar11,0xffffffff,ppcVar12,ppcStack_248);
            if (iVar5 == 0) {
              ppcVar12 = (char **)0x1;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar1,"Error outputting keys and certificates\n");
              (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar1);
            }
            else {
              ppcVar12 = (char **)0x0;
            }
          }
LAB_004651cc:
          (*(code *)PTR_PKCS12_free_006a7268)(ppcVar8);
          goto LAB_00464a3c;
        }
        ppcVar12 = (char **)0x1;
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar1);
        goto LAB_00464a48;
      }
      if (((uint)ppcVar12 & 3) == 3) {
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"Nothing to do!\n");
LAB_004654f8:
        ppcVar12 = (char **)0x1;
      }
      else {
        unaff_s2 = (char **)((uint)ppcVar12 & 2);
        if (unaff_s2 == (char **)0x0) {
          if (((uint)ppcVar12 & 1) != 0) {
            ppcVar12 = (char **)0x1;
            unaff_s2 = (char **)load_certs(*(undefined4 *)puVar1,pcStack_2b0,3,0,ppcVar8,
                                           "certificates");
            if (unaff_s2 != (char **)0x0) {
              pcStack_2bc = (char *)0x0;
              pcStack_2b0 = (char *)0x0;
LAB_004655d4:
              if (pcStack_28c == (char *)0x0) goto LAB_00464fd8;
              iVar5 = load_certs(*(undefined4 *)puVar1,pcStack_28c,3,0,ppcVar8,
                                 "certificates from certfile");
              if (iVar5 != 0) goto LAB_00464fb4;
              ppcVar12 = (char **)0x1;
              ppcVar8 = (char **)0x0;
              goto LAB_00465178;
            }
            goto LAB_00464a58;
          }
LAB_00464d30:
          pcVar10 = pcStack_270;
          if (pcStack_270 == (char *)0x0) {
            pcVar10 = pcStack_2b0;
          }
          pcStack_2bc = (char *)load_key(*(undefined4 *)puVar1,pcVar10,3,1,ppcStack_24c,ppcVar8,
                                         "private key");
          if (pcStack_2bc == (char *)0x0) goto LAB_004654f8;
          if (unaff_s2 != (char **)0x0) {
            unaff_s2 = (char **)0x0;
            pcStack_2b0 = (char *)0x0;
            goto LAB_004655d4;
          }
          unaff_s2 = (char **)load_certs(*(undefined4 *)puVar1,pcStack_2b0,3,0,ppcVar8,
                                         "certificates");
          if (unaff_s2 == (char **)0x0) {
            pcStack_2b0 = (char *)0x0;
            ppcVar12 = (char **)0x1;
            ppcVar8 = (char **)0x0;
            ppcVar16 = (char **)pcVar11;
          }
          else {
            for (ppcVar16 = (char **)0x0; iVar5 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s2),
                ppcStack_2ac = (char **)pcVar11, (int)ppcVar16 < iVar5;
                ppcVar16 = (char **)((int)ppcVar16 + 1)) {
              pcStack_2b0 = (char *)(*(code *)PTR_sk_value_006a6e24)(unaff_s2,ppcVar16);
              iVar5 = (*(code *)PTR_X509_check_private_key_006a707c)(pcStack_2b0,pcStack_2bc);
              if (iVar5 != 0) {
                (*(code *)PTR_X509_keyid_set1_006a7284)(pcStack_2b0,0,0);
                (*(code *)PTR_X509_alias_set1_006a7254)(pcStack_2b0,0,0);
                (*(code *)PTR_sk_delete_006a7288)(unaff_s2,ppcVar16);
                ppcVar16 = (char **)pcVar11;
                if (pcStack_2b0 != (char *)0x0) goto LAB_004655d4;
                break;
              }
            }
            ppcVar12 = (char **)0x1;
            ppcVar8 = (char **)0x0;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar1,"No certificate matches private key\n");
            pcStack_2b0 = (char *)0x0;
          }
LAB_00465184:
          (*(code *)PTR_EVP_PKEY_free_006a6e78)(pcStack_2bc);
          pcVar11 = (char *)ppcVar16;
        }
        else {
          if (((uint)ppcVar12 & 1) == 0) {
            iStack_288 = 0;
            goto LAB_00464d30;
          }
          if (pcStack_28c == (char *)0x0) {
            pcStack_2bc = (char *)0x0;
            unaff_s2 = (char **)0x0;
            pcStack_2b0 = (char *)0x0;
LAB_00464fe4:
            for (iVar5 = 0; iVar6 = (*(code *)PTR_sk_num_006a6e2c)(iVar3), iVar5 < iVar6;
                iVar5 = iVar5 + 1) {
              uVar7 = (*(code *)PTR_sk_value_006a6e24)(iVar3,iVar5);
              uVar9 = (*(code *)PTR_sk_value_006a6e24)(unaff_s2,iVar5);
              (*(code *)PTR_X509_alias_set1_006a7254)(uVar9,uVar7,0xffffffff);
            }
            if (pcStack_280 == (char *)0x0) {
              pcVar10 = pcStack_2bc;
              if (pcStack_26c != (char *)0x0) goto joined_r0x00465740;
            }
            else if (pcStack_2bc != (char *)0x0) {
              (*(code *)PTR_EVP_PKEY_add1_attr_by_NID_006a7258)
                        (pcStack_2bc,0x1a1,0x1001,pcStack_280,0xffffffff);
              pcVar10 = pcStack_26c;
joined_r0x00465740:
              if (pcVar10 != (char *)0x0) {
                (*(code *)PTR_EVP_PKEY_add1_attr_by_NID_006a7258)(pcStack_2bc,0x358,0,0,0xffffffff);
              }
            }
            if ((iStack_2a0 == 0) &&
               (iVar5 = (*(code *)PTR_EVP_read_pw_string_006a7278)
                                  (apcStack_1bc,0x32,"Enter Export Password:",1), iVar5 != 0)) {
              ppcVar12 = (char **)0x1;
              ppcVar8 = (char **)0x0;
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"Can\'t read Password\n");
            }
            else {
              if (iStack_29c == 0) {
                (*(code *)PTR_BUF_strlcpy_006a6f64)(apcStack_188,apcStack_1bc,0x32);
              }
              ppcVar8 = (char **)(*(code *)PTR_PKCS12_create_006a725c)
                                           (pcVar11,pcStack_278,pcStack_2bc,pcStack_2b0,unaff_s2,
                                            uStack_250,uStack_254,uStack_274,0xffffffff,uStack_2b8);
              if (ppcVar8 == (char **)0x0) {
                ppcVar12 = (char **)0x1;
                (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar1);
              }
              else {
                if (pcStack_27c == (char *)0x0) {
                  iVar5 = 0;
                }
                else {
                  iVar5 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(pcStack_27c);
                  if (iVar5 == 0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar1,"Unknown digest algorithm %s\n",pcStack_27c);
                  }
                }
                if (iStack_284 != -1) {
                  (*(code *)PTR_PKCS12_set_mac_006a7260)
                            (ppcVar8,ppcStack_2b4,0xffffffff,0,0,iStack_284,iVar5);
                }
                ppcVar12 = (char **)0x0;
                (*(code *)PTR_i2d_PKCS12_bio_006a7264)(pcVar13,ppcVar8);
              }
            }
          }
          else {
            iVar5 = load_certs(*(undefined4 *)puVar1,pcStack_28c,3,0,ppcVar8,
                               "certificates from certfile");
            if (iVar5 == 0) goto LAB_004654f8;
            pcStack_2bc = (char *)0x0;
            unaff_s2 = (char **)0x0;
            pcStack_2b0 = (char *)0x0;
            iStack_288 = 0;
LAB_00464fb4:
            while (iVar6 = (*(code *)PTR_sk_num_006a6e2c)(iVar5), 0 < iVar6) {
              uVar7 = (*(code *)PTR_sk_shift_006a724c)(iVar5);
              (*(code *)PTR_sk_push_006a6fa8)(unaff_s2,uVar7);
            }
            (*(code *)PTR_sk_free_006a6e80)(iVar5);
LAB_00464fd8:
            if (iStack_288 == 0) goto LAB_00464fe4;
            ppcVar8 = (char **)(*(code *)PTR_X509_STORE_new_006a7250)();
            if (ppcVar8 == (char **)0x0) {
              ppcVar12 = (char **)0x1;
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"Memory allocation error\n");
            }
            else {
              iVar5 = (*(code *)PTR_X509_STORE_load_locations_006a726c)
                                (ppcVar8,pcStack_25c,pcStack_260);
              if (iVar5 == 0) {
                (*(code *)PTR_X509_STORE_set_default_paths_006a7298)(ppcVar8);
              }
              iVar5 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)(auStack_244,ppcVar8,pcStack_2b0,0)
              ;
              if (iVar5 == 0) {
                (*(code *)PTR_X509_STORE_free_006a7274)(ppcVar8);
              }
              else {
                iVar5 = (*(code *)PTR_X509_verify_cert_006a728c)(auStack_244);
                if (0 < iVar5) {
                  uVar7 = (*(code *)PTR_X509_STORE_CTX_get1_chain_006a7290)(auStack_244);
                  (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(auStack_244);
                  (*(code *)PTR_X509_STORE_free_006a7274)(ppcVar8);
                  for (iVar5 = 1; iVar6 = (*(code *)PTR_sk_num_006a6e2c)(uVar7), iVar5 < iVar6;
                      iVar5 = iVar5 + 1) {
                    uVar9 = (*(code *)PTR_sk_value_006a6e24)(uVar7,iVar5);
                    (*(code *)PTR_sk_push_006a6fa8)(unaff_s2,uVar9);
                  }
                  uVar9 = (*(code *)PTR_sk_value_006a6e24)(uVar7,0);
                  (*(code *)PTR_X509_free_006a6e90)(uVar9);
                  (*(code *)PTR_sk_free_006a6e80)(uVar7);
                  goto LAB_00464fe4;
                }
                pcVar11 = (char *)(*(code *)PTR_X509_STORE_CTX_get_error_006a729c)(auStack_244);
                if ((char **)pcVar11 == (char **)0x0) {
                  (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(auStack_244);
                  (*(code *)PTR_X509_STORE_free_006a7274)(ppcVar8);
                }
                else {
                  (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(auStack_244);
                  (*(code *)PTR_X509_STORE_free_006a7274)(ppcVar8);
                  if ((char **)pcVar11 != (char **)0x1) {
                    uVar9 = *(undefined4 *)puVar1;
                    ppcVar8 = (char **)0x0;
                    uVar7 = (*(code *)PTR_X509_verify_cert_error_string_006a72a0)(pcVar11);
                    ppcVar12 = (char **)0x1;
                    (*(code *)PTR_BIO_printf_006a6e38)(uVar9,"Error %s getting chain.\n",uVar7);
                    goto LAB_00465178;
                  }
                }
              }
              ppcVar12 = (char **)0x1;
              ppcVar8 = (char **)0x0;
              (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar1);
            }
          }
LAB_00465178:
          ppcVar16 = (char **)pcVar11;
          if (pcStack_2bc != (char *)0x0) goto LAB_00465184;
        }
        if (unaff_s2 != (char **)0x0) {
          (*(code *)PTR_sk_pop_free_006a7058)(unaff_s2,PTR_X509_free_006a6e90);
        }
        if (pcStack_2b0 != (char *)0x0) {
          (*(code *)PTR_X509_free_006a6e90)(pcStack_2b0);
        }
        if (ppcVar8 != (char **)0x0) goto LAB_004651cc;
      }
LAB_00464a58:
      app_RAND_write_file(0,*(undefined4 *)puVar1);
    }
    else {
      pcVar13 = (char *)0x0;
      puVar15 = (undefined4 *)0x0;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"Usage: pkcs12 [options]\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"where options are\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-export       output PKCS12 file\n")
      ;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-chain        add certificate chain\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-inkey file   private key if not infile\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-certfile f   add all certs in f\n")
      ;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-CApath arg   - PEM format directory of CA\'s\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-CAfile arg   - PEM format file of CA\'s\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-name \"name\"  use name as friendly name\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,
                 "-caname \"nm\"  use nm as CA friendly name (can be used more than once).\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-in  infile   input filename\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-out outfile  output filename\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-noout        don\'t output anything, just verify.\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-nomacver     don\'t verify MAC.\n")
      ;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-nocerts      don\'t output certificates.\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-clcerts      only output client certificates.\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-cacerts      only output CA certificates.\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-nokeys       don\'t output private keys.\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-info         give info about PKCS#12 structure.\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-des          encrypt private keys with DES\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,
                 "-des3         encrypt private keys with triple DES (default)\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-idea         encrypt private keys with idea\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-seed         encrypt private keys with seed\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-aes128, -aes192, -aes256\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"              encrypt PEM output with cbc aes\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-camellia128, -camellia192, -camellia256\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"              encrypt PEM output with cbc camellia\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-nodes        don\'t encrypt private keys\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-noiter       don\'t use encryption iteration\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-nomaciter    don\'t use MAC iteration\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-maciter      use MAC iteration\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-nomac        don\'t generate MAC\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-twopass      separate MAC, encryption passwords\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,
                 "-descert      encrypt PKCS#12 certificates with triple DES (default RC2-40)\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,
                 "-certpbe alg  specify certificate PBE algorithm (default RC2-40)\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,
                 "-keypbe alg   specify private key PBE algorithm (default 3DES)\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-macalg alg   digest algorithm used in MAC (default SHA1)\n"
                );
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-keyex        set MS key exchange type\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-keysig       set MS key signature type\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-password p   set import/export password source\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-passin p     input file pass phrase source\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-passout p    output file pass phrase source\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"-engine e     use engine e, possibly a hardware device.\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-rand file%cfile%c...\n",0x3a,0x3a);
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,
                 "              load the file (or the files in the directory) into\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,"              the random number generator\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"-CSP name     Microsoft CSP name\n")
      ;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar1,
                 "-LMK          Add local machine keyset attribute to private key\n");
LAB_00464a38:
      ppcVar12 = (char **)0x1;
LAB_00464a3c:
      if (iStack_2c4 != 0) goto LAB_00464a58;
LAB_00464a48:
      if (ppcStack_2c0 != (char **)0x0) goto LAB_00464a58;
    }
    (*(code *)PTR_BIO_free_006a6e70)(puVar15);
    (*(code *)PTR_BIO_free_all_006a6e74)(pcVar13);
    if (iVar3 != 0) {
      (*(code *)PTR_sk_free_006a6e80)(iVar3);
    }
LAB_00464ac4:
    if (ppcStack_24c != (char **)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (ppcStack_248 != (char **)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (iStack_154 == *(int *)puVar2) {
      return ppcVar12;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004659f4:
    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-export");
    if (iVar5 != 0) {
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,&DAT_0063a4ec);
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_des_cbc_006a72a4)();
        *puVar15 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-des3");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_des_ede3_cbc_006a6e48)();
        *puVar15 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-idea");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_idea_cbc_006a72ac)();
        *puVar15 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-seed");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_seed_cbc_006a72b0)();
        *puVar15 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-aes128");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_aes_128_cbc_006a72a8)();
        *puVar15 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-aes192");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_aes_192_cbc_006a72c0)();
        *puVar15 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-aes256");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_aes_256_cbc_006a72bc)();
        *puVar15 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-camellia128");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_camellia_128_cbc_006a72b8)();
        *puVar15 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-camellia192");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_camellia_192_cbc_006a72b4)();
        *puVar15 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-camellia256");
      if (iVar5 == 0) {
        uVar7 = (*(code *)PTR_EVP_camellia_256_cbc_006a72c4)();
        *puVar15 = uVar7;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-noiter");
      if (iVar5 == 0) {
        uStack_274 = 1;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-maciter");
      if (iVar5 == 0) {
        iStack_284 = 0x800;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-nomaciter");
      if (iVar5 == 0) {
        iStack_284 = 1;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-nomac");
      if (iVar5 == 0) {
        iStack_284 = -1;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-macalg");
      if (iVar5 == 0) {
        ppcVar16 = ppcVar8 + 1;
        if (*ppcVar16 == (char *)0x0) goto LAB_00464590;
        ppcVar8 = ppcVar8 + 1;
        pcStack_27c = *ppcVar16;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-nodes");
      if (iVar5 == 0) {
        *puVar15 = 0;
        goto LAB_00464594;
      }
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-certpbe");
      if (iVar5 == 0) {
        pcVar10 = ppcVar8[1];
        puVar14 = &uStack_254;
      }
      else {
        iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-keypbe");
        if (iVar5 != 0) {
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-rand");
          if (iVar5 == 0) {
            ppcVar16 = ppcVar8 + 1;
            if ((char **)*ppcVar16 == (char **)0x0) goto LAB_00464590;
            ppcVar8 = ppcVar8 + 1;
            ppcStack_2c0 = (char **)*ppcVar16;
            goto LAB_00464594;
          }
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-inkey");
          if (iVar5 == 0) {
            ppcVar16 = ppcVar8 + 1;
            if (*ppcVar16 == (char *)0x0) goto LAB_00464590;
            ppcVar8 = ppcVar8 + 1;
            pcStack_270 = *ppcVar16;
            goto LAB_00464594;
          }
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-certfile");
          if (iVar5 == 0) {
            ppcVar16 = ppcVar8 + 1;
            if (*ppcVar16 == (char *)0x0) goto LAB_00464590;
            ppcVar8 = ppcVar8 + 1;
            pcStack_28c = *ppcVar16;
            goto LAB_00464594;
          }
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-name");
          if (iVar5 == 0) {
            ppcVar16 = ppcVar8 + 1;
            if (*ppcVar16 == (char *)0x0) goto LAB_00464590;
            ppcVar8 = ppcVar8 + 1;
            pcStack_278 = *ppcVar16;
            goto LAB_00464594;
          }
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,&DAT_00641738);
          if (iVar5 == 0) {
            pcStack_26c = (char *)0x1;
            goto LAB_00464594;
          }
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,&DAT_00641740);
          if (iVar5 == 0) {
            ppcVar16 = ppcVar8 + 1;
            if (*ppcVar16 == (char *)0x0) goto LAB_00464590;
            ppcVar8 = ppcVar8 + 1;
            pcStack_280 = *ppcVar16;
            goto LAB_00464594;
          }
          iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-caname");
          if (iVar5 != 0) {
            if (((*(char *)((int)pcVar11 + 1) == 'i') && (*(char *)((int)pcVar11 + 2) == 'n')) &&
               (*(char *)((int)pcVar11 + 3) == '\0')) {
              ppcVar16 = ppcVar8 + 1;
              if (*ppcVar16 == (char *)0x0) goto LAB_00464590;
              ppcVar8 = ppcVar8 + 1;
              pcStack_2b0 = *ppcVar16;
            }
            else {
              iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,&DAT_00632514);
              if (iVar5 == 0) {
                ppcVar16 = ppcVar8 + 1;
                if ((char **)*ppcVar16 == (char **)0x0) goto LAB_00464590;
                ppcVar8 = ppcVar8 + 1;
                ppcStack_2ac = (char **)*ppcVar16;
              }
              else {
                iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-passin");
                if (iVar5 == 0) {
                  ppcVar16 = ppcVar8 + 1;
                  if (*ppcVar16 == (char *)0x0) goto LAB_00464590;
                  ppcVar8 = ppcVar8 + 1;
                  pcStack_298 = *ppcVar16;
                }
                else {
                  iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-passout");
                  if (iVar5 == 0) {
                    ppcVar16 = ppcVar8 + 1;
                    if (*ppcVar16 == (char *)0x0) goto LAB_00464590;
                    ppcVar8 = ppcVar8 + 1;
                    pcStack_294 = *ppcVar16;
                  }
                  else {
                    iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-password");
                    if (iVar5 == 0) {
                      ppcVar16 = ppcVar8 + 1;
                      if ((char **)*ppcVar16 == (char **)0x0) goto LAB_00464590;
                      ppcVar8 = ppcVar8 + 1;
                      iStack_2a0 = 1;
                      ppcStack_2b4 = (char **)*ppcVar16;
                    }
                    else {
                      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-CApath");
                      if (iVar5 == 0) {
                        ppcVar16 = ppcVar8 + 1;
                        if (*ppcVar16 == (char *)0x0) goto LAB_00464590;
                        ppcVar8 = ppcVar8 + 1;
                        pcStack_260 = *ppcVar16;
                      }
                      else {
                        iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-CAfile");
                        if (iVar5 == 0) {
                          ppcVar16 = ppcVar8 + 1;
                          if (*ppcVar16 == (char *)0x0) goto LAB_00464590;
                          ppcVar8 = ppcVar8 + 1;
                          pcStack_25c = *ppcVar16;
                        }
                        else {
                          iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar11,"-engine");
                          if ((iVar5 != 0) || (ppcVar16 = ppcVar8 + 1, *ppcVar16 == (char *)0x0))
                          goto LAB_00464590;
                          ppcVar8 = ppcVar8 + 1;
                          pcStack_2a4 = *ppcVar16;
                        }
                      }
                    }
                  }
                }
              }
            }
            goto LAB_00464594;
          }
          pcVar10 = ppcVar8[1];
          if (pcVar10 != (char *)0x0) {
            if (iVar3 == 0) {
              iVar3 = (*(code *)PTR_sk_new_null_006a6fa4)();
              pcVar10 = ppcVar8[1];
            }
            (*(code *)PTR_sk_push_006a6fa8)(iVar3,pcVar10);
            ppcVar8 = ppcVar8 + 1;
            goto LAB_00464594;
          }
          goto LAB_00464590;
        }
        pcVar10 = ppcVar8[1];
        puVar14 = &uStack_250;
      }
      ppcVar8 = ppcVar8 + 1;
      iVar5 = set_pbe_isra_0(puVar14,pcVar10);
      if (iVar5 == 0) {
        unaff_s2 = (char **)0x1;
      }
      goto LAB_00464594;
    }
    iStack_2c4 = 1;
  } while( true );
}

