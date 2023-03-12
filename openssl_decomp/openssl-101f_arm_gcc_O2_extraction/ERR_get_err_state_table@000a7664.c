
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

lhash_st_ERR_STATE * ERR_get_err_state_table(void)

{
  lhash_st_ERR_STATE *plVar1;
  
  if (err_fns != (undefined1 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000a767a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    plVar1 = (lhash_st_ERR_STATE *)(**(code **)(err_fns + 0x14))(0);
    return plVar1;
  }
  CRYPTO_lock(9,1,"err.c",0x127);
  if (err_fns == (undefined1 *)0x0) {
    err_fns = &err_defaults;
  }
  CRYPTO_lock(10,1,"err.c",0x12a);
                    /* WARNING: Could not recover jumptable at 0x000a76b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  plVar1 = (lhash_st_ERR_STATE *)(**(code **)(err_fns + 0x14))(0);
  return plVar1;
}

