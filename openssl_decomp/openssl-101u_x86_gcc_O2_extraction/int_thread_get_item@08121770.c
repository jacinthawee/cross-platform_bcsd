
void * int_thread_get_item(void *param_1)

{
  void *mode;
  undefined1 *mode_00;
  int in_GS_OFFSET;
  char *pcVar1;
  undefined4 uVar2;
  _LHASH *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (err_fns == (undefined1 *)0x0) {
    mode_00 = err_fns;
    CRYPTO_lock(0,9,(char *)0x1,(int)"err.c");
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    CRYPTO_lock((int)mode_00,10,(char *)0x1,(int)"err.c");
  }
  local_14 = (_LHASH *)(**(code **)(err_fns + 0x14))(0);
  if (local_14 == (_LHASH *)0x0) {
    mode = (void *)0x0;
  }
  else {
    uVar2 = 499;
    pcVar1 = "err.c";
    CRYPTO_lock((int)local_14,5,(char *)0x1,(int)"err.c");
    mode = lh_retrieve(local_14,param_1);
    CRYPTO_lock((int)mode,6,(char *)0x1,(int)"err.c");
    (**(code **)(err_fns + 0x18))(&local_14,param_1,pcVar1,uVar2);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return mode;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

