
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_OBJ_strings(void)

{
  char *pcVar1;
  
  pcVar1 = ERR_func_error_string(OBJ_str_functs);
  if (pcVar1 != (char *)0x0) {
    return;
  }
  ERR_load_strings(0,(ERR_STRING_DATA *)&OBJ_str_functs);
  ERR_load_strings(0,(ERR_STRING_DATA *)OBJ_str_reasons);
  return;
}
