
void BN_CTX_init(BN_CTX *c)

{
  BIGNUM *a;
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  
  pBVar2 = *(BIGNUM **)c;
  if (pBVar2 == (BIGNUM *)0x0) {
    *(undefined4 *)(c + 4) = 0;
    *(undefined4 *)(c + 0xc) = 0;
    *(undefined4 *)(c + 0x18) = 0;
    *(undefined4 *)(c + 0x20) = 0;
    *(undefined4 *)(c + 0x24) = 0;
    *(undefined4 *)(c + 0x28) = 0;
    return;
  }
  do {
    a = pBVar2;
    do {
      pBVar1 = a + 1;
      if (a->d != (ulong *)0x0) {
        BN_clear(a);
      }
      a = pBVar1;
    } while (pBVar1 != pBVar2 + 0x10);
    pBVar2 = (BIGNUM *)pBVar2[0x10].top;
  } while (pBVar2 != (BIGNUM *)0x0);
  *(undefined4 *)(c + 4) = *(undefined4 *)c;
  *(undefined4 *)(c + 0xc) = 0;
  *(undefined4 *)(c + 0x18) = 0;
  *(undefined4 *)(c + 0x20) = 0;
  *(undefined4 *)(c + 0x24) = 0;
  *(undefined4 *)(c + 0x28) = 0;
  return;
}

