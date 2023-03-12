
undefined4 gost2001_keygen(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = (*(code *)PTR_BN_new_006a82b4)();
  iVar2 = (*(code *)PTR_BN_new_006a82b4)();
  uVar3 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(param_1);
  (*(code *)PTR_EC_GROUP_get_order_006a82ec)(uVar3,uVar1,0);
  do {
    iVar4 = (*(code *)PTR_BN_rand_range_006a97b0)(iVar2,uVar1);
    if (iVar4 == 0) {
      ERR_GOST_error(0x6b,0x7d,"gost2001.c",0x14b);
      (*(code *)PTR_BN_free_006a811c)(iVar2);
      (*(code *)PTR_BN_free_006a811c)(uVar1);
      return 0;
    }
  } while (*(int *)(iVar2 + 4) == 0);
  (*(code *)PTR_EC_KEY_set_private_key_006a913c)(param_1,iVar2);
  (*(code *)PTR_BN_free_006a811c)(iVar2);
  (*(code *)PTR_BN_free_006a811c)(uVar1);
  uVar1 = gost2001_compute_public(param_1);
  return uVar1;
}

