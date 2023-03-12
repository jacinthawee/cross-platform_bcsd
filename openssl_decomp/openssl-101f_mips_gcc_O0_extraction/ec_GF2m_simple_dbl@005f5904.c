
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
  
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)(param_1,param_3);
  if ((iVar1 != 0) ||
     (iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)(param_1,param_3), iVar1 != 0)) {
    iVar1 = (*(code *)PTR_EC_POINT_copy_006a9144)(param_2,param_3);
    return iVar1 != 0;
  }
  if (param_4 == 0) {
    param_4 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (param_4 == 0) {
      return false;
    }
    (*(code *)PTR_BN_CTX_start_006a9644)(param_4);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    iVar4 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    local_38 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    local_30 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    local_2c = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    local_34 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    piVar5 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    iVar1 = param_4;
    if (piVar5 == (int *)0x0) {
      bVar7 = false;
      (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
      goto LAB_005f5cc4;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a9644)(param_4);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    iVar4 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    local_38 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    local_30 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    local_2c = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    local_34 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    piVar5 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    if (piVar5 == (int *)0x0) {
      (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
      return false;
    }
    iVar1 = 0;
  }
  if (*(int *)(param_3 + 0x40) == 0) {
    iVar6 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a97b8)
                      (param_1,param_3,uVar2,uVar3,param_4);
    if (iVar6 == 0) goto LAB_005f5cac;
LAB_005f5a68:
    if (*(int *)(param_3 + 0x40) != 0) {
      iVar6 = (*(code *)PTR_BN_copy_006a9570)(iVar4,param_3 + 4);
      if ((iVar6 != 0) &&
         (iVar6 = (*(code *)PTR_BN_copy_006a9570)(local_38,param_3 + 0x18), iVar6 != 0))
      goto LAB_005f5aa8;
      goto LAB_005f5cac;
    }
    iVar6 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a97b8)
                      (param_1,param_3,iVar4,local_38,param_4);
    if (iVar6 == 0) goto LAB_005f5cac;
LAB_005f5aa8:
    iVar6 = (*(code *)PTR_BN_ucmp_006a9678)(uVar2,iVar4);
    if (iVar6 != 0) {
      iVar6 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(piVar5,uVar2,iVar4);
      if (((((iVar6 != 0) &&
            (iVar6 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_34,uVar3,local_38), iVar6 != 0)) &&
           (iVar6 = (**(code **)(*param_1 + 0x8c))(param_1,local_34,local_34,piVar5,param_4),
           iVar6 != 0)) &&
          ((iVar6 = (**(code **)(*param_1 + 0x88))(param_1,local_30,local_34,param_4), iVar6 != 0 &&
           (iVar6 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_30,local_30,param_1 + 0x1d),
           iVar6 != 0)))) &&
         (iVar6 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_30,local_30,local_34), iVar6 != 0)) {
LAB_005f5b80:
        iVar6 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_30,local_30,piVar5);
        if (((iVar6 != 0) &&
            (iVar4 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_2c,iVar4,local_30), iVar4 != 0)) &&
           ((iVar4 = (**(code **)(*param_1 + 0x84))(param_1,local_2c,local_2c,local_34,param_4),
            iVar4 != 0 &&
            ((iVar4 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_2c,local_2c,local_30), iVar4 != 0 &&
             (iVar4 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_2c,local_2c,local_38), iVar4 != 0)))
            ))) {
          iVar4 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GF2m_006a97b4)
                            (param_1,param_2,local_30,local_2c,param_4);
          bVar7 = iVar4 != 0;
          goto LAB_005f5cb0;
        }
      }
      goto LAB_005f5cac;
    }
    iVar6 = (*(code *)PTR_BN_ucmp_006a9678)(uVar3,local_38);
    if ((iVar6 == 0) && (*(int *)(iVar4 + 4) != 0)) {
      iVar6 = (**(code **)(*param_1 + 0x8c))(param_1,local_34,local_38,iVar4,param_4);
      if ((iVar6 != 0) &&
         (((iVar6 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_34,local_34,iVar4), iVar6 != 0 &&
           (iVar6 = (**(code **)(*param_1 + 0x88))(param_1,local_30,local_34,param_4), iVar6 != 0))
          && (iVar6 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_30,local_30,local_34), iVar6 != 0)))
         ) {
        piVar5 = param_1 + 0x1d;
        goto LAB_005f5b80;
      }
      goto LAB_005f5cac;
    }
    iVar4 = (*(code *)PTR_EC_POINT_set_to_infinity_006a972c)(param_1,param_2);
    bVar7 = iVar4 != 0;
  }
  else {
    iVar6 = (*(code *)PTR_BN_copy_006a9570)(uVar2,param_3 + 4);
    if ((iVar6 != 0) && (iVar6 = (*(code *)PTR_BN_copy_006a9570)(uVar3,param_3 + 0x18), iVar6 != 0))
    goto LAB_005f5a68;
LAB_005f5cac:
    bVar7 = false;
  }
LAB_005f5cb0:
  (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
  param_4 = iVar1;
  if (iVar1 == 0) {
    return bVar7;
  }
LAB_005f5cc4:
  (*(code *)PTR_BN_CTX_free_006a8a40)(param_4);
  return bVar7;
}

