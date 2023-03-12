
void DES_encrypt1(uint *data,DES_key_schedule *ks,int enc)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = (data[1] >> 4 ^ *data) & 0xf0f0f0f;
  uVar4 = *data ^ uVar1;
  uVar1 = uVar1 << 4 ^ data[1];
  uVar2 = (uVar4 >> 0x10 ^ uVar1) & 0xffff;
  uVar1 = uVar1 ^ uVar2;
  uVar4 = uVar2 << 0x10 ^ uVar4;
  uVar2 = (uVar1 >> 2 ^ uVar4) & 0x33333333;
  uVar4 = uVar4 ^ uVar2;
  uVar1 = uVar2 << 2 ^ uVar1;
  uVar2 = (uVar4 >> 8 ^ uVar1) & 0xff00ff;
  uVar1 = uVar1 ^ uVar2;
  uVar4 = uVar2 << 8 ^ uVar4;
  uVar2 = (uVar1 >> 1 ^ uVar4) & 0x55555555;
  uVar4 = uVar4 ^ uVar2;
  uVar1 = uVar2 << 1 ^ uVar1;
  uVar2 = (uVar4 >> 0x1d) + uVar4 * 8;
  uVar1 = (uVar1 >> 0x1d) + uVar1 * 8;
  if (enc == 0) {
    uVar3 = uVar2 ^ ks->ks[0xf].deslong[0];
    uVar5 = uVar2 ^ *(uint *)((int)ks->ks + 0x7c);
    uVar4 = uVar5 >> 4;
    uVar5 = uVar4 + uVar5 * 0x10000000;
    uVar4 = uVar1 ^ *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar4 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar4 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar4 ^ ks->ks[0xe].deslong[0];
    uVar5 = uVar4 ^ *(uint *)((int)ks->ks + 0x74);
    uVar1 = uVar5 >> 4;
    uVar5 = uVar1 + uVar5 * 0x10000000;
    uVar2 = uVar2 ^ *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar2 ^ ks->ks[0xd].deslong[0];
    uVar5 = uVar2 ^ *(uint *)((int)ks->ks + 0x6c);
    uVar1 = uVar5 >> 4;
    uVar5 = uVar1 + uVar5 * 0x10000000;
    uVar5 = uVar4 ^ *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 ^ ks->ks[0xc].deslong[0];
    uVar4 = uVar5 ^ *(uint *)((int)ks->ks + 100);
    uVar1 = uVar4 >> 4;
    uVar4 = uVar1 + uVar4 * 0x10000000;
    uVar3 = uVar2 ^ *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar4 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar4 = uVar3 ^ ks->ks[0xb].deslong[0];
    uVar2 = uVar3 ^ *(uint *)((int)ks->ks + 0x5c);
    uVar1 = uVar2 >> 4;
    uVar2 = uVar1 + uVar2 * 0x10000000;
    uVar5 = uVar5 ^ *(uint *)(DES_SPtrans + ((uVar4 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar5 ^ ks->ks[10].deslong[0];
    uVar4 = uVar5 ^ *(uint *)((int)ks->ks + 0x54);
    uVar1 = uVar4 >> 4;
    uVar4 = uVar1 + uVar4 * 0x10000000;
    uVar6 = uVar3 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar4 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar4 = uVar6 ^ ks->ks[9].deslong[0];
    uVar2 = uVar6 ^ *(uint *)((int)ks->ks + 0x4c);
    uVar1 = uVar2 >> 4;
    uVar2 = uVar1 + uVar2 * 0x10000000;
    uVar3 = uVar5 ^ *(uint *)(DES_SPtrans + ((uVar4 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar4 = uVar3 ^ ks->ks[8].deslong[0];
    uVar2 = uVar3 ^ *(uint *)((int)ks->ks + 0x44);
    uVar1 = uVar2 >> 4;
    uVar2 = uVar1 + uVar2 * 0x10000000;
    uVar4 = uVar6 ^ *(uint *)(DES_SPtrans + ((uVar4 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar4 ^ ks->ks[7].deslong[0];
    uVar5 = uVar4 ^ *(uint *)((int)ks->ks + 0x3c);
    uVar1 = uVar5 >> 4;
    uVar5 = uVar1 + uVar5 * 0x10000000;
    uVar5 = uVar3 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar5 ^ ks->ks[6].deslong[0];
    uVar3 = uVar5 ^ *(uint *)((int)ks->ks + 0x34);
    uVar1 = uVar3 >> 4;
    uVar3 = uVar1 + uVar3 * 0x10000000;
    uVar3 = uVar4 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar3 ^ ks->ks[5].deslong[0];
    uVar4 = uVar3 ^ *(uint *)((int)ks->ks + 0x2c);
    uVar1 = uVar4 >> 4;
    uVar4 = uVar1 + uVar4 * 0x10000000;
    uVar5 = uVar5 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar4 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar5 ^ ks->ks[4].deslong[0];
    uVar4 = uVar5 ^ *(uint *)((int)ks->ks + 0x24);
    uVar1 = uVar4 >> 4;
    uVar4 = uVar1 + uVar4 * 0x10000000;
    uVar4 = uVar3 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar4 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar4 ^ ks->ks[3].deslong[0];
    uVar3 = uVar4 ^ *(uint *)((int)ks->ks + 0x1c);
    uVar1 = uVar3 >> 4;
    uVar3 = uVar1 + uVar3 * 0x10000000;
    uVar5 = uVar5 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar5 ^ ks->ks[2].deslong[0];
    uVar3 = uVar5 ^ *(uint *)((int)ks->ks + 0x14);
    uVar1 = uVar3 >> 4;
    uVar3 = uVar1 + uVar3 * 0x10000000;
    uVar4 = uVar4 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar4 ^ ks->ks[1].deslong[0];
    uVar2 = uVar4 ^ *(uint *)((int)ks->ks + 0xc);
    uVar1 = uVar2 >> 4;
    uVar2 = uVar1 + uVar2 * 0x10000000;
    uVar3 = uVar5 ^ *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar3 ^ ks->ks[0].deslong[0];
    uVar5 = uVar3 ^ ks->ks[0].deslong[1];
    uVar1 = uVar5 >> 4;
    uVar5 = uVar1 + uVar5 * 0x10000000;
    uVar1 = uVar4 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
  }
  else {
    uVar5 = uVar2 ^ ks->ks[0].deslong[0];
    uVar3 = uVar2 ^ ks->ks[0].deslong[1];
    uVar4 = uVar3 >> 4;
    uVar3 = uVar4 + uVar3 * 0x10000000;
    uVar3 = uVar1 ^ *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar4 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar4 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar4 = uVar3 ^ ks->ks[1].deslong[0];
    uVar5 = uVar3 ^ *(uint *)((int)ks->ks + 0xc);
    uVar1 = uVar5 >> 4;
    uVar5 = uVar1 + uVar5 * 0x10000000;
    uVar2 = uVar2 ^ *(uint *)(DES_SPtrans + ((uVar4 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar5 = uVar2 ^ ks->ks[2].deslong[0];
    uVar4 = uVar2 ^ *(uint *)((int)ks->ks + 0x14);
    uVar1 = uVar4 >> 4;
    uVar4 = uVar1 + uVar4 * 0x10000000;
    uVar3 = uVar3 ^ *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar4 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar5 = uVar3 ^ ks->ks[3].deslong[0];
    uVar4 = uVar3 ^ *(uint *)((int)ks->ks + 0x1c);
    uVar1 = uVar4 >> 4;
    uVar4 = uVar1 + uVar4 * 0x10000000;
    uVar5 = uVar2 ^ *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar4 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar5 ^ ks->ks[4].deslong[0];
    uVar4 = uVar5 ^ *(uint *)((int)ks->ks + 0x24);
    uVar1 = uVar4 >> 4;
    uVar4 = uVar1 + uVar4 * 0x10000000;
    uVar3 = uVar3 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar4 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar4 = uVar3 ^ ks->ks[5].deslong[0];
    uVar2 = uVar3 ^ *(uint *)((int)ks->ks + 0x2c);
    uVar1 = uVar2 >> 4;
    uVar2 = uVar1 + uVar2 * 0x10000000;
    uVar4 = uVar5 ^ *(uint *)(DES_SPtrans + ((uVar4 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar5 = uVar4 ^ ks->ks[6].deslong[0];
    uVar2 = uVar4 ^ *(uint *)((int)ks->ks + 0x34);
    uVar1 = uVar2 >> 4;
    uVar2 = uVar1 + uVar2 * 0x10000000;
    uVar5 = uVar3 ^ *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar5 ^ ks->ks[7].deslong[0];
    uVar3 = uVar5 ^ *(uint *)((int)ks->ks + 0x3c);
    uVar1 = uVar3 >> 4;
    uVar3 = uVar1 + uVar3 * 0x10000000;
    uVar2 = uVar4 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar2 ^ ks->ks[8].deslong[0];
    uVar4 = uVar2 ^ *(uint *)((int)ks->ks + 0x44);
    uVar1 = uVar4 >> 4;
    uVar4 = uVar1 + uVar4 * 0x10000000;
    uVar5 = uVar5 ^ *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar4 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 ^ ks->ks[9].deslong[0];
    uVar4 = uVar5 ^ *(uint *)((int)ks->ks + 0x4c);
    uVar1 = uVar4 >> 4;
    uVar4 = uVar1 + uVar4 * 0x10000000;
    uVar4 = uVar2 ^ *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar4 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar4 ^ ks->ks[10].deslong[0];
    uVar3 = uVar4 ^ *(uint *)((int)ks->ks + 0x54);
    uVar1 = uVar3 >> 4;
    uVar3 = uVar1 + uVar3 * 0x10000000;
    uVar5 = uVar5 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar5 ^ ks->ks[0xb].deslong[0];
    uVar3 = uVar5 ^ *(uint *)((int)ks->ks + 0x5c);
    uVar1 = uVar3 >> 4;
    uVar3 = uVar1 + uVar3 * 0x10000000;
    uVar4 = uVar4 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar4 ^ ks->ks[0xc].deslong[0];
    uVar2 = uVar4 ^ *(uint *)((int)ks->ks + 100);
    uVar1 = uVar2 >> 4;
    uVar2 = uVar1 + uVar2 * 0x10000000;
    uVar5 = uVar5 ^ *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar5 ^ ks->ks[0xd].deslong[0];
    uVar3 = uVar5 ^ *(uint *)((int)ks->ks + 0x6c);
    uVar1 = uVar3 >> 4;
    uVar3 = uVar1 + uVar3 * 0x10000000;
    uVar4 = uVar4 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar3 = uVar4 ^ ks->ks[0xe].deslong[0];
    uVar2 = uVar4 ^ *(uint *)((int)ks->ks + 0x74);
    uVar1 = uVar2 >> 4;
    uVar2 = uVar1 + uVar2 * 0x10000000;
    uVar3 = uVar5 ^ *(uint *)(DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar3 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
    uVar2 = uVar3 ^ ks->ks[0xf].deslong[0];
    uVar5 = uVar3 ^ *(uint *)((int)ks->ks + 0x7c);
    uVar1 = uVar5 >> 4;
    uVar5 = uVar1 + uVar5 * 0x10000000;
    uVar1 = uVar4 ^ *(uint *)(DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar5 >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(DES_SPtrans + ((uVar1 * 0x100 >> 0x1a) + 0x140) * 4);
  }
  uVar1 = (uVar1 >> 3) + uVar1 * 0x20000000;
  uVar4 = (uVar3 >> 3) + uVar3 * 0x20000000;
  uVar2 = (uVar1 >> 1 ^ uVar4) & 0x55555555;
  uVar4 = uVar4 ^ uVar2;
  uVar1 = uVar2 << 1 ^ uVar1;
  uVar2 = (uVar4 >> 8 ^ uVar1) & 0xff00ff;
  uVar1 = uVar1 ^ uVar2;
  uVar4 = uVar2 << 8 ^ uVar4;
  uVar2 = (uVar1 >> 2 ^ uVar4) & 0x33333333;
  uVar4 = uVar4 ^ uVar2;
  uVar1 = uVar2 << 2 ^ uVar1;
  uVar2 = (uVar4 >> 0x10 ^ uVar1) & 0xffff;
  uVar1 = uVar1 ^ uVar2;
  uVar4 = uVar2 << 0x10 ^ uVar4;
  uVar2 = (uVar1 >> 4 ^ uVar4) & 0xf0f0f0f;
  *data = uVar4 ^ uVar2;
  data[1] = uVar2 << 4 ^ uVar1;
  return;
}
