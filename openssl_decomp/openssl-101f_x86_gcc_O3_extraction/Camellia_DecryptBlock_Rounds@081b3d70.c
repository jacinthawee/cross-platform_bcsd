
void Camellia_DecryptBlock_Rounds(int param_1,uint *param_2,int param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint local_24;
  uint local_20;
  
  puVar1 = (uint *)(param_1 * 0x40 + param_3);
  uVar2 = param_2[1];
  uVar6 = *param_2;
  local_24 = (uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18) ^
             puVar1[1];
  uVar2 = param_2[2];
  uVar7 = param_2[3];
  uVar6 = (uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18) ^
          *puVar1;
  uVar4 = (uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18) ^
          puVar1[2];
  local_20 = (uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18) ^
             puVar1[3];
  uVar2 = (int)puVar1 + (-0x40 - param_3);
  uVar7 = uVar2 >> 6;
  puVar5 = puVar1;
  while( true ) {
    uVar3 = uVar6 ^ puVar5[-2];
    uVar8 = local_24 ^ puVar5[-1];
    uVar3 = *(uint *)(&DAT_08236640 + (uVar3 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar3 >> 0x18) * 4) ^
            *(uint *)(&DAT_08236e40 + (uVar3 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_08236a40 + (uVar3 >> 0x10 & 0xff) * 4);
    uVar8 = uVar3 ^ *(uint *)(&Camellia_SBOX + (uVar8 & 0xff) * 4) ^
                    *(uint *)(&DAT_08236a40 + (uVar8 >> 0x18) * 4) ^
                    *(uint *)(&DAT_08236640 + (uVar8 >> 8 & 0xff) * 4) ^
                    *(uint *)(&DAT_08236e40 + (uVar8 >> 0x10 & 0xff) * 4);
    uVar4 = uVar4 ^ uVar8;
    local_20 = local_20 ^ uVar8 ^ (uVar3 >> 8 | uVar3 << 0x18);
    uVar3 = puVar5[-3] ^ local_20;
    uVar8 = puVar5[-4] ^ uVar4;
    uVar8 = *(uint *)(&DAT_08236640 + (uVar8 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar8 >> 0x18) * 4) ^
            *(uint *)(&DAT_08236e40 + (uVar8 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_08236a40 + (uVar8 >> 0x10 & 0xff) * 4);
    uVar3 = uVar8 ^ *(uint *)(&Camellia_SBOX + (uVar3 & 0xff) * 4) ^
                    *(uint *)(&DAT_08236a40 + (uVar3 >> 0x18) * 4) ^
                    *(uint *)(&DAT_08236640 + (uVar3 >> 8 & 0xff) * 4) ^
                    *(uint *)(&DAT_08236e40 + (uVar3 >> 0x10 & 0xff) * 4);
    uVar6 = uVar6 ^ uVar3;
    uVar3 = uVar3 ^ local_24 ^ (uVar8 >> 8 | uVar8 << 0x18);
    uVar8 = uVar6 ^ puVar5[-6];
    uVar9 = puVar5[-5] ^ uVar3;
    uVar8 = *(uint *)(&DAT_08236640 + (uVar8 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar8 >> 0x18) * 4) ^
            *(uint *)(&DAT_08236e40 + (uVar8 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_08236a40 + (uVar8 >> 0x10 & 0xff) * 4);
    uVar10 = uVar8 ^ *(uint *)(&Camellia_SBOX + (uVar9 & 0xff) * 4) ^
                     *(uint *)(&DAT_08236a40 + (uVar9 >> 0x18) * 4) ^
                     *(uint *)(&DAT_08236640 + (uVar9 >> 8 & 0xff) * 4) ^
                     *(uint *)(&DAT_08236e40 + (uVar9 >> 0x10 & 0xff) * 4);
    uVar4 = uVar4 ^ uVar10;
    uVar10 = uVar10 ^ local_20 ^ (uVar8 >> 8 | uVar8 << 0x18);
    uVar8 = puVar5[-8] ^ uVar4;
    uVar9 = puVar5[-7] ^ uVar10;
    uVar8 = *(uint *)(&DAT_08236640 + (uVar8 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar8 >> 0x18) * 4) ^
            *(uint *)(&DAT_08236e40 + (uVar8 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_08236a40 + (uVar8 >> 0x10 & 0xff) * 4);
    uVar9 = uVar8 ^ *(uint *)(&Camellia_SBOX + (uVar9 & 0xff) * 4) ^
                    *(uint *)(&DAT_08236a40 + (uVar9 >> 0x18) * 4) ^
                    *(uint *)(&DAT_08236640 + (uVar9 >> 8 & 0xff) * 4) ^
                    *(uint *)(&DAT_08236e40 + (uVar9 >> 0x10 & 0xff) * 4);
    uVar8 = uVar9 ^ uVar3 ^ (uVar8 >> 8 | uVar8 << 0x18);
    uVar6 = uVar6 ^ uVar9;
    uVar3 = uVar6 ^ puVar5[-10];
    uVar9 = puVar5[-9] ^ uVar8;
    uVar3 = *(uint *)(&DAT_08236640 + (uVar3 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar3 >> 0x18) * 4) ^
            *(uint *)(&DAT_08236e40 + (uVar3 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_08236a40 + (uVar3 >> 0x10 & 0xff) * 4);
    local_20 = uVar3 ^ *(uint *)(&Camellia_SBOX + (uVar9 & 0xff) * 4) ^
                       *(uint *)(&DAT_08236a40 + (uVar9 >> 0x18) * 4) ^
                       *(uint *)(&DAT_08236640 + (uVar9 >> 8 & 0xff) * 4) ^
                       *(uint *)(&DAT_08236e40 + (uVar9 >> 0x10 & 0xff) * 4);
    uVar4 = uVar4 ^ local_20;
    local_20 = local_20 ^ uVar10 ^ (uVar3 >> 8 | uVar3 << 0x18);
    uVar3 = uVar4 ^ puVar5[-0xc];
    uVar9 = puVar5[-0xb] ^ local_20;
    uVar3 = *(uint *)(&DAT_08236640 + (uVar3 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar3 >> 0x18) * 4) ^
            *(uint *)(&DAT_08236e40 + (uVar3 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_08236a40 + (uVar3 >> 0x10 & 0xff) * 4);
    local_24 = uVar3 ^ *(uint *)(&Camellia_SBOX + (uVar9 & 0xff) * 4) ^
                       *(uint *)(&DAT_08236a40 + (uVar9 >> 0x18) * 4) ^
                       *(uint *)(&DAT_08236640 + (uVar9 >> 8 & 0xff) * 4) ^
                       *(uint *)(&DAT_08236e40 + (uVar9 >> 0x10 & 0xff) * 4);
    uVar6 = uVar6 ^ local_24;
    local_24 = uVar8 ^ (uVar3 >> 8 | uVar3 << 0x18) ^ local_24;
    if (puVar5 == (uint *)((int)puVar1 - uVar2)) break;
    uVar4 = (puVar5[-0xf] | local_20) ^ uVar4;
    local_24 = local_24 ^ ((puVar5[-0xe] & uVar6) << 1 | (uint)((int)(puVar5[-0xe] & uVar6) < 0));
    uVar6 = (local_24 | puVar5[-0xd]) ^ uVar6;
    uVar3 = puVar5[-0x10] & uVar4;
    local_20 = local_20 ^ (uVar3 << 1 | (uint)((int)uVar3 < 0));
    puVar5 = puVar5 + -0x10;
  }
  uVar4 = uVar4 ^ puVar1[uVar7 * -0x10 + -0x10];
  local_20 = local_20 ^ puVar1[uVar7 * -0x10 + -0xf];
  uVar6 = uVar6 ^ puVar1[uVar7 * -0x10 + -0xe];
  local_24 = local_24 ^ puVar1[uVar7 * -0x10 + -0xd];
  *param_4 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
  param_4[1] = local_20 >> 0x18 | (local_20 & 0xff0000) >> 8 | (local_20 & 0xff00) << 8 |
               local_20 << 0x18;
  param_4[2] = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
  param_4[3] = local_24 >> 0x18 | (local_24 & 0xff0000) >> 8 | (local_24 & 0xff00) << 8 |
               local_24 << 0x18;
  return;
}

