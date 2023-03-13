
int ASN1_BIT_STRING_check(ASN1_BIT_STRING *a,uchar *flags,int flags_len)

{
  int iVar1;
  byte bVar2;
  
  if (((a != (ASN1_BIT_STRING *)0x0) && (a->data != (uchar *)0x0)) && (0 < a->length)) {
    iVar1 = 0;
    while( true ) {
      bVar2 = 0xff;
      if (iVar1 < flags_len) {
        bVar2 = ~flags[iVar1];
      }
      bVar2 = bVar2 & a->data[iVar1];
      iVar1 = iVar1 + 1;
      if (iVar1 == a->length) break;
      if (bVar2 != 0) {
        return 0;
      }
    }
    return (uint)(bVar2 == 0);
  }
  return 1;
}

