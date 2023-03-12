
int EC_GROUP_new_curve_GF2m
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = EC_GF2m_simple_method();
  iVar2 = (*(code *)PTR_EC_GROUP_new_006a8628)(uVar1);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar3 = (*(code *)PTR_EC_GROUP_set_curve_GF2m_006a9690)(iVar2,param_1,param_2,param_3,param_4);
    if (iVar3 == 0) {
      (*(code *)PTR_EC_GROUP_clear_free_006a8650)();
      iVar2 = 0;
    }
  }
  return iVar2;
}

