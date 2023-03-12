
uchar * WHIRLPOOL(void *inp,size_t bytes,uchar *md)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  _union_1012 *p_Var8;
  undefined *puVar9;
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
  uint uVar21;
  uint uVar22;
  WHIRLPOOL_CTX *pWVar23;
  uint *puVar24;
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
  uint *puVar39;
  uint uVar40;
  int iVar41;
  int iVar42;
  int iVar43;
  int iVar44;
  int iVar45;
  int iVar46;
  byte *pbVar47;
  uint uVar48;
  uint uVar49;
  int iVar50;
  int iVar51;
  int iVar52;
  int iVar53;
  int iVar54;
  int iVar55;
  uint uVar56;
  int iVar57;
  int iVar58;
  int iVar59;
  int iVar60;
  uint *puVar61;
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
  void *unaff_s0;
  size_t unaff_s1;
  int iVar96;
  int iVar97;
  undefined4 unaff_s2;
  int iVar98;
  int iVar99;
  undefined4 unaff_s4;
  int iVar100;
  int iVar101;
  WHIRLPOOL_CTX *pWStack_200;
  uchar *puStack_1fc;
  uint *puStack_1b0;
  uint auStack_1a0 [7];
  uint uStack_184;
  uint uStack_180;
  uint uStack_17c;
  uint uStack_178;
  uint uStack_174;
  uint uStack_170;
  uint uStack_16c;
  uint uStack_168;
  uint uStack_164;
  uint uStack_160;
  uint uStack_15c;
  uint uStack_158;
  uint uStack_154;
  uint uStack_150;
  uint uStack_14c;
  uint uStack_148;
  uint uStack_144;
  uint uStack_140;
  uint uStack_13c;
  uint uStack_138;
  uint uStack_134;
  uint uStack_130;
  uint uStack_12c;
  uint uStack_128;
  uint uStack_124;
  uchar *puStack_11c;
  void *pvStack_118;
  uint uStack_114;
  undefined4 uStack_110;
  WHIRLPOOL_CTX *pWStack_10c;
  undefined4 uStack_108;
  size_t sStack_104;
  undefined1 *puStack_100;
  void *pvStack_fc;
  undefined *puStack_f8;
  undefined4 uStack_f4;
  uint uStack_e8;
  undefined *local_e0;
  WHIRLPOOL_CTX WStack_d8;
  uint *local_2c;
  uint *puVar62;
  
  puStack_f8 = PTR___stack_chk_guard_006a9ae8;
  local_e0 = &_gp;
  local_2c = *(uint **)PTR___stack_chk_guard_006a9ae8;
  puStack_100 = md;
  if (md == (uchar *)0x0) {
    puStack_100 = m_3899;
  }
  (*(code *)PTR_memset_006a99f4)(&WStack_d8,0,0xa8);
  uStack_e8 = bytes;
  if (0xfffffff < bytes) {
    unaff_s4 = 0xf0000000;
    unaff_s2 = 0x10000000;
    unaff_s0 = inp;
    unaff_s1 = bytes;
    do {
      unaff_s1 = unaff_s1 + 0xf0000000;
      WHIRLPOOL_BitUpdate(&WStack_d8,unaff_s0,0x80000000);
      unaff_s0 = (void *)((int)unaff_s0 + 0x10000000);
    } while (0xfffffff < unaff_s1);
    uStack_e8 = bytes & 0xfffffff;
    inp = (void *)((int)inp + ((bytes + 0xf0000000 >> 0x1c) + 1) * 0x10000000);
  }
  if (uStack_e8 != 0) {
    uStack_e8 = uStack_e8 << 3;
    WHIRLPOOL_BitUpdate(&WStack_d8,inp,uStack_e8);
  }
  pWStack_200 = &WStack_d8;
  WHIRLPOOL_Final(puStack_100,&WStack_d8);
  if (local_2c == *(uint **)puStack_f8) {
    return puStack_100;
  }
  uStack_f4 = 0x4d3158;
  puVar39 = local_2c;
  (**(code **)(local_e0 + -0x5330))();
  puVar9 = PTR___stack_chk_guard_006a9ae8;
  puStack_1b0 = (uint *)(Cx + 0x4000);
  pvStack_fc = inp;
  sStack_104 = bytes;
  uStack_108 = unaff_s4;
  pWStack_10c = &WStack_d8;
  uStack_110 = unaff_s2;
  uStack_114 = unaff_s1;
  pvStack_118 = unaff_s0;
  puStack_11c = *(uchar **)PTR___stack_chk_guard_006a9ae8;
  do {
    if (((uint)pWStack_200 & 7) == 0) {
      uStack_158 = puVar39[2];
      uStack_160 = *puVar39;
      uStack_144 = puVar39[7];
      uStack_154 = puVar39[3];
      uStack_150 = puVar39[4];
      auStack_1a0[0] = *(uint *)&pWStack_200->H ^ uStack_160;
      uStack_14c = puVar39[5];
      auStack_1a0[2] = *(uint *)((int)&pWStack_200->H + 8) ^ uStack_158;
      uStack_15c = puVar39[1];
      auStack_1a0[1] = *(uint *)((int)&pWStack_200->H + 4) ^ uStack_15c;
      uStack_148 = puVar39[6];
      auStack_1a0[3] = *(uint *)((int)&pWStack_200->H + 0xc) ^ uStack_154;
      auStack_1a0[5] = *(uint *)((int)&pWStack_200->H + 0x14) ^ uStack_14c;
      auStack_1a0[6] = *(uint *)((int)&pWStack_200->H + 0x18) ^ uStack_148;
      auStack_1a0[4] = *(uint *)((int)&pWStack_200->H + 0x10) ^ uStack_150;
      uStack_184 = *(uint *)((int)&pWStack_200->H + 0x1c) ^ uStack_144;
      uStack_140 = puVar39[8];
      uStack_13c = puVar39[9];
      uStack_180 = *(uint *)((int)&pWStack_200->H + 0x20) ^ uStack_140;
      uStack_138 = puVar39[10];
      uStack_17c = *(uint *)((int)&pWStack_200->H + 0x24) ^ uStack_13c;
      uStack_178 = *(uint *)((int)&pWStack_200->H + 0x28) ^ uStack_138;
      uStack_134 = puVar39[0xb];
      uStack_174 = *(uint *)((int)&pWStack_200->H + 0x2c) ^ uStack_134;
      uStack_130 = puVar39[0xc];
      uStack_12c = puVar39[0xd];
      uStack_128 = puVar39[0xe];
      uStack_124 = puVar39[0xf];
      uStack_170 = *(uint *)((int)&pWStack_200->H + 0x30) ^ uStack_130;
      uStack_16c = *(uint *)((int)&pWStack_200->H + 0x34) ^ uStack_12c;
      uStack_168 = *(uint *)((int)&pWStack_200->H + 0x38) ^ uStack_128;
      uStack_164 = *(uint *)((int)&pWStack_200->H + 0x3c) ^ uStack_124;
    }
    else {
      pWVar23 = pWStack_200;
      puVar24 = auStack_1a0;
      do {
        p_Var8 = &pWVar23->H;
        uVar56 = *(uint *)((int)&pWVar23->H + 4);
        uVar49 = *(uint *)((int)&pWVar23->H + 8);
        uVar40 = *(uint *)((int)&pWVar23->H + 0xc);
        pWVar23 = (WHIRLPOOL_CTX *)((int)&pWVar23->H + 0x10);
        *puVar24 = *(uint *)p_Var8;
        puVar24[1] = uVar56;
        puVar24[2] = uVar49;
        puVar24[3] = uVar40;
        puVar24 = puVar24 + 4;
      } while (pWVar23 != (WHIRLPOOL_CTX *)pWStack_200->data);
      uStack_15c = puVar39[1];
      uStack_160 = *puVar39;
      uStack_154 = puVar39[3];
      uStack_158 = puVar39[2];
      auStack_1a0[1] = auStack_1a0[1] ^ uStack_15c;
      uStack_150 = puVar39[4];
      auStack_1a0[0] = auStack_1a0[0] ^ uStack_160;
      uStack_144 = puVar39[7];
      auStack_1a0[2] = auStack_1a0[2] ^ uStack_158;
      uStack_14c = puVar39[5];
      auStack_1a0[3] = auStack_1a0[3] ^ uStack_154;
      uStack_148 = puVar39[6];
      auStack_1a0[6] = auStack_1a0[6] ^ uStack_148;
      auStack_1a0[4] = auStack_1a0[4] ^ uStack_150;
      auStack_1a0[5] = auStack_1a0[5] ^ uStack_14c;
      uStack_140 = puVar39[8];
      uStack_184 = uStack_184 ^ uStack_144;
      uStack_13c = puVar39[9];
      uStack_130 = puVar39[0xc];
      uStack_138 = puVar39[10];
      uStack_134 = puVar39[0xb];
      uStack_12c = puVar39[0xd];
      uStack_17c = uStack_17c ^ uStack_13c;
      uStack_178 = uStack_178 ^ uStack_138;
      uStack_174 = uStack_174 ^ uStack_134;
      uStack_128 = puVar39[0xe];
      uStack_180 = uStack_180 ^ uStack_140;
      uStack_124 = puVar39[0xf];
      uStack_170 = uStack_170 ^ uStack_130;
      uStack_16c = uStack_16c ^ uStack_12c;
      uStack_168 = uStack_168 ^ uStack_128;
      uStack_164 = uStack_164 ^ uStack_124;
    }
    uVar22 = uStack_124;
    uVar21 = uStack_128;
    uVar20 = uStack_12c;
    uVar19 = uStack_130;
    uVar18 = uStack_134;
    uVar17 = uStack_138;
    uVar16 = uStack_13c;
    uVar15 = uStack_140;
    uVar14 = uStack_144;
    uVar13 = uStack_148;
    uVar12 = uStack_14c;
    uVar11 = uStack_150;
    uVar10 = uStack_154;
    uVar56 = uStack_158;
    uVar49 = uStack_15c;
    uVar40 = uStack_160;
    puStack_1fc = pWStack_200->data;
    puVar24 = puStack_1b0;
    do {
      puVar62 = puVar24 + 2;
      iVar50 = (uStack_160 & 0xff) * 0x40;
      iVar41 = (uStack_15c >> 0x18) * 0x40;
      iVar63 = (uStack_15c >> 0x10 & 0xff) * 0x40;
      iVar81 = (uStack_15c >> 8 & 0xff) * 0x40;
      iVar85 = (uStack_150 >> 0x18) * 0x40;
      iVar57 = (uStack_160 >> 8 & 0xff) * 0x40;
      iVar73 = (uStack_15c & 0xff) * 0x40;
      iVar69 = (uStack_158 >> 0x10 & 0xff) * 0x40;
      iVar76 = (uStack_158 >> 0x18) * 0x40;
      iVar32 = (uStack_160 >> 0x10 & 0xff) * 0x40;
      iVar25 = (uStack_14c & 0xff) * 0x40;
      iVar98 = (uStack_158 >> 8 & 0xff) * 0x40;
      iVar94 = (uStack_150 >> 0x10 & 0xff) * 0x40;
      iVar96 = (uStack_148 >> 0x18) * 0x40;
      iVar91 = (uStack_144 >> 8 & 0xff) * 0x40;
      iVar58 = (uStack_144 & 0xff) * 0x40;
      iVar51 = (uStack_158 & 0xff) * 0x40;
      iVar26 = (uStack_13c >> 0x10 & 0xff) * 0x40;
      iVar64 = (uStack_140 >> 0x18) * 0x40;
      iVar42 = (uStack_150 >> 8 & 0xff) * 0x40;
      iVar101 = (uStack_13c >> 8 & 0xff) * 0x40;
      iVar33 = (uStack_148 >> 0x10 & 0xff) * 0x40;
      iVar95 = (uStack_13c & 0xff) * 0x40;
      iVar92 = (uStack_154 >> 0x18) * 0x40;
      iVar77 = (uStack_150 & 0xff) * 0x40;
      iVar82 = (uStack_138 >> 0x18) * 0x40;
      iVar52 = (uStack_134 >> 0x18) * 0x40;
      iVar43 = (uStack_134 >> 0x10 & 0xff) * 0x40;
      iVar59 = (uStack_140 >> 0x10 & 0xff) * 0x40;
      iVar34 = (uStack_134 >> 8 & 0xff) * 0x40;
      iVar27 = (uStack_134 & 0xff) * 0x40;
      iVar65 = (uStack_148 >> 8 & 0xff) * 0x40;
      iVar78 = (uStack_154 >> 0x10 & 0xff) * 0x40;
      iVar66 = (uStack_130 >> 0x18) * 0x40;
      iVar74 = (uStack_140 >> 8 & 0xff) * 0x40;
      iVar86 = (uStack_138 >> 0x10 & 0xff) * 0x40;
      iVar60 = (uStack_130 & 0xff) * 0x40;
      iVar89 = (uStack_14c >> 0x18) * 0x40;
      iVar70 = (uStack_148 & 0xff) * 0x40;
      iVar53 = (uStack_12c >> 0x18) * 0x40;
      iVar35 = (uStack_12c >> 8 & 0xff) * 0x40;
      iVar44 = (uStack_12c >> 0x10 & 0xff) * 0x40;
      iVar28 = (uStack_12c & 0xff) * 0x40;
      iVar67 = (uStack_154 >> 8 & 0xff) * 0x40;
      iVar87 = (uStack_14c >> 0x10 & 0xff) * 0x40;
      iVar79 = (uStack_144 >> 0x18) * 0x40;
      iVar54 = (uStack_138 >> 8 & 0xff) * 0x40;
      iVar45 = (uStack_130 >> 0x10 & 0xff) * 0x40;
      iVar83 = (uStack_128 >> 0x18) * 0x40;
      iVar90 = (uStack_140 & 0xff) * 0x40;
      iVar36 = (uStack_154 & 0xff) * 0x40;
      iVar29 = (uStack_14c >> 8 & 0xff) * 0x40;
      iVar71 = (uStack_160 >> 0x18) * 0x40;
      iVar93 = (uStack_144 >> 0x10 & 0xff) * 0x40;
      iVar80 = (uStack_13c >> 0x18) * 0x40;
      iVar75 = (uStack_138 & 0xff) * 0x40;
      iVar88 = (uStack_130 >> 8 & 0xff) * 0x40;
      iVar100 = (uStack_128 >> 0x10 & 0xff) * 0x40;
      iVar99 = (uStack_128 >> 8 & 0xff) * 0x40;
      iVar84 = (uStack_124 >> 0x18) * 0x40;
      iVar97 = (uStack_128 & 0xff) * 0x40;
      iVar30 = (uStack_124 >> 8 & 0xff) * 0x40;
      iVar37 = (uStack_124 >> 0x10 & 0xff) * 0x40;
      iVar72 = (uStack_124 & 0xff) * 0x40;
      iVar68 = (auStack_1a0[1] & 0xff) * 0x40;
      iVar31 = (auStack_1a0[3] >> 8 & 0xff) * 0x40;
      iVar55 = (uStack_168 >> 0x18) * 0x40;
      iVar46 = (auStack_1a0[5] >> 0x10 & 0xff) * 0x40;
      iVar38 = (uStack_184 >> 0x18) * 0x40;
      uStack_128 = *(uint *)(Cx + iVar45 + 8) ^
                   *(uint *)(Cx + iVar54 + 0x10) ^
                   *(uint *)(Cx + iVar90 + 0x18) ^
                   *(uint *)(Cx + iVar79 + 0x20) ^
                   *(uint *)(Cx + iVar87 + 0x28) ^
                   *(uint *)(Cx + iVar83) ^
                   *(uint *)(Cx + iVar67 + 0x30) ^ *(uint *)(Cx + iVar73 + 0x38);
      uStack_124 = *(uint *)(Cx + iVar45 + 0xc) ^
                   *(uint *)(Cx + iVar54 + 0x14) ^
                   *(uint *)(Cx + iVar90 + 0x1c) ^
                   *(uint *)(Cx + iVar79 + 0x24) ^
                   *(uint *)(Cx + iVar87 + 0x2c) ^
                   *(uint *)(Cx + iVar83 + 4) ^
                   *(uint *)(Cx + iVar67 + 0x34) ^ *(uint *)(Cx + iVar73 + 0x3c);
      uStack_160 = *puVar24 ^
                   *(uint *)(Cx + iVar100 + 8) ^
                   *(uint *)(Cx + iVar88 + 0x10) ^
                   *(uint *)(Cx + iVar75 + 0x18) ^
                   *(uint *)(Cx + iVar80 + 0x20) ^
                   *(uint *)(Cx + iVar93 + 0x28) ^
                   *(uint *)(Cx + iVar71) ^
                   *(uint *)(Cx + iVar36 + 0x38) ^ *(uint *)(Cx + iVar29 + 0x30);
      uStack_15c = puVar24[1] ^
                   *(uint *)(Cx + iVar100 + 0xc) ^
                   *(uint *)(Cx + iVar88 + 0x14) ^
                   *(uint *)(Cx + iVar75 + 0x1c) ^
                   *(uint *)(Cx + iVar80 + 0x24) ^
                   *(uint *)(Cx + iVar93 + 0x2c) ^
                   *(uint *)(Cx + iVar71 + 4) ^
                   *(uint *)(Cx + iVar36 + 0x3c) ^ *(uint *)(Cx + iVar29 + 0x34);
      uStack_158 = *(uint *)(Cx + iVar99 + 0x10) ^
                   *(uint *)(Cx + iVar60 + 0x18) ^
                   *(uint *)(Cx + iVar52 + 0x20) ^
                   *(uint *)(Cx + iVar26 + 0x28) ^
                   *(uint *)(Cx + iVar91 + 0x30) ^
                   *(uint *)(Cx + iVar76) ^
                   *(uint *)(Cx + iVar32 + 8) ^ *(uint *)(Cx + iVar25 + 0x38);
      uStack_154 = *(uint *)(Cx + iVar99 + 0x14) ^
                   *(uint *)(Cx + iVar60 + 0x1c) ^
                   *(uint *)(Cx + iVar52 + 0x24) ^
                   *(uint *)(Cx + iVar26 + 0x2c) ^
                   *(uint *)(Cx + iVar91 + 0x34) ^
                   *(uint *)(Cx + iVar76 + 4) ^
                   *(uint *)(Cx + iVar32 + 0xc) ^ *(uint *)(Cx + iVar25 + 0x3c);
      uStack_150 = *(uint *)(Cx + iVar97 + 0x18) ^
                   *(uint *)(Cx + iVar53 + 0x20) ^
                   *(uint *)(Cx + iVar43 + 0x28) ^
                   *(uint *)(Cx + iVar101 + 0x30) ^
                   *(uint *)(Cx + iVar58 + 0x38) ^
                   *(uint *)(Cx + iVar85) ^
                   *(uint *)(Cx + iVar69 + 8) ^ *(uint *)(Cx + iVar57 + 0x10);
      uStack_14c = *(uint *)(Cx + iVar97 + 0x1c) ^
                   *(uint *)(Cx + iVar53 + 0x24) ^
                   *(uint *)(Cx + iVar43 + 0x2c) ^
                   *(uint *)(Cx + iVar101 + 0x34) ^
                   *(uint *)(Cx + iVar58 + 0x3c) ^
                   *(uint *)(Cx + iVar85 + 4) ^
                   *(uint *)(Cx + iVar69 + 0xc) ^ *(uint *)(Cx + iVar57 + 0x14);
      uStack_148 = *(uint *)(Cx + iVar84 + 0x20) ^
                   *(uint *)(Cx + iVar44 + 0x28) ^
                   *(uint *)(Cx + iVar34 + 0x30) ^
                   *(uint *)(Cx + iVar95 + 0x38) ^
                   *(uint *)(Cx + iVar94 + 8) ^
                   *(uint *)(Cx + iVar96) ^
                   *(uint *)(Cx + iVar98 + 0x10) ^ *(uint *)(Cx + iVar50 + 0x18);
      uStack_144 = *(uint *)(Cx + iVar84 + 0x24) ^
                   *(uint *)(Cx + iVar44 + 0x2c) ^
                   *(uint *)(Cx + iVar34 + 0x34) ^
                   *(uint *)(Cx + iVar95 + 0x3c) ^
                   *(uint *)(Cx + iVar94 + 0xc) ^
                   *(uint *)(Cx + iVar96 + 4) ^
                   *(uint *)(Cx + iVar98 + 0x14) ^ *(uint *)(Cx + iVar50 + 0x1c);
      uStack_140 = *(uint *)(Cx + iVar37 + 0x28) ^
                   *(uint *)(Cx + iVar35 + 0x30) ^
                   *(uint *)(Cx + iVar27 + 0x38) ^
                   *(uint *)(Cx + iVar33 + 8) ^
                   *(uint *)(Cx + iVar42 + 0x10) ^
                   *(uint *)(Cx + iVar64) ^
                   *(uint *)(Cx + iVar51 + 0x18) ^ *(uint *)(Cx + iVar41 + 0x20);
      uStack_13c = *(uint *)(Cx + iVar37 + 0x2c) ^
                   *(uint *)(Cx + iVar35 + 0x34) ^
                   *(uint *)(Cx + iVar27 + 0x3c) ^
                   *(uint *)(Cx + iVar33 + 0xc) ^
                   *(uint *)(Cx + iVar42 + 0x14) ^
                   *(uint *)(Cx + iVar64 + 4) ^
                   *(uint *)(Cx + iVar51 + 0x1c) ^ *(uint *)(Cx + iVar41 + 0x24);
      iVar67 = (uStack_180 & 0xff) * 0x40;
      uStack_138 = *(uint *)(Cx + iVar30 + 0x30) ^
                   *(uint *)(Cx + iVar28 + 0x38) ^
                   *(uint *)(Cx + iVar59 + 8) ^
                   *(uint *)(Cx + iVar65 + 0x10) ^
                   *(uint *)(Cx + iVar77 + 0x18) ^
                   *(uint *)(Cx + iVar82) ^
                   *(uint *)(Cx + iVar92 + 0x20) ^ *(uint *)(Cx + iVar63 + 0x28);
      iVar58 = (uStack_178 >> 8 & 0xff) * 0x40;
      uStack_134 = *(uint *)(Cx + iVar30 + 0x34) ^
                   *(uint *)(Cx + iVar28 + 0x3c) ^
                   *(uint *)(Cx + iVar59 + 0xc) ^
                   *(uint *)(Cx + iVar65 + 0x14) ^
                   *(uint *)(Cx + iVar77 + 0x1c) ^
                   *(uint *)(Cx + iVar82 + 4) ^
                   *(uint *)(Cx + iVar92 + 0x24) ^ *(uint *)(Cx + iVar63 + 0x2c);
      iVar25 = (auStack_1a0[3] & 0xff) * 0x40;
      uStack_130 = *(uint *)(Cx + iVar72 + 0x38) ^
                   *(uint *)(Cx + iVar86 + 8) ^
                   *(uint *)(Cx + iVar74 + 0x10) ^
                   *(uint *)(Cx + iVar70 + 0x18) ^
                   *(uint *)(Cx + iVar89 + 0x20) ^
                   *(uint *)(Cx + iVar66) ^
                   *(uint *)(Cx + iVar78 + 0x28) ^ *(uint *)(Cx + iVar81 + 0x30);
      iVar32 = (auStack_1a0[5] >> 8 & 0xff) * 0x40;
      uStack_12c = *(uint *)(Cx + iVar72 + 0x3c) ^
                   *(uint *)(Cx + iVar86 + 0xc) ^
                   *(uint *)(Cx + iVar74 + 0x14) ^
                   *(uint *)(Cx + iVar70 + 0x1c) ^
                   *(uint *)(Cx + iVar89 + 0x24) ^
                   *(uint *)(Cx + iVar66 + 4) ^
                   *(uint *)(Cx + iVar78 + 0x2c) ^ *(uint *)(Cx + iVar81 + 0x34);
      iVar50 = (uStack_170 >> 0x10 & 0xff) * 0x40;
      iVar94 = (uStack_184 >> 0x10 & 0xff) * 0x40;
      iVar93 = (uStack_17c >> 0x18) * 0x40;
      iVar76 = (auStack_1a0[0] >> 0x18) * 0x40;
      iVar96 = (uStack_178 & 0xff) * 0x40;
      iVar90 = (uStack_168 >> 0x10 & 0xff) * 0x40;
      iVar95 = (uStack_170 >> 8 & 0xff) * 0x40;
      iVar79 = (auStack_1a0[0] >> 0x10 & 0xff) * 0x40;
      iVar77 = (auStack_1a0[5] & 0xff) * 0x40;
      iVar70 = (uStack_184 >> 8 & 0xff) * 0x40;
      iVar65 = (uStack_17c >> 0x10 & 0xff) * 0x40;
      iVar83 = (auStack_1a0[2] >> 0x18) * 0x40;
      iVar41 = (uStack_168 >> 8 & 0xff) * 0x40;
      iVar59 = (uStack_174 >> 0x18) * 0x40;
      iVar51 = (uStack_170 & 0xff) * 0x40;
      iVar33 = (auStack_1a0[0] >> 8 & 0xff) * 0x40;
      iVar26 = (auStack_1a0[2] >> 0x10 & 0xff) * 0x40;
      iVar73 = (auStack_1a0[4] >> 0x18) * 0x40;
      iVar87 = (uStack_184 & 0xff) * 0x40;
      iVar80 = (uStack_17c >> 8 & 0xff) * 0x40;
      iVar66 = (uStack_16c >> 0x18) * 0x40;
      iVar60 = (uStack_168 & 0xff) * 0x40;
      iVar84 = (uStack_174 >> 0x10 & 0xff) * 0x40;
      iVar52 = (auStack_1a0[0] & 0xff) * 0x40;
      iVar42 = (auStack_1a0[2] >> 8 & 0xff) * 0x40;
      iVar71 = (auStack_1a0[6] >> 0x18) * 0x40;
      iVar34 = (auStack_1a0[4] >> 0x10 & 0xff) * 0x40;
      iVar27 = (uStack_17c & 0xff) * 0x40;
      iVar69 = (uStack_164 >> 0x18) * 0x40;
      iVar85 = (uStack_174 >> 8 & 0xff) * 0x40;
      iVar91 = (auStack_1a0[1] >> 0x18) * 0x40;
      iVar63 = (auStack_1a0[2] & 0xff) * 0x40;
      iVar88 = (uStack_16c >> 0x10 & 0xff) * 0x40;
      iVar53 = (auStack_1a0[4] >> 8 & 0xff) * 0x40;
      iVar43 = (auStack_1a0[6] >> 0x10 & 0xff) * 0x40;
      iVar72 = (uStack_180 >> 0x18) * 0x40;
      iVar35 = (uStack_174 & 0xff) * 0x40;
      iVar28 = (uStack_16c >> 8 & 0xff) * 0x40;
      iVar81 = (uStack_164 >> 0x10 & 0xff) * 0x40;
      iVar92 = (auStack_1a0[1] >> 0x10 & 0xff) * 0x40;
      iVar86 = (auStack_1a0[3] >> 0x18) * 0x40;
      iVar78 = (auStack_1a0[4] & 0xff) * 0x40;
      iVar74 = (auStack_1a0[6] >> 8 & 0xff) * 0x40;
      iVar89 = (uStack_178 >> 0x18) * 0x40;
      iVar64 = (uStack_180 >> 0x10 & 0xff) * 0x40;
      iVar54 = (uStack_16c & 0xff) * 0x40;
      iVar29 = (auStack_1a0[3] >> 0x10 & 0xff) * 0x40;
      iVar44 = (uStack_164 >> 8 & 0xff) * 0x40;
      iVar36 = (auStack_1a0[1] >> 8 & 0xff) * 0x40;
      iVar75 = (uStack_170 >> 0x18) * 0x40;
      iVar57 = (auStack_1a0[5] >> 0x18) * 0x40;
      iVar82 = (auStack_1a0[6] & 0xff) * 0x40;
      iVar45 = (uStack_180 >> 8 & 0xff) * 0x40;
      iVar37 = (uStack_178 >> 0x10 & 0xff) * 0x40;
      iVar30 = (uStack_164 & 0xff) * 0x40;
      uStack_168 = *(uint *)(Cx + iVar50 + 8) ^
                   *(uint *)(Cx + iVar58 + 0x10) ^
                   *(uint *)(Cx + iVar67 + 0x18) ^
                   *(uint *)(Cx + iVar38 + 0x20) ^
                   *(uint *)(Cx + iVar46 + 0x28) ^
                   *(uint *)(Cx + iVar55) ^
                   *(uint *)(Cx + iVar68 + 0x38) ^ *(uint *)(Cx + iVar31 + 0x30) ^ uStack_128;
      uStack_164 = *(uint *)(Cx + iVar50 + 0xc) ^
                   *(uint *)(Cx + iVar58 + 0x14) ^
                   *(uint *)(Cx + iVar67 + 0x1c) ^
                   *(uint *)(Cx + iVar38 + 0x24) ^
                   *(uint *)(Cx + iVar46 + 0x2c) ^
                   *(uint *)(Cx + iVar55 + 4) ^
                   *(uint *)(Cx + iVar68 + 0x3c) ^ *(uint *)(Cx + iVar31 + 0x34) ^ uStack_124;
      auStack_1a0[0] =
           *(uint *)(Cx + iVar90 + 8) ^
           *(uint *)(Cx + iVar95 + 0x10) ^
           *(uint *)(Cx + iVar96 + 0x18) ^
           *(uint *)(Cx + iVar93 + 0x20) ^
           *(uint *)(Cx + iVar94 + 0x28) ^
           *(uint *)(Cx + iVar76) ^ *(uint *)(Cx + iVar25 + 0x38) ^ *(uint *)(Cx + iVar32 + 0x30) ^
           uStack_160;
      auStack_1a0[1] =
           *(uint *)(Cx + iVar90 + 0xc) ^
           *(uint *)(Cx + iVar95 + 0x14) ^
           *(uint *)(Cx + iVar96 + 0x1c) ^
           *(uint *)(Cx + iVar93 + 0x24) ^
           *(uint *)(Cx + iVar94 + 0x2c) ^
           *(uint *)(Cx + iVar76 + 4) ^
           *(uint *)(Cx + iVar25 + 0x3c) ^ *(uint *)(Cx + iVar32 + 0x34) ^ uStack_15c;
      uStack_17c = *(uint *)(Cx + iVar81 + 0x2c) ^
                   *(uint *)(Cx + iVar28 + 0x34) ^
                   *(uint *)(Cx + iVar35 + 0x3c) ^
                   *(uint *)(Cx + iVar43 + 0xc) ^
                   *(uint *)(Cx + iVar53 + 0x14) ^
                   *(uint *)(Cx + iVar72 + 4) ^
                   *(uint *)(Cx + iVar91 + 0x24) ^ *(uint *)(Cx + iVar63 + 0x1c) ^ uStack_13c;
      auStack_1a0[2] =
           *(uint *)(Cx + iVar41 + 0x10) ^
           *(uint *)(Cx + iVar51 + 0x18) ^
           *(uint *)(Cx + iVar59 + 0x20) ^
           *(uint *)(Cx + iVar65 + 0x28) ^
           *(uint *)(Cx + iVar70 + 0x30) ^
           *(uint *)(Cx + iVar83) ^ *(uint *)(Cx + iVar79 + 8) ^ *(uint *)(Cx + iVar77 + 0x38) ^
           uStack_158;
      auStack_1a0[3] =
           *(uint *)(Cx + iVar41 + 0x14) ^
           *(uint *)(Cx + iVar51 + 0x1c) ^
           *(uint *)(Cx + iVar59 + 0x24) ^
           *(uint *)(Cx + iVar65 + 0x2c) ^
           *(uint *)(Cx + iVar70 + 0x34) ^
           *(uint *)(Cx + iVar83 + 4) ^ *(uint *)(Cx + iVar79 + 0xc) ^ *(uint *)(Cx + iVar77 + 0x3c)
           ^ uStack_154;
      auStack_1a0[5] =
           *(uint *)(Cx + iVar60 + 0x1c) ^
           *(uint *)(Cx + iVar66 + 0x24) ^
           *(uint *)(Cx + iVar84 + 0x2c) ^
           *(uint *)(Cx + iVar80 + 0x34) ^
           *(uint *)(Cx + iVar87 + 0x3c) ^
           *(uint *)(Cx + iVar73 + 4) ^ *(uint *)(Cx + iVar33 + 0x14) ^ *(uint *)(Cx + iVar26 + 0xc)
           ^ uStack_14c;
      auStack_1a0[6] =
           *(uint *)(Cx + iVar69 + 0x20) ^
           *(uint *)(Cx + iVar88 + 0x28) ^
           *(uint *)(Cx + iVar85 + 0x30) ^
           *(uint *)(Cx + iVar27 + 0x38) ^
           *(uint *)(Cx + iVar34 + 8) ^
           *(uint *)(Cx + iVar71) ^ *(uint *)(Cx + iVar52 + 0x18) ^ *(uint *)(Cx + iVar42 + 0x10) ^
           uStack_148;
      uStack_184 = *(uint *)(Cx + iVar69 + 0x24) ^
                   *(uint *)(Cx + iVar88 + 0x2c) ^
                   *(uint *)(Cx + iVar85 + 0x34) ^
                   *(uint *)(Cx + iVar27 + 0x3c) ^
                   *(uint *)(Cx + iVar34 + 0xc) ^
                   *(uint *)(Cx + iVar71 + 4) ^
                   *(uint *)(Cx + iVar52 + 0x1c) ^ *(uint *)(Cx + iVar42 + 0x14) ^ uStack_144;
      uStack_180 = *(uint *)(Cx + iVar81 + 0x28) ^
                   *(uint *)(Cx + iVar28 + 0x30) ^
                   *(uint *)(Cx + iVar35 + 0x38) ^
                   *(uint *)(Cx + iVar43 + 8) ^
                   *(uint *)(Cx + iVar53 + 0x10) ^
                   *(uint *)(Cx + iVar72) ^
                   *(uint *)(Cx + iVar91 + 0x20) ^ *(uint *)(Cx + iVar63 + 0x18) ^ uStack_140;
      auStack_1a0[4] =
           *(uint *)(Cx + iVar60 + 0x18) ^
           *(uint *)(Cx + iVar66 + 0x20) ^
           *(uint *)(Cx + iVar84 + 0x28) ^
           *(uint *)(Cx + iVar80 + 0x30) ^
           *(uint *)(Cx + iVar87 + 0x38) ^
           *(uint *)(Cx + iVar73) ^ *(uint *)(Cx + iVar33 + 0x10) ^ *(uint *)(Cx + iVar26 + 8) ^
           uStack_150;
      uStack_174 = *(uint *)(Cx + iVar44 + 0x34) ^
                   *(uint *)(Cx + iVar54 + 0x3c) ^
                   *(uint *)(Cx + iVar64 + 0xc) ^
                   *(uint *)(Cx + iVar74 + 0x14) ^
                   *(uint *)(Cx + iVar78 + 0x1c) ^
                   *(uint *)(Cx + iVar89 + 4) ^
                   *(uint *)(Cx + iVar92 + 0x2c) ^ *(uint *)(Cx + iVar86 + 0x24) ^ uStack_134;
      uStack_170 = *(uint *)(Cx + iVar30 + 0x38) ^
                   *(uint *)(Cx + iVar37 + 8) ^
                   *(uint *)(Cx + iVar45 + 0x10) ^
                   *(uint *)(Cx + iVar82 + 0x18) ^
                   *(uint *)(Cx + iVar57 + 0x20) ^
                   *(uint *)(Cx + iVar75) ^
                   *(uint *)(Cx + iVar36 + 0x30) ^ *(uint *)(Cx + iVar29 + 0x28) ^ uStack_130;
      uStack_178 = *(uint *)(Cx + iVar44 + 0x30) ^
                   *(uint *)(Cx + iVar54 + 0x38) ^
                   *(uint *)(Cx + iVar64 + 8) ^
                   *(uint *)(Cx + iVar74 + 0x10) ^
                   *(uint *)(Cx + iVar78 + 0x18) ^
                   *(uint *)(Cx + iVar89) ^
                   *(uint *)(Cx + iVar92 + 0x28) ^ *(uint *)(Cx + iVar86 + 0x20) ^ uStack_138;
      uStack_16c = *(uint *)(Cx + iVar30 + 0x3c) ^
                   *(uint *)(Cx + iVar37 + 0xc) ^
                   *(uint *)(Cx + iVar45 + 0x14) ^
                   *(uint *)(Cx + iVar82 + 0x1c) ^
                   *(uint *)(Cx + iVar57 + 0x24) ^
                   *(uint *)(Cx + iVar75 + 4) ^
                   *(uint *)(Cx + iVar36 + 0x34) ^ *(uint *)(Cx + iVar29 + 0x2c) ^ uStack_12c;
      puVar24 = puVar62;
    } while (puVar62 != (uint *)shifts2_6299);
    if (((uint)pWStack_200 & 7) == 0) {
      uVar48 = *(uint *)((int)&pWStack_200->H + 4);
      *puVar39 = uVar40 ^ *(uint *)&pWStack_200->H ^ auStack_1a0[0];
      puVar39[1] = uVar49 ^ uVar48 ^ auStack_1a0[1];
      uVar40 = *(uint *)((int)&pWStack_200->H + 0xc);
      puVar39[2] = uVar56 ^ *(uint *)((int)&pWStack_200->H + 8) ^ auStack_1a0[2];
      puVar39[3] = uVar10 ^ uVar40 ^ auStack_1a0[3];
      uVar40 = *(uint *)((int)&pWStack_200->H + 0x14);
      puVar39[4] = uVar11 ^ *(uint *)((int)&pWStack_200->H + 0x10) ^ auStack_1a0[4];
      puVar39[5] = uVar12 ^ uVar40 ^ auStack_1a0[5];
      uVar40 = *(uint *)((int)&pWStack_200->H + 0x1c);
      puVar39[6] = uVar13 ^ *(uint *)((int)&pWStack_200->H + 0x18) ^ auStack_1a0[6];
      puVar39[7] = uVar14 ^ uVar40 ^ uStack_184;
      uVar40 = *(uint *)((int)&pWStack_200->H + 0x24);
      puVar39[8] = uVar15 ^ *(uint *)((int)&pWStack_200->H + 0x20) ^ uStack_180;
      puVar39[9] = uVar16 ^ uVar40 ^ uStack_17c;
      uVar40 = *(uint *)((int)&pWStack_200->H + 0x2c);
      puVar39[10] = uVar17 ^ *(uint *)((int)&pWStack_200->H + 0x28) ^ uStack_178;
      puVar39[0xb] = uVar18 ^ uVar40 ^ uStack_174;
      uVar40 = *(uint *)((int)&pWStack_200->H + 0x34);
      puVar39[0xc] = uVar19 ^ *(uint *)((int)&pWStack_200->H + 0x30) ^ uStack_170;
      puVar39[0xd] = uVar20 ^ uVar40 ^ uStack_16c;
      uVar40 = *(uint *)((int)&pWStack_200->H + 0x3c);
      pbVar47 = (byte *)(uVar21 ^ *(uint *)((int)&pWStack_200->H + 0x38));
      puVar39[0xe] = (uint)pbVar47 ^ uStack_168;
      puVar39[0xf] = uVar22 ^ uVar40 ^ uStack_164;
    }
    else if ((puVar39 < (uint *)((int)&pWStack_200->H + 4) &&
              pWStack_200 < (WHIRLPOOL_CTX *)(puVar39 + 1)) || (((uint)pWStack_200 & 3) != 0)) {
      puVar24 = puVar39;
      puVar62 = auStack_1a0;
      do {
        puVar61 = (uint *)((int)puVar62 + 1);
        p_Var8 = &pWStack_200->H;
        pbVar47 = (byte *)(uint)p_Var8->c[0];
        pWStack_200 = (WHIRLPOOL_CTX *)((int)&pWStack_200->H + 1);
        *(byte *)puVar24 = *(byte *)puVar62 ^ *(byte *)puVar24 ^ p_Var8->c[0];
        puVar24 = (uint *)((int)puVar24 + 1);
        puVar62 = puVar61;
      } while (puVar61 != &uStack_160);
    }
    else {
      *puVar39 = auStack_1a0[0] ^ *puVar39 ^ *(uint *)&pWStack_200->H;
      puVar39[1] = auStack_1a0[1] ^ puVar39[1] ^ *(uint *)((int)&pWStack_200->H + 4);
      puVar39[2] = auStack_1a0[2] ^ puVar39[2] ^ *(uint *)((int)&pWStack_200->H + 8);
      puVar39[3] = puVar39[3] ^ auStack_1a0[3] ^ *(uint *)((int)&pWStack_200->H + 0xc);
      puVar39[4] = puVar39[4] ^ auStack_1a0[4] ^ *(uint *)((int)&pWStack_200->H + 0x10);
      puVar39[5] = puVar39[5] ^ auStack_1a0[5] ^ *(uint *)((int)&pWStack_200->H + 0x14);
      puVar39[6] = puVar39[6] ^ auStack_1a0[6] ^ *(uint *)((int)&pWStack_200->H + 0x18);
      puVar39[7] = puVar39[7] ^ uStack_184 ^ *(uint *)((int)&pWStack_200->H + 0x1c);
      puVar39[8] = puVar39[8] ^ uStack_180 ^ *(uint *)((int)&pWStack_200->H + 0x20);
      puVar39[9] = puVar39[9] ^ uStack_17c ^ *(uint *)((int)&pWStack_200->H + 0x24);
      puVar39[10] = puVar39[10] ^ uStack_178 ^ *(uint *)((int)&pWStack_200->H + 0x28);
      pbVar47 = (byte *)puVar39[0xe];
      puVar39[0xb] = uStack_174 ^ puVar39[0xb] ^ *(uint *)((int)&pWStack_200->H + 0x2c);
      puVar39[0xc] = puVar39[0xc] ^ uStack_170 ^ *(uint *)((int)&pWStack_200->H + 0x30);
      puVar39[0xd] = puVar39[0xd] ^ uStack_16c ^ *(uint *)((int)&pWStack_200->H + 0x34);
      puVar39[0xe] = (uint)pbVar47 ^ uStack_168 ^ *(uint *)((int)&pWStack_200->H + 0x38);
      puVar39[0xf] = puVar39[0xf] ^ uStack_164 ^ *(uint *)((int)&pWStack_200->H + 0x3c);
    }
    uStack_e8 = uStack_e8 - 1;
    pWStack_200 = (WHIRLPOOL_CTX *)puStack_1fc;
  } while (uStack_e8 != 0);
  if (puStack_11c != *(uchar **)puVar9) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    bVar1 = odd_parity[pbVar47[1]];
    bVar2 = odd_parity[pbVar47[2]];
    bVar3 = odd_parity[pbVar47[3]];
    bVar4 = odd_parity[pbVar47[4]];
    bVar5 = odd_parity[pbVar47[5]];
    bVar6 = odd_parity[pbVar47[6]];
    bVar7 = odd_parity[pbVar47[7]];
    *pbVar47 = odd_parity[*pbVar47];
    pbVar47[1] = bVar1;
    pbVar47[2] = bVar2;
    pbVar47[3] = bVar3;
    pbVar47[4] = bVar4;
    pbVar47[5] = bVar5;
    pbVar47[6] = bVar6;
    pbVar47[7] = bVar7;
    return (uchar *)(uint)bVar7;
  }
  return *(uchar **)puVar9;
}

