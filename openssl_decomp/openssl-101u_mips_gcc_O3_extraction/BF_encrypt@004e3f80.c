
void BF_encrypt(uint *data,BF_KEY *key)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar5 = *data ^ key->P[0];
  uVar4 = (*(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar5 & 0xff) + 0x300] ^
          data[1] ^ key->P[1];
  uVar5 = (*(int *)((int)key->S + (uVar4 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar4 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar4 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar4 & 0xff) + 0x300] ^
          uVar5 ^ key->P[2];
  uVar4 = (*(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar5 & 0xff) + 0x300] ^
          uVar4 ^ key->P[3];
  uVar5 = (*(int *)((int)key->S + (uVar4 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar4 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar4 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar4 & 0xff) + 0x300] ^
          uVar5 ^ key->P[4];
  uVar4 = (*(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar5 & 0xff) + 0x300] ^
          uVar4 ^ key->P[5];
  uVar5 = (*(int *)((int)key->S + (uVar4 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar4 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar4 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar4 & 0xff) + 0x300] ^
          uVar5 ^ key->P[6];
  uVar7 = (*(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar5 & 0xff) + 0x300] ^
          uVar4 ^ key->P[7];
  uVar4 = (*(int *)((int)key->S + (uVar7 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar7 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar7 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar7 & 0xff) + 0x300] ^
          uVar5 ^ key->P[8];
  uVar5 = (*(int *)((int)key->S + (uVar4 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar4 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar4 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar4 & 0xff) + 0x300] ^
          uVar7 ^ key->P[9];
  uVar4 = (*(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar5 & 0xff) + 0x300] ^
          uVar4 ^ key->P[10];
  uVar5 = (*(int *)((int)key->S + (uVar4 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar4 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar4 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar4 & 0xff) + 0x300] ^
          uVar5 ^ key->P[0xb];
  uVar4 = (*(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar5 & 0xff) + 0x300] ^
          uVar4 ^ key->P[0xc];
  uVar6 = key->P[0x10];
  uVar5 = (*(int *)((int)key->S + (uVar4 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar4 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar4 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar4 & 0xff) + 0x300] ^
          uVar5 ^ key->P[0xd];
  uVar7 = (*(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar5 & 0xff) + 0x300] ^
          uVar4 ^ key->P[0xe];
  uVar5 = (*(int *)((int)key->S + (uVar7 >> 0xe & 0x3fc) + 0x400) +
           *(int *)((int)key->S + (uVar7 >> 0x16 & 0x3fc)) ^
          *(uint *)((int)key->S + (uVar7 >> 6 & 0x3fc) + 0x800)) + key->S[(uVar7 & 0xff) + 0x300] ^
          uVar5 ^ key->P[0xf];
  iVar3 = *(int *)((int)key->S + (uVar5 >> 0x16 & 0x3fc));
  iVar1 = *(int *)((int)key->S + (uVar5 >> 0xe & 0x3fc) + 0x400);
  uVar2 = *(uint *)((int)key->S + (uVar5 >> 6 & 0x3fc) + 0x800);
  uVar4 = key->S[(uVar5 & 0xff) + 0x300];
  *data = uVar5 ^ key->P[0x11];
  data[1] = (iVar1 + iVar3 ^ uVar2) + uVar4 ^ uVar7 ^ uVar6;
  return;
}

