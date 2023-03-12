
void __regparm3 gcm_ghash_4bit(uint *param_1_00,int param_2,int param_3,int param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  int local_28;
  
  local_28 = param_3;
  do {
    uVar3 = (uint)(*(byte *)((int)param_1_00 + 0xf) ^ *(byte *)(local_28 + 0xf));
    puVar2 = (uint *)((uVar3 & 0xf0) + param_2);
    puVar1 = (uint *)((uVar3 & 0xf) * 0x10 + param_2);
    local_48 = puVar2[1] ^ puVar1[1] >> 4 ^ *(uint *)(rem_4bit + (puVar1[2] & 0xf) * 4);
    local_4c = *puVar2 ^ (*puVar1 >> 4 | puVar1[1] << 0x1c);
    local_44 = (puVar1[2] >> 4 | puVar1[3] << 0x1c) ^ puVar2[2];
    local_40 = (*puVar1 << 0x1c | puVar1[3] >> 4) ^ puVar2[3];
    iVar7 = 0xe;
    do {
      uVar3 = (uint)(*(byte *)((int)param_1_00 + iVar7) ^ *(byte *)(local_28 + iVar7));
      iVar7 = iVar7 + -1;
      puVar1 = (uint *)((uVar3 & 0xf0) + param_2);
      puVar2 = (uint *)((uVar3 & 0xf) * 0x10 + param_2);
      uVar5 = *puVar2 ^ (local_4c >> 4 | local_48 << 0x1c);
      uVar6 = *(uint *)(rem_4bit + (local_44 & 0xf) * 4) ^ puVar2[1] ^ local_48 >> 4;
      uVar3 = (local_44 >> 4 | local_40 << 0x1c) ^ puVar2[2];
      uVar4 = puVar2[3] ^ (local_4c << 0x1c | local_40 >> 4);
      local_48 = uVar6 >> 4 ^ puVar1[1] ^ *(uint *)(rem_4bit + (uVar3 & 0xf) * 4);
      local_4c = *puVar1 ^ (uVar5 >> 4 | uVar6 << 0x1c);
      local_44 = (uVar3 >> 4 | uVar4 << 0x1c) ^ puVar1[2];
      local_40 = (uVar5 << 0x1c | uVar4 >> 4) ^ puVar1[3];
    } while (iVar7 != -1);
    local_28 = local_28 + 0x10;
    param_1 = param_1 + -0x10;
    param_1_00[2] =
         local_40 >> 0x18 | (local_40 & 0xff0000) >> 8 | (local_40 & 0xff00) << 8 | local_40 << 0x18
    ;
    param_1_00[3] =
         local_44 >> 0x18 | (local_44 & 0xff0000) >> 8 | (local_44 & 0xff00) << 8 | local_44 << 0x18
    ;
    *param_1_00 = local_48 >> 0x18 | (local_48 & 0xff0000) >> 8 | (local_48 & 0xff00) << 8 |
                  local_48 << 0x18;
    param_1_00[1] =
         local_4c >> 0x18 | (local_4c & 0xff0000) >> 8 | (local_4c & 0xff00) << 8 | local_4c << 0x18
    ;
  } while (param_1 != 0);
  return;
}

