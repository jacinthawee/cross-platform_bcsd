
int CRYPTO_get_ex_new_index
              (int class_index,long argl,void *argp,undefined1 *new_func,undefined1 *dup_func,
              undefined1 *free_func)

{
  int iVar1;
  
  if (impl == (undefined *)0x0) {
    CRYPTO_lock(9,2,"ex_data.c",0xc9);
    if (impl == (undefined *)0x0) {
      impl = PTR_impl_default_0006ba50;
    }
    CRYPTO_lock(10,2,"ex_data.c",0xcc);
  }
                    /* WARNING: Could not recover jumptable at 0x0006ba1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(impl + 8))(class_index,argl,argp,new_func);
  return iVar1;
}

