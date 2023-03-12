
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

lhash_st_ERR_STRING_DATA * ERR_get_string_table(void)

{
  lhash_st_ERR_STRING_DATA *plVar1;
  
  if ((code **)err_fns != (code **)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005327ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    plVar1 = (lhash_st_ERR_STRING_DATA *)(**(code **)err_fns)(0);
    return plVar1;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x127);
  if ((code **)err_fns == (code **)0x0) {
    err_fns = err_defaults;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x12a);
                    /* WARNING: Could not recover jumptable at 0x00532810. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  plVar1 = (lhash_st_ERR_STRING_DATA *)(**(code **)err_fns)(0);
  return plVar1;
}

