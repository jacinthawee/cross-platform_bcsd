
int * do_PVK_body_isra_3(int *param_1,int param_2,uint param_3,int *param_4,int **param_5)

{
  char cVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  int iVar13;
  int *piVar14;
  char **ppcVar15;
  uint uVar16;
  int *piVar17;
  uint uVar18;
  undefined4 uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  char *pcVar23;
  int *piVar24;
  char *pcVar25;
  char *pcVar26;
  code *pcVar27;
  int *unaff_s8;
  int iStack_668;
  int iStack_664;
  int *piStack_660;
  int *piStack_65c;
  undefined *puStack_658;
  int iStack_654;
  int *piStack_650;
  int iStack_64c;
  char *pcStack_648;
  char *pcStack_644;
  int *piStack_640;
  code *pcStack_63c;
  undefined4 uStack_628;
  undefined *puStack_620;
  int *piStack_618;
  char cStack_614;
  char cStack_613;
  uint uStack_60c;
  uint uStack_608;
  int iStack_604;
  int *piStack_600;
  undefined *puStack_5fc;
  uint uStack_5f8;
  int iStack_5f4;
  int *piStack_5f0;
  int iStack_5ec;
  char *pcStack_5e8;
  code *pcStack_5e4;
  undefined4 uStack_5d0;
  undefined *puStack_5c8;
  int *piStack_5c0;
  char cStack_5bc;
  char cStack_5bb;
  uint uStack_5b4;
  uint uStack_5b0;
  int iStack_5ac;
  undefined *puStack_5a8;
  int *piStack_5a4;
  uint uStack_5a0;
  int **ppiStack_59c;
  int *piStack_598;
  int iStack_594;
  undefined *puStack_590;
  code *pcStack_58c;
  undefined4 uStack_578;
  undefined *puStack_570;
  char *pcStack_568;
  int iStack_564;
  undefined *puStack_55c;
  int *piStack_558;
  code *pcStack_554;
  undefined4 uStack_540;
  undefined *puStack_538;
  char *pcStack_530;
  char **ppcStack_52c;
  int *piStack_524;
  int *piStack_520;
  code *pcStack_51c;
  int local_508;
  undefined *local_500;
  int *local_4f4;
  int local_4f0;
  int *local_4ec;
  int *local_4e4 [6];
  int aiStack_4cc [35];
  int iStack_440;
  undefined local_43b;
  undefined local_43a;
  undefined local_439;
  undefined local_438;
  undefined local_437;
  undefined local_436;
  undefined local_435;
  undefined local_434;
  undefined local_433;
  undefined local_432;
  undefined local_431;
  int aiStack_42c [256];
  char **local_2c;
  
  pcVar23 = PTR___stack_chk_guard_006aabf0;
  piStack_650 = aiStack_4cc;
  local_500 = &_gp;
  local_2c = *(char ***)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(piStack_650);
  if (param_2 == 0) {
    param_4 = param_1;
    piVar24 = (int *)0x0;
    goto LAB_0057606c;
  }
  local_4f4 = aiStack_42c;
  if (param_4 == (int *)0x0) {
    unaff_s8 = (int *)PEM_def_callback((char *)local_4f4,0x400,0,param_5);
  }
  else {
    unaff_s8 = (int *)(*(code *)param_4)(local_4f4,0x400,0,param_5);
  }
  if ((int)unaff_s8 < 1) {
    local_508 = 0x2ea;
    piVar3 = (int *)0x87;
    (**(code **)(local_500 + -0x6eb0))(9,0x87,0x68,FUN_0066ce6c);
    piVar5 = (int *)0x0;
  }
  else {
    param_4 = (int *)(**(code **)(local_500 + -0x7dd8))(param_3 + 8,FUN_0066ce6c,0x2ed);
    if (param_4 == (int *)0x0) {
      piVar3 = (int *)0x87;
      local_508 = 0x2f0;
      (**(code **)(local_500 + -0x6eb0))(9,0x87,0x41,FUN_0066ce6c);
      piVar5 = (int *)0x0;
    }
    else {
      param_5 = local_4e4;
      (**(code **)(local_500 + -0x7fc4))(param_5);
      piVar3 = (int *)(**(code **)(local_500 + -0x781c))();
      iVar4 = (**(code **)(local_500 + -0x7870))(param_5,piVar3,0);
      if (((iVar4 != 0) &&
          (piVar3 = param_1, iVar4 = (**(code **)(local_500 + -0x786c))(param_5,param_1,param_2),
          iVar4 != 0)) &&
         (piVar3 = local_4f4, iVar4 = (**(code **)(local_500 + -0x786c))(param_5,local_4f4,unaff_s8)
         , iVar4 != 0)) {
        unaff_s8 = &iStack_440;
        piVar3 = unaff_s8;
        iVar4 = (**(code **)(local_500 + -0x7868))(param_5,unaff_s8,0);
        if (iVar4 != 0) {
          param_1 = (int *)((int)param_1 + param_2);
          (**(code **)(local_500 + -0x7fac))(param_5);
          iVar4 = param_1[1];
          pcVar27 = *(code **)(local_500 + -0x69b8);
          *param_4 = *param_1;
          param_4[1] = iVar4;
          piVar3 = (int *)(*pcVar27)();
          local_508 = 0;
          iVar4 = (**(code **)(local_500 + -0x738c))(piStack_650,piVar3,0,unaff_s8);
          piVar24 = param_4;
          if (iVar4 == 0) {
LAB_0057603c:
            piVar5 = (int *)0x0;
            (**(code **)(local_500 + -0x7380))(piStack_650);
            pcVar27 = *(code **)(local_500 + -0x7f58);
          }
          else {
            local_4f4 = param_1 + 2;
            local_508 = param_3 - 8;
            piVar5 = param_4 + 2;
            piVar3 = piVar5;
            local_4f0 = local_508;
            iVar4 = (**(code **)(local_500 + -0x7384))(piStack_650,piVar5,param_5,local_4f4);
            if (iVar4 == 0) goto LAB_0057603c;
            piVar3 = (int *)((int)piVar5 + (int)local_4e4[0]);
            iVar4 = (**(code **)(local_500 + -0x7388))(piStack_650,piVar3,param_5);
            if (iVar4 == 0) goto LAB_0057603c;
            uVar8 = (uint)*(byte *)((int)param_4 + 9) << 8 |
                    (uint)*(byte *)((int)param_4 + 10) << 0x10 | (uint)*(byte *)(param_4 + 2) |
                    (uint)*(byte *)((int)param_4 + 0xb) << 0x18;
            if ((uVar8 != 0x32415352) && (local_4ec = (int *)0x32535344, uVar8 != 0x32535344)) {
              local_43b = 0;
              local_43a = 0;
              local_439 = 0;
              local_438 = 0;
              local_437 = 0;
              local_436 = 0;
              local_435 = 0;
              local_434 = 0;
              local_433 = 0;
              local_432 = 0;
              local_431 = 0;
              piVar3 = (int *)(**(code **)(local_500 + -0x69b8))();
              local_508 = 0;
              iVar4 = (**(code **)(local_500 + -0x738c))(piStack_650,piVar3,0,unaff_s8);
              if (iVar4 != 0) {
                (**(code **)(local_500 + -0x7d6c))(unaff_s8,0x14);
                local_508 = local_4f0;
                piVar3 = piVar5;
                iVar4 = (**(code **)(local_500 + -0x7384))(piStack_650,piVar5,param_5,local_4f4);
                if (iVar4 != 0) {
                  local_4f4 = local_4ec;
                  piVar3 = (int *)((int)piVar5 + (int)local_4e4[0]);
                  iVar4 = (**(code **)(local_500 + -0x7388))(piStack_650,piVar3,param_5);
                  if (iVar4 != 0) {
                    piVar3 = (int *)((uint)*(byte *)((int)param_4 + 9) << 8 |
                                     (uint)*(byte *)((int)param_4 + 10) << 0x10 |
                                     (uint)*(byte *)(param_4 + 2) |
                                    (uint)*(byte *)((int)param_4 + 0xb) << 0x18);
                    if ((piVar3 == (int *)0x32415352) || (piVar3 == local_4f4)) goto LAB_0057606c;
                    piVar3 = (int *)0x87;
                    local_508 = 0x313;
                    (**(code **)(local_500 + -0x6eb0))(9,0x87,0x65,FUN_0066ce6c);
                  }
                }
              }
              goto LAB_0057603c;
            }
            (**(code **)(local_500 + -0x7d6c))(unaff_s8,0x14);
LAB_0057606c:
            local_4e4[0] = param_4;
            if (param_3 < 0x10) {
LAB_0057615c:
              piVar3 = (int *)&DAT_00000084;
              local_508 = 0xff;
              piVar5 = (int *)0x0;
              (**(code **)(local_500 + -0x6eb0))(9,0x84,0x7a,FUN_0066ce6c);
            }
            else {
              if (*(char *)param_4 == '\x06') {
                pcVar27 = *(code **)(local_500 + -0x6eb0);
                uVar19 = 0x77;
                local_508 = 0x98;
LAB_0057621c:
                local_4e4[0] = param_4;
                (*pcVar27)(9,0x86,uVar19,FUN_0066ce6c);
                goto LAB_0057615c;
              }
              if (*(char *)param_4 != '\a') goto LAB_0057615c;
              if (*(char *)((int)param_4 + 1) != '\x02') {
                pcVar27 = *(code **)(local_500 + -0x6eb0);
                uVar19 = 0x75;
                local_508 = 0xad;
                goto LAB_0057621c;
              }
              local_4e4[0] = param_4 + 4;
              uVar8 = (uint)*(byte *)((int)param_4 + 9) << 8 |
                      (uint)*(byte *)((int)param_4 + 10) << 0x10 | (uint)*(byte *)(param_4 + 2) |
                      (uint)*(byte *)((int)param_4 + 0xb) << 0x18;
              piVar3 = (int *)((uint)*(byte *)((int)param_4 + 0xd) << 8 |
                               (uint)*(byte *)((int)param_4 + 0xe) << 0x10 |
                               (uint)*(byte *)(param_4 + 3) |
                              (uint)*(byte *)((int)param_4 + 0xf) << 0x18);
              if (uVar8 == 0x31535344) {
LAB_0057620c:
                pcVar27 = *(code **)(local_500 + -0x6eb0);
                uVar19 = 0x77;
                local_508 = 0xbe;
                goto LAB_0057621c;
              }
              if (uVar8 < 0x31535345) {
                if (uVar8 != 0x31415352) {
LAB_00576498:
                  pcVar27 = *(code **)(local_500 + -0x6eb0);
                  uVar19 = 0x74;
                  local_508 = 0xcf;
                  goto LAB_0057621c;
                }
                goto LAB_0057620c;
              }
              if (uVar8 == 0x32415352) {
                param_3 = param_3 - 0x10;
                if (param_3 < (((uint)((int)piVar3 + 7) >> 3) + 2) * 2 +
                              ((uint)((int)piVar3 + 0xf) >> 4) * 5) {
LAB_005764d8:
                  local_508 = 0x105;
                  piVar3 = (int *)&DAT_00000084;
                  piVar5 = (int *)0x0;
                  (**(code **)(local_500 + -0x6eb0))(9,0x84,0x7b,FUN_0066ce6c);
                }
                else {
                  piVar5 = (int *)b2i_rsa_isra_1(local_4e4,piVar3,0);
                }
              }
              else {
                param_3 = param_3 - 0x10;
                if (uVar8 != 0x32535344) goto LAB_00576498;
                param_3 = (uint)(param_3 < (((uint)((int)piVar3 + 7) >> 3) + 0x20) * 2);
                if (param_3 != 0) goto LAB_005764d8;
                piVar5 = (int *)b2i_dss_isra_0(local_4e4,piVar3,0);
              }
            }
            (**(code **)(local_500 + -0x7380))(piStack_650);
            param_1 = piVar5;
            param_4 = piVar24;
            if ((piVar24 == (int *)0x0) || (pcVar27 = *(code **)(local_500 + -0x7f58), param_2 == 0)
               ) goto LAB_005761a4;
          }
          (*pcVar27)(piVar24);
          param_1 = piVar5;
          param_4 = piVar24;
          goto LAB_005761a4;
        }
      }
      (**(code **)(local_500 + -0x7fac))(param_5);
      piVar5 = (int *)0x0;
    }
  }
LAB_005761a4:
  piVar24 = (int *)0x670000;
  if (local_2c == *(char ***)pcVar23) {
    return piVar5;
  }
  pcStack_51c = b2i_PrivateKey;
  ppcVar15 = local_2c;
  (**(code **)(local_500 + -0x5328))();
  puStack_55c = PTR___stack_chk_guard_006aabf0;
  pcVar6 = *ppcVar15;
  puStack_538 = &_gp;
  ppcStack_52c = *(char ***)PTR___stack_chk_guard_006aabf0;
  pcStack_530 = pcVar6;
  piStack_524 = param_1;
  piStack_520 = param_4;
  if (piVar3 < &SUB_00000010) {
LAB_0057659c:
    param_4 = (int *)0x670000;
    uVar16 = 0x84;
    uStack_540 = 0xff;
    (**(code **)(puStack_538 + -0x6eb0))(9,0x84,0x7a,FUN_0066ce6c);
    piVar3 = (int *)0x0;
  }
  else {
    if (*pcVar6 == '\x06') {
      uVar19 = 0x77;
      uStack_540 = 0x98;
LAB_005766bc:
      pcStack_530 = pcVar6;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x86,uVar19,FUN_0066ce6c);
      goto LAB_0057659c;
    }
    if (*pcVar6 != '\a') goto LAB_0057659c;
    if (pcVar6[1] != '\x02') {
      uVar19 = 0x75;
      uStack_540 = 0xad;
      goto LAB_005766bc;
    }
    pcStack_530 = pcVar6 + 0x10;
    uVar8 = (uint)(byte)pcVar6[9] << 8 | (uint)(byte)pcVar6[10] << 0x10 | (uint)(byte)pcVar6[8] |
            (uint)(byte)pcVar6[0xb] << 0x18;
    uVar16 = (uint)(byte)pcVar6[0xd] << 8 | (uint)(byte)pcVar6[0xe] << 0x10 |
             (uint)(byte)pcVar6[0xc] | (uint)(byte)pcVar6[0xf] << 0x18;
    if (uVar8 == 0x31535344) {
LAB_00576730:
      uVar19 = 0x77;
      uStack_540 = 0xbe;
      goto LAB_005766bc;
    }
    if (uVar8 < 0x31535345) {
      if (uVar8 != 0x31415352) {
LAB_00576760:
        uVar19 = 0x74;
        uStack_540 = 0xcf;
        goto LAB_005766bc;
      }
      goto LAB_00576730;
    }
    if (uVar8 == 0x32415352) {
      if (piVar3 + -4 < (int *)(((uVar16 + 7 >> 3) + 2) * 2 + (uVar16 + 0xf >> 4) * 5)) {
LAB_00576778:
        uStack_540 = 0x105;
        uVar16 = 0x84;
        (*(code *)PTR_ERR_put_error_006a9030)(9,0x84,0x7b,FUN_0066ce6c);
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)b2i_rsa_isra_1(&pcStack_530,uVar16,0);
      }
    }
    else {
      if (uVar8 != 0x32535344) goto LAB_00576760;
      if (piVar3 + -4 < (int *)(((uVar16 + 7 >> 3) + 0x20) * 2)) goto LAB_00576778;
      piVar3 = (int *)b2i_dss_isra_0(&pcStack_530,uVar16,0);
    }
  }
  if (ppcStack_52c == *(char ***)puStack_55c) {
    return piVar3;
  }
  pcStack_554 = b2i_PublicKey;
  ppcVar15 = ppcStack_52c;
  (**(code **)(puStack_538 + -0x5328))();
  puStack_5a8 = PTR___stack_chk_guard_006aabf0;
  pcVar6 = *ppcVar15;
  puStack_570 = &_gp;
  iStack_564 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_568 = pcVar6;
  piStack_558 = param_4;
  if (uVar16 < 0x10) {
LAB_0057680c:
    param_4 = (int *)0x670000;
    uStack_578 = 0xff;
    (**(code **)(puStack_570 + -0x6eb0))(9,0x84,0x7a,FUN_0066ce6c);
    piVar3 = (int *)0x0;
  }
  else {
    if (*pcVar6 != '\x06') {
      if (*pcVar6 == '\a') {
        uVar19 = 0x78;
        uStack_578 = 0xa2;
        goto LAB_00576914;
      }
      goto LAB_0057680c;
    }
    if (pcVar6[1] != '\x02') {
      uVar19 = 0x75;
      uStack_578 = 0xad;
LAB_00576914:
      pcStack_568 = pcVar6;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x86,uVar19,FUN_0066ce6c);
      goto LAB_0057680c;
    }
    pcStack_568 = pcVar6 + 0x10;
    uVar8 = (uint)(byte)pcVar6[9] << 8 | (uint)(byte)pcVar6[10] << 0x10 | (uint)(byte)pcVar6[8] |
            (uint)(byte)pcVar6[0xb] << 0x18;
    uVar18 = (uint)(byte)pcVar6[0xd] << 8 | (uint)(byte)pcVar6[0xe] << 0x10 |
             (uint)(byte)pcVar6[0xc] | (uint)(byte)pcVar6[0xf] << 0x18;
    if (uVar8 != 0x31535344) {
      if (uVar8 < 0x31535345) {
        if (uVar8 == 0x31415352) {
          if (uVar16 - 0x10 < (uVar18 + 7 >> 3) + 4) goto LAB_005769d4;
          piVar3 = (int *)b2i_rsa_isra_1(&pcStack_568,uVar18,1);
          goto LAB_00576834;
        }
      }
      else if ((uVar8 == 0x32415352) || (uVar8 == 0x32535344)) {
        uVar19 = 0x78;
        uStack_578 = 0xc9;
        goto LAB_00576914;
      }
      uVar19 = 0x74;
      uStack_578 = 0xcf;
      goto LAB_00576914;
    }
    if (uVar16 - 0x10 < (uVar18 + 7 >> 3) * 3 + 0x2c) {
LAB_005769d4:
      uStack_578 = 0x105;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x84,0x7b,FUN_0066ce6c);
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)b2i_dss_isra_0(&pcStack_568,uVar18,1);
    }
  }
LAB_00576834:
  if (iStack_564 == *(int *)puStack_5a8) {
    return piVar3;
  }
  pcStack_58c = b2i_PrivateKey_bio;
  iStack_5f4 = iStack_564;
  (**(code **)(puStack_570 + -0x5328))();
  piVar3 = (int *)PTR___stack_chk_guard_006aabf0;
  piStack_600 = (int *)&cStack_5bc;
  puStack_5c8 = &_gp;
  puStack_590 = pcVar23;
  iStack_5ac = *(int *)PTR___stack_chk_guard_006aabf0;
  piStack_5a4 = param_4;
  uStack_5a0 = param_3;
  ppiStack_59c = param_5;
  piStack_598 = piStack_650;
  iStack_594 = param_2;
  iVar4 = (*(code *)PTR_BIO_read_006a85bc)();
  if (iVar4 == 0x10) {
    piStack_5c0 = piStack_600;
    if (cStack_5bc == '\x06') {
      pcVar27 = *(code **)(puStack_5c8 + -0x6eb0);
      uVar19 = 0x77;
      uStack_5d0 = 0x98;
LAB_00576c0c:
      (*pcVar27)(9,0x86,uVar19,FUN_0066ce6c);
    }
    else if (cStack_5bc == '\a') {
      if (cStack_5bb == '\x02') {
        uVar8 = (((uStack_5b4 >> 0x10) << 0x18 | (uStack_5b4 >> 0x18) << 0x10) >> 0x10) +
                ((uStack_5b4 & 0xff) << 8 | uStack_5b4 >> 8 & 0xff) * 0x10000;
        param_3 = (((uStack_5b0 >> 0x10) << 0x18 | (uStack_5b0 >> 0x18) << 0x10) >> 0x10) +
                  ((uStack_5b0 & 0xff) << 8 | uStack_5b0 >> 8 & 0xff) * 0x10000;
        if (uVar8 != 0x31535344) {
          if (0x31535344 < uVar8) {
            if (uVar8 == 0x32415352) {
              param_2 = 0;
              piStack_600 = (int *)(((param_3 + 7 >> 3) + 2) * 2 + (param_3 + 0xf >> 4) * 5);
            }
            else {
              param_2 = 1;
              if (uVar8 != 0x32535344) goto LAB_00576cd8;
              piStack_600 = (int *)(((param_3 + 7 >> 3) + 0x20) * 2);
            }
            piStack_5c0 = &iStack_5ac;
            pcVar23 = "7 datafinal";
            piStack_650 = (int *)(**(code **)(puStack_5c8 + -0x7dd8))
                                           (piStack_600,FUN_0066ce6c,0x11f);
            if (piStack_650 == (int *)0x0) {
              uStack_5d0 = 0x122;
              (**(code **)(puStack_5c8 + -0x6eb0))(9,0x85,0x41,FUN_0066ce6c);
              piVar5 = (int *)0x0;
            }
            else {
              piStack_5c0 = piStack_650;
              piVar5 = (int *)(**(code **)(puStack_5c8 + -0x7924))
                                        (iStack_5f4,piStack_650,piStack_600);
              if (piStack_600 == piVar5) {
                if (param_2 == 0) {
                  piVar5 = (int *)b2i_rsa_isra_1(&piStack_5c0,param_3,0);
                }
                else {
                  piVar5 = (int *)b2i_dss_isra_0();
                }
              }
              else {
                uStack_5d0 = 0x128;
                piVar5 = (int *)0x0;
                (**(code **)(puStack_5c8 + -0x6eb0))(9,0x85,0x7b,FUN_0066ce6c);
              }
              (**(code **)(puStack_5c8 + -0x7f58))(piStack_650);
              piStack_600 = piVar5;
            }
            goto LAB_00576a94;
          }
          if (uVar8 != 0x31415352) {
LAB_00576cd8:
            pcVar27 = *(code **)(puStack_5c8 + -0x6eb0);
            uVar19 = 0x74;
            uStack_5d0 = 0xcf;
            goto LAB_00576c0c;
          }
        }
        pcVar27 = *(code **)(puStack_5c8 + -0x6eb0);
        uVar19 = 0x77;
        uStack_5d0 = 0xbe;
      }
      else {
        pcVar27 = *(code **)(puStack_5c8 + -0x6eb0);
        uVar19 = 0x75;
        uStack_5d0 = 0xad;
      }
      goto LAB_00576c0c;
    }
    piVar5 = (int *)0x0;
  }
  else {
    uStack_5d0 = 0x117;
    (**(code **)(puStack_5c8 + -0x6eb0))(9,0x85,0x7b,FUN_0066ce6c);
    piVar5 = (int *)0x0;
  }
LAB_00576a94:
  if (iStack_5ac == *piVar3) {
    return piVar5;
  }
  pcStack_5e4 = b2i_PublicKey_bio;
  iStack_654 = iStack_5ac;
  (**(code **)(puStack_5c8 + -0x5328))();
  pcVar6 = PTR___stack_chk_guard_006aabf0;
  piVar17 = (int *)&SUB_00000010;
  piVar9 = (int *)&cStack_614;
  puStack_620 = &_gp;
  puStack_5fc = (undefined *)piVar3;
  iStack_604 = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar5 = piVar9;
  uStack_5f8 = param_3;
  piStack_5f0 = piStack_650;
  iStack_5ec = param_2;
  pcStack_5e8 = pcVar23;
  iVar4 = (*(code *)PTR_BIO_read_006a85bc)();
  if (iVar4 == 0x10) {
    piStack_618 = piVar9;
    if (cStack_614 == '\x06') {
      if (cStack_613 == '\x02') {
        uVar8 = (((uStack_60c >> 0x10) << 0x18 | (uStack_60c >> 0x18) << 0x10) >> 0x10) +
                ((uStack_60c & 0xff) << 8 | uStack_60c >> 8 & 0xff) * 0x10000;
        piStack_650 = (int *)((((uStack_608 >> 0x10) << 0x18 | (uStack_608 >> 0x18) << 0x10) >> 0x10
                              ) + ((uStack_608 & 0xff) << 8 | uStack_608 >> 8 & 0xff) * 0x10000);
        if (uVar8 == 0x31535344) {
          param_2 = 1;
          piVar9 = (int *)(((uint)((int)piStack_650 + 7) >> 3) * 3 + 0x2c);
LAB_00576e9c:
          piStack_618 = &iStack_604;
          pcVar23 = "7 datafinal";
          piVar3 = (int *)(**(code **)(puStack_620 + -0x7dd8))(piVar9,FUN_0066ce6c,0x11f);
          if (piVar3 == (int *)0x0) {
            piVar17 = (int *)&DAT_00000041;
            piVar5 = (int *)0x85;
            uStack_628 = 0x122;
            (**(code **)(puStack_620 + -0x6eb0))(9,0x85,0x41,FUN_0066ce6c);
            piVar7 = (int *)0x0;
          }
          else {
            piStack_618 = piVar3;
            piVar5 = (int *)(**(code **)(puStack_620 + -0x7924))(iStack_654,piVar3,piVar9);
            if (piVar9 == piVar5) {
              piVar17 = (int *)0x1;
              piVar5 = piStack_650;
              if (param_2 == 0) {
                piVar7 = (int *)b2i_rsa_isra_1(&piStack_618);
              }
              else {
                piVar7 = (int *)b2i_dss_isra_0();
              }
            }
            else {
              piVar17 = (int *)0x7b;
              piVar5 = (int *)0x85;
              uStack_628 = 0x128;
              piVar7 = (int *)0x0;
              (**(code **)(puStack_620 + -0x6eb0))(9,0x85,0x7b,FUN_0066ce6c);
            }
            (**(code **)(puStack_620 + -0x7f58))(piVar3);
            piVar9 = piVar7;
          }
          goto LAB_00576d94;
        }
        if (uVar8 < 0x31535345) {
          param_2 = 0;
          if (uVar8 == 0x31415352) {
            piVar9 = (int *)(((uint)((int)piStack_650 + 7) >> 3) + 4);
            goto LAB_00576e9c;
          }
        }
        else if ((uVar8 == 0x32415352) || (uVar8 == 0x32535344)) {
          pcVar27 = *(code **)(puStack_620 + -0x6eb0);
          piVar17 = (int *)&DAT_00000078;
          uStack_628 = 0xc9;
          goto LAB_00576e34;
        }
        pcVar27 = *(code **)(puStack_620 + -0x6eb0);
        piVar17 = (int *)&DAT_00000074;
        uStack_628 = 0xcf;
      }
      else {
        pcVar27 = *(code **)(puStack_620 + -0x6eb0);
        piVar17 = (int *)0x75;
        uStack_628 = 0xad;
      }
LAB_00576e34:
      piVar5 = (int *)0x86;
      (*pcVar27)(9,0x86,piVar17,FUN_0066ce6c);
    }
    else if (cStack_614 == '\a') {
      pcVar27 = *(code **)(puStack_620 + -0x6eb0);
      piVar17 = (int *)&DAT_00000078;
      uStack_628 = 0xa2;
      goto LAB_00576e34;
    }
    piVar7 = (int *)0x0;
  }
  else {
    piVar17 = (int *)0x7b;
    uStack_628 = 0x117;
    piVar5 = (int *)0x85;
    (**(code **)(puStack_620 + -0x6eb0))(9,0x85,0x7b,FUN_0066ce6c);
    piVar7 = (int *)0x0;
  }
LAB_00576d94:
  if (iStack_604 == *(int *)pcVar6) {
    return piVar7;
  }
  pcStack_63c = i2b_PrivateKey_bio;
  iVar4 = iStack_604;
  (**(code **)(puStack_620 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  pcStack_644 = "7 datafinal";
  puStack_658 = pcVar6;
  iStack_668 = 0;
  iStack_664 = *(int *)PTR___stack_chk_guard_006aabf0;
  piStack_660 = piVar9;
  piStack_65c = piVar3;
  iStack_64c = param_2;
  pcStack_648 = pcVar23;
  piStack_640 = unaff_s8;
  if (*piVar5 == 0x74) {
    piVar9 = (int *)piVar5[5];
    pcVar6 = (char *)(*(code *)PTR_BN_num_bits_006a82f4)(piVar9[3]);
    if ((((((uint)pcVar6 & 7) != 0) ||
         (iVar22 = (*(code *)PTR_BN_num_bits_006a82f4)(piVar9[4]), iVar22 != 0xa0)) ||
        (iVar22 = (*(code *)PTR_BN_num_bits_006a82f4)(piVar9[5]), (int)pcVar6 < iVar22)) ||
       (iVar22 = (*(code *)PTR_BN_num_bits_006a82f4)(piVar9[7]), 0xa0 < iVar22)) {
      piVar17 = (int *)0x7e;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x82,0x7e,FUN_0066ce6c,0x23c);
      goto LAB_0057782c;
    }
    iStack_668 = 0x32535344;
    if (pcVar6 == (char *)0x0) goto LAB_0057782c;
    piVar24 = (int *)0x22;
    pcVar23 = (char *)0x2200;
    iVar22 = (((uint)(pcVar6 + 7) >> 3) + 0x20) * 2;
  }
  else {
    piVar7 = (int *)0xffffffff;
    if (*piVar5 != 6) goto LAB_00577790;
    piVar17 = &iStack_668;
    pcVar6 = (char *)check_bitlen_rsa(piVar5[5],0);
    if (pcVar6 == (char *)0x0) goto LAB_0057782c;
    piVar24 = (int *)&DAT_000000a4;
    iVar22 = (((uint)(pcVar6 + 7) >> 3) + 2) * 2 + ((uint)(pcVar6 + 0xf) >> 4) * 5;
    pcVar23 = (char *)0xa400;
  }
  piVar7 = (int *)(iVar22 + 0x10);
  piVar17 = (int *)0x1ff;
  piVar9 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(piVar7,FUN_0066ce6c);
  piVar3 = piVar7;
  if (piVar9 == (int *)0x0) goto LAB_0057782c;
  *(char *)((int)piVar9 + 2) = '\0';
  *(char *)((int)piVar9 + 3) = '\0';
  *(char *)(piVar9 + 1) = '\0';
  *(char *)((int)piVar9 + 5) = (char)piVar24;
  *(char *)((int)piVar9 + 6) = '\0';
  *(char *)piVar9 = '\a';
  piVar24 = piVar9 + 4;
  *(char *)((int)piVar9 + 7) = '\0';
  *(char *)(piVar9 + 3) = (char)pcVar6;
  *(char *)((int)piVar9 + 1) = '\x02';
  *(char *)((int)piVar9 + 0xd) = (char)((uint)pcVar6 >> 8);
  *(char *)((int)piVar9 + 0xe) = (char)((uint)pcVar6 >> 0x10);
  *(char *)((int)piVar9 + 0xf) = (char)((uint)pcVar6 >> 0x18);
  *(char *)(piVar9 + 2) = (char)iStack_668;
  *(char *)((int)piVar9 + 9) = (char)((uint)iStack_668 >> 8);
  *(char *)((int)piVar9 + 10) = (char)((uint)iStack_668 >> 0x10);
  *(char *)((int)piVar9 + 0xb) = (char)((uint)iStack_668 >> 0x18);
  if (pcVar23 == (char *)0x2200) {
    iVar20 = piVar5[5];
    iVar10 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(iVar20 + 0xc));
    uVar19 = *(undefined4 *)(iVar20 + 0xc);
    iVar22 = iVar10 + 7;
    if (iVar10 + 7 < 0) {
      iVar22 = iVar10 + 0xe;
    }
    iVar22 = iVar22 >> 3;
    iVar13 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
    iVar21 = iVar13 + 7;
    iVar10 = iVar13 + 0xe;
    if (-1 < iVar21) {
      iVar10 = iVar21;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,piVar24);
    iVar10 = iVar10 >> 3;
    iVar13 = iVar13 + 0x16;
    if (-1 < iVar21) {
      iVar13 = iVar21;
    }
    if (0 < iVar13 >> 4) {
      piVar3 = piVar24;
      pcVar23 = (char *)((int)piVar24 + iVar10 + -1);
      do {
        cVar1 = *(char *)piVar3;
        piVar5 = (int *)((int)piVar3 + 1);
        *(char *)piVar3 = *pcVar23;
        *pcVar23 = cVar1;
        piVar3 = piVar5;
        pcVar23 = pcVar23 + -1;
      } while ((int *)((int)piVar24 + (iVar13 >> 4)) != piVar5);
    }
    pcVar6 = (char *)((int)piVar24 + iVar10);
    pcVar23 = pcVar6;
    if ((0 < iVar22) && (0 < iVar22 - iVar10)) {
      pcVar23 = pcVar6 + (iVar22 - iVar10);
      (*(code *)PTR_memset_006aab00)(pcVar6,0);
    }
    uVar19 = *(undefined4 *)(iVar20 + 0x10);
    iVar13 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
    iVar21 = iVar13 + 7;
    iVar10 = iVar13 + 0xe;
    if (-1 < iVar21) {
      iVar10 = iVar21;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,pcVar23);
    iVar10 = iVar10 >> 3;
    iVar13 = iVar13 + 0x16;
    if (-1 < iVar21) {
      iVar13 = iVar21;
    }
    if (0 < iVar13 >> 4) {
      pcVar6 = pcVar23;
      pcVar26 = pcVar23 + iVar10 + -1;
      do {
        cVar1 = *pcVar6;
        pcVar25 = pcVar6 + 1;
        *pcVar6 = *pcVar26;
        *pcVar26 = cVar1;
        pcVar6 = pcVar25;
        pcVar26 = pcVar26 + -1;
      } while (pcVar23 + (iVar13 >> 4) != pcVar25);
    }
    pcVar23 = pcVar23 + iVar10;
    pcVar6 = pcVar23;
    if (0 < 0x14 - iVar10) {
      pcVar6 = pcVar23 + (0x14 - iVar10);
      (*(code *)PTR_memset_006aab00)(pcVar23,0);
    }
    uVar19 = *(undefined4 *)(iVar20 + 0x14);
    iVar21 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
    iVar13 = iVar21 + 7;
    iVar10 = iVar21 + 0xe;
    if (-1 < iVar13) {
      iVar10 = iVar13;
    }
    iVar10 = iVar10 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,pcVar6);
    if (-1 >= iVar13) {
      iVar13 = iVar21 + 0x16;
    }
    if (0 < iVar13 >> 4) {
      pcVar23 = pcVar6;
      pcVar26 = pcVar6 + iVar10 + -1;
      do {
        cVar1 = *pcVar23;
        pcVar25 = pcVar23 + 1;
        *pcVar23 = *pcVar26;
        *pcVar26 = cVar1;
        pcVar23 = pcVar25;
        pcVar26 = pcVar26 + -1;
      } while (pcVar25 != pcVar6 + (iVar13 >> 4));
    }
    piVar3 = (int *)(pcVar6 + iVar10);
    piVar24 = piVar3;
    if ((0 < iVar22) && (0 < iVar22 - iVar10)) {
      piVar24 = (int *)((int)piVar3 + (iVar22 - iVar10));
      (*(code *)PTR_memset_006aab00)(piVar3,0);
    }
    uVar19 = *(undefined4 *)(iVar20 + 0x1c);
    iVar22 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
    pcVar6 = (char *)(iVar22 + 7);
    pcVar26 = (char *)(iVar22 + 0xe);
    if (-1 < (int)pcVar6) {
      pcVar26 = pcVar6;
    }
    pcVar23 = (char *)(iVar22 + 0x16);
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,piVar24);
    if (-1 >= (int)pcVar6) {
      pcVar6 = pcVar23;
    }
    piVar5 = (int *)((int)pcVar26 >> 3);
    if (0 < (int)pcVar6 >> 4) {
      piVar3 = piVar24;
      pcVar26 = (char *)((int)piVar24 + (int)((int)piVar5 + -1));
      do {
        cVar1 = *(char *)piVar3;
        piVar17 = (int *)((int)piVar3 + 1);
        *(char *)piVar3 = *pcVar26;
        *pcVar26 = cVar1;
        piVar3 = piVar17;
        pcVar26 = pcVar26 + -1;
      } while (piVar17 != (int *)((int)piVar24 + ((int)pcVar6 >> 4)));
    }
    pcVar26 = (char *)((int)piVar24 + (int)piVar5);
    pcVar6 = pcVar26;
    if (0 < 0x14 - (int)piVar5) {
      pcVar6 = pcVar26 + (0x14 - (int)piVar5);
      (*(code *)PTR_memset_006aab00)(pcVar26,0);
    }
    piVar17 = (int *)&DAT_00000018;
    (*(code *)PTR_memset_006aab00)(pcVar6,0xff);
    piVar14 = piVar9;
    goto LAB_00577758;
  }
  pcVar23 = (char *)piVar5[5];
  iVar10 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(pcVar23 + 0x10));
  iVar22 = iVar10 + 7;
  if (iVar10 + 7 < 0) {
    iVar22 = iVar10 + 0xe;
  }
  piVar5 = (int *)(iVar22 >> 3);
  iVar22 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(pcVar23 + 0x10));
  uVar19 = *(undefined4 *)(pcVar23 + 0x14);
  pcVar6 = (char *)(iVar22 + 0xf >> 4);
  iVar10 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
  iVar20 = iVar10 + 7;
  iVar22 = iVar10 + 0xe;
  if (-1 < iVar20) {
    iVar22 = iVar20;
  }
  iVar22 = iVar22 >> 3;
  (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,piVar24);
  iVar10 = iVar10 + 0x16;
  if (-1 < iVar20) {
    iVar10 = iVar20;
  }
  if (0 < iVar10 >> 4) {
    piVar3 = piVar24;
    pcVar26 = (char *)((int)piVar24 + iVar22 + -1);
    do {
      cVar1 = *(char *)piVar3;
      piVar17 = (int *)((int)piVar3 + 1);
      *(char *)piVar3 = *pcVar26;
      *pcVar26 = cVar1;
      piVar3 = piVar17;
      pcVar26 = pcVar26 + -1;
    } while ((int *)((int)piVar24 + (iVar10 >> 4)) != piVar17);
  }
  pcVar25 = (char *)((int)piVar24 + iVar22);
  pcVar26 = pcVar25;
  if (0 < 4 - iVar22) {
    pcVar26 = pcVar25 + (4 - iVar22);
    (*(code *)PTR_memset_006aab00)(pcVar25,0);
  }
  uVar19 = *(undefined4 *)(pcVar23 + 0x10);
  iVar20 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
  iVar10 = iVar20 + 7;
  (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,pcVar26);
  iVar22 = iVar10;
  if (iVar10 < 0) {
    iVar10 = iVar20 + 0x16;
    iVar22 = iVar20 + 0xe;
  }
  if (0 < iVar10 >> 4) {
    pcVar25 = pcVar26;
    pcVar12 = pcVar26 + (iVar22 >> 3) + -1;
    do {
      cVar1 = *pcVar25;
      pcVar11 = pcVar25 + 1;
      *pcVar25 = *pcVar12;
      *pcVar12 = cVar1;
      pcVar25 = pcVar11;
      pcVar12 = pcVar12 + -1;
    } while (pcVar11 != pcVar26 + (iVar10 >> 4));
  }
  uVar19 = *(undefined4 *)(pcVar23 + 0x1c);
  pcVar26 = pcVar26 + (iVar22 >> 3);
  iVar10 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
  iVar20 = iVar10 + 7;
  iVar22 = iVar10 + 0xe;
  if (-1 < iVar20) {
    iVar22 = iVar20;
  }
  iVar22 = iVar22 >> 3;
  (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,pcVar26);
  iVar10 = iVar10 + 0x16;
  if (-1 < iVar20) {
    iVar10 = iVar20;
  }
  if (0 < iVar10 >> 4) {
    pcVar25 = pcVar26;
    pcVar12 = pcVar26 + iVar22 + -1;
    do {
      cVar1 = *pcVar25;
      pcVar11 = pcVar25 + 1;
      *pcVar25 = *pcVar12;
      *pcVar12 = cVar1;
      pcVar25 = pcVar11;
      pcVar12 = pcVar12 + -1;
    } while (pcVar26 + (iVar10 >> 4) != pcVar11);
  }
  pcVar26 = pcVar26 + iVar22;
  if ((int)pcVar6 < 1) {
    uVar19 = *(undefined4 *)(pcVar23 + 0x20);
    iVar10 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
    iVar20 = iVar10 + 7;
    iVar22 = iVar10 + 0xe;
    if (-1 < iVar20) {
      iVar22 = iVar20;
    }
    iVar22 = iVar22 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,pcVar26);
    iVar10 = iVar10 + 0x16;
    if (-1 < iVar20) {
      iVar10 = iVar20;
    }
    iVar10 = iVar10 >> 4;
    pcVar25 = pcVar26 + iVar22 + -1;
    if (0 < iVar10) goto LAB_0057740c;
    pcVar26 = pcVar26 + iVar22;
LAB_00577bcc:
    uVar19 = *(undefined4 *)(pcVar23 + 0x24);
    iVar10 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
    iVar20 = iVar10 + 7;
    iVar22 = iVar10 + 0xe;
    if (-1 < iVar20) {
      iVar22 = iVar20;
    }
    iVar22 = iVar22 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,pcVar26);
    iVar10 = iVar10 + 0x16;
    if (-1 < iVar20) {
      iVar10 = iVar20;
    }
    iVar10 = iVar10 >> 4;
    pcVar25 = pcVar26 + iVar22 + -1;
    if (0 < iVar10) goto LAB_005774d0;
    pcVar26 = pcVar26 + iVar22;
LAB_00577c44:
    uVar19 = *(undefined4 *)(pcVar23 + 0x28);
    iVar20 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
    iVar22 = iVar20 + 7;
    iVar10 = iVar20 + 0xe;
    if (-1 < iVar22) {
      iVar10 = iVar22;
    }
    iVar10 = iVar10 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,pcVar26);
    if (-1 >= iVar22) {
      iVar22 = iVar20 + 0x16;
    }
    iVar22 = iVar22 >> 4;
    pcVar25 = pcVar26 + iVar10 + -1;
    if (0 < iVar22) goto LAB_00577594;
LAB_005775b8:
    piVar24 = (int *)(pcVar26 + iVar10);
    if ((int)pcVar6 < 1) {
      uVar19 = *(undefined4 *)(pcVar23 + 0x2c);
      iVar20 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
      iVar10 = iVar20 + 7;
      iVar22 = iVar20 + 0xe;
      if (-1 < iVar10) {
        iVar22 = iVar10;
      }
      piVar17 = (int *)(iVar22 >> 3);
      (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,piVar24);
      if (-1 >= iVar10) {
        iVar10 = iVar20 + 0x16;
      }
      iVar10 = iVar10 >> 4;
      pcVar26 = (char *)((int)piVar24 + (int)((int)piVar17 + -1));
      if (iVar10 < 1) {
        piVar24 = (int *)((int)piVar24 + (int)piVar17);
        goto LAB_005776a4;
      }
      goto LAB_00577658;
    }
  }
  else {
    iVar22 = (int)pcVar6 - iVar22;
    if (0 < iVar22) {
      (*(code *)PTR_memset_006aab00)(pcVar26,0,iVar22);
      pcVar26 = pcVar26 + iVar22;
    }
    uVar19 = *(undefined4 *)(pcVar23 + 0x20);
    iVar10 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
    iVar20 = iVar10 + 7;
    iVar22 = iVar10 + 0xe;
    if (-1 < iVar20) {
      iVar22 = iVar20;
    }
    iVar22 = iVar22 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,pcVar26);
    iVar10 = iVar10 + 0x16;
    if (-1 < iVar20) {
      iVar10 = iVar20;
    }
    iVar10 = iVar10 >> 4;
    pcVar25 = pcVar26 + iVar22 + -1;
    if (iVar10 < 1) {
      pcVar26 = pcVar26 + iVar22;
    }
    else {
LAB_0057740c:
      pcVar12 = pcVar26;
      do {
        cVar1 = *pcVar12;
        pcVar11 = pcVar12 + 1;
        *pcVar12 = *pcVar25;
        *pcVar25 = cVar1;
        pcVar12 = pcVar11;
        pcVar25 = pcVar25 + -1;
      } while (pcVar26 + iVar10 != pcVar11);
      pcVar26 = pcVar26 + iVar22;
      if ((int)pcVar6 < 1) goto LAB_00577bcc;
    }
    iVar22 = (int)pcVar6 - iVar22;
    if (0 < iVar22) {
      (*(code *)PTR_memset_006aab00)(pcVar26,0,iVar22);
      pcVar26 = pcVar26 + iVar22;
    }
    uVar19 = *(undefined4 *)(pcVar23 + 0x24);
    iVar10 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
    iVar20 = iVar10 + 7;
    iVar22 = iVar10 + 0xe;
    if (-1 < iVar20) {
      iVar22 = iVar20;
    }
    iVar22 = iVar22 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,pcVar26);
    iVar10 = iVar10 + 0x16;
    if (-1 < iVar20) {
      iVar10 = iVar20;
    }
    iVar10 = iVar10 >> 4;
    pcVar25 = pcVar26 + iVar22 + -1;
    if (iVar10 < 1) {
      pcVar26 = pcVar26 + iVar22;
    }
    else {
LAB_005774d0:
      pcVar12 = pcVar26;
      do {
        cVar1 = *pcVar12;
        pcVar11 = pcVar12 + 1;
        *pcVar12 = *pcVar25;
        *pcVar25 = cVar1;
        pcVar12 = pcVar11;
        pcVar25 = pcVar25 + -1;
      } while (pcVar26 + iVar10 != pcVar11);
      pcVar26 = pcVar26 + iVar22;
      if ((int)pcVar6 < 1) goto LAB_00577c44;
    }
    iVar22 = (int)pcVar6 - iVar22;
    if (0 < iVar22) {
      (*(code *)PTR_memset_006aab00)(pcVar26,0,iVar22);
      pcVar26 = pcVar26 + iVar22;
    }
    uVar19 = *(undefined4 *)(pcVar23 + 0x28);
    iVar20 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
    iVar22 = iVar20 + 7;
    iVar10 = iVar20 + 0xe;
    if (-1 < iVar22) {
      iVar10 = iVar22;
    }
    iVar10 = iVar10 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,pcVar26);
    if (-1 >= iVar22) {
      iVar22 = iVar20 + 0x16;
    }
    iVar22 = iVar22 >> 4;
    pcVar25 = pcVar26 + iVar10 + -1;
    if (0 < iVar22) {
LAB_00577594:
      pcVar12 = pcVar26;
      do {
        cVar1 = *pcVar12;
        pcVar11 = pcVar12 + 1;
        *pcVar12 = *pcVar25;
        *pcVar25 = cVar1;
        pcVar25 = pcVar25 + -1;
        pcVar12 = pcVar11;
      } while (pcVar26 + iVar22 != pcVar11);
      goto LAB_005775b8;
    }
    piVar24 = (int *)(pcVar26 + iVar10);
  }
  iVar10 = (int)pcVar6 - iVar10;
  if (0 < iVar10) {
    (*(code *)PTR_memset_006aab00)(piVar24,0,iVar10);
    piVar24 = (int *)((int)piVar24 + iVar10);
  }
  uVar19 = *(undefined4 *)(pcVar23 + 0x2c);
  iVar20 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
  iVar10 = iVar20 + 7;
  iVar22 = iVar20 + 0xe;
  if (-1 < iVar10) {
    iVar22 = iVar10;
  }
  piVar17 = (int *)(iVar22 >> 3);
  (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,piVar24);
  if (-1 >= iVar10) {
    iVar10 = iVar20 + 0x16;
  }
  iVar10 = iVar10 >> 4;
  pcVar26 = (char *)((int)piVar24 + (int)((int)piVar17 + -1));
  if (iVar10 < 1) goto LAB_00577dbc;
LAB_00577658:
  piVar3 = piVar24;
  do {
    cVar1 = *(char *)piVar3;
    piVar14 = (int *)((int)piVar3 + 1);
    *(char *)piVar3 = *pcVar26;
    *pcVar26 = cVar1;
    pcVar26 = pcVar26 + -1;
    piVar3 = piVar14;
  } while ((int *)((int)piVar24 + iVar10) != piVar14);
  piVar3 = (int *)((int)piVar24 + (int)piVar17);
  piVar24 = piVar3;
  if ((int)pcVar6 < 1) goto LAB_005776a4;
  do {
    piVar24 = piVar3;
    if (0 < (int)pcVar6 - (int)piVar17) {
      piVar24 = (int *)((int)piVar3 + ((int)pcVar6 - (int)piVar17));
      (*(code *)PTR_memset_006aab00)(piVar3,0);
    }
LAB_005776a4:
    uVar19 = *(undefined4 *)(pcVar23 + 0x18);
    iVar20 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar19);
    iVar22 = iVar20 + 7;
    pcVar6 = (char *)(uint)(iVar22 < 0);
    iVar10 = iVar20 + 0xe;
    if (pcVar6 == (char *)0x0) {
      iVar10 = iVar22;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar19,piVar24);
    pcVar23 = (char *)(iVar10 >> 3);
    if (pcVar6 != (char *)0x0) {
      iVar22 = iVar20 + 0x16;
    }
    piVar17 = (int *)(iVar22 >> 4);
    if (0 < (int)piVar17) {
      piVar17 = (int *)((int)piVar24 + (int)piVar17);
      pcVar26 = (char *)((int)piVar24 + (int)(pcVar23 + -1));
      piVar3 = piVar24;
      do {
        cVar1 = *(char *)piVar3;
        piVar14 = (int *)((int)piVar3 + 1);
        *(char *)piVar3 = *pcVar26;
        *pcVar26 = cVar1;
        pcVar26 = pcVar26 + -1;
        piVar3 = piVar14;
      } while (piVar17 != piVar14);
    }
    piVar14 = piVar9;
    if ((0 < (int)piVar5) && (piVar17 = (int *)((int)piVar5 - (int)pcVar23), 0 < (int)piVar17)) {
      (*(code *)PTR_memset_006aab00)((char *)((int)piVar24 + (int)pcVar23),0);
    }
LAB_00577758:
    piVar9 = piVar14;
    piVar3 = piVar7;
    if ((int)piVar7 < 0) {
LAB_0057782c:
      piVar7 = (int *)0xffffffff;
    }
    else {
      piVar17 = piVar7;
      piVar9 = (int *)(*(code *)PTR_BIO_write_006a7f14)(iVar4,piVar14);
      (*(code *)PTR_CRYPTO_free_006a7f88)(piVar14);
      if (piVar9 != piVar7) goto LAB_0057782c;
    }
LAB_00577790:
    if (iStack_664 == *(int *)puVar2) {
      return piVar7;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    piVar7 = piVar3;
LAB_00577dbc:
    piVar3 = (int *)((int)piVar24 + (int)piVar17);
  } while( true );
}

