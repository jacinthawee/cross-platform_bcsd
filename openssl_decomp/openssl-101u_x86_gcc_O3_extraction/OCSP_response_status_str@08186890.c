
char * OCSP_response_status_str(long s)

{
  undefined1 *puVar1;
  
  if (s == 0) {
    puVar1 = rstat_tbl_13568;
  }
  else if (s == 1) {
    puVar1 = (undefined1 *)0x8230da8;
  }
  else if (s == 2) {
    puVar1 = (undefined1 *)0x8230db0;
  }
  else if (s == 3) {
    puVar1 = (undefined1 *)0x8230db8;
  }
  else if (s == 5) {
    puVar1 = (undefined1 *)0x8230dc0;
  }
  else {
    if (s != 6) {
      return "(UNKNOWN)";
    }
    puVar1 = (undefined1 *)0x8230dc8;
  }
  return *(char **)(puVar1 + 4);
}

