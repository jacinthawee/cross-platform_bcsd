
bool ec_GFp_simple_group_get_curve(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  
  if ((param_2 == 0) ||
     (iVar1 = (*(code *)PTR_BN_copy_006a8450)(param_2,param_1 + 0x12), iVar1 != 0)) {
    if (param_3 == 0) {
      if (param_4 == 0) {
        return true;
      }
      iVar1 = *param_1;
      if (*(int *)(iVar1 + 0x94) == 0) {
LAB_0062d3a0:
        iVar1 = (*(code *)PTR_BN_copy_006a8450)(param_4,param_1 + 0x22);
        return iVar1 != 0;
      }
      if (param_5 == 0) goto LAB_0062d340;
      iVar3 = 0;
LAB_0062d2e0:
      iVar1 = (**(code **)(iVar1 + 0x94))(param_1,param_4,param_1 + 0x22,param_5);
      bVar2 = iVar1 != 0;
      param_5 = iVar3;
LAB_0062d300:
      if (param_5 == 0) {
        return bVar2;
      }
    }
    else {
      if (*(code **)(*param_1 + 0x94) == (code *)0x0) {
        iVar1 = (*(code *)PTR_BN_copy_006a8450)(param_3,param_1 + 0x1d);
        if (iVar1 != 0) {
          if (param_4 == 0) {
            return true;
          }
          goto LAB_0062d3a0;
        }
        goto LAB_0062d354;
      }
      if (param_5 != 0) {
        iVar1 = (**(code **)(*param_1 + 0x94))(param_1,param_3,param_1 + 0x1d,param_5);
        if (iVar1 == 0) {
          return false;
        }
        iVar3 = 0;
        if (param_4 != 0) {
LAB_0062d2dc:
          iVar1 = *param_1;
          goto LAB_0062d2e0;
        }
        bVar2 = true;
        param_5 = 0;
        goto LAB_0062d300;
      }
LAB_0062d340:
      param_5 = (*(code *)PTR_BN_CTX_new_006a794c)();
      if (param_5 == 0) goto LAB_0062d354;
      iVar3 = param_5;
      if (param_3 == 0) {
        if (param_4 != 0) {
          iVar1 = *param_1;
          goto LAB_0062d2e0;
        }
        bVar2 = true;
      }
      else {
        iVar1 = (**(code **)(*param_1 + 0x94))(param_1,param_3,param_1 + 0x1d,param_5);
        if (iVar1 != 0) {
          if (param_4 != 0) goto LAB_0062d2dc;
          bVar2 = true;
          goto LAB_0062d300;
        }
        bVar2 = false;
      }
    }
    (*(code *)PTR_BN_CTX_free_006a7954)(param_5);
  }
  else {
LAB_0062d354:
    bVar2 = false;
  }
  return bVar2;
}

