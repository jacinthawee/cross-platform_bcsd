
int DH_check(DH *dh,int *codes)

{
  BN_CTX *c;
  BIGNUM *r;
  int iVar1;
  int iVar2;
  ulong uVar3;
  BIGNUM *pBVar4;
  
  *codes = 0;
  c = BN_CTX_new();
  if (c == (BN_CTX *)0x0) {
    return 0;
  }
  r = BN_new();
  if (r == (BIGNUM *)0x0) {
    BN_CTX_free(c);
    return 0;
  }
  pBVar4 = dh->g;
  if (pBVar4->top == 1) {
    if (*pBVar4->d == 2) {
      if (pBVar4->neg == 0) {
        uVar3 = BN_mod_word(dh->p,0x18);
        if (uVar3 == 0xb) goto LAB_0009aad4;
        goto LAB_0009ab4e;
      }
    }
    else if ((*pBVar4->d == 5) && (pBVar4->neg == 0)) {
      uVar3 = BN_mod_word(dh->p,10);
      if ((uVar3 & 0xfffffffb) == 3) goto LAB_0009aad4;
LAB_0009ab4e:
      *codes = *codes | 8;
      goto LAB_0009aad4;
    }
  }
  *codes = *codes | 4;
LAB_0009aad4:
  iVar1 = BN_is_prime_ex(dh->p,0,c,(BN_GENCB *)0x0);
  if (iVar1 == 0) {
    iVar1 = 1;
    *codes = *codes | 1;
  }
  else {
    iVar1 = BN_rshift1(r,dh->p);
    if (iVar1 != 0) {
      iVar2 = BN_is_prime_ex(r,0,c,(BN_GENCB *)0x0);
      iVar1 = 1;
      if (iVar2 == 0) {
        iVar1 = 1;
        *codes = *codes | 2;
      }
    }
  }
  BN_CTX_free(c);
  BN_free(r);
  return iVar1;
}

