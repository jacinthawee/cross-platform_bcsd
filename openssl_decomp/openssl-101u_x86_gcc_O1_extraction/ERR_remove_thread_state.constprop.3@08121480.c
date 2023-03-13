
void ERR_remove_thread_state_constprop_3(void)

{
  undefined1 *mode;
  int in_GS_OFFSET;
  CRYPTO_THREADID local_1a0 [50];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  CRYPTO_THREADID_current(local_1a0);
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(0,9,(char *)0x1,(int)"err.c");
    mode = err_fns;
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    CRYPTO_lock((int)mode,10,(char *)0x1,(int)"err.c");
  }
  (**(code **)(err_fns + 0x24))(local_1a0);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

