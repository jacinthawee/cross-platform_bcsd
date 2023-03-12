
int BN_BLINDING_convert(BIGNUM *n,BN_BLINDING *b,BN_CTX *ctx)

{
  BN_BLINDING *pBVar1;
  int iVar2;
  undefined4 in_r3;
  uint uVar3;
  BIGNUM *m;
  BIGNUM *pBVar4;
  
  pBVar4 = *(BIGNUM **)b;
  if ((pBVar4 == (BIGNUM *)0x0) || (*(int *)(b + 4) == 0)) {
    ERR_put_error(3,100,0x6b,"bn_blind.c",0xea);
    return 0;
  }
  iVar2 = *(int *)(b + 0x1c);
  if (iVar2 == -1) {
    in_r3 = 0;
  }
  if (iVar2 == -1) {
    *(undefined4 *)(b + 0x1c) = in_r3;
    goto LAB_001015ac;
  }
  iVar2 = iVar2 + 1;
  *(int *)(b + 0x1c) = iVar2;
  if ((iVar2 == 0x20) && (*(int *)(b + 8) != 0)) {
    uVar3 = *(uint *)(b + 0x20);
    if ((uVar3 & 2) != 0) goto LAB_00101598;
    m = (BIGNUM *)ctx;
    pBVar1 = BN_BLINDING_create_param
                       (b,(BIGNUM *)0x0,(BIGNUM *)0x0,ctx,(bn_mod_exp *)0x0,(BN_MONT_CTX *)0x0);
    iVar2 = *(int *)(b + 0x1c);
    if (pBVar1 != (BN_BLINDING *)0x0) {
      pBVar1 = (BN_BLINDING *)0x1;
    }
  }
  else {
    uVar3 = *(uint *)(b + 0x20);
LAB_00101598:
    m = (BIGNUM *)(uVar3 << 0x1f);
    if ((int)m < 0) {
      pBVar1 = (BN_BLINDING *)0x1;
    }
    else {
      m = *(BIGNUM **)(b + 0xc);
      pBVar1 = (BN_BLINDING *)BN_mod_mul(pBVar4,pBVar4,pBVar4,m,ctx);
      if (pBVar1 == (BN_BLINDING *)0x0) {
        iVar2 = *(int *)(b + 0x1c);
      }
      else {
        pBVar4 = *(BIGNUM **)(b + 4);
        m = *(BIGNUM **)(b + 0xc);
        pBVar1 = (BN_BLINDING *)BN_mod_mul(pBVar4,pBVar4,pBVar4,m,ctx);
        iVar2 = *(int *)(b + 0x1c);
        if (pBVar1 != (BN_BLINDING *)0x0) {
          pBVar1 = (BN_BLINDING *)0x1;
        }
      }
    }
  }
  if (iVar2 == 0x20) {
    m = (BIGNUM *)0x0;
  }
  if (iVar2 == 0x20) {
    *(BIGNUM **)(b + 0x1c) = m;
  }
  if (pBVar1 == (BN_BLINDING *)0x0) {
    return 0;
  }
  pBVar4 = *(BIGNUM **)b;
LAB_001015ac:
  iVar2 = BN_mod_mul(n,n,pBVar4,*(BIGNUM **)(b + 0xc),ctx);
  if (iVar2 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}

