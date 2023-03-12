
int BN_BLINDING_update(BN_BLINDING *b,BN_CTX *ctx)

{
  BN_BLINDING BVar1;
  BIGNUM *pBVar2;
  int iVar3;
  uint uVar4;
  BN_BLINDING *pBVar5;
  
  pBVar2 = *(BIGNUM **)b;
  if ((pBVar2 == (BIGNUM *)0x0) || (*(int *)(b + 4) == 0)) {
    ERR_put_error(3,0x67,0x6b,"bn_blind.c",0xc0);
    iVar3 = *(int *)(b + 0x1c);
    uVar4 = 0;
  }
  else {
    if (*(int *)(b + 0x1c) == -1) {
      BVar1 = b[0x20];
      *(undefined4 *)(b + 0x1c) = 1;
joined_r0x081b959b:
      if (((byte)BVar1 & 1) != 0) {
        return 1;
      }
LAB_081b959d:
      uVar4 = BN_mod_mul(pBVar2,pBVar2,pBVar2,*(BIGNUM **)(b + 0xc),ctx);
      if (uVar4 != 0) {
        pBVar2 = *(BIGNUM **)(b + 4);
        pBVar5 = (BN_BLINDING *)BN_mod_mul(pBVar2,pBVar2,pBVar2,*(BIGNUM **)(b + 0xc),ctx);
        goto LAB_081b960d;
      }
    }
    else {
      iVar3 = *(int *)(b + 0x1c) + 1;
      *(int *)(b + 0x1c) = iVar3;
      if (iVar3 != 0x20) {
        BVar1 = b[0x20];
        goto joined_r0x081b959b;
      }
      if ((*(int *)(b + 8) == 0) || ((*(uint *)(b + 0x20) & 2) != 0)) {
        if ((*(uint *)(b + 0x20) & 1) != 0) {
          uVar4 = 1;
          goto LAB_081b95be;
        }
        goto LAB_081b959d;
      }
      pBVar5 = BN_BLINDING_create_param
                         (b,(BIGNUM *)0x0,(BIGNUM *)0x0,ctx,(bn_mod_exp *)0x0,(BN_MONT_CTX *)0x0);
LAB_081b960d:
      uVar4 = (uint)(pBVar5 != (BN_BLINDING *)0x0);
    }
    iVar3 = *(int *)(b + 0x1c);
  }
  if (iVar3 != 0x20) {
    return uVar4;
  }
LAB_081b95be:
  *(undefined4 *)(b + 0x1c) = 0;
  return uVar4;
}

