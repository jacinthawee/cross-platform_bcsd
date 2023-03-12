
int CRYPTO_dup_ex_data(int class_index,CRYPTO_EX_DATA *to,CRYPTO_EX_DATA *from)

{
  int iVar1;
  
  if (impl != (undefined1 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004c0fac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(impl + 0x10))(class_index,to,from);
    return iVar1;
  }
  CRYPTO_lock(9,2,"ex_data.c",0xc9);
  if (impl == (undefined1 *)0x0) {
    impl = impl_default;
  }
  CRYPTO_lock(10,2,"ex_data.c",0xcc);
                    /* WARNING: Could not recover jumptable at 0x004c1024. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(impl + 0x10))(class_index,to,from);
  return iVar1;
}

