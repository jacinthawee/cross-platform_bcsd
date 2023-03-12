
ushort * ssl3_get_certificate_request(int *param_1)

{
  bool bVar1;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  ushort *puVar8;
  int iVar9;
  undefined4 uVar10;
  byte *pbVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  char *pcVar15;
  undefined4 uVar16;
  undefined *puVar17;
  undefined4 uVar18;
  undefined *puVar19;
  undefined *puVar20;
  uint unaff_s3;
  ushort *unaff_s4;
  ushort *unaff_s5;
  ushort *puVar21;
  ushort *unaff_s6;
  ushort *unaff_s7;
  int *piVar22;
  code *pcVar23;
  ushort **unaff_s8;
  undefined uVar24;
  uint uStack_3f0;
  undefined auStack_3ec [4];
  undefined auStack_3e8 [32];
  ushort auStack_3c8 [64];
  undefined uStack_348;
  undefined uStack_347;
  byte abStack_346 [514];
  int iStack_144;
  undefined *puStack_140;
  int iStack_13c;
  undefined *puStack_138;
  char *pcStack_134;
  ushort *puStack_130;
  ushort *puStack_12c;
  ushort *puStack_128;
  ushort *puStack_124;
  ushort **ppuStack_120;
  code *pcStack_11c;
  undefined4 uStack_108;
  int *piStack_104;
  undefined *puStack_100;
  int iStack_f8;
  int *piStack_f4;
  uint uStack_ec;
  int iStack_e8;
  code *pcStack_e4;
  undefined4 uStack_d0;
  int *piStack_cc;
  undefined *puStack_c8;
  int iStack_c0;
  int iStack_bc;
  uint uStack_b4;
  int *piStack_b0;
  undefined *puStack_ac;
  undefined *puStack_a8;
  code *pcStack_a4;
  undefined4 uStack_90;
  int *piStack_8c;
  undefined *puStack_88;
  int iStack_80;
  int iStack_7c;
  ushort *puStack_74;
  int *piStack_70;
  undefined *puStack_6c;
  uint uStack_68;
  ushort *puStack_64;
  ushort *puStack_60;
  code *pcStack_5c;
  int local_48;
  int *local_44;
  undefined *local_40;
  int local_34;
  ushort *local_30;
  uint local_2c;
  
  puStack_ac = PTR___stack_chk_guard_006aabf0;
  local_48 = param_1[0x42];
  local_44 = &local_34;
  local_40 = &_gp;
  local_2c = *(uint *)PTR___stack_chk_guard_006aabf0;
  puStack_74 = (ushort *)(**(code **)(param_1[2] + 0x30))(param_1,0x1150,0x1151,0xffffffff);
  puVar6 = puStack_74;
  if (local_34 != 0) {
    iVar5 = param_1[0x16];
    *(undefined4 *)(iVar5 + 0x358) = 0;
    if (*(int *)(iVar5 + 0x340) == 0xe) {
      *(undefined4 *)(iVar5 + 0x354) = 1;
      if ((*(int *)(iVar5 + 0x178) == 0) ||
         (iVar5 = ssl3_digest_cached_records(param_1), iVar5 != 0)) {
        puVar6 = (ushort *)0x1;
        goto LAB_00485e34;
      }
    }
    else {
      if (*(int *)(iVar5 + 0x340) == 0xd) {
        if ((*param_1 < 0x301) || ((*(uint *)(*(int *)(iVar5 + 0x344) + 0x10) & 4) == 0)) {
          unaff_s6 = (ushort *)param_1[0x10];
          unaff_s5 = (ushort *)(**(code **)(local_40 + -0x6d2c))(ca_dn_cmp);
          if (unaff_s5 != (ushort *)0x0) {
            unaff_s3 = (uint)*(byte *)unaff_s6;
            if (9 < unaff_s3) {
              unaff_s3 = 9;
            }
            if ((((unaff_s3 != 0) &&
                 (*(byte *)(param_1[0x16] + 0x360) = *(byte *)((int)unaff_s6 + 1), unaff_s3 != 1))
                && (*(byte *)(param_1[0x16] + 0x361) = *(byte *)(unaff_s6 + 1), unaff_s3 != 2)) &&
               ((((*(byte *)(param_1[0x16] + 0x362) = *(byte *)((int)unaff_s6 + 3), unaff_s3 != 3 &&
                  (*(byte *)(param_1[0x16] + 0x363) = *(byte *)(unaff_s6 + 2), unaff_s3 != 4)) &&
                 ((*(byte *)(param_1[0x16] + 0x364) = *(byte *)((int)unaff_s6 + 5), unaff_s3 != 5 &&
                  ((*(byte *)(param_1[0x16] + 0x365) = *(byte *)(unaff_s6 + 3), unaff_s3 != 6 &&
                   (*(byte *)(param_1[0x16] + 0x366) = *(byte *)((int)unaff_s6 + 7), unaff_s3 != 7))
                  )))) && (*(byte *)(param_1[0x16] + 0x367) = *(byte *)(unaff_s6 + 4), unaff_s3 == 9
                          )))) {
              *(byte *)(param_1[0x16] + 0x368) = *(byte *)((int)unaff_s6 + 9);
            }
            puVar6 = (ushort *)((int)unaff_s6 + unaff_s3 + 1);
            if ((*param_1 >> 8 == 3) && (unaff_s7 = puVar6 + 1, 0x302 < *param_1)) {
              unaff_s4 = (ushort *)(uint)*puVar6;
              if (puStack_74 <
                  (ushort *)((int)unaff_s4 + (int)((int)unaff_s7 + (2 - (int)unaff_s6)))) {
                ssl3_send_alert(param_1,2,0x32);
                uVar16 = 0x92;
                local_48 = 0x78f;
                pcVar23 = *(code **)(local_40 + -0x6eb0);
              }
              else {
                if (((*puVar6 & 1) == 0) &&
                   (iVar5 = tls1_process_sigalgs(param_1,unaff_s7,unaff_s4), iVar5 != 0)) {
                  puVar6 = (ushort *)((int)unaff_s7 + (int)unaff_s4);
                  goto LAB_00485f88;
                }
                ssl3_send_alert(param_1,2,0x32);
                uVar16 = 0x168;
                local_48 = 0x795;
                pcVar23 = *(code **)(local_40 + -0x6eb0);
              }
            }
            else {
LAB_00485f88:
              unaff_s4 = (ushort *)(uint)*puVar6;
              unaff_s6 = (ushort *)((byte *)((int)puVar6 + (2 - (int)unaff_s6)) + (int)unaff_s4);
              if (puStack_74 == unaff_s6) {
                if (unaff_s4 != (ushort *)0x0) {
                  unaff_s7 = puVar6 + 2;
                  puStack_74 = (ushort *)(uint)puVar6[1];
                  unaff_s6 = puStack_74 + 1;
                  unaff_s8 = &local_30;
                  if (unaff_s4 < unaff_s6) {
                    iVar5 = param_1[0x40];
                  }
                  else {
                    do {
                      local_30 = unaff_s7;
                      iVar5 = (**(code **)(local_40 + -0x6d28))(0,unaff_s8,puStack_74);
                      if (iVar5 == 0) {
                        if (param_1[0x40] << 2 < 0) goto LAB_004860ec;
                        ssl3_send_alert(param_1,2,0x32);
                        uVar16 = 0xd;
                        local_48 = 0x7c3;
                        pcVar23 = *(code **)(local_40 + -0x6eb0);
                        goto LAB_00485fd4;
                      }
                      puStack_74 = (ushort *)((int)unaff_s7 + (int)puStack_74);
                      if (puStack_74 != local_30) {
                        ssl3_send_alert(param_1,2,0x32);
                        uVar16 = 0x83;
                        local_48 = 0x7cb;
                        pcVar23 = *(code **)(local_40 + -0x6eb0);
                        goto LAB_00485fd4;
                      }
                      iVar5 = (**(code **)(local_40 + -0x7e38))(unaff_s5,iVar5);
                      if (iVar5 == 0) {
                        pcVar23 = *(code **)(local_40 + -0x6eb0);
                        uVar16 = 0x41;
                        local_48 = 2000;
                        goto LAB_00485fd4;
                      }
                      if (unaff_s4 <= unaff_s6) goto LAB_004860fc;
                      unaff_s7 = puStack_74 + 1;
                      puStack_74 = (ushort *)(uint)*puStack_74;
                      unaff_s6 = (ushort *)((int)unaff_s6 + (int)(puStack_74 + 1));
                    } while (unaff_s6 <= unaff_s4);
                    iVar5 = param_1[0x40];
                  }
                  if (-1 < iVar5 << 2) {
                    ssl3_send_alert(param_1,2,0x32);
                    uVar16 = 0x84;
                    local_48 = 0x7b5;
                    pcVar23 = *(code **)(local_40 + -0x6eb0);
                    goto LAB_00485fd4;
                  }
LAB_004860ec:
                  (**(code **)(local_40 + -0x7f00))();
                }
LAB_004860fc:
                iVar5 = param_1[0x16];
                *(uint *)(iVar5 + 0x35c) = unaff_s3;
                *(undefined4 *)(iVar5 + 0x358) = 1;
                if (*(int *)(iVar5 + 0x36c) != 0) {
                  (**(code **)(local_40 + -0x7d88))
                            (*(int *)(iVar5 + 0x36c),*(undefined4 *)(local_40 + -0x7de8));
                  iVar5 = param_1[0x16];
                }
                *(ushort **)(iVar5 + 0x36c) = unaff_s5;
                puVar6 = (ushort *)0x1;
                goto LAB_00485e34;
              }
              ssl3_send_alert(param_1,2,0x32);
              uVar16 = 0x9f;
              local_48 = 0x7a9;
              pcVar23 = *(code **)(local_40 + -0x6eb0);
            }
LAB_00485fd4:
            (*pcVar23)(0x14,0x87,uVar16,"s3_clnt.c");
            (**(code **)(local_40 + -0x7d88))(unaff_s5,*(undefined4 *)(local_40 + -0x7de8));
            puVar6 = (ushort *)0x0;
            goto LAB_00485e34;
          }
          pcVar23 = *(code **)(local_40 + -0x6eb0);
          uVar16 = 0x41;
          local_48 = 0x77b;
        }
        else {
          ssl3_send_alert(param_1,2,10);
          uVar16 = 0xe8;
          local_48 = 0x772;
          pcVar23 = *(code **)(local_40 + -0x6eb0);
        }
      }
      else {
        ssl3_send_alert(param_1,2,10);
        uVar16 = 0x106;
        local_48 = 0x768;
        pcVar23 = *(code **)(local_40 + -0x6eb0);
      }
      (*pcVar23)(0x14,0x87,uVar16,"s3_clnt.c");
    }
    puVar6 = (ushort *)0x0;
  }
LAB_00485e34:
  if (local_2c == *(uint *)puStack_ac) {
    return puVar6;
  }
  pcStack_5c = ssl3_get_new_session_ticket;
  uStack_ec = local_2c;
  (**(code **)(local_40 + -0x5328))();
  pcStack_134 = PTR___stack_chk_guard_006aabf0;
  piStack_8c = &iStack_80;
  puStack_88 = &_gp;
  puStack_6c = puStack_ac;
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_90 = 0x4000;
  piStack_70 = param_1;
  uStack_68 = unaff_s3;
  puStack_64 = unaff_s4;
  puStack_60 = unaff_s5;
  puVar6 = (ushort *)(**(code **)(*(int *)(uStack_ec + 8) + 0x30))();
  if (iStack_80 != 0) {
    iVar5 = *(int *)(*(int *)(uStack_ec + 0x58) + 0x340);
    if (iVar5 == 0x14) {
      puVar6 = (ushort *)0x1;
      *(undefined4 *)(*(int *)(uStack_ec + 0x58) + 0x354) = 1;
    }
    else {
      if (iVar5 == 4) {
        if ((int)puVar6 < 6) {
          pcVar23 = *(code **)(puStack_88 + -0x6eb0);
          uStack_90 = 0x811;
        }
        else {
          pbVar11 = *(byte **)(uStack_ec + 0x40);
          param_1 = *(int **)(uStack_ec + 0xc0);
          unaff_s4 = (ushort *)(pbVar11 + 6);
          bVar2 = *pbVar11;
          param_1[0x3b] = (uint)bVar2 << 0x18;
          uVar14 = (uint)pbVar11[1] << 0x10 | (uint)bVar2 << 0x18;
          param_1[0x3b] = uVar14;
          uVar14 = (uint)pbVar11[2] << 8 | uVar14;
          param_1[0x3b] = uVar14;
          param_1[0x3b] = pbVar11[3] | uVar14;
          puStack_ac = (undefined *)(uint)*(ushort *)(pbVar11 + 4);
          pcVar23 = *(code **)(puStack_88 + -0x6eb0);
          if (puVar6 == (ushort *)(puStack_ac + 6)) {
            if (param_1[0x39] != 0) {
              (**(code **)(puStack_88 + -0x7f58))();
              param_1 = *(int **)(uStack_ec + 0xc0);
              param_1[0x3a] = 0;
            }
            unaff_s5 = (ushort *)0x640000;
            iVar5 = (**(code **)(puStack_88 + -0x7dd8))(puStack_ac,"s3_clnt.c",0x824);
            iVar12 = *(int *)(uStack_ec + 0xc0);
            param_1[0x39] = iVar5;
            iVar5 = *(int *)(iVar12 + 0xe4);
            if (iVar5 == 0) {
              uStack_90 = 0x827;
              (**(code **)(puStack_88 + -0x6eb0))(0x14,0x11b,0x41,"s3_clnt.c");
              puVar6 = (ushort *)0xffffffff;
            }
            else {
              (**(code **)(puStack_88 + -0x52ec))(iVar5,unaff_s4,puStack_ac);
              uStack_ec = *(uint *)(uStack_ec + 0xc0);
              pcVar23 = *(code **)(puStack_88 + -0x6d74);
              *(undefined **)(uStack_ec + 0xe8) = puStack_ac;
              uStack_90 = (*pcVar23)();
              piStack_8c = (int *)0x0;
              (**(code **)(puStack_88 + -0x73dc))
                        (unaff_s4,puStack_ac,uStack_ec + 0x48,uStack_ec + 0x44);
              puVar6 = (ushort *)0x1;
            }
            goto LAB_00486490;
          }
          uStack_90 = 0x81c;
        }
        (*pcVar23)(0x14,0x11b,0x9f,"s3_clnt.c");
        uVar16 = 0x32;
      }
      else {
        uStack_90 = 0x80a;
        (**(code **)(puStack_88 + -0x6eb0))(0x14,0x11b,0x72,"s3_clnt.c");
        uVar16 = 10;
      }
      ssl3_send_alert(uStack_ec,2,uVar16);
      puVar6 = (ushort *)0xffffffff;
    }
  }
LAB_00486490:
  if (iStack_7c == *(int *)pcStack_134) {
    return puVar6;
  }
  pcStack_a4 = ssl3_get_cert_status;
  iStack_e8 = iStack_7c;
  (**(code **)(puStack_88 + -0x5328))();
  puStack_138 = PTR___stack_chk_guard_006aabf0;
  piStack_cc = &iStack_c0;
  puStack_c8 = &_gp;
  puStack_a8 = pcStack_134;
  iStack_bc = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_d0 = 0x4000;
  uStack_b4 = uStack_ec;
  piStack_b0 = param_1;
  puVar6 = (ushort *)(**(code **)(*(int *)(iStack_e8 + 8) + 0x30))();
  if (iStack_c0 != 0) {
    if (puVar6 < &SUB_00000004) {
      pcVar23 = *(code **)(puStack_c8 + -0x6eb0);
      uVar16 = 0x9f;
      uStack_d0 = 0x85c;
LAB_00486720:
      (*pcVar23)(0x14,0x121,uVar16,"s3_clnt.c");
      uVar16 = 0x32;
    }
    else {
      pcVar15 = *(char **)(iStack_e8 + 0x40);
      if (*pcVar15 != '\x01') {
        pcVar23 = *(code **)(puStack_c8 + -0x6eb0);
        uVar16 = 0x149;
        uStack_d0 = 0x863;
        goto LAB_00486720;
      }
      uStack_ec = (uint)(byte)pcVar15[1] << 0x10 | (uint)(byte)pcVar15[2] << 8 |
                  (uint)(byte)pcVar15[3];
      pcStack_134 = pcVar15 + 4;
      if (puVar6 != (ushort *)(uStack_ec + 4)) {
        pcVar23 = *(code **)(puStack_c8 + -0x6eb0);
        uVar16 = 0x9f;
        uStack_d0 = 0x86a;
        goto LAB_00486720;
      }
      if (*(int *)(iStack_e8 + 0x138) != 0) {
        (**(code **)(puStack_c8 + -0x7f58))();
      }
      iVar5 = (**(code **)(puStack_c8 + -0x6d20))(pcStack_134,uStack_ec);
      *(int *)(iStack_e8 + 0x138) = iVar5;
      if (iVar5 == 0) {
        uStack_d0 = 0x873;
        (**(code **)(puStack_c8 + -0x6eb0))(0x14,0x121,0x41,"s3_clnt.c");
        uVar16 = 0x50;
      }
      else {
        *(uint *)(iStack_e8 + 0x13c) = uStack_ec;
        pcVar23 = *(code **)(*(int *)(iStack_e8 + 0xe4) + 0x13c);
        if (pcVar23 == (code *)0x0) {
LAB_004866a0:
          puVar6 = (ushort *)0x1;
          goto LAB_004866a4;
        }
        iVar5 = (*pcVar23)(iStack_e8,*(undefined4 *)(*(int *)(iStack_e8 + 0xe4) + 0x140));
        if (iVar5 == 0) {
          uStack_d0 = 0x87e;
          (**(code **)(puStack_c8 + -0x6eb0))(0x14,0x121,0x148,"s3_clnt.c");
          uVar16 = 0x71;
        }
        else {
          if (-1 < iVar5) goto LAB_004866a0;
          uStack_d0 = 0x884;
          (**(code **)(puStack_c8 + -0x6eb0))(0x14,0x121,0x41,"s3_clnt.c");
          uVar16 = 0x50;
        }
      }
    }
    ssl3_send_alert(iStack_e8,2,uVar16);
    puVar6 = (ushort *)0xffffffff;
  }
LAB_004866a4:
  if (iStack_bc == *(int *)puStack_138) {
    return puVar6;
  }
  pcStack_e4 = ssl3_get_server_done;
  iStack_13c = iStack_bc;
  (**(code **)(puStack_c8 + -0x5328))();
  puStack_140 = PTR___stack_chk_guard_006aabf0;
  piStack_104 = &iStack_f8;
  pcVar15 = &DAT_0000000e;
  puStack_100 = &_gp;
  piStack_f4 = *(int **)PTR___stack_chk_guard_006aabf0;
  uStack_108 = 0x1e;
  puVar6 = (ushort *)(**(code **)(*(int *)(iStack_13c + 8) + 0x30))();
  if ((iStack_f8 != 0) && (bVar1 = 0 < (int)puVar6, puVar6 = (ushort *)0x1, bVar1)) {
    ssl3_send_alert(iStack_13c,2,0x32);
    pcVar15 = "s3_clnt.c";
    uStack_108 = 0x8a0;
    (**(code **)(puStack_100 + -0x6eb0))(0x14,0x91,0x9f,"s3_clnt.c");
    puVar6 = (ushort *)0xffffffff;
  }
  if (piStack_f4 == *(int **)puStack_140) {
    return puVar6;
  }
  pcStack_11c = ssl3_send_client_key_exchange;
  piVar13 = piStack_f4;
  (**(code **)(puStack_100 + -0x5328))();
  puVar4 = PTR___stack_chk_guard_006aabf0;
  iStack_144 = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar6 = unaff_s4;
  puVar21 = unaff_s5;
  puStack_130 = unaff_s4;
  puStack_12c = unaff_s5;
  puStack_128 = unaff_s6;
  puStack_124 = unaff_s7;
  ppuStack_120 = unaff_s8;
  if (piVar13[0xd] != 0x1180) goto LAB_00486a38;
  puVar20 = *(undefined **)(piVar13[0xf] + 4);
  uVar14 = *(uint *)(*(int *)(piVar13[0x16] + 0x344) + 0xc);
  puVar19 = puVar20 + 4;
  if ((uVar14 & 1) == 0) {
    if ((uVar14 & 0xe) == 0) {
      if ((uVar14 & 0xe0) != 0) {
        puVar6 = *(ushort **)(*(int *)(piVar13[0x30] + 0x98) + 0x74);
        if (puVar6 == (ushort *)0x0) {
          piVar22 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                     (*(undefined4 *)(*(int *)(piVar13[0x30] + 0x98) + 0x48));
          if (((piVar22 == (int *)0x0) || (*piVar22 != 0x198)) ||
             (puVar6 = (ushort *)piVar22[5], puVar6 == (ushort *)0x0)) {
            uVar18 = 0x44;
            uVar16 = 0x9fb;
            goto LAB_004872f8;
          }
        }
        else {
          piVar22 = (int *)0x0;
        }
        puVar21 = (ushort *)(*(code *)PTR_EC_KEY_get0_group_006a8780)(puVar6);
        iVar5 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(puVar6);
        if ((puVar21 == (ushort *)0x0) || (iVar5 == 0)) {
          uVar18 = 0x44;
          uVar16 = 0xa08;
LAB_004872f8:
          pcVar15 = "s3_clnt.c";
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar18,"s3_clnt.c",uVar16);
          goto LAB_00487124;
        }
        puVar6 = (ushort *)(*(code *)PTR_EC_KEY_new_006a82a8)();
        if (puVar6 == (ushort *)0x0) {
          uVar18 = 0x41;
          uVar16 = 0xa0e;
          goto LAB_004872f8;
        }
        iVar12 = (*(code *)PTR_EC_KEY_set_group_006a82d0)(puVar6,puVar21);
        if (iVar12 == 0) {
          uVar18 = 0x10;
          uVar16 = 0xa14;
        }
        else {
          iVar12 = (*(code *)PTR_EC_KEY_generate_key_006a82d4)(puVar6);
          if (iVar12 == 0) {
            uVar18 = 0x2b;
            uVar16 = 0xa30;
          }
          else {
            iVar12 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)(puVar21);
            if (iVar12 < 1) {
              uVar18 = 0x2b;
              uVar16 = 0xa3d;
            }
            else {
              iVar5 = (*(code *)PTR_ECDH_compute_key_006a8bd4)
                                (puVar19,iVar12 + 7 >> 3,iVar5,puVar6,0);
              if (0 < iVar5) {
                iVar12 = piVar13[0x30];
                uVar16 = (**(code **)(*(int *)(piVar13[2] + 100) + 0xc))
                                   (piVar13,iVar12 + 0x14,puVar19,iVar5);
                puVar3 = PTR_memset_006aab00;
                *(undefined4 *)(iVar12 + 0x10) = uVar16;
                (*(code *)puVar3)(puVar19,0,iVar5);
                uVar16 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(puVar6);
                uVar16 = (*(code *)PTR_EC_POINT_point2oct_006a9118)(puVar21,uVar16,4,0,0,0);
                puVar8 = (ushort *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar16,"s3_clnt.c",0xa62);
                iVar5 = (*(code *)PTR_BN_CTX_new_006a8a38)();
                if (puVar8 == (ushort *)0x0) {
                  pcVar15 = "s3_clnt.c";
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,0x41,"s3_clnt.c",0xa67);
                  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar5);
                  goto LAB_004871d0;
                }
                if (iVar5 == 0) {
                  pcVar15 = "s3_clnt.c";
                  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,0x41,"s3_clnt.c",0xa67);
                  (*(code *)PTR_BN_CTX_free_006a8a40)(0);
                  (*(code *)PTR_CRYPTO_free_006a7f88)(puVar8);
                  goto LAB_004871d0;
                }
                uVar18 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(puVar6);
                pcVar15 = (char *)puVar8;
                iVar9 = (*(code *)PTR_EC_POINT_point2oct_006a9118)
                                  (puVar21,uVar18,4,puVar8,uVar16,iVar5);
                puVar20[4] = (char)iVar9;
                iVar12 = iVar9 + 1;
                (*(code *)PTR_memcpy_006aabf4)(puVar20 + 5,puVar8,iVar9);
                (*(code *)PTR_BN_CTX_free_006a8a40)(iVar5);
                (*(code *)PTR_CRYPTO_free_006a7f88)(puVar8);
                (*(code *)PTR_EC_KEY_free_006a82d8)(puVar6);
                (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar22);
                goto LAB_00486a04;
              }
              uVar18 = 0x2b;
              uVar16 = 0xa44;
            }
          }
        }
        pcVar15 = "s3_clnt.c";
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar18,"s3_clnt.c",uVar16);
        (*(code *)PTR_BN_CTX_free_006a8a40)(0);
LAB_004871d0:
        (*(code *)PTR_EC_KEY_free_006a82d8)(puVar6);
        goto LAB_00487134;
      }
      if ((uVar14 & 0x200) == 0) {
        if ((uVar14 & 0x400) == 0) {
          if ((uVar14 & 0x100) == 0) {
            ssl3_send_alert();
            uVar18 = 0x44;
            uVar16 = 0xb54;
          }
          else {
            if ((code *)piVar13[0x37] != (code *)0x0) {
              puVar6 = (ushort *)&uStack_348;
              puVar21 = auStack_3c8;
              uVar16 = 0x204;
              puVar8 = puVar6;
              uVar14 = (*(code *)piVar13[0x37])();
              if (0x100 < uVar14) {
                uVar18 = 0x44;
                pcVar15 = "s3_clnt.c";
                uVar16 = 0xb14;
                goto LAB_00487250;
              }
              if (uVar14 == 0) {
                uVar18 = 0xdf;
                pcVar15 = "s3_clnt.c";
                uVar16 = 0xb1a;
                goto LAB_00487250;
              }
              (*(code *)PTR_memmove_006aabfc)((byte *)((int)puVar6 + uVar14 + 4),puVar6,uVar14);
              uVar24 = (undefined)(uVar14 >> 8);
              uStack_348 = uVar24;
              uStack_347 = (char)uVar14;
              (*(code *)PTR___memset_chk_006aaa98)(&uStack_348 + 2,0,uVar14,0x202,puVar8,uVar16);
              iVar5 = piVar13[0x30];
              (&uStack_348 + 2)[uVar14] = uVar24;
              (&uStack_348)[uVar14 + 3] = (char)uVar14;
              pcVar15 = (char *)(uVar14 * 2 + 4);
              if (*(int *)(iVar5 + 0x8c) != 0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
                iVar5 = piVar13[0x30];
              }
              uVar16 = (*(code *)PTR_BUF_strdup_006a80dc)(*(undefined4 *)(piVar13[0x39] + 0x14c));
              iVar12 = piVar13[0x39];
              iVar9 = piVar13[0x30];
              *(undefined4 *)(iVar5 + 0x8c) = uVar16;
              if ((*(int *)(iVar12 + 0x14c) != 0) &&
                 (puVar8 = (ushort *)0x640000, *(int *)(iVar9 + 0x8c) == 0)) goto LAB_00487694;
              if (*(int *)(iVar9 + 0x90) != 0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
                iVar9 = piVar13[0x30];
              }
              uVar16 = (*(code *)PTR_BUF_strdup_006a80dc)(puVar21);
              iVar5 = piVar13[0x30];
              *(undefined4 *)(iVar9 + 0x90) = uVar16;
              if (*(int *)(iVar5 + 0x90) == 0) {
                uVar18 = 0x41;
                pcVar15 = "s3_clnt.c";
                uVar16 = 0xb38;
                goto LAB_00487250;
              }
              uVar16 = (**(code **)(*(int *)(piVar13[2] + 100) + 0xc))
                                 (piVar13,iVar5 + 0x14,puVar6,pcVar15);
              puVar19 = PTR_strlen_006aab30;
              *(undefined4 *)(iVar5 + 0x10) = uVar16;
              iVar5 = (*(code *)puVar19)(puVar21);
              puVar20[5] = (char)iVar5;
              puVar20[4] = (char)((uint)iVar5 >> 8);
              iVar12 = iVar5 + 2;
              (*(code *)PTR_memcpy_006aabf4)(puVar20 + 6,puVar21,iVar5);
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(puVar21,0x80);
              (*(code *)PTR_OPENSSL_cleanse_006a8174)(puVar6,0x204);
              goto LAB_00486a04;
            }
            uVar18 = 0xe0;
            uVar16 = 0xb0a;
          }
        }
        else {
          pcVar15 = "s\n";
          if (piVar13[0x6e] == 0) {
            uVar18 = 0x44;
            uVar16 = 0xae9;
          }
          else {
            iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)();
            puVar19 = PTR_BN_bn2bin_006a8300;
            iVar5 = iVar12 + 7;
            if (iVar12 + 7 < 0) {
              iVar5 = iVar12 + 0xe;
            }
            iVar12 = (iVar5 >> 3) + 2;
            puVar20[5] = (char)(iVar5 >> 3);
            puVar20[4] = (char)(iVar5 >> 0xb);
            (*(code *)puVar19)(piVar13[0x6e],puVar20 + 6);
            puVar21 = (ushort *)piVar13[0x30];
            if (*(int *)(puVar21 + 0x78) != 0) {
              (*(code *)PTR_CRYPTO_free_006a7f88)();
              puVar21 = (ushort *)piVar13[0x30];
            }
            uVar16 = (*(code *)PTR_BUF_strdup_006a80dc)(piVar13[0x69]);
            puVar6 = (ushort *)piVar13[0x30];
            *(undefined4 *)(puVar21 + 0x78) = uVar16;
            unaff_s4 = puVar6;
            unaff_s5 = puVar21;
            if (*(int *)(puVar6 + 0x78) == 0) {
              uVar18 = 0x41;
              uVar16 = 0xaf2;
            }
            else {
              iVar5 = (*(code *)PTR_SRP_generate_client_master_secret_006a91cc)(piVar13,puVar6 + 10)
              ;
              *(int *)(puVar6 + 8) = iVar5;
              if (-1 < iVar5) goto LAB_00486a04;
              uVar18 = 0x44;
              uVar16 = 0xaf8;
            }
          }
        }
      }
      else if ((*(int *)(*(int *)(piVar13[0x30] + 0x98) + 0x60) == 0) &&
              (*(int *)(*(int *)(piVar13[0x30] + 0x98) + 0x54) == 0)) {
        uVar18 = 0x14a;
        uVar16 = 0xa93;
      }
      else {
        uVar16 = (*(code *)PTR_X509_get_pubkey_006a8008)();
        puVar21 = (ushort *)(*(code *)PTR_EVP_PKEY_CTX_new_006a80e0)(uVar16,0);
        (*(code *)PTR_EVP_PKEY_encrypt_init_006a8ddc)(puVar21);
        (*(code *)PTR_RAND_bytes_006a8d44)(auStack_3e8,0x20);
        if (((*(int *)(piVar13[0x16] + 0x358) != 0) && (*(int *)(*(int *)piVar13[0x26] + 4) != 0))
           && (iVar5 = (*(code *)PTR_EVP_PKEY_derive_set_peer_006a8de0)(puVar21), iVar5 < 1)) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
        }
        uVar18 = (*(code *)PTR_EVP_MD_CTX_create_006a91c4)();
        uVar10 = (*(code *)PTR_OBJ_nid2sn_006a819c)(0x329);
        uVar10 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar10);
        (*(code *)PTR_EVP_DigestInit_006a8f30)(uVar18,uVar10);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(uVar18,piVar13[0x16] + 0xc0,0x20);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(uVar18,piVar13[0x16] + 0xa0,0x20);
        (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(uVar18,auStack_3c8,auStack_3ec);
        (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)(uVar18);
        iVar5 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(puVar21,0xffffffff,0x100,8,8,auStack_3c8);
        puVar19 = PTR_EVP_PKEY_encrypt_006a8e04;
        unaff_s5 = puVar21;
        if (iVar5 < 0) {
          uVar18 = 0x112;
          uVar16 = 0xab7;
          unaff_s4 = auStack_3c8;
        }
        else {
          puVar20[4] = 0x30;
          uStack_3f0 = 0xff;
          iVar5 = (*(code *)puVar19)(puVar21,&uStack_348,&uStack_3f0,auStack_3e8,0x20);
          if (-1 < iVar5) {
            iVar12 = uStack_3f0 + 2;
            uVar24 = (undefined)uStack_3f0;
            if (uStack_3f0 < 0x80) {
              puVar19 = puVar20 + 6;
            }
            else {
              puVar19 = puVar20 + 7;
              puVar20[6] = uVar24;
              iVar12 = uStack_3f0 + 3;
              uVar24 = 0x81;
            }
            puVar3 = PTR_memcpy_006aabf4;
            puVar20[5] = uVar24;
            (*(code *)puVar3)(puVar19,&uStack_348);
            iVar5 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(puVar21,0xffffffff,0xffffffff,2,2,0);
            if (0 < iVar5) {
              *(uint *)piVar13[0x16] = *(uint *)piVar13[0x16] | 0x10;
            }
            (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(puVar21);
            pcVar15 = &DAT_00000020;
            puVar6 = (ushort *)piVar13[0x30];
            uVar18 = (**(code **)(*(int *)(piVar13[2] + 100) + 0xc))
                               (piVar13,puVar6 + 10,auStack_3e8,0x20);
            puVar19 = PTR_EVP_PKEY_free_006a7f78;
            *(undefined4 *)(puVar6 + 8) = uVar18;
            (*(code *)puVar19)(uVar16);
            goto LAB_00486a04;
          }
          uVar18 = 0x112;
          uVar16 = 0xac0;
          unaff_s4 = (ushort *)&uStack_348;
        }
      }
    }
    else if (*(int *)(piVar13[0x30] + 0x98) == 0) {
      ssl3_send_alert();
      uVar18 = 0xf4;
      uVar16 = 0x98f;
    }
    else {
      puVar21 = *(ushort **)(*(int *)(piVar13[0x30] + 0x98) + 0x70);
      if (puVar21 == (ushort *)0x0) {
        ssl3_send_alert();
        uVar18 = 0xee;
        uVar16 = 0x999;
        unaff_s5 = puVar21;
      }
      else {
        puVar6 = (ushort *)(*(code *)PTR_DHparams_dup_006a90f8)(puVar21);
        if (puVar6 != (ushort *)0x0) {
          iVar5 = (*(code *)PTR_DH_generate_key_006a90fc)(puVar6);
          if (iVar5 == 0) {
            uVar16 = 0x9a5;
LAB_004874a8:
            pcVar15 = "s3_clnt.c";
            piVar22 = (int *)0x0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,5,"s3_clnt.c",uVar16);
            (*(code *)PTR_DH_free_006a8604)(puVar6);
            goto LAB_00487124;
          }
          puVar21 = (ushort *)
                    (*(code *)PTR_DH_compute_key_006a912c)
                              (puVar19,*(undefined4 *)(puVar21 + 10),puVar6);
          if ((int)puVar21 < 1) {
            uVar16 = 0x9b1;
            goto LAB_004874a8;
          }
          iVar5 = piVar13[0x30];
          pcVar15 = (char *)puVar21;
          uVar16 = (**(code **)(*(int *)(piVar13[2] + 100) + 0xc))
                             (piVar13,iVar5 + 0x14,puVar19,puVar21);
          puVar3 = PTR_memset_006aab00;
          *(undefined4 *)(iVar5 + 0x10) = uVar16;
          (*(code *)puVar3)(puVar19,0,puVar21);
          iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(puVar6 + 10));
          puVar19 = PTR_BN_bn2bin_006a8300;
          iVar5 = iVar12 + 7;
          if (iVar12 + 7 < 0) {
            iVar5 = iVar12 + 0xe;
          }
          iVar12 = (iVar5 >> 3) + 2;
          puVar20[5] = (char)(iVar5 >> 3);
          puVar20[4] = (char)(iVar5 >> 0xb);
          (*(code *)puVar19)(*(undefined4 *)(puVar6 + 10),puVar20 + 6);
          (*(code *)PTR_DH_free_006a8604)(puVar6);
          goto LAB_00486a04;
        }
        uVar18 = 5;
        uVar16 = 0x9a0;
        unaff_s4 = puVar6;
        unaff_s5 = puVar21;
      }
    }
  }
  else {
    puVar21 = *(ushort **)(*(int *)(piVar13[0x30] + 0x98) + 0x6c);
    if (puVar21 == (ushort *)0x0) {
      piVar22 = (int *)(*(code *)PTR_X509_get_pubkey_006a8008)
                                 (*(undefined4 *)(*(int *)(piVar13[0x30] + 0x98) + 0xc));
      if (((piVar22 == (int *)0x0) || (pcVar15 = "s\n", *piVar22 != 6)) ||
         (puVar21 = (ushort *)piVar22[5], puVar21 == (ushort *)0x0)) {
        uVar18 = 0x44;
        uVar16 = 0x8d5;
        unaff_s5 = puVar21;
        goto LAB_0048710c;
      }
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar22);
    }
    uStack_347 = (undefined)piVar13[0x44];
    uStack_348 = (undefined)((uint)piVar13[0x44] >> 8);
    iVar5 = (*(code *)PTR_RAND_bytes_006a8d44)(&uStack_348 + 2,0x2e);
    puVar3 = PTR_RSA_public_encrypt_006a8744;
    if (iVar5 < 1) goto LAB_00487120;
    puVar6 = (ushort *)&uStack_348;
    puVar17 = puVar20 + 6;
    if (*piVar13 < 0x301) {
      puVar17 = puVar19;
    }
    *(undefined4 *)(piVar13[0x30] + 0x10) = 0x30;
    iVar5 = (*(code *)puVar3)(0x30,puVar6,puVar17,puVar21,1);
    if (0 < iVar5) {
      iVar12 = iVar5;
      if (0x300 < *piVar13) {
        puVar20[5] = (char)iVar5;
        iVar12 = iVar5 + 2;
        puVar20[4] = (char)((uint)iVar5 >> 8);
      }
      pcVar15 = &DAT_00000030;
      puVar21 = (ushort *)piVar13[0x30];
      uVar16 = (**(code **)(*(int *)(piVar13[2] + 100) + 0xc))(piVar13,puVar21 + 10,puVar6,0x30);
      puVar19 = PTR_OPENSSL_cleanse_006a8174;
      *(undefined4 *)(puVar21 + 8) = uVar16;
      (*(code *)puVar19)(puVar6,0x30);
LAB_00486a04:
      puVar20[3] = (char)iVar12;
      puVar20[2] = (char)((uint)iVar12 >> 8);
      puVar20[1] = (char)((uint)iVar12 >> 0x10);
      *puVar20 = 0x10;
      piVar13[0x11] = iVar12 + 4;
      piVar13[0xd] = 0x1181;
      piVar13[0x12] = 0;
LAB_00486a38:
      puVar7 = (ushort *)ssl3_do_write(piVar13,0x16);
      puVar8 = (ushort *)pcVar15;
      goto LAB_00486a48;
    }
    uVar18 = 0x77;
    uVar16 = 0x8ef;
    unaff_s4 = puVar6;
    unaff_s5 = puVar21;
  }
LAB_0048710c:
  pcVar15 = "s3_clnt.c";
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar18,"s3_clnt.c",uVar16);
  puVar6 = unaff_s4;
  puVar21 = unaff_s5;
LAB_00487120:
  while( true ) {
    piVar22 = (int *)0x0;
LAB_00487124:
    (*(code *)PTR_BN_CTX_free_006a8a40)(0);
LAB_00487134:
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar22);
    puVar7 = (ushort *)0xffffffff;
    puVar8 = (ushort *)pcVar15;
LAB_00486a48:
    if (iStack_144 == *(int *)puVar4) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00487694:
    uVar18 = 0x41;
    pcVar15 = (char *)(puVar8 + 0x34ac);
    uVar16 = 0xb2e;
LAB_00487250:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x98,uVar18,pcVar15,uVar16);
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(puVar21,0x80);
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(puVar6,0x204);
    ssl3_send_alert(piVar13,2,0x28);
  }
  return puVar7;
}

