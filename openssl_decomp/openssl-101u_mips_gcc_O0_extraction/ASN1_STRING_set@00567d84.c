
int ASN1_STRING_set(ASN1_STRING *str,void *data,int len)

{
  int iVar1;
  uchar *puVar2;
  uchar *puVar3;
  
  if (len < 0) {
    if (data == (void *)0x0) {
      return 0;
    }
    len = (*(code *)PTR_strlen_006a9a24)(data);
  }
  if (len < str->length) {
    puVar2 = str->data;
    if (puVar2 == (uchar *)0x0) {
LAB_00567ec0:
      puVar3 = (uchar *)0x0;
      puVar2 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(len + 1,"asn1_lib.c",0x178);
      str->data = puVar2;
      if (puVar2 == (uchar *)0x0) goto LAB_00567e58;
    }
LAB_00567dd8:
    str->length = len;
    if (data == (void *)0x0) {
      return 1;
    }
    (*(code *)PTR_memcpy_006a9aec)(puVar2,data,len);
    iVar1 = 1;
    str->data[len] = '\0';
  }
  else {
    puVar3 = str->data;
    if (puVar3 == (uchar *)0x0) goto LAB_00567ec0;
    puVar2 = (uchar *)(*(code *)PTR_CRYPTO_realloc_006a7b58)(puVar3,len + 1,"asn1_lib.c",0x17a);
    str->data = puVar2;
    if (puVar2 != (uchar *)0x0) goto LAB_00567dd8;
LAB_00567e58:
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xba,0x41,"asn1_lib.c",0x17d);
    iVar1 = 0;
    str->data = puVar3;
  }
  return iVar1;
}

