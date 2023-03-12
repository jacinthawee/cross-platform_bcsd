
BIGNUM * bn_dup_expand(BIGNUM *a,int words)

{
  BIGNUM *a_00;
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (a->dmax < words) {
    a_00 = (BIGNUM *)bn_expand_internal();
    if (a_00 != (BIGNUM *)0x0) {
      pBVar1 = (BIGNUM *)CRYPTO_malloc(0x14,"bn_lib.c",0x11b);
      if (pBVar1 == (BIGNUM *)0x0) {
        ERR_put_error(3,0x71,0x41,"bn_lib.c",0x11d);
        CRYPTO_free(a_00);
        a_00 = pBVar1;
      }
      else {
        pBVar1->top = 0;
        pBVar1->neg = 0;
        iVar2 = a->top;
        iVar3 = a->neg;
        pBVar1->dmax = words;
        pBVar1->top = iVar2;
        pBVar1->neg = iVar3;
        pBVar1->d = (ulong *)a_00;
        pBVar1->flags = 1;
        a_00 = pBVar1;
      }
    }
  }
  else {
    a_00 = (BIGNUM *)CRYPTO_malloc(0x14,"bn_lib.c",0x11b);
    if (a_00 == (BIGNUM *)0x0) {
      ERR_put_error(3,0x71,0x41,"bn_lib.c",0x11d);
    }
    else {
      a_00->flags = 1;
      a_00->top = 0;
      a_00->neg = 0;
      a_00->dmax = 0;
      a_00->d = (ulong *)0x0;
      pBVar1 = BN_copy(a_00,a);
      if (pBVar1 == (BIGNUM *)0x0) {
        uVar4 = a_00->flags;
        if ((a_00->d != (ulong *)0x0) && (-1 < (int)(uVar4 << 0x1e))) {
          CRYPTO_free(a_00->d);
          uVar4 = a_00->flags;
        }
        if ((BIGNUM *)(uVar4 & 1) == (BIGNUM *)0x0) {
          a_00->d = (ulong *)0x0;
          a_00->flags = uVar4 | 0x8000;
          a_00 = (BIGNUM *)(uVar4 & 1);
        }
        else {
          CRYPTO_free(a_00);
          a_00 = (BIGNUM *)0x0;
        }
      }
    }
  }
  return a_00;
}

