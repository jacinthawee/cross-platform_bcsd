
undefined4 MDC2_Final(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = *param_2;
  uVar4 = count_leading_zeroes(param_2[7] + -2);
  uVar4 = uVar4 >> 5;
  uVar1 = uVar4;
  if (iVar2 != 0) {
    uVar1 = uVar4 | 1;
  }
  if (uVar1 != 0) {
    iVar3 = iVar2;
    if (uVar4 != 0) {
      iVar3 = iVar2 + 1;
      *(undefined *)((int)param_2 + iVar2 + 4) = 0x80;
    }
    memset((void *)((int)param_2 + iVar3 + 4),0,8 - iVar3);
    mdc2_body(param_2,param_2 + 1,8);
  }
  iVar2 = param_2[4];
  *param_1 = param_2[3];
  param_1[1] = iVar2;
  iVar2 = param_2[6];
  param_1[2] = param_2[5];
  param_1[3] = iVar2;
  return 1;
}

