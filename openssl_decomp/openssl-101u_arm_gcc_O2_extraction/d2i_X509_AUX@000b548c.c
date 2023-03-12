
X509 * d2i_X509_AUX(X509 **a,uchar **pp,long length)

{
  X509 *val;
  X509_CERT_AUX *pXVar1;
  uint uVar2;
  uchar *local_1c;
  
  local_1c = *pp;
  uVar2 = 1;
  if (a != (X509 **)0x0) {
    uVar2 = count_leading_zeroes(*a);
    uVar2 = uVar2 >> 5;
  }
  val = (X509 *)ASN1_item_d2i((ASN1_VALUE **)a,&local_1c,length,(ASN1_ITEM *)PTR_X509_it_000b54fc);
  if (val != (X509 *)0x0) {
    if (((int)(*pp + (length - (int)local_1c)) < 1) ||
       (pXVar1 = d2i_X509_CERT_AUX((X509_CERT_AUX **)(val->sha1_hash + 0xc),&local_1c,
                                   (long)(*pp + (length - (int)local_1c))),
       pXVar1 != (X509_CERT_AUX *)0x0)) {
      *pp = local_1c;
      return val;
    }
    if ((uVar2 != 0) &&
       (ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_X509_it_000b54fc), a != (X509 **)0x0)) {
      *a = (X509 *)0x0;
      return (X509 *)0x0;
    }
  }
  return (X509 *)0x0;
}

