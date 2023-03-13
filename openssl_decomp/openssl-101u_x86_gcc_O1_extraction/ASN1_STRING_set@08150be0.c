
int ASN1_STRING_set(ASN1_STRING *str,void *data,int len)

{
  uchar *__dest;
  uchar *addr;
  
  if (len < 0) {
    if (data == (void *)0x0) {
      return 0;
    }
    len = strlen((char *)data);
  }
  if (len < str->length) {
    __dest = str->data;
    if (__dest != (uchar *)0x0) goto LAB_08150c28;
LAB_08150c5f:
    addr = (uchar *)0x0;
    __dest = (uchar *)CRYPTO_malloc(len + 1,"asn1_lib.c",0x178);
    str->data = __dest;
  }
  else {
    addr = str->data;
    if (addr == (uchar *)0x0) goto LAB_08150c5f;
    __dest = (uchar *)CRYPTO_realloc(addr,len + 1,"asn1_lib.c",0x17a);
    str->data = __dest;
  }
  if (__dest == (uchar *)0x0) {
    ERR_put_error(0xd,0xba,0x41,"asn1_lib.c",0x17d);
    str->data = addr;
    return 0;
  }
LAB_08150c28:
  str->length = len;
  if (data != (void *)0x0) {
    memcpy(__dest,data,len);
    str->data[len] = '\0';
  }
  return 1;
}

