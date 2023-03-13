
int CRYPTO_new_ex_data(int class_index,void *obj,CRYPTO_EX_DATA *ad)

{
  undefined1 *mode;
  int iVar1;
  
  if (impl == (undefined1 *)0x0) {
    CRYPTO_lock(0,9,(char *)0x2,(int)"ex_data.c");
    mode = impl;
    if (impl == (undefined1 *)0x0) {
      impl = impl_default;
    }
    CRYPTO_lock((int)mode,10,(char *)0x2,(int)"ex_data.c");
  }
                    /* WARNING: Could not recover jumptable at 0x080d2f7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(impl + 0xc))();
  return iVar1;
}

