
int PKCS7_add1_attrib_digest(PKCS7_SIGNER_INFO *si,uchar *md,int mdlen)

{
  void *data;
  int iVar1;
  
  data = (void *)(*(code *)PTR_ASN1_OCTET_STRING_new_006a8668)();
  if (data == (void *)0x0) {
    return 0;
  }
  iVar1 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(data,md,mdlen);
  if (iVar1 != 0) {
    iVar1 = PKCS7_add_signed_attribute(si,0x33,4,data);
    if (iVar1 != 0) {
      return 1;
    }
  }
  (*(code *)PTR_ASN1_OCTET_STRING_free_006a8cfc)(data);
  return 0;
}

