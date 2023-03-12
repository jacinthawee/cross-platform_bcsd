
void gost_dec_cfb(undefined4 param_1,undefined4 *param_2,byte *param_3,byte *param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined *puVar4;
  uint *puVar5;
  int iVar6;
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
  uint *local_2c;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  local_3c = *param_2;
  local_38 = param_2[1];
  puVar5 = *(uint **)PTR___stack_chk_guard_006a9ae8;
  local_2c = puVar5;
  if (0 < param_5) {
    iVar6 = 0;
    do {
      gostcrypt(param_1,&local_3c,&local_34);
      bVar1 = *param_3;
      iVar6 = iVar6 + 1;
      *param_4 = bVar1 ^ local_34;
      bVar2 = param_3[1];
      param_4[1] = bVar2 ^ local_33;
      bVar3 = param_3[2];
      param_4[2] = bVar3 ^ local_32;
      local_3c = CONCAT31(CONCAT21(CONCAT11(bVar1,bVar2),bVar3),param_3[3]);
      param_4[3] = param_3[3] ^ local_31;
      bVar1 = param_3[4];
      param_4[4] = bVar1 ^ local_30;
      bVar2 = param_3[5];
      param_2 = (undefined4 *)(uint)bVar2;
      param_4[5] = bVar2 ^ local_2f;
      bVar3 = param_3[6];
      puVar5 = (uint *)(uint)bVar3;
      param_4[6] = bVar3 ^ local_2e;
      local_38 = CONCAT31(CONCAT21(CONCAT11(bVar1,bVar2),bVar3),param_3[7]);
      param_4[7] = param_3[7] ^ local_2d;
      param_3 = param_3 + 8;
      param_4 = param_4 + 8;
    } while (param_5 != iVar6);
  }
  if (local_2c == *(uint **)puVar4) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  *puVar5 = (uint)*(byte *)((int)param_2 + 2) << 0x10 | (uint)*(byte *)((int)param_2 + 1) << 8 |
            (uint)*(byte *)param_2 | (uint)*(byte *)((int)param_2 + 3) << 0x18;
  puVar5[1] = (uint)*(byte *)((int)param_2 + 5) << 8 | (uint)*(byte *)((int)param_2 + 6) << 0x10 |
              (uint)*(byte *)(param_2 + 1) | (uint)*(byte *)((int)param_2 + 7) << 0x18;
  puVar5[2] = (uint)*(byte *)((int)param_2 + 9) << 8 | (uint)*(byte *)((int)param_2 + 10) << 0x10 |
              (uint)*(byte *)(param_2 + 2) | (uint)*(byte *)((int)param_2 + 0xb) << 0x18;
  puVar5[3] = (uint)*(byte *)((int)param_2 + 0xd) << 8 | (uint)*(byte *)((int)param_2 + 0xe) << 0x10
              | (uint)*(byte *)(param_2 + 3) | (uint)*(byte *)((int)param_2 + 0xf) << 0x18;
  puVar5[4] = (uint)*(byte *)((int)param_2 + 0x11) << 8 |
              (uint)*(byte *)((int)param_2 + 0x12) << 0x10 | (uint)*(byte *)(param_2 + 4) |
              (uint)*(byte *)((int)param_2 + 0x13) << 0x18;
  puVar5[5] = (uint)*(byte *)((int)param_2 + 0x15) << 8 |
              (uint)*(byte *)((int)param_2 + 0x16) << 0x10 | (uint)*(byte *)(param_2 + 5) |
              (uint)*(byte *)((int)param_2 + 0x17) << 0x18;
  puVar5[6] = (uint)*(byte *)((int)param_2 + 0x19) << 8 |
              (uint)*(byte *)((int)param_2 + 0x1a) << 0x10 | (uint)*(byte *)(param_2 + 6) |
              (uint)*(byte *)((int)param_2 + 0x1b) << 0x18;
  puVar5[7] = (uint)*(byte *)((int)param_2 + 0x1d) << 8 |
              (uint)*(byte *)((int)param_2 + 0x1e) << 0x10 | (uint)*(byte *)(param_2 + 7) |
              (uint)*(byte *)((int)param_2 + 0x1f) << 0x18;
  gostcrypt();
  return;
}

