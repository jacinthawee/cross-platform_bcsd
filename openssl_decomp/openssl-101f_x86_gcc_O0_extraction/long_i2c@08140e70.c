
int long_i2c(uint *param_1,char *param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar1 = *param_1;
  if (*(uint *)(param_4 + 0x14) == uVar1) {
    return -1;
  }
  uVar5 = uVar1 ^ (int)uVar1 >> 0x1f;
  uVar2 = BN_num_bits_word(uVar5);
  if ((uVar2 & 7) == 0) {
    iVar6 = 1;
    iVar3 = (int)(uVar2 + 7) >> 3;
    if (param_2 == (char *)0x0) goto LAB_08140ee6;
    iVar6 = 1;
    *param_2 = (char)((int)uVar1 >> 0x1f);
    param_2 = param_2 + 1;
  }
  else {
    iVar6 = 0;
    iVar3 = (int)(uVar2 + 7) >> 3;
    if (param_2 == (char *)0x0) goto LAB_08140ee6;
  }
  iVar4 = iVar3 + -1;
  if (-1 < iVar4) {
    if ((int)uVar1 < 0) {
      do {
        param_2[iVar4] = ~(byte)uVar5;
        iVar4 = iVar4 + -1;
        uVar5 = uVar5 >> 8;
      } while (iVar4 != -1);
    }
    else {
      do {
        param_2[iVar4] = (char)uVar5;
        iVar4 = iVar4 + -1;
        uVar5 = uVar5 >> 8;
      } while (iVar4 != -1);
    }
  }
LAB_08140ee6:
  return iVar3 + iVar6;
}

