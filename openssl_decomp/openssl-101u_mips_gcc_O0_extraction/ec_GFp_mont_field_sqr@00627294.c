
undefined4
ec_GFp_mont_field_sqr(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xa0) != 0) {
    uVar1 = (*(code *)PTR_BN_mod_mul_montgomery_006a8558)
                      (param_2,param_3,param_3,*(int *)(param_1 + 0xa0),param_4);
    return uVar1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x84,0x6f,"ecp_mont.c",0x10c);
  return 0;
}
