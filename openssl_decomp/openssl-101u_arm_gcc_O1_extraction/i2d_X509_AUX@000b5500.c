
int i2d_X509_AUX(X509 *a,uchar **pp)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uchar **ppuVar4;
  
  ppuVar4 = pp;
  if (pp != (uchar **)0x0) {
    ppuVar4 = (uchar **)*pp;
  }
  uVar1 = ASN1_item_i2d((ASN1_VALUE *)a,pp,(ASN1_ITEM *)PTR_X509_it_000b5544);
  uVar3 = count_leading_zeroes(a);
  uVar2 = uVar1;
  if ((uVar3 >> 5 | uVar1 >> 0x1f) == 0) {
    uVar2 = i2d_X509_CERT_AUX(*(X509_CERT_AUX **)(a->sha1_hash + 0xc),pp);
    if ((int)uVar2 < 0) {
      if (ppuVar4 != (uchar **)0x0) {
        *pp = (uchar *)ppuVar4;
      }
    }
    else {
      uVar2 = uVar1 + uVar2;
    }
  }
  return uVar2;
}

