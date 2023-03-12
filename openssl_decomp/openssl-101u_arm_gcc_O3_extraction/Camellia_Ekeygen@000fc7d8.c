
undefined4 Camellia_Ekeygen(int param_1,byte *param_2,uint *param_3)

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
  
  uVar4 = (uint)param_2[1] << 0x10 | (uint)*param_2 << 0x18;
  uVar13 = uVar4 ^ param_2[3] | (uint)param_2[2] << 8;
  *param_3 = uVar13;
  uVar5 = (uint)param_2[5] << 0x10 | (uint)param_2[4] << 0x18;
  uVar15 = uVar5 ^ param_2[7] | (uint)param_2[6] << 8;
  param_3[1] = uVar15;
  uVar6 = (uint)param_2[9] << 0x10 | (uint)param_2[8] << 0x18;
  uVar1 = uVar6 ^ param_2[0xb] | (uint)param_2[10] << 8;
  param_3[2] = uVar1;
  uVar7 = (uint)param_2[0xd] << 0x10 | (uint)param_2[0xc] << 0x18;
  uVar9 = uVar7 ^ param_2[0xf] | (uint)param_2[0xe] << 8;
  param_3[3] = uVar9;
  if (param_1 == 0x80) {
    uVar2 = 0;
    uVar8 = 0;
    uVar3 = uVar15;
    uVar10 = uVar9;
    uVar17 = uVar1;
    uVar14 = uVar13;
  }
  else {
    uVar2 = ((uint)param_2[0x11] << 0x10 | (uint)param_2[0x10] << 0x18) ^ (uint)param_2[0x13] |
            (uint)param_2[0x12] << 8;
    param_3[8] = uVar2;
    uVar8 = ((uint)param_2[0x15] << 0x10 | (uint)param_2[0x14] << 0x18) ^ (uint)param_2[0x17] |
            (uint)param_2[0x16] << 8;
    param_3[9] = uVar8;
    if (param_1 == 0xc0) {
      uVar17 = ~uVar2;
      uVar10 = ~uVar8;
      param_3[10] = uVar17;
      param_3[0xb] = uVar10;
    }
    else {
      uVar17 = ((uint)param_2[0x19] << 0x10 | (uint)param_2[0x18] << 0x18) ^ (uint)param_2[0x1b] |
               (uint)param_2[0x1a] << 8;
      param_3[10] = uVar17;
      uVar10 = ((uint)param_2[0x1d] << 0x10 | (uint)param_2[0x1c] << 0x18) ^ (uint)param_2[0x1f] |
               (uint)param_2[0x1e] << 8;
      param_3[0xb] = uVar10;
    }
    uVar3 = uVar8 ^ uVar15;
    uVar10 = uVar10 ^ uVar9;
    uVar17 = uVar17 ^ uVar1;
    uVar14 = uVar2 ^ uVar13;
  }
  uVar14 = uVar14 ^ 0xa09e667f;
  uVar3 = uVar3 ^ 0x3bcc908b;
  uVar14 = *(uint *)(&Camellia_SBOX + ((uVar14 & 0xff) + 0x100) * 4) ^
           *(uint *)(&Camellia_SBOX + (uVar14 >> 0x18) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar14 << 0x10) >> 0x18) + 0x300) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar14 << 8) >> 0x18) + 0x200) * 4);
  uVar3 = *(uint *)(&Camellia_SBOX + (uVar3 & 0xff) * 4) ^
          *(uint *)(&Camellia_SBOX + ((uVar3 >> 0x18) + 0x200) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar3 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar3 << 8) >> 0x18) + 0x300) * 4) ^ uVar14;
  uVar17 = uVar3 ^ uVar17;
  uVar25 = uVar17 ^ 0xb67ae858;
  uVar10 = uVar3 ^ (uVar14 >> 8 | uVar14 << 0x18) ^ uVar10;
  uVar3 = uVar10 ^ 0x4caa73b2;
  uVar14 = *(uint *)(&Camellia_SBOX + ((uVar25 & 0xff) + 0x100) * 4) ^
           *(uint *)(&Camellia_SBOX + (uVar25 >> 0x18) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar25 << 0x10) >> 0x18) + 0x300) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar25 << 8) >> 0x18) + 0x200) * 4);
  uVar3 = *(uint *)(&Camellia_SBOX + (uVar3 & 0xff) * 4) ^
          *(uint *)(&Camellia_SBOX + ((uVar3 >> 0x18) + 0x200) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar3 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar3 << 8) >> 0x18) + 0x300) * 4) ^ uVar14;
  uVar2 = uVar2 ^ uVar3;
  uVar3 = uVar8 ^ (uVar14 >> 8 | uVar14 << 0x18) ^ uVar3;
  uVar8 = uVar2 ^ 0xc6ef372f;
  uVar14 = uVar3 ^ 0xe94f82be;
  uVar8 = *(uint *)(&Camellia_SBOX + ((uVar8 & 0xff) + 0x100) * 4) ^
          *(uint *)(&Camellia_SBOX + (uVar8 >> 0x18) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar8 << 0x10) >> 0x18) + 0x300) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar8 << 8) >> 0x18) + 0x200) * 4);
  uVar14 = *(uint *)(&Camellia_SBOX + (uVar14 & 0xff) * 4) ^
           *(uint *)(&Camellia_SBOX + ((uVar14 >> 0x18) + 0x200) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar14 << 0x10) >> 0x18) + 0x100) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar14 << 8) >> 0x18) + 0x300) * 4) ^ uVar8;
  uVar17 = uVar17 ^ uVar1 ^ uVar14;
  uVar14 = uVar10 ^ uVar9 ^ (uVar8 >> 8 | uVar8 << 0x18) ^ uVar14;
  uVar8 = uVar17 ^ 0x54ff53a5;
  uVar10 = uVar14 ^ 0xf1d36f1c;
  uVar8 = *(uint *)(&Camellia_SBOX + ((uVar8 & 0xff) + 0x100) * 4) ^
          *(uint *)(&Camellia_SBOX + (uVar8 >> 0x18) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar8 << 0x10) >> 0x18) + 0x300) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar8 << 8) >> 0x18) + 0x200) * 4);
  uVar10 = uVar8 ^ *(uint *)(&Camellia_SBOX + (((uVar10 << 8) >> 0x18) + 0x300) * 4) ^
                   *(uint *)(&Camellia_SBOX + (uVar10 & 0xff) * 4) ^
                   *(uint *)(&Camellia_SBOX + ((uVar10 >> 0x18) + 0x200) * 4) ^
                   *(uint *)(&Camellia_SBOX + (((uVar10 << 0x10) >> 0x18) + 0x100) * 4);
  uVar2 = uVar2 ^ uVar10;
  uVar10 = uVar10 ^ uVar3 ^ (uVar8 >> 8 | uVar8 << 0x18);
  if (param_1 != 0x80) {
    uVar3 = uVar2 ^ param_3[8] ^ 0x10e527fa;
    uVar8 = uVar10 ^ param_3[9] ^ 0xde682d1d;
    uVar25 = *(uint *)(&Camellia_SBOX + ((uVar3 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar3 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar3 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar3 << 8) >> 0x18) + 0x200) * 4);
    uVar11 = *(uint *)(&Camellia_SBOX + ((uVar8 >> 0x18) + 0x200) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar8 & 0xff) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar8 << 0x10) >> 0x18) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar8 << 8) >> 0x18) + 0x300) * 4) ^ uVar25;
    uVar3 = uVar17 ^ param_3[10] ^ uVar11;
    uVar21 = uVar3 ^ 0xb05688c2;
    uVar11 = uVar14 ^ param_3[0xb] ^ (uVar25 >> 8 | uVar25 << 0x18) ^ uVar11;
    uVar8 = uVar11 ^ 0xb3e6c1fd;
    uVar25 = *(uint *)(&Camellia_SBOX + ((uVar21 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar21 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar21 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar21 << 8) >> 0x18) + 0x200) * 4);
    uVar20 = *(uint *)(&Camellia_SBOX + (uVar8 & 0xff) * 4) ^
             *(uint *)(&Camellia_SBOX + ((uVar8 >> 0x18) + 0x200) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar8 << 0x10) >> 0x18) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar8 << 8) >> 0x18) + 0x300) * 4) ^ uVar25;
    uVar8 = param_3[8] << 0xf;
    uVar22 = uVar20 ^ uVar2 ^ param_3[8];
    uVar20 = uVar10 ^ param_3[9] ^ (uVar25 >> 8 | uVar25 << 0x18) ^ uVar20;
    uVar25 = uVar8 | param_3[9] >> 0x11;
    param_3[9] = param_3[9] << 0xf | param_3[10] >> 0x11;
    uVar19 = uVar3 >> 2 | uVar20 << 0x1e;
    param_3[10] = param_3[10] << 0xf | param_3[0xb] >> 0x11;
    param_3[7] = uVar11;
    uVar24 = uVar20 >> 2 | uVar22 << 0x1e;
    param_3[0xb] = param_3[8] >> 0x11 | param_3[0xb] << 0xf;
    uVar26 = uVar22 >> 2 | uVar11 << 0x1e;
    param_3[0x18] = uVar6 >> 0x13 | uVar15 << 0xd;
    param_3[0x1b] = uVar5 >> 0x13 | uVar13 << 0xd;
    param_3[0x1a] = uVar4 >> 0x13 | uVar9 << 0xd;
    uVar21 = param_3[9] >> 0x11;
    uVar4 = uVar25 << 0xf;
    uVar12 = uVar21 | uVar4;
    param_3[0x19] = uVar7 >> 0x13 | uVar1 << 0xd;
    uVar5 = uVar11 >> 2 | uVar3 << 0x1e;
    param_3[0x13] = uVar8 >> 0x11 | param_3[0xb] << 0xf;
    uVar16 = param_3[0xb] >> 0x11;
    uVar1 = param_3[10] << 0xf;
    uVar8 = uVar16 | uVar1;
    uVar23 = param_3[10] >> 0x11;
    uVar18 = uVar23 | param_3[9] << 0xf;
    param_3[0x20] = param_3[0x19] >> 0x11 | param_3[0x18] << 0xf;
    param_3[0x23] = param_3[0x18] >> 0x11 | param_3[0x1b] << 0xf;
    param_3[0xc] = uVar10 >> 0x11 | uVar2 << 0xf;
    param_3[0xf] = uVar2 >> 0x11 | uVar14 << 0xf;
    param_3[0xe] = uVar14 >> 0x11 | uVar17 << 0xf;
    param_3[0xd] = uVar17 >> 0x11 | uVar10 << 0xf;
    param_3[6] = uVar3;
    uVar6 = uVar26 >> 2;
    uVar7 = uVar6 | (uVar11 >> 2) << 0x1e;
    param_3[5] = uVar20;
    uVar9 = uVar5 >> 2;
    param_3[0x15] = uVar19;
    uVar13 = uVar9 | (uVar3 >> 2) << 0x1e;
    uVar19 = uVar19 >> 2;
    param_3[0x22] = param_3[0x1b] >> 0x11 | param_3[0x1a] << 0xf;
    uVar2 = param_3[0x1a];
    param_3[4] = uVar22;
    uVar14 = uVar19 | (uVar20 >> 2) << 0x1e;
    param_3[0x14] = uVar24;
    uVar24 = uVar24 >> 2;
    param_3[0x16] = uVar5;
    param_3[0x17] = uVar26;
    uVar5 = uVar24 | (uVar22 >> 2) << 0x1e;
    param_3[0x29] = uVar13;
    param_3[0x28] = uVar14;
    param_3[0x40] = uVar7 >> 0xd | uVar9 << 0x13;
    param_3[0x2b] = uVar5;
    param_3[0x2a] = uVar7;
    param_3[0x41] = uVar5 >> 0xd | uVar6 << 0x13;
    uVar9 = param_3[0x13];
    param_3[0x43] = uVar13 >> 0xd | uVar19 << 0x13;
    param_3[8] = uVar25;
    param_3[0x2f] = param_3[0x20] >> 0xf | param_3[0x23] << 0x11;
    param_3[0x10] = uVar12;
    uVar3 = param_3[0xd] >> 2 | param_3[0xc] << 0x1e;
    uVar13 = param_3[0xc] >> 2;
    uVar15 = uVar13 | param_3[0xf] << 0x1e;
    uVar6 = param_3[0xf] >> 2;
    uVar7 = uVar6 | param_3[0xe] << 0x1e;
    uVar10 = param_3[0xe] >> 2;
    uVar17 = uVar10 | param_3[0xd] << 0x1e;
    param_3[0x42] = uVar14 >> 0xd | uVar24 << 0x13;
    param_3[0x11] = uVar18;
    param_3[0x12] = uVar8;
    uVar5 = param_3[0x22] << 0x11;
    uVar25 = param_3[0x23] >> 0xf | uVar5;
    param_3[0x25] = uVar8 >> 2 | uVar23 << 0x1e;
    param_3[0x24] = uVar18 >> 2 | uVar21 << 0x1e;
    param_3[0x2c] = param_3[0x19] & 0x1ffff | param_3[0x20] << 0x11;
    uVar14 = param_3[0x22] >> 0xf | uVar2 & 0xfffe0000;
    param_3[0x27] = uVar12 >> 2 | uVar9 << 0x1e;
    param_3[0x34] = uVar16 & 3 | uVar16 & 0xfffffffc | uVar1;
    param_3[0x26] = uVar9 >> 2 | uVar16 << 0x1e;
    param_3[0x1d] = uVar17;
    param_3[0x30] = uVar17;
    param_3[0x35] = uVar9;
    param_3[0x1e] = uVar7;
    param_3[0x31] = uVar7;
    param_3[0x36] = uVar21 & 3 | uVar21 & 0xfffffffc | uVar4;
    param_3[0x1c] = uVar3;
    param_3[0x33] = uVar3;
    param_3[0x37] = uVar23 & 3 | uVar23 & 0xfffffffc | param_3[9] << 0xf;
    param_3[0x1f] = uVar15;
    param_3[0x32] = uVar15;
    param_3[0x38] = uVar7 >> 0xf | uVar10 << 0x11;
    param_3[0x3a] = uVar3 >> 0xf | uVar13 << 0x11;
    param_3[0x39] = uVar15 >> 0xf | uVar6 << 0x11;
    param_3[0x3b] = uVar17 >> 0xf | (param_3[0xd] >> 2) << 0x11;
    param_3[0x2e] = uVar25;
    param_3[0x21] = uVar2 >> 0x11 | param_3[0x19] << 0xf;
    param_3[0x2d] = uVar14;
    param_3[0x3d] = param_3[0x2f] >> 0x1e | uVar25 << 2;
    param_3[0x3c] = uVar5 >> 0x1e | uVar14 << 2;
    param_3[0x3f] = uVar2 >> 0x1e | param_3[0x2c] << 2;
    param_3[0x3e] = param_3[0x2c] >> 0x1e | param_3[0x2f] << 2;
    return 4;
  }
  uVar11 = uVar10 >> 0x11 | uVar2 << 0xf;
  uVar3 = uVar2 >> 0x11 | uVar14 << 0xf;
  uVar8 = uVar14 >> 0x11 | uVar17 << 0xf;
  uVar25 = uVar17 >> 0x11 | uVar10 << 0xf;
  param_3[8] = uVar5 >> 0x11 | uVar13 << 0xf;
  uVar5 = uVar11 << 0xf;
  uVar21 = (uVar10 << 0xf) >> 0x11 | uVar5;
  uVar13 = uVar25 << 0xf;
  uVar12 = (uVar17 << 0xf) >> 0x11 | uVar13;
  param_3[0xb] = uVar4 >> 0x11 | uVar9 << 0xf;
  param_3[10] = uVar7 >> 0x11 | uVar1 << 0xf;
  param_3[9] = uVar6 >> 0x11 | uVar15 << 0xf;
  param_3[4] = uVar2;
  param_3[0x13] = (uVar2 << 0xf) >> 0x11 | uVar3 << 0xf;
  uVar1 = uVar8 << 0xf;
  uVar7 = (uVar14 << 0xf) >> 0x11 | uVar1;
  uVar4 = uVar12 << 0xf;
  uVar2 = uVar1 >> 0x11 | uVar4;
  param_3[0x14] = param_3[9] >> 2 | param_3[8] << 0x1e;
  param_3[0x17] = param_3[8] >> 2 | param_3[0xb] << 0x1e;
  param_3[0x16] = param_3[0xb] >> 2 | param_3[10] << 0x1e;
  param_3[0x15] = param_3[10] >> 2 | param_3[9] << 0x1e;
  uVar1 = uVar21 << 0xf;
  uVar15 = uVar13 >> 0x11 | uVar1;
  param_3[5] = uVar10;
  uVar6 = uVar7 << 0xf;
  param_3[6] = uVar17;
  param_3[7] = uVar14;
  param_3[0x12] = uVar7;
  uVar5 = (uVar5 >> 0x11 | param_3[0x13] << 0xf) << 0xf;
  uVar10 = uVar1 >> 0x11 | uVar5;
  param_3[0xc] = uVar11;
  uVar1 = (param_3[0x13] >> 0x11 | uVar6) << 0xf;
  uVar14 = (param_3[0x13] << 0xf) >> 0x11 | uVar1;
  uVar9 = param_3[0x17];
  uVar7 = uVar2 << 0xf;
  uVar17 = uVar6 >> 0x11 | uVar7;
  param_3[0xf] = uVar3;
  uVar6 = uVar15 << 0xf;
  uVar13 = uVar4 >> 0x11 | uVar6;
  param_3[0x11] = uVar12;
  uVar4 = uVar17 << 2;
  uVar12 = uVar1 >> 0x1e | uVar4;
  param_3[0x1d] = uVar17;
  param_3[0x1b] = param_3[0x14] >> 0x11 | uVar9 << 0xf;
  uVar1 = uVar13 << 2;
  uVar11 = uVar7 >> 0x1e | uVar1;
  uVar17 = param_3[0x16];
  param_3[0xd] = uVar25;
  param_3[0x1c] = uVar13;
  param_3[0x10] = uVar21;
  uVar7 = uVar10 << 2;
  uVar25 = uVar6 >> 0x1e | uVar7;
  param_3[0x1f] = uVar10;
  uVar6 = uVar14 << 2;
  uVar3 = uVar5 >> 0x1e | uVar6;
  param_3[0xe] = uVar8;
  param_3[0x1e] = uVar14;
  param_3[0x28] = uVar12;
  uVar5 = param_3[0x15] & 0x1ffff | param_3[0x15] & 0xfffe0000;
  uVar14 = param_3[0x14] & 0x1ffff;
  param_3[0x33] = uVar4 >> 0xf | uVar11 << 0x11;
  uVar4 = param_3[0x1b] >> 0xf;
  uVar13 = uVar4 | uVar9 & 0xfffe0000;
  param_3[0x18] = uVar15;
  uVar15 = uVar14 | param_3[0x1b] << 0x11;
  param_3[0x2b] = uVar11;
  param_3[0x2a] = uVar25;
  param_3[0x29] = uVar3;
  param_3[0x30] = uVar6 >> 0xf | uVar12 << 0x11;
  uVar6 = uVar5 >> 0xf;
  uVar8 = uVar15 >> 0xf;
  uVar10 = uVar13 >> 0xf;
  uVar21 = uVar17 >> 0xf | (param_3[0x15] & 0x1ffff) << 0x11;
  uVar11 = uVar8 | uVar4 << 0x11;
  uVar4 = uVar6 | uVar14 << 0x11;
  uVar14 = uVar10 | uVar17 << 0x11;
  param_3[0x19] = uVar2;
  param_3[0x32] = uVar1 >> 0xf | uVar25 << 0x11;
  param_3[0x1a] = uVar9 >> 0x11 | uVar17 << 0xf;
  param_3[0x22] = uVar13;
  param_3[0x31] = uVar7 >> 0xf | uVar3 << 0x11;
  param_3[0x20] = uVar5;
  param_3[0x21] = uVar17;
  param_3[0x23] = uVar15;
  param_3[0x24] = uVar21;
  param_3[0x2e] = uVar4 >> 0xf | uVar8 << 0x11;
  param_3[0x25] = uVar14;
  param_3[0x26] = uVar11;
  param_3[0x27] = uVar4;
  param_3[0x2c] = uVar14 >> 0xf | (uVar17 >> 0xf) << 0x11;
  param_3[0x2f] = uVar21 >> 0xf | uVar6 << 0x11;
  param_3[0x2d] = uVar11 >> 0xf | uVar10 << 0x11;
  return 3;
}

