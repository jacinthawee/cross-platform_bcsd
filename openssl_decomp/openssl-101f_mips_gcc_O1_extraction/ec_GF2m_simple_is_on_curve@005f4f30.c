
uint ec_GF2m_simple_is_on_curve(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  code *pcVar7;
  int iVar8;
  
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)();
  if (iVar1 != 0) {
    return 1;
  }
  pcVar6 = *(code **)(*param_1 + 0x84);
  pcVar7 = *(code **)(*param_1 + 0x88);
  if (*(int *)(param_2 + 0x40) == 0) {
    return 0xffffffff;
  }
  if (param_3 == 0) {
    param_3 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (param_3 == 0) {
      return 0xffffffff;
    }
    (*(code *)PTR_BN_CTX_start_006a9644)(param_3);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_3);
    iVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_3);
    iVar1 = param_3;
    if (iVar3 == 0) {
      uVar5 = 0xffffffff;
      (*(code *)PTR_BN_CTX_end_006a9654)(param_3);
      goto LAB_005f5014;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a9644)(param_3);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_3);
    iVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_3);
    if (iVar3 == 0) {
      (*(code *)PTR_BN_CTX_end_006a9654)(param_3);
      return 0xffffffff;
    }
    iVar1 = 0;
  }
  iVar8 = param_2 + 4;
  iVar4 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(iVar3,iVar8,param_1 + 0x1d);
  if ((iVar4 == 0) || (iVar4 = (*pcVar6)(param_1,iVar3,iVar3,iVar8,param_3), iVar4 == 0)) {
LAB_005f4ffc:
    uVar5 = 0xffffffff;
  }
  else {
    iVar4 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(iVar3,iVar3,param_2 + 0x18);
    if (((iVar4 == 0) ||
        (((iVar4 = (*pcVar6)(param_1,iVar3,iVar3,iVar8,param_3), iVar4 == 0 ||
          (iVar4 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(iVar3,iVar3,param_1 + 0x22), iVar4 == 0)) ||
         (iVar4 = (*pcVar7)(param_1,uVar2,param_2 + 0x18,param_3), iVar4 == 0)))) ||
       (iVar4 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(iVar3,iVar3,uVar2), iVar4 == 0))
    goto LAB_005f4ffc;
    uVar5 = (uint)(*(int *)(iVar3 + 4) == 0);
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(param_3);
  param_3 = iVar1;
  if (iVar1 == 0) {
    return uVar5;
  }
LAB_005f5014:
  (*(code *)PTR_BN_CTX_free_006a8a40)(param_3);
  return uVar5;
}

