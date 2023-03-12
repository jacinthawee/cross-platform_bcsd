
void gost_init(int param_1,undefined1 *param_2)

{
  uint uVar1;
  byte *pbVar2;
  int *piVar3;
  uint uVar4;
  
  if (param_2 == (undefined1 *)0x0) {
    param_2 = GostR3411_94_TestParamSet;
  }
  uVar4 = 0;
  piVar3 = (int *)(param_1 + 0x20);
  do {
    uVar1 = uVar4 & 0xf;
    pbVar2 = param_2 + ((int)uVar4 >> 4);
    uVar4 = uVar4 + 1;
    *piVar3 = ((uint)*pbVar2 << 4 | (uint)(byte)param_2[uVar1 + 0x10]) << 0x18;
    piVar3[0x100] = ((uint)pbVar2[0x20] << 4 | (uint)(byte)param_2[uVar1 + 0x30]) << 0x10;
    piVar3[0x200] = ((uint)pbVar2[0x40] << 4 | (uint)(byte)param_2[uVar1 + 0x50]) << 8;
    piVar3[0x300] = (uint)pbVar2[0x60] << 4 | (uint)(byte)param_2[uVar1 + 0x70];
    piVar3 = piVar3 + 1;
  } while (uVar4 != 0x100);
  return;
}

