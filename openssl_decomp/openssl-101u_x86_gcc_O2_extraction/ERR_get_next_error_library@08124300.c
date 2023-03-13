
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ERR_get_next_error_library(void)

{
  undefined1 *mode;
  int iVar1;
  
  if (err_fns != (undefined1 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0812430c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(err_fns + 0x28))();
    return iVar1;
  }
  CRYPTO_lock(0,9,(char *)0x1,(int)"err.c");
  mode = err_fns;
  if (err_fns == (undefined1 *)0x0) {
    err_fns = err_defaults;
  }
  CRYPTO_lock((int)mode,10,(char *)0x1,(int)"err.c");
                    /* WARNING: Could not recover jumptable at 0x08124350. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(err_fns + 0x28))();
  return iVar1;
}

