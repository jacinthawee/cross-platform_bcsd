
char * OCSP_crl_reason_str(long s)

{
  undefined1 *puVar1;
  
  if (s == 0) {
    puVar1 = reason_tbl_13565;
  }
  else if (s == 1) {
    puVar1 = (undefined1 *)0x696a7c;
  }
  else if (s == 2) {
    puVar1 = (undefined1 *)0x696a84;
  }
  else if (s == 3) {
    puVar1 = (undefined1 *)0x696a8c;
  }
  else if (s == 4) {
    puVar1 = (undefined1 *)0x696a94;
  }
  else if (s == 5) {
    puVar1 = (undefined1 *)0x696a9c;
  }
  else if (s == 6) {
    puVar1 = (undefined1 *)0x696aa4;
  }
  else {
    if (s != 8) {
      return "(UNKNOWN)";
    }
    puVar1 = (undefined1 *)0x696aac;
  }
  return *(char **)(puVar1 + 4);
}

