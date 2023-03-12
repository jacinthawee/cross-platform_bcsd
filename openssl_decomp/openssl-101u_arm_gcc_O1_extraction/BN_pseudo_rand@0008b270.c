
int BN_pseudo_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  size_t len;
  BIGNUM *buf;
  int iVar1;
  byte bVar2;
  uint uVar3;
  BIGNUM *pBVar4;
  undefined4 in_stack_ffffffd0;
  undefined4 in_stack_ffffffd4;
  time_t tStack_24;
  
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
      len = bits + 7 >> 3;
      buf = (BIGNUM *)CRYPTO_malloc(len,"bn_rand.c",0x8a);
      if (buf == (BIGNUM *)0x0) {
        ERR_put_error(3,0x7f,0x41,"bn_rand.c",0x8c);
      }
      else {
        time(&tStack_24);
        RAND_add(&tStack_24,4,(double)CONCAT44(in_stack_ffffffd4,in_stack_ffffffd0));
        iVar1 = RAND_bytes((uchar *)buf,len);
        if (0 < iVar1) {
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
            bVar2 = *(byte *)&buf->d | (byte)(3 << (uVar3 - 1 & 0xff));
          }
          *(byte *)&buf->d = bVar2 & ~(byte)(0xff << uVar3 + 1);
          if (bottom != 0) {
            *(byte *)((int)buf + (len - 1)) = *(byte *)((int)buf + (len - 1)) | 1;
          }
          pBVar4 = BN_bin2bn((uchar *)buf,len,rnd);
          if (pBVar4 != (BIGNUM *)0x0) {
            pBVar4 = (BIGNUM *)0x1;
          }
        }
        OPENSSL_cleanse(buf,len);
        CRYPTO_free(buf);
        buf = pBVar4;
      }
      return (int)buf;
    }
  }
  ERR_put_error(3,0x7f,0x76,"bn_rand.c",0x7d);
  return 0;
}

