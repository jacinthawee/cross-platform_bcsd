
int ASN1_STRING_copy(ASN1_STRING *dst,ASN1_STRING *str)

{
  uchar *puVar1;
  int iVar2;
  uchar *puVar3;
  uchar *puVar4;
  
  if (str == (ASN1_STRING *)0x0) {
    return 0;
  }
  iVar2 = str->length;
  puVar3 = str->data;
  dst->type = str->type;
  if (iVar2 < 0) {
    if (puVar3 != (uchar *)0x0) {
      iVar2 = (*(code *)PTR_strlen_006a9a24)(puVar3);
      goto LAB_00567abc;
    }
LAB_00567b84:
    iVar2 = 0;
  }
  else {
LAB_00567abc:
    if (iVar2 < dst->length) {
      puVar1 = dst->data;
      if (puVar1 == (uchar *)0x0) goto LAB_00567bb0;
    }
    else {
      puVar4 = dst->data;
      if (puVar4 == (uchar *)0x0) {
LAB_00567bb0:
        puVar4 = (uchar *)0x0;
        puVar1 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2 + 1,"asn1_lib.c",0x178);
        dst->data = puVar1;
      }
      else {
        puVar1 = (uchar *)(*(code *)PTR_CRYPTO_realloc_006a7b58)
                                    (puVar4,iVar2 + 1,"asn1_lib.c",0x17a);
        dst->data = puVar1;
      }
      if (puVar1 == (uchar *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xba,0x41,"asn1_lib.c",0x17d);
        dst->data = puVar4;
        goto LAB_00567b84;
      }
    }
    dst->length = iVar2;
    if (puVar3 != (uchar *)0x0) {
      (*(code *)PTR_memcpy_006a9aec)(puVar1,puVar3,iVar2);
      dst->data[iVar2] = '\0';
    }
    iVar2 = 1;
    dst->flags = str->flags;
  }
  return iVar2;
}

