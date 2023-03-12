
int bn_cmp_part_words(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_4 < 0) {
    iVar2 = param_2 + (param_3 - param_4) * 4;
    iVar1 = *(int *)(iVar2 + -4);
    while( true ) {
      if (iVar1 != 0) {
        return -1;
      }
      param_4 = param_4 + 1;
      if (param_4 == 0) break;
      iVar1 = *(int *)(iVar2 + -8);
      iVar2 = iVar2 + -4;
    }
  }
  else if (param_4 != 0) {
    do {
      if (*(int *)(param_1 + param_3 * 4 + -4 + param_4 * 4) != 0) {
        return 1;
      }
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  iVar2 = param_3 + 0x3fffffff;
  uVar4 = *(uint *)(param_1 + iVar2 * 4);
  uVar3 = *(uint *)(param_2 + iVar2 * 4);
  if (uVar4 == uVar3) {
    param_3 = param_3 + -2;
    if (param_3 < 0) {
LAB_080f766a:
      iVar2 = 0;
    }
    else {
      uVar4 = *(uint *)(param_1 + -4 + iVar2 * 4);
      uVar3 = *(uint *)(param_2 + -4 + iVar2 * 4);
      if (uVar4 == uVar3) {
        do {
          param_3 = param_3 + -1;
          if (param_3 == -1) goto LAB_080f766a;
          uVar4 = *(uint *)(param_1 + param_3 * 4);
          uVar3 = *(uint *)(param_2 + param_3 * 4);
        } while (uVar4 == uVar3);
      }
      iVar2 = (-(uint)(uVar3 < uVar4) & 2) - 1;
    }
  }
  else {
    iVar2 = (-(uint)(uVar3 < uVar4) & 2) - 1;
  }
  return iVar2;
}

