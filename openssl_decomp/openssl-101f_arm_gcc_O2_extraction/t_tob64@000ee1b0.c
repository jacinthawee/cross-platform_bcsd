
void t_tob64(char *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  
  iVar4 = param_3 % 3;
  if (iVar4 == 1) {
    uVar3 = (uint)*param_2;
    uVar7 = 0;
  }
  else if (iVar4 == 2) {
    uVar7 = (uint)*param_2;
    uVar3 = (uint)param_2[1];
  }
  else {
    uVar3 = 0;
    uVar7 = 0;
  }
  uVar6 = 0;
  uVar2 = 0;
  pbVar1 = param_2 + iVar4;
  do {
    uVar6 = uVar6 & 1;
    if (uVar2 >> 2 != 0) {
      uVar6 = 1;
    }
    if (uVar6 == 0) {
      uVar6 = uVar7 >> 4 | (uVar2 & 3) << 4;
      if (uVar6 != 0) goto LAB_000ee208;
      uVar7 = uVar3 >> 6 | (uVar7 & 0xf) << 2;
      pcVar5 = param_1;
      if (uVar7 != 0) goto LAB_000ee21e;
      uVar6 = uVar3 & 0x3f;
      if (uVar6 != 0) goto LAB_000ee22c;
    }
    else {
      uVar6 = uVar7 >> 4 | (uVar2 & 3) << 4;
      *param_1 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./"[uVar2 >> 2];
      param_1 = param_1 + 1;
LAB_000ee208:
      uVar7 = uVar3 >> 6 | (uVar7 & 0xf) << 2;
      *param_1 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./"[uVar6];
      pcVar5 = param_1 + 1;
LAB_000ee21e:
      param_1 = pcVar5 + 1;
      *pcVar5 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./"[uVar7];
LAB_000ee22c:
      uVar6 = 1;
      *param_1 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./"[uVar3 & 0x3f];
      param_1 = param_1 + 1;
    }
    if (param_3 <= iVar4) {
      *param_1 = '\0';
      return;
    }
    uVar2 = (uint)*pbVar1;
    iVar4 = iVar4 + 3;
    uVar7 = (uint)pbVar1[1];
    uVar3 = (uint)pbVar1[2];
    pbVar1 = pbVar1 + 3;
  } while( true );
}

