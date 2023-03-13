
void gost_init(int param_1,undefined1 *param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_2 == (undefined1 *)0x0) {
    param_2 = GostR3411_94_TestParamSet;
  }
  piVar1 = (int *)(param_1 + 0x20);
  uVar3 = 0;
  do {
    uVar2 = uVar3 + 1;
    iVar4 = (int)uVar3 >> 4;
    uVar3 = uVar3 & 0xf;
    *piVar1 = ((uint)(byte)param_2[iVar4] << 4 | (uint)(byte)param_2[uVar3 + 0x10]) << 0x18;
    piVar1[0x100] =
         ((uint)(byte)param_2[iVar4 + 0x20] << 4 | (uint)(byte)param_2[uVar3 + 0x30]) << 0x10;
    piVar1[0x200] =
         ((uint)(byte)param_2[iVar4 + 0x40] << 4 | (uint)(byte)param_2[uVar3 + 0x50]) << 8;
    piVar1[0x300] = (uint)(byte)param_2[iVar4 + 0x60] << 4 | (uint)(byte)param_2[uVar3 + 0x70];
    piVar1 = piVar1 + 1;
    uVar3 = uVar2;
  } while (uVar2 != 0x100);
  return;
}

