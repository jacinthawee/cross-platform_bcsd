
int i2d_RSA_PUBKEY(RSA *a,uchar **pp)

{
  code *pcVar1;
  EVP_PKEY *pkey;
  ASN1_VALUE *val;
  int iVar2;
  
  if (a == (RSA *)0x0) {
    return 0;
  }
  pkey = EVP_PKEY_new();
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0xd,0xa5,0x41,"x_pubkey.c",0x107);
    return 0;
  }
  EVP_PKEY_set1_RSA(pkey,a);
  val = ASN1_item_new((ASN1_ITEM *)X509_PUBKEY_it);
  if (val != (ASN1_VALUE *)0x0) {
    if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
      ERR_put_error(0xb,0x78,0x6f,"x_pubkey.c",0x76);
    }
    else {
      pcVar1 = *(code **)(pkey->ameth + 0x18);
      if (pcVar1 == (code *)0x0) {
        ERR_put_error(0xb,0x78,0x7c,"x_pubkey.c",0x70);
      }
      else {
        iVar2 = (*pcVar1)(val,pkey);
        if (iVar2 != 0) {
          iVar2 = ASN1_item_i2d(val,pp,(ASN1_ITEM *)X509_PUBKEY_it);
          ASN1_item_free(val,(ASN1_ITEM *)X509_PUBKEY_it);
          goto LAB_081400ab;
        }
        ERR_put_error(0xb,0x78,0x7e,"x_pubkey.c",0x69);
      }
    }
    ASN1_item_free(val,(ASN1_ITEM *)X509_PUBKEY_it);
  }
  iVar2 = 0;
LAB_081400ab:
  EVP_PKEY_free(pkey);
  return iVar2;
}

