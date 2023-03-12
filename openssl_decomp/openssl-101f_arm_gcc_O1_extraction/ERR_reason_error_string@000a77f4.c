
char * ERR_reason_error_string(ulong e)

{
  char *pcVar1;
  uint local_18 [2];
  
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  local_18[0] = e & 0xff000fff;
  pcVar1 = (char *)(**(code **)(err_fns + 8))(local_18);
  if ((pcVar1 != (char *)0x0) ||
     (local_18[0] = e & 0xfff, pcVar1 = (char *)(**(code **)(err_fns + 8))(local_18),
     pcVar1 != (char *)0x0)) {
    pcVar1 = *(char **)(pcVar1 + 4);
  }
  return pcVar1;
}

