
undefined4 EC_POINT_set_affine_coordinates_GF2m(int *param_1,int *param_2)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x44);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    ERR_put_error(0x10,0xb9,0x42,"ec_lib.c",0x341);
  }
  else {
    if (*param_1 == *param_2) {
                    /* WARNING: Could not recover jumptable at 0x0008f742. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE)();
      return uVar1;
    }
    ERR_put_error(0x10,0xb9,0x65,"ec_lib.c",0x346);
  }
  return 0;
}

