
PKCS12_SAFEBAG * PKCS12_x5092certbag(X509 *x509)

{
  PKCS12_SAFEBAG *pPVar1;
  
  pPVar1 = PKCS12_item_pack_safebag(x509,(ASN1_ITEM *)PTR_X509_it_006a8f9c,0x9e,0x98);
  return pPVar1;
}

