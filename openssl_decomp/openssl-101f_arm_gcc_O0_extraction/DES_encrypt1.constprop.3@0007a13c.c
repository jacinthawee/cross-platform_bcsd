
void DES_encrypt1_constprop_3(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = (*param_1 ^ param_1[1] >> 4) & 0xf0f0f0f;
  uVar5 = uVar3 ^ *param_1;
  uVar4 = param_1[1] ^ uVar3 << 4;
  uVar3 = (uVar4 ^ uVar5 >> 0x10) & 0xffff;
  uVar4 = uVar3 ^ uVar4;
  uVar5 = uVar5 ^ uVar3 << 0x10;
  uVar3 = (uVar5 ^ uVar4 >> 2) & 0x33333333;
  uVar5 = uVar3 ^ uVar5;
  uVar4 = uVar4 ^ uVar3 << 2;
  uVar3 = (uVar4 ^ uVar5 >> 8) & 0xff00ff;
  uVar4 = uVar3 ^ uVar4;
  uVar5 = uVar5 ^ uVar3 << 8;
  uVar3 = (uVar5 ^ uVar4 >> 1) & 0x55555555;
  uVar5 = uVar3 ^ uVar5;
  uVar4 = uVar4 ^ uVar3 << 1;
  uVar5 = uVar5 >> 0x1d | uVar5 << 3;
  uVar1 = uVar5 ^ param_2[0x1e];
  uVar3 = (uVar5 ^ param_2[0x1f]) >> 4;
  uVar4 = *(uint *)(&DES_SPtrans + ((uVar1 >> 0x1a) + 0x180) * 4) ^ (uVar4 >> 0x1d | uVar4 << 3) ^
          *(uint *)(&DES_SPtrans + ((uVar1 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (uVar5 ^ param_2[0x1f]) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar1 = param_2[0x1c] ^ uVar4;
  uVar3 = (param_2[0x1d] ^ uVar4) >> 4;
  uVar1 = uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar1 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar1 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (param_2[0x1d] ^ uVar4) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar5 = param_2[0x1a] ^ uVar1;
  uVar3 = (param_2[0x1b] ^ uVar1) >> 4;
  uVar5 = *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (param_2[0x1b] ^ uVar1) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar4 = param_2[0x18] ^ uVar5;
  uVar3 = (param_2[0x19] ^ uVar5) >> 4;
  uVar1 = *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar4 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar4 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (param_2[0x19] ^ uVar5) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar4 = param_2[0x16] ^ uVar1;
  uVar3 = (param_2[0x17] ^ uVar1) >> 4;
  uVar5 = *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar4 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar4 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (param_2[0x17] ^ uVar1) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar4 = param_2[0x14] ^ uVar5;
  uVar3 = (param_2[0x15] ^ uVar5) >> 4;
  uVar1 = *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar4 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar4 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (param_2[0x15] ^ uVar5) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar4 = param_2[0x12] ^ uVar1;
  uVar3 = (param_2[0x13] ^ uVar1) >> 4;
  uVar4 = *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar4 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar4 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (param_2[0x13] ^ uVar1) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar5 = param_2[0x10] ^ uVar4;
  uVar3 = (param_2[0x11] ^ uVar4) >> 4;
  uVar5 = uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (param_2[0x11] ^ uVar4) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar1 = param_2[0xe] ^ uVar5;
  uVar3 = (param_2[0xf] ^ uVar5) >> 4;
  uVar2 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar1 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar1 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (param_2[0xf] ^ uVar5) << 0x1c) >> 0x1a) + 0x1c0) * 4)
          ^ *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar1 = param_2[0xc] ^ uVar2;
  uVar3 = (param_2[0xd] ^ uVar2) >> 4;
  uVar4 = *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar1 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar1 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (param_2[0xd] ^ uVar2) << 0x1c) >> 0x1a) + 0x1c0) * 4)
          ^ *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar5 = param_2[10] ^ uVar4;
  uVar3 = (param_2[0xb] ^ uVar4) >> 4;
  uVar1 = *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (param_2[0xb] ^ uVar4) << 0x1c) >> 0x1a) + 0x1c0) * 4)
          ^ *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar5 = param_2[8] ^ uVar1;
  uVar3 = (param_2[9] ^ uVar1) >> 4;
  uVar5 = *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (param_2[9] ^ uVar1) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar4 = uVar5 ^ param_2[6];
  uVar3 = (param_2[7] ^ uVar5) >> 4;
  uVar4 = uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar4 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar4 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (param_2[7] ^ uVar5) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar1 = uVar4 ^ param_2[4];
  uVar3 = (uVar4 ^ param_2[5]) >> 4;
  uVar1 = uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar1 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar1 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (uVar4 ^ param_2[5]) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar5 = param_2[2] ^ uVar1;
  uVar3 = (param_2[3] ^ uVar1) >> 4;
  uVar4 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (param_2[3] ^ uVar1) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar2 = *param_2 ^ uVar4;
  uVar3 = (param_2[1] ^ uVar4) >> 4;
  uVar5 = uVar4 >> 3 | uVar4 << 0x1d;
  uVar3 = uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar2 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 | (param_2[1] ^ uVar4) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = uVar3 >> 3 | uVar3 << 0x1d;
  uVar1 = (uVar5 ^ uVar3 >> 1) & 0x55555555;
  uVar5 = uVar1 ^ uVar5;
  uVar3 = uVar3 ^ uVar1 << 1;
  uVar1 = (uVar3 ^ uVar5 >> 8) & 0xff00ff;
  uVar3 = uVar3 ^ uVar1;
  uVar5 = uVar5 ^ uVar1 << 8;
  uVar1 = (uVar5 ^ uVar3 >> 2) & 0x33333333;
  uVar5 = uVar5 ^ uVar1;
  uVar3 = uVar3 ^ uVar1 << 2;
  uVar1 = (uVar3 ^ uVar5 >> 0x10) & 0xffff;
  uVar3 = uVar3 ^ uVar1;
  uVar5 = uVar5 ^ uVar1 << 0x10;
  uVar1 = (uVar5 ^ uVar3 >> 4) & 0xf0f0f0f;
  *param_1 = uVar5 ^ uVar1;
  param_1[1] = uVar3 ^ uVar1 << 4;
  return;
}

