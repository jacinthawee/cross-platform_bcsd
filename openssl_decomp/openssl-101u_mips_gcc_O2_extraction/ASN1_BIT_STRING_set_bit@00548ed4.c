
int ASN1_BIT_STRING_set_bit(ASN1_BIT_STRING *a,int n,int value)

{
  uchar *puVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  
  iVar3 = n + 7;
  if (-1 < n) {
    iVar3 = n;
  }
  bVar2 = (byte)(1 << (~n & 7U));
  bVar4 = bVar2;
  if (value == 0) {
    bVar4 = 0;
  }
  if (a == (ASN1_BIT_STRING *)0x0) {
    return 0;
  }
  iVar3 = iVar3 >> 3;
  a->flags = a->flags & 0xfffffff0;
  if (iVar3 < a->length) {
    puVar1 = a->data;
    if (puVar1 != (uchar *)0x0) goto LAB_00548f5c;
    if (value == 0) {
      return 1;
    }
LAB_00549070:
    puVar1 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3 + 1,"a_bitstr.c",0xd0);
  }
  else {
    if (value == 0) {
      return 1;
    }
    if (a->data == (uchar *)0x0) goto LAB_00549070;
    puVar1 = (uchar *)(*(code *)PTR_CRYPTO_realloc_clean_006a88e0)
                                (a->data,a->length,iVar3 + 1,"a_bitstr.c",0xd3);
  }
  if (puVar1 == (uchar *)0x0) {
    ERR_put_error(0xd,0xb7,0x41,"a_bitstr.c",0xd5);
    return 0;
  }
  if (0 < (iVar3 + 1) - a->length) {
    (*(code *)PTR_memset_006a99f4)(puVar1 + a->length,0);
  }
  a->data = puVar1;
  a->length = iVar3 + 1;
LAB_00548f5c:
  puVar1[iVar3] = ~bVar2 & puVar1[iVar3] | bVar4;
  iVar3 = a->length;
  if (0 < iVar3) {
    puVar1 = a->data + iVar3;
    do {
      iVar3 = iVar3 + -1;
      if (puVar1[-1] != '\0') {
        return 1;
      }
      puVar1 = puVar1 + -1;
      a->length = iVar3;
    } while (iVar3 != 0);
  }
  return 1;
}

