
uint ec_GF2m_simple_cmp(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)();
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)(param_1,param_3);
    return (uint)(iVar1 == 0);
  }
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)();
  if (iVar1 != 0) {
    return 1;
  }
  if ((*(int *)(param_2 + 0x40) != 0) && (*(int *)(param_3 + 0x40) != 0)) {
    iVar1 = (*(code *)PTR_BN_cmp_006a8a4c)(param_2 + 4,param_3 + 4);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = (*(code *)PTR_BN_cmp_006a8a4c)(param_2 + 0x18,param_3 + 0x18);
    return (uint)(iVar1 != 0);
  }
  if (param_4 == 0) {
    param_4 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (param_4 == 0) {
      return 0xffffffff;
    }
    (*(code *)PTR_BN_CTX_start_006a9644)(param_4);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    uVar4 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    iVar5 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    iVar1 = param_4;
    if (iVar5 == 0) {
      uVar7 = 0xffffffff;
      (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
      goto LAB_005f4b1c;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a9644)(param_4);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    uVar4 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    iVar5 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    if (iVar5 == 0) {
      (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
      return 0xffffffff;
    }
    iVar1 = 0;
  }
  iVar6 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a97b8)
                    (param_1,param_2,uVar2,uVar3,param_4);
  if ((iVar6 == 0) ||
     (iVar6 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a97b8)
                        (param_1,param_3,uVar4,iVar5,param_4), iVar6 == 0)) {
    uVar7 = 0xffffffff;
  }
  else {
    iVar6 = (*(code *)PTR_BN_cmp_006a8a4c)(uVar2,uVar4);
    if (iVar6 == 0) {
      iVar5 = (*(code *)PTR_BN_cmp_006a8a4c)(uVar3,iVar5);
      uVar7 = (uint)(iVar5 != 0);
    }
    else {
      uVar7 = 1;
    }
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
  param_4 = iVar1;
  if (iVar1 == 0) {
    return uVar7;
  }
LAB_005f4b1c:
  (*(code *)PTR_BN_CTX_free_006a8a40)(param_4);
  return uVar7;
}

