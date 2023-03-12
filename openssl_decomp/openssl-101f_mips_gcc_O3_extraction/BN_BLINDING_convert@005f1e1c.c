
int BN_BLINDING_convert(BIGNUM *n,BN_BLINDING *b,BN_CTX *ctx)

{
  int iVar1;
  BN_BLINDING *pBVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = *(int *)b;
  if ((iVar4 == 0) || (*(int *)(b + 4) == 0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(3,100,0x6b,"bn_blind.c",0xe8);
    return 0;
  }
  if (*(int *)(b + 0x1c) == -1) {
LAB_005f1ef4:
    *(undefined4 *)(b + 0x1c) = 0;
LAB_005f1ef8:
    uVar5 = *(undefined4 *)(b + 0xc);
LAB_005f1efc:
    iVar4 = (*(code *)PTR_BN_mod_mul_006a9698)(n,n,iVar4,uVar5,ctx);
    uVar3 = (uint)(iVar4 != 0);
  }
  else {
    iVar1 = *(int *)(b + 0x1c) + 1;
    *(int *)(b + 0x1c) = iVar1;
    if (iVar1 == 0x20) {
      if (*(int *)(b + 8) == 0) {
        uVar3 = *(uint *)(b + 0x20);
LAB_005f1ee8:
        if ((uVar3 & 1) == 0) goto LAB_005f1e84;
        goto LAB_005f1ef4;
      }
      uVar3 = *(uint *)(b + 0x20);
      if ((uVar3 & 2) != 0) goto LAB_005f1ee8;
      pBVar2 = BN_BLINDING_create_param
                         (b,(BIGNUM *)0x0,(BIGNUM *)0x0,ctx,(bn_mod_exp *)0x0,(BN_MONT_CTX *)0x0);
      if (pBVar2 != (BN_BLINDING *)0x0) goto LAB_005f1f94;
      iVar4 = *(int *)(b + 0x1c);
    }
    else {
      if ((*(uint *)(b + 0x20) & 1) != 0) goto LAB_005f1ef8;
LAB_005f1e84:
      iVar4 = (*(code *)PTR_BN_mod_mul_006a9698)(iVar4,iVar4,iVar4,*(undefined4 *)(b + 0xc),ctx);
      if (iVar4 != 0) {
        uVar5 = *(undefined4 *)(b + 4);
        iVar4 = (*(code *)PTR_BN_mod_mul_006a9698)(uVar5,uVar5,uVar5,*(undefined4 *)(b + 0xc),ctx);
        if (iVar4 != 0) {
LAB_005f1f94:
          iVar4 = *(int *)b;
          if (*(int *)(b + 0x1c) == 0x20) goto LAB_005f1ef4;
          uVar5 = *(undefined4 *)(b + 0xc);
          goto LAB_005f1efc;
        }
      }
      iVar4 = *(int *)(b + 0x1c);
    }
    if (iVar4 != 0x20) {
      return 0;
    }
    uVar3 = 0;
    *(undefined4 *)(b + 0x1c) = 0;
  }
  return uVar3;
}

