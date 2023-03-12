
BIGNUM * BN_bin2bn(uchar *s,int len,BIGNUM *ret)

{
  ulong *puVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar6;
  BIGNUM *pBVar7;
  byte *pbVar5;
  
  pBVar7 = (BIGNUM *)0x0;
  if (ret == (BIGNUM *)0x0) {
    ret = (BIGNUM *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"bn_lib.c",0x11b);
    if (ret == (BIGNUM *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(3,0x71,0x41,"bn_lib.c",0x11d);
      return (BIGNUM *)0x0;
    }
    ret->top = 0;
    ret->neg = 0;
    ret->dmax = 0;
    ret->d = (ulong *)0x0;
    ret->flags = 1;
    pBVar7 = ret;
  }
  if (len == 0) {
    ret->top = 0;
    return ret;
  }
  iVar6 = (len - 1U >> 2) + 1;
  if (ret->dmax < iVar6) {
    puVar1 = (ulong *)bn_expand_internal(ret,iVar6);
    if (puVar1 == (ulong *)0x0) {
      if (pBVar7 != (BIGNUM *)0x0) {
        uVar2 = pBVar7->flags;
        if ((pBVar7->d != (ulong *)0x0) && ((uVar2 & 2) == 0)) {
          (*(code *)PTR_CRYPTO_free_006a7f88)();
          uVar2 = pBVar7->flags;
        }
        if ((uVar2 & 1) == 0) {
          pBVar7->d = (ulong *)0x0;
          pBVar7->flags = uVar2 | 0x8000;
          return (BIGNUM *)0x0;
        }
        (*(code *)PTR_CRYPTO_free_006a7f88)(pBVar7);
      }
      return (BIGNUM *)0x0;
    }
    if (ret->d != (ulong *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    ret->d = puVar1;
    ret->dmax = iVar6;
  }
  ret->top = iVar6;
  uVar3 = 0;
  ret->neg = 0;
  uVar2 = len - 1U & 3;
  pbVar5 = s;
  do {
    while( true ) {
      pbVar4 = pbVar5 + 1;
      uVar3 = (uint)*pbVar5 | uVar3 << 8;
      pbVar5 = pbVar4;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      if (pbVar4 == s + len) {
        iVar6 = ret->top;
        goto LAB_004f64e0;
      }
    }
    iVar6 = iVar6 + -1;
    uVar2 = 3;
    ret->d[iVar6] = uVar3;
    uVar3 = 0;
  } while (pbVar4 != s + len);
  iVar6 = ret->top;
LAB_004f64e0:
  if (0 < iVar6) {
    puVar1 = ret->d + iVar6 + -2;
    do {
      if (puVar1[1] != 0) break;
      iVar6 = iVar6 + -1;
      puVar1 = puVar1 + -1;
    } while (iVar6 != 0);
    ret->top = iVar6;
  }
  return ret;
}

