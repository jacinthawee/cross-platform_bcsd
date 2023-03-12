
void get_mac(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  
  uVar4 = (int)param_2 >> 3;
  param_2 = param_2 & 7;
  bVar6 = (byte)param_2;
  if ((param_2 != 0) && (bVar6 = 0xff, param_2 != 1)) {
    bVar6 = 0;
  }
  if ((int)uVar4 < 1) {
    uVar4 = 0;
  }
  else {
    uVar1 = (uint)(((param_3 | param_1) & 3) == 0);
    if (uVar4 < 10) {
      uVar1 = 0;
    }
    uVar1 = uVar1 & (param_1 + 4 <= param_3 || param_3 + 4 <= param_1);
    if (uVar1 == 0) {
      do {
        *(undefined *)(param_3 + uVar1) = *(undefined *)(param_1 + uVar1);
        uVar5 = uVar1 + 1;
        if (uVar5 == uVar4) break;
        *(undefined *)(param_3 + uVar5) = *(undefined *)(param_1 + uVar5);
        uVar1 = uVar1 + 2;
      } while (uVar1 != uVar4);
    }
    else {
      iVar2 = 0;
      uVar1 = 0;
      uVar5 = uVar4 & 0xfffffffc;
      do {
        uVar1 = uVar1 + 1;
        *(undefined4 *)(param_3 + iVar2) = *(undefined4 *)(param_1 + iVar2);
        iVar2 = iVar2 + 4;
      } while (uVar1 < uVar4 >> 2);
      if (uVar4 != uVar5) {
        iVar2 = uVar5 + 1;
        *(undefined *)(param_3 + (uVar4 & 0xfffffffc)) =
             *(undefined *)(param_1 + (uVar4 & 0xfffffffc));
        if (iVar2 < (int)uVar4) {
          iVar3 = uVar5 + 2;
          *(undefined *)(param_3 + iVar2) = *(undefined *)(param_1 + iVar2);
          if (iVar3 < (int)uVar4) {
            *(undefined *)(param_3 + iVar3) = *(undefined *)(param_1 + iVar3);
          }
        }
      }
    }
  }
  if (param_2 != 0) {
    *(byte *)(param_3 + uVar4) = *(byte *)(param_1 + uVar4) & bVar6;
  }
  return;
}

