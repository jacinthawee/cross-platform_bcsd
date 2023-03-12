
undefined4 bn_cmp_part_words(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if (param_4 < 0) {
    piVar4 = (int *)(param_2 + (param_3 - param_4) * 4 + -4);
    iVar2 = *piVar4;
    param_4 = param_4 + 1;
    while( true ) {
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      bVar1 = param_4 == 0;
      param_4 = param_4 + 1;
      if (bVar1) break;
      iVar2 = piVar4[-1];
      piVar4 = piVar4 + -1;
    }
  }
  else if (param_4 != 0) {
    iVar2 = param_1 + (param_3 + param_4) * 4;
    do {
      piVar4 = (int *)(iVar2 + -4);
      param_4 = param_4 + -1;
      iVar2 = iVar2 + -4;
      if (*piVar4 != 0) {
        return 1;
      }
    } while (param_4 != 0);
  }
  iVar2 = param_3 * 4;
  uVar3 = *(uint *)(param_1 + iVar2 + -4);
  uVar6 = *(uint *)(param_2 + iVar2 + -4);
  if (uVar3 == uVar6) {
    param_3 = param_3 + -2;
    if (param_3 < 0) {
      return 0;
    }
    uVar6 = *(uint *)(param_1 + iVar2 + -8);
    uVar3 = *(uint *)(param_2 + iVar2 + -8);
    if (uVar6 == uVar3) {
      param_1 = param_1 + iVar2;
      iVar2 = param_2 + iVar2;
      do {
        param_3 = param_3 + -1;
        if (param_3 == -1) {
          return 0;
        }
        uVar6 = *(uint *)(param_1 + -0xc);
        uVar3 = *(uint *)(iVar2 + -0xc);
        param_1 = param_1 + -4;
        iVar2 = iVar2 + -4;
      } while (uVar6 == uVar3);
    }
    uVar5 = 1;
    if (uVar6 <= uVar3) {
      uVar5 = 0xffffffff;
    }
    return uVar5;
  }
  uVar5 = 1;
  if (uVar3 <= uVar6) {
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

