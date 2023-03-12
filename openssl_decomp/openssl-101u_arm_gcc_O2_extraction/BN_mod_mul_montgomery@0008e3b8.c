
int BN_mod_mul_montgomery(BIGNUM *r,BIGNUM *a,BIGNUM *b,BN_MONT_CTX *mont,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  uint uVar2;
  uint uVar3;
  ulong *puVar4;
  int iVar5;
  int words;
  
  iVar5 = (mont->N).top;
  if (((1 < iVar5) && (words = a->top, words == iVar5)) && (words == b->top)) {
    if ((r->dmax < words) && (pBVar1 = bn_expand2(r,words), pBVar1 == (BIGNUM *)0x0)) {
      return 0;
    }
    iVar5 = bn_mul_mont(r->d,a->d,b->d,(mont->N).d,mont->n0,words);
    if (iVar5 != 0) {
      uVar2 = b->neg;
      uVar3 = a->neg;
      r->top = words;
      r->neg = uVar2 ^ uVar3;
      puVar4 = r->d + words + 0x3fffffff;
      do {
        if (*puVar4 != 0) break;
        words = words + -1;
        puVar4 = puVar4 + -1;
      } while (words != 0);
      r->top = words;
      return 1;
    }
  }
  BN_CTX_start(ctx);
  pBVar1 = BN_CTX_get(ctx);
  if (pBVar1 != (BIGNUM *)0x0) {
    if (a == b) {
      iVar5 = BN_sqr(pBVar1,a,ctx);
    }
    else {
      iVar5 = BN_mul(pBVar1,a,b,ctx);
    }
    if (iVar5 != 0) {
      iVar5 = BN_from_montgomery_word(r,pBVar1,mont);
      if (iVar5 != 0) {
        iVar5 = 1;
      }
      goto LAB_0008e3f8;
    }
  }
  iVar5 = 0;
LAB_0008e3f8:
  BN_CTX_end(ctx);
  return iVar5;
}

