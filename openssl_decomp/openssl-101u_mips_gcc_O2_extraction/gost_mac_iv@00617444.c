
uint gost_mac_iv(int *param_1,uint param_2,uint param_3,byte *param_4,uint *param_5,int param_6)

{
  undefined *puVar1;
  undefined uVar5;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint in_v1;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined *puVar15;
  char *pcVar16;
  char *pcVar17;
  uint *puVar18;
  int unaff_s2;
  byte *pbVar19;
  int unaff_s3;
  int unaff_s4;
  int unaff_s5;
  uint *puVar20;
  int unaff_s6;
  int unaff_s7;
  uint uVar21;
  code *pcVar22;
  undefined *puVar23;
  int iVar24;
  int iVar25;
  undefined *puVar26;
  int unaff_s8;
  undefined4 uVar27;
  undefined auStack_d8 [16];
  undefined *puStack_c8;
  uint uStack_bc;
  uint uStack_b8;
  byte bStack_b4;
  byte bStack_b3;
  byte bStack_b2;
  byte bStack_b1;
  byte bStack_b0;
  byte bStack_af;
  byte bStack_ae;
  byte bStack_ad;
  byte bStack_ac;
  byte bStack_ab;
  byte bStack_aa;
  byte bStack_a9;
  byte bStack_a8;
  byte bStack_a7;
  byte bStack_a6;
  byte bStack_a5;
  byte bStack_a4;
  byte bStack_a3;
  byte bStack_a2;
  byte bStack_a1;
  byte bStack_a0;
  byte bStack_9f;
  byte bStack_9e;
  byte bStack_9d;
  byte bStack_9c;
  byte bStack_9b;
  byte bStack_9a;
  byte bStack_99;
  byte bStack_98;
  byte bStack_97;
  byte bStack_96;
  byte bStack_95;
  uint uStack_94;
  undefined *puStack_90;
  uint uStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  code *pcStack_6c;
  undefined *local_58;
  uint local_50;
  int local_4c;
  uint **local_48;
  byte *local_44;
  uint local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint *local_2c;
  
  local_58 = &_gp;
  uVar13 = param_3 & 3;
  local_48 = (uint **)PTR___stack_chk_guard_006a9ae8;
  local_38 = *(uint *)(param_3 + 4);
  puVar7 = *(uint **)PTR___stack_chk_guard_006a9ae8;
  uVar12 = param_3 + 3 & 3;
  local_3c = (*(int *)(param_3 - uVar13) << uVar13 * 8 | in_v1 & 0xffffffffU >> (4 - uVar13) * 8) &
             -1 << (uVar12 + 1) * 8 | *(uint *)((param_3 + 3) - uVar12) >> (3 - uVar12) * 8;
  local_44 = param_4;
  local_2c = puVar7;
  local_4c = param_6;
  if (param_5 < &DAT_00000008) {
    if (param_5 == (uint *)0x0) goto LAB_00617c8c;
    puVar7 = (uint *)0x0;
    puVar11 = (uint *)&DAT_00000008;
LAB_00617d20:
    local_34 = 0;
    local_30 = 0;
    uVar27 = (*(code *)PTR___memcpy_chk_006a9a48)
                       (&local_34,param_4 + (int)puVar7,(int)param_5 - (int)puVar7,8);
    mac_block(param_1,&local_3c,uVar27);
    puVar7 = puVar11;
  }
  else {
    unaff_s7 = *param_1;
    unaff_s6 = param_1[1];
    unaff_s5 = param_1[2];
    unaff_s4 = param_1[3];
    unaff_s3 = param_1[4];
    unaff_s2 = param_1[5];
    unaff_s8 = param_1[7];
    uVar21 = local_3c >> 0x18;
    uVar6 = local_3c >> 0x10 & 0xff;
    uVar9 = local_3c >> 8 & 0xff;
    local_3c = local_3c & 0xff;
    uVar14 = local_38 >> 0x18;
    uVar13 = local_38 >> 0x10 & 0xff;
    uVar12 = local_38 >> 8 & 0xff;
    local_38 = local_38 & 0xff;
    puVar11 = (uint *)&DAT_00000008;
    pbVar19 = param_4;
    do {
      puVar7 = puVar11;
      puVar11 = puVar7 + 2;
      local_50 = (uint)(param_5 < puVar11);
      local_3c = (uVar6 ^ pbVar19[1]) << 8 | (uVar9 ^ pbVar19[2]) << 0x10 | uVar21 ^ *pbVar19 |
                 (local_3c ^ pbVar19[3]) << 0x18;
      uVar6 = local_3c + unaff_s7;
      uVar6 = param_1[(uVar6 >> 0x18) + 8] | param_1[(uVar6 & 0xff) + 0x308] |
              param_1[(uVar6 * 0x100 >> 0x18) + 0x108] | param_1[(uVar6 * 0x10000 >> 0x18) + 0x208];
      local_38 = (uVar6 >> 0x15) + uVar6 * 0x800 ^
                 ((uVar13 ^ pbVar19[5]) << 8 | (uVar12 ^ pbVar19[6]) << 0x10 | uVar14 ^ pbVar19[4] |
                 (local_38 ^ pbVar19[7]) << 0x18);
      uVar13 = local_38 + unaff_s6;
      uVar13 = param_1[(uVar13 >> 0x18) + 8] | param_1[(uVar13 & 0xff) + 0x308] |
               param_1[(uVar13 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      local_3c = (uVar13 >> 0x15) + uVar13 * 0x800 ^ local_3c;
      uVar13 = local_3c + unaff_s5;
      uVar13 = param_1[(uVar13 >> 0x18) + 8] | param_1[(uVar13 & 0xff) + 0x308] |
               param_1[(uVar13 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      local_38 = (uVar13 >> 0x15) + uVar13 * 0x800 ^ local_38;
      uVar13 = local_38 + unaff_s4;
      uVar13 = param_1[(uVar13 >> 0x18) + 8] | param_1[(uVar13 & 0xff) + 0x308] |
               param_1[(uVar13 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      local_3c = (uVar13 >> 0x15) + uVar13 * 0x800 ^ local_3c;
      uVar13 = local_3c + unaff_s3;
      uVar13 = param_1[(uVar13 >> 0x18) + 8] | param_1[(uVar13 & 0xff) + 0x308] |
               param_1[(uVar13 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      local_38 = (uVar13 >> 0x15) + uVar13 * 0x800 ^ local_38;
      uVar13 = local_38 + unaff_s2;
      uVar13 = param_1[(uVar13 >> 0x18) + 8] | param_1[(uVar13 & 0xff) + 0x308] |
               param_1[(uVar13 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      local_3c = (uVar13 >> 0x15) + uVar13 * 0x800 ^ local_3c;
      uVar13 = local_3c + param_1[6];
      uVar13 = param_1[(uVar13 >> 0x18) + 8] | param_1[(uVar13 & 0xff) + 0x308] |
               param_1[(uVar13 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      local_38 = (uVar13 >> 0x15) + uVar13 * 0x800 ^ local_38;
      uVar13 = local_38 + unaff_s8;
      uVar13 = param_1[(uVar13 >> 0x18) + 8] | param_1[(uVar13 & 0xff) + 0x308] |
               param_1[(uVar13 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      local_3c = (uVar13 >> 0x15) + uVar13 * 0x800 ^ local_3c;
      uVar13 = local_3c + unaff_s7;
      uVar13 = param_1[(uVar13 >> 0x18) + 8] | param_1[(uVar13 & 0xff) + 0x308] |
               param_1[(uVar13 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      local_38 = (uVar13 >> 0x15) + uVar13 * 0x800 ^ local_38;
      uVar13 = local_38 + unaff_s6;
      uVar13 = param_1[(uVar13 >> 0x18) + 8] | param_1[(uVar13 & 0xff) + 0x308] |
               param_1[(uVar13 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      local_3c = (uVar13 >> 0x15) + uVar13 * 0x800 ^ local_3c;
      uVar13 = local_3c + unaff_s5;
      uVar13 = param_1[(uVar13 >> 0x18) + 8] | param_1[(uVar13 & 0xff) + 0x308] |
               param_1[(uVar13 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      local_38 = (uVar13 >> 0x15) + uVar13 * 0x800 ^ local_38;
      uVar13 = local_38 + unaff_s4;
      uVar13 = param_1[(uVar13 >> 0x18) + 8] | param_1[(uVar13 & 0xff) + 0x308] |
               param_1[(uVar13 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      local_3c = (uVar13 >> 0x15) + uVar13 * 0x800 ^ local_3c;
      uVar13 = local_3c + unaff_s3;
      uVar13 = param_1[(uVar13 >> 0x18) + 8] | param_1[(uVar13 & 0xff) + 0x308] |
               param_1[(uVar13 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      local_38 = (uVar13 >> 0x15) + uVar13 * 0x800 ^ local_38;
      uVar13 = local_38 + unaff_s2;
      uVar13 = param_1[(uVar13 >> 0x18) + 8] | param_1[(uVar13 & 0xff) + 0x308] |
               param_1[(uVar13 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      local_3c = (uVar13 >> 0x15) + uVar13 * 0x800 ^ local_3c;
      uVar13 = local_3c + param_1[6];
      uVar13 = param_1[(uVar13 >> 0x18) + 8] | param_1[(uVar13 & 0xff) + 0x308] |
               param_1[(uVar13 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      local_38 = (uVar13 >> 0x15) + uVar13 * 0x800 ^ local_38;
      uVar6 = local_38 + unaff_s8;
      uVar14 = local_38 & 0xff;
      uVar13 = (local_38 << 0x10) >> 0x18;
      uVar12 = (local_38 << 8) >> 0x18;
      local_38 = local_38 >> 0x18;
      uVar6 = param_1[(uVar6 >> 0x18) + 8] | param_1[(uVar6 & 0xff) + 0x308] |
              param_1[(uVar6 * 0x100 >> 0x18) + 0x108] | param_1[(uVar6 * 0x10000 >> 0x18) + 0x208];
      local_3c = (uVar6 >> 0x15) + uVar6 * 0x800 ^ local_3c;
      uVar21 = local_3c & 0xff;
      uVar6 = (local_3c << 0x10) >> 0x18;
      uVar9 = (local_3c << 8) >> 0x18;
      local_3c = local_3c >> 0x18;
      pbVar19 = pbVar19 + 8;
    } while (param_5 < puVar11 == 0);
    local_38 = uVar14 << 0x18 | uVar13 << 0x10 | uVar12 << 8 | local_38;
    local_3c = uVar21 << 0x18 | uVar6 << 0x10 | uVar9 << 8 | local_3c;
    if (puVar7 < param_5) goto LAB_00617d20;
  }
  if (puVar7 == (uint *)&DAT_00000008) {
    local_34 = 0;
    puVar7 = &local_3c;
    local_30 = 0;
    mac_block(param_1);
  }
LAB_00617c8c:
  puVar15 = (undefined *)((int)param_2 >> 3);
  uStack_8c = param_2 & 7;
  if ((int)puVar15 < 1) {
    puVar15 = (undefined *)0x0;
  }
  else {
    puVar7 = &local_3c;
    (**(code **)(local_58 + -0x52f4))(local_4c,puVar7,puVar15);
  }
  puStack_90 = puVar15;
  if (uStack_8c != 0) {
    uStack_8c = uStack_8c ^ 1;
    puStack_90 = puVar15 + local_4c;
    uVar5 = *(undefined *)((int)&local_3c + (int)puVar15);
    if (uStack_8c != 0) {
      uVar5 = 0;
    }
    *puStack_90 = uVar5;
  }
  if (local_2c == *local_48) {
    return 1;
  }
  pcStack_6c = cryptopro_key_meshing;
  puVar18 = local_2c;
  (**(code **)(local_58 + -0x5330))();
  puVar11 = (uint *)PTR___stack_chk_guard_006a9ae8;
  puVar26 = auStack_d8;
  pbVar19 = &bStack_b4;
  puStack_c8 = &_gp;
  uStack_94 = *(uint *)PTR___stack_chk_guard_006a9ae8;
  pcVar16 = CryptoProKeyMeshingKey;
  iStack_88 = unaff_s2;
  iStack_84 = unaff_s3;
  iStack_80 = unaff_s4;
  iStack_7c = unaff_s5;
  iStack_78 = unaff_s6;
  iStack_74 = unaff_s7;
  iStack_70 = unaff_s8;
  do {
    pcVar17 = pcVar16 + 8;
    gostdecrypt(puVar18,pcVar16,pbVar19);
    pbVar19 = pbVar19 + 8;
    pcVar16 = pcVar17;
  } while (pcVar17 != "gost94_keyx.c");
  puVar8 = &uStack_bc;
  puVar15 = (undefined *)((uint)bStack_ad << 0x18);
  puVar20 = (uint *)(uint)bStack_a0;
  uVar12 = (uint)bStack_b1 << 0x18;
  puVar18[4] = (uint)bStack_a3 << 8 | (uint)bStack_a2 << 0x10 | (uint)bStack_a4 |
               (uint)bStack_a1 << 0x18;
  puVar18[5] = (uint)bStack_9f << 8 | (uint)bStack_9e << 0x10 | (uint)puVar20 |
               (uint)bStack_9d << 0x18;
  *puVar18 = (uint)bStack_b2 << 0x10 | (uint)bStack_b3 << 8 | (uint)bStack_b4 | uVar12;
  puVar18[1] = (uint)bStack_ae << 0x10 | (uint)bStack_af << 8 | (uint)bStack_b0 | (uint)puVar15;
  puVar18[2] = (uint)bStack_ab << 8 | (uint)bStack_aa << 0x10 | (uint)bStack_ac |
               (uint)bStack_a9 << 0x18;
  puVar18[3] = (uint)bStack_a7 << 8 | (uint)bStack_a6 << 0x10 | (uint)bStack_a8 |
               (uint)bStack_a5 << 0x18;
  puVar18[7] = (uint)bStack_97 << 8 | (uint)bStack_96 << 0x10 | (uint)bStack_98 |
               (uint)bStack_95 << 0x18;
  puVar18[6] = (uint)bStack_9b << 8 | (uint)bStack_9a << 0x10 | (uint)bStack_9c |
               (uint)bStack_99 << 0x18;
  puVar4 = puVar7;
  gostcrypt(puVar18);
  *puVar7 = uStack_bc;
  puVar7[1] = uStack_b8;
  uVar13 = *puVar11;
  if (uStack_94 == uVar13) {
    return uVar13;
  }
  uVar27 = 0x618004;
  uVar13 = uStack_94;
  (**(code **)(puStack_c8 + -0x5330))();
  uVar6 = (uint)bStack_a8;
  while( true ) {
    puVar10 = puVar8;
    uVar9 = uVar13;
    puVar1 = PTR___stack_chk_guard_006a9ae8;
    *(uint *)(puVar26 + -0x18) = uVar12;
    *(uint *)(puVar26 + -8) = uVar6;
    *(uint **)(puVar26 + -0xc) = puVar20;
    *(uint **)(puVar26 + -0x10) = puVar11;
    *(undefined **)(puVar26 + -0x1a0) = &_gp;
    *(undefined4 *)(puVar26 + -4) = uVar27;
    *(uint **)(puVar26 + -0x14) = puVar7;
    *(uint **)(puVar26 + -0x1c) = puVar18;
    *(undefined **)(puVar26 + -0x20) = puVar15;
    *(undefined4 *)(puVar26 + -0x24) = *(undefined4 *)PTR___stack_chk_guard_006a9ae8;
    puVar8 = puVar4;
    puVar11 = puVar10;
    puVar2 = (uint *)(*(code *)PTR_DH_new_006a751c)();
    puVar23 = *(undefined **)(puVar26 + -0x1a0);
    if (puVar2 == (uint *)0x0) {
      uVar13 = 0;
      puVar20 = puVar4;
    }
    else {
      puVar7 = (uint *)(puVar26 + -0x124);
      (**(code **)(puVar23 + -0x53ec))(puVar7,0,0x80);
      puVar15 = puVar26 + -0xa4;
      uVar13 = (**(code **)(*(int *)(puVar26 + -0x1a0) + -0x6bc8))
                         (*(undefined4 *)(puVar4[5] + 0x14));
      iVar24 = *(int *)(puVar26 + -0x1a0);
      puVar2[3] = uVar13;
      uVar13 = (**(code **)(iVar24 + -0x6bc8))(*(undefined4 *)(puVar4[5] + 0xc));
      pcVar22 = *(code **)(*(int *)(puVar26 + -0x1a0) + -0x6bc8);
      puVar2[2] = uVar13;
      uVar13 = (*pcVar22)(uVar9);
      pcVar22 = *(code **)(*(int *)(puVar26 + -0x1a0) + -0x5808);
      puVar2[6] = uVar13;
      iVar3 = (*pcVar22)(puVar4);
      puVar8 = *(uint **)(iVar3 + 0x18);
      puVar11 = puVar2;
      puVar20 = (uint *)(**(code **)(*(int *)(puVar26 + -0x1a0) + -0x6e3c))(puVar15);
      puVar18 = puVar2;
      if (puVar20 == (uint *)0x0) {
        (**(code **)(*(int *)(puVar26 + -0x1a0) + -0x78d8))(puVar2);
        uVar13 = 0;
        puVar23 = *(undefined **)(puVar26 + -0x1a0);
      }
      else {
        (**(code **)(*(int *)(puVar26 + -0x1a0) + -0x53ec))(puVar7,0,0x80);
        iVar25 = *(int *)(puVar26 + -0x1a0);
        if (0 < (int)puVar20) {
          puVar15 = puVar15 + (int)((int)puVar20 + -1);
          puVar11 = puVar7;
          do {
            uVar5 = *puVar15;
            puVar15 = puVar15 + -1;
            *(undefined *)puVar11 = uVar5;
            puVar11 = (uint *)((int)puVar11 + 1);
          } while (puVar15 != puVar26 + -0xa5);
        }
        puVar15 = puVar26 + -0x198;
        (**(code **)(iVar25 + -0x78d8))(puVar2);
        init_gost_hash_ctx(puVar15,*(undefined4 *)(*(int *)(puVar26 + -0x1a0) + -0x5814));
        start_hash(puVar15);
        puVar11 = (uint *)&DAT_00000080;
        hash_block(puVar15,puVar7);
        puVar8 = puVar10;
        finish_hash(puVar15);
        done_gost_hash_ctx(puVar15);
        uVar13 = 1;
        puVar23 = *(undefined **)(puVar26 + -0x1a0);
      }
    }
    iVar3 = *(int *)(puVar26 + -0x24);
    if (iVar3 == *(int *)puVar1) break;
    pcVar22 = pkey_gost94_derive;
    (**(code **)(puVar23 + -0x5330))();
    *(code **)(puVar26 + -0x1b4) = pcVar22;
    *(undefined **)(puVar26 + -0x1b8) = puVar1;
    *(uint **)(puVar26 + -0x1bc) = puVar18;
    *(undefined **)(puVar26 + -0x1c0) = puVar15;
    *(undefined **)(puVar26 + -0x1c8) = &_gp;
    puVar4 = (uint *)(*(code *)PTR_EVP_PKEY_CTX_get0_peerkey_006a9824)();
    uVar27 = (**(code **)(*(int *)(puVar26 + -0x1c8) + -0x580c))(iVar3);
    *puVar11 = 0x20;
    if (puVar8 == (uint *)0x0) {
      return 1;
    }
    uVar13 = gost_get0_priv_key(uVar27);
    uVar27 = *(undefined4 *)(puVar26 + -0x1b4);
    uVar12 = *(uint *)(puVar26 + -0x1b8);
    puVar18 = *(uint **)(puVar26 + -0x1bc);
    puVar15 = *(undefined **)(puVar26 + -0x1c0);
    puVar26 = puVar26 + -0x1b0;
    puVar11 = puVar10;
    uVar6 = uVar9;
  }
  return uVar13;
}

