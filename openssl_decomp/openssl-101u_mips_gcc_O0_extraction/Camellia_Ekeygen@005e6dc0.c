
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
  
  uVar1 = (uint)*param_2 << 0x18 ^ (uint)param_2[1] << 0x10;
  uVar6 = uVar1 ^ param_2[3] ^ (uint)param_2[2] << 8;
  *param_3 = uVar6;
  uVar2 = (uint)param_2[4] << 0x18 ^ (uint)param_2[5] << 0x10;
  uVar8 = uVar2 ^ param_2[7] ^ (uint)param_2[6] << 8;
  param_3[1] = uVar8;
  uVar3 = (uint)param_2[8] << 0x18 ^ (uint)param_2[9] << 0x10;
  uVar22 = uVar3 ^ param_2[0xb] ^ (uint)param_2[10] << 8;
  param_3[2] = uVar22;
  uVar4 = (uint)param_2[0xc] << 0x18 ^ (uint)param_2[0xd] << 0x10;
  uVar19 = uVar4 ^ param_2[0xf] ^ (uint)param_2[0xe] << 8;
  param_3[3] = uVar19;
  if (param_1 == 0x80) {
    uVar9 = 0;
    uVar15 = 0;
    uVar5 = uVar22;
    uVar10 = uVar6;
    uVar14 = uVar19;
    uVar7 = uVar8;
  }
  else {
    uVar9 = (uint)param_2[0x10] << 0x18 ^ (uint)param_2[0x11] << 0x10 ^ (uint)param_2[0x13] ^
            (uint)param_2[0x12] << 8;
    param_3[8] = uVar9;
    uVar15 = (uint)param_2[0x14] << 0x18 ^ (uint)param_2[0x15] << 0x10 ^ (uint)param_2[0x17] ^
             (uint)param_2[0x16] << 8;
    param_3[9] = uVar15;
    if (param_1 == 0xc0) {
      uVar5 = ~uVar9;
      uVar14 = ~uVar15;
      param_3[10] = uVar5;
      param_3[0xb] = uVar14;
    }
    else {
      uVar5 = (uint)param_2[0x18] << 0x18 ^ (uint)param_2[0x19] << 0x10 ^ (uint)param_2[0x1b] ^
              (uint)param_2[0x1a] << 8;
      param_3[10] = uVar5;
      uVar14 = (uint)param_2[0x1c] << 0x18 ^ (uint)param_2[0x1d] << 0x10 ^ (uint)param_2[0x1f] ^
               (uint)param_2[0x1e] << 8;
      param_3[0xb] = uVar14;
    }
    uVar5 = uVar5 ^ uVar22;
    uVar10 = uVar6 ^ uVar9;
    uVar14 = uVar14 ^ uVar19;
    uVar7 = uVar8 ^ uVar15;
  }
  uVar10 = uVar10 ^ 0xa09e667f;
  uVar7 = uVar7 ^ 0x3bcc908b;
  uVar10 = *(uint *)(&Camellia_SBOX + ((uVar10 & 0xff) + 0x100) * 4) ^
           *(uint *)(&Camellia_SBOX + (uVar10 >> 0x18) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar10 << 0x10) >> 0x18) + 0x300) * 4) ^
           *(uint *)(&Camellia_SBOX + (((uVar10 << 8) >> 0x18) + 0x200) * 4);
  uVar11 = uVar10 ^ *(uint *)(&Camellia_SBOX + (uVar7 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar7 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar7 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar7 << 8) >> 0x18) + 0x300) * 4);
  uVar5 = uVar5 ^ uVar11;
  uVar7 = uVar5 ^ 0xb67ae858;
  uVar14 = (uVar10 >> 8) + uVar10 * 0x1000000 ^ uVar11 ^ uVar14;
  uVar10 = uVar14 ^ 0x4caa73b2;
  uVar7 = *(uint *)(&Camellia_SBOX + ((uVar7 & 0xff) + 0x100) * 4) ^
          *(uint *)(&Camellia_SBOX + (uVar7 >> 0x18) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar7 << 0x10) >> 0x18) + 0x300) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar7 << 8) >> 0x18) + 0x200) * 4);
  uVar10 = uVar7 ^ *(uint *)(&Camellia_SBOX + (uVar10 & 0xff) * 4) ^
                   *(uint *)(&Camellia_SBOX + ((uVar10 >> 0x18) + 0x200) * 4) ^
                   *(uint *)(&Camellia_SBOX + (((uVar10 << 0x10) >> 0x18) + 0x100) * 4) ^
                   *(uint *)(&Camellia_SBOX + (((uVar10 << 8) >> 0x18) + 0x300) * 4);
  uVar9 = uVar10 ^ uVar9;
  uVar10 = (uVar7 >> 8) + uVar7 * 0x1000000 ^ uVar15 ^ uVar10;
  uVar15 = uVar10 ^ 0xe94f82be;
  uVar7 = uVar9 ^ 0xc6ef372f;
  uVar7 = *(uint *)(&Camellia_SBOX + ((uVar7 & 0xff) + 0x100) * 4) ^
          *(uint *)(&Camellia_SBOX + (uVar7 >> 0x18) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar7 << 0x10) >> 0x18) + 0x300) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar7 << 8) >> 0x18) + 0x200) * 4);
  uVar15 = uVar7 ^ *(uint *)(&Camellia_SBOX + (uVar15 & 0xff) * 4) ^
                   *(uint *)(&Camellia_SBOX + ((uVar15 >> 0x18) + 0x200) * 4) ^
                   *(uint *)(&Camellia_SBOX + (((uVar15 << 0x10) >> 0x18) + 0x100) * 4) ^
                   *(uint *)(&Camellia_SBOX + (((uVar15 << 8) >> 0x18) + 0x300) * 4);
  uVar5 = uVar22 ^ uVar5 ^ uVar15;
  uVar15 = (uVar7 >> 8) + uVar7 * 0x1000000 ^ uVar19 ^ uVar14 ^ uVar15;
  uVar14 = uVar5 ^ 0x54ff53a5;
  uVar11 = uVar15 ^ 0xf1d36f1c;
  uVar7 = *(uint *)(&Camellia_SBOX + ((uVar14 & 0xff) + 0x100) * 4) ^
          *(uint *)(&Camellia_SBOX + (uVar14 >> 0x18) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar14 << 0x10) >> 0x18) + 0x300) * 4) ^
          *(uint *)(&Camellia_SBOX + (((uVar14 << 8) >> 0x18) + 0x200) * 4);
  uVar14 = uVar7 ^ *(uint *)(&Camellia_SBOX + (uVar11 & 0xff) * 4) ^
                   *(uint *)(&Camellia_SBOX + ((uVar11 >> 0x18) + 0x200) * 4) ^
                   *(uint *)(&Camellia_SBOX + (((uVar11 << 0x10) >> 0x18) + 0x100) * 4) ^
                   *(uint *)(&Camellia_SBOX + (((uVar11 << 8) >> 0x18) + 0x300) * 4);
  uVar9 = uVar9 ^ uVar14;
  uVar14 = (uVar7 >> 8) + uVar7 * 0x1000000 ^ uVar10 ^ uVar14;
  if (param_1 != 0x80) {
    uVar17 = param_3[8];
    uVar16 = param_3[0xb];
    uVar23 = param_3[10];
    uVar7 = uVar14 ^ param_3[9] ^ 0xde682d1d;
    uVar10 = uVar9 ^ uVar17 ^ 0x10e527fa;
    uVar11 = *(uint *)(&Camellia_SBOX + ((uVar10 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar10 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 8) >> 0x18) + 0x200) * 4);
    uVar10 = uVar11 ^ *(uint *)(&Camellia_SBOX + (uVar7 & 0xff) * 4) ^
                      *(uint *)(&Camellia_SBOX + ((uVar7 >> 0x18) + 0x200) * 4) ^
                      *(uint *)(&Camellia_SBOX + (((uVar7 << 0x10) >> 0x18) + 0x100) * 4) ^
                      *(uint *)(&Camellia_SBOX + (((uVar7 << 8) >> 0x18) + 0x300) * 4);
    uVar13 = uVar5 ^ uVar23 ^ uVar10;
    uVar10 = (uVar11 >> 8) + uVar11 * 0x1000000 ^ uVar15 ^ uVar16 ^ uVar10;
    param_3[6] = uVar13;
    param_3[7] = uVar10;
    uVar11 = uVar13 ^ 0xb05688c2;
    uVar7 = uVar10 ^ 0xb3e6c1fd;
    uVar11 = *(uint *)(&Camellia_SBOX + ((uVar11 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar11 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar11 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar11 << 8) >> 0x18) + 0x200) * 4);
    uVar12 = *(uint *)(&Camellia_SBOX + (uVar7 & 0xff) * 4) ^
             *(uint *)(&Camellia_SBOX + ((uVar7 >> 0x18) + 0x200) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar7 << 0x10) >> 0x18) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar7 << 8) >> 0x18) + 0x300) * 4) ^ uVar11;
    uVar7 = uVar9 ^ uVar17 ^ uVar12;
    uVar12 = (uVar11 >> 8) + uVar11 * 0x1000000 ^ uVar14 ^ param_3[9] ^ uVar12;
    param_3[4] = uVar7;
    param_3[5] = uVar12;
    param_3[8] = uVar17 << 0xf | param_3[9] >> 0x11;
    param_3[9] = param_3[9] << 0xf | uVar23 >> 0x11;
    param_3[10] = uVar23 << 0xf | uVar16 >> 0x11;
    param_3[0xb] = uVar17 >> 0x11 | uVar16 << 0xf;
    param_3[0x18] = uVar3 >> 0x13 | uVar8 << 0xd;
    param_3[0x1a] = uVar1 >> 0x13 | uVar19 << 0xd;
    param_3[0x19] = uVar4 >> 0x13 | uVar22 << 0xd;
    param_3[0x1b] = uVar2 >> 0x13 | uVar6 << 0xd;
    param_3[0x10] = param_3[9] >> 0x11 | param_3[8] << 0xf;
    uVar1 = uVar13 >> 2 | uVar12 << 0x1e;
    uVar11 = uVar10 >> 2 | uVar13 << 0x1e;
    uVar8 = uVar7 >> 2 | uVar10 << 0x1e;
    uVar3 = uVar12 >> 2 | uVar7 << 0x1e;
    param_3[0x15] = uVar1;
    param_3[0x14] = uVar3;
    param_3[0x16] = uVar11;
    param_3[0x11] = param_3[10] >> 0x11 | param_3[9] << 0xf;
    param_3[0x17] = uVar8;
    param_3[0x12] = param_3[0xb] >> 0x11 | param_3[10] << 0xf;
    param_3[0x13] = param_3[8] >> 0x11 | param_3[0xb] << 0xf;
    param_3[0xc] = uVar14 >> 0x11 | uVar9 << 0xf;
    param_3[0xd] = uVar5 >> 0x11 | uVar14 << 0xf;
    uVar11 = uVar11 >> 2;
    param_3[0xe] = uVar15 >> 0x11 | uVar5 << 0xf;
    param_3[0xf] = uVar9 >> 0x11 | uVar15 << 0xf;
    param_3[0x20] = param_3[0x19] >> 0x11 | param_3[0x18] << 0xf;
    param_3[0x21] = param_3[0x1a] >> 0x11 | param_3[0x19] << 0xf;
    param_3[0x22] = param_3[0x1b] >> 0x11 | param_3[0x1a] << 0xf;
    uVar16 = param_3[0x13];
    uVar3 = uVar3 >> 2;
    param_3[0x23] = param_3[0x18] >> 0x11 | param_3[0x1b] << 0xf;
    uVar1 = uVar1 >> 2;
    uVar8 = uVar8 >> 2;
    uVar2 = uVar1 | (uVar12 >> 2) << 0x1e;
    uVar25 = param_3[0xd] >> 2;
    uVar23 = uVar25 | param_3[0xc] << 0x1e;
    uVar12 = param_3[0xe] >> 2;
    uVar15 = uVar12 | param_3[0xd] << 0x1e;
    param_3[0x28] = uVar2;
    uVar9 = param_3[0xf] >> 2;
    uVar26 = uVar9 | param_3[0xe] << 0x1e;
    uVar17 = param_3[0xc] >> 2 | param_3[0xf] << 0x1e;
    param_3[0x24] = param_3[0x11] >> 2 | param_3[0x10] << 0x1e;
    uVar6 = param_3[0x23] << 0x11;
    uVar14 = uVar11 | (uVar13 >> 2) << 0x1e;
    uVar13 = param_3[0x21] << 0x11;
    param_3[0x29] = uVar14;
    uVar10 = uVar8 | (uVar10 >> 2) << 0x1e;
    uVar5 = param_3[0x22] >> 0xf | uVar13;
    param_3[0x2a] = uVar10;
    uVar19 = uVar3 | (uVar7 >> 2) << 0x1e;
    param_3[0x2b] = uVar19;
    param_3[0x25] = param_3[0x12] >> 2 | param_3[0x11] << 0x1e;
    param_3[0x26] = uVar16 >> 2 | param_3[0x12] << 0x1e;
    uVar22 = param_3[0x23] >> 0xf | param_3[0x22] << 0x11;
    param_3[0x2c] = param_3[0x21] >> 0xf | param_3[0x20] << 0x11;
    uVar4 = param_3[0x20] >> 0xf | uVar6;
    param_3[0x42] = uVar2 >> 0xd | uVar3 << 0x13;
    param_3[0x27] = param_3[0x10] >> 2 | uVar16 << 0x1e;
    param_3[0x1c] = uVar23;
    param_3[0x35] = uVar16 & 3 | param_3[0x26] << 2;
    param_3[0x36] = param_3[0x24] >> 0x1e | param_3[0x10] & 0xfffffffc;
    param_3[0x1e] = uVar26;
    param_3[0x1f] = uVar17;
    param_3[0x37] = param_3[0x25] >> 0x1e | param_3[0x24] << 2;
    param_3[0x31] = uVar26;
    param_3[0x40] = uVar10 >> 0xd | uVar11 << 0x13;
    param_3[0x41] = uVar19 >> 0xd | uVar8 << 0x13;
    param_3[0x43] = uVar14 >> 0xd | uVar1 << 0x13;
    param_3[0x1d] = uVar15;
    param_3[0x30] = uVar15;
    param_3[0x34] = param_3[0x26] >> 0x1e | param_3[0x25] << 2;
    param_3[0x32] = uVar17;
    param_3[0x33] = uVar23;
    param_3[0x38] = uVar26 >> 0xf | uVar12 << 0x11;
    param_3[0x39] = uVar17 >> 0xf | uVar9 << 0x11;
    param_3[0x3a] = uVar23 >> 0xf | (param_3[0xc] >> 2) << 0x11;
    param_3[0x3b] = uVar15 >> 0xf | uVar25 << 0x11;
    param_3[0x2d] = uVar5;
    param_3[0x2e] = uVar22;
    param_3[0x3c] = (param_3[0x22] << 0x11) >> 0x1e | uVar5 << 2;
    param_3[0x3d] = uVar6 >> 0x1e | uVar22 << 2;
    param_3[0x3e] = param_3[0x2c] >> 0x1e | uVar4 << 2;
    param_3[0x3f] = uVar13 >> 0x1e | param_3[0x2c] << 2;
    param_3[0x2f] = uVar4;
    return 4;
  }
  param_3[5] = uVar14;
  param_3[6] = uVar5;
  param_3[4] = uVar9;
  param_3[7] = uVar15;
  uVar16 = uVar5 >> 0x11 | uVar14 << 0xf;
  uVar25 = uVar15 >> 0x11 | uVar5 << 0xf;
  param_3[0xd] = uVar16;
  param_3[0xe] = uVar25;
  uVar12 = uVar14 >> 0x11 | uVar9 << 0xf;
  uVar10 = uVar9 >> 0x11 | uVar15 << 0xf;
  param_3[0xc] = uVar12;
  uVar11 = uVar2 >> 0x11 | uVar6 << 0xf;
  param_3[0xf] = uVar10;
  uVar13 = uVar3 >> 0x11 | uVar8 << 0xf;
  uVar23 = uVar1 >> 0x11 | uVar19 << 0xf;
  param_3[8] = uVar11;
  param_3[9] = uVar13;
  uVar16 = uVar16 << 0xf;
  param_3[0xb] = uVar23;
  uVar25 = uVar25 << 0xf;
  uVar17 = uVar4 >> 0x11 | uVar22 << 0xf;
  uVar13 = uVar13 >> 2;
  uVar12 = uVar12 << 0xf;
  param_3[10] = uVar17;
  uVar10 = uVar10 << 0xf;
  uVar7 = (uVar2 >> 0x11) << 0x1e;
  uVar2 = (uVar5 << 0xf) >> 0x11 | uVar16;
  uVar26 = (uVar15 << 0xf) >> 0x11 | uVar25;
  uVar17 = uVar17 >> 2;
  param_3[0x11] = uVar2;
  uVar23 = uVar23 >> 2;
  param_3[0x12] = uVar26;
  uVar20 = (uVar1 >> 0x11) << 0x1e;
  uVar11 = uVar11 >> 2;
  uVar5 = (uVar3 >> 0x11) << 0x1e;
  uVar14 = (uVar14 << 0xf) >> 0x11 | uVar12;
  uVar1 = (uVar9 << 0xf) >> 0x11 | uVar10;
  uVar3 = uVar13 | uVar7;
  param_3[0x10] = uVar14;
  uVar18 = (uVar4 >> 0x11) << 0x1e;
  param_3[0x13] = uVar1;
  param_3[0x14] = uVar3;
  uVar4 = uVar11 | uVar20;
  param_3[0x15] = uVar17 | uVar5;
  uVar14 = uVar14 << 0xf;
  uVar2 = uVar2 << 0xf;
  uVar26 = uVar26 << 0xf;
  uVar1 = uVar1 << 0xf;
  uVar16 = uVar16 >> 0x11 | uVar14;
  uVar15 = uVar25 >> 0x11 | uVar2;
  param_3[0x18] = uVar16;
  param_3[0x19] = uVar15;
  uVar15 = uVar15 << 0xf;
  uVar16 = uVar16 << 0xf;
  uVar9 = (uVar12 >> 0x11 | uVar1) << 0xf;
  uVar21 = uVar2 >> 0x11 | uVar16;
  uVar12 = (uVar10 >> 0x11 | uVar26) << 0xf;
  param_3[0x1c] = uVar21;
  uVar17 = uVar17 & 0x1ffff;
  uVar2 = uVar26 >> 0x11 | uVar15;
  uVar10 = uVar14 >> 0x11 | uVar9;
  param_3[0x1d] = uVar2;
  uVar25 = uVar23 & 0x1ffff | (uVar19 << 0xf & 0xfff80000) >> 2 | uVar18;
  param_3[0x1f] = uVar10;
  uVar14 = uVar1 >> 0x11 | uVar12;
  param_3[0x1e] = uVar14;
  uVar13 = uVar13 & 0x1ffff;
  uVar2 = uVar2 << 2;
  uVar21 = uVar21 << 2;
  uVar24 = uVar17 | (uVar22 << 0xf & 0xfff80000) >> 2 | uVar5;
  uVar10 = uVar10 << 2;
  uVar8 = uVar13 | (uVar8 << 0xf & 0xfff80000) >> 2 | uVar7;
  uVar1 = uVar15 >> 0x1e | uVar21;
  param_3[0x2b] = uVar1;
  uVar26 = uVar25 >> 0xf;
  uVar14 = uVar14 << 2;
  uVar19 = uVar16 >> 0x1e | uVar10;
  uVar16 = uVar11 & 0x1ffff | (uVar6 << 0xf & 0xfff80000) >> 2 | uVar20;
  uVar15 = uVar26 | uVar17 << 0x11;
  param_3[0x2a] = uVar19;
  uVar6 = uVar12 >> 0x1e | uVar2;
  uVar22 = uVar9 >> 0x1e | uVar14;
  param_3[0x28] = uVar6;
  param_3[0x29] = uVar22;
  uVar17 = uVar16 >> 0xf;
  uVar12 = uVar8 >> 0xf;
  uVar9 = uVar24 >> 0xf;
  param_3[0x32] = uVar21 >> 0xf | uVar19 << 0x11;
  uVar5 = uVar12 | (uVar11 & 0x1ffff) << 0x11;
  uVar7 = uVar17 | (uVar23 & 0x1ffff) << 0x11;
  uVar19 = uVar9 | uVar13 << 0x11;
  param_3[0x30] = uVar14 >> 0xf | uVar6 << 0x11;
  param_3[0x31] = uVar10 >> 0xf | uVar22 << 0x11;
  param_3[0x33] = uVar2 >> 0xf | uVar1 << 0x11;
  param_3[0x16] = uVar23 | uVar18;
  param_3[0x17] = uVar4;
  param_3[0x1a] = uVar4 >> 0x11 | uVar23 << 0xf;
  param_3[0x2c] = uVar7 >> 0xf | uVar26 << 0x11;
  param_3[0x2d] = uVar5 >> 0xf | uVar17 << 0x11;
  param_3[0x1b] = uVar3 >> 0x11 | uVar11 << 0xf;
  param_3[0x20] = uVar24;
  param_3[0x21] = uVar25;
  param_3[0x22] = uVar16;
  param_3[0x2f] = uVar15 >> 0xf | uVar9 << 0x11;
  param_3[0x23] = uVar8;
  param_3[0x24] = uVar15;
  param_3[0x25] = uVar7;
  param_3[0x26] = uVar5;
  param_3[0x27] = uVar19;
  param_3[0x2e] = uVar19 >> 0xf | uVar12 << 0x11;
  return 3;
}

