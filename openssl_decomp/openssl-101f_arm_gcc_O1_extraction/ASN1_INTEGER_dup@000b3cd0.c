
ASN1_STRING * ASN1_INTEGER_dup(ASN1_STRING *a)

{
  ASN1_STRING *ptr;
  uchar *__dest;
  int iVar1;
  size_t __n;
  uchar *__s;
  
  if (a == (ASN1_STRING *)0x0) {
    return (ASN1_STRING *)0x0;
  }
  ptr = (ASN1_STRING *)CRYPTO_malloc(0x10,"asn1_lib.c",0x1a9);
  if (ptr == (ASN1_STRING *)0x0) {
    ERR_put_error(0xd,0x82,0x41,"asn1_lib.c",0x1ac);
    return (ASN1_STRING *)0x0;
  }
  ptr->type = 4;
  iVar1 = a->type;
  ptr->length = 0;
  __n = a->length;
  ptr->data = (uchar *)0x0;
  ptr->type = iVar1;
  ptr->flags = 0;
  __s = a->data;
  if ((int)__n < 0) {
    if (__s == (uchar *)0x0) goto LAB_000c2344;
    __n = strlen((char *)__s);
  }
  __dest = (uchar *)CRYPTO_malloc(__n + 1,"asn1_lib.c",0x182);
  ptr->data = __dest;
  if (__dest != (uchar *)0x0) {
    ptr->length = __n;
    if (__s != (uchar *)0x0) {
      memcpy(__dest,__s,__n);
      ptr->data[__n] = '\0';
    }
    ptr->flags = a->flags;
    return ptr;
  }
  ERR_put_error(0xd,0xba,0x41,"asn1_lib.c",0x188);
  ptr->data = (uchar *)0x0;
LAB_000c2344:
  CRYPTO_free(ptr);
  return (ASN1_STRING *)0x0;
}

