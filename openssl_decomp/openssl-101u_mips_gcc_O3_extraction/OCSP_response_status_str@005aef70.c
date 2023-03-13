
char * OCSP_response_status_str(long s)

{
  undefined1 *puVar1;
  
  if (s == 0) {
    puVar1 = rstat_tbl_13567;
  }
  else if (s == 1) {
    puVar1 = (undefined1 *)0x695978;
  }
  else if (s == 2) {
    puVar1 = (undefined1 *)0x695980;
  }
  else if (s == 3) {
    puVar1 = (undefined1 *)0x695988;
  }
  else if (s == 5) {
    puVar1 = (undefined1 *)0x695990;
  }
  else {
    if (s != 6) {
      return "(UNKNOWN)";
    }
    puVar1 = (undefined1 *)0x695998;
  }
  return *(char **)(puVar1 + 4);
}

