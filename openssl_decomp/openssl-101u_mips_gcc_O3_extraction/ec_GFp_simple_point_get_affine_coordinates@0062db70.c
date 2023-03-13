
bool ec_GFp_simple_point_get_affine_coordinates
               (int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int **ppiVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  bool bVar8;
  
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a864c)();
  if (iVar1 != 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xa7,0x6a,"ecp_smpl.c",0x224);
    return false;
  }
  if (param_5 == 0) {
    param_5 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if (param_5 == 0) {
      return false;
    }
    (*(code *)PTR_BN_CTX_start_006a8528)(param_5);
    ppiVar2 = (int **)(*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    uVar4 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    iVar5 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    iVar1 = param_5;
    if (iVar5 == 0) {
      bVar8 = false;
      (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
      goto LAB_0062dd58;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a8528)(param_5);
    ppiVar2 = (int **)(*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    uVar4 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    iVar5 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    if (iVar5 == 0) {
      (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
      return false;
    }
    iVar1 = 0;
  }
  if (*(code **)(*param_1 + 0x94) == (code *)0x0) {
    ppiVar2 = (int **)(param_2 + 0x2c);
LAB_0062dc64:
    if (((ppiVar2[1] != (int *)0x1) || (**ppiVar2 != 1)) || (ppiVar2[3] != (int *)0x0)) {
      piVar7 = param_1 + 0x12;
      iVar6 = (*(code *)PTR_BN_mod_inverse_006a85f0)(uVar3,ppiVar2,piVar7,param_5);
      if (iVar6 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xa7,3,"ecp_smpl.c",599);
      }
      else {
        if (*(int *)(*param_1 + 0x90) == 0) {
          iVar6 = (**(code **)(*param_1 + 0x88))(param_1,uVar4,uVar3,param_5);
        }
        else {
          iVar6 = (*(code *)PTR_BN_mod_sqr_006a96e8)(uVar4,uVar3,piVar7,param_5);
        }
        if ((iVar6 != 0) &&
           ((param_3 == 0 ||
            (iVar6 = (**(code **)(*param_1 + 0x84))(param_1,param_3,param_2 + 4,uVar4,param_5),
            iVar6 != 0)))) {
          if (param_4 == 0) goto LAB_0062dfdc;
          if (*(int *)(*param_1 + 0x90) == 0) {
            iVar6 = (**(code **)(*param_1 + 0x84))(param_1,iVar5,uVar4,uVar3,param_5);
          }
          else {
            iVar6 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar5,uVar4,uVar3,piVar7,param_5);
          }
          if (iVar6 != 0) {
            iVar5 = (**(code **)(*param_1 + 0x84))(param_1,param_4,param_2 + 0x18,iVar5,param_5);
            bVar8 = iVar5 != 0;
            goto LAB_0062dd44;
          }
        }
      }
      goto LAB_0062dd40;
    }
    if (*(code **)(*param_1 + 0x94) == (code *)0x0) {
      if ((param_3 != 0) &&
         (iVar5 = (*(code *)PTR_BN_copy_006a8450)(param_3,param_2 + 4), iVar5 == 0))
      goto LAB_0062dd40;
      if (param_4 == 0) goto LAB_0062dfdc;
      iVar5 = (*(code *)PTR_BN_copy_006a8450)(param_4,param_2 + 0x18);
      bVar8 = iVar5 != 0;
    }
    else {
      if ((param_3 != 0) &&
         (iVar5 = (**(code **)(*param_1 + 0x94))(param_1,param_3,param_2 + 4,param_5), iVar5 == 0))
      goto LAB_0062dd40;
      if (param_4 == 0) {
LAB_0062dfdc:
        bVar8 = true;
      }
      else {
        iVar5 = (**(code **)(*param_1 + 0x94))(param_1,param_4,param_2 + 0x18,param_5);
        bVar8 = iVar5 != 0;
      }
    }
  }
  else {
    iVar6 = (**(code **)(*param_1 + 0x94))(param_1,ppiVar2,param_2 + 0x2c,param_5);
    if (iVar6 != 0) goto LAB_0062dc64;
LAB_0062dd40:
    bVar8 = false;
  }
LAB_0062dd44:
  (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
  param_5 = iVar1;
  if (iVar1 == 0) {
    return bVar8;
  }
LAB_0062dd58:
  (*(code *)PTR_BN_CTX_free_006a7954)(param_5);
  return bVar8;
}

