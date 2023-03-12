
undefined4 EC_GROUP_set_curve_GF2m(int *param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(*param_1 + 0x18) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08101253. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x18))();
    return uVar1;
  }
  ERR_put_error(0x10,0xb0,0x42,"ec_lib.c",0x1b1);
  return 0;
}

