
undefined4 gost2001_compute_public(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  iVar1 = (*(code *)PTR_EC_KEY_get0_group_006a8780)();
  if (iVar1 == 0) {
    ERR_GOST_error(0x68,0x72,"gost2001.c",0x11e);
    return 0;
  }
  uVar2 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  (*(code *)PTR_BN_CTX_start_006a9644)(uVar2);
  iVar3 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(param_1);
  if (iVar3 == 0) {
    uVar6 = 0;
    ERR_GOST_error(0x68,0x10,"gost2001.c",0x125);
    uVar4 = 0;
  }
  else {
    uVar4 = (*(code *)PTR_EC_POINT_new_006a9140)(iVar1);
    iVar1 = (*(code *)PTR_EC_POINT_mul_006a976c)(iVar1,uVar4,iVar3,0,0,uVar2);
    if (iVar1 == 0) {
      uVar5 = 300;
    }
    else {
      iVar1 = (*(code *)PTR_EC_KEY_set_public_key_006a91b0)(param_1,uVar4);
      if (iVar1 != 0) {
        uVar6 = 0x100;
        goto LAB_006146a4;
      }
      uVar5 = 0x131;
    }
    uVar6 = 0;
    ERR_GOST_error(0x68,0x10,"gost2001.c",uVar5);
  }
LAB_006146a4:
  (*(code *)PTR_BN_CTX_end_006a9654)(uVar2);
  (*(code *)PTR_EC_POINT_free_006a9134)(uVar4);
  (*(code *)PTR_BN_CTX_free_006a8a40)(uVar2);
  return uVar6;
}

