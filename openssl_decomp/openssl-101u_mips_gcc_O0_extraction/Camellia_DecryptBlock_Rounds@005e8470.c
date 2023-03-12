
void Camellia_DecryptBlock_Rounds(int param_1,byte *param_2,int param_3,undefined *param_4)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  puVar2 = (uint *)(param_3 + param_1 * 0x40);
  uVar8 = (int)puVar2 + (-0x40 - param_3);
  uVar5 = (uint)param_2[0xc] << 0x18 ^ (uint)param_2[0xd] << 0x10 ^ (uint)param_2[0xf] ^
          (uint)param_2[0xe] << 8 ^ puVar2[3];
  uVar4 = (uint)*param_2 << 0x18 ^ (uint)param_2[1] << 0x10 ^ (uint)param_2[3] ^
          (uint)param_2[2] << 8 ^ *puVar2;
  uVar6 = (uint)param_2[4] << 0x18 ^ (uint)param_2[5] << 0x10 ^ (uint)param_2[7] ^
          (uint)param_2[6] << 8 ^ puVar2[1];
  uVar7 = (uint)param_2[8] << 0x18 ^ (uint)param_2[9] << 0x10 ^ (uint)param_2[0xb] ^
          (uint)param_2[10] << 8 ^ puVar2[2];
  puVar1 = puVar2;
  while( true ) {
    uVar10 = uVar4 ^ puVar1[-2];
    uVar9 = uVar6 ^ puVar1[-1];
    uVar10 = *(uint *)(&Camellia_SBOX + ((uVar10 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar10 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar10 << 8) >> 0x18) + 0x200) * 4);
    uVar9 = uVar10 ^ *(uint *)(&Camellia_SBOX + (uVar9 & 0xff) * 4) ^
                     *(uint *)(&Camellia_SBOX + ((uVar9 >> 0x18) + 0x200) * 4) ^
                     *(uint *)(&Camellia_SBOX + (((uVar9 << 0x10) >> 0x18) + 0x100) * 4) ^
                     *(uint *)(&Camellia_SBOX + (((uVar9 << 8) >> 0x18) + 0x300) * 4);
    uVar7 = uVar7 ^ uVar9;
    uVar11 = uVar7 ^ puVar1[-4];
    uVar5 = (uVar10 >> 8) + uVar10 * 0x1000000 ^ uVar9 ^ uVar5;
    uVar9 = uVar5 ^ puVar1[-3];
    uVar10 = *(uint *)(&Camellia_SBOX + ((uVar11 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar11 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar11 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar11 << 8) >> 0x18) + 0x200) * 4);
    uVar11 = uVar10 ^ *(uint *)(&Camellia_SBOX + (uVar9 & 0xff) * 4) ^
                      *(uint *)(&Camellia_SBOX + ((uVar9 >> 0x18) + 0x200) * 4) ^
                      *(uint *)(&Camellia_SBOX + (((uVar9 << 0x10) >> 0x18) + 0x100) * 4) ^
                      *(uint *)(&Camellia_SBOX + (((uVar9 << 8) >> 0x18) + 0x300) * 4);
    uVar4 = uVar4 ^ uVar11;
    uVar9 = uVar4 ^ puVar1[-6];
    uVar11 = (uVar10 >> 8) + uVar10 * 0x1000000 ^ uVar6 ^ uVar11;
    uVar6 = uVar11 ^ puVar1[-5];
    uVar9 = *(uint *)(&Camellia_SBOX + ((uVar9 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar9 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar9 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar9 << 8) >> 0x18) + 0x200) * 4);
    uVar6 = uVar9 ^ *(uint *)(&Camellia_SBOX + (uVar6 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar6 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar6 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar6 << 8) >> 0x18) + 0x300) * 4);
    uVar7 = uVar7 ^ uVar6;
    uVar5 = (uVar9 >> 8) + uVar9 * 0x1000000 ^ uVar6 ^ uVar5;
    uVar9 = uVar7 ^ puVar1[-8];
    uVar6 = uVar5 ^ puVar1[-7];
    uVar9 = *(uint *)(&Camellia_SBOX + ((uVar9 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar9 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar9 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar9 << 8) >> 0x18) + 0x200) * 4);
    uVar10 = uVar9 ^ *(uint *)(&Camellia_SBOX + (uVar6 & 0xff) * 4) ^
                     *(uint *)(&Camellia_SBOX + ((uVar6 >> 0x18) + 0x200) * 4) ^
                     *(uint *)(&Camellia_SBOX + (((uVar6 << 0x10) >> 0x18) + 0x100) * 4) ^
                     *(uint *)(&Camellia_SBOX + (((uVar6 << 8) >> 0x18) + 0x300) * 4);
    uVar4 = uVar4 ^ uVar10;
    uVar10 = (uVar9 >> 8) + uVar9 * 0x1000000 ^ uVar11 ^ uVar10;
    uVar9 = uVar4 ^ puVar1[-10];
    uVar6 = uVar10 ^ puVar1[-9];
    uVar11 = *(uint *)(&Camellia_SBOX + ((uVar9 & 0xff) + 0x100) * 4) ^
             *(uint *)(&Camellia_SBOX + (uVar9 >> 0x18) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar9 << 0x10) >> 0x18) + 0x300) * 4) ^
             *(uint *)(&Camellia_SBOX + (((uVar9 << 8) >> 0x18) + 0x200) * 4);
    uVar9 = uVar11 ^ *(uint *)(&Camellia_SBOX + (uVar6 & 0xff) * 4) ^
                     *(uint *)(&Camellia_SBOX + ((uVar6 >> 0x18) + 0x200) * 4) ^
                     *(uint *)(&Camellia_SBOX + (((uVar6 << 0x10) >> 0x18) + 0x100) * 4) ^
                     *(uint *)(&Camellia_SBOX + (((uVar6 << 8) >> 0x18) + 0x300) * 4);
    uVar7 = uVar7 ^ uVar9;
    uVar6 = uVar7 ^ puVar1[-0xc];
    uVar5 = (uVar11 >> 8) + uVar11 * 0x1000000 ^ uVar9 ^ uVar5;
    uVar11 = uVar5 ^ puVar1[-0xb];
    uVar9 = *(uint *)(&Camellia_SBOX + ((uVar6 & 0xff) + 0x100) * 4) ^
            *(uint *)(&Camellia_SBOX + (uVar6 >> 0x18) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar6 << 0x10) >> 0x18) + 0x300) * 4) ^
            *(uint *)(&Camellia_SBOX + (((uVar6 << 8) >> 0x18) + 0x200) * 4);
    uVar6 = uVar9 ^ *(uint *)(&Camellia_SBOX + (uVar11 & 0xff) * 4) ^
                    *(uint *)(&Camellia_SBOX + ((uVar11 >> 0x18) + 0x200) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar11 << 0x10) >> 0x18) + 0x100) * 4) ^
                    *(uint *)(&Camellia_SBOX + (((uVar11 << 8) >> 0x18) + 0x300) * 4);
    uVar4 = uVar4 ^ uVar6;
    uVar6 = (uVar9 >> 8) + uVar9 * 0x1000000 ^ uVar10 ^ uVar6;
    if (puVar1 == (uint *)((int)puVar2 - uVar8)) break;
    uVar7 = (uVar5 | puVar1[-0xf]) ^ uVar7;
    uVar9 = uVar7 & puVar1[-0x10];
    uVar6 = (uVar4 & puVar1[-0xe]) * 2 - ((int)(uVar4 & puVar1[-0xe]) >> 0x1f) ^ uVar6;
    uVar4 = (uVar6 | puVar1[-0xd]) ^ uVar4;
    uVar5 = uVar9 * 2 - ((int)uVar9 >> 0x1f) ^ uVar5;
    puVar1 = puVar1 + -0x10;
  }
  iVar3 = (int)puVar2 - (uVar8 & 0xffffffc0);
  uVar8 = *(uint *)(&DAT_ffffffc4 + iVar3);
  uVar7 = uVar7 ^ *(uint *)(iVar3 + -0x40);
  uVar9 = *(uint *)(&DAT_ffffffcc + iVar3);
  uVar4 = uVar4 ^ *(uint *)(&DAT_ffffffc8 + iVar3);
  param_4[3] = (char)uVar7;
  uVar5 = uVar5 ^ uVar8;
  param_4[0xb] = (char)uVar4;
  *param_4 = (char)(uVar7 >> 0x18);
  param_4[1] = (char)(uVar7 >> 0x10);
  param_4[7] = (char)uVar5;
  uVar6 = uVar6 ^ uVar9;
  param_4[4] = (char)(uVar5 >> 0x18);
  param_4[5] = (char)(uVar5 >> 0x10);
  param_4[0xf] = (char)uVar6;
  param_4[8] = (char)(uVar4 >> 0x18);
  param_4[2] = (char)(uVar7 >> 8);
  param_4[9] = (char)(uVar4 >> 0x10);
  param_4[0xc] = (char)(uVar6 >> 0x18);
  param_4[6] = (char)(uVar5 >> 8);
  param_4[0xd] = (char)(uVar6 >> 0x10);
  param_4[10] = (char)(uVar4 >> 8);
  param_4[0xe] = (char)(uVar6 >> 8);
  return;
}

