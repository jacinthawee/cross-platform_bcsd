
int CMS_stream(uchar ***boundary,CMS_ContentInfo *cms)

{
  ASN1_OCTET_STRING **ppAVar1;
  ASN1_OCTET_STRING *pAVar2;
  
  ppAVar1 = CMS_get0_content(cms);
  if (ppAVar1 == (ASN1_OCTET_STRING **)0x0) {
    return 0;
  }
  pAVar2 = *ppAVar1;
  if (pAVar2 == (ASN1_OCTET_STRING *)0x0) {
    pAVar2 = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_OCTET_STRING_new_006a978c)();
    *ppAVar1 = pAVar2;
    if (pAVar2 == (ASN1_OCTET_STRING *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x9b,0x41,"cms_io.c",0x4c);
      return 0;
    }
  }
  pAVar2->flags = pAVar2->flags & 0xffffffdfU | 0x10;
  *boundary = &pAVar2->data;
  return 1;
}

