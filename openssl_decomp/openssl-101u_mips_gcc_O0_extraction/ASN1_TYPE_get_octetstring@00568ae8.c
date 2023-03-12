
int ASN1_TYPE_get_octetstring(ASN1_TYPE *a,uchar *data,int max_len)

{
  ASN1_STRING *pAVar1;
  int iVar2;
  
  if ((a->type == 4) && (pAVar1 = (a->value).asn1_string, pAVar1 != (ASN1_STRING *)0x0)) {
    iVar2 = pAVar1->length;
    if (iVar2 <= max_len) {
      max_len = iVar2;
    }
    (*(code *)PTR_memcpy_006a9aec)(data,pAVar1->data,max_len);
  }
  else {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x87,0x6d,"evp_asn1.c",0x55);
    iVar2 = -1;
  }
  return iVar2;
}

