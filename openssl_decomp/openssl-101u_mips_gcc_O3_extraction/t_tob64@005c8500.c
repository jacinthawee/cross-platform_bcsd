
void t_tob64(char *param_1,byte *param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  
  iVar9 = param_3 % 3;
  if (iVar9 == 1) {
    uVar7 = (uint)*param_2;
    uVar3 = 0;
  }
  else if (iVar9 == 2) {
    uVar3 = (uint)*param_2;
    uVar7 = (uint)param_2[1];
  }
  else {
    uVar7 = 0;
    uVar3 = 0;
  }
  bVar2 = false;
  uVar5 = 0;
  pbVar4 = param_2 + iVar9;
  do {
    if ((bVar2) || (uVar5 >> 2 != 0)) {
      uVar6 = (uVar5 & 3) << 4 | uVar3 >> 4;
      *param_1 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./"[uVar5 >> 2];
      param_1 = param_1 + 1;
LAB_005c8580:
      uVar3 = (uVar3 & 0xf) << 2 | uVar7 >> 6;
      *param_1 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./"[uVar6];
      pcVar8 = param_1 + 1;
LAB_005c85a4:
      param_1 = pcVar8 + 1;
      *pcVar8 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./"[uVar3];
LAB_005c85b4:
      bVar2 = true;
      *param_1 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./"[uVar7 & 0x3f];
      param_1 = param_1 + 1;
    }
    else {
      uVar6 = uVar3 >> 4 | uVar5 << 4;
      if (uVar6 != 0) goto LAB_005c8580;
      uVar3 = (uVar3 & 0xf) << 2 | uVar7 >> 6;
      pcVar8 = param_1;
      if (uVar3 != 0) goto LAB_005c85a4;
      if ((uVar7 & 0x3f) != 0) goto LAB_005c85b4;
    }
    bVar1 = param_3 <= iVar9;
    iVar9 = iVar9 + 3;
    if (bVar1) {
      *param_1 = '\0';
      return;
    }
    uVar5 = (uint)*pbVar4;
    uVar3 = (uint)pbVar4[1];
    uVar7 = (uint)pbVar4[2];
    pbVar4 = pbVar4 + 3;
  } while( true );
}

