
bool ec_GF2m_simple_dbl(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  bool bVar7;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a864c)(param_1,param_3);
  if ((iVar1 != 0) ||
     (iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a864c)(param_1,param_3), iVar1 != 0)) {
    iVar1 = (*(code *)PTR_EC_POINT_copy_006a7fc4)(param_2,param_3);
    return iVar1 != 0;
  }
  if (param_4 == 0) {
    param_4 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if (param_4 == 0) {
      return false;
    }
    (*(code *)PTR_BN_CTX_start_006a8528)(param_4);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    iVar4 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    local_38 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    local_30 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    local_2c = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    local_34 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    piVar5 = (int *)(*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    iVar1 = param_4;
    if (piVar5 == (int *)0x0) {
      bVar7 = false;
      (*(code *)PTR_BN_CTX_end_006a8530)(param_4);
      goto LAB_005f3c84;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a8528)(param_4);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    iVar4 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    local_38 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    local_30 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    local_2c = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    local_34 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    piVar5 = (int *)(*(code *)PTR_BN_CTX_get_006a852c)(param_4);
    if (piVar5 == (int *)0x0) {
      (*(code *)PTR_BN_CTX_end_006a8530)(param_4);
      return false;
    }
    iVar1 = 0;
  }
  if (*(int *)(param_3 + 0x40) == 0) {
    iVar6 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a8694)
                      (param_1,param_3,uVar2,uVar3,param_4);
    if (iVar6 == 0) goto LAB_005f3c6c;
LAB_005f3a28:
    if (*(int *)(param_3 + 0x40) != 0) {
      iVar6 = (*(code *)PTR_BN_copy_006a8450)(iVar4,param_3 + 4);
      if ((iVar6 != 0) &&
         (iVar6 = (*(code *)PTR_BN_copy_006a8450)(local_38,param_3 + 0x18), iVar6 != 0))
      goto LAB_005f3a68;
      goto LAB_005f3c6c;
    }
    iVar6 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a8694)
                      (param_1,param_3,iVar4,local_38,param_4);
    if (iVar6 == 0) goto LAB_005f3c6c;
LAB_005f3a68:
    iVar6 = (*(code *)PTR_BN_ucmp_006a7fb4)(uVar2,iVar4);
    if (iVar6 != 0) {
      iVar6 = (*(code *)PTR_BN_GF2m_add_006a96a8)(piVar5,uVar2,iVar4);
      if (((((iVar6 != 0) &&
            (iVar6 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_34,uVar3,local_38), iVar6 != 0)) &&
           (iVar6 = (**(code **)(*param_1 + 0x8c))(param_1,local_34,local_34,piVar5,param_4),
           iVar6 != 0)) &&
          ((iVar6 = (**(code **)(*param_1 + 0x88))(param_1,local_30,local_34,param_4), iVar6 != 0 &&
           (iVar6 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_30,local_30,param_1 + 0x1d),
           iVar6 != 0)))) &&
         (iVar6 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_30,local_30,local_34), iVar6 != 0)) {
LAB_005f3b40:
        iVar6 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_30,local_30,piVar5);
        if (((iVar6 != 0) &&
            (iVar4 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_2c,iVar4,local_30), iVar4 != 0)) &&
           ((iVar4 = (**(code **)(*param_1 + 0x84))(param_1,local_2c,local_2c,local_34,param_4),
            iVar4 != 0 &&
            ((iVar4 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_2c,local_2c,local_30), iVar4 != 0 &&
             (iVar4 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_2c,local_2c,local_38), iVar4 != 0)))
            ))) {
          iVar4 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GF2m_006a8690)
                            (param_1,param_2,local_30,local_2c,param_4);
          bVar7 = iVar4 != 0;
          goto LAB_005f3c70;
        }
      }
      goto LAB_005f3c6c;
    }
    iVar6 = (*(code *)PTR_BN_ucmp_006a7fb4)(uVar3,local_38);
    if ((iVar6 == 0) && (*(int *)(iVar4 + 4) != 0)) {
      iVar6 = (**(code **)(*param_1 + 0x8c))(param_1,local_34,local_38,iVar4,param_4);
      if ((iVar6 != 0) &&
         (((iVar6 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_34,local_34,iVar4), iVar6 != 0 &&
           (iVar6 = (**(code **)(*param_1 + 0x88))(param_1,local_30,local_34,param_4), iVar6 != 0))
          && (iVar6 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_30,local_30,local_34), iVar6 != 0)))
         ) {
        piVar5 = param_1 + 0x1d;
        goto LAB_005f3b40;
      }
      goto LAB_005f3c6c;
    }
    iVar4 = (*(code *)PTR_EC_POINT_set_to_infinity_006a860c)(param_1,param_2);
    bVar7 = iVar4 != 0;
  }
  else {
    iVar6 = (*(code *)PTR_BN_copy_006a8450)(uVar2,param_3 + 4);
    if ((iVar6 != 0) && (iVar6 = (*(code *)PTR_BN_copy_006a8450)(uVar3,param_3 + 0x18), iVar6 != 0))
    goto LAB_005f3a28;
LAB_005f3c6c:
    bVar7 = false;
  }
LAB_005f3c70:
  (*(code *)PTR_BN_CTX_end_006a8530)(param_4);
  param_4 = iVar1;
  if (iVar1 == 0) {
    return bVar7;
  }
LAB_005f3c84:
  (*(code *)PTR_BN_CTX_free_006a7954)(param_4);
  return bVar7;
}

