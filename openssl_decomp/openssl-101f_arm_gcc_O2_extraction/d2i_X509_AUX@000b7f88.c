
X509 * d2i_X509_AUX(X509 **a,uchar **pp,long length)

{
  X509 *val;
  X509 *pXVar1;
  uchar *puVar2;
  
  puVar2 = *pp;
  val = (X509 *)ASN1_item_d2i((ASN1_VALUE **)a,pp,length,(ASN1_ITEM *)PTR_X509_it_000b7fc0);
  if (((val != (X509 *)0x0) && (puVar2 + (length - (int)*pp) != (uchar *)0x0)) &&
     (pXVar1 = (X509 *)d2i_X509_CERT_AUX((X509_CERT_AUX **)(val->sha1_hash + 0xc),pp,
                                         (long)(puVar2 + (length - (int)*pp))),
     pXVar1 == (X509 *)0x0)) {
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_X509_it_000b7fc0);
    val = pXVar1;
  }
  return val;
}

