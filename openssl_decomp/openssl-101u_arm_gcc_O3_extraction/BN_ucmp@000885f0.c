
int BN_ucmp(BIGNUM *a,BIGNUM *b)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  iVar6 = a->top - b->top;
  if (iVar6 == 0) {
    iVar4 = a->top + -1;
    if (-1 < iVar4) {
      uVar2 = a->d[iVar4];
      uVar3 = b->d[iVar4];
      if (uVar2 == uVar3) {
        iVar5 = iVar4 * 4 + 4;
        do {
          bVar7 = iVar4 == 0;
          iVar4 = iVar4 + -1;
          iVar1 = iVar6 + iVar5;
          iVar6 = iVar6 + -4;
          if (bVar7) {
            return 0;
          }
          uVar2 = *(uint *)((int)a->d + iVar1 + -8);
          uVar3 = *(uint *)((int)b->d + iVar6 + iVar5 + -4);
        } while (uVar2 == uVar3);
      }
      if (uVar3 < uVar2) {
        iVar6 = 1;
      }
      else {
        iVar6 = -1;
      }
      return iVar6;
    }
  }
  return iVar6;
}

