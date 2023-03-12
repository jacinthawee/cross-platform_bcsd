
int BN_BLINDING_update(BN_BLINDING *b,BN_CTX *ctx)

{
  BN_BLINDING *pBVar1;
  int iVar2;
  char *m;
  BIGNUM *pBVar3;
  uint uVar4;
  
  pBVar3 = *(BIGNUM **)b;
  if ((pBVar3 == (BIGNUM *)0x0) || (*(int *)(b + 4) == 0)) {
    m = "bn_blind.c";
    ERR_put_error(3,0x67,0x6b,"bn_blind.c",0xc0);
    iVar2 = *(int *)(b + 0x1c);
    pBVar1 = (BN_BLINDING *)0x0;
  }
  else {
    if (*(int *)(b + 0x1c) == -1) {
      iVar2 = 1;
      *(undefined4 *)(b + 0x1c) = 1;
      m = (char *)(*(int *)(b + 0x20) << 0x1f);
      if ((int)m < 0) {
        pBVar1 = (BN_BLINDING *)0x1;
        goto LAB_001032bc;
      }
    }
    else {
      iVar2 = *(int *)(b + 0x1c) + 1;
      *(int *)(b + 0x1c) = iVar2;
      if (iVar2 == 0x20) {
        uVar4 = *(uint *)(b + 0x20);
        if ((*(int *)(b + 8) != 0) && ((uVar4 & 2) == 0)) {
          pBVar1 = BN_BLINDING_create_param
                             (b,(BIGNUM *)0x0,(BIGNUM *)0x0,ctx,(bn_mod_exp *)0x0,(BN_MONT_CTX *)0x0
                             );
          iVar2 = *(int *)(b + 0x1c);
          m = (char *)ctx;
          if (pBVar1 != (BN_BLINDING *)0x0) {
            pBVar1 = (BN_BLINDING *)0x1;
          }
          goto LAB_001032bc;
        }
      }
      else {
        uVar4 = *(uint *)(b + 0x20);
      }
      m = (char *)(uVar4 << 0x1f);
      if ((int)m < 0) {
        pBVar1 = (BN_BLINDING *)0x1;
        goto LAB_001032bc;
      }
    }
    m = *(char **)(b + 0xc);
    pBVar1 = (BN_BLINDING *)BN_mod_mul(pBVar3,pBVar3,pBVar3,(BIGNUM *)m,ctx);
    if (pBVar1 == (BN_BLINDING *)0x0) {
      iVar2 = *(int *)(b + 0x1c);
    }
    else {
      pBVar3 = *(BIGNUM **)(b + 4);
      m = *(char **)(b + 0xc);
      pBVar1 = (BN_BLINDING *)BN_mod_mul(pBVar3,pBVar3,pBVar3,(BIGNUM *)m,ctx);
      iVar2 = *(int *)(b + 0x1c);
      if (pBVar1 != (BN_BLINDING *)0x0) {
        pBVar1 = (BN_BLINDING *)0x1;
      }
    }
  }
LAB_001032bc:
  if (iVar2 == 0x20) {
    m = (char *)0x0;
  }
  if (iVar2 == 0x20) {
    *(char **)(b + 0x1c) = m;
  }
  return (int)pBVar1;
}

