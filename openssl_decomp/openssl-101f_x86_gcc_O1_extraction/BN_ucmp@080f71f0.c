
int BN_ucmp(BIGNUM *a,BIGNUM *b)

{
  int iVar1;
  int iVar2;
  
  iVar1 = a->top - b->top;
  if (iVar1 == 0) {
    iVar2 = a->top + -1;
    if (-1 < iVar2) {
      while( true ) {
        if (a->d[iVar2] != b->d[iVar2]) break;
        iVar2 = iVar2 + -1;
        if (iVar2 == -1) {
          return 0;
        }
      }
      iVar1 = (-(uint)(b->d[iVar2] < a->d[iVar2]) & 2) - 1;
    }
  }
  return iVar1;
}

