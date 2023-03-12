
void mac_block(int *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_3 < param_2 + 1 && param_2 < param_3 + 1) ||
     ((((uint)param_2 | (uint)param_3) & 3) != 0)) {
    *(byte *)param_2 = *(byte *)param_2 ^ *(byte *)param_3;
    *(byte *)((int)param_2 + 1) = *(byte *)((int)param_2 + 1) ^ *(byte *)((int)param_3 + 1);
    *(byte *)((int)param_2 + 2) = *(byte *)((int)param_2 + 2) ^ *(byte *)((int)param_3 + 2);
    *(byte *)((int)param_2 + 3) = *(byte *)((int)param_2 + 3) ^ *(byte *)((int)param_3 + 3);
    *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) ^ *(byte *)(param_3 + 1);
    *(byte *)((int)param_2 + 5) = *(byte *)((int)param_2 + 5) ^ *(byte *)((int)param_3 + 5);
    *(byte *)((int)param_2 + 6) = *(byte *)((int)param_2 + 6) ^ *(byte *)((int)param_3 + 6);
    *(byte *)((int)param_2 + 7) = *(byte *)((int)param_2 + 7) ^ *(byte *)((int)param_3 + 7);
  }
  else {
    *param_2 = *param_2 ^ *param_3;
    param_2[1] = param_2[1] ^ param_3[1];
  }
  uVar1 = *param_1 + *param_2;
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 >> 0x10 & 0xff) + 0x108] | param_1[(uVar1 >> 8 & 0xff) + 0x208];
  uVar3 = (uVar1 << 0xb | uVar1 >> 0x15) ^ param_2[1];
  uVar1 = param_1[1] + uVar3;
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 >> 0x10 & 0xff) + 0x108] | param_1[(uVar1 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar1 << 0xb | uVar1 >> 0x15) ^ *param_2;
  uVar2 = param_1[2] + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar3;
  uVar2 = param_1[3] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar1;
  uVar2 = uVar1 + param_1[4];
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar3;
  uVar2 = param_1[5] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar1;
  uVar2 = param_1[6] + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = uVar3 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[7] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = uVar1 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = *param_1 + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = uVar3 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[1] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = uVar1 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[2] + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = uVar3 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[3] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = uVar1 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[4] + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = uVar3 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[5] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = uVar1 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[6] + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = uVar3 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[7] + uVar3;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar1;
  *(byte *)param_2 = (byte)uVar1;
  *(byte *)(param_2 + 1) = (byte)uVar3;
  *(byte *)((int)param_2 + 1) = (byte)(uVar1 >> 8);
  *(byte *)((int)param_2 + 2) = (byte)(uVar1 >> 0x10);
  *(byte *)((int)param_2 + 3) = (byte)(uVar1 >> 0x18);
  *(byte *)((int)param_2 + 5) = (byte)(uVar3 >> 8);
  *(byte *)((int)param_2 + 7) = (byte)(uVar3 >> 0x18);
  *(byte *)((int)param_2 + 6) = (byte)(uVar3 >> 0x10);
  return;
}

