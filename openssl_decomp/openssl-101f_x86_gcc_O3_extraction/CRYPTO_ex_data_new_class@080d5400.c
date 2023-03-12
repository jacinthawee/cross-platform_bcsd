
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_ex_data_new_class(void)

{
  code **mode;
  int iVar1;
  
  if ((code **)impl != (code **)0x0) {
                    /* WARNING: Could not recover jumptable at 0x080d540b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)impl)();
    return iVar1;
  }
  CRYPTO_lock(0,9,(char *)0x2,(int)"ex_data.c");
  mode = (code **)impl;
  if ((code **)impl == (code **)0x0) {
    impl = impl_default;
  }
  CRYPTO_lock((int)mode,10,(char *)0x2,(int)"ex_data.c");
                    /* WARNING: Could not recover jumptable at 0x080d544f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)impl)();
  return iVar1;
}

