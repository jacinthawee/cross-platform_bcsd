
void surewarehk_ex_free(void)

{
  if (p_surewarehk_Free != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x081a364f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*p_surewarehk_Free)();
    return;
  }
  if (SUREWARE_lib_error_code == 0) {
    SUREWARE_lib_error_code = ERR_get_next_error_library();
  }
  ERR_put_error(SUREWARE_lib_error_code,0x66,0x75,"e_sureware.c",0x36d);
  return;
}

