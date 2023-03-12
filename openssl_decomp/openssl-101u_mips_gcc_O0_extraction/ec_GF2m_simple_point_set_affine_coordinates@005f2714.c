
undefined4
ec_GF2m_simple_point_set_affine_coordinates(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_3 != 0) && (param_4 != 0)) {
    iVar1 = (*(code *)PTR_BN_copy_006a8450)(param_2 + 4,param_3);
    if (iVar1 != 0) {
      (*(code *)PTR_BN_set_negative_006a85c4)(param_2 + 4,0);
      iVar1 = (*(code *)PTR_BN_copy_006a8450)(param_2 + 0x18,param_4);
      if (iVar1 != 0) {
        (*(code *)PTR_BN_set_negative_006a85c4)(param_2 + 0x18,0);
        uVar2 = (*(code *)PTR_BN_value_one_006a8554)();
        iVar1 = (*(code *)PTR_BN_copy_006a8450)(param_2 + 0x2c,uVar2);
        if (iVar1 != 0) {
          (*(code *)PTR_BN_set_negative_006a85c4)(param_2 + 0x2c,0);
          *(undefined4 *)(param_2 + 0x40) = 1;
          return 1;
        }
      }
    }
    return 0;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xa3,0x43,"ec2_smpl.c",0x18c);
  return 0;
}

