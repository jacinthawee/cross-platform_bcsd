
ASN1_STRING * ASN1_OCTET_STRING_dup(ASN1_STRING *a)

{
  uchar *__s;
  ASN1_STRING *ptr;
  uchar *__dest;
  size_t __n;
  
  if (a == (ASN1_STRING *)0x0) {
    return (ASN1_STRING *)0x0;
  }
  ptr = (ASN1_STRING *)CRYPTO_malloc(0x10,"asn1_lib.c",0x1a9);
  if (ptr == (ASN1_STRING *)0x0) {
    ERR_put_error(0xd,0x82,0x41,"asn1_lib.c",0x1ac);
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
    if (__s == (uchar *)0x0) goto LAB_081531ad;
    __n = strlen((char *)__s);
    __dest = (uchar *)CRYPTO_malloc(__n + 1,"asn1_lib.c",0x182);
    ptr->data = __dest;
    if (__dest != (uchar *)0x0) {
      ptr->length = __n;
      goto LAB_08153124;
    }
  }
  else {
    __dest = (uchar *)CRYPTO_malloc(__n + 1,"asn1_lib.c",0x182);
    ptr->data = __dest;
    if (__dest != (uchar *)0x0) {
      ptr->length = __n;
      if (__s == (uchar *)0x0) goto LAB_08153139;
LAB_08153124:
      memcpy(__dest,__s,__n);
      ptr->data[__n] = '\0';
LAB_08153139:
      ptr->flags = a->flags;
      return ptr;
    }
  }
  ERR_put_error(0xd,0xba,0x41,"asn1_lib.c",0x188);
  ptr->data = (uchar *)0x0;
LAB_081531ad:
  CRYPTO_free(ptr);
  return (ASN1_STRING *)0x0;
}

