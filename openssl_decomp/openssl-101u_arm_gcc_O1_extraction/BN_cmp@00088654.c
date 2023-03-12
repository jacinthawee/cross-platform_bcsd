
int BN_cmp(BIGNUM *a,BIGNUM *b)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  uVar5 = (uint)(b == (BIGNUM *)0x0 || a == (BIGNUM *)0x0);
  if (b == (BIGNUM *)0x0 || a == (BIGNUM *)0x0) {
    if (a == (BIGNUM *)0x0) {
      if (b != (BIGNUM *)0x0) {
        b = (BIGNUM *)0x1;
      }
      return (int)b;
    }
    return -1;
  }
  iVar6 = a->neg;
  if (iVar6 != b->neg) {
    if (iVar6 == 0) {
      iVar6 = 1;
    }
    else {
      iVar6 = -1;
    }
    return iVar6;
  }
  iVar4 = a->top;
  if (iVar6 == 0) {
    iVar6 = -1;
    iVar9 = 1;
  }
  else {
    iVar6 = 1;
    iVar9 = -1;
  }
  if (b->top < iVar4) {
    return iVar9;
  }
  if (b->top <= iVar4) {
    iVar4 = iVar4 + -1;
    if (iVar4 < 0) {
      return uVar5;
    }
    uVar7 = a->d[iVar4];
    uVar3 = b->d[iVar4];
    if (uVar3 < uVar7) {
      return iVar9;
    }
    if (uVar3 <= uVar7) {
      iVar8 = iVar4 * 4 + 4;
      do {
        iVar4 = iVar4 + -1;
        iVar1 = uVar5 + iVar8;
        iVar2 = uVar5 + iVar8;
        uVar5 = uVar5 - 4;
        if (iVar4 == -1) {
          return 0;
        }
        uVar7 = *(uint *)((int)a->d + iVar1 + -8);
        uVar3 = *(uint *)((int)b->d + iVar2 + -8);
        if (uVar3 < uVar7) {
          return iVar9;
        }
      } while (uVar3 <= uVar7);
    }
  }
  return iVar6;
}

