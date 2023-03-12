
void CRYPTO_free_ex_data(int class_index,void *obj,CRYPTO_EX_DATA *ad)

{
  if (impl != (undefined1 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004c42b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(impl + 0x14))(class_index,obj,ad);
    return;
  }
  CRYPTO_lock(9,2,"ex_data.c",0xcb);
  if (impl == (undefined1 *)0x0) {
    impl = impl_default;
  }
  CRYPTO_lock(10,2,"ex_data.c",0xce);
                    /* WARNING: Could not recover jumptable at 0x004c4328. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(impl + 0x14))(class_index,obj,ad);
  return;
}

