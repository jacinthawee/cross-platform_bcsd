
EC_GROUP * EC_GROUP_new_curve_GFp(BIGNUM *p,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  undefined4 uVar1;
  EC_GROUP *pEVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = (*(code *)PTR_EC_GFp_nist_method_006a9680)();
  pEVar2 = (EC_GROUP *)(*(code *)PTR_EC_GROUP_new_006a8628)(uVar1);
  if (pEVar2 != (EC_GROUP *)0x0) {
    iVar3 = (*(code *)PTR_EC_GROUP_set_curve_GFp_006a9684)(pEVar2,p,a,b,ctx);
    if (iVar3 != 0) {
      return pEVar2;
    }
    uVar4 = (*(code *)PTR_ERR_peek_last_error_006a7408)();
    if ((uVar4 >> 0x18 == 0x10) && ((uVar4 & 0xfff) - 0x87 < 2)) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
      (*(code *)PTR_EC_GROUP_clear_free_006a8650)(pEVar2);
      uVar1 = (*(code *)PTR_EC_GFp_mont_method_006a9688)();
      pEVar2 = (EC_GROUP *)(*(code *)PTR_EC_GROUP_new_006a8628)(uVar1);
      if (pEVar2 != (EC_GROUP *)0x0) {
        iVar3 = (*(code *)PTR_EC_GROUP_set_curve_GFp_006a9684)(pEVar2,p,a,b,ctx);
        if (iVar3 != 0) {
          return pEVar2;
        }
        (*(code *)PTR_EC_GROUP_clear_free_006a8650)();
        return (EC_GROUP *)0x0;
      }
    }
    else {
      (*(code *)PTR_EC_GROUP_clear_free_006a8650)(pEVar2);
    }
  }
  return (EC_GROUP *)0x0;
}

