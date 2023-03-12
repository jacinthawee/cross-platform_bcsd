
ASN1_BIT_STRING * c2i_ASN1_BIT_STRING(ASN1_BIT_STRING **a,uchar **pp,long length)

{
  uchar *__dest;
  ASN1_STRING *a_00;
  size_t __n;
  byte *__src;
  uint uVar1;
  
  if (length < 1) {
    ERR_put_error(0xd,0xbd,0x98,"a_bitstr.c",0xa8);
  }
  else if (((a != (ASN1_BIT_STRING **)0x0) && (a_00 = *a, a_00 != (ASN1_BIT_STRING *)0x0)) ||
          (a_00 = ASN1_STRING_type_new(3), a_00 != (ASN1_STRING *)0x0)) {
    __n = length - 1;
    __src = *pp + 1;
    uVar1 = (uint)**pp;
    a_00->flags = a_00->flags & 0xfffffff0U | uVar1 & 7 | 8;
    if (length == 1) {
      __dest = (uchar *)0x0;
    }
    else {
      __dest = (uchar *)CRYPTO_malloc(__n,"a_bitstr.c",0x93);
      if (__dest == (uchar *)0x0) {
        ERR_put_error(0xd,0xbd,0x41,"a_bitstr.c",0xa8);
        if ((a != (ASN1_BIT_STRING **)0x0) && (a_00 == *a)) {
          return (ASN1_BIT_STRING *)0x0;
        }
        ASN1_STRING_free(a_00);
        return (ASN1_BIT_STRING *)0x0;
      }
      memcpy(__dest,__src,__n);
      __src = __src + __n;
      __dest[length + -2] = __dest[length + -2] & (byte)(0xff << uVar1);
    }
    a_00->length = __n;
    if (a_00->data != (uchar *)0x0) {
      CRYPTO_free(a_00->data);
    }
    a_00->data = __dest;
    a_00->type = 3;
    if (a != (ASN1_BIT_STRING **)0x0) {
      *a = a_00;
    }
    *pp = __src;
    return a_00;
  }
  return (ASN1_BIT_STRING *)0x0;
}

