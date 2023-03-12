
bool param_cmp_gost01(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)();
  uVar1 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar1);
  iVar2 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar1);
  uVar1 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_2);
  uVar1 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar1);
  iVar3 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar1);
  return iVar2 == iVar3;
}

