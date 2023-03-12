
int BN_mask_bits(BIGNUM *a,int n)

{
  int iVar1;
  int iVar2;
  
  if (n < 0) {
    return 0;
  }
  iVar1 = 0;
  iVar2 = n >> 5;
  if (iVar2 < a->top) {
    if ((n & 0x1fU) == 0) {
      a->top = iVar2;
    }
    else {
      a->top = iVar2 + 1;
      a->d[iVar2] = a->d[iVar2] & ~(-1 << (sbyte)(n & 0x1fU));
      iVar2 = a->top;
    }
    if (iVar2 < 1) {
      iVar1 = 1;
    }
    else {
      do {
        if (a->d[iVar2 + -1] != 0) break;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      a->top = iVar2;
      iVar1 = 1;
    }
  }
  return iVar1;
}

