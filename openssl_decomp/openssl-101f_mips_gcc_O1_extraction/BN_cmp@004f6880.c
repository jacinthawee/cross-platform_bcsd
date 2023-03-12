
int BN_cmp(BIGNUM *a,BIGNUM *b)

{
  ulong *puVar1;
  ulong *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ulong *puVar6;
  int iVar7;
  ulong *puVar8;
  uint uVar9;
  int iVar10;
  
  if (a == (BIGNUM *)0x0) {
    return (uint)(b != (BIGNUM *)0x0);
  }
  if (b == (BIGNUM *)0x0) {
    return -1;
  }
  iVar5 = a->neg;
  iVar3 = 1;
  if (iVar5 != b->neg) {
    if (iVar5 != 0) {
      iVar3 = -1;
    }
    return iVar3;
  }
  iVar3 = a->top;
  iVar7 = -1;
  iVar10 = 1;
  if (iVar5 == 0) {
    iVar10 = -1;
  }
  if (iVar5 == 0) {
    iVar7 = 1;
  }
  if (b->top < iVar3) {
    return iVar7;
  }
  iVar5 = iVar3 + -1;
  if (b->top <= iVar3) {
    if (iVar5 < 0) {
      return 0;
    }
    uVar4 = a->d[iVar5];
    uVar9 = b->d[iVar5];
    if (uVar9 < uVar4) {
      return iVar7;
    }
    if (uVar9 <= uVar4) {
      puVar8 = a->d + iVar3;
      puVar6 = b->d + iVar3;
      do {
        iVar5 = iVar5 + -1;
        if (iVar5 == -1) {
          return 0;
        }
        puVar1 = puVar8 + -2;
        puVar2 = puVar6 + -2;
        puVar8 = puVar8 + -1;
        if (*puVar2 < *puVar1) {
          return iVar7;
        }
        puVar6 = puVar6 + -1;
      } while (*puVar2 <= *puVar1);
    }
  }
  return iVar10;
}

