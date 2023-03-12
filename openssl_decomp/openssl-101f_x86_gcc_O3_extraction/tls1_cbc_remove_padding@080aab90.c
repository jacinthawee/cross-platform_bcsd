
uint tls1_cbc_remove_padding(int *param_1,uint *param_2,int param_3,int param_4)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  uint *puVar4;
  ulong uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint local_24;
  
  uVar8 = param_4 + 1;
  uVar10 = param_2[1];
  if ((*param_1 < 0x302) && (*param_1 != 0x100)) {
    if (uVar10 < uVar8) {
      return 0;
    }
    uVar6 = param_2[3];
  }
  else {
    if (uVar10 < uVar8 + param_3) {
      return 0;
    }
    param_2[4] = param_2[4] + param_3;
    uVar10 = uVar10 - param_3;
    param_2[1] = uVar10;
    uVar6 = param_2[3] + param_3;
    param_2[3] = uVar6;
  }
  bVar3 = *(byte *)((uVar6 - 1) + uVar10);
  uVar10 = (uint)bVar3;
  if (((*(byte *)((int)param_1 + 0x101) & 2) != 0) && (param_1[0x22] == 0)) {
    puVar4 = (uint *)param_1[0x16];
    iVar9 = memcmp(puVar4 + 2,"",8);
    uVar6 = *puVar4;
    if ((iVar9 == 0) && ((bVar3 & 1) == 0)) {
      uVar6 = uVar6 | 8;
      *puVar4 = uVar6;
    }
    if ((uVar6 & 8) != 0) {
      uVar10 = (uVar10 - 1) + (uint)(uVar10 == 0);
    }
  }
  uVar5 = EVP_CIPHER_flags(*(EVP_CIPHER **)param_1[0x20]);
  if ((uVar5 & 0x200000) != 0) {
    param_2[1] = param_2[1] + ~uVar10;
    return 1;
  }
  uVar6 = param_2[1];
  local_24 = uVar6 - 1;
  uVar8 = (int)~((uVar6 - uVar8) - uVar10) >> 0x1f;
  if (local_24 < 0xff) {
    if (local_24 == 0) goto LAB_080aac95;
  }
  else {
    local_24 = 0xff;
  }
  iVar9 = uVar6 + param_2[3];
  uVar7 = 0;
  do {
    pbVar1 = (byte *)(iVar9 + -1);
    iVar2 = ~uVar10 + uVar7;
    iVar9 = iVar9 + -1;
    uVar7 = uVar7 + 1;
    uVar8 = uVar8 & ~((*pbVar1 ^ uVar10) & iVar2 >> 0x1f & 0xffU);
  } while (uVar7 < local_24);
LAB_080aac95:
  uVar8 = uVar8 & uVar8 >> 4;
  uVar8 = uVar8 & uVar8 >> 2;
  uVar8 = (int)((uVar8 & uVar8 >> 1) << 0x1f) >> 0x1f;
  uVar10 = uVar10 + 1 & uVar8;
  *param_2 = *param_2 | uVar10 << 8;
  param_2[1] = uVar6 - uVar10;
  return uVar8 & 1 | ~uVar8;
}

