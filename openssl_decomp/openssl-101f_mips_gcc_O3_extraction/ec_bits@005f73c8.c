
undefined4 ec_bits(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = (*(code *)PTR_BN_new_006a82b4)();
  if (iVar1 != 0) {
    uVar2 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(*(undefined4 *)(param_1 + 0x14));
    iVar3 = (*(code *)PTR_EC_GROUP_get_order_006a82ec)(uVar2,iVar1,0);
    if (iVar3 != 0) {
      uVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar1);
      (*(code *)PTR_BN_free_006a811c)(iVar1);
      return uVar2;
    }
  }
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
  return 0;
}

