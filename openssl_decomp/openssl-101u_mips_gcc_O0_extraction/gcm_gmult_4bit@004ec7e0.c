
void gcm_gmult_4bit(uint *param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  
  puVar1 = (uint *)(param_2 + (*(byte *)((int)param_1 + 0xf) & 0xf) * 0x10);
  puVar5 = (uint *)(param_2 + (*(byte *)((int)param_1 + 0xf) & 0xf0));
  pbVar8 = (byte *)((int)param_1 + 0xe);
  uVar9 = *puVar5 ^ *puVar1 >> 4 ^ *(uint *)(rem_4bit + (puVar1[3] & 0xf) * 4);
  uVar2 = puVar5[1] ^ (*puVar1 << 0x1c | puVar1[1] >> 4);
  uVar10 = puVar5[2] ^ (puVar1[1] << 0x1c | puVar1[2] >> 4);
  uVar3 = puVar5[3] ^ (puVar1[2] << 0x1c | puVar1[3] >> 4);
  do {
    puVar5 = (uint *)(param_2 + (*pbVar8 & 0xf) * 0x10);
    puVar1 = (uint *)(param_2 + (*pbVar8 & 0xf0));
    uVar4 = puVar5[3] ^ (uVar10 << 0x1c | uVar3 >> 4);
    uVar6 = *puVar5 ^ uVar9 >> 4 ^ *(uint *)(rem_4bit + (uVar3 & 0xf) * 4);
    uVar3 = puVar5[1] ^ (uVar9 << 0x1c | uVar2 >> 4);
    uVar7 = puVar5[2] ^ (uVar2 << 0x1c | uVar10 >> 4);
    pbVar8 = pbVar8 + -1;
    uVar9 = *puVar1 ^ uVar6 >> 4 ^ *(uint *)(rem_4bit + (uVar4 & 0xf) * 4);
    uVar2 = puVar1[1] ^ (uVar6 << 0x1c | uVar3 >> 4);
    uVar10 = puVar1[2] ^ (uVar3 << 0x1c | uVar7 >> 4);
    uVar3 = puVar1[3] ^ (uVar7 << 0x1c | uVar4 >> 4);
  } while ((byte *)((int)param_1 + -1) != pbVar8);
  *param_1 = uVar9;
  param_1[1] = uVar2;
  param_1[2] = uVar10;
  param_1[3] = uVar3;
  return;
}

