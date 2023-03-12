
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CRYPTO_cleanup_all_ex_data(void)

{
  if (impl != (undefined1 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004c3ee4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(impl + 4))();
    return;
  }
  CRYPTO_lock(9,2,"ex_data.c",0xcb);
  if (impl == (undefined1 *)0x0) {
    impl = impl_default;
  }
  CRYPTO_lock(10,2,"ex_data.c",0xce);
                    /* WARNING: Could not recover jumptable at 0x004c3f44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(impl + 4))();
  return;
}

