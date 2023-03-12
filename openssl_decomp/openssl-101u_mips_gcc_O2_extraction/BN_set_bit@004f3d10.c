
int BN_set_bit(BIGNUM *a,int n)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong *puVar5;
  int iVar6;
  
  if (n < 0) {
    return 0;
  }
  iVar2 = a->top;
  iVar4 = n >> 5;
  bVar1 = iVar4 < iVar2;
  if (bVar1) {
    puVar5 = a->d;
  }
  else {
    iVar6 = iVar4 + 1;
    if ((a->dmax <= iVar4) && (a->dmax < iVar6)) {
      puVar5 = (ulong *)bn_expand_internal(a,iVar6);
      if (puVar5 == (ulong *)0x0) {
        return 0;
      }
      if (a->d != (ulong *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      iVar2 = a->top;
      a->d = puVar5;
      bVar1 = iVar4 < iVar2;
      a->dmax = iVar6;
      if (bVar1) {
        a->top = iVar6;
        goto LAB_004f3d58;
      }
    }
    puVar5 = a->d;
    iVar3 = 4;
    if (!bVar1) {
      iVar3 = (iVar6 - iVar2) * 4;
    }
    (*(code *)PTR_memset_006a99f4)(puVar5 + iVar2,0,iVar3);
    a->top = iVar6;
  }
LAB_004f3d58:
  puVar5[iVar4] = puVar5[iVar4] | 1 << (n & 0x1fU);
  return 1;
}

