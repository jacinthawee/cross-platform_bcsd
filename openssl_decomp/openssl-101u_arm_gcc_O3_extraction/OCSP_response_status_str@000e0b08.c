
char * OCSP_response_status_str(long s)

{
  int *piVar1;
  
  piVar1 = &rstat_tbl_16196;
  do {
    if (s == *piVar1) {
      return (char *)piVar1[1];
    }
    piVar1 = piVar1 + 2;
  } while (piVar1 < cstat_tbl_16200);
  return "(UNKNOWN)";
}

