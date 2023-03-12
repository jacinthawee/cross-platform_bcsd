
void SEED_decrypt(uchar *s,uchar *d,SEED_KEY_SCHEDULE *ks)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = *(uint *)(s + 4);
  uVar2 = *(uint *)(s + 8);
  uVar7 = *(uint *)s;
  uVar1 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  uVar2 = *(uint *)(s + 0xc);
  uVar5 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  uVar6 = ks->data[0x1e] ^ uVar1;
  uVar2 = ks->data[0x1f] ^ uVar5 ^ uVar6;
  uVar4 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar6 = uVar6 + uVar4;
  uVar2 = *(uint *)(SS + (uVar6 & 0xff) * 4) ^ *(uint *)(SS + (uVar6 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar6 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar6 >> 0x10 & 0xff) * 4 + 0x800);
  uVar4 = uVar4 + uVar2;
  uVar4 = *(uint *)(SS + (uVar4 & 0xff) * 4) ^ *(uint *)(SS + (uVar4 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar4 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar4 >> 0x10 & 0xff) * 4 + 0x800);
  uVar6 = uVar2 + uVar4 ^
          (uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18);
  uVar4 = (uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18) ^ uVar4;
  uVar7 = ks->data[0x1c] ^ uVar6;
  uVar3 = uVar4 ^ ks->data[0x1d] ^ uVar7;
  uVar2 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar7 = uVar7 + uVar2;
  uVar3 = *(uint *)(SS + (uVar7 & 0xff) * 4) ^ *(uint *)(SS + (uVar7 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar7 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar7 >> 0x10 & 0xff) * 4 + 0x800);
  uVar2 = uVar2 + uVar3;
  uVar2 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar5 = uVar2 ^ uVar5;
  uVar1 = uVar1 ^ uVar3 + uVar2;
  uVar3 = ks->data[0x1a] ^ uVar1;
  uVar2 = uVar5 ^ ks->data[0x1b] ^ uVar3;
  uVar2 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar3 = uVar3 + uVar2;
  uVar7 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar2 = uVar2 + uVar7;
  uVar3 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar4 = uVar4 ^ uVar3;
  uVar6 = uVar6 ^ uVar7 + uVar3;
  uVar7 = ks->data[0x18] ^ uVar6;
  uVar3 = uVar4 ^ ks->data[0x19] ^ uVar7;
  uVar2 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar7 = uVar7 + uVar2;
  uVar3 = *(uint *)(SS + (uVar7 & 0xff) * 4) ^ *(uint *)(SS + (uVar7 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar7 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar7 >> 0x10 & 0xff) * 4 + 0x800);
  uVar2 = uVar2 + uVar3;
  uVar2 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar1 = uVar3 + uVar2 ^ uVar1;
  uVar5 = uVar5 ^ uVar2;
  uVar3 = uVar1 ^ ks->data[0x16];
  uVar2 = ks->data[0x17] ^ uVar5 ^ uVar3;
  uVar2 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar3 = uVar3 + uVar2;
  uVar7 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar2 = uVar2 + uVar7;
  uVar3 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar4 = uVar3 ^ uVar4;
  uVar6 = uVar6 ^ uVar7 + uVar3;
  uVar7 = ks->data[0x14] ^ uVar6;
  uVar3 = uVar4 ^ ks->data[0x15] ^ uVar7;
  uVar2 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar7 = uVar7 + uVar2;
  uVar3 = *(uint *)(SS + (uVar7 & 0xff) * 4) ^ *(uint *)(SS + (uVar7 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar7 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar7 >> 0x10 & 0xff) * 4 + 0x800);
  uVar2 = uVar2 + uVar3;
  uVar2 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar1 = uVar3 + uVar2 ^ uVar1;
  uVar5 = uVar5 ^ uVar2;
  uVar7 = ks->data[0x12] ^ uVar1;
  uVar3 = ks->data[0x13] ^ uVar5 ^ uVar7;
  uVar2 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar7 = uVar7 + uVar2;
  uVar3 = *(uint *)(SS + (uVar7 & 0xff) * 4) ^ *(uint *)(SS + (uVar7 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar7 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar7 >> 0x10 & 0xff) * 4 + 0x800);
  uVar2 = uVar2 + uVar3;
  uVar2 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar6 = uVar6 ^ uVar3 + uVar2;
  uVar4 = uVar4 ^ uVar2;
  uVar2 = ks->data[0x10] ^ uVar6;
  uVar3 = uVar4 ^ ks->data[0x11] ^ uVar2;
  uVar7 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar2 = uVar2 + uVar7;
  uVar3 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar7 = uVar7 + uVar3;
  uVar2 = *(uint *)(SS + (uVar7 & 0xff) * 4) ^ *(uint *)(SS + (uVar7 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar7 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar7 >> 0x10 & 0xff) * 4 + 0x800);
  uVar5 = uVar2 ^ uVar5;
  uVar1 = uVar1 ^ uVar3 + uVar2;
  uVar7 = ks->data[0xe] ^ uVar1;
  uVar3 = uVar5 ^ ks->data[0xf] ^ uVar7;
  uVar2 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar7 = uVar7 + uVar2;
  uVar3 = *(uint *)(SS + (uVar7 & 0xff) * 4) ^ *(uint *)(SS + (uVar7 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar7 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar7 >> 0x10 & 0xff) * 4 + 0x800);
  uVar2 = uVar2 + uVar3;
  uVar2 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar4 = uVar4 ^ uVar2;
  uVar6 = uVar6 ^ uVar3 + uVar2;
  uVar7 = ks->data[0xc] ^ uVar6;
  uVar3 = ks->data[0xd] ^ uVar4 ^ uVar7;
  uVar2 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar7 = uVar7 + uVar2;
  uVar3 = *(uint *)(SS + (uVar7 & 0xff) * 4) ^ *(uint *)(SS + (uVar7 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar7 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar7 >> 0x10 & 0xff) * 4 + 0x800);
  uVar2 = uVar2 + uVar3;
  uVar2 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar5 = uVar2 ^ uVar5;
  uVar1 = uVar1 ^ uVar3 + uVar2;
  uVar2 = uVar1 ^ ks->data[10];
  uVar3 = uVar5 ^ ks->data[0xb] ^ uVar2;
  uVar7 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar2 = uVar2 + uVar7;
  uVar3 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar7 = uVar7 + uVar3;
  uVar2 = *(uint *)(SS + (uVar7 & 0xff) * 4) ^ *(uint *)(SS + (uVar7 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar7 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar7 >> 0x10 & 0xff) * 4 + 0x800);
  uVar4 = uVar2 ^ uVar4;
  uVar6 = uVar6 ^ uVar3 + uVar2;
  uVar2 = ks->data[8] ^ uVar6;
  uVar3 = uVar4 ^ ks->data[9] ^ uVar2;
  uVar3 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar2 = uVar2 + uVar3;
  uVar2 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar3 = uVar3 + uVar2;
  uVar3 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar5 = uVar3 ^ uVar5;
  uVar1 = uVar2 + uVar3 ^ uVar1;
  uVar3 = ks->data[6] ^ uVar1;
  uVar2 = uVar5 ^ ks->data[7] ^ uVar3;
  uVar2 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar3 = uVar3 + uVar2;
  uVar3 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar2 = uVar2 + uVar3;
  uVar2 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar4 = uVar4 ^ uVar2;
  uVar6 = uVar6 ^ uVar3 + uVar2;
  uVar3 = ks->data[4] ^ uVar6;
  uVar2 = uVar4 ^ ks->data[5] ^ uVar3;
  uVar2 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar3 = uVar3 + uVar2;
  uVar3 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar2 = uVar2 + uVar3;
  uVar2 = *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + (uVar2 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar2 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar2 >> 0x10 & 0xff) * 4 + 0x800);
  uVar1 = uVar1 ^ uVar3 + uVar2;
  uVar2 = uVar2 ^ uVar5;
  uVar7 = ks->data[2] ^ uVar1;
  uVar3 = ks->data[3] ^ uVar2 ^ uVar7;
  uVar3 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar7 = uVar7 + uVar3;
  uVar7 = *(uint *)(SS + (uVar7 & 0xff) * 4) ^ *(uint *)(SS + (uVar7 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar7 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar7 >> 0x10 & 0xff) * 4 + 0x800);
  uVar3 = uVar3 + uVar7;
  uVar3 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar4 = uVar3 ^ uVar4;
  uVar6 = uVar7 + uVar3 ^ uVar6;
  uVar7 = ks->data[0] ^ uVar6;
  uVar3 = ks->data[1] ^ uVar4 ^ uVar7;
  uVar5 = *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + (uVar3 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar3 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar3 >> 0x10 & 0xff) * 4 + 0x800);
  uVar7 = uVar7 + uVar5;
  uVar3 = *(uint *)(SS + (uVar7 & 0xff) * 4) ^ *(uint *)(SS + (uVar7 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar7 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar7 >> 0x10 & 0xff) * 4 + 0x800);
  uVar5 = uVar5 + uVar3;
  uVar7 = *(uint *)(SS + (uVar5 & 0xff) * 4) ^ *(uint *)(SS + (uVar5 >> 0x18) * 4 + 0xc00) ^
          *(uint *)(SS + (uVar5 >> 8 & 0xff) * 4 + 0x400) ^
          *(uint *)(SS + (uVar5 >> 0x10 & 0xff) * 4 + 0x800);
  uVar1 = uVar3 + uVar7 ^ uVar1;
  uVar7 = uVar7 ^ uVar2;
  d[3] = (uchar)uVar1;
  *d = (uchar)(uVar1 >> 0x18);
  d[1] = (uchar)(uVar1 >> 0x10);
  d[4] = (uchar)(uVar7 >> 0x18);
  d[2] = (uchar)(uVar1 >> 8);
  d[5] = (uchar)(uVar7 >> 0x10);
  d[7] = (uchar)uVar7;
  d[0xb] = (uchar)uVar6;
  d[6] = (uchar)(uVar7 >> 8);
  d[8] = (uchar)(uVar6 >> 0x18);
  d[9] = (uchar)(uVar6 >> 0x10);
  d[10] = (uchar)(uVar6 >> 8);
  d[0xc] = (uchar)(uVar4 >> 0x18);
  d[0xd] = (uchar)(uVar4 >> 0x10);
  d[0xe] = (uchar)(uVar4 >> 8);
  d[0xf] = (uchar)uVar4;
  return;
}

