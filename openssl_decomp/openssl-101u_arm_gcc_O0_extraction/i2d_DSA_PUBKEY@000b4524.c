
int i2d_DSA_PUBKEY(DSA *a,uchar **pp)

{
  EVP_PKEY *pkey;
  ASN1_VALUE *val;
  int iVar1;
  code *pcVar2;
  
  if (a == (DSA *)0x0) {
    return 0;
  }
  pkey = EVP_PKEY_new();
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0xd,0xa1,0x41,"x_pubkey.c",0x126);
    return 0;
  }
  EVP_PKEY_set1_DSA(pkey,a);
  val = ASN1_item_new((ASN1_ITEM *)&X509_PUBKEY_it);
  if (val != (ASN1_VALUE *)0x0) {
    if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
      ERR_put_error(0xb,0x78,0x6f,"x_pubkey.c",0x6f);
    }
    else {
      pcVar2 = *(code **)(pkey->ameth + 0x18);
      if (pcVar2 == (code *)0x0) {
        ERR_put_error(0xb,0x78,0x7c,"x_pubkey.c",0x6b);
      }
      else {
        iVar1 = (*pcVar2)(val,pkey);
        if (iVar1 != 0) {
          iVar1 = ASN1_item_i2d(val,pp,(ASN1_ITEM *)&X509_PUBKEY_it);
          ASN1_item_free(val,(ASN1_ITEM *)&X509_PUBKEY_it);
          goto LAB_000b457e;
        }
        ERR_put_error(0xb,0x78,0x7e,"x_pubkey.c",0x67);
      }
    }
    ASN1_item_free(val,(ASN1_ITEM *)&X509_PUBKEY_it);
  }
  iVar1 = 0;
LAB_000b457e:
  EVP_PKEY_free(pkey);
  return iVar1;
}

