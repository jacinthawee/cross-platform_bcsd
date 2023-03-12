
void BF_encrypt(uint *data,BF_KEY *key)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar5 = *data ^ key->P[0];
  uVar3 = data[1] ^ key->P[1] ^
          (*(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) +
          *(int *)((int)key->S + (uVar5 * 4 & 0x3fc) + 0xc00);
  uVar5 = uVar5 ^ key->P[2] ^
          (*(int *)((int)key->S + (uVar3 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar3 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar3 >> 6 & 0x3fc) + 0x800)) +
          *(int *)((int)key->S + (uVar3 * 4 & 0x3fc) + 0xc00);
  uVar3 = uVar3 ^ key->P[3] ^
          (*(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) +
          *(int *)((int)key->S + (uVar5 * 4 & 0x3fc) + 0xc00);
  uVar5 = uVar5 ^ key->P[4] ^
          (*(int *)((int)key->S + (uVar3 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar3 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar3 >> 6 & 0x3fc) + 0x800)) +
          *(int *)((int)key->S + (uVar3 * 4 & 0x3fc) + 0xc00);
  uVar3 = uVar3 ^ key->P[5] ^
          (*(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) +
          *(int *)((int)key->S + (uVar5 * 4 & 0x3fc) + 0xc00);
  uVar5 = uVar5 ^ key->P[6] ^
          (*(int *)((int)key->S + (uVar3 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar3 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar3 >> 6 & 0x3fc) + 0x800)) +
          *(int *)((int)key->S + (uVar3 * 4 & 0x3fc) + 0xc00);
  uVar3 = uVar3 ^ key->P[7] ^
          (*(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) +
          *(int *)((int)key->S + (uVar5 * 4 & 0x3fc) + 0xc00);
  uVar5 = uVar5 ^ key->P[8] ^
          (*(int *)((int)key->S + (uVar3 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar3 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar3 >> 6 & 0x3fc) + 0x800)) +
          *(int *)((int)key->S + (uVar3 * 4 & 0x3fc) + 0xc00);
  uVar3 = uVar3 ^ key->P[9] ^
          (*(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) +
          *(int *)((int)key->S + (uVar5 * 4 & 0x3fc) + 0xc00);
  uVar5 = uVar5 ^ key->P[10] ^
          (*(int *)((int)key->S + (uVar3 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar3 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar3 >> 6 & 0x3fc) + 0x800)) +
          *(int *)((int)key->S + (uVar3 * 4 & 0x3fc) + 0xc00);
  uVar3 = uVar3 ^ key->P[0xb] ^
          (*(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) +
          *(int *)((int)key->S + (uVar5 * 4 & 0x3fc) + 0xc00);
  uVar6 = uVar5 ^ key->P[0xc] ^
          (*(int *)((int)key->S + (uVar3 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar3 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar3 >> 6 & 0x3fc) + 0x800)) +
          *(int *)((int)key->S + (uVar3 * 4 & 0x3fc) + 0xc00);
  uVar5 = uVar3 ^ key->P[0xd] ^
          (*(int *)((int)key->S + (uVar6 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar6 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar6 >> 6 & 0x3fc) + 0x800)) +
          *(int *)((int)key->S + (uVar6 * 4 & 0x3fc) + 0xc00);
  uVar7 = uVar6 ^ key->P[0xe] ^
          (*(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) +
          *(int *)((int)key->S + (uVar5 * 4 & 0x3fc) + 0xc00);
  uVar3 = key->P[0x10];
  uVar4 = uVar5 ^ key->P[0xf] ^
          (*(int *)((int)key->S + (uVar7 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar7 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar7 >> 6 & 0x3fc) + 0x800)) +
          *(int *)((int)key->S + (uVar7 * 4 & 0x3fc) + 0xc00);
  iVar1 = *(int *)((int)key->S + (uVar4 >> 0x16 & 0x3fc));
  iVar2 = *(int *)((int)key->S + (uVar4 >> 0xe & 0x3fc) + 0x400);
  uVar5 = *(uint *)((int)key->S + (uVar4 >> 6 & 0x3fc) + 0x800);
  uVar6 = key->S[(uVar4 & 0xff) + 0x300];
  *data = key->P[0x11] ^ uVar4;
  data[1] = (iVar1 + iVar2 ^ uVar5) + uVar6 ^ uVar7 ^ uVar3;
  return;
}

