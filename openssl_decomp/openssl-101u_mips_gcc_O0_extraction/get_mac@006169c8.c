
void get_mac(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined uVar4;
  undefined4 *puVar3;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  
  uVar8 = (int)param_2 >> 3;
  if ((int)uVar8 < 1) {
    uVar8 = 0;
  }
  else if (((((uint)param_3 | (uint)param_1) & 3) == 0 && 9 < uVar8) &&
          (param_1 + 1 <= param_3 || param_3 + 1 <= param_1)) {
    uVar9 = 0;
    uVar5 = (uVar8 - 4 >> 2) + 1;
    uVar1 = uVar5 * 4;
    puVar3 = param_3;
    puVar7 = param_1;
    do {
      uVar10 = *puVar7;
      uVar9 = uVar9 + 1;
      puVar7 = puVar7 + 1;
      *puVar3 = uVar10;
      puVar3 = puVar3 + 1;
    } while (uVar9 < uVar5);
    if (uVar8 != uVar1) {
      iVar6 = uVar1 + 1;
      *(undefined *)(param_3 + uVar5) = *(undefined *)(param_1 + uVar5);
      if (iVar6 < (int)uVar8) {
        iVar2 = uVar1 + 2;
        *(undefined *)((int)param_3 + iVar6) = *(undefined *)((int)param_1 + iVar6);
        if (iVar2 < (int)uVar8) {
          *(undefined *)((int)param_3 + iVar2) = *(undefined *)((int)param_1 + iVar2);
        }
      }
    }
  }
  else {
    puVar3 = param_1;
    puVar7 = param_3;
    do {
      uVar4 = *(undefined *)puVar3;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
      *(undefined *)puVar7 = uVar4;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    } while (puVar3 != (undefined4 *)((int)param_1 + uVar8));
  }
  if ((param_2 & 7) != 0) {
    uVar4 = *(undefined *)((int)param_1 + uVar8);
    if ((param_2 & 7) != 1) {
      uVar4 = 0;
    }
    *(undefined *)((int)param_3 + uVar8) = uVar4;
  }
  return;
}

