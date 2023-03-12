
NETSCAPE_X509 * d2i_NETSCAPE_X509(NETSCAPE_X509 **a,uchar **in,long len)

{
  NETSCAPE_X509 *pNVar1;
  
  pNVar1 = (NETSCAPE_X509 *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&NETSCAPE_X509_it);
  return pNVar1;
}

