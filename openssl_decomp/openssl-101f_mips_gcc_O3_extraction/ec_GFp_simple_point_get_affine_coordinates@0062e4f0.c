
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
  
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)();
  if (iVar1 != 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xa7,0x6a,"ecp_smpl.c",0x21a);
    return false;
  }
  if (param_5 == 0) {
    param_5 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (param_5 == 0) {
      return false;
    }
    (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
    ppiVar2 = (int **)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    uVar4 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    iVar5 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    iVar1 = param_5;
    if (iVar5 == 0) {
      bVar8 = false;
      (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
      goto LAB_0062e6d8;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
    ppiVar2 = (int **)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    uVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    uVar4 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    iVar5 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    if (iVar5 == 0) {
      (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
      return false;
    }
    iVar1 = 0;
  }
  if (*(code **)(*param_1 + 0x94) == (code *)0x0) {
    ppiVar2 = (int **)(param_2 + 0x2c);
LAB_0062e5e4:
    if (((ppiVar2[1] != (int *)0x1) || (**ppiVar2 != 1)) || (ppiVar2[3] != (int *)0x0)) {
      piVar7 = param_1 + 0x12;
      iVar6 = (*(code *)PTR_BN_mod_inverse_006a9714)(uVar3,ppiVar2,piVar7,param_5);
      if (iVar6 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xa7,3,"ecp_smpl.c",0x255);
      }
      else {
        if (*(int *)(*param_1 + 0x90) == 0) {
          iVar6 = (**(code **)(*param_1 + 0x88))(param_1,uVar4,uVar3,param_5);
        }
        else {
          iVar6 = (*(code *)PTR_BN_mod_sqr_006aa7f0)(uVar4,uVar3,piVar7,param_5);
        }
        if ((iVar6 != 0) &&
           ((param_3 == 0 ||
            (iVar6 = (**(code **)(*param_1 + 0x84))(param_1,param_3,param_2 + 4,uVar4,param_5),
            iVar6 != 0)))) {
          if (param_4 == 0) goto LAB_0062e95c;
          if (*(int *)(*param_1 + 0x90) == 0) {
            iVar6 = (**(code **)(*param_1 + 0x84))(param_1,iVar5,uVar4,uVar3,param_5);
          }
          else {
            iVar6 = (*(code *)PTR_BN_mod_mul_006a9698)(iVar5,uVar4,uVar3,piVar7,param_5);
          }
          if (iVar6 != 0) {
            iVar5 = (**(code **)(*param_1 + 0x84))(param_1,param_4,param_2 + 0x18,iVar5,param_5);
            bVar8 = iVar5 != 0;
            goto LAB_0062e6c4;
          }
        }
      }
      goto LAB_0062e6c0;
    }
    if (*(code **)(*param_1 + 0x94) == (code *)0x0) {
      if ((param_3 != 0) &&
         (iVar5 = (*(code *)PTR_BN_copy_006a9570)(param_3,param_2 + 4), iVar5 == 0))
      goto LAB_0062e6c0;
      if (param_4 == 0) goto LAB_0062e95c;
      iVar5 = (*(code *)PTR_BN_copy_006a9570)(param_4,param_2 + 0x18);
      bVar8 = iVar5 != 0;
    }
    else {
      if ((param_3 != 0) &&
         (iVar5 = (**(code **)(*param_1 + 0x94))(param_1,param_3,param_2 + 4,param_5), iVar5 == 0))
      goto LAB_0062e6c0;
      if (param_4 == 0) {
LAB_0062e95c:
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
    if (iVar6 != 0) goto LAB_0062e5e4;
LAB_0062e6c0:
    bVar8 = false;
  }
LAB_0062e6c4:
  (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
  param_5 = iVar1;
  if (iVar1 == 0) {
    return bVar8;
  }
LAB_0062e6d8:
  (*(code *)PTR_BN_CTX_free_006a8a40)(param_5);
  return bVar8;
}

