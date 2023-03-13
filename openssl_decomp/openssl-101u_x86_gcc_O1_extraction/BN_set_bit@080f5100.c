
int BN_set_bit(BIGNUM *a,int n)

{
  int iVar1;
  size_t __n;
  ulong *puVar2;
  int iVar3;
  int iVar4;
  
  if (n < 0) {
    return 0;
  }
  iVar3 = a->top;
  iVar4 = n >> 5;
  if (iVar4 < iVar3) {
    puVar2 = a->d;
    goto LAB_080f5124;
  }
  iVar1 = iVar4 + 1;
  if ((iVar4 < a->dmax) || (iVar1 <= a->dmax)) {
LAB_080f514e:
    puVar2 = a->d;
    __n = (iVar1 - iVar3) * 4;
    if (iVar4 < iVar3) {
      __n = 4;
    }
    memset(puVar2 + iVar3,0,__n);
  }
  else {
    puVar2 = (ulong *)bn_expand_internal();
    if (puVar2 == (ulong *)0x0) {
      return 0;
    }
    if (a->d != (ulong *)0x0) {
      CRYPTO_free(a->d);
    }
    iVar3 = a->top;
    a->d = puVar2;
    a->dmax = iVar1;
    if (iVar3 <= iVar4) goto LAB_080f514e;
  }
  a->top = iVar1;
LAB_080f5124:
  puVar2[iVar4] = puVar2[iVar4] | 1 << ((byte)n & 0x1f);
  return 1;
}

