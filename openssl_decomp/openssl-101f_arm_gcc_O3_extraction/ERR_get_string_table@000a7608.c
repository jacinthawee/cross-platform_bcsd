
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

lhash_st_ERR_STRING_DATA * ERR_get_string_table(void)

{
  lhash_st_ERR_STRING_DATA *plVar1;
  
  if (err_fns != (code **)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000a761e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    plVar1 = (lhash_st_ERR_STRING_DATA *)(**err_fns)(0);
    return plVar1;
  }
  CRYPTO_lock(9,1,"err.c",0x127);
  if (err_fns == (code **)0x0) {
    err_fns = (code **)&err_defaults;
  }
  CRYPTO_lock(10,1,"err.c",0x12a);
                    /* WARNING: Could not recover jumptable at 0x000a7656. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  plVar1 = (lhash_st_ERR_STRING_DATA *)(**err_fns)(0);
  return plVar1;
}

