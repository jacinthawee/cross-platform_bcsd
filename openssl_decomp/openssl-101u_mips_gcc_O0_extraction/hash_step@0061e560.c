
/* WARNING: Could not reconcile some variable overlaps */

undefined4 hash_step(undefined4 param_1,uint *param_2,uint *param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  uint *puVar11;
  uint *puVar12;
  uint in_t1;
  uint uVar13;
  uint in_t2;
  uint uVar14;
  uint uVar15;
  uint in_t6;
  uint in_t7;
  uint uVar16;
  int iVar17;
  uint unaff_s6;
  uint uVar18;
  uint uVar19;
  uint unaff_s7;
  uint uVar20;
  uint in_t8;
  undefined *puVar21;
  uint uVar22;
  undefined uStack_111;
  undefined uStack_109;
  undefined uStack_101;
  undefined uStack_f9;
  undefined uStack_e9;
  undefined uStack_e1;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  uint local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  undefined4 local_6c;
  undefined4 local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined local_4c;
  undefined local_4b;
  undefined local_4a;
  undefined local_49;
  undefined local_48;
  undefined local_47;
  undefined local_46;
  undefined local_45;
  undefined local_44;
  undefined local_43;
  undefined local_42;
  undefined local_41;
  undefined local_40;
  undefined local_3f;
  undefined local_3e;
  undefined local_3d;
  undefined local_3c;
  undefined local_3b;
  undefined local_3a;
  undefined local_39;
  undefined local_38;
  undefined local_37;
  undefined local_36;
  undefined local_35;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  undefined local_30;
  undefined local_2f;
  undefined local_2e;
  undefined local_2d;
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((((uint)param_3 | (uint)param_2) & 3) == 0) {
    in_t1 = *param_3 ^ *param_2;
    local_a8 = param_3[1] ^ param_2[1];
    local_a4 = param_3[2] ^ param_2[2];
    local_a0 = param_2[3] ^ param_3[3];
    local_9c = param_3[4] ^ param_2[4];
    local_98 = param_3[5] ^ param_2[5];
    in_t2 = param_2[7];
    local_94 = param_3[6] ^ param_2[6];
    local_90 = param_3[7] ^ in_t2;
    local_ac = in_t1;
  }
  else {
    puVar6 = &local_ac;
    puVar11 = param_3;
    puVar12 = param_2;
    do {
      bVar2 = *(byte *)puVar11;
      puVar7 = (uint *)((int)puVar6 + 1);
      bVar1 = *(byte *)puVar12;
      puVar11 = (uint *)((int)puVar11 + 1);
      puVar12 = (uint *)((int)puVar12 + 1);
      *(byte *)puVar6 = bVar2 ^ bVar1;
      puVar6 = puVar7;
    } while (&local_8c != puVar7);
  }
  puVar6 = param_2 + 2;
  iVar10 = (int)&local_6c + 2;
  local_4c = local_ac._0_1_;
  local_48 = local_ac._1_1_;
  local_44 = local_ac._2_1_;
  local_40 = (undefined)local_ac;
  local_3c = local_a8._0_1_;
  local_38 = local_a8._1_1_;
  local_34 = local_a8._2_1_;
  local_30 = (undefined)local_a8;
  local_4b = local_a4._0_1_;
  local_47 = local_a4._1_1_;
  local_43 = local_a4._2_1_;
  local_3f = (undefined)local_a4;
  local_3b = local_a0._0_1_;
  local_37 = local_a0._1_1_;
  local_33 = local_a0._2_1_;
  local_2f = (undefined)local_a0;
  local_4a = local_9c._0_1_;
  local_46 = local_9c._1_1_;
  local_42 = local_9c._2_1_;
  local_3e = (undefined)local_9c;
  local_3a = local_98._0_1_;
  local_36 = local_98._1_1_;
  local_32 = local_98._2_1_;
  local_2e = (undefined)local_98;
  local_49 = local_94._0_1_;
  local_45 = local_94._1_1_;
  local_41 = local_94._2_1_;
  local_3d = (undefined)local_94;
  local_39 = local_90._0_1_;
  local_35 = local_90._1_1_;
  local_31 = local_90._2_1_;
  local_2d = (undefined)local_90;
  puVar8 = &local_6c;
  puVar21 = PTR_gost_enc_with_key_006a98b4;
  gost_enc_with_key(param_1,&local_4c,param_2);
  uVar19 = (uint)(param_2 + 3) & 3;
  uVar5 = (uint)(param_2 + 1) & 3;
  uVar16 = (uint)puVar6 & 3;
  uVar3 = (uint)param_2 & 3;
  uVar14 = (uint)(byte *)((int)param_2 + 0xfU) & 3;
  uVar13 = (*(int *)((int)(param_2 + 3) - uVar19) << uVar19 * 8 |
           in_t1 & 0xffffffffU >> (4 - uVar19) * 8) & -1 << (uVar14 + 1) * 8 |
           *(uint *)((byte *)((int)param_2 + 0xfU) + -uVar14) >> (3 - uVar14) * 8;
  uVar18 = (uint)(byte *)((int)param_2 + 7U) & 3;
  uVar19 = (uint)(param_2 + 4) & 3;
  uVar14 = (uint)(param_2 + 5) & 3;
  uVar15 = (uint)(param_2 + 7) & 3;
  uVar22 = uVar13 ^ ((*(int *)((int)(param_2 + 1) - uVar5) << uVar5 * 8 |
                     (uint)puVar8 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar18 + 1) * 8 |
                    *(uint *)((byte *)((int)param_2 + 7U) + -uVar18) >> (3 - uVar18) * 8);
  uVar5 = (uint)(param_2 + 6) & 3;
  uVar18 = (uint)(byte *)((int)param_2 + 0xbU) & 3;
  uVar20 = (*(int *)((int)puVar6 - uVar16) << uVar16 * 8 |
           unaff_s7 & 0xffffffffU >> (4 - uVar16) * 8) & -1 << (uVar18 + 1) * 8 |
           *(uint *)((byte *)((int)param_2 + 0xbU) + -uVar18) >> (3 - uVar18) * 8;
  uVar16 = (uint)(byte *)((int)param_2 + 3U) & 3;
  uVar18 = (uint)(byte *)((int)param_2 + 0x17U) & 3;
  local_c0 = (*(int *)((int)(param_2 + 5) - uVar14) << uVar14 * 8 |
             in_t8 & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar18 + 1) * 8 |
             *(uint *)((byte *)((int)param_2 + 0x17U) + -uVar18) >> (3 - uVar18) * 8;
  uVar14 = (uint)(byte *)((int)param_2 + 0x13U) & 3;
  local_c4 = (*(int *)((int)(param_2 + 4) - uVar19) << uVar19 * 8 |
             (uint)puVar21 & 0xffffffffU >> (4 - uVar19) * 8) & -1 << (uVar14 + 1) * 8 |
             *(uint *)((byte *)((int)param_2 + 0x13U) + -uVar14) >> (3 - uVar14) * 8;
  uVar18 = uVar20 ^ ((*(int *)((int)param_2 - uVar3) << uVar3 * 8 |
                     unaff_s6 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar16 + 1) * 8 |
                    *(uint *)((byte *)((int)param_2 + 3U) + -uVar16) >> (3 - uVar16) * 8);
  uVar19 = (uint)(byte *)((int)param_2 + 0x1bU) & 3;
  local_bc = (*(int *)((int)(param_2 + 6) - uVar5) << uVar5 * 8 |
             in_t7 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar19 + 1) * 8 |
             *(uint *)((byte *)((int)param_2 + 0x1bU) + -uVar19) >> (3 - uVar19) * 8;
  uVar19 = (uint)(byte *)((int)param_2 + 0x1fU) & 3;
  local_b8 = (*(int *)((int)(param_2 + 7) - uVar15) << uVar15 * 8 |
             in_t6 & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar19 + 1) * 8 |
             *(uint *)((byte *)((int)param_2 + 0x1fU) + -uVar19) >> (3 - uVar19) * 8;
  uVar15 = param_3[2];
  uVar14 = param_3[3];
  local_84 = param_3[4];
  uVar19 = (uint)(param_3 + 5) & 3;
  uVar5 = (uint)(param_3 + 6) & 3;
  uVar16 = (uint)(param_3 + 7) & 3;
  uVar3 = (uint)(byte *)((int)param_3 + 0x17U) & 3;
  local_80 = (*(int *)((int)(param_3 + 5) - uVar19) << uVar19 * 8 |
             in_t2 & 0xffffffffU >> (4 - uVar19) * 8) & -1 << (uVar3 + 1) * 8 |
             *(uint *)((byte *)((int)param_3 + 0x17U) + -uVar3) >> (3 - uVar3) * 8;
  uVar19 = (uint)(byte *)((int)param_3 + 0x1bU) & 3;
  local_7c = (*(int *)((int)(param_3 + 6) - uVar5) << uVar5 * 8 |
             local_b8 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar19 + 1) * 8 |
             *(uint *)((byte *)((int)param_3 + 0x1bU) + -uVar19) >> (3 - uVar19) * 8;
  uVar19 = (uint)(byte *)((int)param_3 + 0x1fU) & 3;
  local_78 = (*(int *)((int)(param_3 + 7) - uVar16) << uVar16 * 8 |
             uVar13 & 0xffffffffU >> (4 - uVar16) * 8) & -1 << (uVar19 + 1) * 8 |
             *(uint *)((byte *)((int)param_3 + 0x1fU) + -uVar19) >> (3 - uVar19) * 8;
  local_74 = uVar15 ^ *param_3;
  local_70 = uVar14 ^ param_3[1];
  local_cc = uVar20;
  local_c8 = uVar13;
  local_b4 = uVar18;
  local_b0 = uVar22;
  local_8c = uVar15;
  local_88 = uVar14;
  (*(code *)PTR_memmove_006a9af4)(&local_8c,&local_84,0x18);
  local_a8 = local_88 ^ uVar13;
  local_70 = local_88 ^ uVar14;
  local_ac = local_8c ^ uVar20;
  local_74 = local_8c ^ uVar15;
  local_94 = uVar18 ^ local_74;
  local_a4 = local_84 ^ local_c4;
  local_a0 = local_80 ^ local_c0;
  local_90 = uVar22 ^ local_70;
  local_9c = local_7c ^ local_bc;
  local_98 = local_78 ^ local_b8;
  local_4c = (undefined)(local_ac >> 0x18);
  local_48 = (undefined)(local_ac >> 0x10);
  local_3b = (undefined)(local_a0 >> 0x18);
  local_44 = (undefined)(local_ac >> 8);
  local_3c = (undefined)(local_a8 >> 0x18);
  local_2f = (undefined)local_a0;
  local_34 = (undefined)(local_a8 >> 8);
  local_40 = (undefined)local_ac;
  local_47 = (undefined)(local_a4 >> 0x10);
  local_3e = (undefined)local_9c;
  uStack_109 = (undefined)(local_9c >> 0x18);
  uStack_111 = (undefined)(local_a0 >> 8);
  uStack_f9 = (undefined)(local_98 >> 0x18);
  local_4a = uStack_109;
  local_38 = (undefined)(local_a8 >> 0x10);
  local_30 = (undefined)local_a8;
  local_3f = (undefined)local_a4;
  local_33 = uStack_111;
  local_3a = uStack_f9;
  local_36 = (undefined)(local_98 >> 0x10);
  local_32 = (undefined)(local_98 >> 8);
  local_49 = (undefined)(local_94 >> 0x18);
  local_45 = (undefined)(local_94 >> 0x10);
  local_41 = (undefined)(local_94 >> 8);
  local_2e = (undefined)local_98;
  local_4b = (undefined)(local_a4 >> 0x18);
  local_43 = (undefined)(local_a4 >> 8);
  local_37 = (undefined)(local_a0 >> 0x10);
  local_42 = (undefined)(local_9c >> 8);
  local_3d = (undefined)local_94;
  uStack_101 = (undefined)(local_9c >> 0x10);
  local_46 = uStack_101;
  local_39 = (undefined)(local_90 >> 0x18);
  local_35 = (undefined)(local_90 >> 0x10);
  local_31 = (undefined)(local_90 >> 8);
  local_2d = (undefined)local_90;
  (*(code *)PTR_gost_enc_with_key_006a98b4)(param_1,&local_4c,puVar6,&local_64);
  uVar5 = local_c8;
  uVar19 = local_cc;
  (*(code *)PTR_memmove_006a9af4)(&local_cc,&local_c4,0x18);
  uVar3 = local_88;
  uVar16 = local_8c;
  uVar5 = local_c8 ^ uVar5;
  local_b8 = CONCAT13(~local_b8._0_1_,(uint3)local_b8 & 0xffff00 | (uint3)(byte)~(byte)local_b8);
  local_bc._1_3_ = CONCAT12(~local_bc._1_1_,CONCAT11(~local_bc._2_1_,(undefined)local_bc));
  local_bc = local_bc & 0xff000000 | (uint)local_bc._1_3_;
  local_c0._2_2_ = CONCAT11(~local_c0._2_1_,(undefined)local_c0);
  local_c0 = CONCAT13(~local_c0._0_1_,(uint3)local_c0 & 0xff0000 | (uint3)local_c0._2_2_);
  local_c4._2_2_ = CONCAT11(~local_c4._2_1_,(undefined)local_c4);
  local_c4 = CONCAT13(~local_c4._0_1_,(uint3)local_c4 & 0xff0000 | (uint3)local_c4._2_2_);
  local_b0 = CONCAT13(~(byte)(uVar5 >> 0x18),
                      CONCAT12(~(byte)(uVar5 >> 0x10),
                               (ushort)uVar5 & 0xff00 | (ushort)(byte)~(byte)uVar5));
  local_b4 = (uVar19 ^ local_cc) & 0xffffff |
             (uint)(byte)~(byte)((uVar19 ^ local_cc) >> 0x18) << 0x18;
  local_c8._1_3_ =
       CONCAT12(~local_c8._1_1_,(ushort)local_c8 & 0xff00 | (ushort)(byte)~(byte)local_c8);
  local_c8 = local_c8 & 0xff000000 | (uint)local_c8._1_3_;
  local_cc._1_3_ =
       CONCAT12(~local_cc._1_1_,(ushort)local_cc & 0xff00 | (ushort)(byte)~(byte)local_cc);
  local_cc = local_cc & 0xff000000 | (uint)local_cc._1_3_;
  (*(code *)PTR_memmove_006a9af4)(&local_8c,&local_84,0x18);
  uVar5 = local_88;
  uVar19 = local_8c;
  local_74 = local_8c ^ uVar16;
  local_70 = local_88 ^ uVar3;
  (*(code *)PTR_memmove_006a9af4)(&local_8c,&local_84,0x18);
  local_74 = local_8c ^ uVar19;
  local_ac = local_8c ^ local_cc;
  local_70 = local_88 ^ uVar5;
  local_a8 = local_88 ^ local_c8;
  local_a4 = local_c4 ^ local_84;
  local_a0 = local_80 ^ local_c0;
  local_9c = local_7c ^ local_bc;
  local_3b = (undefined)(local_a0 >> 0x18);
  local_98 = local_78 ^ local_b8;
  local_37 = (undefined)(local_a0 >> 0x10);
  local_94 = local_74 ^ local_b4;
  local_90 = local_70 ^ local_b0;
  local_33 = (undefined)(local_a0 >> 8);
  local_44 = (undefined)(local_ac >> 8);
  local_3f = (undefined)local_a4;
  local_4a = (undefined)(local_9c >> 0x18);
  local_48 = (undefined)(local_ac >> 0x10);
  local_2f = (undefined)local_a0;
  local_3e = (undefined)local_9c;
  uStack_e9 = (undefined)(local_98 >> 0x18);
  local_42 = (undefined)(local_9c >> 8);
  local_3a = uStack_e9;
  uStack_e1 = (undefined)(local_98 >> 0x10);
  local_4c = (undefined)(local_ac >> 0x18);
  local_40 = (undefined)local_ac;
  local_3c = (undefined)(local_a8 >> 0x18);
  local_38 = (undefined)(local_a8 >> 0x10);
  local_30 = (undefined)local_a8;
  local_34 = (undefined)(local_a8 >> 8);
  local_4b = (undefined)(local_a4 >> 0x18);
  local_47 = (undefined)(local_a4 >> 0x10);
  local_43 = (undefined)(local_a4 >> 8);
  local_46 = (undefined)(local_9c >> 0x10);
  local_36 = uStack_e1;
  local_31 = (undefined)(local_90 >> 8);
  local_32 = (undefined)(local_98 >> 8);
  local_2e = (undefined)local_98;
  local_45 = (undefined)(local_94 >> 0x10);
  local_3d = (undefined)local_94;
  local_39 = (undefined)(local_90 >> 0x18);
  local_35 = (undefined)(local_90 >> 0x10);
  local_2d = (undefined)local_90;
  local_49 = (undefined)(local_94 >> 0x18);
  local_41 = (undefined)(local_94 >> 8);
  (*(code *)PTR_gost_enc_with_key_006a98b4)(param_1,&local_4c,param_2 + 4,&local_5c);
  uVar16 = local_c8;
  uVar19 = local_cc;
  (*(code *)PTR_memmove_006a9af4)(&local_cc,&local_c4,0x18);
  uVar18 = local_88;
  uVar14 = local_8c;
  uVar3 = local_c8;
  uVar5 = local_cc;
  uVar16 = local_c8 ^ uVar16;
  uVar19 = local_cc ^ uVar19;
  local_b4 = uVar19;
  local_b0 = uVar16;
  (*(code *)PTR_memmove_006a9af4)(&local_8c,&local_84,0x18);
  uVar13 = local_88;
  uVar15 = local_8c;
  local_74 = local_8c ^ uVar14;
  local_70 = local_88 ^ uVar18;
  (*(code *)PTR_memmove_006a9af4)(&local_8c,&local_84,0x18);
  local_a0 = local_c0 ^ local_80;
  local_74 = local_8c ^ uVar15;
  local_ac = uVar5 ^ local_8c;
  local_a8 = local_88 ^ uVar3;
  local_70 = local_88 ^ uVar13;
  local_94 = uVar19 ^ local_74;
  local_9c = local_7c ^ local_bc;
  local_a4 = local_84 ^ local_c4;
  local_90 = local_70 ^ uVar16;
  local_37 = (undefined)(local_a0 >> 0x10);
  local_98 = local_b8 ^ local_78;
  local_4c = (undefined)(local_ac >> 0x18);
  local_48 = (undefined)(local_ac >> 0x10);
  local_44 = (undefined)(local_ac >> 8);
  local_46 = (undefined)(local_9c >> 0x10);
  local_40 = (undefined)local_ac;
  local_3c = (undefined)(local_a8 >> 0x18);
  local_38 = (undefined)(local_a8 >> 0x10);
  local_2f = (undefined)local_a0;
  local_34 = (undefined)(local_a8 >> 8);
  local_30 = (undefined)local_a8;
  local_4b = (undefined)(local_a4 >> 0x18);
  local_47 = (undefined)(local_a4 >> 0x10);
  local_43 = (undefined)(local_a4 >> 8);
  local_3f = (undefined)local_a4;
  local_3a = (undefined)(local_98 >> 0x18);
  local_32 = (undefined)(local_98 >> 8);
  local_31 = (undefined)(local_90 >> 8);
  iVar17 = 0xc;
  local_2d = (undefined)local_90;
  local_3b = (undefined)(local_a0 >> 0x18);
  local_33 = (undefined)(local_a0 >> 8);
  local_4a = (undefined)(local_9c >> 0x18);
  local_42 = (undefined)(local_9c >> 8);
  local_3e = (undefined)local_9c;
  local_36 = (undefined)(local_98 >> 0x10);
  local_2e = (undefined)local_98;
  local_49 = (undefined)(local_94 >> 0x18);
  local_45 = (undefined)(local_94 >> 0x10);
  local_41 = (undefined)(local_94 >> 8);
  local_3d = (undefined)local_94;
  local_39 = (undefined)(local_90 >> 0x18);
  local_35 = (undefined)(local_90 >> 0x10);
  (*(code *)PTR_gost_enc_with_key_006a98b4)(param_1,&local_4c,param_2 + 6,&local_54);
  uVar5 = local_50 >> 8 & 0xff;
  uVar19 = local_50 & 0xff;
  do {
    iVar17 = iVar17 + -1;
    (*(code *)PTR_memmove_006a9af4)(&local_6c,iVar10,0x1e);
    uVar16 = (uint)(short)((ushort)((uVar19 ^ (byte)(local_6c._1_1_ ^ (byte)local_6c ^
                                                     local_68._1_1_ ^ (byte)local_68 ^
                                                    local_54._1_1_)) << 8) |
                          (ushort)uVar5 ^
                          (ushort)(byte)(local_6c._0_1_ ^ local_6c._2_1_ ^ local_68._0_1_ ^
                                         local_68._2_1_ ^ local_54._0_1_));
    uVar19 = (uVar16 << 0x10) >> 0x18;
    uVar5 = uVar16 & 0xff;
    local_50 = local_50 & 0xffff0000 | (uint)CONCAT11((char)uVar5,(char)(uVar16 >> 8));
  } while (iVar17 != 0);
  puVar8 = &local_6c;
  if (((uint)param_3 & 3) == 0) {
    local_6c = *param_3 ^ local_6c;
    local_60 = param_3[3] ^ local_60;
    local_68 = param_3[1] ^ local_68;
    local_5c = param_3[4] ^ local_5c;
    local_64 = param_3[2] ^ local_64;
    local_58 = param_3[5] ^ local_58;
    local_54 = param_3[6] ^ local_54;
    local_50 = local_50 ^ param_3[7];
  }
  else {
    do {
      puVar9 = (undefined4 *)((int)puVar8 + 1);
      bVar2 = *(byte *)param_3;
      param_3 = (uint *)((int)param_3 + 1);
      *(byte *)puVar8 = bVar2 ^ *(byte *)puVar8;
      puVar8 = puVar9;
    } while ((undefined4 *)&local_4c != puVar9);
  }
  (*(code *)PTR_memmove_006a9af4)(&local_6c,iVar10,0x1e);
  local_50 = CONCAT31(CONCAT21(local_50._0_2_,
                               local_6c._0_1_ ^ local_6c._2_1_ ^ local_68._0_1_ ^ local_68._2_1_ ^
                               local_54._0_1_ ^ local_50._2_1_),
                      local_6c._1_1_ ^ (byte)local_6c ^ local_68._1_1_ ^ (byte)local_68 ^
                      local_54._1_1_ ^ (byte)local_50);
  puVar8 = &local_6c;
  puVar6 = param_2;
  if (((uint)param_2 & 3) == 0) {
    local_68 = param_2[1] ^ local_68;
    local_6c = *param_2 ^ local_6c;
    local_60 = param_2[3] ^ local_60;
    local_64 = local_64 ^ param_2[2];
    local_5c = local_5c ^ param_2[4];
    local_54 = param_2[6] ^ local_54;
    local_58 = local_58 ^ param_2[5];
    local_50 = local_50 ^ param_2[7];
  }
  else {
    do {
      puVar9 = (undefined4 *)((int)puVar8 + 1);
      *(byte *)puVar8 = *(byte *)puVar6 ^ *(byte *)puVar8;
      puVar8 = puVar9;
      puVar6 = (uint *)((int)puVar6 + 1);
    } while ((undefined4 *)&local_4c != puVar9);
  }
  uVar5 = local_50 >> 8 & 0xff;
  iVar17 = 0x3d;
  uVar19 = local_50 & 0xff;
  do {
    iVar17 = iVar17 + -1;
    (*(code *)PTR_memmove_006a9af4)(&local_6c,iVar10,0x1e);
    uVar16 = (uint)(short)((ushort)((uVar19 ^ (byte)(local_6c._1_1_ ^ (byte)local_6c ^
                                                     local_68._1_1_ ^ (byte)local_68 ^
                                                    local_54._1_1_)) << 8) |
                          (ushort)uVar5 ^
                          (ushort)(byte)(local_6c._0_1_ ^ local_6c._2_1_ ^ local_68._0_1_ ^
                                         local_68._2_1_ ^ local_54._0_1_));
    uVar19 = (uVar16 << 0x10) >> 0x18;
    uVar5 = uVar16 & 0xff;
    local_50 = local_50 & 0xffff0000 | (uint)CONCAT11((char)uVar5,(char)(uVar16 >> 8));
  } while (iVar17 != 0);
  *param_2 = local_6c;
  param_2[1] = local_68;
  param_2[2] = local_64;
  param_2[3] = local_60;
  param_2[4] = local_5c;
  param_2[5] = local_58;
  param_2[6] = local_54;
  param_2[7] = local_50;
  if (local_2c != *(int *)puVar4) {
    iVar10 = local_2c;
    uVar19 = local_58;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    (*(code *)PTR_memset_006a99f4)();
    iVar17 = (*(code *)PTR_malloc_006a9a58)(0x1020);
    *(int *)(iVar10 + 8) = iVar17;
    if (iVar17 == 0) {
      return 0;
    }
    gost_init(iVar17,uVar19);
    return 1;
  }
  return 1;
}

