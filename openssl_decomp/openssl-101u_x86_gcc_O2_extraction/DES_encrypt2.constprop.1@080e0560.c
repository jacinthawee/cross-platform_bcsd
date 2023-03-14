
void __regparm3 DES_encrypt2_constprop_1(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *param_1 >> 0x1d | *param_1 << 3;
  uVar3 = param_2[0x1e] ^ uVar2;
  uVar1 = (param_2[0x1f] ^ uVar2) >> 4;
  uVar3 = (param_1[1] >> 0x1d | param_1[1] << 3) ^
          *(uint *)(DES_SPtrans + ((uVar1 | (param_2[0x1f] ^ uVar2) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + (uVar3 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar3 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar3 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = param_2[0x1c] ^ uVar3;
  uVar1 = (param_2[0x1d] ^ uVar3) >> 4;
  uVar2 = uVar2 ^ *(uint *)(DES_SPtrans +
                           ((uVar1 | (param_2[0x1d] ^ uVar3) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = param_2[0x1a] ^ uVar2;
  uVar1 = (param_2[0x1b] ^ uVar2) >> 4;
  uVar3 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar1 | (param_2[0x1b] ^ uVar2) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar3 ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = param_2[0x18] ^ uVar3;
  uVar1 = (param_2[0x19] ^ uVar3) >> 4;
  uVar2 = uVar2 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar1 | (param_2[0x19] ^ uVar3) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = param_2[0x16] ^ uVar2;
  uVar1 = (param_2[0x17] ^ uVar2) >> 4;
  uVar3 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar1 | (param_2[0x17] ^ uVar2) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar3 ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = param_2[0x14] ^ uVar3;
  uVar1 = (param_2[0x15] ^ uVar3) >> 4;
  uVar2 = uVar2 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar1 | (param_2[0x15] ^ uVar3) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = param_2[0x12] ^ uVar2;
  uVar1 = (param_2[0x13] ^ uVar2) >> 4;
  uVar3 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar1 | (param_2[0x13] ^ uVar2) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar3 ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = param_2[0x10] ^ uVar3;
  uVar1 = (param_2[0x11] ^ uVar3) >> 4;
  uVar2 = uVar2 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar1 | (param_2[0x11] ^ uVar3) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = param_2[0xe] ^ uVar2;
  uVar1 = (param_2[0xf] ^ uVar2) >> 4;
  uVar3 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar1 | (param_2[0xf] ^ uVar2) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar3 ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = param_2[0xc] ^ uVar3;
  uVar1 = (param_2[0xd] ^ uVar3) >> 4;
  uVar2 = uVar2 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar1 | (param_2[0xd] ^ uVar3) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = param_2[10] ^ uVar2;
  uVar1 = (param_2[0xb] ^ uVar2) >> 4;
  uVar3 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar1 | (param_2[0xb] ^ uVar2) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar3 ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = param_2[8] ^ uVar3;
  uVar1 = (param_2[9] ^ uVar3) >> 4;
  uVar2 = uVar2 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar1 | (param_2[9] ^ uVar3) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = param_2[6] ^ uVar2;
  uVar1 = (param_2[7] ^ uVar2) >> 4;
  uVar3 = uVar3 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar1 | (param_2[7] ^ uVar2) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = param_2[4] ^ uVar3;
  uVar1 = (param_2[5] ^ uVar3) >> 4;
  uVar2 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
          *(uint *)(DES_SPtrans + ((uVar1 | (param_2[5] ^ uVar3) << 0x1c) >> 0x1a) * 4 + 0x700) ^
          *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar2 ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = param_2[2] ^ uVar2;
  uVar1 = (param_2[3] ^ uVar2) >> 4;
  uVar3 = uVar3 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar1 | (param_2[3] ^ uVar2) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  uVar4 = *param_2 ^ uVar3;
  uVar1 = (param_2[1] ^ uVar3) >> 4;
  uVar1 = uVar2 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans +
                           ((uVar1 | (param_2[1] ^ uVar3) << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
  *param_1 = uVar3 >> 3 | uVar3 << 0x1d;
  param_1[1] = uVar1 >> 3 | uVar1 << 0x1d;
  return;
}
