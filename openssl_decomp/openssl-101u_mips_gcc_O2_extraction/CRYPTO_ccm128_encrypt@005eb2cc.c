
/* WARNING: Could not reconcile some variable overlaps */

byte ** CRYPTO_ccm128_encrypt(byte *param_1,byte **param_2,byte **param_3,byte **param_4)

{
  undefined uVar1;
  code cVar2;
  code cVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  uint3 uVar9;
  undefined *puVar10;
  code *pcVar11;
  uint uVar12;
  byte **ppbVar13;
  int iVar14;
  byte **ppbVar15;
  byte **ppbVar16;
  byte bVar17;
  byte **ppbVar18;
  byte *pbVar19;
  byte **ppbVar20;
  byte **ppbVar21;
  char cVar24;
  byte bVar25;
  uint uVar22;
  int iVar23;
  byte *pbVar26;
  byte **ppbVar27;
  uint uVar28;
  byte **in_t0;
  byte **in_t1;
  byte **in_t2;
  byte *in_t3;
  byte **unaff_s0;
  byte **unaff_s3;
  uint unaff_s4;
  undefined4 *unaff_s5;
  code *pcVar29;
  byte **unaff_s6;
  byte **unaff_s7;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  byte *pbStack_19c;
  code *pcStack_198;
  byte **ppbStack_194;
  undefined *puStack_190;
  uint uStack_18c;
  byte **ppbStack_188;
  uint uStack_184;
  byte **ppbStack_180;
  byte **ppbStack_17c;
  undefined4 *puStack_178;
  code *pcStack_174;
  code *pcStack_160;
  byte **ppbStack_15c;
  undefined *puStack_158;
  code *pcStack_14c;
  byte **ppbStack_148;
  byte **ppbStack_144;
  byte **ppbStack_140;
  uint uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  byte *pbStack_124;
  byte **ppbStack_120;
  code *pcStack_11c;
  byte **ppbStack_118;
  byte **ppbStack_114;
  uint uStack_110;
  undefined4 *puStack_10c;
  byte **ppbStack_108;
  byte **ppbStack_104;
  byte **ppbStack_100;
  code *pcStack_fc;
  undefined4 *puStack_e8;
  byte **ppbStack_e0;
  byte **ppbStack_dc;
  byte **ppbStack_d8;
  undefined4 uStack_d4;
  code **ppcStack_d0;
  int iStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  code *pcStack_b4;
  byte **ppbStack_b0;
  byte **ppbStack_ac;
  uint uStack_a8;
  byte **ppbStack_a4;
  uint uStack_a0;
  undefined4 *puStack_9c;
  byte **ppbStack_98;
  byte **ppbStack_94;
  byte *pbStack_90;
  code *pcStack_8c;
  undefined *local_78;
  code *local_70;
  byte **local_6c;
  undefined4 *local_68;
  byte **local_64;
  byte **local_60;
  byte **local_5c;
  undefined4 local_58;
  undefined4 *local_54;
  uint local_50;
  int local_4c;
  byte **local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  byte **local_2c;
  
  local_78 = &_gp;
  local_70 = *(code **)(param_1 + 0x28);
  local_58 = (uint)*param_1;
  ppbStack_ac = *(byte ***)(param_1 + 0x2c);
  local_54 = (undefined4 *)PTR___stack_chk_guard_006a9ae8;
  ppbStack_dc = *(byte ***)PTR___stack_chk_guard_006a9ae8;
  ppbStack_d8 = param_3;
  local_60 = param_2;
  local_5c = param_3;
  local_2c = ppbStack_dc;
  if ((*param_1 & 0x40) == 0) {
    ppbStack_d8 = ppbStack_ac;
    local_6c = param_4;
    (*local_70)(param_1,param_1 + 0x10);
    uVar12 = *(uint *)(param_1 + 0x24);
    ppbStack_dc = *(byte ***)(param_1 + 0x20);
    uVar22 = uVar12 + 1;
    *(uint *)(param_1 + 0x24) = uVar22;
    *(undefined **)(param_1 + 0x20) = (undefined *)((uint)(uVar22 < uVar12) + (int)ppbStack_dc);
    param_4 = local_6c;
  }
  local_50 = local_58 & 7;
  local_4c = 0xf - local_50;
  *param_1 = (byte)local_50;
  if (local_4c == 0xf) {
    uVar12 = 0;
  }
  else {
    ppbStack_d8 = (byte **)(param_1 + local_4c);
    bVar25 = *(byte *)ppbStack_d8;
    ppbStack_dc = (byte **)(0x10 - local_50);
    *(undefined *)ppbStack_d8 = 0;
    uVar12 = (uint)bVar25 << 8;
    if (ppbStack_dc != (byte **)&DAT_0000000f) {
      ppbStack_dc = (byte **)(param_1 + (int)ppbStack_dc);
      uVar1 = *(undefined *)ppbStack_dc;
      ppbStack_d8 = (byte **)(0x11 - local_50);
      *(undefined *)ppbStack_dc = 0;
      uVar8 = CONCAT11(bVar25,uVar1);
      uVar12 = (uint)uVar8 << 8;
      if (ppbStack_d8 != (byte **)&DAT_0000000f) {
        ppbStack_d8 = (byte **)(param_1 + (int)ppbStack_d8);
        uVar1 = *(undefined *)ppbStack_d8;
        ppbStack_dc = (byte **)(0x12 - local_50);
        *(undefined *)ppbStack_d8 = 0;
        uVar9 = CONCAT21(uVar8,uVar1);
        uVar12 = (uint)uVar9 << 8;
        if (ppbStack_dc != (byte **)&DAT_0000000f) {
          ppbStack_dc = (byte **)(param_1 + (int)ppbStack_dc);
          uVar1 = *(undefined *)ppbStack_dc;
          ppbStack_d8 = (byte **)(0x13 - local_50);
          *(undefined *)ppbStack_dc = 0;
          uVar12 = CONCAT31(uVar9,uVar1) << 8;
          if (ppbStack_d8 != (byte **)&DAT_0000000f) {
            ppbStack_d8 = (byte **)(param_1 + (int)ppbStack_d8);
            bVar25 = *(byte *)ppbStack_d8;
            ppbStack_dc = (byte **)(0x14 - local_50);
            *(undefined *)ppbStack_d8 = 0;
            uVar12 = (bVar25 | uVar12) << 8;
            if (ppbStack_dc != (byte **)&DAT_0000000f) {
              ppbStack_dc = (byte **)(param_1 + (int)ppbStack_dc);
              bVar25 = *(byte *)ppbStack_dc;
              ppbStack_d8 = (byte **)(0x15 - local_50);
              *(undefined *)ppbStack_dc = 0;
              uVar12 = (bVar25 | uVar12) << 8;
              if (ppbStack_d8 != (byte **)&DAT_0000000f) {
                bVar25 = param_1[0xe];
                param_1[0xe] = 0;
                uVar12 = (bVar25 | uVar12) << 8;
              }
            }
          }
        }
      }
    }
  }
  uStack_a8 = (uint)param_1[0xf];
  ppbVar13 = (byte **)(uStack_a8 | uVar12);
  param_1[0xf] = 1;
  local_64 = ppbVar13;
  if (ppbVar13 == param_4) {
    pbVar19 = (byte *)((int)param_4 + 0xf);
    param_4 = (byte **)0x20000000;
    ppbStack_d8 = (byte **)0x20000001;
    ppbVar20 = (byte **)((uint)pbVar19 >> 3 | 1);
    ppbStack_dc = (byte **)((int)ppbVar20 + *(int *)(param_1 + 0x24));
    uVar12 = (uint)(ppbStack_dc < ppbVar20) + *(int *)(param_1 + 0x20);
    *(byte ***)(param_1 + 0x24) = ppbStack_dc;
    *(uint *)(param_1 + 0x20) = uVar12;
    if ((uVar12 < 0x20000001) && ((uVar12 != 0x20000000 || (ppbStack_dc == (byte **)0x0)))) {
      local_68 = &local_40;
      if (&SUB_00000010 <= ppbVar13) {
        unaff_s0 = (byte **)(param_1 + 0x10);
        unaff_s6 = local_5c;
        unaff_s7 = local_60;
        do {
          uVar12 = (uint)unaff_s7 & 3;
          uVar22 = (uint)(unaff_s7 + 1) & 3;
          uVar28 = (uint)(unaff_s7 + 3) & 3;
          uVar5 = (uint)(unaff_s7 + 2) & 3;
          uVar6 = (int)unaff_s7 + 3U & 3;
          unaff_s5 = (undefined4 *)
                     ((*(int *)((int)unaff_s7 - uVar12) << uVar12 * 8 |
                      (uint)in_t2 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar6 + 1) * 8 |
                     *(uint *)(((int)unaff_s7 + 3U) - uVar6) >> (3 - uVar6) * 8);
          uVar12 = (int)unaff_s7 + 7U & 3;
          local_6c = (byte **)((*(int *)((int)(unaff_s7 + 1) - uVar22) << uVar22 * 8 |
                               (uint)in_t3 & 0xffffffffU >> (4 - uVar22) * 8) &
                               -1 << (uVar12 + 1) * 8 |
                              *(uint *)(((int)unaff_s7 + 7U) - uVar12) >> (3 - uVar12) * 8);
          uVar12 = (int)unaff_s7 + 0xfU & 3;
          uStack_a8 = (*(int *)((int)(unaff_s7 + 3) - uVar28) << uVar28 * 8 |
                      (uint)in_t1 & 0xffffffffU >> (4 - uVar28) * 8) & -1 << (uVar12 + 1) * 8 |
                      *(uint *)(((int)unaff_s7 + 0xfU) - uVar12) >> (3 - uVar12) * 8;
          uVar12 = (int)unaff_s7 + 0xbU & 3;
          unaff_s4 = (*(int *)((int)(unaff_s7 + 2) - uVar5) << uVar5 * 8 |
                     (uint)in_t0 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar12 + 1) * 8 |
                     *(uint *)(((int)unaff_s7 + 0xbU) - uVar12) >> (3 - uVar12) * 8;
          *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ (uint)unaff_s5;
          *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ (uint)local_6c;
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ unaff_s4;
          *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ uStack_a8;
          (*local_70)(unaff_s0,unaff_s0,ppbStack_ac);
          (*local_70)(param_1,local_68,ppbStack_ac);
          bVar25 = param_1[0xf];
          param_1[0xf] = bVar25 + 1;
          if (((((byte)(bVar25 + 1) == 0) &&
               (bVar25 = param_1[0xe], param_1[0xe] = bVar25 + 1, (byte)(bVar25 + 1) == 0)) &&
              (bVar25 = param_1[0xd], param_1[0xd] = bVar25 + 1, (byte)(bVar25 + 1) == 0)) &&
             (((bVar25 = param_1[0xc], param_1[0xc] = bVar25 + 1, (byte)(bVar25 + 1) == 0 &&
               (bVar25 = param_1[0xb], param_1[0xb] = bVar25 + 1, (byte)(bVar25 + 1) == 0)) &&
              ((bVar25 = param_1[10], param_1[10] = bVar25 + 1, (byte)(bVar25 + 1) == 0 &&
               (bVar25 = param_1[9], param_1[9] = bVar25 + 1, (byte)(bVar25 + 1) == 0)))))) {
            param_1[8] = param_1[8] + 1;
          }
          ppbVar13 = ppbVar13 + -4;
          unaff_s7 = unaff_s7 + 4;
          in_t3 = (byte *)(local_3c ^ (uint)local_6c);
          unaff_s6[1] = in_t3;
          in_t2 = (byte **)(local_40 ^ (uint)unaff_s5);
          *unaff_s6 = (byte *)in_t2;
          in_t1 = (byte **)((uint)local_34 ^ uStack_a8);
          unaff_s6[3] = (byte *)in_t1;
          in_t0 = (byte **)((uint)local_38 ^ unaff_s4);
          unaff_s6[2] = (byte *)in_t0;
          unaff_s6 = unaff_s6 + 4;
        } while (&DAT_0000000f < ppbVar13);
        iVar14 = ((uint)(local_64 + -4) >> 4) + 1;
        local_60 = local_60 + iVar14 * 4;
        local_5c = local_5c + iVar14 * 4;
        unaff_s3 = ppbVar13;
        local_64 = (byte **)((uint)local_64 & 0xf);
      }
      if (local_64 != (byte **)0x0) {
        ppbVar13 = (byte **)(param_1 + 0x10);
        local_48 = local_60 + 1;
        local_44 = (uint)(local_64 < &DAT_00000006);
        local_6c = (byte **)(local_44 ^ 1);
        if ((((uint)local_6c & (local_60 < param_1 + 0x14 ^ 1 | ppbVar13 < local_48 ^ 1)) == 0) ||
           (((uint)local_60 & 3) != 0)) {
          param_1[0x10] = param_1[0x10] ^ *(byte *)local_60;
          in_t2 = local_64;
          if (((((local_64 != (byte **)0x1) &&
                ((((param_1[0x11] = param_1[0x11] ^ *(byte *)((int)local_60 + 1),
                   local_64 != (byte **)&SUB_00000002 &&
                   (param_1[0x12] = param_1[0x12] ^ *(byte *)((int)local_60 + 2),
                   local_64 != (byte **)0x3)) &&
                  (param_1[0x13] = param_1[0x13] ^ *(byte *)((int)local_60 + 3),
                  local_64 != (byte **)&SUB_00000004)) &&
                 ((param_1[0x14] = param_1[0x14] ^ *(byte *)(local_60 + 1), local_44 == 0 &&
                  (param_1[0x15] = param_1[0x15] ^ *(byte *)((int)local_60 + 5),
                  &DAT_00000006 < local_64)))))) &&
               (param_1[0x16] = param_1[0x16] ^ *(byte *)((int)local_60 + 6),
               local_64 != (byte **)&DAT_00000007)) &&
              (((param_1[0x17] = param_1[0x17] ^ *(byte *)((int)local_60 + 7),
                local_64 != (byte **)&DAT_00000008 &&
                (param_1[0x18] = param_1[0x18] ^ *(byte *)(local_60 + 2),
                local_64 != (byte **)&DAT_00000009)) &&
               ((param_1[0x19] = param_1[0x19] ^ *(byte *)((int)local_60 + 9),
                local_64 != (byte **)&DAT_0000000a &&
                (((param_1[0x1a] = param_1[0x1a] ^ *(byte *)((int)local_60 + 10),
                  local_64 != (byte **)&DAT_0000000b &&
                  (param_1[0x1b] = param_1[0x1b] ^ *(byte *)((int)local_60 + 0xb),
                  local_64 != (byte **)&SUB_0000000c)) &&
                 (param_1[0x1c] = param_1[0x1c] ^ *(byte *)(local_60 + 3),
                 local_64 != (byte **)&DAT_0000000d)))))))) &&
             (param_1[0x1d] = param_1[0x1d] ^ *(byte *)((int)local_60 + 0xd),
             local_64 == (byte **)&DAT_0000000f)) {
            param_1[0x1e] = param_1[0x1e] ^ *(byte *)((int)local_60 + 0xe);
          }
        }
        else {
          iVar14 = ((uint)(local_64 + -1) >> 2) + 1;
          ppbVar20 = (byte **)(iVar14 * 4);
          if ((byte *)((int)local_64 + -1) < (byte *)0x3) {
            ppbVar20 = (byte **)0x0;
          }
          else {
            in_t2 = (byte **)0x1;
            in_t3 = *(byte **)(param_1 + 0x10);
            *(uint *)(param_1 + 0x10) = (uint)*local_60 ^ (uint)in_t3;
            if (iVar14 != 1) {
              in_t2 = (byte **)&SUB_00000002;
              in_t3 = *(byte **)(param_1 + 0x14);
              *(uint *)(param_1 + 0x14) = (uint)local_60[1] ^ (uint)in_t3;
              if (iVar14 != 2) {
                in_t2 = (byte **)0x3;
                in_t3 = local_60[2];
                *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ (uint)in_t3;
                if (iVar14 != 3) {
                  *(uint *)(param_1 + 0x1c) = (uint)local_60[3] ^ *(uint *)(param_1 + 0x1c);
                }
              }
            }
            if (local_64 == ppbVar20) goto LAB_005eb798;
          }
          ppbVar21 = (byte **)((int)ppbVar20 + 1);
          in_t3 = (byte *)(uint)(ppbVar21 < local_64);
          bVar25 = *(byte *)((int)local_60 + (int)ppbVar20) ^ (param_1 + (int)ppbVar20)[0x10];
          (param_1 + (int)ppbVar20)[0x10] = bVar25;
          in_t2 = (byte **)(uint)bVar25;
          if (in_t3 != (byte *)0x0) {
            ppbVar20 = (byte **)((int)ppbVar20 + 2);
            bVar25 = (param_1 + (int)ppbVar21)[0x10];
            in_t3 = (byte *)(uint)bVar25;
            in_t2 = (byte **)(uint)(ppbVar20 < local_64);
            (param_1 + (int)ppbVar21)[0x10] = *(byte *)((int)local_60 + (int)ppbVar21) ^ bVar25;
            if (in_t2 != (byte **)0x0) {
              (param_1 + (int)ppbVar20)[0x10] =
                   *(byte *)((int)local_60 + (int)ppbVar20) ^ (param_1 + (int)ppbVar20)[0x10];
            }
          }
        }
LAB_005eb798:
        (*local_70)(ppbVar13,ppbVar13,ppbStack_ac);
        (*local_70)(param_1,local_68,ppbStack_ac);
        in_t1 = local_48;
        if ((((uint)local_6c & (local_60 < local_5c + 1 ^ 1 | local_5c < local_48 ^ 1)) == 0) ||
           ((((uint)local_5c | (uint)local_60) & 3) != 0)) {
          *(byte *)local_5c = local_40._0_1_ ^ *(byte *)local_60;
          if (local_64 != (byte **)0x1) {
            *(byte *)((int)local_5c + 1) = local_40._1_1_ ^ *(byte *)((int)local_60 + 1);
            if (local_64 != (byte **)&SUB_00000002) {
              *(byte *)((int)local_5c + 2) = local_40._2_1_ ^ *(byte *)((int)local_60 + 2);
              if (local_64 != (byte **)0x3) {
                *(byte *)((int)local_5c + 3) = (byte)local_40 ^ *(byte *)((int)local_60 + 3);
                if (local_64 != (byte **)&SUB_00000004) {
                  *(byte *)(local_5c + 1) = local_3c._0_1_ ^ *(byte *)(local_60 + 1);
                  if (local_44 == 0) {
                    *(byte *)((int)local_5c + 5) = local_3c._1_1_ ^ *(byte *)((int)local_60 + 5);
                    if (&DAT_00000006 < local_64) {
                      *(byte *)((int)local_5c + 6) = local_3c._2_1_ ^ *(byte *)((int)local_60 + 6);
                      if (local_64 != (byte **)&DAT_00000007) {
                        *(byte *)((int)local_5c + 7) = (byte)local_3c ^ *(byte *)((int)local_60 + 7)
                        ;
                        if (local_64 != (byte **)&DAT_00000008) {
                          *(byte *)(local_5c + 2) = local_38._0_1_ ^ *(byte *)(local_60 + 2);
                          if (local_64 != (byte **)&DAT_00000009) {
                            *(byte *)((int)local_5c + 9) =
                                 local_38._1_1_ ^ *(byte *)((int)local_60 + 9);
                            if (local_64 != (byte **)&DAT_0000000a) {
                              *(byte *)((int)local_5c + 10) =
                                   local_38._2_1_ ^ *(byte *)((int)local_60 + 10);
                              if (local_64 != (byte **)&DAT_0000000b) {
                                *(byte *)((int)local_5c + 0xb) =
                                     (byte)local_38 ^ *(byte *)((int)local_60 + 0xb);
                                if (local_64 != (byte **)&SUB_0000000c) {
                                  *(byte *)(local_5c + 3) = local_34._0_1_ ^ *(byte *)(local_60 + 3)
                                  ;
                                  if (local_64 != (byte **)&DAT_0000000d) {
                                    *(byte *)((int)local_5c + 0xd) =
                                         local_34._1_1_ ^ *(byte *)((int)local_60 + 0xd);
                                    if (local_64 == (byte **)&DAT_0000000f) {
                                      *(byte *)((int)local_5c + 0xe) =
                                           local_34._2_1_ ^ *(byte *)((int)local_60 + 0xe);
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
          iVar14 = ((uint)(local_64 + -1) >> 2) + 1;
          ppbVar13 = (byte **)(iVar14 * 4);
          if ((byte *)((int)local_64 + -1) < (byte *)0x3) {
            ppbVar13 = (byte **)0x0;
          }
          else {
            *local_5c = (byte *)(local_40 ^ (uint)*local_60);
            if (((iVar14 != 1) &&
                (local_5c[1] = (byte *)(local_3c ^ (uint)local_60[1]), iVar14 != 2)) &&
               (local_5c[2] = (byte *)((uint)local_38 ^ (uint)local_60[2]), iVar14 != 3)) {
              local_5c[3] = (byte *)((uint)local_34 ^ (uint)local_60[3]);
            }
            if (local_64 == ppbVar13) goto LAB_005eb91c;
          }
          ppbVar20 = (byte **)((int)ppbVar13 + 1);
          *(byte *)((int)local_5c + (int)ppbVar13) =
               *(byte *)((int)local_60 + (int)ppbVar13) ^ *(byte *)((int)&local_40 + (int)ppbVar13);
          in_t1 = local_5c;
          in_t2 = local_64;
          if (ppbVar20 < local_64) {
            ppbVar13 = (byte **)((int)ppbVar13 + 2);
            uStack_a8 = (uint)(ppbVar13 < local_64);
            *(byte *)((int)local_5c + (int)ppbVar20) =
                 *(byte *)((int)local_60 + (int)ppbVar20) ^
                 *(byte *)((int)&local_40 + (int)ppbVar20);
            in_t1 = local_5c;
            if (uStack_a8 != 0) {
              unaff_s5 = (undefined4 *)((int)local_60 + (int)ppbVar13);
              *(byte *)((int)local_5c + (int)ppbVar13) =
                   *(byte *)unaff_s5 ^ *(byte *)((int)&local_40 + (int)ppbVar13);
              in_t1 = local_5c;
            }
          }
        }
      }
LAB_005eb91c:
      (**(code **)(local_78 + -0x53ec))(param_1 + (0xf - local_50),0,0x10 - local_4c);
      (*local_70)(param_1,local_68,ppbStack_ac);
      ppbVar13 = (byte **)0x0;
      ppbStack_d8 = (byte **)(*(uint *)(param_1 + 0x14) ^ local_3c);
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ local_40;
      ppbStack_dc = (byte **)(*(uint *)(param_1 + 0x18) ^ (uint)local_38);
      *(byte ***)(param_1 + 0x14) = ppbStack_d8;
      *param_1 = (byte)local_58;
      *(byte ***)(param_1 + 0x18) = ppbStack_dc;
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ (uint)local_34;
      param_4 = local_34;
      in_t0 = local_38;
    }
    else {
      ppbVar13 = (byte **)&SUB_fffffffe;
    }
  }
  else {
    ppbVar13 = (byte **)0xffffffff;
  }
  if (local_2c == (byte **)*local_54) {
    return ppbVar13;
  }
  pcStack_8c = CRYPTO_ccm128_decrypt;
  ppbStack_100 = local_2c;
  (**(code **)(local_78 + -0x5330))();
  puStack_e8 = (undefined4 *)&_gp;
  uStack_d4 = (uint)*(byte *)ppbStack_100;
  pcStack_11c = (code *)ppbStack_100[10];
  ppbStack_118 = (byte **)ppbStack_100[0xb];
  pcStack_b4 = *(code **)PTR___stack_chk_guard_006a9ae8;
  ppcStack_d0 = (code **)PTR___stack_chk_guard_006a9ae8;
  ppbStack_180 = ppbStack_100 + 4;
  ppbStack_17c = ppbStack_d8;
  ppbStack_b0 = unaff_s0;
  ppbStack_a4 = unaff_s3;
  uStack_a0 = unaff_s4;
  puStack_9c = unaff_s5;
  ppbStack_98 = unaff_s6;
  ppbStack_94 = unaff_s7;
  pbStack_90 = param_1;
  if ((*(byte *)ppbStack_100 & 0x40) == 0) {
    ppbStack_17c = ppbStack_118;
    ppbStack_e0 = param_4;
    (*pcStack_11c)();
    param_4 = ppbStack_e0;
  }
  uStack_110 = uStack_d4 & 7;
  iStack_cc = 0xf - uStack_110;
  *(char *)ppbStack_100 = (char)uStack_110;
  if (iStack_cc == 0xf) {
    uVar12 = 0;
  }
  else {
    ppbStack_17c = (byte **)((int)ppbStack_100 + iStack_cc);
    bVar25 = *(byte *)ppbStack_17c;
    ppbStack_180 = (byte **)(0x10 - uStack_110);
    *(byte *)ppbStack_17c = 0;
    uVar12 = (uint)bVar25 << 8;
    if (ppbStack_180 != (byte **)&DAT_0000000f) {
      ppbStack_180 = (byte **)((int)ppbStack_100 + (int)ppbStack_180);
      bVar17 = *(byte *)ppbStack_180;
      ppbStack_17c = (byte **)(0x11 - uStack_110);
      *(byte *)ppbStack_180 = 0;
      uVar8 = CONCAT11(bVar25,bVar17);
      uVar12 = (uint)uVar8 << 8;
      if (ppbStack_17c != (byte **)&DAT_0000000f) {
        ppbStack_17c = (byte **)((int)ppbStack_100 + (int)ppbStack_17c);
        bVar25 = *(byte *)ppbStack_17c;
        ppbStack_180 = (byte **)(0x12 - uStack_110);
        *(byte *)ppbStack_17c = 0;
        uVar9 = CONCAT21(uVar8,bVar25);
        uVar12 = (uint)uVar9 << 8;
        if (ppbStack_180 != (byte **)&DAT_0000000f) {
          ppbStack_180 = (byte **)((int)ppbStack_100 + (int)ppbStack_180);
          bVar25 = *(byte *)ppbStack_180;
          ppbStack_17c = (byte **)(0x13 - uStack_110);
          *(byte *)ppbStack_180 = 0;
          uVar12 = CONCAT31(uVar9,bVar25) << 8;
          if (ppbStack_17c != (byte **)&DAT_0000000f) {
            ppbStack_17c = (byte **)((int)ppbStack_100 + (int)ppbStack_17c);
            bVar25 = *(byte *)ppbStack_17c;
            ppbStack_180 = (byte **)(0x14 - uStack_110);
            *(byte *)ppbStack_17c = 0;
            uVar12 = (bVar25 | uVar12) << 8;
            if (ppbStack_180 != (byte **)&DAT_0000000f) {
              ppbStack_180 = (byte **)((int)ppbStack_100 + (int)ppbStack_180);
              bVar25 = *(byte *)ppbStack_180;
              ppbStack_17c = (byte **)(0x15 - uStack_110);
              *(byte *)ppbStack_180 = 0;
              uVar12 = (bVar25 | uVar12) << 8;
              if (ppbStack_17c != (byte **)&DAT_0000000f) {
                bVar25 = *(byte *)((int)ppbStack_100 + 0xe);
                *(undefined *)((int)ppbStack_100 + 0xe) = 0;
                uVar12 = (bVar25 | uVar12) << 8;
              }
            }
          }
        }
      }
    }
  }
  ppbStack_108 = (byte **)(uint)*(byte *)((int)ppbStack_100 + 0xf);
  ppbStack_e0 = (byte **)((uint)ppbStack_108 | uVar12);
  *(undefined *)((int)ppbStack_100 + 0xf) = 1;
  if (ppbStack_e0 == param_4) {
    unaff_s5 = &uStack_c8;
    if (&SUB_00000010 <= param_4) {
      unaff_s3 = ppbStack_100 + 4;
      ppbStack_108 = ppbStack_d8;
      unaff_s7 = ppbStack_dc;
      do {
        (*pcStack_11c)(ppbStack_100,unaff_s5,ppbStack_118);
        cVar24 = *(char *)((int)ppbStack_100 + 0xf) + '\x01';
        *(char *)((int)ppbStack_100 + 0xf) = cVar24;
        if (((((cVar24 == '\0') &&
              (cVar24 = *(char *)((int)ppbStack_100 + 0xe) + '\x01',
              *(char *)((int)ppbStack_100 + 0xe) = cVar24, cVar24 == '\0')) &&
             (cVar24 = *(char *)((int)ppbStack_100 + 0xd) + '\x01',
             *(char *)((int)ppbStack_100 + 0xd) = cVar24, cVar24 == '\0')) &&
            ((cVar24 = *(char *)(ppbStack_100 + 3), *(char *)(ppbStack_100 + 3) = cVar24 + '\x01',
             (char)(cVar24 + '\x01') == '\0' &&
             (cVar24 = *(char *)((int)ppbStack_100 + 0xb) + '\x01',
             *(char *)((int)ppbStack_100 + 0xb) = cVar24, cVar24 == '\0')))) &&
           ((cVar24 = *(char *)((int)ppbStack_100 + 10) + '\x01',
            *(char *)((int)ppbStack_100 + 10) = cVar24, cVar24 == '\0' &&
            (cVar24 = *(char *)((int)ppbStack_100 + 9) + '\x01',
            *(char *)((int)ppbStack_100 + 9) = cVar24, cVar24 == '\0')))) {
          *(char *)(ppbStack_100 + 2) = *(char *)(ppbStack_100 + 2) + '\x01';
        }
        uVar12 = (uint)unaff_s7 & 3;
        param_4 = param_4 + -4;
        uVar22 = (uint)(unaff_s7 + 1) & 3;
        ppbVar13 = unaff_s7 + 2;
        uVar28 = (uint)ppbVar13 & 3;
        uVar6 = (uint)(byte *)((int)unaff_s7 + 3) & 3;
        uVar7 = (uint)(byte *)((int)unaff_s7 + 7) & 3;
        ppbVar20 = unaff_s7 + 3;
        uVar5 = (uint)ppbVar20 & 3;
        in_t3 = (byte *)((uint)uStack_c8 ^
                        ((*(int *)((int)unaff_s7 - uVar12) << uVar12 * 8 |
                         (uint)in_t3 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar6 + 1) * 8 |
                        *(uint *)((byte *)((int)unaff_s7 + 3) + -uVar6) >> (3 - uVar6) * 8));
        pbVar19 = (byte *)((int)unaff_s7 + 0xb);
        uVar12 = (uint)pbVar19 & 3;
        in_t2 = (byte **)((uint)uStack_c4 ^
                         ((*(int *)((int)(unaff_s7 + 1) - uVar22) << uVar22 * 8 |
                          (uint)in_t2 & 0xffffffffU >> (4 - uVar22) * 8) & -1 << (uVar7 + 1) * 8 |
                         *(uint *)((byte *)((int)unaff_s7 + 7) + -uVar7) >> (3 - uVar7) * 8));
        pbVar26 = (byte *)((int)unaff_s7 + 0xf);
        uVar22 = (uint)pbVar26 & 3;
        unaff_s7 = unaff_s7 + 4;
        in_t1 = (byte **)((uint)uStack_c0 ^
                         ((*(int *)((int)ppbVar13 - uVar28) << uVar28 * 8 |
                          (uint)in_t1 & 0xffffffffU >> (4 - uVar28) * 8) & -1 << (uVar12 + 1) * 8 |
                         *(uint *)(pbVar19 + -uVar12) >> (3 - uVar12) * 8));
        in_t0 = (byte **)((uint)uStack_bc ^
                         ((*(int *)((int)ppbVar20 - uVar5) << uVar5 * 8 |
                          (uint)in_t0 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar22 + 1) * 8 |
                         *(uint *)(pbVar26 + -uVar22) >> (3 - uVar22) * 8));
        ppbStack_100[4] = (byte *)((uint)ppbStack_100[4] ^ (uint)in_t3);
        ppbStack_100[5] = (byte *)((uint)ppbStack_100[5] ^ (uint)in_t2);
        ppbStack_100[6] = (byte *)((uint)ppbStack_100[6] ^ (uint)in_t1);
        ppbStack_100[7] = (byte *)((uint)ppbStack_100[7] ^ (uint)in_t0);
        *ppbStack_108 = in_t3;
        ppbStack_108[1] = (byte *)in_t2;
        ppbStack_108[2] = (byte *)in_t1;
        ppbStack_108[3] = (byte *)in_t0;
        ppbStack_108 = ppbStack_108 + 4;
        uStack_c8 = in_t3;
        uStack_c4 = in_t2;
        uStack_c0 = in_t1;
        uStack_bc = in_t0;
        (*pcStack_11c)(unaff_s3,unaff_s3,ppbStack_118);
      } while (&DAT_0000000f < param_4);
      ppbVar13 = ppbStack_e0 + -4;
      ppbStack_e0 = (byte **)((uint)ppbStack_e0 & 0xf);
      iVar14 = ((uint)ppbVar13 >> 4) + 1;
      ppbStack_dc = ppbStack_dc + iVar14 * 4;
      ppbStack_d8 = ppbStack_d8 + iVar14 * 4;
      unaff_s0 = param_4;
    }
    if (ppbStack_e0 != (byte **)0x0) {
      (*pcStack_11c)(ppbStack_100,unaff_s5,ppbStack_118);
      ppbVar13 = ppbStack_100 + 4;
      if (((ppbStack_e0 < &DAT_00000005 ||
           (ppbVar13 < ppbStack_d8 + 1 && ppbStack_d8 < ppbStack_100 + 5 ||
           ppbVar13 < ppbStack_dc + 1 && ppbStack_dc < ppbStack_100 + 5)) ||
           ppbStack_dc < ppbStack_d8 + 1 && ppbStack_d8 < ppbStack_dc + 1) ||
         ((((uint)ppbStack_dc | (uint)ppbStack_d8) & 3) != 0)) {
        bVar25 = *(byte *)ppbStack_dc;
        *(byte *)ppbStack_d8 = bVar25 ^ uStack_c8._0_1_;
        *(byte *)(ppbStack_100 + 4) = bVar25 ^ uStack_c8._0_1_ ^ *(byte *)(ppbStack_100 + 4);
        if (ppbStack_e0 != (byte **)0x1) {
          uStack_c8._1_1_ = uStack_c8._1_1_ ^ *(byte *)((int)ppbStack_dc + 1);
          *(byte *)((int)ppbStack_d8 + 1) = uStack_c8._1_1_;
          *(byte *)((int)ppbStack_100 + 0x11) =
               uStack_c8._1_1_ ^ *(byte *)((int)ppbStack_100 + 0x11);
          if (ppbStack_e0 != (byte **)&SUB_00000002) {
            uStack_c8._2_1_ = uStack_c8._2_1_ ^ *(byte *)((int)ppbStack_dc + 2);
            *(byte *)((int)ppbStack_d8 + 2) = uStack_c8._2_1_;
            *(byte *)((int)ppbStack_100 + 0x12) =
                 uStack_c8._2_1_ ^ *(byte *)((int)ppbStack_100 + 0x12);
            if (ppbStack_e0 != (byte **)0x3) {
              uStack_c8._3_1_ = (byte)uStack_c8 ^ *(byte *)((int)ppbStack_dc + 3);
              *(byte *)((int)ppbStack_d8 + 3) = (byte)uStack_c8;
              *(byte *)((int)ppbStack_100 + 0x13) =
                   (byte)uStack_c8 ^ *(byte *)((int)ppbStack_100 + 0x13);
              if (ppbStack_e0 >= &DAT_00000005) {
                bVar25 = *(byte *)(ppbStack_dc + 1);
                *(byte *)(ppbStack_d8 + 1) = uStack_c4._0_1_ ^ bVar25;
                *(byte *)(ppbStack_100 + 5) = uStack_c4._0_1_ ^ bVar25 ^ *(byte *)(ppbStack_100 + 5)
                ;
                if (&DAT_00000005 < ppbStack_e0) {
                  uStack_c4._1_1_ = uStack_c4._1_1_ ^ *(byte *)((int)ppbStack_dc + 5);
                  *(byte *)((int)ppbStack_d8 + 5) = uStack_c4._1_1_;
                  *(byte *)((int)ppbStack_100 + 0x15) =
                       uStack_c4._1_1_ ^ *(byte *)((int)ppbStack_100 + 0x15);
                  if (ppbStack_e0 != (byte **)&DAT_00000006) {
                    uStack_c4._2_1_ = uStack_c4._2_1_ ^ *(byte *)((int)ppbStack_dc + 6);
                    *(byte *)((int)ppbStack_d8 + 6) = uStack_c4._2_1_;
                    *(byte *)((int)ppbStack_100 + 0x16) =
                         uStack_c4._2_1_ ^ *(byte *)((int)ppbStack_100 + 0x16);
                    if (ppbStack_e0 != (byte **)&DAT_00000007) {
                      uStack_c4._3_1_ = (byte)uStack_c4 ^ *(byte *)((int)ppbStack_dc + 7);
                      *(byte *)((int)ppbStack_d8 + 7) = (byte)uStack_c4;
                      *(byte *)((int)ppbStack_100 + 0x17) =
                           (byte)uStack_c4 ^ *(byte *)((int)ppbStack_100 + 0x17);
                      if (ppbStack_e0 != (byte **)&DAT_00000008) {
                        bVar25 = *(byte *)(ppbStack_dc + 2);
                        *(byte *)(ppbStack_d8 + 2) = uStack_c0._0_1_ ^ bVar25;
                        *(byte *)(ppbStack_100 + 6) =
                             uStack_c0._0_1_ ^ bVar25 ^ *(byte *)(ppbStack_100 + 6);
                        if (ppbStack_e0 != (byte **)&DAT_00000009) {
                          uStack_c0._1_1_ = uStack_c0._1_1_ ^ *(byte *)((int)ppbStack_dc + 9);
                          *(byte *)((int)ppbStack_d8 + 9) = uStack_c0._1_1_;
                          *(byte *)((int)ppbStack_100 + 0x19) =
                               uStack_c0._1_1_ ^ *(byte *)((int)ppbStack_100 + 0x19);
                          if (ppbStack_e0 != (byte **)&DAT_0000000a) {
                            uStack_c0._2_1_ = uStack_c0._2_1_ ^ *(byte *)((int)ppbStack_dc + 10);
                            *(byte *)((int)ppbStack_d8 + 10) = uStack_c0._2_1_;
                            *(byte *)((int)ppbStack_100 + 0x1a) =
                                 uStack_c0._2_1_ ^ *(byte *)((int)ppbStack_100 + 0x1a);
                            if (ppbStack_e0 != (byte **)&DAT_0000000b) {
                              uStack_c0._3_1_ = (byte)uStack_c0 ^ *(byte *)((int)ppbStack_dc + 0xb);
                              *(byte *)((int)ppbStack_d8 + 0xb) = (byte)uStack_c0;
                              *(byte *)((int)ppbStack_100 + 0x1b) =
                                   (byte)uStack_c0 ^ *(byte *)((int)ppbStack_100 + 0x1b);
                              if (ppbStack_e0 != (byte **)&SUB_0000000c) {
                                bVar25 = *(byte *)(ppbStack_dc + 3);
                                *(byte *)(ppbStack_d8 + 3) = uStack_bc._0_1_ ^ bVar25;
                                *(byte *)(ppbStack_100 + 7) =
                                     uStack_bc._0_1_ ^ bVar25 ^ *(byte *)(ppbStack_100 + 7);
                                if (ppbStack_e0 != (byte **)&DAT_0000000d) {
                                  uStack_bc._1_1_ =
                                       uStack_bc._1_1_ ^ *(byte *)((int)ppbStack_dc + 0xd);
                                  *(byte *)((int)ppbStack_d8 + 0xd) = uStack_bc._1_1_;
                                  *(byte *)((int)ppbStack_100 + 0x1d) =
                                       uStack_bc._1_1_ ^ *(byte *)((int)ppbStack_100 + 0x1d);
                                  if (ppbStack_e0 == (byte **)&DAT_0000000f) {
                                    uStack_bc._2_1_ =
                                         uStack_bc._2_1_ ^ *(byte *)((int)ppbStack_dc + 0xe);
                                    *(byte *)((int)ppbStack_d8 + 0xe) = uStack_bc._2_1_;
                                    *(byte *)((int)ppbStack_100 + 0x1e) =
                                         uStack_bc._2_1_ ^ *(byte *)((int)ppbStack_100 + 0x1e);
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
        iVar14 = ((uint)(ppbStack_e0 + -1) >> 2) + 1;
        ppbVar20 = (byte **)(iVar14 * 4);
        if ((byte *)((int)ppbStack_e0 + -1) < (byte *)0x3) {
          ppbVar20 = (byte **)0x0;
        }
        else {
          pbVar19 = *ppbStack_dc;
          *ppbStack_d8 = (byte *)((uint)pbVar19 ^ (uint)uStack_c8);
          ppbStack_100[4] =
               (byte *)((uint)(byte *)((uint)pbVar19 ^ (uint)uStack_c8) ^ (uint)ppbStack_100[4]);
          if (iVar14 != 1) {
            pbVar19 = ppbStack_dc[1];
            ppbStack_d8[1] = (byte *)((uint)uStack_c4 ^ (uint)pbVar19);
            ppbStack_100[5] =
                 (byte *)((uint)(byte *)((uint)uStack_c4 ^ (uint)pbVar19) ^ (uint)ppbStack_100[5]);
            if (iVar14 != 2) {
              pbVar19 = ppbStack_dc[2];
              ppbStack_d8[2] = (byte *)((uint)uStack_c0 ^ (uint)pbVar19);
              ppbStack_100[6] =
                   (byte *)((uint)(byte *)((uint)uStack_c0 ^ (uint)pbVar19) ^ (uint)ppbStack_100[6])
              ;
              if (iVar14 != 3) {
                pbVar19 = ppbStack_dc[3];
                ppbStack_d8[3] = (byte *)((uint)uStack_bc ^ (uint)pbVar19);
                ppbStack_100[7] =
                     (byte *)((uint)(byte *)((uint)uStack_bc ^ (uint)pbVar19) ^
                             (uint)ppbStack_100[7]);
              }
            }
          }
          if (ppbStack_e0 == ppbVar20) goto LAB_005ec360;
        }
        ppbVar21 = (byte **)((int)ppbVar20 + 1);
        bVar25 = *(byte *)((int)ppbStack_dc + (int)ppbVar20) ^
                 *(byte *)((int)&uStack_c8 + (int)ppbVar20);
        *(byte *)((int)ppbStack_d8 + (int)ppbVar20) = bVar25;
        ((byte *)((int)ppbStack_100 + (int)ppbVar20))[0x10] =
             bVar25 ^ ((byte *)((int)ppbStack_100 + (int)ppbVar20))[0x10];
        if (ppbVar21 < ppbStack_e0) {
          ppbVar20 = (byte **)((int)ppbVar20 + 2);
          ppbStack_108 = (byte **)(uint)(ppbVar20 < ppbStack_e0);
          bVar25 = *(byte *)((int)ppbStack_dc + (int)ppbVar21) ^
                   *(byte *)((int)&uStack_c8 + (int)ppbVar21);
          *(byte *)((int)ppbStack_d8 + (int)ppbVar21) = bVar25;
          ((byte *)((int)ppbStack_100 + (int)ppbVar21))[0x10] =
               bVar25 ^ ((byte *)((int)ppbStack_100 + (int)ppbVar21))[0x10];
          if (ppbStack_108 != (byte **)0x0) {
            unaff_s7 = (byte **)((int)ppbStack_dc + (int)ppbVar20);
            bVar25 = *(byte *)unaff_s7 ^ *(byte *)((int)&uStack_c8 + (int)ppbVar20);
            *(byte *)((int)ppbStack_d8 + (int)ppbVar20) = bVar25;
            ((byte *)((int)ppbStack_100 + (int)ppbVar20))[0x10] =
                 bVar25 ^ ((byte *)((int)ppbStack_100 + (int)ppbVar20))[0x10];
          }
        }
      }
LAB_005ec360:
      (*pcStack_11c)(ppbVar13,ppbVar13,ppbStack_118);
    }
    (*(code *)puStack_e8[-0x14fb])
              ((undefined *)((int)ppbStack_100 + (0xf - uStack_110)),0,0x10 - iStack_cc);
    (*pcStack_11c)(ppbStack_100,unaff_s5,ppbStack_118);
    ppbVar13 = (byte **)0x0;
    ppbStack_17c = (byte **)((uint)ppbStack_100[5] ^ (uint)uStack_c4);
    ppbStack_100[4] = (byte *)((uint)ppbStack_100[4] ^ (uint)uStack_c8);
    ppbStack_180 = (byte **)((uint)ppbStack_100[6] ^ (uint)uStack_c0);
    ppbStack_100[5] = (byte *)ppbStack_17c;
    *(undefined *)ppbStack_100 = (undefined)uStack_d4;
    ppbStack_100[6] = (byte *)ppbStack_180;
    ppbStack_100[7] = (byte *)((uint)ppbStack_100[7] ^ (uint)uStack_bc);
    param_4 = uStack_bc;
  }
  else {
    ppbVar13 = (byte **)0xffffffff;
  }
  if (pcStack_b4 == *ppcStack_d0) {
    return ppbVar13;
  }
  pcStack_fc = CRYPTO_ccm128_encrypt_ccm64;
  pcStack_198 = pcStack_b4;
  (*(code *)puStack_e8[-0x14cc])();
  puStack_178 = puStack_e8;
  puStack_190 = PTR___stack_chk_guard_006a9ae8;
  pcStack_14c = *(code **)(pcStack_198 + 0x28);
  puStack_158 = &_gp;
  cVar2 = *pcStack_198;
  uStack_18c = (uint)(byte)cVar2;
  ppbStack_194 = *(byte ***)(pcStack_198 + 0x2c);
  pbStack_124 = *(byte **)PTR___stack_chk_guard_006a9ae8;
  ppbVar13 = ppbStack_180;
  ppbVar20 = ppbStack_17c;
  ppbStack_120 = unaff_s0;
  ppbStack_114 = unaff_s3;
  puStack_10c = unaff_s5;
  ppbStack_104 = unaff_s7;
  if (((byte)cVar2 & 0x40) == 0) {
    ppbVar13 = (byte **)(pcStack_198 + 0x10);
    ppbVar20 = ppbStack_194;
    ppbStack_148 = param_4;
    (*pcStack_14c)();
    uVar12 = *(uint *)(pcStack_198 + 0x24);
    uVar22 = uVar12 + 1;
    *(uint *)(pcStack_198 + 0x24) = uVar22;
    *(uint *)(pcStack_198 + 0x20) = (uint)(uVar22 < uVar12) + *(int *)(pcStack_198 + 0x20);
    param_4 = ppbStack_148;
  }
  uStack_184 = uStack_18c & 7;
  ppbVar21 = (byte **)(0xf - uStack_184);
  *pcStack_198 = SUB41(uStack_184,0);
  if (ppbVar21 == (byte **)&DAT_0000000f) {
    uVar12 = 0;
  }
  else {
    ppbVar13 = (byte **)(pcStack_198 + (int)ppbVar21);
    bVar25 = *(byte *)ppbVar13;
    *(byte *)ppbVar13 = 0;
    uVar12 = (uint)bVar25 << 8;
    if (0x10 - uStack_184 != 0xf) {
      cVar3 = pcStack_198[0x10 - uStack_184];
      ppbVar20 = (byte **)(uint)(byte)cVar3;
      ppbVar13 = (byte **)(0x11 - uStack_184);
      pcStack_198[0x10 - uStack_184] = (code)0x0;
      uVar8 = CONCAT11(bVar25,cVar3);
      uVar12 = (uint)uVar8 << 8;
      if (ppbVar13 != (byte **)&DAT_0000000f) {
        ppbVar13 = (byte **)(pcStack_198 + (int)ppbVar13);
        bVar25 = *(byte *)ppbVar13;
        ppbVar20 = (byte **)(uint)bVar25;
        *(byte *)ppbVar13 = 0;
        uVar9 = CONCAT21(uVar8,bVar25);
        uVar12 = (uint)uVar9 << 8;
        if (0x12 - uStack_184 != 0xf) {
          cVar3 = pcStack_198[0x12 - uStack_184];
          ppbVar20 = (byte **)(uint)(byte)cVar3;
          ppbVar13 = (byte **)(0x13 - uStack_184);
          pcStack_198[0x12 - uStack_184] = (code)0x0;
          uVar12 = CONCAT31(uVar9,cVar3) << 8;
          if (ppbVar13 != (byte **)&DAT_0000000f) {
            ppbVar13 = (byte **)(pcStack_198 + (int)ppbVar13);
            ppbVar20 = (byte **)(uint)*(byte *)ppbVar13;
            *(byte *)ppbVar13 = 0;
            uVar12 = ((uint)ppbVar20 | uVar12) << 8;
            if (0x14 - uStack_184 != 0xf) {
              ppbVar20 = (byte **)(uint)(byte)pcStack_198[0x14 - uStack_184];
              ppbVar13 = (byte **)(0x15 - uStack_184);
              pcStack_198[0x14 - uStack_184] = (code)0x0;
              uVar12 = ((uint)ppbVar20 | uVar12) << 8;
              if (ppbVar13 != (byte **)&DAT_0000000f) {
                cVar3 = pcStack_198[0xe];
                pcStack_198[0xe] = (code)0x0;
                uVar12 = ((byte)cVar3 | uVar12) << 8;
              }
            }
          }
        }
      }
    }
  }
  ppbStack_188 = (byte **)((byte)pcStack_198[0xf] | uVar12);
  pcStack_198[0xf] = (code)0x1;
  if (ppbStack_188 == param_4) {
    ppbVar20 = (byte **)0x20000000;
    ppbVar13 = (byte **)0x20000001;
    uVar22 = (uint)((int)param_4 + 0xf) >> 3 | 1;
    uVar12 = uVar22 + *(int *)(pcStack_198 + 0x24);
    uVar22 = (uint)(uVar12 < uVar22) + *(int *)(pcStack_198 + 0x20);
    *(uint *)(pcStack_198 + 0x24) = uVar12;
    *(uint *)(pcStack_198 + 0x20) = uVar22;
    if ((uVar22 < 0x20000001) && ((uVar22 != 0x20000000 || (uVar12 == 0)))) {
      ppbVar20 = (byte **)((uint)ppbStack_188 >> 4);
      ppbVar13 = (byte **)(pcStack_198 + 0x10);
      if (ppbVar20 == (byte **)0x0) {
        if (ppbStack_188 != (byte **)0x0) goto LAB_005ec7b4;
      }
      else {
        pcStack_160 = pcStack_198;
        ppbStack_15c = ppbVar13;
        ppbStack_148 = ppbVar20;
        ppbStack_144 = ppbVar13;
        ppbStack_140 = ppbVar21;
        (*(code *)puStack_178)(ppbStack_180,ppbStack_17c,ppbVar20,ppbStack_194);
        uVar12 = (int)ppbStack_148 * 0x10;
        ppbStack_188 = ppbStack_188 + (int)ppbStack_148 * -4;
        ppbStack_180 = ppbStack_180 + (int)ppbStack_148 * 4;
        ppbStack_17c = ppbStack_17c + (int)ppbStack_148 * 4;
        ppbVar21 = ppbStack_140;
        if (ppbStack_188 == (byte **)0x0) goto LAB_005eca90;
        uVar22 = (uint)(byte)pcStack_198[0xf] + ((uint)ppbStack_148 & 0xff);
        uVar28 = uVar22 >> 8;
        pcStack_198[0xf] = SUB41(uVar22,0);
        ppbVar13 = ppbStack_144;
        if (uVar12 >> 0xc == 0) {
          if (uVar28 == 0) goto LAB_005ec7b4;
          uVar28 = (byte)pcStack_198[0xe] + 1 >> 8;
          pcStack_198[0xe] = SUB41((byte)pcStack_198[0xe] + 1,0);
LAB_005ecbb0:
          if (uVar28 == 0) goto LAB_005ec7b4;
          uVar28 = (byte)pcStack_198[0xd] + 1 >> 8;
          pcStack_198[0xd] = SUB41((byte)pcStack_198[0xd] + 1,0);
LAB_005ecbc8:
          if (uVar28 == 0) goto LAB_005ec7b4;
          uVar12 = (byte)pcStack_198[0xc] + 1;
          pcStack_198[0xc] = SUB41(uVar12,0);
        }
        else {
          uVar22 = (uint)(byte)pcStack_198[0xe] + (uVar12 >> 0xc & 0xff) + uVar28;
          uVar28 = uVar22 >> 8;
          pcStack_198[0xe] = SUB41(uVar22,0);
          if (uVar12 >> 0x14 == 0) goto LAB_005ecbb0;
          uVar22 = (uint)(byte)pcStack_198[0xd] + (uVar12 >> 0x14 & 0xff) + uVar28;
          uVar28 = uVar22 >> 8;
          pcStack_198[0xd] = SUB41(uVar22,0);
          if (uVar12 >> 0x1c == 0) goto LAB_005ecbc8;
          uVar12 = (uint)(byte)pcStack_198[0xc] + (uVar12 >> 0x1c) + uVar28;
          pcStack_198[0xc] = SUB41(uVar12,0);
        }
        if ((((uVar12 >> 8 != 0) &&
             (cVar3 = pcStack_198[0xb], pcStack_198[0xb] = SUB41((byte)cVar3 + 1,0),
             (byte)cVar3 + 1 >> 8 != 0)) &&
            (cVar3 = pcStack_198[10], pcStack_198[10] = SUB41((byte)cVar3 + 1,0),
            (byte)cVar3 + 1 >> 8 != 0)) &&
           (cVar3 = pcStack_198[9], pcStack_198[9] = SUB41((byte)cVar3 + 1,0),
           (byte)cVar3 + 1 >> 8 != 0)) {
          pcStack_198[8] = (code)((char)pcStack_198[8] + 1);
        }
LAB_005ec7b4:
        ppbStack_140 = ppbStack_180 + 1;
        uStack_13c = (uint)(ppbStack_188 < &DAT_00000006);
        ppbStack_144 = (byte **)(uStack_13c ^ 1);
        if ((((uint)ppbStack_144 &
             (ppbStack_180 < pcStack_198 + 0x14 ^ 1 | ppbVar13 < ppbStack_140 ^ 1)) == 0) ||
           (((uint)ppbStack_180 & 3) != 0)) {
          pcStack_198[0x10] = (code)((byte)pcStack_198[0x10] ^ *(byte *)ppbStack_180);
          if (((((ppbStack_188 != (byte **)0x1) &&
                ((pcStack_198[0x11] =
                       (code)((byte)pcStack_198[0x11] ^ *(byte *)((int)ppbStack_180 + 1)),
                 ppbStack_188 != (byte **)&SUB_00000002 &&
                 (pcStack_198[0x12] =
                       (code)((byte)pcStack_198[0x12] ^ *(byte *)((int)ppbStack_180 + 2)),
                 ppbStack_188 != (byte **)0x3)))) &&
               (pcStack_198[0x13] =
                     (code)((byte)pcStack_198[0x13] ^ *(byte *)((int)ppbStack_180 + 3)),
               ppbStack_188 != (byte **)&SUB_00000004)) &&
              ((((pcStack_198[0x14] = (code)((byte)pcStack_198[0x14] ^ *(byte *)(ppbStack_180 + 1)),
                 uStack_13c == 0 &&
                 (pcStack_198[0x15] =
                       (code)((byte)pcStack_198[0x15] ^ *(byte *)((int)ppbStack_180 + 5)),
                 &DAT_00000006 < ppbStack_188)) &&
                (pcStack_198[0x16] =
                      (code)((byte)pcStack_198[0x16] ^ *(byte *)((int)ppbStack_180 + 6)),
                ppbStack_188 != (byte **)&DAT_00000007)) &&
               ((((pcStack_198[0x17] =
                        (code)((byte)pcStack_198[0x17] ^ *(byte *)((int)ppbStack_180 + 7)),
                  ppbStack_188 != (byte **)&DAT_00000008 &&
                  (pcStack_198[0x18] = (code)((byte)pcStack_198[0x18] ^ *(byte *)(ppbStack_180 + 2))
                  , ppbStack_188 != (byte **)&DAT_00000009)) &&
                 ((pcStack_198[0x19] =
                        (code)((byte)pcStack_198[0x19] ^ *(byte *)((int)ppbStack_180 + 9)),
                  ppbStack_188 != (byte **)&DAT_0000000a &&
                  ((pcStack_198[0x1a] =
                         (code)((byte)pcStack_198[0x1a] ^ *(byte *)((int)ppbStack_180 + 10)),
                   ppbStack_188 != (byte **)&DAT_0000000b &&
                   (pcStack_198[0x1b] =
                         (code)((byte)pcStack_198[0x1b] ^ *(byte *)((int)ppbStack_180 + 0xb)),
                   ppbStack_188 != (byte **)&SUB_0000000c)))))) &&
                (pcStack_198[0x1c] = (code)((byte)pcStack_198[0x1c] ^ *(byte *)(ppbStack_180 + 3)),
                ppbStack_188 != (byte **)&DAT_0000000d)))))) &&
             ((pcStack_198[0x1d] =
                    (code)((byte)pcStack_198[0x1d] ^ *(byte *)((int)ppbStack_180 + 0xd)),
              ppbStack_188 != (byte **)&DAT_0000000e &&
              (pcStack_198[0x1e] =
                    (code)((byte)pcStack_198[0x1e] ^ *(byte *)((int)ppbStack_180 + 0xe)),
              ppbStack_188 != (byte **)&DAT_0000000f)))) {
            pcStack_198[0x1f] = (code)((byte)pcStack_198[0x1f] ^ *(byte *)((int)ppbStack_180 + 0xf))
            ;
          }
        }
        else {
          ppbVar20 = (byte **)0x1;
          if (ppbStack_188 != (byte **)0x0) {
            ppbVar20 = ppbStack_188;
          }
          iVar14 = ((uint)(ppbVar20 + -1) >> 2) + 1;
          ppbVar15 = (byte **)(iVar14 * 4);
          if (ppbStack_188 < &SUB_00000004) {
            ppbVar15 = (byte **)0x0;
          }
          else {
            *(uint *)(pcStack_198 + 0x10) = (uint)*ppbStack_180 ^ *(uint *)(pcStack_198 + 0x10);
            if (((iVar14 != 1) &&
                (*(uint *)(pcStack_198 + 0x14) =
                      *(uint *)(pcStack_198 + 0x14) ^ (uint)ppbStack_180[1], iVar14 != 2)) &&
               (*(uint *)(pcStack_198 + 0x18) =
                     (uint)ppbStack_180[2] ^ *(uint *)(pcStack_198 + 0x18), iVar14 != 3)) {
              *(uint *)(pcStack_198 + 0x1c) = (uint)ppbStack_180[3] ^ *(uint *)(pcStack_198 + 0x1c);
            }
            if (ppbVar20 == ppbVar15) goto LAB_005ec8c8;
          }
          ppbVar20 = (byte **)((int)ppbVar15 + 1);
          (pcStack_198 + (int)ppbVar15)[0x10] =
               (code)(*(byte *)((int)ppbStack_180 + (int)ppbVar15) ^
                     (byte)(pcStack_198 + (int)ppbVar15)[0x10]);
          if (ppbVar20 < ppbStack_188) {
            ppbVar15 = (byte **)((int)ppbVar15 + 2);
            (pcStack_198 + (int)ppbVar20)[0x10] =
                 (code)(*(byte *)((int)ppbStack_180 + (int)ppbVar20) ^
                       (byte)(pcStack_198 + (int)ppbVar20)[0x10]);
            if (ppbVar15 < ppbStack_188) {
              (pcStack_198 + (int)ppbVar15)[0x10] =
                   (code)(*(byte *)((int)ppbStack_180 + (int)ppbVar15) ^
                         (byte)(pcStack_198 + (int)ppbVar15)[0x10]);
            }
          }
        }
LAB_005ec8c8:
        ppbStack_148 = ppbVar21;
        (*pcStack_14c)(ppbVar13,ppbVar13,ppbStack_194);
        (*pcStack_14c)(pcStack_198,&uStack_138,ppbStack_194);
        ppbVar21 = ppbStack_148;
        if ((((uint)ppbStack_144 &
             (ppbStack_180 < ppbStack_17c + 1 ^ 1 | ppbStack_17c < ppbStack_140 ^ 1)) == 0) ||
           ((((uint)ppbStack_17c | (uint)ppbStack_180) & 3) != 0)) {
          *(byte *)ppbStack_17c = uStack_138._0_1_ ^ *(byte *)ppbStack_180;
          if (ppbStack_188 != (byte **)0x1) {
            *(byte *)((int)ppbStack_17c + 1) = uStack_138._1_1_ ^ *(byte *)((int)ppbStack_180 + 1);
            if (ppbStack_188 != (byte **)&SUB_00000002) {
              *(byte *)((int)ppbStack_17c + 2) = uStack_138._2_1_ ^ *(byte *)((int)ppbStack_180 + 2)
              ;
              if (ppbStack_188 != (byte **)0x3) {
                *(byte *)((int)ppbStack_17c + 3) =
                     (byte)uStack_138 ^ *(byte *)((int)ppbStack_180 + 3);
                if (ppbStack_188 != (byte **)&SUB_00000004) {
                  *(byte *)(ppbStack_17c + 1) = uStack_134._0_1_ ^ *(byte *)(ppbStack_180 + 1);
                  if (uStack_13c == 0) {
                    *(byte *)((int)ppbStack_17c + 5) =
                         uStack_134._1_1_ ^ *(byte *)((int)ppbStack_180 + 5);
                    if (&DAT_00000006 < ppbStack_188) {
                      *(byte *)((int)ppbStack_17c + 6) =
                           uStack_134._2_1_ ^ *(byte *)((int)ppbStack_180 + 6);
                      if (ppbStack_188 != (byte **)&DAT_00000007) {
                        *(byte *)((int)ppbStack_17c + 7) =
                             (byte)uStack_134 ^ *(byte *)((int)ppbStack_180 + 7);
                        if (ppbStack_188 != (byte **)&DAT_00000008) {
                          *(byte *)(ppbStack_17c + 2) =
                               uStack_130._0_1_ ^ *(byte *)(ppbStack_180 + 2);
                          if (ppbStack_188 != (byte **)&DAT_00000009) {
                            *(byte *)((int)ppbStack_17c + 9) =
                                 uStack_130._1_1_ ^ *(byte *)((int)ppbStack_180 + 9);
                            if (ppbStack_188 != (byte **)&DAT_0000000a) {
                              *(byte *)((int)ppbStack_17c + 10) =
                                   uStack_130._2_1_ ^ *(byte *)((int)ppbStack_180 + 10);
                              if (ppbStack_188 != (byte **)&DAT_0000000b) {
                                *(byte *)((int)ppbStack_17c + 0xb) =
                                     (byte)uStack_130 ^ *(byte *)((int)ppbStack_180 + 0xb);
                                if (ppbStack_188 != (byte **)&SUB_0000000c) {
                                  *(byte *)(ppbStack_17c + 3) =
                                       uStack_12c._0_1_ ^ *(byte *)(ppbStack_180 + 3);
                                  if (ppbStack_188 != (byte **)&DAT_0000000d) {
                                    *(byte *)((int)ppbStack_17c + 0xd) =
                                         uStack_12c._1_1_ ^ *(byte *)((int)ppbStack_180 + 0xd);
                                    if (ppbStack_188 != (byte **)&DAT_0000000e) {
                                      *(byte *)((int)ppbStack_17c + 0xe) =
                                           uStack_12c._2_1_ ^ *(byte *)((int)ppbStack_180 + 0xe);
                                      if (ppbStack_188 != (byte **)&DAT_0000000f) {
                                        *(byte *)((int)ppbStack_17c + 0xf) =
                                             *(byte *)((int)ppbStack_180 + 0xf) ^ (byte)uStack_12c;
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
          ppbVar13 = (byte **)0x1;
          if (ppbStack_188 != (byte **)0x0) {
            ppbVar13 = ppbStack_188;
          }
          iVar14 = ((uint)(ppbVar13 + -1) >> 2) + 1;
          ppbVar20 = (byte **)(iVar14 * 4);
          if (ppbStack_188 < (byte **)0x4) {
            ppbVar20 = (byte **)0x0;
            ppbVar13 = (byte **)0x1;
            *(byte *)ppbStack_17c = *(byte *)ppbStack_180 ^ uStack_138._0_1_;
            if ((byte **)0x1 < ppbStack_188) {
LAB_005ec9e8:
              ppbVar20 = (byte **)((int)ppbVar20 + 2);
              ppbStack_188 = (byte **)(uint)(ppbVar20 < ppbStack_188);
              *(byte *)((int)ppbStack_17c + (int)ppbVar13) =
                   *(byte *)((int)ppbStack_180 + (int)ppbVar13) ^
                   *(byte *)((int)&uStack_138 + (int)ppbVar13);
              if (ppbStack_188 != (byte **)0x0) {
                ppbStack_180 = (byte **)((int)ppbStack_180 + (int)ppbVar20);
                *(byte *)((int)ppbStack_17c + (int)ppbVar20) =
                     *(byte *)ppbStack_180 ^ *(byte *)((int)&uStack_138 + (int)ppbVar20);
              }
            }
          }
          else {
            *ppbStack_17c = (byte *)((uint)*ppbStack_180 ^ uStack_138);
            if (((iVar14 != 1) &&
                (ppbStack_17c[1] = (byte *)((uint)ppbStack_180[1] ^ uStack_134), iVar14 != 2)) &&
               (ppbStack_17c[2] = (byte *)((uint)ppbStack_180[2] ^ (uint)uStack_130), iVar14 != 3))
            {
              ppbStack_17c[3] = (byte *)((uint)ppbStack_180[3] ^ (uint)uStack_12c);
            }
            if (ppbVar20 != ppbVar13) {
              ppbVar13 = (byte **)((int)ppbVar20 + 1);
              *(byte *)(ppbStack_17c + iVar14) =
                   *(byte *)(ppbStack_180 + iVar14) ^ *(byte *)(&uStack_138 + iVar14);
              if (ppbVar13 < ppbStack_188) goto LAB_005ec9e8;
            }
          }
        }
      }
LAB_005eca90:
      puStack_178 = &uStack_138;
      (**(code **)(puStack_158 + -0x53ec))(pcStack_198 + (0xf - uStack_184),0,0x10 - (int)ppbVar21);
      (*pcStack_14c)(pcStack_198,puStack_178,ppbStack_194);
      ppbVar21 = (byte **)0x0;
      ppbVar13 = (byte **)(*(uint *)(pcStack_198 + 0x14) ^ uStack_134);
      *(uint *)(pcStack_198 + 0x10) = *(uint *)(pcStack_198 + 0x10) ^ uStack_138;
      *pcStack_198 = cVar2;
      *(byte ***)(pcStack_198 + 0x14) = ppbVar13;
      *(uint *)(pcStack_198 + 0x18) = *(uint *)(pcStack_198 + 0x18) ^ (uint)uStack_130;
      *(uint *)(pcStack_198 + 0x1c) = *(uint *)(pcStack_198 + 0x1c) ^ (uint)uStack_12c;
      ppbVar20 = uStack_12c;
      param_4 = uStack_130;
    }
    else {
      ppbVar21 = (byte **)&SUB_fffffffe;
    }
  }
  else {
    ppbVar21 = (byte **)0xffffffff;
  }
  if (pbStack_124 == *(byte **)puStack_190) {
    return ppbVar21;
  }
  pcStack_174 = CRYPTO_ccm128_decrypt_ccm64;
  pbVar19 = pbStack_124;
  (**(code **)(puStack_158 + -0x5330))();
  pcVar11 = pcStack_160;
  puVar10 = PTR___stack_chk_guard_006a9ae8;
  bVar25 = *pbVar19;
  pcVar29 = *(code **)(pbVar19 + 0x28);
  pbStack_19c = *(byte **)PTR___stack_chk_guard_006a9ae8;
  ppbVar15 = *(byte ***)(pbVar19 + 0x2c);
  pbVar26 = pbVar19 + 0x10;
  ppbVar21 = ppbVar20;
  if ((bVar25 & 0x40) == 0) {
    ppbVar21 = ppbVar15;
    (*pcVar29)();
  }
  uVar12 = bVar25 & 7;
  iVar14 = 0xf - uVar12;
  *pbVar19 = (byte)uVar12;
  if (iVar14 == 0xf) {
    uVar22 = 0;
  }
  else {
    pbVar26 = pbVar19 + iVar14;
    bVar17 = *pbVar26;
    *pbVar26 = 0;
    uVar22 = (uint)bVar17 << 8;
    if (0x10 - uVar12 != 0xf) {
      bVar4 = pbVar19[0x10 - uVar12];
      ppbVar21 = (byte **)(uint)bVar4;
      pbVar26 = (byte *)(0x11 - uVar12);
      pbVar19[0x10 - uVar12] = 0;
      uVar8 = CONCAT11(bVar17,bVar4);
      uVar22 = (uint)uVar8 << 8;
      if (pbVar26 != &DAT_0000000f) {
        pbVar26 = pbVar19 + (int)pbVar26;
        bVar17 = *pbVar26;
        ppbVar21 = (byte **)(uint)bVar17;
        *pbVar26 = 0;
        uVar9 = CONCAT21(uVar8,bVar17);
        uVar22 = (uint)uVar9 << 8;
        if (0x12 - uVar12 != 0xf) {
          bVar17 = pbVar19[0x12 - uVar12];
          ppbVar21 = (byte **)(uint)bVar17;
          pbVar26 = (byte *)(0x13 - uVar12);
          pbVar19[0x12 - uVar12] = 0;
          uVar22 = CONCAT31(uVar9,bVar17) << 8;
          if (pbVar26 != &DAT_0000000f) {
            pbVar26 = pbVar19 + (int)pbVar26;
            ppbVar21 = (byte **)(uint)*pbVar26;
            *pbVar26 = 0;
            uVar22 = ((uint)ppbVar21 | uVar22) << 8;
            if (0x14 - uVar12 != 0xf) {
              ppbVar21 = (byte **)(uint)pbVar19[0x14 - uVar12];
              pbVar26 = (byte *)(0x15 - uVar12);
              pbVar19[0x14 - uVar12] = 0;
              uVar22 = ((uint)ppbVar21 | uVar22) << 8;
              if (pbVar26 != &DAT_0000000f) {
                bVar17 = pbVar19[0xe];
                pbVar19[0xe] = 0;
                uVar22 = (bVar17 | uVar22) << 8;
              }
            }
          }
        }
      }
    }
  }
  ppbVar16 = (byte **)(pbVar19[0xf] | uVar22);
  pbVar19[0xf] = 1;
  if (ppbVar16 != param_4) {
    ppbVar13 = (byte **)0xffffffff;
    goto LAB_005ed1e0;
  }
  uVar22 = (uint)param_4 >> 4;
  ppbVar21 = (byte **)(pbVar19 + 0x10);
  if (uVar22 == 0) {
    if (param_4 != (byte **)0x0) goto LAB_005ed344;
  }
  else {
    (*pcVar11)(ppbVar13,ppbVar20,uVar22,ppbVar15,pbVar19,ppbVar21);
    ppbVar16 = param_4 + uVar22 * -4;
    ppbVar13 = (byte **)((int)ppbVar13 + ((uint)param_4 & 0xfffffff0));
    ppbVar20 = (byte **)((int)ppbVar20 + ((uint)param_4 & 0xfffffff0));
    if (ppbVar16 == (byte **)0x0) goto LAB_005ed164;
    uVar22 = (uVar22 & 0xff) + (uint)pbVar19[0xf];
    uVar28 = uVar22 >> 8;
    pbVar19[0xf] = (byte)uVar22;
    if ((uint)param_4 >> 0xc == 0) {
      if (uVar28 == 0) goto LAB_005ed344;
      uVar28 = pbVar19[0xe] + 1 >> 8;
      pbVar19[0xe] = (byte)(pbVar19[0xe] + 1);
LAB_005ed2bc:
      if (uVar28 == 0) goto LAB_005ed344;
      uVar28 = pbVar19[0xd] + 1 >> 8;
      pbVar19[0xd] = (byte)(pbVar19[0xd] + 1);
LAB_005ed2d4:
      if (uVar28 == 0) goto LAB_005ed344;
      uVar22 = pbVar19[0xc] + 1;
      pbVar19[0xc] = (byte)uVar22;
    }
    else {
      uVar22 = (uint)pbVar19[0xe] + ((uint)param_4 >> 0xc & 0xff) + uVar28;
      uVar28 = uVar22 >> 8;
      pbVar19[0xe] = (byte)uVar22;
      if ((uint)param_4 >> 0x14 == 0) goto LAB_005ed2bc;
      uVar22 = (uint)pbVar19[0xd] + ((uint)param_4 >> 0x14 & 0xff) + uVar28;
      uVar28 = uVar22 >> 8;
      pbVar19[0xd] = (byte)uVar22;
      if ((uint)param_4 >> 0x1c == 0) goto LAB_005ed2d4;
      uVar22 = (uint)pbVar19[0xc] + ((uint)param_4 >> 0x1c) + uVar28;
      pbVar19[0xc] = (byte)uVar22;
    }
    if ((((uVar22 >> 8 != 0) &&
         (bVar17 = pbVar19[0xb], pbVar19[0xb] = (byte)(bVar17 + 1), bVar17 + 1 >> 8 != 0)) &&
        (bVar17 = pbVar19[10], pbVar19[10] = (byte)(bVar17 + 1), bVar17 + 1 >> 8 != 0)) &&
       (bVar17 = pbVar19[9], pbVar19[9] = (byte)(bVar17 + 1), bVar17 + 1 >> 8 != 0)) {
      pbVar19[8] = pbVar19[8] + 1;
    }
LAB_005ed344:
    (*pcVar29)(pbVar19,&uStack_1b0,ppbVar15);
    if (((ppbVar16 < &DAT_00000005 ||
         (ppbVar21 < ppbVar20 + 1 && ppbVar20 < pbVar19 + 0x14 ||
         ppbVar21 < ppbVar13 + 1 && ppbVar13 < pbVar19 + 0x14)) ||
         ppbVar13 < ppbVar20 + 1 && ppbVar20 < ppbVar13 + 1) ||
       ((((uint)ppbVar20 | (uint)ppbVar13) & 3) != 0)) {
      bVar17 = *(byte *)ppbVar13;
      *(byte *)ppbVar20 = bVar17 ^ uStack_1b0._0_1_;
      pbVar19[0x10] = bVar17 ^ uStack_1b0._0_1_ ^ pbVar19[0x10];
      if (ppbVar16 != (byte **)0x1) {
        uStack_1b0._1_1_ = uStack_1b0._1_1_ ^ *(byte *)((int)ppbVar13 + 1);
        *(byte *)((int)ppbVar20 + 1) = uStack_1b0._1_1_;
        pbVar19[0x11] = uStack_1b0._1_1_ ^ pbVar19[0x11];
        if (ppbVar16 != (byte **)&SUB_00000002) {
          uStack_1b0._2_1_ = uStack_1b0._2_1_ ^ *(byte *)((int)ppbVar13 + 2);
          *(byte *)((int)ppbVar20 + 2) = uStack_1b0._2_1_;
          pbVar19[0x12] = uStack_1b0._2_1_ ^ pbVar19[0x12];
          if (ppbVar16 != (byte **)0x3) {
            uStack_1b0._3_1_ = (byte)uStack_1b0 ^ *(byte *)((int)ppbVar13 + 3);
            *(byte *)((int)ppbVar20 + 3) = (byte)uStack_1b0;
            pbVar19[0x13] = (byte)uStack_1b0 ^ pbVar19[0x13];
            if (ppbVar16 >= &DAT_00000005) {
              bVar17 = *(byte *)(ppbVar13 + 1);
              *(byte *)(ppbVar20 + 1) = uStack_1ac._0_1_ ^ bVar17;
              pbVar19[0x14] = uStack_1ac._0_1_ ^ bVar17 ^ pbVar19[0x14];
              if (&DAT_00000005 < ppbVar16) {
                uStack_1ac._1_1_ = uStack_1ac._1_1_ ^ *(byte *)((int)ppbVar13 + 5);
                *(byte *)((int)ppbVar20 + 5) = uStack_1ac._1_1_;
                pbVar19[0x15] = uStack_1ac._1_1_ ^ pbVar19[0x15];
                if (ppbVar16 != (byte **)&DAT_00000006) {
                  uStack_1ac._2_1_ = uStack_1ac._2_1_ ^ *(byte *)((int)ppbVar13 + 6);
                  *(byte *)((int)ppbVar20 + 6) = uStack_1ac._2_1_;
                  pbVar19[0x16] = uStack_1ac._2_1_ ^ pbVar19[0x16];
                  if (ppbVar16 != (byte **)&DAT_00000007) {
                    uStack_1ac._3_1_ = (byte)uStack_1ac ^ *(byte *)((int)ppbVar13 + 7);
                    *(byte *)((int)ppbVar20 + 7) = (byte)uStack_1ac;
                    pbVar19[0x17] = (byte)uStack_1ac ^ pbVar19[0x17];
                    if (ppbVar16 != (byte **)&DAT_00000008) {
                      bVar17 = *(byte *)(ppbVar13 + 2);
                      *(byte *)(ppbVar20 + 2) = uStack_1a8._0_1_ ^ bVar17;
                      pbVar19[0x18] = uStack_1a8._0_1_ ^ bVar17 ^ pbVar19[0x18];
                      if (ppbVar16 != (byte **)&DAT_00000009) {
                        uStack_1a8._1_1_ = uStack_1a8._1_1_ ^ *(byte *)((int)ppbVar13 + 9);
                        *(byte *)((int)ppbVar20 + 9) = uStack_1a8._1_1_;
                        pbVar19[0x19] = uStack_1a8._1_1_ ^ pbVar19[0x19];
                        if (ppbVar16 != (byte **)&DAT_0000000a) {
                          uStack_1a8._2_1_ = uStack_1a8._2_1_ ^ *(byte *)((int)ppbVar13 + 10);
                          *(byte *)((int)ppbVar20 + 10) = uStack_1a8._2_1_;
                          pbVar19[0x1a] = uStack_1a8._2_1_ ^ pbVar19[0x1a];
                          if (ppbVar16 != (byte **)&DAT_0000000b) {
                            uStack_1a8._3_1_ = (byte)uStack_1a8 ^ *(byte *)((int)ppbVar13 + 0xb);
                            *(byte *)((int)ppbVar20 + 0xb) = (byte)uStack_1a8;
                            pbVar19[0x1b] = (byte)uStack_1a8 ^ pbVar19[0x1b];
                            if (ppbVar16 != (byte **)&SUB_0000000c) {
                              bVar17 = *(byte *)(ppbVar13 + 3);
                              *(byte *)(ppbVar20 + 3) = uStack_1a4._0_1_ ^ bVar17;
                              pbVar19[0x1c] = uStack_1a4._0_1_ ^ bVar17 ^ pbVar19[0x1c];
                              if (ppbVar16 != (byte **)&DAT_0000000d) {
                                uStack_1a4._1_1_ = uStack_1a4._1_1_ ^ *(byte *)((int)ppbVar13 + 0xd)
                                ;
                                *(byte *)((int)ppbVar20 + 0xd) = uStack_1a4._1_1_;
                                pbVar19[0x1d] = uStack_1a4._1_1_ ^ pbVar19[0x1d];
                                if (ppbVar16 != (byte **)&DAT_0000000e) {
                                  uStack_1a4._2_1_ =
                                       uStack_1a4._2_1_ ^ *(byte *)((int)ppbVar13 + 0xe);
                                  *(byte *)((int)ppbVar20 + 0xe) = uStack_1a4._2_1_;
                                  pbVar19[0x1e] = uStack_1a4._2_1_ ^ pbVar19[0x1e];
                                  if (ppbVar16 != (byte **)&DAT_0000000f) {
                                    uStack_1a4._3_1_ =
                                         *(byte *)((int)ppbVar13 + 0xf) ^ (byte)uStack_1a4;
                                    *(byte *)((int)ppbVar20 + 0xf) = (byte)uStack_1a4;
                                    pbVar19[0x1f] = (byte)uStack_1a4 ^ pbVar19[0x1f];
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
      ppbVar27 = (byte **)0x1;
      if (ppbVar16 != (byte **)0x0) {
        ppbVar27 = ppbVar16;
      }
      iVar23 = ((uint)(ppbVar27 + -1) >> 2) + 1;
      ppbVar18 = (byte **)(iVar23 * 4);
      if (ppbVar16 < &SUB_00000004) {
        ppbVar18 = (byte **)0x0;
      }
      else {
        pbVar26 = *ppbVar13;
        *ppbVar20 = (byte *)(uStack_1b0 ^ (uint)pbVar26);
        *(uint *)(pbVar19 + 0x10) =
             (uint)(byte *)(uStack_1b0 ^ (uint)pbVar26) ^ *(uint *)(pbVar19 + 0x10);
        if (iVar23 != 1) {
          pbVar26 = ppbVar13[1];
          ppbVar20[1] = (byte *)((uint)pbVar26 ^ uStack_1ac);
          *(uint *)(pbVar19 + 0x14) =
               (uint)(byte *)((uint)pbVar26 ^ uStack_1ac) ^ *(uint *)(pbVar19 + 0x14);
          if (iVar23 != 2) {
            pbVar26 = ppbVar13[2];
            ppbVar20[2] = (byte *)((uint)pbVar26 ^ uStack_1a8);
            *(uint *)(pbVar19 + 0x18) =
                 (uint)(byte *)((uint)pbVar26 ^ uStack_1a8) ^ *(uint *)(pbVar19 + 0x18);
            if (iVar23 != 3) {
              pbVar26 = ppbVar13[3];
              ppbVar20[3] = (byte *)((uint)pbVar26 ^ (uint)uStack_1a4);
              *(uint *)(pbVar19 + 0x1c) =
                   (uint)(byte *)((uint)pbVar26 ^ (uint)uStack_1a4) ^ *(uint *)(pbVar19 + 0x1c);
            }
          }
        }
        if (ppbVar18 == ppbVar27) goto LAB_005ed544;
      }
      ppbVar27 = (byte **)((int)ppbVar18 + 1);
      bVar17 = *(byte *)((int)ppbVar13 + (int)ppbVar18) ^
               *(byte *)((int)&uStack_1b0 + (int)ppbVar18);
      *(byte *)((int)ppbVar20 + (int)ppbVar18) = bVar17;
      (pbVar19 + (int)ppbVar18)[0x10] = bVar17 ^ (pbVar19 + (int)ppbVar18)[0x10];
      if (ppbVar27 < ppbVar16) {
        ppbVar18 = (byte **)((int)ppbVar18 + 2);
        bVar17 = *(byte *)((int)ppbVar13 + (int)ppbVar27) ^
                 *(byte *)((int)&uStack_1b0 + (int)ppbVar27);
        *(byte *)((int)ppbVar20 + (int)ppbVar27) = bVar17;
        (pbVar19 + (int)ppbVar27)[0x10] = bVar17 ^ (pbVar19 + (int)ppbVar27)[0x10];
        if (ppbVar18 < ppbVar16) {
          bVar17 = *(byte *)((int)ppbVar13 + (int)ppbVar18) ^
                   *(byte *)((int)&uStack_1b0 + (int)ppbVar18);
          *(byte *)((int)ppbVar20 + (int)ppbVar18) = bVar17;
          (pbVar19 + (int)ppbVar18)[0x10] = bVar17 ^ (pbVar19 + (int)ppbVar18)[0x10];
        }
      }
    }
LAB_005ed544:
    (*pcVar29)(ppbVar21,ppbVar21,ppbVar15);
  }
LAB_005ed164:
  (*(code *)PTR_memset_006a99f4)(pbVar19 + (0xf - uVar12),0,0x10 - iVar14);
  (*pcVar29)(pbVar19,&uStack_1b0,ppbVar15);
  ppbVar13 = (byte **)0x0;
  pbVar26 = (byte *)(*(uint *)(pbVar19 + 0x14) ^ uStack_1ac);
  *(uint *)(pbVar19 + 0x10) = *(uint *)(pbVar19 + 0x10) ^ uStack_1b0;
  *pbVar19 = bVar25;
  *(byte **)(pbVar19 + 0x14) = pbVar26;
  *(uint *)(pbVar19 + 0x18) = *(uint *)(pbVar19 + 0x18) ^ uStack_1a8;
  *(uint *)(pbVar19 + 0x1c) = *(uint *)(pbVar19 + 0x1c) ^ (uint)uStack_1a4;
  ppbVar21 = uStack_1a4;
LAB_005ed1e0:
  if (pbStack_19c == *(byte **)puVar10) {
    return ppbVar13;
  }
  pbVar19 = pbStack_19c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  ppbVar13 = (byte **)((((uint)*pbVar19 << 0x1a) >> 0x1d) * 2 + 2);
  if (ppbVar13 <= ppbVar21) {
    (*(code *)PTR_memcpy_006a9aec)(pbVar26,pbVar19 + 0x10,ppbVar13);
    return ppbVar13;
  }
  return (byte **)0x0;
}

