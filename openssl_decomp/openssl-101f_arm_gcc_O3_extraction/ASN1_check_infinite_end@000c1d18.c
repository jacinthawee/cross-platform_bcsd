
int ASN1_check_infinite_end(uchar **p,long len)

{
  uchar *puVar1;
  
  if (len < 1) {
    return 1;
  }
  if (len != 1) {
    puVar1 = *p;
    if (*puVar1 == '\0') {
      if (puVar1[1] != '\0') {
        return 0;
      }
      *p = puVar1 + 2;
      return 1;
    }
  }
  return 0;
}

