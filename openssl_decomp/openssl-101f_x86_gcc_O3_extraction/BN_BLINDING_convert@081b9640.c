
int BN_BLINDING_convert(BIGNUM *n,BN_BLINDING *b,BN_CTX *ctx)

{
  int iVar1;
  BN_BLINDING *pBVar2;
  BIGNUM *pBVar3;
  
  pBVar3 = *(BIGNUM **)b;
  if ((pBVar3 == (BIGNUM *)0x0) || (*(int *)(b + 4) == 0)) {
    ERR_put_error(3,100,0x6b,"bn_blind.c",0xe8);
    return 0;
  }
  if (*(int *)(b + 0x1c) != -1) {
    iVar1 = *(int *)(b + 0x1c) + 1;
    *(int *)(b + 0x1c) = iVar1;
    if (iVar1 == 0x20) {
      if ((*(int *)(b + 8) == 0) || ((*(uint *)(b + 0x20) & 2) != 0)) {
        if ((*(uint *)(b + 0x20) & 1) != 0) goto LAB_081b96d0;
        goto LAB_081b967b;
      }
      pBVar2 = BN_BLINDING_create_param
                         (b,(BIGNUM *)0x0,(BIGNUM *)0x0,ctx,(bn_mod_exp *)0x0,(BN_MONT_CTX *)0x0);
    }
    else {
      if (((byte)b[0x20] & 1) != 0) goto LAB_081b96d7;
LAB_081b967b:
      iVar1 = BN_mod_mul(pBVar3,pBVar3,pBVar3,*(BIGNUM **)(b + 0xc),ctx);
      if (iVar1 == 0) goto LAB_081b9698;
      pBVar3 = *(BIGNUM **)(b + 4);
      pBVar2 = (BN_BLINDING *)BN_mod_mul(pBVar3,pBVar3,pBVar3,*(BIGNUM **)(b + 0xc),ctx);
    }
    if (pBVar2 == (BN_BLINDING *)0x0) {
LAB_081b9698:
      if (*(int *)(b + 0x1c) == 0x20) {
        *(undefined4 *)(b + 0x1c) = 0;
      }
      return 0;
    }
    pBVar3 = *(BIGNUM **)b;
    if (*(int *)(b + 0x1c) != 0x20) goto LAB_081b96d7;
  }
LAB_081b96d0:
  *(undefined4 *)(b + 0x1c) = 0;
LAB_081b96d7:
  iVar1 = BN_mod_mul(n,n,pBVar3,*(BIGNUM **)(b + 0xc),ctx);
  return (uint)(iVar1 != 0);
}

