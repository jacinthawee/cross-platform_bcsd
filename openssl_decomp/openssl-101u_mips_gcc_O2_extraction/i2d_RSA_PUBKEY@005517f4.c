
int i2d_RSA_PUBKEY(RSA *a,uchar **pp)

{
  EVP_PKEY *pkey;
  ASN1_VALUE *val;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  if (a == (RSA *)0x0) {
    return 0;
  }
  pkey = EVP_PKEY_new();
  if (pkey == (EVP_PKEY *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xa5,0x41,"x_pubkey.c",0xfe);
    return 0;
  }
  EVP_PKEY_set1_RSA(pkey,a);
  val = ASN1_item_new((ASN1_ITEM *)X509_PUBKEY_it);
  if (val != (ASN1_VALUE *)0x0) {
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
          iVar1 = ASN1_item_i2d(val,pp,(ASN1_ITEM *)X509_PUBKEY_it);
          ASN1_item_free(val,(ASN1_ITEM *)X509_PUBKEY_it);
          goto LAB_005518c0;
        }
        uVar3 = 0x7e;
        uVar2 = 0x67;
      }
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x78,uVar3,"x_pubkey.c",uVar2);
    ASN1_item_free(val,(ASN1_ITEM *)X509_PUBKEY_it);
  }
  iVar1 = 0;
LAB_005518c0:
  EVP_PKEY_free(pkey);
  return iVar1;
}

