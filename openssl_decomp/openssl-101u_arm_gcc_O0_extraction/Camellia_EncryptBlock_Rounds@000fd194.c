
void Camellia_EncryptBlock_Rounds(int param_1,byte *param_2,uint *param_3,undefined *param_4)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  puVar3 = param_3 + 4;
  uVar9 = (((uint)param_2[5] << 0x10 | (uint)param_2[4] << 0x18) ^ (uint)param_2[7] |
          (uint)param_2[6] << 8) ^ param_3[1];
  uVar7 = (((uint)param_2[9] << 0x10 | (uint)param_2[8] << 0x18) ^ (uint)param_2[0xb] |
          (uint)param_2[10] << 8) ^ param_3[2];
  uVar8 = (((uint)param_2[1] << 0x10 | (uint)*param_2 << 0x18) ^ (uint)param_2[3] |
          (uint)param_2[2] << 8) ^ *param_3;
  uVar5 = (((uint)param_2[0xd] << 0x10 | (uint)param_2[0xc] << 0x18) ^ (uint)param_2[0xf] |
          (uint)param_2[0xe] << 8) ^ param_3[3];
  puVar4 = puVar3;
  puVar6 = param_3;
  while( true ) {
    puVar1 = puVar6 + 4;
    puVar6 = puVar6 + 0x10;
    uVar10 = uVar8 ^ *puVar1;
    uVar2 = puVar4[1] ^ uVar9;
    uVar10 = *(uint *)(&Camellia_SBOX + ((uVar10 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar10 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 8) >> 0x18) + 0x200) * 4);
    uVar2 = *(uint *)(&Camellia_SBOX + (uVar2 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar2 >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar2 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar2 << 8) >> 0x18) + 0x300) * 4) ^ uVar10;
    uVar7 = uVar7 ^ uVar2;
    uVar5 = uVar2 ^ (uVar10 >> 8 | uVar10 << 0x18) ^ uVar5;
    uVar10 = puVar4[3] ^ uVar5;
    uVar2 = puVar4[2] ^ uVar7;
    uVar11 = *(uint *)(&Camellia_SBOX + ((uVar2 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar2 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar2 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar2 << 8) >> 0x18) + 0x200) * 4);
    uVar2 = *(uint *)(&Camellia_SBOX + (uVar10 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar10 >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar10 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar10 << 8) >> 0x18) + 0x300) * 4) ^ uVar11;
    uVar8 = uVar8 ^ uVar2;
    uVar2 = uVar9 ^ (uVar11 >> 8 | uVar11 << 0x18) ^ uVar2;
    uVar9 = puVar4[5] ^ uVar2;
    uVar10 = uVar8 ^ puVar4[4];
    uVar10 = *(uint *)(&Camellia_SBOX + ((uVar10 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar10 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 8) >> 0x18) + 0x200) * 4);
    uVar9 = *(uint *)(&Camellia_SBOX + (uVar9 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar9 >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar9 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar9 << 8) >> 0x18) + 0x300) * 4) ^ uVar10;
    uVar7 = uVar9 ^ uVar7;
    uVar5 = uVar9 ^ (uVar10 >> 8 | uVar10 << 0x18) ^ uVar5;
    uVar9 = uVar7 ^ puVar4[6];
    uVar10 = uVar5 ^ puVar4[7];
    uVar11 = *(uint *)(&Camellia_SBOX + ((uVar9 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar9 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar9 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar9 << 8) >> 0x18) + 0x200) * 4);
    uVar9 = *(uint *)(&Camellia_SBOX + (uVar10 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar10 >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar10 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar10 << 8) >> 0x18) + 0x300) * 4) ^ uVar11;
    uVar11 = uVar2 ^ (uVar11 >> 8 | uVar11 << 0x18) ^ uVar9;
    uVar8 = uVar8 ^ uVar9;
    uVar9 = uVar11 ^ puVar4[9];
    uVar2 = puVar4[8] ^ uVar8;
    uVar2 = *(uint *)(&Camellia_SBOX + ((uVar2 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar2 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar2 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar2 << 8) >> 0x18) + 0x200) * 4);
    uVar10 = *(uint *)(&Camellia_SBOX + (uVar9 & 0xff) * 4) ^
             *(uint *)(&Camellia_SBOX + ((uVar9 >> 0x18) + 0x200) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar9 << 0x10) >> 0x18) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar9 << 8) >> 0x18) + 0x300) * 4) ^ uVar2;
    uVar7 = uVar10 ^ uVar7;
    uVar9 = puVar4[10] ^ uVar7;
    uVar5 = uVar10 ^ (uVar2 >> 8 | uVar2 << 0x18) ^ uVar5;
    uVar2 = puVar4[0xb] ^ uVar5;
    uVar10 = *(uint *)(&Camellia_SBOX + ((uVar9 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar9 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar9 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar9 << 8) >> 0x18) + 0x200) * 4);
    uVar9 = *(uint *)(&Camellia_SBOX + ((uVar2 >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar2 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar2 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar2 << 8) >> 0x18) + 0x300) * 4) ^ uVar10;
    uVar8 = uVar9 ^ uVar8;
    uVar9 = uVar11 ^ (uVar10 >> 8 | uVar10 << 0x18) ^ uVar9;
    if (param_3 + param_1 * 0x10 == puVar6) break;
    uVar7 = uVar7 ^ (puVar4[0xf] | uVar5);
    uVar9 = uVar9 ^ ((uVar8 & puVar4[0xc]) >> 0x1f | (uVar8 & puVar4[0xc]) << 1);
    uVar5 = uVar5 ^ ((puVar4[0xe] & uVar7) >> 0x1f | (puVar4[0xe] & uVar7) << 1);
    uVar8 = uVar8 ^ (puVar4[0xd] | uVar9);
    puVar4 = puVar4 + 0x10;
  }
  uVar2 = (int)(param_3 + param_1 * 0x10) - (int)(param_3 + 0x10) & 0xffffffc0;
  uVar7 = uVar7 ^ *(uint *)((int)puVar3 + uVar2 + 0x30);
  uVar8 = uVar8 ^ *(uint *)((int)puVar3 + uVar2 + 0x38);
  uVar5 = uVar5 ^ *(uint *)((int)puVar3 + uVar2 + 0x34);
  uVar9 = uVar9 ^ *(uint *)((int)puVar3 + uVar2 + 0x3c);
  *param_4 = (char)(uVar7 >> 0x18);
  param_4[3] = (char)uVar7;
  param_4[7] = (char)uVar5;
  param_4[0xb] = (char)uVar8;
  param_4[0xf] = (char)uVar9;
  param_4[1] = (char)(uVar7 >> 0x10);
  param_4[4] = (char)(uVar5 >> 0x18);
  param_4[5] = (char)(uVar5 >> 0x10);
  param_4[8] = (char)(uVar8 >> 0x18);
  param_4[2] = (char)(uVar7 >> 8);
  param_4[6] = (char)(uVar5 >> 8);
  param_4[9] = (char)(uVar8 >> 0x10);
  param_4[10] = (char)(uVar8 >> 8);
  param_4[0xc] = (char)(uVar9 >> 0x18);
  param_4[0xd] = (char)(uVar9 >> 0x10);
  param_4[0xe] = (char)(uVar9 >> 8);
  return;
}

