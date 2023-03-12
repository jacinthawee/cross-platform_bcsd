
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
  
  iVar8 = 0x19;
  uVar4 = 0;
  uVar2 = 0;
  uVar3 = 0;
  do {
    uVar5 = param_3 & (uVar2 ^ uVar4);
    uVar2 = param_4 & (uVar2 ^ uVar4);
    uVar6 = uVar4 ^ *param_2 ^ uVar5;
    uVar7 = uVar5 << 0x10 ^ uVar6;
    uVar5 = uVar4 ^ param_2[1] ^ uVar2;
    uVar2 = (uVar2 << 0x10 ^ uVar5) >> 4;
    uVar5 = uVar2 + uVar5 * 0x10000000;
    uVar3 = *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar5 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar2 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar2 * 0x100 >> 0x1a) + 0x140) * 4) ^ uVar3;
    uVar2 = uVar3 >> 0x10 ^ uVar3;
    uVar5 = param_3 & uVar2;
    uVar2 = param_4 & uVar2;
    uVar6 = uVar3 ^ param_2[2] ^ uVar5;
    uVar7 = uVar5 << 0x10 ^ uVar6;
    uVar5 = uVar3 ^ param_2[3] ^ uVar2;
    uVar2 = (uVar2 << 0x10 ^ uVar5) >> 4;
    uVar5 = uVar2 + uVar5 * 0x10000000;
    uVar6 = uVar4 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar5 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar2 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar2 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar6 >> 0x10 ^ uVar6;
    uVar4 = param_3 & uVar2;
    uVar2 = param_4 & uVar2;
    uVar5 = uVar6 ^ param_2[4] ^ uVar4;
    uVar7 = uVar4 << 0x10 ^ uVar5;
    uVar4 = uVar6 ^ param_2[5] ^ uVar2;
    uVar2 = (uVar2 << 0x10 ^ uVar4) >> 4;
    uVar4 = uVar2 + uVar4 * 0x10000000;
    uVar5 = uVar3 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar4 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar4 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar2 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar2 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 >> 0x10 ^ uVar5;
    uVar2 = param_3 & uVar3;
    uVar3 = param_4 & uVar3;
    uVar4 = uVar5 ^ param_2[6] ^ uVar2;
    uVar7 = uVar2 << 0x10 ^ uVar4;
    uVar2 = uVar5 ^ param_2[7] ^ uVar3;
    uVar3 = (uVar3 << 0x10 ^ uVar2) >> 4;
    uVar2 = uVar3 + uVar2 * 0x10000000;
    uVar4 = uVar6 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar2 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar4 >> 0x10 ^ uVar4;
    uVar2 = param_3 & uVar3;
    uVar3 = param_4 & uVar3;
    uVar6 = uVar4 ^ param_2[8] ^ uVar2;
    uVar7 = uVar2 << 0x10 ^ uVar6;
    uVar2 = uVar4 ^ param_2[9] ^ uVar3;
    uVar3 = (uVar3 << 0x10 ^ uVar2) >> 4;
    uVar2 = uVar3 + uVar2 * 0x10000000;
    uVar2 = uVar5 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar2 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
    iVar8 = iVar8 + -1;
    uVar3 = uVar2 >> 0x10 ^ uVar2;
    uVar5 = param_3 & uVar3;
    uVar3 = param_4 & uVar3;
    uVar6 = uVar2 ^ param_2[10] ^ uVar5;
    uVar7 = uVar5 << 0x10 ^ uVar6;
    uVar5 = uVar2 ^ param_2[0xb] ^ uVar3;
    uVar3 = (uVar3 << 0x10 ^ uVar5) >> 4;
    uVar5 = uVar3 + uVar5 * 0x10000000;
    uVar5 = uVar4 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar5 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 >> 0x10 ^ uVar5;
    uVar4 = param_3 & uVar3;
    uVar3 = param_4 & uVar3;
    uVar6 = uVar5 ^ param_2[0xc] ^ uVar4;
    uVar7 = uVar4 << 0x10 ^ uVar6;
    uVar4 = uVar5 ^ param_2[0xd] ^ uVar3;
    uVar3 = (uVar3 << 0x10 ^ uVar4) >> 4;
    uVar4 = uVar3 + uVar4 * 0x10000000;
    uVar4 = uVar2 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar4 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar4 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar4 >> 0x10 ^ uVar4;
    uVar2 = param_3 & uVar3;
    uVar3 = param_4 & uVar3;
    uVar6 = uVar4 ^ param_2[0xe] ^ uVar2;
    uVar7 = uVar2 << 0x10 ^ uVar6;
    uVar2 = uVar4 ^ param_2[0xf] ^ uVar3;
    uVar3 = (uVar3 << 0x10 ^ uVar2) >> 4;
    uVar2 = uVar3 + uVar2 * 0x10000000;
    uVar2 = uVar5 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar2 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar2 >> 0x10 ^ uVar2;
    uVar5 = param_3 & uVar3;
    uVar3 = param_4 & uVar3;
    uVar6 = uVar2 ^ param_2[0x10] ^ uVar5;
    uVar7 = uVar5 << 0x10 ^ uVar6;
    uVar5 = uVar2 ^ param_2[0x11] ^ uVar3;
    uVar3 = (uVar3 << 0x10 ^ uVar5) >> 4;
    uVar5 = uVar3 + uVar5 * 0x10000000;
    uVar5 = uVar4 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar5 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 >> 0x10 ^ uVar5;
    uVar4 = param_3 & uVar3;
    uVar3 = param_4 & uVar3;
    uVar6 = uVar5 ^ param_2[0x12] ^ uVar4;
    uVar7 = uVar4 << 0x10 ^ uVar6;
    uVar4 = uVar5 ^ param_2[0x13] ^ uVar3;
    uVar3 = (uVar3 << 0x10 ^ uVar4) >> 4;
    uVar4 = uVar3 + uVar4 * 0x10000000;
    uVar4 = uVar2 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar4 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar4 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar4 >> 0x10 ^ uVar4;
    uVar2 = param_3 & uVar3;
    uVar3 = param_4 & uVar3;
    uVar6 = uVar4 ^ param_2[0x14] ^ uVar2;
    uVar7 = uVar2 << 0x10 ^ uVar6;
    uVar2 = uVar4 ^ param_2[0x15] ^ uVar3;
    uVar3 = (uVar3 << 0x10 ^ uVar2) >> 4;
    uVar2 = uVar3 + uVar2 * 0x10000000;
    uVar2 = uVar5 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar2 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar2 >> 0x10 ^ uVar2;
    uVar5 = param_3 & uVar3;
    uVar3 = param_4 & uVar3;
    uVar6 = uVar2 ^ param_2[0x16] ^ uVar5;
    uVar7 = uVar5 << 0x10 ^ uVar6;
    uVar5 = uVar2 ^ param_2[0x17] ^ uVar3;
    uVar3 = (uVar3 << 0x10 ^ uVar5) >> 4;
    uVar5 = uVar3 + uVar5 * 0x10000000;
    uVar5 = uVar4 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar5 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 >> 0x10 ^ uVar5;
    uVar4 = param_3 & uVar3;
    uVar3 = param_4 & uVar3;
    uVar6 = uVar5 ^ param_2[0x18] ^ uVar4;
    uVar7 = uVar4 << 0x10 ^ uVar6;
    uVar4 = uVar5 ^ param_2[0x19] ^ uVar3;
    uVar3 = (uVar3 << 0x10 ^ uVar4) >> 4;
    uVar4 = uVar3 + uVar4 * 0x10000000;
    uVar4 = uVar2 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar4 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar4 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar4 >> 0x10 ^ uVar4;
    uVar2 = param_3 & uVar3;
    uVar3 = param_4 & uVar3;
    uVar6 = uVar4 ^ param_2[0x1a] ^ uVar2;
    uVar7 = uVar2 << 0x10 ^ uVar6;
    uVar2 = uVar4 ^ param_2[0x1b] ^ uVar3;
    uVar3 = (uVar3 << 0x10 ^ uVar2) >> 4;
    uVar2 = uVar3 + uVar2 * 0x10000000;
    uVar5 = uVar5 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar2 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 >> 0x10 ^ uVar5;
    uVar2 = param_3 & uVar3;
    uVar3 = param_4 & uVar3;
    uVar6 = uVar5 ^ param_2[0x1c] ^ uVar2;
    uVar7 = uVar2 << 0x10 ^ uVar6;
    uVar2 = uVar5 ^ param_2[0x1d] ^ uVar3;
    uVar3 = (uVar3 << 0x10 ^ uVar2) >> 4;
    uVar2 = uVar3 + uVar2 * 0x10000000;
    uVar4 = uVar4 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar7 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar2 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar4 >> 0x10;
    uVar6 = param_3 & (uVar2 ^ uVar4);
    uVar3 = param_4 & (uVar2 ^ uVar4);
    uVar7 = uVar4 ^ param_2[0x1e] ^ uVar6;
    uVar1 = uVar6 << 0x10 ^ uVar7;
    uVar6 = uVar4 ^ param_2[0x1f] ^ uVar3;
    uVar3 = (uVar3 << 0x10 ^ uVar6) >> 4;
    uVar6 = uVar3 + uVar6 * 0x10000000;
    uVar3 = uVar5 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar1 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar1 & 0xfc)) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar7 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar6 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar6 & 0xfc) + 0x100) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar3 * 0x100 >> 0x1a) + 0x140) * 4);
  } while (iVar8 != 0);
  uVar2 = (uVar3 >> 3) + uVar3 * 0x20000000;
  uVar4 = (uVar4 >> 3) + uVar4 * 0x20000000;
  uVar3 = (uVar2 >> 1 ^ uVar4) & 0x55555555;
  uVar4 = uVar4 ^ uVar3;
  uVar2 = uVar3 << 1 ^ uVar2;
  uVar3 = (uVar4 >> 8 ^ uVar2) & 0xff00ff;
  uVar2 = uVar2 ^ uVar3;
  uVar4 = uVar3 << 8 ^ uVar4;
  uVar3 = (uVar2 >> 2 ^ uVar4) & 0x33333333;
  uVar4 = uVar4 ^ uVar3;
  uVar2 = uVar3 << 2 ^ uVar2;
  uVar3 = (uVar4 >> 0x10 ^ uVar2) & 0xffff;
  uVar2 = uVar2 ^ uVar3;
  uVar4 = uVar3 << 0x10 ^ uVar4;
  uVar3 = (uVar2 >> 4 ^ uVar4) & 0xf0f0f0f;
  *param_1 = uVar4 ^ uVar3;
  param_1[1] = uVar3 << 4 ^ uVar2;
  return;
}

