
void gostcrypt(int *param_1,uint *param_2,undefined *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_1 + *param_2;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar2 << 0xb | uVar2 >> 0x15) ^ param_2[1];
  uVar2 = uVar1 + param_1[1];
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = (uVar2 << 0xb | uVar2 >> 0x15) ^ *param_2;
  uVar2 = param_1[2] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = uVar1 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[3] + uVar1;
  uVar2 = param_1[(uVar2 >> 8 & 0xff) + 0x208] |
          param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108];
  uVar3 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar3;
  uVar2 = param_1[4] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = uVar1 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[5] + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = uVar3 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[6] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar1;
  uVar2 = param_1[7] + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar3;
  uVar2 = *param_1 + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar1;
  uVar2 = param_1[1] + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar3;
  uVar2 = param_1[2] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar1;
  uVar2 = param_1[3] + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar3;
  uVar2 = param_1[4] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = uVar1 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[5] + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar3;
  uVar2 = param_1[6] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar1;
  uVar2 = param_1[7] + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar3;
  uVar2 = *param_1 + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar1;
  uVar2 = param_1[1] + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar3;
  uVar2 = param_1[2] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar1;
  uVar2 = param_1[3] + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar3;
  uVar2 = param_1[4] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar1;
  uVar2 = param_1[5] + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar3;
  uVar2 = param_1[6] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar1;
  uVar2 = param_1[7] + uVar1;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = uVar3 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[7] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar1;
  uVar2 = uVar1 + param_1[6];
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = uVar3 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[5] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar1;
  uVar2 = uVar1 + param_1[4];
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = uVar3 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[3] + uVar3;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = (uVar2 << 0xb | uVar2 >> 0x15) ^ uVar1;
  uVar2 = uVar1 + param_1[2];
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar3 = uVar3 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = param_1[1] + uVar3;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  uVar1 = uVar1 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  uVar2 = *param_1 + uVar1;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 >> 0x10 & 0xff) + 0x108] | param_1[(uVar2 >> 8 & 0xff) + 0x208];
  *param_3 = (char)uVar1;
  uVar3 = uVar3 ^ (uVar2 << 0xb | uVar2 >> 0x15);
  param_3[1] = (char)(uVar1 >> 8);
  param_3[4] = (char)uVar3;
  param_3[2] = (char)(uVar1 >> 0x10);
  param_3[3] = (char)(uVar1 >> 0x18);
  param_3[5] = (char)(uVar3 >> 8);
  param_3[7] = (char)(uVar3 >> 0x18);
  param_3[6] = (char)(uVar3 >> 0x10);
  return;
}

