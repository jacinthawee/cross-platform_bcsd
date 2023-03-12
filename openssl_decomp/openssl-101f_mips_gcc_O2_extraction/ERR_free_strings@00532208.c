
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_free_strings(void)

{
  if (err_fns != (undefined1 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00532240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(err_fns + 4))();
    return;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x127);
  if (err_fns == (undefined1 *)0x0) {
    err_fns = err_defaults;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x12a);
                    /* WARNING: Could not recover jumptable at 0x005322a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(err_fns + 4))();
  return;
}

