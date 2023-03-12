
void fcrypt_body(uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar3 = 0;
  uVar4 = 0;
  iVar8 = 0x19;
  uVar1 = 0;
  do {
    uVar6 = (uVar4 ^ uVar3) & param_3;
    uVar4 = (uVar4 ^ uVar3) & param_4;
    uVar5 = uVar3 ^ *param_2 ^ uVar6;
    uVar2 = uVar3 ^ param_2[1] ^ uVar4;
    uVar6 = uVar5 ^ uVar6 << 0x10;
    uVar4 = (uVar2 ^ uVar4 << 0x10) >> 4;
    iVar8 = iVar8 + -1;
    uVar1 = *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x140) * 4) ^ uVar1;
    uVar4 = uVar1 ^ uVar1 >> 0x10;
    uVar6 = uVar4 & param_3;
    uVar4 = uVar4 & param_4;
    uVar5 = uVar1 ^ param_2[2] ^ uVar6;
    uVar2 = uVar1 ^ param_2[3] ^ uVar4;
    uVar6 = uVar5 ^ uVar6 << 0x10;
    uVar4 = (uVar2 ^ uVar4 << 0x10) >> 4;
    uVar4 = *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar3 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar4 ^ uVar4 >> 0x10;
    uVar2 = uVar3 & param_3;
    uVar5 = uVar4 ^ param_2[4] ^ uVar2;
    uVar3 = uVar3 & param_4;
    uVar6 = uVar5 ^ uVar2 << 0x10;
    uVar2 = param_2[5] ^ uVar4 ^ uVar3;
    uVar3 = (uVar2 ^ uVar3 << 0x10) >> 4;
    uVar3 = uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
    uVar7 = uVar3 ^ uVar3 >> 0x10;
    uVar1 = uVar7 & param_3;
    uVar5 = uVar3 ^ param_2[6] ^ uVar1;
    uVar7 = uVar7 & param_4;
    uVar6 = uVar5 ^ uVar1 << 0x10;
    uVar2 = param_2[7] ^ uVar3 ^ uVar7;
    uVar1 = (uVar2 ^ uVar7 << 0x10) >> 4;
    uVar4 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar7 = uVar4 ^ uVar4 >> 0x10;
    uVar1 = uVar7 & param_3;
    uVar5 = uVar4 ^ param_2[8] ^ uVar1;
    uVar7 = uVar7 & param_4;
    uVar6 = uVar5 ^ uVar1 << 0x10;
    uVar2 = param_2[9] ^ uVar4 ^ uVar7;
    uVar1 = (uVar2 ^ uVar7 << 0x10) >> 4;
    uVar3 = uVar3 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar7 = uVar3 ^ uVar3 >> 0x10;
    uVar1 = uVar7 & param_3;
    uVar5 = uVar3 ^ param_2[10] ^ uVar1;
    uVar7 = uVar7 & param_4;
    uVar6 = uVar5 ^ uVar1 << 0x10;
    uVar2 = param_2[0xb] ^ uVar3 ^ uVar7;
    uVar1 = (uVar2 ^ uVar7 << 0x10) >> 4;
    uVar4 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar7 = uVar4 ^ uVar4 >> 0x10;
    uVar1 = uVar7 & param_3;
    uVar5 = uVar4 ^ param_2[0xc] ^ uVar1;
    uVar7 = uVar7 & param_4;
    uVar6 = uVar5 ^ uVar1 << 0x10;
    uVar2 = param_2[0xd] ^ uVar4 ^ uVar7;
    uVar1 = (uVar2 ^ uVar7 << 0x10) >> 4;
    uVar3 = uVar3 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar7 = uVar3 ^ uVar3 >> 0x10;
    uVar1 = uVar7 & param_3;
    uVar5 = uVar3 ^ param_2[0xe] ^ uVar1;
    uVar7 = uVar7 & param_4;
    uVar6 = uVar5 ^ uVar1 << 0x10;
    uVar2 = param_2[0xf] ^ uVar3 ^ uVar7;
    uVar1 = (uVar2 ^ uVar7 << 0x10) >> 4;
    uVar4 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar7 = uVar4 ^ uVar4 >> 0x10;
    uVar1 = uVar7 & param_3;
    uVar5 = uVar4 ^ param_2[0x10] ^ uVar1;
    uVar7 = uVar7 & param_4;
    uVar6 = uVar5 ^ uVar1 << 0x10;
    uVar2 = param_2[0x11] ^ uVar4 ^ uVar7;
    uVar1 = (uVar2 ^ uVar7 << 0x10) >> 4;
    uVar3 = uVar3 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar7 = uVar3 ^ uVar3 >> 0x10;
    uVar1 = uVar7 & param_3;
    uVar5 = uVar3 ^ param_2[0x12] ^ uVar1;
    uVar7 = uVar7 & param_4;
    uVar6 = uVar5 ^ uVar1 << 0x10;
    uVar2 = param_2[0x13] ^ uVar3 ^ uVar7;
    uVar1 = (uVar2 ^ uVar7 << 0x10) >> 4;
    uVar4 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar7 = uVar4 ^ uVar4 >> 0x10;
    uVar1 = uVar7 & param_3;
    uVar5 = uVar4 ^ param_2[0x14] ^ uVar1;
    uVar7 = uVar7 & param_4;
    uVar6 = uVar5 ^ uVar1 << 0x10;
    uVar2 = param_2[0x15] ^ uVar4 ^ uVar7;
    uVar1 = (uVar2 ^ uVar7 << 0x10) >> 4;
    uVar3 = uVar3 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar7 = uVar3 ^ uVar3 >> 0x10;
    uVar1 = uVar7 & param_3;
    uVar5 = uVar3 ^ param_2[0x16] ^ uVar1;
    uVar7 = uVar7 & param_4;
    uVar6 = uVar5 ^ uVar1 << 0x10;
    uVar2 = param_2[0x17] ^ uVar3 ^ uVar7;
    uVar1 = (uVar2 ^ uVar7 << 0x10) >> 4;
    uVar4 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar7 = uVar4 ^ uVar4 >> 0x10;
    uVar1 = uVar7 & param_3;
    uVar5 = uVar4 ^ param_2[0x18] ^ uVar1;
    uVar7 = uVar7 & param_4;
    uVar6 = uVar5 ^ uVar1 << 0x10;
    uVar2 = param_2[0x19] ^ uVar4 ^ uVar7;
    uVar1 = (uVar2 ^ uVar7 << 0x10) >> 4;
    uVar3 = uVar3 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar7 = uVar3 ^ uVar3 >> 0x10;
    uVar1 = uVar7 & param_3;
    uVar5 = uVar3 ^ param_2[0x1a] ^ uVar1;
    uVar7 = uVar7 & param_4;
    uVar6 = uVar5 ^ uVar1 << 0x10;
    uVar2 = param_2[0x1b] ^ uVar3 ^ uVar7;
    uVar1 = (uVar2 ^ uVar7 << 0x10) >> 4;
    uVar5 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar1 = uVar5 ^ uVar5 >> 0x10;
    uVar2 = uVar1 & param_3;
    uVar1 = uVar1 & param_4;
    uVar4 = uVar5 ^ param_2[0x1c] ^ uVar2;
    uVar6 = uVar5 ^ param_2[0x1d] ^ uVar1;
    uVar2 = uVar4 ^ uVar2 << 0x10;
    uVar1 = (uVar6 ^ uVar1 << 0x10) >> 4;
    uVar3 = *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar3 ^ *(uint *)(&DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar4 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar6 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar4 = uVar3 >> 0x10;
    uVar6 = (uVar4 ^ uVar3) & param_3;
    uVar1 = (uVar4 ^ uVar3) & param_4;
    uVar7 = uVar3 ^ param_2[0x1e] ^ uVar6;
    uVar2 = param_2[0x1f] ^ uVar3 ^ uVar1;
    uVar6 = uVar7 ^ uVar6 << 0x10;
    uVar1 = (uVar2 ^ uVar1 << 0x10) >> 4;
    uVar1 = *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4) ^
            uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar7 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar7 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4);
  } while (iVar8 != 0);
  uVar1 = uVar1 >> 3 | uVar1 << 0x1d;
  uVar3 = uVar3 >> 3 | uVar3 << 0x1d;
  uVar4 = (uVar3 ^ uVar1 >> 1) & 0x55555555;
  uVar3 = uVar3 ^ uVar4;
  uVar1 = uVar1 ^ uVar4 << 1;
  uVar4 = (uVar1 ^ uVar3 >> 8) & 0xff00ff;
  uVar1 = uVar1 ^ uVar4;
  uVar3 = uVar3 ^ uVar4 << 8;
  uVar4 = (uVar3 ^ uVar1 >> 2) & 0x33333333;
  uVar3 = uVar3 ^ uVar4;
  uVar1 = uVar1 ^ uVar4 << 2;
  uVar4 = (uVar1 ^ uVar3 >> 0x10) & 0xffff;
  uVar1 = uVar1 ^ uVar4;
  uVar3 = uVar3 ^ uVar4 << 0x10;
  uVar4 = (uVar3 ^ uVar1 >> 4) & 0xf0f0f0f;
  *param_1 = uVar3 ^ uVar4;
  param_1[1] = uVar1 ^ uVar4 << 4;
  return;
}

