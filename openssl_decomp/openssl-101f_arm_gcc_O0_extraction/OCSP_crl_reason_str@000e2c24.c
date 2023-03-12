
char * OCSP_crl_reason_str(long s)

{
  int *piVar1;
  
  piVar1 = (int *)PTR_reason_tbl_16194_000e2c44;
  do {
    if (s == *piVar1) {
      return (char *)piVar1[1];
    }
    piVar1 = piVar1 + 2;
  } while (piVar1 < PTR_reason_tbl_16194_000e2c44 + 0x40);
  return "(UNKNOWN)";
}

