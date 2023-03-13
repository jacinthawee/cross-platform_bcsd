
int RSA_padding_check_PKCS1_type_2(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  byte *pbVar1;
  byte *__s;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int reason;
  int line;
  
  if (tlen < 0) {
    return -1;
  }
  if (fl < 0) {
    return -1;
  }
  if ((10 < rsa_len) && (fl <= rsa_len)) {
    __s = (byte *)CRYPTO_malloc(rsa_len,"rsa_pk1.c",0xce);
    if (__s == (byte *)0x0) {
      line = 0xd0;
      reason = 0x41;
      goto LAB_0810a93f;
    }
    uVar6 = 0;
    memset(__s,0,rsa_len);
    uVar5 = 2;
    memcpy(__s + (rsa_len - fl),f,fl);
    uVar7 = 0;
    do {
      pbVar1 = __s + uVar5;
      uVar4 = uVar5 ^ uVar7;
      uVar5 = uVar5 + 1;
      uVar3 = ~uVar6;
      uVar2 = (int)(*pbVar1 - 1 & ~(uint)*pbVar1) >> 0x1f;
      uVar6 = uVar6 | uVar2;
      uVar7 = uVar7 ^ uVar4 & uVar3 & uVar2;
    } while ((int)uVar5 < rsa_len);
    uVar5 = rsa_len - (uVar7 + 1);
    if ((~((int)((tlen - uVar5 ^ uVar5 | tlen ^ uVar5) ^ tlen) >> 0x1f) &
        ~((int)((uVar7 - 10 ^ 10 | uVar7 ^ 10) ^ uVar7) >> 0x1f) &
        (int)(~(uint)*__s & *__s - 1 & ~(uint)(__s[1] ^ 2) & (__s[1] ^ 2) - 1) >> 0x1f) == 0) {
      CRYPTO_free(__s);
    }
    else {
      memcpy(to,__s + uVar7 + 1,uVar5);
      CRYPTO_free(__s);
      if (uVar5 != 0xffffffff) {
        return uVar5;
      }
    }
  }
  line = 0x111;
  reason = 0x9f;
LAB_0810a93f:
  ERR_put_error(4,0x71,reason,"rsa_pk1.c",line);
  return -1;
}

