
int bn_cmp_words(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = param_3 + 0x3fffffff;
  uVar3 = *(uint *)(param_1 + iVar1 * 4);
  uVar2 = *(uint *)(param_2 + iVar1 * 4);
  if (uVar3 != uVar2) {
    return (-(uint)(uVar2 < uVar3) & 2) - 1;
  }
  param_3 = param_3 + -2;
  if (-1 < param_3) {
    uVar3 = *(uint *)(param_1 + -4 + iVar1 * 4);
    uVar2 = *(uint *)(param_2 + -4 + iVar1 * 4);
    if (uVar2 == uVar3) {
      do {
        param_3 = param_3 + -1;
        if (param_3 == -1) {
          return 0;
        }
        uVar3 = *(uint *)(param_1 + param_3 * 4);
        uVar2 = *(uint *)(param_2 + param_3 * 4);
      } while (uVar3 == uVar2);
    }
    return (-(uint)(uVar2 < uVar3) & 2) - 1;
  }
  return 0;
}

