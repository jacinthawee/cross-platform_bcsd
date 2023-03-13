
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_free_strings(void)

{
  undefined1 *mode;
  
  if (err_fns != (undefined1 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08122279. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(err_fns + 4))();
    return;
  }
  CRYPTO_lock(0,9,(char *)0x1,(int)"err.c");
  mode = err_fns;
  if (err_fns == (undefined1 *)0x0) {
    err_fns = err_defaults;
  }
  CRYPTO_lock((int)mode,10,(char *)0x1,(int)"err.c");
                    /* WARNING: Could not recover jumptable at 0x081222c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(err_fns + 4))();
  return;
}

