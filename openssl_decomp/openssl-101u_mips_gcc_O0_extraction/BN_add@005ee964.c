
int BN_add(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  BIGNUM *a_00;
  int iVar1;
  undefined4 in_a3;
  int iVar2;
  
  iVar2 = a->neg;
  if (iVar2 == b->neg) {
    iVar1 = BN_uadd(r,a,b);
    r->neg = iVar2;
    return iVar1;
  }
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_BN_ucmp_006a7fb4)(a,b);
    a_00 = b;
    b = a;
  }
  else {
    iVar2 = (*(code *)PTR_BN_ucmp_006a7fb4)(b,a,b,in_a3,&_gp);
    a_00 = a;
  }
  if (iVar2 < 0) {
    iVar2 = BN_usub(r,a_00,b);
    if (iVar2 != 0) {
      r->neg = 1;
      return 1;
    }
  }
  else {
    iVar2 = BN_usub(r,b,a_00);
    if (iVar2 != 0) {
      r->neg = 0;
      return 1;
    }
  }
  return 0;
}

