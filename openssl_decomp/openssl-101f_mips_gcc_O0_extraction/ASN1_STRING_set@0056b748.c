
int ASN1_STRING_set(ASN1_STRING *str,void *data,int len)

{
  int iVar1;
  uchar *puVar2;
  uchar *puVar3;
  
  if (len < 0) {
    if (data == (void *)0x0) {
      return 0;
    }
    len = (*(code *)PTR_strlen_006aab30)(data);
  }
  if (str->length < len) {
    puVar3 = str->data;
    if (puVar3 == (uchar *)0x0) goto LAB_0056b884;
    puVar2 = (uchar *)(*(code *)PTR_CRYPTO_realloc_006a8c44)(puVar3,len + 1,"asn1_lib.c",0x184);
    str->data = puVar2;
    if (puVar2 != (uchar *)0x0) goto LAB_0056b79c;
LAB_0056b81c:
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xba,0x41,"asn1_lib.c",0x188);
    iVar1 = 0;
    str->data = puVar3;
  }
  else {
    puVar2 = str->data;
    if (puVar2 == (uchar *)0x0) {
LAB_0056b884:
      puVar3 = (uchar *)0x0;
      puVar2 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(len + 1,"asn1_lib.c",0x182);
      str->data = puVar2;
      if (puVar2 == (uchar *)0x0) goto LAB_0056b81c;
    }
LAB_0056b79c:
    str->length = len;
    if (data == (void *)0x0) {
      return 1;
    }
    (*(code *)PTR_memcpy_006aabf4)(puVar2,data,len);
    iVar1 = 1;
    str->data[len] = '\0';
  }
  return iVar1;
}

