
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_RAND_strings(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ERR_func_error_string_006a9560)(RAND_str_functs._0_4_);
  if (iVar1 != 0) {
    return;
  }
  (*(code *)PTR_ERR_load_strings_006a9564)(0,RAND_str_functs);
                    /* WARNING: Could not recover jumptable at 0x006066f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_ERR_load_strings_006a9564)(0,RAND_str_reasons);
  return;
}
