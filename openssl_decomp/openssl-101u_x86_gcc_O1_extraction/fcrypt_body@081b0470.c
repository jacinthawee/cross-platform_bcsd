
void fcrypt_body(uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int local_94;
  
  local_94 = 0x19;
  uVar2 = 0;
  uVar1 = 0;
  do {
    uVar4 = uVar2 >> 0x10 ^ uVar2;
    uVar6 = param_3 & uVar4;
    uVar4 = uVar4 & param_4;
    uVar3 = *param_2 ^ uVar2 ^ uVar6 ^ uVar6 << 0x10;
    uVar6 = param_2[1] ^ uVar2 ^ uVar4;
    uVar4 = (uVar6 ^ uVar4 << 0x10) >> 4;
    uVar1 = *(uint *)(DES_SPtrans + (uVar4 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar4 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar4 | uVar6 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar4 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar3 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar3 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar3 >> 0x12 & 0x3f) * 4 + 0x400) ^ uVar1;
    uVar4 = uVar1 >> 0x10 ^ uVar1;
    uVar6 = param_3 & uVar4;
    uVar4 = uVar4 & param_4;
    uVar3 = param_2[2] ^ uVar1 ^ uVar6 ^ uVar6 << 0x10;
    uVar6 = param_2[3] ^ uVar1 ^ uVar4;
    uVar4 = (uVar6 ^ uVar4 << 0x10) >> 4;
    uVar5 = uVar2 ^ *(uint *)(DES_SPtrans + ((uVar4 | uVar6 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar4 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar4 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar3 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar3 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar3 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar3 = uVar5 >> 0x10 ^ uVar5;
    uVar2 = param_3 & uVar3;
    uVar3 = uVar3 & param_4;
    uVar6 = param_2[4] ^ uVar5 ^ uVar2 ^ uVar2 << 0x10;
    uVar4 = param_2[5] ^ uVar5 ^ uVar3;
    uVar2 = (uVar4 ^ uVar3 << 0x10) >> 4;
    uVar7 = uVar1 ^ *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar2 | uVar4 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar6 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar6 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar6 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar6 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar1 = uVar7 >> 0x10 ^ uVar7;
    uVar2 = param_3 & uVar1;
    uVar1 = uVar1 & param_4;
    uVar4 = param_2[6] ^ uVar7 ^ uVar2 ^ uVar2 << 0x10;
    uVar2 = param_2[7] ^ uVar7 ^ uVar1;
    uVar1 = (uVar2 ^ uVar1 << 0x10) >> 4;
    uVar4 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar5 ^
            *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar3 = uVar4 >> 0x10 ^ uVar4;
    uVar1 = param_3 & uVar3;
    uVar3 = uVar3 & param_4;
    uVar6 = param_2[8] ^ uVar4 ^ uVar1 ^ uVar1 << 0x10;
    uVar2 = param_2[9] ^ uVar4 ^ uVar3;
    uVar1 = (uVar2 ^ uVar3 << 0x10) >> 4;
    uVar6 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar7 ^
            *(uint *)(DES_SPtrans + (uVar6 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar6 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar6 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar6 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar5 = uVar6 >> 0x10 ^ uVar6;
    uVar1 = param_3 & uVar5;
    uVar5 = uVar5 & param_4;
    uVar3 = param_2[10] ^ uVar6 ^ uVar1 ^ uVar1 << 0x10;
    uVar2 = param_2[0xb] ^ uVar6 ^ uVar5;
    uVar1 = (uVar2 ^ uVar5 << 0x10) >> 4;
    uVar5 = *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^ uVar4 ^
            *(uint *)(DES_SPtrans + (uVar3 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar3 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar3 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar3 = uVar5 >> 0x10 ^ uVar5;
    uVar1 = param_3 & uVar3;
    uVar3 = uVar3 & param_4;
    uVar4 = param_2[0xc] ^ uVar5 ^ uVar1 ^ uVar1 << 0x10;
    uVar2 = param_2[0xd] ^ uVar5 ^ uVar3;
    uVar1 = (uVar2 ^ uVar3 << 0x10) >> 4;
    uVar3 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar6 ^
            *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar1 = uVar3 >> 0x10 ^ uVar3;
    uVar2 = param_3 & uVar1;
    uVar1 = uVar1 & param_4;
    uVar4 = param_2[0xe] ^ uVar3 ^ uVar2 ^ uVar2 << 0x10;
    uVar2 = param_2[0xf] ^ uVar3 ^ uVar1;
    uVar1 = (uVar2 ^ uVar1 << 0x10) >> 4;
    uVar4 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar5 ^
            *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar6 = uVar4 >> 0x10 ^ uVar4;
    uVar1 = param_3 & uVar6;
    uVar6 = uVar6 & param_4;
    uVar5 = param_2[0x10] ^ uVar4 ^ uVar1 ^ uVar1 << 0x10;
    uVar2 = param_2[0x11] ^ uVar4 ^ uVar6;
    uVar1 = (uVar2 ^ uVar6 << 0x10) >> 4;
    uVar6 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar3 ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar5 = uVar6 >> 0x10 ^ uVar6;
    uVar1 = param_3 & uVar5;
    uVar5 = uVar5 & param_4;
    uVar3 = param_2[0x12] ^ uVar6 ^ uVar1 ^ uVar1 << 0x10;
    uVar2 = param_2[0x13] ^ uVar6 ^ uVar5;
    uVar1 = (uVar2 ^ uVar5 << 0x10) >> 4;
    uVar5 = *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^ uVar4 ^
            *(uint *)(DES_SPtrans + (uVar3 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar3 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar3 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar3 = uVar5 >> 0x10 ^ uVar5;
    uVar1 = param_3 & uVar3;
    uVar3 = uVar3 & param_4;
    uVar4 = param_2[0x14] ^ uVar5 ^ uVar1 ^ uVar1 << 0x10;
    uVar2 = param_2[0x15] ^ uVar5 ^ uVar3;
    uVar1 = (uVar2 ^ uVar3 << 0x10) >> 4;
    uVar3 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar6 ^
            *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar1 = uVar3 >> 0x10 ^ uVar3;
    uVar2 = param_3 & uVar1;
    uVar1 = uVar1 & param_4;
    uVar4 = param_2[0x16] ^ uVar3 ^ uVar2 ^ uVar2 << 0x10;
    uVar2 = param_2[0x17] ^ uVar3 ^ uVar1;
    uVar1 = (uVar2 ^ uVar1 << 0x10) >> 4;
    uVar4 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar5 ^
            *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar6 = uVar4 >> 0x10 ^ uVar4;
    uVar1 = param_3 & uVar6;
    uVar6 = uVar6 & param_4;
    uVar5 = param_2[0x18] ^ uVar4 ^ uVar1 ^ uVar1 << 0x10;
    uVar2 = param_2[0x19] ^ uVar4 ^ uVar6;
    uVar1 = (uVar2 ^ uVar6 << 0x10) >> 4;
    uVar6 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar3 ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar1 = uVar6 >> 0x10 ^ uVar6;
    uVar2 = param_3 & uVar1;
    uVar1 = uVar1 & param_4;
    uVar3 = param_2[0x1a] ^ uVar6 ^ uVar2 ^ uVar2 << 0x10;
    uVar2 = param_2[0x1b] ^ uVar6 ^ uVar1;
    uVar1 = (uVar2 ^ uVar1 << 0x10) >> 4;
    uVar3 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar4 ^
            *(uint *)(DES_SPtrans + (uVar3 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar3 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar3 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar5 = uVar3 >> 0x10 ^ uVar3;
    uVar1 = param_3 & uVar5;
    uVar5 = uVar5 & param_4;
    uVar4 = param_2[0x1c] ^ uVar3 ^ uVar1 ^ uVar1 << 0x10;
    uVar2 = param_2[0x1d] ^ uVar3 ^ uVar5;
    uVar1 = (uVar2 ^ uVar5 << 0x10) >> 4;
    uVar2 = uVar6 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar5 = uVar2 >> 0x10 ^ uVar2;
    uVar1 = param_3 & uVar5;
    uVar5 = uVar5 & param_4;
    uVar6 = param_2[0x1e] ^ uVar2 ^ uVar1 ^ uVar1 << 0x10;
    uVar4 = param_2[0x1f] ^ uVar2 ^ uVar5;
    uVar1 = (uVar4 ^ uVar5 << 0x10) >> 4;
    uVar1 = *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar4 << 0x1c) >> 0x1a) * 4 + 0x700) ^ uVar3 ^
            *(uint *)(DES_SPtrans + (uVar6 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar6 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar6 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar6 >> 0x12 & 0x3f) * 4 + 0x400);
    local_94 = local_94 + -1;
  } while (local_94 != 0);
  uVar1 = uVar1 >> 3 | uVar1 << 0x1d;
  uVar4 = uVar2 >> 3 | uVar2 << 0x1d;
  uVar2 = (uVar1 >> 1 ^ uVar4) & 0x55555555;
  uVar4 = uVar4 ^ uVar2;
  uVar1 = uVar1 ^ uVar2 * 2;
  uVar2 = (uVar4 >> 8 ^ uVar1) & 0xff00ff;
  uVar1 = uVar1 ^ uVar2;
  uVar4 = uVar4 ^ uVar2 << 8;
  uVar2 = (uVar1 >> 2 ^ uVar4) & 0x33333333;
  uVar4 = uVar4 ^ uVar2;
  uVar1 = uVar1 ^ uVar2 << 2;
  uVar2 = (uVar4 >> 0x10 ^ uVar1) & 0xffff;
  uVar1 = uVar1 ^ uVar2;
  uVar4 = uVar4 ^ uVar2 << 0x10;
  uVar2 = (uVar1 >> 4 ^ uVar4) & 0xf0f0f0f;
  *param_1 = uVar4 ^ uVar2;
  param_1[1] = uVar2 << 4 ^ uVar1;
  return;
}

