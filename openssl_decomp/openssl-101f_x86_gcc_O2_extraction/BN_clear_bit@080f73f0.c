
int BN_clear_bit(BIGNUM *a,int n)

{
  uint *puVar1;
  ulong *puVar2;
  int iVar3;
  
  if (n < 0) {
    return 0;
  }
  iVar3 = 0;
  if (n >> 5 < a->top) {
    puVar2 = a->d;
    puVar1 = puVar2 + (n >> 5);
    *puVar1 = *puVar1 & ~(1 << ((byte)n & 0x1f));
    iVar3 = a->top;
    if (iVar3 < 1) {
      iVar3 = 1;
    }
    else {
      do {
        if (puVar2[iVar3 + -1] != 0) break;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      a->top = iVar3;
      iVar3 = 1;
    }
  }
  return iVar3;
}

