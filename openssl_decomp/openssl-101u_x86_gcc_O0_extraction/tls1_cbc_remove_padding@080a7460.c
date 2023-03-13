
uint tls1_cbc_remove_padding(int *param_1,uint *param_2,int param_3,int param_4)

{
  byte *pbVar1;
  byte bVar2;
  ulong uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_24;
  
  uVar11 = param_4 + 1;
  if ((*param_1 < 0x302) && (*param_1 != 0x100)) {
    uVar9 = param_2[1];
    if (uVar9 < uVar11) {
      return 0;
    }
    uVar6 = param_2[3];
  }
  else {
    if (param_2[1] < uVar11 + param_3) {
      return 0;
    }
    uVar9 = param_2[1] - param_3;
    param_2[4] = param_2[4] + param_3;
    param_2[1] = uVar9;
    uVar6 = param_2[3] + param_3;
    param_2[3] = uVar6;
  }
  bVar2 = *(byte *)((uVar6 - 1) + uVar9);
  uVar9 = (uint)bVar2;
  if (((*(byte *)((int)param_1 + 0x101) & 2) != 0) && (param_1[0x22] == 0)) {
    iVar5 = CRYPTO_memcmp((void *)(param_1[0x16] + 8),"",8);
    if ((iVar5 == 0) && ((bVar2 & 1) == 0)) {
      uVar6 = *(uint *)param_1[0x16] | 8;
      *(uint *)param_1[0x16] = uVar6;
    }
    else {
      uVar6 = *(uint *)param_1[0x16];
    }
    if ((uVar6 & 8) != 0) {
      uVar9 = (uVar9 - 1) + (uint)(uVar9 == 0);
    }
  }
  uVar3 = EVP_CIPHER_flags(*(EVP_CIPHER **)param_1[0x20]);
  if ((uVar3 & 0x200000) != 0) {
    param_2[1] = param_2[1] + ~uVar9;
    return 1;
  }
  uVar11 = uVar11 + uVar9;
  uVar6 = param_2[1];
  local_24 = uVar6 - 1;
  uVar11 = ~((int)((uVar6 - uVar11 ^ uVar11 | uVar11 ^ uVar6) ^ uVar6) >> 0x1f);
  if (local_24 < 0xff) {
    if (local_24 == 0) goto LAB_080a7530;
  }
  else {
    local_24 = 0xff;
  }
  uVar7 = 0;
  uVar10 = uVar9;
  do {
    uVar8 = uVar9 ^ uVar7;
    uVar4 = uVar7 ^ uVar10;
    uVar7 = uVar7 + 1;
    pbVar1 = (byte *)((uVar6 - uVar9) + param_2[3] + -1 + uVar10);
    uVar10 = uVar10 - 1;
    uVar11 = uVar11 & ~(~((int)((uVar4 | uVar8) ^ uVar9) >> 0x1f) & (*pbVar1 ^ uVar9));
  } while (uVar7 < local_24);
LAB_080a7530:
  uVar11 = uVar11 & 0xff ^ 0xff;
  uVar10 = (int)(uVar11 - 1 & ~uVar11) >> 0x1f;
  uVar11 = uVar9 + 1 & uVar10;
  *param_2 = *param_2 | uVar11 << 8;
  param_2[1] = uVar6 - uVar11;
  return ~(uVar10 & 0xfffffffe);
}

