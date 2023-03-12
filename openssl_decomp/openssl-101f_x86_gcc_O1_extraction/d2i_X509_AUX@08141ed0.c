
X509 * d2i_X509_AUX(X509 **a,uchar **pp,long length)

{
  uchar *puVar1;
  X509 *val;
  X509_CERT_AUX *pXVar2;
  X509 *pXVar3;
  
  puVar1 = *pp;
  val = (X509 *)ASN1_item_d2i((ASN1_VALUE **)a,pp,length,(ASN1_ITEM *)X509_it);
  pXVar3 = val;
  if ((val != (X509 *)0x0) && (puVar1 + (length - (int)*pp) != (uchar *)0x0)) {
    pXVar2 = d2i_X509_CERT_AUX((X509_CERT_AUX **)(val->sha1_hash + 0xc),pp,
                               (long)(puVar1 + (length - (int)*pp)));
    if (pXVar2 == (X509_CERT_AUX *)0x0) {
      pXVar3 = (X509 *)0x0;
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_it);
    }
  }
  return pXVar3;
}

