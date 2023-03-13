
int BN_sub(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *b_00;
  int iVar3;
  
  if (a->neg == 0) {
    if (b->neg != 0) {
      iVar3 = 0;
      goto LAB_081b745a;
    }
    iVar3 = a->top;
    if (iVar3 <= b->top) {
      iVar3 = b->top;
    }
    b_00 = b;
    b = a;
    if (iVar3 <= r->dmax) goto LAB_081b7496;
  }
  else {
    iVar3 = 1;
    if (b->neg == 0) {
LAB_081b745a:
      iVar1 = BN_uadd(r,a,b);
      if (iVar1 == 0) {
        return 0;
      }
      r->neg = iVar3;
      return 1;
    }
    iVar3 = b->top;
    if (iVar3 <= a->top) {
      iVar3 = a->top;
    }
    b_00 = a;
    if (iVar3 <= r->dmax) goto LAB_081b7496;
  }
  pBVar2 = bn_expand2(r,iVar3);
  if (pBVar2 == (BIGNUM *)0x0) {
    return 0;
  }
LAB_081b7496:
  iVar3 = BN_ucmp(b,b_00);
  if (iVar3 < 0) {
    iVar3 = BN_usub(r,b_00,b);
    if (iVar3 != 0) {
      r->neg = 1;
      return 1;
    }
  }
  else {
    iVar3 = BN_usub(r,b,b_00);
    if (iVar3 != 0) {
      r->neg = 0;
      return 1;
    }
  }
  return 0;
}

