
undefined4
nuron_mod_exp_dh(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  undefined4 uVar1;
  
  if (pvDSOHandle != 0) {
                    /* WARNING: Could not recover jumptable at 0x005d4db8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*pfnModExp)(param_2,param_3,param_4,param_5);
    return uVar1;
  }
  if (NURON_lib_error_code == 0) {
    NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(NURON_lib_error_code,0x67,0x69,"e_nuron.c",0xc1);
  return 0;
}
