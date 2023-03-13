
/* WARNING: Could not reconcile some variable overlaps */

uint * CRYPTO_ccm128_encrypt_ccm64
                 (code *param_1,uint *param_2,uint *param_3,uint *param_4,undefined4 *param_5)

{
  code cVar1;
  byte bVar2;
  code cVar3;
  byte bVar4;
  ushort uVar5;
  uint3 uVar6;
  undefined *puVar7;
  code *pcVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  byte bVar12;
  int iVar13;
  uint *puVar14;
  uint uVar15;
  byte *pbVar16;
  int iVar17;
  uint *puVar18;
  byte *pbVar19;
  uint *puVar20;
  uint *puVar21;
  uint uVar22;
  uint *puVar23;
  code *pcVar24;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  byte *pbStack_a4;
  code *pcStack_a0;
  uint *puStack_9c;
  undefined *puStack_98;
  uint uStack_94;
  uint *puStack_90;
  uint uStack_8c;
  uint *puStack_88;
  uint *puStack_84;
  undefined4 *puStack_80;
  code *pcStack_7c;
  code *local_68;
  uint *local_64;
  undefined *local_60;
  code *local_54;
  uint *local_50;
  uint *local_4c;
  uint *local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  byte *local_2c;
  
  puStack_98 = PTR___stack_chk_guard_006a9ae8;
  local_54 = *(code **)(param_1 + 0x28);
  local_60 = &_gp;
  cVar1 = *param_1;
  uStack_94 = (uint)(byte)cVar1;
  puStack_9c = *(uint **)(param_1 + 0x2c);
  local_2c = *(byte **)PTR___stack_chk_guard_006a9ae8;
  puVar18 = param_2;
  puVar21 = param_3;
  if (((byte)cVar1 & 0x40) == 0) {
    puVar18 = (uint *)(param_1 + 0x10);
    puVar21 = puStack_9c;
    local_50 = param_4;
    (*local_54)();
    uVar9 = *(uint *)(param_1 + 0x24);
    uVar15 = uVar9 + 1;
    *(uint *)(param_1 + 0x24) = uVar15;
    *(uint *)(param_1 + 0x20) = (uint)(uVar15 < uVar9) + *(int *)(param_1 + 0x20);
    param_4 = local_50;
  }
  uStack_8c = uStack_94 & 7;
  puVar23 = (uint *)(0xf - uStack_8c);
  *param_1 = SUB41(uStack_8c,0);
  if (puVar23 == (uint *)&DAT_0000000f) {
    uVar9 = 0;
  }
  else {
    puVar18 = (uint *)(param_1 + (int)puVar23);
    bVar2 = *(byte *)puVar18;
    *(byte *)puVar18 = 0;
    uVar9 = (uint)bVar2 << 8;
    if (0x10 - uStack_8c != 0xf) {
      cVar3 = param_1[0x10 - uStack_8c];
      puVar21 = (uint *)(uint)(byte)cVar3;
      puVar18 = (uint *)(0x11 - uStack_8c);
      param_1[0x10 - uStack_8c] = (code)0x0;
      uVar5 = CONCAT11(bVar2,cVar3);
      uVar9 = (uint)uVar5 << 8;
      if (puVar18 != (uint *)&DAT_0000000f) {
        puVar18 = (uint *)(param_1 + (int)puVar18);
        bVar2 = *(byte *)puVar18;
        puVar21 = (uint *)(uint)bVar2;
        *(byte *)puVar18 = 0;
        uVar6 = CONCAT21(uVar5,bVar2);
        uVar9 = (uint)uVar6 << 8;
        if (0x12 - uStack_8c != 0xf) {
          cVar3 = param_1[0x12 - uStack_8c];
          puVar21 = (uint *)(uint)(byte)cVar3;
          puVar18 = (uint *)(0x13 - uStack_8c);
          param_1[0x12 - uStack_8c] = (code)0x0;
          uVar9 = CONCAT31(uVar6,cVar3) << 8;
          if (puVar18 != (uint *)&DAT_0000000f) {
            puVar18 = (uint *)(param_1 + (int)puVar18);
            puVar21 = (uint *)(uint)*(byte *)puVar18;
            *(byte *)puVar18 = 0;
            uVar9 = ((uint)puVar21 | uVar9) << 8;
            if (0x14 - uStack_8c != 0xf) {
              puVar21 = (uint *)(uint)(byte)param_1[0x14 - uStack_8c];
              puVar18 = (uint *)(0x15 - uStack_8c);
              param_1[0x14 - uStack_8c] = (code)0x0;
              uVar9 = ((uint)puVar21 | uVar9) << 8;
              if (puVar18 != (uint *)&DAT_0000000f) {
                cVar3 = param_1[0xe];
                param_1[0xe] = (code)0x0;
                uVar9 = ((byte)cVar3 | uVar9) << 8;
              }
            }
          }
        }
      }
    }
  }
  puStack_90 = (uint *)((byte)param_1[0xf] | uVar9);
  param_1[0xf] = (code)0x1;
  if (puStack_90 == param_4) {
    puVar21 = (uint *)0x20000000;
    puVar18 = (uint *)0x20000001;
    uVar15 = (uint)((int)param_4 + 0xf) >> 3 | 1;
    uVar9 = uVar15 + *(int *)(param_1 + 0x24);
    uVar15 = (uint)(uVar9 < uVar15) + *(int *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x24) = uVar9;
    *(uint *)(param_1 + 0x20) = uVar15;
    if ((uVar15 < 0x20000001) && ((uVar15 != 0x20000000 || (uVar9 == 0)))) {
      puVar21 = (uint *)((uint)puStack_90 >> 4);
      puVar18 = (uint *)(param_1 + 0x10);
      if (puVar21 == (uint *)0x0) {
        if (puStack_90 != (uint *)0x0) goto LAB_005ec7b4;
      }
      else {
        local_68 = param_1;
        local_64 = puVar18;
        local_50 = puVar21;
        local_4c = puVar18;
        local_48 = puVar23;
        (*(code *)param_5)(param_2,param_3,puVar21,puStack_9c);
        uVar9 = (int)local_50 * 0x10;
        puStack_90 = puStack_90 + (int)local_50 * -4;
        param_2 = param_2 + (int)local_50 * 4;
        param_3 = param_3 + (int)local_50 * 4;
        puVar23 = local_48;
        if (puStack_90 == (uint *)0x0) goto LAB_005eca90;
        uVar15 = (uint)(byte)param_1[0xf] + ((uint)local_50 & 0xff);
        uVar22 = uVar15 >> 8;
        param_1[0xf] = SUB41(uVar15,0);
        puVar18 = local_4c;
        if (uVar9 >> 0xc == 0) {
          if (uVar22 == 0) goto LAB_005ec7b4;
          uVar22 = (byte)param_1[0xe] + 1 >> 8;
          param_1[0xe] = SUB41((byte)param_1[0xe] + 1,0);
LAB_005ecbb0:
          if (uVar22 == 0) goto LAB_005ec7b4;
          uVar22 = (byte)param_1[0xd] + 1 >> 8;
          param_1[0xd] = SUB41((byte)param_1[0xd] + 1,0);
LAB_005ecbc8:
          if (uVar22 == 0) goto LAB_005ec7b4;
          uVar9 = (byte)param_1[0xc] + 1;
          param_1[0xc] = SUB41(uVar9,0);
        }
        else {
          uVar15 = (uint)(byte)param_1[0xe] + (uVar9 >> 0xc & 0xff) + uVar22;
          uVar22 = uVar15 >> 8;
          param_1[0xe] = SUB41(uVar15,0);
          if (uVar9 >> 0x14 == 0) goto LAB_005ecbb0;
          uVar15 = (uint)(byte)param_1[0xd] + (uVar9 >> 0x14 & 0xff) + uVar22;
          uVar22 = uVar15 >> 8;
          param_1[0xd] = SUB41(uVar15,0);
          if (uVar9 >> 0x1c == 0) goto LAB_005ecbc8;
          uVar9 = (uint)(byte)param_1[0xc] + (uVar9 >> 0x1c) + uVar22;
          param_1[0xc] = SUB41(uVar9,0);
        }
        if ((((uVar9 >> 8 != 0) &&
             (cVar3 = param_1[0xb], param_1[0xb] = SUB41((byte)cVar3 + 1,0),
             (byte)cVar3 + 1 >> 8 != 0)) &&
            (cVar3 = param_1[10], param_1[10] = SUB41((byte)cVar3 + 1,0), (byte)cVar3 + 1 >> 8 != 0)
            ) && (cVar3 = param_1[9], param_1[9] = SUB41((byte)cVar3 + 1,0),
                 (byte)cVar3 + 1 >> 8 != 0)) {
          param_1[8] = (code)((char)param_1[8] + 1);
        }
LAB_005ec7b4:
        local_48 = param_2 + 1;
        local_44 = (uint)(puStack_90 < &DAT_00000006);
        local_4c = (uint *)(local_44 ^ 1);
        if ((((uint)local_4c & (param_2 < param_1 + 0x14 ^ 1 | puVar18 < local_48 ^ 1)) == 0) ||
           (((uint)param_2 & 3) != 0)) {
          param_1[0x10] = (code)((byte)param_1[0x10] ^ *(byte *)param_2);
          if (((((puStack_90 != (uint *)0x1) &&
                ((param_1[0x11] = (code)((byte)param_1[0x11] ^ *(byte *)((int)param_2 + 1)),
                 puStack_90 != (uint *)&SUB_00000002 &&
                 (param_1[0x12] = (code)((byte)param_1[0x12] ^ *(byte *)((int)param_2 + 2)),
                 puStack_90 != (uint *)0x3)))) &&
               (param_1[0x13] = (code)((byte)param_1[0x13] ^ *(byte *)((int)param_2 + 3)),
               puStack_90 != (uint *)&SUB_00000004)) &&
              (((((param_1[0x14] = (code)((byte)param_1[0x14] ^ *(byte *)(param_2 + 1)),
                  local_44 == 0 &&
                  (param_1[0x15] = (code)((byte)param_1[0x15] ^ *(byte *)((int)param_2 + 5)),
                  &DAT_00000006 < puStack_90)) &&
                 (param_1[0x16] = (code)((byte)param_1[0x16] ^ *(byte *)((int)param_2 + 6)),
                 puStack_90 != (uint *)&DAT_00000007)) &&
                ((param_1[0x17] = (code)((byte)param_1[0x17] ^ *(byte *)((int)param_2 + 7)),
                 puStack_90 != (uint *)&DAT_00000008 &&
                 (param_1[0x18] = (code)((byte)param_1[0x18] ^ *(byte *)(param_2 + 2)),
                 puStack_90 != (uint *)&DAT_00000009)))) &&
               (param_1[0x19] = (code)((byte)param_1[0x19] ^ *(byte *)((int)param_2 + 9)),
               puStack_90 != (uint *)&DAT_0000000a)))) &&
             (((param_1[0x1a] = (code)((byte)param_1[0x1a] ^ *(byte *)((int)param_2 + 10)),
               puStack_90 != (uint *)&DAT_0000000b &&
               (param_1[0x1b] = (code)((byte)param_1[0x1b] ^ *(byte *)((int)param_2 + 0xb)),
               puStack_90 != (uint *)&SUB_0000000c)) &&
              ((param_1[0x1c] = (code)((byte)param_1[0x1c] ^ *(byte *)(param_2 + 3)),
               puStack_90 != (uint *)&DAT_0000000d &&
               ((param_1[0x1d] = (code)((byte)param_1[0x1d] ^ *(byte *)((int)param_2 + 0xd)),
                puStack_90 != (uint *)&DAT_0000000e &&
                (param_1[0x1e] = (code)((byte)param_1[0x1e] ^ *(byte *)((int)param_2 + 0xe)),
                puStack_90 != (uint *)&DAT_0000000f)))))))) {
            param_1[0x1f] = (code)((byte)param_1[0x1f] ^ *(byte *)((int)param_2 + 0xf));
          }
        }
        else {
          puVar21 = (uint *)0x1;
          if (puStack_90 != (uint *)0x0) {
            puVar21 = puStack_90;
          }
          iVar13 = ((uint)(puVar21 + -1) >> 2) + 1;
          puVar10 = (uint *)(iVar13 * 4);
          if (puStack_90 < &SUB_00000004) {
            puVar10 = (uint *)0x0;
          }
          else {
            *(uint *)(param_1 + 0x10) = *param_2 ^ *(uint *)(param_1 + 0x10);
            if (((iVar13 != 1) &&
                (*(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ param_2[1], iVar13 != 2))
               && (*(uint *)(param_1 + 0x18) = param_2[2] ^ *(uint *)(param_1 + 0x18), iVar13 != 3))
            {
              *(uint *)(param_1 + 0x1c) = param_2[3] ^ *(uint *)(param_1 + 0x1c);
            }
            if (puVar21 == puVar10) goto LAB_005ec8c8;
          }
          puVar21 = (uint *)((int)puVar10 + 1);
          (param_1 + (int)puVar10)[0x10] =
               (code)(*(byte *)((int)param_2 + (int)puVar10) ^ (byte)(param_1 + (int)puVar10)[0x10])
          ;
          if (puVar21 < puStack_90) {
            puVar10 = (uint *)((int)puVar10 + 2);
            (param_1 + (int)puVar21)[0x10] =
                 (code)(*(byte *)((int)param_2 + (int)puVar21) ^
                       (byte)(param_1 + (int)puVar21)[0x10]);
            if (puVar10 < puStack_90) {
              (param_1 + (int)puVar10)[0x10] =
                   (code)(*(byte *)((int)param_2 + (int)puVar10) ^
                         (byte)(param_1 + (int)puVar10)[0x10]);
            }
          }
        }
LAB_005ec8c8:
        local_50 = puVar23;
        (*local_54)(puVar18,puVar18,puStack_9c);
        (*local_54)(param_1,&local_40,puStack_9c);
        puVar23 = local_50;
        if ((((uint)local_4c & (param_2 < param_3 + 1 ^ 1 | param_3 < local_48 ^ 1)) == 0) ||
           ((((uint)param_3 | (uint)param_2) & 3) != 0)) {
          *(byte *)param_3 = local_40._0_1_ ^ *(byte *)param_2;
          if (puStack_90 != (uint *)0x1) {
            *(byte *)((int)param_3 + 1) = local_40._1_1_ ^ *(byte *)((int)param_2 + 1);
            if (puStack_90 != (uint *)&SUB_00000002) {
              *(byte *)((int)param_3 + 2) = local_40._2_1_ ^ *(byte *)((int)param_2 + 2);
              if (puStack_90 != (uint *)0x3) {
                *(byte *)((int)param_3 + 3) = (byte)local_40 ^ *(byte *)((int)param_2 + 3);
                if (puStack_90 != (uint *)&SUB_00000004) {
                  *(byte *)(param_3 + 1) = local_3c._0_1_ ^ *(byte *)(param_2 + 1);
                  if (local_44 == 0) {
                    *(byte *)((int)param_3 + 5) = local_3c._1_1_ ^ *(byte *)((int)param_2 + 5);
                    if (&DAT_00000006 < puStack_90) {
                      *(byte *)((int)param_3 + 6) = local_3c._2_1_ ^ *(byte *)((int)param_2 + 6);
                      if (puStack_90 != (uint *)&DAT_00000007) {
                        *(byte *)((int)param_3 + 7) = (byte)local_3c ^ *(byte *)((int)param_2 + 7);
                        if (puStack_90 != (uint *)&DAT_00000008) {
                          *(byte *)(param_3 + 2) = local_38._0_1_ ^ *(byte *)(param_2 + 2);
                          if (puStack_90 != (uint *)&DAT_00000009) {
                            *(byte *)((int)param_3 + 9) =
                                 local_38._1_1_ ^ *(byte *)((int)param_2 + 9);
                            if (puStack_90 != (uint *)&DAT_0000000a) {
                              *(byte *)((int)param_3 + 10) =
                                   local_38._2_1_ ^ *(byte *)((int)param_2 + 10);
                              if (puStack_90 != (uint *)&DAT_0000000b) {
                                *(byte *)((int)param_3 + 0xb) =
                                     (byte)local_38 ^ *(byte *)((int)param_2 + 0xb);
                                if (puStack_90 != (uint *)&SUB_0000000c) {
                                  *(byte *)(param_3 + 3) = local_34._0_1_ ^ *(byte *)(param_2 + 3);
                                  if (puStack_90 != (uint *)&DAT_0000000d) {
                                    *(byte *)((int)param_3 + 0xd) =
                                         local_34._1_1_ ^ *(byte *)((int)param_2 + 0xd);
                                    if (puStack_90 != (uint *)&DAT_0000000e) {
                                      *(byte *)((int)param_3 + 0xe) =
                                           local_34._2_1_ ^ *(byte *)((int)param_2 + 0xe);
                                      if (puStack_90 != (uint *)&DAT_0000000f) {
                                        *(byte *)((int)param_3 + 0xf) =
                                             *(byte *)((int)param_2 + 0xf) ^ (byte)local_34;
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
          puVar18 = (uint *)0x1;
          if (puStack_90 != (uint *)0x0) {
            puVar18 = puStack_90;
          }
          iVar13 = ((uint)(puVar18 + -1) >> 2) + 1;
          puVar21 = (uint *)(iVar13 * 4);
          if (puStack_90 < (uint *)0x4) {
            puVar21 = (uint *)0x0;
            puVar18 = (uint *)0x1;
            *(byte *)param_3 = *(byte *)param_2 ^ local_40._0_1_;
            if ((uint *)0x1 < puStack_90) {
LAB_005ec9e8:
              puVar21 = (uint *)((int)puVar21 + 2);
              puStack_90 = (uint *)(uint)(puVar21 < puStack_90);
              *(byte *)((int)param_3 + (int)puVar18) =
                   *(byte *)((int)param_2 + (int)puVar18) ^ *(byte *)((int)&local_40 + (int)puVar18)
              ;
              if (puStack_90 != (uint *)0x0) {
                param_2 = (uint *)((int)param_2 + (int)puVar21);
                *(byte *)((int)param_3 + (int)puVar21) =
                     *(byte *)param_2 ^ *(byte *)((int)&local_40 + (int)puVar21);
              }
            }
          }
          else {
            *param_3 = *param_2 ^ local_40;
            if (((iVar13 != 1) && (param_3[1] = param_2[1] ^ local_3c, iVar13 != 2)) &&
               (param_3[2] = param_2[2] ^ (uint)local_38, iVar13 != 3)) {
              param_3[3] = param_2[3] ^ (uint)local_34;
            }
            if (puVar21 != puVar18) {
              puVar18 = (uint *)((int)puVar21 + 1);
              *(byte *)(param_3 + iVar13) =
                   *(byte *)(param_2 + iVar13) ^ *(byte *)(&local_40 + iVar13);
              if (puVar18 < puStack_90) goto LAB_005ec9e8;
            }
          }
        }
      }
LAB_005eca90:
      param_5 = &local_40;
      (**(code **)(local_60 + -0x53ec))(param_1 + (0xf - uStack_8c),0,0x10 - (int)puVar23);
      (*local_54)(param_1,param_5,puStack_9c);
      puVar23 = (uint *)0x0;
      puVar18 = (uint *)(*(uint *)(param_1 + 0x14) ^ local_3c);
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ local_40;
      *param_1 = cVar1;
      *(uint **)(param_1 + 0x14) = puVar18;
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ (uint)local_38;
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ (uint)local_34;
      puVar21 = local_34;
      param_4 = local_38;
    }
    else {
      puVar23 = (uint *)&SUB_fffffffe;
    }
  }
  else {
    puVar23 = (uint *)0xffffffff;
  }
  if (local_2c == *(byte **)puStack_98) {
    return puVar23;
  }
  pcStack_7c = CRYPTO_ccm128_decrypt_ccm64;
  pbVar16 = local_2c;
  (**(code **)(local_60 + -0x5330))();
  pcVar8 = local_68;
  puVar7 = PTR___stack_chk_guard_006a9ae8;
  bVar2 = *pbVar16;
  pcVar24 = *(code **)(pbVar16 + 0x28);
  pbStack_a4 = *(byte **)PTR___stack_chk_guard_006a9ae8;
  puVar10 = *(uint **)(pbVar16 + 0x2c);
  pbVar19 = pbVar16 + 0x10;
  puVar23 = puVar21;
  pcStack_a0 = param_1;
  puStack_88 = param_2;
  puStack_84 = param_3;
  puStack_80 = param_5;
  if ((bVar2 & 0x40) == 0) {
    puVar23 = puVar10;
    (*pcVar24)();
  }
  uVar9 = bVar2 & 7;
  iVar13 = 0xf - uVar9;
  *pbVar16 = (byte)uVar9;
  if (iVar13 == 0xf) {
    uVar15 = 0;
  }
  else {
    pbVar19 = pbVar16 + iVar13;
    bVar12 = *pbVar19;
    *pbVar19 = 0;
    uVar15 = (uint)bVar12 << 8;
    if (0x10 - uVar9 != 0xf) {
      bVar4 = pbVar16[0x10 - uVar9];
      puVar23 = (uint *)(uint)bVar4;
      pbVar19 = (byte *)(0x11 - uVar9);
      pbVar16[0x10 - uVar9] = 0;
      uVar5 = CONCAT11(bVar12,bVar4);
      uVar15 = (uint)uVar5 << 8;
      if (pbVar19 != &DAT_0000000f) {
        pbVar19 = pbVar16 + (int)pbVar19;
        bVar12 = *pbVar19;
        puVar23 = (uint *)(uint)bVar12;
        *pbVar19 = 0;
        uVar6 = CONCAT21(uVar5,bVar12);
        uVar15 = (uint)uVar6 << 8;
        if (0x12 - uVar9 != 0xf) {
          bVar12 = pbVar16[0x12 - uVar9];
          puVar23 = (uint *)(uint)bVar12;
          pbVar19 = (byte *)(0x13 - uVar9);
          pbVar16[0x12 - uVar9] = 0;
          uVar15 = CONCAT31(uVar6,bVar12) << 8;
          if (pbVar19 != &DAT_0000000f) {
            pbVar19 = pbVar16 + (int)pbVar19;
            puVar23 = (uint *)(uint)*pbVar19;
            *pbVar19 = 0;
            uVar15 = ((uint)puVar23 | uVar15) << 8;
            if (0x14 - uVar9 != 0xf) {
              puVar23 = (uint *)(uint)pbVar16[0x14 - uVar9];
              pbVar19 = (byte *)(0x15 - uVar9);
              pbVar16[0x14 - uVar9] = 0;
              uVar15 = ((uint)puVar23 | uVar15) << 8;
              if (pbVar19 != &DAT_0000000f) {
                bVar12 = pbVar16[0xe];
                pbVar16[0xe] = 0;
                uVar15 = (bVar12 | uVar15) << 8;
              }
            }
          }
        }
      }
    }
  }
  puVar11 = (uint *)(pbVar16[0xf] | uVar15);
  pbVar16[0xf] = 1;
  if (puVar11 != param_4) {
    puVar18 = (uint *)0xffffffff;
    goto LAB_005ed1e0;
  }
  uVar15 = (uint)param_4 >> 4;
  puVar23 = (uint *)(pbVar16 + 0x10);
  if (uVar15 == 0) {
    if (param_4 != (uint *)0x0) goto LAB_005ed344;
  }
  else {
    (*pcVar8)(puVar18,puVar21,uVar15,puVar10,pbVar16,puVar23);
    puVar11 = param_4 + uVar15 * -4;
    puVar18 = (uint *)((int)puVar18 + ((uint)param_4 & 0xfffffff0));
    puVar21 = (uint *)((int)puVar21 + ((uint)param_4 & 0xfffffff0));
    if (puVar11 == (uint *)0x0) goto LAB_005ed164;
    uVar15 = (uVar15 & 0xff) + (uint)pbVar16[0xf];
    uVar22 = uVar15 >> 8;
    pbVar16[0xf] = (byte)uVar15;
    if ((uint)param_4 >> 0xc == 0) {
      if (uVar22 == 0) goto LAB_005ed344;
      uVar22 = pbVar16[0xe] + 1 >> 8;
      pbVar16[0xe] = (byte)(pbVar16[0xe] + 1);
LAB_005ed2bc:
      if (uVar22 == 0) goto LAB_005ed344;
      uVar22 = pbVar16[0xd] + 1 >> 8;
      pbVar16[0xd] = (byte)(pbVar16[0xd] + 1);
LAB_005ed2d4:
      if (uVar22 == 0) goto LAB_005ed344;
      uVar15 = pbVar16[0xc] + 1;
      pbVar16[0xc] = (byte)uVar15;
    }
    else {
      uVar15 = (uint)pbVar16[0xe] + ((uint)param_4 >> 0xc & 0xff) + uVar22;
      uVar22 = uVar15 >> 8;
      pbVar16[0xe] = (byte)uVar15;
      if ((uint)param_4 >> 0x14 == 0) goto LAB_005ed2bc;
      uVar15 = (uint)pbVar16[0xd] + ((uint)param_4 >> 0x14 & 0xff) + uVar22;
      uVar22 = uVar15 >> 8;
      pbVar16[0xd] = (byte)uVar15;
      if ((uint)param_4 >> 0x1c == 0) goto LAB_005ed2d4;
      uVar15 = (uint)pbVar16[0xc] + ((uint)param_4 >> 0x1c) + uVar22;
      pbVar16[0xc] = (byte)uVar15;
    }
    if ((((uVar15 >> 8 != 0) &&
         (bVar12 = pbVar16[0xb], pbVar16[0xb] = (byte)(bVar12 + 1), bVar12 + 1 >> 8 != 0)) &&
        (bVar12 = pbVar16[10], pbVar16[10] = (byte)(bVar12 + 1), bVar12 + 1 >> 8 != 0)) &&
       (bVar12 = pbVar16[9], pbVar16[9] = (byte)(bVar12 + 1), bVar12 + 1 >> 8 != 0)) {
      pbVar16[8] = pbVar16[8] + 1;
    }
LAB_005ed344:
    (*pcVar24)(pbVar16,&uStack_b8,puVar10);
    if (((puVar11 < &DAT_00000005 ||
         (puVar23 < puVar21 + 1 && puVar21 < pbVar16 + 0x14 ||
         puVar23 < puVar18 + 1 && puVar18 < pbVar16 + 0x14)) ||
         puVar18 < puVar21 + 1 && puVar21 < puVar18 + 1) ||
       ((((uint)puVar21 | (uint)puVar18) & 3) != 0)) {
      bVar12 = *(byte *)puVar18;
      *(byte *)puVar21 = bVar12 ^ uStack_b8._0_1_;
      pbVar16[0x10] = bVar12 ^ uStack_b8._0_1_ ^ pbVar16[0x10];
      if (puVar11 != (uint *)0x1) {
        uStack_b8._1_1_ = uStack_b8._1_1_ ^ *(byte *)((int)puVar18 + 1);
        *(byte *)((int)puVar21 + 1) = uStack_b8._1_1_;
        pbVar16[0x11] = uStack_b8._1_1_ ^ pbVar16[0x11];
        if (puVar11 != (uint *)&SUB_00000002) {
          uStack_b8._2_1_ = uStack_b8._2_1_ ^ *(byte *)((int)puVar18 + 2);
          *(byte *)((int)puVar21 + 2) = uStack_b8._2_1_;
          pbVar16[0x12] = uStack_b8._2_1_ ^ pbVar16[0x12];
          if (puVar11 != (uint *)0x3) {
            uStack_b8._3_1_ = (byte)uStack_b8 ^ *(byte *)((int)puVar18 + 3);
            *(byte *)((int)puVar21 + 3) = (byte)uStack_b8;
            pbVar16[0x13] = (byte)uStack_b8 ^ pbVar16[0x13];
            if (puVar11 >= &DAT_00000005) {
              bVar12 = *(byte *)(puVar18 + 1);
              *(byte *)(puVar21 + 1) = uStack_b4._0_1_ ^ bVar12;
              pbVar16[0x14] = uStack_b4._0_1_ ^ bVar12 ^ pbVar16[0x14];
              if (&DAT_00000005 < puVar11) {
                uStack_b4._1_1_ = uStack_b4._1_1_ ^ *(byte *)((int)puVar18 + 5);
                *(byte *)((int)puVar21 + 5) = uStack_b4._1_1_;
                pbVar16[0x15] = uStack_b4._1_1_ ^ pbVar16[0x15];
                if (puVar11 != (uint *)&DAT_00000006) {
                  uStack_b4._2_1_ = uStack_b4._2_1_ ^ *(byte *)((int)puVar18 + 6);
                  *(byte *)((int)puVar21 + 6) = uStack_b4._2_1_;
                  pbVar16[0x16] = uStack_b4._2_1_ ^ pbVar16[0x16];
                  if (puVar11 != (uint *)&DAT_00000007) {
                    uStack_b4._3_1_ = (byte)uStack_b4 ^ *(byte *)((int)puVar18 + 7);
                    *(byte *)((int)puVar21 + 7) = (byte)uStack_b4;
                    pbVar16[0x17] = (byte)uStack_b4 ^ pbVar16[0x17];
                    if (puVar11 != (uint *)&DAT_00000008) {
                      bVar12 = *(byte *)(puVar18 + 2);
                      *(byte *)(puVar21 + 2) = uStack_b0._0_1_ ^ bVar12;
                      pbVar16[0x18] = uStack_b0._0_1_ ^ bVar12 ^ pbVar16[0x18];
                      if (puVar11 != (uint *)&DAT_00000009) {
                        uStack_b0._1_1_ = uStack_b0._1_1_ ^ *(byte *)((int)puVar18 + 9);
                        *(byte *)((int)puVar21 + 9) = uStack_b0._1_1_;
                        pbVar16[0x19] = uStack_b0._1_1_ ^ pbVar16[0x19];
                        if (puVar11 != (uint *)&DAT_0000000a) {
                          uStack_b0._2_1_ = uStack_b0._2_1_ ^ *(byte *)((int)puVar18 + 10);
                          *(byte *)((int)puVar21 + 10) = uStack_b0._2_1_;
                          pbVar16[0x1a] = uStack_b0._2_1_ ^ pbVar16[0x1a];
                          if (puVar11 != (uint *)&DAT_0000000b) {
                            uStack_b0._3_1_ = (byte)uStack_b0 ^ *(byte *)((int)puVar18 + 0xb);
                            *(byte *)((int)puVar21 + 0xb) = (byte)uStack_b0;
                            pbVar16[0x1b] = (byte)uStack_b0 ^ pbVar16[0x1b];
                            if (puVar11 != (uint *)&SUB_0000000c) {
                              bVar12 = *(byte *)(puVar18 + 3);
                              *(byte *)(puVar21 + 3) = uStack_ac._0_1_ ^ bVar12;
                              pbVar16[0x1c] = uStack_ac._0_1_ ^ bVar12 ^ pbVar16[0x1c];
                              if (puVar11 != (uint *)&DAT_0000000d) {
                                uStack_ac._1_1_ = uStack_ac._1_1_ ^ *(byte *)((int)puVar18 + 0xd);
                                *(byte *)((int)puVar21 + 0xd) = uStack_ac._1_1_;
                                pbVar16[0x1d] = uStack_ac._1_1_ ^ pbVar16[0x1d];
                                if (puVar11 != (uint *)&DAT_0000000e) {
                                  uStack_ac._2_1_ = uStack_ac._2_1_ ^ *(byte *)((int)puVar18 + 0xe);
                                  *(byte *)((int)puVar21 + 0xe) = uStack_ac._2_1_;
                                  pbVar16[0x1e] = uStack_ac._2_1_ ^ pbVar16[0x1e];
                                  if (puVar11 != (uint *)&DAT_0000000f) {
                                    uStack_ac._3_1_ =
                                         *(byte *)((int)puVar18 + 0xf) ^ (byte)uStack_ac;
                                    *(byte *)((int)puVar21 + 0xf) = (byte)uStack_ac;
                                    pbVar16[0x1f] = (byte)uStack_ac ^ pbVar16[0x1f];
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
      puVar20 = (uint *)0x1;
      if (puVar11 != (uint *)0x0) {
        puVar20 = puVar11;
      }
      iVar17 = ((uint)(puVar20 + -1) >> 2) + 1;
      puVar14 = (uint *)(iVar17 * 4);
      if (puVar11 < &SUB_00000004) {
        puVar14 = (uint *)0x0;
      }
      else {
        uVar15 = *puVar18;
        *puVar21 = uStack_b8 ^ uVar15;
        *(uint *)(pbVar16 + 0x10) = uStack_b8 ^ uVar15 ^ *(uint *)(pbVar16 + 0x10);
        if (iVar17 != 1) {
          uVar15 = puVar18[1];
          puVar21[1] = uVar15 ^ uStack_b4;
          *(uint *)(pbVar16 + 0x14) = uVar15 ^ uStack_b4 ^ *(uint *)(pbVar16 + 0x14);
          if (iVar17 != 2) {
            uVar15 = puVar18[2];
            puVar21[2] = uVar15 ^ uStack_b0;
            *(uint *)(pbVar16 + 0x18) = uVar15 ^ uStack_b0 ^ *(uint *)(pbVar16 + 0x18);
            if (iVar17 != 3) {
              uVar15 = puVar18[3];
              puVar21[3] = uVar15 ^ (uint)uStack_ac;
              *(uint *)(pbVar16 + 0x1c) = uVar15 ^ (uint)uStack_ac ^ *(uint *)(pbVar16 + 0x1c);
            }
          }
        }
        if (puVar14 == puVar20) goto LAB_005ed544;
      }
      puVar20 = (uint *)((int)puVar14 + 1);
      bVar12 = *(byte *)((int)puVar18 + (int)puVar14) ^ *(byte *)((int)&uStack_b8 + (int)puVar14);
      *(byte *)((int)puVar21 + (int)puVar14) = bVar12;
      (pbVar16 + (int)puVar14)[0x10] = bVar12 ^ (pbVar16 + (int)puVar14)[0x10];
      if (puVar20 < puVar11) {
        puVar14 = (uint *)((int)puVar14 + 2);
        bVar12 = *(byte *)((int)puVar18 + (int)puVar20) ^ *(byte *)((int)&uStack_b8 + (int)puVar20);
        *(byte *)((int)puVar21 + (int)puVar20) = bVar12;
        (pbVar16 + (int)puVar20)[0x10] = bVar12 ^ (pbVar16 + (int)puVar20)[0x10];
        if (puVar14 < puVar11) {
          bVar12 = *(byte *)((int)puVar18 + (int)puVar14) ^
                   *(byte *)((int)&uStack_b8 + (int)puVar14);
          *(byte *)((int)puVar21 + (int)puVar14) = bVar12;
          (pbVar16 + (int)puVar14)[0x10] = bVar12 ^ (pbVar16 + (int)puVar14)[0x10];
        }
      }
    }
LAB_005ed544:
    (*pcVar24)(puVar23,puVar23,puVar10);
  }
LAB_005ed164:
  (*(code *)PTR_memset_006a99f4)(pbVar16 + (0xf - uVar9),0,0x10 - iVar13);
  (*pcVar24)(pbVar16,&uStack_b8,puVar10);
  puVar18 = (uint *)0x0;
  pbVar19 = (byte *)(*(uint *)(pbVar16 + 0x14) ^ uStack_b4);
  *(uint *)(pbVar16 + 0x10) = *(uint *)(pbVar16 + 0x10) ^ uStack_b8;
  *pbVar16 = bVar2;
  *(byte **)(pbVar16 + 0x14) = pbVar19;
  *(uint *)(pbVar16 + 0x18) = *(uint *)(pbVar16 + 0x18) ^ uStack_b0;
  *(uint *)(pbVar16 + 0x1c) = *(uint *)(pbVar16 + 0x1c) ^ (uint)uStack_ac;
  puVar23 = uStack_ac;
LAB_005ed1e0:
  if (pbStack_a4 == *(byte **)puVar7) {
    return puVar18;
  }
  pbVar16 = pbStack_a4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar18 = (uint *)((((uint)*pbVar16 << 0x1a) >> 0x1d) * 2 + 2);
  if (puVar18 <= puVar23) {
    (*(code *)PTR_memcpy_006a9aec)(pbVar19,pbVar16 + 0x10,puVar18);
    return puVar18;
  }
  return (uint *)0x0;
}

