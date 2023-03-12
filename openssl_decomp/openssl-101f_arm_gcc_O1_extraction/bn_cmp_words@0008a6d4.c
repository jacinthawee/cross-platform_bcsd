
undefined4 bn_cmp_words(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  iVar2 = param_3 + 0x3fffffff;
  uVar5 = *(uint *)(param_1 + iVar2 * 4);
  uVar3 = *(uint *)(param_2 + iVar2 * 4);
  if (uVar5 != uVar3) {
    if (uVar3 < uVar5) {
      return 1;
    }
    return 0xffffffff;
  }
  param_3 = param_3 + -2;
  if (-1 < param_3) {
    iVar4 = iVar2 * 4 + -4;
    uVar5 = *(uint *)(param_1 + iVar4);
    uVar3 = *(uint *)(param_2 + iVar4);
    if (uVar5 == uVar3) {
      iVar4 = iVar2 * 4 + 4;
      iVar2 = 0;
      do {
        bVar7 = param_3 == 0;
        param_3 = param_3 + -1;
        iVar6 = param_1 + iVar4 + iVar2;
        iVar2 = iVar2 + -4;
        if (bVar7) {
          return 0;
        }
        uVar5 = *(uint *)(iVar6 + -0xc);
        uVar3 = *(uint *)(param_2 + iVar4 + iVar2 + -8);
      } while (uVar5 == uVar3);
    }
    if (uVar3 < uVar5) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0xffffffff;
    }
    return uVar1;
  }
  return 0;
}

