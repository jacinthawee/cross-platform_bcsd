
ASN1_BIT_STRING * c2i_ASN1_BIT_STRING(ASN1_BIT_STRING **a,uchar **pp,long length)

{
  size_t __n;
  uchar *__dest;
  int reason;
  ASN1_BIT_STRING *a_00;
  uint uVar1;
  byte *pbVar2;
  
  if (length < 1) {
    ERR_put_error(0xd,0xbd,0x98,"a_bitstr.c",0xb3);
    return (ASN1_BIT_STRING *)0x0;
  }
  if ((a == (ASN1_BIT_STRING **)0x0) || (a_00 = *a, a_00 == (ASN1_BIT_STRING *)0x0)) {
    a_00 = ASN1_STRING_type_new(3);
    if (a_00 == (ASN1_STRING *)0x0) {
      return (ASN1_BIT_STRING *)0x0;
    }
    pbVar2 = *pp;
    uVar1 = (uint)*pbVar2;
    if (uVar1 < 8) goto LAB_08136868;
    reason = 0xdc;
LAB_08136925:
    ERR_put_error(0xd,0xbd,reason,"a_bitstr.c",0xb3);
    if (a == (ASN1_BIT_STRING **)0x0) goto LAB_0813684e;
  }
  else {
    pbVar2 = *pp;
    uVar1 = (uint)*pbVar2;
    if (uVar1 < 8) {
LAB_08136868:
      pbVar2 = pbVar2 + 1;
      a_00->flags = uVar1 | 8 | a_00->flags & 0xfffffff0U;
      __n = length - 1;
      if (length == 1) {
        __dest = (uchar *)0x0;
LAB_081368e2:
        a_00->length = __n;
        if (a_00->data != (uchar *)0x0) {
          CRYPTO_free(a_00->data);
        }
        a_00->data = __dest;
        a_00->type = 3;
        if (a != (ASN1_BIT_STRING **)0x0) {
          *a = a_00;
        }
        *pp = pbVar2;
        return a_00;
      }
      __dest = (uchar *)CRYPTO_malloc(__n,"a_bitstr.c",0x9e);
      if (__dest != (uchar *)0x0) {
        memcpy(__dest,pbVar2,__n);
        pbVar2 = pbVar2 + __n;
        __dest[length + -2] = __dest[length + -2] & (byte)(0xff << ((byte)uVar1 & 0x1f));
        goto LAB_081368e2;
      }
      reason = 0x41;
      goto LAB_08136925;
    }
    ERR_put_error(0xd,0xbd,0xdc,"a_bitstr.c",0xb3);
  }
  if (*a == a_00) {
    return (ASN1_BIT_STRING *)0x0;
  }
LAB_0813684e:
  ASN1_STRING_free(a_00);
  return (ASN1_BIT_STRING *)0x0;
}

