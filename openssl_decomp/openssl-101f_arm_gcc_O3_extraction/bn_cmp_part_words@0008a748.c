
undefined4 bn_cmp_part_words(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  bool bVar8;
  
  if (param_4 < 0) {
    piVar6 = (int *)(param_2 + (param_3 - param_4) * 4);
    do {
      piVar6 = piVar6 + -1;
      if (*piVar6 != 0) goto LAB_0008a776;
      param_4 = param_4 + 1;
    } while (param_4 != 0);
  }
  else if (param_4 != 0) {
    piVar6 = (int *)(param_1 + (param_3 + param_4) * 4);
    do {
      piVar6 = piVar6 + -1;
      if (*piVar6 != 0) {
        return 1;
      }
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  iVar3 = param_3 + 0x3fffffff;
  uVar7 = *(uint *)(param_1 + iVar3 * 4);
  uVar4 = *(uint *)(param_2 + iVar3 * 4);
  if (uVar7 == uVar4) {
    param_3 = param_3 + -2;
    if (param_3 < 0) {
LAB_0008a7d0:
      uVar1 = 0;
    }
    else {
      iVar5 = iVar3 * 4 + -4;
      uVar7 = *(uint *)(param_1 + iVar5);
      uVar4 = *(uint *)(param_2 + iVar5);
      if (uVar7 == uVar4) {
        iVar5 = iVar3 * 4 + 4;
        iVar3 = 0;
        do {
          bVar8 = param_3 == 0;
          param_3 = param_3 + -1;
          iVar2 = param_1 + iVar5 + iVar3;
          iVar3 = iVar3 + -4;
          if (bVar8) goto LAB_0008a7d0;
          uVar7 = *(uint *)(iVar2 + -0xc);
          uVar4 = *(uint *)(iVar5 + param_2 + iVar3 + -8);
        } while (uVar7 == uVar4);
      }
      if (uVar4 < uVar7) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0xffffffff;
      }
    }
  }
  else {
    if (uVar4 <= uVar7 && uVar7 != uVar4) {
      return 1;
    }
LAB_0008a776:
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

