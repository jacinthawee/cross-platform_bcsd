
ASN1_STRING * ASN1_INTEGER_dup(ASN1_STRING *a)

{
  uchar *__s;
  ASN1_STRING *ptr;
  uchar *__dest;
  size_t __n;
  
  if (a == (ASN1_STRING *)0x0) {
    return (ASN1_STRING *)0x0;
  }
  ptr = (ASN1_STRING *)CRYPTO_malloc(0x10,"asn1_lib.c",0x19c);
  if (ptr == (ASN1_STRING *)0x0) {
    ERR_put_error(0xd,0x82,0x41,"asn1_lib.c",0x19e);
    return (ASN1_STRING *)0x0;
  }
  ptr->length = 0;
  __n = a->length;
  ptr->data = (uchar *)0x0;
  ptr->type = 4;
  ptr->flags = 0;
  __s = a->data;
  ptr->type = a->type;
  if ((int)__n < 0) {
    if (__s == (uchar *)0x0) goto LAB_08150b9d;
    __n = strlen((char *)__s);
    __dest = (uchar *)CRYPTO_malloc(__n + 1,"asn1_lib.c",0x178);
    ptr->data = __dest;
    if (__dest != (uchar *)0x0) {
      ptr->length = __n;
      goto LAB_08150b14;
    }
  }
  else {
    __dest = (uchar *)CRYPTO_malloc(__n + 1,"asn1_lib.c",0x178);
    ptr->data = __dest;
    if (__dest != (uchar *)0x0) {
      ptr->length = __n;
      if (__s == (uchar *)0x0) goto LAB_08150b29;
LAB_08150b14:
      memcpy(__dest,__s,__n);
      ptr->data[__n] = '\0';
LAB_08150b29:
      ptr->flags = a->flags;
      return ptr;
    }
  }
  ERR_put_error(0xd,0xba,0x41,"asn1_lib.c",0x17d);
  ptr->data = (uchar *)0x0;
LAB_08150b9d:
  CRYPTO_free(ptr);
  return (ASN1_STRING *)0x0;
}

