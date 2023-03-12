
uint cryptopro_key_meshing(uint *param_1,uint *param_2)

{
  undefined uVar1;
  undefined *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  char *pcVar11;
  char *pcVar12;
  undefined *puVar13;
  byte *pbVar14;
  uint uVar15;
  uint *puVar16;
  uint uVar17;
  code *pcVar18;
  undefined *puVar19;
  int iVar20;
  int iVar21;
  undefined *puVar22;
  undefined4 uVar23;
  undefined auStack_70 [16];
  undefined *local_60;
  uint local_54;
  uint local_50;
  byte local_4c;
  byte local_4b;
  byte local_4a;
  byte local_49;
  byte local_48;
  byte local_47;
  byte local_46;
  byte local_45;
  byte local_44;
  byte local_43;
  byte local_42;
  byte local_41;
  byte local_40;
  byte local_3f;
  byte local_3e;
  byte local_3d;
  byte local_3c;
  byte local_3b;
  byte local_3a;
  byte local_39;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  byte local_30;
  byte local_2f;
  byte local_2e;
  byte local_2d;
  uint local_2c;
  
  puVar10 = (uint *)PTR___stack_chk_guard_006aabf0;
  puVar22 = auStack_70;
  pbVar14 = &local_4c;
  local_60 = &_gp;
  local_2c = *(uint *)PTR___stack_chk_guard_006aabf0;
  pcVar11 = CryptoProKeyMeshingKey;
  do {
    pcVar12 = pcVar11 + 8;
    gostdecrypt(param_1,pcVar11,pbVar14);
    pbVar14 = pbVar14 + 8;
    pcVar11 = pcVar12;
  } while (pcVar12 != "gost94_keyx.c");
  puVar8 = &local_54;
  puVar13 = (undefined *)((uint)local_45 << 0x18);
  puVar16 = (uint *)(uint)local_38;
  uVar15 = (uint)local_49 << 0x18;
  param_1[4] = (uint)local_3b << 8 | (uint)local_3a << 0x10 | (uint)local_3c |
               (uint)local_39 << 0x18;
  param_1[5] = (uint)local_37 << 8 | (uint)local_36 << 0x10 | (uint)puVar16 | (uint)local_35 << 0x18
  ;
  *param_1 = (uint)local_4a << 0x10 | (uint)local_4b << 8 | (uint)local_4c | uVar15;
  param_1[1] = (uint)local_46 << 0x10 | (uint)local_47 << 8 | (uint)local_48 | (uint)puVar13;
  param_1[2] = (uint)local_43 << 8 | (uint)local_42 << 0x10 | (uint)local_44 |
               (uint)local_41 << 0x18;
  param_1[3] = (uint)local_3f << 8 | (uint)local_3e << 0x10 | (uint)local_40 |
               (uint)local_3d << 0x18;
  param_1[7] = (uint)local_2f << 8 | (uint)local_2e << 0x10 | (uint)local_30 |
               (uint)local_2d << 0x18;
  param_1[6] = (uint)local_33 << 8 | (uint)local_32 << 0x10 | (uint)local_34 |
               (uint)local_31 << 0x18;
  puVar6 = param_2;
  gostcrypt(param_1);
  *param_2 = local_54;
  param_2[1] = local_50;
  uVar3 = *puVar10;
  if (local_2c == uVar3) {
    return uVar3;
  }
  uVar23 = 0x618b84;
  uVar3 = local_2c;
  (**(code **)(local_60 + -0x5328))();
  uVar17 = (uint)local_40;
  while( true ) {
    puVar9 = puVar8;
    uVar7 = uVar3;
    puVar2 = PTR___stack_chk_guard_006aabf0;
    *(uint *)(puVar22 + -0x18) = uVar15;
    *(uint *)(puVar22 + -8) = uVar17;
    *(uint **)(puVar22 + -0xc) = puVar16;
    *(uint **)(puVar22 + -0x10) = puVar10;
    *(undefined **)(puVar22 + -0x1a0) = &_gp;
    *(undefined4 *)(puVar22 + -4) = uVar23;
    *(uint **)(puVar22 + -0x14) = param_2;
    *(uint **)(puVar22 + -0x1c) = param_1;
    *(undefined **)(puVar22 + -0x20) = puVar13;
    *(undefined4 *)(puVar22 + -0x24) = *(undefined4 *)PTR___stack_chk_guard_006aabf0;
    puVar8 = puVar6;
    puVar10 = puVar9;
    puVar4 = (uint *)(*(code *)PTR_DH_new_006a8618)();
    puVar19 = *(undefined **)(puVar22 + -0x1a0);
    if (puVar4 == (uint *)0x0) {
      uVar3 = 0;
      puVar16 = puVar6;
    }
    else {
      param_2 = (uint *)(puVar22 + -0x124);
      (**(code **)(puVar19 + -0x53e0))(param_2,0,0x80);
      puVar13 = puVar22 + -0xa4;
      uVar3 = (**(code **)(*(int *)(puVar22 + -0x1a0) + -0x6de0))(*(undefined4 *)(puVar6[5] + 0x14))
      ;
      iVar20 = *(int *)(puVar22 + -0x1a0);
      puVar4[3] = uVar3;
      uVar3 = (**(code **)(iVar20 + -0x6de0))(*(undefined4 *)(puVar6[5] + 0xc));
      pcVar18 = *(code **)(*(int *)(puVar22 + -0x1a0) + -0x6de0);
      puVar4[2] = uVar3;
      uVar3 = (*pcVar18)(uVar7);
      pcVar18 = *(code **)(*(int *)(puVar22 + -0x1a0) + -0x57fc);
      puVar4[6] = uVar3;
      iVar5 = (*pcVar18)(puVar6);
      puVar8 = *(uint **)(iVar5 + 0x18);
      puVar10 = puVar4;
      puVar16 = (uint *)(**(code **)(*(int *)(puVar22 + -0x1a0) + -0x6db4))(puVar13);
      param_1 = puVar4;
      if (puVar16 == (uint *)0x0) {
        (**(code **)(*(int *)(puVar22 + -0x1a0) + -0x78dc))(puVar4);
        uVar3 = 0;
        puVar19 = *(undefined **)(puVar22 + -0x1a0);
      }
      else {
        (**(code **)(*(int *)(puVar22 + -0x1a0) + -0x53e0))(param_2,0,0x80);
        iVar21 = *(int *)(puVar22 + -0x1a0);
        if (0 < (int)puVar16) {
          puVar13 = puVar13 + (int)((int)puVar16 + -1);
          puVar10 = param_2;
          do {
            uVar1 = *puVar13;
            puVar13 = puVar13 + -1;
            *(undefined *)puVar10 = uVar1;
            puVar10 = (uint *)((int)puVar10 + 1);
          } while (puVar13 != puVar22 + -0xa5);
        }
        puVar13 = puVar22 + -0x198;
        (**(code **)(iVar21 + -0x78dc))(puVar4);
        init_gost_hash_ctx(puVar13,*(undefined4 *)(*(int *)(puVar22 + -0x1a0) + -0x5808));
        start_hash(puVar13);
        puVar10 = (uint *)&DAT_00000080;
        hash_block(puVar13,param_2);
        puVar8 = puVar9;
        finish_hash(puVar13);
        done_gost_hash_ctx(puVar13);
        uVar3 = 1;
        puVar19 = *(undefined **)(puVar22 + -0x1a0);
      }
    }
    iVar5 = *(int *)(puVar22 + -0x24);
    if (iVar5 == *(int *)puVar2) break;
    pcVar18 = pkey_gost94_derive;
    (**(code **)(puVar19 + -0x5328))();
    *(code **)(puVar22 + -0x1b4) = pcVar18;
    *(undefined **)(puVar22 + -0x1b8) = puVar2;
    *(uint **)(puVar22 + -0x1bc) = param_1;
    *(undefined **)(puVar22 + -0x1c0) = puVar13;
    *(undefined **)(puVar22 + -0x1c8) = &_gp;
    puVar6 = (uint *)(*(code *)PTR_EVP_PKEY_CTX_get0_peerkey_006aa934)();
    uVar23 = (**(code **)(*(int *)(puVar22 + -0x1c8) + -0x5800))(iVar5);
    *puVar10 = 0x20;
    if (puVar8 == (uint *)0x0) {
      return 1;
    }
    uVar3 = gost_get0_priv_key(uVar23);
    uVar23 = *(undefined4 *)(puVar22 + -0x1b4);
    uVar15 = *(uint *)(puVar22 + -0x1b8);
    param_1 = *(uint **)(puVar22 + -0x1bc);
    puVar13 = *(undefined **)(puVar22 + -0x1c0);
    puVar22 = puVar22 + -0x1b0;
    puVar10 = puVar9;
    uVar17 = uVar7;
  }
  return uVar3;
}

