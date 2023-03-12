
bool ec_GFp_simple_get_Jprojective_coordinates_GFp
               (int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if (*(int *)(*param_1 + 0x94) == 0) {
    if (((param_3 == 0) ||
        (iVar2 = (*(code *)PTR_BN_copy_006a8450)(param_3,param_2 + 4), iVar2 != 0)) &&
       ((param_4 == 0 ||
        (iVar2 = (*(code *)PTR_BN_copy_006a8450)(param_4,param_2 + 0x18), iVar2 != 0)))) {
      if (param_5 != 0) {
        iVar2 = (*(code *)PTR_BN_copy_006a8450)(param_5,param_2 + 0x2c);
        return iVar2 != 0;
      }
      return true;
    }
  }
  else {
    iVar2 = 0;
    if ((param_6 != 0) ||
       (param_6 = (*(code *)PTR_BN_CTX_new_006a794c)(), iVar2 = param_6, param_6 != 0)) {
      if (((param_3 == 0) ||
          (iVar1 = (**(code **)(*param_1 + 0x94))(param_1,param_3,param_2 + 4,param_6), iVar1 != 0))
         && ((param_4 == 0 ||
             (iVar1 = (**(code **)(*param_1 + 0x94))(param_1,param_4,param_2 + 0x18,param_6),
             iVar1 != 0)))) {
        if (param_5 == 0) {
          bVar3 = true;
        }
        else {
          iVar1 = (**(code **)(*param_1 + 0x94))(param_1,param_5,param_2 + 0x2c,param_6);
          bVar3 = iVar1 != 0;
        }
      }
      else {
        bVar3 = false;
      }
      if (iVar2 == 0) {
        return bVar3;
      }
      (*(code *)PTR_BN_CTX_free_006a7954)(iVar2);
      return bVar3;
    }
  }
  return false;
}

