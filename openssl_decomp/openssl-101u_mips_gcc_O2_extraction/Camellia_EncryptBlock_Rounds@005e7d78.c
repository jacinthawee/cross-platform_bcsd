
void Camellia_EncryptBlock_Rounds(int param_1,byte *param_2,uint *param_3,undefined *param_4)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  puVar2 = param_3 + param_1 * 0x10;
  uVar8 = (uint)*param_2 << 0x18 ^ (uint)param_2[1] << 0x10 ^ (uint)param_2[3] ^
          (uint)param_2[2] << 8 ^ *param_3;
  uVar1 = (uint)param_2[4] << 0x18 ^ (uint)param_2[5] << 0x10 ^ (uint)param_2[7] ^
          (uint)param_2[6] << 8 ^ param_3[1];
  uVar7 = (uint)param_2[8] << 0x18 ^ (uint)param_2[9] << 0x10 ^ (uint)param_2[0xb] ^
          (uint)param_2[10] << 8 ^ param_3[2];
  uVar4 = (uint)param_2[0xc] << 0x18 ^ (uint)param_2[0xd] << 0x10 ^ (uint)param_2[0xf] ^
          (uint)param_2[0xe] << 8 ^ param_3[3];
  while( true ) {
    puVar3 = param_3 + 0x10;
    uVar6 = uVar8 ^ param_3[4];
    uVar5 = uVar1 ^ param_3[5];
    uVar6 = *(uint *)(&Camellia_SBOX + ((uVar6 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar6 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar6 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar6 << 8) >> 0x18) + 0x200) * 4);
    uVar5 = uVar6 ^ *(uint *)(&Camellia_SBOX + (uVar5 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar5 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar5 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar5 << 8) >> 0x18) + 0x300) * 4);
    uVar7 = uVar7 ^ uVar5;
    uVar9 = uVar7 ^ param_3[6];
    uVar4 = (uVar6 >> 8) + uVar6 * 0x1000000 ^ uVar5 ^ uVar4;
    uVar5 = uVar4 ^ param_3[7];
    uVar6 = *(uint *)(&Camellia_SBOX + ((uVar9 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar9 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar9 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar9 << 8) >> 0x18) + 0x200) * 4);
    uVar5 = uVar6 ^ *(uint *)(&Camellia_SBOX + (uVar5 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar5 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar5 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar5 << 8) >> 0x18) + 0x300) * 4);
    uVar9 = (uVar6 >> 8) + uVar6 * 0x1000000 ^ uVar1 ^ uVar5;
    uVar8 = uVar8 ^ uVar5;
    uVar5 = uVar8 ^ param_3[8];
    uVar1 = uVar9 ^ param_3[9];
    uVar5 = *(uint *)(&Camellia_SBOX + ((uVar5 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar5 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar5 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar5 << 8) >> 0x18) + 0x200) * 4);
    uVar1 = uVar5 ^ *(uint *)(&Camellia_SBOX + (uVar1 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar1 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar1 << 8) >> 0x18) + 0x300) * 4);
    uVar7 = uVar7 ^ uVar1;
    uVar6 = uVar7 ^ param_3[10];
    uVar4 = (uVar5 >> 8) + uVar5 * 0x1000000 ^ uVar1 ^ uVar4;
    uVar1 = uVar4 ^ param_3[0xb];
    uVar5 = *(uint *)(&Camellia_SBOX + ((uVar6 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar6 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar6 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar6 << 8) >> 0x18) + 0x200) * 4);
    uVar1 = uVar5 ^ *(uint *)(&Camellia_SBOX + (uVar1 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar1 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar1 << 8) >> 0x18) + 0x300) * 4);
    uVar9 = (uVar5 >> 8) + uVar5 * 0x1000000 ^ uVar9 ^ uVar1;
    uVar8 = uVar8 ^ uVar1;
    uVar5 = uVar8 ^ param_3[0xc];
    uVar1 = uVar9 ^ param_3[0xd];
    uVar6 = *(uint *)(&Camellia_SBOX + ((uVar5 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar5 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar5 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar5 << 8) >> 0x18) + 0x200) * 4);
    uVar5 = uVar6 ^ *(uint *)(&Camellia_SBOX + (uVar1 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar1 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar1 << 8) >> 0x18) + 0x300) * 4);
    uVar7 = uVar7 ^ uVar5;
    uVar1 = uVar7 ^ param_3[0xe];
    uVar4 = (uVar6 >> 8) + uVar6 * 0x1000000 ^ uVar5 ^ uVar4;
    uVar5 = uVar4 ^ param_3[0xf];
    uVar6 = *(uint *)(&Camellia_SBOX + ((uVar1 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar1 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar1 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar1 << 8) >> 0x18) + 0x200) * 4);
    uVar1 = uVar6 ^ *(uint *)(&Camellia_SBOX + (uVar5 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar5 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar5 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar5 << 8) >> 0x18) + 0x300) * 4);
    uVar8 = uVar8 ^ uVar1;
    uVar1 = (uVar6 >> 8) + uVar6 * 0x1000000 ^ uVar9 ^ uVar1;
    if (puVar2 == puVar3) break;
    uVar7 = (uVar4 | param_3[0x13]) ^ uVar7;
    uVar1 = (uVar8 & *puVar3) * 2 - ((int)(uVar8 & *puVar3) >> 0x1f) ^ uVar1;
    uVar8 = (uVar1 | param_3[0x11]) ^ uVar8;
    uVar4 = (uVar7 & param_3[0x12]) * 2 - ((int)(uVar7 & param_3[0x12]) >> 0x1f) ^ uVar4;
    param_3 = puVar3;
  }
  uVar7 = uVar7 ^ *puVar2;
  uVar1 = uVar1 ^ puVar2[3];
  uVar4 = uVar4 ^ puVar2[1];
  uVar8 = uVar8 ^ puVar2[2];
  *param_4 = (char)(uVar7 >> 0x18);
  param_4[1] = (char)(uVar7 >> 0x10);
  param_4[3] = (char)uVar7;
  param_4[7] = (char)uVar4;
  param_4[0xb] = (char)uVar8;
  param_4[0xf] = (char)uVar1;
  param_4[4] = (char)(uVar4 >> 0x18);
  param_4[5] = (char)(uVar4 >> 0x10);
  param_4[8] = (char)(uVar8 >> 0x18);
  param_4[2] = (char)(uVar7 >> 8);
  param_4[6] = (char)(uVar4 >> 8);
  param_4[9] = (char)(uVar8 >> 0x10);
  param_4[10] = (char)(uVar8 >> 8);
  param_4[0xc] = (char)(uVar1 >> 0x18);
  param_4[0xd] = (char)(uVar1 >> 0x10);
  param_4[0xe] = (char)(uVar1 >> 8);
  return;
}

