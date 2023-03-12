
int BN_ucmp(BIGNUM *a,BIGNUM *b)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong *puVar4;
  ulong *puVar5;
  uint uVar6;
  
  iVar2 = a->top;
  iVar1 = iVar2 - b->top;
  if (iVar1 == 0) {
    iVar1 = iVar2 + -1;
    if (-1 < iVar1) {
      uVar3 = a->d[iVar1];
      uVar6 = b->d[iVar1];
      if (uVar3 == uVar6) {
        puVar5 = a->d + iVar2;
        puVar4 = b->d + iVar2;
        do {
          iVar1 = iVar1 + -1;
          if (iVar1 == -1) goto LAB_004f3bfc;
          uVar3 = puVar5[-2];
          uVar6 = puVar4[-2];
          puVar5 = puVar5 + -1;
          puVar4 = puVar4 + -1;
        } while (uVar3 == uVar6);
      }
      iVar1 = -1;
      if (uVar6 < uVar3) {
        iVar1 = 1;
      }
      return iVar1;
    }
LAB_004f3bfc:
    iVar1 = 0;
  }
  return iVar1;
}

