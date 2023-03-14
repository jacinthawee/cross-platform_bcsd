
char * OCSP_crl_reason_str(long s)

{
  undefined1 *puVar1;
  
  if (s == 0) {
    puVar1 = reason_tbl_13576;
  }
  else if (s == 1) {
    puVar1 = (undefined1 *)0x8230d48;
  }
  else if (s == 2) {
    puVar1 = (undefined1 *)0x8230d50;
  }
  else if (s == 3) {
    puVar1 = (undefined1 *)0x8230d58;
  }
  else if (s == 4) {
    puVar1 = (undefined1 *)0x8230d60;
  }
  else if (s == 5) {
    puVar1 = (undefined1 *)0x8230d68;
  }
  else if (s == 6) {
    puVar1 = (undefined1 *)0x8230d70;
  }
  else {
    if (s != 8) {
      return "(UNKNOWN)";
    }
    puVar1 = (undefined1 *)0x8230d78;
  }
  return *(char **)(puVar1 + 4);
}
