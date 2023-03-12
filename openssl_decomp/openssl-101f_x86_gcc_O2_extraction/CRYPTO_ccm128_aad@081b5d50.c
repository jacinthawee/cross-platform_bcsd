
void CRYPTO_ccm128_aad(byte *param_1,byte *param_2,uint param_3)

{
  byte *pbVar1;
  uint *puVar2;
  code *pcVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  
  if (param_3 != 0) {
    pcVar3 = *(code **)(param_1 + 0x28);
    pbVar1 = param_1 + 0x10;
    *param_1 = *param_1 | 0x40;
    (*pcVar3)(param_1,pbVar1,*(undefined4 *)(param_1 + 0x2c));
    puVar2 = (uint *)(param_1 + 0x20);
    uVar5 = *puVar2;
    *puVar2 = *puVar2 + 1;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar5);
    bVar4 = (byte)(param_3 >> 8);
    if (param_3 < 0xff00) {
      uVar5 = 2;
      bVar7 = (byte)param_3 ^ param_1[0x11];
      bVar6 = bVar4 ^ param_1[0x10];
    }
    else {
      param_1[0x12] = param_1[0x12] ^ (byte)(param_3 >> 0x18);
      param_1[0x13] = param_1[0x13] ^ (byte)(param_3 >> 0x10);
      bVar6 = ~param_1[0x10];
      param_1[0x14] = param_1[0x14] ^ bVar4;
      bVar7 = param_1[0x11] ^ 0xfe;
      param_1[0x15] = param_1[0x15] ^ (byte)param_3;
      uVar5 = 6;
    }
    param_1[0x11] = bVar7;
    param_1[0x10] = bVar6;
    while( true ) {
      for (; (uVar5 < 0x10 && (param_3 != 0)); param_3 = param_3 - 1) {
        bVar4 = *param_2;
        param_2 = param_2 + 1;
        param_1[uVar5 + 0x10] = param_1[uVar5 + 0x10] ^ bVar4;
        uVar5 = uVar5 + 1;
      }
      (*pcVar3)(pbVar1,pbVar1,*(undefined4 *)(param_1 + 0x2c));
      puVar2 = (uint *)(param_1 + 0x20);
      uVar5 = *puVar2;
      *puVar2 = *puVar2 + 1;
      *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar5);
      if (param_3 == 0) break;
      uVar5 = 0;
    }
  }
  return;
}

