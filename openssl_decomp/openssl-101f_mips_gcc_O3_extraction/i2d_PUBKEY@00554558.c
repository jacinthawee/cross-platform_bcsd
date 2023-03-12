
int i2d_PUBKEY(EVP_PKEY *a,uchar **pp)

{
  ASN1_VALUE *val;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  if (a == (EVP_PKEY *)0x0) {
    return 0;
  }
  val = ASN1_item_new((ASN1_ITEM *)X509_PUBKEY_it);
  if (val != (ASN1_VALUE *)0x0) {
    if (a->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
      uVar3 = 0x6f;
      uVar2 = 0x76;
    }
    else {
      pcVar4 = *(code **)(a->ameth + 0x18);
      if (pcVar4 == (code *)0x0) {
        uVar3 = 0x7c;
        uVar2 = 0x70;
      }
      else {
        iVar1 = (*pcVar4)(val,a);
        if (iVar1 != 0) {
          iVar1 = ASN1_item_i2d(val,pp,(ASN1_ITEM *)X509_PUBKEY_it);
          ASN1_item_free(val,(ASN1_ITEM *)X509_PUBKEY_it);
          return iVar1;
        }
        uVar3 = 0x7e;
        uVar2 = 0x69;
      }
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x78,uVar3,"x_pubkey.c",uVar2);
    ASN1_item_free(val,(ASN1_ITEM *)X509_PUBKEY_it);
  }
  return 0;
}

