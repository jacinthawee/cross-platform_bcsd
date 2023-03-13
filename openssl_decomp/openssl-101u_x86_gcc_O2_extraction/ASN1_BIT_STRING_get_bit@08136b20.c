
int ASN1_BIT_STRING_get_bit(ASN1_BIT_STRING *a,int n)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = n + 7;
  if (-1 < n) {
    iVar2 = n;
  }
  uVar1 = 0;
  if (((a != (ASN1_BIT_STRING *)0x0) && (iVar2 >> 3 < a->length)) && (a->data != (uchar *)0x0)) {
    uVar1 = (uint)((1 << (~(byte)n & 7) & (uint)a->data[iVar2 >> 3]) != 0);
  }
  return uVar1;
}

