
bool ec_missing_parameters(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(*(undefined4 *)(param_1 + 0x14));
  return iVar1 == 0;
}

