
uint ssl3_get_req_cert_type(int *param_1,undefined *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  iVar1 = *param_1;
  uVar2 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  if ((0x300 < iVar1) && ((int)(uVar2 << 0x16) < 0)) {
    *param_2 = 0x15;
    param_2[1] = 0x16;
    return 2;
  }
  uVar3 = uVar2 & 10;
  if (uVar3 == 0) {
    uVar7 = 2;
    uVar4 = 2;
    iVar9 = 3;
    uVar8 = 4;
    iVar6 = 1;
  }
  else {
    uVar4 = 4;
    iVar6 = 3;
    param_2[1] = 4;
    *param_2 = 3;
    uVar3 = 2;
    iVar1 = *param_1;
    uVar7 = 4;
    iVar9 = 5;
    uVar8 = 6;
  }
  uVar5 = uVar4;
  uVar10 = uVar3;
  if ((iVar1 == 0x300) && ((uVar2 & 0xe) != 0)) {
    param_2[uVar3] = 5;
    param_2[iVar6] = 6;
    uVar3 = uVar7;
    uVar5 = uVar8;
    iVar6 = iVar9;
    uVar10 = uVar4;
  }
  param_2[uVar3] = 1;
  param_2[iVar6] = 2;
  if ((uVar2 & 0x60) != 0) {
    if (*param_1 < 0x301) {
      return uVar5;
    }
    param_2[uVar5] = 0x41;
    uVar5 = uVar10 + 4;
    param_2[uVar10 + 3] = 0x42;
  }
  if (*param_1 < 0x301) {
    return uVar5;
  }
  param_2[uVar5] = 0x40;
  return uVar5 + 1;
}

