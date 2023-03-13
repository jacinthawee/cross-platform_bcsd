
int DH_check(DH *dh,int *codes)

{
  BIGNUM *pBVar1;
  BN_CTX *c;
  BIGNUM *r;
  int iVar2;
  ulong uVar3;
  int iVar4;
  
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
  pBVar1 = dh->g;
  if (pBVar1->top == 1) {
    if (*pBVar1->d == 2) {
      if (pBVar1->neg == 0) {
        uVar3 = BN_mod_word(dh->p,0x18);
        if (uVar3 == 0xb) goto LAB_0810fced;
        goto LAB_0810fda5;
      }
    }
    else if ((*pBVar1->d == 5) && (pBVar1->neg == 0)) {
      uVar3 = BN_mod_word(dh->p,10);
      if ((uVar3 & 0xfffffffb) == 3) goto LAB_0810fced;
LAB_0810fda5:
      *codes = *codes | 8;
      goto LAB_0810fced;
    }
  }
  *codes = *codes | 4;
LAB_0810fced:
  iVar2 = BN_is_prime_ex(dh->p,0,c,(BN_GENCB *)0x0);
  if (iVar2 == 0) {
    *codes = *codes | 1;
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
    iVar2 = BN_rshift1(r,dh->p);
    if (iVar2 != 0) {
      iVar4 = 1;
      iVar2 = BN_is_prime_ex(r,0,c,(BN_GENCB *)0x0);
      if (iVar2 == 0) {
        *codes = *codes | 2;
      }
    }
  }
  BN_CTX_free(c);
  BN_free(r);
  return iVar4;
}

