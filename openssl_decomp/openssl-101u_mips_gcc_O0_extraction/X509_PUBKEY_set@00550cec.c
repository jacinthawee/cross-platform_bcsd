
int X509_PUBKEY_set(X509_PUBKEY **x,EVP_PKEY *pkey)

{
  X509_PUBKEY *val;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  if (x == (X509_PUBKEY **)0x0) {
    return 0;
  }
  val = (X509_PUBKEY *)ASN1_item_new((ASN1_ITEM *)X509_PUBKEY_it);
  if (val != (X509_PUBKEY *)0x0) {
    if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
      uVar3 = 0x6f;
      uVar2 = 0x6f;
    }
    else {
      pcVar4 = *(code **)(pkey->ameth + 0x18);
      if (pcVar4 == (code *)0x0) {
        uVar3 = 0x7c;
        uVar2 = 0x6b;
      }
      else {
        iVar1 = (*pcVar4)(val,pkey);
        if (iVar1 != 0) {
          if (*x != (X509_PUBKEY *)0x0) {
            ASN1_item_free((ASN1_VALUE *)*x,(ASN1_ITEM *)X509_PUBKEY_it);
          }
          *x = val;
          return 1;
        }
        uVar3 = 0x7e;
        uVar2 = 0x67;
      }
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x78,uVar3,"x_pubkey.c",uVar2);
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
    return 0;
  }
  return 0;
}

