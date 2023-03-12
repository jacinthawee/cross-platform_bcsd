
int BN_BLINDING_convert_ex(BIGNUM *n,BIGNUM *r,BN_BLINDING *b,BN_CTX *param_4)

{
  int iVar1;
  BIGNUM *pBVar2;
  BN_BLINDING *pBVar3;
  uint uVar4;
  
  pBVar2 = *(BIGNUM **)b;
  if ((pBVar2 == (BIGNUM *)0x0) || (*(int *)(b + 4) == 0)) {
    ERR_put_error(3,100,0x6b,"bn_blind.c",0xe8);
    return 0;
  }
  if (*(int *)(b + 0x1c) != -1) {
    iVar1 = *(int *)(b + 0x1c) + 1;
    *(int *)(b + 0x1c) = iVar1;
    if (iVar1 == 0x20) {
      if ((*(int *)(b + 8) == 0) || ((*(uint *)(b + 0x20) & 2) != 0)) {
        if ((*(uint *)(b + 0x20) & 1) != 0) goto LAB_081b9840;
        goto LAB_081b97e1;
      }
      pBVar3 = BN_BLINDING_create_param
                         (b,(BIGNUM *)0x0,(BIGNUM *)0x0,param_4,(bn_mod_exp *)0x0,(BN_MONT_CTX *)0x0
                         );
    }
    else {
      if (((byte)b[0x20] & 1) != 0) goto LAB_081b9847;
LAB_081b97e1:
      iVar1 = BN_mod_mul(pBVar2,pBVar2,pBVar2,*(BIGNUM **)(b + 0xc),param_4);
      if (iVar1 == 0) goto LAB_081b97fe;
      pBVar2 = *(BIGNUM **)(b + 4);
      pBVar3 = (BN_BLINDING *)BN_mod_mul(pBVar2,pBVar2,pBVar2,*(BIGNUM **)(b + 0xc),param_4);
    }
    if (pBVar3 == (BN_BLINDING *)0x0) {
LAB_081b97fe:
      if (*(int *)(b + 0x1c) == 0x20) {
        *(undefined4 *)(b + 0x1c) = 0;
        return 0;
      }
      return 0;
    }
    if (*(int *)(b + 0x1c) != 0x20) goto LAB_081b9847;
  }
LAB_081b9840:
  *(undefined4 *)(b + 0x1c) = 0;
LAB_081b9847:
  uVar4 = 1;
  if (r != (BIGNUM *)0x0) {
    pBVar2 = BN_copy(r,*(BIGNUM **)(b + 4));
    uVar4 = (uint)(pBVar2 != (BIGNUM *)0x0);
  }
  iVar1 = BN_mod_mul(n,n,*(BIGNUM **)b,*(BIGNUM **)(b + 0xc),param_4);
  if (iVar1 != 0) {
    return uVar4;
  }
  return 0;
}

