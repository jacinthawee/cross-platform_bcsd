
char * OCSP_response_status_str(long s)

{
  undefined1 *puVar1;
  
  if (s == 0) {
    puVar1 = rstat_tbl_13558;
  }
  else if (s == 1) {
    puVar1 = (undefined1 *)0x82308e8;
  }
  else if (s == 2) {
    puVar1 = (undefined1 *)0x82308f0;
  }
  else if (s == 3) {
    puVar1 = (undefined1 *)0x82308f8;
  }
  else if (s == 5) {
    puVar1 = (undefined1 *)0x8230900;
  }
  else {
    if (s != 6) {
      return "(UNKNOWN)";
    }
    puVar1 = (undefined1 *)0x8230908;
  }
  return *(char **)(puVar1 + 4);
}

