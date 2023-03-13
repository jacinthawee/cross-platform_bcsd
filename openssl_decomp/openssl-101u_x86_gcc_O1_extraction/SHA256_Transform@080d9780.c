
void SHA256_Transform(SHA256_CTX *c,uchar *data)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int in_GS_OFFSET;
  uint uStack_e4;
  uint uStack_e0;
  uint uStack_dc;
  undefined1 *puStack_d8;
  uint uStack_d4;
  uint uStack_d0;
  uint uStack_cc;
  uint uStack_c8;
  uint uStack_c4;
  uint uStack_c0;
  uint uStack_b8;
  uchar *puStack_b4;
  uint uStack_ac;
  uint uStack_a8;
  uint uStack_98;
  uint uStack_94;
  uint uStack_90;
  uint uStack_8c;
  uint uStack_88;
  uint uStack_84;
  uint uStack_80;
  uint uStack_7c;
  uint uStack_78;
  int iStack_74;
  uint auStack_60 [4];
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  uint uStack_24;
  int iStack_20;
  
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
  iStack_74 = 0;
  uStack_94 = c->h[0];
  uStack_8c = c->h[1];
  uStack_88 = c->h[2];
  uStack_7c = c->h[3];
  uStack_90 = c->h[4];
  uStack_84 = c->h[5];
  uStack_80 = c->h[6];
  uStack_78 = c->h[7];
  puStack_b4 = data + 0x40;
  do {
    uVar7 = *(uint *)(puStack_b4 + -0x40);
    uStack_ac = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
    auStack_60[0] = uStack_ac;
    iVar3 = uStack_78 + 0x428a2f98 + (uStack_90 & uStack_84 ^ ~uStack_90 & uStack_80) + uStack_ac +
            ((uStack_90 << 0x15 | uStack_90 >> 0xb) ^ (uStack_90 << 0x1a | uStack_90 >> 6) ^
            (uStack_90 << 7 | uStack_90 >> 0x19));
    uVar7 = iVar3 + uStack_7c;
    uVar12 = iVar3 + (uStack_8c & uStack_88 ^ uStack_94 & uStack_88 ^ uStack_94 & uStack_8c) +
                     ((uStack_94 << 0x13 | uStack_94 >> 0xd) ^ (uStack_94 << 0x1e | uStack_94 >> 2)
                     ^ (uStack_94 << 10 | uStack_94 >> 0x16));
    uVar9 = *(uint *)(puStack_b4 + -0x3c);
    uVar2 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
    auStack_60[1] = uVar2;
    iVar3 = (~uVar7 & uStack_84 ^ uStack_90 & uVar7) +
            ((uVar7 * 0x80 | uVar7 >> 0x19) ^
            (uVar7 * 0x200000 | uVar7 >> 0xb) ^ (uVar7 * 0x4000000 | uVar7 >> 6)) +
            uStack_80 + 0x71374491 + uVar2;
    uVar8 = uStack_88 + iVar3;
    uVar4 = iVar3 + (uStack_94 & uStack_8c ^ (uStack_94 ^ uStack_8c) & uVar12) +
                    ((uVar12 * 0x80000 | uVar12 >> 0xd) ^ (uVar12 * 0x40000000 | uVar12 >> 2) ^
                    (uVar12 * 0x400 | uVar12 >> 0x16));
    uVar9 = *(uint *)(puStack_b4 + -0x38);
    auStack_60[2] = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
    iVar3 = (~uVar8 & uStack_90 ^ uVar8 & uVar7) +
            ((uVar8 * 0x200000 | uVar8 >> 0xb) ^ (uVar8 * 0x4000000 | uVar8 >> 6) ^
            (uVar8 * 0x80 | uVar8 >> 0x19)) + uStack_84 + 0xb5c0fbcf + auStack_60[2];
    uVar9 = *(uint *)(puStack_b4 + -0x34);
    uVar10 = uStack_8c + iVar3;
    uVar5 = iVar3 + (uVar12 & uStack_94 ^ (uStack_94 ^ uVar12) & uVar4) +
                    ((uVar4 * 0x80000 | uVar4 >> 0xd) ^ (uVar4 * 0x40000000 | uVar4 >> 2) ^
                    (uVar4 * 0x400 | uVar4 >> 0x16));
    auStack_60[3] = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
    iVar3 = (~uVar10 & uVar7 ^ uVar8 & uVar10) +
            ((uVar10 * 0x200000 | uVar10 >> 0xb) ^ (uVar10 * 0x4000000 | uVar10 >> 6) ^
            (uVar10 * 0x80 | uVar10 >> 0x19)) + uStack_90 + 0xe9b5dba5 + auStack_60[3];
    uVar9 = iVar3 + uStack_94;
    uVar11 = *(uint *)(puStack_b4 + -0x30);
    uVar6 = iVar3 + (uVar12 & uVar4 ^ (uVar4 ^ uVar12) & uVar5) +
                    ((uVar5 * 0x80000 | uVar5 >> 0xd) ^ (uVar5 * 0x40000000 | uVar5 >> 2) ^
                    (uVar5 * 0x400 | uVar5 >> 0x16));
    uStack_50 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18;
    iVar3 = (~uVar9 & uVar8 ^ uVar10 & uVar9) +
            uStack_50 + 0x3956c25b +
            ((uVar9 * 0x200000 | uVar9 >> 0xb) ^ (uVar9 * 0x4000000 | uVar9 >> 6) ^
            (uVar9 * 0x80 | uVar9 >> 0x19)) + uVar7;
    uVar12 = uVar12 + iVar3;
    uVar1 = iVar3 + (uVar4 & uVar5 ^ uVar6 & (uVar4 ^ uVar5)) +
                    ((uVar6 * 0x80000 | uVar6 >> 0xd) ^ (uVar6 * 0x40000000 | uVar6 >> 2) ^
                    (uVar6 * 0x400 | uVar6 >> 0x16));
    uVar7 = *(uint *)(puStack_b4 + -0x2c);
    uStack_4c = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
    iVar3 = (~uVar12 & uVar10 ^ uVar12 & uVar9) +
            uStack_4c + 0x59f111f1 +
            ((uVar12 * 0x200000 | uVar12 >> 0xb) ^ (uVar12 * 0x4000000 | uVar12 >> 6) ^
            (uVar12 * 0x80 | uVar12 >> 0x19)) + uVar8;
    uVar4 = uVar4 + iVar3;
    uVar7 = iVar3 + (uVar5 & uVar6 ^ (uVar6 ^ uVar5) & uVar1) +
                    ((uVar1 * 0x80000 | uVar1 >> 0xd) ^ (uVar1 * 0x40000000 | uVar1 >> 2) ^
                    (uVar1 * 0x400 | uVar1 >> 0x16));
    uVar11 = *(uint *)(puStack_b4 + -0x28);
    uStack_48 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18;
    iVar3 = (~uVar4 & uVar9 ^ uVar12 & uVar4) +
            uVar10 + uStack_48 + 0x923f82a4 +
                     ((uVar4 * 0x200000 | uVar4 >> 0xb) ^ (uVar4 * 0x4000000 | uVar4 >> 6) ^
                     (uVar4 * 0x80 | uVar4 >> 0x19));
    uVar5 = uVar5 + iVar3;
    uVar11 = iVar3 + (uVar6 & uVar1 ^ (uVar1 ^ uVar6) & uVar7) +
                     ((uVar7 * 0x80000 | uVar7 >> 0xd) ^ (uVar7 * 0x40000000 | uVar7 >> 2) ^
                     (uVar7 * 0x400 | uVar7 >> 0x16));
    uVar8 = *(uint *)(puStack_b4 + -0x24);
    uStack_44 = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
    iVar3 = (~uVar5 & uVar12 ^ uVar4 & uVar5) +
            uStack_44 + 0xab1c5ed5 +
            ((uVar5 * 0x200000 | uVar5 >> 0xb) ^ (uVar5 * 0x4000000 | uVar5 >> 6) ^
            (uVar5 * 0x80 | uVar5 >> 0x19)) + uVar9;
    uVar8 = *(uint *)(puStack_b4 + -0x20);
    uVar6 = uVar6 + iVar3;
    uVar9 = iVar3 + (uVar1 & uVar7 ^ (uVar7 ^ uVar1) & uVar11) +
                    ((uVar11 * 0x80000 | uVar11 >> 0xd) ^ (uVar11 * 0x40000000 | uVar11 >> 2) ^
                    (uVar11 * 0x400 | uVar11 >> 0x16));
    uStack_40 = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
    iVar3 = (uVar4 & ~uVar6 ^ uVar5 & uVar6) +
            uVar12 + uStack_40 + 0xd807aa98 +
                     ((uVar6 * 0x200000 | uVar6 >> 0xb) ^ (uVar6 * 0x4000000 | uVar6 >> 6) ^
                     (uVar6 * 0x80 | uVar6 >> 0x19));
    uStack_cc = iVar3 + (uVar7 & uVar11 ^ (uVar7 ^ uVar11) & uVar9) +
                        ((uVar9 * 0x80000 | uVar9 >> 0xd) ^ (uVar9 * 0x40000000 | uVar9 >> 2) ^
                        (uVar9 * 0x400 | uVar9 >> 0x16));
    uVar1 = uVar1 + iVar3;
    uVar12 = *(uint *)(puStack_b4 + -0x1c);
    uStack_a8 = uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 | uVar12 << 0x18;
    uStack_3c = uStack_a8;
    iVar3 = (~uVar1 & uVar5 ^ uVar6 & uVar1) +
            uVar4 + uStack_a8 + 0x12835b01 +
                    ((uVar1 * 0x200000 | uVar1 >> 0xb) ^ (uVar1 * 0x4000000 | uVar1 >> 6) ^
                    (uVar1 * 0x80 | uVar1 >> 0x19));
    uVar7 = uVar7 + iVar3;
    uStack_c8 = iVar3 + (uVar9 & uVar11 ^ (uVar9 ^ uVar11) & uStack_cc) +
                        ((uStack_cc * 0x80000 | uStack_cc >> 0xd) ^
                         (uStack_cc * 0x40000000 | uStack_cc >> 2) ^
                        (uStack_cc * 0x400 | uStack_cc >> 0x16));
    uVar12 = *(uint *)(puStack_b4 + -0x18);
    uStack_38 = uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 | uVar12 << 0x18;
    iVar3 = (~uVar7 & uVar6 ^ uVar1 & uVar7) +
            uVar5 + uStack_38 + 0x243185be +
                    ((uVar7 * 0x200000 | uVar7 >> 0xb) ^ (uVar7 * 0x4000000 | uVar7 >> 6) ^
                    (uVar7 * 0x80 | uVar7 >> 0x19));
    uVar11 = uVar11 + iVar3;
    uVar12 = *(uint *)(puStack_b4 + -0x14);
    uStack_c0 = iVar3 + (uVar9 & uStack_cc ^ (uStack_cc ^ uVar9) & uStack_c8) +
                        ((uStack_c8 * 0x80000 | uStack_c8 >> 0xd) ^
                         (uStack_c8 * 0x40000000 | uStack_c8 >> 2) ^
                        (uStack_c8 * 0x400 | uStack_c8 >> 0x16));
    uStack_34 = uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 | uVar12 << 0x18;
    iVar3 = (~uVar11 & uVar1 ^ uVar7 & uVar11) +
            uVar6 + uStack_34 + 0x550c7dc3 +
                    ((uVar11 * 0x200000 | uVar11 >> 0xb) ^ (uVar11 * 0x4000000 | uVar11 >> 6) ^
                    (uVar11 * 0x80 | uVar11 >> 0x19));
    uVar12 = *(uint *)(puStack_b4 + -0x10);
    uVar9 = uVar9 + iVar3;
    uStack_c4 = iVar3 + (uStack_cc & uStack_c8 ^ uStack_c0 & (uStack_cc ^ uStack_c8)) +
                        ((uStack_c0 * 0x80000 | uStack_c0 >> 0xd) ^
                         (uStack_c0 * 0x40000000 | uStack_c0 >> 2) ^
                        (uStack_c0 * 0x400 | uStack_c0 >> 0x16));
    uStack_30 = uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 | uVar12 << 0x18;
    iVar3 = (~uVar9 & uVar7 ^ uVar9 & uVar11) +
            uStack_30 + 0x72be5d74 +
            ((uVar9 * 0x200000 | uVar9 >> 0xb) ^ (uVar9 * 0x4000000 | uVar9 >> 6) ^
            (uVar9 * 0x80 | uVar9 >> 0x19)) + uVar1;
    uStack_cc = uStack_cc + iVar3;
    uStack_dc = iVar3 + (uStack_c8 & uStack_c0 ^ (uStack_c0 ^ uStack_c8) & uStack_c4) +
                        ((uStack_c4 * 0x80000 | uStack_c4 >> 0xd) ^
                         (uStack_c4 * 0x40000000 | uStack_c4 >> 2) ^
                        (uStack_c4 * 0x400 | uStack_c4 >> 0x16));
    uVar12 = *(uint *)(puStack_b4 + -0xc);
    uStack_2c = uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 | uVar12 << 0x18;
    iVar3 = (~uStack_cc & uVar11 ^ uVar9 & uStack_cc) +
            uStack_2c + 0x80deb1fe +
            ((uStack_cc * 0x200000 | uStack_cc >> 0xb) ^ (uStack_cc * 0x4000000 | uStack_cc >> 6) ^
            (uStack_cc * 0x80 | uStack_cc >> 0x19)) + uVar7;
    uStack_e0 = iVar3 + (uStack_c0 & uStack_c4 ^ uStack_dc & (uStack_c0 ^ uStack_c4)) +
                        ((uStack_dc * 0x80000 | uStack_dc >> 0xd) ^
                         (uStack_dc * 0x40000000 | uStack_dc >> 2) ^
                        (uStack_dc * 0x400 | uStack_dc >> 0x16));
    uStack_c8 = uStack_c8 + iVar3;
    uVar7 = *(uint *)(puStack_b4 + -8);
    uVar12 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
    uStack_28 = uVar12;
    iVar3 = (uVar9 & ~uStack_c8 ^ uStack_cc & uStack_c8) +
            uVar11 + uVar12 + 0x9bdc06a7 +
                     ((uStack_c8 * 0x200000 | uStack_c8 >> 0xb) ^
                      (uStack_c8 * 0x4000000 | uStack_c8 >> 6) ^
                     (uStack_c8 * 0x80 | uStack_c8 >> 0x19));
    uStack_c0 = uStack_c0 + iVar3;
    uStack_d4 = iVar3 + (uStack_dc & uStack_c4 ^ uStack_e0 & (uStack_dc ^ uStack_c4)) +
                        ((uStack_e0 * 0x80000 | uStack_e0 >> 0xd) ^
                         (uStack_e0 * 0x40000000 | uStack_e0 >> 2) ^
                        (uStack_e0 * 0x400 | uStack_e0 >> 0x16));
    uVar7 = *(uint *)(puStack_b4 + -4);
    uStack_24 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
    iVar3 = uStack_24 + 0xc19bf174 +
            ((uStack_c0 * 0x200000 | uStack_c0 >> 0xb) ^ (uStack_c0 * 0x4000000 | uStack_c0 >> 6) ^
            (uStack_c0 * 0x80 | uStack_c0 >> 0x19)) + uVar9 +
            (uStack_c8 & uStack_c0 ^ ~uStack_c0 & uStack_cc);
    puStack_d8 = K256;
    uStack_98 = 0x1e;
    uStack_c4 = uStack_c4 + iVar3;
    uStack_b8 = 0x1d;
    uStack_d0 = iVar3 + (uStack_dc & uStack_e0 ^ (uStack_e0 ^ uStack_dc) & uStack_d4) +
                        ((uStack_d4 * 0x80000 | uStack_d4 >> 0xd) ^
                         (uStack_d4 * 0x40000000 | uStack_d4 >> 2) ^
                        (uStack_d4 * 0x400 | uStack_d4 >> 0x16));
    uStack_e4 = 0x10;
    uVar7 = 0x11;
    while( true ) {
      uVar11 = uStack_e4 & 0xf;
      uStack_a8 = uStack_a8 +
                  ((uVar2 << 0xe | uVar2 >> 0x12) ^ (uVar2 << 0x19 | uVar2 >> 7) ^ uVar2 >> 3) +
                  ((uVar12 << 0xd | uVar12 >> 0x13) ^ (uVar12 << 0xf | uVar12 >> 0x11) ^
                  uVar12 >> 10) + uStack_ac;
      auStack_60[uVar11] = uStack_a8;
      iVar3 = uStack_a8 +
              (uStack_c4 & uStack_c0 ^ uStack_c8 & ~uStack_c4) +
              ((uStack_c4 << 0x15 | uStack_c4 >> 0xb) ^ (uStack_c4 << 0x1a | uStack_c4 >> 6) ^
              (uStack_c4 << 7 | uStack_c4 >> 0x19)) + *(int *)(puStack_d8 + 0x40) + uStack_cc;
      uVar4 = uStack_e4 + 2 & 0xf;
      uStack_cc = iVar3 + (uStack_d4 & uStack_e0 ^ uStack_d0 & uStack_e0 ^ uStack_d4 & uStack_d0) +
                          ((uStack_d0 << 0x13 | uStack_d0 >> 0xd) ^
                           (uStack_d0 << 0x1e | uStack_d0 >> 2) ^
                          (uStack_d0 << 10 | uStack_d0 >> 0x16));
      uStack_dc = uStack_dc + iVar3;
      uVar9 = auStack_60[uVar4];
      uVar8 = uStack_e4 + 0xf & 0xf;
      uVar12 = auStack_60[uVar8];
      uVar9 = ((uVar9 << 0xe | uVar9 >> 0x12) ^ (uVar9 << 0x19 | uVar9 >> 7) ^ uVar9 >> 3) +
              auStack_60[uVar7 & 0xf] + auStack_60[uStack_e4 + 10 & 0xf] +
              ((uVar12 << 0xd | uVar12 >> 0x13) ^ (uVar12 << 0xf | uVar12 >> 0x11) ^ uVar12 >> 10);
      auStack_60[uVar7 & 0xf] = uVar9;
      iVar3 = (~uStack_dc & uStack_c0 ^ uStack_c4 & uStack_dc) +
              ((uStack_dc * 0x200000 | uStack_dc >> 0xb) ^ (uStack_dc * 0x4000000 | uStack_dc >> 6)
              ^ (uStack_dc * 0x80 | uStack_dc >> 0x19)) + *(int *)(puStack_d8 + 0x44) + uStack_c8 +
              uVar9;
      uStack_c8 = iVar3 + ((uStack_d0 ^ uStack_d4) & uStack_cc ^ uStack_d4 & uStack_d0) +
                          ((uStack_cc * 0x80000 | uStack_cc >> 0xd) ^
                           (uStack_cc * 0x40000000 | uStack_cc >> 2) ^
                          (uStack_cc * 0x400 | uStack_cc >> 0x16));
      uStack_e0 = iVar3 + uStack_e0;
      uVar6 = uStack_e4 + 3 & 0xf;
      uVar7 = auStack_60[uVar6];
      uVar9 = auStack_60[uVar11];
      uVar7 = ((uVar9 << 0xd | uVar9 >> 0x13) ^ (uVar9 << 0xf | uVar9 >> 0x11) ^ uVar9 >> 10) +
              auStack_60[uVar4] + auStack_60[uStack_e4 + 0xb & 0xf] +
              ((uVar7 << 0xe | uVar7 >> 0x12) ^ (uVar7 << 0x19 | uVar7 >> 7) ^ uVar7 >> 3);
      auStack_60[uVar4] = uVar7;
      iVar3 = (~uStack_e0 & uStack_c4 ^ uStack_dc & uStack_e0) +
              uVar7 + ((uStack_e0 * 0x200000 | uStack_e0 >> 0xb) ^
                       (uStack_e0 * 0x4000000 | uStack_e0 >> 6) ^
                      (uStack_e0 * 0x80 | uStack_e0 >> 0x19)) + *(int *)(puStack_d8 + 0x48) +
                      uStack_c0;
      uStack_d4 = uStack_d4 + iVar3;
      uStack_c0 = iVar3 + (uStack_cc & uStack_d0 ^ uStack_c8 & (uStack_cc ^ uStack_d0)) +
                          ((uStack_c8 * 0x80000 | uStack_c8 >> 0xd) ^
                           (uStack_c8 * 0x40000000 | uStack_c8 >> 2) ^
                          (uStack_c8 * 0x400 | uStack_c8 >> 0x16));
      uVar12 = uStack_e4 + 4 & 0xf;
      uVar7 = auStack_60[uVar12];
      uVar9 = auStack_60[uStack_e4 + 0x11 & 0xf];
      uVar7 = ((uVar7 << 0xe | uVar7 >> 0x12) ^ (uVar7 << 0x19 | uVar7 >> 7) ^ uVar7 >> 3) +
              auStack_60[uVar6] + auStack_60[uStack_e4 + 0xc & 0xf] +
              ((uVar9 << 0xd | uVar9 >> 0x13) ^ (uVar9 << 0xf | uVar9 >> 0x11) ^ uVar9 >> 10);
      auStack_60[uVar6] = uVar7;
      iVar3 = (~uStack_d4 & uStack_dc ^ uStack_e0 & uStack_d4) +
              uVar7 + ((uStack_d4 * 0x200000 | uStack_d4 >> 0xb) ^
                       (uStack_d4 * 0x4000000 | uStack_d4 >> 6) ^
                      (uStack_d4 * 0x80 | uStack_d4 >> 0x19)) + *(int *)(puStack_d8 + 0x4c) +
                      uStack_c4;
      uStack_d0 = uStack_d0 + iVar3;
      uStack_c4 = iVar3 + (uStack_cc & uStack_c8 ^ uStack_c0 & (uStack_c8 ^ uStack_cc)) +
                          ((uStack_c0 * 0x80000 | uStack_c0 >> 0xd) ^
                           (uStack_c0 * 0x40000000 | uStack_c0 >> 2) ^
                          (uStack_c0 * 0x400 | uStack_c0 >> 0x16));
      uVar4 = uStack_e4 + 5 & 0xf;
      uVar7 = auStack_60[uVar4];
      uVar9 = auStack_60[uStack_e4 + 0x12 & 0xf];
      uVar7 = ((uVar7 << 0xe | uVar7 >> 0x12) ^ (uVar7 << 0x19 | uVar7 >> 7) ^ uVar7 >> 3) +
              auStack_60[uVar12] + auStack_60[uStack_b8 & 0xf] +
              ((uVar9 << 0xd | uVar9 >> 0x13) ^ (uVar9 << 0xf | uVar9 >> 0x11) ^ uVar9 >> 10);
      auStack_60[uVar12] = uVar7;
      iVar3 = (~uStack_d0 & uStack_e0 ^ uStack_d4 & uStack_d0) +
              uVar7 + ((uStack_d0 * 0x200000 | uStack_d0 >> 0xb) ^
                       (uStack_d0 * 0x4000000 | uStack_d0 >> 6) ^
                      (uStack_d0 * 0x80 | uStack_d0 >> 0x19)) + *(int *)(puStack_d8 + 0x50) +
                      uStack_dc;
      uStack_cc = uStack_cc + iVar3;
      uStack_dc = iVar3 + (uStack_c8 & uStack_c0 ^ uStack_c4 & (uStack_c0 ^ uStack_c8)) +
                          ((uStack_c4 * 0x80000 | uStack_c4 >> 0xd) ^
                           (uStack_c4 * 0x40000000 | uStack_c4 >> 2) ^
                          (uStack_c4 * 0x400 | uStack_c4 >> 0x16));
      uVar12 = uStack_e4 + 6 & 0xf;
      uVar7 = auStack_60[uVar12];
      uVar9 = auStack_60[uStack_e4 + 0x13 & 0xf];
      uVar7 = ((uVar7 << 0xe | uVar7 >> 0x12) ^ (uVar7 << 0x19 | uVar7 >> 7) ^ uVar7 >> 3) +
              auStack_60[uVar4] + auStack_60[uStack_98 & 0xf] +
              ((uVar9 << 0xd | uVar9 >> 0x13) ^ (uVar9 << 0xf | uVar9 >> 0x11) ^ uVar9 >> 10);
      auStack_60[uVar4] = uVar7;
      iVar3 = (uStack_d4 & ~uStack_cc ^ uStack_d0 & uStack_cc) +
              uVar7 + ((uStack_cc * 0x200000 | uStack_cc >> 0xb) ^
                       (uStack_cc * 0x4000000 | uStack_cc >> 6) ^
                      (uStack_cc * 0x80 | uStack_cc >> 0x19)) + *(int *)(puStack_d8 + 0x54) +
              uStack_e0;
      uStack_c8 = uStack_c8 + iVar3;
      uStack_e0 = iVar3 + (uStack_c0 & uStack_c4 ^ uStack_dc & (uStack_c4 ^ uStack_c0)) +
                          ((uStack_dc * 0x80000 | uStack_dc >> 0xd) ^
                           (uStack_dc * 0x40000000 | uStack_dc >> 2) ^
                          (uStack_dc * 0x400 | uStack_dc >> 0x16));
      uVar6 = uStack_e4 + 7 & 0xf;
      uVar7 = auStack_60[uVar6];
      uVar9 = auStack_60[uStack_e4 + 0x14 & 0xf];
      uVar7 = ((uVar7 << 0xe | uVar7 >> 0x12) ^ (uVar7 << 0x19 | uVar7 >> 7) ^ uVar7 >> 3) +
              auStack_60[uVar8] + auStack_60[uVar12] +
              ((uVar9 << 0xd | uVar9 >> 0x13) ^ (uVar9 << 0xf | uVar9 >> 0x11) ^ uVar9 >> 10);
      auStack_60[uVar12] = uVar7;
      uVar4 = uStack_e4 + 8;
      iVar3 = (~uStack_c8 & uStack_d0 ^ uStack_cc & uStack_c8) +
              uVar7 + ((uStack_c8 * 0x200000 | uStack_c8 >> 0xb) ^
                       (uStack_c8 * 0x4000000 | uStack_c8 >> 6) ^
                      (uStack_c8 * 0x80 | uStack_c8 >> 0x19)) + *(int *)(puStack_d8 + 0x58) +
              uStack_d4;
      uStack_c0 = uStack_c0 + iVar3;
      uStack_d4 = iVar3 + (uStack_c4 & uStack_dc ^ uStack_e0 & (uStack_dc ^ uStack_c4)) +
                          ((uStack_e0 * 0x80000 | uStack_e0 >> 0xd) ^
                           (uStack_e0 * 0x40000000 | uStack_e0 >> 2) ^
                          (uStack_e0 * 0x400 | uStack_e0 >> 0x16));
      uStack_b8 = uStack_e4 + 0x15;
      uVar7 = auStack_60[uVar4 & 0xf];
      uVar9 = auStack_60[uStack_b8 & 0xf];
      uVar7 = ((uVar7 << 0xe | uVar7 >> 0x12) ^ (uVar7 << 0x19 | uVar7 >> 7) ^ uVar7 >> 3) +
              auStack_60[uVar11] + auStack_60[uVar6] +
              (uVar9 >> 10 ^ (uVar9 << 0xd | uVar9 >> 0x13) ^ (uVar9 << 0xf | uVar9 >> 0x11));
      auStack_60[uVar6] = uVar7;
      iVar3 = (~uStack_c0 & uStack_cc ^ uStack_c8 & uStack_c0) +
              uVar7 + ((uStack_c0 * 0x200000 | uStack_c0 >> 0xb) ^
                       (uStack_c0 * 0x4000000 | uStack_c0 >> 6) ^
                      (uStack_c0 * 0x80 | uStack_c0 >> 0x19)) + *(int *)(puStack_d8 + 0x5c) +
              uStack_d0;
      uStack_c4 = uStack_c4 + iVar3;
      uStack_d0 = iVar3 + (uStack_dc & uStack_e0 ^ (uStack_e0 ^ uStack_dc) & uStack_d4) +
                          ((uStack_d4 * 0x80000 | uStack_d4 >> 0xd) ^
                           (uStack_d4 * 0x40000000 | uStack_d4 >> 2) ^
                          (uStack_d4 * 0x400 | uStack_d4 >> 0x16));
      if (uVar4 == 0x40) break;
      uVar7 = uStack_e4 + 9;
      uStack_98 = uStack_e4 + 0x16;
      uStack_ac = auStack_60[uVar4 & 0xf];
      uVar2 = auStack_60[uVar7 & 0xf];
      uVar12 = auStack_60[uStack_98 & 0xf];
      uStack_a8 = auStack_60[uStack_e4 + 0x11 & 0xf];
      uStack_e4 = uVar4;
      puStack_d8 = puStack_d8 + 0x20;
    }
    uStack_94 = uStack_94 + uStack_d0;
    uStack_8c = uStack_8c + uStack_d4;
    uStack_88 = uStack_88 + uStack_e0;
    c->h[0] = uStack_94;
    c->h[1] = uStack_8c;
    uStack_7c = uStack_7c + uStack_dc;
    uStack_90 = uStack_90 + uStack_c4;
    c->h[2] = uStack_88;
    uStack_84 = uStack_84 + uStack_c0;
    c->h[3] = uStack_7c;
    c->h[4] = uStack_90;
    c->h[5] = uStack_84;
    uStack_80 = uStack_80 + uStack_c8;
    iStack_74 = iStack_74 + -1;
    puStack_b4 = puStack_b4 + 0x40;
    c->h[6] = uStack_80;
    uStack_78 = uStack_78 + uStack_cc;
    c->h[7] = uStack_78;
  } while (iStack_74 != -1);
  if (iStack_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

