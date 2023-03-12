
char * OCSP_cert_status_str(long s)

{
  int *piVar1;
  
  piVar1 = (int *)PTR_cstat_tbl_16200_000e0b50;
  do {
    if (s == *piVar1) {
      return (char *)piVar1[1];
    }
    piVar1 = piVar1 + 2;
  } while (piVar1 < PTR_cstat_tbl_16200_000e0b50 + 0x18);
  return "(UNKNOWN)";
}

