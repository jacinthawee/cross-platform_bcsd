
PKCS12_SAFEBAG * PKCS12_x509crl2certbag(X509_CRL *crl)

{
  PKCS12_SAFEBAG *pPVar1;
  
  pPVar1 = PKCS12_item_pack_safebag(crl,(ASN1_ITEM *)PTR_X509_CRL_it_006a8fa4,0xa0,0x99);
  return pPVar1;
}

