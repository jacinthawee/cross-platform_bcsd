
int BN_BLINDING_update(BN_BLINDING *b,BN_CTX *ctx)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  BN_BLINDING *pBVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar5 = *(int *)b;
  if ((iVar5 == 0) || (*(int *)(b + 4) == 0)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x67,0x6b,"bn_blind.c",0xc4);
    uVar2 = 0;
    iVar5 = *(int *)(b + 0x1c);
  }
  else {
    if (*(int *)(b + 0x1c) == -1) {
      uVar2 = *(uint *)(b + 0x20);
      *(undefined4 *)(b + 0x1c) = 1;
joined_r0x005efd24:
      if ((uVar2 & 1) != 0) {
        return 1;
      }
    }
    else {
      iVar1 = *(int *)(b + 0x1c) + 1;
      *(int *)(b + 0x1c) = iVar1;
      if (iVar1 != 0x20) {
        uVar2 = *(uint *)(b + 0x20);
        goto joined_r0x005efd24;
      }
      if (*(int *)(b + 8) == 0) {
        uVar3 = *(uint *)(b + 0x20);
      }
      else {
        uVar3 = *(uint *)(b + 0x20);
        if ((uVar3 & 2) == 0) {
          pBVar4 = BN_BLINDING_create_param
                             (b,(BIGNUM *)0x0,(BIGNUM *)0x0,ctx,(bn_mod_exp *)0x0,(BN_MONT_CTX *)0x0
                             );
          uVar2 = (uint)(pBVar4 != (BN_BLINDING *)0x0);
          iVar5 = *(int *)(b + 0x1c);
          goto LAB_005efd80;
        }
      }
      uVar2 = 1;
      if ((uVar3 & 1) != 0) goto LAB_005efd00;
    }
    uVar2 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar5,iVar5,iVar5,*(undefined4 *)(b + 0xc),ctx);
    if (uVar2 == 0) {
      iVar5 = *(int *)(b + 0x1c);
    }
    else {
      uVar6 = *(undefined4 *)(b + 4);
      iVar1 = (*(code *)PTR_BN_mod_mul_006a8574)(uVar6,uVar6,uVar6,*(undefined4 *)(b + 0xc),ctx);
      iVar5 = *(int *)(b + 0x1c);
      uVar2 = (uint)(iVar1 != 0);
    }
  }
LAB_005efd80:
  if (iVar5 != 0x20) {
    return uVar2;
  }
LAB_005efd00:
  *(undefined4 *)(b + 0x1c) = 0;
  return uVar2;
}

