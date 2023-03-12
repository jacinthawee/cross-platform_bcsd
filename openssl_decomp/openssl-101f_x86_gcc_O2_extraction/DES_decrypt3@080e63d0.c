
void DES_decrypt3(uint *data,DES_key_schedule *ks1,DES_key_schedule *ks2,DES_key_schedule *ks3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (data[1] >> 4 ^ *data) & 0xf0f0f0f;
  uVar1 = *data ^ uVar2;
  uVar3 = uVar2 << 4 ^ data[1];
  uVar2 = (uVar1 >> 0x10 ^ uVar3) & 0xffff;
  uVar3 = uVar3 ^ uVar2;
  uVar1 = uVar2 << 0x10 ^ uVar1;
  uVar2 = (uVar3 >> 2 ^ uVar1) & 0x33333333;
  uVar1 = uVar1 ^ uVar2;
  uVar3 = uVar2 << 2 ^ uVar3;
  uVar2 = (uVar1 >> 8 ^ uVar3) & 0xff00ff;
  uVar3 = uVar3 ^ uVar2;
  uVar1 = uVar2 << 8 ^ uVar1;
  uVar2 = (uVar3 >> 1 ^ uVar1) & 0x55555555;
  *data = uVar1 ^ uVar2;
  data[1] = uVar2 * 2 ^ uVar3;
  DES_encrypt2_constprop_1();
  DES_encrypt2_constprop_0();
  DES_encrypt2_constprop_1();
  uVar2 = (data[1] >> 1 ^ *data) & 0x55555555;
  uVar1 = *data ^ uVar2;
  uVar3 = uVar2 * 2 ^ data[1];
  uVar2 = (uVar1 >> 8 ^ uVar3) & 0xff00ff;
  uVar3 = uVar3 ^ uVar2;
  uVar1 = uVar2 << 8 ^ uVar1;
  uVar2 = (uVar3 >> 2 ^ uVar1) & 0x33333333;
  uVar1 = uVar1 ^ uVar2;
  uVar3 = uVar2 << 2 ^ uVar3;
  uVar2 = (uVar1 >> 0x10 ^ uVar3) & 0xffff;
  uVar3 = uVar3 ^ uVar2;
  uVar1 = uVar2 << 0x10 ^ uVar1;
  uVar2 = (uVar3 >> 4 ^ uVar1) & 0xf0f0f0f;
  *data = uVar1 ^ uVar2;
  data[1] = uVar2 << 4 ^ uVar3;
  return;
}

