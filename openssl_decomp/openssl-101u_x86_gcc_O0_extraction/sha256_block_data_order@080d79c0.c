
void __regparm3 sha256_block_data_order(uint *param_1,int param_2,int param_3)

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
  uint local_e4;
  uint local_e0;
  uint local_dc;
  undefined1 *local_d8;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_b8;
  int local_b4;
  uint local_ac;
  uint local_a8;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  int local_74;
  uint local_60 [4];
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_74 = param_3 + -1;
  if (param_3 != 0) {
    local_94 = *param_1;
    local_8c = param_1[1];
    local_88 = param_1[2];
    local_7c = param_1[3];
    local_90 = param_1[4];
    local_84 = param_1[5];
    local_80 = param_1[6];
    local_78 = param_1[7];
    local_b4 = param_2 + 0x40;
    do {
      uVar7 = *(uint *)(local_b4 + -0x40);
      local_ac = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
      local_60[0] = local_ac;
      iVar3 = local_78 + 0x428a2f98 + (local_90 & local_84 ^ ~local_90 & local_80) + local_ac +
              ((local_90 << 0x15 | local_90 >> 0xb) ^ (local_90 << 0x1a | local_90 >> 6) ^
              (local_90 << 7 | local_90 >> 0x19));
      uVar7 = iVar3 + local_7c;
      uVar12 = iVar3 + (local_8c & local_88 ^ local_94 & local_88 ^ local_94 & local_8c) +
                       ((local_94 << 0x13 | local_94 >> 0xd) ^ (local_94 << 0x1e | local_94 >> 2) ^
                       (local_94 << 10 | local_94 >> 0x16));
      uVar9 = *(uint *)(local_b4 + -0x3c);
      uVar2 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
      local_60[1] = uVar2;
      iVar3 = (~uVar7 & local_84 ^ local_90 & uVar7) +
              ((uVar7 * 0x80 | uVar7 >> 0x19) ^
              (uVar7 * 0x200000 | uVar7 >> 0xb) ^ (uVar7 * 0x4000000 | uVar7 >> 6)) +
              local_80 + 0x71374491 + uVar2;
      uVar8 = local_88 + iVar3;
      uVar4 = iVar3 + (local_94 & local_8c ^ (local_94 ^ local_8c) & uVar12) +
                      ((uVar12 * 0x80000 | uVar12 >> 0xd) ^ (uVar12 * 0x40000000 | uVar12 >> 2) ^
                      (uVar12 * 0x400 | uVar12 >> 0x16));
      uVar9 = *(uint *)(local_b4 + -0x38);
      local_60[2] = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
      iVar3 = (~uVar8 & local_90 ^ uVar8 & uVar7) +
              ((uVar8 * 0x200000 | uVar8 >> 0xb) ^ (uVar8 * 0x4000000 | uVar8 >> 6) ^
              (uVar8 * 0x80 | uVar8 >> 0x19)) + local_84 + 0xb5c0fbcf + local_60[2];
      uVar9 = *(uint *)(local_b4 + -0x34);
      uVar10 = local_8c + iVar3;
      uVar5 = iVar3 + (uVar12 & local_94 ^ (local_94 ^ uVar12) & uVar4) +
                      ((uVar4 * 0x80000 | uVar4 >> 0xd) ^ (uVar4 * 0x40000000 | uVar4 >> 2) ^
                      (uVar4 * 0x400 | uVar4 >> 0x16));
      local_60[3] = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
      iVar3 = (~uVar10 & uVar7 ^ uVar8 & uVar10) +
              ((uVar10 * 0x200000 | uVar10 >> 0xb) ^ (uVar10 * 0x4000000 | uVar10 >> 6) ^
              (uVar10 * 0x80 | uVar10 >> 0x19)) + local_90 + 0xe9b5dba5 + local_60[3];
      uVar9 = iVar3 + local_94;
      uVar11 = *(uint *)(local_b4 + -0x30);
      uVar6 = iVar3 + (uVar12 & uVar4 ^ (uVar4 ^ uVar12) & uVar5) +
                      ((uVar5 * 0x80000 | uVar5 >> 0xd) ^ (uVar5 * 0x40000000 | uVar5 >> 2) ^
                      (uVar5 * 0x400 | uVar5 >> 0x16));
      local_50 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18
      ;
      iVar3 = (~uVar9 & uVar8 ^ uVar10 & uVar9) +
              local_50 + 0x3956c25b +
              ((uVar9 * 0x200000 | uVar9 >> 0xb) ^ (uVar9 * 0x4000000 | uVar9 >> 6) ^
              (uVar9 * 0x80 | uVar9 >> 0x19)) + uVar7;
      uVar12 = uVar12 + iVar3;
      uVar1 = iVar3 + (uVar4 & uVar5 ^ uVar6 & (uVar4 ^ uVar5)) +
                      ((uVar6 * 0x80000 | uVar6 >> 0xd) ^ (uVar6 * 0x40000000 | uVar6 >> 2) ^
                      (uVar6 * 0x400 | uVar6 >> 0x16));
      uVar7 = *(uint *)(local_b4 + -0x2c);
      local_4c = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
      iVar3 = (~uVar12 & uVar10 ^ uVar12 & uVar9) +
              local_4c + 0x59f111f1 +
              ((uVar12 * 0x200000 | uVar12 >> 0xb) ^ (uVar12 * 0x4000000 | uVar12 >> 6) ^
              (uVar12 * 0x80 | uVar12 >> 0x19)) + uVar8;
      uVar4 = uVar4 + iVar3;
      uVar7 = iVar3 + (uVar5 & uVar6 ^ (uVar6 ^ uVar5) & uVar1) +
                      ((uVar1 * 0x80000 | uVar1 >> 0xd) ^ (uVar1 * 0x40000000 | uVar1 >> 2) ^
                      (uVar1 * 0x400 | uVar1 >> 0x16));
      uVar11 = *(uint *)(local_b4 + -0x28);
      local_48 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18
      ;
      iVar3 = (~uVar4 & uVar9 ^ uVar12 & uVar4) +
              uVar10 + local_48 + 0x923f82a4 +
                       ((uVar4 * 0x200000 | uVar4 >> 0xb) ^ (uVar4 * 0x4000000 | uVar4 >> 6) ^
                       (uVar4 * 0x80 | uVar4 >> 0x19));
      uVar5 = uVar5 + iVar3;
      uVar11 = iVar3 + (uVar6 & uVar1 ^ (uVar1 ^ uVar6) & uVar7) +
                       ((uVar7 * 0x80000 | uVar7 >> 0xd) ^ (uVar7 * 0x40000000 | uVar7 >> 2) ^
                       (uVar7 * 0x400 | uVar7 >> 0x16));
      uVar8 = *(uint *)(local_b4 + -0x24);
      local_44 = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
      iVar3 = (~uVar5 & uVar12 ^ uVar4 & uVar5) +
              local_44 + 0xab1c5ed5 +
              ((uVar5 * 0x200000 | uVar5 >> 0xb) ^ (uVar5 * 0x4000000 | uVar5 >> 6) ^
              (uVar5 * 0x80 | uVar5 >> 0x19)) + uVar9;
      uVar8 = *(uint *)(local_b4 + -0x20);
      uVar6 = uVar6 + iVar3;
      uVar9 = iVar3 + (uVar1 & uVar7 ^ (uVar7 ^ uVar1) & uVar11) +
                      ((uVar11 * 0x80000 | uVar11 >> 0xd) ^ (uVar11 * 0x40000000 | uVar11 >> 2) ^
                      (uVar11 * 0x400 | uVar11 >> 0x16));
      local_40 = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
      iVar3 = (uVar4 & ~uVar6 ^ uVar5 & uVar6) +
              uVar12 + local_40 + 0xd807aa98 +
                       ((uVar6 * 0x200000 | uVar6 >> 0xb) ^ (uVar6 * 0x4000000 | uVar6 >> 6) ^
                       (uVar6 * 0x80 | uVar6 >> 0x19));
      local_cc = iVar3 + (uVar7 & uVar11 ^ (uVar7 ^ uVar11) & uVar9) +
                         ((uVar9 * 0x80000 | uVar9 >> 0xd) ^ (uVar9 * 0x40000000 | uVar9 >> 2) ^
                         (uVar9 * 0x400 | uVar9 >> 0x16));
      uVar1 = uVar1 + iVar3;
      uVar12 = *(uint *)(local_b4 + -0x1c);
      local_a8 = uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 | uVar12 << 0x18
      ;
      local_3c = local_a8;
      iVar3 = (~uVar1 & uVar5 ^ uVar6 & uVar1) +
              uVar4 + local_a8 + 0x12835b01 +
                      ((uVar1 * 0x200000 | uVar1 >> 0xb) ^ (uVar1 * 0x4000000 | uVar1 >> 6) ^
                      (uVar1 * 0x80 | uVar1 >> 0x19));
      uVar7 = uVar7 + iVar3;
      local_c8 = iVar3 + (uVar9 & uVar11 ^ (uVar9 ^ uVar11) & local_cc) +
                         ((local_cc * 0x80000 | local_cc >> 0xd) ^
                          (local_cc * 0x40000000 | local_cc >> 2) ^
                         (local_cc * 0x400 | local_cc >> 0x16));
      uVar12 = *(uint *)(local_b4 + -0x18);
      local_38 = uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 | uVar12 << 0x18
      ;
      iVar3 = (~uVar7 & uVar6 ^ uVar1 & uVar7) +
              uVar5 + local_38 + 0x243185be +
                      ((uVar7 * 0x200000 | uVar7 >> 0xb) ^ (uVar7 * 0x4000000 | uVar7 >> 6) ^
                      (uVar7 * 0x80 | uVar7 >> 0x19));
      uVar11 = uVar11 + iVar3;
      uVar12 = *(uint *)(local_b4 + -0x14);
      local_c0 = iVar3 + (uVar9 & local_cc ^ (local_cc ^ uVar9) & local_c8) +
                         ((local_c8 * 0x80000 | local_c8 >> 0xd) ^
                          (local_c8 * 0x40000000 | local_c8 >> 2) ^
                         (local_c8 * 0x400 | local_c8 >> 0x16));
      local_34 = uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 | uVar12 << 0x18
      ;
      iVar3 = (~uVar11 & uVar1 ^ uVar7 & uVar11) +
              uVar6 + local_34 + 0x550c7dc3 +
                      ((uVar11 * 0x200000 | uVar11 >> 0xb) ^ (uVar11 * 0x4000000 | uVar11 >> 6) ^
                      (uVar11 * 0x80 | uVar11 >> 0x19));
      uVar12 = *(uint *)(local_b4 + -0x10);
      uVar9 = uVar9 + iVar3;
      local_c4 = iVar3 + (local_cc & local_c8 ^ local_c0 & (local_cc ^ local_c8)) +
                         ((local_c0 * 0x80000 | local_c0 >> 0xd) ^
                          (local_c0 * 0x40000000 | local_c0 >> 2) ^
                         (local_c0 * 0x400 | local_c0 >> 0x16));
      local_30 = uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 | uVar12 << 0x18
      ;
      iVar3 = (~uVar9 & uVar7 ^ uVar9 & uVar11) +
              local_30 + 0x72be5d74 +
              ((uVar9 * 0x200000 | uVar9 >> 0xb) ^ (uVar9 * 0x4000000 | uVar9 >> 6) ^
              (uVar9 * 0x80 | uVar9 >> 0x19)) + uVar1;
      local_cc = local_cc + iVar3;
      local_dc = iVar3 + (local_c8 & local_c0 ^ (local_c0 ^ local_c8) & local_c4) +
                         ((local_c4 * 0x80000 | local_c4 >> 0xd) ^
                          (local_c4 * 0x40000000 | local_c4 >> 2) ^
                         (local_c4 * 0x400 | local_c4 >> 0x16));
      uVar12 = *(uint *)(local_b4 + -0xc);
      local_2c = uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 | uVar12 << 0x18
      ;
      iVar3 = (~local_cc & uVar11 ^ uVar9 & local_cc) +
              local_2c + 0x80deb1fe +
              ((local_cc * 0x200000 | local_cc >> 0xb) ^ (local_cc * 0x4000000 | local_cc >> 6) ^
              (local_cc * 0x80 | local_cc >> 0x19)) + uVar7;
      local_e0 = iVar3 + (local_c0 & local_c4 ^ local_dc & (local_c0 ^ local_c4)) +
                         ((local_dc * 0x80000 | local_dc >> 0xd) ^
                          (local_dc * 0x40000000 | local_dc >> 2) ^
                         (local_dc * 0x400 | local_dc >> 0x16));
      local_c8 = local_c8 + iVar3;
      uVar7 = *(uint *)(local_b4 + -8);
      uVar12 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
      local_28 = uVar12;
      iVar3 = (uVar9 & ~local_c8 ^ local_cc & local_c8) +
              uVar11 + uVar12 + 0x9bdc06a7 +
                       ((local_c8 * 0x200000 | local_c8 >> 0xb) ^
                        (local_c8 * 0x4000000 | local_c8 >> 6) ^
                       (local_c8 * 0x80 | local_c8 >> 0x19));
      local_c0 = local_c0 + iVar3;
      local_d4 = iVar3 + (local_dc & local_c4 ^ local_e0 & (local_dc ^ local_c4)) +
                         ((local_e0 * 0x80000 | local_e0 >> 0xd) ^
                          (local_e0 * 0x40000000 | local_e0 >> 2) ^
                         (local_e0 * 0x400 | local_e0 >> 0x16));
      uVar7 = *(uint *)(local_b4 + -4);
      local_24 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
      iVar3 = local_24 + 0xc19bf174 +
              ((local_c0 * 0x200000 | local_c0 >> 0xb) ^ (local_c0 * 0x4000000 | local_c0 >> 6) ^
              (local_c0 * 0x80 | local_c0 >> 0x19)) + uVar9 +
              (local_c8 & local_c0 ^ ~local_c0 & local_cc);
      local_d8 = K256;
      local_98 = 0x1e;
      local_c4 = local_c4 + iVar3;
      local_b8 = 0x1d;
      local_d0 = iVar3 + (local_dc & local_e0 ^ (local_e0 ^ local_dc) & local_d4) +
                         ((local_d4 * 0x80000 | local_d4 >> 0xd) ^
                          (local_d4 * 0x40000000 | local_d4 >> 2) ^
                         (local_d4 * 0x400 | local_d4 >> 0x16));
      local_e4 = 0x10;
      uVar7 = 0x11;
      while( true ) {
        uVar11 = local_e4 & 0xf;
        local_a8 = local_a8 +
                   ((uVar2 << 0xe | uVar2 >> 0x12) ^ (uVar2 << 0x19 | uVar2 >> 7) ^ uVar2 >> 3) +
                   ((uVar12 << 0xd | uVar12 >> 0x13) ^ (uVar12 << 0xf | uVar12 >> 0x11) ^
                   uVar12 >> 10) + local_ac;
        local_60[uVar11] = local_a8;
        iVar3 = local_a8 +
                (local_c4 & local_c0 ^ local_c8 & ~local_c4) +
                ((local_c4 << 0x15 | local_c4 >> 0xb) ^ (local_c4 << 0x1a | local_c4 >> 6) ^
                (local_c4 << 7 | local_c4 >> 0x19)) + *(int *)(local_d8 + 0x40) + local_cc;
        uVar4 = local_e4 + 2 & 0xf;
        local_cc = iVar3 + (local_d4 & local_e0 ^ local_d0 & local_e0 ^ local_d4 & local_d0) +
                           ((local_d0 << 0x13 | local_d0 >> 0xd) ^
                            (local_d0 << 0x1e | local_d0 >> 2) ^ (local_d0 << 10 | local_d0 >> 0x16)
                           );
        local_dc = local_dc + iVar3;
        uVar9 = local_60[uVar4];
        uVar8 = local_e4 + 0xf & 0xf;
        uVar12 = local_60[uVar8];
        uVar9 = ((uVar9 << 0xe | uVar9 >> 0x12) ^ (uVar9 << 0x19 | uVar9 >> 7) ^ uVar9 >> 3) +
                local_60[uVar7 & 0xf] + local_60[local_e4 + 10 & 0xf] +
                ((uVar12 << 0xd | uVar12 >> 0x13) ^ (uVar12 << 0xf | uVar12 >> 0x11) ^ uVar12 >> 10)
        ;
        local_60[uVar7 & 0xf] = uVar9;
        iVar3 = (~local_dc & local_c0 ^ local_c4 & local_dc) +
                ((local_dc * 0x200000 | local_dc >> 0xb) ^ (local_dc * 0x4000000 | local_dc >> 6) ^
                (local_dc * 0x80 | local_dc >> 0x19)) + *(int *)(local_d8 + 0x44) + local_c8 + uVar9
        ;
        local_c8 = iVar3 + ((local_d0 ^ local_d4) & local_cc ^ local_d4 & local_d0) +
                           ((local_cc * 0x80000 | local_cc >> 0xd) ^
                            (local_cc * 0x40000000 | local_cc >> 2) ^
                           (local_cc * 0x400 | local_cc >> 0x16));
        local_e0 = iVar3 + local_e0;
        uVar6 = local_e4 + 3 & 0xf;
        uVar7 = local_60[uVar6];
        uVar9 = local_60[uVar11];
        uVar7 = ((uVar9 << 0xd | uVar9 >> 0x13) ^ (uVar9 << 0xf | uVar9 >> 0x11) ^ uVar9 >> 10) +
                local_60[uVar4] + local_60[local_e4 + 0xb & 0xf] +
                ((uVar7 << 0xe | uVar7 >> 0x12) ^ (uVar7 << 0x19 | uVar7 >> 7) ^ uVar7 >> 3);
        local_60[uVar4] = uVar7;
        iVar3 = (~local_e0 & local_c4 ^ local_dc & local_e0) +
                uVar7 + ((local_e0 * 0x200000 | local_e0 >> 0xb) ^
                         (local_e0 * 0x4000000 | local_e0 >> 6) ^
                        (local_e0 * 0x80 | local_e0 >> 0x19)) + *(int *)(local_d8 + 0x48) + local_c0
        ;
        local_d4 = local_d4 + iVar3;
        local_c0 = iVar3 + (local_cc & local_d0 ^ local_c8 & (local_cc ^ local_d0)) +
                           ((local_c8 * 0x80000 | local_c8 >> 0xd) ^
                            (local_c8 * 0x40000000 | local_c8 >> 2) ^
                           (local_c8 * 0x400 | local_c8 >> 0x16));
        uVar12 = local_e4 + 4 & 0xf;
        uVar7 = local_60[uVar12];
        uVar9 = local_60[local_e4 + 0x11 & 0xf];
        uVar7 = ((uVar7 << 0xe | uVar7 >> 0x12) ^ (uVar7 << 0x19 | uVar7 >> 7) ^ uVar7 >> 3) +
                local_60[uVar6] + local_60[local_e4 + 0xc & 0xf] +
                ((uVar9 << 0xd | uVar9 >> 0x13) ^ (uVar9 << 0xf | uVar9 >> 0x11) ^ uVar9 >> 10);
        local_60[uVar6] = uVar7;
        iVar3 = (~local_d4 & local_dc ^ local_e0 & local_d4) +
                uVar7 + ((local_d4 * 0x200000 | local_d4 >> 0xb) ^
                         (local_d4 * 0x4000000 | local_d4 >> 6) ^
                        (local_d4 * 0x80 | local_d4 >> 0x19)) + *(int *)(local_d8 + 0x4c) + local_c4
        ;
        local_d0 = local_d0 + iVar3;
        local_c4 = iVar3 + (local_cc & local_c8 ^ local_c0 & (local_c8 ^ local_cc)) +
                           ((local_c0 * 0x80000 | local_c0 >> 0xd) ^
                            (local_c0 * 0x40000000 | local_c0 >> 2) ^
                           (local_c0 * 0x400 | local_c0 >> 0x16));
        uVar4 = local_e4 + 5 & 0xf;
        uVar7 = local_60[uVar4];
        uVar9 = local_60[local_e4 + 0x12 & 0xf];
        uVar7 = ((uVar7 << 0xe | uVar7 >> 0x12) ^ (uVar7 << 0x19 | uVar7 >> 7) ^ uVar7 >> 3) +
                local_60[uVar12] + local_60[local_b8 & 0xf] +
                ((uVar9 << 0xd | uVar9 >> 0x13) ^ (uVar9 << 0xf | uVar9 >> 0x11) ^ uVar9 >> 10);
        local_60[uVar12] = uVar7;
        iVar3 = (~local_d0 & local_e0 ^ local_d4 & local_d0) +
                uVar7 + ((local_d0 * 0x200000 | local_d0 >> 0xb) ^
                         (local_d0 * 0x4000000 | local_d0 >> 6) ^
                        (local_d0 * 0x80 | local_d0 >> 0x19)) + *(int *)(local_d8 + 0x50) + local_dc
        ;
        local_cc = local_cc + iVar3;
        local_dc = iVar3 + (local_c8 & local_c0 ^ local_c4 & (local_c0 ^ local_c8)) +
                           ((local_c4 * 0x80000 | local_c4 >> 0xd) ^
                            (local_c4 * 0x40000000 | local_c4 >> 2) ^
                           (local_c4 * 0x400 | local_c4 >> 0x16));
        uVar12 = local_e4 + 6 & 0xf;
        uVar7 = local_60[uVar12];
        uVar9 = local_60[local_e4 + 0x13 & 0xf];
        uVar7 = ((uVar7 << 0xe | uVar7 >> 0x12) ^ (uVar7 << 0x19 | uVar7 >> 7) ^ uVar7 >> 3) +
                local_60[uVar4] + local_60[local_98 & 0xf] +
                ((uVar9 << 0xd | uVar9 >> 0x13) ^ (uVar9 << 0xf | uVar9 >> 0x11) ^ uVar9 >> 10);
        local_60[uVar4] = uVar7;
        iVar3 = (local_d4 & ~local_cc ^ local_d0 & local_cc) +
                uVar7 + ((local_cc * 0x200000 | local_cc >> 0xb) ^
                         (local_cc * 0x4000000 | local_cc >> 6) ^
                        (local_cc * 0x80 | local_cc >> 0x19)) + *(int *)(local_d8 + 0x54) + local_e0
        ;
        local_c8 = local_c8 + iVar3;
        local_e0 = iVar3 + (local_c0 & local_c4 ^ local_dc & (local_c4 ^ local_c0)) +
                           ((local_dc * 0x80000 | local_dc >> 0xd) ^
                            (local_dc * 0x40000000 | local_dc >> 2) ^
                           (local_dc * 0x400 | local_dc >> 0x16));
        uVar6 = local_e4 + 7 & 0xf;
        uVar7 = local_60[uVar6];
        uVar9 = local_60[local_e4 + 0x14 & 0xf];
        uVar7 = ((uVar7 << 0xe | uVar7 >> 0x12) ^ (uVar7 << 0x19 | uVar7 >> 7) ^ uVar7 >> 3) +
                local_60[uVar8] + local_60[uVar12] +
                ((uVar9 << 0xd | uVar9 >> 0x13) ^ (uVar9 << 0xf | uVar9 >> 0x11) ^ uVar9 >> 10);
        local_60[uVar12] = uVar7;
        uVar4 = local_e4 + 8;
        iVar3 = (~local_c8 & local_d0 ^ local_cc & local_c8) +
                uVar7 + ((local_c8 * 0x200000 | local_c8 >> 0xb) ^
                         (local_c8 * 0x4000000 | local_c8 >> 6) ^
                        (local_c8 * 0x80 | local_c8 >> 0x19)) + *(int *)(local_d8 + 0x58) + local_d4
        ;
        local_c0 = local_c0 + iVar3;
        local_d4 = iVar3 + (local_c4 & local_dc ^ local_e0 & (local_dc ^ local_c4)) +
                           ((local_e0 * 0x80000 | local_e0 >> 0xd) ^
                            (local_e0 * 0x40000000 | local_e0 >> 2) ^
                           (local_e0 * 0x400 | local_e0 >> 0x16));
        local_b8 = local_e4 + 0x15;
        uVar7 = local_60[uVar4 & 0xf];
        uVar9 = local_60[local_b8 & 0xf];
        uVar7 = ((uVar7 << 0xe | uVar7 >> 0x12) ^ (uVar7 << 0x19 | uVar7 >> 7) ^ uVar7 >> 3) +
                local_60[uVar11] + local_60[uVar6] +
                (uVar9 >> 10 ^ (uVar9 << 0xd | uVar9 >> 0x13) ^ (uVar9 << 0xf | uVar9 >> 0x11));
        local_60[uVar6] = uVar7;
        iVar3 = (~local_c0 & local_cc ^ local_c8 & local_c0) +
                uVar7 + ((local_c0 * 0x200000 | local_c0 >> 0xb) ^
                         (local_c0 * 0x4000000 | local_c0 >> 6) ^
                        (local_c0 * 0x80 | local_c0 >> 0x19)) + *(int *)(local_d8 + 0x5c) + local_d0
        ;
        local_c4 = local_c4 + iVar3;
        local_d0 = iVar3 + (local_dc & local_e0 ^ (local_e0 ^ local_dc) & local_d4) +
                           ((local_d4 * 0x80000 | local_d4 >> 0xd) ^
                            (local_d4 * 0x40000000 | local_d4 >> 2) ^
                           (local_d4 * 0x400 | local_d4 >> 0x16));
        if (uVar4 == 0x40) break;
        uVar7 = local_e4 + 9;
        local_98 = local_e4 + 0x16;
        local_ac = local_60[uVar4 & 0xf];
        uVar2 = local_60[uVar7 & 0xf];
        uVar12 = local_60[local_98 & 0xf];
        local_a8 = local_60[local_e4 + 0x11 & 0xf];
        local_e4 = uVar4;
        local_d8 = local_d8 + 0x20;
      }
      local_94 = local_94 + local_d0;
      local_8c = local_8c + local_d4;
      local_88 = local_88 + local_e0;
      *param_1 = local_94;
      param_1[1] = local_8c;
      local_7c = local_7c + local_dc;
      local_90 = local_90 + local_c4;
      param_1[2] = local_88;
      local_84 = local_84 + local_c0;
      param_1[3] = local_7c;
      param_1[4] = local_90;
      param_1[5] = local_84;
      local_80 = local_80 + local_c8;
      local_74 = local_74 + -1;
      local_b4 = local_b4 + 0x40;
      param_1[6] = local_80;
      local_78 = local_78 + local_cc;
      param_1[7] = local_78;
    } while (local_74 != -1);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

