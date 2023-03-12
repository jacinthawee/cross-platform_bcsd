
void ERR_release_err_state_table(lhash_st_ERR_STATE **hash)

{
  undefined1 *mode;
  
  if (err_fns != (undefined1 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0812516c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(err_fns + 0x18))();
    return;
  }
  CRYPTO_lock(0,9,(char *)0x1,(int)"err.c");
  mode = err_fns;
  if (err_fns == (undefined1 *)0x0) {
    err_fns = err_defaults;
  }
  CRYPTO_lock((int)mode,10,(char *)0x1,(int)"err.c");
                    /* WARNING: Could not recover jumptable at 0x081251b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(err_fns + 0x18))();
  return;
}

