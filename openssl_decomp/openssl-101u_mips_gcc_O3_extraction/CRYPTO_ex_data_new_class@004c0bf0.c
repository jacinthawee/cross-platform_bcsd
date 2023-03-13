
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_ex_data_new_class(void)

{
  int iVar1;
  
  if ((code **)impl != (code **)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004c0c28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)impl)();
    return iVar1;
  }
  CRYPTO_lock(9,2,"ex_data.c",0xc9);
  if ((code **)impl == (code **)0x0) {
    impl = impl_default;
  }
  CRYPTO_lock(10,2,"ex_data.c",0xcc);
                    /* WARNING: Could not recover jumptable at 0x004c0c88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)impl)();
  return iVar1;
}

