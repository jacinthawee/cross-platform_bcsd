
undefined4 tls1_cbc_remove_padding(int *param_1,uint *param_2,int param_3,int param_4)

{
  ulong uVar1;
  byte *pbVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  uVar10 = param_4 + 1;
  uVar8 = param_2[1];
  if (*param_1 == 0x100 || 0x301 < *param_1) {
    if (uVar8 < uVar10 + param_3) {
      return 0;
    }
    uVar8 = uVar8 - param_3;
    uVar5 = param_2[3] + param_3;
    param_2[1] = uVar8;
    param_2[3] = uVar5;
    param_2[4] = param_3 + param_2[4];
  }
  else {
    if (uVar8 < uVar10) {
      return 0;
    }
    uVar5 = param_2[3];
  }
  uVar8 = (uint)*(byte *)(uVar8 + uVar5 + -1);
  if ((param_1[0x40] << 0x16 < 0) && (param_1[0x22] == 0)) {
    iVar4 = CRYPTO_memcmp((void *)(param_1[0x16] + 8),&DAT_00138fec,8);
    if ((iVar4 == 0) && (-1 < (int)(uVar8 << 0x1f))) {
      uVar5 = *(uint *)param_1[0x16] | 8;
      *(uint *)param_1[0x16] = uVar5;
    }
    else {
      uVar5 = *(uint *)param_1[0x16];
    }
    if (((int)(uVar5 << 0x1c) < 0) && (uVar8 != 0)) {
      uVar8 = uVar8 - 1;
    }
  }
  uVar1 = EVP_CIPHER_flags(*(EVP_CIPHER **)param_1[0x20]);
  if ((int)(uVar1 << 10) < 0) {
    param_2[1] = (param_2[1] - 1) - uVar8;
    return 1;
  }
  uVar5 = param_2[1];
  uVar10 = uVar10 + uVar8;
  uVar12 = uVar5 - 1;
  uVar10 = ~((int)((uVar5 - uVar10 ^ uVar10 | uVar10 ^ uVar5) ^ uVar5) >> 0x1f);
  bVar7 = (byte)uVar10;
  if (uVar12 < 0xff) {
    if (uVar12 == 0) goto LAB_000508c8;
  }
  else {
    uVar12 = 0xff;
  }
  uVar9 = 0;
  pbVar2 = (byte *)(param_2[3] + uVar5);
  do {
    uVar6 = uVar9 ^ uVar8;
    uVar11 = uVar8 - uVar9 ^ uVar9;
    pbVar2 = pbVar2 + -1;
    uVar9 = uVar9 + 1;
    uVar10 = uVar10 & ~((*pbVar2 ^ uVar8) & ~((int)((uVar11 | uVar6) ^ uVar8) >> 0x1f));
    bVar7 = (byte)uVar10;
  } while (uVar9 < uVar12);
LAB_000508c8:
  uVar10 = (bVar7 ^ 0xff) - 1 & ~(bVar7 ^ 0xff);
  uVar8 = uVar8 + 1 & (int)uVar10 >> 0x1f;
  if ((int)uVar10 < 0) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0xffffffff;
  }
  param_2[1] = uVar5 - uVar8;
  *param_2 = *param_2 | uVar8 << 8;
  return uVar3;
}

