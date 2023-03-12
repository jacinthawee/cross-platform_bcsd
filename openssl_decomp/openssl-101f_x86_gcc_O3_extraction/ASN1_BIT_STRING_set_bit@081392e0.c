
int ASN1_BIT_STRING_set_bit(ASN1_BIT_STRING *a,int n,int value)

{
  uchar *puVar1;
  size_t __n;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int local_24;
  
  iVar4 = n + 7;
  if (-1 < n) {
    iVar4 = n;
  }
  iVar4 = iVar4 >> 3;
  bVar3 = (byte)(1 << (~(byte)n & 7));
  bVar2 = 0;
  if (value != 0) {
    bVar2 = bVar3;
  }
  if (a == (ASN1_BIT_STRING *)0x0) {
    return 0;
  }
  a->flags = a->flags & 0xfffffff0;
  if (iVar4 < a->length) {
    puVar1 = a->data;
    if (puVar1 != (uchar *)0x0) goto LAB_081393a7;
    if (value == 0) {
      return 1;
    }
LAB_081393ee:
    puVar1 = (uchar *)CRYPTO_malloc(iVar4 + 1,"a_bitstr.c",0xc3);
  }
  else {
    if (value == 0) {
      return 1;
    }
    if (a->data == (uchar *)0x0) goto LAB_081393ee;
    puVar1 = (uchar *)CRYPTO_realloc_clean(a->data,a->length,iVar4 + 1,"a_bitstr.c",199);
  }
  local_24 = iVar4 + 1;
  if (puVar1 == (uchar *)0x0) {
    ERR_put_error(0xd,0xb7,0x41,"a_bitstr.c",0xca);
    return 0;
  }
  __n = local_24 - a->length;
  if (0 < (int)__n) {
    memset(puVar1 + a->length,0,__n);
  }
  a->data = puVar1;
  a->length = local_24;
LAB_081393a7:
  puVar1[iVar4] = bVar2 | ~bVar3 & puVar1[iVar4];
  iVar4 = a->length;
  if (0 < iVar4) {
    do {
      if (a->data[iVar4 + -1] != '\0') {
        return 1;
      }
      iVar4 = iVar4 + -1;
      a->length = iVar4;
    } while (iVar4 != 0);
  }
  return 1;
}

