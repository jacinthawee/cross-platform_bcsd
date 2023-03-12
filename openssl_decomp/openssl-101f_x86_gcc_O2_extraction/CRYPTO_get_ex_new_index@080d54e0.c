
int CRYPTO_get_ex_new_index
              (int class_index,long argl,void *argp,undefined1 *new_func,undefined1 *dup_func,
              undefined1 *free_func)

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
                    /* WARNING: Could not recover jumptable at 0x080d552a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(impl + 8))();
  return iVar1;
}

