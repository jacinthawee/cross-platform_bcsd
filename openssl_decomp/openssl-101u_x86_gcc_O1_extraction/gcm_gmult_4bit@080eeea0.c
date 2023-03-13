
void __regparm3 gcm_gmult_4bit(uint *param_1,int param_2)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  
  puVar2 = (uint *)((*(byte *)((int)param_1 + 0xf) & 0xf0) + param_2);
  puVar5 = (uint *)((*(byte *)((int)param_1 + 0xf) & 0xf) * 0x10 + param_2);
  local_40 = puVar5[1] >> 4 ^ puVar2[1] ^ *(uint *)(rem_4bit + (puVar5[2] & 0xf) * 4);
  local_44 = *puVar2 ^ (*puVar5 >> 4 | puVar5[1] << 0x1c);
  local_38 = (*puVar5 << 0x1c | puVar5[3] >> 4) ^ puVar2[3];
  local_3c = (puVar5[2] >> 4 | puVar5[3] << 0x1c) ^ puVar2[2];
  pbVar7 = (byte *)((int)param_1 + 0xe);
  do {
    bVar1 = *pbVar7;
    pbVar7 = pbVar7 + -1;
    puVar2 = (uint *)((bVar1 & 0xf0) + param_2);
    puVar5 = (uint *)((bVar1 & 0xf) * 0x10 + param_2);
    uVar3 = (local_44 >> 4 | local_40 << 0x1c) ^ *puVar5;
    uVar8 = puVar5[1] ^ local_40 >> 4 ^ *(uint *)(rem_4bit + (local_3c & 0xf) * 4);
    uVar4 = (local_3c >> 4 | local_38 << 0x1c) ^ puVar5[2];
    uVar6 = (local_38 >> 4 | local_44 << 0x1c) ^ puVar5[3];
    local_40 = uVar8 >> 4 ^ puVar2[1] ^ *(uint *)(rem_4bit + (uVar4 & 0xf) * 4);
    local_44 = *puVar2 ^ (uVar3 >> 4 | uVar8 << 0x1c);
    local_3c = (uVar4 >> 4 | uVar6 << 0x1c) ^ puVar2[2];
    local_38 = (uVar3 << 0x1c | uVar6 >> 4) ^ puVar2[3];
  } while ((byte *)((int)param_1 + -1) != pbVar7);
  *param_1 = local_40 >> 0x18 | (local_40 & 0xff0000) >> 8 | (local_40 & 0xff00) << 8 |
             local_40 << 0x18;
  param_1[1] = local_44 >> 0x18 | (local_44 & 0xff0000) >> 8 | (local_44 & 0xff00) << 8 |
               local_44 << 0x18;
  param_1[2] = local_38 >> 0x18 | (local_38 & 0xff0000) >> 8 | (local_38 & 0xff00) << 8 |
               local_38 << 0x18;
  param_1[3] = local_3c >> 0x18 | (local_3c & 0xff0000) >> 8 | (local_3c & 0xff00) << 8 |
               local_3c << 0x18;
  return;
}

