
undefined4 ec_copy_parameters(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(*(undefined4 *)(param_2 + 0x14));
  iVar2 = (*(code *)PTR_EC_GROUP_dup_006a97c4)(uVar1);
  if (iVar2 != 0) {
    iVar3 = (*(code *)PTR_EC_KEY_set_group_006a82d0)(*(undefined4 *)(param_1 + 0x14),iVar2);
    if (iVar3 != 0) {
      (*(code *)PTR_EC_GROUP_free_006a829c)(iVar2);
      return 1;
    }
  }
  return 0;
}

