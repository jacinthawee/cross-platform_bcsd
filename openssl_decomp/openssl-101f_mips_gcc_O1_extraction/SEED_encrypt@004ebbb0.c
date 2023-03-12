
void SEED_encrypt(uchar *s,uchar *d,SEED_KEY_SCHEDULE *ks)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint in_t2;
  uint uVar4;
  uint uVar5;
  uint in_t5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint unaff_s6;
  uint uVar9;
  
  uVar1 = (uint)(s + 0xc) & 3;
  uVar3 = (uint)s & 3;
  uVar4 = (uint)(s + 4) & 3;
  uVar9 = (uint)(s + 0xf) & 3;
  uVar5 = (*(int *)(s + 0xc + -uVar1) << uVar1 * 8 | unaff_s6 & 0xffffffffU >> (4 - uVar1) * 8) &
          -1 << (uVar9 + 1) * 8 | *(uint *)(s + 0xf + -uVar9) >> (3 - uVar9) * 8;
  uVar1 = (uint)(s + 3) & 3;
  uVar7 = *(uint *)(s + 8) ^ ks->data[0];
  uVar9 = (uint)(s + 7) & 3;
  uVar2 = uVar7 ^ uVar5 ^ ks->data[1];
  uVar2 = *(uint *)(SS + (((uVar2 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + ((uVar2 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + (((uVar2 << 0x10) >> 0x18) + 0x100) * 4);
  uVar7 = uVar7 + uVar2;
  uVar7 = *(uint *)(SS + ((uVar7 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar7 & 0xff) * 4) ^ *(uint *)(SS + ((uVar7 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar7 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar2 = uVar2 + uVar7;
  uVar2 = *(uint *)(SS + ((uVar2 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar2 & 0xff) * 4) ^ *(uint *)(SS + ((uVar2 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar2 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar4 = ((*(int *)(s + 4 + -uVar4) << uVar4 * 8 | in_t2 & 0xffffffffU >> (4 - uVar4) * 8) &
           -1 << (uVar9 + 1) * 8 | *(uint *)(s + 7 + -uVar9) >> (3 - uVar9) * 8) ^ uVar2;
  uVar6 = uVar7 + uVar2 ^
          ((*(int *)(s + -uVar3) << uVar3 * 8 | in_t5 & 0xffffffffU >> (4 - uVar3) * 8) &
           -1 << (uVar1 + 1) * 8 | *(uint *)(s + 3 + -uVar1) >> (3 - uVar1) * 8);
  uVar3 = uVar6 ^ ks->data[2];
  uVar1 = uVar3 ^ uVar4 ^ ks->data[3];
  uVar1 = *(uint *)(SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 + uVar1;
  uVar3 = *(uint *)(SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = uVar1 + uVar3;
  uVar1 = *(uint *)(SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar5 = uVar5 ^ uVar1;
  uVar7 = uVar3 + uVar1 ^ *(uint *)(s + 8);
  uVar3 = uVar7 ^ ks->data[4];
  uVar1 = uVar3 ^ uVar5 ^ ks->data[5];
  uVar1 = *(uint *)(SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 + uVar1;
  uVar3 = *(uint *)(SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = uVar1 + uVar3;
  uVar1 = *(uint *)(SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar4 = uVar4 ^ uVar1;
  uVar6 = uVar3 + uVar1 ^ uVar6;
  uVar3 = uVar6 ^ ks->data[6];
  uVar1 = uVar3 ^ uVar4 ^ ks->data[7];
  uVar1 = *(uint *)(SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 + uVar1;
  uVar3 = *(uint *)(SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = uVar1 + uVar3;
  uVar1 = *(uint *)(SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar5 = uVar5 ^ uVar1;
  uVar7 = uVar3 + uVar1 ^ uVar7;
  uVar3 = uVar7 ^ ks->data[8];
  uVar1 = uVar3 ^ uVar5 ^ ks->data[9];
  uVar1 = *(uint *)(SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 + uVar1;
  uVar3 = *(uint *)(SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = uVar1 + uVar3;
  uVar1 = *(uint *)(SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar4 = uVar4 ^ uVar1;
  uVar6 = uVar3 + uVar1 ^ uVar6;
  uVar1 = uVar6 ^ ks->data[10];
  uVar3 = uVar1 ^ uVar4 ^ ks->data[0xb];
  uVar3 = *(uint *)(SS + (((uVar3 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + (((uVar3 << 0x10) >> 0x18) + 0x100) * 4);
  uVar1 = uVar1 + uVar3;
  uVar9 = *(uint *)(SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 + uVar9;
  uVar1 = *(uint *)(SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar5 = uVar5 ^ uVar1;
  uVar7 = uVar9 + uVar1 ^ uVar7;
  uVar3 = uVar7 ^ ks->data[0xc];
  uVar1 = uVar3 ^ uVar5 ^ ks->data[0xd];
  uVar1 = *(uint *)(SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 + uVar1;
  uVar3 = *(uint *)(SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = uVar1 + uVar3;
  uVar1 = *(uint *)(SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar4 = uVar4 ^ uVar1;
  uVar6 = uVar3 + uVar1 ^ uVar6;
  uVar3 = uVar6 ^ ks->data[0xe];
  uVar1 = uVar3 ^ uVar4 ^ ks->data[0xf];
  uVar1 = *(uint *)(SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 + uVar1;
  uVar3 = *(uint *)(SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = uVar1 + uVar3;
  uVar1 = *(uint *)(SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar5 = uVar5 ^ uVar1;
  uVar7 = uVar3 + uVar1 ^ uVar7;
  uVar3 = uVar7 ^ ks->data[0x10];
  uVar1 = uVar3 ^ uVar5 ^ ks->data[0x11];
  uVar1 = *(uint *)(SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 + uVar1;
  uVar3 = *(uint *)(SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = uVar1 + uVar3;
  uVar1 = *(uint *)(SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar4 = uVar4 ^ uVar1;
  uVar6 = uVar3 + uVar1 ^ uVar6;
  uVar3 = uVar6 ^ ks->data[0x12];
  uVar1 = uVar3 ^ uVar4 ^ ks->data[0x13];
  uVar1 = *(uint *)(SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 + uVar1;
  uVar3 = *(uint *)(SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = uVar1 + uVar3;
  uVar1 = *(uint *)(SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar5 = uVar5 ^ uVar1;
  uVar7 = uVar3 + uVar1 ^ uVar7;
  uVar3 = uVar7 ^ ks->data[0x14];
  uVar1 = uVar3 ^ uVar5 ^ ks->data[0x15];
  uVar1 = *(uint *)(SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 + uVar1;
  uVar3 = *(uint *)(SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = uVar1 + uVar3;
  uVar1 = *(uint *)(SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar4 = uVar4 ^ uVar1;
  uVar6 = uVar3 + uVar1 ^ uVar6;
  uVar3 = uVar6 ^ ks->data[0x16];
  uVar1 = uVar3 ^ uVar4 ^ ks->data[0x17];
  uVar1 = *(uint *)(SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 + uVar1;
  uVar3 = *(uint *)(SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = uVar1 + uVar3;
  uVar1 = *(uint *)(SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar5 = uVar5 ^ uVar1;
  uVar7 = uVar3 + uVar1 ^ uVar7;
  uVar3 = uVar7 ^ ks->data[0x18];
  uVar1 = uVar3 ^ uVar5 ^ ks->data[0x19];
  uVar1 = *(uint *)(SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 + uVar1;
  uVar3 = *(uint *)(SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = uVar1 + uVar3;
  uVar1 = *(uint *)(SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar4 = uVar4 ^ uVar1;
  uVar6 = uVar3 + uVar1 ^ uVar6;
  uVar3 = uVar6 ^ ks->data[0x1a];
  uVar1 = uVar3 ^ uVar4 ^ ks->data[0x1b];
  uVar1 = *(uint *)(SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 + uVar1;
  uVar3 = *(uint *)(SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar1 = uVar1 + uVar3;
  uVar1 = *(uint *)(SS + ((uVar1 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar1 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar5 = uVar5 ^ uVar1;
  uVar7 = uVar3 + uVar1 ^ uVar7;
  uVar9 = uVar7 ^ ks->data[0x1c];
  uVar1 = uVar9 ^ uVar5 ^ ks->data[0x1d];
  uVar3 = *(uint *)(SS + (((uVar1 << 8) >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar1 & 0xff) * 4) ^ *(uint *)(SS + ((uVar1 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + (((uVar1 << 0x10) >> 0x18) + 0x100) * 4);
  uVar9 = uVar9 + uVar3;
  uVar9 = *(uint *)(SS + ((uVar9 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar9 & 0xff) * 4) ^ *(uint *)(SS + ((uVar9 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar9 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar3 = uVar3 + uVar9;
  uVar1 = ks->data[0x1f];
  uVar3 = *(uint *)(SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar4 = uVar4 ^ uVar3;
  uVar6 = uVar9 + uVar3 ^ uVar6;
  uVar2 = uVar6 ^ ks->data[0x1e];
  d[0xf] = (uchar)uVar4;
  d[0xb] = (uchar)uVar6;
  uVar3 = uVar2 ^ uVar4 ^ uVar1;
  uVar8 = *(uint *)(SS + (uVar3 & 0xff) * 4);
  uVar1 = *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4);
  uVar9 = *(uint *)(SS + (((uVar3 << 0x10) >> 0x18) + 0x100) * 4);
  uVar3 = *(uint *)(SS + (((uVar3 << 8) >> 0x18) + 0x200) * 4);
  d[8] = (uchar)(uVar6 >> 0x18);
  d[9] = (uchar)(uVar6 >> 0x10);
  uVar3 = uVar3 ^ uVar8 ^ uVar1 ^ uVar9;
  uVar2 = uVar2 + uVar3;
  d[10] = (uchar)(uVar6 >> 8);
  d[0xc] = (uchar)(uVar4 >> 0x18);
  uVar6 = *(uint *)(SS + (uVar2 & 0xff) * 4);
  uVar8 = *(uint *)(SS + ((uVar2 >> 0x18) + 0x300) * 4);
  uVar1 = *(uint *)(SS + ((uVar2 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar9 = *(uint *)(SS + ((uVar2 * 0x100 >> 0x18) + 0x200) * 4);
  d[0xd] = (uchar)(uVar4 >> 0x10);
  d[0xe] = (uchar)(uVar4 >> 8);
  uVar9 = uVar9 ^ uVar6 ^ uVar8 ^ uVar1;
  uVar3 = uVar3 + uVar9;
  uVar1 = *(uint *)(SS + ((uVar3 * 0x100 >> 0x18) + 0x200) * 4) ^
          *(uint *)(SS + (uVar3 & 0xff) * 4) ^ *(uint *)(SS + ((uVar3 >> 0x18) + 0x300) * 4) ^
          *(uint *)(SS + ((uVar3 * 0x10000 >> 0x18) + 0x100) * 4);
  uVar5 = uVar5 ^ uVar1;
  uVar7 = uVar9 + uVar1 ^ uVar7;
  d[7] = (uchar)uVar5;
  d[3] = (uchar)uVar7;
  *d = (uchar)(uVar7 >> 0x18);
  d[1] = (uchar)(uVar7 >> 0x10);
  d[2] = (uchar)(uVar7 >> 8);
  d[4] = (uchar)(uVar5 >> 0x18);
  d[5] = (uchar)(uVar5 >> 0x10);
  d[6] = (uchar)(uVar5 >> 8);
  return;
}

