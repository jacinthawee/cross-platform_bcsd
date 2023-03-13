
void __regparm3 DES_encrypt1_constprop_3(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = (param_1[1] >> 4 ^ *param_1) & 0xf0f0f0f;
  uVar5 = *param_1 ^ uVar2;
  uVar3 = uVar2 << 4 ^ param_1[1];
  uVar2 = (uVar5 >> 0x10 ^ uVar3) & 0xffff;
  uVar3 = uVar3 ^ uVar2;
  uVar5 = uVar2 << 0x10 ^ uVar5;
  uVar2 = (uVar3 >> 2 ^ uVar5) & 0x33333333;
  uVar5 = uVar5 ^ uVar2;
  uVar3 = uVar2 << 2 ^ uVar3;
  uVar2 = (uVar5 >> 8 ^ uVar3) & 0xff00ff;
  uVar3 = uVar3 ^ uVar2;
  uVar5 = uVar2 << 8 ^ uVar5;
  uVar2 = (uVar3 >> 1 ^ uVar5) & 0x55555555;
  uVar5 = uVar5 ^ uVar2;
  uVar3 = uVar2 * 2 ^ uVar3;
  uVar1 = uVar5 >> 0x1d | uVar5 << 3;
  uVar5 = param_2[0x1e] ^ uVar1;
  uVar2 = (param_2[0x1f] ^ uVar1) >> 4;
  uVar5 = *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
          (uVar3 >> 0x1d | uVar3 << 3) ^
          *(uint *)(DES_SPtrans + ((uVar2 | (param_2[0x1f] ^ uVar1) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar3 = param_2[0x1c] ^ uVar5;
  uVar2 = (param_2[0x1d] ^ uVar5) >> 4;
  uVar3 = uVar1 ^ *(uint *)(DES_SPtrans +
                           ((uVar2 | (param_2[0x1d] ^ uVar5) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar3 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar3 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar3 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar1 = param_2[0x1a] ^ uVar3;
  uVar2 = (param_2[0x1b] ^ uVar3) >> 4;
  uVar5 = *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar2 | (param_2[0x1b] ^ uVar3) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar5 ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar1 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar1 = param_2[0x18] ^ uVar5;
  uVar2 = (param_2[0x19] ^ uVar5) >> 4;
  uVar3 = uVar3 ^ *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar2 | (param_2[0x19] ^ uVar5) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar1 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar1 = param_2[0x16] ^ uVar3;
  uVar2 = (param_2[0x17] ^ uVar3) >> 4;
  uVar5 = *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar2 | (param_2[0x17] ^ uVar3) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar5 ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar1 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar1 = param_2[0x14] ^ uVar5;
  uVar2 = (param_2[0x15] ^ uVar5) >> 4;
  uVar3 = uVar3 ^ *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar2 | (param_2[0x15] ^ uVar5) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar1 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar1 = param_2[0x12] ^ uVar3;
  uVar2 = (param_2[0x13] ^ uVar3) >> 4;
  uVar5 = *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar2 | (param_2[0x13] ^ uVar3) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar5 ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar1 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar1 = param_2[0x10] ^ uVar5;
  uVar2 = (param_2[0x11] ^ uVar5) >> 4;
  uVar3 = uVar3 ^ *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar2 | (param_2[0x11] ^ uVar5) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar1 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar1 = param_2[0xe] ^ uVar3;
  uVar2 = (param_2[0xf] ^ uVar3) >> 4;
  uVar5 = *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar2 | (param_2[0xf] ^ uVar3) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar5 ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar1 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar1 = param_2[0xc] ^ uVar5;
  uVar2 = (param_2[0xd] ^ uVar5) >> 4;
  uVar3 = uVar3 ^ *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar2 | (param_2[0xd] ^ uVar5) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar1 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar1 = param_2[10] ^ uVar3;
  uVar2 = (param_2[0xb] ^ uVar3) >> 4;
  uVar5 = *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar2 | (param_2[0xb] ^ uVar3) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar5 ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar1 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar1 = param_2[8] ^ uVar5;
  uVar2 = (param_2[9] ^ uVar5) >> 4;
  uVar3 = uVar3 ^ *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar2 | (param_2[9] ^ uVar5) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar1 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar1 = param_2[6] ^ uVar3;
  uVar2 = (param_2[7] ^ uVar3) >> 4;
  uVar5 = uVar5 ^ *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar2 | (param_2[7] ^ uVar3) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar1 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar1 = param_2[4] ^ uVar5;
  uVar2 = (param_2[5] ^ uVar5) >> 4;
  uVar1 = *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar2 | (param_2[5] ^ uVar5) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar3 ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar1 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar3 = param_2[2] ^ uVar1;
  uVar2 = (param_2[3] ^ uVar1) >> 4;
  uVar5 = uVar5 ^ *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar2 | (param_2[3] ^ uVar1) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar3 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar3 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar3 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = *param_2 ^ uVar5;
  uVar2 = (param_2[1] ^ uVar5) >> 4;
  uVar3 = uVar5 >> 3 | uVar5 << 0x1d;
  uVar2 = uVar1 ^ *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar2 | (param_2[1] ^ uVar5) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar2 = uVar2 >> 3 | uVar2 << 0x1d;
  uVar5 = (uVar2 >> 1 ^ uVar3) & 0x55555555;
  uVar3 = uVar3 ^ uVar5;
  uVar2 = uVar2 ^ uVar5 * 2;
  uVar5 = (uVar3 >> 8 ^ uVar2) & 0xff00ff;
  uVar2 = uVar2 ^ uVar5;
  uVar3 = uVar3 ^ uVar5 << 8;
  uVar5 = (uVar2 >> 2 ^ uVar3) & 0x33333333;
  uVar3 = uVar3 ^ uVar5;
  uVar2 = uVar2 ^ uVar5 << 2;
  uVar5 = (uVar3 >> 0x10 ^ uVar2) & 0xffff;
  uVar2 = uVar2 ^ uVar5;
  uVar3 = uVar3 ^ uVar5 << 0x10;
  uVar5 = (uVar2 >> 4 ^ uVar3) & 0xf0f0f0f;
  *param_1 = uVar3 ^ uVar5;
  param_1[1] = uVar5 << 4 ^ uVar2;
  return;
}

