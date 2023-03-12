
char * ERR_reason_error_string(ulong e)

{
  undefined1 *mode;
  int iVar1;
  char *pcVar2;
  int in_GS_OFFSET;
  uint local_18 [2];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(0,9,(char *)0x1,(int)"err.c");
    mode = err_fns;
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    CRYPTO_lock((int)mode,10,(char *)0x1,(int)"err.c");
  }
  local_18[0] = e & 0xff000fff;
  iVar1 = (**(code **)(err_fns + 8))(local_18);
  if (iVar1 == 0) {
    local_18[0] = e & 0xfff;
    iVar1 = (**(code **)(err_fns + 8))(local_18);
    pcVar2 = (char *)0x0;
    if (iVar1 == 0) goto LAB_08125377;
  }
  pcVar2 = *(char **)(iVar1 + 4);
LAB_08125377:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pcVar2;
}

