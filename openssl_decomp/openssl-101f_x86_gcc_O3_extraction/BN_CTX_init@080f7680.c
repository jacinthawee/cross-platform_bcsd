
void BN_CTX_init(BN_CTX *c)

{
  undefined4 uVar1;
  BIGNUM *a;
  BIGNUM *pBVar2;
  
  pBVar2 = *(BIGNUM **)c;
  if (pBVar2 == (BIGNUM *)0x0) {
    uVar1 = 0;
  }
  else {
    do {
      a = pBVar2;
      do {
        if (a->d != (ulong *)0x0) {
          BN_clear(a);
        }
        a = a + 1;
      } while (a != pBVar2 + 0x10);
      pBVar2 = (BIGNUM *)pBVar2[0x10].top;
    } while (pBVar2 != (BIGNUM *)0x0);
    uVar1 = *(undefined4 *)c;
  }
  *(undefined4 *)(c + 4) = uVar1;
  *(undefined4 *)(c + 0xc) = 0;
  *(undefined4 *)(c + 0x18) = 0;
  *(undefined4 *)(c + 0x20) = 0;
  *(undefined4 *)(c + 0x24) = 0;
  *(undefined4 *)(c + 0x28) = 0;
  return;
}

