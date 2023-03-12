
void CRYPTO_ccm128_aad(byte *param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  byte bVar5;
  uint uVar4;
  byte *pbVar6;
  code *pcVar7;
  
  if (param_3 == 0) {
    return;
  }
  pbVar6 = param_1 + 0x10;
  pcVar7 = *(code **)(param_1 + 0x28);
  *param_1 = *param_1 | 0x40;
  (*pcVar7)(param_1,pbVar6,*(undefined4 *)(param_1 + 0x2c));
  uVar1 = *(uint *)(param_1 + 0x24);
  uVar3 = uVar1 + 1;
  *(uint *)(param_1 + 0x24) = uVar3;
  *(uint *)(param_1 + 0x20) = (uint)(uVar3 < uVar1) + *(int *)(param_1 + 0x20);
  bVar5 = (byte)(param_3 >> 8);
  if (param_3 < 0xff00) {
    uVar1 = 2;
    bVar2 = bVar5 ^ param_1[0x10];
    bVar5 = (byte)param_3 ^ param_1[0x11];
  }
  else {
    param_1[0x13] = (byte)(param_3 >> 0x10) ^ param_1[0x13];
    bVar2 = ~param_1[0x10];
    param_1[0x12] = (byte)(param_3 >> 0x18) ^ param_1[0x12];
    uVar1 = 6;
    param_1[0x14] = bVar5 ^ param_1[0x14];
    param_1[0x15] = (byte)param_3 ^ param_1[0x15];
    bVar5 = param_1[0x11] ^ 0xfe;
  }
  param_1[0x10] = bVar2;
  param_1[0x11] = bVar5;
  if (0xf < uVar1) goto LAB_005ed26c;
  while (param_3 != 0) {
    while( true ) {
      bVar5 = *param_2;
      uVar3 = uVar1 + 1;
      param_2 = param_2 + 1;
      param_3 = param_3 - 1;
      param_1[uVar1 + 0x10] = param_1[uVar1 + 0x10] ^ bVar5;
      uVar1 = uVar3;
      if (uVar3 < 0x10) break;
LAB_005ed26c:
      (*pcVar7)(pbVar6,pbVar6,*(undefined4 *)(param_1 + 0x2c));
      uVar1 = 0;
      uVar3 = *(uint *)(param_1 + 0x24);
      uVar4 = uVar3 + 1;
      *(uint *)(param_1 + 0x24) = uVar4;
      *(uint *)(param_1 + 0x20) = (uint)(uVar4 < uVar3) + *(int *)(param_1 + 0x20);
      if (param_3 == 0) {
        return;
      }
      if (param_3 == 0) goto LAB_005ed2a4;
    }
  }
LAB_005ed2a4:
  (*pcVar7)(pbVar6,pbVar6,*(undefined4 *)(param_1 + 0x2c));
  uVar1 = *(uint *)(param_1 + 0x24);
  uVar3 = uVar1 + 1;
  *(uint *)(param_1 + 0x24) = uVar3;
  *(uint *)(param_1 + 0x20) = (uint)(uVar3 < uVar1) + *(int *)(param_1 + 0x20);
  return;
}

