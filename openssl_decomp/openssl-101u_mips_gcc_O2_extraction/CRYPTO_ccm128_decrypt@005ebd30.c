
/* WARNING: Could not reconcile some variable overlaps */

uint * CRYPTO_ccm128_decrypt(byte *param_1,uint *param_2,uint *param_3,uint *param_4)

{
  code cVar1;
  code cVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ushort uVar7;
  uint3 uVar8;
  undefined *puVar9;
  code *pcVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  uint *puVar15;
  byte bVar16;
  uint *puVar17;
  byte bVar21;
  uint uVar18;
  byte *pbVar19;
  int iVar20;
  byte *pbVar22;
  uint *puVar23;
  uint *puVar24;
  uint uVar25;
  uint *in_t0;
  uint in_t1;
  uint *puVar26;
  uint in_t2;
  uint in_t3;
  uint *unaff_s0;
  byte *unaff_s3;
  undefined4 *unaff_s5;
  code *pcVar27;
  uint *unaff_s7;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  byte *pbStack_114;
  code *pcStack_110;
  uint *puStack_10c;
  undefined *puStack_108;
  uint uStack_104;
  uint *puStack_100;
  uint uStack_fc;
  uint *puStack_f8;
  uint *puStack_f4;
  undefined4 *puStack_f0;
  code *pcStack_ec;
  code *pcStack_d8;
  uint *puStack_d4;
  undefined *puStack_d0;
  code *pcStack_c4;
  uint *puStack_c0;
  uint *puStack_bc;
  uint *puStack_b8;
  uint uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  byte *pbStack_9c;
  uint *puStack_98;
  code *pcStack_94;
  uint *puStack_90;
  byte *pbStack_8c;
  uint uStack_88;
  undefined4 *puStack_84;
  uint *puStack_80;
  uint *puStack_7c;
  byte *pbStack_78;
  code *pcStack_74;
  undefined4 *local_60;
  uint *local_58;
  uint *local_54;
  uint *local_50;
  undefined4 local_4c;
  code **local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  code *local_2c;
  
  local_60 = (undefined4 *)&_gp;
  local_4c = (uint)*param_1;
  pcStack_94 = *(code **)(param_1 + 0x28);
  puStack_90 = *(uint **)(param_1 + 0x2c);
  local_2c = *(code **)PTR___stack_chk_guard_006a9ae8;
  local_48 = (code **)PTR___stack_chk_guard_006a9ae8;
  puStack_f8 = (uint *)(param_1 + 0x10);
  puStack_f4 = param_3;
  local_54 = param_2;
  local_50 = param_3;
  if ((*param_1 & 0x40) == 0) {
    puStack_f4 = puStack_90;
    local_58 = param_4;
    (*pcStack_94)();
    param_4 = local_58;
  }
  uStack_88 = local_4c & 7;
  local_44 = 0xf - uStack_88;
  *param_1 = (byte)uStack_88;
  if (local_44 == 0xf) {
    uVar11 = 0;
  }
  else {
    puStack_f4 = (uint *)(param_1 + local_44);
    bVar21 = *(byte *)puStack_f4;
    puStack_f8 = (uint *)(0x10 - uStack_88);
    *(byte *)puStack_f4 = 0;
    uVar11 = (uint)bVar21 << 8;
    if (puStack_f8 != (uint *)&DAT_0000000f) {
      puStack_f8 = (uint *)(param_1 + (int)puStack_f8);
      bVar16 = *(byte *)puStack_f8;
      puStack_f4 = (uint *)(0x11 - uStack_88);
      *(byte *)puStack_f8 = 0;
      uVar7 = CONCAT11(bVar21,bVar16);
      uVar11 = (uint)uVar7 << 8;
      if (puStack_f4 != (uint *)&DAT_0000000f) {
        puStack_f4 = (uint *)(param_1 + (int)puStack_f4);
        bVar21 = *(byte *)puStack_f4;
        puStack_f8 = (uint *)(0x12 - uStack_88);
        *(byte *)puStack_f4 = 0;
        uVar8 = CONCAT21(uVar7,bVar21);
        uVar11 = (uint)uVar8 << 8;
        if (puStack_f8 != (uint *)&DAT_0000000f) {
          puStack_f8 = (uint *)(param_1 + (int)puStack_f8);
          bVar21 = *(byte *)puStack_f8;
          puStack_f4 = (uint *)(0x13 - uStack_88);
          *(byte *)puStack_f8 = 0;
          uVar11 = CONCAT31(uVar8,bVar21) << 8;
          if (puStack_f4 != (uint *)&DAT_0000000f) {
            puStack_f4 = (uint *)(param_1 + (int)puStack_f4);
            bVar21 = *(byte *)puStack_f4;
            puStack_f8 = (uint *)(0x14 - uStack_88);
            *(byte *)puStack_f4 = 0;
            uVar11 = (bVar21 | uVar11) << 8;
            if (puStack_f8 != (uint *)&DAT_0000000f) {
              puStack_f8 = (uint *)(param_1 + (int)puStack_f8);
              bVar21 = *(byte *)puStack_f8;
              puStack_f4 = (uint *)(0x15 - uStack_88);
              *(byte *)puStack_f8 = 0;
              uVar11 = (bVar21 | uVar11) << 8;
              if (puStack_f4 != (uint *)&DAT_0000000f) {
                bVar21 = param_1[0xe];
                param_1[0xe] = 0;
                uVar11 = (bVar21 | uVar11) << 8;
              }
            }
          }
        }
      }
    }
  }
  puStack_80 = (uint *)(uint)param_1[0xf];
  local_58 = (uint *)((uint)puStack_80 | uVar11);
  param_1[0xf] = 1;
  if (local_58 == param_4) {
    unaff_s5 = &local_40;
    if (&SUB_00000010 <= param_4) {
      unaff_s3 = param_1 + 0x10;
      puStack_80 = local_50;
      unaff_s7 = local_54;
      do {
        (*pcStack_94)(param_1,unaff_s5,puStack_90);
        bVar21 = param_1[0xf];
        param_1[0xf] = bVar21 + 1;
        if (((((byte)(bVar21 + 1) == 0) &&
             (bVar21 = param_1[0xe], param_1[0xe] = bVar21 + 1, (byte)(bVar21 + 1) == 0)) &&
            (bVar21 = param_1[0xd], param_1[0xd] = bVar21 + 1, (byte)(bVar21 + 1) == 0)) &&
           (((bVar21 = param_1[0xc], param_1[0xc] = bVar21 + 1, (byte)(bVar21 + 1) == 0 &&
             (bVar21 = param_1[0xb], param_1[0xb] = bVar21 + 1, (byte)(bVar21 + 1) == 0)) &&
            ((bVar21 = param_1[10], param_1[10] = bVar21 + 1, (byte)(bVar21 + 1) == 0 &&
             (bVar21 = param_1[9], param_1[9] = bVar21 + 1, (byte)(bVar21 + 1) == 0)))))) {
          param_1[8] = param_1[8] + 1;
        }
        uVar11 = (uint)unaff_s7 & 3;
        param_4 = param_4 + -4;
        uVar18 = (uint)(unaff_s7 + 1) & 3;
        puVar13 = unaff_s7 + 2;
        uVar25 = (uint)puVar13 & 3;
        uVar5 = (uint)(byte *)((int)unaff_s7 + 3) & 3;
        uVar6 = (uint)(byte *)((int)unaff_s7 + 7) & 3;
        puVar24 = unaff_s7 + 3;
        uVar4 = (uint)puVar24 & 3;
        in_t3 = local_40 ^
                ((*(int *)((int)unaff_s7 - uVar11) << uVar11 * 8 |
                 in_t3 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar5 + 1) * 8 |
                *(uint *)((byte *)((int)unaff_s7 + 3) + -uVar5) >> (3 - uVar5) * 8);
        pbVar19 = (byte *)((int)unaff_s7 + 0xb);
        uVar11 = (uint)pbVar19 & 3;
        in_t2 = local_3c ^
                ((*(int *)((int)(unaff_s7 + 1) - uVar18) << uVar18 * 8 |
                 in_t2 & 0xffffffffU >> (4 - uVar18) * 8) & -1 << (uVar6 + 1) * 8 |
                *(uint *)((byte *)((int)unaff_s7 + 7) + -uVar6) >> (3 - uVar6) * 8);
        pbVar22 = (byte *)((int)unaff_s7 + 0xf);
        uVar18 = (uint)pbVar22 & 3;
        unaff_s7 = unaff_s7 + 4;
        in_t1 = local_38 ^
                ((*(int *)((int)puVar13 - uVar25) << uVar25 * 8 |
                 in_t1 & 0xffffffffU >> (4 - uVar25) * 8) & -1 << (uVar11 + 1) * 8 |
                *(uint *)(pbVar19 + -uVar11) >> (3 - uVar11) * 8);
        in_t0 = (uint *)((uint)local_34 ^
                        ((*(int *)((int)puVar24 - uVar4) << uVar4 * 8 |
                         (uint)in_t0 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar18 + 1) * 8 |
                        *(uint *)(pbVar22 + -uVar18) >> (3 - uVar18) * 8));
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ in_t3;
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ in_t2;
        *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ in_t1;
        *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ (uint)in_t0;
        *puStack_80 = in_t3;
        puStack_80[1] = in_t2;
        puStack_80[2] = in_t1;
        puStack_80[3] = (uint)in_t0;
        puStack_80 = puStack_80 + 4;
        local_40 = in_t3;
        local_3c = in_t2;
        local_38 = in_t1;
        local_34 = in_t0;
        (*pcStack_94)(unaff_s3,unaff_s3,puStack_90);
      } while (&DAT_0000000f < param_4);
      puVar13 = local_58 + -4;
      local_58 = (uint *)((uint)local_58 & 0xf);
      iVar12 = ((uint)puVar13 >> 4) + 1;
      local_54 = local_54 + iVar12 * 4;
      local_50 = local_50 + iVar12 * 4;
      unaff_s0 = param_4;
    }
    if (local_58 != (uint *)0x0) {
      (*pcStack_94)(param_1,unaff_s5,puStack_90);
      puVar13 = (uint *)(param_1 + 0x10);
      if (((local_58 < &DAT_00000005 ||
           (puVar13 < local_50 + 1 && local_50 < param_1 + 0x14 ||
           puVar13 < local_54 + 1 && local_54 < param_1 + 0x14)) ||
           local_54 < local_50 + 1 && local_50 < local_54 + 1) ||
         ((((uint)local_54 | (uint)local_50) & 3) != 0)) {
        bVar21 = *(byte *)local_54;
        *(byte *)local_50 = bVar21 ^ local_40._0_1_;
        param_1[0x10] = bVar21 ^ local_40._0_1_ ^ param_1[0x10];
        if (local_58 != (uint *)0x1) {
          local_40._1_1_ = local_40._1_1_ ^ *(byte *)((int)local_54 + 1);
          *(byte *)((int)local_50 + 1) = local_40._1_1_;
          param_1[0x11] = local_40._1_1_ ^ param_1[0x11];
          if (local_58 != (uint *)&SUB_00000002) {
            local_40._2_1_ = local_40._2_1_ ^ *(byte *)((int)local_54 + 2);
            *(byte *)((int)local_50 + 2) = local_40._2_1_;
            param_1[0x12] = local_40._2_1_ ^ param_1[0x12];
            if (local_58 != (uint *)0x3) {
              local_40._3_1_ = (byte)local_40 ^ *(byte *)((int)local_54 + 3);
              *(byte *)((int)local_50 + 3) = (byte)local_40;
              param_1[0x13] = (byte)local_40 ^ param_1[0x13];
              if (local_58 >= &DAT_00000005) {
                bVar21 = *(byte *)(local_54 + 1);
                *(byte *)(local_50 + 1) = local_3c._0_1_ ^ bVar21;
                param_1[0x14] = local_3c._0_1_ ^ bVar21 ^ param_1[0x14];
                if (&DAT_00000005 < local_58) {
                  local_3c._1_1_ = local_3c._1_1_ ^ *(byte *)((int)local_54 + 5);
                  *(byte *)((int)local_50 + 5) = local_3c._1_1_;
                  param_1[0x15] = local_3c._1_1_ ^ param_1[0x15];
                  if (local_58 != (uint *)&DAT_00000006) {
                    local_3c._2_1_ = local_3c._2_1_ ^ *(byte *)((int)local_54 + 6);
                    *(byte *)((int)local_50 + 6) = local_3c._2_1_;
                    param_1[0x16] = local_3c._2_1_ ^ param_1[0x16];
                    if (local_58 != (uint *)&DAT_00000007) {
                      local_3c._3_1_ = (byte)local_3c ^ *(byte *)((int)local_54 + 7);
                      *(byte *)((int)local_50 + 7) = (byte)local_3c;
                      param_1[0x17] = (byte)local_3c ^ param_1[0x17];
                      if (local_58 != (uint *)&DAT_00000008) {
                        bVar21 = *(byte *)(local_54 + 2);
                        *(byte *)(local_50 + 2) = local_38._0_1_ ^ bVar21;
                        param_1[0x18] = local_38._0_1_ ^ bVar21 ^ param_1[0x18];
                        if (local_58 != (uint *)&DAT_00000009) {
                          local_38._1_1_ = local_38._1_1_ ^ *(byte *)((int)local_54 + 9);
                          *(byte *)((int)local_50 + 9) = local_38._1_1_;
                          param_1[0x19] = local_38._1_1_ ^ param_1[0x19];
                          if (local_58 != (uint *)&DAT_0000000a) {
                            local_38._2_1_ = local_38._2_1_ ^ *(byte *)((int)local_54 + 10);
                            *(byte *)((int)local_50 + 10) = local_38._2_1_;
                            param_1[0x1a] = local_38._2_1_ ^ param_1[0x1a];
                            if (local_58 != (uint *)&DAT_0000000b) {
                              local_38._3_1_ = (byte)local_38 ^ *(byte *)((int)local_54 + 0xb);
                              *(byte *)((int)local_50 + 0xb) = (byte)local_38;
                              param_1[0x1b] = (byte)local_38 ^ param_1[0x1b];
                              if (local_58 != (uint *)&SUB_0000000c) {
                                bVar21 = *(byte *)(local_54 + 3);
                                *(byte *)(local_50 + 3) = local_34._0_1_ ^ bVar21;
                                param_1[0x1c] = local_34._0_1_ ^ bVar21 ^ param_1[0x1c];
                                if (local_58 != (uint *)&DAT_0000000d) {
                                  local_34._1_1_ = local_34._1_1_ ^ *(byte *)((int)local_54 + 0xd);
                                  *(byte *)((int)local_50 + 0xd) = local_34._1_1_;
                                  param_1[0x1d] = local_34._1_1_ ^ param_1[0x1d];
                                  if (local_58 == (uint *)&DAT_0000000f) {
                                    local_34._2_1_ = local_34._2_1_ ^ *(byte *)((int)local_54 + 0xe)
                                    ;
                                    *(byte *)((int)local_50 + 0xe) = local_34._2_1_;
                                    param_1[0x1e] = local_34._2_1_ ^ param_1[0x1e];
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
        iVar12 = ((uint)(local_58 + -1) >> 2) + 1;
        puVar24 = (uint *)(iVar12 * 4);
        if ((byte *)((int)local_58 + -1) < (byte *)0x3) {
          puVar24 = (uint *)0x0;
        }
        else {
          uVar11 = *local_54;
          *local_50 = uVar11 ^ local_40;
          *(uint *)(param_1 + 0x10) = uVar11 ^ local_40 ^ *(uint *)(param_1 + 0x10);
          if (iVar12 != 1) {
            uVar11 = local_54[1];
            local_50[1] = local_3c ^ uVar11;
            *(uint *)(param_1 + 0x14) = local_3c ^ uVar11 ^ *(uint *)(param_1 + 0x14);
            if (iVar12 != 2) {
              uVar11 = local_54[2];
              local_50[2] = local_38 ^ uVar11;
              *(uint *)(param_1 + 0x18) = local_38 ^ uVar11 ^ *(uint *)(param_1 + 0x18);
              if (iVar12 != 3) {
                uVar11 = local_54[3];
                local_50[3] = (uint)local_34 ^ uVar11;
                *(uint *)(param_1 + 0x1c) = (uint)local_34 ^ uVar11 ^ *(uint *)(param_1 + 0x1c);
              }
            }
          }
          if (local_58 == puVar24) goto LAB_005ec360;
        }
        puVar26 = (uint *)((int)puVar24 + 1);
        bVar21 = *(byte *)((int)local_54 + (int)puVar24) ^ *(byte *)((int)&local_40 + (int)puVar24);
        *(byte *)((int)local_50 + (int)puVar24) = bVar21;
        (param_1 + (int)puVar24)[0x10] = bVar21 ^ (param_1 + (int)puVar24)[0x10];
        if (puVar26 < local_58) {
          puVar24 = (uint *)((int)puVar24 + 2);
          puStack_80 = (uint *)(uint)(puVar24 < local_58);
          bVar21 = *(byte *)((int)local_54 + (int)puVar26) ^
                   *(byte *)((int)&local_40 + (int)puVar26);
          *(byte *)((int)local_50 + (int)puVar26) = bVar21;
          (param_1 + (int)puVar26)[0x10] = bVar21 ^ (param_1 + (int)puVar26)[0x10];
          if (puStack_80 != (uint *)0x0) {
            unaff_s7 = (uint *)((int)local_54 + (int)puVar24);
            bVar21 = *(byte *)unaff_s7 ^ *(byte *)((int)&local_40 + (int)puVar24);
            *(byte *)((int)local_50 + (int)puVar24) = bVar21;
            (param_1 + (int)puVar24)[0x10] = bVar21 ^ (param_1 + (int)puVar24)[0x10];
          }
        }
      }
LAB_005ec360:
      (*pcStack_94)(puVar13,puVar13,puStack_90);
    }
    (*(code *)local_60[-0x14fb])(param_1 + (0xf - uStack_88),0,0x10 - local_44);
    (*pcStack_94)(param_1,unaff_s5,puStack_90);
    puVar13 = (uint *)0x0;
    puStack_f4 = (uint *)(*(uint *)(param_1 + 0x14) ^ local_3c);
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ local_40;
    puStack_f8 = (uint *)(*(uint *)(param_1 + 0x18) ^ local_38);
    *(uint **)(param_1 + 0x14) = puStack_f4;
    *param_1 = (byte)local_4c;
    *(uint **)(param_1 + 0x18) = puStack_f8;
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ (uint)local_34;
    param_4 = local_34;
  }
  else {
    puVar13 = (uint *)0xffffffff;
  }
  if (local_2c == *local_48) {
    return puVar13;
  }
  pcStack_74 = CRYPTO_ccm128_encrypt_ccm64;
  pcStack_110 = local_2c;
  (*(code *)local_60[-0x14cc])();
  puStack_f0 = local_60;
  puStack_108 = PTR___stack_chk_guard_006a9ae8;
  pcStack_c4 = *(code **)(pcStack_110 + 0x28);
  puStack_d0 = &_gp;
  cVar1 = *pcStack_110;
  uStack_104 = (uint)(byte)cVar1;
  puStack_10c = *(uint **)(pcStack_110 + 0x2c);
  pbStack_9c = *(byte **)PTR___stack_chk_guard_006a9ae8;
  puVar13 = puStack_f8;
  puVar24 = puStack_f4;
  puStack_98 = unaff_s0;
  pbStack_8c = unaff_s3;
  puStack_84 = unaff_s5;
  puStack_7c = unaff_s7;
  pbStack_78 = param_1;
  if (((byte)cVar1 & 0x40) == 0) {
    puVar13 = (uint *)(pcStack_110 + 0x10);
    puVar24 = puStack_10c;
    puStack_c0 = param_4;
    (*pcStack_c4)();
    uVar11 = *(uint *)(pcStack_110 + 0x24);
    uVar18 = uVar11 + 1;
    *(uint *)(pcStack_110 + 0x24) = uVar18;
    *(uint *)(pcStack_110 + 0x20) = (uint)(uVar18 < uVar11) + *(int *)(pcStack_110 + 0x20);
    param_4 = puStack_c0;
  }
  uStack_fc = uStack_104 & 7;
  puVar26 = (uint *)(0xf - uStack_fc);
  *pcStack_110 = SUB41(uStack_fc,0);
  if (puVar26 == (uint *)&DAT_0000000f) {
    uVar11 = 0;
  }
  else {
    puVar13 = (uint *)(pcStack_110 + (int)puVar26);
    bVar21 = *(byte *)puVar13;
    *(byte *)puVar13 = 0;
    uVar11 = (uint)bVar21 << 8;
    if (0x10 - uStack_fc != 0xf) {
      cVar2 = pcStack_110[0x10 - uStack_fc];
      puVar24 = (uint *)(uint)(byte)cVar2;
      puVar13 = (uint *)(0x11 - uStack_fc);
      pcStack_110[0x10 - uStack_fc] = (code)0x0;
      uVar7 = CONCAT11(bVar21,cVar2);
      uVar11 = (uint)uVar7 << 8;
      if (puVar13 != (uint *)&DAT_0000000f) {
        puVar13 = (uint *)(pcStack_110 + (int)puVar13);
        bVar21 = *(byte *)puVar13;
        puVar24 = (uint *)(uint)bVar21;
        *(byte *)puVar13 = 0;
        uVar8 = CONCAT21(uVar7,bVar21);
        uVar11 = (uint)uVar8 << 8;
        if (0x12 - uStack_fc != 0xf) {
          cVar2 = pcStack_110[0x12 - uStack_fc];
          puVar24 = (uint *)(uint)(byte)cVar2;
          puVar13 = (uint *)(0x13 - uStack_fc);
          pcStack_110[0x12 - uStack_fc] = (code)0x0;
          uVar11 = CONCAT31(uVar8,cVar2) << 8;
          if (puVar13 != (uint *)&DAT_0000000f) {
            puVar13 = (uint *)(pcStack_110 + (int)puVar13);
            puVar24 = (uint *)(uint)*(byte *)puVar13;
            *(byte *)puVar13 = 0;
            uVar11 = ((uint)puVar24 | uVar11) << 8;
            if (0x14 - uStack_fc != 0xf) {
              puVar24 = (uint *)(uint)(byte)pcStack_110[0x14 - uStack_fc];
              puVar13 = (uint *)(0x15 - uStack_fc);
              pcStack_110[0x14 - uStack_fc] = (code)0x0;
              uVar11 = ((uint)puVar24 | uVar11) << 8;
              if (puVar13 != (uint *)&DAT_0000000f) {
                cVar2 = pcStack_110[0xe];
                pcStack_110[0xe] = (code)0x0;
                uVar11 = ((byte)cVar2 | uVar11) << 8;
              }
            }
          }
        }
      }
    }
  }
  puStack_100 = (uint *)((byte)pcStack_110[0xf] | uVar11);
  pcStack_110[0xf] = (code)0x1;
  if (puStack_100 == param_4) {
    puVar24 = (uint *)0x20000000;
    puVar13 = (uint *)0x20000001;
    uVar18 = (uint)((int)param_4 + 0xf) >> 3 | 1;
    uVar11 = uVar18 + *(int *)(pcStack_110 + 0x24);
    uVar18 = (uint)(uVar11 < uVar18) + *(int *)(pcStack_110 + 0x20);
    *(uint *)(pcStack_110 + 0x24) = uVar11;
    *(uint *)(pcStack_110 + 0x20) = uVar18;
    if ((uVar18 < 0x20000001) && ((uVar18 != 0x20000000 || (uVar11 == 0)))) {
      puVar24 = (uint *)((uint)puStack_100 >> 4);
      puVar13 = (uint *)(pcStack_110 + 0x10);
      if (puVar24 == (uint *)0x0) {
        if (puStack_100 != (uint *)0x0) goto LAB_005ec7b4;
      }
      else {
        pcStack_d8 = pcStack_110;
        puStack_d4 = puVar13;
        puStack_c0 = puVar24;
        puStack_bc = puVar13;
        puStack_b8 = puVar26;
        (*(code *)puStack_f0)(puStack_f8,puStack_f4,puVar24,puStack_10c);
        uVar11 = (int)puStack_c0 * 0x10;
        puStack_100 = puStack_100 + (int)puStack_c0 * -4;
        puStack_f8 = puStack_f8 + (int)puStack_c0 * 4;
        puStack_f4 = puStack_f4 + (int)puStack_c0 * 4;
        puVar26 = puStack_b8;
        if (puStack_100 == (uint *)0x0) goto LAB_005eca90;
        uVar18 = (uint)(byte)pcStack_110[0xf] + ((uint)puStack_c0 & 0xff);
        uVar25 = uVar18 >> 8;
        pcStack_110[0xf] = SUB41(uVar18,0);
        puVar13 = puStack_bc;
        if (uVar11 >> 0xc == 0) {
          if (uVar25 == 0) goto LAB_005ec7b4;
          uVar25 = (byte)pcStack_110[0xe] + 1 >> 8;
          pcStack_110[0xe] = SUB41((byte)pcStack_110[0xe] + 1,0);
LAB_005ecbb0:
          if (uVar25 == 0) goto LAB_005ec7b4;
          uVar25 = (byte)pcStack_110[0xd] + 1 >> 8;
          pcStack_110[0xd] = SUB41((byte)pcStack_110[0xd] + 1,0);
LAB_005ecbc8:
          if (uVar25 == 0) goto LAB_005ec7b4;
          uVar11 = (byte)pcStack_110[0xc] + 1;
          pcStack_110[0xc] = SUB41(uVar11,0);
        }
        else {
          uVar18 = (uint)(byte)pcStack_110[0xe] + (uVar11 >> 0xc & 0xff) + uVar25;
          uVar25 = uVar18 >> 8;
          pcStack_110[0xe] = SUB41(uVar18,0);
          if (uVar11 >> 0x14 == 0) goto LAB_005ecbb0;
          uVar18 = (uint)(byte)pcStack_110[0xd] + (uVar11 >> 0x14 & 0xff) + uVar25;
          uVar25 = uVar18 >> 8;
          pcStack_110[0xd] = SUB41(uVar18,0);
          if (uVar11 >> 0x1c == 0) goto LAB_005ecbc8;
          uVar11 = (uint)(byte)pcStack_110[0xc] + (uVar11 >> 0x1c) + uVar25;
          pcStack_110[0xc] = SUB41(uVar11,0);
        }
        if ((((uVar11 >> 8 != 0) &&
             (cVar2 = pcStack_110[0xb], pcStack_110[0xb] = SUB41((byte)cVar2 + 1,0),
             (byte)cVar2 + 1 >> 8 != 0)) &&
            (cVar2 = pcStack_110[10], pcStack_110[10] = SUB41((byte)cVar2 + 1,0),
            (byte)cVar2 + 1 >> 8 != 0)) &&
           (cVar2 = pcStack_110[9], pcStack_110[9] = SUB41((byte)cVar2 + 1,0),
           (byte)cVar2 + 1 >> 8 != 0)) {
          pcStack_110[8] = (code)((char)pcStack_110[8] + 1);
        }
LAB_005ec7b4:
        puStack_b8 = puStack_f8 + 1;
        uStack_b4 = (uint)(puStack_100 < &DAT_00000006);
        puStack_bc = (uint *)(uStack_b4 ^ 1);
        if ((((uint)puStack_bc & (puStack_f8 < pcStack_110 + 0x14 ^ 1 | puVar13 < puStack_b8 ^ 1))
             == 0) || (((uint)puStack_f8 & 3) != 0)) {
          pcStack_110[0x10] = (code)((byte)pcStack_110[0x10] ^ *(byte *)puStack_f8);
          if (((((puStack_100 != (uint *)0x1) &&
                ((pcStack_110[0x11] =
                       (code)((byte)pcStack_110[0x11] ^ *(byte *)((int)puStack_f8 + 1)),
                 puStack_100 != (uint *)&SUB_00000002 &&
                 (pcStack_110[0x12] =
                       (code)((byte)pcStack_110[0x12] ^ *(byte *)((int)puStack_f8 + 2)),
                 puStack_100 != (uint *)0x3)))) &&
               (pcStack_110[0x13] = (code)((byte)pcStack_110[0x13] ^ *(byte *)((int)puStack_f8 + 3))
               , puStack_100 != (uint *)&SUB_00000004)) &&
              (((((pcStack_110[0x14] = (code)((byte)pcStack_110[0x14] ^ *(byte *)(puStack_f8 + 1)),
                  uStack_b4 == 0 &&
                  (pcStack_110[0x15] =
                        (code)((byte)pcStack_110[0x15] ^ *(byte *)((int)puStack_f8 + 5)),
                  &DAT_00000006 < puStack_100)) &&
                 (pcStack_110[0x16] =
                       (code)((byte)pcStack_110[0x16] ^ *(byte *)((int)puStack_f8 + 6)),
                 puStack_100 != (uint *)&DAT_00000007)) &&
                (((pcStack_110[0x17] =
                        (code)((byte)pcStack_110[0x17] ^ *(byte *)((int)puStack_f8 + 7)),
                  puStack_100 != (uint *)&DAT_00000008 &&
                  (pcStack_110[0x18] = (code)((byte)pcStack_110[0x18] ^ *(byte *)(puStack_f8 + 2)),
                  puStack_100 != (uint *)&DAT_00000009)) &&
                 ((pcStack_110[0x19] =
                        (code)((byte)pcStack_110[0x19] ^ *(byte *)((int)puStack_f8 + 9)),
                  puStack_100 != (uint *)&DAT_0000000a &&
                  ((pcStack_110[0x1a] =
                         (code)((byte)pcStack_110[0x1a] ^ *(byte *)((int)puStack_f8 + 10)),
                   puStack_100 != (uint *)&DAT_0000000b &&
                   (pcStack_110[0x1b] =
                         (code)((byte)pcStack_110[0x1b] ^ *(byte *)((int)puStack_f8 + 0xb)),
                   puStack_100 != (uint *)&SUB_0000000c)))))))) &&
               (pcStack_110[0x1c] = (code)((byte)pcStack_110[0x1c] ^ *(byte *)(puStack_f8 + 3)),
               puStack_100 != (uint *)&DAT_0000000d)))) &&
             ((pcStack_110[0x1d] =
                    (code)((byte)pcStack_110[0x1d] ^ *(byte *)((int)puStack_f8 + 0xd)),
              puStack_100 != (uint *)&DAT_0000000e &&
              (pcStack_110[0x1e] =
                    (code)((byte)pcStack_110[0x1e] ^ *(byte *)((int)puStack_f8 + 0xe)),
              puStack_100 != (uint *)&DAT_0000000f)))) {
            pcStack_110[0x1f] = (code)((byte)pcStack_110[0x1f] ^ *(byte *)((int)puStack_f8 + 0xf));
          }
        }
        else {
          puVar24 = (uint *)0x1;
          if (puStack_100 != (uint *)0x0) {
            puVar24 = puStack_100;
          }
          iVar12 = ((uint)(puVar24 + -1) >> 2) + 1;
          puVar14 = (uint *)(iVar12 * 4);
          if (puStack_100 < &SUB_00000004) {
            puVar14 = (uint *)0x0;
          }
          else {
            *(uint *)(pcStack_110 + 0x10) = *puStack_f8 ^ *(uint *)(pcStack_110 + 0x10);
            if (((iVar12 != 1) &&
                (*(uint *)(pcStack_110 + 0x14) = *(uint *)(pcStack_110 + 0x14) ^ puStack_f8[1],
                iVar12 != 2)) &&
               (*(uint *)(pcStack_110 + 0x18) = puStack_f8[2] ^ *(uint *)(pcStack_110 + 0x18),
               iVar12 != 3)) {
              *(uint *)(pcStack_110 + 0x1c) = puStack_f8[3] ^ *(uint *)(pcStack_110 + 0x1c);
            }
            if (puVar24 == puVar14) goto LAB_005ec8c8;
          }
          puVar24 = (uint *)((int)puVar14 + 1);
          (pcStack_110 + (int)puVar14)[0x10] =
               (code)(*(byte *)((int)puStack_f8 + (int)puVar14) ^
                     (byte)(pcStack_110 + (int)puVar14)[0x10]);
          if (puVar24 < puStack_100) {
            puVar14 = (uint *)((int)puVar14 + 2);
            (pcStack_110 + (int)puVar24)[0x10] =
                 (code)(*(byte *)((int)puStack_f8 + (int)puVar24) ^
                       (byte)(pcStack_110 + (int)puVar24)[0x10]);
            if (puVar14 < puStack_100) {
              (pcStack_110 + (int)puVar14)[0x10] =
                   (code)(*(byte *)((int)puStack_f8 + (int)puVar14) ^
                         (byte)(pcStack_110 + (int)puVar14)[0x10]);
            }
          }
        }
LAB_005ec8c8:
        puStack_c0 = puVar26;
        (*pcStack_c4)(puVar13,puVar13,puStack_10c);
        (*pcStack_c4)(pcStack_110,&uStack_b0,puStack_10c);
        puVar26 = puStack_c0;
        if ((((uint)puStack_bc & (puStack_f8 < puStack_f4 + 1 ^ 1 | puStack_f4 < puStack_b8 ^ 1)) ==
             0) || ((((uint)puStack_f4 | (uint)puStack_f8) & 3) != 0)) {
          *(byte *)puStack_f4 = uStack_b0._0_1_ ^ *(byte *)puStack_f8;
          if (puStack_100 != (uint *)0x1) {
            *(byte *)((int)puStack_f4 + 1) = uStack_b0._1_1_ ^ *(byte *)((int)puStack_f8 + 1);
            if (puStack_100 != (uint *)&SUB_00000002) {
              *(byte *)((int)puStack_f4 + 2) = uStack_b0._2_1_ ^ *(byte *)((int)puStack_f8 + 2);
              if (puStack_100 != (uint *)0x3) {
                *(byte *)((int)puStack_f4 + 3) = (byte)uStack_b0 ^ *(byte *)((int)puStack_f8 + 3);
                if (puStack_100 != (uint *)&SUB_00000004) {
                  *(byte *)(puStack_f4 + 1) = uStack_ac._0_1_ ^ *(byte *)(puStack_f8 + 1);
                  if (uStack_b4 == 0) {
                    *(byte *)((int)puStack_f4 + 5) =
                         uStack_ac._1_1_ ^ *(byte *)((int)puStack_f8 + 5);
                    if (&DAT_00000006 < puStack_100) {
                      *(byte *)((int)puStack_f4 + 6) =
                           uStack_ac._2_1_ ^ *(byte *)((int)puStack_f8 + 6);
                      if (puStack_100 != (uint *)&DAT_00000007) {
                        *(byte *)((int)puStack_f4 + 7) =
                             (byte)uStack_ac ^ *(byte *)((int)puStack_f8 + 7);
                        if (puStack_100 != (uint *)&DAT_00000008) {
                          *(byte *)(puStack_f4 + 2) = uStack_a8._0_1_ ^ *(byte *)(puStack_f8 + 2);
                          if (puStack_100 != (uint *)&DAT_00000009) {
                            *(byte *)((int)puStack_f4 + 9) =
                                 uStack_a8._1_1_ ^ *(byte *)((int)puStack_f8 + 9);
                            if (puStack_100 != (uint *)&DAT_0000000a) {
                              *(byte *)((int)puStack_f4 + 10) =
                                   uStack_a8._2_1_ ^ *(byte *)((int)puStack_f8 + 10);
                              if (puStack_100 != (uint *)&DAT_0000000b) {
                                *(byte *)((int)puStack_f4 + 0xb) =
                                     (byte)uStack_a8 ^ *(byte *)((int)puStack_f8 + 0xb);
                                if (puStack_100 != (uint *)&SUB_0000000c) {
                                  *(byte *)(puStack_f4 + 3) =
                                       uStack_a4._0_1_ ^ *(byte *)(puStack_f8 + 3);
                                  if (puStack_100 != (uint *)&DAT_0000000d) {
                                    *(byte *)((int)puStack_f4 + 0xd) =
                                         uStack_a4._1_1_ ^ *(byte *)((int)puStack_f8 + 0xd);
                                    if (puStack_100 != (uint *)&DAT_0000000e) {
                                      *(byte *)((int)puStack_f4 + 0xe) =
                                           uStack_a4._2_1_ ^ *(byte *)((int)puStack_f8 + 0xe);
                                      if (puStack_100 != (uint *)&DAT_0000000f) {
                                        *(byte *)((int)puStack_f4 + 0xf) =
                                             *(byte *)((int)puStack_f8 + 0xf) ^ (byte)uStack_a4;
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
          puVar13 = (uint *)0x1;
          if (puStack_100 != (uint *)0x0) {
            puVar13 = puStack_100;
          }
          iVar12 = ((uint)(puVar13 + -1) >> 2) + 1;
          puVar24 = (uint *)(iVar12 * 4);
          if (puStack_100 < (uint *)0x4) {
            puVar24 = (uint *)0x0;
            puVar13 = (uint *)0x1;
            *(byte *)puStack_f4 = *(byte *)puStack_f8 ^ uStack_b0._0_1_;
            if ((uint *)0x1 < puStack_100) {
LAB_005ec9e8:
              puVar24 = (uint *)((int)puVar24 + 2);
              puStack_100 = (uint *)(uint)(puVar24 < puStack_100);
              *(byte *)((int)puStack_f4 + (int)puVar13) =
                   *(byte *)((int)puStack_f8 + (int)puVar13) ^
                   *(byte *)((int)&uStack_b0 + (int)puVar13);
              if (puStack_100 != (uint *)0x0) {
                puStack_f8 = (uint *)((int)puStack_f8 + (int)puVar24);
                *(byte *)((int)puStack_f4 + (int)puVar24) =
                     *(byte *)puStack_f8 ^ *(byte *)((int)&uStack_b0 + (int)puVar24);
              }
            }
          }
          else {
            *puStack_f4 = *puStack_f8 ^ uStack_b0;
            if (((iVar12 != 1) && (puStack_f4[1] = puStack_f8[1] ^ uStack_ac, iVar12 != 2)) &&
               (puStack_f4[2] = puStack_f8[2] ^ (uint)uStack_a8, iVar12 != 3)) {
              puStack_f4[3] = puStack_f8[3] ^ (uint)uStack_a4;
            }
            if (puVar24 != puVar13) {
              puVar13 = (uint *)((int)puVar24 + 1);
              *(byte *)(puStack_f4 + iVar12) =
                   *(byte *)(puStack_f8 + iVar12) ^ *(byte *)(&uStack_b0 + iVar12);
              if (puVar13 < puStack_100) goto LAB_005ec9e8;
            }
          }
        }
      }
LAB_005eca90:
      puStack_f0 = &uStack_b0;
      (**(code **)(puStack_d0 + -0x53ec))(pcStack_110 + (0xf - uStack_fc),0,0x10 - (int)puVar26);
      (*pcStack_c4)(pcStack_110,puStack_f0,puStack_10c);
      puVar26 = (uint *)0x0;
      puVar13 = (uint *)(*(uint *)(pcStack_110 + 0x14) ^ uStack_ac);
      *(uint *)(pcStack_110 + 0x10) = *(uint *)(pcStack_110 + 0x10) ^ uStack_b0;
      *pcStack_110 = cVar1;
      *(uint **)(pcStack_110 + 0x14) = puVar13;
      *(uint *)(pcStack_110 + 0x18) = *(uint *)(pcStack_110 + 0x18) ^ (uint)uStack_a8;
      *(uint *)(pcStack_110 + 0x1c) = *(uint *)(pcStack_110 + 0x1c) ^ (uint)uStack_a4;
      puVar24 = uStack_a4;
      param_4 = uStack_a8;
    }
    else {
      puVar26 = (uint *)&SUB_fffffffe;
    }
  }
  else {
    puVar26 = (uint *)0xffffffff;
  }
  if (pbStack_9c == *(byte **)puStack_108) {
    return puVar26;
  }
  pcStack_ec = CRYPTO_ccm128_decrypt_ccm64;
  pbVar19 = pbStack_9c;
  (**(code **)(puStack_d0 + -0x5330))();
  pcVar10 = pcStack_d8;
  puVar9 = PTR___stack_chk_guard_006a9ae8;
  bVar21 = *pbVar19;
  pcVar27 = *(code **)(pbVar19 + 0x28);
  pbStack_114 = *(byte **)PTR___stack_chk_guard_006a9ae8;
  puVar14 = *(uint **)(pbVar19 + 0x2c);
  pbVar22 = pbVar19 + 0x10;
  puVar26 = puVar24;
  if ((bVar21 & 0x40) == 0) {
    puVar26 = puVar14;
    (*pcVar27)();
  }
  uVar11 = bVar21 & 7;
  iVar12 = 0xf - uVar11;
  *pbVar19 = (byte)uVar11;
  if (iVar12 == 0xf) {
    uVar18 = 0;
  }
  else {
    pbVar22 = pbVar19 + iVar12;
    bVar16 = *pbVar22;
    *pbVar22 = 0;
    uVar18 = (uint)bVar16 << 8;
    if (0x10 - uVar11 != 0xf) {
      bVar3 = pbVar19[0x10 - uVar11];
      puVar26 = (uint *)(uint)bVar3;
      pbVar22 = (byte *)(0x11 - uVar11);
      pbVar19[0x10 - uVar11] = 0;
      uVar7 = CONCAT11(bVar16,bVar3);
      uVar18 = (uint)uVar7 << 8;
      if (pbVar22 != &DAT_0000000f) {
        pbVar22 = pbVar19 + (int)pbVar22;
        bVar16 = *pbVar22;
        puVar26 = (uint *)(uint)bVar16;
        *pbVar22 = 0;
        uVar8 = CONCAT21(uVar7,bVar16);
        uVar18 = (uint)uVar8 << 8;
        if (0x12 - uVar11 != 0xf) {
          bVar16 = pbVar19[0x12 - uVar11];
          puVar26 = (uint *)(uint)bVar16;
          pbVar22 = (byte *)(0x13 - uVar11);
          pbVar19[0x12 - uVar11] = 0;
          uVar18 = CONCAT31(uVar8,bVar16) << 8;
          if (pbVar22 != &DAT_0000000f) {
            pbVar22 = pbVar19 + (int)pbVar22;
            puVar26 = (uint *)(uint)*pbVar22;
            *pbVar22 = 0;
            uVar18 = ((uint)puVar26 | uVar18) << 8;
            if (0x14 - uVar11 != 0xf) {
              puVar26 = (uint *)(uint)pbVar19[0x14 - uVar11];
              pbVar22 = (byte *)(0x15 - uVar11);
              pbVar19[0x14 - uVar11] = 0;
              uVar18 = ((uint)puVar26 | uVar18) << 8;
              if (pbVar22 != &DAT_0000000f) {
                bVar16 = pbVar19[0xe];
                pbVar19[0xe] = 0;
                uVar18 = (bVar16 | uVar18) << 8;
              }
            }
          }
        }
      }
    }
  }
  puVar15 = (uint *)(pbVar19[0xf] | uVar18);
  pbVar19[0xf] = 1;
  if (puVar15 != param_4) {
    puVar13 = (uint *)0xffffffff;
    goto LAB_005ed1e0;
  }
  uVar18 = (uint)param_4 >> 4;
  puVar26 = (uint *)(pbVar19 + 0x10);
  if (uVar18 == 0) {
    if (param_4 != (uint *)0x0) goto LAB_005ed344;
  }
  else {
    (*pcVar10)(puVar13,puVar24,uVar18,puVar14,pbVar19,puVar26);
    puVar15 = param_4 + uVar18 * -4;
    puVar13 = (uint *)((int)puVar13 + ((uint)param_4 & 0xfffffff0));
    puVar24 = (uint *)((int)puVar24 + ((uint)param_4 & 0xfffffff0));
    if (puVar15 == (uint *)0x0) goto LAB_005ed164;
    uVar18 = (uVar18 & 0xff) + (uint)pbVar19[0xf];
    uVar25 = uVar18 >> 8;
    pbVar19[0xf] = (byte)uVar18;
    if ((uint)param_4 >> 0xc == 0) {
      if (uVar25 == 0) goto LAB_005ed344;
      uVar25 = pbVar19[0xe] + 1 >> 8;
      pbVar19[0xe] = (byte)(pbVar19[0xe] + 1);
LAB_005ed2bc:
      if (uVar25 == 0) goto LAB_005ed344;
      uVar25 = pbVar19[0xd] + 1 >> 8;
      pbVar19[0xd] = (byte)(pbVar19[0xd] + 1);
LAB_005ed2d4:
      if (uVar25 == 0) goto LAB_005ed344;
      uVar18 = pbVar19[0xc] + 1;
      pbVar19[0xc] = (byte)uVar18;
    }
    else {
      uVar18 = (uint)pbVar19[0xe] + ((uint)param_4 >> 0xc & 0xff) + uVar25;
      uVar25 = uVar18 >> 8;
      pbVar19[0xe] = (byte)uVar18;
      if ((uint)param_4 >> 0x14 == 0) goto LAB_005ed2bc;
      uVar18 = (uint)pbVar19[0xd] + ((uint)param_4 >> 0x14 & 0xff) + uVar25;
      uVar25 = uVar18 >> 8;
      pbVar19[0xd] = (byte)uVar18;
      if ((uint)param_4 >> 0x1c == 0) goto LAB_005ed2d4;
      uVar18 = (uint)pbVar19[0xc] + ((uint)param_4 >> 0x1c) + uVar25;
      pbVar19[0xc] = (byte)uVar18;
    }
    if ((((uVar18 >> 8 != 0) &&
         (bVar16 = pbVar19[0xb], pbVar19[0xb] = (byte)(bVar16 + 1), bVar16 + 1 >> 8 != 0)) &&
        (bVar16 = pbVar19[10], pbVar19[10] = (byte)(bVar16 + 1), bVar16 + 1 >> 8 != 0)) &&
       (bVar16 = pbVar19[9], pbVar19[9] = (byte)(bVar16 + 1), bVar16 + 1 >> 8 != 0)) {
      pbVar19[8] = pbVar19[8] + 1;
    }
LAB_005ed344:
    (*pcVar27)(pbVar19,&uStack_128,puVar14);
    if (((puVar15 < &DAT_00000005 ||
         (puVar26 < puVar24 + 1 && puVar24 < pbVar19 + 0x14 ||
         puVar26 < puVar13 + 1 && puVar13 < pbVar19 + 0x14)) ||
         puVar13 < puVar24 + 1 && puVar24 < puVar13 + 1) ||
       ((((uint)puVar24 | (uint)puVar13) & 3) != 0)) {
      bVar16 = *(byte *)puVar13;
      *(byte *)puVar24 = bVar16 ^ uStack_128._0_1_;
      pbVar19[0x10] = bVar16 ^ uStack_128._0_1_ ^ pbVar19[0x10];
      if (puVar15 != (uint *)0x1) {
        uStack_128._1_1_ = uStack_128._1_1_ ^ *(byte *)((int)puVar13 + 1);
        *(byte *)((int)puVar24 + 1) = uStack_128._1_1_;
        pbVar19[0x11] = uStack_128._1_1_ ^ pbVar19[0x11];
        if (puVar15 != (uint *)&SUB_00000002) {
          uStack_128._2_1_ = uStack_128._2_1_ ^ *(byte *)((int)puVar13 + 2);
          *(byte *)((int)puVar24 + 2) = uStack_128._2_1_;
          pbVar19[0x12] = uStack_128._2_1_ ^ pbVar19[0x12];
          if (puVar15 != (uint *)0x3) {
            uStack_128._3_1_ = (byte)uStack_128 ^ *(byte *)((int)puVar13 + 3);
            *(byte *)((int)puVar24 + 3) = (byte)uStack_128;
            pbVar19[0x13] = (byte)uStack_128 ^ pbVar19[0x13];
            if (puVar15 >= &DAT_00000005) {
              bVar16 = *(byte *)(puVar13 + 1);
              *(byte *)(puVar24 + 1) = uStack_124._0_1_ ^ bVar16;
              pbVar19[0x14] = uStack_124._0_1_ ^ bVar16 ^ pbVar19[0x14];
              if (&DAT_00000005 < puVar15) {
                uStack_124._1_1_ = uStack_124._1_1_ ^ *(byte *)((int)puVar13 + 5);
                *(byte *)((int)puVar24 + 5) = uStack_124._1_1_;
                pbVar19[0x15] = uStack_124._1_1_ ^ pbVar19[0x15];
                if (puVar15 != (uint *)&DAT_00000006) {
                  uStack_124._2_1_ = uStack_124._2_1_ ^ *(byte *)((int)puVar13 + 6);
                  *(byte *)((int)puVar24 + 6) = uStack_124._2_1_;
                  pbVar19[0x16] = uStack_124._2_1_ ^ pbVar19[0x16];
                  if (puVar15 != (uint *)&DAT_00000007) {
                    uStack_124._3_1_ = (byte)uStack_124 ^ *(byte *)((int)puVar13 + 7);
                    *(byte *)((int)puVar24 + 7) = (byte)uStack_124;
                    pbVar19[0x17] = (byte)uStack_124 ^ pbVar19[0x17];
                    if (puVar15 != (uint *)&DAT_00000008) {
                      bVar16 = *(byte *)(puVar13 + 2);
                      *(byte *)(puVar24 + 2) = uStack_120._0_1_ ^ bVar16;
                      pbVar19[0x18] = uStack_120._0_1_ ^ bVar16 ^ pbVar19[0x18];
                      if (puVar15 != (uint *)&DAT_00000009) {
                        uStack_120._1_1_ = uStack_120._1_1_ ^ *(byte *)((int)puVar13 + 9);
                        *(byte *)((int)puVar24 + 9) = uStack_120._1_1_;
                        pbVar19[0x19] = uStack_120._1_1_ ^ pbVar19[0x19];
                        if (puVar15 != (uint *)&DAT_0000000a) {
                          uStack_120._2_1_ = uStack_120._2_1_ ^ *(byte *)((int)puVar13 + 10);
                          *(byte *)((int)puVar24 + 10) = uStack_120._2_1_;
                          pbVar19[0x1a] = uStack_120._2_1_ ^ pbVar19[0x1a];
                          if (puVar15 != (uint *)&DAT_0000000b) {
                            uStack_120._3_1_ = (byte)uStack_120 ^ *(byte *)((int)puVar13 + 0xb);
                            *(byte *)((int)puVar24 + 0xb) = (byte)uStack_120;
                            pbVar19[0x1b] = (byte)uStack_120 ^ pbVar19[0x1b];
                            if (puVar15 != (uint *)&SUB_0000000c) {
                              bVar16 = *(byte *)(puVar13 + 3);
                              *(byte *)(puVar24 + 3) = uStack_11c._0_1_ ^ bVar16;
                              pbVar19[0x1c] = uStack_11c._0_1_ ^ bVar16 ^ pbVar19[0x1c];
                              if (puVar15 != (uint *)&DAT_0000000d) {
                                uStack_11c._1_1_ = uStack_11c._1_1_ ^ *(byte *)((int)puVar13 + 0xd);
                                *(byte *)((int)puVar24 + 0xd) = uStack_11c._1_1_;
                                pbVar19[0x1d] = uStack_11c._1_1_ ^ pbVar19[0x1d];
                                if (puVar15 != (uint *)&DAT_0000000e) {
                                  uStack_11c._2_1_ =
                                       uStack_11c._2_1_ ^ *(byte *)((int)puVar13 + 0xe);
                                  *(byte *)((int)puVar24 + 0xe) = uStack_11c._2_1_;
                                  pbVar19[0x1e] = uStack_11c._2_1_ ^ pbVar19[0x1e];
                                  if (puVar15 != (uint *)&DAT_0000000f) {
                                    uStack_11c._3_1_ =
                                         *(byte *)((int)puVar13 + 0xf) ^ (byte)uStack_11c;
                                    *(byte *)((int)puVar24 + 0xf) = (byte)uStack_11c;
                                    pbVar19[0x1f] = (byte)uStack_11c ^ pbVar19[0x1f];
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
      puVar23 = (uint *)0x1;
      if (puVar15 != (uint *)0x0) {
        puVar23 = puVar15;
      }
      iVar20 = ((uint)(puVar23 + -1) >> 2) + 1;
      puVar17 = (uint *)(iVar20 * 4);
      if (puVar15 < &SUB_00000004) {
        puVar17 = (uint *)0x0;
      }
      else {
        uVar18 = *puVar13;
        *puVar24 = uStack_128 ^ uVar18;
        *(uint *)(pbVar19 + 0x10) = uStack_128 ^ uVar18 ^ *(uint *)(pbVar19 + 0x10);
        if (iVar20 != 1) {
          uVar18 = puVar13[1];
          puVar24[1] = uVar18 ^ uStack_124;
          *(uint *)(pbVar19 + 0x14) = uVar18 ^ uStack_124 ^ *(uint *)(pbVar19 + 0x14);
          if (iVar20 != 2) {
            uVar18 = puVar13[2];
            puVar24[2] = uVar18 ^ uStack_120;
            *(uint *)(pbVar19 + 0x18) = uVar18 ^ uStack_120 ^ *(uint *)(pbVar19 + 0x18);
            if (iVar20 != 3) {
              uVar18 = puVar13[3];
              puVar24[3] = uVar18 ^ (uint)uStack_11c;
              *(uint *)(pbVar19 + 0x1c) = uVar18 ^ (uint)uStack_11c ^ *(uint *)(pbVar19 + 0x1c);
            }
          }
        }
        if (puVar17 == puVar23) goto LAB_005ed544;
      }
      puVar23 = (uint *)((int)puVar17 + 1);
      bVar16 = *(byte *)((int)puVar13 + (int)puVar17) ^ *(byte *)((int)&uStack_128 + (int)puVar17);
      *(byte *)((int)puVar24 + (int)puVar17) = bVar16;
      (pbVar19 + (int)puVar17)[0x10] = bVar16 ^ (pbVar19 + (int)puVar17)[0x10];
      if (puVar23 < puVar15) {
        puVar17 = (uint *)((int)puVar17 + 2);
        bVar16 = *(byte *)((int)puVar13 + (int)puVar23) ^ *(byte *)((int)&uStack_128 + (int)puVar23)
        ;
        *(byte *)((int)puVar24 + (int)puVar23) = bVar16;
        (pbVar19 + (int)puVar23)[0x10] = bVar16 ^ (pbVar19 + (int)puVar23)[0x10];
        if (puVar17 < puVar15) {
          bVar16 = *(byte *)((int)puVar13 + (int)puVar17) ^
                   *(byte *)((int)&uStack_128 + (int)puVar17);
          *(byte *)((int)puVar24 + (int)puVar17) = bVar16;
          (pbVar19 + (int)puVar17)[0x10] = bVar16 ^ (pbVar19 + (int)puVar17)[0x10];
        }
      }
    }
LAB_005ed544:
    (*pcVar27)(puVar26,puVar26,puVar14);
  }
LAB_005ed164:
  (*(code *)PTR_memset_006a99f4)(pbVar19 + (0xf - uVar11),0,0x10 - iVar12);
  (*pcVar27)(pbVar19,&uStack_128,puVar14);
  puVar13 = (uint *)0x0;
  pbVar22 = (byte *)(*(uint *)(pbVar19 + 0x14) ^ uStack_124);
  *(uint *)(pbVar19 + 0x10) = *(uint *)(pbVar19 + 0x10) ^ uStack_128;
  *pbVar19 = bVar21;
  *(byte **)(pbVar19 + 0x14) = pbVar22;
  *(uint *)(pbVar19 + 0x18) = *(uint *)(pbVar19 + 0x18) ^ uStack_120;
  *(uint *)(pbVar19 + 0x1c) = *(uint *)(pbVar19 + 0x1c) ^ (uint)uStack_11c;
  puVar26 = uStack_11c;
LAB_005ed1e0:
  if (pbStack_114 == *(byte **)puVar9) {
    return puVar13;
  }
  pbVar19 = pbStack_114;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar13 = (uint *)((((uint)*pbVar19 << 0x1a) >> 0x1d) * 2 + 2);
  if (puVar13 <= puVar26) {
    (*(code *)PTR_memcpy_006a9aec)(pbVar22,pbVar19 + 0x10,puVar13);
    return puVar13;
  }
  return (uint *)0x0;
}

