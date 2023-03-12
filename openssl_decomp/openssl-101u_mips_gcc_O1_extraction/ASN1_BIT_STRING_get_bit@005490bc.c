
int ASN1_BIT_STRING_get_bit(ASN1_BIT_STRING *a,int n)

{
  int iVar1;
  
  iVar1 = n + 7;
  if (-1 < n) {
    iVar1 = n;
  }
  if ((a != (ASN1_BIT_STRING *)0x0) && (iVar1 >> 3 < a->length)) {
    if (a->data != (uchar *)0x0) {
      return (uint)((1 << (~n & 7U) & (uint)a->data[iVar1 >> 3]) != 0);
    }
  }
  return 0;
}

