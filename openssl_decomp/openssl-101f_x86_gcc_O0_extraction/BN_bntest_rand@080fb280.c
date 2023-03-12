
int BN_bntest_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  byte *buf;
  int iVar1;
  BIGNUM *pBVar2;
  byte bVar3;
  byte bVar4;
  size_t len;
  size_t sVar5;
  uint uVar6;
  int in_GS_OFFSET;
  byte local_25;
  time_t local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (bits == 0) {
    BN_set_word(rnd,0);
    uVar6 = 1;
  }
  else {
    iVar1 = bits + 7;
    if (bits + 7 < 0) {
      iVar1 = bits + 0xe;
    }
    len = iVar1 >> 3;
    buf = (byte *)CRYPTO_malloc(len,"bn_rand.c",0x86);
    if (buf == (byte *)0x0) {
      uVar6 = 0;
      ERR_put_error(3,0x7f,0x41,"bn_rand.c",0x89);
    }
    else {
      time(&local_24);
      uVar6 = 0;
      RAND_add(&local_24,4,0.0);
      iVar1 = RAND_pseudo_bytes(buf,len);
      if (iVar1 != -1) {
        sVar5 = 0;
        if (0 < (int)len) {
          do {
            while (RAND_pseudo_bytes(&local_25,1), (char)local_25 < '\0') {
              if (0 < (int)sVar5) {
                buf[sVar5] = buf[sVar5 - 1];
              }
LAB_080fb324:
              sVar5 = sVar5 + 1;
              if (len == sVar5) goto LAB_080fb360;
            }
            if (local_25 < 0x2a) {
              buf[sVar5] = 0;
              goto LAB_080fb324;
            }
            if (0x53 < local_25) goto LAB_080fb324;
            buf[sVar5] = 0xff;
            sVar5 = sVar5 + 1;
          } while (len != sVar5);
        }
LAB_080fb360:
        iVar1 = (bits + -1) % 8;
        bVar3 = (byte)iVar1;
        if (top == -1) {
          bVar4 = *buf;
        }
        else if (top == 0) {
          bVar4 = (byte)(1 << (bVar3 & 0x1f)) | *buf;
        }
        else if (iVar1 == 0) {
          buf[1] = buf[1] | 0x80;
          bVar4 = 1;
        }
        else {
          bVar4 = (byte)(3 << (bVar3 - 1 & 0x1f)) | *buf;
        }
        *buf = bVar4 & ~(byte)(0xff << (bVar3 + 1 & 0x1f));
        if (bottom != 0) {
          buf[len - 1] = buf[len - 1] | 1;
        }
        pBVar2 = BN_bin2bn(buf,len,rnd);
        uVar6 = (uint)(pBVar2 != (BIGNUM *)0x0);
      }
      OPENSSL_cleanse(buf,len);
      CRYPTO_free(buf);
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}

