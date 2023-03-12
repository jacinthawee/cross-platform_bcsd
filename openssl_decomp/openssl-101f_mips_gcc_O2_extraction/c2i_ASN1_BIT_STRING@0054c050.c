
ASN1_BIT_STRING * c2i_ASN1_BIT_STRING(ASN1_BIT_STRING **a,uchar **pp,long length)

{
  uchar *puVar1;
  ASN1_STRING *a_00;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  
  if (length < 1) {
    ERR_put_error(0xd,0xbd,0x98,"a_bitstr.c",0xa8);
    return (ASN1_BIT_STRING *)0x0;
  }
  if (((a == (ASN1_BIT_STRING **)0x0) || (a_00 = *a, a_00 == (ASN1_BIT_STRING *)0x0)) &&
     (a_00 = ASN1_STRING_type_new(3), a_00 == (ASN1_STRING *)0x0)) {
    return (ASN1_BIT_STRING *)0x0;
  }
  iVar3 = length + -1;
  pbVar2 = *pp + 1;
  uVar4 = (uint)**pp;
  a_00->flags = a_00->flags & 0xfffffff0U | uVar4 & 7 | 8;
  if (length == 1) {
    puVar1 = (uchar *)0x0;
  }
  else {
    puVar1 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3,"a_bitstr.c",0x93);
    if (puVar1 == (uchar *)0x0) {
      ERR_put_error(0xd,0xbd,0x41,"a_bitstr.c",0xa8);
      if ((a != (ASN1_BIT_STRING **)0x0) && (a_00 == *a)) {
        return (ASN1_BIT_STRING *)0x0;
      }
      ASN1_STRING_free(a_00);
      return (ASN1_BIT_STRING *)0x0;
    }
    (*(code *)PTR_memcpy_006aabf4)(puVar1,pbVar2,iVar3);
    pbVar2 = pbVar2 + iVar3;
    puVar1[length + -2] = (byte)(0xff << (uVar4 & 0x1f)) & puVar1[length + -2];
  }
  a_00->length = iVar3;
  if (a_00->data != (uchar *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  a_00->data = puVar1;
  a_00->type = 3;
  if (a != (ASN1_BIT_STRING **)0x0) {
    *a = a_00;
  }
  *pp = pbVar2;
  return a_00;
}

