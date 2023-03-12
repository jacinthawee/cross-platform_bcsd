
void DES_decrypt3(uint *data,DES_key_schedule *ks1,DES_key_schedule *ks2,DES_key_schedule *ks3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = (*data ^ data[1] >> 4) & 0xf0f0f0f;
  uVar3 = *data ^ uVar1;
  uVar1 = data[1] ^ uVar1 << 4;
  uVar2 = (uVar1 ^ uVar3 >> 0x10) & 0xffff;
  uVar1 = uVar2 ^ uVar1;
  uVar3 = uVar3 ^ uVar2 << 0x10;
  uVar2 = (uVar3 ^ uVar1 >> 2) & 0x33333333;
  uVar3 = uVar3 ^ uVar2;
  uVar1 = uVar1 ^ uVar2 << 2;
  uVar2 = (uVar1 ^ uVar3 >> 8) & 0xff00ff;
  uVar1 = uVar1 ^ uVar2;
  uVar3 = uVar3 ^ uVar2 << 8;
  uVar2 = (uVar3 ^ uVar1 >> 1) & 0x55555555;
  *data = uVar3 ^ uVar2;
  data[1] = uVar1 ^ uVar2 << 1;
  DES_encrypt2_constprop_1(data,ks3);
  DES_encrypt2_constprop_0(data,ks2);
  DES_encrypt2_constprop_1(data,ks1);
  uVar1 = (*data ^ data[1] >> 1) & 0x55555555;
  uVar3 = *data ^ uVar1;
  uVar1 = data[1] ^ uVar1 << 1;
  uVar2 = (uVar1 ^ uVar3 >> 8) & 0xff00ff;
  uVar1 = uVar1 ^ uVar2;
  uVar3 = uVar3 ^ uVar2 << 8;
  uVar2 = (uVar3 ^ uVar1 >> 2) & 0x33333333;
  uVar3 = uVar3 ^ uVar2;
  uVar1 = uVar1 ^ uVar2 << 2;
  uVar2 = (uVar1 ^ uVar3 >> 0x10) & 0xffff;
  uVar1 = uVar1 ^ uVar2;
  uVar3 = uVar3 ^ uVar2 << 0x10;
  uVar2 = (uVar3 ^ uVar1 >> 4) & 0xf0f0f0f;
  *data = uVar3 ^ uVar2;
  data[1] = uVar1 ^ uVar2 << 4;
  return;
}

