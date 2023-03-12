
char * OCSP_response_status_str(long s)

{
  undefined1 *puVar1;
  
  if (s == 0) {
    puVar1 = rstat_tbl_13557;
  }
  else if (s == 1) {
    puVar1 = (undefined1 *)0x696ad4;
  }
  else if (s == 2) {
    puVar1 = (undefined1 *)0x696adc;
  }
  else if (s == 3) {
    puVar1 = (undefined1 *)0x696ae4;
  }
  else if (s == 5) {
    puVar1 = (undefined1 *)0x696aec;
  }
  else {
    if (s != 6) {
      return "(UNKNOWN)";
    }
    puVar1 = (undefined1 *)0x696af4;
  }
  return *(char **)(puVar1 + 4);
}

