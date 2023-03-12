
int BN_mul_word(BIGNUM *a,ulong w)

{
  ulong uVar1;
  int iVar2;
  BIGNUM *pBVar3;
  
  if (a->top != 0) {
    if (w == 0) {
      BN_set_word(a,0);
    }
    else {
      uVar1 = bn_mul_words(a->d,a->d,a->top,w);
      if (uVar1 != 0) {
        iVar2 = a->top;
        if (a->dmax <= iVar2) {
          pBVar3 = bn_expand2(a,iVar2 + 1);
          if (pBVar3 == (BIGNUM *)0x0) {
            return 0;
          }
          iVar2 = a->top;
        }
        a->top = iVar2 + 1;
        a->d[iVar2] = uVar1;
        return 1;
      }
    }
  }
  return 1;
}

