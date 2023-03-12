
ASN1_STRING * ASN1_STRING_dup(ASN1_STRING *a)

{
  ASN1_STRING *pAVar1;
  uchar *puVar2;
  int iVar3;
  uchar *puVar4;
  
  if (a == (ASN1_STRING *)0x0) {
    return (ASN1_STRING *)0x0;
  }
  pAVar1 = (ASN1_STRING *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x10,"asn1_lib.c",0x1a9);
  if (pAVar1 == (ASN1_STRING *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x82,0x41,"asn1_lib.c",0x1ac);
    return (ASN1_STRING *)0x0;
  }
  pAVar1->length = 0;
  pAVar1->data = (uchar *)0x0;
  pAVar1->flags = 0;
  iVar3 = a->length;
  puVar4 = a->data;
  pAVar1->type = 4;
  pAVar1->type = a->type;
  if (iVar3 < 0) {
    if (puVar4 == (uchar *)0x0) goto LAB_0056b704;
    iVar3 = (*(code *)PTR_strlen_006aab30)(puVar4);
    puVar2 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3 + 1,"asn1_lib.c",0x182);
    pAVar1->data = puVar2;
    if (puVar2 != (uchar *)0x0) {
      pAVar1->length = iVar3;
      goto LAB_0056b650;
    }
  }
  else {
    puVar2 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3 + 1,"asn1_lib.c",0x182);
    pAVar1->data = puVar2;
    if (puVar2 != (uchar *)0x0) {
      pAVar1->length = iVar3;
      if (puVar4 == (uchar *)0x0) goto LAB_0056b670;
LAB_0056b650:
      (*(code *)PTR_memcpy_006aabf4)(puVar2,puVar4,iVar3);
      pAVar1->data[iVar3] = '\0';
LAB_0056b670:
      pAVar1->flags = a->flags;
      return pAVar1;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xba,0x41,"asn1_lib.c",0x188);
  pAVar1->data = (uchar *)0x0;
LAB_0056b704:
  (*(code *)PTR_CRYPTO_free_006a7f88)(pAVar1);
  return (ASN1_STRING *)0x0;
}

