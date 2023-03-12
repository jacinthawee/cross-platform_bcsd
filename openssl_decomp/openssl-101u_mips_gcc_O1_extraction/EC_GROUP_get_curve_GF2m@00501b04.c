
undefined4 EC_GROUP_get_curve_GF2m(int *param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(*param_1 + 0x1c) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00501b28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x1c))();
    return uVar1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xac,0x42,"ec_lib.c",0x1a5);
  return 0;
}

