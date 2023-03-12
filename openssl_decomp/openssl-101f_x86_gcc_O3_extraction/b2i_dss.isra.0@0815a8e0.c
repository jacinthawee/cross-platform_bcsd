
EVP_PKEY * __regparm3 b2i_dss_isra_0(int *param_1,int param_2,int param_3)

{
  DSA *r;
  EVP_PKEY *pkey;
  uchar *puVar1;
  uchar *puVar2;
  BIGNUM *pBVar3;
  uchar *puVar4;
  uchar *puVar5;
  int iVar6;
  BN_CTX *ctx;
  uint num;
  int iVar7;
  
  iVar7 = *param_1;
  r = DSA_new();
  pkey = EVP_PKEY_new();
  if ((r == (DSA *)0x0) || (pkey == (EVP_PKEY *)0x0)) {
    ERR_put_error(9,0x7f,0x41,"pvkfmt.c",0x167);
    if (r != (DSA *)0x0) goto LAB_0815ab2f;
  }
  else {
    num = param_2 + 7U >> 3;
    iVar6 = num - 1;
    puVar4 = (uchar *)(iVar7 + iVar6);
    puVar1 = (uchar *)CRYPTO_malloc(num,"pvkfmt.c",0x60);
    if (puVar1 != (uchar *)0x0) {
      puVar5 = puVar1;
      if (num != 0) {
        do {
          puVar2 = puVar5 + 1;
          *puVar5 = *puVar4;
          puVar5 = puVar2;
          puVar4 = puVar4 + -1;
        } while (puVar2 != puVar1 + num);
      }
      pBVar3 = BN_bin2bn(puVar1,num,(BIGNUM *)0x0);
      r->p = pBVar3;
      CRYPTO_free(puVar1);
      if (r->p != (BIGNUM *)0x0) {
        iVar7 = iVar7 + num;
        puVar4 = (uchar *)CRYPTO_malloc(0x14,"pvkfmt.c",0x60);
        if (puVar4 != (uchar *)0x0) {
          puVar1 = puVar4;
          puVar5 = (uchar *)(iVar7 + 0x13);
          do {
            puVar2 = puVar5 + -1;
            *puVar1 = *puVar5;
            puVar1 = puVar1 + 1;
            puVar5 = puVar2;
          } while (puVar2 != (uchar *)(iVar7 + -1));
          pBVar3 = BN_bin2bn(puVar4,0x14,(BIGNUM *)0x0);
          r->q = pBVar3;
          CRYPTO_free(puVar4);
          if (r->q != (BIGNUM *)0x0) {
            puVar4 = (uchar *)CRYPTO_malloc(num,"pvkfmt.c",0x60);
            if (puVar4 != (uchar *)0x0) {
              puVar1 = puVar4;
              puVar5 = (uchar *)(iVar6 + iVar7 + 0x14);
              if (num != 0) {
                do {
                  puVar2 = puVar1 + 1;
                  *puVar1 = *puVar5;
                  puVar1 = puVar2;
                  puVar5 = puVar5 + -1;
                } while (puVar4 + num != puVar2);
              }
              pBVar3 = BN_bin2bn(puVar4,num,(BIGNUM *)0x0);
              r->g = pBVar3;
              CRYPTO_free(puVar4);
              if (r->g != (BIGNUM *)0x0) {
                iVar7 = iVar7 + 0x14 + num;
                if (param_3 == 0) {
                  puVar4 = (uchar *)CRYPTO_malloc(0x14,"pvkfmt.c",0x60);
                  if (puVar4 != (uchar *)0x0) {
                    puVar1 = puVar4;
                    puVar5 = (uchar *)(iVar7 + 0x13);
                    do {
                      puVar2 = puVar5 + -1;
                      *puVar1 = *puVar5;
                      puVar1 = puVar1 + 1;
                      puVar5 = puVar2;
                    } while (puVar2 != (uchar *)(iVar7 + -1));
                    pBVar3 = BN_bin2bn(puVar4,0x14,(BIGNUM *)0x0);
                    r->priv_key = pBVar3;
                    CRYPTO_free(puVar4);
                    if (r->priv_key != (BIGNUM *)0x0) {
                      pBVar3 = BN_new();
                      r->pub_key = pBVar3;
                      if ((pBVar3 == (BIGNUM *)0x0) || (ctx = BN_CTX_new(), ctx == (BN_CTX *)0x0)) {
                        ctx = (BN_CTX *)0x0;
                      }
                      else {
                        iVar6 = BN_mod_exp(r->pub_key,r->g,r->priv_key,r->p,ctx);
                        if (iVar6 != 0) {
                          iVar7 = iVar7 + 0x14;
                          BN_CTX_free(ctx);
                          goto LAB_0815aaec;
                        }
                      }
                      ERR_put_error(9,0x7f,0x41,"pvkfmt.c",0x167);
                      DSA_free(r);
                      goto LAB_0815ab45;
                    }
                  }
                }
                else {
                  puVar4 = (uchar *)(iVar6 + iVar7);
                  puVar1 = (uchar *)CRYPTO_malloc(num,"pvkfmt.c",0x60);
                  if (puVar1 != (uchar *)0x0) {
                    puVar5 = puVar1;
                    if (num != 0) {
                      do {
                        puVar2 = puVar5 + 1;
                        *puVar5 = *puVar4;
                        puVar5 = puVar2;
                        puVar4 = puVar4 + -1;
                      } while (puVar2 != puVar1 + num);
                    }
                    iVar7 = iVar7 + num;
                    pBVar3 = BN_bin2bn(puVar1,num,(BIGNUM *)0x0);
                    r->pub_key = pBVar3;
                    CRYPTO_free(puVar1);
                    if (r->pub_key != (BIGNUM *)0x0) {
LAB_0815aaec:
                      EVP_PKEY_set1_DSA(pkey,r);
                      DSA_free(r);
                      *param_1 = iVar7;
                      return pkey;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    ERR_put_error(9,0x7f,0x41,"pvkfmt.c",0x167);
LAB_0815ab2f:
    DSA_free(r);
  }
  ctx = (BN_CTX *)0x0;
  if (pkey == (EVP_PKEY *)0x0) {
    return (EVP_PKEY *)0x0;
  }
LAB_0815ab45:
  EVP_PKEY_free(pkey);
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
  }
  return (EVP_PKEY *)0x0;
}

