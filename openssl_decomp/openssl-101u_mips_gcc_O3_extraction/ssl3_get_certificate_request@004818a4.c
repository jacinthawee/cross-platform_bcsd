
ushort * ssl3_get_certificate_request(int *param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int *piVar11;
  char *pcVar12;
  undefined4 uVar13;
  undefined *puVar14;
  undefined4 uVar15;
  undefined *puVar16;
  int iVar17;
  undefined *puVar18;
  ushort *unaff_s3;
  ushort *unaff_s4;
  ushort **unaff_s5;
  int iVar19;
  ushort *unaff_s6;
  ushort *unaff_s7;
  int *piVar20;
  code *pcVar21;
  ushort *unaff_s8;
  undefined uVar22;
  uint uStack_3f4;
  undefined auStack_3f0 [4];
  undefined auStack_3ec [32];
  undefined auStack_3cc [129];
  undefined uStack_34b;
  undefined auStack_348 [516];
  int iStack_144;
  undefined *puStack_140;
  int iStack_13c;
  undefined *puStack_138;
  undefined *puStack_134;
  ushort *puStack_130;
  ushort **ppuStack_12c;
  ushort *puStack_128;
  ushort *puStack_124;
  ushort *puStack_120;
  code *pcStack_11c;
  undefined4 uStack_108;
  int *piStack_104;
  undefined *puStack_100;
  int iStack_f8;
  int *piStack_f4;
  int iStack_ec;
  undefined *puStack_e8;
  code *pcStack_e4;
  undefined4 uStack_d0;
  int *piStack_cc;
  undefined *puStack_c8;
  int iStack_c0;
  int iStack_bc;
  int *piStack_b8;
  int iStack_b4;
  undefined *puStack_b0;
  code *pcStack_ac;
  undefined4 uStack_98;
  int *piStack_94;
  undefined *puStack_90;
  int iStack_88;
  int iStack_84;
  int *piStack_80;
  ushort *puStack_7c;
  undefined *puStack_78;
  ushort *puStack_74;
  ushort *puStack_70;
  ushort **ppuStack_6c;
  ushort *puStack_68;
  code *pcStack_64;
  int local_50;
  int *local_4c;
  undefined *local_48;
  int local_3c;
  int local_34;
  ushort *local_30;
  int local_2c;
  
  puStack_138 = PTR___stack_chk_guard_006a9ae8;
  local_50 = param_1[0x42];
  local_4c = &local_34;
  local_48 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_7c = (ushort *)(**(code **)(param_1[2] + 0x30))(param_1,0x1150,0x1151,0xffffffff);
  puVar5 = puStack_7c;
  if (local_34 != 0) {
    iVar4 = param_1[0x16];
    *(undefined4 *)(iVar4 + 0x358) = 0;
    if (*(int *)(iVar4 + 0x340) == 0xe) {
      *(undefined4 *)(iVar4 + 0x354) = 1;
      if ((*(int *)(iVar4 + 0x178) == 0) ||
         (iVar4 = ssl3_digest_cached_records(param_1), iVar4 != 0)) {
        puVar5 = (ushort *)0x1;
        goto LAB_004819a0;
      }
    }
    else {
      if (*(int *)(iVar4 + 0x340) == 0xd) {
        if ((*param_1 < 0x301) || ((*(uint *)(*(int *)(iVar4 + 0x344) + 0x10) & 4) == 0)) {
          unaff_s6 = (ushort *)param_1[0x10];
          local_3c = (**(code **)(local_48 + -0x6d74))(ca_dn_cmp);
          if (local_3c != 0) {
            unaff_s4 = (ushort *)(uint)*(byte *)unaff_s6;
            if (&DAT_00000009 < unaff_s4) {
              unaff_s4 = (ushort *)&DAT_00000009;
            }
            if ((((unaff_s4 != (ushort *)0x0) &&
                 (*(byte *)(param_1[0x16] + 0x360) = *(byte *)((int)unaff_s6 + 1),
                 unaff_s4 != (ushort *)0x1)) &&
                (*(byte *)(param_1[0x16] + 0x361) = *(byte *)(unaff_s6 + 1),
                unaff_s4 != (ushort *)&SUB_00000002)) &&
               ((((*(byte *)(param_1[0x16] + 0x362) = *(byte *)((int)unaff_s6 + 3),
                  unaff_s4 != (ushort *)0x3 &&
                  (*(byte *)(param_1[0x16] + 0x363) = *(byte *)(unaff_s6 + 2),
                  unaff_s4 != (ushort *)&SUB_00000004)) &&
                 ((*(byte *)(param_1[0x16] + 0x364) = *(byte *)((int)unaff_s6 + 5),
                  unaff_s4 != (ushort *)&DAT_00000005 &&
                  ((*(byte *)(param_1[0x16] + 0x365) = *(byte *)(unaff_s6 + 3),
                   unaff_s4 != (ushort *)&DAT_00000006 &&
                   (*(byte *)(param_1[0x16] + 0x366) = *(byte *)((int)unaff_s6 + 7),
                   unaff_s4 != (ushort *)&DAT_00000007)))))) &&
                (*(byte *)(param_1[0x16] + 0x367) = *(byte *)(unaff_s6 + 4),
                unaff_s4 == (ushort *)&DAT_00000009)))) {
              *(byte *)(param_1[0x16] + 0x368) = *(byte *)((int)unaff_s6 + 9);
            }
            puVar5 = (ushort *)((int)unaff_s6 + (int)((int)unaff_s4 + 1));
            if ((*param_1 >> 8 == 3) && (unaff_s7 = puVar5 + 1, 0x302 < *param_1)) {
              unaff_s3 = (ushort *)(uint)*puVar5;
              if (puStack_7c <
                  (ushort *)((int)unaff_s3 + (int)((int)unaff_s7 + (2 - (int)unaff_s6)))) {
                ssl3_send_alert(param_1,2,0x32);
                uVar13 = 0x92;
                local_50 = 0x803;
                pcVar21 = *(code **)(local_48 + -0x6eac);
              }
              else {
                if (((*puVar5 & 1) == 0) &&
                   (iVar4 = tls1_process_sigalgs(param_1,unaff_s7,unaff_s3), iVar4 != 0)) {
                  puVar5 = (ushort *)((int)unaff_s7 + (int)unaff_s3);
                  goto LAB_00481af4;
                }
                ssl3_send_alert(param_1,2,0x32);
                uVar13 = 0x168;
                local_50 = 0x809;
                pcVar21 = *(code **)(local_48 + -0x6eac);
              }
            }
            else {
LAB_00481af4:
              unaff_s3 = (ushort *)(uint)*puVar5;
              unaff_s6 = (ushort *)((byte *)((int)puVar5 + (2 - (int)unaff_s6)) + (int)unaff_s3);
              if (puStack_7c == unaff_s6) {
                if (unaff_s3 == (ushort *)0x0) {
LAB_00481c94:
                  iVar4 = param_1[0x16];
                  *(ushort **)(iVar4 + 0x35c) = unaff_s4;
                  *(undefined4 *)(iVar4 + 0x358) = 1;
                  if (*(int *)(iVar4 + 0x36c) != 0) {
                    (**(code **)(local_48 + -0x7d88))
                              (*(int *)(iVar4 + 0x36c),*(undefined4 *)(local_48 + -0x7de8));
                    iVar4 = param_1[0x16];
                  }
                  pcVar21 = *(code **)(local_48 + -0x7de8);
                  *(int *)(iVar4 + 0x36c) = local_3c;
                  (*pcVar21)(0);
                  puVar5 = (ushort *)0x1;
                  goto LAB_004819a0;
                }
                unaff_s8 = puVar5 + 2;
                if (unaff_s3 == (ushort *)0x1) {
LAB_00481da4:
                  ssl3_send_alert(param_1,2,0x32);
                  uVar13 = 0x84;
                  local_50 = 0x823;
                  pcVar21 = *(code **)(local_48 + -0x6eac);
                }
                else {
                  puStack_7c = (ushort *)(uint)puVar5[1];
                  unaff_s6 = puStack_7c + 1;
                  unaff_s5 = &local_30;
                  if (unaff_s3 < unaff_s6) {
                    iVar4 = param_1[0x40];
                  }
                  else {
                    do {
                      local_30 = unaff_s8;
                      unaff_s7 = (ushort *)(**(code **)(local_48 + -0x6d70))(0,unaff_s5,puStack_7c);
                      if (unaff_s7 == (ushort *)0x0) {
                        if (param_1[0x40] << 2 < 0) goto LAB_00481c84;
                        ssl3_send_alert(param_1,2,0x32);
                        uVar13 = 0xd;
                        local_50 = 0x837;
                        pcVar21 = *(code **)(local_48 + -0x6eac);
LAB_00481e54:
                        (*pcVar21)(0x14,0x87,uVar13,"s3_clnt.c");
                        goto LAB_00481b58;
                      }
                      puStack_7c = (ushort *)((int)unaff_s8 + (int)puStack_7c);
                      if (puStack_7c != local_30) {
                        ssl3_send_alert(param_1,2,0x32);
                        uVar13 = 0x83;
                        local_50 = 0x83f;
                        pcVar21 = *(code **)(local_48 + -0x6eac);
                        goto LAB_00481e54;
                      }
                      iVar4 = (**(code **)(local_48 + -0x7e38))(local_3c,unaff_s7);
                      if (iVar4 == 0) {
                        pcVar21 = *(code **)(local_48 + -0x6eac);
                        uVar13 = 0x41;
                        local_50 = 0x843;
                        goto LAB_00481e54;
                      }
                      if (unaff_s3 <= unaff_s6) goto LAB_00481c94;
                      unaff_s8 = puStack_7c + 1;
                      if (unaff_s3 < unaff_s6 + 1) goto LAB_00481da4;
                      puStack_7c = (ushort *)(uint)*puStack_7c;
                      unaff_s6 = (ushort *)((int)unaff_s6 + (int)(puStack_7c + 1));
                    } while (unaff_s6 <= unaff_s3);
                    iVar4 = param_1[0x40];
                  }
                  if (iVar4 << 2 < 0) {
LAB_00481c84:
                    (**(code **)(local_48 + -0x7f00))();
                    goto LAB_00481c94;
                  }
                  ssl3_send_alert(param_1,2,0x32);
                  uVar13 = 0x84;
                  local_50 = 0x82b;
                  pcVar21 = *(code **)(local_48 + -0x6eac);
                }
              }
              else {
                ssl3_send_alert(param_1,2,0x32);
                uVar13 = 0x9f;
                local_50 = 0x81c;
                pcVar21 = *(code **)(local_48 + -0x6eac);
              }
            }
            unaff_s7 = (ushort *)0x0;
            (*pcVar21)(0x14,0x87,uVar13,"s3_clnt.c");
LAB_00481b58:
            pcVar21 = *(code **)(local_48 + -0x7de8);
            param_1[0xd] = 5;
            (*pcVar21)(unaff_s7);
            (**(code **)(local_48 + -0x7d88))(local_3c,*(undefined4 *)(local_48 + -0x7de8));
            puVar5 = (ushort *)0x0;
            goto LAB_004819a0;
          }
          pcVar21 = *(code **)(local_48 + -0x6eac);
          uVar13 = 0x41;
          local_50 = 0x7ef;
        }
        else {
          ssl3_send_alert(param_1,2,10);
          uVar13 = 0xe8;
          local_50 = 0x7e7;
          pcVar21 = *(code **)(local_48 + -0x6eac);
        }
      }
      else {
        ssl3_send_alert(param_1,2,10);
        uVar13 = 0x106;
        local_50 = 0x7de;
        pcVar21 = *(code **)(local_48 + -0x6eac);
      }
      (*pcVar21)(0x14,0x87,uVar13,"s3_clnt.c");
    }
    pcVar21 = *(code **)(local_48 + -0x7de8);
    param_1[0xd] = 5;
    (*pcVar21)(0);
    puVar5 = (ushort *)0x0;
  }
LAB_004819a0:
  if (local_2c == *(int *)puStack_138) {
    return puVar5;
  }
  pcStack_64 = ssl3_get_new_session_ticket;
  iStack_b4 = local_2c;
  (**(code **)(local_48 + -0x5330))();
  puStack_134 = PTR___stack_chk_guard_006a9ae8;
  piStack_94 = &iStack_88;
  puStack_90 = &_gp;
  puStack_78 = puStack_138;
  iStack_84 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_98 = 0x4000;
  piStack_80 = param_1;
  puStack_74 = unaff_s3;
  puStack_70 = unaff_s4;
  ppuStack_6c = unaff_s5;
  puStack_68 = unaff_s6;
  puVar5 = (ushort *)(**(code **)(*(int *)(iStack_b4 + 8) + 0x30))();
  if (iStack_88 != 0) {
    if ((int)puVar5 < 6) {
      pcVar21 = *(code **)(puStack_90 + -0x6eac);
      uStack_98 = 0x87d;
LAB_00482114:
      (*pcVar21)(0x14,0x11b,0x9f,"s3_clnt.c");
      uVar13 = 0x32;
LAB_0048212c:
      ssl3_send_alert(iStack_b4,2,uVar13);
    }
    else {
      param_1 = *(int **)(iStack_b4 + 0x40);
      puStack_138 = (undefined *)(uint)*(ushort *)(param_1 + 1);
      pcVar21 = *(code **)(puStack_90 + -0x6eac);
      if (puVar5 != (ushort *)(puStack_138 + 6)) {
        uStack_98 = 0x888;
        goto LAB_00482114;
      }
      puVar5 = (ushort *)0x1;
      if (puStack_138 == (undefined *)0x0) goto LAB_0048204c;
      unaff_s4 = *(ushort **)(iStack_b4 + 0xc0);
      unaff_s5 = (ushort **)*param_1;
      unaff_s6 = unaff_s4;
      if (*(int *)(unaff_s4 + 0x22) != 0) {
        iVar4 = *(int *)(iStack_b4 + 0x170);
        pcVar21 = *(code **)(puStack_90 + -0x6d68);
        if ((*(uint *)(iVar4 + 0x20) & 1) != 0) {
          if ((*(uint *)(iVar4 + 0x20) & 0x200) == 0) {
            (**(code **)(puStack_90 + -0x6d64))(iVar4,unaff_s4);
            unaff_s4 = *(ushort **)(iStack_b4 + 0xc0);
          }
          else if (*(code **)(iVar4 + 0x2c) != (code *)0x0) {
            (**(code **)(iVar4 + 0x2c))(iVar4,unaff_s4);
            unaff_s4 = *(ushort **)(iStack_b4 + 0xc0);
          }
          pcVar21 = *(code **)(puStack_90 + -0x6d68);
        }
        unaff_s6 = (ushort *)(*pcVar21)(unaff_s4,0);
        if (unaff_s6 != (ushort *)0x0) {
          (**(code **)(puStack_90 + -0x742c))(*(undefined4 *)(iStack_b4 + 0xc0));
          *(ushort **)(iStack_b4 + 0xc0) = unaff_s6;
          goto LAB_00481fa8;
        }
        uStack_98 = 0x8a7;
        (**(code **)(puStack_90 + -0x6eac))(0x14,0x11b,0x41,"s3_clnt.c");
        uVar13 = 0x50;
        goto LAB_0048212c;
      }
LAB_00481fa8:
      if (*(int *)(unaff_s6 + 0x72) != 0) {
        (**(code **)(puStack_90 + -0x7f58))();
        unaff_s6 = *(ushort **)(iStack_b4 + 0xc0);
        *(undefined4 *)(unaff_s6 + 0x74) = 0;
      }
      uVar13 = (**(code **)(puStack_90 + -0x7dd8))(puStack_138,"s3_clnt.c",0x8b3);
      iVar4 = *(int *)(iStack_b4 + 0xc0);
      *(undefined4 *)(unaff_s6 + 0x72) = uVar13;
      iVar4 = *(int *)(iVar4 + 0xe4);
      unaff_s4 = unaff_s6;
      if (iVar4 != 0) {
        param_1 = (int *)((int)param_1 + 6);
        (**(code **)(puStack_90 + -0x52f4))(iVar4,param_1,puStack_138);
        iStack_b4 = *(int *)(iStack_b4 + 0xc0);
        pcVar21 = *(code **)(puStack_90 + -0x6de0);
        *(ushort ***)(iStack_b4 + 0xec) = unaff_s5;
        *(undefined **)(iStack_b4 + 0xe8) = puStack_138;
        uStack_98 = (*pcVar21)();
        piStack_94 = (int *)0x0;
        (**(code **)(puStack_90 + -0x73cc))(param_1,puStack_138,iStack_b4 + 0x48,iStack_b4 + 0x44);
        puVar5 = (ushort *)0x1;
        unaff_s6 = (ushort *)"-check_ss_sig";
        goto LAB_0048204c;
      }
      uStack_98 = 0x8b5;
      (**(code **)(puStack_90 + -0x6eac))(0x14,0x11b,0x41,"s3_clnt.c");
      unaff_s6 = (ushort *)"-check_ss_sig";
    }
    puVar5 = (ushort *)0xffffffff;
    *(undefined4 *)(iStack_b4 + 0x34) = 5;
  }
LAB_0048204c:
  if (iStack_84 == *(int *)puStack_134) {
    return puVar5;
  }
  pcStack_ac = ssl3_get_cert_status;
  iStack_ec = iStack_84;
  (**(code **)(puStack_90 + -0x5330))();
  puStack_e8 = PTR___stack_chk_guard_006a9ae8;
  piStack_cc = &iStack_c0;
  puStack_c8 = &_gp;
  iStack_bc = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_d0 = 0x4000;
  piStack_b8 = param_1;
  puStack_b0 = puStack_138;
  puVar5 = (ushort *)(**(code **)(*(int *)(iStack_ec + 8) + 0x30))();
  if (iStack_c0 != 0) {
    if (*(int *)(*(int *)(iStack_ec + 0x58) + 0x340) == 0x16) {
      if (puVar5 < &SUB_00000004) {
        pcVar21 = *(code **)(puStack_c8 + -0x6eac);
        uVar13 = 0x9f;
        uStack_d0 = 0x8ee;
      }
      else {
        pcVar12 = *(char **)(iStack_ec + 0x40);
        if (*pcVar12 == '\x01') {
          puStack_138 = (undefined *)
                        ((uint)(byte)pcVar12[1] << 0x10 | (uint)(byte)pcVar12[2] << 8 |
                        (uint)(byte)pcVar12[3]);
          if (puVar5 == (ushort *)(puStack_138 + 4)) {
            iVar4 = (**(code **)(puStack_c8 + -28000))(pcVar12 + 4,puStack_138);
            *(int *)(iStack_ec + 0x138) = iVar4;
            if (iVar4 != 0) {
              *(undefined **)(iStack_ec + 0x13c) = puStack_138;
              goto LAB_0048224c;
            }
            uStack_d0 = 0x900;
            (**(code **)(puStack_c8 + -0x6eac))(0x14,0x121,0x41,"s3_clnt.c");
            uVar13 = 0x50;
            goto LAB_00482328;
          }
          pcVar21 = *(code **)(puStack_c8 + -0x6eac);
          uVar13 = 0x9f;
          uStack_d0 = 0x8fa;
        }
        else {
          pcVar21 = *(code **)(puStack_c8 + -0x6eac);
          uVar13 = 0x149;
          uStack_d0 = 0x8f4;
        }
      }
      (*pcVar21)(0x14,0x121,uVar13,"s3_clnt.c");
      uVar13 = 0x32;
    }
    else {
      *(undefined4 *)(*(int *)(iStack_ec + 0x58) + 0x354) = 1;
LAB_0048224c:
      pcVar21 = *(code **)(*(int *)(iStack_ec + 0xe4) + 0x13c);
      if (pcVar21 == (code *)0x0) {
LAB_00482278:
        puVar5 = (ushort *)0x1;
        goto LAB_0048227c;
      }
      iVar4 = (*pcVar21)(iStack_ec,*(undefined4 *)(*(int *)(iStack_ec + 0xe4) + 0x140));
      if (iVar4 == 0) {
        uStack_d0 = 0x90a;
        (**(code **)(puStack_c8 + -0x6eac))(0x14,0x121,0x148,"s3_clnt.c");
        uVar13 = 0x71;
      }
      else {
        if (-1 < iVar4) goto LAB_00482278;
        uStack_d0 = 0x90f;
        (**(code **)(puStack_c8 + -0x6eac))(0x14,0x121,0x41,"s3_clnt.c");
        uVar13 = 0x50;
      }
    }
LAB_00482328:
    ssl3_send_alert(iStack_ec,2,uVar13);
    puVar5 = (ushort *)0xffffffff;
    *(undefined4 *)(iStack_ec + 0x34) = 5;
  }
LAB_0048227c:
  if (iStack_bc == *(int *)puStack_e8) {
    return puVar5;
  }
  pcStack_e4 = ssl3_get_server_done;
  iStack_13c = iStack_bc;
  (**(code **)(puStack_c8 + -0x5330))();
  puStack_140 = PTR___stack_chk_guard_006a9ae8;
  piStack_104 = &iStack_f8;
  puStack_100 = &_gp;
  piStack_f4 = *(int **)PTR___stack_chk_guard_006a9ae8;
  uStack_108 = 0x1e;
  puVar5 = (ushort *)(**(code **)(*(int *)(iStack_13c + 8) + 0x30))();
  if ((iStack_f8 != 0) && (bVar1 = 0 < (int)puVar5, puVar5 = (ushort *)0x1, bVar1)) {
    ssl3_send_alert(iStack_13c,2,0x32);
    uStack_108 = 0x92b;
    (**(code **)(puStack_100 + -0x6eac))(0x14,0x91,0x9f,"s3_clnt.c");
    puVar5 = (ushort *)0xffffffff;
    *(undefined4 *)(iStack_13c + 0x34) = 5;
  }
  if (piStack_f4 == *(int **)puStack_140) {
    return puVar5;
  }
  pcStack_11c = ssl3_send_client_key_exchange;
  piVar11 = piStack_f4;
  (**(code **)(puStack_100 + -0x5330))();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_144 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_130 = unaff_s4;
  ppuStack_12c = unaff_s5;
  puStack_128 = unaff_s6;
  puStack_124 = unaff_s7;
  puStack_120 = unaff_s8;
  if (piVar11[0xd] != 0x1180) goto LAB_0048268c;
  puVar18 = *(undefined **)(piVar11[0xf] + 4);
  uVar6 = *(uint *)(*(int *)(piVar11[0x16] + 0x344) + 0xc);
  puVar16 = puVar18 + 4;
  if ((uVar6 & 1) == 0) {
    if ((uVar6 & 0xe) == 0) {
      if ((uVar6 & 0xe0) != 0) {
        iVar4 = *(int *)(piVar11[0x30] + 0x98);
        if (iVar4 == 0) {
          ssl3_send_alert();
          uVar15 = 0xf4;
          uVar13 = 0xa65;
          goto LAB_00482d24;
        }
        iVar19 = *(int *)(iVar4 + 0x74);
        if (iVar19 == 0) {
          piVar20 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)(*(undefined4 *)(iVar4 + 0x48));
          if (((piVar20 == (int *)0x0) || (*piVar20 != 0x198)) || (iVar19 = piVar20[5], iVar19 == 0)
             ) {
            uVar15 = 0x44;
            uVar13 = 0xa90;
            goto LAB_00482f4c;
          }
        }
        else {
          piVar20 = (int *)0x0;
        }
        iVar4 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(iVar19);
        iVar19 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar19);
        if ((iVar4 == 0) || (iVar19 == 0)) {
          uVar15 = 0x44;
          uVar13 = 0xa9c;
LAB_00482f4c:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar15,"s3_clnt.c",uVar13);
          goto LAB_00482d3c;
        }
        iVar7 = (*(code *)PTR_EC_KEY_new_006a71a8)();
        if (iVar7 == 0) {
          uVar15 = 0x41;
          uVar13 = 0xaa2;
          goto LAB_00482f4c;
        }
        iVar17 = (*(code *)PTR_EC_KEY_set_group_006a71cc)(iVar7,iVar4);
        if (iVar17 == 0) {
          uVar15 = 0x10;
          uVar13 = 0xaa7;
        }
        else {
          iVar17 = (*(code *)PTR_EC_KEY_generate_key_006a71d0)(iVar7);
          if (iVar17 == 0) {
            uVar15 = 0x2b;
            uVar13 = 0xabf;
          }
          else {
            iVar17 = (*(code *)PTR_EC_GROUP_get_degree_006a7ae0)(iVar4);
            if (iVar17 < 1) {
              uVar15 = 0x2b;
              uVar13 = 0xacb;
            }
            else {
              iVar19 = (*(code *)PTR_ECDH_compute_key_006a7ae8)
                                 (puVar16,iVar17 + 7 >> 3,iVar19,iVar7,0);
              if (0 < iVar19) {
                iVar17 = piVar11[0x30];
                uVar13 = (**(code **)(*(int *)(piVar11[2] + 100) + 0xc))
                                   (piVar11,iVar17 + 0x14,puVar16,iVar19);
                puVar2 = PTR_memset_006a99f4;
                *(undefined4 *)(iVar17 + 0x10) = uVar13;
                (*(code *)puVar2)(puVar16,0,iVar19);
                uVar13 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar7);
                uVar13 = (*(code *)PTR_EC_POINT_point2oct_006a7f84)(iVar4,uVar13,4,0,0,0);
                iVar19 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar13,"s3_clnt.c",0xaed);
                iVar8 = (*(code *)PTR_BN_CTX_new_006a794c)();
                if (iVar19 == 0) {
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,0x41,"s3_clnt.c",0xaf1);
                  (*(code *)PTR_BN_CTX_free_006a7954)(iVar8);
                  goto LAB_00482dec;
                }
                if (iVar8 == 0) {
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,0x41,"s3_clnt.c",0xaf1);
                  (*(code *)PTR_BN_CTX_free_006a7954)(0);
                  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar19);
                  goto LAB_00482dec;
                }
                uVar15 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar7);
                iVar4 = (*(code *)PTR_EC_POINT_point2oct_006a7f84)
                                  (iVar4,uVar15,4,iVar19,uVar13,iVar8);
                puVar18[4] = (char)iVar4;
                iVar17 = iVar4 + 1;
                (*(code *)PTR_memcpy_006a9aec)(puVar18 + 5,iVar19,iVar4);
                (*(code *)PTR_BN_CTX_free_006a7954)(iVar8);
                (*(code *)PTR_CRYPTO_free_006a6e88)(iVar19);
                (*(code *)PTR_EC_KEY_free_006a71d4)(iVar7);
                (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar20);
                goto LAB_00482658;
              }
              uVar15 = 0x2b;
              uVar13 = 0xad1;
            }
          }
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar15,"s3_clnt.c",uVar13);
        (*(code *)PTR_BN_CTX_free_006a7954)(0);
LAB_00482dec:
        (*(code *)PTR_EC_KEY_free_006a71d4)(iVar7);
        goto LAB_00482d4c;
      }
      if ((uVar6 & 0x200) == 0) {
        if ((uVar6 & 0x400) == 0) {
          if ((uVar6 & 0x100) == 0) goto LAB_004833a8;
          pcVar21 = (code *)piVar11[0x37];
          if (pcVar21 == (code *)0x0) {
            uVar15 = 0xe0;
            uVar13 = 0xbaa;
            goto LAB_00482d24;
          }
          (*(code *)PTR_memset_006a99f4)(auStack_3cc,0,0x82);
          uVar6 = (*pcVar21)(piVar11,*(undefined4 *)(piVar11[0x30] + 0x8c),auStack_3cc,0x81,
                             auStack_348,0x204);
          if (0x100 < uVar6) {
            uVar15 = 0x44;
            uVar13 = 0xbb5;
LAB_00482ea0:
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar15,"s3_clnt.c",uVar13);
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_3cc,0x82);
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_348,0x204);
            ssl3_send_alert(piVar11,2,0x28);
            goto LAB_00482d38;
          }
          if (uVar6 == 0) {
            uVar15 = 0xdf;
            uVar13 = 0xbb9;
            goto LAB_00482ea0;
          }
          uStack_34b = 0;
          uVar10 = (*(code *)PTR_strlen_006a9a24)(auStack_3cc);
          if (0x80 < uVar10) {
            uVar15 = 0x44;
            uVar13 = 0xbc0;
            goto LAB_00482ea0;
          }
          (*(code *)PTR_memmove_006a9af4)(auStack_348 + uVar6 + 4,auStack_348,uVar6);
          uVar22 = (undefined)(uVar6 >> 8);
          auStack_348[0] = uVar22;
          auStack_348[1] = (char)uVar6;
          (*(code *)PTR___memset_chk_006a998c)(auStack_348 + 2,0,uVar6,0x202);
          iVar4 = piVar11[0x30];
          (auStack_348 + 2)[uVar6] = uVar22;
          auStack_348[uVar6 + 3] = (char)uVar6;
          if (*(int *)(iVar4 + 0x8c) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            iVar4 = piVar11[0x30];
          }
          uVar13 = (*(code *)PTR_BUF_strdup_006a6fdc)(*(undefined4 *)(piVar11[0x39] + 0x14c));
          iVar19 = piVar11[0x39];
          iVar17 = piVar11[0x30];
          *(undefined4 *)(iVar4 + 0x8c) = uVar13;
          if ((*(int *)(iVar19 + 0x14c) != 0) && (*(int *)(iVar17 + 0x8c) == 0)) {
            uVar15 = 0x41;
            uVar13 = 0xbd3;
            goto LAB_00482ea0;
          }
          if (*(int *)(iVar17 + 0x90) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            iVar17 = piVar11[0x30];
          }
          uVar13 = (*(code *)PTR_BUF_strdup_006a6fdc)(auStack_3cc);
          iVar4 = piVar11[0x30];
          *(undefined4 *)(iVar17 + 0x90) = uVar13;
          if (*(int *)(iVar4 + 0x90) == 0) {
            uVar15 = 0x41;
            uVar13 = 0xbdc;
            goto LAB_00482ea0;
          }
          iVar17 = uVar10 + 2;
          uVar13 = (**(code **)(*(int *)(piVar11[2] + 100) + 0xc))
                             (piVar11,iVar4 + 0x14,auStack_348,uVar6 * 2 + 4);
          *(undefined4 *)(iVar4 + 0x10) = uVar13;
          puVar18[5] = (char)uVar10;
          puVar16 = PTR_memcpy_006a9aec;
          puVar18[4] = 0;
          (*(code *)puVar16)(puVar18 + 6,auStack_3cc,uVar10);
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_3cc,0x82);
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_348,0x204);
        }
        else {
          if (piVar11[0x6e] == 0) {
            uVar15 = 0x44;
            uVar13 = 0xb83;
            goto LAB_00482d24;
          }
          iVar19 = (*(code *)PTR_BN_num_bits_006a71f4)();
          puVar16 = PTR_BN_bn2bin_006a7200;
          iVar4 = iVar19 + 7;
          if (iVar19 + 7 < 0) {
            iVar4 = iVar19 + 0xe;
          }
          iVar17 = (iVar4 >> 3) + 2;
          puVar18[5] = (char)(iVar4 >> 3);
          puVar18[4] = (char)(iVar4 >> 0xb);
          (*(code *)puVar16)(piVar11[0x6e],puVar18 + 6);
          iVar4 = piVar11[0x30];
          if (*(int *)(iVar4 + 0xf0) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
            iVar4 = piVar11[0x30];
          }
          uVar13 = (*(code *)PTR_BUF_strdup_006a6fdc)(piVar11[0x69]);
          iVar19 = piVar11[0x30];
          *(undefined4 *)(iVar4 + 0xf0) = uVar13;
          if (*(int *)(iVar19 + 0xf0) == 0) {
            uVar15 = 0x41;
            uVar13 = 0xb8b;
            goto LAB_00482d24;
          }
          iVar4 = (*(code *)PTR_SRP_generate_client_master_secret_006a808c)(piVar11,iVar19 + 0x14);
          *(int *)(iVar19 + 0x10) = iVar4;
          if (iVar4 < 0) {
            uVar15 = 0x44;
            uVar13 = 0xb94;
            goto LAB_00482d24;
          }
        }
      }
      else {
        if ((*(int *)(*(int *)(piVar11[0x30] + 0x98) + 0x60) == 0) &&
           (*(int *)(*(int *)(piVar11[0x30] + 0x98) + 0x54) == 0)) {
          uVar15 = 0x14a;
          uVar13 = 0xb24;
          goto LAB_00482d24;
        }
        uVar13 = (*(code *)PTR_X509_get_pubkey_006a6f08)();
        iVar4 = (*(code *)PTR_EVP_PKEY_CTX_new_006a6fe0)(uVar13,0);
        if (iVar4 == 0) {
          uVar15 = 0x41;
          uVar13 = 0xb2c;
          goto LAB_00482d24;
        }
        iVar19 = (*(code *)PTR_EVP_PKEY_encrypt_init_006a7cec)(iVar4);
        if (iVar19 < 1) {
LAB_00483224:
          (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar4);
          uVar15 = 0x44;
          uVar13 = 0xb3e;
          goto LAB_00482d24;
        }
        iVar19 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_3ec,0x20);
        if (iVar19 < 1) goto LAB_00483224;
        uVar15 = (*(code *)PTR_EVP_MD_CTX_create_006a8084)();
        uVar9 = (*(code *)PTR_OBJ_nid2sn_006a709c)(0x329);
        uVar9 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar9);
        iVar19 = (*(code *)PTR_EVP_DigestInit_006a7e40)(uVar15,uVar9);
        if (((iVar19 < 1) ||
            (iVar19 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(uVar15,piVar11[0x16] + 0xc0,0x20),
            iVar19 < 1)) ||
           (iVar19 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(uVar15,piVar11[0x16] + 0xa0,0x20),
           iVar19 < 1)) {
LAB_004831a8:
          (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(uVar15);
          uVar15 = 0x44;
          uVar13 = 0xb4f;
          goto LAB_00482d24;
        }
        iVar19 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(uVar15,auStack_3cc,auStack_3f0);
        if (iVar19 < 1) goto LAB_004831a8;
        (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(uVar15);
        iVar19 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(iVar4,0xffffffff,0x100,8,8,auStack_3cc);
        puVar16 = PTR_EVP_PKEY_encrypt_006a7d14;
        if (iVar19 < 0) {
          uVar15 = 0x112;
          uVar13 = 0xb57;
          goto LAB_00482d24;
        }
        puVar18[4] = 0x30;
        uStack_3f4 = 0xff;
        iVar19 = (*(code *)puVar16)(iVar4,auStack_348,&uStack_3f4,auStack_3ec,0x20);
        if (iVar19 < 1) {
          uVar15 = 0x112;
          uVar13 = 0xb63;
          goto LAB_00482d24;
        }
        uVar22 = (undefined)uStack_3f4;
        if (uStack_3f4 < 0x80) {
          puVar16 = puVar18 + 6;
          iVar17 = uStack_3f4 + 2;
        }
        else {
          puVar16 = puVar18 + 7;
          puVar18[6] = uVar22;
          iVar17 = uStack_3f4 + 3;
          uVar22 = 0x81;
        }
        puVar2 = PTR_memcpy_006a9aec;
        puVar18[5] = uVar22;
        (*(code *)puVar2)(puVar16,auStack_348);
        (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar4);
        iVar4 = piVar11[0x30];
        uVar15 = (**(code **)(*(int *)(piVar11[2] + 100) + 0xc))
                           (piVar11,iVar4 + 0x14,auStack_3ec,0x20);
        puVar16 = PTR_EVP_PKEY_free_006a6e78;
        *(undefined4 *)(iVar4 + 0x10) = uVar15;
        (*(code *)puVar16)(uVar13);
      }
    }
    else {
      if (*(int *)(piVar11[0x30] + 0x98) == 0) {
        ssl3_send_alert();
        uVar15 = 0xf4;
        uVar13 = 0xa22;
        goto LAB_00482d24;
      }
      iVar4 = *(int *)(*(int *)(piVar11[0x30] + 0x98) + 0x70);
      if (iVar4 == 0) {
        ssl3_send_alert();
        uVar15 = 0xee;
        uVar13 = 0xa2c;
        goto LAB_00482d24;
      }
      iVar19 = (*(code *)PTR_DHparams_dup_006a7f8c)(iVar4);
      if (iVar19 == 0) {
        uVar15 = 5;
        uVar13 = 0xa32;
        goto LAB_00482d24;
      }
      iVar17 = (*(code *)PTR_DH_generate_key_006a7f90)(iVar19);
      if (iVar17 == 0) {
        uVar13 = 0xa36;
LAB_00482f78:
        piVar20 = (int *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,5,"s3_clnt.c",uVar13);
        (*(code *)PTR_DH_free_006a7508)(iVar19);
        goto LAB_00482d3c;
      }
      iVar4 = (*(code *)PTR_DH_compute_key_006a7fa4)(puVar16,*(undefined4 *)(iVar4 + 0x14),iVar19);
      if (iVar4 < 1) {
        uVar13 = 0xa43;
        goto LAB_00482f78;
      }
      iVar17 = piVar11[0x30];
      uVar13 = (**(code **)(*(int *)(piVar11[2] + 100) + 0xc))(piVar11,iVar17 + 0x14,puVar16,iVar4);
      puVar2 = PTR_memset_006a99f4;
      *(undefined4 *)(iVar17 + 0x10) = uVar13;
      (*(code *)puVar2)(puVar16,0,iVar4);
      iVar17 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar19 + 0x14));
      puVar16 = PTR_BN_bn2bin_006a7200;
      iVar4 = iVar17 + 7;
      if (iVar17 + 7 < 0) {
        iVar4 = iVar17 + 0xe;
      }
      iVar17 = (iVar4 >> 3) + 2;
      puVar18[5] = (char)(iVar4 >> 3);
      puVar18[4] = (char)(iVar4 >> 0xb);
      (*(code *)puVar16)(*(undefined4 *)(iVar19 + 0x14),puVar18 + 6);
      (*(code *)PTR_DH_free_006a7508)(iVar19);
    }
  }
  else {
    iVar4 = *(int *)(piVar11[0x30] + 0x98);
    if (iVar4 == 0) {
      uVar15 = 0x44;
      uVar13 = 0x95b;
      goto LAB_00482d24;
    }
    iVar19 = *(int *)(iVar4 + 0x6c);
    if (iVar19 == 0) {
      piVar20 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)(*(undefined4 *)(iVar4 + 0xc));
      if (((piVar20 == (int *)0x0) || (*piVar20 != 6)) || (iVar19 = piVar20[5], iVar19 == 0)) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,0x44,"s3_clnt.c",0x969);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar20);
        goto LAB_00482d38;
      }
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar20);
    }
    auStack_348[1] = (undefined)piVar11[0x44];
    auStack_348[0] = (undefined)((uint)piVar11[0x44] >> 8);
    iVar4 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_348 + 2,0x2e);
    puVar2 = PTR_RSA_public_encrypt_006a7654;
    if (iVar4 < 1) goto LAB_00482d38;
    puVar14 = puVar18 + 6;
    if (*piVar11 < 0x301) {
      puVar14 = puVar16;
    }
    *(undefined4 *)(piVar11[0x30] + 0x10) = 0x30;
    iVar4 = (*(code *)puVar2)(0x30,auStack_348,puVar14,iVar19,1);
    if (iVar4 < 1) {
      uVar15 = 0x77;
      uVar13 = 0x986;
      goto LAB_00482d24;
    }
    iVar17 = iVar4;
    if (0x300 < *piVar11) {
      puVar18[5] = (char)iVar4;
      iVar17 = iVar4 + 2;
      puVar18[4] = (char)((uint)iVar4 >> 8);
    }
    iVar4 = piVar11[0x30];
    uVar13 = (**(code **)(*(int *)(piVar11[2] + 100) + 0xc))(piVar11,iVar4 + 0x14,auStack_348,0x30);
    puVar16 = PTR_OPENSSL_cleanse_006a7074;
    *(undefined4 *)(iVar4 + 0x10) = uVar13;
    (*(code *)puVar16)(auStack_348,0x30);
  }
LAB_00482658:
  puVar18[3] = (char)iVar17;
  puVar18[2] = (char)((uint)iVar17 >> 8);
  puVar18[1] = (char)((uint)iVar17 >> 0x10);
  *puVar18 = 0x10;
  piVar11[0x11] = iVar17 + 4;
  piVar11[0xd] = 0x1181;
  piVar11[0x12] = 0;
LAB_0048268c:
  puVar5 = (ushort *)ssl3_do_write(piVar11,0x16);
  while (iStack_144 != *(int *)puVar3) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004833a8:
    ssl3_send_alert();
    uVar15 = 0x44;
    uVar13 = 0xbf5;
LAB_00482d24:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x98,uVar15,"s3_clnt.c",uVar13);
LAB_00482d38:
    piVar20 = (int *)0x0;
LAB_00482d3c:
    (*(code *)PTR_BN_CTX_free_006a7954)(0);
LAB_00482d4c:
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar20);
    puVar5 = (ushort *)0xffffffff;
    piVar11[0xd] = 5;
  }
  return puVar5;
}

