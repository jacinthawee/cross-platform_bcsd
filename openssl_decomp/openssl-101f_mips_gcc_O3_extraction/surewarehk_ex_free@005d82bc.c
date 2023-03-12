
void surewarehk_ex_free(undefined4 param_1,undefined4 param_2)

{
  if (p_surewarehk_Free != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005d82cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*p_surewarehk_Free)(param_2,0);
    return;
  }
  if (SUREWARE_lib_error_code == 0) {
    SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
  }
                    /* WARNING: Could not recover jumptable at 0x005d8334. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x66,0x75,"e_sureware.c");
  return;
}

