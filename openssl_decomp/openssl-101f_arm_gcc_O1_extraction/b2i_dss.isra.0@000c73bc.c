
DSA * b2i_dss_isra_0(int *param_1,int param_2,int param_3)

{
  DSA *r;
  DSA *pkey;
  uchar *puVar1;
  BIGNUM *pBVar2;
  uchar *puVar3;
  uchar *puVar4;
  uchar *puVar5;
  DSA *ctx;
  int iVar6;
  int iVar7;
  uint num;
  
  iVar6 = *param_1;
  r = DSA_new();
  pkey = (DSA *)EVP_PKEY_new();
  if (r == (DSA *)0x0 || pkey == (DSA *)0x0) {
    ERR_put_error(9,0x7f,0x41,"pvkfmt.c",0x167);
    if (r == (DSA *)0x0) goto LAB_000c7562;
    ctx = (DSA *)0x0;
  }
  else {
    num = param_2 + 7U >> 3;
    iVar7 = num - 1;
    puVar1 = (uchar *)CRYPTO_malloc(num,"pvkfmt.c",0x60);
    if (puVar1 == (uchar *)0x0) {
LAB_000c757a:
      ctx = (DSA *)0x0;
    }
    else {
      puVar3 = puVar1;
      puVar5 = (uchar *)(iVar6 + iVar7);
      if (num != 0) {
        do {
          puVar4 = puVar3 + 1;
          *puVar3 = *puVar5;
          puVar3 = puVar4;
          puVar5 = puVar5 + -1;
        } while (puVar4 != puVar1 + num);
      }
      pBVar2 = BN_bin2bn(puVar1,num,(BIGNUM *)0x0);
      r->p = pBVar2;
      CRYPTO_free(puVar1);
      if (r->p == (BIGNUM *)0x0) goto LAB_000c757a;
      puVar1 = (uchar *)CRYPTO_malloc(0x14,"pvkfmt.c",0x60);
      iVar6 = iVar6 + num;
      if (puVar1 == (uchar *)0x0) goto LAB_000c757a;
      puVar3 = puVar1 + -1;
      puVar5 = (uchar *)(iVar6 + 0x13);
      do {
        puVar4 = puVar5 + -1;
        puVar3 = puVar3 + 1;
        *puVar3 = *puVar5;
        puVar5 = puVar4;
      } while (puVar4 != (uchar *)(iVar6 + -1));
      pBVar2 = BN_bin2bn(puVar1,0x14,(BIGNUM *)0x0);
      r->q = pBVar2;
      CRYPTO_free(puVar1);
      if ((r->q == (BIGNUM *)0x0) ||
         (puVar1 = (uchar *)CRYPTO_malloc(num,"pvkfmt.c",0x60), puVar1 == (uchar *)0x0))
      goto LAB_000c757a;
      puVar3 = (uchar *)(iVar6 + 0x14 + iVar7);
      puVar5 = puVar1;
      if (num != 0) {
        do {
          puVar4 = puVar5 + 1;
          *puVar5 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar5 = puVar4;
        } while (puVar4 != puVar1 + num);
      }
      pBVar2 = BN_bin2bn(puVar1,num,(BIGNUM *)0x0);
      r->g = pBVar2;
      CRYPTO_free(puVar1);
      if (r->g == (BIGNUM *)0x0) goto LAB_000c757a;
      iVar6 = iVar6 + 0x14 + num;
      if (param_3 != 0) {
        puVar1 = (uchar *)CRYPTO_malloc(num,"pvkfmt.c",0x60);
        if (puVar1 != (uchar *)0x0) {
          puVar3 = puVar1;
          puVar5 = (uchar *)(iVar7 + iVar6);
          if (num != 0) {
            do {
              puVar4 = puVar3 + 1;
              *puVar3 = *puVar5;
              puVar3 = puVar4;
              puVar5 = puVar5 + -1;
            } while (puVar4 != puVar1 + num);
          }
          pBVar2 = BN_bin2bn(puVar1,num,(BIGNUM *)0x0);
          r->pub_key = pBVar2;
          CRYPTO_free(puVar1);
          if (r->pub_key != (BIGNUM *)0x0) {
LAB_000c752a:
            EVP_PKEY_set1_DSA((EVP_PKEY *)pkey,r);
            DSA_free(r);
            *param_1 = iVar6 + num;
            return pkey;
          }
        }
        goto LAB_000c757a;
      }
      puVar1 = (uchar *)CRYPTO_malloc(0x14,"pvkfmt.c",0x60);
      if (puVar1 == (uchar *)0x0) goto LAB_000c757a;
      puVar3 = puVar1 + -1;
      puVar5 = (uchar *)(iVar6 + 0x13);
      do {
        puVar4 = puVar5 + -1;
        puVar3 = puVar3 + 1;
        *puVar3 = *puVar5;
        puVar5 = puVar4;
      } while (puVar4 != (uchar *)(iVar6 + -1));
      pBVar2 = BN_bin2bn(puVar1,0x14,(BIGNUM *)0x0);
      r->priv_key = pBVar2;
      CRYPTO_free(puVar1);
      if (r->priv_key == (BIGNUM *)0x0) goto LAB_000c757a;
      pBVar2 = BN_new();
      r->pub_key = pBVar2;
      if ((pBVar2 == (BIGNUM *)0x0) || (ctx = (DSA *)BN_CTX_new(), ctx == (DSA *)0x0))
      goto LAB_000c757a;
      iVar7 = BN_mod_exp(r->pub_key,r->g,r->priv_key,r->p,(BN_CTX *)ctx);
      if (iVar7 != 0) {
        num = 0x14;
        BN_CTX_free((BN_CTX *)ctx);
        goto LAB_000c752a;
      }
    }
    ERR_put_error(9,0x7f,0x41,"pvkfmt.c",0x167);
  }
  DSA_free(r);
  r = ctx;
LAB_000c7562:
  if (pkey != (DSA *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)pkey);
  }
  if (r != (DSA *)0x0) {
    BN_CTX_free((BN_CTX *)r);
    r = (DSA *)0x0;
  }
  return r;
}

