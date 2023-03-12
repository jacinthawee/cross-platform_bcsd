
bool ec_cmp_parameters(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(*(undefined4 *)(param_1 + 0x14));
  uVar2 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(*(undefined4 *)(param_2 + 0x14));
  iVar3 = (*(code *)PTR_EC_GROUP_cmp_006a96c4)(uVar1,uVar2,0);
  return iVar3 == 0;
}

