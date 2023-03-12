
void whirlpool_block(uint *param_1,uint *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  undefined *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint *puVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  uint *puVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  uint uVar37;
  int iVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  int iVar42;
  int iVar43;
  byte *pbVar44;
  uint uVar45;
  uint uVar46;
  int iVar47;
  int iVar48;
  int iVar49;
  int iVar50;
  int iVar51;
  int iVar52;
  uint uVar53;
  int iVar54;
  int iVar55;
  int iVar56;
  int iVar57;
  uint *puVar58;
  uint uVar59;
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
  int local_res8;
  uint *local_110;
  uint *local_10c;
  uint *local_c0;
  uint local_b0 [7];
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_2c;
  
  puVar8 = PTR___stack_chk_guard_006a9ae8;
  local_c0 = (uint *)(Cx + 0x4000);
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_res8 = param_3;
  local_110 = param_2;
  do {
    if (((uint)local_110 & 7) == 0) {
      local_68 = param_1[2];
      local_70 = *param_1;
      local_54 = param_1[7];
      local_64 = param_1[3];
      local_60 = param_1[4];
      local_b0[0] = *local_110 ^ local_70;
      local_5c = param_1[5];
      local_b0[2] = local_110[2] ^ local_68;
      local_6c = param_1[1];
      local_b0[1] = local_110[1] ^ local_6c;
      local_58 = param_1[6];
      local_b0[3] = local_110[3] ^ local_64;
      local_b0[5] = local_110[5] ^ local_5c;
      local_b0[6] = local_110[6] ^ local_58;
      local_b0[4] = local_110[4] ^ local_60;
      local_94 = local_110[7] ^ local_54;
      local_50 = param_1[8];
      local_4c = param_1[9];
      local_90 = local_110[8] ^ local_50;
      local_48 = param_1[10];
      local_8c = local_110[9] ^ local_4c;
      local_88 = local_110[10] ^ local_48;
      local_44 = param_1[0xb];
      local_84 = local_110[0xb] ^ local_44;
      local_40 = param_1[0xc];
      local_3c = param_1[0xd];
      local_38 = param_1[0xe];
      local_34 = param_1[0xf];
      local_80 = local_110[0xc] ^ local_40;
      local_7c = local_110[0xd] ^ local_3c;
      local_78 = local_110[0xe] ^ local_38;
      local_74 = local_110[0xf] ^ local_34;
    }
    else {
      puVar21 = local_110;
      puVar29 = local_b0;
      do {
        uVar59 = *puVar21;
        uVar53 = puVar21[1];
        uVar46 = puVar21[2];
        uVar37 = puVar21[3];
        puVar21 = puVar21 + 4;
        *puVar29 = uVar59;
        puVar29[1] = uVar53;
        puVar29[2] = uVar46;
        puVar29[3] = uVar37;
        puVar29 = puVar29 + 4;
      } while (puVar21 != local_110 + 0x10);
      local_6c = param_1[1];
      local_70 = *param_1;
      local_64 = param_1[3];
      local_68 = param_1[2];
      local_b0[1] = local_b0[1] ^ local_6c;
      local_60 = param_1[4];
      local_b0[0] = local_b0[0] ^ local_70;
      local_54 = param_1[7];
      local_b0[2] = local_b0[2] ^ local_68;
      local_5c = param_1[5];
      local_b0[3] = local_b0[3] ^ local_64;
      local_58 = param_1[6];
      local_b0[6] = local_b0[6] ^ local_58;
      local_b0[4] = local_b0[4] ^ local_60;
      local_b0[5] = local_b0[5] ^ local_5c;
      local_50 = param_1[8];
      local_94 = local_94 ^ local_54;
      local_4c = param_1[9];
      local_40 = param_1[0xc];
      local_48 = param_1[10];
      local_44 = param_1[0xb];
      local_3c = param_1[0xd];
      local_8c = local_8c ^ local_4c;
      local_88 = local_88 ^ local_48;
      local_84 = local_84 ^ local_44;
      local_38 = param_1[0xe];
      local_90 = local_90 ^ local_50;
      local_34 = param_1[0xf];
      local_80 = local_80 ^ local_40;
      local_7c = local_7c ^ local_3c;
      local_78 = local_78 ^ local_38;
      local_74 = local_74 ^ local_34;
    }
    uVar20 = local_34;
    uVar19 = local_38;
    uVar18 = local_3c;
    uVar17 = local_40;
    uVar16 = local_44;
    uVar15 = local_48;
    uVar14 = local_4c;
    uVar13 = local_50;
    uVar12 = local_54;
    uVar11 = local_58;
    uVar10 = local_5c;
    uVar9 = local_60;
    uVar59 = local_64;
    uVar53 = local_68;
    uVar46 = local_6c;
    uVar37 = local_70;
    local_10c = local_110 + 0x10;
    puVar21 = local_c0;
    do {
      puVar29 = puVar21 + 2;
      iVar47 = (local_70 & 0xff) * 0x40;
      iVar38 = (local_6c >> 0x18) * 0x40;
      iVar60 = (local_6c >> 0x10 & 0xff) * 0x40;
      iVar78 = (local_6c >> 8 & 0xff) * 0x40;
      iVar82 = (local_60 >> 0x18) * 0x40;
      iVar54 = (local_70 >> 8 & 0xff) * 0x40;
      iVar70 = (local_6c & 0xff) * 0x40;
      iVar66 = (local_68 >> 0x10 & 0xff) * 0x40;
      iVar73 = (local_68 >> 0x18) * 0x40;
      iVar30 = (local_70 >> 0x10 & 0xff) * 0x40;
      iVar22 = (local_5c & 0xff) * 0x40;
      iVar95 = (local_68 >> 8 & 0xff) * 0x40;
      iVar91 = (local_60 >> 0x10 & 0xff) * 0x40;
      iVar93 = (local_58 >> 0x18) * 0x40;
      iVar88 = (local_54 >> 8 & 0xff) * 0x40;
      iVar55 = (local_54 & 0xff) * 0x40;
      iVar48 = (local_68 & 0xff) * 0x40;
      iVar23 = (local_4c >> 0x10 & 0xff) * 0x40;
      iVar61 = (local_50 >> 0x18) * 0x40;
      iVar39 = (local_60 >> 8 & 0xff) * 0x40;
      iVar98 = (local_4c >> 8 & 0xff) * 0x40;
      iVar31 = (local_58 >> 0x10 & 0xff) * 0x40;
      iVar92 = (local_4c & 0xff) * 0x40;
      iVar89 = (local_64 >> 0x18) * 0x40;
      iVar74 = (local_60 & 0xff) * 0x40;
      iVar79 = (local_48 >> 0x18) * 0x40;
      iVar49 = (local_44 >> 0x18) * 0x40;
      iVar40 = (local_44 >> 0x10 & 0xff) * 0x40;
      iVar56 = (local_50 >> 0x10 & 0xff) * 0x40;
      iVar32 = (local_44 >> 8 & 0xff) * 0x40;
      iVar24 = (local_44 & 0xff) * 0x40;
      iVar62 = (local_58 >> 8 & 0xff) * 0x40;
      iVar75 = (local_64 >> 0x10 & 0xff) * 0x40;
      iVar63 = (local_40 >> 0x18) * 0x40;
      iVar71 = (local_50 >> 8 & 0xff) * 0x40;
      iVar83 = (local_48 >> 0x10 & 0xff) * 0x40;
      iVar57 = (local_40 & 0xff) * 0x40;
      iVar86 = (local_5c >> 0x18) * 0x40;
      iVar67 = (local_58 & 0xff) * 0x40;
      iVar50 = (local_3c >> 0x18) * 0x40;
      iVar33 = (local_3c >> 8 & 0xff) * 0x40;
      iVar41 = (local_3c >> 0x10 & 0xff) * 0x40;
      iVar25 = (local_3c & 0xff) * 0x40;
      iVar64 = (local_64 >> 8 & 0xff) * 0x40;
      iVar84 = (local_5c >> 0x10 & 0xff) * 0x40;
      iVar76 = (local_54 >> 0x18) * 0x40;
      iVar51 = (local_48 >> 8 & 0xff) * 0x40;
      iVar42 = (local_40 >> 0x10 & 0xff) * 0x40;
      iVar80 = (local_38 >> 0x18) * 0x40;
      iVar87 = (local_50 & 0xff) * 0x40;
      iVar34 = (local_64 & 0xff) * 0x40;
      iVar26 = (local_5c >> 8 & 0xff) * 0x40;
      iVar68 = (local_70 >> 0x18) * 0x40;
      iVar90 = (local_54 >> 0x10 & 0xff) * 0x40;
      iVar77 = (local_4c >> 0x18) * 0x40;
      iVar72 = (local_48 & 0xff) * 0x40;
      iVar85 = (local_40 >> 8 & 0xff) * 0x40;
      iVar97 = (local_38 >> 0x10 & 0xff) * 0x40;
      iVar96 = (local_38 >> 8 & 0xff) * 0x40;
      iVar81 = (local_34 >> 0x18) * 0x40;
      iVar94 = (local_38 & 0xff) * 0x40;
      iVar27 = (local_34 >> 8 & 0xff) * 0x40;
      iVar35 = (local_34 >> 0x10 & 0xff) * 0x40;
      iVar69 = (local_34 & 0xff) * 0x40;
      iVar65 = (local_b0[1] & 0xff) * 0x40;
      iVar28 = (local_b0[3] >> 8 & 0xff) * 0x40;
      iVar52 = (local_78 >> 0x18) * 0x40;
      iVar43 = (local_b0[5] >> 0x10 & 0xff) * 0x40;
      iVar36 = (local_94 >> 0x18) * 0x40;
      local_38 = *(uint *)(Cx + iVar42 + 8) ^
                 *(uint *)(Cx + iVar51 + 0x10) ^
                 *(uint *)(Cx + iVar87 + 0x18) ^
                 *(uint *)(Cx + iVar76 + 0x20) ^
                 *(uint *)(Cx + iVar84 + 0x28) ^
                 *(uint *)(Cx + iVar80) ^
                 *(uint *)(Cx + iVar64 + 0x30) ^ *(uint *)(Cx + iVar70 + 0x38);
      local_34 = *(uint *)(Cx + iVar42 + 0xc) ^
                 *(uint *)(Cx + iVar51 + 0x14) ^
                 *(uint *)(Cx + iVar87 + 0x1c) ^
                 *(uint *)(Cx + iVar76 + 0x24) ^
                 *(uint *)(Cx + iVar84 + 0x2c) ^
                 *(uint *)(Cx + iVar80 + 4) ^
                 *(uint *)(Cx + iVar64 + 0x34) ^ *(uint *)(Cx + iVar70 + 0x3c);
      local_70 = *puVar21 ^
                 *(uint *)(Cx + iVar97 + 8) ^
                 *(uint *)(Cx + iVar85 + 0x10) ^
                 *(uint *)(Cx + iVar72 + 0x18) ^
                 *(uint *)(Cx + iVar77 + 0x20) ^
                 *(uint *)(Cx + iVar90 + 0x28) ^
                 *(uint *)(Cx + iVar68) ^
                 *(uint *)(Cx + iVar34 + 0x38) ^ *(uint *)(Cx + iVar26 + 0x30);
      local_6c = puVar21[1] ^
                 *(uint *)(Cx + iVar97 + 0xc) ^
                 *(uint *)(Cx + iVar85 + 0x14) ^
                 *(uint *)(Cx + iVar72 + 0x1c) ^
                 *(uint *)(Cx + iVar77 + 0x24) ^
                 *(uint *)(Cx + iVar90 + 0x2c) ^
                 *(uint *)(Cx + iVar68 + 4) ^
                 *(uint *)(Cx + iVar34 + 0x3c) ^ *(uint *)(Cx + iVar26 + 0x34);
      local_68 = *(uint *)(Cx + iVar96 + 0x10) ^
                 *(uint *)(Cx + iVar57 + 0x18) ^
                 *(uint *)(Cx + iVar49 + 0x20) ^
                 *(uint *)(Cx + iVar23 + 0x28) ^
                 *(uint *)(Cx + iVar88 + 0x30) ^
                 *(uint *)(Cx + iVar73) ^ *(uint *)(Cx + iVar30 + 8) ^ *(uint *)(Cx + iVar22 + 0x38)
      ;
      local_64 = *(uint *)(Cx + iVar96 + 0x14) ^
                 *(uint *)(Cx + iVar57 + 0x1c) ^
                 *(uint *)(Cx + iVar49 + 0x24) ^
                 *(uint *)(Cx + iVar23 + 0x2c) ^
                 *(uint *)(Cx + iVar88 + 0x34) ^
                 *(uint *)(Cx + iVar73 + 4) ^
                 *(uint *)(Cx + iVar30 + 0xc) ^ *(uint *)(Cx + iVar22 + 0x3c);
      local_60 = *(uint *)(Cx + iVar94 + 0x18) ^
                 *(uint *)(Cx + iVar50 + 0x20) ^
                 *(uint *)(Cx + iVar40 + 0x28) ^
                 *(uint *)(Cx + iVar98 + 0x30) ^
                 *(uint *)(Cx + iVar55 + 0x38) ^
                 *(uint *)(Cx + iVar82) ^ *(uint *)(Cx + iVar66 + 8) ^ *(uint *)(Cx + iVar54 + 0x10)
      ;
      local_5c = *(uint *)(Cx + iVar94 + 0x1c) ^
                 *(uint *)(Cx + iVar50 + 0x24) ^
                 *(uint *)(Cx + iVar40 + 0x2c) ^
                 *(uint *)(Cx + iVar98 + 0x34) ^
                 *(uint *)(Cx + iVar55 + 0x3c) ^
                 *(uint *)(Cx + iVar82 + 4) ^
                 *(uint *)(Cx + iVar66 + 0xc) ^ *(uint *)(Cx + iVar54 + 0x14);
      local_58 = *(uint *)(Cx + iVar81 + 0x20) ^
                 *(uint *)(Cx + iVar41 + 0x28) ^
                 *(uint *)(Cx + iVar32 + 0x30) ^
                 *(uint *)(Cx + iVar92 + 0x38) ^
                 *(uint *)(Cx + iVar91 + 8) ^
                 *(uint *)(Cx + iVar93) ^
                 *(uint *)(Cx + iVar95 + 0x10) ^ *(uint *)(Cx + iVar47 + 0x18);
      local_54 = *(uint *)(Cx + iVar81 + 0x24) ^
                 *(uint *)(Cx + iVar41 + 0x2c) ^
                 *(uint *)(Cx + iVar32 + 0x34) ^
                 *(uint *)(Cx + iVar92 + 0x3c) ^
                 *(uint *)(Cx + iVar91 + 0xc) ^
                 *(uint *)(Cx + iVar93 + 4) ^
                 *(uint *)(Cx + iVar95 + 0x14) ^ *(uint *)(Cx + iVar47 + 0x1c);
      local_50 = *(uint *)(Cx + iVar35 + 0x28) ^
                 *(uint *)(Cx + iVar33 + 0x30) ^
                 *(uint *)(Cx + iVar24 + 0x38) ^
                 *(uint *)(Cx + iVar31 + 8) ^
                 *(uint *)(Cx + iVar39 + 0x10) ^
                 *(uint *)(Cx + iVar61) ^
                 *(uint *)(Cx + iVar48 + 0x18) ^ *(uint *)(Cx + iVar38 + 0x20);
      local_4c = *(uint *)(Cx + iVar35 + 0x2c) ^
                 *(uint *)(Cx + iVar33 + 0x34) ^
                 *(uint *)(Cx + iVar24 + 0x3c) ^
                 *(uint *)(Cx + iVar31 + 0xc) ^
                 *(uint *)(Cx + iVar39 + 0x14) ^
                 *(uint *)(Cx + iVar61 + 4) ^
                 *(uint *)(Cx + iVar48 + 0x1c) ^ *(uint *)(Cx + iVar38 + 0x24);
      iVar64 = (local_90 & 0xff) * 0x40;
      local_48 = *(uint *)(Cx + iVar27 + 0x30) ^
                 *(uint *)(Cx + iVar25 + 0x38) ^
                 *(uint *)(Cx + iVar56 + 8) ^
                 *(uint *)(Cx + iVar62 + 0x10) ^
                 *(uint *)(Cx + iVar74 + 0x18) ^
                 *(uint *)(Cx + iVar79) ^
                 *(uint *)(Cx + iVar89 + 0x20) ^ *(uint *)(Cx + iVar60 + 0x28);
      iVar55 = (local_88 >> 8 & 0xff) * 0x40;
      local_44 = *(uint *)(Cx + iVar27 + 0x34) ^
                 *(uint *)(Cx + iVar25 + 0x3c) ^
                 *(uint *)(Cx + iVar56 + 0xc) ^
                 *(uint *)(Cx + iVar62 + 0x14) ^
                 *(uint *)(Cx + iVar74 + 0x1c) ^
                 *(uint *)(Cx + iVar79 + 4) ^
                 *(uint *)(Cx + iVar89 + 0x24) ^ *(uint *)(Cx + iVar60 + 0x2c);
      iVar22 = (local_b0[3] & 0xff) * 0x40;
      local_40 = *(uint *)(Cx + iVar69 + 0x38) ^
                 *(uint *)(Cx + iVar83 + 8) ^
                 *(uint *)(Cx + iVar71 + 0x10) ^
                 *(uint *)(Cx + iVar67 + 0x18) ^
                 *(uint *)(Cx + iVar86 + 0x20) ^
                 *(uint *)(Cx + iVar63) ^
                 *(uint *)(Cx + iVar75 + 0x28) ^ *(uint *)(Cx + iVar78 + 0x30);
      iVar30 = (local_b0[5] >> 8 & 0xff) * 0x40;
      local_3c = *(uint *)(Cx + iVar69 + 0x3c) ^
                 *(uint *)(Cx + iVar83 + 0xc) ^
                 *(uint *)(Cx + iVar71 + 0x14) ^
                 *(uint *)(Cx + iVar67 + 0x1c) ^
                 *(uint *)(Cx + iVar86 + 0x24) ^
                 *(uint *)(Cx + iVar63 + 4) ^
                 *(uint *)(Cx + iVar75 + 0x2c) ^ *(uint *)(Cx + iVar78 + 0x34);
      iVar47 = (local_80 >> 0x10 & 0xff) * 0x40;
      iVar91 = (local_94 >> 0x10 & 0xff) * 0x40;
      iVar90 = (local_8c >> 0x18) * 0x40;
      iVar73 = (local_b0[0] >> 0x18) * 0x40;
      iVar93 = (local_88 & 0xff) * 0x40;
      iVar87 = (local_78 >> 0x10 & 0xff) * 0x40;
      iVar92 = (local_80 >> 8 & 0xff) * 0x40;
      iVar76 = (local_b0[0] >> 0x10 & 0xff) * 0x40;
      iVar74 = (local_b0[5] & 0xff) * 0x40;
      iVar67 = (local_94 >> 8 & 0xff) * 0x40;
      iVar62 = (local_8c >> 0x10 & 0xff) * 0x40;
      iVar80 = (local_b0[2] >> 0x18) * 0x40;
      iVar38 = (local_78 >> 8 & 0xff) * 0x40;
      iVar56 = (local_84 >> 0x18) * 0x40;
      iVar48 = (local_80 & 0xff) * 0x40;
      iVar31 = (local_b0[0] >> 8 & 0xff) * 0x40;
      iVar23 = (local_b0[2] >> 0x10 & 0xff) * 0x40;
      iVar70 = (local_b0[4] >> 0x18) * 0x40;
      iVar84 = (local_94 & 0xff) * 0x40;
      iVar77 = (local_8c >> 8 & 0xff) * 0x40;
      iVar63 = (local_7c >> 0x18) * 0x40;
      iVar57 = (local_78 & 0xff) * 0x40;
      iVar81 = (local_84 >> 0x10 & 0xff) * 0x40;
      iVar49 = (local_b0[0] & 0xff) * 0x40;
      iVar39 = (local_b0[2] >> 8 & 0xff) * 0x40;
      iVar68 = (local_b0[6] >> 0x18) * 0x40;
      iVar32 = (local_b0[4] >> 0x10 & 0xff) * 0x40;
      iVar24 = (local_8c & 0xff) * 0x40;
      iVar66 = (local_74 >> 0x18) * 0x40;
      iVar82 = (local_84 >> 8 & 0xff) * 0x40;
      iVar88 = (local_b0[1] >> 0x18) * 0x40;
      iVar60 = (local_b0[2] & 0xff) * 0x40;
      iVar85 = (local_7c >> 0x10 & 0xff) * 0x40;
      iVar50 = (local_b0[4] >> 8 & 0xff) * 0x40;
      iVar40 = (local_b0[6] >> 0x10 & 0xff) * 0x40;
      iVar69 = (local_90 >> 0x18) * 0x40;
      iVar33 = (local_84 & 0xff) * 0x40;
      iVar25 = (local_7c >> 8 & 0xff) * 0x40;
      iVar78 = (local_74 >> 0x10 & 0xff) * 0x40;
      iVar89 = (local_b0[1] >> 0x10 & 0xff) * 0x40;
      iVar83 = (local_b0[3] >> 0x18) * 0x40;
      iVar75 = (local_b0[4] & 0xff) * 0x40;
      iVar71 = (local_b0[6] >> 8 & 0xff) * 0x40;
      iVar86 = (local_88 >> 0x18) * 0x40;
      iVar61 = (local_90 >> 0x10 & 0xff) * 0x40;
      iVar51 = (local_7c & 0xff) * 0x40;
      iVar26 = (local_b0[3] >> 0x10 & 0xff) * 0x40;
      iVar41 = (local_74 >> 8 & 0xff) * 0x40;
      iVar34 = (local_b0[1] >> 8 & 0xff) * 0x40;
      iVar72 = (local_80 >> 0x18) * 0x40;
      iVar54 = (local_b0[5] >> 0x18) * 0x40;
      iVar79 = (local_b0[6] & 0xff) * 0x40;
      iVar42 = (local_90 >> 8 & 0xff) * 0x40;
      iVar35 = (local_88 >> 0x10 & 0xff) * 0x40;
      iVar27 = (local_74 & 0xff) * 0x40;
      local_78 = *(uint *)(Cx + iVar47 + 8) ^
                 *(uint *)(Cx + iVar55 + 0x10) ^
                 *(uint *)(Cx + iVar64 + 0x18) ^
                 *(uint *)(Cx + iVar36 + 0x20) ^
                 *(uint *)(Cx + iVar43 + 0x28) ^
                 *(uint *)(Cx + iVar52) ^
                 *(uint *)(Cx + iVar65 + 0x38) ^ *(uint *)(Cx + iVar28 + 0x30) ^ local_38;
      local_74 = *(uint *)(Cx + iVar47 + 0xc) ^
                 *(uint *)(Cx + iVar55 + 0x14) ^
                 *(uint *)(Cx + iVar64 + 0x1c) ^
                 *(uint *)(Cx + iVar36 + 0x24) ^
                 *(uint *)(Cx + iVar43 + 0x2c) ^
                 *(uint *)(Cx + iVar52 + 4) ^
                 *(uint *)(Cx + iVar65 + 0x3c) ^ *(uint *)(Cx + iVar28 + 0x34) ^ local_34;
      local_b0[0] = *(uint *)(Cx + iVar87 + 8) ^
                    *(uint *)(Cx + iVar92 + 0x10) ^
                    *(uint *)(Cx + iVar93 + 0x18) ^
                    *(uint *)(Cx + iVar90 + 0x20) ^
                    *(uint *)(Cx + iVar91 + 0x28) ^
                    *(uint *)(Cx + iVar73) ^
                    *(uint *)(Cx + iVar22 + 0x38) ^ *(uint *)(Cx + iVar30 + 0x30) ^ local_70;
      local_b0[1] = *(uint *)(Cx + iVar87 + 0xc) ^
                    *(uint *)(Cx + iVar92 + 0x14) ^
                    *(uint *)(Cx + iVar93 + 0x1c) ^
                    *(uint *)(Cx + iVar90 + 0x24) ^
                    *(uint *)(Cx + iVar91 + 0x2c) ^
                    *(uint *)(Cx + iVar73 + 4) ^
                    *(uint *)(Cx + iVar22 + 0x3c) ^ *(uint *)(Cx + iVar30 + 0x34) ^ local_6c;
      local_8c = *(uint *)(Cx + iVar78 + 0x2c) ^
                 *(uint *)(Cx + iVar25 + 0x34) ^
                 *(uint *)(Cx + iVar33 + 0x3c) ^
                 *(uint *)(Cx + iVar40 + 0xc) ^
                 *(uint *)(Cx + iVar50 + 0x14) ^
                 *(uint *)(Cx + iVar69 + 4) ^
                 *(uint *)(Cx + iVar88 + 0x24) ^ *(uint *)(Cx + iVar60 + 0x1c) ^ local_4c;
      local_b0[2] = *(uint *)(Cx + iVar38 + 0x10) ^
                    *(uint *)(Cx + iVar48 + 0x18) ^
                    *(uint *)(Cx + iVar56 + 0x20) ^
                    *(uint *)(Cx + iVar62 + 0x28) ^
                    *(uint *)(Cx + iVar67 + 0x30) ^
                    *(uint *)(Cx + iVar80) ^
                    *(uint *)(Cx + iVar76 + 8) ^ *(uint *)(Cx + iVar74 + 0x38) ^ local_68;
      local_b0[3] = *(uint *)(Cx + iVar38 + 0x14) ^
                    *(uint *)(Cx + iVar48 + 0x1c) ^
                    *(uint *)(Cx + iVar56 + 0x24) ^
                    *(uint *)(Cx + iVar62 + 0x2c) ^
                    *(uint *)(Cx + iVar67 + 0x34) ^
                    *(uint *)(Cx + iVar80 + 4) ^
                    *(uint *)(Cx + iVar76 + 0xc) ^ *(uint *)(Cx + iVar74 + 0x3c) ^ local_64;
      local_b0[5] = *(uint *)(Cx + iVar57 + 0x1c) ^
                    *(uint *)(Cx + iVar63 + 0x24) ^
                    *(uint *)(Cx + iVar81 + 0x2c) ^
                    *(uint *)(Cx + iVar77 + 0x34) ^
                    *(uint *)(Cx + iVar84 + 0x3c) ^
                    *(uint *)(Cx + iVar70 + 4) ^
                    *(uint *)(Cx + iVar31 + 0x14) ^ *(uint *)(Cx + iVar23 + 0xc) ^ local_5c;
      local_b0[6] = *(uint *)(Cx + iVar66 + 0x20) ^
                    *(uint *)(Cx + iVar85 + 0x28) ^
                    *(uint *)(Cx + iVar82 + 0x30) ^
                    *(uint *)(Cx + iVar24 + 0x38) ^
                    *(uint *)(Cx + iVar32 + 8) ^
                    *(uint *)(Cx + iVar68) ^
                    *(uint *)(Cx + iVar49 + 0x18) ^ *(uint *)(Cx + iVar39 + 0x10) ^ local_58;
      local_94 = *(uint *)(Cx + iVar66 + 0x24) ^
                 *(uint *)(Cx + iVar85 + 0x2c) ^
                 *(uint *)(Cx + iVar82 + 0x34) ^
                 *(uint *)(Cx + iVar24 + 0x3c) ^
                 *(uint *)(Cx + iVar32 + 0xc) ^
                 *(uint *)(Cx + iVar68 + 4) ^
                 *(uint *)(Cx + iVar49 + 0x1c) ^ *(uint *)(Cx + iVar39 + 0x14) ^ local_54;
      local_90 = *(uint *)(Cx + iVar78 + 0x28) ^
                 *(uint *)(Cx + iVar25 + 0x30) ^
                 *(uint *)(Cx + iVar33 + 0x38) ^
                 *(uint *)(Cx + iVar40 + 8) ^
                 *(uint *)(Cx + iVar50 + 0x10) ^
                 *(uint *)(Cx + iVar69) ^
                 *(uint *)(Cx + iVar88 + 0x20) ^ *(uint *)(Cx + iVar60 + 0x18) ^ local_50;
      local_b0[4] = *(uint *)(Cx + iVar57 + 0x18) ^
                    *(uint *)(Cx + iVar63 + 0x20) ^
                    *(uint *)(Cx + iVar81 + 0x28) ^
                    *(uint *)(Cx + iVar77 + 0x30) ^
                    *(uint *)(Cx + iVar84 + 0x38) ^
                    *(uint *)(Cx + iVar70) ^
                    *(uint *)(Cx + iVar31 + 0x10) ^ *(uint *)(Cx + iVar23 + 8) ^ local_60;
      local_84 = *(uint *)(Cx + iVar41 + 0x34) ^
                 *(uint *)(Cx + iVar51 + 0x3c) ^
                 *(uint *)(Cx + iVar61 + 0xc) ^
                 *(uint *)(Cx + iVar71 + 0x14) ^
                 *(uint *)(Cx + iVar75 + 0x1c) ^
                 *(uint *)(Cx + iVar86 + 4) ^
                 *(uint *)(Cx + iVar89 + 0x2c) ^ *(uint *)(Cx + iVar83 + 0x24) ^ local_44;
      local_80 = *(uint *)(Cx + iVar27 + 0x38) ^
                 *(uint *)(Cx + iVar35 + 8) ^
                 *(uint *)(Cx + iVar42 + 0x10) ^
                 *(uint *)(Cx + iVar79 + 0x18) ^
                 *(uint *)(Cx + iVar54 + 0x20) ^
                 *(uint *)(Cx + iVar72) ^
                 *(uint *)(Cx + iVar34 + 0x30) ^ *(uint *)(Cx + iVar26 + 0x28) ^ local_40;
      local_88 = *(uint *)(Cx + iVar41 + 0x30) ^
                 *(uint *)(Cx + iVar51 + 0x38) ^
                 *(uint *)(Cx + iVar61 + 8) ^
                 *(uint *)(Cx + iVar71 + 0x10) ^
                 *(uint *)(Cx + iVar75 + 0x18) ^
                 *(uint *)(Cx + iVar86) ^
                 *(uint *)(Cx + iVar89 + 0x28) ^ *(uint *)(Cx + iVar83 + 0x20) ^ local_48;
      local_7c = *(uint *)(Cx + iVar27 + 0x3c) ^
                 *(uint *)(Cx + iVar35 + 0xc) ^
                 *(uint *)(Cx + iVar42 + 0x14) ^
                 *(uint *)(Cx + iVar79 + 0x1c) ^
                 *(uint *)(Cx + iVar54 + 0x24) ^
                 *(uint *)(Cx + iVar72 + 4) ^
                 *(uint *)(Cx + iVar34 + 0x34) ^ *(uint *)(Cx + iVar26 + 0x2c) ^ local_3c;
      puVar21 = puVar29;
    } while (puVar29 != (uint *)shifts2_6299);
    if (((uint)local_110 & 7) == 0) {
      uVar45 = local_110[1];
      *param_1 = uVar37 ^ *local_110 ^ local_b0[0];
      param_1[1] = uVar46 ^ uVar45 ^ local_b0[1];
      uVar37 = local_110[3];
      param_1[2] = uVar53 ^ local_110[2] ^ local_b0[2];
      param_1[3] = uVar59 ^ uVar37 ^ local_b0[3];
      uVar37 = local_110[5];
      param_1[4] = uVar9 ^ local_110[4] ^ local_b0[4];
      param_1[5] = uVar10 ^ uVar37 ^ local_b0[5];
      uVar37 = local_110[7];
      param_1[6] = uVar11 ^ local_110[6] ^ local_b0[6];
      param_1[7] = uVar12 ^ uVar37 ^ local_94;
      uVar37 = local_110[9];
      param_1[8] = uVar13 ^ local_110[8] ^ local_90;
      param_1[9] = uVar14 ^ uVar37 ^ local_8c;
      uVar37 = local_110[0xb];
      param_1[10] = uVar15 ^ local_110[10] ^ local_88;
      param_1[0xb] = uVar16 ^ uVar37 ^ local_84;
      uVar37 = local_110[0xd];
      param_1[0xc] = uVar17 ^ local_110[0xc] ^ local_80;
      param_1[0xd] = uVar18 ^ uVar37 ^ local_7c;
      uVar37 = local_110[0xf];
      pbVar44 = (byte *)(uVar19 ^ local_110[0xe]);
      param_1[0xe] = (uint)pbVar44 ^ local_78;
      param_1[0xf] = uVar20 ^ uVar37 ^ local_74;
    }
    else if ((param_1 < local_110 + 1 && local_110 < param_1 + 1) || (((uint)local_110 & 3) != 0)) {
      puVar21 = param_1;
      puVar29 = local_b0;
      do {
        puVar58 = (uint *)((int)puVar29 + 1);
        bVar1 = *(byte *)local_110;
        pbVar44 = (byte *)(uint)bVar1;
        local_110 = (uint *)((int)local_110 + 1);
        *(byte *)puVar21 = *(byte *)puVar29 ^ *(byte *)puVar21 ^ bVar1;
        puVar21 = (uint *)((int)puVar21 + 1);
        puVar29 = puVar58;
      } while (puVar58 != &local_70);
    }
    else {
      *param_1 = local_b0[0] ^ *param_1 ^ *local_110;
      param_1[1] = local_b0[1] ^ param_1[1] ^ local_110[1];
      param_1[2] = local_b0[2] ^ param_1[2] ^ local_110[2];
      param_1[3] = param_1[3] ^ local_b0[3] ^ local_110[3];
      param_1[4] = param_1[4] ^ local_b0[4] ^ local_110[4];
      param_1[5] = param_1[5] ^ local_b0[5] ^ local_110[5];
      param_1[6] = param_1[6] ^ local_b0[6] ^ local_110[6];
      param_1[7] = param_1[7] ^ local_94 ^ local_110[7];
      param_1[8] = param_1[8] ^ local_90 ^ local_110[8];
      param_1[9] = param_1[9] ^ local_8c ^ local_110[9];
      param_1[10] = param_1[10] ^ local_88 ^ local_110[10];
      pbVar44 = (byte *)param_1[0xe];
      param_1[0xb] = local_84 ^ param_1[0xb] ^ local_110[0xb];
      param_1[0xc] = param_1[0xc] ^ local_80 ^ local_110[0xc];
      param_1[0xd] = param_1[0xd] ^ local_7c ^ local_110[0xd];
      param_1[0xe] = (uint)pbVar44 ^ local_78 ^ local_110[0xe];
      param_1[0xf] = param_1[0xf] ^ local_74 ^ local_110[0xf];
    }
    local_res8 = local_res8 + -1;
    local_110 = local_10c;
  } while (local_res8 != 0);
  if (local_2c != *(int *)puVar8) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    bVar1 = odd_parity[pbVar44[1]];
    bVar2 = odd_parity[pbVar44[2]];
    bVar3 = odd_parity[pbVar44[3]];
    bVar4 = odd_parity[pbVar44[4]];
    bVar5 = odd_parity[pbVar44[5]];
    bVar6 = odd_parity[pbVar44[6]];
    bVar7 = odd_parity[pbVar44[7]];
    *pbVar44 = odd_parity[*pbVar44];
    pbVar44[1] = bVar1;
    pbVar44[2] = bVar2;
    pbVar44[3] = bVar3;
    pbVar44[4] = bVar4;
    pbVar44[5] = bVar5;
    pbVar44[6] = bVar6;
    pbVar44[7] = bVar7;
    return;
  }
  return;
}

