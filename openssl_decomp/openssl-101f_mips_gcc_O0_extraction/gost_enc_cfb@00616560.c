
void gost_enc_cfb(undefined4 param_1,undefined4 *param_2,byte *param_3,byte *param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined *puVar5;
  undefined *puVar6;
  uint uVar7;
  uint *puVar8;
  byte *unaff_s0;
  byte *pbVar9;
  byte *unaff_s1;
  byte *pbVar10;
  int unaff_s5;
  undefined *puVar11;
  undefined4 *unaff_s6;
  byte *unaff_s7;
  undefined4 uStack_94;
  undefined4 uStack_90;
  byte bStack_8c;
  byte bStack_8b;
  byte bStack_8a;
  byte bStack_89;
  byte bStack_88;
  byte bStack_87;
  byte bStack_86;
  byte bStack_85;
  uint *puStack_84;
  byte *pbStack_7c;
  byte *pbStack_78;
  int iStack_74;
  undefined4 uStack_70;
  undefined *puStack_6c;
  int iStack_68;
  undefined4 *puStack_64;
  byte *pbStack_60;
  code *pcStack_5c;
  undefined *local_48;
  undefined4 local_3c;
  undefined4 local_38;
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  byte local_30;
  byte local_2f;
  byte local_2e;
  byte local_2d;
  uint local_2c;
  
  puStack_6c = PTR___stack_chk_guard_006aabf0;
  local_48 = &_gp;
  local_3c = *param_2;
  local_38 = param_2[1];
  uVar7 = *(uint *)PTR___stack_chk_guard_006aabf0;
  local_2c = uVar7;
  if (0 < param_5) {
    unaff_s5 = 0;
    unaff_s7 = &local_34;
    unaff_s6 = &local_3c;
    pbVar9 = param_3;
    pbVar10 = param_4;
    do {
      gostcrypt(param_1,unaff_s6,unaff_s7);
      unaff_s1 = pbVar10 + 8;
      bVar1 = *pbVar9;
      unaff_s0 = pbVar9 + 8;
      unaff_s5 = unaff_s5 + 1;
      *pbVar10 = bVar1 ^ local_34;
      bVar2 = pbVar9[1];
      pbVar10[1] = bVar2 ^ local_33;
      bVar3 = pbVar9[2] ^ local_32;
      param_4 = (byte *)(uint)bVar3;
      pbVar10[2] = bVar3;
      bVar4 = pbVar9[3] ^ local_31;
      param_3 = (byte *)(uint)bVar4;
      pbVar10[3] = bVar4;
      local_3c = CONCAT31(CONCAT21(CONCAT11(bVar1 ^ local_34,bVar2 ^ local_33),bVar3),bVar4);
      bVar3 = pbVar9[4] ^ local_30;
      param_2 = (undefined4 *)(uint)bVar3;
      pbVar10[4] = bVar3;
      bVar4 = pbVar9[5] ^ local_2f;
      uVar7 = (uint)bVar4;
      pbVar10[5] = bVar4;
      bVar1 = pbVar9[6];
      pbVar10[6] = bVar1 ^ local_2e;
      bVar2 = pbVar9[7];
      pbVar10[7] = bVar2 ^ local_2d;
      local_38 = CONCAT31(CONCAT21(CONCAT11(bVar3,bVar4),bVar1 ^ local_2e),bVar2 ^ local_2d);
      pbVar9 = unaff_s0;
      pbVar10 = unaff_s1;
    } while (param_5 != unaff_s5);
  }
  if (local_2c == *(uint *)puStack_6c) {
    return;
  }
  pcStack_5c = gost_dec_cfb;
  (**(code **)(local_48 + -0x5328))();
  puVar6 = local_48;
  puVar5 = PTR___stack_chk_guard_006aabf0;
  iStack_74 = param_5;
  uStack_94 = *param_2;
  uStack_90 = param_2[1];
  puVar8 = *(uint **)PTR___stack_chk_guard_006aabf0;
  puStack_84 = puVar8;
  pbStack_7c = unaff_s0;
  pbStack_78 = unaff_s1;
  uStack_70 = param_1;
  iStack_68 = unaff_s5;
  puStack_64 = unaff_s6;
  pbStack_60 = unaff_s7;
  if (0 < (int)local_48) {
    puVar11 = (undefined *)0x0;
    do {
      gostcrypt(uVar7,&uStack_94,&bStack_8c);
      bVar1 = *param_3;
      puVar11 = puVar11 + 1;
      *param_4 = bVar1 ^ bStack_8c;
      bVar2 = param_3[1];
      param_4[1] = bVar2 ^ bStack_8b;
      bVar3 = param_3[2];
      param_4[2] = bVar3 ^ bStack_8a;
      uStack_94 = CONCAT31(CONCAT21(CONCAT11(bVar1,bVar2),bVar3),param_3[3]);
      param_4[3] = param_3[3] ^ bStack_89;
      bVar1 = param_3[4];
      param_4[4] = bVar1 ^ bStack_88;
      bVar2 = param_3[5];
      param_2 = (undefined4 *)(uint)bVar2;
      param_4[5] = bVar2 ^ bStack_87;
      bVar3 = param_3[6];
      puVar8 = (uint *)(uint)bVar3;
      param_4[6] = bVar3 ^ bStack_86;
      uStack_90 = CONCAT31(CONCAT21(CONCAT11(bVar1,bVar2),bVar3),param_3[7]);
      param_4[7] = param_3[7] ^ bStack_85;
      param_3 = param_3 + 8;
      param_4 = param_4 + 8;
    } while (puVar6 != puVar11);
  }
  if (puStack_84 == *(uint **)puVar5) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  *puVar8 = (uint)*(byte *)((int)param_2 + 2) << 0x10 | (uint)*(byte *)((int)param_2 + 1) << 8 |
            (uint)*(byte *)param_2 | (uint)*(byte *)((int)param_2 + 3) << 0x18;
  puVar8[1] = (uint)*(byte *)((int)param_2 + 5) << 8 | (uint)*(byte *)((int)param_2 + 6) << 0x10 |
              (uint)*(byte *)(param_2 + 1) | (uint)*(byte *)((int)param_2 + 7) << 0x18;
  puVar8[2] = (uint)*(byte *)((int)param_2 + 9) << 8 | (uint)*(byte *)((int)param_2 + 10) << 0x10 |
              (uint)*(byte *)(param_2 + 2) | (uint)*(byte *)((int)param_2 + 0xb) << 0x18;
  puVar8[3] = (uint)*(byte *)((int)param_2 + 0xd) << 8 | (uint)*(byte *)((int)param_2 + 0xe) << 0x10
              | (uint)*(byte *)(param_2 + 3) | (uint)*(byte *)((int)param_2 + 0xf) << 0x18;
  puVar8[4] = (uint)*(byte *)((int)param_2 + 0x11) << 8 |
              (uint)*(byte *)((int)param_2 + 0x12) << 0x10 | (uint)*(byte *)(param_2 + 4) |
              (uint)*(byte *)((int)param_2 + 0x13) << 0x18;
  puVar8[5] = (uint)*(byte *)((int)param_2 + 0x15) << 8 |
              (uint)*(byte *)((int)param_2 + 0x16) << 0x10 | (uint)*(byte *)(param_2 + 5) |
              (uint)*(byte *)((int)param_2 + 0x17) << 0x18;
  puVar8[6] = (uint)*(byte *)((int)param_2 + 0x19) << 8 |
              (uint)*(byte *)((int)param_2 + 0x1a) << 0x10 | (uint)*(byte *)(param_2 + 6) |
              (uint)*(byte *)((int)param_2 + 0x1b) << 0x18;
  puVar8[7] = (uint)*(byte *)((int)param_2 + 0x1d) << 8 |
              (uint)*(byte *)((int)param_2 + 0x1e) << 0x10 | (uint)*(byte *)(param_2 + 7) |
              (uint)*(byte *)((int)param_2 + 0x1f) << 0x18;
  gostcrypt();
  return;
}

