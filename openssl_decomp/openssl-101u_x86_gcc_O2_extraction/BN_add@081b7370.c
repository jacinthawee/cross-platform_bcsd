
int BN_add(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  int iVar1;
  int iVar2;
  BIGNUM *a_00;
  
  iVar1 = a->neg;
  if (iVar1 == b->neg) {
    iVar2 = BN_uadd(r,a,b);
    r->neg = iVar1;
    return iVar2;
  }
  a_00 = a;
  if (iVar1 != 0) {
    a_00 = b;
    b = a;
  }
  iVar1 = BN_ucmp(a_00,b);
  if (iVar1 < 0) {
    iVar1 = BN_usub(r,b,a_00);
    if (iVar1 != 0) {
      r->neg = 1;
      return 1;
    }
  }
  else {
    iVar1 = BN_usub(r,a_00,b);
    if (iVar1 != 0) {
      r->neg = 0;
      return 1;
    }
  }
  return 0;
}

