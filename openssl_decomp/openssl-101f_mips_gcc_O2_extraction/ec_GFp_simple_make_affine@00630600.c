
undefined4 ec_GFp_simple_make_affine(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*(int *)(param_2 + 0x40) != 0) ||
     (iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)(), iVar1 != 0)) {
    return 1;
  }
  if (param_3 == 0) {
    param_3 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (param_3 == 0) {
      return 0;
    }
    (*(code *)PTR_BN_CTX_start_006a9644)(param_3);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_3);
    iVar1 = (*(code *)PTR_BN_CTX_get_006a9648)(param_3);
    if (((iVar1 == 0) ||
        (iVar3 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)
                           (param_1,param_2,uVar2,iVar1,param_3), iVar3 == 0)) ||
       (iVar1 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GFp_006a9758)
                          (param_1,param_2,uVar2,iVar1,param_3), iVar1 == 0)) {
      uVar2 = 0;
      (*(code *)PTR_BN_CTX_end_006a9654)(param_3);
      goto LAB_00630754;
    }
    iVar1 = param_3;
    if (*(int *)(param_2 + 0x40) != 0) {
      uVar2 = 1;
      (*(code *)PTR_BN_CTX_end_006a9654)(param_3);
      goto LAB_00630754;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a9644)(param_3);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_3);
    iVar1 = (*(code *)PTR_BN_CTX_get_006a9648)(param_3);
    if (((iVar1 == 0) ||
        (iVar3 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)
                           (param_1,param_2,uVar2,iVar1,param_3), iVar3 == 0)) ||
       (iVar1 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GFp_006a9758)
                          (param_1,param_2,uVar2,iVar1,param_3), iVar1 == 0)) {
      (*(code *)PTR_BN_CTX_end_006a9654)(param_3);
      return 0;
    }
    iVar1 = 0;
    if (*(int *)(param_2 + 0x40) != 0) {
      (*(code *)PTR_BN_CTX_end_006a9654)(param_3);
      return 1;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x66,0x44,"ecp_smpl.c",0x48f);
  (*(code *)PTR_BN_CTX_end_006a9654)(param_3);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = 0;
  param_3 = iVar1;
LAB_00630754:
  (*(code *)PTR_BN_CTX_free_006a8a40)(param_3);
  return uVar2;
}

