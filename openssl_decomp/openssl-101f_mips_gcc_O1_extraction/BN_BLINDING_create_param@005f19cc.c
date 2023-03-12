
BN_BLINDING *
BN_BLINDING_create_param
          (BN_BLINDING *b,BIGNUM *e,BIGNUM *m,BN_CTX *ctx,bn_mod_exp *bn_mod_exp,BN_MONT_CTX *m_ctx)

{
  BIGNUM *pBVar1;
  int iVar2;
  uint uVar3;
  BIGNUM **ppBVar4;
  int iVar5;
  
  if (b == (BN_BLINDING *)0x0) {
    ppBVar4 = (BIGNUM **)BN_BLINDING_new((BIGNUM *)0x0,(BIGNUM *)0x0,m);
    if (ppBVar4 == (BIGNUM **)0x0) {
      return (BN_BLINDING *)0x0;
    }
    pBVar1 = *ppBVar4;
  }
  else {
    pBVar1 = *(BIGNUM **)b;
    ppBVar4 = (BIGNUM **)b;
  }
  if (pBVar1 == (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)(*(code *)PTR_BN_new_006a82b4)();
    *ppBVar4 = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_005f1b1c;
  }
  if (ppBVar4[1] == (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)(*(code *)PTR_BN_new_006a82b4)();
    ppBVar4[1] = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_005f1b1c;
  }
  if (e == (BIGNUM *)0x0) {
    pBVar1 = ppBVar4[2];
  }
  else {
    if (ppBVar4[2] != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_free_006a811c)();
    }
    pBVar1 = (BIGNUM *)(*(code *)PTR_BN_dup_006a9100)(e);
    ppBVar4[2] = pBVar1;
  }
  if (pBVar1 != (BIGNUM *)0x0) {
    if (bn_mod_exp != (bn_mod_exp *)0x0) {
      ppBVar4[10] = (BIGNUM *)bn_mod_exp;
    }
    if (m_ctx != (BN_MONT_CTX *)0x0) {
      ppBVar4[9] = (BIGNUM *)m_ctx;
    }
    iVar5 = 0x21;
    while( true ) {
      iVar5 = iVar5 + -1;
      iVar2 = (*(code *)PTR_BN_rand_range_006a97b0)(*ppBVar4,ppBVar4[3]);
      if (iVar2 == 0) break;
      pBVar1 = BN_mod_inverse(ppBVar4[1],*ppBVar4,ppBVar4[3],ctx);
      if (pBVar1 != (BIGNUM *)0x0) {
        if ((ppBVar4[10] == (BIGNUM *)0x0) || (ppBVar4[9] == (BIGNUM *)0x0)) {
          iVar5 = (*(code *)PTR_BN_mod_exp_006a8a48)(*ppBVar4,*ppBVar4,ppBVar4[2],ppBVar4[3],ctx);
        }
        else {
          iVar5 = (*(code *)ppBVar4[10])(*ppBVar4,*ppBVar4,ppBVar4[2],ppBVar4[3],ctx,ppBVar4[9]);
        }
        if (iVar5 != 0) {
          return (BN_BLINDING *)ppBVar4;
        }
        break;
      }
      uVar3 = (*(code *)PTR_ERR_peek_last_error_006a8508)();
      if ((uVar3 & 0xfff) != 0x6c) break;
      if (iVar5 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(3,0x80,0x71,"bn_blind.c",0x161);
        break;
      }
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
    }
  }
LAB_005f1b1c:
  if (b == (BN_BLINDING *)0x0) {
    if (*ppBVar4 != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_free_006a811c)();
    }
    if (ppBVar4[1] != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_free_006a811c)();
    }
    if (ppBVar4[2] != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_free_006a811c)();
    }
    if (ppBVar4[3] != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_free_006a811c)();
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(ppBVar4);
    ppBVar4 = (BIGNUM **)0x0;
  }
  return (BN_BLINDING *)ppBVar4;
}

