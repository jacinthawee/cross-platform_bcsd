
int CRYPTO_dup_ex_data(int class_index,CRYPTO_EX_DATA *to,CRYPTO_EX_DATA *from)

{
  int iVar1;
  
  if (impl == (undefined *)0x0) {
    CRYPTO_lock(9,2,"ex_data.c",0xcb);
    if (impl == (undefined *)0x0) {
      impl = PTR_impl_default_0006dfa0;
    }
    CRYPTO_lock(10,2,"ex_data.c",0xce);
  }
                    /* WARNING: Could not recover jumptable at 0x0006df6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(impl + 0x10))(class_index,to,from);
  return iVar1;
}
