
int ec_GF2m_simple_point_get_affine_coordinates
              (undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a864c)();
  if (iVar1 == 0) {
    uVar2 = (*(code *)PTR_BN_value_one_006a8554)();
    iVar1 = (*(code *)PTR_BN_cmp_006a7960)(param_2 + 0x2c,uVar2);
    if (iVar1 == 0) {
      if (param_3 != 0) {
        iVar3 = (*(code *)PTR_BN_copy_006a8450)(param_3,param_2 + 4);
        if (iVar3 == 0) {
          return 0;
        }
        (*(code *)PTR_BN_set_negative_006a85c4)(param_3,0);
      }
      if (param_4 == 0) {
        iVar1 = 1;
      }
      else {
        iVar3 = (*(code *)PTR_BN_copy_006a8450)(param_4,param_2 + 0x18);
        if (iVar3 != 0) {
          iVar1 = 1;
          (*(code *)PTR_BN_set_negative_006a85c4)(param_4,0);
        }
      }
      return iVar1;
    }
    uVar4 = 0x42;
    uVar2 = 0x1b3;
  }
  else {
    uVar4 = 0x6a;
    uVar2 = 0x1ad;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xa2,uVar4,"ec2_smpl.c",uVar2);
  return 0;
}

