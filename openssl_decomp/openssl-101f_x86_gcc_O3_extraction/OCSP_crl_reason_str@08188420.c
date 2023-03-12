
char * OCSP_crl_reason_str(long s)

{
  undefined1 *puVar1;
  
  if (s == 0) {
    puVar1 = reason_tbl_13566;
  }
  else if (s == 1) {
    puVar1 = (undefined1 *)0x8230888;
  }
  else if (s == 2) {
    puVar1 = (undefined1 *)0x8230890;
  }
  else if (s == 3) {
    puVar1 = (undefined1 *)0x8230898;
  }
  else if (s == 4) {
    puVar1 = (undefined1 *)0x82308a0;
  }
  else if (s == 5) {
    puVar1 = (undefined1 *)0x82308a8;
  }
  else if (s == 6) {
    puVar1 = (undefined1 *)0x82308b0;
  }
  else {
    if (s != 8) {
      return "(UNKNOWN)";
    }
    puVar1 = (undefined1 *)0x82308b8;
  }
  return *(char **)(puVar1 + 4);
}

