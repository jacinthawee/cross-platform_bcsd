
int RSA_padding_check_PKCS1_type_2(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  byte *__s;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = -((fl | tlen) >> 0x1f);
  if (uVar4 == 0) {
    if ((fl <= rsa_len) && (10 < rsa_len)) {
      __s = (byte *)CRYPTO_malloc(rsa_len,"rsa_pk1.c",0xce);
      if (__s == (byte *)0x0) {
        ERR_put_error(4,0x71,0x41,"rsa_pk1.c",0xd0);
        return -1;
      }
      memset(__s,0,rsa_len);
      memcpy(__s + (rsa_len - fl),f,fl);
      uVar2 = 2;
      uVar5 = uVar4;
      do {
        uVar3 = (int)(__s[uVar2] - 1 & ~(uint)__s[uVar2]) >> 0x1f;
        uVar1 = uVar3 & ~uVar4;
        uVar4 = uVar4 | uVar3;
        uVar3 = uVar1 & uVar2;
        uVar2 = uVar2 + 1;
        uVar5 = uVar5 & ~uVar1 | uVar3;
      } while (uVar2 != rsa_len);
      uVar2 = uVar2 - (uVar5 + 1);
      if (((int)(*__s - 1 & ~(uint)*__s & (__s[1] ^ 2) - 1 & ~(__s[1] ^ 2)) >> 0x1f &
           ~((int)(uVar5 ^ (uVar5 - 10 ^ 10 | uVar5 ^ 10)) >> 0x1f) &
          ~((int)((tlen - uVar2 ^ uVar2 | uVar2 ^ tlen) ^ tlen) >> 0x1f)) == 0) {
        CRYPTO_free(__s);
      }
      else {
        memcpy(to,__s + uVar5 + 1,uVar2);
        CRYPTO_free(__s);
        if (uVar2 != 0xffffffff) {
          return uVar2;
        }
      }
    }
    ERR_put_error(4,0x71,0x9f,"rsa_pk1.c",0x111);
  }
  return -1;
}

