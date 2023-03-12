
/* WARNING: Could not reconcile some variable overlaps */

undefined4
CRYPTO_xts128_encrypt
          (undefined4 *param_1,uint param_2,uint *param_3,uint *param_4,uint param_5,int param_6)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  undefined *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  uint extraout_v1;
  int iVar12;
  uint uVar13;
  uint in_t0;
  uint in_t1;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint in_t4;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint *unaff_s0;
  uint *puVar20;
  uint *puVar21;
  uint uVar22;
  uint uVar23;
  undefined4 *local_68;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_2c;
  
  puVar7 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar11 = 0xffffffff;
  uVar22 = in_t4;
  if (param_5 < 0x10) goto LAB_005edbd0;
  uVar22 = param_2 & 3;
  uVar14 = param_2 + 4 & 3;
  uVar16 = param_2 + 0xc & 3;
  uVar17 = param_2 + 8 & 3;
  uVar23 = param_2 + 3 & 3;
  local_60 = (*(int *)(param_2 - uVar22) << uVar22 * 8 | in_t1 & 0xffffffffU >> (4 - uVar22) * 8) &
             -1 << (uVar23 + 1) * 8 | *(uint *)((param_2 + 3) - uVar23) >> (3 - uVar23) * 8;
  uVar22 = param_2 + 7 & 3;
  local_5c = (*(int *)((param_2 + 4) - uVar14) << uVar14 * 8 |
             in_t0 & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar22 + 1) * 8 |
             *(uint *)((param_2 + 7) - uVar22) >> (3 - uVar22) * 8;
  uVar22 = param_2 + 0xf & 3;
  local_54 = *(int *)((param_2 + 0xc) - uVar16) << uVar16 * 8 & -1 << (uVar22 + 1) * 8 |
             *(uint *)((param_2 + 0xf) - uVar22) >> (3 - uVar22) * 8;
  uVar22 = param_2 + 0xb & 3;
  local_58 = (*(int *)((param_2 + 8) - uVar17) << uVar17 * 8 |
             (uint)param_4 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar22 + 1) * 8 |
             *(uint *)((param_2 + 0xb) - uVar22) >> (3 - uVar22) * 8;
  (*(code *)param_1[3])(&local_60,&local_60,param_1[1]);
  if (((param_6 != 0) || ((param_5 & 0xf) == 0)) ||
     (param_5 = param_5 - 0x10, unaff_s0 = param_4, 0xf < param_5)) {
    local_68 = &local_50;
    uVar14 = extraout_v1;
    do {
      puVar21 = param_3;
      puVar20 = param_4;
      param_5 = param_5 - 0x10;
      uVar22 = (uint)(puVar21 + 2) & 3;
      local_50 = *puVar21 ^ local_60;
      uVar16 = (uint)(byte *)((int)puVar21 + 0xbU) & 3;
      param_3 = puVar21 + 4;
      local_4c = puVar21[1] ^ local_5c;
      local_44 = puVar21[3] ^ local_54;
      local_48 = ((*(int *)((int)(puVar21 + 2) - uVar22) << uVar22 * 8 |
                  uVar14 & 0xffffffffU >> (4 - uVar22) * 8) & -1 << (uVar16 + 1) * 8 |
                 *(uint *)((byte *)((int)puVar21 + 0xbU) + -uVar16) >> (3 - uVar16) * 8) ^ local_58;
      (*(code *)param_1[2])(local_68,local_68,*param_1);
      local_50 = local_50 ^ local_60;
      local_4c = local_4c ^ local_5c;
      local_48 = local_48 ^ local_58;
      *puVar20 = local_50;
      puVar20[1] = local_4c;
      uVar22 = local_44 ^ local_54;
      puVar20[2] = local_48;
      puVar20[3] = uVar22;
      unaff_s0 = puVar20 + 4;
      local_44 = uVar22;
      if (param_5 == 0) {
        uVar11 = 0;
        uVar22 = in_t4;
        goto LAB_005edbd0;
      }
      uVar18 = (local_60 >> 0x18) << 1;
      uVar17 = (local_60 >> 0x10 & 0xff) * 2 + (uVar18 >> 8);
      uVar16 = (local_60 >> 8 & 0xff) * 2 + (uVar17 >> 8);
      uVar14 = (local_60 & 0xff) * 2 + (uVar16 >> 8);
      in_t4 = uVar14 >> 8;
      local_60 = uVar14 & 0xff | (uint)(CONCAT21((short)uVar17,(char)uVar16) & 0xffff) << 8;
      uVar23 = (local_5c >> 0x18) * 2 + in_t4;
      uVar17 = (local_5c >> 0x10 & 0xff) * 2 + (uVar23 >> 8);
      uVar16 = (local_5c >> 8 & 0xff) * 2 + (uVar17 >> 8);
      uVar14 = (local_5c & 0xff) * 2 + (uVar16 >> 8);
      local_5c = uVar14 & 0xff |
                 (uint)CONCAT21(CONCAT11((char)uVar23,(char)uVar17),(char)uVar16) << 8;
      uVar23 = (local_58 >> 0x18) * 2 + (uVar14 >> 8);
      uVar17 = (local_58 >> 0x10 & 0xff) * 2 + (uVar23 >> 8);
      uVar16 = (local_58 >> 8 & 0xff) * 2 + (uVar17 >> 8);
      uVar14 = (local_58 & 0xff) * 2 + (uVar16 >> 8);
      local_58 = uVar14 & 0xff |
                 (uint)CONCAT21(CONCAT11((char)uVar23,(char)uVar17),(char)uVar16) << 8;
      uVar14 = (local_54 >> 0x18) * 2 + (uVar14 >> 8);
      uVar23 = (local_54 >> 0x10 & 0xff) * 2 + (uVar14 >> 8);
      uVar17 = (local_54 >> 8 & 0xff) * 2 + (uVar23 >> 8);
      uVar16 = (local_54 & 0xff) * 2 + (uVar17 >> 8);
      local_54 = uVar16 & 0xff |
                 (uint)CONCAT21(CONCAT11((char)uVar14,(char)uVar23),(char)uVar17) << 8;
      uVar14 = 0xffffff87;
      local_60 = local_60 | (uint)(byte)(-(char)(uVar16 >> 8) & 0x87U ^ (byte)uVar18) << 0x18;
      param_4 = unaff_s0;
    } while (0xf < param_5);
    if (param_6 != 0) {
      if ((param_5 >= 6 && (puVar20 + 5 <= param_3 || puVar21 + 5 <= unaff_s0)) &&
         ((((uint)unaff_s0 | (uint)param_3) & 3) == 0)) {
        uVar14 = 1;
        if (param_5 != 0) {
          uVar14 = param_5;
        }
        iVar12 = (uVar14 - 4 >> 2) + 1;
        uVar16 = iVar12 * 4;
        if (param_5 < 4) {
          uVar16 = 0;
        }
        else {
          uVar17 = *param_3;
          *unaff_s0 = local_50;
          local_50 = uVar17;
          if (iVar12 != 1) {
            uVar17 = puVar21[5];
            puVar20[5] = local_4c;
            local_4c = uVar17;
            if (iVar12 != 2) {
              uVar17 = puVar21[6];
              puVar20[6] = local_48;
              local_48 = uVar17;
              if (iVar12 != 3) {
                local_44 = puVar21[7];
                puVar20[7] = uVar22;
              }
            }
          }
          uVar22 = local_44;
          if (uVar16 == uVar14) goto LAB_005ee16c;
        }
        uVar14 = uVar16 + 1;
        bVar1 = *(byte *)((int)&local_50 + uVar16);
        *(byte *)((int)&local_50 + uVar16) = *(byte *)((int)param_3 + uVar16);
        *(byte *)((int)unaff_s0 + uVar16) = bVar1;
        uVar22 = local_44;
        if (param_5 <= uVar14) goto LAB_005ee16c;
        uVar17 = uVar16 + 2;
        bVar1 = *(byte *)((int)&local_50 + uVar16 + 1);
        *(byte *)((int)&local_50 + uVar16 + 1) = *(byte *)((int)param_3 + uVar14);
        *(byte *)((int)unaff_s0 + uVar14) = bVar1;
        uVar22 = local_44;
        if (param_5 <= uVar17) goto LAB_005ee16c;
        bVar1 = *(byte *)((int)&local_50 + uVar16 + 2);
        *(byte *)((int)&local_50 + uVar16 + 2) = *(byte *)((int)param_3 + uVar17);
        *(byte *)((int)unaff_s0 + uVar17) = bVar1;
        uVar22 = local_44;
        goto LAB_005ee16c;
      }
      bVar1 = *(byte *)param_3;
      local_50._0_1_ = (byte)(local_50 >> 0x18);
      uVar14 = local_50 & 0xffffff;
      uVar16 = (uint)bVar1 << 0x18;
      local_50 = uVar14 | uVar16;
      *(byte *)unaff_s0 = local_50._0_1_;
      if (param_5 == 1) goto LAB_005ee16c;
      local_50._1_1_ = (byte)(uVar14 >> 0x10);
      local_50._2_2_ = (ushort)uVar14;
      local_50._1_3_ = CONCAT12(*(byte *)((int)puVar21 + 0x11),local_50._2_2_);
      local_50 = CONCAT13(bVar1,local_50._1_3_);
      *(byte *)((int)puVar20 + 0x11) = local_50._1_1_;
      if (param_5 == 2) goto LAB_005ee16c;
      local_50._2_1_ = (byte)((uint)local_50._1_3_ >> 8);
      uVar6 = local_50._2_2_ & 0xff;
      local_50._2_2_ = uVar6 | (ushort)*(byte *)((int)puVar21 + 0x12) << 8;
      uVar16 = uVar16 | local_50._1_3_ & 0xffff0000;
      local_50 = uVar16 | local_50._2_2_;
      *(byte *)((int)puVar20 + 0x12) = local_50._2_1_;
      if (param_5 == 3) goto LAB_005ee16c;
      local_50._3_1_ = (byte)uVar6;
      local_50 = uVar16 | local_50._2_2_ & 0xffffff00 | (uint)*(byte *)((int)puVar21 + 0x13);
      *(byte *)((int)puVar20 + 0x13) = (byte)local_50;
      if (param_5 == 4) goto LAB_005ee16c;
      bVar1 = *(byte *)(puVar21 + 5);
      local_4c._0_1_ = (byte)(local_4c >> 0x18);
      uVar14 = local_4c & 0xffffff;
      uVar16 = (uint)bVar1 << 0x18;
      local_4c = uVar14 | uVar16;
      *(byte *)(puVar20 + 5) = local_4c._0_1_;
      if (param_5 < 6) goto LAB_005ee16c;
      local_4c._1_1_ = (byte)(uVar14 >> 0x10);
      local_4c._2_2_ = (ushort)uVar14;
      local_4c._1_3_ = CONCAT12(*(byte *)((int)puVar21 + 0x15),local_4c._2_2_);
      local_4c = CONCAT13(bVar1,local_4c._1_3_);
      *(byte *)((int)puVar20 + 0x15) = local_4c._1_1_;
      if (param_5 < 7) goto LAB_005ee16c;
      local_4c._2_1_ = (byte)((uint)local_4c._1_3_ >> 8);
      uVar6 = local_4c._2_2_ & 0xff;
      local_4c._2_2_ = uVar6 | (ushort)*(byte *)((int)puVar21 + 0x16) << 8;
      uVar16 = uVar16 | local_4c._1_3_ & 0xffff0000;
      local_4c = uVar16 | local_4c._2_2_;
      *(byte *)((int)puVar20 + 0x16) = local_4c._2_1_;
      if (param_5 == 7) goto LAB_005ee16c;
      local_4c._3_1_ = (byte)uVar6;
      local_4c = uVar16 | local_4c._2_2_ & 0xffffff00 | (uint)*(byte *)((int)puVar21 + 0x17);
      *(byte *)((int)puVar20 + 0x17) = (byte)local_4c;
      if (param_5 == 8) goto LAB_005ee16c;
      bVar1 = *(byte *)(puVar21 + 6);
      local_48._0_1_ = (byte)(local_48 >> 0x18);
      uVar14 = local_48 & 0xffffff;
      uVar16 = (uint)bVar1 << 0x18;
      local_48 = uVar14 | uVar16;
      *(byte *)(puVar20 + 6) = local_48._0_1_;
      if (param_5 == 9) goto LAB_005ee16c;
      local_48._1_1_ = (byte)(uVar14 >> 0x10);
      local_48._2_2_ = (ushort)uVar14;
      local_48._1_3_ = CONCAT12(*(byte *)((int)puVar21 + 0x19),local_48._2_2_);
      local_48 = CONCAT13(bVar1,local_48._1_3_);
      *(byte *)((int)puVar20 + 0x19) = local_48._1_1_;
      if (param_5 == 10) goto LAB_005ee16c;
      local_48._2_1_ = (byte)((uint)local_48._1_3_ >> 8);
      uVar6 = local_48._2_2_ & 0xff;
      local_48._2_2_ = uVar6 | (ushort)*(byte *)((int)puVar21 + 0x1a) << 8;
      uVar16 = uVar16 | local_48._1_3_ & 0xffff0000;
      local_48 = uVar16 | local_48._2_2_;
      *(byte *)((int)puVar20 + 0x1a) = local_48._2_1_;
      if (param_5 == 0xb) goto LAB_005ee16c;
      local_48._3_1_ = (byte)uVar6;
      local_48 = uVar16 | local_48._2_2_ & 0xffffff00 | (uint)*(byte *)((int)puVar21 + 0x1b);
      *(byte *)((int)puVar20 + 0x1b) = (byte)local_48;
      if (param_5 == 0xc) goto LAB_005ee16c;
      bVar1 = *(byte *)(puVar21 + 7);
      local_44._0_1_ = (byte)(uVar22 >> 0x18);
      uVar14 = uVar22 & 0xffffff;
      uVar16 = (uint)bVar1 << 0x18;
      local_44 = uVar14 | uVar16;
      *(byte *)(puVar20 + 7) = local_44._0_1_;
      uVar22 = local_44;
      if (param_5 == 0xd) goto LAB_005ee16c;
      local_44._1_1_ = (byte)(uVar14 >> 0x10);
      local_44._2_2_ = (ushort)uVar14;
      local_44._1_3_ = CONCAT12(*(byte *)((int)puVar21 + 0x1d),local_44._2_2_);
      local_44 = CONCAT13(bVar1,local_44._1_3_);
      *(byte *)((int)puVar20 + 0x1d) = local_44._1_1_;
      uVar22 = local_44;
      if (param_5 != 0xf) goto LAB_005ee16c;
      local_44._2_1_ = (byte)((uint)local_44._1_3_ >> 8);
      local_44._2_2_ = local_44._2_2_ & 0xff | (ushort)*(byte *)((int)puVar21 + 0x1e) << 8;
      local_44 = uVar16 | local_44._1_3_ & 0xffff0000 | (uint)local_44._2_2_;
      *(byte *)((int)puVar20 + 0x1e) = local_44._2_1_;
      uVar22 = local_44;
      goto LAB_005ee16c;
    }
  }
  local_68 = &local_50;
  uVar19 = (local_60 >> 0x18) << 1;
  uVar16 = (local_60 >> 0x10 & 0xff) * 2 + (uVar19 >> 8);
  uVar14 = (local_60 >> 8 & 0xff) * 2 + (uVar16 >> 8);
  uVar22 = (local_60 & 0xff) * 2 + (uVar14 >> 8);
  local_40 = uVar22 & 0xff | (uint)(CONCAT21((short)uVar16,(char)uVar14) & 0xffff) << 8;
  uVar17 = (local_5c >> 0x18) * 2 + (uVar22 >> 8);
  uVar22 = (local_5c >> 0x10 & 0xff) * 2 + (uVar17 >> 8);
  uVar16 = (local_5c >> 8 & 0xff) * 2 + (uVar22 >> 8);
  uVar13 = (local_54 >> 8 & 0xff) * 2;
  uVar14 = (local_5c & 0xff) * 2 + (uVar16 >> 8);
  local_3c = uVar14 & 0xff | (uint)CONCAT21(CONCAT11((char)uVar17,(char)uVar22),(char)uVar16) << 8;
  uVar9 = local_3c;
  uVar16 = (local_58 >> 0x18) * 2 + (uVar14 >> 8);
  uVar14 = (local_58 >> 0x10 & 0xff) * 2 + (uVar16 >> 8);
  uVar22 = (local_58 >> 8 & 0xff) * 2 + (uVar14 >> 8);
  uVar15 = (local_58 & 0xff) * 2 + (uVar22 >> 8);
  local_38 = uVar15 & 0xff | (uint)CONCAT21(CONCAT11((char)uVar16,(char)uVar14),(char)uVar22) << 8;
  uVar10 = local_38;
  uVar17 = (local_54 >> 0x18) * 2 + (uVar15 >> 8);
  uVar16 = (local_54 >> 0x10 & 0xff) * 2 + (uVar17 >> 8);
  uVar22 = uVar13 + (uVar16 >> 8);
  uVar14 = (local_54 & 0xff) * 2 + (uVar22 >> 8);
  local_34 = uVar14 & 0xff | (uint)CONCAT21(CONCAT11((char)uVar17,(char)uVar16),(char)uVar22) << 8;
  uVar22 = local_34;
  uVar5 = -(uVar14 >> 8);
  uVar19 = uVar5 & 0xffffff87 ^ uVar19;
  local_40 = local_40 | uVar19 << 0x18;
  uVar8 = local_40;
  uVar14 = (uint)param_3 & 3;
  uVar16 = (uint)(param_3 + 1) & 3;
  uVar17 = (uint)(param_3 + 2) & 3;
  uVar23 = (uint)(param_3 + 3) & 3;
  uVar18 = (uint)(byte *)((int)param_3 + 3U) & 3;
  uVar2 = (uint)(byte *)((int)param_3 + 7U) & 3;
  uVar3 = (uint)(byte *)((int)param_3 + 0xbU) & 3;
  uVar4 = (uint)(byte *)((int)param_3 + 0xfU) & 3;
  local_50 = ((*(int *)((int)param_3 - uVar14) << uVar14 * 8 |
              uVar13 & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar18 + 1) * 8 |
             *(uint *)((byte *)((int)param_3 + 3U) + -uVar18) >> (3 - uVar18) * 8) ^ local_40;
  local_4c = ((*(int *)((int)(param_3 + 1) - uVar16) << uVar16 * 8 |
              uVar15 & 0xffffffffU >> (4 - uVar16) * 8) & -1 << (uVar2 + 1) * 8 |
             *(uint *)((byte *)((int)param_3 + 7U) + -uVar2) >> (3 - uVar2) * 8) ^ local_3c;
  local_48 = ((*(int *)((int)(param_3 + 2) - uVar17) << uVar17 * 8 |
              uVar5 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar3 + 1) * 8 |
             *(uint *)((byte *)((int)param_3 + 0xbU) + -uVar3) >> (3 - uVar3) * 8) ^ local_38;
  local_44 = ((*(int *)((int)(param_3 + 3) - uVar23) << uVar23 * 8 |
              uVar19 & 0xffffffffU >> (4 - uVar23) * 8) & -1 << (uVar4 + 1) * 8 |
             *(uint *)((byte *)((int)param_3 + 0xfU) + -uVar4) >> (3 - uVar4) * 8) ^ local_34;
  (*(code *)param_1[2])(local_68,local_68,*param_1);
  local_4c = local_4c ^ uVar9;
  local_48 = local_48 ^ uVar10;
  uVar22 = local_44 ^ uVar22;
  local_50 = local_50 ^ uVar8;
  local_44 = uVar22;
  if (param_5 != 0) {
    if ((5 < param_5 && (param_3 + 5 <= unaff_s0 + 4 || unaff_s0 + 5 <= param_3 + 4)) &&
       ((((uint)(unaff_s0 + 4) | (uint)(param_3 + 4)) & 3) == 0)) {
      iVar12 = (param_5 - 4 >> 2) + 1;
      uVar14 = iVar12 * 4;
      if (param_5 - 1 < 3) {
        uVar14 = 0;
      }
      else {
        uVar16 = param_3[4];
        unaff_s0[4] = local_50;
        local_50 = uVar16;
        if (iVar12 != 1) {
          uVar16 = param_3[5];
          unaff_s0[5] = local_4c;
          local_4c = uVar16;
          if (iVar12 != 2) {
            uVar16 = param_3[6];
            unaff_s0[6] = local_48;
            local_48 = uVar16;
            if (iVar12 != 3) {
              local_44 = param_3[7];
              unaff_s0[7] = uVar22;
            }
          }
        }
        uVar22 = local_44;
        if (param_5 == uVar14) goto LAB_005edf88;
      }
      bVar1 = *(byte *)((int)&local_50 + uVar14);
      *(byte *)((int)&local_50 + uVar14) = *(byte *)((int)param_3 + uVar14 + 0x10);
      *(byte *)((int)unaff_s0 + uVar14 + 0x10) = bVar1;
      uVar22 = local_44;
      if (uVar14 + 1 < param_5) {
        bVar1 = *(byte *)((int)&local_50 + uVar14 + 1);
        *(byte *)((int)&local_50 + uVar14 + 1) = *(byte *)((int)param_3 + uVar14 + 0x11);
        *(byte *)((int)unaff_s0 + uVar14 + 0x11) = bVar1;
        uVar22 = local_44;
        if (uVar14 + 2 < param_5) {
          bVar1 = *(byte *)((int)&local_50 + uVar14 + 2);
          *(byte *)((int)&local_50 + uVar14 + 2) = *(byte *)((int)param_3 + uVar14 + 0x12);
          *(byte *)((int)unaff_s0 + uVar14 + 0x12) = bVar1;
          uVar22 = local_44;
        }
      }
    }
    else {
      bVar1 = *(byte *)(param_3 + 4);
      local_50._0_1_ = (byte)(local_50 >> 0x18);
      uVar14 = local_50 & 0xffffff;
      uVar16 = (uint)bVar1 << 0x18;
      local_50 = uVar14 | uVar16;
      *(byte *)(unaff_s0 + 4) = local_50._0_1_;
      if (param_5 != 1) {
        local_50._1_1_ = (byte)(uVar14 >> 0x10);
        local_50._2_2_ = (ushort)uVar14;
        local_50._1_3_ = CONCAT12(*(byte *)((int)param_3 + 0x11),local_50._2_2_);
        local_50 = CONCAT13(bVar1,local_50._1_3_);
        *(byte *)((int)unaff_s0 + 0x11) = local_50._1_1_;
        if (param_5 != 2) {
          local_50._2_1_ = (byte)((uint)local_50._1_3_ >> 8);
          uVar6 = local_50._2_2_ & 0xff;
          local_50._2_2_ = uVar6 | (ushort)*(byte *)((int)param_3 + 0x12) << 8;
          uVar16 = uVar16 | local_50._1_3_ & 0xffff0000;
          local_50 = uVar16 | local_50._2_2_;
          *(byte *)((int)unaff_s0 + 0x12) = local_50._2_1_;
          if (param_5 != 3) {
            local_50._3_1_ = (byte)uVar6;
            local_50 = uVar16 | local_50._2_2_ & 0xffffff00 | (uint)*(byte *)((int)param_3 + 0x13);
            *(byte *)((int)unaff_s0 + 0x13) = (byte)local_50;
            if (param_5 != 4) {
              bVar1 = *(byte *)(param_3 + 5);
              local_4c._0_1_ = (byte)(local_4c >> 0x18);
              uVar14 = local_4c & 0xffffff;
              uVar16 = (uint)bVar1 << 0x18;
              local_4c = uVar14 | uVar16;
              *(byte *)(unaff_s0 + 5) = local_4c._0_1_;
              if (5 < param_5) {
                local_4c._1_1_ = (byte)(uVar14 >> 0x10);
                local_4c._2_2_ = (ushort)uVar14;
                local_4c._1_3_ = CONCAT12(*(byte *)((int)param_3 + 0x15),local_4c._2_2_);
                local_4c = CONCAT13(bVar1,local_4c._1_3_);
                *(byte *)((int)unaff_s0 + 0x15) = local_4c._1_1_;
                if (6 < param_5) {
                  local_4c._2_1_ = (byte)((uint)local_4c._1_3_ >> 8);
                  uVar6 = local_4c._2_2_ & 0xff;
                  local_4c._2_2_ = uVar6 | (ushort)*(byte *)((int)param_3 + 0x16) << 8;
                  uVar16 = uVar16 | local_4c._1_3_ & 0xffff0000;
                  local_4c = uVar16 | local_4c._2_2_;
                  *(byte *)((int)unaff_s0 + 0x16) = local_4c._2_1_;
                  if (param_5 != 7) {
                    local_4c._3_1_ = (byte)uVar6;
                    local_4c = uVar16 | local_4c._2_2_ & 0xffffff00 |
                               (uint)*(byte *)((int)param_3 + 0x17);
                    *(byte *)((int)unaff_s0 + 0x17) = (byte)local_4c;
                    if (param_5 != 8) {
                      bVar1 = *(byte *)(param_3 + 6);
                      local_48._0_1_ = (byte)(local_48 >> 0x18);
                      uVar14 = local_48 & 0xffffff;
                      uVar16 = (uint)bVar1 << 0x18;
                      local_48 = uVar14 | uVar16;
                      *(byte *)(unaff_s0 + 6) = local_48._0_1_;
                      if (param_5 != 9) {
                        local_48._1_1_ = (byte)(uVar14 >> 0x10);
                        local_48._2_2_ = (ushort)uVar14;
                        local_48._1_3_ = CONCAT12(*(byte *)((int)param_3 + 0x19),local_48._2_2_);
                        local_48 = CONCAT13(bVar1,local_48._1_3_);
                        *(byte *)((int)unaff_s0 + 0x19) = local_48._1_1_;
                        if (param_5 != 10) {
                          local_48._2_1_ = (byte)((uint)local_48._1_3_ >> 8);
                          uVar6 = local_48._2_2_ & 0xff;
                          local_48._2_2_ = uVar6 | (ushort)*(byte *)((int)param_3 + 0x1a) << 8;
                          uVar16 = uVar16 | local_48._1_3_ & 0xffff0000;
                          local_48 = uVar16 | local_48._2_2_;
                          *(byte *)((int)unaff_s0 + 0x1a) = local_48._2_1_;
                          if (param_5 != 0xb) {
                            local_48._3_1_ = (byte)uVar6;
                            local_48 = uVar16 | local_48._2_2_ & 0xffffff00 |
                                       (uint)*(byte *)((int)param_3 + 0x1b);
                            *(byte *)((int)unaff_s0 + 0x1b) = (byte)local_48;
                            if (param_5 != 0xc) {
                              bVar1 = *(byte *)(param_3 + 7);
                              local_44._0_1_ = (byte)(uVar22 >> 0x18);
                              uVar14 = uVar22 & 0xffffff;
                              uVar16 = (uint)bVar1 << 0x18;
                              local_44 = uVar14 | uVar16;
                              *(byte *)(unaff_s0 + 7) = local_44._0_1_;
                              uVar22 = local_44;
                              if (param_5 != 0xd) {
                                local_44._1_1_ = (byte)(uVar14 >> 0x10);
                                local_44._2_2_ = (ushort)uVar14;
                                local_44._1_3_ =
                                     CONCAT12(*(byte *)((int)param_3 + 0x1d),local_44._2_2_);
                                local_44 = CONCAT13(bVar1,local_44._1_3_);
                                *(byte *)((int)unaff_s0 + 0x1d) = local_44._1_1_;
                                uVar22 = local_44;
                                if (param_5 == 0xf) {
                                  local_44._2_1_ = (byte)((uint)local_44._1_3_ >> 8);
                                  local_44._2_2_ =
                                       local_44._2_2_ & 0xff |
                                       (ushort)*(byte *)((int)param_3 + 0x1e) << 8;
                                  local_44 = uVar16 | local_44._1_3_ & 0xffff0000 |
                                             (uint)local_44._2_2_;
                                  *(byte *)((int)unaff_s0 + 0x1e) = local_44._2_1_;
                                  uVar22 = local_44;
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
LAB_005edf88:
  local_50 = local_60 ^ local_50;
  local_48 = local_58 ^ local_48;
  local_4c = local_5c ^ local_4c;
  local_44 = local_54 ^ uVar22;
  (*(code *)param_1[2])(local_68,local_68,*param_1);
  uVar11 = 0;
  local_50 = local_50 ^ local_60;
  local_4c = local_4c ^ local_5c;
  *unaff_s0 = local_50;
  local_48 = local_48 ^ local_58;
  unaff_s0[1] = local_4c;
  unaff_s0[2] = local_48;
  local_44 = local_44 ^ local_54;
  unaff_s0[3] = local_44;
LAB_005edbd0:
  while (local_2c != *(int *)puVar7) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005ee16c:
    local_50 = local_50 ^ local_60;
    local_48 = local_48 ^ local_58;
    local_4c = local_4c ^ local_5c;
    local_44 = uVar22 ^ local_54;
    (*(code *)param_1[2])(local_68,local_68,*param_1);
    uVar11 = 0;
    local_50 = local_50 ^ local_60;
    local_4c = local_4c ^ local_5c;
    unaff_s0[-4] = local_50;
    local_48 = local_48 ^ local_58;
    unaff_s0[-3] = local_4c;
    unaff_s0[-2] = local_48;
    local_44 = local_44 ^ local_54;
    unaff_s0[-1] = local_44;
  }
  return uVar11;
}

