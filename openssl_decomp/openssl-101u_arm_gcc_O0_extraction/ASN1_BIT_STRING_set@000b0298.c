
int ASN1_BIT_STRING_set(ASN1_STRING *str,void *data,int len)

{
  uchar *puVar1;
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
    if (str->data == (uchar *)0x0) {
LAB_000bfda8:
      puVar1 = (uchar *)CRYPTO_malloc(len + 1,"asn1_lib.c",0x178);
      addr = (uchar *)0x0;
      str->data = puVar1;
      __dest = puVar1;
      if (puVar1 == (uchar *)0x0) goto LAB_000bfd7a;
    }
LAB_000bfd36:
    str->length = len;
    puVar1 = (uchar *)0x1;
    if (data != (void *)0x0) {
      memcpy(__dest,data,len);
      puVar1 = (uchar *)0x1;
      str->data[len] = '\0';
    }
  }
  else {
    addr = str->data;
    if (addr == (uchar *)0x0) goto LAB_000bfda8;
    puVar1 = (uchar *)CRYPTO_realloc(addr,len + 1,"asn1_lib.c",0x17a);
    str->data = puVar1;
    __dest = puVar1;
    if (puVar1 != (uchar *)0x0) goto LAB_000bfd36;
LAB_000bfd7a:
    ERR_put_error(0xd,0xba,0x41,"asn1_lib.c",0x17d);
    str->data = addr;
  }
  return (int)puVar1;
}

