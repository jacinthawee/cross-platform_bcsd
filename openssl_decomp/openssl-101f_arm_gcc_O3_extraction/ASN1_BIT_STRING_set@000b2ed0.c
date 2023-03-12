
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
  if (str->length < len) {
    addr = str->data;
    if (addr == (uchar *)0x0) goto LAB_000c23f8;
    puVar1 = (uchar *)CRYPTO_realloc(addr,len + 1,"asn1_lib.c",0x184);
    str->data = puVar1;
    __dest = puVar1;
    if (puVar1 != (uchar *)0x0) goto LAB_000c2386;
LAB_000c23ca:
    ERR_put_error(0xd,0xba,0x41,"asn1_lib.c",0x188);
    str->data = addr;
  }
  else {
    __dest = str->data;
    if (str->data == (uchar *)0x0) {
LAB_000c23f8:
      puVar1 = (uchar *)CRYPTO_malloc(len + 1,"asn1_lib.c",0x182);
      addr = (uchar *)0x0;
      str->data = puVar1;
      __dest = puVar1;
      if (puVar1 == (uchar *)0x0) goto LAB_000c23ca;
    }
LAB_000c2386:
    str->length = len;
    puVar1 = (uchar *)0x1;
    if (data != (void *)0x0) {
      memcpy(__dest,data,len);
      puVar1 = (uchar *)0x1;
      str->data[len] = '\0';
    }
  }
  return (int)puVar1;
}

