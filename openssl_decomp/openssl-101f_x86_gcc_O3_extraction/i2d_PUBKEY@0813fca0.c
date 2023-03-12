
int i2d_PUBKEY(EVP_PKEY *a,uchar **pp)

{
  code *pcVar1;
  ASN1_VALUE *val;
  int iVar2;
  
  if (a != (EVP_PKEY *)0x0) {
    val = ASN1_item_new((ASN1_ITEM *)X509_PUBKEY_it);
    if (val != (ASN1_VALUE *)0x0) {
      if (a->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
        ERR_put_error(0xb,0x78,0x6f,"x_pubkey.c",0x76);
      }
      else {
        pcVar1 = *(code **)(a->ameth + 0x18);
        if (pcVar1 == (code *)0x0) {
          ERR_put_error(0xb,0x78,0x7c,"x_pubkey.c",0x70);
        }
        else {
          iVar2 = (*pcVar1)(val,a);
          if (iVar2 != 0) {
            iVar2 = ASN1_item_i2d(val,pp,(ASN1_ITEM *)X509_PUBKEY_it);
            ASN1_item_free(val,(ASN1_ITEM *)X509_PUBKEY_it);
            return iVar2;
          }
          ERR_put_error(0xb,0x78,0x7e,"x_pubkey.c",0x69);
        }
      }
      ASN1_item_free(val,(ASN1_ITEM *)X509_PUBKEY_it);
    }
  }
  return 0;
}

