
void ERR_load_TS_strings(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ERR_func_error_string_006a9560)(TS_str_functs._0_4_);
  if (iVar1 != 0) {
    return;
  }
  (*(code *)PTR_ERR_load_strings_006a9564)(0,TS_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005c1ce0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_ERR_load_strings_006a9564)(0,TS_str_reasons);
  return;
}
