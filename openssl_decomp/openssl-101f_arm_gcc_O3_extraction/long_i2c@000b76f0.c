
int long_i2c(uint *param_1,char *param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  
  uVar1 = *param_1;
  if (*(uint *)(param_4 + 0x14) == uVar1) {
    iVar3 = -1;
  }
  else {
    uVar6 = ~uVar1;
    if ((int)~uVar1 < (int)uVar1) {
      uVar6 = uVar1;
    }
    uVar2 = BN_num_bits_word(uVar6);
    uVar8 = (uint)((uVar2 & 7) == 0);
    iVar3 = (int)(uVar2 + 7) >> 3;
    if (param_2 != (char *)0x0) {
      pcVar7 = param_2;
      if (uVar8 != 0) {
        pcVar7 = param_2 + 1;
        *param_2 = (char)((int)uVar1 >> 0x1f);
      }
      iVar5 = iVar3 + -1;
      if (-1 < iVar5) {
        pbVar4 = (byte *)(pcVar7 + iVar3);
        if ((int)uVar1 < 0) {
          do {
            iVar5 = iVar5 + -1;
            pbVar4 = pbVar4 + -1;
            *pbVar4 = ~(byte)uVar6;
            uVar6 = uVar6 >> 8;
          } while (iVar5 != -1);
        }
        else {
          do {
            iVar5 = iVar5 + -1;
            pbVar4 = pbVar4 + -1;
            *pbVar4 = (byte)uVar6;
            uVar6 = uVar6 >> 8;
          } while (iVar5 != -1);
        }
      }
    }
    iVar3 = iVar3 + uVar8;
  }
  return iVar3;
}

