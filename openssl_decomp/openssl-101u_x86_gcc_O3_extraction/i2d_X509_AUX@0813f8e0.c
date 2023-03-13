
int i2d_X509_AUX(X509 *a,uchar **pp)

{
  int iVar1;
  int iVar2;
  uchar *puVar3;
  
  if (pp == (uchar **)0x0) {
    puVar3 = (uchar *)0x0;
  }
  else {
    puVar3 = *pp;
  }
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,pp,(ASN1_ITEM *)X509_it);
  if ((-1 < iVar1) && (a != (X509 *)0x0)) {
    iVar2 = i2d_X509_CERT_AUX(*(X509_CERT_AUX **)(a->sha1_hash + 0xc),pp);
    iVar1 = iVar1 + iVar2;
    if ((iVar2 < 0) && (iVar1 = iVar2, puVar3 != (uchar *)0x0)) {
      *pp = puVar3;
    }
  }
  return iVar1;
}

