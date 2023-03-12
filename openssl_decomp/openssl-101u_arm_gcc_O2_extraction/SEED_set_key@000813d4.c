
void SEED_set_key(uchar *rawkey,SEED_KEY_SCHEDULE *ks)

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
  
  uVar17 = (uint)rawkey[1] << 0x10 | (uint)*rawkey << 0x18 | (uint)rawkey[3] | (uint)rawkey[2] << 8;
  uVar7 = (uint)rawkey[5] << 0x10 | (uint)rawkey[4] << 0x18 | (uint)rawkey[7] | (uint)rawkey[6] << 8
  ;
  uVar1 = (uint)rawkey[9] << 0x10 | (uint)rawkey[8] << 0x18 | (uint)rawkey[0xb] |
          (uint)rawkey[10] << 8;
  uVar10 = (uint)rawkey[0xd] << 0x10 | (uint)rawkey[0xc] << 0x18 | (uint)rawkey[0xf] |
           (uint)rawkey[0xe] << 8;
  uVar2 = uVar17 >> 8;
  uVar12 = (uint)rawkey[7] << 0x18 | uVar2;
  uVar8 = uVar7 >> 8;
  uVar18 = (uint)rawkey[3] << 0x18 | uVar8;
  uVar9 = (uint)rawkey[0xc] | uVar1 << 8;
  uVar6 = (uint)rawkey[8] | uVar10 << 8;
  uVar5 = uVar2 << 0x18 | uVar18 >> 8;
  uVar17 = uVar17 + uVar1 + 0x61c88647;
  uVar8 = uVar8 << 0x18 | uVar12 >> 8;
  uVar3 = (0x3c6ef373 - uVar10) + uVar18;
  uVar11 = (uVar7 + 0x9e3779b9) - uVar10;
  uVar7 = (uVar1 << 8) >> 0x18 | uVar6 << 8;
  uVar4 = (uVar18 >> 8) << 0x18 | uVar8 >> 8;
  uVar2 = (uVar10 << 8) >> 0x18 | uVar9 << 8;
  uVar20 = uVar1 + 0xc3910c8d + uVar12;
  uVar13 = (uVar12 >> 8) << 0x18 | uVar5 >> 8;
  uVar16 = (uVar9 << 8) >> 0x18 | uVar7 << 8;
  uVar15 = (uVar6 << 8) >> 0x18 | uVar2 << 8;
  ks->data[0] = *(uint *)(&SS + ((uVar17 >> 0x18) + 0x300) * 4) ^
                *(uint *)(&SS + (uVar17 & 0xff) * 4) ^
                *(uint *)(&SS + ((uVar17 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar17 * 0x100 >> 0x18) + 0x200) * 4);
  uVar14 = *(uint *)(&SS + ((uVar20 >> 0x18) + 0x300) * 4);
  ks->data[1] = *(uint *)(&SS + (uVar11 & 0xff) * 4) ^
                *(uint *)(&SS + ((uVar11 >> 0x18) + 0x300) * 4) ^
                *(uint *)(&SS + ((uVar11 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar11 * 0x100 >> 0x18) + 0x200) * 4);
  uVar11 = *(uint *)(&SS + ((uVar3 >> 0x18) + 0x300) * 4);
  uVar17 = (uVar18 + 0x78dde6e6) - uVar6;
  uVar1 = uVar9 + 0xe443234 + uVar8;
  uVar10 = (uVar5 + 0xe3779b99) - uVar7;
  ks->data[2] = uVar14 ^ *(uint *)(&SS + (uVar20 & 0xff) * 4) ^
                *(uint *)(&SS + ((uVar20 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar20 * 0x100 >> 0x18) + 0x200) * 4);
  uVar18 = (-0xe443234 - uVar6) + uVar5;
  uVar21 = uVar4 + uVar2 + 0x3910c8cd;
  uVar22 = (uVar8 >> 8) << 0x18 | uVar13 >> 8;
  uVar6 = uVar12 + uVar9 + 0x8722191a;
  uVar8 = uVar8 + uVar2 + 0x1c886467;
  uVar5 = (uVar5 >> 8) << 0x18 | uVar4 >> 8;
  ks->data[3] = uVar11 ^ *(uint *)(&SS + (uVar3 & 0xff) * 4) ^
                *(uint *)(&SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4);
  uVar14 = (uVar7 << 8) >> 0x18 | uVar15 << 8;
  uVar12 = (uVar2 << 8) >> 0x18 | uVar16 << 8;
  uVar19 = (uVar13 >> 8) << 0x18 | uVar5 >> 8;
  ks->data[4] = *(uint *)(&SS + ((uVar6 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar6 & 0xff) * 4)
                ^ *(uint *)(&SS + ((uVar6 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar6 * 0x100 >> 0x18) + 0x200) * 4);
  uVar2 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4);
  ks->data[5] = *(uint *)(&SS + (uVar17 & 0xff) * 4) ^
                *(uint *)(&SS + ((uVar17 >> 0x18) + 0x300) * 4) ^
                *(uint *)(&SS + ((uVar17 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar17 * 0x100 >> 0x18) + 0x200) * 4);
  uVar3 = *(uint *)(&SS + ((uVar18 >> 0x18) + 0x300) * 4);
  uVar17 = *(uint *)(&SS + ((uVar8 >> 0x18) + 0x300) * 4);
  ks->data[6] = uVar2 ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
                *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  uVar1 = *(uint *)(&SS + ((uVar10 >> 0x18) + 0x300) * 4);
  uVar9 = *(uint *)(&SS + ((uVar21 >> 0x18) + 0x300) * 4);
  ks->data[7] = uVar3 ^ *(uint *)(&SS + (uVar18 & 0xff) * 4) ^
                *(uint *)(&SS + ((uVar18 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar18 * 0x100 >> 0x18) + 0x200) * 4);
  uVar11 = (-0x3910c8cd - uVar7) + uVar13;
  uVar18 = (0x1bbcdccf - uVar16) + uVar22;
  uVar23 = (uVar4 >> 8) << 0x18 | uVar22 >> 8;
  ks->data[8] = *(uint *)(&SS + (uVar8 & 0xff) * 4) ^ uVar17 ^
                *(uint *)(&SS + ((uVar8 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar8 * 0x100 >> 0x18) + 0x200) * 4);
  uVar6 = (uVar13 + 0x8dde6e67) - uVar16;
  uVar2 = uVar15 + 0xe4432331 + uVar5;
  uVar7 = (uVar15 << 8) >> 0x18 | uVar12 << 8;
  uVar20 = (uVar22 + 0x3779b99e) - uVar12;
  uVar3 = *(uint *)(&SS + (uVar21 & 0xff) * 4);
  ks->data[9] = uVar1 ^ *(uint *)(&SS + (uVar10 & 0xff) * 4) ^
                *(uint *)(&SS + ((uVar10 * 0x10000 >> 0x18) + 0x100) * 4) ^
                *(uint *)(&SS + ((uVar10 * 0x100 >> 0x18) + 0x200) * 4);
  uVar8 = uVar4 + uVar15 + 0x72219199;
  uVar17 = uVar14 + uVar5 + 0xc8864662;
  uVar10 = (uVar16 << 8) >> 0x18 | uVar14 << 8;
  ks->data[10] = uVar9 ^ uVar3 ^ *(uint *)(&SS + ((uVar21 * 0x10000 >> 0x18) + 0x100) * 4) ^
                 *(uint *)(&SS + ((uVar21 * 0x100 >> 0x18) + 0x200) * 4);
  uVar13 = (uVar5 >> 8) << 0x18 | uVar23 >> 8;
  uVar5 = (uVar22 >> 8) << 0x18 | uVar19 >> 8;
  uVar15 = (uVar12 << 8) >> 0x18 | uVar10 << 8;
  ks->data[0xb] =
       *(uint *)(&SS + ((uVar11 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar11 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar11 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar11 * 0x100 >> 0x18) + 0x200) * 4);
  uVar3 = *(uint *)(&SS + ((uVar6 >> 0x18) + 0x300) * 4);
  ks->data[0xc] =
       *(uint *)(&SS + ((uVar8 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar8 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar8 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar8 * 0x100 >> 0x18) + 0x200) * 4);
  uVar1 = *(uint *)(&SS + ((uVar2 >> 0x18) + 0x300) * 4);
  ks->data[0xd] =
       uVar3 ^ *(uint *)(&SS + (uVar6 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar6 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar6 * 0x100 >> 0x18) + 0x200) * 4);
  uVar6 = *(uint *)(&SS + ((uVar17 >> 0x18) + 0x300) * 4);
  uVar11 = *(uint *)(&SS + ((uVar20 >> 0x18) + 0x300) * 4);
  uVar3 = *(uint *)(&SS + ((uVar18 >> 0x18) + 0x300) * 4);
  uVar8 = (0x6ef3733c - uVar12) + uVar23;
  uVar12 = uVar14 + 0x910c8cc4 + uVar19;
  uVar21 = uVar10 + 0x4432330f + uVar5;
  ks->data[0xe] =
       uVar1 ^ *(uint *)(&SS + (uVar2 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar2 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar2 * 0x100 >> 0x18) + 0x200) * 4);
  uVar9 = (uVar14 << 8) >> 0x18 | uVar7 << 8;
  uVar1 = (uVar23 + 0xdde6e678) - uVar7;
  uVar4 = uVar13 + (-0x4432330f - uVar7);
  ks->data[0xf] =
       uVar3 ^ *(uint *)(&SS + (uVar18 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar18 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar18 * 0x100 >> 0x18) + 0x200) * 4);
  uVar14 = *(uint *)(&SS + (uVar20 & 0xff) * 4);
  uVar18 = *(uint *)(&SS + ((uVar20 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar2 = *(uint *)(&SS + ((uVar20 * 0x100 >> 0x18) + 0x200) * 4);
  uVar3 = uVar19 + uVar10 + 0x22191988;
  ks->data[0x10] =
       uVar6 ^ *(uint *)(&SS + (uVar17 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar17 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar17 * 0x100 >> 0x18) + 0x200) * 4);
  uVar20 = uVar15 + uVar5 + 0x8864661d;
  uVar16 = (uVar23 >> 8) << 0x18 | uVar5 >> 8;
  uVar6 = (uVar19 >> 8) << 0x18 | uVar13 >> 8;
  ks->data[0x11] = uVar11 ^ uVar14 ^ uVar18 ^ uVar2;
  uVar18 = uVar15 << 8 | (uVar7 << 8) >> 0x18;
  uVar11 = (uVar10 << 8) >> 0x18 | uVar9 << 8;
  uVar2 = *(uint *)(&SS + ((uVar8 >> 0x18) + 0x300) * 4);
  ks->data[0x12] =
       *(uint *)(&SS + ((uVar12 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar12 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar12 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar12 * 0x100 >> 0x18) + 0x200) * 4);
  uVar7 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4);
  uVar17 = *(uint *)(&SS + ((uVar3 >> 0x18) + 0x300) * 4);
  ks->data[0x13] =
       uVar2 ^ *(uint *)(&SS + (uVar8 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar8 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar8 * 0x100 >> 0x18) + 0x200) * 4);
  uVar14 = *(uint *)(&SS + ((uVar21 >> 0x18) + 0x300) * 4);
  uVar12 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4);
  uVar2 = *(uint *)(&SS + ((uVar20 >> 0x18) + 0x300) * 4);
  ks->data[0x14] =
       uVar17 ^ *(uint *)(&SS + (uVar3 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4);
  uVar3 = (uVar13 + 0x779b99e3) - uVar9;
  uVar8 = uVar15 + 0x10c8cc3a + uVar16;
  uVar10 = uVar18 + 0x432330e5 + (uVar16 >> 8 | (uVar13 >> 8) << 0x18);
  uVar17 = (-0x10c8cc3a - uVar9) + uVar6;
  uVar19 = ((uVar5 >> 8) << 0x18 | uVar6 >> 8) + (-0x432330e5 - uVar11);
  uVar11 = (uVar6 + 0xde6e678d) - uVar11;
  ks->data[0x15] =
       *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
       uVar7 ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = *(uint *)(&SS + (uVar4 & 0xff) * 4);
  ks->data[0x16] =
       uVar14 ^ *(uint *)(&SS + (uVar21 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar21 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar21 * 0x100 >> 0x18) + 0x200) * 4);
  uVar7 = *(uint *)(&SS + (uVar20 & 0xff) * 4);
  uVar6 = *(uint *)(&SS + ((uVar20 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar9 = *(uint *)(&SS + ((uVar8 >> 0x18) + 0x300) * 4);
  uVar5 = *(uint *)(&SS + ((uVar20 * 0x100 >> 0x18) + 0x200) * 4);
  ks->data[0x17] =
       uVar12 ^ uVar1 ^ *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4);
  ks->data[0x18] = uVar2 ^ uVar7 ^ uVar6 ^ uVar5;
  uVar5 = *(uint *)(&SS + ((uVar17 >> 0x18) + 0x300) * 4);
  uVar6 = *(uint *)(&SS + ((uVar11 >> 0x18) + 0x300) * 4);
  uVar12 = *(uint *)(&SS + ((uVar10 >> 0x18) + 0x300) * 4);
  uVar14 = *(uint *)(&SS + ((uVar19 >> 0x18) + 0x300) * 4);
  uVar15 = *(uint *)(&SS + (uVar8 & 0xff) * 4);
  uVar4 = *(uint *)(&SS + ((uVar8 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = uVar18 + uVar16 + 0x21919873;
  uVar2 = *(uint *)(&SS + ((uVar8 * 0x100 >> 0x18) + 0x200) * 4);
  ks->data[0x19] =
       *(uint *)(&SS + ((uVar3 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar3 & 0xff) * 4) ^
       *(uint *)(&SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4) ^
       *(uint *)(&SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4);
  uVar3 = *(uint *)(&SS + (uVar17 & 0xff) * 4);
  uVar18 = *(uint *)(&SS + ((uVar17 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar13 = *(uint *)(&SS + ((uVar17 * 0x100 >> 0x18) + 0x200) * 4);
  uVar7 = *(uint *)(&SS + (uVar1 & 0xff) * 4);
  uVar16 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4);
  uVar8 = *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar21 = *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  ks->data[0x1a] = uVar2 ^ uVar9 ^ uVar15 ^ uVar4;
  uVar4 = *(uint *)(&SS + (uVar11 & 0xff) * 4);
  uVar9 = *(uint *)(&SS + (uVar10 & 0xff) * 4);
  uVar2 = *(uint *)(&SS + ((uVar11 * 0x100 >> 0x18) + 0x200) * 4);
  uVar11 = *(uint *)(&SS + ((uVar11 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar20 = *(uint *)(&SS + ((uVar10 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = *(uint *)(&SS + ((uVar10 * 0x100 >> 0x18) + 0x200) * 4);
  uVar15 = *(uint *)(&SS + (uVar19 & 0xff) * 4);
  uVar10 = *(uint *)(&SS + ((uVar19 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar17 = *(uint *)(&SS + ((uVar19 * 0x100 >> 0x18) + 0x200) * 4);
  ks->data[0x1b] = uVar5 ^ uVar3 ^ uVar18 ^ uVar13;
  ks->data[0x1c] = uVar16 ^ uVar7 ^ uVar8 ^ uVar21;
  ks->data[0x1d] = uVar2 ^ uVar4 ^ uVar6 ^ uVar11;
  ks->data[0x1e] = uVar12 ^ uVar9 ^ uVar20 ^ uVar1;
  ks->data[0x1f] = uVar10 ^ uVar15 ^ uVar14 ^ uVar17;
  return;
}

