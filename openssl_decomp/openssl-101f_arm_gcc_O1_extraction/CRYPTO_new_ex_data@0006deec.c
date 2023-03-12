
int CRYPTO_new_ex_data(int class_index,void *obj,CRYPTO_EX_DATA *ad)

{
  int iVar1;
  
  if (impl == (undefined *)0x0) {
    CRYPTO_lock(9,2,"ex_data.c",0xcb);
    if (impl == (undefined *)0x0) {
      impl = PTR_impl_default_0006df44;
    }
    CRYPTO_lock(10,2,"ex_data.c",0xce);
  }
                    /* WARNING: Could not recover jumptable at 0x0006df0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(impl + 0xc))(class_index,obj,ad);
  return iVar1;
}

