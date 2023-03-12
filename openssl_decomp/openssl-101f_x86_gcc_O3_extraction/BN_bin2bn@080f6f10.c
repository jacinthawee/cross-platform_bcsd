
BIGNUM * BN_bin2bn(uchar *s,int len,BIGNUM *ret)

{
  ulong *puVar1;
  uint uVar2;
  BIGNUM *ptr;
  byte *pbVar3;
  int iVar5;
  uint uVar6;
  byte *pbVar4;
  
  ptr = (BIGNUM *)0x0;
  if (ret == (BIGNUM *)0x0) {
    ptr = (BIGNUM *)CRYPTO_malloc(0x14,"bn_lib.c",0x11b);
    if (ptr == (BIGNUM *)0x0) {
      ERR_put_error(3,0x71,0x41,"bn_lib.c",0x11d);
      return (BIGNUM *)0x0;
    }
    ptr->flags = 1;
    ptr->top = 0;
    ptr->neg = 0;
    ptr->dmax = 0;
    ptr->d = (ulong *)0x0;
    ret = ptr;
  }
  if (len == 0) {
    ret->top = 0;
  }
  else {
    iVar5 = (len - 1U >> 2) + 1;
    if (ret->dmax < iVar5) {
      puVar1 = (ulong *)bn_expand_internal();
      if (puVar1 == (ulong *)0x0) {
        if (ptr == (BIGNUM *)0x0) {
          return (BIGNUM *)0x0;
        }
        uVar2 = ptr->flags;
        if ((ptr->d != (ulong *)0x0) && ((uVar2 & 2) == 0)) {
          CRYPTO_free(ptr->d);
          uVar2 = ptr->flags;
        }
        if ((uVar2 & 1) != 0) {
          CRYPTO_free(ptr);
          return (BIGNUM *)0x0;
        }
        ptr->d = (ulong *)0x0;
        ptr->flags = uVar2 | 0x8000;
        return (BIGNUM *)0x0;
      }
      if (ret->d != (ulong *)0x0) {
        CRYPTO_free(ret->d);
      }
      ret->d = puVar1;
      ret->dmax = iVar5;
    }
    uVar6 = len - 1U & 3;
    ret->top = iVar5;
    ret->neg = 0;
    uVar2 = 0;
    pbVar4 = s;
    do {
      while( true ) {
        pbVar3 = pbVar4 + 1;
        uVar2 = uVar2 << 8 | (uint)*pbVar4;
        pbVar4 = pbVar3;
        if (uVar6 != 0) break;
        iVar5 = iVar5 + -1;
        uVar6 = 3;
        ret->d[iVar5] = uVar2;
        uVar2 = 0;
        if (pbVar3 == s + len) goto LAB_080f6fca;
      }
      uVar6 = uVar6 - 1;
    } while (pbVar3 != s + len);
LAB_080f6fca:
    iVar5 = ret->top;
    if (0 < iVar5) {
      do {
        if (ret->d[iVar5 + -1] != 0) break;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      ret->top = iVar5;
      return ret;
    }
  }
  return ret;
}

