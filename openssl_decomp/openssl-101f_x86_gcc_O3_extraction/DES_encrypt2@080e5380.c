
void DES_encrypt2(uint *data,DES_key_schedule *ks,int enc)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = *data >> 0x1d | *data << 3;
  uVar1 = data[1] >> 0x1d | data[1] << 3;
  if (enc == 0) {
    uVar5 = uVar3 ^ ks->ks[0xf].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x7c) ^ uVar3;
    uVar2 = uVar4 >> 4;
    uVar2 = uVar1 ^ *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400) ^
            *(uint *)(DES_SPtrans + ((uVar2 | uVar4 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500);
    uVar4 = *(uint *)((int)ks->ks + 0x74) ^ uVar2;
    uVar5 = ks->ks[0xe].deslong[0] ^ uVar2;
    uVar1 = uVar4 >> 4;
    uVar4 = uVar3 ^ *(uint *)(DES_SPtrans + ((uVar1 | uVar4 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar3 = *(uint *)((int)ks->ks + 0x6c) ^ uVar4;
    uVar5 = ks->ks[0xd].deslong[0] ^ uVar4;
    uVar1 = uVar3 >> 4;
    uVar5 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar3 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar2 ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar3 = *(uint *)((int)ks->ks + 100) ^ uVar5;
    uVar2 = ks->ks[0xc].deslong[0] ^ uVar5;
    uVar1 = uVar3 >> 4;
    uVar2 = uVar4 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar3 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar2 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar2 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar2 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar3 = *(uint *)((int)ks->ks + 0x5c) ^ uVar2;
    uVar4 = ks->ks[0xb].deslong[0] ^ uVar2;
    uVar1 = uVar3 >> 4;
    uVar3 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar3 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar5 ^
            *(uint *)(DES_SPtrans + (uVar4 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar4 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar4 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar4 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar4 = *(uint *)((int)ks->ks + 0x54) ^ uVar3;
    uVar5 = ks->ks[10].deslong[0] ^ uVar3;
    uVar1 = uVar4 >> 4;
    uVar2 = uVar2 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar4 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar4 = *(uint *)((int)ks->ks + 0x4c) ^ uVar2;
    uVar5 = ks->ks[9].deslong[0] ^ uVar2;
    uVar1 = uVar4 >> 4;
    uVar4 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar4 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar3 ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar3 = *(uint *)((int)ks->ks + 0x44) ^ uVar4;
    uVar5 = ks->ks[8].deslong[0] ^ uVar4;
    uVar1 = uVar3 >> 4;
    uVar2 = uVar2 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar3 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar3 = *(uint *)((int)ks->ks + 0x3c) ^ uVar2;
    uVar5 = ks->ks[7].deslong[0] ^ uVar2;
    uVar1 = uVar3 >> 4;
    uVar3 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar3 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar4 ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar4 = *(uint *)((int)ks->ks + 0x34) ^ uVar3;
    uVar5 = ks->ks[6].deslong[0] ^ uVar3;
    uVar1 = uVar4 >> 4;
    uVar4 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar4 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar2 ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar2 = *(uint *)((int)ks->ks + 0x2c) ^ uVar4;
    uVar5 = ks->ks[5].deslong[0] ^ uVar4;
    uVar1 = uVar2 >> 4;
    uVar2 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar3 ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar3 = *(uint *)((int)ks->ks + 0x24) ^ uVar2;
    uVar5 = ks->ks[4].deslong[0] ^ uVar2;
    uVar1 = uVar3 >> 4;
    uVar3 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar3 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar4 ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar4 = *(uint *)((int)ks->ks + 0x1c) ^ uVar3;
    uVar5 = ks->ks[3].deslong[0] ^ uVar3;
    uVar1 = uVar4 >> 4;
    uVar4 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar4 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar2 ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar2 = *(uint *)((int)ks->ks + 0x14) ^ uVar4;
    uVar5 = ks->ks[2].deslong[0] ^ uVar4;
    uVar1 = uVar2 >> 4;
    uVar3 = uVar3 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar2 = *(uint *)((int)ks->ks + 0xc) ^ uVar3;
    uVar5 = ks->ks[1].deslong[0] ^ uVar3;
    uVar1 = uVar2 >> 4;
    uVar2 = uVar4 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar4 = ks->ks[0].deslong[1] ^ uVar2;
    uVar1 = ks->ks[0].deslong[0] ^ uVar2;
  }
  else {
    uVar5 = uVar3 ^ ks->ks[0].deslong[0];
    uVar4 = ks->ks[0].deslong[1] ^ uVar3;
    uVar2 = uVar4 >> 4;
    uVar2 = uVar1 ^ *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400) ^
            *(uint *)(DES_SPtrans + ((uVar2 | uVar4 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + (uVar2 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar2 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar2 & 0xfc0000) >> 0x12) * 4 + 0x500);
    uVar4 = *(uint *)((int)ks->ks + 0xc) ^ uVar2;
    uVar5 = ks->ks[1].deslong[0] ^ uVar2;
    uVar1 = uVar4 >> 4;
    uVar4 = uVar3 ^ *(uint *)(DES_SPtrans + ((uVar1 | uVar4 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar3 = *(uint *)((int)ks->ks + 0x14) ^ uVar4;
    uVar5 = ks->ks[2].deslong[0] ^ uVar4;
    uVar1 = uVar3 >> 4;
    uVar3 = uVar2 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar3 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar2 = *(uint *)((int)ks->ks + 0x1c) ^ uVar3;
    uVar5 = ks->ks[3].deslong[0] ^ uVar3;
    uVar1 = uVar2 >> 4;
    uVar4 = uVar4 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar2 = *(uint *)((int)ks->ks + 0x24) ^ uVar4;
    uVar5 = ks->ks[4].deslong[0] ^ uVar4;
    uVar1 = uVar2 >> 4;
    uVar3 = uVar3 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar2 = *(uint *)((int)ks->ks + 0x2c) ^ uVar3;
    uVar5 = ks->ks[5].deslong[0] ^ uVar3;
    uVar1 = uVar2 >> 4;
    uVar2 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar4 ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar4 = *(uint *)((int)ks->ks + 0x34) ^ uVar2;
    uVar5 = ks->ks[6].deslong[0] ^ uVar2;
    uVar1 = uVar4 >> 4;
    uVar3 = uVar3 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar4 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar4 = *(uint *)((int)ks->ks + 0x3c) ^ uVar3;
    uVar5 = ks->ks[7].deslong[0] ^ uVar3;
    uVar1 = uVar4 >> 4;
    uVar2 = uVar2 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar4 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar4 = *(uint *)((int)ks->ks + 0x44) ^ uVar2;
    uVar5 = ks->ks[8].deslong[0] ^ uVar2;
    uVar1 = uVar4 >> 4;
    uVar4 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar4 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar3 ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar3 = *(uint *)((int)ks->ks + 0x4c) ^ uVar4;
    uVar5 = ks->ks[9].deslong[0] ^ uVar4;
    uVar1 = uVar3 >> 4;
    uVar3 = *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
            *(uint *)(DES_SPtrans + ((uVar1 | uVar3 << 0x1c) >> 0x1a) * 4 + 0x700) ^
            *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^ uVar2 ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar2 = *(uint *)((int)ks->ks + 0x54) ^ uVar3;
    uVar5 = ks->ks[10].deslong[0] ^ uVar3;
    uVar1 = uVar2 >> 4;
    uVar4 = uVar4 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar2 = *(uint *)((int)ks->ks + 0x5c) ^ uVar4;
    uVar5 = ks->ks[0xb].deslong[0] ^ uVar4;
    uVar1 = uVar2 >> 4;
    uVar3 = uVar3 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar2 = *(uint *)((int)ks->ks + 100) ^ uVar3;
    uVar5 = ks->ks[0xc].deslong[0] ^ uVar3;
    uVar1 = uVar2 >> 4;
    uVar4 = uVar4 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar2 = *(uint *)((int)ks->ks + 0x6c) ^ uVar4;
    uVar5 = ks->ks[0xd].deslong[0] ^ uVar4;
    uVar1 = uVar2 >> 4;
    uVar3 = uVar3 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar2 = *(uint *)((int)ks->ks + 0x74) ^ uVar3;
    uVar5 = ks->ks[0xe].deslong[0] ^ uVar3;
    uVar1 = uVar2 >> 4;
    uVar2 = uVar4 ^ *(uint *)(DES_SPtrans + (uVar1 & 0xfc) + 0x100) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc00) >> 10) * 4 + 0x300) ^
                    *(uint *)(DES_SPtrans + ((uVar1 | uVar2 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                    *(uint *)(DES_SPtrans + ((uVar1 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x1a) * 4 + 0x600) ^
            *(uint *)(DES_SPtrans + (uVar5 & 0xfc)) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 10 & 0x3f) * 4 + 0x200) ^
            *(uint *)(DES_SPtrans + (uVar5 >> 0x12 & 0x3f) * 4 + 0x400);
    uVar4 = *(uint *)((int)ks->ks + 0x7c) ^ uVar2;
    uVar1 = ks->ks[0xf].deslong[0] ^ uVar2;
  }
  uVar5 = uVar4 >> 4;
  uVar1 = uVar3 ^ *(uint *)(DES_SPtrans + (uVar5 & 0xfc) + 0x100) ^
                  *(uint *)(DES_SPtrans + ((uVar5 & 0xfc00) >> 10) * 4 + 0x300) ^
                  *(uint *)(DES_SPtrans + ((uVar5 | uVar4 << 0x1c) >> 0x1a) * 4 + 0x700) ^
                  *(uint *)(DES_SPtrans + ((uVar5 & 0xfc0000) >> 0x12) * 4 + 0x500) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x1a) * 4 + 0x600) ^
          *(uint *)(DES_SPtrans + (uVar1 & 0xfc)) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 10 & 0x3f) * 4 + 0x200) ^
          *(uint *)(DES_SPtrans + (uVar1 >> 0x12 & 0x3f) * 4 + 0x400);
  *data = uVar2 >> 3 | uVar2 << 0x1d;
  data[1] = uVar1 >> 3 | uVar1 << 0x1d;
  return;
}

