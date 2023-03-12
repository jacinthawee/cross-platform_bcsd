
/* WARNING: Could not reconcile some variable overlaps */

void whirlpool_block(uint *param_1,uint *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  int iVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  int iVar42;
  int iVar43;
  int iVar44;
  int iVar45;
  int iVar46;
  int iVar47;
  int iVar48;
  int iVar49;
  int iVar50;
  int iVar51;
  int iVar52;
  int iVar53;
  int iVar54;
  int iVar55;
  int iVar56;
  int iVar57;
  int iVar58;
  int iVar59;
  int iVar60;
  int iVar61;
  int iVar62;
  int iVar63;
  int iVar64;
  int iVar65;
  int iVar66;
  int iVar67;
  int iVar68;
  int iVar69;
  int iVar70;
  int iVar71;
  int iVar72;
  int iVar73;
  int iVar74;
  int iVar75;
  int iVar76;
  int iVar77;
  int iVar78;
  int iVar79;
  int iVar80;
  int iVar81;
  int iVar82;
  int iVar83;
  int iVar84;
  int iVar85;
  int iVar86;
  int iVar87;
  int iVar88;
  int iVar89;
  int iVar90;
  int iVar91;
  int iVar92;
  int iVar93;
  int iVar94;
  int iVar95;
  int iVar96;
  int iVar97;
  int iVar98;
  int iVar99;
  int iVar100;
  int iVar101;
  int iVar102;
  int iVar103;
  int iVar104;
  int iVar105;
  int iVar106;
  int iVar107;
  int iVar108;
  int iVar109;
  int iVar110;
  int iVar111;
  int iVar112;
  int iVar113;
  int iVar114;
  int iVar115;
  uint uVar116;
  uint uVar117;
  uint uVar118;
  uint uVar119;
  uint uVar120;
  uint uVar121;
  uint uVar122;
  uint uVar123;
  uint uVar124;
  uint uVar125;
  uint uVar126;
  uint uVar127;
  uint uVar128;
  uint uVar129;
  uint uVar130;
  uint uVar131;
  int iVar132;
  uint uVar133;
  uint *puVar134;
  uint *puVar135;
  uint *puVar136;
  uint *local_140;
  uint *local_110;
  uint *local_104;
  int local_c0;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_2c;
  
  local_104 = param_2 + 1;
  local_2c = __TMC_END__;
  local_110 = param_2;
  local_c0 = param_3;
  do {
    if (((uint)local_110 & 7) == 0) {
      local_68 = param_1[2];
      local_64 = param_1[3];
      local_70 = *param_1;
      local_6c = param_1[1];
      local_60 = param_1[4];
      local_5c = param_1[5];
      local_ac = *local_104 ^ local_6c;
      local_b0 = local_104[-1] ^ local_70;
      local_58 = param_1[6];
      local_54 = param_1[7];
      local_a4 = local_110[3] ^ local_64;
      local_a8 = local_110[2] ^ local_68;
      local_50 = param_1[8];
      local_4c = param_1[9];
      local_9c = local_110[5] ^ local_5c;
      local_a0 = local_110[4] ^ local_60;
      local_94 = local_110[7] ^ local_54;
      local_98 = local_110[6] ^ local_58;
      local_48 = param_1[10];
      local_44 = param_1[0xb];
      local_90 = local_110[8] ^ local_50;
      local_8c = local_110[9] ^ local_4c;
      local_40 = param_1[0xc];
      local_3c = param_1[0xd];
      local_84 = local_110[0xb] ^ local_44;
      local_88 = local_110[10] ^ local_48;
      local_80 = local_110[0xc] ^ local_40;
      local_7c = local_110[0xd] ^ local_3c;
      local_38 = param_1[0xe];
      local_34 = param_1[0xf];
      local_78 = local_110[0xe] ^ local_38;
      local_74 = local_110[0xf] ^ local_34;
    }
    else {
      puVar134 = local_104 + -1;
      puVar136 = &local_b0;
      do {
        puVar135 = puVar134 + 4;
        uVar129 = puVar134[1];
        uVar130 = puVar134[2];
        uVar131 = puVar134[3];
        *puVar136 = *puVar134;
        puVar136[1] = uVar129;
        puVar136[2] = uVar130;
        puVar136[3] = uVar131;
        puVar134 = puVar135;
        puVar136 = puVar136 + 4;
      } while (puVar135 != local_104 + 0xf);
      local_68 = param_1[2];
      local_64 = param_1[3];
      local_70 = *param_1;
      local_6c = param_1[1];
      local_60 = param_1[4];
      local_5c = param_1[5];
      local_48 = param_1[10];
      local_44 = param_1[0xb];
      local_58 = param_1[6];
      local_54 = param_1[7];
      local_50 = param_1[8];
      local_4c = param_1[9];
      local_40 = param_1[0xc];
      local_3c = param_1[0xd];
      local_38 = param_1[0xe];
      local_34 = param_1[0xf];
      local_b0 = local_70 ^ local_b0;
      local_ac = local_6c ^ local_ac;
      local_a8 = local_68 ^ local_a8;
      local_a4 = local_64 ^ local_a4;
      local_a0 = local_60 ^ local_a0;
      local_9c = local_5c ^ local_9c;
      local_98 = local_58 ^ local_98;
      local_94 = local_54 ^ local_94;
      local_90 = local_50 ^ local_90;
      local_8c = local_4c ^ local_8c;
      local_88 = local_48 ^ local_88;
      local_84 = local_44 ^ local_84;
      local_80 = local_40 ^ local_80;
      local_7c = local_3c ^ local_7c;
      local_78 = local_38 ^ local_78;
      local_74 = local_34 ^ local_74;
    }
    uVar128 = local_34;
    uVar127 = local_38;
    uVar126 = local_3c;
    uVar125 = local_40;
    uVar124 = local_44;
    uVar123 = local_48;
    uVar122 = local_4c;
    uVar121 = local_50;
    uVar120 = local_54;
    uVar119 = local_58;
    uVar118 = local_5c;
    uVar117 = local_60;
    uVar116 = local_64;
    uVar131 = local_68;
    uVar130 = local_6c;
    uVar129 = local_70;
    local_140 = (uint *)PTR_DAT_000764ac;
    do {
      iVar132 = ((short)(ushort)local_54._1_1_ * 8 + 5) * 8;
      iVar1 = ((short)(ushort)(byte)local_4c * 8 + 4) * 8;
      iVar2 = ((short)(ushort)local_48._3_1_ * 8 + 3) * 8;
      iVar3 = ((short)(ushort)local_40._2_1_ * 8 + 2) * 8;
      iVar4 = (local_70 & 0xff) * 0x40;
      iVar5 = ((short)(ushort)local_64._3_1_ * 8 + 7) * 8;
      puVar134 = local_140 + 2;
      iVar6 = ((short)(ushort)local_5c._2_1_ * 8 + 6) * 8;
      iVar7 = ((short)(ushort)local_70._1_1_ * 8 + 1) * 8;
      iVar8 = ((short)(ushort)local_38._1_1_ * 8 + 1) * 8;
      iVar9 = ((short)(ushort)local_70._2_1_ * 8 + 2) * 8;
      iVar10 = ((short)(ushort)local_70._3_1_ * 8 + 3) * 8;
      iVar11 = ((short)((ushort)local_6c & 0xff) * 8 + 4) * 8;
      iVar12 = ((short)(ushort)local_6c._1_1_ * 8 + 5) * 8;
      iVar13 = ((short)(ushort)local_6c._2_1_ * 8 + 6) * 8;
      iVar14 = ((short)(ushort)local_60._1_1_ * 8 + 1) * 8;
      iVar15 = ((short)(ushort)local_60._2_1_ * 8 + 2) * 8;
      iVar16 = ((short)(ushort)local_60._3_1_ * 8 + 3) * 8;
      iVar17 = ((short)(ushort)local_6c._3_1_ * 8 + 7) * 8;
      iVar18 = ((short)(ushort)local_5c._1_1_ * 8 + 5) * 8;
      iVar19 = ((short)((ushort)local_5c & 0xff) * 8 + 4) * 8;
      iVar20 = ((short)(ushort)local_58._1_1_ * 8 + 1) * 8;
      iVar21 = ((short)(ushort)local_68._1_1_ * 8 + 1) * 8;
      iVar22 = ((short)(ushort)local_5c._3_1_ * 8 + 7) * 8;
      iVar23 = ((short)(ushort)local_58._2_1_ * 8 + 2) * 8;
      iVar24 = ((short)(ushort)local_58._3_1_ * 8 + 3) * 8;
      iVar25 = ((short)(ushort)local_68._2_1_ * 8 + 2) * 8;
      iVar26 = ((short)(ushort)local_68._3_1_ * 8 + 3) * 8;
      iVar27 = ((short)((ushort)local_64 & 0xff) * 8 + 4) * 8;
      iVar28 = ((short)(ushort)local_64._1_1_ * 8 + 5) * 8;
      iVar29 = ((short)(ushort)local_64._2_1_ * 8 + 6) * 8;
      iVar30 = ((short)(ushort)local_4c._1_1_ * 8 + 5) * 8;
      iVar31 = ((short)((ushort)local_54 & 0xff) * 8 + 4) * 8;
      iVar32 = ((short)(ushort)local_54._3_1_ * 8 + 7) * 8;
      iVar33 = ((short)(ushort)local_50._1_1_ * 8 + 1) * 8;
      iVar34 = ((short)(ushort)local_54._2_1_ * 8 + 6) * 8;
      iVar35 = ((short)(ushort)local_50._3_1_ * 8 + 3) * 8;
      iVar36 = ((short)(ushort)local_48._1_1_ * 8 + 1) * 8;
      iVar37 = ((short)(ushort)local_4c._3_1_ * 8 + 7) * 8;
      iVar38 = ((short)(ushort)local_38._2_1_ * 8 + 2) * 8;
      iVar39 = ((short)(ushort)local_4c._2_1_ * 8 + 6) * 8;
      iVar40 = ((short)(ushort)local_50._2_1_ * 8 + 2) * 8;
      iVar41 = ((short)(ushort)local_48._2_1_ * 8 + 2) * 8;
      iVar42 = ((short)(ushort)local_38._3_1_ * 8 + 3) * 8;
      iVar43 = ((short)(ushort)local_44._2_1_ * 8 + 6) * 8;
      iVar44 = ((short)(ushort)local_44._1_1_ * 8 + 5) * 8;
      iVar45 = ((short)(ushort)local_3c._3_1_ * 8 + 7) * 8;
      iVar46 = ((short)(ushort)local_34._3_1_ * 8 + 7) * 8;
      iVar47 = ((short)(ushort)local_34._1_1_ * 8 + 5) * 8;
      iVar48 = ((short)((ushort)local_44 & 0xff) * 8 + 4) * 8;
      iVar49 = ((short)(ushort)local_44._3_1_ * 8 + 7) * 8;
      iVar50 = ((short)((ushort)local_34 & 0xff) * 8 + 4) * 8;
      iVar51 = (local_68 & 0xff) * 0x40;
      iVar52 = ((short)(ushort)local_34._2_1_ * 8 + 6) * 8;
      iVar53 = (local_58 & 0xff) * 0x40;
      iVar54 = (local_50 & 0xff) * 0x40;
      iVar55 = ((short)(ushort)local_40._1_1_ * 8 + 1) * 8;
      iVar56 = (local_60 & 0xff) * 0x40;
      iVar57 = ((short)(ushort)local_40._3_1_ * 8 + 3) * 8;
      iVar58 = ((short)((ushort)local_3c & 0xff) * 8 + 4) * 8;
      iVar59 = ((short)(ushort)local_3c._1_1_ * 8 + 5) * 8;
      iVar60 = ((short)(ushort)local_3c._2_1_ * 8 + 6) * 8;
      local_70 = *(uint *)(&Cx + iVar8) ^
                 *(uint *)(&Cx + iVar2) ^
                 *(uint *)(&Cx + iVar6) ^
                 *(uint *)(&Cx + iVar4) ^ *puVar134 ^ *(uint *)(&Cx + iVar5) ^
                 *(uint *)(&Cx + iVar132) ^ *(uint *)(&Cx + iVar1) ^ *(uint *)(&Cx + iVar3);
      local_6c = *(uint *)(&DAT_0014fa04 + iVar8) ^
                 *(uint *)(&DAT_0014fa04 + iVar2) ^
                 *(uint *)(&DAT_0014fa04 + iVar6) ^
                 *(uint *)(&DAT_0014fa04 + iVar4) ^ local_140[3] ^ *(uint *)(&DAT_0014fa04 + iVar5)
                 ^ *(uint *)(&DAT_0014fa04 + iVar132) ^ *(uint *)(&DAT_0014fa04 + iVar1) ^
                 *(uint *)(&DAT_0014fa04 + iVar3);
      iVar132 = (local_48 & 0xff) * 0x40;
      iVar1 = (local_40 & 0xff) * 0x40;
      iVar2 = (local_38 & 0xff) * 0x40;
      iVar3 = ((short)(ushort)local_9c._2_1_ * 8 + 6) * 8;
      iVar4 = ((short)(ushort)local_a4._3_1_ * 8 + 7) * 8;
      iVar5 = ((short)(ushort)local_a4._2_1_ * 8 + 6) * 8;
      iVar6 = ((short)(ushort)local_ac._3_1_ * 8 + 7) * 8;
      iVar8 = ((short)(ushort)local_9c._3_1_ * 8 + 7) * 8;
      iVar61 = ((short)(ushort)local_b0._1_1_ * 8 + 1) * 8;
      iVar62 = ((short)(ushort)local_a8._1_1_ * 8 + 1) * 8;
      iVar63 = ((short)(ushort)local_b0._2_1_ * 8 + 2) * 8;
      iVar64 = ((short)(ushort)local_b0._3_1_ * 8 + 3) * 8;
      iVar65 = ((short)(ushort)local_a8._2_1_ * 8 + 2) * 8;
      iVar66 = ((short)((ushort)local_ac & 0xff) * 8 + 4) * 8;
      iVar67 = ((short)(ushort)local_a8._3_1_ * 8 + 3) * 8;
      iVar68 = ((short)(ushort)local_ac._1_1_ * 8 + 5) * 8;
      iVar69 = ((short)((ushort)local_a4 & 0xff) * 8 + 4) * 8;
      iVar70 = ((short)(ushort)local_a4._1_1_ * 8 + 5) * 8;
      iVar71 = ((short)(ushort)local_ac._2_1_ * 8 + 6) * 8;
      iVar72 = ((short)(ushort)local_9c._1_1_ * 8 + 5) * 8;
      iVar73 = ((short)(ushort)local_78._1_1_ * 8 + 1) * 8;
      iVar74 = ((short)(ushort)local_94._2_1_ * 8 + 6) * 8;
      iVar75 = ((short)(ushort)local_80._1_1_ * 8 + 1) * 8;
      iVar76 = ((short)(ushort)local_94._1_1_ * 8 + 5) * 8;
      iVar77 = ((short)(ushort)local_94._3_1_ * 8 + 7) * 8;
      iVar78 = ((short)(ushort)local_88._1_1_ * 8 + 1) * 8;
      iVar79 = ((short)(ushort)local_a0._1_1_ * 8 + 1) * 8;
      iVar80 = ((short)(ushort)local_78._2_1_ * 8 + 2) * 8;
      iVar81 = ((short)(ushort)local_a0._3_1_ * 8 + 3) * 8;
      iVar82 = ((short)(ushort)local_a0._2_1_ * 8 + 2) * 8;
      iVar83 = ((short)(ushort)local_78._3_1_ * 8 + 3) * 8;
      iVar84 = ((short)((ushort)local_9c & 0xff) * 8 + 4) * 8;
      iVar85 = ((short)(ushort)(byte)local_74 * 8 + 4) * 8;
      iVar86 = ((short)(ushort)local_74._1_1_ * 8 + 5) * 8;
      iVar87 = ((short)(ushort)local_74._2_1_ * 8 + 6) * 8;
      iVar88 = ((short)(ushort)(byte)local_8c * 8 + 4) * 8;
      iVar89 = (local_b0 & 0xff) * 0x40;
      iVar90 = ((short)(ushort)local_74._3_1_ * 8 + 7) * 8;
      iVar91 = ((short)(ushort)(byte)local_94 * 8 + 4) * 8;
      iVar92 = ((short)(ushort)local_98._1_1_ * 8 + 1) * 8;
      iVar93 = ((short)(ushort)local_8c._1_1_ * 8 + 5) * 8;
      iVar94 = ((short)(ushort)local_98._3_1_ * 8 + 3) * 8;
      iVar95 = ((short)(ushort)local_8c._2_1_ * 8 + 6) * 8;
      iVar96 = (local_78 & 0xff) * 0x40;
      iVar97 = ((short)(ushort)local_8c._3_1_ * 8 + 7) * 8;
      iVar98 = ((short)(ushort)local_98._2_1_ * 8 + 2) * 8;
      iVar99 = ((short)(ushort)local_88._3_1_ * 8 + 3) * 8;
      iVar100 = ((short)(ushort)local_90._3_1_ * 8 + 3) * 8;
      iVar101 = ((short)((ushort)local_84 & 0xff) * 8 + 4) * 8;
      iVar102 = ((short)(ushort)local_84._1_1_ * 8 + 5) * 8;
      iVar103 = ((short)(ushort)local_84._2_1_ * 8 + 6) * 8;
      iVar104 = ((short)(ushort)local_90._1_1_ * 8 + 1) * 8;
      iVar105 = ((short)(ushort)local_84._3_1_ * 8 + 7) * 8;
      iVar106 = ((short)(ushort)local_80._2_1_ * 8 + 2) * 8;
      iVar107 = ((short)(ushort)local_90._2_1_ * 8 + 2) * 8;
      iVar108 = ((short)(ushort)local_88._2_1_ * 8 + 2) * 8;
      iVar109 = (local_a8 & 0xff) * 0x40;
      iVar110 = ((short)(ushort)local_80._3_1_ * 8 + 3) * 8;
      iVar111 = ((short)(ushort)local_7c._2_1_ * 8 + 6) * 8;
      iVar112 = ((short)((ushort)local_7c & 0xff) * 8 + 4) * 8;
      iVar113 = ((short)(ushort)local_7c._1_1_ * 8 + 5) * 8;
      iVar114 = ((short)(ushort)local_7c._3_1_ * 8 + 7) * 8;
      iVar115 = (local_a0 & 0xff) * 0x40;
      local_60 = *(uint *)(&Cx + iVar39) ^
                 *(uint *)(&Cx + iVar9) ^ *(uint *)(&Cx + iVar21) ^ *(uint *)(&Cx + iVar56) ^
                 *(uint *)(&Cx + iVar32) ^ *(uint *)(&Cx + iVar44) ^ *(uint *)(&Cx + iVar58) ^
                 *(uint *)(&Cx + iVar42);
      local_5c = *(uint *)(&DAT_0014fa04 + iVar39) ^
                 *(uint *)(&DAT_0014fa04 + iVar9) ^ *(uint *)(&DAT_0014fa04 + iVar21) ^
                 *(uint *)(&DAT_0014fa04 + iVar56) ^ *(uint *)(&DAT_0014fa04 + iVar32) ^
                 *(uint *)(&DAT_0014fa04 + iVar44) ^ *(uint *)(&DAT_0014fa04 + iVar58) ^
                 *(uint *)(&DAT_0014fa04 + iVar42);
      iVar9 = (local_98 & 0xff) * 0x40;
      local_64 = *(uint *)(&DAT_0014fa04 + iVar30) ^
                 *(uint *)(&DAT_0014fa04 + iVar7) ^ *(uint *)(&DAT_0014fa04 + iVar22) ^
                 *(uint *)(&DAT_0014fa04 + iVar51) ^ *(uint *)(&DAT_0014fa04 + iVar34) ^
                 *(uint *)(&DAT_0014fa04 + iVar48) ^ *(uint *)(&DAT_0014fa04 + iVar57) ^
                 *(uint *)(&DAT_0014fa04 + iVar38);
      local_68 = *(uint *)(&Cx + iVar30) ^
                 *(uint *)(&Cx + iVar7) ^ *(uint *)(&Cx + iVar22) ^ *(uint *)(&Cx + iVar51) ^
                 *(uint *)(&Cx + iVar34) ^ *(uint *)(&Cx + iVar48) ^ *(uint *)(&Cx + iVar57) ^
                 *(uint *)(&Cx + iVar38);
      iVar7 = (local_80 & 0xff) * 0x40;
      local_54 = *(uint *)(&DAT_0014fa04 + iVar10) ^ *(uint *)(&DAT_0014fa04 + iVar25) ^
                 *(uint *)(&DAT_0014fa04 + iVar53) ^ *(uint *)(&DAT_0014fa04 + iVar14) ^
                 *(uint *)(&DAT_0014fa04 + iVar37) ^ *(uint *)(&DAT_0014fa04 + iVar43) ^
                 *(uint *)(&DAT_0014fa04 + iVar59) ^ *(uint *)(&DAT_0014fa04 + iVar50);
      local_58 = *(uint *)(&Cx + iVar10) ^ *(uint *)(&Cx + iVar25) ^ *(uint *)(&Cx + iVar53) ^
                 *(uint *)(&Cx + iVar14) ^ *(uint *)(&Cx + iVar37) ^ *(uint *)(&Cx + iVar43) ^
                 *(uint *)(&Cx + iVar59) ^ *(uint *)(&Cx + iVar50);
      local_4c = *(uint *)(&DAT_0014fa04 + iVar60) ^
                 *(uint *)(&DAT_0014fa04 + iVar11) ^ *(uint *)(&DAT_0014fa04 + iVar26) ^
                 *(uint *)(&DAT_0014fa04 + iVar54) ^ *(uint *)(&DAT_0014fa04 + iVar15) ^
                 *(uint *)(&DAT_0014fa04 + iVar20) ^ *(uint *)(&DAT_0014fa04 + iVar49) ^
                 *(uint *)(&DAT_0014fa04 + iVar47);
      local_50 = *(uint *)(&Cx + iVar60) ^
                 *(uint *)(&Cx + iVar11) ^ *(uint *)(&Cx + iVar26) ^ *(uint *)(&Cx + iVar54) ^
                 *(uint *)(&Cx + iVar15) ^ *(uint *)(&Cx + iVar20) ^ *(uint *)(&Cx + iVar49) ^
                 *(uint *)(&Cx + iVar47);
      local_48 = *(uint *)(&Cx + iVar52) ^
                 *(uint *)(&Cx + iVar12) ^ *(uint *)(&Cx + iVar27) ^ *(uint *)(&Cx + iVar132) ^
                 *(uint *)(&Cx + iVar16) ^ *(uint *)(&Cx + iVar23) ^ *(uint *)(&Cx + iVar33) ^
                 *(uint *)(&Cx + iVar45);
      local_44 = *(uint *)(&DAT_0014fa04 + iVar52) ^
                 *(uint *)(&DAT_0014fa04 + iVar12) ^ *(uint *)(&DAT_0014fa04 + iVar27) ^
                 *(uint *)(&DAT_0014fa04 + iVar132) ^ *(uint *)(&DAT_0014fa04 + iVar16) ^
                 *(uint *)(&DAT_0014fa04 + iVar23) ^ *(uint *)(&DAT_0014fa04 + iVar33) ^
                 *(uint *)(&DAT_0014fa04 + iVar45);
      local_40 = *(uint *)(&Cx + iVar13) ^ *(uint *)(&Cx + iVar28) ^ *(uint *)(&Cx + iVar1) ^
                 *(uint *)(&Cx + iVar19) ^ *(uint *)(&Cx + iVar24) ^ *(uint *)(&Cx + iVar40) ^
                 *(uint *)(&Cx + iVar36) ^ *(uint *)(&Cx + iVar46);
      local_3c = *(uint *)(&DAT_0014fa04 + iVar13) ^ *(uint *)(&DAT_0014fa04 + iVar28) ^
                 *(uint *)(&DAT_0014fa04 + iVar1) ^ *(uint *)(&DAT_0014fa04 + iVar19) ^
                 *(uint *)(&DAT_0014fa04 + iVar24) ^ *(uint *)(&DAT_0014fa04 + iVar40) ^
                 *(uint *)(&DAT_0014fa04 + iVar36) ^ *(uint *)(&DAT_0014fa04 + iVar46);
      iVar132 = (local_90 & 0xff) * 0x40;
      iVar1 = (local_88 & 0xff) * 0x40;
      local_34 = *(uint *)(&DAT_0014fa04 + iVar35) ^
                 *(uint *)(&DAT_0014fa04 + iVar17) ^ *(uint *)(&DAT_0014fa04 + iVar29) ^
                 *(uint *)(&DAT_0014fa04 + iVar2) ^ *(uint *)(&DAT_0014fa04 + iVar18) ^
                 *(uint *)(&DAT_0014fa04 + iVar31) ^ *(uint *)(&DAT_0014fa04 + iVar41) ^
                 *(uint *)(&DAT_0014fa04 + iVar55);
      local_38 = *(uint *)(&Cx + iVar35) ^
                 *(uint *)(&Cx + iVar17) ^ *(uint *)(&Cx + iVar29) ^ *(uint *)(&Cx + iVar2) ^
                 *(uint *)(&Cx + iVar18) ^ *(uint *)(&Cx + iVar31) ^ *(uint *)(&Cx + iVar41) ^
                 *(uint *)(&Cx + iVar55);
      local_ac = local_6c ^
                 *(uint *)(&DAT_0014fa04 + iVar3) ^ *(uint *)(&DAT_0014fa04 + iVar4) ^
                 *(uint *)(&DAT_0014fa04 + iVar89) ^ *(uint *)(&DAT_0014fa04 + iVar76) ^
                 *(uint *)(&DAT_0014fa04 + iVar88) ^ *(uint *)(&DAT_0014fa04 + iVar99) ^
                 *(uint *)(&DAT_0014fa04 + iVar106) ^ *(uint *)(&DAT_0014fa04 + iVar73);
      local_b0 = local_70 ^
                 *(uint *)(&Cx + iVar3) ^ *(uint *)(&Cx + iVar4) ^ *(uint *)(&Cx + iVar89) ^
                 *(uint *)(&Cx + iVar76) ^ *(uint *)(&Cx + iVar88) ^ *(uint *)(&Cx + iVar99) ^
                 *(uint *)(&Cx + iVar106) ^ *(uint *)(&Cx + iVar73);
      local_78 = *(uint *)(&Cx + iVar5) ^ *(uint *)(&Cx + iVar6) ^ *(uint *)(&Cx + iVar96) ^
                 *(uint *)(&Cx + iVar72) ^ *(uint *)(&Cx + iVar91) ^ *(uint *)(&Cx + iVar100) ^
                 *(uint *)(&Cx + iVar108) ^ *(uint *)(&Cx + iVar75) ^ local_38;
      local_74 = *(uint *)(&DAT_0014fa04 + iVar5) ^ *(uint *)(&DAT_0014fa04 + iVar6) ^
                 *(uint *)(&DAT_0014fa04 + iVar96) ^ *(uint *)(&DAT_0014fa04 + iVar72) ^
                 *(uint *)(&DAT_0014fa04 + iVar91) ^ *(uint *)(&DAT_0014fa04 + iVar100) ^
                 *(uint *)(&DAT_0014fa04 + iVar108) ^ *(uint *)(&DAT_0014fa04 + iVar75) ^ local_34;
      local_a8 = *(uint *)(&Cx + iVar8) ^ *(uint *)(&Cx + iVar61) ^ *(uint *)(&Cx + iVar109) ^
                 *(uint *)(&Cx + iVar74) ^ *(uint *)(&Cx + iVar93) ^ *(uint *)(&Cx + iVar101) ^
                 *(uint *)(&Cx + iVar110) ^ *(uint *)(&Cx + iVar80) ^ local_68;
      local_a4 = *(uint *)(&DAT_0014fa04 + iVar8) ^ *(uint *)(&DAT_0014fa04 + iVar61) ^
                 *(uint *)(&DAT_0014fa04 + iVar109) ^ *(uint *)(&DAT_0014fa04 + iVar74) ^
                 *(uint *)(&DAT_0014fa04 + iVar93) ^ *(uint *)(&DAT_0014fa04 + iVar101) ^
                 *(uint *)(&DAT_0014fa04 + iVar110) ^ *(uint *)(&DAT_0014fa04 + iVar80) ^ local_64;
      local_a0 = *(uint *)(&Cx + iVar63) ^ *(uint *)(&Cx + iVar62) ^ *(uint *)(&Cx + iVar115) ^
                 *(uint *)(&Cx + iVar77) ^ *(uint *)(&Cx + iVar95) ^ *(uint *)(&Cx + iVar102) ^
                 *(uint *)(&Cx + iVar112) ^ *(uint *)(&Cx + iVar83) ^ local_60;
      local_9c = *(uint *)(&DAT_0014fa04 + iVar63) ^ *(uint *)(&DAT_0014fa04 + iVar62) ^
                 *(uint *)(&DAT_0014fa04 + iVar115) ^ *(uint *)(&DAT_0014fa04 + iVar77) ^
                 *(uint *)(&DAT_0014fa04 + iVar95) ^ *(uint *)(&DAT_0014fa04 + iVar102) ^
                 *(uint *)(&DAT_0014fa04 + iVar112) ^ *(uint *)(&DAT_0014fa04 + iVar83) ^ local_5c;
      local_98 = *(uint *)(&Cx + iVar65) ^ *(uint *)(&Cx + iVar64) ^ *(uint *)(&Cx + iVar9) ^
                 *(uint *)(&Cx + iVar79) ^ *(uint *)(&Cx + iVar97) ^ *(uint *)(&Cx + iVar103) ^
                 *(uint *)(&Cx + iVar113) ^ *(uint *)(&Cx + iVar85) ^ local_58;
      local_94 = *(uint *)(&DAT_0014fa04 + iVar65) ^ *(uint *)(&DAT_0014fa04 + iVar64) ^
                 *(uint *)(&DAT_0014fa04 + iVar9) ^ *(uint *)(&DAT_0014fa04 + iVar79) ^
                 *(uint *)(&DAT_0014fa04 + iVar97) ^ *(uint *)(&DAT_0014fa04 + iVar103) ^
                 *(uint *)(&DAT_0014fa04 + iVar113) ^ *(uint *)(&DAT_0014fa04 + iVar85) ^ local_54;
      local_88 = *(uint *)(&Cx + iVar69) ^ *(uint *)(&Cx + iVar68) ^ *(uint *)(&Cx + iVar1) ^
                 *(uint *)(&Cx + iVar81) ^ *(uint *)(&Cx + iVar98) ^ *(uint *)(&Cx + iVar104) ^
                 *(uint *)(&Cx + iVar114) ^ *(uint *)(&Cx + iVar87) ^ local_48;
      local_84 = *(uint *)(&DAT_0014fa04 + iVar69) ^ *(uint *)(&DAT_0014fa04 + iVar68) ^
                 *(uint *)(&DAT_0014fa04 + iVar1) ^ *(uint *)(&DAT_0014fa04 + iVar81) ^
                 *(uint *)(&DAT_0014fa04 + iVar98) ^ *(uint *)(&DAT_0014fa04 + iVar104) ^
                 *(uint *)(&DAT_0014fa04 + iVar114) ^ *(uint *)(&DAT_0014fa04 + iVar87) ^ local_44;
      local_90 = *(uint *)(&Cx + iVar66) ^ *(uint *)(&Cx + iVar67) ^ *(uint *)(&Cx + iVar132) ^
                 *(uint *)(&Cx + iVar82) ^ *(uint *)(&Cx + iVar92) ^ *(uint *)(&Cx + iVar105) ^
                 *(uint *)(&Cx + iVar111) ^ *(uint *)(&Cx + iVar86) ^ local_50;
      local_8c = *(uint *)(&DAT_0014fa04 + iVar66) ^ *(uint *)(&DAT_0014fa04 + iVar67) ^
                 *(uint *)(&DAT_0014fa04 + iVar132) ^ *(uint *)(&DAT_0014fa04 + iVar82) ^
                 *(uint *)(&DAT_0014fa04 + iVar92) ^ *(uint *)(&DAT_0014fa04 + iVar105) ^
                 *(uint *)(&DAT_0014fa04 + iVar111) ^ *(uint *)(&DAT_0014fa04 + iVar86) ^ local_4c;
      local_80 = *(uint *)(&Cx + iVar71) ^ *(uint *)(&Cx + iVar70) ^ *(uint *)(&Cx + iVar7) ^
                 *(uint *)(&Cx + iVar84) ^ *(uint *)(&Cx + iVar94) ^ *(uint *)(&Cx + iVar107) ^
                 *(uint *)(&Cx + iVar78) ^ *(uint *)(&Cx + iVar90) ^ local_40;
      local_7c = *(uint *)(&DAT_0014fa04 + iVar71) ^ *(uint *)(&DAT_0014fa04 + iVar70) ^
                 *(uint *)(&DAT_0014fa04 + iVar7) ^ *(uint *)(&DAT_0014fa04 + iVar84) ^
                 *(uint *)(&DAT_0014fa04 + iVar94) ^ *(uint *)(&DAT_0014fa04 + iVar107) ^
                 *(uint *)(&DAT_0014fa04 + iVar78) ^ *(uint *)(&DAT_0014fa04 + iVar90) ^ local_3c;
      local_140 = puVar134;
    } while (puVar134 != (uint *)&DAT_00153a48);
    if (((uint)local_110 & 7) == 0) {
      uVar133 = *local_104;
      *param_1 = local_104[-1] ^ uVar129 ^ local_b0;
      param_1[1] = uVar133 ^ uVar130 ^ local_ac;
      uVar129 = local_110[3];
      param_1[2] = local_110[2] ^ uVar131 ^ local_a8;
      param_1[3] = uVar129 ^ uVar116 ^ local_a4;
      uVar129 = local_110[5];
      param_1[4] = local_110[4] ^ uVar117 ^ local_a0;
      param_1[5] = uVar129 ^ uVar118 ^ local_9c;
      uVar129 = local_110[7];
      param_1[6] = local_110[6] ^ uVar119 ^ local_98;
      param_1[7] = uVar129 ^ uVar120 ^ local_94;
      uVar129 = local_110[9];
      param_1[8] = local_110[8] ^ uVar121 ^ local_90;
      param_1[9] = uVar129 ^ uVar122 ^ local_8c;
      uVar129 = local_110[0xb];
      param_1[10] = local_110[10] ^ uVar123 ^ local_88;
      param_1[0xb] = uVar129 ^ uVar124 ^ local_84;
      uVar129 = local_110[0xd];
      param_1[0xc] = local_110[0xc] ^ uVar125 ^ local_80;
      param_1[0xd] = uVar129 ^ uVar126 ^ local_7c;
      uVar129 = local_110[0xf];
      param_1[0xe] = local_110[0xe] ^ uVar127 ^ local_78;
      param_1[0xf] = uVar129 ^ uVar128 ^ local_74;
    }
    else {
      uVar129 = (uint)((param_1 + 1 <= local_110 || local_104 <= param_1) &&
                      ((uint)local_110 & 3) == 0);
      if (uVar129 == 0) {
        do {
          *(byte *)((int)param_1 + uVar129) =
               *(byte *)((int)local_110 + uVar129) ^ *(byte *)((int)&local_b0 + uVar129) ^
               *(byte *)((int)param_1 + uVar129);
          uVar129 = uVar129 + 1;
        } while (uVar129 != 0x40);
      }
      else {
        iVar132 = 0;
        do {
          *(uint *)((int)param_1 + iVar132) =
               *(uint *)((int)local_110 + iVar132) ^
               *(uint *)((int)param_1 + iVar132) ^ *(uint *)((int)&local_b0 + iVar132);
          iVar132 = iVar132 + 4;
        } while (iVar132 != 0x40);
      }
    }
    local_110 = local_110 + 0x10;
    local_c0 = local_c0 + -1;
    local_104 = local_104 + 0x10;
  } while (local_c0 != 0);
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

