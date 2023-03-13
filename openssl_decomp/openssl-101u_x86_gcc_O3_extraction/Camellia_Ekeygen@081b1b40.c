
undefined4 Camellia_Ekeygen(int param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
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
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint local_2c;
  uint local_20;
  
  uVar13 = *param_2;
  uVar12 = uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8;
  uVar1 = uVar12 | uVar13 << 0x18;
  *param_3 = uVar1;
  uVar9 = param_2[1];
  uVar18 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8;
  uVar2 = uVar18 | uVar9 << 0x18;
  param_3[1] = uVar2;
  uVar7 = param_2[2];
  uVar17 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8;
  uVar3 = uVar17 | uVar7 << 0x18;
  param_3[2] = uVar3;
  uVar8 = param_2[3];
  uVar6 = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8;
  uVar4 = uVar6 | uVar8 << 0x18;
  param_3[3] = uVar4;
  if (param_1 == 0x80) {
    local_20 = 0;
    uVar5 = uVar1;
    uVar10 = uVar3;
    uVar14 = uVar4;
    local_2c = uVar2;
  }
  else {
    uVar5 = param_2[4];
    local_20 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
    param_3[8] = local_20;
    uVar5 = param_2[5];
    uVar19 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
    param_3[9] = uVar19;
    if (param_1 == 0xc0) {
      uVar10 = ~local_20;
      uVar14 = ~uVar19;
      param_3[10] = uVar10;
      param_3[0xb] = uVar14;
    }
    else {
      uVar5 = param_2[6];
      uVar10 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      param_3[10] = uVar10;
      uVar5 = param_2[7];
      uVar14 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      param_3[0xb] = uVar14;
    }
    uVar5 = local_20 ^ uVar1;
    uVar10 = uVar10 ^ uVar3;
    uVar14 = uVar14 ^ uVar4;
    local_2c = uVar19 ^ uVar2;
  }
  uVar5 = uVar5 ^ 0xa09e667f;
  uVar19 = local_2c ^ 0x3bcc908b;
  uVar20 = *(uint *)(&DAT_08236b00 + (uVar5 & 0xff) * 4) ^
           *(uint *)(&Camellia_SBOX + (uVar5 >> 0x18) * 4) ^
           *(uint *)(&DAT_08237300 + (uVar5 >> 8 & 0xff) * 4) ^
           *(uint *)(&DAT_08236f00 + (uVar5 >> 0x10 & 0xff) * 4);
  uVar5 = uVar20 ^ *(uint *)(&Camellia_SBOX + (uVar19 & 0xff) * 4) ^
                   *(uint *)(&DAT_08236f00 + (uVar19 >> 0x18) * 4) ^
                   *(uint *)(&DAT_08236b00 + (uVar19 >> 8 & 0xff) * 4) ^
                   *(uint *)(&DAT_08237300 + (uVar19 >> 0x10 & 0xff) * 4);
  uVar10 = uVar10 ^ uVar5;
  uVar5 = (uVar20 >> 8 | uVar20 << 0x18) ^ uVar14 ^ uVar5;
  uVar14 = uVar10 ^ 0xb67ae858;
  uVar19 = uVar5 ^ 0x4caa73b2;
  uVar14 = *(uint *)(&DAT_08236b00 + (uVar14 & 0xff) * 4) ^
           *(uint *)(&Camellia_SBOX + (uVar14 >> 0x18) * 4) ^
           *(uint *)(&DAT_08237300 + (uVar14 >> 8 & 0xff) * 4) ^
           *(uint *)(&DAT_08236f00 + (uVar14 >> 0x10 & 0xff) * 4);
  uVar19 = uVar14 ^ *(uint *)(&Camellia_SBOX + (uVar19 & 0xff) * 4) ^
                    *(uint *)(&DAT_08236f00 + (uVar19 >> 0x18) * 4) ^
                    *(uint *)(&DAT_08236b00 + (uVar19 >> 8 & 0xff) * 4) ^
                    *(uint *)(&DAT_08237300 + (uVar19 >> 0x10 & 0xff) * 4);
  local_20 = local_20 ^ uVar19;
  uVar19 = local_2c ^ uVar2 ^ (uVar14 >> 8 | uVar14 << 0x18) ^ uVar19;
  uVar14 = local_20 ^ 0xc6ef372f;
  uVar20 = uVar19 ^ 0xe94f82be;
  uVar14 = *(uint *)(&DAT_08236b00 + (uVar14 & 0xff) * 4) ^
           *(uint *)(&Camellia_SBOX + (uVar14 >> 0x18) * 4) ^
           *(uint *)(&DAT_08237300 + (uVar14 >> 8 & 0xff) * 4) ^
           *(uint *)(&DAT_08236f00 + (uVar14 >> 0x10 & 0xff) * 4);
  uVar20 = uVar14 ^ *(uint *)(&Camellia_SBOX + (uVar20 & 0xff) * 4) ^
                    *(uint *)(&DAT_08236f00 + (uVar20 >> 0x18) * 4) ^
                    *(uint *)(&DAT_08236b00 + (uVar20 >> 8 & 0xff) * 4) ^
                    *(uint *)(&DAT_08237300 + (uVar20 >> 0x10 & 0xff) * 4);
  uVar10 = uVar10 ^ uVar3 ^ uVar20;
  uVar20 = (uVar14 >> 8 | uVar14 << 0x18) ^ uVar4 ^ uVar5 ^ uVar20;
  uVar23 = uVar20 ^ 0xf1d36f1c;
  uVar5 = uVar10 ^ 0x54ff53a5;
  uVar14 = *(uint *)(&DAT_08236b00 + (uVar5 & 0xff) * 4) ^
           *(uint *)(&Camellia_SBOX + (uVar5 >> 0x18) * 4) ^
           *(uint *)(&DAT_08237300 + (uVar5 >> 8 & 0xff) * 4) ^
           *(uint *)(&DAT_08236f00 + (uVar5 >> 0x10 & 0xff) * 4);
  uVar5 = *(uint *)(&Camellia_SBOX + (uVar23 & 0xff) * 4) ^
          *(uint *)(&DAT_08236f00 + (uVar23 >> 0x18) * 4) ^
          *(uint *)(&DAT_08236b00 + (uVar23 >> 8 & 0xff) * 4) ^
          *(uint *)(&DAT_08237300 + (uVar23 >> 0x10 & 0xff) * 4) ^ uVar14;
  local_20 = local_20 ^ uVar5;
  uVar5 = uVar19 ^ (uVar14 >> 8 | uVar14 << 0x18) ^ uVar5;
  if (param_1 != 0x80) {
    uVar14 = local_20 ^ param_3[8] ^ 0x10e527fa;
    uVar19 = uVar5 ^ param_3[9] ^ 0xde682d1d;
    uVar23 = *(uint *)(&DAT_08236b00 + (uVar14 & 0xff) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar14 >> 0x18) * 4) ^
             *(uint *)(&DAT_08237300 + (uVar14 >> 8 & 0xff) * 4) ^
             *(uint *)(&DAT_08236f00 + (uVar14 >> 0x10 & 0xff) * 4);
    uVar14 = *(uint *)(&Camellia_SBOX + (uVar19 & 0xff) * 4) ^
             *(uint *)(&DAT_08236f00 + (uVar19 >> 0x18) * 4) ^
             *(uint *)(&DAT_08236b00 + (uVar19 >> 8 & 0xff) * 4) ^
             *(uint *)(&DAT_08237300 + (uVar19 >> 0x10 & 0xff) * 4) ^ uVar23;
    uVar19 = uVar14 ^ uVar10 ^ param_3[10];
    uVar24 = (uVar23 >> 8 | uVar23 << 0x18) ^ uVar20 ^ param_3[0xb] ^ uVar14;
    uVar25 = uVar24 ^ 0xb3e6c1fd;
    param_3[6] = uVar19;
    uVar14 = uVar19 ^ 0xb05688c2;
    uVar23 = *(uint *)(&DAT_08236b00 + (uVar14 & 0xff) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar14 >> 0x18) * 4) ^
             *(uint *)(&DAT_08237300 + (uVar14 >> 8 & 0xff) * 4) ^
             *(uint *)(&DAT_08236f00 + (uVar14 >> 0x10 & 0xff) * 4);
    uVar25 = uVar23 ^ *(uint *)(&Camellia_SBOX + (uVar25 & 0xff) * 4) ^
                      *(uint *)(&DAT_08236f00 + (uVar25 >> 0x18) * 4) ^
             *(uint *)(&DAT_08236b00 + (uVar25 >> 8 & 0xff) * 4) ^
             *(uint *)(&DAT_08237300 + (uVar25 >> 0x10 & 0xff) * 4);
    param_3[7] = uVar24;
    uVar14 = local_20 ^ param_3[8] ^ uVar25;
    uVar25 = (uVar23 >> 8 | uVar23 << 0x18) ^ uVar5 ^ param_3[9] ^ uVar25;
    param_3[5] = uVar25;
    param_3[4] = uVar14;
    uVar21 = uVar19 >> 2 | uVar25 << 0x1e;
    uVar15 = uVar25 >> 2 | uVar14 << 0x1e;
    param_3[0x15] = uVar21;
    param_3[0x14] = uVar15;
    uVar23 = uVar19 << 0x1e | uVar24 >> 2;
    uVar21 = uVar21 >> 2;
    uVar11 = uVar24 << 0x1e | uVar14 >> 2;
    uVar15 = uVar15 >> 2;
    param_3[0x17] = uVar11;
    param_3[0x16] = uVar23;
    uVar25 = (uVar25 >> 2) << 0x1e | uVar21;
    uVar23 = uVar23 >> 2;
    param_3[0x28] = uVar25;
    uVar22 = (uVar19 >> 2) << 0x1e | uVar23;
    uVar14 = (uVar14 >> 2) << 0x1e | uVar15;
    uVar11 = uVar11 >> 2;
    uVar19 = (uVar24 >> 2) << 0x1e | uVar11;
    param_3[0x2b] = uVar14;
    param_3[0x2a] = uVar19;
    param_3[0x41] = uVar14 >> 0xd | uVar11 << 0x13;
    param_3[0x29] = uVar22;
    param_3[0x42] = uVar25 >> 0xd | uVar15 << 0x13;
    uVar14 = param_3[8];
    param_3[0x40] = uVar19 >> 0xd | uVar23 << 0x13;
    param_3[0x43] = uVar22 >> 0xd | uVar21 << 0x13;
    uVar11 = uVar14 << 0xf | param_3[9] >> 0x11;
    uVar19 = param_3[8];
    uVar23 = param_3[9];
    param_3[8] = uVar11;
    uVar15 = param_3[10] >> 0x11 | uVar23 << 0xf;
    uVar25 = param_3[10];
    param_3[9] = uVar15;
    uVar15 = uVar15 << 0xf;
    uVar26 = (uVar23 << 0xf) >> 0x11;
    uVar22 = param_3[0xb] >> 0x11 | uVar25 << 0xf;
    uVar23 = param_3[0xb];
    param_3[10] = uVar22;
    uVar16 = uVar19 >> 0x11 | uVar23 << 0xf;
    uVar11 = uVar11 << 0xf;
    param_3[0xb] = uVar16;
    uVar27 = uVar26 | uVar11;
    uVar22 = uVar22 << 0xf;
    uVar19 = (uVar25 << 0xf) >> 0x11;
    param_3[0x10] = uVar27;
    uVar21 = uVar15 | uVar19;
    uVar16 = uVar16 << 0xf;
    uVar23 = (uVar23 << 0xf) >> 0x11;
    param_3[0x11] = uVar21;
    uVar24 = uVar22 | uVar23;
    uVar14 = (uVar14 << 0xf) >> 0x11;
    uVar25 = uVar14 | uVar16;
    param_3[0x12] = uVar24;
    param_3[0x13] = uVar25;
    param_3[0x24] = uVar21 >> 2 | uVar26 << 0x1e;
    param_3[0x25] = uVar24 >> 2 | uVar19 << 0x1e;
    param_3[0x27] = uVar14 << 0x1e | uVar27 >> 2;
    param_3[0x26] = uVar23 << 0x1e | uVar25 >> 2;
    param_3[0x34] = uVar23 & 3 | uVar22 | uVar23 & 0xfffffffc;
    param_3[0x37] = uVar15 | uVar19 & 0xfffffffc | uVar19 & 3;
    param_3[0x35] = uVar14 & 3 | uVar14 & 0xfffffffc | uVar16;
    param_3[0x36] = uVar26 & 3 | uVar26 & 0xfffffffc | uVar11;
    uVar23 = uVar5 >> 0x11 | local_20 << 0xf;
    uVar25 = uVar5 << 0xf | uVar10 >> 0x11;
    param_3[0xd] = uVar25;
    param_3[0xc] = uVar23;
    uVar14 = uVar10 << 0xf | uVar20 >> 0x11;
    uVar25 = uVar25 >> 2;
    uVar19 = uVar20 << 0xf | local_20 >> 0x11;
    param_3[0xe] = uVar14;
    param_3[0xf] = uVar19;
    uVar11 = uVar25 | (uVar5 >> 0x11) << 0x1e;
    uVar14 = uVar14 >> 2;
    param_3[0x1c] = uVar11;
    param_3[0x33] = uVar11;
    uVar15 = (uVar10 >> 0x11) << 0x1e | uVar14;
    uVar19 = uVar19 >> 2;
    param_3[0x1d] = uVar15;
    param_3[0x30] = uVar15;
    uVar10 = (uVar20 >> 0x11) << 0x1e | uVar19;
    uVar23 = uVar23 >> 2;
    param_3[0x1e] = uVar10;
    param_3[0x31] = uVar10;
    uVar5 = uVar23 | (local_20 >> 0x11) << 0x1e;
    param_3[0x1f] = uVar5;
    param_3[0x32] = uVar5;
    param_3[0x38] = uVar10 >> 0xf | uVar14 << 0x11;
    param_3[0x39] = uVar5 >> 0xf | uVar19 << 0x11;
    param_3[0x3b] = uVar15 >> 0xf | uVar25 << 0x11;
    param_3[0x3a] = uVar23 << 0x11 | uVar11 >> 0xf;
    uVar19 = uVar3 >> 0x13 | uVar18 << 0xd;
    param_3[0x18] = uVar19;
    uVar5 = uVar17 << 0xd | uVar4 >> 0x13;
    param_3[0x19] = uVar5;
    uVar10 = uVar1 >> 0x13 | uVar6 << 0xd;
    uVar14 = uVar12 << 0xd | uVar2 >> 0x13;
    param_3[0x1a] = uVar10;
    param_3[0x1b] = uVar14;
    param_3[0x20] = (uVar17 << 0xd) >> 0x11 | uVar19 << 0xf;
    param_3[0x21] = uVar5 << 0xf | (uVar6 << 0xd) >> 0x11;
    uVar6 = (uVar6 & 0x7fff0) << 0xd;
    param_3[0x22] = uVar10 << 0xf | (uVar12 << 0xd) >> 0x11;
    uVar17 = (uVar17 & 0x7fff0) << 0xd;
    param_3[0x23] = (uVar18 << 0xd) >> 0x11 | uVar14 << 0xf;
    uVar4 = uVar17 | (uVar7 >> 0x18 & 0xf) << 0xd | uVar4 >> 0x13;
    uVar12 = (uVar12 & 0x7fff0) << 0xd;
    param_3[0x2c] = uVar4;
    uVar7 = uVar6 | uVar1 >> 0x13 | (uVar8 >> 0x18 & 0xf) << 0xd;
    uVar8 = (uVar18 & 0x7fff0) << 0xd;
    uVar9 = uVar8 | uVar3 >> 0x13 | (uVar9 >> 0x18 & 0xf) << 0xd;
    param_3[0x2d] = uVar7;
    uVar13 = uVar12 | (uVar13 >> 0x18 & 0xf) << 0xd | uVar2 >> 0x13;
    param_3[0x2f] = uVar9;
    param_3[0x2e] = uVar13;
    param_3[0x3c] = uVar12 >> 0x1e | uVar7 * 4;
    param_3[0x3f] = uVar6 >> 0x1e | uVar4 * 4;
    param_3[0x3d] = uVar8 >> 0x1e | uVar13 * 4;
    param_3[0x3e] = uVar17 >> 0x1e | uVar9 * 4;
    return 4;
  }
  param_3[4] = local_20;
  param_3[5] = uVar5;
  uVar13 = local_20 << 0xf | uVar5 >> 0x11;
  param_3[6] = uVar10;
  param_3[7] = uVar20;
  uVar8 = uVar10 >> 0x11 | uVar5 << 0xf;
  param_3[0xd] = uVar8;
  uVar9 = uVar10 << 0xf | uVar20 >> 0x11;
  uVar23 = uVar20 << 0xf | local_20 >> 0x11;
  uVar8 = uVar8 << 0xf;
  uVar14 = uVar13 << 0xf;
  param_3[0xc] = uVar13;
  param_3[0xe] = uVar9;
  uVar13 = uVar14 | (uVar5 << 0xf) >> 0x11;
  param_3[0xf] = uVar23;
  uVar9 = uVar9 << 0xf;
  uVar10 = uVar8 | (uVar10 << 0xf) >> 0x11;
  uVar23 = uVar23 << 0xf;
  uVar25 = uVar23 | (local_20 << 0xf) >> 0x11;
  uVar5 = uVar9 | (uVar20 << 0xf) >> 0x11;
  uVar7 = uVar13 << 0xf;
  param_3[0x11] = uVar10;
  uVar10 = uVar10 << 0xf;
  uVar8 = uVar8 >> 0x11 | uVar7;
  param_3[0x12] = uVar5;
  uVar5 = uVar5 << 0xf;
  param_3[0x13] = uVar25;
  uVar19 = uVar10 | uVar9 >> 0x11;
  param_3[0x10] = uVar13;
  param_3[0x19] = uVar19;
  param_3[0x18] = uVar8;
  uVar25 = uVar25 << 0xf;
  uVar19 = uVar19 << 0xf;
  uVar8 = uVar8 << 0xf;
  uVar9 = uVar10 >> 0x11 | uVar8;
  uVar10 = (uVar5 | uVar23 >> 0x11) << 0xf;
  param_3[0x1c] = uVar9;
  uVar13 = uVar19 | uVar5 >> 0x11;
  uVar20 = (uVar25 | uVar14 >> 0x11) << 0xf;
  uVar23 = uVar20 | uVar7 >> 0x11;
  param_3[0x1d] = uVar13;
  uVar5 = uVar10 | uVar25 >> 0x11;
  uVar13 = uVar13 * 4;
  param_3[0x1f] = uVar23;
  param_3[0x1e] = uVar5;
  uVar5 = uVar5 << 2;
  uVar14 = uVar10 >> 0x1e | uVar13;
  uVar23 = uVar23 << 2;
  param_3[0x28] = uVar14;
  uVar10 = uVar5 | uVar20 >> 0x1e;
  param_3[0x29] = uVar10;
  uVar7 = uVar8 >> 0x1e | uVar23;
  uVar9 = uVar9 * 4;
  param_3[0x2a] = uVar7;
  uVar8 = uVar19 >> 0x1e | uVar9;
  param_3[0x2b] = uVar8;
  param_3[0x31] = uVar23 >> 0xf | uVar10 << 0x11;
  param_3[0x30] = uVar5 >> 0xf | uVar14 << 0x11;
  param_3[0x32] = uVar9 >> 0xf | uVar7 << 0x11;
  param_3[0x33] = uVar8 << 0x11 | uVar13 >> 0xf;
  uVar10 = uVar2 >> 0x11 | uVar12 << 0xf;
  param_3[8] = uVar10;
  uVar5 = uVar3 >> 0x11 | uVar18 << 0xf;
  param_3[9] = uVar5;
  uVar9 = uVar4 >> 0x11 | uVar17 << 0xf;
  uVar7 = uVar1 >> 0x11 | uVar6 << 0xf;
  uVar5 = uVar5 >> 2;
  uVar13 = (uVar2 >> 0x11) << 0x1e;
  uVar2 = (uVar3 >> 0x11) << 0x1e;
  param_3[10] = uVar9;
  uVar14 = uVar5 | uVar13;
  uVar3 = (uVar4 >> 0x11) << 0x1e;
  uVar9 = uVar9 >> 2;
  param_3[0xb] = uVar7;
  param_3[0x14] = uVar14;
  uVar7 = uVar7 >> 2;
  param_3[0x15] = uVar2 | uVar9;
  uVar8 = (uVar1 >> 0x11) << 0x1e;
  uVar10 = uVar10 >> 2;
  uVar1 = uVar10 | uVar8;
  param_3[0x16] = uVar3 | uVar7;
  param_3[0x17] = uVar1;
  uVar9 = uVar9 & 0x1ffff;
  param_3[0x1a] = uVar7 << 0xf | uVar1 >> 0x11;
  uVar1 = uVar9 | uVar2 | (uVar17 << 0xf & 0xfff80000) >> 2;
  param_3[0x1b] = uVar10 << 0xf | uVar14 >> 0x11;
  param_3[0x20] = uVar1;
  uVar17 = uVar3 | (uVar6 << 0xf & 0xfff80000) >> 2 | uVar7 & 0x1ffff;
  param_3[0x21] = uVar17;
  uVar8 = (uVar12 << 0xf & 0xfff80000) >> 2 | uVar8 | uVar10 & 0x1ffff;
  uVar5 = uVar5 & 0x1ffff;
  uVar17 = uVar17 >> 0xf;
  uVar13 = uVar5 | (uVar18 << 0xf & 0xfff80000) >> 2 | uVar13;
  param_3[0x22] = uVar8;
  param_3[0x23] = uVar13;
  uVar18 = uVar9 << 0x11 | uVar17;
  uVar8 = uVar8 >> 0xf;
  param_3[0x24] = uVar18;
  uVar7 = (uVar7 & 0x1ffff) << 0x11 | uVar8;
  uVar13 = uVar13 >> 0xf;
  param_3[0x25] = uVar7;
  uVar12 = (uVar10 & 0x1ffff) << 0x11 | uVar13;
  uVar1 = uVar1 >> 0xf;
  uVar9 = uVar5 << 0x11 | uVar1;
  param_3[0x27] = uVar9;
  param_3[0x26] = uVar12;
  param_3[0x2c] = uVar7 >> 0xf | uVar17 << 0x11;
  param_3[0x2d] = uVar12 >> 0xf | uVar8 << 0x11;
  param_3[0x2f] = uVar18 >> 0xf | uVar1 << 0x11;
  param_3[0x2e] = uVar9 >> 0xf | uVar13 << 0x11;
  return 3;
}

