
EVP_PKEY * __regparm3 b2i_rsa_isra_1(ulong **param_1,int param_2,int param_3)

{
  int iVar1;
  RSA *r;
  EVP_PKEY *pkey;
  BIGNUM *pBVar2;
  int iVar3;
  uint uVar4;
  uchar *puVar5;
  uchar *puVar6;
  uchar *puVar7;
  EVP_PKEY *pEVar8;
  uchar *puVar9;
  int in_GS_OFFSET;
  ulong *local_24;
  
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = *param_1;
  r = RSA_new();
  pkey = EVP_PKEY_new();
  if ((r == (RSA *)0x0) || (pkey == (EVP_PKEY *)0x0)) {
    ERR_put_error(9,0x81,0x41,"pvkfmt.c",0x19b);
    if (r != (RSA *)0x0) {
      RSA_free(r);
    }
  }
  else {
    pBVar2 = BN_new();
    r->e = pBVar2;
    if (pBVar2 != (BIGNUM *)0x0) {
      iVar3 = BN_set_word(pBVar2,*local_24);
      if (iVar3 != 0) {
        uVar4 = param_2 + 7U >> 3;
        puVar9 = (uchar *)((int)local_24 + uVar4 + 3);
        puVar5 = (uchar *)CRYPTO_malloc(uVar4,"pvkfmt.c",0x60);
        if (puVar5 != (uchar *)0x0) {
          puVar7 = puVar5;
          if (uVar4 != 0) {
            do {
              puVar6 = puVar7 + 1;
              *puVar7 = *puVar9;
              puVar7 = puVar6;
              puVar9 = puVar9 + -1;
            } while (puVar6 != puVar5 + uVar4);
          }
          pBVar2 = BN_bin2bn(puVar5,uVar4,(BIGNUM *)0x0);
          r->n = pBVar2;
          CRYPTO_free(puVar5);
          if (r->n != (BIGNUM *)0x0) {
            local_24 = (ulong *)((int)local_24 + uVar4 + 4);
            if (param_3 != 0) {
LAB_0815aff8:
              EVP_PKEY_set1_RSA(pkey,r);
              RSA_free(r);
              *param_1 = local_24;
              pEVar8 = pkey;
              goto LAB_0815ad09;
            }
            uVar4 = param_2 + 0xfU >> 4;
            iVar3 = uVar4 - 1;
            puVar9 = (uchar *)(iVar3 + (int)local_24);
            puVar5 = (uchar *)CRYPTO_malloc(uVar4,"pvkfmt.c",0x60);
            if (puVar5 != (uchar *)0x0) {
              puVar7 = puVar5;
              if (uVar4 != 0) {
                do {
                  puVar6 = puVar7 + 1;
                  *puVar7 = *puVar9;
                  puVar7 = puVar6;
                  puVar9 = puVar9 + -1;
                } while (puVar6 != puVar5 + uVar4);
              }
              pBVar2 = BN_bin2bn(puVar5,uVar4,(BIGNUM *)0x0);
              r->p = pBVar2;
              CRYPTO_free(puVar5);
              if (r->p != (BIGNUM *)0x0) {
                puVar9 = (uchar *)((int)local_24 + iVar3 + uVar4);
                puVar5 = (uchar *)CRYPTO_malloc(uVar4,"pvkfmt.c",0x60);
                if (puVar5 != (uchar *)0x0) {
                  puVar7 = puVar5;
                  if (uVar4 != 0) {
                    do {
                      puVar6 = puVar7 + 1;
                      *puVar7 = *puVar9;
                      puVar7 = puVar6;
                      puVar9 = puVar9 + -1;
                    } while (puVar6 != puVar5 + uVar4);
                  }
                  pBVar2 = BN_bin2bn(puVar5,uVar4,(BIGNUM *)0x0);
                  r->q = pBVar2;
                  CRYPTO_free(puVar5);
                  if (r->q != (BIGNUM *)0x0) {
                    puVar9 = (uchar *)((int)local_24 + iVar3 + uVar4 * 2);
                    puVar5 = (uchar *)CRYPTO_malloc(uVar4,"pvkfmt.c",0x60);
                    if (puVar5 != (uchar *)0x0) {
                      puVar7 = puVar5;
                      if (uVar4 != 0) {
                        do {
                          puVar6 = puVar7 + 1;
                          *puVar7 = *puVar9;
                          puVar7 = puVar6;
                          puVar9 = puVar9 + -1;
                        } while (puVar6 != puVar5 + uVar4);
                      }
                      pBVar2 = BN_bin2bn(puVar5,uVar4,(BIGNUM *)0x0);
                      r->dmp1 = pBVar2;
                      CRYPTO_free(puVar5);
                      if (r->dmp1 != (BIGNUM *)0x0) {
                        local_24 = (ulong *)((int)local_24 + uVar4 * 3);
                        iVar3 = read_lebn();
                        if (((iVar3 != 0) && (iVar3 = read_lebn(), iVar3 != 0)) &&
                           (iVar3 = read_lebn(), iVar3 != 0)) goto LAB_0815aff8;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    ERR_put_error(9,0x81,0x41,"pvkfmt.c",0x19b);
    RSA_free(r);
  }
  pEVar8 = (EVP_PKEY *)0x0;
  if (pkey != (EVP_PKEY *)0x0) {
    EVP_PKEY_free(pkey);
  }
LAB_0815ad09:
  if (iVar1 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pEVar8;
}

