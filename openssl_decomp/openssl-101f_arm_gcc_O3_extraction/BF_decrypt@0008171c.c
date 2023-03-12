
void BF_decrypt(uint *data,BF_KEY *key)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = *data ^ key->P[0x11];
  uVar3 = data[1] ^ key->P[0x10] ^
          (*(int *)((int)key->S + (uVar6 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar6 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar6 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar6 & 0xff) + 0x300];
  uVar6 = uVar6 ^ key->P[0xf] ^
          key->S[(uVar3 & 0xff) + 0x300] +
          (*(int *)((int)key->S + (uVar3 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar3 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar3 >> 6 & 0x3fc) + 0x800));
  uVar3 = uVar3 ^ key->P[0xe] ^
          (*(int *)((int)key->S + (uVar6 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar6 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar6 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar6 & 0xff) + 0x300];
  uVar7 = uVar6 ^ key->P[0xd] ^
          (*(int *)((int)key->S + (uVar3 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar3 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar3 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar3 & 0xff) + 0x300];
  uVar6 = key->S[(uVar7 & 0xff) + 0x300] +
          (*(int *)((int)key->S + (uVar7 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar7 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar7 >> 6 & 0x3fc) + 0x800)) ^ uVar3 ^ key->P[0xc];
  uVar3 = uVar7 ^ key->P[0xb] ^
          key->S[(uVar6 & 0xff) + 0x300] +
          (*(int *)((int)key->S + (uVar6 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar6 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar6 >> 6 & 0x3fc) + 0x800));
  uVar6 = key->S[(uVar3 & 0xff) + 0x300] +
          (*(int *)((int)key->S + (uVar3 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar3 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar3 >> 6 & 0x3fc) + 0x800)) ^ key->P[10] ^ uVar6;
  uVar7 = key->P[1];
  uVar3 = uVar3 ^ key->P[9] ^
          key->S[(uVar6 & 0xff) + 0x300] +
          (*(int *)((int)key->S + (uVar6 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar6 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar6 >> 6 & 0x3fc) + 0x800));
  uVar6 = key->P[8] ^ uVar6 ^
          (*(int *)((int)key->S + (uVar3 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar3 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar3 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar3 & 0xff) + 0x300];
  uVar5 = uVar3 ^ key->P[7] ^
          (*(int *)((int)key->S + (uVar6 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar6 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar6 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar6 & 0xff) + 0x300];
  uVar3 = uVar6 ^ key->P[6] ^
          (*(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar5 & 0xff) + 0x300];
  uVar6 = uVar5 ^ key->P[5] ^
          (*(int *)((int)key->S + (uVar3 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar3 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar3 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar3 & 0xff) + 0x300];
  uVar3 = uVar3 ^ key->P[4] ^
          (*(int *)((int)key->S + (uVar6 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar6 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar6 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar6 & 0xff) + 0x300];
  uVar4 = uVar6 ^ key->P[3] ^
          (*(int *)((int)key->S + (uVar3 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar3 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar3 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar3 & 0xff) + 0x300];
  uVar6 = uVar3 ^ key->P[2] ^
          (*(int *)((int)key->S + (uVar4 >> 0x16 & 0x3fc)) +
           *(int *)((int)key->S + (uVar4 >> 0xe & 0x3fc) + 0x400) ^
          *(uint *)((int)key->S + (uVar4 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar4 & 0xff) + 0x300];
  iVar1 = *(int *)((int)key->S + (uVar6 >> 0xe & 0x3fc) + 0x400);
  iVar2 = *(int *)((int)key->S + (uVar6 >> 0x16 & 0x3fc));
  uVar5 = *(uint *)((int)key->S + (uVar6 >> 6 & 0x3fc) + 0x800);
  uVar3 = key->S[(uVar6 & 0xff) + 0x300];
  *data = key->P[0] ^ uVar6;
  data[1] = uVar7 ^ uVar4 ^ (iVar2 + iVar1 ^ uVar5) + uVar3;
  return;
}

