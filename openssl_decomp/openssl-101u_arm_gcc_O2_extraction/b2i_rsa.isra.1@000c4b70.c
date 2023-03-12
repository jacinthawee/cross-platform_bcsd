
EVP_PKEY * b2i_rsa_isra_1(byte **param_1,int param_2,int param_3)

{
  byte bVar1;
  RSA *r;
  EVP_PKEY *pkey;
  BIGNUM *pBVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint num;
  byte *pbVar7;
  uint num_00;
  byte *local_30 [3];
  
  local_30[0] = *param_1;
  r = RSA_new();
  pkey = EVP_PKEY_new();
  if (r == (RSA *)0x0 || pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(9,0x81,0x41,"pvkfmt.c",0x18e);
    if (r != (RSA *)0x0) {
      RSA_free(r);
    }
  }
  else {
    pBVar2 = BN_new();
    r->e = pBVar2;
    if (pBVar2 != (BIGNUM *)0x0) {
      pbVar7 = local_30[0] + 2;
      pbVar4 = local_30[0] + 1;
      bVar1 = *local_30[0];
      pbVar6 = local_30[0] + 3;
      local_30[0] = local_30[0] + 4;
      iVar3 = BN_set_word(pBVar2,(uint)*pbVar7 << 0x10 | (uint)*pbVar4 << 8 | (uint)bVar1 |
                                 (uint)*pbVar6 << 0x18);
      if (iVar3 != 0) {
        num_00 = param_2 + 7U >> 3;
        pbVar7 = local_30[0] + (num_00 - 1);
        pbVar4 = (byte *)CRYPTO_malloc(num_00,"pvkfmt.c",100);
        if (pbVar4 != (byte *)0x0) {
          pbVar6 = pbVar4;
          if (num_00 != 0) {
            do {
              pbVar5 = pbVar6 + 1;
              *pbVar6 = *pbVar7;
              pbVar6 = pbVar5;
              pbVar7 = pbVar7 + -1;
            } while (pbVar5 != pbVar4 + num_00);
          }
          pBVar2 = BN_bin2bn(pbVar4,num_00,(BIGNUM *)0x0);
          r->n = pBVar2;
          CRYPTO_free(pbVar4);
          if (r->n != (BIGNUM *)0x0) {
            local_30[0] = local_30[0] + num_00;
            if (param_3 != 0) {
LAB_000c4dae:
              EVP_PKEY_set1_RSA(pkey,r);
              RSA_free(r);
              *param_1 = local_30[0];
              return pkey;
            }
            num = param_2 + 0xfU >> 4;
            iVar3 = num - 1;
            pbVar7 = local_30[0] + iVar3;
            pbVar4 = (byte *)CRYPTO_malloc(num,"pvkfmt.c",100);
            if (pbVar4 != (byte *)0x0) {
              pbVar6 = pbVar4;
              if (num != 0) {
                do {
                  pbVar5 = pbVar6 + 1;
                  *pbVar6 = *pbVar7;
                  pbVar6 = pbVar5;
                  pbVar7 = pbVar7 + -1;
                } while (pbVar5 != pbVar4 + num);
              }
              pBVar2 = BN_bin2bn(pbVar4,num,(BIGNUM *)0x0);
              r->p = pBVar2;
              CRYPTO_free(pbVar4);
              if (r->p != (BIGNUM *)0x0) {
                pbVar4 = local_30[0] + num;
                local_30[0] = pbVar4;
                pbVar7 = (byte *)CRYPTO_malloc(num,"pvkfmt.c",100);
                if (pbVar7 != (byte *)0x0) {
                  pbVar4 = pbVar4 + iVar3;
                  pbVar6 = pbVar7;
                  if (num != 0) {
                    do {
                      pbVar5 = pbVar6 + 1;
                      *pbVar6 = *pbVar4;
                      pbVar4 = pbVar4 + -1;
                      pbVar6 = pbVar5;
                    } while (pbVar5 != pbVar7 + num);
                  }
                  pBVar2 = BN_bin2bn(pbVar7,num,(BIGNUM *)0x0);
                  r->q = pBVar2;
                  CRYPTO_free(pbVar7);
                  if (r->q != (BIGNUM *)0x0) {
                    pbVar4 = local_30[0] + num;
                    local_30[0] = pbVar4;
                    pbVar7 = (byte *)CRYPTO_malloc(num,"pvkfmt.c",100);
                    if (pbVar7 != (byte *)0x0) {
                      pbVar6 = pbVar7;
                      pbVar4 = pbVar4 + iVar3;
                      if (num != 0) {
                        do {
                          pbVar5 = pbVar6 + 1;
                          *pbVar6 = *pbVar4;
                          pbVar6 = pbVar5;
                          pbVar4 = pbVar4 + -1;
                        } while (pbVar5 != pbVar7 + num);
                      }
                      pBVar2 = BN_bin2bn(pbVar7,num,(BIGNUM *)0x0);
                      r->dmp1 = pBVar2;
                      CRYPTO_free(pbVar7);
                      if (r->dmp1 != (BIGNUM *)0x0) {
                        local_30[0] = local_30[0] + num;
                        iVar3 = read_lebn(local_30,num,&r->dmq1);
                        if (((iVar3 != 0) && (iVar3 = read_lebn(local_30,num,&r->iqmp), iVar3 != 0))
                           && (iVar3 = read_lebn(local_30,num_00,&r->d), iVar3 != 0))
                        goto LAB_000c4dae;
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
    ERR_put_error(9,0x81,0x41,"pvkfmt.c",0x18e);
    RSA_free(r);
  }
  if (pkey != (EVP_PKEY *)0x0) {
    EVP_PKEY_free(pkey);
    pkey = (EVP_PKEY *)0x0;
  }
  return pkey;
}

