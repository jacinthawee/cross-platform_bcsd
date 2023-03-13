
undefined4 EC_POINT_set_affine_coordinates_GF2m(int *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x44);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    uVar2 = 0x42;
    uVar1 = 0x341;
  }
  else {
    if (*param_1 == *param_2) {
                    /* WARNING: Could not recover jumptable at 0x00502b64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE)();
      return uVar1;
    }
    uVar2 = 0x65;
    uVar1 = 0x346;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xb9,uVar2,"ec_lib.c",uVar1);
  return 0;
}

