
int BN_BLINDING_convert_ex(BIGNUM *n,BIGNUM *r,BN_BLINDING *b,BN_CTX *param_4)

{
  uint uVar1;
  BN_BLINDING *pBVar2;
  int iVar3;
  BIGNUM *m;
  BIGNUM *pBVar4;
  
  pBVar4 = *(BIGNUM **)b;
  if ((pBVar4 == (BIGNUM *)0x0) || (*(int *)(b + 4) == 0)) {
    ERR_put_error(3,100,0x6b,"bn_blind.c",0xe8);
    return 0;
  }
  iVar3 = *(int *)(b + 0x1c);
  m = (BIGNUM *)param_4;
  if (iVar3 == -1) {
    m = (BIGNUM *)0x0;
  }
  if (iVar3 == -1) {
    *(BIGNUM **)(b + 0x1c) = m;
    goto LAB_0010344a;
  }
  iVar3 = iVar3 + 1;
  *(int *)(b + 0x1c) = iVar3;
  if ((iVar3 == 0x20) && (*(int *)(b + 8) != 0)) {
    uVar1 = *(uint *)(b + 0x20);
    if ((uVar1 & 2) != 0) goto LAB_00103438;
    pBVar2 = BN_BLINDING_create_param
                       (b,(BIGNUM *)0x0,(BIGNUM *)0x0,(BN_CTX *)m,(bn_mod_exp *)0x0,
                        (BN_MONT_CTX *)0x0);
    iVar3 = *(int *)(b + 0x1c);
    if (pBVar2 != (BN_BLINDING *)0x0) {
      pBVar2 = (BN_BLINDING *)0x1;
    }
  }
  else {
    uVar1 = *(uint *)(b + 0x20);
LAB_00103438:
    m = (BIGNUM *)(uVar1 << 0x1f);
    if ((int)m < 0) {
      pBVar2 = (BN_BLINDING *)0x1;
    }
    else {
      m = *(BIGNUM **)(b + 0xc);
      pBVar2 = (BN_BLINDING *)BN_mod_mul(pBVar4,pBVar4,pBVar4,m,param_4);
      if (pBVar2 == (BN_BLINDING *)0x0) {
        iVar3 = *(int *)(b + 0x1c);
      }
      else {
        pBVar4 = *(BIGNUM **)(b + 4);
        m = *(BIGNUM **)(b + 0xc);
        pBVar2 = (BN_BLINDING *)BN_mod_mul(pBVar4,pBVar4,pBVar4,m,param_4);
        iVar3 = *(int *)(b + 0x1c);
        if (pBVar2 != (BN_BLINDING *)0x0) {
          pBVar2 = (BN_BLINDING *)0x1;
        }
      }
    }
  }
  if (iVar3 == 0x20) {
    m = (BIGNUM *)0x0;
  }
  if (iVar3 == 0x20) {
    *(BIGNUM **)(b + 0x1c) = m;
  }
  if (pBVar2 == (BN_BLINDING *)0x0) {
    return 0;
  }
LAB_0010344a:
  if (r == (BIGNUM *)0x0) {
    pBVar4 = (BIGNUM *)0x1;
  }
  else {
    pBVar4 = BN_copy(r,*(BIGNUM **)(b + 4));
    if (pBVar4 != (BIGNUM *)0x0) {
      pBVar4 = (BIGNUM *)0x1;
    }
  }
  iVar3 = BN_mod_mul(n,n,*(BIGNUM **)b,*(BIGNUM **)(b + 0xc),param_4);
  if (iVar3 == 0) {
    pBVar4 = (BIGNUM *)0x0;
  }
  return (int)pBVar4;
}

