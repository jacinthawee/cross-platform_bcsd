
int ssl3_get_req_cert_type(int *param_1,undefined *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar6 = *param_1;
  uVar3 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  if ((0x300 < iVar6) && ((uVar3 & 0x200) != 0)) {
    *param_2 = 0x15;
    param_2[1] = 0x16;
    return 2;
  }
  if ((uVar3 & 10) == 0) {
    iVar10 = 3;
    iVar8 = 4;
    iVar9 = 2;
    iVar4 = 1;
    iVar1 = 2;
    iVar5 = 0;
    iVar7 = 0;
  }
  else {
    iVar10 = 5;
    *param_2 = 3;
    iVar8 = 6;
    iVar9 = 4;
    param_2[1] = 4;
    iVar4 = 3;
    iVar6 = *param_1;
    iVar1 = 4;
    iVar5 = 2;
    iVar7 = 2;
  }
  iVar2 = iVar1;
  if ((iVar6 == 0x300) && ((uVar3 & 0xe) != 0)) {
    param_2[iVar5] = 5;
    param_2[iVar4] = 6;
    iVar2 = iVar8;
    iVar4 = iVar10;
    iVar5 = iVar9;
    iVar7 = iVar1;
  }
  param_2[iVar5] = 1;
  param_2[iVar4] = 2;
  if ((uVar3 & 0x60) != 0) {
    if (*param_1 < 0x301) {
      return iVar2;
    }
    param_2[iVar2] = 0x41;
    iVar2 = iVar7 + 4;
    param_2[iVar7 + 3] = 0x42;
  }
  if (0x300 < *param_1) {
    param_2 = param_2 + iVar2;
    iVar2 = iVar2 + 1;
    *param_2 = 0x40;
  }
  return iVar2;
}

