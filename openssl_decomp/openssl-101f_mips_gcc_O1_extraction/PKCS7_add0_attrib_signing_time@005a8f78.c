
int PKCS7_add0_attrib_signing_time(PKCS7_SIGNER_INFO *si,ASN1_TIME *t)

{
  int iVar1;
  
  if ((t == (ASN1_TIME *)0x0) &&
     (t = (ASN1_TIME *)(*(code *)PTR_X509_gmtime_adj_006a808c)(0), t == (ASN1_TIME *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x87,0x41,"pk7_attr.c",0x8f);
    return 0;
  }
  iVar1 = PKCS7_add_signed_attribute(si,0x34,0x17,t);
  return iVar1;
}

