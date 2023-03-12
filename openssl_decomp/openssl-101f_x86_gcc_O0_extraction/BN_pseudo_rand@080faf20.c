
int BN_pseudo_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  byte bVar1;
  byte *buf;
  int iVar2;
  BIGNUM *pBVar3;
  byte bVar4;
  uint uVar5;
  size_t len;
  int in_GS_OFFSET;
  time_t local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (bits == 0) {
    BN_set_word(rnd,0);
    uVar5 = 1;
  }
  else {
    iVar2 = bits + 7;
    if (bits + 7 < 0) {
      iVar2 = bits + 0xe;
    }
    len = iVar2 >> 3;
    buf = (byte *)CRYPTO_malloc(len,"bn_rand.c",0x86);
    if (buf == (byte *)0x0) {
      ERR_put_error(3,0x7f,0x41,"bn_rand.c",0x89);
      uVar5 = 0;
    }
    else {
      time(&local_24);
      RAND_add(&local_24,4,0.0);
      iVar2 = RAND_pseudo_bytes(buf,len);
      uVar5 = 0;
      if (iVar2 != -1) {
        iVar2 = (bits + -1) % 8;
        bVar4 = (byte)iVar2;
        if (top == -1) {
          bVar1 = *buf;
        }
        else if (top == 0) {
          bVar1 = (byte)(1 << (bVar4 & 0x1f)) | *buf;
        }
        else if (iVar2 == 0) {
          buf[1] = buf[1] | 0x80;
          bVar1 = 1;
        }
        else {
          bVar1 = (byte)(3 << (bVar4 - 1 & 0x1f)) | *buf;
        }
        *buf = ~(byte)(0xff << (bVar4 + 1 & 0x1f)) & bVar1;
        if (bottom != 0) {
          buf[len - 1] = buf[len - 1] | 1;
        }
        pBVar3 = BN_bin2bn(buf,len,rnd);
        uVar5 = (uint)(pBVar3 != (BIGNUM *)0x0);
      }
      OPENSSL_cleanse(buf,len);
      CRYPTO_free(buf);
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}

