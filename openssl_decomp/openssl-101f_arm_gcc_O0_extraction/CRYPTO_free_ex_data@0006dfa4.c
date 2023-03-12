
void CRYPTO_free_ex_data(int class_index,void *obj,CRYPTO_EX_DATA *ad)

{
  if (impl == (undefined *)0x0) {
    CRYPTO_lock(9,2,"ex_data.c",0xcb);
    if (impl == (undefined *)0x0) {
      impl = PTR_impl_default_0006dffc;
    }
    CRYPTO_lock(10,2,"ex_data.c",0xce);
  }
                    /* WARNING: Could not recover jumptable at 0x0006dfc6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(impl + 0x14))(class_index,obj,ad);
  return;
}

