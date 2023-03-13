
int DH_check(DH *dh,int *codes)

{
  undefined *puVar1;
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *pBVar2;
  int iVar3;
  ulong uVar4;
  
  puVar1 = PTR_BN_CTX_new_006a794c;
  *codes = 0;
  ctx = (BN_CTX *)(*(code *)puVar1)();
  if (ctx == (BN_CTX *)0x0) {
    return 0;
  }
  r = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
  if (r == (BIGNUM *)0x0) {
    (*(code *)PTR_BN_CTX_free_006a7954)(ctx);
    return 0;
  }
  pBVar2 = dh->g;
  if (pBVar2->top == 1) {
    if (*pBVar2->d == 2) {
      if (pBVar2->neg == 0) {
        uVar4 = BN_mod_word(dh->p,0x18);
        if (uVar4 == 0xb) goto LAB_005165fc;
        goto LAB_005166f8;
      }
    }
    else if ((*pBVar2->d == 5) && (pBVar2->neg == 0)) {
      uVar4 = BN_mod_word(dh->p,10);
      if ((uVar4 & 0xfffffffb) == 3) goto LAB_005165fc;
LAB_005166f8:
      *codes = *codes | 8;
      goto LAB_005165fc;
    }
  }
  *codes = *codes | 4;
LAB_005165fc:
  iVar3 = BN_is_prime_ex(dh->p,0,ctx,(BN_GENCB *)0x0);
  if (iVar3 == 0) {
    iVar3 = 1;
    *codes = *codes | 1;
  }
  else {
    iVar3 = BN_rshift1(r,dh->p);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = BN_is_prime_ex(r,0,ctx,(BN_GENCB *)0x0);
      if (iVar3 == 0) {
        iVar3 = 1;
        *codes = *codes | 2;
      }
      else {
        iVar3 = 1;
      }
    }
  }
  (*(code *)PTR_BN_CTX_free_006a7954)(ctx);
  (*(code *)PTR_BN_free_006a701c)(r);
  return iVar3;
}

