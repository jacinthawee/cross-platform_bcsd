
uint tls1_cbc_remove_padding(int *param_1,uint *param_2,int param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  
  uVar8 = param_4 + 1;
  if ((*param_1 < 0x302) && (*param_1 != 0x100)) {
    uVar2 = param_2[1];
    if (uVar2 < uVar8) {
      return 0;
    }
    uVar5 = param_2[3];
  }
  else {
    uVar2 = param_2[1] - param_3;
    if (param_2[1] < uVar8 + param_3) {
      return 0;
    }
    uVar5 = param_2[3] + param_3;
    param_2[1] = uVar2;
    param_2[3] = uVar5;
    param_2[4] = param_2[4] + param_3;
  }
  bVar1 = *(byte *)(uVar5 + uVar2 + -1);
  uVar2 = (uint)bVar1;
  if (((param_1[0x40] & 0x200U) != 0) && (param_1[0x22] == 0)) {
    puVar9 = (uint *)param_1[0x16];
    iVar3 = (*(code *)PTR_memcmp_006aabd8)(puVar9 + 2,&DAT_00647940,8);
    if ((iVar3 == 0) && ((bVar1 & 1) == 0)) {
      uVar5 = *puVar9 | 8;
      *puVar9 = uVar5;
    }
    else {
      uVar5 = *puVar9;
    }
    if (((uVar5 & 8) != 0) && (uVar2 != 0)) {
      uVar2 = uVar2 - 1;
    }
  }
  iVar3 = (*(code *)PTR_EVP_CIPHER_flags_006a9270)(*(undefined4 *)param_1[0x20]);
  if (iVar3 << 10 < 0) {
    param_2[1] = (param_2[1] - 1) - uVar2;
    return 1;
  }
  uVar5 = param_2[1];
  uVar7 = uVar5 - 1;
  uVar8 = (int)~((uVar5 - uVar8) - uVar2) >> 0x1f;
  if (uVar7 < 0xff) {
    if (uVar7 == 0) {
      uVar7 = *param_2;
      goto LAB_00491fcc;
    }
  }
  else {
    uVar7 = 0xff;
  }
  uVar6 = 0;
  iVar3 = param_2[3] + uVar5;
  do {
    iVar4 = ~uVar2 + uVar6;
    uVar6 = uVar6 + 1;
    uVar8 = uVar8 & ~(iVar4 >> 0x1f & 0xffU & (*(byte *)(iVar3 + -1) ^ uVar2));
    iVar3 = iVar3 + -1;
  } while (uVar6 < uVar7);
  uVar7 = *param_2;
LAB_00491fcc:
  uVar8 = uVar8 >> 4 & uVar8;
  uVar8 = uVar8 & uVar8 >> 2;
  uVar8 = (int)((uVar8 & uVar8 >> 1) << 0x1f) >> 0x1f;
  uVar2 = uVar8 & uVar2 + 1;
  param_2[1] = uVar5 - uVar2;
  *param_2 = uVar7 | uVar2 << 8;
  return uVar8 & 1 | ~uVar8;
}

