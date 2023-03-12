
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CRYPTO_cleanup_all_ex_data(void)

{
  if (impl != (undefined *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0006de38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(impl + 4))();
    return;
  }
  CRYPTO_lock(9,2,"ex_data.c",0xcb);
  if (impl == (undefined *)0x0) {
    impl = PTR_impl_default_0006de74;
  }
  CRYPTO_lock(10,2,"ex_data.c",0xce);
                    /* WARNING: Could not recover jumptable at 0x0006de6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(impl + 4))();
  return;
}

