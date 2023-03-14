
int i2d_EC_PUBKEY(EC_KEY *a,uchar **pp)

{
  code *pcVar1;
  EVP_PKEY *pkey;
  ASN1_VALUE *val;
  int iVar2;
  
  if (a == (EC_KEY *)0x0) {
    return 0;
  }
  pkey = EVP_PKEY_new();
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0xd,0xb5,0x41,"x_pubkey.c",0x14d);
    return 0;
  }
  EVP_PKEY_set1_EC_KEY(pkey,a);
  val = ASN1_item_new((ASN1_ITEM *)X509_PUBKEY_it);
  if (val != (ASN1_VALUE *)0x0) {
    if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
      ERR_put_error(0xb,0x78,0x6f,"x_pubkey.c",0x6f);
    }
    else {
      pcVar1 = *(code **)(pkey->ameth + 0x18);
      if (pcVar1 == (code *)0x0) {
        ERR_put_error(0xb,0x78,0x7c,"x_pubkey.c",0x6b);
      }
      else {
        iVar2 = (*pcVar1)(val,pkey);
        if (iVar2 != 0) {
          iVar2 = ASN1_item_i2d(val,pp,(ASN1_ITEM *)X509_PUBKEY_it);
          ASN1_item_free(val,(ASN1_ITEM *)X509_PUBKEY_it);
          goto LAB_0813e10b;
        }
        ERR_put_error(0xb,0x78,0x7e,"x_pubkey.c",0x67);
      }
    }
    ASN1_item_free(val,(ASN1_ITEM *)X509_PUBKEY_it);
  }
  iVar2 = 0;
LAB_0813e10b:
  EVP_PKEY_free(pkey);
  return iVar2;
}
