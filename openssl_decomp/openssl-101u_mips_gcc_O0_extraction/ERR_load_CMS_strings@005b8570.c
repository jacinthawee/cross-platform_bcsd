
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_CMS_strings(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ERR_func_error_string_006a8440)(CMS_str_functs._0_4_);
  if (iVar1 != 0) {
    return;
  }
  (*(code *)PTR_ERR_load_strings_006a8444)(0,CMS_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005b85e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_ERR_load_strings_006a8444)(0,CMS_str_reasons);
  return;
}
