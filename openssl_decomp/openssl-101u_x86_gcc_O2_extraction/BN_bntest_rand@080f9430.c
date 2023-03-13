
int BN_bntest_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  byte bVar1;
  uint uVar2;
  byte *buf;
  int iVar3;
  BIGNUM *pBVar4;
  sbyte sVar5;
  size_t sVar6;
  size_t len;
  int in_GS_OFFSET;
  byte local_25;
  time_t local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((bits < 0) || ((bits == 1 && (0 < top)))) {
    ERR_put_error(3,0x7f,0x76,"bn_rand.c",0x7d);
    uVar2 = 0;
  }
  else if (bits == 0) {
    BN_set_word(rnd,0);
    uVar2 = 1;
  }
  else {
    len = bits + 7 >> 3;
    buf = (byte *)CRYPTO_malloc(len,"bn_rand.c",0x8a);
    if (buf == (byte *)0x0) {
      ERR_put_error(3,0x7f,0x41,"bn_rand.c",0x8c);
      uVar2 = 0;
    }
    else {
      time(&local_24);
      uVar2 = 0;
      RAND_add(&local_24,4,0.0);
      iVar3 = RAND_bytes(buf,len);
      if (0 < iVar3) {
        sVar6 = 0;
        if (0 < (int)len) {
          do {
            iVar3 = RAND_pseudo_bytes(&local_25,1);
            if (iVar3 < 0) {
              uVar2 = 0;
              goto LAB_080f95df;
            }
            if ((char)local_25 < '\0') {
              if (sVar6 != 0) {
                buf[sVar6] = buf[sVar6 - 1];
              }
            }
            else if (local_25 < 0x2a) {
              buf[sVar6] = 0;
            }
            else if (local_25 < 0x54) {
              buf[sVar6] = 0xff;
            }
            sVar6 = sVar6 + 1;
          } while (len != sVar6);
        }
        uVar2 = bits - 1U & 7;
        sVar5 = (sbyte)uVar2;
        if (top < 0) {
          bVar1 = *buf;
        }
        else if (top == 0) {
          bVar1 = (byte)(1 << sVar5) | *buf;
        }
        else if (uVar2 == 0) {
          buf[1] = buf[1] | 0x80;
          bVar1 = 1;
        }
        else {
          bVar1 = (byte)(3 << (sVar5 - 1U & 0x1f)) | *buf;
        }
        *buf = ~(byte)(0xff << sVar5 + 1) & bVar1;
        if (bottom != 0) {
          buf[len - 1] = buf[len - 1] | 1;
        }
        pBVar4 = BN_bin2bn(buf,len,rnd);
        uVar2 = (uint)(pBVar4 != (BIGNUM *)0x0);
      }
LAB_080f95df:
      OPENSSL_cleanse(buf,len);
      CRYPTO_free(buf);
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

