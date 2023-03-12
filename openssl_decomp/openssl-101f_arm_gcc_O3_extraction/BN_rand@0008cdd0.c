
int BN_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  BIGNUM *buf;
  int iVar1;
  byte bVar2;
  uint uVar3;
  BIGNUM *pBVar4;
  size_t len;
  bool bVar5;
  undefined4 in_stack_ffffffd0;
  undefined4 in_stack_ffffffd4;
  time_t atStack_24 [2];
  
  if (bits == 0) {
    BN_set_word(rnd,0);
    return 1;
  }
  iVar1 = bits + 0xe;
  if (-1 < bits + 7) {
    iVar1 = bits + 7;
  }
  len = iVar1 >> 3;
  buf = (BIGNUM *)CRYPTO_malloc(len,"bn_rand.c",0x86);
  if (buf == (BIGNUM *)0x0) {
    ERR_put_error(3,0x7f,0x41,"bn_rand.c",0x89);
  }
  else {
    time(atStack_24);
    RAND_add(atStack_24,4,(double)CONCAT44(in_stack_ffffffd4,in_stack_ffffffd0));
    iVar1 = RAND_bytes((uchar *)buf,len);
    if (iVar1 < 1) {
      pBVar4 = (BIGNUM *)0x0;
    }
    else {
      uVar3 = top + 1;
      bVar5 = uVar3 == 0;
      if (bVar5) {
        uVar3 = (uint)*(byte *)&buf->d;
      }
      bVar2 = (byte)uVar3;
      uVar3 = (bits + -1) % 8;
      if (!bVar5) {
        if (top == 0) {
          bVar2 = (byte)(1 << (uVar3 & 0xff)) | *(byte *)&buf->d;
        }
        else if (uVar3 == 0) {
          bVar2 = 1;
          *(byte *)((int)&buf->d + 1) = *(byte *)((int)&buf->d + 1) | 0x80;
        }
        else {
          bVar2 = (byte)(3 << (uVar3 - 1 & 0xff)) | *(byte *)&buf->d;
        }
      }
      *(byte *)&buf->d = bVar2 & ~(byte)(0xff << (uVar3 + 1 & 0xff));
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

