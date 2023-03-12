
void Camellia_DecryptBlock_Rounds(int param_1,byte *param_2,int param_3,undefined *param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *local_3c;
  
  puVar7 = (uint *)(param_3 + param_1 * 0x40);
  uVar11 = (uint)((-0x40 - param_3) + (int)puVar7) >> 6;
  uVar9 = (((uint)param_2[1] << 0x10 | (uint)*param_2 << 0x18) ^ (uint)param_2[3] |
          (uint)param_2[2] << 8) ^ *(uint *)(param_3 + param_1 * 0x40);
  uVar6 = (((uint)param_2[0xd] << 0x10 | (uint)param_2[0xc] << 0x18) ^ (uint)param_2[0xf] |
          (uint)param_2[0xe] << 8) ^ puVar7[3];
  uVar10 = ((uint)param_2[7] ^ ((uint)param_2[5] << 0x10 | (uint)param_2[4] << 0x18) |
           (uint)param_2[6] << 8) ^ puVar7[1];
  uVar8 = (((uint)param_2[9] << 0x10 | (uint)param_2[8] << 0x18) ^ (uint)param_2[0xb] |
          (uint)param_2[10] << 8) ^ puVar7[2];
  puVar5 = puVar7;
  local_3c = puVar7;
  while( true ) {
    uVar12 = uVar9 ^ puVar5[-2];
    uVar4 = uVar10 ^ puVar5[-1];
    uVar12 = *(uint *)(&Camellia_SBOX + ((uVar12 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar12 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar12 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar12 << 8) >> 0x18) + 0x200) * 4);
    uVar4 = *(uint *)(&Camellia_SBOX + (uVar4 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar4 >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar4 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar4 << 8) >> 0x18) + 0x300) * 4) ^ uVar12;
    uVar8 = uVar8 ^ uVar4;
    uVar6 = uVar4 ^ (uVar12 >> 8 | uVar12 << 0x18) ^ uVar6;
    uVar12 = puVar5[-3] ^ uVar6;
    uVar4 = puVar5[-4] ^ uVar8;
    uVar13 = *(uint *)(&Camellia_SBOX + ((uVar4 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar4 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar4 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar4 << 8) >> 0x18) + 0x200) * 4);
    uVar4 = *(uint *)(&Camellia_SBOX + (uVar12 & 0xff) * 4) ^
            *(uint *)(&Camellia_SBOX + ((uVar12 >> 0x18) + 0x200) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar12 << 0x10) >> 0x18) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar12 << 8) >> 0x18) + 0x300) * 4) ^ uVar13;
    uVar9 = uVar9 ^ uVar4;
    uVar4 = uVar10 ^ (uVar13 >> 8 | uVar13 << 0x18) ^ uVar4;
    uVar12 = uVar9 ^ puVar5[-6];
    uVar10 = puVar5[-5] ^ uVar4;
    uVar12 = *(uint *)(&Camellia_SBOX + ((uVar12 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar12 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar12 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar12 << 8) >> 0x18) + 0x200) * 4);
    uVar10 = *(uint *)(&Camellia_SBOX + (uVar10 & 0xff) * 4) ^
             *(uint *)(&Camellia_SBOX + ((uVar10 >> 0x18) + 0x200) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 0x10) >> 0x18) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 8) >> 0x18) + 0x300) * 4) ^ uVar12;
    uVar8 = uVar10 ^ uVar8;
    uVar6 = uVar10 ^ (uVar12 >> 8 | uVar12 << 0x18) ^ uVar6;
    uVar10 = uVar8 ^ puVar5[-8];
    uVar12 = uVar6 ^ puVar5[-7];
    uVar13 = *(uint *)(&Camellia_SBOX + ((uVar10 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar10 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 8) >> 0x18) + 0x200) * 4);
    uVar10 = *(uint *)(&Camellia_SBOX + (uVar12 & 0xff) * 4) ^
             *(uint *)(&Camellia_SBOX + ((uVar12 >> 0x18) + 0x200) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar12 << 0x10) >> 0x18) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar12 << 8) >> 0x18) + 0x300) * 4) ^ uVar13;
    uVar13 = uVar4 ^ (uVar13 >> 8 | uVar13 << 0x18) ^ uVar10;
    uVar9 = uVar9 ^ uVar10;
    uVar10 = uVar13 ^ puVar5[-9];
    uVar4 = puVar5[-10] ^ uVar9;
    uVar4 = *(uint *)(&Camellia_SBOX + ((uVar4 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar4 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar4 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar4 << 8) >> 0x18) + 0x200) * 4);
    uVar12 = *(uint *)(&Camellia_SBOX + (uVar10 & 0xff) * 4) ^
             *(uint *)(&Camellia_SBOX + ((uVar10 >> 0x18) + 0x200) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 0x10) >> 0x18) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 8) >> 0x18) + 0x300) * 4) ^ uVar4;
    uVar8 = uVar12 ^ uVar8;
    uVar10 = puVar5[-0xc] ^ uVar8;
    uVar6 = uVar12 ^ (uVar4 >> 8 | uVar4 << 0x18) ^ uVar6;
    uVar4 = puVar5[-0xb] ^ uVar6;
    uVar12 = *(uint *)(&Camellia_SBOX + ((uVar10 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar10 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 8) >> 0x18) + 0x200) * 4);
    uVar10 = *(uint *)(&Camellia_SBOX + ((uVar4 >> 0x18) + 0x200) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar4 & 0xff) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar4 << 0x10) >> 0x18) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar4 << 8) >> 0x18) + 0x300) * 4) ^ uVar12;
    uVar9 = uVar10 ^ uVar9;
    uVar10 = uVar13 ^ (uVar12 >> 8 | uVar12 << 0x18) ^ uVar10;
    if (puVar5 == puVar7 + uVar11 * -0x10) break;
    puVar5 = puVar5 + -0x10;
    puVar1 = local_3c + -0xe;
    puVar2 = local_3c + -0xf;
    puVar3 = local_3c + -0xd;
    local_3c = local_3c + -0x10;
    uVar8 = (uVar6 | *puVar2) ^ uVar8;
    uVar10 = uVar10 ^ ((uVar9 & *puVar1) >> 0x1f | (uVar9 & *puVar1) << 1);
    uVar9 = uVar9 ^ (uVar10 | *puVar3);
    uVar6 = uVar6 ^ ((uVar8 & *local_3c) >> 0x1f | (uVar8 & *local_3c) << 1);
  }
  uVar10 = uVar10 ^ puVar7[uVar11 * -0x10 + -0xd];
  uVar8 = uVar8 ^ puVar7[uVar11 * -0x10 + -0x10];
  uVar9 = uVar9 ^ puVar7[uVar11 * -0x10 + -0xe];
  uVar6 = uVar6 ^ puVar7[uVar11 * -0x10 + -0xf];
  param_4[3] = (char)uVar8;
  *param_4 = (char)(uVar8 >> 0x18);
  param_4[7] = (char)uVar6;
  param_4[0xb] = (char)uVar9;
  param_4[0xf] = (char)uVar10;
  param_4[1] = (char)(uVar8 >> 0x10);
  param_4[4] = (char)(uVar6 >> 0x18);
  param_4[5] = (char)(uVar6 >> 0x10);
  param_4[8] = (char)(uVar9 >> 0x18);
  param_4[2] = (char)(uVar8 >> 8);
  param_4[6] = (char)(uVar6 >> 8);
  param_4[9] = (char)(uVar9 >> 0x10);
  param_4[10] = (char)(uVar9 >> 8);
  param_4[0xc] = (char)(uVar10 >> 0x18);
  param_4[0xd] = (char)(uVar10 >> 0x10);
  param_4[0xe] = (char)(uVar10 >> 8);
  return;
}

