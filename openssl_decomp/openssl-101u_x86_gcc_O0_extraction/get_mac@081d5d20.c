
void get_mac(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = (int)param_2 >> 3;
  if ((int)uVar1 < 1) {
    uVar1 = 0;
  }
  else if ((((param_3 | param_1) & 3) == 0 && 9 < uVar1) &&
          (param_1 + 4 <= param_3 || param_3 + 4 <= param_1)) {
    uVar3 = 0;
    uVar2 = (uVar1 - 4 >> 2) + 1;
    uVar4 = uVar2 * 4;
    do {
      *(undefined4 *)(param_3 + uVar3 * 4) = *(undefined4 *)(param_1 + uVar3 * 4);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
    if (((uVar1 != uVar4) &&
        (*(undefined *)(param_3 + uVar2 * 4) = *(undefined *)(param_1 + uVar2 * 4),
        (int)(uVar4 + 1) < (int)uVar1)) &&
       (*(undefined *)(param_3 + 1 + uVar4) = *(undefined *)(param_1 + 1 + uVar4),
       (int)(uVar4 + 2) < (int)uVar1)) {
      *(undefined *)(param_3 + 2 + uVar4) = *(undefined *)(param_1 + 2 + uVar4);
    }
  }
  else {
    uVar4 = 0;
    do {
      *(undefined *)(param_3 + uVar4) = *(undefined *)(param_1 + uVar4);
      uVar4 = uVar4 + 1;
    } while (uVar1 != uVar4);
  }
  if ((param_2 & 7) != 0) {
    *(byte *)(param_3 + uVar1) = -((param_2 & 7) == 1) & *(byte *)(param_1 + uVar1);
  }
  return;
}

