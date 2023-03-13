
int i2d_DSA_PUBKEY_bio(BIO *bp,DSA *dsa)

{
  int iVar1;
  
  iVar1 = ASN1_i2d_bio(i2d_DSA_PUBKEY,bp,(uchar *)dsa);
  return iVar1;
}

