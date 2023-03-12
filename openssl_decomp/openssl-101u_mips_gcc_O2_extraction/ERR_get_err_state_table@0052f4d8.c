
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

lhash_st_ERR_STATE * ERR_get_err_state_table(void)

{
  lhash_st_ERR_STATE *plVar1;
  
  if (err_fns != (undefined1 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0052f514. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    plVar1 = (lhash_st_ERR_STATE *)(**(code **)(err_fns + 0x14))(0);
    return plVar1;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
  if (err_fns == (undefined1 *)0x0) {
    err_fns = err_defaults;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x12a);
                    /* WARNING: Could not recover jumptable at 0x0052f578. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  plVar1 = (lhash_st_ERR_STATE *)(**(code **)(err_fns + 0x14))(0);
  return plVar1;
}

