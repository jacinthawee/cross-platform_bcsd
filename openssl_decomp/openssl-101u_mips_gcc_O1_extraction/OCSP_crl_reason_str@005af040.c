
char * OCSP_crl_reason_str(long s)

{
  undefined1 *puVar1;
  
  if (s == 0) {
    puVar1 = reason_tbl_13575;
  }
  else if (s == 1) {
    puVar1 = (undefined1 *)0x695920;
  }
  else if (s == 2) {
    puVar1 = (undefined1 *)0x695928;
  }
  else if (s == 3) {
    puVar1 = (undefined1 *)0x695930;
  }
  else if (s == 4) {
    puVar1 = (undefined1 *)0x695938;
  }
  else if (s == 5) {
    puVar1 = (undefined1 *)0x695940;
  }
  else if (s == 6) {
    puVar1 = (undefined1 *)0x695948;
  }
  else {
    if (s != 8) {
      return "(UNKNOWN)";
    }
    puVar1 = (undefined1 *)0x695950;
  }
  return *(char **)(puVar1 + 4);
}

