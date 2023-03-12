
undefined4
ec_GFp_simple_point_set_affine_coordinates
          (undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if ((param_3 != 0) && (param_4 != 0)) {
    uVar1 = (*(code *)PTR_BN_value_one_006a8554)();
    uVar1 = (*(code *)PTR_EC_POINT_set_Jprojective_coordinates_GFp_006a991c)
                      (param_1,param_2,param_3,param_4,uVar1,param_5);
    return uVar1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xa8,0x43,"ecp_smpl.c",0x210);
  return 0;
}

