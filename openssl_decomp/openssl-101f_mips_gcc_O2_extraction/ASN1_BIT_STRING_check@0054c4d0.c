
int ASN1_BIT_STRING_check(ASN1_BIT_STRING *a,uchar *flags,int flags_len)

{
  byte bVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  
  if ((a != (ASN1_BIT_STRING *)0x0) && (pbVar2 = a->data, pbVar2 != (byte *)0x0)) {
    iVar4 = 0;
    if (0 < a->length) {
      while( true ) {
        bVar3 = 0xff;
        if (iVar4 < flags_len) {
          bVar3 = ~*flags;
        }
        bVar1 = *pbVar2;
        iVar4 = iVar4 + 1;
        pbVar2 = pbVar2 + 1;
        flags = flags + 1;
        if (iVar4 == a->length) break;
        if ((bVar3 & bVar1) != 0) {
          return 0;
        }
      }
      return (uint)((bVar3 & bVar1) == 0);
    }
  }
  return 1;
}

