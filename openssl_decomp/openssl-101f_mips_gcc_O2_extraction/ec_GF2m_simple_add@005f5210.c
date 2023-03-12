
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
  
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)(param_1,param_3);
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_EC_POINT_copy_006a9144)(param_2,param_4);
    return iVar1 != 0;
  }
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)(param_1,param_4);
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_EC_POINT_copy_006a9144)(param_2,param_3);
    return iVar1 != 0;
  }
  if (param_5 == 0) {
    param_5 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (param_5 == 0) {
      return false;
    }
    (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_3c = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    iVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_38 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_30 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_2c = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_34 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    piVar4 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    iVar1 = param_5;
    if (piVar4 == (int *)0x0) {
      bVar6 = false;
      (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
      goto LAB_005f55d4;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_3c = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    iVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_38 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_30 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_2c = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_34 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    piVar4 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    if (piVar4 == (int *)0x0) {
      (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
      return false;
    }
    iVar1 = 0;
  }
  if (*(int *)(param_3 + 0x40) == 0) {
    iVar5 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a97b8)
                      (param_1,param_3,uVar2,local_3c,param_5);
    if (iVar5 == 0) goto LAB_005f55bc;
LAB_005f53c0:
    if (*(int *)(param_4 + 0x40) != 0) {
      iVar5 = (*(code *)PTR_BN_copy_006a9570)(iVar3,param_4 + 4);
      if ((iVar5 != 0) &&
         (iVar5 = (*(code *)PTR_BN_copy_006a9570)(local_38,param_4 + 0x18), iVar5 != 0))
      goto LAB_005f5400;
      goto LAB_005f55bc;
    }
    iVar5 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a97b8)
                      (param_1,param_4,iVar3,local_38,param_5);
    if (iVar5 == 0) goto LAB_005f55bc;
LAB_005f5400:
    iVar5 = (*(code *)PTR_BN_ucmp_006a9678)(uVar2,iVar3);
    if (iVar5 != 0) {
      iVar5 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(piVar4,uVar2,iVar3);
      if (((((iVar5 != 0) &&
            (iVar5 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_34,local_3c,local_38), iVar5 != 0))
           && (iVar5 = (**(code **)(*param_1 + 0x8c))(param_1,local_34,local_34,piVar4,param_5),
              iVar5 != 0)) &&
          ((iVar5 = (**(code **)(*param_1 + 0x88))(param_1,local_30,local_34,param_5), iVar5 != 0 &&
           (iVar5 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_30,local_30,param_1 + 0x1d),
           iVar5 != 0)))) &&
         (iVar5 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_30,local_30,local_34), iVar5 != 0)) {
LAB_005f54d8:
        iVar5 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_30,local_30,piVar4);
        if (((iVar5 != 0) &&
            (iVar3 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_2c,iVar3,local_30), iVar3 != 0)) &&
           ((iVar3 = (**(code **)(*param_1 + 0x84))(param_1,local_2c,local_2c,local_34,param_5),
            iVar3 != 0 &&
            ((iVar3 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_2c,local_2c,local_30), iVar3 != 0 &&
             (iVar3 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_2c,local_2c,local_38), iVar3 != 0)))
            ))) {
          iVar3 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GF2m_006a97b4)
                            (param_1,param_2,local_30,local_2c,param_5);
          bVar6 = iVar3 != 0;
          goto LAB_005f55c0;
        }
      }
      goto LAB_005f55bc;
    }
    iVar5 = (*(code *)PTR_BN_ucmp_006a9678)(local_3c,local_38);
    if ((iVar5 == 0) && (*(int *)(iVar3 + 4) != 0)) {
      iVar5 = (**(code **)(*param_1 + 0x8c))(param_1,local_34,local_38,iVar3,param_5);
      if ((iVar5 != 0) &&
         (((iVar5 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_34,local_34,iVar3), iVar5 != 0 &&
           (iVar5 = (**(code **)(*param_1 + 0x88))(param_1,local_30,local_34,param_5), iVar5 != 0))
          && (iVar5 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_30,local_30,local_34), iVar5 != 0)))
         ) {
        piVar4 = param_1 + 0x1d;
        goto LAB_005f54d8;
      }
      goto LAB_005f55bc;
    }
    iVar3 = (*(code *)PTR_EC_POINT_set_to_infinity_006a972c)(param_1,param_2);
    bVar6 = iVar3 != 0;
  }
  else {
    iVar5 = (*(code *)PTR_BN_copy_006a9570)(uVar2,param_3 + 4);
    if ((iVar5 != 0) &&
       (iVar5 = (*(code *)PTR_BN_copy_006a9570)(local_3c,param_3 + 0x18), iVar5 != 0))
    goto LAB_005f53c0;
LAB_005f55bc:
    bVar6 = false;
  }
LAB_005f55c0:
  (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
  param_5 = iVar1;
  if (iVar1 == 0) {
    return bVar6;
  }
LAB_005f55d4:
  (*(code *)PTR_BN_CTX_free_006a8a40)(param_5);
  return bVar6;
}

