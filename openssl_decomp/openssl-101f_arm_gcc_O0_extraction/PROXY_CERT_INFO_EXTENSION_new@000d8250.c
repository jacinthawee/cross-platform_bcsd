
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PROXY_CERT_INFO_EXTENSION * PROXY_CERT_INFO_EXTENSION_new(void)

{
  PROXY_CERT_INFO_EXTENSION *pPVar1;
  
  pPVar1 = (PROXY_CERT_INFO_EXTENSION *)
           ASN1_item_new((ASN1_ITEM *)PTR_PROXY_CERT_INFO_EXTENSION_it_000d8258);
  return pPVar1;
}

