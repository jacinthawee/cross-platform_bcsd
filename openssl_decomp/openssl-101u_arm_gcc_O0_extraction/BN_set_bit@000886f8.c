
int BN_set_bit(BIGNUM *a,int n)

{
  size_t __n;
  int iVar1;
  int iVar2;
  ulong *puVar3;
  int iVar4;
  
  if (n < 0) {
    return 0;
  }
  iVar1 = a->top;
  iVar2 = n >> 5;
  if (iVar2 < iVar1) {
    puVar3 = a->d;
    goto LAB_00088738;
  }
  iVar4 = iVar2 + 1;
  if ((iVar2 < a->dmax) || (iVar4 <= a->dmax)) {
LAB_00088718:
    puVar3 = a->d;
    __n = (iVar4 - iVar1) * 4;
    if (iVar2 < iVar1) {
      __n = 4;
    }
    memset(puVar3 + iVar1,0,__n);
  }
  else {
    puVar3 = (ulong *)bn_expand_internal(a,iVar4);
    if (puVar3 == (ulong *)0x0) {
      return 0;
    }
    if (a->d != (ulong *)0x0) {
      CRYPTO_free(a->d);
    }
    iVar1 = a->top;
    a->d = puVar3;
    a->dmax = iVar4;
    if (iVar1 <= iVar2) goto LAB_00088718;
  }
  a->top = iVar4;
LAB_00088738:
  puVar3[iVar2] = puVar3[iVar2] | 1 << (n & 0x1fU);
  return 1;
}

