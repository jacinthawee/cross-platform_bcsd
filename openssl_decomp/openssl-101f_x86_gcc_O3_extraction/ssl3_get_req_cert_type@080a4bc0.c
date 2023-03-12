
int ssl3_get_req_cert_type(int *param_1,undefined *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  iVar1 = *param_1;
  uVar2 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc);
  if ((iVar1 < 0x301) || ((uVar2 & 0x200) == 0)) {
    if ((uVar2 & 10) == 0) {
      iVar6 = 0;
      local_14 = 3;
      local_18 = 4;
      local_1c = 2;
      iVar4 = 1;
      iVar5 = 2;
      local_20 = 0;
    }
    else {
      *param_2 = 3;
      param_2[1] = 4;
      iVar4 = 3;
      iVar1 = *param_1;
      local_14 = 5;
      iVar5 = 4;
      local_18 = 6;
      local_1c = 4;
      iVar6 = 2;
      local_20 = 2;
    }
    iVar3 = iVar5;
    if ((iVar1 == 0x300) && ((uVar2 & 0xe) != 0)) {
      param_2[iVar6] = 5;
      param_2[iVar4] = 6;
      iVar4 = local_14;
      iVar3 = local_18;
      iVar6 = local_1c;
      local_20 = iVar5;
    }
    param_2[iVar6] = 1;
    param_2[iVar4] = 2;
    if ((uVar2 & 0x60) != 0) {
      if (*param_1 < 0x301) {
        return iVar3;
      }
      param_2[iVar3] = 0x41;
      iVar3 = local_20 + 4;
      param_2[local_20 + 3] = 0x42;
    }
    if (0x300 < *param_1) {
      param_2[iVar3] = 0x40;
      return iVar3 + 1;
    }
  }
  else {
    *param_2 = 0x15;
    param_2[1] = 0x16;
    iVar3 = 2;
  }
  return iVar3;
}

