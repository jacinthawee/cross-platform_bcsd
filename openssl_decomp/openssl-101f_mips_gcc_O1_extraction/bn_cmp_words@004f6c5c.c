
undefined4 bn_cmp_words(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = param_3 * 4;
  uVar1 = *(uint *)(param_1 + iVar4 + -4);
  uVar3 = *(uint *)(param_2 + iVar4 + -4);
  if (uVar1 == uVar3) {
    param_3 = param_3 + -2;
    if (param_3 < 0) {
      return 0;
    }
    uVar3 = *(uint *)(param_2 + iVar4 + -8);
    uVar1 = *(uint *)(param_1 + iVar4 + -8);
    if (uVar3 == uVar1) {
      param_1 = param_1 + iVar4;
      iVar4 = param_2 + iVar4;
      do {
        param_3 = param_3 + -1;
        if (param_3 == -1) {
          return 0;
        }
        uVar1 = *(uint *)(param_1 + -0xc);
        uVar3 = *(uint *)(iVar4 + -0xc);
        param_1 = param_1 + -4;
        iVar4 = iVar4 + -4;
      } while (uVar1 == uVar3);
    }
  }
  uVar2 = 1;
  if (uVar1 <= uVar3) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

