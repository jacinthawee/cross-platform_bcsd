
void Camellia_EncryptBlock_Rounds(int param_1,uint *param_2,uint *param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_18;
  
  uVar6 = *param_2;
  uVar8 = param_2[1];
  uVar3 = param_2[2];
  uVar2 = param_2[3];
  uVar6 = (uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18) ^
          *param_3;
  uVar8 = (uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18) ^
          param_3[1];
  puVar1 = param_3 + param_1 * 0x10;
  uVar3 = (uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18) ^
          param_3[2];
  local_18 = (uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18) ^
             param_3[3];
  while( true ) {
    uVar2 = uVar6 ^ param_3[4];
    uVar4 = uVar8 ^ param_3[5];
    uVar2 = *(uint *)(&DAT_08236b00 + (uVar2 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar2 >> 0x18) * 4) ^
            *(uint *)(&DAT_08237300 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_08236f00 + (uVar2 >> 0x10 & 0xff) * 4);
    uVar4 = uVar2 ^ *(uint *)(&Camellia_SBOX + (uVar4 & 0xff) * 4) ^
                    *(uint *)(&DAT_08236f00 + (uVar4 >> 0x18) * 4) ^
                    *(uint *)(&DAT_08236b00 + (uVar4 >> 8 & 0xff) * 4) ^
                    *(uint *)(&DAT_08237300 + (uVar4 >> 0x10 & 0xff) * 4);
    uVar3 = uVar3 ^ uVar4;
    local_18 = local_18 ^ uVar4 ^ (uVar2 >> 8 | uVar2 << 0x18);
    uVar2 = param_3[6] ^ uVar3;
    uVar4 = param_3[7] ^ local_18;
    uVar2 = *(uint *)(&DAT_08236b00 + (uVar2 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar2 >> 0x18) * 4) ^
            *(uint *)(&DAT_08237300 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_08236f00 + (uVar2 >> 0x10 & 0xff) * 4);
    uVar7 = uVar2 ^ *(uint *)(&Camellia_SBOX + (uVar4 & 0xff) * 4) ^
                    *(uint *)(&DAT_08236f00 + (uVar4 >> 0x18) * 4) ^
                    *(uint *)(&DAT_08236b00 + (uVar4 >> 8 & 0xff) * 4) ^
                    *(uint *)(&DAT_08237300 + (uVar4 >> 0x10 & 0xff) * 4);
    uVar6 = uVar6 ^ uVar7;
    uVar4 = param_3[8] ^ uVar6;
    uVar7 = uVar7 ^ (uVar2 >> 8 | uVar2 << 0x18) ^ uVar8;
    uVar8 = param_3[9] ^ uVar7;
    uVar2 = *(uint *)(&DAT_08236b00 + (uVar4 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar4 >> 0x18) * 4) ^
            *(uint *)(&DAT_08237300 + (uVar4 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_08236f00 + (uVar4 >> 0x10 & 0xff) * 4);
    uVar8 = uVar2 ^ *(uint *)(&Camellia_SBOX + (uVar8 & 0xff) * 4) ^
                    *(uint *)(&DAT_08236f00 + (uVar8 >> 0x18) * 4) ^
                    *(uint *)(&DAT_08236b00 + (uVar8 >> 8 & 0xff) * 4) ^
                    *(uint *)(&DAT_08237300 + (uVar8 >> 0x10 & 0xff) * 4);
    uVar3 = uVar3 ^ uVar8;
    uVar8 = uVar8 ^ local_18 ^ (uVar2 >> 8 | uVar2 << 0x18);
    uVar2 = param_3[10] ^ uVar3;
    uVar4 = param_3[0xb] ^ uVar8;
    uVar2 = *(uint *)(&DAT_08236f00 + (uVar2 >> 0x10 & 0xff) * 4) ^
            *(uint *)(&DAT_08236b00 + (uVar2 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar2 >> 0x18) * 4) ^
            *(uint *)(&DAT_08237300 + (uVar2 >> 8 & 0xff) * 4);
    uVar4 = uVar2 ^ *(uint *)(&Camellia_SBOX + (uVar4 & 0xff) * 4) ^
                    *(uint *)(&DAT_08236f00 + (uVar4 >> 0x18) * 4) ^
                    *(uint *)(&DAT_08236b00 + (uVar4 >> 8 & 0xff) * 4) ^
                    *(uint *)(&DAT_08237300 + (uVar4 >> 0x10 & 0xff) * 4);
    uVar6 = uVar6 ^ uVar4;
    uVar4 = uVar7 ^ (uVar2 >> 8 | uVar2 << 0x18) ^ uVar4;
    uVar2 = param_3[0xc] ^ uVar6;
    uVar7 = param_3[0xd] ^ uVar4;
    uVar2 = *(uint *)(&DAT_08236b00 + (uVar2 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar2 >> 0x18) * 4) ^
            *(uint *)(&DAT_08237300 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_08236f00 + (uVar2 >> 0x10 & 0xff) * 4);
    local_18 = uVar2 ^ *(uint *)(&Camellia_SBOX + (uVar7 & 0xff) * 4) ^
                       *(uint *)(&DAT_08236f00 + (uVar7 >> 0x18) * 4) ^
                       *(uint *)(&DAT_08236b00 + (uVar7 >> 8 & 0xff) * 4) ^
                       *(uint *)(&DAT_08237300 + (uVar7 >> 0x10 & 0xff) * 4);
    uVar3 = uVar3 ^ local_18;
    local_18 = local_18 ^ uVar8 ^ (uVar2 >> 8 | uVar2 << 0x18);
    uVar2 = uVar3 ^ param_3[0xe];
    uVar8 = param_3[0xf] ^ local_18;
    uVar2 = *(uint *)(&DAT_08236b00 + (uVar2 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar2 >> 0x18) * 4) ^
            *(uint *)(&DAT_08237300 + (uVar2 >> 8 & 0xff) * 4) ^
            *(uint *)(&DAT_08236f00 + (uVar2 >> 0x10 & 0xff) * 4);
    puVar5 = param_3 + 0x10;
    uVar8 = uVar2 ^ *(uint *)(&Camellia_SBOX + (uVar8 & 0xff) * 4) ^
                    *(uint *)(&DAT_08236f00 + (uVar8 >> 0x18) * 4) ^
                    *(uint *)(&DAT_08236b00 + (uVar8 >> 8 & 0xff) * 4) ^
                    *(uint *)(&DAT_08237300 + (uVar8 >> 0x10 & 0xff) * 4);
    uVar6 = uVar6 ^ uVar8;
    uVar8 = uVar8 ^ (uVar2 >> 8 | uVar2 << 0x18) ^ uVar4;
    if (puVar1 == puVar5) break;
    uVar3 = (param_3[0x13] | local_18) ^ uVar3;
    uVar8 = uVar8 ^ ((*puVar5 & uVar6) << 1 | (uint)((int)(*puVar5 & uVar6) < 0));
    uVar6 = (uVar8 | param_3[0x11]) ^ uVar6;
    local_18 = local_18 ^ ((param_3[0x12] & uVar3) << 1 | (uint)((int)(param_3[0x12] & uVar3) < 0));
    param_3 = puVar5;
  }
  local_18 = local_18 ^ puVar1[1];
  uVar3 = uVar3 ^ *puVar1;
  uVar6 = uVar6 ^ puVar1[2];
  uVar8 = uVar8 ^ puVar1[3];
  *param_4 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  param_4[1] = local_18 >> 0x18 | (local_18 & 0xff0000) >> 8 | (local_18 & 0xff00) << 8 |
               local_18 << 0x18;
  param_4[2] = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
  param_4[3] = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
  return;
}

