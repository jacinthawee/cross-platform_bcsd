
void mac_block(int *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if ((param_3 < param_2 + 1 && param_2 < param_3 + 1) ||
     ((((uint)param_3 | (uint)param_2) & 3) != 0)) {
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
    *param_2 = *param_3 ^ *param_2;
    param_2[1] = param_3[1] ^ param_2[1];
  }
  uVar5 = (uint)*(byte *)((int)param_2 + 1) << 8 | (uint)*(byte *)((int)param_2 + 2) << 0x10 |
          (uint)*(byte *)param_2 | (uint)*(byte *)((int)param_2 + 3) << 0x18;
  uVar1 = uVar5 + *param_1;
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar4 = (uVar1 >> 0x15) + uVar1 * 0x800 ^
          ((uint)*(byte *)((int)param_2 + 5) << 8 | (uint)*(byte *)((int)param_2 + 6) << 0x10 |
           (uint)*(byte *)(param_2 + 1) | (uint)*(byte *)((int)param_2 + 7) << 0x18);
  uVar1 = uVar4 + param_1[1];
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar5 = (uVar1 >> 0x15) + uVar1 * 0x800 ^ uVar5;
  uVar1 = uVar5 + param_1[2];
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar4 = (uVar1 >> 0x15) + uVar1 * 0x800 ^ uVar4;
  uVar1 = uVar4 + param_1[3];
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar5 = (uVar1 >> 0x15) + uVar1 * 0x800 ^ uVar5;
  uVar1 = uVar5 + param_1[4];
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar4 = (uVar1 >> 0x15) + uVar1 * 0x800 ^ uVar4;
  uVar1 = uVar4 + param_1[5];
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar5 = (uVar1 >> 0x15) + uVar1 * 0x800 ^ uVar5;
  uVar1 = uVar5 + param_1[6];
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar4 = (uVar1 >> 0x15) + uVar1 * 0x800 ^ uVar4;
  uVar1 = uVar4 + param_1[7];
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar5 = (uVar1 >> 0x15) + uVar1 * 0x800 ^ uVar5;
  uVar1 = *param_1 + uVar5;
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar4 = (uVar1 >> 0x15) + uVar1 * 0x800 ^ uVar4;
  uVar1 = param_1[1] + uVar4;
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar5 = (uVar1 >> 0x15) + uVar1 * 0x800 ^ uVar5;
  uVar1 = param_1[2] + uVar5;
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar4 = (uVar1 >> 0x15) + uVar1 * 0x800 ^ uVar4;
  uVar1 = param_1[3] + uVar4;
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar5 = (uVar1 >> 0x15) + uVar1 * 0x800 ^ uVar5;
  uVar1 = param_1[4] + uVar5;
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar4 = (uVar1 >> 0x15) + uVar1 * 0x800 ^ uVar4;
  uVar1 = param_1[5] + uVar4;
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar5 = (uVar1 >> 0x15) + uVar1 * 0x800 ^ uVar5;
  uVar1 = param_1[6] + uVar5;
  uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar4 = (uVar1 >> 0x15) + uVar1 * 0x800 ^ uVar4;
  uVar1 = param_1[7] + uVar4;
  uVar3 = param_1[(uVar1 & 0xff) + 0x308];
  uVar2 = param_1[(uVar1 >> 0x18) + 8];
  uVar6 = param_1[(uVar1 * 0x100 >> 0x18) + 0x108];
  uVar1 = param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  *(byte *)(param_2 + 1) = (byte)uVar4;
  *(byte *)((int)param_2 + 5) = (byte)(uVar4 >> 8);
  uVar1 = uVar3 | uVar2 | uVar6 | uVar1;
  *(byte *)((int)param_2 + 6) = (byte)(uVar4 >> 0x10);
  *(byte *)((int)param_2 + 7) = (byte)(uVar4 >> 0x18);
  uVar5 = (uVar1 >> 0x15) + uVar1 * 0x800 ^ uVar5;
  *(byte *)param_2 = (byte)uVar5;
  *(byte *)((int)param_2 + 1) = (byte)(uVar5 >> 8);
  *(byte *)((int)param_2 + 2) = (byte)(uVar5 >> 0x10);
  *(byte *)((int)param_2 + 3) = (byte)(uVar5 >> 0x18);
  return;
}

