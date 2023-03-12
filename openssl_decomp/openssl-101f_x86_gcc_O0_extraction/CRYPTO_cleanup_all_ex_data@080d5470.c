
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CRYPTO_cleanup_all_ex_data(void)

{
  undefined1 *mode;
  
  if (impl != (undefined1 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x080d5479. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(impl + 4))();
    return;
  }
  CRYPTO_lock(0,9,(char *)0x2,(int)"ex_data.c");
  mode = impl;
  if (impl == (undefined1 *)0x0) {
    impl = impl_default;
  }
  CRYPTO_lock((int)mode,10,(char *)0x2,(int)"ex_data.c");
                    /* WARNING: Could not recover jumptable at 0x080d54c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(impl + 4))();
  return;
}

