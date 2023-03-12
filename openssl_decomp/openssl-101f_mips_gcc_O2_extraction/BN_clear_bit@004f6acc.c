
int BN_clear_bit(BIGNUM *a,int n)

{
  ulong *puVar1;
  ulong *puVar2;
  int iVar3;
  
  if ((n < 0) || (a->top <= n >> 5)) {
    return 0;
  }
  puVar2 = a->d;
  puVar1 = puVar2 + (n >> 5);
  *puVar1 = *puVar1 & ~(1 << (n & 0x1fU));
  iVar3 = a->top;
  if (iVar3 < 1) {
    return 1;
  }
  puVar2 = puVar2 + iVar3 + -2;
  do {
    if (puVar2[1] != 0) break;
    iVar3 = iVar3 + -1;
    puVar2 = puVar2 + -1;
  } while (iVar3 != 0);
  a->top = iVar3;
  return 1;
}

