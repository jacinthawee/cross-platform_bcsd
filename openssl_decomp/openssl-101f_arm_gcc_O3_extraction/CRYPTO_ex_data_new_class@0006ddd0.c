
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_ex_data_new_class(void)

{
  int iVar1;
  
  if (impl != (code **)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0006dde4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**impl)();
    return iVar1;
  }
  CRYPTO_lock(9,2,"ex_data.c",0xcb);
  if (impl == (code **)0x0) {
    impl = (code **)PTR_impl_default_0006de20;
  }
  CRYPTO_lock(10,2,"ex_data.c",0xce);
                    /* WARNING: Could not recover jumptable at 0x0006de16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**impl)();
  return iVar1;
}

