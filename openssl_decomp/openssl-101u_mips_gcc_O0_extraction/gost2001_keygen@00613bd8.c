
undefined4 gost2001_keygen(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar1 = (*(code *)PTR_BN_new_006a71b4)();
  iVar2 = (*(code *)PTR_BN_new_006a71b4)();
  iVar3 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(param_1);
  if ((iVar3 == 0) ||
     (iVar3 = (*(code *)PTR_EC_GROUP_get_order_006a71ec)(iVar3,uVar1,0), iVar3 == 0)) {
    uVar5 = 0x1b8;
  }
  else {
    do {
      iVar3 = (*(code *)PTR_BN_rand_range_006a868c)(iVar2,uVar1);
      if (iVar3 == 0) {
        uVar5 = 0x1c1;
        uVar4 = 0x7d;
        goto LAB_00613c8c;
      }
    } while (*(int *)(iVar2 + 4) == 0);
    iVar3 = (*(code *)PTR_EC_KEY_set_private_key_006a7fbc)(param_1,iVar2);
    if (iVar3 != 0) {
      (*(code *)PTR_BN_free_006a701c)(iVar2);
      (*(code *)PTR_BN_free_006a701c)(uVar1);
      uVar1 = gost2001_compute_public(param_1);
      return uVar1;
    }
    uVar5 = 0x1ca;
  }
  uVar4 = 0x44;
LAB_00613c8c:
  ERR_GOST_error(0x6b,uVar4,"gost2001.c",uVar5);
  (*(code *)PTR_BN_free_006a701c)(iVar2);
  (*(code *)PTR_BN_free_006a701c)(uVar1);
  return 0;
}

