
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

NETSCAPE_X509 * NETSCAPE_X509_new(void)

{
  NETSCAPE_X509 *pNVar1;
  
  pNVar1 = (NETSCAPE_X509 *)ASN1_item_new((ASN1_ITEM *)&NETSCAPE_X509_it);
  return pNVar1;
}

