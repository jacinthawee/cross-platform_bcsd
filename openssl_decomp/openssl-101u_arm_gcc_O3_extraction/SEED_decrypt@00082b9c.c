
void SEED_decrypt(uchar *s,uchar *d,SEED_KEY_SCHEDULE *ks)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = (uint)s[9] << 0x10 | (uint)s[8] << 0x18 | (uint)s[0xb] | (uint)s[10] << 8;
  uVar6 = (uint)s[0xd] << 0x10 | (uint)s[0xc] << 0x18 | (uint)s[0xf] | (uint)s[0xe] << 8;
  uVar3 = uVar7 ^ ks->data[0x1e];
  uVar1 = uVar6 ^ ks->data[0x1f] ^ uVar3;
  uVar1 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4);
  uVar3 = uVar3 + uVar1;
  uVar4 = *(uint *)(&SS + ((uVar3 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar3 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4);
  uVar1 = uVar1 + uVar4;
  uVar3 = *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  uVar2 = uVar3 + uVar4 ^ ((uint)s[1] << 0x10 | (uint)*s << 0x18 | (uint)s[3] | (uint)s[2] << 8);
  uVar3 = ((uint)s[5] << 0x10 | (uint)s[4] << 0x18 | (uint)s[7] | (uint)s[6] << 8) ^ uVar3;
  uVar1 = ks->data[0x1c] ^ uVar2;
  uVar4 = ks->data[0x1d] ^ uVar3 ^ uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar4 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + (((uVar4 << 8) >> 0x18) + 0x200) * 4);
  uVar1 = uVar1 + uVar4;
  uVar1 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  uVar4 = uVar4 + uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4);
  uVar6 = uVar4 ^ uVar6;
  uVar7 = uVar1 + uVar4 ^ uVar7;
  uVar4 = uVar7 ^ ks->data[0x1a];
  uVar1 = uVar6 ^ ks->data[0x1b] ^ uVar4;
  uVar1 = *(uint *)(&SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4);
  uVar4 = uVar1 + uVar4;
  uVar4 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4);
  uVar1 = uVar4 + uVar1;
  uVar1 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  uVar3 = uVar3 ^ uVar1;
  uVar2 = uVar2 ^ uVar4 + uVar1;
  uVar5 = uVar2 ^ ks->data[0x18];
  uVar1 = uVar3 ^ ks->data[0x19] ^ uVar5;
  uVar4 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4);
  uVar5 = uVar5 + uVar4;
  uVar1 = *(uint *)(&SS + ((uVar5 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(&SS + ((uVar5 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar5 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar5 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar4 = uVar4 + uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar6 = uVar4 ^ uVar6;
  uVar7 = uVar1 + uVar4 ^ uVar7;
  uVar1 = uVar7 ^ ks->data[0x16];
  uVar4 = uVar6 ^ ks->data[0x17] ^ uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar4 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + (((uVar4 << 8) >> 0x18) + 0x200) * 4);
  uVar1 = uVar1 + uVar4;
  uVar1 = *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar4 = uVar4 + uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 ^ uVar4;
  uVar2 = uVar2 ^ uVar1 + uVar4;
  uVar5 = uVar2 ^ ks->data[0x14];
  uVar1 = uVar3 ^ ks->data[0x15] ^ uVar5;
  uVar4 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4);
  uVar5 = uVar5 + uVar4;
  uVar1 = *(uint *)(&SS + ((uVar5 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(&SS + ((uVar5 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar5 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar5 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar4 = uVar4 + uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar6 = uVar4 ^ uVar6;
  uVar7 = uVar1 + uVar4 ^ uVar7;
  uVar5 = uVar7 ^ ks->data[0x12];
  uVar1 = uVar6 ^ ks->data[0x13] ^ uVar5;
  uVar4 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4);
  uVar5 = uVar5 + uVar4;
  uVar1 = *(uint *)(&SS + ((uVar5 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(&SS + ((uVar5 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar5 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar5 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar4 = uVar4 + uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 ^ uVar4;
  uVar2 = uVar2 ^ uVar1 + uVar4;
  uVar1 = uVar2 ^ ks->data[0x10];
  uVar4 = uVar3 ^ ks->data[0x11] ^ uVar1;
  uVar5 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar4 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + (((uVar4 << 8) >> 0x18) + 0x200) * 4);
  uVar1 = uVar1 + uVar5;
  uVar4 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  uVar5 = uVar5 + uVar4;
  uVar1 = *(uint *)(&SS + ((uVar5 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(&SS + ((uVar5 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar5 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar5 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar6 = uVar1 ^ uVar6;
  uVar7 = uVar4 + uVar1 ^ uVar7;
  uVar4 = uVar7 ^ ks->data[0xe];
  uVar1 = uVar6 ^ ks->data[0xf] ^ uVar4;
  uVar1 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4);
  uVar4 = uVar4 + uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = uVar1 + uVar4;
  uVar1 = *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  uVar3 = uVar1 ^ uVar3;
  uVar2 = uVar2 ^ uVar4 + uVar1;
  uVar4 = uVar2 ^ ks->data[0xc];
  uVar1 = ks->data[0xd] ^ uVar3 ^ uVar4;
  uVar1 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4);
  uVar4 = uVar4 + uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4);
  uVar1 = uVar1 + uVar4;
  uVar1 = *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar6 = uVar1 ^ uVar6;
  uVar7 = uVar4 + uVar1 ^ uVar7;
  uVar1 = uVar7 ^ ks->data[10];
  uVar4 = uVar6 ^ ks->data[0xb] ^ uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar4 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + (((uVar4 << 8) >> 0x18) + 0x200) * 4);
  uVar1 = uVar1 + uVar4;
  uVar1 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  uVar4 = uVar4 + uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4);
  uVar3 = uVar4 ^ uVar3;
  uVar2 = uVar1 + uVar4 ^ uVar2;
  uVar4 = ks->data[8] ^ uVar2;
  uVar1 = uVar3 ^ ks->data[9] ^ uVar4;
  uVar1 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4);
  uVar4 = uVar4 + uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4);
  uVar1 = uVar1 + uVar4;
  uVar1 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  uVar6 = uVar1 ^ uVar6;
  uVar7 = uVar4 + uVar1 ^ uVar7;
  uVar4 = uVar7 ^ ks->data[6];
  uVar1 = uVar6 ^ ks->data[7] ^ uVar4;
  uVar1 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4);
  uVar4 = uVar4 + uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4);
  uVar1 = uVar1 + uVar4;
  uVar1 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  uVar3 = uVar1 ^ uVar3;
  uVar2 = uVar4 + uVar1 ^ uVar2;
  uVar4 = uVar2 ^ ks->data[4];
  uVar1 = uVar3 ^ ks->data[5] ^ uVar4;
  uVar1 = *(uint *)(&SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4);
  uVar4 = uVar4 + uVar1;
  uVar4 = *(uint *)(&SS + (uVar4 & 0xff) * 4) ^ *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4);
  uVar1 = uVar1 + uVar4;
  uVar1 = *(uint *)(&SS + (uVar1 & 0xff) * 4) ^ *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  uVar6 = uVar1 ^ uVar6;
  uVar7 = uVar4 + uVar1 ^ uVar7;
  uVar1 = ks->data[2] ^ uVar7;
  uVar4 = ks->data[3] ^ uVar6 ^ uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar4 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + (((uVar4 << 8) >> 0x18) + 0x200) * 4);
  uVar1 = uVar4 + uVar1;
  uVar1 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  uVar4 = uVar4 + uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4);
  uVar3 = uVar4 ^ uVar3;
  uVar2 = uVar1 + uVar4 ^ uVar2;
  uVar4 = ks->data[0] ^ uVar2;
  uVar1 = uVar3 ^ ks->data[1] ^ uVar4;
  uVar1 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4);
  uVar4 = uVar4 + uVar1;
  uVar4 = *(uint *)(&SS + ((uVar4 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar4 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar4 * 0x100 >> 0x18) + 0x200) * 4);
  uVar1 = uVar1 + uVar4;
  uVar1 = *(uint *)(&SS + ((uVar1 >> 0x18) + 0x300) * 4) ^ *(uint *)(&SS + (uVar1 & 0xff) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4) ^
          *(uint *)(&SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4);
  uVar6 = uVar6 ^ uVar1;
  uVar7 = uVar7 ^ uVar4 + uVar1;
  d[3] = (uchar)uVar7;
  *d = (uchar)(uVar7 >> 0x18);
  d[2] = (uchar)(uVar7 >> 8);
  d[7] = (uchar)uVar6;
  d[0xb] = (uchar)uVar2;
  d[0xf] = (uchar)uVar3;
  d[1] = (uchar)(uVar7 >> 0x10);
  d[4] = (uchar)(uVar6 >> 0x18);
  d[5] = (uchar)(uVar6 >> 0x10);
  d[6] = (uchar)(uVar6 >> 8);
  d[8] = (uchar)(uVar2 >> 0x18);
  d[9] = (uchar)(uVar2 >> 0x10);
  d[10] = (uchar)(uVar2 >> 8);
  d[0xc] = (uchar)(uVar3 >> 0x18);
  d[0xd] = (uchar)(uVar3 >> 0x10);
  d[0xe] = (uchar)(uVar3 >> 8);
  return;
}

