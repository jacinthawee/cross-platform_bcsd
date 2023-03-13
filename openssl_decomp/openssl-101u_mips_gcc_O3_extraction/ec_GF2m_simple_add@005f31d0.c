
bool ec_GF2m_simple_add(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  bool bVar6;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a864c)(param_1,param_3);
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_EC_POINT_copy_006a7fc4)(param_2,param_4);
    return iVar1 != 0;
  }
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a864c)(param_1,param_4);
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_EC_POINT_copy_006a7fc4)(param_2,param_3);
    return iVar1 != 0;
  }
  if (param_5 == 0) {
    param_5 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if (param_5 == 0) {
      return false;
    }
    (*(code *)PTR_BN_CTX_start_006a8528)(param_5);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    local_3c = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    iVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    local_38 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    local_30 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    local_2c = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    local_34 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    piVar4 = (int *)(*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    iVar1 = param_5;
    if (piVar4 == (int *)0x0) {
      bVar6 = false;
      (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
      goto LAB_005f3594;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a8528)(param_5);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    local_3c = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    iVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    local_38 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    local_30 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    local_2c = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    local_34 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    piVar4 = (int *)(*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    if (piVar4 == (int *)0x0) {
      (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
      return false;
    }
    iVar1 = 0;
  }
  if (*(int *)(param_3 + 0x40) == 0) {
    iVar5 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a8694)
                      (param_1,param_3,uVar2,local_3c,param_5);
    if (iVar5 == 0) goto LAB_005f357c;
LAB_005f3380:
    if (*(int *)(param_4 + 0x40) != 0) {
      iVar5 = (*(code *)PTR_BN_copy_006a8450)(iVar3,param_4 + 4);
      if ((iVar5 != 0) &&
         (iVar5 = (*(code *)PTR_BN_copy_006a8450)(local_38,param_4 + 0x18), iVar5 != 0))
      goto LAB_005f33c0;
      goto LAB_005f357c;
    }
    iVar5 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a8694)
                      (param_1,param_4,iVar3,local_38,param_5);
    if (iVar5 == 0) goto LAB_005f357c;
LAB_005f33c0:
    iVar5 = (*(code *)PTR_BN_ucmp_006a7fb4)(uVar2,iVar3);
    if (iVar5 != 0) {
      iVar5 = (*(code *)PTR_BN_GF2m_add_006a96a8)(piVar4,uVar2,iVar3);
      if (((((iVar5 != 0) &&
            (iVar5 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_34,local_3c,local_38), iVar5 != 0))
           && (iVar5 = (**(code **)(*param_1 + 0x8c))(param_1,local_34,local_34,piVar4,param_5),
              iVar5 != 0)) &&
          ((iVar5 = (**(code **)(*param_1 + 0x88))(param_1,local_30,local_34,param_5), iVar5 != 0 &&
           (iVar5 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_30,local_30,param_1 + 0x1d),
           iVar5 != 0)))) &&
         (iVar5 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_30,local_30,local_34), iVar5 != 0)) {
LAB_005f3498:
        iVar5 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_30,local_30,piVar4);
        if (((iVar5 != 0) &&
            (iVar3 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_2c,iVar3,local_30), iVar3 != 0)) &&
           ((iVar3 = (**(code **)(*param_1 + 0x84))(param_1,local_2c,local_2c,local_34,param_5),
            iVar3 != 0 &&
            ((iVar3 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_2c,local_2c,local_30), iVar3 != 0 &&
             (iVar3 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_2c,local_2c,local_38), iVar3 != 0)))
            ))) {
          iVar3 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GF2m_006a8690)
                            (param_1,param_2,local_30,local_2c,param_5);
          bVar6 = iVar3 != 0;
          goto LAB_005f3580;
        }
      }
      goto LAB_005f357c;
    }
    iVar5 = (*(code *)PTR_BN_ucmp_006a7fb4)(local_3c,local_38);
    if ((iVar5 == 0) && (*(int *)(iVar3 + 4) != 0)) {
      iVar5 = (**(code **)(*param_1 + 0x8c))(param_1,local_34,local_38,iVar3,param_5);
      if ((iVar5 != 0) &&
         (((iVar5 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_34,local_34,iVar3), iVar5 != 0 &&
           (iVar5 = (**(code **)(*param_1 + 0x88))(param_1,local_30,local_34,param_5), iVar5 != 0))
          && (iVar5 = (*(code *)PTR_BN_GF2m_add_006a96a8)(local_30,local_30,local_34), iVar5 != 0)))
         ) {
        piVar4 = param_1 + 0x1d;
        goto LAB_005f3498;
      }
      goto LAB_005f357c;
    }
    iVar3 = (*(code *)PTR_EC_POINT_set_to_infinity_006a860c)(param_1,param_2);
    bVar6 = iVar3 != 0;
  }
  else {
    iVar5 = (*(code *)PTR_BN_copy_006a8450)(uVar2,param_3 + 4);
    if ((iVar5 != 0) &&
       (iVar5 = (*(code *)PTR_BN_copy_006a8450)(local_3c,param_3 + 0x18), iVar5 != 0))
    goto LAB_005f3380;
LAB_005f357c:
    bVar6 = false;
  }
LAB_005f3580:
  (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
  param_5 = iVar1;
  if (iVar1 == 0) {
    return bVar6;
  }
LAB_005f3594:
  (*(code *)PTR_BN_CTX_free_006a7954)(param_5);
  return bVar6;
}

