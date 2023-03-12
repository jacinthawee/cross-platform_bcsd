
X509 * d2i_X509_AUX(X509 **a,uchar **pp,long length)

{
  X509 *val;
  X509_CERT_AUX *pXVar1;
  int len;
  uchar *puVar2;
  
  puVar2 = *pp;
  val = (X509 *)ASN1_item_d2i((ASN1_VALUE **)a,pp,length,(ASN1_ITEM *)X509_it);
  if (((val != (X509 *)0x0) && (len = length - ((int)*pp - (int)puVar2), len != 0)) &&
     (pXVar1 = d2i_X509_CERT_AUX((X509_CERT_AUX **)(val->sha1_hash + 0xc),pp,len),
     pXVar1 == (X509_CERT_AUX *)0x0)) {
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_it);
    val = (X509 *)0x0;
  }
  return val;
}

