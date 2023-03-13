
undefined4 ec_GFp_simple_make_affine(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*(int *)(param_2 + 0x40) != 0) ||
     (iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a864c)(), iVar1 != 0)) {
    return 1;
  }
  if (param_3 == 0) {
    param_3 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if (param_3 == 0) {
      return 0;
    }
    (*(code *)PTR_BN_CTX_start_006a8528)(param_3);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a852c)(param_3);
    iVar1 = (*(code *)PTR_BN_CTX_get_006a852c)(param_3);
    if (((iVar1 == 0) ||
        (iVar3 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698)
                           (param_1,param_2,uVar2,iVar1,param_3), iVar3 == 0)) ||
       (iVar1 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GFp_006a8634)
                          (param_1,param_2,uVar2,iVar1,param_3), iVar1 == 0)) {
      uVar2 = 0;
      (*(code *)PTR_BN_CTX_end_006a8530)(param_3);
      goto LAB_0062fdd4;
    }
    iVar1 = param_3;
    if (*(int *)(param_2 + 0x40) != 0) {
      uVar2 = 1;
      (*(code *)PTR_BN_CTX_end_006a8530)(param_3);
      goto LAB_0062fdd4;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a8528)(param_3);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a852c)(param_3);
    iVar1 = (*(code *)PTR_BN_CTX_get_006a852c)(param_3);
    if (((iVar1 == 0) ||
        (iVar3 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698)
                           (param_1,param_2,uVar2,iVar1,param_3), iVar3 == 0)) ||
       (iVar1 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GFp_006a8634)
                          (param_1,param_2,uVar2,iVar1,param_3), iVar1 == 0)) {
      (*(code *)PTR_BN_CTX_end_006a8530)(param_3);
      return 0;
    }
    iVar1 = 0;
    if (*(int *)(param_2 + 0x40) != 0) {
      (*(code *)PTR_BN_CTX_end_006a8530)(param_3);
      return 1;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x66,0x44,"ecp_smpl.c",0x4d4);
  (*(code *)PTR_BN_CTX_end_006a8530)(param_3);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = 0;
  param_3 = iVar1;
LAB_0062fdd4:
  (*(code *)PTR_BN_CTX_free_006a7954)(param_3);
  return uVar2;
}

