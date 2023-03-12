
BIGNUM * bn_dup_expand(BIGNUM *a,int words)

{
  int iVar1;
  ulong *ptr;
  BIGNUM *a_00;
  BIGNUM *pBVar2;
  uint uVar3;
  
  if (a->dmax < words) {
    ptr = (ulong *)bn_expand_internal();
    if (ptr == (ulong *)0x0) {
      a_00 = (BIGNUM *)0x0;
    }
    else {
      a_00 = (BIGNUM *)CRYPTO_malloc(0x14,"bn_lib.c",0x11b);
      if (a_00 == (BIGNUM *)0x0) {
        ERR_put_error(3,0x71,0x41,"bn_lib.c",0x11d);
        CRYPTO_free(ptr);
      }
      else {
        a_00->neg = 0;
        a_00->flags = 1;
        a_00->top = 0;
        iVar1 = a->top;
        a_00->dmax = words;
        a_00->top = iVar1;
        iVar1 = a->neg;
        a_00->d = ptr;
        a_00->neg = iVar1;
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
      pBVar2 = BN_copy(a_00,a);
      if (pBVar2 == (BIGNUM *)0x0) {
        uVar3 = a_00->flags;
        if ((a_00->d != (ulong *)0x0) && ((uVar3 & 2) == 0)) {
          CRYPTO_free(a_00->d);
          uVar3 = a_00->flags;
        }
        if ((uVar3 & 1) == 0) {
          a_00->d = (ulong *)0x0;
          a_00->flags = uVar3 | 0x8000;
          a_00 = (BIGNUM *)0x0;
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

