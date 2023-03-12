
void DES_encrypt3(uint *data,DES_key_schedule *ks1,DES_key_schedule *ks2,DES_key_schedule *ks3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar2 = (data[1] >> 4 ^ *data) & 0xf0f0f0f;
  uVar1 = *data ^ uVar2;
  uVar4 = uVar2 << 4 ^ data[1];
  uVar2 = (uVar1 >> 0x10 ^ uVar4) & 0xffff;
  uVar4 = uVar4 ^ uVar2;
  uVar1 = uVar2 << 0x10 ^ uVar1;
  uVar2 = (uVar4 >> 2 ^ uVar1) & 0x33333333;
  uVar1 = uVar1 ^ uVar2;
  uVar4 = uVar2 << 2 ^ uVar4;
  uVar2 = (uVar1 >> 8 ^ uVar4) & 0xff00ff;
  uVar4 = uVar4 ^ uVar2;
  uVar1 = uVar2 << 8 ^ uVar1;
  uVar2 = (uVar4 >> 1 ^ uVar1) & 0x55555555;
  *data = uVar1 ^ uVar2;
  data[1] = uVar2 << 1 ^ uVar4;
  puVar3 = data;
  DES_encrypt2_constprop_0();
  DES_encrypt2_constprop_1();
  DES_encrypt2_constprop_0();
  uVar1 = (puVar3[1] >> 1 ^ *puVar3) & 0x55555555;
  uVar4 = *puVar3 ^ uVar1;
  uVar1 = uVar1 << 1 ^ puVar3[1];
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

