
uint tls1_cbc_remove_padding(int *param_1,uint *param_2,int param_3,int param_4)

{
  ulong uVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  
  uVar6 = param_4 + 1;
  uVar4 = param_2[1];
  if (*param_1 == 0x100 || 0x301 < *param_1) {
    if (uVar4 < uVar6 + param_3) {
      return 0;
    }
    uVar4 = uVar4 - param_3;
    uVar3 = param_2[3] + param_3;
    param_2[1] = uVar4;
    param_2[3] = uVar3;
    param_2[4] = param_3 + param_2[4];
  }
  else {
    if (uVar4 < uVar6) {
      return 0;
    }
    uVar3 = param_2[3];
  }
  uVar4 = (uint)*(byte *)(uVar4 + uVar3 + -1);
  if ((param_1[0x40] << 0x16 < 0) && (param_1[0x22] == 0)) {
    puVar8 = (uint *)param_1[0x16];
    iVar7 = memcmp(puVar8 + 2,&DAT_0013a1f0,8);
    uVar3 = *puVar8;
    if ((iVar7 == 0) && (-1 < (int)(uVar4 << 0x1f))) {
      uVar3 = uVar3 | 8;
      *puVar8 = uVar3;
    }
    if (((int)(uVar3 << 0x1c) < 0) && (uVar4 != 0)) {
      uVar4 = uVar4 - 1;
    }
  }
  uVar1 = EVP_CIPHER_flags(*(EVP_CIPHER **)param_1[0x20]);
  if ((int)(uVar1 << 10) < 0) {
    param_2[1] = (param_2[1] - 1) - uVar4;
    return 1;
  }
  uVar9 = param_2[1];
  uVar3 = uVar9 - 1;
  uVar6 = (int)~((uVar9 - uVar6) - uVar4) >> 0x1f;
  if (uVar3 < 0xff) {
    if (uVar3 == 0) goto LAB_000532ea;
  }
  else {
    uVar3 = 0xff;
  }
  uVar5 = 0;
  pbVar2 = (byte *)(param_2[3] + uVar9);
  do {
    pbVar2 = pbVar2 + -1;
    iVar7 = ~uVar4 + uVar5;
    uVar5 = uVar5 + 1;
    uVar6 = uVar6 & ~((*pbVar2 ^ uVar4) & iVar7 >> 0x1f);
  } while (uVar5 < uVar3);
LAB_000532ea:
  uVar6 = uVar6 & uVar6 >> 4;
  uVar6 = uVar6 & uVar6 >> 2;
  uVar6 = (int)((uVar6 & uVar6 >> 1) << 0x1f) >> 0x1f;
  uVar4 = uVar4 + 1 & uVar6;
  param_2[1] = uVar9 - uVar4;
  *param_2 = *param_2 | uVar4 << 8;
  return uVar6 & 1 | ~uVar6;
}

