
void ERR_remove_thread_state_constprop_3(void)

{
  CRYPTO_THREADID aCStack_198 [50];
  
  CRYPTO_THREADID_current(aCStack_198);
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  (**(code **)(err_fns + 0x24))(aCStack_198);
  return;
}

