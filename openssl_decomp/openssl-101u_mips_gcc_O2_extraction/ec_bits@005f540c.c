
undefined4 ec_bits(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = (*(code *)PTR_BN_new_006a71b4)();
  if (iVar1 != 0) {
    uVar2 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(*(undefined4 *)(param_1 + 0x14));
    iVar3 = (*(code *)PTR_EC_GROUP_get_order_006a71ec)(uVar2,iVar1,0);
    if (iVar3 != 0) {
      uVar2 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar1);
      (*(code *)PTR_BN_free_006a701c)(iVar1);
      return uVar2;
    }
  }
  (*(code *)PTR_ERR_clear_error_006a6ee0)();
  return 0;
}

