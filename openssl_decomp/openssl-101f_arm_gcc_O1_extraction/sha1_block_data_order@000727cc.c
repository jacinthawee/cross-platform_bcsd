
void sha1_block_data_order(uint *param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  bool bVar14;
  
  puVar10 = (uint *)&stack0xffffffd8;
  puVar2 = param_2 + param_3 * 0x10;
  uVar3 = *param_1;
  uVar4 = param_1[1];
  uVar5 = param_1[2];
  uVar6 = param_1[3];
  uVar7 = param_1[4];
  do {
    uVar5 = uVar5 >> 0x1e | uVar5 << 2;
    uVar6 = uVar6 >> 0x1e | uVar6 << 2;
    uVar7 = uVar7 >> 0x1e | uVar7 << 2;
    puVar12 = puVar10;
    do {
      puVar13 = puVar12;
      puVar1 = param_2;
      uVar9 = *puVar1;
      uVar9 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
              uVar9 >> 0x18;
      puVar13[-1] = uVar9;
      uVar7 = DAT_00072ccc + (uVar7 >> 2 | uVar7 << 0x1e) + (uVar3 >> 0x1b | uVar3 << 5) + uVar9 +
              (uVar4 & ((uVar5 ^ uVar6) >> 2 | (uVar5 ^ uVar6) << 0x1e) ^
              (uVar6 >> 2 | uVar6 << 0x1e));
      uVar9 = puVar1[1];
      uVar9 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
              uVar9 >> 0x18;
      puVar13[-2] = uVar9;
      uVar6 = DAT_00072ccc + (uVar6 >> 2 | uVar6 << 0x1e) + (uVar7 >> 0x1b | uVar7 * 0x20) + uVar9 +
              (uVar3 & ((uVar4 ^ uVar5) >> 2 | (uVar4 ^ uVar5) << 0x1e) ^
              (uVar5 >> 2 | uVar5 << 0x1e));
      uVar9 = puVar1[2];
      uVar9 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
              uVar9 >> 0x18;
      puVar13[-3] = uVar9;
      uVar5 = DAT_00072ccc + (uVar5 >> 2 | uVar5 << 0x1e) + (uVar6 >> 0x1b | uVar6 * 0x20) + uVar9 +
              (uVar7 & ((uVar3 ^ uVar4) >> 2 | (uVar3 ^ uVar4) << 0x1e) ^
              (uVar4 >> 2 | uVar4 << 0x1e));
      uVar9 = puVar1[3];
      uVar9 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
              uVar9 >> 0x18;
      puVar13[-4] = uVar9;
      uVar4 = DAT_00072ccc + (uVar4 >> 2 | uVar4 << 0x1e) + (uVar5 >> 0x1b | uVar5 * 0x20) + uVar9 +
              (uVar6 & ((uVar7 ^ uVar3) >> 2 | (uVar7 ^ uVar3) << 0x1e) ^
              (uVar3 >> 2 | uVar3 << 0x1e));
      uVar9 = puVar1[4];
      uVar9 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
              uVar9 >> 0x18;
      puVar12 = puVar13 + -5;
      *puVar12 = uVar9;
      uVar3 = DAT_00072ccc + (uVar3 >> 2 | uVar3 << 0x1e) + (uVar4 >> 0x1b | uVar4 * 0x20) + uVar9 +
              (uVar5 & ((uVar6 ^ uVar7) >> 2 | (uVar6 ^ uVar7) << 0x1e) ^
              (uVar7 >> 2 | uVar7 * 0x40000000));
      param_2 = puVar1 + 5;
    } while (puVar12 != puVar10 + -0xf);
    puVar11 = puVar10 + -0x28;
    param_2 = puVar1 + 6;
    uVar9 = puVar1[5];
    uVar9 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
            uVar9 >> 0x18;
    puVar13[-6] = uVar9;
    uVar7 = DAT_00072ccc + (uVar7 >> 2 | uVar7 * 0x40000000) + (uVar3 >> 0x1b | uVar3 * 0x20) +
            uVar9 + (uVar4 & ((uVar5 ^ uVar6) >> 2 | (uVar5 ^ uVar6) << 0x1e) ^
                    (uVar6 >> 2 | uVar6 * 0x40000000));
    uVar9 = ((puVar13[9] ^ puVar13[7]) >> 0x1f | (puVar13[9] ^ puVar13[7]) << 1) ^
            ((puVar13[1] ^ puVar13[-4]) >> 0x1f | (puVar13[1] ^ puVar13[-4]) << 1);
    puVar13[-7] = uVar9;
    uVar6 = DAT_00072ccc + (uVar6 >> 2 | uVar6 * 0x40000000) + (uVar7 >> 0x1b | uVar7 * 0x20) +
            uVar9 + (uVar3 & ((uVar4 ^ uVar5) >> 2 | (uVar4 ^ uVar5) << 0x1e) ^
                    (uVar5 >> 2 | uVar5 * 0x40000000));
    uVar9 = ((puVar13[8] ^ puVar13[6]) >> 0x1f | (puVar13[8] ^ puVar13[6]) << 1) ^
            ((*puVar13 ^ puVar13[-5]) >> 0x1f | (*puVar13 ^ puVar13[-5]) << 1);
    puVar13[-8] = uVar9;
    uVar5 = DAT_00072ccc + (uVar5 >> 2 | uVar5 * 0x40000000) + (uVar6 >> 0x1b | uVar6 * 0x20) +
            uVar9 + (uVar7 & ((uVar3 ^ uVar4) >> 2 | (uVar3 ^ uVar4) << 0x1e) ^
                    (uVar4 >> 2 | uVar4 * 0x40000000));
    uVar9 = ((puVar13[7] ^ puVar13[5]) >> 0x1f | (puVar13[7] ^ puVar13[5]) << 1) ^
            ((puVar13[-1] ^ puVar13[-6]) >> 0x1f | (puVar13[-1] ^ puVar13[-6]) << 1);
    puVar13[-9] = uVar9;
    uVar4 = DAT_00072ccc + (uVar4 >> 2 | uVar4 * 0x40000000) + (uVar5 >> 0x1b | uVar5 * 0x20) +
            uVar9 + (uVar6 & ((uVar7 ^ uVar3) >> 2 | (uVar7 ^ uVar3) << 0x1e) ^
                    (uVar3 >> 2 | uVar3 * 0x40000000));
    uVar9 = ((puVar13[6] ^ puVar13[4]) >> 0x1f | (puVar13[6] ^ puVar13[4]) << 1) ^
            ((puVar13[-2] ^ puVar13[-7]) >> 0x1f | (puVar13[-2] ^ puVar13[-7]) << 1);
    puVar13 = puVar13 + -10;
    *puVar13 = uVar9;
    uVar3 = DAT_00072ccc + (uVar3 >> 2 | uVar3 * 0x40000000) + (uVar4 >> 0x1b | uVar4 * 0x20) +
            uVar9 + (uVar5 & ((uVar6 ^ uVar7) >> 2 | (uVar6 ^ uVar7) << 0x1e) ^
                    (uVar7 >> 2 | uVar7 * 0x40000000));
    bVar14 = false;
    iVar8 = DAT_00072cd0;
    while( true ) {
      do {
        uVar9 = ((puVar13[0xf] ^ puVar13[0xd]) >> 0x1f | (puVar13[0xf] ^ puVar13[0xd]) << 1) ^
                ((puVar13[7] ^ puVar13[2]) >> 0x1f | (puVar13[7] ^ puVar13[2]) << 1);
        puVar13[-1] = uVar9;
        uVar7 = iVar8 + (uVar7 >> 2 | uVar7 << 0x1e) + (uVar3 >> 0x1b | uVar3 << 5) + uVar9 +
                (uVar4 ^ ((uVar5 ^ uVar6) >> 2 | (uVar5 ^ uVar6) << 0x1e));
        uVar9 = ((puVar13[0xe] ^ puVar13[0xc]) >> 0x1f | (puVar13[0xe] ^ puVar13[0xc]) << 1) ^
                ((puVar13[6] ^ puVar13[1]) >> 0x1f | (puVar13[6] ^ puVar13[1]) << 1);
        puVar13[-2] = uVar9;
        uVar6 = iVar8 + (uVar6 >> 2 | uVar6 << 0x1e) + (uVar7 >> 0x1b | uVar7 * 0x20) + uVar9 +
                (uVar3 ^ ((uVar4 ^ uVar5) >> 2 | (uVar4 ^ uVar5) << 0x1e));
        uVar9 = ((puVar13[0xd] ^ puVar13[0xb]) >> 0x1f | (puVar13[0xd] ^ puVar13[0xb]) << 1) ^
                ((puVar13[5] ^ *puVar13) >> 0x1f | (puVar13[5] ^ *puVar13) << 1);
        puVar13[-3] = uVar9;
        uVar5 = iVar8 + (uVar5 >> 2 | uVar5 << 0x1e) + (uVar6 >> 0x1b | uVar6 * 0x20) + uVar9 +
                (uVar7 ^ ((uVar3 ^ uVar4) >> 2 | (uVar3 ^ uVar4) << 0x1e));
        uVar9 = ((puVar13[0xc] ^ puVar13[10]) >> 0x1f | (puVar13[0xc] ^ puVar13[10]) << 1) ^
                ((puVar13[4] ^ puVar13[-1]) >> 0x1f | (puVar13[4] ^ puVar13[-1]) << 1);
        puVar13[-4] = uVar9;
        uVar4 = iVar8 + (uVar4 >> 2 | uVar4 << 0x1e) + (uVar5 >> 0x1b | uVar5 * 0x20) + uVar9 +
                (uVar6 ^ ((uVar7 ^ uVar3) >> 2 | (uVar7 ^ uVar3) << 0x1e));
        uVar9 = ((puVar13[0xb] ^ puVar13[9]) >> 0x1f | (puVar13[0xb] ^ puVar13[9]) << 1) ^
                ((puVar13[3] ^ puVar13[-2]) >> 0x1f | (puVar13[3] ^ puVar13[-2]) << 1);
        puVar13 = puVar13 + -5;
        *puVar13 = uVar9;
        uVar3 = iVar8 + (uVar3 >> 2 | uVar3 << 0x1e) + (uVar4 >> 0x1b | uVar4 * 0x20) + uVar9 +
                (uVar5 ^ ((uVar6 ^ uVar7) >> 2 | (uVar6 ^ uVar7) << 0x1e));
      } while (puVar13 != puVar11);
      if (bVar14) break;
      do {
        uVar9 = ((puVar13[0xf] ^ puVar13[0xd]) >> 0x1f | (puVar13[0xf] ^ puVar13[0xd]) << 1) ^
                ((puVar13[7] ^ puVar13[2]) >> 0x1f | (puVar13[7] ^ puVar13[2]) << 1);
        puVar13[-1] = uVar9;
        uVar7 = DAT_00072cd4 + (uVar7 >> 2 | uVar7 << 0x1e) + (uVar3 >> 0x1b | uVar3 << 5) + uVar9 +
                (uVar4 & ((uVar5 ^ uVar6) >> 2 | (uVar5 ^ uVar6) << 0x1e)) +
                ((uVar5 & uVar6) >> 2 | (uVar5 & uVar6) << 0x1e);
        uVar9 = ((puVar13[0xe] ^ puVar13[0xc]) >> 0x1f | (puVar13[0xe] ^ puVar13[0xc]) << 1) ^
                ((puVar13[6] ^ puVar13[1]) >> 0x1f | (puVar13[6] ^ puVar13[1]) << 1);
        puVar13[-2] = uVar9;
        uVar6 = DAT_00072cd4 + (uVar6 >> 2 | uVar6 << 0x1e) + (uVar7 >> 0x1b | uVar7 * 0x20) + uVar9
                + (uVar3 & ((uVar4 ^ uVar5) >> 2 | (uVar4 ^ uVar5) << 0x1e)) +
                ((uVar4 & uVar5) >> 2 | (uVar4 & uVar5) << 0x1e);
        uVar9 = ((puVar13[0xd] ^ puVar13[0xb]) >> 0x1f | (puVar13[0xd] ^ puVar13[0xb]) << 1) ^
                ((puVar13[5] ^ *puVar13) >> 0x1f | (puVar13[5] ^ *puVar13) << 1);
        puVar13[-3] = uVar9;
        uVar5 = DAT_00072cd4 + (uVar5 >> 2 | uVar5 << 0x1e) + (uVar6 >> 0x1b | uVar6 * 0x20) + uVar9
                + (uVar7 & ((uVar3 ^ uVar4) >> 2 | (uVar3 ^ uVar4) << 0x1e)) +
                ((uVar3 & uVar4) >> 2 | (uVar3 & uVar4) << 0x1e);
        uVar9 = ((puVar13[0xc] ^ puVar13[10]) >> 0x1f | (puVar13[0xc] ^ puVar13[10]) << 1) ^
                ((puVar13[4] ^ puVar13[-1]) >> 0x1f | (puVar13[4] ^ puVar13[-1]) << 1);
        puVar13[-4] = uVar9;
        uVar4 = DAT_00072cd4 + (uVar4 >> 2 | uVar4 << 0x1e) + (uVar5 >> 0x1b | uVar5 * 0x20) + uVar9
                + (uVar6 & ((uVar7 ^ uVar3) >> 2 | (uVar7 ^ uVar3) << 0x1e)) +
                ((uVar7 & uVar3) >> 2 | (uVar7 & uVar3) << 0x1e);
        uVar9 = ((puVar13[0xb] ^ puVar13[9]) >> 0x1f | (puVar13[0xb] ^ puVar13[9]) << 1) ^
                ((puVar13[3] ^ puVar13[-2]) >> 0x1f | (puVar13[3] ^ puVar13[-2]) << 1);
        puVar13 = puVar13 + -5;
        *puVar13 = uVar9;
        uVar3 = DAT_00072cd4 + (uVar3 >> 2 | uVar3 << 0x1e) + (uVar4 >> 0x1b | uVar4 * 0x20) + uVar9
                + (uVar5 & ((uVar6 ^ uVar7) >> 2 | (uVar6 ^ uVar7) << 0x1e)) +
                ((uVar6 & uVar7) >> 2 | (uVar6 & uVar7) << 0x1e);
      } while (puVar13 != puVar11 + -0x14);
      puVar11 = puVar11 + -0x28;
      bVar14 = true;
      iVar8 = DAT_00072cd8;
    }
    puVar10 = puVar11 + 0x50;
    uVar3 = *param_1 + uVar3;
    uVar4 = param_1[1] + uVar4;
    uVar5 = param_1[2] + (uVar5 >> 2 | uVar5 * 0x40000000);
    uVar6 = param_1[3] + (uVar6 >> 2 | uVar6 * 0x40000000);
    uVar7 = param_1[4] + (uVar7 >> 2 | uVar7 * 0x40000000);
    *param_1 = uVar3;
    param_1[1] = uVar4;
    param_1[2] = uVar5;
    param_1[3] = uVar6;
    param_1[4] = uVar7;
  } while (param_2 != puVar2);
  return;
}

