
int BN_mask_bits(BIGNUM *a,int n)

{
  int iVar1;
  ulong *puVar2;
  
  if (-1 < n) {
    iVar1 = n >> 5;
    if (iVar1 < a->top) {
      if ((n & 0x1fU) == 0) {
        a->top = iVar1;
      }
      else {
        a->top = iVar1 + 1;
        a->d[iVar1] = a->d[iVar1] & ~(-1 << (n & 0x1fU));
        iVar1 = a->top;
      }
      if (iVar1 < 1) {
        return 1;
      }
      puVar2 = a->d + iVar1 + -2;
      do {
        if (puVar2[1] != 0) break;
        iVar1 = iVar1 + -1;
        puVar2 = puVar2 + -1;
      } while (iVar1 != 0);
      a->top = iVar1;
      return 1;
    }
  }
  return 0;
}

