
bool ec_GF2m_simple_group_get_curve(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_2 != 0) &&
     (iVar1 = (*(code *)PTR_BN_copy_006a9570)(param_2,param_1 + 0x48), iVar1 == 0)) {
    return false;
  }
  if ((param_3 != 0) &&
     (iVar1 = (*(code *)PTR_BN_copy_006a9570)(param_3,param_1 + 0x74), iVar1 == 0)) {
    return false;
  }
  if (param_4 == 0) {
    return true;
  }
  iVar1 = (*(code *)PTR_BN_copy_006a9570)(param_4,param_1 + 0x88);
  return iVar1 != 0;
}

