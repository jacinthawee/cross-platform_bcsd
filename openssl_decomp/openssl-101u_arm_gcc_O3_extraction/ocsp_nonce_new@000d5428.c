
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_OCTET_STRING * ocsp_nonce_new(void)

{
  ASN1_OCTET_STRING *pAVar1;
  
  pAVar1 = (ASN1_OCTET_STRING *)ASN1_item_new((ASN1_ITEM *)PTR_ASN1_OCTET_STRING_it_000bce38);
  return pAVar1;
}

