
void ERR_release_err_state_table(lhash_st_ERR_STATE **hash)

{
  if (err_fns != (undefined1 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0052f5d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(err_fns + 0x18))(hash);
    return;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
  if (err_fns == (undefined1 *)0x0) {
    err_fns = err_defaults;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x12a);
                    /* WARNING: Could not recover jumptable at 0x0052f640. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(err_fns + 0x18))(hash);
  return;
}

