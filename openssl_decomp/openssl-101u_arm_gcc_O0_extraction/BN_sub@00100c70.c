
int BN_sub(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  int iVar1;
  BIGNUM *pBVar2;
  int iVar3;
  BIGNUM *a_00;
  BIGNUM *b_00;
  
  iVar3 = a->neg;
  if (iVar3 == 0) {
    a_00 = a;
    b_00 = b;
    if (b->neg != 0) {
      iVar1 = BN_uadd(r,a,b);
      goto joined_r0x00100ca4;
    }
  }
  else {
    iVar3 = 1;
    a_00 = b;
    b_00 = a;
    if (b->neg == 0) {
      iVar1 = BN_uadd(r,a,b);
joined_r0x00100ca4:
      if (iVar1 == 0) {
        return 0;
      }
      r->neg = iVar3;
      return 1;
    }
  }
  iVar3 = a_00->top;
  if (a_00->top < b_00->top) {
    iVar3 = b_00->top;
  }
  if ((r->dmax < iVar3) && (pBVar2 = bn_expand2(r,iVar3), pBVar2 == (BIGNUM *)0x0)) {
    return 0;
  }
  iVar3 = BN_ucmp(a_00,b_00);
  if (iVar3 < 0) {
    iVar3 = BN_usub(r,b_00,a_00);
    if (iVar3 != 0) {
      r->neg = 1;
      return 1;
    }
  }
  else {
    iVar3 = BN_usub(r,a_00,b_00);
    if (iVar3 != 0) {
      r->neg = 0;
      return 1;
    }
  }
  return 0;
}

