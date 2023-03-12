
int i2d_PUBKEY(EVP_PKEY *a,uchar **pp)

{
  ASN1_VALUE *val;
  int iVar1;
  code *pcVar2;
  
  if (a == (EVP_PKEY *)0x0) {
    return 0;
  }
  val = ASN1_item_new((ASN1_ITEM *)&X509_PUBKEY_it);
  if (val != (ASN1_VALUE *)0x0) {
    if (a->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
      ERR_put_error(0xb,0x78,0x6f,"x_pubkey.c",0x6f);
    }
    else {
      pcVar2 = *(code **)(a->ameth + 0x18);
      if (pcVar2 == (code *)0x0) {
        ERR_put_error(0xb,0x78,0x7c,"x_pubkey.c",0x6b);
      }
      else {
        iVar1 = (*pcVar2)(val,a);
        if (iVar1 != 0) {
          iVar1 = ASN1_item_i2d(val,pp,(ASN1_ITEM *)&X509_PUBKEY_it);
          ASN1_item_free(val,(ASN1_ITEM *)&X509_PUBKEY_it);
          return iVar1;
        }
        ERR_put_error(0xb,0x78,0x7e,"x_pubkey.c",0x67);
      }
    }
    ASN1_item_free(val,(ASN1_ITEM *)&X509_PUBKEY_it);
  }
  return 0;
}

