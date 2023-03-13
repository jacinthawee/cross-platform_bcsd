
int X509_PUBKEY_set(X509_PUBKEY **x,EVP_PKEY *pkey)

{
  code *pcVar1;
  X509_PUBKEY *val;
  int iVar2;
  
  if (x != (X509_PUBKEY **)0x0) {
    val = (X509_PUBKEY *)ASN1_item_new((ASN1_ITEM *)X509_PUBKEY_it);
    if (val != (X509_PUBKEY *)0x0) {
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
            if (*x != (X509_PUBKEY *)0x0) {
              ASN1_item_free((ASN1_VALUE *)*x,(ASN1_ITEM *)X509_PUBKEY_it);
            }
            *x = val;
            return 1;
          }
          ERR_put_error(0xb,0x78,0x7e,"x_pubkey.c",0x67);
        }
      }
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
    }
  }
  return 0;
}

