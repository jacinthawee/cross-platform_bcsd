
BIGNUM * BN_bin2bn(uchar *s,int len,BIGNUM *ret)

{
  ulong *puVar1;
  uint uVar2;
  byte *pbVar3;
  BIGNUM *ptr;
  uint uVar5;
  int iVar6;
  bool bVar7;
  byte *pbVar4;
  
  ptr = (BIGNUM *)0x0;
  if (ret == (BIGNUM *)0x0) {
    ptr = (BIGNUM *)CRYPTO_malloc(0x14,"bn_lib.c",0x110);
    if (ptr == (BIGNUM *)0x0) {
      ERR_put_error(3,0x71,0x41,"bn_lib.c",0x111);
      return (BIGNUM *)0x0;
    }
    ptr->top = 0;
    ptr->neg = 0;
    ptr->dmax = 0;
    ptr->d = (ulong *)0x0;
    ptr->flags = 1;
    ret = ptr;
  }
  if (len == 0) {
    ret->top = 0;
  }
  else {
    iVar6 = (len - 1U >> 2) + 1;
    if (ret->dmax < iVar6) {
      puVar1 = (ulong *)bn_expand_internal(ret,iVar6);
      if (puVar1 == (ulong *)0x0) {
        if (ptr == (BIGNUM *)0x0) {
          return (BIGNUM *)0x0;
        }
        uVar2 = ptr->flags;
        if ((ptr->d != (ulong *)0x0) && (-1 < (int)(uVar2 << 0x1e))) {
          CRYPTO_free(ptr->d);
          uVar2 = ptr->flags;
        }
        bVar7 = (uVar2 & 1) == 0;
        if (bVar7) {
          ptr->d = (ulong *)0x0;
          uVar2 = uVar2 | 0x8000;
        }
        if (!bVar7) {
          CRYPTO_free(ptr);
          return (BIGNUM *)0x0;
        }
        ptr->flags = uVar2;
        return (BIGNUM *)0x0;
      }
      if (ret->d != (ulong *)0x0) {
        CRYPTO_free(ret->d);
      }
      ret->d = puVar1;
      ret->dmax = iVar6;
    }
    ret->top = iVar6;
    ret->neg = 0;
    uVar2 = 0;
    pbVar4 = s;
    uVar5 = len - 1U & 3;
    do {
      while( true ) {
        pbVar3 = pbVar4 + 1;
        uVar2 = (uint)*pbVar4 | uVar2 << 8;
        pbVar4 = pbVar3;
        if (uVar5 != 0) break;
        iVar6 = iVar6 + -1;
        ret->d[iVar6] = uVar2;
        uVar2 = uVar5;
        uVar5 = 3;
        if (pbVar3 == s + len) goto LAB_00088484;
      }
      uVar5 = uVar5 - 1;
    } while (pbVar3 != s + len);
LAB_00088484:
    iVar6 = ret->top;
    if (0 < iVar6) {
      puVar1 = ret->d + iVar6 + 0x3fffffff;
      do {
        if (*puVar1 != 0) break;
        iVar6 = iVar6 + -1;
        puVar1 = puVar1 + -1;
      } while (iVar6 != 0);
      ret->top = iVar6;
      return ret;
    }
  }
  return ret;
}

