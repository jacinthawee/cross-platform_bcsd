
/* WARNING: Removing unreachable block (ram,0x005e451c) */
/* WARNING: Removing unreachable block (ram,0x005e3e50) */
/* WARNING: Removing unreachable block (ram,0x005e3b90) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */

void DES_ede3_cfb_encrypt
               (uchar *in,uchar *out,int numbits,long length,DES_key_schedule *ks1,
               DES_key_schedule *ks2,DES_key_schedule *ks3,DES_cblock *ivec,int enc)

{
  uchar *puVar1;
  DES_cblock *pauVar2;
  byte *pbVar3;
  bool bVar4;
  DES_key_schedule *pDVar5;
  uint uVar6;
  int iVar7;
  DES_key_schedule *pDVar8;
  DES_key_schedule *pDVar9;
  byte *pbVar10;
  uint *puVar11;
  DES_key_schedule *pDVar12;
  DES_key_schedule *pDVar13;
  DES_key_schedule *pDVar14;
  DES_key_schedule *pDVar15;
  byte bVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  undefined *puVar22;
  uint uVar23;
  DES_key_schedule *pDVar24;
  uint uVar25;
  uchar *unaff_s0;
  uchar *puVar26;
  uint *unaff_s1;
  uint unaff_s2;
  DES_key_schedule *unaff_s3;
  DES_key_schedule *pDVar27;
  DES_key_schedule *unaff_s4;
  uint *puVar28;
  DES_key_schedule *unaff_s6;
  DES_key_schedule *unaff_s7;
  byte *pbVar29;
  uchar *unaff_s8;
  uint uStack_1cc;
  uint uStack_1c8;
  byte abStack_1c4 [4];
  byte bStack_1c0;
  byte bStack_1bf;
  byte bStack_1be;
  byte bStack_1bd;
  int iStack_1bc;
  uint uStack_1b8;
  uint *puStack_1b4;
  DES_key_schedule *pDStack_1b0;
  undefined4 uStack_1ac;
  byte *pbStack_1a8;
  DES_key_schedule *pDStack_1a4;
  DES_key_schedule *pDStack_1a0;
  uchar *puStack_19c;
  uint *puStack_198;
  undefined4 uStack_194;
  byte *pbStack_180;
  uint *puStack_17c;
  DES_key_schedule *pDStack_174;
  uint *puStack_170;
  int *piStack_16c;
  uint uStack_164;
  uint uStack_160;
  byte abStack_15c [4];
  byte bStack_158;
  byte bStack_157;
  byte bStack_156;
  byte bStack_155;
  int iStack_154;
  uchar *puStack_150;
  uint *puStack_14c;
  uint uStack_148;
  DES_key_schedule *pDStack_144;
  DES_key_schedule *pDStack_140;
  DES_key_schedule *pDStack_13c;
  DES_key_schedule *pDStack_138;
  DES_key_schedule *pDStack_134;
  uchar *puStack_130;
  code *pcStack_12c;
  DES_key_schedule *pDStack_118;
  undefined4 uStack_114;
  byte *pbStack_110;
  uint *puStack_10c;
  DES_key_schedule *pDStack_108;
  DES_key_schedule *pDStack_104;
  DES_key_schedule *pDStack_100;
  DES_key_schedule *pDStack_fc;
  DES_key_schedule *pDStack_f8;
  code **ppcStack_f4;
  int *piStack_f0;
  uint *puStack_ec;
  DES_key_schedule *pDStack_e8;
  DES_key_schedule *pDStack_e4;
  DES_key_schedule *pDStack_dc;
  DES_key_schedule *pDStack_d8;
  undefined uStack_d4;
  undefined uStack_d3;
  byte abStack_d2 [2];
  undefined4 uStack_d0;
  byte abStack_cc [8];
  int iStack_c4;
  uchar *puStack_c0;
  uint *puStack_bc;
  uint uStack_b8;
  DES_key_schedule *pDStack_b4;
  DES_key_schedule *pDStack_b0;
  DES_key_schedule *pDStack_ac;
  DES_key_schedule *pDStack_a8;
  DES_key_schedule *pDStack_a4;
  uchar *puStack_a0;
  undefined4 uStack_9c;
  uint *local_88;
  uint *puStack_84;
  int iStack_80;
  DES_key_schedule *local_7c;
  DES_key_schedule *local_78;
  DES_key_schedule *local_74;
  DES_key_schedule **local_70;
  DES_key_schedule **local_6c;
  undefined *local_68;
  int *local_64;
  int local_60;
  uint local_5c;
  undefined4 *local_58;
  DES_key_schedule *local_54;
  DES_key_schedule *local_50;
  undefined4 local_4c;
  DES_key_schedule *local_44;
  DES_key_schedule *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  byte local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  undefined local_30;
  undefined local_2f;
  undefined local_2e;
  undefined local_2d;
  int local_2c;
  
  local_78 = ks2;
  local_64 = (int *)PTR___stack_chk_guard_006a9ae8;
  local_74 = ks3;
  local_88 = (uint *)&_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_7c = ks1;
  local_54 = (DES_key_schedule *)ivec;
  pDStack_ac = (DES_key_schedule *)numbits;
  if (numbits < 0x41) {
    uVar18 = numbits + 7;
    pDVar27 = (DES_key_schedule *)(uVar18 >> 3);
    pDVar14 = (DES_key_schedule *)
              ((uint)(*ivec)[7] << 0x18 |
              (uint)(*ivec)[5] << 8 | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[4]);
    pDVar8 = (DES_key_schedule *)
             ((uint)(*ivec)[1] << 8 | (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[0] |
             (uint)(*ivec)[3] << 0x18);
    unaff_s1 = (uint *)out;
    unaff_s3 = pDVar27;
    if (enc == 0) {
      if (pDVar27 <= (uint)length) {
        if (-1 < numbits) {
          uVar18 = numbits;
        }
        local_58 = &local_3c;
        local_5c = numbits & 7;
        local_60 = (int)local_58 + ((int)uVar18 >> 3);
        unaff_s6 = (DES_key_schedule *)(numbits & 0x80000007);
        if ((int)unaff_s6 < 0) {
          unaff_s6 = (DES_key_schedule *)(((uint)((int)unaff_s6[-1].ks + 0x7f) | 0xfffffff8) + 1);
        }
        unaff_s2 = 8 - (int)unaff_s6;
        local_70 = &local_44;
        pDStack_ac = (DES_key_schedule *)(length - (int)pDVar27);
        local_6c = (DES_key_schedule **)(&PTR_LAB_00674c14 + (int)pDVar27);
        local_68 = &UNK_00674c5c + (int)pDVar27 * 4;
        unaff_s8 = (uchar *)(uint)(pDVar27 < (DES_key_schedule *)&DAT_00000009);
        unaff_s0 = in;
        pDVar15 = pDVar14;
        pDVar24 = pDVar8;
        do {
          unaff_s0 = unaff_s0 + (int)pDVar27 * 2;
          local_44 = pDVar24;
          local_40 = pDVar15;
          (*(code *)local_88[-0x15dc])(local_70,local_7c,local_78,local_74);
          if (unaff_s8 != (uchar *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e3b00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*(code *)*local_6c)();
            return;
          }
          pDVar14 = (DES_key_schedule *)0x0;
          pDVar12 = (DES_key_schedule *)0x0;
          if (numbits == 0x20) {
            pDVar14 = (DES_key_schedule *)0x0;
            pDVar8 = pDVar15;
          }
          else {
            pDVar8 = pDVar12;
            if (numbits != 0x40) {
              local_34 = 0;
              local_32 = 0;
              local_3c = CONCAT22(CONCAT11((char)pDVar24,(char)((uint)pDVar24 >> 8)),
                                  CONCAT11((char)((uint)pDVar24 >> 0x10),
                                           (char)((uint)pDVar24 >> 0x18)));
              local_33 = 0;
              local_2d = 0;
              local_38 = CONCAT31(CONCAT21(CONCAT11((char)pDVar15,(char)((uint)pDVar15 >> 8)),
                                           (char)((uint)pDVar15 >> 0x10)),
                                  (char)((uint)pDVar15 >> 0x18));
              local_31 = 0;
              local_30 = 0;
              local_2f = 0;
              local_2e = 0;
              if (local_5c == 0) {
                local_4c = 0;
                local_50 = (DES_key_schedule *)0x0;
                (*(code *)local_88[-0x14bb])(local_58,local_60,8);
              }
              else {
                local_4c = 0;
                local_50 = (DES_key_schedule *)0x0;
                (*(code *)local_88[-0x14bb])(local_58,local_60,9);
                local_3c = CONCAT31(CONCAT21(CONCAT11(local_3c._0_1_ << ((uint)unaff_s6 & 0x1f) |
                                                      (byte)((int)(uint)local_3c._1_1_ >>
                                                            (unaff_s2 & 0x1f)),
                                                      local_3c._1_1_ << ((uint)unaff_s6 & 0x1f) |
                                                      (byte)((int)(uint)local_3c._2_1_ >>
                                                            (unaff_s2 & 0x1f))),
                                             local_3c._2_1_ << ((uint)unaff_s6 & 0x1f) |
                                             (byte)((int)(local_3c & 0xff) >> (unaff_s2 & 0x1f))),
                                    (char)local_3c << ((uint)unaff_s6 & 0x1f) |
                                    (byte)((int)(uint)local_38._0_1_ >> (unaff_s2 & 0x1f)));
                local_38 = CONCAT31(CONCAT21(CONCAT11(local_38._0_1_ << ((uint)unaff_s6 & 0x1f) |
                                                      (byte)((int)(uint)local_38._1_1_ >>
                                                            (unaff_s2 & 0x1f)),
                                                      local_38._1_1_ << ((uint)unaff_s6 & 0x1f) |
                                                      (byte)((int)(uint)local_38._2_1_ >>
                                                            (unaff_s2 & 0x1f))),
                                             local_38._2_1_ << ((uint)unaff_s6 & 0x1f) |
                                             (byte)((int)(local_38 & 0xff) >> (unaff_s2 & 0x1f))),
                                    (byte)((int)(uint)local_34 >> (unaff_s2 & 0x1f)) |
                                    (char)local_38 << ((uint)unaff_s6 & 0x1f));
              }
              pDVar14 = (DES_key_schedule *)
                        ((((local_38 >> 0x10) << 0x18 | (local_38 >> 0x18) << 0x10) >> 0x10) +
                        ((local_38 & 0xff) << 8 | local_38 >> 8 & 0xff) * 0x10000);
              pDVar12 = local_50;
              pDVar8 = (DES_key_schedule *)
                       ((((local_3c >> 0x10) << 0x18 | (local_3c >> 0x18) << 0x10) >> 0x10) +
                       ((local_3c & 0xff) << 8 | local_3c >> 8 & 0xff) * 0x10000);
            }
          }
          out = (uchar *)((int)out + (int)pDVar27 * 2);
          length = (uint)pDVar12 ^ (uint)local_44;
          bVar4 = pDVar27 <= pDStack_ac;
          pDStack_ac = (DES_key_schedule *)((int)pDStack_ac - (int)pDVar27);
          unaff_s1 = (uint *)out;
          unaff_s3 = pDVar14;
          pDVar15 = pDVar14;
          unaff_s4 = pDVar27;
          unaff_s7 = pDVar8;
          pDVar24 = pDVar8;
        } while (bVar4);
      }
    }
    else if (pDVar27 <= (uint)length) {
      if (-1 < numbits) {
        uVar18 = numbits;
      }
      local_58 = &local_3c;
      local_5c = numbits & 7;
      local_60 = (int)local_58 + ((int)uVar18 >> 3);
      unaff_s0 = (uchar *)(numbits & 0x80000007);
      if ((int)unaff_s0 < 0) {
        unaff_s0 = (uchar *)(((uint)(unaff_s0 + -1) | 0xfffffff8) + 1);
      }
      unaff_s6 = (DES_key_schedule *)(&UNK_00674bf0 + (int)pDVar27 * 4);
      local_68 = &UNK_00674c38 + (int)pDVar27 * 4;
      local_6c = &local_44;
      unaff_s3 = (DES_key_schedule *)(length - (int)pDVar27);
      local_70 = (DES_key_schedule **)(uint)(pDVar27 < (DES_key_schedule *)&DAT_00000009);
      unaff_s2 = 8 - (int)unaff_s0;
      pDVar15 = pDVar14;
      pDVar24 = pDVar8;
      unaff_s8 = in;
      do {
        unaff_s8 = unaff_s8 + (int)pDVar27 * 2;
        length = (long)local_74;
        local_44 = pDVar24;
        local_40 = pDVar15;
        (*(code *)local_88[-0x15dc])(local_6c,local_7c,local_78);
        if (local_70 != (DES_key_schedule **)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e382c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)unaff_s6->ks[0].deslong[0])();
          return;
        }
        unaff_s1 = (uint *)((int)unaff_s1 + (int)pDVar27 * 2);
        pDVar14 = local_44;
        pDVar8 = pDVar15;
        if ((numbits != 0x20) && (pDVar14 = local_40, pDVar8 = local_44, numbits != 0x40)) {
          local_34 = (byte)local_44;
          local_3c = CONCAT31(CONCAT21(CONCAT11((char)pDVar24,(char)((uint)pDVar24 >> 8)),
                                       (char)((uint)pDVar24 >> 0x10)),(char)((uint)pDVar24 >> 0x18))
          ;
          length = (uint)pDVar15 >> 8;
          local_33 = (undefined)((uint)local_44 >> 8);
          local_32 = (undefined)((uint)local_44 >> 0x10);
          local_31 = (undefined)((uint)local_44 >> 0x18);
          local_38._0_1_ = (byte)pDVar15;
          local_38 = (uint)CONCAT12(local_38._0_1_,
                                    CONCAT11((char)((uint)pDVar15 >> 8),
                                             (char)((uint)pDVar15 >> 0x10))) << 8;
          local_38 = local_38 | (uint)pDVar15 >> 0x18;
          local_30 = SUB41(local_40,0);
          local_2f = (undefined)((uint)local_40 >> 8);
          local_2e = (undefined)((uint)local_40 >> 0x10);
          local_2d = (undefined)((uint)local_40 >> 0x18);
          if (local_5c == 0) {
            (*(code *)local_88[-0x14bb])(local_58,local_60,8);
          }
          else {
            (*(code *)local_88[-0x14bb])(local_58,local_60,9);
            length = (local_3c >> 0x18) << ((uint)unaff_s0 & 0x1f) |
                     (int)(uint)local_3c._1_1_ >> (unaff_s2 & 0x1f);
            local_3c._0_1_ = (char)length;
            local_3c = CONCAT31(CONCAT12(local_3c._0_1_,
                                         CONCAT11(local_3c._1_1_ << ((uint)unaff_s0 & 0x1f) |
                                                  (byte)((int)(uint)local_3c._2_1_ >>
                                                        (unaff_s2 & 0x1f)),
                                                  local_3c._2_1_ << ((uint)unaff_s0 & 0x1f) |
                                                  (byte)((int)(local_3c & 0xff) >> (unaff_s2 & 0x1f)
                                                        ))),
                                (char)local_3c << ((uint)unaff_s0 & 0x1f) |
                                (byte)((int)(uint)local_38._0_1_ >> (unaff_s2 & 0x1f)));
            local_38 = CONCAT31(CONCAT21(CONCAT11(local_38._0_1_ << ((uint)unaff_s0 & 0x1f) |
                                                  (byte)((int)(uint)local_38._1_1_ >>
                                                        (unaff_s2 & 0x1f)),
                                                  local_38._1_1_ << ((uint)unaff_s0 & 0x1f) |
                                                  (byte)((int)(uint)local_38._2_1_ >>
                                                        (unaff_s2 & 0x1f))),
                                         local_38._2_1_ << ((uint)unaff_s0 & 0x1f) |
                                         (byte)((int)(local_38 & 0xff) >> (unaff_s2 & 0x1f))),
                                (byte)((int)(uint)local_34 >> (unaff_s2 & 0x1f)) |
                                (char)local_38 << ((uint)unaff_s0 & 0x1f));
          }
          pDVar14 = (DES_key_schedule *)
                    ((((local_38 >> 0x10) << 0x18 | (local_38 >> 0x18) << 0x10) >> 0x10) +
                    ((local_38 & 0xff) << 8 | local_38 >> 8 & 0xff) * 0x10000);
          pDVar8 = (DES_key_schedule *)
                   ((((local_3c >> 0x10) << 0x18 | (local_3c >> 0x18) << 0x10) >> 0x10) +
                   ((local_3c & 0xff) << 8 | local_3c >> 8 & 0xff) * 0x10000);
        }
        bVar4 = pDVar27 <= unaff_s3;
        unaff_s3 = (DES_key_schedule *)((int)unaff_s3 - (int)pDVar27);
        pDVar15 = pDVar14;
        unaff_s4 = pDVar14;
        pDStack_ac = pDVar27;
        pDVar24 = pDVar8;
        unaff_s7 = pDVar8;
      } while (bVar4);
    }
    out = (uchar *)((uint)pDVar8 >> 0x10);
    ivec = (DES_cblock *)((uint)pDVar14 >> 8);
    local_54->ks[0].cblock[0] = (uchar)pDVar8;
    local_54->ks[0].cblock[4] = (char)pDVar14;
    local_54->ks[0].cblock[1] = (uchar)((uint)pDVar8 >> 8);
    local_54->ks[0].cblock[2] = (uchar)((uint)pDVar8 >> 0x10);
    local_54->ks[0].cblock[3] = (uchar)((uint)pDVar8 >> 0x18);
    local_54->ks[0].cblock[5] = (uchar)((uint)pDVar14 >> 8);
    local_54->ks[0].cblock[6] = (uchar)((uint)pDVar14 >> 0x10);
    local_54->ks[0].cblock[7] = (uchar)((uint)pDVar14 >> 0x18);
    ks1 = local_54;
  }
  if (local_2c == *local_64) {
    return;
  }
  uStack_9c = 0x5e3ffc;
  (*(code *)local_88[-0x14cc])();
  puStack_10c = local_88;
  piStack_f0 = (int *)PTR___stack_chk_guard_006a9ae8;
  puStack_ec = puStack_84;
  pDStack_118 = (DES_key_schedule *)&_gp;
  iStack_c4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_198 = (uint *)out;
  pDVar14 = ks1;
  pDStack_174 = (DES_key_schedule *)length;
  puStack_150 = unaff_s0;
  pDStack_140 = unaff_s4;
  pDStack_1a4 = pDStack_ac;
  pDStack_1a0 = unaff_s6;
  pDStack_134 = unaff_s7;
  puStack_130 = unaff_s8;
  puStack_c0 = unaff_s0;
  puStack_bc = unaff_s1;
  uStack_b8 = unaff_s2;
  pDStack_b4 = unaff_s3;
  pDStack_b0 = unaff_s4;
  pDStack_a8 = unaff_s6;
  pDStack_a4 = unaff_s7;
  puStack_a0 = unaff_s8;
  if ((undefined *)((int)ks1[-1].ks + 0x7f) < &DAT_00000040) {
    pDStack_140 = (DES_key_schedule *)((int)ks1 >> 3);
    pDVar14 = (DES_key_schedule *)((uint)*(byte *)((int)puStack_84 + 7) << 0x18);
    pDVar27 = (DES_key_schedule *)
              ((uint)pDVar14 |
              (uint)*(byte *)((int)puStack_84 + 5) << 8 |
              (uint)*(byte *)((int)puStack_84 + 6) << 0x10 | (uint)*(byte *)(puStack_84 + 1));
    pDStack_1a4 = (DES_key_schedule *)((int)((int)ks1->ks + 7) >> 3);
    pDVar8 = (DES_key_schedule *)
             ((uint)*(byte *)((int)puStack_84 + 1) << 8 |
              (uint)*(byte *)((int)puStack_84 + 2) << 0x10 | (uint)*(byte *)puStack_84 |
             (uint)*(byte *)((int)puStack_84 + 3) << 0x18);
    if (iStack_80 == 0) {
      puStack_150 = (uchar *)ivec;
      if (pDStack_1a4 <= (uint)length) {
        ppcStack_f4 = (code **)(&PTR_LAB_00674ca4 + (int)pDStack_1a4);
        pDStack_174 = (DES_key_schedule *)(length - (int)pDStack_1a4);
        pDVar24 = (DES_key_schedule *)&pDStack_dc;
        pDVar15 = (DES_key_schedule *)((int)pDStack_1a4[-1].ks + 0x7f);
        pDStack_134 = (DES_key_schedule *)&uStack_d4;
        pDStack_1a0 = (DES_key_schedule *)(&PTR_LAB_00674cc8 + (int)pDStack_1a4);
        puStack_130 = (uchar *)(uint)(pDStack_1a4 < (DES_key_schedule *)&DAT_00000009);
        pDStack_104 = (DES_key_schedule *)((uint)ks1 & 7);
        pDVar12 = pDVar8;
        do {
          pDVar8 = pDVar27;
          pDVar14 = (DES_key_schedule *)0x1;
          pDStack_108 = pDVar24;
          pDStack_100 = pDStack_174;
          pDStack_fc = ks1;
          pDStack_f8 = pDVar15;
          pDStack_dc = pDVar12;
          pDStack_d8 = pDVar8;
          (*(code *)pDStack_118[-0xd3].ks[0xd].deslong[0])(pDVar24,puStack_10c);
          if (puStack_130 != (uchar *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e42ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (**ppcStack_f4)();
            return;
          }
          bVar16 = (*(DES_cblock *)((uchar *)((int)ivec + (int)pDStack_1a4) + -1))[0];
          pDVar27 = (DES_key_schedule *)(uint)bVar16;
          ivec = (DES_cblock *)((uchar *)((int)ivec + (int)pDStack_1a4) + (int)pDStack_f8);
          pDVar13 = pDStack_100;
          pDVar15 = pDStack_f8;
          ks1 = pDStack_fc;
          pDVar24 = pDStack_108;
          if (pDStack_fc != (DES_key_schedule *)&DAT_00000020) {
            if (pDStack_fc == (DES_key_schedule *)&DAT_00000040) {
              pDVar8 = pDVar27;
              pDVar27 = (DES_key_schedule *)0x0;
            }
            else {
              abStack_cc[0] = bVar16;
              abStack_cc[1] = 0;
              abStack_cc[2] = 0;
              _uStack_d4 = CONCAT31(CONCAT21(CONCAT11((char)pDVar12,(char)((uint)pDVar12 >> 8)),
                                             (char)((uint)pDVar12 >> 0x10)),
                                    (char)((uint)pDVar12 >> 0x18));
              uStack_d0 = CONCAT31(CONCAT21(CONCAT11((char)pDVar8,(char)((uint)pDVar8 >> 8)),
                                            (char)((uint)pDVar8 >> 0x10)),
                                   (char)((uint)pDVar8 >> 0x18));
              abStack_cc[3] = 0;
              abStack_cc[4] = 0;
              abStack_cc[5] = 0;
              abStack_cc[6] = 0;
              abStack_cc[7] = 0;
              if (pDStack_104 == (DES_key_schedule *)0x0) {
                pDVar14 = (DES_key_schedule *)&DAT_00000008;
                pDStack_e4 = pDStack_108;
                pDStack_e8 = pDStack_f8;
                pDStack_f8 = pDStack_fc;
                pDStack_fc = pDStack_100;
                pDStack_108 = (DES_key_schedule *)0x0;
                pDStack_100 = pDVar27;
                (*(code *)*(DES_key_schedule **)((int)pDStack_118[-0xa6].ks + 0x14))
                          (pDStack_134,(undefined *)((int)pDStack_140->ks + (int)pDStack_134->ks));
                bVar16 = (byte)pDStack_100;
                pDVar13 = pDStack_fc;
                pDVar15 = pDStack_e8;
                ks1 = pDStack_f8;
                pDVar24 = pDStack_e4;
              }
              else {
                pDVar14 = (DES_key_schedule *)((int)&puStack_c0 + (int)pDStack_140);
                uVar18 = 8 - (int)pDStack_104;
                _uStack_d3 = (uint3)(byte)(*(char *)((int)&uStack_d4 +
                                                    (int)(pDStack_140->ks[0].cblock + 1)) <<
                                           ((uint)pDStack_104 & 0x1f) |
                                          (byte)((int)(uint)*(byte *)((int)&uStack_d4 +
                                                                     (int)(pDStack_140->ks[0].cblock
                                                                          + 2)) >> (uVar18 & 0x1f)))
                             << 0x10;
                _uStack_d4 = (uint3)(((uint)(byte)(*(char *)((int)&uStack_d4 + (int)pDStack_140) <<
                                                   ((uint)pDStack_104 & 0x1f) |
                                                  (byte)((int)(uint)*(byte *)((int)&uStack_d4 +
                                                                             (int)(pDStack_140->ks
                                                                                   [0].cblock + 1))
                                                        >> (uVar18 & 0x1f))) << 0x18) >> 8) |
                             _uStack_d3 >> 8 |
                             (uint3)(byte)(*(char *)((int)&uStack_d4 +
                                                    (int)(pDStack_140->ks[0].cblock + 2)) <<
                                           ((uint)pDStack_104 & 0x1f) |
                                          (byte)((int)(uint)*(byte *)((int)&uStack_d4 +
                                                                     (int)(pDStack_140->ks[0].cblock
                                                                          + 3)) >> (uVar18 & 0x1f)))
                ;
                _uStack_d4 = CONCAT31(_uStack_d4,
                                      *(char *)((int)&uStack_d4 +
                                               (int)(pDStack_140->ks[0].cblock + 3)) <<
                                      ((uint)pDStack_104 & 0x1f) |
                                      (byte)((int)(uint)*(byte *)((int)&uStack_d4 +
                                                                 (int)(pDStack_140->ks[0].cblock + 4
                                                                      )) >> (uVar18 & 0x1f)));
                uStack_d0._1_3_ =
                     (uint3)(byte)(*(char *)((int)&uStack_d4 + (int)(pDStack_140->ks[0].cblock + 5))
                                   << ((uint)pDStack_104 & 0x1f) |
                                  (byte)((int)(uint)*(byte *)((int)&uStack_d4 +
                                                             (int)(pDStack_140->ks[0].cblock + 6))
                                        >> (uVar18 & 0x1f))) << 0x10;
                uStack_d0._0_3_ =
                     (uint3)(((uint)(byte)(*(char *)((int)&uStack_d4 +
                                                    (int)(pDStack_140->ks[0].cblock + 4)) <<
                                           ((uint)pDStack_104 & 0x1f) |
                                          (byte)((int)(uint)*(byte *)((int)&uStack_d4 +
                                                                     (int)(pDStack_140->ks[0].cblock
                                                                          + 5)) >> (uVar18 & 0x1f)))
                             << 0x18) >> 8) | uStack_d0._1_3_ >> 8 |
                     (uint3)(byte)(*(char *)((int)&uStack_d4 + (int)(pDStack_140->ks[0].cblock + 6))
                                   << ((uint)pDStack_104 & 0x1f) |
                                  (byte)((int)(uint)*(byte *)((int)&uStack_d4 +
                                                             (int)(pDStack_140->ks[0].cblock + 7))
                                        >> (uVar18 & 0x1f)));
                uStack_d0 = CONCAT31(uStack_d0._0_3_,
                                     (byte)((int)(uint)abStack_cc[(int)pDStack_140] >>
                                           (uVar18 & 0x1f)) |
                                     *(char *)((int)&uStack_d4 +
                                              (int)(pDStack_140->ks[0].cblock + 7)) <<
                                     ((uint)pDStack_104 & 0x1f));
              }
              pDVar8 = (DES_key_schedule *)
                       ((((_uStack_d4 >> 0x10) << 0x18 | (_uStack_d4 >> 0x18) << 0x10) >> 0x10) +
                       ((_uStack_d4 & 0xff) << 8 | _uStack_d4 >> 8 & 0xff) * 0x10000);
              pDVar27 = (DES_key_schedule *)
                        ((((uStack_d0 >> 0x10) << 0x18 | (uStack_d0 >> 0x18) << 0x10) >> 0x10) +
                        ((uStack_d0 & 0xff) << 8 | uStack_d0 >> 8 & 0xff) * 0x10000);
            }
          }
          ((byte *)((int)out + (int)pDStack_1a4))[-1] = bVar16 ^ (byte)pDStack_dc;
          pDStack_174 = (DES_key_schedule *)((int)pDVar13 - (int)pDStack_1a4);
          out = (byte *)((int)out + (int)pDStack_1a4) + (int)pDVar15;
          puStack_150 = (uchar *)ivec;
          pDVar12 = pDVar8;
        } while (pDStack_1a4 <= pDVar13);
      }
    }
    else {
      pDStack_134 = (DES_key_schedule *)(&switchD_005e4168::switchdataD_00674c80 + (int)pDStack_1a4)
      ;
      pDStack_1a0 = (DES_key_schedule *)(&PTR_LAB_00674cec + (int)pDStack_1a4);
      pDStack_174 = (DES_key_schedule *)&pDStack_dc;
      pDVar15 = (DES_key_schedule *)((uint)ks1 & 7);
      pDVar24 = pDVar8;
      pDVar12 = pDVar27;
      while (pDVar27 = pDVar12, pDVar8 = pDVar24, puStack_150 = (uchar *)ivec,
            puStack_130 = unaff_s8, pDStack_1a4 <= (uint)length) {
        pDVar14 = (DES_key_schedule *)0x1;
        unaff_s8 = (uchar *)(uint)(pDStack_1a4 < (DES_key_schedule *)&DAT_00000009);
        puVar26 = (uchar *)((int)ivec + (int)pDStack_1a4);
        pDStack_108 = pDStack_174;
        pDStack_104 = (DES_key_schedule *)length;
        pDStack_100 = pDVar15;
        pDStack_fc = ks1;
        pDStack_dc = pDVar8;
        pDStack_d8 = pDVar27;
        (*(code *)pDStack_118[-0xd3].ks[0xd].deslong[0])(pDStack_174,puStack_10c);
        pDVar13 = pDStack_fc;
        pDVar15 = pDStack_100;
        length = (int)pDStack_104 - (int)pDStack_1a4;
        if (unaff_s8 == (uchar *)0x0) {
switchD_005e4168_caseD_5e4874:
          uVar18 = 0;
          uVar6 = 0;
        }
        else {
          switch((uint)pDStack_134->ks[0].deslong[0] & 0xfffffffe) {
          case 0x5e4598:
            uVar18 = 0;
            break;
          case 0x5e4834:
            uVar18 = 0;
            goto LAB_005e45c8;
          case 0x5e483c:
            uVar18 = 0;
            pDVar14 = (DES_key_schedule *)0x0;
            goto LAB_005e45d4;
          case 0x5e4848:
            uVar18 = 0;
            uVar6 = 0;
            goto LAB_005e45e4;
          case 0x5e485c:
            uVar18 = 0;
            goto LAB_005e45ac;
          case 0x5e4864:
            uVar18 = 0;
            goto LAB_005e45bc;
          case 0x5e4874:
            goto switchD_005e4168_caseD_5e4874;
          case 0x5e4890:
            pauVar2 = (DES_cblock *)(puVar26 + -1);
            puVar26 = puVar26 + -1;
            uVar18 = (uint)(*pauVar2)[0] << 0x18;
          }
          pauVar2 = (DES_cblock *)(puVar26 + -1);
          puVar26 = puVar26 + -1;
          uVar18 = (uint)(*pauVar2)[0] << 0x10 | uVar18;
LAB_005e45ac:
          puVar1 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          uVar18 = (uint)*puVar1 << 8 | uVar18;
LAB_005e45bc:
          puVar1 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          uVar18 = *puVar1 | uVar18;
LAB_005e45c8:
          puVar1 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          pDVar14 = (DES_key_schedule *)((uint)*puVar1 << 0x18);
LAB_005e45d4:
          puVar1 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          uVar6 = (uint)*puVar1 << 0x10 | (uint)pDVar14;
LAB_005e45e4:
          puVar1 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          uVar6 = (uint)*puVar1 << 8 | uVar6;
        }
        puVar22 = (undefined *)((int)pDStack_1a4[-1].ks + 0x7f);
        ivec = (DES_cblock *)(puVar26 + (int)puVar22);
        pDVar5 = (DES_key_schedule *)((puVar26[-1] | uVar6) ^ (uint)pDStack_dc);
        pDVar9 = (DES_key_schedule *)(uVar18 ^ (uint)pDStack_d8);
        if (unaff_s8 != (uchar *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e4620. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)pDStack_1a0->ks[0].deslong[0])();
          return;
        }
        ((byte *)((int)out + (int)pDStack_1a4))[-1] = (byte)pDVar5;
        out = (byte *)((int)out + (int)pDStack_1a4) + (int)puVar22;
        pDStack_174 = pDStack_108;
        ks1 = pDStack_fc;
        pDVar24 = pDVar27;
        pDVar12 = pDVar5;
        if ((pDStack_fc != (DES_key_schedule *)&DAT_00000020) &&
           (pDVar14 = (DES_key_schedule *)((uint)pDVar8 >> 0x10), pDVar24 = pDVar5, pDVar12 = pDVar9
           , pDStack_fc != (DES_key_schedule *)&DAT_00000040)) {
          abStack_cc[0] = (byte)pDVar5;
          abStack_cc[1] = (char)((uint)pDVar5 >> 8);
          abStack_cc[2] = (char)((uint)pDVar5 >> 0x10);
          _uStack_d4 = CONCAT31(CONCAT21(CONCAT11((char)pDVar8,(char)((uint)pDVar8 >> 8)),
                                         (char)((uint)pDVar8 >> 0x10)),(char)((uint)pDVar8 >> 0x18))
          ;
          uStack_d0 = CONCAT31(CONCAT21(CONCAT11((char)pDVar27,(char)((uint)pDVar27 >> 8)),
                                        (char)((uint)pDVar27 >> 0x10)),(char)((uint)pDVar27 >> 0x18)
                              );
          abStack_cc[3] = (char)((uint)pDVar5 >> 0x18);
          abStack_cc[4] = (char)pDVar9;
          abStack_cc[5] = (char)((uint)pDVar9 >> 8);
          abStack_cc[6] = (char)((uint)pDVar9 >> 0x10);
          abStack_cc[7] = (char)((uint)pDVar9 >> 0x18);
          if (pDStack_100 == (DES_key_schedule *)0x0) {
            pDVar14 = (DES_key_schedule *)&DAT_00000008;
            pDStack_fc = pDStack_108;
            pDStack_100 = pDVar13;
            pDStack_104 = pDVar15;
            pDStack_108 = (DES_key_schedule *)length;
            (*(code *)*(DES_key_schedule **)((int)pDStack_118[-0xa6].ks + 0x14))
                      (&uStack_d4,(int)&uStack_d4 + (int)pDStack_140);
            pDStack_174 = pDStack_fc;
            pDVar15 = pDStack_104;
            length = (long)pDStack_108;
            ks1 = pDStack_100;
          }
          else {
            uVar18 = 8 - (int)pDStack_100;
            _uStack_d3 = (uint3)(byte)(*(char *)((int)&uStack_d4 +
                                                (int)(pDStack_140->ks[0].cblock + 1)) <<
                                       ((uint)pDStack_100 & 0x1f) |
                                      (byte)((int)(uint)*(byte *)((int)&uStack_d4 +
                                                                 (int)(pDStack_140->ks[0].cblock + 2
                                                                      )) >> (uVar18 & 0x1f))) <<
                         0x10;
            _uStack_d4 = (uint3)(((uint)(byte)(*(char *)((int)&uStack_d4 + (int)pDStack_140) <<
                                               ((uint)pDStack_100 & 0x1f) |
                                              (byte)((int)(uint)*(byte *)((int)&uStack_d4 +
                                                                         (int)(pDStack_140->ks[0].
                                                                               cblock + 1)) >>
                                                    (uVar18 & 0x1f))) << 0x18) >> 8) |
                         _uStack_d3 >> 8 |
                         (uint3)(byte)(*(char *)((int)&uStack_d4 +
                                                (int)(pDStack_140->ks[0].cblock + 2)) <<
                                       ((uint)pDStack_100 & 0x1f) |
                                      (byte)((int)(uint)*(byte *)((int)&uStack_d4 +
                                                                 (int)(pDStack_140->ks[0].cblock + 3
                                                                      )) >> (uVar18 & 0x1f)));
            _uStack_d4 = CONCAT31(_uStack_d4,
                                  *(char *)((int)&uStack_d4 + (int)(pDStack_140->ks[0].cblock + 3))
                                  << ((uint)pDStack_100 & 0x1f) |
                                  (byte)((int)(uint)*(byte *)((int)&uStack_d4 +
                                                             (int)(pDStack_140->ks[0].cblock + 4))
                                        >> (uVar18 & 0x1f)));
            uStack_d0._1_3_ =
                 (uint3)(byte)(*(char *)((int)&uStack_d4 + (int)(pDStack_140->ks[0].cblock + 5)) <<
                               ((uint)pDStack_100 & 0x1f) |
                              (byte)((int)(uint)*(byte *)((int)&uStack_d4 +
                                                         (int)(pDStack_140->ks[0].cblock + 6)) >>
                                    (uVar18 & 0x1f))) << 0x10;
            pDVar14 = (DES_key_schedule *)
                      ((uint)*(byte *)((int)&uStack_d4 + (int)(pDStack_140->ks[0].cblock + 6)) <<
                      ((uint)pDStack_100 & 0x1f));
            uStack_d0._0_3_ =
                 (uint3)(((uint)(byte)(*(char *)((int)&uStack_d4 +
                                                (int)(pDStack_140->ks[0].cblock + 4)) <<
                                       ((uint)pDStack_100 & 0x1f) |
                                      (byte)((int)(uint)*(byte *)((int)&uStack_d4 +
                                                                 (int)(pDStack_140->ks[0].cblock + 5
                                                                      )) >> (uVar18 & 0x1f))) <<
                         0x18) >> 8) | uStack_d0._1_3_ >> 8 |
                 (uint3)(byte)((byte)pDVar14 |
                              (byte)((int)(uint)*(byte *)((int)&uStack_d4 +
                                                         (int)(pDStack_140->ks[0].cblock + 7)) >>
                                    (uVar18 & 0x1f)));
            uStack_d0 = CONCAT31(uStack_d0._0_3_,
                                 (byte)((int)(uint)abStack_cc[(int)pDStack_140] >> (uVar18 & 0x1f))
                                 | *(char *)((int)&uStack_d4 + (int)(pDStack_140->ks[0].cblock + 7))
                                   << ((uint)pDStack_100 & 0x1f));
          }
          pDVar24 = (DES_key_schedule *)
                    ((((_uStack_d4 >> 0x10) << 0x18 | (_uStack_d4 >> 0x18) << 0x10) >> 0x10) +
                    ((_uStack_d4 & 0xff) << 8 | _uStack_d4 >> 8 & 0xff) * 0x10000);
          pDVar12 = (DES_key_schedule *)
                    ((((uStack_d0 >> 0x10) << 0x18 | (uStack_d0 >> 0x18) << 0x10) >> 0x10) +
                    ((uStack_d0 & 0xff) << 8 | uStack_d0 >> 8 & 0xff) * 0x10000);
        }
      }
    }
    ivec = (DES_cblock *)((uint)pDVar8 >> 0x10);
    *(byte *)puStack_ec = (byte)pDVar8;
    unaff_s2 = (uint)pDVar8 >> 0x18;
    *(byte *)(puStack_ec + 1) = (byte)pDVar27;
    *(byte *)((int)puStack_ec + 1) = (byte)((uint)pDVar8 >> 8);
    unaff_s3 = (DES_key_schedule *)((uint)pDVar27 >> 0x18);
    *(byte *)((int)puStack_ec + 2) = (byte)((uint)pDVar8 >> 0x10);
    *(byte *)((int)puStack_ec + 3) = (byte)((uint)pDVar8 >> 0x18);
    *(byte *)((int)puStack_ec + 5) = (byte)((uint)pDVar27 >> 8);
    *(byte *)((int)puStack_ec + 6) = (byte)((uint)pDVar27 >> 0x10);
    *(byte *)((int)puStack_ec + 7) = (byte)((uint)pDVar27 >> 0x18);
    puStack_198 = puStack_ec;
    unaff_s1 = (uint *)out;
  }
  if (iStack_c4 == *piStack_f0) {
    return;
  }
  pcStack_12c = DES_ede3_ofb64_encrypt;
  (*(code *)pDStack_118[-0xa7].ks[10].deslong[0])();
  pDStack_1b0 = pDStack_118;
  pbVar29 = &_gp;
  pDStack_144 = unaff_s3;
  piStack_16c = (int *)PTR___stack_chk_guard_006a9ae8;
  uStack_148 = unaff_s2;
  pDStack_138 = pDStack_1a0;
  pDStack_13c = pDStack_1a4;
  puStack_14c = unaff_s1;
  pbStack_180 = &_gp;
  uVar19 = (uint)pbStack_110[3];
  uVar17 = (uint)pbStack_110[7];
  puStack_170 = puStack_10c;
  uVar6 = uVar19 << 0x18 |
          (uint)pbStack_110[1] << 8 | (uint)pbStack_110[2] << 0x10 | (uint)*pbStack_110;
  uStack_1b8 = *puStack_10c;
  uVar25 = uVar6 >> 8;
  iStack_154 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pbVar10 = (byte *)(uVar17 << 0x18);
  uStack_164 = uVar6;
  uVar18 = (uint)pbVar10 |
           (uint)pbStack_110[5] << 8 | (uint)pbStack_110[6] << 0x10 | (uint)pbStack_110[4];
  uVar23 = uVar6 >> 0x10;
  uStack_160 = uVar18;
  uVar21 = uVar18 >> 8;
  abStack_15c[0] = *pbStack_110;
  uVar20 = uVar18 >> 0x10;
  abStack_15c[1] = pbStack_110[1];
  abStack_15c[2] = pbStack_110[2];
  abStack_15c[3] = pbStack_110[3];
  bStack_158 = pbStack_110[4];
  bStack_157 = pbStack_110[5];
  bStack_156 = pbStack_110[6];
  bStack_155 = pbStack_110[7];
  if (pDVar14 != (DES_key_schedule *)0x0) {
    pDStack_1a4 = (DES_key_schedule *)0x0;
    unaff_s1 = &uStack_164;
    pDStack_1a0 = pDVar14;
    puVar28 = puStack_198;
    do {
      if (uStack_1b8 == 0) {
        pDStack_1a4 = (DES_key_schedule *)((int)pDStack_1a4->ks + 1);
        pDVar14 = pDStack_1b0;
        (**(code **)(pbVar29 + -0x5770))(unaff_s1,pDStack_174,pDStack_1b0,uStack_114);
        uVar25 = uStack_164 >> 8;
        uVar23 = uStack_164 >> 0x10;
        abStack_15c[0] = (byte)uStack_164;
        uVar19 = uStack_164 >> 0x18;
        bStack_158 = (byte)uStack_160;
        uVar21 = uStack_160 >> 8;
        abStack_15c[1] = (byte)(uStack_164 >> 8);
        uVar20 = uStack_160 >> 0x10;
        abStack_15c[2] = (byte)(uStack_164 >> 0x10);
        uVar17 = uStack_160 >> 0x18;
        abStack_15c[3] = (byte)(uStack_164 >> 0x18);
        bStack_157 = (byte)(uStack_160 >> 8);
        bStack_156 = (byte)(uStack_160 >> 0x10);
        bStack_155 = (byte)(uStack_160 >> 0x18);
        uVar18 = uStack_160;
        uVar6 = uStack_164;
        pbVar29 = pbStack_180;
      }
      puStack_198 = (uint *)((int)puVar28 + 1);
      bVar16 = *(byte *)ivec;
      pDStack_1a0 = (DES_key_schedule *)((int)pDStack_1a0[-1].ks + 0x7f);
      pbVar3 = abStack_15c + uStack_1b8;
      pbVar10 = (byte *)(uint)*pbVar3;
      ivec = (DES_cblock *)((int)ivec + 1);
      uStack_1b8 = uStack_1b8 + 1 & 7;
      *(byte *)puVar28 = bVar16 ^ *pbVar3;
      puVar28 = puStack_198;
    } while (pDStack_1a0 != (DES_key_schedule *)0x0);
    if (pDStack_1a4 != (DES_key_schedule *)0x0) {
      *pbStack_110 = (byte)uVar6;
      pbStack_110[1] = (byte)uVar25;
      pbStack_110[2] = (byte)uVar23;
      pbStack_110[3] = (byte)uVar19;
      pbStack_110[4] = (byte)uVar18;
      pbStack_110[5] = (byte)uVar21;
      pbStack_110[6] = (byte)uVar20;
      pbStack_110[7] = (byte)uVar17;
    }
  }
  iVar7 = *piStack_16c;
  *puStack_170 = uStack_1b8;
  if (iStack_154 != iVar7) {
    uStack_194 = 0x5e4b88;
    puVar28 = puStack_170;
    (**(code **)(pbVar29 + -0x5330))();
    pbVar29 = pbStack_180;
    puVar22 = PTR___stack_chk_guard_006a9ae8;
    puStack_19c = (uchar *)ivec;
    pbStack_1a8 = pbStack_110;
    uStack_1ac = uStack_114;
    puStack_1b4 = unaff_s1;
    uVar18 = (uint)pbStack_180[3];
    uVar6 = *puStack_17c;
    uStack_1cc = uVar18 << 0x18 |
                 (uint)pbStack_180[1] << 8 | (uint)pbStack_180[2] << 0x10 | (uint)*pbStack_180;
    iStack_1bc = *(int *)PTR___stack_chk_guard_006a9ae8;
    uStack_1c8 = (uint)pbStack_180[7] << 0x18 |
                 (uint)pbStack_180[5] << 8 | (uint)pbStack_180[6] << 0x10 | (uint)pbStack_180[4];
    abStack_1c4[0] = *pbStack_180;
    abStack_1c4[2] = pbStack_180[2];
    puVar11 = (uint *)(uStack_1c8 >> 8);
    abStack_1c4[1] = pbStack_180[1];
    abStack_1c4[3] = pbStack_180[3];
    bStack_1c0 = pbStack_180[4];
    bStack_1bf = pbStack_180[5];
    bStack_1be = pbStack_180[6];
    bStack_1bd = pbStack_180[7];
    if (pDVar14 != (DES_key_schedule *)0x0) {
      iVar7 = 0;
      pDVar8 = pDVar14;
      do {
        if (uVar6 == 0) {
          (*(code *)PTR_DES_encrypt1_006a84c8)(&uStack_1cc,uVar17,1);
          iVar7 = iVar7 + 1;
          pDVar14 = (DES_key_schedule *)(uStack_1cc >> 0x10);
          abStack_1c4[0] = (byte)uStack_1cc;
          puVar11 = (uint *)(uStack_1c8 >> 8);
          bStack_1c0 = (byte)uStack_1c8;
          abStack_1c4[1] = (byte)(uStack_1cc >> 8);
          abStack_1c4[2] = (byte)(uStack_1cc >> 0x10);
          bStack_1bf = (byte)(uStack_1c8 >> 8);
          abStack_1c4[3] = (byte)(uStack_1cc >> 0x18);
          bStack_1be = (byte)(uStack_1c8 >> 0x10);
          bStack_1bd = (byte)(uStack_1c8 >> 0x18);
        }
        bVar16 = *(byte *)puVar28;
        pDVar8 = (DES_key_schedule *)((int)pDVar8[-1].ks + 0x7f);
        pbVar3 = abStack_1c4 + uVar6;
        puVar28 = (uint *)((int)puVar28 + 1);
        uVar6 = uVar6 + 1 & 7;
        *pbVar10 = bVar16 ^ *pbVar3;
        pbVar10 = pbVar10 + 1;
      } while (pDVar8 != (DES_key_schedule *)0x0);
      if (iVar7 != 0) {
        pDVar14 = (DES_key_schedule *)(uStack_1cc >> 0x10);
        *pbVar29 = (byte)uStack_1cc;
        puVar11 = (uint *)(uStack_1c8 >> 8);
        pbVar29[4] = (byte)uStack_1c8;
        pbVar29[1] = (byte)(uStack_1cc >> 8);
        pbVar29[2] = (byte)(uStack_1cc >> 0x10);
        pbVar29[5] = (byte)(uStack_1c8 >> 8);
        pbVar29[3] = (byte)(uStack_1cc >> 0x18);
        pbVar29[6] = (byte)(uStack_1c8 >> 0x10);
        pbVar29[7] = (byte)(uStack_1c8 >> 0x18);
      }
    }
    iVar7 = *(int *)puVar22;
    *puStack_17c = uVar6;
    if (iStack_1bc != iVar7) {
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
      iVar7 = 0x19;
      uVar19 = 0;
      uVar17 = 0;
      uVar6 = 0;
      do {
        uVar20 = (uint)pDVar14 & (uVar17 ^ uVar19);
        uVar17 = uVar18 & (uVar17 ^ uVar19);
        uVar21 = uVar19 ^ *puVar11 ^ uVar20;
        uVar23 = uVar20 << 0x10 ^ uVar21;
        uVar20 = uVar19 ^ puVar11[1] ^ uVar17;
        uVar17 = (uVar17 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar17 + uVar20 * 0x10000000;
        uVar6 = *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar23 & 0xfc)) ^
                *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc) + 0x100) ^
                *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 * 0x100 >> 0x1a) + 0x140) * 4) ^ uVar6
        ;
        uVar17 = uVar6 >> 0x10 ^ uVar6;
        uVar20 = (uint)pDVar14 & uVar17;
        uVar17 = uVar18 & uVar17;
        uVar21 = uVar6 ^ puVar11[2] ^ uVar20;
        uVar23 = uVar20 << 0x10 ^ uVar21;
        uVar20 = uVar6 ^ puVar11[3] ^ uVar17;
        uVar17 = (uVar17 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar17 + uVar20 * 0x10000000;
        uVar21 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar17 = uVar21 >> 0x10 ^ uVar21;
        uVar19 = (uint)pDVar14 & uVar17;
        uVar17 = uVar18 & uVar17;
        uVar20 = uVar21 ^ puVar11[4] ^ uVar19;
        uVar23 = uVar19 << 0x10 ^ uVar20;
        uVar19 = uVar21 ^ puVar11[5] ^ uVar17;
        uVar17 = (uVar17 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar17 + uVar19 * 0x10000000;
        uVar20 = uVar6 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar6 = uVar20 >> 0x10 ^ uVar20;
        uVar17 = (uint)pDVar14 & uVar6;
        uVar6 = uVar18 & uVar6;
        uVar19 = uVar20 ^ puVar11[6] ^ uVar17;
        uVar23 = uVar17 << 0x10 ^ uVar19;
        uVar17 = uVar20 ^ puVar11[7] ^ uVar6;
        uVar6 = (uVar6 << 0x10 ^ uVar17) >> 4;
        uVar17 = uVar6 + uVar17 * 0x10000000;
        uVar19 = uVar21 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar19 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar17 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar6 = uVar19 >> 0x10 ^ uVar19;
        uVar17 = (uint)pDVar14 & uVar6;
        uVar6 = uVar18 & uVar6;
        uVar21 = uVar19 ^ puVar11[8] ^ uVar17;
        uVar23 = uVar17 << 0x10 ^ uVar21;
        uVar17 = uVar19 ^ puVar11[9] ^ uVar6;
        uVar6 = (uVar6 << 0x10 ^ uVar17) >> 4;
        uVar17 = uVar6 + uVar17 * 0x10000000;
        uVar17 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar17 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
        iVar7 = iVar7 + -1;
        uVar6 = uVar17 >> 0x10 ^ uVar17;
        uVar20 = (uint)pDVar14 & uVar6;
        uVar6 = uVar18 & uVar6;
        uVar21 = uVar17 ^ puVar11[10] ^ uVar20;
        uVar23 = uVar20 << 0x10 ^ uVar21;
        uVar20 = uVar17 ^ puVar11[0xb] ^ uVar6;
        uVar6 = (uVar6 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar6 + uVar20 * 0x10000000;
        uVar20 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar6 = uVar20 >> 0x10 ^ uVar20;
        uVar19 = (uint)pDVar14 & uVar6;
        uVar6 = uVar18 & uVar6;
        uVar21 = uVar20 ^ puVar11[0xc] ^ uVar19;
        uVar23 = uVar19 << 0x10 ^ uVar21;
        uVar19 = uVar20 ^ puVar11[0xd] ^ uVar6;
        uVar6 = (uVar6 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar6 + uVar19 * 0x10000000;
        uVar19 = uVar17 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar6 = uVar19 >> 0x10 ^ uVar19;
        uVar17 = (uint)pDVar14 & uVar6;
        uVar6 = uVar18 & uVar6;
        uVar21 = uVar19 ^ puVar11[0xe] ^ uVar17;
        uVar23 = uVar17 << 0x10 ^ uVar21;
        uVar17 = uVar19 ^ puVar11[0xf] ^ uVar6;
        uVar6 = (uVar6 << 0x10 ^ uVar17) >> 4;
        uVar17 = uVar6 + uVar17 * 0x10000000;
        uVar17 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar17 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar6 = uVar17 >> 0x10 ^ uVar17;
        uVar20 = (uint)pDVar14 & uVar6;
        uVar6 = uVar18 & uVar6;
        uVar21 = uVar17 ^ puVar11[0x10] ^ uVar20;
        uVar23 = uVar20 << 0x10 ^ uVar21;
        uVar20 = uVar17 ^ puVar11[0x11] ^ uVar6;
        uVar6 = (uVar6 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar6 + uVar20 * 0x10000000;
        uVar20 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar6 = uVar20 >> 0x10 ^ uVar20;
        uVar19 = (uint)pDVar14 & uVar6;
        uVar6 = uVar18 & uVar6;
        uVar21 = uVar20 ^ puVar11[0x12] ^ uVar19;
        uVar23 = uVar19 << 0x10 ^ uVar21;
        uVar19 = uVar20 ^ puVar11[0x13] ^ uVar6;
        uVar6 = (uVar6 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar6 + uVar19 * 0x10000000;
        uVar19 = uVar17 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar6 = uVar19 >> 0x10 ^ uVar19;
        uVar17 = (uint)pDVar14 & uVar6;
        uVar6 = uVar18 & uVar6;
        uVar21 = uVar19 ^ puVar11[0x14] ^ uVar17;
        uVar23 = uVar17 << 0x10 ^ uVar21;
        uVar17 = uVar19 ^ puVar11[0x15] ^ uVar6;
        uVar6 = (uVar6 << 0x10 ^ uVar17) >> 4;
        uVar17 = uVar6 + uVar17 * 0x10000000;
        uVar17 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar17 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar6 = uVar17 >> 0x10 ^ uVar17;
        uVar20 = (uint)pDVar14 & uVar6;
        uVar6 = uVar18 & uVar6;
        uVar21 = uVar17 ^ puVar11[0x16] ^ uVar20;
        uVar23 = uVar20 << 0x10 ^ uVar21;
        uVar20 = uVar17 ^ puVar11[0x17] ^ uVar6;
        uVar6 = (uVar6 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar6 + uVar20 * 0x10000000;
        uVar20 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar6 = uVar20 >> 0x10 ^ uVar20;
        uVar19 = (uint)pDVar14 & uVar6;
        uVar6 = uVar18 & uVar6;
        uVar21 = uVar20 ^ puVar11[0x18] ^ uVar19;
        uVar23 = uVar19 << 0x10 ^ uVar21;
        uVar19 = uVar20 ^ puVar11[0x19] ^ uVar6;
        uVar6 = (uVar6 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar6 + uVar19 * 0x10000000;
        uVar19 = uVar17 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar6 = uVar19 >> 0x10 ^ uVar19;
        uVar17 = (uint)pDVar14 & uVar6;
        uVar6 = uVar18 & uVar6;
        uVar21 = uVar19 ^ puVar11[0x1a] ^ uVar17;
        uVar23 = uVar17 << 0x10 ^ uVar21;
        uVar17 = uVar19 ^ puVar11[0x1b] ^ uVar6;
        uVar6 = (uVar6 << 0x10 ^ uVar17) >> 4;
        uVar17 = uVar6 + uVar17 * 0x10000000;
        uVar20 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar17 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar6 = uVar20 >> 0x10 ^ uVar20;
        uVar17 = (uint)pDVar14 & uVar6;
        uVar6 = uVar18 & uVar6;
        uVar21 = uVar20 ^ puVar11[0x1c] ^ uVar17;
        uVar23 = uVar17 << 0x10 ^ uVar21;
        uVar17 = uVar20 ^ puVar11[0x1d] ^ uVar6;
        uVar6 = (uVar6 << 0x10 ^ uVar17) >> 4;
        uVar17 = uVar6 + uVar17 * 0x10000000;
        uVar19 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar17 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar17 = uVar19 >> 0x10;
        uVar21 = (uint)pDVar14 & (uVar17 ^ uVar19);
        uVar6 = uVar18 & (uVar17 ^ uVar19);
        uVar23 = uVar19 ^ puVar11[0x1e] ^ uVar21;
        uVar25 = uVar21 << 0x10 ^ uVar23;
        uVar21 = uVar19 ^ puVar11[0x1f] ^ uVar6;
        uVar6 = (uVar6 << 0x10 ^ uVar21) >> 4;
        uVar21 = uVar6 + uVar21 * 0x10000000;
        uVar6 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar25 >> 0x1a) + 0x180) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar25 & 0xfc)) ^
                *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar23 << 0x10) >> 0x1a) + 0x80) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar25 << 8) >> 0x1a) + 0x100) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar21 >> 0x1a) + 0x1c0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar21 & 0xfc) + 0x100) ^
                *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar6 * 0x100 >> 0x1a) + 0x140) * 4);
      } while (iVar7 != 0);
      uVar6 = (uVar6 >> 3) + uVar6 * 0x20000000;
      uVar17 = (uVar19 >> 3) + uVar19 * 0x20000000;
      uVar18 = (uVar6 >> 1 ^ uVar17) & 0x55555555;
      uVar17 = uVar17 ^ uVar18;
      uVar6 = uVar18 << 1 ^ uVar6;
      uVar18 = (uVar17 >> 8 ^ uVar6) & 0xff00ff;
      uVar6 = uVar6 ^ uVar18;
      uVar17 = uVar18 << 8 ^ uVar17;
      uVar18 = (uVar6 >> 2 ^ uVar17) & 0x33333333;
      uVar17 = uVar17 ^ uVar18;
      uVar6 = uVar18 << 2 ^ uVar6;
      uVar18 = (uVar17 >> 0x10 ^ uVar6) & 0xffff;
      uVar6 = uVar6 ^ uVar18;
      uVar17 = uVar18 << 0x10 ^ uVar17;
      uVar18 = (uVar6 >> 4 ^ uVar17) & 0xf0f0f0f;
      *puStack_17c = uVar17 ^ uVar18;
      puStack_17c[1] = uVar18 << 4 ^ uVar6;
      return;
    }
    return;
  }
  return;
}

