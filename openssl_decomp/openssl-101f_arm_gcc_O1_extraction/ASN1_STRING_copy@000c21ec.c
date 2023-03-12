
int ASN1_STRING_copy(ASN1_STRING *dst,ASN1_STRING *str)

{
  uchar *__dest;
  size_t __n;
  uchar *__s;
  uchar *addr;
  
  if (str == (ASN1_STRING *)0x0) {
    return 0;
  }
  __n = str->length;
  __s = str->data;
  dst->type = str->type;
  if ((int)__n < 0) {
    if (__s == (uchar *)0x0) {
      return 0;
    }
    __n = strlen((char *)__s);
  }
  if (dst->length < (int)__n) {
    addr = dst->data;
    if (addr == (uchar *)0x0) goto LAB_000c228a;
    __dest = (uchar *)CRYPTO_realloc(addr,__n + 1,"asn1_lib.c",0x184);
    dst->data = __dest;
  }
  else {
    __dest = dst->data;
    if (__dest != (uchar *)0x0) goto LAB_000c2212;
LAB_000c228a:
    __dest = (uchar *)CRYPTO_malloc(__n + 1,"asn1_lib.c",0x182);
    addr = (uchar *)0x0;
    dst->data = __dest;
  }
  if (__dest == (uchar *)0x0) {
    ERR_put_error(0xd,0xba,0x41,"asn1_lib.c",0x188);
    dst->data = addr;
    return 0;
  }
LAB_000c2212:
  dst->length = __n;
  if (__s != (uchar *)0x0) {
    memcpy(__dest,__s,__n);
    dst->data[__n] = '\0';
  }
  dst->flags = str->flags;
  return 1;
}

