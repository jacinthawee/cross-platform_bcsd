
void DES_encrypt2_constprop_1(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = *param_1 >> 0x1d | *param_1 << 3;
  uVar2 = param_2[0x1e] ^ uVar3;
  uVar1 = (param_2[0x1f] ^ uVar3) >> 4;
  uVar4 = *(uint *)(&DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
          (param_1[1] >> 0x1d | param_1[1] << 3) ^
          *(uint *)(&DES_SPtrans + ((uVar2 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[0x1f] ^ uVar3) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  uVar2 = param_2[0x1c] ^ uVar4;
  uVar1 = (param_2[0x1d] ^ uVar4) >> 4;
  uVar5 = uVar3 ^ *(uint *)(&DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar2 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[0x1d] ^ uVar4) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = param_2[0x1a] ^ uVar5;
  uVar1 = (param_2[0x1b] ^ uVar5) >> 4;
  uVar2 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[0x1b] ^ uVar5) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = param_2[0x18] ^ uVar2;
  uVar1 = (param_2[0x19] ^ uVar2) >> 4;
  uVar4 = uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[0x19] ^ uVar2) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = param_2[0x16] ^ uVar4;
  uVar1 = (param_2[0x17] ^ uVar4) >> 4;
  uVar2 = uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[0x17] ^ uVar4) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = param_2[0x14] ^ uVar2;
  uVar1 = (param_2[0x15] ^ uVar2) >> 4;
  uVar4 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[0x15] ^ uVar2) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = param_2[0x12] ^ uVar4;
  uVar1 = (param_2[0x13] ^ uVar4) >> 4;
  uVar2 = uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[0x13] ^ uVar4) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = param_2[0x10] ^ uVar2;
  uVar1 = (param_2[0x11] ^ uVar2) >> 4;
  uVar4 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[0x11] ^ uVar2) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = param_2[0xe] ^ uVar4;
  uVar1 = (param_2[0xf] ^ uVar4) >> 4;
  uVar2 = uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[0xf] ^ uVar4) << 0x1c) >> 0x1a) + 0x1c0) * 4)
          ^ *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = param_2[0xc] ^ uVar2;
  uVar1 = (param_2[0xd] ^ uVar2) >> 4;
  uVar4 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[0xd] ^ uVar2) << 0x1c) >> 0x1a) + 0x1c0) * 4)
          ^ *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = param_2[10] ^ uVar4;
  uVar1 = (param_2[0xb] ^ uVar4) >> 4;
  uVar2 = uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[0xb] ^ uVar4) << 0x1c) >> 0x1a) + 0x1c0) * 4)
          ^ *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = param_2[8] ^ uVar2;
  uVar1 = (param_2[9] ^ uVar2) >> 4;
  uVar4 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[9] ^ uVar2) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = param_2[6] ^ uVar4;
  uVar1 = (param_2[7] ^ uVar4) >> 4;
  uVar2 = uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[7] ^ uVar4) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = param_2[4] ^ uVar2;
  uVar1 = (param_2[5] ^ uVar2) >> 4;
  uVar4 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[5] ^ uVar2) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = param_2[2] ^ uVar4;
  uVar1 = (param_2[3] ^ uVar4) >> 4;
  uVar2 = uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[3] ^ uVar4) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = uVar2 ^ *param_2;
  uVar1 = (param_2[1] ^ uVar2) >> 4;
  uVar1 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 | (param_2[1] ^ uVar2) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
  *param_1 = uVar2 >> 3 | uVar2 << 0x1d;
  param_1[1] = uVar1 >> 3 | uVar1 << 0x1d;
  return;
}
