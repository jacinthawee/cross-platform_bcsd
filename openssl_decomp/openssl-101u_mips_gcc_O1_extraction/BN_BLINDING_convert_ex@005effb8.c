
int BN_BLINDING_convert_ex(BIGNUM *n,BIGNUM *r,BN_BLINDING *b,BN_CTX *param_4)

{
  int iVar1;
  BN_BLINDING *pBVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar3 = *(int *)b;
  if ((iVar3 == 0) || (*(int *)(b + 4) == 0)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,100,0x6b,"bn_blind.c",0xea);
    return 0;
  }
  if (*(int *)(b + 0x1c) == -1) {
LAB_005f00b4:
    *(undefined4 *)(b + 0x1c) = 0;
LAB_005f00b8:
    if (r == (BIGNUM *)0x0) {
LAB_005f00c0:
      uVar5 = 1;
    }
    else {
LAB_005f0034:
      iVar3 = (*(code *)PTR_BN_copy_006a8450)(r,*(undefined4 *)(b + 4));
      uVar5 = (uint)(iVar3 != 0);
    }
    iVar3 = (*(code *)PTR_BN_mod_mul_006a8574)
                      (n,n,*(undefined4 *)b,*(undefined4 *)(b + 0xc),param_4);
    if (iVar3 != 0) {
      return uVar5;
    }
  }
  else {
    iVar1 = *(int *)(b + 0x1c) + 1;
    *(int *)(b + 0x1c) = iVar1;
    if (iVar1 == 0x20) {
      if (*(int *)(b + 8) == 0) {
        uVar5 = *(uint *)(b + 0x20);
LAB_005f00a8:
        if ((uVar5 & 1) != 0) goto LAB_005f00b4;
        goto LAB_005f00e4;
      }
      uVar5 = *(uint *)(b + 0x20);
      if ((uVar5 & 2) != 0) goto LAB_005f00a8;
      pBVar2 = BN_BLINDING_create_param
                         (b,(BIGNUM *)0x0,(BIGNUM *)0x0,param_4,(bn_mod_exp *)0x0,(BN_MONT_CTX *)0x0
                         );
      if (pBVar2 != (BN_BLINDING *)0x0) goto LAB_005f0198;
      iVar3 = *(int *)(b + 0x1c);
    }
    else {
      if ((*(uint *)(b + 0x20) & 1) != 0) {
LAB_005f002c:
        if (r == (BIGNUM *)0x0) goto LAB_005f00c0;
        goto LAB_005f0034;
      }
LAB_005f00e4:
      iVar3 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar3,iVar3,iVar3,*(undefined4 *)(b + 0xc),param_4)
      ;
      if (iVar3 != 0) {
        uVar4 = *(undefined4 *)(b + 4);
        iVar3 = (*(code *)PTR_BN_mod_mul_006a8574)
                          (uVar4,uVar4,uVar4,*(undefined4 *)(b + 0xc),param_4);
        if (iVar3 != 0) {
LAB_005f0198:
          if (*(int *)(b + 0x1c) == 0x20) {
            *(undefined4 *)(b + 0x1c) = 0;
            goto LAB_005f00b8;
          }
          goto LAB_005f002c;
        }
      }
      iVar3 = *(int *)(b + 0x1c);
    }
    if (iVar3 == 0x20) {
      *(undefined4 *)(b + 0x1c) = 0;
      return 0;
    }
  }
  return 0;
}

