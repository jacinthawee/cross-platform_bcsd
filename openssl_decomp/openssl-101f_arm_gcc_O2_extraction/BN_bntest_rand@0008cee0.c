
int BN_bntest_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  undefined uVar1;
  BIGNUM *buf;
  int iVar2;
  byte bVar3;
  uint uVar4;
  size_t len;
  BIGNUM *pBVar5;
  undefined *puVar6;
  size_t sVar7;
  undefined4 in_stack_ffffffc0;
  undefined4 in_stack_ffffffc4;
  byte local_30 [4];
  time_t atStack_2c [2];
  
  if (bits == 0) {
    BN_set_word(rnd,0);
    return 1;
  }
  iVar2 = bits + 0xe;
  if (-1 < bits + 7) {
    iVar2 = bits + 7;
  }
  len = iVar2 >> 3;
  buf = (BIGNUM *)CRYPTO_malloc(len,"bn_rand.c",0x86);
  if (buf == (BIGNUM *)0x0) {
    ERR_put_error(3,0x7f,0x41,"bn_rand.c",0x89);
  }
  else {
    time(atStack_2c);
    RAND_add(atStack_2c,4,(double)CONCAT44(in_stack_ffffffc4,in_stack_ffffffc0));
    iVar2 = RAND_pseudo_bytes((uchar *)buf,len);
    if (iVar2 == -1) {
      pBVar5 = (BIGNUM *)0x0;
    }
    else {
      if (0 < (int)len) {
        puVar6 = (undefined *)((int)&buf[-1].flags + 3);
        sVar7 = 0;
LAB_0008cf6e:
        do {
          RAND_pseudo_bytes(local_30,1);
          if ((int)((uint)local_30[0] << 0x18) < 0) {
            if (sVar7 != 0) {
              uVar1 = *puVar6;
              sVar7 = sVar7 + 1;
              puVar6 = puVar6 + 1;
              *puVar6 = uVar1;
              if (sVar7 == len) break;
              goto LAB_0008cf6e;
            }
          }
          else if (local_30[0] < 0x2a) {
            puVar6[1] = 0;
          }
          else if (local_30[0] < 0x54) {
            puVar6[1] = 0xff;
          }
          sVar7 = sVar7 + 1;
          puVar6 = puVar6 + 1;
        } while (sVar7 != len);
      }
      uVar4 = (bits + -1) % 8;
      if (top == -1) {
        bVar3 = *(byte *)&buf->d;
      }
      else if (top == 0) {
        bVar3 = *(byte *)&buf->d | (byte)(1 << (uVar4 & 0xff));
      }
      else if (uVar4 == 0) {
        bVar3 = 1;
        *(byte *)((int)&buf->d + 1) = *(byte *)((int)&buf->d + 1) | 0x80;
      }
      else {
        bVar3 = *(byte *)&buf->d | (byte)(3 << (uVar4 - 1 & 0xff));
      }
      *(byte *)&buf->d = bVar3 & ~(byte)(0xff << (uVar4 + 1 & 0xff));
      if (bottom != 0) {
        *(byte *)((int)buf + (len - 1)) = *(byte *)((int)buf + (len - 1)) | 1;
      }
      pBVar5 = BN_bin2bn((uchar *)buf,len,rnd);
      if (pBVar5 != (BIGNUM *)0x0) {
        pBVar5 = (BIGNUM *)0x1;
      }
    }
    OPENSSL_cleanse(buf,len);
    CRYPTO_free(buf);
    buf = pBVar5;
  }
  return (int)buf;
}

