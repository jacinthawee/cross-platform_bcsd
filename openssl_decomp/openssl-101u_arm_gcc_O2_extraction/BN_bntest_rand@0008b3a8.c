
int BN_bntest_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  BIGNUM *buf;
  int iVar1;
  byte bVar2;
  BIGNUM *len;
  uint uVar3;
  BIGNUM *pBVar4;
  undefined *puVar5;
  undefined4 in_stack_ffffffc8;
  undefined4 in_stack_ffffffcc;
  byte local_30 [4];
  time_t atStack_2c [2];
  
  if (-1 < bits) {
    uVar3 = count_leading_zeroes(bits + -1);
    pBVar4 = (BIGNUM *)(uVar3 >> 5);
    if (top < 1) {
      pBVar4 = (BIGNUM *)0x0;
    }
    if (pBVar4 == (BIGNUM *)0x0) {
      if (bits == 0) {
        BN_set_word(rnd,0);
        return 1;
      }
      len = (BIGNUM *)(bits + 7 >> 3);
      buf = (BIGNUM *)CRYPTO_malloc((int)len,"bn_rand.c",0x8a);
      if (buf == (BIGNUM *)0x0) {
        ERR_put_error(3,0x7f,0x41,"bn_rand.c",0x8c);
        pBVar4 = buf;
      }
      else {
        time(atStack_2c);
        RAND_add(atStack_2c,4,(double)CONCAT44(in_stack_ffffffcc,in_stack_ffffffc8));
        iVar1 = RAND_bytes((uchar *)buf,(int)len);
        if (0 < iVar1) {
          if (0 < (int)len) {
            puVar5 = (undefined *)((int)&buf[-1].flags + 3);
            do {
              iVar1 = RAND_pseudo_bytes(local_30,1);
              if (iVar1 < 0) {
                OPENSSL_cleanse(buf,(size_t)len);
                CRYPTO_free(buf);
                return 0;
              }
              if ((int)((uint)local_30[0] << 0x18) < 0) {
                if (pBVar4 != (BIGNUM *)0x0) {
                  puVar5[1] = *puVar5;
                }
              }
              else if (local_30[0] < 0x2a) {
                puVar5[1] = 0;
              }
              else if (local_30[0] < 0x54) {
                puVar5[1] = 0xff;
              }
              pBVar4 = (BIGNUM *)((int)&pBVar4->d + 1);
              puVar5 = puVar5 + 1;
            } while (pBVar4 != len);
          }
          uVar3 = bits - 1U & 7;
          if (top < 0) {
            bVar2 = *(byte *)&buf->d;
          }
          else if (top == 0) {
            bVar2 = (byte)(1 << uVar3) | *(byte *)&buf->d;
          }
          else if (uVar3 == 0) {
            bVar2 = 1;
            *(byte *)((int)&buf->d + 1) = *(byte *)((int)&buf->d + 1) | 0x80;
          }
          else {
            bVar2 = (byte)(3 << (uVar3 - 1 & 0xff)) | *(byte *)&buf->d;
          }
          *(byte *)&buf->d = bVar2 & ~(byte)(0xff << uVar3 + 1);
          if (bottom != 0) {
            puVar5 = (undefined *)((int)&len[-1].flags + 3);
            puVar5[(int)&buf->d] = puVar5[(int)&buf->d] | 1;
          }
          pBVar4 = BN_bin2bn((uchar *)buf,(int)len,rnd);
          if (pBVar4 != (BIGNUM *)0x0) {
            pBVar4 = (BIGNUM *)0x1;
          }
        }
        OPENSSL_cleanse(buf,(size_t)len);
        CRYPTO_free(buf);
      }
      return (int)pBVar4;
    }
  }
  ERR_put_error(3,0x7f,0x76,"bn_rand.c",0x7d);
  return 0;
}

