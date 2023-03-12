
void gcm_ghash_4bit(uint *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  
  pbVar4 = (byte *)(param_3 + 0xe);
  do {
    uVar1 = (uint)(*(byte *)((int)param_1 + 0xf) ^ pbVar4[1]);
    puVar3 = (uint *)(param_2 + (uVar1 & 0xf) * 0x10);
    puVar2 = (uint *)(param_2 + (uVar1 & 0xf0));
    uVar9 = *puVar2 ^ *puVar3 >> 4 ^ *(uint *)(rem_4bit + (puVar3[3] & 0xf) * 4);
    uVar1 = puVar2[1] ^ (*puVar3 << 0x1c | puVar3[1] >> 4);
    uVar7 = puVar2[2] ^ (puVar3[2] >> 4 | puVar3[1] << 0x1c);
    uVar5 = puVar2[3] ^ (puVar3[2] << 0x1c | puVar3[3] >> 4);
    pbVar11 = (byte *)((int)param_1 + 0xe);
    pbVar12 = pbVar4;
    do {
      puVar3 = (uint *)(param_2 + ((*pbVar11 ^ *pbVar12) & 0xf) * 0x10);
      puVar2 = (uint *)(param_2 + ((*pbVar11 ^ *pbVar12) & 0xf0));
      uVar6 = puVar3[3] ^ (uVar7 << 0x1c | uVar5 >> 4);
      uVar8 = puVar3[1] ^ (uVar9 << 0x1c | uVar1 >> 4);
      uVar10 = puVar3[2] ^ (uVar1 << 0x1c | uVar7 >> 4);
      uVar1 = *puVar3 ^ uVar9 >> 4 ^ *(uint *)(rem_4bit + (uVar5 & 0xf) * 4);
      pbVar11 = pbVar11 + -1;
      uVar9 = *puVar2 ^ uVar1 >> 4 ^ *(uint *)(rem_4bit + (uVar6 & 0xf) * 4);
      uVar1 = puVar2[1] ^ (uVar1 << 0x1c | uVar8 >> 4);
      uVar7 = puVar2[2] ^ (uVar8 << 0x1c | uVar10 >> 4);
      uVar5 = puVar2[3] ^ (uVar10 << 0x1c | uVar6 >> 4);
      pbVar12 = pbVar12 + -1;
    } while ((byte *)((int)param_1 + -1) != pbVar11);
    param_4 = param_4 + -0x10;
    *param_1 = uVar9;
    param_1[1] = uVar1;
    pbVar4 = pbVar4 + 0x10;
    param_1[2] = uVar7;
    param_1[3] = uVar5;
  } while (param_4 != 0);
  return;
}

