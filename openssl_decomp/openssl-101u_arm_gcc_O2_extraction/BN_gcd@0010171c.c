
int BN_gcd(BIGNUM *r,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  int iVar4;
  uint uVar5;
  int n;
  
  BN_CTX_start(ctx);
  pBVar1 = BN_CTX_get(ctx);
  pBVar2 = BN_CTX_get(ctx);
  uVar5 = (uint)(pBVar1 == (BIGNUM *)0x0 || pBVar2 == (BIGNUM *)0x0);
  if (((pBVar1 != (BIGNUM *)0x0 && pBVar2 != (BIGNUM *)0x0) &&
      (pBVar3 = BN_copy(pBVar1,a), pBVar3 != (BIGNUM *)0x0)) &&
     (pBVar3 = BN_copy(pBVar2,b), pBVar3 != (BIGNUM *)0x0)) {
    pBVar1->neg = uVar5;
    pBVar2->neg = uVar5;
    iVar4 = BN_cmp(pBVar1,pBVar2);
    n = 0;
    pBVar3 = pBVar2;
    if (iVar4 < 0) {
      pBVar3 = pBVar1;
      pBVar1 = pBVar2;
    }
    while (pBVar2 = pBVar3, iVar4 = pBVar2->top, iVar4 != 0) {
      pBVar3 = pBVar2;
      if ((pBVar1->top < 1) || (-1 < (int)(*pBVar1->d << 0x1f))) {
        if ((0 < iVar4) && ((int)(*pBVar2->d << 0x1f) < 0)) goto LAB_00101800;
        iVar4 = BN_rshift1(pBVar1,pBVar1);
        if ((iVar4 == 0) || (iVar4 = BN_rshift1(pBVar2,pBVar2), iVar4 == 0)) goto LAB_0010174c;
        n = n + 1;
      }
      else {
        if ((iVar4 < 1) || (-1 < (int)(*pBVar2->d << 0x1f))) {
          iVar4 = BN_rshift1(pBVar2,pBVar2);
        }
        else {
          iVar4 = BN_sub(pBVar1,pBVar1,pBVar2);
          if (iVar4 == 0) goto LAB_0010174c;
LAB_00101800:
          iVar4 = BN_rshift1(pBVar1,pBVar1);
        }
        if (iVar4 == 0) goto LAB_0010174c;
        iVar4 = BN_cmp(pBVar1,pBVar2);
        if (iVar4 < 0) {
          pBVar3 = pBVar1;
          pBVar1 = pBVar2;
        }
      }
    }
    if ((n == 0) || (iVar4 = BN_lshift(pBVar1,pBVar1,n), iVar4 != 0)) {
      pBVar1 = BN_copy(r,pBVar1);
      if (pBVar1 != (BIGNUM *)0x0) {
        pBVar1 = (BIGNUM *)0x1;
      }
      goto LAB_0010174e;
    }
  }
LAB_0010174c:
  pBVar1 = (BIGNUM *)0x0;
LAB_0010174e:
  BN_CTX_end(ctx);
  return (int)pBVar1;
}

