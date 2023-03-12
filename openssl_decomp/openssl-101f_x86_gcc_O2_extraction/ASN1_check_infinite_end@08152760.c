
int ASN1_check_infinite_end(uchar **p,long len)

{
  uchar *puVar1;
  int iVar2;
  
  if (len < 1) {
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
    if (len != 1) {
      puVar1 = *p;
      if ((*puVar1 == '\0') && (puVar1[1] == '\0')) {
        *p = puVar1 + 2;
        return 1;
      }
    }
  }
  return iVar2;
}

